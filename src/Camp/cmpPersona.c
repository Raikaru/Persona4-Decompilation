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
void func_001437b0(void* arg0, s32 arg1, s32 arg2);
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
extern s16 D_005EB590[];
extern void func_0011cee0(u8* arg0);
extern u8 D_005E9FD0[];
extern u8 D_005EA2E0[];
extern u8 D_005EA5F0[];
extern u8 D_005EA900[];
extern u8 D_005EAC10[];
extern u8 D_005EAF20[];
extern u8 D_005EB230[];
typedef struct CmpPair CmpPair;
struct CmpPair {
    f32 x;
    f32 y;
};
void func_003552d0(s32 arg0, CmpPair arg1);

/* measured: plain-cast reconstruction candidate (corrected callee declarations
   and s16 loop counter) emitted the retail overflow-safe float-to-u16
   conversion idiom, but object size was 1288 versus the 1344-byte window and
   normalized_diff was 860. The remaining mismatch is reconstruction-scale;
   the prior explicit-guard floor classification is rejected. Retail uses
   func_00353c10 with only the s16* argument in $a0, while the resource
   handles are s32 values. */
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
void func_00136fc0(u8* arg0) {
    s16 temp_3;
    s32 i;

    temp_3 = *(s16*)(arg0 + 0x22);
    if (temp_3 < 0x64) {
        *(s16*)(arg0 + 0x22) = temp_3 + 1;
    }
    if (*(s16*)(arg0 + 0x22) == 0x19) {
        *(s32*)(arg0 + 0x1C) &= ~0x1000;
    }
    for (i = 0; i < 0x24; i++) {
        func_001437b0(arg0 + i * 0x30 + 0x1594, *(s16*)(arg0 + 0x22), 0);
    }
    for (i = 0; i < 0x78; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0x64);
    }
    for (i = 0; i < 0x54; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0x9C4);
    }
}

/* measured: opt_propagation off preserves the retail stack-local value-pointer
   address sequence (MATCH); leaving propagation on folds the +0x40 into lh. */
#pragma opt_propagation off
// FUN_001370E0
void func_001370e0(u8* arg0) {
    s16 values[0x19];
    s16* src;
    s16* dst;
    s16* value;
    s16 idx;
    s32 count;
    s32 i;
    s32 offset;
    u8* p;

    src = &D_005EB590[0];
    dst = &values[0];
    count = 0x19;
    do {
        idx = *src;
        src++;
        count--;
        *dst = idx;
        dst++;
    } while (count > 0);
    for (i = 0; i < 0x19; i++) {
        offset = i * 2;
        value = (s16*)((u8*)&values[0] + offset);
        idx = *value;
        p = arg0 + idx * 0x14;
        *(s16*)(p + 0x9C4) = 3;
        *(s16*)(p + 0x9C6) = (s16)(func_003b7060() % 0x19 + 0xF);
    }
}
#pragma opt_propagation on


/* measured: opt_common_subs off around the setup/switch and
   opt_loop_invariants on around the table loop reproduce the retail
   register/constant placement (MATCH). Plain `(u16)float` casts use MWCC's
   native overflow-safe conversion sequence (c.le.s 0x4F000000; trunc.w.s;
   mfc1; andi 0xFFFF with the out-of-line subtract/or path). func_0011cee0
   receives the pointer loaded from 0x1CB4. The switch jump table has case 9
   targeting the default block, so no empty case is needed. */
