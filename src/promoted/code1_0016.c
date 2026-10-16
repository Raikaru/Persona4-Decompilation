#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "Kosaka/k_model_internal.h"

typedef struct RwMatrix RwMatrix;

extern s32 iGpffff9ef8;
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern void K_View_SetFov(void *arg0, f32 arg1);
extern void FldCameraAdvanceCurve();
extern s32 iGpffff9f08;

extern s32* MT_Scene_GetFrameState(void);
extern void (*DAT_008873EC[])(void *);
extern u8 D_007EF9B0[];
extern u8 D_007F16F0[];
extern u8 D_007E4320[];
extern u8 D_007F16F2[];
extern u8 D_007F16F4[];
extern void mdlDestroyModelObject();
extern u8 D_007E8C00[];
extern void strcpy(void *arg0, const char *arg1);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 H_Cdvd_FileExists(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2, ...);
extern u8 *H_Cdvd_AcquireDirectory(void *arg0, s32 arg1);
extern char D_005F1218[];
extern char D_005F1230[];
extern char D_005F1248[];
extern void memset(void *dst, s32 value, u32 size);
extern s32 iGpffffb2e8;
extern s32 iGpffffb2e4;
extern s32 iGpffffb2e0;
extern u8 D_007E8BE0[];
extern u8 D_007E8BE8[];
extern u8 D_007E8BF8[];
extern u8 D_007E80A0[];
extern u8 D_007E8060[];
extern u8 D_007E8020[];
extern u8 *iGpffffb2b0;
extern s32 iGpffffb2b8;
extern s32 D_007643A4;
extern s32 D_007643AC;
extern f32 D_007643B0;
extern f32 D_007643B4;
extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern u8 D_007943C0[];
extern u8 D_00794960[];
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern void (*D_00887300[])(u32, u32);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void chkmemAllocSiteTag(const void *msg, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void H_Cdvd_ReadSync(void *arg0);
extern void memcpy(void *dst, void *src, u32 size);
extern void H_Cdvd_Destroy(void *arg0);
extern u8 *kwlnGetCamera();
extern void func_003e9d50(u8 *arg0, void *arg1, f32 arg2, s32 arg3);
extern void K_ClumpLookAtBasis(u8 *arg0, void *arg1, void *arg2, s32 arg3);
extern void RwMatrixTranslate(void *arg0, void *arg1, s32 arg2);
extern void func_003e0e20(void *arg0, void *arg1, s32 arg2);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern u8 *func_003e9700(s32 arg0);
extern f32 D_007F1730[];

extern u8 D_005F16C8[];
extern u8 D_005F16D0[];

extern u8 D_007EF9F8[];
extern u8 D_007EFA00[];
extern u8 D_005F1698[];
extern u8 D_005F16E0[];
extern char D_005F16B0[];
extern u8 D_007948D0[];
extern void *func_003e9320(void);
extern void func_003e9df0(void *arg0);
extern s32 func_003e0f80(void);
extern s32 FldCameraTaskUpdate(u8 *task);
extern s32 KDraw_CreateGroupTask(s32 arg0, s32 arg1, void *arg2);
extern s32 KDraw_CreateSphereTask(s32 arg0, void *arg1);
extern s32 KDraw_CreateCylinderTask(s32 arg0, void *arg1);
extern void KDraw_SetSphereColor(void *arg0, void *arg1);
extern f32 fabsf(f32 x);
extern f32 KDraw_MatrixYawDeg(u8 *arg0);
extern f32 K_View_GetFov(u8 *arg0);
extern void K_FldFilter_InitQuads(u8 *arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *iGpffffb2c8;
extern u8 *iGpffffb2cc;
extern u8 D_007E7B20[];
extern u8 *mdlGetMatrix();
extern void mdlScale(void *arg0, void *arg1, s32 arg2);
extern u8 D_005F12E0[];
extern u8 D_005F15F8[];
extern u8 D_005F1630[];
extern u8 D_005F1610[];
extern u8 D_007F00D8[];
extern u8 D_007E9328[];
extern s32 FldFrameTask_Update(u8 *arg0);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern void mdlAdvanceModelFromFlags(s32 arg0);
extern s32 iGpffff9f00;
extern void func_003e99a0(void *arg0);
extern void func_003e9390(void *arg0);
extern void func_003e9830(s32 arg0, s32 arg1);
extern void func_003e0f40(s32 arg0);
extern char D_005F11E8[];
extern char D_005F1200[];
extern s32 iGpffff9f08;
extern u8 *iGpffff9db0;
extern s32 datGetFlag();
extern s32 FldStepIndex();
extern s32 FldDayEventActive();
extern s32 FldRoomIsListed(u16 arg0, u16 arg1);
extern s16 datGetPartyId(s32 arg0);
extern s64 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s32 arg0);
extern s32 calIsCurrentMonthDay(s32 arg0, s32 arg1, s32 arg2);
extern s32 datGetTimeSlot(void);
extern s32 calGetDayEntryByPhase(s16 arg0, s32 arg1);
extern s32 D_005F1350[];
extern void mdlSetColor(void *arg0, void *arg1);
extern void mdlSetLookAtRequested(void *arg0);
extern void mdlAttachSlotModelFromResource(void *arg0, u16 arg1, u32 arg2, u16 arg3,
                           void *arg4, u32 arg5);
extern void mdlSetAttachedSlotValue(u8 *arg0, u16 arg1, s32 arg2);
extern u8 iGpffff9f10;
extern u8 D_005F13A0[];


typedef struct F8060Frame
{
    RwV3d sp50;
    RwV3d sp5c;
    u8 pad68[8];
    RwV3d sp70;
    u8 pad7c[4];
    RwV3d sp80;
    u8 pad8c[4];
    RwV3d sp90;
} F8060Frame;

extern s32 FldMap_IsCurrentInBandA(void);
extern s32 FldFrame_RaycastFieldWorlds(RwV3d *arg0, RwV3d *arg1, f32 fparg0,
                         u16 arg2);
extern void FldAmbientTrigger(s32 arg0, u16 arg1, u16 arg2);


typedef struct E8E0Frame
{
    s64 sp30;
    f32 sp38;
    u8 pad3c[4];
    u8 sp40[12];
    u8 pad4c[4];
    RwV3d sp50;
} E8E0Frame;
typedef struct EEE0Frame
{
    s64 sp40;
    f32 sp48;
    u8 pad4c[4];
    u8 sp50[12];
    u8 pad5c[4];
    RwV3d sp60;
    u8 pad6c[4];
    s64 sp70;
    f32 sp78;
    u8 pad7c[4];
    u8 sp80[12];
    u8 pad8c[4];
    RwV3d sp90;
} EEE0Frame;
extern f32 sinf(f32 arg0);
extern f32 iGpffff8094;

extern s32 RwEngineGetMatrixTolerances(RwV3d *arg0);
extern void RwMatrixOptimize(u8 *arg0, RwV3d *arg1);
extern void RwMatrixUpdate(u8 *arg0);


typedef signed __int128 s128;

typedef struct F630Frame
{
    u8 work[0x40];
    f32 sp80;
    s16 sp84;
    u8 pad86[2];
    f32 sp88;
    f32 sp8c;
    f32 sp90;
    f32 sp94;
    f32 sp98;
    f32 sp9c;
    f32 spa0;
    f32 spa4;
    f32 spa8;
    u32 reserved6c; /* Cleared and copied with the seven-quadword snapshot. */
} __attribute__((aligned(16))) F630Frame;
static inline f32 code1_0016_cvt(s32 value) {
    return (f32)value;
}

extern void FldEventSnapshotCapture(FldEventSnapshot *arg0, u8 *arg1);
// FUN_00160440
void func_00160440(void)
{
    if (*(s32 *)((u8 *)((u8*)MT_Scene_GetFrameState()) + 0x1854) != 0) {
        (*DAT_008873EC)(*(void **)((u8 *)((u8*)MT_Scene_GetFrameState()) + 0x1854));
        *(s32 *)((u8 *)((u8*)MT_Scene_GetFrameState()) + 0x1854) = 0;
    }
}


/* Build a 7-by-8 grid of 80-by-64 quads, snapshotting depth before any stores.
   measured: natural vertex assignment order, invariant hoisting and disabled
   propagation preserve retail's coordinate preparation and float registers.
   Object 252B/window 256B; exact instructions and a four-byte zero tail. */
#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_001604A0
void K_FldFilter_InitQuads(u8 *arg0)
{
    f32 depth = *(f32 *)(arg0 + 0x80);
    f32 inv = 1.0f / depth;
    s32 i;
    s32 j;
    u8 *row;
    u8 *p;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    s32 x;
    s32 top_y;
    s32 bottom_y;

    for (i = 0; i < 7; i++) {
        j = 0;
        row = D_007E4320 + (i << 11);
        while (j < 8) {
            x = (j * 5) << 4;
            p = row + (j << 8);
            left = (f32)x;
            *(f32 *)(p + 0) = left;
            top_y = i << 6;
            bottom_y = top_y + 64;
            top = (f32)top_y;
            *(f32 *)(p + 4) = top;
            *(f32 *)(p + 8) = depth;
            j++;
            right = (f32)((j * 5) << 4);
            *(f32 *)(p + 64) = right;
            *(f32 *)(p + 68) = top;
            *(f32 *)(p + 72) = depth;
            *(f32 *)(p + 128) = left;
            bottom = (f32)bottom_y;
            *(f32 *)(p + 132) = bottom;
            *(f32 *)(p + 136) = depth;
            *(f32 *)(p + 192) = right;
            *(f32 *)(p + 196) = bottom;
            *(f32 *)(p + 200) = depth;
            *(f32 *)(p + 24) = inv;
            *(f32 *)(p + 88) = inv;
            *(f32 *)(p + 152) = inv;
            *(f32 *)(p + 216) = inv;
        }
    }
}
/* measured: restore propagation and invariant baselines after the exact grid. */
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_001605A0
void FldFilterLoadFile(void)
{
    u8 *temp_2;

    if (iGpffffb2b0 == NULL) {
        chkmemAllocSiteTag(D_005F11E8, 0xEE);
        iGpffffb2b0 = (u8 *)D_008873F4[0](1, 0x12400, 0x40000);
    }
    func_00440b68((char *)&iGpffff9f00, D_005F11E8, 0xF4);
    temp_2 = H_Cdvd_AcquireDirectory(D_005F1200, 0);
    H_Cdvd_ReadSync(temp_2);
    memcpy(iGpffffb2b0, *(void **)(temp_2 + 0x110), 0x12400);
    H_Cdvd_Destroy(temp_2);
    K_FldFilter_InitQuads(kwlnGetCamera());
}
/* measured: retail hoists the D_00887300 base into a saved local across
   five indirect calls; opt_propagation off preserves that address materialization. */
// FUN_00160680
#pragma opt_propagation off
void FldFilterResetRenderState(void)
{
    s32 temp_5;
    void (**base)(u32, u32);

    base = D_00887300;
    base[0](6, 0);
    base[0](8, 0);
    base[0](7, 2);
    base[0](1, 0);
    base[0](0xC, 1);
    base[0](0xE, 0);
    RpSkyRenderStateSet(3, 0x71801);
    temp_5 = *(s32 *)(iGpffffb2b0 + iGpffffb2b8 * 0x124);
    switch (temp_5) {
    case 0:
        RpSkyRenderStateSet(2, 0x44);
        break;
    case 1:
        RpSkyRenderStateSet(2, 0x48);
        break;
    case 2:
        RpSkyRenderStateSet(2, 0x42);
        break;
    case 3:
        RpSkyRenderStateSet(2, 6);
        break;
    }
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves the render-state table base across calls. */
#pragma opt_propagation off
// FUN_001607E0
void FldFilterApplyColour(void)
{
    u32 color;
    void (**base)(u32, u32);

    if (iGpffffba48 == 1) {
        base = D_00887300;
        base[0](0xE, 1);
        color = ((u32)iGpffffba58 << 24) |
                ((u32)iGpffffba4c << 16) |
                ((u32)iGpffffba50 << 8) |
                (u32)iGpffffba54;
        base[0](0xF, color);
        base[0](0x10, 1);
    }
}
/* measured: closes the function-scoped opt_propagation probe. */
#pragma opt_propagation on
/* measured: 655wd via probe_variants (fnalign retail 760 vs object 779, +19 +2.5% inside 3% gate, 527 edits +8 reloc); opt_common_subs off 677->655 load-bearing; opt_loop_invariants on 677->699 regress, opt_unroll_loops off/schedule off tie at 677, direct subscript ((s32*)P)[j+N] 655->687 regress so materialized p=base+row+j*4 kept, decl swaps i/j and curOff/prevOff tie at 655; residual is saved-reg coloring + FPU lerp/madd ordering + lbu/sb scheduling, time-boxed per batch recipe. */
/* 2026-09-19: materialisation-surplus removal per assignment (over by 19): lui audit retail {0x3f80:3, 0x7e:1, 0x79:2, 0x16:2} vs object {0x3f80:6, 0:5} => +3 float 1.0f (blend<1.0f, 1.0f/D_007643B4, nb>1.0f, =1.0f, 1.0f-b, b<1.0f; retail keeps 1.0f in reg, CSE-off reloads each). Frame retail -0x1f0 vs object -0x200 (+16 from colsA+colsB both live). Removed #pragma opt_common_subs off/on (CSE on): fnalign retail 760 vs object 754 (-6, -0.8%; stripped 758 vs 754 -4), lui {0x3f80:3} exact, frame -0x1f0 exact, words 677 (+22), edits 518 +11 reloc. Count lands inside gate with surplus gone; words cost accepted per assignment. */
/* measured 00160880 (owner, 2026-09-19): fnalign **518 -> 516 edits**, count
   754 -> 752 against retail 758, by turning one constant-bound `for` loop into
   the `do { } while` retail emits.  A `for (i = <const>; i < <const>; i++)` compiles
   with a guard before the first iteration; retail has none, because the loop provably
   runs at least once and the original source said so.
   This is the same lever as the `loop_N:` goto sweep but reaches ordinary `for` loops,
   which that sweep could not see.  Across the 40 floors with the most constant-bound
   loops, 21 improved and 19 had no loop that helped - and only ONE loop per function
   was ever the right one, so each loop is measured separately rather than converting
   them all.
   2026-10-08: opt_lifetimes on lowers fnalign from 506 to 502 edits. */
/* 2026-10-09: a declaration-order hill climb (build/declclimb.py) lowers fnalign from 502 to 401 edits.
 * 2026-10-09: 401 -> 387: the colour buffers are cleared through a guarded
 * count-down byte loop (inline helper), as retail does.
 * 2026-10-09: 387 -> 383: body taken from the parallel cos/finish-first-party-20261009 worktree.
 * 379: range tests in retail's slti $at form.
 * 376: conversion lever (j:(0, 1)).
 * fnalign 376 -> 115: rewritten from retail: globals read at use (base per column, brightness after the four byte extractions, blend test and alpha re-read), per-word extraction order with the brightness adds after, i/j loops test-first, element pointers in the vertex loops.
 * j declared before i (retail i in $s0, j in $s1).
 * all clamps spelled `> 255` (retail tests through $at).
 * blend row offset uses (u32)j * 4 (retail recomputes it; the s32 form is CSE'd with the current row's).
 * current-row base held as an integer (u32) so the row offset is the first addu operand, as retail.
 * blend row reads the base word as u32 (retail reloads it there instead of reusing the current-row base).
 */
static inline void zeroBytes16_00160880(u8 *p)
{
    s32 n = 16;

    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
}

/* Keep the state-word read at the join after updating the previous state. */
static inline s32 previousStateValue_00160880(const s32 *state)
{
    return *state;
}

/* Matched full 759-instruction retail body.  The state accessor preserves the
 * read before the row-offset calculations across the branch join. */
#pragma push
#pragma opt_lifetimes on
// Intent: Advance the colour cross-fade from the previous state table to the current one by one step, writing blended vertex colours for seven rows of eight [inferred]
// FUN_00160880
void FldColorCrossfadeStep(void)
{
    s32 cur;
    s32 prev;
    f32 blend;
    f32 nb;
    f32 b;
    f32 inv;
    s32 curOff;
    s32 prevOff;
    s32 j;
    s32 i;
    s32 k;
    s32 r0;
    s32 g0;
    s32 b0;
    s32 a0;
    s32 r1;
    s32 g1;
    s32 b1;
    s32 a1;
    s32 r2;
    s32 g2;
    s32 b2;
    s32 a2;
    s32 r3;
    s32 g3;
    s32 b3;
    s32 a3;
    u8 colsA[16];
    u8 colsB[16];
    u8 *res;

    cur = iGpffffb2b8;
    if (cur == 0) {
        return;
    }
    blend = D_007643B0;
    if (blend < 1.0f) {
        nb = blend + 1.0f / D_007643B4;
        D_007643B0 = nb;
        if (nb > 1.0f) {
            D_007643B0 = 1.0f;
            D_007643AC = cur;
        }
    }
    prev = previousStateValue_00160880(&D_007643AC);
    b = D_007643B0;
    inv = 1.0f - b;
    i = 0;
    curOff = cur * 0x124;
    prevOff = prev * 0x124;
    for (; i < 7; i++) {
        s32 curRow;
        s32 prevRow;
        u8 *vtxRow;

        j = 0;
        curRow = curOff + i * 0x24;
        prevRow = prevOff + i * 0x24;
        vtxRow = D_007E4320 + (i << 11);
        for (; j < 8; j++) {
            u32 base = (u32)iGpffffb2b0;
            u8 *p = (u8 *)(curRow + base) + j * 4;
            s32 w;
            s32 bright;

            w = *(s32 *)(p + 4);
            r0 = w & 0xFF;
            g0 = (w >> 8) & 0xFF;
            b0 = (w >> 16) & 0xFF;
            a0 = (w >> 24) & 0xFF;
            w = *(s32 *)(p + 8);
            r1 = w & 0xFF;
            g1 = (w >> 8) & 0xFF;
            b1 = (w >> 16) & 0xFF;
            a1 = (w >> 24) & 0xFF;
            w = *(s32 *)(p + 0x2C);
            r2 = w & 0xFF;
            g2 = (w >> 8) & 0xFF;
            b2 = (w >> 16) & 0xFF;
            a2 = (w >> 24) & 0xFF;
            w = *(s32 *)(p + 0x28);
            r3 = w & 0xFF;
            g3 = (w >> 8) & 0xFF;
            b3 = (w >> 16) & 0xFF;
            a3 = (w >> 24) & 0xFF;
            bright = D_007643A4;
            a0 += bright;
            a1 += bright;
            a2 += bright;
            a3 += bright;
            if (a0 < 0) { a0 = 0; }
            if (a0 > 255) { a0 = 255; }
            if (a1 < 0) { a1 = 0; }
            if (a1 > 255) { a1 = 255; }
            if (a2 < 0) { a2 = 0; }
            if (a2 > 255) { a2 = 255; }
            if (D_007643B0 < 1.0f) {
                u8 *q = (u8 *)(prevRow + *(u32 *)&iGpffffb2b0) + (u32)j * 4;
                s32 sr0, sg0, sb0, sa0;
                s32 sr1, sg1, sb1, sa1;
                s32 sr2, sg2, sb2, sa2;
                s32 sr3, sg3, sb3, sa3;

                w = *(s32 *)(q + 4);
                sr0 = w & 0xFF;
                sg0 = (w >> 8) & 0xFF;
                sb0 = (w >> 16) & 0xFF;
                sa0 = (w >> 24) & 0xFF;
                w = *(s32 *)(q + 8);
                sr1 = w & 0xFF;
                sg1 = (w >> 8) & 0xFF;
                sb1 = (w >> 16) & 0xFF;
                sa1 = (w >> 24) & 0xFF;
                w = *(s32 *)(q + 0x2C);
                sr2 = w & 0xFF;
                sg2 = (w >> 8) & 0xFF;
                sb2 = (w >> 16) & 0xFF;
                sa2 = (w >> 24) & 0xFF;
                w = *(s32 *)(q + 0x28);
                sr3 = w & 0xFF;
                sg3 = (w >> 8) & 0xFF;
                sb3 = (w >> 16) & 0xFF;
                sa3 = (w >> 24) & 0xFF;
                bright = D_007643A4;
                sa0 += bright;
                sa1 += bright;
                sa2 += bright;
                sa3 += bright;
                if (sa0 < 0) { sa0 = 0; }
                if (sa0 > 255) { sa0 = 255; }
                if (sa1 < 0) { sa1 = 0; }
                if (sa1 > 255) { sa1 = 255; }
                if (sa2 < 0) { sa2 = 0; }
                if (sa2 > 255) { sa2 = 255; }
                r0 = (s32)((f32)r0 * b + (f32)sr0 * inv);
                g0 = (s32)((f32)g0 * b + (f32)sg0 * inv);
                b0 = (s32)((f32)b0 * b + (f32)sb0 * inv);
                a0 = (s32)((f32)a0 * b + (f32)sa0 * inv);
                r1 = (s32)((f32)r1 * b + (f32)sr1 * inv);
                g1 = (s32)((f32)g1 * b + (f32)sg1 * inv);
                b1 = (s32)((f32)b1 * b + (f32)sb1 * inv);
                a1 = (s32)((f32)a1 * b + (f32)sa1 * inv);
                r2 = (s32)((f32)r2 * b + (f32)sr2 * inv);
                g2 = (s32)((f32)g2 * b + (f32)sg2 * inv);
                b2 = (s32)((f32)b2 * b + (f32)sb2 * inv);
                a2 = (s32)((f32)a2 * b + (f32)sa2 * inv);
                r3 = (s32)((f32)r3 * b + (f32)sr3 * inv);
                g3 = (s32)((f32)g3 * b + (f32)sg3 * inv);
                b3 = (s32)((f32)b3 * b + (f32)sb3 * inv);
                a3 = (s32)((f32)a3 * b + (f32)sa3 * inv);
            }
            if (iGpffff9ef8 != 255) {
                r0 = r0 * iGpffff9ef8 / 255;
                g0 = g0 * iGpffff9ef8 / 255;
                b0 = b0 * iGpffff9ef8 / 255;
                a0 = a0 * iGpffff9ef8 / 255;
                r1 = r1 * iGpffff9ef8 / 255;
                g1 = g1 * iGpffff9ef8 / 255;
                b1 = b1 * iGpffff9ef8 / 255;
                a1 = a1 * iGpffff9ef8 / 255;
                r2 = r2 * iGpffff9ef8 / 255;
                g2 = g2 * iGpffff9ef8 / 255;
                b2 = b2 * iGpffff9ef8 / 255;
                a2 = a2 * iGpffff9ef8 / 255;
                r3 = r3 * iGpffff9ef8 / 255;
                g3 = g3 * iGpffff9ef8 / 255;
                b3 = b3 * iGpffff9ef8 / 255;
                a3 = a3 * iGpffff9ef8 / 255;
            }
            if (*(s32 *)(curOff + base) == 3) {
                u8 *vtx;

                zeroBytes16_00160880(colsA);
                colsA[0] = (u8)r0;
                colsA[1] = (u8)g0;
                colsA[2] = (u8)b0;
                colsA[3] = (u8)a0;
                colsA[4] = (u8)r1;
                colsA[5] = (u8)g1;
                colsA[6] = (u8)b1;
                colsA[7] = (u8)a1;
                colsA[8] = (u8)r3;
                colsA[9] = (u8)g3;
                colsA[10] = (u8)b3;
                colsA[11] = (u8)a3;
                colsA[12] = (u8)r2;
                colsA[13] = (u8)g2;
                colsA[14] = (u8)b2;
                colsA[15] = (u8)a2;
                k = 0;
                vtx = vtxRow + (j << 8);
                for (; k < 4; k++) {
                    u8 *c = &colsA[k * 4];
                    u8 *v = vtx + (k << 6);

                    *(f32 *)(v + 0x20) = (f32)c[0];
                    *(f32 *)(v + 0x24) = (f32)c[1];
                    *(f32 *)(v + 0x28) = (f32)c[2];
                    *(f32 *)(v + 0x2C) = (f32)c[3];
                }
                res = PrimQueueDrawPrimitive(D_007943C0, 4, vtx, 4);
            } else {
                u8 *vtx;

                zeroBytes16_00160880(colsB);
                colsB[0] = (u8)r0;
                colsB[1] = (u8)g0;
                colsB[2] = (u8)b0;
                colsB[3] = (u8)a0;
                colsB[4] = (u8)r1;
                colsB[5] = (u8)g1;
                colsB[6] = (u8)b1;
                colsB[7] = (u8)a1;
                colsB[8] = (u8)r3;
                colsB[9] = (u8)g3;
                colsB[10] = (u8)b3;
                colsB[11] = (u8)a3;
                colsB[12] = (u8)r2;
                colsB[13] = (u8)g2;
                colsB[14] = (u8)b2;
                colsB[15] = (u8)a2;
                k = 0;
                vtx = vtxRow + (j << 8);
                for (; k < 4; k++) {
                    u8 *c = &colsB[k * 4];
                    u8 *v = vtx + (k << 6);

                    *(f32 *)(v + 0x20) = (f32)c[0];
                    *(f32 *)(v + 0x24) = (f32)c[1];
                    *(f32 *)(v + 0x28) = (f32)c[2];
                    *(f32 *)(v + 0x2C) = (f32)c[3];
                }
                res = PrimQueueDrawPrimitive(D_00794960, 4, vtx, 4);
            }
            if ((j == 0) && (i == 0)) {
                *(void **)(res + 8) = (void *)FldFilterResetRenderState;
                *(s32 *)(res + 16) = 0;
            }
            if ((j == 7) && (i == 6) && (*(s32 *)(iGpffffb2b0 + iGpffffb2b8 * 0x124) == 3)) {
                *(void **)(res + 12) = (void *)FldFilterApplyColour;
                *(s32 *)(res + 20) = 0;
            }
        }
    }
}
#pragma pop
// FUN_001614D0
s32 FldFilterGetEntry(void)
{
    return *(s32 *)(iGpffffb2b0 + iGpffffb2b8 * 0x124);
}
// FUN_00161500
void FldFilterSetIndex(s32 arg0)
{
    iGpffff9ef8 = arg0;
}

/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the 0x750 stride and exact table bases (nd 14 -> 0).
   Committed at nd 0. */

// FUN_00161510
s32 FldEnemyOpenTable(void)
{
    char sp90[0x80];
    char sp10[0x80];

    strcpy(sp90, D_005F1218);
    sprintf(sp10, D_005F1230);
    if (H_Cdvd_FileExists(sp10) == 0) {
        return 0;
    }
    func_00440b68((char *)&iGpffff9f08, D_005F1248, 0x69);
    return (s32)H_Cdvd_AcquireDirectory(sp10, 0);
}

/* measured: opt_propagation off probe for retail field-load order in FldEnemyLoadTable */
#pragma opt_propagation off
// FUN_001615A0
s32 FldEnemyLoadTable(u8 *arg0)
{
    void *src;
    u32 size;

    if (arg0 == NULL) {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded(arg0) == 0) {
        return 0;
    }
    iGpffffb2c8 = D_007E7B20;
    size = *(u32 *)(arg0 + 0x118);
    src = *(void **)(((u8 *)arg0 + size) - size + 0x110);
    memcpy(iGpffffb2c8, src, size);
    iGpffffb2cc = iGpffffb2c8 + 0x300;
    H_Cdvd_Destroy(arg0);
    return 1;
}
/* measured: opt_propagation on closes the FldEnemyLoadTable load-order probe */
#pragma opt_propagation on
// FUN_00162120
void FldStateTablesClear(void)
{
    memset(D_007F16F0, 0, 0x20);
    memset(D_007EF9B0, 0, 0x1D40);
    memset(D_007E8C00, 0, 0x6DB0);
    iGpffffb2e8 = 0;
    memset(D_007E8BE0, 0, 0x20);
    *(s32 *)D_007E8BE8 = -1;
    *(s32 *)D_007E8BF8 = -1;
    memset(D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    iGpffffb2e0 = 0;
    memset(D_007E8060, 0, 0x40);
    memset(D_007E8020, 0, 0x40);
}

/* measured: opt_propagation off preserves the retail recomputed index and live register set in FldPartyModelRelease. */
#pragma opt_propagation off
// FUN_00162200
void FldPartyModelRelease(s32 arg0) {
    s32 saved_arg0;
    s32 temp_18;
    s32 *temp_17;
    u8 *temp_16;
    u8 *temp_3;
    s32 var_6;

    saved_arg0 = arg0;
    if (*(s32 *)(D_007F16F4 + (arg0 * 8)) != 0) {
        var_6 = 0;
        temp_16 = D_007F16F0 + (arg0 * 8);
        goto loop_test;
loop_body:
        temp_3 = (u8 *)(*(s32 *)(temp_16 + 4) + (var_6 * 0xC));
        *(u8 *)(temp_3 + 0x28C) =
            (u8)(*(u8 *)(temp_3 + 0x28C) | 1);
        var_6 += 1;
loop_test:
        if (var_6 < 5) {
            goto loop_body;
        }
        temp_18 = saved_arg0 * 8;
        temp_17 = (s32 *)(D_007F16F4 + temp_18);
        mdlDestroyModelObject(*temp_17);
        *temp_17 = 0;
        *(s16 *)(temp_16 + 0) = 0;
        *(s16 *)(D_007F16F2 + temp_18) = 0;
    }
}
/* measured: closes the opt_propagation bracket for FldPartyModelRelease. */
#pragma opt_propagation on
/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the stride (nd 14 -> 0). */
// FUN_001622D0
#pragma opt_loop_invariants on
void FldSlotTablesReset(void) {
    s32 i = 0;
    s32 one = 1;
    s32 stride = 0x750;

    while (i < 4) {
        *(s32 *)(D_007EF9B0 + i * stride + 0x44) = one;
        *(s32 *)(D_007F16F0 + i * 8 + 4) = 0;
        *(s16 *)(D_007F16F0 + i * 8) = 0;
        *(s16 *)(D_007F16F0 + i * 8 + 2) = 0;
        i++;
    }
}
/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the stride (nd 14 -> 0). */
#pragma opt_loop_invariants off

// FUN_00162330
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *FldSlotFindFree(void) {
    u8 *r = NULL;
    s32 i = 0;
    u8 *e;

    while (i < 4) {
        e = D_007EF9B0 + i * 0x750;
        if (*(s32 *)(e + 0x48) == 0) {
            r = e;
            break;
        }
        i++;
    }
    return r;
}
/* measured: closes the loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off

// FUN_00162390
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *FldObjFindFree(void) {
    u8 *r = NULL;
    s32 i = 0;
    s32 stride = 0x750;
    u8 *e;

    while (i < 0xF) {
        e = D_007E8C00 + i * stride;
        if (*(s32 *)(e + 0x48) == 0) {
            r = e;
            break;
        }
        i++;
    }
    return r;
}
/* measured: closes the loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off

/* measured: optimization_level 1 reproduces FldDayEventActive's register coloring. */
#pragma optimization_level 1
// FUN_001623F0
s32 FldDayEventActive(void)
{
    u8 *temp_5;
    s32 temp_3;
    s32 var_17;
    s32 var_16;
    s16 temp_18;
    s32 temp_3_2;
    s32 var_2;
    u8 *temp_4;

    var_17 = 0;
    if (calIsCurrentMonthDay((s16)datGetDateIndex(), 3, 0x14) == 1) {
        return 0;
    }
    var_16 = 0;
    goto loop_test;
loop_body:
    temp_5 = iGpffff9db0;
    if ((*(s32 *)(temp_5 + 0) == temp_3) &&
        (*(s32 *)(temp_5 + 4) == *(s32 *)(temp_4 + 4))) {
        temp_18 = (s16)datGetDateIndex();
        temp_3_2 = (s8)calGetDayEntryByPhase(temp_18, datGetTimeSlot() & 0xFF);
        var_2 = temp_3_2 & 1;
        if ((temp_3_2 < 0) && (var_2 != 0)) {
            var_2 -= 2;
        }
        if (var_2 != 0) {
            var_17 = 1;
            goto done;
        }
    }
    var_16 += 1;
loop_test:
    temp_4 = (u8 *)D_005F1350 + (var_16 * 8);
    temp_3 = *(s32 *)(temp_4 + 0);
    if (temp_3 != -1) {
        goto loop_body;
    }
done:
    return var_17;
}
/* measured: restore baseline optimization level after FldDayEventActive. */
#pragma optimization_level 2
// FUN_00162510
s32 FldRoomIsListed(u16 arg0, u16 arg1)
{
    s32 result;

    result = 0;
    if (arg0 == 0x14) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x15) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x16) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x16) {
        if (arg1 == 2) {
            goto success;
        }
    }
    if (arg0 == 0x17) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x18) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x19) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x1A) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x1B) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x1C) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x1D) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 != 0x1E) {
        goto done;
    }
    if (arg1 != 2) {
        goto done;
    }
