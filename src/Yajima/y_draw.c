#include "fcl_scale_transition.h"
/* Original translation unit y_draw.c (from __FILE__ assert strings). */
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "fcl_row_draw.h"
#include "type.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
#include "kwln_task_internal.h"
#include "rw_camera_internal.h"
#include "btl_ui_task_internal.h"
#include "member_access.h"

/* measured: retail sprite helpers are built with loop-invariant hoisting off and propagation on. */
#pragma opt_loop_invariants off
#pragma opt_propagation on

/* The five transition channels occupy 0xF0 bytes, copied as a unit by fclSpriteUpdateTweens
 * callers. */
typedef struct FclSpriteAnimation {
    s16 flags;
    u8 pad02[2];
    f32 depth;
    u8 pad08[0x10];
    FclVec2 positionStart;
    FclVec2 positionEnd;
    FclVec2 position;
    s16 positionDuration;
    s16 positionElapsed;
    s16 positionDelay;
    s8 positionMode;
    s8 positionReverse;
    u8 pad38[0x20];
    s16 alphaDuration;
    s16 alphaElapsed;
    u8 alphaStart;
    u8 alphaEnd;
    u8 alpha;
    u8 pad5F;
    s16 alphaDelay;
    s8 alphaMode;
    s8 alphaReverse;
    u8 pad64[9];
    FclDrawColor colorStart;
    FclDrawColor colorEnd;
    FclDrawColor color;
    u8 pad79;
    s16 colorDuration;
    s16 colorElapsed;
    s16 colorDelay;
    s8 colorMode;
    s8 colorReverse;
    s16 scaleDuration;
    s16 scaleElapsed;
    u8 pad86[2];
    union { f32 value; s32 bits; } scaleXStart;
    union { f32 value; s32 bits; } scaleXEnd;
    union { f32 value; s32 bits; } scaleX;
    union { f32 value; s32 bits; } scaleYStart;
    union { f32 value; s32 bits; } scaleYEnd;
    union { f32 value; s32 bits; } scaleY;
    s16 scaleDelay;
    s8 scaleMode;
    s8 scaleReverse;
    u8 padA4[0x14];
    union { f32 value; s32 bits; } valueStart;
    union { f32 value; s32 bits; } valueEnd;
    union { f32 value; s32 bits; } value;
    s16 valueElapsed;
    s16 valueDuration;
    s16 valueDelay;
    s8 valueMode;
    s8 valueReverse;
    u8 padCC[0x14];
    s16 pulseElapsed;
    u8 padE2[6];
    f32 bounceHeight;
    s16 bounceElapsed;
    s16 bounceDuration;
} FclSpriteAnimation;

/* Draw tasks allocate one 0x100-byte record. Pools prefix an array of
   exactly the same records with the shared resource word. */
typedef struct FclSpriteRecord {
    union { u32 id; s32 signedId; void *pointer; } resource;
    s16 id;
    u8 pad06[2];
    union { s32 word; u32 unsignedWord; } order;
    s16 halfWidth;
    s16 halfHeight;
    FclSpriteAnimation animation;
} FclSpriteRecord;

typedef struct FclSpritePool {
    u32 resource;
    FclSpriteRecord records[0x30C];
    s16 count;
    s16 activeIndices[0x30C];
    u8 pad3121E[2];
} FclSpritePool;

/* The child constructor allocates 0x190 bytes; bounds packets are opaque
   representations rather than guessed width/height fields. */
typedef struct FclSpriteChild {
    u8 state;
    u8 pad01[0x10F];
    FclDrawColor cornerColors[4];
    FclBoundsPacket bounds;
    f32 baseScale;
    FclVec2 position;
    FclVec2 positionStart;
    FclVec2 positionEnd;
    s16 elapsed;
    u8 pad14E[2];
    u32 duration;
    u8 mode;
    u8 pad155;
    s16 transition;
    FclBoundsPacket boundsStart;
    FclBoundsPacket boundsEnd;
    u8 alphaStart;
    u8 alphaEnd;
    s16 alphaElapsed;
    u32 alphaDuration;
    u8 fadeEnabled;
    u8 pad181;
    s16 timer;
    u8 hidden;
    u8 pad185[3];
    u32 order;
    u8 transitionFlag;
    u8 pad18D[3];
} FclSpriteChild;

/* Quad vertices are 0x40-byte render packets. Both panel and list draws
   write positions, texture coordinates, reciprocal scale and float RGBA. */
typedef struct FclQuadVertex {
    f32 x;
    f32 y;
    f32 depth;
    u8 pad0C[4];
    f32 u;
    f32 v;
    f32 reciprocalScale;
    u8 pad1C[4];
    union { f32 value; s32 bits; } red;
    union { f32 value; s32 bits; } green;
    union { f32 value; s32 bits; } blue;
    f32 alpha;
    u8 pad30[0x10];
} FclQuadVertex;

typedef struct FclSpritePanel {
    FclVec2 position;
    u8 pad08[8];
    s32 width;
    s32 height;
    f32 depth;
    u8 pad1C[4];
    FclQuadVertex vertices[4];
    s32 order;
    u8 hidden;
    u8 alpha;
    u8 pad126[0xA];
} FclSpritePanel;

typedef struct FclSpriteListEntry {
    FclQuadVertex vertices[4];
    s16 order;
    u8 pad102[2];
    FclSpriteAnimation animation;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    u8 pad204[8];
    s32 width;
    s32 height;
    u8 *resource;
    u8 pad218[8];
} FclSpriteListEntry;

typedef struct FclSpriteList {
    FclSpriteListEntry entries[0x30];
    s16 count;
    u8 pad6602[0xE];
} FclSpriteList;

/* Queue users store either a no-argument render-state callback or a
   primitive callback in the same pointer-sized slot. */
typedef struct FclDrawQueueNode {
    u8 pad00[8];
    union { void (*callback)(void); void *pointer; } draw;
    u8 pad0C[4];
    union { s32 word; u8 *work; } data;
} FclDrawQueueNode;

typedef char FclSpriteAnimationSize[sizeof(FclSpriteAnimation) == 0xF0 ? 1 : -1];
typedef char FclSpriteRecordSize[sizeof(FclSpriteRecord) == 0x100 ? 1 : -1];
typedef char FclSpriteChildSize[sizeof(FclSpriteChild) == 0x190 ? 1 : -1];
typedef char FclSpritePanelSize[sizeof(FclSpritePanel) == 0x130 ? 1 : -1];
typedef char FclSpriteListEntrySize[sizeof(FclSpriteListEntry) == 0x220 ? 1 : -1];
extern s32 fclFadeRectTaskUpdate(u8 *task);
extern void fclFadeRectTaskDestroy(u8 *task);
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

extern void fclSpriteStartPosition(u8 *, f2 p1, f2 p2, u32 , s32 , s32 );


extern void fclSpriteStartColor(u8 *, u4 , u4 , u8 , s16 , s32 );


extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void RpSkyRenderStateSet(s32, s32);
extern void (*D_00887300[])(u32 state, u32 value);

extern s32 fclPackRgba(u8, u8, u8, u8);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 sdkSpriteScaledWidth(u8 *);
extern f32 sdkSpriteScaledHeight(u8 *);
extern u8 *sdkSpriteNewNode(u32 , u32 );
extern void sdkSpriteFreeNode(void *node);
extern void fclSpriteUpdateCulling(u8 *, s16, s16);
extern f32 fclEaseInterpolate(s64, f32, f32, f32, f32);
extern s32 fclAddClamped(s32, s32, s32, s32, s8);
extern s16 fclSubClamped(s32, s32, s32, s32, s8);
extern void fclSpriteApplySkyPresetA(void);
extern void fclSpriteApplySkyPresetB(void);
extern s32 fclSpriteUpdateAndDrawTask(u8 *);
extern void fclSpriteDestroyTask(u8 *);
extern s32 fclSpriteStartPanelLayout(u8 *);
extern s32 fclSpriteUpdateTweens(u8 *);
extern s8 fclSpriteTestRecordFlag(u8 *, u32 );
extern s32 fclSpriteListUpdate(u8 *);
extern void fclSpriteBuildCornerQuads(u8 *, u8 *);
extern s32 fclSpritePoolUpdate(u8 *);
extern void fclSpritePoolDestroy(u8 *);
extern void fclSpriteDestroyListTask(u8 *);

extern u8 D_0063F178[];
extern u8 D_0063F188[];
extern u8 D_0063F1A0[];
extern u8 D_0063F1B0[];
extern u8 D_0063F1D0[];
extern u8 D_0063F1E0[];
void fclSpriteStartFade(u8 *task, u8 startAlpha, u8 endAlpha, u32 duration);

extern void mdlEffectEmitMaskedTagPair(void);
extern u8 *kwlnGetCamera(void);
extern void memcpy(void *, s32, s32);
extern void *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *, void *);
extern u8 *PrimQueueDrawPrimitive(void *list, s32 , void *, s32 );
extern f32 fGpffff8504;
extern f32 iGpffff84f4;
extern f32 D_008872F8[];
extern u8 D_00793E80[];


/* Create a fade-rect child task under parent with a 0x190-byte sprite work block at the given
 * position, white corner colours and cleared flags; return the task handle. */
// FUN_002B5C90
#pragma push
/* measured: retail hoists the 0xFF corner constant out of the loop. */
#pragma opt_loop_invariants on
s32 fclSpriteSpawnChild(s32 parent, f2 position) {
    s32 handle;
    u8 *work;
    s32 cornerIndex;
    chkmemAllocSiteTag(&D_0063F178, 0xD4);
    work = D_008873F4[0](1, 0x190, 0x40000);
    handle = (s32)kwlnTaskCreateChild((void *)((void *)(parent)), (const void *)(D_0063F188), 0xF, 0, 0, fclFadeRectTaskUpdate, fclFadeRectTaskDestroy, (u8 *)(work));
    ((FclSpriteChild *)(work))->position = position;
    ((FclSpriteChild *)(work))->elapsed = 0;
    ((FclSpriteChild *)(work))->mode = 0;
    for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
        u8 *q = work + 0x110 + cornerIndex * 4;
        ((FclDrawColor *)q)->c0 = 0xFF;
        ((FclDrawColor *)q)->c1 = 0xFF;
        ((FclDrawColor *)q)->c2 = 0xFF;
        ((FclDrawColor *)q)->c3 = 0xFF;
    }
    ((FclSpriteChild *)(work))->order = 0x49;
    ((FclSpriteChild *)(work))->hidden = 0;
    ((FclSpriteChild *)(work))->transition = -1;
    ((FclSpriteChild *)(work))->fadeEnabled = 0;
    ((FclSpriteChild *)(work))->transitionFlag = 0;
    ((FclSpriteChild *)(work))->timer = 0;
    return handle;
}
#pragma pop
// Same body as fclSpriteWork, kept under the Alt name.
// FUN_002B5DA0
u8 *fclSpriteWorkAlt(u8 *task) {
    return ((KwlnTask *)(task))->work;
}

/* Store a child sprite position and copy its opaque bounds representation. */
// FUN_002B5DB0
void fclSpriteSetPositionBounds(u8 *task, f2 position, FclBoundsPacket bounds) {
    FclBoundsBytes representation;
    u8 *work;
    representation = bounds.representation;
    work = ((KwlnTask *)(task))->work;
    ((FclSpriteChild *)(work))->position = position;
    (&((FclSpriteChild *)work)->bounds)->representation = representation;
}

// Stores the base scale; fclSpriteResetScale copies it into the four layout scales.
// FUN_002B5E20
void fclSpriteSetBaseScale(u8 *task, f32 scale) {
    ((FclSpriteChild *)(((KwlnTask *)(task))->work))->baseScale = scale;
}

/* Set all four child-sprite corner colors to the same RGBA value. */
// FUN_002B5E30
void fclSpriteSetCornerColors(u8 *task, u4 color) {
    u8 *work = ((KwlnTask *)(task))->work;
    s32 cornerIndex;
    for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
        ((FclSpriteChild *)work)->cornerColors[cornerIndex] = color;
    }
}
/* Initialize a child-sprite position transition and select transition kind two. */
// FUN_002B5E90
void fclSpriteStartMove(u8 *task, f2 start, f2 end, u32 duration) {
    u8 *work = ((KwlnTask *)(task))->work;
    ((FclSpriteChild *)(work))->elapsed = 0;
    ((FclSpriteChild *)(work))->duration = duration;
    ((FclSpriteChild *)(work))->positionStart = start;
    ((FclSpriteChild *)(work))->positionEnd = end;
    ((FclSpriteChild *)(work))->transition = 2;
    ((FclSpriteChild *)(work))->mode = 0;
    ((FclSpriteChild *)(work))->state = 2;
}

