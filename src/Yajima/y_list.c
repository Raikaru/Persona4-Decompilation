#include "include_asm.h"
#include "type.h"

/* gp-relative global at 0x0072467C (gp - 0x4A74): pointer to the active list. */
static u8 *iGpffffb58c;
/* gp-relative global at 0x007244C4 (gp - 0x4C2C). */
static u8 *iGpffffb3d4;

extern char D_0063FC48[];
extern char D_0063FC58[];
extern u8 *D_00882F70[];
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *);

extern s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern void func_0044ea90(void *msg, s32 id);
extern void func_00452080(s32 handle);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, s32 (*init)(u8 *),
                        void (*close)(u8 *), void *buf);
extern s32 func_00451fc0(s32 arg0, void *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern s32 func_002e23b0(u8 *arg0);
extern s32 func_002e2410(u8 *arg0);
extern void func_002e2470(u8 *arg0);
extern s32 func_002e4090(u8 *arg0);
extern void func_002e29a0(void);
extern s8 func_002e47b0(void);
extern void func_002e4820(s8 arg0);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern s32 func_002e6b20(s16 *arg0, s16 *arg1);
extern s32 func_002e6630(s16 *arg0, s16 *arg1);
extern s32 func_00440bb8();
extern void *func_0010fcb0();
extern void func_0010cad0(void *dest, u16 id);
extern s16 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00311d00(u16 id);
extern s32 func_00311d60(u16 id);
extern s32 func_00311e40(u16 id);
extern void func_0043f810(void *dst, void *src, u32 size);

// FUN_002E24A0
void func_002e24a0(s32 arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *buf;

    if (iGpffffb58c != NULL) {
        func_002e29a0();
    }
    func_0044ea90(D_0063FC48, 0x67);
    buf = D_008873F4[0](1, 0x1810, 0x40000);
    iGpffffb58c = (u8 *)func_00451de0(D_0063FC58, 0xF, 0, 0, func_002e23b0,
                                       func_002e2470, buf);
    *(s32 *)(buf + 4) = arg0;
    *(s32 *)(buf + 8) = arg1;
    *(s8 *)(buf + 1) = arg2;
    *(s8 *)(buf + 0) = 1;
    *(s8 *)(buf + 0xC) = arg3;
}
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e24a0);

// FUN_002E2590
void func_002e2590(s32 arg0, s32 arg1, s32 arg2, s8 arg3, s8 arg4) {
    u8 *buf;

    func_0044ea90(D_0063FC48, 0x82);
    buf = D_008873F4[0](1, 0x1810, 0x40000);
    func_00451fc0(arg0, D_0063FC58, 0xF, 0, 0, func_002e2410, func_002e2470,
                  buf);
    *(s32 *)(buf + 4) = arg1;
    *(s32 *)(buf + 8) = arg2;
    *(s8 *)(buf + 1) = arg3;
    *(s8 *)(buf + 0) = 1;
    *(s8 *)(buf + 0xC) = arg4;
}

// FUN_002E2670
s16 func_002e2670(void) {
    u8 *g = iGpffffb58c;

    if (g == NULL) {
        return -1;
    }
    return *(s16 *)(*(u8 **)(g + 0x38) + 2);
}

// FUN_002E26A0
s32 func_002e26a0(void) {
    u8 *g = iGpffffb58c;

    if (g == NULL) {
        return -1;
    }
    return func_002b2d00(*(s16 *)(*(u8 **)(g + 0x38) + 2), 1, 0, 0, 1);
}

// FUN_002E26F0
s16 func_002e26f0(void *arg0) {
    return *(s16 *)(*(u8 **)((u8 *)arg0 + 0x38) + 2);
}

// FUN_002E2700
void func_002e2700(void *arg0) {
    func_002b2d00(*(s16 *)(*(u8 **)((u8 *)arg0 + 0x38) + 2), 1, 0, 0, 1);
}