success:
    result = 1;
done:
    return result;
}
/* measured: MATCH (window 1456B). The slot-cache lookup is a static inline
   helper returning the object or NULL; each switch arm keeps its own copy
   of the refresh code with block-local `entry` and loop counter; the
   default arm narrows `member` into a u16. The cache stores a 16-bit
   type key; the constructor takes a separate integer model kind. */
static inline u8 *fldPartyModelCached(s32 slot, u16 type, u16 id)
{
    if (type == *(u16 *)(D_007F16F0 + slot * 8) && id == *(u16 *)(D_007F16F2 + slot * 8)) {
        return *(u8 **)(D_007F16F4 + slot * 8);
    }
    return NULL;
}

// FUN_00162680
u8 *FldPartyModelGet(u16 field, u16 room, s32 member)
{
    s32 i;
    u8 *obj;
    s32 slot;
    u16 type;
    u32 modelKind;
    u16 id;

    slot = 0;
    id = 0;
    for (i = 0; i < 3; i++) {
        if (member == datGetPartyId(i)) {
            slot = i + 1;
            break;
        }
    }
    switch (member) {
    case 1: {
        u8 *entry;

        if (FldRoomIsListed(field, room) == 1) {
            modelKind = type = 9;
            switch (calGetDayWindowFlags((s16)datGetDateIndex())) {
            case 0:
            case 2:
                id = 0x103;
                break;
            case 1:
            case 3:
                id = 0x102;
                break;
            }
        } else if (field == 0x44 && room == 1) {
            modelKind = type = 9;
            id = 0x100;
        } else if (FldStepIndex() != 0) {
            modelKind = type = 1;
            id = member;
        } else if ((field == 7 && room == 2) || (field == 7 && room == 3)) {
            modelKind = type = 9;
            switch (calGetDayWindowFlags((s16)datGetDateIndex())) {
            case 0:
                id = 0x10B;
                break;
            case 2:
                id = 0x10D;
                break;
            case 1:
                id = 0x10A;
                break;
            case 3:
                id = 0x10C;
                break;
            }
        } else {
            modelKind = type = 9;
            switch (calGetDayWindowFlags((s16)datGetDateIndex())) {
            case 0:
                id = 0x101;
                break;
            case 2:
                id = 0x105;
                break;
            case 1:
                id = 0x100;
                break;
            case 3:
                id = 0x104;
                break;
            }
        }
        obj = fldPartyModelCached(slot, type, id);
        entry = D_007F16F0 + slot * 8;
        if (obj == NULL) {
            obj = mdlFindOrCreateModelObject(modelKind, id, 0);
            if (type == 1) {
                mdlRunSetupCallback(obj);
            } else {
                mdlAttachSlotModelFromResource(obj, 0, 9, 0x163, D_005F13A0, 0);
                mdlSetAttachedSlotValue(obj, 0, 0x1F4);
            }
            if (*(u8 **)(D_007F16F4 + slot * 8) != NULL) {
                s32 j;

                for (j = 0; j < 5; j++) {
                    *(u8 *)(*(u8 **)(entry + 4) + j * 0xC + 0x28C) |= 1;
                }
                mdlDestroyModelObject(*(u8 **)(D_007F16F4 + slot * 8));
                *(u8 **)(D_007F16F4 + slot * 8) = NULL;
            }
            *(u8 **)(D_007F16F4 + slot * 8) = obj;
            *(u16 *)entry = *(u16 *)(obj + 0xD4);
            *(u16 *)(D_007F16F2 + slot * 8) = *(u16 *)(*(u8 **)(D_007F16F4 + slot * 8) + 0xD6);
        } else {
            mdlSetColor(obj, &iGpffff9f10);
            mdlSetLookAtRequested(obj);
        }
        break;
    }
    default: {
        u16 m = member;
        u8 *entry;

        obj = fldPartyModelCached(slot, 1, m);
        entry = D_007F16F0 + slot * 8;
        if (obj == NULL) {
            obj = mdlFindOrCreateModelObject(1, m, 0);
            mdlRunSetupCallback(obj);
            if (*(u8 **)(D_007F16F4 + slot * 8) != NULL) {
                s32 j;

                for (j = 0; j < 5; j++) {
                    *(u8 *)(*(u8 **)(entry + 4) + j * 0xC + 0x28C) |= 1;
                }
                mdlDestroyModelObject(*(u8 **)(D_007F16F4 + slot * 8));
                *(u8 **)(D_007F16F4 + slot * 8) = NULL;
            }
            *(u8 **)(D_007F16F4 + slot * 8) = obj;
            *(u16 *)entry = *(u16 *)(obj + 0xD4);
            *(u16 *)(D_007F16F2 + slot * 8) = *(u16 *)(*(u8 **)(D_007F16F4 + slot * 8) + 0xD6);
        } else {
            mdlSetColor(obj, &iGpffff9f10);
            mdlSetLookAtRequested(obj);
        }
        break;
    }
    }
    return obj;
}





