#include "E18.h"
#include "motor.h"

//���Ż����ٶ��
//���ȼ�����Ե>����ͷ>����>�״�
//������Ż������׷�ٹ���
//�����ü������

void attack(void){
	uint8_t a1,a2;
	a1=Read_attack_left();
	a2=Read_attack_right();
	if(a1==0&&a2==0){//ǰ
	move(20,20);
	}
	else if(a1==0&&a2==1){//��
	move(5,20);
	}
	else if(a1==1&&a2==0){//��
	move(20,5);
	}
	else if(a1==1&&a2==1){
		//��λ��
	}
}
	