/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include "serial.h"

uint8_t Usart1_Receive_buf[1];          //����1�����ж����ݴ�ŵĻ�����?
uint8_t Uart4_Receive_buf[1];
uint8_t Uart5_Receive_buf[1];

uint8_t Usart2_Receive_buf[1];//2
uint8_t Usart3_Receive_buf[1];
/* USER CODE END 0 */

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart6;

/* UART4 init function */
void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */
 

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 230400;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */
   HAL_UART_Receive_IT(&huart4,Uart4_Receive_buf,sizeof(Uart4_Receive_buf)); //3
  /* USER CODE END UART4_Init 2 */

}
/* UART5 init function */
void MX_UART5_Init(void)
{

  /* USER CODE BEGIN UART5_Init 0 */

  /* USER CODE END UART5_Init 0 */

  /* USER CODE BEGIN UART5_Init 1 */

  /* USER CODE END UART5_Init 1 */
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 230400;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART5_Init 2 */
   HAL_UART_Receive_IT(&huart5,Uart5_Receive_buf,sizeof(Uart5_Receive_buf)); //�򿪴���5�����ж�
  /* USER CODE END UART5_Init 2 */

}
/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 230400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */
   HAL_UART_Receive_IT(&huart1,Usart1_Receive_buf,sizeof(Usart1_Receive_buf)); //�򿪴���5�����ж�
  /* USER CODE END USART1_Init 2 */

}
/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 230400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */
   HAL_UART_Receive_IT(&huart2,Usart2_Receive_buf,sizeof(Usart2_Receive_buf)); //�򿪴���5�����ж�
  /* USER CODE END USART2_Init 2 */

}
/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 230400;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */
   HAL_UART_Receive_IT(&huart3,Usart3_Receive_buf,sizeof(Usart3_Receive_buf)); //�򿪴���5�����ж�
  /* USER CODE END USART3_Init 2 */

}
/* USART6 init function */

