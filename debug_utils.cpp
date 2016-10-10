#include <FastLED.h>
#include <WString.h>
#include "globals.h"

String getLedState(int ledCount) {
  char separator = '\0';

  String output = "";
  for (int i = 0; i < ledCount; ++i) {
    output += separator;
    output += leds[i];
    separator = ',';
  }

  return output;
}
