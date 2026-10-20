/* Source unit: src/Script/scrScriptProcess_0029d900.c */
#include "type.h"
#include "scr_internal.h"
#include "scr_data_internal.h"
#include "sdk_task_registration.h"
#include "kwln_task_internal.h"
#include "member_access.h"
#include "byte_address_internal.h"
#include "sdk_pad_mask_column.h"

#include "include_asm.h"
#include "sdk_dbprt.h"


typedef struct KwlnTask KwlnTask;

void* dds3GetProcessWorkData(KwlnTask* task);
void dds3SetProcessWorkData(KwlnTask* task, void* workData);
void scrReleaseScript(ScrScriptWork* scr);
void scrDestroyTask(u8 *sdkTaskBytes);
extern s32 scrRunTaskStep(u8 *task);
extern void scrPoolFree(void* pool, void* payload);


typedef struct ScrPool ScrPool;
typedef struct ScrPoolElem ScrPoolElem;

struct ScrPoolElem
{
    s32 index; // 0x00
    u8* next;  // 0x04
};

struct ScrPool
{
    s32 elemSize;   // 0x00
    s32 elemCount;  // 0x04
    s32 freeCount;  // 0x08
    u8* freeList;   // 0x0C
};


typedef struct ScrTaskData
{
    u32 flags;        // 0x00
    u8* unk_04;       // 0x04. Filer task pointer.
    s32 state;        // 0x08
    s32 unk_0C;       // 0x0C
    char text[0x200]; // 0x10
    s32 unk_210;      // 0x210
    ScrScriptWork* unk_214; // 0x214
    s32 unk_218;      // 0x218
    union {
        struct {
            f32 unk_21C;
            f32 unk_220;
        };
        s64 coordinates __attribute__((aligned(4)));
    } __attribute__((packed));
    s32 unk_224;      // 0x224
} ScrTaskData;
typedef unsigned int ScrE040U128 __attribute__((mode(TI)));

extern f32 iGpffffa7cc;
extern char iGpffffa7d0;
extern char iGpffffa7d8;


int strcmp(const char* s1, const char* s2);

// Script list bookkeeping globals (gp window).
extern s32 D_00764604; // -0x4AEC. Number of live scripts.
extern ScrScriptWork* D_00764608; // -0x4AE8. List head.
extern ScrScriptWork* D_0076460C; // -0x4AE4. List tail.
extern ScrPool* D_00764610; // -0x4AE0. Small block pool.
extern ScrPool* D_00764614; // -0x4ADC. Message block pool.
extern char D_007638D0;     // -0x5820. Script name buffer.

// Diagnostic strings / data outside the gp window (absolute addressing).
extern char D_0063E3D0[];
extern char D_0063E3F0[];
extern char D_0063E420[];
extern char D_0063E450[];
extern char D_0063E480[];
extern char D_0063E490[];
extern char D_0063E4A0[];
extern char D_0063E4B8[];
extern char D_0063E4D0[];
extern char D_0063E4F0[];
extern char D_0063E520[];
extern char D_0063E548[];
extern char D_0063E560[];
extern char D_0063E580[];
extern char D_0063E5A0[];
extern char D_0063E5B8[];
extern char D_0063E5C8[];
extern ScrE040U128 D_0063E5E0;
extern char D_0063E5F0[];
extern char D_0063E600[];
extern char D_0063E618[];
extern void *(*D_008873F4[])(size_t, size_t, u32); // Allocator slot.
extern void (*jtbl_008873EC[])(void *);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern SdkPadMaskColumn D_008C0256[];

void chkmemAllocSiteTag(char* file, s32 line);
void kAssertFail(char* file, s32 line);
void kAssertFailAt(const void *msg, const void *file, u32 line);
void kAssertFailMsg(char* file, s32 line, char* msg, s32 value);
void memset(void* dst, s32 value, s32 size);
void memcpy(void* dst, void* src, s32 size);
void poolSetAllocationSite(char* allocationFile, s32 allocationLine);
u8* poolAlloc(s32 requestedSize);
void poolFree(void* address);
u32 kwlnTaskGetWork(void* task);
s32 scrProcessGetHandleNoop(void);
void scrProcessInitNoop(s32);
void func_00440b68(char* fmt, ...);
void H_Dbprt_FmtLog(char* fmt, ...);
void itfMesWindowReleaseIfActive(s32 handle);
s32 itfMesWindowInstall(u8* record);
void itfMesWindowApplyStyle(s32 handle, s32 kind, s32 unusedValue);
s32 kwlnTaskDestroyWithHierarchy(KwlnTask* task);
void H_Cdvd_Destroy(s32 cdvd);
u8* sdkFilerTaskCreate(void* parent, const char* path);
s32 sprintf(char* dst, const char* format, ...);
u32 strlen(void*);


