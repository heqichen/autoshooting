#include "button.h"


static int lastStatus;
static int debounceCount = 0;
static bool isReleased = false;

void initButton(void) {
  pinMode(2, INPUT);
  lastStatus = digitalRead(2);
  debounceCount = 0;
  isReleased = false;
}



void tickButton(uint32_t currentTime) {
  int currentRead = digitalRead(2);
  if (currentRead != lastStatus) {
    debounceCount ++;
  } else {
    debounceCount = 0;  
  }

  if (debounceCount >= 5) {
    debounceCount = 0;
    lastStatus = currentRead;
    if (currentRead != 0) {
      isReleased = true;
    }
  }
}


bool readButton(void) {
  bool tmp = isReleased;
  isReleased = false;
  return tmp;
}
