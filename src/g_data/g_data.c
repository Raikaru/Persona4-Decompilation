#include "include_asm.h"
#include "type.h"
extern u8 D_007973A0[];

extern s16 D_00797F88[];

extern u32 D_0079B68C[];

typedef struct DatGlobal {
    u8 padding[0x3c6c];
    u32 flags[1];
    u8 padding2[0x4c0];
    s16 partyIds[1];
} DatGlobal;

extern DatGlobal D_00797560;

extern s16 D_00797B7A[];

extern u8 D_00797B7C[];

extern s32 D_00797B80[];

extern u16 D_0079B6A4[];

extern u8 D_0079B6A8[];

extern u8 D_0079757A[];

extern u32 D_005E2200[];

extern u8 D_0079BF00[];

typedef struct GDataEntry {
    u32 f00;
    u32 f04;
    u16 f08;
    u16 f0A;
    u8 f0C;
    u8 f0D;
    u8 f0E;
    u8 f0F;
    u16 f10;
    u16 f12;
    u8 f14[0x10];
    u32 f24;
    u16 f28;
    u16 f2A;
    u16 f2C;
    u16 f2E;
    u32 f30;
    u32 f34;
    s8 f38;
    s8 f39;
    u8 f3A;
    u8 f3B;
    u32 f3C;
    u32 f40;
} GDataEntry;

extern GDataEntry* D_007242A0;
extern GDataEntry* iGpffffb1ac;

extern u8 D_007981CC[];

extern u8 D_0079BE2C[];

extern void func_00232a40(void);

extern void func_0010b610(s32 arg0);

extern void func_00193ad0(void* arg0);

extern s16 D_007973F4[];

extern u32 D_0079BCD8[];

extern u32 D_005E4480[];

extern s32 D_005DD6E0[];

extern s32 D_005DD6DC[];

extern s16 func_00104f50(s16 arg0, s16 arg1);

extern s32 func_00246a50(s16 arg0, s16 arg1);

extern void func_0044ea90(void* msg, s32 id);

extern void func_00440b68(char *fmt, ...);

extern u32 D_0079B1CC[];

extern char iGpffff9b18;

extern u8* iGpffffb3d4; /* gp -0x4C2C */

extern u16 (*iGpffffb3e4)[311]; /* gp -0x4C1C */

extern u8* iGpffffb3dc; /* gp -0x4C24 */

extern u8 D_005E4298[];

extern u8 D_005E42B0[];

extern void* (*jtbl_008873E8[])(u32 size, u32 align);

extern u32 D_00764298;

extern u16 func_00107890(u8 arg0);

extern void func_0043f810(void* arg0, void* arg1, u32 arg2);

extern s32 func_00231e20(u8* arg0);
extern u32 func_00231ed0(void* arg0);
extern u32 func_00231ee0(void* arg0);
struct DatUnit;
extern u16 func_00231f80(struct DatUnit* unit);
extern u16 func_00232290(struct DatUnit* unit);
extern void func_002326c0(void* arg0);
extern void func_00231dc0(void* arg0, s16 arg1);
extern void func_00232680(void* arg0);
extern u32 datCalcClearBadStatus(int unit, u32 badStatus);
extern u32 datCalcIsDead(int unit, s32 hpDelta);

extern u8 D_007973C4[];
extern u8 D_00796E50[];
extern u8 D_00796D4C[];
extern u8 D_00796D4E[];
extern u8 D_00796D84[];
extern u8 D_00796D8C[];
extern u8 D_00796D74[];
extern u8 D_00796D54[];
extern s16 D_00797574[];
extern u8 D_007973CA[];
extern u16 D_007973CC[];
extern u16 D_007973CE[];
extern u32 D_00797400[];
extern u16 D_00797404[];
extern s8 D_007973D4[];
extern u32 D_0079B48C[];
extern u8* DAT_007644A8;

extern u32 D_005E4540[];

extern u32 D_005E4570[];

extern u8 D_00796D96[];

extern u8 D_005DD844[];

extern u8 D_005DD846[];

extern u8 D_00797410[];

extern u8 D_00797F8E[];

extern u8* DAT_007644D0;

extern void func_0023dd90(void* arg0, u8* arg1);

extern void func_003e40b0(f32* a, f32* b);

extern u8* func_00457120(void);

extern u8* func_003e9700(s32 a0);

extern void* func_003e4320(void* out, const void* in, const void* matrix);

extern char D_005E45C0[];

extern u32 D_0079B67C[];

extern u32 iGpffffb19c; /* gp -0x4E64 */

extern char iGpffff9b10; /* gp -0x64F0 */

extern u8 iGpffff9bb0; /* gp -0x6450 */

extern void func_00442088(void* dst, void* fmt, void* value, void* extra);

extern void func_00456150(u8* ptr);

extern u8* func_00454a60(u8* param, s32 mode);

extern void func_00454bd0(u8* ptr);

extern void func_00106390(s32 arg0, s32 arg1);

extern u32 func_00110580(s32 arg0);

extern s32 func_00110d30(s32 idx);

extern void func_0010e9e0(s32 arg0, u32 arg1, u32 arg2, u8* arg3);

extern s32 func_0023a1e0(s32 arg0, u8* arg1, u8* arg2, s32 arg3);

extern u32 func_0023d9b0(u8* arg0, s32 arg1);

extern s16 D_00797B84[];

extern u8 D_00797B86[];

typedef int (*code)();
extern code DAT_008873ec_abs[];

extern char D_005e4308[];
extern long func_00452380(void* path);
extern void func_00452080(long handle);

extern void FUN_0046d730(const char* file, s32 line);

#define K_ASSERT(condition, line) do { if (!(condition)) { FUN_0046d730(__FILE__, (line)); } } while (0)

extern u8* DAT_00764530;

extern u8* DAT_007644c4;

typedef struct PersonaWork {
    u16 flags;
    u16 id;
    u8 level;
    u8 pad[3];
    u32 nextExp;
    u16 skills[8];
    u8 naturalStats[5];
    u8 bonusStats[5];
} PersonaWork;

extern PersonaWork* func_0010a900(u16 pcId);

extern u32 func_0010c750(void *persona, u16 level);

extern u32 datPersonaGetNextExp(int persona);

extern void FUN_0043f9c8(void* destination, s32 value, u32 size);
extern void func_0010d560(void);
extern u8 DAT_007973a0[0x24];

static inline u8* idxFirst(u32 a, u8* b)
{
    return (u8*)(a + (u32)b);
}

// FUN_00104900
void* func_00104900(s32 arg0)
{
    u8* new;
    u32 size;
    u32 idx;

    func_0044ea90(D_005E4298, 0xB8);
    idx = (arg0 & 0xFFFF) * 16;
    size = *(u32*)((u8*)iGpffffb1ac + idx + 0) * 32 + 0x10 + *(u32*)((u8*)iGpffffb1ac + idx + 4) * 16;
    new = jtbl_008873E8[0](size, 0x40000);
    func_0043f810(new, (u8*)iGpffffb1ac + idx, 0x10);
    *(u32*)(new + 8) = (u32)new + 0x10;
    *(u32*)(new + 0xC) = *(u32*)(new + 8) + *(u32*)(new + 0) * 32;
    func_0043f810(*(void**)(new + 8), *(void**)(idxFirst(idx, (u8*)iGpffffb1ac) + 8), *(u32*)(new + 0) * 32);
    func_0043f810(*(void**)(new + 0xC), *(void**)(idxFirst(idx, (u8*)iGpffffb1ac) + 0xC), *(u32*)(new + 4) * 16);
    return new;
}

// FUN_00104A00
void func_00104a00(s32 arg0)
{
    K_ASSERT(arg0 != 0, 0xC2);
    DAT_008873ec_abs[0](arg0);
}

// FUN_00104A60
void func_00104a60(void)
{
    u8* obj;
    u8* src;
    u32 size;
    u8* dst;

    func_00440b68(&iGpffff9b10, D_005E4298, 0xCD);
    obj = func_00454a60(D_005E42B0, 0);
    func_00456150(obj);
    src = *(u8**)(obj + 0x110);
    size = (*(u32*)(src + 0) + *(u32*)(src + 0x10)) * 32 + 0x20 + (*(u32*)(src + 4) + *(u32*)(src + 0x14)) * 16;
    func_0044ea90(D_005E4298, 0xD2);
    iGpffffb1ac = (GDataEntry*)jtbl_008873E8[0](size, 0x40000);
    *(u32*)((u8*)iGpffffb1ac + 0) = *(u32*)(src + 0);
    *(u32*)((u8*)iGpffffb1ac + 4) = *(u32*)(src + 4);
    *(u32*)((u8*)iGpffffb1ac + 8) = (u32)iGpffffb1ac + 0x20;
    *(u32*)((u8*)iGpffffb1ac + 0xC) = *(u32*)((u8*)iGpffffb1ac + 8) + *(u32*)((u8*)iGpffffb1ac + 0) * 32;
    dst = src + 0x20;
    func_0043f810(*(void**)((u8*)iGpffffb1ac + 8), dst, *(u32*)((u8*)iGpffffb1ac + 0) * 32);
    dst = dst + *(u32*)((u8*)iGpffffb1ac + 0) * 32;
    func_0043f810(*(void**)((u8*)iGpffffb1ac + 0xC), dst, *(u32*)((u8*)iGpffffb1ac + 4) * 16);
    *(u32*)((u8*)iGpffffb1ac + 0x10) = *(u32*)(src + 0x10);
    *(u32*)((u8*)iGpffffb1ac + 0x14) = *(u32*)(src + 0x14);
    *(u32*)((u8*)iGpffffb1ac + 0x18) = *(u32*)((u8*)iGpffffb1ac + 0xC) + *(u32*)((u8*)iGpffffb1ac + 4) * 16;
    *(u32*)((u8*)iGpffffb1ac + 0x1C) = *(u32*)((u8*)iGpffffb1ac + 0x18) + *(u32*)((u8*)iGpffffb1ac + 0x10) * 32;
    dst = dst + *(u32*)((u8*)iGpffffb1ac + 4) * 16;
    func_0043f810(*(void**)((u8*)iGpffffb1ac + 0x18), dst, *(u32*)((u8*)iGpffffb1ac + 0x10) * 32);
    func_0043f810(*(void**)((u8*)iGpffffb1ac + 0x1C), dst + *(u32*)((u8*)iGpffffb1ac + 0x10) * 32, *(u32*)((u8*)iGpffffb1ac + 0x14) * 16);
    func_00454bd0(obj);
}

