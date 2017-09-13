/*
  bd621.h - Library for using the BD6211F H-Bridge with the ESP32
  Created by Paul Petring 13th September 2017
*/

/*  BD6211F
            _____
     OUT1  -|    |- GND
     VCC   -|    |- OUT2  (Motor)
     VCC   -|    |- VHREF (duty power)
     FIN   -|____|- RIN

*/

#ifndef Bd6211f_h
#define Bd6211f_h

 
class Bd6211f
{
  public:
    Bd6211f(int fin, int rin, int fin_chan, int rin_chan);
    void standby(); //mode a (idling)
    void forward(); //mode b (OUT1 > OUT2)
    void forward(int pwm); //mode e PWM (OUT1 > OUT2)
    void reverse(); //mode c (OUT1 < OUT2)
    void reverse(int pwm); //mode f (OUT1 < OUT2)
    void hold(); //mode d Brake (stop)
    
  private:
    int _fin;
    int _rin;
    int _fin_chan;
    int _rin_chan;
    void setPWM(uint8_t channel, uint32_t value);
};

#endif