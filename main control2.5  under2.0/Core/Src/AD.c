//#include "adc.h"
//#include "dma.h"
//#include "usart.h"

//#include "stdio.h"
//#include "string.h"//��׼����ַ�����������


//uint16_t ADC_value[4];


//void AD_DMA_Init(void){
//		//char str[64];//�洢����
//		
//		HAL_ADC_Start(&hadc1);    //��
//		HAL_ADC_PollForConversion(&hadc1, 50);   //��ʱ����
// 
//		HAL_ADC_Start_DMA(&hadc1,(uint32_t*)ADC_value,8);//���֣�4��ͨ����ÿ��ͨ��һ���ֳ�
// 
//		//sprintf(str,"%f,%f,%f,%f\r\n",(ADC_value[0]*3.3)/4095,(ADC_value[1]*3.3)/4095,(ADC_value[2]*3.3)/4095,(ADC_value[3]*3.3)/4095);   //һ�δ������޴β���
//	   //HAL_UART_Transmit(&huart1,(uint8_t*)str,strlen(str),HAL_MAX_DELAY);//����
//		HAL_Delay(10);
//}
