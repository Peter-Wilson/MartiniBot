#include "Ultrasonic2.h"

Ultrasonic ultrasonic(8,7);

void setup() {
 // setup the xbee connection 
  Serial.begin(115200);
}

void loop() {
  //check for radio signal
  if(Serial.available() > 0)
  {
      //read command
      char input = Serial.read();

      //if send
      if(input == 'B')
      {
        //send until told otherwise
        while(Serial.available() == 0)
        {
          ultrasonic.Send();
        }
      } 
  }

}
