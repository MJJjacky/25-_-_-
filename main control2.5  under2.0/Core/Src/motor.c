//#include "tim.h"

////开启定时器和通道
//void PWM_Init(void)
//{   
//	  HAL_TIM_PWM_Init(&htim2);
//    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); 
//    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); 
//    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); 
//    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); 

//           
//}
//	
////输出选择通道
//void PWM_SetCompare(uint8_t channel, uint16_t Compare)
//{
//    switch (channel)
//    {
//        case 0:
//            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, Compare);//左轮正转
//				   
//            break;
//        case 1:
//            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, Compare);//右轮正转
//				   
//            break;
//        case 2:
//            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, Compare);//左轮倒转
//				    
//            break;
//        case 3:
//            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, Compare);//右轮倒转
//				   
//            break;
//       
//				    
//          
//        default:
//            // Invalid channel, do nothing or handle error
//            break;
//    }
//	}

//	
////左右电机速度
//void left_Speed(int speed)
//{
//		if(speed>0)
//		{
//			PWM_SetCompare(1,speed);
//			PWM_SetCompare(3,0);
//		}
//		else
//		{
//			PWM_SetCompare(1,0);
//			PWM_SetCompare(3,-speed);//左负速度就是倒转，同时防止负数炸电机
//		}
//}
//	
//void right_Speed(int speed)
//{
//		if(speed>0)
//		{
//			PWM_SetCompare(2,speed);
//			PWM_SetCompare(0,0);
//		}
//		else
//		{
//			PWM_SetCompare(2,0);
//			PWM_SetCompare(0,-speed);//同上		
//		}
//}

////运动函数
//void Straight_Speed(int Speed)
//{
//	left_Speed(Speed);
//	right_Speed(Speed);
//}

//void Motor_Stop(void)
//{
//	left_Speed(0);
//	right_Speed(0);
//	HAL_Delay(10);
//}

//void Turn_left_45(void)
//{
//		left_Speed(30);
//		right_Speed(-30);
//		HAL_Delay(113);
//}
//	
//void Turn_right_45(void)
//{
//		left_Speed(-30);
//		right_Speed(30);
//		HAL_Delay(113);
//}

//void Turn_left_90(void)
//{
//		left_Speed(30);
//		right_Speed(-30);
//		HAL_Delay(182);
//}

//void Turn_right_90(void)
//{
//		left_Speed(-30);
//		right_Speed(30);
//		HAL_Delay(182);
//}

//void Turn_180(void)
//{
//		left_Speed(35);
//		right_Speed(-35);
//		HAL_Delay(310);
//}
#include "tim.h"


//基础使能
void PWM_Init(void)//开通道
{   
	  HAL_TIM_PWM_Init(&htim2);

    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //A0左前正
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //A1左前反
	
	
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); //C8右前反
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4); //C9右前正

	//前轮与四路pwm思路一样，后轮复制
	
	
	
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); //D12左后正
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2); //D13
	
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3); //D14右后反
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); //D15

           
}
	

void PWM_SetCompare(uint8_t channel, uint16_t Compare)//发占空比
{
    switch (channel)
    {
        case 1:
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, Compare);//
				   
            break;
        case 2:
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, Compare);//
				   
            break;
				
				
        case 3:
            __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, Compare);//
				    
            break;
        case 4:
            __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, Compare);//
				   
            break;
				
				
				
				case 5:
            __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, Compare);//
				   
            break;
        case 6:
            __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, Compare);//
				   
            break;
				
				
        case 7:
            __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, Compare);//
				    
            break;
        case 8:
            __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, Compare);//
				   
            break;
        default:
            // Invalid channel, do nothing or handle error
            break;
    }
	}

	
	//左右轮速度
int Last_left_Speed=0,Last_right_Speed=0;
void left_Speed(double speed)
{
		if(speed>0)
		{
			PWM_SetCompare(1,speed);//左后正
			PWM_SetCompare(2,0);//左后反
			
			PWM_SetCompare(3,speed);//左前正
			PWM_SetCompare(4,0);//
		}
		else if(speed<0)
		{
			PWM_SetCompare(1,0);
			PWM_SetCompare(2,-speed);
			
			PWM_SetCompare(3,0);
			PWM_SetCompare(4,-speed);
		}
		else 
		{
			PWM_SetCompare(1,0);
			PWM_SetCompare(2,0);
			PWM_SetCompare(3,0);
			PWM_SetCompare(4,0);
		}
}

