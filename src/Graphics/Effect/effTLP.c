/* Whole-file translation unit: src/Graphics/Effect/effTLP.c */

#include "type.h"

void func_0046d730(u8 *file, s32 line);
void func_0044ea90(u8 *file, s32 line);
void *memcpy(void *dst, const void *src, s32 size);
s32 func_00481390(u8 *ptr);
void func_003ef3a0(void *ptr);

extern u8 D_00713300[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);

typedef struct TlpEntry
{
    s32 size;    // 0x00
    s32 stride;  // 0x04
    u8 pad[8];   // 0x08
} TlpEntry;      // 0x10

typedef struct TLP
{
    u32 magic;        // 0x00
    u32 count;        // 0x04
    u32 flags;        // 0x08
    u32 pad;          // 0x0C
    TlpEntry *entries;// 0x10
    u32 *texIds;      // 0x14
    s32 totalSize;    // 0x18
    s32 refCount;     // 0x1C
    s32 lastTex;      // 0x20
    void *self;       // 0x24
} TLP;                // 0x28

/* Header of the creation description; 0x10-byte entries and the texId
 * pointer array follow it inline in memory. */
typedef struct TlpDesc
{
    u32 magic; // 0x00
    u32 count; // 0x04
    u32 flags; // 0x08
    u32 pad;   // 0x0C
} TlpDesc;

typedef struct TlpSel
{
    f32 a;     // 0x00
    f32 b;     // 0x04
    f32 w;     // 0x08
    f32 h;     // 0x0C
    void *tex; // 0x10
} TlpSel;      // 0x14

// FUN_00482800
TLP *func_00482800(TlpDesc *desc)
{
    u32 j;
    u32 cnt;
    s32 total;
    TLP *work;
    u32 count;
    u8 *src;
    u8 *p;
    u32 i;

    if (desc->magic != 0x30504C54) {
        func_0046d730(D_00713300, 0x29);
    }
    count = desc->count;
    if (count == 0) {
        func_0046d730(D_00713300, 0x2D);
    }
    func_0044ea90(D_00713300, 0x33);
    work = (TLP *)(*jtbl_008873E8)(count * 0x10 + 0x28 + count * 4, 0x40000);
    work->entries = (TlpEntry *)((u8 *)work + 0x28);
    work->texIds = (u32 *)((u8 *)work->entries + count * 0x10);
    work->refCount = 0;
    work->lastTex = -1;
    work->self = work;
    memcpy(work, desc, 0x10);
    src = (u8 *)desc + 0x10;
    p = src + count * 0x10;
    for (i = 0; i < count; i++) {
        memcpy((u8 *)work->entries + i * 0x10, src, 0x10);
        work->texIds[i] = (u32)func_00481390(p);
        p += ((TlpEntry *)src)->stride;
        src += 0x10;
    }
    total = 0;
    j = 0;
    cnt = work->count;
    for (; j < cnt; j++) {
        total = total + 1;
        total = total + work->entries[j].size;
    }
    work->totalSize = total;
    work->refCount = work->refCount + 1;
    return work;
}

// FUN_004829C0
void func_004829c0(TLP *work)
{
    s32 n;
    u32 i;

    if (work->refCount == 0) {
        func_0046d730(D_00713300, 0x56);
    }
    n = work->refCount - 1;
    work->refCount = n;
    if (n == 0) {
        for (i = 0; i < work->count; i++) {
            func_003ef3a0((void *)work->texIds[i]);
        }
        (*jtbl_008873EC)(work->self);
    }
}

// FUN_00482A70
TLP *func_00482a70(TLP *work)
{
    if (work->refCount == 0) {
        func_0046d730(D_00713300, 0x68);
    }
    work->refCount = work->refCount + 1;
    return work;
}

// FUN_00482AD0
void func_00482ad0(TLP *work, u32 index, TlpSel *out)
{
    TlpEntry *e;
    u32 j;
    u32 acc;
    u32 i = 0;
    s32 sel = -1;
    u32 count = work->count;
    f32 scale;
    u8 *texData;
    void *tex;

    if (count == 1) {
        sel = 0;
    } else {
        if (work->flags & 1) {
            i = index % work->totalSize;
        } else if (index >= work->totalSize) {
            sel = count - 1;
        } else {
            i = index;
        }
        if (sel == -1) {
            e = work->entries;
            acc = 0;
            for (j = 0; j < count; j++, e++) {
                if (i <= acc + e->size) {
                    sel = (s32)j;
                    break;
                }
                acc = acc + e->size + 1;
            }
            if (sel < 0) {
                func_0046d730(D_00713300, 0x9A);
            }
        }
    }
    scale = 1.0f;
    out->a = 1.0f;
    if (work->flags & 4) {
        scale = 2.0f;
    }
    out->b = scale;
    tex = (void *)work->texIds[sel];
    out->tex = tex;
    texData = *(u8 **)tex;
    out->w = (f32)((s32 *)texData)[3];
    out->h = (f32)((s32 *)texData)[4];
}
