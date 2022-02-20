/*
 * API_gpio.h
 *
 *  Created on: 13 feb. 2022
 *      Author: pato
 */

#ifndef API_INC_API_GPIO_H_
#define API_INC_API_GPIO_H_

#include "API.h"

typedef uint8_t gpioMap_t;

void gpioInit(void);
void gpioDeInit(void);
bool_t gpioRead(gpioMap_t gpio);
bool_t gpioWrite(gpioMap_t gpio);


#endif /* API_INC_API_GPIO_H_ */
