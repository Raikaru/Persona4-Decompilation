#include "include_asm.h"
#include "type.h"
/* Force the offset operand into the first addu slot. */
static inline u32 addOffsetFirst(u32 offset, u32 base) {
    return offset + base;
}

/* Force the base operand into the first addu slot. */
static inline u32 addBaseFirst(u32 base, u32 offset) {
    return base + offset;
}
static inline s32 promoteS16(s16 value) {
    return value;
}
static inline u32 addOffsetAfterBase(u32 base, u32 offset) {
    return offset + base;
}

extern s32 func_00232710(s32 arg0, s32 arg1);
extern s32 func_002326e0(s32 arg0);
extern s32 func_00243ce0(s32 arg0);
extern u8 *iGpffffb3c4;
extern s32 func_00231ed0(u8 *arg0);
extern s32 func_00231ee0(u8 *arg0);
extern s32 func_00231f80(u8 *arg0);
extern s32 func_00232290(u8 *arg0);
extern s32 func_002326c0(u8 *arg0);
extern s32 func_002428f0(u8 *arg0, s32 arg1);
extern s32 func_00106330(s32 arg0);
extern s32 func_0010f420(s32 arg0, s32 arg1);
extern u8 *iGpffffb3bc;
extern u8 *iGpffffb3d0;

extern s32 func_001f56d0(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern u16 func_001d7f10();
extern void func_001f62b0();
extern void func_001f58d0();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_0045af90(s32 arg0);

extern void memset(void *destination, s32 value, u32 size);

extern s32 func_001ef720(s32 arg0, s32 arg1);
extern s32 func_001ef5f0(s32 arg0, s32 arg1, s32 arg2);

extern u32 func_00231d70(s32 arg0);
extern s32 func_00243950(s32 arg0);
extern s32 func_002439c0(s32 arg0);
extern s32 func_00243a30(s32 arg0, s32 *arg1);
extern void func_0046d730(void *arg0, s32 arg1);
extern u8 D_0060AB08[];
extern s32 func_002340c0(s32 arg0, s32 arg1);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern s16 func_001060b0(void);
extern s32 func_00110d60(s32 arg0);
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern s32 func_001f65d0(u8 *arg0);
extern u8 D_00624B20[];
extern u8 D_00624B22[];
extern s32 func_001ef9a0(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern s32 func_00459880(void);

extern void func_00454bd0(u8 *arg0);
extern void func_00235020(s32 arg0);
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
extern void func_002bd3c0(void);

extern s32 func_0045ae10(s32 arg0, s64 arg1, u16 arg2);
extern void func_0045aa90();
extern void func_0045af60(s32 bank, s32 channel, s32 cue, s32 variant);
extern void func_002bd3e0(void);
extern void func_002bd410(void);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern s32 func_0022bad0(u8 *arg0, s16 arg1);
extern s32 func_0022bc80(s32 arg0);
extern s32 func_001fa7a0(s32 *arg0);
extern s32 func_001fa940(void);
extern s32 func_001faa00(void);
extern s32 func_0022bd00(void);
extern s32 func_00120ee0(s32 arg0);
extern s32 func_004553c0(u8 *arg0);
extern s32 func_00484bb0(s32 arg0, u8 *arg1);
extern void func_00243e70(s32 arg0);
extern void func_00231f20(s32 arg0, s32 arg1);
extern void func_002326f0(s32 arg0, s32 arg1);
extern void func_00232680(s32 arg0, s32 arg1);

extern void func_00485b20(s32 arg0);
extern void func_00486180(s32 arg0);
extern void func_00120f20(s32 arg0);
extern s32 func_00122520(s32 arg0, s32 arg1);
extern void func_001228a0(s32 arg0, s32 arg1, s32 arg2);
extern void func_0043f810(void *arg0, void *arg1, u32 arg2);
extern void func_001fa490(void);
extern s32 func_001fa660(void);
extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];
extern s32 func_00452380(void *arg0);
extern s32 func_00451de0(void *data, s32 arg1, s32 arg2, s32 arg3,
                         void *init, void *close, void *buf);
extern s32 func_001fbb50(u8 *arg0);


extern void func_001f38e0(u8 **arg0);
extern s32 func_00109360(u16 arg0);
extern s32 func_001f3900(u8 **arg0);
extern void func_001f3930(void);
extern void *func_00194470();

extern void func_001f39b0(u8 **arg0);
extern void func_001f37b0(void);
extern void func_001f37d0(void);
extern void func_001f3850(void);

extern s32 func_001f39d0(u8 **arg0);
extern void func_001f3b00(void);

extern s32 func_001f8380(u8 **arg0);
extern s32 func_00106600(s32 arg0);
extern void func_00106620(s32 arg0, u32 arg1);
extern s32 func_002325a0(s32 arg0, s32 arg1);
extern s32 func_00232610(s32 arg0, s32 arg1);
extern s32 func_0023d9b0(s32 arg0, u16 arg1);

extern s32 func_001f8400(u8 **arg0);

// FUN_001F01A0
s32 func_001f01a0(u8 *arg0, u8 *arg1)
{
    u16 temp_2;

    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 2:
        return 0x104;
    case 3:
        if ((arg1 != NULL) &&
            (func_00243ce0(*(s32 *)(*(u8 **)(arg1 + 0x30) + 0xA64)) != 0)) {
            return 0x10A;
        }
        return 0x105;
    case 4:
        return 0x106;
    case 6:
        return 0x107;
    case 7:
        return 0x109;
    case 8:
        return 0x108;
    default:
        return 0;
    }
}
// FUN_001F0260
s64 func_001f0260(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0xDA:
    case 0xDB:
        return 0x40;
    case 0xDC:
    case 0xDD:
        return 0x42;
    case 0xDE:
    case 0xDF:
        return 0x44;
    case 0xE0:
        return 0x60;
    case 0xD3:
    case 0xD4:
        return 0x5A;
    case 0xD5:
    case 0xD6:
        return 0x5C;
    case 0xD7:
    case 0xD8:
        return 0x5E;
    case 0xD9:
        return 0x62;
    case 0xEA:
        return 0x4A;
    case 0xEB:
        return 0x4C;
    case 0xE3:
        return 0x64;
    case 0xE4:
        return 0x66;
    case 0x63:
    case 0x64:
        return 0x4E;
    case 0xEC:
        return 0x6A;
    case 0xED:
        return 0x6C;
    case 0xEE:
        return 0x70;
    case 0xEF:
        return 0x6E;
    case 0x103:
        return 0x72;
    case 0xE7:
        return 0x74;
    case 0xE8:
        return 0x76;
    case 0xF0:
        return 0x7A;
    case 0xF1:
        return 0x7C;
    case 0xF2:
        return 0x7E;
    case 0xF3:
        return 0x80;
    case 0xE1:
        return 0x46;
    case 0xE2:
        return 0x48;
    case 0x169:
        return 0xA5;
    case 0x17F:
        return 0xB0;
    case 0x180:
        return 0xB1;
    case 0x165:
        return 0xA3;
    case 0x16B:
        return 0xA6;
    case 0x17A:
        return 0xAE;
    case 0x178:
        return 0xA8;
    case 0x186:
        return 0xB5;
    case 0x181:
        return 0xB7;
    default:
        return 0;
    }
}



/* Parked candidate: switch dispatch, case bodies, and final shared return are instruction-close; measured object 664B/window 672B, normalized_diff 22. Committed at nd 22. */
/* Best candidate for func_001f0620: object 664B, window 672B, normalized_diff 22. */
// FUN_001F0620 NONMATCHING
#ifdef NON_MATCHING
s32 func_001f0620(u8 *arg0, s64 arg1)
{
    s32 temp_3_2;
    s64 temp_2;
    u16 temp_6;
    u8 *temp_3;
    u8 *temp_5;

    temp_6 = *(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8);
    if ((temp_6 == 0x215) && ((s16)arg1 != 2)) {
        return 0;
    }
    temp_2 = (s16)arg1;
    switch (temp_2) {
    case 1:
        return 1;
    case 2:
        return (s32)(func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 8) == 0);
    case 3:
        return func_00106330(0x1438) == 0;
    case 4:
        temp_3 = *(u8 **)(arg0 + 0x30);
        if (temp_3[0xA2] != 0) return 0;
        if (*(u16 *)(temp_3 + 0xA4) != 1) return 0;
        if ((func_001ef720(1, 0) & 0xFFFF) < 2) return 0;
        return func_00106330(0x1438) == 0;
    case 5:
        temp_5 = *(u8 **)(arg0 + 0x30);
        if (temp_5[0xA2] != 0) return 0;
        if (*(u16 *)(temp_5 + 0xA4) != 1) return 0;
        if ((*(u16 *)(arg0 + 0x18) & 0x400) == 0) return 0;
        if (func_00232710(*(s32 *)(temp_5 + 0xA64), 8) != 0) return 0;
        return func_00106330(0x1438) == 0;
    case 6:
        temp_3_2 = *(s32 *)(iGpffffb414 + ((temp_6 & 0xFFFF) * 0x18));
        if (temp_3_2 & 0x20) return 0;
        if ((temp_3_2 & 1) == 0) return 0;
        return func_001f5ea0(0) == 0;
    case 7:
    case 8:
    case 11:
    case 12:
        return 1;
    case 10:
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) return 0;
        return func_00106330(0x1438) == 0;
    case 13:
        return 1;
    default:
        return 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0620);
#endif
// FUN_001F08C0
s32 func_001f08c0(u8 *arg0)
{
    u16 temp_2;

    temp_2 = *(u16 *)(arg0 + 0xA4);
    switch (temp_2) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 0;
    case 4:
        return 0;
    case 6:
        return 0;
    case 7:
        return 1;
    case 8:
        return 1;
    default:
        return 0;
    }
}
// FUN_001F0950
s32 func_001f0950(s32 arg0, s32 arg1)
{
    if (((*(u16 *)(iGpffffb3c4 + ((arg0 & 0xFFFF) * 0x3C)) & 0x4004) == 0) &&
        (func_00106330(0x1403) != 0)) {
        if (func_00106330(0x1408) != 0) {
            return 1;
        }
        if (func_00106330(0x1409) != 0) {
            return 0;
        }
    }
    return func_0010f420(arg0, arg1);
}
// FUN_001F0A10
void func_001f0a10(u8 *arg0) {
    memset(arg0, 0, 0x20);
}



