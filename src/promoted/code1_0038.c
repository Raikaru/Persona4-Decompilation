#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "btl_shuffle_draw_internal.h"
#include "shd_misc_internal.h"
#include "sdk_snd_internal.h"
#include "ed_staff_internal.h"
#include "datPersona_internal.h"
extern void (*jtbl_008873EC[])(void *);

extern void (*D_008873ec[])(s32);

void btlShuffleDrawViewRequestStep(u8 *arg0, u8 arg1, u8 arg2, u8 arg3);

s32 datGetFlag(u32 arg0);

extern u8 *D_007246AC;
void func_00389180(u8 *arg0);
extern void memset(void *dst, s32 value, u32 size);
extern void nmMesWindowShowCurrentRecord(s32 arg0);
extern void nmMesWindowSetCurrentString(s32 arg0, void *arg1);
extern s32 btlShuffleDrawCheck(u8 *arg0, u8 *arg1);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064ECA0[];
extern u8 D_0064EED0[];
extern void func_00389cb0(u8 *arg0);
extern void btlShuffleDrawCardReset(u8 *arg0);
extern void func_003889b0(s32 arg0, u8 *arg1);
extern void chkmemAllocSiteTag(const void *arg0, s32 arg1);

extern void btlShuffleDrawViewClearFlags(u8 *arg0);
extern void func_003874c0(s32 arg0, u8 *arg1);
extern s32 btlShuffleDrawViewStep(u8 *arg0);
extern void btlShuffleDrawViewDestroy(u8 *arg0);
extern u8 *iGpffffb5b0;
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_00795E30[];
extern u8 D_00795EF0[];
extern u8 D_0064EEB0[];
extern void PrimAppendNode(u8 *arg0, u8 *arg1);
extern void kAssertFail(void *arg0, s32 arg1);
extern void sdkRenderStateSetDefault(void);
extern void func_0038acd0(u8 *arg0);
extern void func_0038bab0(u8 *arg0);
extern void func_0038c100(u8 *arg0);
extern void func_0038c770(u8 *arg0);
extern void func_0038cab0(u8 *arg0);

extern f32 D_00761470;
extern f32 D_008872F8[];
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern s32 (*D_00887310[])(s32, void *, s32);
extern s32 kwlnGetCamera(void);
extern f32 cosf(f32 fparg0);
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
extern u8 D_0064F0E0[];
extern u8 D_0064EEF0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
extern s32 func_003df590(s32 arg0, ...);
extern u8 *func_003df4d0(s32 *arg0);
extern void func_00389370();
extern void func_00389640();
extern void btlShuffleDrawWave();
extern void func_0038a940();
extern void func_0038b1c0();
extern void sdkSpriteDrawOnceAt(s32 resource, s32 slot, f32 x, f32 y,
                          u8 r, u8 g, u8 b, u8 alpha);
extern void sdkSpriteDrawOnceScaled(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                          f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0,
                          s16 arg_sp8);
static inline u32 add_offset_first_0038(u32 offset, u32 base)
{
    return offset + base;
}

/* Window frame fade.  The 192 alpha is converted at each vertex (u8)(192.0f *
   scale) - the product is shared, the float->u8 conversion is not - and the
   primitive table is read through an integer view so its address stays in
   $s0 across the first draw, as in fclCmbBallDraw's twin 0014dd80 recipe. */
/* The two work floats are each reused across the phases, as retail's FP
   colouring shows: `ratio` holds the first-phase interpolation and then the
   width delta, `extent` the start value and then the half width.
   -0.2617994f is -15 degrees in radians (the sprite below is drawn at -15.0f);
   it and the other float literals are pooled in retail's gp data. */

/* This helper retains the radius-scale operation with the same operand
 * order as the other circular drawing primitives. */
static inline f32 code38ScaleRadius(f32 value, f32 scale)
{
    return scale * value;
}

static inline f32 code38QuarterTurnOffset(s32 index)
{
    extern f32 fGpffff83d8;
    return fGpffff83d8 * (f32)index;
}

/* Persona list panel. The slide-in ease is 2t - t*t, clamped. Every
   position term is written with a (0.0f + K) origin, as the sibling ring
   drawers are. The title x stays in a register and is also stored to
   pos.x. */

/* measured: opt_rebuildconditionals off preserves the retail positive branch. */
#pragma opt_rebuildconditionals off
/* measured: restore conditional rebuilding after this function. */
#pragma opt_rebuildconditionals on

