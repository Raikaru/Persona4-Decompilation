/* Source unit: src/Script/scrScriptProcess_0029d900.c */
#include "type.h"
#include "sdk_task_registration.h"

#include "include_asm.h"
#include "sdk_dbprt.h"


typedef struct KwlnTask KwlnTask;
typedef struct ScrData ScrData;

void* dds3GetProcessWorkData(KwlnTask* task);
void dds3SetProcessWorkData(KwlnTask* task, void* workData);
void scrReleaseScript(ScrData* scr);
void scrDestroyTask(u8 *task);
extern s32 func_0029d870(u8 *task);
extern void func_0029d1c0(void* pool, void* elem);

typedef enum
{
    SCR_CONTENT_TYPE_PROCEDURE,
    SCR_CONTENT_TYPE_LABEL,
    SCR_CONTENT_TYPE_INSTR,
    SCR_CONTENT_TYPE_MSG,
    SCR_CONTENT_TYPE_STRINGS,
    SCR_CONTENT_TYPE_MAX
} ScrContentType;

// 16 bytes
typedef struct
{
    u32 contentType;  // 0x00. See enum 'ScrContentType'
    u32 unk_04;
    s32 elementCount; // 0x08
    u32 offset;       // 0x0c
} ScrContentEntry;

// 112 bytes
typedef struct ScrHeader
{
    s32 unk_00;                                    // 0x00
    u32 scrSize;                                   // 0x04
    char magic[4];                                 // 0x08. "FLW0"
    u32 unk_0c;
    u32 totalEntries;                              // 0x10
    s16 localIntNum;                               // 0x14
    s16 localFloatNum;                             // 0x16
    s32 unk_18;                                    // 0x18
    s32 unk_1c;                                    // 0x1c
    ScrContentEntry entries[SCR_CONTENT_TYPE_MAX]; // 0x20
} ScrHeader;

// 32 bytes. Label or procedure (this name is horrible)
typedef struct
{
    char name[24]; // 0x00
    u32 addr;      // 0x18
    s32 unk_1c;    // 0x1c
} ScrLblPrcd;

typedef struct ScrPool ScrPool;
typedef struct ScrPoolElem ScrPoolElem;
typedef struct ScrScriptWork ScrScriptWork;

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

struct ScrScriptWork
{
    ScrLblPrcd label; // 0x00
    u8 unk_20[0xF0];  // 0x20
    u8* header;       // 0x110
    u8* entries;      // 0x114
    u8* procedure;    // 0x118
    u8* unk_11C;      // 0x11C
    u8* unk_120;      // 0x120
    u8* unk_124;      // 0x124
    u8* unk_128;      // 0x128
    s32 index;        // 0x12C
    s32 soundHandle;  // 0x130
    s32 unk_134;      // 0x134
    s32 unk_138;      // 0x138
    u8* textBuf;      // 0x13C
    u8* msgA;         // 0x140
    u8* msgB;         // 0x144
    s32 taskId;       // 0x148
    ScrScriptWork* prev; // 0x14C
    ScrScriptWork* next; // 0x150
    u8* proc;         // 0x154
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
    f32 unk_21C;      // 0x21C
    f32 unk_220;      // 0x220
    s32 unk_224;      // 0x224
} ScrTaskData;
typedef struct
{
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} ScrE040Vec4;

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
extern ScrE040Vec4 D_0063E5E0[];
extern char D_0063E5F0[];
extern char D_0063E600[];
extern char D_0063E618[];
extern void *(*D_008873F4[])(size_t, size_t, u32); // Allocator slot.
extern void (*jtbl_008873EC[])(void *);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u16 D_008C0256[];

