#include "gpio.h"

//±ßÔµ¼ì²â
uint8_t Read_right_front_edge(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);//ÓÒÇ°
	return output1;
}

uint8_t Read_right_back_edge(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);//ÓÒºó
	return output1;
}

uint8_t Read_left_front_edge(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);//×óÇ°
	return output1;
}

uint8_t Read_left_back_edge(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);//×óºó
	return output1;
}


//¹¥»÷
uint8_t Read_attack_left(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);//¹¥×ó
	return output1;
}
uint8_t Read_attack_right(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);//¹¥ÓÒ
	return output1;
}



//¼ì²âÇ½
uint8_t Read_wall_left(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);//Ç½×ó
	return output1;
}

uint8_t Read_wall_right(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);//Ç½ÓÒ
	return output1;
}
/*
A4ÓÒÇ°		ÓÒÇ°
A6ÓÒºó    ×óÇ°
B0×óÇ°
B1×óºó

A5¹¥×ó		
A7¹¥ÓÒ

B3Ç½×ó		
B4Ç½ÓÒ

A5 Ç°»Ò
C4 ºó»Ò
*/
