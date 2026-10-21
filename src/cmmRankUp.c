#include "rw_types_internal.h"
#include "mt_scene_internal.h"
/* Original translation unit cmmRankUp.c (from __FILE__ assert strings). */
#include "type.h"
#include "model_battle_internal.h"
#include "rw_object_internal.h"
#include "primitive_point_buffer.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "cmm_internal.h"
#include "btl_effect_internal.h"
#include "resrc_manager_internal.h"
#include "datPersona_internal.h"

/* measured: retail compiles this unit with loop invariant hoisting off, and only the animation and
 * drawing functions turn it back on. */
#pragma opt_loop_invariants off
extern u8 *PrimAllocQueueNode();
extern void cmmRankUpRunQueue();
extern u8 D_007963D0[];
extern void PrimAppendNode();
extern void cmmRankUpStepSparklePools();

/* Absolute-addressed data; these must be array-typed so retail's lui/addiu addressing is reproduced
 * instead of GP-relative access. */
extern u8 D_00635CF8[];
extern u8 D_00635D18[];
extern u8 D_006367C0[];
extern u8 D_00636410[];
extern u8 D_00636460[];
extern u8 D_00636480[];
extern u8 D_006364D0[];
extern u8 D_006364F0[];
extern u8 D_00636540[];
extern u8 D_00636210[];
extern u8 D_00636230[];
extern const struct RwV3d D_00636250;
extern u8 D_00636260[];
extern const s32 D_006361F0[8];
extern u32 D_80000046[];
extern u32 D_8000001E[];
extern f32 D_00761184;
extern f32 D_007613A0;
extern f32 D_007612CC;
extern f32 D_007612D0;
extern f32 D_0076120C;
extern f32 D_00761288;
extern f32 D_0076122C;
extern void (*D_00887300[])(u32, u32);
extern void *(*D_008873F4[])(size_t, size_t, u32);

void chkmemAllocSiteTag(void *file, s32 line);
void kAssertFail(const void *file, s32 line);
extern void mdlComputeIndexedAttachMatrix(s32 model, s32 index, void *destination);
extern void FldPanel2dTaskCreate();
extern void MT_Scene_SetResEnabled(s32 resource, s32 enabled);
extern void func_003ef3a0(s32 value);
extern void H_Cdvd_Destroy(s32 cdvd);
extern void mdlSetLayerWeight(u8 *model, s32 layer, f32 speed);
extern void *memset(void *destination, s32 value, size_t count);

/* 128-bit objects copied with quadword loads and stores. */
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u_long128 D_00636560;
extern u_long128 D_00636570;
typedef struct { u32 w0; u32 w1; } CopyPair;

/* Snapshot of a scene resource while its rank-up presentation owns visibility. */
typedef struct RankUpResourceState {
    f32 weight;
    u8 *model;
    u8 *resource;
    s32 enabled;
} RankUpResourceState;
/* Font run links follow the same private layout used by frFont.c. */
typedef struct FrFontNode { u8 pad00[0x24]; struct FrFontNode *next; } FrFontNode;

extern const CopyPair D_00636310[16];
extern const CopyPair D_00636390[16];

struct RwMatrixTag {
    struct RwV3d right; u32 flags;
    struct RwV3d up; u32 pad1;
    struct RwV3d at; u32 pad2;
    struct RwV3d pos; u32 pad3;
};
typedef struct RwMatrixTag RankUpMatrix __attribute__((aligned(16)));

/* Chunk 25 uses 66-byte records; the final halfword selects the persona name. */
typedef struct CmmPersonaNameRecord { u8 pad00[0x40]; u16 personaId; } CmmPersonaNameRecord;

typedef struct {
    s32 kind;
    f32 x;
    f32 y;
    struct RwV3d axis;
    s32 color;
    f32 angle;
    s16 width;
    s16 height;
} RankUpSpriteState;
extern u_long128 D_00636730;
extern void PrimDrawFlatRectangle(u8 *colorData, f32 *rectangleData, f32 depth, s32 preserveState);
static void cmmRankUpLerpState(RankUpSpriteState *out, RankUpSpriteState *a, RankUpSpriteState *b, f32 t);

extern struct RwMatrixTag *RwMatrixRotate(struct RwMatrixTag *matrix,
        const struct RwV3d *axis, f32 angle, s32 combine);
extern void RpSkyRenderStateSet(s32 value, s32 option1);
extern u8 *cmmRankUpReserveSparkle(s32 workAddress, s32 poolKind);
extern void cmmRankUpFadeSparklePools(u8 *work);
extern s32 shdSpriteSlotHandle(s32 entryId, s32 entryOffset, u8 *pack);
extern s32 datPortraitValue(s32 task);
extern u32 RpRandom(void);
extern u8 *RwMatrixMultiply(u8 *value, u8 *option1, u8 *option2);
extern f32 cosf(f32 floatValue);
extern f32 sinf(f32 floatValue);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern void PrimDrawRectangle(u8 *colors, u8 *positions, f32 depth,
                          s32 preserveState, s32 offsetX, s32 offsetY,
                          f32 rotation, f32 scaleX, f32 scaleY);

extern s32 sflDataDrawTexturedQuad(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                          s32 alpha, s32 mode, s16 centerX, s16 centerY,
                          struct RwMatrixTag *matrix, s32 texture, f32 (*uv)[2]);

extern s32 shdEffectTaskCreate(s32 parentTask, s32 resource, s32 frameLimit, void *context);
extern s32 cmmScriptTaskGetWorkValue(s32 task);
extern void mdlEffectSetMatrixPose(s32 effect, s32 matrix);
extern void mdlEffectSetChildPositionVec(void *object, f32 *position);
extern void mdlEffectGetPackedColor(void *object, s32 *color);
extern void mdlEffectSetPackedColor(void *object, s32 *packedColor);
extern u8 *datScreenPointToWorldPosition(u8 *output, s32 screenX, s32 screenY, f32 distance);
extern u8 *kwlnGetCamera(void);
extern s32 func_003e9700(s32 value);
extern void itfMesWindowSetString(s32 handle, s32 slotIndex, void *text);
extern void sdkSndStartChannel(s32 channelIndex, void *path);
extern f32 fGpffffa66c;
extern f32 fGpffffa670;
extern f32 fGpffffa674;
extern f32 fGpffffa678;
extern u16 D_008C024E[];
extern u8 D_00636580[];
extern u8 D_006365D0[];
extern u_long128 D_006365F0;
extern u_long128 D_00636600;
extern u_long128 D_00636610;
extern u_long128 D_00636620;
extern u8 D_00636630[];
extern u8 D_00636650[];
extern u8 D_00636670[];
extern u8 D_00636690[];
extern u8 D_006366B0[];
extern u8 D_006366D0[];
extern u8 D_006366F0[];
extern u8 D_00636710[];
extern u8 D_00635C80[];
extern u8 D_00635CA0[];
extern u8 D_005DC974[];
extern s64 cmmCommunityArcana(s32 communityId);
extern u8 *func_002438b0();
extern u8 *cmmPersonaRecord();

/* Old-style: the two callbacks passed here (cmmRankUpEnqueueTask takes one s32,
 * cmmRankUpDestroy takes none) do not share a signature, and a typed prototype
 * would force casts at every call site. */


/* Forward declarations for asm-fallback siblings referenced by C bodies. */
s32 cmmRankUpDrawMovingWipe(u8 *root, u8 *work, CmmRankUpCardTask *context);
s32 cmmRankUpDrawExitWipe(u8 *root, u8 *work, CmmRankUpCardTask *context);
s32 cmmRankUpSequenceUpdate(u8 *task);
void cmmRankUpSequenceDestroy(u8 *unusedTask);

typedef int (*code)();
extern code DAT_008873ec_abs[];


// Matches P3FES comuTimerSequence. kwlnTaskGetWork is declared without a prototype because a typed
// prototype adds zero-extensions retail lacks.


/* Run active entry callbacks, clear ACTIVE on completed entries, then update the shared effect pool. */
// FUN_00251D80
void cmmRankUpRunQueue(s32 unused, s32 *task) {
    extern s32 *kwlnTaskGetWork();
    u8 *base;
    s32 i;
    CmmRankUpEntry *entry;

    base = (u8 *)kwlnTaskGetWork(task);
    entry = (CmmRankUpEntry *)base;
    for (i = 0; i < 0x10; i++) {
        if (entry->flags & 1) {
            if (entry->step == NULL) {
                kAssertFail(D_00635CF8, 0x289);
            }
            if (entry->step(base, (u8 *)entry, ((CmmRankUpWork *)base)->callerArg) != 0) {
                entry->flags &= ~1;
            }
        }
        entry++;
    }
    cmmRankUpStepSparklePools(base, ((CmmRankUpWork *)base)->callerArg);
}


// Queues cmmRankUpRunQueue on the shared queue with the argument as its context; returns 0.
// FUN_00251E60
s32 cmmRankUpEnqueueTask(u8 *sdkTaskBytes) {
    s32 taskHandle = (s32)sdkTaskBytes;
    u8 *node;

    kwlnTaskGetWork();
    node = PrimAllocQueueNode();
    ((BtlRenderNode *)node)->callback = (void *)cmmRankUpRunQueue;
    ((BtlRenderNode *)node)->work = (void *)taskHandle;
    PrimAppendNode(D_007963D0, node);
    return 0;
}

// Releases the rank-up work handle through the free-table slot 0.
// FUN_00251EC0
void cmmRankUpDestroy(u8 *unusedTask)
{
    int workHandle;

    workHandle = kwlnTaskGetWork();
    DAT_008873ec_abs[0](workHandle);
}


// Allocates the rank-up work block, records the caller's argument in it, and creates the child task that runs cmmRankUpEnqueueTask and cmmRankUpDestroy.
// FUN_00251F00
void cmmRankUpCreate(s32 parentTask, u32 *context) {
    u8 *work;

    chkmemAllocSiteTag(D_00635CF8, 0x277);
    work = (u8 *)D_008873F4[0](1, 0x9E4, 0x40000);
    ((CmmRankUpWork *)work)->callerArg = (u8 *)context;
    if (work == NULL) {
        kAssertFail(D_00635CF8, 0x2D5);
    }
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_00635D18), 0xF, 0, 0, cmmRankUpEnqueueTask, cmmRankUpDestroy, (u8 *)(work));
}


/* measured: retail keeps the flag-clear mask in the loop preheader; without this pragma it is
 * rematerialized inside the else-branch. */

// Sets (hold != 0) or clears flag bit 2 on each active entry of the rank-up table, holding or
// releasing the entries.
// FUN_00251FC0
#pragma push
#pragma opt_loop_invariants on
void cmmRankUpSetEntryHold(s32 taskHandle, s32 hold) {
    extern u32 *kwlnTaskGetWork();
    CmmRankUpEntry *entry;
    u32 flags;
    s32 i;

    entry = (CmmRankUpEntry *)kwlnTaskGetWork();
    for (i = 0; i < 0x10; i++) {
        flags = entry->flags;
        if (flags & 1) {
            if (hold != 0) {
                entry->flags = flags | 2;
            } else {
                entry->flags = flags & ~2;
            }
        }
        entry++;
    }
}
#pragma pop

/* Absolute-addressed float data for cmmRankUpCopyState's stack snapshot. */
extern f32 D_00635D28[];
extern f32 D_00635D2C[];
extern f32 D_00635D30[];
extern u8 D_00635D40[];
extern u8 D_00636180[];
extern u8 *cmmRankUpFindFreeEntry(u8 *entries);
extern void *memset(void *dst, s32 value, u32 size);
extern void *memcpy(void *dst, const void *src, u32 size);
extern u8 *cmmKindRecord(s32 kindId);
extern s32 datGetFlag(s32 bit);
extern s64 cmmResolveCounterpart(s16 value);
extern void itfMesWindowApplySlots(s32 handle);
extern u8 *itfMesWindowBuildEntry(f32 x, f32 y, f32 scale, s32 color,
                         s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex);
extern u8 *frFontSplitRun(u8 **listAddress, s32 runIndex);
extern s32 frFontNodeWidth(u8 *node);
extern void frFontMoveListToFloat(u8 *list, f32 x, f32 y);
extern void frFontSetGlyphColor(u8 *list, s32 color);
extern void frFontListKeepOrRelease(u8 *list);
extern u8 *MT_Scene_GetResListHead(s32 resourceType);
extern s32 MT_Scene_IsResEnabled(u8 *resource);
extern void MT_Scene_SetResEnabledById(s32 resTypeId, s32 enabled);

/* Claim an entry, select its step callback by kind, and copy three sprite keyframes from the
 * indexed table. */
// FUN_00252050
void cmmRankUpCopyState(s32 taskHandle, s32 kind, s32 stateIndex) {
    extern u8 *kwlnTaskGetWork();
    f32 stepAddresses[3];
    s32 copy2[0x87 * 2];
    s32 copy1[0x1B];
    u8 *src;
    u8 *p;
    u8 *srcp;
    u8 *dstp;
    s32 *srcp2;
    s32 *dstp2;
    s32 i;
    s32 v;
    s32 w;
    s32 t;
    s32 stepAddress;
    typedef struct { f32 x, y, z; } RankUpStepAddresses;

    *(RankUpStepAddresses *)stepAddresses = *(RankUpStepAddresses *)D_00635D28;

    srcp = D_00635D40;
    dstp = (u8 *)copy2;
    i = 0x87;
    do {
        v = (s32)((const CopyPair *)srcp)->w0;
        w = (s32)((const CopyPair *)srcp)->w1;
        srcp += 8;
        i--;
        ((CopyPair *)dstp)->w0 = v;
        ((CopyPair *)dstp)->w1 = w;
        dstp += 8;
    } while (i > 0);

    srcp2 = (s32 *)D_00636180;
    dstp2 = copy1;
    v = 0x1B;
    do {
        t = *srcp2;
        srcp2++;
        v--;
        *dstp2 = t;
        dstp2++;
    } while (v > 0);

    p = kwlnTaskGetWork(taskHandle);
    if (kind >= 3) {
        kAssertFail(D_00635CF8, 0x329);
    }
    switch (kind) {
    case 0:
        src = (u8 *)copy2 + stateIndex * 0x6C;
        break;
    case 1:
        src = (u8 *)copy1 + stateIndex * 0x6C;
        break;
    case 2:
        src = NULL;
        break;
    }
    stepAddress = *(s32 *)&stepAddresses[kind];
    p = cmmRankUpFindFreeEntry(p);
    if (p == NULL) {
        kAssertFail(D_00635CF8, 0x2A5);
    }
    memset(p, 0, 0x78);
    ((CmmRankUpEntry *)p)->flags |= 1;
    ((CmmRankUpEntry *)p)->step = (CmmRankUpEntryStep)stepAddress;
    if (src != NULL) {
        memcpy(((CmmRankUpEntry *)p)->unk_0c, src, 0x6C);
    }
}


/* Linear interpolation of two sprite states by t into out: position, scale and axis fields. Packed
 * channels use unsigned word shifts and byte truncation. */
// FUN_00252230
static void cmmRankUpLerpState(RankUpSpriteState *out, RankUpSpriteState *a, RankUpSpriteState *b, f32 t)
{
    f32 fa;
    f32 fb;
    f32 r;

    fa = a->x;
    fb = b->x;
    out->x = fa + t * (fb - fa);
    fa = a->y;
    fb = b->y;
    out->y = fa + t * (fb - fa);
    fa = a->axis.x;
    fb = b->axis.x;
    out->axis.x = fa + t * (fb - fa);
    fa = a->axis.y;
    fb = b->axis.y;
    out->axis.y = fa + t * (fb - fa);
    fa = a->axis.z;
    fb = b->axis.z;
    out->axis.z = fa + t * (fb - fa);
    fa = a->angle;
    fb = b->angle;
    out->angle = fa + t * (fb - fa);
    fa = (f32)a->width;
    fb = (f32)b->width;
    out->width = (s16)(s32)(fa + t * (fb - fa));
    fa = (f32)a->height;
    fb = (f32)b->height;
    out->height = (s16)(s32)(fa + t * (fb - fa));
    {
        f32 ba;
        f32 bb;
        ba = (f32)(u32)(((u32)a->color >> 24) & 0xFF);
        bb = (f32)(u32)(((u32)b->color >> 24) & 0xFF);
        r = ba + t * (bb - ba);
        out->color = (s32)(((u32)(u8)r) << 24);
        ba = (f32)(u32)(((u32)a->color >> 16) & 0xFF);
        bb = (f32)(u32)(((u32)b->color >> 16) & 0xFF);
        r = ba + t * (bb - ba);
        out->color |= (s32)(((u32)(u8)r) << 16);
        ba = (f32)(u32)(((u32)a->color >> 8) & 0xFF);
        bb = (f32)(u32)(((u32)b->color >> 8) & 0xFF);
        r = ba + t * (bb - ba);
        out->color |= (s32)(((u32)(u8)r) << 8);
        ba = (f32)(u32)((u32)a->color & 0xFF);
        bb = (f32)(u32)((u32)b->color & 0xFF);
        r = ba + t * (bb - ba);
        out->color |= (s32)(u32)(u8)r;
    }
}


/* Per-frame rank-up sprite step: advances the frame counter, interpolates the sprite state after
 * frame 30, and emits the sprite through the provider until frame 0x3C. Both interpolation phases
 * share one private leaf, and the provider takes depth before width and height. */
// FUN_00252710
s32 cmmRankUpStepSprite(s32 unused, u8 *work, CmmRankUpCardTask *context)
{
    RankUpSpriteState state;
    RankUpMatrix matrix;
    union { s32 words[8]; f32 coordinates[4][2]; } uvBlock;
    const u8 *sourceBytes;
    u8 *destinationBytes;
    s32 pairs;
    s32 firstWord;
    s32 secondWord;
    s32 frame;
    s32 complete;
    s32 special;
    s32 texture;
    complete = 0;
    special = 0;
    if (context->mode == 0xA) {
        special = 1;
    }
    if (!(((CmmRankUpEntry *)work)->flags & 2)) {
        ((CmmRankUpEntry *)work)->frame += 1;
    }
    frame = ((CmmRankUpEntry *)work)->frame;
    if (frame >= 0x3C) {
        complete = 1;
    }
    if (frame > 30) {
        cmmRankUpLerpState(&state, (RankUpSpriteState *)(work + 0x30), (RankUpSpriteState *)(work + 0x54),
                      (f32)(frame - 0x1E) / 30.0f);
    } else {
        cmmRankUpLerpState(&state, (RankUpSpriteState *)(work + 0xC), (RankUpSpriteState *)(work + 0x30),
                      (f32)frame / 30.0f);
    }
    if (special != 0) {
        if (state.color == 0xFFE92CFF) {
            ((CmmRankUpEntry *)work)->spriteKind = 0;
            state.color = -1;
        } else {
            state.color = 0xBFBFBFFF;
        }
    }
    sourceBytes = (const u8 *)&D_006361F0;
    destinationBytes = (u8 *)&uvBlock.words;
    pairs = 4;
    do {
        firstWord = (s32)((const CopyPair *)sourceBytes)->w0;
        secondWord = (s32)((const CopyPair *)sourceBytes)->w1;
        sourceBytes += 8;
        pairs--;
        ((CopyPair *)destinationBytes)->w0 = firstWord;
        ((CopyPair *)destinationBytes)->w1 = secondWord;
        destinationBytes += 8;
    } while (pairs > 0);
    texture = shdSpriteSlotHandle(0x18, 0, context->slot10.sprites);
    RwMatrixRotate(&matrix, &state.axis, state.angle, 0);
    if (((CmmRankUpEntry *)work)->spriteKind == 1) {
        work = (u8 *)D_00887300;
        (*(void (**)(u32, u32))work)(7, 2);
        (*(void (**)(u32, u32))work)(9, 2);
        (*(void (**)(u32, u32))work)(6, 1);
        (*(void (**)(u32, u32))work)(8, 1);
        (*(void (**)(u32, u32))work)(0xC, 1);
        (*(void (**)(u32, u32))work)(2, 4);
        (*(void (**)(u32, u32))work)(0xE, 0);
        RpSkyRenderStateSet(3, 0x7000D);
        RpSkyRenderStateSet(2, 0x48);
        sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f, state.width, state.height, (u32)state.color >> 8,
                      state.color & 0xFF, 0, (s16)(state.width >> 1), (s16)(state.height >> 1), &matrix, texture,
                      uvBlock.coordinates);
    } else {
        sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f, state.width, state.height, (u32)state.color >> 8,
                      state.color & 0xFF, 1, (s16)(state.width >> 1), (s16)(state.height >> 1), &matrix, texture,
                      uvBlock.coordinates);
    }
    return complete;
}
/* D_00636250 is the (0,1,0) vector; particle timers are integer stores and random draws keep their
 * original order and unsigned conversions. */
