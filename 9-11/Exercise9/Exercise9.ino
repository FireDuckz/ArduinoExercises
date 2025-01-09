#define TEMP A0

int analog_temperature; 
float temperature;
float voltage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TEMP, INPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  // we obtain analog value from 0 to 1023
  analog_temperature = analogRead(A0);

  voltage = analog_temperature/1023.0 * 5.0;
  temperature = voltage /0.01;

  delay(200);
  Serial.print(temperature);
  Serial.write(0xC2);
  Serial.write(0xB0);
  Serial.println('C');
  
  
}
