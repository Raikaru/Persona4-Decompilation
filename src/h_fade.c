/* Source unit: src/h_fade_001228a0.c */
#include "type.h"

static u8 sFadeRed __attribute__((aligned(4)));   // 007642c8
static u8 sFadeGreen __attribute__((aligned(4))); // 007642c4
static u8 sFadeBlue __attribute__((aligned(4)));  // 007642c0



// FUN_001228A0
void H_Fade_SetCustomColor(u8 r, u8 g, u8 b)
{
    sFadeRed = r;
    sFadeGreen = g;
    sFadeBlue = b;
}