typedef struct { struct RwV3d vector; } RankUpVectorCopy;

/* The pool provider initializes 0x20 bytes. These are its four fields used
 * here; the particle update provider treats offset 0xC as an integer timer. */
typedef struct {
    u32 flags;
    f32 x;
    f32 y;
    s32 timer;
} RankUpParticlePrefix;

// Per-frame rank-up effect step: draws textured particles and an overlay with pulse and angle,
// using the matrix and UV blocks.
// FUN_00252A60
s32 cmmRankUpStepEffect(s32 root, u8 *work, CmmRankUpCardTask *context)
{
    CmmRankUpEntry *entry = (CmmRankUpEntry *)work;

    RankUpVectorCopy axis;
    PrimPoint displacement;
    RankUpVectorCopy axisTemplate;
    RankUpSpriteState state;
    RankUpMatrix matrix;
    RankUpMatrix effectMatrix;
    RankUpMatrix product;
    union { f32 coordinates[4][2]; s32 words[8]; } uv;
    union { f32 coordinates[4][2]; s32 words[8]; } overlayUv;
    union { PrimPoint points[5]; s32 words[10]; } positions;
    s32 done;
    s32 is10;
    s32 frame;
    s32 textureA;
    s32 textureB;
    s32 overlay;
    f32 pulse;
    f32 angle;
    f32 radius;
    u8 *renderState;

    done = 0;
    is10 = 0;
    if (context->mode == 10) {
        is10 = 1;
    }
    if (!(*(s32 *)work & 2)) {
        ((CmmRankUpEntry *)work)->frame += 1;
    }
    if (entry->frame >= 60) {
        done = 1;
    }
    if (entry->frame > 30) {
        cmmRankUpLerpState(&state, (RankUpSpriteState *)(work + 0x30), (RankUpSpriteState *)(work + 0x54),
            (f32)(entry->frame - 30) / 30.0f);
    } else {
        cmmRankUpLerpState(&state, (RankUpSpriteState *)(work + 0xC), (RankUpSpriteState *)(work + 0x30),
            sinf(D_00761184 * (f32)entry->frame / 30.0f));
    }
    {
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        source = D_00636210;
        destination = (u8 *)&uv;
        count = 4;
        do {
            first = (s32)((const CopyPair *)source)->w0;
            second = (s32)((const CopyPair *)source)->w1;
            source += 8;
            count--;
            ((CopyPair *)destination)->w0 = first;
            ((CopyPair *)destination)->w1 = second;
            destination += 8;
        } while (count > 0);
    }
    {
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        source = D_00636230;
        destination = (u8 *)&overlayUv;
        count = 4;
        do {
            first = (s32)((const CopyPair *)source)->w0;
            second = (s32)((const CopyPair *)source)->w1;
            source += 8;
            count--;
            ((CopyPair *)destination)->w0 = first;
            ((CopyPair *)destination)->w1 = second;
            destination += 8;
        } while (count > 0);
    }
    if (((CmmRankUpEntry *)work)->frame < 31) {
        RwMatrixRotate(&matrix, &state.axis, state.angle, 0);
    } else {
        frame = ((CmmRankUpEntry *)work)->frame - 30;
        axisTemplate.vector = D_00636250;
        axis = axisTemplate;
        RwMatrixRotate(&matrix, &state.axis, state.angle, 0);
        RwMatrixRotate(&matrix, &axis.vector, -90.0f * (f32)frame / 30.0f, 2);
    }
    textureA = datPortraitValue(context->unk_14);
    textureB = datPortraitValue(context->slot18.word);
    if (entry->frame >= 25) {
        f32 factor;
        overlay = shdSpriteSlotHandle(25, 0, context->slot10.sprites);
        if (entry->frame < 31) {
            factor = (f32)(entry->frame - 25) / 5.0f;
        } else {
            factor = (f32)(entry->frame - 30);
            if (factor < 5.0f) {
                factor = 1.0f - factor / 5.0f;
            } else {
                factor = 0.0f;
            }
        }
        RwMatrixRotate(&effectMatrix, &state.axis, D_007613A0 * factor, 0);
        RwMatrixMultiply((u8 *)&product, (u8 *)&effectMatrix, (u8 *)&matrix);
        {
            u_long128 *source;
            u_long128 *destination;
            s32 count;
            u_long128 value;
            source = (u_long128 *)&product;
            destination = (u_long128 *)&effectMatrix;
            count = 4;
            do {
                value = *source;
                source++;
                count--;
                *destination = value;
                destination++;
            } while (count > 0);
        }
        sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f, 115, 144, 0xFFFFFF,
            *(u8 *)&state.color, 1, 57, 72, &effectMatrix, overlay, overlayUv.coordinates);
        if (is10) {
            sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f, 109, 137, 0x7F7F7F,
                255, 1, 55, 69, &matrix, overlay, overlayUv.coordinates);
        } else {
            sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f, 109, 137, 0xFF9C35,
                255, 1, 55, 69, &matrix, overlay, overlayUv.coordinates);
        }
    }
    sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f, state.width, state.height,
        (u32)state.color >> 8, (u32)state.color & 255, 3,
        (s16)(state.width >> 1), (s16)(state.height >> 1), &matrix, textureA, uv.coordinates);
    sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f, state.width, state.height,
        (u32)state.color >> 8, (u32)state.color & 255, 5,
        (s16)(state.width >> 1), (s16)(state.height >> 1), &matrix, textureB, uv.coordinates);
    renderState = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderState)(7, 2);
    (*(void (**)(u32, u32))renderState)(9, 2);
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 0);
    (*(void (**)(u32, u32))renderState)(12, 1);
    (*(void (**)(u32, u32))renderState)(2, 4);
    (*(void (**)(u32, u32))renderState)(14, 0);
    RpSkyRenderStateSet(3, 0x30003);
    RpSkyRenderStateSet(2, 0x48);
    context->pulse120.ticks += 1;
    if (context->pulse120.ticks >= 120) {
        context->pulse120.ticks = 0;
    }
    pulse = sinf(D_007612CC + D_007612D0 * (f32)context->pulse120.ticks / 120.0f);
    pulse = (1.0f + pulse) / 2.0f;
    sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f, state.width, state.height,
        (u32)state.color >> 8, (s32)(0.8f * (f32)((u32)state.color & 255) * pulse), 2,
        (s16)(state.width >> 1), (s16)(state.height >> 1), &matrix, textureA, uv.coordinates);
    sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f, state.width, state.height,
        (u32)state.color >> 8, (s32)(0.8f * (f32)((u32)state.color & 255) * pulse), 4,
        (s16)(state.width >> 1), (s16)(state.height >> 1), &matrix, textureB, uv.coordinates);

    angle = D_007612D0 * ((f32)RpRandom() / 2147483648.0f);
    if ((f32)RpRandom() / 2147483648.0f < D_00761288) {
        radius = (f32)((u32)(46.0f * ((f32)RpRandom() / 2147483648.0f)) + 70U);
    } else {
        radius = (f32)((u32)(40.0f * ((f32)RpRandom() / 2147483648.0f)) + 30U);
    }
    displacement.v[0] = radius * cosf(angle);
    displacement.v[1] = -radius * sinf(angle);
    if (entry->frame < 41) {
        RankUpParticlePrefix *particle;
        f32 y = state.y + displacement.v[1];
        f32 x = state.x + displacement.v[0];
        particle = (RankUpParticlePrefix *)cmmRankUpReserveSparkle(root, 0);
        if (particle != NULL) {
            particle->x = x;
            particle->y = y;
        }
        {
            const u8 *source;
            u8 *destination;
            s32 count;
            s32 first;
            s32 second;
            source = D_00636260;
            destination = (u8 *)&positions;
            count = 5;
            do {
                first = (s32)((const CopyPair *)source)->w0;
                second = (s32)((const CopyPair *)source)->w1;
                source += 8;
                count--;
                ((CopyPair *)destination)->w0 = first;
                ((CopyPair *)destination)->w1 = second;
                destination += 8;
            } while (count > 0);
        }
        frame = (s32)(5.0f * ((f32)RpRandom() / 2147483648.0f));
        displacement = positions.points[frame];
        y = displacement.v[1];
        particle = (RankUpParticlePrefix *)cmmRankUpReserveSparkle(root, 3);
        if (particle != NULL) {
            particle->timer = (s32)(100.0f * ((f32)RpRandom() / 2147483648.0f));
            particle->x = displacement.v[0];
            particle->y = y;
        }
    }
    if (entry->frame == 20) {
        RankUpParticlePrefix *particle = (RankUpParticlePrefix *)cmmRankUpReserveSparkle(root, 1);
        if (particle != NULL) {
            particle->flags |= 2;
            particle->timer = (s32)(100.0f * ((f32)RpRandom() / 2147483648.0f));
            particle->x = 123.0f;
            particle->y = 272.0f;
        }
        particle = (RankUpParticlePrefix *)cmmRankUpReserveSparkle(root, 2);
        if (particle != NULL) {
            particle->flags |= 4;
            particle->timer = (s32)(100.0f * ((f32)RpRandom() / 2147483648.0f));
            particle->x = 68.0f;
            particle->y = 419.0f;
        }
    } else if (entry->frame == 31) {
        cmmRankUpFadeSparklePools((u8 *)root);
    }
    return done;
}
typedef struct { u8 r, g, b, a; } RankUpVertexColor;
extern u8 D_00636290[];
extern u8 D_00635CC0[];
extern u8 D_00635CE0[];
extern f32 D_00761174, D_0076118C, D_00761308, D_0076132C, D_0076139C;
s32 shdSpriteDrawNow(f32 x, f32 y, f32 depth, s32 color, u8 alpha, s32 entryId, s32 entryOffset, u8 *pack, s32 flags);
s32 shdSpriteDrawNowEx(f32 x, f32 y, f32 depth, s32 color, u8 alpha, s32 entryId, s32 entryOffset, u8 *pack, s32 flags, s16 width, s16 height, f32 rotation, f32 scaleX, f32 scaleY);
void PrimDrawPoints(void *colors, void *positions, f32 depth, s32 count, s32 primitiveType, s32 preserveState);
u8 *resourceFindByName(char *name);
f32 sdkSpriteEntryWidth(void *blob, s32 index);
void sdkSpriteDrawNowUnscaled(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void *pack, s32 setStates);
u8 *cmmNameRecord(u32 nameId);

/* measured: keep the banner constants explicit and the label distance local, because automatic
 * constant extraction joins the two distance evaluations. Draws the moving-point wipe for the rank-
 * up panel: a fixed quad set plus a pair of points that move across the panel. */
// FUN_00253850
#pragma push
#pragma opt_loop_invariants on
/* measured: retail needs both loop-invariant hoisting on and constant extraction off. */
#pragma opt_pulloutconstants off
s32 cmmRankUpDrawMovingWipe(u8 *root, u8 *work, CmmRankUpCardTask *context)
{
    CmmRankUpEntry *entry = (CmmRankUpEntry *)work;

    PrimPoint positions[8];
    PrimPoint movingPoints[4];
    RankUpVertexColor movingColors[4];
    PrimPoint fixedPoints[4];
    RankUpVertexColor fixedColors[4];
    s32 special;
    s32 color;
    s32 white;
    f32 bannerY;
    f32 progress;
    f32 pulse;
    f32 scaleX;
    f32 scaleY;

    special = 0;
    if (context->mode == 10) {
        special = 1;
    }
    if (((CmmRankUpEntry *)work)->frame > 15) {
        if (((CmmRankUpEntry *)work)->frame < 32) {
            s32 i;
            const u8 *source;
            u8 *destination;
            s32 count;
            s32 first;
            s32 second;
            source = D_00636290;
            destination = (u8 *)positions;
            count = 8;
            do {
                first = (s32)((const CopyPair *)source)->w0;
                second = (s32)((const CopyPair *)source)->w1;
                source += 8;
                count--;
                ((CopyPair *)destination)->w0 = first;
                ((CopyPair *)destination)->w1 = second;
                destination += 8;
            } while (count > 0);
            for (i = 0; i < 8; i++) {
                s32 elapsed = entry->frame - 15;
                if (!(elapsed < i)) {
                    if (elapsed - i < 9) {
                        f32 value = sinf(D_00761174 * (f32)(elapsed - i) / 8.0f);
                        shdSpriteDrawNow(
                            positions[i].v[0], (0.0f + positions[i].v[1]) - 40.0f * value, 0.0f, 0xFFFFFF, 255,
                            i + 13, 0, context->slot10.sprites, 1);
                    } else {
                        shdSpriteDrawNow(
                            positions[i].v[0], positions[i].v[1], 0.0f, 0xFFFFFF, 255, i + 13, 0,
                            context->slot10.sprites, 1);
                    }
                }
            }
        } else {
            shdSpriteDrawNow(
                356.0f, 340.0f, 0.0f, 0xFFFFFF, 255, 13, 0, context->slot10.sprites, 1);
            shdSpriteDrawNow(
                396.0f, 350.0f, 0.0f, 0xFFFFFF, 255, 14, 0, context->slot10.sprites, 1);
            shdSpriteDrawNow(
                430.0f, 350.0f, 0.0f, 0xFFFFFF, 255, 15, 0, context->slot10.sprites, 1);
            shdSpriteDrawNow(
                467.0f, 338.0f, 0.0f, 0xFFFFFF, 255, 16, 0, context->slot10.sprites, 1);
            shdSpriteDrawNow(
                515.0f, 349.0f, 0.0f, 0xFFFFFF, 255, 17, 0, context->slot10.sprites, 1);
            shdSpriteDrawNow(
                550.0f, 347.0f, 0.0f, 0xFFFFFF, 255, 18, 0, context->slot10.sprites, 1);
            shdSpriteDrawNow(
                588.0f, 340.0f, 0.0f, 0xFFFFFF, 255, 19, 0, context->slot10.sprites, 1);
            shdSpriteDrawNow(
                603.0f, 340.0f, 0.0f, 0xFFFFFF, 255, 19, 0, context->slot10.sprites, 1);
        }
    }
    if (entry->frame < 16) {
        f32 value = sinf(D_00761184 * (f32)entry->frame / 15.0f);
        white = 0xFFFFFF;
        bannerY = 375.0f;
        shdSpriteDrawNow(
            -(640.0f * (1.0f - value)), bannerY, 0.0f, white, 255, 41, 0, context->slot10.sprites, 1);
    } else {
        white = 0xFFFFFF;
        bannerY = 375.0f;
        shdSpriteDrawNow(
            0.0f, bannerY, 0.0f, white, 255, 41, 0, context->slot10.sprites, 1);
    }
    if (entry->frame > 7) {
        if (entry->frame < 16) {
            f32 value = sinf(D_00761184 * ((f32)entry->frame - 7.0f) / 8.0f);
            shdSpriteDrawNowEx(
                0.0f, (0.0f + 380.0f) + 10.0f * (1.0f - value), 0.0f, white, 255, special + 42, 0,
                context->slot10.sprites, 1, 0, 0, 0.0f, 1.0f, value);
        } else {
            shdSpriteDrawNow(
                0.0f, 380.0f, 0.0f, white, 255, special + 42, 0, context->slot10.sprites, 1);
        }
    }
    if (entry->frame > 18) {
        if (entry->frame < 27) {
            f32 value;
            f32 displacement;
            f32 distance;
            f32 complement;
            const u8 *source;
            u8 *destination;
            s32 count;
            s32 first;
            s32 second;
            u32 vertex;
            s32 relation;
            u8 *sprites;
            u8 *font;
            s32 offset;
            s32 width;
            value = sinf(D_00761184 * (f32)(entry->frame - 18) / 8.0f);
            if (special == 0) {
                displacement = 1.0f - value;
                distance = 450.0f;
                distance *= displacement;
                displacement = distance;
                shdSpriteDrawNow(
                    188.0f + displacement, bannerY, 0.0f, white, 255, 1, 0, context->slot10.sprites, 1);
            } else {
                displacement = 1.0f - value;
                distance = 450.0f;
                distance *= displacement;
                displacement = distance;
                shdSpriteDrawNow(
                    184.0f + displacement, 336.0f, 0.0f, white, 255, 26, 0, context->slot10.sprites, 1);
            }
            source = D_00635CC0;
            destination = (u8 *)movingPoints;
            count = 4;
            do {
                first = (s32)((const CopyPair *)source)->w0;
                second = (s32)((const CopyPair *)source)->w1;
                source += 8;
                count--;
                ((CopyPair *)destination)->w0 = first;
                ((CopyPair *)destination)->w1 = second;
                destination += 8;
            } while (count > 0);
            for (vertex = 0; vertex < 4; vertex++) {
                movingPoints[vertex].v[0] += (f32)(s32)(218.0f + displacement);
                movingPoints[vertex].v[1] += 406.0f;
                movingColors[vertex].r = 0;
                movingColors[vertex].g = 0;
                movingColors[vertex].b = 0;
                movingColors[vertex].a = 0x99;
            }
            PrimDrawPoints(movingColors, movingPoints, 0.0f, 4, 4, 1);
            relation = context->relation;
            sprites = context->slot10.sprites;
            font = resourceFindByName((char *)D_00635CE0);
            if (font == NULL) {
                kAssertFail(D_00635CF8, 0x1E4);
            }
            width = (s32)sdkSpriteEntryWidth(font, ((u8 *)cmmKindRecord(relation & 0xFFFF))[8] + 0x20);
            complement = 1.0f;
            complement -= value;
            offset = (s32)(450.0f * complement);
            sdkSpriteDrawNowUnscaled(
                (f32)((offset + 299) - (width >> 1)), 407.0f, 0.0f, 0xFFFFFF, 255,
                ((u8 *)cmmKindRecord((u32)relation & 0xFFFF))[8] + 0x20, font, 1);
            shdSpriteDrawNow(
                (f32)(offset + 355), 411.0f, 0.0f, 0xFFFFFF, 255, 22, 0, sprites, 1);
            frFontExDrawText((f32)(offset + 392), 403.0f, 0.0f,
                -1, 0, 1, (const char *)cmmNameRecord((u16)relation), 0, 0);
        } else {
            const u8 *source;
            u8 *destination;
            s32 count;
            s32 first;
            s32 second;
            u32 vertex;
            s32 relation;
            u8 *sprites;
            u8 *font;
            s32 width;
            if (special == 0) {
                shdSpriteDrawNow(
                    188.0f, bannerY, 0.0f, white, 255, 1, 0, context->slot10.sprites, 1);
            } else {
                shdSpriteDrawNow(
                    184.0f, 336.0f, 0.0f, white, 255, 26, 0, context->slot10.sprites, 1);
            }
            source = D_00635CC0;
            destination = (u8 *)fixedPoints;
            count = 4;
            do {
                first = (s32)((const CopyPair *)source)->w0;
                second = (s32)((const CopyPair *)source)->w1;
                source += 8;
                count--;
                ((CopyPair *)destination)->w0 = first;
                ((CopyPair *)destination)->w1 = second;
                destination += 8;
            } while (count > 0);
            for (vertex = 0; vertex < 4; vertex++) {
                fixedPoints[vertex].v[0] += 218.0f;
                fixedPoints[vertex].v[1] += 406.0f;
                fixedColors[vertex].r = 0;
                fixedColors[vertex].g = 0;
                fixedColors[vertex].b = 0;
                fixedColors[vertex].a = 0x99;
            }
            PrimDrawPoints(fixedColors, fixedPoints, 0.0f, 4, 4, 1);
            relation = context->relation;
            sprites = context->slot10.sprites;
            font = resourceFindByName((char *)D_00635CE0);
            if (font == NULL) {
                kAssertFail(D_00635CF8, 0x1E4);
            }
            width = (s32)sdkSpriteEntryWidth(font, ((u8 *)cmmKindRecord(relation & 0xFFFF))[8] + 0x20);
            sdkSpriteDrawNowUnscaled(
                (f32)(299 - (width >> 1)), 407.0f, 0.0f, 0xFFFFFF, 255,
                ((u8 *)cmmKindRecord((u32)relation & 0xFFFF))[8] + 0x20, font, 1);
            shdSpriteDrawNow(
                355.0f, 411.0f, 0.0f, 0xFFFFFF, 255, 22, 0, sprites, 1);
            frFontExDrawText(392.0f, 403.0f, 0.0f, -1, 0, 1, (const char *)cmmNameRecord((u16)relation), 0, 0);
        }
    }
    if (entry->frame > 30) {
        if (entry->frame < 39) {
            f32 value = sinf(D_00761174 * (f32)(entry->frame - 30) / 8.0f);
            if (special == 0) {
                shdSpriteDrawNow(
                    277.0f, (0.0f + 350.0f) - 17.0f * value, 0.0f, white, 255, context->mode + 1, 0,
                    context->slot10.sprites, 1);
            }
        } else if (special == 0) {
            shdSpriteDrawNow(
                277.0f, 350.0f, 0.0f, white, 255, context->mode + 1, 0, context->slot10.sprites, 1);
        }
    }
    /* A star color is assigned before the glow can use it below. */
    if (entry->frame > 23) {
        if (entry->frame < 39) {
            s32 i;
            for (i = 0; i < 10; i++) {
                s32 elapsed = entry->frame - 23;
                if (!(elapsed < i)) {
                    f32 value;
                    if (context->mode <= i) {
                        color = 0xDE7201;
                    } else {
                        color = white;
                    }
                    value = (f32)(elapsed - i);
                    if (value < 5.0f) {
                        value = sinf(D_00761184 * value / 5.0f);
                        shdSpriteDrawNow(
                            (0.0f + (f32)(i * 23 + 354)) + 400.0f * (1.0f - value), 381.0f, 0.0f, color, 255,
                            21, 0, context->slot10.sprites, 1);
                    } else {
                        shdSpriteDrawNow(
                            (f32)(i * 23 + 354), 381.0f, 0.0f, color, 255, 21, 0, context->slot10.sprites, 1);
                    }
                }
            }
        } else {
            s32 i;
            for (i = 0; i < 10; i++) {
                if (context->mode <= i) {
                    color = 0xDE7201;
                } else {
                    color = white;
                }
                shdSpriteDrawNow(
                    (f32)(i * 23 + 354), 381.0f, 0.0f, color, 255, 21, 0, context->slot10.sprites, 1);
            }
        }
    }
    if (entry->frame > 30) {
        s32 index;
        context->pulse45 += 1;
        if (context->pulse45 >= 45) {
            context->pulse45 = 0;
        }
        index = context->mode - 1;
        pulse = sinf(D_007612CC + D_007612D0 * (f32)context->pulse45 / 45.0f);
        pulse = (0.0f + D_00761288) + D_0076118C * ((1.0f + pulse) / 2.0f);
        progress = 1.0f;
        if (entry->frame < 61) {
            progress = (f32)(entry->frame - 30) / 30.0f;
            shdSpriteDrawNowEx(
                (f32)(index * 23 + 357) - 58.0f * progress, 385.0f - 62.0f * progress, 0.0f, white,
                (u8)(255.0f * (1.0f - progress)), 27, 0, context->slot10.sprites, 1,
                (s16)(s32)(58.0f * progress), (s16)(s32)(62.0f * progress), 90.0f * progress, progress,
                progress);
        }
        pulse *= progress;
        scaleX = D_00761308 * pulse;
        scaleY = scaleX;
        scaleX = 1.0f;
        scaleX += scaleY;
        scaleY = scaleX;
        shdSpriteDrawNowEx(
            (0.0f + (f32)(index * 23 + 350)) - D_0076139C * pulse, (0.0f + 377.0f) - D_0076132C * pulse, 0.0f,
            color, (u8)(255.0f * pulse), 28, 0, context->slot10.sprites, 1, 0, 0, 0.0f, scaleX, scaleY);
    }
    return 0;
}
#pragma pop

