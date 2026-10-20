/* Original translation unit y_CmbCardEff.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "fcl_color.h"
#include "type.h"
#include "sdktask.h"
#include "h_cdvd_internal.h"
#include "effect_update_internal.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "fcl_draw_task.h"
#include "cmb_card_eff.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(void *);
typedef FclVec3 CmbVec3f;
typedef FclVec2 CmbVec2f;
typedef FclDrawColor CmbRGBA;

static inline u8 *cmbAddPtrRev(u32 base, u32 index) { return (u8 *)(index + base); }

void chkmemAllocSiteTag(void *file, u32 line);

struct HCdvd;
s32 func_00440b68(const char *format, ...);
u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
s32 cmbCardEffSpriteTaskUpdate(u8 *task);
s32 cmbFiveSpriteTask(u8 *task);
u32 H_Cdvd_IsFileLoaded(struct HCdvd *cdvd);
void mdlEffectDestroy(u8 *model);
u32 H_Cdvd_Destroy(struct HCdvd *cdvd);
void pscResTeardown(void *unusedTask);
void pscResInitScene(u8 *work, s32 resetCamera);
void pscResBuildMiscCardW00(u8 *container);
s32 pscResIsIdle(void);
void btlShuffleCardSetupLayout(u8 *card, s32 personaId);
s32 cmbCardEffRenderTask(u8 *task);
u8 *cmbCardEffTaskCreate(u8 *parent, s32 *texture);
void *cmbCardEffState(u8 *task);
void cmbCardEffSetParams(u8 *task, u8 startAlpha, u8 endAlpha, u16 duration);
void cmbCardEffSetPosition(u8 *task, CmbVec2f startPosition, CmbVec2f endPosition, u16 duration);
void cmbCardEffSetTween(u8 *task, CmbVec3f position, f32 rotationX, f32 rotationY, f32 rotationZ, f32 scale, CmbRGBA color, u16 duration, u32 lifetime, CmbVec3f clonePosition, f32 cloneRotationX, f32 cloneRotationY, f32 cloneRotationZ, f32 cloneScale, CmbRGBA cloneColor);
s32 *fclCombineGetCardTable(void);
void RpSkyRenderStateSet(u32 state, u32 value);
struct RtQuat;
struct RwV3d;
struct RtQuat *func_003dc740(struct RtQuat *rotation, const struct RwV3d *axis,
                           f32 angle, s32 mode);
void btlShuffleCardBindPacket(u8 *card, void *rotation);
void btlShuffleCardApplyScale(u8 *unit, f32 *src, f32 scale);
s32 evtGetEventFrame(void);
f32 fclEaseInterpolate(s64, f32, f32, f32, f32);
s32 fclAddClamped(s32, s32, s32, s32, s8);
s32 kwlnGetCamera(void);
u8 *PrimQueueDrawPrimitive(void *inputList, s32 primitive, void *vertices, s32 count);
extern f32 iGpffff8360;
extern f32 iGpffff8508;
extern f32 iGpffff850c;
extern f32 D_008872F8[];
extern u8 D_00794F00[];
u32 datGetFlag(s32 bit);
void datSetFlag(s32, s32);
s32 sdkSndStartChannel(s16 channelIndex, u8 *path);
s32 kwlnTaskIsLinked(void *target);
extern u8 D_0064A5B0[];
s32 fclSubClamped(s32, s32, s32, s32, s8);
u8 *mdlEffectCreateFromResource(s32);
u8 *mdlEffectClone(u8 *);

void mdlEffectFlushWithTable(void *, void *);
void mdlEffectSetChildPositionVec(void *, u8 *);
void mdlEffectSetEulerRotation(u8 *, f32, f32, f32);
void mdlEffectSetUniformScale(u8 *, f32);
void mdlEffectSetPackedColor(void *, u8 *);
s32 mdlEffectIsFinished(u8 *);
extern u8 D_005DC7D0[];



void fclSpriteSetOrder(u8 *, u32);
void fclSpriteSetBaseScale(u8 *, f32);



extern u8 D_0064E590[];
extern u8 D_0064A4A0[];
extern u8 D_0064A5E8[];
extern u8 D_0064A600[];
extern u8 D_0064A5D0[];
extern u8 D_0064A4E0[];
extern u8 D_0064A4B0[];
extern u8 D_0064A500[];
extern u8 D_0064A520[];
extern u8 D_0064A540[];
extern u8 D_0064A560[];
extern u8 D_0064A580[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
s32 cmbCardPathUpdate(u8 *task);
s32 cmbCardLoaderStep(u8 *task);
u8 *cmbCardEffCreateSprite(u8 *parent, u8 *directory, s8 drawOrder);
/* Retail's six-byte "%s %d" diagnostic format, addressed at GP - 0x56C8. */
extern char D_00763A28[6];
extern s64 D_0064A5A0[];
extern f32 D_0064A5A8[];
extern void (*D_00887300[])(s32, s32);



typedef struct { u8 data[0xFB0]; } CmbLoaderCard;
typedef struct {
    s8 state;
    u8 reserved01;
    u16 ids[12];
    u8 reserved1a[2];
    u8 *file;
    u8 environment[0x2738];
    CmbLoaderCard cards[2][12];
    s8 loaded;
    u8 reserved_end[3];
} CmbLoaderState;
typedef char CmbLoaderSizeCheck[sizeof(CmbLoaderState) == 0x19FDC ? 1 : -1];

typedef struct {
    CmbVec2f position;
    s16 duration;
    u8 reserved[2];
} CmbCardPathPoint;
typedef struct {
    s8 flags; /* 1: move, 2: angle, 4: color, 8: queued waypoints */
    u8 reserved01[3];
    CmbVec2f moveStart, moveEnd, position;
    s16 moveDuration, moveFrame;
    CmbCardPathPoint path[5];
    s8 pathCount, pathIndex;
    u8 reserved5e[2];
    f32 angleStart, angleEnd, angle;
    s16 angleFrame, angleDuration;
    CmbRGBA colorStart, colorEnd, color;
    s16 colorFrame, colorDuration;
    f32 scale;
} CmbCardSlot;
typedef char CmbCardSlotSizeCheck[sizeof(CmbCardSlot) == 0x84 ? 1 : -1];
/* Controller allocation is 0x6E0 bytes; unnamed tail bytes remain opaque. */
typedef struct {
    s8 phase;
    u8 reserved01[3];
    u8 *loaderTask;
    u8 reserved08[4];
    CmbCardSlot cards[12];
    s16 layout;
    s8 nextPhase;
    u8 reserved63f;
    u8 reserved640[0xC];
    u8 *loadGate;
    u8 reserved650[8];
    union { u8 *task; u32 bits; s32 value; } effectTasks[12];
    u8 reserved688[0x30];
    s8 hideSecondary, activeCount;
    u8 reserved6ba[2];
    s16 pulseFrame;
    u8 reserved6be[0x22];
} CmbCardController;
typedef char CmbCardControllerSizeCheck[sizeof(CmbCardController) == 0x6E0 ? 1 : -1];

/* PrimQueueDrawPrimitive uses four 0x40-byte vertices per quad. UVs are
 * written as IEEE-754 words (0 or 0x3F800000) before submission. */
typedef struct {
    f32 x, y, z;
    u8 pad0C[4];
    s32 uBits, vBits;
    f32 reciprocalDepth;
    u8 pad1C[4];
    f32 red, green, blue, alpha;
    u8 pad30[0x10];
} CmbCardVertex;
typedef struct {
    u8 pad00[8];
    void *draw;
    u8 pad0C[4];
    u8 *work;
} CmbCardDrawPacket;
typedef struct {
    u8 pad00[0x80];
    f32 depth;
} CmbCardCamera;

/* Render work allocated by cmbCardEffTaskCreate (0x1B0 bytes). */
typedef union { f32 value; u32 bits; } CmbFloat;
typedef union { s16 value; u16 bits; } CmbFrame;
typedef struct {
    u8 vertices[0x110];
    u8 pad110[8];
    s32 *texture;
    union { s32 value; u32 bits; } flags;
    u8 pad120[4];
    CmbVec2f startPosition, endPosition, position;
    CmbFrame moveDuration, moveFrame;
    u8 pad140[0x50];
    CmbRGBA colors[3];
    CmbFrame alphaFrame, alphaDuration;
    CmbFloat scale;
    u8 pad1A4[0xC];
} CmbCardEffect;
typedef char CmbCardEffectSizeCheck[sizeof(CmbCardEffect) == 0x1B0 ? 1 : -1];

/* Model-effect resource task: primary transform plus an optional clone. */
typedef struct {
    u8 *file;
    s8 state;
    u8 pad05[3];
    u8 *effect;
    CmbFrame lifetimeFrame;
    u8 pad0E[2];
    union { u32 bits; s32 value; } lifetime;
    u8 drawOrder;
    u8 pad15[3];
    CmbVec3f position;
    f32 rotationX, rotationY, rotationZ, scale;
    CmbRGBA color;
    u8 alpha, alphaMode;
    CmbFrame alphaDuration, alphaFrame, delay;
    CmbFloat maxAlpha;
    u8 *clone;
    u8 hasClone;
    u8 pad49[3];
    CmbVec3f clonePosition;
    f32 cloneRotationX, cloneRotationY, cloneRotationZ, cloneScale;
    CmbRGBA cloneColor;
    u8 pad6C[4];
} CmbCardSprite;
typedef char CmbCardSpriteSizeCheck[sizeof(CmbCardSprite) == 0x70 ? 1 : -1];

typedef struct {
    s8 colorMode, state;
    u8 pad02[2];
    s32 sprites[5];
} CmbFiveSprites;

/* Both twelve-card banks share the caller-owned ID slots. Reload the
 * second ID after initialization, which can update caller-visible state. */
// FUN_0033E5C0
#pragma push
#pragma opt_propagation off
/* Steps the card loader state machine; returns its status. */
s32 cmbCardLoaderStep(u8 *task) {
    /* measured: each typed ID-array load loses MATCH; preserve the three byte-based reads, including the post-setup reload. */
    s16 cardIndex;
    CmbLoaderState *work;
    s8 state;

    work = (CmbLoaderState *)((SdkTask *)task)->work;
    state = work->state;
    if (state != 4) {
        switch (state) {
        case 0:
            pscResInitScene(work->environment, 0);
            func_00440b68((const char *)D_00763A28, D_0064A4A0, 0x63);
            work->file = H_Cdvd_AcquireDirectory(D_0064E590, 0);
            work->state += 1;
            break;
        case 1:
            if (H_Cdvd_IsFileLoaded((struct HCdvd *)work->file) != 0) {
                pscResBuildMiscCardW00((u8 *)((HCdvd *)work->file)->fileMemory);
                H_Cdvd_Destroy((struct HCdvd *)work->file);
                work->state += 1;
            }
            break;
        case 2:
            for (cardIndex = 0; cardIndex < 0xC; cardIndex++) {
                if (*(u16 *)((u8 *)work + (s32)cardIndex * 2 + 2) == 0)
                    goto next_card;
                btlShuffleCardSetupLayout((u8 *)&work->cards[0][cardIndex],
                              *(u16 *)((u8 *)work + (s32)cardIndex * 2 + 2));
                {
                    CmbLoaderCard *second;
                    s32 id;
                    second = &work->cards[1][cardIndex];
                    id = *(u16 *)((u8 *)work + (s32)cardIndex * 2 + 2);
                    btlShuffleCardSetupLayout((u8 *)second, id);
                }
                work->loaded += 1;
            next_card:
                ;
            }
            work->state += 1;
            break;
        case 3:
            if (pscResIsIdle() != 0) {
                work->state += 1;
            }
            break;
        }
    }
    return 0;
}

#pragma pop
// FUN_0033E7C0
/* Tear down the loader resource scene, then free its state block. */
void cmbCardControllerDestroy(u8 *task) {
    /* measured: the final task-work reload must remain byte-based after resource teardown. */
    pscResTeardown((u8 *)(((SdkTask *)task)->work) + 0x20);
    jtbl_008873EC[0](*(u8 **)(task + 0x38));
}

/* The controller keeps twelve complete 0x84-byte card records. Constructor
 * results and the rotation axis retain their real aggregate extents; both
 * setup loops reload the signed loader count before short-index promotion.
 * Measured in the complete owner: 3652 code bytes and twelve retail zero bytes.
 * opt_loop_invariants on retains the retail loop/address lifetimes. */
