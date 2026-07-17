/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00285170)
/* Source unit: src/fmGslCont_00285170.c */
#include "type.h"

// FUN_00285170
int* func_00285170(int* param_1)
{
    u32* puVar1;
    int* piVar2;

    piVar2 = (int*)param_1[2];

    if (piVar2 == (int*)0x0) {
        piVar2 = (int*)0x0;
    }
    else {
        puVar1 = (u32*)piVar2[1];

        if (*param_1 != 0) {
            *piVar2 = param_1[1];
            *(int**)(param_1[1] + 4) = piVar2;
        }
        else {
            *piVar2 = 0;
            *param_1 = (int)piVar2;
        }

        piVar2[1] = 0;
        param_1[1] = (int)piVar2;

        if (puVar1 != (u32*)0x0) {
            *puVar1 = 0;
        }
        else {
            param_1[3] = 0;
        }

        param_1[2] = (int)puVar1;
    }

    return piVar2;
}
#endif /* P4_UNIT_00285170 */

#if defined(P4_UNIT_002851F0)
/* Source unit: src/fmGslCont_002851f0.c */
#include "type.h"

// FUN_002851F0
void func_002851f0(int* param_1, u32* param_2)
{
    int iVar1;
    int* piVar2;

    iVar1 = *param_1;
    piVar2 = (int*)param_1[1];

    if (iVar1 != 0) {
        *(int**)(iVar1 + 4) = piVar2;
    }
    else {
        *param_2 = (u32)piVar2;
    }

    if (piVar2 != (int*)0x0) {
        *piVar2 = iVar1;
    }
    else {
        param_2[1] = iVar1;
    }

    param_1[1] = 0;
    iVar1 = param_2[3];
    *param_1 = iVar1;

    if (iVar1 != 0) {
        *(int**)(iVar1 + 4) = param_1;
    }

    param_2[3] = (u32)param_1;

    if (param_2[2] == 0) {
        param_2[2] = (u32)param_1;
    }
}
#endif /* P4_UNIT_002851F0 */

#if defined(P4_UNIT_0026E120)
/* Source unit: src/fmGslCont_0026e120.c */
#include "type.h"

// FUN_0026E120
u32 func_0026e120(int* param_1, int param_2)
{
    u32 uVar1;
    int* piVar1;

    if (param_1 == 0) {
        uVar1 = 0;
    }
    else {
        piVar1 = param_1 - 2;

        if (piVar1[1] != 0) {
            uVar1 = 0;
        }
        else {
            piVar1[1] = *(u32*)(param_2 + 4);
            *(int*)(param_2 + 4) = (int)piVar1;
            uVar1 = 1;
        }
    }

    return uVar1;
}
#endif /* P4_UNIT_0026E120 */
