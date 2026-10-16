#include "fcl_scale_transition.h"
/* Original translation unit y_draw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "fcl_row_draw.h"
#include "type.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
extern s32 func_002b52a0(u8 *task);
extern void func_002b5c60(u8 *task);
#include "include_asm.h"
extern u8 *iGpffffb574;

typedef FclVec2 f2;

typedef FclDrawColor u4;

typedef struct {
    f32 f[4];
} f4;




extern void mdlEffectEmitTagPair(void);

extern void (*jtbl_008873EC[])(void *ptr);

extern u8 *D_0076DB7C;

extern void fclSpriteStartPosition(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5);


extern void fclSpriteStartColor(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s32 arg5);


extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void RpSkyRenderStateSet(s32, s32);
extern void (*D_00887300[])(u32 state, u32 value);

extern s32 fclPackRgba(u8, u8, u8, u8);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 sdkSpriteScaledWidth(u8 *arg0);
extern f32 sdkSpriteScaledHeight(u8 *arg0);
extern u8 *sdkSpriteNewNode(u32 arg0, u32 arg1);
extern void sdkSpriteFreeNode(void *node);
extern void fclSpriteUpdateCulling(u8 *, s16, s16);
extern f32 fclEaseInterpolate(s32, f32, f32, f32, f32);
extern s32 fclAddClamped(s32, s32, s32, s32, s8);
extern s16 fclSubClamped(s32, s32, s32, s32, s8);
extern void fclSpriteApplySkyPresetA(void);
extern void fclSpriteApplySkyPresetB(void);
extern s32 fclSpriteUpdateAndDrawTask(u8 *arg0);
extern void fclSpriteDestroyTask(u8 *arg0);
extern s32 fclSpriteStartPanelLayout(u8 *arg0);
extern s32 fclSpriteUpdateTweens(u8 *arg0);
extern s8 fclSpriteTestRecordFlag(u8 *arg0, u32 arg1);
extern s32 fclSpriteListUpdate(u8 *arg0);
extern void fclSpriteBuildCornerQuads(u8 *arg0, u8 *arg1);
extern s32 fclSpritePoolUpdate(u8 *arg0);
extern void fclSpritePoolDestroy(u8 *arg0);
extern void fclSpriteDestroyListTask(u8 *arg0);

extern u8 D_0063F178[];
extern u8 D_0063F188[];
extern u8 D_0063F1A0[];
extern u8 D_0063F1B0[];
extern u8 D_0063F1D0[];
extern u8 D_0063F1E0[];
void fclSpriteStartFade(u8 *arg0, u8 arg1, u8 arg2, u32 arg3);

extern void mdlEffectEmitMaskedTagPair(void);
extern u8 *func_00457120(void);
extern void memcpy(void *, s32, s32);
extern void *PrimAllocQueueNode(void);
extern void func_00460ac0(void *, void *);
extern u8 *func_00461390(void *list, s32 arg1, void *arg2, s32 arg3);
extern f32 fGpffff8504;
extern f32 iGpffff84f4;
extern f32 D_008872F8[];
extern u8 D_00793E80[];


/* measured: retail hoists the loop's 0xFF constant into the preheader (addiu before
   the entry branch) and emits base-first addu; mwcc b210 sinks the constant
   materialization into the loop body and emits index-first addu (8 differing words
   reloc-masked). Tried inline p[0x110 + i*4] literal, a pre-loop u8 val local, an
   s32 off local with plain assignment, and a u8 *q = p + off pointer local - all
   keep the sunk constant; best (8) is the inline literal form. Constant-sinking
   floor, cousin of the load-sinking wall. */
/* measured 2026-08-03: MATCHED with #pragma opt_loop_invariants on (nd 12 -> 0)
   + *(f2 *)(p + 0x134) = p1 struct store (retail's batched pair loads) + the
   4-sb byte loop. The pragma hoists the loop's 0xFF into the preheader in $a0
   exactly as retail. SDK callbacks use their actual update and destroy signatures. */
// Intent: creates a child task with a 0x190-byte sprite work block at +0x38. It sets the start position at +0x134, clears the four corner colours and the flags, and returns the task handle.
// FUN_002B5C90
/* measured: open opt_loop_invariants scope for fclSpriteSpawnChild. */
#pragma opt_loop_invariants on
s32 fclSpriteSpawnChild(s32 arg0, f2 p1) {
    s32 handle;
    u8 *p;
    s32 i;
    chkmemAllocSiteTag(&D_0063F178, 0xD4);
    p = D_008873F4[0](1, 0x190, 0x40000);
    handle = (s32)kwlnTaskCreateChild((void *)((void *)(arg0)), (const void *)(D_0063F188), 0xF, 0, 0, func_002b52a0, func_002b5c60, (u8 *)(p));
    *(f2 *)(p + 0x134) = p1;
    *(s16 *)(p + 0x14C) = 0;
    p[0x154] = 0;
    for (i = 0; i < 4; i++) {
        u8 *q = p + 0x110 + i * 4;
        q[0] = 0xFF;
        q[1] = 0xFF;
        q[2] = 0xFF;
        q[3] = 0xFF;
    }
    *(u32 *)(p + 0x188) = 0x49;
    p[0x184] = 0;
    *(s16 *)(p + 0x156) = -1;
    p[0x180] = 0;
    p[0x18C] = 0;
    *(s16 *)(p + 0x182) = 0;
    return handle;
}
/* measured: close opt_loop_invariants scope after fclSpriteSpawnChild. */
#pragma opt_loop_invariants off
// Intent: duplicate of fclSpriteWork (same body, kept under the Alt name).
// FUN_002B5DA0
u8 *fclSpriteWorkAlt(u8 *arg0) {
    return *(u8 **)(arg0 + 0x38);
}

// FUN_002B5DB0
void fclSpriteSetPositionBounds(u8 *arg0, f2 p1, FclBoundsPacket p2) {
    FclBoundsBytes t;
    u8 *base;
    t = p2.representation;
    base = *(u8 **)(arg0 + 0x38);
    *(f2 *)(base + 0x134) = p1;
    ((FclBoundsPacket *)(base + 0x120))->representation = t;
}

// Intent: stores the base scale at +0x130. fclSpriteResetScale copies it into the four layout scales at +0x4, +0x44, +0x84 and +0xC4.
// FUN_002B5E20
void fclSpriteSetBaseScale(u8 *arg0, f32 fparg0) {
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x130) = fparg0;
}

// FUN_002B5E30
void fclSpriteSetCornerColors(u8 *arg0, u4 arg1) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s32 i;
    for (i = 0; i < 4; i++) {
        *(u4 *)(base + 0x110 + i * 4) = arg1;
    }
}
// FUN_002B5E90
void fclSpriteStartMove(u8 *arg0, f2 p1, f2 p2, u32 arg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x14C) = 0;
    *(u32 *)(base + 0x150) = arg3;
    *(f2 *)(base + 0x13C) = p1;
    *(f2 *)(base + 0x144) = p2;
    *(s16 *)(base + 0x156) = 2;
    base[0x154] = 0;
    base[0x0] = 2;
}

// FUN_002B5EF0
void fclSpriteStartBoundsMove(u8 *arg0, f2 p1, f2 p2, FclBoundsPacket p3, FclBoundsPacket p4, u32 arg5) {
    FclBoundsBytes a = p3.representation;
    FclBoundsBytes b = p4.representation;
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x14C) = 0;
    *(u32 *)(base + 0x150) = arg5;
    *(f2 *)(base + 0x13C) = p1;
    *(f2 *)(base + 0x144) = p2;
    ((FclBoundsPacket *)(base + 0x158))->representation = a;
    ((FclBoundsPacket *)(base + 0x168))->representation = b;
    *(s16 *)(base + 0x156) = 3;
    base[0x154] = 0;
    base[0x0] = 2;
}

// Intent: as fclSpriteStartBoundsMove, plus a fade (fclSpriteStartFade, alpha 0x80) and the timer at +0x182 from arg6.
// FUN_002B5FD0
void fclSpriteStartBoundsMoveFade(u8 *arg0, f2 p1, f2 p2, FclBoundsPacket p3, FclBoundsPacket p4, u32 arg5, s16 arg6) {
    FclBoundsBytes a = p3.representation;
    FclBoundsBytes b = p4.representation;
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x14C) = 0;
    *(u32 *)(base + 0x150) = arg5;
    *(f2 *)(base + 0x13C) = p1;
    *(f2 *)(base + 0x144) = p2;
    ((FclBoundsPacket *)(base + 0x158))->representation = a;
    ((FclBoundsPacket *)(base + 0x168))->representation = b;
    *(s16 *)(base + 0x156) = 4;
    fclSpriteStartFade(arg0, 0x80, 0, arg5);
    base[0x154] = 0;
    base[0x0] = 2;
    base[0x184] = 1;
    base[0x18C] = 1;
    *(s16 *)(base + 0x182) = arg6;
}

// Intent: starts a fade. Stores the two alpha bytes at +0x178/+0x179, resets the timer at +0x17A, sets the duration at +0x17C and enables the fade at +0x180.
// FUN_002B60F0
void fclSpriteStartFade(u8 *arg0, u8 arg1, u8 arg2, u32 arg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    base[0x178] = arg1;
    base[0x179] = arg2;
    *(s16 *)(base + 0x17A) = 0;
    *(u32 *)(base + 0x17C) = arg3;
    base[0x180] = 1;
}

// Intent: sets the sprite's mode byte at +0x154 (y_fclCombine callers pass the mode).
// FUN_002B6120
void fclSpriteSetMode(u8 *arg0, u8 arg1) {
    *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x154) = arg1;
}

// Intent: sets the sprite's draw order word at +0x188 (y_fclCombine callers pass the order).
// FUN_002B6130
void fclSpriteSetOrder(u8 *arg0, u32 arg1) {
    *(u32 *)(*(u8 **)(arg0 + 0x38) + 0x188) = arg1;
}

// Intent: sets the sprite's hidden byte at +0x184 (y_fclCombine callers pass 0 or 1).
// FUN_002B6140
void fclSpriteSetHidden(u8 *arg0, u8 arg1) {
    *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x184) = arg1;
}

// Fcl sprite entry: returns the 0x100-byte record for sprite index arg0 in the draw pool.
// FUN_002B6150
u8 *fclSpriteEntry(s16 arg0) {
    return (u8 *)((u32)(*(u8 **)(D_0076DB7C + 0x38)) + (u32)((s32)arg0 << 8) + 4);
}
// Intent: applies sky render-state preset A (texture stage and blend setup, then RpSkyRenderStateSet 3 = 0x71009). Used as a task callback.
// FUN_002B6180
void fclSpriteApplySkyPresetA(void) {
    void (*const *tbl)(u32, u32) = D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x71009);
}

// Intent: applies sky render-state preset B, the same stages as preset A with RpSkyRenderStateSet 3 = 0x7C003. Used as a task callback.
// FUN_002B6260
void fclSpriteApplySkyPresetB(void) {
    void (*const *tbl)(u32, u32) = D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x7C003);
}

/* measured: 536B/544B, all 19 relocations resolved; eight zero-tail bytes.
   Canonical byte color/opacity contracts preserve draw argument order.
   The neighboring 002b9e10 field/global staging preserves the first
   comparison's load order under this bounded propagation pragma. */
