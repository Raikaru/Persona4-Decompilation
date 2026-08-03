/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */
/* Original translation unit cmmScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

u16 func_00248b80();
extern void func_0029cf50(s32 arg0);

u16 func_00247270();

u16 func_002474f0();

extern s32 func_0029cc00(s32 arg0);
extern s32 func_00107930(s32 arg0);
extern s32 func_00109100(s32 arg0);
extern void func_001090c0(s32 arg0);

extern s32 func_001090e0(void);
extern void datResetTotalBtl(void);
extern void func_00106020(s32 arg0);

extern s16 func_001060b0(void);
extern s32 func_00249010(s32 arg0);
extern s32 func_00249230(s32 arg0);
extern s32 func_002492b0(s32 arg0);
extern s32 func_00249370(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_002494c0(s32 arg0, s32 arg1);

extern u8* func_00108dc0(void);
extern s32 func_00108e10(void);
extern void func_00108ef0(s32 arg0);
extern void func_00107bd0(s32 arg0);
extern void func_00108d80(void);
extern void func_00108cf0(u16 arg0);
extern s16 func_00248d80(s16 arg0);
extern s32 func_00249670(s32 arg0, s32 arg1);
extern s16 func_00247820(s16 arg0);
extern u8* func_002485e0(s32 arg0, u16 arg1);
extern s32 func_00249770(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0029d020(void);
extern void func_0025c230(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0025c310(void);
extern s32 func_00452380(void* arg0);
extern void func_0046d730(const void* file, s32 line);
extern void func_00452080(s32 handle);
extern s32 D_00635A78[];
extern s32 D_006359F0[];
extern s32 D_00635A20[];
extern s32 D_00635A00[];
extern s16 D_00635BB8[];
extern s32 D_00635B38[];
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00452490(s32 arg0);
extern void func_0046b0d0(u8* arg0);
extern void func_00454bd0(u8* arg0);
extern u8* func_00454a60(void* arg0, s32 arg1);
extern s32 func_004553c0(u8* arg0);
extern s32 func_00455f70(void* arg0, u32* arg1);
extern s32 func_0046af60(u32 arg0);
extern s32 func_0046a750(s32 arg0);
extern void func_00440b68(void* arg0, void* arg1, u32 arg2);
extern u8* func_00246cd0(s32 arg0);
extern void func_002483c0(s32 arg0);
extern s32 func_00109220(s32 arg0);
extern void func_0010d360(s32 arg0, void* arg1, s32* arg2);
extern void func_001029a0(s32 arg0, void* arg1, s32 arg2, s32 arg3);
extern s32 func_00102980(void);
extern s32 func_0029d030(void);
extern s32 func_0010d620(s16 arg0);
extern s8 func_002487e0(s32 arg0, s32 arg1);
extern s32 func_00246830(s32 arg0);
extern u8 func_00248760(s32 arg0);
extern s32 func_002438b0(s32 arg0);
extern s32 func_00246b10(s32 arg0);
extern s32 func_00107ac0(s32 arg0);
extern s32 func_00248040(s32 arg0);
extern s32 func_00110580(s32 arg0, s32* arg1, s32* arg2);
extern s32 func_002468a0(s32 arg0);
extern s32 func_001067f0(s32 arg0);
extern s32 func_002490b0(s32 arg0);
extern s32 func_00249180(s32 arg0);
extern void func_002784e0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00246c90(s32 arg0);
extern s32 func_00246d50(s32 arg0);
extern s32 func_001060c0(void);
extern s8 func_00110960(s32 arg0, s32 arg1);
extern s32 func_00106330(s32 arg0);
extern s32 func_003b7060(void);
typedef struct {
    s64 q;
    f32 f;
} bbSrc;

extern bbSrc D_00635A88[];
extern u8 D_00635AA0[];
extern u8 D_00635AC0[];
extern u8 D_00635AE0[];
extern u8 D_00635B00[];
extern u8 D_00635B20[];
extern u8 D_005DC7D0[];
extern s32 func_0025fe50(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern s32 func_0025ff60(s32 arg0);
extern void func_004b1250(s32 arg0, void* arg1);
extern u8* func_00246e90(s32 arg0);
extern s32 func_00249960(s32 arg0);
extern void func_00249a60(s32 arg0);
extern void func_00113480(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0045aeb0(s32 arg0, u8* arg1);
extern f32 func_0044b7b0(f32 arg0);
extern void func_004b14f0(s32 arg0, void* arg1);
extern void func_004b1420(s32 arg0, void* arg1);
extern void func_004b13f0(s32 arg0, void* arg1);
extern u16 D_008C024E[];
extern u8 D_00635B50[];
extern u8 D_00635B90[];
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
typedef struct {
    s64 q;
    f32 f;
} bbPair;

extern bbPair D_00635B68[];
extern bbPair D_00635B78[];
extern f32 iGpffff809c;
extern f32 iGpffff8084;
extern f32 iGpffff8094;
extern u8 D_00794E70[];
extern void func_0025ecd0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, void* arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13);
extern s32 func_00243840(s32 arg0);
extern void func_002782c0(s32 arg0, s32 arg1, s32 arg2, u32 arg3);
extern void func_00275980();
extern void func_00278450();
extern s32 iGpffffa658;
extern s32 iGpffffa62c;
extern u8* iGpffffb3d4;
extern s32 D_00635A40[];
extern s32 D_00635A60[];
extern s32 D_00635BA8[];
extern u8* func_00285af0(void);
extern void func_001104d0(s32 arg0, void* arg1, void* arg2);
extern u8* func_00246e10(u16 arg0);
extern s32 func_00104c70(s32 arg0);
extern s32 func_00247900(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00451fc0(void* arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4, s32 (*arg5)(void), void (*arg6)(void), void* arg7);
extern void func_0044ea90(const void* arg0, s32 arg1);
extern u8* (*D_008873F4[])(s32, s32, s32);
extern s32 func_0024f160(u8* arg0);
extern s32 func_0024f790(u8* arg0);
extern s32 func_0024b870(void);
extern void func_0024b990(void);
extern s32 func_0024c0e0(u8* arg0, u8* arg1);
extern s32 func_0024c460(u8 *arg0);
extern s32 func_0024d1f0(void);
typedef struct { f32 x, y, z, w; } Vec4f;

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

// FUN_0024A200
s32 func_0024a200(void)
{
    s32 a;
    s32 b;
    u8* p;
    u8* q2;
    u8* q3;
    u8* q;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    func_00108cf0(b);
    p = func_00108dc0();
    if (p == 0) {
        func_0046d730(D_006359F0, 0xE7);
    }
    q = func_002485e0(a & 0xFFFF, b & 0xFFFF);
    *(u8**)(p + 0x18) = q;
    if (q == 0) {
        func_0046d730(D_006359F0, 0xE9);
    }
    *(Vec4f*)(p + 8) = *(Vec4f*)(*(u8**)(p + 0x18));
    return 1;
}
typedef struct {
    u8 pad[0xC];
    s32 hi;
    s32 lo;
    u32 u;
} cmmMsgPack;

// FUN_0024A2E0
s32 func_0024a2e0(void)
{
    u8* p;
    u8* q2;
    u8* q3;
    s32 x;
    u32 u16val;
    u32 lo;
    cmmMsgPack pack1;
    cmmMsgPack pack2;

    p = func_00108dc0();
    if (p == 0) {
        func_0046d730(D_006359F0, 0x109);
    }
    x = *(s32*)(p + 0x1C);
    if (x == 0) {
        u16val = *(u16*)(p + 0x10);
        x = *(s32*)(p + 0xC);
        lo = x & 0xFFFF;
        pack1.hi = (u32)(x & 0xFFFF0000) >> 0x10;
        pack1.lo = lo;
        pack1.u = u16val;
        func_001029a0(0xA, &pack1, 0x1C, 2);
    } else if (x > 0xA) {
        u32 b;

        b = ~func_00102980() == 0;
        if (b) {
            if (*(u8*)(p + 0x13) != 0) {
            u8* q;

            q = *(u8**)(p + 0x18);
            *(u8**)(p + 0x18) = q + 0x10;
            *(Vec4f*)(p + 8) = *(Vec4f*)(q + 0x10);
            u16val = *(u16*)(p + 0x10);
            x = *(s32*)(p + 0xC);
            lo = x & 0xFFFF;
            pack2.hi = (u32)(x & 0xFFFF0000) >> 0x10;
            pack2.lo = lo;
            pack2.u = u16val;
            func_001029a0(0xA, &pack2, 0x1C, 2);
            *(s32*)(p + 0x1C) = 0;
        } else {
            func_00108d80();
                func_002483c0(*(u16*)(p + 0));
                return 1;
            }
        }
    }
    *(s32*)(p + 0x1C) += 1;
    return 0;
}
// FUN_0024A450
s32 func_0024a450(void)
{
    u8* p;
    u8* q2;
    u8* q3;

    p = func_00108dc0();
    if (p != 0) {
        func_0029cf50(p[0xA]);
    }
    return 1;
}

/* measured: b210 at -O2 CSEs `a & 0xFFFF` across the 9 call sites into
   callee-saved copies (frame 0xF0, sq $18/$19); retail re-ANDIs into $a0
   per site with a 0xD0 frame. optimization_level 1 (scoped back to 2)
   restores the per-site andi, and then the s8 return of func_002487e0
   must be held in an s32 local (an s8/u8 local makes level-1 codegen
   emit a redundant `move` around the dsll32/dsra32 sign-extension). */
