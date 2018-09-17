

#include <SPI.h>
#include <ADC_MAX11100.h>
#include <Arduino.h>


ADC_MAX11100::ADC_MAX11100(int CS) 
{
	_CS = CS;
	pinMode(_CS, OUTPUT);
	digitalWrite(_CS, HIGH);	//deactivate Chipselect
	SPI.begin();
}


int ADC_MAX11100::readAdc() 
{
	/* 16MHz => 4MHz
	 * the max is 4.8MHz, 24 clock cycles for one reading 
	 *        => 4.8MHz/24 = 200ksps MAX
	 * We are slightly below the max speed
	*/
	SPI.setClockDivider(SPI_CLOCK_DIV4);	
	SPI.setBitOrder(MSBFIRST);	
	SPI.setDataMode(SPI_MODE0);

	digitalWrite(_CS, LOW);	//activate Chipselect
	// there is no MOSI for this chip so lets just send bytes of 0s
	byte leading8zeros = SPI.transfer(0x00); 
	byte hi = SPI.transfer(0x00);
	byte lo = SPI.transfer(0x00);	
	digitalWrite(_CS, HIGH); //deactivate Chipselect

	uint16_t adcValue = (hi << 8) + lo; //combinig the 2 return Values

	// clean up
	// SPI.setClockDivider();	//set back to default
	return adcValue;
}
