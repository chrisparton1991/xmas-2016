#include <FastLED.h>
#include "globals.h"
#include "debug_utils.h"
#include "effect_utils.h"
#include "colors.h"

void flash(uint32_t startMs, uint32_t durationMs, CRGB color) {
  int progress = getProgress(startMs, startMs + durationMs);
  CHECK_PROGRESS(progress);

  uint8_t darkness = cos8(progress);

  if (color == CRGB(SpecialColor::Rainbow)) {
    uint8_t darkness = cos8(progress);
    fill_rainbow(leds, LED_COUNT, progress * 2);
    leds.fadeToBlackBy(darkness);
  } else {
    CRGB adjustedColor = color.fadeToBlackBy(darkness);
    fill_solid(leds, LED_COUNT, adjustedColor);
  }
}
