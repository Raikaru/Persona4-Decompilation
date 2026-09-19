#include "include_asm.h"
#include "type.h"
typedef struct BtlPacket BtlPacket;
typedef struct BtlUnit BtlUnit;
typedef struct RwV3d { f32 x, y, z; } RwV3d;
extern void func_00194ff0(u8 *, u8 *, f32 *, f32 *);
extern f32 func_001ec250(const RwV3d *, const RwV3d *);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *, const RwV3d *, f32, u32);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

void btlActionSetState(u8 *arg0, u16 arg1);
u8 *func_00193bf0(u64 arg0, u64 arg1);
void func_001b0800();
static inline s32 func_001a_add_offset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 func_001a_fix_var(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}
void func_001f6cd0(void);

void func_001f14f0(void *arg0);
void func_001eb3b0(u8 *arg0);
u8 func_001d7f10(void *arg0, u8 *arg1, u16 arg2, u32 arg3);
extern void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);
void func_001d8cb0(void *arg0, void *arg1);

s32 btlUnitIsMoving(u8 *arg0);

void func_001a03b0(s64 *arg0);
void func_001dbf20(void *arg0, s32 arg1);
BtlPacket *func_001d3700(u16 arg0, u16 arg1);
s32 func_00194590(u8 *arg0, u32 arg1);
extern void func_0022db90(u8 *arg0);
extern void func_001f0a40(void *arg0);
extern void func_00212070(u8 *arg0, u8 *arg1);
extern void func_001b0850(u8 *arg0, s32 arg1, s32 arg2);
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern void func_001eb4a0(u8 *arg0, u8 *arg1, s64 arg2);
extern s32 func_001f6930(u8 *arg0);
extern s32 func_001f6bf0(u8 *arg0);
extern s32 func_001f6f60(u8 *arg0);
extern s32 func_001f7140(u8 *arg0);
extern void func_001f62b0(void);
extern s32 func_001f62f0(u8 *arg0);
extern void func_001f86d0(void);
extern void func_001f9a50(u16 arg0, s32 arg1);
extern void func_001f9a90(void);
extern void func_00213bb0(s32 arg0);
extern void func_00213be0(s32 arg0);
extern void func_00218560(u8 *arg0, u8 *arg1);
extern s32 func_00218690(s32 arg0);
extern void func_002186c0(u8 *arg0, s32 arg1);
extern void func_00218700(s32 arg0);
extern void func_00218730(s32 arg0);
extern u8 *func_0019bbe0(u8 *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern u8 *func_0019bd00(u8 *arg0);
extern u8 *func_0019bdd0(u8 *arg0);
extern s32 func_0020ba00(s32 arg0);
extern s32 func_001d8df0(u8 *arg0);
extern void func_0020bac0(s32 arg0);
extern u8 *func_0020ba90(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0020ba60(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_001faf70(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0020ba30(s32 arg0);
extern void func_00203880(s32 arg0, s32 arg1);
extern u8 *func_0019b6a0(s32 arg0);
u8 *btlCameraCreateSetStatePacket(void *arg0, s32 arg1);
u32 func_001deeb0(void *arg0);
void func_001ded30();
u32 func_001deee0();
s32 func_0023dfe0(u8 *unit);
u32 func_001d8bc0(void *arg0);
void func_001d8be0(u8 *arg0, s32 arg1);
u8 *func_001f5f70(u8 *arg0, u16 arg1, u32 arg2, u32 arg3, u32 arg4);
extern u8 *iGpffffb3b8;
void func_001d8e50(u8 *arg0, u8 *arg1);
void func_0020b6d0(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3);
extern void func_00212010(s32 task);
void func_0019faf0(u8 *arg0);
s32 func_0023e1f0();
u8 *func_0019e550(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_001bc920(u8 *arg0, s32 arg1);
u8 *func_0019a0c0(u8 *arg0, s16 arg1);
u8 *func_0019e7c0(s32 arg0, s32 arg1);
extern s16 func_00196bd0(u8 *arg0, u8 *arg1, s32 arg2);
extern void func_001eb410(u8 *arg0);
extern u8 *func_001979e0(u8 *arg0, u8 *arg1, s32 arg2, f32 arg3, f32 arg4);
extern u8 *func_001d3530(u8 *arg0, u8 *arg1, s32 arg2);
extern f32 fGpffff811c;
extern s32 func_002326e0(s32 arg0);
extern s32 func_001f6d60(u8 *arg0);
extern u8 *func_00202590(u8 *arg0, s32 arg1, s32 arg2);
extern void func_001f0a10(u8 *arg0);
extern u8 *func_001f36e0(s32 arg0, s32 arg1, void *arg2, s16 arg3, s16 arg4);
extern u8 *func_00202740(u8 *arg0);
extern u8 *func_00201de0(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u8 *arg7, u16 arg8);
u8 *func_00194b60(void);
extern BtlPacket *func_001d3900(u16 arg0);
extern u8 *func_0019e9f0();
extern u8 *func_001d3d00();
BtlPacket *func_001ba090(s32 arg0);
u8 *func_001d7a10(u16 arg0);
u8 *func_00201f20(void);
s32 func_002428f0(u8 *arg0, s32 arg1);
u8 *func_001fa720(u8 *arg0);
s32 func_001eb860(void);
extern void func_00218420(s32 task, u8 *arg1);
u8 *func_001fa8f0(void);
extern s32 func_002184a0(s32 task);
extern s32 func_002184d0(s32 task);
u8 *func_001faa60(void);
extern void func_00218500(s32 task);
extern void func_00212240(u8 *arg0, s32 arg1);
s32 func_0019ff60(u8 *arg0);
s64 *func_001b1540(void);
s32 func_001d94d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 (*arg5)(u8 *arg0, s64 arg1));
s32 func_001f01a0(u8 *arg0, s32 arg1);
s32 func_0023d8e0(u8 *arg0, u16 arg1);
u8 *func_001fa9c0(void);
s32 func_001db5e0(u8 *arg0, s64 arg1);
u32 func_00193cd0(u32 arg0);
u8 *func_001fa110(u8 *arg0);
u8 *func_00202850(void);
extern void func_002182c0(u8 *arg0, u8 *arg1);
u8 *func_00198300(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_00194c90(s32 arg0, s32 arg1);
u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
extern s32 func_00218360(s32 task);
extern s32 func_00218390(s32 task);
u8 *func_001f99c0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 *func_001fa450(void);
u8 *func_002027e0(void);
u8 *func_001f3870(s64 *arg0, s8 arg1);
extern void func_002183c0(s32 task);
extern void func_00218160(u8 *task, u8 *unit);
extern s32 func_00218200(s32 task);
extern s32 func_00218230(s32 task);
extern void func_00218260(s32 task);
s64 func_001d15a0(s32 arg0);
void func_001eb7f0(void);
s32 func_001ef720(s32 arg0, s32 arg1);
s32 func_001fabe0(u8 *arg0);
u32 func_00232710(s32 arg0, u32 arg1);
s32 func_00232d80(u8 *arg0);
s64 func_00235320(u8 *arg0);
s32 func_00243e30(u16 *arg0);
s32 func_001f6770(u8 *arg0);
s32 func_001fac30(void);
s32 func_001a3de0(u8 *arg0);

u8 *func_002022e0(u32 arg0, u16 arg1);
extern u8 *func_00199ee0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
s32 func_0010b300(s32 arg0);
extern void func_0019ef30(u8 *arg0, u16 arg1);
extern void func_0010b7f0(void);
extern s32 func_00106330(s32 arg0);
BtlPacket *func_001d6240(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
BtlPacket *func_001f7c20(u16 arg0, u16 arg1, u16 arg2);
extern f32 D_0076144C;
s32 func_001fac80(u8 *arg0);
void func_001fad10(void);



// FUN_001A0140
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
#pragma opt_loop_invariants on
s32 func_001a0140(u8 *arg0)
{
    s32 i0;
    u8 temp_3;

    temp_3 = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
    switch (temp_3) {
    case 0:
    {
        s32 j0;
        s32 n0;
        s32 count0;
        s32 mask0;
        u8 *target0;

        i0 = 0;
        n0 = *(u16 *)(arg0 + 0x6A);
        mask0 = 0x100000;
        goto outer0_test;
outer0_body:
        target0 = *(u8 **)(arg0 + ((u16)i0 * 4) + 0x38);
        count0 = target0[0xD9];
        j0 = 0;
        goto inner0_test;
inner0_body:
        if ((*(s32 *)(target0 + ((u16)j0 << 5) + 0xF8) & mask0) != 0) {
            return 1;
        }
        j0 = (j0 + 1) & 0xFFFF;
inner0_test:
        if ((j0 & 0xFFFF) < count0) {
            goto inner0_body;
        }
        i0 = (i0 + 1) & 0xFFFF;
outer0_test:
        if ((i0 & 0xFFFF) >= n0) {
            goto block_20;
        }
        goto outer0_body;
    }
    case 1:
    {
        s32 i1;
        s32 j1;
        s32 n1;
        s32 count1;
        u8 *target1;

        i1 = 0;
        n1 = *(u16 *)(arg0 + 0x6A);
        goto outer1_test;
outer1_body:
        target1 = *(u8 **)(arg0 + ((u16)i1 * 4) + 0x38);
        count1 = target1[0xD9];
        j1 = 0;
        goto inner1_test;
inner1_body:
        if ((*(u16 *)(target1 + ((u16)j1 << 5) + 0x10E) & 4) != 0) {
            return 1;
        }
        j1 = (j1 + 1) & 0xFFFF;
inner1_test:
        if ((j1 & 0xFFFF) < count1) {
            goto inner1_body;
        }
        i1 = (i1 + 1) & 0xFFFF;
outer1_test:
        if ((i1 & 0xFFFF) < n1) {
            goto outer1_body;
        }
        goto block_20;
    }
    default:
        goto block_20;
    }
block_20:
    return 0;
}
/* measured: close loop-invariant probe for 001A0140. */
#pragma opt_loop_invariants off
// FUN_001A0290
void func_001a0290(u8 *arg0, s32 arg1, u8 *arg2)
{
    s32 temp_5;
    s32 temp_3;
    u8 *temp_4;

    if (*(u16 *)(arg0 + 0x18) & 0x4000) {
        *(s16 *)arg2 = 0x24;
        *(s16 *)(arg2 + 2) = -1;
        return;
    }
    *(s16 *)arg2 = 0;
    *(s16 *)(arg2 + 2) = 3;
    temp_5 = (arg1 & 0xFFFF) * 0x28;
    if (*(u8 *)(iGpffffb3b8 + temp_5) & 2) {
        temp_4 = *(u8 **)(arg0 + 0x30);
        if (temp_4[0xA2] == 0) {
            temp_3 = func_0023e1f0(*(u8 **)(temp_4 + 0xA64), temp_5) & 0xFF;
            switch (temp_3) {
            case 0:
            case 1:
            case 6:
                *(s16 *)arg2 = 1;
                *(s16 *)(arg2 + 2) = 4;
                return;
            case 5:
                *(s16 *)arg2 = 2;
                *(s16 *)(arg2 + 2) = 5;
                return;
            case 2:
            case 3:
            case 4:
                break;
            }
        } else {
            switch (*(u16 *)(temp_4 + 0xA4)) {
            case 0x109:
                *(s16 *)arg2 = 2;
                *(s16 *)(arg2 + 2) = 5;
                break;
            }
        }
    }
}
// FUN_001A03B0
void func_001a03b0(s64 *arg0)
{
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_4;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *var_16;

    temp_5 = D_0076449C;
    if (*(s32 *)(temp_5 + 0xC) & 0x400000) {
        if (*(u16 *)(temp_5 + 0x18) & 0x20) {
            temp_2 = func_0019e7c0(0, 3);
            *(s64 *)(temp_2 + 0x60) = *arg0;
            func_00194590(temp_2, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 2) {
            temp_2_2 = (u8 *)func_001d3700(3, 0xFFF);
            *(s64 *)(temp_2_2 + 0x60) = *arg0;
            func_00194590(temp_2_2, 0);
        }
        temp_4 = D_0076449C;
        if (*(u16 *)(temp_4 + 0x18) & 1) {
            var_16 = *(u8 **)(temp_4 + 0x174);
            goto loop_test;
loop_body:
            if ((*(u16 *)(var_16 + 0x1A) & 1) &&
                func_002428f0(*(u8 **)(*(u8 **)(var_16 + 0x30) + 0xA64), 0) == 0) {
                temp_2_3 = func_0019a0c0(*(u8 **)(var_16 + 0x30), 0);
                *(s64 *)(temp_2_3 + 0x60) = *arg0;
                func_00194590(temp_2_3, 0);
            }
            var_16 = *(u8 **)(var_16 + 0x450);
loop_test:
            if (var_16 != NULL) {
                goto loop_body;
            }
        }
        if (*(u16 *)(D_0076449C + 0x18) & 0x10) {
            temp_2_4 = (u8 *)func_001ba090(0);
            *(s64 *)(temp_2_4 + 0x60) = *arg0;
            func_00194590(temp_2_4, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 8) {
            temp_2_5 = func_001d7a10(5);
            *(s64 *)(temp_2_5 + 0x60) = *arg0;
            func_00194590(temp_2_5, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 4) {
            temp_2_6 = func_001bc920((u8 *)arg0, 0x24);
            *(s64 *)(temp_2_6 + 0x60) = *arg0;
            func_00194590(temp_2_6, 0);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 0x40) {
            temp_2_7 = func_00201f20();
            *(s64 *)(temp_2_7 + 0x60) = *arg0;
            func_00194590(temp_2_7, 0);
        }
        *(u16 *)(D_0076449C + 0x18) = 0;
        temp_5_2 = D_0076449C;
        *(s32 *)(temp_5_2 + 0xC) &= 0xFFBFFFFF;
    }
}
// FUN_001A05F0
s32 func_001a05f0(u8 *arg0) {
    u16 temp_5;
    u8 *temp_3;

    temp_5 = *(u16 *)(arg0 + 0x1A);
    if (temp_5 & 1) {
        goto cont1;
    }
    return 0;
cont1:
    temp_3 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA0C);
    if (temp_5 & 0x10) {
        goto cont2;
    }
    return 0;
cont2:
    return (*(s32 *)(temp_3 + 0x98) & 2) != 0;
}



// FUN_001A0640
void func_001a0640(void)
{
}

// FUN_001A0650
void func_001a0650(void)
{
}

// FUN_001A0660
void func_001a0660(void)
{
}

// FUN_001A0670
void func_001a0670(u8 *arg0) {
    s32 temp_5;

    temp_5 = *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C);
    if (temp_5 & 0x10) {
        *(s16 *)(arg0 + 0x430) = 1;
        btlActionSetState(arg0, 0x18);
        return;
    }
    if (temp_5 & 1) {
        btlActionSetState(arg0, 0x23);
    }
}



// FUN_001A06D0
void func_001a06d0(u8 *arg0) {
    extern void func_001b0800(u8 *arg0, u16 arg1);
    u8 *var_17;
    s32 var_16;
    u32 temp_4;
    s16 temp_17;
    s32 var_2;

    var_16 = 1;
    if (*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x10) {
        *(s16 *)(arg0 + 0x430) = 2;
        func_001b0800(arg0, 0x18);
        return;
    }
    var_17 = *(u8 **)(D_0076449C + 0x174);
    while (var_17 != NULL) {
        if ((arg0 != var_17) && (*(u16 *)(var_17 + 0x1A) & 1) &&
            (func_002428f0(*(u8 **)(*(u8 **)(var_17 + 0x30) + 0xA64), 0) == 0) &&
            (*(s32 *)(*(u8 **)(var_17 + 0x30) + 0x9C) & 0x10)) {
            var_16 = 0;
            break;
        }
        var_17 = *(u8 **)(var_17 + 0x450);
    }
    func_0022db90(arg0);
    if (*(u16 *)(arg0 + 0x18) & 0x8000) {
        func_001b0800(arg0, 0x21);
        return;
    }
    func_001f0a40(arg0 + 0xD8);
    if (func_001fabe0(arg0) != 0) {
        *(void **)(arg0 + 0x440) = (void *)&func_001fac30;
        *(s16 *)(arg0 + 0x43C) = 2;
        func_001b0800(arg0, 0x16);
        return;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        var_2 = 0;
    } else if ((*(s16 *)(iGpffffb3ac + 0xA70) != -1) &&
               (temp_4 = func_001ef720(2, 0x80000) & 0xFFFF,
                (u32)(*(s16 *)(iGpffffb3ac + 0xA72) >> 1) >= temp_4) &&
               ((temp_17 = *(s16 *)(iGpffffb3ac + 0xA70)) != (s16)func_001d15a0(temp_4))) {
        var_2 = 1;
    } else {
        var_2 = 0;
    }
    if ((var_2 != 0) &&
        (func_00232710((s32)*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x180001) == 0)) {
        func_001b0850(arg0, 4, 1);
        return;
    }
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x80000) {
        var_16 = 0;
    }
    if (func_001eb860() == 1) {
        *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
    } else {
        *(s32 *)(iGpffffb3ac + 0xC) &= ~0x2000;
        func_001eb7f0();
    }
    if ((s32)*(u8 *)(arg0 + 0x28) > 0) {
        if (!(*(s32 *)(iGpffffb3ac + 0x10) & 0x20)) {
            func_00212070(*(u8 **)(iGpffffb3ac + 0xDD4), arg0);
            func_00194590(func_001f99c0(arg0, 0xE, 0, 0, 0), 1);
        }
    } else {
        *(u16 *)(arg0 + 0x18) |= 0x400;
        *(u16 *)(arg0 + 0x1A) &= 0xFFBF;
    }
    if ((*(u8 *)(arg0 + 0x28) == 0) && (*(u8 *)(arg0 + 0x29) == 0)) {
        *(s32 *)(arg0 + 0x41C) = func_00232d80(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    } else {
        *(s32 *)(arg0 + 0x41C) = 0;
    }
    if ((*(s32 *)(arg0 + 0x41C) != 0) ||
        (func_00243e30(*(u16 **)(*(u8 **)(arg0 + 0x30) + 0xA64)) != 0)) {
        var_16 = 0;
    }
    if (var_16 != 0) {
        if ((*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0) &&
            (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4) == 1) &&
            (*(u8 *)(arg0 + 0x28) == 0) && (*(u8 *)(arg0 + 0x29) == 0)) {
            *(s32 *)(iGpffffb3ac + 0x20) += 1;
        }
        if ((s8)func_00235320(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64)) >= 0) {
            func_001b0800(arg0, 0xA);
            return;
        }
        if (func_001f6770(arg0) != 0) {
            func_001b0800(arg0, 0xB);
            return;
        }
        func_001b0800(arg0, *(u16 *)(arg0 + 0x14));
    }
}
/* measured: live object 956B/window 1088B, normalized_diff 230 (guard below; schedule on inside the guard is worth 2 words, 232 -> 230, sweep-measured; schedule fills delay slots so the object compacts 266 -> 239 instrs while fnalign fragments 99 -> 393 edits). Solved: twin-idiom calls, local externs, s64 arg0, memset-grounded stack, Ghidra nested tail (else-form), alternating unit-address spellings. Walls: frame 0x80 vs retail 0x70 (5 saved regs vs 3; temp live values overflow into s-regs), sp6E uninit-OR kept in reg ($s4 ori) vs retail stack slot (lhu/ori/sh), first-global lw symbol/offset. Ruled out today: baseline opts without the cs-off/prop-off pair (233, frame balloons to 0xa0), sp6E declared last (232, lateral), volatile sp6E (236). Production stays ASM; banked as floor. */
// FUN_001A0B00 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma schedule on
void func_001a0b00(s64 *arg0) {
    extern void func_001f0a10(u8 *arg0);
    extern u8 *func_001f36e0(s32 arg0, s32 arg1, void *arg2, s16 arg3, s16 arg4);
    extern u8 *func_00201de0(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u8 *arg7, u16 arg8);
    extern u8 *func_00202740(u8 *arg0);
    extern u8 *func_00202590(s32 arg0, s8 arg1, s16 arg2);
    extern u32 func_00231f80(u8 *arg0);
    extern void func_001b0800(s64 *arg0, u16 arg1);
    u16 sp6E;
    s32 sp54;
    s32 sp50;
    s64 var_17;
    s32 temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x80000) == 0 &&
        func_00193cd0(0x700) == 0 && func_00193cd0(0x504) == 0 &&
        func_00193cd0(0x506) == 0 && func_00193cd0(0x301) == 0 &&
        func_00193cd0(0x104) == 0) {
        func_001a03b0(arg0);
        func_001f0a10((u8 *)&sp50);
        if (func_00243e30(*(u16 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA64)) != 0) {
            sp6E |= 0x80;
        }
        if (*(s32 *)((u8 *)arg0 + 0x41C) != 0) {
            temp_16 = func_00231f80(*(u8 **)(*(u8 **)(arg0 + 6) + 0xA64)) & 0xFFFF;
            func_00232290(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA64));
            var_17 = 0x16;
            if (*(s32 *)((u8 *)arg0 + 0x41C) & 1) {
                sp50 += ((temp_16 & 0xFFFF) * 0x64) / 5000;
            }
            if (*(s32 *)((u8 *)arg0 + 0x41C) & 2) {
                sp50 += ((temp_16 & 0xFFFF) * 0x64) / 2500;
            }
            if (*(s32 *)((u8 *)arg0 + 0x41C) & 4) {
                sp50 += ((temp_16 & 0xFFFF) * 0x64) / 1666;
            }
            if (*(s32 *)((u8 *)arg0 + 0x41C) & 8) {
                sp54 += 3;
            }
            if (*(s32 *)((u8 *)arg0 + 0x41C) & 0x10) {
                sp54 += 5;
            }
            if (*(s32 *)((u8 *)arg0 + 0x41C) & 0x20) {
                sp54 += 7;
            }
        }
        if ((sp6E != 0) || (sp50 != 0) || (sp54 != 0)) {
            if ((sp50 != 0) || (sp54 != 0)) {
                temp_2 = func_00202740(*(u8 **)(arg0 + 6));
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 1);
                if ((s16)var_17 != -1) {
                    temp_2_2 = (u8 *)func_001f7c20(0xE, 2, var_17 & 0xFFFF);
                    *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2_2, 1);
                }
            }
            temp_2_3 = (u8 *)func_001f36e0((s32)arg0, (s32)arg0, (u8 *)&sp50, 1, 1);
            *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_3, 1);
            if ((sp50 != 0) || (sp54 != 0)) {
                temp_2_4 = func_00201de0((s32)*(u8 **)((u8 *)arg0 + 0x30), (s32)*(u8 **)(arg0 + 6), -1, 0, 0, 0, 1, (u8 *)&sp50, 8);
                *(s8 *)(temp_2_4 + 0) = 4;
                *(s64 *)(temp_2_4 + 8) = *(s64 *)(temp_2_3 + 0x58);
                *(u8 *)(temp_2_4 + 0x47) &= ~0x20;
                func_00194590(temp_2_4, 3);
                if (sp50 != 0) {
                    temp_2_5 = (u8 *)func_00202590((s32)*(u8 **)((u8 *)arg0 + 0x30), 0, 0);
                    *(s8 *)(temp_2_5 + 0) = 4;
                    *(s64 *)(temp_2_5 + 8) = *(s64 *)(temp_2_3 + 0x58);
                    *(u8 *)(temp_2_5 + 0x47) &= ~0x20;
                    func_00194590(temp_2_5, 3);
                }
            }
        }
        if ((s8)func_00235320(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA64)) >= 0) {
            func_001b0800(arg0, 0xA);
        } else if (func_001f6770((u8 *)arg0) == 0) {
            func_001b0800(arg0, 3);
        } else {
            func_001b0800(arg0, 0xB);
        }
    }
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a0b00);
#endif
#pragma opt_common_subs on
#pragma opt_propagation on
/* measured: opt_propagation off plus one named local per address term. mwcc
   keeps source operand order for `named + named` (addu off,base / addu idx,sum
   as retail) but commutes an inline product on the left (`a * k + b` emits
   addu b,a*k); the table base must be copied first so its lw leads the block. */
