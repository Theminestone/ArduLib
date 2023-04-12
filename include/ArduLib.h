#ifndef ARDULIB_ARDULIB_H
#define ARDULIB_ARDULIB_H

#include <SPI.h>

class LED {
private:
    byte _pin;
    bool _status;
    unsigned long _interval;
    unsigned long _lastToggle;

public:
    LED();

    LED(byte pin);

    LED(byte pin, unsigned long interval);

    void setInterval(unsigned long interval);

    void on();

    void off();

    void toggle();

    void set();

    void fade();

};

class BUTTON {
private:
    byte _pin;
    int _debounce;
    bool _status;
    byte _last_value;
    unsigned long _last_millis;
public:
    BUTTON(byte pin);

    void setDebounce(int debounce);

    boolean getStatus();
};

#endif //ARDULIB_ARDULIB_H
