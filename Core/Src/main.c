/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdio.h"
#include "math.h"

#define SINE_TABLE_SIZE 256
#define PI 3.14159265358979323846

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// happy birthday
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c1;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim8;

UART_HandleTypeDef huart1;

PCD_HandleTypeDef hpcd_USB_FS;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_SPI1_Init(void);
static void MX_USB_PCD_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM7_Init(void);
static void MX_TIM3_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM8_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void off() {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, SET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);

}

void show_0() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);

}
void show_1() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
}
void show_2() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
}
void show_3() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);

}
void show_4() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
}
void show_5() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
}
void show_6() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
}
void show_7() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
}
void show_8() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, SET);
}
void show_9() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, SET);
}
void reset() {
	off();
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, RESET);
	show_0();
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
	show_0();
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, RESET);
	show_0();
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, RESET);
	show_0();
}

void led_off() {
	TIM1->CCR2 = 0;
	TIM1->CCR3 = 0;
	TIM2->CCR2 = 0;
	TIM8->CCR4 = 0;
	TIM8->CCR1 = 0;
	TIM8->CCR2 = 0;
	TIM8->CCR3 = 0;
	TIM1->CCR4 = 0;
	TIM2->CCR4 = 0;
	TIM2->CCR3 = 0;
	TIM1->CCR1 = 0;
}
typedef void (*func_ptr)();
func_ptr functionArray[10] = { show_0, show_1, show_2, show_3, show_4, show_5,
		show_6, show_7, show_8, show_9 };
int mood_g = 0;

int melody[] = {
NOTE_AS4, 8, NOTE_AS4, 8, NOTE_AS4,
		8, //1
		NOTE_F5, 2, NOTE_C6, 2,
		NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6, 4,
		NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6, 4,
		NOTE_AS5, 8, NOTE_A5, 8, NOTE_AS5, 8, NOTE_G5, 2, NOTE_C5, 8, NOTE_C5,
		8, NOTE_C5, 8,
		NOTE_F5, 2, NOTE_C6, 2,
		NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6, 4,

		NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6,
		4, //8
		NOTE_AS5, 8, NOTE_A5, 8, NOTE_AS5, 8, NOTE_G5, 2, NOTE_C5, -8, NOTE_C5,
		16,
		NOTE_D5, -4, NOTE_D5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5,
		8,
		NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 4, NOTE_D5, 8, NOTE_E5, 4,
		NOTE_C5, -8, NOTE_C5, 16,
		NOTE_D5, -4, NOTE_D5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5,
		8,

		NOTE_C6, -8,
		NOTE_G5, 16,
		NOTE_G5, 2,
		REST, 8,
		NOTE_C5, 8,
		NOTE_D5, -4, NOTE_D5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5,
		8,
		NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 4, NOTE_D5, 8, NOTE_E5, 4,
		NOTE_C6, -8, NOTE_C6, 16,
		NOTE_F6, 4, NOTE_DS6, 8, NOTE_CS6, 4, NOTE_C6, 8, NOTE_AS5, 4, NOTE_GS5,
		8, NOTE_G5, 4, NOTE_F5, 8,
		NOTE_C6, 1

};
int noteDurations[] = { 500, 500, 500, 1000, 1000, 500, 500, 500, 1000, 500,
		500, 500, 500, 1000, 500, 500, 500, 500, 1000, 500, 500, 500, 1000,
		1000, 500, 500, 500, 1000, 500, 500, 500, 500, 1000, 500, 500, 500, 500,
		1000, 500, 500, 750, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500,
		500, 750, 500, 750, 500, 500, 500, 500, 500, 1500, 500, 500, 250, 500,
		750, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 750, 500,
		1000, 500, 500, 500, 500, 500, 500, 500, 2000 };

