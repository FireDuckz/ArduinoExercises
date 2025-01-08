#define Redpin 3
#define Greenpin 5
#define Bluepin 6

char enable = 1;
char red = 250;
char green = 0;
char blue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Redpin, OUTPUT);
  pinMode(Greenpin, OUTPUT);
  pinMode(Bluepin, OUTPUT);
}

void loop() {
  /* 
  if (Serial.available() > 0) {  
      red = Serial.parseInt();
      green = Serial.parseInt();
      blue = Serial.parseInt();
  }*/
  if(blue<160){
    blue +=10;
  }else{
    blue = 0;
  }
  delay(100);
  analogWrite(Redpin, red);
  analogWrite(Greenpin, green);
  analogWrite(Bluepin, blue);

}