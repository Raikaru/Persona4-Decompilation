#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

/* Ported from P3FES frFontRaster.c (verified MATCH there), adapted to P4
 * addresses, assert lines, and callee names. */
typedef int (*code)(...);

/* Defined below in this file; called at line 347, above its definition. */
extern void func_00276420(int param_1, u8 *param_2, int param_3);

extern u8 *D_007645b8;
#define iGpffffb954 D_007645b8
#define piGpffffb954 ((int *)D_007645b8)
#define uGpffffb954 (*(u32 *)D_007645b8)

/* Data in the P4 image (absolute, outside the gp window). */
extern char D_0063bc88[]; /* "frFontRaster.c" */
extern char D_0063bca0[];
extern char D_0063bde0[];
extern float D_0063bcc0[];
extern s16 D_0063bce0[];
extern u8 D_0063b5f0[];
extern float D_008872f8[];

/* Function-pointer slots outside the gp window. */
extern code D_008873e8_abs[]; /* RwMalloc */
#pragma alias D_008873e8_abs D_008873e8
extern code D_008873ec_abs[]; /* RwFree */
#pragma alias D_008873ec_abs D_008873ec
extern u32 DAT_00881750_abs[];
#pragma alias DAT_00881750_abs DAT_00881750
extern void (*D_00887300[])(u32 state, u32 value); /* device.setRenderState */
extern void (*D_00887310[])(s32, void *, s32);     /* device.fpIm2DRenderPrimitive */

/* Runtime helpers (old-style where retail passes no prototype-driven
 * zero-extension). */
extern void func_0046d730(const void *file, u32 line);
extern void func_0044ea90(void *msg, s32 id);
extern void func_00440b68();
extern u8 *func_00457120(void);
extern void func_0043f9c8();
extern void func_0043f810();
extern u32 func_003ec590(u32, u32, u32, u32);
extern int func_003ec6a0(u32 tex, s32, s32);
extern void func_003ec2a0(u32 tex);
extern u32 func_003ec3d0(u32 tex, s32);
extern void func_003ec2e0(u32 tex);
extern u32 func_00271f50(u32 *param_1, u32 param_2);
extern void func_00271310(u32 param_1);

// Ported from P3FES FUN_003b3d60 (verified MATCH there). Calls use the
// donor's implicit old-style declarations (FUN_003b3e00_raw/FUN_003b3e60_raw)
// so the arguments are passed without prototype-driven zero-extension.

// FUN_00275A60
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_00275a60);

// FUN_00275BD0
void func_00275bd0(void)
{
    D_008873ec_abs[0](iGpffffb954);
    iGpffffb954 = (u8 *)0x0;
}

// FUN_00275C00
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_00275c00);

// FUN_00275D80
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_00275d80);

// FUN_00276260
u32 func_00276260(u32 param_1, int param_2)
{
    u32 result;

    result = FUN_003b3e00_typed(param_1, param_2);
    if (result == 0) {
        result = 0;
    }

    return result;
}

// Ported from P3FES FUN_003b3e00 (verified MATCH there). The goto shape is
// the donor's exact loop layout: test entry!=0 first, then walk entry[6].

extern u8 *D_007645b8;
#define iGpffffb954 D_007645b8

// FUN_00276290
u32 func_00276290(u32 param_1, int param_2)
{
    u32 *entry;

    entry = *(u32 **)(iGpffffb954 + 8);
    goto check;
body:
    if (entry[1] != param_1) {
        goto next;
    }
    if (*(s16 *)((u8 *)entry + 8) != param_2) {
        goto next;
    }
    *(u16 *)((u8 *)entry + 10) = 1;
    entry[0] |= 1;
    goto done;
next:
    entry = (u32 *)entry[6];
check:
    if (entry != 0) {
        goto body;
    }
    entry = 0;
done:
    return (u32)entry;
}