// FUN_001F0A50
s32 func_001f0a50(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    u8 *target;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if ((*(u16 *)(target + ((u16)j << 5) + 0x10E) & 4) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
#pragma opt_loop_invariants on
// FUN_001F0AF0
s32 func_001f0af0(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    s32 mask;
    u8 *target;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    mask = 0x100000;
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if ((*(s32 *)(target + ((u16)j << 5) + 0xF8) & mask) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}
/* measured: closes the invariant-hoist bracket for func_001f0af0. */
#pragma opt_loop_invariants off
// FUN_001F0B90
/* The two 0xFFFF masks are spelled differently on purpose: retail re-masks
   the counter separately for the index and for the loop bound, and writing
   both as `i & 0xFFFF` lets b210 common-subexpression them into one andi
   (nd 57, one word short). */
s32 func_001f0b90(u8 *arg0) {
    s32 i;
    s32 n;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto test;
loop:
    if (*(s32 *)(*(u8 **)(arg0 + ((u16)i * 4) + 0x38) + 0xE4) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

// FUN_001F0BF0
/* Mask spelling as in func_001f0b90: `(u16)i` for the index and
   `i & 0xFFFF` for the bound, so b210 does not fold retail's two andi
   instructions into one. */
s32 func_001f0bf0(u8 *arg0) {
    s32 i;
    s32 n;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto test;
loop:
    if ((*(u16 *)(*(u8 **)(arg0 + ((u16)i * 4) + 0x38) + 0xDE) & 6) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

// FUN_001F0C50
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0c50);
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
#pragma opt_loop_invariants on
// FUN_001F0D30
s32 func_001f0d30(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    s32 mask;
    u8 *target;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    mask = 0x80000;
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if ((*(s32 *)(target + ((u16)j << 5) + 0xFC) & mask) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}
/* measured: closes the invariant-hoist bracket for func_001f0d30. */
#pragma opt_loop_invariants off
// FUN_001F0DD0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0dd0);
// FUN_001F0F70
u32 func_001f0f70(u8 *arg0)
{
    u8 *target;
    s32 targetCount;
    s32 targetIndex;

    targetIndex = 0;
    targetCount = *(u16 *)(arg0 + 0x6A);
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = *(u8 **)(arg0 + 0x38 + (u32)(u16)targetIndex * 4);
        if (*(s32 *)(target + 0xE4) != 0) {
            return 1;
        }
        if ((*(u16 *)(target + 0xDC) & 0x500) != 0) {
            return 1;
        }
    }
    return 0;
}

/* measured: compiler residual in call argument materialization. Committed at nd 3. */
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
#pragma optimization_level 1
// FUN_001F0FF0
s32 func_001f0ff0(u32 arg0)
{
    u16 index;
    index = *(u16 *)(arg0 + 0x6E);
    return (func_001d7f10(arg0, 0, index, 0) & 0xFFFF) == 0;
}
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma optimization_level 2
// FUN_001F1030
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f1030);
// FUN_001F11E0
s32 func_001f11e0(s64 arg0) {
    u8 *base;

    base = iGpffffb3b8;
    return (s32)(base[(s16)arg0 * 0x28 + 2] == 1);
}
/* Matched with direct-index and global-address helper spellings. */
// FUN_001F1210
s32 func_001f1210(u8 *arg0, s64 arg1, s32 arg2)
{
    s32 index;

    index = (s16)arg1;
    if (*(u8 *)((u32)addOffsetFirst(
        (u32)(index * 0x28),
        (u32)addBaseFirst((u32)iGpffffb3b8, 0)) + 2) != 1) {
        return 0;
    }
    if ((arg2 == 0) ||
        ((*(u16 *)(iGpffffb3d0 + (*(u16 *)(arg0 + 0xA4) * 0x58)) & 0x10) != 0) ||
        ((*(u16 *)((u32)addOffsetFirst(
            (u32)(index * 4),
            (u32)iGpffffb3bc) + 2) & 1) == 0)) {
        return 0;
    }
    return 1;
}
// FUN_001F12B0
s8 func_001f12b0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 temp_3;
    s32 temp_4;
    s8 var_16;
    s8 var_2;
    s8 var_2_2;
    s8 var_2_3;

    var_16 = -1;
    temp_4 = *(s32 *)(arg1 + 8);
    if ((temp_4 != 0) || (*(s32 *)(arg1 + 0x10) & 0x037C12AA)) {
        var_16 = -2;
    }
    if ((temp_4 & 0x100000) != 0) {
        var_16 = 9;
    } else if ((*(s32 *)arg1 < 0) || ((temp_4 & 0x80000) != 0)) {
        if ((*(u16 *)(arg1 + 0x1E) & 8) == 0) {
            if ((func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                               0x100000) != 0) &&
                ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x8000) == 0)) {
                var_16 = 9;
            } else {
                var_16 = 2;
            }
        } else {
            var_16 = 2;
        }
    } else if ((*(s32 *)(arg1 + 0xC) & 0x100000) != 0) {
        var_16 = 0xB;
    }
    temp_3 = arg2 & 0xFFFF;
    switch (temp_3) {
    case 4:
    case 2:
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x80) != 0) {
            var_2 = 0x17;
        } else {
            var_2 = -4;
        }
        var_16 = var_2;
        break;
    default:
        break;
    }
    if ((*(u16 *)(arg1 + 0x1E) & 4) != 0) {
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x80) != 0) {
            var_2_2 = 0x17;
        } else {
            var_2_2 = -3;
        }
        var_16 = var_2_2;
    }
    if (arg4 != 0) {
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x20) != 0) {
            var_2_3 = 0x13;
        } else {
            var_2_3 = 2;
        }
        var_16 = var_2_3;
    }
    if (((*(s32 *)(arg1 + 0xC) & 0x80000) != 0) &&
        (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                       0x80000) != 0) &&
        ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x200) != 0)) {
        var_16 = 0x14;
    }
    return var_16;
}
// FUN_001F14F0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f14f0);
// FUN_001F2CC0
#ifdef NON_MATCHING
void func_001f2cc0(u8 *arg0)
{
    s32 sp3C;
    u8 *base;
    s32 temp_4_5;
    s32 temp_6;
    s32 temp_6_2;
    s32 var_7;
    s32 var_8;
    s32 var_8_2;
    u16 temp_4;
    u16 var_16;
    u8 *temp_16;

    temp_4 = *(u16 *)(arg0 + 0x1A);
    if ((temp_4 & 1) != 0) {
        temp_16 = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(temp_16 + 0xA2) == 1) {
            if (*(u16 *)(temp_16 + 0xA4) >= 0x150) {
                func_0046d730((void *)D_0060AB08, 0x4F5);
            }
            temp_4 = *(u16 *)(arg0 + 0x1A);
            if ((temp_4 & 0x20) == 0) {
                *(u16 *)(arg0 + 0x1A) = (u16)(temp_4 | 0x20);
                *(s32 *)(D_0076449C + 0xCB0) =
                    *(s32 *)(D_0076449C + 0xCB0) +
                    func_00243950(*(s32 *)(temp_16 + 0xA64));
                *(s32 *)(D_0076449C + 0xCB4) =
                    *(s32 *)(D_0076449C + 0xCB4) +
                    func_002439c0(*(s32 *)(temp_16 + 0xA64));
                var_16 = (u16)(func_00243a30(
                    *(s32 *)(temp_16 + 0xA64), &sp3C) & 0xFFFF);
                if ((sp3C != 1) &&
                    (*(u16 *)(arg0 + 0x80) != 0) &&
                    ((func_00231d70(0x64) & 0xFF) <
                     *(u8 *)(arg0 + 0x82))) {
                    var_16 = *(u16 *)(arg0 + 0x80);
                }
                temp_6 = var_16 & 0xFFFF;
                if (temp_6 != 0) {
                    base = D_0076449C;
                    var_7 = 0;
                    var_8 = 0;
                    goto loop_14_check;
loop_14_body:
                    if (*(u16 *)(base +
                                 ((var_8 & 0xFFFF) * 4) + 0xCD0) == temp_6) {
                        *(s16 *)(base +
                                 ((var_8 & 0xFFFF) * 4) + 0xCD2) =
                            (s16)(*(s16 *)(base +
                                           ((var_8 & 0xFFFF) * 4) + 0xCD2) + 1);
                        var_7 = 1;
                        goto loop_14_end;
                    }
                    var_8 = (var_8 + 1) & 0xFFFF;
loop_14_check:
                    if ((var_8 & 0xFFFF) < 3) {
                        goto loop_14_body;
                    }
loop_14_end:
                    if (var_7 == 0) {
                        var_8_2 = 0;
                        goto loop_20_check;
loop_20_body:
                        temp_4_5 = var_8_2 & 0xFFFF;
                        temp_6_2 = temp_4_5 * 4;
                        if (*(u16 *)(base + temp_6_2 + 0xCD0) == 0) {
                            *(u16 *)(base + temp_6_2 + 0xCD0) = var_16;
                            *(s16 *)(base + temp_6_2 + 0xCD2) = 1;
                            *(s32 *)(base + 0xCDC) = temp_4_5 + 1;
                            return;
                        }
                        var_8_2 = (var_8_2 + 1) & 0xFFFF;
loop_20_check:
                        if ((var_8_2 & 0xFFFF) < 3) {
                            goto loop_20_body;
                        }
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f2cc0);
#endif
// FUN_001F2EB0
void func_001f2eb0(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    func_00243e70(*(s32 *)(work + 0xA64));
    if (arg1 == 1) {
        if (*(u16 *)(arg0 + 0x3F4) != 0x154) {
            func_00231f20(*(s32 *)(work + 0xA64), 1);
        }
        func_002326f0(*(s32 *)(work + 0xA64), 0x80000);
        *(s32 *)(work + 0x9C) |= 0x10;
        return;
    }
    func_00231f20(*(s32 *)(work + 0xA64), 0);
    func_002326f0(*(s32 *)(work + 0xA64), 0xFFFFFF);
    func_00232680(*(s32 *)(work + 0xA64), 0x80000);
    value = *(s32 *)(work + 0x9C) | 1;
    *(s32 *)(work + 0x9C) = value;
    *(s32 *)(work + 0x9C) = value & ~0x10;
}
// FUN_001F2F90
s32 func_001f2f90(u8 *arg0) {
    u8 *p;

    p = iGpffffb3b8 + *(s16 *)(arg0 + 0x6E) * 40;
    if ((p[0] & 2) != 0) {
        return 0;
    }
    return (p[0x24] ^ 6) != 0;
}

// FUN_001F3870
void func_001f3870(u8 *arg0, s8 arg1)
{
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)func_00194470(0x701, 8);
    *(void **)(temp_2 + 0x68) = (void *)func_001f37b0;
    *(void **)(temp_2 + 0x6C) = (void *)func_001f37d0;
    *(void **)(temp_2 + 0x70) = (void *)func_001f3850;
    temp_3 = *(u8 **)(temp_2 + 0x78);
    *(u8 **)(temp_3 + 0) = arg0;
    *(s8 *)(temp_3 + 4) = arg1;
}

// FUN_001F38E0
void func_001f38e0(u8 **arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(*arg0 + 0x30);
    *(u16 *)(temp_4 + 0xA0) = (u16)(*(u16 *)(temp_4 + 0xA0) + 1);
}
// FUN_001F3900
s32 func_001f3900(u8 **arg0) {
    func_00235020(*(s32 *)(*(u8 **)(*arg0 + 0x30) + 0xA64));
    return 1;
}
// FUN_001F3950
u8 *func_001f3950(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x703, 4);
    *(void **)(packet + 0x68) = (void *)func_001f38e0;
    *(void **)(packet + 0x6C) = (void *)func_001f3900;
    *(void **)(packet + 0x70) = (void *)func_001f3930;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_001F39B0
void func_001f39b0(u8 **arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(*arg0 + 0x30);
    *(u16 *)(temp_4 + 0xA0) = (u16)(*(u16 *)(temp_4 + 0xA0) + 1);
}
// FUN_001F39D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f39d0);
// FUN_001F3B20
u8 *func_001f3b20(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x702, 4);
    *(void **)(packet + 0x68) = (void *)func_001f39b0;
    *(void **)(packet + 0x6C) = (void *)func_001f39d0;
    *(void **)(packet + 0x70) = (void *)func_001f3b00;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_001F3B80
s32 func_001f3b80(s32 arg0) {
    s32 temp_5;
    s32 value;

    temp_5 = *(s32 *)(*(u8 **)(iGpffffb3ac + 0xA54) + 0x110);
    value = *(s32 *)((u8 *)addOffsetFirst((u32)((arg0 & 0xFFFF) * 0xC),
                                          (u32)temp_5) + 4);
    return (s32)addBaseFirst((u32)temp_5, (u32)value);
}
// FUN_001F3BB0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f3bb0);
// FUN_001F3F60
s32 func_001f3f60(void)
{
    s32 state;

    state = *(s32 *)(iGpffffb3ac + 0xA58);
    if (state == 0xFC) {
        return -1;
    }
    if ((func_001ef720(1, 0x80000) & 0xFFFF) < 2) {
        return -1;
    }
    return 0xFC;
}

// FUN_001F3FE0
s32 func_001f3fe0(u8 *arg0)
{
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    return 0xCC;
}
// FUN_001F4010
s32 func_001f4010(u8 *arg0)
{
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    return 0x67;
}
// FUN_001F4040
s32 func_001f4040(u8 *arg0) {
    if (*(u8 *)((u8 *)(*(u8 **)(arg0 + 0x30)) + 0xA2) != 0) {
        return -1;
    }
    if (func_001f5ea0(0) != 0) {
        return 0xCD;
    }
    return 0xCE;
}

// FUN_001F40A0
s32 func_001f40a0(void) {
    s32 temp_3;

    temp_3 = func_001ef720(2, 0x80000) & 0xFFFF;
    if (temp_3 >= 5) {
        return -1;
    }
    if (temp_3 == 0) {
        return -1;
    }
    return 0x58 - temp_3;
}

// FUN_001F4100
s32 func_001f4100(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return -1;
    case 2:
        return 0x15F;
    case 3:
        return 0x160;
    case 4:
        return 0x161;
    case 6:
        return 0x162;
    case 7:
        return 0x163;
    case 8:
        return 0x164;
    default:
        return -1;
    }
}
// FUN_001F41B0
s32 func_001f41b0(u8 *arg0)
{
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    return 0xCB;
}
// FUN_001F41E0
s32 func_001f41e0(void) {
    s32 temp_3;

    temp_3 = func_001ef720(2, 0x80000) & 0xFFFF;
    if (temp_3 > 5) {
        return -1;
    }
    if (temp_3 < 2) {
        return -1;
    }
    return 0x5E - temp_3;
}



// FUN_001F42A0
s32 func_001f42a0(s32 arg0) {
    if (*(s32 *)(iGpffffb3ac + 0x170) != arg0) {
        return -1;
    }
    return 0x173;
}
// FUN_001F42D0
s32 func_001f42d0(void) {
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) != 0) {
        if (func_001ef9a0() == 0x20B) {
            return 0x18B;
        }
    }
    return 0x165;
}

