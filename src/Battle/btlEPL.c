#include "btl_effect_internal.h"
#include "datCalc_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "effect_instance_internal.h"
/* Original translation unit btlEPL.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

extern void mdlEffectDestroyModel(s32 input);
extern void (*jtbl_008873EC[])(void *);

extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern s32 mdlEffectCreateUniqueModel(s32 model, s32 size);
extern s32 EffModelFindOrCreate(s32 effect);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00625230[];

static u8 *D_0072449C;

extern void btlUnitGetAnchorPose(void *unit, void *outPosition, void *outRotation, void *outTarget);
extern void btlUnitSetPos(void *unit, void *pos);
extern void btlUnitSetRot(void *unit, void *rot);
extern void mdlEffectBuildBasisRows(void *output, void *orientation);
extern void mdlApplyModelMatrix(void *model, void *matrix, s32 combineOp);
extern void mdlScale(void *model, void *scale, s32 combineOp);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern void mdlSetLayerWeight(void *model, s32 layer, f32 speed);
extern void mdlAdvanceModelFromFlags(void *model);
extern s32 mdlCopyIndexedMatrix(void *model, s32 index, void *destination);
extern void RwMatrixScale(void *input, f32 *value, s32 options);
extern void RwMatrixMultiply(void *input, void *value, void *options);
extern void RtQuatConvertFromMatrix(void *input, void *value);
extern void btlTargetNormalizeVector(void *source, void *destination);
extern u32 mdlCountIntUserData(u32 model);
extern void btlUnitClearModelState(void *unit, s32 mode);
extern void btlUnitSetModelAnimFrame(void *unit, s32 frame);
extern void btlUnitApplyModelState(void *unit, s32 mode);
extern s32 mdlComputeIndexedAttachMatrix(void *model, s32 index, void *destination);
extern u8 *btlMainGetSceneColorBlock(void);
extern u8 *btlMainGetSceneList4Block(void);
extern u8 *btlMainGetSceneList4SavedBlock(void);
extern u8 *btlMainGetSceneRgbaBlock(void);
extern void resrcMngApplyColorFactors(void *value);
extern u8 *resrcMngGetColorValue(void);
extern u8 *resrcMngGetColorTarget(void);
extern f32 D_0076129C;
extern f32 D_00922CA0[];
extern s32 D_00922CC0[];
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct
{
    f32 v[4];
} V4;

/* Common callback context prefix: every EPL updater reads count/target/params
 * at the same offsets. The complete allocation extends beyond this prefix. */
typedef struct BtlEplEffect {
    f32 position[3];       /* 0x00 */
    u8 pad0C[4];
    f32 rotation[4];       /* 0x10 */
    f32 scale;             /* 0x20 */
    u8 pad24[4];
    u32 count;             /* 0x28 */
    u8 pad2C[4];
    void *target;          /* 0x30: model handle or saved colors */
    u8 pad34[4];
    void *params;          /* 0x38: parameter type depends on callback */
} BtlEplEffect;

typedef struct BtlEplEplWork
{
    s32 target;   // 0x00
    s16 pattern;  // 0x04
} BtlEplEplWork; // 0x08

typedef struct BtlEplColor
{
    u8 r; // 0x00
    u8 g; // 0x01
    u8 b; // 0x02
    u8 a; // 0x03
} BtlEplColor; // 0x04

typedef union BtlEplRgba
{
    u32 rgba;
    BtlEplColor c;
} BtlEplRgba; // 0x04

extern BtlEplColor D_007641F8;
extern BtlEplColor D_00764C54;

typedef struct BtlEplFadeParam
{
    u32 total;        // 0x00
    u16 fadeIn;       // 0x04
    u16 fadeOut;      // 0x06
    BtlEplRgba color; // 0x08
} BtlEplFadeParam;

/* Normalize packed effect color channels into a four-component vector. */
static inline void btlEplColorToVector(V4 *out, const BtlEplColor *rgba)
{
    out->v[0] = (1.0f / 255.0f) * (f32)(u32)rgba->r;
    out->v[1] = (1.0f / 255.0f) * (f32)(u32)rgba->g;
    out->v[2] = (1.0f / 255.0f) * (f32)(u32)rgba->b;
    out->v[3] = (1.0f / 255.0f) * (f32)(u32)rgba->a;
}


typedef struct BtlEplSelect
{
    u8 kind[2]; // 0x00: for reference slot n (D_00881440_abs[n]) when unit->unkA2 matches it:
                //       0 rejects, 1 accepts only that entry, 2 accepts; other values fall through
    u8 mask;    // 0x02: bit n selects unit slot n + 2
    u8 all;     // 0x03: nonzero accepts every unit
} BtlEplSelect;

typedef struct BtlEplV3
{
    f32 x;
    f32 y;
    f32 z;
} BtlEplV3;

typedef struct BtlEplUnit
{
    u8 pad00[0x38];
    BtlEplColor startRgba;   // 0x38
    BtlEplColor rgba;        // 0x3C
    u8 pad40[0x14];
    BtlEplV3 pos;            // 0x54
    V4 startColor;           // 0x60
    V4 color;                // 0x70
    u8 pad80[0x18];
    u32 flags;               // 0x98
    u8 pad9C[6];
    u8 unkA2;                // 0xA2, compared by btlEplUnitIsSelected
    u8 padA3[0x935];
    u16 unk9D8;             // 0x9D8, bit 8 set by btlEplUnitApplyMotion
    u8 pad9DA[0x12];
    s16 motion;             // 0x9EC, stored motion id, read by btlEplApplyScaleEffect
    u8 pad9EE[2];
    f32 rate;               // 0x9F0, stored motion rate
    s8 option;              // 0x9F4, stored motion option
    u8 pad9F5[0x6F];
    DatUnit *datUnit;        // 0xA64, DatUnit record of this unit
    u8 padA68[4];
    struct BtlEplUnit *next; // 0xA6C
} BtlEplUnit;
extern BtlEplUnit *D_00881440_abs[];

/* measured: opt_loop_invariants on keeps the table base and the constant 1 hoisted above the
   scan loop as retail; a `for` form of the scan loop mismatched at `cmp 8`, so the goto
   ladder stays. The mode-1 blocks are `var = 1; if (slot == arg0) { t = var; } else
   { var = 0; t = var; } return (s8)t;` - the copy at the join keeps the then-branch as
   retail's `b join` trampoline (the plain if/else folds to xor/sltiu under rebuildconditionals,
   which must stay off for these two blocks). */
/* Accept all units, masked explicit slots, or the requested same-kind anchor group.
 * Kind 1 selects only its anchor; kind 2 selects every unit of that kind. */
// FUN_001FC300
/* Selection predicate for EPL unit loops; see BtlEplSelect.
 * measured: loop-invariant hoisting and the mode-1 branch form are justified above. */