extern s32 scrLoadScriptStep(u8* sdkTask);
s32 H_Cdvd_IsFileLoaded(s32 cdvd);
s32 H_Cdvd_AcquireDirectory(void* path, s32 flags);
s32 sdkFilerPollResult(u8* task, s8* resultPath);
void strcpy(void*, void*);
s32 H_Cdvd_LookupRequest(s32 pathAddress, s32 *slot);
void PrimDrawFlatRectangle(u8 *colorData, f32 *rectangleData, f32 depth, s32 preserveState);




// Script pool: allocates a fixed-size element pool and threads its free list.
// FUN_0029D060
ScrPool* scrPoolCreate(s32 elemSize, s32 elemCount)
{
    ScrPool* pool;
    ScrPoolElem* elem;
    s32 size;
    s32 i;
    s32 last;

    chkmemAllocSiteTag(D_0063E3D0, 0x3D);
    size = elemSize + 8;
    pool = ((ScrPool* (*)(s32, s32, s32))D_008873F4[0])(1, size * elemCount + 0x10, 0x40000);
    pool->freeList = (u8*)(pool + 1);
    pool->elemSize = elemSize;
    pool->elemCount = elemCount;
    pool->freeCount = 0;
    elem = (ScrPoolElem*)pool->freeList;
    i = 0;
    last = elemCount - 1;
    while (i < last)
    {
        elem->index = i;
        elem->next = (u8*)((u8*)elem + size);
        elem = (ScrPoolElem*)elem->next;
        i++;
    }
    elem->index = last;
    elem->next = NULL;
    return pool;
}

// Script pool: pops one element off the free list and returns its payload.
// FUN_0029D120
u8* scrPoolAlloc(ScrPool* pool)
{
    u8* elem;

    if (pool == NULL)
    {
        kAssertFail(D_0063E3D0, 0x5B);
    }
    if (pool->freeCount == pool->elemCount)
    {
        return NULL;
    }
    elem = pool->freeList;
    if (elem == NULL)
    {
        kAssertFail(D_0063E3D0, 0x5F);
    }
    pool->freeList = ((ScrPoolElem*)elem)->next;
    ((ScrPoolElem*)elem)->next = NULL;
    pool->freeCount++;
    return elem + 8;
}


/* Measured nd 0 (object 164 / window 176). The offset-0 pool field is
   materialized through a u32 local and the first call argument through a
   named pointer local; this reproduces retail's lw $a2 before the two move
   instructions without barriers or volatile accesses. */
// Script pool: pushes an element back onto the free list and zeroes its payload.
// FUN_0029D1C0
void scrPoolFree(void *pool, void *payload)
{
    u8 *node;
    void *call0;
    u32 call2;

    if (pool == NULL) {
        kAssertFail(D_0063E3D0, 0x6A);
    }
    if (payload == NULL) {
        kAssertFail(D_0063E3D0, 0x6B);
    }
    node = (u8 *)payload - 8;
    if (((ScrPoolElem*)((u8*)payload - 8))->next == 0) {
        ((ScrPoolElem *)node)->next = ((ScrPool *)pool)->freeList;
        ((ScrPool *)pool)->freeList = node;
        ((ScrPool *)pool)->freeCount = ((ScrPool *)pool)->freeCount - 1;
        call2 = *(u32 *)pool;
        call0 = payload;
        memset(call0, 0, call2);
    }
}
// Script work list: unlinks a script work item from the global head list.
// FUN_0029D270
void scrScriptWorkUnlink(ScrScriptWork* s)
{
    if (D_00764608 == s)
    {
        D_00764608 = s->next;
    }
    else
    {
        s->prev->next = s->next;
    }
    if (D_0076460C == s)
    {
        D_0076460C = s->prev;
    }
    else
    {
        s->next->prev = s->prev;
    }
    s->prev = NULL;
    s->next = NULL;
    D_00764604--;
}

// Returns the number of live script works [inferred].
// FUN_0029D2E0
s32 scrGetWorkCount(void)
{
    return D_00764604;
}