#pragma push
#pragma opt_propagation off
// Intent: per-frame update of one sprite task: advances its tweens, then, when alpha and scale are above threshold, queues the sprite draw (sdkSpriteDrawQueued) with the layout chosen by flag 13.
// FUN_002B6340
s32 fclSpriteUpdateAndDrawTask(u8 *arg0) {
    u8 *p;
    u8 *q;
    s32 color;
    f32 a;
    f32 g;
    p = *(u8 **)(arg0 + 0x38);
    memcpy(p + 0x10, fclSpriteUpdateTweens(p + 0x10), 0xF0);
    if (p[0x6E] <= 0) return 0;
    a = *(f32 *)(p + 0xA0);
    g = iGpffff84f4;
    if (a <= g) return 0;
    if (*(f32 *)(p + 0xAC) <= g) return 0;
    if (fclSpriteTestRecordFlag(arg0, 0) == 1) {
        if (fclSpriteTestRecordFlag(arg0, 13) == 1) {
            q = PrimAllocQueueNode();
            *(void (**)(void))(q + 8) = fclSpriteApplySkyPresetA;
            *(s32 *)(q + 0x10) = 0;
            func_00460ac0(D_00793E80 + *(s32 *)(p + 8) * 0x30, q);
            color = fclPackRgba(255, p[0x85], p[0x86], p[0x87]);
            sdkSpriteDrawQueued(*(f32 *)(p + 0x38), *(f32 *)(p + 0x3C), *(f32 *)(p + 0x14),
                color, p[0x6E], *(s16 *)(p + 4), *(void **)(p + 0), 0,
                *(s16 *)(p + 0xC), *(s16 *)(p + 0xE), *(f32 *)(p + 0xD0),
                *(f32 *)(p + 0xA0), *(f32 *)(p + 0xAC), D_00793E80 + *(s32 *)(p + 8) * 0x30);
        } else {
            color = fclPackRgba(255, p[0x85], p[0x86], p[0x87]);
            sdkSpriteDrawQueued(*(f32 *)(p + 0x38), *(f32 *)(p + 0x3C), *(f32 *)(p + 0x14),
                color, p[0x6E], *(s16 *)(p + 4), *(void **)(p + 0), 1,
                *(s16 *)(p + 0xC), *(s16 *)(p + 0xE), *(f32 *)(p + 0xD0),
                *(f32 *)(p + 0xA0), *(f32 *)(p + 0xAC), D_00793E80 + *(s32 *)(p + 8) * 0x30);
        }
    }
    return 0;
}
#pragma pop
// Intent: destroy callback for the 0x100-byte task created by fclSpriteCreateDrawTask (frees the work block at +0x38).
// FUN_002B6560
void fclSpriteDestroyTask(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

/* Keep the component's byte color shared while rematerializing each
 * dimension divisor after its provider call. The copied signed index and
 * named word offset retain the component-address arithmetic. */
#pragma push
/* measured: opt_loop_invariants off preserves the retail loop's per-iteration
   index-extension and issue order. */
#pragma opt_loop_invariants off
/* measured: opt_propagation off preserves saved-register assignment and local
   load ordering for this target. */
#pragma opt_propagation off
/* measured: schedule off preserves the retail loop and call issue order. */
#pragma schedule off
/* Keep dimension constants local to their queries. */
#pragma opt_pulloutconstants off
// Intent: creates the 0x100-byte sprite draw task under parent arg0 (update fclSpriteUpdateAndDrawTask, destroy fclSpriteDestroyTask). arg1 is the slot stored at +4 and arg2 the tint word stored at +0. Three channels start at their default state and the size comes from the sprite node. y_smap.c creates two of these, slots 0xC and 0xD, for map symbols.
// FUN_002B6590
s32 fclSpriteCreateDrawTask(s32 arg0, s16 arg1, s32 arg2) {
    s32 result;
    u8 *p;
    s16 i;
    s16 j;
    s32 off;
    const u8 ff = 0xFF;
    f2 pos;
    u4 color;
    u8 *q;
    s32 one;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
    f32 zero;
    chkmemAllocSiteTag(&D_0063F178, 0x236);
    p = D_008873F4[0](1, 0x100, 0x40000);
    result = (s32)kwlnTaskCreateChild((void *)((void *)(arg0)), (const void *)(D_0063F1A0), 0xF, 0, 0, fclSpriteUpdateAndDrawTask, fclSpriteDestroyTask, (u8 *)(p));
    *(s16 *)(p + 4) = arg1;
    *(s32 *)(p + 0) = arg2;
    i = 0;
    j = i;
    while (i < 3) {
        j = i;
        off = j;
        zero = 0.0f;
        pos = fclMakeVec2(zero, zero);
        *(f2 *)((u8 *)((s32)p + off * 8) + 0x28) = pos;
        *(u8 *)((s32)p + off + 0x6C) = ff;
        q = (u8 *)((s32)p + off * 4);
        *(s32 *)(q + 0xC8) = 0;
        one = 0x3F800000;
        *(s32 *)(q + 0xA4) = one;
        *(s32 *)(q + 0x98) = one;
        color = fclMakeDrawColor(ff, ff, ff, ff);
        c0 = color.c0;
        c1 = color.c1;
        c2 = color.c2;
        c3 = color.c3;
        q[0x7D] = c0;
        q[0x7E] = c1;
        q[0x7F] = c2;
        q[0x80] = c3;
        i++;
    }
    *(f32 *)(p + 0x14) = 100.0f;
    *(s32 *)(p + 8) = 0x55;
    *(s16 *)(p + 0x10) = 0;
    q = sdkSpriteNewNode(*(u32 *)(p + 0), (s32)arg1);
    *(s16 *)(p + 0xC) = (s16)(s32)(sdkSpriteScaledWidth(q) / 2.0f);
    *(s16 *)(p + 0xE) = (s16)(s32)(sdkSpriteScaledHeight(q) / 2.0f);
    sdkSpriteFreeNode(q);
    return result;
}
/* measured: restore opt_loop_invariants after the target. */
#pragma opt_loop_invariants off
#pragma pop


// Intent: sets (arg2 == 0) or clears (arg2 == 1) bit arg1 in the record's flag word at +0x10. Record-level twin of fclSpriteSetFlag.
// FUN_002B67A0
void fclSpriteSetRecordFlag(u8 *arg0, u32 arg1, s8 arg2) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    if (arg2 == 0) {
        *(s16 *)(base + 0x10) |= (s16)((1 << (arg1 & 0xFFFF)) & 0xFFFF);
        return;
    }
    if (arg2 == 1) {
        *(s16 *)(base + 0x10) &= (s16)((1 << (arg1 & 0xFFFF)) ^ 0xFFFF);
        return;
    }
}

// Intent: returns bit arg1 of the record's flag word at +0x10 (as 0 or 1). Test-side twin of fclSpriteSetRecordFlag.
// FUN_002B6820
s8 fclSpriteTestRecordFlag(u8 *arg0, u32 arg1) {
    u32 n = arg1 & 0xFFFF;
    return (s8)((s32)(*(s16 *)(*(u8 **)(arg0 + 0x38) + 0x10) & ((1 << n) & 0xFFFF)) >> n);
}




// Intent: returns 1 when any of flag bits 1-4 of the record's +0x10 word is set.
// FUN_002B6850
s32 fclSpriteHasDisplayFlags(u8 *arg0) {
    s16 flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x10);
    if (((s8)((flags & 2) >> 1)) == 0 && ((s8)((flags & 4) >> 2)) == 0 &&
        ((s8)((flags & 8) >> 3)) == 0 && ((s8)((flags & 0x10) >> 4)) == 0) {
        return 0;
    }
    return 1;
}

/* measured 2026-08-07: MATCHED (nd 0). opt_propagation off fixes the prologue
   load-sinking wall (lw gp then lw 0x38 table base before the arg0 sign-ext).
   The OR branch uses (1 << arg1) & 0xFFFF (andi) and the AND branch uses
   (1 << arg1) ^ 0xFFFF (xori) - spelling ~ on the mask emits 32-bit `not`
   instead of retail's 16-bit xori. s32 v holds the loaded s16; p4 = slot + 4
   is the store pointer. arg0/s16, arg1/s16, arg2/s8 sign-exts match retail. */
// Fcl sprite set flag: sets (mode 0) or clears (mode 1) bit arg1 of the flags of sprite arg0.
// FUN_002B68D0
/* measured: open opt_propagation scope for fclSpriteSetFlag. */
#pragma opt_propagation off
void fclSpriteSetFlag(s16 arg0, s16 arg1, s8 arg2) {
    u8 *p = *(u8 **)(iGpffffb574 + 0x38);
    u8 *slot = p + ((s32)arg0 << 8);
    u8 *p4 = slot + 4;
    s32 v = *(s16 *)(slot + 0x14);
    if (arg2 == 0) {
        v = (s16)(v | (s16)((1 << arg1) & 0xFFFF));
    } else if (arg2 == 1) {
        v = (s16)(v & (s16)((1 << arg1) ^ 0xFFFF));
    }
    *(s16 *)(p4 + 0x10) = (s16)v;
}
/* measured: close opt_propagation scope after fclSpriteSetFlag. */
#pragma opt_propagation on
// Fcl sprite flag bit: returns bit arg1 of arg0 as 0 or 1.
// FUN_002B6970
s16 fclSpriteFlagBit(s16 arg0, s16 arg1) {
    return (s16)((arg0 & ((1 << arg1) & 0xFFFF)) >> arg1);
}

// Fcl sprite start position (task): starts a position transition on the task's sprite block.
// FUN_002B69B0
void fclSpriteStartPositionTask(u8 *arg0, f2 p1, f2 p2, u32 arg3, u32 arg4, s16 arg5) {
    fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 0x10, p1, p2, arg3, arg4, arg5);
}

/* measured: argument-forwarding wrapper that must repeat fclSpriteStartPosition's full
   parameter list (retail sets only $a0, sign-extends arg0/s16 and arg5/s16 in
   place); residual is the load-sinking wall - retail loads iGpffffb574 then the
   0x38 table base before touching arg0, mwcc sinks the 0x38 load below the shift
   and flips the addu operands (7 differing words reloc-masked, identical with the
   base hoisted into a local). Same wall as fclSpriteStartRevealScaleAt/fclSpriteStartTweenAt. */
/* measured: re-tested recipe B (global-base hoist) with four spellings - typed
   u8 *base local, two-step u8 *g = iGpffffb574 then base, fully inline
   expression, and an s32 idx local for (s16)arg0 << 8 - all nd 7 reloc-masked,
   byte-identical apart from the load-sinking wall: retail loads iGpffffb574
   then the 0x38 table base BEFORE sign-extending arg0, mwcc b210 sinks the
   0x38 load below the dsll32/dsra32/sll and flips the addu operands (base in
   $v1, index in $v0 vs candidate index/base reversed). Same wall as
   fclSpriteSetFlag, fclSpriteStartAlphaAt, fclSpriteStartRevealScaleAt, fclSpriteStartTweenAt, fclSpriteStartColorAt; nothing source-side moves it. */
/* measured: re-measured 2026-08-03 with the full-parameter-list forwarding
   body (s16 arg0 + f2 p1/p2 + s16 arg5, inline base deref) - nd 7, same wall:
   candidate emits lw $t2,-0x4A8C($gp) / dsll32/dsra32/sll / lw $v0,0x38($t2)
   / addu $v0,$v0,$v1; retail interleaves lw $v1,0x38($v0) right after the gp
   load and shifts after it. Load-sinking wall, corroborated. */
/* measured 2026-08-03: MATCHED with #pragma opt_propagation off (nd 7 -> 0).
   The pragma makes b210 load the 0x38 table base immediately after the gp load
   (retail's order) instead of sinking it below the dsll32/dsra32/sll index
   chain. This lever cracks the load-sinking wall for the whole wrapper family
   fclSpriteSetFlag, fclSpriteStartAlphaAt, fclSpriteStartRevealScaleAt, fclSpriteStartTweenAt, fclSpriteStartColorAt, fclSpriteReset, fclSpriteResetScale). */
