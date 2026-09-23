/* Retail RenderWare plugin/core functions attributed to balight.c.
 * Originally in src/rprandom/rprandom_grouped.c; see
 * docs/sky2/rw_unit_attribution.json.
 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
/* Measured file idiom: tight no_branch_likely on/off brackets reproduce retail's plain beqz/equality branches in seven functions; preserve them when adding bodies. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
u64 func_003b7a80(u64 value);
u64 func_003b82b0(u64 value);
u32 func_003b83f0(int object);
u32 func_003b8510(int object);
u64 func_003b88c0();
u64 func_003bf1c0(u64 value);
u64 func_003bf1f0(u64 value);
u64 func_003bf320(u64 value);
u64 func_003c38a0(u64 value);
u64 func_003cad80(u64 value);
u64 func_003caee0(u64 value);
u64 func_003e3800(u64 value);
u64 func_003e3810(u64 value);
u64 func_003e3820(u64 value);
extern s32 D_00886490[];
extern s32 D_00886498[];
extern u32 DAT_00886498_abs[];
extern s32 func_003e8930(s32 arg0, s32 arg1, void *arg2, void *arg3);
extern s32 func_003c1ab0(s32 arg0, s32 arg1, void *arg2, void *arg3, void *arg4);
extern s32 func_003c1b10(s32 arg0, void *arg1, void *arg2, void *arg3);
extern s32 func_003c1b40(s32 arg0, void *arg1);
extern s32 _rpSkinSplitDataStreamGetSize(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_003b88d0(s32 arg0);
extern s32 func_003c1b60(s32 arg0, void *arg1);
extern s32 func_003c2b70(s32 arg0, s32 arg1, void *arg2, void *arg3, void *arg4);
extern s32 func_003c2ba0(s32 arg0, void *arg1, void *arg2, void *arg3);
extern void func_003b7860();
extern void func_003b7970();
extern void func_003b79f0();
extern void func_003b7a10();
extern s32 func_003b7a90(s32 arg0);
extern s32 func_003b7ad0(s32 arg0);
extern s32 func_003b7b00(s32 arg0, s32 arg1);
extern s32 func_003c1b80(s32 arg0);
extern s32 func_003b7b20(s32 arg0);
extern s32 func_003b7bb0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_003b7c10(u8 *arg0);
extern s32 *func_003b7ca0(s32 *arg0, s32 arg1, u8 *arg2);
extern u8 *func_003b7e00(u8 *arg0, s32 arg1, u8 *arg2);
extern u8 *func_003b8050(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);
extern s32 func_003b82c0(void);
extern s32 D_00886494[];
extern s32 iGpffffb6b4;
extern s32 iGpffffb6b0;
extern u8 D_008872E0[];
extern s32 iGpffffb710;
extern s32 iGpffffb718;
extern void memset(void *dst, s32 value, s32 size);
extern void func_003b7480(u8 *arg0, s32 arg1);
extern void func_003b7150(u8 *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void (*jtbl_008873FC[])(s32 arg0, u8 *arg1);
extern s32 D_008864A8[];
extern void func_003c0880(s32 arg0, s32 arg1);
extern void func_003c08c0(s32 arg0, s32 arg1);
extern void func_003c3cc0(s32 arg0);
extern void func_003e8440(s32 arg0);
extern s32 func_003c3980(void);
extern s32 func_003e5250(void);
extern void func_003cbcf0(s32 arg0, s32 arg1);
extern s32 func_003e8960(s32 arg0);
extern u8 *func_003b85e0(u8 *arg0);
extern void func_003b8d40(u8 *arg0, s32 arg1);
extern u8 *(*D_008873F8[])(s32 arg0, s32 arg1);
extern u8 *func_003b7290(u8 *arg0, void *arg1);
extern void func_003b7510(u8 *arg0, s32 arg1, u32 arg2);
extern void func_003b7590(u8 *arg0, void *arg1, void *arg2, void *arg3,
                          u32 *arg4, u32 arg5);
extern s32 func_003b7680(u8 *arg0, s32 arg1, u32 arg2, u32 arg3,
                          void *arg4, void *arg5, void *arg6, s32 arg7);
extern s32 func_003b8ad0(u8 *arg0, u8 *arg1);
extern s32 func_003df300(u8 *arg0, void *arg1, s32 arg2);
extern s32 func_003df360(u8 *arg0, void *arg1, s32 arg2);
extern s32 func_003e2910(u8 *arg0, void *arg1, s32 arg2);
extern s32 func_003e2ce0(u8 *arg0, s32 arg1);
extern u8 *func_003b8410(u8 *arg0, u8 *arg1);


/* Source unit: src/rprandom/rprandom_003b7a80.c (1 function markers) */
/* measured: removing this pragma takes func_003b7a80 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003b82b0.c (1 function markers) */
/* measured: removing this pragma takes func_003b82b0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3


/* measured: close no_branch_likely around func_003b7ad0. */
#pragma no_branch_likely off

/* measured: no_branch_likely on selects retail's plain branches and prologue ordering. */
#pragma no_branch_likely off


/* measured: close no_branch_likely around func_003b7bb0. */
#pragma no_branch_likely off

/* measured: close no_branch_likely around pointer family probe. */
#pragma no_branch_likely off

/* measured: close no_branch_likely around func_003b7e00. */
#pragma no_branch_likely off
/* measured: restore default propagation after func_003b7e00. */
#pragma opt_propagation on

#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003b83f0.c (1 function markers) */


#pragma schedule on



/* measured: removing the schedule on/off bracket takes func_003b83f0 nd 0 -> nd 6: retail loads in the jr $ra delay slot; unscheduled it emits lw; jr; nop. */
#pragma schedule off

/* Source unit: src/rprandom/rprandom_003b8510.c (1 function markers) */
/* measured: removing this pragma takes func_003b8510 nd 0 -> nd 6: retail fills the jr $ra delay slot with lw $v0, 0xc($a0); baseline -O2 emits lw; jr; nop. */
#pragma optimization_level 3

/* measured: close no_branch_likely around func_003b8410. */
#pragma no_branch_likely off
/* measured: close no_branch_likely around func_003b84a0. */
#pragma no_branch_likely off

#pragma optimization_level 2
/* measured: removing this pragma takes func_003b88c0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3

#pragma no_branch_likely off

/* measured: close no_branch_likely around func_003b85b0. */
#pragma no_branch_likely off

#pragma optimization_level 2
/* Source unit: src/rprandom/rprandom_003bf1c0.c (1 function markers) */
/* measured: removing this pragma takes func_003bf1c0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003bf1f0.c (1 function markers) */
/* measured: removing this pragma takes func_003bf1f0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003bf320.c (1 function markers) */
/* measured: removing this pragma takes func_003bf320 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3




#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003c38a0.c (1 function markers) */
/* measured: removing this pragma takes func_003c38a0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003C38A0
u64 func_003c38a0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003cad80.c (1 function markers) */
/* measured: removing this pragma takes func_003cad80 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003caee0.c (1 function markers) */
/* measured: removing this pragma takes func_003caee0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3



/* measured: close no_branch_likely around func_003caea0. */
#pragma no_branch_likely off

#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003e3800.c (1 function markers) */
/* measured: removing this pragma takes func_003e3800 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003e3810.c (1 function markers) */
/* measured: removing this pragma takes func_003e3810 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003e3820.c (1 function markers) */
/* measured: removing this pragma takes func_003e3820 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
#pragma optimization_level 2
