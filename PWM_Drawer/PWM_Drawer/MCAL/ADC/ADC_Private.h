/*
 * ADC_Private.h
 *
 * Created: 29/12/2022 12:23:48 م
 *  Author: user
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "ADC_Configuration.h"

void ADC_Initialization(ADC_Vref vref, ADC_Prescaler prescaler);
uint16_t ADC_Read(ADC_Channel channel);



#endif /* ADC_PRIVATE_H_ */