#pragma opt_propagation off
// FUN_001A0F40
void func_001a0f40(s64 *arg0)
{
    extern void func_001b0800(s64 *arg0, u16 arg1);
    RwV3d sp30;
    s32 temp_7;
    u16 var_5;
    u16 temp_6;
    u8 temp_3;
    u8 *temp_16;
    u8 *temp_2;
    u32 source_offset;
    u32 tbl;
    u32 sum;
    u32 idx4;

    temp_16 = *(u8 **)((u8 *)arg0 + 0x30);
    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) &&
        ((*(u16 *)((u8 *)arg0 + 0x1A) & 1) != 0) &&
        (temp_16[0xA2] == 0)) {
        *(u16 *)((u8 *)arg0 + 0x14) = 9;
    }
    if (func_001b0e90(arg0) != 0) {
        func_001b0800(arg0, *(u16 *)((u8 *)arg0 + 0x14));
        return;
    }
    func_00194ff0(temp_16, (u8 *)&sp30, 0, NULL);
    if (!(func_001ec250((const RwV3d *)(temp_16 + 4), &sp30) <= 75.0f)) {
        var_5 = 2;
        temp_7 = (u16)(!(iGpffffb3b8[
            (*(u16 *)((u8 *)arg0 + 0x6E) * 0x28)] & 2));
        temp_6 = *(u16 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) + 2);
        temp_3 = *(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2);
        switch (temp_3) {
        case 0:
            break;
        case 1:
            tbl = (u32)iGpffffb3cc;
            source_offset = (u32)temp_6 * 0xE8;
            sum = source_offset + tbl;
            idx4 = (u16)temp_7 * 4;
            var_5 = *(u16 *)(idx4 + sum + 0x24);
            break;
        }
        temp_2 = (u8 *)btlUnitCreateMovePacket(
            *(BtlUnit **)((u8 *)arg0 + 0x30), &sp30, D_005F6D20[var_5 & 0xFFFF], 0);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 1);
        return;
    }
    func_001b0800(arg0, *(u16 *)((u8 *)arg0 + 0x14));
}
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
// FUN_001A1450
void func_001a1450(s64 *arg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } sp40;
    struct Vec3 sp30;
    u16 temp_3;
    u16 temp_3_2;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *var_16;
    u8 *var_16_2;

    extern void func_001958f0(u8 *arg0, f32 *arg1);
    extern s32 func_00196b50(u8 *arg0);
    extern u8 *func_00197f50(u8 *arg0, void *arg1, s32 arg2);
    extern void func_00194590(u8 *arg0, s32 arg1);
    extern void func_00203670(s32 arg0, u8 *arg1);
    extern void func_00213c10(s32 task);

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) &&
        (*(u16 *)((u8 *)arg0 + 0x1A) & 1) &&
        (*(u8 **)((u8 *)arg0 + 0x30))[0xA2] == 0) {
        func_001b0800(arg0, 9);
        return;
    }
    func_001a03b0(arg0);
    temp_3 = *(u16 *)((u8 *)arg0 + 0x10);
    if ((temp_3 != 0x25) && (temp_3 != 4) && (temp_3 != 6) &&
        (temp_3 != 5) && (*(u16 *)(iGpffffb3ac + 0xF4) != 2)) {
        func_00194ff0(
            *(u8 **)((u8 *)arg0 + 0x30), NULL, 0, (f32 *)&sp40);
        var_16 = *(u8 **)(iGpffffb3ac + 0x17C);
        goto loop_14_test;
loop_14_body:
        if (func_00232710((s32)*(u8 **)(var_16 + 0xA64), 0x100) != 0) {
            func_001958f0(
                *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                (f32 *)&sp30);
        } else {
            sp30 = sp40;
        }
        temp_2 = func_00197f50(var_16, &sp30, 2);
        *(s64 *)(temp_2 + 0x60) = *arg0;
        func_00194590(temp_2, 0);
        var_16 = *(u8 **)(var_16 + 0xA68);
loop_14_test:
        if (var_16 != NULL) {
            goto loop_14_body;
        }
        var_16_2 = *(u8 **)(iGpffffb3ac + 0x184);
        goto loop_19_test;
loop_19_body:
        if (func_00196b50(var_16_2) == 0) {
            func_00194ff0(var_16_2, NULL, 0, (f32 *)&sp40);
            temp_2_2 = func_00197f50(var_16_2, &sp40, 2);
            *(s64 *)(temp_2_2 + 0x60) = *arg0;
            func_00194590(temp_2_2, 0);
        }
        var_16_2 = *(u8 **)(var_16_2 + 0xA68);
loop_19_test:
        if (var_16_2 != NULL) {
            goto loop_19_body;
        }
        temp_2_3 = (u8 *)func_001d3700(3, 0x8001);
        *(s64 *)(temp_2_3 + 0x60) = *arg0;
        func_00194590(temp_2_3, 0);
        if (*(u8 *)((u8 *)arg0 + 0x28) == 0) {
            temp_2_4 = func_001f5f70((u8 *)arg0, 0x1D, 0, 0, 0);
            *(s64 *)(temp_2_4 + 0x60) = *arg0;
            func_00194590(temp_2_4, 1);
        }
    }
    {
        u8 *temp_5;

        temp_5 = *(u8 **)((u8 *)arg0 + 0x30);
        if (temp_5[0xA2] == 0) {
            temp_2_5 = func_0019e550(NULL, temp_5, 2);
            *(s64 *)(temp_2_5 + 0x60) = *arg0;
            func_00194590(temp_2_5, 1);
        } else {
            temp_2_6 = func_0019e7c0(0, 2);
            *(s64 *)(temp_2_6 + 0x60) = *arg0;
            func_00194590(temp_2_6, 1);
        }
    }
    func_00194590(
        func_0019e7c0(
            *(s32 *)(u8 *)func_001a_add_offset(0x30, (s32)arg0), 0),
        1);
    temp_2_7 = func_001bc920((u8 *)arg0, 0x21);
    *(s64 *)(temp_2_7 + 0x60) = *arg0;
    func_00194590(temp_2_7, 0);
    func_001eb3b0((u8 *)arg0 + 0x38);
    temp_3_2 = *(u16 *)(u8 *)func_001a_add_offset(0x10, (s32)arg0);
    if ((temp_3_2 != 0x25) && (temp_3_2 != 6) && (temp_3_2 != 5)) {
        func_00203670(*(s32 *)(iGpffffb3ac + 0xDD4), (u8 *)arg0);
        func_00213c10(*(s32 *)(iGpffffb3ac + 0xDD4));
    }
    func_0019faf0((u8 *)arg0);
    *(s32 *)(iGpffffb3ac + 0xC) |= 0x20000;
    *(u16 *)((u8 *)arg0 + 0x41C) = 0;
    *(s32 *)((u8 *)arg0 + 0x420) = 0;
}
/* Battle-dispatch floor (1200B window). First probe nd 124
   (obj 1176B, in-window); frame/prologue verified. Open:
   switch-dispatch order, scheduler ordering. Array-form
   absolute symbol access fixed a 90-word GPREL cascade;
   redundant-mask variants measured worse. Triple-built. */
// FUN_001A17D0 NONMATCHING
#ifdef NON_MATCHING
void func_001a17d0(u8 *arg0)
{
    extern u8 *func_001bc920(u8 *arg0, s32 arg1);
    extern u16 D_008C024C[];
    s32 v4;
    u16 t;
    u16 v10;
    u16 f;
    s32 bVar;
    s16 sVar2;
    u8 *w;
    u8 *i;

    func_0019fc60();
    func_0019fa40();
    func_00212010(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (*(s32 *)(arg0 + 0x420) == 1) {
        t = *(u16 *)(arg0 + 0x41C);
        if (t == 0) {
            func_002037b0(*(s32 *)(iGpffffb3ac + 0xDD4));
            *(s32 *)(arg0 + 0x420) = 0;
        } else {
            *(u16 *)(arg0 + 0x41C) = t - 1;
        }
        return;
    }
    v4 = func_002037e0(*(s32 *)(iGpffffb3ac + 0xDD4)) & 0xFFFF;
    if ((D_008C024C[0] & 8) != 0 && (v4 & 0xFFFF) == 1 && (*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) == 0) {
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000) != 0) {
            if (func_00203810(*(s32 *)(iGpffffb3ac + 0xDD4)) == 1) {
                if (func_00203850(*(s32 *)(iGpffffb3ac + 0xDD4)) == 0) {
                    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x10000) == 0) {
                        func_0020bf60(*(s32 *)(iGpffffb3ac + 0xDD4));
                        *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x10000;
                        func_00213b80(*(s32 *)(iGpffffb3ac + 0xDD4));
                        func_00204d90(*(s32 *)(iGpffffb3ac + 0xDD4));
                        w = func_001bc920(arg0, 40);
                        *(s64 *)(w + 0x60) = *(s64 *)arg0;
                        func_00194590(w, 0);
                    }
                    return;
                }
            }
        }
    } else {
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x10000) != 0) {
            func_0020bf90(*(s32 *)(iGpffffb3ac + 0xDD4));
            *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) & ~0x10000;
            func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
            func_00204d50(*(s32 *)(iGpffffb3ac + 0xDD4));
            w = func_001bc920(arg0, 33);
            *(s64 *)(w + 0x60) = *(s64 *)arg0;
            func_00194590(w, 0);
        }
    }
    if (v4 == 0) {
        goto tail;
    }
    if (v4 == 2) {
        v10 = *(u16 *)(arg0 + 0x6C);
        switch (v10) {
        case 10:
            f = 0;
            bVar = 1;
            break;
        case 3:
            f = (u16)func_001fae80(arg0, *(u16 *)(arg0 + 0x6E), 1);
            bVar = 1;
            break;
        case 2:
        case 1:
            f = (u16)func_001fae80(arg0, *(u16 *)(arg0 + 0x6E), 0);
            bVar = 1;
            break;
        default:
            f = 0;
            bVar = 0;
            break;
        }
        if (bVar != 0) {
            sVar2 = func_001fb170(f);
            if (sVar2 != 0) {
                func_0045af60(0, 15, 0, 8);
                func_002019f0(*(s32 *)(arg0 + 0x30), sVar2);
                *(u16 *)(arg0 + 0x41C) = 6;
                *(s32 *)(arg0 + 0x420) = 1;
                func_00203890(*(s32 *)(iGpffffb3ac + 0xDD4));
                return;
            } else {
                func_00213c40(*(s32 *)(iGpffffb3ac + 0xDD4));
                func_00204d90(*(s32 *)(iGpffffb3ac + 0xDD4));
                func_001b0800(arg0, 6);
                return;
            }
        }
        goto tail;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) {
        func_00212040(*(s32 *)(iGpffffb3ac + 0xDD4));
        func_00216ca0(*(s32 *)(iGpffffb3ac + 0xDD4));
        func_002038c0(*(s32 *)(iGpffffb3ac + 0xDD4));
        func_00213c40(*(s32 *)(iGpffffb3ac + 0xDD4));
        for (i = *(u8 **)(iGpffffb3ac + 0x174); i != 0; i = *(u8 **)(i + 0x450)) {
        }
        func_001b0800(arg0, 9);
    }
    return;
tail:
    *(u16 *)(arg0 + 0x18) = *(u16 *)(arg0 + 0x18) | 2;
    func_00212040(*(s32 *)(iGpffffb3ac + 0xDD4));
    func_00216ca0(*(s32 *)(iGpffffb3ac + 0xDD4));
    func_002038c0(*(s32 *)(iGpffffb3ac + 0xDD4));
    func_00213c40(*(s32 *)(iGpffffb3ac + 0xDD4));
    for (i = *(u8 **)(iGpffffb3ac + 0x174); i != 0; i = *(u8 **)(i + 0x450)) {
    }
    func_001b0800(arg0, 15);
    return;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a17d0);
#endif
// FUN_001A1C80
void func_001a1c80(u8 *arg0)
{
    u8 *var_17;
    s32 var_16;
    u8 temp_3;
    u8 *temp_2;

    switch (*(u16 *)(arg0 + 0x6C)) {
    case 4:
        func_001d7c60(arg0, arg0 + 0x98, 2, 0, 0);
        var_16 = func_001a_fix_var(*(u16 *)(arg0 + 0x6E));
        break;
    default:
        var_16 = *(u16 *)(arg0 + 0x6E);
        temp_3 = *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                               (u32)iGpffffb3b8) + 8);
        switch (temp_3) {
        case 1:
        case 2:
            {
                extern void func_001d7c60(
                    u8 *arg0, u8 *arg1, u8 arg2, u8 arg3, u32 arg4);
                func_001d7c60(
                    arg0,
                    arg0 + 0x98,
                    *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                                  (u32)iGpffffb3b8) + 9),
                    *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                                  (u32)iGpffffb3b8) + 0xA),
                    0);
            }
            break;
        default:
            func_001d7f10(arg0, arg0 + 0x98, var_16 & 0xFFFF, 0);
            break;
        }
        break;
    }
init_1c80:
    func_001d8cb0(arg0, arg0 + 0x98);
    temp_3 = *(u8 *)(func_001a_add_offset(
        *(u16 *)(arg0 + 0x6E) * 0x28, (u32)iGpffffb3b8) + 8);
    switch (temp_3) {
    case 1:
    case 2:
        goto type12_2_1c80;
    default:
        goto typeother_2_1c80;
    }
type12_2_1c80:
    var_17 = NULL;
    goto after_type_1c80;
typeother_2_1c80:
    func_001d8e50(arg0, arg0 + 0x98);