typedef struct { u8 r, g, b, a; } RankUpExitColor;
typedef union {
    RankUpExitColor rgba;
    f32 copy;
} RankUpExitColorCopy;
typedef union {
    struct { s32 x, y, width, height; } rect;
    u_long128 copy;
} RankUpExitRect;
extern u8 D_006362D0[], D_00635CC0[], D_00635CE0[];
extern f32 D_0076118C;
s32 shdSpriteDrawNow(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
void PrimDrawPoints(void *, void *, f32, s32, s32, s32);
u8 *resourceFindByName(char *);
f32 sdkSpriteEntryWidth(void *, s32);
void sdkSpriteDrawNowUnscaled(f32, f32, f32, s32, u8, s32, void *, s32);
u8 *cmmNameRecord(u32);

/* measured: keep the unit scales local to their shrinking-sprite calls; otherwise one constant
 * stays live across both animation branches. Draws the exit wipe: copies the clip and reset
 * colours, then draws the sprite strips that slide in with the wipe. */
// FUN_00254A70
#pragma push
#pragma opt_loop_invariants on
/* measured: retail needs both loop-invariant hoisting on and constant extraction off. */
#pragma opt_pulloutconstants off
s32 cmmRankUpDrawExitWipe(u8 *root, u8 *work, CmmRankUpCardTask *context)
{
    RankUpExitColorCopy clipColor;
    RankUpExitColorCopy clipColorSource;
    RankUpExitColorCopy resetColor;
    RankUpExitColorCopy resetColorSource;
    PrimPoint positions[8];
    RankUpExitRect clipRect;
    RankUpExitRect clipRectSource;
    RankUpExitRect resetRect;
    RankUpExitRect resetRectSource;
    PrimPoint fixedPoints[4];
    RankUpExitColor fixedColors[4];
    PrimPoint movingPoints[4];
    RankUpExitColor movingColors[4];
    s32 special;
    s32 elapsed;
    f32 value;
    f32 scale;
    f32 translation;
    f32 origin;
    u8 *renderState;

    special = 0;
    if (context->mode == 10) {
        special = 1;
    }
    elapsed = ((CmmRankUpEntry *)work)->frame - 60;
    if (elapsed < 19) {
        s32 i;
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        source = D_006362D0;
        destination = (u8 *)positions;
        count = 8;
        do {
            first = (s32)((const CopyPair *)source)->w0;
            second = (s32)((const CopyPair *)source)->w1;
            source += 8;
            count--;
            ((CopyPair *)destination)->w0 = first;
            ((CopyPair *)destination)->w1 = second;
            destination += 8;
        } while (count > 0);
        {
            u8 *cursor;
            u32 remaining;
            cursor = (u8 *)&clipColorSource;
            remaining = sizeof(clipColorSource);
            if (cursor != NULL) {
                do {
                    *cursor++ = 0;
                    remaining--;
                } while (remaining != 0);
            }
        }
        clipColor.copy = clipColorSource.copy;
        {
            u8 *cursor;
            u32 remaining;
            cursor = (u8 *)&clipRectSource;
            remaining = sizeof(clipRectSource);
            if (cursor != NULL) {
                do {
                    *cursor++ = 0;
                    remaining--;
                } while (remaining != 0);
            }
        }
        clipRectSource.rect.x = 350;
        clipRectSource.rect.y = 380;
        clipRectSource.rect.width = 290;
        clipRectSource.rect.height = 100;
        clipRect.copy = clipRectSource.copy;
        renderState = (u8 *)D_00887300;
        (*(void (**)(u32, u32))renderState)(14, 0);
        (*(void (**)(u32, u32))renderState)(12, 1);
        (*(void (**)(u32, u32))renderState)(7, 2);
        (*(void (**)(u32, u32))renderState)(9, 1);
        (*(void (**)(u32, u32))renderState)(20, 1);
        (*(void (**)(u32, u32))renderState)(6, 0);
        (*(void (**)(u32, u32))renderState)(8, 1);
        RpSkyRenderStateSet(3, 0x31003);
        RpSkyRenderStateSet(2, 0x44);
        mdlEffectEmitMaskedTagPair();
        PrimDrawFlatRectangle((u8 *)(&clipColor), (f32 *)(&clipRect), 5.0f, 0);
        mdlEffectEmitTagPair();
        for (i = 0; i < 8; i++) {
            if (!(elapsed < i)) {
                if (elapsed - i < 9) {
                    value = sinf(D_00761184 * (f32)(elapsed - i) / 8.0f);
                    shdSpriteDrawNow(positions[i].v[0], (0.0f + positions[i].v[1]) + 50.0f * value, 10.0f, 0xFFFFFF, 255, i + 13, 0, context->slot10.sprites, 1);
                }
            } else {
                shdSpriteDrawNow(positions[i].v[0], positions[i].v[1], 10.0f, 0xFFFFFF, 255, i + 13, 0, context->slot10.sprites, 1);
            }
        }
        {
            u8 *cursor;
            u32 remaining;
            cursor = (u8 *)&resetColorSource;
            remaining = sizeof(resetColorSource);
            if (cursor != NULL) {
                do {
                    *cursor++ = 0;
                    remaining--;
                } while (remaining != 0);
            }
        }
        resetColor.copy = resetColorSource.copy;
        {
            u8 *cursor;
            u32 remaining;
            cursor = (u8 *)&resetRectSource;
            remaining = sizeof(resetRectSource);
            if (cursor != NULL) {
                do {
                    *cursor++ = 0;
                    remaining--;
                } while (remaining != 0);
            }
        }
        resetRectSource.rect.x = 350;
        resetRectSource.rect.y = 380;
        resetRectSource.rect.width = 290;
        resetRectSource.rect.height = 100;
        resetRect.copy = resetRectSource.copy;
        renderState = (u8 *)D_00887300;
        (*(void (**)(u32, u32))renderState)(14, 0);
        (*(void (**)(u32, u32))renderState)(12, 1);
        (*(void (**)(u32, u32))renderState)(7, 2);
        (*(void (**)(u32, u32))renderState)(9, 1);
        (*(void (**)(u32, u32))renderState)(20, 1);
        (*(void (**)(u32, u32))renderState)(6, 0);
        (*(void (**)(u32, u32))renderState)(8, 1);
        RpSkyRenderStateSet(3, 0x31003);
        RpSkyRenderStateSet(2, 0x44);
        mdlEffectEmitMaskedTagPair();
        PrimDrawFlatRectangle((u8 *)(&resetColor), (f32 *)(&resetRect), 0.0f, 0);
        mdlEffectEmitTagPair();
    }
    if (elapsed < 25) {
        shdSpriteDrawNow(0.0f, 375.0f, 0.0f, 0xFFFFFF, 255, 41, 0, context->slot10.sprites, 1);
    } else if (elapsed < 36) {
        value = sinf(D_00761184 * (f32)(elapsed - 25) / 10.0f);
        shdSpriteDrawNow(640.0f * value, 375.0f, 0.0f, 0xFFFFFF, 255, 41, 0, context->slot10.sprites, 1);
    }
    if (elapsed < 30) {
        shdSpriteDrawNow(0.0f, 380.0f, 0.0f, 0xFFFFFF, 255, special + 42, 0, context->slot10.sprites, 1);
    } else if (elapsed < 36) {
        value = sinf(D_00761184 * (f32)(elapsed - 30) / 5.0f);
        shdSpriteDrawNowEx(0.0f, (0.0f + 380.0f) + 10.0f * value, 0.0f, 0xFFFFFF, 255, special + 42, 0, context->slot10.sprites, 1, 0, 0, 0.0f, 1.0f, 1.0f - value);
    }
    if (elapsed < 20) {
        s32 color;
        if (special == 0) {
            color = 0xFFFFFF;
            shdSpriteDrawNow(188.0f, 375.0f, 0.0f, color, 255, 1, 0, context->slot10.sprites, 1);
        } else {
            color = 0xFFFFFF;
            shdSpriteDrawNow(184.0f, 336.0f, 0.0f, color, 255, 26, 0, context->slot10.sprites, 1);
        }
        if (special == 0) {
            shdSpriteDrawNow(277.0f, 350.0f, 0.0f, color, 255, context->mode + 1, 0, context->slot10.sprites, 1);
        }
    } else if (elapsed < 26) {
        s32 color;
        value = sinf(D_00761184 * (f32)(elapsed - 20) / 5.0f);
        if (special == 0) {
            scale = 1.0f - value;
            color = 0xFFFFFF;
            shdSpriteDrawNowEx(188.0f, (0.0f + 375.0f) + 28.0f * value, 0.0f, color, 255, 1, 0, context->slot10.sprites, 1, 0, 0, 0.0f, 1.0f, scale);
        } else {
            scale = 1.0f - value;
            color = 0xFFFFFF;
            shdSpriteDrawNowEx(184.0f, (0.0f + 336.0f) + 62.0f * value, 0.0f, color, 255, 26, 0, context->slot10.sprites, 1, 0, 0, 0.0f, 1.0f, scale);
        }
        if (special == 0) {
            shdSpriteDrawNowEx(277.0f, (0.0f + 350.0f) + 50.0f * value, 0.0f, color, 255, context->mode + 1, 0, context->slot10.sprites, 1, 0, 0, 0.0f, 1.0f, scale);
        }
    }
    if (elapsed < 5) {
        s32 i;
        s32 color;
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        s32 relation;
        u8 *sprites;
        u8 *font;
        s32 width;
        u32 vertex;
        source = D_00635CC0;
        destination = (u8 *)fixedPoints;
        count = 4;
        do {
            first = (s32)((const CopyPair *)source)->w0;
            second = (s32)((const CopyPair *)source)->w1;
            source += 8;
            count--;
            ((CopyPair *)destination)->w0 = first;
            ((CopyPair *)destination)->w1 = second;
            destination += 8;
        } while (count > 0);
        for (vertex = 0; vertex < 4U; vertex++) {
            fixedPoints[vertex].v[0] += 218.0f;
            fixedPoints[vertex].v[1] += 406.0f;
            fixedColors[vertex].r = 0;
            fixedColors[vertex].g = 0;
            fixedColors[vertex].b = 0;
            fixedColors[vertex].a = 153;
        }
        PrimDrawPoints(fixedColors, fixedPoints, 0.0f, 4, 4, 1);
        relation = context->relation;
        sprites = context->slot10.sprites;
        font = resourceFindByName((char *)D_00635CE0);
        if (font == NULL) {
            kAssertFail(D_00635CF8, 0x1E4);
        }
        /* The width query masks the relation as signed and the glyph lookup as unsigned, as retail
         * does. */
        width = (s32)sdkSpriteEntryWidth(font, ((u8 *)cmmKindRecord(relation & 0xFFFF))[8] + 32);
        sdkSpriteDrawNowUnscaled((f32)(299 - (width >> 1)), 407.0f, 0.0f, 0xFFFFFF, 255, ((u8 *)cmmKindRecord((u32)relation & 0xFFFF))[8] + 32, font, 1);
        shdSpriteDrawNow(355.0f, 411.0f, 0.0f, 0xFFFFFF, 255, 22, 0, sprites, 1);
        frFontExDrawText(392.0f, 403.0f, 0.0f, -1, 0, 1,
            (const char *)cmmNameRecord((u16)relation), 0, 0);
        for (i = 0; i < 10; i++) {
            if (context->mode <= i) {
                color = 0xDE7201;
            } else {
                color = 0xFFFFFF;
            }
            shdSpriteDrawNow((f32)(i * 23 + 354), 381.0f, 0.0f, color, 255, 21, 0, context->slot10.sprites, 1);
        }
        context->pulse45 += 1;
        if (context->pulse45 >= 45) {
            context->pulse45 = 0;
        }
        value = sinf(D_007612CC + D_007612D0 * (f32)context->pulse45 / 45.0f);
        value = (0.0f + D_00761288) + D_0076118C * ((1.0f + value) / 2.0f);
        value *= 1.0f - (f32)elapsed / 5.0f;
        shdSpriteDrawNow((f32)((context->mode - 1) * 23 + 349), 376.0f, 0.0f, color, (u8)(255.0f * value), 28, 0, context->slot10.sprites, 1);
    } else if (elapsed < 21) {
        s32 i;
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        s32 relation;
        u8 *sprites;
        u8 *font;
        s32 width;
        s32 offset;
        u32 vertex;
        value = sinf(D_00761184 * (f32)(elapsed - 5) / 15.0f);
        source = D_00635CC0;
        destination = (u8 *)movingPoints;
        count = 4;
        do {
            first = (s32)((const CopyPair *)source)->w0;
            second = (s32)((const CopyPair *)source)->w1;
            source += 8;
            count--;
            ((CopyPair *)destination)->w0 = first;
            ((CopyPair *)destination)->w1 = second;
            destination += 8;
        } while (count > 0);
        vertex = 0;
        translation = 500.0f * value;
        origin = 218.0f;
        origin += translation;
        translation = origin;
        for (; vertex < 4U; vertex++) {
            movingPoints[vertex].v[0] += (f32)(s32)translation;
            movingPoints[vertex].v[1] += 406.0f;
            movingColors[vertex].r = 0;
            movingColors[vertex].g = 0;
            movingColors[vertex].b = 0;
            movingColors[vertex].a = 153;
        }
        PrimDrawPoints(movingColors, movingPoints, 0.0f, 4, 4, 1);
        relation = context->relation;
        sprites = context->slot10.sprites;
        font = resourceFindByName((char *)D_00635CE0);
        if (font == NULL) {
            kAssertFail(D_00635CF8, 0x1E4);
        }
        /* The width query masks the relation as signed and the glyph lookup as unsigned, as retail
         * does. */
        width = (s32)sdkSpriteEntryWidth(font, ((u8 *)cmmKindRecord(relation & 0xFFFF))[8] + 32);
        origin = 500.0f;
        origin *= value;
        value = origin;
        offset = (s32)value;
        sdkSpriteDrawNowUnscaled((f32)(offset + 299 - (width >> 1)), 407.0f, 0.0f, 0xFFFFFF, 255, ((u8 *)cmmKindRecord((u32)relation & 0xFFFF))[8] + 32, font, 1);
        shdSpriteDrawNow((f32)(offset + 355), 411.0f, 0.0f, 0xFFFFFF, 255, 22, 0, sprites, 1);
        frFontExDrawText((f32)(offset + 392), 403.0f, 0.0f, -1, 0, 1,
            (const char *)cmmNameRecord((u16)relation), 0, 0);
        for (i = 0; i < 10; i++) {
            shdSpriteDrawNow(value + (f32)(i * 23 + 354), 381.0f, 0.0f, context->mode <= i ? 0xDE7201 : 0xFFFFFF, 255, 21, 0, context->slot10.sprites, 1);
        }
    }
    return 0;
}
#pragma pop

// Timed rank-up step: counts the frame up to 0x78, runs phase A below 0x3D and phase B after, and returns 1 when the timer finishes.
// FUN_00255B00
s32 cmmRankUpStepTimed(u8 *root, s32 *entry, CmmRankUpCardTask *context) {
    s32 frame;
    s32 complete;

    complete = 0;
    if (entry[1] < 0x3C || !(entry[0] & 2)) {
        entry[1]++;
    }
    frame = entry[1];
    if (frame >= 0x78) {
        complete = 1;
    }
    if (frame < 0x3D) {
        cmmRankUpDrawMovingWipe(root, (u8 *)entry, context);
    } else {
        cmmRankUpDrawExitWipe(root, (u8 *)entry, context);
    }
    return complete;
}


/* Snapshot model weights and visibility for resource types 1, 2, 3 and 10; return a sentinel-terminated array. */
// FUN_00255B90
u8 *cmmRankUpFindResEntry(void) {
    u8 *entry;
    s32 count;
    ResrcRecord *cnt;
    ResrcRecord *node1;
    ResrcRecord *node2;
    ResrcRecord *node3;
    ResrcRecord *node4;

    /* The model layer weight is private to the model provider, so it is read by byte offset. */
    count = 0;
    cnt = (ResrcRecord *)MT_Scene_GetResListHead(1);
    while (cnt != NULL) {
        count++;
        cnt = cnt->next;
    }
    cnt = (ResrcRecord *)MT_Scene_GetResListHead(2);
    while (cnt != NULL) {
        count++;
        cnt = cnt->next;
    }
    cnt = (ResrcRecord *)MT_Scene_GetResListHead(3);
    while (cnt != NULL) {
        count++;
        cnt = cnt->next;
    }
    cnt = (ResrcRecord *)MT_Scene_GetResListHead(0xA);
    while (cnt != NULL) {
        count++;
        cnt = cnt->next;
    }
    chkmemAllocSiteTag(D_00635CF8, 0x5FA);
    entry = (u8 *)D_008873F4[0](1, (count + 1) * 0x10, 0x40000);
    count = 0;
    node1 = (ResrcRecord *)MT_Scene_GetResListHead(1);
    while (node1 != NULL) {
        RankUpResourceState *snapshot = (RankUpResourceState *)(entry + count * 0x10);
        snapshot->model = (u8 *)node1->modelHandle164;
        snapshot->enabled = MT_Scene_IsResEnabled((u8 *)node1);
        snapshot->weight = ((Model *)(u8 *)node1->modelHandle164)->layerSpeed;
        snapshot->resource = (u8 *)node1;
        count++;
        mdlSetLayerWeight((u8 *)node1->modelHandle164, 0, 0.0f);
        MT_Scene_SetResEnabledById(node1->resTypeId, 1);
        node1 = node1->next;
    }
    node2 = (ResrcRecord *)MT_Scene_GetResListHead(2);
    while (node2 != NULL) {
        RankUpResourceState *snapshot = (RankUpResourceState *)(entry + count * 0x10);
        snapshot->model = (u8 *)node2->modelHandle158;
        snapshot->enabled = MT_Scene_IsResEnabled((u8 *)node2);
        snapshot->weight = ((Model *)(u8 *)node2->modelHandle158)->layerSpeed;
        snapshot->resource = (u8 *)node2;
        count++;
        mdlSetLayerWeight((u8 *)node2->modelHandle158, 0, 0.0f);
        MT_Scene_SetResEnabledById(node1->resTypeId, 1);
        node2 = node2->next;
    }
    node3 = (ResrcRecord *)MT_Scene_GetResListHead(3);
    while (node3 != NULL) {
        RankUpResourceState *snapshot = (RankUpResourceState *)(entry + count * 0x10);
        snapshot->model = (u8 *)node3->modelHandle164;
        snapshot->enabled = MT_Scene_IsResEnabled((u8 *)node3);
        snapshot->weight = ((Model *)(u8 *)node3->modelHandle164)->layerSpeed;
        snapshot->resource = (u8 *)node3;
        count++;
        mdlSetLayerWeight((u8 *)node3->modelHandle164, 0, 0.0f);
        MT_Scene_SetResEnabledById(node3->resTypeId, 1);
        node3 = node3->next;
    }
    node4 = (ResrcRecord *)MT_Scene_GetResListHead(0xA);
    while (node4 != NULL) {
        RankUpResourceState *snapshot = (RankUpResourceState *)(entry + count * 0x10);
        snapshot->model = (u8 *)node4->slotHandle[1];
        snapshot->enabled = MT_Scene_IsResEnabled((u8 *)node4);
        snapshot->weight = ((Model *)(u8 *)node4->slotHandle[1])->layerSpeed;
        snapshot->resource = (u8 *)node4;
        count++;
        mdlSetLayerWeight((u8 *)node4->slotHandle[1], 0, 0.0f);
        MT_Scene_SetResEnabledById(node4->resTypeId, 1);
        node4 = node4->next;
    }
    return entry;
}


// Maps the counterpart state and the given index to a rank-up display slot (2 to 9), or 0 when the
// entry does not show.
// FUN_00255ED0
s32 cmmRankUpSelectDisplayIndex(s64 communityId, s32 rank) {
    if (((s32)((CmmKindRecord *)cmmKindRecord((u16)communityId))->flags & 0x10) != 0 &&
        (communityId != 0x18 || datGetFlag(0x38) != 0)) {
        if ((s16)cmmResolveCounterpart(communityId) == 3 ||
            (s16)cmmResolveCounterpart(communityId) == 4) {
            if (rank == 3) {
                return 7;
            }
            if (rank == 6) {
                return 8;
            }
            if (rank == 10) {
                return 9;
            }
        } else {
            if (rank == 3) {
                return 2;
            }
            if (rank == 7) {
                return 3;
            }
            if (rank == 5) {
                return 4;
            }
            if (rank == 9) {
                return 5;
            }
            if (rank == 1) {
                return 6;
            }
        }
    }
    return 0;
}


// Draws a message centred on x: splits it into runs, measures them, moves the list and sets the
// glyph colour from the alpha argument.
// FUN_00256040
void cmmRankUpDrawCenteredText(f32 x, f32 y, f32 depth, s32 rgb, s32 alpha,
                   s32 font, s32 style, s32 flags, s32 messageSlot, s32 stringIndex,
                   s32 lineIndex) {
    u8 *remainingRuns;
    u8 *line;
    u8 *node;
    s32 width;

    itfMesWindowApplySlots(messageSlot);
    remainingRuns = itfMesWindowBuildEntry(x, y, depth, (rgb << 8) | alpha, font,
                         style, flags, messageSlot, stringIndex);
    if (remainingRuns != NULL) {
        line = frFontSplitRun(&remainingRuns, lineIndex);
        if (line == NULL) {
            line = remainingRuns;
            remainingRuns = NULL;
        }
        node = line;
        width = 0;
        while (node != NULL) {
            width += frFontNodeWidth(node);
            node = (u8 *)((FrFontNode *)node)->next;
        }
        frFontMoveListToFloat(line, x - ((f32)width / 2.0f), y);
        frFontSetGlyphColor(line, alpha | ~0xFF);
        frFontDrawList(line, 1, 0);
        frFontListKeepOrRelease(line);
        if (remainingRuns != NULL) {
            frFontListKeepOrRelease(remainingRuns);
        }
    }
}


/* Same as cmmRankUpDrawGradientStripPass2 except for the palette table address; callers pass both
 * offsets explicitly. */
typedef struct { u8 r, g, b, a; } RankUpColor;

// Draws the palette gradient strip: copies the palette table into 16 point rows, then colours the
// rows by the upper and lower alpha values.
// FUN_002561F0
/* measured: retail hoists the loop-invariant colour divisions out of the loop. */
#pragma push
#pragma opt_loop_invariants on
void cmmRankUpDrawGradientStrip(f32 translateX, f32 translateY, f32 depth,
                   s32 rgbValue, s32 mainAlpha, s32 upperAlpha, s32 lowerAlpha,
                   s32 saveState, s32 offsetX, s32 offsetY,
                   f32 scaleX, f32 scaleY)
{
    PrimPointRow positions[16];
    RankUpColor colors[20];
    RankUpColor edge;
    RankUpColor mainColor;
    RankUpColor upper;
    RankUpColor lower;
    const CopyPair *source;
    PrimPointRow *destination;
    u32 word0;
    u32 word1;
    u32 rgb;
    u32 packed;
    s32 remaining;
    u32 index;
    PrimPointRow *point;
    RankUpColor *color;
    f32 scaledUpper;
    f32 scaledLower;

    source = D_00636310;
    destination = positions;
    remaining = 16;
    do {
        word0 = source->w0;
        word1 = source->w1;
        source++;
        remaining--;
        destination->words.w0 = word0;
        destination->words.w1 = word1;
        destination++;
    } while (remaining > 0);
    index = 0;
    rgb = (u32)rgbValue << 8;
    edge.r = (rgb >> 24) & 255;
    edge.g = (rgb >> 16) & 255;
    edge.b = rgbValue & 255;
    edge.a = rgb & 255;
    scaledUpper = 255.0f * (f32)upperAlpha;
    scaledLower = 255.0f * (f32)lowerAlpha;
    packed = rgb | mainAlpha;
    mainColor.r = (packed >> 24) & 255;
    mainColor.g = (packed >> 16) & 255;
    mainColor.b = (packed >> 8) & 255;
    mainColor.a = packed & 255;
    while (index < 16U) {
        point = &positions[index];
        point->point.v[0] += translateX;
        point->point.v[1] += translateY;
        if (index == 0 || index == 1 || (u32)(index - 14) < 2U) {
            color = &colors[index];
            color->r = edge.r;
            color->g = edge.g;
            color->b = edge.b;
            color->a = edge.a;
        } else if ((u32)(index - 6) < 4U) {
            packed = rgb | (s32)(scaledUpper / 255.0f);
            upper.r = packed >> 24;
            upper.g = packed >> 16;
            upper.b = packed >> 8;
            upper.a = packed;
            color = &colors[index];
            color->r = upper.r;
            color->g = upper.g;
            color->b = upper.b;
            color->a = upper.a;
        } else if ((u32)(index - 10) < 4U) {
            packed = rgb | (s32)(scaledLower / 255.0f);
            lower.r = packed >> 24;
            lower.g = packed >> 16;
            lower.b = packed >> 8;
            lower.a = packed;
            color = &colors[index];
            color->r = lower.r;
            color->g = lower.g;
            color->b = lower.b;
            color->a = lower.a;
        } else {
            color = &colors[index];
            color->r = mainColor.r;
            color->g = mainColor.g;
            color->b = mainColor.b;
            color->a = mainColor.a;
        }
        index++;
    }
    offsetX = (s16)offsetX;
    offsetY = (s16)offsetY;
    PrimDrawTransformed(colors, &positions,
                  depth, 16U, 4, saveState, offsetX, offsetY,
                  0.0f, scaleX, scaleY);
}

/* Draws the 16-point rank-up panel with separate upper and lower alpha; each point's word copy and
 * float translation share one storage union. */

// Second palette gradient strip; same layout as cmmRankUpDrawGradientStrip with its own palette
// table.
// FUN_00256460
/* measured: relies on the same loop-invariant colour hoisting as the first gradient strip. */
void cmmRankUpDrawGradientStripPass2(f32 translateX, f32 translateY, f32 depth,
                   s32 rgbValue, s32 mainAlpha, s32 upperAlpha, s32 lowerAlpha,
                   s32 saveState, s32 offsetX, s32 offsetY,
                   f32 scaleX, f32 scaleY)
{
    PrimPointRow positions[16];
    RankUpColor colors[20];
    RankUpColor edge;
    RankUpColor mainColor;
    RankUpColor upper;
    RankUpColor lower;
    const CopyPair *source;
    PrimPointRow *destination;
    u32 word0;
    u32 word1;
    u32 rgb;
    u32 packed;
    s32 remaining;
    u32 index;
    PrimPointRow *point;
    RankUpColor *color;
    f32 scaledUpper;
    f32 scaledLower;

    source = D_00636390;
    destination = positions;
    remaining = 16;
    do {
        word0 = source->w0;
        word1 = source->w1;
        source++;
        remaining--;
        destination->words.w0 = word0;
        destination->words.w1 = word1;
        destination++;
    } while (remaining > 0);
    index = 0;
    rgb = (u32)rgbValue << 8;
    edge.r = (rgb >> 24) & 255;
    edge.g = (rgb >> 16) & 255;
    edge.b = rgbValue & 255;
    edge.a = rgb & 255;
    scaledUpper = 255.0f * (f32)upperAlpha;
    scaledLower = 255.0f * (f32)lowerAlpha;
    packed = rgb | mainAlpha;
    mainColor.r = (packed >> 24) & 255;
    mainColor.g = (packed >> 16) & 255;
    mainColor.b = (packed >> 8) & 255;
    mainColor.a = packed & 255;
    while (index < 16U) {
        point = &positions[index];
        point->point.v[0] += translateX;
        point->point.v[1] += translateY;
        if (index == 0 || index == 1 || (u32)(index - 14) < 2U) {
            color = &colors[index];
            color->r = edge.r;
            color->g = edge.g;
            color->b = edge.b;
            color->a = edge.a;
        } else if ((u32)(index - 6) < 4U) {
            packed = rgb | (s32)(scaledUpper / 255.0f);
            upper.r = packed >> 24;
            upper.g = packed >> 16;
            upper.b = packed >> 8;
            upper.a = packed;
            color = &colors[index];
            color->r = upper.r;
            color->g = upper.g;
            color->b = upper.b;
            color->a = upper.a;
        } else if ((u32)(index - 10) < 4U) {
            packed = rgb | (s32)(scaledLower / 255.0f);
            lower.r = packed >> 24;
            lower.g = packed >> 16;
            lower.b = packed >> 8;
            lower.a = packed;
            color = &colors[index];
            color->r = lower.r;
            color->g = lower.g;
            color->b = lower.b;
            color->a = lower.a;
        } else {
            color = &colors[index];
            color->r = mainColor.r;
            color->g = mainColor.g;
            color->b = mainColor.b;
            color->a = mainColor.a;
        }
        index++;
    }
    offsetX = (s16)offsetX;
    offsetY = (s16)offsetY;
    PrimDrawTransformed(colors, &positions,
                  depth, 16U, 4, saveState, offsetX, offsetY,
                  0.0f, scaleX, scaleY);
}
#pragma pop


/* Draws the expanding texture with a fade in four passes, using the interpolation and expansion
 * values; typed keyframes and separate expansion/centering lifetimes keep that shape. */
// FUN_002566D0
void cmmRankUpDrawFadedExpansion(f32 unusedX, f32 unusedY, f32 unusedZ,
                  s32 unusedColor, s32 alpha, f32 interpolation, f32 expansion,
                  s32 textureA, s32 textureB)
{
    RankUpSpriteState state;
    union { RankUpSpriteState states[2]; s32 words[18]; } keys;
    union { f32 coordinates[4][2]; s32 words[8]; } uv;
    RankUpMatrix matrix;
    const u8 *source;
    u8 *destination;
    s32 count;
    s32 first;
    s32 second;
    f32 effect;
    f32 opacity;
    f32 growth;
    f32 center;
    u8 *renderState;

    effect = expansion;
    source = D_00636410;
    destination = (u8 *)&keys;
    count = 9;
    do {
        first = (s32)((const CopyPair *)source)->w0;
        second = (s32)((const CopyPair *)source)->w1;
        source += 8;
        count--;
        ((CopyPair *)destination)->w0 = first;
        ((CopyPair *)destination)->w1 = second;
        destination += 8;
    } while (count > 0);
    source = D_00636460;
    destination = (u8 *)&uv;
    count = 4;
    do {
        first = (s32)((const CopyPair *)source)->w0;
        second = (s32)((const CopyPair *)source)->w1;
        source += 8;
        count--;
        ((CopyPair *)destination)->w0 = first;
        ((CopyPair *)destination)->w1 = second;
        destination += 8;
    } while (count > 0);

    opacity = (f32)alpha / 255.0f;
    growth = 0.25f * effect;
    cmmRankUpLerpState(&state, &keys.states[0], &keys.states[1], interpolation);
    RwMatrixRotate(&matrix, &state.axis, state.angle, 0);
    sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f,
                  state.width, state.height, (u32)state.color >> 8,
                  (s32)((f32)((u32)state.color & 0xFF) * opacity), 3,
                  (s16)(state.width >> 1), (s16)(state.height >> 1),
                  &matrix, textureA, uv.coordinates);
    sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f,
                  state.width, state.height, (u32)state.color >> 8,
                  (s32)((f32)((u32)state.color & 0xFF) * opacity), 5,
                  (s16)(state.width >> 1), (s16)(state.height >> 1),
                  &matrix, textureB, uv.coordinates);
    renderState = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 1);
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x48);

    effect = D_0076122C * (1.0f - effect);
    effect = effect * opacity;
    {
        s16 height = state.height;
        s16 width = state.width;
        u32 packed = (u32)state.color;
        opacity = 1.0f + growth;
        center = 0.5f * growth;
        sflDataDrawTexturedQuad((s32)((0.0f + state.x) - (f32)width * center),
                      (s32)((0.0f + state.y) - (f32)height * center), 0.0f,
                      (s32)((f32)width * opacity), (s32)((f32)height * opacity),
                      packed >> 8,
                      (s32)((f32)(packed & 0xFF) * effect), 2,
                      (s16)(width >> 1), (s16)(height >> 1),
                      &matrix, textureA, uv.coordinates);
    }
    sflDataDrawTexturedQuad((s32)((0.0f + state.x) - (f32)state.width * center),
                  (s32)((0.0f + state.y) - (f32)state.height * center), 0.0f,
                  (s32)((f32)state.width * opacity), (s32)((f32)state.height * opacity),
                  (u32)state.color >> 8,
                  (s32)((f32)((u32)state.color & 0xFF) * effect), 4,
                  (s16)(state.width >> 1), (s16)(state.height >> 1),
                  &matrix, textureB, uv.coordinates);
}
/* Same expanding fade as cmmRankUpDrawFadedExpansion, for the second texture pair; typed keyframes
 * and separate expansion/centering lifetimes keep the four-pass draw. */
