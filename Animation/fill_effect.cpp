#include <FastLED.h>
#include "globals.h"
#include "effect_utils.h"
#include "colors.h"

void fill(uint32_t startMs, uint32_t durationMs, CRGB color) {
  int progress = getProgress(startMs, startMs + durationMs);
  CHECK_PROGRESS(progress);

  fillColor(0, LED_COUNT, progress, color);
}
