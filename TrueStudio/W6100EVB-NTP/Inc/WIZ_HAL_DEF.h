#ifndef __HAL_DEF_H__
#define __HAL_DEF_H__

#include "main.h"
extern SPI_HandleTypeDef hspi2;

/* RESET */
#define W6100_RESET_PIN		    GPIO_PIN_8
#define W6100_RESET_PORT		GPIOD

/* SPI2 */
#define W6100_CS_PIN			GPIO_PIN_7
#define W6100_CS_PORT			GPIOD

#define W6100_SPI               hspi2
#define W6100_SPI_SIZE          1
#define W6100_SPI_TIMEOUT       10
#endif
