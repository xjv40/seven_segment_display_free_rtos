/*
 * clignotant.c
 *
 *  Created on: 18 juin 2018
 *      Author: Grégoire
 */

#include "../source_header/clignotant.h"

#include "main.h"
#include "stm32f3xx_hal.h"
#include "cmsis_os.h"

void StartTaskClignotant(const void* argument) {
	uint32_t* args = (uint32_t*) argument;
	GPIO_TypeDef* port = (GPIO_TypeDef*) args[0];
	uint16_t pin = (uint16_t) args[1];

	for (;;) {
		HAL_GPIO_TogglePin(port, pin);
		osDelay(1000);
	}
}