// FUN_00256BE0
void cmmRankUpDrawFadedExpansionPass2(f32 unusedX, f32 unusedY, f32 unusedZ,
                  s32 unusedColor, s32 alpha, f32 interpolation, f32 expansion,
                  s32 textureA, s32 textureB)
{
    RankUpSpriteState state;
    union { RankUpSpriteState states[2]; s32 words[18]; } keys;
    union { f32 coordinates[4][2]; s32 words[8]; } uv;
    RankUpMatrix matrix;
    const u8 *source;
    u8 *destination;
    s32 count;
    s32 first;
    s32 second;
    f32 effect;
    f32 opacity;
    f32 growth;
    f32 center;
    u8 *renderState;

    effect = expansion;
    source = D_00636480;
    destination = (u8 *)&keys;
    count = 9;
    do {
        first = (s32)((const CopyPair *)source)->w0;
        second = (s32)((const CopyPair *)source)->w1;
        source += 8;
        count--;
        ((CopyPair *)destination)->w0 = first;
        ((CopyPair *)destination)->w1 = second;
        destination += 8;
    } while (count > 0);
    source = D_006364D0;
    destination = (u8 *)&uv;
    count = 4;
    do {
        first = (s32)((const CopyPair *)source)->w0;
        second = (s32)((const CopyPair *)source)->w1;
        source += 8;
        count--;
        ((CopyPair *)destination)->w0 = first;
        ((CopyPair *)destination)->w1 = second;
        destination += 8;
    } while (count > 0);

    opacity = (f32)alpha / 255.0f;
    growth = 0.25f * effect;
    cmmRankUpLerpState(&state, &keys.states[0], &keys.states[1], interpolation);
    RwMatrixRotate(&matrix, &state.axis, state.angle, 0);
    sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f,
                  state.width, state.height, (u32)state.color >> 8,
                  (s32)((f32)((u32)state.color & 0xFF) * opacity), 3,
                  (s16)(state.width >> 1), (s16)(state.height >> 1),
                  &matrix, textureA, uv.coordinates);
    sflDataDrawTexturedQuad((s32)state.x, (s32)state.y, 0.0f,
                  state.width, state.height, (u32)state.color >> 8,
                  (s32)((f32)((u32)state.color & 0xFF) * opacity), 5,
                  (s16)(state.width >> 1), (s16)(state.height >> 1),
                  &matrix, textureB, uv.coordinates);
    renderState = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 1);
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x48);

    effect = D_0076122C * (1.0f - effect);
    effect = effect * opacity;
    {
        s16 height = state.height;
        s16 width = state.width;
        u32 packed = (u32)state.color;
        opacity = 1.0f + growth;
        center = 0.5f * growth;
        sflDataDrawTexturedQuad((s32)((0.0f + state.x) - (f32)width * center),
                      (s32)((0.0f + state.y) - (f32)height * center), 0.0f,
                      (s32)((f32)width * opacity), (s32)((f32)height * opacity),
                      packed >> 8,
                      (s32)((f32)(packed & 0xFF) * effect), 2,
                      (s16)(width >> 1), (s16)(height >> 1),
                      &matrix, textureA, uv.coordinates);
    }
    sflDataDrawTexturedQuad((s32)((0.0f + state.x) - (f32)state.width * center),
                  (s32)((0.0f + state.y) - (f32)state.height * center), 0.0f,
                  (s32)((f32)state.width * opacity), (s32)((f32)state.height * opacity),
                  (u32)state.color >> 8,
                  (s32)((f32)((u32)state.color & 0xFF) * effect), 4,
                  (s16)(state.width >> 1), (s16)(state.height >> 1),
                  &matrix, textureB, uv.coordinates);
}
typedef union {
    u8 channels[4];
    f32 bits;
    s32 packed;
} RankUpPackedColor;
typedef union {
    struct { s32 x, y, width, height; } fields;
    u_long128 quad;
} RankUpRectangle;

