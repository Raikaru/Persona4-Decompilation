#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit nLine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct {
    f32 lo;
    f32 hi;
} SP68T;

static inline f32 addF(f32 a, f32 b) { return a + b; }


extern void (*D_00887310[])(s32, void *, s32);
extern void (*D_00887300[])(s32, s32);
extern s32 D_00882FC0[];
extern void (*D_00882FC8[])(void);
extern s32 D_00882FD0[];
extern u8 D_00882FF0[];
extern s16 D_00883988[];
extern s16 D_00884660[];
extern s32 D_00884670[];
extern s16 D_00884674[];
extern f32 D_00884678[];
extern f32 D_0088467C[];
extern s32 D_00884680[];
extern s32 D_00884684[];
extern f32 D_008872F8[];
extern u8 D_00752600[];
extern u8 D_00749AC0[];
extern u8 D_00749B30[];
extern u8 D_00749CC0[];
extern u8 D_00749840[];
extern u8 D_007523C0[];
extern u8 D_007523C4[];
extern u8 D_007523C8[];
extern u8 D_007523CA[];
extern u8 D_007523CC[];
extern u8 D_007523CE[];
extern u8 D_007525D4[];
/* gp - 0x4A5C = 0x00724694, GP-relative s16. */
extern s16 iGpffffb5a4;
/* gp - 0x56B0 = 0x00723A40, GP-relative assert string. */
extern char iGpffffa950;
/* gp - 0x56B8 = 0x00723A38, GP-relative name string. */
extern char iGpffffa948;
/* gp - 0x7F6C = 0x00761184, GP-relative f32. */
extern f32 iGpffff8094;
/* gp - 0x7DE0 = 0x00761310, GP-relative f32. */
extern f32 iGpffff8220;

void func_0034b8d0(void);
void func_0034b950(void);
void func_0034ba20(void);
void func_0034ba30(void);
void func_0034c500(u8 *arg0, s64 arg1, s32 arg2);
void func_0034c6c0(u8 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
void func_0034c820(u8 *arg0);
void func_0034c860(u8 *arg0, s64 arg1, s32 arg2);
void func_0034cef0(u8 *arg0);
s16 func_0034e290(u8 *arg0, s32 arg1);
s16 func_0034e360(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
void func_0034ee90(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2);
void func_0034f0d0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
u32 func_003b7060(void);
void func_00364c50(void);
void func_00364c70(void);
void func_003f6440(s32 arg0, s32 arg1);
u8 *func_00457120(void);
f32 func_0044b7b0(f32 arg0);
f32 func_0044b610(f32 arg0);
s32 func_00451de0();
void func_0046d730(const char *file, s32 line);
void func_0043f9c8(void *dest, s32 value, s32 size);
void func_0034edc0(void);

void func_0034e0b0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2);
void func_0034d040(u8 *arg0);
void func_0034d070(u8 *arg0, s32 arg1);
void func_0034d280(u8 *arg0, s32 arg1);
void func_0034d490(u8 *arg0, s32 arg1);
void func_0034d690(u8 *arg0, s32 arg1);
void func_0034d890(u8 *arg0, s32 arg1);
void func_0034ddf0(u8 *arg0, s32 arg1);
void func_0034db60(u8 *arg0, s32 arg1, f32 fparg0);




// FUN_0034B970
s32 func_0034b970(void) {
    s32 temp_2;

    temp_2 = func_00451de0(&iGpffffa948, 0xC7, 0, 0, func_0034b8d0, 0, 0);
    if (temp_2 == 0) {
        func_0046d730(&iGpffffa950, 0x168);
    }
    func_0043f9c8(D_00882FC0, 0, 0x30);
    D_00882FC8[0] = func_0034b950;
    D_00882FD0[0] = 0;
    func_0034ba20();
    func_0034ba30();
    return temp_2;
}

// FUN_0034BA20
void func_0034ba20(void) {
    iGpffffb5a4 = 0xB0;
}

/* measured: retail colors the D_00882FF0 base $a2 and D_00749B30 base $a0
   (loop dst-temp in $a1); mwcc b210 always colors the second preheader base
   load $a1 and the dst-temp $a0, cascading through every store, nd 25. Tried
   named pointer locals, inline expressions, f32* pointers, s32 base/offset
   locals, m2c goto shape, and src/dst declaration+assignment order swaps —
   best identical nd 25. Re-attacked this wave: hoisting both bases into
   locals before the loop reproduces retail's preheader exactly (lui/addiu
   $a2 dst, $a0 src, move $a3 counter) and the store body matches byte-
   for-byte; the ONLY residual is a clean $a0/$a1 swap between the src base
   and the dst-temp (retail src=$a0/dst-temp=$a1, mwcc src=$a1/dst-temp=$a0)
   across all 19 stores, nd 25. Lever 1 (signature) N/A: void, no args, no
   externs. Register-coloring floor. */
/* measured: nd 64 against retail's 224-byte window (object 212, retail's real
   body is the same 212 with three trailing nops). Every instruction is right -
   an earlier probe measured zero differing WORDS - and the residual is register
   colouring across the nineteen stores plus the order in which the two table
   base addresses are materialised: retail loads the destination base first.
   Declaring and assigning the destination pointer ahead of the source does not
   move it. Committed at nd 64. */
// Archived C body: build/WBHygiene_func_0034ba30_archive.txt; no current park body remains.
// FUN_0034BA30
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034ba30);

