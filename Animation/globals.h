#ifndef GLOBALS_H
#define GLOBALS_H

#include <FastLED.h>

// Strip can be between 1 and 4, for each pillar.
// This compiles the correct version of the app for each strip.
#define STRIP 4

// The Arduino pin with an inbuild LED.
#define LED_PIN 13

// Allows an animation to be started at a certain point.
// Useful for testing animations, but should be set to 0 for proper builds.
#define START_MILLIS 0

// LEDS in the strip.
#define LED_COUNT 50

// The LED strip controller chipset.
#define CHIPSET UCS1903B

// LED communication pin.
#define DATA_PIN 10

// Format of RGB data sent to the LED strip.
#define RGB_ORDER BRG

#if STRIP == 1
    #define RUN(A, B, C, D) A
    #define TIME_CORRECTION_MS 505
    #define TIME_CORRECTION_FACTOR 1
#elif STRIP == 2
    #define RUN(A, B, C, D) B
    #define TIME_CORRECTION_MS 300
    #define TIME_CORRECTION_FACTOR 1
#elif STRIP == 3
    #define RUN(A, B, C, D) C
    #define TIME_CORRECTION_MS 325
    #define TIME_CORRECTION_FACTOR 1
#elif STRIP == 4
    #define RUN(A, B, C, D) D
    #define TIME_CORRECTION_MS 555
    #define TIME_CORRECTION_FACTOR 1
#else
    #error STRIP must be between 1 and 4, inclusive.
#endif

extern CRGBArray<LED_COUNT> leds;

#endif