// FUN_002E2740
s16 func_002e2740(s32 arg0) {
    u8 *g = iGpffffb58c;
    u8 *p;
    s32 count;

    if (g == NULL) {
        return -1;
    }
    p = *(u8 **)(g + 0x38);
    if (g == NULL) {
        count = -1;
    } else {
        count = *(s16 *)(p + 2);
    }
    if (count < arg0) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 2: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 3: {
        s32 idx = arg0 * 2;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 4: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    default:
        return -1;
    }
}

// FUN_002E2830
s16 func_002e2830(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s16 *)(p + 2) < arg1) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 2: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 3: {
        s32 idx = arg1 * 2;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 4: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    default:
        return -1;
    }
}

// FUN_002E28F0
s16 func_002e28f0(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s16 *)(p + 2) < arg1) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0x10);
    }
    case 2:
        return 1;
    case 3:
        return 1;
    case 4: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0x10);
    }
    default:
        return -1;
    }
}

// FUN_002E29A0
void func_002e29a0(void) {
    u8 *g = iGpffffb58c;

    if (g != NULL) {
        func_00452080((s32)g);
        iGpffffb58c = NULL;
    }
}

// FUN_002E29D0
s8 func_002e29d0(void) {
    u8 *g = iGpffffb58c;

    if (g != NULL) {
        return *(s8 *)(*(void **)(g + 0x38));
    }
    return -1;
}

// FUN_002E2A00
s8 func_002e2a00(void *arg0) {
    return *(s8 *)(*(void **)((u8 *)arg0 + 0x38));
}

/* measured: structure fully recovered (iGpffffb58c null-check, p=e+0x38 with
   the four state stores, the descending-test switch on p->1 with the four
   0x600 loops and 4-way ok-chains, the case-2 6b20/6b50/2be160/2bdff0/1462
   chains, the 2b2cb0 count stores, the arg3==1 -1-init/compaction loops with
   10830/10810 into arr[0x600], the arg3==2 sortbuf copy + 40bb8 sort +
   re-store loops; case order 1,2,3,4 reproduces retail's descending test
   chain and ascending body layout exactly) but mwcc b210 rotates the saved
   registers: mine arg3=$s5 p=$s1 e2=$s2 i=$s0 (frame 0x3070 matches) vs
   retail arg3=$s1 p=$s0 e2=$s2 i=$s3 j=$s4 n=$s5, so every instruction in
   the six loops differs (nd 603). Tried 3 declaration orders, separate
   m/k loop counters for the arg3==1/2 blocks, a shared loop variable;
   all nd 603. Same saved-reg rotation floor as func_002e3560 (this file),
   mdlManager func_0047c660 and mdlMatAnim func_00480670. */
// FUN_002E2A10
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e2a10);

// FUN_002E3560
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e3560);

// FUN_002E4090
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4090);

// FUN_002E45E0
void func_002e45e0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_002E4610
void func_002e4610(s32 arg0, s8 arg1) {
    u8 *buf;
    u8 **slot;
    u8 *base;
    s16 i;
    s16 j;

    func_002e47b0();
    slot = &D_00882F70[arg1];
    if (*slot != NULL) {
        func_002e4820(arg1);
    }
    func_0044ea90(D_0063FC48, 0x38F);
    buf = D_008873F4[0](1, 0x3014, 0x40000);
    *slot = (u8 *)func_00451de0(D_0063FC58, 0xF, 0, 0, func_002e4090, (void (*)(u8 *))func_002e45e0, buf);
    buf[0] = 0;
    *(s32 *)(buf + 4) = arg0;
    *(s32 *)(buf + 8) = 0;
    switch (arg0) {
    case 1:
    case 0xA:
    case 6:
        for (i = 0; i < 0xC; i++) {
            j = 0;
            base = buf + i * 12;
            while (j < 0xC) {
                *(u8 *)(base + 0x14 + j) = 0;
                j++;
            }
        }
        break;
    default:
        break;
    }
    if (arg0 == 0xA) {
        buf[0] = 1;
    }
}
// FUN_002E47B0
s8 func_002e47b0(void) {
    s16 i = 0;
    u8 **base = D_00882F70;

    while (i < 15) {
        if (*(u8 **)((u32)base + i * 4) == NULL) {
            return (s8)i;
        }
        i++;
    }
    return -1;
}

