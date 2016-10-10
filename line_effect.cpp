#include <FastLED.h>
#include "globals.h"
#include "debug_utils.h"
#include "effect_utils.h"

void lineEffect(uint32_t startMs, uint32_t endMs, uint8_t lineLength, CRGB color, bool up) {
  int progressPct = getProgressPercent(startMs, endMs);
  CHECK_PROGRESS(progressPct);

  progressPct = up ? progressPct : 100 - progressPct;
  DEBUG_PRINT("ProgressPct: "); DEBUG_PRINTLN(progressPct);

  int startLed = (int) round((LED_COUNT) * progressPct / 100.0) - lineLength;
  int endLed = startLed + lineLength - 1;

  startLed = constrain(startLed, 0, LED_COUNT - 1);
  endLed = constrain(endLed, 0, LED_COUNT - 1);

  DEBUG_PRINT("Start LED: "); DEBUG_PRINTLN(startLed);
  DEBUG_PRINT("End LED: "); DEBUG_PRINTLN(endLed);
  
  if (startLed <= endLed) {
    DEBUG_PRINT("endLed - startLed: "); DEBUG_PRINTLN(endLed - startLed);
    DEBUG_PRINT("color: "); DEBUG_PRINTLN(color);
    fill_solid(&(leds[startLed]), endLed - startLed, color);
    DEBUG_LED_STATE();
  }

  DEBUG_PRINTLN("");DEBUG_PRINTLN("");DEBUG_PRINTLN("");
}

void lineUp(uint32_t startMs, uint32_t endMs, uint8_t lineLength, CRGB color) {
  lineEffect(startMs, endMs, lineLength, color, true);
}

void lineDown(uint32_t startMs, uint32_t endMs, uint8_t lineLength, CRGB color) {
  lineEffect(startMs, endMs, lineLength, color, false);
}