// Allocates a script work block for a header, its content entries and the procedure at index; the work is bound to those inputs [inferred].
// FUN_0029D2F0
ScrScriptWork* scrCreateWork(ScrHeader* header, ScrContentEntry* entries, u8* procedure, u8* labels, u8* instructions, u8* messages, u8* strings, s32 index)
{
    ScrScriptWork* work;
    u8* src;
    u8* msg;
    s32 i;
    s32 j;
    s8 c;
    s32 handle;
    ScrLblPrcd* sourceProcedure;

    if (header == NULL || entries == NULL || procedure == NULL || instructions == NULL)
    {
        kAssertFailAt(D_0063E3F0, D_0063E3D0, 0x119);
        return NULL;
    }
    if (index < 0 || index >= entries->elementCount)
    {
        kAssertFailAt(D_0063E420, D_0063E3D0, 0x11D);
        return NULL;
    }
    work = (ScrScriptWork*)scrPoolAlloc(D_00764610);
    if (work == NULL)
    {
        kAssertFail(D_0063E3D0, 0x83);
    }
    if (work == NULL)
    {
        kAssertFailAt(D_0063E450, D_0063E3D0, 0x124);
        return NULL;
    }
    i = 0;
    src = procedure + (index << 5);
    sourceProcedure = (ScrLblPrcd*)src;
    while ((work->label.name[i] = sourceProcedure->name[i]) != 0)
    {
        i++;
    }
    work->label.addr = ((ScrLblPrcd*)((u32)(index << 5) + (u32)procedure))->addr;
    work->label.unk_1c = 0;
    /* Measured: field and typed-local array forms reverse addu operands; separate array bases add instructions. */
    for (j = 0; j < 0x30; j++)
    {
        MEMBER(u8, (s32)work + j, ScrScriptWork, stackTypes) = 0;
        MEMBER(u32, (s32)work + j * 4, ScrScriptWork, stackValues) = 0;
    }
    work->header = (u8*)header;
    work->entries = (u8*)entries;
    work->procedure = procedure;
    work->unk_11C = labels;
    work->unk_120 = instructions;
    work->unk_124 = messages;
    work->unk_128 = strings;
    work->index = index;
    work->soundHandle = -1;
    work->unk_134 = 0;
    work->unk_138 = 0;
    work->msgA = NULL;
    work->msgB = NULL;
    work->taskId = 0;
    work->prev = NULL;
    work->next = NULL;
    work->proc = NULL;
    if (!(header->localIntNum <= 0xC8))
    {
        kAssertFailMsg(D_0063E3D0, 0x143, D_0063E480, header->localIntNum);
    }
    if (!(header->localFloatNum <= 8))
    {
        kAssertFailMsg(D_0063E3D0, 0x144, D_0063E490, header->localFloatNum);
    }
    msg = scrPoolAlloc(D_00764614);
    if (msg == NULL)
    {
        kAssertFail(D_0063E3D0, 0x93);
    }
    if (msg == NULL)
    {
        kAssertFail(D_0063E3D0, 0x148);
    }
    work->msgA = msg;
    work->msgB = msg + 0x320;
    if (messages != NULL)
    {
        handle = itfMesWindowInstall(messages);
        work->soundHandle = handle;
        itfMesWindowApplyStyle(handle, 0, 0);
    }
    if (D_0076460C == NULL)
    {
        D_00764608 = work;
        D_0076460C = work;
        work->prev = NULL;
        work->next = NULL;
    }
    else
    {
        work->prev = D_0076460C;
        D_0076460C->next = work;
        work->next = NULL;
        D_0076460C = work;
    }
    D_00764604++;
    func_00440b68(D_0063E4A0, (index << 5) + procedure);
    func_00440b68(D_0063E4B8, (index << 5) + procedure);
    return work;
}

