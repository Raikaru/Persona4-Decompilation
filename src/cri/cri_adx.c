/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004E7798)
/* Source unit: src/cri/cri_adx_004e7798.c (1 function markers) */
#include "type.h"

int func_004e77c0(void);

#pragma optimization_level 3
// FUN_004E7798
long func_004e7798(void)
{
    return func_004e77c0();
}
#pragma optimization_level 2
#endif /* P4_UNIT_004E7798 */

#if defined(P4_UNIT_004E80C0)
/* Source unit: src/cri/cri_adx_004e80c0.c (1 function markers) */
#include "type.h"

u64 func_004e8058(void);

#pragma optimization_level 3
// FUN_004E80C0
long func_004e80c0(void)
{
    long result;

    result = func_004e8058();
    return result >> 0x20;
}
#pragma optimization_level 2
#endif /* P4_UNIT_004E80C0 */

#if defined(P4_UNIT_004F1F58)
/* Source unit: src/cri/cri_adx_004f1f58.c (1 function markers) */
#include "type.h"

void func_004f9a88(void);

#pragma optimization_level 3
// FUN_004F1F58
void func_004f1f58(void)
{
    func_004f9a88();
    func_004f9a88();
}
#pragma optimization_level 2
#endif /* P4_UNIT_004F1F58 */

#if defined(P4_UNIT_004F2648)
/* Source unit: src/cri/cri_adx_004f2648.c (1 function markers) */
#include "type.h"

void func_004f54a0(void);

#pragma optimization_level 3
// FUN_004F2648
u32 func_004f2648(void)
{
    func_004f54a0();
    return 0x800;
}
#pragma optimization_level 2
#endif /* P4_UNIT_004F2648 */

#if defined(P4_UNIT_00524580)
/* Source unit: src/cri/cri_adx_00524580.c (1 function markers) */
#include "type.h"

u32 func_00527960(int param_1,int param_2);

#pragma optimization_level 3
// FUN_00524580
u8 func_00524580(int param_1)
{
    return func_00527960(param_1,1) != 0;
}
#pragma optimization_level 2
#endif /* P4_UNIT_00524580 */