// Draws the wipe rectangle: interpolates the first and second screen rectangles by progress and
// draws them with the texture.
// FUN_002570F0
void cmmRankUpDrawWipeRect(f32 unusedX, f32 unusedY, f32 unusedZ,
                  s32 unusedColor, s32 alpha, f32 progress, s32 texture)
{
    RankUpPackedColor wipeColor;
    RankUpPackedColor firstColorCopy;
    RankUpPackedColor firstColor;
    RankUpPackedColor secondColorCopy;
    RankUpPackedColor secondColor;
    RankUpSpriteState state;
    union { RankUpSpriteState states[2]; s32 words[18]; } keys;
    union { f32 coordinates[4][2]; s32 words[8]; } uv;
    RankUpMatrix matrix;
    RankUpRectangle rectangle;
    RankUpRectangle firstTemplate;
    RankUpRectangle secondTemplate;
    RankUpRectangle firstScreenCopy;
    RankUpRectangle firstScreen;
    RankUpRectangle secondScreenCopy;
    RankUpRectangle secondScreen;
    const u8 *source;
    u8 *destination;
    s32 count;
    s32 first;
    s32 second;
    f32 opacity;
    f32 deltaX;
    f32 deltaY;
    u8 *renderState;

    source = D_006364F0;
    destination = (u8 *)&keys;
    count = 9;
    do {
        first = (s32)((const CopyPair *)source)->w0;
        second = (s32)((const CopyPair *)source)->w1;
        source += 8;
        count--;
        ((CopyPair *)destination)->w0 = first;
        ((CopyPair *)destination)->w1 = second;
        destination += 8;
    } while (count > 0);
    source = D_00636540;
    destination = (u8 *)&uv;
    count = 4;
    do {
        first = (s32)((const CopyPair *)source)->w0;
        second = (s32)((const CopyPair *)source)->w1;
        source += 8;
        count--;
        ((CopyPair *)destination)->w0 = first;
        ((CopyPair *)destination)->w1 = second;
        destination += 8;
    } while (count > 0);
    {
        u8 *bytes = (u8 *)&wipeColor;
        s32 remaining = 4;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    opacity = (f32)alpha / 255.0f;
    cmmRankUpLerpState(&state, &keys.states[0], &keys.states[1], 0.0f);
    RwMatrixRotate(&matrix, &state.axis, state.angle, 0);
    deltaX = 80.0f * progress;
    deltaY = -80.0f * progress;
    {
        u8 *bytes = (u8 *)&firstColor;
        s32 remaining = 4;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    firstColorCopy.bits = firstColor.bits;
    {
        u8 *bytes = (u8 *)&firstScreen;
        s32 remaining = 16;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    firstScreen.fields.x = 0;
    firstScreen.fields.y = 0;
    firstScreen.fields.width = 640;
    firstScreen.fields.height = 480;
    firstScreenCopy = firstScreen;
    renderState = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderState)(14, 0);
    (*(void (**)(u32, u32))renderState)(12, 1);
    (*(void (**)(u32, u32))renderState)(7, 2);
    (*(void (**)(u32, u32))renderState)(9, 1);
    (*(void (**)(u32, u32))renderState)(20, 1);
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 1);
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x44);
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle((u8 *)(&firstColorCopy), (f32 *)(&firstScreenCopy), 10.0f, 0);
    mdlEffectEmitTagPair();
    /* Each template and the working rectangle is copied as a whole 16-byte object. */
    *(u_long128 *)&firstTemplate = D_00636560;
    *(u_long128 *)&rectangle = *(u_long128 *)&firstTemplate;
    rectangle.fields.x = (s32)((f32)rectangle.fields.x + deltaX);
    rectangle.fields.y = (s32)((f32)rectangle.fields.y + deltaY);
    (*(void (**)(u32, u32))renderState)(6, 1);
    (*(void (**)(u32, u32))renderState)(8, 1);
    RpSkyRenderStateSet(3, 0x71003);
    RpSkyRenderStateSet(2, 0x44);
    PrimDrawRectangle((u8 *)&wipeColor, (u8 *)&rectangle, 0.0f, 0, 200, 0,
                  45.0f, 1.0f, 1.0f);
    sflDataDrawTexturedQuad((s32)(state.x + deltaX), (s32)(state.y + deltaY), 5.0f,
                  state.width, state.height, (u32)state.color >> 8,
                  (s32)((f32)((u32)state.color & 0xFF) * opacity), 1,
                  (s16)(state.width >> 1), (s16)(state.height >> 1),
                  &matrix, texture, uv.coordinates);
    {
        u8 *bytes = (u8 *)&secondColor;
        s32 remaining = 4;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    secondColorCopy.bits = secondColor.bits;
    {
        u8 *bytes = (u8 *)&secondScreen;
        s32 remaining = 16;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    secondScreen.fields.x = 0;
    secondScreen.fields.y = 0;
    secondScreen.fields.width = 640;
    secondScreen.fields.height = 480;
    secondScreenCopy = secondScreen;
    (*(void (**)(u32, u32))renderState)(14, 0);
    (*(void (**)(u32, u32))renderState)(12, 1);
    (*(void (**)(u32, u32))renderState)(7, 2);
    (*(void (**)(u32, u32))renderState)(9, 1);
    (*(void (**)(u32, u32))renderState)(20, 1);
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 1);
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x44);
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle((u8 *)(&secondColorCopy), (f32 *)(&secondScreenCopy), 10.0f, 0);
    mdlEffectEmitTagPair();
    *(u_long128 *)&secondTemplate = D_00636570;
    *(u_long128 *)&rectangle = *(u_long128 *)&secondTemplate;
    rectangle.fields.x = (s32)((f32)rectangle.fields.x - deltaX);
    rectangle.fields.y = (s32)((f32)rectangle.fields.y + (-deltaY - 200.0f));
    (*(void (**)(u32, u32))renderState)(6, 1);
    (*(void (**)(u32, u32))renderState)(8, 1);
    RpSkyRenderStateSet(3, 0x71003);
    RpSkyRenderStateSet(2, 0x44);
    PrimDrawRectangle((u8 *)&wipeColor, (u8 *)&rectangle, 0.0f, 0, 200, 200,
                  45.0f, 1.0f, 1.0f);
    sflDataDrawTexturedQuad((s32)(state.x - deltaX), (s32)(state.y - deltaY), 5.0f,
                  state.width, state.height, (u32)state.color >> 8,
                  (s32)((f32)((u32)state.color & 0xFF) * opacity), 1,
                  (s16)(state.width >> 1), (s16)(state.height >> 1),
                  &matrix, texture, uv.coordinates);
}
// Attaches the rank-up resource's indexed matrix when the resource exists; returns 1 on success, 0
// otherwise.
// FUN_00257820
s32 cmmRankUpAttachResMatrix(s32 resourceIndex, void *matrix) {
    s32 model;
    u8 *resource;
    u16 resourceId;

    resourceId = 0x400;
    resource = MT_Scene_GetRes(0x400);
    if (resource == NULL) {
        resourceId = ((resourceIndex & 0x3FF) | 0xC00) & 0xFFFF;
        resource = MT_Scene_GetRes(resourceId);
    }
    if (resource != NULL) {
        model = 0;
        switch ((s32)((resourceId & 0xFFC00) >> 0xA)) {
        case 1:
            model = (s32)((ResrcRecord *)resource)->modelHandle164;
            break;
        case 3:
            model = (s32)((ResrcRecord *)resource)->modelHandle164;
            break;
        }
        if (model != 0) {
            mdlComputeIndexedAttachMatrix(model, 2, matrix);
            return 1;
        }
    }
    return 0;
}


extern u8 *func_003ec3d0(void *raster, s32 lockMode);
extern void *func_003ec2e0(void *raster);
extern s32 H_Cdvd_LookupRequest(s32 pathAddress, s32 *slot);

#pragma push
#pragma always_inline on
#pragma opt_common_subs off
#pragma opt_propagation off
/* Capture a float-backed packed palette value for subsequent byte-channel edits. */
static inline RankUpPackedColor *cmmRankUpCapturePackedColor(RankUpPackedColor *color, const f32 *packed)
{
    color->bits = *packed;
    return color;
}
/* Copy the palette alpha channel without replacing its other color components. measured: retail
 * does a separate alpha load/store; a plain struct assignment drops it. */
static inline void cmmRankUpCopyPaletteAlpha(RankUpColor *output, const RankUpColor *input)
{
    output->a = input->a;
}
/* Draw a centered sprite using keyframe dimensions, packed color and opacity. */
static inline void cmmRankUpDrawSpriteState(const RankUpSpriteState *state, RankUpMatrix *matrix,
                                         s32 texture, f32 uv[4][2], f32 opacity)
{
    s32 height = state->height;
    s32 width = state->width;
    sflDataDrawTexturedQuad((s32)state->x, (s32)state->y, 0.0f, width, height,
                  (u32)state->color >> 8,
                  (s32)((f32)((u32)state->color & 0xFF) * opacity), 0,
                  (s16)(width >> 1), (s16)(height >> 1), matrix, texture, uv);
}
/* Scale only the alpha byte of the packed effect color. measured: retail multiplies in this operand
 * order, and a plain assignment swaps it. */
static inline void cmmRankUpScaleEffectAlpha(RankUpPackedColor *color, f32 amount)
{
    color->channels[3] = (u8)((f32)(u32)color->channels[3] * amount);
}
#pragma pop

typedef union { RankUpSpriteState states[2]; s32 words[18]; } RankUpRenderKeys;
typedef union { f32 coordinates[4][2]; s32 words[8]; } RankUpRenderUV;
/* Rank-up renderer: draws the panel each frame from the task's context and render-state table.
 * Keyframe, UV, position, color and rectangle are kept as whole objects to preserve the original
 * phase calculations. */