/* Initialize simultaneous position and bounds transitions for a child sprite. */
// FUN_002B5EF0
void fclSpriteStartBoundsMove(u8 *task, f2 start, f2 end, FclBoundsPacket startBounds, FclBoundsPacket endBounds, u32 duration) {
    FclBoundsBytes startRepresentation = startBounds.representation;
    FclBoundsBytes endRepresentation = endBounds.representation;
    u8 *work = ((KwlnTask *)(task))->work;
    ((FclSpriteChild *)(work))->elapsed = 0;
    ((FclSpriteChild *)(work))->duration = duration;
    ((FclSpriteChild *)(work))->positionStart = start;
    ((FclSpriteChild *)(work))->positionEnd = end;
    (&((FclSpriteChild *)work)->boundsStart)->representation = startRepresentation;
    (&((FclSpriteChild *)work)->boundsEnd)->representation = endRepresentation;
    ((FclSpriteChild *)(work))->transition = 3;
    ((FclSpriteChild *)(work))->mode = 0;
    ((FclSpriteChild *)(work))->state = 2;
}

// Like fclSpriteStartBoundsMove, but also starts an alpha fade (fclSpriteStartFade, alpha 0x80) and
// sets the timer.
// FUN_002B5FD0
void fclSpriteStartBoundsMoveFade(u8 *task, f2 start, f2 end, FclBoundsPacket startBounds, FclBoundsPacket endBounds, u32 duration, s16 timer) {
    FclBoundsBytes startRepresentation = startBounds.representation;
    FclBoundsBytes endRepresentation = endBounds.representation;
    u8 *work = ((KwlnTask *)(task))->work;
    ((FclSpriteChild *)(work))->elapsed = 0;
    ((FclSpriteChild *)(work))->duration = duration;
    ((FclSpriteChild *)(work))->positionStart = start;
    ((FclSpriteChild *)(work))->positionEnd = end;
    (&((FclSpriteChild *)work)->boundsStart)->representation = startRepresentation;
    (&((FclSpriteChild *)work)->boundsEnd)->representation = endRepresentation;
    ((FclSpriteChild *)(work))->transition = 4;
    fclSpriteStartFade(task, 0x80, 0, duration);
    ((FclSpriteChild *)(work))->mode = 0;
    ((FclSpriteChild *)(work))->state = 2;
    ((FclSpriteChild *)(work))->hidden = 1;
    ((FclSpriteChild *)(work))->transitionFlag = 1;
    ((FclSpriteChild *)(work))->timer = timer;
}

// Starts a fade: stores start and end alpha, resets the elapsed timer, sets the duration and
// enables the fade.
// FUN_002B60F0
void fclSpriteStartFade(u8 *task, u8 startAlpha, u8 endAlpha, u32 duration) {
    u8 *work = ((KwlnTask *)(task))->work;
    ((FclSpriteChild *)(work))->alphaStart = startAlpha;
    ((FclSpriteChild *)(work))->alphaEnd = endAlpha;
    ((FclSpriteChild *)(work))->alphaElapsed = 0;
    ((FclSpriteChild *)(work))->alphaDuration = duration;
    ((FclSpriteChild *)(work))->fadeEnabled = 1;
}

// Sets the sprite's mode byte; y_fclCombine callers pass the mode.
// FUN_002B6120
void fclSpriteSetMode(u8 *task, u8 mode) {
    ((FclSpriteChild *)(((KwlnTask *)(task))->work))->mode = mode;
}

// Sets the sprite's draw order word; y_fclCombine callers pass the order.
// FUN_002B6130
void fclSpriteSetOrder(u8 *task, u32 order) {
    ((FclSpriteChild *)(((KwlnTask *)(task))->work))->order = order;
}

// Sets the sprite's hidden byte; y_fclCombine callers pass 0 or 1.
// FUN_002B6140
void fclSpriteSetHidden(u8 *task, u8 hidden) {
    ((FclSpriteChild *)(((KwlnTask *)(task))->work))->hidden = hidden;
}

// Returns the 0x100-byte record for the given sprite index in the draw pool.
// FUN_002B6150
u8 *fclSpriteEntry(s16 index) {
    return (u8 *)((u32)(((KwlnTask *)(D_0076DB7C))->work) + (u32)((s32)index << 8) + 4);
}
// Applies sky render-state preset A (texture stage and blend setup, then RpSkyRenderStateSet 3 =
// 0x71009). Used as a task callback.
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

/* measured: propagation off keeps the first comparison's field and global loads in retail order. */
#pragma push
#pragma opt_propagation off
// Per-frame update of one sprite task: advances its tweens, then queues the sprite draw with the
// layout chosen by flag 13 when alpha and scale exceed threshold.
// FUN_002B6340
s32 fclSpriteUpdateAndDrawTask(u8 *task) {
    FclSpriteRecord *sprite;
    u8 *p;
    u8 *q;
    s32 color;
    f32 a;
    f32 g;
    p = ((KwlnTask *)(task))->work;
    sprite = (FclSpriteRecord *)p;
    memcpy(p + 0x10, fclSpriteUpdateTweens(p + 0x10), 0xF0);
    if (((FclSpriteRecord *)p)->animation.alpha <= 0) return 0;
    a = ((FclSpriteRecord *)p)->animation.scaleX.value;
    g = iGpffff84f4;
    if (a <= g) return 0;
    if (((FclSpriteRecord *)p)->animation.scaleY.value <= g) return 0;
    if (fclSpriteTestRecordFlag(task, 0) == 1) {
        if (fclSpriteTestRecordFlag(task, 13) == 1) {
            q = PrimAllocQueueNode();
            ((FclDrawQueueNode *)q)->draw.callback = fclSpriteApplySkyPresetA;
            ((FclDrawQueueNode *)q)->data.word = 0;
            PrimAppendNode(D_00793E80 + ((FclSpriteRecord *)p)->order.word * 0x30, q);
            color = fclPackRgba(255, ((FclSpriteRecord *)p)->animation.color.c0, ((FclSpriteRecord *)p)->animation.color.c1, ((FclSpriteRecord *)p)->animation.color.c2);
            sdkSpriteDrawQueued(((FclSpriteRecord *)p)->animation.position.x, ((FclSpriteRecord *)p)->animation.position.y, ((FclSpriteRecord *)p)->animation.depth,
                color, p[0x6E], ((FclSpriteRecord *)p)->id, ((FclSpriteRecord *)p)->resource.pointer, 0,
                ((FclSpriteRecord *)p)->halfWidth, ((FclSpriteRecord *)p)->halfHeight, ((FclSpriteRecord *)p)->animation.value.value,
                sprite->animation.scaleX.value, sprite->animation.scaleY.value, D_00793E80 + sprite->order.word * 0x30);
        } else {
            color = fclPackRgba(255, ((FclSpriteRecord *)p)->animation.color.c0, ((FclSpriteRecord *)p)->animation.color.c1, ((FclSpriteRecord *)p)->animation.color.c2);
            sdkSpriteDrawQueued(((FclSpriteRecord *)p)->animation.position.x, ((FclSpriteRecord *)p)->animation.position.y, ((FclSpriteRecord *)p)->animation.depth,
                color, p[0x6E], ((FclSpriteRecord *)p)->id, ((FclSpriteRecord *)p)->resource.pointer, 1,
                ((FclSpriteRecord *)p)->halfWidth, ((FclSpriteRecord *)p)->halfHeight, ((FclSpriteRecord *)p)->animation.value.value,
                sprite->animation.scaleX.value, sprite->animation.scaleY.value, D_00793E80 + ((FclSpriteRecord *)p)->order.word * 0x30);
        }
    }
    return 0;
}
#pragma pop
// Destroy callback for the 0x100-byte task created by fclSpriteCreateDrawTask; frees the task's
// work block.
// FUN_002B6560
void fclSpriteDestroyTask(u8 *task) {
    u8 *p = ((KwlnTask *)(task))->work;
    jtbl_008873EC[0](p);
}

/* Each dimension divisor is reloaded after its provider call while the component's byte color stays
 * shared. */
#pragma push
/* measured: loop invariants stay off file-wide to keep retail index-extension order; propagation
 * off keeps retail saved-register assignment and local load order. */
#pragma opt_propagation off
/* measured: schedule off preserves the retail loop and call issue order. */
#pragma schedule off
/* Keep dimension constants local to their queries. */
#pragma opt_pulloutconstants off
// Creates the 0x100-byte sprite draw task under parent; spriteId is stored at +4 and resource tint
// at +0, size from the sprite node. y_smap.c uses slots 0xC and 0xD.
// FUN_002B6590
s32 fclSpriteCreateDrawTask(s32 parent, s16 spriteId, s32 resource) {
    s32 result;
    u8 *work;
    s16 spriteIndex;
    s16 componentIndex;
    s32 componentOffset;
    const u8 fullAlpha = 0xFF;
    f2 position;
    u4 color;
    u8 *component;
    s32 unitBits;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
    f32 zeroValue;
    chkmemAllocSiteTag(&D_0063F178, 0x236);
    work = D_008873F4[0](1, 0x100, 0x40000);
    result = (s32)kwlnTaskCreateChild((void *)((void *)(parent)), (const void *)(D_0063F1A0), 0xF, 0, 0, fclSpriteUpdateAndDrawTask, fclSpriteDestroyTask, (u8 *)(work));
    ((FclSpriteRecord *)(work))->id = spriteId;
    ((FclSpriteRecord *)(work))->resource.signedId = resource;
    spriteIndex = 0;
    componentIndex = spriteIndex;
    while (spriteIndex < 3) {
        componentIndex = spriteIndex;
        componentOffset = componentIndex;
        zeroValue = 0.0f;
        position = fclMakeVec2(zeroValue, zeroValue);
        ((FclSpriteRecord *)((u8 *)((s32)work + componentOffset * 8)))->animation.positionStart = position;
        ((FclSpriteRecord *)((s32)work + componentOffset))->animation.alphaStart = fullAlpha;
        component = (u8 *)((s32)work + componentOffset * 4);
        ((FclSpriteRecord *)(component))->animation.valueStart.bits = 0;
        unitBits = 0x3F800000;
        ((FclSpriteRecord *)(component))->animation.scaleYStart.bits = unitBits;
        ((FclSpriteRecord *)(component))->animation.scaleXStart.bits = unitBits;
        color = fclMakeDrawColor(fullAlpha, fullAlpha, fullAlpha, fullAlpha);
        c0 = color.c0;
        c1 = color.c1;
        c2 = color.c2;
        c3 = color.c3;
        ((FclSpriteRecord *)(component))->animation.colorStart.c0 = c0;
        ((FclSpriteRecord *)(component))->animation.colorStart.c1 = c1;
        ((FclSpriteRecord *)(component))->animation.colorStart.c2 = c2;
        ((FclSpriteRecord *)(component))->animation.colorStart.c3 = c3;
        spriteIndex++;
    }
    ((FclSpriteRecord *)(work))->animation.depth = 100.0f;
    ((FclSpriteRecord *)(work))->order.word = 0x55;
    ((FclSpriteRecord *)(work))->animation.flags = 0;
    component = sdkSpriteNewNode(((FclSpriteRecord *)(work))->resource.id, (s32)spriteId);
    ((FclSpriteRecord *)(work))->halfWidth = (s16)(s32)(sdkSpriteScaledWidth(component) / 2.0f);
    ((FclSpriteRecord *)(work))->halfHeight = (s16)(s32)(sdkSpriteScaledHeight(component) / 2.0f);
    sdkSpriteFreeNode(component);
    return result;
}
#pragma pop