// Fcl sprite start position (index): starts a position transition on sprite arg0.
// FUN_002B69F0
/* measured: open opt_propagation scope for fclSpriteStartPositionAt. */
#pragma opt_propagation off
void fclSpriteStartPositionAt(s16 arg0, f2 p1, f2 p2, u32 arg3, u32 arg4, s16 arg5) {
    u8 *base = *(u8 **)(iGpffffb574 + 0x38);
    fclSpriteStartPosition(base + ((s32)arg0 << 8) + 0x14, p1, p2, arg3, arg4, arg5);
}
/* measured: close opt_propagation scope after fclSpriteStartPositionAt. */
#pragma opt_propagation on
// Fcl sprite start alpha (task): starts an alpha transition on the task's sprite block.
// FUN_002B6A40
void fclSpriteStartAlphaTask(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, s16 arg5) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg5;
    fclSpriteStartAlpha(base + 0x10, arg1, arg2, arg3, arg4, ext);
}




/* measured: argument-forwarding wrapper around fclSpriteStartAlpha (full parameter list
   repeated; retail sets only $a0, sign-extends arg0 and arg5 in place). Residual is
   the load-sinking wall: retail loads iGpffffb574 then the 0x38 table base before
   sign-extending arg0, mwcc sinks the 0x38 load below the shift and flips the addu
   operands (17 differing words reloc-masked). Same wall as fclSpriteStartRevealScaleAt/fclSpriteStartTweenAt. */
/* measured 2026-08-03: MATCHED with #pragma opt_propagation off + arg5 declared
   s32 and passed as (s16)arg5 (the s16 widening emits the retail dsll32/dsra32
   sign-extension; opt_propagation off fixes the load-sinking order). */
// Fcl sprite start alpha (index): starts an alpha transition on sprite arg0.
// FUN_002B6A70
/* measured: open opt_propagation scope for fclSpriteStartAlphaAt. */
#pragma opt_propagation off
void fclSpriteStartAlphaAt(s16 arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, s16 arg5) {
    u8 *base = *(u8 **)(iGpffffb574 + 0x38);
    fclSpriteStartAlpha(base + ((s32)arg0 << 8) + 0x14, arg1, arg2, arg3, arg4, (s16)arg5);
}
/* measured: close opt_propagation scope after fclSpriteStartAlphaAt. */
#pragma opt_propagation on
// Fcl sprite start reveal scale (task): starts a scale reveal on the task's sprite block.
// FUN_002B6AC0
void fclSpriteStartRevealScaleTask(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, u32 arg1, u32 arg2, s32 arg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg3;
    fclSpriteStartRevealScale(base + 0x10, fparg0, fparg1, fparg2, fparg3, arg1, arg2, ext);
}

/* measured: retail issues both indirections up front (lw gp, then lw 0x38) before touching
   arg0; mwcc b210 sinks the 0x38 load past the shift, which also flips the addu operand
   order. Hoisting the base into a local first does not move it (nd 9 either way). This is
   the load-sinking wall documented in docs/matching.md. */
/* measured: re-measured 2026-08-03 with the matched-sibling-6ac0 idiom (s32
   arg3 + s16 ext = (s16)arg3, inline base deref) - nd 9, same wall: candidate
   lw $t0,-0x4A8C($gp) / dsll32/dsra32/sll / lw $v0,0x38($t0) / addu
   $v0,$v0,$v1 vs retail's lw $v1,0x38($v0) interleaved right after the gp
   load. Load-sinking wall, corroborated. */
/* measured 2026-08-03: MATCHED with #pragma opt_propagation off + arg3 declared
   s32 and passed as (s16)arg3 (s16 widening emits the retail sign-extension). */
// Fcl sprite start reveal scale (index): starts a scale reveal on sprite arg0.
// FUN_002B6AF0
#pragma opt_propagation off
void fclSpriteStartRevealScaleAt(s16 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, u32 arg1, u32 arg2, s16 arg3) {
    u8 *base = *(u8 **)(iGpffffb574 + 0x38);
    fclSpriteStartRevealScale(base + ((s32)arg0 * 256) + 0x14, fparg0, fparg1, fparg2, fparg3, arg1, arg2, (s16)arg3);
}
/* measured: close opt_propagation scope after fclSpriteStartRevealScaleAt. */
#pragma opt_propagation on
/* measured 2026-08-03: MATCHED with #pragma opt_propagation off + arg3 s32 passed
   as (s16)arg3 (s16 widening = retail's dsll32/dsra32 sign-ext). */
// Fcl sprite start tween (index): starts a two-float tween on sprite arg0.
// FUN_002B6B40
#pragma opt_propagation off
void fclSpriteStartTweenAt(s16 arg0, u8 arg1, s32 arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    u8 *base = *(u8 **)(iGpffffb574 + 0x38);
    fclSpriteStartTween(base + ((s32)arg0 << 8) + 0x14, arg1, arg2, (s16)arg3, fparg0, fparg1);
}
/* measured: close opt_propagation scope after fclSpriteStartTweenAt. */
#pragma opt_propagation on
/* measured 2026-08-03: MATCHED with #pragma opt_propagation off + arg5 s32 passed
   as (s16)arg5 (s16 widening = retail's dsll32/dsra32 sign-ext). */
// Fcl sprite start color (index): starts a colour fade on sprite arg0.
// FUN_002B6B90
#pragma opt_propagation off
void fclSpriteStartColorAt(s16 arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s32 arg5) {
    u8 *base = *(u8 **)(iGpffffb574 + 0x38);
    fclSpriteStartColor(base + ((s32)arg0 << 8) + 0x14, arg1, arg2, arg3, arg4, (s16)arg5);
}
/* measured: close opt_propagation scope after fclSpriteStartColorAt. */
#pragma opt_propagation on
// Fcl sprite activate (task): marks the task's sprite active and sets its id, scale and position.
// FUN_002B6BE0
void fclSpriteActivateTask(u8 *arg0, f2 p1, u32 arg2, f32 fparg0) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x10) |= 1;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x14) = fparg0;
    *(u32 *)(*(u8 **)(arg0 + 0x38) + 0x8) = arg2;
    *(f2 *)(base + 0x38) = p1;
}

/* measured: retail emits the func_0046d200 call's arg1 chain (lw 0x38 base reload,
   addu, lh 8($v0)) BEFORE the arg0 load (lw $a0, ($a3) from the prologue-hoisted
   base, which retail keeps in $a3); mwcc b210 schedules the arg0 load first and
   colors the hoisted base $a1, flipping the addu at the first store (9 differing
   words reloc-masked). Tried full-deref stores, q = base+off+0x10 hoisted pre-call,
   b = base hoisted pre-call, and a pre-call s32 v = lh load - all keep mwcc's
   arg0-first order. Argument-materialization-order floor, cousin of the
   load-sinking wall. */
/* measured: re-tested recipe B (base hoist) with four spellings. A single typed
   u8 *p local keeps the base in $s0 across the calls (frame 0x40, nd 71);
   full-deref stores re-derive the base per store but mwcc still keeps the
   first base in $v0 and the pair reloads split (nd 70); the closest shape is
   pre-call b = *(u8 **)(iGpffffb574 + 0x38) hoists before func_0046b260/2f0
   plus full derefs elsewhere: frame 0x50, prologue through the 0xC store and
   every post-call chain byte-identical, nd 46 of which ~6 are real - retail
   CSEs the iGpffffb574 gp load between the p1 pair and the lh chain (lw $v1
   once, 0x38 reloaded), mwcc reloads gp, and retail loads the p1 pair into
   $f1/$f0 before both swc1s. A *(f2 *) struct assignment for the pair does
   produce retail's batched loads, but hoisting g = iGpffffb574 into a local
   for the CSE makes it live across the whole function ($s1, frame 0x60,
   worse). Remaining levers: deferred g local scoped to the pair+chain only.
   Same argument-materialization family as the old nd 9 note. */
// Fcl sprite create: creates the sprite node for sprite arg0 and records its half width and height.
// FUN_002B6C30
void fclSpriteCreate(s16 arg0, f2 p1, f32 fparg0, s32 arg2) {
    u8 *base;
    u8 *base2;
    s32 off;
    u8 *entry;
    u8 *tmp;
    base = *(u8 **)(iGpffffb574 + 0x38);
    off = (s32)(s16)arg0 * 256;
    entry = base + off;
    *(s16 *)(entry + 0x14) |= 1;
    *(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x18) = fparg0;
    *(s32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x0C) = arg2;
    entry = *(u8 **)(iGpffffb574 + 0x38) + off;
    *(f2 *)(entry + 0x3C) = p1;
    tmp = sdkSpriteNewNode(*(u32 *)base, *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 8));
    base2 = *(u8 **)(iGpffffb574 + 0x38);
    *(s16 *)(base2 + off + 0x10) = (s16)(sdkSpriteScaledWidth(tmp) / 2.0f);
    base2 = *(u8 **)(iGpffffb574 + 0x38);
    *(s16 *)(base2 + off + 0x12) = (s16)(sdkSpriteScaledHeight(tmp) / 2.0f);
    sdkSpriteFreeNode(tmp);
}

// Fcl sprite reset scale: resets sprite arg0 to unit scale and full opacity.
// FUN_002B6D60
/* measured: open opt_propagation scope for fclSpriteResetScale. */
#pragma opt_propagation off
void fclSpriteResetScale(s16 arg0) {
    u8 *base = *(u8 **)(iGpffffb574 + 0x38);
    u8 *last;
    s32 off = ((s32)arg0) << 8;
    *(f32 *)(base + off + 0xB0) = 1.0f;
    *(f32 *)(base + off + 0xA4) = 1.0f;
    last = *(u8 **)(iGpffffb574 + 0x38);
    *(u8 *)(last + off + 0x72) = 0xFF;
}
/* measured: opt_propagation off is bracketed around fclSpriteResetScale. */
#pragma opt_propagation on
// Intent: applies the masked render-state preset and emits the masked tag pair. Used as a queue callback by fclSpriteStartPanelLayout.
// FUN_002B6DA0
void fclSpriteApplyMaskedPreset(void) {
    void (*const *tbl)(u32, u32) = D_00887300;
    tbl[0](6, 1);
    tbl[0](7, 2);
    tbl[0](8, 1);
    tbl[0](0xA, 5);
    tbl[0](0xB, 6);
    tbl[0](9, 2);
    tbl[0](0xC, 1);
    tbl[0](1, 0);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
    mdlEffectEmitMaskedTagPair();
}

// Intent: emits the plain tag pair for the sprite's queued draw. Used as a queue callback by fclSpriteStartPanelLayout.
// FUN_002B6EA0
void fclSpriteEmitTagPair(void) {
    mdlEffectEmitTagPair();
}

/* Advance every active draw entry: refresh its animation, run the colour
 * and draw stages, clear finished entries and append active ones to the
 * queue. One queue pointer holds the work table (a copy of it would keep
 * the base a declared local; retail's base is a temporary in $s3), and the
 * entry offset is formed once before the active test. */
static inline s16 yDrawAnyBit(s32 flags)
{
    s16 bit;

    for (bit = 1; bit < 13; bit++) {
        if (((flags & (u16)(1 << bit)) >> bit) == 1) {
            return 1;
        }
    }
    return 0;
}

#define YDRAW_BASE (*(u8 **)(iGpffffb574 + 0x38))

