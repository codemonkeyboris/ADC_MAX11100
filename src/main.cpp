/* 
	MAX11100.h - Library for 16-Bit, +5V, 200ksps ADC with 10µA Shutdown
	
	This is a quick test.

	version 0.1 (Sep 17, 2018) - Kick off.
	Created by Bohan Zheng, Sep 17, 2018.
	Copyright (c) 2018 Bohan Zheng(codemonkeyboris) under The MIT License (MIT)
	for other librarys and sketches look at https://github.com/codemonkeyboris
*/

#include <Arduino.h>
#include <ADC_MAX11100.h>

ADC_MAX11100 ADC_EC(10);
uint16_t raw_reading = 0;


void setup()
{  
	Serial.begin(9600);  
}

void loop()
{
	raw_reading = ADC_EC.readAdc();
	Serial.println(raw_reading);
	delay(10);
}