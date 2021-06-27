#ifndef __LED_H__
#define __LED_H__

#include <Arduino.h>
#include "stage.h"

void initLed();
void tickLed(uint32_t currentTime);
void switchLed(uint32_t currentTime, Stage stage);
void ledOff(void);
#endif
