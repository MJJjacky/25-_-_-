//#include "main.h"
//#include "adc.h"
//#include "main.h"
//#include "OLED.h"




//uint8_t AD0,sum,AD;//灰度，反射光原理;光敏电阻:反射越大，阻值越小


//void getAD(void){
//		uint8_t sum;
//			HAL_ADC_Start(&hadc1);     //启动ADC转换
//		HAL_ADC_PollForConversion(&hadc1, 50);   //等待转换完成，50为最大等待时间，单位为ms
// 
//		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
//		{
//			

//			 AD0= HAL_ADC_GetValue(&hadc1);   //获取AD值
//			
//		OLED_ShowNum(2,11,AD0,5);				//显示通道0的转换结果AD0

//		
//			//HAL_Delay(1000);
//		}
//}
//uint8_t direction_judge(){
//	
//			for(int i=0;i<100;i++){//滤波
//			sum+=AD0;
//			}
//			AD=sum/100;
//			
//			/*平均台上120
//						台下250*/
//		if(AD>=200){
//		return 0;
//		}
//		else{
//		return 1; 
//		}
//}