// FUN_00104C50
void func_00104c50(void)
{
    D_007242A0 = (GDataEntry*)((u32)&D_0079BF00[0] + 0x10);
}

/* Return the reader's level; normalize the selector's signed low word at entry. */
// FUN_00104C70
s32 func_00104c70(s32 arg0)
{
    s16 unit = (s16)arg0;

    if (unit == 1)
    {
        return func_00231e20(D_007973C4);
    }
    else
    {
        return func_00231e20((u8*)D_00796E50 + (unit - 2) * 0x88 + 4);
    }
}

/* Return the unit reader's value explicitly; both 108-byte bodies retain
 * their six relocations and four zero alignment bytes. */
// FUN_00104CE0
u32 func_00104ce0(s16 arg0)
{
    if (arg0 == 1)
    {
        return func_00231ed0(D_007973C4);
    }
    else
    {
        return func_00231ed0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_00104D50
u32 func_00104d50(s16 arg0)
{
    if (arg0 == 1)
    {
        return func_00231ee0(D_007973C4);
    }
    else
    {
        return func_00231ee0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

/* Character selectors are signed halfwords. Canonical getter/setter
 * declarations preserve both 108-byte wrappers and their caller bodies. */
// FUN_00104DC0
u16 func_00104dc0(s16 arg0)
{
    if (arg0 == 1)
    {
        return func_00231f80((struct DatUnit*)D_007973C4);
    }
    else
    {
        return func_00231f80((struct DatUnit*)((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4));
    }
}

// FUN_00104E30
u16 func_00104e30(s16 arg0)
{
    if (arg0 == 1)
    {
        return func_00232290((struct DatUnit*)D_007973C4);
    }
    else
    {
        return func_00232290((struct DatUnit*)((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4));
    }
}

// FUN_00104EA0
s16 func_00104ea0(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        return D_007973F4[arg1];
    }
    else
    {
        return *(s16*)((u8*)D_00796D74 + (s32)arg0 * 0x88 + (s32)arg1 * 2);
    }
}

// FUN_00104F10
s16 func_00104f10(s16 arg0)
{
    return func_00104f50(arg0, D_007973F4[arg0]);
}

// FUN_00104F50
s16 func_00104f50(s16 arg0, s16 arg1)
{
    s32 sum = 0;
    s32 i = 0;
    s32 limit = arg1;

    while (i < 5)
    {
        sum = (s16)(sum + func_00246a50(arg0, (s16)(i + 1)));
        if (sum > limit)
        {
            break;
        }
        i++;
    }
    if (i >= 5)
    {
        return 5;
    }
    else
    {
        return (s16)(i + 1);
    }
}

/* Measured: 396B/400B, normalized_diff=0; four trailing zero bytes are padding.
 * The s32 carriers retain explicit signed-short wrapping without reusing the
 * comparison's narrowed temporary for subtraction. Scoped propagation preserves
 * the short progress stages; greater-than selects retail's AT comparison. */
#pragma push
#pragma opt_propagation off
// FUN_00105010
s16 func_00105010(s16 category, f32 scale)
{
    s32 remaining;
    s32 threshold;
    s32 level;
    s16 baseProgress;
    s16 partialProgress;
    s16 progress;

    remaining = D_007973F4[category];
    threshold = 0;
    level = 0;
    while (level < 5)
    {
        threshold = (s16)func_00246a50(category, (s16)(level + 1));
        if (threshold > (s16)remaining)
        {
            break;
        }
        remaining = (s16)(remaining - threshold);
        level++;
    }
    if (level >= 5)
    {
        level = 4;
    }
    baseProgress = (s16)(100 * (level + 1));
    partialProgress = (s16)(s32)((f32)(100 * (s16)remaining) / (f32)threshold);
    progress = (s16)(baseProgress + partialProgress);
    return (s16)(s32)(100.0f * ((f32)(100 * progress) / scale));
}
#pragma pop

// FUN_001051A0
void func_001051a0(s16 arg0, s16 arg1, s16 arg2)
{
    if (arg0 == 1)
    {
        D_007973F4[arg1] = arg2;
    }
    else
    {
        *(s16*)((u8*)D_00796D74 + (s32)arg0 * 0x88 + (s32)arg1 * 2) = arg2;
    }
}

// FUN_00105210
u32 func_00105210(s16 arg0)
{
    if (arg0 == 1)
    {
        return D_00797400[0];
    }
    else
    {
        PersonaWork* persona = func_0010a900(arg0);

        K_ASSERT(persona != 0, 0x1B8);
        return datPersonaGetNextExp((int)persona);
    }
}

// FUN_00105290
u16 func_00105290(s16 arg0)
{
    if (arg0 == 1)
    {
        s32 v = D_00797F88[0];

        K_ASSERT(v < 0xC, 0x1C3);
        return *(u16*)((u8*)D_00797F8E + v * 0x30);
    }
    else
    {
        return *(u16*)((u8*)D_00796D96 + (s32)arg0 * 0x88);
    }
}

/* Ported from the P3FES donor func_00177410, which carries opt_loop_invariants on
 * around this function to hoist the gGlobalWork base out of both copy loops.
 * Removing this loses func_0010d490 (MATCH nd0 -> MISMATCH nd59, size 200 -> 200)
 * - measured W161 (donor's own P3 measurement: nd89). */

#pragma opt_loop_invariants on
extern u32 memcpy();
extern u32 sprintf();
extern u8 DAT_00796de0[];
extern u8 DAT_00796e00[];
extern u8 DAT_00796e20[];
extern u8 DAT_007973a0[];
extern u8 DAT_007973b2[];
extern u32 DAT_00762ca0;



// FUN_00105330
s16 func_00105330(void)
{
    return D_00797F88[0];
}



// FUN_00105340
void func_00105340(s16 arg0)
{
    if (arg0 == 1)
    {
        func_002326c0(D_007973C4);
    }
    else
    {
        func_002326c0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

/* Both level-table lookups byte-mask the selected level after the branch join. */
// FUN_001053B0
u16 func_001053b0(s16 arg0)
{
    s32 r;

    if (arg0 == 1)
    {
        r = func_00231e20(D_007973C4);
    }
    else
    {
        r = func_00231e20((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    return *(u16*)((u8*)D_005DD844 + (r & 0xFF) * 0x2C + (s32)arg0 * 4);
}

// FUN_00105460
u16 func_00105460(s16 arg0)
{
    s32 r;

    if (arg0 == 1)
    {
        r = func_00231e20(D_007973C4);
    }
    else
    {
        r = func_00231e20((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    return *(u16*)((u8*)D_005DD846 + (r & 0xFF) * 0x2C + (s32)arg0 * 4);
}

// FUN_00105510
u8* func_00105510(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u8*)D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        return (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
}

// FUN_001055A0
void func_001055a0(s16 arg0)
{
    if (arg0 == 1)
    {
        func_00231dc0(D_007973C4, arg0);
    }
    else
    {
        func_00231dc0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4, arg0);
    }
}
// FUN_00105610
u32 func_00105610(s16 arg0)
{
    if (arg0 == 1)
    {
        return datCalcIsDead((int)D_007973C4, 0);
    }
    else
    {
        return datCalcIsDead((int)((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4), 0);
    }
}

// FUN_00105690
void func_00105690(s16 arg0, u8 arg1)
{
    if (arg0 == 1)
    {
        D_007973CA[0] = arg1;
    }
    else
    {
        K_ASSERT(0, 0x260);
    }
}

// FUN_001056E0
void func_001056e0(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        D_007973CC[0] = arg1;
    }
    else
    {
        *(s16*)((u8*)D_00796D4C + (s32)arg0 * 0x88) = arg1;
    }
}

// FUN_00105730
void func_00105730(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        D_007973CE[0] = arg1;
    }
    else
    {
        *(s16*)((u8*)D_00796D4E + (s32)arg0 * 0x88) = arg1;
    }
}

// FUN_00105780
void func_00105780(s16 arg0)
{
    u32 r;
    u16 v1;
    u16 v2;

    if (arg0 == 1)
    {
        r = func_00231ed0(D_007973C4);
    }
    else
    {
        r = func_00231ed0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    v1 = (u16)r;
    if (arg0 == 1)
    {
        v2 = func_00231f80((struct DatUnit*)D_007973C4);
    }
    else
    {
        v2 = func_00231f80((struct DatUnit*)((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4));
    }
    if (v2 < v1)
    {
        s16 t = (s16)v2;
        if (arg0 == 1)
        {
            D_007973CC[0] = t;
        }
        else
        {
            *(s16*)((u8*)D_00796D4C + (s32)arg0 * 0x88) = t;
        }
    }
    if (arg0 == 1)
    {
        r = func_00231ee0(D_007973C4);
    }
    else
    {
        r = func_00231ee0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    v1 = (u16)r;
    if (arg0 == 1)
    {
        v2 = func_00232290((struct DatUnit*)D_007973C4);
    }
    else
    {
        v2 = func_00232290((struct DatUnit*)((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4));
    }
    if (v2 < v1)
    {
        s16 t = (s16)v2;
        if (arg0 == 1)
        {
            D_007973CE[0] = t;
        }
        else
        {
            *(s16*)((u8*)D_00796D4E + (s32)arg0 * 0x88) = t;
        }
    }
}

// FUN_00105990
void func_00105990(s16 arg0, u32 arg1)
{
    if (arg0 == 1)
    {
        D_00797400[0] = arg1;
    }
    else
    {
        K_ASSERT(0, 0x297);
    }
}

/* 576/576 bytes; twenty-seven resolved relocations.
 * Independent byte counters retain both scans and the final experience reload. */
// FUN_00105A50
s32 func_00105a50(s16 arg0)
{
    extern void func_0046d730(const char *file, s32 line);
    s32 value;
    s32 value3;
    u8 j;
    u8 index;
    u8 i;
    u8 index2;
    if (arg0 == 1)
        value = D_00797400[0];
    else {
        PersonaWork *persona = func_0010a900((u16)arg0);
        if (persona == 0)
            func_0046d730((const char *)D_005E4298, 0x1B8);
        value = datPersonaGetNextExp((int)persona);
    }
    index = 0;
    i = 0;
    j = 0;
    goto first_test;
first_body:
    if (value < D_005DD6E0[j]) {
        index = i;
        goto first_done;
    }
    i++;
    j++;
first_test:
    if (j < 0x63)
        goto first_body;
    index = 0x63;
first_done:
    if ((index & 0xFF) == 0x63)
        return 0;
    if (arg0 == 1)
        value = D_00797400[0];
    else {
        PersonaWork *persona = func_0010a900((u16)arg0);
        if (persona == 0)
            func_0046d730((const char *)D_005E4298, 0x1B8);
        value = datPersonaGetNextExp((int)persona);
    }
    index2 = 0;
    i = 0;
    j = 0;
    goto second_test;
second_body:
    if (value < D_005DD6E0[j]) {
        index2 = i;
        goto second_done;
    }
    i++;
    j++;
second_test:
    if (j < 0x63)
        goto second_body;
    index2 = 0x63;
second_done:
    value3 = D_005DD6DC[((index2 & 0xFF) + 1) & 0xFF];
    if (arg0 == 1)
        value = D_00797400[0];
    else {
        PersonaWork *persona = func_0010a900((u16)arg0);
        if (persona == 0)
            func_0046d730((const char *)D_005E4298, 0x1B8);
        value = datPersonaGetNextExp((int)persona);
    }
    return (s32)((u32)value3 - (u32)value);
}

// FUN_00105C90
void func_00105c90(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        D_00797404[0] = arg1;
    }
    else
    {
        *(s16*)((u8*)D_00796D84 + (s32)arg0 * 0x88) = arg1;
    }
}

/* The retail initializer supplies a second halfword; this reset ignores it. */
// FUN_00105CE0
void func_00105ce0(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        func_00232680(D_007973C4);
    }
    else
    {
        func_00232680((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_00105D50
void func_00105d50(s16 arg0, u32 mask)
{
    if (arg0 == 1)
    {
        datCalcClearBadStatus((int)D_007973C4, mask);
    }
    else
    {
        datCalcClearBadStatus((int)((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4), mask);
    }
}

// FUN_00105DC0
void func_00105dc0(s16 arg0, s16 arg1, s16 arg2)
{
    if (arg0 == 1)
    {
        D_00797574[arg1] = arg2;
    }
    else
    {
        *(s16*)((u8*)D_00796D8C + (s32)arg0 * 0x88 + (s32)arg1 * 2) = arg2;
    }
}

// FUN_00105E30
void func_00105e30(s16 arg0, s16 arg1)
{
    K_ASSERT(arg1 < 5, 0x322);
    if (arg0 == 1)
    {
        D_007973D4[0] = arg1;
    }
    else
    {
        *(s8*)((u8*)D_00796D54 + (s32)arg0 * 0x88) = arg1;
    }
}

// FUN_00105ED0
u32 func_00105ed0(void)
{
    return D_0079B68C[0];
}



// FUN_00105EE0
s16 datGetPartyId(s32 idx)
{
    return D_00797560.partyIds[idx];
}



// FUN_00105F00
s16 func_00105f00(s16 arg0)
{
    if (arg0 == 1)
    {
        return D_007973D4[0];
    }
    else
    {
        return *(s8*)((u8*)D_00796D54 + (s32)arg0 * 0x88);
    }
}

// FUN_00105F50
s8 func_00105f50(u16 arg0)
{
    u8* table = DAT_007644c4;
    u16 id = arg0;

    return (s8)func_00107890(table[id * 0xE + 2]);
}

// FUN_00105FA0
void func_00105fa0(u32 arg0)
{
    if (arg0 > 0x98967F)
    {
        FUN_0046d730(__FILE__, 0x359);
    }
    D_0079B68C[0] = arg0;
}

// FUN_00106000
void datSetPartyId(s32 idx, s16 pcId)
{
    D_00797560.partyIds[idx] = pcId;
}



// FUN_00106020
s32 func_00106020(s32 arg0)
{
    s32 value = arg0 + D_0079B68C[0];

    if (value > 0x98967F)
    {
        value = 0x98967F;
    }
    else if (value < 0)
    {
        value = 0;
    }

    if ((u32)value > 0x98967Fu)
    {
        FUN_0046d730(__FILE__, 0x359);
    }
    D_0079B68C[0] = value;
    return value;
}
// FUN_001060B0
s16 func_001060b0(void)
{
    return D_00797B7A[0];
}



// FUN_001060C0
u8 func_001060c0(void)
{
    return D_00797B7C[0];
}



// FUN_001060D0
s16 func_001060d0(void)
{
    return D_00797B84[0];
}



// FUN_001060E0
u8 func_001060e0(void)
{
    return D_00797B86[0];
}



// FUN_001060F0
s32 func_001060f0(void)
{
    return D_00797B80[0];
}

// FUN_00106100
void func_00106100(s16 arg0)
{
    u32 temp_2;

    func_00106390(0xAD0, 0);
    func_00106390(0xAD7, 0);
    func_00106390(0xAD1, 0);
    func_00106390(0xAD2, 0);
    func_00106390(0xAD3, 0);
    func_00106390(0xAD4, 0);
    func_00106390(0xAD5, 0);
    func_00106390(0xAD6, 0);
    func_00106390(0xAD8, 0);
    func_00106390(0xAD9, 0);
    func_00106390(0xADA, 0);
    func_00106390(0xADB, 0);
    D_00797B7A[0] = arg0;
    temp_2 = func_00110580(arg0);
    switch (temp_2)
    {
    case 0:
        func_00106390(0xAD7, 1);
        break;
    case 1:
        func_00106390(0xAD1, 1);
        break;
    case 2:
        func_00106390(0xAD2, 1);
        break;
    case 3:
        func_00106390(0xAD3, 1);
        break;
    case 4:
        func_00106390(0xAD4, 1);
        break;
    case 5:
        func_00106390(0xAD5, 1);
        break;
    case 6:
        func_00106390(0xAD6, 1);
        break;
    }
    if (func_00110d30(D_00797B7A[0]) != 0)
    {
        func_00106390(0xAD0, 1);
    }
}

// FUN_001062F0
void func_001062f0(u8 arg0)
{
    D_00797B7C[0] = arg0;
}

// FUN_00106300
void func_00106300(s16 arg0)
{
    D_00797B84[0] = arg0;
}

// FUN_00106310
void func_00106310(u8 arg0)
{
    D_00797B86[0] = arg0;
}

// FUN_00106320
void func_00106320(u32 arg0)
{
    D_00797B80[0] = arg0;
}

// FUN_00106330
u32 datGetFlag(s32 bit)
{
    s32 mask;
    s32 idx;

    idx = bit / 32;
    mask = bit % 32;

    return (D_00797560.flags[idx] & (1U << mask)) != 0;
}



// FUN_00106390
void func_00106390(s32 arg0, s32 arg1)
{
    s32 idx;
    s32 bit;

    if ((arg0 < 0) || (arg0 >= 0x1600))
    {
        FUN_0046d730(__FILE__, 0x471);
    }
    if (arg0 == 0x1576)
    {
        func_00440b68(&iGpffff9b18);
    }
    idx = arg0 / 32;
    bit = 1 << (arg0 % 32);
    if (arg1 != 0)
    {
        D_0079B1CC[idx] |= bit;
    }
    else
    {
        D_0079B1CC[idx] &= ~bit;
    }
}

// FUN_00106480
void func_00106480(void)
{
    s32 i = 0;

    while (i < 0xB0)
    {
        *(u32*)((u8*)DAT_007973a0 + i * 4 + 0x3E2C) = 0;
        i = i + 1;
    }
}

// FUN_001064C0
void func_001064c0(void)
{
    func_0010b610(0);
}

// FUN_001064F0
u32 func_001064f0(s32 arg0)
{
    K_ASSERT(arg0 < 0x80, 0x4AE);
    return D_0079B48C[arg0];
}

// FUN_00106550
void func_00106550(s32 arg0, u32 arg1)
{
    K_ASSERT(arg0 < 0x80, 0x4B9);
    D_0079B48C[arg0] = arg1;
}

// FUN_001065C0
void func_001065c0(void)
{
    s32 i = 0;

    while (i < 0x7F)
    {
        *(u32*)((u8*)DAT_007973a0 + i * 4 + 0x40EC) = 0;
        i = i + 1;
    }
}

// FUN_00106600
s32 func_00106600(s16 arg0)
{
    return D_0079757A[arg0];
}

// FUN_00106620
/* func_00106850 takes the raw 32-bit id and narrows it itself; retail's call
   here passes arg0 with no sign-extension at the call site. */
u32 func_00106850(s32 arg0);
void func_00106620(s32 arg0, s32 arg1)
{
    s16 id;
    u8 *p;
    s32 value;
    s32 x;
    s32 bit;
    s32 idx;

    value = arg1 & 0xFF;
    if (value > 0x63)
    {
        value = 0x63;
    }
    id = (s16)arg0;
    p = (u8 *)D_0079757A + id;
    *p = value;
    if (func_00106850(arg0) == 4)
    {
        if (*p != 0)
        {
            x = id - 0x200;
            if ((x < 0) || (x >= 0x1600))
            {
                FUN_0046d730((const char *)D_005E4298, 0x471);
            }
            if (x == 0x1576)
            {
                func_00440b68(&iGpffff9b18);
            }
            x = (s16)arg0 - 0x200;
            bit = 1 << (x % 32);
            idx = x / 32;
            D_0079B1CC[idx] |= bit;
        }
        else
        {
            s32 bit2;
            s32 idx2;

            x = id - 0x200;
            if ((x < 0) || (x >= 0x1600))
            {
                FUN_0046d730((const char *)D_005E4298, 0x471);
            }
            if (x == 0x1576)
            {
                func_00440b68(&iGpffff9b18);
            }
            x = (s16)arg0 - 0x200;
            bit2 = 1 << (x % 32);
            idx2 = x / 32;
            D_0079B1CC[idx2] &= ~bit2;
        }
    }
}

// FUN_001067F0
u32 func_001067f0(s16 arg0)
{
    return D_005E2200[arg0];
}

// FUN_00106820
GDataEntry* func_00106820(s16 arg0)
{
    return (GDataEntry*)((u8*)D_007242A0 + (s32)arg0 * 68);
}

// FUN_00106850
u32 func_00106850(s32 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)(s16)arg0 * 68);
}

// FUN_00106880
u32 func_00106880(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 4);
}

// FUN_001068B0
u16 func_001068b0(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 8);
}

// FUN_001068E0
u16 func_001068e0(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0xA);
}

// FUN_00106910
u8 func_00106910(s16 arg0)
{
    return *(u8*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0xE);
}

// FUN_00106940
u16 func_00106940(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x10);
}

// FUN_00106970
u16 func_00106970(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x12);
}

// FUN_001069A0
u32 func_001069a0(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x24);
}

// FUN_001069D0
u16 func_001069d0(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x28);
}

// FUN_00106A00
u16 func_00106a00(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x2A);
}

// FUN_00106A30
u16 func_00106a30(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x2C);
}

// FUN_00106A60
u32 func_00106a60(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x30);
}

// FUN_00106A90
u32 func_00106a90(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x34);
}

// FUN_00106AC0
s8 func_00106ac0(s16 arg0)
{
    return *(s8*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x38);
}

// FUN_00106AF0
s8 func_00106af0(s16 arg0)
{
    return *(s8*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x39);
}

// FUN_00106B20
u32 func_00106b20(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x3C);
}

// FUN_00106B50
u32 func_00106b50(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x40);
}

/* Metadata IDs arrive as words; the signed low halfword selects the
 * bank-relative index. The word-sized input preserves all 176 bytes. */
// FUN_00106B80
s64 func_00106b80(s32 arg0)
{
    s16 temp_2;

    temp_2 = (s16)arg0;
    if (temp_2 < 0x100) {
        return temp_2;
    }
    if (temp_2 < 0x200) {
        return (s16)(temp_2 - 0x100);
    }
    if (temp_2 < 0x300) {
        return (s16)(temp_2 - 0x200);
    }
    if (temp_2 < 0x400) {
        return (s16)(temp_2 - 0x300);
    }
    if (temp_2 < 0x500) {
        return (s16)(temp_2 - 0x400);
    }
    return (s16)(temp_2 - 0x500);
}



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

/* The "load-sinking floor" here needed the word local AND the pragma together.
   The note was right that a word local alone still sinks the f30 load (nd 11),
   which is why one-liner / mask-order / GDataEntry* spellings all stalled there;
   `#pragma opt_propagation off` is what keeps that single-use load right after
   the base addu, and only then does the local hold it in place. Measured 11 -> 3
   (the 3 are the window's trailing padding), verify reports MATCH. */
// FUN_00106C30
#pragma opt_propagation off
s32 func_00106c30(s16 arg0, s16 arg1)
{
    u32 flags;

    flags = *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x30);
    return (flags & (1 << ((s32)arg1 + 4))) != 0;
}
#pragma opt_propagation on

// FUN_00106C80
s32 func_00106c80(s16 arg0)
{
    if (arg0 < 0x100)
    {
        return 0;
    }
    if (arg0 < 0x200)
    {
        return 1;
    }
    return 2;
}

// FUN_00106CD0
s16 func_00106cd0(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        return D_00797574[arg1];
    }
    else
    {
        return *(s16*)((u8*)D_00796D8C + (s32)arg0 * 0x88 + (s32)arg1 * 2);
    }
}

// FUN_00106D40
void func_00106d40(s16 arg0, s16 arg1, s16 arg2)
{
    if (arg0 == 1)
    {
        D_00797574[arg1] = arg2;
    }
    else
    {
        *(s16*)((u8*)D_00796D8C + (s32)arg0 * 0x88 + (s32)arg1 * 2) = arg2;
    }
}

// FUN_00108CB0
void func_00108cb0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}