after_type_1c80:
    func_0020b6d0(
        *(s32 *)(D_0076449C + 0xDD4),
        arg0,
        arg0 + 0x98,
        (s64)(s16)var_16);
    temp_2 = func_001bc920(arg0, 0x22);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    func_00212010(*(s32 *)(D_0076449C + 0xDD4));
    func_0019faf0(arg0);
    if (var_17 != NULL) {
        temp_2 = func_0019e550(NULL, *(u8 **)(var_17 + 0x30), 1);
        func_00194590(temp_2, 1);
        temp_2 = func_0019e7c0(*(s32 *)(var_17 + 0x30), 0);
        func_00194590(temp_2, 1);
    }
}
/* measured 001a1ea0 (WCold): m2c cold draft cleaned to honest compiling C (raw `iGpffffb3ac`/`iGpffffb3b8` + file-evidenced `*(s32*)/(u8**)/(u16*)/(u8*)/(s64*)` casts, old-style `s32()` for 18 truly-missing callees, honest `s64` for 001fb170/002019f0); 262 words via `tools/probe_variants.py` (v6 base 294; sched 296, commonsubs 262 win, loopinv 294, propOff 311), 380/381 (-1, 0.26% floor) 183 edits via `tools/fnalign.py --candidate`, `tools/wscan_pairs.py` 1 vs 1 (same 0x10 shift, colour only); remaining for next pass: `temp_2_4!=2&&!=1` + `temp_3_4` switch 1/2 adjacent folding (`x==K||x==K+1` two-compare), double-def pinning for `((unk6E*0x28)+base)->unk8` scheduling. */
// FUN_001A1EA0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_001a1ea0(u8 *arg0) {
    extern u16 D_008C024C;
    extern s32 func_0019e550();
    extern s32 func_0019e7c0();
    extern s32 func_0019fa40();
    extern s32 func_0019fc60();
    extern s32 func_001d8be0();
    extern s64 func_001fb170(s32);
    extern void func_002019f0(u8 *, s64);
    extern s32 func_002037b0();
    extern s32 func_002038c0();
    extern s32 func_00204d50();
    extern s32 func_0020bf60();
    extern s32 func_0020bf90();
    extern s32 func_00212040();
    extern s32 func_00213b50();
    extern s32 func_00213b80();
    extern s32 func_00213c40();
    extern s32 func_00216ca0();
    extern s32 func_0045af60();
    s32 temp_16;
    s32 temp_2_5;
    s32 temp_4;
    s32 temp_6;
    s32 var_4;
    s32 var_4_2;
    s64 temp_16_2;
    u16 temp_3_2;
    u16 temp_3_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_5_2;
    u8 temp_2_4;
    u8 *temp_3;
    u8 *temp_3_3;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_5;
    u8 *var_2;
    u8 *var_2_2;

    func_0019fc60();
    func_0019fa40();
    temp_16 = func_0020ba00((s32)(*(u8**)(iGpffffb3ac + 0xDD4))) & 0xFFFF;
    if ((D_008C024C & 8) && !(temp_16 & 0xFFFF)) {
        temp_4 = (*(s32*)(iGpffffb3ac + 0xC));
        if (temp_4 & 0x20000) {
            if (!(temp_4 & 0x10000) && ((func_001d8df0(arg0 + 0x98) & 0xFFFF) != 1)) {
                func_0020bf60((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
                temp_4_2 = iGpffffb3ac;
                (*(s32*)(temp_4_2 + 0xC)) = (s32) ((*(s32*)(temp_4_2 + 0xC)) | 0x10000);
                func_00213b80((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
                temp_2 = func_001bc920(arg0, 0x28);
                (*(s64*)(temp_2 + 0x60)) = (s64) (*(s64*)arg0);
                func_00194590(temp_2, 0U);
            }
            return;
        }
        goto block_9;
    }
    temp_5 = iGpffffb3ac;
    if ((*(s32*)(temp_5 + 0xC)) & 0x10000) {
        func_0020bf90((s32)(*(u8**)(temp_5 + 0xDD4)), temp_5);
        temp_4_3 = iGpffffb3ac;
        (*(s32*)(temp_4_3 + 0xC)) = (s32) ((*(s32*)(temp_4_3 + 0xC)) & 0xFFFEFFFF);
        func_00213b50((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        temp_2_2 = func_001bc920(arg0, 0x22);
        (*(s64*)(temp_2_2 + 0x60)) = (s64) (*(s64*)arg0);
        func_00194590(temp_2_2, 0U);
    }
block_9:
    temp_6 = temp_16 & 0xFFFF;
    switch (temp_6) {                               /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        temp_3 = iGpffffb3ac;
        if ((*(s32*)(temp_3 + 0xC)) & 0x1000) {
            func_00212040((s32)(*(u8**)(temp_3 + 0xDD4)), 2, temp_6);
            func_00216ca0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_0020bac0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_002038c0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00213c40((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            var_2 = (*(u8**)(iGpffffb3ac + 0x174));
loop_17:
            if (var_2 != NULL) {
                var_2 = (*(u8**)(var_2 + 0x450));
                goto loop_17;
            }
            func_001b0800(arg0, 9);
            func_00194590((u8*)func_0019e7c0(0, 1), 1U);
            return;
        }
        temp_2_3 = func_0020ba90((s32)(*(u8**)(temp_3 + 0xDD4)), 2, temp_6);
        if (temp_2_3 != NULL) {
            temp_5_2 = (*(u8**)(temp_2_3 + 0x30));
            if ((*(u8*)(temp_5_2 + 0xA2)) == 1) {
                func_00194590((u8*)func_0019e550(NULL, temp_5_2, 1), 1U);
                func_00194590((u8*)func_0019e7c0((s32) (*(u8**)(temp_2_3 + 0x30)), 0), 1U);
                return;
            }
        }
        func_00194590((u8*)func_0019e7c0(0, 3), 1U);
        return;
    case 1:                                         /* switch 1 */
        temp_2_4 = (*(u8*)(((*(u16*)(arg0 + 0x6E)) * 0x28) + iGpffffb3b8 + 0x8));
        if ((temp_2_4 != 2) && (temp_2_4 != 1)) {
            temp_2_5 = func_0020ba60((s32)(*(u8**)(iGpffffb3ac + 0xDD4)), 2, temp_6);
            (*(u8**)(arg0 + 0x38)) = (u8*)temp_2_5;
            (*(u16*)(arg0 + 0x6A)) = 1U;
            func_001d8be0(arg0 + 0x98, temp_2_5);
        } else {
            var_4 = 0;
loop_28:
            temp_3_2 = (*(u16*)(arg0 + 0xD0));
            if ((var_4 & 0xFFFF) < (s32) temp_3_2) {
                temp_3_3 = arg0 + ((var_4 & 0xFFFF) * 4);
                (*(u8**)(temp_3_3 + 0x38)) = (u8*)(s32)(*(s32*)(temp_3_3 + 0x98));
                var_4 = (var_4 + 1) & 0xFFFF;
                goto loop_28;
            }
            (*(u16*)(arg0 + 0x6A)) = temp_3_2;
        }
        temp_3_4 = (*(u16*)(arg0 + 0x6C));
        switch (temp_3_4) {                         /* switch 2; irregular */
        case 2:                                     /* switch 2 */
        case 1:                                     /* switch 2 */
            var_4_2 = func_001faf70(arg0, (s32) (*(u16*)(arg0 + 0x6E)), 0) & 0xFFFF;
            break;
        case 3:                                     /* switch 2 */
            var_4_2 = func_001faf70(arg0, (s32) (*(u16*)(arg0 + 0x6E)), 1) & 0xFFFF;
            break;
        default:                                    /* switch 2 */
            var_4_2 = 0;
            break;
        }
        temp_16_2 = (s64) (func_001fb170(var_4_2) << 0x30) >> 0x30;
        if (temp_16_2 != 0) {
            func_0045af60(0, 0xF, 0, 8);
            func_002019f0((*(u8**)(arg0 + 0x30)), temp_16_2);
            func_0020ba30((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            return;
        }
        if ((*(u16*)(arg0 + 0x6C)) != 4) {
            (*(u16*)(arg0 + 0x18)) = (u16) ((*(u16*)(arg0 + 0x18)) | 2);
            func_00212040((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00216ca0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_0020bac0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_002038c0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00213c40((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            var_2_2 = (*(u8**)(iGpffffb3ac + 0x174));
loop_45:
            if (var_2_2 != NULL) {
                var_2_2 = (*(u8**)(var_2_2 + 0x450));
                goto loop_45;
            }
            func_001b0800(arg0, 0xF);
            return;
        }
        func_0020bac0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        func_00203880((s32)(*(u8**)(iGpffffb3ac + 0xDD4)), (s32)(*(u8**)(arg0 + 0x38)));
        func_001b0800(arg0, 5);
        return;
    case 2:                                         /* switch 1 */
        func_00194590((u8*)func_0019e7c0(0, 1), 1U);
        func_0020bac0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        func_00213c10((*(u8**)(iGpffffb3ac + 0xDD4)));
        func_00204d50((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        func_002037b0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        func_001b0800(arg0, 5);
        /* fallthrough */
    case 3:                                         /* switch 1 */
        return;
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a1ea0);
#endif
// FUN_001A24A0
void func_001a24a0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x41c) = 1;
}
// FUN_001A24B0 NONMATCHING
/* measured 001a24b0: 346 differing words guarded via `python3 tools/measure_guarded.py src/promoted/code1_001a.c func_001a24b0` (GUARDED_SCORE 346); probe 346 via `python3 tools/probe_variants.py src/promoted/code1_001a.c func_001a24b0 --candidate f=/tmp/cand_24b0f.c`; fnalign retail 392 vs object 404 instrs (1616B/1568B, 3.1% over), 522 edits (+5 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_001a.c func_001a24b0 --candidate /tmp/cand_24b0f.c --quiet`. Levers copied: block-scope loop counters (shared s32 k across disjoint loops claims saved reg; separate k per loop), compare operand order decides load order (cand != base emits word first as retail), if/else descending 4/3/2/1 beats switch (347/411 vs 346/404), opt_common_subs off hurts here (376/439) so none installed, redundant (flag & 0xFFFF) removal saves 4 instrs (408->404). Extern audit: func_00193cd0(u32)->u32 (bnez $v0), func_001d3700(u16,u16)->BtlPacket* (daddu $v0), func_00194590(u8*,u32)->s32 (return ignored, kept file decl), func_0019bbe0/bdd0/bd00 (u8*, correct widths; (u32)-1 for -1, 0xFFFFFF for case1 else), func_002186c0(u8*,s32) needs (u8**) cast on task (illegal implicit conversion otherwise), D_008C024E as D_008C024C[1] (only D_008C024C registered, +2 bytes). Frame 0x40, saves s16-s18/ra; dispatch reuses $4=3 into case1 call (if/else preserves carry, switch does not). 1 instr over 3% threshold (404 vs 403); banked as honest floor for next agent to shave. */
#ifdef NON_MATCHING
void func_001a24b0(u8 *arg0)
{
    extern u16 D_008C024C[];
    extern s32 func_0045af60();
    s32 state;


    if (func_00193cd0(0x800) != 0) {
        return;
    }
    state = *(s32 *)(arg0 + 0x41C);
    if (state == 4) {
        u8 *var_17;
        u8 *temp_2;
        func_001f9a90();
        var_17 = *(u8 **)(D_0076449C + 0x174);
        while (var_17 != NULL) {
            if ((*(u16 *)(var_17 + 0x1A) & 1) != 0 && (*(u16 *)(var_17 + 0x1A) & 0x400) == 0) {
                if (arg0 == var_17) {
                    temp_2 = func_0019bd00(*(u8 **)(var_17 + 0x30));
                } else {
                    temp_2 = func_0019bbe0(*(u8 **)(var_17 + 0x30), (u32)-1, 0, 0, 3, 0);
                }
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 0);
            }
            var_17 = *(u8 **)(var_17 + 0x450);
        }
        func_00213bb0(*(s32 *)(D_0076449C + 0xDD4));
        func_00218700(*(s32 *)(D_0076449C + 0xDD4));
        func_001b0800(arg0, *(u16 *)(arg0 + 0x14));
        *(s32 *)(arg0 + 0x41C) = 0;
        return;
    } else if (state == 3) {
        u16 flag = D_008C024C[1];
        if (((flag & 8) != 0) || ((flag & 4) != 0)) {
            u8 *base38;
            s32 curD2;
            s32 limD0;
            base38 = *(u8 **)(arg0 + 0x38);
            curD2 = (s32)(s16)*(u16 *)(arg0 + 0xD2);
            limD0 = *(u16 *)(arg0 + 0xD0);
            if ((flag & 8) != 0) {
                s32 idx = curD2;
                s32 lim = limD0;
                while ((s32)(s16)idx < lim) {
                    u8 *cand = *(u8 **)(arg0 + ((s32)(s16)idx * 4) + 0x98);
                    if (*(u16 *)(*(u8 **)(cand + 0x30) + 0xA4) != *(u16 *)(*(u8 **)(base38 + 0x30) + 0xA4)) {
                        break;
                    }
                    idx = (s32)(s16)(idx + 1);
                }
                if (lim == (s32)(s16)idx) {
                    idx = 0;
                    while ((s32)(s16)idx < (s32)flag) {
                        u8 *cand = *(u8 **)(arg0 + ((s32)(s16)idx * 4) + 0x98);
                        if (*(u16 *)(*(u8 **)(cand + 0x30) + 0xA4) != *(u16 *)(*(u8 **)(base38 + 0x30) + 0xA4)) {
                            break;
                        }
                        idx = (s32)(s16)(idx + 1);
                    }
                }
                if ((s32)flag != (s32)(s16)idx) {
                    func_0045af60(0, 0, 0, 5);
                    *(u8 **)(arg0 + 0x38) = *(u8 **)(arg0 + ((s32)(s16)idx * 4) + 0x98);
                    *(u16 *)(arg0 + 0xD2) = (u16)idx;
                    func_002186c0(*(u8 **)(D_0076449C + 0xDD4), *(s32 *)(arg0 + 0x38));
                }
                return;
            } else {
                s32 idx = curD2;
                while ((s32)(s16)idx >= 0) {
                    u8 *cand = *(u8 **)(arg0 + ((s32)(s16)idx * 4) + 0x98);
                    if (*(u16 *)(*(u8 **)(cand + 0x30) + 0xA4) != *(u16 *)(*(u8 **)(base38 + 0x30) + 0xA4)) {
                        break;
                    }
                    idx = (s32)(s16)(idx - 1);
                }
                if ((s32)(s16)idx < 0) {
                    idx = (s32)(s16)(limD0 - 1);
                    while ((s32)flag < (s32)(s16)idx) {
                        u8 *cand = *(u8 **)(arg0 + ((s32)(s16)idx * 4) + 0x98);
                        if (*(u16 *)(*(u8 **)(cand + 0x30) + 0xA4) != *(u16 *)(*(u8 **)(base38 + 0x30) + 0xA4)) {
                            break;
                        }
                        idx = (s32)(s16)(idx - 1);
                    }
                }
                if ((s32)flag != (s32)(s16)idx) {
                    func_0045af60(0, 0, 0, 5);
                    *(u8 **)(arg0 + 0x38) = *(u8 **)(arg0 + ((s32)(s16)idx * 4) + 0x98);
                    *(u16 *)(arg0 + 0xD2) = (u16)idx;
                    func_002186c0(*(u8 **)(D_0076449C + 0xDD4), *(s32 *)(arg0 + 0x38));
                }
                return;
            }
        } else if (((flag & 0x40) != 0) || ((flag & 0x20) != 0)) {
            func_0045af60(0, 0, 0, 4);
            if (func_001eb860() == 1) {
                *(s32 *)(D_0076449C + 0xC) |= 0x2000;
                func_00212240(*(u8 **)(D_0076449C + 0xDD4), 0);
            }
            *(s32 *)(arg0 + 0x41C) = 4;
            return;
        }
        return;
    } else if (state == 2) {
        if (func_00218690(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            u8 *slot = *(u8 **)(*(u8 **)(arg0 + 0x38) + 0x30);
            if (slot != NULL) {
                s32 v = func_001f62f0(slot);
                if (v >= 0) {
                    func_001f9a50((u16)v, 1);
                }
            }
            *(s32 *)(arg0 + 0x41C) = 3;
        }
        return;
    } else if (state == 1) {
        u8 *pkt;
        u8 *var_17;
        u8 *temp_2;
        pkt = (u8 *)func_001d3700(3, 0xFFF);
        *(s64 *)(pkt + 0x60) = *(s64 *)arg0;
        func_00194590(pkt, 0);
        var_17 = *(u8 **)(D_0076449C + 0x174);
        while (var_17 != NULL) {
            if ((*(u16 *)(var_17 + 0x1A) & 1) != 0) {
                if (arg0 == var_17 || (*(u16 *)(var_17 + 0x1A) & 8) == 0) {
                    temp_2 = func_0019bdd0(*(u8 **)(var_17 + 0x30));
                } else {
                    temp_2 = func_0019bbe0(*(u8 **)(var_17 + 0x30), 0xFFFFFF, 8, 0, 4, 0);
                }
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 0);
            }
            var_17 = *(u8 **)(var_17 + 0x450);
        }
        {
            u8 *base38 = *(u8 **)(arg0 + 0x38);
            s32 var_18;
            s32 i;
            func_001d7c60(arg0, arg0 + 0x98, 2, 0, 0);
            var_18 = 0;
            *(u16 *)(arg0 + 0xD2) = *(u16 *)(arg0 + 0xD0);
            i = 0;
            while ((i & 0xFFFF) < *(u16 *)(arg0 + 0xD0)) {
                if (*(u8 **)(arg0 + ((i & 0xFFFF) * 4) + 0x98) == base38) {
                    *(u16 *)(arg0 + 0xD2) = (u16)i;
                }
                if (*(u16 *)(*(u8 **)(*(u8 **)(arg0 + ((i & 0xFFFF) * 4) + 0x98) + 0x30) + 0xA4) != *(u16 *)(*(u8 **)(base38 + 0x30) + 0xA4)) {
                    var_18 = 1;
                }
                i = (i + 1) & 0xFFFF;
            }
            func_00213be0(*(s32 *)(D_0076449C + 0xDD4));
            func_00218560(*(u8 **)(D_0076449C + 0xDD4), base38);
            if (var_18 != 0) {
                func_00218730(*(s32 *)(D_0076449C + 0xDD4));
            }
            func_001a03b0((s64 *)arg0);
            temp_2 = func_001bc920(base38, 1);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 0);
            func_001f62b0();
            func_001f86d0();
            if (func_001eb860() == 1) {
                *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
                func_00212240(*(u8 **)(D_0076449C + 0xDD4), 0);
            }
            *(s32 *)(arg0 + 0x41C) = 2;
        }
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a24b0);
#endif
// FUN_001A2AD0
void func_001a2ad0(u8 *arg0) {
    func_001eb3b0(arg0 + 0x38);
    if ((*(s32 *)(D_0076449C + 0xC) & 0x1000) == 0) {
        return;
    }
    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return;
    }
    if (*(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return;
    }
    func_001b0800(arg0, 9);
}

// FUN_001A2B50
void func_001a2b50(u8 *arg0)
{
    s32 temp_3;

    if (func_001deeb0(arg0 + 0x38) == 0) {
        func_001ded30(arg0, arg0 + 0x38);
    }
    if (func_001deee0(arg0 + 0x38) != 0) {
        temp_3 = *(s32 *)(D_0076449C + 0xC);
        if ((temp_3 & 0x1000) &&
            (temp_3 & 0x04000000) &&
            (*(u8 **)(arg0 + 0x30))[0xA2] == 1) {
            *(u16 *)(arg0 + 0x18) |= 0x4000;
        }
        *(u16 *)(arg0 + 0x18) |= 2;
        func_001b0800(arg0, 0xF);
    }
}
// FUN_001A2C10
void func_001a2c10(s64 *arg0) {
    func_001eb3b0((u8 *)arg0 + 0x38);
    func_001d7f10(arg0, (u8 *)arg0 + 0x98, 0, 0);
    func_001d8cb0(NULL, arg0 + 0x13);
}



// FUN_001A2C70
void func_001a2c70(u8 *arg0)
{
    u8 *temp_3;

    *(s16 *)(arg0 + 0x6C) = 1;
    *(s16 *)(arg0 + 0x6E) =
        func_0023dfe0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    *(s32 *)(arg0 + 0x38) = func_001d8bc0(arg0 + 0x98);
    *(s16 *)(arg0 + 0x6A) = 1;
    func_001d8be0(arg0 + 0x98, *(s32 *)(arg0 + 0x38));
    temp_3 = *(u8 **)(arg0 + 0x30);
    if ((temp_3[0xA2] == 0) && (*(u16 *)(temp_3 + 0xA4) == 1)) {
        func_00194590(func_001f5f70(arg0, 1, 0, 0, 0), 1);
    }
    if (*(s32 *)(D_0076449C + 0xC) & 0x04000000) {
        *(u16 *)(arg0 + 0x18) |= 0x4000;
    }
    *(u16 *)(arg0 + 0x18) |= 2;
    func_001b0800(arg0, 0xF);
}
// FUN_001A2D60
void func_001a2d60(void)
{
}
/* MATCHED: 1072 bytes of code and the 64-byte table at 0x00746FD0 resolve
   exactly.  This is D_005f6e20[10].update, a void action callback, so the
   packet UID that func_00194590 returns is discarded here.  The u8
   conversion plus the explicit signed guard reproduce retail's redundant
   `bltz` range check - the two words an earlier pass could not place -
   and opt_propagation off with opt_common_subs off keep that lowering
   together with the repeated `*(u8 **)(unit + 0xA64)` loads that retail
   reloads rather than folding. */
// FUN_001A2D70
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_001a2d70(u8 *arg0) {
    extern void func_001b0800(u8 *, u16);
    extern u8 *func_001bc920(u8 *, u16);

    s32 state;
    s32 kind;
    u8 *unit;
    u8 *packet;

    void func_00233880(u8 *arg0, s32 arg1);
    u8 *func_00202400(s32 arg0, s32 arg1);

    if (func_00193cd0(0x506) == 0) {
        unit = *(u8 **)((u8 *)arg0 + 0x30);
        kind = (u8)func_00235320(*(u8 **)(unit + 0xA64));
        if (kind < 0) {
            goto fallback;
        }
        switch (kind) {
        case 0:
        case 1:
            if (unit[0xA2] == 0) {
                state = 30;
            } else {
                state = 31;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 0);
            func_00233880(*(u8 **)(unit + 0xA64), 1);
            break;
        case 2:
        case 4:
            if (unit[0xA2] == 0) {
                state = 32;
            } else {
                state = 33;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 4);
            func_00233880(*(u8 **)(unit + 0xA64), 2);
            break;
        case 3:
            if (unit[0xA2] == 0) {
                state = 34;
            } else {
                state = 35;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 3);
            break;
        case 5:
            if (unit[0xA2] == 0) {
                state = 36;
            } else {
                state = 37;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 5);
            break;
        case 6:
            if (unit[0xA2] == 0) {
                state = 38;
            } else {
                state = 39;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 6);
            break;
        case 7:
            if (unit[0xA2] == 0) {
                state = 40;
            } else {
                state = 41;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 7);
            break;
        case 8:
            if (unit[0xA2] == 0) {
                state = 80;
            } else {
                state = 81;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 8);
            break;
        case 9:
            if (unit[0xA2] == 0) {
                state = 82;
            } else {
                state = 83;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 9);
            break;
        case 10:
            if (unit[0xA2] == 0) {
                state = 84;
            } else {
                state = 85;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 10);
            break;
        case 11:
            if (unit[0xA2] == 0) {
                state = 86;
            } else {
                state = 87;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 11);
            break;
        case 12:
            if (unit[0xA2] == 0) {
                state = 130;
            } else {
                state = 131;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 12);
            break;
        case 13:
            if (unit[0xA2] == 0) {
                state = 132;
            } else {
                state = 133;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 13);
            break;
        case 14:
            if (unit[0xA2] == 0) {
                state = 134;
            } else {
                state = 135;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 14);
            break;
        case 15:
            if (unit[0xA2] == 0) {
                state = 136;
            } else {
                state = 137;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 15);
            break;
        default:
            state = 0;
            break;
        }
        if (state != 0) {
            func_001a03b0((s64 *)arg0);
            packet = func_001bc920((u8 *)arg0, 10);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            func_00194590(packet, 0);
            packet = func_00202400(*(s32 *)((u8 *)arg0 + 0x30), (s32)state);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            func_00194590(packet, 3);
        } else {
fallback:
            if (func_001f6770((u8 *)arg0) != 0) {
                func_001b0800((u8 *)arg0, 11);
            } else {
                func_001b0800((u8 *)arg0, 3);
            }
        }
    }
}
#pragma pop
// FUN_001A31A0
void func_001a31a0(u8 *arg0)
{
    func_001f6cd0();
    *(s32 *)(arg0 + 0x41C) = 1;
    *(s32 *)(arg0 + 0x420) = 0;
}
/* measured 001a31e0: `opt_common_subs off` inside the guard is worth 36 words (330 -> 294); retail rematerialises what b210 hoists. s64 temp_17 (honest: eb4a0 takes s64) deletes the s32->s64 extension pair (294 -> 278); s32 t214/t216 pin downstream coloring, ruled out (326 each). Banked as floor (278). */
// FUN_001A31E0 NONMATCHING
#ifdef SKIP_ASM
#pragma opt_common_subs off
void func_001a31e0(u8 *arg0) {
    u8 *func_00202400(s32 arg0, s32 arg1);
    u8 *func_0019a980(u8 *arg0);
    s32 sp6C;
    s32 sp60;
    s64 temp_17;
    s32 var_17;
    s32 var_5;
    u8 *temp_2;

    if ((func_00193cd0(0x506) == 0) && (func_00193cd0(0x105) == 0)) {
        func_001a03b0((s64 *)arg0);
        temp_17 = func_002326e0(*(s32 *)(*(u8 **)arg0 + 0xA64));
        if ((func_00232710(*(s32 *)(*(u8 **)arg0 + 0xA64), 0x100000) != 0) && (*(s32 *)(arg0 + 0x420) == 0)) {
            var_17 = 1;
            if ((func_00232710(*(s32 *)(*(u8 **)arg0 + 0xA64), 1) != 0) && (func_001f6bf0(arg0) == 0)) {
                var_17 = 0;
            }
            if (var_17 != 0) {
                temp_2 = (u8 *)func_001bc920(arg0, 0x31);
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 0);
                if (*(s32 *)(*(u8 **)iGpffffb3ac + 0x0C) & 0x200000) {
                    u8 *t22;
                    func_00194ff0(*(u8 **)arg0, NULL, 0, (f32 *)&sp60);
                    t22 = (u8 *)func_00197f50(*(u8 **)arg0, (u8 *)&sp60, 2);
                    *(s64 *)(t22 + 0x60) = *(s64 *)arg0;
                    func_00194590(t22, 0);
                }
                {
                    s32 t3 = *(s32 *)(*(u8 **)iGpffffb3ac + 0x0C);
                    u32 f12v;
                    s16 v18;
                    s16 v172;
                    if ((t3 & 0x1000) && (t3 & 0x04000000)) {
                        f12v = 0x3FE00000;
                        v18 = 0x0C;
                        v172 = 4;
                    } else {
                        f12v = 0x3F800000;
                        v18 = 0x1E;
                        v172 = 8;
                    }
                    temp_2 = (u8 *)func_00199ee0(*(u8 **)arg0, 0x0B, 0, 0, *(f32 *)&f12v);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    *(s16 *)(temp_2 + 0x48) = v18;
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 0);
                    temp_2 = (u8 *)func_001f99c0(arg0, 3, 0, 0, 0);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    func_00194590(temp_2, 1);
                    func_001f0a10((u8 *)&sp60);
                    sp6C = 0x100001;
                    temp_2 = (u8 *)func_001f36e0((s32)arg0, (s32)arg0, &sp60, 1, 1);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 1);
                    temp_2 = (u8 *)func_0019a980(*(u8 **)arg0);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    *(s16 *)(temp_2 + 0x4A) = v172;
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 0);
                    temp_2 = (u8 *)func_001f5f70(arg0, 0x11, 0, 0, 0);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 1);
                    *(s32 *)(arg0 + 0x41C) = 1;
                }
            } else {
                temp_2 = (u8 *)func_001bc920(arg0, 0x0A);
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 0);
                temp_2 = (u8 *)func_001f5f70(arg0, 0x12, 0, 0, 0);
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 1);
                {
                    u8 *t4 = *(u8 **)arg0;
                    if (*(t4 + 0xA2) == 0) {
                        var_5 = 0x68;
                    } else {
                        var_5 = 0x69;
                    }
                    temp_2 = (u8 *)func_00202400((s32)t4, var_5);
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 3);
                    *(s32 *)(arg0 + 0x41C) = 0;
                }
            }
            func_00194590(func_0019e550(NULL, *(u8 **)arg0, 1), 1);
            func_00194590(func_0019e7c0((s32)*(u8 **)arg0, 0), 1);
            *(u16 *)(arg0 + 0x18) |= 0x200;
            *(s32 *)(arg0 + 0x420) = 1;
            return;
        }
        {
            s32 t211 = func_001f6930(arg0);
            if (t211 != 0) {
                temp_2 = (u8 *)func_001bc920(arg0, 0x0A);
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 0);
                func_001f0a10((u8 *)&sp60);
                sp6C = t211;
                temp_2 = (u8 *)func_001f36e0((s32)arg0, (s32)arg0, &sp60, 1, 1);
                *(s16 *)(temp_2 + 0x48) = 0x12;
                func_00194590(temp_2, 1);
                {
                    s16 t214 = (s16)func_001f7140(arg0);
                    if (t214 > 0) {
                        temp_2 = (u8 *)func_00202400((s32)*(u8 **)arg0, t214);
                        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                        func_00194590(temp_2, 3);
                    }
                }
                return;
            }
        }
        if (*(s32 *)(arg0 + 0x41C) != 0) {
            if (temp_17 & 0x116) {
                func_001eb4a0(arg0, arg0 + 0x38, (s64)temp_17);
                *(u16 *)(arg0 + 0x18) |= 2;
                {
                    s16 t216 = (s16)func_001f6f60(arg0);
                    if (t216 > 0) {
                        temp_2 = (u8 *)func_001bc920(arg0, 0x0A);
                        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                        func_00194590(temp_2, 0);
                        temp_2 = (u8 *)func_00202400((s32)*(u8 **)arg0, t216);
                        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                        func_00194590(temp_2, 3);
                    }
                }
                temp_2 = (u8 *)func_001f5f70(arg0, 0x1E, 0, 0, 0);
                *(s16 *)(temp_2 + 0x48) = 0x18;
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 1);
                func_001b0800(arg0, 0x0F);
                return;
            }
            func_001b0850(arg0, 3, 1);
            return;
        }
        func_001eb3b0(arg0 + 0x38);
        *(u16 *)(arg0 + 0x18) &= 0xFFF7;
        if (func_001f68e0(arg0) != 0) {
            func_001b0800(arg0, 0x1B);
            return;
        }
        func_001b0800(arg0, 0x20);
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a31e0);
#endif
/* measured 001a3840: `opt_common_subs off` inside the guard is worth 6 words (279 -> 273); retail rematerialises what b210 hoists. s32 st (275) and s32 spB0 (274) ruled out: the extension pairs pin downstream rotation coloring. Banked as floor (273). */
// FUN_001A3840 NONMATCHING
#ifdef SKIP_ASM
#pragma opt_common_subs off
void func_001a3840(u8 *arg0)
{
    u8 *t20;
    s16 st;
    s32 spC0;
    f32 f20;
    s16 spB0;
    s32 v18;
    s32 v19;
    s32 v21;
    s32 v22;
    s32 v23;
    u8 *pkt;

    t20 = *(u8 **)(arg0 + 1092);
    st = *(s16 *)(arg0 + 1096);
    if (st == 0) {
    } else if (st == 1) {
        spC0 = 0x100001;
        v18 = 27;
        v19 = 0;
        {
            f32 a = *(f32 *)(*(u8 **)(arg0 + 48) + 44);
            f32 b = *(f32 *)(*(u8 **)(arg0 + 48) + 144);
            f32 c = *(f32 *)(*(u8 **)(t20 + 48) + 44);
            f32 d = *(f32 *)(*(u8 **)(t20 + 48) + 144);
            f20 = 50.0f + (a * b + c * d);
        }
        spB0 = -1;
        v23 = 14;
        v22 = arg0[0] & 0xFFFF;
        v21 = 12;
        *(u16 *)(arg0 + 26) = *(u16 *)(arg0 + 26) | 0x800;
    } else {
        spC0 = 30;
        v18 = 29;
        f20 = 50.0f + func_00196bd0(*(u8 **)(arg0 + 48), *(u8 **)(t20 + 48), 29);
        v19 = func_001991c0(*(u8 **)(arg0 + 48), 29, 1.0f) & 0xFFFF;
        v23 = 15;
        spB0 = 40;
        v22 = 0;
        v21 = 10;
        *(u16 *)(arg0 + 26) = *(u16 *)(arg0 + 26) | 0x1000;
    }
    func_001a03b0((s64 *)arg0);
    func_001eb410(arg0 + 56);
    *(u8 **)(arg0 + 56) = t20;
    *(s16 *)(arg0 + 106) = 1;
    if ((v22 & 0xFFFF) != 0) {
        pkt = func_001f99c0(arg0, v22, *(u16 *)(*(u8 **)(t20 + 48) + 164), 0, 0);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 1);
    }
    if ((*(s32 *)(iGpffffb3ac + 12) & 0x200000) == 0) {
        pkt = func_001bc920(arg0, 25);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
        pkt = func_001979e0(*(u8 **)(arg0 + 48), *(u8 **)(t20 + 48), 10, f20, fGpffff811c);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
    } else {
        pkt = func_00194b60();
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
    }
    pkt = func_002022e0(*(u32 *)(arg0 + 48), v23);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 3);
    pkt = func_001d3530(*(u8 **)(arg0 + 48), *(u8 **)(t20 + 48), v22);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    pkt = func_001bc920(arg0, 42);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    if ((v21 & 0xFFFF) != 0) {
        pkt = func_001f99c0(arg0, v21, *(u16 *)(*(u8 **)(t20 + 48) + 164), 0, 0);
        *(pkt + 0) = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 1);
    }
    pkt = func_00199ee0(*(u8 **)(arg0 + 48), v18, 0, 0, 1.0f);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    *(s16 *)(pkt + 74) = func_00199500(*(u8 **)(arg0 + 48), v18, 1.0f);
    func_00194590(pkt, 0);
    pkt = func_00199ee0(*(u8 **)(t20 + 48), v19, 0, 0, 1.0f);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    *(s16 *)(pkt + 72) = v19;
    func_00194590(pkt, 0);
    if (spB0 != -1) {
        pkt = (u8 *)func_001d6240(*(u32 *)(*(u8 **)((u8 *)iGpffffb3ac + spB0 * 4 + 3332)), (u32)*(u8 **)(arg0 + 48), (u32)*(u8 **)(t20 + 48), 1, 0);
        *(pkt + 0) = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        *(s16 *)(pkt + 72) = v19;
        func_00194590(pkt, 2);
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a3840);
#endif
// FUN_001A3D50
void func_001a3d50(s64 *arg0)
{
    if (func_00193bf0(*arg0, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        *(s16 *)((u8 *)arg0 + 0x448) = -1;
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 7;
        func_001b0800(arg0, 0x20);
    }
}
// FUN_001A3DE0
s32 func_001a3de0(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x420);
}

// FUN_001A3DF0
void func_001a3df0(u8 *arg0)
{
    s32 status;
    u8 *iter;
    u8 *temp;
    s64 *current;

    iter = *(u8 **)(D_0076449C + 0x174);
    goto loop_test;
loop_body:
    if (func_001a05f0(iter) != 0) {
        temp = func_0019b6a0((s32)*(u8 **)(*(u8 **)(iter + 0x30) + 0xA0C));
        *(s64 *)(temp + 0x60) = *(s64 *)iter;
        func_00194590(temp, 1);
    }
    iter = *(u8 **)(iter + 0x450);
loop_test:
    if (iter != NULL) {
        goto loop_body;
    }
    status = 1;
    current = func_001b1540();
    if ((*(u16 *)((u8 *)current + 0x18) & 8) != 0 &&
        func_0019ff60((u8 *)current) != 0) {
        status = 0;
    }
    if (status == 1) {
        status = func_001d94d0(
            arg0,
            func_0023d8e0(
                *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64),
                func_001f01a0(arg0, *(s32 *)(arg0 + 0x90)) & 0xFFFF) & 0xFFFF,
            2, 0x80000, 2, func_001db5e0);
    }
    if (status == 0) {
        temp = func_001fa9c0();
        *(s64 *)(temp + 0x60) = *(s64 *)arg0;
        func_00194590(temp, 1);
        func_001b0800(arg0, 0x20);
        return;
    }
    if (func_001eb860() == 1) {
        *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
        func_00212240(*(u8 **)(D_0076449C + 0xDD4), 0);
    }
    *(s32 *)(arg0 + 0x41C) = 0;
    *(s32 *)(arg0 + 0x420) = 0;
}
// FUN_001A3F90
void func_001a3f90(u8 *arg0)
{
    u8 frame[0x10];
    struct {
        u8 pad[0x30];
        s32 field_30;
    } *temp_2;
    s64 *temp_2_4;
    u16 temp_3_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_3;

    if (*(s32 *)(arg0 + 0x41C) == 0) {
        if ((func_00193cd0(0xC00) == 0) && (func_00193cd0(0xC04) == 0)) {
            *(s16 *)(frame + 0) = 2;
            *(u16 *)(frame + 2) =
                *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
            func_00194590(func_001fa110(frame), 1);
            func_001a03b0((s64 *)arg0);
            func_00194590(func_00202850(), 1);
            func_00194590(func_001fa8f0(), 1);
            func_002182c0(*(u8 **)(D_0076449C + 0xDD4), (u8 *)arg0);
            func_00194590((u8 *)func_001d3700(3, 0xFFF), 0);
            temp_2 = (void *)func_001b1540();
            func_00194590(
                func_00198300((u8 *)temp_2->field_30,
                              *(u8 **)(arg0 + 0x30), 2),
                0);
            func_00194590(
                func_00198300(*(u8 **)(arg0 + 0x30),
                              (u8 *)temp_2->field_30, 2),
                0);
            func_00194590(
                func_0019e7c0(temp_2->field_30, 0),
                1);
            func_00194590(
                func_0019e550(*(u8 **)(arg0 + 0x30),
                              (u8 *)temp_2->field_30, 0),
                1);
            func_00194590(func_001bc920((u8 *)arg0, 0x30), 0);
            temp_2_2 = func_00194c90((s32)func_001a3de0, (s32)arg0);
            func_00194590(temp_2_2, 1);
            func_00194590(
                func_001d65d0(*(s32 *)(D_0076449C + 0xD90),
                              *(s32 *)(arg0 + 0x30), 0,
                              *(s64 *)(temp_2_2 + 0x58), 0xC000),
                2);
            if (func_001eb860() == 1) {
                *(s32 *)(D_0076449C + 0xC) |= 0x2000;
                func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
            }
            *(s32 *)(arg0 + 0x41C) = 1;
        }
    } else if (*(s32 *)(arg0 + 0x420) == 0) {
        if (func_00218360(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
            if (func_00218390(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
                func_00194590(func_001f99c0((u8 *)arg0, 8, 0, 0, 0), 1);
                temp_2_3 = func_001fa450();
                *(s8 *)(temp_2_3 + 0) = 0xA;
                *(s16 *)(temp_2_3 + 8) = 0xC00;
                *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2_3, 1);
                func_00194590(func_002027e0(), 1);
            }
            func_00194590(func_001faa60(), 1);
            *(s32 *)(arg0 + 0x420) = 1;
            *(u16 *)(arg0 + 0x424) = 6;
        }
    } else {
        temp_3_2 = *(u16 *)(arg0 + 0x424);
        if (temp_3_2 == 0) {
            func_00194590(func_0019e7c0(0, 3), 1);
            if (func_00218390(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
                temp_2_4 = func_001b1540();
                func_00194590(func_001f3870(temp_2_4, 2), 1);
                *(u16 *)((u8 *)temp_2_4 + 0x18) |= 0x8000;
                func_001b0800((u8 *)arg0, 0xE);
            } else {
                func_001b0800((u8 *)arg0, 0x20);
            }
            func_002183c0(*(s32 *)(D_0076449C + 0xDD4));
            return;
        }
        *(u16 *)(arg0 + 0x424) = temp_3_2 - 1;
    }
}
// FUN_001A4390
void func_001a4390(void)
{
}

/* measured 001a43a0: live object 1092B/window 1104B, normalized_diff 161 (guard below; fnalign 273/273 instrs, 83 edits). `opt_loop_invariants on` inside the guard is worth 56 words (218 -> 162), the loop-preheader constant hoist; `temp_18 > 1` for `>= 2` fixes the slti destination to $at (162 -> 161). Remainder is a self-consistent 5-cycle saved-register rotation (banked wall) plus the s16-slot sh/lh pair (retail sh + lh vs this build sign-extend + sw + lw). Ruled out today: volatile s16 spB0 (219), u16 res23 (215), s16 res23 (163, neutral), s32 spB0 (219), opt_common_subs off (223). Banked as floor. */
// FUN_001A43A0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_001a43a0(u8 *arg0) {
    extern u8 *func_001fa320(void);
    extern s32 func_001a05f0(u8 *arg0);
    extern s32 func_001d7f10(void *arg0, u8 *arg1, u16 arg2, u32 arg3);
    s32 spF0[12];
    s32 spC0[12];
    s16 spB0;
    u32 spA0;
    s32 temp_17;
    u16 temp_23;
    s32 var_30;
    s32 var_18;
    s32 var_19;
    s32 var_20;
    u8 *temp_16;
    u8 *temp_22;
    s32 temp_22_2;
    s32 temp_3;
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    s32 temp_4_2;
    s32 var_16;
    u8 *temp_2_4;
    s32 var_16_2;
    u8 *temp_2_5;
    u8 *temp_2_6;
    s32 temp_4;
    s32 temp_18;
    s32 var_7;
    s32 temp_3_2;
    s32 bound19;
    u8 *copyDst;
    s32 res23;

    if (func_00193cd0(0xC00) == 0) {
        temp_17 = *(s32 *)(arg0 + 0x90);
        temp_23 = func_001f01a0(arg0, temp_17) & 0xFFFF;
        spA0 = func_001d7f10(arg0, arg0 + 0x98, temp_23, 0) & 0xFFFF;
        res23 = func_0023d8e0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), temp_23);
        var_30 = 0;
        var_19 = 0;
        var_18 = 0;
        var_20 = 0;
        spB0 = res23;
        for (var_20 = 0; (var_20 & 0xFFFF) < *(u16 *)(arg0 + 0xD0); var_20 = (var_20 + 1) & 0xFFFF) {
            temp_16 = *(u8 **)(arg0 + ((var_20 & 0xFFFF) * 4) + 0x98);
            if (*(u16 *)(temp_16 + 0x1A) & 1) {
                temp_22 = *(u8 **)(temp_16 + 0x30);
                if (func_002428f0(*(u8 **)(temp_22 + 0xA64), 0) == 0 &&
                    (s8)func_00233a90(*(u8 **)(temp_22 + 0xA64), 0x10) <= 0 &&
                    !(func_00242800(*(u8 **)(temp_22 + 0xA64), spB0) & 0x7000000)) {
                    if (func_00232710((s32)*(u8 **)(temp_22 + 0xA64), 0x100000) == 0) {
                        spC0[var_18 & 0xFFFF] = (s32)temp_16;
                        var_18 = (var_18 + 1) & 0xFFFF;
                    }
                    if (temp_17 == (s32)temp_16) {
                        var_30 = 1;
                    } else {
                        spF0[var_19 & 0xFFFF] = (s32)temp_16;
                        var_19 = (var_19 + 1) & 0xFFFF;
                    }
                }
            }
        }
        func_001eb3b0(arg0 + 0x38);
        *(s16 *)(arg0 + 0x6C) = 2;
        *(s16 *)(arg0 + 0x6E) = temp_23;
        if ((spA0 & 0xFFFF) == 0) {
        temp_4 = var_18 & 0xFFFF;
        if (temp_4 > 0) {
            *(s32 *)(arg0 + 0x38) = spC0[func_00231d70(temp_4)];
        } else if (var_30 != 0) {
            *(s32 *)(arg0 + 0x38) = temp_17;
        } else {
            *(s32 *)(arg0 + 0x38) = spF0[func_00231d70(var_19 & 0xFFFF)];
        }
        *(u16 *)(arg0 + 0x6A) = 1;
        } else {
            var_16 = 0;
            temp_18 = var_19 & 0xFFFF;
            var_20 = temp_18 * 3;
            for (var_16 = 0; (var_16 & 0xFFFF) < var_20; var_16 = (var_16 + 1) & 0xFFFF) {
                temp_22_2 = func_00231d70(temp_18) & 0xFFFF;
                temp_3 = func_00231d70(temp_18) & 0xFFFF;
                temp_2 = temp_22_2 & 0xFFFF;
                if (temp_2 != temp_3) {
                    temp_4_2 = spF0[temp_2];
                    spF0[temp_2] = spF0[temp_3];
                    spF0[temp_3] = temp_4_2;
                }
            }
            if (var_30 != 0) {
                *(s32 *)(arg0 + 0x38) = temp_17;
                *(u16 *)(arg0 + 0x6A) = 1;
                var_16_2 = 1;
            } else {
                *(u16 *)(arg0 + 0x6A) = 0;
                var_16_2 = 0;
            }
            if (temp_18 > 1) {
                if (temp_18 == 2) {
                    var_19 = 1;
                } else {
                    var_19 = (func_00231d70(temp_18 - 1) + 1) & 0xFFFF;
                }
            }
            bound19 = var_19 & 0xFFFF;
            copyDst = arg0 + ((var_16_2 & 0xFFFF) * 4);
            for (var_7 = 0; (var_7 & 0xFFFF) < bound19; var_7 = (var_7 + 1) & 0xFFFF) {
                *(s32 *)(copyDst + (var_7 & 0xFFFF) * 4 + 0x38) = spF0[var_7 & 0xFFFF];
            }
            *(u16 *)(arg0 + 0x6A) += var_19;
        }
        *(u16 *)(arg0 + 0x18) |= 2;
        temp_2_4 = func_001f99c0(arg0, 9, 0, 0, 0);
        *(s64 *)(temp_2_4 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_4, 1);
        temp_2_5 = func_001fa320();
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_5, 1);
        temp_2_6 = func_002027e0();
        *(s8 *)(temp_2_6 + 0) = 4;
        *(s64 *)(temp_2_6 + 0x58) = *(s64 *)(temp_2_5 + 0x58);
        func_00194590(temp_2_6, 1);
        func_001b0800(arg0, 0xF);
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a43a0);
#endif
// FUN_001A47F0
void func_001a47f0(void)
{
}

