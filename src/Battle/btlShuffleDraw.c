/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern void func_003549d0();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 func_00354830();

extern void func_0036df30(u8 *arg0);
extern void func_0036d8b0(void);
extern void *func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern s32 func_0038cec0(void *arg0);
extern s32 func_00388bd0(void *arg0);
extern s32 func_0038d790(void *arg0);
extern void func_0034f1e0(void);
extern void func_00374d20(u8 *arg0);
extern void func_00371990(u8 *arg0, u8 *arg1, u8 *arg2);
extern void func_00371ba0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern void func_00370410(u8 *arg0);
extern void func_00370a80(u8 *arg0);
extern void func_003723a0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern void func_00372870(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern void func_00372c30(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5);
extern void func_003730f0(u8 *arg0, s32 arg1, s32 arg2, void *arg3);
extern void func_003733d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00373590(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

typedef struct { f32 x, y, z; } ShuffleVec3;
typedef struct { f32 x, y, z, w; } ShuffleVec4;
typedef struct { s64 a; f32 b; } ShuffleVec2s;

extern s32 func_00442088(char *buf, const char *fmt, ...);
extern char D_0064EA80[];
extern void func_003547c0(s32 *arg0, u8 *arg1);
extern char D_0064EA20[];
extern void func_0046d730(const void *file, u32 line);
extern f32 func_00373cb0(f32 fparg0, f32 fparg1, s32 arg0, f32 fparg2);
extern s64 func_001060b0(void);
extern s32 func_00110d60(s16 value);
extern char iGpffffa9d0;
extern s32 iGpffffa9c8;
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_00440b68();
extern void func_00371f40(u8 *arg0, f32 fparg0, u8 *arg1);
extern void func_00373f00(u8 *arg0);
extern void func_00371e50(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern void func_00371160(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3, u8 *arg4, f32 fparg0);
extern void func_0046b0d0(void *ptr);
extern void func_0044ea90(const void *file, s32 line);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern f32 func_00373c20(u8 *arg0);
extern s32 func_00106330(s32 arg0);
extern void func_0036c900(void);
extern void func_0036d990(u8 *arg0, u8 *arg1);
extern void func_0043f9c8(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0045af60(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_0036dc60(u8 *unit, f32 *src, f32 *dst, f32 scale);
extern void func_00373750(s32 arg0, s32 arg1, void *arg2);
extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, u8 *arg7);
extern void func_003781d0(u8 *arg0, s32 arg1);
extern void func_00378260(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4);
extern char D_0064EA60[];
extern f32 iGpffff83e0;
extern s32 func_00371a60(u8 *arg0, s32 arg1);
extern s32 func_00371c70(u8 *arg0);
extern void func_00370640(u8 *arg0);
extern s32 func_003720c0(u8 *arg0);
extern s32 func_00372200(u8 *arg0);
extern s32 func_003724f0(u8 *arg0);
extern s32 func_003726b0(u8 *arg0);
extern s32 func_00372960(u8 *arg0);
extern s32 func_00372d60(u8 *arg0);
extern void func_00370cd0(u8 *arg0);
extern s32 func_00373170(u8 *arg0);
extern void func_003733f0(u8 *arg0);
extern void func_00373610(u8 *arg0);
extern void func_00375f00(u8 *arg0, s32 arg1);
extern s32 func_004553c0(s32 arg0);
extern s32 func_00455ea0(s32 arg0, s32 arg1, void *arg2);
extern void func_0043f810(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0046af60(s32 arg0);
extern void func_0036d230(s32 arg0);
extern s32 func_0046a750(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_003768e0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, f32 fparg0);
extern f32 func_00375a70(u8 *arg0, s32 arg1);
extern f32 iGpffff8170;
extern void func_003766f0(f32 **arg0, s32 arg1, s32 arg2, u8 *arg3);
extern void func_00376800(u8 **arg0, s32 arg1);
extern void func_00374910(u8 *arg0);
extern void func_00375d50(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 *arg2, f32 *arg3);
extern void func_00375dd0(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1);
extern void func_003760f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5);
extern void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 func_0036de70(u8 *arg0);
extern f32 func_0036deb0(u8 *arg0);
extern void *func_003e0f80(void);
extern void func_003e0c90(void *arg0, void *arg1, s32 arg2, f32 fparg0);
extern void func_003e42a0(void *arg0, void *arg1, void *arg2);
extern void func_003717e0(void *arg0, void *arg1);
extern void func_003e0f40(void *arg0);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern f32 D_008872F8[];
extern void (*D_00887300[])(u32, u32);
extern void (*D_00887310[])(s32, void *, s32);
extern void func_003dc740(void *dst, void *src, s32 c, f32 d);
extern s64 D_0064EA48[];
extern f32 D_0064EA50[];
extern s64 D_0064EA38[];
extern f32 D_0064EA40[];
extern f32 iGpffff840c;
extern f32 iGpffff81e0;
extern void *func_003e9700(s32 arg0);
extern void func_003e0e20(u8 *arg0, void *arg1, s32 arg2);
extern void func_003f6440(s32 arg0, s32 arg1);
extern s32 func_0036be00(void);
extern void func_00410420(s32 arg0, s32 arg1, void *arg2, s32 arg3);
extern void func_004106a0(s32 arg0);
extern void func_00378280(s32 arg0, s32 arg1);
extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 fparg0);
extern f32 func_0044b610(f32 fparg0);
extern void func_003e0a90(void *arg0, void *arg1, s32 arg2);


// FUN_00373E10
void func_00373e10(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg2 > 8) {
        func_0046d730(D_0064EA20, 0x53);
    }
    if ((arg3 < 0) || (arg3 > 4)) {
        func_0046d730(D_0064EA20, 0x54);
    }
    *(s32 *)(arg0 + 0x1F2A8) = arg1;
    *(s32 *)(arg0 + 0x1F304) = arg2;
    *(s32 *)(arg0 + 0x1F2FC) = arg3;
    *(s32 *)(arg0 + 0x1F300) = arg4;
    *(s32 *)(arg0 + 0x1F30C) = 0;
    func_00373f00(arg0);
}


// FUN_00373F00
void func_00373f00(u8 *arg0) {
    s32 count;
    s32 v;
    s32 i;
    u8 *p;

    func_0043f9c8(arg0 + 0x1F1D0, 0, 0x40);
    func_0043f9c8(arg0 + 0x1D6A0, 0, 0x1B30);
    *(u16 *)(arg0 + 0x1F2F4) = 0;
    *(s32 *)(arg0 + 0x1F2F8) = 0;
    *(u16 *)(arg0 + 0x1F2F0) = 0;
    *(u16 *)(arg0 + 0x1F2F2) = 0;
    *(s32 *)(arg0 + 0x1F308) = -1;
    count = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    v = *(s32 *)(arg0 + 0x1F2FC);
    switch (v) {
    case 0:
    case 1:
    case 2:
        *(s32 *)(arg0 + 0x1F310) = 0x42480000;
        break;
    case 3:
    case 4:
        *(s32 *)(arg0 + 0x1F310) = 0x41200000;
        break;
    default:
        func_0046d730(D_0064EA20, 0x7C);
        break;
    }
    for (i = 0; i < count; i++) {
        p = (u8 *)(arg0 + i * 0xE8);
        *(u16 *)(p + 0x1D6A0) |= 2;
    }
}


// FUN_003740B0
void func_003740b0(u8 *arg0, s32 arg1) {
    s32 count;
    s32 i;
    u8 *p;

    if ((func_00106330(0x1403) != 0) && (func_00106330(0x142B) != 0)) {
        func_0036c900();
    }
    count = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    for (i = 0; i < count; i++) {
        func_0036d990(arg0 + i * 0xFB0, (u8 *)(arg1 + (i % *(s32 *)(arg0 + 0x1F304)) * 8));
        p = (u8 *)(arg0 + i * 0xE8);
        *(s32 *)(p + 0x1D720) = 0;
        *(s32 *)(p + 0x1D714) = 0;
        *(s32 *)(p + 0x1D718) = 0x3F800000;
        *(s32 *)(p + 0x1D71C) = 0;
    }
}


// FUN_003741F0
void func_003741f0(u8 *arg0) {
    s32 temp_17;
    s32 temp_2;

    temp_17 = !(func_00110d60((s16)func_001060b0()) & 1);
    func_00440b68(&iGpffffa9d0, D_0064EA20, 0xB5);
    temp_2 = (s32)(func_00454a60(*(u8 **)((u8 *)&iGpffffa9c8 + temp_17 * 4), 1));
    *(s32 *)(arg0 + 0x1F2E8) = temp_2;
    if (temp_2 == 0) {
        func_0046d730(D_0064EA20, 0xB6);
    }
    *(s32 *)(arg0 + 0x1F2EC) = 0;
}


/* measured: re-tested the old \"saved-register rotation\" floor note -- that part is
   SOLVED: declaring i first reproduces retail's exact allocation arg0=$s0, temp=$s1,
   i=$s2, r=$s3, p=$s4 (nd 147 -> 133) and the loop-1/3 pointer form
   lui/ori/addu + sw($s4) with full-address pointer locals all match. The real
   residuals are two scheduling floors: (1) argument-materialisation order before
   BOTH the D_008873F4[0] and func_0043f810 calls -- retail materialises the sp6C
   stack load (lw $a1 / lw $a2) before the constant/register args, mwcc b210 emits
   the constants first (arg reorderings tried, nd stuck); (2) loop 2's pointer
   hoist: retail computes arg0+idx*4+0x1F2AC into $18 BEFORE both calls, mwcc sinks
   it to the store and folds 0x1F2AC as lui $v1,2 / sw -0xd54($v1) (load-sinking
   floor; hoisting into a pointer local did not move it). 4 attempts: m2c decl
   order nd 108, reordered nd 147, probe batch best 133, final 133. */
// FUN_003742B0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003742b0);
// FUN_00374610
void func_00374610(u8 *arg0) {
    s32 i;
    s32 j;
    s32 k;
    u8 *p;
    s32 v;

    for (i = 0; i < 3; i++) {
        p = (u8 *)(arg0 + i * 4 + 0x1F2DC);
        v = *(s32 *)p;
        if (v != 0) {
            jtbl_008873EC[0]((void *)v);
            *(s32 *)p = 0;
        }
    }
    for (j = 0; j < 3; j++) {
        p = (u8 *)(arg0 + j * 4 + 0x1F2AC);
        v = *(s32 *)p;
        if (v != 0) {
            func_0046b0d0((void *)v);
            *(s32 *)p = 0;
        }
    }
    for (k = 0; k < 9; k++) {
        p = (u8 *)(arg0 + k * 4 + 0x1F2B8);
        v = *(s32 *)p;
        if (v != 0) {
            jtbl_008873EC[0]((void *)v);
            *(s32 *)p = 0;
        }
    }
}


// FUN_00374730
void func_00374730(u8 *arg0) {
    f32 sp68[2];
    f32 sp58[3];
    f32 sp48[3];
    f32 sp30[6];
    f32 temp_f12;
    s32 temp_5;
    s32 var_16;

    sp48[0] = 0.0f;
    sp48[1] = 0.0f;
    sp48[2] = 0.0f;
    func_00374910(arg0);
    sp30[3] = 0.0f;
    sp30[0] = 0.0f;
    sp30[1] = 1.0f;
    sp30[2] = 0.0f;
    var_16 = 0;
    goto loop_test;
loop_body:
    func_00373750(var_16, temp_5, &sp68);
    func_0036dc60(arg0 + var_16 * 0xFB0, sp68, sp58, 84.0f);
    if (*(s32 *)(arg0 + 0x1F30C) != 0) {
        temp_f12 = (f32)var_16 * (2.0f - ((f32)(*(s32 *)(arg0 + 0x1F304) - 3) / 5.0f));
        func_00375dd0(arg0, var_16, sp48, sp58, temp_f12, 10.0f + temp_f12);
    } else {
        func_00375d50(arg0, var_16, 0.0f, 0.0f, sp58, sp58);
    }
    func_003760f0(arg0, var_16, 0, 0, sp30, sp30);
    func_00376290(arg0, var_16, 0, 0xFF, 0xFF);
    var_16++;
loop_test:
    temp_5 = *(s32 *)(arg0 + 0x1F304);
    if (var_16 < temp_5) {
        goto loop_body;
    }
    if (*(s32 *)(arg0 + 0x1F30C) != 0) {
        func_0045af60(1, 0, 5, 4);
    }
}


// FUN_00374910
void func_00374910(u8 *arg0) {
    func_0036d8b0();
    func_004577d0(func_00457120(), *(f32 *)(arg0 + 0x1F310));
}


// FUN_00374960
void func_00374960(u8 *arg0) {
    func_0036d8b0();
    func_004577d0(func_00457120(), *(f32 *)(arg0 + 0x1F310));
    *(s32 *)(arg0 + 0x1F298) = func_0038cec0((void *)*(s32 *)(arg0 + 0x1F2A8));
    *(s32 *)(arg0 + 0x1F294) = func_00388bd0((void *)*(s32 *)(arg0 + 0x1F2A8));
    *(s32 *)(arg0 + 0x1F29C) = func_0038d790((void *)*(s32 *)(arg0 + 0x1F2A8));
}


// FUN_00374A10
void func_00374a10(u8 *arg0, s32 arg1) {
    u8 *p = (u8 *)(arg0 + arg1 * 0xE8 + 0x1D6A0);

    switch (*(u32 *)(p + 4)) {
    case 0:
        break;
    case 1:
        if (func_00371a60(p + 0xC, 0) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 2:
        if (func_00371a60(p + 0xC, 1) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 3:
        if (func_00371a60(p + 0xC, 2) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 4:
        if (func_00371c70(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 5:
        func_00370640(p + 0xC);
        break;
    case 6:
        if (func_003720c0(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 7:
        if (func_00372200(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 8:
        if (func_003724f0(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 9:
        if (func_003726b0(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    default:
        func_0046d730(D_0064EA20, 0x1F5);
        break;
    }
    switch (*(s32 *)(p + 8)) {
    case 0:
        break;
    case 1:
        if (func_00372960(p + 0x6C) != 0) {
            *(s32 *)(p + 8) = 0;
        }
        break;
    case 2:
        if (func_00372d60(p + 0x6C) != 0) {
            *(s32 *)(p + 8) = 0;
        }
        break;
    case 3:
        func_00370cd0(p + 0x6C);
        break;
    case 4:
        if (func_00373170(p + 0x6C) != 0) {
            *(s32 *)(p + 8) = 0;
        }
        break;
    default:
        func_0046d730(D_0064EA20, 0x218);
        break;
    }
    func_003733f0(p + 0xD8);
    func_00373610(p + 0xE0);
    if ((func_00375910(p) != 0) && (*(u16 *)p & 1)) {
        func_00375f00(arg0, arg1);
        *(u16 *)p &= 0xFFFE;
    }
}


// FUN_00374CF0
void func_00374cf0(u8 *arg0) {
    func_0036df30(*(u8 **)arg0);
}


/* measured: reconstructed to nd 121 (obj 0x6A4, window 0x6D0). Most of the body
   is byte-exact: frame/slots, the two vec struct copies, the full camera-matrix
   chain (2.0f/dot + 9 products + 9 stores), func_003e0c90/003e0e20, the
   D_00887300 base-hoist calls via the u32-cast recipe ((u32)D_00887300 + per-call
   *(u32*)base jalr -- one lui/addiu in a saved reg, as retail), the
   func_003f6440/00410420/004106a0 calls, the func_00373cb0 call and the
   func_003e0a90 tail. Residuals (all scheduling/register-choice floors): (1) the
   dot chain sorts to mula(x) where retail has mula(y) (same 2-word family as
   func_00377930); (2) func_00378280's arg load is emitted before the a0 move
   (2 words); (3) the D_0064EA38/D_0064EA40 12-byte input interleaves
   ld;sd;lwc1;swc1 and materialises the a1 arg last, retail batches
   a1;ld;lwc1;sd;swc1 (also seen in func_00375b40); (4) both alpha blocks'
   else-arm or/mtc1/cvt use $v0/$f0 where retail uses $v1/$f1 (recipe-A
   register residual, 8 words); (5) both 0x4F000000 float-to-byte guards emit
   c.olt.s $f1,$f0 + bc1f where retail has c.ole.s $f0,$f1 + bc1t, plus mfc1
   $v0 vs $v1 -- identical polarity floor as btlShuffleCalc func_003733f0
   (nd 27, all four compare spellings probed there); (6) the &0x100 u16
   increment block: mwcc keeps the +1 result in $a0 and hoists the andi before
   the sh (retail: $v1, sh-then-andi; tried s32/u16 temp spellings).
   New symbols: D_0064EA38/D_0064EA40/iGpffff840c (evidence in
   config/symbol_data_addrs.txt). 4 attempts: 121, 126, 126, 132. */
// FUN_00374D20
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00374d20);

// FUN_003753F0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003753f0);


// FUN_003757F0
void func_003757f0(u8 *arg0) {
    func_0034f1e0();
    if (*(u16 *)(arg0 + 0x1F2F4) & 4) {
        func_0036df30(arg0 + *(s32 *)(arg0 + 0x1F308) * 0xFB0);
    }
    if (*(u16 *)(arg0 + 0x1F2F4) & 8) {
        func_00374d20(arg0);
    }
}


// FUN_00375890
void func_00375890(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg2) {
        *(u16 *)((u8 *)(arg1 * 0xE8) + (u32)arg0 + 0x1D6A0) |= 2;
    } else {
        *(u16 *)((u8 *)(arg1 * 0xE8) + (u32)arg0 + 0x1D6A0) &= 0xFFFD;
    }
}


// FUN_00375910
s32 func_00375910(u8 *arg0) {
    s32 b;

    b = func_00375970(arg0) != 0;
    if (b) {
        b = func_00375a00(arg0) != 0;
    }
    if (b) {
        b = func_00375a50(arg0) != 0;
    }
    return b;
}


// FUN_00375970
s32 func_00375970(u8 *arg0) {
    f32 var_f1;
    s32 temp_3;
    u32 temp_2;

    temp_3 = *(s32 *)(arg0 + 4);
    switch (temp_3) {
    case 0:
    case 5:
        return 1;
    default:
        temp_2 = *(u16 *)(arg0 + 0xC);
        if (temp_2 >= 0) {
            var_f1 = (f32)temp_2;
        } else {
            temp_2 = (temp_2 >> 1) | (temp_2 & 1);
            var_f1 = (f32)temp_2;
            var_f1 += var_f1;
        }
        return var_f1 >= *(f32 *)(arg0 + 0x10);
    }
}


// FUN_00375A00
s32 func_00375a00(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 8);
    switch (v) {
    case 0:
    case 3:
        return 1;
    default:
        return *(u16 *)(arg0 + 0x6C) >= *(u16 *)(arg0 + 0x6E);
    }
}


// FUN_00375A50
s32 func_00375a50(u8 *arg0) {
    return *(u16 *)(arg0 + 0xDC) >= *(u16 *)(arg0 + 0xDE);
}


/* The source call must place the two converted values in f12/f14 around the
   integer argument as func_00373cb0(var_f12, 0.0f, 0, var_f14); O2 CSEs the
   base-address materialization and swaps the resulting argument registers.
   measured: O1 plus that call order gives a byte-exact match, obj 204B of a
   208B window. */
#pragma optimization_level 1
// FUN_00375A70
f32 func_00375a70(u8 *arg0, s32 arg1) {
    f32 var_f12;
    f32 var_f14;
    s32 idx;

    idx = arg1 * 0xE8;
    var_f12 = (f32)(u32)*(u16 *)((u8 *)idx + (u32)arg0 + 0x1D70C);
    var_f14 = (f32)(u32)*(u16 *)((u8 *)idx + (u32)arg0 + 0x1D70E);
    return func_00373cb0(var_f12, 0.0f, 0, var_f14);
}
/* measured: O1 probe for f70 address materialization */
#pragma optimization_level 2


/* measured: reconstructed to nd 88 (obj 504B, window 528B). The ACC-fused rotation
   block IS emittable -- the chain (mula/madda/madd then mula/msub x3 then
   adda/madd x6) compiles byte-for-byte from plain expressions, with the fixed
   register pattern (f5,f11),(f6,f10),(f7,f9). The residuals are: (1) load order
   of the 7 chain operands -- retail hoists them (B,A,C,D,G,E,F) = sp74,sp70,
   sp78,sp7C,p7C,p74,p78; mwcc b210 sorts struct-field loads ascending and emits
   (A,B,C,D,G,F,E) (sp70-7C as ShuffleVec4) or (B,C,D,G,E,F,A) (temp locals), so
   every downstream register differs (~20 words; separate f32 locals instead make
   mwcc register-allocate them across the func_003dc740 call, nd 127);
   (2) the v==3||v==0 dispatch -- retail beq+beqz-to-shared-var1 + b-to-else;
   mwcc emits beq-to-var1 + bnez-to-else (|| spelling) or separate var1 blocks
   (else-if spelling); (3) the D_0064EA48/D_0064EA50 input: retail batches
   ld;lwc1;sd;swc1, mwcc interleaves ld;sd;lwc1;swc1 (temp-load spelling tried).
   4 attempts: 88, 88, 127, 88. New symbols D_0064EA48/D_0064EA50 added to
   config/symbol_data_addrs.txt (ld/lwc1 evidence). */
// FUN_00375B40
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375b40);

// FUN_00375D50
void func_00375d50(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 *arg2, f32 *arg3) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371990((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3);
    *(s32 *)(p + 0x1D6A4) = 1;
}


// FUN_00375DD0
void func_00375dd0(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371990((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3);
    *(s32 *)(p + 0x1D6A4) = 2;
}


// FUN_00375E50
void func_00375e50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371ba0((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg4, arg2, arg3);
    *(s32 *)(p + 0x1D6A4) = 4;
}


// FUN_00375EC0
void func_00375ec0(u8 *arg0, s32 arg1) {
    u8 *p = (u8 *)(arg1 * 0xE8) + (u32)arg0;
    *(u16 *)(p + 0x1D6A0) |= 1;
}


/* measured: O1 near miss (nd 20, obj 156B/window 160B). Retail keeps arg0 in $s1, idx in $s0, and p in $s2; declaring the base as ((u32)arg0 + (u32)idx) fixes the addu operand order. The second call and final store still recompute the base instead of reusing p; p+ forms collapse the frame under b210. Committed at nd 20. */
// FUN_00375F00 NONMATCHING
#ifdef NON_MATCHING
#pragma optimization_level 1
void func_00375f00(u8 *arg0, s32 arg1) {
    s32 idx;
    u8 *p;
    idx = arg1 * 0xE8;
    p = (u8 *)((u32)arg0 + (u32)idx);
    func_00370410(p + 0x1D6AC);
    *(s32 *)(p + 0x1D6A4) = 5;
    func_00370a80((u8 *)idx + (u32)arg0 + 0x1D70C);
    *(s32 *)((u8 *)idx + (u32)arg0 + 0x1D6A8) = 3;
}
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375f00);
#endif

// FUN_00375FA0
void func_00375fa0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, u8 *arg4, u8 *arg5) {
    ShuffleVec3 v3;
    ShuffleVec3 v4;
    ShuffleVec3 v5;
    s32 idx;

    v3 = *(ShuffleVec3 *)arg3;
    v4 = *(ShuffleVec3 *)arg4;
    v5 = *(ShuffleVec3 *)arg5;
    idx = arg1 * 0xE8;
    func_00371e50((u8 *)(arg0 + idx + 0x1D6AC), arg2, (f32 *)&v3, (f32 *)&v4, (f32 *)&v5);
    *(s32 *)((u8 *)idx + (u32)arg0 + 0x1D6A4) = 6;
}


// FUN_00376070
void func_00376070(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_003723a0((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5);
    *(s32 *)(p + 0x1D6A4) = 8;
}


// FUN_003760F0
void func_003760f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372870((u8 *)(arg0 + idx + 0x1D70C), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5);
    *(s32 *)(p + 0x1D6A8) = 1;
}


// FUN_00376170
void func_00376170(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372c30((u8 *)(arg0 + idx + 0x1D70C), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5, (u8 *)arg6);
    *(s32 *)(p + 0x1D6A8) = 2;
}


// FUN_003761F0
void func_003761f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    ShuffleVec3 v;
    s32 idx;
    u8 *p;

    v = *(ShuffleVec3 *)arg4;
    idx = arg1 * 0xE8;
    p = (u8 *)idx + (u32)arg0;
    func_003730f0((u8 *)(arg0 + idx + 0x1D70C), arg2, arg3, &v);
    *(s32 *)(p + 0x1D6A8) = 4;
}


// FUN_00376290
void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;

    func_003733d0((u8 *)(arg0 + idx + 0x1D778), arg2, arg3, arg4);
}


// FUN_003762E0
void func_003762e0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;

    func_00373590((u8 *)(arg0 + idx + 0x1D780), arg2, arg3, arg4);
}


// FUN_00376330
void func_00376330(u8 *arg0, s32 arg1, f32 *arg2) {
    u8 *p = (u8 *)(arg0 + arg1 * 0xE8 + 0x1D6A0);
    switch (*(u32 *)(p + 4)) {
    case 0:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x18);
        return;
    case 1:
    case 2:
    case 3:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
        return;
    case 5:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x54);
        return;
    case 4:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x48);
        return;
    case 6:
        func_00371160(p + 0x38, p + 0x2C, p + 0x44, arg2, p, *(f32 *)(p + 0x28));
        return;
    case 7:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
        return;
    case 8:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
    case 9:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
        return;
    default:
        func_0046d730(D_0064EA20, 0x4DA);
        return;
    }
}


/* measured: retail emits the two saved-register setup moves (mov.s $f20,$f12 then
   move $s1,$a2) with the FP move first; mwcc b210 emits the GPR move first (nd 4).
   Everything else is solved: u8 *arg0, idx/p locals, the full 0-9 case switch, and
   func_00371f40's interleaved prototype (u8*, f32, u8*) which fixes the pre-jal
   materialisation order. Saved-register setup-order scheduling floor. */
// FUN_003764B0
/* Case values decoded from jtbl_007529D0 with tools/jtbl.py: only entry 6 has
   a body, entries 0-5 and 7-9 fall straight to the epilogue, and >= 10 hits
   the assert. The empty cases must still be listed or b210 emits a compare
   chain instead of the 10-entry table, and `default` is declared before them
   because b210 lays case bodies out in declaration order.
   The parameter list is interleaved (u8*, s32, f32, u8*), not grouped: the
   float arrives in $f12 between the second and third integer argument, and
   the grouped spelling costs nd 8. */
void func_003764b0(u8 *arg0, s32 arg1, f32 fparg0, u8 *arg2) {
    u8 *p;

    p = (u8 *)(arg0 + arg1 * 0xE8 + 0x1D6A0);
    if (arg2 == NULL) {
        func_0046d730(D_0064EA20, 0x4E5);
    }
    switch ((u32)*(s32 *)(p + 4)) {
    case 6:
        func_00371f40(p + 0xC, fparg0, arg2);
        break;
    default:
        func_0046d730(D_0064EA20, 0x508);
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
        break;
    }
}

// FUN_00376590
s32 func_00376590(u8 *arg0, u8 *arg1) {
    ShuffleVec3 sp80;
    ShuffleVec3 sp70;
    s32 i;
    s32 count;
    s32 best;
    f32 bestf;
    f32 f;

    count = *(s32 *)(arg0 + 0x1F2FC);
    if ((count < 0) || (count > 2)) {
        func_0046d730(D_0064EA20, 0x516);
    }
    count = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    func_00376330(arg0, 0, (f32 *)&sp70);
    bestf = func_00373c20((u8 *)&sp70);
    i = 1;
    best = 0;
    while (i < count) {
        func_00376330(arg0, i, (f32 *)&sp80);
        f = func_00373c20((u8 *)&sp80);
        if (f < bestf) {
            bestf = f;
            best = i;
            sp70 = sp80;
        }
        i++;
    }
    if (arg1 != NULL) {
        *(ShuffleVec3 *)arg1 = sp70;
    }
    return best;
}


// FUN_003766F0
void func_003766f0(f32 **arg0, s32 arg1, s32 arg2, u8 *arg3) {
    f32 **var_19;
    f32 *temp_2;
    f32 *temp_3;
    f32 key;

    func_0044ea90(D_0064EA20, 0x589);
    temp_2 = (f32 *)D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_0064EA20, 0x58A);
    }
    key = func_00373c20(arg3);
    *(s32 *)(temp_2 + 1) = arg1;
    *(s32 *)(temp_2 + 2) = arg2;
    temp_2[0] = key;
    var_19 = arg0;
    while ((temp_3 = *var_19) != NULL) {
        if (!(temp_2[0] <= temp_3[0])) break;
        var_19 = (f32 **)(temp_3 + 3);
    }
    if (temp_3 == NULL) {
        *var_19 = temp_2;
        *(f32 **)(temp_2 + 3) = NULL;
        return;
    }
    *(f32 **)(temp_2 + 3) = temp_3;
    *var_19 = temp_2;
}


void func_00376880(u8 **arg0);

// FUN_00376800
void func_00376800(u8 **arg0, s32 arg1) {
    u8 *var_16;

    var_16 = *arg0;
    while (var_16 != NULL) {
        (*(void (**)(s32))(var_16 + 4))(*(s32 *)(var_16 + 8));
        var_16 = *(u8 **)(var_16 + 0xC);
    }
    if (arg1 != 0) {
        func_00376880(arg0);
    }
}


/* Retail re-loads *arg0 at every use. The fix is simply NOT to cache it: a `cur`
   local lets b210 CSE the load with the loop test and the body comes out two
   instructions short (nd 44), and a for(;;)-with-break shape scores nd 33.
   Dereferencing *arg0 at each use is byte-exact - measured. */
// FUN_00376880
void func_00376880(u8 **arg0) {
    u8 *next;

    while (*arg0 != NULL) {
        next = *(u8 **)(*arg0 + 0xC);
        jtbl_008873EC[0](*arg0);
        *arg0 = next;
    }
}


// FUN_003768E0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003768e0);


/* measured: the old "FPU FMA-fusion floor" note is REFUTED -- b210 emits the exact
   retail accumulator chain (mula/madda/madda/madd + 2.0f/div + the 9 rotation
   products) from the plain spelling 2.0f / (y*y + x*x + z*z + w*w), verified
   against a bare compile. Reconstructed the whole function to nd 15 (obj 1236B):
   prologue, all stack slots (sp1B8v ShuffleVec3, sp1C8[2], spB0[0x40] at 0xB0,
   sp80[12], sp70v ShuffleVec4 at 0x70), the f20-f23 saved-FP mapping
   (declaration order alphaBase/halfW/halfH/scale), the alpha lbu/bltz/mtc1/cvt/
   srl/andi/or/add.s recipe-A blocks and the D_00887300/D_00887310 tail all match
   byte-for-byte. Remaining 3 residuals: (1) the two arg1*0xE8 chains emit
   addu $v0,$s4,$v0 where retail has addu $v0,$v0,$s4 -- inline operand flips
   (arg1*0xE8+arg0) did not change it, lever-10 named s32 local untested;
   (2) the dot sum canonicalises to mula(x),madda(y) where retail has
   mula(y),madda(x) -- survived direct-struct-field and 4-temp spellings;
   (3) alpha else-arm or/mtc1 result register $v0 vs retail $v1 (scheduling
   residual, 8 words). 4 attempts: nd 108->15->51. */
// FUN_00377930
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377930);

// FUN_00377E10
s32 func_00377e10(u8 *arg0) {
    s32 *p = *(s32 **)(arg0 + 0x38);

    if (func_00378220() == 0) {
        *p = func_00354830((u8 *)p + 8);
    }
    return 0;
}


// FUN_00377E60
void func_00377e60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_003549d0(p + 8);
    jtbl_008873EC[0](p);
}


