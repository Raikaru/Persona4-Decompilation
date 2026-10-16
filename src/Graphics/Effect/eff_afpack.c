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
    u8 reserved[8];
    struct RuntimeListNode* previous;
    struct RuntimeListNode* next;
} RuntimeListNode;

extern void* D_00764C98;
extern s32 D_00922DB0[];
extern s32 D_00922DB4[];
extern void func_00460ac0(void* arg0, s32* arg1);
extern void* D_00764C9C;
extern RuntimeListNode* D_00764CA0;
extern void effAfterResetCommand(void* arg0, void* arg1);
extern void effAfterRunCommands(void* arg0, void* arg1);
extern void func_00440b68(const void* msg, const void* file, s32 line);
extern u8* func_00454a60(u8* param, s32 mode);
extern void H_Cdvd_ReadSync(void* handle);
extern s32 func_003ef740(u8* param, s32 mode);
extern void H_Cdvd_Destroy(u8* ptr);

extern void memset(void* dst, s32 value, u32 size);
extern u8 D_00764210;
extern s32 D_00764CA4;
extern s32 D_00764CA8;
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
extern void effAfterFreeVectorBuffers(void* arg0);
extern void (*jtbl_008873EC[])(void* ptr);
extern void chkmemAllocSiteTag(const void* file, s32 line);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern void effAfterAllocVectorBuffers(void* arg0, void* arg1);
extern s32 func_003c4140(void);
extern void func_003c42b0(void* a, void* b);
struct RpMaterial;
extern u8* effAfterCreateRibbon(u8* a, struct RpMaterial* material);
extern s32 func_003c00e0(void);
extern void func_003c0210(void* a, void* b, s32 c);
extern s32 func_003e9320(void);
extern void RpAtomicSetFrame(void* a, void* b);
extern void func_003c2a80(void* a);
extern void func_004bccf0(void* a, void* b);
extern void func_003c22f0(void* a);

/* The allocation result lands in `base` first and is copied to `node`:
 * retail adds 0x24 to the $v0 result directly and keeps the cursor out of
 * the saved register that holds the node. measured: opt_loop_invariants
 * and opt_lifetimes on are both required (verify MISMATCH, nd 116,
 * without them). */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// Binds the sections of the packed afterimage resource at arg0: walks the header counts and records each table's pointer; the per-record size depends on the header's type word (0x64 or 0x65).
