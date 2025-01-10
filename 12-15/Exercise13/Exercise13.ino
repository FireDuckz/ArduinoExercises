int a[5] = {9,2,42,5,8};
int *pointer = &a[0];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Address of pointer is ");
  Serial.print((unsigned int)pointer, HEX);
  Serial.println();
  Serial.print("Value of pointer is ");
  Serial.print(*pointer);
  Serial.println();
  pointer++;;
  delay(3000);

}
