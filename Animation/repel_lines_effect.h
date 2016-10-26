#ifndef REPEL_LINES_EFFECT_H
#define REPEL_LINES_EFFECT_H

#include <FastLED.h>

void repelLines(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color);
void attractLines(uint32_t startMs, uint32_t durationMs, uint8_t lineLength, CRGB color);

#endif