void func_0044ea90(char* file, s32 line);
void func_0046d730(char* file, s32 line);
void func_0046d740(const void *msg, const void *file, u32 line);
void func_0046d700(char* file, s32 line, char* msg, s32 value);
void func_0043f9c8(void* dst, s32 value, s32 size);
void func_0043f810(void* dst, void* src, s32 size);
void func_0046a2d0(char* file, s32 line);
u8* func_0046a430(s32 size);
void func_0046a340(void* ptr);
u32 func_00452560(void* task);
s32 func_0029cb00(void* arg0, ...);
s32 func_0029e970(void);
void func_0029e960(s32 arg0);
void func_00440b68(char* fmt, ...);
void func_004504f0(char* fmt, ...);
void func_002777f0(s32 handle);
s32 func_002774d0(u8* str);
void func_00278640(s32 handle, s32 arg1, s32 arg2);
s32 func_00452080(KwlnTask* task);
void func_00454bd0(s32 handle);
u8* func_00468170(void* parent, const char* text);
s32 func_00442088(char* dst, const char* format, ...);
u32 func_00442948(void* arg0);


extern s32 func_0029e040(u8* task);
s32 func_004553c0(s32 arg0);
s32 func_00454a60(void* arg0, s32 arg1);
s32 func_004680f0(u8* task, s8* text);
void func_00442830(void* arg0, void* arg1);
u8* func_00455f70(void* arg0, void* arg1);
void func_0045d6e0(void* arg0, void* arg1, f32 fparg0, s32 arg2);
static inline u8 *scrAddOff(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}




