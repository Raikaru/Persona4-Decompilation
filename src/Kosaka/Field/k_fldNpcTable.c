#include "include_asm.h"
/* Original translation unit k_fldNpcTable.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "field_frame_internal.h"
#include "field_scene_internal.h"
typedef struct HCdvd HCdvd;

/* Scene rows are 0x20 bytes; calendar lookup reads only the fields below. */
typedef struct FldNpcSceneEntry {
    u16 month, day, timeSlot, unk06;
    s32 requiredFlag;
    u8 pad0C[0x14];
} FldNpcSceneEntry;

typedef struct FldNpcSceneTable {
    s32 count;
    u8 pad04[0x1C];
    FldNpcSceneEntry entries[1];
} FldNpcSceneTable;

/* Block-table request/install share these fields; other state is not read here. */
typedef struct FldNpcBlockTable {
    u8 pad00[0x0C];
    HCdvd *request;
    u8 pad10[4];
    void *data;
    s32 size;
} FldNpcBlockTable;

typedef struct FldNpcFixedEntry {
    u16 marker;
    u8 pad02[0x82];
} FldNpcFixedEntry;

/* Marked records following the calendar rows retain the same 0x20-byte stride. */
typedef struct FldNpcSectionEntry {
    u16 marker;
    u8 pad02[0x1E];
} FldNpcSectionEntry;

extern u8 *MT_Scene_GetFrameState(void);
extern void (*DAT_008873EC[])(void *);
extern s32 FldRc_GetLoadSource(void);
extern void strcpy(void *destination, const char *source);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 H_Cdvd_FileExists(void *path);
extern s32 H_Cdvd_IsFileLoaded(u8 *request);
extern void H_Cdvd_Destroy(void *request);
extern void func_00440b68(char *context, const char *file, s32 line, ...);
extern u8 *H_Cdvd_AcquireDirectory(void *path, s32 mode);
extern u8 *gMtScene;
extern char D_00762F20;
extern char D_005F0790[];
extern char D_005F07A0[];
extern char D_005F07C0[];
extern char D_005F07D0[];
extern char D_005F07F0[];
extern char D_005F0810[];
extern char D_005F0830[];
extern char D_005F0850[];
extern void chkmemAllocSiteTag(void *file, s32 line);
extern void memcpy(void *destination, void *source, u32 size);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 D_00764384; /* owned fixed-record table */
extern s32 D_00764388; /* fixed-table marker count */
extern s32 D_0076438C; /* fixed-record count */
extern u8 *H_Cdvd_LookupRequest(void *path, u32 *size);
extern s32 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern void calSplitDayOfYear(s16 year, s32 *month, s32 *day);
extern s32 datGetFlag(s32 id);
extern s32 clndIsDateInRange(s32 startMonth, s32 startDay, s32 endMonth, s32 endDay);

/* Source unit: src/promoted/k_fldNpcTable.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_fldNpcTable.c; members 0015c750-0015d1a0 */

// FUN_0015C750
/* Request the scene NPC table unless resources are already supplied by the field loader. */
s32 NpcTable_RequestSceneTable(void)
{
    char directoryPath[0x80];
    char filePath[0x80];
    u8 *scene;

    if (FldRc_GetLoadSource() != 0) {
        goto ret1;
    }
    strcpy(directoryPath, D_005F0790);
    scene = gMtScene;
    sprintf(filePath, D_005F07A0, ((FieldSceneState *)scene)->field.value, ((FieldSceneState *)scene)->room.value);
    if (H_Cdvd_FileExists(filePath) == 0) {
        return 0;
    }
    func_00440b68(&D_00762F20, D_005F07C0, 0x68);
    return (s32)H_Cdvd_AcquireDirectory(filePath, 0);
ret1:
    return 1;
}

