#include <bd6211f.h>

Bd6211f m1 = Bd6211f(2, 4, 0, 1);

void setup()
{
}

void loop()
{
    int delay_ms = 100;

    for(int i=10; i <=41;i++) {
    Serial.println("F"+String(i));
    m1.forward(i);
    delay(delay_ms);
    }
    m1.forward(255);
    delay(5000);


    for(int i=10; i <=41;i++) {
    Serial.println("R"+String(i));
    m1.reverse(i);
    delay(delay_ms);
    }
    m1.reverse(255);
    delay(5000);
}