// FUN_0024A490
#pragma optimization_level 1

s32 func_0024a490(void)
{
    s32 a;
    s32 r;
    u8 buf[0x80];
    s32 tbl[7];
    s32 b;
    s32 idx;
    s32 i;
    s32 tmp;
    s32* src;
    s32* dst;

    a = func_0029cc00(0);
    if (a == 0) {
        a = func_00108e10() & 0xFFFF;
    }
    r = func_0029d030();
    if (r < 0) {
        func_0046d730(D_006359F0, 0x140);
    }
    b = func_002487e0(a & 0xFFFF, 0);
    if (b != 0) {
        func_00278450(r, 0, func_0010d620((s16)b));
    }
    func_00275980(func_00246830(a & 0xFFFF), buf, 0x80);
    func_00278450(r, 1, buf);
    func_00278450(r, 2, func_002438b0(func_00248760(a & 0xFFFF)));
    func_00275980(func_00246b10((s8)func_00248760(a & 0xFFFF)), buf, 0x80);
    func_00278450(r, 3, buf);
    func_002782c0(r, 4, func_00107ac0(a & 0xFFFF) & 0xFFFF, 0);
    b = func_00247820((s16)a);
    if (b != 0) {
        func_00278450(r, 5, func_00109220(b & 0xFFFF));
    }
    idx = func_00248040(func_001060b0());
    if (idx != 0) {
        src = D_00635A00;
        dst = tbl;
        i = 7;
        do {
            tmp = *src++;
            i--;
            *dst++ = tmp;
        } while (i > 0);
        func_00275980(tbl[func_00110580(idx, dst, src)], buf, 0x80);
        func_00278450(r, 6, buf);
    }
    func_00275980(func_002468a0(a & 0xFFFF), buf, 0x80);
    func_00278450(r, 7, buf);
    return 1;
}
/* measured: retail loads the iGpffffb3d4 base at the top of the
   if-block, computes a*14 into $v0 (sll 3/subu/sll 1) and addu $v0,$v1;
   mwcc b210 sinks the base load after the multiply, colors the multiply
   result $v1 (sll $v1,$v0,1), and in the i<3 loop emits addiu $a2,gp
   before move $a0,$s1 where retail emits the move first. Tried: named
   base/off locals in both declaration orders, inline (a*14)+base,
   base+a*14, 3+base+a*14, named pointer q = base + a*14, (u16)a, j=i+2
   loop temp. All give the identical nd 6 (4 load-sink/coloring + 2 loop
   arg order) — the documented load-sinking floor, same as FUN_0024A8B0. */