// FUN_0015C800
/* Poll and copy the scene table, then expose its counted 0x20-byte rows. */
s32 NpcTable_InstallSceneTable(u8 *request)
{
    /* Typed HCdvd/API rewrite lost MATCH; keep its +0x110 payload and +0x118 size accesses. */
    s32 allocation;
    u8 *table;
    u8 *work;
    char filePath[0x4C];
    u32 fileSize;

    if (request == 0) {
        return 1;
    }
    if (FldRc_GetLoadSource() == 0) {
        if (H_Cdvd_IsFileLoaded(request) == 0) {
            goto ret0;
        }
        chkmemAllocSiteTag(&D_005F07C0, 0x81);
        allocation = (s32)(*D_008873F4)(1, (s32)(*(u32 *)(request + 0x118)), 0x40000);
        ((FldFrame *)MT_Scene_GetFrameState())->sceneTable = (u8 *)allocation;
        {
            u8 *state = MT_Scene_GetFrameState();
            s32 size = *(s32 *)(request + 0x118);
            void *dst = ((FldFrame *)state)->sceneTable;
            void *src = *(void **)(request + 0x110);
            memcpy(dst, src, size);
        }
        table = ((FldFrame *)MT_Scene_GetFrameState())->sceneTable;
        ((FldFrame *)MT_Scene_GetFrameState())->sceneCount = ((FldNpcSceneTable *)table)->count;
        work = (u8 *)((FldNpcSceneTable *)table)->entries;
        ((FldFrame *)MT_Scene_GetFrameState())->sceneEntries = work;
        ((FldFrame *)MT_Scene_GetFrameState())->sceneEntriesEnd =
            ((FldFrame *)MT_Scene_GetFrameState())->sceneEntries + ((FldNpcSceneTable *)table)->count * 0x20;
        H_Cdvd_Destroy(request);
        return 1;
    }
    sprintf(filePath, D_005F07D0, ((FieldSceneState *)gMtScene)->field.value, ((FieldSceneState *)gMtScene)->room.value);
    table = H_Cdvd_LookupRequest(filePath, &fileSize);
    if (table != 0) {
        chkmemAllocSiteTag(&D_005F07C0, 0xA2);
        allocation = (s32)(*D_008873F4)(1, (s32)(fileSize), 0x40000);
        ((FldFrame *)MT_Scene_GetFrameState())->sceneTable = (u8 *)allocation;
        {
            u8 *state = MT_Scene_GetFrameState();
            s32 size = fileSize;
            void *dst = ((FldFrame *)state)->sceneTable;
            void *src = table;
            memcpy(dst, src, size);
        }
        work = ((FldFrame *)MT_Scene_GetFrameState())->sceneTable;
        ((FldFrame *)MT_Scene_GetFrameState())->sceneCount = ((FldNpcSceneTable *)work)->count;
        table = (u8 *)((FldNpcSceneTable *)work)->entries;
        ((FldFrame *)MT_Scene_GetFrameState())->sceneEntries = table;
        ((FldFrame *)MT_Scene_GetFrameState())->sceneEntriesEnd =
            ((FldFrame *)MT_Scene_GetFrameState())->sceneEntries + ((FldNpcSceneTable *)work)->count * 0x20;
    }
    return 1;
ret0:
    return 0;
}

// FUN_0015CA30
/* Search newest-to-oldest date boundaries, honoring time slots and optional flags. */
void *NpcTable_FindActiveEntry(void)
{
    s32 month;
    s32 day;
    FldNpcSceneEntry *work = (FldNpcSceneEntry *)((FldFrame *)MT_Scene_GetFrameState())->sceneEntries;
    FldNpcSceneEntry *end;
    s32 endMonth;
    s32 endDay;
    s32 endTimeSlot;
    s32 i;

    if (work == 0) {
        return 0;
    }
    end = work + (((FldFrame *)MT_Scene_GetFrameState())->sceneCount - 1);
    endMonth = 3;
    endDay = 0x1F;
    endTimeSlot = 5;
    calSplitDayOfYear((s16)datGetDateIndex(), &month, &day);
    i = 0;
    while (i < (u32)((FldFrame *)MT_Scene_GetFrameState())->sceneCount) {
        if (clndIsDateInRange(end->month, end->day, endMonth, endDay) != 1) {
            goto update;
        }
        if (end->month == month && end->day == day) {
            if ((datGetTimeSlot() & 0xFF) < end->timeSlot) {
                goto next;
            }
        }
        if (endMonth == month && endDay == day) {
            if ((datGetTimeSlot() & 0xFF) > endTimeSlot) {
                goto next;
            }
        }
        if (end->requiredFlag == -1) {
            break;
        }
        if (datGetFlag(end->requiredFlag) == 1) {
            break;
        }
    update:
        endMonth = end->month;
        endDay = end->day;
        endTimeSlot = end->timeSlot;
    next:
        i++;
        end -= 1;
    }
    if (i >= (u32)((FldFrame *)MT_Scene_GetFrameState())->sceneCount) {
        end = 0;
    }
    return end;
}

