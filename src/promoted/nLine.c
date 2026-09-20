#include "include_asm.h"
#include "sdk_task_registration.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit nLine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

/* measured: inline arithmetic boundaries keep c860's height additions
   separate and its remaining-width calculation before the callbacks. */
static inline f32 addF(f32 a, f32 b) { return a + b; }
static inline f32 subF(f32 a, f32 b) { return a - b; }
static inline f32 mulF(f32 a, f32 b) { return a * b; }


extern s32 (*D_00887310[])(s32, void *, s32);
extern void (*D_00887300[])(s32, s32);
extern s32 D_00882FC0[];
extern void (*D_00882FC8[])(void);
extern s32 D_00882FD0[];
extern u8 D_00882FF0[];
extern s16 D_00883988[];
extern s16 D_00884660[];
extern f32 D_0088466C[];
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
/* gp - 0x4A5C = 0x00764694, GP-relative s16. */
extern s16 iGpffffb5a4;
/* gp - 0x56B0 = 0x00763A40, GP-relative assert string. */
extern char iGpffffa950;
/* gp - 0x56B8 = 0x00763A38, GP-relative name string. */
extern char iGpffffa948;
/* gp - 0x7F6C = 0x00761184, GP-relative f32. */
extern f32 iGpffff8094;
extern f32 fGpffff84a4;
/* gp - 0x7DE0 = 0x00761310, GP-relative f32. */
extern f32 iGpffff8220;

