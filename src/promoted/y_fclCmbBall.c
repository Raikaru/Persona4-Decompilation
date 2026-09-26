#define FCL_COLOR_ARG u8
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_combine_internal.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
extern s32 func_0034ac00(u8 *task);
extern void func_0034ad40(u8 *task);
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclCmbBall.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void func_0044ea90(const void *, s32);
extern char D_0064A740[];
extern char D_0064A750[];
extern char D_0064A770[];
extern s32 func_0034b380(u8 *);
extern u8 *func_00461390(void *, s32, void *, s32);
extern f32 func_002b2aa0(s64, f32, f32, f32, f32);
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s32 func_002b2d00(s32, s32, s32, s32, s8);
extern u8 D_00793E80[];
extern void (*D_00887300[])(u32, u32);
extern s32 func_00457120(void);
extern s32 func_003315e0(void);
extern void RpSkyRenderStateSet(s32, s32);



// FUN_0034AD70
s32 func_0034ad70(s32 arg0, u8 arg1, s16 arg2) {
    s32 handle;
    u8 *buf;
    s32 i;

    func_0044ea90(&D_0064A740, 0x98);
    buf = (u8 *)D_008873F4[0](1, 0x1810, 0x40000);
    handle = (s32)func_00451fc0((void *)((void *)(arg0)), (const void *)(D_0064A750), 0xF, 0, 0, func_0034ac00, func_0034ad40, (u8 *)(buf));
    for (i = 0; i < 0xC; i++) {
        *(s16 *)(buf + (i << 9) + 0x104) = 0;
        *(s16 *)(buf + (i << 9) + 0x100) = arg2;
    }
    *(s8 *)(buf + 0x1800) = arg1;
    return handle;
}

// FUN_0034AE50
u8 *func_0034ae50(u8 *arg0, s8 arg1) {
    s32 off = arg1 * 0x200;

    return *(u8 **)(arg0 + 0x38) + off + 0x104;
}

/* The RenderWare globals block at D_008872E0 is read through a cast
   (RWSRCGLOBAL style); its open device's near screen Z sits at +0x18 and
   RenderStateSet at +0x20 (D_00887300).  Reading nearZ through the cast
   evaluates it before the 0xE14 depth, as retail does; a typed struct
   global loads it last.  opt_propagation off keeps &RenderStateSet in
   $s0, and loop invariants hoist only the %hi of the nearZ address. */
typedef struct {
    u8 unk00[0x18];
    f32 nearZ;
    f32 farZ;
} RenderDepth;
extern u8 D_008872E0[];

#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
// FUN_0034AE70
void func_0034ae70(u8 *arg0, u8 *arg1) {
    void (**setState)(u32, u32);
    s32 texture;
    f32 scale;
    FclDrawColor color;
    FclVec2 position;
    s16 i;
    s16 slot;

    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    texture = func_003315e0();
    setState = D_00887300;
    setState[0](6, 1);
    setState[0](7, 2);
    setState[0](8, 1);
    setState[0](9, 2);
    setState[0](0xC, 1);
    setState[0](2, 3);
    setState[0](0xB, 6);
    setState[0](0xA, 5);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x20) = 0;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x24) = 0;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x60) = 0x3F800000;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x64) = 0;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xA0) = 0;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xA4) = 0x3F800000;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xE0) = 0x3F800000;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xE4) = 0x3F800000;
    if (*(s8 *)(arg1 + 0xF00) == 1) {
        color = func_002b2a60(0x2D, 0x2D, 0x2D, *(u8 *)(arg1 + 0xE6E));
    } else {
        color = func_002b2a60(0, 0, 0x66, *(u8 *)(arg1 + 0xE6E));
        if (*(s16 *)(arg1 + 2) >= 3) {
            color = func_002b2a60(0xCC, 0xFF, 0xFF, (u32)*(u8 *)(arg1 + 0xE6E) >> 1);
        }
    }
    for (i = 0; i < 4; i++) {
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x18) = ((RenderDepth *)D_008872E0)->nearZ - *(f32 *)(arg1 + 0xE14);
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x28) = scale;
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x30) = color.c0;
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x34) = color.c1;
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x38) = color.c2;
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x3C) = color.c3;
    }
    position = *(FclVec2 *)(arg1 + 0xE38);
    slot = *(s16 *)(arg1 + 2);
    position.x += slot * 19;
    if (slot >= 3) {
        position.x += 12.0f;
    }
    *(f32 *)((slot << 8) + (u32)arg1 + 0x10) = position.x;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x14) = position.y;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x50) = 16.0f + position.x;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x54) = position.y;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x90) = position.x;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x94) = 16.0f + position.y;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xD0) = 16.0f + position.x;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xD4) = 16.0f + position.y;
    (*setState)(1, *(u32 *)texture);
    *(s16 *)(arg1 + 2) += 1;
}
#pragma pop