// FUN_00108D80
void func_00108d80(void)
{
  long handle;

  if ((handle = func_00452380(D_005e4308)) == 0) {
    return;
  }
  func_00452080(handle);
  return;
}



// FUN_001090F0
void datResetTotalBtl(void)
{
    *(u32*)&D_00797560 = 0;
}



/* measured: retail compiles the GS doubled-alpha loop with a single bltz and
   one shared join (add.s $f1,$f1,$f0); mwcc b210 duplicates the whole loop
   tail (join + increments + test) for the else path in every spelling, and
   bloats the object past the 0x144 window. Tried: s32 value + >=0 (skill
   recipe), (s16)/(s32) casts, f=f+f and *2.0f doubling, u32 shift cast -
   best nd 37 with 188B object vs 144B window. Branch-duplication floor. */
/* The old "branch-duplication floor" note here was wrong twice over. The
   halve/convert/double branch around the accumulate is not something to write by
   hand - it is b210's built-in UNSIGNED-to-float conversion, so `(f32)(u32)x` emits
   the whole idiom with retail's shared tail. Hand-rolling the two arms is what
   bloated the object to 188B against a 144B window (nd 37).
   With the cast the size is exact and only the register roles differ: retail keeps
   the counter in $a0 and the walking pointer in $a1. That is DECLARATION order -
   declaring `u8 *p` before `s32 i` is byte-exact. Measured: the reverse order is
   nd 7, an `i = 0` before the pointer setup is nd 12, index arithmetic without a
   pointer local is nd 101, and fourteen allocation/loop pragmas all leave nd 7. */
