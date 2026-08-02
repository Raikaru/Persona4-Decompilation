#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit sdkTask.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern s32 func_003e1220(u32 a0, u32 a1, u32 a2, u32 a3, void* a4, u32 a5);
/* GP-relative scalar at gp -0x45E8 (absolute 0x00764B08). */
extern s32 iGpffffba18;
extern u32 D_008BFFB0[];

typedef struct KwlnTask
{
    u8 unk0[0x18];
    s32 nameSum;               /* 0x18 */
    u32 flags;                 /* 0x1C */
    u8 unk20[0x24 - 0x20];
    u32 unk24;                 /* 0x24 */
    u32 unk28;                 /* 0x28 */
    u16 unk2C;                 /* 0x2C */
    u16 unk2E;                 /* 0x2E */
    u8 unk30[0x34 - 0x30];
    void (*unk34)(struct KwlnTask*); /* 0x34 */
    u8 unk38[0x3C - 0x38];
    struct KwlnTask* listNext; /* 0x3C */
    u8 unk40[0x48 - 0x40];
    struct KwlnTask* parent;   /* 0x48 */
    struct KwlnTask* childList; /* 0x4C */
    struct KwlnTask* next;     /* 0x50 */
} KwlnTask;

/* GP-relative list heads: gp -0x4614 (0x00764ADC), gp -0x4608 (0x00764AE8), gp -0x45FC (0x00764AF4). */
extern void* iGpffffb9ec;
extern void* iGpffffb9f8;
extern KwlnTask* iGpffffba04;

void* func_00451de0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
void func_00452570(KwlnTask* a0, KwlnTask* a1);
void func_00452600(KwlnTask* a0);
void func_00452080(void* a0);
void func_00450f20(void* a0);
void func_004526a0(void* a0);
void func_00451110(void* a0);
void func_004515b0(void);
/* GP-relative current-task pointer at gp -0x45EC (absolute 0x00764B04). */
extern KwlnTask* iGpffffba14;
s32 func_00451430(void* a0);
extern void (*jtbl_008873FC[])(...);
extern void func_0046d730(const void* file, u32 line);
extern char D_00710568[];
extern void func_0046d740(const void* file, const void* file2, u32 line);
extern char D_00710580[];


extern KwlnTask* kwlnTaskGetTaskByName(const char* name);
extern u8 kwlnTaskDestroyWithHierarchy(KwlnTask* task);



// FUN_00450F20
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00450f20);

// FUN_00451110
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00451110);

// FUN_00451430
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00451430);

// FUN_004515B0
void func_004515b0(void)
{
    KwlnTask* node;

    node = iGpffffba04;
    while (node != 0)
    {
        iGpffffba14 = node;
        if (func_00451430(node) != 0)
        {
            if (node != iGpffffba14)
            {
                if ((iGpffffba14->flags & 0xF) != 2)
                {
                    func_0046d730(D_00710568, 0x22F);
                }
                if (iGpffffba14 != 0)
                {
                    node = iGpffffba14->listNext;
                }
                else
                {
                    node = iGpffffba04;
                }
            }
            else
            {
                if ((node->flags & 0xF) != 2)
                {
                    func_0046d730(D_00710568, 0x236);
                }
                node = node->listNext;
            }
        }
        else
        {
            if (iGpffffba14 != 0)
            {
                node = iGpffffba14->listNext;
            }
            else
            {
                node = iGpffffba04->listNext;
            }
        }
    }
}
// FUN_004516B0
void func_004516b0(KwlnTask* task)
{
    KwlnTask* node;
    KwlnTask* next;

    node = task->childList;
    while (node != 0)
    {
        next = node->next;
        func_00452080(node);
        node = next;
    }
    func_00450f20(task);
    if (task->unk34 != 0)
    {
        task->unk34(task);
    }
    task->flags &= ~0xF;
    func_00452600(task);
    func_004526a0(task);
    jtbl_008873FC[0](iGpffffba18, task);
}
// FUN_00451770
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00451770);

// FUN_004518E0
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_004518e0);

// FUN_00451A10
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00451a10);

