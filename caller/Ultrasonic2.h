/*
  Ultrasonic.h - Library for HR-SC04 Ultrasonic Ranging Module.
  Created by ITead studio. Alex, Apr 20, 2010.
  iteadstudio.com
*/


#ifndef Ultrasonic2_h
#define Ultrasonic2_h


#define CM 1
#define INC 0

class Ultrasonic
{
  public:
    Ultrasonic(int TP, int EP);
    long Timing();
    void Send();
    long Recieve();
    long Ranging(int sys);

    private:
    int Trig_pin;
    int Echo_pin;
    long  duration,distacne_cm,distance_inc;
    
};

#endif