#pragma push
#pragma opt_common_subs on
/* measured: these scopes reproduce retail's lifetimes and register roles (fnalign 0). */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma opt_pulloutconstants off
// Fcl sprite pool update: per-frame update of every active sprite record in the pool.
// FUN_002B6EC0
s32 fclSpritePoolUpdate(u8 *arg0) {
    u32 entryOffset;
    s16 *queue;
    s16 i;
    s32 count;
    s32 color;
    s32 animation;
    u8 *w;
    u8 *e;
    u8 *base;
    u8 *b2;
    s16 fl;

    queue = *(s16 **)(arg0 + 0x38);
    *(s16 *)(((u8 *)queue) + 0x30C04) = 0;
    i = 0;
    while (i < 0x30C) {
        *(s16 *)(((u8 *)queue) + (s32)i * 2 + 0x30C06) = 0;
        e = YDRAW_BASE;
        entryOffset = (u32)((s32)i << 8);
        e += (s32)entryOffset;
        if ((s16)(*(s16 *)(e + 0x14) & 1) == 1) {
            animation = fclSpriteUpdateTweens(e + 0x14);
            memcpy(YDRAW_BASE + entryOffset + 0x14, animation, 0xF0);
            fclSpriteUpdateCulling(arg0, i, *(s16 *)(YDRAW_BASE + entryOffset + 8));
            base = YDRAW_BASE;
            e = base + (s32)entryOffset;
            fl = *(s16 *)(e + 0x14);
            if ((s16)((fl & 0x4000) >> 0xE) == 1) {
                w = PrimAllocQueueNode();
                *(void (**)(void))(w + 8) = fclSpriteApplySkyPresetB;
                *(s32 *)(w + 0x10) = 0;
                b2 = YDRAW_BASE;
                func_00460ac0(D_00793E80 + *(s32 *)(b2 + (s32)i * 0x100 + 0xC) * 0x30, w);
                b2 = YDRAW_BASE;
                if (!(*(f32 *)(b2 + (s32)i * 0x100 + 0xA4) <= 0.1f) && !(*(f32 *)(b2 + (s32)entryOffset + 0xB0) <= 0.1f)) {
                    s32 rowOffset = (s32)(u32)i * 0x100;
                    u8 *d;

                    color = fclPackRgba(0xFF, (b2 + rowOffset)[0x89], (b2 + rowOffset)[0x8A], (b2 + rowOffset)[0x8B]);
                    d = b2;
                    d += (s32)(u32)rowOffset;
                    sdkSpriteDrawQueued(
                        *(f32 *)(d + 0x3C), *(f32 *)(d + 0x40), *(f32 *)(d + 0x18),
                        color, d[0x72], *(s16 *)(d + 8),
                        *(void **)(((u8 *)queue) + 0), 0, *(s16 *)(d + 0x10),
                        *(s16 *)(d + 0x12), *(f32 *)(d + 0xD4), *(f32 *)(d + 0xA4),
                        *(f32 *)(d + 0xB0), D_00793E80 + *(s32 *)(d + 0xC) * 0x30);
                } else {
                    if (yDrawAnyBit(*(s16 *)(b2 + (s32)entryOffset + 0x14)) == 0) {
                        *(s16 *)(b2 + entryOffset + 0x14) &= ~1;
                    }
                }
            } else if ((s16)((fl & 0x2000) >> 0xD) == 1) {
                w = PrimAllocQueueNode();
                *(void (**)(void))(w + 8) = fclSpriteApplySkyPresetA;
                *(s32 *)(w + 0x10) = 0;
                b2 = YDRAW_BASE;
                func_00460ac0(D_00793E80 + *(s32 *)(b2 + (s32)i * 0x100 + 0xC) * 0x30, w);
                b2 = YDRAW_BASE;
                if (!(*(f32 *)(b2 + (s32)i * 0x100 + 0xA4) <= 0.1f) && !(*(f32 *)(b2 + (s32)entryOffset + 0xB0) <= 0.1f)) {
                    s32 rowOffset = (s32)(u32)i * 0x100;
                    u8 *d;

                    color = fclPackRgba(0xFF, (b2 + rowOffset)[0x89], (b2 + rowOffset)[0x8A], (b2 + rowOffset)[0x8B]);
                    d = b2;
                    d += (s32)(u32)rowOffset;
                    sdkSpriteDrawQueued(
                        *(f32 *)(d + 0x3C), *(f32 *)(d + 0x40), *(f32 *)(d + 0x18),
                        color, d[0x72], *(s16 *)(d + 8),
                        *(void **)(((u8 *)queue) + 0), 0, *(s16 *)(d + 0x10),
                        *(s16 *)(d + 0x12), *(f32 *)(d + 0xD4), *(f32 *)(d + 0xA4),
                        *(f32 *)(d + 0xB0), D_00793E80 + *(s32 *)(d + 0xC) * 0x30);
                } else {
                    if (yDrawAnyBit(*(s16 *)(b2 + (s32)entryOffset + 0x14)) == 0) {
                        *(s16 *)(b2 + entryOffset + 0x14) &= ~1;
                    }
                }
            } else if (e[0x72] > 0 && !(*(f32 *)(e + 0xA4) <= 0.1f) && !(*(f32 *)(e + 0xB0) <= 0.1f)) {
                u8 *d;

                entryOffset = (s32)(u32)i * 0x100;

                color = fclPackRgba(0xFF, (base + entryOffset)[0x89], (base + entryOffset)[0x8A], (base + entryOffset)[0x8B]);
                d = base;
                d += (s32)(u32)entryOffset;
                sdkSpriteDrawQueued(
                    *(f32 *)(d + 0x3C), *(f32 *)(d + 0x40), *(f32 *)(d + 0x18),
                    color, d[0x72], *(s16 *)(d + 8),
                    *(void **)(((u8 *)queue) + 0), 1, *(s16 *)(d + 0x10),
                    *(s16 *)(d + 0x12), *(f32 *)(d + 0xD4), *(f32 *)(d + 0xA4),
                    *(f32 *)(d + 0xB0), D_00793E80 + *(s32 *)(d + 0xC) * 0x30);
            } else {
                u8 *d = base + entryOffset;

                fl = *(s16 *)(d + 0x14);
                if (fl == 1) {
                    if (*(s8 *)(d + 0x77) == 0) {
                        if (*(s8 *)(d + 0x4B) == 0) {
                            *(s16 *)(d + 0x14) = fl & ~1;
                        }
                    }
                }
            }
            /* Only entries active on loop entry belong in this list. */
            count = queue[0x18602];
            queue[count + 0x18603] = i;
            (queue[0x18602])++;
        }
        i++;
    }
    return 0;
}
#pragma pop
#undef YDRAW_BASE

// Fcl sprite pool destroy: frees the pool work block.
// FUN_002B74C0
void fclSpritePoolDestroy(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

/* Measured: 596/608 bytes, 25 resolved relocations and 12 zero alignment bytes.
 * Record addresses use signed EE word arithmetic before byte component offsets;
 * separate table snapshots preserve provider-visible work-data replacement. */
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma schedule off
// Fcl sprite pool create: creates the pool task, initialises its 0x30C records, and returns the pool work block.
// FUN_002B74F0
u8 *fclSpritePoolCreate(s32 arg0, s32 arg1) {
    u8 *data;
    u8 *entries;
    u8 *entry;
    s32 componentOffset;
    s32 entryOffset;
    s16 record;
    s16 component;
    s16 index;
    f2 position;
    u4 color;
    const u8 alpha = 0xFF;
    f32 unitScale;
    f32 zero;

    chkmemAllocSiteTag(&D_0063F178, 0x3F3);
    data = D_008873F4[0](1, 0x31220, 0x40000);
    iGpffffb574 = (u8 *)kwlnTaskCreateChild((void *)((void *)(arg0)), (const void *)(D_0063F1B0), 0xF, 0, 0, fclSpritePoolUpdate, fclSpritePoolDestroy, (u8 *)(data));
    *(s32 *)(data + 0) = arg1;
    *(s16 *)(data + 0x30C04) = 0;
    record = 0;
    while ((s32)record < 0x30C) {
        component = 0;
        entryOffset = (s32)record * 0x100;
        while ((s32)component < 3) {
            entries = *(u8 **)(iGpffffb574 + 0x38);
            index = component;
            componentOffset = index;
            zero = 0.0f;
            position = fclMakeVec2(zero, zero);
            *(f2 *)((u8 *)(entryOffset + (s32)entries) + componentOffset * 8 + 0x2C) = position;
            entry = *(u8 **)(iGpffffb574 + 0x38);
            *(u8 *)((u8 *)(entryOffset + (s32)entry) + componentOffset + 0x70) = alpha;
            entry = *(u8 **)(iGpffffb574 + 0x38);
            componentOffset = componentOffset * 4;
            *(s32 *)((u8 *)(entryOffset + (s32)entry) + componentOffset + 0xCC) = 0;
            entry = *(u8 **)(iGpffffb574 + 0x38);
            unitScale = 1.0f;
            entry = (u8 *)(entryOffset + (s32)entry) + componentOffset;
            *(f32 *)(entry + 0xA8) = unitScale;
            *(f32 *)(entry + 0x9C) = unitScale;
            entries = *(u8 **)(iGpffffb574 + 0x38);
            color = fclMakeDrawColor(alpha, alpha, alpha, alpha);
            *(u4 *)((u8 *)(entryOffset + (s32)entries) + componentOffset + 0x81) = color;
            component++;
        }
        entry = *(u8 **)(iGpffffb574 + 0x38);
        index = record;
        entryOffset = (s32)index * 0x100;
        *(f32 *)(entry + entryOffset + 0x18) = 100.0f;
        entry = *(u8 **)(iGpffffb574 + 0x38);
        *(s32 *)(entry + entryOffset + 0x0C) = 0x55;
        *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + entryOffset + 0x14) = 0;
        entry = (u8 *)(*(u8 **)(iGpffffb574 + 0x38) + entryOffset);
        *(s16 *)(entry + 0x12) = 0;
        *(s16 *)(entry + 0x10) = 0;
        record++;
    }
    return iGpffffb574;
}
#pragma pop

// Fcl sprite reset: sets sprite arg0's id to arg1 and clears its flags and state.
// FUN_002B7750
/* measured: open opt_propagation scope for fclSpriteReset. */
#pragma opt_propagation off
void fclSpriteReset(s16 arg0, s16 arg1) {
    u8 *base = *(u8 **)(iGpffffb574 + 0x38);
    s32 off = ((s32)arg0) << 8;
    *(s16 *)(base + off + 8) = arg1;
    base = *(u8 **)(iGpffffb574 + 0x38);
    *(s16 *)(base + off + 0x14) = 0;
    base = *(u8 **)(iGpffffb574 + 0x38);
    *(u8 *)(base + off + 0x4B) = 0;
    base = *(u8 **)(iGpffffb574 + 0x38);
    *(u8 *)(base + off + 0x77) = 0;
    base = *(u8 **)(iGpffffb574 + 0x38);
    *(u8 *)(base + off + 0xB7) = 0;
    base = *(u8 **)(iGpffffb574 + 0x38);
    *(u8 *)(base + off + 0xDF) = 0;
}
/* measured: opt_propagation off is required for the byte-exact 7750 reset sequence. */
#pragma opt_propagation on
/* 1280-byte retail row transition.
 * Capture each table before the associated provider or conversion.
 * Preserve the constructor result and outgoing position in each branch.
 * The scoped propagation and constant controls retain those real copies
 * and the independently materialized dimension divisors. */
#pragma push
#pragma opt_propagation off
#pragma opt_pulloutconstants off
/* Preserve both components of the outgoing position value. */
static inline void fclCopyTransitionPosition(f2 *destination, const f2 *source)
{
    f32 y, x;
    x = source->x;
    y = source->y;
    destination->x = x;
    destination->y = y;
}

typedef struct YDrawTransitionFlags {
    u8 unknown00[0x4B];
    u8 positionFlag;
    u8 unknown4C[0x2B];
    u8 alphaFlag;
    u8 unknown78[0x3F];
    u8 scaleFlag;
    u8 unknownB8[0x27];
    u8 valueFlag;
} YDrawTransitionFlags;

/* Submit the actual initial and target opacity values in row order. */
static inline void fclRevealOpacity(u8 *work, const FclDrawColor *color)
{
    u8 initialAlpha = 0;
    u32 targetAlpha = color->c3;
    fclSpriteStartAlpha(work, initialAlpha, targetAlpha, 0, 0, 0);
}