s32 func_0034b8d0(u8 *task);
void func_0034b950(void);
void func_0034ba20(void);
void func_0034ba30(void);
void func_0034c500(u8 *arg0, Vec2f arg1, s32 arg2);
void func_0034c6c0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, u8 *arg1);
void func_0034c820(u8 *arg0);
void func_0034c860(u8 *arg0, Vec2f arg1, s32 arg2);
void func_0034cef0(u8 *arg0);
s16 func_0034e290(u8 *arg0, s32 arg1);
s32 func_0034e360(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
void func_0034ee90(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2);
void func_0034f0d0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
u32 func_003b7060(void);
void func_00364c50(void);
void func_00364c70(void);
void func_003f6440(s32 arg0, s32 arg1);
u8 *func_00457120(void);
f32 func_0044b7b0(f32 arg0);
f32 func_0044b610(f32 arg0);

void func_0046d730(void *file, s32 line);
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
void func_0034db60(u8 *arg0, f32 fparg0, s32 arg1);




// FUN_0034B970
s32 func_0034b970(void) {
    s32 temp_2;

    temp_2 = (s32)func_00451de0((const void *)(&iGpffffa948), 0xC7, 0, 0, func_0034b8d0, 0, (u8 *)(0));
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

/* Initialize 20 records from the compact defaults table, preserving untouched
   fields. Row pointers formed inside the loop plus invariant hoisting give
   retail's destination-first address schedule and register allocation.
   measured: object 212B/window 224B; exact instructions, 12B zero tail. */
#pragma opt_loop_invariants on
// FUN_0034BA30
void func_0034ba30(void) {
    u8 *dst;
    u8 *src;
    s32 i;
    f32 t0;
    f32 t1;
    f32 t2;
    f32 t3;

    D_00884670[0] = 0;
    D_00884674[0] = 0;
    D_00884678[0] = 0;
    D_00884680[0] = 0;
    D_00884684[0] = 0;
    for (i = 0; i < 20; i++) {
        dst = D_00882FF0 + i * 84;
        src = D_00749B30 + i * 20;
        t0 = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x18) = t0;
        *(f32 *)(dst + 0x08) = t0;
        *(f32 *)(dst + 0x00) = t0;
        t1 = *(f32 *)(src + 4);
        *(f32 *)(dst + 0x1C) = t1;
        *(f32 *)(dst + 0x0C) = t1;
        *(f32 *)(dst + 0x04) = t1;
        t2 = *(f32 *)(src + 0xC);
        *(f32 *)(dst + 0x2C) = t2;
        *(f32 *)(dst + 0x24) = t2;
        *(f32 *)(dst + 0x20) = t2;
        t3 = *(f32 *)(src + 0x10);
        *(f32 *)(dst + 0x34) = t3;
        *(f32 *)(dst + 0x30) = t3;
        *(s16 *)(dst + 0x48) = *(s16 *)(src + 8);
        *(s32 *)(dst + 0x4C) = 0;
        *(s32 *)(dst + 0x10) = 0;
        *(s32 *)(dst + 0x14) = 0;
    }
}
/* measured: close the exact ba30 loop-invariant scope at the TU baseline. */
#pragma opt_loop_invariants off

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

/* measured: opt_propagation off with the mode byte loaded into a u8 local before the
   counter init and masked after it (`flags = ...; var_18 = 0; temp_16 = flags & 1;`)
   gives retail's lbu / move s2,zero / andi preheader; propagation on sinks the load. */
// FUN_0034BEA0
#pragma opt_propagation off
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
    u8 flags;

    if ((D_00884684[0] == 0) || (D_00884670[0] == 0)) {
        func_0046d730(&iGpffffa950, 0x235);
    }
    if ((f32)D_00884674[0] < D_00884678[0]) {
        D_00884674[0] += 1;
    }
    flags = D_007523C0[D_00884670[0] * 0x10];
    var_18 = 0;
    temp_16 = flags & 1;
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
            temp_f22 = fGpffff84a4 * temp_f21;
            temp_f20 = func_0044b7b0(temp_f22);
            if (temp_f21 < 0.5f) {
                temp_f0 = func_0044b7b0(2.0f * temp_f22);
            } else {
                if (*(s32 *)(temp_17 + 0x44) == 0) {
                    *(f32 *)(temp_17 + 0x3C) = *(f32 *)(temp_17 + 0x40);
                    *(f32 *)(temp_17 + 0x38) = *(f32 *)(temp_17 + 0x30) - *(f32 *)(temp_17 + 0x40);
                    *(s32 *)(temp_17 + 0x44) = 1;
                }
                temp_f0 = func_0044b7b0(2.0f * temp_f22 - fGpffff84a4);
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
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
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
/* measured: loop-invariant source recipe from the archived c270 probe. */
#pragma opt_loop_invariants on
// FUN_0034C270
void func_0034c270(Vec2f arg0, s32 arg1, s32 arg2, f32 fparg0) {
    u8 sp50[0x16A0];
    s32 b;
    f32 hi;
    f32 lo;
    f32 c255;
    f32 *srcBase;
    s32 i;
    u8 *dst;
    f32 *src;
    f32 var_f4;
    f32 temp_f0;
    f32 var_f0;
    u8 var_3;

    b = arg1;
    srcBase = (f32 *)(D_00749CC0 + arg2 * 0x3C0);
    D_0088467C[0] = fparg0;
    func_0043f9c8(sp50, 0, 0x16A0);
    if ((arg2 <= 0) || (arg2 >= 0x24)) {
        func_0046d730(&iGpffffa950, 0x2B8);
    }
    *(s32 *)((u8 *)sp50 + 0x1680) = arg2;
    *(s16 *)((u8 *)sp50 + 0x1684) = (s16)(s32)(*(f32 *)(D_007523C4 + arg2 * 0x10));
    i = 0;
    hi = arg0.y;
    lo = arg0.x;
    c255 = 255.0f;
    for (; i < 0x14; i++) {
        dst = sp50 + i * 0x54;
        src = srcBase + i * 0xC;
        *(f32 *)(dst + 8) = lo + src[2];
        *(f32 *)(dst + 0xC) = hi + src[3];
        *(f32 *)(dst + 0x34) = src[6];
        *(s16 *)(dst + 0x48) = *(s16 *)((u8 *)src + 0x1C);
        var_f4 = (f32)(u32)b;
        temp_f0 = (var_f4 * src[9]) / c255;
        var_3 = (u8)temp_f0;
        var_f0 = (f32)var_3;
        *(f32 *)(dst + 0x24) = var_f0;
    }
    func_0034c500(sp50, arg0, b);
    D_0088467C[0] = 0.0f;
}
/* measured: closes the c270 loop-invariant scope. */
#pragma opt_loop_invariants off
// FUN_0034C4A0
void func_0034c4a0(void) {
    Vec2f sp18;
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

/* measured: the by-value Vec2f position gives the retail argument home at
   sp+0x38 without a scalar-to-aggregate copy. Load XY before selecting the
   dimensions; keep the blue/red/green local order for byte-clamp allocation.
   Object 436B/window 448B, normalized_diff 0; twelve zero tail bytes.
   The c270 and c4a0 aggregate callers retain normalized_diff 0. */
// FUN_0034C500
void func_0034c500(u8 *arg0, Vec2f arg1, s32 arg2) {
    u8 bytes[4];
    u8 sp40[0x100];
    f32 x;
    f32 y;
    f32 var_f14;
    f32 var_f15;
    s32 var_16;
    u8 var_2;
    u8 var_5;
    u8 var_3;
    u8 var_3_2;
    u8 *temp_2;
    u8 *temp_4;

    func_0034edc0();
    if (*(s16 *)(D_007523CA + (*(s32 *)(arg0 + 0x1680) * 0x10)) != 0) {
        func_0034c860(arg0, arg1, arg2);
        func_0034cef0(arg0 + 0x690);
    }
    var_16 = 0;
    for (; var_16 < 0x14; var_16++) {
        temp_4 = arg0 + (var_16 * 0x54);
        x = *(f32 *)(temp_4 + 8);
        y = *(f32 *)(temp_4 + 0xC);
        if (*(s16 *)(D_007523C0 + (*(s32 *)(arg0 + 0x1680) * 0x10) + 8) == 0) {
            var_f15 = 448.0f;
            var_f14 = *(f32 *)(temp_4 + 0x34);
        } else {
            var_f15 = *(f32 *)(temp_4 + 0x34);
            var_f14 = 640.0f;
        }
        temp_2 = D_00749840 + (*(s16 *)(temp_4 + 0x48) * 4);
        var_5 = temp_2[0];
        if ((s32)var_5 < 0) {
            var_5 = 0;
        }
        var_3 = temp_2[1];
        if ((s32)var_3 < 0) {
            var_3 = 0;
        }
        var_2 = temp_2[2];
        if ((s32)var_2 < 0) {
            var_2 = 0;
        }
        bytes[0] = var_5;
        bytes[1] = var_3;
        bytes[2] = var_2;
        var_3_2 = (u8)*(f32 *)(temp_4 + 0x24);
        bytes[3] = var_3_2;
        func_0034c6c0(sp40, x, y, var_f14, var_f15, bytes);
        func_0034c820(sp40);
    }
}

/* measured (wave 14): the f0d0 extern is floats-first — the true signature is
   (u8*, f32, f32, f32, f32, u8, u8, u8, u8), NOT (u8*, s32, s32, s32, s32,
   f32, f32, f32, f32). With the corrected extern AND the C callsite written
   floats-first (ptr, f0, f1, f2, f3, b0, b1, b2, b3), all four callsites now
   match retail byte-for-byte (move $a0, mov.s $f12-$f15, then lbu $5-$8) —
   nd 17 -> 6. */
/* measured: declaration order is intentionally interleaved (u8* arg0, four f32
   parameters, then u8* arg1); this makes MWCCPS2 save the float arguments before
   $s0, matching retail exactly. The grouped integer-first declaration was nd 13;
   this order is nd 0. */
// FUN_0034C6C0
void func_0034c6c0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, u8 *arg1) {
    f32 z;
    f32 scale;

    z = D_008872F8[0] - D_0088467C[0];
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    func_0034f0d0(arg0, fparg0, fparg1, z, scale, arg1[0], arg1[1], arg1[2], arg1[3]);
    func_0034f0d0(arg0 + 0x40, fparg0, fparg1 + fparg3, z, scale, arg1[0], arg1[1], arg1[2], arg1[3]);
    func_0034f0d0(arg0 + 0x80, fparg0 + fparg2, fparg1 + fparg3, z, scale, arg1[0], arg1[1], arg1[2], arg1[3]);
    func_0034f0d0(arg0 + 0xC0, fparg0 + fparg2, fparg1, z, scale, arg1[0], arg1[1], arg1[2], arg1[3]);
}


// FUN_0034C820
void func_0034c820(u8 *arg0) {
    D_00887310[0](5, arg0, 4);
}




/* measured: Vec2f owns the argument spill; addF prevents height-sum caching,
   and subF preserves the pre-callback width lifetime. The db60 declaration
   is floats-first. Object 1672B/window 1680B, normalized_diff 0; eight zero
   tail bytes. No stack/register assembly or optimization pragma is needed. */
// FUN_0034C860
void func_0034c860(u8 *arg0, Vec2f arg1, s32 arg2) {
    s32 offset;
    s16 kind;
    s16 effect;
    f32 width1;
    f32 y1;
    f32 z1;
    f32 q1;
    f32 x1;
    f32 extent2;
    f32 width2;
    f32 y2;
    f32 x2;
    f32 z2;
    f32 q2;
    f32 right2;
    f32 start;
    f32 elapsed;
    f32 width3;
    f32 y3;
    f32 x3;
    f32 z3;
    f32 q3;
    f32 right3;
    u8 alpha1;
    u8 alpha2;
    u8 alpha3;

    offset = *(s32 *)(arg0 + 0x1680) * 0x10;
    kind = *(s16 *)(D_007523CA + offset);
    effect = *(s16 *)(D_007523CC + offset);
    *(s16 *)(arg0 + 0x996) = effect;
    *(Vec2f *)(arg0 + 0x99C) = arg1;
    *(u8 *)(arg0 + 0x994) = arg2;
    switch (kind) {
    case 0: break;
    case 1: func_0034d040(arg0); break;
    case 2: func_0034d070(arg0, 1); break;
    case 3: func_0034d280(arg0, 1); break;
    case 4: func_0034d490(arg0, 1); break;
    case 5: func_0034d690(arg0, 1); break;
    case 6: func_0034d890(arg0, 1); break;
    case 7: func_0034d070(arg0, 0); break;
    case 8: func_0034d280(arg0, 0); break;
    case 9: func_0034d490(arg0, 0); break;
    case 10: func_0034d690(arg0, 0); break;
    case 11: func_0034d890(arg0, 0); break;
    case 12: func_0034ddf0(arg0, 1); break;
    case 13: func_0034ddf0(arg0, 0); break;
    case 14: func_0034db60(arg0, 0.5f, 1); break;
    case 15: func_0034db60(arg0, 0.5f, 0); break;
    case 16: func_0034db60(arg0, 1.0f, 1); break;
    case 17: func_0034db60(arg0, 1.0f, 0); break;
    default: func_0046d730(&iGpffffa950, 0x3A9); break;
    }
    switch ((s64)effect) {
    case 0: break;
    case 1:
        width1 = *(f32 *)(arg0 + 8) - arg1.x;
        y1 = arg1.y;
        z1 = D_008872F8[0] - D_0088467C[0];
        q1 = 1.0f / *(f32 *)(func_00457120() + 0x80);
        alpha1 = arg2 & 0xFF;
        func_0034f0d0(arg0 + 0x890, arg1.x, y1, z1, q1, 255, 255, 129, alpha1);
        func_0034f0d0(arg0 + 0x8D0, arg1.x, addF(y1, 448.0f), z1, q1, 255, 255, 129, alpha1);
        x1 = arg1.x + width1;
        func_0034f0d0(arg0 + 0x910, x1, addF(y1, 448.0f), z1, q1, 255, 255, 129, alpha1);
        func_0034f0d0(arg0 + 0x950, x1, y1, z1, q1, 255, 255, 129, alpha1);
        break;
    case 2:
        extent2 = *(f32 *)(arg0 + 0x644);
        width2 = subF(640.0f - extent2, arg1.x);
        y2 = arg1.y;
        x2 = extent2 + arg1.x;
        z2 = D_008872F8[0] - D_0088467C[0];
        q2 = 1.0f / *(f32 *)(func_00457120() + 0x80);
        alpha2 = arg2 & 0xFF;
        func_0034f0d0(arg0 + 0x890, x2, y2, z2, q2, 255, 255, 129, alpha2);
        func_0034f0d0(arg0 + 0x8D0, x2, addF(y2, 448.0f), z2, q2, 255, 255, 129, alpha2);
        right2 = x2 + width2;
        func_0034f0d0(arg0 + 0x910, right2, addF(y2, 448.0f), z2, q2, 255, 255, 129, alpha2);
        func_0034f0d0(arg0 + 0x950, right2, y2, z2, q2, 255, 255, 129, alpha2);
        break;
    case 3:
        if (*(s32 *)(arg0 + 0x1690) == 0) {
            start = *(f32 *)(arg0 + 0x4C);
            elapsed = (f32)*(s16 *)(arg0 + 0x1684);
            if (!(elapsed <= start)) {
                width3 = 840.0f * func_0044b610((iGpffff8094 * (elapsed - start)) / (*(f32 *)(arg0 + 0x50) - start));
            } else {
                width3 = 840.0f;
            }
        } else {
            width3 = 0.0f;
        }
        y3 = arg1.y;
        x3 = arg1.x + (*(f32 *)(arg0 + 8) - width3);
        z3 = D_008872F8[0] - D_0088467C[0];
        q3 = 1.0f / *(f32 *)(func_00457120() + 0x80);
        alpha3 = arg2 & 0xFF;
        func_0034f0d0(arg0 + 0x890, x3, y3, z3, q3, 255, 255, 129, alpha3);
        func_0034f0d0(arg0 + 0x8D0, x3, addF(y3, 448.0f), z3, q3, 255, 255, 129, alpha3);
        right3 = x3 + (width3 - arg1.x);
        func_0034f0d0(arg0 + 0x910, right3, addF(y3, 448.0f), z3, q3, 255, 255, 129, alpha3);
        func_0034f0d0(arg0 + 0x950, right3, y3, z3, q3, 255, 255, 129, alpha3);
        break;
    case 4: break;
    default: func_0046d730(&iGpffffa950, 0x3DF); break;
    }
}
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
void func_0034d890(u8 *arg0, s32 arg1) {
    f32 temp_f2;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f1;
    f32 temp_f2_2;
    f32 temp_f0;
    f32 var_f1;
    s32 temp_16;
    u8 temp_2;
    u8 temp_3;

    temp_f2 = (2.0f * *(f32 *)(arg0 + 0x1688)) / 3.0f;
    if (*(s32 *)(arg0 + 0x1690) == 0) {
        temp_f1 = (f32)*(s16 *)(arg0 + 0x1684);
        if (temp_f1 < temp_f2) {
            temp_f0 = func_0044b7b0((iGpffff8094 * temp_f1) / temp_f2);
        } else {
            temp_f0 = 1.0f;
        }
    } else {
        temp_f0 = 1.0f;
    }
    if (arg1 == 0) {
        temp_f0 = 1.0f - temp_f0;
    }
    temp_f21 = 164.0f * temp_f0;
    temp_2 = *(u8 *)(arg0 + 0x994);
    var_f1 = (f32)(u32)temp_2;
    temp_f2_2 = var_f1 * temp_f0;
    temp_16 = (u8)temp_f2_2;
    *(s32 *)(arg0 + 0x990) = 0;
    temp_f20 = *(f32 *)(arg0 + 0x9A0);
    temp_f22 = (247.0f - 82.0f * temp_f0) + *(f32 *)(arg0 + 0x99C);
    temp_f23 = D_008872F8[0] - D_0088467C[0];
    temp_f24 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_3 = (u8)temp_16;
    func_0034f0d0(arg0 + 0x690, temp_f22, temp_f20, temp_f23, temp_f24,
                  0xFF, 0xE9, 0x2C, temp_3);
    func_0034f0d0(arg0 + 0x6D0, temp_f22, addF(temp_f20, 448.0f), temp_f23, temp_f24,
                  0xFF, 0xE9, 0x2C, temp_3);
    func_0034f0d0(arg0 + 0x710, addF(temp_f22, temp_f21), addF(temp_f20, 448.0f),
                  temp_f23, temp_f24, 0xFF, 0xE9, 0x2C, temp_3);
    func_0034f0d0(arg0 + 0x750, addF(temp_f22, temp_f21), temp_f20, temp_f23, temp_f24,
                  0xFF, 0xE9, 0x2C, temp_3);
}
/* measured: reconstructed d890 body matches retail byte-for-byte (720-byte window). */

/* Measured: declaration order and inline multiply boundaries preserve FP
 * allocation; 652/656 bytes, 13 resolved relocations and four zero tail bytes. */
// FUN_0034DB60
void func_0034db60(u8 *arg0, f32 fparg0, s32 arg1) {
    f32 elapsed;
    f32 height;
    f32 width;
    f32 inset_x;
    f32 inset_y;
    f32 amount;
    f32 left;
    f32 right;
    f32 top;
    f32 depth;
    f32 bottom;
    f32 reciprocal;
    f32 duration;

    duration = *(f32 *)(arg0 + 0x1688) * fparg0;
    if (*(s32 *)(arg0 + 0x1690) == 0) {
        elapsed = (f32)*(s16 *)(arg0 + 0x1684);
        if (elapsed < duration) {
            amount = func_0044b7b0((iGpffff8094 * elapsed) / duration);
        } else {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (arg1 == 0) {
        amount = 1.0f - amount;
    }
    width = mulF(640.0f, amount);
    inset_x = (640.0f - width) / 2.0f;
    height = mulF(480.0f, amount);
    inset_y = (448.0f - height) / 2.0f;
    *(s32 *)(arg0 + 0x990) = 0;
    top = inset_y + *(f32 *)(arg0 + 0x9A0);
    left = inset_x + *(f32 *)(arg0 + 0x99C);
    depth = D_008872F8[0] - D_0088467C[0];
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    func_0034f0d0(arg0 + 0x690, left, top, depth, reciprocal, 255, 233, 44, 255);
    bottom = addF(top, height);
    func_0034f0d0(arg0 + 0x6D0, left, bottom, depth, reciprocal, 255, 233, 44, 255);
    right = addF(left, width);
    func_0034f0d0(arg0 + 0x710, right, bottom, depth, reciprocal, 255, 233, 44, 255);
    func_0034f0d0(arg0 + 0x750, right, top, depth, reciprocal, 255, 233, 44, 255);
    *(s16 *)(arg0 + 0x1670) = func_0034e360(arg0, inset_x + *(f32 *)(arg0 + 0x99C), inset_y + *(f32 *)(arg0 + 0x9A0), width, height);
    func_0034ee90(arg0, 0.0f, 0.0f, amount);
}
/* measured: disabling common-subexpression elimination preserves retail's
   per-call corner recomputation. */
#pragma opt_common_subs off
/* Floor (re-measured 2026-09-17): probe_variants 5 reloc-masked differing */
/* words; fnalign retail 175 instrs / object 175 instrs, 5 edits plus 6 */
/* reloc-only (175*4 = 700B in the 704B window; the 1-word suffix is retail */
/* zero tail). All five edits sit in the alpha float-to-int clamp: retail */
/* `cvt.w.s $f1,$f2` against object `cvt.w.s $f2,$f2`, cascading through the */
/* high-path sub.s/cvt/mfc1 FPR colour. That is destination selection, not */
/* source shape: sibling func_00311930 (code1_0031.c) measures 149/149 with */
/* 5 words / 5 edits over the same cvt.w.s/mfc1 colour wall (re-measured */
/* 2026-09-17), so this floor is banked with that evidence rather than */
/* ground further. Body banked verbatim from */
/* docs/probe_archive/VNLN_0034ddf0_body.c; its native geometry and */
/* mutating-callback smoke evidence stays in the archive. Pragma sweep */
/* 2026-09-17: `opt_propagation off` is load-bearing (bare body scores 140), */
/* the file `opt_common_subs off` region is load-bearing (forcing it on */
/* scores 161), `schedule on` scores 158, `opt_loop_invariants on` ties at */
/* 5 words / 5 edits with an identical stream and is omitted for simplicity. */
/* Pairs 2026-09-17 (`tools/pragma_sweep.py --pairs`, 8 singles + 28 pairs, */
/* banked 5, already carries prop_off): ties at 5 only with prop_off */
/* (prop alone + 5 prop pairs); bare 140, cse/loopinv/strength/unroll 140, */
/* dead 144, sched 156, peephole 146/205. No pair beats prop_off; floor stands. */
/* Semantic gate: (u8*,s32) signature matches retail and both headstarts; */
/* the alpha-narrowing idiom mirrors MATCHED sibling func_0034d890 above. */
/* 2026-09-18, handoff 7h-quinquies and 7p probes; floor stands at 5.  The
   residual is conversion-register selection: retail lands `cvt.w.s` in $f1
   at instructions 70 and 77, this body lands it in $f2, reusing the source
   register.  The 7h-quinquies pragma lever does not reach it here -
   `opt_common_subs off`, `opt_propagation off` and `schedule off` all tie at
   5, and `optimization_level 1` costs 121.  Nor does the source form of the
   conversion: folding the product into the cast ties at 5, assigning the
   product back into `var_f1` costs 9, and forcing an explicit integer
   intermediate - `(u8)(s32)temp_f2_2` or a separate `s32 conv` - costs 101
   both ways, because it materialises a second conversion. */
/* 2026-09-19 pair close-out (Main request): fnalign 175/175, 5 edits +6 reloc-only =11 floor_distance edits, 17 words. Frame addiu $sp,-0x50 both sides -- match, closed on frame. */
/* - reloc-only [22:23] lwc1 $f0,-0x7f6c($gp) vs lwc1 $f0,($gp) (iGpffff8094): immediate. */
/* - replace [70:72] cvt.w.s $f1,$f2 + mfc1 $v1,$f1 vs cvt.w.s $f2,$f2 + mfc1 $v1,$f2: register-only FPR rotation $f1<->$f2 (conversion-temp selection, 7h-bis). */
/* - replace [76:79] sub.s $f1,$f2,$f1 + cvt.w.s $f1,$f1 + mfc1 $v1,$f1 vs sub.s $f2,$f2,$f1 + cvt.w.s $f2,$f2 + mfc1 $v1,$f2: register-only FPR rotation (high-path cascade of the same temp). */
/* - reloc-only [92:93] lwc1 $f0,-0x7de0($gp) vs lwc1 $f0,($gp) (iGpffff8220): immediate. */
/* - reloc-only [101:105] lui $v0,0x88 + lwc1 $f1,0x72f8($v0) + lui $v0,0x88 + lwc1 $f0,0x467c($v0) vs lui $v0,0 + lwc1 $f1,($v0) + lui $v0,0 + lwc1 $f0,($v0) (D_008872F8/D_0088467C): immediates. */
/* No $a0-$t0 spill move, no operand-order (mul/div/sub operand order already retail's), no branch-offset (bc1t/bc1f/c.lt/c.le all match), no nop-vs-work (both sides emit cvt+mfc1+andi). Next person: finished on frame/count, open only on $f1/$f2 destination. */
// FUN_0034DDF0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_0034ddf0(u8 *arg0, s32 arg1) {
    f32 temp_f2;
    f32 temp_f21;
    f32 temp_f20;
    struct { f32 reciprocal; f32 depth; } projection;
    f32 temp_f24;
    f32 temp_f1;
    f32 temp_f2_2;
    f32 var_f0;
    f32 var_f1;
    s32 temp_16;
    u8 temp_2;
    u8 temp_3;

    temp_f2 = *(f32 *)(arg0 + 0x1688);
    if (*(s32 *)(arg0 + 0x1690) == 0) {
        temp_f1 = (f32)*(s16 *)(arg0 + 0x1684);
        if (temp_f1 < temp_f2) {
            var_f0 = func_0044b7b0((iGpffff8094 * temp_f1) / temp_f2);
        } else {
            var_f0 = 1.0f;
        }
    } else {
        var_f0 = 1.0f;
    }
    if (arg1 == 0) {
        var_f0 = 1.0f - var_f0;
    }
    temp_f21 = 171.0f * var_f0;
    temp_2 = *(u8 *)(arg0 + 0x994);
    var_f1 = (f32)(u32)temp_2;
    temp_f2_2 = var_f1 * var_f0;
    temp_16 = (u8)temp_f2_2;
    *(s32 *)(arg0 + 0x990) = 0;
    temp_f1 = iGpffff8220 - (171.0f * var_f0) / 2.0f;
    temp_f20 = addF(temp_f1, *(f32 *)(arg0 + 0x9A0));
    temp_f24 = 77.0f + *(f32 *)(arg0 + 0x99C);
    projection.depth = D_008872F8[0] - D_0088467C[0];
    projection.reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_3 = (u8)temp_16;
    func_0034f0d0(arg0 + 0x690, temp_f24, temp_f20, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, temp_3);
    temp_f21 = addF(temp_f20, temp_f21);
    func_0034f0d0(arg0 + 0x6D0, temp_f24, temp_f21, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, temp_3);
    func_0034f0d0(arg0 + 0x710, addF(temp_f24, 580.0f), temp_f21, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, temp_3);
    func_0034f0d0(arg0 + 0x750, addF(temp_f24, 580.0f), temp_f20, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, temp_3);
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034ddf0);
#endif
/* measured: closes ddf0 common-subexpression scope after its archived body. */
#pragma opt_common_subs on
/* measured: snapshot alpha before the camera callback, then narrow for the
   vertex calls. addF keeps each translated corner addition separate. */
// FUN_0034E0B0
void func_0034e0b0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2)
{
    u32 alpha;
    u8 byte_alpha;
    f32 x;
    f32 y;
    f32 z;
    f32 scale;
    alpha = *(u8 *)(arg0 + 0x994);
    y = fparg1 + *(f32 *)(arg0 + 0x9A0);
    x = fparg0 + *(f32 *)(arg0 + 0x99C);
    z = D_008872F8[0] - D_0088467C[0];
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    byte_alpha = (u8)alpha;
    func_0034f0d0(arg0 + 0x690, x, y, z, scale, 0xFA, 0xE3, 0x27, byte_alpha);
    func_0034f0d0(arg0 + 0x6D0, x, addF(y, 480.0f), z, scale, 0xFA, 0xE3, 0x27, byte_alpha);
    func_0034f0d0(arg0 + 0x710, addF(x, 640.0f), addF(y, 480.0f), z, scale, 0xFA, 0xE3, 0x27, byte_alpha);
    func_0034f0d0(arg0 + 0x750, addF(x, 640.0f), y, z, scale, 0xFA, 0xE3, 0x27, byte_alpha);
    *(s16 *)(arg0 + 0x1670) = func_0034e360(arg0, fparg0, fparg1, 640.0f, 448.0f);
    func_0034ee90(arg0, fparg0, fparg1, fparg2);
}

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

/* measured: GUARDED_SCORE 331 via tools/measure_guarded.py */
/* src/promoted/nLine.c func_0034e360; fnalign retail 662/object 662 instrs */
/* exact (2648B emitted/window 2656B, 8B zero tail), 233 edits +11 reloc-only. */
/* De-noised /var/tmp/cold34e360/m2c.c (259 lines, s128 sp110/sp100, spFC..spD4, */
/* goto-loops) + romwright.c (211 lines, arity 5) + romwright_raw.c (198 lines) */
/* + romwright_types.txt (arg0 +0x994/+0x998/+0x99A) + ghidra nLine.c:464-659 + */
/* ida nLine.c:335-449 + docs/probe_archive/VNLN_0034e360_body.c (334) into file */
/* idiom (Vec2f, s32 return, 44B NLineDecorationStyle, floats-first f0d0, */
/* iGpffffa950). Neighbouring opt_loop_invariants/opt_propagation/opt_common_subs */
/* regions read (ba30, bd60, bea0/c120, c270, d070/d280/d490/d690, ddf0); none */
/* kept without measurement. Step1 counts exact: no float-to-unsigned lui 0x4f00, */
/* s16 mode/index correct (retail 3 dsll32), no struct-copy widen, no defensive */
/* init (directions unset on custom-size path). Step2 pragma_sweep banked 331: */
/* strength/unroll tie 331, loop 496, dead 498, prop 562, subs 574, peephole 594, */
/* schedule 616, O3/O4 617, O1 624, O0 767 — no keep. Step3 subscript: byte-offset */
/* *(f32*)((u8*)style+24+i*4) 493 regress (+162), array-idx tie 334 — P[i] stands; */
/* base pointer not hoisted (retail reloads each iteration). Step4 decl order: */
/* direction_y before direction_x 334->331 WINNER (-3, edits 249->233); depth/vert */
/* ties 334; second round (mode/start/vert-top) all tie 331; expr mulswap + */
/* split-center tie 331 — two consecutive non-improving (decl2+expr) so bank 331. */
/* Biggest residual: saved-GPR/FP rotation + stack-slot shifts + slti $at vs $v0 */
/* at 0x34 + add.s/mul.s operand orientation. verify 26 MATCH/2 ASM/0 MISMATCH; */
/* lint 0 errors (1 pre-existing H007 warn at c270:449). */
// FUN_0034E360 NONMATCHING
#ifdef NON_MATCHING
typedef struct {
    s16 count;
    s32 colors[5];
    f32 offsets[5];
} NLineDecorationStyle;

/* Styles 1-4 require a full-width or full-height translated edge. Retail */
/* does not initialize directions on the custom-size path; style 5 does */
/* not use them. Do not invent a direction for unsupported combinations. */
s32 func_0034e360(u8 *arg0, f32 x, f32 y, f32 width, f32 height) {
    s16 mode;
    s16 index;
    Vec2f start;
    f32 depth;
    f32 reciprocal;
    s32 direction_y;
    s32 direction_x;
    u8 *vertices;

    mode = *(s16 *)(arg0 + 0x998);
    index = (s16)(mode - 1);
    if (mode == 0) {
        return 0;
    }
    depth = D_008872F8[0] - D_0088467C[0];
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    vertices = arg0 + 0x9B0;
    if (width != 640.0f && height != 448.0f) {
        start.x = x;
        start.y = y;
        x += width;
        y += height;
    } else if (x < 0.0f) {
        start.x = 640.0f + x;
        start.y = y;
        x = start.x;
        y = 448.0f + y;
        direction_x = 1;
        direction_y = 0;
    } else if (!(x <= 0.0f)) {
        start.x = x;
        start.y = 448.0f + y;
        direction_x = -1;
        direction_y = 0;
    } else if (!(y <= 0.0f)) {
        start.x = x;
        start.y = y;
        x = 640.0f + x;
        direction_x = 0;
        direction_y = -1;
    } else if (y < 0.0f) {
        start.x = 640.0f + x;
        start.y = y;
        direction_x = 0;
        direction_y = 1;
    } else {
        return 0;
    }
    switch (mode) {
    case 1:
    case 2:
    case 3:
    case 4: {
        NLineDecorationStyle *style;
        s32 count;
        s32 selected;
        s32 i;
        s32 n;
        Vec2f center;
        Vec2f peak_offset;
        Vec2f gap_offset;
        style = (NLineDecorationStyle *)D_00752600 + index;
        count = style->count;
        selected = *(s16 *)(arg0 + 0x99A);
        i = 0;
        n = 0;
        if (count > 0) {
            center.x = (start.x + x) / 2.0f;
            center.y = (start.y + y) / 2.0f;
            peak_offset.y = 200.0f * (f32)direction_y;
            peak_offset.x = 200.0f * (f32)direction_x;
            gap_offset.x = 30.0f * (f32)direction_x;
            gap_offset.y = 30.0f * (f32)direction_y;
            while (i < count) {
                f32 distance;
                Vec2f shift;
                u8 *color;
                u32 alpha;
                u8 byte_alpha;
                distance = style->offsets[i];
                shift.x = (f32)direction_x * distance;
                shift.y = (f32)direction_y * distance;
                color = D_00749AC0 + style->colors[i] * 4;
                if (i == selected) {
                    alpha = 0;
                } else {
                    alpha = (u8)((color[3] * arg0[0x994]) / 255);
                }
                byte_alpha = (u8)alpha;
                if (i == 0) {
                    func_0034f0d0(vertices + (n++ << 6), x, y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), peak_offset.x + (center.x + shift.x), peak_offset.y + (center.y + shift.y), depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), start.x, start.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                } else {
                    f32 previous;
                    Vec2f previous_shift;
                    Vec2f peak;
                    Vec2f edge;
                    Vec2f inner_peak;
                    Vec2f other;
                    previous = 30.0f + style->offsets[i - 1];
                    previous_shift.x = (f32)direction_x * previous;
                    previous_shift.y = (f32)direction_y * previous;
                    shift.x += gap_offset.x;
                    shift.y += gap_offset.y;
                    func_0034f0d0(vertices + (n++ << 6), x + shift.x, y + shift.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    peak.y = peak_offset.y + (center.y + shift.y);
                    peak.x = peak_offset.x + (center.x + shift.x);
                    func_0034f0d0(vertices + (n++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    edge.y = y + previous_shift.y;
                    edge.x = x + previous_shift.x;
                    func_0034f0d0(vertices + (n++ << 6), edge.x, edge.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), edge.x, edge.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    inner_peak.y = peak_offset.y + (center.y + previous_shift.y);
                    inner_peak.x = peak_offset.x + (center.x + previous_shift.x);
                    func_0034f0d0(vertices + (n++ << 6), inner_peak.x, inner_peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), inner_peak.x, inner_peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    other.y = start.y + previous_shift.y;
                    other.x = start.x + previous_shift.x;
                    func_0034f0d0(vertices + (n++ << 6), other.x, other.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), other.x, other.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), start.x + shift.x, start.y + shift.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                }
                ++i;
            }
        }
        if (n >= 0x34) {
            func_0046d730(&iGpffffa950, 0x67E);
        }
        return n;
    }
    case 5: {
        NLineDecorationStyle *style;
        s32 i;
        s32 n;
        style = (NLineDecorationStyle *)D_00752600 + index;
        i = style->count - 1;
        n = 0;
        while (i >= 0) {
            f32 distance;
            Vec2f top_left;
            Vec2f bottom_right;
            u8 *color;
            u8 alpha;
            distance = style->offsets[i];
            color = D_00749AC0 + style->colors[i] * 4;
            alpha = (u8)((color[3] * arg0[0x994]) / 255);
            top_left.y = start.y - distance;
            top_left.x = start.x - distance;
            func_0034f0d0(vertices + (n++ << 6), top_left.x, top_left.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            bottom_right.x = x + distance;
            func_0034f0d0(vertices + (n++ << 6), bottom_right.x, top_left.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            bottom_right.y = y + distance;
            func_0034f0d0(vertices + (n++ << 6), bottom_right.x, bottom_right.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            func_0034f0d0(vertices + (n++ << 6), top_left.x, top_left.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            func_0034f0d0(vertices + (n++ << 6), bottom_right.x, bottom_right.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            func_0034f0d0(vertices + (n++ << 6), top_left.x, bottom_right.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            --i;
        }
        if (n >= 0x34) {
            func_0046d730(&iGpffffa950, 0x6AC);
        }
        return n;
    }
    default:
        func_0046d730(&iGpffffa950, 0x6AF);
        return 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034e360);
#endif
