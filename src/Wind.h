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

Inspired by the original project of Federico Davanteri:
http://www.nonsolovele.com/ARDUINO/DAVANTERI%20FEDERICO/Anemometro%20Arduino%20di%20Federico%20Davanteri%20FINALE%202015.pdf

  */


#ifndef __WIND_WIND_H
#define __WIND_WIND_H

#include <Arduino.h>

class Wind {

		public:
			Wind(uint8_t PIN);
			bool begin(void);

			double getKmhSpeed(void);
			double getMtpsSpeed(void);
			double getMpHSpeed(void);
			double getKtsSpeed(void);



		private:

			uint8_t _PIN;

	};
void contaImpulsi();
#endif
