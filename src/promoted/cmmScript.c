/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */
/* Original translation unit cmmScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
#include "type.h"

extern u8 *func_00452380(s8 *name);
extern u32 func_00452560(void *task);
extern void func_004b1250(void *model, f32 *position);
extern s32 func_0045aeb0(s16 channel, const char *name);
extern s32 func_0045af60(s16 channel, s16 stream, s16 arg2, s16 arg3);
extern void func_0046d730(void *file, s32 line);

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
extern void H_Cdvd_Destroy(u8* arg0);
extern u8* func_00454a60(void* arg0, s32 arg1);
extern s32 H_Cdvd_IsFileLoaded(u8* arg0);
extern s32 func_00455f70(void* arg0, u32* arg1);
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
extern s64 func_00248760(s32 arg0);
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
extern s32 datGetFlag(s32 arg0);
extern u32 RpRandom(void);


extern u8 D_00635A88[];
extern u8 D_00635AA0[];
extern u8 D_00635AC0[];
extern u8 D_00635AE0[];
extern u8 D_00635B00[];
extern u8 D_00635B20[];
extern u8 D_005DC7D0[];
extern s32 func_0025fe50(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern s32 func_0025ff60(s32 arg0);
extern u8* func_00246e90(s32 arg0);
extern s32 func_00249960(s32 arg0);
extern void func_00249a60(s32 arg0);
extern void func_00113480(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern f32 sinf(f32 arg0);
extern void func_004b14f0(s32 arg0, void* arg1);
extern void func_004b1420(s32 arg0, void* arg1);
extern void func_004b13f0(s32 arg0, void* arg1);
extern u16 D_008C024E[];
extern u8 D_00635B50[];
extern u8 D_00635B90[];
typedef struct {
    f32 value[3];
} CmmFishingPosition;

/* Both retail origin objects begin on eight-byte boundaries. Only the
   three-coordinate value participates in the copied position. */
typedef union {
    CmmFishingPosition value;
    s64 alignment;
} CmmFishingOrigin;

extern CmmFishingOrigin D_00635B68;
extern CmmFishingOrigin D_00635B78;
extern f32 iGpffff809c;
extern f32 iGpffff8084;
extern f32 iGpffff8094;
extern u8 D_00794E70[];
extern s32 func_0025ecd0(f32 farg0, f32 farg1, f32 farg2,
                         s32 arg0, u8 arg1, s32 arg2, void* arg3,
                         s32 arg4, s16 arg5, s16 arg6,
                         f32 farg3, f32 farg4, f32 farg5, void* arg7);
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

extern void func_0044ea90(const void* arg0, s32 arg1);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 func_0024f160(u8* arg0);
extern s32 func_0024f790(u8* arg0);
extern s32 func_0024b870(u8 *task);
extern void func_0024b990(u8 *task);
extern s32 func_0024c0e0(u8* arg0, u8* arg1);
extern s32 func_0024c460(u8* arg0, u8* arg1);
extern s32 func_0024d1f0(u8* arg0, u8* arg1);
typedef struct { f32 x, y, z, w; } Vec4f;

typedef int (*code)();
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
    func_00278450(r, 2, func_002438b0((u8)func_00248760(a & 0xFFFF)));
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

/* Closes the measured optimization_level 1 scope opened above; -O2 is the
   baseline everywhere else in this translation unit. */
#pragma optimization_level 2
// FUN_0024A710
/* measured: -O2 CSEs `temp_18 & 0xFFFF` into a callee-saved copy and sinks
   the iGpffffb3d4 base load past the multiply (nd 287, object 428 of 416);
   level 1 restores the per-site andi and retail's load-first order. Same
   recipe as FUN_0024A8B0 below, including the integer-domain
   ((u32)off + (u32)base) add. */
