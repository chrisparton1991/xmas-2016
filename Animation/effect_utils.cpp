#include <Arduino.h>
#include "globals.h"
#include "colors.h"

#define STRIP_RANDOMNESS 5
#define SPARKLE_MOVEMENTS 3
#define SPARKLE_MOVEMENT_DISTANCE 7
#define SPARKLE_PATTERN_COUNT 8
#define SPARKLE_PATTERN_BITS 32

// 1 bits represent places where sparkles should occur.
const uint32_t SPARKLE_PATTERNS[SPARKLE_PATTERN_COUNT] = {
  0b00100100001010001001000100100010,
  0b01000010100100001010001000001010,
  0b00000100100010010010100100100001,
  0b10010000100000010100100010000101,
  0b10010001001000100101000010000100,
  0b00000100100010010010100100001001,
  0b01000010100100001010001000100010,
  0b00100100001010001001000100100010
};

bool isSpecialColor(CRGB color) {
  return color.r == 0 && color.g == 0 && color.b > 0 && color.b < 0x50;
}

void fillSparkle(uint8_t startLed, uint8_t ledCount, int progress, CRGB backgroundColor, CRGB sparkleColor) {
  fill_solid(&(leds[startLed]), ledCount, backgroundColor); 

  for (byte i = 0; i < ledCount; ++i) {
    uint8_t patternIndex = (progress / 2) % SPARKLE_PATTERN_COUNT;
    uint8_t bitIndex = (i * STRIP) % SPARKLE_PATTERN_BITS;
    bool isSparkle = (SPARKLE_PATTERNS[patternIndex] >> bitIndex) & 1;
    if (isSparkle) {
      leds[startLed + i] = sparkleColor;
    }
  }
}

void fillColor(uint8_t startLed, uint8_t ledCount, int progress, CRGB color) {
    if (!isSpecialColor(color)) {
      fill_solid(&(leds[startLed]), ledCount, color); 
    } else if (color == CRGB(SpecialColor::Rainbow)) {
      fill_rainbow(&(leds[startLed]), ledCount, progress * 2);
    } else if (color == CRGB(SpecialColor::BlueRedGradient)) {
      fill_gradient_RGB(&(leds[startLed]), ledCount, Color::Blue, Color::Purple, Color::Pink, Color::Red);
    } else if (color == CRGB(SpecialColor::RedBlueGradient)) {
      fill_gradient_RGB(&(leds[startLed]), ledCount, Color::Red, Color::Pink, Color::Purple, Color::Blue);
    } else if (color == CRGB(SpecialColor::RedGoldSparkles)) {
      fillSparkle(startLed, ledCount, progress, Color::Red, Color::Gold);
    } else if (color == CRGB(SpecialColor::BlueGreenSparkles)) {
      fillSparkle(startLed, ledCount, progress, Color::Blue, Color::Green);
    } else if (color == CRGB(SpecialColor::WhiteBlackSparkles)) {
      fillSparkle(startLed, ledCount, progress, Color::White, Color::Black);
    } else if (color == CRGB(SpecialColor::YellowPurpleSparkles)) {
      fillSparkle(startLed, ledCount, progress, Color::Yellow, Color::Purple);
    }
}

uint32_t getMillis() {
  uint32_t elapsedMs = millis();

  // Per-Arduino adjustment to compensate for variation in clock frequencies.
  if (TIME_CORRECTION_MS != 0) {
    elapsedMs += (elapsedMs / TIME_CORRECTION_MS) * TIME_CORRECTION_FACTOR;
  }
  return elapsedMs + START_MILLIS;
}

int getMappedProgress(unsigned long startMs, unsigned long endMs, uint8_t startValue, uint8_t endValue) {
  unsigned long currentMs = getMillis();

  if (currentMs < startMs || currentMs > endMs) {
    return -1;
  }

  return map(currentMs, startMs, endMs, startValue, endValue);
}

int getProgress(unsigned long startMs, unsigned long endMs) {
  return getMappedProgress(startMs, endMs, 0, 255);
}
