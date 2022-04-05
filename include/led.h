#ifndef ARDULIB_LED_H
#define ARDULIB_LED_H

#include <Arduino.h>


class LED {
private:
    byte _pin;
    bool _status;
    unsigned long _interval;
    unsigned long _lastToggle;

public:
    LED(int pin, unsigned long interval);

    void on();

    void off();

    void toggle();
};


#endif //ARDULIB_LED_H
