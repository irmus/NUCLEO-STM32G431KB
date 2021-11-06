/*
 * seh_stdio.c
 *
 * STM32 Extended HAL
 *
 *  Created on: Nov 2, 2021
 *      Author: irmus
 */


#include "stm32g4xx_hal.h"
#include "seh_stdio.h"


static UART_HandleTypeDef * stdio_huart;

/*
 * SEH stdio libraries must be initialized before its use.
 *
 * [in] huart :
 *         Handle of UART peripheral. Used for printf()
 *         User must initialized huart before function call.
 *         This can be done with CubeIDE.
 */
void seh_stdio_init(UART_HandleTypeDef *huart)
{
	stdio_huart = huart;
}


/*
 * Formatted text by printf() is handled through ptr argument
 */
int _write(int32_t file, uint8_t *ptr, int32_t len)
{
	if( stdio_huart == NULL )
		return 0;

    if( HAL_UART_Transmit(stdio_huart, ptr, len, len) == HAL_OK )
    	return len;
    else
    	return 0;
}
