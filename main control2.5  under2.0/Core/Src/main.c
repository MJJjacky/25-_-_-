/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
#include "OLED.h"
#include "E18.h"

#include "stdio.h"
#include "string.h"//标准库和字符串，防报错
#include "serial.h"

#include "on_stage.h"
#include "under_stage.h"
//#include "judge.h"
#include "attack.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
//uint16_t AD0, AD1, AD2, AD3;
//uint16_t ADC_value[4]; //变量易变，编译器不能随便优化(?)


/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//激光参数
u16 receive_cnt1;
u8 confidence1;
u16 distance1,noise1,reftof1;
u32 peak1,intg1;
u8 dis1;
extern LidarPointTypedef Pack_sum1;

u16 receive_cnt2;
u8 confidence2;
u16 distance2,noise2,reftof2;
u32 peak2,intg2;
u8 dis2;
extern LidarPointTypedef Pack_sum2; 

u16 receive_cnt3;
u8 confidence3;
u16 distance3,noise3,reftof3;
u32 peak3,intg3;
u8 dis3;
extern LidarPointTypedef Pack_sum3; 

u16 receive_cnt4;
u8 confidence4;
u16 distance4,noise4,reftof4;//1
u32 peak4,intg4;
u8 dis4;
extern LidarPointTypedef Pack_sum4; 

u16 receive_cnt5;
u8 confidence5;
u16 distance5,noise5,reftof5;
u32 peak5,intg5;
u8 dis5;
extern LidarPointTypedef Pack_sum5; 

extern  adcValue_type adcValue ;
extern uint16_t left_laser;//?
extern uint16_t right_laser;//?

	 uint8_t j;
   uint16_t judge = 1;
//u16 receive_cnt4;
//u8 confidence4;
//u16 distance4,noise4,reftof4;
//u32 peak3,intg4;
//u8 dis4;
//extern LidarPointTypedef Pack_sum4; 
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	OLED_Init();//只能放这里
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_TIM2_Init();
  MX_UART4_Init();
  MX_UART5_Init();
  MX_USART6_UART_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
	PWM_Init();
	UART_Init();

  HAL_TIM_Base_Start_IT(&htim1);

//	HAL_ADC_Start(&hadc1);     
	//HAL_ADCEx_Calibration_Start(&hadc1);    //ADC校准，f4不能用
	
//	AD_DMA_Init();

//	OLED_ShowString(1, 1, "AD0:");
//	OLED_ShowString(2, 1, "AD1:");
//	OLED_ShowString(3, 1, "AD2:");
//	OLED_ShowString(4, 1, "AD3:");
  /* USER CODE END 2 */
	HAL_Delay(800);
	move(0,0);
	while (1){
			move(0,0);
		if(left_laser<=80&&right_laser<=80){
			break;
		}
	}
		move(-23,-23);
		HAL_Delay(600);
		move(-19,-19);
		HAL_Delay(600);
		move(-14,-20);
		HAL_Delay(600);
		
		move(0,0);
		HAL_Delay(300);
	
//		move(-8,8);
//		HAL_Delay(400);
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		OLED_ShowNum(4,15,judge,1);
		OLED_ShowNum(2,15,j,1);
	if(judge){
		tai_shang_control();
//		move(0,0);
		}
	else{
		under_stage_control();
		}
//		tai_shang_control();
		//move(10,10);
//		move(10,10);
//		HAL_Delay(2400);
//		move(-10,-10);
//		HAL_Delay(1000);
		
//		tai_shang_control();
		
		
		
//		if(j==1){
//		tai_shang_control();
//		}
//		else{
//		move(0,0);
//				HAL_Delay(2000);
//		move(-22,-22);
//		HAL_Delay(500);
//		move(-19,-19);
//		HAL_Delay(600);
//		move(-10,-10);
//		HAL_Delay(500);

//		move(0,0);
//		HAL_Delay(100000);
//				
//move(-25,-25);
//		HAL_Delay(400);
//		move(-15,-15);
//		HAL_Delay(1200);
//		
//		
//		move(0,0);
//				HAL_Delay(4000);
//				break;
				
//		}
//				getAD();
//		u8 j=direction_judge();
//		OLED_ShowNum(3,11,j,1);
		
//		OLED_ShowNum(1,1,distance1 ,5);
//	OLED_ShowNum(2,1,distance2 ,5);
//	OLED_ShowNum(3,1,distance3 ,5);
//	OLED_ShowNum(4,1,distance4 ,5);
//	OLED_ShowNum(1,11,distance5 ,5);

//		OLED_ShowHexNum(1, 1, distance1, 5);
//		OLED_ShowNum(1, 1, 1, 1);
//		int dt;
//		dt = direction_judge();

//		
//		if(dt){
//		tai_shang_control();
//		}else{
//		under_stage_control();
//		}
		
		

		
//		char str[64];//存储数组
//		
//		HAL_ADC_Start(&hadc1);    //开
//		HAL_ADC_PollForConversion(&hadc1, 50);   //超时报错
// 
//		HAL_ADC_Start_DMA(&hadc1,(uint32_t*)ADC_value,8);//半字，4个通道，每个通道一个字长
// 
//		//sprintf(str,"%f,%f,%f,%f\r\n",(ADC_value[0]*3.3)/4095,(ADC_value[1]*3.3)/4095,(ADC_value[2]*3.3)/4095,(ADC_value[3]*3.3)/4095);   //一次触发无限次采样
//	   HAL_UART_Transmit(&huart1,(uint8_t*)str,strlen(str),HAL_MAX_DELAY);//DMA转运
//		HAL_Delay(10);
                        

//单通道
//		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
//		{
//			AD0 = HAL_ADC_GetValue(&hadc1);   
//			
//		OLED_ShowNum(1, 5, AD0, 4);				
//		OLED_ShowNum(2, 5, AD1, 4);				
//		OLED_ShowNum(3, 5, AD2, 4);				
//		OLED_ShowNum(4, 5, AD3, 4);				
//		
//			HAL_Delay(10);
//		}
	}

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {

  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
