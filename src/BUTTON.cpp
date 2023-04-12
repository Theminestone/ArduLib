#include "ArduLib.h"

BUTTON::BUTTON(byte pin) {
    _pin = pin;
    _status = false;
    _debounce = 0;
    _last_millis = 0;
    _last_value = 0;
    pinMode(_pin, OUTPUT);
}

void BUTTON::setDebounce(int debounce) {
    _debounce = debounce;
}
bool BUTTON::getStatus() {
    byte buf = digitalRead(_pin);
    if (buf != _last_value) {
        if (millis() > _last_millis + _debounce) {
            _last_millis = millis();
            _status = !_status;
        }
        _last_value = buf;
    }
    return _status;
}