// Creates the procedure work for the header at index, from the header's entry table.
// FUN_0029D660
/* Removing the pragma loses this match (19 differing words without, 2 tail-padding with) - measured. */
/* measured: baseline differs by 23 words; entry-pointer traversal leaves nd162; retain hoisting. */
#pragma opt_loop_invariants on
ScrScriptWork* scrCreateProcedureWork(ScrHeader* header, s32 index)
{
    ScrScriptWork* work;
    ScrLblPrcd* prcd;
    ScrLblPrcd* labels;
    u8* instr;
    u8* msgs;
    u8* strings;
    ScrContentEntry* entries;
    s32 totalEntries;
    s32 i;
    ScrContentEntry* currEntry;

    prcd = NULL;
    labels = NULL;
    instr = NULL;
    msgs = NULL;
    strings = NULL;
    if (header == NULL)
    {
        kAssertFail(D_0063E3D0, 0x180);
    }
    entries = header->entries;
    if (header->magic[0] != 'F' || header->magic[1] != 'L' || header->magic[2] != 'W' || header->magic[3] != '0')
    {
        kAssertFailAt(D_0063E4D0, D_0063E3D0, 0x186);
        return NULL;
    }
    i = 0;
    totalEntries = header->totalEntries;
    for (; i < totalEntries; i++)
    {
        currEntry = &entries[i];

        switch (currEntry->contentType)
        {
        case SCR_CONTENT_TYPE_PROCEDURE:
            prcd = (ScrLblPrcd*)((uintptr_t)header + currEntry->offset);
            break;
        case SCR_CONTENT_TYPE_LABEL:
            labels = (ScrLblPrcd*)((uintptr_t)header + currEntry->offset);
            break;
        case SCR_CONTENT_TYPE_INSTR:
            instr = (u8*)((uintptr_t)header + currEntry->offset);
            break;
        case SCR_CONTENT_TYPE_MSG:
            if (currEntry->elementCount != 0)
            {
                msgs = (u8*)((uintptr_t)header + currEntry->offset);
            }
            break;
        case SCR_CONTENT_TYPE_STRINGS:
            strings = (u8*)((uintptr_t)header + currEntry->offset);
            break;
        default:
            kAssertFailAt(D_0063E4F0, D_0063E3D0, 0x19E);
            return NULL;
        }
    }
    work = scrCreateWork((ScrHeader*)header, entries, (u8*)prcd, (u8*)labels, instr, msgs, strings, index);
    return work;
}
/* measured: see annotation above (func_0029d660). */
#pragma opt_loop_invariants off

// Runs one script step for the task: returns -1 to end the task on stop, or on error (error also asserts); returns 0 to continue [inferred].
// FUN_0029D870
s32 scrRunTaskStep(u8 *task)
{
    s32 code;

    code = scrRunCodeLoop((void*)kwlnTaskGetWork(task));
    switch (code)
    {
    case 0:  // no SCRTRACE_* value 0 exists; scrRunCodeLoop returns only 1 or 2 (kept for the matched assert)
        kAssertFailAt(D_0063E520, D_0063E3D0, 0x1C2);
        return -1;
    case 1:  // SCRTRACE_YIELD
    default:
        break;
    case 2:  // SCRTRACE_STOP
        return -1;
    }
    return 0;
}

/* Release the script attached to a scheduler task and clear its process-work pointer. */
// FUN_0029D900
void scrDestroyTask(u8 *sdkTaskBytes)
{
    KwlnTask* scrTask = (KwlnTask*)sdkTaskBytes;
    ScrScriptWork* scr;

    scr = (ScrScriptWork*)dds3GetProcessWorkData(scrTask);
    if (scr != NULL)
    {
        scrReleaseScript(scr);
    }

    dds3SetProcessWorkData(scrTask, NULL);
}

// Creates the script work pools (three 0x160-byte and three 0x340-byte elements) and runs the conditional init step [inferred].
// FUN_0029D950
void scrInitPools(void)
{
    D_00764610 = scrPoolCreate(0x160, 3);
    D_00764614 = scrPoolCreate(0x340, 3);
    if (scrProcessGetHandleNoop() == 0)
    {
        scrProcessInitNoop(0);
    }
}

// Starts procedure prcdIdx under a task priority: creates its work from the header and entries [inferred].
// FUN_0029D9B0
s32 scrStartProcedureWork(s32 priority, u8* header, u8* entries, u8* procedures, u8* labels, u8* instructions, u8* messages, u8* strings, s32 procedureIndex)
{
    ScrScriptWork* work;
    s32 task;

    work = scrCreateWork((ScrHeader*)header, (ScrContentEntry*)entries, procedures, labels, instructions, messages, strings, procedureIndex);
    if (work == NULL)
    {
        kAssertFail(D_0063E3D0, 0x23D);
    }
    task = (s32)kwlnTaskCreate((const void *)((work->index << 5) + work->procedure), priority, 1, 1, scrRunTaskStep, scrDestroyTask, (u8 *)(work));
    if (task == 0)
    {
        kAssertFail(D_0063E3D0, 0x1F4);
    }
    work->taskId = task;
    return task;
}