/* Closes the measured optimization_level 1 scope opened above; -O2 is the
   baseline everywhere else in this translation unit. */
#pragma optimization_level 2
// FUN_0024A710
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a710);
/* measured: -O2 CSEs `temp_18 & 0xFFFF` into a callee-saved copy (andi $s0);
   level 1 restores the per-site andi. The base hoist (u8 *base = iGpffffb3d4)
   reproduces retail's load-first-into-$v1 and the integer-domain add
   ((u32)off + (u32)base) reproduces the index-first addu $v0,$v0,$v1. */
// FUN_0024A8B0
#pragma optimization_level 1

s32 func_0024a8b0(void)
{
    s32 sp5C;
    u16 sp40[0xE];
    s32 temp_18;
    s32 temp_2;
    s32 var_16;
    s32 var_16_2;

    temp_18 = func_0029cc00(0);
    temp_2 = func_0029d030();
    if (temp_2 < 0) {
        func_0046d730(&D_006359F0, 0x190);
    }
    if (temp_18 != 0) {
        u8 *base = iGpffffb3d4;
        s32 off = temp_18 * 14;
        func_002782c0(temp_2, 0, *(u8 *)((u32)off + (u32)base + 3), 0);
        func_00278450(temp_2, 1, func_00109220(temp_18 & 0xFFFF));
        for (var_16 = 0; var_16 < 3; var_16++) {
            func_00278450(temp_2, var_16 + 2, &iGpffffa62c);
        }
        func_0010d360(temp_18 & 0xFFFF, sp40, &sp5C);
        for (var_16_2 = 0; var_16_2 < sp5C; var_16_2++) {
            func_00278450(temp_2, var_16_2 + 2, func_00243840(sp40[var_16_2]));
        }
    }
    func_0029cf50(temp_18);
    return 1;
}
#pragma optimization_level 2
// FUN_0024AA10
s32 func_0024aa10(void)
{
    s32 temp_2;

    temp_2 = func_0029cc00(0);
    if (temp_2 == 0) {
        temp_2 = func_00108e10() & 0xFFFF;
    }
    func_00108ef0(temp_2 & 0xFFFF);
    return 1;
}
// FUN_0024AA60
s32 func_0024aa60(void)
{
    s32 temp_16;
    s32 temp_2;

    temp_16 = func_0029cc00(0);
    temp_2 = func_0029cc00(1);
    if (temp_2 == 0) {
        temp_2 = func_00108e10() & 0xFFFF;
    }
    if (func_002485e0(temp_16 & 0xFFFF, temp_2 & 0xFFFF) != 0) {
        func_0029cf50(1);
    } else {
        func_0029cf50(0);
    }
    return 1;
}
// FUN_0024AAF0
s32 func_0024aaf0(void)
{
    s32 temp_2;

    temp_2 = func_0029cc00(0);
    if (temp_2 == 0) {
        func_00108d80();
    } else {
        func_00108cf0(temp_2 & 0xFFFF);
    }
    return 1;
}




// FUN_0024AB40
u32 func_0024AB40(void)
{
    u16 uVar1;

    uVar1 = func_00248b80();
    func_0029cf50(uVar1);
    return 1;
}

// FUN_0024AB70
s32 func_0024ab70(void)
{
    s32 temp_2;
    s32 r;

    temp_2 = func_0029cc00(0);
    if (temp_2 == 0) {
        temp_2 = func_00108e10() & 0xFFFF;
    }
    r = func_00247820((s16)temp_2);
    if (r != 0) {
        func_0029cf50(r);
    } else {
        func_0029cf50(0);
    }
    return 1;
}




// FUN_0024ABF0
u32 func_0024ABF0(void)
{
    u16 uVar1;

    uVar1 = func_00247270();
    func_0029cf50(uVar1);
    return 1;
}



// FUN_0024AC20
u32 func_0024AC20(void)
{
    u16 uVar1;

    uVar1 = func_002474f0();
    func_0029cf50(uVar1);
    return 1;
}

