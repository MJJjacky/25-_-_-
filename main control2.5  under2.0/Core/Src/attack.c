#include "E18.h"
#include "motor.h"

//可优化差速躲避
//优先级：边缘>摄像头>攻击>雷达
//将光电优化到侧边追踪攻击
//攻击用激光差速

void attack(void){
	uint8_t a1,a2;
	a1=Read_attack_left();
	a2=Read_attack_right();
	if(a1==0&&a2==0){//前
	move(20,20);
	}
	else if(a1==0&&a2==1){//左
	move(5,20);
	}
	else if(a1==1&&a2==0){//右
	move(20,5);
	}
	else if(a1==1&&a2==1){
		//上位机
	}
}
	