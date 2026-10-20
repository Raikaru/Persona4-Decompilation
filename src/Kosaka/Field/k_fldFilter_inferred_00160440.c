/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Kosaka/Field/k_fldFilter.c; members 00160440-00160880 */

#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "field_frame_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw_camera_internal.h"
#include "h_cdvd_request_internal.h"
#include "primitive_queue_internal.h"
#include "Kosaka/k_fldFilter_internal.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "Kosaka/k_model_internal.h"
extern s32 iGpffff9ef8;
extern s32* MT_Scene_GetFrameState(void);
extern void (*DAT_008873EC[])(void *);
extern u8 D_007E4320[];
extern void func_00440b68(char *, const char *, s32 , ...);
extern u8 *H_Cdvd_AcquireDirectory(void *, s32 );
extern u8 *iGpffffb2b0;
extern s32 iGpffffb2b8;
extern s32 D_007643A4;
extern s32 D_007643AC;
extern f32 D_007643B0;
extern f32 D_007643B4;
extern u8 *PrimQueueDrawPrimitive(void *, s32 , void *, s32 );
extern u8 D_007943C0[];
extern u8 D_00794960[];
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern void (*D_00887300[])(u32, u32);
extern void RpSkyRenderStateSet(s32 , s32 );
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void H_Cdvd_ReadSync(void *);
extern void memcpy(void *dst, void *src, u32 size);
extern void H_Cdvd_Destroy(void *);
extern u8 *kwlnGetCamera();
extern void K_FldFilter_InitQuads(u8 *);
extern s32 iGpffff9f00;
extern char D_005F11E8[];
extern char D_005F1200[];
/* Release and clear the frame-owned auxiliary script buffer. */
// FUN_00160440
void FldAuxBufferRelease(void)
{
    if (((FldFrame *)MT_Scene_GetFrameState())->auxBuffer != 0) {
        (*DAT_008873EC)(((FldFrame *)MT_Scene_GetFrameState())->auxBuffer);
        ((FldFrame *)MT_Scene_GetFrameState())->auxBuffer = 0;
    }
}