// Intent: starts a show or hide transition for pool slot arg0 (arg4 == 1 hides, otherwise shows). Sets the slot's flags, sizes it from the scaled sprite width and height, and starts the alpha, reveal-scale and position tweens with the given duration and delay.
// FUN_002B77D0
void fclSpriteStartShowHide(s16 arg0, f2 p1, s16 arg1, FclDrawColor arg2, f32 fparg0, s16 arg3, s8 arg4, s16 arg5, s16 arg6, s16 arg7, u32 arg8) {
    u8 *first;
    s32 off;
    f2 hideConstructed;
    f2 showConstructed;
    f2 hidePosition;
    f2 showPosition;
    first = sdkSpriteNewNode(arg8, (s32)arg1);
    if ((s32)arg4 == 1) {
        u8 *tmp;
        u8 *dimensionRows;
        u8 *base;
        u8 *orderRows;
        u8 *animationRows;
        s32 delay;
        s32 duration;
        base = *(u8 **)(iGpffffb574 + 0x38);
        off = (s32)arg0 * 256;
        *(s16 *)(base + off + 0x14) |= 1;
        *(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x18) = fparg0;
        orderRows = *(u8 **)(iGpffffb574 + 0x38);
        *(s32 *)(orderRows + off + 0x0C) = (s32)arg3;
        *(f2 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x3C) = p1;
        tmp = sdkSpriteNewNode(*(u32 *)base, *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 8));
        dimensionRows = *(u8 **)(iGpffffb574 + 0x38);
        *(s16 *)(dimensionRows + off + 0x10) = (s16)(sdkSpriteScaledWidth(tmp) / 2.0f);
        dimensionRows = *(u8 **)(iGpffffb574 + 0x38);
        *(s16 *)(dimensionRows + off + 0x12) = (s16)(sdkSpriteScaledHeight(tmp) / 2.0f);
        sdkSpriteFreeNode(tmp);
        animationRows = *(u8 **)(iGpffffb574 + 0x38);
        delay = (s32)arg7;
        duration = (s32)arg6;
        fclSpriteStartAlpha(animationRows + off + 0x14, *(animationRows + off + 0x72), 0, 0, 0, (s16)(duration + delay));
        fclSpriteStartRevealScale(*(u8 **)(iGpffffb574 + 0x38) + off + 0x14, 1.0f, 1.0f, 1.0f, fGpffff8504, 0, (u32)duration, delay);
        hideConstructed = fclMakeVec2(p1.x, p1.y + sdkSpriteScaledHeight(first) / 2.0f);
        fclCopyTransitionPosition(&hidePosition, &hideConstructed);
        fclSpriteStartPosition(*(u8 **)(iGpffffb574 + 0x38) + off + 0x14, p1, hidePosition, 0, duration, delay);
    } else {
        u8 *tmp;
        u8 *dimensionRows;
        u8 *base;
        u8 *orderRows;
        u8 *animationRows;
        s32 delay;
        s32 duration;
        base = *(u8 **)(iGpffffb574 + 0x38);
        off = (s32)arg0 * 256;
        *(s16 *)(base + off + 8) = arg1;
        *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x14) = 0;
        ((YDrawTransitionFlags *)(*(u8 **)(iGpffffb574 + 0x38) + off))->positionFlag = 0;
        ((YDrawTransitionFlags *)(*(u8 **)(iGpffffb574 + 0x38) + off))->alphaFlag = 0;
        ((YDrawTransitionFlags *)(*(u8 **)(iGpffffb574 + 0x38) + off))->scaleFlag = 0;
        ((YDrawTransitionFlags *)(*(u8 **)(iGpffffb574 + 0x38) + off))->valueFlag = 0;
        base = *(u8 **)(iGpffffb574 + 0x38);
        *(s16 *)(base + off + 0x14) |= 1;
        *(f32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x18) = fparg0;
        orderRows = *(u8 **)(iGpffffb574 + 0x38);
        *(s32 *)(orderRows + off + 0x0C) = (s32)arg3;
        *(f2 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x3C) = p1;
        tmp = sdkSpriteNewNode(*(u32 *)base, *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 8));
        dimensionRows = *(u8 **)(iGpffffb574 + 0x38);
        *(s16 *)(dimensionRows + off + 0x10) = (s16)(sdkSpriteScaledWidth(tmp) / 2.0f);
        dimensionRows = *(u8 **)(iGpffffb574 + 0x38);
        *(s16 *)(dimensionRows + off + 0x12) = (s16)(sdkSpriteScaledHeight(tmp) / 2.0f);
        sdkSpriteFreeNode(tmp);
        *(FclDrawColor *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x89) = arg2;
        fclRevealOpacity(*(u8 **)(iGpffffb574 + 0x38) + off + 0x14, &arg2);
        animationRows = *(u8 **)(iGpffffb574 + 0x38);
        delay = (s32)arg7;
        duration = (s32)arg5;
        fclSpriteStartRevealScale(animationRows + off + 0x14, 1.0f, 1.0f, fGpffff8504, 1.0f, 0, (u32)duration, delay);
        showConstructed = fclMakeVec2(p1.x, p1.y + sdkSpriteScaledHeight(first) / 2.0f);
        fclCopyTransitionPosition(&showPosition, &showConstructed);
        fclSpriteStartPosition(*(u8 **)(iGpffffb574 + 0x38) + off + 0x14, showPosition, p1, 0, duration, delay);
    }
    sdkSpriteFreeNode(first);
}

#pragma pop

/* 580/592 bytes; 10 resolved relocations; 12 zero alignment bytes.
 * The selected-state join retains both signed-index extensions. */
typedef struct {
    u8 unknown00[0x14];
    s16 flags;
    u8 unknown16[0x26];
    f32 x;
    f32 y;
    u8 unknown44[0xBC];
} YDrawCullEntry;
typedef struct {
    u8 unknown00[0x34];
    s32 margins[4];
    u8 unknown44[0x3C];
} YDrawSpriteFrameMargins;

#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma schedule off
// Intent: when the sprite entry has no bit set in flags 1-12, computes its screen margins and sets or clears its cull flag by whether it lies on screen.
// FUN_002B7CD0
void fclSpriteUpdateCulling(u8 *arg0, s16 arg1, s16 arg2) {
    u8 *context;
    s32 entryOffset;
    s32 flags;
    s16 bit;
    s16 selected;
    u8 *sample;
    s32 frameIndex;
    YDrawSpriteFrameMargins *frame;
    YDrawCullEntry *entries;
    f32 margins[4];
    s16 side;

    context = *(u8 **)(arg0 + 0x38);
    entries = *(YDrawCullEntry **)(iGpffffb574 + 0x38);
    entryOffset = (s32)arg1 * 0x100;
    flags = ((YDrawCullEntry *)((u8 *)entries + entryOffset))->flags;
    for (bit = 1; bit < 13; bit++) {
        if (((flags & (u16)(1 << bit)) >> bit) == 1) {
            selected = 1;
            goto found_check;
        }
    }
    selected = 0;
found_check:
    if (selected == 0) {
        frameIndex = arg2;
        sample = sdkSpriteNewNode(*(u32 *)context, frameIndex);
        (void)sdkSpriteScaledWidth(sample);
        (void)sdkSpriteScaledHeight(sample);
        side = 0;
        frame = (YDrawSpriteFrameMargins *)(*(u8 **)(*(u8 **)sample + 0x204) + frameIndex * 0x80);
        for (; side < 4; side++) {
            margins[side] = (f32)frame->margins[side];
        }
        if (!(((YDrawCullEntry *)((u8 *)(entries = *(YDrawCullEntry **)(iGpffffb574 + 0x38)) + entryOffset))->x - margins[2] < 640.0f) ||
            (margins[3] + (((YDrawCullEntry *)((u8 *)entries + entryOffset))->x + sdkSpriteScaledWidth(sample)) < 0.0f) ||
            !(((YDrawCullEntry *)((u8 *)(entries = *(YDrawCullEntry **)(iGpffffb574 + 0x38)) + entryOffset))->y - margins[0] < 480.0f) ||
            (margins[1] + (((YDrawCullEntry *)((u8 *)entries + entryOffset))->y + sdkSpriteScaledHeight(sample)) < 0.0f)) {
            ((YDrawCullEntry *)((u8 *)*(YDrawCullEntry **)(iGpffffb574 + 0x38) + entryOffset))->flags &= ~1;
        }
        sdkSpriteFreeNode(sample);
    }
}
#pragma pop

/* measured: retail compiles the u8->float c-check (lbu 0x125 + bltz, round-to-even
   trick via srl/andi/or, doubling via add.s) as a standard if/else - one bltz, direct
   path inline, trick out of line, single join store; mwcc b210 duplicates the else
   block and emits TWO bltz on the same lbu result for every spelling tried (>= / <
   condition, u8/u32 c, v2 local or inline doubled expression, u32 shift casts; nd
   111-129). Also retail hoists the D_008872F8 lui into the loop preheader and loads
   the LHS operand first (sub.s $f1, $f0 order), mwcc keeps the lui in the body and
   loads RHS first (nd 12 in the loop alone, same floor family as fclSpriteListUpdate's
   operand-order note). Else-duplication + loop-operand-order floor. */
/* measured: recipe A (s32 v = lbu load, u32 c copy, (f32)(s32)((c >> 1) | (c & 1)),
   f = f + f doubling, direct-path-first if (v >= 0)) DOES fix the old bltz
   duplication - mwcc now emits retail's single bare bltz, direct path inline,
   trick out of line, byte-identical conversion (nd 111-129 before, 0 here).
   Residual is the loop triple-wall: (1) retail re-sign-extends (s16)i at the
   body head (dsll32/dsra32 before the sll) while mwcc b210 folds that extension
   into the bottom test (2 words/iter x4); (2) retail hoists the D_008872F8 lui
   alone into the preheader and reloads lwc1 %lo per iteration, mwcc either
   rematerializes lui+addiu in the body (nd 59 best) or, with a typed f32 *dv
   local, hoists the full address into $s1 growing the frame (nd 59), or, with
   opt_loop_invariants on, hoists the whole lwc1 out of the loop (nd 106);
   (3) sub.s operand order: retail loads the D LHS first, mwcc loads the RHS
   (p+0x18) first - also survives (0.0f - x) + D reassociation (nd 108).
   lb for the 0x124 check needs the (s8) cast (lbu otherwise). Tail after the
   loop is byte-identical once aligned. Loop walls, s16-index-extension +
   operand-order family, same as func_002b6590/002b9ab0/002b9e10 notes. */
/* measured: re-measured 2026-08-03 with four fresh bodies (recipe-A
   conversion + s16 i + inline D_008872F8[0] LHS + per-site q), best nd 107:
   (s16)i cast at the body head does NOT force the extension (mwcc CSEs the
   bottom-test extension across the back edge), the inline D read keeps
   lui %hi(D_008872F8) in the body (lwc1 %lo folded - no addiu), the
   conversion itself is byte-identical, but the q/i temp colors rotate
   ($a0/$a1 vs retail $a1/$a2) and cascade through the trick path (or-result
   in $v0 vs retail's $a0) so the whole tail misaligns. f32 *dv local hoists
   the full address into the prologue (nd 113); while-loop + loop-scoped q
   folds q into $s0-relative stores (nd 110). Walls corroborated in
   y_CmbCardEff func_00347c70 (lui-hoist + or-register) and y_smap
   func_002b0b10 (lui-hoist + register cascade). */
#pragma push
/* measured: opt_loop_invariants on hoists D_008872F8's high-half constant into the
   loop preheader; the push/pop keeps this target's setting local. */
#pragma opt_loop_invariants on
/* measured: opt_propagation off keeps the local load and index-extension
   ordering stable for this target. */
#pragma opt_propagation off
/* measured: schedule off preserves the D_008872F8 base register through the
   loop body and matches the retail issue order. */
