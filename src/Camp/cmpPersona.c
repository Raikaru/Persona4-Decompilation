#include "include_asm.h"
/* Persona 4 USA decompilation - cmpPersona.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

typedef struct CmpHead CmpHead;
struct CmpHead {
    u8 _pad00[0x1C];
    s32 flags; // 0x1C
    s16 f20;   // 0x20
    s16 f22;   // 0x22
};

s32 func_0010abd0(s16 arg0);
s32 func_0034c210(void);
void func_001437b0(void* arg0, s16 arg1, s32 arg2);
void func_0034f5d0(void* arg0);
u32 func_003b7060(void);
void func_0046d280(s32 arg0);
void func_00452080(s32 arg0);
void func_002bb4e0(void);
void func_003550d0(s32 arg0, void* arg1, void* arg2);
void func_00355070(s32 arg0, void* arg1, void* arg2);
void func_00355300(s32 arg0, s32 arg1);
void func_0046d730(void* arg0, s32 arg1);
void func_00136fc0(u8* arg0);
void func_00135dc0(u8* arg0);
extern s32 D_005EB580[];
extern u8 D_005EB560[];
extern u8 D_005EB570[];
extern u8 D_005EB578[];
typedef struct CmpPair CmpPair;
struct CmpPair {
    f32 x;
    f32 y;
};
void func_003552d0(s32 arg0, CmpPair arg1);

// FUN_001356D0
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_001356d0);

// FUN_00135C10
void func_00135c10(u8* arg0) {
    s16 j = 0;
    s16 i = 0;
    while (j < 0xC) {
        if (func_0010abd0(j) == 0) {
            break;
        }
        *(s16*)((u8*)arg0 + i * 2 + 0x36) = j;
        i++;
        j++;
    }
    *(s16*)((u8*)arg0 + 0x4E) = i;
}

// FUN_00135CB0
s32 func_00135cb0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    default:
        return 1;
    }
}

// FUN_00135CF0
/* measured: without opt_common_subs off, mwcc CSEs (u8*)arg0 + 0x20 into a
   callee-saved pointer (nd 40); with it off each access keeps the
   base+offset form like retail (nd 0). */
#pragma opt_common_subs off
s32 func_00135cf0(u8* arg0) {
    s32 i;
    s32 result = 1;
    u8* p;
    s32 v = *(s16*)((u8*)arg0 + 0x20);
    if (v < 0x64) {
        *(s16*)((u8*)arg0 + 0x20) = v + 1;
    }
    for (i = 0; i < 0x1C; i++) {
        p = (u8*)arg0 + i * 0x30;
        v = *(s16*)((u8*)arg0 + 0x20);
        func_001437b0(p + 0x1054, v, 0);
        if (*(u8*)(p + 0x106E) != 0) {
            result = 0;
        }
    }
    func_00136fc0(arg0);
    func_00135dc0(arg0);
    return result;
}
#pragma opt_common_subs on

// FUN_00135DC0
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_00135dc0);

// FUN_00136FA0
s32 func_00136fa0(s16* arg0, s32 arg1, s32 arg2) {
    s32 idx = arg1 * 2;
    s16* p = (s16*)(idx + (s32)arg0);
    p[0x2C] = p[0x28];
    p[0x28] = arg2;
    return 1;
}

// FUN_00136FC0
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_00136fc0);

// FUN_001370E0
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_001370e0);

// FUN_001371A0
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_001371a0);

// FUN_001374D0
/* measured: without opt_loop_invariants on, the 200.0f/-200.0f/0x44480000
   constants are rematerialized inside the loop (nd 39); with it they hoist
   to the preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void func_001374d0(u8* arg0) {
    s32 i;
    s16 cur;
    u8* p;
    f32 f;
    for (i = 0; i < 8; i++) {
        cur = *(s16*)((u8*)arg0 + 0x50);
        if (i == cur) {
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x12FC) = 0x44480000;
            *(s32*)(p + 0x1300) = 0;
            *(u8*)(p + 0x130D) = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x12FC) = 0;
            *(f32*)(p + 0x1300) = f;
            *(u8*)(p + 0x130D) = 0;
        }
    }
}
/* measured: see annotation above (func_001374d0). */
#pragma opt_loop_invariants off

