/* Whole-file translation unit: src/Event/Fcl/fclMisc.c */

/* Source unit: src/Event/Fcl/fclMisc.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fcl_assist_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"


extern int *comuDataRemoveAndReleaseNode(int *, int *, int *);

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
extern void comuDataClearList();
extern s32 fclMiscRequestSlotRelease(u8 *, s32);
extern s32 fclMiscAttachSlot(u8 *, s32);
extern s32 fclMiscUpdateSlots(u8 *);
extern s32 fclMiscTryReleaseEntry(u8 *, u8 *);
extern s32 fclMiscPendingIsEmpty(void);
extern u32 PTR_DAT_00762ea0;
extern u32 D_0076466C;





/* Source unit: src/Event/Fcl/fcl_misc_0014a2e0.c */
/* Store the caller value in the external work block; its owning layout is not established here. */
// FUN_0014A2E0
void fclMiscSetExternalWord(u32 value)
{
    *(u32 *)(PTR_DAT_00762ea0 + 0x14) = value;
}

/* Attach user data to the message window subtable; only its +0x18 member is known here. */
// FUN_0027BE90
void fclMesWindowSetUserData(s32 handle, void *userdata)
{
    int subTable;

    subTable = itfMesWindowGetSubTable(handle);
    *(void **)(subTable + 0x18) = userdata;
}



/* Prune unloaded pending sprites and inactive message entries from their lists. */
// FUN_002BCC60
u64 fclMiscPruneLists(int *manager)
{
    int *item;
    int *node;

    item = (int *)((FclAssistManager *)manager)->pending->head;
    while (item != 0) {
        node = (int *)((FclAssistNode *)item)->data;
        if (((FclAssistSlot *)node)->sprite == 0) {
            item = comuDataRemoveAndReleaseNode((int *)((FclAssistManager *)manager)->pending, (int *)&((FclAssistManager *)manager)->pending->head, item);
        }
        else {
            item = (int *)((FclAssistNode *)item)->next;
        }
    }
    item = (int *)((FclAssistManager *)manager)->entries->head;
    while (item != 0) {
        node = (int *)((FclAssistNode *)item)->data;
        if ((((FclAssistEntry *)node)->flags & 2) == 0) {
            item = comuDataRemoveAndReleaseNode((int *)((FclAssistManager *)manager)->entries, (int *)&((FclAssistManager *)manager)->entries->head, item);
        }
        else {
            item = (int *)((FclAssistNode *)item)->next;
        }
    }
    return 0;
}
/* Allocate the assist manager and pending list, reset its window slot, and register the update task. */
// FUN_002BCD20
void fclMiscCreateAssistTask(void)
{
    u8 *work;
    u8 *state;
    u8 *globalState;

    globalState = D_00882F30;
    work = func_002e1db0(0xa0, 0, 0, 0);
    state = (u8 *)((FclAssistList *)work)->work;
    ((FclAssistManager *)state)->entries = (FclAssistList *)work;
    ((FclAssistManager *)state)->pending = (FclAssistList *)func_002e1db0(0xc, 0, 0, 0);
    ((FclAssistManager *)state)->flags |= 1;
    iGpffffb57c = (int)state;
    if (globalState != NULL)
    {
        ((FclAssistHandle *)globalState)->handle = -1;
        ((FclAssistHandle *)globalState)->mode = 0;
        ((FclAssistHandle *)globalState)->suspended = 0;
        ((FclAssistHandle *)globalState)->pending = -1;
        ((FclAssistHandle *)globalState)->unk0c = 1;
        ((FclAssistHandle *)globalState)->unk0d = 1;
    }
    (s32)kwlnTaskCreate((const void *)(D_0063F398), 0xf, 0, 0, msgAssistUpdate, 0, (u8 *)(0));
}



