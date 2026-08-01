/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001228A0)
/* Source unit: src/h_fade_001228a0.c */
#include "type.h"

static u8 sFadeRed;                    // 007642c8
static u8 sbssPadRed[3];
static u8 sFadeGreen;                  // 007642c4
static u8 sbssPadGreen[3];
static u8 sFadeBlue;                   // 007642c0

// FUN_001228A0
void H_Fade_SetCustomColor(u8 r, u8 g, u8 b)
{
    sFadeRed = r;
    sFadeGreen = g;
    sFadeBlue = b;
}
#endif /* P4_UNIT_001228A0 */
