void setup() {
 // setup the xbee connection 
  Serial.begin(115200);

}

void loop() {
  Serial.print('W');
  delay(1000);

  Serial.print('A');
  delay(1000);

  Serial.print('S');
  delay(1000);

  Serial.print('D');
  delay(1000);
  // put your main code here, to run repeatedly:

  //wait for button to be pressed
    //when pressed, notify the matrini bot

  //if bot requests trigger
    //send trigger

}