// FUN_0034BB10
s32 func_0034bb10(void) {
    return D_00884670[0];
}

// FUN_0034BB20
s32 func_0034bb20(s32 arg0) {
    s32 i;
    s32 temp_16;
    u8 *srcBase;
    u8 *dstBase;
    f32 temp_f2;
    f32 temp_f0;
    f32 temp_f1;
    u8 *dst;
    u8 *src;

    if (D_00884670[0] != arg0) {
        if (arg0 == 0) {
            D_00884670[0] = arg0;
            D_00884674[0] = 0;
            D_00884678[0] = *(f32 *)(D_007523C4 + arg0 * 0x10);
            D_00884680[0] = 0;
            return 1;
        }
        if ((arg0 >= 0) && (arg0 < 0x24)) {
            i = 0;
            temp_16 = arg0 * 0x10;
            srcBase = D_00749CC0 + arg0 * 0x3C0;
            temp_f2 = *(f32 *)(D_007523C0 + temp_16 + 4);
            dstBase = D_00882FF0;
            for (; i < 0x14; i++) {
                dst = dstBase + i * 0x54;
                src = srcBase + i * 0x30;
                *(f32 *)(dst + 0) = *(f32 *)(src + 8);
                *(f32 *)(dst + 4) = *(f32 *)(src + 0xC);
                temp_f0 = *(f32 *)(src + 0);
                *(f32 *)(dst + 0x18) = temp_f0;
                *(f32 *)(dst + 8) = temp_f0;
                temp_f0 = *(f32 *)(src + 4);
                *(f32 *)(dst + 0x1C) = temp_f0;
                *(f32 *)(dst + 0xC) = temp_f0;
                *(f32 *)(dst + 0x10) = *(f32 *)(dst + 0) - *(f32 *)(dst + 0x18);
                *(f32 *)(dst + 0x14) = *(f32 *)(dst + 4) - *(f32 *)(dst + 0x1C);
                *(f32 *)(dst + 0x3C) = *(f32 *)(src + 0x10);
                temp_f1 = *(f32 *)(src + 0x14);
                *(f32 *)(dst + 0x40) = temp_f1;
                *(f32 *)(dst + 0x38) = temp_f1 - *(f32 *)(dst + 0x3C);
                *(f32 *)(dst + 0x30) = *(f32 *)(src + 0x18);
                *(s32 *)(dst + 0x44) = 0;
                *(s16 *)(dst + 0x48) = *(s16 *)(src + 0x1C);
                *(f32 *)(dst + 0x20) = *(f32 *)(src + 0x24);
                temp_f0 = *(f32 *)(src + 0x20);
                *(f32 *)(dst + 0x24) = temp_f0;
                *(f32 *)(dst + 0x2C) = temp_f0;
                *(f32 *)(dst + 0x28) = *(f32 *)(dst + 0x20) - *(f32 *)(dst + 0x2C);
                *(f32 *)(dst + 0x4C) = temp_f2 * *(f32 *)(src + 0x28);
                *(f32 *)(dst + 0x50) = temp_f2 * *(f32 *)(src + 0x2C);
            }
            D_00884660[0] = 0;
            D_00883988[0] = func_0034e290(D_00882FF0, arg0);
            D_00884670[0] = arg0;
            D_00884674[0] = 0;
            D_00884678[0] = *(f32 *)(D_007523C4 + temp_16);
            D_00884680[0] = 0;
            return 1;
        }
        func_0046d730(&iGpffffa950, 0x1F2);
    }
    return 0;
}

// FUN_0034BD60
/* measured: without opt_loop_invariants, mwcc rematerializes the 5.0f constant
 * inside the loop ($v0) instead of hoisting it to the preheader like retail
 * (lui $v1 used by both stores), nd 48 -> 0. */
