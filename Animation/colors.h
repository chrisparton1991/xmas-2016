#ifndef COLORS_H
#define COLORS_H

#define SPECIAL_COLOR_RANGE_START 0x000001
#define SPECIAL_COLOR_RANGE_END 0x0000F0

// Regular colours (treated literally).
typedef enum {
  Black     = 0x000000,
  Blue      = 0x0000FF,
  Gold      = 0xFF5000,
  Green     = 0x00FF00,
  LightBlue = 0x0064FF,
  Magenta   = 0xFF0150,
  Orange    = 0xFF1400,
  Pink      = 0xC80A0A,
  Purple    = 0x900096,
  Red       = 0xFF0000,
  White     = 0xFFFFFF,
  Yellow    = 0xFF6400
} Color;

// Reserved color codes used to create custom effects.
typedef enum {
  Rainbow = 0x000001,
  BlueRedGradient = 0x000002,
  RedBlueGradient = 0x000003,
  RedGoldSparkles = 0x000004,
  BlueGreenSparkles = 0x000005,
  WhiteBlackSparkles = 0x000006,
  YellowPurpleSparkles = 0x000007,
} SpecialColor;

#endif
