#include "include_asm.h"
#include "sdk_task_registration.h"
/* Persona 4 USA decompilation - evtPMFileReader.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

/* 0x40-byte task work, allocated by evtPMFileReaderCreate and released by
   evtPMFileReaderTaskDestroy. Section handles remain words because CD lookup
   and table allocation both write them through their existing APIs. */
typedef struct EvtPMReader {
    s32 state;
    s32 useAllocatedTables;
    s32 loadDirectory;
    s32 eventId;
    s32 variantId;
    s32 unk14;
    u16 completionFlag;
    u8 pad1A[2];
    s32 directoryA;
    s32 directoryB;
    s32 directoryC;
    s32 ownedTableA;
    s32 ownedTableB;
    s32 ownedTableC;
    s32 tableA;
    s32 tableB;
    s32 tableC;
} EvtPMReader;

/* Section directory: header count at +0x10, 16-byte entries starting at +0x20.
   Kind zero points at the record inspected by evtPMFileReaderGetFirstEntry. */
typedef struct EvtPMSectionHeader {
    u8 pad00[0x10];
    u32 count;
    u8 pad14[0xC];
} EvtPMSectionHeader;
typedef struct EvtPMSectionEntry {
    u32 kind;
    u8 pad04[8];
    u32 offset;
} EvtPMSectionEntry;
typedef struct EvtPMFirstRecord {
    u8 pad00[0x10];
    u32 firstValue;
    u32 secondValue;
    u8 pad18[2];
    u8 byteValue;
    u8 pad1B;
    s16 halfwordValue;
} EvtPMFirstRecord;
/* The same 0x114-byte movie context allocated by evtPolygonMovieAlloc; only
   its secondary-section fields are needed by this scan. */
typedef struct EvtPMScanContext {
    u8 pad00[0x80];
    EvtPMSectionHeader *section;
    EvtPMSectionEntry *entries;
    u8 pad88[8];
    EvtPMFirstRecord *record;
    u8 pad94[0x80];
} EvtPMScanContext;


extern s32 kwlnTaskIsLinked();
extern u32 kwlnTaskGetWork(void *task);
extern u8 D_0063C970[];
extern u8 D_0063C990[];
extern char iGpffffa7c0;
extern void evtPolygonMovieFormatNames(s32 eventId, s32 variantId, u8 *tableNameA, u8 *tableNameB, u8 *tableNameC, u8 *directoryName);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 mode);
extern s32 H_Cdvd_IsFileLoaded(u8 *request);
extern s32 H_Cdvd_LookupRequest(u8 *path, s32 *fileSize);
extern s32 *evtPolygonMovieAllocTableA(s32 **table);
extern s32 *evtPolygonMovieAllocTableB(s32 **table);
extern s32 *evtPolygonMovieAllocTableC(s32 **table);
extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void evtMemAccount(s32 category, s32 size);
extern void memset(void *dest, s32 value, s32 size);

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];
extern u8 D_0063CAA0[];
extern s32 evtPMFileReaderTaskUpdate(u8 *task);
extern void evtPMFileReaderTaskDestroy(u8 *task);
extern void datSetFlag(s32 a, s32 b);
extern void H_Cdvd_Destroy(s32 a);
extern void func_00440b68(char *fmt, ...);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 D_0063C9B0[];
extern u8 D_0063C9D0[];
extern u8 D_0063CA00[];
extern u8 D_0063CA20[];
extern u8 D_0063CA50[];
extern u8 D_0063CA70[];

/* measured: nd 126. The two else-branch flag checks (case 2: `if (p->flag == 1)`
   and case 4) emit `lw; addiu $v0,1; bne` in b210, but retail emits
   `lw; xori $v0,$v0,1; sltiu $v0,$v0,1; beqz` (the boolean-then-test form).
   Every spelling probed (==1 / !=1 / struct field / pointer cast / named local /
   u8/u16/u32 types / switch on flag) folds to `beq`/`bne`, never the xori/sltiu
   pair; the 4-byte residual from this floor propagates to every branch target
   in the else-branch (nd 126). Same family as cmpConfig func_0035cb00's
   documented sltu/xori booleanization floor. INCLUDE_ASM restored. */
