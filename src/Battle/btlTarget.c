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
typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 _pad00[0x68];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 _pad74[4];
    void* workData;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);
void func_0043f810(void* dst, const void* src, u32 size);
void func_001f36b0(void* arg);
s32 func_001f3010(u8* arg);
extern u8* iGpffffb3ac;
extern void func_00106020(s32 arg);
extern void func_00113480(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_001f6c40(void* action, s32 flags);
extern void func_001f56d0(void* action, s32 effect, s32 arg2, s32 arg3, s32 arg4);
extern void func_00198dd0(void* unit, s32 state);
extern void func_00213b10(void* unit);
extern void func_00213b30(void* unit);
extern s32 func_00231e20(void* data);
extern void func_00231f20(void* data, s32 value);
extern void func_002325a0(void* data, s32 value);
extern void func_00232610(void* data, s32 value);
extern void func_00232680(void* data, s32 value);
extern void func_002326f0(void* data, s32 value);
extern s32 func_00232710(void* data, s32 flags);
extern void func_00234830(void* data, s32 value, s32 mode);
extern s32 func_002428f0(void* data, s32 mode);
extern s32 func_00242930(void* data);
extern s32 func_00243e30(void* data);
extern void func_00243e50(void* data);
extern void func_00243e70(void* data);
extern void func_0022d600(void* source, void* action, void* data);



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
s32 func_001f3010(u8* arg0)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_21;
    s32 temp_22;
    s32 temp_2;
    s32 temp_3;
    s32 temp_3_5;
    s32 temp_4;
    s32 temp_5;
    u16 temp_3_8;
    u8 temp_3_6;
    u8 temp_3_7;
    u8* temp_16_2;
    u8* temp_19;
    u8* temp_18;
    u8* temp_2_2;
    u8* temp_3_2;
    u8* temp_3_3;
    u8* temp_3_4;
    u8* temp_4_2;

    temp_19 = *(u8**)(arg0 + 4);
    if ((*(u16*)(temp_19 + 0x1a) & 1) == 0) {
        return 1;
    }
    temp_18 = *(u8**)(temp_19 + 0x30);
    temp_17 = func_002428f0(*(u8**)(temp_18 + 0xa64), 0);
    temp_21 = func_00242930(*(u8**)(temp_18 + 0xa64));
    temp_22 = func_00232710(*(u8**)(temp_18 + 0xa64), 1);
    temp_16 = func_00232710(*(u8**)(temp_18 + 0xa64), 0x100000);
    if (*(u16*)(arg0 + 0x2a) & 2) {
        *(u16*)(temp_19 + 0x18) = *(u16*)(temp_19 + 0x18) | 0x1000;
    }
    if (*(u16*)(arg0 + 0x2a) & 4) {
        *(u16*)(temp_19 + 0x18) = *(u16*)(temp_19 + 0x18) | 0x800;
    }
    if (*(s32*)(arg0 + 0x10) & 0x100000) {
        *(u16*)(temp_19 + 0x18) = *(u16*)(temp_19 + 0x18) | 0x2000;
    }
    if (*(u16*)(arg0 + 0x26) & 0x200) {
        *(u16*)(temp_19 + 0x1a) = *(u16*)(temp_19 + 0x1a) | 0x80;
    }
    if (*(u16*)(arg0 + 0x26) & 0x80) {
        if (func_00243e30(*(u8**)(temp_18 + 0xa64)) != 0) {
            func_00243e70(*(u8**)(temp_18 + 0xa64));
        } else {
            func_00243e50(*(u8**)(temp_18 + 0xa64));
        }
    }
    if (*(s32*)(iGpffffb3ac + 0xc) & 0x10) {
        func_002325a0(*(u8**)(temp_18 + 0xa64), *(s32*)(arg0 + 8));
        func_00232610(*(u8**)(temp_18 + 0xa64), *(s32*)(arg0 + 0xc));
        func_00106020(*(s32*)(arg0 + 0x1c));
    }
    temp_3 = *(s32*)(arg0 + 8);
    if ((temp_3 < 0) || (temp_2 = *(s32*)(arg0 + 0xc), temp_2 < 0)) {
        func_00213b10(temp_18);
        if ((*(u16*)(arg0 + 0x26) & 0x300) == 0) {
            func_00243e70(*(u8**)(temp_18 + 0xa64));
        }
    } else if ((temp_3 > 0) || (temp_2 > 0)) {
        func_00213b30(temp_18);
    }
    if (*(s32*)(iGpffffb3ac + 0xc) & 0x20) {
        func_001f6c40(temp_19, *(s32*)(arg0 + 0x10));
        func_00232680(*(u8**)(temp_18 + 0xa64), *(s32*)(arg0 + 0x10));
        func_002326f0(*(u8**)(temp_18 + 0xa64), *(s32*)(arg0 + 0x14));
    }
    temp_5 = *(s32*)(arg0 + 0x18);
    if (temp_5 != 0) {
        func_00234830(*(u8**)(temp_18 + 0xa64), temp_5, 1);
    }
    if ((func_002428f0(*(u8**)(temp_18 + 0xa64), 0) != 0) && (temp_17 == 0)) {
        if (*(u8*)(temp_18 + 0xa2) == 1) {
            temp_3_2 = iGpffffb3ac;
            *(u16*)(temp_3_2 + 0xc5a) = *(u16*)(temp_3_2 + 0xc5a) + 1;
            if (*(u16*)(arg0 + 0x26) & 8) {
                temp_3_3 = iGpffffb3ac;
                *(u16*)(temp_3_3 + 0xc5c) = *(u16*)(temp_3_3 + 0xc5c) + 1;
            }
            temp_4 = func_00231e20(*(u8**)(temp_18 + 0xa64)) & 0xff;
            temp_3_4 = iGpffffb3ac;
            *(s32*)(temp_3_4 + 0xce4) = *(s32*)(temp_3_4 + 0xce4) + temp_4;
            temp_2_2 = iGpffffb3ac + 0xce0;
            if (*(s32*)temp_2_2 < temp_4) {
                *(s32*)temp_2_2 = temp_4;
            }
        }
        temp_17_2 = (*(u16*)(arg0 + 0x26) & 0x10) != 0;
        temp_16_2 = *(u8**)(temp_19 + 0x30);
        func_00243e70(*(u8**)(temp_16_2 + 0xa64));
        if (temp_17_2 == 1) {
            if (*(u16*)(temp_19 + 0x3f4) != 0x154) {
                func_00231f20(*(u8**)(temp_16_2 + 0xa64), 1);
            }
            func_002326f0(*(u8**)(temp_16_2 + 0xa64), 0x80000);
            *(s32*)(temp_16_2 + 0x9c) = *(s32*)(temp_16_2 + 0x9c) | 0x10;
        } else {
            func_00231f20(*(u8**)(temp_16_2 + 0xa64), 0);
            func_002326f0(*(u8**)(temp_16_2 + 0xa64), 0xffffff);
            func_00232680(*(u8**)(temp_16_2 + 0xa64), 0x80000);
            temp_3_5 = *(s32*)(temp_16_2 + 0x9c) | 1;
            *(s32*)(temp_16_2 + 0x9c) = temp_3_5;
            *(s32*)(temp_16_2 + 0x9c) = temp_3_5 & ~0x10;
        }
        if (func_002428f0(*(u8**)(temp_18 + 0xa64), 0) != 0) {
            if (*(u8**)(iGpffffb3ac + 0x170) == temp_19) {
                func_00113480(0x19, 0x96, 0x19, 0);
                func_001f56d0(temp_19, 0x10, (*(s32*)(arg0 + 0x10) & 0x80000) != 0, 0, 2);
            } else {
                func_001f56d0(temp_19, 0x1c, 0, 0, 0);
            }
        }
    } else if ((func_00242930(*(u8**)(temp_18 + 0xa64)) != 0) && (temp_21 == 0)) {
        func_001f56d0(temp_19, 0x1b, 0, 0, 0);
    } else {
        temp_3_6 = *(u8*)(*(u8**)(temp_19 + 0x30) + 0xa2);
        if ((temp_3_6 == 0) && (temp_3_6 != *(u8*)(*(u8**)(*(u8**)(arg0 + 0) + 0x30) + 0xa2))) {
            if ((func_00232710(*(u8**)(temp_18 + 0xa64), 1) != 0) && (temp_22 == 0)) {
                func_001f56d0(temp_19, 0x16, 0, 0, 0);
            } else if ((func_00232710(*(u8**)(temp_18 + 0xa64), 0x100000) != 0) && (temp_16 == 0)) {
                func_001f56d0(temp_19, 0x17, 0, 0, 0);
            } else if (*(u16*)(arg0 + 0x28) & 6) {
                func_001f56d0(temp_19, 0x1a, 0, 0, 0);
            }
        } else if ((func_00232710(*(u8**)(temp_18 + 0xa64), 0x100000) == 0) || (temp_16 == 1)) {
            temp_4_2 = *(u8**)(arg0 + 0);
            temp_3_7 = *(u8*)(*(u8**)(temp_4_2 + 0x30) + 0xa2);
            if ((temp_3_7 == 0) &&
                (temp_3_7 != *(u8*)(*(u8**)(temp_19 + 0x30) + 0xa2)) &&
                !(*(u16*)(arg0 + 0x28) & 4) &&
                (*(s32*)(arg0 + 8) != 0 || *(s32*)(arg0 + 0xc) != 0 ||
                 *(s32*)(arg0 + 0x10) != 0 || *(s32*)(arg0 + 0x14) != 0 ||
                 *(s32*)(arg0 + 0x18) != 0)) {
                temp_3_8 = *(u16*)(arg0 + 0x2a);
                if (temp_3_8 & 2) {
                    func_001f56d0(temp_4_2, 0x14, 0, 0, 0);
                } else if (temp_3_8 & 4) {
                    func_001f56d0(temp_4_2, 0x15, 0, 0, 0);
                }
            }
        }
    }
    func_0022d600(*(u8**)(arg0 + 0), temp_19, arg0 + 8);
    func_00198dd0(temp_18, 6);
    return 1;
}
// FUN_001F36B0
void func_001f36b0(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->packetCount--;
    work->action->unit->packetCount--;
}



// FUN_001F36E0
BtlPacket* func_001f36e0(s32 param_1, s32 param_2, void* param_3, s16 param_4, s16 param_5)
{
    BtlPacket* packet;
    u8* work;

    packet = func_00194470(0x700, 0x2c);
    packet->initFunc = (BtlPacketFunc)func_001f2fe0;
    packet->updateFunc = (BtlPacketFunc)func_001f3010;
    packet->destroyFunc = (BtlPacketFunc)func_001f36b0;
    work = (u8*)packet->workData;
    *(s32*)(work + 0) = param_1;
    *(s32*)(work + 4) = param_2;
    func_0043f810(work + 8, param_3, 0x20);
    *(s16*)(work + 0x28) = param_4;
    *(s16*)(work + 0x2a) = param_5;
    return packet;
}
// FUN_001F37B0
void func_001f37b0(void* arg)
{
    BtlAction* action;

    action = *(BtlAction**)arg;
    action->unit->packetCount++;
}
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
