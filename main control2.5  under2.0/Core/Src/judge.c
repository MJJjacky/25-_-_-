//#include "main.h"
//#include "adc.h"
//#include "main.h"
//#include "OLED.h"




//uint8_t AD0,sum,AD;//�Ҷȣ������ԭ��;��������:����Խ����ֵԽС


//void getAD(void){
//		uint8_t sum;
//			HAL_ADC_Start(&hadc1);     //����ADCת��
//		HAL_ADC_PollForConversion(&hadc1, 50);   //�ȴ�ת����ɣ�50Ϊ���ȴ�ʱ�䣬��λΪms
// 
//		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
//		{
//			

//			 AD0= HAL_ADC_GetValue(&hadc1);   //��ȡADֵ
//			
//		OLED_ShowNum(2,11,AD0,5);				//��ʾͨ��0��ת�����AD0

//		
//			//HAL_Delay(1000);
//		}
//}
//uint8_t direction_judge(){
//	
//			for(int i=0;i<100;i++){//�˲�
//			sum+=AD0;
//			}
//			AD=sum/100;
//			
//			/*ƽ��̨��120
//						̨��250*/
//		if(AD>=200){
//		return 0;
//		}
//		else{
//		return 1; 
//		}
//}


