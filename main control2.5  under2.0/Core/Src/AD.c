//#include "adc.h"
//#include "dma.h"
//#include "usart.h"

//#include "stdio.h"
//#include "string.h"//标准库和字符串，防报错


//uint16_t ADC_value[4];


//void AD_DMA_Init(void){
//		//char str[64];//存储数组
//		
//		HAL_ADC_Start(&hadc1);    //开
//		HAL_ADC_PollForConversion(&hadc1, 50);   //超时报错
// 
//		HAL_ADC_Start_DMA(&hadc1,(uint32_t*)ADC_value,8);//半字，4个通道，每个通道一个字长
// 
//		//sprintf(str,"%f,%f,%f,%f\r\n",(ADC_value[0]*3.3)/4095,(ADC_value[1]*3.3)/4095,(ADC_value[2]*3.3)/4095,(ADC_value[3]*3.3)/4095);   //一次触发无限次采样
//	   //HAL_UART_Transmit(&huart1,(uint8_t*)str,strlen(str),HAL_MAX_DELAY);//串口
//		HAL_Delay(10);
//}