#pragma optimization_level 1
s32 func_0024a710(void)
{
    s32 sp5C;
    u16 sp40[0xE];
    s32 temp_18;
    s32 temp_16;
    s32 temp_2;
    s32 var_16;
    s32 var_16_2;

    temp_18 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    temp_2 = func_0029d030();
    if (temp_2 < 0) {
        func_0046d730(&D_006359F0, 0x16D);
    }
    if (temp_18 == 0) {
        temp_18 = func_00108e10() & 0xFFFF;
    }
    temp_18 = func_00247900(temp_18 & 0xFFFF, func_00104c70(1), temp_16);
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
/* measured: closes the level 1 scope above; -O2 is the baseline everywhere
   else in this translation unit. */
#pragma optimization_level 2

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
s32 func_0024b870(u8 *task)
{
    s32* s0;
    s32 sp2c;
    s32 temp;
    s32 state;

    s0 = (s32*)(s32)func_00452560(task);
    state = s0[1];
    switch (state) {
    case 0:
        s0[1] = 1;
    case 1:
        s0[1] = 2;
        func_00440b68(&iGpffffa658, D_006359F0, 0x35D);
        s0[2] = (s32)func_00454a60(D_00635A40, 1);
    case 2:
        if (H_Cdvd_IsFileLoaded((u8*)s0[2]) != 0) {
            s0[1] = 3;
            s0[0] |= 1;
        }
        break;
    case 3:
        s0[1] = 4;
        temp = func_00455f70(D_00635A60, (u32*)&sp2c);
        if (temp != 0) {
            s0[9] = (s32)func_0046af60((u32)temp);
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
void func_0024b990(u8 *task)
{
    u8* p;
    u8* q2;
    u8* q3;
    s32 h;
    s32 i;
    s32 x;

    p = (u8*)(s32)func_00452560(task);
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
    H_Cdvd_Destroy((u8*)*(s32*)(p + 0x8));
    DAT_008873ec_abs[0](p);
}
// FUN_0024BA60
void func_0024ba60(s32 arg0)
{
    s32 p;
    s32* q;

    p = (s32)func_00452380((s8 *)(D_00635A78));
    if (arg0 < 0 || arg0 >= 5) {
        func_0046d730(D_006359F0, 0x3B2);
    }
    if (p != 0) {
        q = (s32*)((int)(s32)func_00452560((void *)(u32)(p)) + arg0 * 4 + 0xC);
        if (q[0] != 0) {
            func_00452080(q[0]);
            q[0] = 0;
        }
    }
}
// FUN_0024BB00
/* measured: O1 probe for global-load scheduling; revert if it does not match. */
#pragma optimization_level 1
s32 func_0024bb00(s32 arg0) {
    extern s32 func_00452080(struct KwlnTask* task);
    extern s32 func_00455f70(s32 arg0, s32* arg1);
    extern s32 func_0025ff60(s32 arg0);
    s64 sp40;
    f32 sp48;
    s32 sp4C;
    s32 temp_17;
    s32 temp_2;
    s32* temp_16;
    s32* temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    s32 temp_4;
    u8 flag;
    s64 temp_q;
    f32 temp_f;
    temp_17 = (s32)(s32)func_00452380((s8 *)((s8*)&D_00635A78));
    temp_q = *(s64*)D_00635A88;
    temp_f = *(f32*)(D_00635A88 + 8);
    sp40 = temp_q;
    sp48 = temp_f;
    *(f32*)((u8*)&sp40 + 8) = sp48;
    temp_2 = (s32)(s32)func_00452380((s8 *)((s8*)&D_00635A78));
    if (temp_2 == 0) {
        func_0046d730(&D_006359F0, 0x392);
    }
    flag = (*(u32*)(s32)func_00452560((void *)(u32)((void*)temp_2)) & 1U) != 0;
    if (!flag) {
        func_0046d730(&D_006359F0, 0x3CD);
    }
    temp_16 = (s32*)(s32)func_00452560((void *)(u32)((void*)temp_17));
    if (arg0 < 0 || arg0 >= 5) {
        func_0046d730(&D_006359F0, 0x3CF);
    }
    temp_2_2 = (s32*)((u32)(arg0 << 2) + (u32)temp_16);
    temp_16 = temp_2_2 + 3;
    temp_4 = temp_2_2[3];
    if (temp_4 != 0) {
        func_00452080((struct KwlnTask*)(uintptr_t)temp_4);
    }
    switch (arg0) {
    case 0:
        temp_2_3 = func_0025fe50(temp_17, func_00455f70((s32)(uintptr_t)&D_00635AA0, &sp4C), 0, &D_005DC7D0);
        func_004b1250((void *)(u32)(func_0025ff60(temp_2_3)), (f32 *)((void*)&sp40));
        *temp_16 = temp_2_3;
        break;
    case 1:
        temp_2_4 = func_0025fe50(temp_17, func_00455f70((s32)(uintptr_t)&D_00635AC0, &sp4C), 0, &D_005DC7D0);
        func_004b1250((void *)(u32)(func_0025ff60(temp_2_4)), (f32 *)((void*)&sp40));
        *temp_16 = temp_2_4;
        break;
    case 2:
        temp_2_5 = func_0025fe50(temp_17, func_00455f70((s32)(uintptr_t)&D_00635AE0, &sp4C), 0, &D_005DC7D0);
        func_004b1250((void *)(u32)(func_0025ff60(temp_2_5)), (f32 *)((void*)&sp40));
        *temp_16 = temp_2_5;
        break;
    case 3:
        temp_2_6 = func_0025fe50(temp_17, func_00455f70((s32)(uintptr_t)&D_00635B00, &sp4C), 0, &D_005DC7D0);
        temp_2_7 = func_0025ff60(temp_2_6);
        (*(f32*)((u8*)&sp40 + 4)) -= 10.0f;
        func_004b1250((void *)(u32)(temp_2_7), (f32 *)((void*)&sp40));
        *temp_16 = temp_2_6;
        break;
    case 4:
        temp_2_8 = func_0025fe50(temp_17, func_00455f70((s32)(uintptr_t)&D_00635B20, &sp4C), 0, &D_005DC7D0);
        func_004b1250((void *)(u32)(func_0025ff60(temp_2_8)), (f32 *)((void*)&sp40));
        *temp_16 = temp_2_8;
        break;
    }
    return 0;
}
/* measured: restore the translation-unit optimization level after func_0024bb00. */
#pragma optimization_level 2
/* Floor (re-measured 2026-09-17): probe_variants 8 reloc-masked differing */
/* words; fnalign retail 168 instrs / object 168 instrs, 8 edits plus 4 */
/* reloc-only (168*4 = 672B = window, exact size, no tail). Residual is a */
/* single $s0/$s2 saved-register swap (found-pointer against the second-loop */
/* counter); the instruction stream is otherwise retail's with no inserts or */
/* deletes. Declaration order is the archive's best of 250 permutations */
/* (docs/probe_archive/WSCR2_0024be40_body.c, banked verbatim below); the */
/* eight documented pragmas and the slti-<= spellings stay worse on top of */
/* it (both/j-only/i-only <=5 forms give 23/10/21 words). Pairs 2026-09-17 */
/* (`tools/pragma_sweep.py --pairs`, 8 singles + 28 pairs, banked 8): ties */
/* at 8 among loopinv/prop/strength/unroll + 6 pairs among them; cse_off 14, */
/* dead 75, peephole 138, sched 141. No pair beats the singles; floor stands. */
/* Semantic gate: the */
/* block-scope s32(s32) for func_00246e10 matches the MATCHED provider */
/* src/cmmMisc.c:294; the file-scope u8*(u16) is retained untouched for the */
/* other caller func_00250940. K&R void* for func_00452560 ties the */
/* prototyped u32(void*)/void*(void*) spellings at 8 words (measured */
/* 2026-09-17) and follows this file's bare-call idiom; production stays */
/* ASM. */
/* 2026-09-18 lead pass, 4 more measured variants on top of the permuter's
   14160 compiles; floor confirmed at 8 words.  168/168 instructions and the
   whole residual is one saved-register swap: retail allocates the second
   loop counter to $s0 and the `found` pointer to $s2, this body has them the
   other way round, and the eight differing words are the eight instructions
   that name them.
   Declaration order does not drive it.  Moving `i` above `found` ties at 8,
   `&base[index * 6]` instead of `base + index * 6` ties at 8, moving `found`
   to the end of the declaration list costs 8 -> 13, and hoisting `i` to the
   top of the function costs 8 -> 20.  Retail keeps `base` live past the
   `found` assignment and this body does not, which is what frees the lower
   register for the counter there and not here; no source shape tried
   reproduces that without changing the stream. */
/* 2026-09-18, handoff 7o re-probe by a dedicated worker; floor stands at 8.
   168/168 instructions, 672/672 bytes, and the pair is $s0/$s2: retail holds
   the second loop's counter in $s0 and the found-pointer in $s2, this body
   the other way round.  All eight 7o variants measured - bare declarations
   in retail computation order at function scope 8 (tie), reversed order 76,
   found-pointer at block scope 11 / 79, counter at block scope 13 / 81, both
   at block scope 16 / 84.  Every reversal of the assignment order is a large
   regression, so the order this body already uses is retail's. */
/* 2026-09-19 verbatim residual, masked 8 (raw 12/25, 168/168 exact, frame */
/* both addiu $sp,$sp,-0x60): object vs retail, all $s0<->$s2, same targets: */
/* off 196: object addu $s0,$s0,$v0 vs retail addu $s2,$s0,$v0; */
/* off 236: object addu $v0,$s0,$s1 vs retail addu $v0,$s2,$s1; */
/* off 480: object move $s2,$zero vs retail move $s0,$zero; */
/* off 492: object bnez $s2,0x24c048 vs retail bnez $s0,0x24c048 (same target); */
/* off 520: object addu $v0,$s0,$s2 vs retail addu $v0,$s2,$s0; */
/* off 544: object move $s3,$s2 vs retail move $s3,$s0; */
/* off 556: object addiu $s2,$s2,1 vs retail addiu $s0,$s0,1; */
/* off 560: object slti $v0,$s2,6 vs retail slti $v0,$s0,6. */
/* No immediate/branch-offset/nop diff; jal equal, lui/addiu 4 reloc-only. */
// FUN_0024BE40 NONMATCHING
#ifdef NON_MATCHING
s32 func_0024be40(void)
{
    s32 month;
    extern s32 func_00246e10(s32 arg0);
    s32 sum;
    u8* work;
    s32 j;
    f32 random_f;
    u8* found;
    s32 i;
    s32 day;
    f32 product;
    s32 index;
    u8* base;
    s32 sum2;
    f32 sum_f;

    found = 0;
    index = 0;
    func_001104d0(func_001060b0(), &month, &day);
    base = (u8*)func_00246e10((u16)month);
    if ((func_001060c0() & 0xFF) == 5) {
        index = 2;
    }
    if ((s8)func_00110960(func_001060b0(), func_001060c0() & 0xFF) == 1) {
        found = (u8*)1;
    }
    index = index + (s32)found;
    sum = 0;
    j = 0;
    {
        found = base + index * 6;
        while (j < 6) {
            if ((j != 0) || (datGetFlag(2703) != 0)) {
                sum += *(s8*)(found + j);
            }
            j++;
        }
        random_f = (f32)(u32)RpRandom();
        random_f /= 2147483648.0f;
        sum_f = (f32)(u32)sum;
        product = sum_f * random_f;
        sum = (u32)product;
        sum2 = 0;
        i = 0;
        while (i < 6) {
            if ((i != 0) || (datGetFlag(2703) != 0)) {
                sum2 += *(s8*)(found + i);
                if ((s32)sum < (s32)sum2) {
                    sum = i;
                    break;
                }
            }
            i++;
        }
    }
    work = (u8*)(u32)(s32)func_00452560((void *)(u32)((void*)(u32)(s32)func_00452380((s8 *)((s8*)D_00635A78))));
    if (work == 0) {
        func_0046d730(D_006359F0, 1041);
    }
    *(s32*)(work + 32) = sum;
    return sum;
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024be40);
#endif
// FUN_0024C0E0
s32 func_0024c0e0(u8 *arg0, u8 *arg1)
{
    f32 temp_f1;
    f32 var_f0;
    s32 temp_16;
    s32 temp_2;
    s32 temp_16_2;
    s32 temp_3;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;

    temp_2 = (s32)func_00452380((s8 *)(D_00635A78));
    temp_16 = (s32)func_00452380((s8 *)(D_00635A78));
    if (temp_16 == 0) {
        func_0046d730(D_006359F0, 0x392);
    }
    temp_2_2 = (*(s32 *)(s32)func_00452560((void *)(u32)(temp_16)) & 1) != 0;
    if (temp_2_2 != 0) {
        goto block_1;
    }
    func_0046d730(D_006359F0, 0x39D);
block_1:
    temp_16_2 = *(s32 *)((u8 *)(s32)func_00452560((void *)(u32)(temp_2)) + 0x24);
    temp_3 = *(s32 *)arg1;
    if (temp_3 & 2) {
        temp_2_2 = *(s32 *)(arg1 + 8);
        if (temp_2_2 < 10) {
            temp_f1 = (f32)temp_2_2;
            temp_f1 = (iGpffff8094 * temp_f1) / 10.0f;
            var_f0 = sinf(temp_f1);
        } else {
            var_f0 = 1.0f;
        }
        func_0025ecd0(512.0f,
                      418.0f + 200.0f * (1.0f - var_f0), 0.0f,
                      0xFFFFFF, 0xFF, 0, (void *)(uintptr_t)temp_16_2, 1, 0, 0,
                      -30.0f, 1.0f, 1.0f, D_00794E70);
        temp_2_3 = *(s32 *)(arg1 + 8) + 1;
        *(s32 *)(arg1 + 8) = temp_2_3;
        if (temp_2_3 >= 10) {
            *(s32 *)arg1 &= ~2;
            *(s32 *)(arg1 + 8) = 0;
        }
        goto block_20;
    }
    if (temp_3 & 4) {
        temp_2_4 = *(s32 *)(arg1 + 8);
        if (temp_2_4 < 10) {
            temp_f1 = (f32)temp_2_4;
            temp_f1 = (iGpffff8094 * temp_f1) / 10.0f;
            var_f0 = sinf(temp_f1);
        } else {
            var_f0 = 1.0f;
        }
        func_0025ecd0(512.0f, 418.0f, 0.0f,
                      0xFFFFFF,
                      (u8)(255.0f * (1.0f - var_f0)),
                      0, (void *)(uintptr_t)temp_16_2, 1, 0, 0,
                      -30.0f, 1.0f, 1.0f, D_00794E70);
        temp_2_5 = *(s32 *)(arg1 + 8) + 1;
        *(s32 *)(arg1 + 8) = temp_2_5;
        if (temp_2_5 >= 10) {
            *(s32 *)arg1 &= ~4;
            *(s32 *)(arg1 + 8) = 0;
            return 1;
        }
    } else {
        func_0025ecd0(512.0f, 418.0f, 0.0f,
                      0xFFFFFF, 0xFF, 0, (void *)(uintptr_t)temp_16_2, 1, 0, 0,
                      -30.0f, 1.0f, 1.0f, D_00794E70);
    }
block_20:
    return 0;
}
/* Native b210 -O2 recovery: 3,464 emitted bytes in the 3,472-byte retail
   window. Full proof and callback behavior evidence are retained in
   docs/probe_archive/Community_script_recovery_20260922.md. */
// FUN_0024C460
s32 func_0024c460(u8 *arg0, u8 *work)
{
    u8 *task;
    u8 *checkTask;
    void *atlas;
    s32 active;
    s32 flags;
    s32 frame;
    s32 alpha;
    s32 sprite;
    s32 pulse;
    f32 sine;
    f32 scale;
    f32 y;

    task = func_00452380((s8 *)D_00635A78);
    checkTask = func_00452380((s8 *)D_00635A78);
    if (checkTask == 0) {
        func_0046d730(D_006359F0, 0x392);
    }
    active = (*(u32 *)func_00452560(checkTask) & 1) != 0;
    if (active == 0) {
        func_0046d730(D_006359F0, 0x39D);
    }
    atlas = *(void **)(func_00452560(task) + 0x24);
    flags = *(s32 *)work;
    if ((flags & 2) != 0) {
        frame = *(s32 *)(work + 8);
        if (frame < 5) {
            sine = sinf((iGpffff8094 * (f32)frame) / 5.0f);
        } else {
            sine = 1.0f;
        }
        alpha = (s32)(255.0f * sine);
        scale = 1.0f + (0.5f * (f32)*(s32 *)(work + 8)) / 5.0f;
        func_0025ecd0(433.0f, 163.0f, 0.0f, 0xFFFFFF, alpha, 1, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(433.0f, 139.0f - 5.0f * sine, 0.0f, 0xFFFFFF, alpha, 2, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        y = 24.0f * scale;
        y = 177.0f - y;
        func_0025ecd0(443.0f - 60.0f * scale, y, 0.0f, 0xF27400, alpha, 0xC, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        func_0025ecd0(453.0f, y, 0.0f, 0xF27400, alpha, 0xD, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        y = 28.0f * scale;
        y = 177.0f - y;
        func_0025ecd0(443.0f - 51.0f * scale, y, 0.0f, 0xECF54D, alpha, 0xA, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        func_0025ecd0(453.0f, y, 0.0f, 0xECF54D, alpha, 0xB, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        frame = *(s32 *)(work + 8) + 1;
        *(s32 *)(work + 8) = frame;
        if (frame >= 5) {
            *(s32 *)work &= ~2;
            *(s32 *)(work + 8) = 0;
        }
        goto done;
    }
    if ((flags & 4) != 0) {
        frame = *(s32 *)(work + 8);
        if (frame < 5) {
            sine = sinf((iGpffff8094 * (f32)frame) / 5.0f);
        } else {
            sine = 1.0f;
        }
        alpha = (s32)(255.0f * (1.0f - sine));
        scale = 1.0f + (0.5f * (f32)*(s32 *)(work + 8)) / 5.0f;
        func_0025ecd0(433.0f, 163.0f, 0.0f, 0xFFFFFF, alpha, 1, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(433.0f, 139.0f - 5.0f * sine, 0.0f, 0xFFFFFF, alpha, 2, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        y = 24.0f * scale;
        y = 177.0f - y;
        func_0025ecd0(443.0f - 60.0f * scale, y, 0.0f, 0xF27400, alpha, 0xC, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        func_0025ecd0(453.0f, y, 0.0f, 0xF27400, alpha, 0xD, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        y = 28.0f * scale;
        y = 177.0f - y;
        func_0025ecd0(443.0f - 51.0f * scale, y, 0.0f, 0xECF54D, alpha, 0xA, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        func_0025ecd0(453.0f, y, 0.0f, 0xECF54D, alpha, 0xB, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        frame = *(s32 *)(work + 8) + 1;
        *(s32 *)(work + 8) = frame;
        if (frame >= 5) {
            *(s32 *)work &= ~4;
            *(s32 *)(work + 8) = 0;
            return 1;
        }
        goto done;
    }
    {
        f32 steadySine;
        f32 steadyScale;
        f32 steadyY;
        frame = *(s32 *)(work + 8);
        if (frame < 5) {
            steadySine = sinf((iGpffff8094 * (f32)frame) / 5.0f);
        } else {
            steadySine = 1.0f;
        }
        alpha = 255;
        steadyScale = 1.0f + (0.5f * (f32)*(s32 *)(work + 8)) / 5.0f;
        func_0025ecd0(433.0f, 163.0f, 0.0f, 0xFFFFFF, alpha, 1, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(433.0f, 139.0f - 5.0f * steadySine, 0.0f, 0xFFFFFF, alpha, 2, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        steadyY = 24.0f * steadyScale;
        steadyY = 177.0f - steadyY;
        func_0025ecd0(443.0f - 60.0f * steadyScale, steadyY, 0.0f, 0xF27400, alpha, 0xC, atlas,
                       1, 0, 0, 0.0f, steadyScale, steadyScale, D_00794E70);
        func_0025ecd0(453.0f, steadyY, 0.0f, 0xF27400, alpha, 0xD, atlas,
                       1, 0, 0, 0.0f, steadyScale, steadyScale, D_00794E70);
        steadyY = 28.0f * steadyScale;
        steadyY = 177.0f - steadyY;
        func_0025ecd0(443.0f - 51.0f * steadyScale, steadyY, 0.0f, 0xECF54D, alpha, 0xA, atlas,
                       1, 0, 0, 0.0f, steadyScale, steadyScale, D_00794E70);
        func_0025ecd0(453.0f, steadyY, 0.0f, 0xECF54D, alpha, 0xB, atlas,
                       1, 0, 0, 0.0f, steadyScale, steadyScale, D_00794E70);
        frame = *(s32 *)(work + 8) + 1;
        *(s32 *)(work + 8) = frame;
        if (frame >= 5) {
            *(s32 *)(work + 8) = 0;
        }
    }
    if (*(s32 *)(work + 0x10) > 0) {
        frame = *(s16 *)(work + 0xC);
        if (frame < 5) {
            sine = sinf((iGpffff8094 * (f32)frame) / 5.0f);
            alpha = (s32)(255.0f * sine);
        } else if (frame < 20) {
            alpha = 255;
        } else if (frame < 30) {
            frame -= 20;
            sine = (f32)frame;
            sine = sinf(iGpffff8094 + (iGpffff8094 * sine) / 10.0f);
            alpha = (s32)(255.0f * sine);
        }
        sprite = *(s32 *)(work + 0x10) + 0xD;
        func_0025ecd0(416.0f, 148.0f, 0.0f, 0xFFFFFF, alpha, sprite, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        if ((*(s32 *)work & 0x10) != 0) {
            f32 pulseScale;
            pulse = *(s16 *)(work + 0xE);
            pulseScale = 1.0f + (iGpffff809c * (f32)pulse) / 10.0f;
            sprite = *(s32 *)(work + 0x10) + 0x10;
            sine = sinf(iGpffff8094 + (iGpffff8094 * (f32)pulse) / 10.0f);
            alpha = (s32)(127.5f * sine);
            func_0025ecd0(448.0f - 32.0f * pulseScale, 177.0f - 29.0f * pulseScale, 0.0f,
                           0xFFFFFF, alpha, sprite, atlas, 1, 0, 0, 0.0f, pulseScale, pulseScale, D_00794E70);
            *(s16 *)(work + 0xE) += 1;
            if (*(s16 *)(work + 0xE) >= 10) {
                *(s16 *)(work + 0xE) = 0;
                *(s32 *)work &= ~0x10;
            }
        }
        *(s16 *)(work + 0xC) += 1;
        if (*(s16 *)(work + 0xC) >= 30) {
            *(s16 *)(work + 0xC) = 0;
            *(s32 *)(work + 0x10) = 0;
            *(s32 *)work &= ~0x10;
        }
    }
done:
    return 0;
}
/* Keep the displacement product separate from the anchor addition. The
   retail steady animation rounds this multiplication before adding the
   sprite baseline, while its bounce expressions use the accumulator. */
static inline f32 cmmScoreProduct(f32 phase, f32 scale)
{
    f32 value;
    value = scale * phase;
    return value;
}

static inline void *cmmScoreAtlas(void)
{
    u8 *task;
    u8 *checkTask;
    s32 active;
    task = func_00452380((s8 *)D_00635A78);
    checkTask = func_00452380((s8 *)D_00635A78);
    if (checkTask == NULL) {
        func_0046d730(D_006359F0, 0x392);
    }
    active = (*(u32 *)func_00452560(checkTask) & 1) != 0;
    if (active == 0) {
        func_0046d730(D_006359F0, 0x39D);
    }
    return *(void **)(func_00452560(task) + 0x24);
}

static inline s32 cmmScoreClamp(s32 value, s32 first, s32 limit)
{
    if (value < first) {
        return 0;
    }
    if (value < limit) {
        return value;
    }
    return limit;
}

static inline f32 cmmScoreBounce(f32 phase, f32 extent, f32 baseline)
{
    if (phase > 0.0f) {
        return -baseline + extent * (1.0f - phase);
    }
    return phase * 10.0f + 10.0f;
}

static inline f32 cmmScoreDisplacement(f32 phase, f32 negative, f32 positive)
{
    if (phase < 0.0f) {
        return negative * phase;
    }
    return positive * phase;
}

// FUN_0024D1F0
s32 func_0024d1f0(u8 *parent, u8 *work)
{
    extern f32 sinf(f32);
    extern u8 *func_0046a770(char *name);
    extern s32 func_00106600(s16);
    extern u8 D_005E5850[];
    extern f32 iGpffff81dc;
    extern f32 iGpffff81e0;
    void *atlas;
    void *digitsAtlas;
    f32 fadePhase;
    f32 bounceHeight;
    s32 fade;
    s32 frame;
    s32 phaseFrame;
    s32 score;

    atlas = cmmScoreAtlas();
    digitsAtlas = func_0046a770((char *)D_005E5850);
    if ((*(u32 *)work & 2) != 0) {
        frame = *(u32 *)(work + 8);
        if (frame < 5) {
            phaseFrame = 0;
        } else if (frame < 0xF) {
            phaseFrame = frame - 5;
        } else {
            phaseFrame = 10;
        }
        fadePhase = sinf((iGpffff8094 * (f32)phaseFrame) / 10.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 60.0f, 50.0f);
        func_0025ecd0(44.0f, bounceHeight + 10.0f, 0.0f, 0x6EB3, fade, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 5) {
            phaseFrame = 0;
        } else if (frame < 0xF) {
            phaseFrame = frame - 5;
        } else {
            phaseFrame = 10;
        }
        fadePhase = sinf((iGpffff8094 * (f32)phaseFrame) / 10.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 20.0f, 10.0f);
        func_0025ecd0(26.0f, bounceHeight + 135.0f, 0.0f, 0x50B6, fade, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 0, 10);
        fadePhase = sinf((iGpffff8094 * (f32)frame) / 10.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 30.0f, 20.0f);
        func_0025ecd0(15.0f, bounceHeight + 199.0f, 0.0f, 0x63B3, fade, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 5) {
            phaseFrame = 0;
        } else if (frame < 0xF) {
            phaseFrame = frame - 5;
        } else {
            phaseFrame = 10;
        }
        fadePhase = sinf((iGpffff8094 * (f32)phaseFrame) / 10.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 20.0f, 10.0f);
        func_0025ecd0(132.0f, bounceHeight + 12.0f, 0.0f, 0x6CB3, fade, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(91.0f, bounceHeight + 32.0f, 0.0f, 0x57B3, fade, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(34.0f, bounceHeight + 161.0f, 0.0f, 0x2BB3, fade, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 0, 0x14);
        fadePhase = sinf((iGpffff8094 * (f32)frame) / 20.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 30.0f, 20.0f);
        func_0025ecd0(11.0f, bounceHeight + 27.0f, 0.0f, 0x6AB3, fade, 7, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 5) {
            phaseFrame = 0;
        } else if (frame < 0x14) {
            phaseFrame = frame - 5;
        } else {
            phaseFrame = 0xF;
        }
        fadePhase = sinf((iGpffff8094 * (f32)phaseFrame) / 15.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 30.0f, 20.0f);
        func_0025ecd0(67.0f, bounceHeight + 11.0f, 0.0f, 0x2078, fade, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 0, 0xF);
        fadePhase = sinf((iGpffff8094 * (f32)frame) / 15.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 20.0f, 10.0f);
        func_0025ecd0(8.0f, bounceHeight + 52.0f, 0.0f, 0x2346, fade, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 3, 0x11);
        fadePhase = sinf((iGpffff8094 * (f32)frame) / 17.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 40.0f, 30.0f);
        func_0025ecd0(59.0f, bounceHeight + 121.0f, 0.0f, 0xC52, fade, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 10) {
            fadePhase = 0.0f;
        } else if (frame < 0xF) {
            fadePhase = sinf((iGpffff8094 * ((f32)frame - 10.0f)) / 5.0f);
        } else {
            fadePhase = 1.0f;
        }
        func_0025ecd0(30.0f, (1.0f - fadePhase) * 27.5f + 66.0f, 0.0f, 0x7AFEFF, 0xFF, 5, atlas, 1, 0, 0, 0.0f, 1.0f, fadePhase, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 10) {
            fadePhase = 0.0f;
        } else {
            fadePhase = sinf((iGpffff8094 * (f32)(frame - 10)) / 10.0f);
        }
        fade = (s32)(fadePhase * 255.0f);
        score = func_00106600(0x3F8) & 0xFF;
        if (score < 10) {
            func_0025ecd0(47.0f, 83.0f, 0.0f, 0, fade, score + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        } else {
            func_0025ecd0(37.0f, 83.0f, 0.0f, 0, fade, score / 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
            func_0025ecd0(59.0f, 83.0f, 0.0f, 0, fade, score % 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        }
        func_0025ecd0(70.0f, 55.0f, 0.0f, 0x7AFEFF, fade, 4, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 0, 0x14);
        {
            f32 result;

            fadePhase = sinf(iGpffff8094 + (iGpffff8084 * (f32)frame) / 20.0f);
            if (fadePhase > 0.0f) {
                result = -150.0f + 170.0f * (1.0f - fadePhase);
            } else {
                bounceHeight = sinf(iGpffff8084 * -fadePhase + iGpffff8094);
                if (bounceHeight > 0.0f) {
                    result = 20.0f - (1.0f - bounceHeight) * 24.0f;
                } else {
                    result = -4.0f - bounceHeight * 4.0f;
                }
            }
            func_0025ecd0(13.0f, result - 2.0f, 0.0f, 0, 0xFF, 3, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        }
        frame = *(u32 *)(work + 8) + 1;
        *(u32 *)(work + 8) = frame;
        if (frame >= 20) {
            *(u32 *)work &= ~2;
            *(u32 *)(work + 8) = 0;
        }
    } else if ((*(u32 *)work & 4) != 0) {
        frame = *(u32 *)(work + 8);
        if (frame < 10) {
            fadePhase = sinf((iGpffff8094 * (f32)frame) / 10.0f);
        } else {
            fadePhase = 1.0f;
        }
        fade = (s32)((1.0f - fadePhase) * 255.0f);
        func_0025ecd0(30.0f, 66.0f, 0.0f, 0x7AFEFF, fade, 5, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        score = func_00106600(0x3F8) & 0xFF;
        if (score < 10) {
            func_0025ecd0(47.0f, 83.0f, 0.0f, 0, fade, score + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        } else {
            func_0025ecd0(37.0f, 83.0f, 0.0f, 0, fade, score / 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
            func_0025ecd0(59.0f, 83.0f, 0.0f, 0, fade, score % 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        }
        func_0025ecd0(70.0f, 55.0f, 0.0f, 0x7AFEFF, fade, 4, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(13.0f, -2.0f, 0.0f, 0, fade, 3, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8) + 1;
        *(u32 *)(work + 8) = frame;
        if (frame >= 10) {
            *(u32 *)work &= ~4;
            *(u32 *)(work + 8) = 0;
            return 1;
        }
    } else {
        f32 phase;
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 60)) / 60.0f);
        phase = (phase + 1.0f) / 2.0f;
        func_0025ecd0(44.0f, 10.0f + cmmScoreDisplacement(phase, 2.0f, 5.0f), 0.0f, 0x6EB3, 0xFF, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(26.0f, 135.0f + cmmScoreProduct(phase, 5.0f), 0.0f, 0x50B6, 0xFF, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(15.0f, 199.0f + cmmScoreDisplacement(phase, 6.0f, 3.0f), 0.0f, 0x63B3, 0xFF, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 80)) / 80.0f);
        phase = (phase + 1.0f) / 2.0f;
        func_0025ecd0(132.0f, 12.0f + cmmScoreDisplacement(phase, 5.0f, 3.0f), 0.0f, 0x6CB3, 0xFF, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(91.0f, 32.0f + cmmScoreDisplacement(phase, 2.0f, 5.0f), 0.0f, 0x57B3, 0xFF, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(34.0f, 161.0f + cmmScoreDisplacement(phase, 4.0f, 2.0f), 0.0f, 0x2BB3, 0xFF, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 100)) / 100.0f);
        phase = (phase + 1.0f) / 2.0f;
        func_0025ecd0(11.0f, 27.0f + cmmScoreDisplacement(phase, 4.0f, 10.0f), 0.0f, 0x6AB3, 0xFF, 7, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 100)) / 100.0f);
        phase = (phase + 1.0f) / 2.0f;
        func_0025ecd0(67.0f, 11.0f + cmmScoreDisplacement(phase, 10.0f, 4.0f), 0.0f, 0x2078, 0xFF, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 120)) / 100.0f);
        phase = (phase + 1.0f) / 2.0f;
        func_0025ecd0(8.0f, 52.0f + cmmScoreDisplacement(phase, 8.0f, 2.0f), 0.0f, 0x2346, 0xFF, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(59.0f, 121.0f + cmmScoreDisplacement(phase, 10.0f, 6.0f), 0.0f, 0xC52, 0xFF, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(30.0f, 66.0f, 0.0f, 0x7AFEFF, 0xFF, 5, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        score = func_00106600(0x3F8) & 0xFF;
        if (score < 10) {
            func_0025ecd0(47.0f, 83.0f, 0.0f, 0, 0xFF, score + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        } else {
            func_0025ecd0(37.0f, 83.0f, 0.0f, 0, 0xFF, score / 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
            func_0025ecd0(59.0f, 83.0f, 0.0f, 0, 0xFF, score % 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        }
        func_0025ecd0(70.0f, 55.0f, 0.0f, 0x7AFEFF, 0xFF, 4, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0(13.0f, -2.0f, 0.0f, 0, 0xFF, 3, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        *(u32 *)(work + 8) = frame + 1;
        if ((s32)(frame + 1) >= 0x7FFFFFFF) {
            *(u32 *)(work + 8) = 0;
        }
    }
    return 0;
}
typedef struct cmmScriptEntry {
    u32 flags;                 /* 0x00 */
    u32 unk4;                  /* 0x04 */
    u32 unk8;                  /* 0x08 */
    u16 unkC;                  /* 0x0C */
    u16 padE;                  /* 0x0E */
    u32 unk10;                 /* 0x10 */
    s32 (*func)(u8*, u8*);    /* 0x14 */
} cmmScriptEntry;

// FUN_0024EFA0
s32 func_0024efa0(u8 *task)
{
    cmmScriptEntry* p;
    cmmScriptEntry* q;
    s32 i;

    p = (cmmScriptEntry*)(s32)func_00452560(task);
    q = p;
    i = 0;
    while (i < 3) {
        if ((q->flags & 1) != 0) {
            if (q->func((u8 *)p, (u8 *)q) != 0) {
                q->flags = q->flags & ~1;
            }
        }
        q++;
        i++;
    }
    return 0;
}




// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).

// FUN_0024F040
void func_0024f040(u8 *task)
{
    int iVar1;

    iVar1 = (s32)func_00452560(task);
    DAT_008873ec_abs[0](iVar1);
}

// FUN_0024F080
void func_0024f080(s32 arg0, s32 arg1)
{
    cmmScriptEntry* e;
    s32 p;

    p = (s32)func_00452380((s8 *)(D_00635B38));
    if (p == 0) {
        func_0046d730(D_006359F0, 0x67E);
    }
    e = (cmmScriptEntry*)(s32)func_00452560((void *)(u32)(p)) + arg0;
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
// FUN_0024F160
s32 func_0024f160(u8 *arg0)
{
    s32 result;
    s32 i;
    s32 id;
    s32 handle;
    s32 handle2;
    s32 rec;
    s32 state;
    s32 resource;
    s32 signal;
    s32 active;
    u32 random;
    f32 value;
    u8 color[4];
    u8 pos[12];
    u8 *entry;

    result = 0;
    switch (*(s32 *)(arg0 + 8)) {
    case 0:
        *(s32 *)(arg0 + 8) = 1;
        *(s32 *)arg0 &= ~4;
        *(s32 *)arg0 &= ~0x10;
        *(s32 *)arg0 &= ~0x20;
        *(s32 *)arg0 &= ~0x40;
        for (i = 0; i < 5; i++) {
            func_0024ba60(i);
        }
        func_0024bb00(3);
        func_0024bb00(1);
        func_0024f080(2, 1);
        func_0024f080(0, 1);
        id = func_0024be40();
        func_00246e90((u16)id);
        *(s16 *)(arg0 + 0xE) = func_00249960(id);
    case 1:
        break;
    default:
        goto done;
    }

    rec = (s32)func_00452560((void *)(u32)((s32)func_00452380((s8 *)(D_00635A78))));
    if (rec == 0) {
        func_0046d730(D_006359F0, 0x41B);
    }
    id = *(s32 *)(rec + 0x20);
    entry = func_00246e90((u16)id);
    *(s16 *)(arg0 + 0xC) += 1;
    if (*(s16 *)(arg0 + 0xC) >= *(s16 *)(arg0 + 0xE)) {
        *(s16 *)(arg0 + 0xC) = 0;
        *(s16 *)(arg0 + 0xE) = func_00249960(id);
        func_0024bb00(4);
        *(s16 *)(arg0 + 0x10) += 1;
        func_00249a60(id);
        state = *(s16 *)(arg0 + 0x10);
        if (state >= 3) {
            if (state >= 10 ||
                (random = (u32)RpRandom(),
                 (f32)random / 2147483648.0f > iGpffff809c)) {
                *(s32 *)arg0 |= 0x40;
                *(s16 *)(arg0 + 0x12) = 0;
            }
        }
    }

    signal = 0;
    if ((*(s32 *)arg0 & 0x40) != 0) {
        *(s16 *)(arg0 + 0x12) += 1;
        state = *(s16 *)(arg0 + 0x12);
        if (state == 1) {
            func_00113480(5, 61, 10, 0);
            func_0045aeb0((s16)(2), (const char *)(D_00635B50));
        }

        handle = (s32)func_00452380((s8 *)(D_00635A78));
        handle2 = (s32)func_00452380((s8 *)(D_00635A78));
        if (handle2 == 0) {
            func_0046d730(D_006359F0, 0x392);
        }
        active = (*(s32 *)(s32)func_00452560((void *)(u32)(handle2)) & 1) != 0;
        if (active == 0) {
            func_0046d730(D_006359F0, 0x3A6);
        }
        rec = (s32)func_00452560((void *)(u32)(handle));
        if (*(s32 *)(rec + 0x18) != 0) {
            resource = func_0025ff60(*(s32 *)(rec + 0x18));
        } else {
            resource = 0;
        }
        if (resource != 0) {
            func_004b14f0(resource, color);
            func_004b1420(resource, pos);
            value = sinf((iGpffff8084 * (f32)state) /
                                  (f32)*(s16 *)(entry + 4));
            *(f32 *)(pos + 4) = -55.0f - (20.0f * value);
            color[3] = (u8)(255.0f * (1.0f - value));
            func_004b13f0(resource, color);
            func_004b1250((void *)(u32)(resource), (f32 *)(pos));
        }
        if (state <= *(s16 *)(entry + 4)) {
            signal = 1;
        } else {
            signal = 2;
        }
    }

    if (signal == 2 || (D_008C024E[0] & 0x20) != 0) {
        if (signal == 0) {
            result = 3;
        } else {
            result = signal;
        }
    }
    if (result == 0) {
        goto done;
    }

    if ((rec = (s32)func_00452380((s8 *)(D_00635A78))) != 0) {
        rec = (s32)func_00452560((void *)(u32)(rec));
        if (*(s32 *)(rec + 0x10) != 0) {
            func_00452080(*(s32 *)(rec + 0x10));
            *(s32 *)(rec + 0x10) = 0;
        }
    }
    if ((rec = (s32)func_00452380((s8 *)(D_00635A78))) != 0) {
        rec = (s32)func_00452560((void *)(u32)(rec));
        if (*(s32 *)(rec + 0x18) != 0) {
            func_00452080(*(s32 *)(rec + 0x18));
            *(s32 *)(rec + 0x18) = 0;
        }
    }
    func_0024bb00(2);
    func_0024f080(0, 0);

    switch (result) {
    case 0:
        break;
    case 1:
        func_00113480(10, 101, 10, 0);
        *(s32 *)arg0 |= 0x10;
        break;
    case 2:
        func_00113480(3, 120, 1, 0);
        break;
    case 3:
        *(s32 *)arg0 |= 0x20;
        break;
    }
    *(s32 *)arg0 |= 4;
    return 1;

done:
    return 0;
}
static inline f32 cmmFishingBlend(f32 delta, f32 ratio, f32 origin)
{
    return 0.0f + origin + delta * ratio;
}

// FUN_0024F790
s32 func_0024f790(u8 *work)
{
    s32 i;
    u8 *task;
    u8 *checkTask;
    u8 *fishingData;
    s32 flags;
    s32 model;
    s32 direction;
    s16 currentDirection;
    s16 frameCount;
    s32 active;
    s32 directionPressed;
    u32 random;
    f32 randomFloat;
    f32 scaledRandom;
    u32 scaledCount;
    f32 ratio;
    CmmFishingPosition start;
    CmmFishingPosition finish;
    CmmFishingPosition result;
    u8 *fishEntry;

    switch (*(s32 *)(work + 8)) {
    case 0:
        *(s32 *)(work + 8) = 1;
        *(s32 *)work &= ~8;
        *(s32 *)work &= ~0x80;
        for (i = 0; i < 5; i++) {
            func_0024ba60(i);
        }
        func_0024bb00(0);
        func_0024f080(1, 1);
        random = RpRandom();
        randomFloat = (f32)random;
        scaledRandom = 360.0f * (randomFloat / 2147483648.0f);
        scaledCount = (u32)scaledRandom;
        *(s16 *)(work + 0x1C) = (s16)(scaledCount + 90);
    case 1:
        break;
    default:
        goto done;
    }

    fishingData = (u8 *)func_00452560(func_00452380((s8 *)D_00635A78));
    if (fishingData == 0) {
        func_0046d730(D_006359F0, 0x41B);
    }
    fishEntry = func_00246e90(*(u16 *)(fishingData + 0x20));
    if ((*(s16 *)(work + 0xC) % 60) == 0) {
        func_0045aeb0(2, (const char *)D_00635B90);
    }
    *(s16 *)(work + 0xC) += 1;
    if ((*(s16 *)(work + 0xC) % 20) == 0) {
        func_00113480(1, 0x50, 1, 0);
    }
    if (*(s16 *)(work + 0x1C) == 0) {
        random = RpRandom();
        randomFloat = (f32)random;
        scaledRandom = 360.0f * (randomFloat / 2147483648.0f);
        scaledCount = (u32)scaledRandom;
        *(s16 *)(work + 0x1C) = (s16)(scaledCount + 90);
        random = RpRandom();
        randomFloat = (f32)random;
        scaledRandom = 3.0f * (randomFloat / 2147483648.0f);
        scaledCount = (u32)scaledRandom;
        *(s16 *)(work + 0x1E) = (s16)(scaledCount + 1);
        direction = *(s16 *)(work + 0x1E);
        {
            u8 *directionTask;

            directionTask = func_00452380((s8 *)D_00635B38);
            if (directionTask == 0) {
                func_0046d730(D_006359F0, 0x696);
            }
            *(s32 *)(func_00452560(directionTask) + 0x28) = direction;
        }
        *(s32 *)work |= 0x10;
        *(s16 *)(work + 0x22) = 0x19;
    } else {
        *(s16 *)(work + 0x1C) = *(s16 *)(work + 0x1C) - 1;
    }
    if ((*(s32 *)work & 0x10) != 0) {
        directionPressed = 0;
        currentDirection = *(s16 *)(work + 0x1E);
        switch (currentDirection) {
        case 1:
            if ((D_008C024E[0] & 0x10) != 0) {
                directionPressed = 1;
            }
            break;
        case 2:
            if ((D_008C024E[0] & 0x80) != 0) {
                directionPressed = 1;
            }
            break;
        case 3:
            if ((D_008C024E[0] & 0x40) != 0) {
                directionPressed = 1;
            }
            break;
        }
        if (directionPressed != 0) {
            func_0045af60(0, 0, 4, 3);
            task = func_00452380((s8 *)D_00635B38);
            if (task == 0) {
                func_0046d730(D_006359F0, 0x6A2);
            }
            *(s32 *)(func_00452560(task) + 0x18) |= 0x10;
            flags = *(s32 *)work & ~0x10;
            *(s32 *)work = flags;
            *(s32 *)work = flags | 0x20;
            *(s16 *)(work + 0x20) = 0;
            *(s16 *)(work + 0x22) = 0;
        } else {
            *(s16 *)(work + 0x22) = *(s16 *)(work + 0x22) - 1;
        }
        if (*(s16 *)(work + 0x22) <= 0) {
            *(s32 *)work &= ~0x10;
        }
    }
    if ((*(s32 *)work & 0x20) != 0) {
        *(s16 *)(work + 0x20) += 1;
        if (*(s16 *)(work + 0x20) >= 10) {
            *(s32 *)work &= ~0x20;
            *(s16 *)(work + 0x20) = 0;
        }
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 2;
    }
    start = D_00635B68.value;
    finish = D_00635B78.value;
    ratio = (f32)*(s32 *)(work + 0x14) / (f32)*(s16 *)(fishEntry + 8);
    {
        f32 delta = finish.value[0] - start.value[0];
        f32 origin = start.value[0];
        result.value[0] = cmmFishingBlend(delta, ratio, origin);
    }
    {
        f32 delta = finish.value[1] - start.value[1];
        f32 origin = start.value[1];
        result.value[1] = cmmFishingBlend(delta, ratio, origin);
    }
    {
        f32 delta = finish.value[2] - start.value[2];
        f32 origin = start.value[2];
        result.value[2] = cmmFishingBlend(delta, ratio, origin);
    }
    task = func_00452380((s8 *)D_00635A78);
    checkTask = func_00452380((s8 *)D_00635A78);
    if (checkTask == 0) {
        func_0046d730(D_006359F0, 0x392);
    }
    active = (*(s32 *)func_00452560(checkTask) & 1) != 0;
    if (active == 0) {
        func_0046d730(D_006359F0, 0x3A6);
    }
    fishingData = (u8 *)func_00452560(task);
    if (*(s32 *)(fishingData + 0xC) != 0) {
        model = func_0025ff60(*(s32 *)(fishingData + 0xC));
    } else {
        model = 0;
    }
    func_004b1250((void *)(u32)model, result.value);
    if ((D_008C024E[0] & 0x20) != 0) {
        func_00113480(3, 0x79, 3, 0);
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 1;
    }
    if ((*(s16 *)(work + 0xC) % *(s16 *)(fishEntry + 0xA)) == 0) {
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) - 1;
    }
    frameCount = *(s16 *)(work + 0xC);
    if (frameCount >= 0x1E && *(s32 *)(work + 0x14) >= *(s16 *)(fishEntry + 8)) {
        func_00113480(5, 0xC9, 5, 0);
        *(s32 *)(work + 4) = 2;
        flags = *(s32 *)work | 8;
        *(s32 *)work = flags;
        *(s32 *)work = flags | 0x80;
        func_0024f080(1, 0);
    } else if (frameCount >= *(s16 *)(fishEntry + 0xC) || *(s32 *)(work + 0x14) < -10) {
        *(s32 *)(work + 4) = 2;
        *(s32 *)work |= 8;
        func_0024f080(1, 0);
    }
done:
    return 0;
}
// FUN_0024FF60
s32 func_0024ff60(u8 *task)
{
    cmmScriptEntry* e;
    s32 handle;
    s32 st;

    e = (cmmScriptEntry*)(s32)func_00452560(task);
    switch (e->unk4) {
    case 0:
        e->unk4 = 1;
    case 1:
        e->unk4 = 2;
    case 2:
        handle = (s32)func_00452380((s8 *)(D_00635A78));
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x392);
        }
        st = (((cmmScriptEntry*)(s32)func_00452560((void *)(u32)(handle)))->flags & 1) != 0;
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
void func_002500e0(u8 *task)
{
    int iVar1;

    iVar1 = (s32)func_00452560(task);
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

    handle = (s32)func_00452380((s8 *)(D_00635BA8));
    if (handle != 0) {
        func_00452080(handle);
    }
    if ((s32)func_00452380((s8 *)(D_00635A78)) == 0) {
        p = func_00285af0();
        if ((s32)func_00452380((s8 *)(D_00635A78)) == 0) {
            func_0044ea90(D_006359F0, 0x402);
            e = D_008873F4[0](1, 0x28, 0x40000);
            *(s32*)(e + 4) = 0;
            (s32)func_00451fc0((void *)(p), (const void *)(D_00635A78), 0xF, 0, 0, func_0024b870, func_0024b990, (u8 *)(e));
        }
    }
    p = func_00285af0();
    handle = (s32)func_00452380((s8 *)(D_00635B38));
    if (handle != 0) {
        func_00452080(handle);
    }
    func_0044ea90(D_006359F0, 0x66C);
    e = D_008873F4[0](1, 0x5C, 0x40000);
    *(s32*)(e + 0x14) = (s32)func_0024c0e0;
    *(s32*)(e + 0x2C) = (s32)func_0024c460;
    *(s32*)(e + 0x44) = (s32)func_0024d1f0;
    (s32)func_00451fc0((void *)(p), (const void *)(D_00635B38), 0xF, 0, 0, func_0024efa0, func_0024f040, (u8 *)(e));
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
        if ((s32)func_00452380((s8 *)(D_00635BA8)) == 0) {
            if ((s32)func_00452380((s8 *)(D_00635A78)) == 0) {
                if ((s32)func_00452380((s8 *)(D_00635A78)) == 0) {
                    func_0044ea90(D_006359F0, 0x402);
                    e = (cmmScriptEntry*)D_008873F4[0](1, 0x28, 0x40000);
                    e->unk4 = 0;
                    (s32)func_00451fc0((void *)(p), (const void *)(D_00635A78), 0xF, 0, 0, func_0024b870, func_0024b990, (u8 *)(e));
                }
            }
            func_0044ea90(D_006359F0, 0x81D);
            e = (cmmScriptEntry*)D_008873F4[0](1, 0x24, 0x40000);
            e->unk4 = 0;
            (s32)func_00451fc0((void *)(p), (const void *)(D_00635BA8), 0xF, 0, 0, func_0024ff60, func_002500e0, (u8 *)(e));
        }
        handle = (s32)func_00452380((s8 *)(D_00635BA8));
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x82A);
        }
        e = (cmmScriptEntry*)(s32)func_00452560((void *)(u32)(handle));
        e->flags |= 1;
    } else {
        handle = (s32)func_00452380((s8 *)(D_00635BA8));
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x83E);
        }
        e = (cmmScriptEntry*)(s32)func_00452560((void *)(u32)(handle));
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
            func_00452080((s32)func_00452380((s8 *)(D_00635BA8)));
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
        if ((s32)func_00452380((s8 *)(D_00635BA8)) == 0) {
            if ((s32)func_00452380((s8 *)(D_00635A78)) == 0) {
                if ((s32)func_00452380((s8 *)(D_00635A78)) == 0) {
                    func_0044ea90(D_006359F0, 0x402);
                    e = (cmmScriptEntry*)D_008873F4[0](1, 0x28, 0x40000);
                    e->unk4 = 0;
                    (s32)func_00451fc0((void *)(p), (const void *)(D_00635A78), 0xF, 0, 0, func_0024b870, func_0024b990, (u8 *)(e));
                }
            }
            func_0044ea90(D_006359F0, 0x81D);
            e = (cmmScriptEntry*)D_008873F4[0](1, 0x24, 0x40000);
            e->unk4 = 0;
            (s32)func_00451fc0((void *)(p), (const void *)(D_00635BA8), 0xF, 0, 0, func_0024ff60, func_002500e0, (u8 *)(e));
        }
        handle = (s32)func_00452380((s8 *)(D_00635BA8));
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x834);
        }
        e = (cmmScriptEntry*)(s32)func_00452560((void *)(u32)(handle));
        e->flags |= 2;
    } else {
        handle = (s32)func_00452380((s8 *)(D_00635BA8));
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x84E);
        }
        e = (cmmScriptEntry*)(s32)func_00452560((void *)(u32)(handle));
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
            func_00452080((s32)func_00452380((s8 *)(D_00635BA8)));
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
    p = (s32)func_00452380((s8 *)(D_00635A78));
    r = (u8*)(s32)func_00452560((void *)(u32)(p));
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
