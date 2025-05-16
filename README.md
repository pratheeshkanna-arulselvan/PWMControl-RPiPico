# PWMControl-RPiPico# PWMControl Library for Raspberry Pi Pico

This library provides a simple, Arduino-style interface to control PWM signals on the Raspberry Pi Pico.

## Features
- Set PWM frequency
- Adjust duty cycle
- Use with LED brightness control

## Example Usage

```cpp
PWMControl led(16);
led.setFrequency(1000); // 1 kHz
led.setDutyCycle(0.5);  // 50% brightness
