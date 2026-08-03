/* Original translation unit cmmMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_00440b68(const char *fmt, const char *file, s32 line);
extern void *func_00454a60(const char *path, s32 flags);
extern void func_00456150(void *handle);
extern u8 *func_00455ea0(void *handle, s32 index, void *out);
extern void func_0046d730(const char *file, s32 line);
extern void func_0046d700(const char *file, s32 line, char *fmt, s32 value);
extern s32 func_001060b0(void);
extern s32 func_00106330(s32 flag);
extern void func_00106390(s32 id, s32 flag);
extern s32 func_001064f0(s32 idx);
extern s32 func_00106550(s32 id, s32 value);
extern s32 func_00106600(s32 idx);
extern void func_00106620(s32 a, s32 b);
extern s32 func_00107b70(s32 idx);
extern s32 func_00107c80(s32 idx);
extern void func_00107ce0(s32 idx);
extern s32 func_00107ea0(s32 idx);
extern s32 func_001087e0(s32 idx);
extern s32 func_001070e0(s32 idx);
extern s32 func_00110580(s32 a);
extern s32 func_00110680(s32 a, s32 b, s32 c);
extern s32 func_001106f0(s32 a, s32 b, s32 c, s32 d, s32 e);
extern s32 func_00107240(s32 idx);
extern s32 func_00107ac0(s32 idx);
extern s32 func_001093a0(s32 idx);
extern s8 func_00248760(s32 idx);
extern s32 func_001077f0(s32 idx);
extern s32 func_00109280(s32 idx);
extern s32 func_00109300(s32 idx);
extern s32 func_0010b6f0(void);
extern void func_001104d0(s32 seed, s32 *month, s32 *day);
extern s32 func_001064f0(s32 idx);
extern u32 func_00110600(u8 a, u8 b);
extern s32 func_00110d30(s32 idx);
extern s32 func_00249010();
extern u16 func_002489c0(s32 arg0);

extern char D_006359D0[];
extern char D_006359E0[];
extern char D_007636F0;
extern char D_007636F8;
extern u8 *D_00881480[];
extern u8 *D_00881484[];
extern u8 *D_0088148C[];
extern s32 D_0088149C[];
extern s32 D_008814A0[];
extern s32 D_008814A4[];
extern s32 D_008814A8[];
extern s32 D_008814AC[];
extern u8 *D_008814B0[];
extern u8 *D_008814B4[];
extern s32 D_008814B8[];
extern u8 *D_008814BC[];
extern u8 *D_008814C4[];
extern u8 *D_008814D4[];
extern u8 *D_008814D8[];
extern u8 *D_008814DC[];
extern u8 *D_008814E0[];
extern u8 *D_008814E4[];
extern s32 D_008814E8[];
extern s32 D_008814EC[];
extern u8 *D_00881490[];
extern u8 *D_00881494[];
extern u8 *D_00881498[];
extern u8 *D_008814C0[];
extern u8 *D_008814C8[];
extern s32 D_008814CC[];
extern u8 *D_008814D0[];

// FUN_00246700
void func_00246700(void) {
    u32 sp3C;
    s32 i;
    void *handle;

    func_00440b68(&D_007636F0, D_006359D0, 0x3F);
    func_00456150(handle = func_00454a60(D_006359E0, 1));
    for (i = 0; i < 0x1C; i++) {
        D_00881480[i] = func_00455ea0(handle, i, &sp3C);
    }
}

// FUN_002467B0
u8 *func_002467b0(s32 arg0) {
    u8 *temp_16 = D_00881480[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// FUN_00246830
u8 *func_00246830(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_00881484[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        func_0046d730(D_006359D0, 0x54);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

// FUN_002468A0
u8 *func_002468a0(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_008814DC[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        func_0046d730(D_006359D0, 0x5C);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

/* measured: re-measured nd 9 (flat expr, s16 arg). Retail loads
   D_0088149C into $a1 FIRST (lui/lw), then sign-extends arg0 and runs the
   sll/addu/sll x24 chain in $v0, final `addu $v0,$v0,$a1`. mwcc b210 always
   sinks the lui/lw after the chain and holds the loaded value in $v0
   (addu $v0,$v0,$v1). s64-arg m2c spelling: nd 13 + 4B oversize. Tried also
   hoisted local, separated statements, both orders, s16/s32 args (prior
   wave, all nd 9). Load-sinking floor (same family as FUN_00246940). */
