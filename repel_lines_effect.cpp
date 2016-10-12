#include <FastLED.h>
#include "globals.h"
#include "debug_utils.h"
#include "colors.h"
#include "effect_utils.h"

void repelHalf(uint8_t halfStart, uint8_t halfEnd, int progress, int lineLength, CRGB color, bool up) {
  int progressPct = map(progress, 0, 255, 0, 100);
  progressPct = up ? progressPct : 100 - progressPct;

  int startLed = halfStart + round((halfEnd - halfStart + lineLength) * progressPct / 100.0) - lineLength;
  int endLed = startLed + lineLength;

  startLed = constrain(startLed, halfStart, halfEnd);
  endLed = constrain(endLed, halfStart, halfEnd);

  for (uint8_t i = halfStart; i < halfEnd; ++i) {
    if (i < startLed || i > endLed) {
      leds[i] = Color::Black;
    }
  }
}

void repelEffect(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color, bool reverse) {
  int progress = getProgress(startMs, startMs + durationMs);
  CHECK_PROGRESS(progress);

  // Fill all LEDs with color, then remove color where needed.
  // This eliminates unsightly joins in the middle of the strip for effects such as rainbows.
  fillColor(0, LED_COUNT, progress, color);

  repelHalf(0, LED_COUNT / 2, progress, lineLength, color, !reverse);
  repelHalf(LED_COUNT / 2, LED_COUNT, progress, lineLength, color, reverse);
}

void repelLines(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  repelEffect(startMs, durationMs, lineLength, color, true);
}

void attractLines(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  repelEffect(startMs, durationMs, lineLength, color, false);
}
