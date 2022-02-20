/*
 * API_uart.c
 *
 *  Created on: 22 nov. 2021
 *      Author: pato
 */


#include "API_uart.h"
#include <string.h>
#include <stdio.h>


int32_t var = 8;
uint8_t buffer[255];



/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */
static UART_HandleTypeDef UartHandle;

/* Private function prototypes -----------------------------------------------*/
void uartPrintConfig( void );
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */


bool_t uartInit(){

	/*##-1- Configure the UART peripheral ######################################*/
	/* Put the USART peripheral in the Asynchronous mode (UART Mode) */
	/* UART configured as follows:
	      - Word Length = 8 Bits (7 data bit + 1 parity bit) :
		                  BE CAREFUL : Program 7 data bits + 1 parity bit in PC HyperTerminal
	      - Stop Bit    = One Stop bit
	      - Parity      = ODD parity
	      - BaudRate    = 9600 baud
	      - Hardware flow control disabled (RTS and CTS signals) */
	UartHandle.Instance        = USARTx;

	UartHandle.Init.BaudRate   = 9600;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits   = UART_STOPBITS_1;
	UartHandle.Init.Parity     = UART_PARITY_ODD;
	UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode       = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&UartHandle) != HAL_OK)
	{
		/* Initialization Error */
		//Error_Handler();
	}

	uartPrintConfig();

}

bool_t uartSendString(uint8_t * pstring){

	uint8_t index, count = 0;
	const uint8_t MAX_COUNT = 255;
	bool_t returnValue = false;

	//FIXME: poner un maximo para count por si no hay un string bien formado
	for(index = 0; *(pstring + index) != 0; index++){
		count++;

	}

	if (*(pstring + count) != 0)
		returnValue = false;
	else {
		HAL_UART_Transmit(&UartHandle, pstring, count, 0xFFFF);
		returnValue = true;
	}

	return returnValue;
}

void uartSendStringSize(uint8_t * pstring, uint16_t size){

	//TODO: implementación
}

void uartPrintConfig( void ){


	//uartSendString();
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART3 and Loop until the end of transmission */
  HAL_UART_Transmit(&UartHandle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

