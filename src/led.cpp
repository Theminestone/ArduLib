#include "led.h"

LED::LED(int pin, unsigned long interval) {
    _pin = pin;
    _interval = interval;
    pinMode(_pin, OUTPUT);
}

void LED::on() { digitalWrite(_pin, HIGH); }

void LED::off() { digitalWrite(_pin, LOW); }

void LED::toggle() {
    if (_interval < millis() - _lastToggle) {
        _status = !_status;
        digitalWrite(_pin, _status);
        _lastToggle = millis();
    }
}