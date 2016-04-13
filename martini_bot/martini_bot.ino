bool findingMode;
int distanceToMove;

void setup() {  
  // setup the xbee connection 
  Serial.begin(115200);
  findingMode = false;
  distanceToMove = 0;
}

void loop() {
    
  //wait for user to enter the button
  if(!findingMode && Serial.available > 0)
  {
      //controller sends radio signal to start search
      char input = Serial.read();
      if(input == 'y')
        findingMode = true;
  }

  if(findingMode)
  {
    if(distanceToMove == 0)
    {
      //trigger for reading
      Serial.write('s');
    }
    
    //if no reading found, rotate 45 degrees trigger for reading (repeat)
  
     //move forward x units, trigger for new reading (repeat)
     
     //when within threashold, stop
  }
}
