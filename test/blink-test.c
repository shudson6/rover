/*******************************************************************************
 * blink-test.c
 *
 * Blinks the Arduino Uno's onboard LED (Arduino Pin 13 / Atmega328P pin B5)
 * using a busy wait.
 * Just testing the tools.
 */

#include "m328p.h"

#define WAIT_TIME 0x0007ffffL

int main() {
  // set the pin for output
  DDRB |= PIN5;
  // initialize it off
  PORTB &= ~PIN5;

  volatile unsigned long timer;

  while (1) {
    timer = 0;
    // busy wait
    while (timer++ < WAIT_TIME);
    // toggle the led
    PINB = PIN5;
  }

  // unreachable
  return 0;
}