/* measured: retail allocates the copy loops as dst=$a0, i=$a1, p=$v0, 0xFF=$v1
   (0xFF hoisted to the preheader); mwcc b210 rotates i to $v0/$a0 and p to $v1,
   materialising 0xFF inside the loop — every instruction is otherwise identical
   (nd 64, obj 800B = window). Everything else in this function is solved: the
   stack layout spA0[3]@0xA0 / sp90[3]@0x90 / sp60[4][3]@0x60 / sp50[4]@0x50 /
   sp40[4]@0x40, the element-wise spill copies via a block-scoped f32* q, the
   +30/-30 shared materialisation (temp_f1 = 30.0f, stores via -temp_f1), the gp
   value in temp_f0/temp_f0_2, the two 4-iteration copy loops to mem[i*0x24+0x120]
   and +0x1B0, and func_00451fc0's 8-arg call. Temp-register rotation floor. */
// FUN_00377EB0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377eb0);





// FUN_003781D0
void func_003781d0(u8 *arg0, s32 arg1) {
    char buf[0x100];
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_00442088(buf, D_0064EA80, arg1 & 0xFF);
    func_003547c0((s32 *)(temp_16 + 8), (u8 *)buf);
    *(s32 *)temp_16 = 0;
}


// FUN_00378220
s32 func_00378220(u8 *arg0) {
    return *(u32 *)(*(u8 **)(arg0 + 0x38)) != 0;
}


