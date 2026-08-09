/* Whole-file translation unit: src/Event/Fcl/fclMisc.c */

/* Source unit: src/Event/Fcl/fclMisc.c */
#include "include_asm.h"
#include "type.h"

// Donor calls this implicitly (no prototype), so keep the old-style form.
extern s32 func_00277840();

extern int *func_002e2240(int *, int *, int *);

// P3 counterpart iGpffffb98c (gp -0x4674, absolute 0x007ce67c); P4 retail
// uses gp -0x4A84, i.e. absolute 0x007690f0 - 0x4a84 = 0x0076466c.
extern int iGpffffb57c;

// P3 counterpart piGpffffb98c (gp -0x4674, absolute 0x007ce67c); P4 retail
// uses gp -0x4A84, i.e. absolute 0x007690f0 - 0x4a84 = 0x0076466c.
extern int *piGpffffb57c;
extern u32 func_002bd730();
extern void func_002777f0();

extern s32 func_00276e10(s32);

// Donor calls these implicitly (no prototypes), so keep old-style forms.
extern void func_00276e70();
extern void func_00277250();
extern void func_00277ad0();
extern s32 func_002774d0(s32);
extern void func_00278610(s32, s32);
extern void func_00278170(s32, s32);
extern void func_002778c0(s32, s32, s32);
extern void func_002818a0(s32, s32);
extern u8 *func_002e1db0(s32, s32, s32, s32);
extern s32 func_00451de0(void *, s32, s32, s32, void *, void *, void *);
extern u8 D_0063F398[];
extern u8 D_00882F30[];
extern s32 func_002bce00(void);



// FUN_0027BE90
void func_0027be90(u64 param_1, u32 param_2)
{
    int iVar1;

    iVar1 = func_00277840();
    *(u32 *)(iVar1 + 0x18) = param_2;
}



// FUN_002BCC60
u64 func_002bcc60(int *param_1)
{
    int *item;
    int *node;

    item = *(int **)(param_1[6] + 4);
    while (item != 0) {
        node = *(int **)((u8 *)item + 0x14);
        if (*(int *)((u8 *)node + 8) == 0) {
            item = func_002e2240((int *)param_1[6], (int *)(param_1[6] + 4), item);
        }
        else {
            item = *(int **)((u8 *)item + 0x10);
        }
    }
    item = *(int **)(*param_1 + 4);
    while (item != 0) {
        node = *(int **)((u8 *)item + 0x14);
        if ((*(u32 *)((u8 *)node + 4) & 2) == 0) {
            item = func_002e2240((int *)*param_1, (int *)(*param_1 + 4), item);
        }
        else {
            item = *(int **)((u8 *)item + 0x10);
        }
    }
    return 0;
}
// FUN_002BCD20
void func_002bcd20(void)
{
    u8 *work;
    u8 *state;
    u8 *globalState;

    globalState = D_00882F30;
    work = func_002e1db0(0xa0, 0, 0, 0);
    state = *(u8 **)(work + 0x24);
    *(u8 **)state = work;
    *(u8 **)(state + 0x18) = func_002e1db0(0xc, 0, 0, 0);
    *(s32 *)(state + 4) |= 1;
    iGpffffb57c = (int)state;
    if (globalState != NULL)
    {
        *(s32 *)globalState = -1;
        *(s8 *)(globalState + 4) = 0;
        *(s8 *)(globalState + 5) = 0;
        *(s32 *)(globalState + 8) = -1;
        *(s8 *)(globalState + 0xc) = 1;
        *(s8 *)(globalState + 0xd) = 1;
    }
    func_00451de0(D_0063F398, 0xf, 0, 0, (void *)func_002bce00, 0, 0);
}



// FUN_002BCE00
INCLUDE_ASM("asm/nonmatchings/fclMisc", func_002bce00);
// FUN_002BCFB0
INCLUDE_ASM("asm/nonmatchings/fclMisc", func_002bcfb0);
// FUN_002BD1E0
s32 func_002bd1e0(s32 param_1)
{
    u8* entry;

    entry = (u8*)iGpffffb57c;
    entry = (u8*)(param_1 * 0xc) + (u32)entry;
    if ((*(s32*)(entry + 0x1c) & 2) == 0)
    {
        return 0;
    }
    return *(s32*)(entry + 0x24);
}
// FUN_002BD220
u8 func_002bd220(void)
{
    return *(int *)(*(int *)(iGpffffb57c + 0x18) + 4) == 0;
}