void playTone(uint16_t frequency, uint32_t duration) {
	uint32_t period = HAL_RCC_GetPCLK1Freq() / (htim4.Init.Prescaler + 1)
			/ frequency - 1;
	__HAL_TIM_SET_AUTORELOAD(&htim4, period);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, period / 2);
	uint32_t startTick = HAL_GetTick();
	while ((HAL_GetTick() - startTick) < duration * 0.9) { // Wait for 90% of the duration
	}
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0); // Turn off the sound
	startTick = HAL_GetTick();
	while ((HAL_GetTick() - startTick) < duration * 0.1) {
		// Short delay between notes

	}
}

// happy birth day
int melody_2[] = {

// Happy Birthday
// Score available at https://musescore.com/user/8221/scores/26906

		NOTE_C4, 4, NOTE_C4, 8,
		NOTE_D4, -4, NOTE_C4, -4, NOTE_F4, -4,
		NOTE_E4, -2, NOTE_C4, 4, NOTE_C4, 8,
		NOTE_D4, -4, NOTE_C4, -4, NOTE_G4, -4,
		NOTE_F4, -2, NOTE_C4, 4, NOTE_C4, 8,

		NOTE_C5, -4, NOTE_A4, -4, NOTE_F4, -4,
		NOTE_E4, -4, NOTE_D4, -4, NOTE_AS4, 4, NOTE_AS4, 8,
		NOTE_A4, -4, NOTE_F4, -4, NOTE_G4, -4,
		NOTE_F4, -2,

};

int noteDurations_2[] = { 250, 125, 375, 375, 375, 750, 250, 125, 375, 375, 375,
		750, 250, 125, 375, 375, 375, 375, 375, 250, 125, 375, 375, 375, 1500 };

void playTone_2(uint16_t frequency, uint32_t duration) {
	uint32_t period = HAL_RCC_GetPCLK1Freq() / (htim4.Init.Prescaler + 1)
			/ frequency - 1;
	__HAL_TIM_SET_AUTORELOAD(&htim4, period);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, period / 2);

	uint32_t startTick = HAL_GetTick();

	while ((HAL_GetTick() - startTick) < (duration * 0.9)) {

	}

	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);

	startTick = HAL_GetTick();

	while ((HAL_GetTick() - startTick) < (duration * 0.1)) {

	}
}

char username[6];
int password[4];
int T_G[4];
int t_g = 0;
int D_G[4];
int d_g = 0;
int security_check = 0;

void get_user() {
	char user2[6];
	HAL_UART_Transmit(&huart1, "\nusername : ", strlen("\nusername : "),
	HAL_MAX_DELAY);
	HAL_UART_Receive(&huart1, user2, 6, HAL_MAX_DELAY);
	strcpy(username, user2);
	HAL_UART_Transmit(&huart1, username, 6, HAL_MAX_DELAY);
	if (username[0] == 'm') {
		HAL_UART_Transmit(&huart1, 'm', 1, HAL_MAX_DELAY);
	}
}