// Starts the procedure at index in header (no range check).
// FUN_0029DA90
s32 scrStartProcedureIndex(s32 priority, u8* header, s32 procedureIndex)
{
    ScrScriptWork* work;
    s32 task;

    work = scrCreateProcedureWork((ScrHeader*)header, procedureIndex);
    if (work == NULL)
    {
        kAssertFail(D_0063E3D0, 0x259);
    }
    task = (s32)kwlnTaskCreate((const void *)((work->index << 5) + work->procedure), priority, 1, 1, scrRunTaskStep, scrDestroyTask, (u8 *)(work));
    if (task == 0)
    {
        kAssertFail(D_0063E3D0, 0x1F4);
    }
    work->taskId = task;
    return task;
}

// Starts the procedure at index in header after a range check that asserts on failure.
// FUN_0029DB50
s32 scrStartProcedureChecked(s32 priority, s32 source, s32 size, s32 procedureIndex)
{
    ScrScriptWork* work;
    u8* text;
    s32 task;

    poolSetAllocationSite(D_0063E3D0, 0x275);
    text = poolAlloc(size);
    memset(text, 0, size);
    memcpy(text, (void*)source, size);
    work = scrCreateProcedureWork((ScrHeader*)text, procedureIndex);
    if (work == NULL)
    {
        kAssertFail(D_0063E3D0, 0x27C);
    }
    work->textBuf = text;
    task = (s32)kwlnTaskCreate((const void *)((work->index << 5) + work->procedure), priority, 1, 1, scrRunTaskStep, scrDestroyTask, (u8 *)(work));
    if (task == 0)
    {
        kAssertFail(D_0063E3D0, 0x1F4);
    }
    work->taskId = task;
    return task;
}

// Releases a script work: frees its message, text and sound handle, unlinks it from the work list, decrements the count, and returns it to the pool [inferred].
// FUN_0029DC80
void scrReleaseWork(ScrScriptWork* work)
{
    s32 handle;

    func_00440b68(D_0063E548, (work->index << 5) + work->procedure);
    H_Dbprt_FmtLog(D_0063E560, (work->index << 5) + work->procedure);
    scrPoolFree(D_00764614, work->msgA);
    handle = work->soundHandle;
    if (handle >= 0)
    {
        itfMesWindowReleaseIfActive(handle);
        func_00440b68(D_0063E580);
    }
    handle = (s32)work->textBuf;
    if (handle != 0)
    {
        poolFree((void*)handle);
        func_00440b68(D_0063E5A0);
    }
    if (D_00764608 == work)
    {
        D_00764608 = work->next;
    }
    else
    {
        work->prev->next = work->next;
    }
    if (D_0076460C == work)
    {
        D_0076460C = work->prev;
    }
    else
    {
        work->next->prev = work->prev;
    }
    work->prev = NULL;
    work->next = NULL;
    D_00764604--;
    scrPoolFree(D_00764610, (u8*)work);
}

// Debug dump: logs the live work count and walks the work list [inferred].
// FUN_0029DDB0
void scrDebugDumpWorkList(void)
{
    ScrScriptWork* s;

    func_00440b68(D_0063E5B8, D_00764604);
    s = D_00764608;
    while (s != NULL)
    {
        s = s->next;
    }
    func_00440b68(D_0063E5C8, D_00764604);
}

/* Find the procedure content section, then return the matching procedure-name index or -1. */
// FUN_0029DE20
s32 scrFindPrcdIdxByName(ScrHeader* header, const char* name)
{
    ScrContentEntry* entries;
    s32 totalEntries;
    s32 i;
    ScrContentEntry* currEntry;
    ScrLblPrcd* prcd;
    s32 j;
    s32 elementCount;

    prcd = NULL;
    if (header == NULL)
    {
        return -1;
    }

    entries = header->entries;
    i = 0;
    totalEntries = header->totalEntries;
    for (; i < totalEntries; i++)
    {
        currEntry = &entries[i];

        if (currEntry->contentType == SCR_CONTENT_TYPE_PROCEDURE)
        {
            prcd = (ScrLblPrcd*)((uintptr_t)header + currEntry->offset);
            break;
        }
    }

    if (prcd == NULL)
    {
        return -1;
    }

    j = 0;
    currEntry = &entries[i];
    for (; j < currEntry->elementCount; j++)
    {
        if (strcmp(prcd[j].name, name) == 0)
        {
            return j;
        }
    }

    return -1;
}