#pragma schedule off
// Intent: one-shot layout of the 0x130-byte panel task: sets its four channel records and two render positions, and queues the render job with fclSpriteApplyMaskedPreset and fclSpriteEmitTagPair. Returns at once while +0x124 is set; fclSpriteCreatePanelChild sets that flag, and nothing traced so far clears it.
// FUN_002B7F20
s32 fclSpriteStartPanelLayout(u8 *arg0) {
    u8 *p;
    f32 scale;
    u8 *q;
    s32 off;
    s16 i;
    s16 j;
    f32 d;

    p = *(u8 **)(arg0 + 0x38);
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    if (*(s8 *)(p + 0x124) == 1) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        j = i;
        q = p;
        q = (u8 *)((s32)q + (off = (s32)j << 6));
        d = *(f32 *)D_008872F8;
        *(f32 *)(q + 0x28) = d - *(f32 *)(p + 0x18);
        *(f32 *)(q + 0x38) = scale;
        *(s32 *)(q + 0x40) = 0;
        *(s32 *)(q + 0x44) = 0;
        *(s32 *)(q + 0x48) = 0;
        *(f32 *)(q + 0x4C) = (f32)(u32)*(u8 *)(p + 0x125);
    }
    *(f32 *)(p + 0x20) = *(f32 *)(p + 0);
    *(f32 *)(p + 0x24) = *(f32 *)(p + 4);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0) + (f32)*(s32 *)(p + 0x10);
    *(f32 *)(p + 0x64) = *(f32 *)(p + 4);
    *(f32 *)(p + 0xA0) = *(f32 *)(p + 0);
    *(f32 *)(p + 0xA4) = *(f32 *)(p + 4) + (f32)*(s32 *)(p + 0x14);
    *(f32 *)(p + 0xE0) = *(f32 *)(p + 0) + (f32)*(s32 *)(p + 0x10);
    *(f32 *)(p + 0xE4) = *(f32 *)(p + 4) + (f32)*(s32 *)(p + 0x14);
    q = func_00461390(D_00793E80 + *(s32 *)(p + 0x120) * 0x30,
                      4, (void *)(p + 0x20), 4);
    *(void **)(q + 8) = (void *)fclSpriteApplyMaskedPreset;
    *(u8 **)(q + 0x10) = p;
    q = PrimAllocQueueNode();
    *(void **)(q + 8) = (void *)fclSpriteEmitTagPair;
    *(u8 **)(q + 0x10) = p;
    func_00460ac0(D_00793E80 + (*(s32 *)(p + 0x120) + 1) * 0x30, q);
    return 0;
}
/* measured: restore opt_loop_invariants after the target. */
#pragma opt_loop_invariants off
#pragma pop

