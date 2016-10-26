#ifndef BUILD_EFFECT_H
#define BUILD_EFFECT_H

#include <FastLED.h>

void buildUp(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color);
void buildDown(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color);
void unbuildUp(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color);
void unbuildDown(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color);

#endif
