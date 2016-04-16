#include "Ultrasonic2.h"

long distance, check;
Ultrasonic ultrasonic(9,8);
bool findingMode;
int distanceToMove;

//XBee Pins
int Tx = 1;
int Rx = 0;

//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control

void setup() {  
  // setup the xbee connection 
  Serial.begin(115200);
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);  
  
  findingMode = false;
  distanceToMove = 0;
}

void loop() {

  //Rotate 45*
  /*turn_R(100,100);
  delay(50);
  stop();*/

  //Test Direction
  distance = 0;
  check = 0;

  for (int i = 0; i < 5; i++){
    distance = distance + ultrasonic.Ranging(CM);
  }
  distance = distance / 5;

  Serial.write('B');

  for (int i = 0; i < 5; i++){
    check = check + ultrasonic.Ranging(CM);
  }
  check = check / 5;

  Serial.write('S');

  if (distance * 0.7 > check || distance * 1.3 < check){
    //move Forward
    advance(100,100);
    delay(50);
    stop();
    delay(50);
    back_off(100,100);
    delay(50);
    stop();
  }
  else {
    //Rotate 60*
    /*turn_R(100,100);
    delay(50);
    stop();*/
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