#pragma opt_common_subs off
// FUN_001371A0
s32 func_001371a0(u8* arg0, s32 arg1) {
    s32 i;
    s32 j;
    u8* table;
    u8* src;
    u8* dst;
    f32 value;
    table = 0;
    if (*(s32*)(arg0 + 0x18) == arg1) {
        return 0;
    }
    for (i = 0; i < 0x1C; i++) {
        dst = arg0 + i * 0x30;
        *(f32*)(dst + 0x1054) = *(f32*)(dst + 0x1064);
        *(f32*)(dst + 0x1058) = *(f32*)(dst + 0x1068);
        *(u16*)(dst + 0x1070) = *(u16*)(dst + 0x1074);
        *(u16*)(dst + 0x1076) = *(u16*)(dst + 0x107A);
        *(u8*)(dst + 0x106C) = *(u8*)(dst + 0x106E);
    }
    switch (arg1) {
    case 0:
        table = D_005E9FD0;
        *(s32*)(arg0 + 0x1C) = 0x243;
        *(s16*)(arg0 + 0x60) = 0;
        break;
    case 1:
        table = D_005EA2E0;
        break;
    case 2:
        table = D_005EA5F0;
        *(s32*)(arg0 + 0x1C) = 0xA43;
        *(s16*)(arg0 + 0x60) = 0;
        break;
    case 3:
        table = D_005EA900;
        *(s32*)(arg0 + 0x1C) = 0xFE7;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    case 4:
    case 5:
        table = D_005EAC10;
        *(s32*)(arg0 + 0x1C) = 0x5A5;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    case 6:
        table = D_005EAF20;
        *(s32*)(arg0 + 0x1C) = 0x48D;
        *(s16*)(arg0 + 0x60) = -1;
        func_0011cee0(*(u8**)(arg0 + 0x1CB4));
        break;
    case 7:
        table = D_005EAF20;
        *(s32*)(arg0 + 0x1C) = 9;
        break;
    case 8:
        table = D_005EB230;
        *(s32*)(arg0 + 0x1C) = 0xA13;
        *(s16*)(arg0 + 0x60) = 0xE;
        func_0011cee0(*(u8**)(arg0 + 0x1CB4));
        break;
    case 10:
        *(s32*)(arg0 + 0x1C) = 8;
        *(s16*)(arg0 + 0x60) = -1;
        break;
    case 11:
        *(s32*)(arg0 + 0x1C) = 0x5A5;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    case 12:
        *(s32*)(arg0 + 0x1C) = 0x5A5;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    default:
        func_0046d730(D_005EB580, 0x3BA);
        break;
    }
#pragma opt_common_subs on
/* measured: opt_loop_invariants on hoists the table/dst stride multiplies
   out of the j loop to match retail; without it the function mismatches. */
#pragma opt_loop_invariants on
    if (table != 0) {
        for (j = 0; j < 0x1C; j++) {
            src = table + j * 0x1C;
            dst = arg0 + j * 0x30;
            *(f32*)(dst + 0x105C) = *(f32*)(src + 0);
            *(f32*)(dst + 0x1060) = *(f32*)(src + 4);
            value = *(f32*)(src + 8);
            *(u16*)(dst + 0x1072) = (u16)value;
            value = *(f32*)(src + 0xC);
            *(u16*)(dst + 0x1078) = (u16)value;
            *(u8*)(dst + 0x106D) = *(u8*)(src + 0x10);
            *(s32*)(dst + 0x107C) = *(s32*)(src + 0x14);
            *(s32*)(dst + 0x1080) = *(s32*)(src + 0x18);
        }
    *(s16*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x18) = arg1;
    }
    return 1;
}
/* measured: closes the opt_loop_invariants on scope opened above for
   func_001371a0's table loop. */
#pragma opt_loop_invariants off

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
/* measured: probing O1 for retail's extra saved pointer. */
#pragma optimization_level 1
void func_001375f0(u8 *arg0)
{
    f32 f;
    u32 val;
    s32 i;
    u32 random;
    u8 *p;
    u32 *q;

    for (i = 0; i < 0x24; i++) {
        if (func_003b7060() & 3) {
            p = arg0 + i * 0x30;
            val = (func_003b7060() % 7U) * 0x2C;
            if (val >= 0) {
                f = (f32)val;
            } else {
                val = (val >> 1) | (val & 1);
                f = (f32)(s32)val;
                f += f;
            }
            *(f32 *)(p + 0x159C) = f;
            *(f32 *)(p + 0x1594) = f;
            *(u32 *)(p + 0x1598) = 0x43FA0000;
            *(f32 *)(p + 0x15A8) = *(f32 *)(p + 0x1598);
            *(s32 *)(p + 0x15A0) = 0xC2C80000;
            q = (u32 *)(p + 0x15BC);
            random = func_003b7060() % 10U;
            *q = random;
            *(s32 *)(p + 0x15C0) = random + 0xA;
        } else {
            p = arg0 + i * 0x30;
            *(f32 *)(p + 0x1598) = *(f32 *)(p + 0x15A0);
        }
    }
    *(s16 *)(arg0 + 0x22) = 0;
    *(s32 *)(arg0 + 0x1C) |= 0x1000;
}
/* measured: closing O1 probe. */
#pragma optimization_level 2

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
void func_001377e0(u8* arg0) {
    u8* base = arg0;
    s32 i;
    s32* p;
    for (i = 0; i < 0x17; i++) {
        p = (s32*)(base + i * 4 + 0x1C54);
        if (*p != 0) {
            func_0046d280(*p);
            *p = 0;
        }
    }
    if (*(s32*)(base + 0x1CB4) != 0) {
        func_00452080(*(s32*)(base + 0x1CB4));
        *(s32*)(base + 0x1CB4) = 0;
    }
    if (*(s32*)(base + 0x1CB8) != 0) {
        func_00452080(*(s32*)(base + 0x1CB8));
        *(s32*)(base + 0x1CB8) = 0;
    }
    func_002bb4e0();
    *(s32*)(base + 0x1C) = 0;
}

/* measured: the plain `(u8)` cast uses MWCC's native guarded conversion
   idiom; it is not a float-to-unsigned compiler floor. This function still
   has the genuine COP1 accumulator-chain floor: retail contains
   `adda.s $f0,$f1` / `madd.s $f20,$f3,$f2` for the alpha calculation, plus the
   doubled-bltz u16 sign-test pattern. */
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
