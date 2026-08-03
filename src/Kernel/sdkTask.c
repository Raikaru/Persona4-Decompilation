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
    void* unk30;               /* 0x30 */
    void (*unk34)(struct KwlnTask*); /* 0x34 */
    u8 unk38[0x3C - 0x38];
    struct KwlnTask* listNext; /* 0x3C */
    struct KwlnTask* listPrev; /* 0x40 */
    struct KwlnTask* listPrev2; /* 0x44 */
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
s32 func_00452080(KwlnTask* a0);
void func_00450f20(KwlnTask* a0);
void func_00451110(KwlnTask* a0);
s32 func_00451430(KwlnTask* a0);
void func_004515b0(void);
void func_00451770(KwlnTask* a0);
void func_004518e0(KwlnTask* a0);
/* GP-relative current-task pointer at gp -0x45EC (absolute 0x00764B04). */
extern KwlnTask* iGpffffba14;
extern void (*jtbl_008873FC[])(...);
extern void func_0046d730(const void* file, u32 line);
extern char D_00710568[];
extern void func_0046d740(const void* file, const void* file2, u32 line);
extern char D_00710580[];
extern char D_00710550[];
extern char D_00710598[];
extern char D_007105B0[];
extern char D_007105D0[];
extern void func_00440b68();
extern void func_0043f9c8(void* a0, s32 a1, s32 a2);
extern void func_0043f810(void* a0, void* a1, s32 a2);
extern u8 D_008BFF70[];
extern u8 D_008BFF74[];
extern u8 D_008C0240[];
extern s32 D_008C02E0[];
extern void* (*D_008873F8[])(s32, s32);
/* GP-relative list tails and counts: tails gp-0x4610/0x45F8/0x4604,
 * counts gp-0x460C/0x45F4/0x4600 (absolute 0x00764AE0/0x00764AF8/0x00764AEC
 * and 0x00764AE4/0x00764AFC/0x00764AF0). */
extern KwlnTask* iGpffffb9f0;
extern s32 iGpffffb9f4;
extern KwlnTask* iGpffffba08;
extern s32 iGpffffba0c;
extern KwlnTask* iGpffffb9fc;
extern s32 iGpffffba00;
/* GP-relative processing-task pointer at gp -0x45F0 (absolute 0x00764B00). */
extern KwlnTask* iGpffffba10;
/* GP-relative debug strings at gp -0x53A4/-0x53A0/-0x5398/-0x5390. */
extern char iGpffffac5c;
extern char iGpffffac60;
extern char iGpffffac68;
extern char iGpffffac70;


extern KwlnTask* kwlnTaskGetTaskByName(const char* name);
extern u8 kwlnTaskDestroyWithHierarchy(KwlnTask* task);



// FUN_00450F20
void func_00450f20(KwlnTask* task)
{
    KwlnTask* prev;
    KwlnTask* next;
    s32 state;

    state = task->flags & 0xF;
    switch (state)
    {
    default:
err:
        func_0046d740(D_00710550, D_00710568, 0x3F);
        break;
    case 1:
    case 2:
    case 3:
        if (iGpffffba14 == task)
        {
            iGpffffba14 = task->listPrev;
        }
        prev = task->listPrev;
        if (prev != 0)
        {
            prev->listNext = task->listNext;
        }
        else
        {
            switch (task->flags & 0xF)
            {
            case 1:
                iGpffffb9ec = task->listNext;
                break;
            case 2:
                iGpffffba04 = task->listNext;
                break;
            case 3:
                iGpffffb9f8 = task->listNext;
                break;
            }
        }
        next = task->listNext;
        if (next != 0)
        {
            prev = task->listPrev;
            next->listPrev2 = prev;
            task->listNext->listPrev = prev;
        }
        else
        {
            switch (task->flags & 0xF)
            {
            case 1:
                iGpffffb9f0 = task->listPrev;
                break;
            case 2:
                iGpffffba08 = task->listPrev;
                break;
            case 3:
                iGpffffb9fc = task->listPrev;
                break;
            }
        }
        task->listNext = 0;
        task->listPrev = 0;
        switch (task->flags & 0xF)
        {
        case 1:
            iGpffffb9f4--;
            break;
        case 2:
            iGpffffba0c--;
            break;
        case 3:
            iGpffffba00--;
            break;
        }
        break;
    case 0:
        goto err;
    }
}

