#ifndef LINE_EFFECT_H
#define LINE_EFFECT_H

#include <FastLED.h>

void lineUp(uint32_t startMs, uint32_t endMs, uint8_t lineLength, CRGB color);
void lineDown(uint32_t startMs, uint32_t endMs, uint8_t lineLength, CRGB color);

#endif
