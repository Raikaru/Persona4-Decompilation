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
extern s32 func_00243840(s32 arg0);
extern void func_002782c0(s32 arg0, s32 arg1, s32 arg2, u32 arg3);
extern void func_00278450(s32 arg0, s32 arg1, s32 arg2);
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
extern s32 func_00451fc0(void* arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4, s32 (*arg5)(void), void (*arg6)(void));
extern void func_0044ea90(const void* arg0, s32 arg1);
extern u8* (*D_008873F4[])(s32, s32, s32);
extern s32 func_0024f160(u8* arg0);
extern s32 func_0024f790(u8* arg0);
extern s32 func_0024b870(void);
extern void func_0024b990(void);
extern s32 func_0024c0e0(void);
extern s32 func_0024c460(void);
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
// FUN_0024A2E0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a2e0);
// FUN_0024A450
s32 func_0024a450(void)
{
    u8* p;

    p = func_00108dc0();
    if (p != 0) {
        func_0029cf50(p[0xA]);
    }
    return 1;
}

// FUN_0024A490
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a490);
// FUN_0024A710
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a710);
// FUN_0024A8B0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a8b0);
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
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b070);
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
// FUN_0024B490
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b490);
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
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b870);
// FUN_0024B990
void func_0024b990(void)
{
    u8* p;
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
// FUN_0024BB00
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024bb00);
// FUN_0024BE40
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024be40);
// FUN_0024C0E0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024c0e0);
// FUN_0024C460
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024c460);
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
// FUN_0024F160
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024f160);
// FUN_0024F790
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024f790);
// FUN_0024FF60
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024ff60);

// FUN_002500E0
void func_002500e0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}

// FUN_00250120
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_00250120);

// FUN_002502F0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_002502f0);
// FUN_00250560
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_00250560);
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