// FUN_00451110
void func_00451110(KwlnTask* task)
{
    s32 state;
    KwlnTask* node;
    KwlnTask* prev;

    state = task->flags & 0xF;
    switch (state)
    {
    case 1:
        node = iGpffffb9ec;
        break;
    case 2:
        node = iGpffffba04;
        break;
    case 3:
        node = iGpffffb9f8;
        break;
    default:
err:
        func_0046d740(D_00710550, D_00710568, 0xCE);
        return;
    case 0:
        goto err;
    }
    if (node == 0)
    {
        switch (state)
        {
        case 1:
            iGpffffb9ec = task;
            iGpffffb9f0 = task;
            break;
        case 2:
            iGpffffba04 = task;
            iGpffffba08 = task;
            break;
        case 3:
            iGpffffb9f8 = task;
            iGpffffb9fc = task;
            break;
        }
        task->listPrev2 = 0;
        task->listPrev = 0;
        task->listNext = 0;
    }
    else
    {
        while (node != 0)
        {
            if ((u32)*(u32*)((u8*)node + 0x20) > (u32)*(u32*)((u8*)task + 0x20))
            {
                if (node->listPrev != 0)
                {
                    node->listPrev->listNext = task;
                    prev = node->listPrev;
                    task->listPrev2 = prev;
                    task->listPrev = prev;
                    task->listNext = node;
                    node->listPrev2 = task;
                    node->listPrev = task;
                }
                else
                {
                    switch (state)
                    {
                    case 1:
                        iGpffffb9ec = task;
                        break;
                    case 2:
                        iGpffffba04 = task;
                        break;
                    case 3:
                        iGpffffb9f8 = task;
                        break;
                    }
                    task->listPrev = 0;
                    task->listNext = node;
                    node->listPrev2 = task;
                    node->listPrev = task;
                }
                break;
            }
            node = node->listNext;
        }
        if (node == 0)
        {
            switch (task->flags & 0xF)
            {
            case 1:
                iGpffffb9f0->listNext = task;
                prev = iGpffffb9f0;
                task->listPrev2 = prev;
                task->listPrev = prev;
                iGpffffb9f0 = task;
                break;
            case 2:
                iGpffffba08->listNext = task;
                prev = iGpffffba08;
                task->listPrev2 = prev;
                task->listPrev = prev;
                iGpffffba08 = task;
                break;
            case 3:
                iGpffffb9fc->listNext = task;
                prev = iGpffffb9fc;
                task->listPrev2 = prev;
                task->listPrev = prev;
                iGpffffb9fc = task;
                break;
            }
            task->listNext = 0;
        }
    }
    switch (task->flags & 0xF)
    {
    case 1:
        iGpffffb9f4++;
        if (iGpffffb9f4 > 0x3E8)
        {
            func_0046d730(D_00710568, 0x121);
        }
        break;
    case 2:
        iGpffffba0c++;
        if (iGpffffba0c > 0x3E8)
        {
            func_0046d730(D_00710568, 0x125);
        }
        break;
    case 3:
        iGpffffba00++;
        if (iGpffffba00 > 0x3E8)
        {
            func_0046d730(D_00710568, 0x129);
        }
        break;
    }
}

// FUN_00451430
/* measured: without opt_loop_invariants the D_008C0240 base address and the
 * 0x80 constant are rematerialized inside the init loop (nd 68); with it they
 * hoist to the preheader and the function matches byte-for-byte. */
