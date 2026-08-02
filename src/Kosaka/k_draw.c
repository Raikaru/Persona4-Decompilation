/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "include_asm.h"
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

typedef struct RwMatrix
{
    RwV3d right;    // 0x00
    u32 flags;      // 0x0c
    RwV3d up;       // 0x10
    u32 pad1;       // 0x1c
    RwV3d at;       // 0x20
    u32 pad2;       // 0x2c
    RwV3d pos;      // 0x30
    u32 pad3;       // 0x3c
} RwMatrix;

extern RwMatrix* func_003e0670(RwMatrix* matrixOut, RwMatrix* matrixIn);
extern f32 func_0044b950(f32 x, f32 y);
extern f32 gPI;

extern void func_0044ea90(u8 *file, s32 line);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern s32 func_00451fc0(s32 window, u8 *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
extern void *func_00460990(void);
extern void func_00460ac0(void *param, void *work);
extern void (*jtbl_008873EC[])(void *);
extern void func_004601c0(f32, u8 *, u8 *, s32);
extern u8 D_005EFBC8[];
extern u8 D_005EFBD8[];
extern u8 D_005EFBE8[];
extern u8 D_005EFBF8[];
extern u8 D_005EFC08[];
extern s32 func_0014d470(u8 *);
extern void func_0014d4e0(u8 *);
extern void func_0014d830(u8 *, u8 *);
extern void func_0014da30(u8 *, u8 *);

// FUN_0014B5D0
f32 func_0014b5d0(const RwMatrix* matrix)
{
    RwMatrix normalized;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    return (-func_0044b950(normalized.right.z, normalized.right.x) * 180.0f) / gPI;
}

// FUN_0014B660
f32 func_0014b660(const RwMatrix* matrix)
{
    RwMatrix normalized;
    RwV3d* up;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    up = &normalized.up;
    return (-func_0044b950(up->z, up->y) * 180.0f) / gPI;
}

// FUN_0014B6F0
f32 func_0014b6f0(const RwMatrix* matrix)
{
    RwMatrix normalized;
    RwV3d* up;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    up = &normalized.up;
    return (func_0044b950(up->x, up->y) * 180.0f) / gPI;
}

// FUN_0014D510
s32 func_0014d510(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *buf;
    s32 ret;

    func_0044ea90(D_005EFBC8, 0x72);
    buf = D_008873F4[0](1, 0x114, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    ret = func_00451fc0(arg0, D_005EFBD8, 0xF, 0, 0, func_0014d470, func_0014d4e0, buf);
    *(s32 *)(buf + 0xC) = arg1;
    *(s32 *)(buf + 0x4) = 0x14;
    *(s32 *)(buf + 0x110) = arg2;
    return ret;
}

// FUN_0014D5E0
void func_0014d5e0(u8 *arg0, u32 arg1)
{
    *(u32 *) *(u8 **)(arg0 + 0x38) = arg1;
}

// FUN_0014D5F0
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d5f0);

// FUN_0014D620
void func_0014d620(u8 *arg0, u8 *arg1)
{
    func_004601c0(10.0f, arg1 + 4, arg1 + 0x10, 1);
}

// FUN_0014D660
s32 func_0014d660(u8 *arg0)
{
    u8 *work;
    u8 *obj;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)work == 0) {
        return 0;
    }
    obj = func_00460990();
    *(void **)(obj + 8) = func_0014d620;
    *(void **)(obj + 0x10) = work;
    func_00460ac0(*(void **)(work + 0x14), obj);
    return 0;
}

// FUN_0014D6D0
void func_0014d6d0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0014D700
s32 func_0014d700(s32 arg0, s32 arg1)
{
    u8 *buf;
    s32 ret;

    func_0044ea90(D_005EFBC8, 0x16E);
    buf = D_008873F4[0](1, 0x18, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    ret = func_00451fc0(arg0, D_005EFBE8, 0xF, 0, 0, func_0014d660, func_0014d6d0, buf);
    *(s32 *)(buf + 0x14) = arg1;
    return ret;
}

// FUN_0014D7C0
void func_0014d7c0(u8 *arg0, u32 arg1)
{
    *(u32 *) *(u8 **)(arg0 + 0x38) = arg1;
}

// FUN_0014D800
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d800);

// FUN_0014D830
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d830);

// FUN_0014D870
s32 func_0014d870(u8 *arg0)
{
    u8 *work;
    u8 *obj;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)work == 0) {
        return 0;
    }
    obj = func_00460990();
    *(void **)(obj + 8) = func_0014d830;
    *(void **)(obj + 0x10) = work;
    func_00460ac0(*(void **)(work + 0x18), obj);
    return 0;
}

// FUN_0014D8E0
void func_0014d8e0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0014D910
s32 func_0014d910(s32 arg0, s32 arg1)
{
    u8 *buf;
    s32 ret;

    func_0044ea90(D_005EFBC8, 0x1DF);
    buf = D_008873F4[0](1, 0x1C, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    ret = func_00451fc0(arg0, D_005EFBF8, 0xF, 0, 0, func_0014d870, func_0014d8e0, buf);
    *(s32 *)(buf + 0x18) = arg1;
    return ret;
}

// FUN_0014D9D0
void func_0014d9d0(u8 *arg0, u32 arg1)
{
    *(u32 *) *(u8 **)(arg0 + 0x38) = arg1;
}

// FUN_0014DA10
void func_0014da10(u8 *arg0, f32 arg1)
{
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x10) = arg1;
}

// FUN_0014DA20
void func_0014da20(u8 *arg0, f32 arg1)
{
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x14) = arg1;
}

// FUN_0014DA30
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014da30);

// FUN_0014DB10
s32 func_0014db10(u8 *arg0)
{
    u8 *work;
    u8 *obj;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(work + 0x44) == 0) {
        return 0;
    }
    obj = func_00460990();
    *(void **)(obj + 8) = func_0014da30;
    *(void **)(obj + 0x10) = work;
    func_00460ac0(*(void **)(work + 0x4C), obj);
    return 0;
}

// FUN_0014DB80
void func_0014db80(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0014DBB0
s32 func_0014dbb0(s32 arg0, s32 arg1)
{
    u8 *buf;
    s32 ret;

    func_0044ea90(D_005EFBC8, 0x30E);
    buf = D_008873F4[0](1, 0x50, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    ret = func_00451fc0(arg0, D_005EFC08, 0xF, 0, 0, func_0014db10, func_0014db80, buf);
    *(f32 *)(buf + 0x28) = 1.0f;
    *(f32 *)(buf + 0x14) = 1.0f;
    *(f32 *)(buf + 0x00) = 1.0f;
    *(s32 *)(buf + 0x10) = 0;
    *(s32 *)(buf + 0x08) = 0;
    *(s32 *)(buf + 0x04) = 0;
    *(s32 *)(buf + 0x24) = 0;
    *(s32 *)(buf + 0x20) = 0;
    *(s32 *)(buf + 0x18) = 0;
    *(s32 *)(buf + 0x38) = 0;
    *(s32 *)(buf + 0x34) = 0;
    *(s32 *)(buf + 0x30) = 0;
    *(s32 *)(buf + 0x0C) |= 0x20003;
    *(u8 *)(buf + 0x48) = 0xFF;
    *(u8 *)(buf + 0x49) = 0;
    *(u8 *)(buf + 0x4A) = 0;
    *(u8 *)(buf + 0x4B) = 0xFF;
    *(s32 *)(buf + 0x4C) = arg1;
    *(s32 *)(buf + 0x44) = 1;
    return ret;
}