// FUN_00257900
/* measured: retail hoists the panel and colour computations out of loops. */
#pragma push
#pragma opt_loop_invariants on
s32 cmmRankUpRender(u8 *task) {
    /* Camera +4 is the provider handle; persona chunk +0x40 is its row id. Both providers expose byte records. */

    CmmRankUpSequence *context;
    u8 *renderStateTable;
    s32 firstTexture;
    s32 secondTexture;
    s32 animationMode;
    s32 mode0Frame;
    s32 exitAnimationMode;
    s32 effectFrame;
    s32 maxExitAnimationMode;
    s32 textElapsed;
    s32 maxTextElapsed;
    s32 wipeStartTask;
    s32 wipeStartEffect;
    s32 wipeEndTask;
    s32 wipeEndEffect;
    s32 exitElapsed;
    s32 maxAttachEffect;
    s32 maxExitElapsed;
    s32 spriteExitTask;
    s32 spriteExitEffect;
    s32 startTask;
    s32 startEffect;
    s32 secondaryTask;
    s32 secondaryEffect;
    s32 midpointTask;
    s32 midpointEffect;
    s32 leavingTask;
    s32 leavingEffect;
    s32 attachedEffect;
    s32 maxStartTask;
    s32 maxStartEffect;
    s32 maxParticleTask;
    s32 maxParticleEffect;
    s32 maxLeavingTask;
    s32 maxLeavingEffect;
    s32 maxAttachedEffect;
    s32 spriteTexture;
    s32 spriteStartTask;
    s32 spriteStartEffect;
    s32 nextPulseFrame;
    s32 firstTextFrame;
    s32 middleTextFrame;
    s32 lastTextFrame;
    s32 firstSkipFrame;
    s32 middleSkipFrame;
    s32 lastSkipFrame;
    s32 firstFadeFrame;
    s32 middleFadeFrame;
    s32 lastFadeFrame;
    s32 firstLineFrame;
    s32 middleLineFrame;
    s32 lastLineFrame;
    s32 nextFrame;
    s32 maxNextPulseFrame;
    s32 mode10Frame;
    s32 maxFirstTextFrame;
    s32 maxMiddleTextFrame;
    s32 maxLastTextFrame;
    s32 maxFirstSkipFrame;
    s32 maxMiddleSkipFrame;
    s32 maxLastSkipFrame;
    s32 maxFirstFadeFrame;
    s32 maxMiddleFadeFrame;
    s32 maxLastFadeFrame;
    s32 maxFirstLineFrame;
    s32 maxMiddleLineFrame;
    s32 maxLastLineFrame;
    s32 maxNextFrame;
    s32 mode11Frame;
    s32 spriteNextFrame;
    s32 mode12Frame;
    s32 wipeNextFrame;
    s32 enteringAlpha;
    s32 leavingAlpha;
    f32 firstTextAlpha;
    f32 middleTextAlpha;
    f32 lastTextAlpha;
    f32 panelExitAlpha;
    f32 textExitAlpha;
    f32 maxFirstTextAlpha;
    f32 maxMiddleTextAlpha;
    f32 maxLastTextAlpha;
    f32 maxPanelExitAlpha;
    f32 maxTextExitAlpha;
    f32 spriteExitAlpha;
    f32 bannerPhase;
    f32 transitionValue;
    f32 leavingShadeAlpha;
    f32 expansion;
    f32 maxExpansion;
    f32 spritePhase;
    f32 leavingOpacity;
    f32 exitOpacity;
    f32 maxExitOpacity;
    f32 firstTextOpacity;
    f32 middleTextOpacity;
    f32 lastTextOpacity;
    f32 maxFirstTextOpacity;
    f32 maxMiddleTextOpacity;
    f32 maxLastTextOpacity;
    s32 resourceSize;
    f32 *drawColor;
    u_long128 *drawRectangle;
    RankUpPackedColor drawColorValue;
    RankUpPackedColor enteringColor;
    RankUpPackedColor steadyColor;
    RankUpPackedColor pulseColor;
    RankUpPackedColor leavingColor;
    RankUpPackedColor overlayColor;
    f32 position[3];
    RankUpRectangle drawRectangleValue;
    RankUpRectangle enteringRectangle;
    RankUpRectangle steadyRectangle;
    RankUpRectangle pulseRectangle;
    RankUpRectangle leavingRectangle;
    RankUpSpriteState enteringSprite;
    RankUpRenderKeys enteringKeys;
    RankUpRenderUV enteringUv;
    RankUpMatrix enteringMatrix;
    RankUpSpriteState steadySprite;
    RankUpRenderKeys steadyKeys;
    RankUpRenderUV steadyUv;
    RankUpMatrix steadyMatrix;
    RankUpSpriteState leavingSprite;
    RankUpRenderKeys leavingKeys;
    RankUpRenderUV leavingUv;
    RankUpMatrix leavingMatrix;
    RankUpRectangle overlayRectangle;

    context = (CmmRankUpSequence *)kwlnTaskGetWork(task);
    firstTexture = (s32)(datPortraitValue(context->portraitIdFirst));
    secondTexture = (s32)(datPortraitValue(context->portraitIdSecond));
    animationMode = (s32)(context->animationMode);
    switch (animationMode) {
    case 0:
        if (context->mode >= 0x96) {
            nextPulseFrame = (s32)(context->frame45 + 1);
            context->frame45 = nextPulseFrame;
            if (nextPulseFrame >= 0x2D) {
                context->frame45 = 0;
            }
        }
        expansion = (f32)context->frame45 / 45.0f;
        if (context->mode == 0) {
            startTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xA5, 300.0f);
            startEffect = cmmScriptTaskGetWorkValue(startTask);
            mdlEffectSetMatrixPose(startEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(startEffect), position);
        }
        if (context->mode == 0) {
            secondaryTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636650, &resourceSize), 0x64, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xB4, 300.0f);
            secondaryEffect = cmmScriptTaskGetWorkValue(secondaryTask);
            mdlEffectSetMatrixPose(secondaryEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(secondaryEffect), position);
        }
        if (context->mode == 0x78) {
            midpointTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636670, &resourceSize), 0x96, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xB4, 300.0f);
            midpointEffect = cmmScriptTaskGetWorkValue(midpointTask);
            mdlEffectSetMatrixPose(midpointEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(midpointEffect), position);
        }
        if (context->mode == 0x23A) {
            leavingTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xA5, 300.0f);
            leavingEffect = cmmScriptTaskGetWorkValue(leavingTask);
            mdlEffectSetMatrixPose(leavingEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(leavingEffect), position);
        }
        if ((context->mode == 0x258) && (cmmRankUpAttachResMatrix(context->unk_20, (u8 *)position) != 0)) {
            attachedEffect = (s32)(cmmScriptTaskGetWorkValue(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636690, &resourceSize), 0x96, &D_005DC974)));
            mdlEffectSetMatrixPose(attachedEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(attachedEffect), position);
        }
        if ((context->mode == 0x280) && (cmmRankUpAttachResMatrix(context->unk_20, (u8 *)position) != 0)) {
            mdlEffectSetChildPositionVec((void *)(cmmScriptTaskGetWorkValue(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_006366B0, &resourceSize), 0x96, &D_005DC974))), position);
        }
        mode0Frame = (s32)(context->mode);
        if (mode0Frame >= 0xA) {
            if (mode0Frame < 0x50) {
                cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * ((f32) (mode0Frame - 0xA) / 70.0f))), 1.0f, 0.0f, firstTexture, secondTexture);
            } else if (mode0Frame < 0x65) {
                cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 1.0f, 0.0f, firstTexture, secondTexture);
            } else if (mode0Frame < 0x79) {
                transitionValue = (f32)(mode0Frame - 0x64) / 20.0f;
                cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF,
                              1.0f - transitionValue, 0.0f, firstTexture, secondTexture);
            } else if (mode0Frame < 0x97) {
                cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, 0.0f, firstTexture, secondTexture);
            } else if (mode0Frame < 0xBF) {
                cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, expansion, firstTexture, secondTexture);
            } else if (mode0Frame < 0x1EB) {
                cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, expansion, firstTexture, secondTexture);
                textElapsed = (s32)(context->mode - 0xBE);
                itfMesWindowSetString(context->pulse120.low, 0, func_002438b0(cmmCommunityArcana(context->slot18.communityId) & 0xFF));
                firstTextFrame = (s32)(context->unk_0c);
                if (firstTextFrame > 0) {
                    context->unk_0c = (s32) (firstTextFrame + 1);
                }
                middleTextFrame = (s32)(context->slot10.counter);
                if (middleTextFrame > 0) {
                    context->slot10.counter = (s32) (middleTextFrame + 1);
                }
                lastTextFrame = (s32)(context->unk_14);
                if (lastTextFrame > 0) {
                    context->unk_14 = (s32) (lastTextFrame + 1);
                }
                if (context->flags & 0x10) {
                    firstSkipFrame = (s32)(context->unk_0c);
                    if (firstSkipFrame == 0) {
                        context->unk_0c = (s32) (firstSkipFrame + 1);
                    }
                    middleSkipFrame = (s32)(context->slot10.counter);
                    if (middleSkipFrame == 0) {
                        context->slot10.counter = (s32) (middleSkipFrame + 1);
                    }
                    lastSkipFrame = (s32)(context->unk_14);
                    if (lastSkipFrame == 0) {
                        context->unk_14 = (s32) (lastSkipFrame + 1);
                    }
                } else {
                    if (textElapsed == 1) {
                        context->unk_0c += 1;
                    } else if (textElapsed == 0x5A) {
                        context->slot10.counter += 1;
                    } else if (textElapsed == 0xB4) {
                        context->unk_14 += 1;
                    }
                }
                {
                f32 middleFade;
                f32 lastFade;
                f32 firstFade;
                firstFade = 0.0f;
                middleFade = 0.0f;
                lastFade = 0.0f;
                firstFadeFrame = (s32)(context->unk_0c);
                if (firstFadeFrame > 0) {
                    firstFade = (f32) firstFadeFrame / 30.0f;
                    if (!(firstFade < 1.0f)) {
                        firstFade = 1.0f;
                    }
                }
                middleFadeFrame = (s32)(context->slot10.counter);
                if (middleFadeFrame > 0) {
                    middleFade = (f32) middleFadeFrame / 30.0f;
                    if (!(middleFade < 1.0f)) {
                        middleFade = 1.0f;
                    }
                }
                lastFadeFrame = (s32)(context->unk_14);
                if (lastFadeFrame > 0) {
                    lastFade = (f32) lastFadeFrame / 30.0f;
                    if (!(lastFade < 1.0f)) {
                        lastFade = 1.0f;
                    }
                }
                if (!(firstFade <= 0.0f)) {
                    cmmRankUpDrawGradientStrip(0.0f, 40.0f, 0.0f, 0, (s32)( (153.0f * firstFade)), (s32)( (153.0f * middleFade)), (s32)( (153.0f * lastFade)), 1, 0, 0, 1.0f, 1.0f);
                }
                }
                firstLineFrame = (s32)(context->unk_0c);
                if (firstLineFrame > 0) {
                    firstTextOpacity = (f32) firstLineFrame / 30.0f;
                    if (!(firstTextOpacity < 1.0f)) {
                        firstTextOpacity = 1.0f;
                    }
                    firstTextAlpha = 255.0f * firstTextOpacity;
                    cmmRankUpDrawCenteredText(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( firstTextAlpha), 0, 0, 0, context->pulse120.low, 0, 0);
                    cmmRankUpDrawCenteredText(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( firstTextAlpha), 0, 0, 0, context->pulse120.low, 0, 1);
                }
                middleLineFrame = (s32)(context->slot10.counter);
                if (middleLineFrame > 0) {
                    middleTextOpacity = (f32) middleLineFrame / 30.0f;
                    if (!(middleTextOpacity < 1.0f)) {
                        middleTextOpacity = 1.0f;
                    }
                    middleTextAlpha = 255.0f * middleTextOpacity;
                    cmmRankUpDrawCenteredText(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( middleTextAlpha), 0, 0, 0, context->pulse120.low, 0, 2);
                    cmmRankUpDrawCenteredText(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( middleTextAlpha), 0, 0, 0, context->pulse120.low, 0, 3);
                    cmmRankUpDrawCenteredText(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( middleTextAlpha), 0, 0, 0, context->pulse120.low, 0, 4);
                }
                lastLineFrame = (s32)(context->unk_14);
                if (lastLineFrame > 0) {
                    lastTextOpacity = (f32) lastLineFrame / 30.0f;
                    if (!(lastTextOpacity < 1.0f)) {
                        lastTextOpacity = 1.0f;
                    }
                    lastTextAlpha = 255.0f * lastTextOpacity;
                    cmmRankUpDrawCenteredText(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( lastTextAlpha), 0, 0, 0, context->pulse120.low, 0, 5);
                    cmmRankUpDrawCenteredText(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( lastTextAlpha), 0, 0, 0, context->pulse120.low, 0, 6);
                }
                if ((D_008C024E[0] & 0x40) && (context->mode < 0x1CC)) {
                    context->mode = 0x1CC;
                    context->flags |= 0x10;
                }
            } else if (mode0Frame < 0x213) {
                cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, expansion, firstTexture, secondTexture);
                cmmRankUpDrawGradientStrip(0.0f, 40.0f, 0.0f, 0, 0x99, 0x99, 0x99, 1, 0, 0, 1.0f, 1.0f);
                itfMesWindowSetString(context->pulse120.low, 0, func_002438b0(cmmCommunityArcana(context->slot18.communityId) & 0xFF));
                cmmRankUpDrawCenteredText(320.0f, 60.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 0, 0);
                cmmRankUpDrawCenteredText(320.0f, 100.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 0, 1);
                cmmRankUpDrawCenteredText(320.0f, 140.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 0, 2);
                cmmRankUpDrawCenteredText(320.0f, 180.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 0, 3);
                cmmRankUpDrawCenteredText(320.0f, 220.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 0, 4);
                cmmRankUpDrawCenteredText(320.0f, 260.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 0, 5);
                cmmRankUpDrawCenteredText(320.0f, 300.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 0, 6);
            } else if (mode0Frame < 0x227) {
                exitOpacity = 1.0f - ((f32) (mode0Frame - 0x212) / 20.0f);
                cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, expansion, firstTexture, secondTexture);
                panelExitAlpha = 153.0f * exitOpacity;
                cmmRankUpDrawGradientStrip(0.0f, 40.0f, 0.0f, 0, (s32)( panelExitAlpha), (s32)( panelExitAlpha), (s32)( panelExitAlpha), 1, 0, 0, 1.0f, 1.0f);
                itfMesWindowSetString(context->pulse120.low, 0, func_002438b0(cmmCommunityArcana(context->slot18.communityId) & 0xFF));
                textExitAlpha = 255.0f * exitOpacity;
                cmmRankUpDrawCenteredText(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( textExitAlpha), 0, 0, 0, context->pulse120.low, 0, 0);
                cmmRankUpDrawCenteredText(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( textExitAlpha), 0, 0, 0, context->pulse120.low, 0, 1);
                cmmRankUpDrawCenteredText(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( textExitAlpha), 0, 0, 0, context->pulse120.low, 0, 2);
                cmmRankUpDrawCenteredText(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( textExitAlpha), 0, 0, 0, context->pulse120.low, 0, 3);
                cmmRankUpDrawCenteredText(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( textExitAlpha), 0, 0, 0, context->pulse120.low, 0, 4);
                cmmRankUpDrawCenteredText(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( textExitAlpha), 0, 0, 0, context->pulse120.low, 0, 5);
                cmmRankUpDrawCenteredText(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( textExitAlpha), 0, 0, 0, context->pulse120.low, 0, 6);
            } else if (mode0Frame < 0x24F) {
                exitElapsed = mode0Frame - 0x226;
                if (exitElapsed == 1) {
                    exitAnimationMode = (s32)(context->animationMode);
                    if ((exitAnimationMode == 0xA) || (exitAnimationMode == 0)) {
                        sdkSndStartChannel(2, &D_00635C80);
                    } else {
                        sdkSndStartChannel(2, &D_00635CA0);
                    }
                }
                cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * (1.0f - ((f32) exitElapsed / 40.0f)))), 0.0f, expansion, firstTexture, secondTexture);
            }
        }
        nextFrame = (s32)(context->mode + 1);
        context->mode = nextFrame;
        if (nextFrame >= 0x2BC) {
            context->unk_44 = 1;
        }
        break;
    case 10:
        if (context->mode >= 0x6E) {
            maxNextPulseFrame = (s32)(context->frame45 + 1);
            context->frame45 = maxNextPulseFrame;
            if (maxNextPulseFrame >= 0x2D) {
                context->frame45 = 0;
            }
        }
        maxExpansion = (f32)context->frame45 / 45.0f;
        if (context->mode == 0) {
            maxStartTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xA5, 300.0f);
            maxStartEffect = cmmScriptTaskGetWorkValue(maxStartTask);
            mdlEffectSetMatrixPose(maxStartEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(maxStartEffect), position);
        }
        if (context->mode == 0xA) {
            sdkSndStartChannel(2, &D_006366D0);
        }
        effectFrame = (s32)(context->mode);
        if (((effectFrame % 10) == 0) && (effectFrame < 0x1CD)) {
            maxParticleTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_006366F0, &resourceSize), 0x32, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xA5, 300.0f);
            maxParticleEffect = cmmScriptTaskGetWorkValue(maxParticleTask);
            mdlEffectSetMatrixPose(maxParticleEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(maxParticleEffect), position);
            mdlEffectGetPackedColor((void *)maxParticleEffect, &drawColorValue.packed);
            cmmRankUpScaleEffectAlpha(&drawColorValue, 0.5f);
            mdlEffectSetPackedColor((void *)maxParticleEffect, &drawColorValue.packed);
        }
        if (context->mode == 0x21C) {
            maxLeavingTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xA5, 300.0f);
            maxLeavingEffect = cmmScriptTaskGetWorkValue(maxLeavingTask);
            mdlEffectSetMatrixPose(maxLeavingEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(maxLeavingEffect), position);
        }
        if ((context->mode == 0x23A) && (cmmRankUpAttachResMatrix(context->unk_20, (u8 *)position) != 0)) {
            maxAttachedEffect = (s32)(cmmScriptTaskGetWorkValue(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636690, &resourceSize), 0x96, &D_005DC974)));
            mdlEffectSetMatrixPose(maxAttachedEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(maxAttachedEffect), position);
        }
        if ((context->mode == 0x262) && (cmmRankUpAttachResMatrix(context->unk_20, (u8 *)position) != 0)) {
            maxAttachEffect = (s32)(cmmScriptTaskGetWorkValue(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_006366B0, &resourceSize), 0x96, &D_005DC974)));
            mdlEffectSetMatrixPose(maxAttachEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(maxAttachEffect), position);
        }
        mode10Frame = (s32)(context->mode);
        if (mode10Frame < 0x50) {
            cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * ((f32) mode10Frame / 80.0f))), 0.0f, 0.0f, firstTexture, secondTexture);
        } else if (mode10Frame < 0x5B) {
            cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, 0.0f, firstTexture, secondTexture);
        } else if (mode10Frame < 0x97) {
            cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, maxExpansion, firstTexture, secondTexture);
        } else if (mode10Frame < 0x1C3) {
            cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, maxExpansion, firstTexture, secondTexture);
            maxTextElapsed = (s32)(context->mode - 0x96);
            itfMesWindowSetString(context->pulse120.low, 0, func_002438b0(cmmCommunityArcana(context->slot18.communityId) & 0xFF));
            itfMesWindowSetString(context->pulse120.low, 1, datPersonaGetRow(((CmmPersonaNameRecord *)(u8 *)cmmPersonaRecord((s32)(s8)cmmCommunityArcana(context->slot18.communityId)))->personaId));
            maxFirstTextFrame = (s32)(context->unk_0c);
            if (maxFirstTextFrame > 0) {
                context->unk_0c = (s32) (maxFirstTextFrame + 1);
            }
            maxMiddleTextFrame = (s32)(context->slot10.counter);
            if (maxMiddleTextFrame > 0) {
                context->slot10.counter = (s32) (maxMiddleTextFrame + 1);
            }
            maxLastTextFrame = (s32)(context->unk_14);
            if (maxLastTextFrame > 0) {
                context->unk_14 = (s32) (maxLastTextFrame + 1);
            }
            if (context->flags & 0x10) {
                maxFirstSkipFrame = (s32)(context->unk_0c);
                if (maxFirstSkipFrame == 0) {
                    context->unk_0c = (s32) (maxFirstSkipFrame + 1);
                }
                maxMiddleSkipFrame = (s32)(context->slot10.counter);
                if (maxMiddleSkipFrame == 0) {
                    context->slot10.counter = (s32) (maxMiddleSkipFrame + 1);
                }
                maxLastSkipFrame = (s32)(context->unk_14);
                if (maxLastSkipFrame == 0) {
                    context->unk_14 = (s32) (maxLastSkipFrame + 1);
                }
            } else {
                if (maxTextElapsed == 1) {
                    context->unk_0c += 1;
                } else if (maxTextElapsed == 0x5A) {
                    context->slot10.counter += 1;
                } else if (maxTextElapsed == 0xB4) {
                    context->unk_14 += 1;
                }
            }
            {
            struct { f32 first; f32 middle; f32 last; } fade;
            fade.first = 0.0f;
            fade.middle = 0.0f;
            fade.last = 0.0f;
            maxFirstFadeFrame = (s32)(context->unk_0c);
            if (maxFirstFadeFrame > 0) {
                fade.first = (f32) maxFirstFadeFrame / 30.0f;
                if (!(fade.first < 1.0f)) {
                    fade.first = 1.0f;
                }
            }
            maxMiddleFadeFrame = (s32)(context->slot10.counter);
            if (maxMiddleFadeFrame > 0) {
                fade.middle = (f32) maxMiddleFadeFrame / 30.0f;
                if (!(fade.middle < 1.0f)) {
                    fade.middle = 1.0f;
                }
            }
            maxLastFadeFrame = (s32)(context->unk_14);
            if (maxLastFadeFrame > 0) {
                fade.last = (f32) maxLastFadeFrame / 30.0f;
                if (!(fade.last < 1.0f)) {
                    fade.last = 1.0f;
                }
            }
            if (!(fade.first <= 0.0f)) {
                cmmRankUpDrawGradientStripPass2(0.0f, 40.0f, 0.0f, 0, (s32)( (153.0f * fade.first)), (s32)( (153.0f * fade.middle)), (s32)( (153.0f * fade.last)), 1, 0, 0, 1.0f, 1.0f);
            }
            }
            maxFirstLineFrame = (s32)(context->unk_0c);
            if (maxFirstLineFrame > 0) {
                maxFirstTextOpacity = (f32) maxFirstLineFrame / 30.0f;
                if (!(maxFirstTextOpacity < 1.0f)) {
                    maxFirstTextOpacity = 1.0f;
                }
                maxFirstTextAlpha = 255.0f * maxFirstTextOpacity;
                cmmRankUpDrawCenteredText(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( maxFirstTextAlpha), 0, 0, 0, context->pulse120.low, 1, 0);
                cmmRankUpDrawCenteredText(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( maxFirstTextAlpha), 0, 0, 0, context->pulse120.low, 1, 1);
                cmmRankUpDrawCenteredText(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( maxFirstTextAlpha), 0, 0, 0, context->pulse120.low, 1, 2);
            }
            maxMiddleLineFrame = (s32)(context->slot10.counter);
            if (maxMiddleLineFrame > 0) {
                maxMiddleTextOpacity = (f32) maxMiddleLineFrame / 30.0f;
                if (!(maxMiddleTextOpacity < 1.0f)) {
                    maxMiddleTextOpacity = 1.0f;
                }
                maxMiddleTextAlpha = 255.0f * maxMiddleTextOpacity;
                cmmRankUpDrawCenteredText(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( maxMiddleTextAlpha), 0, 0, 0, context->pulse120.low, 1, 3);
                cmmRankUpDrawCenteredText(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( maxMiddleTextAlpha), 0, 0, 0, context->pulse120.low, 1, 4);
                cmmRankUpDrawCenteredText(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( maxMiddleTextAlpha), 0, 0, 0, context->pulse120.low, 1, 5);
            }
            maxLastLineFrame = (s32)(context->unk_14);
            if (maxLastLineFrame > 0) {
                maxLastTextOpacity = (f32) maxLastLineFrame / 30.0f;
                if (!(maxLastTextOpacity < 1.0f)) {
                    maxLastTextOpacity = 1.0f;
                }
                maxLastTextAlpha = 255.0f * maxLastTextOpacity;
                cmmRankUpDrawCenteredText(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( maxLastTextAlpha), 0, 0, 0, context->pulse120.low, 1, 6);
                cmmRankUpDrawCenteredText(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( maxLastTextAlpha), 0, 0, 0, context->pulse120.low, 1, 7);
                cmmRankUpDrawCenteredText(320.0f, 340.0f, 0.0f, 0xFFFFFF, (s32)( maxLastTextAlpha), 0, 0, 0, context->pulse120.low, 1, 8);
            }
            if ((D_008C024E[0] & 0x40) && (context->mode < 0x1A4)) {
                context->mode = 0x1A4;
                context->flags |= 0x10;
            }
        } else if (mode10Frame < 0x1F5) {
            cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, maxExpansion, firstTexture, secondTexture);
            cmmRankUpDrawGradientStripPass2(0.0f, 40.0f, 0.0f, 0, 0x99, 0x99, 0x99, 1, 0, 0, 1.0f, 1.0f);
            itfMesWindowSetString(context->pulse120.low, 0, func_002438b0(cmmCommunityArcana(context->slot18.communityId) & 0xFF));
            itfMesWindowSetString(context->pulse120.low, 1, datPersonaGetRow(((CmmPersonaNameRecord *)(u8 *)cmmPersonaRecord((s32)(s8)cmmCommunityArcana(context->slot18.communityId)))->personaId));
            cmmRankUpDrawCenteredText(320.0f, 60.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 1, 0);
            cmmRankUpDrawCenteredText(320.0f, 100.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 1, 1);
            cmmRankUpDrawCenteredText(320.0f, 140.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 1, 2);
            cmmRankUpDrawCenteredText(320.0f, 180.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 1, 3);
            cmmRankUpDrawCenteredText(320.0f, 220.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 1, 4);
            cmmRankUpDrawCenteredText(320.0f, 260.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 1, 5);
            cmmRankUpDrawCenteredText(320.0f, 260.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 1, 6);
            cmmRankUpDrawCenteredText(320.0f, 300.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 1, 7);
            cmmRankUpDrawCenteredText(320.0f, 340.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, context->pulse120.low, 1, 8);
        } else if (mode10Frame < 0x209) {
            maxExitOpacity = 1.0f - ((f32) (mode10Frame - 0x1F4) / 20.0f);
            cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, maxExpansion, firstTexture, secondTexture);
            maxPanelExitAlpha = 153.0f * maxExitOpacity;
            cmmRankUpDrawGradientStripPass2(0.0f, 40.0f, 0.0f, 0, (s32)( maxPanelExitAlpha), (s32)( maxPanelExitAlpha), (s32)( maxPanelExitAlpha), 1, 0, 0, 1.0f, 1.0f);
            itfMesWindowSetString(context->pulse120.low, 0, func_002438b0(cmmCommunityArcana(context->slot18.communityId) & 0xFF));
            itfMesWindowSetString(context->pulse120.low, 1, datPersonaGetRow(((CmmPersonaNameRecord *)(u8 *)cmmPersonaRecord((s32)(s8)cmmCommunityArcana(context->slot18.communityId)))->personaId));
            maxTextExitAlpha = 255.0f * maxExitOpacity;
            cmmRankUpDrawCenteredText(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( maxTextExitAlpha), 0, 0, 0, context->pulse120.low, 1, 0);
            cmmRankUpDrawCenteredText(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( maxTextExitAlpha), 0, 0, 0, context->pulse120.low, 1, 1);
            cmmRankUpDrawCenteredText(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( maxTextExitAlpha), 0, 0, 0, context->pulse120.low, 1, 2);
            cmmRankUpDrawCenteredText(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( maxTextExitAlpha), 0, 0, 0, context->pulse120.low, 1, 3);
            cmmRankUpDrawCenteredText(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( maxTextExitAlpha), 0, 0, 0, context->pulse120.low, 1, 4);
            cmmRankUpDrawCenteredText(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( maxTextExitAlpha), 0, 0, 0, context->pulse120.low, 1, 5);
            cmmRankUpDrawCenteredText(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( maxTextExitAlpha), 0, 0, 0, context->pulse120.low, 1, 6);
            cmmRankUpDrawCenteredText(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( maxTextExitAlpha), 0, 0, 0, context->pulse120.low, 1, 7);
            cmmRankUpDrawCenteredText(320.0f, 340.0f, 0.0f, 0xFFFFFF, (s32)( maxTextExitAlpha), 0, 0, 0, context->pulse120.low, 1, 8);
        } else if (mode10Frame < 0x231) {
            maxExitElapsed = mode10Frame - 0x208;
            if (maxExitElapsed == 1) {
                maxExitAnimationMode = (s32)(context->animationMode);
                if ((maxExitAnimationMode == 0xA) || (maxExitAnimationMode == 0)) {
                    sdkSndStartChannel(2, &D_00635C80);
                } else {
                    sdkSndStartChannel(2, &D_00635CA0);
                }
            }
            cmmRankUpDrawFadedExpansion(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * (1.0f - ((f32) maxExitElapsed / 40.0f)))), 0.0f, maxExpansion, firstTexture, secondTexture);
        }
        maxNextFrame = (s32)(context->mode + 1);
        context->mode = maxNextFrame;
        if (maxNextFrame >= 0x29E) {
            context->unk_44 = 1;
        }
        break;
    case 11:
        spriteTexture = (s32)(*context->unk_54);
        if (context->mode == 0) {
            spriteStartTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xA5, 300.0f);
            spriteStartEffect = cmmScriptTaskGetWorkValue(spriteStartTask);
            mdlEffectSetMatrixPose(spriteStartEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(spriteStartEffect), position);
        }
        if (context->mode == 0xBE) {
            spriteExitTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xA5, 300.0f);
            spriteExitEffect = cmmScriptTaskGetWorkValue(spriteExitTask);
            mdlEffectSetMatrixPose(spriteExitEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(spriteExitEffect), position);
        }
        mode11Frame = (s32)(context->mode);
        if (mode11Frame < 0x50) {
            cmmRankUpDrawFadedExpansionPass2(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * ((f32) mode11Frame / 80.0f))), 0.0f, 0, firstTexture, secondTexture);
        } else if (mode11Frame < 0x65) {
            cmmRankUpDrawFadedExpansionPass2(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, 0, firstTexture, secondTexture);
        } else if (mode11Frame < 0x6F) {
            spritePhase = (f32) (mode11Frame - 0x64) / 10.0f;
            cmmRankUpDrawFadedExpansionPass2(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, spritePhase, 0, firstTexture, secondTexture);
            enteringKeys = *(const RankUpRenderKeys *)D_00636580;
            enteringKeys.states[0].color = 0xFF0000FF;
            enteringKeys.states[1].color = 0xFF0000FF;
            enteringUv = *(const RankUpRenderUV *)D_006365D0;
            cmmRankUpLerpState(&enteringSprite, &enteringKeys.states[0], &enteringKeys.states[1], spritePhase);
            RwMatrixRotate(&enteringMatrix, &enteringSprite.axis, enteringSprite.angle, 0);
            renderStateTable = (u8 *)D_00887300;
            (*(void (**)(u32, u32))renderStateTable)(6, 0);
            (*(void (**)(u32, u32))renderStateTable)(8, 1);
            RpSkyRenderStateSet(3, 0x31003);
            RpSkyRenderStateSet(2, 0x48);
            sflDataDrawTexturedQuad((s32)enteringSprite.x, (s32)enteringSprite.y, 0, enteringSprite.width, enteringSprite.height, (u32)enteringSprite.color >> 8,
                          (s32)( ((f32)((u32)enteringSprite.color & 0xFF) * ((f32)(s32)(255.0f * spritePhase) / 255.0f))), 0,
                          (s16)(enteringSprite.width >> 1), (s16)(enteringSprite.height >> 1), &enteringMatrix,
                          spriteTexture, (f32 (*)[2])((void *)&enteringUv));
        } else if (mode11Frame < 0xAB) {
            cmmRankUpDrawFadedExpansionPass2(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 1.0f, 0, firstTexture, secondTexture);
            steadyKeys = *(const RankUpRenderKeys *)D_00636580;
            steadyKeys.states[0].color = 0xFF0000FF;
            steadyKeys.states[1].color = 0xFF0000FF;
            steadyUv = *(const RankUpRenderUV *)D_006365D0;
            cmmRankUpLerpState(&steadySprite, &steadyKeys.states[0], &steadyKeys.states[1], 1.0f);
            RwMatrixRotate(&steadyMatrix, &steadySprite.axis, steadySprite.angle, 0);
            renderStateTable = (u8 *)D_00887300;
            (*(void (**)(u32, u32))renderStateTable)(6, 0);
            (*(void (**)(u32, u32))renderStateTable)(8, 1);
            RpSkyRenderStateSet(3, 0x31003);
            RpSkyRenderStateSet(2, 0x48);
            cmmRankUpDrawSpriteState(&steadySprite, &steadyMatrix, spriteTexture, steadyUv.coordinates, 1.0f);
        } else if (mode11Frame < 0xD3) {
            spriteExitAlpha = 255.0f * (1.0f - ((f32) (mode11Frame - 0xAA) / 40.0f));
            cmmRankUpDrawFadedExpansionPass2(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( spriteExitAlpha), 1.0f, 0, firstTexture, secondTexture);
            leavingKeys = *(const RankUpRenderKeys *)D_00636580;
            leavingKeys.states[0].color = 0xFF0000FF;
            leavingKeys.states[1].color = 0xFF0000FF;
            leavingUv = *(const RankUpRenderUV *)D_006365D0;
            cmmRankUpLerpState(&leavingSprite, &leavingKeys.states[0], &leavingKeys.states[1], 1.0f);
            RwMatrixRotate(&leavingMatrix, &leavingSprite.axis, leavingSprite.angle, 0);
            renderStateTable = (u8 *)D_00887300;
            (*(void (**)(u32, u32))renderStateTable)(6, 0);
            (*(void (**)(u32, u32))renderStateTable)(8, 1);
            RpSkyRenderStateSet(3, 0x31003);
            RpSkyRenderStateSet(2, 0x48);
            sflDataDrawTexturedQuad((s32)leavingSprite.x, (s32)leavingSprite.y, 0, leavingSprite.width, leavingSprite.height, (u32)leavingSprite.color >> 8,
                          (s32)( ((f32)((u32)leavingSprite.color & 0xFF) * ((f32)(s32)spriteExitAlpha / 255.0f))), 0, (s16)(leavingSprite.width >> 1),
                          (s16)(leavingSprite.height >> 1), &leavingMatrix, spriteTexture,
                          (f32 (*)[2])((void *)&leavingUv));
        }
        spriteNextFrame = (s32)(context->mode + 1);
        context->mode = spriteNextFrame;
        if (spriteNextFrame >= 0xD2) {
            context->unk_44 = 1;
        }
        break;
    case 12:
        if (context->mode == 0) {
            wipeStartTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xA5, 300.0f);
            wipeStartEffect = cmmScriptTaskGetWorkValue(wipeStartTask);
            mdlEffectSetMatrixPose(wipeStartEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(wipeStartEffect), position);
        }
        if (context->mode == 0x9B) {
            wipeEndTask = (s32)(shdEffectTaskCreate((s32)(task), H_Cdvd_LookupRequest((s32)D_00636710, &resourceSize), 0x96, &D_005DC974));
            datScreenPointToWorldPosition((u8 *)position, 0x140, 0xB4, 300.0f);
            wipeEndEffect = cmmScriptTaskGetWorkValue(wipeEndTask);
            mdlEffectSetMatrixPose(wipeEndEffect, func_003e9700((s32)((RwObject *)kwlnGetCamera())->parent));
            mdlEffectSetChildPositionVec((void *)(wipeEndEffect), position);
        }
        mode12Frame = (s32)(context->mode);
        if (mode12Frame < 0x50) {
            cmmRankUpDrawWipeRect(0, 0, 0, 0xFFFFFF, (s32)( (255.0f * ((f32) mode12Frame / 80.0f))), 0.0f, firstTexture);
        } else if (mode12Frame < 0x65) {
            cmmRankUpDrawWipeRect(0, 0, 0, 0xFFFFFF, 0xFF, 0.0f, firstTexture);
        } else if (mode12Frame < 0x8D) {
            f32 shadePhase = (f32)(mode12Frame - 0x64) / 40.0f;
            enteringColor.bits = fGpffffa66c;
            transitionValue = 76.5f * shadePhase;
            enteringAlpha = (u8)transitionValue;
            enteringColor.channels[3] = enteringAlpha;
            drawColor = &drawColorValue.bits;
            drawColorValue = enteringColor;
            *(u_long128 *)&enteringRectangle = D_006365F0;
            drawRectangle = (u_long128 *)&drawRectangleValue;
            *(u_long128 *)&drawRectangleValue = *(u_long128 *)&enteringRectangle;
            PrimDrawFlatRectangle((u8 *)(drawColor), (f32 *)(drawRectangle), 0.0f, 1);
            {
                RankUpColor *palette;
                const RankUpColor *original;
                s32 index;
                f32 amount = shadePhase;
                palette = (RankUpColor *)func_003ec3d0((void *)firstTexture, 1);
                original = (const RankUpColor *)context->unk_58;
                if (palette == NULL) {
                    kAssertFail(&D_00635CF8, 0xA5E);
                }
                for (index = 0; index < 0x100; ++index) {
                    s32 green = palette->g;
                    s32 red = palette->r;
                    s32 maximum = green < red ? red : green;
                    if (maximum < palette->b) {
                        maximum = palette->b;
                    }
                    palette->r = (u8)((f32)(u32)original->r +
                        amount * (f32)(maximum - (s32)original->r));
                    palette->g = (u8)((f32)(u32)original->g +
                        amount * (f32)(maximum - (s32)original->g));
                    palette->b = (u8)((f32)(u32)original->b +
                        amount * (f32)(maximum - (s32)original->b));
                    cmmRankUpCopyPaletteAlpha(palette, palette);
                    palette++;
                    original++;
                }
            }
            func_003ec2e0((void *)firstTexture);
            cmmRankUpDrawWipeRect(0, 0, 0, 0xFFFFFF, 0xFF, 0.0f, firstTexture);
        } else if (mode12Frame < 0xA1) {
            drawColor = &drawColorValue.bits;
            drawColorValue = *cmmRankUpCapturePackedColor(&steadyColor, &fGpffffa670);
            *(u_long128 *)&steadyRectangle = D_00636600;
            drawRectangle = (u_long128 *)&drawRectangleValue;
            *(u_long128 *)&drawRectangleValue = *(u_long128 *)&steadyRectangle;
            PrimDrawFlatRectangle((u8 *)(drawColor), (f32 *)(drawRectangle), 0.0f, 1);
            cmmRankUpDrawWipeRect(0, 0, 0, 0xFFFFFF, 0xFF, 0.0f, firstTexture);
        } else if (mode12Frame < 0xA4) {
            drawColor = &drawColorValue.bits;
            drawColorValue = *cmmRankUpCapturePackedColor(&pulseColor, &fGpffffa674);
            *(u_long128 *)&pulseRectangle = D_00636610;
            drawRectangle = (u_long128 *)&drawRectangleValue;
            *(u_long128 *)&drawRectangleValue = *(u_long128 *)&pulseRectangle;
            PrimDrawFlatRectangle((u8 *)(drawColor), (f32 *)(drawRectangle), 0.0f, 1);
            bannerPhase = (f32) (context->mode - 0xA0) / 3.0f;
            bannerPhase = bannerPhase * bannerPhase;
            cmmRankUpDrawWipeRect(0, 0, 0, 0xFFFFFF, 0xFF, bannerPhase, firstTexture);
        } else if (mode12Frame < 0xC9) {
            leavingOpacity = (f32)(mode12Frame - 0xA3) / 37.0f;
            leavingColor.bits = fGpffffa678;
            leavingOpacity = 1.0f - leavingOpacity;
            leavingShadeAlpha = 76.5f * leavingOpacity;
            leavingAlpha = (u8)leavingShadeAlpha;
            leavingColor.channels[3] = leavingAlpha;
            drawColor = &drawColorValue.bits;
            drawColorValue = leavingColor;
            *(u_long128 *)&leavingRectangle = D_00636620;
            drawRectangle = (u_long128 *)&drawRectangleValue;
            *(u_long128 *)&drawRectangleValue = *(u_long128 *)&leavingRectangle;
            PrimDrawFlatRectangle((u8 *)(drawColor), (f32 *)(drawRectangle), 0.0f, 1);
            cmmRankUpDrawWipeRect(0, 0, 0, 0xFFFFFF, (s32)( (255.0f * leavingOpacity)), 1.0f, firstTexture);
        }
        wipeNextFrame = (s32)(context->mode + 1);
        context->mode = wipeNextFrame;
        if (wipeNextFrame >= 0xF0) {
            context->mode = 0x64;
            context->unk_44 = 1;
        }
        break;
    }
    {
    RankUpPackedColor zeroColor = {{0, 0, 0, 0}};
    overlayColor.bits = zeroColor.bits;
    {
    RankUpRectangle overlayTemplate = {{0, 0, 0, 0}};
    overlayTemplate.fields.x = 0;
    overlayTemplate.fields.y = 0;
    overlayTemplate.fields.width = 0x280;
    overlayTemplate.fields.height = 0x1C0;
    *(u_long128 *)&overlayRectangle = *(u_long128 *)&overlayTemplate;
    renderStateTable = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderStateTable)(0xE, 0);
    (*(void (**)(u32, u32))renderStateTable)(0xC, 1);
    (*(void (**)(u32, u32))renderStateTable)(7, 2);
    (*(void (**)(u32, u32))renderStateTable)(9, 1);
    (*(void (**)(u32, u32))renderStateTable)(0x14, 1);
    (*(void (**)(u32, u32))renderStateTable)(6, 0);
    (*(void (**)(u32, u32))renderStateTable)(8, 1);
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x44);
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle((u8 *)(&overlayColor), (f32 *)(&overlayRectangle), (f32) 0xFFFF, 0);
    mdlEffectEmitTagPair();
    }
    }
    return 0;
}
#pragma pop

