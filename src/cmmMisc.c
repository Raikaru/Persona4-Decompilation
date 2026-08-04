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
extern s32 func_00248a60(s32 arg0);
extern void func_00113480(s32 a, s32 b, s32 c, s32 d);

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

static inline s32 cmmMiscAddOff(s32 offset, s32 base) {
    return offset + base;
}

static inline s32 cmmMiscOr(s32 left, s32 right) {
    return left | right;
}

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

/* MATCHED (wave 14): `#pragma opt_propagation off` (measured: nd 9 -> 2,
   forces the single-use D_0088149C load into $a1 before the mul chain) + a
   hoisted `s32 base` local + the cmmMiscAddOff inline helper (measured:
   nd 2 -> 1, fixes the `addu $v0,$v0,$a1` mul-first operand order). Retail
   loads the global into $a1 FIRST, then the x24 chain, then `addu $v0,$v0,$a1`. */
// FUN_00246910
#pragma opt_propagation off
u8 *func_00246910(s16 arg0) {
    s32 base = D_0088149C[0];
    s32 mul = (s16)arg0 * 24;
    return (u8 *)(cmmMiscAddOff(mul, base) + 8);
}
#pragma opt_propagation on
// FUN_00246940
/* MATCHED (wave 14): same recipe as func_00246910 — `#pragma opt_propagation
   off` (measured: nd 9 -> 1, forces the single-use D_008814A0 load into $a1
   before the x20 chain) + hoisted `s32 base` local + cmmMiscAddOff helper
   (fixes the `addu $v0,$v0,$a1` operand order). Final residual is a benign
   reloc-masked word. */
#pragma opt_propagation off
u8 *func_00246940(s16 arg0) {
    s32 base = D_008814A0[0];
    s32 mul = (s16)arg0 * 20;
    return (u8 *)(cmmMiscAddOff(mul, base) + 8);
}
#pragma opt_propagation on
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

/* MATCHED (wave 14): lever-3 static inline helper `cmmMiscAddOff(offset, base)`
   carrying the addu operand order through its parameters fixed the two
   transposed `addu` residuals (nd 4 -> 0). The `index` local + first helper
   call fixed the first addu; the second call `cmmMiscAddOff(arg1*2, mid)`
   fixed the second. Original residual was `addu $v0,$v1,$v0` vs retail
   `addu $v0,$v0,$v1` (fresh sll result in rs). */
// FUN_00246A50
s32 func_00246a50(s16 arg0, s16 arg1) {
    s32 base = D_008814AC[0] + 8;
    s32 index;
    s32 mid;

    if (arg0 >= 5) {
        func_0046d730(D_006359D0, 0xC8);
    }
    if ((arg1 <= 0) || (arg1 > 5)) {
        func_0046d700(D_006359D0, 0xC9, &D_007636F8, arg1);
    }
    index = arg0 * 8;
    mid = cmmMiscAddOff(index, base);
    return *(s16 *)(cmmMiscAddOff(arg1 * 2, mid) - 2);
}
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

/* measured (wave 14 retest — nd 5 best, no match): named-offset locals
   `off = (u16)arg0 * 14; mid = off + base;` + `m = arg0 & 0xFFFF` statement
   + `arg0 < 0` first test keep everything but the bltz cluster (5 words:
   retail `andi $v0,$s1,0xffff; bltz $v0; slti $at,$v0,6` mask-first +
   $at dest, mwcc `bltz $s1; andi; slti $v0,$v0,6` raw-first + $v0 dest).
   `(arg0 & 0xFFFF) < 0` folds to false (nd 23); `(s16)m < 0` materializes
   dsll32/dsra32 (nd 23); `(u32)m > 0x7FFF` halves to nd 22. Dead-comparison
   elimination floor. */
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
/* measured (wave 14 retest — nd 12 best, no match): `(u16)i` at the FIRST
   call site + `i & 0xFFFF` at the second breaks the mask-CSE (no 5th saved
   reg) and `best=0; bestId=0; i=1; se=(s16)arg0;` init order (then a while
   loop) reaches nd 12 — better than this note's earlier nd 14. Residual is
   the pure saved-reg rotation: retail = best:$s2/bestId:$s1/se:$s0/i:$s3,
   mwcc = best:$s3/bestId:$s2/i:$s1 (se already $s0); decl-order and
   for-vs-while variants land 12-15. Saved-register-rotation floor (same
   family as FUN_00247820). */