/* Recovered target body: the retail flag gates, staged interpolation, and
   0xE-entry packet loop are represented directly. The first interpolation
   call passes E72 as its signed integer mode and E6C/E6D/E6A/E68 as floats;
   the second uses signed E68 / 2 (C division supplies retail's correction
   sequence). The bounded update is func_002b2cb0(E6A, 1, E68, 0, 1).
   The plain u8 result cast preserves retail's float-to-u8 saturation path. */
/* Target window: 0x390 bytes; the compiled owner image is 0x384 bytes and
   its remaining 12 target bytes are zero padding. */
/* func_0034b380 -- reconstructed from the complete retail, Ghidra, and IDA
   bodies; all six owner images and all target relocations are checked. */
extern void func_0034ae70(u8 *, u8 *);

// FUN_0034B380
s32 func_0034b380(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((*(s16 *)(p + 0xE10) & 1) == 0) {
        return 0;
    }

    if (((*(s16 *)(p + 0xE10) & 4) >> 2) == 1) {
        if (*(s16 *)(p + 0xE70) == 0) {
            if (*(s8 *)(p + 0xE73) == 0) {
                *(u8 *)(p + 0xE6E) =
                    (u8)func_002b2aa0((s32)*(s8 *)(p + 0xE72),
                                           (f32)*(u8 *)(p + 0xE6C),
                                           (f32)*(u8 *)(p + 0xE6D),
                                           (f32)(s16)*(s16 *)(p + 0xE6A),
                                           (f32)(s16)*(s16 *)(p + 0xE68));
            } else {
                *(u8 *)(p + 0xE6E) =
                    (u8)func_002b2aa0((s32)*(s8 *)(p + 0xE72),
                                           (f32)*(u8 *)(p + 0xE6C),
                                           (f32)*(u8 *)(p + 0xE6D),
                                           (f32)(s16)*(s16 *)(p + 0xE6A),
                                           (f32)(*(s16 *)(p + 0xE68) / 2));
            }
            if (*(s16 *)(p + 0xE6A) < *(s16 *)(p + 0xE68)) {
                *(s16 *)(p + 0xE6A) =
                    func_002b2cb0(*(s16 *)(p + 0xE6A), 1,
                                  *(s16 *)(p + 0xE68), 0, 1);
            } else {
                *(u8 *)(p + 0xE6E) = *(u8 *)(p + 0xE6D);
                if (*(s8 *)(p + 0xE73) == 1) {
                    *(u8 *)(p + 0xE6E) = *(u8 *)(p + 0xE6C);
                }
                *(s16 *)(p + 0xE10) = *(s16 *)(p + 0xE10) | 4;
            }
        } else {
            *(s16 *)(p + 0xE70) = func_002b2d00(*(s16 *)(p + 0xE70), 1, 0, 0, 1);
        }
    }

    if (*(u8 *)(p + 0xE6E) <= 0) {
        return 0;
    }

    *(s16 *)(p + 2) = 0;
    {
        s16 i;

        for (i = 0; i < 0xE; i++) {
            u8 *q = (u8 *)func_00461390(D_00793E80 + *(s16 *)p * 0x30, 4,
                                        p + i * 0x100 + 0x10, 4);
            *(void **)(q + 8) = (void *)func_0034ae70;
            *(u8 **)(q + 0x10) = p;
        }
    }
    return 0;
}
// FUN_0034B710
void func_0034b710(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0034B740
s32 func_0034b740(s32 arg0) {
    s32 handle;
    u8 *buf;
    s16 i;

    func_0044ea90(&D_0064A740, 0x14D);
    buf = (u8 *)D_008873F4[0](1, 0xF10, 0x40000);
    handle = (s32)func_00451fc0((void *)((void *)(arg0)), (const void *)(D_0064A770), 0xF, 0, 0, func_0034b380, func_0034b710, (u8 *)(buf));
    i = 0;
    *(s16 *)(buf + 0xE10) = 0;
    while (i < 0xE) {
        i++;
    }
    *(s16 *)(buf + 0) = 0x41;
    return handle;
}
