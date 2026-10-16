/* Whole-file translation unit: src/Event/Fcl/fclMisc.c */

/* Source unit: src/Event/Fcl/fclMisc.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "message_handle.h"
#include "message_procedure_api.h"


extern int *func_002e2240(int *, int *, int *);

// P3 counterpart iGpffffb98c (gp -0x4674, absolute 0x007ce67c); P4 retail
// uses gp -0x4A84, i.e. absolute 0x007690f0 - 0x4a84 = 0x0076466c.
extern int iGpffffb57c;

// P3 counterpart piGpffffb98c (gp -0x4674, absolute 0x007ce67c); P4 retail
// uses gp -0x4A84, i.e. absolute 0x007690f0 - 0x4a84 = 0x0076466c.
extern int *piGpffffb57c;
extern u32 fclMiscCloseHandle();
extern void itfMesWindowReleaseIfActive();

/* measured: s8 here regresses fclMiscUpdateHandle (its "< 0" test); s32 is kept. */
extern s32 itfMesWindowState(s32); /* lint: allow H011 -- measured: s8 regresses fclMiscUpdateHandle ("< 0" test); retail consumes the full register */

// Donor calls these implicitly (no prototypes), so keep old-style forms.
extern void itfMesWindowSetState();
extern void itfMesWindowRelease();
extern void itfMesWindowClear();
extern s32 itfMesWindowInstall(u8 *);
extern s32 itfMesWindowSetStyle(s32, s16);
extern void itfMesWindowSetFlagBits(s32, s32);
extern s32 itfMesWindowBindRecord(s32, s32, s32);
extern u8 *func_002e1db0(s32, int (*)(), int (*)(), int (*)());

extern u8 D_0063F398[];
extern u8 D_00882F30[];
extern s32 msgAssistUpdate(u8 *task);
extern void kAssertFail(void *, s32);
extern char D_0063F2A0[];
extern void fclMiscReleaseHandle(int *);
extern s32 fclMiscActivateHandle(u8 *, s32, s32);

extern void fclMiscUpdateHandle(int *);
extern u32 fclMiscCloseHandle();
extern void fclMiscSetWord14();
extern void func_002e22f0();
extern s32 func_002bcbc0(u8 *, s32);
extern s32 func_002bc890(u8 *, s32);
extern s32 func_002bc9e0(u8 *);
extern s32 func_002bcfb0(u8 *, u8 *);
extern s32 fclMiscPendingIsEmpty(void);
extern u32 PTR_DAT_00762ea0;
extern u32 D_0076466C;





/* Source unit: src/Event/Fcl/fcl_misc_0014a2e0.c */
// FUN_0014A2E0
void func_0014a2e0(u32 value)
{
    *(u32 *)(PTR_DAT_00762ea0 + 0x14) = value;
}

// FUN_0027BE90
void fclMesWindowSetUserData(s32 handle, void *userdata)
{
    int iVar1;

    iVar1 = itfMesWindowGetSubTable(handle);
    *(void **)(iVar1 + 0x18) = userdata;
}



// FUN_002BCC60
u64 fclMiscPruneLists(int *param_1)
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
void fclMiscCreateAssistTask(void)
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
    (s32)kwlnTaskCreate((const void *)(D_0063F398), 0xf, 0, 0, msgAssistUpdate, 0, (u8 *)(0));
}



