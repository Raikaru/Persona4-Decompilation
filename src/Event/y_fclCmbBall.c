#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_combine_internal.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
extern s32 fclCmbBallSlotsUpdate(u8 *task);
extern void fclCmbBallSlotsDestroy(u8 *task);
/* Original translation unit y_fclCmbBall.c (from __FILE__ assert strings). */
#include "type.h"
#include "sdktask.h"

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void chkmemAllocSiteTag(const void *, s32);
extern char D_0064A740[];
extern char D_0064A750[];
extern char D_0064A770[];
extern s32 fclCmbBallUpdate(u8 *);
extern u8 *PrimQueueDrawPrimitive(void *, s32, void *, s32);
extern f32 fclEaseInterpolate(s64, f32, f32, f32, f32);
extern s32 fclAddClamped(s32, s32, s32, s32, s8);
extern s32 fclSubClamped(s32, s32, s32, s32, s8);
extern u8 D_00793E80[];
extern void (*D_00887300[])(u32, u32);
extern s32 kwlnGetCamera(void);
extern s32 fclCombineGetTexture(void);
extern void RpSkyRenderStateSet(s32, s32);


/* PrimQueueDrawPrimitive uses four 0x40-byte vertices per ball. UVs are
 * written as IEEE-754 words (0 or 0x3F800000) before submission. */
typedef struct {
    f32 x, y, z;
    u8 pad0C[4];
    s32 uBits, vBits;
    f32 reciprocalDepth;
    u8 pad1C[4];
    f32 red, green, blue, alpha;
    u8 pad30[0x10];
} FclBallVertex;
typedef struct {
    u8 pad00[8];
    void *draw;
    u8 pad0C[4];
    u8 *work;
} FclBallDrawPacket;
typedef struct {
    u8 pad00[0x80];
    f32 depth;
} FclBallCamera;

/* The allocator reserves 0xF10 bytes. Fourteen 0x100-byte quad packets
 * precede the animation fields; drawPacket is reset before queue traversal. */
typedef struct {
    s16 drawOrder, drawPacket;
    u8 pad04[0xE0C];
    s16 flags;
    u8 padE12[2];
    f32 depth;
    u8 padE18[0x20];
    FclVec2 position;
    u8 padE40[0x28];
    s16 alphaDuration, alphaFrame;
    u8 startAlpha, endAlpha, alpha;
    u8 padE6F;
    s16 alphaDelay;
    s8 easeMode, alphaLoop;
    u8 padE74[0x8C];
    s8 colorMode;
    u8 padF01[0xF];
} FclCmbBall;
typedef char FclCmbBallSizeCheck[sizeof(FclCmbBall) == 0xF10 ? 1 : -1];

/* Twelve records, each 0x200 bytes, followed by a count byte. */
typedef struct {
    u8 pad00[0x100];
    s16 order;
    u8 pad102[2];
    s16 state;
    u8 pad106[0xFA];
} FclCmbBallSlot;
typedef struct {
    FclCmbBallSlot slots[12];
    s8 count;
    u8 pad1801[0xF];
} FclCmbBallSlots;

/* Allocate twelve slot records, initialize their order, and store the requested count. */
// FUN_0034AD70
s32 fclCmbBallTaskCreateSlots(s32 parent, u8 count, s16 order) {
    s32 handle;
    u8 *work;
    s32 slotIndex;

    chkmemAllocSiteTag(&D_0064A740, 0x98);
    work = (u8 *)D_008873F4[0](1, 0x1810, 0x40000);
    handle = (s32)kwlnTaskCreateChild((void *)((void *)(parent)), (const void *)(D_0064A750), 0xF, 0, 0, fclCmbBallSlotsUpdate, fclCmbBallSlotsDestroy, (u8 *)(work));
    for (slotIndex = 0; slotIndex < 0xC; slotIndex++) {
        ((FclCmbBallSlots *)work)->slots[slotIndex].state = 0;
        ((FclCmbBallSlots *)work)->slots[slotIndex].order = order;
    }
    ((FclCmbBallSlots *)work)->count = count;
    return handle;
}

/* Returns the record inside the given slot of the task's 0x200-stride slot block. */
// FUN_0034AE50
u8 *fclCombineSlotRecord(u8 *task, s8 slotIndex) {
    s32 slotOffset = slotIndex * 0x200;

    return ((SdkTask *)task)->work + slotOffset + 0x104;
}