/* Animate four sprites with interpolated colors and rotated pixel offsets.
   The timer and random samples are snapshots; angle division precedes
   multiplication, and the second sine result is converted to a signed
   pixel offset after scaling. Opacity crosses the sprite API as a byte. */
/* measured: opt_loop_invariants on hoists the conversion constants into the retail preheader. */
#pragma opt_loop_invariants on
/* measured: restore loop-invariant optimization after func_00389cb0. */
#pragma opt_loop_invariants off
typedef union Code38WavePhase {
    Vec2f direction[2];
    Vec2f pair[2];
} Code38WavePhase;

typedef struct Code38WaveWorkspace {
    Vec2f normal[2];
    Code38WavePhase phase;
    BtlShuffleSkyVertex vertices[62];
    /* Retail leaves sp+0x1030..0x1037 unused; this layout places delta at sp+0x1038. */
    u32 pad[2];
    Vec2f delta;
} Code38WaveWorkspace;

/* Ring samples use complete three-component vectors and two vertices per
 * sample. The 65 samples occupy the entire 130-vertex buffer. */
typedef struct Code38RingVertex {
    f32 x, y, z;
    u32 pad0, pad1, pad2;
    f32 reciprocalZ;
    u32 pad3;
    f32 color[4];
    u32 tail[4];
} Code38RingVertex;

static inline void code38RingVertex(Code38RingVertex *vertex,
    f32 x, f32 y, f32 depth, f32 reciprocalZ, u32 r, u32 g, u32 b, u32 a)
{
    vertex->x = x;
    vertex->y = y;
    vertex->z = depth;
    vertex->color[0] = (f32)r;
    vertex->color[1] = (f32)g;
    vertex->color[2] = (f32)b;
    vertex->color[3] = (f32)a;
    vertex->reciprocalZ = reciprocalZ;
}

/* Measured: 904/912 bytes, eleven resolved relocations and eight zero
 * alignment bytes. D_00761490 is the retail scalar 0xBD872B00, not the
 * rounded -0.066f literal; keep the five-frame and 300-frame reloads. */
#pragma opt_propagation off
#pragma opt_propagation on
typedef struct Code38RevealWeight {
    f32 value;
} Code38RevealWeight;

#pragma push
#pragma opt_loop_invariants on

#pragma pop

// measured: preserve retail argument materialization order
#pragma opt_propagation off
// measured: restore propagation default
#pragma opt_propagation on
typedef struct {
    u16 counter;
    u16 pad;
    f32 x;
    f32 z;
    f32 y;
    f32 w;
} State_0038CAB0;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u32 pad0;
    u32 pad1;
    u32 pad2;
    f32 scale;
    u32 pad3;
    f32 color[4];
    u32 tail[4];
} Vertex_0038CAB0;

// FUN_0038D660
s32 btlShuffleEffStep(u8 *arg0) {
    s32 *work;

    work = (s32 *)(*(s32 **)(arg0 + 0x38));
    btlShuffleDrawViewReset(*work);
    btlShuffleEffUpdate(arg0);
    func_0038d330(work);
    return 0;
}

