#include "ArduLib.h"

LED::LED(byte pin) {
    _pin = pin;
    _status = false;
    _interval = 0;
    _lastToggle = 0;
    pinMode(_pin, OUTPUT);
}

LED::LED(byte pin, unsigned long interval) {
    _pin = pin;
    _status = false;
    _interval = interval;
    _lastToggle = 0;
    pinMode(_pin, OUTPUT);
}

void LED::setInterval(unsigned long interval) {
    _interval = interval;
}

void LED::on() { digitalWrite(_pin, HIGH); }

void LED::off() { digitalWrite(_pin, LOW); }

void LED::set() { digitalWrite(_pin, _status); }

void LED::toggle() {
    if (_interval < millis() - _lastToggle) {
        _status = !_status;
        digitalWrite(_pin, _status);
        _lastToggle = millis();
    }
}

void LED::fade() {
    analogWrite(_pin, (128 + 127 * cos(2 * PI / (_interval * 2) * millis())));
}