void right_Speed(double speed)
{
	if(speed>0)
		{
			PWM_SetCompare(6,speed);//左前正
			PWM_SetCompare(5,0);
			PWM_SetCompare(8,speed);//右后正
			PWM_SetCompare(7,0);
		}
		else if(speed<0)
		{
			PWM_SetCompare(6,0);
			PWM_SetCompare(5,-speed);
			PWM_SetCompare(8,0);
			PWM_SetCompare(7,-speed);
		}
		else
		{
			PWM_SetCompare(6,0);
			PWM_SetCompare(5,0);
			PWM_SetCompare(7,0);
			PWM_SetCompare(8,0);
		}
}


//基础控制
void Motor_Stop(void);//递归调用
void move(double left_speed,double right_speed)
{
	//防止瞬间反转，电压过大
	if( ((left_speed>0)&&(Last_left_Speed<0)) ||((left_speed<0)&&(Last_left_Speed>0)) || ((right_speed>0)&&(Last_right_Speed<0)) ||((right_speed<0)&&(Last_right_Speed>0)))
	{
		Motor_Stop();
		left_Speed(left_speed);
		right_Speed(right_speed);
	}
	else
	{
		left_Speed(left_speed);
		right_Speed(right_speed);
	}
	Last_left_Speed = left_speed;
	Last_right_Speed = right_speed;
 
}


void Motor_Stop(void)
{
		move(0,0);
		HAL_Delay(20);
}

//转向
uint8_t turnspeed,turntime;//方便修改
#define turnspeed  ts;//转45速度
#define turnstime  tt;//转45时间

uint8_t ts=25;
uint8_t tt=150;//150

void Turn_right_45(void)
{
		move(ts,-ts);
		HAL_Delay(tt);
}
	
void Turn_left_45(void)
{
		move(-ts,ts);
		HAL_Delay(tt);  
}

void Turn_right_90(void)
{
		move(ts/2,-ts/2);
		HAL_Delay(tt);
		move(ts,-ts);
		HAL_Delay(tt);
}

void Turn_left_90(void)
{
		move(-ts/2,ts/2);
		HAL_Delay(tt);
	move(-ts,ts);
		HAL_Delay(tt);
}

void Turn_180(void)//左转
{
		move(-ts,ts);
		HAL_Delay(tt*4);
}

//void left_Speed(int speed)
//{
//		if((speed<0) && (Last_left_Speed>0))
//		{
//			Motor_Stop();
//		}
//		else if((speed>0) && (Last_left_Speed<0))
//		{
//			Motor_Stop();
//		}
//		if(speed>0)
//		{
//			PWM_SetCompare(1,speed);
//			PWM_SetCompare(3,0);
//		}
//		else if(speed<0)
//		{
//			PWM_SetCompare(1,0);
//			PWM_SetCompare(3,-speed);
//		}
//		else 
//		{
//			PWM_SetCompare(1,0);
//			PWM_SetCompare(3,0);
//		}
//		Last_left_Speed = speed;
//}
/*
这个是最早的，会出现只进行判断正反从而只进行停止操作
*/
//void left_Speed(int speed)
//{
//		if(speed>0)
//		{
//			if(Last_left_Speed<0)
//			{
//				Motor_Stop();
//				PWM_SetCompare(1,speed);
//				PWM_SetCompare(3,0);
//			}
//			else
//			{
//				PWM_SetCompare(1,speed);
//				PWM_SetCompare(3,0);
//			}
//		}
//		else if(speed<0)
//		{
//			if(Last_left_Speed>0)
//			{
//				Motor_Stop();
//				PWM_SetCompare(1,0);
//				PWM_SetCompare(3,-speed);
//			}
//			else
//			{
//				PWM_SetCompare(1,0);
//				PWM_SetCompare(3,-speed);
//			}
//		}
//		else
//		{
//			PWM_SetCompare(1,0);
//			PWM_SetCompare(3,0);
//		}
//		Last_left_Speed = speed;
//}
/*
这个是我改了一下的时候但我稍微烧烤了一下，发现他可能会影响响应速度，和流畅性。
然后就将其统一了一下变成了move这个函数也就是现在这个最终版。
主要还是希望各位添加各种乱七八糟的东西时候考虑是否会较大的影响函数的主要功能。不要像我一样想当然。给各位带来不便真是抱歉。
*/

