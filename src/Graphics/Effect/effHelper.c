#include "model_motion_internal.h"
/* Whole-file translation unit: src/Graphics/Effect/effHelper.c */

#include "type.h"
#include "effect_instance_internal.h"

void kAssertFail(u8 *file, s32 line);
void chkmemAllocSiteTag(u8 *file, s32 line);
void *memcpy(void *dst, const void *src, s32 size);
void *memset(void *dst, s32 value, s32 size);
u8 *func_004abc50(u8 *base, s32 size);
s32 mdlLayerIsPresent(s32 res, s32 arg1);
u32 mdlCountIntUserData(s32 res);
void mdlEffectDestroyWithNodes(u32 arg);
void func_004abd60(s32 res);
void *mdlFindOrCreateModelObject(u32 a, u16 b, u32 c);
void EffModelInit(s32 res);

extern u8 D_007144F8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);

typedef struct EffHlpData
{
    u8 raw[0x60];  // 0x00
    s32 mode;      // 0x60
    u8 tail[4];    // 0x64
} EffHlpData;      // 0x68

typedef struct EffHlpWork
{
    u8 zero[0x20];   // 0x00
    f32 alpha;       // 0x20
    s32 lastTex;     // 0x24
    u32 count;       // 0x28
    u8 pad[4];       // 0x2C
    EffHlpData data; // 0x30
    u32 *list;       // 0x98
    u32 *listAlloc;  // 0x9C
    s32 res;         // 0xA0
} EffHlpWork;        // 0xA4

void EffHelperRebindModel(EffHlpWork *work, EffHlpWork *src);

// Allocates a 0xA4-byte helper work block; with a source, copies its 0x68-byte header, loads the model layer, counts its user data and builds the list when the source kind is 6.
// FUN_004AD460
void *EffHelperCreate(void *arg0)
{
    void *(*const *allocSlot)(u32, u32);
    EffHlpWork *work;
    s32 v20;
    s32 v;
    u8 *tex;
    u32 i;

    chkmemAllocSiteTag(D_007144F8, 0x1D);
    allocSlot = jtbl_008873E8;
    work = (EffHlpWork *)(*allocSlot)(0xA4, 0x40000);
    if (work == NULL) {
        kAssertFail(D_007144F8, 0x1E);
    }
    memset(work, 0, 0xA4);
    work->lastTex = -1;
    work->alpha = 1.0f;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(work) : "memory");
    __asm__ volatile ("sqc2 vf0, 16(%0)" : : "r"(work) : "memory");
    if (arg0 == NULL) {
        return work;
    }
    tex = mdlEffectResolveRelPtrA(arg0);
    if (tex == NULL) {
        kAssertFail(D_007144F8, 0x2E);
    }
    switch (*(u16 *)((u8 *)arg0 + 0xC)) {
    case 0:
        v20 = 0x70;
        memcpy((u8 *)work + 0x30, tex, 0x68);
        break;
    default:
        kAssertFail(D_007144F8, 0x38);
        v20 = 0;
        break;
    }
    work->res = (s32)func_004abc50(tex + v20, *(s32 *)((u8 *)arg0 + 0x14) - v20);
    if (work->res == 0) {
        kAssertFail(D_007144F8, 0x40);
    }
    if (mdlLayerIsPresent(work->res, 0) != 0) {
        if (work->data.mode != 0) {
            mdlDispatchAnimIfPresent((u8*)work->res, 0, 0, 0, 0);
        } else {
            mdlDispatchAnimIfPresent((u8*)work->res, 0, 0, 0, 1);
        }
    }
    work->count = mdlCountIntUserData(work->res);
    if (work->count == 0) {
        return work;
    }
    v = (s32)mdlEffectResolveRelPtrB(arg0);
    if (v != 0) {
        if (*(u16 *)((u8 *)arg0 + 0x1C) != 6) {
            kAssertFail(D_007144F8, 0x53);
        }
        {
            u32 bytes = work->count * 4;
            chkmemAllocSiteTag(D_007144F8, 0x57);
            work->listAlloc = (*allocSlot)(bytes, 0x40000);
        }
        if (work->listAlloc == NULL) {
            kAssertFail(D_007144F8, 0x58);
        }
        work->list = work->listAlloc;
        work->list[0] = (u32)mdlEffectBuildFromResource((u8 *)v);
        for (i = 1; i < work->count; i++) {
            work->list[i] = (u32)mdlEffectCloneWithNodes((u8 *)work->list[0]);
        }
    }
    return work;
}

// Releases the model layer, the list entries and the block.
// FUN_004AD760
void EffHelperFree(EffHlpWork *work)
{
    u32 i;

    if (work->res != 0) {
        func_004abd60(work->res);
    }
    if (work->listAlloc != NULL) {
        for (i = 0; i < work->count; i++) {
            mdlEffectDestroyWithNodes(work->list[i]);
        }
        (*jtbl_008873EC)(work->listAlloc);
    }
    (*jtbl_008873EC)(work);
}

// Creates a helper from arg0 by copying its 0x68-byte header and rebinding its model.
// FUN_004AD810
void *EffHelperClone(void *arg0)
{
    EffHlpWork *work;

    work = EffHelperCreate(NULL);
    memcpy((u8 *)work + 0x30, (u8 *)arg0 + 0x30, 0x68);
    EffHelperRebindModel(work, (EffHlpWork *)arg0);
    return work;
}

// Replaces work's model layer with the model object that src's layer names (ids at +0xD4 and +0xD6); asserts that src has a layer.
// FUN_004AD880
void EffHelperRebindModel(EffHlpWork *work, EffHlpWork *src)
{
    u32 i;

    if (src->res == 0) {
        kAssertFail(D_007144F8, 0x9F);
    }
    if (work->res != 0) {
        func_004abd60(work->res);
    }
    work->res = (s32)mdlFindOrCreateModelObject(*(u16 *)((u8 *)src->res + 0xD4),
                                   *(u16 *)((u8 *)src->res + 0xD6), 0);
    if (work->res == 0) {
        kAssertFail(D_007144F8, 0xA9);
    }
    EffModelInit(work->res);
    if (mdlLayerIsPresent(work->res, 0) != 0) {
        if (work->data.mode != 0) {
            mdlDispatchAnimIfPresent((u8*)work->res, 0, 0, 0, 0);
        } else {
            mdlDispatchAnimIfPresent((u8*)work->res, 0, 0, 0, 1);
        }
    }
    work->count = mdlCountIntUserData(work->res);
    if (src->listAlloc != NULL) {
        if (work->listAlloc != NULL) {
            for (i = 0; i < work->count; i++) {
                mdlEffectDestroyWithNodes(work->list[i]);
            }
            (*jtbl_008873EC)(work->listAlloc);
        }
        {
            u32 bytes = work->count * 4;
            chkmemAllocSiteTag(D_007144F8, 0xCB);
            work->listAlloc = (*jtbl_008873E8)(bytes, 0x40000);
        }
        if (work->listAlloc == NULL) {
            kAssertFail(D_007144F8, 0xCC);
        }
        work->list = work->listAlloc;
        for (i = 0; i < work->count; i++) {
            work->list[i] = (u32)mdlEffectCloneWithNodes((u8 *)src->list[0]);
        }
    }
}
