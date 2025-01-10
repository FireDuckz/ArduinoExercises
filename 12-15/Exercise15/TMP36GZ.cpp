#include "Arduino.h"
#include "TMP36GZ.h"
#include <WString.h>

Temperature::Temperature(String name){
	this->name = name;
}

float Temperature::AnalogToTemp(){
  int analog_temperature;
  float voltage;
  float temperature;
	if(name == "TMP36GZ"){
		analog_temperature = analogRead(A0);
		voltage = analog_temperature/1023.0 * 5.0;
		temperature = voltage /0.02;
	}else if(name == "LM35DZ"){
		// probably will be different
		analog_temperature = analogRead(A0);
		voltage = analog_temperature/1023.0 * 5.0;
		temperature = voltage /0.01;	
	}
	return temperature;
}