#pragma opt_loop_invariants on
s32 func_0034bd60(s32 arg0) {
    s32 i;
    u8 *srcBase;
    u8 *dstBase;
    u8 *dst;
    u8 *src;
    u32 five;

    if ((D_00884670[0] != arg0) && (arg0 >= 0) && (arg0 < 0x24)) {
        i = 0;
        srcBase = D_00749CC0 + arg0 * 0x3C0;
        dstBase = D_00882FF0;
        five = 0x40A00000;
        for (; i < 0x14; i++) {
            f32 v;
            dst = dstBase + i * 0x54;
            src = srcBase + i * 0x30;

            v = *(f32 *)(src + 8);
            *(f32 *)(dst + 0) = v;
            *(f32 *)(dst + 8) = v;
            *(f32 *)(dst + 0x18) = v;
            v = *(f32 *)(src + 0xC);
            *(f32 *)(dst + 4) = v;
            *(f32 *)(dst + 0xC) = v;
            *(f32 *)(dst + 0x1C) = v;
            *(s32 *)(dst + 0x10) = 0;
            *(s32 *)(dst + 0x14) = 0;
            *(s32 *)(dst + 0x38) = 0;
            v = *(f32 *)(src + 0x18);
            *(f32 *)(dst + 0x30) = v;
            *(f32 *)(dst + 0x40) = v;
            *(f32 *)(dst + 0x3C) = v;
            *(f32 *)(dst + 0x34) = v;
            *(s16 *)(dst + 0x48) = *(s16 *)(src + 0x1C);
            *(s32 *)(dst + 0x24) = 0;
            *(s32 *)(dst + 0x2C) = 0;
            *(f32 *)(dst + 0x20) = *(f32 *)(src + 0x24);
            *(f32 *)(dst + 0x28) = *(f32 *)(src + 0x24) - *(f32 *)(dst + 0x24);
            *(s32 *)(dst + 0x4C) = 0;
            *(u32 *)(dst + 0x50) = five;
        }
        D_00884660[0] = 0;
        D_00884670[0] = arg0;
        D_00884674[0] = 0;
        *(u32 *)&D_00884678[0] = five;
        D_00884680[0] = 1;
        return 1;
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_0034bd60). */
#pragma opt_loop_invariants off

/* measured: reconstructed retail control flow and arithmetic; residual is the preheader move/andi order plus one trailing nop, best normalized_diff 8. Committed at nd 8. */
// FUN_0034BEA0 NONMATCHING
#ifdef NON_MATCHING
/* Only needed when this body is the arm that compiles: it calls
   func_0034c120 above that function's definition, and without this the
   implicit `int (...)` declaration collides with the real one. */
void func_0034c120(u8 *arg0);
void func_0034bea0(void) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f2;
    s32 temp_16;
    s32 temp_4;
    s32 var_18;
    u8 *temp_17;

    if ((D_00884684[0] == 0) || (D_00884670[0] == 0)) {
        func_0046d730(&iGpffffa950, 0x235);
    }
    if ((f32)D_00884674[0] < D_00884678[0]) {
        D_00884674[0] += 1;
    }
    temp_16 = D_007523C0[D_00884670[0] * 0x10] & 1;
    var_18 = 0;
    for (; var_18 < 0x14; var_18++) {
        temp_4 = var_18 * 0x54;
        temp_17 = D_00882FF0 + temp_4;
        temp_f2 = *(f32 *)(temp_17 + 0x4C);
        temp_f1 = (f32)D_00884674[0];
        if (temp_f1 < temp_f2) {
            temp_f20 = 0.0f;
            temp_f0 = temp_f20;
        } else if (temp_f1 < *(f32 *)(temp_17 + 0x50)) {
            temp_f1 = temp_f1 - temp_f2;
            temp_f0 = *(f32 *)(temp_17 + 0x50) - temp_f2;
            temp_f21 = temp_f1 / temp_f0;
            temp_f22 = iGpffff8094 * temp_f21;
            temp_f20 = func_0044b7b0(temp_f22);
            if (temp_f21 < 0.5f) {
                temp_f0 = func_0044b7b0(2.0f * temp_f22);
            } else {
                if (*(s32 *)(temp_17 + 0x44) == 0) {
                    *(f32 *)(temp_17 + 0x3C) = *(f32 *)(temp_17 + 0x40);
                    *(f32 *)(temp_17 + 0x38) = *(f32 *)(temp_17 + 0x30) - *(f32 *)(temp_17 + 0x40);
                    *(s32 *)(temp_17 + 0x44) = 1;
                }
                temp_f0 = func_0044b7b0(2.0f * temp_f22 - iGpffff8094);
            }
        } else {
            temp_f20 = 1.0f;
            temp_f0 = temp_f20;
        }
        *(f32 *)(temp_17 + 8) = *(f32 *)(temp_17 + 0x18) + *(f32 *)(temp_17 + 0x10) * temp_f20;
        *(f32 *)(temp_17 + 0xC) = *(f32 *)(temp_17 + 0x1C) + *(f32 *)(temp_17 + 0x14) * temp_f20;
        *(f32 *)(temp_17 + 0x24) = *(f32 *)(temp_17 + 0x2C) + *(f32 *)(temp_17 + 0x28) * temp_f20;
        *(f32 *)(temp_17 + 0x34) = *(f32 *)(temp_17 + 0x3C) + *(f32 *)(temp_17 + 0x38) * temp_f0;
        if (temp_16 != 0) {
            func_0034c120(temp_17);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034bea0);
#endif
// FUN_0034C120
void func_0034c120(u8 *arg0) {
    f32 temp_f2 = *(f32 *)(arg0 + 8);

    if (temp_f2 < 0.0f) {
        *(f32 *)(arg0 + 0) += 640.0f;
        *(f32 *)(arg0 + 0x18) += 640.0f;
    } else if (!(temp_f2 < 640.0f)) {
        *(f32 *)(arg0 + 0) -= 640.0f;
        *(f32 *)(arg0 + 0x18) -= 640.0f;
    }
    temp_f2 = *(f32 *)(arg0 + 0xC);
    if (temp_f2 < 0.0f) {
        *(f32 *)(arg0 + 4) += 448.0f;
        *(f32 *)(arg0 + 0x1C) += 448.0f;
        return;
    }
    if (!(temp_f2 < 448.0f)) {
        *(f32 *)(arg0 + 4) -= 448.0f;
        *(f32 *)(arg0 + 0x1C) -= 448.0f;
    }
}




// FUN_0034C210
s32 func_0034c210(void) {
    if ((D_00884670[0] == 0) || !((f32)D_00884674[0] < D_00884678[0])) {
        return 1;
    }
    return 0;
}

// FUN_0034C260
void func_0034c260(s32 arg0) {
    D_00884684[0] = arg0;
}

/* measured (wave 14 re-attack, best nd 11 vs recorded 69): the true signature is
   (s64 arg0, u32 arg1, s32 arg2, f32 fparg0) — NOT the old (u8*, s64, s32).
   The s64 arg0 is spilled to 0x48 and its two words read as f32 in the loop
   (baseLo/baseHi). With #pragma opt_loop_invariants on + the u32-copy half-
   scaler recipe `c = (u32)var_3; var_f0 = (f32)(s32)((c>>1)|(c&1)); var_f0+=var_f0`
   (logical srl, kills the else-branch clone) + x+x doubling (no 2.0f const),
   every instruction matches except 4 fixed residuals: (1) baseLo/baseHi FP
   register coloring is deterministically swapped (retail baseLo=$f5/baseHi=$f6,
   mwcc baseLo=$f6/baseHi=$f5 regardless of assignment order), (2) the clamp
   comparison — `temp_f0 < 2.1474836e9f` gives retail's layout but encodes
   c.olt.s $f0,$f1+bc1f vs retail c.ole.s $f1,$f0+bc1t, and the c.ole.s form
   only compiles with the inverted (wrong) layout (documented floor), (3) the
   or-fold `(c>>1)|(c&1)` colors into $v1 vs retail $a0 (operand order), (4)
   the base float load order (retail loads baseHi first). opt_propagation off
   wrecked it (nd 97). Lever 1 (u32 arg1) + u32-copy recipe + x+x were the
   big wins. FP-coloring + clamp-comparison floor. */
// FUN_0034C270
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c270);
// FUN_0034C4A0
void func_0034c4a0(void) {
    s64 sp18;
    u8 *p = (u8 *)&sp18;
    s32 n = 8;

    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    func_0034c500(D_00882FF0, sp18, 0xFF);
}

/* measured: three compounding mwcc b210 defects vs retail, nd 105. (1) The
   s64 arg1 is kept in $s1 across the edc0 call instead of spilled to 0x38
   (retail sd/ld $5, 0x38), pushing arg0 to $s2 and cascading through every
   address — tried passing arg1 directly, s64 local, and 1-element s64 array,
   all identical. (2) cvt.w.s if/else: only `temp_f1 < 2.1474836e9f` gives
   retail's layout (cvt inline, sub out of line, shared sb join) but mwcc then
   encodes c.olt.s $f1,$f0 + bc1f where retail has c.ole.s $f0,$f1 + bc1t; the
   c.ole.s form only compiles with the inverted (wrong) layout. (3) byte-clamp
   values land in $a0/$v1/$v0 vs retail's $a1/$v1/$v0. */
// FUN_0034C500
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c500);