// FUN_00246910
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246910);

/* measured: retail loads D_008814A0 into $a1 FIRST, then sign-extends and
   multiplies; mwcc b210 sinks the load after the multiply chain in every
   spelling tried (flat expr, hoisted base local, separated statements, s16
   vs s32 arg; all nd 9). Load-sinking floor (same family as FUN_00246910). */
/* measured: same load-sinking floor as FUN_00246910 (re-measured nd 9):
   retail loads D_008814A0 into $a1 FIRST, then the x20 chain; mwcc b210
   sinks the load after the chain and uses $v0 for the loaded value.
   Tried flat expr, hoisted base local, separated statements, s16 vs s32
   arg (all nd 9). Load-sinking floor. */
// FUN_00246940
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246940);

// FUN_00246970
s32 func_00246970(void) {
    return D_008814A4[0];
}

// FUN_00246980
s32 func_00246980(s16 arg0, s16 arg1) {
    s32 base = D_008814A8[0] + 8;

    if (arg0 >= 5) {
        func_0046d730(D_006359D0, 0xBC);
    }
    if ((arg1 <= 0) || (arg1 > 5)) {
        func_0046d700(D_006359D0, 0xBD, &D_007636F8, arg1);
    }
    return base + arg0 * 0x41 + (arg1 - 1) * 0xD;
}

/* measured: retail emits `addu $v1, $v0, $s2` then `addu $v0, $v0, $v1`
   (fresh sll results in rs, older value in rt). mwcc b210 puts fresh in rt.
   Naming the offset in an s32 local (`mid = index + base`) flips the FIRST
   addu to retail's order (nd 5 -> 4); also naming the second operand
   (`tail = arg1 * 2`) rotates every saved register (nd 17). Best nd 4: only
   residual is `addu $v0, $v1, $v0` vs retail `addu $v0, $v0, $v1`.
   Addu-operand-order floor (same family as FUN_002487E0/FUN_00249670). */
