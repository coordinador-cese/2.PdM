/*
 * API_debounce.c
 *
 *  Created on: 9 nov. 2021
 *      Author: pato
 */


#include "API_debounce.h"
#include "API_delay.h"

#include <stdint.h>
#include <stdbool.h>

void buttonPressed(void);
void buttonReleased(void);

typedef enum{
	BUTTON_UP,
	BUTTON_RAISING,
	BUTTON_DOWN,
	BUTTON_FALLING
} debounce_t;

static debounce_t debounceState;
static delay_t delay;

#define DELAY_TIME 40

bool_t debounceInit(void){

	debounceState = BUTTON_UP;
	delayInit(&delay, DELAY_TIME);

	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
	BSP_LED_Init(LED1);
	BSP_LED_Init(LED2);

	return true;
}
void debounceUpdate(void){
	switch (debounceState){
	case BUTTON_UP:
		if(BSP_PB_GetState(BUTTON_USER)){
			delayRead(&delay);
			debounceState = BUTTON_FALLING;
		}
		break;
	case BUTTON_FALLING:
		if(delayRead(&delay)){
			if (BSP_PB_GetState(BUTTON_USER)){
				buttonPressed();
				debounceState = BUTTON_DOWN;
			} else {
				debounceState = BUTTON_UP;
			}
		}
		break;
	case BUTTON_DOWN:
		if(!BSP_PB_GetState(BUTTON_USER)){
			delayRead(&delay);
			debounceState = BUTTON_RAISING;
		}
		break;

		break;
	case BUTTON_RAISING:
		if(delayRead(&delay)){
			if (!BSP_PB_GetState(BUTTON_USER)){
				buttonReleased();
				debounceState = BUTTON_UP;
			} else {
				debounceState = BUTTON_DOWN;
			}
		}
		break;


	}
}

void buttonPressed(void){
	BSP_LED_Toggle(LED1);
}
void buttonReleased(void){
	BSP_LED_Toggle(LED2);
}
