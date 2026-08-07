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

/* measured 2026-08-03 (re-attack, wave 14): LEVER 1 HIT — the true signature
   is func_002e4960(void *dest, s8 arg0, s16 arg1); the old note's 2-arg decl
   was missing the dest pointer (caller at 0x30f0a8: addiu $4,$29,0x60; lb $5,
   0x2F9($16); lb $6,0x2FA($16)). With dest added, the body is a 6x8-byte copy
   loop (0x30 bytes) from p + arg1*0x30 + 0x14 (types 8/7/0) or +0xA4 (types
   6/5/A/1) into dest. LEVER 5: declaring cases 0,7,8 then 1,A,5,6 (reverse
   order) gives retail's exact descending test chain 6,5,A,1,8,7,0. Structure
   now matches to nd 24: the ONLY residual is register allocation — retail
   keeps p in $t0 and the default-case loop counter in $a3 (the switch const-6
   register, reused after the dispatch), while mwcc b210 colors p->$a3 and the
   counters->$t0, plus 3 operand-order addu words (retail index-first
   `addu $v1,$v1,$t0`, mine base-first `addu $v1,$a3,$v1`; lever-2 struct
   spelled via a[arg1]/a[arg1+3] union failed to compile). Pure
   register-colouring floor, nd 24. */
// FUN_002E4960
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4960);
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

/* measured 2026-08-03 (wave 14 re-attack): LEVER 6 applies directly — retail
   reloads the type (lw 4(p)) into $v0/$v1/$a2/$a2 across the four jump-table
   dispatches because each dispatch jr clobbers $v0; spelling the four reads
   with distinct integer-domain casts (*(s32*)(p+4) / (u32)p+4 / (s8*)p+4 /
   (u8*)p+4) forces four distinct CSE keys and the reloads (recorded 135 ->
   121). The residual: retail keeps offA=a*0x30 in $a3 and offB=b*0x30 in $t0
   and re-derives p+offA per slot, while mwcc hoists p+offA into $a3 and
   shares it across dispatch1/2 (and similarly for p+offB). Named offA/offB
   locals regress to 158 (frame/blowup); inline expressions give 121. Load-
   hoist/coloring floor, nd 121 (was 135). */
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

/* measured 2026-08-03 (wave 14 re-attack): old note's nd 70 was DISPROVED as
   a pure floor. LEVER 6 is the key: retail reloads the type (lw 4(p)) into $v0
   then $a1 after each jump-table dispatch because the dispatch jr clobbers
   $v0; mwcc CSEs it into $v1. Spelling the second read with a different
   integer-domain cast — switch2 on `*(s32 *)((u8 *)p + 4)` (switch1 on
   `*(s32 *)(p + 4)`) forces a distinct CSE key and the two loads come out
   (70 -> 25). Then DECLARE/LOAD p before b (`u8 *p; ... p = ...; b = *arg1;`)
   so allocation lands b->$v1 / p->$a0 like retail (25 -> 6). v1/v2 must be
   u16 (retail andi 0xffff, not 0xff). Residual is exactly the top load ORDER:
   retail emits lh a; lh b; lui/lw/lw(p); mwcc emits lh a; p-chain; lh b no
   matter the spelling — tried #pragma schedule on (89), opt_common_subs off
   (13), e-split (24), decl orders (24). 4 instruction words + 2 pool-number
   relocs. Load-order scheduling floor, nd 6. */
/* A qsort-style comparator. Both halves select a per-entry field through the
   SAME 11-entry switch on *(base + 4), decoded from jtbl_00748FE0 and
   jtbl_00748FB0 with tools/jtbl.py: cases 0/2/7/8 take offset 0x14, cases
   1/5/6/10 take 0xA4, and cases 3/4/9 share the out-of-range default, which
   also takes 0x14 - so the first and third blocks are byte-identical
   duplicates in retail as well.
   measured: nd 159 at exactly retail's 356-byte object. Every instruction and
   the whole block layout line up; the entire residual is that the allocator
   shifts one register (retail ia=$a2, ib=$v1, selector=$v0; b210 ia=$a3,
   ib=$a1, selector=$v1). Measured identical at nd 159: swapping the two index
   loads, declaring the indices last, and casting the comparison through
   (s32)(u16); s32 indices, inlining the second load and loading the base
   first are all worse. Register colouring floor. Committed at nd 45. */
// FUN_002E6B20 NONMATCHING
#ifdef NON_MATCHING
/* measured: retail re-issues the comparison operands b210 would share; turning
   common-subexpression sharing off restores that, nd 159 -> 45. */
#pragma opt_common_subs off
s32 func_002e6b20(s16 *arg0, s16 *arg1) {
    s16 ia;
    s16 ib;
    u8 *base;
    u8 *pa;
    u8 *pb;
    s32 va;
    s32 vb;

    ia = *arg0;
    ib = *arg1;
    base = *(u8 **)(D_00882F70[0] + 0x38);
    switch ((u32)*(s32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        pa = base + ia * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        pa = base + ia * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        pa = base + ia * 0x30 + 0x14;
        break;
    }
    va = *(u8 *)(pa + 4);
    switch ((u32)*(s32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        pb = base + ib * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        pb = base + ib * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        pb = base + ib * 0x30 + 0x14;
        break;
    }
    vb = *(u8 *)(pb + 4);
    if (vb < (va & 0xFFFF)) {
        return 1;
    }
    return -((va & 0xFFFF) < vb);
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6b20);
#endif

/* measured 2026-08-03 (wave 14 re-attack): func_002e6c90 is the sibling of the
   MATCHED func_002e68b0 (same structure) with func_002e6b20 as the sort
   comparator. Porting func_002e68b0's exact C (same decl order, same p2
   re-index spelling `(u8 *)*(u8 **)((u8 *)D_00882F70 + (u32)(s8)arg0 * 4)` +
   the same loop2/loop3 shapes) cut the recorded nd 140 to 52 and fixed the
   old "arg0 not saved to $s2" defect (arg0 now correctly -> $s2) and the
   missing p2 re-index (now emitted). Residual is a pure register rotation in
   loop2: mine j->$a2/count2->$a1/p2->$a0/idx->$t0/q->$a3 vs retail
   j->$a3/count2->$a2/p2->$a1/idx->$t1/q->$t0 (one register lower each).
   Tried decl-order variants (61), #pragma opt_propagation off (52, no
   change). Register-rotation floor, nd 52 (was 140). */
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