// Looks up content entry arg1 in the table at arg0: finds the first table entry with a zero key and returns its content at arg1 * 32, or NULL when out of range [inferred].
// FUN_0029DF30
u8* scrFindContentEntry(u8* script, s32 procedureIndex)
{
    u8* found;
    u8* entries;
    s32 count;
    s32 i;
    s32 off;

    found = NULL;
    if (script == NULL) {
        return NULL;
    }
    entries = script + 0x20;
    /* i is zeroed before the count load: a for-init lands in the loop
       preheader, after it. */
    i = 0;
    count = ((ScrHeader*)script)->totalEntries;
    while (i < count) {
        if (((ScrContentEntry*)entries)[i].contentType == 0) {
            found = script + ((ScrContentEntry*)entries)[i].offset;
            break;
        }
        i++;
    }
    if (found == NULL) {
        return NULL;
    }
    off = i * 16;
    if (((ScrContentEntry*)((u8*)(off + (s32)entries)))->elementCount < procedureIndex) {
        return NULL;
    }
    return found + procedureIndex * 32;
}

// Sets the work's proc pointer; asserts when the task has no work [inferred].
// FUN_0029DFE0
void scrSetTaskProc(void* task, u8* proc)
{
    ScrScriptWork* work;

    work = (ScrScriptWork*)kwlnTaskGetWork(task);
    if (work == NULL)
    {
        kAssertFail(D_0063E3D0, 0x3C5);
    }
    work->proc = proc;
}

/* The preview passes complete color and rectangle values. Returning these
 * small objects preserves the two argument-copy lifetimes measured in the
 * retail frame; the helpers perform no additional arithmetic or side effects.
 * The color is transported as four bytes through its existing float-sized
 * storage. The rectangle has complete packed, integer and transport views. */
typedef struct ScrPreviewColor { f32 value; } ScrPreviewColor;
typedef union ScrPreviewRectangle {
    ScrE040U128 packed;
    s32 coordinates[4];
    f32 transport[4];
} ScrPreviewRectangle;

/* Construct the float-transport color object used by preview drawing. */
static inline ScrPreviewColor scrPreviewColorValue(f32 bits)
{
    ScrPreviewColor value;
    value.value = bits;
    return value;
}



/* Native b210 O2: 1284/1296 bytes, 41 resolved relocations and
 * twelve zero alignment bytes. See
 * docs/probe_archive/Script_selection_0029e040_20260924.md. */