// FUN_0029D060
ScrPool* func_0029d060(s32 elemSize, s32 elemCount)
{
    ScrPool* pool;
    ScrPoolElem* elem;
    s32 size;
    s32 i;
    s32 last;

    func_0044ea90(D_0063E3D0, 0x3D);
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

// FUN_0029D120
u8* func_0029d120(ScrPool* pool)
{
    u8* elem;

    if (pool == NULL)
    {
        func_0046d730(D_0063E3D0, 0x5B);
    }
    if (pool->freeCount == pool->elemCount)
    {
        return NULL;
    }
    elem = pool->freeList;
    if (elem == NULL)
    {
        func_0046d730(D_0063E3D0, 0x5F);
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
// FUN_0029D1C0
void func_0029d1c0(void *arg0, void *arg1)
{
    u8 *node;
    void *call0;
    u32 call2;

    if (arg0 == NULL) {
        func_0046d730(D_0063E3D0, 0x6A);
    }
    if (arg1 == NULL) {
        func_0046d730(D_0063E3D0, 0x6B);
    }
    node = (u8 *)arg1 - 8;
    if (*(s32 *)((u8 *)arg1 - 4) == 0) {
        *(u8 **)(node + 4) = *(u8 **)((u8 *)arg0 + 0xC);
        *(u8 **)((u8 *)arg0 + 0xC) = node;
        *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)arg0 + 8) - 1;
        call2 = *(u32 *)arg0;
        call0 = arg1;
        func_0043f9c8(call0, 0, call2);
    }
}
// FUN_0029D270
void func_0029d270(ScrScriptWork* s)
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

// FUN_0029D2E0
s32 func_0029d2e0(void)
{
    return D_00764604;
}

// FUN_0029D2F0
ScrScriptWork* func_0029d2f0(ScrHeader* header, ScrContentEntry* entries, u8* procedure, u8* arg3, u8* arg4, u8* arg5, u8* arg6, s32 index)
{
    ScrScriptWork* work;
    u8* src;
    u8* msg;
    s32 i;
    s32 j;
    s8 c;
    s32 handle;

    if (header == NULL || entries == NULL || procedure == NULL || arg4 == NULL)
    {
        func_0046d740(D_0063E3F0, D_0063E3D0, 0x119);
        return NULL;
    }
    if (index < 0 || index >= entries->elementCount)
    {
        func_0046d740(D_0063E420, D_0063E3D0, 0x11D);
        return NULL;
    }
    work = (ScrScriptWork*)func_0029d120(D_00764610);
    if (work == NULL)
    {
        func_0046d730(D_0063E3D0, 0x83);
    }
    if (work == NULL)
    {
        func_0046d740(D_0063E450, D_0063E3D0, 0x124);
        return NULL;
    }
    i = 0;
    src = procedure + (index << 5);
    while ((work->label.name[i] = *(s8*)((s32)src + i)) != 0)
    {
        i++;
    }
    work->label.addr = ((ScrLblPrcd*)((u32)(index << 5) + (u32)procedure))->addr;
    work->label.unk_1c = 0;
    for (j = 0; j < 0x30; j++)
    {
        *(u8*)((s32)work + j + 0x20) = 0;
        *(u32*)((s32)work + j * 4 + 0x50) = 0;
    }
    work->header = (u8*)header;
    work->entries = (u8*)entries;
    work->procedure = procedure;
    work->unk_11C = arg3;
    work->unk_120 = arg4;
    work->unk_124 = arg5;
    work->unk_128 = arg6;
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
        func_0046d700(D_0063E3D0, 0x143, D_0063E480, header->localIntNum);
    }
    if (!(header->localFloatNum <= 8))
    {
        func_0046d700(D_0063E3D0, 0x144, D_0063E490, header->localFloatNum);
    }
    msg = func_0029d120(D_00764614);
    if (msg == NULL)
    {
        func_0046d730(D_0063E3D0, 0x93);
    }
    if (msg == NULL)
    {
        func_0046d730(D_0063E3D0, 0x148);
    }
    work->msgA = msg;
    work->msgB = msg + 0x320;
    if (arg5 != NULL)
    {
        handle = func_002774d0(arg5);
        work->soundHandle = handle;
        func_00278640(handle, 0, 0);
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

// FUN_0029D660
/* Removing the pragma loses this match (19 differing words without, 2 tail-padding with) - measured. */
#pragma opt_loop_invariants on
ScrScriptWork* func_0029d660(ScrHeader* header, s32 index)
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
        func_0046d730(D_0063E3D0, 0x180);
    }
    entries = header->entries;
    if (header->magic[0] != 'F' || header->magic[1] != 'L' || header->magic[2] != 'W' || header->magic[3] != '0')
    {
        func_0046d740(D_0063E4D0, D_0063E3D0, 0x186);
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
            func_0046d740(D_0063E4F0, D_0063E3D0, 0x19E);
            return NULL;
        }
    }
    work = func_0029d2f0((ScrHeader*)header, entries, (u8*)prcd, (u8*)labels, instr, msgs, strings, index);
    return work;
}
/* measured: see annotation above (func_0029d660). */
#pragma opt_loop_invariants off

// FUN_0029D870
s32 func_0029d870(u8 *task)
{
    s32 code;

    code = func_0029cb00((void*)func_00452560(task));
    switch (code)
    {
    case 0:  // SCRTRACE_ERROR
        func_0046d740(D_0063E520, D_0063E3D0, 0x1C2);
        return -1;
    case 1:  // SCRTRACE_YIELD
    default:
        break;
    case 2:  // SCRTRACE_STOP
        return -1;
    }
    return 0;
}

// FUN_0029D900
void scrDestroyTask(u8 *sdkTaskBytes)
{
    KwlnTask* scrTask = (KwlnTask*)sdkTaskBytes;
    ScrData* scr;

    scr = (ScrData*)dds3GetProcessWorkData(scrTask);
    if (scr != NULL)
    {
        scrReleaseScript(scr);
    }

    dds3SetProcessWorkData(scrTask, NULL);
}

// FUN_0029D950
void func_0029d950(void)
{
    D_00764610 = func_0029d060(0x160, 3);
    D_00764614 = func_0029d060(0x340, 3);
    if (func_0029e970() == 0)
    {
        func_0029e960(0);
    }
}