void get_pass() {
	char pass2[4];
	HAL_UART_Transmit(&huart1, "\npassword : ", strlen("\npassword : "),
	HAL_MAX_DELAY);
	HAL_UART_Receive(&huart1, pass2, 4, HAL_MAX_DELAY);
	for (int i = 0; i < 4; i++) {
		password[i] = pass2[i] - '0';
	}
	if (password[0] == 1) {
		HAL_UART_Transmit(&huart1, "hi", strlen("hi"), HAL_MAX_DELAY);
	}

}
void get_T_D() {
	char t1[4];
	char d1[4];
	HAL_UART_Transmit(&huart1, "\nT : ", strlen("\nT : "), HAL_MAX_DELAY);
	HAL_UART_Receive(&huart1, t1, 4, HAL_MAX_DELAY);
	for (int i = 0; i < 4; i++) {
		T_G[i] = t1[i] - '0';
		t_g = T_G[i] * pow(10, (3 - i)) + t_g;

	}
	if (T_G[0] == 2) {
		HAL_UART_Transmit(&huart1, "heyy", strlen("heyy"), HAL_MAX_DELAY);
	}
	HAL_UART_Transmit(&huart1, "\nD : ", strlen("\nD : "), HAL_MAX_DELAY);
	HAL_UART_Receive(&huart1, d1, 4, HAL_MAX_DELAY);
	for (int i = 0; i < 4; i++) {
		D_G[i] = d1[i] - '0';
		d_g = D_G[i] * pow(10, (3 - i)) + d_g;

	}
	if (D_G[0] == 3) {
		HAL_UART_Transmit(&huart1, "noice", strlen("noice"), HAL_MAX_DELAY);
	}
}
void check_user() {
	char user2[6];
	char user_check[6];
	int j = 0;
	HAL_UART_Transmit(&huart1, "\nusername : ", strlen("\nusername : "),
	HAL_MAX_DELAY);
	HAL_UART_Receive(&huart1, user2, 6, HAL_MAX_DELAY);
	strcpy(user_check, user2);
	for (int i = 0; i < 6; i++) {
		if (user_check[i] != username[i]) {
			HAL_UART_Transmit(&huart1, "\nwrong username! ",
					strlen("\nwrong username! "),
					HAL_MAX_DELAY);
			j = -1;
			break;
		} else {
			j++;
		}

	}
	if (j == -1) {
		check_user();
	} else if (j == 6) {
		HAL_UART_Transmit(&huart1, "\nWelcom ", strlen("\nWelcom "),
		HAL_MAX_DELAY);
		security_check++;
	}
}

void check_pass() {
	char pass2[4];
	char pass_check[4];
	int j = 0;
	HAL_UART_Transmit(&huart1, "\npassword : ", strlen("\npassword : "),
	HAL_MAX_DELAY);
	HAL_UART_Receive(&huart1, pass2, 4, HAL_MAX_DELAY);
	for (int i = 0; i < 4; i++) {
		pass_check[i] = pass2[i] - '0';
	}
	for (int i = 0; i < 4; i++) {
		if (pass_check[i] != password[i]) {
			HAL_UART_Transmit(&huart1, "\nwrong password ",
					strlen("\nwrong password "),
					HAL_MAX_DELAY);
			j = -1;
			break;
		} else {

			j++;
		}
	}
	if (j == -1) {
		check_pass();
	} else if (j == 4) {
		HAL_UART_Transmit(&huart1, "\nWelcome ", strlen("\nWelcome "),
		HAL_MAX_DELAY);
		security_check++;

	}

}

TIM_HandleTypeDef *buzzerPwmTimer;
uint32_t buzzerPwmChannel;

void buzzerInit() {
	buzzerPwmTimer = &htim4;
	buzzerPwmChannel = TIM_CHANNEL_3;
	HAL_TIM_PWM_Start(buzzerPwmTimer, buzzerPwmChannel);
}

void buzzerChangeTone(uint16_t freq, uint16_t volume) {
	if (freq == 0 || freq > 20000) {
		__HAL_TIM_SET_COMPARE(buzzerPwmTimer, buzzerPwmChannel, 0);
	} else {
		const uint32_t internalClockFreq = HAL_RCC_GetSysClockFreq();
		const uint32_t prescaler = 1 + internalClockFreq / freq / 60000;
		const uint32_t timerClock = internalClockFreq / prescaler;
		const uint32_t periodCycles = timerClock / freq;
		const uint32_t pulseWidth = volume * periodCycles / 1000 / 2;

		buzzerPwmTimer->Instance->PSC = prescaler - 1;
		buzzerPwmTimer->Instance->ARR = periodCycles - 1;
		buzzerPwmTimer->Instance->EGR = TIM_EGR_UG;

		__HAL_TIM_SET_COMPARE(buzzerPwmTimer, buzzerPwmChannel, pulseWidth);
	}
}

TIM_HandleTypeDef htim4;
uint32_t period = 0;

