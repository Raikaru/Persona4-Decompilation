/* Source unit: src/fmGslCont_0026e0e0.c */
#include "type.h"

typedef int (*code)();
extern code DAT_008873ec_abs[];

extern u64 memcpy();
extern u32 DAT_00764590;



// FUN_0026E0E0
int* func_0026e0e0(int param_1)
{
    int* piVar1;
    int* piVar2;

    piVar2 = (int*)param_1;
    piVar1 = (int*)piVar2[1];

    if (*piVar1 == 0) {
        piVar1 = (int*)0x0;
    }
    else {
        piVar2[1] = piVar1[1];
        piVar1[1] = 0;
        piVar1 = piVar1 + 2;
    }

    return piVar1;
}



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




// FUN_0026E170
u32 func_0026e170(int param_1)
{
    DAT_008873ec_abs[0](*(u32*)(param_1 + -4));
    return 1;
}



// FUN_0026E1A0
void func_0026e1a0(int* param_1, int* param_2)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar2 = *param_1 + param_1[1];
    iVar1 = param_1[6];
    iVar3 = iVar2 + iVar1;

    *param_2 = (int)param_1 + *param_1;
    param_2[1] = (int)param_1 + iVar2;
    param_2[2] = (int)param_1 + iVar3;
}



// FUN_0026E1E0
int func_0026e1e0(int param_1, int param_2, u64 param_3, int* param_4)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    u32 uVar8;
    int iVar7;
    u32 uVar6;
    int iVar9;
    int iVar5;
    u32 uStack_4;
    int iStack_8;

    iVar1 = *param_4;
    iVar7 = 0;
    memcpy(&uStack_4, param_4[1] + param_2 * 4, 4);
    memcpy(&iStack_8, param_4[1] + (param_2 + 1) * 4, 4);
    iVar5 = iVar1 + 2;
    iVar3 = iVar5;
    iVar2 = param_4[2];
    uVar6 = uStack_4 >> 4;
    uVar8 = (int)(*(u16*)(iVar2 + uVar6 * 2) | 0x10000) >> (uStack_4 & 0xf);
    iVar9 = iStack_8 - uStack_4;
    do {
        iVar4 = iVar1 + (u32)*(u16*)(iVar3 + (uVar8 & 1) * 2) * 6;
        iVar3 = iVar4 + 2;
        if (*(u16*)(iVar4 + 2) == 0) {
            memcpy(param_1 + iVar7, iVar3 + 2, 1);
            iVar7 = iVar7 + 1;
            iVar3 = iVar5;
        }
        uVar8 = uVar8 >> 1;
        if (uVar8 == 1) {
            uVar6 = uVar6 + 1;
            uVar8 = *(u16*)(iVar2 + uVar6 * 2) | 0x10000;
        }
        iVar9 = iVar9 + -1;
    } while (iVar9 != 0);

    DAT_00764590 = iVar7;
    return iVar7;
}



// FUN_002850F0
void func_002850f0(u32* param_1, u32* param_2, int param_3, int param_4)
{
    int cVar4;
    u32* puVar1;
    u32* puVar2;
    u32* puVar3;

    cVar4 = '\0';
    puVar2 = (u32*)0x0;
    puVar1 = param_2;

    do {
        *puVar1 = (u32)puVar2;
        puVar3 = (u32*)((int)puVar1 + param_4);
        puVar1[1] = (u32)puVar3;
        puVar1[2] = (int)(s8)cVar4;
        puVar2 = puVar1;
        puVar1 = puVar3;
        param_3 = param_3 + -1;
        cVar4 = (s8)(cVar4 + 1);
    } while (1 < param_3);

    *puVar1 = (u32)puVar2;
    puVar1[1] = 0;
    puVar1[2] = (int)(s8)cVar4;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = (u32)param_2;
    param_1[3] = (u32)puVar1;
}



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
