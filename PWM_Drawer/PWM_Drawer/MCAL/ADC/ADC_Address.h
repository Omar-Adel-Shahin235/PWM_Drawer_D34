/*
 * ADC_Address.h
 *
 * Created: 29/12/2022 12:23:16 م
 *  Author: user
 */ 


#ifndef ADC_ADDRESS_H_
#define ADC_ADDRESS_H_

/*
#define ADMUX  (*(volatile uint8_t*)(0x27))
#define ADCSRA (*(volatile uint8_t*)(0x26))
#define ADCL   (*(volatile uint8_t*)(0x24))
#define ADCH   (*(volatile uint8_t*)(0x25))
#define SFIOR  (*(volatile uint8_t*)(0x))
*/
#define ADC_DT (*(volatile uint16_t*)(0x24))



#endif /* ADC_ADDRESS_H_ */