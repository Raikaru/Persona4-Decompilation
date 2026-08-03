#include "include_asm.h"
#include "type.h"

u16 func_00115750(u8 *arg0);
void func_0046d730(const char *file, s32 line);
s64 func_0023d8e0(u32 arg0, u16 arg1);
extern char D_005E4800[];

// FUN_001138C0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_001138c0);

/* measured: retail prologue saves in order `sd $a0,0x48; mov.s $f20,$f12; move $s1,$a1; move $s0,$a2` and sets up the inner call's FP args contiguously (cvt pair then mov.s $f14 before any GPR arg moves). mwcc b210 emits the same four value-saves with the fparg0 instructions last (`sd; move $s1; move $s0; mov.s $f20`) and defers `mov.s $f14,$f20` until after the $a2/$a3/$t0/$t1 setup, for every spelling tried: &arg0 derefs direct, s64 sp48 local, `f32 z = fparg0` first and between, m2c's inline-nested call, and `#pragma schedule on` (which instead reorders the whole body). nd 5, all five words are these two fparg0-scheduling positions; prologue/FP-arg save-order floor. */
// FUN_00113E30
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00113e30);

/* measured: rule 2 (FMA operand order) applied: `0.0f + 45.0f * fparg1 +
   129.0f * (1.0f - fparg1)` does emit the retail adda.s/madd.s pair with the
   same fs/ft order, but the function's frame (0xE0 vs retail 0xF0) and every
   saved register rotate: retail [arg3->$s0, temp_17->$s1, var_18->$s2,
   var_19->$s3, temp_2->$s4, arg2->$s5, temp_22->$s6, arg1->$s7, temp_lo->$fp,
   hi->$f20, fparg0->$f21, fparg1->$f22]; mwcc b210 assigns arg1->$s0,
   arg3->$s4, fparg0->$f20, fparg1->$f21 for every declaration order tried
   (with and without an explicit hi-word local). The guard-cvt color chains,
   S3f struct copy, d4c0 calls and the s16 spC0 switch all compile
   identically. nd 315; saved-reg/FP-reg rotation floor. */
// FUN_00113EF0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00113ef0);

/* measured: rule 2 (FMA operand order) applied: the same
   `0.0f + 45.0f * fparg1 + 129.0f * (1.0f - fparg1)` shape emits the retail
   adda.s/madd.s pair identically. But retail uses a 0x120 frame with FIVE
   callee-saved FP regs ($f20-$f24, fparg0 in $f24) while mwcc b210 builds a
   0x100 frame with four ($f20-$f23) and rotates every saved GPR, for the
   m2c-faithful spelling with an explicit hi local. The S3f copy at 0xF8, the
   mid-float u16 read at 0xFA, the constant-folded spF0 switch, the GPREL
   iGpffff8368 load and all d4c0 call shapes compile identically in
   isolation. nd 504; frame + saved-reg/FP-reg rotation floor. */
// FUN_00114460
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00114460);

// FUN_00114CB0
s32 func_00114cb0(u16 arg0) {
    s16 temp_2;

    if ((arg0 & 0xFFFF) >= 0x1B8) {
        return 0xC2;
    }
    temp_2 = (s16)func_0023d8e0(0, arg0);
    switch (temp_2) {
    case 0:
        return 0xB8;
    case 1:
        return 0xB9;
    case 2:
        return 0xBA;
    case 3:
        return 0xBB;
    case 4:
        return 0xBC;
    case 5:
        return 0xBD;
    case 6:
        return 0xBE;
    case 7:
        return 0xBF;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        return 0xC0;
    case -1:
        return -1;
    default:
        func_0046d730(D_005E4800, 0x32E);
        return 0;
    }
}

/* measured: retail emits its prologue value-saves as `sd $a0,0x30; mov.s $f20,$f12; sw $a1,0x3c; move $s0,$a3`, mwcc b210 emits a rotation of the same four independent saves (`move $s0` first or last, mov.s pinned at slot 2) for every source spelling tried: direct `*(f32 *)&arg0`/`*((u8 *)&arg1+n)` derefs, s64/sp3C locals with decl/assign combined and separated, `f32 z = fparg0` first, alpha split into `alpha = 0xFF; alpha -= byte;` (that split did fix the `subu $v0,$v1,$v0` operand order), and `#pragma schedule on` (which instead if-converts the blez). All give nd 4, all four words are this same rotation; prologue-save scheduling floor. */
// FUN_00114DC0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00114dc0);

/* measured: retail computes each d4c0 call's f32 args (1.0f+lo, hi-1.0f ...)
   before the alpha/GPR setup and emits `andi $a3,$s0,0xff` at ALL three
   calls; mwcc b210 emits the alpha chain first (argument evaluation order),
   coalesces temp_17 into arg1's $s0 register (retail coalesces temp_16 there
   instead), deletes the provably-redundant `temp_16 & 0xFF` masks at calls 1
   and 3 (keeping call 2's), orders `mov.s $f14` after `move $t3` in the call
   setups, and picks $f0 for the 2bc860 add (retail $f2). Tried: temp_16
   local vs inline, (u8)arg1 cast (kept all masks but reordered the whole arg
   setup, 73), x/y f32 locals before the calls (67), decl-order swaps,
   `#pragma schedule on` (103). nd 73; arg-eval-order + reg-coalescing +
   FP-arg-scheduling floor. */
