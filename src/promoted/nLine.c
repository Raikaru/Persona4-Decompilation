#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit nLine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

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
extern char iGpffffa958;

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
void func_0034f0d0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
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




// FUN_0034B970
s32 func_0034b970(void) {
    s32 temp_2;

    temp_2 = func_00451de0(&iGpffffa958, 0xC7, 0, 0, func_0034b8d0, 0, 0);
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
   best identical nd 25. Register-coloring floor. */
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

// FUN_0034BEA0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034bea0);
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

/* measured: retail emits each call's args in source order (move $a0, mov.s
   $f12-$f15, then lbu $a1-$t0) and saves $a1 to $s0 after the four float-arg
   mov.s's; mwcc b210 always hoists the four independent lbu argument loads
   ahead of the FP moves and spills $a1 before the float saves, nd 17 (16
   argument-order words + 1 prologue). Tried both prototype class orders
   (ptr,f,f,f,f,i,i,i,i and ptr,i,i,i,i,f,f,f,f) and both C arg orders —
   identical nd. Argument-materialization scheduling floor. */
// FUN_0034C6C0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c6c0);

// FUN_0034C820
void func_0034c820(u8 *arg0) {
    D_00887310[0](5, arg0, 4);
}




// FUN_0034C860
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c860);

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

// FUN_0034D070
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d070);

// FUN_0034D280
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d280);

// FUN_0034D490
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d490);

// FUN_0034D690
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d690);

// FUN_0034D890
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d890);

// FUN_0034DB60
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034db60);

// FUN_0034DDF0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034ddf0);

/* measured: retail colors temp_f21/f22/f20/f26 to $f21/$f22/$f20/$f26 and
   arg0/$byte to $s0/$s1; mwcc b210 permutes the temps to $f21/$f20/$f22/$f27
   (extra $f27 save), swaps $s0/$s1, and hoists call-arg constant materialization
   ahead of the FP mov.s's, nd 101. Tried declaration orders f20,f21,f22,f26 /
   f21,f22,f20,f26 and both arg spellings — identical nd 101. Register-coloring
   + argument-materialization scheduling floor. */
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

// FUN_0034E360
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034e360);
