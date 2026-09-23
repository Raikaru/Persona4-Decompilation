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
extern f32 D_008872F8[];
extern u8 *func_00457120(void);
extern s32 *func_003315e0(void);
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

/* re-measured from scratch in correct tree (pwd source/Persona4-Decompilation):
   top 8 D_00887300[0] calls + 8 data stores match (typed base local +
   opt_propagation off twin 0014dd80 recipe; stores use index-first
   (idx<<8)+(u32)arg1, loop uses base-first (u32)arg1+(idx<<8) -- both
   byte-exact). Banked body measures 193 words via measure_guarded and 32
   edits (+2 reloc-only) via fnalign --candidate /var/tmp/ae70/saved.c.
   Residuals are floors: (1) 002b2a60 5th-arg lbu scheduling (call-arg order
   floor, insert+delete balanced); (2) loop D-base/counter $a0/$v1 swap +
   sub.s load order (tried decl/assign orders dptr/i both ways, varA/varB
   both 49 edits vs banked 32 -- register-coloring floor); (3) tail FPU
   allocation ($f1/$f0/$f2/$f3 rotation) + *p load scheduling (scheduling
   floor, opclass 0 surplus confirms no width/signedness defect). Prior
   hoist-floor note (obj 1028B/window 1296B, 67 words short) re-measured
   void -- stores rematerialise per store in retail, matching the banked
   spelling. */
/* 2026-09-19 (this lane): scoped `#pragma opt_common_subs off` around the
   function regresses 193 -> 250 (the byte-exact loop stores depend on load
   CSE; reverted). Surgical `arg1[0xE6E]` subscript for the shared 5th-arg
   lbu ties at 193 - the cross-branch CSE share is robust to spelling.
   Residual stands: lbu load-position x2, $a0/$v1 counter swap + float-reg
   colouring, tail sp50/sp54 stack spills (the 5-instruction frame gap). */
// FUN_0034AE70 NONMATCHING
#ifdef NON_MATCHING
/* measured: opt_propagation off keeps the single lui/addiu D_00887300 hoist
   in $s0 (twin 0014dd80 recipe); without it each call rematerialises lui+lw. */
#pragma opt_propagation off
void func_0034ae70(u8 *arg0, u8 *arg1) {
    void (**base)(u32, u32);
    s32 *p;
    f32 scale;
    u8 colors[4];
    f32 sp50;
    f32 sp54;
    f32 *dptr;
    s16 i;
    (void)arg0;
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    p = func_003315e0();
    base = D_00887300;
    base[0](6, 1);
    base[0](7, 2);
    base[0](8, 1);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](2, 3);
    base[0](0xB, 6);
    base[0](0xA, 5);
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
        fclWriteColorBytes(colors, 0x2D, 0x2D, 0x2D, *(u8 *)(arg1 + 0xE6E));
    } else {
        fclWriteColorBytes(colors, 0, 0, 0x66, *(u8 *)(arg1 + 0xE6E));
        if (*(s16 *)(arg1 + 2) >= 3) {
            fclWriteColorBytes(colors, 0xCC, 0xFF, 0xFF, (u8)((u32)*(u8 *)(arg1 + 0xE6E) >> 1));
        }
    }
    i = 0;
    dptr = D_008872F8;
    goto loop_test;
loop_body:
    *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + (s32)i * 64 + 0x18) = *dptr - *(f32 *)(arg1 + 0xE14);
    *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + (s32)i * 64 + 0x28) = scale;
    *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + (s32)i * 64 + 0x30) = (f32)(u32)colors[0];
    *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + (s32)i * 64 + 0x34) = (f32)(u32)colors[1];
    *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + (s32)i * 64 + 0x38) = (f32)(u32)colors[2];
    *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + (s32)i * 64 + 0x3C) = (f32)(u32)colors[3];
    i++;
loop_test:
    if (i < 4) {
        goto loop_body;
    }
    {
        s16 idx = *(s16 *)(arg1 + 2);
        sp50 = *(f32 *)(arg1 + 0xE38);
        sp54 = *(f32 *)(arg1 + 0xE3C);
        sp50 = sp50 + (f32)(idx * 19);
        if (idx >= 3) {
            sp50 = sp50 + 12.0f;
        }
        *(f32 *)((idx << 8) + (u32)arg1 + 0x10) = sp50;
        *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x14) = sp54;
        *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x50) = 16.0f + sp50;
        *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x54) = sp54;
        *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x90) = sp50;
        *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x94) = 16.0f + sp54;
        *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xD0) = 16.0f + sp50;
        *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xD4) = 16.0f + sp54;
    }
    base[0](1, *p);
    *(s16 *)(arg1 + 2) = *(s16 *)(arg1 + 2) + 1;
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCmbBall", func_0034ae70);
#endif

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