#pragma opt_loop_invariants on
#pragma opt_loop_invariants off



typedef struct FldRaySelectionResource
{
    u32 flags;
    u32 unknown04;
    void *fallback;
    u32 unknown0c;
    u32 unknown10;
    void *preferred;
} FldRaySelectionResource;

static inline void fldRaySelectWorld(const FldRaySelectionResource *selected, void **destination)
{
    void *world = selected->preferred;
    if (world != NULL) {
        *destination = world;
        return;
    }
    *destination = selected->fallback;
}

#pragma push
#pragma optimization_level 3
#pragma schedule off
#pragma opt_loop_invariants off
#pragma opt_rotateloops off
#pragma tailcall off
#pragma opt_common_subs off
#pragma opt_decomposeaggregates off
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma opt_pulloutconstants off
#pragma pop
#pragma push
#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma pop

#pragma opt_propagation off
#pragma opt_propagation on






#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on

#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma push
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma pop
#pragma optimization_level 1
/* measured: restore baseline optimization level after FldEventSnapshotCapture. */
#pragma optimization_level 2

extern u16 D_008C024C[];
extern u8 D_008C025C[];
extern u8 D_008C025D[];
extern u8 D_008C025E[];
extern u8 D_008C025F[];
extern f32 fGpffff8300;
extern f32 func_0044b920(f32 arg0);
extern f32 sqrtf(f32 x);