#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
/* Initialize the seven-by-eight screen grid of four-vertex filter quads. */
/* Quad depth is captured from the camera near plane before any vertex store. */
// FUN_001604A0
void K_FldFilter_InitQuads(u8 *camera)
{
    f32 depth = ((RwCamera *)(camera))->nearPlane;
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
    s32 topY;
    s32 bottomY;

    for (i = 0; i < 7; i++) {
        j = 0;
        row = D_007E4320 + (i << 11);
        while (j < 8) {
            x = (j * 5) << 4;
            p = row + (j << 8);
            left = (f32)x;
            ((FldFilterVertex *)p)[0].x = left;
            topY = i << 6;
            bottomY = topY + 64;
            top = (f32)topY;
            ((FldFilterVertex *)p)[0].y = top;
            ((FldFilterVertex *)p)[0].z = depth;
            j++;
            right = (f32)((j * 5) << 4);
            ((FldFilterVertex *)p)[1].x = right;
            ((FldFilterVertex *)p)[1].y = top;
            ((FldFilterVertex *)p)[1].z = depth;
            ((FldFilterVertex *)p)[2].x = left;
            bottom = (f32)bottomY;
            ((FldFilterVertex *)p)[2].y = bottom;
            ((FldFilterVertex *)p)[2].z = depth;
            ((FldFilterVertex *)p)[3].x = right;
            ((FldFilterVertex *)p)[3].y = bottom;
            ((FldFilterVertex *)p)[3].z = depth;
            ((FldFilterVertex *)p)[0].reciprocalDepth = inv;
            ((FldFilterVertex *)p)[1].reciprocalDepth = inv;
            ((FldFilterVertex *)p)[2].reciprocalDepth = inv;
            ((FldFilterVertex *)p)[3].reciprocalDepth = inv;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Load the complete filter table and initialize its screen-space quad geometry. */
/* The CDVD request's +0x110 word is the loaded file buffer, not a filter-entry field. */
// FUN_001605A0
void FldFilterLoadFile(void)
{
    u8 *file;

    if (iGpffffb2b0 == NULL) {
        chkmemAllocSiteTag(D_005F11E8, 0xEE);
        iGpffffb2b0 = (u8 *)D_008873F4[0](1, 0x12400, 0x40000);
    }
    func_00440b68((char *)&iGpffff9f00, D_005F11E8, 0xF4);
    file = H_Cdvd_AcquireDirectory(D_005F1200, 0);
    H_Cdvd_ReadSync(file);
    memcpy(iGpffffb2b0, ((HCdvdRequest *)(file))->data, 0x12400);
    H_Cdvd_Destroy(file);
    K_FldFilter_InitQuads(kwlnGetCamera());
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Set the filter draw states and choose the GS alpha mode from the active table entry. */
// FUN_00160680
#pragma opt_propagation off
void FldFilterResetRenderState(void)
{
    s32 filterType;
    void (**base)(u32, u32);

    base = D_00887300;
    base[0](6, 0);
    base[0](8, 0);
    base[0](7, 2);
    base[0](1, 0);
    base[0](0xC, 1);
    base[0](0xE, 0);
    RpSkyRenderStateSet(3, 0x71801);
    filterType = (s32)((FldFilterEntry *)(iGpffffb2b0 + iGpffffb2b8 * 0x124))->type;
    switch (filterType) {
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
/* Apply the packed environment color when environment-color rendering is enabled. */
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
#pragma pop

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

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_lifetimes on
// Intent: Advance the colour cross-fade from the previous state table to the current one by one step, writing blended vertex colours for seven rows of eight [inferred]
/* Current/previous cursors advance one packed color per column and 0x24 bytes per row.
 * Their colors[0..1][0..1] fields therefore select the four corners at (i, j). */
// FUN_00160880
void FldColorCrossfadeStep(void)
{
    FldFilterEntry *currentColors;
    FldFilterEntry *previousColors;
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

            currentColors = (FldFilterEntry *)p;
    w = (s32)currentColors->colors[0][0];
            r0 = w & 0xFF;
            g0 = (w >> 8) & 0xFF;
            b0 = (w >> 16) & 0xFF;
            a0 = (w >> 24) & 0xFF;

    w = (s32)currentColors->colors[0][1];
            r1 = w & 0xFF;
            g1 = (w >> 8) & 0xFF;
            b1 = (w >> 16) & 0xFF;
            a1 = (w >> 24) & 0xFF;

    w = (s32)currentColors->colors[1][1];
            r2 = w & 0xFF;
            g2 = (w >> 8) & 0xFF;
            b2 = (w >> 16) & 0xFF;
            a2 = (w >> 24) & 0xFF;

    w = (s32)currentColors->colors[1][0];
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

                previousColors = (FldFilterEntry *)q;
    w = (s32)previousColors->colors[0][0];
                sr0 = w & 0xFF;
                sg0 = (w >> 8) & 0xFF;
                sb0 = (w >> 16) & 0xFF;
                sa0 = (w >> 24) & 0xFF;

    w = (s32)previousColors->colors[0][1];
                sr1 = w & 0xFF;
                sg1 = (w >> 8) & 0xFF;
                sb1 = (w >> 16) & 0xFF;
                sa1 = (w >> 24) & 0xFF;

    w = (s32)previousColors->colors[1][1];
                sr2 = w & 0xFF;
                sg2 = (w >> 8) & 0xFF;
                sb2 = (w >> 16) & 0xFF;
                sa2 = (w >> 24) & 0xFF;

    w = (s32)previousColors->colors[1][0];
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
            if ((s32)((FldFilterEntry *)(curOff + base))[0].type == 3) {
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

                    ((FldFilterVertex *)v)[0].red = (f32)c[0];
                    ((FldFilterVertex *)v)[0].green = (f32)c[1];
                    ((FldFilterVertex *)v)[0].blue = (f32)c[2];
                    ((FldFilterVertex *)v)[0].alpha = (f32)c[3];
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

                    ((FldFilterVertex *)v)[0].red = (f32)c[0];
                    ((FldFilterVertex *)v)[0].green = (f32)c[1];
                    ((FldFilterVertex *)v)[0].blue = (f32)c[2];
                    ((FldFilterVertex *)v)[0].alpha = (f32)c[3];
                }
                res = PrimQueueDrawPrimitive(D_00794960, 4, vtx, 4);
            }
            if ((j == 0) && (i == 0)) {
                ((PrimQueueDrawNode *)(res))->begin.callback = (void *)FldFilterResetRenderState;
                ((PrimQueueDrawNode *)(res))->begin.argument.handle = 0;
            }
            if ((j == 7) && (i == 6) && ((s32)((FldFilterEntry *)(iGpffffb2b0 + iGpffffb2b8 * 0x124))->type == 3)) {
                ((PrimQueueDrawNode *)(res))->begin.endCallback = (void *)FldFilterApplyColour;
                ((PrimQueueDrawNode *)(res))->endArgument.handle = 0;
            }
        }
    }
}
#pragma pop
