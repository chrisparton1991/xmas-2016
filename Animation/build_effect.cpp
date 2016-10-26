#include <FastLED.h>
#include "globals.h"
#include "debug_utils.h"
#include "colors.h"
#include "effect_utils.h"

void buildEffect(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color, bool up, bool reverse) {
  int progress = getProgress(startMs, startMs + durationMs);
  CHECK_PROGRESS(progress);

  if (reverse) {
    progress = 255 - progress;
  }

  int totalFragments = ceil(LED_COUNT / (float) lineLength),
      rightPos = (LED_COUNT * (totalFragments - 1)) + (lineLength * totalFragments); 

  fillColor(0, LED_COUNT, progress, color);
  bool ledMask[LED_COUNT] = {};

  for (int i = 0; i < totalFragments; ++i) {
    int startPos = LED_COUNT * (i + 1) + lineLength * i;
    startPos -= round((LED_COUNT * totalFragments) * (progress / 255.0));
    
    int endPos = startPos + lineLength;
    startPos = min(LED_COUNT, max(lineLength * i, startPos));
    endPos = min(LED_COUNT, max(lineLength * (i + 1), endPos));

    for (int j = startPos; j < endPos; ++j) {
      ledMask[j] = true;
    }
  }

  for (uint8_t i = 0; i < LED_COUNT; ++i) {
    uint8_t index = up ? i : LED_COUNT - i - 1;
    if (!ledMask[index]) {
      leds[i] = Color::Black;
    } 
  }
}

void buildUp(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  buildEffect(startMs, durationMs, lineLength, color, true, false);
}

void buildDown(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  buildEffect(startMs, durationMs, lineLength, color, false, false);
}

void unbuildUp(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  buildEffect(startMs, durationMs, lineLength, color, true, true);
}

void unbuildDown(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color) {
  buildEffect(startMs, durationMs, lineLength, color, false, true);
}

