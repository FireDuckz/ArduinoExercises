#include <LiquidCrystal.h>
#define led1pin 13
#define led2pin 9
#define led3pin 8
#define led4pin 3
#define led5pin 2

#define buttonpin 10

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define TEMP A0

unsigned long int timer = 0;
unsigned char ledstate = 0;
int hits = 0;
int misses = 0;
unsigned long int countto = 32000;
char hasbeenreleased = 1;
char hasbeenhit = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TEMP, INPUT);
  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
  pinMode(led3pin, OUTPUT);
  pinMode(led4pin, OUTPUT);
  pinMode(led5pin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hits: 0");
  lcd.setCursor(0,1);
  lcd.print("Misses: 0");
}

void loop() {
  // put your main code here, to run repeatedly:
  // we obtain analog value from 0 to 1023

  if (timer >= countto && (hits != 8)){
    timer = 0;
    switch(ledstate){
      case 0:
        ledstate = 1;
        digitalWrite(led1pin,HIGH);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,LOW);
      break; 
      case 1:
        ledstate = 2;
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,HIGH);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,LOW);
      break;
      case 2:
        ledstate = 3;
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,HIGH);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,LOW);
      break;
      case 3:
        ledstate = 4;
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,HIGH);
        digitalWrite(led5pin,LOW);
      break;
      case 4:
        ledstate = 0;
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,HIGH);
        
      break;
      default:
        ledstate = 0;
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,LOW);
      }    
  }

  if( timer >= 15000 && hits == 8 ){ // random
     ledstate = random(1,5);
     timer = 0;
     switch(ledstate-1){
      case 0:
        digitalWrite(led1pin,HIGH);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,LOW);
      break; 
      case 1:
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,HIGH);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,LOW);
      break;
      case 2:
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,HIGH);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,LOW);
      break;
      case 3:
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,HIGH);
        digitalWrite(led5pin,LOW);
      break;
      case 4:
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,HIGH);
        
      break;
      default:
        digitalWrite(led1pin,LOW);
        digitalWrite(led2pin,LOW);
        digitalWrite(led3pin,LOW);
        digitalWrite(led4pin,LOW);
        digitalWrite(led5pin,LOW);
      }    
  }
  timer++; 
  

  if( !(digitalRead(buttonpin)) && hasbeenreleased == 1) { 
    hasbeenreleased = 0;
    if(ledstate == 3){ // if 3rd led is on
        hits++;
        countto = countto - 4000;
        if(countto < 6000){
          countto = 6000;
          }
        for (int i = 0 ; i<4; i++){
          digitalWrite(led1pin,HIGH);
          digitalWrite(led2pin,HIGH);
          digitalWrite(led3pin,HIGH);
          digitalWrite(led4pin,HIGH);
          digitalWrite(led5pin,HIGH);  
          delay(100);
          digitalWrite(led1pin,LOW);
          digitalWrite(led2pin,LOW);
          digitalWrite(led3pin,LOW);
          digitalWrite(led4pin,LOW);
          digitalWrite(led5pin,LOW);
          delay(100);
        }
        ledstate = 0;
    }else{
      misses++;
      digitalWrite(led1pin,LOW);
      digitalWrite(led2pin,LOW);
      digitalWrite(led3pin,LOW);
      digitalWrite(led4pin,LOW);
      digitalWrite(led5pin,LOW);
      delay(1000);
    }
    lcd.setCursor(6,0);
    lcd.print(hits);

    lcd.setCursor(8,1);
    lcd.print(misses);  
  }
  if(digitalRead(buttonpin) && hasbeenreleased == 0){
    hasbeenreleased = 1;
    }
}
