#ifndef EFFECT_UTILS_H
#define EFFECT_UTILS_H

/**
 * Convenience macro to quickly exit from a future or completed animation effect.
 */
#define CHECK_PROGRESS(progress) if (progress == -1) { return; }

/**
 * Fills the specified LEDS with the specified color (or special color effect).
 */
void fillColor(uint8_t startLed, uint8_t ledCount, int progress, CRGB color);

/**
 * Returns an integer to indicate the progress of an effect.
 * The number will be between 0 and 255 for an active effect, or -1 for a future or completed effect.
 */
int getProgress(uint32_t startMs, uint32_t endMs);

#endif