// FUN_0029D9B0
s32 func_0029d9b0(s32 arg0, u8* arg1, u8* arg2, u8* arg3, u8* arg4, u8* arg5, u8* arg6, u8* arg7, s32 arg8)
{
    ScrScriptWork* work;
    s32 task;

    work = func_0029d2f0((ScrHeader*)arg1, (ScrContentEntry*)arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    if (work == NULL)
    {
        func_0046d730(D_0063E3D0, 0x23D);
    }
    task = (s32)func_00451de0((const void *)((work->index << 5) + work->procedure), arg0, 1, 1, func_0029d870, scrDestroyTask, (u8 *)(work));
    if (task == 0)
    {
        func_0046d730(D_0063E3D0, 0x1F4);
    }
    work->taskId = task;
    return task;
}

// FUN_0029DA90
s32 func_0029da90(s32 arg0, u8* arg1, s32 arg2)
{
    ScrScriptWork* work;
    s32 task;

    work = func_0029d660((ScrHeader*)arg1, arg2);
    if (work == NULL)
    {
        func_0046d730(D_0063E3D0, 0x259);
    }
    task = (s32)func_00451de0((const void *)((work->index << 5) + work->procedure), arg0, 1, 1, func_0029d870, scrDestroyTask, (u8 *)(work));
    if (task == 0)
    {
        func_0046d730(D_0063E3D0, 0x1F4);
    }
    work->taskId = task;
    return task;
}

// FUN_0029DB50
s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    ScrScriptWork* work;
    u8* text;
    s32 task;

    func_0046a2d0(D_0063E3D0, 0x275);
    text = func_0046a430(arg2);
    func_0043f9c8(text, 0, arg2);
    func_0043f810(text, (void*)arg1, arg2);
    work = func_0029d660((ScrHeader*)text, arg3);
    if (work == NULL)
    {
        func_0046d730(D_0063E3D0, 0x27C);
    }
    work->textBuf = text;
    task = (s32)func_00451de0((const void *)((work->index << 5) + work->procedure), arg0, 1, 1, func_0029d870, scrDestroyTask, (u8 *)(work));
    if (task == 0)
    {
        func_0046d730(D_0063E3D0, 0x1F4);
    }
    work->taskId = task;
    return task;
}