// FUN_00109190
f32 func_00109190(void) {
    f32 sum;
    u8 *p;
    s32 i;

    sum = 0.0f;
    p = &D_007973A0[0x70];
    for (i = 0; i < 21; i++) {
        sum += (f32)(u32)*(u16 *)(p + 6);
        p += 16;
    }
    return sum / 210.0f;
}

// FUN_00109220
u8* func_00109220(s32 personaId)
{
    u16 id;

    K_ASSERT((personaId & 0xffff) < 0x100, 0x18);
    id = personaId;
    return DAT_00764530 + id * 0x11;
}



// FUN_00109280
u8 func_00109280(s32 personaId)
{
    u8* table;
    u16 id;

    K_ASSERT((personaId & 0xffff) < 0x100, 0x26);
    table = DAT_007644c4;
    id = personaId;
    return table[id * 0xE + 2];
}



// FUN_00109390
u8 datPersonaGetLevel(int persona)
{
    return *(u8*)(persona + 4);
}



// FUN_00109400
u8 datPersonaGetLevelByPcId(u16 pcId)
{
    PersonaWork* persona = func_0010a900(pcId);
    return persona->level;
}



// FUN_00109430
u32 datPersonaGetNextExp(int persona)
{
    return *(u32*)(persona + 8);
}



// FUN_00109440
u32 func_00109440(PersonaWork* persona)
{
    return func_0010c750(persona, (u16)(persona->level + 1));
}



// FUN_001094D0
u16* datPersonaGetSkills(int persona)
{
    return (u16*)(persona + 0xc);
}



// FUN_001094E0
u16* datPersonaGetSkillsByPcId(u16 pcId)
{
    PersonaWork* persona = func_0010a900(pcId);

    return persona->skills;
}