// FUN_00246A50
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246a50);
// FUN_00246B10
u8 *func_00246b10(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_008814B0[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        func_0046d730(D_006359D0, 0xD1);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

// FUN_00246B80
s32 func_00246b80(void) {
    return D_008814B8[0] + 8;
}

// FUN_00246BA0
u8 *func_00246ba0(s32 arg0) {
    u8 *temp_16 = D_008814BC[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0xEE);
    }
    off = (u16)arg0 * 24;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// FUN_00246C20
u8 *func_00246c20(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_008814C4[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        func_0046d730(D_006359D0, 0x104);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

// FUN_00246C90
u8 *func_00246c90(u32 arg0) {
    if (arg0 >= *(u32 *)(D_008814D4[0] + 4)) {
        return NULL;
    }
    return (u8 *)((arg0 << 6) + (u32)D_008814D4[0] + 8);
}

// FUN_00246CD0
u8 *func_00246cd0(s32 arg0) {
    u8 *temp_16 = D_008814E0[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x13B);
    }
    off = (u16)arg0 * 72;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// FUN_00246D50
u8 *func_00246d50(u32 arg0) {
    if (arg0 >= *(u32 *)(D_008814D8[0] + 4)) {
        return NULL;
    }
    return (u8 *)((arg0 << 6) + (u32)D_008814D8[0] + 8);
}

// FUN_00246D90
u8 *func_00246d90(s32 arg0) {
    u8 *temp_16 = D_008814E4[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x15B);
    }
    off = (u16)arg0 * 66;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// FUN_00246E10
s32 func_00246e10(s32 arg0) {
    s32 temp_16;
    s32 temp_2;
    s32 off;

    temp_16 = D_008814E8[0];
    temp_2 = arg0 & 0xFFFF;
    if ((temp_2 <= 0) || (temp_2 > 0xC)) {
        func_0046d730(D_006359D0, 0x163);
    }
    off = (u16)arg0 * 72;
    return off + (u32)temp_16 - 0x40;
}

/* measured: nd 6 -> 3 with two levers: (1) lever-10 named-offset local
   (`off = (u16)arg0 * 14; mid = off + base;`) fixed the addu-operand-order
   residual; (2) `m = arg0 & 0xFFFF;` as a STATEMENT before the if fixed
   the andi/bltz order (`andi $v0,$s1` now precedes the branch, matching
   retail's layout). Single remaining word: retail `bltz $v0` (tests the
   MASKED value) vs mwcc `bltz $s1` (raw arg0) for `arg0 < 0`; the masked
   spelling `(arg0 & 0xFFFF) < 0` folds to false and DELETES the bltz
   (nd 23), `(s16)` casts materialize dsll32/dsra32 (nd 23), u16/s32 temps
   fold or CSE. Dead-comparison-elimination floor (recipe A family). */
// FUN_00246E90
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246e90);
// FUN_00246F10
s32 func_00246f10(s32 arg0) {
    u16 temp_2;
    u16 temp_3;
    u8 *var_19 = D_008814B4[0] + 8;
    s32 temp_17 = *(s32 *)(D_008814B4[0] + 4);
    s32 var_18 = 0;
    s32 a0 = arg0 & 0xFFFF;

    while (var_18 < temp_17) {
        temp_2 = *(u16 *)var_19;
        if (temp_2 == 0 || temp_2 == a0) {
            temp_3 = *(u16 *)(var_19 + 4);
            switch (temp_3) {
            case 0:
                if (func_00110680((s16)func_001060b0(), var_19[6], var_19[7]) != 0) {
                    return 1;
                }
                break;
            case 1:
                if (*(u16 *)(var_19 + 6) == func_00110580((s16)func_001060b0())) {
                    return 1;
                }
                break;
            }
        }
        var_19 += 8;
        var_18++;
    }
    return 0;
}
// FUN_00247020
s32 func_00247020(void) {
    if ((func_00106330(0x11) == 0) && (func_001106f0((s16)func_001060b0(), 4, 0x12, 4, 0x1D) != 0)) {
        return 1;
    }
    if ((func_00106330(0x12) == 0) && (func_001106f0((s16)func_001060b0(), 5, 0x12, 6, 4) != 0)) {
        return 1;
    }
    if ((func_00106330(0x13) == 0) && (func_001106f0((s16)func_001060b0(), 6, 0x18, 7, 9) != 0)) {
        return 1;
    }
    if ((func_00106330(0x14) == 0) && (func_001106f0((s16)func_001060b0(), 7, 0x1B, 8, 0xC) != 0)) {
        return 1;
    }
    if ((func_00106330(0x15) == 0) && (func_001106f0((s16)func_001060b0(), 9, 0x10, 0xA, 5) != 0)) {
        return 1;
    }
    if ((func_00106330(0x16) == 0) && (func_001106f0((s16)func_001060b0(), 0xB, 6, 0xB, 0x14) != 0)) {
        return 1;
    }
    if ((func_00106330(0x17) == 0) && (func_001106f0((s16)func_001060b0(), 0xC, 8, 0xC, 0x18) != 0)) {
        return 1;
    }
    return 0;
}
/* measured: retail re-issues var_19&0xFFFF into $a0 at every call site
   (7+ sites) while keeping temp_18 in $s2 for the idx checks and the
   multiply (4 saved regs); mwcc b210 CSEs the call-arg masks into $s2 and
   emits move $a0,$s2 instead of andi (nd 35, all diffs from this one
   pattern; structure otherwise matches). Mask-CSE floor (same family as
   FUN_002474F0, whose draft differs only in one comparison, floored nd 33;
   also FUN_002483C0/FUN_00248B80). */
// FUN_00247270
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247270);

/* measured: retail re-issues the var_19&0xFFFF mask into $a0 at every call
   site (10+ times) while keeping temp_18 ($s2) for the idx checks; mwcc b210
   CSEs the call-arg masks into $s2 and emits move $a0, $s2 instead of andi
   (nd 33, all diffs from this one pattern; u32 vs s32 temp_18 unchanged).
   Mask-CSE floor (same family as FUN_00247DD0/FUN_00248A60). */
// FUN_002474F0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002474f0);
/* measured: retail allocates best=$s2, bestId=$s1, se=$s0, i=$s3; mwcc
   b210 insists on se/i in the $s0/$s1 pair and best/bestId in $s2/$s3 in
   every declaration order tried (best nd 14). Using `(u16)i` at the first
   call site broke mwcc's mask-CSE (which hoisted i&0xFFFF into a 5th saved
   register, nd 42) but no spelling moves bestId to $s1 with i at $s3.
   Saved-register-rotation floor (same family as FUN_00247820). */
// FUN_00247770
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247770);
/* measured: retail allocates target=$s0, best_id=$s1, best=$s2, i=$s3,
   v=$s4; mwcc b210 gives i=$s2, best=$s3, best_id=$s4, v=$s5 in every
   declaration order tried (nd 52); s8 vs s32 target fixed the re-cast but not
   the rotation. Saved-register-rotation floor (same family as FUN_00247770). */
// FUN_00247820
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247820);
/* measured: retail reads spB0 (u_long128, sq at 0xB0) with `lq` AFTER the
   func_00109280 call and compares via single bne; mwcc b210 hoists the load
   before the call into $s7 and narrows it (lq+dsll32/dsra32 pair with the
   value cast, lw with the s64 alias read; both nd 121+, operand swap and
   (u32) spA0 cast fixed everything else). The store side (sq after
   dsll32/dsra32 24) and spA0's sq match. Load-hoisting + 128-bit-read-shape
   floor; rule-3 alias-read note: retail's lq has NO narrowing pair, and no
   spelling of the read reproduced the post-call lq. */