/* The RenderWare globals block is read through a cast so nearZ is evaluated before the ball depth,
 * as retail does. */
typedef struct {
    u8 unk00[0x18];
    f32 nearZ;
    f32 farZ;
} RenderDepth;
extern u8 D_008872E0[];

#pragma push
/* measured: retail keeps the RenderStateSet address live across the packet loop and hoists only the
 * high half of the nearZ address. */
#pragma opt_propagation off
#pragma opt_loop_invariants on
/* Renders one fusion ball: sets the render states, then per-slot depth and colour. */
// FUN_0034AE70
void fclCmbBallDraw(u8 *drawTask, u8 *work) {
    void (**setState)(u32, u32);
    s32 texture;
    f32 scale;
    FclDrawColor color;
    FclVec2 position;
    s16 vertexIndex;
    s16 packetIndex;
    FclCmbBall *ballWork = (FclCmbBall *)work;

    scale = 1.0f / ((FclBallCamera *)kwlnGetCamera())->depth;
    texture = fclCombineGetTexture();
    setState = D_00887300;
    /* RenderWare: depth test/write, filtering, addressing and alpha blending. */
    setState[0](6, 1);
    setState[0](7, 2);
    setState[0](8, 1);
    setState[0](9, 2);
    setState[0](0xC, 1);
    setState[0](2, 3);
    setState[0](0xB, 6);
    setState[0](0xA, 5);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x10))->uBits = 0;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x10))->vBits = 0;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x50))->uBits = 0x3F800000;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x50))->vBits = 0;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x90))->uBits = 0;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x90))->vBits = 0x3F800000;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0xD0))->uBits = 0x3F800000;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0xD0))->vBits = 0x3F800000;
    if (((FclCmbBall *)work)->colorMode == 1) {
        color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, ((FclCmbBall *)work)->alpha);
    } else {
        color = fclMakeDrawColor(0, 0, 0x66, ballWork->alpha);
        if (((FclCmbBall *)work)->drawPacket >= 3) {
            color = fclMakeDrawColor(0xCC, 0xFF, 0xFF, (u32)((FclCmbBall *)work)->alpha >> 1);
        }
    }
    for (vertexIndex = 0; vertexIndex < 4; vertexIndex++) {
        ((FclBallVertex *)((u32)work + (ballWork->drawPacket << 8) + vertexIndex * 64 + 0x10))->z = ((RenderDepth *)D_008872E0)->nearZ - ((FclCmbBall *)work)->depth;
        ((FclBallVertex *)((u32)work + (ballWork->drawPacket << 8) + vertexIndex * 64 + 0x10))->reciprocalDepth = scale;
        ((FclBallVertex *)((u32)work + (ballWork->drawPacket << 8) + vertexIndex * 64 + 0x10))->red = color.c0;
        ((FclBallVertex *)((u32)work + (ballWork->drawPacket << 8) + vertexIndex * 64 + 0x10))->green = color.c1;
        ((FclBallVertex *)((u32)work + (ballWork->drawPacket << 8) + vertexIndex * 64 + 0x10))->blue = color.c2;
        ((FclBallVertex *)((u32)work + (((FclCmbBall *)work)->drawPacket << 8) + vertexIndex * 64 + 0x10))->alpha = color.c3;
    }
    position = ((FclCmbBall *)work)->position;
    packetIndex = ballWork->drawPacket;
    position.x += packetIndex * 19;
    if (packetIndex >= 3) {
        position.x += 12.0f;
    }
    ((FclBallVertex *)((packetIndex << 8) + (u32)work + 0x10))->x = position.x;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x10))->y = position.y;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x50))->x = 16.0f + position.x;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x50))->y = position.y;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x90))->x = position.x;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0x90))->y = 16.0f + position.y;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0xD0))->x = 16.0f + position.x;
    ((FclBallVertex *)((ballWork->drawPacket << 8) + (u32)work + 0xD0))->y = 16.0f + position.y;
    (*setState)(1, *(u32 *)texture);
    ((FclCmbBall *)work)->drawPacket += 1;
}
#pragma pop

/* The second interpolation call uses signed E68 / 2, and the plain u8 cast keeps retail's float-
 * to-u8 saturation. */
