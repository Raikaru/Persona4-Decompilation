#include "include_asm.h"
#include "type.h"

extern s32 D_0075DDD8[];

extern s32 D_0075DE40[];

extern s32 D_0074428C[];

extern s32 D_0075E8B0[];

extern s32 D_007442A0[];

extern s32 D_0074586C[];

extern s32 D_00745878[];

extern s32 D_00745884[];


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


/* measured: -O2 emits lui $v1; sw; jr; nop; retail is lui $v0; jr; sw (store
   in the delay slot).  -O3 reproduces the delay-slot shape but b210 still
   colors the base $v1 where retail uses $v0 (residual nd 2, allocator
   coloring floor; see mwccps2-debugger p3-allocation-explanation). */
#pragma optimization_level 3

// FUN_00509910 NONMATCHING
#ifdef NON_MATCHING
void func_00509910(s32 arg0)
{
    D_0074428C[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00509910);
#endif
#pragma optimization_level 2


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


/* measured: -O2 emits lui $v0; lw $v0; jr; nop; retail is lui $v1; jr;
   lw $v0 (load in the delay slot, separate base $v1).  -O3 reproduces the
   delay-slot shape but b210 merges base and destination into $v0 (residual
   nd 2, allocator coloring floor). */
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


/* measured: -O2 emits lui $v0; lw $v0; jr; nop; retail is lui $v1; jr;
   lw $v0 (load in the delay slot, separate base $v1).  -O3 reproduces the
   delay-slot shape but b210 merges base and destination into $v0 (residual
   nd 2, allocator coloring floor). */
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


/* measured: -O2 emits lui $v1; sw; jr; nop; retail is lui $v0; jr; sw (store
   in the delay slot).  -O3 reproduces the delay-slot shape but b210 still
   colors the base $v1 where retail uses $v0 (residual nd 2, allocator
   coloring floor). */
#pragma optimization_level 3

// FUN_0050CCE0 NONMATCHING
#ifdef NON_MATCHING
void func_0050cce0(s32 arg0)
{
    D_00745884[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cce0);
#endif
#pragma optimization_level 2