// FUN_002E4820
void func_002e4820(s8 arg0) {
    u8 **p = &D_00882F70[arg0];

    if (*p != NULL) {
        func_00452080((s32)*p);
        *p = NULL;
    }
}

// FUN_002E4870
u8 *func_002e4870(s8 arg0) {
    return *(void **)(D_00882F70[arg0] + 0x38);
}

// FUN_002E48A0
u8 *func_002e48a0(s8 arg0, s16 arg1) {
    u8 *p = *(u8 **)(D_00882F70[arg0] + 0x38);

    switch (*(u32 *)(p + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        return p + ((arg1 * 3) * 0x10) + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        return p + ((arg1 * 3) * 0x10) + 0xA4;
    default:
        return p + ((arg1 * 3) * 0x10) + 0x14;
    }
}

/* measured: retail keeps the p pointer in $t0 and the pre-switch counter
   (n3=6, merged with the case-6 chain constant) in $a3, with the addiu placed
   after the type load. mwcc b210 at O2 colors p->$a3 and the counter->$t0 and
   hoists the addiu into the p/type load-delay gap; every spelling tried gives
   the identical nd 14: case groups in both orders and several intra-group
   orders (6,5,10,1,8,7,0 / 0,7,8,1,10,5,6 / 0,7,8,6,5,10,1), counter declared
   at top vs inside block vs after the src assignment, n3 declared first/last,
   dead 4th arg, separate entry local, inline switch(*(s32*)(p+4)), if/else-if
   chain (71), and #pragma schedule on (64). Pure register-coloring residual
   plus one load-slot scheduling word; this is the coloring floor. */
// FUN_002E4960
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4960);

/* measured: structure fully recovered (p = D_00882F70[0]+0x38 with the
   type 6/10/1 gate, a0/a1/offA1 prologue, nested i/j loops with the five
   sq/lq 16-byte stack slots spE0/spD0/spC0/spB0/spA0 (i*12, p+i*12,
   &D_00882F70[(s8)(i+1)], &D_00882F70[i], t5+0x14), the a0==0 path's three
   jump-table switches (748BC0/748B90/748B60) + func_00312b60, the a0==1
   path's four switches (748B30/748B00/748AD0/748AA0) + func_00312b90 with
   the spE0+p2'+j q-store and the two w!=0/w==2 sb chains) but mwcc b210
   emits a dsll32/dsrl32 widening pair before every sq and after every lq of
   the slots (u32->u_long128 cast) where retail sq's/lq's the 32-bit values
   directly, and u64 locals get 8-byte slots with sd/ld instead of sq/lq
   (aligned(16) still sd). Tried u_long128/s128/u64/aligned-u64 locals with
   (u64)/(u32)/direct casts and typed-alias reads; best nd 302 at 1352/1344B.
   Mixed-width u_long128 floor (same family as mdlManager func_0047c660 and
   mdlMatAnim func_00480670); the saved-reg assignments also rotate after
   the type gate (bne vs retail's third beq). */
// FUN_002E4AC0
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4ac0);

// FUN_002E5000
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e5000);

// FUN_002E5270
s32 func_002e5270(u8 *arg0, u8 *arg1) {
    s16 i;
    s16 j;
    s16 k;

    if (*(u8 *)(arg0 + 4) != *(u8 *)(arg1 + 4)) {
        return 1;
    }
    for (i = 0; i < 5; i++) {
        if (*(u8 *)(arg0 + 0x1C + i) != *(u8 *)(arg1 + 0x1C + i)) {
            return 1;
        }
    }
    for (j = 0; j < 5; j++) {
        if (*(u8 *)(arg0 + 0x26 + j) != *(u8 *)(arg1 + 0x26 + j)) {
            return 1;
        }
    }
    for (k = 0; k < 8; k++) {
        if (*(u16 *)(arg0 + 0xC + k * 2) != *(u16 *)(arg1 + 0xC + k * 2)) {
            return 1;
        }
    }
    return *(u32 *)(arg0 + 8) != *(u32 *)(arg1 + 8);
}
// FUN_002E53B0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
/* measured: without `opt_loop_invariants on` the switch jump-table base is
   rematerialized in the loop body instead of hoisted to the preheader (nd 30+). */
