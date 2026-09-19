#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

/* Ported from P3FES frFontRaster.c (verified MATCH there), adapted to P4
 * addresses, assert lines, and callee names. */
typedef int (*code)();

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
extern code D_008873ec_abs[]; /* RwFree */
extern u32 DAT_00881750_abs[];
extern void (*D_00887300[])(u32 state, u32 value); /* device.setRenderState */
extern s32 (*D_00887310[])(s32, void *, s32);     /* device.fpIm2DRenderPrimitive */

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

/* The loop bound is the fresh expression `i < count - 1`; a named `limit`
   local is coloured first and lands in $a1 (archived at nd 8). */
/* measured: opt_loop_invariants on hoists that bound AFTER the body's
   temporaries are coloured, which is what puts the bound in $a0 and the
   next-node pointer in $a1 as retail. */
#pragma opt_loop_invariants on
// FUN_00275A60
void func_00275a60(s32 count)
{
    s32 i;
    s32 *node;
    s32 size;
    u32 memory;
    u32 block;
    s32 *current;

    size = count * 0x21c + 0x18;
    if (piGpffffb954 != NULL) {
        func_0046d730(D_0063bc88, 0x26);
    }
    func_0044ea90(D_0063bc88, 0x27);
    memory = D_008873e8_abs[0](size, 0x40000);
    piGpffffb954 = (s32 *)memory;
    func_0043f9c8(memory, 0, size);
    *piGpffffb954 = count;
    piGpffffb954[1] = (s32)(piGpffffb954 + 6);
    node = (s32 *)piGpffffb954[1];
    node[3] = (s32)(node + 7);
    piGpffffb954[4] = (s32)node;
    for (i = 0; i < count - 1; i++) {
        node[6] = (s32)(node[3] + 0x200);
        node = (s32 *)node[6];
        node[3] = (s32)(node + 7);
    }
    piGpffffb954[5] = (s32)node;
    current = (s32 *)piGpffffb954[4];
    while (current != NULL) {
        block = func_003ec590(0x20, 0x20, 4, 0x4504);
        current[5] = block;
        if (block == 0) {
            func_00440b68(D_0063bca0);
        } else {
            current = (s32 *)current[6];
        }
    }
}
/* measured: closes the hoisting scope after func_00275a60. */
#pragma opt_loop_invariants off

// FUN_00275BD0
void func_00275bd0(void)
{
    D_008873ec_abs[0](iGpffffb954);
    iGpffffb954 = (u8 *)0x0;
}

// FUN_00275C00
void func_00275c00(void)
{
    u32 *puVar1;
    u32 *puVar2;
    u32 *puVar3;

    puVar2 = (u32 *)0x0;
    puVar1 = *(u32 **)(iGpffffb954 + 8);
    while (puVar3 = puVar1, puVar3 != (u32 *)0x0) {
        if (((*puVar3 & 1) == 0) || (puVar3[4] == 0)) {
            *(short *)((int)puVar3 + 10) =
                *(short *)((int)puVar3 + 10) + -1;
        }
        if (*(short *)((int)puVar3 + 10) < 0) {
            if (puVar2 == (u32 *)0x0) {
                *(u32 *)(iGpffffb954 + 8) = puVar3[6];
                if (*(int *)(iGpffffb954 + 8) == 0) {
                    *(int *)(iGpffffb954 + 0xc) = 0;
                }
                if (*(int *)(iGpffffb954 + 0x14) != 0) {
                    *(u32 **)(*(int *)(iGpffffb954 + 0x14) + 0x18) = puVar3;
                    *(u32 **)(iGpffffb954 + 0x14) = puVar3;
                } else {
                    *(u32 **)(iGpffffb954 + 0x14) = puVar3;
                    *(u32 **)(iGpffffb954 + 0x10) = puVar3;
                }
                puVar3[6] = 0;
                puVar2 = (u32 *)0x0;
                puVar1 = *(u32 **)(iGpffffb954 + 8);
            } else if (puVar3[6] == 0) {
                *(u32 **)(iGpffffb954 + 0xc) = puVar2;
                puVar2[6] = 0;
                if (*(int *)(iGpffffb954 + 0x14) != 0) {
                    *(u32 **)(*(int *)(iGpffffb954 + 0x14) + 0x18) = puVar3;
                    *(u32 **)(iGpffffb954 + 0x14) = puVar3;
                } else {
                    *(u32 **)(iGpffffb954 + 0x14) = puVar3;
                    *(u32 **)(iGpffffb954 + 0x10) = puVar3;
                }
                puVar3[6] = 0;
                puVar1 = (u32 *)0x0;
            } else {
                puVar2[6] = puVar3[6];
                if (*(int *)(iGpffffb954 + 0x14) != 0) {
                    *(u32 **)(*(int *)(iGpffffb954 + 0x14) + 0x18) = puVar3;
                    *(u32 **)(iGpffffb954 + 0x14) = puVar3;
                } else {
                    *(u32 **)(iGpffffb954 + 0x14) = puVar3;
                    *(u32 **)(iGpffffb954 + 0x10) = puVar3;
                }
                puVar3[6] = 0;
                puVar1 = (u32 *)puVar2[6];
            }
        } else {
            puVar2 = puVar3;
            puVar1 = (u32 *)puVar3[6];
        }
    }
}