// FUN_00451B70
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00451b70);
// FUN_00451CA0
void func_00451ca0(s32 arg0)
{
    iGpffffba18 = func_003e1220(0x54, arg0, 4, 1, D_008BFFB0, 0x41001);
}



// FUN_00451CF0
s32 func_00451cf0(void)
{
    KwlnTask* node1;
    KwlnTask* cur1;
    KwlnTask* node2;
    KwlnTask* cur2;
    s32 timer;

    node1 = iGpffffb9ec;
    while (node1 != 0)
    {
        timer = node1->unk2C;
        if (timer > 0)
        {
            node1->unk2C = timer - 1;
        }
        cur1 = node1;
        node1 = node1->listNext;
        if (cur1->unk2C == 0)
        {
            func_00450f20(cur1);
            cur1->flags = (cur1->flags & ~0xF) | 2;
            func_00451110(cur1);
            cur1->unk24 = 0;
            cur1->unk28 = 0;
        }
    }
    func_004515b0();
    node2 = iGpffffb9f8;
    while (node2 != 0)
    {
        timer = node2->unk2E;
        if (timer > 0)
        {
            node2->unk2E = timer - 1;
        }
        cur2 = node2;
        node2 = node2->listNext;
        if (cur2->unk2E == 0)
        {
            func_004516b0(cur2);
        }
    }
    return 1;
}
// FUN_00451DE0
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00451de0);

// FUN_00451FC0
void* func_00451fc0(void* a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7)
{
    void* result;

    result = func_00451de0(a1, a2, a3, a4, a5, a6, a7);
    if (result != 0 && a0 != 0)
    {
        func_00452570(a0, result);
    }
    return result;
}
// FUN_00452040
u8 kwlnTaskDestroyWithHierarchyByName(const char* name)
{
    KwlnTask* task;

    task = kwlnTaskGetTaskByName(name);
    if (task == NULL)
    {
        return 0;
    }

    return kwlnTaskDestroyWithHierarchy(task);
}



// FUN_00452080
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00452080);

// FUN_004522D0
s32 func_004522d0(void* task)
{
    s32 state;

    if (func_00452490(task) == 0)
    {
        return 0;
    }

    state = *(u32*)((u8*)task + 0x1C) & 0xF;
    switch (state)
    {
    case 1:
    case 2:
    case 3:
    case 0:
        return state;
    default:
        func_0046d740(D_00710580, D_00710568, 0x57C);
        return 0;
    }
}
// FUN_00452380
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00452380);

// FUN_00452490
/* measured: without opt_loop_invariants the switch case constants are
 * rematerialized inside the loop (nd 25); with it they hoist to the
 * preheader and the function matches byte-for-byte. */
#pragma opt_loop_invariants on
s32 func_00452490(void* target)
{
    s32 idx;
    void* node;

    node = 0;
    idx = 0;
    for (; idx < 3; idx++)
    {
        switch (idx)
        {
        case 0:
            node = iGpffffb9ec;
            break;
        case 1:
            node = iGpffffba04;
            break;
        case 2:
            node = iGpffffb9f8;
            break;
        }
        while (node != 0)
        {
            if (node == target)
            {
                return 1;
            }
            node = *(void**)((u8*)node + 0x3C);
        }
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_00452490). */
#pragma opt_loop_invariants off
// FUN_00452540
u32 kwlnTaskGetTimer(void* task)
{
    return *(u32*)((u8*)task + 0x28);
}

// FUN_00452560
u32 func_00452560(void* task)
{
    return *(u32*)((u8*)task + 0x38);
}

// FUN_00452570
void func_00452570(KwlnTask* parent, KwlnTask* child)
{
    KwlnTask* node;
    KwlnTask* next;

    if (child->parent != 0)
    {
        func_00452600(child);
    }

    node = parent->childList;
    if (node != 0)
    {
        while ((next = node->next) != 0)
        {
            node = next;
        }
        node->next = child;
    }
    else
    {
        parent->childList = child;
    }
    child->parent = parent;
}

// FUN_00452600
INCLUDE_ASM("asm/nonmatchings/sdkTask", func_00452600);