// Sets (mode 0) or clears (mode 1) a bit in the record's animation.flags; record-level twin of
// fclSpriteSetFlag.
// FUN_002B67A0
void fclSpriteSetRecordFlag(u8 *task, u32 bit, s8 mode) {
    u8 *work = ((KwlnTask *)(task))->work;
    if (mode == 0) {
        ((FclSpriteRecord *)(work))->animation.flags |= (s16)((1 << (bit & 0xFFFF)) & 0xFFFF);
        return;
    }
    if (mode == 1) {
        ((FclSpriteRecord *)(work))->animation.flags &= (s16)((1 << (bit & 0xFFFF)) ^ 0xFFFF);
        return;
    }
}

// Returns the given bit of the record's animation.flags as 0 or 1.
// FUN_002B6820
s8 fclSpriteTestRecordFlag(u8 *task, u32 bit) {
    u32 shift = bit & 0xFFFF;
    return (s8)((s32)(((FclSpriteRecord *)(((KwlnTask *)(task))->work))->animation.flags & ((1 << shift) & 0xFFFF)) >> shift);
}


// Returns 1 when any of bits 1-4 of the record's animation.flags is set.
// FUN_002B6850
s32 fclSpriteHasDisplayFlags(u8 *task) {
    s16 flags = ((FclSpriteRecord *)(((KwlnTask *)(task))->work))->animation.flags;
    if (((s8)((flags & 2) >> 1)) == 0 && ((s8)((flags & 4) >> 2)) == 0 &&
        ((s8)((flags & 8) >> 3)) == 0 && ((s8)((flags & 0x10) >> 4)) == 0) {
        return 0;
    }
    return 1;
}

/* measured: opt_propagation off keeps retail's prologue load order; the clear path uses ^ 0xFFFF
 * because ~ emits a 32-bit not instead of retail's 16-bit xori. Sets (mode 0) or clears (mode 1) a
 * flag bit on sprite index. */
/* Set (mode 0) or clear (mode 1) one bit in the animation flags of the sprite at index in the pool. */
// FUN_002B68D0
#pragma push
#pragma opt_propagation off
/* measured: opt_propagation off keeps retail's order of loading the work base before the index
 * shift. */
void fclSpriteSetFlag(s16 index, s16 bit, s8 mode) {
    u8 *pool = ((KwlnTask *)(iGpffffb574))->work;
    u8 *slot = pool + ((s32)index << 8);
    u8 *record = slot + 4;
    s32 flags = ((FclSpriteRecord *)(slot + 4))->animation.flags;
    if (mode == 0) {
        flags = (s16)(flags | (s16)((1 << bit) & 0xFFFF));
    } else if (mode == 1) {
        flags = (s16)(flags & (s16)((1 << bit) ^ 0xFFFF));
    }
    ((FclSpriteRecord *)(record + 4))->halfWidth = (s16)flags;
}
#pragma pop
// Fcl sprite flag bit: returns bit bit of flags as 0 or 1.
// FUN_002B6970
s16 fclSpriteFlagBit(s16 flags, s16 bit) {
    return (s16)((flags & ((1 << bit) & 0xFFFF)) >> bit);
}

// Fcl sprite start position (task): starts a position transition on the task's sprite block.
// FUN_002B69B0
void fclSpriteStartPositionTask(u8 *task, f2 start, f2 end, u32 mode, u32 duration, s16 delay) {
    fclSpriteStartPosition(((KwlnTask *)(task))->work + 0x10, start, end, mode, duration, delay);
}

/* measured: opt_propagation off keeps the table-base load right after the global work load,
 * matching retail's order. Starts a position transition on a sprite by index. */
// FUN_002B69F0
#pragma push
#pragma opt_propagation off
/* measured: opt_propagation off keeps retail's order of loading the work base before the index
 * shift. */
void fclSpriteStartPositionAt(s16 index, f2 start, f2 end, u32 mode, u32 duration, s16 delay) {
    u8 *work = ((KwlnTask *)(iGpffffb574))->work;
    fclSpriteStartPosition(work + ((s32)index << 8) + 0x14, start, end, mode, duration, delay);
}
#pragma pop
// Fcl sprite start alpha (task): starts an alpha transition on the task's sprite block.
// FUN_002B6A40
void fclSpriteStartAlphaTask(u8 *task, u8 startAlpha, u8 endAlpha, u8 mode, s32 duration, s16 delay) {
    u8 *work = ((KwlnTask *)(task))->work;
    s16 narrowedDelay = (s16)delay;
    fclSpriteStartAlpha(work + 0x10, startAlpha, endAlpha, mode, duration, narrowedDelay);
}


/* measured: starts an alpha transition on sprite index; opt_propagation off keeps retail's load
 * order and delay is re-narrowed to s16 for retail's sign-extension. */
// FUN_002B6A70
#pragma push
#pragma opt_propagation off
/* measured: opt_propagation off keeps retail's order of loading the work base before the index
 * shift. */
void fclSpriteStartAlphaAt(s16 index, u8 startAlpha, u8 endAlpha, u8 mode, s32 duration, s16 delay) {
    u8 *work = ((KwlnTask *)(iGpffffb574))->work;
    fclSpriteStartAlpha(work + ((s32)index << 8) + 0x14, startAlpha, endAlpha, mode, duration, (s16)delay);
}
#pragma pop
// Fcl sprite start reveal scale (task): starts a scale reveal on the task's sprite block.
// FUN_002B6AC0
void fclSpriteStartRevealScaleTask(u8 *task, f32 startX, f32 endX, f32 startY, f32 endY, u32 mode, u32 duration, s32 delay) {
    u8 *work = ((KwlnTask *)(task))->work;
    s16 narrowedDelay = (s16)delay;
    fclSpriteStartRevealScale(work + 0x10, startX, endX, startY, endY, mode, duration, narrowedDelay);
}

/* measured: retail loads the task work pointer before using the index, which needs copy propagation
 * off. Starts a scale reveal on the sprite at the given index. */
// FUN_002B6AF0
#pragma push
#pragma opt_propagation off
/* measured: opt_propagation off keeps retail's order of loading the work base before the index
 * shift. */
void fclSpriteStartRevealScaleAt(s16 index, f32 startX, f32 endX, f32 startY, f32 endY, u32 mode, u32 duration, s16 delay) {
    u8 *work = ((KwlnTask *)(iGpffffb574))->work;
    fclSpriteStartRevealScale(work + ((s32)index * 256) + 0x14, startX, endX, startY, endY, mode, duration, (s16)delay);
}
/* Fcl sprite start tween (index): starts a two-float tween on sprite index. */
// FUN_002B6B40
/* measured: retail reloads the work base from the task in this wrapper. */
void fclSpriteStartTweenAt(s16 index, u8 mode, s32 duration, s32 delay, f32 start, f32 end) {
    u8 *work = ((KwlnTask *)(iGpffffb574))->work;
    fclSpriteStartTween(work + ((s32)index << 8) + 0x14, mode, duration, (s16)delay, start, end);
}
/* Fcl sprite start color (index): starts a colour fade on sprite index. */
// FUN_002B6B90
/* measured: retail reloads the work base from the task in this wrapper. */
void fclSpriteStartColorAt(s16 index, u4 start, u4 end, u8 mode, s16 duration, s32 delay) {
    u8 *work = ((KwlnTask *)(iGpffffb574))->work;
    fclSpriteStartColor(work + ((s32)index << 8) + 0x14, start, end, mode, duration, (s16)delay);
}
#pragma pop
// Fcl sprite activate (task): marks the task's sprite active and sets its id, scale and position.
// FUN_002B6BE0
void fclSpriteActivateTask(u8 *task, f2 position, u32 order, f32 depth) {
    u8 *work = ((KwlnTask *)(task))->work;
    ((FclSpriteRecord *)(work))->animation.flags |= 1;
    ((FclSpriteRecord *)(((KwlnTask *)(task))->work))->animation.depth = depth;
    ((FclSpriteRecord *)(((KwlnTask *)(task))->work))->order.unsignedWord = order;
    ((FclSpriteRecord *)(work))->animation.position = position;
}

/* Fcl sprite create: creates the sprite node for sprite index and records its half width and
 * height. */
// FUN_002B6C30
void fclSpriteCreate(s16 index, f2 position, f32 depth, s32 order) {
    u8 *pool;
    u8 *refreshedPool;
    s32 recordOffset;
    u8 *entry;
    u8 *sprite;
    pool = ((KwlnTask *)(iGpffffb574))->work;
    recordOffset = (s32)(s16)index * 256;
    entry = pool + recordOffset;
    ((FclSpriteRecord *)(entry + 4))->animation.flags |= 1;
    ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->animation.depth = depth;
    ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->order.word = order;
    entry = ((KwlnTask *)(iGpffffb574))->work + recordOffset;
    ((FclSpriteRecord *)(entry + 4))->animation.position = position;
    sprite = sdkSpriteNewNode(((FclSpritePool *)pool)->resource, ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->id);
    refreshedPool = ((KwlnTask *)(iGpffffb574))->work;
    ((FclSpriteRecord *)(refreshedPool + recordOffset + 4))->halfWidth = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
    refreshedPool = ((KwlnTask *)(iGpffffb574))->work;
    ((FclSpriteRecord *)(refreshedPool + recordOffset + 4))->halfHeight = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
    sdkSpriteFreeNode(sprite);
}

// Fcl sprite reset scale: resets sprite index to unit scale and full opacity.
// FUN_002B6D60
#pragma push
#pragma opt_propagation off
/* measured: propagation off keeps retail's second reload of the work base. */
void fclSpriteResetScale(s16 index) {
    u8 *base = ((KwlnTask *)(iGpffffb574))->work;
    u8 *last;
    s32 recordOffset = ((s32)index) << 8;
    ((FclSpriteRecord *)(base + recordOffset + 4))->animation.scaleY.value = 1.0f;
    ((FclSpriteRecord *)(base + recordOffset + 4))->animation.scaleX.value = 1.0f;
    last = ((KwlnTask *)(iGpffffb574))->work;
    ((FclSpriteRecord *)(last + recordOffset + 4))->animation.alpha = 0xFF;
}
#pragma pop
// Applies the masked render-state preset and emits the masked tag pair; queue callback used by
// fclSpriteStartPanelLayout.
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

// Emits the plain tag pair for the sprite's queued draw; queue callback used by
// fclSpriteStartPanelLayout.
// FUN_002B6EA0
void fclSpriteEmitTagPair(void) {
    mdlEffectEmitTagPair();
}

/* Test whether any animation flag in bits one through twelve is active. */
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

/* The global task owns the shared sprite pool allocation. */
#define YDRAW_BASE (((KwlnTask *)iGpffffb574)->work)