// FUN_00247900
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247900);

// FUN_00247C20
s32 func_00247c20(s16 arg0) {
    s32 i = 0;
    s32 key = (s32)arg0;

    while (i < (func_0010b6f0() & 0xFFFF)) {
        if (key == (func_00109280(func_00109300(i & 0xFFFF) & 0xFFFF) & 0xFF)) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* measured: retail loads each case constant with daddiu ($s0, $zero, imm)
   and re-materializes it for the call arg (addiu $a0, $zero, imm), while mwcc
   b210 emits addiu for the variable and CSEs the constant into a move (nd 16)
   in every spelling tried (s32/s16/s64/u32 vars, L-suffix constants, arg-from-
   var). 64-bit-constant-load floor. */
// FUN_00247CB0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247cb0);
/* measured: retail re-issues the var_18&0xFFFF mask per use (check into
   $v1, ladder/arg into $a0, func_001077f0 arg, return) with a 3-saved-reg
   frame; mwcc b210 CSEs the mask into a saved register $s2 across the calls
   (4 saved regs, nd 31) in every spelling tried ((u16) vs & 0xFFFF mixes).
   Mask-CSE floor (same family as FUN_00247770/FUN_00248E90). */
// FUN_00247DD0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247dd0);
// FUN_00247EC0
s32 func_00247ec0(s32 seed) {
    u8 *p = D_00881498[0] + 8;
    s32 a, b;
    s32 a0, b0;
    s32 i;
    s32 count;

    func_001104d0(seed, &a, &b);
    count = *(s32 *)(D_00881498[0] + 4);
    i = 0;
    a0 = a;
    b0 = b;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            return 1;
        }
        p += 2;
        i++;
    }
    return 0;
}

/* measured: retail hoists the &sp3C/&sp38 outputs of func_001104d0 into
   $a0/$v1 before the loop, keeps ret in $v0, and folds the not-found test
   away; mwcc b210 reloads both stack slots per iteration, keeps ret in a
   saved register, and emits the post-loop i>=count test (best nd 53 across
   pre-init, m2c-goto, and post-test shapes). Load-sinking floor. */
// FUN_00247F60
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247f60);
// FUN_00248040
s32 func_00248040(s32 arg0) {
    s32 var_16 = arg0 + 1;
    s32 var_2;
    goto body;
incr:
    var_16 += 1;
    if (var_16 < 0x16D) {
        goto body;
    }
    return 0;
body:
    if (func_00110d30(var_16) == 0) {
        var_2 = 0;
    } else if (func_00247ec0(var_16) != 0) {
        var_2 = 0;
    } else {
        var_2 = 1;
    }
    if (var_2 != 0) {
        return var_16;
    }
    goto incr;
}
/* measured: retail booleanizes the match chain (ret in $v0, fail block out
   of line) with 8 saved regs; mwcc b210 inlines the fail skips and balloons
   to 10 saved registers (best nd 30 without the ret booleanize, 82 with).
   Register-pressure + if-chain-layout floor. */