void initTimerPWM(void) {
	__HAL_RCC_TIM1_CLK_ENABLE();

	htim4.Instance = TIM4;
	htim4.Init.Prescaler = 79; // Adjust prescaler as needed
	htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim4.Init.Period = period; // Initial period value
	htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim4.Init.RepetitionCounter = 0;
	HAL_TIM_PWM_Init(&htim4);

	TIM_OC_InitTypeDef sConfigOC;
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = period / 2; // Initial pulse value
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3);

	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM4) {
		static uint8_t direction = 0;
		if (direction == 0) {
			period += 10; // Increase frequency
			if (period > 1000)
				direction = 1;
		} else {
			period -= 10; // Decrease frequency
			if (period < 500)
				direction = 0;
		}
		__HAL_TIM_SET_AUTORELOAD(&htim4, period);
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, period / 2);
	}
}

char c_mood[14];
char check_u[20];
char pass_u[4];
int s;
int illegal = 0;
int music = 0;
int first_mood1 = 0;
int first_mood2 = 0;
int first_mood3 = 0;
int stop_flag = 0 ;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART1) {

		if (mood_g == 1) {
			HAL_UART_Transmit(huart, "ok\n", strlen("ok\n"),
			HAL_MAX_DELAY);
			mood_g = c_mood[12] - '0';

		}
		if (mood_g == 2) {
			if (illegal == 0) {
				HAL_UART_Transmit(huart, "ok\n", strlen("ok\n"),
				HAL_MAX_DELAY);
				mood_g = c_mood[12] - '0';

			}

		}
		if (mood_g == 3) {
			first_mood3++;
			if (first_mood3 > 1) {
				HAL_UART_Transmit(huart, "no shit \n", strlen("no shit \n"),
				HAL_MAX_DELAY);
				char c_mood_2[14];
				strcpy(c_mood_2, c_mood);
				if (c_mood_2[7] == 'm') {
					HAL_UART_Transmit(huart, "nice shit \n",
							strlen("nice shit \n"), HAL_MAX_DELAY);
					mood_g = c_mood[12] - '0';
				}
				if (c_mood_2[7] == 'n') {
					HAL_UART_Transmit(huart, "nice job \n",
							strlen("nice job \n"), HAL_MAX_DELAY);
					music = c_mood[12] - '0';

					stop_flag = 0 ;
				}

			}

		}

	}
}

void song2() {
	initTimerPWM();
	int notes = sizeof(melody_2) / sizeof(melody_2[0]);
	for (int thisNote = 0; thisNote < notes; thisNote++) {
		uint16_t note = melody_2[thisNote];
		uint32_t duration = noteDurations_2[thisNote];
		if (note != REST) {
			playTone(note, duration);
		} else {
			HAL_Delay(duration);
		}

	}

}

uint32_t lastBut_13 = 0;
int mood_13 = 0;
uint32_t lastBut_12 = 0;
int mood_12 = 0;
uint32_t lastBut_0 = 0;
int mood_0 = 0;
uint32_t last_blue = 0;

int sum_LED = 0;
int on_led[3];
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (mood_g == 1) {
		if (GPIO_Pin == GPIO_PIN_0) {
			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_SET) {
				if (HAL_GetTick() - lastBut_0 > 400) {
					if (mood_0 % 3 == 0) {
						TIM2->CCR4 = 0;
						on_led[0] = 0;
					}
					if (mood_0 % 3 == 1) {
						TIM2->CCR4 = 200;
						on_led[0] = 1;
					}
					if (mood_0 % 3 == 2) {
						TIM2->CCR4 = 1000;
						on_led[0] = 1;
					}
					lastBut_0 = HAL_GetTick();
					mood_0++;
				}
			}
		}

		if (GPIO_Pin == GPIO_PIN_13) {

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == GPIO_PIN_SET) {
				if (HAL_GetTick() - lastBut_13 > 400) {
					if (mood_13 % 3 == 0) {
						TIM2->CCR3 = 0;
						on_led[1] = 0;
					}
					if (mood_13 % 3 == 1) {
						TIM2->CCR3 = 200;
						on_led[1] = 1;
					}
					if (mood_13 % 3 == 2) {
						TIM2->CCR3 = 1000;
						on_led[1] = 1;
					}
					lastBut_13 = HAL_GetTick();
					mood_13++;

				}

			}
		}

		if (GPIO_Pin == GPIO_PIN_12) {
			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) == GPIO_PIN_SET) {
				if (HAL_GetTick() - lastBut_12 > 400) {
					if (mood_12 % 3 == 0) {
						TIM1->CCR1 = 0;
						on_led[2] = 0;
					}
					if (mood_12 % 3 == 1) {
						TIM1->CCR1 = 200;
						on_led[2] = 1;
					}
					if (mood_12 % 3 == 2) {
						TIM1->CCR1 = 1000;
						on_led[2] = 1;
					}
					lastBut_12 = HAL_GetTick();
					mood_12++;
				}

			}
		}
		sum_LED = on_led[0] + on_led[1] + on_led[2];
	}
	if (mood_g == 2) {
		if (GPIO_Pin == GPIO_PIN_13) {
			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == GPIO_PIN_SET) {
				if (HAL_GetTick() - last_blue > 400) {
					illegal = 1;
					TIM1->CCR3 = 1000;
					last_blue = HAL_GetTick();
				}
			}
		}

	}
}