#pragma push
/* measured: loop invariants and lifetimes on reproduce retail's register lifetimes. */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// Fcl sprite pool update: per-frame update of every active sprite record in the pool.
// FUN_002B6EC0
/* measured: retail needs both loop invariants and lifetimes enabled for this function. */
s32 fclSpritePoolUpdate(u8 *task) {
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

    queue = (s16 *)((KwlnTask *)task)->work;
    ((FclSpritePool *)queue)->count = 0;
    i = 0;
    while (i < 0x30C) {
        ((FclSpritePool *)queue)->activeIndices[(s32)i] = 0;
        e = YDRAW_BASE;
        entryOffset = (u32)((s32)i << 8);
        e += (s32)entryOffset;
        if ((s16)(((FclSpriteRecord *)(e + 4))->animation.flags & 1) == 1) {
            animation = fclSpriteUpdateTweens(e + 0x14);
            memcpy(YDRAW_BASE + entryOffset + 0x14, animation, 0xF0);
            fclSpriteUpdateCulling(task, i, ((FclSpriteRecord *)(YDRAW_BASE + entryOffset + 4))->id);
            base = YDRAW_BASE;
            e = base + (s32)entryOffset;
            fl = ((FclSpriteRecord *)(e + 4))->animation.flags;
            if ((s16)((fl & 0x4000) >> 0xE) == 1) {
                w = PrimAllocQueueNode();
                ((FclDrawQueueNode *)w)->draw.callback = fclSpriteApplySkyPresetB;
                ((FclDrawQueueNode *)w)->data.word = 0;
                b2 = YDRAW_BASE;
                PrimAppendNode(D_00793E80 + ((FclSpriteRecord *)(b2 + (s32)i * 0x100 + 4))->order.word * 0x30, w);
                b2 = YDRAW_BASE;
                if (!(((FclSpriteRecord *)(b2 + (s32)i * 0x100 + 4))->animation.scaleX.value <= 0.1f) && !(((FclSpriteRecord *)(b2 + (s32)entryOffset + 4))->animation.scaleY.value <= 0.1f)) {
                    s32 rowOffset = (s32)(u32)i * 0x100;
                    u8 *d;

                    color = fclPackRgba(0xFF, ((FclSpriteRecord *)(b2 + rowOffset + 4))->animation.color.c0, ((FclSpriteRecord *)(b2 + rowOffset + 4))->animation.color.c1, ((FclSpriteRecord *)(b2 + rowOffset + 4))->animation.color.c2);
                    d = b2;
                    d += (s32)(u32)rowOffset;
                    sdkSpriteDrawQueued(
                        ((FclSpriteRecord *)(d + 4))->animation.position.x, ((FclSpriteRecord *)(d + 4))->animation.position.y, ((FclSpriteRecord *)(d + 4))->animation.depth,
                        color, ((FclSpriteRecord *)(d + 4))->animation.alpha, ((FclSpriteRecord *)(d + 4))->id,
                        (void *)((FclSpritePool *)queue)->resource, 0, ((FclSpriteRecord *)(d + 4))->halfWidth,
                        ((FclSpriteRecord *)(d + 4))->halfHeight, ((FclSpriteRecord *)(d + 4))->animation.value.value, ((FclSpriteRecord *)(d + 4))->animation.scaleX.value,
                        ((FclSpriteRecord *)(d + 4))->animation.scaleY.value, D_00793E80 + ((FclSpriteRecord *)(d + 4))->order.word * 0x30);
                } else {
                    if (yDrawAnyBit(((FclSpriteRecord *)(b2 + (s32)entryOffset + 4))->animation.flags) == 0) {
                        ((FclSpriteRecord *)(b2 + entryOffset + 4))->animation.flags &= ~1;
                    }
                }
            } else if ((s16)((fl & 0x2000) >> 0xD) == 1) {
                w = PrimAllocQueueNode();
                ((FclDrawQueueNode *)w)->draw.callback = fclSpriteApplySkyPresetA;
                ((FclDrawQueueNode *)w)->data.word = 0;
                b2 = YDRAW_BASE;
                PrimAppendNode(D_00793E80 + ((FclSpriteRecord *)(b2 + (s32)i * 0x100 + 4))->order.word * 0x30, w);
                b2 = YDRAW_BASE;
                if (!(((FclSpriteRecord *)(b2 + (s32)i * 0x100 + 4))->animation.scaleX.value <= 0.1f) && !(((FclSpriteRecord *)(b2 + (s32)entryOffset + 4))->animation.scaleY.value <= 0.1f)) {
                    s32 rowOffset = (s32)(u32)i * 0x100;
                    u8 *d;

                    color = fclPackRgba(0xFF, ((FclSpriteRecord *)(b2 + rowOffset + 4))->animation.color.c0, ((FclSpriteRecord *)(b2 + rowOffset + 4))->animation.color.c1, ((FclSpriteRecord *)(b2 + rowOffset + 4))->animation.color.c2);
                    d = b2;
                    d += (s32)(u32)rowOffset;
                    sdkSpriteDrawQueued(
                        ((FclSpriteRecord *)(d + 4))->animation.position.x, ((FclSpriteRecord *)(d + 4))->animation.position.y, ((FclSpriteRecord *)(d + 4))->animation.depth,
                        color, ((FclSpriteRecord *)(d + 4))->animation.alpha, ((FclSpriteRecord *)(d + 4))->id,
                        (void *)((FclSpritePool *)queue)->resource, 0, ((FclSpriteRecord *)(d + 4))->halfWidth,
                        ((FclSpriteRecord *)(d + 4))->halfHeight, ((FclSpriteRecord *)(d + 4))->animation.value.value, ((FclSpriteRecord *)(d + 4))->animation.scaleX.value,
                        ((FclSpriteRecord *)(d + 4))->animation.scaleY.value, D_00793E80 + ((FclSpriteRecord *)(d + 4))->order.word * 0x30);
                } else {
                    if (yDrawAnyBit(((FclSpriteRecord *)(b2 + (s32)entryOffset + 4))->animation.flags) == 0) {
                        ((FclSpriteRecord *)(b2 + entryOffset + 4))->animation.flags &= ~1;
                    }
                }
            } else if (((FclSpriteRecord *)(e + 4))->animation.alpha > 0 && !(((FclSpriteRecord *)(e + 4))->animation.scaleX.value <= 0.1f) && !(((FclSpriteRecord *)(e + 4))->animation.scaleY.value <= 0.1f)) {
                u8 *d;

                entryOffset = (s32)(u32)i * 0x100;

                color = fclPackRgba(0xFF, ((FclSpriteRecord *)(base + entryOffset + 4))->animation.color.c0, ((FclSpriteRecord *)(base + entryOffset + 4))->animation.color.c1, ((FclSpriteRecord *)(base + entryOffset + 4))->animation.color.c2);
                d = base;
                d += (s32)(u32)entryOffset;
                sdkSpriteDrawQueued(
                    ((FclSpriteRecord *)(d + 4))->animation.position.x, ((FclSpriteRecord *)(d + 4))->animation.position.y, ((FclSpriteRecord *)(d + 4))->animation.depth,
                    color, ((FclSpriteRecord *)(d + 4))->animation.alpha, ((FclSpriteRecord *)(d + 4))->id,
                    (void *)((FclSpritePool *)queue)->resource, 1, ((FclSpriteRecord *)(d + 4))->halfWidth,
                    ((FclSpriteRecord *)(d + 4))->halfHeight, ((FclSpriteRecord *)(d + 4))->animation.value.value, ((FclSpriteRecord *)(d + 4))->animation.scaleX.value,
                    ((FclSpriteRecord *)(d + 4))->animation.scaleY.value, D_00793E80 + ((FclSpriteRecord *)(d + 4))->order.word * 0x30);
            } else {
                u8 *d = base + entryOffset;

                fl = ((FclSpriteRecord *)(d + 4))->animation.flags;
                if (fl == 1) {
                    if ((s8)((FclSpriteRecord *)(d + 4))->animation.alphaReverse == 0) {
                        if ((s8)((FclSpriteRecord *)(d + 4))->animation.positionReverse == 0) {
                            ((FclSpritePool *)d)->records[0].animation.flags = fl & ~1;
                        }
                    }
                }
            }
            /* Only entries active on loop entry belong in this list. */
            count = queue[0x18602];
            ((FclSpritePool *)queue)->activeIndices[count] = i;
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
void fclSpritePoolDestroy(u8 *task) {
    u8 *p = ((KwlnTask *)(task))->work;
    jtbl_008873EC[0](p);
}

/* Record addresses use signed word arithmetic before byte component offsets; separate table
 * snapshots allow the work data to be replaced. */
#pragma push
#pragma opt_propagation off
#pragma schedule off
// Fcl sprite pool create: creates the pool task, initialises its 0x30C records, and returns the pool work block.
// FUN_002B74F0
u8 *fclSpritePoolCreate(s32 parent, s32 resource) {
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
    iGpffffb574 = (u8 *)kwlnTaskCreateChild((void *)((void *)(parent)), (const void *)(D_0063F1B0), 0xF, 0, 0, fclSpritePoolUpdate, fclSpritePoolDestroy, (u8 *)(data));
    ((FclSpritePool *)data)->resource = resource;
    ((FclSpritePool *)(data))->count = 0;
    record = 0;
    while ((s32)record < 0x30C) {
        component = 0;
        entryOffset = (s32)record * 0x100;
        while ((s32)component < 3) {
            entries = ((KwlnTask *)(iGpffffb574))->work;
            index = component;
            componentOffset = index;
            zero = 0.0f;
            position = fclMakeVec2(zero, zero);
            ((FclSpriteRecord *)((u8 *)(entryOffset + (s32)entries) + componentOffset * 8 + 4))->animation.positionStart = position;
            entry = ((KwlnTask *)(iGpffffb574))->work;
            ((FclSpriteRecord *)((u8 *)(entryOffset + (s32)entry) + componentOffset + 4))->animation.alphaStart = alpha;
            entry = ((KwlnTask *)(iGpffffb574))->work;
            componentOffset = componentOffset * 4;
            ((FclSpriteRecord *)((u8 *)(entryOffset + (s32)entry) + componentOffset + 4))->animation.valueStart.bits = 0;
            entry = ((KwlnTask *)(iGpffffb574))->work;
            unitScale = 1.0f;
            entry = (u8 *)(entryOffset + (s32)entry) + componentOffset;
            ((FclSpriteRecord *)(entry + 4))->animation.scaleYStart.value = unitScale;
            ((FclSpriteRecord *)(entry + 4))->animation.scaleXStart.value = unitScale;
            entries = ((KwlnTask *)(iGpffffb574))->work;
            color = fclMakeDrawColor(alpha, alpha, alpha, alpha);
            ((FclSpriteRecord *)((u8 *)(entryOffset + (s32)entries) + componentOffset + 4))->animation.colorStart = color;
            component++;
        }
        entry = ((KwlnTask *)(iGpffffb574))->work;
        index = record;
        entryOffset = (s32)index * 0x100;
        ((FclSpriteRecord *)(entry + entryOffset + 4))->animation.depth = 100.0f;
        entry = ((KwlnTask *)(iGpffffb574))->work;
        ((FclSpriteRecord *)(entry + entryOffset + 4))->order.word = 0x55;
        ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + entryOffset + 4))->animation.flags = 0;
        entry = (u8 *)(((KwlnTask *)(iGpffffb574))->work + entryOffset);
        ((FclSpriteRecord *)(entry + 4))->halfHeight = 0;
        ((FclSpriteRecord *)(entry + 4))->halfWidth = 0;
        record++;
    }
    return iGpffffb574;
}
#pragma pop

// Fcl sprite reset: sets sprite index's id to spriteId and clears its flags and state.
// FUN_002B7750
void fclSpriteReset(s16 index, s16 spriteId) {
    u8 *base = ((KwlnTask *)(iGpffffb574))->work;
    s32 recordOffset = ((s32)index) << 8;
    ((FclSpriteRecord *)(base + recordOffset + 4))->id = spriteId;
    base = ((KwlnTask *)(iGpffffb574))->work;
    ((FclSpriteRecord *)(base + recordOffset + 4))->animation.flags = 0;
    base = ((KwlnTask *)(iGpffffb574))->work;
    ((FclSpriteRecord *)(base + recordOffset + 4))->animation.positionReverse = 0;
    base = ((KwlnTask *)(iGpffffb574))->work;
    ((FclSpriteRecord *)(base + recordOffset + 4))->animation.alphaReverse = 0;
    base = ((KwlnTask *)(iGpffffb574))->work;
    ((FclSpriteRecord *)(base + recordOffset + 4))->animation.scaleReverse = 0;
    base = ((KwlnTask *)(iGpffffb574))->work;
    ((FclSpriteRecord *)(base + recordOffset + 4))->animation.valueReverse = 0;
}
/* Row transition: each table is captured before its provider or conversion, and the constructor
 * result and outgoing position are kept in each branch. */
#pragma push
#pragma opt_propagation off
#pragma opt_pulloutconstants off
/* Preserve both components of the outgoing position value. */
/* measured: plain aggregate copies at either call change fclSpriteStartShowHide code generation. */
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


// Starts a show or hide transition for pool slot index (hidden == 1 hides, otherwise shows), sizing
// it from the scaled sprite and starting alpha, reveal-scale and position tweens.
// FUN_002B77D0
void fclSpriteStartShowHide(s16 index, f2 position, s16 spriteId, FclDrawColor color, f32 depth, s16 order, s8 hidden, s16 showDuration, s16 hideDuration, s16 startDelay, u32 resource) {
    u8 *sprite;
    s32 recordOffset;
    f2 hideConstructed;
    f2 showConstructed;
    f2 hidePosition;
    f2 showPosition;
    sprite = sdkSpriteNewNode(resource, (s32)spriteId);
    if ((s32)hidden == 1) {
        u8 *sample;
        u8 *dimensionRows;
        u8 *base;
        u8 *orderRows;
        u8 *animationRows;
        s32 delay;
        s32 duration;
        base = ((KwlnTask *)(iGpffffb574))->work;
        recordOffset = (s32)index * 256;
        ((FclSpriteRecord *)(base + recordOffset + 4))->animation.flags |= 1;
        ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->animation.depth = depth;
        orderRows = ((KwlnTask *)(iGpffffb574))->work;
        ((FclSpriteRecord *)(orderRows + recordOffset + 4))->order.word = (s32)order;
        ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->animation.position = position;
        sample = sdkSpriteNewNode(((FclSpritePool *)base)->resource, ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->id);
        dimensionRows = ((KwlnTask *)(iGpffffb574))->work;
        ((FclSpriteRecord *)(dimensionRows + recordOffset + 4))->halfWidth = (s16)(sdkSpriteScaledWidth(sample) / 2.0f);
        dimensionRows = ((KwlnTask *)(iGpffffb574))->work;
        ((FclSpriteRecord *)(dimensionRows + recordOffset + 4))->halfHeight = (s16)(sdkSpriteScaledHeight(sample) / 2.0f);
        sdkSpriteFreeNode(sample);
        animationRows = ((KwlnTask *)(iGpffffb574))->work;
        delay = (s32)startDelay;
        duration = (s32)hideDuration;
        fclSpriteStartAlpha(animationRows + recordOffset + 0x14, ((FclSpriteRecord *)(animationRows + recordOffset + 4))->animation.alpha, 0, 0, 0, (s16)(duration + delay));
        fclSpriteStartRevealScale(((KwlnTask *)(iGpffffb574))->work + recordOffset + 0x14, 1.0f, 1.0f, 1.0f, fGpffff8504, 0, (u32)duration, delay);
        hideConstructed = fclMakeVec2(position.x, position.y + sdkSpriteScaledHeight(sprite) / 2.0f);
        fclCopyTransitionPosition(&hidePosition, &hideConstructed);
        fclSpriteStartPosition(((KwlnTask *)(iGpffffb574))->work + recordOffset + 0x14, position, hidePosition, 0, duration, delay);
    } else {
        u8 *sample;
        u8 *dimensionRows;
        u8 *base;
        u8 *orderRows;
        u8 *animationRows;
        s32 delay;
        s32 duration;
        base = ((KwlnTask *)(iGpffffb574))->work;
        recordOffset = (s32)index * 256;
        ((FclSpriteRecord *)(base + recordOffset + 4))->id = spriteId;
        ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->animation.flags = 0;
        ((YDrawTransitionFlags *)(((KwlnTask *)(iGpffffb574))->work + recordOffset))->positionFlag = 0;
        ((YDrawTransitionFlags *)(((KwlnTask *)(iGpffffb574))->work + recordOffset))->alphaFlag = 0;
        ((YDrawTransitionFlags *)(((KwlnTask *)(iGpffffb574))->work + recordOffset))->scaleFlag = 0;
        ((YDrawTransitionFlags *)(((KwlnTask *)(iGpffffb574))->work + recordOffset))->valueFlag = 0;
        base = ((KwlnTask *)(iGpffffb574))->work;
        ((FclSpriteRecord *)(base + recordOffset + 4))->animation.flags |= 1;
        ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->animation.depth = depth;
        orderRows = ((KwlnTask *)(iGpffffb574))->work;
        ((FclSpriteRecord *)(orderRows + recordOffset + 4))->order.word = (s32)order;
        ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->animation.position = position;
        sample = sdkSpriteNewNode(((FclSpritePool *)base)->resource, ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->id);
        dimensionRows = ((KwlnTask *)(iGpffffb574))->work;
        ((FclSpriteRecord *)(dimensionRows + recordOffset + 4))->halfWidth = (s16)(sdkSpriteScaledWidth(sample) / 2.0f);
        dimensionRows = ((KwlnTask *)(iGpffffb574))->work;
        ((FclSpriteRecord *)(dimensionRows + recordOffset + 4))->halfHeight = (s16)(sdkSpriteScaledHeight(sample) / 2.0f);
        sdkSpriteFreeNode(sample);
        ((FclSpriteRecord *)(((KwlnTask *)(iGpffffb574))->work + recordOffset + 4))->animation.color = color;
        (fclSpriteStartAlpha((((KwlnTask *)(iGpffffb574))->work + recordOffset + 0x14), 0, (&color)->c3, 0, 0, 0));
        animationRows = ((KwlnTask *)(iGpffffb574))->work;
        delay = (s32)startDelay;
        duration = (s32)showDuration;
        fclSpriteStartRevealScale(animationRows + recordOffset + 0x14, 1.0f, 1.0f, fGpffff8504, 1.0f, 0, (u32)duration, delay);
        showConstructed = fclMakeVec2(position.x, position.y + sdkSpriteScaledHeight(sprite) / 2.0f);
        fclCopyTransitionPosition(&showPosition, &showConstructed);
        fclSpriteStartPosition(((KwlnTask *)(iGpffffb574))->work + recordOffset + 0x14, showPosition, position, 0, duration, delay);
    }
    sdkSpriteFreeNode(sprite);
}

#pragma pop

/* The selected-state join keeps both signed-index extensions. */
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
#pragma schedule off
// When the sprite entry has no bit set in flags 1-12, computes its screen margins and sets or
// clears its cull flag by whether it is on screen.
// FUN_002B7CD0
void fclSpriteUpdateCulling(u8 *task, s16 index, s16 spriteId) {
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

    /* The SDK resource prefix selects its 0x80-byte frame table at +0x204. */
    context = ((KwlnTask *)(task))->work;
    entries = (YDrawCullEntry *)((KwlnTask *)iGpffffb574)->work;
    entryOffset = (s32)index * 0x100;
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
        frameIndex = spriteId;
        sample = sdkSpriteNewNode(((FclSpritePool *)context)->resource, frameIndex);
        (void)sdkSpriteScaledWidth(sample);
        (void)sdkSpriteScaledHeight(sample);
        side = 0;
        frame = (YDrawSpriteFrameMargins *)(((SdkSpriteResource *)*(u8 **)sample)->segments + frameIndex * 0x80);
        for (; side < 4; side++) {
            margins[side] = (f32)frame->margins[side];
        }
        if (!(((YDrawCullEntry *)((u8 *)(entries = (YDrawCullEntry *)((KwlnTask *)iGpffffb574)->work) + entryOffset))->x - margins[2] < 640.0f) ||
            (margins[3] + (((YDrawCullEntry *)((u8 *)entries + entryOffset))->x + sdkSpriteScaledWidth(sample)) < 0.0f) ||
            !(((YDrawCullEntry *)((u8 *)(entries = (YDrawCullEntry *)((KwlnTask *)iGpffffb574)->work) + entryOffset))->y - margins[0] < 480.0f) ||
            (margins[1] + (((YDrawCullEntry *)((u8 *)entries + entryOffset))->y + sdkSpriteScaledHeight(sample)) < 0.0f)) {
            ((YDrawCullEntry *)((u8 *)(YDrawCullEntry *)((KwlnTask *)iGpffffb574)->work + entryOffset))->flags &= ~1;
        }
        sdkSpriteFreeNode(sample);
    }
}
#pragma pop

