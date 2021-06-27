#include <util/delay.h>
#include "stage.h"
#include "button.h"
#include "ir.h"
#include "led.h"

static Stage stage;

void setup() {
  // Disable ADC
  ADCSRA &= ~_BV(ADEN);
  ACSR &= ~_BV(ACD);
  initButton();
  initIr();
  initLed();
  stage = POWERON;
}

static uint32_t firstShootTime = 0ULL;
static uint32_t lastShootTime = 0ULL;
static uint32_t shootInterval = 0ULL;

void loop() {
  uint32_t currentTime = millis();
  tickLed(currentTime);
  tickButton(currentTime);

  switch (stage) {
    case (POWERON): {
      if (readButton()) {
        ledOff();
        irShoot();
        firstShootTime = currentTime;
        switchLed(currentTime, WAITTING);
        stage = WAITTING;
      }
      break;
    }
    case (WAITTING): {
      if (readButton()) {
        // ledOff();
        irShoot();
        lastShootTime = currentTime;
        shootInterval = currentTime - firstShootTime;
        switchLed(currentTime, RUNNING);
        stage = RUNNING;
      }
      break;
    }
    case (RUNNING): {
      if ((currentTime - lastShootTime) > shootInterval) {
        // ledOff();
        irShoot();
        lastShootTime = currentTime;
      }
    }
  }

  

  _delay_ms(1);
}
