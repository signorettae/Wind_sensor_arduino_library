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

    Inspired by the original project of Mauro Alfieri:
  http://www.mauroalfieri.it/elettronica/anemometro-coppe-portatile-prima-parte.html
  http://www.mauroalfieri.it/elettronica/anemometro-coppe-portatile-seconda-parte.html


*/
#include <Wind.h>

Wind::Wind(uint8_t pin)
{
	_pin = pin;
}

void Wind::begin(void)  //initializethe sensor
{
	pinMode(_pin, INPUT_PULLUP);  //set the pin as input
}

double Wind::getKmhSpeed(void)  //to get the speed in KM/h
{
	double kmhspeed = 0;  //initialize the variable
	int pinval = digitalRead(_pin);  
	if ((stato == 0) & (pinval == 1))
	{
		unsigned long startime = 0;  //initialize the variable
		unsigned long durata = 0;   //initialize the variable

		durata = millis() - startime;	// interval between two pulsations
		startime = millis();	// set a new startime for the next pulsation
		kmhspeed = 2500.0 / durata; 
	}
	return kmhspeed;
}

double Wind::getKtsSpeed(void)  //to get the speed in knots
{
	double ktsspeed = 0; //initialize the variable
	int pinval = digitalRead(_pin);
	if ((stato == 0) & (pinval == 1))
	{
		unsigned long startime = 0; //initialize the variable
		unsigned long durata = 0; //initialize the variable

		durata = millis() - startime;	// interval between two pulsations
		startime = millis();	// set a new startime for the next pulsation
		ktsspeed = (2500.0 / durata) * 5.4;
	}
	return ktsspeed;
}

double Wind::getMpHSpeed() //to get the Miles per hour
{
	double mphspeed = 0; //initialize the variable
	int pinval = digitalRead(_pin);
	if ((stato == 0) & (pinval == 1))
	{
		unsigned long startime = 0; //initialize the variable
		unsigned long durata = 0; //initialize the variable

		durata = millis() - startime;	// interval between two pulsations
		startime = millis();	// set a new startime for the next pulsation
		mphspeed = (2500.0 / durata) * 5.21;
	}
	return mphspeed;
}


double Wind::getMtpsSpeed() //to get the speed in m/s
{
	double mtsspeed = 0;
	int pinval = digitalRead(_pin);
	if ((stato == 0) & (pinval == 1))
	{
		unsigned long startime = 0;
		unsigned long durata = 0;

		durata = millis() - startime;	// interval between two pulsations
		startime = millis();	// set a new startime for the next pulsation

		mtsspeed = (2500.0 / durata) * 2.8;
	}
	return mtsspeed;
}