/* measured: retail hoists the D_008872F8 high-half load out of the loop, re-sign-extends the s16
 * index each iteration, and loads the subtraction's left operand first. */
#pragma push
/* measured: opt_loop_invariants on hoists the high half of D_008872F8's address into the loop
 * preheader, as retail does. */
#pragma opt_loop_invariants on
/* measured: opt_propagation off keeps the local load and index-extension order retail uses. */
#pragma opt_propagation off
/* measured: schedule off keeps the D_008872F8 base register live through the loop body in retail's
 * issue order. */
#pragma schedule off
// One-shot layout of the panel task: sets its four channel records and two render positions and
// queues the render job. Returns at once while hidden is set.
// FUN_002B7F20
s32 fclSpriteStartPanelLayout(u8 *task) {
    FclSpritePanel *panel;
    u8 *p;
    f32 scale;
    u8 *q;
    s32 off;
    s16 i;
    s16 j;
    f32 d;

    p = ((KwlnTask *)(task))->work;
    panel = (FclSpritePanel *)p;
    scale = 1.0f / ((RwCamera *)kwlnGetCamera())->nearPlane;
    if ((s8)((FclSpritePanel *)p)->hidden == 1) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        j = i;
        q = p;
        q = (u8 *)((s32)q + (off = (s32)j << 6));
        d = *(f32 *)D_008872F8;
        ((FclSpritePanel *)(q))->vertices[0].depth = d - ((FclSpritePanel *)p)->depth;
        ((FclSpritePanel *)(q))->vertices[0].reciprocalScale = scale;
        ((FclSpritePanel *)(q))->vertices[0].red.bits = 0;
        ((FclSpritePanel *)(q))->vertices[0].green.bits = 0;
        ((FclSpritePanel *)(q))->vertices[0].blue.bits = 0;
        ((FclSpritePanel *)(q))->vertices[0].alpha = (f32)(u32)((FclSpritePanel *)p)->alpha;
    }
    ((FclSpritePanel *)p)->vertices[0].x = ((FclSpritePanel *)p)->position.x;
    ((FclSpritePanel *)p)->vertices[0].y = ((FclSpritePanel *)p)->position.y;
    ((FclSpritePanel *)p)->vertices[1].x = ((FclSpritePanel *)p)->position.x + (f32)((FclSpritePanel *)p)->width;
    ((FclSpritePanel *)p)->vertices[1].y = ((FclSpritePanel *)p)->position.y;
    ((FclSpritePanel *)p)->vertices[2].x = ((FclSpritePanel *)p)->position.x;
    ((FclSpritePanel *)p)->vertices[2].y = ((FclSpritePanel *)p)->position.y + (f32)((FclSpritePanel *)p)->height;
    ((FclSpritePanel *)p)->vertices[3].x = ((FclSpritePanel *)p)->position.x + (f32)MEMBER(s32, p, FclSpritePanel, width);
    ((FclSpritePanel *)p)->vertices[3].y = ((FclSpritePanel *)p)->position.y + (f32)((FclSpritePanel *)p)->height;
    q = PrimQueueDrawPrimitive(D_00793E80 + ((FclSpritePanel *)p)->order * 0x30,
                      4, (void *)(p + 0x20), 4);
    ((FclDrawQueueNode *)q)->draw.pointer = (void *)fclSpriteApplyMaskedPreset;
    ((FclDrawQueueNode *)q)->data.work = p;
    q = PrimAllocQueueNode();
    ((FclDrawQueueNode *)q)->draw.pointer = (void *)fclSpriteEmitTagPair;
    ((FclDrawQueueNode *)q)->data.work = p;
    PrimAppendNode(D_00793E80 + (panel->order + 1) * 0x30, q);
    return 0;
}
#pragma pop

// Destroy callback for the panel task created by fclSpriteCreatePanelChild; frees its work block.
// FUN_002B8120
void fclSpriteDestroyPanel(u8 *task) {
    u8 *p = ((KwlnTask *)(task))->work;
    jtbl_008873EC[0](p);
}

// Creates a child task with a 0x130-byte panel work block (destroy: fclSpriteDestroyPanel), sets
// hidden and clears alpha.
// FUN_002B8150
s32 fclSpriteCreatePanelChild(s32 parent) {
    s32 handle;
    u8 *work;
    chkmemAllocSiteTag(&D_0063F178, 0x4A2);
    work = D_008873F4[0](1, 0x130, 0x40000);
    handle = (s32)kwlnTaskCreateChild((void *)((void *)(parent)), (const void *)(D_0063F1D0), 0xF, 0, 0, fclSpriteStartPanelLayout, fclSpriteDestroyPanel, (u8 *)(work));
    ((FclSpritePanel *)(work))->hidden = 1;
    ((FclSpritePanel *)(work))->alpha = 0;
    return handle;
}

// Fcl sprite work: returns the pool work block of the task.
// FUN_002B81F0
u8 *fclSpriteWork(u8 *task) {
    return ((KwlnTask *)(task))->work;
}

// Sets a sprite's position, scale, colour, alpha, value and depth, and enables the sprite (flags |=
// 1).
// FUN_002B8200
void fclSpriteSetAppearance(u8 *animation, f2 position, u4 color, f32 scale, f32 value, f32 depth) {
    ((FclSpriteAnimation *)(animation))->position = position;
    ((FclSpriteAnimation *)(animation))->scaleY.value = scale;
    ((FclSpriteAnimation *)(animation))->scaleX.value = scale;
    ((FclSpriteAnimation *)(animation))->alpha = color.c3;
    ((FclSpriteAnimation *)(animation))->color = color;
    ((FclSpriteAnimation *)(animation))->value.value = value;
    ((FclSpriteAnimation *)(animation))->depth = depth;
    ((FclSpriteAnimation *)(animation))->flags |= 1;
}