// Task step that loads the script file named by the task's text, then creates the procedure work once the file is ready [inferred].
// FUN_0029E040
s32 scrLoadScriptStep(u8 *sdkTask)
{
    ScrTaskData *task;
    u8 *scriptBytes;
    u8 *procedureBytes;
    u8 *procedureRecord;
    s32 procedureCount;
    s32 entryIndex;
    f32 coordinate;
    ScrPreviewRectangle drawRectangle;
    ScrPreviewRectangle rectangle;
    s32 loadedSize;
    ScrPreviewColor color;
    f32 pixelX;
    f32 pixelY;
    s8 *selectionText;
    char *prefix;

    task = (ScrTaskData *)((KwlnTask *)sdkTask)->work;
    if (sdkFilerPollResult(task->unk_04, (s8 *)task->text) == 1) {
        switch (task->state) {
        case 0:
            selectionText = (s8 *)task->text;
            prefix = D_0063E5F0;
            if (*selectionText == 0) {
                return 1;
            }
            strcpy(task->text + 0x100, (u8 *)selectionText + strlen(prefix));
            func_00440b68(&iGpffffa7d0, D_0063E3D0, 0x417);
            task->unk_210 = H_Cdvd_AcquireDirectory(task->text + 0x100, 0);
            task->state = 1;
            break;
        case 1:
            if (H_Cdvd_IsFileLoaded(task->unk_210) != 0) {
                task->unk_224 = H_Cdvd_LookupRequest((s32)(task->text + 0x100), &loadedSize);
                task->state = 2;
                task->unk_218 = 0;
                task->unk_21C = 30.0f;
                task->unk_220 = 8.0f;
            }
            break;
        case 2:
            /* Linker interior alias of SdkPadRecord.directionPressed; distinct address forms retain retail reloads. */
            if (D_008C0256[0].mask & 0x1000) {
                coordinate = task->unk_220;
                if (coordinate >= 2.0f) {
                    task->unk_220 = coordinate - 1.0f;
                }
            }
            if (((SdkPadMaskColumn *)((u8 *)D_008C0256 + 0))->mask & 0x4000) {
                coordinate = task->unk_220;
                if (coordinate < 30.0f) {
                    coordinate += 1.0f;
                    task->unk_220 = coordinate;
                }
            }
            if (((SdkPadMaskColumn *)((u32)&D_008C0256[0]))->mask & 0x8000) {
                coordinate = task->unk_21C;
                if (coordinate >= 2.0f) {
                    task->unk_21C = coordinate - 1.0f;
                }
            }
            if (((SdkPadMaskColumn *)((s32)&D_008C0256[0]))->mask & 0x2000) {
                coordinate = task->unk_21C;
                if (coordinate < 45.0f) {
                    coordinate += 1.0f;
                    task->unk_21C = coordinate;
                }
            }
            if (D_008C0252[0] & 0x4000) {
                task->unk_218++;
            } else if (D_008C0252[0] & 0x1000) {
                task->unk_218--;
            }
            if (D_008C024E[0] & 0x40) {
                task->state = 3;
            } else if (D_008C024E[0] & 0x20) {
                return 2;
            }
            scriptBytes = (u8 *)task->unk_224;
            procedureBytes = NULL;
            if (scriptBytes == NULL) {
                procedureCount = 0;
            } else {
                u8 *entries;
                s32 entryCount;
                u32 entryOffset;

                entries = scriptBytes + 0x20;
                entryIndex = 0;
                entryCount = ((ScrHeader *)scriptBytes)->totalEntries;
                while (entryIndex < entryCount) {
                    u8 *entry;

                    entry = entries + entryIndex * 16;
                    if (((ScrContentEntry *)entry)->contentType == 0) {
                        procedureBytes = scriptBytes + ((ScrContentEntry *)entry)->offset;
                        break;
                    }
                    entryIndex++;
                }
                if (procedureBytes == NULL) {
                    procedureCount = 0;
                } else {
                    entryOffset = (u32)(entryIndex * 16);
                    procedureCount = ((ScrContentEntry *)(entryOffset + (u32)entries))->elementCount;
                }
            }
            if (task->unk_218 < 0) {
                task->unk_218 = 0;
            } else if (task->unk_218 >= procedureCount) {
                task->unk_218 = procedureCount - 1;
            }
            procedureRecord = scrFindContentEntry((u8 *)task->unk_224, task->unk_218);
            /* Packed record: transport the adjacent floats at 0x21C/0x220 as one unaligned 64-bit argument. */
            H_Dbprt_FmtAt(task->coordinates, &iGpffffa7d8, task->unk_218, procedureRecord);
            pixelX = 12.0f * task->unk_21C;
            pixelY = 12.0f * task->unk_220;
            color = scrPreviewColorValue(iGpffffa7cc);
            rectangle.packed = D_0063E5E0;
            rectangle.coordinates[0] = (s32)pixelX;
            rectangle.coordinates[1] = (s32)pixelY;
            drawRectangle = (*(&rectangle));
            PrimDrawFlatRectangle((u8 *)&color, drawRectangle.transport, 0.0f, 1);
            break;
        case 3:
            task->unk_214 = scrCreateProcedureWork((ScrHeader *)(void *)task->unk_224, task->unk_218);
            if (task->unk_214 == NULL) {
                kAssertFail(D_0063E3D0, 0x44C);
            }
            task->state = 4;
            task->flags |= 1;
            break;
        case 4:
            {
                s32 ret;

                ret = scrRunCodeLoop((void *)task->unk_214);
                switch (ret) {
                case 0:  // unreachable: scrRunCodeLoop returns only 1 or 2 (see above)
                    kAssertFailAt(D_0063E520, D_0063E3D0, 0x457);
                    task->flags &= ~1;
                    return 1;
                case 1:
                    break;
                case 2:
                    task->flags &= ~1;
                    return 1;
                }
            }
            break;
        }
    }
    return 0;
}
/* Measured: all 608 bytes and 35 resolved relocations match retail.
 * Loop invariants hoist the slash constant. */