// FUN_0024AC50
s32 func_0024ac50(void)
{
    s32 temp_2;

    temp_2 = func_0029cc00(0);
    if (temp_2 == 0) {
        temp_2 = func_00108e10() & 0xFFFF;
    }
    func_00107bd0(temp_2 & 0xFFFF);
    return 1;
}
// FUN_0024ACA0
s32 func_0024aca0(void)
{
    func_0029cf50(func_00248d80((s16)(func_0029cc00(0) & 0xFFFF)));
    return 1;
}




// FUN_0024ACF0
s32 func_0024acf0(void)
{
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    func_0029cf50(0);
    if ((temp_16 != 0) && (temp_16 != 1)) {
        return 1;
    }
    func_0029cf50(func_00107930(temp_16));
    return 1;
}



// FUN_0024AD70
s32 func_0024ad70(void)
{
    func_001090c0(func_00109100(func_0029cc00(0) & 0xFFFF));
    return 1;
}



// FUN_0024ADB0
s32 func_0024adb0(void)
{
    s32 temp_2;

    temp_2 = func_001090e0();
    func_0029cf50(temp_2);
    datResetTotalBtl();
    func_00106020(temp_2);
    return 1;
}



// FUN_0024AE00
s32 func_0024ae00(void)
{
    func_0029cf50(func_00109100(func_0029cc00(0) & 0xFFFF));
    return 1;
}



// FUN_0024AE40
s32 func_0024ae40(void)
{
    func_0029cf50(func_00249010(func_001060b0()));
    return 1;
}



// FUN_0024AE80
s32 func_0024ae80(void)
{
    func_0029cf50(func_00249230(func_001060b0()) != 0);
    return 1;
}



// FUN_0024AEC0
s32 func_0024aec0(void)
{
    func_0029cf50(func_002492b0(func_001060b0()) != 0);
    return 1;
}



// FUN_0024AF00
s32 func_0024af00(void)
{
    s32 temp_16;
    s32 temp_17;

    temp_16 = func_0029cc00(0);
    temp_17 = func_0029cc00(1);
    func_0029cf50(0);
    if ((temp_17 != 0) && (temp_17 != 1)) {
        return 1;
    }
    if (temp_16 == 0) {
        func_0029cf50(func_00249370(0, func_001060b0(), temp_17));
    } else {
        func_0029cf50(func_00249370(1, func_001060b0(), temp_17));
    }
    return 1;
}



// FUN_0024AFE0
s32 func_0024afe0(void)
{
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    func_0029cf50(0);
    if ((temp_16 != 0) && (temp_16 != 1)) {
        return 1;
    }
    func_0029cf50(func_002494c0(func_001060b0(), temp_16));
    return 1;
}

// FUN_0024B070
s32 func_0024b070(void)
{
    s32 a;
    s32 r;
    s32 x;
    u8 buf[0x80];
    u8* p;
    u8* q2;
    u8* q3;

    a = func_0029cc00(0);
    x = func_001060b0();
    if (a == 0) {
        a = func_002490b0(x);
    } else {
        a = func_00249180(x);
    }
    if (a == 0) {
        func_0046d730(D_006359F0, 0x27A);
    }
    r = func_0029d030();
    if (r < 0) {
        func_0046d730(D_006359F0, 0x27D);
    }
    func_00278450(r, 0, func_001067f0(*(s16*)(a + 4)));
    func_00278450(r, 2, func_001067f0(*(s16*)(a + 8)));
    func_00278450(r, 4, func_001067f0(*(s16*)(a + 0x14)));
    func_00278450(r, 6, func_001067f0(*(s16*)(a + 0x18)));
    func_002784e0(r, 0xE, *(u16*)(a + 4));
    func_002784e0(r, 0xF, *(u16*)(a + 8));
    func_002784e0(r, 0x10, *(u16*)(a + 0x14));
    func_002784e0(r, 0x11, *(u16*)(a + 0x18));
    func_002782c0(r, 1, *(s16*)(a + 6), 0);
    func_002782c0(r, 3, *(s16*)(a + 0xA), 0);
    func_002782c0(r, 5, *(s16*)(a + 0x16), 0);
    func_002782c0(r, 7, *(s16*)(a + 0x1A), 0);
    func_002782c0(r, 8, *(u32*)(a + 0xC), 0);
    func_002782c0(r, 9, *(u32*)(a + 0x1C), 0);
    p = (u8*)func_00246c90(*(u16*)(a + 0x12));
    if (p != 0) {
        func_00275980(p, buf, 0x80);
        func_00278450(r, 0xA, buf);
    }
    p = (u8*)func_00246c90(*(u16*)(a + 0x22));
    if (p != 0) {
        func_00275980(p, buf, 0x80);
        func_00278450(r, 0xB, buf);
    }
    p = (u8*)func_00246d50(*(u16*)(a + 0x10));
    if (p != 0) {
        func_00275980(p, buf, 0x80);
        func_00278450(r, 0xC, buf);
    }
    p = (u8*)func_00246d50(*(u16*)(a + 0x20));
    if (p != 0) {
        func_00275980(p, buf, 0x80);
        func_00278450(r, 0xD, buf);
    }
    return 1;
}
// FUN_0024B380
s32 func_0024b380(void)
{
    s32 temp_18;
    s32 temp_17;
    s32 temp_16;

    temp_18 = func_0029cc00(0);
    temp_17 = func_0029cc00(1);
    temp_16 = func_0029cc00(2);
    if (func_0029d020() == 0) {
        func_0025c230(0, temp_18, temp_17, temp_16);
        goto block_4;
    }
    if (func_0025c310() == 0) {
        return 1;
    }
block_4:
    return 0;
}
// FUN_0024B430
s32 func_0024b430(void)
{
    s32 temp_16;
    s32 temp_17;

    temp_16 = func_0029cc00(0);
    temp_17 = func_0029cc00(1);
    func_0029cf50(func_00249670(temp_16, temp_17));
    return 1;
}
/* measured: -O2 CSEs `a & 0xFFFF` into callee-saved copies (frame 0xF0);
   level 1 restores the per-site andi/0xD0 frame. Loop temps need decl
   order src, dst, i (first-declared -> $a1 at level 1) and the s8 loads
   need an s32 local (s8 adds a move + dsll32/dsra32 re-extension). */