/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_I2C1_Init();
	MX_SPI1_Init();
	MX_USB_PCD_Init();
	MX_USART1_UART_Init();
	MX_TIM1_Init();
	MX_TIM7_Init();
	MX_TIM3_Init();
	MX_ADC1_Init();
	MX_TIM8_Init();
	MX_TIM2_Init();
	MX_TIM4_Init();
	/* USER CODE BEGIN 2 */

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	/*
	 */



	HAL_TIM_Base_Start_IT(&htim7);
	HAL_ADC_Start(&hadc1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);	// PA 8  external red
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);	// PA 9  external yellow
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);	// PA 10 external green
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);	// PE 11
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);	// PE 13
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);	// PE 14
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);	// PE 8
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_2);	// PE 10
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);	// PE 12
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_4);	// PE 15
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);	// PE 9

	int i = 0;
	uint32_t dance_t = 0;

	uint32_t last_update = 0;
	int j = 0;

	int thisNote_2 = 0;
	uint32_t start_d = 0;
	int notes_2 = sizeof(melody_2) / sizeof(melody_2[0]);



	if (mood_g == 0) {
		get_user();
		get_pass();
		get_T_D();
		mood_g = 1;
	}

	while (1) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, RESET);
		functionArray[mood_g]();
		HAL_Delay(3);
		off();

		if (mood_g == 1) {
			HAL_UART_Receive_IT(&huart1, c_mood, 14);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
			functionArray[sum_LED]();
			HAL_Delay(3);
			off();
			if (HAL_GetTick() - last_update > t_g) {
				HAL_ADC_Start(&hadc1);
				HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
				uint32_t val = HAL_ADC_GetValue(&hadc1);
				char str[20];
				sprintf(str, "%lu\n", val);
				HAL_UART_Transmit(&huart1, str, strlen(str),
				HAL_MAX_DELAY);
				last_update = HAL_GetTick();
			}
		}
		if (mood_g == 2) {

			if (illegal == 1) {

				HAL_Init();
				initTimerPWM();
				HAL_TIM_Base_Start_IT(&htim4);

				if (j == 0) {
					HAL_UART_Transmit(&huart1, "Unauthorized entry !! \n",
							strlen("Unauthorized entry !! \n"),
							HAL_MAX_DELAY);
					check_user();
					check_pass();
					if (security_check == 2) {
						illegal = 0;
					}
					j++;
				}
			} else if (illegal == 0) {
				HAL_TIM_Base_Stop_IT(&htim4);
				HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_3);
				TIM1->CCR3 = 0;
				j = 0;
			}

		}
		if (mood_g == 3) {
			if (music == 0) {
				start_d = HAL_GetTick();

				music = 2;
			}
			if (music == 1) {
				initTimerPWM();
				int notes = sizeof(melody) / sizeof(melody[0]);

				for (int thisNote = 0; thisNote < notes; thisNote++) {
					HAL_UART_Receive_IT(&huart1, c_mood, 14);

					uint16_t note = melody[thisNote];
					uint32_t duration = noteDurations[thisNote];
					if (note != REST) {
						playTone(note, duration);
					} else {
						HAL_Delay(duration);
					}
					if (i % 2 == 0) {
						led_off();
						TIM1->CCR2 = 1000;
						TIM1->CCR3 = 1000;
						TIM2->CCR2 = 1000;
						TIM8->CCR4 = 1000;

					} else {
						led_off();
						TIM8->CCR1 = 1000;
						TIM8->CCR2 = 1000;
						TIM8->CCR3 = 1000;
						TIM1->CCR4 = 1000;
					}
					if (HAL_GetTick() - dance_t > 1000) {
						i++;
						dance_t = HAL_GetTick();
					}
				}
			}
			if (music == 2) {
				if (stop_flag != 1) {
					initTimerPWM();
				}


				//for (int thisNote = 0; thisNote < notes; thisNote++) {
				HAL_UART_Receive_IT(&huart1, c_mood, 14);

				uint16_t note = melody_2[thisNote_2];
				uint32_t duration = noteDurations_2[thisNote_2];
				if (note != REST) {
					playTone_2(note, duration);
					thisNote_2++;
				} else {
					HAL_Delay(duration);
				}
				if ((HAL_GetTick() - start_d < d_g)
						&& (thisNote_2 == notes_2)) {
					thisNote_2 = 0;
				} else if (HAL_GetTick() - start_d >= d_g) {
					HAL_UART_Transmit(&huart1, "ok", strlen("ok"),
							HAL_MAX_DELAY);
					HAL_TIM_Base_Stop_IT(&htim4);
					HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_3);
					stop_flag = 1;
				}

				if (i % 2 == 0) {
					led_off();
					TIM1->CCR2 = 500;
					TIM1->CCR3 = 1000;
					TIM2->CCR2 = 500;
					TIM8->CCR4 = 1000;

				} else {
					led_off();
					TIM8->CCR1 = 500;
					TIM8->CCR2 = 500;
					TIM8->CCR3 = 1000;
					TIM1->CCR4 = 1000;
				}
				if (HAL_GetTick() - dance_t > 1000) {
					i++;
					dance_t = HAL_GetTick();
				}
				//}
			}
		}

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };
	RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI
			| RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
		Error_Handler();
	}
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB
			| RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_TIM1
			| RCC_PERIPHCLK_TIM8 | RCC_PERIPHCLK_ADC12;
	PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
	PeriphClkInit.Adc12ClockSelection = RCC_ADC12PLLCLK_DIV1;
	PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
	PeriphClkInit.USBClockSelection = RCC_USBCLKSOURCE_PLL;
	PeriphClkInit.Tim1ClockSelection = RCC_TIM1CLK_HCLK;
	PeriphClkInit.Tim8ClockSelection = RCC_TIM8CLK_HCLK;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief ADC1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_ADC1_Init(void) {

	/* USER CODE BEGIN ADC1_Init 0 */

	/* USER CODE END ADC1_Init 0 */

	ADC_MultiModeTypeDef multimode = { 0 };
	ADC_ChannelConfTypeDef sConfig = { 0 };

	/* USER CODE BEGIN ADC1_Init 1 */

	/* USER CODE END ADC1_Init 1 */

	/** Common config
	 */
	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
	hadc1.Init.ContinuousConvMode = DISABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.NbrOfConversion = 1;
	hadc1.Init.DMAContinuousRequests = DISABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	hadc1.Init.LowPowerAutoWait = DISABLE;
	hadc1.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
	if (HAL_ADC_Init(&hadc1) != HAL_OK) {
		Error_Handler();
	}

	/** Configure the ADC multi-mode
	 */
	multimode.Mode = ADC_MODE_INDEPENDENT;
	if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK) {
		Error_Handler();
	}

	/** Configure Regular Channel
	 */
	sConfig.Channel = ADC_CHANNEL_2;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SingleDiff = ADC_SINGLE_ENDED;
	sConfig.SamplingTime = ADC_SAMPLETIME_181CYCLES_5;
	sConfig.OffsetNumber = ADC_OFFSET_NONE;
	sConfig.Offset = 0;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN ADC1_Init 2 */

	/* USER CODE END ADC1_Init 2 */

}