// FUN_001F4330
s32 func_001f4330(u8 *arg0)
{
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return 0x99;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1) {
        return 0x5D;
    }
    return -1;
}

// FUN_001F4380
s32 func_001f4380(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x68;
    case 2:
        return 0x69;
    case 3:
        return 0x6A;
    case 4:
        return 0x6B;
    case 6:
        return 0x6C;
    case 7:
        return 0x6D;
    case 8:
        return 0x6E;
    default:
        return -1;
    }
}
// FUN_001F4430
s32 func_001f4430(u8 *arg0, s32 arg1) {
    s32 temp_4;
    u16 temp_2;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (arg1 <= 0) {
        return -1;
    }
    if (!(func_001ef720(2, 0x80000) & 0xFFFF)) {
        return -1;
    }
    temp_4 = (5 - arg1) * 7;
    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 1:
        return temp_4 + 0xFD;
    case 2:
        return temp_4 + 0xFE;
    case 3:
        return temp_4 + 0xFF;
    case 4:
        return temp_4 + 0x100;
    case 6:
        return temp_4 + 0x101;
    case 7:
        return temp_4 + 0x102;
    case 8:
        return temp_4 + 0x103;
    default:
        return -1;
    }
}



// FUN_001F4550
s32 func_001f4550(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x3D;
    case 2:
        return 0x3E;
    case 3:
        return 0x3F;
    case 4:
        return 0x40;
    case 6:
        return 0x41;
    case 7:
        return 0x42;
    case 8:
        return 0x43;
    default:
        return -1;
    }
}
// FUN_001F4600
s32 func_001f4600(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x35;
    case 2:
        return 0x36;
    case 3:
        return 0x37;
    case 4:
        return 0x38;
    case 6:
        return 0x39;
    case 7:
        return 0x3A;
    case 8:
        return 0x3B;
    default:
        return -1;
    }
}
// FUN_001F46B0
s32 func_001f46b0(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x14A;
    case 2:
        return 0x14B;
    case 3:
        return 0x14C;
    case 4:
        return 0x14D;
    case 6:
        return 0x14E;
    case 7:
        return 0x14F;
    case 8:
        return 0x150;
    default:
        return -1;
    }
}
// FUN_001F4760
s32 func_001f4760(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x143;
    case 2:
        return 0x144;
    case 3:
        return 0x145;
    case 4:
        return 0x146;
    case 6:
        return 0x147;
    case 7:
        return 0x148;
    case 8:
        return 0x149;
    default:
        return -1;
    }
}
// FUN_001F4810
s32 func_001f4810(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_4;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if ((arg2 >= 6) || (arg2 <= 0)) {
        return -1;
    }
    if (arg2 == 1) {
        if ((arg1 & 2) && (func_00231d70(0x64) < 0x1E)) {
            s32 var_2_2;
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
                var_2_2 = -1;
            } else {
                switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
                case 1:
                    var_2_2 = 0x14A;
                    break;
                case 2:
                    var_2_2 = 0x14B;
                    break;
                case 3:
                    var_2_2 = 0x14C;
                    break;
                case 4:
                    var_2_2 = 0x14D;
                    break;
                case 6:
                    var_2_2 = 0x14E;
                    break;
                case 7:
                    var_2_2 = 0x14F;
                    break;
                case 8:
                    var_2_2 = 0x150;
                    break;
                default:
                    var_2_2 = -1;
                    break;
                }
            }
            return var_2_2;
        }
        if ((arg1 & 4) && (func_00231d70(0x64) < 0x1E)) {
            s32 var_2;
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
                var_2 = -1;
            } else {
                switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
                case 1:
                    var_2 = 0x143;
                    break;
                case 2:
                    var_2 = 0x144;
                    break;
                case 3:
                    var_2 = 0x145;
                    break;
                case 4:
                    var_2 = 0x146;
                    break;
                case 6:
                    var_2 = 0x147;
                    break;
                case 7:
                    var_2 = 0x148;
                    break;
                case 8:
                    var_2 = 0x149;
                    break;
                default:
                    var_2 = -1;
                    break;
                }
            }
            return var_2;
        }
    }
    temp_4 = (5 - arg2) * 7;
    switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
    case 1:
        return temp_4 + 0x120;
    case 2:
        return temp_4 + 0x121;
    case 3:
        return temp_4 + 0x122;
    case 4:
        return temp_4 + 0x123;
    case 6:
        return temp_4 + 0x124;
    case 7:
        return temp_4 + 0x125;
    case 8:
        return temp_4 + 0x126;
    default:
        return -1;
    }
}