// FUN_0033E810
#pragma push
#pragma opt_loop_invariants on
/* Advances each card along its CmbCardPathPoint path once per frame. */
s32 cmbCardPathUpdate(u8 *task) {
    typedef char CardColorSizeCheck[sizeof(CmbRGBA) == 4 ? 1 : -1];

    void cmbCardSetAngle(u8 *, s8, f32);
    void cmbCardSetPosition(u8 *, s8, CmbVec2f);
    void cmbCardApplySlotTransform(u8 *, s8, CmbVec2f, f32);
    void cmbCardStartMove(u8 *, s8, CmbVec2f, CmbVec2f, s16);
    s32 cmbCardRunTwoCardLayout(u8 *);
    s32 cmbCardRunThreeCardLayout(u8 *);
    s32 cmbCardRunFourCardLayout(u8 *);
    s32 cmbCardRunFiveCardLayout(u8 *);
    s32 cmbCardRunSixCardLayout(u8 *);
    void cmbCardClearSlots(u8 *);
    s32 cmbCardEffSpriteFileLoaded(u8 *);
    void btlShuffleCardBindPacket(u8 *, void *);
    void btlShuffleCardBindSlot(u8 *, void *);
    void btlShuffleCardQueueEnqueue(u8 *, u8 *);
    extern CmbVec3f D_0064A4C8;
    extern u8 D_00794E70[];
    extern u8 D_00794EA0[];
    CmbCardController *work;
    s8 loadedCount;
    s16 setupIndex;
    s16 scaleIndex;
    s16 cardIndex;
    /* The setters consume byte representations. Each buffer also owns a
     * correctly aligned, complete color member for the constructor result. */
    union { CmbRGBA color; u8 bytes[sizeof(CmbRGBA)]; } initialColorBytes;
    union { CmbRGBA color; u8 bytes[sizeof(CmbRGBA)]; } secondaryColorBytes;
    CmbVec3f axis;
    CmbVec2f initialPosition;
    f32 quaternion[4];
    u8 secondaryOpacity;
    f32 opacityValue;
    f32 secondaryScale;
    work = (CmbCardController *)((SdkTask *)task)->work;
    if (((CmbLoaderState *)((SdkTask *)work->loaderTask)->work)->state != 4) {
        return 0;
    }
    if (evtGetEventFrame() >= 1000 && evtGetEventFrame() < 1011) {
        datSetFlag(0x5C, 0);
    }
    switch (work->phase) {
    case 0:
        if (cmbCardEffSpriteFileLoaded(work->loadGate) == 0) {
            return 0;
        }
        /* Keep a fresh signed count snapshot before promoting the short index. */
        for (setupIndex = 0;
             (loadedCount = ((CmbLoaderState *)((SdkTask *)work->loaderTask)->work)->loaded),
             setupIndex < loadedCount; setupIndex++) {
            initialPosition = fclMakeVec2(0.0f, 0.0f);
            cmbCardSetPosition(task, (s8)setupIndex, initialPosition);
            cmbCardSetAngle(task, (s8)setupIndex, 0.0f);
            *(CmbRGBA *)initialColorBytes.bytes = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0);
            btlShuffleCardBindSlot(((SdkTask *)work->loaderTask)->work + (s32)(s8)setupIndex * 0xFB0 + 0xE398, initialColorBytes.bytes);
            work->cards[setupIndex].scale = 1.0f;
            axis = D_0064A4C8;
            func_003dc740((struct RtQuat *)quaternion, (const struct RwV3d *)&axis, 180.0f, 0);
            btlShuffleCardBindPacket(((SdkTask *)work->loaderTask)->work + (s32)(s8)setupIndex * 0xFB0 + 0xE398, quaternion);
        }
        work->layout = 0;
        work->phase = work->nextPhase;
        cmbCardClearSlots(task);
        break;
    case 1:
        cmbCardRunTwoCardLayout(task);
        break;
    case 2:
        cmbCardRunThreeCardLayout(task);
        break;
    case 3:
        cmbCardRunFourCardLayout(task);
        break;
    case 4:
        cmbCardRunFiveCardLayout(task);
        break;
    case 5:
        cmbCardRunSixCardLayout(task);
        break;
    case 6:
        for (scaleIndex = 0;
             (loadedCount = ((CmbLoaderState *)((SdkTask *)work->loaderTask)->work)->loaded),
             scaleIndex < loadedCount; scaleIndex++) {
            work->cards[scaleIndex].scale = 0.75f;
        }
        cmbCardRunFullLayout(task);
        break;
    case 7:
        return -1;
    }
    if (work->layout == 9 && evtGetEventFrame() < 490) {
        secondaryScale = fclEaseInterpolate(0, work->cards[0].scale, work->cards[0].scale + 0.125f, (f32)work->pulseFrame, 60.0f);
        opacityValue = fclEaseInterpolate(1, 0.0f, 168.0f, (f32)work->pulseFrame, 30.0f);
        secondaryOpacity = (u8)opacityValue;
        work->pulseFrame = fclAddClamped(work->pulseFrame, 1, 60, 0, 2);
    }
    for (cardIndex = 0; cardIndex < work->activeCount; cardIndex++) {
        if ((work->cards[cardIndex].flags & 1) != 0) {
            work->cards[cardIndex].position.x = fclEaseInterpolate(0, work->cards[cardIndex].moveStart.x, work->cards[cardIndex].moveEnd.x, (f32)work->cards[cardIndex].moveFrame, (f32)work->cards[cardIndex].moveDuration);
            work->cards[cardIndex].position.y = fclEaseInterpolate(0, work->cards[cardIndex].moveStart.y, work->cards[cardIndex].moveEnd.y, (f32)work->cards[cardIndex].moveFrame, (f32)work->cards[cardIndex].moveDuration);
            if (work->cards[cardIndex].moveFrame < work->cards[cardIndex].moveDuration) {
                work->cards[cardIndex].moveFrame = fclAddClamped(work->cards[cardIndex].moveFrame, 1, work->cards[cardIndex].moveDuration, 0, 1);
            } else if ((work->cards[cardIndex].flags & 8) != 0) {
                cmbCardStartMove(task, (s8)cardIndex, work->cards[cardIndex].position, work->cards[cardIndex].path[work->cards[cardIndex].pathIndex].position, work->cards[cardIndex].path[work->cards[cardIndex].pathIndex].duration);
                work->cards[cardIndex].position.x = fclEaseInterpolate(0, work->cards[cardIndex].moveStart.x, work->cards[cardIndex].moveEnd.x, (f32)work->cards[cardIndex].moveFrame, (f32)work->cards[cardIndex].moveDuration);
                work->cards[cardIndex].position.y = fclEaseInterpolate(0, work->cards[cardIndex].moveStart.y, work->cards[cardIndex].moveEnd.y, (f32)work->cards[cardIndex].moveFrame, (f32)work->cards[cardIndex].moveDuration);
                work->cards[cardIndex].moveFrame = fclAddClamped(work->cards[cardIndex].moveFrame, 1, work->cards[cardIndex].moveDuration, 0, 1);
                work->cards[cardIndex].pathIndex += 1;
                if (work->cards[cardIndex].pathCount <= work->cards[cardIndex].pathIndex) {
                    work->cards[cardIndex].flags ^= 8;
                }
            } else {
                work->cards[cardIndex].flags ^= 1;
            }
        }
        cmbCardSetPosition(task, (s8)cardIndex, work->cards[cardIndex].position);
        if ((work->cards[cardIndex].flags & 2) != 0) {
            work->cards[cardIndex].angle = (f32)(s16)(s32)fclEaseInterpolate(0, work->cards[cardIndex].angleStart, work->cards[cardIndex].angleEnd, (f32)work->cards[cardIndex].angleFrame, (f32)work->cards[cardIndex].angleDuration);
            if (work->cards[cardIndex].angleFrame < work->cards[cardIndex].angleDuration) {
                work->cards[cardIndex].angleFrame = fclAddClamped(work->cards[cardIndex].angleFrame, 1, work->cards[cardIndex].angleDuration, 0, 1);
            } else {
                work->cards[cardIndex].flags ^= 2;
            }
            cmbCardSetAngle(task, (s8)cardIndex, work->cards[cardIndex].angle);
        }
        if ((work->cards[cardIndex].flags & 4) != 0) {
            work->cards[cardIndex].color.c0 = (u8)fclEaseInterpolate(0, (f32)work->cards[cardIndex].colorStart.c0, (f32)work->cards[cardIndex].colorEnd.c0, (f32)work->cards[cardIndex].colorFrame, (f32)work->cards[cardIndex].colorDuration);
            work->cards[cardIndex].color.c1 = (u8)fclEaseInterpolate(0, (f32)work->cards[cardIndex].colorStart.c1, (f32)work->cards[cardIndex].colorEnd.c1, (f32)work->cards[cardIndex].colorFrame, (f32)work->cards[cardIndex].colorDuration);
            work->cards[cardIndex].color.c2 = (u8)fclEaseInterpolate(0, (f32)work->cards[cardIndex].colorStart.c2, (f32)work->cards[cardIndex].colorEnd.c2, (f32)work->cards[cardIndex].colorFrame, (f32)work->cards[cardIndex].colorDuration);
            work->cards[cardIndex].color.c3 = (u8)fclEaseInterpolate(0, (f32)work->cards[cardIndex].colorStart.c3, (f32)work->cards[cardIndex].colorEnd.c3, (f32)work->cards[cardIndex].colorFrame, (f32)work->cards[cardIndex].colorDuration);
            if (work->cards[cardIndex].colorFrame < work->cards[cardIndex].colorDuration) {
                work->cards[cardIndex].colorFrame = fclAddClamped(work->cards[cardIndex].colorFrame, 1, work->cards[cardIndex].colorDuration, 0, 1);
            } else {
                work->cards[cardIndex].flags ^= 4;
            }
            btlShuffleCardBindSlot(((SdkTask *)work->loaderTask)->work + (s32)(s8)cardIndex * 0xFB0 + 0x2758, &work->cards[cardIndex].color);
        }
        if (work->cards[cardIndex].color.c3 > 0 && work->hideSecondary == 0) {
            btlShuffleCardQueueEnqueue(((SdkTask *)work->loaderTask)->work + (s32)(s8)cardIndex * 0xFB0 + 0x2758, D_00794E70);
        }
        if (work->layout == 9 && evtGetEventFrame() < 490 && work->hideSecondary == 0) {
            cmbCardApplySlotTransform(task, (s8)cardIndex, work->cards[cardIndex].position, secondaryScale);
            *(CmbRGBA *)secondaryColorBytes.bytes = fclMakeDrawColor(0xFF, 0xFF, 0xFF, secondaryOpacity);
            btlShuffleCardBindSlot(((SdkTask *)work->loaderTask)->work + (s32)(s8)cardIndex * 0xFB0 + 0xE398, secondaryColorBytes.bytes);
            btlShuffleCardQueueEnqueue(((SdkTask *)work->loaderTask)->work + (s32)(s8)cardIndex * 0xFB0 + 0xE398, D_00794EA0);
        }
    }
    return 0;
}
#pragma pop


// FUN_0033F660
/* Releases the card controller's state block through jump-table slot 0. */
void cmbCardReleaseState(u8 *task) {
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

/* measured: MATCHED this wave — the recorded nd-22 copy-loop rotation floor is broken
   by three spellings together: (1) recipe B (u32 cast base `u32 base = (u32)D_008873F4;`
   + per-call `((u8 *(*)(s32,s32,s32))*(u32 *)base)()`) for the saved-$20 lui/addiu
   base hoist (typed-pointer local and array spelling still fold to per-call lui/lw);
   (2) `ret` declared FIRST (before blk1/base) — any other order puts ret in $s0 and
   blk1 in $s1, retail has ret=$s1/blk1=$s0, a pure 40-word rotation; (3) a SEPARATE
   `s16 j` counter for the second 0x84-stride loop — reusing i makes b210 pick $a2
   where retail's second loop counter is $a0 (the first loop holds $a2). nd path:
   68 (plain array spelling) -> 40 (recipe B) -> 8 (ret-first) -> 0 (separate j).
   Callbacks cmbCardPathUpdate/cmbCardLoaderStep need file-scope prototypes for the arg passing. */
// Creates the card's child tasks: a path task with a 0x6E0-byte work block and a loader task with a 0x19FDC-byte block that copies the 12-entry table from cardIds [inferred].
// FUN_0033F690
u8 *cmbCardEffSpawnChild(u8 *parent, u8 *cardIds, s8 layoutMode) {
    u8 *pathTask;
    u8 *controllerWork;
    u32 allocatorTable;
    u8 *loaderWork;
    u8 *loaderTask;
    s16 idIndex;
    s16 cardIndex;
    chkmemAllocSiteTag(D_0064A4A0, 0x1B8);
    allocatorTable = (u32)D_008873F4;
    controllerWork = ((u8 *(*)(s32, s32, s32))*(u32 *)allocatorTable)(1, 0x6E0, 0x40000);
    pathTask = (u8 *)(s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064A4E0), 0xF, 0, 0, cmbCardPathUpdate, cmbCardReleaseState, (u8 *)(controllerWork));
    chkmemAllocSiteTag(D_0064A4A0, 0xAD);
    loaderWork = ((u8 *(*)(s32, s32, s32))*(u32 *)allocatorTable)(1, 0x19FDC, 0x40000);
    loaderTask = (u8 *)(s32)kwlnTaskCreateChild((void *)(pathTask), (const void *)(D_0064A4B0), 0xF, 0, 0, cmbCardLoaderStep, cmbCardControllerDestroy, (u8 *)(loaderWork));
    for (idIndex = 0; idIndex < 0xC; idIndex++) {
        ((CmbLoaderState *)loaderWork)->ids[idIndex] = ((s16 *)cardIds)[idIndex];
    }
    ((CmbLoaderState *)loaderWork)->state = 0;
    ((CmbLoaderState *)loaderWork)->loaded = 0;
    ((CmbCardController *)controllerWork)->loaderTask = loaderTask;
    for (cardIndex = 0; cardIndex < 0xC; cardIndex++) {
        ((CmbCardController *)controllerWork)->cards[cardIndex].flags = 0;
    }
    ((CmbCardController *)controllerWork)->phase = 0;
    ((CmbCardController *)controllerWork)->nextPhase = layoutMode;
    ((CmbCardController *)controllerWork)->reserved08[0] = 0;
    ((CmbCardController *)controllerWork)->reserved01[0] = 0;
    ((CmbCardController *)controllerWork)->hideSecondary = 0;
    switch (layoutMode) {
    case 1:
        ((CmbCardController *)controllerWork)->activeCount = 2;
        ((CmbCardController *)controllerWork)->loadGate = cmbCardEffCreateSprite(pathTask, D_0064A500, 6);
        break;
    case 2:
        ((CmbCardController *)controllerWork)->activeCount = 3;
        ((CmbCardController *)controllerWork)->loadGate = cmbCardEffCreateSprite(pathTask, D_0064A520, 6);
        break;
    case 3:
        ((CmbCardController *)controllerWork)->activeCount = 4;
        ((CmbCardController *)controllerWork)->loadGate = cmbCardEffCreateSprite(pathTask, D_0064A540, 6);
        break;
    case 4:
        ((CmbCardController *)controllerWork)->activeCount = 5;
        ((CmbCardController *)controllerWork)->loadGate = cmbCardEffCreateSprite(pathTask, D_0064A560, 6);
        break;
    case 5:
        ((CmbCardController *)controllerWork)->activeCount = 6;
        ((CmbCardController *)controllerWork)->loadGate = cmbCardEffCreateSprite(pathTask, D_0064A580, 6);
        break;
    case 6:
        ((CmbCardController *)controllerWork)->activeCount = 0xC;
        ((CmbCardController *)controllerWork)->loadGate = cmbCardEffCreateSprite(pathTask, D_0064A580, 6);
        break;
    }
    datSetFlag(0x58, 0);
    datSetFlag(0x59, 0);
    datSetFlag(0x5A, 0);
    datSetFlag(0x5B, 0);
    datSetFlag(0x5C, 0);
    datSetFlag(0x5D, 0);
    datSetFlag(0x5E, 0);
    datSetFlag(0x5F, 0);
    return pathTask;
}
// Returns the card effect's work block, stored at task+0x38 [inferred].
// FUN_0033FA20
void *cmbCardEffWork(u8 *task) {
    return ((SdkTask *)task)->work;
}

