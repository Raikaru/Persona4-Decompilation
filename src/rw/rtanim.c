/* Consolidated Persona 4 source units. */

/* Grouped RenderWare animation and UV-animation source units. */
/* The 0x135 registration below is rwID_UVANIMPLUGIN; this block is not Rt2d. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
void func_003d5830(u8 *value);
void RtAnimInterpolatorSetAnimLoopCallBack(s32 object, u32 first, u32 second);
u32 func_003d60e0(u32 object, u32 value);
u32 _rpUVAnimCustomDataStreamGetSize(u32 value);

extern s32 func_003df8a0(s32 value);
extern s32 *func_003df890(s32 value);
extern void func_003df7f0(s32 value);
extern void func_003e0f40(s32 value);
extern s32 func_003e1220(s32, s32, s32, s32, s32, s32);
extern s32 func_003e2910(s32, void *, s32);
extern s32 func_003df360(s32, void *, s32);
extern void func_003d6010(u8 *value);
extern void func_003d5000(u8 *value);
extern void func_003d5fb0(u8 *value);
extern void func_003e12f0(s32 value);
extern u8 *RpUVAnimLinearKeyFrameDataInitFromMatrix(u8 *dst, u8 *src);
extern u8 *func_003e05d0(u8 *value);
extern u8 *func_003d6fb0(u8 *dst, u8 *src);
extern void *(*D_008873F8[])(s32, s32);
extern s32 (*D_008873C8[])(s32, s32);
extern s32 D_0070B650[];
extern s32 D_0070B680[];
extern u8 D_0070B610[];
extern s32 D_0072483C;
#define _rpUVAnimMaterialExtOffset D_0072483C
extern s32 iGpffffb744;
extern s32 iGpffffb748;
extern s32 iGpffffab24;
extern s32 iGpffffab28;
extern s32 UVAnimOpen(s32 value);
extern s32 UVAnimClose(s32 value);
extern s32 UVAnimConstructor(s32 value);
extern s32 func_003d72a0(s32 value);
extern s32 func_003d7350(s32 value, s32 arg1);
extern s32 func_003d77f0(s32 value, s32 arg1);
extern s32 func_003d75b0(s32 value, s32 arg1);
extern s32 UVAnimSize(s32 value);
extern s32 func_003d8150(void);
extern s32 func_003e8930(s32, s32, s32 (*)(s32), s32 (*)(s32));
extern s32 func_003c4310(s32, s32, s32 (*)(s32), s32 (*)(s32), s32 (*)(s32, s32));
extern s32 func_003c4340(s32, s32 (*)(s32, s32), s32 (*)(s32, s32), s32 (*)(s32));
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_003d7c50(void *value);
extern void *func_003d7a20(s32 value);

/* Source unit: src/rw/rt2d_003d5830.c (1 function markers) */

extern void (*DAT_008873ec_abs[])(void);

/* measured: optimization_level 3 probe for func_003d5830. */
#pragma optimization_level 3
// FUN_003D5830
void func_003d5830(u8 *value)
{
    DAT_008873ec_abs[0]();
}
/* measured: close optimization_level 3 for func_003d5830. */
#pragma optimization_level 2

/* Source unit: src/rw/rt2d_003d5990.c (1 function markers) */

// FUN_003D5840
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d5840);
/* measured: optimization_level 3 probe for func_003d5990. */
#pragma optimization_level 3
// FUN_003D5990
void RtAnimInterpolatorSetAnimLoopCallBack(s32 object, u32 first, u32 second)
{
    *(u32*)(object + 0x18) = first;
    *(u32*)(object + 0x1c) = second;
}
/* measured: close optimization_level 3 for func_003d5990. */
#pragma optimization_level 2

/* Source unit: src/rw/rt2d_003d60e0.c (1 function markers) */

/* measured: schedule on probe for func_003d60e0. */
#pragma schedule on
// FUN_003D60E0
u32 func_003d60e0(u32 object, u32 value)
{
    *(u32 *)(object + 0x14) = value;
    return object;
}
/* measured: close schedule on for func_003d60e0. */
#pragma schedule off

