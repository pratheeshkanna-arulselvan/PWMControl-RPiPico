#ifndef PWMCONTROL_H
#define PWMCONTROL_H

#include "hardware/pwm.h"

class PWMControl {
public:
    PWMControl(uint pin);
    void setFrequency(uint32_t freq);
    void setDutyCycle(float duty);

private:
    uint _slice_num;
    uint _pin;
};

#endif
