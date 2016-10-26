#include <FastLED.h>
#include "globals.h"
#include "debug_utils.h"
#include "effect_utils.h"
#include "colors.h"

void flash(uint32_t startMs, uint32_t durationMs, CRGB color) {
  int progress = getProgress(startMs, startMs + durationMs);
  CHECK_PROGRESS(progress);

  uint8_t darkness = cos8(progress);
  fillColor(0, LED_COUNT, progress, color);
  leds.fadeToBlackBy(darkness);
}
