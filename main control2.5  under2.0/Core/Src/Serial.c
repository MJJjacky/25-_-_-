#include "usart.h"
#include <stdio.h>
#include <stdarg.h>
#include "Serial.h"
#include "stdint.h"//不然uint8_t会报错
#include "motor.h"
#include "adc.h"

//USART1 PA9 PA10 上位机通讯

uint8_t Serial_TxPacket[4];                
uint16_t Serial_RxPacket[6];               
uint8_t Serial_RxFlag;                     
uint8_t uart_rx_byte;                      // 
uint16_t left_pwm = 0;                      // 
uint16_t right_pwm = 0; 
uint16_t left_laser = 0;                      // 
uint16_t right_laser = 0;  
uint8_t speed_updated = 0;                 // 
extern  adcValue_type adcValue ;
//static void UART_ParsePacket(uint8_t *buf);


//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//    static uint8_t rx_buffer[7];           // (0x7B + 2 + 2 + checksum + 0x7D)
//    static uint8_t rx_state = 0;           // 
//    static uint8_t rx_counter = 0;         // 
//    static uint8_t checksum = 0;           // 

//    if (huart != &huart6) return;         

//    if (rx_state == 0) {
//        /* 0x7B */
//        if (uart_rx_byte == 0x7B) {
//            rx_counter = 0;
//            checksum = 0;
//            rx_buffer[rx_counter++] = uart_rx_byte;
//            checksum ^= uart_rx_byte;     
//            rx_state = 1;               
//        }
//    } else {
//        rx_buffer[rx_counter] = uart_rx_byte;
//        
//        /* (0x7B + pwm_left + pwm_right) */
//        if (rx_counter < 5) checksum ^= uart_rx_byte;
//        
//        if (++rx_counter >= sizeof(rx_buffer)) {
//            rx_state = 0;  
//            if (rx_buffer[6] == 0x7D && rx_buffer[5] == checksum) {
//                UART_ParsePacket(rx_buffer);  
//                speed_updated = 1;            
//            }
//        }
//    }

//    HAL_UART_Receive_IT(&huart6, &uart_rx_byte, 1);
//}


void UART_ParsePacket(uint8_t *buf)
{

    left_pwm = (int16_t)(((uint16_t)buf[1] << 8) | buf[2]); 
    right_pwm = (int16_t)(((uint16_t)buf[3] << 8) | buf[4]);
	  left_laser = (int16_t)(((uint16_t)buf[5] << 8) | buf[6]);
	  right_laser = (int16_t)(((uint16_t)buf[7] << 8) | buf[8]);
}


void UART_Init(void)
{
    HAL_UART_Receive_IT(&huart6, &uart_rx_byte, 1);
}


void ProcessMotorCommands(void)
{
    if (speed_updated) {
        speed_updated = 0;  
			if(left_pwm==0){
//				move(0,0);
//				HAL_Delay(20);
        move(-right_pwm, right_pwm);  
			}
			else if(right_pwm==0){
//				move(0,0);
//				HAL_Delay(20);
				move(left_pwm, -left_pwm); 
    }
			else{
				if(adcValue .value1>100&&adcValue .value1<200){
				move(left_pwm-adcValue .value1*0.028,right_pwm-adcValue .value1*0.028);
				}
				else{
					move(left_pwm,right_pwm);
				}
			}
	}
}


//发送
void hhSerialSendByte(uint8_t Byte){
	HAL_UART_Transmit(&huart6, &Byte, 1, HAL_MAX_DELAY);
}
void hhSerialSendArray(uint8_t *Array,uint16_t Length){
	for(uint16_t i=0;i<Length;i++){
		hhSerialSendByte(Array[i]);
	}
}
void hhSerialSendString(char * mString){
	for(uint16_t i=0;mString[i]!='\0';i++){
		hhSerialSendByte(mString[i]);
	}
}

//x的y次方
uint32_t Serial_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y --)
	{
		Result *= X;
	}
	return Result;
}

//切割数据
void hhSerial_SendNumber(uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i ++)
	{
		hhSerialSendByte(Number / Serial_Pow(10, Length - i - 1) % 10 + '0');
	}
}

//printf
void Serial_Printf(char *format, ...)
{
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	hhSerialSendString(String);
}



//清除标志位
uint8_t Serial_GetRxFlag(void)
{
	if (Serial_RxFlag == 1)
	{
		Serial_RxFlag = 0;
		return 1;
	}
	return 0;
}


int16_t Byteconb(int16_t byte1,int16_t byte2)
{
    int16_t num = byte1<<8;
	  int16_t num1 = byte2 + num;
	  return num1;
}

//发送4个字节的数据包
uint8_t Serial_TxPacket[4];
void hhSerial_SendPacket(void)
{
	hhSerialSendByte(0xFF);
	hhSerialSendArray(Serial_TxPacket, 4);
	hhSerialSendByte(0xFE);
}


