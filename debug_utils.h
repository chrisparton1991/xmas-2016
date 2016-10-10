#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include "globals.h"

#define DEBUG_ENABLED false

#if DEBUG_ENABLED == true
  #define DEBUG_PRINT(x) Serial.print(x);
  #define DEBUG_PRINTLN(x) Serial.println(x);
  #define DEBUG_LED_STATE() Serial.println(getLedState(LED_COUNT));
#else
  #define DEBUG_PRINT(x) NULL;
  #define DEBUG_PRINTLN(x) NULL;
  #define DEBUG_LED_STATE() NULL;
#endif

String getLedState(int ledCount);

#endif