/* measured: matched by typing the context pointer as a byte pointer (the
   u8 ** draft scaled every field offset by four), materialising the
   `*(s32 *)(ctx + 4) == 1` tests as boolean values rather than branches,
   restoring the empty `case 7` the second dispatch needs for its eight-
   entry jump table, writing the cases in ascending order, taking the
   format buffer through its small-data name, and giving evtPolygonMovieFormatNames
   the pointer parameters its own body already requires. */
// Intent: Reader task update: loads the movie's CD files (sections 0x0C..0x38) in stages and advances the reader state machine to done (state 7) [inferred]
// FUN_002938C0
s32 evtPMFileReaderTaskUpdate(u8 *task) {
    s32 fileSize;
    u8 tableNameA[64];
    u8 tableNameB[64];
    u8 tableNameC[64];
    u8 directoryName[64];
    s32 requestA;
    s32 requestB;
    s32 requestC;
    u16 completionFlag;
    EvtPMReader *reader;
    s32 state;
    s32 ready;

    reader = (EvtPMReader *)kwlnTaskGetWork(task);
    evtPolygonMovieFormatNames(reader->eventId, reader->variantId, tableNameA, tableNameB, tableNameC, directoryName);
    if (reader->loadDirectory != 0) {
        state = reader->state;
        switch ((s32)state) {
        case 0:
            reader->ownedTableA = 0;
            reader->ownedTableB = 0;
            reader->ownedTableC = 0;
            reader->tableA = 0;
            reader->tableB = 0;
            reader->tableC = 0;
            func_00440b68(&iGpffffa7c0, D_0063C970, 0x3F);
            reader->directoryA = (s32)H_Cdvd_AcquireDirectory(directoryName, 1);
            reader->state = 1;
            break;
        case 1:
            if (H_Cdvd_IsFileLoaded((u8 *)reader->directoryA) == 1) {
                requestA = H_Cdvd_LookupRequest(tableNameA, &fileSize);
                reader->tableA = requestA;
                if (requestA == 0) {
                    reader->ownedTableA = (s32)evtPolygonMovieAllocTableA((s32 **)&reader->tableA);
                }
                evtMemAccount(4, fileSize);
                requestB = H_Cdvd_LookupRequest(tableNameB, &fileSize);
                reader->tableB = requestB;
                if (requestB == 0) {
                    reader->ownedTableB = (s32)evtPolygonMovieAllocTableB((s32 **)&reader->tableB);
                }
                evtMemAccount(5, fileSize);
                requestC = H_Cdvd_LookupRequest(tableNameC, &fileSize);
                reader->tableC = requestC;
                if (requestC == 0) {
                    reader->ownedTableC = (s32)evtPolygonMovieAllocTableC((s32 **)&reader->tableC);
                }
                evtMemAccount(6, fileSize);
                reader->state = 7;
            }
            break;
        case 7:
            break;
        }
    } else {
        state = reader->state;
        switch ((s32)state) {
        case 0:
            func_00440b68(&iGpffffa7c0, D_0063C970, 0x6C);
            reader->directoryA = (s32)H_Cdvd_AcquireDirectory(tableNameA, 0);
            reader->state = 1;
            break;
        case 1:
            if (H_Cdvd_IsFileLoaded((u8 *)reader->directoryA) == 1) {
                reader->ownedTableA = 0;
                reader->tableA = H_Cdvd_LookupRequest(tableNameA, &fileSize);
                evtMemAccount(4, fileSize);
                reader->state = 2;
            }
            break;
        case 2:
            ready = (reader->useAllocatedTables == 1);
            if (ready != 0) {
                reader->ownedTableB = (s32)evtPolygonMovieAllocTableB((s32 **)&reader->tableB);
                if (reader->tableB == 0) {
                    kAssertFail(D_0063C970, 0x88);
                }
                reader->state = 4;
            } else {
                func_00440b68(&iGpffffa7c0, D_0063C970, 0x8C);
                reader->directoryB = (s32)H_Cdvd_AcquireDirectory(tableNameB, 0);
                reader->state = 3;
            }
            break;
        case 3:
            if (H_Cdvd_IsFileLoaded((u8 *)reader->directoryB) == 1) {
                reader->state = 4;
                reader->ownedTableB = 0;
                reader->tableB = H_Cdvd_LookupRequest(tableNameB, &fileSize);
                evtMemAccount(5, fileSize);
            }
            break;
        case 4:
            ready = (reader->useAllocatedTables == 1);
            if (ready != 0) {
                reader->ownedTableC = (s32)evtPolygonMovieAllocTableC((s32 **)&reader->tableC);
                if (reader->tableC == 0) {
                    kAssertFail(D_0063C970, 0xA4);
                }
                reader->state = 6;
            } else {
                func_00440b68(&iGpffffa7c0, D_0063C970, 0xA8);
                reader->directoryC = (s32)H_Cdvd_AcquireDirectory(tableNameC, 0);
                reader->state = 5;
            }
            break;
        case 5:
            if (H_Cdvd_IsFileLoaded((u8 *)reader->directoryC) == 1) {
                reader->state = 6;
                reader->ownedTableC = 0;
                reader->tableC = H_Cdvd_LookupRequest(tableNameC, &fileSize);
                evtMemAccount(6, fileSize);
            }
            break;
        case 6:
            reader->completionFlag = 0;
            completionFlag = reader->completionFlag;
            if ((s32)completionFlag > 0) {
                datSetFlag(completionFlag, 1);
            }
            reader->state = 7;
            func_00440b68((char *)D_0063C990);
            break;
        case 7:
            break;
        }
    }
    return 0;
}