/* Activate the next queued message, wait for its slots, and retire completed entries. */
/* Typed manager/list accesses changed codegen (nd279); retain offsets from fcl_assist_internal.h. */
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
                comuDataClearList(*(void **)manager,
                              (u8 *)*(void **)manager + 4);
                i = 0;
                while (i < 0xb)
                {
                    fclMiscRequestSlotRelease(manager, i);
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
        fclMiscAttachSlot(manager, 0);
        fclMiscAttachSlot(manager, *(s32 *)(item + 0x2c));
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
            if (fclMiscTryReleaseEntry(manager, entry) != 0)
            {
                *(s32 *)(manager + 4) |= 1;
                comuDataRemoveAndReleaseNode(*(int **)manager,
                              (int *)((u8 *)*(int **)manager + 4),
                              (int *)head);
            }
        }
    }
    fclMiscUpdateSlots(manager);
    return 0;
}
/* Wait for slot readiness before activating a message; release its slots once its window closes. */
/* Typed entry/slot accesses changed codegen (nd405); retain offsets from fcl_assist_internal.h. */
// FUN_002BCFB0
s32 fclMiscTryReleaseEntry(u8 *manager, u8 *entry) {
    extern u32 fclMiscCloseHandle(u32 *);
    /* measured: s8 here regresses func_002bcfb0 (MATCH -> MISMATCH); the s32 extern keeps its compare. */
    extern s32 fclMiscHandleState(int *); /* lint: allow H011 -- measured: s8 regresses func_002bcfb0 MATCH->MISMATCH; retail consumes the full register */
    s32 slotIndex;
    s32 activeSlotIndex;
    s32 flags;
    u8 *slotBase;

    flags = *(s32 *)(entry + 4);
    if (flags & 4) {
        if (!(itfMesWindowGetFlags(*(s32 *)(entry + 0x10)) & 0x3300)) {
            fclMiscReleaseHandle((int *)(entry + 0x10));
            if (!(*(s32 *)(manager + 0x14) & 1)) {
                if (manager == NULL) {
                    kAssertFail(&D_0063F2A0, 0x58F);
                }
                *(s32 *)(manager + 0x1C) |= 4;
            }
            slotIndex = *(s32 *)(entry + 0x2C);
            if (!(*(s32 *)(manager + 0x14) & (1 << slotIndex))) {
                if (manager == NULL) {
                    kAssertFail(&D_0063F2A0, 0x58F);
                }
                if ((slotIndex < 0) || (slotIndex > 0xB)) {
                    kAssertFail(&D_0063F2A0, 0x590);
                }
                slotBase = manager + (slotIndex * 0xC);
                *(s32 *)(slotBase + 0x1C) |= 4;
            }
            return 1;
        }
        return 0;
    }
    if (flags & 1) {
        if (manager == NULL) {
            kAssertFail(&D_0063F2A0, 0x587);
        }
        if (!(*(s32 *)(manager + 0x1C) & 2)) {
            return 0;
        }
        activeSlotIndex = *(s32 *)(entry + 0x2C);
        if (manager == NULL) {
            kAssertFail(&D_0063F2A0, 0x587);
        }
        if (!(*(s32 *)(manager + (activeSlotIndex * 0xC) + 0x1C) & 2)) {
            return 0;
        }
        *(s32 *)(entry + 4) &= ~1;
        fclMiscActivateHandle(entry + 0x10, *(s32 *)(entry + 0x2C), *(s32 *)(entry + 0x20));
    }
    fclMiscUpdateHandle((int *)(entry + 0x10));
    if (fclMiscHandleState((int *)(entry + 0x10)) == 0) {
        fclMiscCloseHandle((u32 *)(entry + 0x10));
        *(s32 *)(entry + 4) |= 4;
    }
    return 0;
}
/* Return a slot sprite only when the loaded flag (bit 1) is set. */
/* Typed slot indexing changed codegen (nd37); retain the 0x0C stride and flags/sprite at +0x1C/+0x24. */
// FUN_002BD1E0
s32 fclMiscSlotValue(s32 slotIndex)
{
    u8* entry;

    entry = (u8*)iGpffffb57c;
    entry = (u8*)(slotIndex * 0xc) + (u32)entry;
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
    return ((FclAssistManager *)iGpffffb57c)->pending->head == 0;
}



// FUN_002BD240
void fclMiscOrStateFlags(u32 flags)
{
    ((FclAssistManager *)iGpffffb57c)->stateFlags = ((FclAssistManager *)iGpffffb57c)->stateFlags | flags;
}

/* Source unit: src/Event/Fcl/fcl_misc_002bd260.c */
/* Stores value in the word at D_0076466C+0x14. */
// FUN_002BD260
void fclMiscSetWord14(u32 value)
{
    ((FclAssistManager *)D_0076466C)->stateFlags = value;
}

/* Source unit: src/Event/Fcl/fcl_misc_002bd270.c */
// FUN_002BD270
void fclMiscSetStatusCode(u32 value)
{
    ((FclAssistManager *)D_0076466C)->source = value;
}



// FUN_002BD340
u16 fclMiscGetRecordCount(void)
{
    return ((FclAssistManager *)piGpffffb57c)->entries->count;
}



/* Find a queued entry by slot index and bound message record. */
// FUN_002BD360
u32 fclMiscHasEntry(int slotIndex, int record)
{
    int node;

    node = (int)((FclAssistManager *)piGpffffb57c)->entries->head;
    while (node != 0) {
        if ((((FclAssistEntry *)((FclAssistNode *)node)->data)->slotIndex == slotIndex) &&
            (((FclAssistEntry *)((FclAssistNode *)node)->data)->record == record)) {
            return 1;
        }
        node = (int)((FclAssistNode *)node)->next;
    }
    return 0;
}