// FUN_0024B490
#pragma optimization_level 1

s32 func_0024b490(void)
{
    s32 r;
    s32 a;
    u8 buf[0x80];
    s32 tbl[5];
    u8* q;
    s32* src;
    s32* dst;
    s32 i;
    s32 tmp;
    s32 b;

    a = func_0029cc00(0);
    src = D_00635A20;
    dst = tbl;
    i = 5;
    do {
        tmp = *src++;
        i--;
        *dst++ = tmp;
    } while (i > 0);
    r = func_0029d030();
    if (r < 0) {
        func_0046d730(D_006359F0, 0x2DC);
    }
    q = (u8*)func_00246cd0(a & 0xFFFF) + 0xC;
    if (q != 0) {
        func_00275980(q, buf, 0x80);
        func_00278450(r, 0, buf);
    }
    func_002782c0(r, 1, *(s32*)(func_00246cd0(a & 0xFFFF) + 4), 0);
    q = (u8*)func_00246cd0(a & 0xFFFF) + 0x22;
    if (q != 0) {
        func_00275980(q, buf, 0x80);
        func_00278450(r, 2, buf);
    }
    b = *(s8*)(func_00246cd0(a & 0xFFFF) + 8);
    if (b != -1) {
        func_00275980(tbl[b], buf, 0x80);
        func_00278450(r, 3, buf);
    }
    func_002782c0(r, 4, *(s8*)(func_00246cd0(a & 0xFFFF) + 9), 0);
    b = *(s8*)(func_00246cd0(a & 0xFFFF) + 0xA);
    if (b != -1) {
        func_00275980(tbl[b], buf, 0x80);
        func_00278450(r, 5, buf);
    }
    func_002782c0(r, 6, *(s8*)(func_00246cd0(a & 0xFFFF) + 0xB), 0);
    return 1;
}
#pragma optimization_level 2
// FUN_0024B6A0
s32 func_0024b6a0(void)
{
    s32 temp_17;
    s32 temp_16;
    s32 temp_2;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    temp_2 = func_0029cc00(2);
    func_0029cf50(func_00249770(temp_17, temp_16, temp_2));
    return 1;
}
// FUN_0024B720
s32 func_0024b720(void)
{
    s32 a;
    s32 b;
    u8* p;
    u8* q2;
    u8* q3;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    if (a == 0) {
        func_0046d730(D_006359F0, 0x30A);
    }
    p = func_00246cd0(a & 0xFFFF);
    if (p == 0) {
        func_0046d730(D_006359F0, 0x30C);
    }
    switch (b) {
    case 0:
        func_0029cf50(*(s32*)(p + 4));
        break;
    case 1:
        func_0029cf50(*(s8*)(p + 8));
        break;
    case 2:
        func_0029cf50(*(s8*)(p + 0xA));
        break;
    case 3:
        func_0029cf50(*(s32*)(p + 0));
        break;
    case 4:
        func_0029cf50(*(s8*)(p + 9));
        break;
    case 5:
        func_0029cf50(*(s8*)(p + 0xB));
        break;
    default:
        func_0046d730(D_006359F0, 0x321);
        break;
    }
    return 1;
}
// FUN_0024B870
s32 func_0024b870(void)
{
    s32* s0;
    s32 sp2c;
    s32 temp;
    s32 state;

    s0 = (s32*)func_00452560();
    state = s0[1];
    switch (state) {
    case 0:
        s0[1] = 1;
    case 1:
        s0[1] = 2;
        func_00440b68(&iGpffffa658, D_006359F0, 0x35D);
        s0[2] = (s32)func_00454a60(D_00635A40, 1);
    case 2:
        if (func_004553c0((u8*)s0[2]) != 0) {
            s0[1] = 3;
            s0[0] |= 1;
        }
        break;
    case 3:
        s0[1] = 4;
        temp = func_00455f70(D_00635A60, (u32*)&sp2c);
        if (temp != 0) {
            s0[9] = func_0046af60(temp);
        }
    case 4:
        if (func_0046a750(s0[9]) != 0) {
            s0[1] = 5;
        }
        break;
    case 5:
        break;
    }
    return 0;
}
// FUN_0024B990
void func_0024b990(void)
{
    u8* p;
    u8* q2;
    u8* q3;
    s32 h;
    s32 i;
    s32 x;

    p = (u8*)func_00452560();
    for (i = 0; i < 5; i++) {
        h = *(s32*)(p + i * 4 + 0xC);
        if (h != 0) {
            if (func_00452490(h) != 0) {
                func_00452080(h);
            }
        }
    }
    x = *(s32*)(p + 0x24);
    if (x != 0) {
        func_0046b0d0((u8*)x);
        *(s32*)(p + 0x24) = 0;
    }
    func_00454bd0((u8*)*(s32*)(p + 0x8));
    DAT_008873ec_abs[0](p);
}
// FUN_0024BA60
void func_0024ba60(s32 arg0)
{
    s32 p;
    s32* q;

    p = func_00452380(D_00635A78);
    if (arg0 < 0 || arg0 >= 5) {
        func_0046d730(D_006359F0, 0x3B2);
    }
    if (p != 0) {
        q = (s32*)((int)func_00452560(p) + arg0 * 4 + 0xC);
        if (q[0] != 0) {
            func_00452080(q[0]);
            q[0] = 0;
        }
    }
}
/* measured: everything matches except two b210 codegen choices. (1) The
   12-byte global->stack copy (ld D_00635A88 + lwc1 D_00635A90 -> sd + swc1)
   is emitted by retail as loads-batched-then-stores with ONE shared lui;
   b210 either stores the s64 between the loads or re-materialises the lui
   (tried struct assignment, s64/f32 locals in both orders, bbSrc member
   loads). (2) The entry index `addu $v0,$v0,$s0` (scaled index first, per
   m2c temp_16[arg0]) is emitted base-first by b210 across every spelling
   (p+arg0*4, arg0*4+p, &p[arg0], s32 off local + byte-ptr cast). Best nd 7,
   no further source lever. Scheduling/operand-order floor. */
