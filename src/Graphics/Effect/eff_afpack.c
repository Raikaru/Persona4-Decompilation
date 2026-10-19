/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"

typedef struct RuntimeWork RuntimeWork;

typedef struct RuntimeListNode
{
    u32 flags;
    RuntimeWork* work;
    void* vertices;
    void* renderObjects;
    void *commands;
    void *entries;
    struct RuntimeListNode* previous;
    struct RuntimeListNode* next;
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
} RuntimeWork;

extern void* D_00764C98; /* render-list owner */
extern s32 D_00922DB0[];
extern s32 D_00922DB4[];
extern void PrimAppendNode(void* drawList, s32* node);
extern void* D_00764C9C; /* instance-list tail */
extern RuntimeListNode* D_00764CA0; /* instance-list head */
extern void effAfterResetCommand(void* command, void* resource);
extern void effAfterRunCommands(void* command, void* result);
extern void func_00440b68(const void* msg, const void* file, s32 line);
extern u8* H_Cdvd_AcquireDirectory(u8* param, s32 mode);
extern void H_Cdvd_ReadSync(void* handle);
extern s32 func_003ef740(u8* param, s32 mode);
extern void H_Cdvd_Destroy(u8* ptr);

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
extern s32 AfPackTaskUpdate(u8 *task);
extern void kAssertFail(const void* file, s32 line);
extern void func_003e9390(void* frame);
extern void func_003c02e0(void* arg);
extern void func_003c4220(void* arg);
extern void effAfterFreeVectorBuffers(void* source);
extern void (*jtbl_008873EC[])(void* ptr);
extern void chkmemAllocSiteTag(const void* file, s32 line);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern void effAfterAllocVectorBuffers(void* source, void* taskPriority);
extern s32 func_003c4140(void);
extern void func_003c42b0(void* a, void* b);
struct RpMaterial;
extern u8* effAfterCreateRibbon(u8* a, struct RpMaterial* material);
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
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 1833 differing bytes). Offsets remain as observed. */
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
    for (parameterIndex = 0; parameterIndex < *(u16 *)(header + 0xA); parameterIndex++) {
        parameterRecords[parameterIndex] = p;
        p += 0x38;
    }
    for (recordIndex = 0; recordIndex < *(u16 *)(header + 0xC); recordIndex++) {
        u8 *cur;

        materialRecords[recordIndex] = p;
        p += 8;
        cur = materialRecords[recordIndex];
        switch (*(u16 *)(cur + 4)) {
        case 0:
            p += 4;
            break;
        default:
            kAssertFail(D_007146B0, 0x1AE);
            break;
        }
        materialColors[(u32)recordIndex] = p;
        switch (*(u16 *)(cur + 6)) {
        case 0:
            p += 0x10;
            break;
        default:
            kAssertFail(D_007146B0, 0x1BA);
            break;
        }
    }
    for (recordIndex = 0; recordIndex < *(u16 *)(header + 8); recordIndex++) {
        sectionRecords[recordIndex] = p;
        switch (*(s32 *)header) {
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
        switch (*(s32 *)header) {
        case 0x64:
            p += *(s32 *)(sectionRecords[recordIndex] + 0x14);
            break;
        case 0x65:
            p += *(s32 *)(sectionRecords[recordIndex] + 0x1C);
            break;
        }
    }
    size = 0;
    size = size + 0x24;
    size = size + *(u16 *)(header + 8) * 0x18;
    size = size + *(u16 *)(header + 0xA) * 0x34;
    size = size + *(u16 *)(header + 0xC) * 0x18;
    size = size + *(u16 *)(header + 8) * 4;
    for (sizeIndex = 0; sizeIndex < *(u16 *)(header + 8); sizeIndex++) {
        switch (*(s32 *)header) {
        case 0x64:
            size += *(s32 *)(sectionRecords[sizeIndex] + 0x14);
            break;
        case 0x65:
            size += *(s32 *)(sectionRecords[sizeIndex] + 0x1C);
            break;
        }
    }
    size += *(u16 *)(header + 8) * 8;
    chkmemAllocSiteTag(D_007146B0, 0x1E4);
    base = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    node = base;
    base = base + 0x24;
    *(u8 **)(node + 0xC) = base;
    base += *(u16 *)(header + 8) * 0x18;
    *(u8 **)(node + 0x10) = base;
    base += *(u16 *)(header + 0xA) * 0x34;
    *(u8 **)(node + 0x14) = base;
    base += *(u16 *)(header + 0xC) * 0x18;
    *(u8 **)(node + 0x1C) = base;
    base += *(u16 *)(header + 8) * 4;
    for (commandIndex = 0; commandIndex < *(u16 *)(header + 8); commandIndex++) {
        (*(u8 ***)(node + 0x1C))[commandIndex] = base;
        switch (*(s32 *)header) {
        case 0x64:
            base += *(s32 *)(sectionRecords[commandIndex] + 0x14);
            break;
        case 0x65:
            base += *(s32 *)(sectionRecords[commandIndex] + 0x1C);
            break;
        }
    }
    *(u8 **)(node + 0x18) = base;
    *(s32 *)(node + 0) = *(s32 *)(header + 4);
    *(u16 *)(node + 4) = *(u16 *)(header + 8);
    *(u16 *)(node + 6) = *(u16 *)(header + 0xA);
    *(u16 *)(node + 8) = *(u16 *)(header + 0xC);
    for (copyParameterIndex = 0; copyParameterIndex < *(u16 *)(header + 0xA); copyParameterIndex++) {
        f32 *dst = (f32 *)(*(u8 **)(node + 0x10) + copyParameterIndex * 0x34);
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
    for (materialIndex = 0; materialIndex < *(u16 *)(header + 0xC); materialIndex++) {
        u8 *dst = *(u8 **)(node + 0x14) + materialIndex * 0x18;
        u8 *src = materialRecords[materialIndex];
        u8 *colors = materialColors[materialIndex];
        u16 id = *(u16 *)(src + 2);

        *(s32 *)dst = id;
        if ((id & 1) != 0) {
            *(s32 *)(dst + 4) = D_00764CA8;
        } else {
            *(s32 *)(dst + 4) = 0;
        }
        switch (*(u16 *)(src + 6)) {
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
    for (sectionIndex = 0; sectionIndex < *(u16 *)(header + 8); sectionIndex++) {
        u8 *dst = *(u8 **)(node + 0xC) + sectionIndex * 0x18;
        u8 *src = sectionRecords[sectionIndex];
        u32 id;
        s32 j;
        s32 n;

        switch (*(s32 *)header) {
        case 0x64:
            id = *(u16 *)(src + 2);
            break;
        case 0x65:
            id = *(u16 *)(src + 2);
            break;
        }
        j = 0;
        n = *(u16 *)(header + 0xA);
        for (; j < n; j++) {
            if (id == *(u16 *)parameterRecords[j]) {
                break;
            }
        }
        *(u8 **)dst = *(u8 **)(node + 0x10) + j * 0x34;
        switch (*(s32 *)header) {
        case 0x64:
            id = *(u16 *)(src + 4);
            break;
        case 0x65:
            id = *(u16 *)(src + 4);
            break;
        }
        j = 0;
        n = *(u16 *)(header + 0xC);
        for (; j < n; j++) {
            if (id == *(u16 *)materialRecords[j]) {
                break;
            }
        }
        *(u8 **)(dst + 4) = *(u8 **)(node + 0x14) + j * 0x18;
        switch (*(s32 *)header) {
        case 0x64:
            *(s32 *)(dst + 8) = *(u16 *)(src + 0x10);
            break;
        case 0x65:
            *(s32 *)(dst + 8) = *(u16 *)(src + 0x10);
            break;
        }
        switch (*(s32 *)header) {
        case 0x64:
            *(s32 *)(dst + 0xC) = *(u16 *)(src + 0x12);
            break;
        case 0x65:
            *(s32 *)(dst + 0xC) = *(u16 *)(src + 0x12);
            break;
        }
        switch (*(s32 *)header) {
        case 0x64:
            *(s32 *)(dst + 0x10) = 0;
            break;
        case 0x65:
            *(s32 *)(dst + 0x10) = *(u16 *)(src + 0x14);
            break;
        }
        switch (*(s32 *)header) {
        case 0x64:
            *(f32 *)(dst + 0x14) = 10.0f;
            break;
        case 0x65:
            *(f32 *)(dst + 0x14) = *(f32 *)(src + 0x18);
            break;
        }
        switch (*(s32 *)header) {
        case 0x64:
            *(s32 *)(*(u8 **)(node + 0x18) + sectionIndex * 8) = *(s32 *)(src + 8);
            *(s32 *)(*(u8 **)(node + 0x18) + sectionIndex * 8 + 4) = *(s32 *)(src + 0xC);
            break;
        case 0x65:
            *(s32 *)(*(u8 **)(node + 0x18) + sectionIndex * 8) = *(s32 *)(src + 8);
            *(s32 *)(*(u8 **)(node + 0x18) + sectionIndex * 8 + 4) = *(s32 *)(src + 0xC);
            break;
        }
        switch (*(s32 *)header) {
        case 0x64:
            memcpy((*(u8 ***)(node + 0x1C))[sectionIndex], commandStreams[sectionIndex], *(u32 *)(src + 0x14));
            break;
        case 0x65:
            memcpy((*(u8 ***)(node + 0x1C))[sectionIndex], commandStreams[sectionIndex], *(u32 *)(src + 0x1C));
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
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 544 differing bytes). Offsets remain as observed. */
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

    size = 0;
    size += 0x24;
    size += *(s16*)(resource + 4) * 0x3C;
    size += *(s16*)(resource + 4) * 8;
    size += *(s16*)(resource + 4) * 0x20;
    size += *(s16*)(resource + 4) * 0x18;
    chkmemAllocSiteTag(D_007146B0, 0x287);
    node = (u8*)(*jtbl_008873E8)(size, 0x40000);
    base = node + 0x24;
    *(u8**)(node + 8) = base;
    base += *(s16*)(resource + 4) * 0x3C;
    *(u8**)(node + 0xC) = base;
    base += *(s16*)(resource + 4) * 8;
    *(u8**)(node + 0x10) = base;
    base += *(s16*)(resource + 4) * 0x20;
    *(u8**)(node + 0x14) = base;
    *(s32*)node = 0;
    *(u8**)(node + 4) = resource;
    node[0x20] = 0xFF;
    node[0x21] = 0xFF;
    node[0x22] = 0xFF;
    node[0x23] = 0xFE;

    i = 0;
    if (*(s16*)(resource + 4) > 0)
    {
        color.c[0] = 0xFF;
        color.c[1] = 0xFF;
        color.c[2] = 0xFF;
        color.c[3] = 0xFE;
        while (i < *(s16*)(resource + 4))
        {
            effAfterAllocVectorBuffers(*(u8**)(node + 8) + i * 0x3C,
                          *(u8**)(resource + 0xC) + i * 0x18);
            *(s32*)(*(u8**)(node + 0xC) + i * 8 + 4) = func_003c4140();
            {
                u8* obj;
                u8* material;
                obj = *(u8**)(*(u8**)(node + 8) + i * 0x3C);
                material = *(u8**)(obj + 4);
                if ((*(s32*)material & 1) != 0)
                {
                    func_003c42b0(*(u8**)(*(u8**)(node + 0xC) + i * 8 + 4),
                                  *(u8**)(material + 4));
                }
            }
            *(Color4*)(*(u8**)(*(u8**)(node + 0xC) + i * 8 + 4) + 4) = color;
            temp = effAfterCreateRibbon(*(u8**)(node + 8) + i * 0x3C,
                                 *(struct RpMaterial**)(*(u8**)(node + 0xC) + i * 8 + 4));
            *(s32*)(*(u8**)(node + 0xC) + i * 8) = func_003c00e0();
            func_003c0210(*(u8**)(*(u8**)(node + 0xC) + i * 8), temp, 0);
            RpAtomicSetFrame(*(u8**)(*(u8**)(node + 0xC) + i * 8),
                          (void*)func_003e9320());
            func_003c2a80(temp);
            effMiscProgressResetWork(*(u8**)(node + 8) + i * 0x3C, temp);
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
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 483 differing bytes). Offsets remain as observed. */
    typedef int (*code)();
    extern code DAT_008873ec_abs[];
    void *(**table);
    extern void Vpad_UpdateRenderEntries(void *source);
    extern void Vpad_DrawEntries(void *source);
    extern s32 Vpad_HasEntries(void *source);
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
            flags = *(s32 *)(first + 0);
            if (flags & 8) {
                Vpad_UpdateRenderEntries(first);
            } else if (flags & 2) {
                Vpad_UpdateRenderEntries(first);
                *(s32 *)(first + 0) = *(s32 *)(first + 0) & ~2;
            }
            first = *(u8 **)(first + 0x1C);
        }
        node = (u8 *)D_00764CA0;
        while (node != NULL) {
            temp = node;
            node = *(u8 **)(node + 0x1C);
            bits = 0;
            i = 0;
            while (i < *(s16 *)(*(u8 **)(temp + 4) + 4)) {
                bits |= Vpad_HasEntries(*(u8 **)(temp + 0x10) + (i << 5));
                i++;
            }
            if (bits == 0) {
                if (D_00764CA0 == NULL) {
                    kAssertFail(D_007146B0, 0x326);
                }
                if (D_00764C9C == NULL) {
                    kAssertFail(D_007146B0, 0x327);
                }
                next = *(u8 **)(temp + 0x1C);
                if (next != NULL) {
                    *(u8 **)(next + 0x18) = *(u8 **)(temp + 0x18);
                }
                prev = *(u8 **)(temp + 0x18);
                if (prev != NULL) {
                    *(u8 **)(prev + 0x1C) = *(u8 **)(temp + 0x1C);
                }
                if (temp == (u8 *)D_00764C9C) {
                    D_00764C9C = *(u8 **)(temp + 0x18);
                }
                if (temp == (u8 *)D_00764CA0) {
                    D_00764CA0 = (RuntimeListNode *)*(u8 **)(temp + 0x1C);
                }
                work = *(u8 **)(temp + 4);
                i = 0;
                while (i < *(s16 *)(*(u8 **)(temp + 4) + 4)) {
                    effAfterFreeVectorBuffers(*(u8 **)(temp + 8) + i * 0x3C);
                    off = i * 8;
                    func_003e9390(*(u8 **)(*(u8 **)(*(u8 **)(temp + 0xC) + off) + 4));
                    func_003c02e0(*(u8 **)(*(u8 **)(temp + 0xC) + off));
                    func_003c4220(*(u8 **)(*(u8 **)(temp + 0xC) + off + 4));
                    i++;
                }
                table = (void *(**) )DAT_008873ec_abs;
                ((code)table[0])(temp);
                ((code)table[0])(work);
            }
        }
        first = (u8 *)D_00764CA0;
        while (first != NULL) {
            flags = *(s32 *)(first + 0);
            if (flags & 8) {
                Vpad_DrawEntries(first);
            } else if (flags & 4) {
                Vpad_DrawEntries(first);
                *(s32 *)(first + 0) = *(s32 *)(first + 0) & ~4;
            }
            first = *(u8 **)(first + 0x1C);
        }
    }
}

// Releases every afterimage instance whose pack's word at +0x20 equals owner: unlinks it, frees its vector buffers and sections, and frees the node and its pack.
// FUN_004B7140
void AfPackReleaseByOwner(s32 owner)
{
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 303 differing bytes). Offsets remain as observed. */
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
        nextNode = *(u8**)(nextNode + 0x1C);
        if (*(s32*)(*(u8**)(node + 4) + 0x20) == owner)
        {
            if (D_00764CA0 == NULL)
            {
                kAssertFail(D_007146B0, 0x326);
            }
            if (D_00764C9C == NULL)
            {
                kAssertFail(D_007146B0, 0x327);
            }
            next = *(u8**)(node + 0x1C);
            if (next != NULL)
            {
                *(u8**)(next + 0x18) = *(u8**)(node + 0x18);
            }
            previous = *(u8**)(node + 0x18);
            if (previous != NULL)
            {
                *(u8**)(previous + 0x1C) = *(u8**)(node + 0x1C);
            }
            if (node == (u8*)D_00764C9C)
            {
                D_00764C9C = *(void**)(node + 0x18);
            }
            if (node == (u8*)D_00764CA0)
            {
                D_00764CA0 = *(RuntimeListNode**)(node + 0x1C);
            }
            resource = *(u8**)(node + 4);
            sectionIndex = 0;
            while (sectionIndex < *(s16*)(*(u8**)(node + 4) + 4))
            {
                effAfterFreeVectorBuffers(*(u8**)(node + 8) + sectionIndex * 0x3C);
                renderOffset = sectionIndex * 8;
                func_003e9390(*(void**)(*(u8**)(*(u8**)(node + 0xC) + renderOffset) + 4));
                func_003c02e0(*(u8**)(*(u8**)(node + 0xC) + renderOffset));
                func_003c4220(*(void**)(*(u8**)(node + 0xC) + renderOffset + 4));
                sectionIndex++;
            }
            base = (u32)jtbl_008873EC;
            ((void (*)(void*))*(u32*)base)(node);
            ((void (*)(void*))*(u32*)base)(resource);
        }
    }
}