// FUN_0015CBE0
/* Find a marked section after the dated rows; the caller supplies a valid section index. */
/* measured: without opt_loop_invariants on the loop's invariant table base is
   rematerialized in the body (nd 6); with it the address hoists to the
   preheader like retail (nd 1, the last word being all-zero padding tail). */
/* measured: NpcTable_GetMarkedEntry MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
u16 *NpcTable_GetMarkedEntry(s32 sectionIndex)
{
    FldNpcSectionEntry *entry = (FldNpcSectionEntry *)((FldFrame *)MT_Scene_GetFrameState())->sceneEntriesEnd;
    s32 count = 0;

    for (;;) {
        if (count == sectionIndex) {
            break;
        }
        if (entry->marker == 0xFFFF) {
            count += 1;
        }
        entry += 1;
    }
    return (u16 *)entry;
}

/* measured: see annotation above (NpcTable_GetMarkedEntry). */
// FUN_0015CC40
/* Release the owned scene table and clear its derived row pointers. */
void NpcTable_ReleaseSceneTable(void)
{
    if (((FldFrame *)MT_Scene_GetFrameState())->sceneTable != 0) {
        (*DAT_008873EC)(((FldFrame *)MT_Scene_GetFrameState())->sceneTable);
        ((FldFrame *)MT_Scene_GetFrameState())->sceneTable = 0;
        ((FldFrame *)MT_Scene_GetFrameState())->sceneCount = 0;
        ((FldFrame *)MT_Scene_GetFrameState())->sceneEntries = 0;
        ((FldFrame *)MT_Scene_GetFrameState())->sceneEntriesEnd = 0;
    }
}

// FUN_0015CCC0
/* Request the secondary NPC table for the current field and room. */
s32 NpcTable_RequestSecondaryTable(void)
{
    char directoryPath[0x80];
    char filePath[0x80];
    u8 *scene;

    if (FldRc_GetLoadSource() != 0) {
        goto ret1;
    }
    strcpy(directoryPath, D_005F0790);
    scene = gMtScene;
    sprintf(filePath, D_005F07F0, ((FieldSceneState *)scene)->field.value, ((FieldSceneState *)scene)->room.value);
    if (H_Cdvd_FileExists(filePath) == 0) {
        return 0;
    }
    func_00440b68(&D_00762F20, D_005F07C0, 0x140);
    return (s32)H_Cdvd_AcquireDirectory(filePath, 0);
ret1:
    return 1;
}

// FUN_0015CD70
/* Install an owned copy of the secondary table from disk or the resource lookup. */
s32 NpcTable_InstallSecondaryTable(u8 *request)
{
    /* Typed HCdvd/API rewrite lost MATCH; keep its +0x110 payload and +0x118 size accesses. */
    u8 *source;
    s32 allocation;
    char filePath[0x4C];
    u32 fileSize;

    source = request;
    if (source == 0) {
        return 1;
    }
    if (FldRc_GetLoadSource() == 0) {
        if (H_Cdvd_IsFileLoaded(source) != 0) {
            chkmemAllocSiteTag(&D_005F07C0, 0x158);
            allocation = (s32)(*D_008873F4)(1, (s32)(*(u32 *)(source + 0x118)), 0x40000);
            ((FldFrame *)MT_Scene_GetFrameState())->secondaryTable = (u16 *)allocation;
            ((FldFrame *)MT_Scene_GetFrameState())->secondaryTableSize = *(u32 *)(source + 0x118);
            {
                u8 *state = MT_Scene_GetFrameState();
                s32 size = *(s32 *)(source + 0x118);
                void *dst = ((FldFrame *)state)->secondaryTable;
                void *src = *(void **)(source + 0x110);
                memcpy(dst, src, size);
            }
            H_Cdvd_Destroy(source);
            return 1;
        }
        goto ret0;
    }
    sprintf(filePath, D_005F0810, ((FieldSceneState *)gMtScene)->field.value, ((FieldSceneState *)gMtScene)->room.value);
    source = H_Cdvd_LookupRequest(filePath, &fileSize);
    if (source != 0) {
        chkmemAllocSiteTag(&D_005F07C0, 0x172);
        allocation = (s32)(*D_008873F4)(1, (s32)(fileSize), 0x40000);
        ((FldFrame *)MT_Scene_GetFrameState())->secondaryTable = (u16 *)allocation;
        ((FldFrame *)MT_Scene_GetFrameState())->secondaryTableSize = fileSize;
        {
            u8 *state = MT_Scene_GetFrameState();
            s32 size = fileSize;
            void *dst = ((FldFrame *)state)->secondaryTable;
            void *src = source;
            memcpy(dst, src, size);
        }
    }
    return 1;
ret0:
    return 0;
}

