/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "effect_mesh_internal.h"
#include "effect_after_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"

typedef struct RuntimeWork RuntimeWork;

typedef struct RuntimeListNode
{
    u32 flags;
    RuntimeWork* work;
    u8* vertices;
    u8* renderObjects;
    u8 *commands;
    u8 *entries;
    struct RuntimeListNode* previous;
    struct RuntimeListNode* next;
    u8 color[4]; /* +0x20: default per-instance color; allocation header is 0x24. */
} RuntimeListNode;

/* Relocation and instance allocation each reserve a 0x24-byte header. */

typedef struct AfPackCommand {
    u8 pad0[0x8];
    s32 start; /* +0x8 */
    u8 padC[0x4];
    s32 target; /* +0x10 */
} AfPackCommand;

typedef struct RuntimeWork {
    s32 flags; /* +0x0 */
    union { s16 signedHalf; u16 half; } sectionCount; /* +0x4 */
    u16 parameterCount; /* +0x6 */
    u16 materialCount; /* +0x8 */
    u8 padA[0x2];
    u8 * sections; /* +0xC */
    u8 * parameters; /* +0x10 */
    u8 * materials; /* +0x14 */
    u8 * timing; /* +0x18 */
    union { s32* signedWords; u8 * bytes; u8 ** byteTable; } commands; /* +0x1C */
    s32 owner; /* +0x20: compared by AfPackReleaseByOwner */
} RuntimeWork;

/* Disk headers are fixed prefixes; their command streams have variable length. */
typedef struct AfPackResourceHeader {
    s32 kind;
    s32 flags;
    u16 sectionCount;
    u16 parameterCount;
    u16 materialCount;
    u8 padE[2];
} AfPackResourceHeader;
typedef struct AfPackMaterialRecord {
    u16 id;
    u16 flags;
    u16 textureKind;
    u16 colorKind;
} AfPackMaterialRecord;
typedef struct AfPackSectionRecord {
    u16 id;
    u16 parameter;
    u16 material;
    u8 pad6[2];
    s32 start;
    s32 end;
    u16 capacity;
    u16 sectionCount;
} AfPackSectionRecord;
typedef struct AfPackSectionRecord64 {
    AfPackSectionRecord base;
    union { s32 signedValue; u32 value; } commandBytes;
} AfPackSectionRecord64;
typedef struct AfPackSectionRecord65 {
    AfPackSectionRecord base;
    u16 mode;
    u8 pad16[2];
    f32 width;
    union { s32 signedValue; u32 value; } commandBytes;
} AfPackSectionRecord65;
typedef struct AfPackTiming {
    s32 start;
    s32 end;
} AfPackTiming;

typedef struct AfPackRenderEntry {
    union { s32 value; u8 *pointer; } atomic;
    union { s32 value; u8 *pointer; struct RpMaterial *rpMaterial; } material;
} AfPackRenderEntry;

extern void* D_00764C98; /* render-list owner */
extern s32 D_00922DB0[];
extern s32 D_00922DB4[];
extern void PrimAppendNode(void* list, s32* node);
extern void* D_00764C9C; /* instance-list tail */
extern RuntimeListNode* D_00764CA0; /* instance-list head */
extern void effAfterResetCommand(void* command, void* resource);
extern void effAfterRunCommands(void* work, void* unused);
extern void func_00440b68(const void* msg, const void* file, s32 line);
extern u8* H_Cdvd_AcquireDirectory(u8* path, s32 flags);
extern void H_Cdvd_ReadSync(void* cdvd);
extern s32 func_003ef740(u8* param, s32 mode);
extern void H_Cdvd_Destroy(u8* cdvd);

