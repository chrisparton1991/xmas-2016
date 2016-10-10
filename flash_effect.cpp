#include <FastLED.h>
#include "globals.h"
#include "effect_utils.h"

void flash(uint32_t startMs, uint32_t endMs, CRGB color) {
  int progress = getProgress(startMs, endMs);
  CHECK_PROGRESS(progress);
  
  uint8_t darkness = cos8(progress);
  CRGB adjustedColor = color.fadeToBlackBy(darkness);
  fill_solid(leds, LED_COUNT, adjustedColor);
}