extern void fclCmbBallDraw(u8 *, u8 *);

/* Per-frame update: advances the interpolation, then queues the 0xE draw packets. */
// FUN_0034B380
s32 fclCmbBallUpdate(u8 *task) {
    u8 *work;
    FclCmbBall *ballWork;

    work = ((SdkTask *)task)->work;
    ballWork = (FclCmbBall *)work;
    if ((((FclCmbBall *)work)->flags & 1) == 0) {
        return 0;
    }

    /* Flags: bit 0 enables drawing; bit 2 enables the alpha animation. Both the cast work pointer
     * and the ballWork alias are needed so field addresses are not hoisted across the interpolation
     * calls. */
    if (((((FclCmbBall *)work)->flags & 4) >> 2) == 1) {
        if (((FclCmbBall *)work)->alphaDelay == 0) {
            if (ballWork->alphaLoop == 0) {
                ballWork->alpha =
                    (u8)fclEaseInterpolate((s32)((FclCmbBall *)work)->easeMode,
                                           (f32)ballWork->startAlpha,
                                           (f32)ballWork->endAlpha,
                                           (f32)(s16)ballWork->alphaFrame,
                                           (f32)(s16)((FclCmbBall *)work)->alphaDuration);
            } else {
                ((FclCmbBall *)work)->alpha =
                    (u8)fclEaseInterpolate((s32)((FclCmbBall *)work)->easeMode,
                                           (f32)((FclCmbBall *)work)->startAlpha,
                                           (f32)((FclCmbBall *)work)->endAlpha,
                                           (f32)(s16)((FclCmbBall *)work)->alphaFrame,
                                           (f32)(((FclCmbBall *)work)->alphaDuration / 2));
            }
            if (((FclCmbBall *)work)->alphaFrame < ballWork->alphaDuration) {
                ballWork->alphaFrame =
                    fclAddClamped(((FclCmbBall *)work)->alphaFrame, 1,
                                  ballWork->alphaDuration, 0, 1);
            } else {
                ballWork->alpha = ((FclCmbBall *)work)->endAlpha;
                if (((FclCmbBall *)work)->alphaLoop == 1) {
                    ((FclCmbBall *)work)->alpha = ((FclCmbBall *)work)->startAlpha;
                }
                ((FclCmbBall *)work)->flags = ((FclCmbBall *)work)->flags | 4;
            }
        } else {
            ballWork->alphaDelay = fclSubClamped(((FclCmbBall *)work)->alphaDelay, 1, 0, 0, 1);
        }
    }

    if (((FclCmbBall *)work)->alpha <= 0) {
        return 0;
    }

    ((FclCmbBall *)work)->drawPacket = 0;
    {
        s16 packetIndex;

        for (packetIndex = 0; packetIndex < 0xE; packetIndex++) {
            u8 *packet = (u8 *)PrimQueueDrawPrimitive(D_00793E80 + ((FclCmbBall *)work)->drawOrder * 0x30, 4,
                                        work + packetIndex * 0x100 + 0x10, 4);
            ((FclBallDrawPacket *)packet)->draw = (void *)fclCmbBallDraw;
            ((FclBallDrawPacket *)packet)->work = work;
        }
    }
    return 0;
}
/* Task destructor: forwards the state block to jump-table slot 0. */
// FUN_0034B710
void fclCmbBallDestroy(u8 *task) {
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

/* Creates the ball task with a 0xF10-byte state block whose s16 header is set to 0x41. */
// FUN_0034B740
s32 fclCmbBallTaskCreate(s32 parent) {
    s32 handle;
    u8 *work;
    s16 packetIndex;

    chkmemAllocSiteTag(&D_0064A740, 0x14D);
    work = (u8 *)D_008873F4[0](1, 0xF10, 0x40000);
    handle = (s32)kwlnTaskCreateChild((void *)((void *)(parent)), (const void *)(D_0064A770), 0xF, 0, 0, fclCmbBallUpdate, fclCmbBallDestroy, (u8 *)(work));
    packetIndex = 0;
    ((FclCmbBall *)work)->flags = 0;
    /* Preserve the recovered empty packet-count loop; it has no observable writes. */
    while (packetIndex < 0xE) {
        packetIndex++;
    }
    ((FclCmbBall *)work)->drawOrder = 0x41;
    return handle;
}