extern void memset(void* dst, s32 value, u32 size);
extern u8 D_00764210;
extern s32 D_00764CA4;
extern s32 D_00764CA8; /* loaded pack texture */
extern u8 D_007146B0[];
extern u8 D_007146C0[];
extern u8 D_007146D0[];
extern void* D_00922DB8[];
extern s32 D_00922DC0[];
extern void AfPackRunList(void);
extern s32 AfPackTaskUpdate(u8 *unusedTask);
extern void kAssertFail(const void* file, s32 line);
extern void func_003e9390(void* frame);
extern void func_003c02e0(void* arg);
extern void func_003c4220(void* arg);
extern void effAfterFreeVectorBuffers(void* work);
extern void (*jtbl_008873EC[])(void* ptr);
extern void chkmemAllocSiteTag(const void* file, s32 line);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern void effAfterAllocVectorBuffers(void* work, void* config);
extern s32 func_003c4140(void);
extern void func_003c42b0(void* a, void* b);
struct RpMaterial;
extern u8* effAfterCreateRibbon(u8* work, struct RpMaterial* material);
extern s32 func_003c00e0(void);
extern void func_003c0210(void* a, void* b, s32 c);
extern s32 func_003e9320(void);
extern void RpAtomicSetFrame(void* a, void* b);
extern void func_003c2a80(void* a);
extern void effMiscProgressResetWork(void* a, void* b);
extern void func_003c22f0(void* a);

/* The allocation result lands in `base` first and is copied to `node`:
 * retail adds 0x24 to the $v0 result directly and keeps the cursor out of
 * the saved register that holds the node. measured: opt_loop_invariants
 * and opt_lifetimes on are both required (verify MISMATCH, nd 116,
 * without them). */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// Binds the sections of the packed afterimage resource at resource: walks the header counts and records each table's pointer; the per-record size depends on the header's type word (0x64 or 0x65).
