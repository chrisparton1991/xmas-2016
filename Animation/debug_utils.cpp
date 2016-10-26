#include <FastLED.h>
#include <WString.h>
#include "globals.h"

String getLedState(int ledCount) {
  char separator = '\0';

  String output = "";
  for (int i = 0; i < ledCount; ++i) {
    output += separator;
    output += '(';
    output += leds[i].r;
    output += ',';
    output += leds[i].g;
    output += ',';
    output += leds[i].b;
    output += ')';
    separator = ' ';
  }

  return output;
}