// FUN_002BCE00
s32 msgAssistUpdate(u8 *unusedTask)
{
    u8 *manager;
    u8 *head;
    u8 *entry;
    u8 *item;
    s32 flags;
    s32 i;

    manager = (u8 *)(uintptr_t)iGpffffb57c;
    flags = *(s32 *)(manager + 4);
    if ((flags & 1) != 0)
    {
        if ((flags & 2) != 0)
        {
            fclMiscPruneLists((int *)manager);
            if (fclMiscPendingIsEmpty() != 0)
            {
                *(s32 *)(manager + 4) &= ~2;
                fclMiscSetWord14(0);
                func_002e22f0(*(void **)manager,
                              (u8 *)*(void **)manager + 4);
                i = 0;
                while (i < 0xb)
                {
                    func_002bcbc0(manager, i);
                    i++;
                }
            }
            goto update_tail;
        }
        head = *(u8 **)((u8 *)*(u32 *)manager + 4);
        if (head == NULL)
        {
            item = NULL;
            goto process_item;
        }
        item = *(u8 **)(head + 0x14);
process_item:
        if (item == NULL)
        {
            goto update_tail;
        }
        *(s32 *)(manager + 4) = flags & ~1;
        fclMiscAcquireHandle(item + 0x10, *(u8 **)(item + 0x28));
        func_002bc890(manager, 0);
        func_002bc890(manager, *(s32 *)(item + 0x2c));
        *(s32 *)(item + 4) |= 2;
        *(s32 *)(item + 4) |= 1;
    }
update_tail:
    head = *(u8 **)((u8 *)*(u32 *)manager + 4);
    if (head != NULL)
    {
        entry = *(u8 **)(head + 0x14);
        if ((*(s32 *)(entry + 4) & 2) != 0)
        {
            if (func_002bcfb0(manager, entry) != 0)
            {
                *(s32 *)(manager + 4) |= 1;
                func_002e2240(*(int **)manager,
                              (int *)((u8 *)*(int **)manager + 4),
                              (int *)head);
            }
        }
    }
    func_002bc9e0(manager);
    return 0;
}
// FUN_002BCFB0
s32 func_002bcfb0(u8 *arg0, u8 *arg1) {
    extern u32 fclMiscCloseHandle(u32 *);
    /* measured: s8 here regresses func_002bcfb0 (MATCH -> MISMATCH); the s32 extern keeps its compare. */
    extern s32 fclMiscHandleState(int *); /* lint: allow H011 -- measured: s8 regresses func_002bcfb0 MATCH->MISMATCH; retail consumes the full register */
    s32 temp_16;
    s32 temp_18;
    s32 temp_3;
    u8 *temp_3_2;

    temp_3 = *(s32 *)(arg1 + 4);
    if (temp_3 & 4) {
        if (!(itfMesWindowGetFlags(*(s32 *)(arg1 + 0x10)) & 0x3300)) {
            fclMiscReleaseHandle((int *)(arg1 + 0x10));
            if (!(*(s32 *)(arg0 + 0x14) & 1)) {
                if (arg0 == NULL) {
                    kAssertFail(&D_0063F2A0, 0x58F);
                }
                *(s32 *)(arg0 + 0x1C) |= 4;
            }
            temp_16 = *(s32 *)(arg1 + 0x2C);
            if (!(*(s32 *)(arg0 + 0x14) & (1 << temp_16))) {
                if (arg0 == NULL) {
                    kAssertFail(&D_0063F2A0, 0x58F);
                }
                if ((temp_16 < 0) || (temp_16 > 0xB)) {
                    kAssertFail(&D_0063F2A0, 0x590);
                }
                temp_3_2 = arg0 + (temp_16 * 0xC);
                *(s32 *)(temp_3_2 + 0x1C) |= 4;
            }
            return 1;
        }
        return 0;
    }
    if (temp_3 & 1) {
        if (arg0 == NULL) {
            kAssertFail(&D_0063F2A0, 0x587);
        }
        if (!(*(s32 *)(arg0 + 0x1C) & 2)) {
            return 0;
        }
        temp_18 = *(s32 *)(arg1 + 0x2C);
        if (arg0 == NULL) {
            kAssertFail(&D_0063F2A0, 0x587);
        }
        if (!(*(s32 *)(arg0 + (temp_18 * 0xC) + 0x1C) & 2)) {
            return 0;
        }
        *(s32 *)(arg1 + 4) &= ~1;
        fclMiscActivateHandle(arg1 + 0x10, *(s32 *)(arg1 + 0x2C), *(s32 *)(arg1 + 0x20));
    }
    fclMiscUpdateHandle((int *)(arg1 + 0x10));
    if (fclMiscHandleState((int *)(arg1 + 0x10)) == 0) {
        fclMiscCloseHandle((u32 *)(arg1 + 0x10));
        *(s32 *)(arg1 + 4) |= 4;
    }
    return 0;
}
// FUN_002BD1E0
s32 fclMiscSlotValue(s32 param_1)
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
/* Returns 1 when the pending list at iGpffffb57c+0x18 has no entries. */
// FUN_002BD220
s32 fclMiscPendingIsEmpty(void)
{
    return *(int *)(*(int *)(iGpffffb57c + 0x18) + 4) == 0;
}