/* measured: live object 1164B/window 1152B, normalized_diff 219 (installed guard below; prior nd232 note at 1168B; object exceeds window by 12B). Restructured the scan loop per retail: bound check as the while condition (init + branch-over-to-test), skip-chain as separate early-outs to incr with the != 1 arm exiting to donecheck (goto-loop + OR-combined chain miscompiled the branch tree). Unmasked increment (232 -> 223 -> 219). Open walls: frame 0x60 vs 0x50, s-reg rotation, body-index mask folded away (unmasked counter proves it redundant; separate/temp/three-mask/O1 spellings all tie), slt stays signed per retail. Ruled out today: masked-incr while (223), three-mask tail temp (219 tie), O1 on both (223/219 ties). Banked as floor. */
/* measured 001a4800: opt_common_subs off (219 -> 174); byte-load at unit+0xA2 for word-then-byte (174 -> 163), u8 at +0x24 (163 -> 162), honest globals iGpffffb3b8 table base and temp_4=iGpffffb3ac for single gp loads (162 -> 107); u16 index kept (neutral, faithful); masked incr ruled out (+5/+16). Open: commutative addu order, cs-off remat reload, frame 0x60 vs 0x50. Banked as floor (107). */
// FUN_001A4800 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_001a4800(u8 *arg0)
{
    s32 temp_16;
    s32 var_16;
    s32 var_18;
    s32 var_2;
    u16 temp_2;
    u8 *temp_17;
    u8 *temp_4;
    if (((s32)(func_00193cd0(0x506)) == (s32)(0)) && ((s32)(func_00193cd0(0xC05)) == (s32)(0))) {
        var_18 = 0;
        while ((s32)(temp_16 = var_18 & 0xFFFF) < (s32)(*(u16 *)((u8 *)arg0 + 0x6A))) {
            temp_17 = (u8 *)((*(u8 **)((u8 *)(((s32)(arg0) + ((var_18 & 0xFFFF) * 4))) + 0x38)));
            if ((s32)(arg0) == (s32)(temp_17)) {
                goto incr;
            }
            if (!((*(u16 *)((u8 *)(temp_17) + 0x1A)) & 1)) {
                goto incr;
            }
            if (((s32)(func_002428f0((*(u8 **)((u8 *)((*(s32 *)((u8 *)(temp_17) + 0x30))) + 0xA64)), 0)) != (s32)(0))) {
                goto incr;
            }
            if ((*(u16 *)((u8 *)(temp_17) + 0xC)) != 1) {
                goto donecheck;
            }
incr:
            var_18 = var_18 + 1;
        }
donecheck:
        if (temp_16 == (*( u16*)((u8 *)(arg0) + 0x6A))) {
            if (!((*( u16*)((u8 *)(arg0) + 0x18)) & 4)) {
                func_001eb420((s32)(arg0) + 0x38);
            }
            (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFFD));
            var_16 = 0;
            temp_2 = (u16)((u16)((*( u16*)((u8 *)(arg0) + 0x6C))));
            switch (temp_2) {
            case 1:
            case 2:
            case 3:
                var_16 = 1;
                /* fallthrough */
            case 9:
                func_001f14f0(arg0);
                if ((*( u8*)((u8 *)((((*( u16*)((u8 *)(arg0) + 0x6E)) * 0x28) + (iGpffffb3b8))) + 0x24)) == 5) {
                    func_001b0800(arg0, 0x20U);
                } else if ((*( s32*)((u8 *)(arg0) + 0xE8)) == 1) {
                    func_001b0800(arg0, 0x17U);
                } else if ((s32)(func_0019fc70(arg0)) != (s32)(0)) {
                    (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFEF));
                    func_001b0800(arg0, 0x10U);
                } else {
                    (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) | 0x10));
                    func_001b0800(arg0, 0x11U);
                }
                break;
            case 7:
            case 8:
            case 11:
                func_001b0800(arg0, 0x19U);
                break;
            case 6:
                if ((s32)((*( u8*)((*( u8**)((u8 *)(arg0) + 0x30)) + 0xA2))) == (s32)(0)) {
                    if ((s32)(func_00106330(0x38)) != (s32)(0)) {
                        var_2 = 5;
                    } else {
                        var_2 = 8;
                    }
                    if (((s32)(func_0010ce10(func_0010a900(var_2 & 0xFFFF), 0x114)) != (s32)(-1)) || ((temp_4 = (iGpffffb3ac), ((*( u16*)((u8 *)(temp_4) + 0x1A)) == 1)) && ((*( u16*)((u8 *)(temp_4) + 0x290)) & 2))) {
                        func_00194590(func_001f5f70(arg0, 8, 0, 0, 3), 1);
                        func_00194590(func_001bc920(arg0, 8), 0);
                        func_001b0850(arg0, 0x1D, 0xC);
                    } else {
                        func_001f5bd0(0);
                        func_00194590(func_001f5f70(arg0, 3, 0, 0, 2), 1);
                        func_00194590(func_001f3870((s64 *)arg0, 0U), 1);
                        func_00194590(func_001bc920(arg0, 1), 0);
                        if ((s32)(func_001f68e0(arg0)) != (s32)(0)) {
                            func_001b0850(arg0, 0x1B, 0xC);
                        } else {
                            func_001b0850(arg0, 0x20, 0xC);
                        }
                    }
                } else {
                    func_001b0800(arg0, 0x1DU);
                }
                break;
            case 12:
                func_001b0800(arg0, 0x1DU);
                break;
            case 5:
                func_001b0800(arg0, 0x1AU);
                break;
            case 10:
                func_001b0800(arg0, 7U);
                break;
            }
            if ((var_16 != 0) && ((s32)(func_001a0140(arg0)) != (s32)(0))) {
                (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) | 8));
            } else {
                (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFF7));
            }
            func_0022dc70(arg0);
        }
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a4800);
#endif
/* measured 001a4c80 (WCold): m2c + romwright cold drafts de-noised to file idiom (u8* + RwV3d, truthful externs per tree: 95850(u8*,f32*)/95c50(u8*,u8*,RwV3d*)/99d00(s32,u8*,s64,s32)/f1210(u8*,s64,s32)/951f0(u8*,u8*,u8*,s32,f32*,f32*,s32)/95730(u8*,u8*,u8*,s32)/ec1c0(u8*,u8*,u8*)/3e4180(f32*)/3e40b0(f32*,f32*)/243d80(u8*)/f0a50(u8*)/f0bf0(u8*)/f0ff0(u8*)/22fb10(void)/96bd0(f32 local shadow over file s16)/b3bc+iGp8360 locals, D_005F6D20 kept); count first retail 584 vs v1 597 (2.2% over) then v2 586 (0.34% over); v1 525 -> v2 506 (float max/threshold fix) -> v4 487 via address-fold `(u8*)b3bc+off+2` for `lhu 2` (19-word win, 583/583 exact, 0% deviation, 445 edits +3 reloc-only via fnalign --candidate); pragma singles all tie/regress (sched 508, cs 520, prop 521), pair sched+cs 503 but 517/583 (11% short, rejected per 3% gate); scoped-counter v3 511 and s32-idx v5 499 regressed. Open walls: frame 0x140 vs retail 0x120 (spill of var_22/23), s-reg rotation, VU ACC (adda/msuba/madda) vs plain mul/add. Production stays ASM; banked as floor. Evidence in /var/tmp/cold1a4c80/ (m2c.c/rom.c/raw.c/types.txt/cand_v*.c). */
// FUN_001A4C80 NONMATCHING
#ifdef NON_MATCHING
void func_001a4c80(u8 *arg0)
{
    extern void func_00195850(u8 *arg0, f32 *arg1);
    extern void func_00195c50(u8 *arg0, u8 *arg1, RwV3d *arg2);
    extern s32 func_00199d00(s32 unused, u8 *arg1, s64 arg2, s32 arg3);
    extern s32 func_001f1210(u8 *arg0, s64 arg1, s32 arg2);
    extern void func_001951f0(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, f32 *arg4, f32 *arg5, s32 arg6);
    extern u8 *func_00195730(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
    extern void func_001ec1c0(u8 *arg0, u8 *arg1, u8 *arg2);
    extern f32 func_003e4180(f32 *arg0);
    extern f32 func_003e40b0(f32 *arg0, f32 *arg1);
    extern s32 func_00243d80(u8 *arg0);
    extern s32 func_001f0a50(u8 *arg0);
    extern s32 func_001f0bf0(u8 *arg0);
    extern s32 func_001f0ff0(u8 *arg0);
    extern s32 func_0022fb10(void);
    extern f32 func_00196bd0(u8 *arg0, u8 *arg1, s32 arg2);
    extern u8 *iGpffffb3bc;
    extern f32 fGpffff8360;
    u8 spC0[16];
    RwV3d spD0;
    RwV3d spE0;
    f32 spF0[4];
    f32 sp100[3];
    RwV3d sp110;
    s32 spB0;
    u16 idx;
    s32 off;
    s32 var_18;
    s32 var_22;
    s32 var_23;
    s32 tmp_bf0;
    s32 var_6;
    s32 tmp_6b;
    u8 *unit30;
    u8 *other30;
    u8 kind;
    u8 *tmp_pkt;
    u8 *tmp_a64_ptr;
    u16 tmp_half;
    s32 tmp_e1f0;
    s32 tmp_1210;
    f32 var_f21;
    f32 var_f20;
    f32 tmp_dist;
    f32 tmp_len;

    idx = *(u16 *)((u8 *)arg0 + 0x6E);
    off = (s32)idx * 4;
    if ((*(u16 *)((u8 *)iGpffffb3bc + off + 2) & 0x8000) != 0) {
        return;
    }
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x2000) != 0) {
        return;
    }
    var_18 = 1;
    var_23 = 0;
    var_22 = 0;
    tmp_pkt = func_0019e550(NULL, *(u8 **)((u8 *)arg0 + 0x30), 3);
    *(s64 *)(tmp_pkt + 0x60) = *(s64 *)arg0;
    func_00194590(tmp_pkt, 1);
    tmp_pkt = (u8 *)func_0019e7c0(*(s32 *)((u8 *)arg0 + 0x30), 0);
    *(s64 *)(tmp_pkt + 0x60) = *(s64 *)arg0;
    func_00194590(tmp_pkt, 1);
    *(u16 *)((u8 *)arg0 + 0x18) = (u16)(*(u16 *)((u8 *)arg0 + 0x18) | 0x200);
    if ((*(u8 *)(iGpffffb3b8 + (u32)idx * 0x28) & 2) != 0) {
        tmp_bf0 = func_001f0bf0(arg0);
        unit30 = *(u8 **)((u8 *)arg0 + 0x30);
        kind = *(u8 *)(unit30 + 0xA2);
        if (kind != 0) {
            goto first_a2_nonzero;
        }
        tmp_a64_ptr = *(u8 **)(unit30 + 0xA64);
        tmp_half = *(u16 *)(tmp_a64_ptr + 2);
        var_6 = 1;
        if (kind == 1) {
            if (*(s16 *)((u8 *)iGpffffb3cc + (u32)(tmp_half & 0xFFFF) * 0xE8 + 0x22) == 1) {
            } else {
                goto first_var6_zero;
            }
        } else if (kind == 0) {
            tmp_e1f0 = func_0023e1f0(*(u8 **)(unit30 + 0xA64)) & 0xFF;
            if (tmp_e1f0 == 5) {
                var_6 = 1;
            } else if ((tmp_e1f0 == 3) && (((*(u16 *)((u8 *)iGpffffb3bc + off + 2) & 0x8000) != 0) || (tmp_bf0 == 0))) {
                var_6 = 1;
            } else {
                goto first_var6_zero;
            }
        } else {
first_var6_zero:
            var_6 = 0;
        }
        if (var_6 != 0) {
            unit30 = *(u8 **)((u8 *)arg0 + 0x30);
            other30 = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x38) + 0x30);
            if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) && (*(u8 *)(unit30 + 0xA2) != *(u8 *)(other30 + 0xA2))) {
                var_18 = 0;
            } else {
                func_00195850(unit30, (f32 *)&spE0);
                func_00195c50(other30, unit30, &spD0);
                tmp_dist = func_001ec250(&spE0, &spD0);
                if (tmp_dist < 500.0f) {
                    var_23 = 1;
                    var_18 = 0;
                } else {
                    var_f21 = 500.0f;
                }
            }
        } else {
first_a2_nonzero:
            unit30 = *(u8 **)((u8 *)arg0 + 0x30);
            if (*(u8 *)(unit30 + 0xA2) == 0) {
                if ((*(u16 *)((u8 *)iGpffffb3bc + off + 2) & 0x8000) != 0) {
                    tmp_6b = 7;
                } else if (tmp_bf0 != 0) {
                    tmp_6b = 5;
                } else {
                    if (func_001f0a50(arg0) != 0) {
                        tmp_6b = 0xC;
                    } else {
                        tmp_6b = 4;
                    }
                    tmp_6b = tmp_6b & 0xFFFF;
                }
            } else {
                if (func_001f0a50(arg0) != 0) {
                    tmp_6b = 0xC;
                } else {
                    tmp_6b = 4;
                }
                tmp_6b = tmp_6b & 0xFFFF;
            }
            var_f21 = func_00196bd0(*(u8 **)((u8 *)arg0 + 0x30), *(u8 **)(*(u8 **)((u8 *)arg0 + 0x38) + 0x30), tmp_6b);
        }
        if ((*(u16 *)((u8 *)arg0 + 0x18) & 0x4000) != 0) {
            var_22 = 1;
        }
    } else {
        unit30 = *(u8 **)((u8 *)arg0 + 0x30);
        kind = *(u8 *)(unit30 + 0xA2);
        if (kind == 1) {
            if (func_001f0a50(arg0) != 0) {
                tmp_6b = 0xC;
            } else {
                tmp_6b = 4;
            }
            tmp_6b = tmp_6b & 0xFFFF;
            var_f21 = func_00196bd0(*(u8 **)((u8 *)arg0 + 0x30), *(u8 **)(*(u8 **)((u8 *)arg0 + 0x38) + 0x30), tmp_6b);
        } else if (kind == 0) {
            other30 = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x38) + 0x30);
            tmp_a64_ptr = *(u8 **)(unit30 + 0xA0C);
            tmp_pkt = (u8 *)func_001f0ff0(arg0);
            spB0 = func_00199d00((s32)tmp_a64_ptr, unit30, (s64)(s16)idx, (s32)tmp_pkt) & 0xFFFF;
            tmp_1210 = func_001f1210(tmp_a64_ptr, (s64)(s16)idx, (s32)tmp_pkt);
            func_00195850(unit30, (f32 *)&spE0);
            func_00195c50(other30, unit30, &spD0);
            tmp_dist = func_001ec250(&spE0, &spD0);
            var_f20 = tmp_dist - *(f32 *)(unit30 + 0x90) * *(f32 *)(unit30 + 0x2C) - *(f32 *)(other30 + 0x90) * *(f32 *)(other30 + 0x2C);
            if ((tmp_1210 == 0) || (func_0022fb10() == 0) || (var_f20 < 300.0f) || ((var_f20 - 300.0f) < 200.0f)) {
                *(u16 *)((u8 *)arg0 + 0x18) = (u16)(*(u16 *)((u8 *)arg0 + 0x18) | 0x10);
                var_18 = 0;
            } else {
                var_f20 = var_f20 + *(f32 *)(unit30 + 0x90) * *(f32 *)(unit30 + 0x2C) + *(f32 *)(other30 + 0x90) * *(f32 *)(other30 + 0x2C);
                func_001951f0(tmp_a64_ptr, unit30, other30, (s32)(s16)spB0, (f32 *)&sp110, NULL, 2);
                tmp_len = func_001ec250(&sp110, &spD0);
                var_f21 = tmp_len;
                tmp_dist = 300.0f + *(f32 *)(unit30 + 0x90) * *(f32 *)(unit30 + 0x2C) + *(f32 *)(other30 + 0x90) * *(f32 *)(other30 + 0x2C);
                if (tmp_len < tmp_dist) {
                    var_f21 = tmp_dist;
                }
                func_001951f0(tmp_a64_ptr, unit30, NULL, -1, (f32 *)&sp110, NULL, 0);
                spF0[0] = sp110.x - spE0.x;
                spF0[2] = sp110.z - spE0.z;
                spF0[1] = 0.0f;
                tmp_len = func_003e4180(spF0);
                var_f21 = var_f21 + tmp_len;
                if (var_f20 < var_f21) {
                    *(u16 *)((u8 *)arg0 + 0x18) = (u16)(*(u16 *)((u8 *)arg0 + 0x18) | 0x10);
                    var_18 = 0;
                }
            }
        }
    }
    if (var_18 == 0) {
        return;
    }
    func_001a03b0((s64 *)arg0);
    {
        s32 pktFlags;
        s32 tblIdx;
        u16 half2;
        u8 kind2;
        u8 invFlag;
        u8 *u30;
        u8 *o30;
        f32 f20;
        pktFlags = 0;
        tblIdx = 2;
        invFlag = (u8)(((*(u8 *)(iGpffffb3b8 + (u32)idx * 0x28) & 2) == 0) & 0xFFFF);
        u30 = *(u8 **)((u8 *)arg0 + 0x30);
        half2 = *(u16 *)(*(u8 **)(u30 + 0xA64) + 2);
        kind2 = *(u8 *)(u30 + 0xA2);
        if (kind2 == 1) {
            tblIdx = *(u16 *)((u32)iGpffffb3cc + (u32)(half2 & 0xFFFF) * 0xE8 + (u32)(invFlag & 0xFFFF) * 4 + 0x24);
        }
        f20 = D_005F6D20[tblIdx & 0xFFFF];
        if (var_22 == 1) {
            if (var_23 != 0) {
                f20 = f20 * 1.25f;
            } else {
                o30 = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x38) + 0x30);
                func_00195850(u30, (f32 *)&spE0);
                func_00195c50(o30, u30, &spD0);
                sp100[0] = spE0.x - spD0.x;
                sp100[2] = spE0.z - spD0.z;
                sp100[1] = 0.0f;
                func_003e40b0(sp100, sp100);
                tmp_dist = (*(f32 *)(u30 + 0x90) * *(f32 *)(u30 + 0x2C) + *(f32 *)(o30 + 0x90) * *(f32 *)(o30 + 0x2C)) + var_f21 + 50.0f;
                sp100[0] = sp100[0] * tmp_dist;
                sp100[1] = sp100[1] * tmp_dist;
                sp100[2] = sp100[2] * tmp_dist;
                sp110.x = spD0.x + sp100[0];
                sp110.y = spD0.y + sp100[1];
                sp110.z = spD0.z + sp100[2];
                sp110.y = *(f32 *)(u30 + 8);
                func_001ec1c0(spC0, (u8 *)&sp110, (u8 *)&spD0);
                tmp_pkt = func_00195730(u30, (u8 *)&sp110, spC0, 0);
                *(s64 *)(tmp_pkt + 0x60) = *(s64 *)arg0;
                func_00194590(tmp_pkt, 0);
                f20 = f20 * fGpffff8360;
                pktFlags = 8;
            }
        }
        if (func_00243d80(*(u8 **)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x38) + 0x30) + 0xA64)) == 0) {
            pktFlags = pktFlags | 0x40;
        }
        tmp_pkt = func_001979e0(*(u8 **)((u8 *)arg0 + 0x30), *(u8 **)(*(u8 **)((u8 *)arg0 + 0x38) + 0x30), pktFlags, var_f21, f20);
        *(s64 *)(tmp_pkt + 0x60) = *(s64 *)arg0;
        func_00194590(tmp_pkt, 0);
        if ((tmp_pkt != NULL) && (var_23 == 0)) {
            if (var_22 != 0) {
                tmp_pkt = func_001bc920(arg0, 0x17);
                *(s64 *)(tmp_pkt + 0x60) = *(s64 *)arg0;
                func_00194590(tmp_pkt, 0);
            } else {
                tmp_pkt = func_001bc920(arg0, 0x16);
                *(s64 *)(tmp_pkt + 0x60) = *(s64 *)arg0;
                func_00194590(tmp_pkt, 0);
            }
        }
        *(u16 *)((u8 *)arg0 + 0x18) = (u16)(*(u16 *)((u8 *)arg0 + 0x18) & 0xFFEF);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a4c80);