// FUN_0024BB00
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024bb00);
/* measured: float conversion recipe works (single bltz per arm, c.ole.s for the
   final (s32) conversion, (f32)(s32)((u32)x>>1|(x&1)) + doubling). But the
   register allocation is stuck: my candidate needs 6 saved registers
   ($s0-$s4: var_19_2 -> $s2 early, var_18 -> $s3, temp_19 -> $s4) while retail
   reuses $s3 for temp_19 then var_19_2 then var_19 (5 regs, frame 0x60). Tried
   6 declaration orders (m2c order, temp_19 first/last, var_19_2 after temp_19,
   retail first-use order) -- all nd 127, frame 0x70 (obj 676B vs window 672B).
   Saved-register rotation floor. */
// FUN_0024BE40
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024be40);
/* measured: the (u8)(s32)f1 colour conversion needs the explicit
   if (2.1474836e9f > f1) { cb = (u8)(s32)f1; } else { ... | 0x80000000; }
   form to reproduce retail's per-arm andi and c.ole.s/bc1t, but b210 then
   keeps the (s32)f1 mfc1 intermediate in $v0/$v1 and re-masks into $a1
   where retail coalesces the whole chain into $a1 (tried u8/s32 locals,
   inline casts, & 0xFF, decl positions -- best nd 15, all else matching).
   Also the f17 mov.s is scheduled after the $11 address load (retail has
   it before) at all 3 call sites. Register/scheduling floor. */
// FUN_0024C0E0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024c0e0);
/* measured: the func_0025ecd0 calls use H1 FPU FMA chains (adda.s seeds the
   accumulator, then msub.s f13 = ACC - f1*f20; e.g. arg10 = 139.0f - 5.0f*f20)
   that m2c couldn't decode (M2C_ERROR). Writing the natural C
   (139.0f - 5.0f*var_f20, 433.0f-60.0f*temp_f21, etc.) compiles to mul.s/sub.s
   instead, and needs 4 saved FP regs ($f20-$f23) vs retail's 2 ($f20,$f21);
   obj 3784B vs window 3472B. FMA + FP-register-pressure floor; the gp floats
   were identified (iGpffff8094 = -0x7F6C, iGpffff809c = -0x7F64) and the
   struct offsets (0x0/0x8/0xC/0xE/0x10) are confirmed. */
// FUN_0024C460
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024c460);
/* measured: same H1 FPU FMA floor as FUN_0024C460 -- the func_0025ecd0 calls
   here use adda.s/madd.s chains (m2c M2C_ERROR) inside a branching value-range
   scan (0..5/5..0xF/0xF..0x14/0x14..0x1E). Not attempted: the FMA chain is
   undecodable by m2c and the branch structure (7600 B window) multiplies the
   register-pressure surface. Assessed as the same floor family. */
// FUN_0024D1F0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024d1f0);
typedef struct cmmScriptEntry {
    u32 flags;                 /* 0x00 */
    u32 unk4;                  /* 0x04 */
    u32 unk8;                  /* 0x08 */
    u16 unkC;                  /* 0x0C */
    u16 padE;                  /* 0x0E */
    u32 unk10;                 /* 0x10 */
    s32 (*func)(void*, void*); /* 0x14 */
} cmmScriptEntry;

// FUN_0024EFA0
s32 func_0024efa0(void)
{
    cmmScriptEntry* p;
    cmmScriptEntry* q;
    s32 i;

    p = (cmmScriptEntry*)func_00452560();
    q = p;
    i = 0;
    while (i < 3) {
        if ((q->flags & 1) != 0) {
            if (q->func(p, q) != 0) {
                q->flags = q->flags & ~1;
            }
        }
        q++;
        i++;
    }
    return 0;
}



#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0024F040
void func_0024f040(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}

