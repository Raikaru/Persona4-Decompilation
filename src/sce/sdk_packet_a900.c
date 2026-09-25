/* Sony SDK synchronous packet call using a stack-resident output block. */
#include "type.h"

extern s32 func_0042a330(u32 a0, u32 a1, u32 a2, u32 *packet);

// FUN_0042A900
s32 func_0042a900(u32 a0, u32 a1, u32 a2)
{
    u32 packet[4];
    return func_0042a330(a0, a1, a2, packet);
}
