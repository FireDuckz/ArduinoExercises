#define a 2
#define b 3
#define c 4
#define d 5
#define e 6

int enable = 1;
char incomingByte;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (enable == 1) {
      enable = 0;
      switch(incomingByte){
        case 'a':
          digitalWrite(a, HIGH);
          break;
  
         case 'b':
          digitalWrite(b, HIGH);
          break;
  
          case 'c':
          digitalWrite(c, HIGH);
          break;
  
          case 'd':
          digitalWrite(d, HIGH);
          break;
  
          case 'e':
          digitalWrite(e, HIGH);
          break;

          default:
            digitalWrite(a, LOW);
            digitalWrite(b, LOW);
            digitalWrite(c, LOW);
            digitalWrite(d, LOW);
            digitalWrite(e, LOW);
      }
    }
    if (incomingByte == 10){
      enable = 1;
    }
    Serial.println(incomingByte, DEC);
  }  
}