/* measured (wave 14): the f0d0 extern is floats-first — the true signature is
   (u8*, f32, f32, f32, f32, u8, u8, u8, u8), NOT (u8*, s32, s32, s32, s32,
   f32, f32, f32, f32). With the corrected extern AND the C callsite written
   floats-first (ptr, f0, f1, f2, f3, b0, b1, b2, b3), all four callsites now
   match retail byte-for-byte (move $a0, mov.s $f12-$f15, then lbu $5-$8) —
   nd 17 -> 6. The ONLY residual (5 words) is the prologue save order: retail
   saves the 4 float params to $f26/$f25/$f24/$f20 THEN moves arg1 to $s0;
   mwcc b210 always moves arg1 to $s0 first, then the float saves. Tried
   named float locals, opt_propagation off (identical), decl orders — the
   int-arg-first prologue save is a fixed b210 scheduling floor. Lever 1
   (extern width/class) was the big win here. */
/* measured: nd 13 against a 352-byte window. The body is right; the residual is
   the prologue, where retail performs the float moves before saving the second
   argument into $s0 and b210 does the save first. Capturing the argument into a
   local first does not reorder it. Committed at nd 13. */
// FUN_0034C6C0 NONMATCHING
#ifdef NON_MATCHING
void func_0034c6c0(u8 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 z;
    f32 scale;

    z = D_008872F8[0] - D_0088467C[0];
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    func_0034f0d0(arg0, fparg0, fparg1, z, scale, arg1[0], arg1[1], arg1[2], arg1[3]);
    func_0034f0d0(arg0 + 0x40, fparg0, fparg1 + fparg3, z, scale, arg1[0], arg1[1], arg1[2], arg1[3]);
    func_0034f0d0(arg0 + 0x80, fparg0 + fparg2, fparg1 + fparg3, z, scale, arg1[0], arg1[1], arg1[2], arg1[3]);
    func_0034f0d0(arg0 + 0xC0, fparg0 + fparg2, fparg1, z, scale, arg1[0], arg1[1], arg1[2], arg1[3]);
}
#else
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c6c0);
#endif