/* measured: baseline differs by 6 words; explicit path-separator local leaves nd16; retain hoisting. */
#pragma opt_loop_invariants on
// Starts a script task from its text: creates the task node, then runs the load step [inferred].
// FUN_0029E550
s32 scrStartScriptTask(u8 *sdkTask)
{
    ScrTaskData *task;
    ScrScriptWork *child;
    s32 ret;
    s32 n;
    s32 handle;

    task = (ScrTaskData*)((KwlnTask*)sdkTask)->work;
    switch (task->unk_0C) {
    case 0:
        sprintf(task->text, &D_007638D0, D_0063E5F0,
                      byteAddressAdd(strlen(D_0063E5F0), (u8 *)task) + MEMBER_OFFSET(ScrTaskData, text));
        n = strlen(task->text) - 1;
        while (n > 0) {
            if (task->text[n] == 0x2F) {
                memset(&task->text[n + 1], 0, n - 1);
                break;
            }
            n--;
        }
        task->unk_04 = sdkFilerTaskCreate(sdkTask, task->text);
        task->unk_0C = 1;
        task->state = 0;
        break;
    case 1:
        ret = scrLoadScriptStep(sdkTask);
        switch (ret) {
        case 1:
            task->unk_0C = 3;
            break;
        case 2:
            child = task->unk_214;
            if (child != NULL) {
                func_00440b68(D_0063E548,
                              child->procedure + (child->index << 5));
                H_Dbprt_FmtLog(D_0063E560,
                              child->procedure + (child->index << 5));
                scrPoolFree(D_00764614, child->msgA);
                handle = child->soundHandle;
                if (handle >= 0) {
                    itfMesWindowReleaseIfActive(handle);
                    func_00440b68(D_0063E580);
                }
                if (child->textBuf != NULL) {
                    poolFree(child->textBuf);
                    func_00440b68(D_0063E5A0);
                }
                scrScriptWorkUnlink(child);
                scrPoolFree(D_00764610, child);
                task->unk_214 = 0;
            }
            handle = task->unk_210;
            if (handle != 0) {
                H_Cdvd_Destroy(handle);
                task->unk_210 = 0;
            }
            kwlnTaskDestroyWithHierarchy((KwlnTask*)task->unk_04);
            task->unk_04 = 0;
            task->unk_0C = 0;
            break;
        }
        break;
    case 3:
        func_00440b68(D_0063E600);
        return -1;
    }
    return 0;
}
#pragma opt_loop_invariants off


// Task destroy callback: releases the task's script work and CDVD handle, then runs the task's destroy hook [inferred].
// FUN_0029E7B0
void scrTaskDestroyWork(u8* sdkTask)
{
    ScrTaskData* task;
    ScrScriptWork* work;
    s32 handle;

    task = (ScrTaskData*)((KwlnTask*)sdkTask)->work;
    work = task->unk_214;
    if (work != NULL)
    {
        func_00440b68(D_0063E548, (work->index << 5) + work->procedure);
        H_Dbprt_FmtLog(D_0063E560, (work->index << 5) + work->procedure);
        scrPoolFree(D_00764614, work->msgA);
        handle = work->soundHandle;
        if (handle >= 0)
        {
            itfMesWindowReleaseIfActive(handle);
            func_00440b68(D_0063E580);
        }
        handle = (s32)work->textBuf;
        if (handle != 0)
        {
            poolFree((void*)handle);
            func_00440b68(D_0063E5A0);
        }
        scrScriptWorkUnlink(work);
        scrPoolFree(D_00764610, (u8*)work);
        task->unk_214 = 0;
    }
    handle = task->unk_210;
    if (handle != 0)
    {
        H_Cdvd_Destroy(handle);
        task->unk_210 = 0;
    }
    jtbl_008873EC[0](task);
}

// Creates a script child task under arg0 with a 0x228-byte task block, running scrStartScriptTask and scrTaskDestroyWork [inferred].
// FUN_0029E8D0
void scrCreateScriptChildTask(u8* parent)
{
    u8* buf;

    chkmemAllocSiteTag(D_0063E3D0, 0x4AB);
    buf = D_008873F4[0](1, 0x228, 0x40000);
    (s32)kwlnTaskCreateChild((void *)((s32)parent), (const void *)(D_0063E618), 0xC9, 0, 0, scrStartScriptTask, scrTaskDestroyWork, (u8 *)(buf));
}
