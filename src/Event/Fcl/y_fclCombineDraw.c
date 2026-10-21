#include "operand_order_internal.h"
#include "fcl_row_mode.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "fcl_row_draw.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "shdPersona_internal.h"
/* Original translation unit y_fclCombineDraw.c (from __FILE__ assert strings). */
#include "type.h"
#include "sdk_snd_internal.h"

#include "fcl_combine_internal.h"
#include "fcl_combine_row_internal.h"
#include "datPersona_internal.h"
#include "kwln_task_internal.h"
#include "fcl_object_internal.h"

#include "member_access.h"

/* Unit settings: independent variable-lifetime optimization enabled. */
#pragma opt_lifetimes on
/* fclDrawTaskCreate allocates and clears 0x14 bytes for this work block. */
typedef struct {
    s8 state;
    u8 pad01[3];
    u32 personaHandle;
    s32 value;
    s8 selector;
    s8 flag;
    u8 pad0E[2];
    s32 extraValue;
} FclPersonaDrawWork;

/* Loader work block allocated as 0x48 bytes, holding sprite requests, resource directories and the
 * message-window slot. */
typedef struct {
    s8 state;
    u8 pad01[3];
    u32 firstSpriteRequest;
    u32 secondSpriteRequest;
    u32 firstDirectory;
    u32 secondDirectory;
    u32 thirdDirectory;
    u32 fourthDirectory;
    u32 messageDirectory;
    u32 extraDirectory;
    u32 firstResource;
    u32 secondResource;
    u32 thirdResource;
    u32 fourthResource;
    u32 firstResourceRequest;
    u32 secondResourceRequest;
    u32 thirdResourceRequest;
    u32 fourthResourceRequest;
    s8 messageWindow;
    s8 destroyRequested;
    u8 pad46[2];
} FclCombineLoaderWork;

/* The detail tables contain five four-byte effects per day (0x14), or a
   header and five effects per rule (0x1C); +2/+A are the effect argument. */
typedef struct {
    s8 kind;
    u8 pad01;
    u16 argument;
} FclCombineDetailEffect;

typedef struct {
    u8 pad00[2];
    s8 kind;
    u8 pad03;
    s16 firstPersona;
    s16 secondPersona;
    FclCombineDetailEffect effects[5];
} FclCombineCalendarRule;

/* The ball allocator reserves 0xF10 bytes; fourteen inline quad packets and
   the animation state precede the color-mode byte used by the row renderer. */
typedef struct {
    u8 pad00[0xF00];
    s8 colorMode;
    u8 padF01[0xF];
} FclCombineBallWork;

/* Model work is 0xF4 bytes; the selected-name path clears byte +1. */
typedef struct {
    s8 state;
    u8 unk1;
    u8 pad02[0xF2];
} FclCombineModelState;

/* Extend the shared sprite prefix (sizeof 0x8C) only for fields exercised
   here: the color-animation flag and the independent X/Y scale values. */
typedef struct {
    FclCombineRowSprite row;
    u8 pad8C[5];
    s8 colorTransitionActive;
    u8 pad92[0xE];
    f32 scaleX;
    u8 padA4[8];
    f32 scaleY;
    u8 padB0[0x20];
    f32 unkD0;
} FclCombineDrawSprite;

/* fclSpriteWork clip records: position and 16-byte bounds precede depth;
   row/column setup writes the order and state byte at 0x120/0x124. */
typedef struct {
    FclVec2 position;
    FclBoundsPacket bounds;
    f32 depth;
    u8 pad1C[0x104];
    s32 order;
    u8 unk124;
} FclCombineClipWork;

/* Choice records have a kind and a label-resource byte, with stride two. */
typedef struct {
    u8 kind;
    u8 resource;
} FclCombineChoice;


/* Copy the two-coordinate position through its existing storage representation. measured: retail
 * copies the position as one storage-typed block; direct struct assignment changes code in both
 * panel callers. */
static inline void fclCopyPositionStorage(void *out, const void *in)
{
    *(FclVec2 *)out = *(const FclVec2 *)in;
}

/* Clear an optional eight-byte buffer without calling the bulk memory routine. */
static inline void fclClearEightBytes(u8 *p)
{
    s32 n = 8;

    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
}


/* Colors are native four-byte values and position pairs use FclVec2. */
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void *memset(void *dest, s32 value, s32 size);

extern u8 *shdPersonaTaskCreate(s32, s32, s32, s32, s32);
extern s32 fclDrawTaskStep(u8 *ownerTask);
extern void fclDrawTaskDestroy(u8 *task);
extern s32 datGetFlag(s32);
extern s32 kwlnTaskIsLinked(void *);
extern void shdPersonaSetOrigin(u8 *task, f32 *position);
extern void shdPersonaSetDisplayState(u8 *, s32, u32, s8);
extern void shdPersonaBeginClose(u8 *task);
extern void shdPersonaBeginDisplayAndEndSelection(u8 *, s32, s32, s8);
extern void shdPersonaBeginDisplay(u8 *, s32, s32, s8);
extern void shdPersonaStartSlideOut(u8 *task);
extern void shdPersonaEnterCloseState(u8 *task);
extern void fclSpriteStartAlphaAt(s16, u8, u8, u8, s32, s16);
extern u8 *fclSpriteEntry(s16);
extern s16 fclSpriteFlagBit(s16, s16);
extern void fclSpriteReset(s16, s16);
extern u8 *yListSlotWork(s8 list);
extern u8 *yListSlotEntry(s8 list, s16 index);
extern void nmMesWindowSetNumberColor(u8 *, s16, FclDrawColor);
extern s32 fclPackRgba(u8, u8, u8, u8);
extern void fclSpriteStartColorAt(s16, s32, s32, s32, s32, s32);
extern void fclSpriteStartColor(u8 *, FclDrawColor, FclDrawColor, u8, s16, s32);
extern void fclCombineSetSlotColors(u8 *, s16, FclDrawColor, FclDrawColor, FclDrawColor);
extern s8 fclCombineMapSlotKind(s8);
extern void fclCombineSlideInHeaderSprites(f32, f32, u8 *, s64, s8);
extern void fclCombineDrawPersonaRow(u8 *, FclVec2, s8, s8, s32, s16, s16, s8, s8, u8);
extern f32 D_006440F0[];
extern f32 D_006440F8[];
extern f32 D_00644290[];
extern f32 D_00644298[];
extern f32 D_00644350[];

extern void fclSpriteStartPositionAt(s16, FclVec2, FclVec2, u32, u32, s16);
extern u8 *sdkSpriteNewNode(u32, u32);
extern f32 sdkSpriteScaledHeight(u8 *);
extern void sdkSpriteFreeNode(void *node);
extern void fclSpriteSetFlag(s16, s16, s8);
extern f32 D_007495C0[];
extern f32 D_00749600[];
extern s32 datGetPersonaCacheCompletionPercent(void);
extern void fclSpriteResetScale(s16);
extern s32 fclAddClamped(s32, s32, s32, s32, s8);
extern s32 fclSubClamped(s32, s32, s32, s32, s8);
extern s16 yListStepIndex(s16, s16, s16, s16, s16);
extern void yListAdvanceCursorScroll(s32, s32, s32, s32, s16 *, s16 *);
extern void yListRetreatCursorScroll(s32, s32, s32, s32, s16 *, s16 *);
extern f32 iGpffff8360;
extern f32 iGpffff8504;
extern void fclCombinePartyRow(u8 *, FclVec2, s32, s32, s16, s16, s8, s8);
extern s32 fclCombineGetSpritePool(void);


extern u8 *fclSpriteWork(u8 *);
extern f32 sdkSpriteScaledWidth(u8 *);
extern void fclCombineDrawListRowPlain(u8 *, s8, FclVec2, s16, s16, s8);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern void sdkSpriteRelease(u8 *node);
extern void func_003ef3a0(u8 *resource);
extern void itfMesWindowReleaseIfActive(s32 handle);
extern void H_Cdvd_Destroy(u8 *cdvd);
extern void (*D_008873EC[])(void *);
extern char D_00644D30[];
extern char D_00644D50[];
extern char D_00644DB0[];
extern char D_00644DD0[];
extern char D_00644DF0[];
extern char D_00644E10[];
extern char D_00644E30[];
extern char D_00644E48[];
extern char D_00644E60[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern f32 D_00644C90[];
extern f32 D_00644020[];
extern f32 D_00644098[];
extern f32 D_00644AD0[];
extern f32 D_00644B00[];
extern s8 D_00749530[];
extern s64 iGpffffa900;
extern s64 iGpffffa908;
extern s32 iGpffffa910;
extern s32 iGpffffb598;
extern s32 iGpffffb440;
extern u8 D_00796310[];
extern u8 D_00796370[];
extern s32 itfMesWindowQueueEntry(f32, f32, f32, s32, s32, s32, s32, s32, s32, u8 *);
extern int frFontExDrawTextDeferredOutB(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
extern void fclCombineSetModel(s32, u16, s32);
extern s32 fclCombineGetWork(u8 *);
extern void shdPersonaSetOpacity(u8 *, f32);
extern s8 fclCombineGetRowCount(void);
extern void fclCombineDrawResourceAt(s32, FclVec2, f32, s32, u8, s32, f32, f32, void *);
extern f32 fclEaseInterpolate(s64, f32, f32, f32, f32);
extern u8 D_00795E60[];

extern void func_00440b68();
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern void fclCombineCdvdTaskDestroy(u8 *);
extern char D_00644D70[];
extern char D_00644D90[];
extern f32 D_00644880[];
extern f32 D_00644888[];
extern f32 D_00644890[];
extern f32 D_00644898[];
extern f32 D_006440B8[];
extern void fclSpriteSetHidden(u8 *, u8);
extern f32 D_00643D70[];
extern f32 D_00644CA0[];
extern f32 D_006441C8[];
extern f32 D_006441D0[];
extern f32 D_006441C0[];
extern f32 D_006441E0[];
extern f32 D_006441D8[];

// Create a draw task under parent with a cleared 0x14-byte work block and initial state 7.
// FUN_00314320
s32 fclDrawTaskCreate(s32 parent) {
    s32 result;
    u8 *p;

    chkmemAllocSiteTag(D_00644D30, 0x16D);
    p = (u8 *)D_008873F4[0](1, 0x14, 0x40000);
    memset(p, 0, 0x14);
    result = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_00644D50), 0xF, 0, 0, fclDrawTaskStep, fclDrawTaskDestroy, (u8 *)(p));
    ((FclPersonaDrawWork *)p)->state = 7;
    ((FclPersonaDrawWork *)(p))->personaHandle = (s32)shdPersonaTaskCreate(result, 0xF, 3, 5, 5);
    ((FclPersonaDrawWork *)(p))->flag = 0;
    return result;
}

// Enter state 0x10, or state 0xF and close the Persona object when closeObject is 1.
// FUN_00314400
void fclDrawSetState(u8 *task, s8 closeObject) {
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    ((FclPersonaDrawWork *)(work))->state = 0x10;
    if (closeObject == 1) {
        ((FclPersonaDrawWork *)(work))->state = 0xF;
        shdPersonaBeginClose((u8 *)((FclPersonaDrawWork *)(work))->personaHandle);
    }
}

// Store value/selector, enter mode 0, and place the Persona origin at Y = 40 * row.
// FUN_00314450
void fclDrawSetPlacement(u8 *task, s32 value, u8 selector, s32 row) {
    /* Keep the integer work handle while naming both remaining fields. */
    f32 originCoordinates1[2];
    u32 work = (u32)((struct KwlnTask *)task)->work;

    fclClearEightBytes((u8 *)originCoordinates1);
    originCoordinates1[1] = 40.0f * (f32)row;
    ((FclPersonaDrawWork *)work)->value = value;
    ((FclPersonaDrawWork *)work)->selector = selector;
    ((FclPersonaDrawWork *)(u32)work)->state = 0;
    shdPersonaSetOrigin((u8 *)((FclPersonaDrawWork *)(u32)work)->personaHandle, originCoordinates1);
}

// Fcl draw placement (ex): as fclDrawSetPlacement with mode 8 and an extra value.
// FUN_003144D0
void fclDrawSetPlacementEx(u8 *task, s32 value, s8 selector, s32 extraValue, s32 row) {
    f32 originCoordinates1[2];
    u32 work = (u32)((struct KwlnTask *)task)->work;

    fclClearEightBytes((u8 *)originCoordinates1);
    originCoordinates1[1] = 40.0f * (f32)row;
    ((FclPersonaDrawWork *)(u32)work)->value = value;
    ((FclPersonaDrawWork *)(u32)work)->selector = selector;
    ((FclPersonaDrawWork *)(u32)work)->state = 8;
    ((FclPersonaDrawWork *)(u32)work)->extraValue = extraValue;
    shdPersonaSetOrigin((u8 *)((FclPersonaDrawWork *)(u32)work)->personaHandle, originCoordinates1);
}

// Store value/selector and display the Persona; keepSelection chooses the display variant.
// FUN_00314560
void fclDrawSetSlot(u8 *task, s32 value, s8 selector, s8 keepSelection) {
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    if (keepSelection == 0) {
        ((FclPersonaDrawWork *)(work))->value = value;
        ((FclPersonaDrawWork *)(work))->selector = selector;
        shdPersonaBeginDisplayAndEndSelection((u8 *)((FclPersonaDrawWork *)(work))->personaHandle, 0, ((FclPersonaDrawWork *)(work))->value, selector);
        return;
    }
    ((FclPersonaDrawWork *)(work))->value = value;
    ((FclPersonaDrawWork *)(work))->selector = selector;
    shdPersonaBeginDisplay((u8 *)((FclPersonaDrawWork *)(work))->personaHandle, 0, ((FclPersonaDrawWork *)(work))->value, selector);
}
// Fcl draw active: 1 when the task exists, is live and its state is below 6.
// FUN_003145E0
s32 fclDrawIsActive(u8 *task) {
    /* Read the task work slot as a word before dereferencing it; this also preserves the null-work guard. */
    if (task == 0) {
        return 0;
    }
    if (kwlnTaskIsLinked((void *)task) == 0) {
        return 0;
    }
    if ((u32)((struct KwlnTask *)task)->work == 0) {
        return 0;
    }
    return ((FclPersonaDrawWork *)((struct KwlnTask *)task)->work)->state < 6;
}

// FUN_00314660
s8 fclDrawGetState(u8 *task) {
    return ((FclPersonaDrawWork *)(((struct KwlnTask *)task)->work))->state;
}

// FUN_00314670
void fclDrawSetStateByte(u8 *task, s8 state) {
    ((FclPersonaDrawWork *)(((struct KwlnTask *)task)->work))->state = state;
}

// Fcl draw reset scale: resets the object's scale to the default.
// FUN_00314680
void fclDrawResetScale(u8 *task) {
    s64 originPacket;
    f32 *p;
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    shdPersonaSetOrigin((u8 *)((FclPersonaDrawWork *)(work))->personaHandle,
                  (p = (f32 *)&originPacket, (originPacket = iGpffffa900, p)));
}
// Fcl draw handle value: sets the value on the object handle.
// FUN_003146C0
void fclDrawSetHandleValue(u8 *task, u32 value) {
    shdPersonaSetHandleValue(((FclPersonaDrawWork *)(((struct KwlnTask *)task)->work))->personaHandle, value);
}

/* The stored selector is a signed byte; it is reloaded from the work block at the call. */
// FUN_003146F0
void fclDrawSetSlotMode(u8 *task, s32 value, s8 selector)
{
    u8 *obj;

    obj = ((struct KwlnTask *)task)->work;
    ((FclPersonaDrawWork *)obj)->value = value;
    ((FclPersonaDrawWork *)obj)->selector = selector;
    shdPersonaSetDisplayState((u8 *)((FclPersonaDrawWork *)obj)->personaHandle, 0, MEMBER(u32, obj, FclPersonaDrawWork, value), ((FclPersonaDrawWork *)obj)->selector);
}


// FUN_00314740
void fclDrawSetFlag(u8 *task, s8 flag) {
    ((FclPersonaDrawWork *)(((struct KwlnTask *)task)->work))->flag = flag;
}

// Restore the retained origin and select the object's slide-out or close transition from visible.
// FUN_00314750
void fclDrawSetVisible(u8 *task, s8 visible) {
    u8 *work;
    s64 originPacket;
    f32 *p;

    work = ((struct KwlnTask *)task)->work;
    shdPersonaSetOrigin((u8 *)((FclPersonaDrawWork *)work)->personaHandle,
                  (p = (f32 *)&originPacket, (originPacket = iGpffffa908, p)));
    if (visible == 0) {
        shdPersonaStartSlideOut((u8 *)MEMBER(u32, work, FclPersonaDrawWork, personaHandle));
    } else {
        shdPersonaEnterCloseState((u8 *)MEMBER(u32, work, FclPersonaDrawWork, personaHandle));
    }
}

// Fcl draw get resource: returns the object handle.
// FUN_003147D0
u8 *fclDrawGetResource(u8 *task) {
    return (u8 *)((FclPersonaDrawWork *)((struct KwlnTask *)task)->work)->personaHandle;
}

/* measured: retail counts the 0x174 row loop in the early resource id's register and carries each
 * row resource in base; opt_loop_invariants hoists the row floats. */
#pragma push
/* measured: retail's row layout needs loop-invariant hoisting with lifetimes off. */
#pragma opt_loop_invariants on
/* measured: retail does not split local lifetimes in this row function. */
#pragma opt_lifetimes off
// Draw a combine-list row's bars and label at position, retaining its sprite handle in work+0x258.
// Kinds 0x174 and 0x160 add extra cells; kind 0x16C draws through fclCombineDrawListRowPlain at a fixed position.
// FUN_003147E0
void fclCombineDrawListRow(u8 *task, s8 row, FclVec2 position, s16 resource, s16 delay, s8 mode) {
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    FclVec2 drawPosition6;
    FclVec2 drawPosition7;
    FclVec2 drawPosition8;
    FclBoundsPacket boundsPacket1;
    u8 *work;
    u8 *h;
    u8 **slot;
    s16 base;
    s32 order;
    s16 id;
    s16 kind;
    s32 r;
    s32 two;
    s32 o2;
    f32 x;

    work = ((struct KwlnTask *)task)->work;
    kind = resource;
    base = row * 5 + 0x66;
    if (kind == 0x16C) {
        drawPosition3 = fclMakeVec2(67.0f, 175.0f);
        fclCombineDrawListRowPlain(task, row, drawPosition3, 0x16C, delay, mode);
        return;
    }
    two = row * 2;
    id = two + 0x1F4;
    fclSpriteReset(id, 0x1AC);
    order = base;
    o2 = order + 2;
    drawPosition4 = fclMakeVec2(position.x, position.y);
    drawColor1 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
    fclSpriteStartShowHide(id, drawPosition4, 0x1AC, drawColor1, 154.0f, o2, mode, 3, 3, delay, fclCombineGetSpritePool());
    id = two + 0x1F5;
    fclSpriteReset(id, 0x1AF);
    drawPosition2 = fclMakeVec2(258.0f + position.x, position.y);
    drawColor2 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
    fclSpriteStartShowHide(id, drawPosition2, 0x1AF, drawColor2, 154.0f, o2, mode, 3, 3, delay, fclCombineGetSpritePool());
    drawPosition1 = fclMakeVec2(drawPosition2.x - 28.0f, drawPosition2.y);
    id = row + 0x2FB;
    fclSpriteReset(id, 0x131);
    drawPosition2 = fclMakeVec2(266.0f + position.x, position.y);
    drawColor3 = fclMakeDrawColor(0x25, 0x2F, 0x94, 0xFF);
    fclSpriteStartShowHide(id, drawPosition1, 0x131, drawColor3, 153.0f, order + 3, mode, 3, 3, delay, fclCombineGetSpritePool());
    fclSpriteSetFlag(id, 0xE, 0);
    h = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x131);
    slot = (u8 **)(work + 0x258) + row;
    *(FclVec2 *)fclSpriteWork(*slot) = drawPosition1;
    x = sdkSpriteScaledWidth(h);
    boundsPacket1 = fclMakeBoundsPacket(x, sdkSpriteScaledHeight(h));
    ((FclBoundsPacket *)(fclSpriteWork(*slot) + 8))->representation = boundsPacket1.representation;
    ((FclCombineClipWork *)fclSpriteWork(*slot))->order = order;
    ((FclCombineClipWork *)fclSpriteWork(*slot))->depth = 152.0f;
    ((FclCombineClipWork *)fclSpriteWork(*slot))->unk124 = 0;
    sdkSpriteFreeNode(h);
    if (kind == -1) {
        return;
    }
    if (kind == 0x174) {

        for (id = 0, o2 = order + 4; id < 2; id++) {
            r = id + 0x174;
            base = r;
            fclSpriteStartShowHide(base, drawPosition5 = fclMakeVec2(6.0f + position.x + (f32)(id * 0x67), 4.0f + position.y), r,
                          drawColor4 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF), 152.0f, o2, mode, 3, 3, delay, fclCombineGetSpritePool());
        }
        return;
    }
    if (datGetFlag(0x1305) != 0 && kind == 0x160) {

        fclSpriteStartShowHide(0x160, drawPosition6 = fclMakeVec2(6.0f + position.x, 4.0f + position.y), 0x160,
                      drawColor5 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF), 152.0f, base + 4, mode, 3, 3, delay, fclCombineGetSpritePool());
        fclSpriteReset(0x2EB, 0x16F);
        fclSpriteStartShowHide(0x2EB, drawPosition7 = fclMakeVec2(100.0f + (6.0f + position.x), 4.0f + position.y), 0x16F,
                      drawColor6 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF), 152.0f, base + 4, mode, 3, 3, delay, fclCombineGetSpritePool());
        return;
    }
    drawPosition8 = fclMakeVec2(6.0f + position.x, 4.0f + position.y);
    drawColor7 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
    fclSpriteStartShowHide(resource, drawPosition8, resource, drawColor7, 152.0f, order + 4, mode, 3, 3, delay, fclCombineGetSpritePool());
}
#pragma pop
/* Fcl combine list row, plain variant: the same row layout without the kind-specific cells; reached
 * for kind 0x16C. */
// FUN_00314EF0
void fclCombineDrawListRowPlain(u8 *task, s8 row, FclVec2 position, s16 resource, s16 delay, s8 mode) {
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclBoundsPacket boundsPacket1;
    u8 *work;
    u8 *h;
    u8 *q;
    u8 **slot;
    s16 order;
    s16 res;
    s32 two;
    s32 o2;
    f32 x;

    work = ((struct KwlnTask *)task)->work;
    order = row * 5 + 0x66;
    two = row * 2;
    res = two + 0x1F4;
    fclSpriteReset(res, 0x1AC);
    o2 = order + 2;
    drawPosition2 = fclMakeVec2(position.x, position.y);
    drawColor1 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
    fclSpriteStartShowHide(res, drawPosition2, 0x1AC, drawColor1, 151.0f, o2, mode, 3, 3, delay, fclCombineGetSpritePool());
    res = two + 0x1F5;
    fclSpriteReset(res, 0x1B3);
    x = 217.0f + position.x;
    drawPosition3 = fclMakeVec2(x, position.y);
    drawColor2 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
    fclSpriteStartShowHide(res, drawPosition3, 0x1B3, drawColor2, 151.0f, o2, mode, 3, 3, delay, fclCombineGetSpritePool());
    drawPosition1 = fclMakeVec2(x - 28.0f, position.y);
    res = row + 0x2FB;
    fclSpriteReset(res, 0x131);
    drawColor3 = fclMakeDrawColor(0x25, 0x2F, 0x94, 0xFF);
    fclSpriteStartShowHide(res, drawPosition1, 0x131, drawColor3, 150.0f, order + 3, mode, 3, 3, delay, fclCombineGetSpritePool());
    fclSpriteSetFlag(res, 0xE, 0);
    h = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x131);
    slot = (u8 **)(work + 0x258) + row;
    *(FclVec2 *)fclSpriteWork(*slot) = drawPosition1;
    x = sdkSpriteScaledWidth(h);
    boundsPacket1 = fclMakeBoundsPacket(x, sdkSpriteScaledHeight(h));
    ((FclBoundsPacket *)(fclSpriteWork(*slot) + 8))->representation = boundsPacket1.representation;
    ((FclCombineClipWork *)fclSpriteWork(*slot))->order = order;
    ((FclCombineClipWork *)fclSpriteWork(*slot))->depth = 149.0f;
    ((FclCombineClipWork *)fclSpriteWork(*slot))->unk124 = 0;
    sdkSpriteFreeNode(h);
    fclSpriteReset(resource, resource);
    drawPosition4 = fclMakeVec2(6.0f + position.x, 8.0f + position.y);
    drawColor4 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
    fclSpriteStartShowHide(resource, drawPosition4, resource, drawColor4, 148.0f, order + 4, mode, 3, 3, delay, fclCombineGetSpritePool());
}

/* Draws the three slot rows at the base offset with fclCombineDrawListRow, then recolours the
 * selected slot's sprites; the middle row uses 0x160 when flag 0x1305 is set. */
// FUN_00315310
void fclCombineDrawSlotRows(u8 *task, s64 delay) {
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclVec2 drawPosition1;
    s32 i;
    u8 *work;
    u32 base;
    s64 raw;
    s32 off;
    u8 *p;

    raw = delay;
    work = ((struct KwlnTask *)task)->work;
    ((FclCombineWork *)(work))->selectedIds[0] = 0x15D;
    ((FclCombineWork *)(work))->selectedIds[1] = 0x15E;
    ((FclCombineWork *)(work))->selectedIds[2] = 0x15F;
    if (datGetFlag(0x1305) != 0) {
        MEMBER(s16, work, FclCombineWork, selectedIds[1]) = 0x160;
    }
    i = 0;
    base = (s16)raw;
    for (; (s16)i < 3; i = (s16)(i + 1)) {
        off = (s16)i * 2;
        drawPosition1 = fclMakeVec2(26.0f, (f32)((s16)i * 34 + 0x57));
        fclCombineDrawListRow(task, (s8)(s16)i, drawPosition1, ((FclCombineWork *)(work + off))->selectedIds[0], (s16)(base + off), 0);
    }
    drawColor1 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
    p = fclSpriteEntry((s16)(((FclCombineWork *)work)->slotCursor * 2 + 0x1F4));
    ((FclCombineRowSprite *)p)->color = drawColor1;
    drawColor2 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
    p = fclSpriteEntry((s16)(MEMBER(s8, work, FclCombineWork, slotCursor) * 2 + 0x1F5));
    ((FclCombineRowSprite *)p)->color = drawColor2;
    drawColor3 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    p = fclSpriteEntry((s16)((FclCombineWork *)(operandOrderAddUnsigned(MEMBER(s8, work, FclCombineWork, slotCursor) * 2, (u32)work)))->selectedIds[0]);
    ((FclCombineRowSprite *)p)->color = drawColor3;
    if (MEMBER(s8, work, FclCombineWork, slotCursor) == 1) {
        if (datGetFlag(0x1305) != 0) {
        drawColor4 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        p = fclSpriteEntry(0x2EB);
        ((FclCombineRowSprite *)p)->color = drawColor4;
        }
    }
    drawColor5 = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
    p = fclSpriteEntry((s16)(MEMBER(s8, work, FclCombineWork, slotCursor) + 0x2FB));
    ((FclCombineRowSprite *)p)->color = drawColor5;
}

/* Row base pointers are f32 tables cast to FclVec2 *, and fclSpriteCreate takes an s16 resource
 * here. In mode 0, creates and tints the calendar detail sprites; otherwise moves the existing
 * sprites out. */
// FUN_00315600
void fclCombineLayoutDetailSprites(u8 *task, s64 mode) {
    extern s64 datGetDateIndex(void);
    extern s32 calGetWeekdayOfDay(s32 dateIndex);
    extern s32 calHasDayEntry(s32 day);
    extern s64 calGetDayEntryForMonthDay(s32 month, s32 day);
    extern u8 fclCalendarMonth(void);
    extern s32 fclCalendarDay(void);
    extern f32 D_00643DA8[];
    extern f32 D_00643E28[];
    extern f32 D_00643E30[];
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclVec2 pos;
    s32 weekday;
    s16 id;
    s16 id2;
    FclVec2 *b;
    FclVec2 *v;
    u8 *p;

    weekday = calGetWeekdayOfDay((s16)datGetDateIndex());
    b = (FclVec2 *)D_00643DA8;
    pos = fclMakeVec2(b->x, b->y);
    if ((s8)mode == 0) {
        fclSpriteCreate(7, fclMakeVec2(24.0f + b->x, b->y), 94.0f, 0x41);
        drawColor1 = fclMakeDrawColor(0x19, 0x19, 0x19, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(7))->color = drawColor1;
        fclSpriteStartPositionAt(7, fclMakeVec2(300.0f + (24.0f + b->x), b->y), fclMakeVec2(24.0f + b->x, b->y), 0, 0xA, 0);
    } else {
        fclSpriteStartPositionAt(7, fclMakeVec2(24.0f + b->x, b->y), fclMakeVec2(24.0f + (300.0f + b->x), b->y), 0, 0xA, 0);
    }
    if ((s8)mode == 0) {
        fclSpriteCreate((fclCalendarMonth() & 0xFF) / 10 + 9, fclMakeVec2(24.0f + (13.0f + pos.x), pos.y), 89.0f, 0x56);
        id = (fclCalendarMonth() & 0xFF) / 10 + 9;
        fclSpriteStartPositionAt(id, fclMakeVec2(300.0f + (24.0f + (13.0f + pos.x)), pos.y), fclMakeVec2(24.0f + (13.0f + pos.x), pos.y), 0, 0xA, 0);
        fclSpriteCreate(0x2DB, fclMakeVec2(24.0f + (26.0f + pos.x), pos.y), 89.0f, 0x56);
        fclSpriteStartPositionAt(0x2DB, fclMakeVec2(300.0f + (24.0f + (26.0f + pos.x)), pos.y), fclMakeVec2(24.0f + (26.0f + pos.x), pos.y), 0, 0xA, 0);
        fclSpriteCreate(0x19, fclMakeVec2(24.0f + (40.0f + pos.x), pos.y), 89.0f, 0x56);
        fclSpriteStartPositionAt(0x19, fclMakeVec2(300.0f + (24.0f + (40.0f + pos.x)), pos.y), fclMakeVec2(24.0f + (40.0f + pos.x), pos.y), 0, 0xA, 0);
        fclSpriteCreate(0x2DC, fclMakeVec2(24.0f + (50.0f + pos.x), pos.y), 89.0f, 0x56);
        fclSpriteStartPositionAt(0x2DC, fclMakeVec2(300.0f + (24.0f + (50.0f + pos.x)), pos.y), fclMakeVec2(24.0f + (50.0f + pos.x), pos.y), 0, 0xA, 0);
        fclSpriteCreate(0x2DD, fclMakeVec2(24.0f + (63.0f + pos.x), pos.y), 89.0f, 0x56);
        fclSpriteStartPositionAt(0x2DD, fclMakeVec2(300.0f + (24.0f + (63.0f + pos.x)), pos.y), fclMakeVec2(24.0f + (63.0f + pos.x), pos.y), 0, 0xA, 0);
        v = (FclVec2 *)D_00643D70 + weekday;
        fclSpriteCreate((s16)weekday, fclMakeVec2(v->x, v->y), 90.0f, 0x56);
        if (weekday == 0) {
            drawColor2 = fclMakeDrawColor(0xFF, 0xAC, 0x99, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry((s16)weekday))->color = drawColor2;
        }
        if (weekday == 6) {
            drawColor3 = fclMakeDrawColor(0x99, 0xA4, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry((s16)weekday))->color = drawColor3;
        }
        if (calHasDayEntry((s16)datGetDateIndex()) == 1) {
            drawColor4 = fclMakeDrawColor(0xFF, 0xAC, 0x99, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry((s16)weekday))->color = drawColor4;
        }
        fclSpriteStartPositionAt((s16)weekday, fclMakeVec2(300.0f + v->x, v->y), fclMakeVec2(v->x, v->y), 0, 0xA, 0);
        v = (FclVec2 *)D_00643E28;
        fclSpriteCreate(0x17, fclMakeVec2(v->x, v->y), 93.0f, 0x56);
        drawColor5 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x17))->color = drawColor5;
        fclSpriteStartPositionAt(0x17, fclMakeVec2(300.0f + v->x, v->y), fclMakeVec2(v->x, v->y), 0, 0xA, 0);
        v = (FclVec2 *)D_00643E30;
        fclSpriteCreate(0x18, fclMakeVec2(v->x, v->y), 92.0f, 0x57);
        drawColor6 = fclMakeDrawColor(0x19, 0x19, 0x19, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x18))->color = drawColor6;
        fclSpriteStartPositionAt(0x18, fclMakeVec2(300.0f + v->x, v->y), fclMakeVec2(v->x, v->y), 0, 0xA, 0);
        id2 = (s8)calGetDayEntryForMonthDay(fclCalendarMonth() & 0xFF, fclCalendarDay() & 0xFF) + 0x13;
        v = (FclVec2 *)D_00643D70 + id2;
        fclSpriteCreate(id2, fclMakeVec2(v->x, v->y), 91.0f, 0x58);
        drawColor7 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(id2))->color = drawColor7;
        fclSpriteStartPositionAt(id2, fclMakeVec2(300.0f + v->x, v->y), fclMakeVec2(v->x, v->y), 0, 0xA, 0);
    } else {
        id = (fclCalendarMonth() & 0xFF) / 10 + 9;
        pos = ((FclCombineRowSprite *)fclSpriteEntry(id))->position;
        fclSpriteStartPositionAt(id, pos, fclMakeVec2(300.0f + pos.x, pos.y), 0, 0xA, 0);
        pos = ((FclCombineRowSprite *)fclSpriteEntry(0x2DB))->position;
        fclSpriteStartPositionAt(0x2DB, pos, fclMakeVec2(300.0f + pos.x, pos.y), 0, 0xA, 0);
        pos = ((FclCombineRowSprite *)fclSpriteEntry(0x2DC))->position;
        fclSpriteStartPositionAt(0x2DC, pos, fclMakeVec2(300.0f + pos.x, pos.y), 0, 0xA, 0);
        pos = ((FclCombineRowSprite *)fclSpriteEntry(0x2DD))->position;
        fclSpriteStartPositionAt(0x2DD, pos, fclMakeVec2(300.0f + pos.x, pos.y), 0, 0xA, 0);
        pos = ((FclCombineRowSprite *)fclSpriteEntry(0x19))->position;
        fclSpriteStartPositionAt(0x19, pos, fclMakeVec2(300.0f + pos.x, pos.y), 0, 0xA, 0);
        pos = ((FclCombineRowSprite *)fclSpriteEntry((s16)weekday))->position;
        fclSpriteStartPositionAt((s16)weekday, pos, fclMakeVec2(300.0f + pos.x, pos.y), 0, 0xA, 0);
        pos = ((FclCombineRowSprite *)fclSpriteEntry(0x17))->position;
        fclSpriteStartPositionAt(0x17, pos, fclMakeVec2(300.0f + pos.x, pos.y), 0, 0xA, 0);
        pos = ((FclCombineRowSprite *)fclSpriteEntry(0x18))->position;
        fclSpriteStartPositionAt(0x18, pos, fclMakeVec2(300.0f + pos.x, pos.y), 0, 0xA, 0);
        id = (s8)calGetDayEntryForMonthDay(fclCalendarMonth() & 0xFF, fclCalendarDay() & 0xFF) + 0x13;
        pos = ((FclCombineRowSprite *)fclSpriteEntry(id))->position;
        fclSpriteStartPositionAt(id, pos, fclMakeVec2(300.0f + pos.x, pos.y), 0, 0xA, 0);
    }
}

/* Bounds and constructed positions are two-float values; the displacement becomes live in each
 * transition branch and is shared by later rows. Lay out the frame, optional drawPlates sprites,
 * header and count digits; mode 0 creates them. */
// FUN_00316470
void fclCombineLayoutFrame(u8 *task, s64 drawPlates, s8 mode) {
    extern s32 datCalcGetLevelById(s32);
    extern f32 D_00644380[];
    extern f32 D_00644378[];
    extern f32 D_00644388[];
    extern f32 D_00644390[];
    extern f32 D_00644AD8[];
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    FclVec2 drawPosition6;
    FclVec2 drawPosition7;
    FclVec2 drawPosition8;
    FclVec2 drawPosition9;
    FclVec2 drawPosition10;
    FclVec2 drawPosition11;
    FclVec2 drawPosition12;
    FclVec2 drawPosition13;
    FclVec2 drawPosition14;
    FclVec2 drawPosition15;
    FclVec2 drawPosition16;
    FclVec2 drawPosition17;
    FclVec2 drawPosition18;
    FclVec2 drawPosition19;
    FclVec2 drawPosition20;
    FclVec2 drawPosition21;
    FclVec2 drawPosition22;
    FclVec2 drawPosition23;
    FclVec2 drawPosition24;
    FclVec2 drawPosition25;
    FclVec2 drawPosition26;
    FclVec2 drawPosition27;
    FclVec2 drawPosition28;
    FclVec2 drawPosition29;
    FclVec2 drawPosition30;
    FclVec2 drawPosition31;
    FclVec2 drawPosition32;
    FclVec2 drawPosition33;
    FclVec2 drawPosition34;
    f32 slideDistance;
    FclVec2 *b;
    u8 *p;
    (void)task;
    if ((s8)drawPlates == 1) {
        b = (FclVec2 *)D_00644380;
        drawPosition1 = fclMakeVec2(b->x, b->y);
        if ((s8)mode == 0) {
            drawPosition2 = fclMakeVec2(b->x, b->y);
            fclSpriteCreate(0xC2, drawPosition2, 100.0f, 0x41);
            slideDistance = 300.0f;
            drawPosition3 = fclMakeVec2(slideDistance + b->x, b->y);
            drawPosition4 = fclMakeVec2(b->x, b->y);
            fclSpriteStartPositionAt(0xC2, drawPosition3, drawPosition4, 0, 0xA, 0);
        } else {
            slideDistance = 300.0f;
            drawPosition5 = fclMakeVec2(b->x, b->y);
            drawPosition6 = fclMakeVec2(300.0f + b->x, b->y);
            fclSpriteStartPositionAt(0xC2, drawPosition5, drawPosition6, 0, 0xA, 0);
        }
        b = (FclVec2 *)D_00644378;
        drawPosition1 = fclMakeVec2(b->x, b->y);
        if ((s8)mode == 0) {
            drawPosition7 = fclMakeVec2(b->x, b->y);
            fclSpriteCreate(0xC1, drawPosition7, 100.0f, 0x41);
            drawPosition8 = fclMakeVec2(slideDistance + b->x, b->y);
            drawPosition9 = fclMakeVec2(b->x, b->y);
            fclSpriteStartPositionAt(0xC1, drawPosition8, drawPosition9, 0, 0xA, 0);
        } else {
            drawPosition10 = fclMakeVec2(b->x, b->y);
            drawPosition11 = fclMakeVec2(slideDistance + b->x, b->y);
            fclSpriteStartPositionAt(0xC1, drawPosition10, drawPosition11, 0, 0xA, 0);
        }
        b = (FclVec2 *)D_00644388;
        drawPosition1 = fclMakeVec2(b->x, b->y);
        if ((s8)mode == 0) {
            drawPosition12 = fclMakeVec2(b->x, b->y);
            fclSpriteCreate(0xC3, drawPosition12, 99.0f, 0x56);
            drawPosition13 = fclMakeVec2(slideDistance + b->x, b->y);
            drawPosition14 = fclMakeVec2(b->x, b->y);
            fclSpriteStartPositionAt(0xC3, drawPosition13, drawPosition14, 0, 0xA, 0);
        } else {
            drawPosition15 = fclMakeVec2(b->x, b->y);
            drawPosition16 = fclMakeVec2(slideDistance + b->x, b->y);
            fclSpriteStartPositionAt(0xC3, drawPosition15, drawPosition16, 0, 0xA, 0);
        }
        b = (FclVec2 *)D_00644390;
        drawPosition1 = fclMakeVec2(b->x, b->y);
        if ((s8)mode == 0) {
            drawPosition17 = fclMakeVec2(b->x, b->y);
            fclSpriteCreate(0xC4, drawPosition17, 99.0f, 0x56);
            drawPosition18 = fclMakeVec2(slideDistance + b->x, b->y);
            drawPosition19 = fclMakeVec2(b->x, b->y);
            fclSpriteStartPositionAt(0xC4, drawPosition18, drawPosition19, 0, 0xA, 0);
        } else {
            drawPosition20 = fclMakeVec2(b->x, b->y);
            drawPosition21 = fclMakeVec2(slideDistance + b->x, b->y);
            fclSpriteStartPositionAt(0xC4, drawPosition20, drawPosition21, 0, 0xA, 0);
        }
    }
    drawPosition1 = fclMakeVec2((f32)0x167, 29.0f);
    if ((s8)mode == 0) {
        fclSpriteCreate(0x69, drawPosition1, 98.0f, 0x56);
        slideDistance = 300.0f;
        drawPosition22 = fclMakeVec2(slideDistance + drawPosition1.x, drawPosition1.y);
        fclSpriteStartPositionAt(0x69, drawPosition22, drawPosition1, 0, 0xA, 0);
        drawColor1 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        p = fclSpriteEntry(0x69);
        ((FclCombineRowSprite *)p)->color = drawColor1;
    } else {
        slideDistance = 300.0f;
        drawPosition23 = fclMakeVec2(slideDistance + drawPosition1.x, drawPosition1.y);
        fclSpriteStartPositionAt(0x69, drawPosition1, drawPosition23, 0, 0xA, 0);
    }
    b = (FclVec2 *)D_00644AD8;
    drawPosition1 = fclMakeVec2(b->x, b->y);
    if ((s8)mode == 0) {
        drawPosition24 = fclMakeVec2(b->x, b->y);
        fclSpriteCreate(0x1AD, drawPosition24, 100.0f, 0x41);
        drawPosition25 = fclMakeVec2(slideDistance + b->x, b->y);
        drawPosition26 = fclMakeVec2(b->x, b->y);
        fclSpriteStartPositionAt(0x1AD, drawPosition25, drawPosition26, 0, 0xA, 0);
        drawColor2 = fclMakeDrawColor(0x0E, 0x17, 0x49, 0xFF);
        p = fclSpriteEntry(0x1AD);
        ((FclCombineRowSprite *)p)->color = drawColor2;
        ((FclCombineRowSprite *)fclSpriteEntry(0x1AD))->alpha = 0x80;
    } else {
        drawPosition27 = fclMakeVec2(b->x, b->y);
        drawPosition28 = fclMakeVec2(slideDistance + b->x, b->y);
        fclSpriteStartPositionAt(0x1AD, drawPosition27, drawPosition28, 0, 0xA, 0);
    }
    drawPosition1 = fclMakeVec2((f32)0x23B, 50.0f);
    if ((s8)mode == 0) {
        fclSpriteCreate(0x2B3, drawPosition1, 189.0f, 0x56);
        drawPosition29 = fclMakeVec2(slideDistance + drawPosition1.x, drawPosition1.y);
        fclSpriteStartPositionAt(0x2B3, drawPosition29, drawPosition1, 0, 0xA, 0);
        drawColor3 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        p = fclSpriteEntry(0x2B3);
        ((FclCombineRowSprite *)p)->color = drawColor3;
    } else {
        drawPosition30 = fclMakeVec2(slideDistance + drawPosition1.x, drawPosition1.y);
        fclSpriteStartPositionAt(0x2B3, drawPosition1, drawPosition30, 0, 0xA, 0);
    }
    drawPosition1 = fclMakeVec2((f32)0x263, 50.0f);
    if ((datCalcGetLevelById(1) & 0xFF) < 0xA) {
        drawPosition1 = fclMakeVec2((f32)0x251, 50.0f);
    }
    if ((s8)mode == 0) {
        fclSpriteCreate(0x26E, drawPosition1, 46.0f, 0x56);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26E))->image = (s16)((datCalcGetLevelById(1) & 0xFF) % 10 + 0x46);
        drawPosition31 = fclMakeVec2(slideDistance + drawPosition1.x, drawPosition1.y);
        fclSpriteStartPositionAt(0x26E, drawPosition31, drawPosition1, 0, 0xA, 0);
    } else {
        drawPosition32 = fclMakeVec2(slideDistance + drawPosition1.x, drawPosition1.y);
        fclSpriteStartPositionAt(0x26E, drawPosition1, drawPosition32, 0, 0xA, 0);
    }
    drawPosition1 = fclMakeVec2((f32)0x251, 50.0f);
    if ((datCalcGetLevelById(1) & 0xFF) / 10 > 0) {
        if ((s8)mode == 0) {
            fclSpriteCreate(0x26F, drawPosition1, 46.0f, 0x56);
            ((FclCombineRowSprite *)fclSpriteEntry(0x26F))->image = (s16)((datCalcGetLevelById(1) & 0xFF) / 10 + 0x46);
            drawPosition33 = fclMakeVec2(slideDistance + drawPosition1.x, drawPosition1.y);
            fclSpriteStartPositionAt(0x26F, drawPosition33, drawPosition1, 0, 0xA, 0);
        } else {
            drawPosition34 = fclMakeVec2(slideDistance + drawPosition1.x, drawPosition1.y);
            fclSpriteStartPositionAt(0x26F, drawPosition1, drawPosition34, 0, 0xA, 0);
        }
    }
}
// Fcl combine label fades: five label sprites (0x8B, 0x8C, 0x8A, 0x8E, 0x8D), each with a show flag and a second flag. When the show flag is 1, a second flag of 0 creates the sprite at its table position and fades it in; nonzero fades it out from its current alpha.
// FUN_00316E80
void fclCombineFadeLabelSprites(u8 *task, s64 showFirst, s64 fadeFirst, s64 showSecond, s64 fadeSecond, s64 showThird, s64 fadeThird, s64 showFourth, s8 fadeFourth, s8 showFifth, s8 fadeFifth) {
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    f32 *b1;
    f32 *b2;
    f32 *b3;
    f32 *b4;
    f32 *b5;

    if ((s8)showFirst == 1) {
        b1 = D_006441C8;
        if ((s8)fadeFirst == 0) {
            drawPosition1 = fclMakeVec2(b1[0], b1[1]);
            fclSpriteCreate(0x8B, drawPosition1, 103.0f, 0xBC);
            fclSpriteStartAlphaAt(0x8B, 0, 0xFF, 0, 0xA, 0);
        } else {
            fclSpriteStartAlphaAt(0x8B, ((FclCombineRowSprite *)fclSpriteEntry(0x8B))->alpha, 0, 0, 0xA, 0);
        }
    }
    if ((s8)showSecond == 1) {
        b2 = D_006441D0;
        if ((s8)fadeSecond == 0) {
            drawPosition2 = fclMakeVec2(b2[0], b2[1]);
            fclSpriteCreate(0x8C, drawPosition2, 103.0f, 0xBC);
            fclSpriteStartAlphaAt(0x8C, 0, 0xFF, 0, 0xA, 0);
        } else {
            fclSpriteStartAlphaAt(0x8C, ((FclCombineRowSprite *)fclSpriteEntry(0x8C))->alpha, 0, 0, 0xA, 0);
        }
    }
    if ((s8)showThird == 1) {
        b3 = D_006441C0;
        if ((s8)fadeThird == 0) {
            drawPosition3 = fclMakeVec2(b3[0], b3[1]);
            fclSpriteCreate(0x8A, drawPosition3, 103.0f, 0xBC);
            fclSpriteStartAlphaAt(0x8A, 0, 0xFF, 0, 0xA, 0);
        } else {
            fclSpriteStartAlphaAt(0x8A, ((FclCombineRowSprite *)fclSpriteEntry(0x8A))->alpha, 0, 0, 0xA, 0);
        }
    }
    if ((s8)showFourth == 1) {
        b4 = D_006441E0;
        if (fadeFourth == 0) {
            drawPosition4 = fclMakeVec2(b4[0], b4[1]);
            fclSpriteCreate(0x8E, drawPosition4, 103.0f, 0xBC);
            fclSpriteStartAlphaAt(0x8E, 0, 0xFF, 0, 0xA, 0);
        } else {
            fclSpriteStartAlphaAt(0x8E, ((FclCombineRowSprite *)fclSpriteEntry(0x8E))->alpha, 0, 0, 0xA, 0);
        }
    }
    if (showFifth == 1) {
        b5 = D_006441D8;
        if (fadeFifth == 0) {
            drawPosition5 = fclMakeVec2(b5[0], b5[1]);
            fclSpriteCreate(0x8D, drawPosition5, 103.0f, 0xBC);
            fclSpriteStartAlphaAt(0x8D, 0, 0xFF, 0, 0xA, 0);
            return;
        }
        fclSpriteStartAlphaAt(0x8D, ((FclCombineRowSprite *)fclSpriteEntry(0x8D))->alpha, 0, 0, 0xA, 0);
    }
}

// Create the panel at its table position plus offsetX in mode 0; otherwise fade its current alpha out.
// FUN_00317240
void fclCombineFadePanelSprite(u8 *task, s64 mode, f32 offsetX) {
    FclVec2 drawPosition1;
    f32 *b;

    b = D_00644C90;
    if (((s64)(mode << 0x38) >> 0x38) == 0) {
        drawPosition1 = fclMakeVec2(b[0] + offsetX, b[1]);
        fclSpriteCreate(0x1E4, drawPosition1, 103.0f, 0xBC);
        fclSpriteStartAlphaAt(0x1E4, 0, 0xFF, 0, 0xA, 0);
        fclSpriteStartTweenAt(0x1E4, 0, 0, 0, 0.0f, 90.0f);
        return;
    }
    fclSpriteStartAlphaAt(0x1E4, ((FclCombineRowSprite *)fclSpriteEntry(0x1E4))->alpha, 0, 0, 0xA, 0);
}

// Create the fixed-column cursor arrow at X = 358 + offsetX in mode 0; otherwise fade it out.
// FUN_00317320
void fclCombineFadeCursorArrow(u8 *task, s64 mode, f32 offsetX) {
    FclVec2 drawPosition1;
    f32 *b;

    b = D_00644C90;
    if (((s64)(mode << 0x38) >> 0x38) == 0) {
        drawPosition1 = fclMakeVec2(358.0f + offsetX, b[1]);
        fclSpriteCreate(0x1E4, drawPosition1, 103.0f, 0xBC);
        fclSpriteStartAlphaAt(0x1E4, 0, 0xFF, 0, 0xA, 0);
        fclSpriteStartTweenAt(0x1E4, 0, 0, 0, 0.0f, 90.0f);
        return;
    }
    fclSpriteStartAlphaAt(0x1E4, ((FclCombineRowSprite *)fclSpriteEntry(0x1E4))->alpha, 0, 0, 0xA, 0);
}

// Recolor the current slot, step it for command 0/1, then apply the selected colors to the new slot.
// FUN_00317410
void fclCombineStepSlotSelection(u8 *task, s8 command) {
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclDrawColor drawColor8;
    FclDrawColor drawColor9;
    FclDrawColor drawColor10;
    FclDrawColor drawColor11;
    u8 *p;
    u8 *work;
    u8 *q;
    s32 v;

    work = ((struct KwlnTask *)task)->work;
    drawColor1 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
    p = fclSpriteEntry((s16)(((FclCombineWork *)work)->slotCursor * 2 + 0x1F5));
    ((FclCombineRowSprite *)p)->color = drawColor1;
    q = fclSpriteEntry((s16)(MEMBER(s8, work, FclCombineWork, slotCursor) * 2 + 0x1F4));
    ((FclCombineRowSprite *)q)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
    drawColor2 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
    v = MEMBER(s8, work, FclCombineWork, slotCursor) * 2;
    p = fclSpriteEntry((s16)((FclCombineWork *)(v + (s32)work))->selectedIds[0]);
    ((FclCombineRowSprite *)p)->color = drawColor2;
    if (MEMBER(s8, work, FclCombineWork, slotCursor) == 1) {
        if (datGetFlag(0x1305) != 0) {
            drawColor3 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
            p = fclSpriteEntry(0x2EB);
            ((FclCombineRowSprite *)p)->color = drawColor3;
        }
    }
    if (MEMBER(s8, work, FclCombineWork, slotCursor) == 2) {
        drawColor4 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        p = fclSpriteEntry(0x175);
        ((FclCombineRowSprite *)p)->color = drawColor4;
    }
    drawColor5 = fclMakeDrawColor(0x25, 0x2F, 0x94, 0xFF);
    p = fclSpriteEntry((s16)(MEMBER(s8, work, FclCombineWork, slotCursor) + 0x2FB));
    ((FclCombineRowSprite *)p)->color = drawColor5;
    sdkSndStartStream(0, 0, 0, 0);
    switch (command) {
    case 0:
        MEMBER(s8, work, FclCombineWork, slotCursor) = (s8)fclAddClamped(MEMBER(s8, work, FclCombineWork, slotCursor), 1, 2, 0, 2);
        break;
    case 1:
        MEMBER(s8, work, FclCombineWork, slotCursor) = (s8)fclSubClamped(MEMBER(s8, work, FclCombineWork, slotCursor), 1, 0, 2, 2);
        break;
    case 2:
    case 3:
    default:
        break;
    }
    drawColor6 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
    p = fclSpriteEntry((s16)(MEMBER(s8, work, FclCombineWork, slotCursor) * 2 + 0x1F4));
    ((FclCombineRowSprite *)p)->color = drawColor6;
    drawColor7 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
    p = fclSpriteEntry((s16)(MEMBER(s8, work, FclCombineWork, slotCursor) * 2 + 0x1F5));
    ((FclCombineRowSprite *)p)->color = drawColor7;
    drawColor8 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    v = MEMBER(s8, work, FclCombineWork, slotCursor) * 2;
    p = fclSpriteEntry((s16)((FclCombineWork *)(v + (s32)work))->selectedIds[0]);
    ((FclCombineRowSprite *)p)->color = drawColor8;
    if (MEMBER(s8, work, FclCombineWork, slotCursor) == 1) {
        if (datGetFlag(0x1305) != 0) {
            drawColor9 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            p = fclSpriteEntry(0x2EB);
            ((FclCombineRowSprite *)p)->color = drawColor9;
        }
    }
    if (MEMBER(s8, work, FclCombineWork, slotCursor) == 2) {
        drawColor10 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        p = fclSpriteEntry(0x175);
        ((FclCombineRowSprite *)p)->color = drawColor10;
    }
    drawColor11 = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
    p = fclSpriteEntry((s16)(MEMBER(s8, work, FclCombineWork, slotCursor) + 0x2FB));
    ((FclCombineRowSprite *)p)->color = drawColor11;
}


/* Point-by-value construction as in fclCombineDrawPersonaCard.  The anchor is declared
   with its initializer (the constructor's result is copied out of a
   temporary, so the anchor never escapes and its sums stay in registers),
   the frame id is assigned through an s16 argument local ahead of the
   depth, and the fade orders are converted to s16 at each call through
   the local fclSpriteStartAlphaAt prototype. */
// Draw entry from startPosition to endPosition at delay, depth and layer; the selected entry adds animated highlights.
// FUN_00317900
void fclCombineDrawEntryCell(u8 *task, FclVec2 startPosition, FclVec2 endPosition, s8 entry, s16 delay, s16 depth, s16 layer) {
    extern void fclSpriteStartAlphaAt(s16, u8, u8, u8, s32, s16);
    extern void fclSpriteStartPositionAt(s16, FclVec2, FclVec2, u32, u32, s16);
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    s16 sprite;
    s32 depthUp;
    s32 order;
    u8 *work = ((struct KwlnTask *)task)->work;
    FclVec2 pos = fclMakeVec2(startPosition.x, startPosition.y);
    u8 *node;
    s32 frame;
    s16 frameId;
    s32 fadeA;
    s32 fadeB;
    s32 fadeC;
    f32 scale;
    s32 orderUp;

    sprite = entry * 2 + 0xDF;
    if (entry == 6) {
        sprite = 0xEF;
    } else if (entry == 7) {
        sprite = 0xEB;
    } else if (entry == 8) {
        sprite = 0xED;
    }
    order = layer;
    orderUp = order + 1;
    fclSpriteCreate(sprite, fclMakeVec2(6.0f + pos.x, 4.0f + pos.y), (f32)depth, orderUp);
    drawColor1 = fclMakeDrawColor(0x46, 0x6A, 0x82, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = drawColor1;
    ((FclCombineDrawSprite *)fclSpriteEntry(sprite))->scaleX = 1.0f;
    ((FclCombineDrawSprite *)fclSpriteEntry(sprite))->scaleY = 1.0f;
    fclSpriteStartPositionAt(sprite, fclMakeVec2(6.0f + pos.x, 4.0f + pos.y), fclMakeVec2(6.0f + endPosition.x, 4.0f + endPosition.y), 0, 8, delay);
    frameId = frame = entry + 0x20D;
    depthUp = depth + 1;
    fclSpriteCreate(frameId, endPosition, (f32)depthUp, order);
    fclSpriteCreate(entry + 0xF2, fclMakeVec2(6.0f + endPosition.x, 78.0f + endPosition.y), (f32)depthUp, orderUp);
    drawColor2 = fclMakeDrawColor(0x46, 0x6A, 0x82, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(entry + 0xF2))->color = drawColor2;
    fclSpriteCreate(entry + 0xFD, fclMakeVec2(endPosition.x - 12.0f, 104.0f + endPosition.y), (f32)depth, order + 2);
    drawColor3 = fclMakeDrawColor(0xE0, 0xFF, 0x33, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(entry + 0xFD))->color = drawColor3;
    if (entry == (&MEMBER(s16, work, FclCombineWork, commandRows[0].id))[((FclCombineWork *)work)->commandCursor * 5]) {
        fclSpriteCreate(sprite, fclMakeVec2(6.0f + pos.x, 4.0f + pos.y), 59.0f, 0xAB);
        scale = iGpffff8360;
        ((FclCombineDrawSprite *)fclSpriteEntry(sprite))->scaleX = scale;
        ((FclCombineDrawSprite *)fclSpriteEntry(sprite))->scaleY = scale;
        node = sdkSpriteNewNode(fclCombineGetSpritePool(), (s16)sprite);
        fclSpriteStartPositionAt(sprite, fclMakeVec2((5.0f + pos.x) - 2.0f * (sdkSpriteScaledWidth(node) / 10.0f), pos.y - 3.0f),
                      fclMakeVec2((5.0f + endPosition.x) - 2.0f * (sdkSpriteScaledWidth(node) / 10.0f), endPosition.y - 3.0f), 0, 8, delay);
        sdkSpriteFreeNode(node);
        drawColor4 = fclMakeDrawColor(0xE0, 0xFF, 0x33, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = drawColor4;
        fclSpriteCreate(0x1DC, pos, 60.0f, 0xAA);
        fclSpriteStartPositionAt(0x1DC, pos, endPosition, 0, 8, delay);
        fclSpriteStartPositionAt(entry + 0xFD, fclMakeVec2(pos.x - 12.0f, 104.0f + pos.y), fclMakeVec2(endPosition.x - 12.0f, 104.0f + endPosition.y), 0, 8, delay);
        fclSpriteSetFlag(frame, 0, 1);
        if (entry < 6) {
            fclSpriteCreate(0xFC, fclMakeVec2(pos.x - 12.0f, 123.0f + pos.y), 59.0f, 0xAC);
            fclSpriteStartPositionAt(0xFC, fclMakeVec2(pos.x - 12.0f, 123.0f + pos.y), fclMakeVec2(endPosition.x - 12.0f, 123.0f + endPosition.y), 0, 8, delay);
            drawColor5 = fclMakeDrawColor(0xE0, 0xFF, 0x33, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(0xFC))->color = drawColor5;
        }
        fclSpriteSetFlag(entry + 0xF2, 0, 1);
        fclSpriteReset(0x216, 0x87);
        ((FclCombineRowSprite *)fclSpriteEntry(0x216))->flags = 0;
        fclSpriteCreate(0x216, fclMakeVec2(6.0f + pos.x, 62.0f + pos.y), 62.0f, 0xAA);
        fclSpriteStartPositionAt(0x216, fclMakeVec2(6.0f + pos.x, 62.0f + pos.y), fclMakeVec2(6.0f + endPosition.x, 62.0f + endPosition.y), 0, 8, delay);
        fadeA = delay + 8;
        fclSpriteStartAlphaAt(0x216, 0x40, 0x80, 1, 0x3C, fadeA);
        ((FclCombineRowSprite *)fclSpriteEntry(0x216))->flag73 = 1;
        fclSpriteSetFlag(0x216, 0xB, 0);
        fclSpriteReset(0x217, 0x87);
        ((FclCombineRowSprite *)fclSpriteEntry(0x217))->flags = 0;
        fclSpriteCreate(0x217, fclMakeVec2(33.0f + pos.x, 62.0f + pos.y), 62.0f, 0xAA);
        fclSpriteStartPositionAt(0x217, fclMakeVec2(33.0f + pos.x, 62.0f + pos.y), fclMakeVec2(33.0f + endPosition.x, 62.0f + endPosition.y), 0, 8, delay);
        fadeB = delay + 0x26;
        fclSpriteStartAlphaAt(0x217, 0x40, 0x80, 1, 0x3C, fadeB);
        ((FclCombineRowSprite *)fclSpriteEntry(0x217))->flag73 = 1;
        fclSpriteSetFlag(0x217, 0xB, 0);
        fclSpriteReset(0x218, 0x86);
        ((FclCombineRowSprite *)fclSpriteEntry(0x218))->flags = 0;
        fclSpriteCreate(0x218, fclMakeVec2(20.0f + pos.x, 62.0f + pos.y), 61.0f, 0xAA);
        fclSpriteStartPositionAt(0x218, fclMakeVec2(20.0f + pos.x, 62.0f + pos.y), fclMakeVec2(20.0f + endPosition.x, 62.0f + endPosition.y), 0, 8, delay);
        fadeC = delay + 0x17;
        fclSpriteStartAlphaAt(0x218, 0x40, 0x80, 1, 0x3C, fadeC);
        ((FclCombineRowSprite *)fclSpriteEntry(0x218))->flag73 = 1;
        fclSpriteSetFlag(0x218, 0xB, 0);
        fclSpriteReset(0x219, 0x89);
        ((FclCombineRowSprite *)fclSpriteEntry(0x219))->flags = 0;
        fclSpriteCreate(0x219, fclMakeVec2(6.0f + pos.x, pos.y - 44.0f), 62.0f, 0xAA);
        fclSpriteStartPositionAt(0x219, fclMakeVec2(6.0f + pos.x, pos.y - 44.0f), fclMakeVec2(6.0f + endPosition.x, endPosition.y - 44.0f), 0, 8, delay);
        fclSpriteStartAlphaAt(0x219, 0x80, 0xFF, 1, 0x3C, fadeA);
        ((FclCombineRowSprite *)fclSpriteEntry(0x219))->flag73 = 1;
        fclSpriteSetFlag(0x219, 0xB, 0);
        fclSpriteReset(0x21A, 0x89);
        ((FclCombineRowSprite *)fclSpriteEntry(0x21A))->flags = 0;
        fclSpriteCreate(0x21A, fclMakeVec2(33.0f + pos.x, pos.y - 44.0f), 62.0f, 0xAA);
        fclSpriteStartPositionAt(0x21A, fclMakeVec2(33.0f + pos.x, pos.y - 44.0f), fclMakeVec2(33.0f + endPosition.x, endPosition.y - 44.0f), 0, 8, delay);
        fclSpriteStartAlphaAt(0x21A, 0x80, 0xFF, 1, 0x3C, fadeB);
        ((FclCombineRowSprite *)fclSpriteEntry(0x21A))->flag73 = 1;
        fclSpriteSetFlag(0x21A, 0xB, 0);
        fclSpriteReset(0x21B, 0x88);
        ((FclCombineRowSprite *)fclSpriteEntry(0x21B))->flags = 0;
        fclSpriteCreate(0x21B, fclMakeVec2(20.0f + pos.x, pos.y - 44.0f), 61.0f, 0xAA);
        fclSpriteStartPositionAt(0x21B, fclMakeVec2(20.0f + pos.x, pos.y - 44.0f), fclMakeVec2(20.0f + endPosition.x, endPosition.y - 44.0f), 0, 8, delay);
        fclSpriteStartAlphaAt(0x21B, 0x80, 0xFF, 1, 0x3C, fadeC);
        ((FclCombineRowSprite *)fclSpriteEntry(0x21B))->flag73 = 1;
        fclSpriteSetFlag(0x21B, 0xB, 0);
        return;
    }
    fclSpriteStartPositionAt(entry + 0x20D, pos, endPosition, 0, 8, delay);
    fclSpriteStartPositionAt(entry + 0xF2, fclMakeVec2(6.0f + pos.x, 78.0f + pos.y), fclMakeVec2(6.0f + endPosition.x, 78.0f + endPosition.y), 0, 8, delay);
    drawColor6 = fclMakeDrawColor(0x42, 0x6E, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(entry + 0xF2))->color = drawColor6;
    fclSpriteSetFlag(entry + 0xFD, 0, 1);
    drawColor7 = fclMakeDrawColor(0x42, 0x6E, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = drawColor7;
}

/* Each point is built inside the store that consumes it (fclMakeVec2 returns by value), matching
 * retail's float saved-register order. Moves/shows the selected row's entry highlight; otherwise
 * restores the entry icon at depth and layer + 1. */
// FUN_00318840
void fclCombineUpdateEntryHighlight(u8 *task, s8 row, s8 entry, s16 depth, s16 layer) {
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclVec2 pos;
    u8 *work;
    u8 *h;
    s32 resource;
    s16 icon;
    f32 scale;

    work = ((struct KwlnTask *)task)->work;
    resource = entry + 0x20D;
    pos = ((FclCombineRowSprite *)fclSpriteEntry(resource))->position;
    icon = entry * 2 + 0xDF;
    if (entry == 6) {
        icon = 0xEF;
    } else if (entry == 7) {
        icon = 0xEB;
    } else if (entry == 8) {
        icon = 0xED;
    }
    if (row == ((FclCombineWork *)work)->commandCursor) {
        ((FclCombineRowSprite *)fclSpriteEntry(0x1DC))->position = pos;
        ((FclCombineRowSprite *)fclSpriteEntry(0x216))->position = fclMakeVec2(6.0f + pos.x, 62.0f + pos.y);
        ((FclCombineRowSprite *)fclSpriteEntry(0x217))->position = fclMakeVec2(33.0f + pos.x, 62.0f + pos.y);
        ((FclCombineRowSprite *)fclSpriteEntry(0x218))->position = fclMakeVec2(20.0f + pos.x, 62.0f + pos.y);
        ((FclCombineRowSprite *)fclSpriteEntry(0x219))->position = fclMakeVec2(6.0f + pos.x, pos.y - 44.0f);
        ((FclCombineRowSprite *)fclSpriteEntry(0x21A))->position = fclMakeVec2(33.0f + pos.x, pos.y - 44.0f);
        ((FclCombineRowSprite *)fclSpriteEntry(0x21B))->position = fclMakeVec2(20.0f + pos.x, pos.y - 44.0f);
        scale = iGpffff8360;
        ((FclCombineDrawSprite *)fclSpriteEntry(icon))->scaleX = scale;
        ((FclCombineDrawSprite *)fclSpriteEntry(icon))->scaleY = scale;
        ((FclCombineRowSprite *)fclSpriteEntry(icon))->depth = 59.0f;
        ((FclCombineRowSprite *)fclSpriteEntry(icon))->order = 0xAB;
        h = sdkSpriteNewNode(fclCombineGetSpritePool(), icon);
        ((FclCombineRowSprite *)fclSpriteEntry(icon))->position = fclMakeVec2((5.0f + pos.x) - 2.0f * (sdkSpriteScaledWidth(h) / 10.0f), pos.y - 3.0f);
        sdkSpriteFreeNode(h);
        drawColor1 = fclMakeDrawColor(0xE0, 0xFF, 0x33, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(icon))->color = drawColor1;
        fclSpriteSetFlag(entry + 0x20D, 0, 1);
        fclSpriteSetFlag(entry + 0xF2, 0, 1);
        fclSpriteCreate((s16)(entry + 0xFD), fclMakeVec2(pos.x - 12.0f, 104.0f + pos.y), 59.0f, 0xAC);
        if (entry < 6) {
            fclSpriteCreate(0xFC, fclMakeVec2(pos.x - 12.0f, 123.0f + pos.y), 59.0f, 0xAC);
            drawColor2 = fclMakeDrawColor(0xE0, 0xFF, 0x33, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(0xFC))->color = drawColor2;
            return;
        }
        fclSpriteSetFlag(0xFC, 0, 1);
        return;
    }
    fclSpriteSetFlag(entry + 0xFD, 0, 1);
    fclSpriteSetFlag(resource, 0, 0);
    resource = entry + 0xF2;
    fclSpriteSetFlag(resource, 0, 0);
    drawColor3 = fclMakeDrawColor(0x42, 0x6E, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(resource))->color = drawColor3;
    ((FclCombineDrawSprite *)fclSpriteEntry(icon))->scaleX = 1.0f;
    ((FclCombineDrawSprite *)fclSpriteEntry(icon))->scaleY = 1.0f;
    ((FclCombineRowSprite *)fclSpriteEntry(icon))->depth = depth;
    ((FclCombineRowSprite *)fclSpriteEntry(icon))->order = layer + 1;
    ((FclCombineRowSprite *)fclSpriteEntry(icon))->position = fclMakeVec2(6.0f + pos.x, 4.0f + pos.y);
    drawColor4 = fclMakeDrawColor(0x42, 0x6E, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(icon))->color = drawColor4;
}

// Place the fading row marker beside row; entries 6-8 use the special icon slots.
// FUN_00318F30
void fclCombineMarkRow(s16 row) {
    s16 sprite;
    u8 *p;
    f32 fv;
    FclVec2 drawPosition1;
    FclDrawColor drawColor1;
    FclVec2 drawPosition2;

    sprite = (s16)(row * 2 + 0xDF);
    if (row == 6) {
        sprite = 0xEF;
    } else if (row == 7) {
        sprite = 0xEB;
    } else if (row == 8) {
        sprite = 0xED;
    }
    fclSpriteReset(0x2F2, (s16)(sprite + 1));
    p = fclSpriteEntry(sprite);
    drawPosition1 = ((FclCombineRowSprite *)p)->position;
    drawPosition2 = fclMakeVec2(drawPosition1.x - 15.0f, drawPosition1.y - 7.0f);
    fclSpriteCreate(0x2F2, drawPosition2, 58.0f, 0xAB);
    fclSpriteStartAlphaAt(0x2F2, 0xFF, 0, 0, 0xF, 0);
    fv = iGpffff8360;
    ((FclCombineDrawSprite *)fclSpriteEntry(0x2F2))->scaleX = fv;
    ((FclCombineDrawSprite *)fclSpriteEntry(0x2F2))->scaleY = fv;
    drawColor1 = fclMakeDrawColor(0xE0, 0xFF, 0x33, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x2F2))->color = drawColor1;
}

// Fcl combine rows busy: returns 1 while any row sprite or the 0x1DC sprite is still animating.
// FUN_003190D0
s32 fclCombineRowsBusy(u8 *task) {
    u8 *work;
    s16 i;

    work = ((struct KwlnTask *)task)->work;
    for (i = 0; i < ((FclCombineWork *)work)->commandCount; i++) {
        if (((FclCombineWork *)work)->commandCursor != i) {
            if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry((s16)(((FclCombineWork *)work)->commandRows[i].id + 0x20D)))->flags, 1) == 1) {
                return 1;
            }
        }
    }
    return (s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1DC))->flags, 1) == 1;
}
/* Draw the party row's icon, Persona, arcana, level and labels; mode 1 transitions existing sprites
 * out. */
// FUN_003191C0
void fclCombinePartyRow(u8 *task, FclVec2 position, s32 row, s32 persona, s16 level, s16 delay, s8 mode, s8 rowCountLimit) {
    /* Slot is s32 here, not the header's s8, because fclCombinePartyRow passes an unnarrowed value. */
    extern u8 *fclCombineSlotRecord(u8 *, s32);
    extern void fclSpriteStartPositionAt(s16, FclVec2, FclVec2, u32, u32, s16);
    extern void fclCombineSetSprite(u8 *, FclVec2, s16, FclDrawColor, f32);
    extern void fclCombineSetTint(u8 *, u8, u8, u8, s16, s16);
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclDrawColor drawColor8;
    FclDrawColor drawColor9;
    FclDrawColor drawColor10;
    FclDrawColor drawColor11;
    FclDrawColor drawColor12;
    FclDrawColor drawColor13;
    FclDrawColor drawColor14;
    FclDrawColor drawColor15;
    FclDrawColor drawColor16;
    FclDrawColor drawColor17;
    FclDrawColor drawColor18;
    FclDrawColor drawColor19;
    FclDrawColor drawColor20;
    FclDrawColor drawColor21;
    FclDrawColor drawColor22;
    FclDrawColor drawColor23;
    FclDrawColor drawColor24;
    FclDrawColor drawColor25;
    u8 *work;
    f32 y;
    f32 sc;
    s8 special;
    s8 c;
    s16 id;
    u8 *hA;
    u8 *hB;
    u8 *hC;
    u8 *hD;
    s32 n;
    u8 *h3;
    u8 *h2;
    u8 **pp;
    s8 c2;

    work = ((struct KwlnTask *)task)->work;
    special = 0;
    if (((FclObject *)((u8 *)fclCombineSlotRecord((u8 *)((FclCombineWork *)work)->f188, row) - 4))->color.c0 == 0x8C) {
        if (((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, work, FclCombineWork, ballTask.task), row) - 4))->color.c1 == 0xE2) {
            if (((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, work, FclCombineWork, ballTask.task), row) - 4))->color.c2 == 0xFF) {
                special = 1;
            }
        }
    }
    c = (s8)row;
    position.y += (f32)(c * 23);
    id = (s16)(c + 0x21C);
    hA = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x193);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, ((FclCombineRowSprite *)fclSpriteEntry(id))->alpha, 0, 0, 0, delay + 3);
        sc = iGpffff8504;
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, sc, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(position.x, y = position.y), fclMakeVec2(position.x, position.y + sdkSpriteScaledHeight(hA) / 2.0f), 0, 3, delay);
    } else {
        y = position.y;
        fclSpriteCreate(id, fclMakeVec2(position.x, y), 191.0f, 0x57);
        if (special == 1) {
            drawColor2 = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor2;
            fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
        } else if (((FclCombineRowWork *)work)->cursorRow == c) {
            drawColor3 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor3;
            fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
        } else {
            drawColor4 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor4;
            fclSpriteStartAlphaAt(id, 0, 0x66, 0, 0, delay);
        }
        sc = iGpffff8504;
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, sc, 1.0f, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(position.x, position.y + sdkSpriteScaledHeight(hA) / 2.0f), fclMakeVec2(position.x, position.y), 0, 3, delay);
    }
    sdkSpriteFreeNode(hA);
    id = (s16)(c + 0x22B);
    hB = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x19A);
    if ((s8)mode == 1) {
        if (((FclCombineRowWork *)work)->cursorRow == c) {
            fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, delay + 3);
        } else {
            fclSpriteStartAlphaAt(id, ((FclCombineRowSprite *)fclSpriteEntry(id))->alpha, 0, 0, 0, delay + 3);
        }
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, sc, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(301 + position.x, position.y), fclMakeVec2(301 + position.x, position.y + sdkSpriteScaledHeight(hB) / 2.0f), 0, 3, delay);
    } else {
        fclSpriteCreate(id, fclMakeVec2(301 + position.x, y), 192.0f, 0x57);
        if (special == 1) {
            drawColor5 = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor5;
            fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
        } else if (((FclCombineRowWork *)work)->cursorRow == c) {
            drawColor6 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor6;
            fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
        } else {
            drawColor7 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor7;
            fclSpriteStartAlphaAt(id, 0, 0x66, 0, 0, delay);
        }
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, sc, 1.0f, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(301 + position.x, position.y + sdkSpriteScaledHeight(hB) / 2.0f), fclMakeVec2(301 + position.x, position.y), 0, 3, delay);
    }
    sdkSpriteFreeNode(hB);
    id = (s16)(c + 0x238);
    hC = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x188);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, delay + 3);
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, sc, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(position.x, position.y), fclMakeVec2(position.x, position.y + sdkSpriteScaledHeight(hC) / 2.0f), 0, 3, delay);
    } else {
        fclSpriteCreate(id, fclMakeVec2(position.x, position.y), 163.0f, 0x57);
        fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, sc, 1.0f, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(position.x, position.y + sdkSpriteScaledHeight(hC) / 2.0f), fclMakeVec2(position.x, position.y), 0, 3, delay);
        if (special == 1) {
            drawColor8 = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor8;
        } else if (((FclCombineRowWork *)work)->cursorRow == c) {
            drawColor9 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor9;
        } else {
            drawColor10 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor10;
            if (rowCountLimit <= c) {
                drawColor11 = fclMakeDrawColor(0x24, 0x3F, 0x9F, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor11;
            }
        }
    }
    sdkSpriteFreeNode(hC);
    id = (s16)(c + 0x244);
    hD = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x18C);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, delay + 3);
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, sc, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(55.0f + position.x, position.y), fclMakeVec2(55.0f + position.x, position.y + sdkSpriteScaledHeight(hD) / 2.0f), 0, 3, delay);
    } else {
        fclSpriteCreate(id, fclMakeVec2(55.0f + position.x, position.y), 163.0f, 0x57);
        fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, sc, 1.0f, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(55.0f + position.x, position.y + sdkSpriteScaledHeight(hD) / 2.0f), fclMakeVec2(55.0f + position.x, position.y), 0, 3, delay);
        if (special == 1) {
            drawColor12 = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor12;
        } else if (((FclCombineRowWork *)work)->cursorRow == c) {
            drawColor13 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor13;
        } else {
            drawColor14 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor14;
            if (rowCountLimit <= c) {
                drawColor15 = fclMakeDrawColor(0x24, 0x3F, 0x9F, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor15;
            }
        }
    }
    sdkSpriteFreeNode(hD);
    if (((FclCombineRowWork *)work)->cursorRow == c) {
        fclSpriteStartEntrance(fclCombineSlotRecord(MEMBER(u8 *, work, FclCombineWork, ballTask.task), row), fclMakeVec2(position.x, y),
                      (drawColor16 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF)), (drawColor17 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF)),
                      0xFF, 0xFF, 32.0f, 159.0f, 3, (s16)delay, mode, 0);
    } else if (special == 1) {
        fclSpriteStartEntrance(fclCombineSlotRecord(MEMBER(u8 *, work, FclCombineWork, ballTask.task), row), fclMakeVec2(position.x, y),
                      ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, work, FclCombineWork, ballTask.task), row) - 4))->color,
                      ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, work, FclCombineWork, ballTask.task), row) - 4))->color,
                      0xFF, 0xFF, 32.0f, 159.0f, 3, (s16)delay, mode, 0);
    } else {
        fclSpriteStartEntrance(fclCombineSlotRecord(MEMBER(u8 *, work, FclCombineWork, ballTask.task), row), fclMakeVec2(position.x, y),
                      (drawColor18 = fclMakeDrawColor(0, 0, 0x99, 0xFF)), (drawColor19 = fclMakeDrawColor(0, 0, 0x99, 0xFF)),
                      0xFF, 0xFF, 32.0f, 159.0f, 3, (s16)delay, mode, 0);
    }
    n = (s8)row + 0x39;
    id = (s16)n;
    h2 = sdkSpriteNewNode(fclCombineGetSpritePool(), n);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, delay + 3);
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, sc, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(4.0f + position.x, 5.0f + position.y), fclMakeVec2(4.0f + position.x, 5.0f + position.y + sdkSpriteScaledHeight(h2) / 2.0f), 0, 3, delay);
    } else {
        fclSpriteCreate(id, fclMakeVec2(4.0f + position.x, 5.0f + position.y), 158.0f, 0x59);
        if (special == 1) {
            drawColor20 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor20;
        } else if (MEMBER(s16, work, FclCombineRowWork, cursorRow) == c) {
            drawColor21 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor21;
        } else {
            drawColor22 = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor22;
        }
        fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, sc, 1.0f, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(4.0f + position.x, 5.0f + position.y + sdkSpriteScaledHeight(h2) / 2.0f), fclMakeVec2(4.0f + position.x, 5.0f + position.y), 0, 3, delay);
    }
    sdkSpriteFreeNode(h2);
    if (c < rowCountLimit) {
        id = (s16)(c + 0x250);
        h3 = sdkSpriteNewNode(fclCombineGetSpritePool(), (s16)((datPersonaGetArcana(persona) & 0xFF) + 0x1B));
        if ((s8)mode == 1) {
            fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, delay + 3);
            fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, sc, 0, 3, delay);
            fclSpriteStartPositionAt(id, fclMakeVec2(28.0f + position.x, 2.0f + position.y), fclMakeVec2(28.0f + position.x, 2.0f + position.y + sdkSpriteScaledHeight(h3) / 2.0f), 0, 3, delay);
        } else {
            fclSpriteCreate(id, fclMakeVec2(28.0f + position.x, 2.0f + position.y), 46.0f, 0x59);
            ((FclCombineRowSprite *)fclSpriteEntry(id))->image = (s16)((datPersonaGetArcana(persona) & 0xFF) + 0x1B);
            if (special == 1) {
                drawColor23 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor23;
            } else if (MEMBER(s16, work, FclCombineRowWork, cursorRow) == c) {
                drawColor24 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor24;
            } else {
                drawColor25 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(id))->color = drawColor25;
            }
            fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
            fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, sc, 1.0f, 0, 3, delay);
            fclSpriteStartPositionAt(id, fclMakeVec2(28.0f + position.x, 2.0f + position.y + sdkSpriteScaledHeight(h3) / 2.0f), fclMakeVec2(28.0f + position.x, 2.0f + position.y), 0, 3, delay);
        }
        sdkSpriteFreeNode(h3);
        if (special == 1) {
            drawColor1 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
        } else if (MEMBER(s16, work, FclCombineRowWork, cursorRow) == c) {
            drawColor1 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        } else if (level == 0) {
            drawColor1 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0x80);
        } else {
            drawColor1 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        }
        nmMesWindowShowNumber(((FclCombineRowWork *)work)->digitTask, (s8)(u32)row, level, position, drawColor1, 3, (s16)delay, 46.0f, 0x59, mode);
        return;
    }
    if ((s8)mode == 1) {
        fclCombineSetTint(((u8 **)(work + 0x21C))[c], 0xFF, 0, 0, 3, delay);
    } else {
        c2 = (s8)row;
        pp = (u8 **)(work + 0x21C) + c2;
        fclCombineSetSprite(*pp, fclMakeVec2(30.0f + position.x, 7.0f + y), 0x59, fclMakeDrawColor(0, 0, 0x66, 0xFF), 157.0f);
        fclCombineSetTint(*pp, 0, 0xFF, 0, 3, delay);
        ((FclCombineBallWork *)(fclCombineGetWorkAlt(*pp)))->colorMode = 0;
        if (MEMBER(s16, work, FclCombineRowWork, cursorRow) == c2) {
            ((FclCombineBallWork *)(fclCombineGetWorkAlt(*pp)))->colorMode = 1;
        }
    }
    fclSpriteSetFlag((s16)(c + 0x250), 0, 1);
}

/* Resource scale is established only in the branch that uses it.
   The name scale is established independently before the two-row tail.
   The digit pair uses the shared native aggregate/depth contract. */
// Fcl combine persona row: draws list row `row` at position (art, arcana, labels and level digits). checkAvailability == 1 reads the row's availability from the slot list; availability 2 adds the special-row backdrop and cursor sprites, and in mode 0 also creates the selection cursors (0x1C7, 0x2E8). Mode 1 transitions the existing sprites.
// FUN_0031AC10
/* measured: opt_lifetimes splits the two non-overlapping transition-scale lifetimes, which gives
 * retail's saved-register allocation. The name sits two pixels below rowY; the digit pair and
 * special-row backdrop use rowY unchanged. */
void fclCombineDrawPersonaRow(u8 *task, FclVec2 position, s8 selectedRow, s8 row, s32 persona, s16 level, s16 delay, s8 mode, s8 checkAvailability, u8 alpha) {
    /* Availability is read through a byte-biased row pointer, with the row added before the signed
     * column read. */
    s16 digitRow;
    FclCombineRowWork *work;
    u8 *resource;
    f32 rowY;
    f32 transitionScale;
    s8 rowIndex;
    s8 availability;
    s8 rowAvailability;
    s16 sprite;

    rowY = position.y;
    work = ((FclCombineRowTask *)task)->work;
    availability = 1;
    rowIndex = (s8)row;
    rowY += (f32)(rowIndex * 23);
    if (checkAvailability == 1) {
        availability = ((FclCombineRowList *)(yListSlotWork(0) + (s32)selectedRow * 12 + rowIndex))->availability[0][0];
    }
    if (work->firstSelectedRow != rowIndex && work->secondSelectedRow != rowIndex && (rowAvailability = availability) > 0) {
        if (rowAvailability != 2) {
            sprite = (s16)(rowIndex + 0x270);
            fclSpriteReset(sprite, 0x193);
            fclSpriteCreate(sprite, fclMakeVec2(position.x, rowY), 191.0f, 0x57);
            resource = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x193);
            if (mode == 1) {
                fclSpriteStartAlphaAt(sprite, ((FclCombineRowSprite *)fclSpriteEntry(sprite))->alpha, 0, 0, 0, delay + 3);
                transitionScale = iGpffff8504;
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, 1.0f, transitionScale, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(position.x, rowY), fclMakeVec2(position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), 0, 3, delay);
            } else {
                ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                fclSpriteStartAlphaAt(sprite, 0, alpha, 0, 0, delay);
                transitionScale = iGpffff8504;
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, transitionScale, 1.0f, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), fclMakeVec2(position.x, rowY), 0, 3, delay);
            }
            sdkSpriteFreeNode(resource);
            sprite = (s16)(rowIndex + 0x27D);
            fclSpriteReset(sprite, 0x19B);
            fclSpriteCreate(sprite, fclMakeVec2(286.0f + position.x, rowY), 192.0f, 0x57);
            resource = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x19B);
            if (mode == 1) {
                fclSpriteStartAlphaAt(sprite, ((FclCombineRowSprite *)fclSpriteEntry(sprite))->alpha, 0, 0, 0, delay + 3);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, 1.0f, transitionScale, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(286.0f + position.x, rowY), fclMakeVec2(286.0f + position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), 0, 3, delay);
            } else {
                ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                fclSpriteStartAlphaAt(sprite, 0, alpha, 0, 0, delay);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, transitionScale, 1.0f, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(286.0f + position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), fclMakeVec2(286.0f + position.x, rowY), 0, 3, delay);
            }
            sdkSpriteFreeNode(resource);
            sprite = (s16)(rowIndex + 0x28B);
            fclSpriteCreate(sprite, fclMakeVec2(position.x, rowY), 163.0f, 0x57);
            resource = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x188);
            if (mode == 1) {
                fclSpriteStartAlphaAt(sprite, 0xFF, 0, 0, 0, delay + 3);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, 1.0f, transitionScale, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(position.x, rowY), fclMakeVec2(position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), 0, 3, delay);
            } else {
                ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                fclSpriteStartAlphaAt(sprite, 0, 0xFF, 0, 0, delay);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, transitionScale, 1.0f, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), fclMakeVec2(position.x, rowY), 0, 3, delay);
            }
            sdkSpriteFreeNode(resource);
            sprite = (s16)(rowIndex + 0x297);
            fclSpriteCreate(sprite, fclMakeVec2(36.0f + position.x, rowY), 163.0f, 0x57);
            resource = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x18C);
            if (mode == 1) {
                fclSpriteStartAlphaAt(sprite, 0xFF, 0, 0, 0, delay + 3);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, 1.0f, transitionScale, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(36.0f + position.x, rowY), fclMakeVec2(36.0f + position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), 0, 3, delay);
            } else {
                ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                fclSpriteStartAlphaAt(sprite, 0, 0xFF, 0, 0, delay);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, transitionScale, 1.0f, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(36.0f + position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), fclMakeVec2(36.0f + position.x, rowY), 0, 3, delay);
            }
            sdkSpriteFreeNode(resource);
        }
        sprite = (s16)(rowIndex + 0x2A3);
        resource = sdkSpriteNewNode(fclCombineGetSpritePool(), (u16)((datPersonaGetArcana((u16)persona) & 0xFF) + 0x1B));
        if (mode == 1) {
            fclSpriteStartAlphaAt(sprite, 0xFF, 0, 0, 0, delay + 3);
            transitionScale = iGpffff8504;
            fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, 1.0f, transitionScale, 0, 3, delay);
            fclSpriteStartPositionAt(sprite, fclMakeVec2(8.0f + position.x, 2.0f + rowY), fclMakeVec2(8.0f + position.x, 2.0f + rowY + sdkSpriteScaledHeight(resource) / 2.0f), 0, 3, delay);
        } else {
            fclSpriteCreate(sprite, fclMakeVec2(8.0f + position.x, 2.0f + rowY), 46.0f, 0x59);
            ((FclCombineRowSprite *)fclSpriteEntry(sprite))->image = (datPersonaGetArcana((u16)persona) & 0xFF) + 0x1B;
            ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = fclMakeDrawColor(0, 0, 0x66, 0xFF);
            fclSpriteStartAlphaAt(sprite, 0, 0xFF, 0, 0, delay);
            transitionScale = iGpffff8504;
            fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, transitionScale, 1.0f, 0, 3, delay);
            fclSpriteStartPositionAt(sprite, fclMakeVec2(8.0f + position.x, 2.0f + rowY + sdkSpriteScaledHeight(resource) / 2.0f), fclMakeVec2(8.0f + position.x, 2.0f + rowY), 0, 3, delay);
        }
        sdkSpriteFreeNode(resource);
        /* The persona lookup is complete; this scalar now carries the digit delay. */
        persona = delay;
        digitRow = (s8)(rowIndex + 0xC);
        nmMesWindowShowNumber(work->digitTask, digitRow, (s16)level, fclMakeVec2(position.x - 16.0f, rowY),
                      fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0x80), 3, persona, 46.0f, 0x59, mode);
        if (rowAvailability == 2) {
            sprite = (s16)(rowIndex + 0x270);
            fclSpriteReset(sprite, 0x193);
            fclSpriteCreate(sprite, fclMakeVec2(position.x, rowY), 191.0f, 0x57);
            resource = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x193);
            if (mode == 1) {
                fclSpriteStartAlphaAt(sprite, ((FclCombineRowSprite *)fclSpriteEntry(sprite))->alpha, 0, 0, 0, delay + 3);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, 1.0f, transitionScale, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(position.x, rowY), fclMakeVec2(position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), 0, 3, delay);
            } else {
                ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = fclMakeDrawColor(0, 0, 0x99, 0xFF);
                fclSpriteStartAlphaAt(sprite, 0, 0, 0, 0, delay);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, transitionScale, 1.0f, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2(position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), fclMakeVec2(position.x, rowY), 0, 3, delay);
            }
            sdkSpriteFreeNode(resource);
            sprite = (s16)(rowIndex + 0x27D);
            fclSpriteReset(sprite, 0x19B);
            fclSpriteCreate(sprite, fclMakeVec2((f32)0x11D + position.x, rowY), 192.0f, 0x57);
            resource = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x19B);
            if (mode == 1) {
                fclSpriteStartAlphaAt(sprite, ((FclCombineRowSprite *)fclSpriteEntry(sprite))->alpha, 0, 0, 0, delay + 3);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, 1.0f, transitionScale, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2((f32)0x11D + position.x, rowY), fclMakeVec2((f32)0x11D + position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), 0, 3, delay);
            } else {
                ((FclCombineRowSprite *)fclSpriteEntry(sprite))->color = fclMakeDrawColor(0, 0, 0x99, 0xFF);
                fclSpriteStartAlphaAt(sprite, 0, 0, 0, 0, delay);
                fclSpriteStartRevealScaleAt(sprite, 1.0f, 1.0f, transitionScale, 1.0f, 0, 3, delay);
                fclSpriteStartPositionAt(sprite, fclMakeVec2((f32)0x11D + position.x, rowY + sdkSpriteScaledHeight(resource) / 2.0f), fclMakeVec2((f32)0x11D + position.x, rowY), 0, 3, delay);
            }
            sdkSpriteFreeNode(resource);
            fclSpriteReset(0xCF, 0xCF);
            fclSpriteStartShowHide(0xCF, fclMakeVec2(position.x - 10.0f, rowY - 12.0f), 0xCF, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0x80), 193.0f, 0x56, mode, 3, 3, delay, fclCombineGetSpritePool());
            fclSpriteReset(0xD2, 0xD2);
            fclSpriteStartShowHide(0xD2, fclMakeVec2(282.0f + position.x, rowY - 12.0f), 0xD2, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0x80), 193.0f, 0x56, mode, 3, 3, delay, fclCombineGetSpritePool());
            if (mode == 0) {
                work->cursorPosition = fclMakeVec2(position.x - 60.0f, rowY - 8.0f);
                fclSpriteCreate(0x1C7, fclMakeVec2(position.x - 60.0f, rowY - 8.0f), 190.0f, 0x58);
                ((FclCombineRowSprite *)fclSpriteEntry(0x1C7))->alpha = 0;
                work->firstCursorState = 0;
                fclSpriteSetFlag(0x1C7, 2, 1);
                ((FclCombineRowSprite *)fclSpriteEntry(0x1C7))->flag73 = 1;
                fclSpriteReset(0x2E8, 0x1C7);
                fclSpriteCreate(0x2E8, fclMakeVec2(position.x - 60.0f, rowY - 8.0f), 190.0f, 0x58);
                ((FclCombineRowSprite *)fclSpriteEntry(0x2E8))->alpha = 0;
                work->secondCursorState = 0;
                fclSpriteSetFlag(0x2E8, 2, 1);
                ((FclCombineRowSprite *)fclSpriteEntry(0x2E8))->flag73 = 1;
                ((FclCombineRowSprite *)fclSpriteEntry((s16)(rowIndex + 0x2A3)))->color = fclMakeDrawColor(0xFF, 0xCC, 0xFA, 0xFF);
                nmMesWindowSetNumberColor(work->digitTask, digitRow, fclMakeDrawColor(0xFF, 0xCC, 0xFA, 0xFF));
                return;
            }
            fclSpriteSetFlag(0x1C7, 0, 1);
            fclSpriteSetFlag(0x2E8, 0, 1);
        }
    } else {
        fclSpriteSetFlag((s16)(row + 0x270), 0, 1);
        fclSpriteSetFlag((s16)(row + 0x27D), 0, 1);
        fclSpriteSetFlag((s16)(row + 0x28B), 0, 1);
        fclSpriteSetFlag((s16)(row + 0x297), 0, 1);
        fclSpriteSetFlag((s16)(row + 0x2A3), 0, 1);
    }
}


/* The coordinate pairs are FclVec2 values: fclMakeVec2 returns its point by
   value (hidden result pointer), so each point is built inside the call that
   consumes it.  Building both endpoints within one fclSpriteStartPositionAt call is what
   lets the destination Y be evaluated before the first constructor call. */
// Draw the Persona summary for slot, moving its art, labels, arcana and level from startPosition to endPosition.
// FUN_0031C2B0
void fclCombineDrawPersonaCard(u8 *task, s16 slot, FclVec2 startPosition, FclVec2 endPosition) {
    /* Read the Persona ID as signed here; the shared Persona header exposes its unsigned representation. */
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclDrawColor drawColor8;
    FclVec2 pos;
    s16 w;
    s16 b;
    u8 alpha;

    w = (s16)((FclCombinePersonaHeader *)yListSlotEntry(0, slot))->personaId;
    b = ((FclCombinePersonaHeader *)yListSlotEntry(0, slot))->level;
    pos = startPosition;
    alpha = ((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha;
    fclSpriteCreate(0x7C, fclMakeVec2(pos.x, pos.y - 2.0f), 124.0f, 0x58);
    fclSpriteStartPositionAt(0x7C, fclMakeVec2(startPosition.x, startPosition.y - 2.0f), fclMakeVec2(endPosition.x, endPosition.y - 2.0f), 0, 0xA, 0);

    fclSpriteCreate(0x228, fclMakeVec2(36.0f + pos.x, pos.y - 2.0f), 126.0f, 0x58);
    drawColor1 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x228))->color = drawColor1;
    ((FclCombineRowSprite *)fclSpriteEntry(0x228))->alpha = alpha;
    fclSpriteStartPositionAt(0x228, fclMakeVec2(36.0f + pos.x, pos.y - 2.0f), fclMakeVec2(36.0f + endPosition.x, endPosition.y - 2.0f), 0, 0xA, 0);

    fclSpriteCreate(0x1A2, fclMakeVec2(94.0f + pos.x, pos.y - 2.0f), 126.0f, 0x58);
    drawColor2 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x1A2))->color = drawColor2;
    ((FclCombineRowSprite *)fclSpriteEntry(0x1A2))->alpha = alpha;
    fclSpriteStartPositionAt(0x1A2, fclMakeVec2(94.0f + pos.x, pos.y - 2.0f), fclMakeVec2(94.0f + endPosition.x, endPosition.y - 2.0f), 0, 0xA, 0);

    fclSpriteCreate(0x25C, fclMakeVec2(43.0f + pos.x, pos.y), 46.0f, 0x59);
    ((FclCombineRowSprite *)fclSpriteEntry(0x25C))->image = (datPersonaGetArcana((u16)w) & 0xFF) + 0x1B;
    drawColor3 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x25C))->color = drawColor3;
    ((FclCombineRowSprite *)fclSpriteEntry(0x25C))->alpha = alpha;
    fclSpriteStartPositionAt(0x25C, fclMakeVec2(43.0f + pos.x, pos.y), fclMakeVec2(43.0f + endPosition.x, endPosition.y), 0, 0xA, 0);

    fclSpriteCreate(0x54, fclMakeVec2((f32)0x117 + pos.x, 6.0f + pos.y), 189.0f, 0x56);
    drawColor4 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x54))->color = drawColor4;
    ((FclCombineRowSprite *)fclSpriteEntry(0x54))->alpha = alpha;
    fclSpriteStartPositionAt(0x54, fclMakeVec2((f32)0x115 + pos.x, 6.0f + pos.y), fclMakeVec2((f32)0x115 + endPosition.x, 6.0f + endPosition.y), 0, 0xA, 0);

    if (b >= 10) {
        fclSpriteCreate(0x26A, fclMakeVec2(320.0f + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26A))->image = b % 10 + 0x46;
        drawColor5 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26A))->color = drawColor5;
        fclSpriteStartPositionAt(0x26A, fclMakeVec2(320.0f + pos.x, 6.0f + pos.y), fclMakeVec2(320.0f + endPosition.x, 6.0f + endPosition.y), 0, 0xA, 0);
        fclSpriteCreate(0x26B, fclMakeVec2((f32)0x12D + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26B))->image = b / 10 + 0x46;
        drawColor6 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26B))->color = drawColor6;
        fclSpriteStartPositionAt(0x26B, fclMakeVec2((f32)0x12D + pos.x, 6.0f + pos.y), fclMakeVec2((f32)0x12D + endPosition.x, 6.0f + endPosition.y), 0, 0xA, 0);
    } else {
        fclSpriteCreate(0x26A, fclMakeVec2((f32)0x13D + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26A))->image = b % 10 + 0x46;
        drawColor7 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26A))->color = drawColor7;
        fclSpriteStartPositionAt(0x26A, fclMakeVec2((f32)0x137 + pos.x, 6.0f + pos.y), fclMakeVec2((f32)0x137 + endPosition.x, 6.0f + endPosition.y), 0, 0xA, 0);
        fclSpriteSetFlag(0x26B, 0, 1);
    }
    fclSpriteCreate(0x74, fclMakeVec2((f32)0x14D + pos.x, 13.0f + pos.y), 188.0f, 0x58);
    drawColor8 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x74))->color = drawColor8;
    ((FclCombineRowSprite *)fclSpriteEntry(0x74))->alpha = alpha;
    fclSpriteStartPositionAt(0x74, fclMakeVec2((f32)0x14D + pos.x, 13.0f + pos.y), fclMakeVec2((f32)0x14D + endPosition.x, 13.0f + endPosition.y), 0, 0xA, 0);
}

/* Same point-by-value construction as fclCombineDrawPersonaCard. */
// Draw the alternate summary-card sprite set for slot, moving from startPosition to endPosition.
// FUN_0031CCE0
void fclCombineDrawPersonaCardAlt(u8 *task, s16 slot, FclVec2 startPosition, FclVec2 endPosition) {
    /* Read the Persona ID as signed here; the shared Persona header exposes its unsigned representation. */
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclVec2 pos;
    s16 w;
    s16 b;
    u8 alpha;

    w = (s16)((FclCombinePersonaHeader *)yListSlotEntry(0, slot))->personaId;
    b = ((FclCombinePersonaHeader *)yListSlotEntry(0, slot))->level;
    pos = startPosition;
    alpha = ((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha;
    fclSpriteCreate(0x7D, fclMakeVec2(pos.x, pos.y - 1.0f), 125.0f, 0x58);
    fclSpriteStartPositionAt(0x7D, fclMakeVec2(startPosition.x, startPosition.y - 1.0f), fclMakeVec2(endPosition.x, endPosition.y - 1.0f), 0, 0xA, 0);

    fclSpriteCreate(0x229, fclMakeVec2(36.0f + pos.x, pos.y - 2.0f), 126.0f, 0x58);
    drawColor1 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x229))->color = drawColor1;
    ((FclCombineRowSprite *)fclSpriteEntry(0x229))->alpha = alpha;
    fclSpriteStartPositionAt(0x229, fclMakeVec2(36.0f + pos.x, pos.y - 2.0f), fclMakeVec2(36.0f + endPosition.x, endPosition.y - 2.0f), 0, 0xA, 0);

    fclSpriteCreate(0x2B1, fclMakeVec2(94.0f + pos.x, pos.y - 2.0f), 126.0f, 0x58);
    drawColor2 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x2B1))->color = drawColor2;
    ((FclCombineRowSprite *)fclSpriteEntry(0x2B1))->alpha = alpha;
    fclSpriteStartPositionAt(0x2B1, fclMakeVec2(94.0f + pos.x, pos.y - 2.0f), fclMakeVec2(94.0f + endPosition.x, endPosition.y - 2.0f), 0, 0xA, 0);

    fclSpriteCreate(0x25D, fclMakeVec2(43.0f + pos.x, 1.0f + pos.y), 46.0f, 0x59);
    ((FclCombineRowSprite *)fclSpriteEntry(0x25D))->image = (datPersonaGetArcana((u16)w) & 0xFF) + 0x1B;
    drawColor3 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x25D))->color = drawColor3;
    ((FclCombineRowSprite *)fclSpriteEntry(0x25D))->alpha = alpha;
    fclSpriteStartPositionAt(0x25D, fclMakeVec2(43.0f + pos.x, 1.0f + pos.y), fclMakeVec2(43.0f + endPosition.x, 1.0f + endPosition.y), 0, 0xA, 0);

    fclSpriteCreate(0x2B2, fclMakeVec2((f32)0x117 + pos.x, 6.0f + pos.y), 189.0f, 0x56);
    drawColor4 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x2B2))->color = drawColor4;
    ((FclCombineRowSprite *)fclSpriteEntry(0x2B2))->alpha = alpha;
    fclSpriteStartPositionAt(0x2B2, fclMakeVec2((f32)0x115 + pos.x, 6.0f + pos.y), fclMakeVec2((f32)0x115 + endPosition.x, 6.0f + endPosition.y), 0, 0xA, 0);

    if (b >= 10) {
        fclSpriteCreate(0x26C, fclMakeVec2(320.0f + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26C))->image = b % 10 + 0x46;
        drawColor5 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26C))->color = drawColor5;
        fclSpriteStartPositionAt(0x26C, fclMakeVec2(320.0f + pos.x, 6.0f + pos.y), fclMakeVec2(320.0f + endPosition.x, 6.0f + endPosition.y), 0, 0xA, 0);
        fclSpriteCreate(0x26D, fclMakeVec2((f32)0x12D + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26D))->image = b / 10 + 0x46;
        drawColor6 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26D))->color = drawColor6;
        fclSpriteStartPositionAt(0x26D, fclMakeVec2((f32)0x12D + pos.x, 6.0f + pos.y), fclMakeVec2((f32)0x12D + endPosition.x, 6.0f + endPosition.y), 0, 0xA, 0);
    } else {
        fclSpriteCreate(0x26C, fclMakeVec2((f32)0x13D + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26C))->image = b % 10 + 0x46;
        drawColor7 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x26C))->color = drawColor7;
        fclSpriteStartPositionAt(0x26C, fclMakeVec2((f32)0x137 + pos.x, 6.0f + pos.y), fclMakeVec2((f32)0x137 + endPosition.x, 6.0f + endPosition.y), 0, 0xA, 0);
        fclSpriteSetFlag(0x26D, 0, 1);
    }
}

/* Selects a slot entry using packed color values, signed-byte slots and the list row offset. */
// FUN_0031D630
/* measured: retail does not propagate copies in this function. */
#pragma opt_propagation off
void fclCombineSelectSlotEntry(u8 *task, s8 slot, s8 firstSelectedSlot, s64 secondSelectedSlot, s64 skipRoster) {
    typedef union { FclDrawColor channels; u32 word; } PackedColor;
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    PackedColor packedColor1;
    FclDrawColor drawColor8;
    FclDrawColor drawColor9;
    u8 *work;
    s8 v;
    u8 *p;
    u8 *q;
    u8 *e;
    s32 result;
    f32 f;
    work = ((struct KwlnTask *)task)->work;
    v = (s8)slot;
    if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry((s16)(v + 0x21C)))->flags, 1) != 0) {
        return;
    }
    if (((FclCombineRowWork *)work)->cursorRow == v) {
        result = fclCombineApplySlotState(task, slot, 1, 0xFF);
        ((FclCombineBallWork *)((u8 *)fclCombineGetWorkAlt(((u8 **)(work + 0x21C))[(s32)v])))->colorMode = 1;
        if ((s8)skipRoster == 0) {
            s16 i = 0;
            s8 row = slot;
            u8 *base = work + (s32)v * 4;
            s32 off12 = row * 12;
            for (; (s16)i < (u16)datPersonaRosterCapacity(); ++i) {
                e = fclCombineSlotRecord(((FclCombineRowWork *)base)->gridRowTasks[0], (s8)i);
                if (((*(s16 *)e & 4) >> 2) == 0) {
                    drawColor1 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    p = fclCombineSlotRecord(MEMBER(u8 *, base, FclCombineRowWork, gridRowTasks[0]), (s8)i);
                    ((FclObject *)((u8 *)p - 4))->color = drawColor1;
                    ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, base, FclCombineRowWork, gridRowTasks[0]), (s8)i) - 4))->alpha = 0xFF;
                    if (((FclCombineRowList *)((u8 *)(off12 + (uintptr_t)yListSlotWork(0)) + (s16)i))->availability[0][0] > 0) {
                        drawColor2 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                        p = fclCombineSlotRecord(MEMBER(u8 *, base, FclCombineRowWork, gridRowTasks[0]), (s8)i);
                        ((FclObject *)((u8 *)p - 4))->color = drawColor2;
                    }
                }
            }
        }
    } else {
        result = fclCombineApplySlotState(task, slot, 0, 0xFF);
        if (((FclCombinePersonaListHeader *)yListSlotWork(0))->count <= v) {
            s32 overflowSlot = (s8)slot;
            drawColor3 = fclMakeDrawColor(0x24, 0x3F, 0x9F, 0xFF);
            p = fclSpriteEntry((s16)(overflowSlot + 0x244));
            ((FclCombineRowSprite *)p)->color = drawColor3;
            q = fclSpriteEntry((s16)(overflowSlot + 0x238));
            ((FclCombineRowSprite *)q)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
            ((FclCombineBallWork *)((u8 *)fclCombineGetWorkAlt(((u8 **)(work + 0x21C))[overflowSlot])))->colorMode = 0;
        }
        if ((s8)firstSelectedSlot == v || (s8)secondSelectedSlot == v) {
            s32 highlightedSlot = (s8)slot;
            s32 v22b = highlightedSlot + 0x22B;
            s32 v21c = highlightedSlot + 0x21C;
            drawColor4 = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
            p = fclSpriteEntry((s16)v22b);
            ((FclCombineRowSprite *)p)->color = drawColor4;
            q = fclSpriteEntry((s16)v21c);
            ((FclCombineRowSprite *)q)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
            ((FclCombineRowSprite *)fclSpriteEntry((s16)v21c))->alpha =
                ((FclCombineRowSprite *)fclSpriteEntry((s16)v22b))->alpha = 0xFF;
            drawColor5 = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
            p = fclSpriteEntry((s16)(highlightedSlot + 0x244));
            ((FclCombineRowSprite *)p)->color = drawColor5;
            q = fclSpriteEntry((s16)(highlightedSlot + 0x238));
            ((FclCombineRowSprite *)q)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
            drawColor6 = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
            p = fclCombineSlotRecord((u8 *)((FclCombineWork *)work)->f188, slot);
            ((FclObject *)((u8 *)p - 4))->color = drawColor6;
            drawColor7 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
            p = fclSpriteEntry((s16)(highlightedSlot + 0x39));
            ((FclCombineRowSprite *)p)->color = drawColor7;
            result = fclPackRgba(0, 0, 0x66, 0xFF);
            packedColor1.channels = fclMakeDrawColor(0, 0, 0x66, 0xFF);
            nmMesWindowSetNumberColor(((FclCombineRowWork *)work)->digitTask, (s8)slot, packedColor1.channels);
        }
        if ((s8)skipRoster == 0) {
            s16 j = 0;
            u8 *base = work + (s8)slot * 4;
            s32 off12 = (s8)slot * 12;
            for (; (s16)j < (u16)datPersonaRosterCapacity(); ++j) {
                e = fclCombineSlotRecord(((FclCombineRowWork *)base)->gridRowTasks[0], (s8)j);
                if (((*(s16 *)e & 4) >> 2) == 0) {
                    drawColor8 = fclMakeDrawColor(0, 0, 0x99, 0xA5);
                    p = fclCombineSlotRecord(MEMBER(u8 *, base, FclCombineRowWork, gridRowTasks[0]), (s8)j);
                    ((FclObject *)((u8 *)p - 4))->color = drawColor8;
                    ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, base, FclCombineRowWork, gridRowTasks[0]), (s8)j) - 4))->alpha = 0xA5;
                    if (((FclCombineRowList *)((u8 *)(off12 + (uintptr_t)yListSlotWork(0)) + (s16)j))->availability[0][0] > 0) {
                        drawColor9 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xA5);
                        p = fclCombineSlotRecord(MEMBER(u8 *, base, FclCombineRowWork, gridRowTasks[0]), (s8)j);
                        ((FclObject *)((u8 *)p - 4))->color = drawColor9;
                        ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, base, FclCombineRowWork, gridRowTasks[0]), (s8)j) - 4))->alpha = 0xCC;
                    }
                }
            }
        }
    }
    if (v < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
        f = (f32)((s32)v * 0x17 + 0x80);
        frFontExDrawTextDeferredOutB(113.0f, f, 43.0f, result, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(((FclCombinePersonaHeader *)yListSlotEntry(0, (s8)slot))->personaId) * 0x11), 0, 0, D_00795E60, 0x15);
    }
}

#pragma opt_propagation on
/* Apply selected or idle colors to slot and return its packed label color with the requested
 * opacity. */
// FUN_0031DDF0
s32 fclCombineApplySlotState(u8 *task, s8 slot, s8 selected, u8 opacity) {
    typedef union { FclDrawColor channels; u32 word; } PackedColor;
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    PackedColor packedColor1;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    PackedColor packedColor2;
    u8 *work;
    u8 *p;
    u8 *q;
    s32 result;

    work = ((struct KwlnTask *)task)->work;
    if (selected == 1) {
        s32 slotIndex;
        s32 rightBarSprite;
        s32 leftBarSprite;
        slotIndex = (s8)slot;
        rightBarSprite = slotIndex + 0x22B;
        leftBarSprite = slotIndex + 0x21C;
        ((FclCombineRowSprite *)fclSpriteEntry((s16)leftBarSprite))->alpha =
            ((FclCombineRowSprite *)fclSpriteEntry((s16)rightBarSprite))->alpha = 0xFF;
        drawColor1 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
        p = fclCombineSlotRecord((u8 *)((FclCombineWork *)work)->f188, slot);
        ((FclObject *)((u8 *)p - 4))->color = drawColor1;
        q = fclSpriteEntry((s16)(slotIndex + 0x244));
        ((FclCombineRowSprite *)q)->color = ((FclCombineRowSprite *)p)->colorStart;
        p = fclSpriteEntry((s16)(slotIndex + 0x238));
        ((FclCombineRowSprite *)p)->color = MEMBER(FclDrawColor, q, FclCombineRowSprite, color);
        q = fclSpriteEntry((s16)rightBarSprite);
        ((FclCombineRowSprite *)q)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
        p = fclSpriteEntry((s16)leftBarSprite);
        ((FclCombineRowSprite *)p)->color = MEMBER(FclDrawColor, q, FclCombineRowSprite, color);
        drawColor2 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        p = fclSpriteEntry((s16)(slotIndex + 0x250));
        ((FclCombineRowSprite *)p)->color = drawColor2;
        q = fclSpriteEntry((s16)(slotIndex + 0x39));
        ((FclCombineRowSprite *)q)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
        packedColor1.channels = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        nmMesWindowSetNumberColor(((FclCombineRowWork *)work)->digitTask, (s8)slot, packedColor1.channels);
        result = fclPackRgba(0x2D, 0x2D, 0x2D, opacity);
    } else {
        s32 slotIndex;
        s32 rightBarSprite;
        s32 leftBarSprite;
        slotIndex = (s8)slot;
        rightBarSprite = slotIndex + 0x22B;
        leftBarSprite = slotIndex + 0x21C;
        drawColor3 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        p = fclSpriteEntry((s16)rightBarSprite);
        ((FclCombineRowSprite *)p)->color = drawColor3;
        q = fclSpriteEntry((s16)leftBarSprite);
        ((FclCombineRowSprite *)q)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
        ((FclCombineRowSprite *)fclSpriteEntry((s16)leftBarSprite))->alpha =
            ((FclCombineRowSprite *)fclSpriteEntry((s16)rightBarSprite))->alpha = 0x66;
        drawColor4 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        p = fclSpriteEntry((s16)(slotIndex + 0x244));
        ((FclCombineRowSprite *)p)->color = drawColor4;
        q = fclSpriteEntry((s16)(slotIndex + 0x238));
        ((FclCombineRowSprite *)q)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
        drawColor5 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
        ((FclObject *)((u8 *)fclCombineSlotRecord((u8 *)((FclCombineWork *)work)->f188, slot) - 4))->color = drawColor5;
        drawColor6 = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry((s16)(slotIndex + 0x39)))->color = drawColor6;
        drawColor7 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry((s16)(slotIndex + 0x250)))->color = drawColor7;
        packedColor2.channels = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        nmMesWindowSetNumberColor(((FclCombineRowWork *)work)->digitTask, (s8)slot, packedColor2.channels);
        result = fclPackRgba(0xCC, 0xFF, 0xFF, opacity);
    }
    return result;
}
// Flash slot's four sprites and descriptor pale yellow, enabling their color-transition flags.
// FUN_0031E320
void fclCombineFlashSlot(u8 *task, s8 slot) {
    s32 idx;
    s16 n1;
    s16 n2;
    s16 n3;
    s16 n4;
    u8 *work;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    u8 *q1;
    u8 *q2;
    FclDrawColor drawColor1, drawColor2, drawColor3, drawColor4, drawColor5;

    work = ((struct KwlnTask *)task)->work;
    idx = (s8)slot;
    n1 = (s16)(idx + 0x21C);
    p1 = fclSpriteEntry(n1);
    drawColor1 = fclMakeDrawColor(0xFF, 0xFF, 0x9E, 0xFF);
    fclSpriteStartColorAt(n1, *(s32 *)&((FclCombineRowSprite *)p1)->color, *(s32 *)&drawColor1, 1, 6, 0);
    ((FclCombineDrawSprite *)fclSpriteEntry(n1))->colorTransitionActive = 1;
    n2 = (s16)(idx + 0x22B);
    p2 = fclSpriteEntry(n2);
    drawColor2 = fclMakeDrawColor(0xFF, 0xFF, 0x9E, 0xFF);
    fclSpriteStartColorAt(n2, *(s32 *)&((FclCombineRowSprite *)p2)->color, *(s32 *)&drawColor2, 1, 6, 0);
    ((FclCombineDrawSprite *)fclSpriteEntry(n2))->colorTransitionActive = 1;
    n3 = (s16)(idx + 0x238);
    p3 = fclSpriteEntry(n3);
    drawColor3 = fclMakeDrawColor(0xFF, 0xFF, 0x9E, 0xFF);
    fclSpriteStartColorAt(n3, *(s32 *)&((FclCombineRowSprite *)p3)->color, *(s32 *)&drawColor3, 1, 6, 0);
    ((FclCombineDrawSprite *)fclSpriteEntry(n3))->colorTransitionActive = 1;
    n4 = (s16)(idx + 0x244);
    p4 = fclSpriteEntry(n4);
    drawColor4 = fclMakeDrawColor(0xFF, 0xFF, 0x9E, 0xFF);
    fclSpriteStartColorAt(n4, *(s32 *)&((FclCombineRowSprite *)p4)->color, *(s32 *)&drawColor4, 1, 6, 0);
    ((FclCombineDrawSprite *)fclSpriteEntry(n4))->colorTransitionActive = 1;
    q1 = fclCombineSlotRecord((u8 *)((FclCombineWork *)work)->f188, slot);
    q2 = fclCombineSlotRecord(MEMBER(u8 *, work, FclCombineWork, ballTask.task), slot);
    drawColor5 = fclMakeDrawColor(0xFF, 0xFF, 0x9E, 0xFF);
    fclSpriteStartColor(q1, ((FclObject *)((u8 *)q2 - 4))->color, *(FclDrawColor *)&drawColor5, 1, 6, 0);
    ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, work, FclCombineWork, ballTask.task), slot) - 4))->colorLoop = 1;
}


/* Draw slot-field chips and values at position with delay/mode; alternateSprites, narrowLayout and
 * variant select the layout. variant must be 0..3, as retail has no default case. */
// FUN_0031E5B0
void fclCombineDrawSlotFields(u8 *task, FclVec2 position, s16 delay, s8 mode, s32 alternateSprites, s32 narrowLayout, s32 variant) {
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclVec2 pos;
    f32 by;
    f32 y;
    s16 id;
    s16 idB;
    s8 alternateSet;
    s8 compactSet;
    s8 fieldVariant;
    u8 *h0;
    u8 *h1;
    u8 *h2;
    u8 *h3;
    u8 *h4;
    u8 *h5;
    u8 *p;

    (void)task;
    id = 0x193;
    pos = position;
    alternateSet = (s8)alternateSprites;
    if (alternateSet == 1) {
        id = 0x2B4;
    }
    fieldVariant = (s8)variant;
    if (fieldVariant == 3) {
        pos.x = pos.x + 1.0f;
    }
    h0 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x193);
    fclSpriteCreate(id, fclMakeVec2(pos.x, pos.y), 191.0f, 0x57);
    drawColor1 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
    p = fclSpriteEntry(id);
    ((FclCombineRowSprite *)p)->color = drawColor1;
    fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(id, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h0) / 2.0f), fclMakeVec2(pos.x, pos.y), 0, 3, delay);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, (s16)((s16)delay + 3));
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(pos.x, pos.y), fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h0) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(h0);
    switch (fieldVariant) {
    case 0:
        id = 0x19A;
        idB = id;
        pos = fclMakeVec2((f32)0x12D + position.x, position.y);
        if ((s8)narrowLayout == 1) {
            pos = fclMakeVec2((f32)0x11D + position.x, position.y);
        }
        break;
    case 1:
        id = 0x1A0;
        idB = id;
        pos = fclMakeVec2(36.0f + ((f32)0x12D + position.x), position.y);
        if ((s8)narrowLayout == 1) {
            pos = fclMakeVec2(36.0f + ((f32)0x11D + position.x), position.y);
        }
        break;
    case 2:
        id = 0x1A4;
        idB = id;
        pos = fclMakeVec2((f32)0x12D + position.x, position.y);
        if ((s8)narrowLayout == 1) {
            pos = fclMakeVec2((f32)0x11D + position.x, position.y);
        }
        break;
    case 3:
        id = 0x1A4;
        idB = id;
        pos = fclMakeVec2((f32)0x12D + position.x, position.y);
        if ((s8)narrowLayout == 1) {
            pos = fclMakeVec2((f32)0x11D + position.x, position.y);
        }
        pos.x = pos.x + 4.0f;
        break;
    }
    if (alternateSet == 1) {
        id = 0x2B5;
    }
    compactSet = (s8)narrowLayout;
    if (compactSet == 1) {
        id = 0x28A;
    }
    fclSpriteReset(id, idB);
    h1 = sdkSpriteNewNode(fclCombineGetSpritePool(), idB);
    fclSpriteCreate(id, fclMakeVec2(pos.x, pos.y), 191.0f, 0x57);
    drawColor2 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
    p = fclSpriteEntry(id);
    ((FclCombineRowSprite *)p)->color = drawColor2;
    fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(id, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h1) / 2.0f), fclMakeVec2(pos.x, pos.y), 0, 3, delay);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, (s16)((s16)delay + 3));
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        fclSpriteStartPositionAt(id, fclMakeVec2(pos.x, pos.y), fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h1) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(h1);

    id = 0x51;
    by = position.y;
    y = 5.0f + by;
    pos = fclMakeVec2(29.0f + position.x, y);
    if (alternateSet == 1) {
        id = 0x2B6;
    }
    if (compactSet == 1) {
        pos = fclMakeVec2(13.0f + position.x, y);
    }
    if (fieldVariant == 3) {
        pos.x = pos.x + 4.0f;
    }
    if (fieldVariant == 1) {
        pos.x = pos.x + 3.0f;
    }
    h2 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x51);
    fclSpriteCreate(id, pos, 176.0f, 0x59);
    drawColor3 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    p = fclSpriteEntry(id);
    ((FclCombineRowSprite *)p)->color = drawColor3;
    fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(id, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h2) / 2.0f), pos, 0, 3, delay);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, (s16)((s16)delay + 3));
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        fclSpriteStartPositionAt(id, pos, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h2) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(h2);

    id = 0x52;
    pos = fclMakeVec2(151.0f + position.x, y);
    if (alternateSet == 1) {
        id = 0x2B7;
    }
    if (compactSet == 1) {
        pos = fclMakeVec2(135.0f + position.x, y);
    }
    if (fieldVariant == 3) {
        pos.x = pos.x + 4.0f;
    }
    if (fieldVariant == 1) {
        pos.x = pos.x + 3.0f;
    }
    h3 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x52);
    fclSpriteCreate(id, pos, 176.0f, 0x59);
    drawColor4 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
    p = fclSpriteEntry(id);
    ((FclCombineRowSprite *)p)->color = drawColor4;
    fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(id, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h3) / 2.0f), pos, 0, 3, delay);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, (s16)((s16)delay + 3));
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        fclSpriteStartPositionAt(id, pos, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h3) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(h3);

    id = 0x53;
    y = 6.0f + by;
    pos = fclMakeVec2(274.0f + position.x, y);
    if (alternateSet == 1) {
        id = 0x2B8;
    }
    if (compactSet == 1) {
        pos = fclMakeVec2(258.0f + position.x, y);
    }
    if (fieldVariant == 3) {
        pos.x = pos.x + 6.0f;
    }
    if (fieldVariant == 1) {
        pos.x = pos.x + 3.0f;
    }
    h4 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x53);
    fclSpriteCreate(id, pos, 176.0f, 0x59);
    drawColor5 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
    p = fclSpriteEntry(id);
    ((FclCombineRowSprite *)p)->color = drawColor5;
    fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(id, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h4) / 2.0f), pos, 0, 3, delay);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, (s16)((s16)delay + 3));
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        fclSpriteStartPositionAt(id, pos, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h4) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(h4);

    id = 0x73;
    y = 9.0f + by;
    pos = fclMakeVec2(100.0f + position.x, y);
    if (alternateSet == 1) {
        id = 0x2B9;
    }
    if (compactSet == 1) {
        pos = fclMakeVec2(84.0f + position.x, y);
    }
    if (fieldVariant == 3) {
        pos.x = pos.x + 4.0f;
    }
    if (fieldVariant == 1) {
        pos.x = pos.x + 3.0f;
    }
    h5 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x73);
    fclSpriteCreate(id, pos, 175.0f, 0x59);
    drawColor6 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    p = fclSpriteEntry(id);
    ((FclCombineRowSprite *)p)->color = drawColor6;
    fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(id, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h5) / 2.0f), pos, 0, 3, delay);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, (s16)((s16)delay + 3));
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        fclSpriteStartPositionAt(id, pos, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h5) / 2.0f), 0, 3, delay);
    }

    id = 0x237;
    pos = fclMakeVec2(225.0f + position.x, y);
    if (alternateSet == 1) {
        id = 0x2BA;
    }
    if (compactSet == 1) {
        pos = fclMakeVec2(209.0f + position.x, y);
    }
    if (fieldVariant == 3) {
        pos.x = pos.x + 4.0f;
    }
    if (fieldVariant == 1) {
        pos.x = pos.x + 3.0f;
    }
    fclSpriteCreate(id, pos, 175.0f, 0x59);
    drawColor7 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    p = fclSpriteEntry(id);
    ((FclCombineRowSprite *)p)->color = drawColor7;
    fclSpriteStartAlphaAt(id, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(id, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h5) / 2.0f), pos, 0, 3, delay);
    if ((s8)mode == 1) {
        fclSpriteStartAlphaAt(id, 0xFF, 0, 0, 0, (s16)((s16)delay + 3));
        fclSpriteStartRevealScaleAt(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        fclSpriteStartPositionAt(id, pos, fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(h5) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(h5);
}

#pragma push
/* measured: retail does not split local lifetimes in fclCombineDrawSlotLabels. */
#pragma opt_lifetimes off
/* Point is built by value as in fclCombineDrawPersonaCard; reading the first x through *(f32
 * *)&arg1 keeps the anchor addressable so retail reloads it after each call. */
// FUN_0031FA20
void fclCombineDrawSlotLabels(u8 *task, FclVec2 position, s16 delay, s8 mode) {
    extern void fclSpriteStartPositionAt(s16, FclVec2, FclVec2, u32, u32, s16);
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    u8 *node0;
    u8 *node1;
    u8 *node2;
    u8 *node3;
    f32 y;
    f32 x;
    f32 top;

    node0 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x193);
    x = position.y;
    fclSpriteCreate(0x27C, fclMakeVec2(*(f32 *)&position, x), 191.0f, 0x57);
    drawColor1 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x27C))->color = drawColor1;
    fclSpriteStartAlphaAt(0x27C, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(0x27C, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(0x27C, fclMakeVec2(position.x, x + sdkSpriteScaledHeight(node0) / 2.0f), fclMakeVec2(position.x, x), 0, 3, delay);
    if (mode == 1) {
        fclSpriteStartAlphaAt(0x27C, 0xFF, 0, 0, 0, delay + 3);
        fclSpriteStartRevealScaleAt(0x27C, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        fclSpriteStartPositionAt(0x27C, fclMakeVec2(position.x, x), fclMakeVec2(position.x, x + sdkSpriteScaledHeight(node0) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(node0);
    node1 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x19B);
    y = position.y;
    x = (f32)0x11D + position.x;
    fclSpriteCreate(0x289, fclMakeVec2(x, y), 191.0f, 0x57);
    drawColor2 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x289))->color = drawColor2;
    fclSpriteStartAlphaAt(0x289, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(0x289, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(0x289, fclMakeVec2(x, y + sdkSpriteScaledHeight(node1) / 2.0f), fclMakeVec2(x, y), 0, 3, delay);
    if (mode == 1) {
        fclSpriteStartAlphaAt(0x289, 0xFF, 0, 0, 0, delay + 3);
        fclSpriteStartRevealScaleAt(0x289, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        x = (f32)0x11D + position.x;
        fclSpriteStartPositionAt(0x289, fclMakeVec2(x, y), fclMakeVec2(x, y + sdkSpriteScaledHeight(node1) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(node1);
    node2 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x72);
    top = position.y;
    y = 4.0f + top;
    x = 102.0f + position.x;
    fclSpriteCreate(0x72, fclMakeVec2(x, y), 177.0f, 0x59);
    drawColor3 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x72))->color = drawColor3;
    fclSpriteStartAlphaAt(0x72, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(0x72, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(0x72, fclMakeVec2(x, y + sdkSpriteScaledHeight(node2) / 2.0f), fclMakeVec2(x, y), 0, 3, delay);
    if (mode == 1) {
        fclSpriteStartAlphaAt(0x72, 0xFF, 0, 0, 0, delay + 3);
        fclSpriteStartRevealScaleAt(0x72, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        top = position.y;
        y = 4.0f + top;
        x = 102.0f + position.x;
        fclSpriteStartPositionAt(0x72, fclMakeVec2(x, y), fclMakeVec2(x, y + sdkSpriteScaledHeight(node2) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(node2);
    node3 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x73);
    top = position.y;
    y = 9.0f + top;
    x = 55.0f + position.x;
    fclSpriteCreate(0x2AF, fclMakeVec2(x, y), 175.0f, 0x59);
    drawColor4 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x2AF))->color = drawColor4;
    fclSpriteStartAlphaAt(0x2AF, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(0x2AF, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(0x2AF, fclMakeVec2(x, y + sdkSpriteScaledHeight(node3) / 2.0f), fclMakeVec2(x, y), 0, 3, delay);
    if (mode == 1) {
        fclSpriteStartAlphaAt(0x2AF, 0xFF, 0, 0, 0, delay + 3);
        fclSpriteStartRevealScaleAt(0x2AF, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        top = position.y;
        y = 9.0f + top;
        x = 55.0f + position.x;
        fclSpriteStartPositionAt(0x2AF, fclMakeVec2(x, y), fclMakeVec2(x, y + sdkSpriteScaledHeight(node3) / 2.0f), 0, 3, delay);
    }
    top = position.y;
    y = 9.0f + top;
    x = 208.0f + position.x;
    fclSpriteCreate(0x2B0, fclMakeVec2(x, y), 175.0f, 0x59);
    drawColor5 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x2B0))->color = drawColor5;
    fclSpriteStartAlphaAt(0x2B0, 0, 0xFF, 0, 0, delay);
    fclSpriteStartRevealScaleAt(0x2B0, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
    fclSpriteStartPositionAt(0x2B0, fclMakeVec2(x, y + sdkSpriteScaledHeight(node3) / 2.0f), fclMakeVec2(x, y), 0, 3, delay);
    if (mode == 1) {
        fclSpriteStartAlphaAt(0x2B0, 0xFF, 0, 0, 0, delay + 3);
        fclSpriteStartRevealScaleAt(0x2B0, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, delay);
        top = position.y;
        y = 9.0f + top;
        x = 208.0f + position.x;
        fclSpriteStartPositionAt(0x2B0, fclMakeVec2(x, y), fclMakeVec2(x, y + sdkSpriteScaledHeight(node3) / 2.0f), 0, 3, delay);
    }
    sdkSpriteFreeNode(node3);
}
#pragma pop

/* Starts the slot sprite slide-in for two slot resources: firstResource from the left (x - 200),
 * secondResource from the right; resource 0x92 also starts sprite 0x1E6. */
// FUN_003205F0
void fclCombineSlideInSlotSprites(u8 *task, s16 firstResource, s16 secondResource) {
    extern void fclSpriteSetHidden(u8 *, u8);
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    FclVec2 drawPosition6;
    FclVec2 drawPosition7;
    FclVec2 drawPosition8;
    FclVec2 drawPosition9;
    FclVec2 drawPosition10;
    FclVec2 drawPosition11;
    FclDrawColor drawColor1;
    FclVec2 *tbl1;
    FclVec2 *tbl2;
    FclVec2 *ca;
    s16 idx1;
    s16 idx2;
    u8 *obj;
    u8 *spriteEntry;

    obj = ((struct KwlnTask *)task)->work;
    fclSpriteSetHidden(((FclCombineWork *)obj)->f28C, 0);
    fclSpriteSetHidden(((FclCombineWork *)obj)->f290, 0);
    idx1 = (s16)firstResource;
    if (idx1 != 0) {
        tbl1 = (FclVec2 *)&D_00643D70[idx1 * 2];
        drawPosition1 = fclMakeVec2(tbl1->x - 200.0f, tbl1->y);
        fclSpriteCreate(firstResource, drawPosition1, 54.0f, 0xAC);
        drawPosition2 = fclMakeVec2(tbl1->x - 200.0f, tbl1->y);
        drawPosition3 = fclMakeVec2(tbl1->x, tbl1->y);
        fclSpriteStartPositionAt(firstResource, drawPosition2, drawPosition3, 0, 0xA, 0);
        fclSpriteStartAlphaAt(firstResource, 0, 0xFF, 0, 0xA, 0);
        if (idx1 == 0x92) {
            ca = (FclVec2 *)D_00644CA0;
            drawPosition4 = fclMakeVec2(ca->x, ca->y);
            fclSpriteCreate(0x1E6, drawPosition4, 54.0f, 0x65);
            drawPosition5 = fclMakeVec2(58.0f, ca->y);
            drawPosition6 = fclMakeVec2(ca->x, ca->y);
            fclSpriteStartPositionAt(0x1E6, drawPosition5, drawPosition6, 0, 0xA, 3);
            fclSpriteStartAlphaAt(0x1E6, 0, 0xFF, 0, 0xA, 3);
            drawColor1 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            spriteEntry = fclSpriteEntry(0x1E6);
            ((FclCombineRowSprite *)spriteEntry)->color = drawColor1;
        }
    }
    idx2 = (s16)secondResource;
    if (idx2 != 0) {
        tbl2 = (FclVec2 *)&D_00643D70[idx2 * 2];
        drawPosition7 = fclMakeVec2(tbl2->x, tbl2->y);
        fclSpriteCreate(secondResource, drawPosition7, 54.0f, 0xAC);
        drawPosition8 = fclMakeVec2(tbl2->x, tbl2->y);
        drawPosition9 = fclMakeVec2(200.0f + tbl2->x, tbl2->y);
        fclSpriteStartPositionAt(secondResource, drawPosition8, drawPosition9, 0, 0xA, 0);
        fclSpriteStartAlphaAt(secondResource, 0xFF, 0, 0, 0xA, 0);
        if (idx2 == 0x92) {
            ca = (FclVec2 *)D_00644CA0;
            drawPosition10 = fclMakeVec2(ca->x, ca->y);
            drawPosition11 = fclMakeVec2(122.0f, ca->y);
            fclSpriteStartPositionAt(0x1E6, drawPosition10, drawPosition11, 0, 6, 2);
            fclSpriteStartAlphaAt(0x1E6, 0xFF, 0, 0, 6, 2);
        }
    }
}
// Fcl combine slot icons: creates the four slot icon sprites at their fixed positions.
// FUN_00320970
void fclCombineCreateSlotIcons(u8 *task, s8 mode) {
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 *p;

    p = (FclVec2 *)D_00644020;
    drawPosition1 = fclMakeVec2(p->x, p->y);
    drawColor1 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    fclSpriteStartShowHide(0x56, drawPosition1, 0x56, drawColor1, 55.0f, 0xAA, mode, 6, 6, 0, fclCombineGetSpritePool());
    p = (FclVec2 *)D_00644098;
    drawPosition2 = fclMakeVec2(p->x, p->y);
    drawColor2 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    fclSpriteStartShowHide(0x65, drawPosition2, 0x65, drawColor2, 56.0f, 0xAA, mode, 6, 6, 0, fclCombineGetSpritePool());
    p = (FclVec2 *)D_00644AD0;
    drawPosition3 = fclMakeVec2(p->x, p->y);
    drawColor3 = fclMakeDrawColor(0xE, 0x17, 0x49, 0x80);
    fclSpriteStartShowHide(0x1AC, drawPosition3, 0x1AC, drawColor3, 57.0f, 0xA9, mode, 6, 6, 0, fclCombineGetSpritePool());
    p = (FclVec2 *)D_00644B00;
    drawPosition4 = fclMakeVec2(p->x, p->y);
    drawColor4 = fclMakeDrawColor(0xE, 0x17, 0x49, 0x80);
    fclSpriteStartShowHide(0x1B2, drawPosition4, 0x1B2, drawColor4, 58.0f, 0xA9, mode, 6, 6, 0, fclCombineGetSpritePool());
}

/* The s16 row/column counters reproduce retail's Persona lookups without sign extension; the grid
 * phase takes a signed wide row snapshot and narrows it once for word indexing. */


/* Clear the transition-start flag for one grid cell, biasing the row view by the column before the
 * field displacement. measured: retail adds the column to the row pointer first; direct indexed
 * stores change the code at both call sites. */
static inline void fclClearGridCellTransition(FclCombineGridRowStateView *rowState, s32 column)
{
    FclCombineGridRowStateView *cellState = (FclCombineGridRowStateView *)((u8 *)rowState + column);
    cellState->cellTransitionStarted[0] = 0;
}

/* Keep the grid's row snapshot separate from the outer traversal's header
   arithmetic. Both entry and refresh consume the same row/delay contract. */
/* Initialize or refresh a pair-grid row with staggered color and alpha transitions. */
static inline void fclAnimatePairGridRow(FclCombineRowWork *work, s64 renderedRow, s32 gridOffset, s32 mode)
{
    extern void fclSpriteSetAppearance(u8 *, FclVec2, FclDrawColor, f32, f32, f32);
    FclDrawColor initialCellColor;
    FclDrawColor initialFadeStartColor;
    FclDrawColor initialFadeEndColor;
    FclDrawColor refreshCellColor;
    FclDrawColor refreshFadeStartColor;
    FclDrawColor refreshFadeEndColor;
    FclVec2 initialCellPosition;
    FclVec2 refreshCellPosition;
    FclCombineGridRowStateView *initialRowState;
    s32 columnIndex;
    s32 rowIndex = (s32)renderedRow;
    if (mode == 0) {
        s16 column = 0;
        s32 rowY;
        FclCombineGridRowTaskView *rowTasks;
        rowY = gridOffset + 0x7F;
        rowTasks = (FclCombineGridRowTaskView *)((u8 *)work + rowIndex * 4);
        initialRowState = (FclCombineGridRowStateView *)((u8 *)work + rowIndex * 12);
        while (column < (u16)datPersonaRosterCapacity()) {
            u8 *cellElement;

            columnIndex = column;
            cellElement = fclCombineSlotRecord(rowTasks->cellListTask, (s8)column);
            initialCellPosition = fclMakeVec2((f32)(columnIndex * 23 + 0x149), (f32)rowY);
            initialCellColor = fclMakeDrawColor(0, 0, 0x99, 0xA5);
            fclSpriteSetAppearance(cellElement, initialCellPosition, initialCellColor, 1.0f, 0.0f, 159.0f);
            {
                s32 delay = (s16)column + rowIndex;
                u8 *colorElement = fclCombineSlotRecord(rowTasks->cellListTask, (s8)column);
                initialFadeStartColor = fclMakeDrawColor(0, 0, 0x99, 0xFF);
                initialFadeEndColor = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                fclSpriteStartColor(colorElement, initialFadeStartColor, initialFadeEndColor, 0, 0xA, delay);
                fclSpriteStartAlpha(fclCombineSlotRecord(rowTasks->cellListTask, (s8)column), 0, 0xA5, 0, 0xA, delay);
            }
            fclClearGridCellTransition(initialRowState, columnIndex);
            column++;
        }
    } else {
        s16 column = 0;
        s32 rowY = gridOffset + 0x7F;
        FclCombineGridRowTaskView *rowTasks = (FclCombineGridRowTaskView *)((u8 *)work + rowIndex * 4);
        FclCombineGridRowStateView *refreshRowState = (FclCombineGridRowStateView *)((u8 *)work + rowIndex * 12);
        while (column < (u16)datPersonaRosterCapacity()) {
            u8 *cellElement;

            columnIndex = column;
            cellElement = fclCombineSlotRecord(rowTasks->cellListTask, (s8)column);
            refreshCellPosition = fclMakeVec2((f32)(columnIndex * 23 + 0x149), (f32)rowY);
            refreshCellColor = fclMakeDrawColor(0, 0, 0x99, 0xA5);
            fclSpriteSetAppearance(cellElement, refreshCellPosition, refreshCellColor, 1.0f, 0.0f, 159.0f);
            {
                u8 *colorElement = fclCombineSlotRecord(rowTasks->cellListTask, (s8)column);
                refreshFadeStartColor = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xA5);
                refreshFadeEndColor = fclMakeDrawColor(0, 0, 0x99, 0xA5);
                fclSpriteStartColor(colorElement, refreshFadeStartColor, refreshFadeEndColor,
                              0, 0xA, (s16)column + rowIndex);
                fclSpriteStartAlpha(fclCombineSlotRecord(rowTasks->cellListTask, (s8)column), 0, 0xA5, 0, 0xA, 0);
            }
            fclClearGridCellTransition(refreshRowState, columnIndex);
            column++;
        }
    }
}

/* Set up the pair-fusion grid, column headers, and staged cell fades.
   Zero entryMode rebuilds pair availability and fades dark cells to blue;
   nonzero entryMode keeps the availability data and reverses that fade.
   Descriptive names below are recovered roles, not original Atlus symbols. */
// FUN_00320B80
void fclCombineSetupPairGrid(u8 *task, s8 entryMode) {
    extern void yListBuildAvailability(s32, s32);
    FclDrawColor columnSpriteColor;
    FclDrawColor columnHeaderStartColor;
    FclDrawColor columnHeaderEndColor;
    FclVec2 titlePosition;
    FclVec2 personaRowPosition;
    FclVec2 columnSpritePosition;
    FclVec2 columnSlideStart;
    FclVec2 columnSlideEnd;
    FclVec2 columnHeaderPosition;
    FclCombineRowWork *work;
    s16 row;
    s32 listCountByte;
    s32 savedMode;
    s32 gridMode;

    /* Phase 1: reset selection and, on initial entry, pair availability.
       Test the promoted entry value. The traversal takes its own mode
       snapshot after the title is set up. */
    work = ((FclCombineRowTask *)task)->work;
    work->cursorRow = 0;
    work->firstSelectedRow = -1;
    savedMode = entryMode;
    if (!savedMode) {
        yListBuildAvailability(0, 0);
    }

    /* Phase 2: title, followed by one Persona row and column header per slot. */
    titlePosition = fclMakeVec2(16.0f, 104.0f);
    fclCombineDrawSlotFields((*(u8 * const *)(&task)), titlePosition, 0, 0, 0, 0, 0);
    for (row = 0, gridMode = savedMode; row < (u16)datPersonaRosterCapacity(); row++) {
        s32 rowIndex;
        s32 gridOffset;
        s32 personaId;
        rowIndex = row;
        personaRowPosition = fclMakeVec2(16.0f, 128.0f);
        personaId = ((FclCombinePersonaHeader *)yListSlotEntry(0, row))->personaId;
        /* Retail looks up the entry twice and reads the count as a signed byte; the delay converts
         * row to s16 again. */
        fclCombinePartyRow(task, personaRowPosition, (s8)row, personaId, ((FclCombinePersonaHeader *)yListSlotEntry(0, row))->level, (s16)(row * 2), 0, (listCountByte = *(s8 *)&((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
        {
            s16 columnSprite = rowIndex + 0x25E;
            u8 *columnResource = (u8 *)sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
            s32 columnSpriteX;
            gridOffset = rowIndex * 23;
            columnSpriteX = gridOffset + 0x14E;
            columnSpritePosition = fclMakeVec2((f32)columnSpriteX, 110.0f);
            fclSpriteCreate((s16)(columnSprite), columnSpritePosition, 158.0f, 0x56);
            columnSpriteColor = fclMakeDrawColor(0x8C, 0xE2, 0xFF, 0xFF);
            {
                FclCombineRowSprite *sprite = (FclCombineRowSprite *)fclSpriteEntry(columnSprite);
                sprite->color = columnSpriteColor;
            }
            fclSpriteStartAlphaAt(columnSprite, 0, 0xFF, 0, 2, rowIndex);
            fclSpriteStartRevealScaleAt(columnSprite, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 2, rowIndex);
            columnSlideStart = fclMakeVec2((f32)columnSpriteX, 110.0f + sdkSpriteScaledHeight(columnResource) / 2.0f);
            columnSlideEnd = fclMakeVec2((f32)columnSpriteX, 110.0f);
            fclSpriteStartPositionAt(columnSprite, columnSlideStart, columnSlideEnd, 0, 2, rowIndex);
            sdkSpriteFreeNode(columnResource);
        }
        {
            u8 *columnHeaderElement = fclCombineSlotRecord(work->gridColumnHeaderTask, (s8)row);
            columnHeaderPosition = fclMakeVec2((f32)(gridOffset + 0x149), 104.0f);
            columnHeaderStartColor = fclMakeDrawColor(0, 0, 0x99, 0xFF);
            columnHeaderEndColor = fclMakeDrawColor(0, 0, 0x99, 0xFF);
            fclSpriteStartEntrance(columnHeaderElement, columnHeaderPosition,
                          columnHeaderStartColor, columnHeaderEndColor,
                          0xFF, 0xFF, 32.0f, 159.0f, 2, rowIndex, 0, 0);
        }

        /* Animate this grid row and clear its transition-state bytes. */
        fclAnimatePairGridRow(work, row, gridOffset, gridMode);
    }
}

/* Sets the pair grid cell colours (mode 1 swaps the two cell colours), writes nextState into the
 * task state byte, and draws row labels with the selected row dark. */
// FUN_003212E0
void fclCombineAdvanceGridFade(u8 *task, u8 nextState, s8 mode) {
    /* Row and cell state are walked with byte-biased pointers into separate parallel tables rather
     * than through typed row-task members. */
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    u8 *lastCellState;
    u8 *rowState;
    f32 interpolatedAlpha;
    f32 elapsedOrTextY;
    f32 duration;
    u8 alpha;
    s32 textColor;
    s16 lastCellIndex;
    s16 i;
    s32 j;
    u8 *work;
    u8 *rowTasks;
    u8 *cellTransition;
    u8 *lastRowTasks;
    u8 *cell2;
    s32 rowOffset;
    work = ((struct KwlnTask *)task)->work;
    lastCellIndex = (s64)(s16)(((u16)datPersonaRosterCapacity() - 1) + (((u16)datPersonaRosterCapacity() - 1) * 0xC));
    datPersonaRosterCapacity();
    datPersonaRosterCapacity();
    fclConstructColor(&drawColor1, 0, 0, 0x99, 0xFF);
    fclConstructColor(&drawColor2, 0x49, 0x72, 0xFF, 0xFF);
    fclConstructColor(&drawColor3, 0x49, 0x72, 0xFF, 0xFF);
    if (mode == 1) {
        drawColor2 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
        drawColor1 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        drawColor3 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        lastCellIndex = 0;
    }
    i = 0;
    lastCellState = work + (s16)lastCellIndex;
    for (; (s16)i < (s32)(u16)datPersonaRosterCapacity(); ++i) {
        j = 0;
        rowOffset = (s32)(s16)i * 0xC;
        rowState = work + rowOffset;
        rowTasks = work + ((s32)(s16)i * 4);
        for (; (s16)j < (s32)(u16)datPersonaRosterCapacity(); j = (s16)(j + 1)) {
            cellTransition = rowState + (s32)(s16)j + 0x18C;
            if (*(s8 *)cellTransition == 0) {
                if (((*(s16 *)fclCombineSlotRecord(((FclCombineRowWork *)rowTasks)->gridRowTasks[0], j) & 0x200) >> 9) == 0) {
                    fclSpriteStartColor(fclCombineSlotRecord(MEMBER(u8 *, rowTasks, FclCombineRowWork, gridRowTasks[0]), j), drawColor2, drawColor1, 0, 2, 1);
                    if (((FclCombineRowList *)((u8 *)(((u32)yListSlotWork(0)) + (rowOffset)) + (s32)(s16)j))->availability[0][0] > 0) {
                        fclSpriteStartColor(fclCombineSlotRecord(MEMBER(u8 *, rowTasks, FclCombineRowWork, gridRowTasks[0]), j), drawColor2, drawColor3, 0, 2, 1);
                        cell2 = fclCombineSlotRecord(MEMBER(u8 *, rowTasks, FclCombineRowWork, gridRowTasks[0]), j);
                        fclSpriteStartAlpha(cell2, ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowTasks, FclCombineRowWork, gridRowTasks[0]), j) - 4))->alpha, 0xCC, 0, 2, 1);
                    }
                    *(s8 *)cellTransition = 1;
                }
            } else if ((((FclCombineRowWork *)lastCellState)->cellTransitionStarted[0][0] == 1) && ((s16)lastCellIndex == ((s16)j + rowOffset))) {
                lastRowTasks = work + ((u16)datPersonaRosterCapacity() * 4);
                if (((*(s16 *)fclCombineSlotRecord(((FclCombineRowWork *)lastRowTasks)->gridRowTasks[-1], (u16)datPersonaRosterCapacity() - 1) & 0x200) >> 9) == 0) {
                    ((FclCombineWork *)work)->f1 = nextState;
                    if (((FclCombineRowWork *)work)->firstSelectedRow == -1) {
                        ((FclCombineRowWork *)work)->cursorRow = 0;
                    }
                }
            }
        }
        {
            s64 renderedRow = (s16)i;
            s32 rowResource = (s32)renderedRow + 0x21C;
            elapsedOrTextY = (f32)(s32)((FclCombineRowSprite *)(u8 *)fclSpriteEntry((s16)rowResource))->positionElapsed;
            duration = (f32)(s32)((FclCombineRowSprite *)(u8 *)fclSpriteEntry((s16)rowResource))->positionDuration;
            interpolatedAlpha = fclEaseInterpolate(0, 0.0f, 255.0f, elapsedOrTextY, duration);
            textColor = (u8)interpolatedAlpha;
            alpha = textColor & 0xFF;
            if (((FclCombineRowWork *)(u8 *)work)->cursorRow == renderedRow) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, alpha);
            } else {
                textColor = fclPackRgba(0xCC, 0xFF, 0xFF, alpha);
            }
            if ((s16)i < ((FclCombinePersonaListHeader *)(u8 *)yListSlotWork(0))->count) {
                elapsedOrTextY = (f32)(s32)((s16)i * 0x17 + 0x80);
                frFontExDrawTextDeferredOutB(113.0f, elapsedOrTextY, 43.0f, textColor, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(((FclCombinePersonaHeader *)(u8 *)yListSlotEntry(0, i))->personaId) * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
    }
}
/* Loop-invariant hoisting spills the inner-loop row offset as retail does; both loop counters are
 * zeroed before the statements that follow them. */
#pragma push
/* measured: retail hoists and spills the inner-loop row offset, which needs loop-invariant
 * optimization on. */
#pragma opt_loop_invariants on
// Fcl combine grid cell refresh: for each roster row, redraws the row's cells with colours taken from the selected row (0x11E) and the availability counts, and resets the row sprite and its column header at the given order.
// FUN_003218A0
void fclCombineRefreshGridCells(u8 *task, s16 delay) {
    extern void fclSpriteStartPositionAt(s16, FclVec2, FclVec2, u32, u32, s16);
    extern void fclSpriteStartAlphaAt(s16, u8, u8, u8, s32, s16);
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    u8 *work;
    u8 *e;
    u8 *h;
    s16 order;
    s16 i;
    s16 j;
    s16 res;
    s32 r;
    s32 x;
    s32 xx;
    s32 row;
    s32 y;
    u8 *p;

    work = ((struct KwlnTask *)task)->work;
    i = 0;
    order = delay;
    for (; i < (u16)datPersonaRosterCapacity(); i++) {
        x = i * 23;
        e = fclCombineSlotRecord(((FclCombineRowWork *)work)->gridColumnHeaderTask, i);
        fclSpriteStartEntrance(e, fclMakeVec2(x + 0x149, 104.0f),
                      drawColor1 = fclMakeDrawColor(0, 0, 0x99, 0xFF), drawColor2 = fclMakeDrawColor(0, 0, 0x99, 0xFF),
                      0xFF, 0xFF, 32.0f, 159.0f, 2, order, 0, 0);
        r = i + 0x25E;
        res = r;
        h = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
        fclSpriteStartAlphaAt(res, 0, 0xFF, 0, 0, order + 3);
        fclSpriteStartRevealScaleAt(res, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, delay);
        xx = x + 0x14E;
        fclSpriteStartPositionAt(r, fclMakeVec2(xx, 110.0f + sdkSpriteScaledHeight(h) / 2.0f), fclMakeVec2(xx, 110.0f), 0, 3, delay);
        fclSpriteSetFlag(res, 0, 0);
        sdkSpriteFreeNode(h);
        j = 0;
        p = work + i * 4;
        row = i * 12;
        y = x + 0x7F;
        for (; j < (u16)datPersonaRosterCapacity(); j++) {
            if (((FclCombineRowWork *)work)->cursorRow == i) {
                drawColor3 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                ((FclObject *)((u8 *)fclCombineSlotRecord(((FclCombineRowWork *)p)->gridRowTasks[0], j) - 4))->color = drawColor3;
                if (((s8 *)yListSlotWork(0))[row + j + 0x14] > 0) {
                    drawColor4 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                    ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), j) - 4))->color = drawColor4;
                }
            } else {
                drawColor5 = fclMakeDrawColor(0, 0, 0x99, 0xA5);
                ((FclObject *)((u8 *)fclCombineSlotRecord(((FclCombineRowWork *)p)->gridRowTasks[0], j) - 4))->color = drawColor5;
                if (((s8 *)yListSlotWork(0))[row + j + 0x14] > 0) {
                    drawColor6 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xCC);
                    ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), j) - 4))->color = drawColor6;
                }
            }
            fclSpriteStartEntrance(fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), j),
                          fclMakeVec2(j * 23 + 0x149, y),
                          ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), j) - 4))->color,
                          ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), j) - 4))->color,
                          ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), j) - 4))->color.c3,
                          ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), j) - 4))->color.c3,
                          32.0f,
                          ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), j) - 4))->anchorValue,
                          3, order, 0, 0);
        }
    }
}
#pragma pop

/* The 0x40 path has its own eligibility guard; it is not a copy of 0x80.
   Cursor activation and the 0x7E reset follow the retail control-flow join. */
/* Create the combination cursor arrow and hide the two work-owned arrows. */
static inline void fclShowCombineCursorArrows(u8 *work)
{
    FclVec2 *v = (FclVec2 *)D_00644C90;
    f32 dx = 60.0f;

    fclSpriteCreate(0x1E4, fclMakeVec2(v->x + dx, v->y), 103.0f, 0xBC);
    fclSpriteStartAlphaAt(0x1E4, 0, 0xFF, 0, 0xA, 0);
    fclSpriteStartTweenAt(0x1E4, 0, 0, 0, 0.0f, 90.0f);
    fclSpriteSetHidden(((FclCombineWork *)work)->f28C, 1);
    fclSpriteSetHidden(((FclCombineWork *)work)->f290, 1);
}

/* Handle grid navigation and transitions: confirm enters selectedState, cancel enters cancelState,
 * and mode selects the card path. */
// FUN_00321E60
void fclCombineHandleGridInput(u8 *task, s64 mode, u8 selectedState, u8 cancelState) {
    extern u16 D_008C027A[];
    extern u16 D_008C024E[];
    extern u16 D_008C024C[];
    extern f32 D_00644150[];
    extern void fclCombineFuseSourceRecords(u16 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, s32, s8, s8);
    extern void yListBuildAvailability(s32, s32);
    extern s32 sdkSndStartStream(s16, s16, s16, s16);
    FclDrawColor drawColor1;
    u8 *work;
    FclVec2 *v;
    s16 i;
    s16 j;
    s16 k;
    s32 m;
    s32 x;
    s32 acc;
    s8 c;
    s32 rowCount;
    u8 alpha;
    u8 *p;
    u8 *row;
    u8 *h;
    s16 ka;
    u8 *ha;
    s16 ia;
    s16 ja;
    s32 ma;
    u8 *rowa;
    u8 *pa;
    s32 xa;
    s32 acca;
    s16 jb1;
    s16 kb1;
    s32 mb1;
    u8 *rowb1;
    u8 *pb1;
    u8 *hb1;
    s32 xb1;
    s32 accb1;
    s16 jb2;
    s16 kb2;
    u8 *rowb2;
    s16 jc;
    s16 kc;
    u8 *rowc;
    u8 *hc;
    s32 xc;

    work = ((struct KwlnTask *)task)->work;
    ((FclCombineRowWork *)work)->firstSelectedRow = -1;
    ((FclCombineRowWork *)work)->secondSelectedRow = -1;
    i = 0;
    while ((s16)i < (u16)datPersonaRosterCapacity()) {
        fclCombineSelectSlotEntry(task, (s8)i, MEMBER(s8, work, FclCombineRowWork, firstSelectedRow), MEMBER(s8, work, FclCombineRowWork, secondSelectedRow), mode);
        ++i;
    }
    if (D_008C027A[0] & 0x1000) {
        ((FclCombineRowWork *)work)->cursorRow = fclSubClamped(MEMBER(s16, work, FclCombineRowWork, cursorRow), 1, 0, (u16)datPersonaRosterCapacity() - 1, 2);
        sdkSndStartStream(0, 0, 0, 0);
        return;
    }
    if (D_008C027A[0] & 0x4000) {
        ((FclCombineRowWork *)work)->cursorRow = fclAddClamped(MEMBER(s16, work, FclCombineRowWork, cursorRow), 1, (u16)datPersonaRosterCapacity() - 1, 0, 2);
        sdkSndStartStream(0, 0, 0, 0);
        return;
    }
    if (D_008C024E[0] & 0x80) {
        if (((FclCombineRowWork *)work)->cursorRow < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
            sdkSndStartStream(0, 1, 0, 3);
            ia = 0;
            while ((s16)ia < (u16)datPersonaRosterCapacity()) {
                fclCombinePartyRow(task, fclMakeVec2(16.0f, 128.0f), (s8)ia, ((FclCombinePersonaHeader *)yListSlotEntry(0, ia))->personaId, ((FclCombinePersonaHeader *)yListSlotEntry(0, ia))->level, 0, 1, (rowCount = *(s8*)&((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                ++ia;
            }
            fclCombineDrawSlotFields(task, fclMakeVec2(16.0f, 104.0f), 0, 1, 0, 0, 0);
            fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
            ja = 0;
            while ((s16)ja < (u16)datPersonaRosterCapacity()) {
                ma = ja * 23;
                pa = fclCombineSlotRecord(((FclCombineRowWork *)work)->gridColumnHeaderTask, (s8)ja);
                fclSpriteStartEntrance(pa, fclMakeVec2((f32)(ma + 0x149), 104.0f), fclMakeDrawColor(0, 0, 0x99, 0xFF),
                              fclMakeDrawColor(0, 0, 0x99, 0xFF), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
                ka = 0;
                rowa = work + ja * 4;
                acca = ma + 0x7F;
                while ((s16)ka < (u16)datPersonaRosterCapacity()) {
                    fclSpriteStartEntrance(fclCombineSlotRecord(((FclCombineRowWork *)rowa)->gridRowTasks[0], (s8)ka),
                                  fclMakeVec2((f32)(ka * 23 + 0x149), (f32)acca),
                                  ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowa, FclCombineRowWork, gridRowTasks[0]), (s8)ka) - 4))->color,
                                  ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowa, FclCombineRowWork, gridRowTasks[0]), (s8)ka) - 4))->color,
                                  ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowa, FclCombineRowWork, gridRowTasks[0]), (s8)ka) - 4))->alpha,
                                  ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowa, FclCombineRowWork, gridRowTasks[0]), (s8)ka) - 4))->alpha,
                                  32.0f, ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowa, FclCombineRowWork, gridRowTasks[0]), (s8)ka) - 4))->anchorValue, 3, 0, 1, 0);
                    ++ka;
                }
                {
                    s16 normalizedRow = ja;
                    s16 resource = (s16)((u32)normalizedRow + 0x25E);
                    ha = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
                    fclSpriteStartAlphaAt(resource, 0xFF, 0, 0, 3, 0);
                    fclSpriteStartRevealScaleAt(resource, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                    xa = (u32)normalizedRow * 23 + 0x14E;
                    fclSpriteStartPositionAt(resource, fclMakeVec2((f32)xa, 110.0f),
                                  fclMakeVec2((f32)xa, 110.0f + sdkSpriteScaledHeight(ha) / 2.0f), 0, 3, 0);
                    sdkSpriteFreeNode(ha);
                }
                ++ja;
            }
            fclShowCombineCursorArrows(work);
            if ((s8)mode == 0) {
                ((FclCombineWork *)work)->f1 = 0x28;
            } else {
                ((FclCombineWork *)work)->f1 = 0x3E;
            }
        }
    } else if (D_008C024C[0] & 0x40) {
        if (((FclCombineRowWork *)work)->cursorRow < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
            sdkSndStartStream(0, 0, 0, 1);
            MEMBER(s8, work, FclCombineRowWork, firstSelectedRow) = MEMBER(s16, work, FclCombineRowWork, cursorRow);
            v = (FclVec2 *)D_00644150;
            fclCombineDrawPersonaCard(task, MEMBER(s16, work, FclCombineRowWork, cursorRow), fclMakeVec2(-380.0f, v->y), fclMakeVec2(v->x, v->y));
            if ((s8)mode == 0) {
                jb1 = 0;
                while ((s16)jb1 < (u16)datPersonaRosterCapacity()) {
                    fclCombineDrawPersonaRow(task, fclMakeVec2((f32)0x149, 128.0f), MEMBER(s8, work, FclCombineRowWork, firstSelectedRow), (s8)jb1, ((FclCombinePersonaHeader *)yListSlotEntry(MEMBER(s8, work, FclCombineRowWork, firstSelectedRow) + 1, jb1))->personaId, ((FclCombinePersonaHeader *)yListSlotEntry(MEMBER(s8, work, FclCombineRowWork, firstSelectedRow) + 1, jb1))->level, 3, 0, 1, 0xCC);
                    mb1 = jb1 * 23;
                    pb1 = fclCombineSlotRecord(((FclCombineRowWork *)work)->gridColumnHeaderTask, (s8)jb1);
                    fclSpriteStartEntrance(pb1, fclMakeVec2((f32)(mb1 + 0x149), 104.0f), fclMakeDrawColor(0, 0, 0x99, 0xFF),
                                  fclMakeDrawColor(0, 0, 0x99, 0xFF), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
                    kb1 = 0;
                    rowb1 = work + jb1 * 4;
                    accb1 = mb1 + 0x7F;
                    while ((s16)kb1 < (u16)datPersonaRosterCapacity()) {
                        fclSpriteStartEntrance(fclCombineSlotRecord(((FclCombineRowWork *)rowb1)->gridRowTasks[0], (s8)kb1),
                                      fclMakeVec2((f32)(kb1 * 23 + 0x149), (f32)accb1),
                                      ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowb1, FclCombineRowWork, gridRowTasks[0]), (s8)kb1) - 4))->color,
                                      ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowb1, FclCombineRowWork, gridRowTasks[0]), (s8)kb1) - 4))->color,
                                      ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowb1, FclCombineRowWork, gridRowTasks[0]), (s8)kb1) - 4))->alpha,
                                      ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowb1, FclCombineRowWork, gridRowTasks[0]), (s8)kb1) - 4))->alpha,
                                      32.0f, ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowb1, FclCombineRowWork, gridRowTasks[0]), (s8)kb1) - 4))->anchorValue, 3, 0, 1, 0);
                        ++kb1;
                    }
                    {
                        s16 normalizedRow = jb1;
                        s16 resource = (s16)((u32)normalizedRow + 0x25E);
                        hb1 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
                        fclSpriteStartAlphaAt(resource, 0xFF, 0, 0, 3, 0);
                        fclSpriteStartRevealScaleAt(resource, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        xb1 = (u32)normalizedRow * 23 + 0x14E;
                        fclSpriteStartPositionAt(resource, fclMakeVec2((f32)xb1, 110.0f),
                                      fclMakeVec2((f32)xb1, 110.0f + sdkSpriteScaledHeight(hb1) / 2.0f), 0, 3, 0);
                        sdkSpriteFreeNode(hb1);
                        c = MEMBER(s8, work, FclCombineRowWork, firstSelectedRow);
                        if (((FclCombineRowList *)(yListSlotWork(0) + c * 12 + (u32)normalizedRow))->availability[0][0] > 0) {
                            fclCombineFuseSourceRecords((u16 *)yListSlotEntry(MEMBER(s8, work, FclCombineRowWork, firstSelectedRow) + 1, jb1),
                                                        yListSlotEntry(0, MEMBER(s8, work, FclCombineRowWork, firstSelectedRow)),
                                                        yListSlotEntry(0, jb1), 0, 0, 0, 0, 2, (s8)(c + 1), (s8)jb1);
                        }
                    }
                    ++jb1;
                }
                fclCombineDrawSlotLabels(task, fclMakeVec2((f32)0x149, 104.0f), 3, 0);
                fclCombineSlideInSlotSprites(task, 0x94, 0x93);
                fclSpriteSetFlag(0x1C7, 2, 1);
                fclCombineFlashSlot(task, (s32)MEMBER(s8, work, FclCombineRowWork, firstSelectedRow));
            } else {
                yListBuildAvailability(1, MEMBER(s8, work, FclCombineRowWork, firstSelectedRow));
                fclSpriteStartAlphaAt(0x7E, 0xFF, 0, 0, 6, 0);
                ((FclCombineRowSprite *)fclSpriteEntry(0x7E))->positionReverse = 0;
                jb2 = 0;
                while ((s16)jb2 < (u16)datPersonaRosterCapacity()) {
                    s16 cur;

                    kb2 = 0;
                    cur = (s16)(u32)jb2;
                    m = cur * 12;
                    rowb2 = work + cur * 4;
                    while ((s16)kb2 < (u16)datPersonaRosterCapacity()) {
                        if (((FclCombineRowList *)((u8 *)(((u32)yListSlotWork(0)) + (m)) + kb2))->availability[0][0] == 0) {
                            if (MEMBER(s16, work, FclCombineRowWork, cursorRow) == cur) {
                                drawColor1 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                            } else {
                                drawColor1 = fclMakeDrawColor(0, 0, 0x99, 0xA5);
                            }
                            alpha = drawColor1.c3;
                            fclSpriteStartEntrance(fclCombineSlotRecord(((FclCombineRowWork *)rowb2)->gridRowTasks[0], (s8)kb2),
                                          ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowb2, FclCombineRowWork, gridRowTasks[0]), (s8)kb2) - 4))->anchorPosition,
                                          fclMakeDrawColor(0, 0, 0x99, 0xA5), drawColor1, alpha, alpha,
                                          32.0f, ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowb2, FclCombineRowWork, gridRowTasks[0]), (s8)kb2) - 4))->anchorValue, 6, 0, 1, 1);
                        } else {
                            if (MEMBER(s16, work, FclCombineRowWork, cursorRow) == cur) {
                                drawColor1 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                            } else {
                                drawColor1 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xCC);
                            }
                            alpha = drawColor1.c3;
                            fclSpriteStartEntrance(fclCombineSlotRecord(((FclCombineRowWork *)rowb2)->gridRowTasks[0], (s8)kb2),
                                          ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowb2, FclCombineRowWork, gridRowTasks[0]), (s8)kb2) - 4))->anchorPosition,
                                          fclMakeDrawColor(0, 0, 0x99, 0xCC), drawColor1, alpha, alpha,
                                          32.0f, ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowb2, FclCombineRowWork, gridRowTasks[0]), (s8)kb2) - 4))->anchorValue, 6, 0, 1, 1);
                        }
                        ++kb2;
                    }
                    ++jb2;
                }
                fclCombineSlideInSlotSprites(task, 0x94, 0x93);
                fclCombineFlashSlot(task, (s32)MEMBER(s8, work, FclCombineRowWork, firstSelectedRow));
            }
            ((FclCombineWork *)work)->f1 = selectedState;
        }
    } else if (D_008C024E[0] & 0x20) {
        sdkSndStartStream(0, 0, 0, 2);
        datPersonaRosterCapacity();
        fclCombineDrawSlotFields(task, fclMakeVec2(16.0f, 104.0f), 0, 1, 0, 0, 0);
        jc = 0;
        while ((s16)jc < (u16)datPersonaRosterCapacity()) {
            fclCombinePartyRow(task, fclMakeVec2(16.0f, 128.0f), (s8)jc, ((FclCombinePersonaHeader *)yListSlotEntry(0, jc))->personaId, ((FclCombinePersonaHeader *)yListSlotEntry(0, jc))->level, 0, 1, (rowCount = *(s8*)&((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
            m = jc * 23;
            fclSpriteStartEntrance(fclCombineSlotRecord(((FclCombineRowWork *)work)->gridColumnHeaderTask, (s8)jc), fclMakeVec2((f32)(m + 0x149), 104.0f), fclMakeDrawColor(0, 0, 0x99, 0xFF),
                          fclMakeDrawColor(0, 0, 0x99, 0xFF), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
            kc = 0;
            rowc = work + jc * 4;
            while ((s16)kc < (u16)datPersonaRosterCapacity()) {
                fclSpriteStartEntrance(fclCombineSlotRecord(((FclCombineRowWork *)rowc)->gridRowTasks[0], (s8)kc),
                              ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowc, FclCombineRowWork, gridRowTasks[0]), (s8)kc) - 4))->anchorPosition,
                              ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowc, FclCombineRowWork, gridRowTasks[0]), (s8)kc) - 4))->color,
                              ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowc, FclCombineRowWork, gridRowTasks[0]), (s8)kc) - 4))->color,
                              ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowc, FclCombineRowWork, gridRowTasks[0]), (s8)kc) - 4))->alpha,
                              ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowc, FclCombineRowWork, gridRowTasks[0]), (s8)kc) - 4))->alpha,
                              32.0f, ((FclObject *)((u8 *)fclCombineSlotRecord(MEMBER(u8 *, rowc, FclCombineRowWork, gridRowTasks[0]), (s8)kc) - 4))->anchorValue, 3, 0, 1, 0);
                ++kc;
            }
            {
                s16 normalizedRow = jc;
                s16 resource = (s16)((u32)normalizedRow + 0x25E);
                hc = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
                fclSpriteStartAlphaAt(resource, 0xFF, 0, 0, 3, 0);
                fclSpriteStartRevealScaleAt(resource, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                xc = (u32)normalizedRow * 23 + 0x14E;
                fclSpriteStartPositionAt(resource, fclMakeVec2((f32)xc, 110.0f),
                              fclMakeVec2((f32)xc, 110.0f + sdkSpriteScaledHeight(hc) / 2.0f), 0, 3, 0);
                sdkSpriteFreeNode(hc);
            }
            ++jc;
        }
        if ((s8)mode == 1) {
            fclSpriteStartAlphaAt(0x7E, 0xFF, 0, 0, 0xA, 0);
            fclSpriteSetFlag(0x7E, 0, 0);
        }
        fclCombineLayoutFrame(task, 1, 1);
        fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
        ((FclCombineWork *)work)->f1 = cancelState;
    }
}


// Fcl combine roster selection refresh: for each roster row, refreshes the slot entry, then colours
// the selected row's sprites (selection flags and the 0x2A3 highlight) or the other rows' sprites.
// Rows whose availability count is 2 get their entries flagged.
// FUN_003233D0
void fclCombineRefreshRosterSelection(u8 *task) {
    typedef union { FclDrawColor channels; u32 word; } PackedColor;
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    PackedColor packedColor1;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    PackedColor packedColor2;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    PackedColor packedColor3;
    s16 i;
    u8 *work;
    u8 *p;
    work = ((struct KwlnTask *)task)->work;
    for (i = 0; (s16)i < (u16)datPersonaRosterCapacity(); ++i) {
        fclCombineSelectSlotEntry(task, (s8)i, ((FclCombineRowWork *)work)->firstSelectedRow, ((FclCombineRowWork *)work)->secondSelectedRow, 0);
        if ((s16)i < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
            if ((s16)i == ((FclCombineRowWork *)work)->cursorRow) {
                u8 *p297;
                u8 *p28B;
                u8 *p27D;
                ((FclCombineRowSprite *)fclSpriteEntry((s16)((s16)i + 0x270)))->alpha =
                    ((FclCombineRowSprite *)fclSpriteEntry((s16)((s16)i + 0x27D)))->alpha = 0xFF;
                drawColor1 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                p297 = fclSpriteEntry((s16)((s16)i + 0x297));
                ((FclCombineRowSprite *)p297)->color = drawColor1;
                p28B = fclSpriteEntry((s16)((s16)i + 0x28B));
                ((FclCombineRowSprite *)p28B)->color = MEMBER(FclDrawColor, p297, FclCombineRowSprite, color);
                p27D = fclSpriteEntry((s16)((s16)i + 0x27D));
                ((FclCombineRowSprite *)p27D)->color = MEMBER(FclDrawColor, p28B, FclCombineRowSprite, color);
                p = fclSpriteEntry((s16)((s16)i + 0x270));
                ((FclCombineRowSprite *)p)->color = MEMBER(FclDrawColor, p27D, FclCombineRowSprite, color);
                drawColor2 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                p = fclSpriteEntry((s16)((s16)i + 0x2A3));
                ((FclCombineRowSprite *)p)->color = drawColor2;
                packedColor1.channels = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                nmMesWindowSetNumberColor(((FclCombineRowWork *)work)->digitTask, (s16)((s16)i + 0xC), packedColor1.channels);
                fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF);
                if (((FclCombineRowList *)(yListSlotWork(0) + MEMBER(s8, work, FclCombineRowWork, secondSelectedRow) * 0xC + (s16)i))->availability[0][0] == 2) {
                    fclSpriteSetFlag(0xCF, 0, 1);
                    fclSpriteSetFlag(0xD2, 0, 1);
                    fclSpriteSetFlag((s16)((s16)i + 0x270), 0, 0);
                    fclSpriteSetFlag((s16)((s16)i + 0x27D), 0, 0);
                }
            } else if (((FclCombineRowList *)(yListSlotWork(0) + MEMBER(s8, work, FclCombineRowWork, secondSelectedRow) * 0xC + (s16)i))->availability[0][0] == 2) {
                u8 *p27D;
                ((FclCombineRowSprite *)fclSpriteEntry((s16)((s16)i + 0x270)))->alpha =
                    ((FclCombineRowSprite *)fclSpriteEntry((s16)((s16)i + 0x27D)))->alpha = 0;
                drawColor3 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
                p27D = fclSpriteEntry((s16)((s16)i + 0x27D));
                ((FclCombineRowSprite *)p27D)->color = drawColor3;
                p = fclSpriteEntry((s16)((s16)i + 0x270));
                ((FclCombineRowSprite *)p)->color = MEMBER(FclDrawColor, p27D, FclCombineRowSprite, color);
                drawColor4 = fclMakeDrawColor(0xFF, 0xCC, 0xFA, 0xFF);
                p = fclSpriteEntry((s16)((s16)i + 0x2A3));
                ((FclCombineRowSprite *)p)->color = drawColor4;
                packedColor2.channels = fclMakeDrawColor(0xFF, 0xCC, 0xFA, 0xFF);
                nmMesWindowSetNumberColor(((FclCombineRowWork *)work)->digitTask, (s16)((s16)i + 0xC), packedColor2.channels);
                fclPackRgba(0xFF, 0xCC, 0xFA, 0xFF);
                fclSpriteSetFlag(0xCF, 0, 0);
                fclSpriteSetFlag(0xD2, 0, 0);
            } else {
                u8 *p27D;
                u8 *p297;
                ((FclCombineRowSprite *)fclSpriteEntry((s16)((s16)i + 0x270)))->alpha =
                    ((FclCombineRowSprite *)fclSpriteEntry((s16)((s16)i + 0x27D)))->alpha = 0xCC;
                drawColor5 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                p27D = fclSpriteEntry((s16)((s16)i + 0x27D));
                ((FclCombineRowSprite *)p27D)->color = drawColor5;
                p = fclSpriteEntry((s16)((s16)i + 0x270));
                ((FclCombineRowSprite *)p)->color = MEMBER(FclDrawColor, p27D, FclCombineRowSprite, color);
                drawColor6 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                p297 = fclSpriteEntry((s16)((s16)i + 0x297));
                ((FclCombineRowSprite *)p297)->color = drawColor6;
                p = fclSpriteEntry((s16)((s16)i + 0x28B));
                ((FclCombineRowSprite *)p)->color = MEMBER(FclDrawColor, p297, FclCombineRowSprite, color);
                drawColor7 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
                p = fclSpriteEntry((s16)((s16)i + 0x2A3));
                ((FclCombineRowSprite *)p)->color = drawColor7;
                packedColor3.channels = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
                nmMesWindowSetNumberColor(((FclCombineRowWork *)work)->digitTask, (s16)((s16)i + 0xC), packedColor3.channels);
                fclPackRgba(0xCC, 0xFF, 0xFF, 0xFF);
            }
            if (MEMBER(s8, work, FclCombineRowWork, firstSelectedRow) != (s16)i && MEMBER(s8, work, FclCombineRowWork, secondSelectedRow) != (s16)i) {
                if (((FclCombineRowList *)(yListSlotWork((s8)(MEMBER(s8, work, FclCombineRowWork, secondSelectedRow) + 1)) + MEMBER(s8, work, FclCombineRowWork, secondSelectedRow) * 0xC + (s16)i))->availability[0][0] > 0) {
                    f32 elapsed = (f32)((FclCombineRowSprite *)fclSpriteEntry((s16)((s16)i + 0x270)))->positionElapsed;
                    s16 duration = ((FclCombineRowSprite *)fclSpriteEntry((s16)((s16)i + 0x270)))->positionDuration;
                    f32 f = fclEaseInterpolate(0, 0.0f, 255.0f, elapsed, (f32)duration);
                    u8 alpha;
                    s32 result;
                    alpha = (u8)f;
                    if (MEMBER(s16, work, FclCombineRowWork, cursorRow) == (s16)i) {
                        result = fclPackRgba(0x2D, 0x2D, 0x2D, alpha);
                    } else {
                        result = fclPackRgba(0xCC, 0xFF, 0xFF, alpha);
                        if (((FclCombineRowList *)(yListSlotWork(0) + MEMBER(s8, work, FclCombineRowWork, secondSelectedRow) * 0xC + (s16)i))->availability[0][0] == 2) {
                            result = fclPackRgba(0xFF, 0xCC, 0xFA, alpha);
                        }
                    }
                    frFontExDrawTextDeferredOutB(405.0f, (f32)((s16)i * 0x17 + 0x80), 43.0f, result, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(((FclCombinePersonaHeader *)yListSlotEntry((s8)(MEMBER(s8, work, FclCombineRowWork, secondSelectedRow) + 1), (s16)i))->personaId) * 0x11), 0, 0, D_00795E60, 0x15);
                }
            }
        }
    }
}

#pragma push
/* measured: with lifetime analysis on, the locals get different registers than retail uses. */
#pragma opt_lifetimes off
/* The hidden and shown locals are declared before res and passed through (s32) casts at every call
 * on purpose; retail's code is shaped by those repeated conversions. Draws both slot lists and side
 * panels with a per-row delayStep, and mode sets their entry/exit alpha. */
// FUN_00323D00
void fclCombineDrawSidePanels(u8 *task, s32 delayStep, s8 mode) {
    /* The count argument is specifically the signed low byte of the word-sized list count. */
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclPackedPosition positionPacket1;
    FclPackedPosition positionPacket2;
    FclPackedPosition positionPacket3;
    FclPackedPosition positionPacket4;
    FclPackedPosition positionPacket5;
    FclPackedPosition positionPacket6;
    FclPackedPosition positionPacket7;
    FclPackedPosition positionPacket8;
    FclPackedPosition positionPacket9;
    FclPackedPosition positionPacket10;
    s16 k;
    s32 count;
    FclVec2 *p;

    positionPacket1.position = fclMakeVec2(16.0f, 104.0f);
    fclCombineDrawSlotFields(task, positionPacket1.position, 0, mode, 0, 1, 2);
    positionPacket2.position = fclMakeVec2(313, 104.0f);
    fclCombineDrawSlotFields(task, positionPacket2.position, 0, mode, 1, 0, 0);
    for (k = 0; k < ((FclCombinePersonaListHeader *)yListSlotWork(1))->count; k++) {
        positionPacket3.position = fclMakeVec2(313, 128.0f);
        fclCombinePartyRow(task, positionPacket3.position, (s8)k, ((FclCombinePersonaHeader *)yListSlotEntry(1, k))->personaId, ((FclCombinePersonaHeader *)yListSlotEntry(1, k))->level, (s16)(k * delayStep), mode, (count = *(s8*)&((FclCombinePersonaListHeader *)yListSlotWork(1))->count));
    }
    for (k = 0; k < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count; k++) {
        positionPacket4.position = fclMakeVec2(16.0f, 128.0f);
        fclCombineDrawPersonaRow(task, positionPacket4.position, 0, (s8)k, ((FclCombinePersonaHeader *)yListSlotEntry(0, k))->personaId, ((FclCombinePersonaHeader *)yListSlotEntry(0, k))->level, (s16)(k * delayStep), mode, 1, 0xCC);
    }
    {
        s32 hidden;
        s32 shown;
        s16 res;
        p = (FclVec2 *)D_006440F8;
        positionPacket5.position = fclMakeVec2(p->x, p->y);
        fclSpriteCreate(0x71, positionPacket5.position, 138.0f, 0x41);
        drawColor1 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x71))->color = drawColor1;
        hidden = (1 - (s8)mode) * 0xFF;
        shown = (s8)mode * 0xFF;
        fclSpriteStartAlphaAt(0x71, (s32)shown, (s32)hidden, 0, 0, 0);
        p = (FclVec2 *)D_006440F0;
        positionPacket6.position = fclMakeVec2(p->x, p->y);
        fclSpriteCreate(0x70, positionPacket6.position, 139.0f, 0x41);
        drawColor2 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x70))->color = drawColor2;
        fclSpriteStartAlphaAt(0x70, (s32)shown, (s32)hidden, 0, 0, 0);
        for (k = 0; k < 2; k++) {
            p = (FclVec2 *)D_00644290;
            res = (s16)(k + 0x2BB);
            positionPacket7.position = fclMakeVec2(p->x + (f32)(k * 313), p->y);
            fclSpriteCreate(res, positionPacket7.position, 140.0f, 0x41);
            drawColor3 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(res))->color = drawColor3;
            fclSpriteStartAlphaAt(res, (s32)shown, (s32)hidden, 0, 0, 0);
            p = (FclVec2 *)D_00644298;
            res = (s16)(k + 0x2BD);
            positionPacket8.position = fclMakeVec2(p->x + (f32)(k * 330), p->y);
            fclSpriteCreate(res, positionPacket8.position, 141.0f, 0x41);
            drawColor4 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(res))->color = drawColor4;
            fclSpriteStartAlphaAt(res, (s32)shown, (s32)hidden, 0, 0, 0);
            p = (FclVec2 *)D_00644350;
            res = (s16)(k + 0x2BF);
            positionPacket9.position = fclMakeVec2(p->x + (f32)(k * 14), p->y);
            fclSpriteCreate(res, positionPacket9.position, 142.0f, 0x41);
            drawColor5 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(res))->color = drawColor5;
            fclSpriteStartAlphaAt(res, (s32)shown, (s32)hidden, 0, 0, 0);
        }
        p = (FclVec2 *)D_00644350;
        positionPacket10.position = fclMakeVec2(28.0f + p->x, p->y);
        fclSpriteCreate(0xBC, positionPacket10.position, 142.0f, 0x41);
        drawColor6 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0xBC))->color = drawColor6;
        fclSpriteStartAlphaAt(0xBC, (s32)shown, (s32)hidden, 0, 0, 0);
    }
}
#pragma pop

// FUN_00324410
void fclCombineStepSidePanel(u8 *task, s16 sprite, s8 side) {
    /* Cursor-state pointers add the side byte before the field offset. */
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    f32 shiftedY;
    f32 y;
    u8 *work;
    s32 sideIndex;
    extern void fclSpriteStartPositionAt(s16, FclVec2, FclVec2, u32, u32, s16);

    work = ((struct KwlnTask *)task)->work;
    drawPosition1 = ((FclCombineRowWork *)work)->cursorPosition;
    sideIndex = side;
    switch (((FclCombineWork *)((u8 *)(sideIndex + (s32)work)))->cursorStates[0]) {
    case 0:
        if ((s64)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(sprite))->flags, 2) == 1) { break; }
        fclSpriteReset(sprite, 0x1C7);
        fclSpriteSetFlag(sprite, 0, 0);
        if (sideIndex == 0) {
            drawPosition2 = fclMakeVec2(280.0f + drawPosition1.x, drawPosition1.y);
            fclSpriteStartPositionAt(sprite, drawPosition1, drawPosition2, 0, 0x32, 0);
        } else if (sideIndex == 1) {
            shiftedY = 20.0f + ((y = drawPosition1.y), y);
            drawPosition3 = fclMakeVec2(280.0f + drawPosition1.x, shiftedY);
            drawPosition4 = fclMakeVec2(drawPosition1.x, shiftedY);
            fclSpriteStartPositionAt(sprite, drawPosition3, drawPosition4, 0, 0x32, 0);
        }
        {
            fclSpriteStartRevealScaleAt(sprite, 1.0f, 2.0f, 1.0f, 1.0f, 0, 0, 0);
        }
        fclSpriteStartAlphaAt(sprite, 0, 0xFF, 1, 0x32, 0);
        ((FclCombineRowSprite *)fclSpriteEntry(sprite))->flag73 = 1;
        ((FclCombineWork *)((u8 *)(sideIndex + (s32)work)))->cursorStates[0] = 1;
        break;
    case 1:
        if ((s64)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(sprite))->flags, 1) == 1) { break; }
        ((FclCombineWork *)((u8 *)(sideIndex + (s32)work)))->cursorStates[0] = 0;
        break;
    case 2:
        fclSpriteSetFlag(sprite, 0, 1);
        break;
    }
}


/* Redraw the pair-grid frame, headers, lists and side panels for mode, using delayStep between
 * rows. The on/off arguments are passed as (s32) casts so they stay locals. */
// FUN_00324680
void fclCombineDrawPairLayout(u8 *task, s32 delayStep, s8 mode) {
    extern f32 D_006443D8[];
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclDrawColor drawColor8;
    FclDrawColor drawColor9;
    FclDrawColor drawColor10;
    s16 a;
    s16 i;
    s32 m;
    s32 count;
    u8 *p;
    u8 *work;
    FclVec2 *v;

    work = ((struct KwlnTask *)task)->work;
    fclCombineLayoutFrame(task, 0, mode);
    fclCombineDrawSlotFields(task, fclMakeVec2(6.0f, 104.0f), 0, mode, 0, 1, 2);
    fclCombineDrawSlotFields(task, fclMakeVec2((f32)315, 104.0f), 0, mode, 1, 0, 0);
    i = 0;
    m = (s16)delayStep;
    for (; i < 12; i++) {
        fclCombinePartyRow(task, fclMakeVec2((f32)315, 128.0f), (s8)i, ((FclCombinePersonaHeader *)yListSlotEntry(0, i))->personaId, ((FclCombinePersonaHeader *)yListSlotEntry(0, i))->level, (s16)(i * m), mode, (count = *(s8*)&((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
    }
    fclCombineDrawPersonaRow(task, fclMakeVec2(6.0f, 195.0f), 0, 0, ((FclCombinePersonaHeader *)yListSlotEntry(1, 0))->personaId, ((FclCombinePersonaHeader *)yListSlotEntry(1, 0))->level, 0, mode, 0, 0xCC);
    if ((s8)mode == 0) {
        u8 *p297;
        u8 *p28B;
        u8 *p27D;
        drawColor1 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
        p297 = fclSpriteEntry(0x297);
        ((FclCombineRowSprite *)p297)->color = drawColor1;
        p28B = fclSpriteEntry(0x28B);
        ((FclCombineRowSprite *)p28B)->color = MEMBER(FclDrawColor, p297, FclCombineRowSprite, color);
        p27D = fclSpriteEntry(0x27D);
        ((FclCombineRowSprite *)p27D)->color = MEMBER(FclDrawColor, p28B, FclCombineRowSprite, color);
        p = fclSpriteEntry(0x270);
        ((FclCombineRowSprite *)p)->color = MEMBER(FclDrawColor, p27D, FclCombineRowSprite, color);
        drawColor2 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        p = fclSpriteEntry(0x2A3);
        ((FclCombineRowSprite *)p)->color = drawColor2;
        drawColor3 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        nmMesWindowSetNumberColor(((FclCombineRowWork *)work)->digitTask, (s16)(i + 0xC), drawColor3);
    }
    v = (FclVec2 *)D_006440F8;
    fclSpriteCreate(0x71, fclMakeVec2(v->x, v->y), 138.0f, 0x41);
    drawColor4 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0x71))->color = drawColor4;
    {
        s32 off = (1 - (s8)mode) * 0xFF;
        s32 on = (s8)mode * 0xFF;
        fclSpriteStartAlphaAt(0x71, (s32)on, (s32)off, 0, 0, 0);
        v = (FclVec2 *)D_006440F0;
        fclSpriteCreate(0x70, fclMakeVec2(v->x, v->y), 139.0f, 0x41);
        drawColor5 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x70))->color = drawColor5;
        fclSpriteStartAlphaAt(0x70, (s32)on, (s32)off, 0, 0, 0);
        for (i = 0; i < 2; i++) {
            v = (FclVec2 *)D_00644290;
            a = i + 0x2BB;
            fclSpriteCreate(a, fclMakeVec2(v->x + (f32)(i * 0x139), v->y), 140.0f, 0x41);
            drawColor6 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(a))->color = drawColor6;
            fclSpriteStartAlphaAt(a, (s32)on, (s32)off, 0, 0, 0);
            v = (FclVec2 *)D_00644298;
            a = i + 0x2BD;
            fclSpriteCreate(a, fclMakeVec2(v->x + (f32)(i * 0x14A), v->y), 141.0f, 0x41);
            drawColor7 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(a))->color = drawColor7;
            fclSpriteStartAlphaAt(a, (s32)on, (s32)off, 0, 0, 0);
            v = (FclVec2 *)D_00644350;
            a = i + 0x2BF;
            fclSpriteCreate(a, fclMakeVec2(v->x + (f32)(i * 0xE), v->y), 142.0f, 0x41);
            drawColor8 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(a))->color = drawColor8;
            fclSpriteStartAlphaAt(a, (s32)on, (s32)off, 0, 0, 0);
        }
    }
    {
        v = (FclVec2 *)D_00644350;
        fclSpriteCreate(0xBC, fclMakeVec2(28.0f + v->x, v->y), 142.0f, 0x41);
        drawColor9 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0xBC))->color = drawColor9;
        fclSpriteStartAlphaAt(0xBC, (s8)mode * 0xFF, (1 - (s8)mode) * 0xFF, 0, 0, 0);
        v = (FclVec2 *)D_006443D8;
        fclSpriteCreate(0xCD, fclMakeVec2(v->x, v->y), 143.0f, 0x41);
        fclSpriteStartAlphaAt(0xCD, (s8)mode * 0xFF, (1 - (s8)mode) * 0xFF, 1, 0xF, 0);
    }
    drawColor10 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0xCD))->color = drawColor10;
}

// Create slot's frame sprites at position, or fade them out when mode is 1.
// FUN_00324F80
void fclCombineDrawSlotFrames(u8 *task, FclVec2 position, s32 slot, s8 mode) {
    FclDrawColor drawColor1, drawColor2, drawColor3, drawColor4, drawColor5;
    FclPackedPosition positionPacket1, positionPacket2, positionPacket3, positionPacket4, positionPacket5, positionPacket6;
    s16 slotIndex;
    f32 originY;

    slotIndex = (s8)slot;
    if (slotIndex == 0) {
        if ((s8)mode == 1) {
            fclSpriteStartAlphaAt(0xAA, 0xFF, 0, 0, 6, 0);
        } else {
            positionPacket1.position = fclMakeVec2(position.x, position.y);
            fclSpriteCreate(0xAA, positionPacket1.position, 168.0f, 0x41);
            drawColor1 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(0xAA))->color = drawColor1;
            fclSpriteStartAlphaAt(0xAA, 0, 0xFF, 0, 6, 0);
        }
    } else if (slotIndex == 1) {
        if ((s8)mode == 1) {
            fclSpriteStartAlphaAt(0xA9, 0xFF, 0, 0, 6, 0);
        } else {
            positionPacket2.position = fclMakeVec2(position.x, position.y);
            fclSpriteCreate(0xA9, positionPacket2.position, 168.0f, 0x41);
            drawColor2 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(0xA9))->color = drawColor2;
            fclSpriteStartAlphaAt(0xA9, 0, 0xFF, 0, 6, 0);
        }
    }
    mode = (s8)mode;
    if (mode == 1) {
        fclSpriteStartAlphaAt(0xAD, 0xFF, 0, 0, 6, 0);
    } else {
        originY = position.y;
        positionPacket3.position = fclMakeVec2(position.x, 176.0f + originY);
        fclSpriteCreate(0xAD, positionPacket3.position, 169.0f, 0x41);
        if (slotIndex == 1) {
            positionPacket4.position = fclMakeVec2(position.x, 194.0f + originY);
            fclSpriteCreate(0xAD, positionPacket4.position, 169.0f, 0x41);
        }
        drawColor3 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0xAD))->color = drawColor3;
        fclSpriteStartAlphaAt(0xAD, 0, 0xFF, 0, 6, 0);
    }
    if (mode == 1) {
        fclSpriteStartAlphaAt(0xB1, 0xFF, 0, 0, 6, 0);
    } else {
        positionPacket5.position = fclMakeVec2(position.x, position.y);
        fclSpriteCreate(0xB1, positionPacket5.position, 166.0f, 0x56);
        drawColor4 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0xB1))->color = drawColor4;
        fclSpriteStartAlphaAt(0xB1, 0, 0xFF, 0, 6, 0);
    }
    if (mode == 1) {
        fclSpriteStartAlphaAt(0xB5, 0xFF, 0, 0, 6, 0);
        return;
    }
    positionPacket6.position = fclMakeVec2(position.x, 52.0f + position.y);
    fclSpriteCreate(0xB5, positionPacket6.position, 167.0f, 0x56);
    drawColor5 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    ((FclCombineRowSprite *)fclSpriteEntry(0xB5))->color = drawColor5;
    fclSpriteStartAlphaAt(0xB5, 0, 0xFF, 0, 6, 0);
}

/* The cursor arrow at x 358 is fclCombineFadeCursorArrow with a zero offset. Retail
   inlines it here, and it loads D_00644C90 before testing the flag. */
/* Create a visible cursor arrow or fade the existing arrow away. */
static inline void fclShowCursorArrow(s8 flag)
{
    f32 *b = D_00644C90;

    if ((s8)flag == 0) {
        fclSpriteCreate(0x1E4, fclMakeVec2(358.0f, b[1]), 103.0f, 0xBC);
        fclSpriteStartAlphaAt(0x1E4, 0, 0xFF, 0, 0xA, 0);
        fclSpriteStartTweenAt(0x1E4, 0, 0, 0, 0.0f, 90.0f);
        return;
    }
    fclSpriteStartAlphaAt(0x1E4, ((FclCombineRowSprite *)fclSpriteEntry(0x1E4))->alpha, 0, 0, 0xA, 0);
}

/* Draw stage's banner tiles and marker; mode 0 also initializes the stage/window selection. Colours
 * are declaration initializers, reassigned in place outside mode 2. */
// FUN_00325450
void fclCombineDrawStageBanner(u8 *task, s32 stage, s8 mode) {
    u8 *work = ((struct KwlnTask *)task)->work;
    FclVec2 pos = fclMakeVec2(18.0f, 14.0f);
    FclDrawColor drawColor1 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
    FclDrawColor drawColor2 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    FclDrawColor drawColor3 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
    FclDrawColor drawColor4 = fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0xFF);
    FclDrawColor drawColor5 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    FclDrawColor drawColor6 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
    FclVec2 pt;

    if ((s8)stage != 2) {
        drawColor1 = fclMakeDrawColor(0xFF, 0xFF, 0x81, 0xFF);
        drawColor2 = fclMakeDrawColor(0x31, 0x31, 0x31, 0xFF);
        drawColor3 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        drawColor4 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        drawColor5 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawColor6 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    }
    pt = fclMakeVec2(13.0f + pos.x, pos.y);
    fclSpriteStartShowHide(0x12E, pt, 0x12E, drawColor1, 37.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
    pt = fclMakeVec2(573 + pos.x, pos.y);
    fclSpriteStartShowHide(0x12F, pt, 0x12F, drawColor1, 38.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
    pt = fclMakeVec2(pos.x - 5.0f, (pos.y - 14.0f));
    fclSpriteStartShowHide(0x12C, pt, 0x12C, drawColor2, 31.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
    pt = fclMakeVec2(559 + pos.x, (pos.y - 14.0f));
    fclSpriteStartShowHide(0x12A, pt, 0x12A, drawColor2, 32.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
    pt = fclMakeVec2((40.0f + pos.x), (13.0f + pos.y));
    fclSpriteStartShowHide(0x13A, pt, 0x13A, drawColor3, 33.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
    pt = fclMakeVec2(24.0f + pos.x, (13.0f + pos.y));
    fclSpriteStartShowHide(0x13C, pt, 0x13C, drawColor3, 33.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
    pt = fclMakeVec2((522 + pos.x), (13.0f + pos.y));
    fclSpriteStartShowHide(0x13B, pt, 0x13B, drawColor3, 34.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
    pt = fclMakeVec2(562 + pos.x, (13.0f + pos.y));
    fclSpriteStartShowHide(0x13D, pt, 0x13D, drawColor3, 33.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
    pt = fclMakeVec2((87.0f + pos.x), (2.0f + pos.y));
    fclSpriteStartShowHide(0x14F, pt, 0x14F, drawColor2, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
    pt = fclMakeVec2((428.0f + (87.0f + pos.x)) - 1.0f, (2.0f + pos.y));
    fclSpriteStartShowHide(0x2C2, pt, 0x14F, drawColor2, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
    switch ((s8)stage) {
    case 0:
        fclSpriteReset(0x2DE, 0x126);
        fclSpriteReset(0x2DF, 0x125);
        pt = fclMakeVec2(113.0f + pos.x, (13.0f + pos.y));
        fclSpriteStartShowHide(0x126, pt, 0x126, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DE, pt, 0x126, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(320.0f + pos.x, (13.0f + pos.y));
        fclSpriteStartShowHide(0x125, pt, 0x125, drawColor5, 30.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DF, pt, 0x125, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(214.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2C1, pt, 0x14F, drawColor2, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((216.0f + (87.0f + pos.x)) - (f32)(((FclCombineWork *)work)->f122 * 0xD6), 4.0f + pos.y);
        fclSpriteStartShowHide(0x150, pt, 0x150, drawColor6, 36.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteReset(0x2E0, 0x150);
        fclSpriteStartShowHide(0x2E0, pt, 0x150, fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0), 24.0f, 0xBE, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E0, 0xD, 0);
        break;
    case 1:
        fclSpriteReset(0x2DE, 0x128);
        fclSpriteReset(0x2DF, 0x127);
        pt = fclMakeVec2((171.0f + pos.x), (12.0f + pos.y));
        fclSpriteStartShowHide(0x128, pt, 0x128, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((171.0f + pos.x), (12.0f + pos.y));
        fclSpriteStartShowHide(0x2DE, pt, 0x128, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((354.0f + pos.x), (14.0f + pos.y));
        fclSpriteStartShowHide(0x127, pt, 0x127, drawColor5, 30.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((354.0f + pos.x), (14.0f + pos.y));
        fclSpriteStartShowHide(0x2DF, pt, 0x127, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(214.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2C1, pt, 0x14F, drawColor2, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((216.0f + (87.0f + pos.x)) - (f32)(((FclCombineWork *)work)->f122 * 0xD6), 4.0f + pos.y);
        fclSpriteStartShowHide(0x150, pt, 0x150, drawColor6, 36.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteReset(0x2E0, 0x150);
        fclSpriteStartShowHide(0x2E0, pt, 0x150, fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0), 24.0f, 0xBE, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E0, 0xD, 0);
        break;
    case 2:
        pt = fclMakeVec2((40.0f + pos.x), (13.0f + pos.y));
        fclSpriteStartShowHide(0x13A, pt, 0x13A, drawColor3, 33.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((522 + pos.x), (13.0f + pos.y));
        fclSpriteStartShowHide(0x13B, pt, 0x13B, drawColor3, 34.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteReset(0x2DE, 0x1D4);
        fclSpriteReset(0x2DF, 0x1D5);
        pt = fclMakeVec2((140.0f + pos.x), (12.0f + pos.y));
        fclSpriteStartShowHide(0x1D4, pt, 0x1D4, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((140.0f + pos.x), (12.0f + pos.y));
        fclSpriteStartShowHide(0x2DE, pt, 0x1D4, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((355 + pos.x), (14.0f + pos.y));
        fclSpriteStartShowHide(0x1D5, pt, 0x1D5, drawColor5, 30.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((355 + pos.x), (14.0f + pos.y));
        fclSpriteStartShowHide(0x2DF, pt, 0x1D5, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(214.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2C1, pt, 0x14F, drawColor2, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        if ((s8)mode == 0) {
            ((FclCombineWork *)work)->f122 = 1;
        }
        pt = fclMakeVec2((216.0f + (87.0f + pos.x)) - (f32)(((FclCombineWork *)work)->f122 * 0xD6), 4.0f + pos.y);
        fclSpriteStartShowHide(0x150, pt, 0x150, drawColor6, 36.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteReset(0x2E0, 0x150);
        fclSpriteStartShowHide(0x2E0, pt, 0x150, fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0), 24.0f, 0xBE, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E0, 0xD, 0);
        break;
    case 3:
        fclSpriteReset(0x2DE, 0x13F);
        fclSpriteReset(0x2DF, 0x140);
        fclSpriteReset(0x2E0, 0x151);
        fclSpriteReset(0x2E1, 0x14C);
        fclSpriteReset(0x2E2, 0x14F);
        if ((s8)mode == 0) {
            fclSpriteSetHidden(((FclCombineWork *)work)->f28C, 1);
            fclSpriteSetHidden(((FclCombineWork *)work)->f290, 1);
            ((FclCombineWork *)work)->f122 = 2;
        }
        pt = fclMakeVec2(138.0f + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x13F, pt, 0x13F, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DE, pt, 0x13F, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(277 + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x140, pt, 0x140, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DF, pt, 0x140, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(416.0f + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x14C, pt, 0x14C, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E1, pt, 0x14C, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(88.0f + pos.x + (f32)(((FclCombineWork *)work)->f122 * 0x8E), 4.0f + pos.y);
        fclSpriteStartShowHide(0x151, pt, 0x151, drawColor6, 36.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E0, pt, 0x151, fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0), 24.0f, 0xBE, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E0, 0xD, 0);
        pt = fclMakeVec2(142.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2C1, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(284.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E2, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        break;
    case 4:
        fclSpriteReset(0x2DE, 0x13F);
        fclSpriteReset(0x2DF, 0x140);
        fclSpriteReset(0x2E0, 0x152);
        fclSpriteReset(0x2E1, 0x14C);
        fclSpriteReset(0x2E2, 0x14F);
        fclSpriteReset(0x2E3, 0x141);
        fclSpriteReset(0x2E4, 0x14F);
        if ((s8)mode == 0) {
            fclSpriteSetHidden(((FclCombineWork *)work)->f28C, 1);
            fclSpriteSetHidden(((FclCombineWork *)work)->f290, 1);
            ((FclCombineWork *)work)->f122 = 3;
        }
        pt = fclMakeVec2(127.0f + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x13F, pt, 0x13F, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DE, pt, 0x13F, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(229.0f + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x140, pt, 0x140, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DF, pt, 0x140, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(334.0f + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x141, pt, 0x141, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E3, pt, 0x141, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(435 + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x14C, pt, 0x14C, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E1, pt, 0x14C, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(88.0f + pos.x + (f32)(((FclCombineWork *)work)->f122 * 0x6B), 4.0f + pos.y);
        fclSpriteStartShowHide(0x152, pt, 0x152, drawColor6, 36.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E0, pt, 0x152, fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0), 24.0f, 0xBE, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E0, 0xD, 0);
        pt = fclMakeVec2(107.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2C1, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(214.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E2, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(321 + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E4, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        break;
    case 5:
        fclSpriteReset(0x2DE, 0x13F);
        fclSpriteReset(0x2DF, 0x140);
        fclSpriteReset(0x2E0, 0x153);
        fclSpriteReset(0x2E1, 0x14C);
        fclSpriteReset(0x2E2, 0x14F);
        fclSpriteReset(0x2E3, 0x141);
        fclSpriteReset(0x2E4, 0x14F);
        fclSpriteReset(0x2E5, 0x142);
        fclSpriteReset(0x2E6, 0x14F);
        fclSpriteReset(0x2E7, 0x14B);
        if ((s8)mode == 0) {
            fclSpriteSetHidden(((FclCombineWork *)work)->f28C, 1);
            fclSpriteSetHidden(((FclCombineWork *)work)->f290, 1);
            ((FclCombineWork *)work)->f122 = 4;
        }
        pt = fclMakeVec2(114.0f + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x13F, pt, 0x13F, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DE, pt, 0x13F, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(199.0f + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x140, pt, 0x140, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DF, pt, 0x140, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(284.0f + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x141, pt, 0x141, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E3, pt, 0x141, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((369 + pos.x), (9.0f + pos.y));
        fclSpriteStartShowHide(0x142, pt, 0x142, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E5, pt, 0x142, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(24.0f + (369 + pos.x), 15.0f + (9.0f + pos.y));
        fclSpriteStartShowHide(0x14B, pt, 0x14B, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E7, pt, 0x14B, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(446.0f + pos.x, (9.0f + pos.y));
        fclSpriteStartShowHide(0x14C, pt, 0x14C, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E1, pt, 0x14C, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(88.0f + pos.x + (f32)(((FclCombineWork *)work)->f122 * 0x55), 4.0f + pos.y);
        fclSpriteStartShowHide(0x153, pt, 0x153, drawColor6, 36.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E0, pt, 0x153, fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0), 24.0f, 0xBE, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E0, 0xD, 0);
        pt = fclMakeVec2(85.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2C1, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(170.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E2, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(255.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E4, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(340.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E6, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        break;
    case 6:
        fclSpriteReset(0x2DE, 0x13F);
        fclSpriteReset(0x2DF, 0x140);
        fclSpriteReset(0x2E0, 0x154);
        fclSpriteReset(0x2E1, 0x14C);
        fclSpriteReset(0x2E2, 0x14F);
        fclSpriteReset(0x2E3, 0x141);
        fclSpriteReset(0x2E4, 0x14F);
        fclSpriteReset(0x2E5, 0x142);
        fclSpriteReset(0x2E6, 0x14F);
        fclSpriteReset(0x2E7, 0x14B);
        fclSpriteReset(0x2E8, 0x143);
        fclSpriteReset(0x2E9, 0x14F);
        fclSpriteReset(0x2EA, 0x14B);
        fclSpriteReset(0x2EB, 0x14B);
        if ((s8)mode == 0) {
            fclSpriteSetHidden(((FclCombineWork *)work)->f28C, 1);
            fclSpriteSetHidden(((FclCombineWork *)work)->f290, 1);
            ((FclCombineWork *)work)->f122 = 5;
        }
        pt = fclMakeVec2(20.0f + (87.0f + pos.x), (9.0f + pos.y));
        fclSpriteStartShowHide(0x13F, pt, 0x13F, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DE, pt, 0x13F, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(15.0f + (71.0f + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x140, pt, 0x140, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DF, pt, 0x140, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(16.0f + (142.0f + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x141, pt, 0x141, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E3, pt, 0x141, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(16.0f + (213.0f + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x142, pt, 0x142, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E5, pt, 0x142, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(24.0f + pt.x, 15.0f + pt.y);
        fclSpriteStartShowHide(0x14B, pt, 0x14B, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E7, pt, 0x14B, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(15.0f + (284.0f + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x143, pt, 0x143, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E8, pt, 0x143, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(25.0f + pt.x, 15.0f + pt.y);
        fclSpriteStartShowHide(0x2EA, pt, 0x14B, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2EB, pt, 0x14B, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(11.0f + (355 + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x14C, pt, 0x14C, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E1, pt, 0x14C, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((87.0f + pos.x) + (f32)(((FclCombineWork *)work)->f122 * 0x47), 4.0f + pos.y);
        fclSpriteStartShowHide(0x154, pt, 0x154, drawColor6, 36.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E0, pt, 0x154, fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0), 24.0f, 0xBE, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E0, 0xD, 0);
        pt = fclMakeVec2((71.0f + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2C1, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((142.0f + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E2, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((213.0f + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E4, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((284.0f + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E6, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((355 + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E9, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        break;
    case 7:
        fclSpriteReset(0x2DE, 0x13F);
        fclSpriteReset(0x2DF, 0x140);
        fclSpriteReset(0x2E0, 0x155);
        fclSpriteReset(0x2E1, 0x14C);
        fclSpriteReset(0x2E2, 0x14F);
        fclSpriteReset(0x2E3, 0x141);
        fclSpriteReset(0x2E4, 0x14F);
        fclSpriteReset(0x2E5, 0x142);
        fclSpriteReset(0x2E6, 0x14F);
        fclSpriteReset(0x2E7, 0x14B);
        fclSpriteReset(0x2E8, 0x143);
        fclSpriteReset(0x2E9, 0x14F);
        fclSpriteReset(0x2EA, 0x14B);
        fclSpriteReset(0x2EB, 0x14B);
        fclSpriteReset(0x2EC, 0x144);
        fclSpriteReset(0x2ED, 0x14F);
        fclSpriteReset(0x2EE, 0x14B);
        fclSpriteReset(0x2EF, 0x14B);
        if ((s8)mode == 0) {
            fclSpriteSetHidden(((FclCombineWork *)work)->f28C, 1);
            fclSpriteSetHidden(((FclCombineWork *)work)->f290, 1);
            ((FclCombineWork *)work)->f122 = 6;
        }
        pt = fclMakeVec2(13.0f + (87.0f + pos.x), (9.0f + pos.y));
        fclSpriteStartShowHide(0x13F, pt, 0x13F, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DE, pt, 0x13F, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(12.0f + (61.0f + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x140, pt, 0x140, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2DF, pt, 0x140, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(10.0f + (122.0f + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x141, pt, 0x141, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E3, pt, 0x141, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(10.0f + (183.0f + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x142, pt, 0x142, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E5, pt, 0x142, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(24.0f + pt.x, 15.0f + pt.y);
        fclSpriteStartShowHide(0x14B, pt, 0x14B, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E7, pt, 0x14B, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(10.0f + (244.0f + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x143, pt, 0x143, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E8, pt, 0x143, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(25.0f + pt.x, 15.0f + pt.y);
        fclSpriteStartShowHide(0x2EA, pt, 0x14B, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2EB, pt, 0x14B, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(10.0f + (305 + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x144, pt, 0x144, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2EC, pt, 0x144, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(25.0f + pt.x, 15.0f + pt.y);
        fclSpriteStartShowHide(0x2EE, pt, 0x14B, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2EF, pt, 0x14B, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(6.0f + (366.0f + (87.0f + pos.x)), (9.0f + pos.y));
        fclSpriteStartShowHide(0x14C, pt, 0x14C, drawColor5, 29.0f, 0xBD, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E1, pt, 0x14C, drawColor4, 25.0f, 0xBF, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((87.0f + pos.x) + (f32)(((FclCombineWork *)work)->f122 * 0x3D), 4.0f + pos.y);
        fclSpriteStartShowHide(0x155, pt, 0x155, drawColor6, 36.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E0, pt, 0x155, fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0), 24.0f, 0xBE, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E0, 0xD, 0);
        pt = fclMakeVec2((61.0f + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2C1, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((122.0f + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E2, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((183.0f + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E4, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((244.0f + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E6, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((305 + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E9, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2((366.0f + (87.0f + pos.x)), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2ED, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        break;
    case 8:
        fclSpriteReset(0x2DE, 0x14F);
        fclSpriteReset(0x2DF, 0x14F);
        fclSpriteReset(0x2E0, 0x155);
        fclSpriteReset(0x2E1, 0x14F);
        fclSpriteReset(0x2E2, 0x14F);
        fclSpriteReset(0x2E3, 0x14F);
        if ((s8)mode == 0) {
            fclSpriteSetHidden(((FclCombineWork *)work)->f28C, 1);
            fclSpriteSetHidden(((FclCombineWork *)work)->f290, 1);
            ((FclCombineWork *)work)->f122 = 0xC;
            ((FclCombineWork *)work)->windowRow = 6;
        }
        fclCombineDrawStageTiles(task, 6, mode);
        pt = fclMakeVec2((87.0f + pos.x) + (f32)(((FclCombineWork *)work)->windowRow * 0x3D), 4.0f + pos.y);
        fclSpriteStartShowHide(0x155, pt, 0x155, drawColor6, 36.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteStartShowHide(0x2E0, pt, 0x155, fclMakeDrawColor(0x8A, 0xCC, 0xFF, 0), 24.0f, 0xBE, mode, 6, 3, 0, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E0, 0xD, 0);
        pt = fclMakeVec2(61.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2C1, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(122.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2DE, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(183.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2DF, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(244.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E1, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(305 + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E2, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        pt = fclMakeVec2(366.0f + (87.0f + pos.x), (2.0f + pos.y));
        fclSpriteStartShowHide(0x2E3, pt, 0x14F, drawColor6, 35.0f, 0xBC, mode, 6, 3, 0, fclCombineGetSpritePool());
        break;
    }
    if ((s8)mode == 0) {
        if ((s8)stage == 0) {
            fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0);
            fclShowCursorArrow(mode);
        } else if ((s8)stage == 1) {
            fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0);
            fclShowCursorArrow(mode);
        }
    } else {
        if ((s8)stage == 0) {
            fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1);
            fclShowCursorArrow(mode);
        } else if ((s8)stage == 1) {
            fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0);
        }
    }
}

/* measured: retail keeps the table load and add as a separate inline step, which keeps the
 * current-x load order; expanding it inline changes the caller's code. */
static inline f32 fclRowAdjustedX(f32 x, const f32 *table, s32 offset)
{
    const f32 *adjustment = (const f32 *)((const u8 *)table + offset);
    x += *adjustment;
    return x;
}

// Draw seven visible stage tiles and their shadows with duration and mode; later tiles add secondary pairs.
// FUN_00329310
void fclCombineDrawStageTiles(u8 *owner, s16 duration, s8 mode) {
    /* Table offsets are in bytes, not float indices; the stage/window bytes lie outside the shared
     * row-work prefix. */
    typedef union { FclDrawColor channels; u32 word; } PackedColor;
    PackedColor white;
    PackedColor dark;
    PackedColor secondaryWhite;
    PackedColor secondaryDark;
    f32 origin[2];
    FclVec2 position;
    FclVec2 constructedOrigin;
    /* Preserve resource, column and index declaration order for the saved values. */
    s16 resource;
    s8 first;
    s16 i;
    s16 column;
    s16 index;
    s32 limit;
    f32 baseY;
    f32 baseX;
    u8 *task;

    task = ((struct KwlnTask *)owner)->work;
    constructedOrigin = fclMakeVec2(18.0f, 14.0f);
    *(FclVec2 *)&origin = constructedOrigin;
    first = (s8)(((FclCombineWork *)task)->f122 - ((FclCombineWork *)task)->windowRow);
    for (i = 0; i < 14; ++i) {
        fclSpriteSetFlag((s16)(i + 0x13F), 0, 1);
    }
    fclSpriteSetFlag(0x2E4, 0, 1);
    index = first;
    column = 0;
    baseY = 9.0f + origin[1];
    baseX = 87.0f + origin[0];
    limit = first + 7;
    while (index < limit) {
        s16 shadow;
        s64 savedIndex;
        s32 tableOffset;
        u32 savedColumn;
        f32 *columnAdjustment;
        resource = (s16)(index + 0x13F);
        if (resource == 0x14B) {
            resource = 0x14C;
        }
        savedIndex = index;
        tableOffset = (s32)savedIndex * 4;
        savedColumn = column;
        /* The typed element pointer is assigned inside the expression to keep retail's evaluation
         * order. */
        position = fclMakeVec2(baseX + (f32)((s32)savedColumn * 61) + *(columnAdjustment = (f32 *)((u8 *)D_007495C0 + tableOffset)), baseY);
        ((FclCombineRowSprite *)fclSpriteEntry(resource))->position = position;
        white.channels = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        fclSpriteStartShowHide(resource, position, resource, white.channels, 29.0f, 0xBD, mode, duration, 3, 0, fclCombineGetSpritePool());
        shadow = (s16)((s16)((s32)savedColumn * 3 + 0xF1) + 0x1F4);
        fclSpriteSetFlag(shadow, 0, 1);
        fclSpriteReset(shadow, resource);
        dark.channels = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        fclSpriteStartShowHide(shadow, position, resource, dark.channels, 25.0f, 0xBF, mode, duration, 3, 0, fclCombineGetSpritePool());
        if (savedIndex >= 3 && index != 12) {
            s32 group;
            s16 secondary;
            s16 secondaryShadow;
            position = fclMakeVec2(fclRowAdjustedX(position.x, D_00749600, tableOffset), 15.0f + position.y);
            group = column * 3;
            secondary = (s16)((s16)(group + 0xF2) + 0x1F4);
            fclSpriteReset(secondary, 0x14B);
            secondaryWhite.channels = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
            fclSpriteStartShowHide(secondary, position, 0x14B, secondaryWhite.channels, 29.0f, 0xBD, mode, duration, 3, 0, fclCombineGetSpritePool());
            secondaryShadow = (s16)((s16)(group + 0xF3) + 0x1F4);
            fclSpriteReset(secondaryShadow, 0x14B);
            secondaryDark.channels = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclSpriteStartShowHide(secondaryShadow, position, 0x14B, secondaryDark.channels, 25.0f, 0xBF, mode, duration, 3, 0, fclCombineGetSpritePool());
        } else {
            s32 group = column * 3;
            fclSpriteSetFlag((s16)((s16)(group + 0xF2) + 0x1F4), 0, 1);
            fclSpriteSetFlag((s16)((s16)(group + 0xF3) + 0x1F4), 0, 1);
        }
        ++index;
        ++column;
    }
}
/* measured: opt_propagation off keeps the shared bounds pointer live across its constructor calls.
 * Slides the panel header from originX by slideOffset; variant picks the label pair, mode 0 creates
 * the sprites. */
/* Slide the combine panel header sprites horizontally by slideOffset from originX, choosing the
 * label pair by variant. Mode 0 creates the sprites and slides them in; any other mode slides the
 * existing sprites out from where they are now. */
// FUN_003297F0
/* measured: retail keeps the shared bounds pointer through the constructor calls, which needs
 * propagation off. */
#pragma opt_propagation off
void fclCombineSlideInHeaderSprites(f32 originX, f32 slideOffset, u8 *task, s64 variant, s8 mode) {
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    FclVec2 drawPosition6;
    FclVec2 drawPosition7;
    FclVec2 drawPosition8;
    FclVec2 drawPosition9;
    FclVec2 drawPosition10;
    FclVec2 drawPosition11;
    FclVec2 drawPosition12;
    FclVec2 drawPosition13;
    FclVec2 drawPosition14;
    FclVec2 drawPosition15;
    s64 entryMode;
    s64 headerVariant;
    u8 *p;
    u8 *q;
    f32 *bounds;
    bounds = D_006440B8;
    drawPosition1 = fclMakeVec2(originX, bounds[1]);
    entryMode = (s8)mode;
    if (entryMode == 0) {
        fclSpriteCreate(0x69, drawPosition1, 132.0f, 0x56);
        drawColor1 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        p = fclSpriteEntry(0x69);
        ((FclCombineRowSprite *)p)->color = drawColor1;
        drawPosition3 = fclMakeVec2(drawPosition1.x + slideOffset, bounds[1]);
        drawPosition4 = fclMakeVec2(drawPosition1.x, bounds[1]);
        fclSpriteStartPositionAt(0x69, drawPosition3, drawPosition4, 0, 8, 0);
    } else {
        p = fclSpriteEntry(0x69);
        drawPosition5 = fclMakeVec2(drawPosition1.x + slideOffset, bounds[1]);
        fclSpriteStartPositionAt(0x69, ((FclCombineRowSprite *)p)->position, drawPosition5, 0, 8, 0);
    }
    drawPosition2 = fclMakeVec2(17.0f + drawPosition1.x, 9.0f + drawPosition1.y);
    if (entryMode == 0) {
        fclSpriteCreate(0x1AD, drawPosition2, 135.0f, 0x41);
        drawColor2 = fclMakeDrawColor(0xE, 0x17, 0x49, 0xFF);
        q = fclSpriteEntry(0x1AD);
        ((FclCombineRowSprite *)q)->color = drawColor2;
        ((FclCombineRowSprite *)fclSpriteEntry(0x1AD))->alpha = 0x80;
        drawPosition6 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
        fclSpriteStartPositionAt(0x1AD, drawPosition6, drawPosition2, 0, 8, 0);
    } else {
        p = fclSpriteEntry(0x1AD);
        drawPosition7 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
        fclSpriteStartPositionAt(0x1AD, ((FclCombineRowSprite *)p)->position, drawPosition7, 0, 8, 0);
    }
    headerVariant = (s8)variant;
    if ((s8)headerVariant == 0) {
        drawPosition2 = fclMakeVec2(67.0f + drawPosition1.x, 13.0f + drawPosition1.y);
        if (entryMode == 0) {
            fclSpriteCreate(0x109, drawPosition2, 134.0f, 0x56);
            drawPosition8 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
            fclSpriteStartPositionAt(0x109, drawPosition8, drawPosition2, 0, 8, 0);
        } else {
            p = fclSpriteEntry(0x109);
            drawPosition9 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
            fclSpriteStartPositionAt(0x109, ((FclCombineRowSprite *)p)->position, drawPosition9, 0, 8, 0);
        }
        drawPosition2 = fclMakeVec2(95.0f + drawPosition1.x, 15.0f + drawPosition1.y);
        if (entryMode == 0) {
            fclSpriteCreate(0x10A, drawPosition2, 133.0f, 0x56);
            drawPosition10 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
            fclSpriteStartPositionAt(0x10A, drawPosition10, drawPosition2, 0, 8, 0);
            return;
        }
        p = fclSpriteEntry(0x10A);
        drawPosition11 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
        fclSpriteStartPositionAt(0x10A, ((FclCombineRowSprite *)p)->position, drawPosition11, 0, 8, 0);
        return;
    } else if ((s8)headerVariant == 1) {
        drawPosition2 = fclMakeVec2(114.0f + drawPosition1.x, 11.0f + drawPosition1.y);
        if (entryMode == 0) {
            fclSpriteCreate(0x11C, drawPosition2, 134.0f, 0x56);
            drawPosition12 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
            fclSpriteStartPositionAt(0x11C, drawPosition12, drawPosition2, 0, 8, 0);
        } else {
            p = fclSpriteEntry(0x11C);
            drawPosition13 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
            fclSpriteStartPositionAt(0x11C, ((FclCombineRowSprite *)p)->position, drawPosition13, 0, 8, 0);
        }
        drawPosition2 = fclMakeVec2(50.0f + drawPosition1.x, 16.0f + drawPosition1.y);
        if (entryMode == 0) {
            fclSpriteCreate(0x11B, drawPosition2, 133.0f, 0x56);
            drawPosition14 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
            fclSpriteStartPositionAt(0x11B, drawPosition14, drawPosition2, 0, 8, 0);
            return;
        }
        p = fclSpriteEntry(0x11B);
        drawPosition15 = fclMakeVec2(drawPosition2.x + slideOffset, drawPosition2.y);
        fclSpriteStartPositionAt(0x11B, ((FclCombineRowSprite *)p)->position, drawPosition15, 0, 8, 0);
        return;
    }
}

#pragma opt_propagation on
/* The aggregate FclVec2 copy loads both coordinates before storing the retained origin; a typed-
 * pointer or scalar copy changes that order. */


/* Draws the fixed header panel at (79, 97): backing frame, title sprites and two highlight rows
 * offset by the cursor byte (step 0x101). delay and mode pass through to every draw call. */
// FUN_00329E40
void fclCombineDrawHeaderPanel(u8 *task, s16 delay, s8 mode) {


    FclVec2 origin;
    FclVec2 constructed;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    FclVec2 drawPosition6;
    FclVec2 drawPosition7;
    FclVec2 drawPosition8;
    FclVec2 drawPosition9;
    FclVec2 drawPosition10;
    FclVec2 drawPosition11;
    FclVec2 drawPosition12;
    FclVec2 drawPosition13;
    FclVec2 drawPosition14;
    FclVec2 drawPosition15;
    FclVec2 drawPosition16;
    FclVec2 drawPosition17;
    u8 *work;
    work = ((struct KwlnTask *)task)->work;
    constructed = fclMakeVec2(79.0f, 97.0f);
    fclCopyPositionStorage(&origin, &constructed);
    {
        FclDrawColor panelColor = fclMakeDrawColor(0, 0, 0x99, 0xFF);
        FclDrawColor textColor = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        textColor = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        fclSpriteStartShowHide(0x21C, origin, 0x193, panelColor, 191.0f, 0x41, mode, 6, 3, delay, fclCombineGetSpritePool());
        drawPosition1 = fclMakeVec2((f32)0x1DF + origin.x, origin.y);
        fclSpriteStartShowHide(0x1A3, drawPosition1, 0x1A3, panelColor, 191.0f, 0x41, mode, 6, 3, delay, fclCombineGetSpritePool());
        drawPosition2 = fclMakeVec2(20.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x120, drawPosition2, 0x120, textColor, 184.0f, 0x56, mode, 6, 3, delay, fclCombineGetSpritePool());
        fclSpriteReset(0x2E8, 0x120);
        drawPosition3 = fclMakeVec2(30.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x2E8, drawPosition3, 0x120, textColor, 184.0f, 0x56, mode, 6, 3, delay, fclCombineGetSpritePool());
        drawPosition4 = fclMakeVec2(47.0f + origin.x, 2.0f + origin.y);
        fclSpriteStartShowHide(0x11F, drawPosition4, 0x11F, textColor, 183.0f, 0x56, mode, 6, 3, delay, fclCombineGetSpritePool());
        origin = fclMakeVec2(314.0f, 97.0f);
        drawPosition5 = fclMakeVec2(214.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x121, drawPosition5, 0x121, textColor, 185.0f, 0x56, mode, 6, 3, delay, fclCombineGetSpritePool());
        fclSpriteReset(0x2E9, 0x121);
        drawPosition6 = fclMakeVec2(224.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x2E9, drawPosition6, 0x121, textColor, 185.0f, 0x56, mode, 6, 3, delay, fclCombineGetSpritePool());
        drawPosition7 = fclMakeVec2(97.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x11E, drawPosition7, 0x11E, textColor, 182.0f, 0x56, mode, 6, 3, delay, fclCombineGetSpritePool());
        panelColor = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
        origin = fclMakeVec2(79.0f, 97.0f);
        fclSpriteReset(0x2EA, 0x193);
        drawPosition8 = fclMakeVec2(origin.x + (f32)(((FclCombineWork *)work)->headerSelection * 0x101), origin.y);
        fclSpriteStartShowHide(0x2EA, drawPosition8, 0x193, panelColor, 187.0f, 0x41, mode, 6, 3, delay, fclCombineGetSpritePool());
        fclSpriteReset(0x2EB, 0x19C);
        drawPosition9 = fclMakeVec2(220.0f + origin.x + (f32)(MEMBER(s8, work, FclCombineWork, headerSelection) * 0x101), origin.y);
        fclSpriteStartShowHide(0x2EB, drawPosition9, 0x19C, panelColor, 187.0f, 0x41, mode, 6, 3, delay, fclCombineGetSpritePool());
        origin = fclMakeVec2(79.0f, 97.0f);
        fclSpriteReset(0x2EC, 0x11F);
        drawPosition10 = fclMakeVec2(47.0f + origin.x, 2.0f + origin.y);
        fclSpriteStartShowHide(0x2EC, drawPosition10, 0x11F, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, fclCombineGetSpritePool());
        fclSpriteReset(0x2E4, 0x120);
        drawPosition11 = fclMakeVec2(20.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x2E4, drawPosition11, 0x120, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, fclCombineGetSpritePool());
        fclSpriteReset(0x2E5, 0x120);
        drawPosition12 = fclMakeVec2(30.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x2E5, drawPosition12, 0x120, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, fclCombineGetSpritePool());
        origin = fclMakeVec2(314.0f, 97.0f);
        fclSpriteReset(0x2E1, 0x11E);
        drawPosition13 = fclMakeVec2(97.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x2E1, drawPosition13, 0x11E, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, fclCombineGetSpritePool());
        fclSpriteReset(0x2E6, 0x121);
        drawPosition14 = fclMakeVec2(214.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x2E6, drawPosition14, 0x121, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, fclCombineGetSpritePool());
        fclSpriteReset(0x2E7, 0x121);
        drawPosition15 = fclMakeVec2(224.0f + origin.x, 3.0f + origin.y);
        fclSpriteStartShowHide(0x2E7, drawPosition15, 0x121, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, fclCombineGetSpritePool());
        panelColor = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
        origin = fclMakeVec2(79.0f, 97.0f);
        fclSpriteReset(0x2E2, 0x193);
        drawPosition16 = fclMakeVec2(origin.x + (f32)(MEMBER(s8, work, FclCombineWork, headerSelection) * 0x101), origin.y);
        fclSpriteStartShowHide(0x2E2, drawPosition16, 0x193, fclMakeDrawColor(0xCC, 0xFF, 0x33, 0), 180.0f, 0x59, mode, 6, 3, delay, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E2, 0xD, 0);
        fclSpriteReset(0x2E3, 0x19C);
        drawPosition17 = fclMakeVec2(220.0f + origin.x + (f32)(MEMBER(s8, work, FclCombineWork, headerSelection) * 0x101), origin.y);
        fclSpriteStartShowHide(0x2E3, drawPosition17, 0x19C, fclMakeDrawColor(0xCC, 0xFF, 0x33, 0), 180.0f, 0x59, mode, 6, 3, delay, fclCombineGetSpritePool());
        fclSpriteSetFlag(0x2E3, 0xD, 0);
    }
}
/* measured: the draw routine needs opt_propagation off around it, with constructor-built FclVec2
 * values and explicit x/y snapshots, to reproduce retail code. */
// FUN_0032A960
#pragma push
/* measured: retail keeps the constructor-backed positions unpropagated, which needs propagation
 * off. */
#pragma opt_propagation off
void fclCombineDrawPanelBorder(u8 *task, s8 mode) {
    /* Alpha is stored as a signed byte inside the surrounding animation packet. */
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclVec2 origin;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    f32 labelY;
    f32 cornerX;
    u8 *p;
    (void)task;
    drawPosition2 = fclMakeVec2(22.0f, 78.0f);
    {
        f32 x = drawPosition2.x;
        f32 y = drawPosition2.y;
        origin.x = x;
        origin.y = y;
    }
    if ((s8)mode == 0) {
        fclSpriteCreate(0x9E, origin, 15.0f, 0xC1);
        drawColor1 = fclMakeDrawColor(0, 0, 0, 0xFF);
        p = fclSpriteEntry(0x9E);
        ((FclCombineRowSprite *)p)->color = drawColor1;
        ((FclCombineRowSprite *)fclSpriteEntry(0x9E))->alpha = 0x66;
        fclSpriteStartAlphaAt(0x9E, 0, 0x66, 0, 5, 3);
    } else {
        fclSpriteStartAlphaAt(0x9E, ((FclCombineRowSprite *)fclSpriteEntry(0x9E))->alpha, 0, 0, 0, 0);
    }
    drawPosition1 = fclMakeVec2(origin.x, 293.0f + origin.y);
    if ((s8)mode == 0) {
        fclSpriteCreate(0xA0, drawPosition1, 16.0f, 0xC1);
        drawColor2 = fclMakeDrawColor(0, 0, 0, 0xFF);
        p = fclSpriteEntry(0xA0);
        ((FclCombineRowSprite *)p)->color = drawColor2;
        ((FclCombineRowSprite *)fclSpriteEntry(0xA0))->alpha = 0x66;
        fclSpriteStartAlphaAt(0xA0, 0, 0x66, 0, 5, 3);
    } else {
        fclSpriteStartAlphaAt(0xA0, ((FclCombineRowSprite *)fclSpriteEntry(0xA0))->alpha, 0, 0, 0, 0);
    }
    labelY = 23.0f + origin.y;
    drawPosition1 = fclMakeVec2(15.0f + origin.x, labelY);
    if ((s8)mode == 0) {
        fclSpriteCreate(0x196, drawPosition1, 13.0f, 0xC2);
        drawColor3 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        p = fclSpriteEntry(0x196);
        ((FclCombineRowSprite *)p)->color = drawColor3;
        fclSpriteStartAlphaAt(0x196, 0, 0xFF, 0, 5, 0);
    } else {
        fclSpriteStartAlphaAt(0x196, ((FclCombineRowSprite *)fclSpriteEntry(0x196))->alpha, 0, 0, 0, 0);
    }
    drawPosition1 = fclMakeVec2(285.0f + origin.x, labelY);
    if ((s8)mode == 0) {
        fclSpriteCreate(0x1A1, drawPosition1, 14.0f, 0xC2);
        drawColor4 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        p = fclSpriteEntry(0x1A1);
        ((FclCombineRowSprite *)p)->color = drawColor4;
        fclSpriteStartAlphaAt(0x1A1, 0, 0xFF, 0, 5, 0);
    } else {
        fclSpriteStartAlphaAt(0x1A1, ((FclCombineRowSprite *)fclSpriteEntry(0x1A1))->alpha, 0, 0, 0, 0);
    }
    fclSpriteReset(0x2E2, 0x9E);
    cornerX = 11.0f + origin.x;
    drawPosition1 = fclMakeVec2(cornerX, 13.0f + origin.y);
    if ((s8)mode == 0) {
        fclSpriteCreate(0x2E2, drawPosition1, 14.0f, 0xC1);
        fclSpriteResetScale(0x2E2);
        drawColor5 = fclMakeDrawColor(0, 0, 0, 0xFF);
        p = fclSpriteEntry(0x2E2);
        ((FclCombineRowSprite *)p)->color = drawColor5;
        ((FclCombineRowSprite *)fclSpriteEntry(0x2E2))->alpha = 0x66;
        {
            f32 scale = 1.0f;
        p = fclSpriteEntry(0x2E2);
        ((FclCombineDrawSprite *)p)->scaleY = scale;
        p = fclSpriteEntry(0x2E2);
        ((FclCombineDrawSprite *)p)->scaleX = scale;
        }
        fclSpriteStartAlphaAt(0x2E2, 0, 0x66, 0, 5, 3);
    } else {
        fclSpriteStartAlphaAt(0x2E2, ((FclCombineRowSprite *)fclSpriteEntry(0x2E2))->alpha, 0, 0, 0, 0);
    }
    fclSpriteReset(0x2E3, 0xA0);
    drawPosition1 = fclMakeVec2(cornerX, 306.0f + origin.y);
    if ((s8)mode == 0) {
        fclSpriteCreate(0x2E3, drawPosition1, 14.0f, 0xC1);
        drawColor6 = fclMakeDrawColor(0, 0, 0, 0xFF);
        p = fclSpriteEntry(0x2E3);
        ((FclCombineRowSprite *)p)->color = drawColor6;
        ((FclCombineRowSprite *)fclSpriteEntry(0x2E3))->alpha = 0x66;
        {
            f32 scale = 1.0f;
        p = fclSpriteEntry(0x2E3);
        ((FclCombineDrawSprite *)p)->scaleY = scale;
        p = fclSpriteEntry(0x2E3);
        ((FclCombineDrawSprite *)p)->scaleX = scale;
        }
        fclSpriteStartAlphaAt(0x2E3, 0, 0x66, 0, 5, 3);
        return;
    }
    fclSpriteStartAlphaAt(0x2E3, ((FclCombineRowSprite *)fclSpriteEntry(0x2E3))->alpha, 0, 0, 0, 0);
}
#pragma pop
/* Fcl combine counter: draws the counter value from func_00110140() as a bar (0x2CF) with two
 * labels, the ones digit (0x2D0) always, the tens digit (0x2D1) from 10 up, and sprite 0x10D when
 * the value is 100. mode 0 creates and fades in; any other mode fades out and repositions. */
// FUN_0032B000
void fclCombineDrawCounter(u8 *task, s8 mode) {
    /* The image halfword at offset 4 is accessed without changing the surrounding constructor packet lifetimes. */
    FclDrawColor drawColor1;
    FclVec2 origin;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    FclVec2 drawPosition6;
    FclVec2 drawPosition7;
    FclVec2 drawPosition8;
    FclVec2 drawPosition9;
    FclVec2 drawPosition10;
    FclVec2 drawPosition11;
    FclVec2 drawPosition12;
    FclVec2 drawPosition13;
    FclVec2 drawPosition14;
    FclVec2 drawPosition15;
    f32 rowY;
    s32 entryMode;
    s8 counter;
    u8 *p;
    (void)task;
    drawPosition2 = fclMakeVec2(266.0f, (f32)0x163);
    fclCopyPositionStorage(&origin, &drawPosition2);
    counter = (s8)datGetPersonaCacheCompletionPercent();
    entryMode = (s8)mode;
    if (entryMode == 0) {
        fclSpriteCreate(0x2CF, origin, 215.0f, 0x56);
        drawColor1 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        p = fclSpriteEntry(0x2CF);
        ((FclCombineRowSprite *)p)->color = drawColor1;
        rowY = origin.y;
        drawPosition3 = fclMakeVec2(380.0f + origin.x, rowY);
        drawPosition4 = fclMakeVec2(origin.x, rowY);
        fclSpriteStartPositionAt(0x2CF, drawPosition3, drawPosition4, 1, 0xA, 0);
    } else {
        rowY = origin.y;
        p = fclSpriteEntry(0x2CF);
        drawPosition5 = fclMakeVec2(380.0f + origin.x, rowY);
        fclSpriteStartPositionAt(0x2CF, ((FclCombineRowSprite *)p)->position, drawPosition5, 1, 0xA, 0);
    }
    drawPosition1 = fclMakeVec2(35.0f + origin.x, 11.0f + rowY);
    if (entryMode == 0) {
        fclSpriteCreate(0x119, drawPosition1, 212.0f, 0x57);
        fclSpriteStartAlphaAt(0x119, 0, 0xFF, 0, 0xA, 2);
        drawPosition6 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
        fclSpriteStartPositionAt(0x119, drawPosition6, drawPosition1, 1, 0xA, 2);
    } else {
        fclSpriteStartAlphaAt(0x119, 0xFF, 0, 0, 0xA, 0);
        drawPosition7 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
        fclSpriteStartPositionAt(0x119, drawPosition1, drawPosition7, 1, 0xA, 2);
    }
    drawPosition1 = fclMakeVec2((f32)0x11D + origin.x, 12.0f + rowY);
    if (entryMode == 0) {
        fclSpriteCreate(0x11A, drawPosition1, 213.0f, 0x57);
        fclSpriteStartAlphaAt(0x11A, 0, 0xFF, 0, 0xA, 2);
        drawPosition8 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
        fclSpriteStartPositionAt(0x11A, drawPosition8, drawPosition1, 1, 0xA, 2);
    } else {
        fclSpriteStartAlphaAt(0x11A, 0xFF, 0, 0, 0xA, 0);
        drawPosition9 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
        fclSpriteStartPositionAt(0x11A, drawPosition1, drawPosition9, 1, 0xA, 2);
    }
    rowY = rowY - 3.0f;
    drawPosition1 = fclMakeVec2(247.0f + origin.x, rowY);
    if (entryMode == 0) {
        fclSpriteCreate(0x2D0, drawPosition1, 211.0f, 0x57);
        ((FclCombineRowSprite *)fclSpriteEntry(0x2D0))->image = (s16)(((counter % 10) + 0x10C));
        fclSpriteStartAlphaAt(0x2D0, 0, 0xFF, 0, 0xA, 2);
        drawPosition10 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
        fclSpriteStartPositionAt(0x2D0, drawPosition10, drawPosition1, 1, 0xA, 2);
    } else {
        fclSpriteStartAlphaAt(0x2D0, 0xFF, 0, 0, 0xA, 0);
        drawPosition11 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
        fclSpriteStartPositionAt(0x2D0, drawPosition1, drawPosition11, 1, 0xA, 2);
    }
    if (counter >= 0xA) {
        drawPosition1 = fclMakeVec2(221.0f + origin.x, rowY);
        if (entryMode == 0) {
            fclSpriteCreate(0x2D1, drawPosition1, 211.0f, 0x57);
            ((FclCombineRowSprite *)fclSpriteEntry(0x2D1))->image = (s16)((((s8)(counter / 10) % 10) + 0x10C));
            fclSpriteStartAlphaAt(0x2D1, 0, 0xFF, 0, 0xA, 2);
            drawPosition12 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
            fclSpriteStartPositionAt(0x2D1, drawPosition12, drawPosition1, 1, 0xA, 2);
        } else {
            fclSpriteStartAlphaAt(0x2D1, 0xFF, 0, 0, 0xA, 0);
            drawPosition13 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
            fclSpriteStartPositionAt(0x2D1, drawPosition1, drawPosition13, 1, 0xA, 2);
        }
    }
    if (datGetPersonaCacheCompletionPercent() == 0x64) {
        drawPosition1 = fclMakeVec2(195.0f + origin.x, rowY);
        if (entryMode == 0) {
            fclSpriteCreate(0x10D, drawPosition1, 211.0f, 0x57);
            fclSpriteStartAlphaAt(0x10D, 0, 0xFF, 0, 0xA, 2);
            drawPosition14 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
            fclSpriteStartPositionAt(0x10D, drawPosition14, drawPosition1, 1, 0xA, 2);
            return;
        }
        fclSpriteStartAlphaAt(0x10D, 0xFF, 0, 0, 0xA, 0);
        drawPosition15 = fclMakeVec2(drawPosition1.x, drawPosition1.y - 20.0f);
        fclSpriteStartPositionAt(0x10D, drawPosition1, drawPosition15, 1, 0xA, 2);
    }
}

/* Draw rowCount roster rows with per-row delayStep, then the frame/header and the current window
 * indicators. The loop passes word-sized list indices. */
// FUN_0032B770
void fclCombineDrawRosterRows(u8 *task, s32 delayStep, s32 rowCount, s8 mode)
{
  /* Row spacing is read through an address snapshot and the Y accumulator through a byte offset. */
  float markY;
  f32 *rowStepAddress;
  FclVec2 drawPosition1;
  FclVec2 drawPosition2;
  u8 *frameYAddress;
  FclVec2 drawPosition3;
  f32 indicatorY;
  f32 *rowStepField;
  short yOffset;
  s16 i;
  s32 rowDelayStep;
  s32 visibleRowCount;
  u8 *savedWork;
  s16 shortRowCount;
  s16 *selectionAddress;
  u8 b;
  u8 **workAddress;
  u8 *obj;
  f32 windowStart;
  s16 selectedRow;
  f32 rowStepOrY;
  workAddress = &((struct KwlnTask *)task)->work;
  obj = *workAddress;
  drawPosition1 = fclMakeVec2(156.0f, (float) ((float) 87.0f));
  fclCombineDrawSlotFields(task, drawPosition1, 0, mode, 0, 1, 1);
  i = 0;
  rowDelayStep = (s16) delayStep;
  shortRowCount = (s16) rowCount;
  visibleRowCount = shortRowCount;
  b = (unsigned char) 0xAA;
  while (((s16) i) < visibleRowCount)
  {
    drawPosition2 = fclMakeVec2(162.0f, 111.0);
    ;
    ;
    fclCombineDrawPersonaRow(task, drawPosition2, -1, (s8) i, (((FclCombinePersonaHeader *)yListSlotEntry(0, i))->personaId) & 0xFFFFu, ((FclCombinePersonaHeader *)yListSlotEntry(0, i))->level, (s16) (((s16) i) * rowDelayStep), mode, 0, 0x99);
    i++;
  }

  yOffset = 0x3C;
  selectionAddress = &((FclCombineRowWork *)obj)->cursorRow;
  fclCombineSlideInHeaderSprites(417.0, 220.0f, task, 0, mode);
  savedWork = obj;
  rowStepField = &((FclCombineWork *)obj)->rowSpacing;
  drawPosition3 = fclMakeVec2(472.0f, 112.0f);
  fclCombineDrawSlotFrames(task, drawPosition3, 0, mode);
  windowStart = (selectedRow = *selectionAddress) - (((FclCombineWork *)savedWork)->windowRow);
  rowStepOrY = *rowStepField;
  rowStepAddress = &rowStepOrY;
  frameYAddress = (u8 *)&((FclCombineRowSprite *)fclSpriteEntry(b))->position.y;
  *((f32 *) (fclSpriteEntry(0xB1) + yOffset)) = (rowStepOrY = (*((f32 *) frameYAddress)) + ((*rowStepAddress) * windowStart));
  indicatorY = ((FclCombineRowSprite *)fclSpriteEntry(0xB1))->position.y;
  markY = 52.0f + indicatorY;
  ((FclCombineRowSprite *)fclSpriteEntry(0xB5))->position.y = (rowStepOrY = markY);
}

/* Draw rowCount windowed roster rows with delayStep and mode, highlighting the cursor and updating
 * the header/counter. mode is passed to callees as s8. */
// FUN_0032B9D0
void fclCombineDrawRosterList(u8 *task, s32 delayStep, s32 rowCount, s8 mode) {
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 origin;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    FclVec2 drawPosition6;
    FclVec2 drawPosition7;
    FclVec2 drawPosition8;
    FclVec2 cell;
    FclVec2 drawPosition9;
    FclVec2 drawPosition10;
    u8 *work;
    u8 *rowWork;
    s16 entry;
    s16 row;
    s32 end;
    s32 step;
    f32 y;
    f32 y9;

    work = ((struct KwlnTask *)task)->work;
    drawPosition1 = fclMakeVec2(88.0f, 127.0f);
    fclCombineDrawSlotFields(task, drawPosition1, 0, mode, 0, 1, 3);
    drawPosition4 = fclMakeVec2(390.0f, 127.0f);
    origin = *(FclVec2 *)&drawPosition4;
    drawColor1 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
    fclSpriteStartShowHide(0x21E, origin, 0x193, drawColor1, 191.0f, 0x41, mode, 6, 3, 0, fclCombineGetSpritePool());
    y = origin.y;
    drawPosition5 = fclMakeVec2(151.0f + origin.x, y);
    drawColor2 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
    fclSpriteStartShowHide(0x19D, drawPosition5, 0x19D, drawColor2, 191.0f, 0x41, mode, 6, 3, 0, fclCombineGetSpritePool());
    y9 = 9.0f + y;
    drawPosition6 = fclMakeVec2(24.0f + origin.x, y9);
    drawColor3 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    fclSpriteStartShowHide(0x2AF, drawPosition6, 0x73, drawColor3, 175.0f, 0x56, mode, 6, 3, 0, fclCombineGetSpritePool());
    drawPosition7 = fclMakeVec2(65.0f + origin.x, y9);
    drawColor4 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
    fclSpriteStartShowHide(0x2B0, drawPosition7, 0x73, drawColor4, 175.0f, 0x56, mode, 6, 3, 0, fclCombineGetSpritePool());
    drawPosition8 = fclMakeVec2(119.0f + origin.x, 5.0f + y);
    drawColor5 = fclMakeDrawColor(0x33, 0xCD, 0xFF, 0xFF);
    fclSpriteStartShowHide(0x11D, drawPosition8, 0x11D, drawColor5, 191.0f, 0x56, mode, 6, 3, 0, fclCombineGetSpritePool());
    fclCombineDrawHeaderPanel(task, 0, mode);
    entry = ((FclCombineRowWork *)work)->cursorRow - ((FclCombineWork *)work)->windowRow;
    row = 0;
    step = (s16)delayStep;
    end = (s16)rowCount + entry;
    for (; entry < end; entry++, row++) {
        {
            /* The label point is returned by value into its named slot while
               the row offset is evaluated ahead of the constructor call. */

            fclCombineDrawPersonaRow(task, drawPosition2 = fclMakeVec2(90.0f, 151.0f), -1, row, ((FclCombinePersonaHeader *)yListSlotEntry(0, entry))->personaId, ((FclCombinePersonaHeader *)yListSlotEntry(0, entry))->level, (s16)(row * step), mode, 0, 0x99);
        }
        rowWork = MEMBER(u8 *, task, struct KwlnTask, work);
        drawPosition9 = fclMakeVec2(390.0f, 151.0f);
        cell = *(FclVec2 *)&drawPosition9;
        drawColor7 = fclMakeDrawColor(0, 0, 0x99, 0x80);
        *(FclDrawColor *)&drawColor6 = drawColor7;
        cell.y += (s8)row * 23;
        if (((FclCombineWork *)rowWork)->windowRow == (s8)row) {
            drawColor6 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
        }
        fclSpriteStartShowHide((s8)row + 0x21F, cell, 0x193, drawColor6, 191.0f, 0x41, mode, 6, 3, row * step, fclCombineGetSpritePool());
        drawPosition10 = fclMakeVec2(132.0f + cell.x, cell.y);
        fclSpriteStartShowHide((s8)row + 0x2C5, drawPosition10, 0x19E, drawColor6, 191.0f, 0x41, mode, 6, 3, row * step, fclCombineGetSpritePool());
    }
    drawPosition3 = fclMakeVec2(535, 154.0f);
    fclCombineDrawSlotFrames(task, drawPosition3, 0, mode);
    ((FclCombineRowSprite *)fclSpriteEntry(0xB1))->position.y = ((FclCombineWork *)work)->rowSpacing * (MEMBER(s16, work, FclCombineRowWork, cursorRow) - MEMBER(s16, work, FclCombineWork, windowRow)) + ((FclCombineRowSprite *)fclSpriteEntry(0xAA))->position.y;
    ((FclCombineRowSprite *)fclSpriteEntry(0xB5))->position.y = 52.0f + ((FclCombineRowSprite *)fclSpriteEntry(0xB1))->position.y;
    fclCombineSlideInHeaderSprites(359, 300.0f, task, 1, mode);
    fclCombineDrawCounter(task, mode);
}

/* The switch emits an extra anonymous jump table next to retail's six-entry table, so a linked-
 * image difference in this file likely starts here. Move the roster cursor for command, retaining
 * the visible window and repositioning its two indicators. */
// FUN_0032C0C0
void fclCombineMoveRosterCursor(u8 *task, s64 command) {
    /* measured: typing the remaining cursor fields as struct members changes the generated code. */
    f32 fdiff;
    f32 facc;
    s16 r;
    s32 nextRow;
    u8 *obj;

    obj = ((struct KwlnTask *)task)->work;
    r = 8;
    if (((FclCombinePersonaListHeader *)yListSlotWork(0))->count < 8) {
        r = *(s16*)&((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
    }
    ((FclCombineWork *)obj)->redrawRequested = 1;
    switch ((s8)command) {
    case 0:
        ((FclCombineRowWork *)obj)->cursorRow = fclAddClamped(MEMBER(s16, obj, FclCombineRowWork, cursorRow), 1, (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), 0, 1);
        ((FclCombineWork *)obj)->windowRow = yListStepIndex(MEMBER(s16, obj, FclCombineRowWork, cursorRow), MEMBER(s16, obj, FclCombineWork, windowRow), (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), r, 1);
        break;
    case 1:
        ((FclCombineRowWork *)obj)->cursorRow = fclSubClamped(MEMBER(s16, obj, FclCombineRowWork, cursorRow), 1, 0, 0, 1);
        {
        s16 count = *(s16*)&((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
        ((FclCombineWork *)obj)->windowRow = yListStepIndex(MEMBER(s16, obj, FclCombineRowWork, cursorRow), MEMBER(s16, obj, FclCombineWork, windowRow), count, r, -1);
        }
        break;
    case 2:
        yListAdvanceCursorScroll(((FclCombineRowWork *)obj)->cursorRow, ((FclCombineWork *)obj)->windowRow, ((FclCombinePersonaListHeader *)yListSlotWork(0))->count, 8, &MEMBER(s16, obj, FclCombineRowWork, cursorRow), &MEMBER(s16, obj, FclCombineWork, windowRow));
        break;
    case 3:
        yListRetreatCursorScroll(((FclCombineRowWork *)obj)->cursorRow, ((FclCombineWork *)obj)->windowRow, ((FclCombinePersonaListHeader *)yListSlotWork(0))->count, 8, &MEMBER(s16, obj, FclCombineRowWork, cursorRow), &MEMBER(s16, obj, FclCombineWork, windowRow));
        break;
    case 4:
        nextRow = fclAddClamped(((FclCombineRowWork *)obj)->cursorRow, 1, (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), 0, 2);
        MEMBER(u16, obj, FclCombineRowWork, cursorRow) = (u16)nextRow;
        if ((s16)nextRow == 0) {
            ((FclCombineWork *)obj)->windowRow = 0;
        } else {
            ((FclCombineWork *)obj)->windowRow = yListStepIndex(MEMBER(s16, obj, FclCombineRowWork, cursorRow), MEMBER(s16, obj, FclCombineWork, windowRow), (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), r, 1);
        }
        break;
    case 5:
        if (((FclCombineRowWork *)obj)->cursorRow == 0) {
            MEMBER(s16, obj, FclCombineRowWork, cursorRow) = fclSubClamped(MEMBER(s16, obj, FclCombineRowWork, cursorRow), 1, 0, (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), 2);
            ((FclCombineWork *)obj)->windowRow = (s16)((s16)r - 1);
        } else {
            MEMBER(s16, obj, FclCombineRowWork, cursorRow) = fclSubClamped(MEMBER(s16, obj, FclCombineRowWork, cursorRow), 1, 0, (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), 2);
            ((FclCombineWork *)obj)->windowRow = yListStepIndex(MEMBER(s16, obj, FclCombineRowWork, cursorRow), MEMBER(s16, obj, FclCombineWork, windowRow), (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), r, -1);
        }
        break;
    }
    fdiff = (f32)(((FclCombineRowWork *)obj)->cursorRow - ((FclCombineWork *)obj)->windowRow);
    facc = ((FclCombineWork *)obj)->rowSpacing;
    facc = 0.0f + ((FclCombineRowSprite *)fclSpriteEntry(0xAA))->position.y + facc * fdiff;
    ((FclCombineRowSprite *)fclSpriteEntry(0xB1))->position.y = facc;
    facc = 52.0f + ((FclCombineRowSprite *)fclSpriteEntry(0xB1))->position.y;
    ((FclCombineRowSprite *)fclSpriteEntry(0xB5))->position.y = facc;
}

typedef struct {
    u8 pad00[0x11E];
    s16 selection;
    u8 pad120[0x28];
    u8 *draw;
    u8 pad14C[0x108];
    u8 *model;
} FclCombineModelWork;

/* Retrieve the persona handle from the draw task work area. measured: inlining the nested
 * work/handle load at the call site changes the caller's code. */
static inline u8 *fclDrawPersonaTask(u8 *draw)
{
    return (u8 *)((FclPersonaDrawWork *)((struct KwlnTask *)draw)->work)->personaHandle;
}

/* Draws the selected persona's name and arcana, and loads its model. */
// FUN_0032C480
void fclCombineDrawSelectedName(u8 *task)
{
    FclVec2 drawPosition1;
    FclCombineModelWork *obj;
    s32 n;

    obj = (FclCombineModelWork *)((struct KwlnTask *)task)->work;
    frFontExDrawTextDeferredOutB(140.0f, 101.0f, 1.0f, fclPackRgba(0, 0, 0, 0xFF), 0, 2,
        (const char *)((u8 *)iGpffffb440 + ((FclCombinePersonaHeader *)yListSlotEntry(0, obj->selection))->personaId * 0x11),
        0, 0, D_00796310, 0x15);
    n = (s16)((datPersonaGetArcana(((FclCombinePersonaHeader *)yListSlotEntry(0, obj->selection))->personaId) & 0xFF) + 0x1B);
    drawPosition1 = fclMakeVec2(54.0f, 103.0f);
    fclCombineDrawResourceAt(n, drawPosition1, 1.0f, 0xFF000000, 0xFF, 1, 1.0f, 1.0f, D_00796310);
    n = (s16)fclCombineGetRowCount();
    itfMesWindowQueueEntry(54.0f, 138.0f, 1.0f, -1, 1, 0, 1, n,
        ((FclCombinePersonaHeader *)yListSlotEntry(0, obj->selection))->personaId, D_00796370);
    fclCombineSetModel((s32)obj->model, ((FclCombinePersonaHeader *)yListSlotEntry(0, obj->selection))->personaId, 1);
    ((FclCombineModelState *)(fclCombineGetWork(obj->model)))->unk1 = 0;
    shdPersonaSetOpacity(fclDrawPersonaTask(obj->draw), 64000.0f);
}

/* Slides column slot's panel (0 or 1) in when mode is 1, otherwise out to origin or hiddenPosition
 * and fades its frame sprites. The upper row snapshots each position before its state change; the
 * lower row reads it afterward. */
// FUN_0032C660
void fclCombineSlidePanelColumn(u8 *task, s32 slot, FclVec2 shownPosition, FclVec2 hiddenPosition, s32 mode, s32 useHiddenPosition) {
    /* measured: retail generates clipTasks addresses from byte-table bases, not member indexing. */
    f32 travelDistance = 600.0f;
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclDrawColor drawColor7;
    FclDrawColor drawColor8;
    FclDrawColor drawColor9;
    FclDrawColor drawColor10;
    FclDrawColor drawColor11;
    FclDrawColor drawColor12;
    FclVec2 origin;
    FclVec2 drawPosition1;
    FclVec2 constructedOrigin;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    FclVec2 drawPosition6;
    FclVec2 drawPosition7;
    FclVec2 drawPosition8;
    FclVec2 drawPosition9;
    FclVec2 drawPosition10;
    FclVec2 drawPosition11;
    FclVec2 drawPosition12;
    FclVec2 drawPosition13;
    FclVec2 drawPosition14;
    FclVec2 drawPosition15;
    FclVec2 drawPosition16;
    FclVec2 drawPosition17;
    FclVec2 drawPosition18;
    FclVec2 drawPosition19;
    FclVec2 drawPosition20;
    FclVec2 drawPosition21;
    FclVec2 drawPosition22;
    FclVec2 drawPosition23;
    FclVec2 drawPosition24;
    FclVec2 drawPosition25;
    FclVec2 drawPosition26;
    FclVec2 drawPosition27;
    FclVec2 drawPosition28;
    FclVec2 drawPosition29;
    FclVec2 drawPosition30;
    FclVec2 drawPosition31;
    FclVec2 drawPosition32;
    FclVec2 drawPosition33;
    FclVec2 drawPosition34;
    FclVec2 drawPosition35;
    FclVec2 drawPosition36;
    FclVec2 drawPosition37;
    FclVec2 drawPosition38;
    FclVec2 drawPosition39;
    FclVec2 drawPosition40;
    FclVec2 drawPosition41;
    FclVec2 drawPosition42;
    FclVec2 drawPosition43;
    FclVec2 drawPosition44;
    FclVec2 drawPosition45;
    FclVec2 drawPosition46;
    FclVec2 drawPosition47;
    FclVec2 drawPosition48;
    FclVec2 drawPosition49;
    FclVec2 drawPosition50;
    FclVec2 drawPosition51;
    FclVec2 drawPosition52;
    FclVec2 drawPosition53;
    FclVec2 drawPosition54;
    FclVec2 drawPosition55;
    FclVec2 drawPosition56;
    FclVec2 drawPosition57;
    FclVec2 drawPosition58;
    FclVec2 drawPosition59;
    FclVec2 drawPosition60;
    FclVec2 drawPosition61;
    FclVec2 drawPosition62;
    FclVec2 drawPosition63;
    FclVec2 drawPosition64;
    FclVec2 drawPosition65;
    FclVec2 drawPosition66;
    FclVec2 drawPosition67;
    FclVec2 drawPosition68;
    FclVec2 drawPosition69;
    FclVec2 drawPosition70;
    FclBoundsPacket boundsPacket1;
    FclBoundsPacket boundsPacket2;
    s16 upperFrameLeftSprite;
    s16 lowerLabelRightSprite;
    s16 lowerIconSprite;
    s16 lowerClipSprite;
    s16 upperFrameRightSprite;
    s16 upperLabelLeftSprite;
    s16 upperLabelRightSprite;
    s16 upperIconSprite;
    s16 upperClipSprite;
    s16 lowerFrameLeftSprite;
    s16 lowerFrameRightSprite;
    s16 lowerLabelLeftSprite;
    u8 *work;
    s64 showing;
    s64 column;
    s64 upperOrder;
    s64 lowerOrder;
    u8 *lowerClipResource;
    u8 *upperClipResource;
    u8 *upperFrameLeftEntryPosition;
    u8 *upperIconEntryColor;
    u8 *upperClipEntryPosition;
    u8 *upperClipEntryColor;
    u8 *upperClipPositionWork;
    u8 *upperClipBoundsWork;
    u8 *lowerFrameLeftEntryColor;
    u8 *lowerFrameLeftEntryPosition;
    u8 *lowerFrameRightEntryColor;
    u8 *lowerFrameRightEntryPosition;
    u8 *lowerLabelLeftEntryColor;
    u8 *lowerLabelLeftEntryPosition;
    u8 *lowerLabelRightEntryColor;
    u8 *lowerLabelRightEntryPosition;
    u8 *lowerIconEntryColor;
    u8 *lowerIconEntryPosition;
    u8 *lowerClipEntryColor;
    u8 *lowerClipEntryPosition;
    u8 *lowerClipPositionWork;
    u8 *upperFrameLeftEntryColor;
    u8 *lowerClipBoundsWork;
    u8 *upperFrameRightEntryPosition;
    u8 *upperFrameRightEntryColor;
    u8 *upperLabelLeftEntryPosition;
    u8 *upperLabelLeftEntryColor;
    u8 *upperLabelRightEntryPosition;
    u8 *upperLabelRightEntryColor;
    u8 *upperIconEntryPosition;
    u8 **upperClipSlot;
    u8 **lowerClipSlot;

    work = ((struct KwlnTask *)task)->work;
    constructedOrigin = fclMakeVec2(57.0f, 72.0f);
    fclCopyPositionStorage(&origin, &constructedOrigin);
    upperOrder = 0x66;
    column = (s8)slot;
    if (column == 1) {
        upperOrder = 0x70;
    }
    upperFrameLeftSprite = 0x1CA;
    if (column == 1) {
        upperFrameLeftSprite = 0x2E4;
    }
    fclSpriteReset(upperFrameLeftSprite, 0x1CA);
    upperFrameLeftEntryPosition = fclSpriteEntry(upperFrameLeftSprite);
    drawPosition1 = ((FclCombineRowSprite *)upperFrameLeftEntryPosition)->position;
    showing = (s8)mode;
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(upperFrameLeftSprite))->flags = 0;
        fclSpriteCreate((s16)(upperFrameLeftSprite), origin, 112.0f, (s16)upperOrder + 2);
        drawColor1 = fclMakeDrawColor(0x38, 0, 0x99, 0xFF);
        upperFrameLeftEntryColor = fclSpriteEntry(upperFrameLeftSprite);
        ((FclCombineRowSprite *)upperFrameLeftEntryColor)->color = drawColor1;
        fclSpriteResetScale(upperFrameLeftSprite);
        drawPosition2 = fclMakeVec2(origin.x + travelDistance, origin.y);
        fclSpriteStartPositionAt(upperFrameLeftSprite, drawPosition2, shownPosition, 0U, 0xAU, 0);
    } else {
        fclSpriteSetFlag(upperFrameLeftSprite, 0, 0);
        if ((s8)useHiddenPosition == 0) {
            fclSpriteStartPositionAt(upperFrameLeftSprite, drawPosition1, origin, 0U, 4U, 0);
        } else {
            fclSpriteStartPositionAt(upperFrameLeftSprite, drawPosition1, hiddenPosition, 0U, 4U, 0);
        }
    }
    upperFrameRightSprite = 0x1CB;
    if (column == 1) {
        upperFrameRightSprite = 0x2E5;
    }
    fclSpriteReset(upperFrameRightSprite, 0x1CB);
    upperFrameRightEntryPosition = fclSpriteEntry(upperFrameRightSprite);
    drawPosition70 = ((FclCombineRowSprite *)upperFrameRightEntryPosition)->position;
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(upperFrameRightSprite))->flags = 0;
        drawPosition3 = fclMakeVec2((f32) 0x183 + origin.x, origin.y);
        fclSpriteCreate((s16)(upperFrameRightSprite), drawPosition3, 113.0f, (s16)upperOrder + 2);
        drawColor2 = fclMakeDrawColor(0x38, 0, 0x99, 0xFF);
        upperFrameRightEntryColor = fclSpriteEntry(upperFrameRightSprite);
        ((FclCombineRowSprite *)upperFrameRightEntryColor)->color = drawColor2;
        fclSpriteResetScale(upperFrameRightSprite);
        drawPosition4 = fclMakeVec2((f32) 0x183 + origin.x + travelDistance, origin.y);
        drawPosition5 = fclMakeVec2((f32) 0x183 + shownPosition.x, shownPosition.y);
        fclSpriteStartPositionAt(upperFrameRightSprite, drawPosition4, drawPosition5, 0U, 0xAU, 0);
    } else {
        fclSpriteSetFlag(upperFrameRightSprite, 0, 0);
        if ((s8)useHiddenPosition == 0) {
            drawPosition6 = fclMakeVec2((f32) 0x183 + origin.x, origin.y);
            fclSpriteStartPositionAt(upperFrameRightSprite, drawPosition70, drawPosition6, 0U, 4U, 0);
        } else {
            drawPosition7 = fclMakeVec2((f32) 0x183 + hiddenPosition.x, hiddenPosition.y);
            fclSpriteStartPositionAt(upperFrameRightSprite, drawPosition70, drawPosition7, 0U, 4U, 0);
        }
    }
    upperLabelLeftSprite = 0x1CC;
    if (column == 1) {
        upperLabelLeftSprite = 0x2E6;
    }
    fclSpriteReset(upperLabelLeftSprite, 0x1CC);
    upperLabelLeftEntryPosition = fclSpriteEntry(upperLabelLeftSprite);
    drawPosition69 = ((FclCombineRowSprite *)upperLabelLeftEntryPosition)->position;
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(upperLabelLeftSprite))->flags = 0;
        drawPosition8 = fclMakeVec2(70.0f + origin.x, 6.0f + origin.y);
        fclSpriteCreate((s16)(upperLabelLeftSprite), drawPosition8, 108.0f, 0x56);
        drawColor3 = fclMakeDrawColor(0x26, 0, 0x66, 0xFF);
        upperLabelLeftEntryColor = fclSpriteEntry(upperLabelLeftSprite);
        ((FclCombineRowSprite *)upperLabelLeftEntryColor)->color = drawColor3;
        fclSpriteResetScale(upperLabelLeftSprite);
        drawPosition9 = fclMakeVec2(70.0f + origin.x + travelDistance, 6.0f + origin.y);
        drawPosition10 = fclMakeVec2(70.0f + shownPosition.x, 6.0f + shownPosition.y);
        fclSpriteStartPositionAt(upperLabelLeftSprite, drawPosition9, drawPosition10, 0U, 0xAU, 0);
    } else {
        fclSpriteSetFlag(upperLabelLeftSprite, 0, 0);
        if ((s8)useHiddenPosition == 0) {
            drawPosition11 = fclMakeVec2(70.0f + origin.x, 6.0f + origin.y);
            fclSpriteStartPositionAt(upperLabelLeftSprite, drawPosition69, drawPosition11, 0U, 4U, 0);
        } else {
            drawPosition12 = fclMakeVec2(70.0f + hiddenPosition.x, 6.0f + hiddenPosition.y);
            fclSpriteStartPositionAt(upperLabelLeftSprite, drawPosition69, drawPosition12, 0U, 4U, 0);
        }
    }
    upperLabelRightSprite = 0x1CD;
    if (column == 1) {
        upperLabelRightSprite = 0x2E7;
    }
    fclSpriteReset(upperLabelRightSprite, 0x1CD);
    upperLabelRightEntryPosition = fclSpriteEntry(upperLabelRightSprite);
    drawPosition68 = ((FclCombineRowSprite *)upperLabelRightEntryPosition)->position;
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(upperLabelRightSprite))->flags = 0;
        drawPosition13 = fclMakeVec2(382.0f + origin.x, 6.0f + origin.y);
        fclSpriteCreate((s16)(upperLabelRightSprite), drawPosition13, 109.0f, 0x56);
        drawColor4 = fclMakeDrawColor(0x26, 0, 0x66, 0xFF);
        upperLabelRightEntryColor = fclSpriteEntry(upperLabelRightSprite);
        ((FclCombineRowSprite *)upperLabelRightEntryColor)->color = drawColor4;
        fclSpriteResetScale(upperLabelRightSprite);
        drawPosition14 = fclMakeVec2(382.0f + origin.x + travelDistance, 6.0f + origin.y);
        drawPosition15 = fclMakeVec2(382.0f + shownPosition.x, 6.0f + shownPosition.y);
        fclSpriteStartPositionAt(upperLabelRightSprite, drawPosition14, drawPosition15, 0U, 0xAU, 0);
    } else {
        fclSpriteSetFlag(upperLabelRightSprite, 0, 0);
        if ((s8)useHiddenPosition == 0) {
            drawPosition16 = fclMakeVec2(382.0f + origin.x, 6.0f + origin.y);
            fclSpriteStartPositionAt(upperLabelRightSprite, drawPosition68, drawPosition16, 0U, 4U, 0);
        } else {
            drawPosition17 = fclMakeVec2(382.0f + hiddenPosition.x, 6.0f + hiddenPosition.y);
            fclSpriteStartPositionAt(upperLabelRightSprite, drawPosition68, drawPosition17, 0U, 4U, 0);
        }
    }
    upperIconSprite = 0x1D6;
    if (column == 1) {
        upperIconSprite = 0x2E8;
    }
    fclSpriteReset(upperIconSprite, 0x1D6);
    upperIconEntryPosition = fclSpriteEntry(upperIconSprite);
    drawPosition67 = ((FclCombineRowSprite *)upperIconEntryPosition)->position;
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(upperIconSprite))->flags = 0;
        drawPosition18 = fclMakeVec2(8.0f + origin.x, 8.0f + origin.y);
        fclSpriteCreate((s16)(upperIconSprite), drawPosition18, 107.0f, (s16)upperOrder + 4);
        drawColor5 = fclMakeDrawColor(0x95, 0x7C, 0xFF, 0xFF);
        upperIconEntryColor = fclSpriteEntry(upperIconSprite);
        ((FclCombineRowSprite *)upperIconEntryColor)->color = drawColor5;
        fclSpriteResetScale(upperIconSprite);
        drawPosition19 = fclMakeVec2(8.0f + origin.x + travelDistance, 6.0f + origin.y);
        drawPosition20 = fclMakeVec2(8.0f + shownPosition.x, 8.0f + shownPosition.y);
        fclSpriteStartPositionAt(upperIconSprite, drawPosition19, drawPosition20, 0U, 0xAU, 0);
        if (column == 1) {
            ((FclCombineRowSprite *)fclSpriteEntry(upperIconSprite))->alpha = 0;
        }
    } else {
        fclSpriteSetFlag(upperIconSprite, 0, 0);
        if ((s8)useHiddenPosition == 0) {
            drawPosition21 = fclMakeVec2(8.0f + origin.x, 8.0f + origin.y);
            fclSpriteStartPositionAt(upperIconSprite, drawPosition67, drawPosition21, 0U, 4U, 0);
            fclSpriteStartAlphaAt(upperIconSprite, 0U, 0xFFU, 0, 4, 0);
        } else {
            drawPosition22 = fclMakeVec2(8.0f + hiddenPosition.x, 8.0f + hiddenPosition.y);
            fclSpriteStartPositionAt(upperIconSprite, drawPosition67, drawPosition22, 0U, 4U, 0);
            fclSpriteStartAlphaAt(upperIconSprite, 0xFFU, 0U, 0, 4, 0);
        }
    }
    upperClipSprite = 0x2E3;
    if (column == 1) {
        upperClipSprite = 0x2E9;
    }
    fclSpriteReset(upperClipSprite, 0x80);
    upperClipEntryPosition = fclSpriteEntry(upperClipSprite);
    drawPosition66 = ((FclCombineRowSprite *)upperClipEntryPosition)->position;
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(upperClipSprite))->flags = 0;
        drawPosition23 = fclMakeVec2((origin.x - 120.0f) + travelDistance, origin.y - 40.0f);
        fclSpriteCreate((s16)(upperClipSprite), drawPosition23, 111.0f, (s16)upperOrder + 3);
        drawColor6 = fclMakeDrawColor(0x18, 2, 0x67, 0xFF);
        upperClipEntryColor = fclSpriteEntry(upperClipSprite);
        ((FclCombineRowSprite *)upperClipEntryColor)->color = drawColor6;
        drawPosition24 = fclMakeVec2((origin.x - 120.0f) + travelDistance, origin.y - 40.0f);
        drawPosition25 = fclMakeVec2(shownPosition.x - 120.0f, shownPosition.y - 40.0f);
        fclSpriteStartPositionAt(upperClipSprite, drawPosition24, drawPosition25, 0U, 0xAU, 0);
        fclSpriteResetScale(upperClipSprite);
        fclSpriteSetFlag(upperClipSprite, 0xE, 0);
    } else {
        fclSpriteSetFlag(upperClipSprite, 0, 0);
        fclSpriteSetFlag(upperClipSprite, 0xE, 0);
        if ((s8)useHiddenPosition == 0) {
            drawPosition26 = fclMakeVec2(origin.x - 120.0f, origin.y - 40.0f);
            fclSpriteStartPositionAt(upperClipSprite, drawPosition66, drawPosition26, 0U, 4U, 0);
        } else {
            drawPosition27 = fclMakeVec2(hiddenPosition.x - 120.0f, hiddenPosition.y - 40.0f);
            fclSpriteStartPositionAt(upperClipSprite, drawPosition66, drawPosition27, 0U, 4U, 0);
        }
    }
    if (showing == 1) {
        upperClipResource = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x80U);
        upperClipSlot = (u8 **)(work + 0x258) + (s8)(u32)slot * 2;
        drawPosition28 = fclMakeVec2(shownPosition.x - 120.0f, shownPosition.y - 40.0f);
        upperClipPositionWork = fclSpriteWork(*upperClipSlot);
        *(FclVec2 *)upperClipPositionWork = drawPosition28;
        boundsPacket1 = fclMakeBoundsPacket(250.0f, 250.0f);
        upperClipBoundsWork = fclSpriteWork(*upperClipSlot);
        ((FclBoundsPacket *)(upperClipBoundsWork + 8))->representation = boundsPacket1.representation;
        ((FclCombineClipWork *)fclSpriteWork(*upperClipSlot))->order = (s32) (s16)upperOrder;
        ((FclCombineClipWork *)fclSpriteWork(*upperClipSlot))->depth = 110.0f;
        ((FclCombineClipWork *)fclSpriteWork(*upperClipSlot))->unk124 = 0;
        sdkSpriteFreeNode(upperClipResource);
    }
    origin = fclMakeVec2(origin.x, 99.0f + origin.y);
    lowerOrder = 0x6B;
    if (column == 1) {
        lowerOrder = 0x75;
    }
    lowerFrameLeftSprite = 0x1CE;
    if (column == 1) {
        lowerFrameLeftSprite = 0x2EA;
    }
    fclSpriteReset(lowerFrameLeftSprite, 0x1CE);
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(lowerFrameLeftSprite))->flags = 0;
        drawPosition29 = fclMakeVec2(origin.x + travelDistance, origin.y);
        fclSpriteCreate((s16)(lowerFrameLeftSprite), drawPosition29, 112.0f, (s16)lowerOrder + 2);
        drawColor7 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
        lowerFrameLeftEntryColor = fclSpriteEntry(lowerFrameLeftSprite);
        ((FclCombineRowSprite *)lowerFrameLeftEntryColor)->color = drawColor7;
        drawPosition30 = fclMakeVec2(origin.x + travelDistance, origin.y);
        drawPosition31 = fclMakeVec2(shownPosition.x, 99.0f + shownPosition.y);
        fclSpriteStartPositionAt(lowerFrameLeftSprite, drawPosition30, drawPosition31, 0U, 0xAU, 0);
        fclSpriteResetScale(lowerFrameLeftSprite);
    } else {
        fclSpriteSetFlag(lowerFrameLeftSprite, 0, 0);
        lowerFrameLeftEntryPosition = fclSpriteEntry(lowerFrameLeftSprite);
        drawPosition65 = ((FclCombineRowSprite *)lowerFrameLeftEntryPosition)->position;
        if ((s8)useHiddenPosition == 0) {
            drawPosition32 = fclMakeVec2(origin.x, origin.y);
            fclSpriteStartPositionAt(lowerFrameLeftSprite, drawPosition65, drawPosition32, 0U, 4U, 0);
        } else {
            drawPosition33 = fclMakeVec2(hiddenPosition.x, 99.0f + hiddenPosition.y);
            fclSpriteStartPositionAt(lowerFrameLeftSprite, drawPosition65, drawPosition33, 0U, 4U, 0);
        }
    }
    lowerFrameRightSprite = 0x1CF;
    if (column == 1) {
        lowerFrameRightSprite = 0x2EB;
    }
    fclSpriteReset(lowerFrameRightSprite, 0x1CF);
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(lowerFrameRightSprite))->flags = 0;
        drawPosition34 = fclMakeVec2((f32) 0x183 + origin.x + travelDistance, origin.y);
        fclSpriteCreate((s16)(lowerFrameRightSprite), drawPosition34, 113.0f, (s16)lowerOrder + 2);
        drawColor8 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
        lowerFrameRightEntryColor = fclSpriteEntry(lowerFrameRightSprite);
        ((FclCombineRowSprite *)lowerFrameRightEntryColor)->color = drawColor8;
        drawPosition35 = fclMakeVec2((f32) 0x183 + origin.x + travelDistance, origin.y);
        drawPosition36 = fclMakeVec2((f32) 0x183 + shownPosition.x, 99.0f + shownPosition.y);
        fclSpriteStartPositionAt(lowerFrameRightSprite, drawPosition35, drawPosition36, 0U, 0xAU, 0);
        fclSpriteResetScale(lowerFrameRightSprite);
    } else {
        fclSpriteSetFlag(lowerFrameRightSprite, 0, 0);
        lowerFrameRightEntryPosition = fclSpriteEntry(lowerFrameRightSprite);
        drawPosition64 = ((FclCombineRowSprite *)lowerFrameRightEntryPosition)->position;
        if ((s8)useHiddenPosition == 0) {
            drawPosition37 = fclMakeVec2((f32) 0x183 + origin.x, origin.y);
            fclSpriteStartPositionAt(lowerFrameRightSprite, drawPosition64, drawPosition37, 0U, 4U, 0);
        } else {
            drawPosition38 = fclMakeVec2((f32) 0x183 + hiddenPosition.x, 99.0f + hiddenPosition.y);
            fclSpriteStartPositionAt(lowerFrameRightSprite, drawPosition64, drawPosition38, 0U, 4U, 0);
        }
    }
    lowerLabelLeftSprite = 0x1D0;
    if (column == 1) {
        lowerLabelLeftSprite = 0x2EC;
    }
    fclSpriteReset(lowerLabelLeftSprite, 0x1D0);
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(lowerLabelLeftSprite))->flags = 0;
        drawPosition39 = fclMakeVec2(70.0f + origin.x + travelDistance, 6.0f + origin.y);
        fclSpriteCreate((s16)(lowerLabelLeftSprite), drawPosition39, 108.0f, 0x56);
        drawColor9 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
        lowerLabelLeftEntryColor = fclSpriteEntry(lowerLabelLeftSprite);
        ((FclCombineRowSprite *)lowerLabelLeftEntryColor)->color = drawColor9;
        drawPosition40 = fclMakeVec2(70.0f + origin.x + travelDistance, 6.0f + origin.y);
        drawPosition41 = fclMakeVec2(70.0f + shownPosition.x, 99.0f + (6.0f + shownPosition.y));
        fclSpriteStartPositionAt(lowerLabelLeftSprite, drawPosition40, drawPosition41, 0U, 0xAU, 0);
        fclSpriteResetScale(lowerLabelLeftSprite);
    } else {
        fclSpriteSetFlag(lowerLabelLeftSprite, 0, 0);
        lowerLabelLeftEntryPosition = fclSpriteEntry(lowerLabelLeftSprite);
        drawPosition63 = ((FclCombineRowSprite *)lowerLabelLeftEntryPosition)->position;
        if ((s8)useHiddenPosition == 0) {
            drawPosition42 = fclMakeVec2(70.0f + origin.x, 6.0f + origin.y);
            fclSpriteStartPositionAt(lowerLabelLeftSprite, drawPosition63, drawPosition42, 0U, 4U, 0);
        } else {
            drawPosition43 = fclMakeVec2(70.0f + hiddenPosition.x, 99.0f + (6.0f + hiddenPosition.y));
            fclSpriteStartPositionAt(lowerLabelLeftSprite, drawPosition63, drawPosition43, 0U, 4U, 0);
        }
    }
    lowerLabelRightSprite = 0x1D1;
    if (column == 1) {
        lowerLabelRightSprite = 0x2ED;
    }
    fclSpriteReset(lowerLabelRightSprite, 0x1D1);
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(lowerLabelRightSprite))->flags = 0;
        drawPosition44 = fclMakeVec2(382.0f + origin.x + travelDistance, 6.0f + origin.y);
        fclSpriteCreate((s16)(lowerLabelRightSprite), drawPosition44, 109.0f, 0x56);
        drawColor10 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
        lowerLabelRightEntryColor = fclSpriteEntry(lowerLabelRightSprite);
        ((FclCombineRowSprite *)lowerLabelRightEntryColor)->color = drawColor10;
        drawPosition45 = fclMakeVec2(382.0f + origin.x + travelDistance, 6.0f + origin.y);
        drawPosition46 = fclMakeVec2(382.0f + shownPosition.x, 99.0f + (6.0f + shownPosition.y));
        fclSpriteStartPositionAt(lowerLabelRightSprite, drawPosition45, drawPosition46, 0U, 0xAU, 0);
        fclSpriteResetScale(lowerLabelRightSprite);
    } else {
        fclSpriteSetFlag(lowerLabelRightSprite, 0, 0);
        lowerLabelRightEntryPosition = fclSpriteEntry(lowerLabelRightSprite);
        drawPosition62 = ((FclCombineRowSprite *)lowerLabelRightEntryPosition)->position;
        if ((s8)useHiddenPosition == 0) {
            drawPosition47 = fclMakeVec2(382.0f + origin.x, 6.0f + origin.y);
            fclSpriteStartPositionAt(lowerLabelRightSprite, drawPosition62, drawPosition47, 0U, 4U, 0);
        } else {
            drawPosition48 = fclMakeVec2(382.0f + hiddenPosition.x, 99.0f + (6.0f + hiddenPosition.y));
            fclSpriteStartPositionAt(lowerLabelRightSprite, drawPosition62, drawPosition48, 0U, 4U, 0);
        }
    }
    lowerIconSprite = 0x1D7;
    if (column == 1) {
        lowerIconSprite = 0x2EE;
    }
    fclSpriteReset(lowerIconSprite, 0x1D7);
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(lowerIconSprite))->flags = 0;
        drawPosition49 = fclMakeVec2(8.0f + origin.x + travelDistance, 8.0f + origin.y);
        fclSpriteCreate((s16)(lowerIconSprite), drawPosition49, 107.0f, (s16)lowerOrder + 4);
        drawColor11 = fclMakeDrawColor(0x95, 0x7C, 0xFF, 0xFF);
        lowerIconEntryColor = fclSpriteEntry(lowerIconSprite);
        ((FclCombineRowSprite *)lowerIconEntryColor)->color = drawColor11;
        drawPosition50 = fclMakeVec2(8.0f + origin.x + travelDistance, 8.0f + origin.y);
        drawPosition51 = fclMakeVec2(8.0f + shownPosition.x, 99.0f + (8.0f + shownPosition.y));
        fclSpriteStartPositionAt(lowerIconSprite, drawPosition50, drawPosition51, 0U, 0xAU, 0);
        fclSpriteResetScale(lowerIconSprite);
        if (column == 1) {
            ((FclCombineRowSprite *)fclSpriteEntry(lowerIconSprite))->alpha = 0;
        }
    } else {
        fclSpriteSetFlag(lowerIconSprite, 0, 0);
        lowerIconEntryPosition = fclSpriteEntry(lowerIconSprite);
        drawPosition61 = ((FclCombineRowSprite *)lowerIconEntryPosition)->position;
        if ((s8)useHiddenPosition == 0) {
            drawPosition52 = fclMakeVec2(8.0f + origin.x, 8.0f + origin.y);
            fclSpriteStartPositionAt(lowerIconSprite, drawPosition61, drawPosition52, 0U, 4U, 0);
            fclSpriteStartAlphaAt(lowerIconSprite, 0U, 0xFFU, 0, 4, 0);
        } else {
            drawPosition53 = fclMakeVec2(8.0f + hiddenPosition.x, 99.0f + (8.0f + hiddenPosition.y));
            fclSpriteStartPositionAt(lowerIconSprite, drawPosition61, drawPosition53, 0U, 4U, 0);
            fclSpriteStartAlphaAt(lowerIconSprite, 0xFFU, 0U, 0, 4, 0);
        }
    }
    lowerClipSprite = 0x2E2;
    if (column == 1) {
        lowerClipSprite = 0x2EF;
    }
    fclSpriteReset(lowerClipSprite, 0x80);
    if (showing == 1) {
        ((FclCombineRowSprite *)fclSpriteEntry(lowerClipSprite))->flags = 0;
        drawPosition54 = fclMakeVec2((origin.x - 120.0f) + travelDistance, origin.y - 27.0f);
        fclSpriteCreate((s16)(lowerClipSprite), drawPosition54, 111.0f, (s16)lowerOrder + 3);
        drawColor12 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
        lowerClipEntryColor = fclSpriteEntry(lowerClipSprite);
        ((FclCombineRowSprite *)lowerClipEntryColor)->color = drawColor12;
        drawPosition55 = fclMakeVec2((origin.x - 120.0f) + travelDistance, origin.y - 27.0f);
        drawPosition56 = fclMakeVec2(shownPosition.x - 120.0f, 99.0f + (shownPosition.y - 27.0f));
        fclSpriteStartPositionAt(lowerClipSprite, drawPosition55, drawPosition56, 0U, 0xAU, 0);
        fclSpriteResetScale(lowerClipSprite);
        fclSpriteSetFlag(lowerClipSprite, 0xE, 0);
    } else {
        fclSpriteSetFlag(lowerClipSprite, 0, 0);
        fclSpriteSetFlag(lowerClipSprite, 0xE, 0);
        lowerClipEntryPosition = fclSpriteEntry(lowerClipSprite);
        drawPosition60 = ((FclCombineRowSprite *)lowerClipEntryPosition)->position;
        if ((s8)useHiddenPosition == 0) {
            drawPosition57 = fclMakeVec2(origin.x - 120.0f, origin.y - 27.0f);
            fclSpriteStartPositionAt(lowerClipSprite, drawPosition60, drawPosition57, 0U, 4U, 0);
        } else {
            drawPosition58 = fclMakeVec2(hiddenPosition.x - 120.0f, 99.0f + (hiddenPosition.y - 27.0f));
            fclSpriteStartPositionAt(lowerClipSprite, drawPosition60, drawPosition58, 0U, 4U, 0);
        }
    }
    if (showing == 1) {
        lowerClipResource = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x80U);
        lowerClipSlot = (u8 **)(work + 0x25C) + (s8)(u32)slot * 2;
        drawPosition59 = fclMakeVec2(shownPosition.x - 120.0f, 99.0f + (shownPosition.y - 27.0f));
        lowerClipPositionWork = fclSpriteWork(*lowerClipSlot);
        *(FclVec2 *)lowerClipPositionWork = drawPosition59;
        boundsPacket2 = fclMakeBoundsPacket(250.0f, 250.0f);
        lowerClipBoundsWork = fclSpriteWork(*lowerClipSlot);
        ((FclBoundsPacket *)(lowerClipBoundsWork + 8))->representation = boundsPacket2.representation;
        ((FclCombineClipWork *)fclSpriteWork(*lowerClipSlot))->order = (s32) (s16)lowerOrder;
        ((FclCombineClipWork *)fclSpriteWork(*lowerClipSlot))->depth = 110.0f;
        ((FclCombineClipWork *)fclSpriteWork(*lowerClipSlot))->unk124 = 0;
        sdkSpriteFreeNode(lowerClipResource);
    }
}
/* Draws the detail panel for the highlighted combine choice: if its table index is -1, the empty-
 * choice header and flagged entries; otherwise its three info lines or header, then the flagged
 * entries. */
// FUN_0032E570
void fclCombineDrawDetailPanel(u8 *task) {
    /* measured: typing the remaining side/flag fields as struct members changes the generated code. */
    extern u8 fclCalendarMonth(void);
    extern s32 fclCalendarDay(void);
    extern s64 calGetDayEntryForMonthDay(s32 month, s32 day);
    extern u8 D_00643D00[];
    extern u8 D_006432B0[];
    extern char *D_006430B0[];
    extern char *D_00643220[];
    extern char *D_00644D18[];
    extern char *D_00644D1C[];
    extern char *D_00644D20[];
    extern s32 iGpffffb44c;
    extern int frFontExDrawTextDeferred(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int unused, void *param);
    extern void strcpy(char *dst, const char *src);
    extern void strcat(char *dst, char *src);
    extern void frFontExCopyString(char *src, char *dst, s32 maxlen);
    extern char *fclExpandNameTags(char *text, u8 *mode, u8 *secondName, u8 *thirdName, u8 *fourthName);
    extern char *func_00243840(s32 task);
    char text[128];
    char convertedSuffix[64];
    char suffix[64];
    u8 *work;
    u8 *base;
    u8 *ent;
    u8 *e;
    u8 *b440;
    u8 *b44c;
    u8 alpha;
    s8 v;
    s8 id;
    s16 j;
    s16 n;
    s16 k;
    s16 j1;
    s16 n1;
    s16 firstPersona;
    s16 secondPersona;
    s32 off;
    f32 x;

    work = ((struct KwlnTask *)task)->work;
    ((FclCombineWork *)work)->detailSide = ((FclCombineWork *)work)->f122 ^ 1;
    alpha = fclEaseInterpolate(2, 0.0f, 255.0f, (f32)((FclCombineRowSprite *)fclSpriteEntry(0x2E4))->positionElapsed,
                          (f32)((FclCombineRowSprite *)fclSpriteEntry(0x2E4))->positionDuration);
    v = (&MEMBER(s8, work, FclCombineWork, ruleIndices[0]))[MEMBER(s8, work, FclCombineWork, detailSide)];
    if (v == -1) {
        if (MEMBER(s8, work, FclCombineWork, f122) == 1) {
            base = D_00643D00 + (s8)calGetDayEntryForMonthDay(fclCalendarMonth() & 0xFF, fclCalendarDay() & 0xFF) * 0x14;
        } else if (MEMBER(s8, work, FclCombineWork, f122) == 0) {
            base = D_00643D00 + (s8)calGetDayEntryForMonthDay(((FclCombineWork *)work)->calendarMonth, ((FclCombineWork *)work)->calendarDay) * 0x14;
        }
        fclCombineDrawResourceAt(0x1D2, fclMakeVec2(135.0f, 96.0f), 43.0f, fclPackRgba(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
        frFontExDrawTextDeferred(153.0f, 86.0f, 43.0f, fclPackRgba(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D18[0], 0, 0, D_00795E60);
        for (j1 = 0, n1 = 0; j1 < 5; j1++) {
            if (((FclCombineWork *)(work + MEMBER(s8, work, FclCombineWork, detailSide) * 5 + j1))->detailFlags[0][0] == 1) {
                off = n1 * 0x22;
                fclCombineDrawResourceAt(0x1D2, fclMakeVec2(135.0f, (f32)(off + 0xC3)), 43.0f, fclPackRgba(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
                e = base + j1 * 4;
                id = *(s8 *)e;
                if (id == 0xA) {
                    strcpy(text, func_00243840(((FclCombineDetailEffect *)e)->argument));
                    strcpy(suffix, D_00644D20[0]);
                    frFontExCopyString(suffix, convertedSuffix, 0x40);
                    strcat(text, convertedSuffix);
                    frFontExDrawTextDeferred(153.0f, (f32)(off + 0xB9), 43.0f, fclPackRgba(0xFF, 0xFF, 0xFF, alpha), 0, 1, text, 0, 0, D_00795E60);
                } else {
                    frFontExDrawTextDeferred(153.0f, (f32)(off + 0xB9), 43.0f, fclPackRgba(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_006430B0[id], 0, 0, D_00795E60);
                }
                n1++;
            }
        }
        if (n1 == 0) {
            fclCombineDrawResourceAt(0x1D2, fclMakeVec2(135.0f, 195.0f), 43.0f, fclPackRgba(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
            frFontExDrawTextDeferred(153.0f, 185.0f, 43.0f, fclPackRgba(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D1C[0], 0, 0, D_00795E60);
        }
    } else {
        ent = D_006432B0 + v * 0x1C;
        fclCombineDrawResourceAt(0x1D2, fclMakeVec2(135.0f, 96.0f), 43.0f, fclPackRgba(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
        if (((FclCombineCalendarRule *)ent)->kind != 0) {
            k = 0;
            x = 153.0f;
            for (; k < 3; k++) {
                strcpy(text, (D_00643220 + MEMBER(s8, ent, FclCombineCalendarRule, kind) * 3)[k]);
                secondPersona = ((FclCombineCalendarRule *)ent)->secondPersona;
                b44c = (u8 *)iGpffffb44c;
                firstPersona = ((FclCombineCalendarRule *)ent)->firstPersona;
                b440 = (u8 *)iGpffffb440;
                frFontExDrawTextDeferred(153.0f, (f32)(k * 0x19 + 0x56), 43.0f, fclPackRgba(0xFF, 0xFF, 0xFF, alpha), 0, 1,
                              fclExpandNameTags(text, b440 + firstPersona * 0x11, b440 + secondPersona * 0x11, b44c + firstPersona * 0x15, b44c + secondPersona * 0x15),
                              0, 0, D_00795E60);
            }
        } else {
            x = 153.0f;
            frFontExDrawTextDeferred(153.0f, 86.0f, 43.0f, fclPackRgba(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D18[0], 0, 0, D_00795E60);
        }
        for (j = 0, n = 0; j < 5; j++) {
            if (((FclCombineWork *)(work + MEMBER(s8, work, FclCombineWork, detailSide) * 5 + j))->detailFlags[0][0] == 1) {
                off = n * 0x22;
                fclCombineDrawResourceAt(0x1D2, fclMakeVec2(135.0f, (f32)(off + 0xC3)), 43.0f, fclPackRgba(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
                e = ent + j * 4;
                id = ((FclCombineCalendarRule *)e)->effects[0].kind;
                if (id == 0xA) {
                    strcpy(text, func_00243840(((FclCombineCalendarRule *)e)->effects[0].argument));
                    strcpy(suffix, D_00644D20[0]);
                    frFontExCopyString(suffix, convertedSuffix, 0x40);
                    strcat(text, convertedSuffix);
                    frFontExDrawTextDeferred(x, (f32)(off + 0xB9), 43.0f, fclPackRgba(0xFF, 0xFF, 0xFF, alpha), 0, 1, text, 0, 0, D_00795E60);
                } else {
                    frFontExDrawTextDeferred(x, (f32)(off + 0xB9), 43.0f, fclPackRgba(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_006430B0[id], 0, 0, D_00795E60);
                }
                n++;
            }
        }
        if (n == 0) {
            fclCombineDrawResourceAt(0x1D2, fclMakeVec2(135.0f, 195.0f), 43.0f, fclPackRgba(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
            frFontExDrawTextDeferred(x, 185.0f, 43.0f, fclPackRgba(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D1C[0], 0, 0, D_00795E60);
        }
    }
}

// Fcl combine detail frame: mode 0 creates the five frame sprites of the detail panel (0x162, 0x163, 0x164, 0x165 and 0x2DA) at their table positions and fades them in; any other mode fades them out.
// FUN_0032F060
void fclCombineDrawDetailFrame(u8 *task, s32 mode) {
    FclDrawColor drawColor1, drawColor2, drawColor3, drawColor4, drawColor5;
    FclPackedPosition positionPacket1, positionPacket2, positionPacket3, positionPacket4, positionPacket5;
    s32 entryMode;
    f32 *p;
    f32 spriteValue;

    p = D_00644880;
    entryMode = (s8)mode;
    if (entryMode == 0) {
        positionPacket1.position = fclMakeVec2(p[0], p[1]);
        fclSpriteCreate(0x162, positionPacket1.position, 147.0f, 0xA1);
        drawColor1 = fclMakeDrawColor(0xFF, 0xCC, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x162))->color = drawColor1;
        spriteValue = -15.0f;
        ((FclCombineDrawSprite *)fclSpriteEntry(0x162))->unkD0 = spriteValue;
        fclSpriteStartAlphaAt(0x162, 0, 0xFF, 0, 0xA, 0);
    } else {
        fclSpriteStartAlphaAt(0x162, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644888;
    if (entryMode == 0) {
        positionPacket2.position = fclMakeVec2(p[0], p[1]);
        fclSpriteCreate(0x163, positionPacket2.position, 146.0f, 0xA2);
        drawColor2 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x163))->color = drawColor2;
        spriteValue = -15.0f;
        ((FclCombineDrawSprite *)fclSpriteEntry(0x163))->unkD0 = spriteValue;
        fclSpriteStartAlphaAt(0x163, 0, 0xFF, 0, 0xA, 0);
    } else {
        fclSpriteStartAlphaAt(0x163, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644890;
    if (entryMode == 0) {
        positionPacket3.position = fclMakeVec2(p[0], p[1]);
        fclSpriteCreate(0x164, positionPacket3.position, 145.0f, 0x59);
        drawColor3 = fclMakeDrawColor(0xFF, 0xCC, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x164))->color = drawColor3;
        fclSpriteStartAlphaAt(0x164, 0, 0xFF, 0, 0xA, 0);
    } else {
        fclSpriteStartAlphaAt(0x164, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644898;
    if (entryMode == 0) {
        positionPacket4.position = fclMakeVec2(p[0], p[1]);
        fclSpriteCreate(0x165, positionPacket4.position, 145.0f, 0x59);
        drawColor4 = fclMakeDrawColor(0xFF, 0xCC, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x165))->color = drawColor4;
        fclSpriteStartAlphaAt(0x165, 0, 0xFF, 0, 0xA, 0);
    } else {
        fclSpriteStartAlphaAt(0x165, 0xFF, 0, 0, 0xA, 0);
    }
    if (entryMode == 0) {
        positionPacket5.position = fclMakeVec2(0.0f, 65.0f);
        fclSpriteCreate(0x2DA, positionPacket5.position, 145.0f, 0x59);
        drawColor5 = fclMakeDrawColor(0xFF, 0xCC, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x2DA))->color = drawColor5;
        fclSpriteStartAlphaAt(0x2DA, 0, 0xFF, 0, 0xA, 0);
    } else {
        fclSpriteStartAlphaAt(0x2DA, 0xFF, 0, 0, 0xA, 0);
    }
}

/* The frame holds only five table entries, but six rows are added when both flags are set: a latent
 * overflow in retail, kept as written. */
typedef union {
    FclDrawColor channels;
    u32 bits;
} FclActionColor;

/* Store a selected action identifier at an already-scaled row displacement. */
/* measured: expanding the offset-first selected-ID store changes owner instruction bytes at all six call sites. */
static inline void fclStoreActionResource(s16 id, s32 offset, u8 *work)
{
    /* offset is already a byte displacement and is added before work. */
    ((FclCombineWork *)((u32)offset + (u32)work))->selectedIds[0] = id;
}
// Fcl combine action list: builds the action rows (sprite ids 0x169 and 0x16A, then 0x16B and 0x16C when flags 0x1305 and 0x1306 are set, then 0x16D and 0x16E), lays them out 34 units apart, draws them with fclCombineDrawListRow and sets the row colours. Flag 0x1306 also recolours sprites 0x200, 0x201, 0x16B and 0x301.
// FUN_0032F4D0
void fclCombineDrawActionList(u8 *task) {
    /* measured: typing the remaining count/color-source fields as struct members changes the
     * generated code. */
    FclVec2 tbl[5];
    FclActionColor packedColor1;
    FclActionColor packedColor2;
    FclActionColor packedColor3;
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    f32 rowAdjustment;
    s32 i;
    s16 n;
    s16 r;
    u8 *work;
    u8 *p1;
    u8 *p2;

    work = ((struct KwlnTask *)task)->work;
    rowAdjustment = 0.0f;
    ((FclCombineWork *)work)->actionCount = 0;
    fclStoreActionResource(0x169, ((FclCombineWork *)work)->actionCount * 2, work);
    tbl[MEMBER(s8, work, FclCombineWork, actionCount)] = fclMakeVec2(26.0f, (f32)(((FclCombineWork *)work)->actionCount * 34 + 0x57));
    MEMBER(s8, work, FclCombineWork, actionCount) += 1;
    fclStoreActionResource(0x16A, MEMBER(s8, work, FclCombineWork, actionCount) * 2, work);
    tbl[MEMBER(s8, work, FclCombineWork, actionCount)] = fclMakeVec2(26.0f, (f32)(MEMBER(s8, work, FclCombineWork, actionCount) * 34 + 0x57));
    MEMBER(s8, work, FclCombineWork, actionCount) += 1;
    if (datGetFlag(0x1305) != 0) {
        fclStoreActionResource(0x16B, MEMBER(s8, work, FclCombineWork, actionCount) * 2, work);
        tbl[MEMBER(s8, work, FclCombineWork, actionCount)] = fclMakeVec2(26.0f, (f32)(MEMBER(s8, work, FclCombineWork, actionCount) * 34 + 0x57));
        MEMBER(s8, work, FclCombineWork, actionCount) += 1;
        if (datGetFlag(0x1306) != 0) {
            fclStoreActionResource(0x16C, MEMBER(s8, work, FclCombineWork, actionCount) * 2, work);
            tbl[MEMBER(s8, work, FclCombineWork, actionCount)] = fclMakeVec2(26.0f, 20.0f + (f32)(MEMBER(s8, work, FclCombineWork, actionCount) * 34 + 0x57));
            MEMBER(s8, work, FclCombineWork, actionCount) += 1;
            rowAdjustment = -14.0f;
        }
    }
    fclStoreActionResource(0x16D, MEMBER(s8, work, FclCombineWork, actionCount) * 2, work);
    tbl[MEMBER(s8, work, FclCombineWork, actionCount)] = fclMakeVec2(26.0f, rowAdjustment + (f32)(MEMBER(s8, work, FclCombineWork, actionCount) * 34 + 0x57));
    MEMBER(s8, work, FclCombineWork, actionCount) += 1;
    fclStoreActionResource(0x16E, MEMBER(s8, work, FclCombineWork, actionCount) * 2, work);
    tbl[MEMBER(s8, work, FclCombineWork, actionCount)] = fclMakeVec2(26.0f, rowAdjustment + (f32)(MEMBER(s8, work, FclCombineWork, actionCount) * 34 + 0x57));
    MEMBER(s8, work, FclCombineWork, actionCount) += 1;
    i = 0;
    for (; (s16)i < MEMBER(s8, work, FclCombineWork, actionCount); i = (s16)(i + 1)) {
        n = (s16)i;
        fclCombineDrawListRow(task, (s8)(n + 4), tbl[n], ((FclCombineWork *)(work + n * 2))->selectedIds[0], (s16)(n * 2 + 3), 0);
    }
    r = (s16)fclCombineMapSlotKind(((FclCombineWork *)work)->actionKind);
    packedColor1.channels = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
    packedColor2.channels = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    packedColor3.channels = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
    fclCombineSetSlotColors(task, r, packedColor1.channels, packedColor2.channels, packedColor3.channels);
    if (datGetFlag(0x1306) != 0) {
        drawColor1 = fclMakeDrawColor(0x29, 0x29, 0x29, 0xFF);
        p1 = fclSpriteEntry(0x201);
        ((FclCombineRowSprite *)p1)->color = drawColor1;
        p2 = fclSpriteEntry(0x200);
        ((FclCombineRowSprite *)p2)->color = MEMBER(FclDrawColor, p1, FclCombineRowSprite, color);
        drawColor2 = fclMakeDrawColor(0x61, 0x61, 0x61, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x16B))->color = drawColor2;
        drawColor3 = fclMakeDrawColor(0x4A, 0x4A, 0x4A, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x301))->color = drawColor3;
    }
}

// Fcl combine slot colours: sets the colours of the slot's two sprite pairs and the marker sprites.
// FUN_0032FA30
void fclCombineSetSlotColors(u8 *task, s16 slot, FclDrawColor barColor, FclDrawColor labelColor, FclDrawColor markerColor) {
    /* measured: retail copies the remaining color source byte by byte, not as a struct member. */
    u8 *work;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    s32 idx;

    work = ((struct KwlnTask *)task)->work;
    p1 = fclSpriteEntry((s16)((slot + 4) * 2 + 0x1F5));
    ((FclCombineRowSprite *)p1)->color = barColor;
    p2 = fclSpriteEntry((s16)((slot + 4) * 2 + 0x1F4));
    ((FclCombineRowSprite *)p2)->color = MEMBER(FclDrawColor, p1, FclCombineRowSprite, color);
    idx = slot * 2;
    p3 = fclSpriteEntry(((FclCombineWork *)(idx + (s32)work))->selectedIds[0]);
    ((FclCombineRowSprite *)p3)->color = labelColor;
    p4 = fclSpriteEntry((s16)(slot + 0x2FF));
    ((FclCombineRowSprite *)p4)->color = markerColor;
}
// Fcl combine map slot kind: maps a slot kind through D_00749530 when flag 0x1306 is set.
// FUN_0032FB60
s8 fclCombineMapSlotKind(s8 kind) {
    if (datGetFlag(0x1306)) {
        kind = (s8)(D_00749530[kind] - 4);
    }
    return kind;
}

/* Draws the combine roster grid: a slot-field header, then one party row per roster entry with
 * eight slot cells, and a marker sprite (0x25E + row) that fades in and slides to x = 0x14E + 23
 * row. */
// FUN_0032FBC0
void fclCombineDrawGridRows(u8 *task) {
    /* measured: retail reads the remaining row-task fields through a four-byte row bias, not struct
     * members. */
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclVec2 drawPosition1;
    FclVec2 drawPosition2;
    FclVec2 drawPosition3;
    FclVec2 drawPosition4;
    FclVec2 drawPosition5;
    u8 *work;
    s16 i;
    s16 j;
    u8 *p;
    u8 *h;

    work = ((struct KwlnTask *)task)->work;
    drawPosition1 = fclMakeVec2(16.0f, 104.0f);
    fclCombineDrawSlotFields(task, drawPosition1, 0, 1, 0, 0, 0);
    i = 0;
    while ((s16)i < (u16)datPersonaRosterCapacity()) {
        drawPosition2 = fclMakeVec2(16.0f, 128.0f);
        fclCombinePartyRow(task, drawPosition2, (s8)i, ((FclCombinePersonaHeader *)yListSlotEntry(0, i))->personaId, ((FclCombinePersonaHeader *)yListSlotEntry(0, i))->level, 0, 1, (s8)*(u8*)&((FclCombinePersonaListHeader *)yListSlotWork(0))->count);
        j = 0;
        p = work + (s16)i * 4;
        while ((s16)j < (u16)datPersonaRosterCapacity()) {
            u8 *e0;
            u8 *e1;
            u8 *e2;
            u8 *e3;
            u8 *e4;
            u8 *e5;
            u8 *e6;
            e0 = fclCombineSlotRecord(((FclCombineRowWork *)p)->gridRowTasks[0], (s8)j);
            e1 = fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), (s8)j);
            e2 = fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), (s8)j);
            e3 = fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), (s8)j);
            e4 = fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), (s8)j);
            e5 = fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), (s8)j);
            e6 = fclCombineSlotRecord(MEMBER(u8 *, p, FclCombineRowWork, gridRowTasks[0]), (s8)j);
            fclSpriteStartEntrance(e0, ((FclObject *)((u8 *)e1 - 4))->anchorPosition,
                          ((FclObject *)((u8 *)e2 - 4))->color, ((FclObject *)((u8 *)e3 - 4))->color,
                          ((FclObject *)((u8 *)e4 - 4))->alpha, ((FclObject *)((u8 *)e5 - 4))->alpha,
                          32.0f, ((FclObject *)((u8 *)e6 - 4))->anchorValue, 3, 0, 1, 0);
            ++j;
        }
        p = fclCombineSlotRecord(((FclCombineRowWork *)work)->gridColumnHeaderTask, (s8)i);
        {
            f32 spacing = 23.0f;
            f32 row = (f32)i;
            f32 startX = (f32)329;
            drawPosition3 = fclMakeVec2(startX + spacing * row, 104.0f);
        }
        drawColor1 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
        drawColor2 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
        fclSpriteStartEntrance(p, drawPosition3, drawColor1, drawColor2, 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
        {
            s16 normalizedRow = i;
            s16 resource = (s16)(normalizedRow + 0x25E);
            h = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
            fclSpriteStartAlphaAt(resource, 0xFF, 0, 0, 3, 0);
            {
                f32 unitScale = 1.0f;
                fclSpriteStartRevealScaleAt(resource, unitScale, unitScale, unitScale, iGpffff8504, 0, 3, 0);
            }
            drawPosition4 = fclMakeVec2((f32)(normalizedRow * 23 + 0x14E), 110.0f);
            drawPosition5 = fclMakeVec2((f32)(normalizedRow * 23 + 0x14E),
                         110.0f + sdkSpriteScaledHeight(h) / 2.0f);
            fclSpriteStartPositionAt(resource, drawPosition4, drawPosition5, 0, 3, 0);
            sdkSpriteFreeNode(h);
        }
        ++i;
    }
}

/* Moves the eight-entry grid cursor for command, redraws the six-row window highlights and
 * repositions its indicators. Depth precedes draw order in the shared placement call. */
// FUN_00330060
void fclCombineMoveGridCursor(u8 *task, s32 command) {
    /* measured: typing the remaining cursor/color fields as struct members changes the generated
     * code. */
    FclDrawColor drawColor1;
    FclDrawColor drawColor2;
    FclDrawColor drawColor3;
    FclDrawColor drawColor4;
    FclDrawColor drawColor5;
    FclDrawColor drawColor6;
    FclVec2 position;
    u8 *work;
    u8 *p;
    u8 *p1;
    s16 i;
    s16 diff;
    s16 jj;
    s16 cur;
    s32 lim;
    s32 bid;
    s32 savedColumn;
    f32 diff_f;
    f32 base;
    f32 fv;
    f32 fv2;
    work = ((struct KwlnTask *)task)->work;
    drawColor1 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
    p = fclSpriteEntry((s16)(((FclCombineWork *)work)->windowRow * 2 + 0x1F5));
    ((FclCombineRowSprite *)p)->color = drawColor1;
    p1 = fclSpriteEntry((s16)(MEMBER(s16, work, FclCombineWork, windowRow) * 2 + 0x1F4));
    ((FclCombineRowSprite *)p1)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
    drawColor2 = fclMakeDrawColor(0x25, 0x2F, 0x94, 0xFF);
    p = fclSpriteEntry((s16)(MEMBER(s16, work, FclCombineWork, windowRow) + 0x2FB));
    ((FclCombineRowSprite *)p)->color = drawColor2;
    ((FclCombineWork *)work)->redrawRequested = 1;
    switch ((s8)command) {
    case 0:
        if (((FclCombineRowWork *)work)->cursorRow != 7) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        MEMBER(s16, work, FclCombineRowWork, cursorRow) = (s16)fclAddClamped(MEMBER(s16, work, FclCombineRowWork, cursorRow), 1, 7, 0, 1);
        MEMBER(s16, work, FclCombineWork, windowRow) = yListStepIndex(MEMBER(s16, work, FclCombineRowWork, cursorRow), MEMBER(s16, work, FclCombineWork, windowRow), 7, 6, 1);
        break;
    case 1:
        if (((FclCombineRowWork *)work)->cursorRow != 0) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        MEMBER(s16, work, FclCombineRowWork, cursorRow) = (s16)fclSubClamped(MEMBER(s16, work, FclCombineRowWork, cursorRow), 1, 0, 0, 1);
        MEMBER(s16, work, FclCombineWork, windowRow) = yListStepIndex(MEMBER(s16, work, FclCombineRowWork, cursorRow), MEMBER(s16, work, FclCombineWork, windowRow), 7, 6, -1);
        break;
    case 2:
        if (((FclCombineRowWork *)work)->cursorRow != 7) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        yListAdvanceCursorScroll(MEMBER(s16, work, FclCombineRowWork, cursorRow), MEMBER(s16, work, FclCombineWork, windowRow), 8, 6, &MEMBER(s16, work, FclCombineRowWork, cursorRow), &MEMBER(s16, work, FclCombineWork, windowRow));
        break;
    case 3:
        if (((FclCombineRowWork *)work)->cursorRow != 0) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        yListRetreatCursorScroll(MEMBER(s16, work, FclCombineRowWork, cursorRow), MEMBER(s16, work, FclCombineWork, windowRow), 8, 6, &MEMBER(s16, work, FclCombineRowWork, cursorRow), &MEMBER(s16, work, FclCombineWork, windowRow));
        break;
    case 4:
        sdkSndStartStream(0, 0, 0, 0);
        ((FclCombineRowWork *)work)->cursorRow = (s16)fclAddClamped(MEMBER(s16, work, FclCombineRowWork, cursorRow), 1, 7, 0, 2);
        if (MEMBER(s16, work, FclCombineRowWork, cursorRow) == 0) {
            MEMBER(s16, work, FclCombineWork, windowRow) = 0;
        } else {
            MEMBER(s16, work, FclCombineWork, windowRow) = yListStepIndex(MEMBER(s16, work, FclCombineRowWork, cursorRow), MEMBER(s16, work, FclCombineWork, windowRow), 7, 6, 1);
        }
        break;
    case 5:
        sdkSndStartStream(0, 0, 0, 0);
        if (((FclCombineRowWork *)work)->cursorRow == 0) {
            MEMBER(s16, work, FclCombineRowWork, cursorRow) = (s16)fclSubClamped(((FclCombineRowWork *)work)->cursorRow, 1, 0, 7, 2);
            MEMBER(s16, work, FclCombineWork, windowRow) = 5;
        } else {
            MEMBER(s16, work, FclCombineRowWork, cursorRow) = (s16)fclSubClamped(((FclCombineRowWork *)work)->cursorRow, 1, 0, 7, 2);
            MEMBER(s16, work, FclCombineWork, windowRow) = yListStepIndex(MEMBER(s16, work, FclCombineRowWork, cursorRow), MEMBER(s16, work, FclCombineWork, windowRow), 7, 6, -1);
        }
        break;
    }
    for (i = 0; i < 9; ++i) {
        fclSpriteSetFlag((s16)(i + 0x179), 0, 1);
    }
    diff = (s16)(((FclCombineRowWork *)work)->cursorRow - MEMBER(s16, work, FclCombineWork, windowRow));
    cur = diff;
    jj = 0;
    lim = diff + 6;
    while (cur < lim) {
        savedColumn = jj;
        bid = (s32)operandOrderAddUnsigned((s16)cur, 0x179);
        position = fclMakeVec2(32.0f, (f32)(savedColumn * 34 + 0x5B));
        fclSpriteCreate((s16)((s16)bid), position, 152.0f, savedColumn * 5 + 0x6A);
        fclSpriteSetFlag((s16)bid, 0, 0);
        fclSpriteResetScale((s16)bid);
        drawColor3 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        p = fclSpriteEntry((s16)bid);
        ((FclCombineRowSprite *)p)->color = drawColor3;
        ++cur;
        ++jj;
    }
    drawColor4 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
    p = fclSpriteEntry((s16)(MEMBER(s16, work, FclCombineWork, windowRow) * 2 + 0x1F5));
    ((FclCombineRowSprite *)p)->color = drawColor4;
    p1 = fclSpriteEntry((s16)(MEMBER(s16, work, FclCombineWork, windowRow) * 2 + 0x1F4));
    ((FclCombineRowSprite *)p1)->color = MEMBER(FclDrawColor, p, FclCombineRowSprite, color);
    drawColor5 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    p = fclSpriteEntry((s16)operandOrderAddUnsigned(diff + 0x179, MEMBER(s16, work, FclCombineWork, windowRow)));
    ((FclCombineRowSprite *)p)->color = drawColor5;
    drawColor6 = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
    p = fclSpriteEntry((s16)(MEMBER(s16, work, FclCombineWork, windowRow) + 0x2FB));
    ((FclCombineRowSprite *)p)->color = drawColor6;
    diff_f = (f32)(MEMBER(s16, work, FclCombineRowWork, cursorRow) - MEMBER(s16, work, FclCombineWork, windowRow));
    base = ((FclCombineWork *)work)->rowSpacing;
    fv = ((FclCombineRowSprite *)fclSpriteEntry(0xA9))->position.y;
    base = base * diff_f + fv;
    ((FclCombineRowSprite *)fclSpriteEntry(0xB1))->position.y = base;
    fv2 = ((FclCombineRowSprite *)fclSpriteEntry(0xB1))->position.y;
    base = 52.0f + fv2;
    ((FclCombineRowSprite *)fclSpriteEntry(0xB5))->position.y = base;
}
/* Restore the old choice colors, move the cursor for command through choiceTable, then highlight
 * the new choice. */
// FUN_003307B0
void fclCombineMoveChoiceCursor(u8 *task, s64 command, s32 choiceTable) {
    /* measured: typing the remaining cursor/color fields as struct members changes the generated
     * code; choice pairs are interleaved. */
    FclDrawColor drawColor1, drawColor2, drawColor3, drawColor4, drawColor5, drawColor6, drawColor7, drawColor8, drawColor9, drawColor10;
    u8 *obj = ((struct KwlnTask *)task)->work;
    s64 choiceCount = (s8)((FclCombineWork *)obj)->choiceCount;
    s8 choiceKind;
    u8 *p1, *p2;

    drawColor1 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
    p1 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(choiceTable + ((FclCombineRowWork *)obj)->cursorRow * 2))->kind * 2 + 0x1F5));
    ((FclCombineRowSprite *)p1)->color = drawColor1;
    p2 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(choiceTable + MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2))->kind * 2 + 0x1F4));
    ((FclCombineRowSprite *)p2)->color = MEMBER(FclDrawColor, p1, FclCombineRowSprite, color);
    drawColor2 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
    p1 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(operandOrderAddUnsigned(MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2, (u32)choiceTable)))->resource + 0x168));
    ((FclCombineRowSprite *)p1)->color = drawColor2;
    drawColor3 = fclMakeDrawColor(0x25, 0x2F, 0x94, 0xFF);
    p1 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(choiceTable + MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2))->kind + 0x2FB));
    ((FclCombineRowSprite *)p1)->color = drawColor3;
    if ((s8)((FclCombineChoice *)(choiceTable + MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2))->kind == 1) {
        drawColor4 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
        p1 = fclSpriteEntry(0x175);
        ((FclCombineRowSprite *)p1)->color = drawColor4;
    }
    choiceKind = (s8)((FclCombineChoice *)(choiceTable + MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2))->kind;
    if (choiceKind == 0xA) {
        if (((s8)((FclCombineWork *)obj)->choiceFlags & 1) == 1) {
            drawColor5 = fclMakeDrawColor(0xFF, 0xCC, 0xFF, 0xFF);
            p1 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(operandOrderAddUnsigned(MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2, (u32)choiceTable)))->resource + 0x168));
            ((FclCombineRowSprite *)p1)->color = drawColor5;
        }
    } else if ((choiceKind == 0xB) && (((s32)((s8)((FclCombineWork *)obj)->choiceFlags & 2) >> 1) == 1)) {
        drawColor6 = fclMakeDrawColor(0xFF, 0xCC, 0xFF, 0xFF);
        p1 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(operandOrderAddUnsigned(MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2, (u32)choiceTable)))->resource + 0x168));
        ((FclCombineRowSprite *)p1)->color = drawColor6;
    }
    ((FclCombineWork *)obj)->redrawRequested = 1;
    switch ((s8)command) {
    case 0: {
        s32 lastChoice = (s16)((s16)choiceCount - 1);
        if (MEMBER(s16, obj, FclCombineRowWork, cursorRow) != lastChoice) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        MEMBER(s16, obj, FclCombineRowWork, cursorRow) = (s16)fclAddClamped(MEMBER(s16, obj, FclCombineRowWork, cursorRow), 1, lastChoice, 0, 1);
        break;
    }
    case 1:
        if (MEMBER(s16, obj, FclCombineRowWork, cursorRow) != 0) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        MEMBER(s16, obj, FclCombineRowWork, cursorRow) = (s16)fclSubClamped(MEMBER(s16, obj, FclCombineRowWork, cursorRow), 1, 0, (s16)((s16)choiceCount - 1), 1);
        break;
    case 2:
    case 3:
        break;
    case 4:
        sdkSndStartStream(0, 0, 0, 0);
        MEMBER(s16, obj, FclCombineRowWork, cursorRow) = (s16)fclAddClamped(MEMBER(s16, obj, FclCombineRowWork, cursorRow), 1, (s16)((s16)choiceCount - 1), 0, 2);
        break;
    case 5:
        sdkSndStartStream(0, 0, 0, 0);
        MEMBER(s16, obj, FclCombineRowWork, cursorRow) = (s16)fclSubClamped(MEMBER(s16, obj, FclCombineRowWork, cursorRow), 1, 0, (s16)((s16)choiceCount - 1), 2);
        break;
    }
    drawColor7 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
    p1 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(choiceTable + MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2))->kind * 2 + 0x1F5));
    ((FclCombineRowSprite *)p1)->color = drawColor7;
    p2 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(choiceTable + MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2))->kind * 2 + 0x1F4));
    ((FclCombineRowSprite *)p2)->color = MEMBER(FclDrawColor, p1, FclCombineRowSprite, color);
    drawColor8 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    p1 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(operandOrderAddUnsigned(MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2, (u32)choiceTable)))->resource + 0x168));
    ((FclCombineRowSprite *)p1)->color = drawColor8;
    drawColor9 = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
    p1 = fclSpriteEntry((s16)((s8)((FclCombineChoice *)(choiceTable + MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2))->kind + 0x2FB));
    ((FclCombineRowSprite *)p1)->color = drawColor9;
    if ((s8)((FclCombineChoice *)(choiceTable + MEMBER(s16, obj, FclCombineRowWork, cursorRow) * 2))->kind == 1) {
        drawColor10 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        p1 = fclSpriteEntry(0x175);
        ((FclCombineRowSprite *)p1)->color = drawColor10;
    }
}
// Queue resource at position with the supplied color, alpha, depth, layer, scale and draw queue.
// FUN_00330E50
void fclCombineDrawResourceAt(s32 resource, FclVec2 position, f32 depth, s32 color, u8 alpha, s32 layer, f32 scaleX, f32 scaleY, void *queue) {
    FclVec2 *p;

    p = &position;
    sdkSpriteDrawQueued(p->x, p->y, depth, color, alpha, (s16)resource, (void *)(u32)fclCombineGetSpritePool(), layer, 0, 0, 0.0f, scaleX, scaleY, queue);
}
// Fcl combine CDVD task update: polls the disc load for the task and advances its load state.
// FUN_00330F20
s32 fclCombineCdvdTaskUpdate(u8 *task) {
    /* measured: typing the eight zero stores as struct members changes the state-update code. */
    s32 firstLoaded, secondLoaded, thirdLoaded, fourthLoaded;
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    if (((FclCombineLoaderWork *)work)->destroyRequested == 1) {
        return -1;
    }
    switch (((FclCombineLoaderWork *)work)->state) {
    case 0:
        if (H_Cdvd_IsFileLoaded(((FclCombineLoaderWork *)work)->firstDirectory) == 0) {
            return 0;
        }
        if (H_Cdvd_IsFileLoaded(((FclCombineLoaderWork *)work)->secondDirectory) == 0) {
            return 0;
        }
        if (H_Cdvd_IsFileLoaded(((FclCombineLoaderWork *)work)->thirdDirectory) == 0) {
            return 0;
        }
        if (H_Cdvd_IsFileLoaded(((FclCombineLoaderWork *)work)->fourthDirectory) == 0) {
            return 0;
        }
        ((FclCombineLoaderWork *)work)->firstSpriteRequest = sdkSpriteRequestLoad(D_00644D70);
        ((FclCombineLoaderWork *)work)->secondSpriteRequest = sdkSpriteRequestLoad(D_00644D90);
        ((FclCombineLoaderWork *)work)->firstResourceRequest = filerEnqueueRequest(0, D_00644DB0, 0, 0, 0, 0, 0, 0, 0, 0);
        ((FclCombineLoaderWork *)work)->secondResourceRequest = filerEnqueueRequest(0, D_00644DD0, 0, 0, 0, 0, 0, 0, 0, 0);
        ((FclCombineLoaderWork *)work)->thirdResourceRequest = filerEnqueueRequest(0, D_00644DF0, 0, 0, 0, 0, 0, 0, 0, 0);
        ((FclCombineLoaderWork *)work)->fourthResourceRequest = filerEnqueueRequest(0, D_00644E10, 0, 0, 0, 0, 0, 0, 0, 0);
        ((FclCombineLoaderWork *)work)->state = (s8)(((FclCombineLoaderWork *)work)->state + 1);
    case 1:
        if (hMaestroDecodeIsReady(((FclCombineLoaderWork *)work)->firstSpriteRequest) != 0 && hMaestroDecodeIsReady(((FclCombineLoaderWork *)work)->secondSpriteRequest) != 0) {
            ((FclCombineLoaderWork *)work)->firstResource = filerTakeCompletedRequest(((FclCombineLoaderWork *)work)->firstResourceRequest, &firstLoaded, 0);
            if (firstLoaded != 0) {
                H_Cdvd_Destroy((u8 *)((FclCombineLoaderWork *)work)->firstDirectory);
                MEMBER(u32, work, FclCombineLoaderWork, firstDirectory) = 0;
                MEMBER(u32, work, FclCombineLoaderWork, firstResourceRequest) = 0;
                ((FclCombineLoaderWork *)work)->state = (s8)(((FclCombineLoaderWork *)work)->state + 1);
            }
        }
        break;
    case 2:
        ((FclCombineLoaderWork *)work)->secondResource = filerTakeCompletedRequest(((FclCombineLoaderWork *)work)->secondResourceRequest, &secondLoaded, 0);
        if (secondLoaded != 0) {
            H_Cdvd_Destroy((u8 *)((FclCombineLoaderWork *)work)->secondDirectory);
            MEMBER(u32, work, FclCombineLoaderWork, secondDirectory) = 0;
            MEMBER(u32, work, FclCombineLoaderWork, secondResourceRequest) = 0;
            ((FclCombineLoaderWork *)work)->state = (s8)(((FclCombineLoaderWork *)work)->state + 1);
        }
        break;
    case 3:
        ((FclCombineLoaderWork *)work)->thirdResource = filerTakeCompletedRequest(((FclCombineLoaderWork *)work)->thirdResourceRequest, &thirdLoaded, 0);
        if (thirdLoaded != 0) {
            H_Cdvd_Destroy((u8 *)((FclCombineLoaderWork *)work)->thirdDirectory);
            MEMBER(u32, work, FclCombineLoaderWork, thirdDirectory) = 0;
            MEMBER(u32, work, FclCombineLoaderWork, thirdResourceRequest) = 0;
            ((FclCombineLoaderWork *)work)->state = (s8)(((FclCombineLoaderWork *)work)->state + 1);
        }
        break;
    case 4:
        ((FclCombineLoaderWork *)work)->fourthResource = filerTakeCompletedRequest(((FclCombineLoaderWork *)work)->fourthResourceRequest, &fourthLoaded, 0);
        if (fourthLoaded != 0) {
            H_Cdvd_Destroy((u8 *)((FclCombineLoaderWork *)work)->fourthDirectory);
            MEMBER(u32, work, FclCombineLoaderWork, fourthDirectory) = 0;
            MEMBER(u32, work, FclCombineLoaderWork, fourthResourceRequest) = 0;
            ((FclCombineLoaderWork *)work)->state = (s8)(((FclCombineLoaderWork *)work)->state + 1);
        }
        break;
    case 5:
        if (H_Cdvd_IsFileLoaded(((FclCombineLoaderWork *)work)->messageDirectory) != 0 && H_Cdvd_IsFileLoaded(((FclCombineLoaderWork *)work)->extraDirectory) != 0) {
            ((FclCombineLoaderWork *)work)->messageWindow = itfMesWindowInstall(H_Cdvd_LookupRequest(D_00644E30, 0));
            ((FclCombineLoaderWork *)work)->state = (s8)(((FclCombineLoaderWork *)work)->state + 1);
        }
        break;
    case 6:
        break;
    }
    return 0;
}

// Fcl combine CDVD task destroy: releases the sprites, the message window, and the CDVD handles.
// FUN_003312E0
void fclCombineCdvdTaskDestroy(u8 *task) {
    /* measured: typing the final task-work access as a struct member changes reload code. */
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    sdkSpriteRelease((u8 *)((FclCombineLoaderWork *)(work))->firstSpriteRequest);
    sdkSpriteRelease((u8 *)((FclCombineLoaderWork *)(work))->secondSpriteRequest);
    func_003ef3a0((u8 *)((FclCombineLoaderWork *)(work))->firstResource);
    func_003ef3a0((u8 *)((FclCombineLoaderWork *)(work))->secondResource);
    func_003ef3a0((u8 *)((FclCombineLoaderWork *)(work))->thirdResource);
    func_003ef3a0((u8 *)((FclCombineLoaderWork *)(work))->fourthResource);
    itfMesWindowReleaseIfActive(((FclCombineLoaderWork *)(work))->messageWindow);
    H_Cdvd_Destroy((u8 *)((FclCombineLoaderWork *)(work))->messageDirectory);
    H_Cdvd_Destroy((u8 *)((FclCombineLoaderWork *)(work))->extraDirectory);
    D_008873EC[0](MEMBER(u8 *, task, struct KwlnTask, work));
}

// Fcl combine CDVD task create: creates the CDVD loader task with the update and destroy callbacks.
// FUN_00331390
void fclCombineCdvdTaskCreate(void) {
    u8 *p;

    if (iGpffffb598 != 0) {
        iGpffffb598 = 0;
    }
    chkmemAllocSiteTag(D_00644D30, 0x16A4);
    p = D_008873F4[0](1, 0x48, 0x40000);
    iGpffffb598 = (s32)kwlnTaskCreate((const void *)(D_00644E48), 0xF, 0, 0, fclCombineCdvdTaskUpdate, fclCombineCdvdTaskDestroy, (u8 *)(p));
    ((FclCombineLoaderWork *)(p))->state = 0;
    ((FclCombineLoaderWork *)(p))->destroyRequested = 0;
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B2);
    ((FclCombineLoaderWork *)(p))->firstDirectory = (s32)H_Cdvd_AcquireDirectory((u8 *)D_00644DB0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B3);
    ((FclCombineLoaderWork *)(p))->secondDirectory = (s32)H_Cdvd_AcquireDirectory((u8 *)D_00644DD0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B4);
    ((FclCombineLoaderWork *)(p))->thirdDirectory = (s32)H_Cdvd_AcquireDirectory((u8 *)D_00644DF0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B5);
    ((FclCombineLoaderWork *)(p))->fourthDirectory = (s32)H_Cdvd_AcquireDirectory((u8 *)D_00644E10, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B7);
    ((FclCombineLoaderWork *)(p))->messageDirectory = (s32)H_Cdvd_AcquireDirectory((u8 *)D_00644E30, 0);
    ((FclCombineLoaderWork *)(p))->messageWindow = -1;
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B9);
    ((FclCombineLoaderWork *)(p))->extraDirectory = (s32)H_Cdvd_AcquireDirectory((u8 *)D_00644E60, 0);
}