#pragma opt_loop_invariants on
s32 func_00451430(KwlnTask* task)
{
    s32 (*fn)(KwlnTask*);
    u8* ptr;
    s32 result;
    s32 i;

    if (task->flags & 0x20)
    {
        return 1;
    }
    iGpffffba10 = task;
    if (task->flags & 0x10)
    {
        func_0043f9c8(D_008C0240, 0, 0x94);
        for (i = 0; i < 2; i++)
        {
            ptr = (u8*)D_008C0240 + i * 0x4A;
            *(u16*)(ptr + 0x16) = 0x80;
            *(u16*)(ptr + 0x18) = 0x80;
            *(u16*)(ptr + 0x1A) = 0x80;
            *(u8*)(ptr + 0x1C) = 0x80;
            *(u8*)(ptr + 0x1D) = 0x80;
            *(u8*)(ptr + 0x1E) = 0x80;
            *(u8*)(ptr + 0x1F) = 0x80;
        }
    }
    else
    {
        func_0043f810(D_008C0240, D_008C02E0, 0x94);
    }
    fn = (s32 (*)(KwlnTask*))task->unk30;
    if (fn != 0 && fn != (s32 (*)(KwlnTask*))-1)
    {
        result = fn(task);
        if (result != 0)
        {
            task->unk30 = (void*)result;
        }
        if (result == -1 && (task->flags & 0xF) == 2)
        {
            func_00451770(task);
            func_004518e0(task->childList);
            iGpffffba10 = 0;
            return 0;
        }
    }
    task->unk28++;
    iGpffffba10 = 0;
    return 1;
}
/* measured: see the annotation above the matching `on` pragma (func_00451430). */
#pragma opt_loop_invariants off

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
void func_00451770(KwlnTask* task)
{
    KwlnTask* node;
    KwlnTask* next;
    s32 state;

    state = task->flags & 0xF;
    if (state == 0)
    {
        goto err;
    }
    if (state == 3)
    {
        goto done;
    }
    switch (state)
    {
    case 1:
    case 2:
        goto body;
    default:
        goto err;
    }
done:
    return;
err:
    func_00440b68(D_00710580);
    func_0046d730(D_00710568, 0x308);
    return;
body:
    func_00450f20(task);
    task->flags = (task->flags & ~0xF) | 3;
    func_00451110(task);
    if (task->unk2E == 0)
    {
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
    return;
}

// FUN_004518E0
void func_004518e0(KwlnTask* task)
{
    KwlnTask* node;
    KwlnTask* child;

    if (task == 0)
    {
        return;
    }
    node = task;
    while (node != 0)
    {
        child = node->childList;
        if (child != 0)
        {
            while (child != 0)
            {
                func_004518e0(child->childList);
                func_00451770(child);
                child = child->next;
            }
        }
        switch (node->flags & 0xF)
        {
        default:
err:
            func_00440b68(D_00710580);
            func_0046d730(D_00710568, 0x308);
            break;
        case 1:
        case 2:
            func_00450f20(node);
            node->flags = (node->flags & ~0xF) | 3;
            func_00451110(node);
            if (node->unk2E == 0)
            {
                func_004516b0(node);
            }
            break;
        case 3:
            break;
        case 0:
            goto err;
        }
        node = node->next;
    }
}

// FUN_00451A10
void func_00451a10(KwlnTask* task, s32 depth)
{
    func_00440b68(D_00710598, D_008BFF70, task, *(u32*)((u8*)task + 0x20));
    if (task->flags & 0x20)
    {
        func_00440b68(&iGpffffac60);
    }
    if (task->flags & 0x10)
    {
        func_00440b68(&iGpffffac68);
    }
    func_00440b68(&iGpffffac70);
    if (task->childList != 0)
    {
        if (task->parent == 0)
        {
            D_008BFF70[0] = 0x20;
        }
        else if (task->next == 0)
        {
            D_008BFF70[depth * 4] = 0x20;
        }
        else
        {
            D_008BFF70[depth * 4] = 0x7C;
        }
        D_008BFF74[depth * 4] = 0;
        func_00451a10(task->childList, depth + 1);
        D_008BFF70[depth * 4] = 0;
    }
    if (task->next != 0)
    {
        func_00451a10(task->next, depth);
    }
}

// FUN_00451B70
/* measured: without opt_loop_invariants the 0x20 constant and the D_008BFF70
 * base address are rematerialized inside the fill loop (nd 65); with it they
 * hoist to the preheader and the function matches byte-for-byte. */
#pragma opt_loop_invariants on
void func_00451b70(void)
{
    s32 i;
    KwlnTask* node;

    func_00440b68(D_007105B0);
    for (i = 0; i < 0x40; i++)
    {
        D_008BFF70[i] = 0x20;
    }
    node = iGpffffb9ec;
    while (node != 0)
    {
        if (node->parent == 0)
        {
            D_008BFF70[0] = 0;
            func_00451a10(node, 0);
        }
        node = node->listNext;
    }
    node = iGpffffba04;
    while (node != 0)
    {
        if (node->parent == 0)
        {
            D_008BFF70[0] = 0;
            func_00451a10(node, 0);
        }
        node = node->listNext;
    }
    node = iGpffffb9f8;
    while (node != 0)
    {
        if (node->parent == 0)
        {
            D_008BFF70[0] = 0;
            func_00451a10(node, 0);
        }
        node = node->listNext;
    }
    func_00440b68(&iGpffffac5c);
}
/* measured: see the annotation above the matching `on` pragma (func_00451b70). */
#pragma opt_loop_invariants off
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
void* func_00451de0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6)
{
    KwlnTask* task;
    s8* dst;
    s8* name;
    s32 i;

    name = (s8*)a0;
    if (name[0] == 0)
    {
        func_0046d730(D_00710568, 0x4A9);
    }
    task = D_008873F8[0](iGpffffba18, 0x41001);
    if (task == 0)
    {
        func_0046d730(D_00710568, 0x4B5);
    }
    if (task == 0)
    {
        return 0;
    }
    task->nameSum = 0;
    dst = (s8*)task;
    i = 0;
    while ((dst[i] = name[i]) != 0 && i < 0x18)
    {
        task->nameSum += name[i];
        i++;
    }
    ((u8*)task)[0x17] = 0;
    task->flags = 0;
    task->flags |= 1;
    *(u32*)((u8*)task + 0x20) = a1;
    task->unk24 = 0;
    task->unk28 = 0;
    task->unk2C = (u16)a2;
    task->unk2E = (u16)a3;
    *(u32*)((u8*)task + 0x30) = a4;
    *(u32*)((u8*)task + 0x34) = a5;
    *(u32*)((u8*)task + 0x38) = a6;
    task->listNext = 0;
    *(u32*)((u8*)task + 0x40) = 0;
    *(u32*)((u8*)task + 0x44) = 0;
    task->parent = 0;
    task->childList = 0;
    task->next = 0;
    if (task->unk2E < 2)
    {
        task->unk2E = 2;
    }
    func_00451110(task);
    if (task->unk2C == 0)
    {
        func_00450f20(task);
        task->flags = (task->flags & ~0xF) | 2;
        func_00451110(task);
        task->unk24 = 0;
        task->unk28 = 0;
    }
    return task;
}
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
s32 func_00452080(KwlnTask* task)
{
    KwlnTask* node;
    KwlnTask* child;
    s32 state;

    if (task == 0 || task == (KwlnTask*)-1)
    {
        func_0046d740(D_007105D0, D_00710568, 0x516);
        return 0;
    }
    state = task->flags & 0xF;
    switch (state)
    {
    case 1:
    case 2:
        switch (state)
        {
        default:
inner_err:
            func_00440b68(D_00710580);
            func_0046d730(D_00710568, 0x308);
            break;
        case 1:
        case 2:
            func_00450f20(task);
            task->flags = (task->flags & ~0xF) | 3;
            func_00451110(task);
            if (task->unk2E == 0)
            {
                func_004516b0(task);
            }
            break;
        case 3:
            break;
        case 0:
            goto inner_err;
        }
        task = task->childList;
        if (task != 0)
        {
            while (task != 0)
            {
                func_004518e0(task->childList);
                func_00451770(task);
                task = task->next;
            }
        }
        break;
    case 3:
        if (task->unk2E == 0)
        {
            node = task->childList;
            while (node != 0)
            {
                child = node->next;
                func_00452080(node);
                node = child;
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
        break;
    default:
outer_err:
        func_0046d740(D_007105D0, D_00710568, 0x52C);
        return 0;
    case 0:
        goto outer_err;
    }
    return 1;
}

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
/* measured: without opt_loop_invariants the switch-case constants and the
 * three list heads are rematerialized inside the dispatch loop; with it they
 * hoist to the preheader and the function matches byte-for-byte. */
#pragma opt_loop_invariants on
u8* func_00452380(s8* name)
{
    KwlnTask* node;
    s32 listIdx;
    s32 i;
    s32 len;
    s32 sum;
    s8 c;

    node = 0;
    sum = 0;
    len = 0;
    while ((c = name[len]) != 0)
    {
        sum += c;
        len++;
    }
    for (listIdx = 0; listIdx < 3; listIdx++)
    {
        switch (listIdx)
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
            if (node->nameSum == sum)
            {
                i = len;
                while (name[i] == ((s8*)node)[i])
                {
                    if (i == 0)
                    {
                        return (u8*)node;
                    }
                    i--;
                }
            }
            node = node->listNext;
        }
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_00452380). */
#pragma opt_loop_invariants off

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