// FUN_00137570
/* measured: without opt_loop_invariants on, mwcc rematerializes the 0x41F00000
   constant inside the loop body (nd 22); with it the lui hoists to the
   preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void func_00137570(u8* arg0) {
    s32 i;
    u8* p;
    s32 c = 0x41F00000;
    for (i = 0; i < 0xC; i++) {
        p = (u8*)arg0 + i * 0x30;
        *(f32*)(p + 0x10B4) = *(f32*)(p + 0x10C4);
        *(f32*)(p + 0x10B8) = *(f32*)(p + 0x10C8);
        *(u8*)(p + 0x10CC) = *(u8*)(p + 0x10CE);
        if (*(s16*)((u8*)arg0 + 0x52) == i) {
            *(s32*)(p + 0x10BC) = c;
        } else {
            *(s32*)(p + 0x10BC) = 0;
        }
    }
    *(s16*)((u8*)arg0 + 0x20) = 0;
    *(s32*)((u8*)arg0 + 0x1C) &= ~0x1000;
}
/* measured: see annotation above (func_00137570). */
#pragma opt_loop_invariants off


// FUN_001375F0
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_001375f0);

// FUN_00137740
/* measured: without opt_loop_invariants on, the 200.0f/-200.0f/0x44480000
   constants are rematerialized inside the loop (nd 39); with it they hoist
   to the preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void func_00137740(u8* arg0) {
    s32 i;
    s16 cur;
    u8* p;
    f32 f;
    for (i = 0; i < 0xC; i++) {
        cur = *(s16*)((u8*)arg0 + 0x52);
        if (i == cur) {
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x10BC) = 0x44480000;
            *(s32*)(p + 0x10C0) = 0;
            *(u8*)(p + 0x10CD) = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x10BC) = 0;
            *(f32*)(p + 0x10C0) = f;
            *(u8*)(p + 0x10CD) = 0;
        }
    }
}
/* measured: see annotation above (func_00137740). */
#pragma opt_loop_invariants off

// FUN_001377E0
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_001377e0);

// FUN_00137890
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_00137890);

// FUN_00137DD0
s32 func_00137dd0(u8* arg0) {
    s32 result = 1;
    s32 i = 0;
    s32 cmp = *(s16*)((u8*)arg0 + 0x20);
    for (; i < 0x1C; i++) {
        if (cmp < *(s32*)((u8*)arg0 + i * 0x30 + 0x1080)) {
            result = 0;
        }
    }
    return result & func_0034c210();
}

// FUN_00137E50
void func_00137e50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8* var_5;
    u8* var_6;
    CmpPair pair;
    if ((arg1 < 0) || (arg1 > 0)) {
        func_0046d730(&D_005EB580[0], 0x505);
    }
    if (arg0 == 0) {
        func_0046d730(&D_005EB580[0], 0x506);
    }
    if (arg3 != 0) {
        var_6 = &D_005EB560[arg1 * 0x1C];
        var_5 = var_6 + 8;
    } else {
        var_5 = &D_005EB560[arg1 * 0x1C];
        var_6 = var_5 + 8;
    }
    pair = *(CmpPair*)&D_005EB570[arg1 * 0x1C];
    arg1 = *(s32*)&D_005EB578[arg1 * 0x1C];
    if (arg2 != 0) {
        func_003550d0(arg0, var_5, var_6);
    } else {
        func_00355070(arg0, var_6, var_6);
    }
    func_003552d0(arg0, pair);
    func_00355300(arg0, arg1);
}