// FUN_001F4AD0
s32 func_001f4ad0(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x158;
    case 2:
        return 0x159;
    case 3:
        return 0x15A;
    case 4:
        return 0x15B;
    case 6:
        return 0x15C;
    case 7:
        return 0x15D;
    case 8:
        return 0x15E;
    default:
        return -1;
    }
}
// FUN_001F4B80
s32 func_001f4b80(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x4D;
    case 2:
        return 0x4E;
    case 3:
        return 0x4F;
    case 4:
        return 0x50;
    case 6:
        return 0x51;
    case 7:
        return 0x52;
    case 8:
        return 0x53;
    default:
        return -1;
    }
}
// FUN_001F4C30
s32 func_001f4c30(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x2D;
    case 2:
        return 0x2E;
    case 3:
        return 0x2F;
    case 4:
        return 0x30;
    case 6:
        return 0x31;
    case 7:
        return 0x32;
    case 8:
        return 0x33;
    default:
        return -1;
    }
}
// FUN_001F4CE0
s32 func_001f4ce0(u8 *arg0)
{
    u16 temp_2;
    u16 temp_2_2;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (temp_4[0xA2] != 0) {
        return -1;
    }
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) != 0) {
        if (func_001ef9a0() != 0x20B) {
            goto high_default_4ce0;
        }
        temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
        switch (temp_2) {
        case 2:
            return 0x18C;
        case 3:
            return 0x18D;
        case 4:
            return 0x18E;
        case 6:
            return 0x18F;
        case 7:
            return 0x190;
        case 8:
            return 0x18A;
        case 0:
        case 1:
        case 5:
        default:
            goto high_default_4ce0;
        }
    }
    goto low_switch_4ce0;
high_default_4ce0:
    return -1;
low_switch_4ce0:
    temp_2_2 = *(u16 *)(temp_4 + 0xA4);
    switch (temp_2_2) {
    case 2:
        return 0x26;
    case 3:
        return 0x27;
    case 4:
        return 0x28;
    case 6:
        return 0x29;
    case 7:
        return 0x2A;
    case 8:
        return 0x2B;
    case 0:
    case 1:
    case 5:
    default:
        return -1;
    }
}
// FUN_001F4E50
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4e50);
// FUN_001F55B0
s32 func_001f55b0(u8 *arg0)
{
    u8 *work;

    if (*(u8 **)(iGpffffb3ac + 0x170) != arg0) {
        return -1;
    }
    work = *(u8 **)(arg0 + 0x30);
    switch (*(u16 *)(arg0 + 0x6C)) {
    case 0xB:
        if (func_00232710(*(s32 *)(work + 0xA64), 0x10) != 0) {
            return 0x91;
        }
        if (func_00232710(*(s32 *)(work + 0xA64), 4) != 0) {
            return 0x93;
        }
        if (func_00232710(*(s32 *)(work + 0xA64), 2) != 0) {
            return 0x94;
        }
        break;
    default:
        break;
    }
    return -1;
}
// FUN_001F5680
/* The `return -1` and `return v + 0x11` blocks are reached by goto so they
   land in retail's order; writing both as plain returns emits them the other
   way round. */
s32 func_001f5680(void) {
    u8 *p;
    s32 v;

    p = *(u8 **)(iGpffffb3ac + 0xC68);
    if (p == NULL) {
        return -1;
    }
    v = *(u16 *)(p + 2);
    if (v < 6) {
        if (v != 0) {
            goto add;
        }
    }
    return -1;
add:
    return v + 0x11;
}
// FUN_001F56D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f56d0);
// FUN_001F58D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f58d0);
// FUN_001F5A00
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f5a00);
// FUN_001F5BD0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f5bd0);
// FUN_001F5EA0
s32 func_001f5ea0(s32 arg0) {
    return (s32)((*(u16 *)((u8 *)iGpffffb3ac + 0xA48) & (1 << (arg0 & 0xFFFF))) != 0);
}



// FUN_001F5ED0
s32 func_001f5ed0(u8 *arg0)
{
    s32 result;
    u8 *global;

    if (*(s32 *)(arg0 + 0x14) == 0) {
        *(s32 *)(arg0 + 0x14) = func_001f56d0(
            *(s32 *)(arg0 + 0),
            *(u16 *)(arg0 + 4),
            *(s32 *)(arg0 + 8),
            *(s32 *)(arg0 + 0xC),
            *(s32 *)(arg0 + 0x10));
    }
    result = *(s32 *)(arg0 + 0x14);
    if ((result == 1) && (*(s32 *)(arg0 + 0x10) & 1) != 0) {
        global = iGpffffb3ac;
        if (((*(u16 *)(global + 0xA4E) & 1) != 0) ||
            (*(u16 *)(global + 0xA50) != 0)) {
            result = 0;
        }
    }
    return result;
}
// FUN_001F6090
s32 func_001f6090(void)
{
    func_001f62b0();
    return 1;
}

// FUN_001F6100
void func_001f6100(void)
{
    func_0043f9c8(iGpffffb3ac + 0xA44, 0, 0x2C);
    *(s32 *)(iGpffffb3ac + 0xA54) = 0;
    *(s32 *)(iGpffffb3ac + 0xA58) = -1;
    *(s16 *)(iGpffffb3ac + 0xA5C) = -1;
    *(s32 *)(iGpffffb3ac + 0xA60) = -1;
    *(s16 *)(iGpffffb3ac + 0xA64) = -1;
    *(s32 *)(iGpffffb3ac + 0xA68) = -1;
    *(s16 *)(iGpffffb3ac + 0xA6C) = -1;
    *(s16 *)(iGpffffb3ac + 0xA50) = 0;
    *(s16 *)(iGpffffb3ac + 0xA4E) = 0;
    *(s16 *)(iGpffffb3ac + 0xA4C) = 8;
    *(s16 *)(iGpffffb3ac + 0xA6E) = 0;
}
// FUN_001F6190
void func_001f6190(void)
{
    func_001f58d0();
}

// FUN_001F61B0
void func_001f61b0(void)
{
    u8 *temp_3;
    u8 *var_4;

    var_4 = *(u8 **)(iGpffffb3ac + 0xA54);
    if (var_4 != NULL) {
        func_00454bd0(var_4);
        *(u8 **)(iGpffffb3ac + 0xA54) = NULL;
        temp_3 = iGpffffb3ac;
        *(s32 *)(temp_3 + 0xC) = *(s32 *)(temp_3 + 0xC) & 0xFEFFFFFF;
    }
    temp_3 = iGpffffb3ac;
    *(u16 *)(temp_3 + 0xA4E) = *(u16 *)(temp_3 + 0xA4E) & 0xFFFE;
    func_002bd3c0();
}

// FUN_001F6220
s32 func_001f6220(s16 arg0, s32 arg1)
{
    u8 *temp_3;

    temp_3 = iGpffffb3ac;
    if ((*(u16 *)(temp_3 + 0xA4E) & 1) != 0) {
        if (*(s32 *)(temp_3 + 0xA58) == arg1) {
            return 1;
        }
        if (*(s32 *)(temp_3 + 0xA60) == arg1) {
            return 1;
        }
    }
    *(s16 *)(temp_3 + 0xA64) = arg0;
    *(s32 *)(iGpffffb3ac + 0xA60) = arg1;
    *(s16 *)(iGpffffb3ac + 0xA50) = 1;
    return 1;
}

// FUN_001F6290
s32 func_001f6290(void) {
    return (s32)((*(u16 *)((u8 *)iGpffffb3ac + 0xA4E) & 1) != 0);
}



// FUN_001F62B0
void func_001f62b0(void) {
    u8 *temp_4;

    func_002bd3e0();
    func_002bd410();
    *(s16 *)(iGpffffb3ac + 0xA50) = 0;
    temp_4 = iGpffffb3ac;
    *(u16 *)(temp_4 + 0xA4E) &= 0xFFFE;
}
// FUN_001F62F0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f62f0);
// FUN_001F65D0
s32 func_001f65d0(u8 *arg0)
{
    extern void func_002bd240(u32 arg0);
    extern void func_00440b68();
    extern s32 func_00454a60();
    extern u8 iGpffffa4e8;
    extern u8 iGpffffa4e0;
    extern u8 D_0060ABE8[];
    u16 temp_3;
    u16 var_3;
    u8 *temp_4;

    temp_3 = *(u16 *)(arg0 + 6);
    switch (temp_3) {
    case 0:
        if (*(u16 *)(arg0 + 4) == 0) {
            var_3 = 8;
        } else {
            var_3 = 5;
        }
        *(u16 *)(iGpffffb3ac + 0xA4C) = var_3;
    case 1:
        func_00440b68(&iGpffffa4e8, D_0060ABE8, 0x713);
        *(s32 *)(iGpffffb3ac + 0xA54) =
            func_00454a60(
                *(u8 **)((u8 *)&iGpffffa4e0 +
                         (*(u16 *)(arg0 + 4) * 4)),
                0);
        *(u16 *)(arg0 + 6) = 2;
        goto block_14;
    case 2:
        if (func_004553c0(*(u8 **)(iGpffffb3ac + 0xA54)) != 0) {
    case 3:
            func_002bd240(
                (1 << *(u16 *)(iGpffffb3ac + 0xA4C)) | 1);
            *(u16 *)(arg0 + 6) = 4;
    case 4:
            temp_4 = iGpffffb3ac;
            *(s32 *)(temp_4 + 0xC) =
                *(s32 *)(temp_4 + 0xC) | 0x01000000;
            return 1;
        }
        goto block_14;
    block_14:
    default:
        return 0;
    }
}
// FUN_001F6710
void func_001f6710(s32 arg0) {
    u8 *p;
    u8 *q;

    p = (u8 *)func_00194470(0x803, 8);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)func_001f65d0;
    q = *(u8 **)(p + 0x78);
    *(s16 *)(q + 4) = (s16)arg0;
    *(s16 *)(q + 6) = 0;
}