extern u8 D_0063BCC0[];
extern f32 D_008872F8[];
extern u8 D_0063BC88[];
extern s32 D_00881750;
/* measured 00275d80: fnalign retail 284 / object 288 instrs (+1.4%, inside 272-288 band); edits 124 +6 reloc-only; */
/* guarded obj 1152B/window 1136B, normalized_diff 140 (was 255), frame -448 exact (320B: 32 xy +32 copy +256 render); 5 jal +2 jalr complete; D_00881750 via DAT_00881750_abs; see docs/probe_archive/FR_00275d80_body.c */
// FUN_00275D80 NONMATCHING
#ifdef NON_MATCHING
s32 func_00275d80(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5, u32 arg6, f32 fparg0) {
    f32 render[64];
    f32 copy[8];
    f32 xy[8];
    f32 f22;
    f32 f21;
    f32 f20;
    f32 f5;
    f32 x2tmp;
    f32 x5tmp;
    f32 conv4;
    f32 conv5;
    s32 temp_19;
    u8 *temp_17;
    u8 *var_20;
    s32 v22;
    s32 sh24;
    s32 sh16;
    s32 sh8;
    s32 t10;
    s32 t9;
    s32 t8;
    s32 t7;
    s32 t6;
    s32 t5;
    s32 t4;

    f22 = (f32)arg0 / 16.0f;
    f21 = (f32)arg1 / 8.0f;
    f20 = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    temp_19 = arg6 & 0xFF;
    {
        u8 *v7 = D_0063BCC0;
        u8 *v6 = (u8 *)copy;
        s32 v4 = 4;
        s32 t3;
        s32 t2;
        do {
            t3 = *(s32 *)v7;
            t2 = *(s32 *)(v7 + 4);
            v7 += 8;
            v4 -= 1;
            *(s32 *)v6 = t3;
            *(s32 *)(v6 + 4) = t2;
            v6 += 8;
        } while (v4 > 0);
    }
    {
        f32 *p = xy;
        s32 n = 0x20;
        if (p != (f32 *)0) {
            do {
                *(u8 *)p = 0;
                p = (f32 *)((u8 *)p + 1);
                n -= 1;
            } while (n != 0);
        }
    }
    xy[0] = f22;
    xy[1] = f21;
    if (arg4 >= 0) {
        conv4 = (f32)arg4;
    } else {
        s32 uu = ((u32)arg4 >> 1) | (arg4 & 1);
        f32 vf0 = (f32)uu;
        vf0 += vf0;
        conv4 = vf0;
    }
    x2tmp = f22 + conv4;
    xy[2] = x2tmp;
    xy[3] = f21;
    xy[4] = f22;
    if (arg5 >= 0) {
        conv5 = (f32)arg5;
    } else {
        s32 uu2 = ((u32)arg5 >> 1) | (arg5 & 1);
        f32 vf02 = (f32)uu2;
        vf02 += vf02;
        conv5 = vf02;
    }
    x5tmp = f21 + conv5;
    xy[5] = x5tmp;
    xy[6] = x2tmp;
    xy[7] = x5tmp;
    if (*(u8 **)(arg2 + 0x1C) == NULL) {
        func_0046d730(&D_0063BC88, 0x9B);
    }
    var_20 = *(u8 **)(*(u8 **)(arg2 + 0x1C) + 0x0C);
    if (*(s16 *)(var_20 + 8) != arg3) {
        temp_17 = (u8 *)func_00271f50((u32 *)arg2, *(s32 *)(var_20 + 4));
        *(u16 *)((*(u8 **)(arg2 + 0x1C)) + 4) -= 1;
        {
            u8 *t5b = *(u8 **)(arg2 + 0x1C);
            if ((t5b != NULL) && (*(u16 *)(t5b + 4) == 0)) {
                u8 *t4b = *(u8 **)(t5b + 0x0C);
                if (t4b != NULL) {
                    *(s32 *)(t4b + 0) &= ~1;
                    *(s32 *)(t4b + 0x10) = 0;
                }
                func_00271310(*(s32 *)(t5b + 8));
                DAT_00881750_abs[0] -= 1;
            }
        }
        *(u8 **)(arg2 + 0x1C) = temp_17;
        var_20 = *(u8 **)(temp_17 + 0x0C);
    }
    *(s32 *)(var_20 + 0) |= 1;
    if (temp_19 == 0) {
        return 0;
    }
    func_0043f9c8(render, 0, 0x100);
    f5 = D_008872F8[0] - fparg0;
    sh24 = arg6 >> 24;
    sh16 = arg6 >> 16;
    sh8 = arg6 >> 8;
    t10 = sh24 & 0xFF;
    t9 = t10 & 1;
    t8 = sh16 & 0xFF;
    t7 = t8 & 1;
    t6 = sh8 & 0xFF;
    t5 = t6 & 1;
    t4 = temp_19 & 1;
    v22 = 0;
    while (v22 < 4) {
        f32 *dst = &render[v22 * 16];
        f32 *pCopy = &copy[v22 * 2];
        f32 *pXy = &xy[v22 * 2];
        dst[2] = f5;
        dst[6] = f20;
        dst[4] = *pCopy;
        dst[5] = *(pCopy + 1);
        if (t10 >= 0) {
            dst[8] = (f32)t10;
        } else {
            s32 q10 = ((u32)t10 >> 1) | t9;
            f32 g10 = (f32)q10;
            g10 += g10;
            dst[8] = g10;
        }
        if (t8 >= 0) {
            dst[9] = (f32)t8;
        } else {
            s32 q8 = ((u32)t8 >> 1) | t7;
            f32 g8 = (f32)q8;
            g8 += g8;
            dst[9] = g8;
        }
        if (t6 >= 0) {
            dst[10] = (f32)t6;
        } else {
            s32 q6 = ((u32)t6 >> 1) | t5;
            f32 g6 = (f32)q6;
            g6 += g6;
            dst[10] = g6;
        }
        if (temp_19 >= 0) {
            dst[11] = (f32)temp_19;
        } else {
            s32 q19 = ((u32)temp_19 >> 1) | t4;
            f32 g19 = (f32)q19;
            g19 += g19;
            dst[11] = g19;
        }
        dst[0] = *pXy;
        dst[1] = *(pXy + 1);
        v22 += 1;
    }
    D_00887300[0](1, *(s32 *)(var_20 + 0x14));
    D_00887310[0](4, render, 4);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_00275d80);
#endif
// end FUN_00275D80

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