// FUN_00109D80
void datPersonaAddToBonusStatByPcId(u16 pcId, u16 statId, s8 amount)
{
    PersonaWork* persona = func_0010a900(pcId);

    persona->bonusStats[statId] += amount;
}



// FUN_0010C6F0
s32 func_0010c6f0(PersonaWork* persona)
{
    if (persona->level >= 99) {
        return 0;
    }
    return func_0010c750(persona, persona->level + 1) <= persona->nextExp;
}



static inline void datCollectValidSkills(u8* skillData, u16* skills,
                                         s32* validSkills, s32 skillLimit)
{
    s32 skillIdx;

    for (skillIdx = 0; skillIdx < skillLimit; skillIdx++)
    {
        if (skillData[skillIdx * 4] == 0 &&
            ((s8*)skillData)[skillIdx * 4 + 1] == 1)
        {
            skills[*validSkills] = *(u16*)(skillData + skillIdx * 4 + 2);
            (*validSkills)++;
        }
    }
}

// FUN_0010D360
void func_0010d360(u16 personaId, u16* skills, s32* skillCount)
{
    u8* skillData;
    s32 validSkills;

    validSkills = 0;
    if (personaId >= 0xc0 && personaId <= 0xd7)
    {
        skillData = (u8*)iGpffffb3e4 + (personaId - 0xc0) * 0x26e + 4;
        datCollectValidSkills(skillData, skills, &validSkills, 0x20);
    }
    else
    {
        skillData = (u8*)iGpffffb3dc + (u32)personaId * 0x46 + 6;
        datCollectValidSkills(skillData, skills, &validSkills, 0x10);
    }

    *skillCount = validSkills;
}

// FUN_0010D480
void func_0010d480(void)
{
}

// FUN_0010D490
void func_0010d490(u8* param_1, u8* param_2)
{
    s32 index;
    s8 value;

    FUN_0043f9c8(DAT_007973a0, 0, 0x24);
    index = 0;

    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_1 + index);
        if (value == '\0')
        {
            break;
        }
        DAT_007973a0[index] = value;
    }

    index = 0;
    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_2 + index);
        if (value == '\0')
        {
            break;
        }
        DAT_007973a0[index + 0x12] = value;
    }

    func_0010d560();
}
/* measured: see the annotation above the matching `on` pragma (func_0010d490). */
#pragma opt_loop_invariants off



// FUN_0010D560
void func_0010d560(void)
{
    FUN_0043f9c8(DAT_00796de0, 0, 0x12);
    FUN_0043f9c8(DAT_00796e00, 0, 0x12);
    FUN_0043f9c8(DAT_00796e20, 0, 0x24);
    memcpy(DAT_00796de0, DAT_007973a0, 0x12);
    memcpy(DAT_00796e00, DAT_007973b2, 0x12);
    sprintf(DAT_00796e20, &DAT_00762ca0, DAT_00796e00, DAT_00796de0);
}

// FUN_0010D620
u32 func_0010d620(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u32)DAT_00796e20;
    }
    else
    {
        return D_005E4480[arg0];
    }
}

// FUN_0010D660
u32 func_0010d660(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u32)DAT_00796de0;
    }
    if (arg0 < 0xB)
    {
        return D_005E4540[arg0];
    }
    return D_005E4480[arg0];
}

// FUN_0010D6D0
u32 func_0010d6d0(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u32)DAT_00796e00;
    }
    if (arg0 < 0xB)
    {
        return D_005E4570[arg0];
    }
    return D_005E4480[arg0];
}

// FUN_0010D740
u32 func_0010d740(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u32)DAT_00796e00;
    }
    if (arg0 < 0xB)
    {
        return D_005E4570[arg0];
    }
    return D_005E4480[arg0];
}

// FUN_0010D7B0
void func_0010d7b0(void)
{
}

extern u8 D_0079740C[];
extern u8 D_00797564[];
extern u8 D_00797B87[];
extern u8 D_00797F8C[];
extern u8 D_0079B690[];
extern u8 D_0079B698[];
extern u8 D_0079B69C[];
extern u8 D_0079B6A0[];
extern u8 D_0079B6D8[];
extern u8 D_0079BEF4[];
extern u8 D_007BBF00[];
extern s32 iGpffffb1b4;
extern s32 iGpffffb1b8;
extern u8 *func_0015a690(void);
extern s32 func_0015a6a0(void);

/* The inferred nested metadata layout leaves one natural tail-padding byte.
 * Retail includes that byte in the character-wise summary checksum.
 * 3908/3920 bytes; 219 resolved relocations; 12 zero alignment bytes. */
extern u8 *iGpffff9db0;
extern u8 *(*D_008873F4[])(s32 count, s32 size, s32 hint);
extern s32 func_0015a160(void);
extern u32 func_00110460(void);
extern u32 D_0079B3CC[];
extern char D_005E45A0[];
typedef struct DatSaveMetadata {
    s16 date;
    u16 period;
    u32 elapsed;
    u8 level;
    u8 difficulty;
    u8 cleared;
} DatSaveMetadata;
typedef struct DatSaveSummary {
    DatSaveMetadata metadata;
    s8 names[2][18];
    u8 mode;
    u8 submode;
    u16 checksum;
} DatSaveSummary;
typedef char DatSaveMetadataSize[(sizeof(DatSaveMetadata) == 12) ? 1 : -1];
typedef char DatSaveSummarySize[(sizeof(DatSaveSummary) == 52) ? 1 : -1];

