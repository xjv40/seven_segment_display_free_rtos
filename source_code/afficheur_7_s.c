/*
 * afficheur_7_s.c
 *
 *  Created on: 23 juin 2018
 *      Author: Grégoire
 */

#include "main.h"
#include "stm32f3xx_hal.h"
#include "cmsis_os.h"

#include "../source_header/afficheur_7_s.h"

void startTaskAfficheur(const void* argument) {
	uint32_t* pargs = (uint32_t*) argument;
	SPI_HandleTypeDef* phandle_spi = (SPI_HandleTypeDef*) pargs[0];
	uint8_t data[16] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, AA, AB, AC, AD, AE, AF};
	int i;

	for(;;) {
		for (i = 0; i < 16; i++) {
			shiftOut(data + i, 1, phandle_spi);
			osDelay(500);
		}
	}
}

void shiftOut(uint8_t* pdata, uint16_t size, SPI_HandleTypeDef* handle_spi) {
	HAL_GPIO_WritePin(SRCLR_GPIO_Port, SRCLR_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SRCLR_GPIO_Port, SRCLR_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RCLK_GPIO_Port, RCLK_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(handle_spi, pdata, size, 100);
	HAL_GPIO_WritePin(RCLK_GPIO_Port, RCLK_Pin, GPIO_PIN_SET);
}