// FUN_002480E0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002480e0);
/* measured: retail re-issues var_20&0xFFFF into $a0 at every call site
   (4 sites) plus the multiply, keeping temp_18 in $s2 (5 saved regs); mwcc
   b210 CSEs the mask into a saved register $s3 at loop top and emits move
   $a0,$s3 per call (nd 73). Mask-CSE floor (same family as
   FUN_002474F0/FUN_002483C0/FUN_00248B80; the & 0xFFFF vs (u16) mixes
   proven ineffective on FUN_00248B80). */
// FUN_00248240
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248240);
/* measured: retail re-issues i&0xFFFF into $a0 at every call (10 sites);
   mwcc b210 CSEs the mask into a saved register and emits move $a0, $s3 (nd
   30+). Mask-CSE floor (same family as FUN_002474F0/FUN_00248240). */
// FUN_002483C0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002483c0);
/* measured: #pragma opt_loop_invariants on/off scoped around this function:
   retail hoists arg1&0xFFFF and var_4&0xFFFF into $s1/$s6 before the loop;
   without the pragma mwcc b210 re-masks inside the loop (nd 43 -> 2). s32
   arg1 (not u16) is also required so the ladder calls pass the raw register
   instead of a CSE'd mask. */
// FUN_002485E0
#pragma opt_loop_invariants on
u8 *func_002485e0(s32 arg0, s32 arg1) {
    s32 var_4 = arg0;
    s32 var_2;
    s32 temp_18;
    s32 var_20;
    s32 temp_4;
    u8 temp_16;
    u8 *var_19;

    if (!(var_4 & 0xFFFF)) {
        if (func_001077f0(arg1) == 0) {
            var_2 = 3;
        } else if (func_001087e0(arg1) != 0) {
            if ((func_00107ac0(arg1) & 0xFFFF) == 9) {
                var_2 = 6;
            } else {
                var_2 = 2;
            }
        } else {
            var_2 = 1;
        }
        var_4 = var_2 & 0xFFFF;
    }
    var_19 = (u8 *)(D_0088148C[0] + 8);
    temp_18 = *(u32 *)(D_0088148C[0] + 4);
    var_20 = 0;
    while (var_20 < temp_18) {
        if ((*(u16 *)var_19 == (arg1 & 0xFFFF)) && (*(u8 *)(var_19 + 2) == (var_4 & 0xFFFF)) && ((temp_16 = *(u8 *)(var_19 + 3), temp_16 == 0) || ((temp_16 != 0) && (temp_16 == (func_00107ac0(arg1) & 0xFFFF)))) && ((temp_4 = *(u32 *)(var_19 + 0xC), temp_4 == 0) || (func_00106330(temp_4) != 0))) {
            return var_19;
        }
        var_19 += 0x10;
        var_20 += 1;
    }
    return NULL;
}
#pragma opt_loop_invariants off
// FUN_00248760
s8 func_00248760(s32 arg0) {
    u8 *temp_16 = D_00881480[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    return *(s8 *)(off + (u32)temp_16 + 0x10);
}

// FUN_002487E0
s8 func_002487e0(s32 arg0, s8 arg1) {
    u8 *base;
    s32 off;
    s32 elem;
    s32 idx;
    s32 p;
    u8 *q;
    s32 v;

    if (arg1 >= 8) {
        func_0046d730(D_006359D0, 0x3A3);
    }
    base = D_00881480[0];
    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(base + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    elem = off + (s32)base + 8;
    if (elem != 0) {
        idx = arg1 * 8;
        p = idx + elem;
        q = (u8 *)(p + 0x28);
        if (*(u32 *)(p + 0x28) != 0) {
            v = *(u32 *)(p + 0x24);
            if ((v == 0) || (func_00106330(v) != 0)) {
                return *(s8 *)q;
            }
        }
    }
    return 0;
}
// FUN_002488E0
s32 func_002488e0(s32 arg0, s32 arg1) {
    s32 temp_3;
    s32 var_4;
    u8 *temp_16 = D_00881480[0];
    u8 *temp_2;
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    temp_2 = (u8 *)(off + (u32)temp_16 + 8);
    if (temp_2 != NULL) {
        var_4 = *(u16 *)(temp_2 + 0xC);
    } else {
        var_4 = 0;
    }
    temp_3 = arg1 & 0xFF;
    if ((temp_3 == 0) || (temp_3 >= 0xA)) {
        return 0;
    }
    return (var_4 & (1 << (temp_3 - 1))) != 0;
}
// FUN_002489C0
u16 func_002489c0(s32 arg0) {
    u8 *temp_16 = D_00881480[0];
    s32 off;
    u8 *temp_2;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    temp_2 = (u8 *)(off + (u32)temp_16 + 8);
    if (temp_2 != NULL) {
        return *(u16 *)(temp_2 + 0xE);
    }
    return 0;
}

/* measured: retail keeps arg0 raw in $s3, masks once into $s1 (temp_17)
   and re-masks into $v1 for the 100-multiply; mwcc b210 CSEs the mask into
   one register (best nd 37) in every spelling tried ((u16) vs & 0xFFFF vs
   temp_17 = arg0). Mask-CSE floor (same family as FUN_00247DD0). */
// FUN_00248A60
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248a60);
/* measured: retail re-issues var_18&0xFFFF into $a0 at every call site
   (3 sites) while keeping temp_21 in $s5 for the bounds checks (6 saved
   regs); mwcc b210 CSEs the mask into a saved register $s0 at loop top and
   emits move $a0,$s0 per call (nd 75; tried & 0xFFFF / (u16) mixes at all
   sites, temp_21 u32 vs s32). Mask-CSE floor (same family as
   FUN_002474F0/FUN_002483C0/FUN_00248A60). */
// FUN_00248B80
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248b80);