// Fcl sprite start position: sets the start and end points, the duration, the delay and the mode of a position transition.
// FUN_002B8270
void fclSpriteStartPosition(u8 *animation, f2 start, f2 end, u32 mode, s32 duration, s32 delay) {
    ((FclSpriteAnimation *)(animation))->positionStart.x = start.x;
    ((FclSpriteAnimation *)(animation))->positionStart.y = start.y;
    ((FclSpriteAnimation *)(animation))->positionEnd.x = end.x;
    ((FclSpriteAnimation *)(animation))->positionEnd.y = end.y;
    ((FclSpriteAnimation *)(animation))->position.x = start.x;
    ((FclSpriteAnimation *)(animation))->position.y = start.y;
    ((FclSpriteAnimation *)(animation))->positionElapsed = 0;
    ((FclSpriteAnimation *)(animation))->positionDuration = duration;
    ((FclSpriteAnimation *)(animation))->positionDelay = delay;
    ((FclSpriteAnimation *)(animation))->positionMode = mode;
    ((FclSpriteAnimation *)(animation))->flags |= 2;
}

// Fcl sprite start alpha: sets the alpha levels, the duration and the mode of an alpha transition.
// FUN_002B82D0
void fclSpriteStartAlpha(u8 *animation, u8 startAlpha, u8 endAlpha, u8 mode, s32 duration, s32 delay) {
    ((FclSpriteAnimation *)(animation))->alphaStart = startAlpha;
    ((FclSpriteAnimation *)(animation))->alphaEnd = endAlpha;
    ((FclSpriteAnimation *)(animation))->alpha = startAlpha;
    ((FclSpriteAnimation *)(animation))->alphaElapsed = 0;
    ((FclSpriteAnimation *)(animation))->alphaDuration = (s16)duration;
    ((FclSpriteAnimation *)(animation))->alphaDelay = (s16)delay;
    ((FclSpriteAnimation *)(animation))->alphaMode = mode;
    ((FclSpriteAnimation *)(animation))->flags |= 4;
}

// Fcl sprite start reveal scale: sets the scale endpoints, duration, delay and mode of a reveal.
// FUN_002B8300
void fclSpriteStartRevealScale(u8 *animation, f32 startX, f32 endX, f32 startY, f32 endY, u32 mode, u32 duration, s32 delay) {
    ((FclSpriteAnimation *)(animation))->scaleXStart.value = startX;
    ((FclSpriteAnimation *)(animation))->scaleXEnd.value = endX;
    ((FclSpriteAnimation *)(animation))->scaleX.value = startX;
    ((FclSpriteAnimation *)(animation))->scaleYStart.value = startY;
    ((FclSpriteAnimation *)(animation))->scaleYEnd.value = endY;
    ((FclSpriteAnimation *)(animation))->scaleY.value = startY;
    ((FclSpriteAnimation *)(animation))->scaleElapsed = 0;
    ((FclSpriteAnimation *)(animation))->scaleDuration = duration;
    ((FclSpriteAnimation *)(animation))->scaleDelay = (s16)delay;
    ((FclSpriteAnimation *)(animation))->scaleMode = mode;
    ((FclSpriteAnimation *)(animation))->flags |= 0x10;
}

// Fcl sprite start tween: sets the two tween values, the duration, the delay and the mode.
// FUN_002B8340
void fclSpriteStartTween(u8 *animation, u8 mode, s32 duration, s16 delay, f32 start, f32 end) {
    ((FclSpriteAnimation *)(animation))->valueStart.value = start;
    ((FclSpriteAnimation *)(animation))->valueEnd.value = end;
    ((FclSpriteAnimation *)(animation))->value.value = start;
    ((FclSpriteAnimation *)(animation))->valueElapsed = 0;
    ((FclSpriteAnimation *)(animation))->valueDuration = duration;
    ((FclSpriteAnimation *)(animation))->valueDelay = delay;
    ((FclSpriteAnimation *)(animation))->valueMode = mode;
    ((FclSpriteAnimation *)(animation))->flags |= 8;
}

// Fcl sprite start color: sets the start and end colours, the duration and the mode of a colour fade.
// FUN_002B8370
void fclSpriteStartColor(u8 *animation, u4 start, u4 end, u8 mode, s16 duration, s32 delay) {
    ((FclSpriteAnimation *)(animation))->colorStart.c0 = start.c0;
    ((FclSpriteAnimation *)(animation))->colorStart.c1 = start.c1;
    ((FclSpriteAnimation *)(animation))->colorStart.c2 = start.c2;
    ((FclSpriteAnimation *)(animation))->colorEnd.c0 = end.c0;
    ((FclSpriteAnimation *)(animation))->colorEnd.c1 = end.c1;
    ((FclSpriteAnimation *)(animation))->colorEnd.c2 = end.c2;
    ((FclSpriteAnimation *)(animation))->color.c0 = start.c0;
    ((FclSpriteAnimation *)(animation))->color.c1 = start.c1;
    ((FclSpriteAnimation *)(animation))->color.c2 = start.c2;
    ((FclSpriteAnimation *)(animation))->colorDuration = duration;
    ((FclSpriteAnimation *)(animation))->colorElapsed = 0;
    ((FclSpriteAnimation *)(animation))->colorDelay = delay;
    ((FclSpriteAnimation *)(animation))->colorMode = mode;
    ((FclSpriteAnimation *)(animation))->flags |= 0x200;
}

/* Position snapshots are consumed by the inline transition setters.
   Duration stays signed-word sized until each field is stored. */
/* Initialize position interpolation endpoints, timing, mode and active flag. */
static inline void fclStartPosition(u8 *animation, f2 start, f2 end, u32 mode, s32 duration, s32 delay) {
    f32 startX = start.x;
    f32 startY;
    ((FclSpriteAnimation *)(animation))->positionStart.x = startX;
    startY = start.y;
    ((FclSpriteAnimation *)(animation))->positionStart.y = startY;
    ((FclSpriteAnimation *)(animation))->positionEnd.x = end.x;
    ((FclSpriteAnimation *)(animation))->positionEnd.y = end.y;
    ((FclSpriteAnimation *)(animation))->position.x = startX;
    ((FclSpriteAnimation *)(animation))->position.y = startY;
    ((FclSpriteAnimation *)(animation))->positionElapsed = 0;
    ((FclSpriteAnimation *)(animation))->positionDuration = duration;
    ((FclSpriteAnimation *)(animation))->positionDelay = delay;
    ((FclSpriteAnimation *)(animation))->positionMode = mode;
    ((FclSpriteAnimation *)(animation))->flags |= 2;
}

/* Initialize opacity interpolation endpoints, timing, mode and active flag. */
static inline void fclStartAlpha(u8 *animation, u8 startAlpha, u32 endAlpha, u32 mode, u32 duration, s16 delay) {
    ((FclSpriteAnimation *)(animation))->alphaStart = startAlpha;
    ((FclSpriteAnimation *)(animation))->alphaEnd = endAlpha;
    ((FclSpriteAnimation *)(animation))->alpha = startAlpha;
    ((FclSpriteAnimation *)(animation))->alphaElapsed = 0;
    ((FclSpriteAnimation *)(animation))->alphaDuration = duration;
    ((FclSpriteAnimation *)(animation))->alphaDelay = delay;
    ((FclSpriteAnimation *)(animation))->alphaMode = mode;
    ((FclSpriteAnimation *)(animation))->flags |= 4;
}

/* Initialize the incoming or outgoing vertical reveal-scale transition. */
static inline void fclStartRevealScale(u8 *animation, u32 mode, u32 duration, s32 delay, s8 outgoing)
{
    ((FclSpriteAnimation *)(animation))->scaleXStart.value = 1.0f;
    ((FclSpriteAnimation *)(animation))->scaleXEnd.value = 1.0f;
    ((FclSpriteAnimation *)(animation))->scaleX.value = 1.0f;
    if (outgoing == 0) {
        f32 initialScale = fGpffff8504;
        ((FclSpriteAnimation *)(animation))->scaleYStart.value = initialScale;
        ((FclSpriteAnimation *)(animation))->scaleYEnd.value = 1.0f;
        ((FclSpriteAnimation *)(animation))->scaleY.value = initialScale;
    } else {
        ((FclSpriteAnimation *)(animation))->scaleYStart.value = 1.0f;
        ((FclSpriteAnimation *)(animation))->scaleYEnd.value = fGpffff8504;
        ((FclSpriteAnimation *)(animation))->scaleY.value = 1.0f;
    }
    ((FclSpriteAnimation *)(animation))->scaleElapsed = 0;
    ((FclSpriteAnimation *)(animation))->scaleDuration = duration;
    ((FclSpriteAnimation *)(animation))->scaleDelay = delay;
    ((FclSpriteAnimation *)(animation))->scaleMode = mode;
    ((FclSpriteAnimation *)(animation))->flags |= 0x10;
}

/* Initialize RGB interpolation endpoints, timing, mode and active flag. */
static inline void fclStartColor(u8 *animation, u4 start, u4 end, u8 mode, s16 duration, s32 delay) {
    ((FclSpriteAnimation *)(animation))->colorStart.c0 = start.c0;
    ((FclSpriteAnimation *)(animation))->colorStart.c1 = start.c1;
    ((FclSpriteAnimation *)(animation))->colorStart.c2 = start.c2;
    ((FclSpriteAnimation *)(animation))->colorEnd.c0 = end.c0;
    ((FclSpriteAnimation *)(animation))->colorEnd.c1 = end.c1;
    ((FclSpriteAnimation *)(animation))->colorEnd.c2 = end.c2;
    ((FclSpriteAnimation *)(animation))->color.c0 = start.c0;
    ((FclSpriteAnimation *)(animation))->color.c1 = start.c1;
    ((FclSpriteAnimation *)(animation))->color.c2 = start.c2;
    ((FclSpriteAnimation *)(animation))->colorDuration = duration;
    ((FclSpriteAnimation *)(animation))->colorElapsed = 0;
    ((FclSpriteAnimation *)(animation))->colorDelay = delay;
    ((FclSpriteAnimation *)(animation))->colorMode = mode;
    ((FclSpriteAnimation *)(animation))->flags |= 0x200;
}

// Starts an entrance: alpha, reveal scale, position and colour in one call; outgoing selects the
// variant.
// FUN_002B83E0
void fclSpriteStartEntrance(u8 *animation, FclVec2 position, u4 startColor, u4 endColor, u8 startAlpha, u8 endAlpha,
                   f32 height, f32 depth, s32 duration, s32 delay, s8 outgoing, s8 reverse)
{
    ((FclSpriteAnimation *)(animation))->positionReverse = reverse;
    ((FclSpriteAnimation *)(animation))->scaleReverse = reverse;
    fclStartAlpha(animation, startAlpha, endAlpha, 0, duration, delay);
    if ((s8)outgoing == 0) {
        if (reverse == 0) {
            fclStartRevealScale(animation, 0, (s16)duration, (s16)delay, 0);
            fclStartPosition(animation, fclMakeVec2(position.x, position.y + height / 2.0f), position, 0, duration, delay);
            fclStartColor(animation, startColor, endColor, 0, 0, 0);
        } else {
            fclStartRevealScale(animation, 1, (s16)duration, (s16)delay, 0);
            fclStartPosition(animation, fclMakeVec2(position.x, position.y + height / 2.0f), position, 1, duration, delay);
            fclStartColor(animation, startColor, endColor, 0, 0, duration / 2);
        }
    } else if (reverse == 0) {
        fclStartRevealScale(animation, 0, (s16)duration, (s16)delay, 1);
        fclStartPosition(animation, position, fclMakeVec2(position.x, position.y + height / 2.0f), 0, duration, delay);
        fclStartColor(animation, startColor, endColor, 0, 0, 0);
    } else {
        fclStartRevealScale(animation, 1, (s16)duration, (s16)delay, 1);
        fclStartPosition(animation, position, fclMakeVec2(position.x, position.y + height / 2.0f), 1, duration, delay);
        fclStartColor(animation, startColor, endColor, 0, 0, duration / 2);
    }
    ((FclSpriteAnimation *)(animation))->depth = depth;
    ((FclSpriteAnimation *)(animation))->flags |= 1;
}

