#include <FastLED.h>
#include "globals.h"
#include "debug_utils.h"
#include "colors.h"
#include "effect_utils.h"

void lineEffect(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color, bool up) {
  int progressPct = getProgressPercent(startMs, startMs + durationMs);
  CHECK_PROGRESS(progressPct);

  progressPct = up ? progressPct : 100 - progressPct;

  int startLed = (int) round((LED_COUNT) * progressPct / 100.0) - lineLength;
  int endLed = startLed + lineLength - 1;

  startLed = constrain(startLed, 0, LED_COUNT - 1);
  endLed = constrain(endLed, 0, LED_COUNT - 1);

  if (startLed <= endLed) {
    if (color == CRGB(SpecialColor::Rainbow)) {
      int progress = getProgress(startMs, startMs + durationMs);
      fill_rainbow(&(leds[startLed]), endLed - startLed, progress * 2);
    } else {
      fill_solid(&(leds[startLed]), endLed - startLed, color);
    }
  }
}

void lineUp(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  lineEffect(startMs, durationMs, lineLength, color, true);
}

void lineDown(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  lineEffect(startMs, durationMs, lineLength, color, false);
}
