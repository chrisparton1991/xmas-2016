#include <FastLED.h>
#include "globals.h"
#include "debug_utils.h"
#include "flash_effect.h"
#include "line_effect.h"

#define LAST_ANIMATION_MS 10000

const CRGBArray<LED_COUNT> leds;

void setup() {
  Serial.begin(9600);
  DEBUG_PRINTLN("Initialised Serial.");

  FastLED.addLeds<UCS1903B, DATA_PIN, BRG>(leds, LED_COUNT).setCorrection(TypicalSMD5050);
  blackout();
  DEBUG_PRINTLN("Initialised FastLED.");

  DEBUG_PRINTLN("Initialisation complete.");
}

void loop() {
  fill_solid(leds, LED_COUNT, CRGB::Black);

  // Red and green flashes.
  RUN(flash(1000, 5000, CRGB::Red),  NULL,                             flash(1000, 5000, CRGB::Red),  NULL);
  RUN(NULL,                          flash(4500, 9500, CRGB::Green),   NULL,                          flash(4500, 9500, CRGB::Green));
  RUN(flash(9000, 13000, CRGB::Red), NULL,                             flash(9000, 13000, CRGB::Red), NULL);
  RUN(NULL,                          flash(12500, 16500, CRGB::Green), NULL,                          flash(12500, 16500, CRGB::Green));

  
  RUN(lineUp(18000, 18800, 3, CRGB::Blue), lineUp(18300, 19100, 3, CRGB::Blue), lineUp(18600, 19400, 3, CRGB::Blue), lineUp(18900, 19700, 3, CRGB::Blue))

  FastLED.show();
  checkAnimationCompletion();
}

void checkAnimationCompletion() {
  if (millis() > LAST_ANIMATION_MS) {
    blackout();
    DEBUG_PRINTLN("Animation complete, waiting for power supply restart...");
    for (;;) {}
  }
}

void blackout() {
  fill_solid(leds, LED_COUNT, CRGB::Black);
  FastLED.show();
}