// FUN_004B6030
u8 *AfPackBindResource(void *arg0)
{
    extern void memcpy(void *dst, void *src, u32 size);
    u8 *aTmp[16];
    u8 *cTmp1[16];
    u8 *cTmp2[16];
    u8 *bTmp1[16];
    u8 *bTmp2[16];
    u8 *node;
    s32 i3;
    s32 i0;
    s32 i4;
    s32 i1;
    u8 *base;
    u8 *header;
    s32 i6;
    s32 i5;
    s32 size;
    s32 i7;
    u8 *p;

    p = arg0;
    header = p;
    p += 0x10;
    for (i0 = 0; i0 < *(u16 *)(header + 0xA); i0++) {
        aTmp[i0] = p;
        p += 0x38;
    }
    for (i1 = 0; i1 < *(u16 *)(header + 0xC); i1++) {
        u8 *cur;

        cTmp1[i1] = p;
        p += 8;
        cur = cTmp1[i1];
        switch (*(u16 *)(cur + 4)) {
        case 0:
            p += 4;
            break;
        default:
            kAssertFail(D_007146B0, 0x1AE);
            break;
        }
        cTmp2[(u32)i1] = p;
        switch (*(u16 *)(cur + 6)) {
        case 0:
            p += 0x10;
            break;
        default:
            kAssertFail(D_007146B0, 0x1BA);
            break;
        }
    }
    for (i1 = 0; i1 < *(u16 *)(header + 8); i1++) {
        bTmp1[i1] = p;
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
        bTmp2[i1] = p;
        switch (*(s32 *)header) {
        case 0x64:
            p += *(s32 *)(bTmp1[i1] + 0x14);
            break;
        case 0x65:
            p += *(s32 *)(bTmp1[i1] + 0x1C);
            break;
        }
    }
    size = 0;
    size = size + 0x24;
    size = size + *(u16 *)(header + 8) * 0x18;
    size = size + *(u16 *)(header + 0xA) * 0x34;
    size = size + *(u16 *)(header + 0xC) * 0x18;
    size = size + *(u16 *)(header + 8) * 4;
    for (i3 = 0; i3 < *(u16 *)(header + 8); i3++) {
        switch (*(s32 *)header) {
        case 0x64:
            size += *(s32 *)(bTmp1[i3] + 0x14);
            break;
        case 0x65:
            size += *(s32 *)(bTmp1[i3] + 0x1C);
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
    for (i4 = 0; i4 < *(u16 *)(header + 8); i4++) {
        (*(u8 ***)(node + 0x1C))[i4] = base;
        switch (*(s32 *)header) {
        case 0x64:
            base += *(s32 *)(bTmp1[i4] + 0x14);
            break;
        case 0x65:
            base += *(s32 *)(bTmp1[i4] + 0x1C);
            break;
        }
    }
    *(u8 **)(node + 0x18) = base;
    *(s32 *)(node + 0) = *(s32 *)(header + 4);
    *(u16 *)(node + 4) = *(u16 *)(header + 8);
    *(u16 *)(node + 6) = *(u16 *)(header + 0xA);
    *(u16 *)(node + 8) = *(u16 *)(header + 0xC);
    for (i5 = 0; i5 < *(u16 *)(header + 0xA); i5++) {
        f32 *dst = (f32 *)(*(u8 **)(node + 0x10) + i5 * 0x34);
        f32 *src = (f32 *)aTmp[i5];

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
    for (i6 = 0; i6 < *(u16 *)(header + 0xC); i6++) {
        u8 *dst = *(u8 **)(node + 0x14) + i6 * 0x18;
        u8 *src = cTmp1[i6];
        u8 *colors = cTmp2[i6];
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
    for (i7 = 0; i7 < *(u16 *)(header + 8); i7++) {
        u8 *dst = *(u8 **)(node + 0xC) + i7 * 0x18;
        u8 *src = bTmp1[i7];
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
            if (id == *(u16 *)aTmp[j]) {
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
            if (id == *(u16 *)cTmp1[j]) {
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
            *(s32 *)(*(u8 **)(node + 0x18) + i7 * 8) = *(s32 *)(src + 8);
            *(s32 *)(*(u8 **)(node + 0x18) + i7 * 8 + 4) = *(s32 *)(src + 0xC);
            break;
        case 0x65:
            *(s32 *)(*(u8 **)(node + 0x18) + i7 * 8) = *(s32 *)(src + 8);
            *(s32 *)(*(u8 **)(node + 0x18) + i7 * 8 + 4) = *(s32 *)(src + 0xC);
            break;
        }
        switch (*(s32 *)header) {
        case 0x64:
            memcpy((*(u8 ***)(node + 0x1C))[i7], bTmp2[i7], *(u32 *)(src + 0x14));
            break;
        case 0x65:
            memcpy((*(u8 ***)(node + 0x1C))[i7], bTmp2[i7], *(u32 *)(src + 0x1C));
            break;
        }
    }
    return node;
}
#pragma pop
// Creates the afterimage instance for a pack: allocates the node with its vector, material and ribbon tables, then per section builds the vector buffers, the ribbon geometry (effAfterCreateRibbon) and the atomic and texture bindings.
// FUN_004B6900
u8* AfPackCreateInstance(u8* arg0)
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

    size = 0;
    size += 0x24;
    size += *(s16*)(arg0 + 4) * 0x3C;
    size += *(s16*)(arg0 + 4) * 8;
    size += *(s16*)(arg0 + 4) * 0x20;
    size += *(s16*)(arg0 + 4) * 0x18;
    chkmemAllocSiteTag(D_007146B0, 0x287);
    node = (u8*)(*jtbl_008873E8)(size, 0x40000);
    base = node + 0x24;
    *(u8**)(node + 8) = base;
    base += *(s16*)(arg0 + 4) * 0x3C;
    *(u8**)(node + 0xC) = base;
    base += *(s16*)(arg0 + 4) * 8;
    *(u8**)(node + 0x10) = base;
    base += *(s16*)(arg0 + 4) * 0x20;
    *(u8**)(node + 0x14) = base;
    *(s32*)node = 0;
    *(u8**)(node + 4) = arg0;
    node[0x20] = 0xFF;
    node[0x21] = 0xFF;
    node[0x22] = 0xFF;
    node[0x23] = 0xFE;

    i = 0;
    if (*(s16*)(arg0 + 4) > 0)
    {
        color.c[0] = 0xFF;
        color.c[1] = 0xFF;
        color.c[2] = 0xFF;
        color.c[3] = 0xFE;
        while (i < *(s16*)(arg0 + 4))
        {
            effAfterAllocVectorBuffers(*(u8**)(node + 8) + i * 0x3C,
                          *(u8**)(arg0 + 0xC) + i * 0x18);
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
            func_004bccf0(*(u8**)(node + 8) + i * 0x3C, temp);
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
    s32 sp3C;
    s32 off;
    u8* work;
    u8* out;

    i = 0;
    while (i < *(s16*)((u8*)node->work + 4))
    {
        work = (u8*)node->work;
        out = *(u8**)((u8*)node + 0x10) + i * 0x20;
        *(s32*)(out + 8) = *(s32*)(*(s32**)(work + 0x1C) + i);
        off = i * 0x3C;
        *(s32*)(out + 0x10) = (s32)((u8*)node->vertices + off);
        effAfterResetCommand(out, work);
        i++;
    }
    node->flags |= 1;
    i = 0;
    while (i < *(s16*)((u8*)node->work + 4))
    {
        effAfterRunCommands(*(u8**)((u8*)node + 0x10) + i * 0x20, &sp3C);
        i++;
    }
}

// Loads the afterimage pack from resource D_007146C0 with a synchronous CDVD read, creates the update task at priority arg1 and the render-list task, clears the list, and stores arg0 in D_00764C98.
// FUN_004B6C90
void AfPackInit(s32 arg0, s32 arg1)
{
    s32 temp_2;

    func_00440b68(&D_00764210, D_007146B0, 0x2DA);
    temp_2 = (s32)func_00454a60(D_007146C0, 0);
    H_Cdvd_ReadSync((void*)temp_2);
    D_00764CA8 = (s32)func_003ef740(D_007146C0, 0);
    H_Cdvd_Destroy((u8*)temp_2);
    D_00764CA0 = NULL;
    D_00764C9C = NULL;
    D_00764CA4 = (s32)kwlnTaskCreate((const void *)(D_007146D0), arg1, 0, 0, AfPackTaskUpdate, 0, (u8 *)(NULL));
    memset(D_00922DB0, 0, 0x30);
    D_00922DB8[0] = (void*)AfPackRunList;
    D_00922DC0[0] = 0;
    D_00764C98 = (void*)arg0;
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
        current = *(RuntimeListNode**)((u8*)current + 0x1c);
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
        *(void**)((u8*)node + 0x18) = NULL;
        *(void**)((u8*)node + 0x1c) = NULL;
        D_00764CA0 = (RuntimeListNode*)node;
        D_00764C9C = node;
        return;
    }
    else
    {
        *(void**)((u8*)node + 0x18) = D_00764C9C;
        *(void**)((u8*)node + 0x1c) = NULL;
        *(void**)((u8*)D_00764C9C + 0x1c) = node;
    }
    D_00764C9C = node;
}
// Task callback: clears two words of the update state and runs func_00460ac0 on the pack registered in D_00764C98.
// FUN_004B6E40
s32 AfPackTaskUpdate(u8 *unusedTask)
{
    D_00922DB0[0] = 0;
    D_00922DB4[0] = 0;
    func_00460ac0(D_00764C98, D_00922DB0);
    return 0;
}

// Runs the afterimage list once per frame: updates the render entries, reaps nodes with no live entries (freeing their buffers), then draws the remaining entries.
// FUN_004B6E80
void AfPackRunList(void) {
    typedef int (*code)();
    extern code DAT_008873ec_abs[];
    void *(**table);
    extern void Vpad_UpdateRenderEntries(void *arg0);
    extern void Vpad_DrawEntries(void *arg0);
    extern s32 Vpad_HasEntries(void *arg0);
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

// Releases every afterimage instance whose pack's word at +0x20 equals arg0: unlinks it, frees its vector buffers and sections, and frees the node and its pack.
// FUN_004B7140
void AfPackReleaseByOwner(s32 arg0)
{
    s32 temp_16;
    u8* var_19;
    u8* temp_18;
    u8* temp_21;
    u8* temp_3;
    u8* temp_3_2;
    s32 var_17;
    u32 base;

    var_19 = (u8*)D_00764CA0;
    while (var_19 != NULL)
    {
        temp_18 = var_19;
        var_19 = *(u8**)(var_19 + 0x1C);
        if (*(s32*)(*(u8**)(temp_18 + 4) + 0x20) == arg0)
        {
            if (D_00764CA0 == NULL)
            {
                kAssertFail(D_007146B0, 0x326);
            }
            if (D_00764C9C == NULL)
            {
                kAssertFail(D_007146B0, 0x327);
            }
            temp_3 = *(u8**)(temp_18 + 0x1C);
            if (temp_3 != NULL)
            {
                *(u8**)(temp_3 + 0x18) = *(u8**)(temp_18 + 0x18);
            }
            temp_3_2 = *(u8**)(temp_18 + 0x18);
            if (temp_3_2 != NULL)
            {
                *(u8**)(temp_3_2 + 0x1C) = *(u8**)(temp_18 + 0x1C);
            }
            if (temp_18 == (u8*)D_00764C9C)
            {
                D_00764C9C = *(void**)(temp_18 + 0x18);
            }
            if (temp_18 == (u8*)D_00764CA0)
            {
                D_00764CA0 = *(RuntimeListNode**)(temp_18 + 0x1C);
            }
            temp_21 = *(u8**)(temp_18 + 4);
            var_17 = 0;
            while (var_17 < *(s16*)(*(u8**)(temp_18 + 4) + 4))
            {
                effAfterFreeVectorBuffers(*(u8**)(temp_18 + 8) + var_17 * 0x3C);
                temp_16 = var_17 * 8;
                func_003e9390(*(void**)(*(u8**)(*(u8**)(temp_18 + 0xC) + temp_16) + 4));
                func_003c02e0(*(u8**)(*(u8**)(temp_18 + 0xC) + temp_16));
                func_003c4220(*(void**)(*(u8**)(temp_18 + 0xC) + temp_16 + 4));
                var_17++;
            }
            base = (u32)jtbl_008873EC;
            ((void (*)(void*))*(u32*)base)(temp_18);
            ((void (*)(void*))*(u32*)base)(temp_21);
        }
    }
}

