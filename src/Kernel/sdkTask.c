#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit sdkTask.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_pad_record.h"

extern s32 func_003e1220(u32 a0, u32 a1, u32 a2, u32 a3, void* a4, u32 a5);
/* GP-relative scalar at gp -0x45E8 (absolute 0x00764B08). */
extern s32 iGpffffba18;
extern u32 D_008BFFB0[];

struct KwlnTask
{
    s8 name[0x18];
    s32 nameSum;               /* 0x18 */
    u32 flags;                 /* 0x1C */
    u32 priority;              /* 0x20: ascending scheduler order */
    u32 unk24;                 /* 0x24 */
    u32 unk28;                 /* 0x28 */
    u16 unk2C;                 /* 0x2C */
    u16 unk2E;                 /* 0x2E */
    SdkTaskUpdate unk30;               /* 0x30 */
    SdkTaskDestroy unk34; /* 0x34 */
    u8 *work;
    struct KwlnTask* listNext; /* 0x3C */
    struct KwlnTask* listPrev; /* 0x40 */
    struct KwlnTask* listPrev2; /* 0x44 */
    struct KwlnTask* parent;   /* 0x48 */
    struct KwlnTask* childList; /* 0x4C */
    struct KwlnTask* next;     /* 0x50 */
};

/* GP-relative list heads: gp -0x4614 (0x00764ADC), gp -0x4608 (0x00764AE8), gp -0x45FC (0x00764AF4). */
extern void* iGpffffb9ec;
extern void* iGpffffb9f8;
extern KwlnTask* iGpffffba04;


void kwlnTaskAddChild(KwlnTask* parent, KwlnTask* child);
void kwlnTaskRemoveFromParent(KwlnTask* childTask);
u8 kwlnTaskDestroyWithHierarchy(KwlnTask* task);
void kwlnTaskUnlinkFromList(KwlnTask* task);
void kwlnTaskLinkToList(KwlnTask* task);
s32 kwlnTaskRunUpdate(KwlnTask* task);
void kwlnTaskRunList(void);
void kwlnTaskMoveToDying(KwlnTask* task);
void kwlnTaskKillSiblingChain(KwlnTask* task);
/* GP-relative current-task pointer at gp -0x45EC (absolute 0x00764B04). */
extern KwlnTask* iGpffffba14;
extern void (*jtbl_008873FC[])();
extern void kAssertFail(const void* file, u32 line);
extern char D_00710568[];
extern void kAssertFailAt(const void* msg, const void* file, u32 line);
extern char D_00710580[];
extern char D_00710550[];
extern char D_00710598[];
extern char D_007105B0[];
extern char D_007105D0[];
extern void func_00440b68();
extern void memset(void* a0, s32 a1, s32 a2);
extern void memcpy(void* a0, void* a1, s32 a2);
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



/* Unlink from the state-selected scheduler list, updating traversal and counts. */
// FUN_00450F20
void kwlnTaskUnlinkFromList(KwlnTask* task)
{
    KwlnTask* prev;
    KwlnTask* next;
    s32 state;

    state = task->flags & 0xF;
    switch (state)
    {
    default:
err:
        kAssertFailAt(D_00710550, D_00710568, 0x3F);
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

/* Insert into the state-selected list in ascending priority order. */
// FUN_00451110
void kwlnTaskLinkToList(KwlnTask* task)
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
        kAssertFailAt(D_00710550, D_00710568, 0xCE);
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
            if ((u32)node->priority > (u32)task->priority)
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
            kAssertFail(D_00710568, 0x121);
        }
        break;
    case 2:
        iGpffffba0c++;
        if (iGpffffba0c > 0x3E8)
        {
            kAssertFail(D_00710568, 0x125);
        }
        break;
    case 3:
        iGpffffba00++;
        if (iGpffffba00 > 0x3E8)
        {
            kAssertFail(D_00710568, 0x129);
        }
        break;
    }
}

/* Snapshot or mask input, invoke the update callback, and process its result. */
// FUN_00451430
/* measured: without opt_loop_invariants the D_008C0240 base address and the
 * 0x80 constant are rematerialized inside the init loop (nd 68); with it they
 * hoist to the preheader and the function matches byte-for-byte. */