// FUN_004B6030
u8 *AfPackBindResource(void *resource)
{
    /* Earlier whole-layout comparison: 1833 differing bytes; remaining raw sites are isolated below. */
    extern void memcpy(void *dst, void *src, u32 size);
    u8 *parameterRecords[16];
    u8 *materialRecords[16];
    u8 *materialColors[16];
    u8 *sectionRecords[16];
    u8 *commandStreams[16];
    u8 *node;
    s32 sizeIndex;
    s32 parameterIndex;
    s32 commandIndex;
    s32 recordIndex;
    u8 *base;
    u8 *header;
    s32 materialIndex;
    s32 copyParameterIndex;
    s32 size;
    s32 sectionIndex;
    u8 *p;

    p = resource;
    header = p;
    p += 0x10;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    for (parameterIndex = 0; parameterIndex < *(u16 *)(header + 0xA); parameterIndex++) {
        parameterRecords[parameterIndex] = p;
        p += 0x38;
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    for (recordIndex = 0; recordIndex < *(u16 *)(header + 0xC); recordIndex++) {
        u8 *cur;

        materialRecords[recordIndex] = p;
        p += 8;
        cur = materialRecords[recordIndex];
        switch (((AfPackMaterialRecord *)cur)->textureKind) {
        case 0:
            p += 4;
            break;
        default:
            kAssertFail(D_007146B0, 0x1AE);
            break;
        }
        materialColors[(u32)recordIndex] = p;
        switch (((AfPackMaterialRecord *)cur)->colorKind) {
        case 0:
            p += 0x10;
            break;
        default:
            kAssertFail(D_007146B0, 0x1BA);
            break;
        }
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    for (recordIndex = 0; recordIndex < *(u16 *)(header + 8); recordIndex++) {
        sectionRecords[recordIndex] = p;
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            p += 0x18;
            break;
        case 0x65:
            p += 0x20;
            break;
        default:
            kAssertFail(D_007146B0, 0x1C8);
            break;
        }
        commandStreams[recordIndex] = p;
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            p += ((AfPackSectionRecord64 *)sectionRecords[recordIndex])->commandBytes.signedValue;
            break;
        case 0x65:
            p += ((AfPackSectionRecord65 *)sectionRecords[recordIndex])->commandBytes.signedValue;
            break;
        }
    }
    size = 0;
    size = size + 0x24;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    size = size + *(u16 *)(header + 8) * 0x18;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    size = size + *(u16 *)(header + 0xA) * 0x34;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    size = size + *(u16 *)(header + 0xC) * 0x18;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    size = size + *(u16 *)(header + 8) * 4;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    for (sizeIndex = 0; sizeIndex < *(u16 *)(header + 8); sizeIndex++) {
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            size += ((AfPackSectionRecord64 *)sectionRecords[sizeIndex])->commandBytes.signedValue;
            break;
        case 0x65:
            size += ((AfPackSectionRecord65 *)sectionRecords[sizeIndex])->commandBytes.signedValue;
            break;
        }
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    size += *(u16 *)(header + 8) * 8;
    chkmemAllocSiteTag(D_007146B0, 0x1E4);
    base = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    node = base;
    base = base + 0x24;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    *(u8 **)(node + 0xC) = base;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    base += *(u16 *)(header + 8) * 0x18;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    *(u8 **)(node + 0x10) = base;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    base += *(u16 *)(header + 0xA) * 0x34;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    *(u8 **)(node + 0x14) = base;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    base += *(u16 *)(header + 0xC) * 0x18;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    *(u8 **)(node + 0x1C) = base;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    base += *(u16 *)(header + 8) * 4;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    for (commandIndex = 0; commandIndex < *(u16 *)(header + 8); commandIndex++) {
        (((RuntimeWork *)node)->commands.byteTable)[commandIndex] = base;
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            base += ((AfPackSectionRecord64 *)sectionRecords[commandIndex])->commandBytes.signedValue;
            break;
        case 0x65:
            base += ((AfPackSectionRecord65 *)sectionRecords[commandIndex])->commandBytes.signedValue;
            break;
        }
    }
    ((RuntimeWork *)node)->timing = base;
    ((RuntimeWork *)node)->flags = ((AfPackResourceHeader *)header)->flags;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    ((RuntimeWork *)node)->sectionCount.half = *(u16 *)(header + 8);
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    ((RuntimeWork *)node)->parameterCount = *(u16 *)(header + 0xA);
    ((RuntimeWork *)node)->materialCount = ((AfPackResourceHeader *)header)->materialCount;
    for (copyParameterIndex = 0; copyParameterIndex < ((AfPackResourceHeader *)header)->parameterCount; copyParameterIndex++) {
        f32 *dst = (f32 *)(((RuntimeWork *)node)->parameters + copyParameterIndex * 0x34);
        f32 *src = (f32 *)parameterRecords[copyParameterIndex];

        dst[0] = src[1];
        dst[1] = src[2];
        dst[2] = src[3];
        dst[3] = src[4];
        dst[4] = src[5];
        dst[5] = src[6];
        dst[6] = src[7];
        dst[7] = src[8];
        dst[9] = src[9];
        dst[8] = src[10];
        dst[10] = src[11];
        dst[11] = src[12];
        dst[12] = src[13];
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    for (materialIndex = 0; materialIndex < *(u16 *)(header + 0xC); materialIndex++) {
        u8 *dst = ((RuntimeWork *)node)->materials + materialIndex * 0x18;
        u8 *src = materialRecords[materialIndex];
        u8 *colors = materialColors[materialIndex];
        u16 id = ((AfPackMaterialRecord *)src)->flags;

        ((EffAfterMaterial *)dst)->flags = id;
        if ((id & 1) != 0) {
            ((EffAfterMaterial *)dst)->texture = D_00764CA8;
        } else {
            ((EffAfterMaterial *)dst)->texture = 0;
        }
        switch (((AfPackMaterialRecord *)src)->colorKind) {
        case 0: {
            s32 k;

            for (k = 0; k < 4; k++) {
                u8 *s = colors + k * 4;
                u8 *d = dst + (k >> 1) * 8 + (k & 1) * 4;

                d[8] = s[0];
                d[9] = s[1];
                d[10] = s[2];
                d[11] = s[3];
            }
            break;
        }
        default:
            kAssertFail(D_007146B0, 0x22E);
            break;
        }
    }
    for (sectionIndex = 0; sectionIndex < ((AfPackResourceHeader *)header)->sectionCount; sectionIndex++) {
        u8 *dst = ((RuntimeWork *)node)->sections + sectionIndex * 0x18;
        u8 *src = sectionRecords[sectionIndex];
        u32 id;
        s32 j;
        s32 n;

        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            id = ((AfPackSectionRecord *)src)->parameter;
            break;
        case 0x65:
            id = ((AfPackSectionRecord *)src)->parameter;
            break;
        }
        j = 0;
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        n = *(u16 *)(header + 0xA);
        for (; j < n; j++) {
            if (id == *(u16 *)parameterRecords[j]) {
                break;
            }
        }
        ((EffAfterConfig *)dst)->param = (EffAfterParam *)(((RuntimeWork *)node)->parameters + j * 0x34);
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            id = ((AfPackSectionRecord *)src)->material;
            break;
        case 0x65:
            id = ((AfPackSectionRecord *)src)->material;
            break;
        }
        j = 0;
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        n = *(u16 *)(header + 0xC);
        for (; j < n; j++) {
            if (id == *(u16 *)materialRecords[j]) {
                break;
            }
        }
        ((EffAfterConfig *)dst)->material = ((RuntimeWork *)node)->materials + j * 0x18;
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            ((EffAfterConfig *)dst)->capacity = ((AfPackSectionRecord *)src)->capacity;
            break;
        case 0x65:
            ((EffAfterConfig *)dst)->capacity = ((AfPackSectionRecord *)src)->capacity;
            break;
        }
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            ((EffAfterConfig *)dst)->sectionCount = ((AfPackSectionRecord *)src)->sectionCount;
            break;
        case 0x65:
            ((EffAfterConfig *)dst)->sectionCount = ((AfPackSectionRecord *)src)->sectionCount;
            break;
        }
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            ((EffAfterConfig *)dst)->mode = 0;
            break;
        case 0x65:
            ((EffAfterConfig *)dst)->mode = ((AfPackSectionRecord65 *)src)->mode;
            break;
        }
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            ((EffAfterConfig *)dst)->width = 10.0f;
            break;
        case 0x65:
            ((EffAfterConfig *)dst)->width = ((AfPackSectionRecord65 *)src)->width;
            break;
        }
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            ((AfPackTiming *)((RuntimeWork *)node)->timing)[sectionIndex].start = ((AfPackSectionRecord *)src)->start;
            ((AfPackTiming *)((RuntimeWork *)node)->timing)[sectionIndex].end = ((AfPackSectionRecord *)src)->end;
            break;
        case 0x65:
            ((AfPackTiming *)((RuntimeWork *)node)->timing)[sectionIndex].start = ((AfPackSectionRecord *)src)->start;
            ((AfPackTiming *)((RuntimeWork *)node)->timing)[sectionIndex].end = ((AfPackSectionRecord *)src)->end;
            break;
        }
        switch (((AfPackResourceHeader *)header)->kind) {
        case 0x64:
            memcpy((((RuntimeWork *)node)->commands.byteTable)[sectionIndex], commandStreams[sectionIndex], ((AfPackSectionRecord64 *)src)->commandBytes.value);
            break;
        case 0x65:
            memcpy((((RuntimeWork *)node)->commands.byteTable)[sectionIndex], commandStreams[sectionIndex], ((AfPackSectionRecord65 *)src)->commandBytes.value);
            break;
        }
    }
    return node;
}
#pragma pop
// Creates the afterimage instance for a pack: allocates the node with its vector, material and ribbon tables, then per section builds the vector buffers, the ribbon geometry (effAfterCreateRibbon) and the atomic and texture bindings.
// FUN_004B6900
u8* AfPackCreateInstance(u8* resource)
{
    u8* node;
    u8* base;
    u8* temp;
    s32 i;
    s32 size;
    typedef struct
    {
        u8 c[4];
    } Color4;
    Color4 color;
    RuntimeWork *pack;
    RuntimeListNode *instance;

    pack = (RuntimeWork *)resource;
    size = 0;
    size += 0x24;
    size += ((RuntimeWork *)resource)->sectionCount.signedHalf * 0x3C;
    size += ((RuntimeWork *)resource)->sectionCount.signedHalf * 8;
    size += ((RuntimeWork *)resource)->sectionCount.signedHalf * 0x20;
    size += ((RuntimeWork *)resource)->sectionCount.signedHalf * 0x18;
    chkmemAllocSiteTag(D_007146B0, 0x287);
    node = (u8*)(*jtbl_008873E8)(size, 0x40000);
    instance = (RuntimeListNode *)node;
    base = node + 0x24;
    ((RuntimeListNode *)node)->vertices = base;
    base += pack->sectionCount.signedHalf * 0x3C;
    ((RuntimeListNode *)node)->renderObjects = base;
    base += pack->sectionCount.signedHalf * 8;
    ((RuntimeListNode *)node)->commands = base;
    base += pack->sectionCount.signedHalf * 0x20;
    ((RuntimeListNode *)node)->entries = base;
    ((RuntimeListNode *)node)->flags = 0;
    ((RuntimeListNode *)node)->work = (RuntimeWork *)(resource);
    node[0x20] = 0xFF;
    node[0x21] = 0xFF;
    node[0x22] = 0xFF;
    node[0x23] = 0xFE;

    i = 0;
    if (pack->sectionCount.signedHalf > 0)
    {
        color.c[0] = 0xFF;
        color.c[1] = 0xFF;
        color.c[2] = 0xFF;
        color.c[3] = 0xFE;
        while (i < pack->sectionCount.signedHalf)
        {
            effAfterAllocVectorBuffers(instance->vertices + i * 0x3C,
                          ((RuntimeWork *)resource)->sections + i * 0x18);
            ((AfPackRenderEntry *)(instance->renderObjects + i*8))->material.value = func_003c4140();
            {
                u8* obj;
                u8* material;
                obj = (u8 *)((EffAfterQueue *)instance->vertices)[i].config;
                material = ((EffAfterConfig *)obj)->material;
                if ((((EffAfterMaterial *)material)->flags & 1) != 0)
                {
                    func_003c42b0(((AfPackRenderEntry *)(instance->renderObjects + i*8))->material.pointer,
                                  (u8 *)((EffAfterMaterial *)material)->texture);
                }
            }
            *(Color4 *)&((RpMaterial *)(((AfPackRenderEntry *)instance->renderObjects)[i].material.pointer))->color = color;
            temp = effAfterCreateRibbon(instance->vertices + i * 0x3C,
                                 ((AfPackRenderEntry *)(instance->renderObjects + i*8))->material.rpMaterial);
            ((AfPackRenderEntry *)(instance->renderObjects + i*8))->atomic.value = func_003c00e0();
            func_003c0210(((AfPackRenderEntry *)(instance->renderObjects + i*8))->atomic.pointer, temp, 0);
            RpAtomicSetFrame(((AfPackRenderEntry *)(instance->renderObjects + i*8))->atomic.pointer,
                          (void*)func_003e9320());
            func_003c2a80(temp);
            effMiscProgressResetWork(instance->vertices + i * 0x3C, temp);
            func_003c22f0(temp);
            i++;
        }
    }
    return node;
}