// FUN_00247770
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247770);
/* measured (wave 14 retest — nd 50, no match): draft-based reconstruction
   (s8 target = func_00248760(arg0 & 0xFFFF); for i < (func_0010b6f0() &
   0xFFFF) — the count call is INSIDE the loop condition in retail;
   func_00109300(i & 0xFFFF) & 0xFFFF -> v; target == func_00109280(v) & 0xFF;
   func_001093a0(...) & 0xFF -> cur; best < cur -> best=cur, best_id=v;
   return (s16)best_id) — mwcc balloons the frame to 6 saved regs (-0x70 vs
   retail's 5 at -0x60) by CSE-ing i & 0xFFFF and duplicating the target
   sign-extension ($s5 copy); mixed (u16)i / i & 0xFFFF spellings are
   normalised (nd 50). Saved-register-rotation + Mask-CSE floor. */
// FUN_00247820
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247820);
/* measured (wave 14 — no fresh full-body attempt; complex 800B floor):
   below the recorded read-shape issue — retail reads the u_long128 spB0 with
   `lq` AFTER the func_00109280 call and compares via one bne, while mwcc
   b210 hoists the load before the call into $s7 and narrows it; no spelling
   reproduced the post-call lq. Structure per m2c draft: recursive
   func_00247900(arg0,arg1,-1), func_0044ea90 assert (extern added as
   void(const void*, s32)), D_008873F4 allocator call, the 0x100 loop with
   func_00109280/func_00107ac0 gates and var_18/var_17 list build, a bubble
   sort, then the jtbl_008873EC dispatch. Load-hoisting + 128-bit-read-shape
   floor; also needs the four vtable spellings for D_008873F4/jtbl_008873EC.
   func_00109280 takes (s32) — calls pass (u16) masks via leftover regs. */
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
/* measured (wave 14 retest): mask-CSE reconfirmed — my fresh reconstruction
   of the loop (mask = arg0&0xFFFF; for i in 0..0x1E, base = D_00881480[0];
   per-iteration checks, *100 ladder, func_002489c0(i&0xFFFF) with the
   leftover-$4 arg, func_001077f0, return i&0xFFFF) scores nd 48-49
   (note's earlier nd 31 with the func_002489c0 arg spelled explicitly).
   mwcc b210 still CSEs i&0xFFFF into a 4th saved register $s2 (frame -0x50
   vs retail's 3-reg -0x40); `(u16)i`/`i & 0xFFFF` mixes at the 5 sites are
   normalised away (nd 49), and the cmmMiscAddOff helper on the *100 ladder
   base-add only takes it to nd 48 (retail `addu $v0,$v0,$s0` mul-first, the
   helper fixed that one word). Mask-CSE floor. */
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

/* measured (wave 14 retest — nd 53 -> 16): `#pragma opt_loop_invariants on`
   (measured: 53 -> 16) DOES hoist the sp3C/sp38 outputs and the count into
   registers before the loop (retail's $a0/$v1/$a2), so the earlier
   "reloads per iteration" floor is gone. Loop body, advance, and the
   i<count test now match byte-for-byte. Residual 16 words are all the
   RETURN-sentinel layout: retail computes ret=1 (found) / ret=0 (loop end)
   into $v0 then a shared `beqz $v0 -> RET1` CHECK block (found->return 0,
   not-found->return 1), while mwcc b210 emits direct return-0/return-1
   moves at the sites. Simple `while (i<count){ if(match) return 0; ... }`
   is best (16); break/goto/while(1)+sentinel structures all explode the
   register count (24/54/53). */
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
/* measured (wave 14 retest — nd 66, no match): fresh reconstruction from the
   m2c draft (u16 return, arg0=s32 counter target, p = D_00881490[0]+8,
   8-saved-reg -0x90 frame — prologue matches retail exactly). The match
   chain `p[0]==arg1 && p[1]==arg2 && func_00107ac0(*(u16*)(p+2))&0xFFFF
   within [*(u16*)(p+4), *(u16*)(p+6)] && !=0xA && func_00107a00(...,3)==0
   && *(u16*)(p+2) != func_00108ee0()&0xFFFF` compiles with a systematic
   saved-reg rotation (my var_16/17/18 in $s3/$s2/$s1 vs retail $s0/$s1/$s2
   — decl-order changes are neutral, nd 66) plus the documented inlined-
   fail-skip vs retail's out-of-line booleanized match chain. func_00107a00
   extern added as (u16, s32); func_00108ee0 as u16(void). Register-pressure
   + Booleanize-layout floor (note's earlier best nd 30 with ret booleanize
   avoided; not reproduced this wave). */
/* measured (wave 14 retest — nd 73 reproduced exactly; no match): draft-based
   reconstruction `while (var_20 < 0x1F) { if (func_001077f0(var_20&0xFFFF)
   && func_00107a00(var_20&0xFFFF,3)==0) { temp_2 = func_001070e0(...); ...
   *0x64 ladder, D_00881480 bounds, +0x12 flags, func_00107ce0 } }` scores
   nd 73 — mwcc b210 CSEs var_20&0xFFFF into a saved register ($s3) at loop
   top and emits move $a0,$s3 per call, retail re-issues andi per site.
   Mixed `(u16)`/`& 0xFFFF` spellings regress to nd 90 (normalised away).
   Mask-CSE floor (same family as FUN_002483C0/FUN_00248B80). */