/* measured: retail hoists the 0xFFFF0000 mask constant into $v1 before the
   loop and keeps the loop count in $t0; without #pragma opt_loop_invariants
   mwcc b210 rematerializes lui per iteration (nd 16). Declarations must be
   count/var_10/var_9/temp_7 order for the $t0/$t1/$t2 allocation. */
// FUN_00248D00
#pragma opt_loop_invariants on
s32 func_00248d00(s32 arg0, s32 arg1, s32 arg2) {
    s32 count;
    u8 *var_10;
    s32 var_9;
    s32 temp_7;

    var_10 = D_008814C0[0] + 8;
    count = *(s32 *)(D_008814C0[0] + 4);
    var_9 = 0;
    while (var_9 < count) {
        temp_7 = *(s32 *)var_10;
        if ((((u32)(temp_7 & 0xFFFF0000) >> 0x10) == arg0) && ((temp_7 & 0xFFFF) == arg1) && (*(u16 *)(var_10 + 4) == arg2)) {
            return *(s32 *)(var_10 + 8);
        }
        var_10 += 0xC;
        var_9 += 1;
    }
    return -1;
}
#pragma opt_loop_invariants off

/* measured: rule-3 check: retail's two dsll32/dsra32 pairs are (s16)
   sign-extensions of 32-bit values (arg0 and the func_00107240 result), not
   quadword-narrowing casts - no lq data load exists, so the typed-alias
   read does not apply. Retail sign-extends (s16)arg0 into $s0 between the
   two calls (3 saved regs, -0x40 frame); mwcc b210 sinks the dsll32/dsra32
   cast to its use after the second call into a temp (2 saved regs, -0x30
   frame, nd 37) in every spelling tried (inline cast, s16 locals at top,
   se-first declaration order). Load/cast-sinking floor. */
// FUN_00248D80
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248d80);
// FUN_00248E20
s32 func_00248e20(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_16;
    s32 temp_3;
    s32 temp_4;
    u8 *var_18;
    s32 var_17;
    u16 temp_2;

    var_18 = D_008814C8[0] + 8;
    temp_16 = *(s32 *)(D_008814C8[0] + 4);
    var_17 = 0;
    while (var_17 < temp_16) {
        temp_4 = *(s32 *)var_18;
        if (temp_4 == 0 || func_00106330(temp_4) != 0) {
            temp_3 = *(s32 *)(var_18 + 4);
            if (((u32)(temp_3 & 0xFFFF0000) >> 0x10) == arg0 && (temp_3 & 0xFFFF) == arg1 && (*(u16 *)(var_18 + 8) == 0xFFFF || *(u16 *)(var_18 + 8) == arg2)) {
                temp_2 = *(u16 *)(var_18 + 0xA);
                if (temp_2 & 0x8000) {
                    return temp_2;
                }
            }
        }
        var_18 += 0xC;
        var_17++;
    }
    return -1;
}
// FUN_00248F20
s32 func_00248f20(s32 arg0, s32 arg1) {
    u8 *temp_19 = (u8 *)(D_008814CC[0] + 8);
    s16 temp_17 = (s16)arg0;
    s32 temp_16;

    if (temp_17 >= 5) {
        func_0046d730(D_006359D0, 0x11B);
    }
    temp_16 = temp_17 * 8;
    if (arg1 <= *(s16 *)(temp_19 + temp_16)) {
        return 0;
    }
    temp_19 = (u8 *)(D_008814CC[0] + 8);
    if (temp_17 >= 5) {
        func_0046d730(D_006359D0, 0x11B);
    }
    if (arg1 <= *(s16 *)(temp_16 + (u32)temp_19 + 2)) {
        return 1;
    }
    return 2;
}