// Resets each section's command state from the pack's section config, sets the node's flag bit 0, then runs each section's command stream.
// FUN_004B6BB0
void AfPackStartSections(RuntimeListNode* node)
{
    s32 i;
    s32 commandResult;
    s32 off;
    u8* work;
    u8* out;

    i = 0;
    while (i < node->work->sectionCount.signedHalf)
    {
        work = (u8*)node->work;
        out = (u8 *)node->commands + i * 0x20;
        ((AfPackCommand *)out)->start = ((RuntimeWork *)work)->commands.signedWords[i];
        off = i * 0x3C;
        ((AfPackCommand *)out)->target = (s32)((u8*)node->vertices + off);
        effAfterResetCommand(out, work);
        i++;
    }
    node->flags |= 1;
    i = 0;
    while (i < node->work->sectionCount.signedHalf)
    {
        effAfterRunCommands((u8 *)node->commands + i * 0x20, &commandResult);
        i++;
    }
}

// Loads the afterimage pack synchronously, creates its update task at taskPriority, and registers drawList for rendering.
// FUN_004B6C90
void AfPackInit(s32 drawList, s32 taskPriority)
{
    s32 directoryHandle;

    func_00440b68(&D_00764210, D_007146B0, 0x2DA);
    directoryHandle = (s32)H_Cdvd_AcquireDirectory(D_007146C0, 0);
    H_Cdvd_ReadSync((void*)directoryHandle);
    D_00764CA8 = (s32)func_003ef740(D_007146C0, 0);
    H_Cdvd_Destroy((u8*)directoryHandle);
    D_00764CA0 = NULL;
    D_00764C9C = NULL;
    D_00764CA4 = (s32)kwlnTaskCreate((const void *)(D_007146D0), taskPriority, 0, 0, AfPackTaskUpdate, 0, (u8 *)(NULL));
    memset(D_00922DB0, 0, 0x30);
    D_00922DB8[0] = (void*)AfPackRunList;
    D_00922DC0[0] = 0;
    D_00764C98 = (void*)drawList;
}