#pragma schedule on
#pragma no_branch_likely on
// FUN_0038F990
u8 *func_0038f990(u16 arg0, u16 arg1, f32 *arg2, s32 arg3)
{
    u8 *temp_6;
    s32 temp_16;
    s32 temp_22;
    s32 temp_4;
    s32 var_17;
    u8 *temp_2;
    f32 temp_f1;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f3;
    s32 fail_words[2];
    temp_16 = arg1 & 0xFFFF;
    var_17 = 0x28;

    if (temp_16 > 0) {
        var_17 += (temp_16 * 0x10) + 0xF;
    }
    goto dispatch_0;

add_0:
    var_17 += ((arg0 & 0xFFFF) * 2) + 1;

alloc_0:
    temp_2 = jtbl_008873E8[0](var_17, 0x3002C);
    if (temp_2 == NULL) {
        goto failure_0;
    }
    *(s32 *)(temp_2 + 0) = arg3;
    temp_6 = temp_2;
    *(u16 *)(temp_2 + 0x1C) = arg0;
    *(u16 *)(temp_2 + 0x1E) = arg1;
    temp_f0 = arg2[0];
    temp_f1 = arg2[1];
    temp_f2 = arg2[2];
    temp_f3 = arg2[3];
    *(f32 *)(temp_2 + 4) = temp_f0;
    *(f32 *)(temp_2 + 8) = temp_f1;
    *(f32 *)(temp_2 + 0xC) = temp_f2;
    *(f32 *)(temp_2 + 0x10) = temp_f3;
    temp_f1 = *(f32 *)((u8 *)arg2 + 0x10);
    temp_f0 = temp_f1;
    temp_f1 = *(f32 *)((u8 *)arg2 + 0x14);
    *(f32 *)(temp_2 + 0x14) = temp_f0;
    *(f32 *)(temp_2 + 0x18) = temp_f1;
    temp_2 += 0x28;
    if (temp_16 <= 0) {
        goto zero_extra;
    }
    temp_4 = ((s32)(temp_2 + 0xF)) & ~0xF;
    temp_2 = (u8 *)(temp_4 + (temp_16 * 0x10));
    *(s32 *)(temp_6 + 0x20) = temp_4;

pointer_0:
    if (temp_22 != 0) {
        *(s32 *)(temp_6 + 0x24) = ((s32)(temp_2 + 1)) & ~1;
    } else {
        *(s32 *)(temp_6 + 0x24) = 0;
    }
    return temp_6;
dispatch_0:
    temp_22 = arg3 & 1;
    switch (temp_22) {
    case 0:
        goto alloc_0;
    default:
        goto add_0;
    }

failure_0:
    fail_words[0] = 0x11D;
    fail_words[1] = func_003df590(0x80000013, var_17);
    func_003df4d0(fail_words);
    return NULL;
zero_extra:
    *(s32 *)(temp_6 + 0x20) = 0;
    goto pointer_0;
}
/* measured: closes the bracket opened above func_0038f990, which matches at
   object 372 against the 384-byte window at nd 0 with the float copy-chain
   locals; the explicit off restores the file baseline for what follows. */
#pragma schedule off
#pragma no_branch_likely off
// measured: b210 at -O2 folds (a*0x10)+0x30 into one addiu in the beqz delay
// slot (11 words); schedule on with the constant materialized first reproduces
// retail's hoisted addiu $a1,0x30 + addu $v0,$a1,$v0 delay-slot pair (12 words).
#pragma schedule on
// FUN_0038FB20
s32 func_0038fb20(u8 *arg0) {
    s32 var_2;

    var_2 = 0x30;
    var_2 += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        var_2 += *(u16 *)(arg0 + 0x1C) * 2;
    }
    return var_2;
}
// measured: closing bracket for the schedule-on above; the function body is
// already compiled, so this off only satisfies decomp_lint P001 balance.
#pragma schedule off
/* FUN_0038FB50, FUN_0038FD30: matched in src/promoted/code1_0038_cw119.c */

/* measured: probe_variants func_0038fe90 fixed (externs corrected, jtbl redeclare removed) 216wd (vs stale archive 732wd oversized), sched 191wd win (-25), loop_invariants 215wd tie, sched inclusive (value<0xF0 -> <=0xEF) 191wd tie (fndiff both slti $at, exclusive already $at so lever neutral here); fnalign sched 246 edits (frame 0x140 vs retail 0x110 + scheduling + address chains, plus 4 reloc-only); lever 4 tie per above; parent lesson: schedule measured, common_subs off COMPILE ERROR (pragma+body interaction, banked without it), loop_invariants tie; lb (lbu correct for u8 record bytes) checked; double-def offset (addu base+off after lw at 28FF24/28FF30) remains; re-derived (5-arg f990, 3-arg df360/df300, 1-arg e2ce0, jtbl void* per file-scope, Ghidra/IDA 5-arg confirmed); archive docs/probe_archive/P038_0038fe90_body.c (stale oversized). Banked guarded floor with sched bracket; revisit (2.4% short 204v209): sched+common_subs push 192wd tie+1 (not adopted), dead-arm N/A (no trailing empty else-if, ends with flag-gated j-loop + return), compare-chain N/A (two ==2 tests on different bytes, not adjacent K/K+1). */
/* FUN_0038FE90: matched in src/promoted/code1_0038_cw119.c */
extern u8 *func_0038fe90(u8 *arg0, u32 arg1, s32 arg2, f32 *arg3, s32 *arg4);