// FUN_00114E50
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00114e50);

/* measured: retail allocates temp_7 (s8) to $a3 and var_6 (the `arg1 != 0`
   boolean) to $a2; mwcc b210 swaps them (temp_7 -> $a2, var_6 -> $a3) for
   every spelling tried: all 8 declaration orders, all def orders of the
   temp_7/count/var_6 loads, count local vs inline, `arg1 > 0` vs `arg1 != 0`
   with u32/s32 params, temp_7 loaded at its first use in the branches (160,
   no hoist). Everything else matches byte-for-byte (s8 sign-extension pairs,
   signed %4 fixup chains, D_008C027A[0] absolute lhu, sb stores). nd 9, all
   this a2/a3 rotation; temp-register rotation floor. */
// FUN_00115020
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115020);

// FUN_001152B0
u16 func_001152b0(u8 *arg0) {
    s8 temp_17;
    s32 p;
    u16 r;

    temp_17 = *(s8 *)(arg0 + 4);
    if ((temp_17 < 0) || (temp_17 > 8)) {
        func_0046d730(D_005E4800, 0x447);
    }
    if (temp_17 < 8) {
        if (temp_17 < (s32) *(u16 *)(arg0 + 0x68)) {
            p = temp_17 * 12;
            r = *(u16 *)(p + (s32)arg0 + 0xA);
        } else {
            r = 0;
        }
    } else {
        if ((temp_17 - 8) >= (s32) *(u16 *)(arg0 + 0x22C)) {
            func_0046d730(D_005E4800, 0x453);
        }
        r = *(u16 *)(arg0 + 0x6E);
    }
    return r;
}


// FUN_00115380
s16 func_00115380(u8 *arg0, s32 arg1) {
    s16 i;
    s32 target;
    s32 count;

    i = 0;
    target = arg1 & 0xFFFF;
    count = *(u16 *)(arg0 + 0x60);
    for (; i < count; i++) {
        if (target == *(u16 *)(arg0 + i * 12 + 2)) {
            return i;
        }
    }
    if (target == (func_00115750(arg0) & 0xFFFF)) {
        return 8;
    }
    return -1;
}

/* measured: retail allocates the s16 loop counter to $a1, the match key
   (`arg0 & 0xFFFF`) to $a3 and the u16 bound (0x224) to $a2, and reuses the
   counter register directly at the func_00115670 call (`move $a0,$s0; jal`,
   $5 already holds the counter). mwcc b210 pins the s16 counter in $a3 and
   gives the key $a2 / bound $a1 for EVERY spelling tried (10+ probe_variants
   batches: all 6 declaration orders, all 6 def orders, u16/s16 variants of
   key/bound/count, comparison-form swaps, while vs for, inline bound/key
   expressions, for-init placement, bound/key hoisted before the trap). The
   whole function is otherwise byte-identical. nd 23, all in this rotation
   plus the extra dsll32/dsra32 re-extension the call path needs; temp-register
   rotation floor. */
// FUN_00115420
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115420);

/* measured: same rotation as func_00115420 — retail reuses loop-1's dead
   registers for loop 2 (counter -> $a1, key -> $a3, bound -> $a2), mwcc b210
   assigns counter $a3 / key $a2 / bound $a1 regardless of declaration and def
   order (probed), adding a dsll32/dsra32 in the call path. First loop, join,
   trap and store all match. nd 25, all this rotation; temp-register rotation
   floor. */
// FUN_00115500
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115500);

// FUN_00115760
void func_00115760(u8 *arg0) {
    typedef struct {
        f32 v[3];
    } S3f;
    s32 i;
    s32 off;
    s32 p;

    if (*(u16 *)(arg0 + 0x224) <= 0) {
        func_0046d730(D_005E4800, 0x4B7);
    }
    for (i = 0; i < *(u16 *)(arg0 + 0x224) - 1; i++) {
        *(S3f *)(arg0 + i * 12 + 0x64) = *(S3f *)(arg0 + i * 12 + 0x70);
        *(u16 *)(arg0 + i * 2 + 0x1E4) = *(u16 *)(arg0 + i * 2 + 0x1E6);
    }
    off = *(u16 *)(arg0 + 0x224) * 12;
    p = off + (s32)arg0;
    *(u16 *)(p + 0x5A) = 0;
    off = *(u16 *)(arg0 + 0x224) * 2;
    p = off + (s32)arg0;
    *(u16 *)(p + 0x1E2) = 0;
    *(u16 *)(arg0 + 0x224) -= 1;
}

/* measured: retail trap-skip `bnez $3,0x1156b0` targets the loop pre-jump
   `b 0x1156f0`; mwcc b210 folds the chain and emits `bnez $3,0x1156f0`
   directly for every spelling tried: for/while loop, `#pragma schedule on`,
   and a `for(;;){if(i>=count-1)break;...}` break-loop (which instead keeps the
   loop test at the top, 21 words). All other words match byte-for-byte
   (i = (s16)arg1 dsll32/dsra32 pair, trap, S3f+u16 copies, stores). nd 1 real
   word, always this one skip-target; branch-target sharing floor. */
// FUN_00115670
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115670);

// FUN_00115750
u16 func_00115750(u8 *arg0) {
    return *(u16 *)(arg0 + 0x66);
}

