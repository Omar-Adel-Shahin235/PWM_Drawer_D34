/*
 * LED0_Interface.c
 *
 * Created: 29/12/2022 12:18:10 م
 *  Author: user
 */ 


#include "LED0_Private.h"

void LED0_Initialize(void)
{
	//Define direction of LED0
	//SET_BIT(DDRC, LED0);
	DIO_SetPin_Direction(LED0_PRT, LED0, LED0_OUT);
}
void LED0_ON(void)
{
	//Turn on the LED0
	//SET_BIT(PORTC, LED0);
	DIO_SetPin_Value(LED0_PRT, LED0, LED0_HIGH);
}
void LED0_OFF(void)
{
	//Turn off the LED0
	//CLR_BIT(PORTC, LED0);
	DIO_SetPin_Value(LED0_PRT, LED0, LED0_LOW);
}
void LED0_TGL(void)
{
	//Toggle Bit for LED0
	//TGL_BIT(PORTC, LED0);
	DIO_TogglePin_Value(LED0_PRT, LED0);
}