#endif
// FUN_001A55A0
void func_001a55a0(s64 *arg0) {
    u16 var_5;

    if (btlUnitIsMoving(*(u8 **)((u8 *)arg0 + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)arg0 + 0x6C)) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((u8 *)arg0, var_5);
    }
}



/* Measured: 656/656 bytes and 15 resolved relocations match retail.
 * Preserve unit/UID reloads across queue callbacks and the ordered distance test. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_001A5650
void func_001a5650(s64 *arg0)
{
    RwV3d sp30;
    u32 source_offset, sum, idx4;
    f32 speed, scale;
    u16 temp_7;
    u16 temp_3_3;
    u16 var_5;
    u16 var_5_2;
    u16 var_5_3;
    u16 temp_3;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = *(u8 **)((u8 *)arg0 + 0x30);
    temp_4 = D_0076449C;
    if ((*(s32 *)(temp_4 + 0xC) & 0x400000) &&
        (*(u16 *)(temp_4 + 0x18) & 2)) {
        temp_3 = *(u16 *)((u8 *)arg0 + 0x6C);
        switch (temp_3) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((u8 *)arg0, var_5);
        return;
    }
    func_00194ff0(temp_16, (u8 *)&sp30, NULL, NULL);
    if (!(func_001ec250((RwV3d *)(temp_16 + 4), &sp30) <= 75.0f)) {
        func_001a03b0(arg0);
        var_5_2 = 2;
        temp_7 = (!(iGpffffb3b8[
            (*(u16 *)((u8 *)arg0 + 0x6E) * 0x28)] & 2)) & 0xFFFF;
        temp_4_2 = *(u8 **)((u8 *)arg0 + 0x30);
        temp_3 = *(u16 *)(*(u8 **)(temp_4_2 + 0xA64) + 2);
        temp_3_2 = *(u8 *)(temp_4_2 + 0xA2);
        switch (temp_3_2) {
        case 0:
            break;
        case 1:
            temp_4 = iGpffffb3cc;
            source_offset = temp_3 * 0xE8;
            sum = source_offset + (u32)temp_4;
            idx4 = temp_7 * 4;
            var_5_2 = *(u16 *)(idx4 + sum + 0x24);
            break;
        }
        speed = D_005F6D20[var_5_2];
        scale = D_0076144C;
        temp_2 = (u8 *)btlUnitCreateMovePacket(
            (BtlUnit *)temp_4_2, &sp30,
            speed * scale, 0);
        *(s64 *)(temp_2 + 0x60) = *arg0;
        func_00194590(temp_2, 1);
        temp_2_2 = func_001bc920((u8 *)arg0, 0x18);
        *(s64 *)(temp_2_2 + 0x60) = *arg0;
        func_00194590(temp_2_2, 0);
        return;
    }
    temp_3_3 = *(u16 *)((u8 *)arg0 + 0x6C);
    switch (temp_3_3) {
    case 1:
        var_5_3 = 0x12;
        break;
    case 2:
    case 3:
        var_5_3 = 0x13;
        break;
    case 9:
        var_5_3 = 0x14;
        break;
    default:
        var_5_3 = 0;
        break;
    }
    btlActionSetState((u8 *)arg0, var_5_3);
}
#pragma pop

// FUN_001A58E0
void func_001a58e0(s64 *arg0) {
    u16 var_5;

    if (btlUnitIsMoving(*(u8 **)((u8 *)arg0 + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)arg0 + 0x6C)) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((u8 *)arg0, var_5);
    }
}



// FUN_001A5990
void func_001a5990(void)
{
}

// FUN_001A59A0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a59a0);
// FUN_001A7710
void func_001a7710(void)
{
}

// FUN_001A7720
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a7720);
// FUN_001ABBA0
void func_001abba0(void)
{
}
/* Floor: 449 differing words of 596, 2384 emitted bytes against retail's
   2384-byte window, frame -0x170 with all ten saves (sd ra@0x90, sq
   s0-s7+fp@0x00-0x80) verified identical.  The frame is what the pragma
   stack buys: common-subs off + propagation off + loop-invariants on
   lands -0x170 and 449 words, where no-pragma and both-on land 0x1A0 and
   480, and the two both-off variants land 0x160 and 488.  Other levers
   that held: s16 auxRaw at +0x6E so the aux offset emits retail's
   dsll32/dsra32+sll (s32 loses them, 486); the +0x58 parentUID comes
   from the func_001d5eb0 packet, not the func_001d6240 one (a semantic
   fix, not just a word count); unit position at +0x04/+0x08/+0x0C is
   f32, copied lwc1/swc1 rather than lw/sw; the tail's three-way empty
   if preserves retail's redundant branches.
   WALL: first residual at offset 56 is propagation-off emitting
   `move $a0,$s4` before jal func_001a03b0 where retail passes $a0
   directly - propagation on removes the move but costs the frame - and
   the rest is scattered saved-register colour and scheduling across
   thirty packet calls with no bulk left.  Fourteen variants measured;
   full evidence in docs/probe_archive/C1A_001abbb0_body.c. */
// FUN_001ABBB0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_001abbb0(s64 *arg0) {
    extern s32 func_001d3d50(s32 arg0);
    extern u8 *func_00202010(s32 arg0, u16 arg1);
    extern u8 *func_001f3b20(u8 *arg0);
    extern s16 func_001991c0(u8 *arg0, s32 arg1, f32 arg2);
    extern void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2);
    extern s32 func_001b7080(s32 arg0);
    extern s32 func_001b7090(s32 arg0);
    extern void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2);
    extern u8 *func_001b7880(s32 arg0, s32 arg1, s32 arg2);
    extern u8 *func_001b83f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern u8 *func_001b9560(s32 arg0, s32 arg1);
    extern u8 *func_001b9de0(u8 *arg0, u16 arg1, s32 arg2);
    extern void func_001d69f0(s32 arg0, void *arg1);
    extern u8 *func_001d5eb0(s32 arg0, void *arg1, s32 arg2);
    extern u8 *func_001f8000(s32 arg0, s32 arg1);
    extern u8 *func_00194b60(void);
    extern u8 *func_001f8140(s32 arg0);
    extern u8 *func_0019f5f0(s32 arg0, s64 arg1, u16 *arg2);
    extern void func_0019ea60(u8 *arg0, s32 arg1);
    extern u8 *func_0019b550(u8 *arg0, u16 arg1, s16 arg2);
    extern u8 *func_0019c030(u8 *arg0, u16 arg1, u16 arg2);
    extern u8 *func_00202400(s32 arg0, s32 arg1);
    extern u8 *func_001b7e20(s32 arg0);
    extern u8 *func_001b9360(s32 arg0, s32 arg1);
    extern u8 *func_001b99a0(s32 arg0);
    extern s32 func_001f68e0(u8 *arg0);
    extern void func_001b0800(u8 *arg0, u16 arg1);
    extern u8 *iGpffffb3ac;
    extern u8 *iGpffffb3bc;
    extern s32 func_002317a0(u8 *arg0, u16 arg1);
    s64 uid;
    s16 auxRaw;
    u16 aux;
    s32 handle;
    s32 outHi;
    s32 outLo;
    u8 workBuf[136];
    s32 firstDone;
    s16 scaleTmp;
    u8 *evPkt;
    u8 *holdJ;
    u8 *tailPkt;
    s64 cur58;
    u8 *tmp;
    s32 tmpS;
    u16 tailId;
    s32 off;
    s32 idx;
    u8 *pktI_save;
    auxRaw = *(s16 *)((u8 *)arg0 + 0x6E);
    uid = *arg0;
    func_001a03b0(arg0);
    handle = func_001d3d50(1);
    aux = (u16)(auxRaw & 0xFFFF);
    tmp = func_00202010(*(s32 *)((u8 *)arg0 + 0x30), aux);
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 3);
    tmp = func_001f3b20((u8 *)arg0);
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    tmp = func_001f3870(arg0, 0);
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    evPkt = func_00199ee0(*(u8 **)((u8 *)arg0 + 0x30), 8, 6, 0, 1.0f);
    *(s64 *)(evPkt + 0x60) = uid;
    func_00194590(evPkt, 0);
    tmp = func_001bc920((u8 *)arg0, 0x15);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = *(s64 *)(evPkt + 0x58);
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 0);
    cur58 = *(s64 *)(evPkt + 0x58);
    scaleTmp = func_001991c0(*(u8 **)((u8 *)arg0 + 0x30), 8, 1.0f);
    func_001b7060(aux, &outHi, &outLo);
    tmp = func_001b7880(outHi, outLo, 0x10);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = cur58;
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    tmpS = func_001b7080(aux);
    func_001b70a0(aux, &outHi, &outLo);
    tmp = func_001b83f0(tmpS, outHi, outLo, 0x10, 0);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = cur58;
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    tmp = func_001b9560(func_001b7090(aux), 0x10);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = cur58;
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    tmp = func_001b9de0((u8 *)arg0, aux, 0x10);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = cur58;
    *(s64 *)(tmp + 0x60) = uid;
    func_00194590(tmp, 1);
    func_001d69f0(aux, workBuf);
    pktI_save = func_001d5eb0(handle, workBuf, 0);
    *(pktI_save + 0) = 4;
    *(s64 *)(pktI_save + 8) = 0;
    *(s16 *)(pktI_save + 0x48) = (s16)(scaleTmp + 6);
    *(s64 *)(pktI_save + 0x60) = uid;
    func_00194590(pktI_save, 1);
    holdJ = func_001f8000(aux, 0);
    *(holdJ + 0) = 4;
    *(s64 *)(holdJ + 8) = *(s64 *)(pktI_save + 0x58);
    func_00194590(holdJ, 1);
    {
        u8 *pk;
        pk = (u8 *)func_001d6240((u32)handle, (u32)*(u8 **)((u8 *)arg0 + 0x30), (u32)*(u8 **)((u8 *)arg0 + 0x30), 0, 0);
        *(pk + 0) = 4;
        *(s64 *)(pk + 8) = *(s64 *)(pktI_save + 0x58);
        *(pk + 0x10) = 4;
        *(s64 *)(pk + 0x18) = *(s64 *)(holdJ + 0x58);
        func_00194590(pk, 2);
        tmp = pk;
    }
    {
        u8 *pk2;
        pk2 = func_001f8140(0);
        *(pk2 + 0) = 5;
        *(s64 *)(pk2 + 8) = *(s64 *)(tmp + 0x58);
        func_00194590(pk2, 1);
    }
    cur58 = *(s64 *)(pktI_save + 0x58);
    {
        u8 *pk3;
        pk3 = func_00194b60();
        *(pk3 + 0) = 4;
        *(s64 *)(pk3 + 8) = cur58;
        *(s16 *)(pk3 + 0x48) = 0x18;
        *(s64 *)(pk3 + 0x60) = uid;
        func_00194590(pk3, 1);
        tmp = pk3;
    }
    tailPkt = func_001d65d0(*(s32 *)(iGpffffb3ac + 0xD40), *(s32 *)((u8 *)arg0 + 0x30), 0, *(s64 *)(tmp + 0x58), 0x100);
    *(tailPkt + 0) = 4;
    *(s64 *)(tailPkt + 8) = *(s64 *)(evPkt + 0x58);
    *(s64 *)(tailPkt + 0x60) = uid;
    func_00194590(tailPkt, 1);
    tmp = (u8 *)func_001f7c20(10, 2, 7);
    *(tmp + 0) = 4;
    *(s64 *)(tmp + 8) = *(s64 *)(evPkt + 0x58);
    func_00194590(tmp, 1);
    firstDone = 0;
    off = ((s32)auxRaw) * 4;
    idx = 0;
    goto loop_test;
loop_body:
    {
        u16 curId;
        u8 *loopPkt;
        u8 *unit;
        curId = *(u16 *)((u8 *)arg0 + (idx & 0xFFFF) * 2 + 0x76);
        if (curId == 0) {
            goto loop_end;
        }
        loopPkt = func_0019f5f0(1, (s64)curId, (u16 *)0);
        unit = *(u8 **)(loopPkt + 0x30);
        *(s32 *)(unit + 0xA64) = func_002317a0(*(u8 **)(iGpffffb3ac + 0xC68), curId);
        func_0019ea60(unit, (s32)(curId & 0xFFFF));
        *(s16 *)(unit + 0x94) = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x94);
        *(s16 *)(unit + 0x96) = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x96);
        *(f32 *)(unit + 4) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 4);
        *(f32 *)(unit + 8) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 8);
        *(f32 *)(unit + 12) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 12);
        if (firstDone == 0) {
            u8 *r1;
            u8 *r2;
            r1 = (u8 *)func_001d3900(0);
            *(r1 + 0) = 4;
            *(s64 *)(r1 + 8) = cur58;
            *(s64 *)(r1 + 0x60) = uid;
            func_00194590(r1, 0);
            r2 = (u8 *)func_001d3700(1, 0xFFF);
            *(r2 + 0) = 4;
            *(s64 *)(r2 + 8) = cur58;
            *(s64 *)(r2 + 0x60) = uid;
            func_00194590(r2, 0);
            if ((*(u16 *)((u32)iGpffffb3bc + 2U + (u32)off) & 0x40) == 0) {
                u8 *r3;
                u8 *r4;
                r3 = func_001d7a10(5);
                *(r3 + 0) = 4;
                *(s64 *)(r3 + 8) = cur58;
                *(s64 *)(r3 + 0x60) = uid;
                func_00194590(r3, 0);
                r4 = func_001bc920((u8 *)arg0, 0x2D);
                *(r4 + 0) = 4;
                *(s64 *)(r4 + 8) = cur58;
                *(s64 *)(r4 + 0x60) = uid;
                func_00194590(r4, 0);
            }
            firstDone = 1;
        }
        {
            u8 *q1;
            u8 *q2;
            q1 = func_0019b550(unit, curId, 0x7E);
            *(q1 + 0) = 4;
            *(s64 *)(q1 + 8) = cur58;
            *(s64 *)(q1 + 0x60) = uid;
            func_00194590(q1, 1);
            q2 = func_0019c030(unit, curId, 0x10);
            *(q2 + 0) = 4;
            *(s64 *)(q2 + 8) = *(s64 *)(q1 + 0x58);
            func_00194590(q2, 1);
            {
                u8 *q3;
                u8 *q4;
                q3 = (u8 *)func_001d6240((u32)handle, (u32)*(u8 **)((u8 *)arg0 + 0x30), (u32)*(u8 **)(loopPkt + 0x30), 1, 0x100);
                *(q3 + 0) = 4;
                *(s64 *)(q3 + 8) = *(s64 *)(q2 + 0x58);
                *(q3 + 0x10) = 4;
                *(s64 *)(q3 + 0x18) = *(s64 *)(holdJ + 0x58);
                *(s64 *)(q3 + 0x60) = uid;
                func_00194590(q3, 2);
                tailPkt = q3;
                q4 = func_001f8140(1);
                *(q4 + 0) = 5;
                *(s64 *)(q4 + 8) = *(s64 *)(q3 + 0x58);
                func_00194590(q4, 1);
                if (((idx & 0xFFFF) == 0) && (*(u16 *)((u8 *)arg0 + 0x78) == 0)) {
                    u8 *q5;
                    q5 = func_00202400(*(s32 *)(loopPkt + 0x30), 0x9F);
                    *(q5 + 0) = 5;
                    *(s64 *)(q5 + 8) = *(s64 *)(q3 + 0x58);
                    *(s16 *)(q5 + 0x48) = 0x1C;
                    func_00194590(q5, 3);
                }
                {
                    u8 *q6;
                    q6 = func_0019bbe0(unit, (u32)-1, 0xC, 0, 3, 1);
                    *(q6 + 0) = 4;
                    *(s64 *)(q6 + 8) = *(s64 *)(q2 + 0x58);
                    *(q6 + 0x10) = 0xB;
                    *(s64 *)(q6 + 0x18) = *(s64 *)(q3 + 0x58);
                    *(s16 *)(q6 + 0x48) = 1;
                    *(s64 *)(q6 + 0x60) = uid;
                    func_00194590(q6, 1);
                    cur58 = *(s64 *)(q2 + 0x58);
                }
            }
        }
    }
    idx = (idx + 1) & 0xFFFF;
loop_test:
    if ((idx & 0xFFFF) < 3) {
        goto loop_body;
    }
loop_end:;
    {
        u8 *t1;
        u8 *t2;
        u8 *t3;
        u8 *t4;
        u8 *t5;
        t1 = func_001f5f70((u8 *)arg0, 9, 0, 0, 0);
        *(t1 + 0) = 0xB;
        *(s64 *)(t1 + 8) = *(s64 *)(tailPkt + 0x58);
        func_00194590(t1, 1);
        t2 = func_001b7e20(0x10);
        *(t2 + 0) = 4;
        *(s64 *)(t2 + 8) = *(s64 *)(tailPkt + 0x58);
        *(t2 + 0x47) &= (u8)~0x20;
        *(s64 *)(t2 + 0x60) = uid;
        func_00194590(t2, 1);
        t3 = func_001b9360(0x10, 0);
        *(t3 + 0) = 4;
        *(s64 *)(t3 + 8) = *(s64 *)(tailPkt + 0x58);
        *(t3 + 0x47) &= (u8)~0x20;
        *(s64 *)(t3 + 0x60) = uid;
        func_00194590(t3, 1);
        t4 = func_001b99a0(0x10);
        *(t4 + 0) = 4;
        *(s64 *)(t4 + 8) = *(s64 *)(tailPkt + 0x58);
        *(t4 + 0x47) &= (u8)~0x20;
        *(s64 *)(t4 + 0x60) = uid;
        func_00194590(t4, 1);
        t5 = (u8 *)func_001ba090(8);
        *(t5 + 0) = 4;
        *(s64 *)(t5 + 8) = *(s64 *)(tailPkt + 0x58);
        *(t5 + 0x47) &= (u8)~0x20;
        *(s64 *)(t5 + 0x60) = uid;
        func_00194590(t5, 0);
    }
    func_001d3e00(handle);
    if (func_001f68e0((u8 *)arg0) != 0) {
        func_001b0800((u8 *)arg0, 0x1B);
        return;
    }
    tailId = *(u16 *)((u8 *)arg0 + 0x6C);
    if ((tailId != 2) && (tailId != 3) && (tailId != 1)) {
    }
    func_001b0800((u8 *)arg0, 0x20);
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001abbb0);
#endif
// FUN_001AC500
void func_001ac500(s64 *arg0) {
    u8 *temp_2;
    u8 *temp_2_2;

    func_001a03b0(arg0);
    func_001eb3b0((u8 *)arg0 + 0x38);
    func_001dbf20(arg0, 0);
    func_001a03b0(arg0);
    temp_2 = (u8 *)func_001d3700(3, 0xFFF);
    *(s64 *)(temp_2 + 0x60) = *arg0;
    func_00194590(temp_2, 0);
    temp_2_2 = btlCameraCreateSetStatePacket(arg0, 0x2C);
    *(s64 *)(temp_2_2 + 0x60) = *arg0;
    func_00194590(temp_2_2, 0);
    *(u16 *)((u8 *)arg0 + 0x18) |= 2;
}