// FUN_00249010
s32 func_00249010(s32 seed) {
    u8 *base = D_008814D0[0];
    u8 *p = base + 8;
    s32 count = *(s32 *)(base + 4);
    s32 a, b;
    s32 a0, b0;
    s32 i;

    func_001104d0(seed, &a, &b);
    i = 0;
    a0 = a;
    b0 = b;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            return i;
        }
        p += 0x24;
        i++;
    }
    return -1;
}

/* measured: retail's not-found path sets i=-1 with no post-loop test and
   branches positively (beq -> .L158) to an out-of-line return NULL; mwcc b210
   emits the post-loop `i==count` test (bne), keeps the NULL return inline with
   a negated skip, and shifts the body by one word (best nd 27 across while,
   break, goto-done and m2c goto shapes). Loop-exit-test + layout floor. */
// FUN_002490B0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002490b0);
// FUN_00249180
u8 *func_00249180(u32 arg0) {
    s32 sp3C;
    s32 sp38;
    u8 *temp_17 = D_008814D0[0] + 8;

    func_001104d0(arg0, &sp3C, &sp38);
    if (func_00106330(0xA61) != 0) {
        temp_17 += func_001064f0(0x6D) * 0x24;
        if (arg0 >= func_00110600(temp_17[2], temp_17[3])) {
            return temp_17;
        }
    }
    return NULL;
}

// FUN_00249230
s32 func_00249230(void) {
    s32 seed;
    u8 *base8 = D_008814D0[0] + 8;
    s32 idx = func_00249010(seed);
    u8 *p;

    if (idx != -1) {
        p = base8 + idx * 0x24;
    } else {
        p = NULL;
    }
    if (p == NULL) {
        return 0;
    }
    return 1;
}

/* measured: retail places the shared temp_17=NULL block out of line
   (beqz/bnez -> .L334, main path b .L338) and booleanizes the final test with
   bnez/move/branch; mwcc b210 keeps both if bodies inline with negated skips
   and booleanizes via sltu (best nd 26 across if/else, merged-NULL, switch
   wraps, comparison forms). Single-statement-if layout floor. */
// FUN_002492B0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002492b0);
/* measured: retail merges the two base=NULL paths into one out-of-line
   block (.L49450) with both tests branching positively to it and the main
   path skipping via `b .L49454`; mwcc b210 keeps the NULL stores inline in
   both branch orders, uses sltu $at/beqz instead of sltu $v0/bnez for the
   arg1<result test, and inverts the final if/else return placement (best nd
   33). Out-of-line-if + comparison-form floor. */
// FUN_00249370
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249370);
/* measured: retail allocates arg0=$s0, temp_17=$s1, var_18=$s2, arg1=$s3
   (4 saved regs, -0x60 frame); mwcc b210 always gives arg0=$s1, arg1=$s0,
   temp_17+var_18 merged in $s2 (3 saved regs, -0x50 frame, nd 94-95) in
   every declaration order and temp shape tried (block-scoped pointers,
   draft-style temps, sp locals first/last). Call/if/branch structure and
   the func_001104d0 $a0-skip all match. Saved-register-rotation floor
   (same family as FUN_00247820/FUN_00247770). */
// FUN_002494C0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002494c0);

