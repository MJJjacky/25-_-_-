#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>
#include "stdint.h"
#include "usart.h"
#include "motor.h"

extern uint16_t Serial_RxPacket[6];
extern uint8_t ByteRecv;
extern uint8_t Serial_RxFlag;
extern uint8_t Serial_TxPacket[4];
extern uint8_t uart_rx_byte;              // 单字节缓存
extern uint16_t left_pwm ;        
extern uint16_t right_pwm ;  
extern uint16_t left_laser ;        
extern uint16_t right_laser ;  
extern uint8_t speed_updated ;        // 数据更新标志

void UART_ParsePacket(uint8_t *buf);
uint8_t Serial_GetRxFlag(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void hhSerial_SendPacket(void);
void UART_Init(void);                
void ProcessMotorCommands(void);  
int16_t Byteconb(int16_t byte1,int16_t byte2);

#endif
