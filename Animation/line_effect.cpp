#include <FastLED.h>
#include "globals.h"
#include "debug_utils.h"
#include "colors.h"
#include "effect_utils.h"

void lineEffect(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color, bool up) {
  int progress = getProgress(startMs, startMs + durationMs);
  CHECK_PROGRESS(progress);

  int progressPct = map(progress, 0, 255, 0, 100);
  progressPct = up ? progressPct : 100 - progressPct;

  int startLed = round((LED_COUNT + lineLength) * progressPct / 100.0) - lineLength;
  int endLed = startLed + lineLength;

  startLed = constrain(startLed, 0, LED_COUNT);
  endLed = constrain(endLed, 0, LED_COUNT);

  if (startLed <= endLed) {
    fillColor(startLed, endLed - startLed, progress, color);
  }
}

void lineUp(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  lineEffect(startMs, durationMs, lineLength, color, true);
}

void lineDown(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  lineEffect(startMs, durationMs, lineLength, color, false);
}
