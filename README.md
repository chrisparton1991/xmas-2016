# xmas-2016
This repository contains Arduino sketches for my 2016 Christmas lights. There are two sketches: `Animation` and `Restart`.

## Animation Sketch
The animation sketch powers four Arduino Pro Minis to create a synchronised animation effect across four pillars at the front of my house.
All animations are driven by the current elapsed milliseconds of the Arduino, which allows the effect rendering to be stateless and frame-rate independent.

Because the Arduinos run at slightly different clock speeds, I've introduced two constants called `TIME_CORRECTION_MS` and `TIME_CORRECTION_FACTOR`,
which I use to manually adjust the drift on each of the Arduinos. This method is far from perfect, but it's better than not adjusting at all.

The Animation sketch defines the animation sequences for all four Arduinos. There is a `STRIP` constant defined that can be set to values `1`, `2`, `3`, `4`
at build time to compile the correct sequence for each Arduino.

## Restart Sketch
The Restart sketch is quite simple. It runs on an Arduino that is powered by the ATX power supply's 5V standby connection.
The sketch starts by pulling the power supply's `PS_ON` pin low to start it up.
When a sufficient amount of time has passed for the animation to complete, the `PS_ON` pin is pulled high momentarily, then low again to restart the sequence.
This has the effect of repeating the animation and keeping the animation Arduinos (more or less) in sync over a longer period of time.

This probably isn't too great for the power supply, but I have a better solution in mind for 2017.
