﻿/*
 * ADC_Interface.c
 *
 * Created: 29/12/2022 12:24:03 م
 *  Author: user
 */ 


#include "ADC_Private.h"

void ADC_Initialization(ADC_Vref vref, ADC_Prescaler prescaler)
{
	// Choose voltage reference
	switch(vref)
	{
		case AREF:
		CLR_BIT(ADMUX, REFS1);CLR_BIT(ADMUX, REFS0);
		break;
		case AVCC:
		CLR_BIT(ADMUX, REFS1);SET_BIT(ADMUX, REFS0);
		break;
		case INTERNAL:
		SET_BIT(ADMUX, REFS1);SET_BIT(ADMUX, REFS0);
		break;
	}
	// Choose prescaler
	switch (prescaler)
	{
		case ADC_PRE1:
		CLR_BIT(ADCSRA, ADPS2);CLR_BIT(ADCSRA, ADPS1);CLR_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRE2:
		CLR_BIT(ADCSRA, ADPS2);CLR_BIT(ADCSRA, ADPS1);SET_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRE4:
		CLR_BIT(ADCSRA, ADPS2);SET_BIT(ADCSRA, ADPS1);CLR_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRE8:
		CLR_BIT(ADCSRA, ADPS2);SET_BIT(ADCSRA, ADPS1);SET_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRE16:
		SET_BIT(ADCSRA, ADPS2);CLR_BIT(ADCSRA, ADPS1);CLR_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRE32:
		SET_BIT(ADCSRA, ADPS2);CLR_BIT(ADCSRA, ADPS1);SET_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRE64:
		SET_BIT(ADCSRA, ADPS2);SET_BIT(ADCSRA, ADPS1);CLR_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRE128:
		SET_BIT(ADCSRA, ADPS2);SET_BIT(ADCSRA, ADPS1);SET_BIT(ADCSRA, ADPS0);
		break;
	}
	// ADC Enable
	SET_BIT(ADCSRA, ADEN);
	// ADC interrupt disable
	CLR_BIT(ADCSRA, ADIE);
	// ADC auto trigger enable
	SET_BIT(ADCSRA, ADATE);
	// ADC Right adjust
	CLR_BIT(ADMUX, ADLAR);
}
uint16_t ADC_Read(ADC_Channel channel)
{
	uint16_t reading = 0;
	// Choose channel
	switch (channel)
	{
		case ADC_CH0:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);// 0 0 0 0 0
		break;
		case ADC_CH1:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);// 0 0 0 0 1
		break;
		case ADC_CH2:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);// 0 0 0 1 0
		break;
		case ADC_CH3:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);// 0 0 0 1 1
		break;
		case ADC_CH4:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);SET_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);// 0 0 1 0 0
		break;
		case ADC_CH5:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);SET_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);// 0 0 1 0 1
		break;
		case ADC_CH6:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);SET_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);// 0 0 1 1 0
		break;
		case ADC_CH7:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);SET_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);// 0 0 1 1 1
		break;
	}
	// ADC Start conversion
	SET_BIT(ADCSRA, ADSC);
	// wait until conversion finish
	while (GET_BIT(ADCSRA, ADIF) != 1);
	reading = ADC_DT;
	return reading;
}