/* The angle arrives in the independent floating-point argument register and
 * is forwarded to the quaternion constructor before the draw scale is formed.
 * The task callback caller supplies zero or its current animation angle.
 * Native b210 -O2 remains 224/224 bytes; contract and controlled-provider proof:
 * docs/probe_archive/yCmb_angle_forwarding_20260922.md. */
// FUN_0033FA30
#pragma push
/* measured: opt_propagation off keeps &axisXY in $a1 before the D_0064A5A0/D_0064A5A8
   staging loads and the p84 multiply below the task chain (the "scheduler-CSE floor"
   above was propagation, not scheduling). */
#pragma opt_propagation off
/* Sets the selected card's angle (f32, radians-style value from the caller). */
void cmbCardSetAngle(u8 *task, s8 cardIndex, f32 angle) {
    /* measured: the first loaderTask read stays raw; typing it changes the matched instruction stream. */
    struct { f32 rotation[4]; s64 axisXY; f32 axisZ; } rotationWork;
    s64 axisXY;
    f32 axisZ;
    f32 *axis;
    u8 *work;
    u8 *loaderWork;
    u8 *loaderCard;
    u8 *card;
    u8 *slotBase;

    work = ((SdkTask *)task)->work;
    axis = (f32 *)&rotationWork.axisXY;
    axisXY = D_0064A5A0[0];
    axisZ = *(f32 *)&D_0064A5A0[1];
    rotationWork.axisXY = axisXY;
    rotationWork.axisZ = axisZ;
    func_003dc740((struct RtQuat *)&rotationWork.rotation, (const struct RwV3d *)axis, angle, 0);
    loaderWork = ((SdkTask *)*(u8 **)(work + 4))->work;
    if ((s8)*loaderWork == 4) {
        loaderCard = loaderWork + (s32)cardIndex * 0xFB0;
        card = loaderCard + 0x2758;
        slotBase = work + (s32)cardIndex * 0x84;
        btlShuffleCardApplyScale(card, (f32 *)(slotBase + 0x20), 90.0f * ((CmbCardSlot *)(slotBase + 0xC))->scale);
        btlShuffleCardBindPacket(((SdkTask *)((CmbCardController *)work)->loaderTask)->work + (s32)cardIndex * 0xFB0 + 0x2758, &rotationWork.rotation);
    }
}
#pragma pop

/* Native two-float values preserve four-byte-aligned card positions. */
// FUN_0033FB10
/* Sets the selected card's position from a native two-float vector. */
void cmbCardSetPosition(u8 *task, s8 cardIndex, CmbVec2f position) {
    /* measured: typing the loader task-work read changes address evaluation (20 differing bytes); the scale read is typed. */
    u8 *work = ((SdkTask *)task)->work;
    u32 slotOffset = (s32)cardIndex * 0x84;
    btlShuffleCardApplyScale((u8 *)(*(u32 *)(((CmbCardController *)work)->loaderTask + 0x38) + (s32)cardIndex * 0xFB0 + 0x2758), (f32 *)&position, 90.0f * ((CmbCardSlot *)(slotOffset + (u32)work + 0xC))->scale);
}
/* measured: MATCHED this wave. The nd-8 candidate had the correct 0xFB0 stride,
   packed two-float argument, and 90.0f scaling, but fndiff showed the final 0xE398
   address operation after the float setup (`lui/mtc1/nop/mul.s`) and with the
   wrong intermediate destination register. Applying the matching guide's
   pointer-typed staging lever — first compute `tmp = ptr + 0xE398`, then cast
   that pointer through a u32 local before the call — forces retail's
   `ori $at,$zero,0xE398; addu $a0,$v0,$at` before the float setup. The residual
   changed from 8 words (obj 108B/window 112B) to padding-only nd 1, and scoped
   lverify reports MATCH (normalized_diff 0). */
// Apply slot transform: sets the selected card's position and its 90 * scale size on its packet (btlShuffleCardApplyScale).
// FUN_0033FB90
void cmbCardApplySlotTransform(u8 *task, s8 cardIndex, CmbVec2f position, f32 scale) {
    u8 *work;
    u8 *loaderWork;
    u32 cardOffset;
    u8 *loaderCard;
    u8 *secondaryCard;
    u32 cardAddress;

    work = ((SdkTask *)task)->work;
    loaderWork = ((SdkTask *)((CmbCardController *)work)->loaderTask)->work;
    cardOffset = (s32)cardIndex * 0xFB0;
    loaderCard = loaderWork + cardOffset;
    secondaryCard = loaderCard + 0xE398;
    cardAddress = (u32)secondaryCard;
    btlShuffleCardApplyScale((u8 *)cardAddress, (f32 *)&position, 90.0f * scale);
}
/* measured: MATCHED this wave — the old nd-1 "load-sinking + addu-order floor" is broken by
   lever 3 + opt_propagation: the inline helper cmbAddPtrRev carries the index-first addu
   (`addu $a0,$v1,$a2` vs the old base-first `addu $a0,$a2,$v1`) through its parameters,
   and `#pragma opt_propagation off` forces the single-use base load early into $a2
   (helper alone: nd 9, load sinks to $v1 and the sign-ext chain shifts to $a1;
   pragma alone on the plain expression: nd 3, still base-first addu). */
