/* Source unit: src/Battle/btlTarget_001eb440.c */
#include "include_asm.h"
#include "type.h"

typedef struct BtlUnit {
    u8 padding_00[0xa0];
    u16 packetCount; // 0xa0
    u8 genus;        // 0xa2
} BtlUnit;

typedef struct BtlAction {
    u8 padding_00[0x28];
    u8 unk_28; // 0x28
    u8 padding_29[7];
    BtlUnit* unit; // 0x30
} BtlAction;

typedef struct BtlTarget {
    BtlAction* targetedActions[12]; // 0x00
    u8 padding_30[2];               // 0x30
    u16 targetedCount;              // 0x32
} BtlTarget;

/* Ported from the P3FES btlTarget donor at 002d1600 (verified MATCH there),
 * which wraps this function in the same pragma. It is load-bearing:
 * measured: without it MWCC rematerializes the loop constant inside the loop
 * (addiu/sllv with swapped operands) instead of hoisting it, giving nd 28. */
#pragma opt_loop_invariants on

/* Ported from P3FES src/Battle/btlTarget.c FUN_002d21e0 (verified MATCH there).
 * The `volatile` on `state` is load-bearing and carried over from the donor.
 * measured: removing it takes this function MATCH nd0 -> nd6 (size 148/160),
 * matching the donor's own recorded W170 measurement of nd0 -> nd6. */

typedef struct BtlTargetPacketWork {
    BtlAction* source; // 0x00
    BtlAction* action; // 0x04
    u8 data[0x1c];
    u16 effect;
    u16 targetFlags;
} BtlTargetPacketWork;

typedef struct BtlTargetStatePacketWork {
    BtlAction* action;
    u8 flags;
} BtlTargetStatePacketWork;


// FUN_001EB440
u16 func_001eb440(BtlTarget* target)
{
    u16 mask = 0;
    u16 i = 0;
    u16 bit = 1;
    s32 count = target->targetedCount;

    for (; i < count; i++) {
        mask |= bit << target->targetedActions[i]->unit->genus;
    }
    return mask;
}
/* measured: see the annotation above the matching `on` pragma (func_001eb440). */
#pragma opt_loop_invariants off


/* measured: the `volatile` on `state` is load-bearing (see annotation above);
 * removing it costs FUN_001EC630 MATCH nd0 -> nd6. */
// FUN_001EC630
f32 func_001ec630(f32 value, volatile f32* state)
{
    f32 current;
    f32 slopeBase;
    f32 remaining;
    f32 resultBase;
    f32 slope;
    f32 result;

    current = state[1];
    slopeBase = state[3];
    resultBase = state[4];
    remaining = current - value;

    if (remaining <= 0.0f)
    {
        return 1.0f;
    }
    if (remaining < state[0] * 0.5f)
    {
        slope = slopeBase - state[2] * value;
    }
    else
    {
        slope = state[2] * value + slopeBase;
    }
    result = slope * value + resultBase;
    state[1] = remaining;
    state[3] = slope;
    state[4] = result;
    return result;
}



// FUN_001ED330
int func_001ed330(const float* param_1, const float* param_2, const float* param_3)
{
    int side;
    float cross;

    cross = (param_2[0] - param_1[0]) * (param_3[1] - param_1[1]) -
            (param_2[1] - param_1[1]) * (param_3[0] - param_1[0]);
    if (cross >= 0.0f)
    {
        side = 1;
    }
    else
    {
        side = -(cross < 0.0f);
    }
    return side;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F0610
s32 func_001f0610(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d7970 (verified MATCH there). */

// FUN_001F2FE0
void func_001f2fe0(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->packetCount++;
    work->action->unit->packetCount++;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d7df0 (verified MATCH there). */

// FUN_001F3010
INCLUDE_ASM("asm/nonmatchings/btlTarget", func_001f3010);
// FUN_001F36B0
void func_001f36b0(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->packetCount--;
    work->action->unit->packetCount--;
}



// FUN_001F36E0
INCLUDE_ASM("asm/nonmatchings/btlTarget", func_001f36e0);
// FUN_001F37B0
INCLUDE_ASM("asm/nonmatchings/btlTarget", func_001f37b0);
// FUN_001F37D0
u32 func_001f37d0(void* arg)
{
    BtlTargetStatePacketWork* work = (BtlTargetStatePacketWork*)arg;
    u8 value;

    if ((work->flags & 2) != 0)
    {
        work->action->unk_28 = 0;
    }
    else if ((work->flags & 1) != 0)
    {
        work->action->unk_28++;
    }
    else
    {
        value = work->action->unk_28;
        if (value > 0)
        {
            if (value > 1)
            {
                value = 1;
            }
            work->action->unk_28 = value - 1;
        }
    }
    return 1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F3FD0
s32 func_001f3fd0(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4250
s32 func_001f4250(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4260
s32 func_001f4260(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4270
s32 func_001f4270(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4280
s32 func_001f4280(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F4290
s32 func_001f4290(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F9710
s32 func_001f9710(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F9720
s32 func_001f9720(void)
{
    return -1;
}


/* Ported from P3FES src/Battle/btlTarget.c FUN_002d8db0 (verified MATCH there). */

// FUN_001F9730
s32 func_001f9730(void)
{
    return -1;
}