/* Source unit: src/rw/rt2d_003d7b30.c (1 function markers) */
/* measured: object 120B vs window 128B, normalized_diff 25; retail frame is 0x50 while plain-C is 0x40, with a landing/branch shift and final call/epilogue scheduling residual. schedule/no_branch_likely and do-loop body reproduce helper calls, callbacks, branch and return; archive F2D0_003d60f0_body.c. */
// FUN_003D60F0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d60f0);
// FUN_003D6170
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6170);
// FUN_003D6230
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6230);
// FUN_003D6350
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6350);
// FUN_003D65E0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d65e0);
// FUN_003D6680
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6680);
// FUN_003D6790
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6790);
/* measured: object 68B vs window 80B, normalized_diff 8; differing offsets 0x0C-0x13. Retail prologue interleaves `move $s1,$a0` before `sq $s0`, while the candidate keeps the saves grouped. First-statement object assignment (register and non-register forms, plus pointer-width cast) and no_branch_likely bracket were re-measured without effect; declaration order and delayed object copy remain ruled out. Retail bytes +0x44..+0x4C are zero padding through the 80B window; +0x50 begins func_003d6900. */
/* measured: optimization_level 3 probe for func_003d6900 and func_003d6b70. */
#pragma optimization_level 3
/* measured: close schedule on for func_003d6900. */
#pragma schedule off
/* measured: close tailcall for func_003d6900. */
#pragma tailcall off
/* measured: schedule-on probe for func_003d6a00 FPU order. */
#pragma schedule on
/* measured: closes schedule-on probe for func_003d6a00. */
#pragma schedule off
/* measured: optimization_level 3 probe for func_003d6b70. */
#pragma optimization_level 3
/* measured: schedule on probe for func_003d6b70 load order. */
#pragma schedule on
/* measured: close schedule on for func_003d6b70. */
#pragma schedule off
/* measured: close optimization_level 3 for func_003d6900 and func_003d6b70. */
#pragma optimization_level 2
/* measured: optimization_level 1 probe for func_003d6c10 load scheduling. */
#pragma optimization_level 1
/* measured: schedule on probe for func_003d6c10 delay-slot placement. */
#pragma schedule on
/* measured: close schedule on probe for func_003d6c10. */
#pragma schedule off
/* measured: close optimization_level 1 for func_003d6c10. */
#pragma optimization_level 2

/* measured: schedule on probe for func_003d70c0 instruction order. */
#pragma schedule on
/* measured: close schedule on for func_003d70c0. */
#pragma schedule off
/* measured: no_branch_likely on probe for func_003d7150 plain branch. */
#pragma no_branch_likely on
/* measured: schedule on probe for func_003d7150 instruction order. */
#pragma schedule on
/* measured: close schedule on for func_003d7150. */
#pragma schedule off
/* measured: close no_branch_likely on for func_003d7150. */
#pragma no_branch_likely off
/* measured: schedule on probe for func_003d71b0 prologue ordering. */
#pragma schedule on
/* measured: no_branch_likely on probe for func_003d71b0 plain branch. */
#pragma no_branch_likely on
/* measured: close no_branch_likely on probe for func_003d71b0. */
#pragma no_branch_likely off
/* measured: close schedule on probe for func_003d71b0. */
#pragma schedule off
/* measured: schedule on probe for func_003d7260 prologue argument setup. */
#pragma schedule on
/* measured: close schedule on probe for func_003d7260. */
#pragma schedule off
/* measured: schedule on probe for func_003d79b0 call delay. */
#pragma schedule on
/* measured: no_branch_likely on probe for func_003d79b0 plain branches. */
#pragma no_branch_likely on
/* measured: close no_branch_likely on for func_003d79b0. */
#pragma no_branch_likely off
/* measured: close schedule on for func_003d79b0. */
#pragma schedule off
/* measured: schedule on probe for func_003d7b30 return delay slot. */
#pragma schedule on
/* measured: close schedule on for func_003d7b30. */
#pragma schedule off
