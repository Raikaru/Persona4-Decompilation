/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffle.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_003753f0(u8 *arg0);

extern void func_003757f0(u8 *arg0);



// FUN_0036E580
void func_0036e580(u8 *arg0, u16 *arg1)
{
    if (*arg1 & 2) {
        func_003753f0((u8 *)arg1 + 0x70);
    }
}



// FUN_0036E5C0
void func_0036e5c0(u8 *arg0, u16 *arg1)
{
    if (*arg1 & 2) {
        func_003757f0((u8 *)arg1 + 0x70);
    }
}
