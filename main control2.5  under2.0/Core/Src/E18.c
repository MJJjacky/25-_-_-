#include "gpio.h"

//��Ե���
uint8_t Read_right_front_edge(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);//��ǰ
	return output1;
}

uint8_t Read_right_back_edge(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);//�Һ�
	return output1;
}

uint8_t Read_left_front_edge(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);//��ǰ
	return output1;
}

uint8_t Read_left_back_edge(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);//���
	return output1;
}


//����
uint8_t Read_attack_left(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);//����
	return output1;
}
uint8_t Read_attack_right(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);//����
	return output1;
}



//���ǽ
uint8_t Read_wall_left(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);//ǽ��
	return output1;
}

uint8_t Read_wall_right(void)
{
	uint8_t output1;
	output1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);//ǽ��
	return output1;
}
/*
A4��ǰ		��ǰ
A6�Һ�    ��ǰ
B0��ǰ
B1���

A5����		
A7����

B3ǽ��		
B4ǽ��

A5 ǰ��
C4 ���
*/
