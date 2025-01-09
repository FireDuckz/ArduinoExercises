#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define TEMP A0
int analog_temperature; 
float temperature;
float voltage;
float temp_avg = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TEMP, INPUT);
  lcd.begin(16,2);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  // we obtain analog value from 0 to 1023
  lcd.clear();
  lcd.setCursor(0,0);
  analog_temperature = analogRead(A0);
  voltage = analog_temperature/1023.0 * 5.0;
  temperature = voltage /0.01;
  temp_avg = 0;
  for(int i = 0; i<10; i++){
    analog_temperature = analogRead(A0);
    voltage = analog_temperature/1023.0 * 5.0;
    temperature = voltage /0.01;
    temp_avg += temperature/10;
  }

  
  lcd.print("temp = ");
  lcd.print(temp_avg);

  lcd.setCursor(0,1);
  if(temperature > 27.5){
    lcd.print("Temp too high!");
  }

  else{
    lcd.print("Temp is ok");
  }
  
 
  Serial.print(temperature);
  Serial.write(0xC2);
  Serial.write(0xB0);
  Serial.println('C');
  
  delay(200);
}
