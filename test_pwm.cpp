#include "PWMControl.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    PWMControl led_pwm(16); // GPIO16
    led_pwm.setFrequency(1000); // 1kHz

    while (true) {
        for (float d = 0.0; d <= 1.0; d += 0.1) {
            led_pwm.setDutyCycle(d);
            printf("Duty: %.0f%%\n", d * 100);
            sleep_ms(500);
        }
    }
}
