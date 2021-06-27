#include "led.h"

static uint32_t cycleStartTime = 0ULL;
static uint32_t cycleOnDuration = 1000ULL;
static uint32_t cycleOffDuration = 1000ULL;

void initLed() {
  pinMode(1, OUTPUT);
  digitalWrite(1, HIGH);  
  cycleStartTime = 0ULL;
  cycleOnDuration = 1000ULL;
  cycleOffDuration = 1000ULL;
}

void ledOff(void) {
  digitalWrite(1, LOW);  
}


void tickLed(uint32_t currentTime) {
  uint32_t passed = currentTime - cycleStartTime;
  if (passed > (cycleOnDuration + cycleOffDuration)) {
    cycleStartTime = currentTime;
    digitalWrite(1, HIGH);
  } else if (passed > cycleOnDuration) {
    digitalWrite(1, LOW);
  }
}

void switchLed(uint32_t currentTime, Stage stage) {
  switch (stage) {
    case (POWERON): {
      cycleStartTime = currentTime;
      cycleOnDuration = 500ULL;
      cycleOffDuration = 500ULL;
      break;
    }
    case (WAITTING): {
      cycleStartTime = currentTime;
      cycleOnDuration = 50ULL;
      cycleOffDuration = 50ULL;
      break;
    }
    case (RUNNING): {
      cycleStartTime = currentTime;
      cycleOnDuration = 5ULL;
      cycleOffDuration = 5000ULL;
      break;
    }
    default: {
      cycleStartTime = currentTime;
      cycleOnDuration = 500ULL;
      cycleOffDuration = 500ULL;
      break;
    }
  }
}