/* measured: structured selection scanning retains 71 baseline words; either selection toggle alone differs. */
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
static s64 btlEplUnitIsSelected(BtlEplUnit *unit, BtlEplSelect *select)
{
    BtlEplUnit **table;
    BtlEplUnit *entry;
    s32 slot;
    s32 one;
    s64 isEntry1;
    s64 t;
    s64 isEntry0;
    u32 bit;
    u8 kind0;
    u8 kind1;

    if (select->all != 0) {
        return 1;
    }
    slot = 0;
    table = D_00881440_abs;
    one = 1;
    goto loop_test;
loop_body:
    entry = table[2 + (u16)slot];
    if (entry != NULL) {
        if ((select->mask & (one << bit)) && (entry == unit)) {
            return 1;
        }
        slot = (slot + 1) & 0xFFFF;
        goto loop_test;
    }
    goto block_9;
loop_test:
    bit = slot & 0xFFFF;
    if (bit < 3U) {
        goto loop_body;
    }
block_9:
    if ((D_00881440_abs[0] != NULL) &&
        (unit->unkA2 == D_00881440_abs[0]->unkA2)) {
        kind0 = select->kind[0];
        switch (kind0) {
        case 0:
            return 0;
        case 1:
            isEntry0 = 1;
            if (D_00881440_abs[0] == unit) {
                t = isEntry0;
            } else {
                isEntry0 = 0;
                t = isEntry0;
            }
            return (s64)(t << 0x38) >> 0x38;
        case 2:
            return 1;
        }
    }
    if ((D_00881440_abs[1] != NULL) &&
        (unit->unkA2 == D_00881440_abs[1]->unkA2)) {
        kind1 = select->kind[1];
        switch (kind1) {
        case 0:
            return 0;
        case 1:
            isEntry1 = 1;
            if (D_00881440_abs[1] == unit) {
                t = isEntry1;
            } else {
                isEntry1 = 0;
                t = isEntry1;
            }
            return (s64)(t << 0x38) >> 0x38;
        case 2:
            return 1;
        }
    }
    return 0;
}
/* measured: restore rebuildconditionals after btlEplUnitIsSelected. */
#pragma opt_rebuildconditionals on
/* measured: restore the unit default after btlEplUnitIsSelected. */
#pragma opt_loop_invariants off
/* Allocate owned model-ID work from kind-3 source data; other kinds retain a zero handle. */
// FUN_001FC4A0
s32 *btlEplNewIdHandle(s32 context, s32 kind, s32 source, s32 options) {
    s32 *result;

    chkmemAllocSiteTag(D_00625230, 0xB1);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    if ((source != 0) && ((kind & 0xFFFF) == 3)) {
        *result = mdlEffectCreateUniqueModel(source, options);
    } else {
        *result = 0;
    }
    return result;
}

/* Allocate owned model-ID work from the unit's source model, or leave the handle zero when absent. */
// FUN_001FC550
s32 *btlEplNewIdHandleFromUnit(u8 *effect) {
    s32 *field;
    s32 *result;
    s32 value;

    field = (s32 *)((BtlEplEffect *)effect)->target;
    chkmemAllocSiteTag(D_00625230, 0xB1);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    value = *field;
    if (value != 0) {
        *result = EffModelFindOrCreate(value);
    } else {
        *result = 0;
    }
    return result;
}
/* Release the model-ID resource when nonzero, then free its work allocation. */
// FUN_001FC5E0
void btlEplFreeIdHandle(s32 *work) {
    if (*work != 0) {
        mdlEffectDestroyModel(*work);
    }
    jtbl_008873EC[0](work);
}


typedef struct BtlEplUnitParam
{
    BtlEplSelect select;   // 0x00, read by btlEplUnitIsSelected
    u8 pad04[8];           // 0x04
    BtlEplFadeParam fade;  // 0x0C
    f32 rotate;            // 0x18
    f32 scale;             // 0x1C
} BtlEplUnitParam;


/* measured: opt_dead_assignments off keeps the four colour conversions ahead of
   the blend products (217 words without it); opt_loop_invariants on hoists the
   mode byte and 1 - scale above the unit loop in retail order. */
