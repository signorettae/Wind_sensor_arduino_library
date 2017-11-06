#include <Wind.h>
int pin = 2;
Wind wind(pin);

void setup()
{
	Serial.begin(9600);
	wind.begin();

	Serial.println("Wind sensor library example");
	Serial.println("2017 - Emanuele Signoretta");
}

void loop()
{
	float kmhspeed = wind.getKmhSpeed();
	float mpsspeed = wind.getMtpsSpeed();
	float Mphspeed = wind.getMpHSpeed();
	float ktsspeed = wind.getKtsSpeed();

	Serial.print(kmhspeed);
	Serial.print(" Km/H  ");
	Serial.print(mpsspeed);
	Serial.print(" m/s   ");
	Serial.print(Mphspeed);
	Serial.print(" Mi/H  ");
	Serial.print(ktsspeed);
	Serial.println(" Knots");
	delay(10000);


}