// FUN_0034C820
void func_0034c820(u8 *arg0) {
    D_00887310[0](5, arg0, 4);
}




// FUN_0034C860
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c860);
/* measured: re-tested 4 spellings, best nd 329 (was 352). The jtbl switch
   (17 cases) and the second switch's descending beq-chain (4,3,2,1,0 via
   ascending case labels, empty cases 0/4, dsll32/dsra32 sign-extend) both
   match retail structurally. Remaining b210 floors: (1) load-sinking — the
   sp68-lo word `*((f32 *)&sp68 + 1)` gets its ADDRESS CSE'd across the 3
   case bodies and hoisted into a saved $s0 (addiu $s0,$sp,0x7C + lwc1
   ($s0) per body) instead of retail's plain lwc1 0x6C($sp) in each body —
   that extra GPR cascades arg0 to $s3 and pushes the frame to 0x80 vs 0x70
   (4 GPR + 6 FP vs 3+5); tried hoisted lo local before/after the switch,
   byte-cast and mixed spellings — identical. (2) `lo + 448.0f` in calls
   2+3 is CSE'd into a 6th saved FP where retail re-issues lui/mtc1/add.s.
   (3) saved-FP rotation: retail allocates y/lo/delta/inv to $f20/$f23/
   $f22/$f21 in case 1, mwcc permutes ($f20/$f24/$f23/$f22 + $f21 for the
   448 sum). (4) int-args-before-float-moves call materialization. */
