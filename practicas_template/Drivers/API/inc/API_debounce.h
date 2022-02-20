/*
 * API_debounce.h
 *
 *  Created on: 9 nov. 2021
 *      Author: pato
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include <stdint.h>
#include <stdbool.h>

#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */

typedef bool bool_t;

bool_t debounceInit(void);
void debounceUpdate(void);

#endif /* API_INC_API_DEBOUNCE_H_ */