/* measured: opt_propagation off keeps the two argument addresses where retail takes them, before
 * the fbuf store and between the two quad stores. Builds the sprite arguments in a local buffer
 * from the work record and draws them. */
// FUN_0025B0F0
#pragma push
#pragma opt_propagation off
void cmmRankUpDrawSprite(s32 unused, u8 *task) {
    extern u32 *kwlnTaskGetWork();
    CmmRankUpSequence *work;
    u8 *colorByte;
    s32 remainingBytes;
    f32 packedColor;
    u8 rgba[4];
    u8 rectangles[32];
    u_long128 quad;
    u_long128 *drawRectangle;
    f32 *drawColor;
    f32 alpha;

    work = (CmmRankUpSequence *)kwlnTaskGetWork(task);
    colorByte = rgba;
    remainingBytes = 4;
    if (colorByte != NULL) {
        do {
            *colorByte = 0;
            colorByte++;
        } while (--remainingBytes != 0);
    }
    alpha = (f32)work->fadeFrame * 127.5f / 40.0f;
    rgba[3] = (u8)alpha;
    drawColor = &packedColor;
    packedColor = *(f32 *)rgba;
    quad = D_00636730;
    *(u_long128 *)&rectangles[0] = quad;
    drawRectangle = (u_long128 *)&rectangles[16];
    *(u_long128 *)&rectangles[16] = quad;
    PrimDrawFlatRectangle((u8 *)(drawColor), (f32 *)(drawRectangle), 0.0f, 1);
    switch ((u32)work->relation) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;
    case 9:
    case 10:
        cmmRankUpRender(task);
        break;
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    }
}
#pragma pop
extern u8 D_00636740[];
extern u8 D_00636760[];
extern u8 D_00636780[];
extern u8 D_006367A0[];
extern u8 D_00635D08[];
extern u8 D_005DC974[];
extern s32 iGpffffa664;
extern s32 iGpffffa668;
extern f32 fGpffff82a4;
extern u8 *iGpffffb448;
extern char cGpffffa680;
extern char cGpffffa688;
extern u8 *datPortraitTaskCreate(s32 parentAddress, s64 portraitId, s32 flags);
extern void func_00440b68();
extern u8 *H_Cdvd_AcquireDirectory();
extern s32 H_Cdvd_IsFileLoaded();
extern u8 *filerEnqueueRequest(s32 kind, const char *name, const char *path, s32 flags, s32 source, s32 buffer, s32 byteCount, const char *cacheName, s32 resultKind, s32 memoryKind);
extern void *memcpy(void *destination, const void *source, u32 size);
extern void *memset(void *destination, s32 value, u32 size);
extern u8 *filerTakeCompletedRequest(u8 *request, s32 *completed, s32 *resultValue);
extern s32 hsndGetCurrentCue();
extern s32 hsndGetCurrentTrack();
extern s32 sdkSndFadeMainChannel();
extern void sdkSndFadeOutChannelFrames();
extern void shdEffectSetRenderParams(u8 *effect, s32 parameter, u8 flags);
extern void shdEffectFillFbufParams(u8 *dst, u8 flags, u32 firstColor, u32 secondColor, u32 thirdColor, u32 fourthColor, f32 firstValue, f32 secondValue);
extern void shdEffectSetFargParams(u8 *dst, s32 firstValue, s32 secondValue, f32 firstFloat, f32 secondFloat);
extern s32 shdEffectCreateBlurTask(s32 parentTask, s32 filterKind, s32 filterHandle, u8 *effect, void *renderContext);
extern u8 *cmmRankUpFindResEntry();
extern void cmmRankUpPlayRankSound();
extern s32 FldPanel2dRelease();
extern void kwlnTaskDestroyWithHierarchy();
extern s32 kwlnTaskGetTaskByName();
extern s32 itfMesWindowInstall();
extern void itfMesWindowReleaseIfActive();
extern s32 nmMesWindowSlotStatus();
extern void nmMesWindowRestartSlot();
extern void nmMesWindowDestroySlot();
extern void nmMesWindowStepSlotRelease(s32);
extern s8 nmMesWindowAcquire();
extern s32 nmMesWindowShowSlotRecord(s8 slotIndex, s32 recordIndex);
extern void nmMesWindowShowSlotRecordStyle1();
extern s32 cmmRankUpSelectDisplayIndex();
extern s64 cmmCommunityArcana(s32 communityId);
extern u8 *func_002438b0();
extern u8 *cmmNameRecord(u32);
extern u8 *cmmTextRecord();
extern u8 *cmmPersonaRecord();
extern char *strcpy(char *destination, const char *source);
extern void frFontExCopyString(char *src, char *dst, s32 maxlen);
extern void nmMesWindowSetSlotString(s8 slotIndex, s32 variable, void *text);
extern s32 datGetFlag();
extern void datSetFlag();
extern void hsndQueueSound();
extern void sdkSndSetMainChannelData();
extern void sdkSndStopMainChannel();
extern void sdkSndStopChannel();
extern void sdkSndFadeOutChannel();
extern void sdkSndRequestTrack();
extern s32 cmmRankUpCardTaskUpdate(u8 *sdkTaskBytes);
extern void cmmRankUpCardTaskDestroy(u8 *task);
extern void PrimAppendNode();
extern u8 *PrimAllocQueueNode();
typedef struct { s32 values[5]; } RankUpUnlockFlags;