#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_0010D7C0
u8 *func_0010d7c0(s32 version, s32 *outSize, s32 compact)
{
    u8 checksum;
    s32 tag;
    s32 length;
    DatSaveSummary summary;
    u8 *buffer;
    u8 *records;
    u8 *cursor;
    u8 *unit;
    s32 total;
    s32 eventEnd;
    u32 nameIndex;
    u32 surnameIndex;
    u32 unitIndex;
    u32 checksumIndex;
    u8 threshold;
    u8 level;
    u8 sum;
    u32 summaryIndex;
    u8 resultLevel;
    s32 experience;
    u8 *summaryBytes;

    *(s32 *)D_0079B698 = *(s32 *)iGpffff9db0;
    *(s32 *)D_0079B69C = *(s32 *)(iGpffff9db0 + 4);
    *(s32 *)D_0079B6A0 = func_0015a160();
    func_0044ea90(D_005E4298, 0x721);
    buffer = D_008873F4[0](1, 0x2A000, 0x40000);
    tag = 0;
    total = 0;
    func_0043f810(buffer, &version, 4);
    summary.metadata.elapsed = iGpffffb19c;
    D_0079B67C[0] = iGpffffb19c;
    summary.metadata.date = D_00797B7A[0];
    summary.metadata.period = D_00797B7C[0];
    for (nameIndex = 0; nameIndex < 18; nameIndex++)
        summary.names[0][nameIndex] = ((s8 *)D_007973A0)[nameIndex];
    for (surnameIndex = 0; surnameIndex < 18; surnameIndex++)
        summary.names[1][surnameIndex] = *((s8 *)D_007973A0 + surnameIndex + 18);
    summary.mode = *(s32 *)iGpffff9db0;
    summary.submode = *(s32 *)(iGpffff9db0 + 4);
    experience = D_00797400[0];
    level = 0;
    threshold = 0;
    goto level_test;
level_body:
    if (experience < D_005DD6E0[threshold]) {
        resultLevel = level;
        goto level_done;
    }
    level++;
    threshold++;
level_test:
    if (threshold < 99)
        goto level_body;
    resultLevel = 99;
level_done:
    summary.metadata.level = resultLevel;
    summary.metadata.cleared = func_00110460();
    if (D_0079B3CC[0] & 0x10000)
        summary.metadata.difficulty = 0;
    else if (D_0079B3CC[0] & 0x20000)
        summary.metadata.difficulty = 2;
    else
        summary.metadata.difficulty = 1;
    summaryBytes = (u8 *)&summary;
    sum = 0;
    for (summaryIndex = 0; summaryIndex < 50; summaryIndex++)
        sum += summaryBytes[summaryIndex];
    summary.checksum = sum;
    func_0043f810(buffer + 4, &summary, 52);
    records = buffer + 56;
    tag = 1;
    func_0043f810(records, &tag, 4);
    length = 36;
    func_0043f810(buffer + 60, &length, 4);
    func_0043f810(buffer + 64, D_007973A0, 36);
    tag = 2;
    func_0043f810(buffer + 100, &tag, 4);
    length = 72;
    func_0043f810(buffer + 104, &length, 4);
    func_0043f810(buffer + 108, D_007973C4, 72);
    tag = 3;
    func_0043f810(buffer + 180, &tag, 4);
    length = 344;
    func_0043f810(buffer + 184, &length, 4);
    func_0043f810(buffer + 188, D_0079740C, 344);
    tag = 4;
    func_0043f810(buffer + 532, &tag, 4);
    length = 16;
    func_0043f810(buffer + 536, &length, 4);
    func_0043f810(buffer + 540, D_00797564, 16);
    tag = 5;
    func_0043f810(buffer + 556, &tag, 4);
    length = 6;
    func_0043f810(buffer + 560, &length, 4);
    func_0043f810(buffer + 564, D_00797574, 6);
    tag = 6;
    func_0043f810(buffer + 570, &tag, 4);
    length = 1536;
    func_0043f810(buffer + 574, &length, 4);
    func_0043f810(buffer + 578, D_0079757A, 1536);
    tag = 8;
    func_0043f810(buffer + 2114, &tag, 4);
    length = 2;
    func_0043f810(buffer + 2118, &length, 4);
    func_0043f810(buffer + 2122, D_00797B7A, 2);
    tag = 9;
    func_0043f810(buffer + 2124, &tag, 4);
    length = 1;
    func_0043f810(buffer + 2128, &length, 4);
    func_0043f810(buffer + 2132, D_00797B7C, 1);
    tag = 10;
    func_0043f810(buffer + 2133, &tag, 4);
    length = 4;
    func_0043f810(buffer + 2137, &length, 4);
    func_0043f810(buffer + 2141, D_00797B80, 4);
    tag = 11;
    func_0043f810(buffer + 2145, &tag, 4);
    length = 2;
    func_0043f810(buffer + 2149, &length, 4);
    func_0043f810(buffer + 2153, D_00797B84, 2);
    tag = 12;
    func_0043f810(buffer + 2155, &tag, 4);
    length = 1;
    func_0043f810(buffer + 2159, &length, 4);
    func_0043f810(buffer + 2163, D_00797B86, 1);
    tag = 13;
    func_0043f810(buffer + 2164, &tag, 4);
    length = 1024;
    func_0043f810(buffer + 2168, &length, 4);
    func_0043f810(buffer + 2172, D_00797B87, 1024);
    tag = 14;
    func_0043f810(buffer + 3196, &tag, 4);
    length = 2;
    func_0043f810(buffer + 3200, &length, 4);
    func_0043f810(buffer + 3204, D_00797F88, 2);
    tag = 15;
    func_0043f810(buffer + 3206, &tag, 4);
    length = 576;
    func_0043f810(buffer + 3210, &length, 4);
    func_0043f810(buffer + 3214, D_00797F8C, 576);
    tag = 16;
    func_0043f810(buffer + 3790, &tag, 4);
    length = 12288;
    func_0043f810(buffer + 3794, &length, 4);
    func_0043f810(buffer + 3798, D_007981CC, 12288);
    tag = 17;
    func_0043f810(buffer + 16086, &tag, 4);
    length = 704;
    func_0043f810(buffer + 16090, &length, 4);
    func_0043f810(buffer + 16094, D_0079B1CC, 704);
    tag = 18;
    func_0043f810(buffer + 16798, &tag, 4);
    length = 4;
    func_0043f810(buffer + 16802, &length, 4);
    func_0043f810(buffer + 16806, D_0079B68C, 4);
    tag = 19;
    func_0043f810(buffer + 16810, &tag, 4);
    length = 8;
    func_0043f810(buffer + 16814, &length, 4);
    func_0043f810(buffer + 16818, D_0079B690, 8);
    tag = 21;
    func_0043f810(buffer + 16826, &tag, 4);
    length = 4;
    func_0043f810(buffer + 16830, &length, 4);
    func_0043f810(buffer + 16834, D_0079B698, 4);
    tag = 22;
    func_0043f810(buffer + 16838, &tag, 4);
    length = 4;
    func_0043f810(buffer + 16842, &length, 4);
    func_0043f810(buffer + 16846, D_0079B69C, 4);
    tag = 23;
    func_0043f810(buffer + 16850, &tag, 4);
    length = 4;
    func_0043f810(buffer + 16854, &length, 4);
    func_0043f810(buffer + 16858, D_0079B6A0, 4);
    tag = 24;
    func_0043f810(buffer + 16862, &tag, 4);
    length = 340;
    func_0043f810(buffer + 16866, &length, 4);
    func_0043f810(buffer + 16870, D_0079BCD8, 340);
    tag = 25;
    func_0043f810(buffer + 17210, &tag, 4);
    length = 512;
    func_0043f810(buffer + 17214, &length, 4);
    func_0043f810(buffer + 17218, D_0079B48C, 512);
    tag = 26;
    func_0043f810(buffer + 17730, &tag, 4);
    length = 1536;
    func_0043f810(buffer + 17734, &length, 4);
    func_0043f810(buffer + 17738, D_0079B6D8, 1536);
    tag = 27;
    func_0043f810(buffer + 19274, &tag, 4);
    length = 52;
    func_0043f810(buffer + 19278, &length, 4);
    func_0043f810(buffer + 19282, D_0079B6A4, 52);
    tag = 34;
    func_0043f810(buffer + 19334, &tag, 4);
    length = 1;
    func_0043f810(buffer + 19338, &length, 4);
    func_0043f810(buffer + 19342, D_00797B7C, 1);
    tag = 35;
    func_0043f810(buffer + 19343, &tag, 4);
    length = 4;
    func_0043f810(buffer + 19347, &length, 4);
    func_0043f810(buffer + 19351, D_0079BEF4, 4);
    cursor = buffer + 19355;
    total += 19355;
    if (compact == 0) {
        tag = 37;
        func_0043f810(cursor, &tag, 4);
        length = 4;
        func_0043f810(cursor + 4, &length, 4);
        func_0043f810(cursor + 8, &iGpffffb1b4, 4);
        tag = 38;
        func_0043f810(cursor + 12, &tag, 4);
        length = 4;
        func_0043f810(cursor + 16, &length, 4);
        func_0043f810(cursor + 20, &iGpffffb1b8, 4);
        tag = 39;
        func_0043f810(cursor + 24, &tag, 4);
        length = 86016;
        func_0043f810(cursor + 28, &length, 4);
        func_0043f810(cursor + 32, D_007BBF00, 86016);
        cursor += 0x15020;
        total += 0x15020;
    }
    tag = 40;
    func_0043f810(cursor, &tag, 4);
    length = 200;
    func_0043f810(cursor + 4, &length, 4);
    func_0043f810(cursor + 8, D_0079BE2C, 200);
    tag = 41;
    func_0043f810(cursor + 208, &tag, 4);
    length = func_0015a6a0();
    func_0043f810(cursor + 212, &length, 4);
    cursor += 216;
    eventEnd = total + 216;
    func_0043f810(cursor, func_0015a690(), func_0015a6a0());
    cursor += func_0015a6a0();
    total = eventEnd + func_0015a6a0();
    for (unitIndex = 0; unitIndex < 10; unitIndex++) {
        tag = (unitIndex << 8) + 0x100;
        func_0043f810(cursor, &tag, 4);
        length = 4;
        func_0043f810(cursor + 4, &length, 4);
        unit = D_00796E50 + unitIndex * 0x88;
        func_0043f810(cursor + 8, unit, 4);
        tag = (unitIndex << 8) + 257;
        func_0043f810(cursor + 12, &tag, 4);
        length = 72;
        func_0043f810(cursor + 16, &length, 4);
        func_0043f810(cursor + 20, unit + 4, 72);
        tag = (unitIndex << 8) + 258;
        func_0043f810(cursor + 92, &tag, 4);
        length = 6;
        func_0043f810(cursor + 96, &length, 4);
        func_0043f810(cursor + 100, unit + 76, 6);
        tag = (unitIndex << 8) + 261;
        func_0043f810(cursor + 106, &tag, 4);
        length = 48;
        func_0043f810(cursor + 110, &length, 4);
        func_0043f810(cursor + 114, unit + 84, 48);
        tag = (unitIndex << 8) + 267;
        func_0043f810(cursor + 162, &tag, 4);
        length = 4;
        func_0043f810(cursor + 166, &length, 4);
        func_0043f810(cursor + 170, unit + 132, 4);
        cursor += 174;
        total += 174;
    }
    checksum = 0;
    for (checksumIndex = 0; checksumIndex < (u32)(total - 56); checksumIndex++)
        checksum += records[checksumIndex];
    tag = 0x2000;
    func_0043f810(cursor, &tag, 4);
    length = 1;
    func_0043f810(cursor + 4, &length, 4);
    func_0043f810(cursor + 8, &checksum, 1);
    tag = -1;
    func_0043f810(cursor + 9, &tag, 4);
    *outSize = total + 13;
    func_00440b68(D_005E45A0, total + 13);
    return buffer;
}
#pragma pop

// FUN_0010E710
void func_0010e710(s32 arg0, u8 *arg1, s32 arg2)
{
    u32 v1;
    u32 v2;
    u8* p = arg1 + 0x34;

    while (1)
    {
        func_0043f810(&v1, p, 4);
        func_00440b68(D_005E45C0, v1);
        if (v1 == -1 || v1 == 0x2000)
        {
            break;
        }
        func_0043f810(&v2, p + 4, 4);
        p = p + 8;
        func_0010e9e0(arg0, v1, v2, p);
        p = p + v2;
    }
    iGpffffb19c = D_0079B67C[0];
    func_0043f9c8(DAT_00796de0, 0, 0x12);
    func_0043f9c8(DAT_00796e00, 0, 0x12);
    func_0043f9c8(DAT_00796e20, 0, 0x24);
    func_0043f810(DAT_00796de0, DAT_007973a0, 0x12);
    func_0043f810(DAT_00796e00, DAT_007973b2, 0x12);
    func_00442088(DAT_00796e20, &iGpffff9bb0, DAT_00796e00, DAT_00796de0);
}

