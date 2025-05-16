#include "PWMControl.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"

PWMControl::PWMControl(uint pin) : _pin(pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    _slice_num = pwm_gpio_to_slice_num(pin);
}

void PWMControl::setFrequency(uint32_t freq) {
    uint32_t clock = clock_get_hz(clk_sys);
    uint32_t divider16 = clock * 16 / freq / 65536 + 1;
    pwm_set_clkdiv_int_frac(_slice_num, divider16 / 16, divider16 & 0xF);
}

void PWMControl::setDutyCycle(float duty) {
    pwm_set_wrap(_slice_num, 65535);
    pwm_set_chan_level(_slice_num, pwm_gpio_to_channel(_pin), duty * 65535);
    pwm_set_enabled(_slice_num, true);
}