/**
 * @brief I2C1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_I2C1_Init(void) {

	/* USER CODE BEGIN I2C1_Init 0 */

	/* USER CODE END I2C1_Init 0 */

	/* USER CODE BEGIN I2C1_Init 1 */

	/* USER CODE END I2C1_Init 1 */
	hi2c1.Instance = I2C1;
	hi2c1.Init.Timing = 0x2000090E;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
		Error_Handler();
	}

	/** Configure Analogue filter
	 */
	if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE)
			!= HAL_OK) {
		Error_Handler();
	}

	/** Configure Digital filter
	 */
	if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN I2C1_Init 2 */

	/* USER CODE END I2C1_Init 2 */

}

/**
 * @brief SPI1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_SPI1_Init(void) {

	/* USER CODE BEGIN SPI1_Init 0 */

	/* USER CODE END SPI1_Init 0 */

	/* USER CODE BEGIN SPI1_Init 1 */

	/* USER CODE END SPI1_Init 1 */
	/* SPI1 parameter configuration*/
	hspi1.Instance = SPI1;
	hspi1.Init.Mode = SPI_MODE_MASTER;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.DataSize = SPI_DATASIZE_4BIT;
	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.NSS = SPI_NSS_SOFT;
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 7;
	hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
	hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
	if (HAL_SPI_Init(&hspi1) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN SPI1_Init 2 */

	/* USER CODE END SPI1_Init 2 */

}