#pragma push
#pragma always_inline on
#pragma opt_common_subs off
#pragma opt_propagation off
/* Report whether the rank-up task work has set its completion flag. */
static inline s32 cmmRankUpAnimationComplete(u8 *task)
{
    CmmRankUpSequence *context = (CmmRankUpSequence *)kwlnTaskGetWork(task);
    s32 complete = 0;
    if (context->unk_44 != 0) {
        complete = 1;
    }
    return complete;
}
#pragma pop

// Steps the rank-up CDVD load: creates the portrait tasks, acquires the directory, then waits for
// the load.
// FUN_0025B240
s32 cmmRankUpSequenceUpdate(u8 *task) {
    /* Persona chunk records expose the row id at +0x40; the rest is inline text. */
    CmmRankUpSequence *context;
    s32 fadeFrame;
    s32 value;
    s32 frameOrCommunity;
    s32 rankOrFlags;
    s32 fileSize;
    s32 loadComplete;
    char text[0x20];
    u8 blurParams[0xD8];
    RankUpUnlockFlags unlockFlags;
    s32 skill;
    s8 displayIndex;
    s8 completedRankValue;
    u8 *node;
    void *cardWork;
    s32 count;
    u8 *taskBytes = task;
    context = (CmmRankUpSequence *)kwlnTaskGetWork(taskBytes);
    skill = 0;
    switch (context->relation) {
    case 0:
        context->relation = 3;
        context->portraitIdFirst = (s32)datPortraitTaskCreate((s32)taskBytes, cmmCommunityArcana(context->slot18.communityId), 0);
        context->portraitIdSecond = (s32)datPortraitTaskCreate((s32)taskBytes, -1, 0);
        func_00440b68(&cGpffffa680, D_00635CF8, 0xADB);
        context->directory = H_Cdvd_AcquireDirectory(D_00636760, 1);
        goto tail;
    case 1:
        context->relation = 2;
        if (context->animationMode < 1 || context->animationMode > 9) {
            sdkSndStopChannel(10);
        }
        /* fallthrough */
    case 2:
        if ((context->flags & 8) != 0) {
            goto tail;
        }
        if (iGpffffa664 != -1) {
            hsndQueueSound((s16)iGpffffa664, 10);
            sdkSndSetMainChannelData(-0x3C);
        } else {
            sdkSndStopMainChannel();
        }
        if (iGpffffa668 != -1) {
            sdkSndRequestTrack(iGpffffa668);
        } else {
            sdkSndFadeOutChannel(3, 0);
        }
        return -1;
    case 3:
        if (datPortraitIsLoaded(context->portraitIdFirst) == 0) {
            goto tail;
        }
        if (datPortraitIsLoaded(context->portraitIdSecond) == 0) {
            goto tail;
        }
        if (H_Cdvd_IsFileLoaded(context->directory) == 0) {
            goto tail;
        }
        context->relation = 4;
        context->messageData = H_Cdvd_LookupRequest((s32)D_00636780, &fileSize);
        context->loadRequest = filerEnqueueRequest(0, (const char *)D_006367A0, 0, 0, 0, 0, 0, 0, 0, 0);
        {
        u8 *palette;
        s32 raster;
        u8 *paletteCopy;
        raster = datPortraitValue(context->portraitIdFirst);
        palette = func_003ec3d0((void *)raster, 1);
        if (palette == 0) {
            kAssertFail(D_00635CF8, 0xAF7);
        }
        chkmemAllocSiteTag(D_00635CF8, 0xAF8);
        paletteCopy = D_008873F4[0](1, 0x400, 0x40000);
        context->unk_58 = paletteCopy;
        memcpy(paletteCopy, palette, 0x400);
        func_003ec2e0((void *)raster);
        }
        goto tail;
    case 4:
        context->unk_54 = (s32 *)filerTakeCompletedRequest(context->loadRequest, &loadComplete, 0);
        if (loadComplete == 0) {
            goto tail;
        }
        context->relation = 5;
        context->loadRequest = NULL;
        goto tail;
    case 5:
        iGpffffa664 = hsndGetCurrentCue();
        iGpffffa668 = hsndGetCurrentTrack();
        sdkSndFadeMainChannel();
        sdkSndFadeOutChannelFrames(3, 0, 10);
        context->relation = 6;
        context->mode = 0;
        memset(blurParams, 0, 0xD8);
        shdEffectSetRenderParams(blurParams, 0x35, 0);
        shdEffectFillFbufParams(blurParams, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0, 0, 0.0f, 0.0f);
        shdEffectSetFargParams(blurParams, 0xFF, 0, fGpffff82a4, 0.25f);
        context->blurTask = shdEffectCreateBlurTask((s32)taskBytes, 1, 0, blurParams, D_005DC974);
        context->unk_40 = (s32)cmmRankUpFindResEntry();
        cmmRankUpPlayRankSound(context->animationMode);
    case 6:
        frameOrCommunity = context->mode + 1;
        context->mode = frameOrCommunity;
        if (frameOrCommunity == 5 && FldPanel2dRelease() != 0) {
            context->flags |= 1;
        }
        if (context->mode < 0x35) {
            goto tail;
        }
        kwlnTaskDestroyWithHierarchy(context->blurTask);
        if (context->animationMode >= 1 && context->animationMode <= 10) {
            context->relation = 7;
        } else {
            context->relation = 9;
        }
        context->mode = 0;
        goto tail;
    case 7:
        context->relation = 8;
        rankOrFlags = context->animationMode;
        frameOrCommunity = context->slot18.word;
        if (frameOrCommunity == 0) {
            kAssertFail(D_00635CF8, 0x25D);
        }
        chkmemAllocSiteTag(D_00635CF8, 0x25E);
        cardWork = D_008873F4[0](1, 0x40, 0x40000);
        ((CmmRankUpCardTask *)cardWork)->relation = frameOrCommunity;
        ((CmmRankUpCardTask *)cardWork)->mode = rankOrFlags;
        context->cardTask = (s32)kwlnTaskCreateChild((void *)(taskBytes), (const void *)(D_00635D08), 0xF, 0, 0, cmmRankUpCardTaskUpdate, cmmRankUpCardTaskDestroy, (u8 *)(cardWork));
    case 8:
        if (kwlnTaskGetTaskByName(D_00635D08) != 0) {
            goto tail;
        }
        if (context->animationMode == 0 || context->animationMode == 10) {
            context->relation = 9;
        } else {
            context->relation = 0xB;
        }
        context->mode = 0;
        goto tail;
    case 9:
        context->relation = 10;
        context->pulse120.low = (s8)itfMesWindowInstall(context->messageData);
        context->unk_44 = 0;
        context->flags |= 2;
        rankOrFlags = context->animationMode;
        sdkSndFadeOutChannelFrames(3, 0, 10);
        if (rankOrFlags >= 1 && rankOrFlags <= 9) {
            goto case10tail;
        }
        if (rankOrFlags == 10) {
            hsndQueueSound(0xF, 10);
        } else {
            hsndQueueSound(0xE, 10);
        }
        /* fallthrough */
    case 10:
    case10tail:
        if (cmmRankUpAnimationComplete(taskBytes) == 0) {
            goto tail;
        }
        context->relation = 0xB;
        itfMesWindowReleaseIfActive(context->pulse120.low);
        context->mode = 0;
        goto tail;
    case 11:
        context->relation = 0xC;
    case 12:
        context->relation = 0xD;
        context->mode = 0;
        goto tail;
    case 13:
        context->relation = 0xE;
        context->pulse120.low = nmMesWindowAcquire((void *)context->messageData);
        rankOrFlags = context->animationMode;
        if (rankOrFlags == 0) {
            nmMesWindowSetSlotString(context->pulse120.low, 0, (char *)func_002438b0((u8)cmmCommunityArcana(context->slot18.communityId)));
            if (context->slot18.word == 7) {
                nmMesWindowShowSlotRecord(context->pulse120.low, 0xC);
            } else {
                nmMesWindowShowSlotRecord(context->pulse120.low, 2);
            }
        } else if (rankOrFlags == 10) {
            frFontExCopyString((char *)cmmNameRecord(context->slot18.communityId), (char *)text, 0x20);
            nmMesWindowSetSlotString(context->pulse120.low, 0, text);
            nmMesWindowSetSlotString(context->pulse120.low, 1, (char *)func_002438b0((u8)cmmCommunityArcana(context->slot18.communityId)));
            frFontExCopyString((char *)cmmPersonaRecord((s8)cmmCommunityArcana(context->slot18.communityId)), (char *)text, 0x20);
            nmMesWindowSetSlotString(context->pulse120.low, 2, text);
            strcpy((char *)text, (char *)datPersonaGetRow(((CmmPersonaNameRecord *)cmmPersonaRecord((s8)cmmCommunityArcana(context->slot18.communityId)))->personaId));
            nmMesWindowSetSlotString(context->pulse120.low, 3, text);
            nmMesWindowShowSlotRecord(context->pulse120.low, 4);
        } else if (rankOrFlags == 11) {
            nmMesWindowShowSlotRecord(context->pulse120.low, 5);
        } else if (rankOrFlags == 12) {
            nmMesWindowShowSlotRecord(context->pulse120.low, 6);
        } else {
            if (iGpffffa664 != -1) {
                hsndQueueSound((s16)iGpffffa664, 10);
                sdkSndSetMainChannelData(-0xB4);
            } else {
                sdkSndStopMainChannel();
            }
            if (iGpffffa668 != -1) {
                sdkSndRequestTrack(iGpffffa668);
            } else {
                sdkSndFadeOutChannel(3, 0);
            }
            frFontExCopyString((char *)cmmNameRecord(context->slot18.communityId), (char *)text, 0x20);
            nmMesWindowSetSlotString(context->pulse120.low, 0, text);
            sprintf(text, &cGpffffa688, context->animationMode);
            nmMesWindowSetSlotString(context->pulse120.low, 1, text);
            nmMesWindowSetSlotString(context->pulse120.low, 2, (char *)func_002438b0((u8)cmmCommunityArcana(context->slot18.communityId)));
            nmMesWindowShowSlotRecord(context->pulse120.low, 3);
        }
    case 14:
        if (nmMesWindowSlotStatus(context->pulse120.low) == 0) {
            s8 completedRank;
            nmMesWindowRestartSlot(context->pulse120.low);
            rankOrFlags = context->animationMode;
            completedRank = (s8)rankOrFlags;
            if (completedRank == 0) {
                completedRank = 1;
            }
            if (rankOrFlags != 0xB && rankOrFlags != 0xC && cmmRankUpSelectDisplayIndex(context->slot18.word, completedRank) != 0) {
                context->relation = 0xF;
            } else {
                nmMesWindowDestroySlot(context->pulse120.low);
                context->relation = 1;
                context->flags |= 4;
            }
        }
        nmMesWindowStepSlotRelease(context->pulse120.low);
        goto tail;
    case 15:
        context->relation = 0x10;
        completedRankValue = *(s8 *)&context->animationMode;
        if (completedRankValue == 0) {
            completedRankValue = 1;
        }
        unlockFlags = *(const RankUpUnlockFlags *)D_00636740;
        displayIndex = (s8)cmmRankUpSelectDisplayIndex(context->slot18.word, completedRankValue);
        if (displayIndex >= 2 && displayIndex <= 6 && (context->flags & 0x20) != 0) {
            datSetFlag(unlockFlags.values[displayIndex - 2], 1);
            switch (displayIndex) {
            case 2:
                nmMesWindowShowSlotRecordStyle1(context->pulse120.low, 0xD);
                break;
            case 3:
                nmMesWindowShowSlotRecordStyle1(context->pulse120.low, 0xE);
                break;
            case 4:
                nmMesWindowShowSlotRecordStyle1(context->pulse120.low, 0xF);
                break;
            case 5:
                nmMesWindowShowSlotRecordStyle1(context->pulse120.low, 0x10);
                break;
            case 6:
                nmMesWindowShowSlotRecordStyle1(context->pulse120.low, 0x11);
                break;
            }
            context->flags &= ~0x20;
            goto case16tail;
        }
        if (displayIndex >= 2 && displayIndex < 7 && datGetFlag(unlockFlags.values[displayIndex - 2]) == 0) {
            context->flags |= 0x20;
        }
        frFontExCopyString((char *)cmmTextRecord(context->slot18.communityId), (char *)text, 0x20);
        nmMesWindowSetSlotString(context->pulse120.low, 0, text);
        switch (displayIndex) {
        case 2:
            nmMesWindowShowSlotRecord(context->pulse120.low, 7);
            break;
        case 3:
            nmMesWindowShowSlotRecord(context->pulse120.low, 8);
            break;
        case 4:
            nmMesWindowShowSlotRecord(context->pulse120.low, 9);
            break;
        case 5:
            nmMesWindowShowSlotRecord(context->pulse120.low, 10);
            break;
        case 6:
            nmMesWindowShowSlotRecord(context->pulse120.low, 11);
            break;
        case 7:
            skill = 0x113;
            nmMesWindowSetSlotString(context->pulse120.low, 1, (void *)(iGpffffb448 + 0x1469));
            nmMesWindowShowSlotRecord(context->pulse120.low, 0x12);
            datPersonaAddSkill((u8 *)datPersonaGetRecord(5), 0x113);
            break;
        case 8:
            skill = 0x112;
            nmMesWindowSetSlotString(context->pulse120.low, 1, (void *)(iGpffffb448 + 0x1456));
            nmMesWindowShowSlotRecord(context->pulse120.low, 0x13);
            datPersonaAddSkill((u8 *)datPersonaGetRecord(5), 0x112);
            break;
        case 9:
            skill = 0x10D;
            nmMesWindowSetSlotString(context->pulse120.low, 1, (void *)(iGpffffb448 + 0x13F7));
            datPersonaAddSkill((u8 *)datPersonaGetRecord(5), 0x10D);
            break;
        }
        if (skill == 0x113) {
            datSetFlag(0x1013, 1);
        }
        if (skill == 0x112) {
            datSetFlag(0x1012, 1);
        }
        /* fallthrough */
    case 16:
    case16tail:
        if (nmMesWindowSlotStatus(context->pulse120.low) == 0) {
            nmMesWindowRestartSlot(context->pulse120.low);
            if ((context->flags & 0x20) != 0) {
                context->relation = 0xF;
            } else {
                nmMesWindowDestroySlot(context->pulse120.low);
                context->relation = 1;
                context->flags |= 4;
            }
        }
        nmMesWindowStepSlotRelease(context->pulse120.low);
        goto tail;
    default:
        goto tail;
    }
tail:
    rankOrFlags = context->flags;
    if ((rankOrFlags & 8) != 0) {
        if ((rankOrFlags & 4) != 0) {
            fadeFrame = context->fadeFrame - 1;
            context->fadeFrame = fadeFrame;
            if (fadeFrame <= 0) {
                context->flags &= ~4;
                context->flags &= ~8;
            }
        }
    } else if ((rankOrFlags & 2) != 0) {
        fadeFrame = context->fadeFrame + 1;
        context->fadeFrame = fadeFrame;
        if (fadeFrame >= 0x28) {
            context->flags &= ~2;
            context->flags |= 8;
        }
    }
    node = PrimAllocQueueNode();
    ((BtlRenderNode *)node)->callback = (void *)cmmRankUpDrawSprite;
    ((BtlRenderNode *)node)->work = taskBytes;
    PrimAppendNode(D_007963D0, node);
    return 0;
}


/* Releases a CDVD load task: disables and clears the scene resources in its list, frees the list
 * and work blocks, and destroys the CDVD handle. */
// FUN_0025C100
void cmmRankUpSequenceDestroy(u8 *unusedTask) {
    void (**freeWork)(void *);
    CmmRankUpSequence *context;
    u8 *list;
    s32 i;

    context = (CmmRankUpSequence *)kwlnTaskGetWork();
    if (context->flags & 1) {
        FldPanel2dTaskCreate();
    }
    list = (u8 *)context->unk_40;
    i = 0;
    while ((s32)((RankUpResourceState *)list)[i].resource != 0) {
        if (((RankUpResourceState *)list)[i].enabled == 0) {
            MT_Scene_SetResEnabled((s32)((RankUpResourceState *)list)[i].resource, 0);
        }
        mdlSetLayerWeight(((RankUpResourceState *)list)[i].model, 0, ((RankUpResourceState *)list)[i].weight);
        i++;
    }
    freeWork = (void (**)(void *))DAT_008873ec_abs;
    (*freeWork)(list);
    if ((u32)context->loadRequest != 0) {
        kAssertFail(&D_00635CF8, 0xC2F);
    }
    if (context->unk_58 != NULL) {
        (*freeWork)(context->unk_58);
    }
    if ((u32)context->unk_54 != 0) {
        func_003ef3a0((u32)context->unk_54);
    }
    H_Cdvd_Destroy((u32)context->directory);
    (*freeWork)(context);
}
// Spawns the rank-up sequence task under value for resource option1 (must be nonzero), storing option2 and option3 as its load parameters; the task is destroyed by cmmRankUpSequenceDestroy.
// FUN_0025C230
void cmmRankUpSequenceStart(s32 parentTask, s32 communityId, s32 rank, s32 resourceId) {
    CmmRankUpSequence *work;

    if (communityId == 0) {
        kAssertFail(D_00635CF8, 0xC40);
    }
    chkmemAllocSiteTag(D_00635CF8, 0xC41);
    work = (CmmRankUpSequence *)D_008873F4[0](1, 0x5C, 0x40000);
    work->slot18.word = communityId;
    work->animationMode = rank;
    work->unk_20 = resourceId;
    work->relation = 0;
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_006367C0), 0xF, 0, 0, cmmRankUpSequenceUpdate, cmmRankUpSequenceDestroy, (u8 *)(work));
}