// FUN_00248240
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00248240);
/* measured (wave 14 retest — nd 119 with a fresh draft-based reconstruction,
   no match): loop of func_001077f0/func_00107ac0==0xA/func_00248a60/
   func_00107a00 guards, the D_00881494 two-u16 table scan into var_20,
   func_001070e0 (real signature s32(s32) — the m2c's 2nd arg is a leftover
   $5 the callee ignores), +0x12 flags and func_00107ce0 — mask-CSE
   dominates (mwcc drills var_21&0xFFFF into a saved register; nd 30+ per the
   earlier note's better spelling). Same family as FUN_00248240/FUN_00248B80.
   func_00248a60 extern added as s32(s32). */
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

/* measured (wave 14 retest — nd 26 -> 20, no match): the merged-NULL
   spelling `if ((A61==0) || (var_17 = temp_17 + func_001064f0(0x6D)*0x24,
   arg0 < func_00110600(var_17[2],var_17[3]))) var_17 = NULL;` now scores
   nd 20; #pragma opt_rebuildconditionals off is neutral (nd 20) and a
   one-case switch wrap regresses to nd 48. Residual: retail puts the shared
   NULL block OUT OF LINE (.L249334) with positive branches (bnez $v0) and a
   main-path `b .L249338`, plus `sltu $v0` (not $at) and a different
   return-block 0/1 ordering; mwcc b210 keeps the NULL body inline with a
   negated skip (beqz $at -> main) and sltu $at. Original note's claim —
   switch wraps don't help — reconfirmed. */
// FUN_002492B0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002492b0);
// FUN_00249370
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249370);
/* measured (wave 14 retest — nd 33 reproducible, no match): merged-OR form
   `if ((A61==0) || (var_16 = temp_16_2 + func_001064f0(0x6D)*0x24,
   arg1 < func_00110600(var_16[2],var_16[3]))) var_16 = NULL;` scores nd 33
   (the `!(arg1<result)` combined form also nd 33-34; opt_rebuildconditionals
   off is neutral). Residual: retail emits `sltu $v0; bnez $v0 -> .L49450`
   (positive branch to the shared out-of-line NULL) while mwcc emits
   `xori $v0,$v0,1; bnez` or inlined negated skips, and all branch targets
   shift by 4; the `if (arg2!=0 && arg2!=1)` assert and final
   `return *(s32*)(var_16+arg2*0x10+0xC)` match after the shift. Out-of-line
   shared-NULL layout floor (same family as FUN_002492B0). */
/* measured (wave 14 retest — nd 71, no match): draft-based reconstruction
   (u32 arg0 seed, s32 arg1; func_001104d0(arg0,&sp5C,&sp58) with the
   leftover-$4 seed; A61!=0 && var_18 = temp_17+func_001064f0(0x6D)*0x24 &&
   !(arg0 < func_00110600(...)) else NULL; arg1 0/1 assert; two u16-flag
   blocks: func_00106600((s16)field4)&0xFF + field6 capped at 0x63 then
   func_00106620(*(s16*)field4, v&0xFF), same for field8/fieldA) — the
   shared-NULL + booleanization layout (xori vs bnez, branch targets shift)
   and saved-reg merge (temp_17+var_18 into one reg) dominate; note's
   earlier nd 94-95 with a different spelling. Out-of-line-if floor family. */
// FUN_002494C0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002494c0);
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

/* measured (wave 14 retest — nd 5 reproducible, no match): the INLINE mask
   spelling (no `s32 m` local — that forces a saved register, nd 38) + the
   cmmMiscAddOff/cmmMiscOr helpers DID fix the documented addu rs/rt and
   or rs/rt residuals (source operand order alone never did). The remaining 5
   words are all the bltz dead-comparison cluster: retail emits
   `andi $v0,$s1,0xffff; bltz $v0; slti $at,$v0,6` (mask FIRST, bltz tests
   the MASKED value, slti result into $at) while mwcc b210 emits
   `bltz $s1; andi $v0; slti $v0,$v0,6` (raw arg0, $v0 dest) — same family as
   FUN_00246E90/FUN_00249960, and the $v0-vs-$at slti is the confirmed b210
   floor (see frFont func_00272170). `(u32)(arg0&0xFFFF)>0x7FFF` halves it to
   nd 17; `(s16)m<0` materializes dsll32/dsra32. Pointer-typed address
   arithmetic keeps lh 0xE($v0). (s16) casts on the func_00113480 args
   reproduce retail's dsll32/dsra32. */
// FUN_00249A60
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249a60);