s32 func_002e53b0(s8 arg0, s16 arg1) {
    u8 **entryp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 *q;
    s32 count;
    s32 key;
    s16 i = 0;

    if (*(u32 *)entryp != 0) {
        i = 0;
        key = (s16)arg1;
        p = *(u8 **)((u8 *)*(u32 *)entryp + 0x38);
        count = *(s32 *)(p + 8);
        for (; i < count; i++) {
            entry = *entryp;
            p = *(u8 **)(entry + 0x38);
            switch (*(u32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((i * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            }
            if (key == *(u16 *)(q + 2)) {
                return 1;
            }
        }
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_002e53b0). */
#pragma opt_loop_invariants off

// FUN_002E54C0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
s16 func_002e54c0(s8 arg0, s16 arg1) {
    s16 i = 0;
    u8 **entryp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 *q;
    s32 count;
    s32 key;

    if (*(u32 *)entryp != 0) {
        i = 0;
        key = (s16)arg1;
        p = *(u8 **)((u8 *)*(u32 *)entryp + 0x38);
        count = *(s32 *)(p + 8);
        for (; i < count; i++) {
            entry = *entryp;
            p = *(u8 **)(entry + 0x38);
            switch (*(u32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((i * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            }
            if (key == *(u16 *)(q + 2)) {
                return i;
            }
        }
    }
    return -1;
}
/* measured: see the annotation above the matching `on` pragma (func_002e54c0). */
#pragma opt_loop_invariants off

/* measured: structure fully recovered (entry null-check, arg2==0 path with
   the 748D70 switch + func_0010cad0, else path with func_0010aa80 == -1
   check, three re-indexed D_00882F70[(s8)arg0]+0x38 chains with the 748D40 /
   748D10 / 748CE0 switches, q[4]=0 and the ac10/memcpy variants, and the
   trailing count++ via slotp) but mwcc b210 CSEs re-indexes 2 and 3 into the
   freed arg0 register (byte-arith `(u8*)D_00882F70+(u32)(s8)arg0*4` keeps
   re-index 1's full dsll32/dsra32/sll/lui/addiu/addu chain but the result
   lands in $s0 and survives the cad0 calls, so 2/3 reload from it; retail
   rematerializes from saved arg0 every time, nd 6 in that region) and the
   saved registers are rotated (mine arg0=$s0 slotp=$s1 arg1=$s2 vs retail
   slotp=$s0 arg1=$s1 arg0=$s2). The rotation is independent of declaration
   order, block scoping, entry-init shape and `<<2`/`*4`/`&D[0]` spellings
   (9 shapes, all nd 125); a shared slot local inflates the frame to 0x50,
   per-path slot locals give 904B/nd 125 at a 928B window. Saved-reg
   rotation + selective load-CSE floor, best nd 125. */
// FUN_002E55C0
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e55c0);
// FUN_002E5960
void func_002e5960(s8 arg0) {
    u8 *p;
    s16 i;
    s16 j;
    s32 type;

    if (D_00882F70[arg0] == NULL) {
        return;
    }
    p = *(u8 **)(D_00882F70[arg0] + 0x38);
    type = *(s32 *)(p + 4);
    switch (type) {
    case 0:
    case 7:
    case 8:
        for (i = 0; i < 0x100; i++) {
            func_0043f9c8(p + ((i * 3) * 0x10) + 0x14, 0, 0x30);
        }
        break;
    case 1:
    case 10:
    case 5:
    case 6:
        for (j = 0; j < 0xC; j++) {
            func_0043f9c8(p + ((j * 3) * 0x10) + 0xA4, 0, 0x30);
            *(u8 *)(p + j + 0x2E4) = 0;
        }
        break;
    default:
        break;
    }
    *(s16 *)(p + 0xE) = 0;
    *(s16 *)(p + 0x10) = 0;
    *(s32 *)(p + 8) = 0;
}

/* measured: structure fully recovered (slotp/entry/p chain, func_002e5960
   calls, the 0xC0 i-loop with the iGpffffb3d4+i*14 entry2 checks, the
   311d00/311d60/2e6230 gates, the func_002e48a0 j-loop, the 311e40 gate,
   the spE0/spD0 range compare and the two jump-table switches with
   memset/cad0 + p->8++, the 0x3C tail gate and the 5-iteration do-loop with
   spC0/spB0/spA0 slot writes) but the five 16-byte stack slots spE0/spD0/
   spC0/spB0/spA0 hold s16-extended values: retail sq's the value directly
   after its dsll32/dsra32 and lq's it into a raw 32-bit compare (slt), while
   mwcc b210 emits a dsll32/dsrl32 widening pair before every sq and after
   every lq of a u_long128 local holding a 32-bit value. Same mixed-width
   u_long128 floor measured in this file at func_002e4ac0 (nd 302, best of
   u_long128/s128/u64/aligned-u64 with direct/(u64)/(u32) casts and
   typed-alias reads) and recorded in mdlManager func_0047c660 / mdlMatAnim
   func_00480670 / P3 W414. Not transcribed further; floor. */
// FUN_002E5AE0
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e5ae0);

// FUN_002E6230
s32 func_002e6230(u16 arg0, u16 *arg1) {
    s32 i = 0;
    s32 key = arg0 & 0xFFFF;

    while (i < 13) {
        if (*(u16 *)((u8 *)arg1 + i * 2) == key) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* measured: structure fully recovered (entry null-check, func_002e5960 and
   func_002b2cb0((s8)arg2,3,0x63,1,1) with the s16 result spilled to the
   stack, the 0xC0 i-loop with the iGpffffb3d4+i*14 entry2 checks, the id =
   (u16)i j-loop over list with found flag, the k-loop via func_002e48a0
   comparing q[2] against i, the 31e40 check, the count<entry2[3] gate and
   the two jump-table switches (full-chain *slotp+0x38 conditions) with
   memset/cad0 and the trailing p->8++) but mwcc b210 assigns the saved
   registers one slot higher for arg0 ($s7 vs retail $s6), pushing the s16-i
   temp to $s6 and i*14 to $fp, so arg1 (list) is spilled to the stack and
   reloaded per j-iteration, and the found flag is kept in a saved register
   with a single materialization where retail keeps it in $v1 with the
   post-j-loop sink and the k-join re-materialization. Best nd 73 at
   936/944B. Saved-reg rotation/spill floor. */
// FUN_002E6280
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6280);

/* measured: structure fully recovered (a=*arg0/b=*arg1, p=*D_00882F70[0]+0x38,
   four jump-table switches {0,2,7,8}->+0x14 / {1,5,6,10}->+0xA4 on *(p+4),
   off1=a*0x30 / off2=b*0x30, g=iGpffffb3d4+2 with the u16*14 index and
   u8*100 chain, v1 first then v2, slt/negu tail) but mwcc b210 CSEs the type
   load into $a0 across all four dispatches (retail reloads lw 4(p) into
   $v0/$v1/$a2/$a2 each time) and hoists p+off1 into $t0 for both slots where
   retail keeps off1=$a3 and off2=$t0 live and re-derives p+off1 per slot;
   obj 600B vs window 640B. Tried: decl orders, b-first load order, inline
   (s16)*arg0 reads, signed (s32) type, explicit t locals; all nd 135. This is
   the load-CSE/coloring floor (same family as func_002e6b20/6c90). */
// FUN_002E6630
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6630);

// FUN_002E68B0
/* measured: without `opt_loop_invariants on` MWCC keeps the loop2 switch
   jump-table base (lui/addiu) inside the dispatch instead of hoisting it
   into the preheader as retail does. */
#pragma opt_loop_invariants on
void func_002e68b0(s8 arg0) {
    u8 **slotp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 **ep;
    u8 *p2;
    s32 count2;
    s16 k;
    s16 j;
    u8 *dst;
    s16 i;
    s16 idx;
    s16 arr1[0x100];
    s16 arr2[0x100];

    entry = *slotp;
    if (entry == NULL) {
        return;
    }
    ep = (u8 **)(entry + 0x38);
    p = *(u8 **)(entry + 0x38);
    for (k = 0; k < *(s32 *)(*(u8 **)(entry + 0x38) + 8); k++) {
        arr1[k] = k;
    }
    func_00440bb8(arr1, *(u16 *)((u8 *)*ep + 8), 2, func_002e6630);
    j = 0;
    count2 = *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8);
    if (count2 > 0) {
        p2 = *(u8 **)((u8 *)*(u8 **)((u8 *)D_00882F70 + (u32)(s8)arg0 * 4) + 0x38);
        for (; j < count2; j++) {
            u8 *q;

            idx = arr1[j];
            switch (*(u32 *)(p2 + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p2 + ((idx * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            }
            arr2[j] = *(u16 *)(q + 2);
        }
    }
    for (i = 0; i < *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8); i++) {
        dst = p + ((i * 3) * 0x10) + 0x14;

        func_0043f9c8(dst, 0, 0x30);
        func_0043f810(dst, func_0010fcb0(arr2[i]), 0x30);
    }
}
/* measured: see the annotation above the matching `on` pragma (func_002e68b0). */
#pragma opt_loop_invariants off

/* measured: structure fully recovered (both jump-table switches with
   {0,2,7,8}->+0x14 / {1,5,6,10}->+0xA4 / default, x = var2[4] loaded at the
   switch1 join, y loaded at the switch2 join, andi 0xffff at the compare) but
   mwcc b210 CSEs the type load across the jump-table switch (kept in $v1)
   where retail's allocator puts it in $v0, which the dispatch jr clobbers,
   forcing retail's reload; plus first-load coloring a->$a3 vs $a2 and
   b->$a1 vs $v1. Tried x/y as u8/s32 with (u16) casts, both switch type-load
   spellings, hoisted and inline loads; all give the identical nd 70 of pure
   register renames. This is the load-CSE/coloring floor. */
// FUN_002E6B20
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6b20);

/* measured: full structure recovered (entry/slotp split re-derefs, sort via
   func_00440bb8 with u16 count, loop2 jump-table switch {0,2,7,8}->+0x14 /
   {1,5,6,10}->+0xA4, loop3 re-zero + re-copy) but mwcc b210 CSEs the loop2
   p2 load (D_00882F70[arg0]+0x38) into the count2 load's intermediate, where
   retail re-issues the full arg0 re-index (dsll32/sll/lui/lw/lw) after the
   blez guard; every spelling tried (block-scoped p2, (s32)(s8)arg0 cast,
   entry-vs-slotp paths, p2-before-count2 order) gives nd 140 with the same
   missing re-index block and a cascading register-allocation shift (arg0 not
   saved to $s2, q in $s2). This is the load-CSE floor. */
// FUN_002E6C90
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6c90);
// FUN_002E6F00
/* measured: without `opt_loop_invariants on` MWCC rematerializes the -1 store
   constant at the top of the loop body (nd 6) instead of hoisting it into the
   preheader as retail does (addiu $a1,$zero,-1 before the initial branch). */
#pragma opt_loop_invariants on
void func_002e6f00(void) {
    s16 *buf;
    s16 i;
    s16 value;

    func_0044ea90(D_0063FC48, 0x649);
    buf = (s16 *)D_008873F4[0](1, 0x62, 0x40000);
    i = 0;
    value = -1;
    while (i < 0x30) {
        buf[i] = value;
        i++;
    }
    buf[0x30] = 0;
}
/* measured: see the annotation above the matching `on` pragma (func_002e6f00). */
#pragma opt_loop_invariants off