// FUN_001AC5B0
void func_001ac5b0(s64 *arg0) {
    if ((func_00193cd0(0x506) == 0) && (func_00193cd0(0x800) == 0)) {
        *(u16 *)((u8 *)(arg0) + 0x18) = (u16) (*(u16 *)((u8 *)(arg0) + 0x18) | 0x100);
        func_001b0800(arg0, 0xFU);
    }
}

// FUN_001AC620
void func_001ac620(void) {
    u8 *p = *(u8 **)(D_0076449C + 0x174);
    u8 *o;

    while (p != NULL) {
        if (func_001a05f0(p) != 0) {
            o = func_0019b6a0(*(s32 *)(*(u8 **)(p + 0x30) + 0xA0C));
            *(s64 *)(o + 0x60) = *(s64 *)p;
            func_00194590(o, 1);
        }
        p = *(u8 **)(p + 0x450);
    }
}

// FUN_001AC6A0
void func_001ac6a0(u8 *arg0) {
    if ((*(s32 (**)(void))(arg0 + 0x440))() == 0) {
        btlActionSetState(arg0, *(u16 *)(arg0 + 0x43C));
    }
}

// FUN_001AC6F0
void func_001ac6f0(void)
{
}
/* measured: live object 1040B/window 1040B, normalized_diff 155 (installed guard below completes the tail; prior nd154 draft note was 52B short). Tail completed per retail: f68e0 != 0 calls 0x1B and returns, else the 0x6C ==2/==3/==1 chain assigns 0x20 twice and calls once. Both chain arms load the same 0x20, so the dispatch is vestigial but reproduced. Open walls: s-reg rotation (self-consistent, banked), addiu-vs-daddiu small-const loads (s64/u64/O-level/propagation all give addiu), 2nd/3rd beq forms (braced == gives bne-over, unbraced gotos merge the last test to bne). Ruled out today: goto-diamond (155), unbraced-goto (155, beq+beq+bne), u64 cmd (155). Banked as floor. */
// FUN_001AC700 NONMATCHING
#ifdef NON_MATCHING
void func_001ac700(u8 *arg0) {
    s64 temp_17;
    s64 temp_18;
    s64 var_19;
    s64 var_20;
    u16 var_21;
    s32 var_2;
    f32 var_f20;
    u16 temp_3;
    u8 *event_packet;

    u8 *func_00202010(s32 arg0, u16 arg1);
    u8 *func_00202120(s32 arg0, u16 arg1);
    s16 func_001991c0(u8 *arg0, s64 arg1, f32 arg2);
    s16 func_00199500(u8 *arg0, s64 arg1, f32 arg2);
    u8 *func_001b9360(s32 arg0, s32 arg1);
    u8 *func_001b7e20(s32 arg0);
    u8 *func_001b99a0(s32 arg0);
    s32 func_001f11e0(s16 arg0);
    u8 *func_00202400(s32 arg0, s16 arg1);

    func_001a03b0((s64 *)arg0);
    temp_18 = (*(u16 *)(arg0 + 0x6C) == 3);
    temp_17 = *(s64 *)arg0;
    if (temp_18 == 0) {
        u8 *packet;
        packet = func_00202010(*(s32 *)(arg0 + 0x30),
                               *(u16 *)(arg0 + 0x6E));
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 3);
    } else {
        u8 *packet;
        packet = func_00202120(*(s32 *)(arg0 + 0x30),
                               *(u16 *)(arg0 + 0x70));
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 3);
    }
    if ((*(u8 **)(arg0 + 0x30))[0xA2] == 0) {
        if (temp_18 == 0) {
            var_20 = (s64)0xD;
            var_19 = (s64)0xB;
        } else {
            var_20 = (s64)0x16;
            var_19 = (s64)0x21;
        }
        temp_18 = (s64)0x14;
        var_21 = func_00199500(*(u8 **)(arg0 + 0x30),
                               var_20, 1.0f);
        var_f20 = 1.0f;
    } else {
        if (func_001f11e0(*(s16 *)(arg0 + 0x6E)) != 0) {
            var_2 = 4;
        } else {
            var_2 = 8;
        }
        var_20 = (u16)var_2;
        var_19 = (s64)0xF;
        temp_18 = (s64)0x15;
        if (*(u16 *)(arg0 + 0x18) & 0x4000) {
            var_f20 = 2.0f;
        } else {
            var_f20 = 1.0f;
        }
        var_21 = func_001991c0(*(u8 **)(arg0 + 0x30),
                               var_20, var_f20);
    }
    event_packet = func_00199ee0(*(u8 **)(arg0 + 0x30),
                                 (s16)var_20, 6, 0, var_f20);
    *(s64 *)(event_packet + 0x60) = temp_17;
    *(s16 *)(event_packet + 0x4A) = (s16)((var_21 & 0xFFFF) + 6);
    func_00194590(event_packet, 0);
    {
        u8 *packet;
        packet = func_001d65d0(
            *(s32 *)(D_0076449C + ((var_19 & 0xFFFF) * 4) + 0xD04),
            *(s32 *)(arg0 + 0x30), 0,
            *(s64 *)(event_packet + 0x58), 0x100);
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 2);
    }
    {
        u8 *packet;
        packet = func_001bc920((u8 *)arg0, temp_18);
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 0);
    }
    {
        u8 *packet;
        packet = func_00202400(*(s32 *)(arg0 + 0x30),
                               *(s16 *)(arg0 + 0xEC));
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(event_packet + 0x58);
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 3);
    }
    {
        u8 *packet;
        packet = func_001f3870((s64 *)arg0, 0);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(event_packet + 0x58);
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 1);
    }
    {
        u8 *packet;
        packet = func_001b7e20(0x10);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(event_packet + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 1);
    }
    {
        u8 *packet;
        packet = func_001b9360(0x10, 0);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(event_packet + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 1);
    }
    {
        u8 *packet;
        packet = func_001b99a0(0x10);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(event_packet + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)func_001ba090(8);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(event_packet + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = temp_17;
        func_00194590(packet, 0);
    }
    if (func_001f68e0(arg0) != 0) {
        func_001b0800(arg0, 0x1B);
        return;
    }
    temp_3 = *(u16 *)(arg0 + 0x6C);
    {
        s64 cmd;
        if (temp_3 == 2) {
            cmd = 0x20;
        } else if (temp_3 == 3) {
            cmd = 0x20;
        } else if (temp_3 == 1) {
            cmd = 0x20;
        } else {
            cmd = 0x20;
        }
        func_001b0800(arg0, cmd);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ac700);
#endif
// FUN_001ACB10
void func_001acb10(u8 *arg0)
{
    u16 temp_5;
    u8 *temp_5_4;

    temp_5 = *(u16 *)(arg0 + 0x3F4);
    switch (temp_5) {
    case 0x20F:
        temp_5_4 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)temp_5_4 = *(u16 *)temp_5_4 | 0x400;
        break;
    case 0x210:
        temp_5_4 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)temp_5_4 = *(u16 *)temp_5_4 | 0x800;
        break;
    }
    if (*(u16 *)(arg0 + 0x3F4) == 0) {
        temp_5_4 = *(u8 **)(arg0 + 0x30);
        *(s32 *)(temp_5_4 + 0x9C) = *(s32 *)(temp_5_4 + 0x9C) & ~0x10;
        func_001b0800(arg0, *(u16 *)(arg0 + 0x430));
    }
}
// FUN_001ACBB0
void func_001acbb0(u8 *arg0) {
    s32 sp80[8];
    s32 temp_19;
    s32 temp_2_4;
    s32 temp_4;
    s32 var_17;
    s64 temp_20;
    s64 temp_21;
    s64 var_2;
    s64 var_2_2;
    s64 var_2_3;
    u16 temp_3;
    u8 *temp_16;
    u8 *temp_2_2;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;

    s32 func_00106600(s16 id);
    void func_00106620(s32 arg0, s32 arg1);
    u8 *func_001937f0(s32 arg0);
    u8 *func_00194b60(void);
    void func_001f0a10(u8 *arg0);
    u8 *func_001f36e0(s32 arg0, s32 arg1, void *arg2, s16 arg3, s16 arg4);
    u8 *func_00201de0(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4,
                      s16 arg5, s16 arg6, u8 *arg7, u16 arg8);
    u8 *func_00202400(s32 arg0, s32 arg1);
    u8 *func_00202590(s32 arg0, s8 arg1, s16 arg2);
    void func_001b0800(u8 *arg0, u16 arg1);
    u8 *func_00202740(u8 *arg0);
    u32 func_00231ed0(u8 *arg0);
    u32 func_00231f80(u8 *arg0);

    temp_16 = *(u8 **)((u8 *)arg0 + 0x30);
    *(s32 *)(temp_16 + 0x9C) &= ~0x10;
    if (func_00193cd0(0xFF03) == 0) {
        temp_4 = *(s32 *)(D_0076449C + 0xC);
        if (!(temp_4 & 0x80000)) {
            *(s32 *)(D_0076449C + 0xC) = temp_4 | 0x80000;
            var_17 = 1;
        } else {
            var_17 = 0;
        }
        temp_3 = *(u16 *)(arg0 + 0x3F4);
        switch (temp_3) {
        case 0x210:
            if (temp_16[0xA2] == 0) {
                var_2 = 0x3E;
            } else {
                var_2 = 0x3F;
            }
            var_2_2 = (s16)var_2;
            break;
        case 0x154:
            var_2_2 = 0x9B;
            break;
        case 0x231:
            var_2_2 = 0xB4;
            break;
        case 0x232:
            var_2_2 = 0xB6;
            break;
        default:
            if (temp_16[0xA2] == 0) {
                var_2_3 = 0x3C;
            } else {
                var_2_3 = 0x3D;
            }
            var_2_2 = (s16)var_2_3;
            break;
        }
        temp_19 = (s16)var_2_2;
        temp_2_2 = func_00202400((s32)*(u8 **)(arg0 + 0x30),
                                 temp_19);
        *(s16 *)(temp_2_2 + 0x48) = 8;
        *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_2, 3);
        temp_21 = *(s64 *)(temp_2_2 + 0x58);
        temp_2_2 = func_00194b60();
        *(s16 *)(temp_2_2 + 0x48) = 8;
        *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_2, 0);
        temp_20 = *(s64 *)(temp_2_2 + 0x58);
        if (*(u16 *)(arg0 + 0x3F4) == 0x154) {
            temp_2_4 = func_00106600(0x340) & 0xFF;
            if (temp_2_4 > 0) {
                func_00106620(0x340, (temp_2_4 - 1) & 0xFF);
            }
        }
        if (*(u16 *)(arg0 + 0x3F4) == 0x210) {
            func_001f0a10((u8 *)&sp80);
            temp_19 = func_00231f80(*(u8 **)(temp_16 + 0xA64)) & 0xFFFF;
            sp80[0] = temp_19 - (func_00231ed0(*(u8 **)(temp_16 + 0xA64)) & 0xFFFF);
            temp_2_5 = func_001f36e0((s32)arg0, (s32)arg0,
                                     &sp80, 1, 1);
            *(s8 *)(temp_2_5 + 0) = 4;
            *(s64 *)(temp_2_5 + 8) = temp_20;
            *(s64 *)(temp_2_5 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_5, 1);
            temp_2_6 = func_00202740(temp_16);
            *(s8 *)(temp_2_6 + 0) = 4;
            *(s64 *)(temp_2_6 + 8) = temp_20;
            *(s64 *)(temp_2_6 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_6, 1);
            temp_2_7 = func_00201de0((s32)temp_16, (s32)temp_16, -1, 0, 0,
                                     0, 1, (u8 *)&sp80, 0);
            *(s8 *)(temp_2_7 + 0) = 4;
            *(s64 *)(temp_2_7 + 8) = temp_20;
            *(s64 *)(temp_2_7 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_7, 3);
            temp_2_8 = func_00202590((s32)temp_16, 0, 0);
            *(s8 *)(temp_2_8 + 0) = 4;
            *(s64 *)(temp_2_8 + 8) = temp_20;
            *(s64 *)(temp_2_8 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_8, 3);
        }
        if (var_17 != 0) {
            temp_2_9 = func_001937f0(0x80000);
            *(s8 *)(temp_2_9 + 0) = 4;
            *(s64 *)(temp_2_9 + 8) = temp_21;
            *(s64 *)(temp_2_9 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_9, 0);
        }
        func_001b0800(arg0, *(u16 *)(arg0 + 0x430));
    }
}
// FUN_001ACF40
void func_001acf40(void)
{
}
// FUN_001ACF50
u8 *func_00194b60(void);
s32 func_00198810(u8 *arg0);
u8 *func_0019a980(BtlUnit *unit);
void func_001f0a10(u8 *arg0);
u8 *func_001f36e0(s32 param_1, s32 param_2, void *param_3, s16 param_4, s16 param_5);
s32 func_001f68e0(u8 *arg0);
u8 *func_00202400(s32 param_1, s32 param_2);
void func_001acf50(u8 *arg0) {
    struct {
        s32 sp30;
        u8 pad[0x1A];
        u16 sp4E;
    } locals;
    u16 var_2;
    u8 *temp_2;
    u8 *temp_4;
    void func_001a03b0();
    u8 *func_001f3870(u8 *arg0, s8 arg1);
    u8 *var_16;

    switch (*(u16 *)(arg0 + 0x6C)) {
    case 7:
        func_001a03b0();
        temp_2 = func_0019e7c0(0, 3);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 0);
        if (*(s16 *)(arg0 + 0xEC) != 0) {
            temp_2 = func_00202400(*(s32 *)(arg0 + 0x30), *(s16 *)(arg0 + 0xEC));
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 3);
        } else {
            temp_4 = *(u8 **)(arg0 + 0x30);
            if ((*(s32 *)(temp_4 + 0x9C) & 0x4000) != 0) {
                var_2 = *(u16 *)(arg0 + 0x6C);
            } else {
                var_2 = 8;
            }
            temp_2 = func_002022e0((u32)temp_4, var_2 & 0xFFFF);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 3);
        }
        temp_2 = func_001f99c0(arg0, 0x16, 0, 0, 0);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 1);
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x4000) != 0) {
            temp_2 = func_001bc920(arg0, 0x32);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 0);
            if ((s16)func_00198810(*(u8 **)(arg0 + 0x30)) != 0x11) {
                var_16 = func_0019a980((BtlUnit *)*(u8 **)(arg0 + 0x30));
                *(s64 *)(var_16 + 0x60) = *(s64 *)arg0;
                func_00194590(var_16, 0);
            } else {
                var_16 = func_00194b60();
                *(s64 *)(var_16 + 0x60) = *(s64 *)arg0;
                func_00194590(var_16, 0);
            }
            func_001f0a10((u8 *)&locals.sp30);
            locals.sp4E |= 0x80;
            temp_2 = func_001f36e0((s32)arg0, (s32)arg0, &locals.sp30, 1, 1);
            *(s8 *)(temp_2 + 0) = 4;
            *(s64 *)(temp_2 + 8) = *(s64 *)(var_16 + 0x58);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 1);
            temp_2 = func_00199ee0(*(u8 **)(arg0 + 0x30), 0x18, 6, 1, 1.0f);
            *(s8 *)(temp_2 + 0) = 4;
            *(s64 *)(temp_2 + 8) = *(s64 *)(var_16 + 0x58);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 0);
        } else {
            temp_2 = func_001bc920(arg0, 0xA);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 0);
        }
        break;
    case 8:
    case 11:
        break;
    }
    func_00194590(func_001f3870(arg0, 0), 1);
    if ((func_001f68e0(arg0) != 0) && (*(u16 *)(arg0 + 0x6C) != 8)) {
        func_001b0800(arg0, 0x1B);
        return;
    }
    func_001b0800(arg0, 0x20);
}
// FUN_001AD280
void func_001ad280(u8 *arg0)
{
    s16 sp20[8];
    u8 *temp_2;

    func_001a03b0((s64 *)arg0);
    temp_2 = func_0019e550(
        *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30),
        *(u8 **)(arg0 + 0x30),
        0);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 1);
    temp_2 = func_0019e550(
        *(u8 **)(arg0 + 0x30),
        *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30),
        0);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 1);
    *(u16 *)(arg0 + 0x18) |= 0x200;
    temp_2 = (u8 *)func_001d3700(3, 0xFFF);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    temp_2 = func_001bc920(arg0, 9);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    sp20[0] = 5;
    temp_2 = func_001fa720((u8 *)&sp20[0]);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 1);
    if (func_001eb860() == 1) {
        *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
        func_00212240(*(u8 **)(D_0076449C + 0xDD4), 0);
    }
    *(s32 *)(arg0 + 0x41C) = 0;
}
// FUN_001AD3E0
void func_001ad3e0(u8 *arg0)
{
    u8 *temp;

    if (*(s32 *)(arg0 + 0x41C) != 0) {
        goto common;
    }
    if (func_00193bf0(*(s64 *)arg0, 0x3FFFFFFFFFFFFFFFLL) != 0) {
        goto done;
    }
    func_00218420(*(s32 *)(D_0076449C + 0xDD4), arg0);
    temp = func_001fa8f0();
    *(s64 *)(temp + 0x60) = *(s64 *)arg0;
    func_00194590(temp, 1);
    *(s32 *)(arg0 + 0x41C) = 1;
common:
    if (func_002184a0(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
        goto done;
    }
    if (func_001eb860() != 1) {
        goto after_flag;
    }
    *(s32 *)(D_0076449C + 0xC) |= 0x2000;
    func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
after_flag:
    if (func_002184d0(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
        goto alternate;
    }
    func_001b0800(arg0, 0x1D);
    goto after_state;
alternate:
    func_001b0800(arg0, 0x20);
after_state:
    temp = func_001faa60();
    *(s64 *)(temp + 0x60) = *(s64 *)arg0;
    func_00194590(temp, 1);
    func_00218500(*(s32 *)(D_0076449C + 0xDD4));
done:
    return;
}
// FUN_001AD540
void func_001ad540(void)
{
}
/* measured: live object 1616B/window 1584B (32B over, 2.0% within 3%), fndiff 319 differing words with peephole off (guard below; frame -0x110 vs -0xF0, obj 403 vs retail 396 instrs, edit 198 +2 reloc-only). Re-derived from retail plus matched packet idiom (a03b0/bc920/94590 chain, 95850/94ff0/dcb40 second loop); truthful externs (f32 for 8218/8350 scale floats, void-ptr plus RwV3d for dcb40, s32 for A4 index, s16 kept for +0x22). Walls: s-reg rotation (obj 8 vs retail 7), stack-slot shift (+0x20/+0x30), lh plus dsll/dsra vs retail lh. Ruled out today: nocache 369, reorder tie 320, lim-hoist 325, loopinv 325, for-tie 318, u16-tbl 319 (rejected: lh-to-lhu opcode untruthful; combined 318 not taken); prior O0/1/3/4 458/368/349/349 (O2 342), pragma sched 348/cs 368/li 348/prop 357/sr-dead-unroll tie 342, peephole off 320-to-319 (applied: s32 a4 plus void-ptr/RwV3d). Production stays ASM; banked as floor. Real-tree re-measure 319, probe r5 319 vs nocache 369, verify 53M/18A/0MM, lint 0E. */
// FUN_001AD550 NONMATCHING
#ifdef NON_MATCHING
#pragma peephole off
void func_001ad550(s64 *arg0)
{
    extern void func_00195850(u8 *arg0, f32 *arg1);
    extern void func_003dcb40(void *out, const void *in, s32 count, const void *quat);
    extern u8 *func_001973f0(u8 *arg0, f32 *arg1, s32 arg2, f32 arg3);
    extern u8 *func_00193770(s32 arg0);
    extern u8 *func_001f7d10(s32 arg0, s32 arg1, s32 arg2);
    extern RwV3d D_0060A100;
    extern f32 fGpffff8218;
    extern f32 fGpffff8350;
    u8 *collected[12];
    f32 posD0[3];
    f32 vecC0[3];
    f32 outE0[3];
    f32 quat80[4];
    u8 *unit30;
    u8 *tmp;
    u8 *iter;
    u8 kind;
    s32 var5;
    s32 var21;
    s32 var16;
    s32 idx;
    s64 var18;

    func_001a03b0(arg0);
    tmp = func_002022e0((u32)*(u8 **)((u8 *)arg0 + 0x30), 6);
    *(s64 *)(tmp + 0x60) = *arg0;
    func_00194590(tmp, 3);
    var5 = 0;
    var21 = 0;
    var16 = 0;
    var18 = 0;
    unit30 = *(u8 **)((u8 *)arg0 + 0x30);
    kind = *(u8 *)(unit30 + 0xA2);
    if (kind == 1) {
        goto case_one;
    }
    if (kind != 0) {
        goto after_switch;
    }
    if (*(u16 *)((u8 *)arg0 + 0x6C) == 0xC) {
        goto case_one;
    }
    *(u16 *)(D_0076449C + 0xC5E) = *(u16 *)(D_0076449C + 0xC5E) + 1;
    var21 = 1;
    iter = *(u8 **)(D_0076449C + 0x174);
    goto loop_check;
loop_body:
    if ((*(u16 *)(iter + 0x1A) & 1) != 0) {
        u8 *u = *(u8 **)(iter + 0x30);
        if (*(u8 *)(u + 0xA2) == 0) {
            if (func_002428f0(*(u8 **)(u + 0xA64), 0) == 0) {
                if (func_00232710((s32)*(u8 **)(u + 0xA64), 0x100001) == 0) {
                    collected[(var16 & 0xFFFF)] = iter;
                    var16 = (var16 + 1) & 0xFFFF;
                }
            }
        }
    }
    iter = *(u8 **)(iter + 0x450);
loop_check:
    if (iter != NULL) {
        goto loop_body;
    }
    var5 = 1;
    goto after_switch;
case_one:
    collected[0] = (u8 *)arg0;
    var16 = 1 & 0xFFFF;
    *(u16 *)((u8 *)arg0 + 0x18) |= 0x20;
    *(u16 *)((u8 *)arg0 + 0x1A) &= 0xFFF7;
after_switch:
    if (var5 == 0) {
        u8 *q = func_001bc920(collected[0], 0xA);
        *(s64 *)(q + 0x60) = *arg0;
        func_00194590(q, 0);
    }
    unit30 = *(u8 **)((u8 *)arg0 + 0x30);
    if (*(u8 *)(unit30 + 0xA2) == 0) {
        u8 *r = func_001f7d10(0xF, 2, 0);
        *r = 5;
        *(s64 *)(r + 8) = *(s64 *)(tmp + 0x58);
        *(u16 *)(r + 0x48) = 0x1A;
        *(s64 *)(r + 0x60) = *arg0;
        func_00194590(r, 1);
        if (*(u16 *)((u8 *)arg0 + 0x6C) == 0xC) {
            u8 *s = (u8 *)func_001f5f70((u8 *)arg0, 7, 0, 0, 0);
            *(s64 *)(s + 0x60) = *arg0;
            func_00194590(s, 1);
        } else if (var21 == 1) {
            u8 *t = func_00202850();
            *t = 5;
            *(s64 *)(t + 8) = *(s64 *)(tmp + 0x58);
            *(u16 *)(t + 0x48) = 0x10;
            *(s64 *)(t + 0x60) = *arg0;
            func_00194590(t, 1);
        }
    } else {
        u8 *r = (u8 *)func_001f7c20(0xC, 2, 0xF);
        *r = 5;
        *(s64 *)(r + 8) = *(s64 *)(tmp + 0x58);
        *(u16 *)(r + 0x48) = 0x16;
        *(s64 *)(r + 0x60) = *arg0;
        func_00194590(r, 1);
        {
            u8 *s = (u8 *)func_001f5f70((u8 *)arg0, 6, 0, 0, 0);
            *(u16 *)(s + 0x48) = 0xC;
            *(s64 *)(s + 0x60) = *arg0;
            func_00194590(s, 1);
        }
    }
    idx = 0;
    goto second_check;
second_body:
    {
        u8 *cur = collected[(idx & 0xFFFF)];
        u8 *u30 = *(u8 **)(cur + 0x30);
        u8 *qpkt;
        func_00195850(u30, posD0);
        func_00194ff0(u30, NULL, quat80, NULL);
        func_003dcb40(vecC0, &D_0060A100, 1, quat80);
        unit30 = *(u8 **)((u8 *)arg0 + 0x30);
        if (*(u8 *)(unit30 + 0xA2) == 0) {
            vecC0[0] = vecC0[0] * 500.0f;
            vecC0[1] = vecC0[1] * 500.0f;
            vecC0[2] = vecC0[2] * 500.0f;
            outE0[0] = posD0[0] + vecC0[0];
            outE0[1] = posD0[1] + vecC0[1];
            outE0[2] = posD0[2] + vecC0[2];
            qpkt = func_001973f0(u30, outE0, 0, 0.5f);
            goto qpkt_done;
        } else {
            u8 *u2 = *(u8 **)(cur + 0x30);
            s32 a4 = *(u16 *)(u2 + 0xA4);
            s32 e = ((a4 << 3) - a4) << 2;
            e = (e + a4) << 3;
            {
                u8 *tbase = iGpffffb3cc;
                u8 *ent = tbase + e;
                if (*(s16 *)(ent + 0x22) != 1) {
                    f32 k = fGpffff8350;
                    vecC0[0] = vecC0[0] * k;
                    vecC0[1] = vecC0[1] * k;
                    vecC0[2] = vecC0[2] * k;
                    outE0[0] = posD0[0] + vecC0[0];
                    outE0[1] = posD0[1] + vecC0[1];
                    outE0[2] = posD0[2] + vecC0[2];
                } else {
                    outE0[0] = posD0[0];
                    outE0[1] = posD0[1];
                    outE0[2] = posD0[2];
                }
            }
            qpkt = func_001973f0(u30, outE0, 4, fGpffff8218);
        }
qpkt_done:
        *qpkt = 5;
        *(s64 *)(qpkt + 8) = *(s64 *)(tmp + 0x58);
        *(u16 *)(qpkt + 0x48) = 0x10;
        *(s64 *)(qpkt + 0x60) = *arg0;
        func_00194590(qpkt, 1);
        {
            u8 *bpkt = (u8 *)func_0019bbe0(u30, 0xFFFFFF, 8, 0, 4, 0);
            *bpkt = 5;
            *(s64 *)(bpkt + 8) = *(s64 *)(qpkt + 0x58);
            *(u16 *)(bpkt + 0x48) = 0xC;
            *(s64 *)(bpkt + 0x60) = *arg0;
            func_00194590(bpkt, 1);
            var18 = *(s64 *)(bpkt + 0x58);
        }
    }
    idx = (idx + 1) & 0xFFFF;
second_check:
    if ((idx & 0xFFFF) < (var16 & 0xFFFF)) {
        goto second_body;
    }
    if (var21 != 0) {
        u8 *z = func_00193770(0x80);
        *z = 4;
        *(s64 *)(z + 8) = var18;
        *(z + 0x10) = 0xA;
        *(u16 *)(z + 0x18) = 0x801;
        *(s64 *)(z + 0x60) = *arg0;
        func_00194590(z, 1);
        *(u16 *)(D_0076449C + 0x1C) = 3;
    }
    {
        u8 *f = func_001f3870(arg0, 0);
        *(s64 *)(f + 0x60) = *arg0;
        func_00194590(f, 1);
    }
    func_001b0800((u8 *)arg0, 0x20);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ad550);
#endif
#pragma peephole on
/* Measured: 644/656 bytes, 22 resolved relocations and 12 zero tail bytes.
 * Packet submissions retain callback-visible unit, UID and global reloads. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_001ADB80
void func_001adb80(s64 *arg0)
{
    u16 person;
    u32 unit;
    s32 var_2;
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_6;
    u8 *temp_7;

    temp_4 = *(u16 *)((u8 *)arg0 + 0x1A);
    if ((temp_4 & 1) == 0) {
        var_2 = 0;
    } else {
        temp_6 = *(u8 **)((u8 *)arg0 + 0x30);
        temp_7 = *(u8 **)(temp_6 + 0xA0C);
        if ((temp_4 & 0x10) == 0) {
            var_2 = 0;
        } else if ((*(s32 *)(temp_7 + 0x98) & 2) != 0) {
            var_2 = 1;
        } else {
            var_2 = 0;
        }
    }
    if (var_2 != 0) {
        temp_2 = func_0019b6a0(
            *(s32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA0C));
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 1);
    }
    func_001a03b0(arg0);
    temp_2_2 = func_002022e0(
        *(u32 *)((u8 *)arg0 + 0x30),
        *(u16 *)((u8 *)arg0 + 0x6C));
    *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_2, 3);
    temp_2_3 = func_001bc920((u8 *)arg0, 0x1F);
    *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_3, 0);
    temp_2_4 = func_00199ee0(*(u8 **)((u8 *)arg0 + 0x30),
                             0x19, 0, 0, 1.0f);
    *(s64 *)(temp_2_4 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_4, 0);
    temp_2_5 = func_001f99c0((u8 *)arg0, 0x15, 0, 0, 0);
    *(s64 *)(temp_2_5 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_5, 1);
    if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2) == 0) {
        func_0010b300(*(u16 *)((u8 *)arg0 + 0x74));
        person = *(u16 *)((u8 *)arg0 + 0x74);
        func_0019ef30(*(u8 **)((u8 *)arg0 + 0x30), person);
        func_0010b7f0();
        if (func_00106330(0x3C) != 0) {
            temp_2_6 = *(u8 **)((u8 *)arg0 + 0x3F0);
            if (temp_2_6 != NULL) {
                *(s16 *)(temp_2_6 + 6) = 0;
                *(s16 *)(*(u8 **)((u8 *)arg0 + 0x3F0) + 4) = 0;
            }
        }
    }
    unit = *(u32 *)((u8 *)arg0 + 0x30);
    temp_2_7 = (u8 *)func_001d6240(
        *(s32 *)(D_0076449C + 0xD3C),
        unit, unit,
        0, 0);
    *(s16 *)(temp_2_7 + 0x48) = 0xF;
    *(s64 *)(temp_2_7 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_7, 2);
    temp_2_8 = (u8 *)func_001f7c20(0xA, 2, 6);
    *(s8 *)(temp_2_8 + 0) = 5;
    *(s64 *)(temp_2_8 + 8) = *(s64 *)(temp_2_7 + 0x58);
    *(s64 *)(temp_2_8 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_8, 1);
    *(s32 *)(D_0076449C + 0xC) |= 0x400000;
    *(u16 *)(D_0076449C + 0x18) |= 5;
}
#pragma pop

// FUN_001ADE10
void func_001ade10(s64 *arg0)
{
    void func_001b0800(u8 *arg0, u16 arg1);

    if (func_00193bf0(*arg0, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2) == 0) {
            *(u16 *)((u8 *)arg0 + 0x18) &= 0xFBFF;
        }
        func_001b0800((u8 *)arg0, *(u16 *)((u8 *)arg0 + 0x14));
    }
}
// FUN_001ADE90
void func_001ade90(void)
{
}
/* measured 001adea0: schedule on inside the guard is worth 1 word (271 -> 270, sweep-measured) but churns alignment (277 -> 237 instrs, 189 -> 337 edits); body remains distant (50 short pre-schedule, 90 short now) with unrecovered dispatch structure and needs reconstruction; sp64 dead store pre-existing (H007). Production stays ASM. */
// FUN_001ADEA0 NONMATCHING
#ifdef SKIP_ASM
#pragma schedule on
void func_001adea0(u8 *arg0)
{
    u8 *t18;
    s64 t16;
    u32 sw;
    s32 sp60;
    s32 sp64;
    u16 sp7E;
    s32 t2;
    u8 *pkt;

    if (func_00193cd0(0x700) == 0 && func_00193cd0(0x506) == 0 && func_00193cd0(0x507) == 0) {
        t18 = *(u8 **)(arg0 + 48);
        t16 = *(s64 *)arg0;
        sw = ((u32)func_002326e0(*(s32 *)(t18 + 2660)) << 20) >> 20;
        if (sw == 0x20) {
            func_001f0a10((u8 *)&sp60);
            sp7E = sp7E | 0x100;
            t2 = func_001f6d60(arg0);
            sp60 = t2;
            if (t2 < 0) {
                pkt = func_001f36e0((s32)arg0, (s32)arg0, &sp60, 1, 1);
                *(s16 *)(pkt + 72) = 12;
                func_00194590(pkt, 1);
                pkt = func_00202740(t18);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                func_00194590(pkt, 1);
                pkt = func_00201de0((s32)t18, (s32)t18, -1, 0, 0, 0, 1, (u8 *)&sp60, 0);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 71) = *(pkt + 71) & 0xDF;
                func_00194590(pkt, 3);
                pkt = func_00202590(t18, 0, 0);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 71) = *(pkt + 71) & 0xDF;
                func_00194590(pkt, 3);
                pkt = func_00199ee0(*(u8 **)(arg0 + 48), -2, 0, 0, 1.0f);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 32) = 10;
                *(s16 *)(pkt + 40) = 769;
                *(s64 *)(pkt + 96) = t16;
                func_00194590(pkt, 0);
                pkt = (u8 *)func_001f7c20(10, 2, 24);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                func_00194590(pkt, 1);
            }
            {
                u16 f = *(u16 *)(arg0 + 108);
                if (f != 2 && f != 3 && f != 1) {
                }
            }
            func_001b0800(arg0, 32);
            return;
        } else if (sw == 0x40) {
            func_001f0a10((u8 *)&sp60);
            sp7E = sp7E | 0x100;
            t2 = func_001f6d60(arg0);
            sp64 = t2;
            if (t2 < 0) {
                pkt = func_001f36e0((s32)arg0, (s32)arg0, &sp60, 1, 1);
                *(s16 *)(pkt + 72) = 12;
                func_00194590(pkt, 1);
                pkt = func_00202740(t18);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                func_00194590(pkt, 1);
                pkt = func_00201de0((s32)t18, (s32)t18, -1, 0, 0, 0, 1, (u8 *)&sp60, 0);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 71) = *(pkt + 71) & 0xDF;
                func_00194590(pkt, 3);
                pkt = func_00202590(t18, 1, 0);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 71) = *(pkt + 71) & 0xDF;
                func_00194590(pkt, 3);
                pkt = func_00199ee0(*(u8 **)(arg0 + 48), -2, 0, 0, 1.0f);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 32) = 10;
                *(s16 *)(pkt + 40) = 769;
                *(s64 *)(pkt + 96) = t16;
                func_00194590(pkt, 0);
                pkt = (u8 *)func_001f7c20(10, 2, 24);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                func_00194590(pkt, 1);
            }
            {
                u16 f = *(u16 *)(arg0 + 108);
                if (f != 2 && f != 3 && f != 1) {
                }
            }
            func_001b0800(arg0, 32);
            return;
        } else {
            u16 f = *(u16 *)(arg0 + 108);
            u16 v;
            if (f != 2 && f != 3 && f != 1) {
                v = 32;
            } else {
                v = 32;
            }
            func_001b0800(arg0, v);
        }
    }
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001adea0);
#endif
// FUN_001AE3C0
s32 func_001ae3c0(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x428);
}
// FUN_001AE3D0 NONMATCHING
/* measured: live object 1076B/window 1072B, normalized_diff 123 (installed guard below; first real floor, replaces the SKIP_ASM stub; object exceeds window by 4B). Recovery from docs/probe_archive/L1A_001ae3d0_body.c: list-node packet fill, ==0/arg-first arm swap, v=0-first structure, u32 sel. Open walls: s3-hoist of the 2672-half before the 1d15a0 call, deep-lookahead temp coloring, pr-stack-slot layout, bne-operand canonicalization; the (s16)-cast extend pair is load-bearing. Banked as floor. */
#ifdef NON_MATCHING
void func_001ae3d0(u8 *arg0)
{
    u8 *lst;
    u8 *found;
    u32 entry;
    u8 *entryp;
    u8 *pkt;
    u16 pr[2];
    u32 sel;
    s32 v;
    u32 t;
    s16 h2;
    s32 cu;

    lst = *(u8 **)(iGpffffb3ac + 372);
    while (lst != NULL) {
        if (func_001a05f0(lst) != 0) {
            pkt = func_0019b6a0((s32)*(u8 **)(*(u8 **)(lst + 48) + 2572));
            *(s64 *)(pkt + 96) = *(s64 *)lst;
            func_00194590(pkt, 1);
        }
        lst = *(u8 **)(lst + 1104);
    }
    found = NULL;
    if (*(u8 *)(*(u8 **)(arg0 + 48) + 162) == 0) {
        sel = (u32)arg0;
    } else {
        sel = (u32)*(u8 **)(arg0 + 56);
    }
    if (sel != 0) {
        u32 n = *(u16 *)(iGpffffb3ac + 3160);
        u16 i = 0;
        while (((i & 0xFFFF)) < n) {
            if (*(u32 *)(iGpffffb3ac + ((i & 0xFFFF) * 4) + 3144) == sel) {
                found = (u8 *)sel;
                break;
            }
            i = (i + 1) & 0xFFFF;
        }
    }
    if (found == NULL) {
        found = *(u8 **)(iGpffffb3ac + (func_00231d70(*(u16 *)(iGpffffb3ac + 3160)) & 0xFFFF) * 4 + 3144);
    }
    pr[0] = 1;
    pr[1] = *(u16 *)(*(u8 **)(found + 48) + 164);
    pkt = func_001fa720((u8 *)pr);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 1);
    v = 0;
    if (*(u8 *)(*(u8 **)(arg0 + 48) + 162) == 0) {
        if (*(s16 *)(iGpffffb3ac + 2672) != -1) {
            t = func_001ef720(2, 0x80000) & 0xFFFF;
            if ((u32)((s16)(*(s16 *)(iGpffffb3ac + 2674) >> 1)) < t) {
                v = 0;
            } else {
                h2 = *(s16 *)(iGpffffb3ac + 2672);
                if (h2 == (s16)func_001d15a0((s32)t)) {
                    v = 0;
                } else {
                    v = 1;
                }
            }
        }
    }
    if (v != 0) {
        pkt = (u8 *)func_001d3900(1);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
    }
    pkt = func_00199ee0(*(u8 **)(*(u8 **)(iGpffffb3ac + 368) + 48), 0, 0, 1, 1.0f);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    cu = 0;
    while (((cu & 0xFFFF)) < *(u16 *)(iGpffffb3ac + 3160)) {
        entryp = *(u8 **)(iGpffffb3ac + ((cu & 0xFFFF) * 4) + 3144);
        pkt = func_00199ee0(*(u8 **)(entryp + 48), 0, 0, 1, 1.0f);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
        cu = (cu + 1) & 0xFFFF;
    }
    pkt = (u8 *)func_001d3700(3, 0xFFF);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    pkt = func_0019e9f0(0, 3);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 1);
    pkt = func_0019e7c0(0, 3);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 1);
    pkt = func_001d3d00(arg0);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    pkt = (u8 *)func_001ba090(0);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    pkt = func_001bc920(arg0, 7);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    entry = *(u32 *)(iGpffffb3ac + 12);
    entry = entry & 0xFFBFFFFF;
    *(u32 *)(iGpffffb3ac + 12) = entry;
    *(u16 *)(iGpffffb3ac + 24) = 0;
    if (func_001eb860() == 1) {
        entry = *(u32 *)(iGpffffb3ac + 12);
        entry = entry & ~0x2000;
        *(u32 *)(iGpffffb3ac + 12) = entry;
        func_00212240(*(u8 **)(iGpffffb3ac + 3540), 0);
    }
    *(u8 **)(arg0 + 1052) = found;
    *(s32 *)(arg0 + 1056) = 0;
    *(s32 *)(arg0 + 1060) = 0;
    *(s32 *)(arg0 + 1064) = 0;
    *(u16 *)(arg0 + 1068) = 12;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ae3d0);