// Returns 1 when node is on the afterimage list and its flag bit 0x8 is clear, otherwise 0.
// FUN_004B6DE0
s32 AfPackIsActive(RuntimeListNode* node)
{
    RuntimeListNode* current;

    current = D_00764CA0;
    while (current != NULL)
    {
        if (current == node)
        {
            break;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        return 0;
    }
    return !(node->flags & 8);
}

// Appends a node to the tail of the afterimage list; an empty list makes it both head and tail.
// FUN_004B6DA0
void AfPackListAppend(void* node)
{
    if (D_00764C9C == NULL)
    {
        ((RuntimeListNode *)node)->previous = NULL;
        ((RuntimeListNode *)node)->next = NULL;
        D_00764CA0 = (RuntimeListNode*)node;
        D_00764C9C = node;
        return;
    }
    else
    {
        ((RuntimeListNode *)node)->previous = D_00764C9C;
        ((RuntimeListNode *)node)->next = NULL;
        ((RuntimeListNode *)D_00764C9C)->next = node;
    }
    D_00764C9C = node;
}
// Task callback: clears two words of the update state and runs PrimAppendNode on the pack registered in D_00764C98.
// FUN_004B6E40
s32 AfPackTaskUpdate(u8 *unusedTask)
{
    D_00922DB0[0] = 0;
    D_00922DB4[0] = 0;
    PrimAppendNode(D_00764C98, D_00922DB0);
    return 0;
}

// Runs the afterimage list once per frame: updates the render entries, reaps nodes with no live entries (freeing their buffers), then draws the remaining entries.
// FUN_004B6E80
void AfPackRunList(void) {
    /* Earlier whole-layout comparison: 483 differing bytes; remaining raw sites are isolated below. */
    typedef int (*code)();
    extern code DAT_008873ec_abs[];
    void *(**table);
    extern void Vpad_UpdateRenderEntries(void *workData);
    extern void Vpad_DrawEntries(void *work);
    extern s32 Vpad_HasEntries(void *workData);
    s32 flags;
    u8 *first;
    u8 *prev;
    u8 *next;
    s32 off;
    u8 *temp;
    s32 bits;
    u8 *work;
    s32 i;
    u8 *node;

    first = (u8 *)D_00764CA0;
    if (first != NULL) {
        while (first != NULL) {
            flags = (s32)((RuntimeListNode *)first)->flags;
            if (flags & 8) {
                Vpad_UpdateRenderEntries(first);
            } else if (flags & 2) {
                Vpad_UpdateRenderEntries(first);
                ((RuntimeListNode *)first)->flags = (s32)((RuntimeListNode *)first)->flags & ~2;
            }
            first = (u8 *)((RuntimeListNode *)first)->next;
        }
        node = (u8 *)D_00764CA0;
        while (node != NULL) {
            temp = node;
            node = (u8 *)((RuntimeListNode *)node)->next;
            bits = 0;
            i = 0;
            while (i < ((RuntimeListNode *)temp)->work->sectionCount.signedHalf) {
                bits |= Vpad_HasEntries(((RuntimeListNode *)temp)->commands + (i << 5));
                i++;
            }
            if (bits == 0) {
                if (D_00764CA0 == NULL) {
                    kAssertFail(D_007146B0, 0x326);
                }
                if (D_00764C9C == NULL) {
                    kAssertFail(D_007146B0, 0x327);
                }
                next = (u8 *)((RuntimeListNode *)temp)->next;
                if (next != NULL) {
                    ((RuntimeListNode *)next)->previous = (RuntimeListNode *)((u8 *)((RuntimeListNode *)temp)->previous);
                }
                prev = (u8 *)((RuntimeListNode *)temp)->previous;
                if (prev != NULL) {
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    ((RuntimeListNode *)prev)->next = (RuntimeListNode *)(*(u8 **)(temp + 0x1C));
                }
                if (temp == (u8 *)D_00764C9C) {
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    D_00764C9C = *(u8 **)(temp + 0x18);
                }
                if (temp == (u8 *)D_00764CA0) {
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    D_00764CA0 = (RuntimeListNode *)*(u8 **)(temp + 0x1C);
                }
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                work = *(u8 **)(temp + 4);
                i = 0;
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                while (i < ((RuntimeWork *)*(u8 **)(temp + 4))->sectionCount.signedHalf) {
                    effAfterFreeVectorBuffers(((RuntimeListNode *)temp)->vertices + i * 0x3C);
                    off = i * 8;
                    func_003e9390((u8 *)((RpAtomic *)(((AfPackRenderEntry *)(((RuntimeListNode *)temp)->renderObjects + off))->atomic.pointer))->frame);
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    func_003c02e0(((AfPackRenderEntry *)(*(u8 **)(temp + 0xC) + off))->atomic.pointer);
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    func_003c4220(((AfPackRenderEntry *)(*(u8 **)(temp + 0xC) + off))->material.pointer);
                    i++;
                }
                table = (void *(**) )DAT_008873ec_abs;
                ((code)table[0])(temp);
                ((code)table[0])(work);
            }
        }
        first = (u8 *)D_00764CA0;
        while (first != NULL) {
            flags = (s32)((RuntimeListNode *)first)->flags;
            if (flags & 8) {
                Vpad_DrawEntries(first);
            } else if (flags & 4) {
                Vpad_DrawEntries(first);
                ((RuntimeListNode *)first)->flags = (s32)((RuntimeListNode *)first)->flags & ~4;
            }
            first = (u8 *)((RuntimeListNode *)first)->next;
        }
    }
}

// Releases every afterimage instance whose pack's word at +0x20 equals owner: unlinks it, frees its vector buffers and sections, and frees the node and its pack.
// FUN_004B7140
void AfPackReleaseByOwner(s32 owner)
{
    /* Earlier whole-layout comparison: 303 differing bytes; remaining raw sites are isolated below. */
    s32 renderOffset;
    u8* nextNode;
    u8* node;
    u8* resource;
    u8* next;
    u8* previous;
    s32 sectionIndex;
    u32 base;

    nextNode = (u8*)D_00764CA0;
    while (nextNode != NULL)
    {
        node = nextNode;
        nextNode = (u8 *)((RuntimeListNode *)nextNode)->next;
        if (((RuntimeListNode *)node)->work->owner == owner)
        {
            if (D_00764CA0 == NULL)
            {
                kAssertFail(D_007146B0, 0x326);
            }
            if (D_00764C9C == NULL)
            {
                kAssertFail(D_007146B0, 0x327);
            }
            next = (u8 *)((RuntimeListNode *)node)->next;
            if (next != NULL)
            {
                ((RuntimeListNode *)next)->previous = (RuntimeListNode *)((u8 *)((RuntimeListNode *)node)->previous);
            }
            previous = (u8 *)((RuntimeListNode *)node)->previous;
            if (previous != NULL)
            {
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                ((RuntimeListNode *)previous)->next = (RuntimeListNode *)(*(u8**)(node + 0x1C));
            }
            if (node == (u8*)D_00764C9C)
            {
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                D_00764C9C = *(void**)(node + 0x18);
            }
            if (node == (u8*)D_00764CA0)
            {
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                D_00764CA0 = *(RuntimeListNode**)(node + 0x1C);
            }
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            resource = *(u8**)(node + 4);
            sectionIndex = 0;
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            while (sectionIndex < ((RuntimeWork *)*(u8 **)(node + 4))->sectionCount.signedHalf)
            {
                effAfterFreeVectorBuffers(((RuntimeListNode *)node)->vertices + sectionIndex * 0x3C);
                renderOffset = sectionIndex * 8;
                func_003e9390(((RpAtomic *)(((AfPackRenderEntry *)(((RuntimeListNode *)node)->renderObjects + renderOffset))->atomic.pointer))->frame);
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                func_003c02e0(((AfPackRenderEntry *)(*(u8 **)(node + 0xC) + renderOffset))->atomic.pointer);
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                func_003c4220(((AfPackRenderEntry *)(*(u8 **)(node + 0xC) + renderOffset))->material.pointer);
                sectionIndex++;
            }
            base = (u32)jtbl_008873EC;
            ((void (*)(void*))*(u32*)base)(node);
            ((void (*)(void*))*(u32*)base)(resource);
        }
    }
}