// FUN_002BD3C0
void fclMiscSetDoneFlag(void)
{
    ((FclAssistManager *)iGpffffb57c)->flags = ((FclAssistManager *)iGpffffb57c)->flags | 2;
}



/* Close the active queued window and mark its entry for retirement. */
/* Typed queue traversal changed codegen (nd47); links are +0x10, payload +0x14, entry flags +4. */
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
s32 fclMiscAcquireHandle(u8 *window, u8 *source)
{
    s32 value;

    if (window != NULL)
    {
        ((FclAssistHandle *)window)->handle = -1;
        ((FclAssistHandle *)window)->mode = 0;
        ((FclAssistHandle *)window)->suspended = 0;
        ((FclAssistHandle *)window)->pending = -1;
        ((FclAssistHandle *)window)->unk0c = 1;
        ((FclAssistHandle *)window)->unk0d = 1;
    }
    if (((FclAssistHandle *)window)->handle < 0)
    {
        value = itfMesWindowInstall(source);
        ((FclAssistHandle *)window)->handle = value;
        itfMesWindowSetStyle(value, 2);
        return 1;
    }
    return 0;
}
/* Closes the handle, releases it, and resets the slot to idle. */
// FUN_002BD530
void fclMiscReleaseHandle(int *window)
{
    fclMiscCloseHandle(window);

    if (((FclAssistHandle *)window)->handle >= 0) {
        itfMesWindowReleaseIfActive(((FclAssistHandle *)window)->handle);
        ((FclAssistHandle *)window)->handle = -1;
        ((FclAssistHandle *)window)->mode = 0;
        ((FclAssistHandle *)window)->suspended = 0;
    }
}



/* Sets the handle's flags and parameters and marks its mode active. */
// FUN_002BD580
s32 fclMiscActivateHandle(u8 *window, s32 slotIndex, s32 record)
{
    s32 value;

    value = ((FclAssistHandle *)window)->handle;
    if (value < 0)
    {
        return 0;
    }
    itfMesWindowSetFlagBits(value, 0x200000);
    itfMesWindowBindRecord(((FclAssistHandle *)window)->handle, record, 0);
    msgWinStoreSlot(((FclAssistHandle *)window)->handle, slotIndex);
    ((FclAssistHandle *)window)->mode = 1;
    return 0;
}
/* Reports the handle's mode; mode 2 reads as idle while the flag at +5 is set. */
// FUN_002BD610
/* measured: an s32 return regresses fclMiscHandleState and fclMiscUpdateHandle (MATCH -> MISMATCH); the s8 definition is kept. */
s8 fclMiscHandleState(int *window)
{
    s8 result;

    if (((FclAssistHandle *)window)->handle < 0) {
        result = 0;
    }
    else if ((((FclAssistHandle *)window)->suspended != 0) && (((FclAssistHandle *)window)->mode == 2)) {
        result = 0;
    }
    else {
        result = ((FclAssistHandle *)window)->mode;
    }
    return result;
}



/* Per-frame step of the handle's mode state machine. */
/* Typed handle accesses changed codegen (nd74); handle +0, mode +4, suspended +5, pending +8. */
// FUN_002BD660
void fclMiscUpdateHandle(int *window)
{
    int state;
    s8 mode;

    state = *window;
    if (state < 0) {
        return;
    }
    mode = *(s8 *)((u8 *)window + 4);
    switch (mode) {
    case 0:
        return;
    case 1:
        if (itfMesWindowState(state) < 0) {
            *(u8 *)(window + 1) = 2;
        }
        break;
    case 2:
        if (window[2] >= 0) {
            window[2] = -1;
        }
        if (*(s8 *)((u8 *)window + 5) == 0) {
            *(u8 *)(window + 1) = 3;
        }
        break;
    case 3:
        fclMiscCloseHandle((u32 *)window);
        break;
    }
}



/* Closes the handle's hooks and clears its mode; returns 1 when closed. */
// FUN_002BD730
u32 fclMiscCloseHandle(u32 *window)
{
    u32 result;

    if (window == 0) {
        result = 0;
    }
    else if ((s32)((FclAssistHandle *)window)->handle < 0) {
        result = 0;
    }
    else {
        itfMesWindowSetState(((FclAssistHandle *)window)->handle, 0);
        itfMesWindowRelease(((FclAssistHandle *)window)->handle);
        itfMesWindowClear(((FclAssistHandle *)window)->handle, 0);
        ((FclAssistHandle *)window)->mode = 0;
        result = 1;
    }
    return result;
}