// FUN_0033FC00
#pragma opt_propagation off /* measured: see above; forces the base load early (lw $a2,0x38($a0) first) */
/* Starts the selected card's move: start and target positions, duration in frames; sets the active flag. */
void cmbCardStartMove(u8 *task, s8 cardIndex, CmbVec2f startPosition, CmbVec2f endPosition, s16 duration) {
    u8 *slotBase = cmbAddPtrRev((u32)((SdkTask *)task)->work, (u32)((s32)cardIndex * 0x84));
    ((CmbCardSlot *)(slotBase + 0xC))->position = startPosition;
    ((CmbCardSlot *)(slotBase + 0xC))->moveStart = ((CmbCardSlot *)(slotBase + 0xC))->position;
    ((CmbCardSlot *)(slotBase + 0xC))->moveEnd = endPosition;
    ((CmbCardSlot *)(slotBase + 0xC))->moveFrame = 0;
    ((CmbCardSlot *)(slotBase + 0xC))->moveDuration = duration;
    ((CmbCardSlot *)(slotBase + 0xC))->flags |= 1;
}
#pragma opt_propagation on
static inline void cmbSetMove(u8 *task, s8 cardIndex, CmbVec2f startPosition, CmbVec2f endPosition, u16 duration) {
    /* Start movement (flag 1); the raw task read preserves the inline setters' shared byte-alias scope. */
    u8 *slotBase = *(u8 **)(task + 0x38);
    slotBase += (s32)cardIndex * 0x84;
    ((CmbCardSlot *)(slotBase + 0xC))->position = startPosition;
    ((CmbCardSlot *)(slotBase + 0xC))->moveStart = ((CmbCardSlot *)(slotBase + 0xC))->position;
    ((CmbCardSlot *)(slotBase + 0xC))->moveEnd = endPosition;
    ((CmbCardSlot *)(slotBase + 0xC))->moveFrame = 0;
    ((CmbCardSlot *)(slotBase + 0xC))->moveDuration = duration;
    ((CmbCardSlot *)(slotBase + 0xC))->flags |= 1;
}
static inline void cmbSetColor(u8 *task, s8 cardIndex, CmbRGBA start, CmbRGBA end, u16 duration) {
    /* Start color interpolation (flag 4); retain the inline setters' byte-based task read for matching. */
    u8 *slotBase = *(u8 **)(task + 0x38);
    slotBase += (s32)cardIndex * 0x84;
    ((CmbCardSlot *)(slotBase + 0xC))->color = start;
    ((CmbCardSlot *)(slotBase + 0xC))->colorStart = ((CmbCardSlot *)(slotBase + 0xC))->color;
    ((CmbCardSlot *)(slotBase + 0xC))->colorEnd = end;
    ((CmbCardSlot *)(slotBase + 0xC))->colorFrame = 0;
    ((CmbCardSlot *)(slotBase + 0xC))->colorDuration = duration;
    ((CmbCardSlot *)(slotBase + 0xC))->flags |= 4;
}
static inline void cmbAddPath(u8 *task, s8 cardIndex, CmbVec2f position, s16 duration) {
    /* Append a waypoint (flag 8). measured: typing the count store loses six layout matches; the reads and waypoint are typed. */
    u8 *work = *(u8 **)(task + 0x38);
    s32 pathIndex = ((CmbCardSlot *)(work + cardIndex * 0x84 + 0xC))->pathCount;
    u8 *pathBase = cmbAddPtrRev((u32)work, (u32)(pathIndex * 0xC));
    ((CmbCardPathPoint *)(pathBase + cardIndex * 0x84 + 0x2C))->position = position;
    ((CmbCardPathPoint *)(pathBase + cardIndex * 0x84 + 0x2C))->duration = duration;
    ((CmbCardSlot *)(work + cardIndex * 0x84 + 0xC))->flags |= 8;
    *(s8 *)(work + cardIndex * 0x84 + 0x68) = fclAddClamped(((CmbCardSlot *)(work + cardIndex * 0x84 + 0xC))->pathCount, 1, 5, 0, 1);
}
// Two-card layout: card-layout state machine for two cards (dispatcher phase 1). States: 0 start the slide at frame 0x50, 6 init slot params at 0x73, 7 spawn the effect, 8 wait for it, 9 converge at 0x1EA, 10 clear colour, 11 cue sound at 0x208-0x347, 12 advance. Returns 0 when blocked or skipped by flag 0x58, else 1.
// FUN_0033FC80
s32 cmbCardRunTwoCardLayout(u8 *task) {
    /* measured: the initial layout read stays raw; typing that single read loses MATCH. Task reads retain the inline setters' byte-alias scope. */
    u8 *effectWork;
    u8 *effectTableBase;
    u8 *effectSlot;
    u8 *slotBase;
    u8 *work;
    s16 state;
    s8 hideIndex;
    s8 setupIndex;
    s8 enableIndex;
    s8 convergeIndex;
    s8 fadeIndex;
    s32 index;
    s32 value;
    f32 coordinate;

    work = *(u8 **)(task + 0x38);
    if (((CmbCardSlot *)(work + 0xC))->flags != 0 || ((CmbCardController *)work)->cards[1].flags != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        ((CmbCardController *)work)->hideSecondary = 1;
        hideIndex = 0;
        while (hideIndex < 2) {
            cmbSetColor(task, hideIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)hideIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            hideIndex++;
        }
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(work + 0x63C);
    switch (state) {
    case 0:
        if (evtGetEventFrame() >= 0x50) {
            cmbSetMove(task, 0, fclMakeVec2(10.0f, 212.0f), fclMakeVec2(230.0f, 212.0f), 5);
            cmbSetColor(task, 0, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbSetMove(task, 1, fclMakeVec2(10.0f, 212.0f), fclMakeVec2(230.0f, 212.0f), 5);
            cmbSetColor(task, 1, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 1, fclMakeVec2(0x19F, 212.0f), 5);
            ((CmbCardController *)work)->layout = 6;
        }
        break;
    case 6:
        if (evtGetEventFrame() >= 0x73) {
            setupIndex = 0;
            while (setupIndex < 2) {
                slotBase = *(u8 **)(task + 0x38);
                slotBase += (s32)setupIndex * 0x84;
                ((CmbCardSlot *)(slotBase + 0xC))->angle = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleStart = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleEnd = -180.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleFrame = 0;
                ((CmbCardSlot *)(slotBase + 0xC))->angleDuration = 3;
                ((CmbCardSlot *)(slotBase + 0xC))->flags |= 2;
                effectTableBase = work + (s32)setupIndex * 4;
                slotBase = work + (s32)setupIndex * 0x84;
                effectSlot = effectTableBase + 0x658;
                coordinate = ((CmbCardSlot *)(slotBase + 0xC))->position.x + 16.0f;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.x = coordinate;
                coordinate = ((CmbCardSlot *)(slotBase + 0xC))->position.y;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.y = coordinate;
                cmbCardEffSetParams(*(u8 **)effectSlot, 0, 0x80, 0x3C);
                setupIndex++;
            }
            ((CmbCardController *)work)->layout = 7;
        }
        break;
    case 7:
        sdkSndStartChannel(2, D_0064A5B0);
        cmbCardEffSpawnSprite(((CmbCardController *)work)->loadGate, fclMakeVec3(0.0f, 5.0f, 30.0f),
                      0.0f, 0.0f, 0.0f, 1.0f,
                      fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
        ((CmbCardController *)work)->layout = 8;
    case 8:
        if (kwlnTaskIsLinked(((CmbCardController *)work)->loadGate) != 1) {
            enableIndex = 0;
            while (enableIndex < 2) {
                effectSlot = work + (s32)enableIndex * 4;
                effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
                ((CmbCardEffect *)effectWork)->flags.value |= 2;
                enableIndex++;
            }
            ((CmbCardController *)work)->layout = 9;
        }
        break;
    case 9:
        if (evtGetEventFrame() >= 0x1EA) {
            convergeIndex = 0;
            while (convergeIndex < 2) {
                cmbSetMove(task, convergeIndex, ((CmbCardSlot *)(work + (s32)convergeIndex * 0x84 + 0xC))->position, fclMakeVec2(323.0f, 217.0f), 3);
                effectSlot = work + (s32)convergeIndex * 4;
                slotBase = effectSlot + 0x658;
                effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
                cmbCardEffSetPosition(*(u8 **)slotBase, ((CmbCardEffect *)effectWork)->position, fclMakeVec2(339.0f, 217.0f), 3);
                convergeIndex++;
            }
            ((CmbCardController *)work)->layout = 10;
        }
        break;
    case 10:
        fadeIndex = 0;
        while (fadeIndex < 2) {
            cmbSetColor(task, fadeIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)fadeIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            fadeIndex++;
        }
        ((CmbCardController *)work)->hideSecondary = 1;
        ((CmbCardController *)work)->layout = 11;
        break;
    case 11:
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        break;
    case 12:
        ((CmbCardController *)work)->phase += 1;
        break;
    }
    return 1;
}

// Three-card layout: card-layout state machine for three cards (dispatcher phase 2). States as in cmbCardRunTwoCardLayout. Returns 0 when blocked or skipped by flag 0x58, else 1.
// FUN_003407F0
s32 cmbCardRunThreeCardLayout(u8 *task) {
    /* measured: the initial layout read stays raw; typing that single read loses MATCH. Task reads retain the inline setters' byte-alias scope. The remaining hideSecondary store also fails an individual typed substitution. */
    u8 *effectWork;
    u8 *effectTableBase;
    u8 *effectSlot;
    u8 *slotBase;
    u8 *updatedSlotBase;
    u8 *work;
    s16 state;
    s8 hideIndex;
    s8 setupIndex;
    s8 enableIndex;
    s8 convergeIndex;
    s8 fadeIndex;
    s32 index;
    s32 index2;
    f32 coordinate;

    work = *(u8 **)(task + 0x38);
    if (((CmbCardSlot *)(work + 0xC))->flags != 0 || ((CmbCardController *)work)->cards[1].flags != 0 || ((CmbCardController *)work)->cards[2].flags != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        ((CmbCardController *)work)->hideSecondary = 1;
        hideIndex = 0;
        while (hideIndex < 3) {
            cmbSetColor(task, hideIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)hideIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            hideIndex++;
        }
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(work + 0x63C);
    switch (state) {
    case 0:
        if (evtGetEventFrame() >= 0x50) {
            cmbSetMove(task, 0, fclMakeVec2(-86.0f, 297.0f), fclMakeVec2(185.0f, 297.0f), 5);
            cmbSetColor(task, 0, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbSetMove(task, 1, fclMakeVec2(-86.0f, 297.0f), fclMakeVec2(185.0f, 297.0f), 5);
            cmbSetColor(task, 1, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 1, fclMakeVec2(456.0f, 297.0f), 5);
            cmbSetMove(task, 2, fclMakeVec2(-86.0f, 297.0f), fclMakeVec2(185.0f, 297.0f), 5);
            cmbSetColor(task, 2, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 2, fclMakeVec2(456.0f, 297.0f), 5);
            cmbAddPath(task, 2, fclMakeVec2(320.0f, 104.0f), 5);
            ((CmbCardController *)work)->layout = 6;
        }
        break;
    case 6:
        if (evtGetEventFrame() >= 0x73) {
            setupIndex = 0;
            while (setupIndex < 3) {
                slotBase = *(u8 **)(task + 0x38);
                slotBase += (s32)setupIndex * 0x84;
                ((CmbCardSlot *)(slotBase + 0xC))->angle = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleStart = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleEnd = -180.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleFrame = 0;
                ((CmbCardSlot *)(slotBase + 0xC))->angleDuration = 3;
                ((CmbCardSlot *)(slotBase + 0xC))->flags |= 2;
                effectTableBase = work + (s32)setupIndex * 4;
                slotBase = work + (s32)setupIndex * 0x84;
                effectSlot = effectTableBase + 0x658;
                coordinate = ((CmbCardSlot *)(slotBase + 0xC))->position.x + 16.0f;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.x = coordinate;
                coordinate = ((CmbCardSlot *)(slotBase + 0xC))->position.y;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.y = coordinate;
                cmbCardEffSetParams(*(u8 **)effectSlot, 0, 0x80, 0x32);
                setupIndex++;
            }
            ((CmbCardController *)work)->layout = 7;
        }
        break;
    case 7:
        sdkSndStartChannel(2, D_0064A5B0);
        cmbCardEffSpawnSprite(((CmbCardController *)work)->loadGate, fclMakeVec3(0.0f, -5.0f, 30.0f), 0.0f, 0.0f, 0.0f, iGpffff8360, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
        ((CmbCardController *)work)->layout = 8;
        /* fallthrough */
    case 8:
        if (kwlnTaskIsLinked(((CmbCardController *)work)->loadGate) != 1) {
            enableIndex = 0;
            while (enableIndex < 3) {
                effectSlot = work + (s32)enableIndex * 4;
                effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
                ((CmbCardEffect *)effectWork)->flags.value |= 2;
                enableIndex++;
            }
            ((CmbCardController *)work)->layout = 9;
        }
        break;
    case 9:
        if (evtGetEventFrame() >= 0x1EA) {
            convergeIndex = 0;
            while (convergeIndex < 3) {
                cmbSetMove(task, convergeIndex, ((CmbCardSlot *)(work + (s32)convergeIndex * 0x84 + 0xC))->position, fclMakeVec2(323.0f, 217.0f), 3);
                effectSlot = work + (s32)convergeIndex * 4;
                slotBase = effectSlot + 0x658;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)slotBase);
                cmbCardEffSetPosition(*(u8 **)slotBase, ((CmbCardEffect *)effectWork)->position, fclMakeVec2(339.0f, 217.0f), 3);
                convergeIndex++;
            }
            ((CmbCardController *)work)->layout = 10;
        }
        break;
    case 10:
        *(u8 *)(work + 0x6B8) = 1;
        fadeIndex = 0;
        while (fadeIndex < 3) {
            cmbSetColor(task, fadeIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)fadeIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            fadeIndex++;
        }
        ((CmbCardController *)work)->hideSecondary = 1;
        ((CmbCardController *)work)->layout = 11;
        break;
    case 11:
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        break;
    case 12:
        ((CmbCardController *)work)->phase += 1;
        break;
    }
    return 1;
}

// Four-card layout: card-layout state machine for four cards (dispatcher phase 3). States as in cmbCardRunTwoCardLayout. Returns 0 when blocked or skipped by flag 0x58, else 1.
// FUN_00341640
s32 cmbCardRunFourCardLayout(u8 *task) {
    /* measured: the initial layout read stays raw; typing that single read loses MATCH. Task reads retain the inline setters' byte-alias scope. */
    u8 *effectWork;
    u8 *effectTableBase;
    u8 *effectSlot;
    u8 *slotBase;
    u8 *updatedSlotBase;
    u8 *work;
    s16 state;
    s8 hideIndex;
    s8 setupIndex;
    s8 enableIndex;
    s8 convergeIndex;
    s8 fadeIndex;
    s32 index;
    s32 index2;
    s32 index3;
    f32 coordinate;

    work = *(u8 **)(task + 0x38);
    if (((CmbCardSlot *)(work + 0xC))->flags != 0 || ((CmbCardController *)work)->cards[1].flags != 0 || ((CmbCardController *)work)->cards[2].flags != 0 || ((CmbCardController *)work)->cards[3].flags != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        ((CmbCardController *)work)->hideSecondary = 1;
        hideIndex = 0;
        while (hideIndex < 4) {
            cmbSetColor(task, hideIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)hideIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            hideIndex++;
        }
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(work + 0x63C);
    switch (state) {
    case 0:
        if (evtGetEventFrame() >= 0x50) {
            cmbSetMove(task, 0, fclMakeVec2(-82.0f, 217.0f), fclMakeVec2(188.0f, 217.0f), 5);
            cmbSetColor(task, 0, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbSetMove(task, 1, fclMakeVec2(-82.0f, 217.0f), fclMakeVec2(188.0f, 217.0f), 5);
            cmbSetColor(task, 1, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 1, fclMakeVec2(458.0f, 217.0f), 5);
            cmbSetMove(task, 2, fclMakeVec2(-82.0f, 217.0f), fclMakeVec2(188.0f, 217.0f), 5);
            cmbSetColor(task, 2, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 2, fclMakeVec2(458.0f, 217.0f), 5);
            cmbAddPath(task, 2, fclMakeVec2(323.0f, 337.0f), 5);
            cmbSetMove(task, 3, fclMakeVec2(-82.0f, 217.0f), fclMakeVec2(188.0f, 217.0f), 5);
            cmbSetColor(task, 3, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 3, fclMakeVec2(458.0f, 217.0f), 5);
            cmbAddPath(task, 3, fclMakeVec2(323.0f, 337.0f), 5);
            cmbAddPath(task, 3, fclMakeVec2(323.0f, 82.0f), 5);
            ((CmbCardController *)work)->layout = 6;
        }
        break;
    case 6:
        if (evtGetEventFrame() >= 0x73) {
            setupIndex = 0;
            while (setupIndex < 4) {
                slotBase = *(u8 **)(task + 0x38);
                slotBase += (s32)setupIndex * 0x84;
                ((CmbCardSlot *)(slotBase + 0xC))->angle = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleStart = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleEnd = -180.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleFrame = 0;
                ((CmbCardSlot *)(slotBase + 0xC))->angleDuration = 3;
                ((CmbCardSlot *)(slotBase + 0xC))->flags |= 2;
                effectTableBase = work + (s32)setupIndex * 4;
                slotBase = work + (s32)setupIndex * 0x84;
                effectSlot = effectTableBase + 0x658;
                coordinate = ((CmbCardSlot *)(slotBase + 0xC))->position.x + 16.0f;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.x = coordinate;
                coordinate = ((CmbCardSlot *)(slotBase + 0xC))->position.y;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.y = coordinate;
                cmbCardEffSetParams(*(u8 **)effectSlot, 0, 0x80, 0x32);
                setupIndex++;
            }
            ((CmbCardController *)work)->layout = 7;
        }
        break;
    case 7:
        sdkSndStartChannel(2, D_0064A5B0);
        cmbCardEffSpawnSprite(((CmbCardController *)work)->loadGate, fclMakeVec3(0.0f, 5.0f, 30.0f), 0.0f, 0.0f, 0.0f, iGpffff8360, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
        ((CmbCardController *)work)->layout = 8;
        /* fallthrough */
    case 8:
        if (kwlnTaskIsLinked(((CmbCardController *)work)->loadGate) != 1) {
            enableIndex = 0;
            while (enableIndex < 4) {
                effectSlot = work + (s32)enableIndex * 4;
                effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
                ((CmbCardEffect *)effectWork)->flags.value |= 2;
                enableIndex++;
            }
            ((CmbCardController *)work)->layout = 9;
        }
        break;
    case 9:
        if (evtGetEventFrame() >= 0x1EA) {
            convergeIndex = 0;
            while (convergeIndex < 4) {
                cmbSetMove(task, convergeIndex, ((CmbCardSlot *)(work + (s32)convergeIndex * 0x84 + 0xC))->position, fclMakeVec2(323.0f, 217.0f), 3);
                effectSlot = work + (s32)convergeIndex * 4;
                slotBase = effectSlot + 0x658;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)slotBase);
                cmbCardEffSetPosition(*(u8 **)slotBase, ((CmbCardEffect *)effectWork)->position, fclMakeVec2(339.0f, 217.0f), 3);
                convergeIndex++;
            }
            ((CmbCardController *)work)->layout = 10;
        }
        break;
    case 10:
        ((CmbCardController *)work)->hideSecondary = 1;
        fadeIndex = 0;
        while (fadeIndex < 4) {
            cmbSetColor(task, fadeIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)fadeIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            fadeIndex++;
        }
        ((CmbCardController *)work)->layout = 11;
        break;
    case 11:
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        break;
    case 12:
        ((CmbCardController *)work)->phase += 1;
        break;
    }
    return 1;
}

// Five-card layout: card-layout state machine for five cards (dispatcher phase 4). States as in cmbCardRunTwoCardLayout. Returns 0 when blocked or skipped by flag 0x58, else 1.
// FUN_003427A0
s32 cmbCardRunFiveCardLayout(u8 *task) {
    /* measured: the initial layout read stays raw; typing that single read loses MATCH. Task reads retain the inline setters' byte-alias scope. */
    u8 *effectWork;
    u8 *effectSlot;
    u8 *effectTableBase;
    u8 *slotBase;
    u8 *updatedSlotBase;
    u8 *work;
    s16 state;
    s8 hideIndex;
    s8 setupIndex;
    s8 enableIndex;
    s8 convergeIndex;
    s8 fadeIndex;
    s32 index;
    s32 index2;
    s32 index3;
    f32 coordinate;

    work = *(u8 **)(task + 0x38);
    if (((CmbCardSlot *)(work + 0xC))->flags != 0 || ((CmbCardController *)work)->cards[1].flags != 0 || ((CmbCardController *)work)->cards[2].flags != 0 || ((CmbCardController *)work)->cards[3].flags != 0 || ((CmbCardController *)work)->cards[4].flags != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        ((CmbCardController *)work)->hideSecondary = 1;
        hideIndex = 0;
        while (hideIndex < 5) {
            cmbSetColor(task, hideIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)hideIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            hideIndex++;
        }
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(work + 0x63C);
    switch (state) {
    case 0:
        if (evtGetEventFrame() >= 0x50) {
            cmbSetMove(task, 0, fclMakeVec2(-95.0f, 182.0f), fclMakeVec2(185.0f, 182.0f), 5);
            cmbSetColor(task, 0, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbSetMove(task, 1, fclMakeVec2(-95.0f, 182.0f), fclMakeVec2(185.0f, 182.0f), 5);
            cmbSetColor(task, 1, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 1, fclMakeVec2(465.0f, 182.0f), 5);
            cmbSetMove(task, 2, fclMakeVec2(-95.0f, 182.0f), fclMakeVec2(185.0f, 182.0f), 5);
            cmbSetColor(task, 2, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 2, fclMakeVec2(465.0f, 182.0f), 5);
            cmbAddPath(task, 2, fclMakeVec2(239.0f, 343.0f), 5);
            cmbSetMove(task, 3, fclMakeVec2(-95.0f, 182.0f), fclMakeVec2(185.0f, 182.0f), 5);
            cmbSetColor(task, 3, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 3, fclMakeVec2(465.0f, 182.0f), 5);
            cmbAddPath(task, 3, fclMakeVec2(239.0f, 343.0f), 5);
            cmbAddPath(task, 3, fclMakeVec2(411.0f, 343.0f), 5);
            cmbSetMove(task, 4, fclMakeVec2(-95.0f, 182.0f), fclMakeVec2(185.0f, 182.0f), 5);
            cmbSetColor(task, 4, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(task, 4, fclMakeVec2(465.0f, 182.0f), 5);
            cmbAddPath(task, 4, fclMakeVec2(239.0f, 343.0f), 5);
            cmbAddPath(task, 4, fclMakeVec2(411.0f, 343.0f), 5);
            cmbAddPath(task, 4, fclMakeVec2(325.0f, 83.0f), 5);
            ((CmbCardController *)work)->layout = 6;
        }
        break;
    case 6:
        if (evtGetEventFrame() >= 0x73) {
            setupIndex = 0;
            while (setupIndex < 5) {
                slotBase = *(u8 **)(task + 0x38);
                slotBase += (s32)setupIndex * 0x84;
                ((CmbCardSlot *)(slotBase + 0xC))->angle = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleStart = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleEnd = -180.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleFrame = 0;
                ((CmbCardSlot *)(slotBase + 0xC))->angleDuration = 3;
                ((CmbCardSlot *)(slotBase + 0xC))->flags |= 2;
                effectTableBase = work + (s32)setupIndex * 4;
                updatedSlotBase = work + (s32)setupIndex * 0x84;
                effectSlot = effectTableBase + 0x658;
                coordinate = ((CmbCardSlot *)(updatedSlotBase + 0xC))->position.x + 16.0f;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.x = coordinate;
                coordinate = ((CmbCardSlot *)(updatedSlotBase + 0xC))->position.y;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.y = coordinate;
                cmbCardEffSetParams(*(u8 **)effectSlot, 0, 0x80, 0x32);
                setupIndex++;
            }
            ((CmbCardController *)work)->layout = 7;
        }
        break;
    case 7:
        sdkSndStartChannel(2, D_0064A5B0);
        cmbCardEffSpawnSprite(((CmbCardController *)work)->loadGate, fclMakeVec3(0.0f, 5.0f, 30.0f), 0.0f, 0.0f, 0.0f, iGpffff8360, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
        ((CmbCardController *)work)->layout = 8;
        /* fallthrough */
    case 8:
        if (kwlnTaskIsLinked(((CmbCardController *)work)->loadGate) != 1) {
            enableIndex = 0;
            while (enableIndex < 5) {
                effectSlot = work + (s32)enableIndex * 4;
                effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
                ((CmbCardEffect *)effectWork)->flags.value |= 2;
                enableIndex++;
            }
            ((CmbCardController *)work)->layout = 9;
        }
        break;
    case 9:
        if (evtGetEventFrame() >= 0x1EA) {
            convergeIndex = 0;
            while (convergeIndex < 5) {
                cmbSetMove(task, convergeIndex, ((CmbCardSlot *)(work + (s32)convergeIndex * 0x84 + 0xC))->position, fclMakeVec2(323.0f, 217.0f), 3);
                effectSlot = work + (s32)convergeIndex * 4;
                updatedSlotBase = effectSlot + 0x658;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)updatedSlotBase);
                cmbCardEffSetPosition(*(u8 **)updatedSlotBase, ((CmbCardEffect *)effectWork)->position, fclMakeVec2(339.0f, 217.0f), 3);
                convergeIndex++;
            }
            ((CmbCardController *)work)->layout = 10;
        }
        break;
    case 10:
        ((CmbCardController *)work)->hideSecondary = 1;
        fadeIndex = 0;
        while (fadeIndex < 5) {
            cmbSetColor(task, fadeIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)fadeIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            fadeIndex++;
        }
        ((CmbCardController *)work)->layout = 11;
        break;
    case 11:
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        break;
    case 12:
        ((CmbCardController *)work)->phase += 1;
        break;
    }
    return 1;
}

// Six-card layout: card-layout state machine for six cards (dispatcher phase 5). States as in cmbCardRunTwoCardLayout. Returns 0 when blocked or skipped by flag 0x58, else 1.
// FUN_00343CF0
s32 cmbCardRunSixCardLayout(u8 *task) {
    /* measured: the initial layout read stays raw; typing that single read loses MATCH. Task reads retain the inline setters' byte-alias scope. */
    u8 *effectWork;
    u8 *effectSlot;
    u8 *effectTableBase;
    u8 *slotBase;
    u8 *updatedSlotBase;
    u8 *work;
    s16 state;
    s8 hideIndex;
    s8 setupIndex;
    s8 enableIndex;
    s8 convergeIndex;
    s8 fadeIndex;
    s32 index;
    s32 index2;
    f32 coordinate;

    work = *(u8 **)(task + 0x38);
    if (((CmbCardSlot *)(work + 0xC))->flags != 0 || ((CmbCardController *)work)->cards[1].flags != 0 || ((CmbCardController *)work)->cards[2].flags != 0 || ((CmbCardController *)work)->cards[3].flags != 0 || ((CmbCardController *)work)->cards[4].flags != 0 || ((CmbCardController *)work)->cards[5].flags != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        ((CmbCardController *)work)->hideSecondary = 1;
        hideIndex = 0;
        while (hideIndex < 6) {
            cmbSetColor(task, hideIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)hideIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            hideIndex++;
        }
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(work + 0x63C);
    switch (state) {
    case 0:
        if (evtGetEventFrame() >= 0x50) {
            cmbSetMove(task, 0, fclMakeVec2(421.0f, -43.0f), fclMakeVec2(321.0f, 70.0f), 4);
            cmbSetColor(task, 0, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbSetMove(task, 1, fclMakeVec2(421.0f, -43.0f), fclMakeVec2(321.0f, 70.0f), 4);
            cmbSetColor(task, 1, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(task, 1, fclMakeVec2(186.0f, 143.0f), 4);
            cmbSetMove(task, 2, fclMakeVec2(421.0f, -43.0f), fclMakeVec2(321.0f, 70.0f), 4);
            cmbSetColor(task, 2, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(task, 2, fclMakeVec2(186.0f, 143.0f), 4);
            cmbAddPath(task, 2, fclMakeVec2(186.0f, 285.0f), 4);
            cmbSetMove(task, 3, fclMakeVec2(421.0f, -43.0f), fclMakeVec2(321.0f, 70.0f), 4);
            cmbSetColor(task, 3, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(task, 3, fclMakeVec2(186.0f, 143.0f), 4);
            cmbAddPath(task, 3, fclMakeVec2(186.0f, 285.0f), 4);
            cmbAddPath(task, 3, fclMakeVec2(321.0f, 348.0f), 4);
            cmbSetMove(task, 4, fclMakeVec2(421.0f, -43.0f), fclMakeVec2(321.0f, 70.0f), 4);
            cmbSetColor(task, 4, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(task, 4, fclMakeVec2(186.0f, 143.0f), 4);
            cmbAddPath(task, 4, fclMakeVec2(186.0f, 285.0f), 4);
            cmbAddPath(task, 4, fclMakeVec2(321.0f, 348.0f), 4);
            cmbAddPath(task, 4, fclMakeVec2(456.0f, 285.0f), 4);
            cmbSetMove(task, 5, fclMakeVec2(421.0f, -43.0f), fclMakeVec2(321.0f, 70.0f), 4);
            cmbSetColor(task, 5, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(task, 5, fclMakeVec2(186.0f, 143.0f), 4);
            cmbAddPath(task, 5, fclMakeVec2(186.0f, 285.0f), 4);
            cmbAddPath(task, 5, fclMakeVec2(321.0f, 348.0f), 4);
            cmbAddPath(task, 5, fclMakeVec2(456.0f, 285.0f), 4);
            cmbAddPath(task, 5, fclMakeVec2(456.0f, 143.0f), 4);
            ((CmbCardController *)work)->layout = 6;
        }
        break;
    case 6:
        if (evtGetEventFrame() >= 0x73) {
            setupIndex = 0;
            while (setupIndex < 6) {
                slotBase = *(u8 **)(task + 0x38);
                slotBase += (s32)setupIndex * 0x84;
                ((CmbCardSlot *)(slotBase + 0xC))->angle = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleStart = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleEnd = -180.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleFrame = 0;
                ((CmbCardSlot *)(slotBase + 0xC))->angleDuration = 3;
                ((CmbCardSlot *)(slotBase + 0xC))->flags |= 2;
                effectTableBase = work + (s32)setupIndex * 4;
                updatedSlotBase = work + (s32)setupIndex * 0x84;
                effectSlot = effectTableBase + 0x658;
                coordinate = ((CmbCardSlot *)(updatedSlotBase + 0xC))->position.x + 16.0f;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.x = coordinate;
                coordinate = ((CmbCardSlot *)(updatedSlotBase + 0xC))->position.y;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.y = coordinate;
                cmbCardEffSetParams(*(u8 **)effectSlot, 0, 0x80, 0x32);
                setupIndex++;
            }
            ((CmbCardController *)work)->layout = 7;
        }
        break;
    case 7:
        sdkSndStartChannel(2, D_0064A5B0);
        cmbCardEffSpawnSprite(((CmbCardController *)work)->loadGate, fclMakeVec3(0.0f, 5.0f, 30.0f), 0.0f, 0.0f, 0.0f, 1.5f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
        ((CmbCardController *)work)->layout = 8;
        /* fallthrough */
    case 8:
        if (kwlnTaskIsLinked(((CmbCardController *)work)->loadGate) != 1) {
            enableIndex = 0;
            while (enableIndex < 6) {
                effectSlot = work + (s32)enableIndex * 4;
                effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
                ((CmbCardEffect *)effectWork)->flags.value |= 2;
                enableIndex++;
            }
            ((CmbCardController *)work)->layout = 9;
        }
        break;
    case 9:
        if (evtGetEventFrame() >= 0x1EA) {
            convergeIndex = 0;
            while (convergeIndex < 6) {
                cmbSetMove(task, convergeIndex, ((CmbCardSlot *)(work + (s32)convergeIndex * 0x84 + 0xC))->position, fclMakeVec2(323.0f, 217.0f), 3);
                effectSlot = work + (s32)convergeIndex * 4;
                updatedSlotBase = effectSlot + 0x658;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)updatedSlotBase);
                cmbCardEffSetPosition(*(u8 **)updatedSlotBase, ((CmbCardEffect *)effectWork)->position, fclMakeVec2(339.0f, 217.0f), 3);
                convergeIndex++;
            }
            ((CmbCardController *)work)->layout = 10;
        }
        break;
    case 10:
        ((CmbCardController *)work)->hideSecondary = 1;
        fadeIndex = 0;
        while (fadeIndex < 6) {
            cmbSetColor(task, fadeIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)fadeIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            fadeIndex++;
        }
        ((CmbCardController *)work)->layout = 11;
        break;
    case 11:
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        break;
    case 12:
        ((CmbCardController *)work)->phase += 1;
        break;
    }
    return 1;
}

/* Each of the twelve cards shares the native move, color and path
 * operations used by the smaller combination layouts. */
// Full layout: card-layout state machine for all twelve card slots (dispatcher phase 6). Same states as the smaller layouts (0 slide start at frame 0x50, 6 slot init at 0x73, 7 spawn effect, 8 wait, 9 converge at 0x1EA, 10 clear colour, 11 cue at 0x208-0x347). Returns 0 when blocked or skipped by flag 0x58, else 1.
// FUN_00345700
s32 cmbCardRunFullLayout(u8 *task) {
    /* measured: the initial layout read stays raw; typing that single read loses MATCH. Task reads retain the inline setters' byte-alias scope. */
    u8 *effectWork;
    u8 *effectTableBase;
    u8 *effectSlot;
    u8 *slotBase;
    u8 *work;
    s16 state;
    s8 hideIndex;
    s8 setupIndex;
    s8 enableIndex;
    s8 convergeIndex;
    s8 fadeIndex;
    s32 index;
    s32 value;
    f32 coordinate;

    work = *(u8 **)(task + 0x38);
    if (((CmbCardSlot *)(work + 0xC))->flags != 0 || ((CmbCardController *)work)->cards[1].flags != 0 || ((CmbCardController *)work)->cards[2].flags != 0 || ((CmbCardController *)work)->cards[3].flags != 0 || ((CmbCardController *)work)->cards[4].flags != 0 || ((CmbCardController *)work)->cards[5].flags != 0 || ((CmbCardController *)work)->cards[6].flags != 0 || ((CmbCardController *)work)->cards[7].flags != 0 || ((CmbCardController *)work)->cards[8].flags != 0 || ((CmbCardController *)work)->cards[9].flags != 0 || ((CmbCardController *)work)->cards[10].flags != 0 || ((CmbCardController *)work)->cards[11].flags != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        ((CmbCardController *)work)->hideSecondary = 1;
        hideIndex = 0;
        while (hideIndex < 12) {
            cmbSetColor(task, hideIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)hideIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            hideIndex++;
        }
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(work + 0x63C);
    switch (state) {
    case 0:
        if (evtGetEventFrame() >= 0x50) {
            cmbSetMove(task, 0, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(0x141, 70.0f), 8);
            cmbSetColor(task, 0, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbSetMove(task, 1, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(0x141, 70.0f), 8);
            cmbSetColor(task, 1, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(task, 1, fclMakeVec2(250.0f, 95.0f), 5);
            cmbSetMove(task, 2, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(0x141, 70.0f), 8);
            cmbSetColor(task, 2, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(task, 2, fclMakeVec2(250.0f, 95.0f), 5);
            cmbAddPath(task, 2, fclMakeVec2(175.0f, 141.0f), 5);
            cmbSetMove(task, 3, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(156.0f, 232.0f), 8);
            cmbSetColor(task, 3, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbSetMove(task, 4, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(156.0f, 232.0f), 8);
            cmbSetColor(task, 4, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(task, 4, fclMakeVec2(180.0f, 322.0f), 5);
            cmbSetMove(task, 5, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(156.0f, 232.0f), 8);
            cmbSetColor(task, 5, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(task, 5, fclMakeVec2(180.0f, 322.0f), 5);
            cmbAddPath(task, 5, fclMakeVec2(250.0f, 0x16B), 5);
            cmbSetMove(task, 6, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(0x141, 388.0f), 8);
            cmbSetColor(task, 6, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbSetMove(task, 7, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(0x141, 388.0f), 8);
            cmbSetColor(task, 7, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(task, 7, fclMakeVec2(0x187, 0x16B), 5);
            cmbSetMove(task, 8, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(0x141, 388.0f), 8);
            cmbSetColor(task, 8, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(task, 8, fclMakeVec2(0x187, 0x16B), 5);
            cmbAddPath(task, 8, fclMakeVec2(458.0f, 322.0f), 5);
            cmbSetMove(task, 9, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(482.0f, 232.0f), 8);
            cmbSetColor(task, 9, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbSetMove(task, 10, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(482.0f, 232.0f), 8);
            cmbSetColor(task, 10, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(task, 10, fclMakeVec2(462.0f, 141.0f), 5);
            cmbSetMove(task, 11, fclMakeVec2(326.0f, 224.0f), fclMakeVec2(482.0f, 232.0f), 8);
            cmbSetColor(task, 11, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(task, 11, fclMakeVec2(462.0f, 141.0f), 5);
            cmbAddPath(task, 11, fclMakeVec2(0x187, 95.0f), 5);
            ((CmbCardController *)work)->layout = 6;
        }
        break;
    case 6:
        if (evtGetEventFrame() >= 0x73) {
            setupIndex = 0;
            while (setupIndex < 12) {
                slotBase = *(u8 **)(task + 0x38);
                slotBase += (s32)setupIndex * 0x84;
                ((CmbCardSlot *)(slotBase + 0xC))->angle = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleStart = 0.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleEnd = -180.0f;
                ((CmbCardSlot *)(slotBase + 0xC))->angleFrame = 0;
                ((CmbCardSlot *)(slotBase + 0xC))->angleDuration = 3;
                ((CmbCardSlot *)(slotBase + 0xC))->flags |= 2;
                effectTableBase = work + (s32)setupIndex * 4;
                slotBase = work + (s32)setupIndex * 0x84;
                effectSlot = effectTableBase + 0x658;
                coordinate = ((CmbCardSlot *)(slotBase + 0xC))->position.x + 12.0f;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.x = coordinate;
                coordinate = ((CmbCardSlot *)(slotBase + 0xC))->position.y;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->position.y = coordinate;
                cmbCardEffSetParams(*(u8 **)effectSlot, 0, 0x80, 0x32);
                coordinate = iGpffff8508;
                effectWork = (u8 *)cmbCardEffState(*(u8 **)effectSlot);
                ((CmbCardEffect *)effectWork)->scale.value = coordinate;
                setupIndex++;
            }
            ((CmbCardController *)work)->layout = 7;
        }
        break;
    case 7:
        sdkSndStartChannel(2, D_0064A5B0);
        cmbCardEffSetTween(((CmbCardController *)work)->loadGate,
                      fclMakeVec3(0.0f, -5.0f, 30.0f),
                      0.0f, 0.0f, 0.0f, iGpffff850c,
                      fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28,
                      fclMakeVec3(35.0f, 5.0f, 30.0f),
                      0.0f, 0.0f, 31.5f, iGpffff850c,
                      fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU));
        ((CmbCardController *)work)->layout = 8;
    case 8:
        if (kwlnTaskIsLinked(((CmbCardController *)work)->loadGate) != 1) {
            enableIndex = 0;
            while (enableIndex < 12) {
                effectSlot = work + (s32)enableIndex * 4;
                effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
                ((CmbCardEffect *)effectWork)->flags.value |= 2;
                enableIndex++;
            }
            ((CmbCardController *)work)->layout = 9;
        }
        break;
    case 9:
        if (evtGetEventFrame() >= 0x1EA) {
            convergeIndex = 0;
            while (convergeIndex < 12) {
                cmbSetMove(task, convergeIndex, ((CmbCardSlot *)(work + (s32)convergeIndex * 0x84 + 0xC))->position, fclMakeVec2(0x143, 217.0f), 3);
                effectSlot = work + (s32)convergeIndex * 4;
                slotBase = effectSlot + 0x658;
                effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
                cmbCardEffSetPosition(*(u8 **)slotBase, ((CmbCardEffect *)effectWork)->position, fclMakeVec2(0x153, 217.0f), 3);
                convergeIndex++;
            }
            ((CmbCardController *)work)->layout = 10;
        }
        break;
    case 10:
        ((CmbCardController *)work)->hideSecondary = 1;
        fadeIndex = 0;
        while (fadeIndex < 12) {
            cmbSetColor(task, fadeIndex, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFFU), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0U), 0);
            effectSlot = work + (s32)fadeIndex * 4;
            effectWork = (u8 *)cmbCardEffState(((CmbCardController *)effectSlot)->effectTasks[0].task);
            ((CmbCardEffect *)effectWork)->flags.value &= 0xFFFD;
            fadeIndex++;
        }
        ((CmbCardController *)work)->layout = 11;
        break;
    case 11:
        if (evtGetEventFrame() >= 0x208 && evtGetEventFrame() < 0x348) {
            datSetFlag(0x1450, 1);
        }
        break;
    case 12:
        ((CmbCardController *)work)->phase += 1;
        break;
    }
    return 1;
}

// FUN_00347940
/* Clear the twelve effect handles, then create the number required by the layout. */
void cmbCardClearSlots(u8 *task) {
    u8 *work;
    s16 cardIndex;

    work = ((SdkTask *)task)->work;
    for (cardIndex = 0; cardIndex < 0xC; cardIndex++) {
        ((CmbCardController *)work)->effectTasks[cardIndex].value = 0;
    }
    switch (((CmbCardController *)work)->nextPhase) {
    case 6:
        ((CmbCardController *)work)->effectTasks[6].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
        ((CmbCardController *)work)->effectTasks[7].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
        ((CmbCardController *)work)->effectTasks[8].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
        ((CmbCardController *)work)->effectTasks[9].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
        ((CmbCardController *)work)->effectTasks[10].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
        ((CmbCardController *)work)->effectTasks[11].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
    case 5:
        ((CmbCardController *)work)->effectTasks[5].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
    case 4:
        ((CmbCardController *)work)->effectTasks[4].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
    case 3:
        ((CmbCardController *)work)->effectTasks[3].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
    case 2:
        ((CmbCardController *)work)->effectTasks[2].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
    case 1:
        ((CmbCardController *)work)->effectTasks[0].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
        ((CmbCardController *)work)->effectTasks[1].bits = (u32)cmbCardEffTaskCreate(task, fclCombineGetCardTable());
        break;
    }
}

/* Set RenderWare draw states and the four corners' UV words, then bind the card texture. */
// FUN_00347B30
void cmbCardEffDrawStep(u8 *drawTask, u8 *vertices) {
    u32 renderStateTable = (u32)D_00887300;

    ((void (*)(s32, s32))*(u32 *)renderStateTable)(6, 1);
    ((void (*)(s32, s32))*(u32 *)renderStateTable)(7, 2);
    ((void (*)(s32, s32))*(u32 *)renderStateTable)(8, 1);
    ((void (*)(s32, s32))*(u32 *)renderStateTable)(9, 2);
    ((void (*)(s32, s32))*(u32 *)renderStateTable)(0xC, 1);
    ((void (*)(s32, s32))*(u32 *)renderStateTable)(2, 3);
    ((void (*)(s32, s32))*(u32 *)renderStateTable)(0xB, 6);
    ((void (*)(s32, s32))*(u32 *)renderStateTable)(0xA, 5);
    RpSkyRenderStateSet(2, 0x48);
    RpSkyRenderStateSet(3, 0x71801);
    ((CmbCardVertex *)(vertices + 0x10))->uBits = 0;
    ((CmbCardVertex *)(vertices + 0x10))->vBits = 0;
    ((CmbCardVertex *)(vertices + 0x50))->uBits = 0x3F800000;
    ((CmbCardVertex *)(vertices + 0x50))->vBits = 0;
    ((CmbCardVertex *)(vertices + 0x90))->uBits = 0;
    ((CmbCardVertex *)(vertices + 0x90))->vBits = 0x3F800000;
    ((CmbCardVertex *)(vertices + 0xD0))->uBits = 0x3F800000;
    ((CmbCardVertex *)(vertices + 0xD0))->vBits = 0x3F800000;
    ((void (*)(s32, s32))*(u32 *)renderStateTable)(1, *fclCombineGetCardTable());
}

/* Update the enabled card quad, queue its draw packet, then advance position
 * and alpha animation. The enable bit gates the entire update after the camera
 * read. The four-vertex index copy retains the signed-halfword loop domain.
 *
 * Native b210 -O2: 1204/1216 bytes, with a verified 12-byte zero suffix.
 * Loop invariants retain the depth-symbol base; propagation is disabled so the
 * camera result, first scale read and packet arguments keep retail's order.
 * Recovery history and full relocation/sibling proof:
 * docs/probe_archive/yCmb_00347c70_recovery_20260922.md. */
// Renders the enabled card quads: updates each quad from the camera depth, then queues its draw packet [inferred].
// FUN_00347C70
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
s32 cmbCardEffRenderTask(u8 *task)
{
    /* measured: the remaining raw flags, position and timer accesses fail individual typed substitutions; keep their alias/evaluation scope. */
    u8 *work;
    f32 reciprocalDepth;
    u8 *vertex;
    s16 index;
    s64 wideIndex;
    f32 depth;
    f32 scale;
    u8 *camera;

    work = ((SdkTask *)task)->work;
    camera = (u8 *)(u32)kwlnGetCamera();
    reciprocalDepth = 1.0f / ((CmbCardCamera *)camera)->depth;
    if (((( *(s32 *)(work + 0x11C) & 2) >> 1) == 1)) {
        for (index = 0; index < 4; index++) {
            wideIndex = index;
            vertex = work;
            vertex = (u8 *)((u32)vertex + ((u32)wideIndex << 6));
            depth = *(f32 *)D_008872F8;
            ((CmbCardVertex *)(vertex + 0x10))->z = depth - 1.0f;
            ((CmbCardVertex *)(vertex + 0x10))->reciprocalDepth = reciprocalDepth;
            ((CmbCardVertex *)(vertex + 0x10))->red = (f32)((CmbCardEffect *)work)->colors[2].c0;
            ((CmbCardVertex *)(vertex + 0x10))->green = (f32)((CmbCardEffect *)work)->colors[2].c1;
            ((CmbCardVertex *)(vertex + 0x10))->blue = (f32)((CmbCardEffect *)work)->colors[2].c2;
            ((CmbCardVertex *)(vertex + 0x10))->alpha = (f32)((CmbCardEffect *)work)->colors[2].c3;
        }
        /* Four corners of a square with an unscaled half-width of 64. */
        scale = ((CmbCardEffect *)work)->scale.value;
        ((CmbCardVertex *)(work + 0x10))->x = *(f32 *)(work + 0x134) - 64.0f * scale;
        ((CmbCardVertex *)(work + 0x10))->y = *(f32 *)(work + 0x138) - 64.0f * ((CmbCardEffect *)work)->scale.value;
        ((CmbCardVertex *)(work + 0x50))->x = *(f32 *)(work + 0x134) + 64.0f * ((CmbCardEffect *)work)->scale.value;
        ((CmbCardVertex *)(work + 0x50))->y = *(f32 *)(work + 0x138) - 64.0f * ((CmbCardEffect *)work)->scale.value;
        ((CmbCardVertex *)(work + 0x90))->x = *(f32 *)(work + 0x134) - 64.0f * ((CmbCardEffect *)work)->scale.value;
        ((CmbCardVertex *)(work + 0x90))->y = *(f32 *)(work + 0x138) + 64.0f * ((CmbCardEffect *)work)->scale.value;
        ((CmbCardVertex *)(work + 0xD0))->x = *(f32 *)(work + 0x134) + 64.0f * ((CmbCardEffect *)work)->scale.value;
        ((CmbCardVertex *)(work + 0xD0))->y = *(f32 *)(work + 0x138) + 64.0f * ((CmbCardEffect *)work)->scale.value;
        if (evtGetEventFrame() < 0x208) {
            u8 *list;
            s32 primitive;
            void *vertices;
            s32 count;
            u8 *alloc;
            list = D_00794F00;
            primitive = 4;
            vertices = work + 0x10;
            count = primitive;
            alloc = PrimQueueDrawPrimitive(list, primitive, vertices, count);
            ((CmbCardDrawPacket *)alloc)->draw = (void *)cmbCardEffDrawStep;
            ((CmbCardDrawPacket *)alloc)->work = work;
        }
        if (((( *(s32 *)(work + 0x11C) & 4) >> 2) == 1)) {
            f32 elapsed = (f32)*(s16 *)(work + 0x13E);
            f32 duration = (f32)*(s16 *)(work + 0x13C);
            ((CmbCardEffect *)work)->position.x = fclEaseInterpolate(0, ((CmbCardEffect *)work)->startPosition.x, ((CmbCardEffect *)work)->endPosition.x, elapsed, duration);
            elapsed = (f32)*(s16 *)(work + 0x13E);
            duration = (f32)((CmbCardEffect *)work)->moveDuration.value;
            ((CmbCardEffect *)work)->position.y = fclEaseInterpolate(0, ((CmbCardEffect *)work)->startPosition.y, ((CmbCardEffect *)work)->endPosition.y, elapsed, duration);
            if (((CmbCardEffect *)work)->moveFrame.value < *(s16 *)(work + 0x13C)) {
                *(s16 *)(work + 0x13E) = fclAddClamped(((CmbCardEffect *)work)->moveFrame.value, 1, *(s16 *)(work + 0x13C), 0, 1);
            } else {
                ((CmbCardEffect *)work)->flags.value &= 0xFFFB;
            }
        }
        if (((( ((CmbCardEffect *)work)->flags.value & 0x10) >> 4) == 1)) {
            f32 startAlpha = (f32)((CmbCardEffect *)work)->colors[0].c3;
            f32 endAlpha = (f32)((CmbCardEffect *)work)->colors[1].c3;
            f32 elapsed = (f32)*(s16 *)(work + 0x19C);
            f32 duration = (f32)(((CmbCardEffect *)work)->alphaDuration.value / 2);
            f32 alphaValue = fclEaseInterpolate(1, startAlpha, endAlpha, elapsed, duration);
            ((CmbCardEffect *)work)->colors[2].c3 = (u8)alphaValue;
            if (*(s16 *)(work + 0x19C) < *(s16 *)(work + 0x19E)) {
                *(s16 *)(work + 0x19C) = fclAddClamped(((CmbCardEffect *)work)->alphaFrame.value, 1, *(s16 *)(work + 0x19E), 0, 1);
            } else {
                ((CmbCardEffect *)work)->alphaFrame.value = 0;
            }
        }
    }
    return 0;
}
#pragma pop
/* Effect task destructor: forwards the state block to jump-table slot 0. */
// FUN_00348130
void cmbCardEffDestroy(u8 *task) {
    jtbl_008873EC[0](((SdkTask *)task)->work);
}



/* Create a card-quad task with its texture, three white colors and unit scale. */
// FUN_00348160
u8 *cmbCardEffTaskCreate(u8 *parent, s32 *texture) {
    FclDrawColor color;
    u8 *task;
    u8 *work;
    s16 colorIndex;

    chkmemAllocSiteTag(D_0064A4A0, 0x702);
    work = D_008873F4[0](1, 0x1B0, 0x40000);
    task = (u8 *)(s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064A5D0), 0xF, 0, 0, cmbCardEffRenderTask, cmbCardEffDestroy, (u8 *)(work));
    ((CmbCardEffect *)work)->texture = texture;
    ((CmbCardEffect *)work)->flags.value = 0;
    for (colorIndex = 0; colorIndex < 3; colorIndex++) {
        color = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        ((CmbCardEffect *)work)->colors[colorIndex] = color;
    }
    ((CmbCardEffect *)work)->scale.bits = 0x3F800000;
    return task;
}

/* Returns the effect's state block (task +0x38). */
// FUN_00348290
void *cmbCardEffState(u8 *task) {
    return ((SdkTask *)task)->work;
}

/* Enable alpha pulsing (flag 0x10), set the endpoints and duration, and reset its frame. */
// FUN_003482A0
void cmbCardEffSetParams(u8 *task, u8 startAlpha, u8 endAlpha, u16 duration) {
    u8 *work = ((SdkTask *)task)->work;
    ((CmbCardEffect *)work)->flags.bits |= 0x10;
    ((CmbCardEffect *)work)->colors[2].c3 = startAlpha;
    ((CmbCardEffect *)work)->colors[0].c3 = startAlpha;
    ((CmbCardEffect *)work)->colors[1].c3 = endAlpha;
    ((CmbCardEffect *)work)->alphaFrame.bits = 0;
    ((CmbCardEffect *)work)->alphaDuration.bits = duration;
}

/* Enable movement (flag 4) and initialize the current/start/target positions and timer. */
// FUN_003482D0
void cmbCardEffSetPosition(u8 *task, CmbVec2f startPosition, CmbVec2f endPosition, u16 duration) {
    u8 *work = ((SdkTask *)task)->work;
    ((CmbCardEffect *)work)->flags.bits |= 4;
    ((CmbCardEffect *)work)->position = startPosition;
    ((CmbCardEffect *)work)->startPosition = ((CmbCardEffect *)work)->position;
    ((CmbCardEffect *)work)->endPosition = endPosition;
    ((CmbCardEffect *)work)->moveFrame.bits = 0;
    ((CmbCardEffect *)work)->moveDuration.bits = duration;
}

/* measured: nd 15, obj 1296B = window (323 instrs both) — dispatch (lb 0x4, beq 3,2,1 + beqz 0 + b default), 004553c0/004b11xx/002b2d00 branches and float loads all match; EVERYTHING matches except the guarded-conversion result register: three `if (2.1474836e9f > f0) { v = (s32)f0; v &= 0xFF; } else { v = (s32)(f0-K)|0x80000000; v &= 0xFF; }` keep b210 mfc1/or/sb in $v0 where retail coalesces into $v1 (3 sites x 5 = 15 words; tried u8 locals, f0/v order, inline stores — no shift, same family as cmmScriptStepWaveSprite). Recipe (correct-tree, top-down fnalign): outer switch cases 0,1,2,3 ascending (reverse beq chain 3,2,1,0+beqz) with case0/default break-shared to single return 0 (explicit return 0 in case1/2 regresses to 275; order 1,0,2,3 regresses dispatch to 39); inner 0x39 3-way if/else-if (x==0/1/2) reusing $a1=2; D_005DC7D0 indexed `&D_005DC7D0[idx*0x54]` (reloc-only); half via `h/2` (manual sra+bgez keeps $v0/$v1 swap, 29); nv via reload `*(s16*)=func...; if (*(s16*)<...)` (nv-local + explicit (s32)(s16) cast mis-schedules sh, 18). func_004553c0 takes ONE arg (m2c 2nd arg wrong); guard must be `2.1474836e9f > f0` with normal-first to keep c.le.s/bc1t + per-arm andi. Path 275->39->29->18->15. Production stays ASM. */
/* measured: nd 16, obj 1292B vs 1296B window — EVERYTHING matches byte-for-byte
   except the guarded-conversion result register: the three
   `if (2.1474836e9f > f0) { v = (u8)(s32)f0; } else { v = (u8)((s32)(f0-2.1474836e9f)|0x80000000); }`
   chains (explicit guard needed — implicit (u8)(s32) deletes the c.ole.s/bc1t guard
   AND the per-arm andi) keep b210's mfc1/or/sb chain in $v0 where retail coalesces
   into $v1 (3 sites x 5 words; tried u8 locals, f0/v declaration orders, inline
   stores — no shift). Same family as cmmScriptStepWaveSprite's conversion-coloring
   floor. Also measured: outer state switch needs cases declared 0,1,2,3 ascending
   (reversed beq chain 3,2,1,0 + beqz); inner 0x39 dispatch is a 3-way if/else-if
   chain (x==0 / x==1 / x==2) whose x==2 test reuses the dispatch's $a1=2 constant;
   D_005DC7D0 must be indexed (`&D_005DC7D0[idx*0x54]`) or b210 hoists the base into
   a saved reg and rotates obj to $s1. All verified against this function's retail.
   Re-measured this wave: two fresh m2c-draft-based reconstructions (285, then the
   same with 3-way if/else-if dispatch + indexed D_005DC7D0, 279) both far above
   the recorded 16 — the exact winning recipe is not recoverable from the
   truncated note; confirmed func_004553c0 takes ONE arg (the m2c draft's 2nd arg
   is wrong), and the gated conversion needs the explicit `2.1474836e9f > f0`
   guard to keep the c.ole.s/bc1t + per-arm andi. 16 remains the measured best. */
/* measured 2026-09-17 full pragma_sweep --pairs: banked 15 via measure_guarded; */
/* best stays 15 (ties: loopinv on, strength off, unroll off and pairs; 26-group */
/* prop/dead pairs; 234-235 csoff group, 277-281 schedule group, 310-331 peephole */
/* group). No pair wins; floor stands. */
/* MATCHED 2026-09-18.  The three `*(u8 *)(obj + 0x38) = ...` sites had the
   float-to-unsigned-byte conversion written out by hand (compare against
   2.1474836e9f, subtract, or in 0x80000000, mask).  b210 generates exactly
   that sequence for a plain `(u8)f0` cast, and its own version colours the
   result $v1 with the constant in $v0 - the hand-written form does the
   reverse, which was the whole 15-word residual.  Writing the cast fixes all
   three at once; fixing only the two shallow sites leaves 5. */
/* Load/create the primary effect and optional clone, animate alpha, then finish at the lifetime limit. */
// FUN_00348330
s32 cmbCardEffSpriteTaskUpdate(u8 *task) {
    /* measured: the remaining raw state, handle and timer accesses fail individual typed substitutions. */
    u8 *work = ((SdkTask *)task)->work;
    switch (*(s8 *)(work + 4)) {
    case 0:
        break;
    case 1: {
        if (H_Cdvd_IsFileLoaded((HCdvd *)((CmbCardSprite *)work)->file) == 0) {
            return 0;
        }
        {
            u8 *effect = *(u8 **)(work + 8);
            if (effect != 0) {
                mdlEffectDestroy(effect);
                ((CmbCardSprite *)work)->effect = 0;
            }
        }
        {
            u8 *effect = mdlEffectCreateFromResource((s32)((HCdvd *)((CmbCardSprite *)work)->file)->fileMemory);
            *(u8 **)(work + 8) = effect;
            mdlEffectSetChildPositionVec(effect, work + 0x18);
            mdlEffectSetEulerRotation(*(u8 **)(work + 8), ((CmbCardSprite *)work)->rotationX, ((CmbCardSprite *)work)->rotationY, ((CmbCardSprite *)work)->rotationZ);
            mdlEffectSetUniformScale(*(u8 **)(work + 8), ((CmbCardSprite *)work)->scale);
            mdlEffectSetPackedColor(*(u8 **)(work + 8), work + 0x34);
            if (((CmbCardSprite *)work)->hasClone == 1) {
                u8 *clone = mdlEffectClone(((CmbCardSprite *)work)->effect);
                *(u8 **)(work + 0x44) = clone;
                mdlEffectSetChildPositionVec(clone, work + 0x4C);
                mdlEffectSetEulerRotation(*(u8 **)(work + 0x44), ((CmbCardSprite *)work)->cloneRotationX, ((CmbCardSprite *)work)->cloneRotationY, ((CmbCardSprite *)work)->cloneRotationZ);
                mdlEffectSetUniformScale(*(u8 **)(work + 0x44), ((CmbCardSprite *)work)->cloneScale);
                mdlEffectSetPackedColor(((CmbCardSprite *)work)->clone, work + 0x68);
            }
        }
        ((CmbCardSprite *)work)->lifetimeFrame.bits = 0;
        ((CmbCardSprite *)work)->state += 1;
        break;
    }
    case 2: {
        s16 delay = *(s16 *)(work + 0x3E);
        if (delay > 0) {
            ((CmbCardSprite *)work)->delay.value = fclSubClamped(delay, 1, 0, 0, 1);
            return 0;
        }
        {
            u8 mode = ((CmbCardSprite *)work)->alphaMode;
            if (mode == 0) {
                f32 alphaValue = fclEaseInterpolate(0, 0.0f, ((CmbCardSprite *)work)->maxAlpha.value, (f32)((CmbCardSprite *)work)->alphaFrame.value, (f32)((CmbCardSprite *)work)->alphaDuration.value);
                ((CmbCardSprite *)work)->alpha = (u8)alphaValue;
            } else if (mode == 1) {
                f32 alphaValue = fclEaseInterpolate(0, ((CmbCardSprite *)work)->maxAlpha.value, 0.0f, (f32)*(s16 *)(work + 0x3C), (f32)*(s16 *)(work + 0x3A));
                ((CmbCardSprite *)work)->alpha = (u8)alphaValue;
                if (((CmbCardSprite *)work)->alphaFrame.value >= ((CmbCardSprite *)work)->alphaDuration.value) {
                    ((CmbCardSprite *)work)->state = 3;
                }
            } else if (mode == 2) {
                s16 alphaDuration = ((CmbCardSprite *)work)->alphaDuration.value;
                s32 halfDuration = alphaDuration / 2;
                {
                    f32 alphaValue = fclEaseInterpolate(1, 0.0f, 255.0f, (f32)((CmbCardSprite *)work)->alphaFrame.value, (f32)halfDuration);
                    ((CmbCardSprite *)work)->alpha = (u8)alphaValue;
                }
            }
        }
        {
            *(s16 *)(work + 0x3C) = fclAddClamped(*(s16 *)(work + 0x3C), 1, *(s16 *)(work + 0x3A), 0, 1);
            if (((CmbCardSprite *)work)->alphaFrame.value < ((CmbCardSprite *)work)->alphaDuration.value) {
                ((CmbCardSprite *)work)->color.c3 = *(u8 *)(work + 0x38);
                mdlEffectSetPackedColor(((CmbCardSprite *)work)->effect, work + 0x34);
                if (((CmbCardSprite *)work)->hasClone == 1) {
                    ((CmbCardSprite *)work)->cloneColor.c3 = ((CmbCardSprite *)work)->alpha;
                    mdlEffectSetPackedColor(((CmbCardSprite *)work)->clone, work + 0x68);
                }
            }
        }
        mdlEffectCommitAndAdvance(*(u8 **)(work + 8));
        mdlEffectFlushWithTable(&D_005DC7D0[*(u8 *)(work + 0x14) * 0x54], *(u8 **)(work + 8));
        if (((CmbCardSprite *)work)->hasClone == 1) {
            mdlEffectCommitAndAdvance(*(u8 **)(work + 0x44));
            mdlEffectFlushWithTable(&D_005DC7D0[((CmbCardSprite *)work)->drawOrder * 0x54], ((CmbCardSprite *)work)->clone);
        }
        {
            s32 lifetime = *(s32 *)(work + 0x10);
            if (lifetime == -1) {
                if (mdlEffectIsFinished(((CmbCardSprite *)work)->effect) == 0) {
                    ((CmbCardSprite *)work)->state = 3;
                }
            } else {
                *(u16 *)(work + 0xC) = fclAddClamped(*(u16 *)(work + 0xC), 1, lifetime, 0, 1);
                if (((CmbCardSprite *)work)->lifetimeFrame.bits >= ((CmbCardSprite *)work)->lifetime.value) {
                    ((CmbCardSprite *)work)->state = 3;
                }
            }
        }
        break;
    }
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}
// FUN_00348840
/* Frees the handle stored at state+0x8, if any. */
void cmbCardEffFreeHandle(u8 *task) {
    /* measured: handle reads and the final task reload stay raw across destruction; the handle-clearing stores are typed. */
    u8 *work = ((SdkTask *)task)->work;
    u8 *effect = *(u8 **)(work + 8);
    if (effect != 0) {
        mdlEffectDestroy(effect);
        ((CmbCardSprite *)work)->effect = 0;
    }
    if (((CmbCardSprite *)work)->hasClone == 1) {
        u8 *clone = *(u8 **)(work + 0x44);
        if (clone != 0) {
            mdlEffectDestroy(clone);
            ((CmbCardSprite *)work)->clone = 0;
        }
    }
    H_Cdvd_Destroy((HCdvd *)((CmbCardSprite *)work)->file);
    jtbl_008873EC[0](*(u8 **)(task + 0x38));
}

// Creates a sprite task with a 0x70-byte state block and acquires the requested directory for it [inferred].
// FUN_003488D0
u8 *cmbCardEffCreateSprite(u8 *parent, u8 *directory, s8 drawOrder) {
    u8 *task;
    u8 *work;

    chkmemAllocSiteTag(D_0064A4A0, 0x7F5);
    work = D_008873F4[0](1, 0x70, 0x40000);
    task = (u8 *)(s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064A5E8), 0xF, 0, 0, cmbCardEffSpriteTaskUpdate, cmbCardEffFreeHandle, (u8 *)(work));
    ((CmbCardSprite *)work)->state = 0;
    ((CmbCardSprite *)work)->drawOrder = drawOrder;
    func_00440b68(D_00763A28, D_0064A4A0, 0x805);
    ((CmbCardSprite *)work)->file = H_Cdvd_AcquireDirectory(directory, 0);
    ((CmbCardSprite *)work)->maxAlpha.bits = 0x437F0000;
    return task;
}
// Starts a sprite: sets its state to 1 and stores its position, scale, colour and timing values [inferred].
// FUN_003489C0
void cmbCardEffSpawnSprite(u8 *task, CmbVec3f position, f32 rotationX, f32 rotationY, f32 rotationZ, f32 scale, CmbRGBA color, u16 duration, u32 lifetime) {
    CmbVec3f initialPosition = position;
    u8 *work = ((SdkTask *)task)->work;
    ((CmbCardSprite *)work)->state = 1;
    ((CmbCardSprite *)work)->position = initialPosition;
    ((CmbCardSprite *)work)->rotationX = rotationX;
    ((CmbCardSprite *)work)->rotationY = rotationY;
    ((CmbCardSprite *)work)->rotationZ = rotationZ;
    ((CmbCardSprite *)work)->scale = scale;
    ((CmbCardSprite *)work)->color = color;
    ((CmbCardSprite *)work)->maxAlpha.value = (f32)color.c3;
    ((CmbCardSprite *)work)->alphaFrame.bits = 0;
    ((CmbCardSprite *)work)->alphaDuration.bits = duration;
    ((CmbCardSprite *)work)->alphaMode = 0;
    ((CmbCardSprite *)work)->lifetime.bits = lifetime;
}

/* Start a primary model effect with a second transform/color for its optional clone. */
// FUN_00348A90
void cmbCardEffSetTween(u8 *task, CmbVec3f position, f32 rotationX, f32 rotationY, f32 rotationZ, f32 scale, CmbRGBA color, u16 duration, u32 lifetime, CmbVec3f clonePosition, f32 cloneRotationX, f32 cloneRotationY, f32 cloneRotationZ, f32 cloneScale, CmbRGBA cloneColor) {
    CmbVec3f initialPosition = position;
    CmbVec3f secondaryPosition = clonePosition;
    u8 *work = ((SdkTask *)task)->work;
    f32 colorBits = *(f32 *)&color;
    ((CmbCardSprite *)work)->state = 1;
    ((CmbCardSprite *)work)->position = initialPosition;
    ((CmbCardSprite *)work)->rotationX = rotationX;
    ((CmbCardSprite *)work)->rotationY = rotationY;
    ((CmbCardSprite *)work)->rotationZ = rotationZ;
    ((CmbCardSprite *)work)->scale = scale;
    ((CmbCardSprite *)work)->color = color;
    ((CmbCardSprite *)work)->maxAlpha.value = (f32)((u8 *)&colorBits)[3];
    ((CmbCardSprite *)work)->alphaFrame.bits = 0;
    ((CmbCardSprite *)work)->alphaDuration.bits = duration;
    ((CmbCardSprite *)work)->alphaMode = 0;
    ((CmbCardSprite *)work)->lifetime.bits = lifetime;
    ((CmbCardSprite *)work)->clonePosition = secondaryPosition;
    ((CmbCardSprite *)work)->cloneRotationX = cloneRotationX;
    ((CmbCardSprite *)work)->cloneRotationY = cloneRotationY;
    ((CmbCardSprite *)work)->cloneRotationZ = cloneRotationZ;
    ((CmbCardSprite *)work)->cloneScale = cloneScale;
    ((CmbCardSprite *)work)->cloneColor = cloneColor;
    ((CmbCardSprite *)work)->hasClone = 1;
}

// Returns 1 when the sprite's file is loaded, else 0 [inferred].
// FUN_00348BE0
s32 cmbCardEffSpriteFileLoaded(u8 *task) {
    return H_Cdvd_IsFileLoaded((HCdvd *)((CmbCardSprite *)((SdkTask *)task)->work)->file) != 0;
}

// Returns 1 when the sprite is in state 2 (active), else 0 [inferred].
// FUN_00348C10
u32 cmbCardEffSpriteIsActive(u8 *task) {
    return ((CmbCardSprite *)((SdkTask *)task)->work)->state == 2;
}
// Stores a 16-bit value in the sprite state's +0x3E field [inferred].
// FUN_00348C30
void cmbCardEffSetSpriteValue(u8 *task, u16 delay) {
    ((CmbCardSprite *)((SdkTask *)task)->work)->delay.bits = delay;
}

/* Build the channel gradient in its own value scope. This genuine inline
 * color constructor preserves the channel/base lifetimes without sharing the
 * controller's handle and index temporaries. */
static inline FclDrawColor cmbFiveSpriteColor(s32 base)
{
    u8 red;
    u8 green;
    u8 blue;
    red = fclAddClamped(base, 10, 0xFF, 0, 1) & 0xFF;
    green = fclAddClamped(base + 0x37, 10, 0xFF, 0, 1) & 0xFF;
    blue = fclAddClamped(base + 0xF2, 10, 0xFF, 0, 1) & 0xFF;
    return fclMakeDrawColor(red, green, blue, 0xFF);
}

/* Create five colored sprites and configure their bounds animations. The
 * final sprite's completion state controls this task's -1 completion return.
 * Native b210 -O2: 1560/1568 bytes plus eight verified zero alignment bytes.
 * Full source, contract and sibling proof:
 * docs/probe_archive/yCmb_angle_forwarding_20260922.md. */
// Five-sprite task: creates five colour sprites, colours them (gradient in mode 1, solid blue otherwise), sets their bounds, and returns -1 once the fifth sprite's state byte reaches 1.
// FUN_00348C40
#pragma push
s32 cmbFiveSpriteTask(u8 *task) {
    /* measured: typing the initial state read grows the owner image from 1560 to 1572 bytes; the state store and handle slots are typed. */
    s32 index;
    s32 *handleSlot;
    s32 *updatedHandleSlot;
    u8 *work;
    FclDrawColor gradientColor;
    FclDrawColor lastGradientColor;
    FclDrawColor solidColor;
    /* Initialize once, then wait for the fifth sprite to finish. */
    work = ((SdkTask *)task)->work;
    switch (*(s8 *)(work + 1)) {
    case 0:
        /* The task work owns five consecutive sprite handles. */
        index = 0;
        while (index < 5) {
            /* handle create: 465,0 -> 5c90 */
            handleSlot = (s32 *)(work + index * 4 + 4);
            *handleSlot = fclSpriteSpawnChild((s32)task, fclMakeVec2(0x1D1, 0.0f));
            /* vec: 9.0,480.0 -> 5db0 */
            fclSpriteSetPositionBounds((u8 *)*handleSlot, fclMakeVec2(0x1D1, 0.0f), fclMakeBoundsPacket(9.0f, 480.0f));
            /* Mode one uses a gradient; other modes use solid blue. */
            if (((CmbFiveSprites *)work)->colorMode == 1) {
                gradientColor = cmbFiveSpriteColor((index + 2) * 10);
                fclSpriteSetCornerColors((u8 *)*handleSlot, gradientColor);
                if (index == 4) {
                    lastGradientColor = cmbFiveSpriteColor((index + 1) * 10);
                    fclSpriteSetCornerColors((u8 *)*handleSlot, lastGradientColor);
                }
            } else {
                solidColor = fclMakeDrawColor(0, 0x37, 0xF2, 0xFF);
                fclSpriteSetCornerColors((u8 *)*handleSlot, solidColor);
            }
            /* Recompute the handle slot for flags and draw depth. */
            updatedHandleSlot = (s32 *)(work + (u32)index * 4U + 4);
            fclSpriteSetOrder((u8 *)*updatedHandleSlot, 0xBB);
            fclSpriteSetBaseScale((u8 *)*updatedHandleSlot, 50.0f);
            index++;
        }
        /* --- five post-loop 5fd0 groups --- */
        /* group offset 4: 465,275 + 8,480 + 380,480, last 0 */
        fclSpriteStartBoundsMoveFade((u8 *)((CmbFiveSprites *)work)->sprites[0], fclMakeVec2(0x1D1, 0.0f), fclMakeVec2(0x113, 0.0f),
                      fclMakeBoundsPacket(8.0f, 480.0f), fclMakeBoundsPacket(380.0f, 480.0f), 0xF, 0);
        /* group offset 8: same, last 2 */
        fclSpriteStartBoundsMoveFade((u8 *)((CmbFiveSprites *)work)->sprites[1], fclMakeVec2(0x1D1, 0.0f), fclMakeVec2(0x113, 0.0f),
                      fclMakeBoundsPacket(8.0f, 480.0f), fclMakeBoundsPacket(380.0f, 480.0f), 0xF, 2);
        /* group offset C: same, last 9 */
        fclSpriteStartBoundsMoveFade((u8 *)((CmbFiveSprites *)work)->sprites[2], fclMakeVec2(0x1D1, 0.0f), fclMakeVec2(0x113, 0.0f),
                      fclMakeBoundsPacket(8.0f, 480.0f), fclMakeBoundsPacket(380.0f, 480.0f), 0xF, 9);
        /* group offset 0x10: 8,480 + 8,480, last 9 */
        fclSpriteStartBoundsMoveFade((u8 *)((CmbFiveSprites *)work)->sprites[3], fclMakeVec2(0x1D1, 0.0f), fclMakeVec2(0x113, 0.0f),
                      fclMakeBoundsPacket(8.0f, 480.0f), fclMakeBoundsPacket(8.0f, 480.0f), 0xF, 9);
        /* group offset 0x14: 465,655 + 8,480 + 8,480, last 9 */
        fclSpriteStartBoundsMoveFade((u8 *)((CmbFiveSprites *)work)->sprites[4], fclMakeVec2(0x1D1, 0.0f), fclMakeVec2(0x28F, 0.0f),
                      fclMakeBoundsPacket(8.0f, 480.0f), fclMakeBoundsPacket(8.0f, 480.0f), 0xF, 9);
        ((CmbFiveSprites *)work)->state = 1;
        break;
    case 1:
        /* --- state-1 check: 5th handle via 5da0, -1 if byte==1 else 0 --- */
        if (*(s8 *)fclSpriteWorkAlt((u8 *)((CmbFiveSprites *)work)->sprites[4]) == 1) {
            return -1;
        }
        break;
    default:
        break;
    }
    return 0;
}

#pragma pop
// FUN_00349260
/* Releases the effect's state block through jump-table slot 0. */
void cmbCardEffReleaseState(u8 *task) {
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

extern u8 D_0064A600[];
s32 cmbFiveSpriteTask(u8 *task);

/* Create the five-sprite controller with the selected color mode and initial state. */
// FUN_00349290
u8 *cmbCardEffCreateTask(u8 *parent, s8 colorMode) {
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(D_0064A4A0, 0x8B9);
    work = D_008873F4[0](1, 0x18, 0x40000);
    task = (u8 *)(s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064A600), 0xF, 0, 0, cmbFiveSpriteTask, cmbCardEffReleaseState, (u8 *)(work));
    ((CmbFiveSprites *)work)->colorMode = colorMode;
    ((CmbFiveSprites *)work)->state = 0;
    return task;
}