// Intent: destroy callback for the 0x130-byte panel task created by fclSpriteCreatePanelChild (frees the work block at +0x38).
// FUN_002B8120
void fclSpriteDestroyPanel(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

// Intent: creates a child task with a 0x130-byte panel work block (destroy: fclSpriteDestroyPanel), sets the panel flag at +0x124 and clears +0x125.
// FUN_002B8150
s32 fclSpriteCreatePanelChild(s32 arg0) {
    s32 handle;
    u8 *p;
    chkmemAllocSiteTag(&D_0063F178, 0x4A2);
    p = D_008873F4[0](1, 0x130, 0x40000);
    handle = (s32)kwlnTaskCreateChild((void *)((void *)(arg0)), (const void *)(D_0063F1D0), 0xF, 0, 0, fclSpriteStartPanelLayout, fclSpriteDestroyPanel, (u8 *)(p));
    p[0x124] = 1;
    p[0x125] = 0;
    return handle;
}

// Fcl sprite work: returns the pool work block of the task.
// FUN_002B81F0
u8 *fclSpriteWork(u8 *arg0) {
    return *(u8 **)(arg0 + 0x38);
}

// Intent: sets a sprite's appearance: position at +0x28, size at +0x90/+0x9C, colour at +0x5E/+0x75, the scale at +0xC0 and +0x4, and enables the sprite (flag |= 1).
// FUN_002B8200
void fclSpriteSetAppearance(u8 *arg0, f2 p1, u4 arg2, f32 fparg0, f32 fparg1, f32 fparg2) {
    *(f2 *)(arg0 + 0x28) = p1;
    *(f32 *)(arg0 + 0x9C) = fparg0;
    *(f32 *)(arg0 + 0x90) = fparg0;
    arg0[0x5E] = arg2.c3;
    *(u4 *)(arg0 + 0x75) = arg2;
    *(f32 *)(arg0 + 0xC0) = fparg1;
    *(f32 *)(arg0 + 0x4) = fparg2;
    *(s16 *)(arg0 + 0x0) |= 1;
}

// Fcl sprite start position: sets the start and end points, the duration, the delay and the mode of a position transition.
// FUN_002B8270
void fclSpriteStartPosition(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5) {
    *(f32 *)(arg0 + 0x18) = p1.x;
    *(f32 *)(arg0 + 0x1C) = p1.y;
    *(f32 *)(arg0 + 0x20) = p2.x;
    *(f32 *)(arg0 + 0x24) = p2.y;
    *(f32 *)(arg0 + 0x28) = p1.x;
    *(f32 *)(arg0 + 0x2C) = p1.y;
    *(s16 *)(arg0 + 0x32) = 0;
    *(s16 *)(arg0 + 0x30) = arg4;
    *(s16 *)(arg0 + 0x34) = arg5;
    arg0[0x36] = arg3;
    *(s16 *)(arg0 + 0x0) |= 2;
}

// Fcl sprite start alpha: sets the alpha levels, the duration and the mode of an alpha transition.
// FUN_002B82D0
void fclSpriteStartAlpha(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, s32 arg5) {
    arg0[0x5C] = arg1;
    arg0[0x5D] = arg2;
    arg0[0x5E] = arg1;
    *(s16 *)(arg0 + 0x5A) = 0;
    *(s16 *)(arg0 + 0x58) = (s16)arg4;
    *(s16 *)(arg0 + 0x60) = (s16)arg5;
    arg0[0x62] = arg3;
    *(s16 *)(arg0 + 0x0) |= 4;
}

// Fcl sprite start reveal scale: sets the scale endpoints, duration, delay and mode of a reveal.
// FUN_002B8300
void fclSpriteStartRevealScale(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, u32 arg1, u32 arg2, s32 arg3) {
    *(f32 *)(arg0 + 0x88) = fparg0;
    *(f32 *)(arg0 + 0x8C) = fparg1;
    *(f32 *)(arg0 + 0x90) = fparg0;
    *(f32 *)(arg0 + 0x94) = fparg2;
    *(f32 *)(arg0 + 0x98) = fparg3;
    *(f32 *)(arg0 + 0x9C) = fparg2;
    *(s16 *)(arg0 + 0x84) = 0;
    *(s16 *)(arg0 + 0x82) = arg2;
    *(s16 *)(arg0 + 0xA0) = (s16)arg3;
    arg0[0xA2] = arg1;
    *(s16 *)(arg0 + 0x0) |= 0x10;
}

// Fcl sprite start tween: sets the two tween values, the duration, the delay and the mode.
// FUN_002B8340
void fclSpriteStartTween(u8 *arg0, u8 arg1, s32 arg2, s16 arg3, f32 fparg0, f32 fparg1) {
    *(f32 *)(arg0 + 0xB8) = fparg0;
    *(f32 *)(arg0 + 0xBC) = fparg1;
    *(f32 *)(arg0 + 0xC0) = fparg0;
    *(s16 *)(arg0 + 0xC4) = 0;
    *(s16 *)(arg0 + 0xC6) = arg2;
    *(s16 *)(arg0 + 0xC8) = arg3;
    arg0[0xCA] = arg1;
    *(s16 *)(arg0 + 0x0) |= 8;
}

// Fcl sprite start color: sets the start and end colours, the duration and the mode of a colour fade.
// FUN_002B8370
void fclSpriteStartColor(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s32 arg5) {
    arg0[0x6D] = arg1.c0;
    arg0[0x6E] = arg1.c1;
    arg0[0x6F] = arg1.c2;
    arg0[0x71] = arg2.c0;
    arg0[0x72] = arg2.c1;
    arg0[0x73] = arg2.c2;
    arg0[0x75] = arg1.c0;
    arg0[0x76] = arg1.c1;
    arg0[0x77] = arg1.c2;
    *(s16 *)(arg0 + 0x7A) = arg4;
    *(s16 *)(arg0 + 0x7C) = 0;
    *(s16 *)(arg0 + 0x7E) = arg5;
    arg0[0x80] = arg3;
    *(s16 *)(arg0 + 0x0) |= 0x200;
}

/* Position snapshots are consumed by the inline transition setters.
   Duration stays signed-word sized until each field is stored. */
static inline void fclStartPosition(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5) {
    f32 startX = p1.x;
    f32 startY;
    *(f32 *)(arg0 + 0x18) = startX;
    startY = p1.y;
    *(f32 *)(arg0 + 0x1C) = startY;
    *(f32 *)(arg0 + 0x20) = p2.x;
    *(f32 *)(arg0 + 0x24) = p2.y;
    *(f32 *)(arg0 + 0x28) = startX;
    *(f32 *)(arg0 + 0x2C) = startY;
    *(s16 *)(arg0 + 0x32) = 0;
    *(s16 *)(arg0 + 0x30) = arg4;
    *(s16 *)(arg0 + 0x34) = arg5;
    arg0[0x36] = arg3;
    *(s16 *)(arg0 + 0x0) |= 2;
}

static inline void fclStartAlpha(u8 *arg0, u8 arg1, u32 arg2, u32 arg3, u32 arg4, s16 arg5) {
    arg0[0x5C] = arg1;
    arg0[0x5D] = arg2;
    arg0[0x5E] = arg1;
    *(s16 *)(arg0 + 0x5A) = 0;
    *(s16 *)(arg0 + 0x58) = arg4;
    *(s16 *)(arg0 + 0x60) = arg5;
    arg0[0x62] = arg3;
    *(s16 *)(arg0 + 0x0) |= 4;
}

static inline void fclStartRevealScale(u8 *arg0, u32 mode, u32 duration, s32 delay, s8 outgoing)
{
    *(f32 *)(arg0 + 0x88) = 1.0f;
    *(f32 *)(arg0 + 0x8C) = 1.0f;
    *(f32 *)(arg0 + 0x90) = 1.0f;
    if (outgoing == 0) {
        f32 initialScale = fGpffff8504;
        *(f32 *)(arg0 + 0x94) = initialScale;
        *(f32 *)(arg0 + 0x98) = 1.0f;
        *(f32 *)(arg0 + 0x9C) = initialScale;
    } else {
        *(f32 *)(arg0 + 0x94) = 1.0f;
        *(f32 *)(arg0 + 0x98) = fGpffff8504;
        *(f32 *)(arg0 + 0x9C) = 1.0f;
    }
    *(s16 *)(arg0 + 0x84) = 0;
    *(s16 *)(arg0 + 0x82) = duration;
    *(s16 *)(arg0 + 0xA0) = delay;
    arg0[0xA2] = mode;
    *(s16 *)arg0 |= 0x10;
}

static inline void fclStartColor(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s32 arg5) {
    arg0[0x6D] = arg1.c0;
    arg0[0x6E] = arg1.c1;
    arg0[0x6F] = arg1.c2;
    arg0[0x71] = arg2.c0;
    arg0[0x72] = arg2.c1;
    arg0[0x73] = arg2.c2;
    arg0[0x75] = arg1.c0;
    arg0[0x76] = arg1.c1;
    arg0[0x77] = arg1.c2;
    *(s16 *)(arg0 + 0x7A) = arg4;
    *(s16 *)(arg0 + 0x7C) = 0;
    *(s16 *)(arg0 + 0x7E) = arg5;
    arg0[0x80] = arg3;
    *(s16 *)(arg0 + 0x0) |= 0x200;
}

// Intent: starts an entrance: alpha, reveal scale, position and colour in one call. The first flag selects the variant.
// FUN_002B83E0
void fclSpriteStartEntrance(u8 *arg0, FclVec2 p1, u4 arg2, u4 arg3, u8 arg4, u8 arg5,
                   f32 fparg0, f32 fparg1, s32 arg6, s32 arg7, s8 arg_sp0, s8 arg_sp8)
{
    arg0[0x37] = arg_sp8;
    arg0[0xA3] = arg_sp8;
    fclStartAlpha(arg0, arg4, arg5, 0, arg6, arg7);
    if ((s8)arg_sp0 == 0) {
        if (arg_sp8 == 0) {
            fclStartRevealScale(arg0, 0, (s16)arg6, (s16)arg7, 0);
            fclStartPosition(arg0, fclMakeVec2(p1.x, p1.y + fparg0 / 2.0f), p1, 0, arg6, arg7);
            fclStartColor(arg0, arg2, arg3, 0, 0, 0);
        } else {
            fclStartRevealScale(arg0, 1, (s16)arg6, (s16)arg7, 0);
            fclStartPosition(arg0, fclMakeVec2(p1.x, p1.y + fparg0 / 2.0f), p1, 1, arg6, arg7);
            fclStartColor(arg0, arg2, arg3, 0, 0, arg6 / 2);
        }
    } else if (arg_sp8 == 0) {
        fclStartRevealScale(arg0, 0, (s16)arg6, (s16)arg7, 1);
        fclStartPosition(arg0, p1, fclMakeVec2(p1.x, p1.y + fparg0 / 2.0f), 0, arg6, arg7);
        fclStartColor(arg0, arg2, arg3, 0, 0, 0);
    } else {
        fclStartRevealScale(arg0, 1, (s16)arg6, (s16)arg7, 1);
        fclStartPosition(arg0, p1, fclMakeVec2(p1.x, p1.y + fparg0 / 2.0f), 1, arg6, arg7);
        fclStartColor(arg0, arg2, arg3, 0, 0, arg6 / 2);
    }
    *(f32 *)(arg0 + 4) = fparg1;
    *(s16 *)arg0 |= 1;
}

/* The byte channels go through the compiler's own unsigned conversions:
   `(f32)(u32)byte` is retail's `lbu` + `bltz` + halved-`srl/andi/or` +
   `add.s` sequence, and `(u8)float` is the `0x4F000000` threshold/`sub.s`
   pair with the mask in both arms.  Hand-expanding either (an s32 copy with
   an explicit sign test, `(u8)(s32)tf` with a threshold branch) left 131
   edits of register colouring and moves; the plain casts match. */
// Intent: advances the five tween channels of one sprite record (position, alpha, colour, scale, colour pulse) by a frame. Each channel waits out its delay (+0x34, +0x60, +0x7E, +0xA0, +0xC8), eases with fclEaseInterpolate and steps its timer with fclAddClamped. Returns the record.
// FUN_002B89A0
s32 fclSpriteUpdateTweens(u8 *arg0) {
    if (((*(s16 *)arg0 & 2) >> 1) == 1) {
        if (*(s16 *)(arg0 + 0x34) == 0) {
            if (*(s8 *)(arg0 + 0x37) == 0) {
                *(f32 *)(arg0 + 0x28) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x36), *(f32 *)(arg0 + 0x18), *(f32 *)(arg0 + 0x20), (f32)*(s16 *)(arg0 + 0x32), (f32)*(s16 *)(arg0 + 0x30));
                *(f32 *)(arg0 + 0x2C) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x36), *(f32 *)(arg0 + 0x1C), *(f32 *)(arg0 + 0x24), (f32)*(s16 *)(arg0 + 0x32), (f32)*(s16 *)(arg0 + 0x30));
            } else {
                *(f32 *)(arg0 + 0x28) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x36), *(f32 *)(arg0 + 0x18), *(f32 *)(arg0 + 0x20), (f32)*(s16 *)(arg0 + 0x32), (f32)(*(s16 *)(arg0 + 0x30) / 2));
                *(f32 *)(arg0 + 0x2C) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x36), *(f32 *)(arg0 + 0x1C), *(f32 *)(arg0 + 0x24), (f32)*(s16 *)(arg0 + 0x32), (f32)(*(s16 *)(arg0 + 0x30) / 2));
            }
            if (*(s16 *)(arg0 + 0x32) < *(s16 *)(arg0 + 0x30)) {
                *(s16 *)(arg0 + 0x32) = fclAddClamped((s32)*(s16 *)(arg0 + 0x32), 1, (s32)*(s16 *)(arg0 + 0x30), 0, 1);
            } else {
                *(f32 *)(arg0 + 0x28) = *(f32 *)(arg0 + 0x20);
                *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x24);
                if (*(s8 *)(arg0 + 0x37) == 1) {
                    *(f32 *)(arg0 + 0x28) = *(f32 *)(arg0 + 0x18);
                    *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x1C);
                }
                if (((*(s16 *)arg0 & 0x1000) >> 12) == 1) {
                    *(s16 *)(arg0 + 0x32) = 1;
                } else {
                    *(s16 *)arg0 &= ~2;
                }
            }
        } else {
            *(s16 *)(arg0 + 0x34) = fclSubClamped((s32)*(s16 *)(arg0 + 0x34), 1, 0, 0, 1);
        }
    } else if (((*(s16 *)arg0 & 0x80) >> 7) == 1) {
        *(f32 *)(arg0 + 0x2C) = fclEaseInterpolate(1, *(f32 *)(arg0 + 0x24), *(f32 *)(arg0 + 0x24) - *(f32 *)(arg0 + 0xE8), (f32)*(s16 *)(arg0 + 0xEC), (f32)(*(s16 *)(arg0 + 0xEE) / 2));
        if (*(s16 *)(arg0 + 0xEC) < *(s16 *)(arg0 + 0xEE)) {
            *(s16 *)(arg0 + 0xEC) = fclAddClamped((s32)*(s16 *)(arg0 + 0xEC), 1, (s32)*(s16 *)(arg0 + 0xEE), 0, 1);
        } else {
            *(f32 *)(arg0 + 0x28) = *(f32 *)(arg0 + 0x20);
            *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x24);
            *(s16 *)arg0 &= ~0x80;
        }
    }
    if (((*(s16 *)arg0 & 4) >> 2) == 1) {
        if (*(s16 *)(arg0 + 0x60) == 0) {
            if (*(s8 *)(arg0 + 0x63) == 0) {
                arg0[0x5E] = (u8)fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x62), (f32)(u32)arg0[0x5C], (f32)(u32)arg0[0x5D], (f32)*(s16 *)(arg0 + 0x5A), (f32)*(s16 *)(arg0 + 0x58));
            } else {
                arg0[0x5E] = (u8)fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x62), (f32)(u32)arg0[0x5C], (f32)(u32)arg0[0x5D], (f32)*(s16 *)(arg0 + 0x5A), (f32)(*(s16 *)(arg0 + 0x58) / 2));
            }
            if (*(s16 *)(arg0 + 0x5A) < *(s16 *)(arg0 + 0x58)) {
                *(s16 *)(arg0 + 0x5A) = fclAddClamped((s32)*(s16 *)(arg0 + 0x5A), 1, (s32)*(s16 *)(arg0 + 0x58), 0, 1);
            } else {
                arg0[0x5E] = arg0[0x5D];
                if (*(s8 *)(arg0 + 0x63) == 1) {
                    arg0[0x5E] = arg0[0x5C];
                }
                if (((*(s16 *)arg0 & 0x800) >> 11) == 1) {
                    *(s16 *)(arg0 + 0x5A) = 1;
                } else {
                    *(s16 *)arg0 &= ~4;
                }
            }
        } else {
            *(s16 *)(arg0 + 0x60) = fclSubClamped((s32)*(s16 *)(arg0 + 0x60), 1, 0, 0, 1);
        }
    }
    if (((*(s16 *)arg0 & 0x200) >> 9) == 1) {
        if (*(s16 *)(arg0 + 0x7E) == 0) {
            if (*(s8 *)(arg0 + 0x81) == 0) {
                arg0[0x75] = (u8)fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x80), (f32)(u32)arg0[0x6D], (f32)(u32)arg0[0x71], (f32)*(s16 *)(arg0 + 0x7C), (f32)*(s16 *)(arg0 + 0x7A));
                arg0[0x76] = (u8)fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x80), (f32)(u32)arg0[0x6E], (f32)(u32)arg0[0x72], (f32)*(s16 *)(arg0 + 0x7C), (f32)*(s16 *)(arg0 + 0x7A));
                arg0[0x77] = (u8)fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x80), (f32)(u32)arg0[0x6F], (f32)(u32)arg0[0x73], (f32)*(s16 *)(arg0 + 0x7C), (f32)*(s16 *)(arg0 + 0x7A));
            } else {
                arg0[0x75] = (u8)fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x80), (f32)(u32)arg0[0x6D], (f32)(u32)arg0[0x71], (f32)*(s16 *)(arg0 + 0x7C), (f32)(*(s16 *)(arg0 + 0x7A) / 2));
                arg0[0x76] = (u8)fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x80), (f32)(u32)arg0[0x6E], (f32)(u32)arg0[0x72], (f32)*(s16 *)(arg0 + 0x7C), (f32)(*(s16 *)(arg0 + 0x7A) / 2));
                arg0[0x77] = (u8)fclEaseInterpolate((s32)*(s8 *)(arg0 + 0x80), (f32)(u32)arg0[0x6F], (f32)(u32)arg0[0x73], (f32)*(s16 *)(arg0 + 0x7C), (f32)(*(s16 *)(arg0 + 0x7A) / 2));
            }
            if (((*(s16 *)arg0 & 0x40) >> 6) == 1) {
                *(s16 *)(arg0 + 0x7C) = fclAddClamped((s32)*(s16 *)(arg0 + 0x7C), 1, (s32)*(s16 *)(arg0 + 0x7A), 1, 2);
            } else if (*(s16 *)(arg0 + 0x7C) < *(s16 *)(arg0 + 0x7A)) {
                *(s16 *)(arg0 + 0x7C) = fclAddClamped((s32)*(s16 *)(arg0 + 0x7C), 1, (s32)*(s16 *)(arg0 + 0x7A), 0, 1);
            } else {
                arg0[0x75] = arg0[0x71];
                arg0[0x76] = arg0[0x72];
                arg0[0x77] = arg0[0x73];
                if (*(s8 *)(arg0 + 0x81) == 1) {
                    arg0[0x75] = arg0[0x6D];
                    arg0[0x76] = arg0[0x6E];
                    arg0[0x77] = arg0[0x6F];
                }
                *(s16 *)arg0 &= ~0x200;
            }
        } else {
            *(s16 *)(arg0 + 0x7E) = fclSubClamped((s32)*(s16 *)(arg0 + 0x7E), 1, 0, 0, 1);
        }
    }
    if (((*(s16 *)arg0 & 0x10) >> 4) == 1) {
        if (*(s16 *)(arg0 + 0xA0) == 0) {
            if (*(s8 *)(arg0 + 0xA3) == 0) {
                *(f32 *)(arg0 + 0x90) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0xA2), *(f32 *)(arg0 + 0x88), *(f32 *)(arg0 + 0x8C), (f32)*(s16 *)(arg0 + 0x84), (f32)*(s16 *)(arg0 + 0x82));
                *(f32 *)(arg0 + 0x9C) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0xA2), *(f32 *)(arg0 + 0x94), *(f32 *)(arg0 + 0x98), (f32)*(s16 *)(arg0 + 0x84), (f32)*(s16 *)(arg0 + 0x82));
            } else {
                *(f32 *)(arg0 + 0x90) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0xA2), *(f32 *)(arg0 + 0x88), *(f32 *)(arg0 + 0x8C), (f32)*(s16 *)(arg0 + 0x84), (f32)(*(s16 *)(arg0 + 0x82) / 2));
                *(f32 *)(arg0 + 0x9C) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0xA2), *(f32 *)(arg0 + 0x94), *(f32 *)(arg0 + 0x98), (f32)*(s16 *)(arg0 + 0x84), (f32)(*(s16 *)(arg0 + 0x82) / 2));
            }
            if (((*(s16 *)arg0 & 0x40) >> 6) == 1) {
                *(s16 *)(arg0 + 0x84) = fclAddClamped((s32)*(s16 *)(arg0 + 0x84), 1, (s32)*(s16 *)(arg0 + 0x82), 1, 2);
            } else if (*(s16 *)(arg0 + 0x84) < *(s16 *)(arg0 + 0x82)) {
                *(s16 *)(arg0 + 0x84) = fclAddClamped((s32)*(s16 *)(arg0 + 0x84), 1, (s32)*(s16 *)(arg0 + 0x82), 0, 1);
            } else {
                *(f32 *)(arg0 + 0x90) = *(f32 *)(arg0 + 0x8C);
                *(f32 *)(arg0 + 0x9C) = *(f32 *)(arg0 + 0x98);
                if (*(s8 *)(arg0 + 0xA3) == 1) {
                    *(f32 *)(arg0 + 0x90) = *(f32 *)(arg0 + 0x88);
                    *(f32 *)(arg0 + 0x9C) = *(f32 *)(arg0 + 0x94);
                }
                *(s16 *)arg0 &= ~0x10;
            }
        } else {
            *(s16 *)(arg0 + 0xA0) = fclSubClamped((s32)*(s16 *)(arg0 + 0xA0), 1, 0, 0, 1);
        }
    }
    if (((*(s16 *)arg0 & 8) >> 3) == 1) {
        if (*(s16 *)(arg0 + 0xC8) == 0) {
            if (*(s8 *)(arg0 + 0xCB) == 0) {
                *(f32 *)(arg0 + 0xC0) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0xCA), *(f32 *)(arg0 + 0xB8), *(f32 *)(arg0 + 0xBC), (f32)*(s16 *)(arg0 + 0xC4), (f32)*(s16 *)(arg0 + 0xC6));
                if (((*(s16 *)arg0 & 0x100) >> 8) == 1) {
                    *(f32 *)(arg0 + 0xC0) = *(f32 *)(arg0 + 0xC0) + (fclEaseInterpolate(1, 0.0f, 50.0f, (f32)*(s16 *)(arg0 + 0xE0), 100.0f) - 25.0f);
                    *(s16 *)(arg0 + 0xE0) = fclAddClamped((s32)*(s16 *)(arg0 + 0xE0), 1, 0xC8, 1, 2);
                }
            } else {
                *(f32 *)(arg0 + 0xC0) = fclEaseInterpolate((s32)*(s8 *)(arg0 + 0xCA), *(f32 *)(arg0 + 0xB8), *(f32 *)(arg0 + 0xBC), (f32)*(s16 *)(arg0 + 0xC4), (f32)(*(s16 *)(arg0 + 0xC6) / 2));
                if (((*(s16 *)arg0 & 0x100) >> 8) == 1) {
                    *(f32 *)(arg0 + 0xC0) = *(f32 *)(arg0 + 0xC0) + (fclEaseInterpolate(1, 0.0f, 50.0f, (f32)*(s16 *)(arg0 + 0xE0), 100.0f) - 25.0f);
                    *(s16 *)(arg0 + 0xE0) = fclAddClamped((s32)*(s16 *)(arg0 + 0xE0), 1, 0xC8, 1, 2);
                }
            }
            if (((*(s16 *)arg0 & 0x40) >> 6) == 1) {
                *(s16 *)(arg0 + 0xC4) = fclAddClamped((s32)*(s16 *)(arg0 + 0xC4), 1, (s32)*(s16 *)(arg0 + 0xC6), 1, 2);
            } else if (*(s16 *)(arg0 + 0xC4) < *(s16 *)(arg0 + 0xC6)) {
                *(s16 *)(arg0 + 0xC4) = fclAddClamped((s32)*(s16 *)(arg0 + 0xC4), 1, (s32)*(s16 *)(arg0 + 0xC6), 0, 1);
            } else {
                *(f32 *)(arg0 + 0xC0) = *(f32 *)(arg0 + 0xBC);
                if (*(s8 *)(arg0 + 0xCB) == 1) {
                    *(f32 *)(arg0 + 0xC0) = *(f32 *)(arg0 + 0xB8);
                }
                *(s16 *)arg0 &= ~8;
            }
        } else {
            *(s16 *)(arg0 + 0xC8) = fclSubClamped((s32)*(s16 *)(arg0 + 0xC8), 1, 0, 0, 1);
        }
    }
    return (s32)arg0;
}

