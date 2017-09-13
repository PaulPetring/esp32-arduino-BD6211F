#include "Arduino.h"
#include "./bd6211f.h"

// use 13 bit precission for LEDC timer
#define LEDC_TIMER_13_BIT  13

// use 5000 Hz as a LEDC base frequency
#define LEDC_BASE_FREQ 50000

Bd6211f::Bd6211f(int fin, int rin,int fin_chan=0,int rin_chan=1)
{
 
  pinMode(fin, OUTPUT);
  pinMode(rin, OUTPUT);
  _fin = fin;
  _rin = rin;
  _fin_chan = fin_chan;
  _rin_chan = rin_chan;
}

void Bd6211f::setPWM(uint8_t channel, uint32_t value) {
  // calculate duty

  ledcSetup(channel, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(_fin, _fin_chan);
  ledcAttachPin(_rin, _rin_chan);
  
  uint32_t duty = ((LEDC_BASE_FREQ) / 255) * min(value, 255);
  // write duty to LEDC
  ledcWrite(channel, duty);
}

void Bd6211f::standby() {
  digitalWrite(_fin, LOW);
  digitalWrite(_rin, LOW);
}
void Bd6211f::forward() {
  pinMode(_fin, OUTPUT);
  pinMode(_rin, OUTPUT);
  digitalWrite(_fin, HIGH);
  digitalWrite(_rin, LOW);
}
void Bd6211f::forward(int pwm) {  
  setPWM(_rin_chan, 0);
  setPWM(_fin_chan, pwm);
}
void Bd6211f::reverse() {
  pinMode(_fin, OUTPUT);
  pinMode(_rin, OUTPUT);
  digitalWrite(_fin, LOW);
  digitalWrite(_rin, HIGH);
}
void Bd6211f::reverse(int pwm) {
  setPWM(_fin_chan, 0);
  setPWM(_rin_chan, pwm);
}
void Bd6211f::hold() {
  digitalWrite(_fin, HIGH);
  digitalWrite(_rin, HIGH);
}