// FUN_0029DC80
void func_0029dc80(ScrScriptWork* work)
{
    s32 handle;

    func_00440b68(D_0063E548, (work->index << 5) + work->procedure);
    func_004504f0(D_0063E560, (work->index << 5) + work->procedure);
    func_0029d1c0(D_00764614, work->msgA);
    handle = work->soundHandle;
    if (handle >= 0)
    {
        func_002777f0(handle);
        func_00440b68(D_0063E580);
    }
    handle = (s32)work->textBuf;
    if (handle != 0)
    {
        func_0046a340((void*)handle);
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
    func_0029d1c0(D_00764610, (u8*)work);
}

// FUN_0029DDB0
void func_0029ddb0(void)
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

// FUN_0029DF30
u8* func_0029df30(u8* arg0, s32 arg1)
{
    u8* found;
    u8* entries;
    s32 count;
    s32 i;
    s32 off;

    found = NULL;
    if (arg0 == NULL) {
        return NULL;
    }
    entries = arg0 + 0x20;
    /* i is zeroed before the count load: a for-init lands in the loop
       preheader, after it. */
    i = 0;
    count = *(s32*)(arg0 + 0x10);
    while (i < count) {
        if (*(s32*)(entries + i * 16) == 0) {
            found = arg0 + *(s32*)(entries + i * 16 + 0xC);
            break;
        }
        i++;
    }
    if (found == NULL) {
        return NULL;
    }
    off = i * 16;
    if (*(s32*)((u8*)(off + (s32)entries) + 8) < arg1) {
        return NULL;
    }
    return found + arg1 * 32;
}

// FUN_0029DFE0
void func_0029dfe0(void* arg0, u8* proc)
{
    ScrScriptWork* work;

    work = (ScrScriptWork*)func_00452560(arg0);
    if (work == NULL)
    {
        func_0046d730(D_0063E3D0, 0x3C5);
    }
    work->proc = proc;
}

/* Measured floor: 282 reloc-masked differing words (obj 1264B/window 1296B, 2.5% short, within 3% 1257-1335B; fnalign 124 edits +10 reloc-only, retail 320I/object 316I) via probe_variants + measure_guarded + fnalign. */
/* Commands (pwd source/Persona4-Decompilation): python3 -E -s tools/probe_variants.py src/Script/scrScriptProcess.c func_0029e040 --candidate base=/tmp/auth_array_candidate.c --candidate AltGuard=/tmp/auth_A_ltguard.c --candidate clampLt=/tmp/auth_B_clampLt.c --candidate fltFirst=/tmp/auth_D_fltFirst.c --candidate ifchain=/tmp/auth_E_ifchain.c; python3 -E -s tools/measure_guarded.py src/Script/scrScriptProcess.c func_0029e040; python3 -E -s tools/fnalign.py src/Script/.probe_array_test.c func_0029e040 --addr 0029e040 */
/* Re-derived line-by-line against rabbitizer dis (frame 0x60, task=*(arg0+0x38), func_004680f0 2-arg then beq chain 4->2E4A0/3->2E454/2->2E174/1->2E128/0->2E0B0/else->2E528). case0: lb s8 0x10 + func_00442948 1-arg/func_00442830 2-arg/func_00440b68 3-arg/func_00454a60 2-arg storing unk_210/state=1. case1: func_004553c0 1-arg then func_00455f70 2-arg + 30.0f/8.0f via lui. case2: D_008C0256 0x1000/0x4000 on 0x220 (2.0/30.0 via c.lt.s+bc1t/bc1f + sub/add 1.0f) + 0x8000/0x2000 on 0x21C (2.0/45.0), D_008C0252 0x4000 inc/0x1000 dec on 0x218, D_008C024E 0x40->state3/0x20->ret2, entry+0x20 stride-16 search (*(entry+0x10) count, slt loop, found=entry+*(e+0xC) on zero word, count=*(q+i*16+8)), 0x218 clamp (bgez/slt, count-1), func_0029df30 2-arg + s64 ldr/ldl 0x21C + func_00450050 s64+ptr+s32+ptr + lq D_0063E5E0 + 12.0f muls + cvt.w.s pair + func_0045d6e0 ptr+ptr+f32+s32. case3: func_0029d660 2-arg + func_0046d730 2-arg + state4/flags|=1. case4: func_0029cb00 1-arg dispatch (2->clear+ret1, 1->break, 0->log+clear+ret1 via func_0046d740 3-arg). */
/* Idioms measured authoritative (pwd source/Persona4-Decompilation, no hardware-asm): absolute D_008C/D_0063E5E0[0] (retail lui+lhu/lq; scalar GPREL 1216B/289wd vs array 1264B/282wd, +48B/-7wd, header scalar->array preserves 21 MATCH via scratch verify 21 MATCH+1 MISMATCH); scalar &iGpffffa7d0/&iGpffffa7d8/iGpffffa7cc gp-relative (array would cost extra lui per 0036e140 lever); s8 lb (retail lb, casts fixed first: (s8*)text, pointer unk_214 without (s32)); 30/8/2/1/45/12 via lui; lq+cvt pair; s64 ldr/ldl; mul-before-flt kept (flt-first neutral 282 vs 282, kept retail order); block-scope q/n/e; switch kept (base 282 vs ifchain descending 289, +7); AltGuard empty-else sequential-< neutral 282, clampLt sequential-< neutral 282, kept readable >= per honesty and 0036e140 <guard preference measured neutral; task->unk_218++/-- single-register form per 0036e140 cnt lever; opt_common_subs off not adopted (retail rematerialises 0256 4x lui vs single lhu CSE, needs waiver, not measured beneficial); q+i*16 kept honest (L378 offset-first vs L330 base-first is scheduling). Prior MIRROR 1216B scalar, MMisc3 nd858 not reproducing (current 282/289). No pragma/volatile/asm. */
// FUN_0029E040 NONMATCHING
#ifdef NON_MATCHING
s32 func_0029e040(u8 *arg0)
{
    ScrTaskData *task;
    u8 *entry;
    u8 *found;
    u8 *ptr;
    s32 count;
    s32 i;
    f32 f;
    ScrE040Vec4 v0;
    ScrE040Vec4 v1;
    f32 flt;
    s32 out;

    task = *(ScrTaskData **)(arg0 + 0x38);
    if (func_004680f0(task->unk_04, (s8 *)task->text) != 1) {
        return 0;
    }
    switch (task->state) {
    case 0:
        if (*(s8 *)task->text == 0) {
            return 1;
        }
        func_00442830(task->text + 0x100, task->text + func_00442948(D_0063E5F0));
        func_00440b68(&iGpffffa7d0, D_0063E3D0, 0x417);
        task->unk_210 = func_00454a60(task->text + 0x100, 0);
        task->state = 1;
        break;
    case 1:
        if (func_004553c0(task->unk_210) != 0) {
            task->unk_224 = (s32)func_00455f70(task->text + 0x100, &out);
            task->state = 2;
            task->unk_218 = 0;
            task->unk_21C = 30.0f;
            task->unk_220 = 8.0f;
        }
        break;
    case 2:
        if (D_008C0256[0] & 0x1000) {
            f = task->unk_220;
            if (f >= 2.0f) {
                task->unk_220 = f - 1.0f;
            }
        }
        if (D_008C0256[0] & 0x4000) {
            f = task->unk_220;
            if (f < 30.0f) {
                task->unk_220 = f + 1.0f;
            }
        }
        if (D_008C0256[0] & 0x8000) {
            f = task->unk_21C;
            if (f >= 2.0f) {
                task->unk_21C = f - 1.0f;
            }
        }
        if (D_008C0256[0] & 0x2000) {
            f = task->unk_21C;
            if (f < 45.0f) {
                task->unk_21C = f + 1.0f;
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
        entry = (u8 *)task->unk_224;
        found = NULL;
        count = 0;
        if (entry != NULL) {
            u8 *q;
            s32 n;

            q = entry + 0x20;
            n = *(s32 *)(entry + 0x10);
            i = 0;
            while (i < n) {
                u8 *e;

                e = q + i * 16;
                if (*(s32 *)e == 0) {
                    found = entry + *(s32 *)(e + 0xC);
                    break;
                }
                i++;
            }
            if (found != NULL) {
                count = *(s32 *)(q + i * 16 + 8);
            }
        }
        if (task->unk_218 < 0) {
            task->unk_218 = 0;
        } else if (task->unk_218 >= count) {
            task->unk_218 = count - 1;
        }
        ptr = func_0029df30(entry, task->unk_218);
        func_00450050(*(s64 *)&task->unk_21C, &iGpffffa7d8, task->unk_218, ptr);
        v0 = D_0063E5E0[0];
        v0.a = (s32)(12.0f * task->unk_21C);
        v0.b = (s32)(12.0f * task->unk_220);
        flt = iGpffffa7cc;
        v1 = v0;
        func_0045d6e0(&flt, &v1, 0.0f, 1);
        break;
    case 3:
        task->unk_214 = func_0029d660((ScrHeader *)(void *)task->unk_224, task->unk_218);
        if (task->unk_214 == NULL) {
            func_0046d730(D_0063E3D0, 0x44C);
        }
        task->state = 4;
        task->flags |= 1;
        break;
    case 4:
        {
            s32 ret;

            ret = func_0029cb00((void *)task->unk_214);
            if (ret == 2) {
                task->flags &= ~1;
                return 1;
            }
            if (ret == 1) {
                break;
            }
            if (ret == 0) {
                func_0046d740(D_0063E520, D_0063E3D0, 0x457);
                task->flags &= ~1;
                return 1;
            }
        }
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/scrScriptProcess", func_0029e040);
#endif

/* Measured: all 608 bytes and 35 resolved relocations match retail.
 * Loop invariants hoist the slash constant. */
#pragma opt_loop_invariants on
// FUN_0029E550
s32 func_0029e550(u8 *arg0)
{
    ScrTaskData *task;
    ScrScriptWork *child;
    s32 ret;
    s32 n;
    s32 handle;

    task = *(ScrTaskData **)(arg0 + 0x38);
    switch (task->unk_0C) {
    case 0:
        func_00442088(task->text, &D_007638D0, D_0063E5F0,
                      scrAddOff(func_00442948(D_0063E5F0), (u8 *)task) + 0x10);
        n = func_00442948(task->text) - 1;
        while (n > 0) {
            if (task->text[n] == 0x2F) {
                func_0043f9c8(&task->text[n + 1], 0, n - 1);
                break;
            }
            n--;
        }
        task->unk_04 = func_00468170(arg0, task->text);
        task->unk_0C = 1;
        task->state = 0;
        break;
    case 1:
        ret = func_0029e040(arg0);
        switch (ret) {
        case 1:
            task->unk_0C = 3;
            break;
        case 2:
            child = task->unk_214;
            if (child != NULL) {
                func_00440b68(D_0063E548,
                              child->procedure + (child->index << 5));
                func_004504f0(D_0063E560,
                              child->procedure + (child->index << 5));
                func_0029d1c0(D_00764614, child->msgA);
                handle = child->soundHandle;
                if (handle >= 0) {
                    func_002777f0(handle);
                    func_00440b68(D_0063E580);
                }
                if (child->textBuf != NULL) {
                    func_0046a340(child->textBuf);
                    func_00440b68(D_0063E5A0);
                }
                func_0029d270(child);
                func_0029d1c0(D_00764610, child);
                task->unk_214 = 0;
            }
            handle = task->unk_210;
            if (handle != 0) {
                func_00454bd0(handle);
                task->unk_210 = 0;
            }
            func_00452080((KwlnTask*)task->unk_04);
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


// FUN_0029E7B0
void func_0029e7b0(u8* arg0)
{
    ScrTaskData* task;
    ScrScriptWork* work;
    s32 handle;

    task = *(ScrTaskData**)(arg0 + 0x38);
    work = task->unk_214;
    if (work != NULL)
    {
        func_00440b68(D_0063E548, (work->index << 5) + work->procedure);
        func_004504f0(D_0063E560, (work->index << 5) + work->procedure);
        func_0029d1c0(D_00764614, work->msgA);
        handle = work->soundHandle;
        if (handle >= 0)
        {
            func_002777f0(handle);
            func_00440b68(D_0063E580);
        }
        handle = (s32)work->textBuf;
        if (handle != 0)
        {
            func_0046a340((void*)handle);
            func_00440b68(D_0063E5A0);
        }
        func_0029d270(work);
        func_0029d1c0(D_00764610, (u8*)work);
        task->unk_214 = 0;
    }
    handle = task->unk_210;
    if (handle != 0)
    {
        func_00454bd0(handle);
        task->unk_210 = 0;
    }
    jtbl_008873EC[0](task);
}

// FUN_0029E8D0
void func_0029e8d0(u8* arg0)
{
    u8* buf;

    func_0044ea90(D_0063E3D0, 0x4AB);
    buf = D_008873F4[0](1, 0x228, 0x40000);
    (s32)func_00451fc0((void *)((s32)arg0), (const void *)(D_0063E618), 0xC9, 0, 0, func_0029e550, func_0029e7b0, (u8 *)(buf));
}