// FUN_0010E880
s32 func_0010e880(s32 arg0, u8 *arg1, s32 arg2)
{
    u8 byte;
    u32 v1;
    u32 v2;
    u32 limit;
    u32 sum;
    u8* p;
    s32 checksum;
    u32 i;

    if (arg2 < 0x1000)
    {
        return 0;
    }
    p = arg1 + 0x34;
    sum = 0;
    limit = (u32)(arg2 - 0x34);
    while (1)
    {
        func_0043f810(&v1, p, 4);
        if (v1 == -1)
        {
            break;
        }
        if (v1 == 0x2000)
        {
            checksum = 0;
            i = 0;
            while (i < sum)
            {
                checksum = (checksum + *(u8*)(arg1 + i + 0x34)) & 0xFF;
                i = i + 1;
            }
            func_0043f810(&v2, p + 4, 4);
            func_0043f810(&byte, p + 8, 1);
            return (checksum & 0xFF) == byte;
        }
        func_0043f810(&v2, p + 4, 4);
        if (v2 == 0)
        {
            return 0;
        }
        p = p + 8;
        p = p + v2;
        sum = sum + 8;
        sum = sum + v2;
        if (sum >= limit)
        {
            return 0;
        }
    }
    return 0;
}

/* 2480/2480 bytes; 106 fully resolved relocations. */
// FUN_0010E9E0
void func_0010e9e0(s32 arg0, u32 arg1, u32 arg2, u8* arg3)
{
    u32 index;
    switch (arg1) {
    case 1:
        if (arg2 == 36)
            func_0043f810(D_007973A0, arg3, 36);
        break;
    case 2:
        if (arg2 == 72)
            func_0043f810(D_007973C4, arg3, 72);
        break;
    case 3:
        if (arg2 == 344)
            func_0043f810(D_0079740C, arg3, 344);
        break;
    case 4:
        if (arg2 == 16)
            func_0043f810(D_00797564, arg3, 16);
        break;
    case 5:
        if (arg2 == 6)
            func_0043f810(D_00797574, arg3, 6);
        break;
    case 6:
        if (arg2 == 1536)
            func_0043f810(D_0079757A, arg3, arg2);
        break;
    case 8:
        if (arg2 == 2)
            func_0043f810(D_00797B7A, arg3, arg2);
        break;
    case 9:
        if (arg2 == 1)
            func_0043f810(D_00797B7C, arg3, arg2);
        break;
    case 10:
        if (arg2 == 4)
            func_0043f810(D_00797B80, arg3, arg2);
        break;
    case 11:
        if (arg2 == 2)
            func_0043f810(D_00797B84, arg3, arg2);
        break;
    case 12:
        if (arg2 == 1)
            func_0043f810(D_00797B86, arg3, arg2);
        break;
    case 13:
        if (arg2 == 1024)
            func_0043f810(D_00797B87, arg3, arg2);
        break;
    case 14:
        if (arg2 == 2)
            func_0043f810(D_00797F88, arg3, arg2);
        break;
    case 15:
        if (arg2 == 576)
            func_0043f810(D_00797F8C, arg3, arg2);
        break;
    case 16:
        if (arg2 == 12288)
            func_0043f810(D_007981CC, arg3, arg2);
        break;
    case 17:
        if (arg2 == 704)
            func_0043f810(D_0079B1CC, arg3, arg2);
        break;
    case 18:
        if (arg2 == 4)
            func_0043f810(D_0079B68C, arg3, arg2);
        break;
    case 19:
        if (arg2 == 8)
            func_0043f810(D_0079B690, arg3, arg2);
        break;
    case 21:
        if (arg2 == 4)
            func_0043f810(D_0079B698, arg3, arg2);
        break;
    case 22:
        if (arg2 == 4)
            func_0043f810(D_0079B69C, arg3, arg2);
        break;
    case 23:
        if (arg2 == 4)
            func_0043f810(D_0079B6A0, arg3, arg2);
        break;
    case 24:
        if (arg2 == 340)
            func_0043f810(D_0079BCD8, arg3, arg2);
        break;
    case 25:
        if (arg2 == 512)
            func_0043f810(D_0079B48C, arg3, arg2);
        break;
    case 26:
        if (arg2 == 1536)
            func_0043f810(D_0079B6D8, arg3, arg2);
        break;
    case 27:
        if (arg2 == 52)
            func_0043f810(D_0079B6A4, arg3, arg2);
        break;
    case 32:
        break;
    case 34:
        if (arg2 == 1)
            func_0043f810(D_00797B7C, arg3, arg2);
        break;
    case 35:
        if (arg2 == 4)
            func_0043f810(D_0079BEF4, arg3, arg2);
        break;
    case 37:
        if (arg2 == 4)
            func_0043f810(&iGpffffb1b4, arg3, arg2);
        break;
    case 38:
        if (arg2 == 4)
            func_0043f810(&iGpffffb1b8, arg3, arg2);
        break;
    case 39:
        if (arg2 == 86016)
            func_0043f810(D_007BBF00, arg3, arg2);
        break;
    case 40:
        if (arg2 == 200)
            func_0043f810(D_0079BE2C, arg3, arg2);
        break;
    case 41:
        if (arg2 == func_0015a6a0())
            func_0043f810(func_0015a690(), arg3, arg2);
        break;
    case 0x100:
    case 0x200:
    case 0x300:
    case 0x400:
    case 0x500:
    case 0x600:
    case 0x700:
    case 0x800:
    case 0x900:
    case 0xa00:
        index = arg1 >> 8;
        if (arg2 == 4)
            func_0043f810(D_00796E50 + (index - 1) * 0x88, arg3, arg2);
        break;
    case 0x101:
    case 0x201:
    case 0x301:
    case 0x401:
    case 0x501:
    case 0x601:
    case 0x701:
    case 0x801:
    case 0x901:
    case 0xa01:
        index = arg1 >> 8;
        if (arg2 == 72)
            func_0043f810(D_00796E50 + (index - 1) * 0x88 + 4, arg3, arg2);
        break;
    case 0x102:
    case 0x202:
    case 0x302:
    case 0x402:
    case 0x502:
    case 0x602:
    case 0x702:
    case 0x802:
    case 0x902:
    case 0xa02:
        index = arg1 >> 8;
        if (arg2 == 6)
            func_0043f810(D_00796E50 + (index - 1) * 0x88 + 76, arg3, arg2);
        break;
    case 0x105:
    case 0x205:
    case 0x305:
    case 0x405:
    case 0x505:
    case 0x605:
    case 0x705:
    case 0x805:
    case 0x905:
    case 0xa05:
        index = arg1 >> 8;
        if (arg2 == 48)
            func_0043f810(D_00796E50 + (index - 1) * 0x88 + 84, arg3, arg2);
        break;
    }
}

// FUN_0010F390
void func_0010f390(void)
{
    u32 i = 0;
    u8* p = (u8*)DAT_007973a0;

    while (i < 0x55)
    {
        *(u32*)(p + i * 4 + 0x4938) = 0;
        i = i + 1;
    }
}

/* Unsigned masks define bit 31 without changing either retail shift. */
// FUN_0010F3D0
void func_0010f3d0(u32 arg0, u32 arg1)
{
    u32 bit = (arg1 & 0xffff) + (arg0 & 0xffff) * 8;

    *(u32*)((u8*)D_0079BCD8 + (bit >> 5) * 4) |= 1U << (bit & 0x1f);
}

// FUN_0010F420
u32 func_0010f420(u32 arg0, u32 arg1)
{
    u32 bit = (arg1 & 0xffff) + (arg0 & 0xffff) * 8;
    u32* p = &D_0079BCD8[bit >> 5];

    return *p & (1U << (bit & 0x1f));
}

static inline u32 bitAndFirst(u32 a, u32 b)
{
    return a & b;
}

/* measured: opt_loop_invariants on hoists the sllv constant 1 and keeps the
   D_007973A0 base in $a3 like retail; without it mwcc rematerializes addiu
   $v1,0,1 in the loop body (nd 18 -> 0). */
#pragma opt_loop_invariants on

// FUN_0010F460
u32 func_0010f460(u16 arg0)
{
    u32 result = 0;
    u32 j = (u32)arg0 * 8;
    u32 i = 0;
    u8* base = DAT_007973a0;

    while (i < 8)
    {
        result |= bitAndFirst(*(u32*)(base + (j >> 5) * 4 + 0x4938), 1 << (j & 0x1F));
        i = i + 1;
        j = j + 1;
    }
    return result;
}
#pragma opt_loop_invariants off

// FUN_0010F4C0
void func_0010f4c0(void)
{
    func_00193ad0(D_0079BE2C);
}

// FUN_0010F4F0
u8 *func_0010f4f0(s32 arg0) {
    s32 v = (s16)arg0;

    if ((v == 0) || (v >= 0xB)) {
        return NULL;
    }
    return (u8 *)(((s32)D_007973A0 + ((v - 1) * 0x14)) + 0x4A8C);
}

// FUN_0010F540
void func_0010f540(void)
{
    func_00232a40();
}