// FUN_0034CEF0
void func_0034cef0(u8 *arg0) {
    void (**f)(s32, void *, s32);

    D_00887300[0](1, 0);
    if (*(s16 *)(arg0 + 0xFE0) > 0) {
        func_00364c50();
        if ((u32)*(s16 *)(arg0 + 0xFE0) <= 0x33U) {
            /* no-op */
        } else {
            func_0046d730(&iGpffffa950, 0x3EF);
        }
        D_00887310[0](3, arg0 + 0x320, *(s16 *)(arg0 + 0xFE0));
        func_00364c70();
    }
    f = (void (**)(s32, void *, s32))(u32)D_00887310;
    f[0](5, arg0, 4);
    if (*(s32 *)(arg0 + 0x300) != 0) {
        func_003f6440(3, 0x71801);
        func_003f6440(2, 0x48);
        f[0](5, arg0 + 0x100, 3);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
    if (*(s16 *)(arg0 + 0x306) != 0) {
        f[0](5, arg0 + 0x200, 4);
    }
}
// FUN_0034D040
void func_0034d040(u8 *arg0) {
    func_0034e0b0(arg0, 0.0f, 0.0f, 1.0f);
}

/* measured: three separate loop-index locals plus the exact `lh` table access
   reproduce retail's shared $a2 counter coloring; d070 is nd 0
   (object 528B / window 528B). */
// FUN_0034D070
/* measured: opens d070's exact loop-invariant scope. */
#pragma opt_loop_invariants on
void func_0034d070(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f14;
    f32 var_f4;
    s32 var_6_1;
    s32 var_6_2;
    s32 var_6_3;

    if (arg1 != 0) {
        var_f4 = 640.0f;
        var_6_1 = 0;
        for (; var_6_1 < 0x14; var_6_1++) {
            temp_f0 = *(f32 *)(arg0 + var_6_1 * 0x54 + 8);
            if (temp_f0 < var_f4) {
                var_f4 = temp_f0;
            }
        }
    } else if (*(s16 *)(D_007523C8 + (*(s32 *)(arg0 + 0x1680) * 0x10)) == 1) {
        var_f4 = -640.0f;
        var_6_2 = 0;
        for (; var_6_2 < 0x14; var_6_2++) {
            temp_f0_2 = *(f32 *)(arg0 + var_6_2 * 0x54 + 8);
            if (!(temp_f0_2 <= var_f4)) {
                var_f4 = temp_f0_2;
            }
        }
    } else {
        var_f4 = -640.0f;
        var_6_3 = 0;
        for (; var_6_3 < 0x14; var_6_3++) {
            temp_f0_3 = *(f32 *)(arg0 + var_6_3 * 0x54 + 8) - 640.0f;
            if (!(temp_f0_3 <= var_f4)) {
                var_f4 = temp_f0_3;
            }
        }
    }
    temp_f3 = *(f32 *)(arg0 + 0x1688) / 4.0f;
    if (*(s32 *)(arg0 + 0x1690) == 0) {
        temp_f2 = (f32)*(s16 *)(arg0 + 0x1684);
        if (temp_f2 < temp_f3) {
            var_f14 = (temp_f2 - temp_f3) / (*(f32 *)(D_007523C4 + (*(s32 *)(arg0 + 0x1680) * 0x10)) - temp_f3);
        } else {
            var_f14 = 1.0f;
        }
    } else {
        var_f14 = 1.0f;
    }
    if (arg1 == 0) {
        var_f14 = 1.0f - var_f14;
    }
    func_0034e0b0(arg0, var_f4 - *(f32 *)(arg0 + 0x99C), -*(f32 *)(arg0 + 0x9A0), var_f14);
}
/* measured: closes the tested d070 loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off
// FUN_0034D280
/* measured: opens d280's exact loop-invariant scope. */
#pragma opt_loop_invariants on
void func_0034d280(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f14;
    f32 var_f4;
    s32 var_6_1;
    s32 var_6_2;
    s32 var_6_3;

    if (arg1 != 0) {
        if (*(s16 *)(D_007523C8 + (*(s32 *)(arg0 + 0x1680) * 0x10)) == 1) {
            var_f4 = -640.0f;
            var_6_1 = 0;
            for (; var_6_1 < 0x14; var_6_1++) {
                temp_f0 = *(f32 *)(arg0 + var_6_1 * 0x54 + 8);
                if (!(temp_f0 <= var_f4)) {
                    var_f4 = temp_f0;
                }
            }
        } else {
            var_f4 = -640.0f;
            var_6_2 = 0;
            for (; var_6_2 < 0x14; var_6_2++) {
                temp_f0_2 = *(f32 *)(arg0 + var_6_2 * 0x54 + 8) - 640.0f;
                if (!(temp_f0_2 <= var_f4)) {
                    var_f4 = temp_f0_2;
                }
            }
        }
    } else {
        var_f4 = 640.0f;
        var_6_3 = 0;
        for (; var_6_3 < 0x14; var_6_3++) {
            temp_f0_3 = *(f32 *)(arg0 + var_6_3 * 0x54 + 8);
            if (temp_f0_3 < var_f4) {
                var_f4 = temp_f0_3;
            }
        }
    }
    temp_f3 = *(f32 *)(arg0 + 0x1688) / 4.0f;
    if (*(s32 *)(arg0 + 0x1690) == 0) {
        temp_f2 = (f32)*(s16 *)(arg0 + 0x1684);
        if (temp_f2 < temp_f3) {
            var_f14 = (temp_f2 - temp_f3) / (*(f32 *)(D_007523C4 + (*(s32 *)(arg0 + 0x1680) * 0x10)) - temp_f3);
        } else {
            var_f14 = 1.0f;
        }
    } else {
        var_f14 = 1.0f;
    }
    if (arg1 == 0) {
        var_f14 = 1.0f - var_f14;
    }
    func_0034e0b0(arg0, var_f4 - *(f32 *)(arg0 + 0x99C), -*(f32 *)(arg0 + 0x9A0), var_f14);
}
/* measured: closes the tested d280 loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off

/* measured: three separate loop-index locals plus the exact `lh` table access
   reproduce retail's shared $a2 counter coloring; d280 is nd 0
   (object 528B / window 528B). */
// FUN_0034D490
/* measured: opt_loop_invariants hoists the shared 448.0f/4.0f constants for
   this exact loop-index spelling. */
#pragma opt_loop_invariants on
void func_0034d490(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 var_f14;
    f32 var_f2;
    s32 var_6_1;
    s32 var_6_2;
    s32 var_6_3;

    if (arg1 != 0) {
        var_f2 = 448.0f;
        var_6_1 = 0;
        for (; var_6_1 < 0x14; var_6_1++) {
            temp_f0 = *(f32 *)(arg0 + var_6_1 * 0x54 + 0xC);
            if (temp_f0 < var_f2) {
                var_f2 = temp_f0;
            }
        }
    } else if (*(s16 *)(D_007523C8 + (*(s32 *)(arg0 + 0x1680) * 0x10)) == 1) {
        var_f2 = -448.0f;
        var_6_2 = 0;
        for (; var_6_2 < 0x14; var_6_2++) {
            temp_f0_2 = *(f32 *)(arg0 + var_6_2 * 0x54 + 0xC) - 448.0f;
            if (!(temp_f0_2 <= var_f2)) {
                var_f2 = temp_f0_2;
            }
        }
    } else {
        var_f2 = -448.0f;
        var_6_3 = 0;
        for (; var_6_3 < 0x14; var_6_3++) {
            temp_f0_3 = *(f32 *)(arg0 + var_6_3 * 0x54 + 0xC);
            if (!(temp_f0_3 <= var_f2)) {
                var_f2 = temp_f0_3;
            }
        }
    }
    temp_f1 = *(f32 *)(arg0 + 0x1688) / 4.0f;
    if (*(s32 *)(arg0 + 0x1690) == 0) {
        temp_f0_4 = (f32)*(s16 *)(arg0 + 0x1684);
        if (temp_f0_4 < temp_f1) {
            var_f14 = (temp_f1 - temp_f0_4) / temp_f1;
        } else {
            var_f14 = 1.0f;
        }
    } else {
        var_f14 = 1.0f;
    }
    if (arg1 == 0) {
        var_f14 = 1.0f - var_f14;
    }
    func_0034e0b0(arg0, -*(f32 *)(arg0 + 0x99C), var_f2 - *(f32 *)(arg0 + 0x9A0), var_f14);
}
/* measured: closes the tested loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off
/* measured: separate loop-index locals for d690's three independent extrema
   scans reproduce retail's reused $a2 coloring; `lh` table access and
   opt_loop_invariants give nd 0 (object 504B / window 512B). */
// FUN_0034D690
/* measured: opens the exact d690 loop-invariant scope. */
#pragma opt_loop_invariants on
void func_0034d690(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 var_f14;
    f32 var_f2;
    s32 var_6_1;
    s32 var_6_2;
    s32 var_6_3;

    if (arg1 != 0) {
        if (*(s16 *)(D_007523C8 + (*(s32 *)(arg0 + 0x1680) * 0x10)) == 1) {
            var_f2 = -448.0f;
            var_6_1 = 0;
            for (; var_6_1 < 0x14; var_6_1++) {
                temp_f0 = *(f32 *)(arg0 + var_6_1 * 0x54 + 0xC) - 448.0f;
                if (!(temp_f0 <= var_f2)) {
                    var_f2 = temp_f0;
                }
            }
        } else {
            var_f2 = -448.0f;
            var_6_2 = 0;
            for (; var_6_2 < 0x14; var_6_2++) {
                temp_f0_2 = *(f32 *)(arg0 + var_6_2 * 0x54 + 0xC);
                if (!(temp_f0_2 <= var_f2)) {
                    var_f2 = temp_f0_2;
                }
            }
        }
    } else {
        var_f2 = 448.0f;
        var_6_3 = 0;
        for (; var_6_3 < 0x14; var_6_3++) {
            temp_f0_3 = *(f32 *)(arg0 + var_6_3 * 0x54 + 0xC);
            if (temp_f0_3 < var_f2) {
                var_f2 = temp_f0_3;
            }
        }
    }
    temp_f1 = *(f32 *)(arg0 + 0x1688) / 4.0f;
    if (*(s32 *)(arg0 + 0x1690) == 0) {
        temp_f0_4 = (f32)*(s16 *)(arg0 + 0x1684);
        if (temp_f0_4 < temp_f1) {
            var_f14 = (temp_f1 - temp_f0_4) / temp_f1;
        } else {
            var_f14 = 1.0f;
        }
    } else {
        var_f14 = 1.0f;
    }
    if (arg1 == 0) {
        var_f14 = 1.0f - var_f14;
    }
    func_0034e0b0(arg0, -*(f32 *)(arg0 + 0x99C), var_f2 - *(f32 *)(arg0 + 0x9A0), var_f14);
}
/* measured: closes the tested d690 loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off

// FUN_0034D890
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d890);
/* measured: re-tested with recipe A (3 attempts, best nd 161). 4th attempt
   (plain-C byte chain + unfused FMA) was worse (nd 179, obj 796B > 720B
   window). The 0x994 byte chain and adda.s/msub.s FMA (247.0f - 82.0f*var_f0)
   match retail instruction-for-instruction (lbu + single bltz + srl/andi/or
   + cvt + add.s doubling). Remaining b210 floors: (1) the clamp comparison —
   only `prod < 2.1474836e9f` gives retail's layout (cvt inline, sub out of
   line) but mwcc encodes c.olt.s prod,const + bc1f where retail has
   c.ole.s const,prod + bc1t (same family as c500/ddf0). (2) `y + 448.0f`
   repeated in calls 2+3 is CSE'd into a saved $f22 (6 saved FP vs retail's
   5, $f22 hole shifts x/delta/inv to $f23/$f24/$f25); retail re-issues
   lui/mtc1/add.s per call; operand reversal does not break mwcc's CSE.
   (3) saved-FP rotation: retail allocates by declaration order (0x9A0 ->
   $f20, 164.0f*var_f0 -> $f21, 1/x -> $f22, delta -> $f23, x -> $f24),
   mwcc by first-use (164*var_f0 -> $f20, 0x9A0 -> $f21). (4) int-args-before-
   float-moves call materialization. Register-coloring + CSE + comparison-
   shape floor. Re-attacked wave 14 with the corrected floats-first f0d0
   extern (u8*,f32,f32,f32,f32,u8,u8,u8,u8) + full reconstruction — nd 41
   (all remaining words are the saved-FP rotation + call-arg FP pairing). */

// FUN_0034DB60
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034db60);
// FUN_0034DDF0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034ddf0);
/* measured: nd 87 from 101. Logic is complete and every constant is confirmed
   (480.0f, 640.0f, 448.0f; the four quad corners are 0x690/0x6D0/0x710/0x750).

   The one real win: `#pragma opt_common_subs off` (101 -> 87). Without it b210
   caches `y + 480.0f` -- shared by calls 2 and 3 -- in an EIGHTH float saved
   register, so the prologue pushes $f20..$f27 where retail pushes $f20..$f26 and
   every subsequent word is offset by one. Retail recomputes the corner offsets
   per call, including re-materializing the constant.

   What remains is three small residuals repeated across the four calls: `x` and
   `z` are transposed ($f20 vs $f22), arg0 and the alpha byte are transposed
   ($s0 vs $s1), and the commutative `add.s` operands come out reversed
   ($f0 + $f21 rather than $f21 + $f0).

   Measured and rejected: four declaration permutations of {scale, x, y, z,
   alpha} (all 91, worse), computing z first (94), computing x first (90), and
   alpha declared last (101). The callee signatures are already confirmed
   correct -- func_0034f0d0 is (u8*, f32x4, u8x4), func_0034e360 returns s16.
   Float-register colouring floor. */
