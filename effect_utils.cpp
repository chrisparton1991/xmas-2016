#include <Arduino.h>

int getMappedProgress(unsigned long startMs, unsigned long endMs, uint8_t startValue, uint8_t endValue) {
  unsigned long currentMs = millis();

  if (currentMs < startMs || currentMs > endMs) {
    return -1;
  }

  return map(currentMs, startMs, endMs, startValue, endValue);
}

int getProgress(unsigned long startMs, unsigned long endMs) {
  return getMappedProgress(startMs, endMs, 0, 255);
}

int getProgressPercent(uint32_t startMs, uint32_t endMs) {
  return getMappedProgress(startMs, endMs, 0, 100);
}