// FUN_001F6770
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6770);
// FUN_001F68E0
s32 func_001f68e0(u8 *arg0)
{
    u8 *unit;
    s32 status;

    unit = *(u8 **)(arg0 + 0x30);
    status = *(s32 *)(unit + 0xA64);
    if ((*(u16 *)(arg0 + 0x18) & 4) != 0) {
        return 0;
    }
    return (func_00232710(status, 0x60) != 0);
}

/* measured: every instruction matches and the object is exactly the 80-byte
   window; the only residual is that retail materialises the shift constant
   (`addiu $v1,$zero,1`) BEFORE the branch into the loop test while b210 puts
   it after, which also shifts the back-edge displacement by one word (nd 9).
   Measured identical at nd 9: an inline `1 << i`, a hoisted `one` local, and
   an explicit goto loop with the test at the bottom. Preheader hoist-order
   floor. Committed at nd 9. */

// FUN_001F6930
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6930);
// FUN_001F6BF0
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
#pragma opt_loop_invariants on
s32 func_001f6bf0(u8 *arg0) {
    s32 i;
    s32 one;

    i = 0;
    one = 1;
    while ((u32)i < 0x18) {
        if ((one << i) == one) {
            return arg0[i + 0x3F6] >= 2;
        }
        i++;
    }
    return 1;
}
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
#pragma opt_loop_invariants off

// measured: required for exact retail loop codegen in func_001f7260.
#pragma opt_loop_invariants on

// FUN_001F6C40
void func_001f6c40(u8 *arg0, s32 arg1)
{
    s32 temp_2;
    s32 temp_4;
    u32 var_6;

    if (arg1 != 0) {
        temp_2 = func_002326e0(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64));
        var_6 = 0;
        goto loop_test_6;
loop_6:
        temp_4 = 1 << var_6;
        if ((arg1 & temp_4) && !(temp_2 & temp_4)) {
            *(s8 *)(arg0 + var_6 + 0x3F6) = 0;
        }
        var_6 += 1;
loop_test_6:
        if (var_6 < 0x18U) {
            goto loop_6;
        }
    }
}
// FUN_001F6CD0
void func_001f6cd0(u8 *arg0)
{
    s32 temp_2;
    u32 var_6;
    u8 temp_3_2;
    u8 *temp_3;
    u8 *temp_4;

    temp_2 = func_002326e0(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64));
    var_6 = 0;
    goto loop_test_5;
loop_5:
    if ((temp_2 & (1 << var_6)) != 0) {
        temp_3 = arg0 + var_6;
        temp_4 = temp_3 + 0x3F6;
        temp_3_2 = *(u8 *)(temp_3 + 0x3F6);
        if ((s32)temp_3_2 < 0xFF) {
            *temp_4 = (u8)(temp_3_2 + 1);
        }
    }
    var_6 += 1;
loop_test_5:
    if (var_6 < 0x18U) {
        goto loop_5;
    }
}

// FUN_001F6D60
s16 func_001f6d60(u8 *arg0)
{
    u8 *temp_17;
    s16 var_16;
    s32 temp_16;
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_2;
    u16 temp_3;

    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
    var_16 = 0;
    temp_2 = func_002326c0(temp_17);
    switch (temp_2) {
    case 0x20:
        temp_4 = func_00231f80(temp_17) & 0xFFFF;
        if ((*(u16 *)temp_17 & 4) == 0) {
            var_16 = -((temp_4 & 0xFFFF) * 0x64) / 1000;
        } else {
            temp_3 = *(u16 *)(iGpffffb3c4 +
                              (*(u16 *)(temp_17 + 2) * 0x3C));
            if ((temp_3 & 0x400) != 0) {
                var_16 = -0x32;
            } else if ((temp_3 & 0x800) != 0) {
                var_16 = -0x64;
            } else {
                var_16 = -((temp_4 & 0xFFFF) * 0x64) / 1000;
            }
            if (var_16 > 0x3E7) {
                var_16 = 0x3E7;
            }
            }
        if (func_002428f0(temp_17, var_16) != 0) {
            var_16 = -((func_00231ed0(temp_17) & 0xFFFF) - 1);
        }
        break;
    case 0x40:
        temp_16 = func_00232290(temp_17) & 0xFFFF;
        temp_4_2 = func_00231ee0(temp_17) & 0xFFFF;
        var_16 = -((temp_16 & 0xFFFF) * 0x64) / 1000;
        if (temp_4_2 < var_16) {
            var_16 = temp_4_2;
        }
        break;
    default:
        break;
    }
    return var_16;
}

/* measured: opt_rebuildconditionals off probe for func_001f6f60 final branch. */
#pragma opt_rebuildconditionals off
// FUN_001F6F60
s32 func_001f6f60(u8 *arg0)
{
    u8 *temp_16;
    s32 var_17;
    s32 temp_18;
    s32 temp_2;
    u16 temp_3;
    u16 temp_3_2;

    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return -1;
    }
    temp_16 = *(u8 **)(arg0 + 0x30);
    var_17 = -1;
    temp_2 = func_002326c0(*(u8 **)(temp_16 + 0xA64));
    switch (temp_2) {
    case 2:
        if ((*(u8 *)(arg0 + 0x28) == 0) &&
            (*(u8 *)(arg0 + 0x29) == 0)) {
            var_17 = 0xC;
        }
        break;
    case 4:
        temp_3 = *(u16 *)(arg0 + 0x6C);
        switch (temp_3) {
        case 6:
        case 12:
            var_17 = 8;
            break;
        case 7:
        case 8:
        case 11:
            var_17 = 0xA;
            break;
        default:
            break;
        }
        break;
    case 8:
        break;
    case 0x10:
        switch (*(u16 *)(arg0 + 0x6C)) {
        case 1:
            var_17 = 4;
            break;
        default:
            var_17 = 6;
            break;
        }
        break;
    case 0x100:
        temp_3_2 = *(u16 *)(arg0 + 0x6C);
        switch (temp_3_2) {
        case 2:
        case 1:
            var_17 = 0xAA;
            break;
        case 7:
        case 8:
        case 11:
            var_17 = 0xAB;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    if (var_17 < 0) {
        return -1;
    }
    {
        if (*(u8 *)(temp_16 + 0xA2) != 0)
            goto increment_6f60;
        temp_18 = var_17;
        goto done_6f60;
    increment_6f60:
        temp_18 = var_17 + 1;
    done_6f60:
        ;
    }
    var_17 = temp_18;
    return var_17;
}
/* measured: close opt_rebuildconditionals after func_001f6f60 probe. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off preserves func_001f7140's positive flag branch. */
#pragma opt_rebuildconditionals off
// FUN_001F7140
s32 func_001f7140(u8 *arg0)
{
    u8 *temp_16;
    s32 var_17;
    s32 temp_18;
    s32 temp_2;

    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return -1;
    }
    temp_16 = *(u8 **)(arg0 + 0x30);
    var_17 = -1;
    temp_2 = func_002326c0(*(u8 **)(temp_16 + 0xA64));
    switch (temp_2) {
    case 2:
        var_17 = 0x2E;
        break;
    case 4:
        var_17 = 0x2C;
        break;
    case 8:
        var_17 = 0x34;
        break;
    case 0x10:
        var_17 = 0x2A;
        break;
    case 0x40:
        var_17 = 0x30;
        break;
    case 0x80:
        var_17 = 0x32;
        break;
    default:
        break;
    }
    if (var_17 < 0) {
        return -1;
    }
    {
        if (*(u8 *)(temp_16 + 0xA2) != 0)
            goto increment_7140;
        temp_18 = var_17;
        goto done_7140;
    increment_7140:
        temp_18 = var_17 + 1;
    done_7140:
        ;
    }
    var_17 = temp_18;
    return var_17;
}
/* measured: close opt_rebuildconditionals after func_001f7140. */
#pragma opt_rebuildconditionals on
// FUN_001F7260
void func_001f7260(void)
{
    s32 offset;
    s32 empty;
    u16 i;
    u8 state;

    *(s16 *)(iGpffffb3ac + 0xAC8) = 5;
    empty = -1;
    *(s8 *)(iGpffffb3ac + 0xACA) = empty;
    i = 0;
    state = 3;
    for (; i < 0x10; i++) {
        offset = (u32)i * 6;
        *(s16 *)(iGpffffb3ac + offset + 0xACC) = empty;
        *(s16 *)(iGpffffb3ac + offset + 0xACE) = empty;
        *(s8 *)(iGpffffb3ac + offset + 0xAD0) = state;
    }
}
// measured: required for exact retail loop codegen in func_001f7260.
/* measured: optimization_level 1 required for exact func_001f72e0 codegen. */
#pragma optimization_level 1
/* measured: opt_loop_invariants off baseline for func_001f72e0. */
#pragma opt_loop_invariants off
// FUN_001F72E0
void func_001f72e0(void)
{
    s32 var_8;
    u8 *temp_3_4;
    u8 *temp_3_8;
    s32 temp_6;
    s32 index_8;
    s32 empty;
    s32 temp_3_5;

    {
        u8 *temp_3;
        u8 *temp_3_7;
        s32 temp_3_2;

        temp_3 = iGpffffb3ac;
        temp_3_7 = temp_3 + 0xACA;
        temp_3_2 = *(s8 *)temp_3_7;
        if (temp_3_2 >= 0) {
            temp_3_2 = temp_3_2 + 1;
            *(s8 *)temp_3_7 = (s8)temp_3_2;
            if ((s8)temp_3_2 >= 3) {
                *(s8 *)(iGpffffb3ac + 0xACA) = -1;
            }
        }
    }
    var_8 = 0;
    empty = -1;
    goto loop_test_8;
loop_8:
    temp_3_4 = iGpffffb3ac;
    index_8 = var_8 & 0xFFFF;
    temp_6 = index_8 * 6;
    temp_3_8 = temp_3_4 + temp_6;
    index_8 = (s32)(temp_3_8 + 0xAD0);
    temp_3_5 = *(s8 *)(temp_3_8 + 0xAD0);
    if (temp_3_5 >= 0) {
        temp_3_5 = temp_3_5 + 1;
        *(s8 *)index_8 = (s8)temp_3_5;
        if ((s8)temp_3_5 >= 3) {
            *(s16 *)(iGpffffb3ac + temp_6 + 0xACC) = empty;
            *(s16 *)(iGpffffb3ac + temp_6 + 0xACE) = empty;
            *(s8 *)(iGpffffb3ac + temp_6 + 0xAD0) = empty;
        }
    }
    var_8 = (var_8 + 1) & 0xFFFF;
loop_test_8:
    if ((var_8 & 0xFFFF) < 0x10) {
        goto loop_8;
    }
}
/* measured: restore optimization_level 2 after func_001f72e0. */
#pragma optimization_level 2
// FUN_001F73C0
void func_001f73c0(void)
{
}

