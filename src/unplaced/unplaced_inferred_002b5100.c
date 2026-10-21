
/* Unit optimizer settings shared by the neighboring functions. */
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on

#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "kwln_view_internal.h"
#include "primitive_queue_internal.h"
#include "message_handle.h"
#include "shd_misc_internal.h"
typedef struct FclFadeRectVertex
{
    f32 x;        // 0x00
    f32 y;        // 0x04
    f32 z;        // 0x08
    u8 pad0C[0xC];
    f32 q;        // 0x18
    u8 pad1C[4];
    f32 r;        // 0x20
    f32 g;        // 0x24
    f32 b;        // 0x28
    f32 a;        // 0x2C
    u8 pad30[0x10];
} FclFadeRectVertex; // 0x40

typedef struct FclFadeRect
{
    s8 state;                    // 0x000
    u8 pad001[7];
    s8 unk08;
    u8 pad009[7];
    FclFadeRectVertex vtx[4];    // 0x010
    u8 color[4][4];              // 0x110
    u8 pad120[8];
    s32 width;                   // 0x128
    s32 height;                  // 0x12C
    f32 depth;                   // 0x130
    f32 x;                       // 0x134
    f32 y;                       // 0x138
    f32 x0;                      // 0x13C
    f32 y0;                      // 0x140
    f32 x1;                      // 0x144
    f32 y1;                      // 0x148
    s16 frame;                   // 0x14C
    u8 pad14E[2];
    s32 frames;                  // 0x150
    s8 done;                     // 0x154
    u8 pad155;
    s16 mode;                    // 0x156
    u8 pad158[8];
    s32 width0;                  // 0x160
    s32 height0;                 // 0x164
    u8 pad168[8];
    s32 width1;                  // 0x170
    s32 height1;                 // 0x174
    u8 alpha0;                   // 0x178
    u8 alpha1;                   // 0x179
    s16 alphaFrame;              // 0x17A
    s32 alphaFrames;             // 0x17C
    u8 alphaFading;              // 0x180
    u8 pad181;
    u16 wait;                    // 0x182
    s8 renderMode;
    u8 pad185[3];
    s32 layer;                   // 0x188
    s8 blendMode;                // 0x18C
} FclFadeRect;

extern void (*jtbl_008873EC[])(void *);
extern u8 D_00793E80[];
extern void (*D_00887300[])(s32 , s32 );
extern void RpSkyRenderStateSet(s32 , s32 );
extern u8 *kwlnGetCamera(void);
extern f32 fclEaseInterpolate(s64 , f32 , f32 , f32 , f32 );
extern s32 fclAddClamped(s32 , s32 , s32 , s32 , s8 );
extern s32 fclSubClamped(s32 , s32 , s32 , s32 , s8 );
/* Store the task work control byte when a task is supplied. */
// FUN_002B5100
void fclFadeRectSetControl(u8 *task, s8 value)
{
    if (task != NULL) {
        ((FclFadeRect *)((struct KwlnTask *)task)->work)->unk08 = value;
    }
}

/* Set the fade-rectangle render states, selecting the alternate blend preset from its work record. */
// FUN_002B5120
void fclFadeRectSetRenderStates(s32 unusedQueue, u8 *work)
{
    void (*(*base)[1])(s32, s32);
    s8 blendMode;

    base = (void (*(*)[1])(s32, s32))D_00887300;
    (*base)[0](6, 1);
    (*base)[0](7, 2);
    (*base)[0](8, 1);
    (*base)[0](0xA, 5);
    (*base)[0](0xB, 6);
    (*base)[0](9, 2);
    (*base)[0](0xC, 1);
    (*base)[0](1, 0);
    if (((FclFadeRect *)work)->renderMode == 1) {
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
        blendMode = ((FclFadeRect *)work)->blendMode;
        switch (blendMode) {
        case 1:
            RpSkyRenderStateSet(2, 0x48);
            RpSkyRenderStateSet(3, 0x71801);
            return;
        case 2:
            RpSkyRenderStateSet(2, 0x42);
            RpSkyRenderStateSet(3, 0x71801);
            break;
        }
    }
}


