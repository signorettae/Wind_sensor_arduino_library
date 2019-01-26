/*
  Wind.cpp - Library for wind sensor
  Copyright (c) 2017 Emanuele Signoretta.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  VERSION 1.0.0 - INITIAL VERSION
  VERSION 1.0.1 - BUG FIXING

    Inspired by the original project of Federico Davanteri:
http://www.nonsolovele.com/ARDUINO/DAVANTERI%20FEDERICO/Anemometro%20Arduino%20di%20Federico%20Davanteri%20FINALE%202015.pdf


*/
#include "Wind.h"


float windspeed = 0.0;
uint32_t pulses = 0;
uint32_t startTime = 0;

Wind::Wind(uint8_t PIN) {
	_PIN = PIN;
}


bool Wind::begin(void) {

	pinMode(_PIN, INPUT);
	attachInterrupt(digitalPinToInterrupt(_PIN), contaImpulsi, FALLING);
	startTime = millis();
	pulses = 0;
	return true;
}


void contaImpulsi(void)
{
	uint32_t durata = millis() - startTime;
	if(durata > 15)
	{
		startTime = millis();

		// calcola velocità in Km/h
		windspeed = 2500.0 / durata;
	}
}

double Wind::getKmhSpeed(void)
{
	noInterrupts();
	double res = windspeed;
	//windspeed = 0;
interrupts();
	return res;
}




double Wind::getMtpsSpeed(void) {
	disableInterrupts();
	double MtpsSpeed = windspeed*2.77778;
	windspeed = 0;
	enableInterrupts();
	return MtpsSpeed;
}


double Wind::getMpHSpeed(void) {
	disableInterrupts();
	double MpHSpeed = windspeed*6.21371;
	windspeed = 0;
	enableInterrupts();
	return MpHSpeed;

}



double Wind::getKtsSpeed(void) {

	disableInterrupts();
	double KtsSpeed = windspeed*5.39957;
	windspeed = 0;
	enableInterrupts();
	return KtsSpeed;
}


