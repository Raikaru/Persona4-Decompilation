/* Sony SDK packet call with an explicit zero fifth register argument. */
#include "type.h"

extern s32 func_0042a940(u32 a0, u32 a1, u32 a2, u32 *packet, u32 mode);

// FUN_0042AB68
s32 func_0042ab68(u32 a0, u32 a1, u32 a2)
{
    u32 packet[4];
    return func_0042a940(a0, a1, a2, packet, 0);
}
