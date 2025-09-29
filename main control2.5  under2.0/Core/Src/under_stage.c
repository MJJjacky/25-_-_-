#include "main.h"
#include "motor.h"
#include "E18.h"
#include "stdint.h"
#include "stdlib.h"
#include "usart.h"
#include "judge.h"
#include "OLED.h"
#include "serial.h"
#include "adc.h"

//??:????,????(????)

/*????*/
extern uint16_t distance1;//??
extern uint16_t distance2;//??
extern uint16_t left_laser;//?
extern uint16_t right_laser;//?
extern uint16_t distance5;//?
	
	
	/*
	??700
	??2300
	????850
	??-?=420
	*/

uint16_t limit=1000;
uint16_t ml,mr,b;
uint16_t judge_near=750;//?????????
uint16_t judge_far=2450;//???????????
uint16_t near=300;
uint16_t far=3000;//????
uint16_t corridor_w=400;//??
uint16_t corridor_l=1200;
uint8_t l_light,r_light;
uint16_t corner;
extern uint8_t j;





#define wide_corner 0
#define corridor 1



/*???*/
uint16_t up;
uint16_t cnt1=0;
uint16_t cnt2=0;
uint8_t flag;
/*??????
?????
???
*/

void under_stage_control(void)
{

/*????*/
//fl=left_laser;//????????
//fr=right_laser;
//ml=distance1;
//mr=distance2 ;
l_light=Read_wall_left();
r_light=Read_wall_right();
	
	
	
	//????
	if(l_light==1&&r_light==1){
		cnt2=0;
		move(12,-12);
		HAL_Delay(200);
		cnt1++;
		if(cnt1>=8){
			move(-12,-12);
			HAL_Delay(200);
			cnt1=0;
		}
	}
//	if(l_light==1&&r_light==0){
//		cnt2=0;
//		cnt1=0;
//		move(10,-10);
//		HAL_Delay(200);
//	}
//	if(l_light==0&&r_light==1){
//		cnt2=0;
//		cnt1=0;
//		move(-10,10);
//		HAL_Delay(200);
//	}
//	
	//??
	if((l_light==0&&r_light==0)&&(left_laser>=140||right_laser>=140)){
		cnt1=0;
		move(12,12);
		HAL_Delay(700);
		cnt2++;
		if(cnt2>=3){
			if(left_laser>right_laser){
				move(12,-4);
				HAL_Delay(400);
				cnt2=0;
			}
			if(left_laser<right_laser){
				move(-4,12);
				HAL_Delay(400);
				cnt2=0;
			}
		}
		//????,?????
//		if((distance1<300&&distance2>1500)||(distance1>1500&&distance2<300)){
//			move(-15,-15);//??????
//			HAL_Delay(1000);
////			move(-15,-15);
////			HAL_Delay(1000);
//			//??
////			if(left_laser>400||right_laser>400){
////				if(left_laser<right_laser){
////					move(8,8);
////					HAL_Delay(200);
////					move(8,-8);
////					HAL_Delay(500);
////					move(8,8);
////					HAL_Delay(300);
////				}
////				if(left_laser>right_laser){
////					move(8,8);
////					HAL_Delay(200);
////					move(-8,8);
////					HAL_Delay(500);
////					move(8,8);
////					HAL_Delay(300);
////				}
////			}
//		}
	}

	
	//??
	if((l_light==0&&r_light==0)&&(left_laser<140&&right_laser<140)){
		cnt1=0;
		cnt2=0;
		flag=1;
		if(distance1<800&&distance2>1500){
			move(-12,-12);
			HAL_Delay(200);
			move(15,-15);
			HAL_Delay(340);
			move(15,15);
			HAL_Delay(600);
			move(-15,15);
			HAL_Delay(350);
			flag=0;
		}
		if(distance2<800&&distance1>1500){
			move(-12,-12);
			HAL_Delay(200);
			move(-15,15);
			HAL_Delay(340);
			move(15,15);
			HAL_Delay(600);
			move(15,-15);
			HAL_Delay(350);
			flag=0;
		}
		if(flag){
		move(12,12);//??
		HAL_Delay(600);
		
		//????
		move(-25,-25);
		HAL_Delay(600);
		move(-20,-20);
		HAL_Delay(600);
		move(-25,-25);
		HAL_Delay(400);
		move(-5,-5);
		HAL_Delay(100);
		
		move(0,0);
		HAL_Delay(200);
		}
	}


}