#pragma opt_loop_invariants on
s32 kwlnTaskRunUpdate(KwlnTask* task)
{
    SdkTaskUpdate fn;
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
        memset(D_008C0240, 0, 0x94);
        for (i = 0; i < 2; i++)
        {
            ptr = (u8*)D_008C0240 + i * 0x4A;
            ((SdkPadRecord*)ptr)->directions = 0x80;
            ((SdkPadRecord*)ptr)->directionPressed = 0x80;
            ((SdkPadRecord*)ptr)->previousDirections = 0x80;
            ((SdkPadRecord*)ptr)->leftX = 0x80;
            ((SdkPadRecord*)ptr)->leftY = 0x80;
            ((SdkPadRecord*)ptr)->rightX = 0x80;
            ((SdkPadRecord*)ptr)->rightY = 0x80;
        }
    }
    else
    {
        memcpy(D_008C0240, D_008C02E0, 0x94);
    }
    fn = task->unk30;
    if (fn != 0 && fn != (SdkTaskUpdate)-1)
    {
        result = fn((u8 *)task);
        if (result != 0)
        {
            task->unk30 = (SdkTaskUpdate)result;
        }
        if (result == -1 && (task->flags & 0xF) == 2)
        {
            kwlnTaskMoveToDying(task);
            kwlnTaskKillSiblingChain(task->childList);
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

/* Visit runnable tasks while allowing callbacks to unlink the current node. */
// FUN_004515B0
void kwlnTaskRunList(void)
{
    KwlnTask* node;

    node = iGpffffba04;
    while (node != 0)
    {
        iGpffffba14 = node;
        if (kwlnTaskRunUpdate(node) != 0)
        {
            if (node != iGpffffba14)
            {
                if ((iGpffffba14->flags & 0xF) != 2)
                {
                    kAssertFail(D_00710568, 0x22F);
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
                    kAssertFail(D_00710568, 0x236);
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
/* Destroy descendants, invoke teardown, detach hierarchy links, and free the task. */
// FUN_004516B0
void kwlnTaskFinalize(KwlnTask* task)
{
    KwlnTask* node;
    KwlnTask* next;

    node = task->childList;
    while (node != 0)
    {
        next = node->next;
        kwlnTaskDestroyWithHierarchy(node);
        node = next;
    }
    kwlnTaskUnlinkFromList(task);
    if (task->unk34 != 0)
    {
        task->unk34((u8 *)task);
    }
    task->flags &= ~0xF;
    kwlnTaskRemoveFromParent(task);
    kwlnTaskDetachChildren(task);
    jtbl_008873FC[0](iGpffffba18, task);
}
/* Move a live task to the dying list; finalize immediately for a zero delay. */
// FUN_00451770
void kwlnTaskMoveToDying(KwlnTask* task)
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
    kAssertFail(D_00710568, 0x308);
    return;
body:
    kwlnTaskUnlinkFromList(task);
    task->flags = (task->flags & ~0xF) | 3;
    kwlnTaskLinkToList(task);
    if (task->unk2E == 0)
    {
        node = task->childList;
        while (node != 0)
        {
            next = node->next;
            kwlnTaskDestroyWithHierarchy(node);
            node = next;
        }
        kwlnTaskUnlinkFromList(task);
        if (task->unk34 != 0)
        {
            task->unk34((u8 *)task);
        }
        task->flags &= ~0xF;
        kwlnTaskRemoveFromParent(task);
        kwlnTaskDetachChildren(task);
        jtbl_008873FC[0](iGpffffba18, task);
    }
    return;
}

/* Mark a sibling chain and its descendants for destruction. */
// FUN_004518E0
void kwlnTaskKillSiblingChain(KwlnTask* task)
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
                kwlnTaskKillSiblingChain(child->childList);
                kwlnTaskMoveToDying(child);
                child = child->next;
            }
        }
        switch (node->flags & 0xF)
        {
        default:
err:
            func_00440b68(D_00710580);
            kAssertFail(D_00710568, 0x308);
            break;
        case 1:
        case 2:
            kwlnTaskUnlinkFromList(node);
            node->flags = (node->flags & ~0xF) | 3;
            kwlnTaskLinkToList(node);
            if (node->unk2E == 0)
            {
                kwlnTaskFinalize(node);
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

/* Print the task hierarchy recursively, preserving indentation for sibling branches. */
// FUN_00451A10
void kwlnTaskDumpNode(KwlnTask* task, s32 depth)
{
    func_00440b68(D_00710598, D_008BFF70, task, task->priority);
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
        kwlnTaskDumpNode(task->childList, depth + 1);
        D_008BFF70[depth * 4] = 0;
    }
    if (task->next != 0)
    {
        kwlnTaskDumpNode(task->next, depth);
    }
}

/* Dump root hierarchies from the waiting, running, and dying lists. */
// FUN_00451B70
/* measured: without opt_loop_invariants the 0x20 constant and the D_008BFF70
 * base address are rematerialized inside the fill loop (nd 65); with it they
 * hoist to the preheader and the function matches byte-for-byte. */
#pragma opt_loop_invariants on
void kwlnTaskDumpAll(void)
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
            kwlnTaskDumpNode(node, 0);
        }
        node = node->listNext;
    }
    node = iGpffffba04;
    while (node != 0)
    {
        if (node->parent == 0)
        {
            D_008BFF70[0] = 0;
            kwlnTaskDumpNode(node, 0);
        }
        node = node->listNext;
    }
    node = iGpffffb9f8;
    while (node != 0)
    {
        if (node->parent == 0)
        {
            D_008BFF70[0] = 0;
            kwlnTaskDumpNode(node, 0);
        }
        node = node->listNext;
    }
    func_00440b68(&iGpffffac5c);
}
/* measured: see the annotation above the matching `on` pragma (func_00451b70). */
#pragma opt_loop_invariants off
/* Create the fixed-size task pool with the requested capacity. */
// FUN_00451CA0
void kwlnTaskInitPool(s32 capacity)
{
    iGpffffba18 = func_003e1220(0x54, capacity, 4, 1, D_008BFFB0, 0x41001);
}



/* Start expired waiting tasks, run updates, and finalize expired dying tasks. */
// FUN_00451CF0
s32 kwlnTaskRunFrame(void)
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
            kwlnTaskUnlinkFromList(cur1);
            cur1->flags = (cur1->flags & ~0xF) | 2;
            kwlnTaskLinkToList(cur1);
            cur1->unk24 = 0;
            cur1->unk28 = 0;
        }
    }
    kwlnTaskRunList();
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
            kwlnTaskFinalize(cur2);
        }
    }
    return 1;
}
/* Allocate a named task, initialize callbacks and delays, and link its initial state. */
// FUN_00451DE0
void* kwlnTaskCreate(const void* taskName, s32 priority, s32 startDelay, s32 destroyDelay, SdkTaskUpdate update, SdkTaskDestroy destroy, u8 *work)
{
    KwlnTask* task;
    s8* dst;
    const s8* name;
    s32 i;

    name = (const s8*)taskName;
    if (name[0] == 0)
    {
        kAssertFail(D_00710568, 0x4A9);
    }
    task = D_008873F8[0](iGpffffba18, 0x41001);
    if (task == 0)
    {
        kAssertFail(D_00710568, 0x4B5);
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
    task->name[0x17] = 0;
    task->flags = 0;
    task->flags |= 1;
    task->priority = priority;
    task->unk24 = 0;
    task->unk28 = 0;
    task->unk2C = (u16)startDelay;
    task->unk2E = (u16)destroyDelay;
    task->unk30 = update;
    task->unk34 = destroy;
    task->work = work;
    task->listNext = 0;
    task->listPrev = 0;
    task->listPrev2 = 0;
    task->parent = 0;
    task->childList = 0;
    task->next = 0;
    if (task->unk2E < 2)
    {
        task->unk2E = 2;
    }
    kwlnTaskLinkToList(task);
    if (task->unk2C == 0)
    {
        kwlnTaskUnlinkFromList(task);
        task->flags = (task->flags & ~0xF) | 2;
        kwlnTaskLinkToList(task);
        task->unk24 = 0;
        task->unk28 = 0;
    }
    return task;
}
/* Create a task and optionally append it to the parent hierarchy. */
// FUN_00451FC0
void* kwlnTaskCreateChild(void* parent, const void* taskName, s32 priority, s32 startDelay, s32 destroyDelay, SdkTaskUpdate update, SdkTaskDestroy destroy, u8 *work)
{
    void* result;

    result = kwlnTaskCreate((const void *)(taskName), priority, startDelay, destroyDelay, update, destroy, (u8 *)(work));
    if (result != 0 && parent != 0)
    {
        kwlnTaskAddChild(parent, result);
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



/* Request hierarchical destruction, or finalize a dying task whose delay expired. */
// FUN_00452080
u8 kwlnTaskDestroyWithHierarchy(KwlnTask* task)
{
    KwlnTask* node;
    KwlnTask* child;
    s32 state;

    if (task == 0 || task == (KwlnTask*)-1)
    {
        kAssertFailAt(D_007105D0, D_00710568, 0x516);
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
            kAssertFail(D_00710568, 0x308);
            break;
        case 1:
        case 2:
            kwlnTaskUnlinkFromList(task);
            task->flags = (task->flags & ~0xF) | 3;
            kwlnTaskLinkToList(task);
            if (task->unk2E == 0)
            {
                kwlnTaskFinalize(task);
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
                kwlnTaskKillSiblingChain(task->childList);
                kwlnTaskMoveToDying(task);
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
                kwlnTaskDestroyWithHierarchy(node);
                node = child;
            }
            kwlnTaskUnlinkFromList(task);
            if (task->unk34 != 0)
            {
                task->unk34((u8 *)task);
            }
            task->flags &= ~0xF;
            kwlnTaskRemoveFromParent(task);
            kwlnTaskDetachChildren(task);
            jtbl_008873FC[0](iGpffffba18, task);
        }
        break;
    default:
outer_err:
        kAssertFailAt(D_007105D0, D_00710568, 0x52C);
        return 0;
    case 0:
        goto outer_err;
    }
    return 1;
}

/* Return a linked task state; reject states outside the scheduler low nibble. */
// FUN_004522D0
s32 kwlnTaskGetState(void* task)
{
    s32 state;

    if (kwlnTaskIsLinked(task) == 0)
    {
        return 0;
    }

    state = ((KwlnTask*)task)->flags & 0xF;
    switch (state)
    {
    case 1:
    case 2:
    case 3:
    case 0:
        return state;
    default:
        kAssertFailAt(D_00710580, D_00710568, 0x57C);
        return 0;
    }
}
/* Search all scheduler lists by signed-character name sum, then exact spelling. */
// FUN_00452380
/* measured: without opt_loop_invariants the switch-case constants and the
 * three list heads are rematerialized inside the dispatch loop; with it they
 * hoist to the preheader and the function matches byte-for-byte. */
#pragma opt_loop_invariants on
KwlnTask* kwlnTaskGetTaskByName(const char* name)
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
                while (name[i] == node->name[i])
                {
                    if (i == 0)
                    {
                        return node;
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

/* Test membership in any of the three scheduler lists. */
// FUN_00452490
/* measured: without opt_loop_invariants the switch case constants are
 * rematerialized inside the loop (nd 25); with it they hoist to the
 * preheader and the function matches byte-for-byte. */
#pragma opt_loop_invariants on
s32 kwlnTaskIsLinked(void* target)
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
            node = ((KwlnTask*)node)->listNext;
        }
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_00452490). */
#pragma opt_loop_invariants off
// FUN_00452540
u32 kwlnTaskGetTimer(void* task)
{
    return ((KwlnTask*)task)->unk28;
}

/* Stores `value` in the task's +0x38 field. */
// FUN_00452550
void kwlnTaskSetValue38(KwlnTask* task, u32 value)
{
    task->work = (u8*)value;
}

// FUN_00452560
u32 kwlnTaskGetWork(void* task)
{
    return (u32)((KwlnTask*)task)->work;
}

/* Append a child, first detaching it from any previous parent. */
// FUN_00452570
void kwlnTaskAddChild(KwlnTask* parent, KwlnTask* child)
{
    KwlnTask* node;
    KwlnTask* next;

    if (child->parent != 0)
    {
        kwlnTaskRemoveFromParent(child);
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

/* Remove a child from its parent chain and clear its hierarchy links. */
// FUN_00452600
void kwlnTaskRemoveFromParent(KwlnTask* childTask)
{
    KwlnTask* parentTask;
    KwlnTask* currSibling;
    KwlnTask** childPtr;

    parentTask = childTask->parent;
    if (parentTask == NULL)
    {
        if (childTask->next != NULL)
        {
            kAssertFail(D_00710568, 0x657);
        }
        return;
    }

    childPtr = &parentTask->childList;
    if (*childPtr == childTask)
    {
        *childPtr = childTask->next;
    }
    else
    {
        currSibling = *childPtr;
        while (currSibling->next != childTask)
        {
            currSibling = currSibling->next;
        }

        currSibling->next = childTask->next;
    }

    childTask->parent = NULL;
    childTask->next = NULL;
}