// FUN_002BD240
void fclMiscOrStateFlags(u32 param_1)
{
    *(u32 *)(iGpffffb57c + 0x14) = *(u32 *)(iGpffffb57c + 0x14) | param_1;
}

/* Source unit: src/Event/Fcl/fcl_misc_002bd260.c */
/* Stores value in the word at D_0076466C+0x14. */
// FUN_002BD260
void fclMiscSetWord14(u32 value)
{
    *(u32 *)(D_0076466C + 0x14) = value;
}

/* Source unit: src/Event/Fcl/fcl_misc_002bd270.c */
// FUN_002BD270
void fclMiscSetStatusCode(u32 value)
{
    *(u32 *)(D_0076466C + 0xc) = value;
}



// FUN_002BD340
u16 fclMiscGetRecordCount(void)
{
    return *(u16 *)(*piGpffffb57c + 0x10);
}



// FUN_002BD360
u32 fclMiscHasEntry(int param_1, int param_2)
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
void fclMiscSetDoneFlag(void)
{
    *(u32 *)(iGpffffb57c + 4) = *(u32 *)(iGpffffb57c + 4) | 2;
}



// FUN_002BD440
void fclMiscCloseActiveHandle(void)
{
    u8 *context;

    if (*(int *)(*piGpffffb57c + 4) != 0) {
        context = *(u8 **)(*(int *)(*piGpffffb57c + 4) + 0x14);
        if ((*(u32 *)(context + 4) & 2) != 0) {
            fclMiscCloseHandle(context + 0x10);
            *(u32 *)(context + 4) |= 4;
        }
    }
}



/* Initialises the handle slot and acquires a handle when it has none; returns 1 if one was acquired. */
// FUN_002BD4A0
s32 fclMiscAcquireHandle(u8 *param_1, u8 *param_2)
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
        value = itfMesWindowInstall(param_2);
        *(s32 *)param_1 = value;
        itfMesWindowSetStyle(value, 2);
        return 1;
    }
    return 0;
}
/* Closes the handle, releases it, and resets the slot to idle. */
// FUN_002BD530
void fclMiscReleaseHandle(int *param_1)
{
    fclMiscCloseHandle(param_1);

    if (*param_1 >= 0) {
        itfMesWindowReleaseIfActive(*param_1);
        *param_1 = -1;
        *(u8 *)(param_1 + 1) = 0;
        *(u8 *)((int)param_1 + 5) = 0;
    }
}



/* Sets the handle's flags and parameters and marks its mode active. */
// FUN_002BD580
s32 fclMiscActivateHandle(u8 *param_1, s32 param_2, s32 param_3)
{
    s32 value;

    value = *(s32 *)param_1;
    if (value < 0)
    {
        return 0;
    }
    itfMesWindowSetFlagBits(value, 0x200000);
    itfMesWindowBindRecord(*(s32 *)param_1, param_3, 0);
    msgWinStoreSlot(*(s32 *)param_1, param_2);
    *(s8 *)(param_1 + 4) = 1;
    return 0;
}
/* Reports the handle's mode; mode 2 reads as idle while the flag at +5 is set. */
// FUN_002BD610
/* measured: an s32 return regresses fclMiscHandleState and fclMiscUpdateHandle (MATCH -> MISMATCH); the s8 definition is kept. */
s8 fclMiscHandleState(int *param_1)
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



/* Per-frame step of the handle's mode state machine. */
// FUN_002BD660
void fclMiscUpdateHandle(int *param_1)
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
        if (itfMesWindowState(state) < 0) {
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
        fclMiscCloseHandle((u32 *)param_1);
        break;
    }
}



/* Closes the handle's hooks and clears its mode; returns 1 when closed. */
// FUN_002BD730
u32 fclMiscCloseHandle(u32 *param_1)
{
    u32 result;

    if (param_1 == 0) {
        result = 0;
    }
    else if ((s32)*param_1 < 0) {
        result = 0;
    }
    else {
        itfMesWindowSetState(*param_1, 0);
        itfMesWindowRelease(*param_1);
        itfMesWindowClear(*param_1, 0);
        *((u8 *)param_1 + 4) = 0;
        result = 1;
    }
    return result;
}
