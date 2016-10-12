#include <Arduino.h>
#include "globals.h"
#include "colors.h"

void fillColor(uint8_t startLed, uint8_t ledCount, int progress, CRGB color) {
    if (color == CRGB(SpecialColor::Rainbow)) {
      fill_rainbow(&(leds[startLed]), ledCount, progress * 2);
    } else {
      fill_solid(&(leds[startLed]), ledCount, color);
    }
}

int getMappedProgress(unsigned long startMs, unsigned long endMs, uint8_t startValue, uint8_t endValue) {
  unsigned long currentMs = millis();

  if (currentMs < startMs || currentMs > endMs) {
    return -1;
  }

  return map(currentMs, startMs, endMs, startValue, endValue);
}

int getProgress(unsigned long startMs, unsigned long endMs) {
  return getMappedProgress(startMs, endMs, 0, 255);
}
