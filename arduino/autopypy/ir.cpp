#include "ir.h"
#include <util/delay.h>
void initIr() {
  pinMode(0, OUTPUT);
}


void tickIr(void) {
}

#define HPERIOD 0.01294 // 38.05kHz
// #define HPERIOD 0.01524 // 32.32kHz
// #define HPERIOD 0.00915 // 53.8kHz
// #define HPERIOD 500
#define IRLED 0b00000001
// #define IRLED 0b00000010

void flashIr(void) {
  for (uint8_t i=0; i<16; ++i) {
  // while (true) {
    PORTB |= IRLED;
    // PORTB &= ~IRLED;
    _delay_ms(HPERIOD);
    PORTB &= ~IRLED;
    // PORTB |= IRLED;
    _delay_ms(HPERIOD);
    
  }
}

void irShoot(void) {
  cli();
  flashIr();
  _delay_ms(7.33);
  // _delay_ms(5.36); // 2s
  flashIr();
  sei();
}
