/*
  Wind.h - Library for wind sensor
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




#ifndef Wind_H
#define Wind_H
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Wind
{
	public:
		Wind(uint8_t pin);
		void begin(void);
		double getKmhSpeed(void);
		double getMtpsSpeed(void);
		double getMpHSpeed(void);
		double getKtsSpeed(void);

	private:

		unsigned long startime = 0;
		unsigned long durata = 0;
		int stato = 0;
		uint8_t _pin;


};

#endif