// FUN_0010F560
void func_0010f560(s16 arg0, u8* arg1)
{
    u8* p;

    if (arg0 == 1)
    {
        p = (u8*)D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        p = (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
    func_0023dd90(p, arg1);
}

// FUN_0010F600
u32 func_0010f600(s16 arg0, s32 arg1)
{
    u8* p;

    if (arg0 == 1)
    {
        p = (u8*)D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        p = (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
    return func_0023d9b0(p, arg1);
}

// FUN_0010F6A0
void func_0010f6a0(s16 arg0, u32 arg1)
{
    u8* ptr;
    u16 v;

    if (arg0 == 1)
    {
        ptr = D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        ptr = (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
    v = *(u16*)(ptr + 2);
    K_ASSERT(v != 0 && v < 0xB, 0xE54);
    func_0023ddc0((u32)ptr, arg1);
}

// FUN_0010F770
void func_0010f770(s16 arg0, s16 arg1, u32 arg2, u32 arg3)
{
    u8* ptr1;
    u8* ptr2;

    K_ASSERT(arg1 != 0 && arg1 < 0xB, 0xE6A);
    if (arg0 == 1)
    {
        ptr1 = D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        ptr1 = (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
    if (arg1 == 1)
    {
        ptr2 = D_007973C4;
    }
    else
    {
        K_ASSERT(arg1 < 0xB, 0x234);
        ptr2 = (u8*)D_00796E50 + (arg1 - 2) * 0x88 + 4;
    }
    func_00239f50(arg2, ptr1, ptr2, arg3);
}

// FUN_0010F8C0
u16 func_0010f8c0(s32 arg0)
{
    u8* table;
    u16 id;

    K_ASSERT((arg0 & 0xffff) < 0x1B8, 0xE87);
    table = DAT_007644A8;
    id = arg0;
    return table[id * 0x28 + 8];
}

// FUN_0010F930
void func_0010f930(s16 arg0, s16 arg1, u32 arg2, u32 arg3)
{
    u8* ptr1;
    u8* ptr2;

    K_ASSERT(arg1 != 0 && arg1 < 0xB, 0xEAC);
    if (arg0 == 1)
    {
        ptr1 = D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        ptr1 = (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
    if (arg1 == 1)
    {
        ptr2 = D_007973C4;
    }
    else
    {
        K_ASSERT(arg1 < 0xB, 0x234);
        ptr2 = (u8*)D_00796E50 + (arg1 - 2) * 0x88 + 4;
    }
    func_0023a1e0(arg2, ptr1, ptr2, arg3);
}

// FUN_0010FA80
void func_0010fa80(s16 arg0, s16 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6)
{
    u8* ptr1;
    u8* ptr2;

    if (arg0 == 1)
    {
        ptr1 = D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        ptr1 = (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
    if (arg1 == 1)
    {
        ptr2 = D_007973C4;
    }
    else
    {
        K_ASSERT(arg1 < 0xB, 0x234);
        ptr2 = (u8*)D_00796E50 + (arg1 - 2) * 0x88 + 4;
    }
    func_0023a490(arg2, ptr1, ptr2, arg3, (s32*)arg4, (s32*)arg5, (s32*)arg6);
}

// FUN_0010FBD0
u32 func_0010fbd0(u32 arg0)
{
    u16 f;

    K_ASSERT(arg0 < 0x100, 0xF04);
    f = *(u16*)((u8*)DAT_007644D0 + arg0 * 0x58);
    if (f & 2)
    {
        return 2;
    }
    if (f & 4)
    {
        return 4;
    }
    if (f & 8)
    {
        return 8;
    }
    return 0;
}

// FUN_0010FC80
void func_0010fc80(void)
{
    FUN_0043f9c8(D_007981CC, 0, 0x3000);
}

// FUN_0010FCB0
u8* func_0010fcb0(s32 arg0)
{
    u16 v;

    K_ASSERT(arg0 >= 0 && arg0 < 0x100, 0xF1D);
    v = *(u16*)((u8*)D_007981CC + arg0 * 0x30);
    if (v & 1)
    {
        return (u8*)DAT_007973a0 + arg0 * 0x30 + 0xE2C;
    }
    return 0;
}

// FUN_0010FD40
void func_0010fd40(u8* src)
{
    s32 index;

    K_ASSERT(src != 0, 0xF27);
    index = *(u16*)(src + 2);
    K_ASSERT(index >= 0 && index < 0x100, 0xF28);
    func_0043f810((u8*)DAT_007973a0 + *(u16*)(src + 2) * 48 + 0xE2C, src, 0x30);
}

// FUN_0010FDE0
u8* func_0010fde0(u8* arg0)
{
    s32 v;
    u16 w;
    u8* q;

    if (arg0 == NULL)
    {
        FUN_0046d730(__FILE__, 0xF5D);
    }
    v = *(u16*)(arg0 + 2);
    if ((v < 0) || (v >= 0x100))
    {
        FUN_0046d730(__FILE__, 0xF5E);
    }
    v = *(u16*)(arg0 + 2);
    w = *(u16*)((u8*)iGpffffb3d4 + v * 14);
    if (w & 8)
    {
        return arg0;
    }
    if (w & 0x20)
    {
        return arg0;
    }
    if ((v < 0) || (v >= 0x100))
    {
        FUN_0046d730(__FILE__, 0xF1D);
    }
    if (*(u16*)(D_007981CC + v * 0x30) & 1)
    {
        q = (u8*)D_007973A0 + v * 0x30 + 0xE2C;
    }
    else
    {
        q = NULL;
    }
    if (q != NULL)
    {
        return q;
    }
    if (arg0 == NULL)
    {
        FUN_0046d730(__FILE__, 0xF27);
    }
    v = *(u16*)(arg0 + 2);
    if ((v < 0) || (v >= 0x100))
    {
        FUN_0046d730(__FILE__, 0xF28);
    }
    v = *(u16*)(arg0 + 2);
    func_0043f810((u8*)D_007973A0 + v * 0x30 + 0xE2C, arg0, 0x30);
    return NULL;
}

// FUN_0010FFA0
extern void func_0010cad0(u8 *arg0, u16 arg1);
void func_0010ffa0(void) {
    u8 buf[0x30];
    u8 *base;
    s32 id;
    s32 i;

    i = 1;
    while (i < 0x100)
    {
        FUN_0043f9c8(buf, 0, 0x30);
        func_0010cad0(buf, (u16)i);
        *(u16 *)buf |= 1;
        if (((s32)*(u16 *)(buf + 2) < 0) || ((s32)*(u16 *)(buf + 2) >= 0x100))
        {
            FUN_0046d730((const char *)D_005E4298, 0xF5E);
        }
        base = iGpffffb3d4;
        id = *(u16 *)(buf + 2);
        if (!(*(u16 *)(base + id * 0xE) & 8) &&
            !(*(u16 *)(base + id * 0xE) & 0x20))
        {
            if (((s32)*(u16 *)(buf + 2) < 0) || ((s32)*(u16 *)(buf + 2) >= 0x100))
            {
                FUN_0046d730((const char *)D_005E4298, 0xF1D);
            }
            {
                u8 *q;
                q = (u8 *)DAT_007973a0 + id * 0x30;
                if (*(u16 *)(q + 0xE2C) & 1)
                {
                    q = q + 0xE2C;
                }
                else
                {
                    q = NULL;
                }
                if (q == NULL)
                {
                    if (((s32)*(u16 *)(buf + 2) < 0) || ((s32)*(u16 *)(buf + 2) >= 0x100))
                    {
                        FUN_0046d730((const char *)D_005E4298, 0xF28);
                    }
                    func_0043f810((u8 *)DAT_007973a0 + (s32)*(u16 *)(buf + 2) * 0x30 + 0xE2C, buf, 0x30);
                }
            }
        }
        i = i + 1;
    }
}

// FUN_00110140
s32 func_00110140(void)
{
    s32 count1 = 0;
    s32 i = 0;
    s32 count2;
    s32 j;
    u8* q;
    u16 v;
    u8* p;

    while (i < 0x100)
    {
        if ((i < 0) || (i >= 0x100))
        {
            FUN_0046d730(__FILE__, 0xF1D);
        }
        p = (u8*)DAT_007973a0 + i * 0x30;
        if (*(u16*)(p + 0xE2C) & 1)
        {
            q = p + 0xE2C;
        }
        else
        {
            q = NULL;
        }
        if (q != NULL)
        {
            count1 = count1 + 1;
        }
        i = i + 1;
    }
    count2 = 0;
    j = 0;
    p = (u8*)iGpffffb3d4;
    while (j < 0x100)
    {
        v = *(u16*)(p + j * 0xE);
        if (!(v & 8) && !(v & 0x20))
        {
            count2 = count2 + 1;
        }
        j = j + 1;
    }
    return count1 * 0x64 / count2;
}

// FUN_00110270
void func_00110270(u8* src, u16 arg1)
{
    func_0043f810(D_0079B6A8, src, 0x30);
    D_0079B6A4[0] = arg1;
}

// FUN_001102C0
void func_001102c0(s16 arg0)
{
    D_0079B6A4[0] = arg0;
}

// FUN_001102D0
u16 func_001102d0(void)
{
    return D_0079B6A4[0];
}

// FUN_001102E0
u8* func_001102e0(void)
{
    return D_0079B6A8;
}

// FUN_001102F0
u8* func_001102f0(u8* arg0, s32 arg1, s32 arg2, f32 fparg0)
{
    f32 buf[3];
    u8* obj;
    u8* obj3;

    if (arg0 == NULL)
    {
        FUN_0046d730(__FILE__, 0xFB8);
    }
    obj = func_00457120();
    buf[0] = -((f32)arg1 - 320.0f) * *(f32*)(obj + 0x68) / 320.0f;
    buf[1] = -((f32)arg2 - 224.0f) * *(f32*)(obj + 0x6C) / 224.0f;
    buf[2] = 1.0f;
    func_003e40b0(buf, buf);
    obj3 = func_003e9700(*(s32*)(func_00457120() + 4));
    func_003e4320(buf, buf, obj3);
    buf[0] = buf[0] * fparg0;
    buf[1] = buf[1] * fparg0;
    buf[2] = buf[2] * fparg0;
    *(f32*)(arg0 + 0) = *(f32*)(obj3 + 0x30) + buf[0];
    *(f32*)(arg0 + 4) = *(f32*)(obj3 + 0x34) + buf[1];
    *(f32*)(arg0 + 8) = *(f32*)(obj3 + 0x38) + buf[2];
    return arg0;
}