// FUN_00378240
s32 func_00378240(u8 *arg0) {
    return *(s32 *)(arg0 + 0x38) + 0x120;
}


// FUN_00378250
s32 func_00378250(u8 *arg0) {
    return *(s32 *)(arg0 + 0x38) + 0x1B0;
}


// FUN_00378260
void func_00378260(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    u8 *temp = *(u8 **)(arg0 + 0x38);
    temp[0x11C] = arg1;
    temp[0x11D] = arg2;
    temp[0x11E] = arg3;
    *(s32 *)(temp + 4) = arg4;
}


/* measured: retail's loop body uses the FPU accumulator idiom (adda.s $f2,$f3 /
   msuba.s $f6,$f0 / msub.s $f4,$f5,$f4 after the signed (3-i)/2 and (3-i)%2
   splits) which m2c marks M2C_ERROR; no C float spelling reproduces the
   ACC-fused instructions byte-for-byte (same floor as btlAICommand func_001de370
   and effBlurFilter func_004a8da0). The rest decodes cleanly: u8 arg1 stored to
   p[0x11F], p = *(u8**)(arg0+0x38), the (*(s32*)(p+4)!=0) branch loading
   iGpffff8308/iGpffff8218, the byte-to-float (x>>1)|(x&1) doubling idiom, the
   float-to-byte clamp via c.le.s 0x4F000000 with 0x80000000 or, and the
   4-iteration loop storing 0xFF/alpha to p[i*0x24+0x12C..]. FPU FMA-fusion
   floor. */
// FUN_00378280
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00378280);


// FUN_00378500
s32 func_00378500(u8 *arg0) {
    u8 *temp = *(u8 **)(arg0 + 0x38);
    if ((u8)(*(u32 *)temp != 0) != 0) {
        return *(u32 *)(*(u8 **)(temp + 0x14));
    }
    return 0;
}


// FUN_00378530
s32 func_00378530(s32 arg0, s32 arg1) {
    s32 var_2;

    switch (arg1) {
    case 0:
        return arg0;
    case 1:
        return arg0;
    case 2:
        return arg0;
    case 3:
        return arg0 * 2;
    case 4:
        if (arg0 < 6) {
            var_2 = arg0 * 6;
        } else {
            var_2 = arg0 * 3;
        }
        return var_2;
    default:
        func_0046d730(&D_0064EA20, 0x854);
        return 0;
    }
}
