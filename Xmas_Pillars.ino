#include <FastLED.h>
#include "globals.h"
#include "debug_utils.h"
#include "colors.h"
#include "effect_utils.h"
#include "fill_effect.h"
#include "flash_effect.h"
#include "line_effect.h"
#include "repel_lines_effect.h"
#include "build_effect.h"

CRGBArray<LED_COUNT> leds;

void setup() {
  Serial.begin(9600);
  DEBUG_PRINTLN("Initialised Serial.");

  FastLED.addLeds<UCS1903B, DATA_PIN, BRG>(leds, LED_COUNT).setCorrection(TypicalSMD5050);
  DEBUG_PRINTLN("Initialised FastLED.");

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  DEBUG_PRINTLN("Initialisation complete.");
}

void loop() {
  fill_solid(leds, LED_COUNT, Color::Black);

  // Red and green flashes.
  RUN(flash(1000, 3000, Color::Red), NULL,                            flash(1000, 3000, Color::Red), NULL);
  RUN(NULL,                          flash(3500, 3000, Color::Green), NULL,                          flash(3500, 3000, Color::Green));
  RUN(flash(6000, 3000, Color::Red), NULL,                            flash(6000, 3000, Color::Red), NULL);
  RUN(NULL,                          flash(8500, 3000, Color::Green), NULL,                          flash(8500, 3000, Color::Green));

  // Fast line ups.
  RUN(lineUp(13000, 800, 4, Color::Blue),    lineUp(13500, 800, 4, Color::Blue),    lineUp(14000, 800, 4, Color::Blue),    lineUp(14500, 800, 4, Color::LightBlue));
  RUN(lineUp(14000, 800, 6, Color::Pink),    lineUp(14500, 800, 6, Color::Pink),    lineUp(15000, 800, 6, Color::Pink),    lineUp(15500, 800, 6, Color::Pink));
  RUN(lineUp(15000, 800, 8, Color::Gold),    lineUp(15500, 800, 8, Color::Gold),    lineUp(16000, 800, 8, Color::Gold),    lineUp(16500, 800, 8, Color::Gold));
  RUN(lineUp(16000, 800, 10, Color::Purple), lineUp(16500, 800, 10, Color::Purple), lineUp(17000, 800, 10, Color::Purple), lineUp(17500, 800, 10, Color::Purple));

  // Fast line downs.
  RUN(lineDown(18000, 800, 4, Color::Purple), lineDown(18500, 800, 4, Color::Purple), lineDown(19000, 800, 4, Color::Purple), lineDown(19500, 800, 4, Color::Purple));
  RUN(lineDown(19000, 800, 6, Color::Gold),   lineDown(19500, 800, 6, Color::Gold),   lineDown(20000, 800, 6, Color::Gold),   lineDown(20500, 800, 6, Color::Gold));
  RUN(lineDown(20000, 800, 8, Color::Pink),   lineDown(20500, 800, 8, Color::Pink),   lineDown(21000, 800, 8, Color::Pink),   lineDown(21500, 800, 8, Color::Pink));
  RUN(lineDown(21000, 800, 10, Color::Blue),  lineDown(21500, 800, 10, Color::Blue),  lineDown(22000, 800, 10, Color::Blue),  lineDown(22500, 800, 10, Color::LightBlue));

  // Rainbows.
  flash(25000, 5000, SpecialColor::Rainbow);
  attractLines(31000, 2000, 25, SpecialColor::Rainbow);
  repelLines(34000, 2000, 25, SpecialColor::Rainbow);

  // Consecutive colorful lines.
  RUN(lineUp(37000, 5000, 10, Color::Red),    lineUp(37000, 5000, 10, Color::Gold),   lineUp(37000, 5000, 10, Color::Purple), lineUp(37000, 5000, 10, Color::Pink));
  RUN(lineUp(37850, 5000, 10, Color::Green),  lineUp(37850, 5000, 10, Color::Red),    lineUp(37850, 5000, 10, Color::Gold),   lineUp(37850, 5000, 10, Color::Purple));
  RUN(lineUp(38700, 5000, 10, Color::Blue),   lineUp(38700, 5000, 10, Color::Green),  lineUp(38700, 5000, 10, Color::Red),    lineUp(38700, 5000, 10, Color::Gold));
  RUN(lineUp(39550, 5000, 10, Color::Pink),   lineUp(39550, 5000, 10, Color::Blue),   lineUp(39550, 5000, 10, Color::Green),  lineUp(39550, 5000, 10, Color::Red));
  RUN(lineUp(40400, 5000, 10, Color::Purple), lineUp(40400, 5000, 10, Color::Pink),   lineUp(40400, 5000, 10, Color::Blue),   lineUp(40400, 5000, 10, Color::Green));
  RUN(lineUp(41250, 5000, 50, Color::Gold),   lineUp(41250, 5000, 50, Color::Purple), lineUp(41250, 5000, 50, Color::Pink),   lineUp(41250, 5000, 50, Color::Blue));

  // Gradient lines.
  RUN(attractLines(47000, 3000, 50, SpecialColor::RedBlueGradient), repelLines(47000, 3000, 50, SpecialColor::BlueRedGradient),   attractLines(47000, 3000, 50, SpecialColor::RedBlueGradient), repelLines(47000, 3000, 50, SpecialColor::BlueRedGradient));
  RUN(repelLines(50000, 3000, 50, SpecialColor::BlueRedGradient),   attractLines(50000, 3000, 50, SpecialColor::RedBlueGradient), repelLines(50000, 3000, 50, SpecialColor::BlueRedGradient),   attractLines(50000, 3000, 50, SpecialColor::RedBlueGradient));

  flash(54000, 10000, SpecialColor::RedGoldSparkles);
  flash(63000, 10000, SpecialColor::BlueGreenSparkles);
  RUN(lineDown(72000, 10000, 50, SpecialColor::WhiteBlackSparkles), lineUp(72000, 10000, 50, SpecialColor::WhiteBlackSparkles), lineDown(72000, 10000, 50, SpecialColor::WhiteBlackSparkles), lineUp(72000, 10000, 50, SpecialColor::WhiteBlackSparkles));

  RUN(buildUp(83000, 5000, 5, Color::Red),   buildUp(83000, 5000, 5, Color::Green),   buildUp(83000, 5000, 5, Color::Blue),   buildUp(83000, 5000, 5, Color::Gold));
  RUN(fill(88000, 2000, Color::Red),         fill(88000, 2000, Color::Green),         fill(88000, 2000, Color::Blue),         fill(88000, 2000, Color::Gold));
  RUN(unbuildUp(90000, 5000, 5, Color::Red), unbuildUp(90000, 5000, 5, Color::Green), unbuildUp(90000, 5000, 5, Color::Blue), unbuildUp(90000, 5000, 5, Color::Gold));

  buildUp(96000, 10000, 10, SpecialColor::Rainbow);
  unbuildDown(106000, 10000, 10, SpecialColor::Rainbow);

  RUN(buildDown(117000, 10000, 10, SpecialColor::RedGoldSparkles),   buildUp(117000, 10000, 10, SpecialColor::BlueGreenSparkles),   buildDown(117000, 10000, 10, SpecialColor::WhiteBlackSparkles),   buildUp(117000, 10000, 10, SpecialColor::YellowPurpleSparkles));
  RUN(unbuildDown(127000, 10000, 10, SpecialColor::RedGoldSparkles), unbuildUp(127000, 10000, 10, SpecialColor::BlueGreenSparkles), unbuildDown(127000, 10000, 10, SpecialColor::WhiteBlackSparkles), unbuildUp(127000, 10000, 10, SpecialColor::YellowPurpleSparkles));

  FastLED.show();
  endAnimation(138000);
}

// Wait for PSU reset.
void endAnimation(uint32_t endMs) {
  while (getMillis() >= endMs) {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
  }
}

