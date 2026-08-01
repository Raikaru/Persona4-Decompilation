/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00290EC0)
/* Source unit: src/Event/mt_misc_00290ec0.c */
#include "type.h"

/* opt_loop_invariants on: measured nd 124 -> 0, object 292/304 -> 292/304. */
// FUN_00290EC0
void func_00290ec0(int param_1, u32 param_2)
{
    int iVar1;

    iVar1 = *(int *)(param_1 + 4) * 0x2c;
    iVar1 = iVar1 + param_1;

    *(u8 *)(iVar1 + 0x14) = 0;
    *(u32 *)(iVar1 + 0x10) = 0;
    *(u32 *)(iVar1 + 0x38) = 0;
    *(u32 *)(iVar1 + 0x34) = param_2;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;

    return;
}
#endif /* P4_UNIT_00290EC0 */

#if defined(P4_UNIT_00291060)
/* Source unit: src/Event/mt_misc_00291060.c */
#include "type.h"

// FUN_00291060
void func_00291060(u32 *param_1)
{
    *param_1 = 1;
    param_1[2] = 0;

    return;
}
#endif /* P4_UNIT_00291060 */

#if defined(P4_UNIT_00291360)
/* Source unit: src/Event/mt_misc_00291360.c */
#include "type.h"

extern int func_00145250();

// FUN_00291360
u16 func_00291360(int param_1, int param_2)
{
    int lVar2;

    if (param_2 >= 0x10) {
        return 0;
    }

    lVar2 = func_00145250();

    if (lVar2 == 0) {
        return 0;
    }

    return *(u16 *)((u8 *)((int)param_2 * 2) + param_1 + 0x170);
}
#endif /* P4_UNIT_00291360 */

#if defined(P4_UNIT_00298100)
/* Source unit: src/Event/mt_misc_00298100.c */
#include "type.h"

extern int func_0045a3e0();

// FUN_00298100
u64 func_00298100(s16 param_1)
{
    func_0045a3e0(param_1, 1);

    return 0;
}
#endif /* P4_UNIT_00298100 */

#if defined(P4_UNIT_00298190)
/* Source unit: src/Event/mt_misc_00298190.c */
#include "type.h"

extern int func_0045aac0();
extern int func_0045a9a0();

// FUN_00298190
u64 func_00298190(s16 param_1, int param_2)
{
    int iVar1;

    iVar1 = param_2;
    if (iVar1 != 0) {
        func_0045aac0(param_1, 0, param_2);
    }
    else {
        func_0045a9a0(param_1, 0, param_2);
    }

    return 0;
}
#endif /* P4_UNIT_00298190 */

#if defined(P4_UNIT_00291220)
/* Source unit: src/Event/mt_misc_00291220.c */
#include "type.h"

extern void *func_00145250(void);
extern void *MT_Scene_GetRes(u16);
extern void func_00146630(u16);
extern u16 func_001459b0(u32, int, u64);
extern void func_00440b68(...);
extern void func_00269c20(u16, int);
extern char DAT_0063c8a0[];

// FUN_00291220
void func_00291220(int param_1, int param_2, int param_3, u64 param_4)
{
    u16 sVar1;
    u16 uVar2;
    u16 *puVar5;
    int iVar4;

    if (((param_2 < 0x10) && (param_3 < *(int *)(param_1 + 4))) &&
        func_00145250() != 0) {
        iVar4 = (int)param_2 * 2;
        iVar4 = iVar4 + param_1;
        puVar5 = (u16 *)(iVar4 + 0x170);
        sVar1 = *(u16 *)(iVar4 + 0x170);
        if (sVar1 != 0) {
            if (MT_Scene_GetRes(sVar1) != 0) {
                func_00146630(sVar1);
            }
            *puVar5 = 0;
        }
        if (*(int *)(param_1 + 4) <= param_3) {
            iVar4 = 0;
        }
        else {
            iVar4 = *(int *)((u8 *)(uintptr_t)(param_3 * 0x2c) + (uintptr_t)param_1 + 0x34);
        }
        if (iVar4 != 0) {
            uVar2 = func_001459b0((int)param_2 + 200U & 0xffff, iVar4, param_4);
            func_00440b68(DAT_0063c8a0, uVar2);
            func_00269c20(uVar2, 1);
            *puVar5 = uVar2;
        }
    }
    return;
}
#endif /* P4_UNIT_00291220 */

#if defined(P4_UNIT_002913D0)
/* Source unit: src/Event/mt_misc_002913d0.c */
#include "type.h"

extern int func_00145250();
extern int MT_Scene_GetRes();
extern int func_00146630();
extern void func_00440b68(...);
extern char DAT_0063c8c0[];

// FUN_002913D0
void func_002913d0(int param_1, int param_2)
{
    u16 *puVar5;
    u16 sVar1;
    int iVar4;

    if ((param_2 < 0x10) && (func_00145250() != 0)) {
        iVar4 = (int)param_2 * 2;
        iVar4 = iVar4 + param_1;
        puVar5 = (u16 *)(iVar4 + 0x170);
        sVar1 = *(u16 *)(iVar4 + 0x170);
        if (sVar1 != 0) {
            if (MT_Scene_GetRes(sVar1) != 0) {
                func_00146630(sVar1);
                func_00440b68(DAT_0063c8c0);
            }
            *puVar5 = 0;
        }
    }
    return;
}
#endif /* P4_UNIT_002913D0 */

#if defined(P4_UNIT_00291470)
/* Source unit: src/Event/mt_misc_00291470.c */
#include "type.h"

extern int func_00145250();
extern int MT_Scene_GetRes();
extern int func_00146630();
extern void func_00440b68(...);
extern char DAT_0063c8c0[];

// FUN_00291470
void func_00291470(int param_1)
{
    u16 *puVar5;
    u16 sVar1;
    int iVar3;
    int iVar4;

    for (iVar4 = 0; iVar4 < 0x10; iVar4 = iVar4 + 1) {
        if ((iVar4 < 0x10) && (func_00145250() != 0)) {
            iVar3 = param_1 + iVar4 * 2;
            puVar5 = (u16 *)(iVar3 + 0x170);
            sVar1 = *(u16 *)(iVar3 + 0x170);
            if (sVar1 != 0) {
                if (MT_Scene_GetRes(sVar1) != 0) {
                    func_00146630(sVar1);
                    func_00440b68(DAT_0063c8c0);
                }
                *puVar5 = 0;
            }
        }
    }
    return;
}
#endif /* P4_UNIT_00291470 */
