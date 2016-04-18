#include "Ultrasonic2.h"
#include <Wire.h>

long distance, check;
Ultrasonic ultrasonic(9,8);
int leftDistance;
int rightDistance;
int x;

//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control

void setup() {  
  // setup the xbee connection   
  Wire.begin();
  Serial.begin(115200);
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);  

  leftDistance = 0;
  rightDistance = 0;

  idle();
}

void loop() {
  //Test Direction
  distance = 0;
  check = 0;

  x = 20;
  delay(25);
  for (int i = 0; i < x; i++){
    int temp = 0;
    temp = ultrasonic.Ranging(CM);
    if (temp < 3000){
      distance = distance + temp;
    }
    else {
      x++;
      if(x==25)
      {
        break;
      }
    }
    delay(10);
  }
  distance = distance / 20;

  Serial.write('B');
  delay(5);
  x = 20;
  
  for (int i = 0; i < x; i++){
    int temp = 0;
    temp = ultrasonic.Ranging(CM);
    if (temp < 3000){
      check = check + temp;
    }
    else {
      x++;
      if(x==25)
      {
        break;
      }
    }
    delay(10);
  }
  check = check / 20;

  Serial.write('S');
  delay(5);

  if (distance * 0.7 > check){
    //move Forward
    leftDistance = 0;
    rightDistance = 0;
    advance(100,100);
    while(leftDistance < check/2)
    {
      delay(50);
      UpdateDistance();
    }
    stop();
    if (check / 2 < 10){ //Terminate
      idle();
    }
  }
  else {
    leftDistance = 0;
    turn_a_bit();
  }
  delay(50); 
}



void turn_a_bit(){
  turn_L(100,100);
  while(leftDistance < 3)
  {
      delay(20);
      UpdateDistance();
  }  
  stop();
  leftDistance = 0;
}

void UpdateDistance()
{
  Wire.requestFrom(0x7, 1); // request 1 byte from slave device #7
   if (Wire.available()) { //make sure you got something
     byte c = Wire.read();
      leftDistance += c&0x0F;
      rightDistance += (c>>4)&0x0F;
     }
}

void stop(void)                    //Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void advance(char a,char b)          //Move forward
{
  analogWrite (E1,a);      //PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}  
void back_off (char a,char b)          //Move backward
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
void turn_L (char a,char b)             //Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b)             //Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}

void idle(){
  char c;
  while (c != 'A'){
    if (Serial.available() > 0){
      c = Serial.read();
    }
    delay(50);
  }
}