// FUN_001F73D0
void func_001f73d0(void)
{
    u16 temp_2;
    u8 *temp_4;

    temp_4 = iGpffffb3ac;
    if (*(s32 *)(temp_4 + 0xC) & 0x40) {
        temp_2 = *(u16 *)(*(u8 **)(temp_4 + 0xC68) + 8);
        temp_2 = *(u16 *)(iGpffffb414 + (temp_2 * 0x18) + 0x16);
        switch (temp_2) {
        case 2:
            func_0045a3e0(2, 1);
            break;
        case 3:
            func_0045a3e0(3, 1);
            break;
        case 4:
            func_0045a3e0(4, 1);
            break;
        case 5:
            func_0045a3e0(5, 1);
            break;
        case 6:
            func_0045a3e0(6, 1);
            break;
        case 7:
            func_0045a3e0(0x29, 1);
            break;
        case 8:
            func_0045a3e0(0x30, 1);
            break;
        case 9:
            func_0045a3e0(0x2F, 1);
            break;
        case 10:
            func_0045a3e0(0x2D, 1);
            break;
        default:
            func_0045a3e0(1, 1);
            break;
        }
    }
}
// FUN_001F75B0
void func_001f75b0(void)
{
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x40) != 0) {
        func_0045a9a0(1, 0);
        func_0045a9a0(2, 0);
        func_0045a9a0(3, 0);
        func_00459880();
    }
}

// FUN_001F7650
u8 *func_001f7650(u8 *arg0)
{
    u8 *var_2;
    u32 temp_3;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        if (func_00110d60((s16)func_001060b0()) & 1) {
            var_2 = D_0060AC00 + (*(u16 *)(arg0 + 0xA4) * 0xA20);
        } else {
            var_2 = D_0060AC00 + (*(u16 *)(arg0 + 0xA4) * 0xA20) + 0x6F60;
        }
        return var_2;
    }
    temp_3 = *(u16 *)(arg0 + 0xA4);
    if ((s32)temp_3 < 0x100) {
        return NULL;
    }
    if ((s32)temp_3 <= 0x112) {
        goto dispatch;
    }
    return NULL;
dispatch:
    if (temp_3 == 0x214) {
        goto return_214;
    } else if (temp_3 == 0x112) {
        goto return_group;
    } else if (temp_3 == 0x10E) {
        goto return_group;
    } else if (temp_3 == 0x10B) {
        goto return_group;
    } else if (temp_3 == 0x10A) {
        goto return_group;
    } else if (temp_3 == 0x109) {
        goto return_group;
    } else if (temp_3 == 0x108) {
        goto return_group;
    } else if (temp_3 == 0x107) {
        goto return_group;
    } else if (temp_3 == 0x106) {
        goto return_group;
    } else if (temp_3 == 0x105) {
        goto return_group;
    } else if (temp_3 == 0x104) {
        goto return_group;
    } else if (temp_3 == 0x103) {
        goto return_group;
    } else if (temp_3 == 0x102) {
        goto return_group;
    } else if (temp_3 == 0x101) {
        goto return_group;
    } else {
        switch (temp_3) {
        case 0x100:
            goto return_group;
        default:
            goto return_null;
        }
    }
return_group:
    return D_00618AC0 + ((temp_3 - 0x100) * 0xA20);
return_214:
    return D_0061F000;
return_null:
    var_2 = NULL;
    return var_2;
}
// FUN_001F7830
void func_001f7830(u8 *arg0, s32 arg1, s32 arg2, s16 *arg3, s16 *arg4)
{
    s32 temp_5;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        temp_5 = (s32)func_0023e270(*(u8 **)(arg0 + 0xA64)) & 0xFFFF;
        switch (*(u16 *)(arg0 + 0xA4)) {
        case 7:
            if (arg2 != 0) {
                if (arg1 == 3) {
                    *arg3 = -1;
                    *arg4 = -1;
                    goto done;
                }
            }
        default:
            *arg3 = 0;
            *arg4 = *(s16 *)(D_00624B20 + (temp_5 * 4));
            goto done;
        }
    }
    *arg3 = -1;
    *arg4 = -1;
done:
    ;
}
// FUN_001F7910
void func_001f7910(u8 *arg0, u32 arg1, s32 arg2, s16 *arg3, s16 *arg4)
{
    s32 temp_5;
    u16 temp_4;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        temp_5 = (s32)func_0023e270(*(u8 **)(arg0 + 0xA64)) & 0xFFFF;
        *arg3 = 0;
        temp_4 = *(u16 *)(arg0 + 0xA4);
        switch (temp_4) {
        case 4:
            if ((arg2 != 0) && (arg1 < 2U)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        case 6:
            if ((arg2 != 0) && ((u32)(arg1 - 1) < 2U)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        case 7:
            if ((arg2 != 0) && (arg1 == 3)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        default:
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        }
    }
    *arg3 = 0;
    switch (*(u16 *)(arg0 + 0xA4)) {
    case 0x109:
        *arg4 = 8;
        break;
    default:
        *arg4 = 0;
        break;
    }
}
// FUN_001F7AD0
void func_001f7ad0(u8 *arg0)
{
    u16 temp_7;
    u8 *temp_6;
    u32 offset;

    temp_7 = *(u16 *)arg0;
    offset = temp_7 * 6;
    temp_6 = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((*(s16 *)(temp_6 + 0xACC) != *(u16 *)(arg0 + 2)) ||
        (*(s16 *)(temp_6 + 0xACE) != *(u16 *)(arg0 + 4))) {
        func_0045aa90(1, (s16)temp_7, temp_6, temp_7);
    }
}
// FUN_001F7B40
s32 func_001f7b40(u8 *arg0)
{
    u16 temp_4;
    u16 temp_6;
    u8 *temp_3;
    u32 offset;

    temp_6 = *(u16 *)(arg0 + 2);
    temp_4 = *(u16 *)arg0;
    offset = temp_4 * 6;
    temp_3 = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((*(s16 *)(temp_3 + 0xACC) != temp_6) ||
        (*(s16 *)(temp_3 + 0xACE) != *(u16 *)(arg0 + 4))) {
        func_0045af60(1, (s16)temp_4, (s16)temp_6,
                      (s16)*(u16 *)(arg0 + 4));
        temp_6 = *(u16 *)(arg0 + 2);
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u16 *)((u8 *)offset + 0xACC) = temp_6;
        temp_6 = *(u16 *)(arg0 + 4);
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u16 *)((u8 *)offset + 0xACE) = temp_6;
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u8 *)((u8 *)offset + 0xAD0) = 0;
    }
    return 1;
}
// FUN_001F8380
s32 func_001f8380(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) |= 0x40;
    }
    return 1;
}
// FUN_001F83B0
void func_001f83b0(u32 value)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x90B, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8380;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
}

// FUN_001F8400
s32 func_001f8400(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) &= 0xFFBF;
    }
    return 1;
}
// FUN_001F8430
void func_001f8430(u32 value)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x90C, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8400;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
}