#endif
// FUN_001AE800
void func_001ae800(u8 *arg0)
{
    u8 *gp2;
    u8 *packet1;
    u8 *packet2;
    u8 *packet3;
    u8 *packet4;
    u16 i;
    u32 loop_i;
    u8 frame[0x10];

    if (*(s32 *)(arg0 + 0x424) == 0) {
        if (func_00193cd0(0xC00) != 0) {
            return;
        }
        if (func_00193cd0(0xC04) != 0) {
            return;
        }
        *(s16 *)frame = 0;
        i = 0;
        gp2 = D_0076449C;
        while ((s32)(loop_i = i) < *(u16 *)(gp2 + 0xC58)) {
            packet1 = *(u8 **)(gp2 + 0xC48 + ((u32)i * 4));
            *(u16 *)(frame + 2 + ((u32)i * 2)) =
                *(u16 *)(*(u8 **)(packet1 + 0x30) + 0xA4);
            i++;
        }
        *(u16 *)(frame + 8) = *(u16 *)(gp2 + 0xC58);
        packet1 = func_001fa110(frame);
        func_00194590(packet1, 1);
        packet2 = func_001fa8f0();
        *(s16 *)(packet2 + 0x48) = *(s16 *)(arg0 + 0x42C);
        func_00194590(packet2, 1);
        packet3 = func_00194c90((s32)func_001ae3c0, (s32)arg0);
        *(s16 *)(packet3 + 0x48) = *(s16 *)(arg0 + 0x42C);
        func_00194590(packet3, 1);
        packet4 = func_001d65d0(
            *(s32 *)(D_0076449C + 0xD8C),
            *(s32 *)(arg0 + 0x30), 0,
            *(s64 *)(packet3 + 0x58), 0x8000);
        *(s16 *)(packet4 + 0x48) = *(s16 *)(arg0 + 0x42C);
        func_00194590(packet4, 2);
        *(s32 *)(arg0 + 0x424) = 1;
    }

    if (*(s32 *)(arg0 + 0x420) == 0) {
        if (*(s16 *)(arg0 + 0x42C) <= 0) {
            func_00218160(*(u8 **)(D_0076449C + 0xDD4),
                          *(u8 **)(arg0 + 0x41C));
            *(s32 *)(arg0 + 0x420) = 1;
        } else {
            *(s16 *)(arg0 + 0x42C) = *(s16 *)(arg0 + 0x42C) - 1;
        }
    }

    if (func_00193bf0(*(u64 *)arg0,
                      0x3FFFFFFFFFFFFFFFULL) != 0) {
        return;
    }

    if (*(s32 *)(arg0 + 0x428) == 0) {
        if (func_00218200(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            return;
        }
        if (func_00218230(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            packet1 = func_001f3870((s64 *)arg0, 2);
            *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
            func_00194590(packet1, 1);
            *(s32 *)(*(u8 **)(D_0076449C + 0x170) + 0x434) =
                *(s32 *)(arg0 + 0x41C);
            *(s16 *)(*(u8 **)(D_0076449C + 0x170) + 0x16) = 0x1F;
            func_001b0e30(*(s32 *)(D_0076449C + 0x170));
            packet2 = (u8 *)func_001b1540();
            if ((*(u8 *)(*(u8 **)(packet2 + 0x30) + 0xA2) == 0) &&
                (*(u8 *)(packet2 + 0x28) != 0)) {
                *(u16 *)(packet2 + 0x18) |= 0x8000;
            }
            func_00194590(
                func_001f99c0(*(u8 **)(arg0 + 0x41C), 6, 1, 0, 0), 1);
        } else {
            func_00194590(
                func_001f99c0(*(u8 **)(arg0 + 0x41C), 6, 0, 0, 0), 1);
            packet1 = func_001fa450();
            *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
            func_00194590(packet1, 1);
        }

        packet1 = func_001faa60();
        *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
        func_00194590(packet1, 1);
        packet2 = func_0019e7c0(0, 1);
        *(u64 *)(packet2 + 0x60) = *(u64 *)arg0;
        func_00194590(packet2, 1);
        *(u16 *)(arg0 + 0x18) &= 0xFFF7;
        if (func_001eb860() == 1) {
            *(s32 *)(D_0076449C + 0xC) |= 0x2000;
            func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
        }
        *(s32 *)(arg0 + 0x428) = 1;
        *(u16 *)(arg0 + 0x42E) = 6;
        return;
    }

    if (*(u16 *)(arg0 + 0x42E) == 0) {
        func_00218260(*(s32 *)(D_0076449C + 0xDD4));
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 7;
        func_001b0800(arg0, 0x20);
        return;
    }
    *(u16 *)(arg0 + 0x42E) = *(u16 *)(arg0 + 0x42E) - 1;
}
// FUN_001AEC20
void func_001aec20(u8 *arg0)
{
    s32 temp_3_3;
    s32 var_4;
    s32 var_6;
    s32 var_5;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_3_2;

    func_001eb3b0(arg0 + 0x38);
    func_001d7f10(arg0, arg0 + 0x98, 0x100, 0);
    var_4 = 0;
    goto loop_2_test;
loop_2_body:
    temp_3_2 = arg0 + ((u16)var_4 * 4);
    *(s32 *)(temp_3_2 + 0x38) = *(s32 *)(temp_3_2 + 0x98);
    var_4 = (var_4 + 1) & 0xFFFF;
loop_2_test:
    temp_3 = *(u16 *)(arg0 + 0xD0);
    if ((var_4 & 0xFFFF) < temp_3) {
        goto loop_2_body;
    }
    *(u16 *)(arg0 + 0x6A) = temp_3;
    *(s16 *)(arg0 + 0x6C) = 2;
    *(s16 *)(arg0 + 0x6E) = 0x100;
    func_001f14f0(arg0);
    var_6 = 0;
    var_5 = 0;
    temp_4 = *(u16 *)(arg0 + 0x6A);
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(*(u8 **)(arg0 + ((u16)var_5 * 4) + 0x38) + 0xE0) != 0) {
        var_6 = (var_6 + 1) & 0xFFFF;
    }
    var_5 = (var_5 + 1) & 0xFFFF;
loop_7_test:
    if ((var_5 & 0xFFFF) < temp_4) {
        goto loop_7_body;
    }
    temp_3_3 = var_6 & 0xFFFF;
    if (temp_4 == temp_3_3) {
        *(s16 *)(arg0 + 0x6E) = 0x102;
        return;
    }
    if (temp_3_3 != 0) {
        *(s16 *)(arg0 + 0x6E) = 0x100;
        return;
    }
    *(s16 *)(arg0 + 0x6E) = 0x101;
}
/* measured 001aed50 (WCold): m2c + romwright cold drafts de-noised to file idiom (u8* + truthful externs per tree: d3d50(s32)/d3e00(u32)/d43f0(s32)/d5eb0(s32,void*,s32)/d69f0(s32,void*)/d7bf0(u32,u32,u32)->u8* leftover/ fa320(void)->u8* leftover/f3950(u8*)/ef4a0(s32)/230340(u8*)/232710(s32,u32)/2428f0(s32,s32)/b7060(u32,s32*,s32*)/b7080(s32)/b7090(s32)/b70a0(u32,s32*,s32*)/b7880(s32,s32,s32)/b83f0(s32*5)/b9560(s32,s32)/b9de0(u8*,u16,s32) leftover/b7e20(s32)/b9360(s32,s32)/b99a0(s32)/b0800(u8*,u16)/f81f0(s32,u8*) + D_005F6D38/48/58 + iGpffffb3bc local, file decls reused for 94590/f3870(s64*,s8)/f7c20/f99c0/99ee0/98300/19bbe0/19a980/201de0/202740/202590(s32,s8,s16) local/d6240; workBuf[128] at 0x130 + tmpBuf[32] at 0x1B0 (f0a10/f36e0 32B contract) + sp1D8[3] at 0x1D8 + sp100(s32 sign-extended aux)/sp110(u16) + distinct t1-t35 SSA temps for short-lived packets (long-lived pkt/pkt12C/pkt128/unit30/cur58/tmpS kept); probe v1 694 -> v2 696 (tmpBuf32+sp1D8[3]) -> loopinv 684 (-12 kept) vs csoff 710/unroll/sched tie/propOff 732/deadOff tie -> v4 SSA 675 (-9 kept) -> off tie/uidlast tie/v7 truthful widths (u8 D9 + s32 spE0 word, no (s16) casts) tie; fnalign retail 798 vs object 790 (-8, -1.0% inside 3%, 211 edits +11 reloc-only via fnalign --candidate); wscan_pairs obj 3 dsll32/dsra32 vs retail 1 (2 extra conversion pairs, time-boxed per 7m/7l); frame -0x1E0 vs retail -0x1F0 (16 short, 3 quad slots B0/C0/D0 as s32 vs retail sq/lq) + s-reg rotation (self-consistent, banked wall) + sp100/sp110 sw/lw vs sh/lhu placement shift. Production stays ASM; banked as floor. Evidence in /var/tmp/cold1aed50/ (m2c.c/rom.c/types.txt/cand_v*.c). */
// FUN_001AED50 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_001aed50(u8 *arg0)
{
    extern s32 func_001d3d50(s32 arg0);
    extern void func_001d3e00(u32 arg0);
    extern u32 func_001d43f0(s32 arg0);
    extern u8 *func_001d5eb0(s32 arg0, void *arg1, s32 arg2);
    extern void func_001d69f0(s32 arg0, void *arg1);
    extern u8 *func_001d7bf0(u32 arg0, u32 arg1, u32 arg2);
    extern u8 *func_001fa320(void);
    extern u8 *func_001f3950(u8 *arg0);
    extern s32 func_001ef4a0(s32 arg0);
    extern void func_00230340(u8 *arg0);
    extern u32 func_00232710(s32 arg0, u32 arg1);
    extern s32 func_002428f0(s32 arg0, s32 arg1);
    extern void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2);
    extern s32 func_001b7080(s32 arg0);
    extern s32 func_001b7090(s32 arg0);
    extern void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2);
    extern u8 *func_001b7880(s32 arg0, s32 arg1, s32 arg2);
    extern u8 *func_001b83f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern u8 *func_001b9560(s32 arg0, s32 arg1);
    extern u8 *func_001b9de0(u8 *arg0, u16 arg1, s32 arg2);
    extern u8 *func_001b7e20(s32 arg0);
    extern u8 *func_001b9360(s32 arg0, s32 arg1);
    extern u8 *func_001b99a0(s32 arg0);
    extern void func_001b0800(u8 *arg0, u16 arg1);
    extern u8 *func_001f81f0(s32 arg0, u8 *arg1);
    extern u8 *func_0019a980(u8 *arg0);
    extern u8 *func_00202590(s32 arg0, s8 arg1, s16 arg2);
    extern u8 D_005F6D38[];
    extern u8 D_005F6D48[];
    extern u8 D_005F6D58[];
    extern u8 *iGpffffb3bc;
    s64 uid;
    u16 aux;
    s32 handle;
    s32 outHi;
    s32 outLo;
    u8 workBuf[128];
    u8 tmpBuf[32];
    s32 sp1D8[3];
    s32 sp100;
    u16 sp110;
    s32 var23;
    s32 var22;
    u8 *t1;
    u8 *t2;
    u8 *t3;
    u8 *t4;
    u8 *t5;
    u8 *t6;
    u8 *t7;
    u8 *t8;
    u8 *t9;
    u8 *t10;
    u8 *t11;
    u8 *t12;
    u8 *t13;
    u8 *t14;
    u8 *t15;
    u8 *t16;
    u8 *t17;
    u8 *t18;
    u8 *t19;
    u8 *t20;
    u8 *t21;
    u8 *t22;
    u8 *t23;
    u8 *t24;
    u8 *t25;
    u8 *t26;
    u8 *t27;
    u8 *t28;
    u8 *t29;
    u8 *t30;
    u8 *t31;
    u8 *t32;
    u8 *t33;
    u8 *t34;
    u8 *t35;
    u8 *pkt12C;
    u8 *pkt128;
    u8 *unit17;
    u8 *unit19;
    u8 *unit30;
    u8 *pkt;
    s64 cur58;
    s32 tmpS;
    s32 k;
    s32 j;
    u8 *list;
    u8 *elem28;
    uid = *(s64 *)arg0;
    handle = func_001d3d50(1);
    list = *(u8 **)(iGpffffb3ac + 0x174);
