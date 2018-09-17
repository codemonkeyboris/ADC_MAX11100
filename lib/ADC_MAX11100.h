

#ifndef ADC_MAX11100_h
#define ADC_MAX11100_h

#include <Arduino.h>


class ADC_MAX11100 
{
	public:
		//constructor
		ADC_MAX11100(int CS);
		int readAdc();
	
	private:
		int _CS;
};