void setup() {  
  // setup the xbee connection 
  Serial.begin(115200);
}

void loop() {
    
  //wait for user to enter the button
  if(Serial.available > 0)
  {
  //controller sends radio signal to start search
  
  //trigger for reading
  //if no reading found, rotate 45 degrees trigger for reading (repeat)

   //move forward x units, trigger for new reading (repeat)
   
   //when within threashold, stop
}
