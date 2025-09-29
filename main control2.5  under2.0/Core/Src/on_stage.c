#include "main.h"
#include "motor.h"
#include "E18.h"
#include "stdint.h"
#include "attack.h"
#include "serial.h"
#include "usart.h"
#include "oled.h"


//#include "HAL_Delay.h"

#define on_edge 1
#define left_out_edge 2
#define right_out_edge 3
#define all_out_edge 4
#define back_left_out_edge 5
#define back_right_out_edge 6
#define back_all_out_edge 7


//uint8_t edge_scan(void)
//{
//		if(Read_left_front_edge() == 0 && Read_right_front_edge() == 0 && Read_left_back_edge() == 0 && Read_right_back_edge() == 0)
//		{
//			return on_edge;
//		}
//		else if(Read_left_front_edge() == 1 && Read_right_front_edge() == 0 && Read_left_back_edge() == 0 && Read_right_back_edge() == 0)
//		{
//			return left_out_edge;
//		}
//		else if(Read_left_front_edge() == 0 && Read_right_front_edge() == 1 && Read_left_back_edge() == 0 && Read_right_back_edge() == 0)
//		{
//			return right_out_edge;
//		}
//		else if(Read_left_front_edge() == 1 && Read_right_front_edge() == 1 && Read_left_back_edge() == 0 && Read_right_back_edge() == 0)
//		{
//			return all_out_edge;
//		}
//		else if(Read_left_front_edge() == 0 && Read_right_front_edge() == 0 && Read_left_back_edge() == 1 && Read_right_back_edge() == 0)
//		{
//			return back_left_out_edge;
//		}
//		else if(Read_left_front_edge() == 0 && Read_right_front_edge() == 0 && Read_left_back_edge() == 0 && Read_right_back_edge() == 1)
//		{
//			return back_right_out_edge;
//		}
//		else if(Read_left_front_edge() == 0 && Read_right_front_edge() == 0 && Read_left_back_edge() == 1 && Read_right_back_edge() == 1)
//		{
//			return back_all_out_edge;
//		}
//		
//}

//±ßÔµ×´Ì¬
uint8_t edge_scan(void)//ÁÁÎª0£¬°µÎª1
{
		if(Read_left_front_edge() == 0 && Read_right_front_edge() == 0)
		{
			return on_edge;
		}
		else if(Read_left_front_edge() == 1 && Read_right_front_edge() == 0)
		{
			return left_out_edge;
		}
		else if(Read_left_front_edge() == 0 && Read_right_front_edge() == 1)
		{
			return right_out_edge;
		}
		else if(Read_left_front_edge() == 1 && Read_right_front_edge() == 1)
		{
			return all_out_edge;
		}
		
}

void tai_shang_control(void)
{
		if(edge_scan() == on_edge)
		{
//			move(10,10);//ÂþÓÎ
			ProcessMotorCommands();
//			OLED_ShowNum(1,1,left_pwm,5);
//			OLED_ShowNum(2,1,right_pwm,5);
//			OLED_ShowNum(3,1,left_laser,5);
//			OLED_ShowNum(4,1,right_laser,5);
		}
		else if(edge_scan() == all_out_edge)
		{	
			move(-8,-8);
			HAL_Delay(200);
			move(-15,-15);
			HAL_Delay(300);
			move(-8,-8);
			HAL_Delay(200);
			Turn_180();
		}
		else if(edge_scan() == left_out_edge)
		{
			move(-8,-8);
			HAL_Delay(200);
			move(-15,-15);
			HAL_Delay(300);
			move(-8,-8);
			HAL_Delay(200);
			Turn_right_90();
		}
		else if(edge_scan() == right_out_edge)
		{
			move(-8,-8);
			HAL_Delay(200);
			move(-15,-15);
			HAL_Delay(300);
			move(-8,-8);
			HAL_Delay(200);
			Turn_left_90();
		}

}