/**
 * @brief TIM1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM1_Init(void) {

	/* USER CODE BEGIN TIM1_Init 0 */

	/* USER CODE END TIM1_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };
	TIM_OC_InitTypeDef sConfigOC = { 0 };
	TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = { 0 };

	/* USER CODE BEGIN TIM1_Init 1 */

	/* USER CODE END TIM1_Init 1 */
	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 47;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = 1000 - 1;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.RepetitionCounter = 0;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim1) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_Init(&htim1) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4)
			!= HAL_OK) {
		Error_Handler();
	}
	sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
	sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
	sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
	sBreakDeadTimeConfig.DeadTime = 0;
	sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
	sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
	sBreakDeadTimeConfig.BreakFilter = 0;
	sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
	sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
	sBreakDeadTimeConfig.Break2Filter = 0;
	sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
	if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM1_Init 2 */

	/* USER CODE END TIM1_Init 2 */
	HAL_TIM_MspPostInit(&htim1);

}

/**
 * @brief TIM2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM2_Init(void) {

	/* USER CODE BEGIN TIM2_Init 0 */

	/* USER CODE END TIM2_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };
	TIM_OC_InitTypeDef sConfigOC = { 0 };

	/* USER CODE BEGIN TIM2_Init 1 */

	/* USER CODE END TIM2_Init 1 */
	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 47;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 999;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_Init(&htim2) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM2_Init 2 */

	/* USER CODE END TIM2_Init 2 */
	HAL_TIM_MspPostInit(&htim2);

}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void) {

	/* USER CODE BEGIN TIM3_Init 0 */

	/* USER CODE END TIM3_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	/* USER CODE BEGIN TIM3_Init 1 */

	/* USER CODE END TIM3_Init 1 */
	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 0;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 65535;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim3) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM3_Init 2 */

	/* USER CODE END TIM3_Init 2 */

}