/* Fade selected units' normalized colors and position against the EPL model, preserving the distinct fade-in and fade-out snapshots. */
// FUN_001FC630
/* measured: typed effect aliases and cached fade complements retain 341 or more baseline words; either toggle alone differs. */
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void btlEplStepUnitFadeInOut(u8 *effect)
{
    u32 count;
    BtlEplUnitParam *param;
    u8 **model;
    u32 total;
    u8 mode;
    f32 scale;
    s32 hasPos;
    u32 i;
    BtlEplUnit *node;
    BtlEplRgba rgba;
    BtlEplV3 pos;
    f32 vec[3];
    u8 matrix[0x40];

    model = (u8 **)((BtlEplEffect *)effect)->target;
    param = (BtlEplUnitParam *)((BtlEplEffect *)effect)->params;
    count = ((BtlEplEffect *)effect)->count;
    total = param->fade.total;
    if (total < count && total != 0) {
        return;
    }
    mode = 0;
    if (total != 0) {
        if (count <= param->fade.fadeIn) {
            if (param->fade.fadeIn > 0) {
                scale = (f32)count / (f32)param->fade.fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fade.fadeOut) {
            if (param->fade.fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fade.fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    hasPos = 0;
    if (*model != NULL) {
        mdlEffectBuildBasisRows(matrix, ((BtlEplEffect *)effect)->rotation);
        mdlApplyModelMatrix(*model, matrix, 0);
        vec[0] = vec[1] = vec[2] = ((BtlEplEffect *)effect)->scale * param->scale;
        mdlScale(*model, vec, 2);
        vec[0] = ((BtlEplEffect *)effect)->position[0];
        vec[1] = ((BtlEplEffect *)effect)->position[1];
        vec[2] = ((BtlEplEffect *)effect)->position[2];
        mdlTranslateMatrix((RwMatrix *)*model, (const RwV3d *)vec, 2);
        mdlSetLayerWeight(*model, 0, param->rotate);
        mdlAdvanceModelFromFlags(*model);
        if (mdlComputeIndexedAttachMatrix(*model, 0, &pos) != 0) {
            hasPos = 1;
        }
    }
    {

        for (i = 0; i < 4; i++) {
            for (node = (BtlEplUnit *)((BtlBattleState *)D_0072449C)->unitLists[i * 2]; node != NULL; node = node->next) {
                if (btlEplUnitIsSelected(node, &param->select) == 0) {
                    continue;
                }
                switch (mode) {
                case 0:
                    if (count == 0) {
                        rgba.rgba = param->fade.color.rgba;
                        btlEplColorToVector(&node->color, &rgba.c);
                    }
                    break;
                case 1:
                    if (count == 0) {
                        node->startColor = node->color;
                    }
                    rgba.rgba = param->fade.color.rgba;
                    {
                        V4 color;
                        f32 a0, a1, a2, a3;
                        f32 b0, b1, b2, b3;

                        btlEplColorToVector(&color, &rgba.c);
                        a0 = node->startColor.v[0] * (1.0f - scale);
                        a1 = node->startColor.v[1] * (1.0f - scale);
                        a2 = node->startColor.v[2] * (1.0f - scale);
                        a3 = node->startColor.v[3] * (1.0f - scale);
                        b0 = color.v[0] * scale;
                        b1 = color.v[1] * scale;
                        b2 = color.v[2] * scale;
                        b3 = color.v[3];
                        node->color.v[0] = a0 + b0;
                        node->color.v[1] = a1 + b1;
                        node->color.v[2] = a2 + b2;
                        node->color.v[3] = a3 + b3 * scale;
                    }
                    break;
                case 2:
                    if (count == total - param->fade.fadeOut) {
                        node->startColor = node->color;
                    }
                    {
                        V4 color;
                        f32 a0, a1, a2, a3;
                        f32 b0, b1, b2, b3;

                        btlEplColorToVector(&color, &D_00764C54);
                        a0 = color.v[0] * (1.0f - scale);
                        a1 = color.v[1] * (1.0f - scale);
                        a2 = color.v[2] * (1.0f - scale);
                        a3 = color.v[3] * (1.0f - scale);
                        b0 = node->startColor.v[0] * scale;
                        b1 = node->startColor.v[1] * scale;
                        b2 = node->startColor.v[2] * scale;
                        b3 = node->startColor.v[3];
                        node->color.v[0] = a0 + b0;
                        node->color.v[1] = a1 + b1;
                        node->color.v[2] = a2 + b2;
                        node->color.v[3] = a3 + b3 * scale;
                    }
                    break;
                }
                if (hasPos) {
                    node->pos = pos;
                } else {
                    node->pos.x = ((BtlEplEffect *)effect)->position[0];
                    node->pos.y = ((BtlEplEffect *)effect)->position[1];
                    node->pos.z = ((BtlEplEffect *)effect)->position[2];
                }
            }
        }
    }
}
#pragma opt_dead_assignments on
#pragma opt_loop_invariants off

/* Reserve saved-color work for the corresponding EPL fade callback; the allocation size matches its vector count. */
// FUN_001FCE30
void btlEplAllocColorPair(void) {
    chkmemAllocSiteTag(D_00625230, 0x1D3);
    (*jtbl_008873E8)(0x20, 0x40000);
}

/* Release the saved color work through the battle allocator. */
// FUN_001FCE80
void btlEplFreeColorPair(void *work) {
    jtbl_008873EC[0](work);
}

typedef struct BtlEplFade2Param
{
    u32 total;          // 0x00
    u16 fadeIn;         // 0x04
    u16 fadeOut;        // 0x06
    BtlEplRgba color[2]; // 0x08
} BtlEplFade2Param;

/* measured: opt_dead_assignments off keeps the colour conversions where the
   source puts them (first pair converted up front, second pair converted and
   scaled per component); 189 words without it. */
/* Blend the two scene color vectors through the requested fade-in/out interval, saving endpoints at each transition. */
// FUN_001FCEB0
/* measured: typed effect aliases and separate second-vector products retain 259 or more baseline words. */
#pragma opt_dead_assignments off
void btlEplStepColorPairFade(u8 *effect)
{
    u32 count;
    BtlEplFade2Param *param;
    V4 *target;
    u32 total;
    u8 mode;
    f32 scale;
    V4 *dst;
    V4 *src;
    BtlEplRgba rgba;

    target = (V4 *)((BtlEplEffect *)effect)->target;
    param = (BtlEplFade2Param *)((BtlEplEffect *)effect)->params;
    count = ((BtlEplEffect *)effect)->count;
    total = param->total;
    if (total < count && total != 0) {
        return;
    }
    dst = (V4 *)btlMainGetSceneList4Block();
    src = (V4 *)btlMainGetSceneList4SavedBlock();
    mode = 0;
    if (total != 0) {
        if (count <= param->fadeIn) {
            if (param->fadeIn > 0) {
                scale = (f32)count / (f32)param->fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fadeOut) {
            if (param->fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    switch (mode) {
    case 0:
        if (count != 0) {
            return;
        }
        rgba.rgba = param->color[0].rgba;
        btlEplColorToVector(&dst[0], &rgba.c);
        rgba.rgba = param->color[1].rgba;
        btlEplColorToVector(&dst[1], &rgba.c);
        break;
    case 1:
        if (count == 0) {
            target[0] = dst[0];
            target[1] = dst[1];
        }
        {
            V4 color;
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            rgba.rgba = param->color[0].rgba;
            btlEplColorToVector(&color, &rgba.c);
            inv = 1.0f - scale;
            a0 = target[0].v[0] * inv;
            a1 = target[0].v[1] * inv;
            a2 = target[0].v[2] * inv;
            a3 = target[0].v[3] * inv;
            b0 = color.v[0] * scale;
            b1 = color.v[1] * scale;
            b2 = color.v[2] * scale;
            b3 = color.v[3];
            dst[0].v[0] = a0 + b0;
            dst[0].v[1] = a1 + b1;
            dst[0].v[2] = a2 + b2;
            dst[0].v[3] = a3 + b3 * scale;

            rgba.rgba = param->color[1].rgba;
            a0 = target[1].v[0] * inv;
            a1 = target[1].v[1] * inv;
            a2 = target[1].v[2] * inv;
            a3 = target[1].v[3] * inv;
            b0 = (1.0f / 255.0f) * (f32)(u32)rgba.c.r * scale;
            b1 = (1.0f / 255.0f) * (f32)(u32)rgba.c.g * scale;
            b2 = (1.0f / 255.0f) * (f32)(u32)rgba.c.b * scale;
            b3 = (1.0f / 255.0f) * (f32)(u32)rgba.c.a * scale;
            a0 += b0;
            dst[1].v[0] = a0;
            a1 += b1;
            dst[1].v[1] = a1;
            a2 += b2;
            dst[1].v[2] = a2;
            a3 += b3;
            dst[1].v[3] = a3;
        }
        break;
    case 2:
        if (count == total - param->fadeOut) {
            target[0] = dst[0];
            target[1] = dst[1];
        }
        {
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            inv = 1.0f - scale;
            a0 = src[0].v[0] * inv;
            a1 = src[0].v[1] * inv;
            a2 = src[0].v[2] * inv;
            a3 = src[0].v[3] * inv;
            b0 = target[0].v[0] * scale;
            b1 = target[0].v[1] * scale;
            b2 = target[0].v[2] * scale;
            b3 = target[0].v[3];
            dst[0].v[0] = a0 + b0;
            dst[0].v[1] = a1 + b1;
            dst[0].v[2] = a2 + b2;
            dst[0].v[3] = a3 + b3 * scale;
            a0 = src[1].v[0] * inv;
            a1 = src[1].v[1] * inv;
            a2 = src[1].v[2] * inv;
            a3 = src[1].v[3] * inv;
            b0 = target[1].v[0] * scale;
            b1 = target[1].v[1] * scale;
            b2 = target[1].v[2] * scale;
            b3 = target[1].v[3];
            dst[1].v[0] = a0 + b0;
            dst[1].v[1] = a1 + b1;
            dst[1].v[2] = a2 + b2;
            dst[1].v[3] = a3 + b3 * scale;
        }
        break;
    }
}
#pragma opt_dead_assignments on
/* Empty retail EPL entry; its intended parameter or update role is not established. */
// FUN_001FD780
void btlEplUnitRgbaDestroyNoop(void)
{
}

typedef struct BtlEplUnitRgbaParam
{
    BtlEplFadeParam fade; // 0x00
    BtlEplSelect select;  // 0x0C, read by btlEplUnitIsSelected
} BtlEplUnitRgbaParam;

/* Fade-in/out alone initialize and consume the scale complement.
 * The fade-out arm converts two complete normalized RGBA values and computes
 * all four blended outputs before storing any byte. These real value
 * lifetimes reproduce retail's FPR allocation and native operation order.
 * Measured b210: 2172/2176 bytes, four retail-zero tail bytes,
 * 22 resolved target relocations and all 26 sibling functions unchanged. */
/* Fade selected units' packed RGBA channels, rounding normalized results back to bytes and setting their explicit-color flag. */
// FUN_001FD790
/* measured: typed effect aliases and scalar blend arrays retain 377 baseline words; either toggle alone differs. */
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void btlEplStepUnitRgbaFade(u8 *effect)
{
    u32 count;
    BtlEplUnitRgbaParam *param;
    u32 total;
    u8 mode;
    f32 scale;
    u32 i;
    BtlEplUnit *node;
    BtlEplRgba rgba;

    param = (BtlEplUnitRgbaParam *)((BtlEplEffect *)effect)->params;
    count = ((BtlEplEffect *)effect)->count;
    total = param->fade.total;
    if (total < count && total != 0) {
        return;
    }
    mode = 0;
    if (total != 0) {
        if (count <= param->fade.fadeIn) {
            if (param->fade.fadeIn > 0) {
                scale = (f32)count / (f32)param->fade.fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fade.fadeOut) {
            if (param->fade.fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fade.fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    for (i = 0; i < 4; i++) {
        for (node = (BtlEplUnit *)((BtlBattleState *)D_0072449C)->unitLists[i * 2]; node != NULL; node = node->next) {
            if (btlEplUnitIsSelected(node, &param->select) == 0) {
                continue;
            }
            node->flags |= 4;
            switch (mode) {
            case 0:
                if (count == 0) {
                    rgba.rgba = param->fade.color.rgba;
                    node->rgba = rgba.c;
                }
                break;
            case 1:
                if (count == 0) {
                    node->startRgba = node->rgba;
                }
                rgba.rgba = param->fade.color.rgba;
                {
                    const f32 inv = 1.0f - scale;
                    V4 color;
                    V4 start;
                    V4 from;
                    V4 to;

                    btlEplColorToVector(&color, &rgba.c);
                    btlEplColorToVector(&start, &node->startRgba);
                    from.v[0] = start.v[0] * inv;
                    from.v[1] = start.v[1] * inv;
                    from.v[2] = start.v[2] * inv;
                    from.v[3] = start.v[3] * inv;
                    to.v[0] = color.v[0] * scale;
                    to.v[1] = color.v[1] * scale;
                    to.v[2] = color.v[2] * scale;
                    to.v[3] = color.v[3] * scale;
                    color.v[0] = from.v[0] + to.v[0];
                    color.v[1] = from.v[1] + to.v[1];
                    color.v[2] = from.v[2] + to.v[2];
                    color.v[3] = from.v[3] + to.v[3];
                    node->rgba.r = (s32)(0.5f + 255.0f * color.v[0]);
                    node->rgba.g = (s32)(0.5f + 255.0f * color.v[1]);
                    node->rgba.b = (s32)(0.5f + 255.0f * color.v[2]);
                    node->rgba.a = (s32)(0.5f + 255.0f * color.v[3]);
                }
                break;
            case 2:
                if (count == total - param->fade.fadeOut) {
                    node->startRgba = node->rgba;
                }
                {
                    const f32 inv = 1.0f - scale;
                    f32 c0, c1, c2, c3;
                    f32 s0, s1, s2, s3;
                    f32 a0, a1, a2, a3;
                    f32 b0, b1, b2, b3;
                    V4 out;

                    c0 = (1.0f / 255.0f) * (f32)(u32)D_007641F8.r;
                    c1 = (1.0f / 255.0f) * (f32)(u32)D_007641F8.g;
                    c2 = (1.0f / 255.0f) * (f32)(u32)D_007641F8.b;
                    c3 = (1.0f / 255.0f) * (f32)(u32)D_007641F8.a;
                    s0 = (1.0f / 255.0f) * (f32)(u32)node->startRgba.r;
                    s1 = (1.0f / 255.0f) * (f32)(u32)node->startRgba.g;
                    s2 = (1.0f / 255.0f) * (f32)(u32)node->startRgba.b;
                    s3 = (1.0f / 255.0f) * (f32)(u32)node->startRgba.a;
                    a0 = c0 * inv;
                    a1 = c1 * inv;
                    a2 = c2 * inv;
                    a3 = c3 * inv;
                    b0 = s0 * scale;
                    b1 = s1 * scale;
                    b2 = s2 * scale;
                    b3 = s3 * scale;
                    out.v[0] = a0 + b0;
                    out.v[1] = a1 + b1;
                    out.v[2] = a2 + b2;
                    out.v[3] = a3 + b3;
                    node->rgba.r = (s32)(0.5f + 255.0f * out.v[0]);
                    node->rgba.g = (s32)(0.5f + 255.0f * out.v[1]);
                    node->rgba.b = (s32)(0.5f + 255.0f * out.v[2]);
                    node->rgba.a = (s32)(0.5f + 255.0f * out.v[3]);
                }
                break;
            }
        }
    }
}
#pragma opt_dead_assignments on
#pragma opt_loop_invariants off

/* Reserve saved-color work for the corresponding EPL fade callback; the allocation size matches its vector count. */
// FUN_001FE010
void btlEplAllocColorValueTarget(void) {
    chkmemAllocSiteTag(D_00625230, 0x2DF);
    (*jtbl_008873E8)(0x20, 0x40000);
}

/* Release the saved color work through the battle allocator. */
// FUN_001FE060
void btlEplFreeColorValueTarget(void *work) {
    jtbl_008873EC[0](work);
}

/* measured: opt_dead_assignments off keeps the second pair's blend unfused
   like the first (138 words without it). */
/* Fade the resource color value and target vectors after applying the scene color multipliers. */
// FUN_001FE090
/* measured: typed effect aliases and separate second-vector products retain 138 or more baseline words. */
#pragma opt_dead_assignments off
void btlEplStepColorValueTargetFade(u8 *effect)
{
    u32 count;
    BtlEplFade2Param *param;
    V4 *target;
    u32 total;
    u8 mode;
    f32 scale;
    V4 *mul;
    V4 color;
    BtlEplRgba rgba;

    target = (V4 *)((BtlEplEffect *)effect)->target;
    param = (BtlEplFade2Param *)((BtlEplEffect *)effect)->params;
    count = ((BtlEplEffect *)effect)->count;
    total = param->total;
    if (total < count && total != 0) {
        return;
    }
    mul = (V4 *)btlMainGetSceneColorBlock();
    mode = 0;
    if (total != 0) {
        if (count <= param->fadeIn) {
            if (param->fadeIn > 0) {
                scale = (f32)count / (f32)param->fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fadeOut) {
            if (param->fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    switch (mode) {
    case 0:
        if (count != 0) {
            return;
        }
        rgba.rgba = param->color[0].rgba;
        btlEplColorToVector(&color, &rgba.c);
        color.v[0] = color.v[0] * mul[0].v[0];
        color.v[1] = color.v[1] * mul[0].v[1];
        color.v[2] = color.v[2] * mul[0].v[2];
        color.v[3] = color.v[3] * mul[0].v[3];
        *(V4 *)resrcMngGetColorValue() = color;
        rgba.rgba = param->color[1].rgba;
        btlEplColorToVector(&color, &rgba.c);
        color.v[0] = color.v[0] * mul[1].v[0];
        color.v[1] = color.v[1] * mul[1].v[1];
        color.v[2] = color.v[2] * mul[1].v[2];
        color.v[3] = color.v[3] * mul[1].v[3];
        *(V4 *)resrcMngGetColorTarget() = color;
        break;
    case 1:
        if (count == 0) {
            target[0] = *(V4 *)resrcMngGetColorValue();
            target[1] = *(V4 *)resrcMngGetColorTarget();
        }
        {
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            rgba.rgba = param->color[0].rgba;
            btlEplColorToVector(&color, &rgba.c);
            color.v[0] = color.v[0] * mul[0].v[0];
            color.v[1] = color.v[1] * mul[0].v[1];
            color.v[2] = color.v[2] * mul[0].v[2];
            color.v[3] = color.v[3] * mul[0].v[3];
            inv = 1.0f - scale;
            a0 = target[0].v[0] * inv;
            a1 = target[0].v[1] * inv;
            a2 = target[0].v[2] * inv;
            a3 = target[0].v[3] * inv;
            b0 = color.v[0] * scale;
            b1 = color.v[1] * scale;
            b2 = color.v[2] * scale;
            b3 = color.v[3];
            color.v[0] = a0 + b0;
            color.v[1] = a1 + b1;
            color.v[2] = a2 + b2;
            color.v[3] = a3 + b3 * scale;
            *(V4 *)resrcMngGetColorValue() = color;

            rgba.rgba = param->color[1].rgba;
            btlEplColorToVector(&color, &rgba.c);
            color.v[0] = color.v[0] * mul[1].v[0];
            color.v[1] = color.v[1] * mul[1].v[1];
            color.v[2] = color.v[2] * mul[1].v[2];
            color.v[3] = color.v[3] * mul[1].v[3];
            a0 = target[1].v[0] * inv;
            a1 = target[1].v[1] * inv;
            a2 = target[1].v[2] * inv;
            a3 = target[1].v[3] * inv;
            b0 = color.v[0] * scale;
            b1 = color.v[1] * scale;
            b2 = color.v[2] * scale;
            b3 = color.v[3];
            color.v[0] = a0 + b0;
            color.v[1] = a1 + b1;
            color.v[2] = a2 + b2;
            color.v[3] = a3 + b3 * scale;
            *(V4 *)resrcMngGetColorTarget() = color;
        }
        break;
    case 2:
        if (count == total - param->fadeOut) {
            target[0] = *(V4 *)resrcMngGetColorValue();
            target[1] = *(V4 *)resrcMngGetColorTarget();
        }
        {
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            inv = 1.0f - scale;
            a0 = mul[0].v[0] * inv;
            a1 = mul[0].v[1] * inv;
            a2 = mul[0].v[2] * inv;
            a3 = mul[0].v[3] * inv;
            b0 = target[0].v[0] * scale;
            b1 = target[0].v[1] * scale;
            b2 = target[0].v[2] * scale;
            b3 = target[0].v[3];
            color.v[0] = a0 + b0;
            color.v[1] = a1 + b1;
            color.v[2] = a2 + b2;
            color.v[3] = a3 + b3 * scale;
            *(V4 *)resrcMngGetColorValue() = color;
            a0 = mul[1].v[0] * inv;
            a1 = mul[1].v[1] * inv;
            a2 = mul[1].v[2] * inv;
            a3 = mul[1].v[3] * inv;
            b0 = target[1].v[0] * scale;
            b1 = target[1].v[1] * scale;
            b2 = target[1].v[2] * scale;
            b3 = target[1].v[3];
            color.v[0] = a0 + b0;
            color.v[1] = a1 + b1;
            color.v[2] = a2 + b2;
            color.v[3] = a3 + b3 * scale;
            *(V4 *)resrcMngGetColorTarget() = color;
        }
        break;
    }
}
#pragma opt_dead_assignments on
/* Reserve saved-color work for the corresponding EPL fade callback; the allocation size matches its vector count. */
// FUN_001FEB80
void btlEplAllocColor(void) {
    chkmemAllocSiteTag(D_00625230, 0x389);
    (*jtbl_008873E8)(0x10, 0x40000);
}

/* Release the saved color work through the battle allocator. */
// FUN_001FEBD0
void btlEplFreeColor(void *work) {
    jtbl_008873EC[0](work);
}

/* Fade the scene RGB factors, forcing alpha to one before applying the resource-manager color factors. */
// FUN_001FEC00
/* The blend keeps the third colour term unscaled until the final add, as in
   btlMainUpdateColorWork (btlMain.c); retail fuses only that last component. */
void btlEplStepColorFade(u8 *effect)
{
    u32 count;
    BtlEplFadeParam *param;
    V4 *target;
    u32 total;
    u8 mode;
    f32 scale;
    V4 *heap;
    V4 color;
    V4 blend;
    BtlEplRgba rgba;
    f32 inv;
    f32 a0;
    f32 a1;
    f32 a2;
    f32 b0;
    f32 b1;
    f32 b2;

    target = (V4 *)((BtlEplEffect *)effect)->target;
    param = (BtlEplFadeParam *)((BtlEplEffect *)effect)->params;
    count = ((BtlEplEffect *)effect)->count;
    total = param->total;
    if (total < count && total != 0) {
        return;
    }
    mode = 0;
    if (total != 0) {
        if (count <= param->fadeIn) {
            if (param->fadeIn > 0) {
                scale = (f32)count / (f32)param->fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fadeOut) {
            if (param->fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    heap = (V4 *)btlMainGetSceneRgbaBlock();
    switch (mode) {
    case 0:
        if (count != 0) {
            return;
        }
        rgba.rgba = param->color.rgba;
        btlEplColorToVector(&color, &rgba.c);
        color.v[3] = 1.0f;
        *heap = color;
        resrcMngApplyColorFactors(&color);
        break;
    case 1:
        if (count == 0) {
            *target = *heap;
        }
        rgba.rgba = param->color.rgba;
        btlEplColorToVector(&color, &rgba.c);
        inv = 1.0f - scale;
        a0 = target->v[0] * inv;
        a1 = target->v[1] * inv;
        a2 = target->v[2] * inv;
        b0 = color.v[0] * scale;
        b1 = color.v[1] * scale;
        b2 = color.v[2];
        blend.v[0] = a0 + b0;
        blend.v[1] = a1 + b1;
        blend.v[2] = a2 + b2 * scale;
        blend.v[3] = 1.0f;
        *heap = blend;
        resrcMngApplyColorFactors(&blend);
        break;
    case 2:
        if (count == total - param->fadeOut) {
            *target = *heap;
        }
        btlEplColorToVector(&color, &D_007641F8);
        inv = 1.0f - scale;
        a0 = color.v[0] * inv;
        a1 = color.v[1] * inv;
        a2 = color.v[2] * inv;
        b0 = target->v[0] * scale;
        b1 = target->v[1] * scale;
        b2 = target->v[2];
        blend.v[0] = a0 + b0;
        blend.v[1] = a1 + b1;
        blend.v[2] = a2 + b2 * scale;
        blend.v[3] = 1.0f;
        *heap = blend;
        resrcMngApplyColorFactors(&blend);
        break;
    }
}
/* Allocate owned model-ID work from kind-3 source data; other kinds retain a zero handle. */
// FUN_001FF300
s32 *btlEplNewWideIdHandle(s32 context, s32 kind, s32 source, s32 options) {
    s32 *result;

    chkmemAllocSiteTag(D_00625230, 0x429);
    result = (s32 *)(*jtbl_008873E8)(0x24, 0x40000);
    if ((source != 0) && ((kind & 0xFFFF) == 3)) {
        *result = mdlEffectCreateUniqueModel(source, options);
    } else {
        *result = 0;
    }
    return result;
}

/* Allocate owned model-ID work from the unit's source model, or leave the handle zero when absent. */
// FUN_001FF3B0
s32 *btlEplNewWideIdHandleFromUnit(u8 *effect) {
    s32 *field;
    s32 *result;
    s32 value;

    field = (s32 *)((BtlEplEffect *)effect)->target;
    chkmemAllocSiteTag(D_00625230, 0x429);
    result = (s32 *)(*jtbl_008873E8)(0x24, 0x40000);
    value = *field;
    if (value != 0) {
        *result = EffModelFindOrCreate(value);
    } else {
        *result = 0;
    }
    return result;
}
/* Release the model-ID resource when nonzero, then free its work allocation. */
// FUN_001FF440
void btlEplFreeWideIdHandle(s32 *work) {
    if (*work != 0) {
        mdlEffectDestroyModel(*work);
    }
    jtbl_008873EC[0](work);
}

typedef struct BtlEplMatrix
{
    BtlEplV3 right; // 0x00
    u32 flags;      // 0x0C
    BtlEplV3 up;    // 0x10
    u32 pad1;       // 0x1C
    BtlEplV3 at;    // 0x20
    u32 pad2;       // 0x2C
    BtlEplV3 pos;   // 0x30
    u32 pad3;       // 0x3C
} BtlEplMatrix;

typedef struct BtlEplLightParam
{
    u32 total;           // 0x00
    u16 fadeIn;          // 0x04
    u16 fadeOut;         // 0x06
    BtlEplRgba color[2]; // 0x08
    f32 rotate;          // 0x10
    f32 scale;           // 0x14
} BtlEplLightParam;

typedef struct BtlEplLightTarget
{
    u8 *model;    // 0x00
    V4 start[2];  // 0x04
} BtlEplLightTarget;

extern BtlEplMatrix D_00922C60;

/* measured: opt_dead_assignments off keeps the colour conversions where the
   source puts them, as in btlEplStepColorPairFade. */
/* Fade both light color vectors and, when available, publish the transformed EPL model matrix. */
// FUN_001FF490
/* measured: typed effect aliases and separate second-vector products retain 298 baseline words. */
#pragma opt_dead_assignments off
void btlEplStepLightFadeInOut(u8 *effect)
{
    u32 count;
    BtlEplLightParam *param;
    BtlEplLightTarget *target;
    u32 total;
    u8 mode;
    f32 scale;
    V4 *src;
    s32 hasMatrix;
    BtlEplRgba rgba;
    f32 vec[3];
    BtlEplMatrix matrix;

    target = (BtlEplLightTarget *)((BtlEplEffect *)effect)->target;
    param = (BtlEplLightParam *)((BtlEplEffect *)effect)->params;
    count = ((BtlEplEffect *)effect)->count;
    total = param->total;
    if (total < count && total != 0) {
        return;
    }
    src = (V4 *)btlMainGetSceneColorBlock();
    mode = 0;
    if (total != 0) {
        if (count <= param->fadeIn) {
            if (param->fadeIn > 0) {
                scale = (f32)count / (f32)param->fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fadeOut) {
            if (param->fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    hasMatrix = 0;
    if (target->model != NULL) {
        mdlEffectBuildBasisRows(&matrix, ((BtlEplEffect *)effect)->rotation);
        mdlApplyModelMatrix(target->model, &matrix, 0);
        vec[0] = vec[1] = vec[2] = ((BtlEplEffect *)effect)->scale * param->scale;
        mdlScale(target->model, vec, 2);
        vec[0] = ((BtlEplEffect *)effect)->position[0];
        vec[1] = ((BtlEplEffect *)effect)->position[1];
        vec[2] = ((BtlEplEffect *)effect)->position[2];
        mdlTranslateMatrix((RwMatrix *)target->model, (const RwV3d *)vec, 2);
        mdlSetLayerWeight(target->model, 0, param->rotate);
        mdlAdvanceModelFromFlags(target->model);
        if (mdlCopyIndexedMatrix(target->model, 0, &matrix) != 0) {
            hasMatrix = 1;
        }
    }
    switch (mode) {
    case 0:
        if (count != 0) {
            break;
        }
        rgba.rgba = param->color[0].rgba;
        btlEplColorToVector((V4 *)&D_00922CA0[0], &rgba.c);
        rgba.rgba = param->color[1].rgba;
        btlEplColorToVector((V4 *)&D_00922CA0[4], &rgba.c);
        D_00922CC0[0] = 1;
        break;
    case 1:
        if (count == 0) {
            target->start[0] = *(V4 *)&D_00922CA0[0];
            target->start[1] = *(V4 *)&D_00922CA0[4];
        }
        {
            V4 color;
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            rgba.rgba = param->color[0].rgba;
            btlEplColorToVector(&color, &rgba.c);
            inv = 1.0f - scale;
            a0 = target->start[0].v[0] * inv;
            a1 = target->start[0].v[1] * inv;
            a2 = target->start[0].v[2] * inv;
            a3 = target->start[0].v[3] * inv;
            b0 = color.v[0] * scale;
            b1 = color.v[1] * scale;
            b2 = color.v[2] * scale;
            b3 = color.v[3];
            D_00922CA0[0] = a0 + b0;
            D_00922CA0[1] = a1 + b1;
            D_00922CA0[2] = a2 + b2;
            D_00922CA0[3] = a3 + b3 * scale;

            rgba.rgba = param->color[1].rgba;
            a0 = target->start[1].v[0] * inv;
            a1 = target->start[1].v[1] * inv;
            a2 = target->start[1].v[2] * inv;
            a3 = target->start[1].v[3] * inv;
            b0 = (1.0f / 255.0f) * (f32)(u32)rgba.c.r * scale;
            b1 = (1.0f / 255.0f) * (f32)(u32)rgba.c.g * scale;
            b2 = (1.0f / 255.0f) * (f32)(u32)rgba.c.b * scale;
            b3 = (1.0f / 255.0f) * (f32)(u32)rgba.c.a * scale;
            a0 += b0;
            D_00922CA0[4] = a0;
            a1 += b1;
            D_00922CA0[5] = a1;
            a2 += b2;
            D_00922CA0[6] = a2;
            a3 += b3;
            D_00922CA0[7] = a3;
        }
        D_00922CC0[0] = 1;
        break;
    case 2:
        if (count == total - param->fadeOut) {
            target->start[0] = *(V4 *)&D_00922CA0[0];
            target->start[1] = *(V4 *)&D_00922CA0[4];
        }
        {
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            inv = 1.0f - scale;
            a0 = src[0].v[0] * inv;
            a1 = src[0].v[1] * inv;
            a2 = src[0].v[2] * inv;
            a3 = src[0].v[3] * inv;
            b0 = target->start[0].v[0] * scale;
            b1 = target->start[0].v[1] * scale;
            b2 = target->start[0].v[2] * scale;
            b3 = target->start[0].v[3];
            D_00922CA0[0] = a0 + b0;
            D_00922CA0[1] = a1 + b1;
            D_00922CA0[2] = a2 + b2;
            D_00922CA0[3] = a3 + b3 * scale;
            a0 = src[1].v[0] * inv;
            a1 = src[1].v[1] * inv;
            a2 = src[1].v[2] * inv;
            a3 = src[1].v[3] * inv;
            b0 = target->start[1].v[0] * scale;
            b1 = target->start[1].v[1] * scale;
            b2 = target->start[1].v[2] * scale;
            b3 = target->start[1].v[3];
            D_00922CA0[4] = a0 + b0;
            D_00922CA0[5] = a1 + b1;
            D_00922CA0[6] = a2 + b2;
            D_00922CA0[7] = a3 + b3 * scale;
        }
        D_00922CC0[0] = 1;
        break;
    }
    if (hasMatrix) {
        D_00922C60 = matrix;
    }
}
#pragma opt_dead_assignments on
typedef struct BtlEplMotionParam
{
    BtlEplSelect select; // 0x00, read by btlEplUnitIsSelected
    s16 motion;          // 0x04, unit motion id
    u16 option;          // 0x06
    f32 rate;            // 0x08
    u16 frame;           // 0x0C
    u8 unk0E;            // 0x0E, zero also calls btlUnitClearModelState
    u8 pad0F;            // 0x0F
    s32 unk10;           // 0x10, nonzero also calls btlUnitSetModelAnimFrame
} BtlEplMotionParam;

// FUN_001FFF40
/* Applies the motion parameters to every selected unit when the effect starts (count 0). */
void btlEplUnitApplyMotion(u8 *effect)
{
    s32 count;
    BtlEplMotionParam *param;
    BtlEplUnit *node;
    u32 i;
    s32 value;

    param = (BtlEplMotionParam *)((BtlEplEffect *)effect)->params;
    count = (s32)((BtlEplEffect *)effect)->count;
    for (i = 0; i < 4; i++) {
        node = (BtlEplUnit *)((BtlBattleState *)D_0072449C)->unitLists[i * 2];
        while (node != NULL) {
            if ((btlEplUnitIsSelected(node, &param->select) != 0) &&
                ((node->datUnit == 0) ||
                 (datCalcEnemyHasExtendedFlag(node->datUnit) != 0) ||
                 (datCalcIsDead(node->datUnit, 0) == 0))) {
                node->unk9D8 |= 8;
                if (count == 0) {
                    if (param->unk0E == 0) {
                        btlUnitClearModelState(node, 4);
                    }
                    value = param->motion;
                    btlUnitSetMotion((u8 *)node, (s16)value, param->frame, param->rate, param->option);
                    value = param->unk10;
                    if (value != 0) {
                        btlUnitSetModelAnimFrame(node, (s16)value);
                    }
                    btlUnitApplyModelState(node, 4);
                }
            }
            node = node->next;
        }
    }
}
/* Allocate owned model-ID work from kind-3 source data; other kinds retain a zero handle. */
// FUN_00200090
s32 *btlEplNewZeroedIdHandle(s32 context, s32 kind, s32 source, s32 options) {
    s32 *result;

    chkmemAllocSiteTag(D_00625230, 0x54D);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    *result = 0;
    if ((source != 0) && ((kind & 0xFFFF) == 3)) {
        *result = mdlEffectCreateUniqueModel(source, options);
    } else {
        *result = 0;
    }
    return result;
}

/* Allocate owned model-ID work from the unit's source model, or leave the handle zero when absent. */
// FUN_00200150
s32 *btlEplNewZeroedIdHandleFromUnit(u8 *effect) {
    s32 *field;
    s32 *result;
    s32 value;

    field = (s32 *)((BtlEplEffect *)effect)->target;
    chkmemAllocSiteTag(D_00625230, 0x54D);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    *result = 0;
    value = *field;
    if (value != 0) {
        *result = EffModelFindOrCreate(value);
    } else {
        *result = 0;
    }
    return result;
}

/* Release the model-ID resource when nonzero, then free its work allocation. */
// FUN_002001E0
void btlEplFreeZeroedIdHandle(s32 *work) {
    if (*work != 0) {
        mdlEffectDestroyModel(*work);
    }
    jtbl_008873EC[0](work);
}

typedef struct BtlEplScaleParam
{
    BtlEplSelect select; // 0x00, read by btlEplUnitIsSelected
    u32 total;           // 0x04, compared with the effect count
    f32 unk08;           // 0x08, passed to mdlSetLayerWeight
    f32 scale;           // 0x0C, multiplies the arg0 + 0x20 scale
    s32 unk10;           // 0x10, nonzero enables the final unit pass
} BtlEplScaleParam;

// FUN_00200230
/* Scales the target model and counter-scales selected units; the final pass reapplies stored motion. */
void btlEplApplyScaleEffect(u8 *effect) {
    f32 scaleVector[4];
    u8 anchorPosition[0x10];
    u8 modelPosition[0x10];
    u8 basisMatrix[0x30];
    u8 inverseScaleMatrix[0x40];
    u8 unitMatrix[0x40];
    u8 rotation[0x10];
    f32 scale;
    f32 inv;
    u32 count;
    u32 i;
    u8 **target;
    BtlEplScaleParam *param;
    BtlEplUnit *node;

    target = (u8 **)((BtlEplEffect *)effect)->target;
    param = (BtlEplScaleParam *)((BtlEplEffect *)effect)->params;
    count = ((BtlEplEffect *)effect)->count;
    if ((param->total >= count) || (param->total == 0)) {
        if ((count == param->total) && (param->unk10 != 0)) {
            for (i = 0; i < 2; i++) {
                node = (BtlEplUnit *)((BtlBattleState *)D_0072449C)->unitLists[i * 2];
                while (node != NULL) {
                    if ((node->datUnit != 0) &&
                        (btlEplUnitIsSelected(node, &param->select) != 0) &&
                        (datCalcIsDead(node->datUnit, 0) == 0)) {
                        btlUnitGetAnchorPose(node, anchorPosition, rotation, NULL);
                        btlUnitSetPos(node, anchorPosition);
                        btlUnitSetRot(node, rotation);
                        btlUnitUpdateStatusMotion((u8 *)node, 0);
                        btlUnitSetMotion((u8 *)node, node->motion, 0, node->rate, (u16)node->option);
                    }
                    node = node->next;
                }
            }
            return;
        }
        if (*target != NULL) {
            mdlEffectBuildBasisRows(basisMatrix, ((BtlEplEffect *)effect)->rotation);
            mdlApplyModelMatrix(*target, basisMatrix, 0);
            scale = ((BtlEplEffect *)effect)->scale * param->scale;
            scaleVector[2] = scale;
            scaleVector[1] = scale;
            scaleVector[0] = scale;
            mdlScale(*target, scaleVector, 2);
            scaleVector[0] = ((BtlEplEffect *)effect)->position[0];
            scaleVector[1] = ((BtlEplEffect *)effect)->position[1];
            scaleVector[2] = ((BtlEplEffect *)effect)->position[2];
            mdlTranslateMatrix((RwMatrix *)*target, (const RwV3d *)scaleVector, 2);
            mdlSetLayerWeight(*target, 0, param->unk08);
            mdlAdvanceModelFromFlags(*target);
            if (mdlCopyIndexedMatrix(*target, 0, basisMatrix) != 0) {
                for (i = 0; i < 4; i++) {
                    node = (BtlEplUnit *)((BtlBattleState *)D_0072449C)->unitLists[i * 2];
                    while (node != NULL) {
                        if ((btlEplUnitIsSelected(node, &param->select) != 0) &&
                            (node->datUnit == 0 || datCalcIsDead(node->datUnit, 0) == 0)) {
                            btlUnitSetPos(node, modelPosition);
                            inv = 1.0f / scale;
                            scaleVector[2] = inv;
                            scaleVector[1] = inv;
                            scaleVector[0] = inv;
                            RwMatrixScale(inverseScaleMatrix, scaleVector, 0);
                            RwMatrixMultiply(unitMatrix, basisMatrix, inverseScaleMatrix);
                            RtQuatConvertFromMatrix(rotation, unitMatrix);
                            btlTargetNormalizeVector(rotation, rotation);
                            btlUnitSetRot(node, rotation);
                        }
                        node = node->next;
                    }
                }
            }
        }
    }
}

/* Allocate pattern work and choose an even user-data pattern index from kind-3 source data; other kinds retain a zero handle. */
// FUN_00200550
s32 *btlEplNewPatternWork(s32 context, s32 kind, s32 source, s32 options) {
    BtlEplEplWork *result;
    s32 value;
    u32 rnd;

    chkmemAllocSiteTag(D_00625230, 0x60D);
    result = (BtlEplEplWork *)(*jtbl_008873E8)(8, 0x40000);
    result->target = 0;
    result->pattern = 0;
    if ((source != 0) && ((kind & 0xFFFF) == 3)) {
        value = mdlEffectCreateUniqueModel(source, options);
        result->target = value;
        rnd = mdlCountIntUserData(value);
        if ((rnd >> 1) != 0) {
            result->pattern = (s16)((effMiscRand(0) % (rnd / 2)) * 2);
        }
    } else {
        result->target = 0;
    }
    return (s32 *)result;
}

/* Allocate pattern work and choose an even user-data pattern index from the unit's source model, or leave the handle zero when absent. */
// FUN_00200650
s32 *btlEplNewPatternWorkFromUnit(u8 *effect) {
    s32 *field;
    BtlEplEplWork *result;
    s32 value;
    u32 rnd;

    field = (s32 *)((BtlEplEffect *)effect)->target;
    chkmemAllocSiteTag(D_00625230, 0x60D);
    result = (BtlEplEplWork *)(*jtbl_008873E8)(8, 0x40000);
    result->target = 0;
    result->pattern = 0;
    value = *field;
    if (value != 0) {
        value = EffModelFindOrCreate(value);
        result->target = value;
        rnd = mdlCountIntUserData(value);
        if ((rnd >> 1) != 0) {
            result->pattern = (s16)((effMiscRand(0) % (rnd / 2)) * 2);
        }
    } else {
        result->target = 0;
    }
    return (s32 *)result;
}
