//#include "tim.h"

////������ʱ����ͨ��
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
////���ѡ��ͨ��
//void PWM_SetCompare(uint8_t channel, uint16_t Compare)
//{
//    switch (channel)
//    {
//        case 0:
//            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, Compare);//������ת
//				   
//            break;
//        case 1:
//            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, Compare);//������ת
//				   
//            break;
//        case 2:
//            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, Compare);//���ֵ�ת
//				    
//            break;
//        case 3:
//            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, Compare);//���ֵ�ת
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
////���ҵ���ٶ�
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
//			PWM_SetCompare(3,-speed);//���ٶȾ��ǵ�ת��ͬʱ��ֹ����ը���
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
//			PWM_SetCompare(0,-speed);//ͬ��		
//		}
//}

////�˶�����
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


//����ʹ��
void PWM_Init(void)//��ͨ��
{   
	  HAL_TIM_PWM_Init(&htim2);

    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //A0��ǰ��
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //A1��ǰ��
	
	
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); //C8��ǰ��
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4); //C9��ǰ��

	//ǰ������·pwm˼·һ�������ָ���
	
	
	
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); //D12�����
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2); //D13
	
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3); //D14�Һ�
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); //D15

           
}
	

void PWM_SetCompare(uint8_t channel, uint16_t Compare)//��ռ�ձ�
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

	
	//�������ٶ�
int Last_left_Speed=0,Last_right_Speed=0;
void left_Speed(double speed)
{
		if(speed>0)
		{
			PWM_SetCompare(1,speed);//�����
			PWM_SetCompare(2,0);//���
			
			PWM_SetCompare(3,speed);//��ǰ��
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
			PWM_SetCompare(6,speed);//��ǰ��
			PWM_SetCompare(5,0);
			PWM_SetCompare(8,speed);//�Һ���
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


//��������
void Motor_Stop(void);//�ݹ����
void move(double left_speed,double right_speed)
{
	//��ֹ˲�䷴ת����ѹ����
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

//ת��
uint8_t turnspeed,turntime;//�����޸�
#define turnspeed  ts;//ת45�ٶ�
#define turnstime  tt;//ת45ʱ��

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

void Turn_180(void)//��ת
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
���������ģ������ֻ�����ж������Ӷ�ֻ����ֹͣ����
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
������Ҹ���һ�µ�ʱ������΢�տ���һ�£����������ܻ�Ӱ����Ӧ�ٶȣ��������ԡ�
Ȼ��ͽ���ͳһ��һ�±����move�������Ҳ��������������հ档
��Ҫ����ϣ����λ��Ӹ������߰���Ķ���ʱ�����Ƿ��ϴ��Ӱ�캯������Ҫ���ܡ���Ҫ����һ���뵱Ȼ������λ�����������Ǳ�Ǹ��
*/