// Intent: Reader task destroy: destroys the CD requests and flags, frees the reader's sections and releases the work block [inferred]
// FUN_00293D30
void evtPMFileReaderTaskDestroy(u8 *task) {
    EvtPMReader *reader;
    u16 completionFlag;

    reader = (EvtPMReader *)kwlnTaskGetWork(task);
    completionFlag = reader->completionFlag;
    if ((s32)completionFlag > 0) {
        datSetFlag(completionFlag, 0);
    }
    if (reader->directoryA != 0) {
        H_Cdvd_Destroy(reader->directoryA);
        reader->directoryA = 0;
        func_00440b68((char *)D_0063C9B0);
    }
    if (reader->ownedTableA != 0) {
        jtbl_008873EC[0]((void *)reader->ownedTableA);
        evtMemAccount(4, 0);
        reader->ownedTableA = 0;
        func_00440b68((char *)D_0063C9D0);
    }
    if (reader->directoryB != 0) {
        H_Cdvd_Destroy(reader->directoryB);
        reader->directoryB = 0;
        func_00440b68((char *)D_0063CA00);
    }
    if (reader->ownedTableB != 0) {
        jtbl_008873EC[0]((void *)reader->ownedTableB);
        evtMemAccount(5, 0);
        reader->ownedTableB = 0;
        func_00440b68((char *)D_0063CA20);
    }
    if (reader->directoryC != 0) {
        H_Cdvd_Destroy(reader->directoryC);
        reader->directoryC = 0;
        func_00440b68((char *)D_0063CA50);
    }
    if (reader->ownedTableC != 0) {
        jtbl_008873EC[0]((void *)reader->ownedTableC);
        evtMemAccount(6, 0);
        reader->ownedTableC = 0;
        func_00440b68((char *)D_0063CA70);
    }
    jtbl_008873EC[0](reader);
    evtMemAccount(1, -0x40);
}

