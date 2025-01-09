#define Redpin 3
#define Greenpin 5
#define Bluepin 6

char red = 255;
char green = 0;
char blue = 0;
int ledcolor = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Redpin, OUTPUT);
  pinMode(Greenpin, OUTPUT);
  pinMode(Bluepin, OUTPUT);
}

void loop() {
  delay(200);
  ledcolor =(255 - 5/3.33*(analogRead(A0)/4) ) ;
  Serial.println(5.0/1023 * analogRead(A0), 3);

  analogWrite(Bluepin, ledcolor);
  analogWrite(Redpin, red);
  analogWrite(Greenpin, green);
}