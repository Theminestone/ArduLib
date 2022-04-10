#ifndef ARDULIB_ARDULIB_H
#define ARDULIB_ARDULIB_H

#include <Arduino.h>

class LED {
private:
    byte _pin;
    bool _status;
    unsigned long _interval;
    unsigned long _lastToggle;

public:
    LED(byte pin);

    LED(byte pin, unsigned long interval);

    void setInterval(unsigned long interval);

    void on();

    void off();

    void toggle();

    void set();

    void fade();

};

#endif //ARDULIB_ARDULIB_H