/**
 * @brief TIM4 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM4_Init(void) {

	/* USER CODE BEGIN TIM4_Init 0 */

	/* USER CODE END TIM4_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };
	TIM_OC_InitTypeDef sConfigOC = { 0 };

	/* USER CODE BEGIN TIM4_Init 1 */

	/* USER CODE END TIM4_Init 1 */
	htim4.Instance = TIM4;
	htim4.Init.Prescaler = 0;
	htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim4.Init.Period = 65535;
	htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim4) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_Init(&htim4) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM4_Init 2 */

	/* USER CODE END TIM4_Init 2 */
	HAL_TIM_MspPostInit(&htim4);

}

/**
 * @brief TIM7 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM7_Init(void) {

	/* USER CODE BEGIN TIM7_Init 0 */

	/* USER CODE END TIM7_Init 0 */

	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	/* USER CODE BEGIN TIM7_Init 1 */

	/* USER CODE END TIM7_Init 1 */
	htim7.Instance = TIM7;
	htim7.Init.Prescaler = 48 - 1;
	htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim7.Init.Period = 100 - 1;
	htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim7) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM7_Init 2 */

	/* USER CODE END TIM7_Init 2 */

}

/**
 * @brief TIM8 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM8_Init(void) {

	/* USER CODE BEGIN TIM8_Init 0 */

	/* USER CODE END TIM8_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };
	TIM_OC_InitTypeDef sConfigOC = { 0 };
	TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = { 0 };

	/* USER CODE BEGIN TIM8_Init 1 */

	/* USER CODE END TIM8_Init 1 */
	htim8.Instance = TIM8;
	htim8.Init.Prescaler = 47;
	htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim8.Init.Period = 999;
	htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim8.Init.RepetitionCounter = 0;
	htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim8) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim8, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_Init(&htim8) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_1)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_2)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_3)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_4)
			!= HAL_OK) {
		Error_Handler();
	}
	sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
	sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
	sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
	sBreakDeadTimeConfig.DeadTime = 0;
	sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
	sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
	sBreakDeadTimeConfig.BreakFilter = 0;
	sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
	sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
	sBreakDeadTimeConfig.Break2Filter = 0;
	sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
	if (HAL_TIMEx_ConfigBreakDeadTime(&htim8, &sBreakDeadTimeConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM8_Init 2 */

	/* USER CODE END TIM8_Init 2 */
	HAL_TIM_MspPostInit(&htim8);

}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void) {

	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 9600;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart1) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}

/**
 * @brief USB Initialization Function
 * @param None
 * @retval None
 */
static void MX_USB_PCD_Init(void) {

	/* USER CODE BEGIN USB_Init 0 */

	/* USER CODE END USB_Init 0 */

	/* USER CODE BEGIN USB_Init 1 */

	/* USER CODE END USB_Init 1 */
	hpcd_USB_FS.Instance = USB;
	hpcd_USB_FS.Init.dev_endpoints = 8;
	hpcd_USB_FS.Init.speed = PCD_SPEED_FULL;
	hpcd_USB_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
	hpcd_USB_FS.Init.low_power_enable = DISABLE;
	hpcd_USB_FS.Init.battery_charging_enable = DISABLE;
	if (HAL_PCD_Init(&hpcd_USB_FS) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USB_Init 2 */

	/* USER CODE END USB_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC,
	GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOD,
			GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12
					| GPIO_PIN_13 | GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_RESET);

	/*Configure GPIO pin : CS_I2C_SPI_Pin */
	GPIO_InitStruct.Pin = CS_I2C_SPI_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(CS_I2C_SPI_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : MEMS_INT3_Pin MEMS_INT4_Pin MEMS_INT2_Pin */
	GPIO_InitStruct.Pin = MEMS_INT3_Pin | MEMS_INT4_Pin | MEMS_INT2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pins : PC0 PC1 PC2 PC3 */
	GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pin : PA0 */
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : PE8 PE9 PE10 PE12
	 PE15 */
	GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_12
			| GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pins : PB12 PB13 */
	GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin : PB15 */
	GPIO_InitStruct.Pin = GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : PD8 PD9 PD10 PD11
	 PD12 PD13 PD6 PD7 */
	GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11
			| GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
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