// Creates a 0x40-byte reader with filename ids and table-allocation mode; returns its task handle.
// FUN_00293ED0
s32 evtPMFileReaderCreate(s32 eventId, s32 variantId, s32 value, s32 useAllocatedTables) {
    EvtPMReader *reader;

    chkmemAllocSiteTag(D_00748340, 0x52);
    reader = (EvtPMReader *)D_008873F4[0](1, 0x40, 0x40000);
    evtMemAccount(1, 0x40);
    memset(reader, 0, 0x40);
    reader->eventId = eventId;
    reader->variantId = variantId;
    reader->unk14 = value;
    reader->useAllocatedTables = useAllocatedTables;
    reader->loadDirectory = 0;
    return (s32)kwlnTaskCreate((const void *)(D_0063CAA0), 0xF, 1, 1, evtPMFileReaderTaskUpdate, evtPMFileReaderTaskDestroy, (u8 *)(reader));
}

// Intent: Returns 1 when the reader task has finished loading (state 7) [inferred]
// FUN_00293FC0
s32 evtPMFileReaderIsDone(s32 task) {
    if (kwlnTaskIsLinked(task) == 0) {
        kAssertFail(D_0063C970, 0x123);
    }
    if (((EvtPMReader *)kwlnTaskGetWork((void *)task))->state == 7) {
        return 1;
    }
    return 0;
}

// Intent: Returns the reader task's work block; asserts the task is linked [inferred]
// FUN_00294040
u8 *evtPMFileReaderGetWork(s32 task) {
    if (kwlnTaskIsLinked(task) == 0) {
        kAssertFail(D_0063C970, 0x131);
    }
    return (u8 *)kwlnTaskGetWork((void *)task);
}

// Intent: Returns the first kind-0 record of the reader's table through the output pointers, or 0 when none is found or the reader is not done [inferred]
// FUN_002940A0
s32 evtPMFileReaderGetFirstEntry(s32 task, s32 *firstValue, s32 *secondValue, s32 *byteValue, s32 *halfwordValue) {
    EvtPMScanContext tableContext;
    EvtPMScanContext *context = &tableContext;
    EvtPMReader *reader;
    s32 entryIndex;
    s32 count;
    EvtPMSectionEntry *entry;
    EvtPMFirstRecord *record;

    memset(context, 0, 0x114);
    if (kwlnTaskIsLinked(task) == 0) {
        kAssertFail((char *)D_0063C970, 0x123);
    }
    if (((EvtPMReader *)kwlnTaskGetWork((void *)task))->state != 7) {
        if (kwlnTaskIsLinked(task) == 0) {
            kAssertFail((char *)D_0063C970, 0x123);
        }
        if (((EvtPMReader *)kwlnTaskGetWork((void *)task))->state != 7) {
            kAssertFail((char *)D_0063C970, 0x143);
        }
        return 0;
    }
    reader = (EvtPMReader *)kwlnTaskGetWork((void *)task);
    context->section = (EvtPMSectionHeader *)reader->tableB;
    if (reader->tableB != 0) {
        context->entries = (EvtPMSectionEntry *)(reader->tableB + 0x20);
    } else {
        context->entries = NULL;
    }
    entryIndex = 0;
    count = context->section->count;
    for (; entryIndex < count; entryIndex++) {
        entry = context->entries;
        entry = (EvtPMSectionEntry *)((u32)entry + entryIndex * 16);
        switch (entry->kind) {
        case 0:
            record = (EvtPMFirstRecord *)(reader->tableB + entry->offset);
            context->record = record;
            *firstValue = record->firstValue;
            *secondValue = context->record->secondValue;
            *byteValue = context->record->byteValue;
            *halfwordValue = context->record->halfwordValue;
            return 1;
        default:
            break;
        }
    }
    return 0;
}