/* measured: retail emits `addu $s0, $v0, $s0` (call result, var) for
   var_16 = func_001064f0(0x57) + arg1; mwcc b210 only emits rs=result when
   the call result is named in a fresh s32 local on the LEFT (`var_16 =
   r + arg1`; nd 5 -> 4). Residual at nd 4 is 3 prologue words only: mwcc
   saves $a1 before $a0 (`move $s0,$a1; move $s1,$a0`) where retail saves
   $a0 first, and tests the raw $a0 in the first bnez where retail tests
   $s1. Tried: +=, both operand orders, temp local, declaration init,
   early `var_16 = arg1` (rotates + flips addu back, nd 5). Addu-ok;
   prologue-save-order floor. */
// FUN_00249670
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249670);
// FUN_00249770
s32 func_00249770(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_16;
    s32 var_20;
    s32 off;
    u8 *temp_20;
    u8 *p;
    s32 var_21;

    var_21 = 0;
    var_16 = 0;
    while (var_16 < 0x14) {
        temp_20 = D_008814E0[0];
        if ((u32)((var_16 + 1) & 0xFFFF) >= *(u32 *)(temp_20 + 4)) {
            func_0046d730(D_006359D0, 0x13B);
        }
        off = (u16)(var_16 + 1) * 72;
        p = (u8 *)(off + (u32)temp_20 + 8);
        var_20 = 0;
        if (arg0 == 0 || arg0 == *(s32 *)p) {
            var_20 += 1;
        }
        switch (arg1) {
        case 0:
            if (func_00106330(var_16 + 0x9B0) != 0) {
                var_20 += 1;
            }
            break;
        case 1:
            if (((func_00106600((s16)(var_16 + 0x4EB)) & 0xFF) > 0) && (func_00106330(var_16 + 0x9B0) == 0)) {
                var_20 += 1;
            }
            break;
        case 2:
            if ((func_00106600((s16)(var_16 + 0x4EB)) & 0xFF) > 0) {
                var_20 += 1;
            }
            break;
        case 3:
            if ((func_00106600((s16)(var_16 + 0x4EB)) & 0xFF) == 0) {
                var_20 += 1;
            }
            break;
        }
        if (var_20 == 2) {
            if (var_21 == arg2) {
                return var_16 + 1;
            }
            var_21 += 1;
        }
        var_16++;
    }
    return 0;
}

/* measured: recipe A re-test — nd 56 -> 12. Recipe A half-scaler shape
   (s32 z; u32 c=(u32)z; fz=(f32)(s32)((c>>1)|(c&1)); fz=fz+fz) + retail's
   layout `if (z >= 0) {direct} else {half-scaler}` (direct path inline,
   bltz to the out-of-line scaler) + naming the y-address `p = off+temp_16+8`
   (reproduces addiu $s1,$v0,8 / lh $s0,8($v0) / lh $v0,2($s1)) made
   everything through the join byte-identical. Residual 12 words: the
   arg0&0xFFFF bltz dead-comparison (3, same family as FUN_00246E90); the
   or-fold (mwcc or $v0,$v1,$v0 rd=rt vs retail or $v1,$v1,$v0 rd=rs + mtc1);
   the half-scaler cvt into $f0 scratch then add.s into $f1 (retail cvt.s.w
   $f1,$f0 directly); and mwcc hoists the x load+cvt above lui/mtc1/div.s
   with FP temps x=$f3/t=$f2 (retail div first, x=$f2/t=$f3, cascading into
   the madd.s operands). adda.s/madd.s are COP1 accumulator (acc+a*b). */
// FUN_00249960
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249960);

/* measured: recipe A re-test — nd 37 -> 5. Key crack: temp_16 must be a
   POINTER (u8 *) — as s32, mwcc folds the load offset 0xE into the *0xE as
   (x+1)*14 (extra addiu, nd 29); pointer-typed address arithmetic keeps
   retail's lh 0xE($v0). (s16) casts on the call args reproduce the
   dsll32/dsra32 16-bit sign-extension pairs for the s64 params of
   func_00113480; everything else is byte-identical. Residual 5 words:
   arg0&0xFFFF bltz dead-comparison (3, same family as FUN_00246E90 /
   FUN_00249960); addu rs/rt on the base add (mwcc addu $v0,$s0,$v0 vs retail
   $v0,$v0,$s0, source operand order does not change it); and the or rs/rt
   (or $v0,$v0,$v1 vs retail $v0,$v1,$v0 — or-fold family). */
// FUN_00249A60
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249a60);
