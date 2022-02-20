/*
 * API_delay.h
 *
 *  Created on: 16 oct. 2021
 *      Author: pato
 */

#ifndef API_DELAY_H_
#define API_DELAY_H_


#include "API.h"


// 10 seconds is the roof for this non-blocking delay implementation.
// Use RTC if you need larger delays.
#define MAX_DELAY 10000

typedef uint32_t tick_t;
typedef bool bool_t;


typedef struct{
	tick_t startTime;
	tick_t duration;
	bool_t running;
} delay_t;

void delayInit( delay_t * delay, tick_t duration );
bool_t delayRead( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );


#endif /* API_DELAY_H_ */
