/* Whole-file translation unit: src/Graphics/Effect/effHelper.c */

#include "type.h"

void func_0046d730(u8 *file, s32 line);
void func_0044ea90(u8 *file, s32 line);
void *memcpy(void *dst, const void *src, s32 size);
void *memset(void *dst, s32 value, s32 size);
u8 *func_00484490(u8 *obj);
s32 func_004844d0(u8 *obj);
u8 *func_004abc50(u8 *base, s32 size);
s32 func_00479ca0(s32 res, s32 arg1);
extern s32 func_00479940(u8* model, u32 layer, s32 animation, s32 frame, s32 flags);
u32 func_0047a7c0(s32 res);
u32 func_00484bb0(s32 arg);
u32 func_00485c80(u32 arg);
void func_00485b20(u32 arg);
void func_004abd60(s32 res);
s32 func_00478140(u16 a, u16 b, s32 c);
void func_004abbb0(s32 res);

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

void func_004ad880(EffHlpWork *work, EffHlpWork *src);

// FUN_004AD460
EffHlpWork *func_004ad460(u8 *arg0)
{
    void *(*const *allocSlot)(u32, u32);
    EffHlpWork *work;
    s32 v20;
    s32 v;
    u8 *tex;
    u32 i;

    func_0044ea90(D_007144F8, 0x1D);
    allocSlot = jtbl_008873E8;
    work = (EffHlpWork *)(*allocSlot)(0xA4, 0x40000);
    if (work == NULL) {
        func_0046d730(D_007144F8, 0x1E);
    }
    memset(work, 0, 0xA4);
    work->lastTex = -1;
    work->alpha = 1.0f;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(work) : "memory");
    __asm__ volatile ("sqc2 vf0, 16(%0)" : : "r"(work) : "memory");
    if (arg0 == NULL) {
        return work;
    }
    tex = func_00484490(arg0);
    if (tex == NULL) {
        func_0046d730(D_007144F8, 0x2E);
    }
    switch (*(u16 *)(arg0 + 0xC)) {
    case 0:
        v20 = 0x70;
        memcpy((u8 *)work + 0x30, tex, 0x68);
        break;
    default:
        func_0046d730(D_007144F8, 0x38);
        v20 = 0;
        break;
    }
    work->res = (s32)func_004abc50(tex + v20, *(s32 *)(arg0 + 0x14) - v20);
    if (work->res == 0) {
        func_0046d730(D_007144F8, 0x40);
    }
    if (func_00479ca0(work->res, 0) != 0) {
        if (work->data.mode != 0) {
            func_00479940((u8*)work->res, 0, 0, 0, 0);
        } else {
            func_00479940((u8*)work->res, 0, 0, 0, 1);
        }
    }
    work->count = func_0047a7c0(work->res);
    if (work->count == 0) {
        return work;
    }
    v = func_004844d0(arg0);
    if (v != 0) {
        if (*(u16 *)(arg0 + 0x1C) != 6) {
            func_0046d730(D_007144F8, 0x53);
        }
        {
            u32 bytes = work->count * 4;
            func_0044ea90(D_007144F8, 0x57);
            work->listAlloc = (*allocSlot)(bytes, 0x40000);
        }
        if (work->listAlloc == NULL) {
            func_0046d730(D_007144F8, 0x58);
        }
        work->list = work->listAlloc;
        work->list[0] = func_00484bb0(v);
        for (i = 1; i < work->count; i++) {
            work->list[i] = func_00485c80(work->list[0]);
        }
    }
    return work;
}

// FUN_004AD760
void func_004ad760(EffHlpWork *work)
{
    u32 i;

    if (work->res != 0) {
        func_004abd60(work->res);
    }
    if (work->listAlloc != NULL) {
        for (i = 0; i < work->count; i++) {
            func_00485b20(work->list[i]);
        }
        (*jtbl_008873EC)(work->listAlloc);
    }
    (*jtbl_008873EC)(work);
}

// FUN_004AD810
EffHlpWork *func_004ad810(u8 *arg0)
{
    EffHlpWork *work;

    work = func_004ad460(NULL);
    memcpy((u8 *)work + 0x30, arg0 + 0x30, 0x68);
    func_004ad880(work, (EffHlpWork *)arg0);
    return work;
}

// FUN_004AD880
void func_004ad880(EffHlpWork *work, EffHlpWork *src)
{
    u32 i;

    if (src->res == 0) {
        func_0046d730(D_007144F8, 0x9F);
    }
    if (work->res != 0) {
        func_004abd60(work->res);
    }
    work->res = (s32)func_00478140(*(u16 *)((u8 *)src->res + 0xD4),
                                   *(u16 *)((u8 *)src->res + 0xD6), 0);
    if (work->res == 0) {
        func_0046d730(D_007144F8, 0xA9);
    }
    func_004abbb0(work->res);
    if (func_00479ca0(work->res, 0) != 0) {
        if (work->data.mode != 0) {
            func_00479940((u8*)work->res, 0, 0, 0, 0);
        } else {
            func_00479940((u8*)work->res, 0, 0, 0, 1);
        }
    }
    work->count = func_0047a7c0(work->res);
    if (src->listAlloc != NULL) {
        if (work->listAlloc != NULL) {
            for (i = 0; i < work->count; i++) {
                func_00485b20(work->list[i]);
            }
            (*jtbl_008873EC)(work->listAlloc);
        }
        {
            u32 bytes = work->count * 4;
            func_0044ea90(D_007144F8, 0xCB);
            work->listAlloc = (*jtbl_008873E8)(bytes, 0x40000);
        }
        if (work->listAlloc == NULL) {
            func_0046d730(D_007144F8, 0xCC);
        }
        work->list = work->listAlloc;
        for (i = 0; i < work->count; i++) {
            work->list[i] = func_00485c80(src->list[0]);
        }
    }
}