loop_4:
    if (list != NULL) {
        elem28 = *(u8 **)(list + 0x28);
        if (*(u8 *)(list + 0x28) != 0) {
            t1 = func_001f3870((s64 *)list, 2);
            *(s64 *)(elem28 + 0x60) = uid;
            func_00194590(elem28, 1);
        }
        list = *(u8 **)(list + 0x450);
        goto loop_4;
    }
    aux = *(u16 *)(arg0 + 0x6E);
    k = 0;
loop_7:
    if ((k & 0xFFFF) < (s32)*(u16 *)(iGpffffb3ac + 0xC58)) {
        sp1D8[(k & 0xFFFF)] = *(s32 *)(*(u8 **)(iGpffffb3ac + ((k & 0xFFFF) * 4) + 0xC48) + 0x30);
        k = (k + 1) & 0xFFFF;
        goto loop_7;
    }
loop_10:
    if ((u32)(k & 0xFFFF) < 3U) {
        sp1D8[(k & 0xFFFF)] = 0;
        k = (k + 1) & 0xFFFF;
        goto loop_10;
    }
    t2 = func_001d7bf0((u32)sp1D8[0], (u32)sp1D8[1], (u32)sp1D8[2]);
    *(s64 *)(t2 + 0x60) = uid;
    func_00194590(t2, 1);
    t3 = func_001fa320();
    *(t3 + 0) = 10;
    *(s16 *)(t3 + 8) = 0xC00;
    *(t3 + 0x10) = 10;
    *(s16 *)(t3 + 0x18) = 0xC05;
    *(s64 *)(t3 + 0x60) = uid;
    func_00194590(t3, 1);
    pkt = t3;
    t4 = (u8 *)func_001f7c20(0xE, 4, 4);
    *(t4 + 0) = 5;
    *(s64 *)(t4 + 8) = *(s64 *)(pkt + 0x58);
    *(s64 *)(t4 + 0x60) = *(s64 *)arg0;
    func_00194590(t4, 1);
    cur58 = *(s64 *)(pkt + 0x58);
    t5 = func_001f99c0(*(u8 **)(arg0 + 0x434), 7, 0, 0, 0);
    *(t5 + 0) = 5;
    *(s64 *)(t5 + 8) = *(s64 *)(pkt + 0x58);
    *(s16 *)(t5 + 0x48) = 0x3C;
    *(s64 *)(t5 + 0x60) = *(s64 *)arg0;
    func_00194590(t5, 1);
    func_001b7060(aux, &outHi, &outLo);
    t6 = func_001b7880(outHi, outLo, 0x10);
    *(t6 + 0) = 5;
    *(s64 *)(t6 + 8) = cur58;
    *(s16 *)(t6 + 0x48) = 0x3C;
    *(s64 *)(t6 + 0x60) = uid;
    func_00194590(t6, 1);
    tmpS = func_001b7080(aux);
    func_001b70a0(aux, &outHi, &outLo);
    sp100 = (s32)(s16)aux;
    t7 = func_001b83f0(tmpS, outHi, outLo, 0x10, (((*(u16 *)((u8 *)iGpffffb3bc + sp100 * 4 + 2) & 2) != 0) & 0xFFFF));
    *(t7 + 0) = 5;
    *(s64 *)(t7 + 8) = cur58;
    *(s16 *)(t7 + 0x48) = 0x3C;
    *(s64 *)(t7 + 0x60) = uid;
    func_00194590(t7, 1);
    t8 = func_001b9560(func_001b7090(aux), 0x10);
    *(t8 + 0) = 5;
    *(s64 *)(t8 + 8) = cur58;
    *(s16 *)(t8 + 0x48) = 0x3C;
    *(s64 *)(t8 + 0x60) = uid;
    func_00194590(t8, 1);
    t9 = func_001b9de0(arg0, aux, 0x10);
    *(t9 + 0) = 5;
    *(s64 *)(t9 + 8) = cur58;
    *(s16 *)(t9 + 0x48) = 0x3C;
    *(s64 *)(t9 + 0x60) = uid;
    func_00194590(t9, 1);
    func_001d69f0(aux, workBuf);
    pkt12C = func_001d5eb0(handle, workBuf, 0);
    *(pkt12C + 0) = 5;
    *(s64 *)(pkt12C + 8) = cur58;
    *(s16 *)(pkt12C + 0x48) = 0x3C;
    *(s64 *)(pkt12C + 0x60) = uid;
    func_00194590(pkt12C, 1);
    unit17 = *(u8 **)(iGpffffb3ac + 0x178);
loop_16:
    if (unit17 != NULL) {
        if ((func_00232710(*(s32 *)(unit17 + 0xA64), 0x100117) != 0) || (func_002428f0(*(s32 *)(unit17 + 0xA64), 0) != 0)) {
            t10 = func_0019bbe0(unit17, 0xFFFFFF, 0, 0, 4, 0);
            *(t10 + 0) = 4;
            *(s64 *)(t10 + 8) = *(s64 *)(pkt12C + 0x58);
            *(s64 *)(t10 + 0x60) = uid;
            func_00194590(t10, 0);
        }
        unit17 = *(u8 **)(unit17 + 0xA6C);
        goto loop_16;
    }
    t11 = (u8 *)func_001d6240((u32)handle, *(u32 *)(arg0 + 0x30), *(u32 *)(*(u8 **)(arg0 + 0x38) + 0x30), 0, 0);
    pkt128 = t11;
    *(t11 + 0) = 4;
    *(s64 *)(t11 + 8) = *(s64 *)(pkt12C + 0x58);
    *(s64 *)(t11 + 0x60) = uid;
    func_00194590(t11, 2);
    if (sp100 == 0x101) {
        t12 = func_001f81f0(2, D_005F6D48);
    } else if (sp100 == 0x100) {
        t13 = func_001f81f0(2, D_005F6D38);
    } else {
        t14 = func_001f81f0(2, D_005F6D58);
    }
    *(t14 + 0) = 5;
    *(s64 *)(t14 + 8) = *(s64 *)(pkt128 + 0x58);
    *(s64 *)(t14 + 0x60) = uid;
    func_00194590(t14, 1);
    sp110 = 0;
    cur58 = (s64)(func_001ef4a0(aux) & 0xFFFF);
    pkt = t14;
    var23 = 0;
loop_44:
    if ((var23 & 0xFFFF) < (s32)*(u16 *)(arg0 + 0x6A)) {
        unit17 = *(u8 **)(arg0 + ((var23 & 0xFFFF) * 4) + 0x38);
        func_00230340(unit17);
        tmpS = func_001d43f0((s32)(unit17 + 0xD8));
        if (*(s32 *)(unit17 + 0xE4) != 0) {
            unit19 = arg0;
        } else {
            unit19 = unit17;
        }
        t15 = func_00202740(*(u8 **)(unit19 + 0x30));
        *(s64 *)(t15 + 0x60) = uid;
        func_00194590(t15, 1);
        t16 = (u8 *)func_001d6240((u32)handle, *(u32 *)(arg0 + 0x30), *(u32 *)(unit19 + 0x30), 1, (u32)(tmpS | 0x1000));
        unit30 = t16;
        *(t16 + 0) = 4;
        *(s64 *)(t16 + 8) = *(s64 *)(pkt12C + 0x58);
        *(s16 *)(t16 + 0x48) = sp110;
        *(s64 *)(t16 + 0x60) = uid;
        func_00194590(t16, 2);
        t17 = (u8 *)func_001f7c20(0xA, 0, 4);
        *(t17 + 0) = 0xB;
        *(s64 *)(t17 + 8) = *(s64 *)(unit30 + 0x58);
        func_00194590(t17, 1);
        if (*(s32 *)(unit17 + 0xE4) != 0) {
            t18 = (u8 *)func_001d6240(*(u32 *)(iGpffffb3ac + 0xD28), *(u32 *)(arg0 + 0x30), *(u32 *)(unit17 + 0x30), 1, 0);
            *(t18 + 0) = 0xB;
            *(s64 *)(t18 + 8) = *(s64 *)(unit30 + 0x58);
            func_00194590(t18, 1);
        }
        if (*(u16 *)(unit17 + 0xDC) == 0x400) {
            t19 = (u8 *)func_001d6240(*(u32 *)(iGpffffb3ac + 0xD2C), *(u32 *)(arg0 + 0x30), *(u32 *)(unit19 + 0x30), 1, 0);
            *(t19 + 0) = 0xB;
            *(s64 *)(t19 + 8) = *(s64 *)(unit30 + 0x58);
            func_00194590(t19, 1);
        }
        var22 = 0;
loop_42:
        if ((var22 & 0xFFFF) < (s32)*(u8 *)(unit17 + 0xD9)) {
            unit30 = unit17 + ((var22 & 0xFFFF) << 5);
            t20 = func_00199ee0(*(u8 **)(unit19 + 0x30), (s32)*(s8 *)(unit30 + 0x10C), 0, 0, 1.0f);
            pkt = t20;
            *(t20 + 0) = 0xB;
            *(s64 *)(t20 + 8) = *(s64 *)(unit30 + 0x58);
            *(s64 *)(t20 + 0x60) = uid;
            func_00194590(t20, 0);
            t21 = func_00198300(*(u8 **)(unit17 + 0x30), *(u8 **)(arg0 + 0x30), 2);
            *(t21 + 0) = 5;
            *(s64 *)(t21 + 8) = *(s64 *)(pkt + 0x58);
            *(t21 + 0x47) &= (u8)~0x20;
            *(s64 *)(t21 + 0x60) = uid;
            func_00194590(t21, 1);
            t22 = func_001f36e0((s32)arg0, (s32)unit19, unit30 + 0xF0, *(u16 *)(unit17 + 0xDC), *(s16 *)(unit17 + 0xDE));
            *(t22 + 0) = 5;
            *(s64 *)(t22 + 8) = *(s64 *)(pkt + 0x58);
            *(s64 *)(t22 + 0x60) = uid;
            func_00194590(t22, 1);
            t23 = func_001f3950(unit17);
            *(t23 + 0) = 5;
            *(s64 *)(t23 + 8) = *(s64 *)(pkt + 0x58);
            *(s64 *)(t23 + 0x60) = uid;
            func_00194590(t23, 1);
            if (((var23 & 0xFFFF) == (*(u16 *)(arg0 + 0x6A) - 1)) && ((var22 & 0xFFFF) == (*(u8 *)(unit17 + 0xD9) - 1))) {
                t24 = func_001f3950(arg0);
                *(t24 + 0) = 5;
                *(s64 *)(t24 + 8) = *(s64 *)(pkt + 0x58);
                *(s64 *)(t24 + 0x60) = uid;
                func_00194590(t24, 1);
            }
            if (((var22 & 0xFFFF) == 0) && (*(s32 *)(unit30 + 0xF0) != 0)) {
                t25 = func_00202590(*(s32 *)(unit19 + 0x30), 0, 0);
                *(t25 + 0) = 5;
                *(s64 *)(t25 + 8) = *(s64 *)(pkt + 0x58);
                *(t25 + 0x47) &= (u8)~0x20;
                *(s64 *)(t25 + 0x60) = uid;
                func_00194590(t25, 3);
            }
            if ((*(u16 *)(unit30 + 0x10E) & 1) != 0) {
                func_001f0a10(tmpBuf);
                *(s32 *)(tmpBuf + 12) = 0x100001;
                t26 = func_001f36e0((s32)unit17, (s32)unit17, tmpBuf, 1, 1);
                *(t26 + 0) = 4;
                *(s64 *)(t26 + 8) = *(s64 *)(pkt + 0x58);
                *(s64 *)(t26 + 0x60) = uid;
                func_00194590(t26, 1);
                if ((*(u16 *)(unit30 + 0x10E) & 2) != 0) {
                    t27 = func_00199ee0(*(u8 **)(unit17 + 0x30), 0xB, 0, 0, 1.0f);
                    *(t27 + 0) = 4;
                    *(s64 *)(t27 + 8) = *(s64 *)(pkt + 0x58);
                    *(s64 *)(t27 + 0x60) = uid;
                    func_00194590(t27, 0);
                    t28 = func_0019a980(*(u8 **)(unit17 + 0x30));
                    *(t28 + 0) = 4;
                    *(s64 *)(t28 + 8) = *(s64 *)(pkt + 0x58);
                    *(s64 *)(t28 + 0x60) = uid;
                    func_00194590(t28, 0);
                }
            }
            t29 = func_00201de0(*(s32 *)(arg0 + 0x30), *(s32 *)(unit19 + 0x30), sp100, *(u16 *)(unit17 + 0xDC), *(s16 *)(unit17 + 0xDE), (var22 & 0xFFFF), *(u8 *)(unit17 + 0xD9), *(u8 **)(unit30 + 0xF0), 0);
            *(t29 + 0) = 5;
            *(s64 *)(t29 + 8) = *(s64 *)(pkt + 0x58);
            *(t29 + 0x47) &= (u8)~0x20;
            *(s64 *)(t29 + 0x60) = uid;
            func_00194590(t29, 3);
            var22 = (var22 + 1) & 0xFFFF;
            goto loop_42;
        }
        sp110 = sp110 + (s16)cur58;
        var23 = (var23 + 1) & 0xFFFF;
        goto loop_44;
    }
    unit17 = *(u8 **)(iGpffffb3ac + 0x178);
loop_50:
    if (unit17 != NULL) {
        if ((func_00232710(*(s32 *)(unit17 + 0xA64), 0x100117) != 0) || (func_002428f0(*(s32 *)(unit17 + 0xA64), 0) != 0)) {
            t30 = func_0019bbe0(unit17, (u32)-1, 0xC, 0, 3, 0);
            *(t30 + 0) = 0xB;
            *(s64 *)(t30 + 8) = *(s64 *)(unit30 + 0x58);
            *(s16 *)(t30 + 0x48) = 6;
            *(s64 *)(t30 + 0x60) = uid;
            func_00194590(t30, 0);
        }
        unit17 = *(u8 **)(unit17 + 0xA6C);
        goto loop_50;
    }
    t31 = func_001b7e20(0x10);
    *(t31 + 0) = 4;
    *(s64 *)(t31 + 8) = *(s64 *)(pkt + 0x58);
    *(t31 + 0x47) &= (u8)~0x20;
    *(s64 *)(t31 + 0x60) = uid;
    func_00194590(t31, 1);
    t32 = func_001b9360(0x10, 0);
    *(t32 + 0) = 4;
    *(s64 *)(t32 + 8) = *(s64 *)(pkt + 0x58);
    *(t32 + 0x47) &= (u8)~0x20;
    *(s64 *)(t32 + 0x60) = uid;
    func_00194590(t32, 1);
    t33 = func_001b99a0(0x10);
    *(t33 + 0) = 4;
    *(s64 *)(t33 + 8) = *(s64 *)(pkt + 0x58);
    *(t33 + 0x47) &= (u8)~0x20;
    *(s64 *)(t33 + 0x60) = uid;
    func_00194590(t33, 1);
    t34 = (u8 *)func_001ba090(8);
    *(t34 + 0) = 4;
    *(s64 *)(t34 + 8) = *(s64 *)(unit30 + 0x58);
    *(t34 + 0x47) &= (u8)~0x20;
    *(s64 *)(t34 + 0x60) = uid;
    func_00194590(t34, 0);
    t35 = func_001d7bf0(0, 0, 0);
    *(t35 + 0) = 4;
    *(s64 *)(t35 + 8) = *(s64 *)(unit30 + 0x58);
    *(t35 + 0x10) = 4;
    *(s64 *)(t35 + 0x18) = *(s64 *)(pkt128 + 0x58);
    *(s64 *)(t35 + 0x60) = uid;
    func_00194590(t35, 1);
    func_001d3e00((u32)handle);
    func_001b0800(arg0, 0x20);
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001aed50);
#endif
// FUN_001AF9D0
void func_001af9d0(void)
{
}
// FUN_001AF9E0
void func_001af9e0(s64 *arg0)
{
    if (func_00193bf0(*arg0, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        func_001b0800(arg0, 0x21U);
    }
}
// FUN_001AFA50
void func_001afa50(u8 *arg0)
{
    if (*(u16 *)(arg0 + 0x18) & 0x4000) {
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 6;
        *(u16 *)(arg0 + 0x18) &= 0xBFFF;
    }
    *(u16 *)(arg0 + 0x18) &= 0xFEFF;
    if (*(u16 *)(arg0 + 0x18) & 0x200) {
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 0x20;
        *(u16 *)(arg0 + 0x18) &= 0xFDFF;
    }
    if (func_001fac80(arg0) != 0) {
        *(void (**)(void))(arg0 + 0x440) = func_001fad10;
        *(s16 *)(arg0 + 0x43C) = 0x21;
        func_001b0800(arg0, 0x16);
        return;
    }
    *(u16 *)(arg0 + 0x18) &= 0xC7FF;
}
/* Battle-state floor (1232B window). Measured nd 208 (guard below; obj 1236B, 4B overrun; fnalign 308/309 instrs, 139 edits +3 reloc-only, 1 long; prior nd219 note at 1240B). Frame/prologue verified. Open: branch-target cascade (layout inversion at retail bnez-far pair vs inline 40-instr arm needs reconstruction), scheduler ordering. Array-free; mask-literal 0xFFF7 measured better than ~8; no width/slti/dead-arm pattern in residual. Triple-built. */
// FUN_001AFB50 NONMATCHING
#ifdef NON_MATCHING
void func_001afb50(u8 *arg0)
{
    u16 t3;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 bVar2;
    u8 *w;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x80) == 0) {
        t3 = *(u16 *)(arg0 + 0x18);
        v4 = (t3 & 4) != 0;
        if ((t3 & 8) != 0 && func_0019ff60(arg0) != 0) {
            if (func_00193cd0(0x504) != 0) {
                return;
            }
            if (func_00193cd0(0x506) != 0) {
                return;
            }
            *(s16 *)(arg0 + 0x16) = 30;
            func_001b0e30(arg0);
            v5 = 1;
        } else {
            *(u16 *)(arg0 + 0x18) = *(u16 *)(arg0 + 0x18) & 0xFFF7;
            v5 = 0;
        }
        if ((*(u16 *)(arg0 + 0x18) & 0x8000) == 0 && v4 == 0) {
            *(s32 *)(arg0 + 0x20) = *(s32 *)(arg0 + 0x20) + 1;
        }
        if (func_00193060() != 0) {
            *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x80;
        } else if ((*(u16 *)(arg0 + 0x18) & 0x8000) != 0 || v4 != 0) {
            if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
                bVar2 = 0;
            } else if ((*(u16 *)(arg0 + 0x1A) & 0x10) == 0) {
                bVar2 = 0;
            } else if ((*(u32 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA0C) + 0x98) & 2) == 0) {
                bVar2 = 0;
            } else {
                bVar2 = 1;
            }
            if (bVar2 != 0) {
                w = func_0019b6a0((s32)(*(u8 **)(arg0 + 0x30) + 0xA0C));
                *(s64 *)(w + 0x60) = *(s64 *)arg0;
                func_00194590(w, 1);
            }
            func_001b13c0(arg0);
        } else {
            if (*(arg0 + 0x29) != 0) {
                if (*(arg0 + 0x28) == 0 && func_002428f0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0) == 0) {
                    *(arg0 + 0x29) = *(arg0 + 0x29) - 1;
                } else {
                    *(arg0 + 0x29) = 0;
                }
            }
            v6 = func_002428f0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0);
            if ((*(arg0 + 0x28) != 0 || *(arg0 + 0x29) != 0) && v6 == 0) {
                func_001b1450(arg0);
                func_001f5a00(0);
            } else {
                if (v6 != 0) {
                    *(arg0 + 0x28) = 0;
                    *(arg0 + 0x29) = 0;
                    func_001b0dd0(arg0);
                }
                if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
                    bVar2 = 0;
                } else if ((*(u16 *)(arg0 + 0x1A) & 0x10) == 0) {
                    bVar2 = 0;
                } else if ((*(u32 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA0C) + 0x98) & 2) == 0) {
                    bVar2 = 0;
                } else {
                    bVar2 = 1;
                }
                if (bVar2 != 0) {
                    w = func_0019b6a0((s32)(*(u8 **)(arg0 + 0x30) + 0xA0C));
                    *(s64 *)(w + 0x60) = *(s64 *)arg0;
                    func_00194590(w, 1);
                }
                func_00235110(*(u8 **)(arg0 + 0x30) + 0xA64);
                func_001f5a00(1);
                func_001b13c0(arg0);
            }
        }
        if (v4 == 0) {
            *(u16 *)(arg0 + 0x18) = *(u16 *)(arg0 + 0x18) & ~0x8000;
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x80) == 0) {
            if (v5 != 0) {
                func_001b0800(arg0, 1);
                return;
            }
            if ((*(u16 *)(arg0 + 0x18) & 0x20) == 0) {
                func_001b0800(arg0, 0x22);
                return;
            }
            func_001b0dd0(arg0);
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1) {
                func_00232680(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x80000);
                func_00231f20(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0);
            }
            if (func_00193060() != 0) {
                *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x80;
            }
            func_001b0800(arg0, 0x24);
            return;
        }
        if ((*(u16 *)(arg0 + 0x18) & 0x20) != 0) {
            func_001b0dd0(arg0);
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1) {
                func_00232680(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x80000);
                func_00231f20(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0);
            }
            func_001b0800(arg0, 0x24);
            return;
        }
        if (func_002428f0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0) != 0) {
            func_001f2cc0(arg0);
            func_001b0800(arg0, 1);
        }
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001afb50);
#endif
