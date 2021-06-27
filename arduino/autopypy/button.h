#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <Arduino.h>
#include "stage.h"

void initButton(void);
void tickButton(uint32_t currentTime);
bool readButton(void);


#endif
