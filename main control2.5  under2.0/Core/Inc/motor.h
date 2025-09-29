#ifndef __MOTOR_H
#define __MOTOR_H
#include "stdint.h"


void PWM_Init(void);
void PWM_SetCompare(uint8_t channel, uint16_t Compare);
void Servo_SetAngle(float Angle);


void Motor_Servo_Init(void);
void Straight_Speed(int Speed);
void left_Speed(double speed);
void right_Speed(double speed);
void Motor_Stop(void);
void Turn_left_45(void);
void Turn_right_45(void);
void Turn_left_90(void);
void Turn_right_90(void);
void Turn_180(void);

void move(double left_speed,double right_speed);

/*
TIM2
PA0 CH1 | PA1 2 | PA2 3 | PA3 4  



PA0 PA2	 ����  2��ת 0��ת
PA1 PA3  ����  1��ת 3��ת


����
P0 1 2 3 Ϊ�������PWM��ARR=100 - 1;PSC = 168 - 1;��
10KHz
ռ�ձȣ�x/1000


*/

#endif