/* measured: opt_loop_invariants on is required for the signed-short loop
   preheader/register shape; removing it produced obj 860B/window 864B with
   50 differing words. */
#pragma opt_loop_invariants on
/* measured: opt_propagation off is required for ordered global/field loads and
   final-call argument setup; removing it produced obj 852B/window 864B with
   130 differing words. */
#pragma opt_propagation off
// Intent: sets the four corner quads of a sprite from the fixed inputs at +0x1F4-+0x200, sets the sky render states for the quad draw, and writes the four corner positions.
// FUN_002B9AB0
void fclSpriteBuildCornerQuads(u8 *arg0, u8 *arg1) {
    f32 scale;
    s16 i;
    s16 j;
    s32 off;
    u8 *p;
    u8 *q;
    f32 d;
    f32 h;
    u32 one;
    u8 *r;
    void (*const *tbl)(u32, u32);

    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    tbl = D_00887300;
    tbl[0](6, 1);
    tbl[0](7, 2);
    tbl[0](8, 1);
    tbl[0](9, 2);
    tbl[0](0xC, 1);
    tbl[0](2, 3);
    tbl[0](0xB, 6);
    tbl[0](0xA, 5);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x1F4);
    *(f32 *)(arg1 + 0x14) = *(f32 *)(arg1 + 0x1F8);
    *(f32 *)(arg1 + 0x50) = *(f32 *)(arg1 + 0x1FC);
    *(f32 *)(arg1 + 0x54) = *(f32 *)(arg1 + 0x1F8);
    *(f32 *)(arg1 + 0x90) = *(f32 *)(arg1 + 0x1F4);
    *(f32 *)(arg1 + 0x94) = *(f32 *)(arg1 + 0x200);
    *(f32 *)(arg1 + 0xD0) = *(f32 *)(arg1 + 0x1FC);
    *(f32 *)(arg1 + 0xD4) = *(f32 *)(arg1 + 0x200);
    for (i = 0; i < 4; i++) {
        j = i;
        p = arg1;
        q = (u8 *)((s32)p + (off = (s32)j << 6));
        d = *(f32 *)D_008872F8;
        h = *(f32 *)(arg1 + 0x108);
        *(f32 *)(q + 8) = d - h;
        *(f32 *)(q + 0x18) = scale;
        *(f32 *)(q + 0x20) = (f32)(u32)arg1[0x179];
        *(f32 *)(q + 0x24) = (f32)(u32)arg1[0x17A];
        *(f32 *)(q + 0x28) = (f32)(u32)arg1[0x17B];
        *(f32 *)(q + 0x2C) = (f32)(u32)arg1[0x162];
    }
    *(f32 *)(arg1 + 0x0) = *(f32 *)(arg1 + 0x12C);
    *(f32 *)(arg1 + 0x4) = *(f32 *)(arg1 + 0x130);
    *(f32 *)(arg1 + 0x40) = *(f32 *)(arg1 + 0x12C) +
                            (f32)*(s32 *)(arg1 + 0x20C) * *(f32 *)(arg1 + 0x194);
    *(f32 *)(arg1 + 0x44) = *(f32 *)(arg1 + 0x130);
    *(f32 *)(arg1 + 0x80) = *(f32 *)(arg1 + 0x12C);
    *(f32 *)(arg1 + 0x84) = *(f32 *)(arg1 + 0x130) +
                            (f32)*(s32 *)(arg1 + 0x210) * *(f32 *)(arg1 + 0x1A0);
    *(f32 *)(arg1 + 0xC0) = *(f32 *)(arg1 + 0x12C) +
                            (f32)*(s32 *)(arg1 + 0x20C) * *(f32 *)(arg1 + 0x194);
    *(f32 *)(arg1 + 0xC4) = *(f32 *)(arg1 + 0x130) +
                            (f32)*(s32 *)(arg1 + 0x210) * *(f32 *)(arg1 + 0x1A0);
    r = *(u8 **)(arg1 + 0x214);
    one = 1;
    tbl[0](one, *(s32 *)r);
}
#pragma opt_propagation on
/* measured probe: restore opt_loop_invariants after fclSpriteBuildCornerQuads. */
#pragma opt_loop_invariants off


/* measured: opt_propagation off orders the compare loads as retail (0x194 field
   into f0, then the fGpffff8504 global into f1 via the g local). The recompute of
   the entry pointer after the compares is the (u32)i * 0x220 spelling, which mwcc
   does not CSE with the s32 form above. Declaration order q,p,i,r colours s0..s3. */
#pragma opt_propagation off
// Intent: updates the list's entries (count at +0x6600). An active entry advances its tweens and queues fclSpriteBuildCornerQuads while visible; an idle one clears its active bit.
// FUN_002B9E10
s32 fclSpriteListUpdate(u8 *arg0) {
    u8 *q;
    u8 *p;
    s32 i;
    s16 *r;
    f32 a;
    f32 g;

    q = *(u8 **)(arg0 + 0x38);
    p = q;
    for (i = 0; i < *(s16 *)(p + 0x6600); i++) {
        q = p + i * 0x220;
        r = (s16 *)(q + 0x104);
        if ((*(s16 *)(q + 0x104) & 1) == 1) {
            memcpy((void *)r, fclSpriteUpdateTweens((u8 *)r), 0xF0);
            a = *(f32 *)(q + 0x194);
            g = fGpffff8504;
            if (!(a <= g) && !(*(f32 *)(q + 0x1A0) <= g) && (q[0x162] > 0)) {
                u8 *res;
                u8 *e;
                e = p + (u32)i * 0x220;
                res = func_00461390(D_00793E80 + *(s16 *)(e + 0x100) * 0x30, 4, (void *)e, 4);
                *(void **)(res + 8) = (void *)fclSpriteBuildCornerQuads;
                *(u8 **)(res + 0x10) = e;
            } else {
                if (*r == 1) {
                    *r &= ~1;
                }
            }
        }
    }
    return 0;
}
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
// Intent: destroy callback for the 0x6610-byte list task created by fclSpriteListCreateChild (frees the work block at +0x38).
// FUN_002B9F60
void fclSpriteDestroyListTask(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

// Intent: creates a child task with a 0x6610-byte list of 48 entries of 0x220 bytes, clears each entry's state and sets the list's count argument at +0x6600.
// FUN_002B9F90
s32 fclSpriteListCreateChild(s32 arg0, s16 arg1, s32 arg2) {
    s32 handle;
    u8 *p;
    s32 i;
    chkmemAllocSiteTag(&D_0063F178, 0x693);
    p = D_008873F4[0](1, 0x6610, 0x40000);
    handle = (s32)kwlnTaskCreateChild((void *)((void *)(arg0)), (const void *)(D_0063F1E0), 0xF, 0, 0, fclSpriteListUpdate, fclSpriteDestroyListTask, (u8 *)(p));
    for (i = 0; i < 0x30; i++) {
        *(s16 *)(p + i * 0x220 + 0x104) = 0;
        *(u32 *)(p + i * 0x220 + 0x214) = arg2;
    }
    *(s16 *)(p + 0x6600) = arg1;
    return handle;
}
