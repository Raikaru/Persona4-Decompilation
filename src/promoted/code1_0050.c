#include "include_asm.h"
#include "type.h"

extern s32 D_0075DDD8[];

extern s32 D_0075DE40[];

extern s32 D_0075E8B0[];

extern s32 D_007442A0[];

extern s32 D_0074586C[];

extern s32 D_00745878[];


/* measured: -O2 emits lui/addiu before jr $ra; retail schedules the final
   addiu into the jr delay slot (lui $v0; jr $ra; addiu $v0, $v0, %lo). */
#pragma optimization_level 3

// FUN_005036B8
s32 *func_005036b8(void)
{
    return D_0075DDD8;
}
#pragma optimization_level 2


/* measured: -O2 emits both stores before jr $ra; retail schedules the second
   store into the jr delay slot (sw $a2, 4($a0); jr $ra; sw $a1, ($a0)). */
#pragma optimization_level 3

// FUN_00503990
void func_00503990(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 4) = arg2;
    *(s32 *)arg0 = arg1;
}
#pragma optimization_level 2


/* measured: -O2 emits lui/addiu before jr $ra; retail schedules the final
   addiu into the jr delay slot (lui $v0; jr $ra; addiu $v0, $v0, %lo). */
#pragma optimization_level 3

// FUN_00506B88
s32 *func_00506b88(void)
{
    return D_0075DE40;
}
#pragma optimization_level 2


/* measured: retail is lui $v0; jr; sw %lo(D_0074428C)($v0) -- the base is a
   live return value, which is why the store folds into an offset off $v0
   (same family as func_004d18d8/004d3148/004d3678/004d36a8). A void
   spelling colors the base $v1 (nd 2); returning the segment pointer (lo
   bits zero, so lui alone materializes it) gives nd 0. */
#pragma schedule on

// FUN_00509910
s32 *func_00509910(s32 arg0)
{
    s32 *segment = (s32 *)0x00740000;
    segment[0x10A3] = arg0;
    return segment;
}
#pragma schedule off


/* measured: -O2 emits lui/addiu before jr $ra; retail schedules the final
   addiu into the jr delay slot (lui $v0; jr $ra; addiu $v0, $v0, %lo). */
#pragma optimization_level 3

// FUN_0050B3C0
s32 *func_0050b3c0(void)
{
    return D_0075E8B0;
}
#pragma optimization_level 2


/* measured: -O2 emits lui/addiu before jr $ra; retail schedules the final
   addiu into the jr delay slot (lui $v0; jr $ra; addiu $v0, $v0, %lo). */
#pragma optimization_level 3

// FUN_0050B3D0
s32 *func_0050b3d0(void)
{
    return D_007442A0;
}
#pragma optimization_level 2


/* retail: lui $v1; jr; lw $v0, %lo(D)($v1) (separate base $v1); mwcc b210
   merges the base into $v0 (lui $v0; jr; lw $v0, ($v0)), nd 2. Tried
   schedule on/off, opt_regalloc on/off, u32, pointer local (*p and p[0]),
   address-of, u8-cast; corroborated across 19 getters in code1_004c/004d/
   004e/004f/0050/0051/0052 with 16+ spellings. measured allocator floor
   ($v0/$v1 coalescing in tiny accessors; getters not reachable). */
#pragma optimization_level 3

// FUN_0050BCA0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0050bca0(void)
{
    return D_0074586C[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bca0);
#endif
#pragma optimization_level 2


/* retail: lui $v1; jr; lw $v0, %lo(D)($v1) (separate base $v1); mwcc b210
   merges the base into $v0 (lui $v0; jr; lw $v0, ($v0)), nd 2. Tried
   schedule on/off, opt_regalloc on/off, u32, pointer local (*p and p[0]),
   address-of, u8-cast; corroborated across 19 getters in code1_004c/004d/
   004e/004f/0050/0051/0052 with 16+ spellings. measured allocator floor
   ($v0/$v1 coalescing in tiny accessors; getters not reachable). */
#pragma optimization_level 3

// FUN_0050CA80 NONMATCHING
#ifdef NON_MATCHING
s32 func_0050ca80(void)
{
    return D_00745878[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050ca80);
#endif
#pragma optimization_level 2


/* measured: retail is lui $v0; jr; sw %lo(D_00745884)($v0) -- the base is a
   live return value, which is why the store folds into an offset off $v0
   (same family as func_004d18d8/004d3148/004d3678/004d36a8). A void
   spelling colors the base $v1 (nd 2); returning the segment pointer (lo
   bits zero, so lui alone materializes it) gives nd 0. */
#pragma schedule on

// FUN_0050CCE0
s32 *func_0050cce0(s32 arg0)
{
    s32 *segment = (s32 *)0x00740000;
    segment[0x1621] = arg0;
    return segment;
}
#pragma schedule off
