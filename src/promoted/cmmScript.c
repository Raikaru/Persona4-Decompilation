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

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

// FUN_0024A200
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a200);
// FUN_0024A2E0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a2e0);
// FUN_0024A450
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a450);
// FUN_0024A490
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a490);
// FUN_0024A710
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a710);
// FUN_0024A8B0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024a8b0);
// FUN_0024AA10
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024aa10);
// FUN_0024AA60
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024aa60);
// FUN_0024AAF0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024aaf0);




// FUN_0024AB40
u32 func_0024AB40(void)
{
    u16 uVar1;

    uVar1 = func_00248b80();
    func_0029cf50(uVar1);
    return 1;
}

// FUN_0024AB70
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024ab70);




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
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024ac50);
// FUN_0024ACA0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024aca0);




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
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b380);
// FUN_0024B430
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b430);
// FUN_0024B490
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b490);
// FUN_0024B6A0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b6a0);
// FUN_0024B720
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b720);
// FUN_0024B870
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b870);
// FUN_0024B990
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024b990);
// FUN_0024BA60
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024ba60);
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
// FUN_0024EFA0
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024efa0);



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
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024f080);
// FUN_0024F160
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024f160);
// FUN_0024F790
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024f790);
// FUN_0024FF60
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_0024ff60);



#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

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
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_002507c0);
// FUN_00250870
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_00250870);
// FUN_00250940
INCLUDE_ASM("asm/nonmatchings/cmmScript", func_00250940);