void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 115200;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==UART4)
  {
  /* USER CODE BEGIN UART4_MspInit 0 */

  /* USER CODE END UART4_MspInit 0 */
    /* UART4 clock enable */
    __HAL_RCC_UART4_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**UART4 GPIO Configuration
    PC10     ------> UART4_TX
    PC11     ------> UART4_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* UART4 interrupt Init */
    HAL_NVIC_SetPriority(UART4_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(UART4_IRQn);
  /* USER CODE BEGIN UART4_MspInit 1 */

  /* USER CODE END UART4_MspInit 1 */
  }
  else if(uartHandle->Instance==UART5)
  {
  /* USER CODE BEGIN UART5_MspInit 0 */

  /* USER CODE END UART5_MspInit 0 */
    /* UART5 clock enable */
    __HAL_RCC_UART5_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**UART5 GPIO Configuration
    PC12     ------> UART5_TX
    PD2     ------> UART5_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* UART5 interrupt Init */
    HAL_NVIC_SetPriority(UART5_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(UART5_IRQn);
  /* USER CODE BEGIN UART5_MspInit 1 */

  /* USER CODE END UART5_MspInit 1 */
  }
  else if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */
	   HAL_UART_Receive_IT(&huart1,Usart1_Receive_buf,sizeof(Usart1_Receive_buf)); //�򿪴���5�����ж�

  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PD5     ------> USART2_TX
    PD6     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
  else if(uartHandle->Instance==USART6)
  {
  /* USER CODE BEGIN USART6_MspInit 0 */

  /* USER CODE END USART6_MspInit 0 */
    /* USART6 clock enable */
    __HAL_RCC_USART6_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**USART6 GPIO Configuration
    PC6     ------> USART6_TX
    PC7     ------> USART6_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_USART6;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* USART6 interrupt Init */
    HAL_NVIC_SetPriority(USART6_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART6_IRQn);
  /* USER CODE BEGIN USART6_MspInit 1 */

  /* USER CODE END USART6_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==UART4)
  {
  /* USER CODE BEGIN UART4_MspDeInit 0 */

  /* USER CODE END UART4_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_UART4_CLK_DISABLE();

    /**UART4 GPIO Configuration
    PC10     ------> UART4_TX
    PC11     ------> UART4_RX
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_10|GPIO_PIN_11);

    /* UART4 interrupt Deinit */
    HAL_NVIC_DisableIRQ(UART4_IRQn);
  /* USER CODE BEGIN UART4_MspDeInit 1 */

  /* USER CODE END UART4_MspDeInit 1 */
  }
  else if(uartHandle->Instance==UART5)
  {
  /* USER CODE BEGIN UART5_MspDeInit 0 */

  /* USER CODE END UART5_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_UART5_CLK_DISABLE();

    /**UART5 GPIO Configuration
    PC12     ------> UART5_TX
    PD2     ------> UART5_RX
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_2);

    /* UART5 interrupt Deinit */
    HAL_NVIC_DisableIRQ(UART5_IRQn);
  /* USER CODE BEGIN UART5_MspDeInit 1 */

  /* USER CODE END UART5_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PD5     ------> USART2_TX
    PD6     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_5|GPIO_PIN_6);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART6)
  {
  /* USER CODE BEGIN USART6_MspDeInit 0 */

  /* USER CODE END USART6_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART6_CLK_DISABLE();

    /**USART6 GPIO Configuration
    PC6     ------> USART6_TX
    PC7     ------> USART6_RX
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6|GPIO_PIN_7);

    /* USART6 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART6_IRQn);
  /* USER CODE BEGIN USART6_MspDeInit 1 */

  /* USER CODE END USART6_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */


















char USART_RX_BUF[USART_REC_LEN];     //���ջ���,���USART_REC_LEN���ֽ�.
uint16_t point1 ;
LidarPointTypedef Pack_Data1[12];
LidarPointTypedef Pack_Data2[12];
LidarPointTypedef Pack_Data5[12];
LidarPointTypedef Pack_sum1;
LidarPointTypedef Pack_sum2; 
LidarPointTypedef Pack_sum3; 
LidarPointTypedef Pack_sum4; 
LidarPointTypedef Pack_sum5; 

extern uint16_t receive_cnt1;
extern uint8_t confidence1;
extern uint16_t distance1,noise1,reftof1;
extern uint32_t peak1,intg1;

extern uint16_t receive_cnt2;
extern uint8_t confidence2;
extern uint16_t distance2,noise2,reftof2;
extern uint32_t peak2,intg2;

extern uint16_t receive_cnt3;
extern uint8_t confidence3;
extern uint16_t distance3,noise3,reftof3;
extern uint32_t peak3,intg3;

extern uint16_t receive_cnt4;
extern uint8_t confidence4;
extern uint16_t distance4,noise4,reftof4;//4
extern uint32_t peak4,intg4;

extern uint16_t receive_cnt5;
extern uint8_t confidence5;
extern uint16_t distance5,noise5,reftof5;
extern uint32_t peak5,intg5;


void data1_process(void);/*���ݴ����������һ֮֡��ɽ������ݴ���*/
void data2_process(void);
void data3_process(void);
void data4_process(void);
void data5_process(void);
//void data4_process(void);


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) //���ջص�����
{

	static uint8_t state = 0;			//״̬λ	
	static uint8_t crc = 0;				//У���?
	static uint8_t cnt = 0;				//����һ֡12����ļ���?
	static uint8_t PACK_FLAG = 0;  //�����־�?
	static uint8_t data_len  = 0;  //���ݳ���
	static uint32_t timestamp = 0; //ʱ���?
	static uint8_t state_flag = 1; //ת�����ݽ��ձ�־λ
	static uint8_t rx_buffer[12];           // (0x7B + 2 + 2 + checksum + 0x7D)
  static uint8_t rx_state = 0;           // 
  static uint8_t rx_counter = 0;         // 
  static uint8_t checksum = 0;   
	uint8_t temp_data;
	if(huart -> Instance == UART4)
	{
			temp_data=Uart4_Receive_buf[0];	
			if(state< 4) 																					 /* ��ʼ����֤ ǰ4�����ݾ�Ϊ0xAA */
				{                                          
						if(temp_data == HEADER) state ++;
						else state = 0;
				}
				else if(state<10&&state>3)
				{
						switch(state)
						{
								case 4:   
									if(temp_data == device_address)              /* �豸��ַ��֤ */
									{							
													state ++;
													crc = crc + temp_data;									
													break;        
									} 
									else state = 0,crc = 0;
								case 5:   
									if(temp_data == PACK_GET_DISTANCE)					 /* ��ȡ������������ */
									{  
													PACK_FLAG = PACK_GET_DISTANCE;
													state ++;	
													crc = crc + temp_data;	
													break;									
									}		 

									else if(temp_data == PACK_RESET_SYSTEM) 		 /* ��λ���� */
									{
													PACK_FLAG = PACK_RESET_SYSTEM;
													state ++; 
													crc = crc + temp_data;	
													break;	
									}
									else if(temp_data == PACK_STOP)							 /* ֹͣ�������ݴ������� */
									{ 
													PACK_FLAG = PACK_STOP;
													state ++; 
													crc = crc + temp_data;	
													break;
									}
									else if(temp_data == PACK_ACK)							 /* Ӧ�������� */
									{  
													PACK_FLAG = PACK_ACK;
													state ++;
													crc = crc + temp_data;	
													break;
									}			 				 
									else if(temp_data == PACK_VERSION)					 /* ��ȡ��������Ϣ���� */
									{ 
													PACK_FLAG = PACK_VERSION,
													state ++,
													crc = crc + temp_data;	   	     
													break;
									}
									else state = 0,crc = 0;
								case 6: if(temp_data == chunk_offset)          /* ƫ�Ƶ�ַ */
												{  
													state ++;
													crc = crc + temp_data;
													break; 	  
												}	
												else state = 0,crc = 0;
								case 7: if(temp_data == chunk_offset)
												{  
													state ++;
													crc = crc + temp_data;
													break;
												}
												else state = 0,crc = 0;
								case 8: 
										data_len = (u16)temp_data;								 /* ���ݳ��ȵͰ�λ */
										state ++; 
										crc = crc + temp_data;
										break;																			 
								case 9: 
										data_len = data_len + ((u16)temp_data<<8); 			 /* ���ݳ��ȸ߰�λ */
										state ++;
										crc = crc + temp_data;
										break; 
								default: break;
						}
				}
				else if(state == 10 ) state_flag = 0;                    /*��switch������ʱstateΪ10����temp_data��Ϊ���볤�ȸ߰�λ���ݣ�������һ���ж�*/
				if(PACK_FLAG == PACK_GET_DISTANCE&&state_flag == 0)      /* ��ȡһ֡���ݲ�У�� */
				{
						if(state>9)
						{
								if(state<190)
								{
										static uint8_t state_num;
										state_num = (state-10)%15;
										switch(state_num)
										{
												case 0: 
													Pack_Data1[cnt].distance = (uint16_t)temp_data ;				 /* �������ݵͰ�λ */
													crc = crc + temp_data;
													state++;
													break;        
												case 1: 
													Pack_Data1[cnt].distance = ((u16)temp_data<<8) + Pack_Data1[cnt].distance;	 /* �������� */
													crc = crc + temp_data;
													state++;
													break; 
												case 2:
													Pack_Data1[cnt].noise = (u16)temp_data;				 /* ���������Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 3:
													Pack_Data1[cnt].noise = ((u16)temp_data<<8) + Pack_Data1[cnt].noise;				 /* �������� */
													crc = crc + temp_data;
													state++;
													break; 
												case 4:
													Pack_Data1[cnt].peak = (u32)temp_data;				 										 /* ����ǿ����Ϣ�Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 5:
													Pack_Data1[cnt].peak = ((u32)temp_data<<8) + Pack_Data1[cnt].peak;
													crc = crc + temp_data;
													state++;
													break; 
												case 6:
													Pack_Data1[cnt].peak = ((u32)temp_data<<16) + Pack_Data1[cnt].peak;	
													crc = crc + temp_data;
													state++;
													break; 
												case 7:
													Pack_Data1[cnt].peak = ((u32)temp_data<<24) + Pack_Data1[cnt].peak;				    /* ����ǿ����Ϣ */
													crc = crc + temp_data;
													state++;
													break; 
												case 8:
													Pack_Data1[cnt].confidence = temp_data;				 /* ���Ŷ� */
													crc = crc + temp_data;
													state++;
													break; 
												case 9:
													Pack_Data1[cnt].intg = (u32)temp_data;															/* ���ִ����Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 10:
													Pack_Data1[cnt].intg = ((u32)temp_data<<8) + Pack_Data1[cnt].intg;
													crc = crc + temp_data;
													state++;
													break; 
												case 11:
													Pack_Data1[cnt].intg = ((u32)temp_data<<16) + Pack_Data1[cnt].intg;
													crc = crc + temp_data;
													state++;
													break; 
												case 12:
													Pack_Data1[cnt].intg = ((u32)temp_data<<24) + Pack_Data1[cnt].intg;				  	 /* ���ִ��� */
													crc = crc + temp_data;
													state++;
													break; 
												case 13:
													Pack_Data1[cnt].reftof = (int16_t)temp_data;				 								 /* �¶ȱ���ֵ�Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 14:
													Pack_Data1[cnt].reftof = ((int16_t)temp_data<<8) +Pack_Data1[cnt].reftof;			/* �¶ȱ���ֵ */
													crc = crc + temp_data;
													state++;
													cnt++;							 /* ������һ�������� */
													break; 
												default: break;
										}
							}
										/* ʱ���?*/ //��Ϊ��12������������STATEֵΪ190����ˣ�ʱ��֡Ӧ�ô�?91��ʼ��STATE��191��ʼ
										if(state == 191) timestamp = temp_data,state++,crc = crc + temp_data;
										else if(state == 192) timestamp = ((u32)temp_data<<8) + timestamp,state++,crc = crc + temp_data; 
										else if(state == 193) timestamp = ((u32)temp_data<<16) + timestamp,state++,crc = crc + temp_data;
										else if(state == 194) timestamp = ((u32)temp_data<<24) + timestamp,state++,crc = crc + temp_data; 
										else if(state==195)
										{
													if(temp_data == crc)   /* У��ɹ�?*/
													{
															data1_process();  	 /* ���ݴ����������һ֮֡��ɽ������ݴ��� */
															receive_cnt1++;	 	 /* ������յ���ȷ���ݵĴ���?*/
													}
													distance1 = Pack_Data1[0].distance;
													crc = 0;
													state = 0;
													state_flag = 1;
													cnt = 0; 							 /* ��λ*/
										}
										 if(state == 190) state++;//state����190������ʵ���ǵ�12����������һλ���ݣ������Ѿ�ȡ��ʹ��
							
						}
				}
			HAL_UART_Receive_IT(&huart4,Uart4_Receive_buf,sizeof(Uart4_Receive_buf));//����5�ص�����ִ�����֮����Ҫ�ٴο��������жϵȴ���һ�ν����жϵķ���?
	}
	

	  	
	
	
	
	
	
	
	
	
			else if(huart -> Instance == USART1)
	{
			temp_data=Usart1_Receive_buf[0];	
			if(state< 4) 																					 /* ��ʼ����֤ ǰ4�����ݾ�Ϊ0xAA */
				{                                          
						if(temp_data == HEADER) state ++;
						else state = 0;
				}
				else if(state<10&&state>3)
				{
						switch(state)
						{
								case 4:   
									if(temp_data == device_address)              /* �豸��ַ��֤ */
									{							
													state ++;
													crc = crc + temp_data;									
													break;        
									} 
									else state = 0,crc = 0;
								case 5:   
									if(temp_data == PACK_GET_DISTANCE)					 /* ��ȡ������������ */
									{  
													PACK_FLAG = PACK_GET_DISTANCE;
													state ++;	
													crc = crc + temp_data;	
													break;									
									}		 

									else if(temp_data == PACK_RESET_SYSTEM) 		 /* ��λ���� */
									{
													PACK_FLAG = PACK_RESET_SYSTEM;
													state ++; 
													crc = crc + temp_data;	
													break;	
									}
									else if(temp_data == PACK_STOP)							 /* ֹͣ�������ݴ������� */
									{ 
													PACK_FLAG = PACK_STOP;
													state ++; 
													crc = crc + temp_data;	
													break;
									}
									else if(temp_data == PACK_ACK)							 /* Ӧ�������� */
									{  
													PACK_FLAG = PACK_ACK;
													state ++;
													crc = crc + temp_data;	
													break;
									}			 				 
									else if(temp_data == PACK_VERSION)					 /* ��ȡ��������Ϣ���� */
									{ 
													PACK_FLAG = PACK_VERSION,
													state ++,
													crc = crc + temp_data;	   	     
													break;
									}
									else state = 0,crc = 0;
								case 6: if(temp_data == chunk_offset)          /* ƫ�Ƶ�ַ */
												{  
													state ++;
													crc = crc + temp_data;
													break; 	  
												}	
												else state = 0,crc = 0;
								case 7: if(temp_data == chunk_offset)
												{  
													state ++;
													crc = crc + temp_data;
													break;
												}
												else state = 0,crc = 0;
								case 8: 
										data_len = (u16)temp_data;								 /* ���ݳ��ȵͰ�λ */
										state ++; 
										crc = crc + temp_data;
										break;																			 
								case 9: 
										data_len = data_len + ((u16)temp_data<<8); 			 /* ���ݳ��ȸ߰�λ */
										state ++;
										crc = crc + temp_data;
										break; 
								default: break;
						}
				}
				else if(state == 10 ) state_flag = 0;                    /*��switch������ʱstateΪ10����temp_data��Ϊ���볤�ȸ߰�λ���ݣ�������һ���ж�*/
				if(PACK_FLAG == PACK_GET_DISTANCE&&state_flag == 0)      /* ��ȡһ֡���ݲ�У�� */
				{
						if(state>9)
						{
								if(state<190)
								{
										static uint8_t state_num;
										state_num = (state-10)%15;
										switch(state_num)
										{
												case 0: 
													Pack_Data2[cnt].distance = (uint16_t)temp_data ;				 /* �������ݵͰ�λ */
													crc = crc + temp_data;
													state++;
													break;        
												case 1: 
													Pack_Data2[cnt].distance = ((u16)temp_data<<8) + Pack_Data2[cnt].distance;	 /* �������� */
													crc = crc + temp_data;
													state++;
													break; 
												case 2:
													Pack_Data2[cnt].noise = (u16)temp_data;				 /* ���������Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 3:
													Pack_Data2[cnt].noise = ((u16)temp_data<<8) + Pack_Data2[cnt].noise;				 /* �������� */
													crc = crc + temp_data;
													state++;
													break; 
												case 4:
													Pack_Data2[cnt].peak = (u32)temp_data;				 										 /* ����ǿ����Ϣ�Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 5:
													Pack_Data2[cnt].peak = ((u32)temp_data<<8) + Pack_Data2[cnt].peak;
													crc = crc + temp_data;
													state++;
													break; 
												case 6:
													Pack_Data2[cnt].peak = ((u32)temp_data<<16) + Pack_Data2[cnt].peak;	
													crc = crc + temp_data;
													state++;
													break; 
												case 7:
													Pack_Data2[cnt].peak = ((u32)temp_data<<24) + Pack_Data2[cnt].peak;				    /* ����ǿ����Ϣ */
													crc = crc + temp_data;
													state++;
													break; 
												case 8:
													Pack_Data2[cnt].confidence = temp_data;				 /* ���Ŷ� */
													crc = crc + temp_data;
													state++;
													break; 
												case 9:
													Pack_Data2[cnt].intg = (u32)temp_data;															/* ���ִ����Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 10:
													Pack_Data2[cnt].intg = ((u32)temp_data<<8) + Pack_Data2[cnt].intg;
													crc = crc + temp_data;
													state++;
													break; 
												case 11:
													Pack_Data2[cnt].intg = ((u32)temp_data<<16) + Pack_Data2[cnt].intg;
													crc = crc + temp_data;
													state++;
													break; 
												case 12:
													Pack_Data2[cnt].intg = ((u32)temp_data<<24) + Pack_Data2[cnt].intg;				  	 /* ���ִ��� */
													crc = crc + temp_data;
													state++;
													break; 
												case 13:
													Pack_Data2[cnt].reftof = (int16_t)temp_data;				 								 /* �¶ȱ���ֵ�Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 14:
													Pack_Data2[cnt].reftof = ((int16_t)temp_data<<8) +Pack_Data2[cnt].reftof;			/* �¶ȱ���ֵ */
													crc = crc + temp_data;
													state++;
													cnt++;							 /* ������һ�������� */
													break; 
												default: break;
										}
							}
										/* ʱ���?*/ //��Ϊ��12������������STATEֵΪ190����ˣ�ʱ��֡Ӧ�ô�?91��ʼ��STATE��191��ʼ
										if(state == 191) timestamp = temp_data,state++,crc = crc + temp_data;
										else if(state == 192) timestamp = ((u32)temp_data<<8) + timestamp,state++,crc = crc + temp_data; 
										else if(state == 193) timestamp = ((u32)temp_data<<16) + timestamp,state++,crc = crc + temp_data;
										else if(state == 194) timestamp = ((u32)temp_data<<24) + timestamp,state++,crc = crc + temp_data; 
										else if(state==195)
										{
													if(temp_data == crc)   /* У��ɹ�?*/
													{
															data2_process();  	 /* ���ݴ����������һ֮֡��ɽ������ݴ��� */
															receive_cnt2++;	 	 /* ������յ���ȷ���ݵĴ���?*/
													}
													distance2 = Pack_Data2[0].distance;
													crc = 0;
													state = 0;
													state_flag = 1;
													cnt = 0; 							 /* ��λ*/
										}
										 if(state == 190) state++;//state����190������ʵ���ǵ�12����������һλ���ݣ������Ѿ�ȡ��ʹ��
							
						}
				}
			HAL_UART_Receive_IT(&huart1,Usart1_Receive_buf,sizeof(Usart1_Receive_buf));//����5�ص�����ִ�����֮����Ҫ�ٴο��������жϵȴ���һ�ν����жϵķ���?
	}
	

	
	
	
	
	
	
	
	
	
	


			else	if(huart -> Instance == USART2)
	{
			temp_data=Usart2_Receive_buf[0];	
			if(state< 4) 																					 /* ��ʼ����֤ ǰ4�����ݾ�Ϊ0xAA */
				{                                          
						if(temp_data == HEADER) state ++;
						else state = 0;
				}
				else if(state<10&&state>3)
				{
						switch(state)
						{
								case 4:   
									if(temp_data == device_address)              /* �豸��ַ��֤ */
									{							
													state ++;
													crc = crc + temp_data;									
													break;        
									} 
									else state = 0,crc = 0;
								case 5:   
									if(temp_data == PACK_GET_DISTANCE)					 /* ��ȡ������������ */
									{  
													PACK_FLAG = PACK_GET_DISTANCE;
													state ++;	
													crc = crc + temp_data;	
													break;									
									}		 

									else if(temp_data == PACK_RESET_SYSTEM) 		 /* ��λ���� */
									{
													PACK_FLAG = PACK_RESET_SYSTEM;
													state ++; 
													crc = crc + temp_data;	
													break;	
									}
									else if(temp_data == PACK_STOP)							 /* ֹͣ�������ݴ������� */
									{ 
													PACK_FLAG = PACK_STOP;
													state ++; 
													crc = crc + temp_data;	
													break;
									}
									else if(temp_data == PACK_ACK)							 /* Ӧ�������� */
									{  
													PACK_FLAG = PACK_ACK;
													state ++;
													crc = crc + temp_data;	
													break;
									}			 				 
									else if(temp_data == PACK_VERSION)					 /* ��ȡ��������Ϣ���� */
									{ 
													PACK_FLAG = PACK_VERSION,
													state ++,
													crc = crc + temp_data;	   	     
													break;
									}
									else state = 0,crc = 0;
								case 6: if(temp_data == chunk_offset)          /* ƫ�Ƶ�ַ */
												{  
													state ++;
													crc = crc + temp_data;
													break; 	  
												}	
												else state = 0,crc = 0;
								case 7: if(temp_data == chunk_offset)
												{  
													state ++;
													crc = crc + temp_data;
													break;
												}
												else state = 0,crc = 0;
								case 8: 
										data_len = (u16)temp_data;								 /* ���ݳ��ȵͰ�λ */
										state ++; 
										crc = crc + temp_data;
										break;																			 
								case 9: 
										data_len = data_len + ((u16)temp_data<<8); 			 /* ���ݳ��ȸ߰�λ */
										state ++;
										crc = crc + temp_data;
										break; 
								default: break;
						}
				}
				else if(state == 10 ) state_flag = 0;                    /*��switch������ʱstateΪ10����temp_data��Ϊ���볤�ȸ߰�λ���ݣ�������һ���ж�*/
				if(PACK_FLAG == PACK_GET_DISTANCE&&state_flag == 0)      /* ��ȡһ֡���ݲ�У�� */
				{
						if(state>9)
						{
								if(state<190)
								{
										static uint8_t state_num;
										state_num = (state-10)%15;
										switch(state_num)
										{
												case 0: 
													Pack_Data5[cnt].distance = (uint16_t)temp_data ;				 /* �������ݵͰ�λ */
													crc = crc + temp_data;
													state++;
													break;        
												case 1: 
													Pack_Data5[cnt].distance = ((u16)temp_data<<8) + Pack_Data5[cnt].distance;	 /* �������� */
													crc = crc + temp_data;
													state++;
													break; 
												case 2:
													Pack_Data5[cnt].noise = (u16)temp_data;				 /* ���������Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 3:
													Pack_Data5[cnt].noise = ((u16)temp_data<<8) + Pack_Data5[cnt].noise;				 /* �������� */
													crc = crc + temp_data;
													state++;
													break; 
												case 4:
													Pack_Data5[cnt].peak = (u32)temp_data;				 										 /* ����ǿ����Ϣ�Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 5:
													Pack_Data5[cnt].peak = ((u32)temp_data<<8) + Pack_Data5[cnt].peak;
													crc = crc + temp_data;
													state++;
													break; 
												case 6:
													Pack_Data5[cnt].peak = ((u32)temp_data<<16) + Pack_Data5[cnt].peak;	
													crc = crc + temp_data;
													state++;
													break; 
												case 7:
													Pack_Data5[cnt].peak = ((u32)temp_data<<24) + Pack_Data5[cnt].peak;				    /* ����ǿ����Ϣ */
													crc = crc + temp_data;
													state++;
													break; 
												case 8:
													Pack_Data5[cnt].confidence = temp_data;				 /* ���Ŷ� */
													crc = crc + temp_data;
													state++;
													break; 
												case 9:
													Pack_Data5[cnt].intg = (u32)temp_data;															/* ���ִ����Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 10:
													Pack_Data5[cnt].intg = ((u32)temp_data<<8) + Pack_Data5[cnt].intg;
													crc = crc + temp_data;
													state++;
													break; 
												case 11:
													Pack_Data5[cnt].intg = ((u32)temp_data<<16) + Pack_Data5[cnt].intg;
													crc = crc + temp_data;
													state++;
													break; 
												case 12:
													Pack_Data5[cnt].intg = ((u32)temp_data<<24) + Pack_Data5[cnt].intg;				  	 /* ���ִ��� */
													crc = crc + temp_data;
													state++;
													break; 
												case 13:
													Pack_Data5[cnt].reftof = (int16_t)temp_data;				 								 /* �¶ȱ���ֵ�Ͱ�λ */
													crc = crc + temp_data;
													state++;
													break; 
												case 14:
													Pack_Data5[cnt].reftof = ((int16_t)temp_data<<8) +Pack_Data5[cnt].reftof;			/* �¶ȱ���ֵ */
													crc = crc + temp_data;
													state++;
													cnt++;							 /* ������һ�������� */
													break; 
												default: break;
										}
							}
										/* ʱ���?*/ //��Ϊ��12������������STATEֵΪ190����ˣ�ʱ��֡Ӧ�ô�?91��ʼ��STATE��191��ʼ
										if(state == 191) timestamp = temp_data,state++,crc = crc + temp_data;
										else if(state == 192) timestamp = ((u32)temp_data<<8) + timestamp,state++,crc = crc + temp_data; 
										else if(state == 193) timestamp = ((u32)temp_data<<16) + timestamp,state++,crc = crc + temp_data;
										else if(state == 194) timestamp = ((u32)temp_data<<24) + timestamp,state++,crc = crc + temp_data; 
										else if(state==195)
										{
													if(temp_data == crc)   /* У��ɹ�?*/
													{
															data5_process();  	 /* ���ݴ����������һ֮֡��ɽ������ݴ��� */
															receive_cnt5++;	 	 /* ������յ���ȷ���ݵĴ���?*/
													}
													distance5 = Pack_Data5[0].distance;
													crc = 0;
													state = 0;
													state_flag = 1;
													cnt = 0; 							 /* ��λ*/
										}
										 if(state == 190) state++;//state����190������ʵ���ǵ�12����������һλ���ݣ������Ѿ�ȡ��ʹ��
							
						}
				}
			HAL_UART_Receive_IT(&huart2,Usart2_Receive_buf,sizeof(Usart2_Receive_buf));//����5�ص�����ִ�����֮����Ҫ�ٴο��������жϵȴ���һ�ν����жϵķ���?
	}
	
		
		else if(huart -> Instance == USART6)//6
{
//    static uint8_t rx_buffer[11];           // (0x7B + 2 + 2 + checksum + 0x7D)
//    static uint8_t rx_state = 0;           // 
//    static uint8_t rx_counter = 0;         // 
//    static uint8_t checksum = 0;           // 

    if (huart != &huart6) return;         

    if (rx_state == 0) {
        /* 0x7B */
        if (uart_rx_byte == 0x7B) {
            rx_counter = 0;
            checksum = 0;
            rx_buffer[rx_counter++] = uart_rx_byte;
            checksum ^= uart_rx_byte;     
            rx_state = 1;               
        }
    } else {
        rx_buffer[rx_counter] = uart_rx_byte;
        
        /* (0x7B + pwm_left + pwm_right) */
        if (rx_counter < 9) checksum ^= uart_rx_byte;
        
        if (++rx_counter >= sizeof(rx_buffer)) {
            rx_state = 0;  
            if (rx_buffer[11] == 0x7D && rx_buffer[9] == checksum) {
                UART_ParsePacket(rx_buffer);  
                speed_updated = 1;            
            }
        }
    }

    HAL_UART_Receive_IT(&huart6, &uart_rx_byte, 1);

}
}



/*

��ǰ    d1     u4			c10c11 
��ǰ		d2		us1			a9a10
����		d3		u5			d2c12
����		d4		us2			d5d6
��			d5		us3			b10b11

5->4
*/




void data1_process(void)/*���ݴ����������һ֮֡��ɽ������ݴ���*/
{
		/* �������?*/
		static u8 cnt = 0;
		u8 i;
		static u16 count = 0;
		static u32 sum = 0;
		LidarPointTypedef Pack_sum1;
		for(i=0;i<12;i++)									/* 12����ȡƽ�� */
		{
				if(Pack_Data1[i].distance != 0)  /* ȥ��0�ĵ� */
				{
						count++;
						Pack_sum1.distance += Pack_Data1[i].distance;
						Pack_sum1.noise += Pack_Data1[i].noise;
						Pack_sum1.peak += Pack_Data1[i].peak;
						Pack_sum1.confidence += Pack_Data1[i].confidence;
						Pack_sum1.intg += Pack_Data1[i].intg;
						Pack_sum1.reftof += Pack_Data1[i].reftof;
				}
		}
		if(count !=0)
		{

					distance1 = Pack_sum1.distance/count;
					noise1 = Pack_sum1.noise/count;
					peak1 = Pack_sum1.peak/count;
					confidence1 = Pack_sum1.confidence/count;
					intg1 = Pack_sum1.intg/count;
					reftof1 = Pack_sum1.reftof/count;
					Pack_sum1.distance = 0;
					Pack_sum1.noise = 0;
					Pack_sum1.peak = 0;
					Pack_sum1.confidence = 0;
					Pack_sum1.intg = 0;
					Pack_sum1.reftof = 0;
					count = 0;
		}
	}

void data2_process(void)/*���ݴ����������һ֮֡��ɽ������ݴ���*/
{
		/* �������?*/
		static u8 cnt = 0;
		u8 i;
		static u16 count = 0;
		static u32 sum = 0;
		LidarPointTypedef Pack_sum2;				/* 12����ȡƽ�� */
		{
				if(Pack_Data2[i].distance != 0)  /* ȥ��0�ĵ� */
				{
						count++;
						Pack_sum2.distance += Pack_Data1[i].distance;
						Pack_sum2.noise += Pack_Data1[i].noise;
						Pack_sum2.peak += Pack_Data1[i].peak;
						Pack_sum2.confidence += Pack_Data1[i].confidence;
						Pack_sum2.intg += Pack_Data1[i].intg;
						Pack_sum2.reftof += Pack_Data1[i].reftof;
				}
		}
		if(count !=0)
		{

					distance2 = Pack_sum2.distance/count;
					noise2 = Pack_sum2.noise/count;
					peak2 = Pack_sum2.peak/count;
					confidence2 = Pack_sum2.confidence/count;
					intg2 = Pack_sum2.intg/count;
					reftof2 = Pack_sum2.reftof/count;
					Pack_sum2.distance = 0;
					Pack_sum2.noise = 0;
					Pack_sum2.peak = 0;
					Pack_sum2.confidence = 0;
					Pack_sum2.intg = 0;
					Pack_sum2.reftof = 0;
					count = 0;
		}
	}

	void data5_process(void)/*���ݴ����������һ֮֡��ɽ������ݴ���*/
{
		/* �������?*/
		static u8 cnt = 0;
		u8 i;
		static u16 count = 0;
		static u32 sum = 0;
		LidarPointTypedef Pack_sum5;				/* 12����ȡƽ�� */
		{
				if(Pack_Data5[i].distance != 0)  /* ȥ��0�ĵ� */
				{
						count++;
						Pack_sum5.distance += Pack_Data5[i].distance;
						Pack_sum5.noise += Pack_Data5[i].noise;
						Pack_sum5.peak += Pack_Data5[i].peak;
						Pack_sum5.confidence += Pack_Data5[i].confidence;
						Pack_sum5.intg += Pack_Data5[i].intg;
						Pack_sum5.reftof += Pack_Data5[i].reftof;
				}
		}
		if(count !=0)
		{

					distance5 = Pack_sum5.distance/count;
					noise5 = Pack_sum5.noise/count;
					peak5 = Pack_sum5.peak/count;
					confidence5 = Pack_sum5.confidence/count;
					intg5 = Pack_sum5.intg/count;
					reftof5 = Pack_sum5.reftof/count;
					Pack_sum5.distance = 0;
					Pack_sum5.noise = 0;
					Pack_sum5.peak = 0;
					Pack_sum5.confidence = 0;
					Pack_sum5.intg = 0;
					Pack_sum5.reftof = 0;
					count = 0;
		}
	}




/* USER CODE END 1 */