/* Advance rectangle movement and alpha transitions, rebuild four projected vertices and queue their draw. */
#pragma push
#pragma opt_loop_invariants on
/* measured: retail hoists loop-invariant loads out of the vertex loop, so loop invariants are on. */
// FUN_002B52A0
s32 fclFadeRectTaskUpdate(u8 *task)
{
    /* far-plane depth inside the render-state record; sized so that it is
       re-read after the vertex stores, as retail does */
    extern f32 D_008872F8[4];
    extern u8 *PrimQueueDrawPrimitive(void *task, s32 , void *, s32 );
    FclFadeRect *work;
    f32 q;
    s32 i;
    s32 j;
    u8 *pkt;

    work = (FclFadeRect *)((struct KwlnTask *)task)->work;
    if (work->done == 1) {
        return 0;
    }
    switch (work->state) {
    case 2:
        if (work->wait == 0) {
            if (work->mode == 0) {
                work->x = fclEaseInterpolate(0, work->x0 + (f32)(work->width1 / 2), work->x0, (f32)work->frame, (f32)work->frames);
                work->y = fclEaseInterpolate(0, work->y0 + (f32)(work->height1 / 2), work->y0, (f32)work->frame, (f32)work->frames);
                work->width = fclEaseInterpolate(0, (f32)work->width0, (f32)work->width1, (f32)work->frame, (f32)work->frames);
                work->height = fclEaseInterpolate(0, (f32)work->height0, (f32)work->height1, (f32)work->frame, (f32)work->frames);
            } else if (work->mode == 1) {
                work->x = fclEaseInterpolate(0, work->x0, work->x0 + (f32)(work->width0 / 2), (f32)work->frame, (f32)work->frames);
                work->y = fclEaseInterpolate(0, work->y0, work->y0 + (f32)(work->height0 / 2), (f32)work->frame, (f32)work->frames);
                work->width = fclEaseInterpolate(0, (f32)work->width0, (f32)work->width1, (f32)work->frame, (f32)work->frames);
                work->height = fclEaseInterpolate(0, (f32)work->height0, (f32)work->height1, (f32)work->frame, (f32)work->frames);
            } else if (work->mode == 2) {
                work->x = fclEaseInterpolate(0, work->x0, work->x1, (f32)work->frame, (f32)work->frames);
                work->y = fclEaseInterpolate(0, work->y0, work->y1, (f32)work->frame, (f32)work->frames);
            } else if (work->mode == 3) {
                work->x = fclEaseInterpolate(0, work->x0, work->x1, (f32)work->frame, (f32)work->frames);
                work->y = fclEaseInterpolate(0, work->y0, work->y1, (f32)work->frame, (f32)work->frames);
                work->width = fclEaseInterpolate(0, (f32)work->width0, (f32)work->width1, (f32)work->frame, (f32)work->frames);
                work->height = fclEaseInterpolate(0, (f32)work->height0, (f32)work->height1, (f32)work->frame, (f32)work->frames);
            } else if (work->mode == 4) {
                work->x = fclEaseInterpolate(0, work->x0, work->x1, (f32)work->frame, (f32)work->frames);
                work->y = fclEaseInterpolate(0, work->y0, work->y1, (f32)work->frame, (f32)work->frames);
                work->width = fclEaseInterpolate(0, (f32)work->width0, (f32)work->width1, (f32)work->frame, (f32)work->frames);
                work->height = fclEaseInterpolate(0, (f32)work->height0, (f32)work->height1, (f32)work->frame, (f32)work->frames);
            }
            if (work->alphaFading == 1) {
                work->color[0][3] = fclEaseInterpolate(2, (f32)work->alpha0, (f32)work->alpha1, (f32)work->alphaFrame, (f32)work->alphaFrames);
                for (j = 1; j < 4; j++) {
                    work->color[j][3] = work->color[0][3];
                }
                work->alphaFrame = fclAddClamped(work->alphaFrame, 1, work->alphaFrames, 0, 1);
                if (work->alphaFrame >= work->alphaFrames) {
                    work->color[0][3] = work->alpha1;
                    for (j = 1; j < 4; j++) {
                        work->color[j][3] = work->color[0][3];
                    }
                    work->alphaFading = 0;
                }
            }
            if (work->frame < work->frames) {
                work->frame++;
            } else {
                work->mode = -1;
                if (work->width == 0 || work->height == 0) {
                    work->done = 1;
                }
                if (work->alphaFading == 0 && work->mode == -1) {
                    work->state = 1;
                }
            }
        } else {
            work->wait = fclSubClamped(work->wait, 1, 0, 0, 1);
            return 0;
        }
    case 0:
    case 1:
        q = 1.0f / ((KwlnView *)kwlnGetCamera())->unk80;
        for (i = 0; i < 4; i++) {
            f32 farZ = D_008872F8[0];

            work->vtx[i].z = farZ - work->depth;
            work->vtx[i].q = q;
            work->vtx[i].r = work->color[i][0];
            work->vtx[i].g = work->color[i][1];
            work->vtx[i].b = work->color[i][2];
            work->vtx[i].a = work->color[i][3];
        }
        work->vtx[0].x = work->x;
        work->vtx[0].y = work->y;
        work->vtx[1].x = work->x + (f32)work->width;
        work->vtx[1].y = work->y;
        work->vtx[2].x = work->x;
        work->vtx[2].y = work->y + (f32)work->height;
        work->vtx[3].x = work->x + (f32)work->width;
        work->vtx[3].y = work->y + (f32)work->height;
        pkt = PrimQueueDrawPrimitive(D_00793E80 + work->layer * 0x30, 4, work->vtx, 4);
        ((PrimQueueNode *)pkt)->callback = (void *)fclFadeRectSetRenderStates;
        ((PrimQueueNode *)pkt)->argument.data = (u8 *)work;
        break;
    case 3:
        return -1;
    }
    return 0;
}
#pragma pop

// FUN_002B5C60
void fclFadeRectTaskDestroy(u8 *task)
{
    jtbl_008873EC[0](((struct KwlnTask *)task)->work);
}