// FUN_002762F0
u32 func_002762f0(u32 param_1, u32 param_2, u32 param_3)
{
    u32 *puVar1;

    if (param_2 == 0) {
        func_0046d730(D_0063bc88, 0x128);
    }
    puVar1 = *(u32 **)(iGpffffb954 + 0x10);
    if (puVar1 != (u32 *)0x0) {
        *(u32 *)(iGpffffb954 + 0x10) = puVar1[6];
        if (*(int *)(iGpffffb954 + 0x10) == 0) {
            *(u32 *)(iGpffffb954 + 0x14) = 0;
        }
        puVar1[6] = 0;
        if (*(int *)(iGpffffb954 + 0xc) != 0) {
            *(u32 *)(*(int *)(iGpffffb954 + 0xc) + 0x18) = (u32)puVar1;
            *(u32 *)(iGpffffb954 + 0xc) = (u32)puVar1;
        } else {
            *(u32 *)(iGpffffb954 + 0xc) = (u32)puVar1;
            *(u32 *)(iGpffffb954 + 8) = (u32)puVar1;
        }
        puVar1[4] = 0;
    }
    if (puVar1 == (u32 *)0x0) {
        return 0;
    }
    func_00276420((int)puVar1, (u8 *)param_2, param_3);
    puVar1[1] = param_1;
    *(u16 *)((int)puVar1 + 10) = 1;
    *puVar1 = *puVar1 | 1;
    func_0043f810(puVar1[3], param_2, 0x200);
    puVar1[4] = 0;
    return (u32)puVar1;
}

// FUN_00276420
void func_00276420(int param_1, u8 *param_2, int param_3)
{
    short uVar1;
    short uVar2;
    u32 lVar3;
    short *puVar8;
    u32 uVar7;
    u16 *puVar6;
    u32 uVar5;
    int iVar4;
    u32 base;
    u32 outer16;
    u32 inner16;
    u32 rowOffset;
    u8 rawByte;
    int uVar10;
    int uVar9;
    u8 *src;
    u8 *pbVar11;
    u16 auStack_100[128];

    if (param_2 == (u8 *)0x0) {
        func_00440b68(D_0063bde0);
        func_0046d730(D_0063bc88, 0x17e);
        return;
    }
    puVar8 = (short *)D_0063bce0;
    puVar6 = auStack_100;
    iVar4 = 0x40;
    do {
        uVar1 = *puVar8;
        uVar2 = puVar8[1];
        puVar8 = puVar8 + 2;
        iVar4 = iVar4 + -1;
        *puVar6 = uVar1;
        puVar6[1] = uVar2;
        puVar6 = puVar6 + 2;
    } while (0 < iVar4);
    src = param_2;
    iVar4 = func_003ec6a0(*(u32 *)(param_1 + 0x14), 0, 9);
    for (uVar5 = 0; (int)uVar5 < 0x20; uVar5 = uVar5 + 1) {
        uVar7 = 0;
        outer16 = uVar5 & 0xffff;
        puVar6 = auStack_100 + ((int)(outer16 & 7) >> 2) * 0x40 + (outer16 & 3) * 0x10;
        base = ((int)outer16 >> 2) * 0x80;
        while ((int)uVar7 < 0x20) {
            inner16 = uVar7 & 0xffff;
            uVar9 = (u32)puVar6[inner16 & 0xf];
            rowOffset = ((int)inner16 >> 4) * 0x20;
            rowOffset += base;
            uVar9 = (uVar9 + (rowOffset & 0xffffU)) & 0xffff;
            pbVar11 = (u8 *)(iVar4 + ((int)uVar9 >> 1));
            uVar10 = *src >> ((uVar7 & 1) << 2);
            rawByte = uVar10 & 0xf;
            if ((uVar9 & 1) == 0) {
                *pbVar11 = rawByte;
            } else {
                *pbVar11 = *pbVar11 | (u8)((rawByte << 4) & 0xf0);
            }
            if ((uVar7 & 1) != 0) {
                src = src + 1;
            }
            uVar7 = uVar7 + 1;
        }
    }
    func_003ec2a0(*(u32 *)(param_1 + 0x14));
    lVar3 = func_003ec3d0(*(u32 *)(param_1 + 0x14), 1);
    if (lVar3 == 0) {
        func_0046d730(D_0063bc88, 0x1b1);
    }
    func_0043f810(lVar3, (u32)D_0063b5f0 + param_3 * 0x40, 0x40);
    func_003ec2e0(*(u32 *)(param_1 + 0x14));
    *(short *)(param_1 + 8) = (short)param_3;
}