/* Advances the five tween channels of one sprite record (position, alpha, colour, scale, colour
 * pulse) by one frame, easing each after its delay. Byte channels use plain (f32)(u32) and (u8)
 * casts so the compiler emits retail's unsigned conversion sequences. */
// FUN_002B89A0
s32 fclSpriteUpdateTweens(u8 *animation) {
    FclSpriteAnimation *spriteAnimation = (FclSpriteAnimation *)animation;
    if (((((FclSpriteAnimation *)(animation))->flags & 2) >> 1) == 1) {
        if (((FclSpriteAnimation *)animation)->positionDelay == 0) {
            if ((s8)((FclSpriteAnimation *)animation)->positionReverse == 0) {
                ((FclSpriteAnimation *)animation)->position.x = fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->positionMode, ((FclSpriteAnimation *)animation)->positionStart.x, ((FclSpriteAnimation *)animation)->positionEnd.x, (f32)((FclSpriteAnimation *)animation)->positionElapsed, (f32)((FclSpriteAnimation *)animation)->positionDuration);
                ((FclSpriteAnimation *)animation)->position.y = fclEaseInterpolate((s32)spriteAnimation->positionMode, ((FclSpriteAnimation *)animation)->positionStart.y, ((FclSpriteAnimation *)animation)->positionEnd.y, (f32)spriteAnimation->positionElapsed, (f32)spriteAnimation->positionDuration);
            } else {
                ((FclSpriteAnimation *)animation)->position.x = fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->positionMode, ((FclSpriteAnimation *)animation)->positionStart.x, ((FclSpriteAnimation *)animation)->positionEnd.x, (f32)((FclSpriteAnimation *)animation)->positionElapsed, (f32)(((FclSpriteAnimation *)animation)->positionDuration / 2));
                ((FclSpriteAnimation *)animation)->position.y = fclEaseInterpolate((s32)spriteAnimation->positionMode, ((FclSpriteAnimation *)animation)->positionStart.y, ((FclSpriteAnimation *)animation)->positionEnd.y, (f32)spriteAnimation->positionElapsed, (f32)(spriteAnimation->positionDuration / 2));
            }
            if (spriteAnimation->positionElapsed < MEMBER(s16, animation, FclSpriteAnimation, positionDuration)) {
                spriteAnimation->positionElapsed = fclAddClamped((s32)spriteAnimation->positionElapsed, 1, (s32)MEMBER(s16, animation, FclSpriteAnimation, positionDuration), 0, 1);
            } else {
                spriteAnimation->position.x = spriteAnimation->positionEnd.x;
                spriteAnimation->position.y = spriteAnimation->positionEnd.y;
                if (spriteAnimation->positionReverse == 1) {
                    spriteAnimation->position.x = spriteAnimation->positionStart.x;
                    spriteAnimation->position.y = spriteAnimation->positionStart.y;
                }
                if (((((FclSpriteAnimation *)(animation))->flags & 0x1000) >> 12) == 1) {
                    spriteAnimation->positionElapsed = 1;
                } else {
                    ((FclSpriteAnimation *)(animation))->flags &= ~2;
                }
            }
        } else {
            spriteAnimation->positionDelay = fclSubClamped((s32)((FclSpriteAnimation *)animation)->positionDelay, 1, 0, 0, 1);
        }
    } else if (((((FclSpriteAnimation *)(animation))->flags & 0x80) >> 7) == 1) {
        ((FclSpriteAnimation *)animation)->position.y = fclEaseInterpolate(1, ((FclSpriteAnimation *)animation)->positionEnd.y, ((FclSpriteAnimation *)animation)->positionEnd.y - ((FclSpriteAnimation *)animation)->bounceHeight, (f32)((FclSpriteAnimation *)animation)->bounceElapsed, (f32)(((FclSpriteAnimation *)animation)->bounceDuration / 2));
        if (spriteAnimation->bounceElapsed < MEMBER(s16, animation, FclSpriteAnimation, bounceDuration)) {
            spriteAnimation->bounceElapsed = fclAddClamped((s32)spriteAnimation->bounceElapsed, 1, (s32)MEMBER(s16, animation, FclSpriteAnimation, bounceDuration), 0, 1);
        } else {
            ((FclSpriteAnimation *)animation)->position.x = ((FclSpriteAnimation *)animation)->positionEnd.x;
            spriteAnimation->position.y = spriteAnimation->positionEnd.y;
            ((FclSpriteAnimation *)(animation))->flags &= ~0x80;
        }
    }
    if (((((FclSpriteAnimation *)(animation))->flags & 4) >> 2) == 1) {
        if (((FclSpriteAnimation *)animation)->alphaDelay == 0) {
            if ((s8)((FclSpriteAnimation *)animation)->alphaReverse == 0) {
                ((FclSpriteAnimation *)animation)->alpha = (u8)fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->alphaMode, (f32)(u32)((FclSpriteAnimation *)animation)->alphaStart, (f32)(u32)((FclSpriteAnimation *)animation)->alphaEnd, (f32)((FclSpriteAnimation *)animation)->alphaElapsed, (f32)((FclSpriteAnimation *)animation)->alphaDuration);
            } else {
                ((FclSpriteAnimation *)animation)->alpha = (u8)fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->alphaMode, (f32)(u32)((FclSpriteAnimation *)animation)->alphaStart, (f32)(u32)((FclSpriteAnimation *)animation)->alphaEnd, (f32)((FclSpriteAnimation *)animation)->alphaElapsed, (f32)(((FclSpriteAnimation *)animation)->alphaDuration / 2));
            }
            if (spriteAnimation->alphaElapsed < MEMBER(s16, animation, FclSpriteAnimation, alphaDuration)) {
                spriteAnimation->alphaElapsed = fclAddClamped((s32)spriteAnimation->alphaElapsed, 1, (s32)MEMBER(s16, animation, FclSpriteAnimation, alphaDuration), 0, 1);
            } else {
                animation[0x5E] = animation[0x5D];
                if (spriteAnimation->alphaReverse == 1) {
                    animation[0x5E] = animation[0x5C];
                }
                if (((((FclSpriteAnimation *)(animation))->flags & 0x800) >> 11) == 1) {
                    spriteAnimation->alphaElapsed = 1;
                } else {
                    ((FclSpriteAnimation *)(animation))->flags &= ~4;
                }
            }
        } else {
            spriteAnimation->alphaDelay = fclSubClamped((s32)((FclSpriteAnimation *)animation)->alphaDelay, 1, 0, 0, 1);
        }
    }
    if (((((FclSpriteAnimation *)(animation))->flags & 0x200) >> 9) == 1) {
        if (((FclSpriteAnimation *)animation)->colorDelay == 0) {
            if ((s8)((FclSpriteAnimation *)animation)->colorReverse == 0) {
                ((FclSpriteAnimation *)animation)->color.c0 = (u8)fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->colorMode, (f32)(u32)((FclSpriteAnimation *)animation)->colorStart.c0, (f32)(u32)((FclSpriteAnimation *)animation)->colorEnd.c0, (f32)((FclSpriteAnimation *)animation)->colorElapsed, (f32)((FclSpriteAnimation *)animation)->colorDuration);
                ((FclSpriteAnimation *)animation)->color.c1 = (u8)fclEaseInterpolate((s32)spriteAnimation->colorMode, (f32)(u32)((FclSpriteAnimation *)animation)->colorStart.c1, (f32)(u32)((FclSpriteAnimation *)animation)->colorEnd.c1, (f32)spriteAnimation->colorElapsed, (f32)spriteAnimation->colorDuration);
                ((FclSpriteAnimation *)animation)->color.c2 = (u8)fclEaseInterpolate((s32)spriteAnimation->colorMode, (f32)(u32)((FclSpriteAnimation *)animation)->colorStart.c2, (f32)(u32)((FclSpriteAnimation *)animation)->colorEnd.c2, (f32)spriteAnimation->colorElapsed, (f32)spriteAnimation->colorDuration);
            } else {
                ((FclSpriteAnimation *)animation)->color.c0 = (u8)fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->colorMode, (f32)(u32)((FclSpriteAnimation *)animation)->colorStart.c0, (f32)(u32)((FclSpriteAnimation *)animation)->colorEnd.c0, (f32)((FclSpriteAnimation *)animation)->colorElapsed, (f32)(((FclSpriteAnimation *)animation)->colorDuration / 2));
                ((FclSpriteAnimation *)animation)->color.c1 = (u8)fclEaseInterpolate((s32)spriteAnimation->colorMode, (f32)(u32)((FclSpriteAnimation *)animation)->colorStart.c1, (f32)(u32)((FclSpriteAnimation *)animation)->colorEnd.c1, (f32)spriteAnimation->colorElapsed, (f32)(spriteAnimation->colorDuration / 2));
                ((FclSpriteAnimation *)animation)->color.c2 = (u8)fclEaseInterpolate((s32)spriteAnimation->colorMode, (f32)(u32)((FclSpriteAnimation *)animation)->colorStart.c2, (f32)(u32)((FclSpriteAnimation *)animation)->colorEnd.c2, (f32)spriteAnimation->colorElapsed, (f32)(spriteAnimation->colorDuration / 2));
            }
            if (((((FclSpriteAnimation *)(animation))->flags & 0x40) >> 6) == 1) {
                spriteAnimation->colorElapsed = fclAddClamped((s32)spriteAnimation->colorElapsed, 1, (s32)spriteAnimation->colorDuration, 1, 2);
            } else if (spriteAnimation->colorElapsed < MEMBER(s16, animation, FclSpriteAnimation, colorDuration)) {
                spriteAnimation->colorElapsed = fclAddClamped((s32)spriteAnimation->colorElapsed, 1, (s32)MEMBER(s16, animation, FclSpriteAnimation, colorDuration), 0, 1);
            } else {
                animation[0x75] = animation[0x71];
                animation[0x76] = animation[0x72];
                animation[0x77] = animation[0x73];
                if (spriteAnimation->colorReverse == 1) {
                    animation[0x75] = animation[0x6D];
                    animation[0x76] = animation[0x6E];
                    animation[0x77] = animation[0x6F];
                }
                ((FclSpriteAnimation *)(animation))->flags &= ~0x200;
            }
        } else {
            spriteAnimation->colorDelay = fclSubClamped((s32)((FclSpriteAnimation *)animation)->colorDelay, 1, 0, 0, 1);
        }
    }
    if (((((FclSpriteAnimation *)(animation))->flags & 0x10) >> 4) == 1) {
        if (((FclSpriteAnimation *)animation)->scaleDelay == 0) {
            if ((s8)((FclSpriteAnimation *)animation)->scaleReverse == 0) {
                ((FclSpriteAnimation *)animation)->scaleX.value = fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->scaleMode, ((FclSpriteAnimation *)animation)->scaleXStart.value, ((FclSpriteAnimation *)animation)->scaleXEnd.value, (f32)((FclSpriteAnimation *)animation)->scaleElapsed, (f32)((FclSpriteAnimation *)animation)->scaleDuration);
                ((FclSpriteAnimation *)animation)->scaleY.value = fclEaseInterpolate((s32)spriteAnimation->scaleMode, ((FclSpriteAnimation *)animation)->scaleYStart.value, ((FclSpriteAnimation *)animation)->scaleYEnd.value, (f32)spriteAnimation->scaleElapsed, (f32)spriteAnimation->scaleDuration);
            } else {
                ((FclSpriteAnimation *)animation)->scaleX.value = fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->scaleMode, ((FclSpriteAnimation *)animation)->scaleXStart.value, ((FclSpriteAnimation *)animation)->scaleXEnd.value, (f32)((FclSpriteAnimation *)animation)->scaleElapsed, (f32)(((FclSpriteAnimation *)animation)->scaleDuration / 2));
                ((FclSpriteAnimation *)animation)->scaleY.value = fclEaseInterpolate((s32)spriteAnimation->scaleMode, ((FclSpriteAnimation *)animation)->scaleYStart.value, ((FclSpriteAnimation *)animation)->scaleYEnd.value, (f32)spriteAnimation->scaleElapsed, (f32)(spriteAnimation->scaleDuration / 2));
            }
            if (((((FclSpriteAnimation *)(animation))->flags & 0x40) >> 6) == 1) {
                spriteAnimation->scaleElapsed = fclAddClamped((s32)spriteAnimation->scaleElapsed, 1, (s32)spriteAnimation->scaleDuration, 1, 2);
            } else if (spriteAnimation->scaleElapsed < MEMBER(s16, animation, FclSpriteAnimation, scaleDuration)) {
                spriteAnimation->scaleElapsed = fclAddClamped((s32)spriteAnimation->scaleElapsed, 1, (s32)MEMBER(s16, animation, FclSpriteAnimation, scaleDuration), 0, 1);
            } else {
                spriteAnimation->scaleX.value = spriteAnimation->scaleXEnd.value;
                spriteAnimation->scaleY.value = spriteAnimation->scaleYEnd.value;
                if (spriteAnimation->scaleReverse == 1) {
                    spriteAnimation->scaleX.value = spriteAnimation->scaleXStart.value;
                    spriteAnimation->scaleY.value = spriteAnimation->scaleYStart.value;
                }
                ((FclSpriteAnimation *)(animation))->flags &= ~0x10;
            }
        } else {
            spriteAnimation->scaleDelay = fclSubClamped((s32)((FclSpriteAnimation *)animation)->scaleDelay, 1, 0, 0, 1);
        }
    }
    if (((((FclSpriteAnimation *)(animation))->flags & 8) >> 3) == 1) {
        if (((FclSpriteAnimation *)animation)->valueDelay == 0) {
            if ((s8)((FclSpriteAnimation *)animation)->valueReverse == 0) {
                ((FclSpriteAnimation *)animation)->value.value = fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->valueMode, ((FclSpriteAnimation *)animation)->valueStart.value, ((FclSpriteAnimation *)animation)->valueEnd.value, (f32)((FclSpriteAnimation *)animation)->valueElapsed, (f32)((FclSpriteAnimation *)animation)->valueDuration);
                if (((((FclSpriteAnimation *)(animation))->flags & 0x100) >> 8) == 1) {
                    spriteAnimation->value.value = spriteAnimation->value.value + (fclEaseInterpolate(1, 0.0f, 50.0f, (f32)((FclSpriteAnimation *)animation)->pulseElapsed, 100.0f) - 25.0f);
                    spriteAnimation->pulseElapsed = fclAddClamped((s32)spriteAnimation->pulseElapsed, 1, 0xC8, 1, 2);
                }
            } else {
                ((FclSpriteAnimation *)animation)->value.value = fclEaseInterpolate((s32)(s8)((FclSpriteAnimation *)animation)->valueMode, ((FclSpriteAnimation *)animation)->valueStart.value, ((FclSpriteAnimation *)animation)->valueEnd.value, (f32)((FclSpriteAnimation *)animation)->valueElapsed, (f32)(((FclSpriteAnimation *)animation)->valueDuration / 2));
                if (((((FclSpriteAnimation *)(animation))->flags & 0x100) >> 8) == 1) {
                    spriteAnimation->value.value = spriteAnimation->value.value + (fclEaseInterpolate(1, 0.0f, 50.0f, (f32)((FclSpriteAnimation *)animation)->pulseElapsed, 100.0f) - 25.0f);
                    spriteAnimation->pulseElapsed = fclAddClamped((s32)spriteAnimation->pulseElapsed, 1, 0xC8, 1, 2);
                }
            }
            if (((((FclSpriteAnimation *)(animation))->flags & 0x40) >> 6) == 1) {
                spriteAnimation->valueElapsed = fclAddClamped((s32)spriteAnimation->valueElapsed, 1, (s32)spriteAnimation->valueDuration, 1, 2);
            } else if (spriteAnimation->valueElapsed < MEMBER(s16, animation, FclSpriteAnimation, valueDuration)) {
                spriteAnimation->valueElapsed = fclAddClamped((s32)spriteAnimation->valueElapsed, 1, (s32)MEMBER(s16, animation, FclSpriteAnimation, valueDuration), 0, 1);
            } else {
                spriteAnimation->value.value = spriteAnimation->valueEnd.value;
                if (spriteAnimation->valueReverse == 1) {
                    spriteAnimation->value.value = spriteAnimation->valueStart.value;
                }
                ((FclSpriteAnimation *)(animation))->flags &= ~8;
            }
        } else {
            spriteAnimation->valueDelay = fclSubClamped((s32)((FclSpriteAnimation *)animation)->valueDelay, 1, 0, 0, 1);
        }
    }
    return (s32)animation;
}

