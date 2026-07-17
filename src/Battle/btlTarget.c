/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001EC630)
/* Source unit: src/Battle/btlTarget_001ec630.c */
#include "type.h"

/* Ported from P3FES src/Battle/btlTarget.c FUN_002d21e0 (verified MATCH there).
 * The `volatile` on `state` is load-bearing and carried over from the donor:
 * removing it measures MATCH nd0 -> nd6 (size 148/160) here, matching the
 * donor's own recorded W170 measurement of nd0 -> nd6. */
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
#endif /* P4_UNIT_001EC630 */

#if defined(P4_UNIT_001F37D0)
/* Source unit: src/Battle/btlTarget_001f37d0.c */
#include "type.h"

typedef struct BtlAction {
    u8 padding_00[0x28];
    u8 unk_28; // 0x28
} BtlAction;

typedef struct BtlTargetStatePacketWork {
    BtlAction* action;
    u8 flags;
} BtlTargetStatePacketWork;

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
#endif /* P4_UNIT_001F37D0 */

#if defined(P4_UNIT_001ED330)
/* Source unit: src/Battle/btlTarget_001ed330.c */
#include "type.h"

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
#endif /* P4_UNIT_001ED330 */

#if defined(P4_UNIT_001EB440)
/* Source unit: src/Battle/btlTarget_001eb440.c */
#include "type.h"

typedef struct BtlUnit {
    u8 padding_00[0xa2];
    u8 genus; // 0xa2
} BtlUnit;

typedef struct BtlAction {
    u8 padding_00[0x30];
    BtlUnit* unit; // 0x30
} BtlAction;

typedef struct BtlTarget {
    BtlAction* targetedActions[12]; // 0x00
    u8 padding_30[2];               // 0x30
    u16 targetedCount;              // 0x32
} BtlTarget;

/* Ported from the P3FES btlTarget donor at 002d1600 (verified MATCH there),
 * which wraps this function in the same pragma. It is load-bearing: without
 * it MWCC rematerializes the loop constant inside the loop (addiu/sllv with
 * swapped operands) instead of hoisting it, measuring nd 28 here. */
#pragma opt_loop_invariants on
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
#pragma opt_loop_invariants off
#endif /* P4_UNIT_001EB440 */