// FUN_002BD240
void func_002bd240(u32 param_1)
{
    *(u32 *)(iGpffffb57c + 0x14) = *(u32 *)(iGpffffb57c + 0x14) | param_1;
}



// FUN_002BD340
u16 func_002bd340(void)
{
    return *(u16 *)(*piGpffffb57c + 0x10);
}



// FUN_002BD360
u32 func_002bd360(int param_1, int param_2)
{
    int iVar1;

    iVar1 = *(int *)(*piGpffffb57c + 4);
    while (iVar1 != 0) {
        if ((*(int *)(*(int *)(iVar1 + 0x14) + 0x2c) == param_1) &&
            (*(int *)(*(int *)(iVar1 + 0x14) + 0x20) == param_2)) {
            return 1;
        }
        iVar1 = *(int *)(iVar1 + 0x10);
    }
    return 0;
}



// FUN_002BD3C0
void func_002bd3c0(void)
{
    *(u32 *)(iGpffffb57c + 4) = *(u32 *)(iGpffffb57c + 4) | 2;
}



// FUN_002BD440
void func_002bd440(void)
{
    u8 *context;

    if (*(int *)(*piGpffffb57c + 4) != 0) {
        context = *(u8 **)(*(int *)(*piGpffffb57c + 4) + 0x14);
        if ((*(u32 *)(context + 4) & 2) != 0) {
            func_002bd730(context + 0x10);
            *(u32 *)(context + 4) |= 4;
        }
    }
}



// FUN_002BD4A0
s32 func_002bd4a0(u8 *param_1, s32 param_2)
{
    s32 value;

    if (param_1 != NULL)
    {
        * (s32 *)param_1 = -1;
        *(s8 *)(param_1 + 4) = 0;
        *(s8 *)(param_1 + 5) = 0;
        *(s32 *)(param_1 + 8) = -1;
        *(s8 *)(param_1 + 0xc) = 1;
        *(s8 *)(param_1 + 0xd) = 1;
    }
    if (*(s32 *)param_1 < 0)
    {
        value = func_002774d0(param_2);
        *(s32 *)param_1 = value;
        func_00278610(value, 2);
        return 1;
    }
    return 0;
}
// FUN_002BD530
void func_002bd530(int *param_1)
{
    func_002bd730(param_1);

    if (*param_1 >= 0) {
        func_002777f0(*param_1);
        *param_1 = -1;
        *(u8 *)(param_1 + 1) = 0;
        *(u8 *)((int)param_1 + 5) = 0;
    }
}



// FUN_002BD580
s32 func_002bd580(u8 *param_1, s32 param_2, s32 param_3)
{
    s32 value;

    value = *(s32 *)param_1;
    if (value < 0)
    {
        return 0;
    }
    func_00278170(value, 0x200000);
    func_002778c0(*(s32 *)param_1, param_3, 0);
    func_002818a0(*(s32 *)param_1, param_2);
    *(s8 *)(param_1 + 4) = 1;
    return 0;
}
// FUN_002BD610
s8 func_002bd610(int *param_1)
{
    s8 result;

    if (*param_1 < 0) {
        result = 0;
    }
    else if ((*(s8 *)((u8 *)param_1 + 5) != 0) && (*(s8 *)((u8 *)param_1 + 4) == 2)) {
        result = 0;
    }
    else {
        result = *(s8 *)((u8 *)param_1 + 4);
    }
    return result;
}



// FUN_002BD660
void func_002bd660(int *param_1)
{
    int state;
    s8 mode;

    state = *param_1;
    if (state < 0) {
        return;
    }
    mode = *(s8 *)((u8 *)param_1 + 4);
    switch (mode) {
    case 0:
        return;
    case 1:
        if (func_00276e10(state) < 0) {
            *(u8 *)(param_1 + 1) = 2;
        }
        break;
    case 2:
        if (param_1[2] >= 0) {
            param_1[2] = -1;
        }
        if (*(s8 *)((u8 *)param_1 + 5) == 0) {
            *(u8 *)(param_1 + 1) = 3;
        }
        break;
    case 3:
        func_002bd730((u32 *)param_1);
        break;
    }
}



// FUN_002BD730
u32 func_002bd730(u32 *param_1)
{
    u32 result;

    if (param_1 == 0) {
        result = 0;
    }
    else if ((s32)*param_1 < 0) {
        result = 0;
    }
    else {
        func_00276e70(*param_1, 0);
        func_00277250(*param_1);
        func_00277ad0(*param_1, 0);
        *((u8 *)param_1 + 4) = 0;
        result = 1;
    }
    return result;
}