// FUN_001F8480
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8480);
// FUN_001F8690
void func_001f8690(s32 arg0) {
    s32 value;
    u16 index;

    value = *(u16 *)(iGpffffb3ac + 0xB30);
    index = (u16)arg0;
    func_0045ae10(value, 3, index);
}
// FUN_001F86D0
void func_001f86d0(void) {
    func_0045aac0(3, 0, 8);
}
// FUN_001F8700
s32 func_001f8700(u8 *arg0, s32 arg1)
{
    s32 temp_2;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(s32 *)(temp_4 + 0xA0C) == 0)
    {
        return -1;
    }
    if (*(u8 *)(temp_4 + 0xA2) == 1)
    {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0)
    {
        return arg1 - 1;
    }
    temp_2 = func_00109360(*(u16 *)(temp_4 + 0xA4)) & 0xFFFF;
    switch (temp_2)
    {
    case 0xC0:
    case 0xC2:
    case 0xC4:
    case 0xC6:
    case 0xC8:
    case 0xCA:
    case 0xCC:
        return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x22;
    case 0xC1:
    case 0xC3:
    case 0xC5:
    case 0xC7:
    case 0xC9:
    case 0xCB:
    case 0xCD:
        return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x23;
    default:
        return -1;
    }
}
// FUN_001F8810
s32 func_001f8810(u8 *arg0, s32 arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) == 1)
    {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0)
    {
        return -1;
    }
    if (arg1 >= 5)
    {
        return -1;
    }
    if (func_002428f0((u8 *)*(s32 *)(temp_4 + 0xA64), 0) != 0)
    {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x1001D7) != 0)
    {
        return -1;
    }
    return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] +
           (s32)D_00624FD8[arg1];
}
// FUN_001F8920
s32 func_001f8920(u8 *arg0)
{
    extern s32 func_0022bd20(void);
    s32 temp_16;
    s32 var_2;
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) == 0) {
        if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
            var_2 = -1;
        } else {
            temp_16 = (s32)D_00624FC0[*(u16 *)(temp_3 + 0xA4)] + 7;
            var_2 = temp_16 + func_00231d70(3);
        }
        return var_2;
    }
    if (func_0022bd20() == 0) {
        return -1;
    }
    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 0x100:
        return func_00231d70(3) + 0x417;
    case 0x101:
        return func_00231d70(3) + 0x429;
    case 0x102:
        return func_00231d70(3) + 0x43C;
    case 0x103:
        return func_00231d70(3) + 0x44F;
    case 0x104:
        return func_00231d70(3) + 0x462;
    case 0x105:
        return func_00231d70(3) + 0x475;
    case 0x106:
        return func_00231d70(3) + 0x488;
    case 0x107:
        return func_00231d70(3) + 0x49B;
    case 0x108:
        return func_00231d70(3) + 0x4AE;
    case 0x109:
        return func_00231d70(3) + 0x4C3;
    case 0x112:
        return func_00231d70(3) + 0x4FC;
    case 0x10A:
    case 0x10B:
    case 0x10C:
    case 0x10D:
    case 0x10E:
    case 0x10F:
    case 0x110:
    case 0x111:
    default:
        return -1;
    }
}
// FUN_001F8B00
s32 func_001f8b00(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x78;
    return value + func_00231d70(5);
}
// FUN_001F8B90
s32 func_001f8b90(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x63;
    return value + func_00231d70(3);
}
// FUN_001F8C20
s32 func_001f8c20(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (arg1 != 0) {
        value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x6F;
        return value + func_00231d70(3);
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x72;
    return value + func_00231d70(3);
}
// FUN_001F8CE0
s32 func_001f8ce0(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x75;
    return value + func_00231d70(3);
}
// FUN_001F8D70
s32 func_001f8d70(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (arg1 != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x2C;
    return value + func_00231d70(3);
}
// FUN_001F8E10
s32 func_001f8e10(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x29;
    return value + func_00231d70(3);
}
/* measured: opt_propagation off preserves func_001f8ea0's loop constants. */
#pragma opt_propagation off
// FUN_001F8EA0
s32 func_001f8ea0(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x10;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
done:
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}
/* measured: close opt_propagation after func_001f8ea0 probe. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves func_001f8f40's loop constants. */
#pragma opt_propagation off
// FUN_001F8F40
s32 func_001f8f40(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x16;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}
/* measured: close opt_propagation after func_001f8f40 probe. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves func_001f8fe0's loop constants. */
#pragma opt_propagation off
// FUN_001F8FE0
s32 func_001f8fe0(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x1C;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}
/* measured: close opt_propagation after func_001f8fe0 probe. */
#pragma opt_propagation on
// FUN_001F9080
s32 func_001f9080(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(arg0 + 0x30);
    if (p[0xA2] != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    return D_00624FC0[*(u16 *)(p + 0xA4)] + 0x45;
}

// FUN_001F90E0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f90e0);
// FUN_001F92C0
s32 func_001f92c0(u8 *arg0)
{
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x51;
    return value + func_00231d70(3);
}
// FUN_001F93A0
s32 func_001f93a0(u8 *arg0)
{
    s32 type;
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    type = func_001ef720(2, 0x80000) & 0xFFFF;
    switch (type) {
    case 4:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x54;
        return value + func_00231d70(3);
    case 3:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x57;
        return value + func_00231d70(3);
    case 2:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x5A;
        return value + func_00231d70(3);
    case 1:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x5D;
        return value + func_00231d70(3);
    }
    return -1;
}
// FUN_001F9570
s32 func_001f9570(u8 *arg0)
{
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x69;
    return value + func_00231d70(3);
}
// FUN_001F9650
s32 func_001f9650(u8 *arg0)
{
    s32 value;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x66;
    return value + func_00231d70(3);
}
// FUN_001F9740
s32 func_001f9740(void)
{
    return -1;
}

// FUN_001F9750
s32 func_001f9750(s32 *arg0) {
    s32 r;

    if (arg0[1] == 0) {
        if (iGpffffb460 != 0) {
            arg0[0] = 0;
        }
        arg0[1] = 1;
    }
    if (arg0[0] == 0) {
        *(u16 *)(D_0076449C + 0xB2E) |= 1;
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

// FUN_001F9800
s32 func_001f9800(u8 *arg0)
{
    s32 temp_2;
    u8 *temp_16;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;

    if ((*(u16 *)(iGpffffb3ac + 0xB2E) & 1) == 0) {
        return 1;
    }
    temp_16 = *(u8 **)arg0;
    if (*(s32 *)(arg0 + 0x14) == 0) {
        if ((temp_16 != NULL) &&
            ((*(u16 *)(temp_16 + 0x1A) & 1) == 0)) {
            return 1;
        }
        temp_2 = D_00624FF0[*(u16 *)(arg0 + 4)](
            temp_16, *(s32 *)(arg0 + 8), *(s32 *)(arg0 + 0xC));
        if (temp_2 == -1) {
            return 1;
        }
        func_0045ae10(*(u16 *)(iGpffffb3ac + 0xB30), 3, (u16)temp_2);
        *(s32 *)(arg0 + 0x14) = 1;
        goto block_15_9800;
    }
    if (func_0045af90(3) != 1) {
        if ((*(u16 *)(arg0 + 0x10) & 1) == 0 && (temp_16 != NULL)) {
            temp_3 = *(u8 **)(temp_16 + 0x30);
            if ((*(s32 *)(temp_3 + 0x98) & 2) != 0) {
                *(u16 *)(temp_3 + 0x9D8) &= 0xFFEF;
                temp_3_2 = *(u8 **)(*(u8 **)(temp_16 + 0x30) + 0xA00);
                *(u16 *)(temp_3_2 + 0x2E0) |= 0x20;
            }
        }
        return 1;
    }
block_15_9800:
    if ((*(u16 *)(arg0 + 0x10) & 1) == 0 &&
        *(s32 *)(arg0 + 0x14) == 1 && (temp_16 != NULL)) {
        temp_3_3 = *(u8 **)(temp_16 + 0x30);
        if ((*(s32 *)(temp_3_3 + 0x98) & 2) != 0) {
            *(u16 *)(temp_3_3 + 0x9D8) |= 0x10;
            temp_3_4 = *(u8 **)(*(u8 **)(temp_16 + 0x30) + 0xA00);
            *(u16 *)(temp_3_4 + 0x2E0) &= 0xFFDF;
        }
    }
    return 0;
}
// FUN_001F9A50
void func_001f9a50(s32 arg0, s32 arg1) {
    s32 f = *(u16 *)((u8 *)iGpffffb3ac + 0xB3A);
    func_0045ae10((u16)f, (u16)arg1, (u16)arg0);
}

// FUN_001F9A90
void func_001f9a90(void) {
    func_0045aac0(1, 0, 8);
}
/* measured: opt_propagation off preserves 9ac0's explicit boolean branch. */
#pragma opt_propagation off
// FUN_001F9AC0
s32 func_001f9ac0(u8 *arg0)
{
    s32 value;
    s32 code;
    s32 flag;

    if (*(s32 *)(arg0 + 4) == 0) {
        if (*(u16 *)(arg0 + 8) == 0) {
            value = 0x6C;
        } else {
            value = 0x69;
        }
        code = value & 0xFFFF;
        switch (code) {
        case 0x6C:
            *(s16 *)(iGpffffb3ac + 0xB3A) = 5;
            break;
        case 0x69:
            *(s16 *)(iGpffffb3ac + 0xB3A) = 4;
            break;
        default:
            break;
        }
        *(s32 *)(arg0 + 0) = 0;
        *(s32 *)(arg0 + 4) = 1;
    }
    if (*(s32 *)(arg0 + 0) == 0) {
        goto return_one_a;
    }
    flag = (*(u16 *)(iGpffffb3ac + 0xB38) & 1) != 0;
    if (flag == 0) {
        goto return_zero;
    }
return_one_b:
    return 1;
return_one_a:
    return 1;
return_zero:
    return 0;
}
/* measured: close opt_propagation after func_001f9ac0 probe. */
#pragma opt_propagation on
// FUN_001F9BE0
void func_001f9be0(void)
{
}
// FUN_001F9BF0
void func_001f9bf0(void) {
    func_0043f9c8(iGpffffb3ac + 0xB2C, 0, 0x14);
    *(s16 *)(iGpffffb3ac + 0xB30) = 3;
    *(s16 *)(iGpffffb3ac + 0xB3A) = 0;
}
// FUN_001F9C40
void func_001f9c40(void)
{
    if (*(s32 *)(iGpffffb3ac + 0xB34) != 0) {
        jtbl_008873EC[0](*(void **)(iGpffffb3ac + 0xB34));
        *(s32 *)(iGpffffb3ac + 0xB34) = 0;
        *(u16 *)(iGpffffb3ac + 0xB2E) &= 0xFFFE;
    }
    if (*(s32 *)(iGpffffb3ac + 0xB3C) != 0) {
        jtbl_008873EC[0](*(void **)(iGpffffb3ac + 0xB3C));
        *(s32 *)(iGpffffb3ac + 0xB3C) = 0;
        *(u16 *)(iGpffffb3ac + 0xB38) &= 0xFFFE;
    }
}
// FUN_001F9CD0
void func_001f9cd0(void)
{
}
// FUN_001F9CE0
s32 func_001f9ce0(void)
{
    return 0;
}
// FUN_001FA660
s32 func_001fa660(void)
{
    s32 flags;
    u8 *base;
    u8 *work;
    u8 *flag_ptr;

    base = iGpffffb3ac;
    if (*(u16 *)(base + 0xB7C) == 5) {
        return func_00120ee0(*(s32 *)(base + 0xB88));
    }
    if (func_004553c0(*(u8 **)(base + 0xB84)) != 0) {
        base = iGpffffb3ac;
        flag_ptr = base + 0xB4C;
        flags = *(s32 *)flag_ptr;
        if ((flags & 2) == 0) {
            work = *(u8 **)(base + 0xB84);
            *(s32 *)(iGpffffb3ac + 0xB80) =
                func_00484bb0(*(s32 *)(work + 0x110), base);
        } else {
            *(s32 *)flag_ptr = flags & ~2;
        }
        func_00454bd0(*(u8 **)(iGpffffb3ac + 0xB84));
        *(u8 **)(iGpffffb3ac + 0xB84) = NULL;
        return 1;
    }
    return 0;
}
// FUN_001FA720
u8 *func_001fa720(s32 arg0) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0xC04, 0xA);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x68) = (void *)func_001fa490;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa660;
    func_0043f810(*(s32 **)(temp_2 + 0x78), (void *)arg0, 0xA);
    return temp_2;
}
// FUN_001FA7A0
s32 func_001fa7a0(s32 *arg0)
{
    extern void func_00120f00(s32 arg0);
    extern s32 func_004b1520(s32 arg0);
    extern s32 func_00481450(void);
    extern void func_00481440(void *arg0);
    extern void func_00485630(s32 arg0);
    extern void func_00485870(s32 arg0);
    extern void func_00485b20(s32 arg0);
    extern u8 D_005DC8CC[];
    void *temp_17;
    s32 temp_4_2;
    s32 temp_4_3;
    u8 *temp_4;

    temp_4 = iGpffffb3ac;
    if (*(u16 *)(temp_4 + 0xB7C) == 5) {
        temp_4_2 = *(s32 *)(temp_4 + 0xB88);
        if (temp_4_2 == 0) {
            return 1;
        }
        if (*arg0 == 0) {
            func_00120f00(temp_4_2);
        }
        goto block_12;
    }
    temp_4_3 = *(s32 *)(temp_4 + 0xB80);
    if (temp_4_3 == 0) {
        return 1;
    }
    if (func_004b1520(temp_4_3) == 0) {
        if (*arg0 == 0) {
            func_0045af60(1, 0xE, 2, 0x10);
        }
        temp_17 = (void *)func_00481450();
        func_00481440(&D_005DC8CC);
        func_00485630(*(s32 *)(iGpffffb3ac + 0xB80));
        func_00485870(*(s32 *)(iGpffffb3ac + 0xB80));
        func_00481440(temp_17);
        *arg0 += 1;
        goto block_12;
    }
    func_00485b20(*(s32 *)(iGpffffb3ac + 0xB80));
    *(s32 *)(iGpffffb3ac + 0xB80) = 0;
    return 1;
block_12:
        return 0;
}
// FUN_001FA8F0
void func_001fa8f0(void) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0xC05, 4);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa7a0;
    *(s32 **)(*(u8 **)(temp_2 + 0x78)) = NULL;
}
// FUN_001FA940
s32 func_001fa940(void) {
    s32 temp_4;
    s32 temp_4_2;
    u8 *temp_3;

    temp_3 = D_0076449C;
    if (*(s32 *)(temp_3 + 0xB84) != 0) {
        *(s32 *)(temp_3 + 0xB4C) |= 2;
    } else {
        temp_4 = *(s32 *)(temp_3 + 0xB80);
        if (temp_4 != 0) {
            func_00485b20(temp_4);
            *(s32 *)(D_0076449C + 0xB80) = 0;
        }
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        func_00120f20(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}
// FUN_001FA9C0
void func_001fa9c0(void) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0xC06, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa940;
}
// FUN_001FAA00
s32 func_001faa00(void) {
    s32 temp_4;
    s32 temp_4_2;

    temp_4 = *(s32 *)(D_0076449C + 0xB80);
    if (temp_4 != 0) {
        func_00486180(temp_4);
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        func_00120f20(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}
// FUN_001FAA60
void func_001faa60(void) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0xC07, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001faa00;
}
// FUN_001FAAA0
s32 func_001faaa0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 0);
    }
    return 0;
}
// FUN_001FAAF0
s32 func_001faaf0(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(0);
    }
    return 0;
}
// FUN_001FAB40
s32 func_001fab40(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 1);
    }
    return 0;
}
// FUN_001FAB90
s32 func_001fab90(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(1);
    }
    return 0;
}
// FUN_001FABE0
s32 func_001fabe0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 2);
    }
    return 0;
}
// FUN_001FAC30
s32 func_001fac30(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(2);
    }
    return 0;
}
// FUN_001FAC80
s32 func_001fac80(u8 *arg0)
{
    u8 *base;

    base = iGpffffb3ac;
    if ((*(s32 *)(base + 0xC) & 0x200000) == 0) {
        goto return_zero;
    }
    if (func_0022bd00() == 0) {
        base = iGpffffb3ac;
        if (*(s32 *)(base + 0xB40) != 0) {
            ((void (*)(void *))(*(void **)(base + 0xB40)))(
                *(void **)(base + 0xB48));
            return 1;
        }
    }
    return func_0022bad0(arg0, 3);
return_zero:
    return 0;
}
// FUN_001FAD10
s32 func_001fad10(void)
{
    s32 (*callback)(s32);
    s32 result;
    u8 *base;

    result = 0;
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        if (func_0022bd00() == 0) {
            base = iGpffffb3ac;
            callback = *(s32 (**)(s32))(base + 0xB44);
            if (callback != NULL) {
                result = callback(*(s32 *)(base + 0xB48));
                if (result == 0) {
                    *(s32 *)(iGpffffb3ac + 0xB40) = 0;
                    *(s32 *)(iGpffffb3ac + 0xB44) = 0;
                    *(s32 *)(iGpffffb3ac + 0xB48) = 0;
                }
            }
        }
        if (result == 0) {
            result = func_0022bc80(3);
        }
    }
    return result;
}
// FUN_001FADC0
s32 func_001fadc0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bad0(arg0, 4);
    }
    return 0;
}
// FUN_001FAE10
s32 func_001fae10(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return func_0022bc80(4);
    }
    return 0;
}
// FUN_001FAE60
void func_001fae60(s32 arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(D_0076449C + 0xB40) = arg0;
    *(s32 *)(D_0076449C + 0xB44) = arg1;
    *(s32 *)(D_0076449C + 0xB48) = arg2;
}
// FUN_001FAE80
s32 func_001fae80(u8 *arg0, s32 arg1)
{
    extern void func_001d7c60(u8 *arg0, u8 *arg1, u8 arg2, u8 arg3,
                              u32 arg4);
    u8 sp30[0x38];
    s32 temp_16;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_16 = arg1 * 0x28;
    temp_3 = (u8 *)((u32)iGpffffb3b8 + temp_16);
    if ((*(u8 *)temp_3 & 8) == 0) {
        return 0;
    }
    func_001d7c60(arg0, sp30,
                   *(u8 *)(temp_3 + 9),
                   *(u8 *)(temp_3 + 0xA),
                   *(u16 *)(temp_3 + 0xC));
    if (*(u16 *)(sp30 + 0x38) == 0) {
        return 2;
    }
    switch (*(u8 *)((u8 *)addOffsetFirst((u32)temp_16,
                                         (u32)iGpffffb3b8) + 0x24)) {
    case 2:
        if (func_001da130(arg0, 0) == 0) {
            return 6;
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_001FAF70
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001faf70);
// FUN_001FB170
s32 func_001fb170(s32 arg0) {
    u32 temp_2;

    temp_2 = arg0 & 0xFFFF;
    switch (temp_2) {
    case 2:
        return 0x8A;
    case 3:
        return 0x8B;
    case 4:
        return 0x8C;
    case 5:
        return 0x8D;
    case 6:
        return 0x8E;
    case 7:
        return 0x98;
    default:
        return 0;
    }
}
// FUN_001FB1F0
s32 func_001fb1f0(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    u32 var_19;
    u32 var_18;
    s32 temp_17;
    s32 var_2;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7F7FFFFF) && !(temp_16 & 0x80800000)) {
        var_19 = 0;
        goto loop_outer_test;
loop_outer_body:
        temp_17 = 1 << var_19;
        if (temp_16 & temp_17) {
            var_18 = 0;
            goto loop_inner_test;
loop_inner_body:
            if (func_002340c0(
                *(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_18 * 4) + 0x38) + 0x30) + 0xA64),
                temp_17) != 0) {
                var_18 += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            if (var_18 < *(u16 *)(arg0 + 0x6A)) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (var_18 != *(u16 *)(arg0 + 0x6A)) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        var_19 += 1;
loop_outer_test:
        if (var_19 < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (var_19 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
done:
        return 0;
}
/* measured: candidate object 284B/window 288B, normalized_diff 1. Committed at nd 1. */
// FUN_001FB360
s32 func_001fb360(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_5;
    s32 var_2;
    u32 var_17;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7C7FFFFF) && !(temp_16 & 0x83800000)) {
        var_17 = 0;
        goto loop_test;
loop_body:
        temp_5 = 1 << var_17;
        if (!(temp_16 & temp_5)) {
            goto loop_increment;
        }
        if (func_002340c0(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                          temp_5) == 0) {
            goto loop_after_call;
        }
loop_increment:
        var_17 += 1;
loop_test:
        if (var_17 < 0x20U) {
            goto loop_body;
        }
loop_after_call:
        if (var_17 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
    return 0;
}
// FUN_001FB480
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fb480);
// FUN_001FBB50
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fbb50);
// FUN_001FC1B0
void func_001fc1b0(s16 arg0) {
    if (func_00452380(&D_006251F0) == 0) {
        iGpffffb468 = 2;
        iGpffffb46e = arg0;
        iGpffffb469 = 0;
        func_00451de0(&D_006251F0, 0xC9, 0, 0,
                      (void *)func_001fbb50, NULL, (void *)&iGpffffb468);
    }
}
// FUN_001FC270
s32 func_001fc270(void)
{
    return 1;
}
// FUN_001FC280
void func_001fc280(void) {
    iGpffffb469 = 1;
    func_00122520(1, 1);
    func_001228a0(0xFF, 0xFF, 0xFF);
}
// FUN_001FC300
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fc300);