#pragma push
/* measured: retail keeps the global and field loads and the final call's argument setup in source
 * order, which needs propagation off. */
#pragma opt_propagation off
#pragma push
/* measured: retail hoists loop-invariant work out of the signed-short loops, which needs loop
 * invariants on. */
#pragma opt_loop_invariants on
// Sets a sprite's four corner quads from its fixed inputs, sets the sky render states for the quad
// draw, and writes the four corner positions.
// FUN_002B9AB0
/* measured: this function relies on the propagation and loop-invariant settings above to follow
 * retail's load order. */
void fclSpriteBuildCornerQuads(u8 *task, u8 *entry) {
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

    scale = 1.0f / ((RwCamera *)kwlnGetCamera())->nearPlane;
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
    ((FclSpriteListEntry *)(entry))->vertices[0].u = ((FclSpriteListEntry *)(entry))->left;
    ((FclSpriteListEntry *)(entry))->vertices[0].v = ((FclSpriteListEntry *)(entry))->top;
    ((FclSpriteListEntry *)(entry))->vertices[1].u = ((FclSpriteListEntry *)(entry))->right;
    ((FclSpriteListEntry *)(entry))->vertices[1].v = ((FclSpriteListEntry *)(entry))->top;
    ((FclSpriteListEntry *)(entry))->vertices[2].u = ((FclSpriteListEntry *)(entry))->left;
    ((FclSpriteListEntry *)(entry))->vertices[2].v = ((FclSpriteListEntry *)(entry))->bottom;
    ((FclSpriteListEntry *)(entry))->vertices[3].u = ((FclSpriteListEntry *)(entry))->right;
    ((FclSpriteListEntry *)(entry))->vertices[3].v = ((FclSpriteListEntry *)(entry))->bottom;
    for (i = 0; i < 4; i++) {
        j = i;
        p = entry;
        q = (u8 *)((s32)p + (off = (s32)j << 6));
        d = *(f32 *)D_008872F8;
        h = ((FclSpriteListEntry *)(entry))->animation.depth;
        ((FclSpriteListEntry *)(q))->vertices[0].depth = d - h;
        ((FclSpriteListEntry *)(q))->vertices[0].reciprocalScale = scale;
        ((FclSpriteListEntry *)(q))->vertices[0].red.value = (f32)(u32)((FclSpriteListEntry *)(entry))->animation.color.c0;
        ((FclSpriteListEntry *)(q))->vertices[0].green.value = (f32)(u32)((FclSpriteListEntry *)(entry))->animation.color.c1;
        ((FclSpriteListEntry *)(q))->vertices[0].blue.value = (f32)(u32)((FclSpriteListEntry *)(entry))->animation.color.c2;
        ((FclSpriteListEntry *)(q))->vertices[0].alpha = (f32)(u32)((FclSpriteListEntry *)(entry))->animation.alpha;
    }
    ((FclSpriteListEntry *)(entry))->vertices[0].x = ((FclSpriteListEntry *)(entry))->animation.position.x;
    ((FclSpriteListEntry *)(entry))->vertices[0].y = ((FclSpriteListEntry *)(entry))->animation.position.y;
    ((FclSpriteListEntry *)(entry))->vertices[1].x = ((FclSpriteListEntry *)(entry))->animation.position.x +
                            (f32)((FclSpriteListEntry *)(entry))->width * ((FclSpriteListEntry *)(entry))->animation.scaleX.value;
    ((FclSpriteListEntry *)(entry))->vertices[1].y = ((FclSpriteListEntry *)(entry))->animation.position.y;
    ((FclSpriteListEntry *)(entry))->vertices[2].x = ((FclSpriteListEntry *)(entry))->animation.position.x;
    ((FclSpriteListEntry *)(entry))->vertices[2].y = ((FclSpriteListEntry *)(entry))->animation.position.y +
                            (f32)((FclSpriteListEntry *)(entry))->height * ((FclSpriteListEntry *)(entry))->animation.scaleY.value;
    ((FclSpriteListEntry *)(entry))->vertices[3].x = ((FclSpriteListEntry *)(entry))->animation.position.x +
                            (f32)((FclSpriteListEntry *)(entry))->width * ((FclSpriteListEntry *)(entry))->animation.scaleX.value;
    ((FclSpriteListEntry *)(entry))->vertices[3].y = ((FclSpriteListEntry *)(entry))->animation.position.y +
                            (f32)((FclSpriteListEntry *)(entry))->height * ((FclSpriteListEntry *)(entry))->animation.scaleY.value;
    r = ((FclSpriteListEntry *)(entry))->resource;
    one = 1;
    tbl[0](one, *(s32 *)r);
}
#pragma pop


/* measured: propagation off orders the compare loads as retail, and the (u32)i 0x220 entry
 * recompute is kept separate from the s32 form. Updates each list entry: active entries advance
 * tweens and queue fclSpriteBuildCornerQuads while visible; idle ones clear their active bit. */
/* Advance the tweens of every active sprite list entry and queue fclSpriteBuildCornerQuads for the
 * visible ones. Clear the active bit on entries that have no visible scale or alpha. */
// FUN_002B9E10
s32 fclSpriteListUpdate(u8 *task) {
    u8 *q;
    u8 *p;
    s32 i;
    s16 *r;
    f32 a;
    f32 g;

    q = ((KwlnTask *)(task))->work;
    p = q;
    for (i = 0; i < ((FclSpriteList *)(p))->count; i++) {
        q = p + i * 0x220;
        r = (s16 *)(q + 0x104);
        if ((((FclSpriteListEntry *)(q))->animation.flags & 1) == 1) {
            memcpy((void *)r, fclSpriteUpdateTweens((u8 *)r), 0xF0);
            a = ((FclSpriteListEntry *)(q))->animation.scaleX.value;
            g = fGpffff8504;
            if (!(a <= g) && !(((FclSpriteListEntry *)(q))->animation.scaleY.value <= g) && (((FclSpriteListEntry *)(q))->animation.alpha > 0)) {
                u8 *res;
                u8 *e;
                e = p + (u32)i * 0x220;
                res = PrimQueueDrawPrimitive(D_00793E80 + ((FclSpriteListEntry *)(e))->order * 0x30, 4, (void *)e, 4);
                ((FclDrawQueueNode *)res)->draw.pointer = (void *)fclSpriteBuildCornerQuads;
                ((FclDrawQueueNode *)res)->data.work = e;
            } else {
                if (*r == 1) {
                    *r &= ~1;
                }
            }
        }
    }
    return 0;
}
#pragma pop
// Destroy callback for the list task created by fclSpriteListCreateChild; frees its work block.
// FUN_002B9F60
void fclSpriteDestroyListTask(u8 *task) {
    u8 *p = ((KwlnTask *)(task))->work;
    jtbl_008873EC[0](p);
}

// Creates a child task holding a list of 48 entries of 0x220 bytes, clears each entry's state and
// stores the count argument.
// FUN_002B9F90
s32 fclSpriteListCreateChild(s32 parent, s16 count, s32 resource) {
    s32 handle;
    u8 *work;
    s32 entryIndex;
    chkmemAllocSiteTag(&D_0063F178, 0x693);
    work = D_008873F4[0](1, 0x6610, 0x40000);
    handle = (s32)kwlnTaskCreateChild((void *)((void *)(parent)), (const void *)(D_0063F1E0), 0xF, 0, 0, fclSpriteListUpdate, fclSpriteDestroyListTask, (u8 *)(work));
    for (entryIndex = 0; entryIndex < 0x30; entryIndex++) {
        ((FclSpriteListEntry *)(work + entryIndex * 0x220))->animation.flags = 0;
        ((FclSpriteList *)work)->entries[entryIndex].resource = (u8 *)resource;
    }
    ((FclSpriteList *)(work))->count = count;
    return handle;
}
