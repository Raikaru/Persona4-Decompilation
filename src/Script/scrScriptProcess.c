/* Source unit: src/Script/scrScriptProcess_0029d900.c */
#include "type.h"
#include "include_asm.h"


typedef struct KwlnTask KwlnTask;
typedef struct ScrData ScrData;

void* dds3GetProcessWorkData(KwlnTask* task);
void dds3SetProcessWorkData(KwlnTask* task, void* workData);
void scrReleaseScript(ScrData* scr);
void scrDestroyTask(KwlnTask* scrTask);
extern s32 func_0029d870(void);
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
    s32 unk_04;       // 0x04
    s32 state;        // 0x08
    s32 unk_0C;       // 0x0C
    char text[0x200]; // 0x10
    s32 unk_210;      // 0x210
    s32 unk_214;      // 0x214
    s32 unk_218;      // 0x218
    f32 unk_21C;      // 0x21C
    f32 unk_220;      // 0x220
    s32 unk_224;      // 0x224
} ScrTaskData;

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
extern char D_0063E5E0[];
extern char D_0063E5F0[];
extern char D_0063E600[];
extern char D_0063E618[];
extern u8* D_008873F4[]; // Allocator slot.
extern void* jtbl_008873EC[];
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u16 D_008C0256[];

void func_0044ea90(char* file, s32 line);
void func_0046d730(char* file, s32 line);
void func_0046d740(char* msg, char* file, s32 line, ...);
void func_0046d700(char* file, s32 line, char* msg, s32 value);
void func_0043f9c8(void* dst, s32 value, s32 size);
void func_0043f810(void* dst, void* src, s32 size);
void func_0046a2d0(char* file, s32 line);
u8* func_0046a430(s32 size);
void func_0046a340(void* ptr);
void* func_00452560(void);
s32 func_0029cb00(void* arg0, ...);
s32 func_0029e970(void);
void func_0029e960(s32 arg0);
void func_00440b68(char* fmt, ...);
void func_004504f0(char* fmt, ...);
void func_002777f0(s32 handle);
s32 func_002774d0(u8* str);
void func_00278640(s32 handle, s32 arg1, s32 arg2);
void func_00452080(s32 handle);
void func_00454bd0(s32 handle);
s32 func_00468170(void* arg0, void* arg1);
void func_00442088(void* arg0, void* arg1, void* arg2, void* arg3);
u32 func_00442948(void* arg0);
s32 func_00451de0(void* data, s32 a, s32 b, s32 c, void* init, void* close, void* buf);
s32 func_00451fc0(s32 arg0, char* arg1, s32 arg2, s32 arg3, s32 arg4, void (*init)(u8*), void (*close)(u8*), u8* arg7);
/* Still an INCLUDE_ASM fallback below, so it has no C definition to declare it;
 * its address is taken at line 720. */
extern void func_0029e550(u8* arg0);
s32 func_004553c0(s32 arg0, s32 arg1);
s32 func_00454a60(void* arg0, s32 arg1);
s32 func_004680f0(s32 arg0, void* arg1);
void func_00442830(void* arg0, void* arg1);
u8* func_00455f70(void* arg0, void* arg1);
void func_00450050(s64 arg0, char* arg1, s32 arg2, void* arg3);
void func_0045d6e0(void* arg0, void* arg1, s32 arg2, f32 arg3);




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

// FUN_0029D1C0
INCLUDE_ASM("asm/nonmatchings/scrScriptProcess", func_0029d1c0);

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
            func_0046d740(D_0063E4F0, D_0063E3D0, 0x19E, 2, 3, 4, currEntry);
            return NULL;
        }
    }
    work = func_0029d2f0((ScrHeader*)header, entries, (u8*)prcd, (u8*)labels, instr, msgs, strings, index);
    return work;
}
/* measured: see annotation above (func_0029d660). */
#pragma opt_loop_invariants off

// FUN_0029D870
s32 func_0029d870(void)
{
    s32 code;

    code = func_0029cb00(func_00452560());
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
void scrDestroyTask(KwlnTask* scrTask)
{
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
    task = func_00451de0((work->index << 5) + work->procedure, arg0, 1, 1, (void*)&func_0029d870, (void*)&scrDestroyTask, work);
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
    task = func_00451de0((work->index << 5) + work->procedure, arg0, 1, 1, (void*)&func_0029d870, (void*)&scrDestroyTask, work);
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
    task = func_00451de0((work->index << 5) + work->procedure, arg0, 1, 1, (void*)&func_0029d870, (void*)&scrDestroyTask, work);
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

    work = (ScrScriptWork*)func_00452560();
    if (work == NULL)
    {
        func_0046d730(D_0063E3D0, 0x3C5);
    }
    work->proc = proc;
}

// FUN_0029E040
INCLUDE_ASM("asm/nonmatchings/scrScriptProcess", func_0029e040);

// FUN_0029E550
INCLUDE_ASM("asm/nonmatchings/scrScriptProcess", func_0029e550);

// FUN_0029E7B0
void func_0029e7b0(u8* arg0)
{
    ScrTaskData* task;
    ScrScriptWork* work;
    s32 handle;

    task = *(ScrTaskData**)(arg0 + 0x38);
    work = (ScrScriptWork*)task->unk_214;
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
    ((void (*)(void*))jtbl_008873EC[0])(task);
}

// FUN_0029E8D0
void func_0029e8d0(u8* arg0)
{
    u8* buf;

    func_0044ea90(D_0063E3D0, 0x4AB);
    buf = ((u8* (*)(s32, s32, s32))D_008873F4[0])(1, 0x228, 0x40000);
    func_00451fc0((s32)arg0, D_0063E618, 0xC9, 0, 0, (void (*)(u8*))func_0029e550, (void (*)(u8*))func_0029e7b0, buf);
}