// FUN_0015CF10
/* Release the secondary NPC table allocation. */
void NpcTable_ReleaseSecondaryTable(void)
{
    if (((FldFrame *)MT_Scene_GetFrameState())->secondaryTable != 0) {
        (*DAT_008873EC)(((FldFrame *)MT_Scene_GetFrameState())->secondaryTable);
        ((FldFrame *)MT_Scene_GetFrameState())->secondaryTable = 0;
    }
}

// FUN_0015CF70
/* Request the common fixed-record NPC table. */
s32 NpcTable_RequestFixedTable(void)
{
    char directoryPath[0x80];
    char filePath[0x80];

    strcpy(directoryPath, D_005F0790);
    sprintf(filePath, D_005F0830);
    if (H_Cdvd_FileExists(filePath) == 0) {
        return 0;
    }
    func_00440b68(&D_00762F20, D_005F07C0, 0x1A2);
    return (s32)H_Cdvd_AcquireDirectory(filePath, 0);
}

// FUN_0015D000
/* Copy the fixed table and count its 0xFFFF section markers at 0x84-byte intervals. */
/* measured: without opt_loop_invariants on, mwcc rematerializes the loop's
   invariant base inside the body (nd 6); with it it hoists to the preheader
   like retail (nd 0). */
s32 NpcTable_InstallFixedTable(u8 *request)
{
    /* Typed HCdvd/API rewrite lost MATCH; keep its +0x110 payload and +0x118 size accesses. */
    s32 handle;
    s32 count;
    FldNpcFixedEntry *work;
    s32 i;

    if (request == 0) {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded(request) == 0) {
        return 0;
    }
    chkmemAllocSiteTag(D_005F07C0, 0x1B3);
    handle = (s32)D_008873F4[0](1, (s32)(*(u32 *)(request + 0x118)), 0x40000);
    D_00764384 = handle;
    memcpy((void *)handle, *(void **)(request + 0x110), *(s32 *)(request + 0x118));
    count = *(u32 *)(request + 0x118) / 0x84;
    D_0076438C = count;
    work = (FldNpcFixedEntry *)D_00764384;
    i = 0;
    while (i < count) {
        if (work->marker == 0xFFFF) {
            D_00764388 += 1;
        }
        i++;
        work += 1;
    }
    H_Cdvd_Destroy(request);
    return 1;
}

/* measured: see annotation above (NpcTable_InstallFixedTable). */
// FUN_0015D100
/* Request a numbered block table when its file exists. */
void NpcTable_RequestBlockTable(u8 *block, s32 blockIndex)
{
    char directoryPath[0x80];
    char filePath[0x80];

    strcpy(directoryPath, D_005F0790);
    sprintf(filePath, D_005F0850, blockIndex);
    if (H_Cdvd_FileExists(filePath) != 0) {
        func_00440b68(&D_00762F20, D_005F07C0, 0x1DF);
        ((FldNpcBlockTable *)block)->request = (HCdvd *)H_Cdvd_AcquireDirectory(filePath, 1);
    }
}

// FUN_0015D1A0
/* Poll a block request and retain an owned copy of its payload. */
s32 NpcTable_InstallBlockTable(u8 *block, s32 blockIndex)
{
    /* Typed HCdvd/API rewrite lost MATCH; keep its +0x110 payload and +0x118 size accesses. */
    /* FldNpcBlockTable typing changes alias/reload scheduling under MWCC; retain byte access for MATCH. */
    s32 size;

    if (*(s32 *)(block + 0xC) == 0) {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded(*(u8 **)(block + 0xC)) == 0) {
        goto ret0;
    }
    chkmemAllocSiteTag(D_005F07C0, 0x1F6);
    size = *(u32 *)(*(u8 **)(block + 0xC) + 0x118);
    *(s32 *)(block + 0x14) = (s32)D_008873F4[0](1, (s32)(size), 0x40000);
    *(s32 *)(block + 0x18) = *(s32 *)(*(u8 **)(block + 0xC) + 0x118);
    memcpy(*(void **)(block + 0x14), *(void **)(*(u8 **)(block + 0xC) + 0x110), *(s32 *)(*(u8 **)(block + 0xC) + 0x118));
    H_Cdvd_Destroy(*(u8 **)(block + 0xC));
    *(s32 *)(block + 0xC) = 0;
    return 1;
ret0:
    return 0;
}