// Archived C body: build/WBHygiene_func_0034e0b0_archive.txt; no current park body remains.
// FUN_0034E0B0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034e0b0);

// FUN_0034E290
s16 func_0034e290(u8 *arg0, s32 arg1) {
    s16 val;
    s32 r;
    s32 t;

    val = *(s16 *)(D_007523CE + arg1 * 0x10);
    switch (val) {
    case 1:
    case 2:
    case 3:
    case 4:
        r = func_003b7060() & 0xFFF;
        t = *(s16 *)(D_007525D4 + val * 0x2C) + 1;
        *(s16 *)(arg0 + 0x99A) = (s16)((u32)(t * r) >> 12);
        return val;
    }
    return val;
}

/* measured: four attempts, best nd 592. With the corrected f0d0 prototype the
   whole body compiles structurally correct (loop bodies, mult/div alpha
   chains, sq/lq s128 sp110/sp100 at 0x110/0x100, spFC..spD4 slots, switch
   dispatch 5,4,3,2,1 all match instruction-for-instruction) but mwcc b210
   permutes the saved-GPR and saved-FP allocation: temp_16 lands $s2 and
   temp_18 $s0 (retail $s0/$s2), the four float params rotate to
   $f25/$f24/$f21/$f20 (retail $f21/$f20/$f23/$f22), f27/f26 to $f30/$f31,
   and the coalescing cascade spills arg0 to 0x13C (frame 0x140 vs retail
   0x120) instead of $s7 — tried m2c declaration order, temp_16 first, GPR
   reorders, and all four params copied to named locals; identical nd 592.
   Saved-register-rotation floor (same family as func_0034e0b0). Re-attacked
   wave 14: the f0d0 extern is confirmed floats-first (u8*,f32,f32,f32,f32,u8,
   u8,u8,u8) from f0d0's own prologue — but e360 is a saved-register/FP rotation
   floor (mwcc permutes the trivial saved-GPR/FP allocation), not a signature
   issue; the 20+ f0d0 callsites are byte-correct with the floats-first extern. */
// FUN_0034E360
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034e360);
