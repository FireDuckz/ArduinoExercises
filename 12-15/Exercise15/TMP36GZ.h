#ifndef TMP36GZ_H_
#define TMP36GZ_H_

#include "Arduino.h"
#include <WString.h>

#ifndef TempPin
#define TempPin A0
#endif
class Temperature{
	private:
		String name;
	public:
		Temperature(String name);
		float AnalogToTemp();
		
		
};
#endif