// FUN_0024F080
void func_0024f080(s32 arg0, s32 arg1)
{
    cmmScriptEntry* e;
    s32 p;

    p = func_00452380(D_00635B38);
    if (p == 0) {
        func_0046d730(D_006359F0, 0x67E);
    }
    e = (cmmScriptEntry*)func_00452560(p) + arg0;
    e->flags |= 1;
    e->unk8 = 0;
    e->unk4 = 0;
    e->unkC = 0;
    e->unk10 = 0;
    if (arg1 == 0) {
        e->flags = e->flags & ~2;
        e->flags = e->flags | 4;
    } else {
        e->flags = e->flags & ~4;
        e->flags = e->flags | 2;
    }
}
/* measured: b210's optimizer miscompiles the int->float idiom
   `(f32)((u32)x >> 1 | (x & 1))` + doubling in this function's FP context:
   it splits the else-path into a dead defensive `bltz` on the (always
   non-negative) or-result and puts the add.s doubling in the unreachable
   fixup block, leaving the taken path undoubled and $f1 unset. Tried the
   two-statement x+x form, 2.0f* single statement, u32 locals, x+x as one
   expression, and inverted if/else -- all reproduce the split (best nd 248,
   object 48B over window). Also persists: r19 gets $s2 instead of $s3 and
   the unkC sh is scheduled after the dsll32/dsra32 re-extension. Optimizer
   floor. */
// FUN_0024F160
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024f160);
/* measured: the 12-byte D_00635B68/D_00635B70 copy pairs (ld+lwc1 batched,
   then sd+swc1 into 16-byte slots at 0x70/0x60) defeat b210: as separate
   locals the f32 halves get dead-store-eliminated, as a { s64 q; f32 f; }
   struct assignment they over-read via ld+ld, and the r0/r1/r2 slots then
   pack into the struct tail gaps (r2 at 0x7C vs retail 0x58). Tried decl
   orders, bbPair struct copies, member-wise copies -- best nd 412 with the
   frame otherwise exact. Also blocked downstream by the nested-context
   `(u32)x >> 1 | (x & 1)` + doubling split (see FUN_0024F160). */
// FUN_0024F790
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024f790);
// FUN_0024FF60
s32 func_0024ff60(void)
{
    cmmScriptEntry* e;
    s32 handle;
    s32 st;

    e = (cmmScriptEntry*)func_00452560();
    switch (e->unk4) {
    case 0:
        e->unk4 = 1;
    case 1:
        e->unk4 = 2;
    case 2:
        handle = func_00452380(D_00635A78);
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x392);
        }
        st = (((cmmScriptEntry*)func_00452560(handle))->flags & 1) != 0;
        if (st) {
            e->unk4 = 3;
        }
        break;
    case 3:
        st = e->flags;
        if (st & 1) {
            e->flags = st & ~1;
            e->unk4 = 4;
        } else if (st & 2) {
            e->flags = st & ~2;
            e->unk4 = 6;
        }
        break;
    case 4:
        e->unk4 = 5;
        e->unk8 = 0;
    case 5:
        if (func_0024f160((u8*)e) != 0) {
            e->unk4 = 3;
        }
        break;
    case 6:
        e->unk4 = 7;
        e->unk8 = 0;
    case 7:
        if (func_0024f790((u8*)e) != 0) {
            e->unk4 = 3;
        }
        break;
    }
    return 0;
}

// FUN_002500E0
void func_002500e0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}

// FUN_00250120
s32 func_00250120(void)
{
    s32 i;
    s32 handle;
    u8* p;
    u8* q2;
    u8* q3;
    u8* e;

    handle = func_00452380(D_00635BA8);
    if (handle != 0) {
        func_00452080(handle);
    }
    if (func_00452380(D_00635A78) == 0) {
        p = func_00285af0();
        if (func_00452380(D_00635A78) == 0) {
            func_0044ea90(D_006359F0, 0x402);
            e = D_008873F4[0](1, 0x28, 0x40000);
            *(s32*)(e + 4) = 0;
            func_00451fc0(p, D_00635A78, 0xF, 0, 0, func_0024b870, func_0024b990, e);
        }
    }
    p = func_00285af0();
    handle = func_00452380(D_00635B38);
    if (handle != 0) {
        func_00452080(handle);
    }
    func_0044ea90(D_006359F0, 0x66C);
    e = D_008873F4[0](1, 0x5C, 0x40000);
    *(s32*)(e + 0x14) = (s32)func_0024c0e0;
    *(s32*)(e + 0x2C) = (s32)func_0024c460;
    *(s32*)(e + 0x44) = (s32)func_0024d1f0;
    func_00451fc0(p, D_00635B38, 0xF, 0, 0, func_0024efa0, func_0024f040, e);
    for (i = 0; i < 5; i++) {
        func_0024ba60(i);
    }
    return 1;
}

