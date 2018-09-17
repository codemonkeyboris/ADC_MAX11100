/* 
	MAX11100.h - Library for 16-Bit, +5V, 200ksps ADC with 10µA Shutdown
	
	version 0.1 (Sep 17, 2018) - Kick off.
	Created by Bohan Zheng, Sep 17, 2018.
	Copyright (c) 2018 Bohan Zheng(codemonkeyboris) under The MIT License (MIT)
	for other librarys and sketches look at https://github.com/codemonkeyboris
*/

#ifndef ADC_MAX11100_h
#define ADC_MAX11100_h

#include <Arduino.h>


class ADC_MAX11100 
{
	public:
		//constructor
		ADC_MAX11100(int CS);
		uint16_t readAdc();
	
	private:
		int _CS;
};

#endif