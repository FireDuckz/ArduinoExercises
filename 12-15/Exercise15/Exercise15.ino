#define TempPin A0
#include "TMP36GZ.h"

float temperature = 0;
Temperature tempsensor("TMP36GZ");
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temperature = tempsensor.AnalogToTemp();
  Serial.print(temperature);
  Serial.write(0xC2);
  Serial.write(0xB0);
  Serial.println('C');
  delay(1000);
}