// FUN_002502F0
s32 func_002502f0(void)
{
    u8* p;
    u8* q2;
    u8* q3;
    cmmScriptEntry* e;
    s32 handle;
    s32 st;
    s32 ret;

    if (func_0029d020() == 0) {
        p = func_00285af0();
        if (func_00452380(D_00635BA8) == 0) {
            if (func_00452380(D_00635A78) == 0) {
                if (func_00452380(D_00635A78) == 0) {
                    func_0044ea90(D_006359F0, 0x402);
                    e = (cmmScriptEntry*)D_008873F4[0](1, 0x28, 0x40000);
                    e->unk4 = 0;
                    func_00451fc0(p, D_00635A78, 0xF, 0, 0, func_0024b870, func_0024b990, e);
                }
            }
            func_0044ea90(D_006359F0, 0x81D);
            e = (cmmScriptEntry*)D_008873F4[0](1, 0x24, 0x40000);
            e->unk4 = 0;
            func_00451fc0(p, D_00635BA8, 0xF, 0, 0, func_0024ff60, func_002500e0, e);
        }
        handle = func_00452380(D_00635BA8);
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x82A);
        }
        e = (cmmScriptEntry*)func_00452560(handle);
        e->flags |= 1;
    } else {
        handle = func_00452380(D_00635BA8);
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x83E);
        }
        e = (cmmScriptEntry*)func_00452560(handle);
        st = e->flags;
        if (st & 4) {
            if (st & 0x10) {
                ret = 2;
            } else if (st & 0x20) {
                ret = 3;
            } else {
                ret = 1;
            }
        } else {
            ret = 0;
        }
        if (ret != 0) {
            func_0029cf50(ret - 1);
            func_00452080(func_00452380(D_00635BA8));
            return 1;
        }
    }
    return 0;
}
// FUN_00250560
s32 func_00250560(void)
{
    u8* p;
    u8* q2;
    u8* q3;
    cmmScriptEntry* e;
    s32 handle;
    s32 st;
    s32 ret;

    if (func_0029d020() == 0) {
        p = func_00285af0();
        if (func_00452380(D_00635BA8) == 0) {
            if (func_00452380(D_00635A78) == 0) {
                if (func_00452380(D_00635A78) == 0) {
                    func_0044ea90(D_006359F0, 0x402);
                    e = (cmmScriptEntry*)D_008873F4[0](1, 0x28, 0x40000);
                    e->unk4 = 0;
                    func_00451fc0(p, D_00635A78, 0xF, 0, 0, func_0024b870, func_0024b990, e);
                }
            }
            func_0044ea90(D_006359F0, 0x81D);
            e = (cmmScriptEntry*)D_008873F4[0](1, 0x24, 0x40000);
            e->unk4 = 0;
            func_00451fc0(p, D_00635BA8, 0xF, 0, 0, func_0024ff60, func_002500e0, e);
        }
        handle = func_00452380(D_00635BA8);
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x834);
        }
        e = (cmmScriptEntry*)func_00452560(handle);
        e->flags |= 2;
    } else {
        handle = func_00452380(D_00635BA8);
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x84E);
        }
        e = (cmmScriptEntry*)func_00452560(handle);
        st = e->flags;
        if (st & 8) {
            if (st & 0x80) {
                ret = 2;
            } else {
                ret = 1;
            }
        } else {
            ret = 0;
        }
        if (ret != 0) {
            func_0029cf50(ret - 1);
            func_00452080(func_00452380(D_00635BA8));
            return 1;
        }
    }
    return 0;
}
// FUN_002507C0
s32 func_002507c0(void)
{
    s32 i;

    if (func_0029d020() == 0) {
        func_0024f080(2, 0);
        for (i = 0; i < 5; i++) {
            func_0024ba60(i);
        }
        goto ret0;
    }
    if (func_0029d020() < 30) {
        goto ret0;
    }
    func_0045aac0(2, 0, 0x1E);
    return 1;
ret0:
    return 0;
}
// FUN_00250870
s32 func_00250870(void)
{
    s16 buf[6];
    s16* s;
    s16* d;
    s32 i;
    s32 p;
    u8* r;
    s32 idx;

    s = D_00635BB8;
    d = buf;
    i = 3;
    do {
        s16 a = s[0];
        s16 b = s[1];
        s += 2;
        i--;
        d[0] = a;
        d[1] = b;
        d += 2;
    } while (i > 0);
    p = func_00452380(D_00635A78);
    r = (u8*)func_00452560(p);
    if (r == 0) {
        func_0046d730(D_006359F0, 0x41B);
    }
    idx = *(s32*)(r + 0x20);
    if (idx >= 6) {
        func_0046d730(D_006359F0, 0x8A9);
    }
    func_0029cf50(buf[idx]);
    return 1;
}
// FUN_00250940
s32 func_00250940(void)
{
    s32 b;
    s32 a;
    u8* p;
    u8* q2;
    u8* q3;
    s32 out1;
    s32 out2;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    func_001104d0(func_001060b0(), &out1, &out2);
    p = func_00246e10(*(u16*)&out1);
    if (p == 0) {
        func_0046d730(D_006359F0, 0x8B8);
    }
    if (b < 0 || !(b <= 3)) {
        func_0046d730(D_006359F0, 0x8B9);
    }
    switch (b) {
    case 0: {
        s32 idx = a * 12;
        func_0029cf50(*(u16*)(idx + (s32)p + 0x18));
        break;
    }
    case 1: {
        s32 idx = a * 12;
        func_0029cf50(*(u16*)(idx + (s32)p + 0x1A));
        break;
    }
    case 2: {
        s32 idx = a * 12;
        func_0029cf50(*(s32*)(idx + (s32)p + 0x1C));
        break;
    }
    case 3: {
        s32 idx = a * 12;
        func_0029cf50(*(s32*)(idx + (s32)p + 0x20));
        break;
    }
    }
    return 1;
}

