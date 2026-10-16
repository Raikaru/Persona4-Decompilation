#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "message_handle.h"
#include "shd_misc_internal.h"
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}
extern void (*jtbl_008873EC[])(void *);
extern void nmMesWindowClearSlotTable(void);
extern void nmMesWindowInitRecord(s32 *arg0);
extern void nmMesWindowStepCurrent(s32 arg0);
extern void fclMiscCloseActiveHandle(void);



extern u64 fclMiscPruneLists(u8 *arg0);
extern s32 func_002bc0e0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern void kAssertFail(const void *arg0, s32 arg1);
extern char D_0063F2A0[];
extern char D_007488E8[];
extern void sdkSndResetChannel(s32 arg0, s32 arg1);


extern u32 datItemPrice(s16 arg0);
extern u8 *D_00882F40[];
extern void itfMesWindowSetString(s32 handle, s32 variable, char *text);
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern u8 D_0063F1F0[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s8 nmMesWindowFindFreeSlot(void);
extern s32 iGpffffb57c;
extern s32 *nmMesWindowCurrent();
extern s32 nmMesWindowCurrentAnim(void);
extern void itfMesWindowDrawEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 itfMesWindowQueueEntry(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6);
extern u32 datEntryGetFlags(s16 item);
extern s32 func_002be1e0(s32 arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void fieldSceneUnload(void);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void itfMesWindowSetState(s32 arg0, s8 arg1);
extern void itfMesWindowRelease(s32 arg0);
extern void itfMesWindowClear(s32 arg0, s32 arg1);
extern s32 itfMesWindowState();
extern s32 itfMesWindowGetAnim(s32 arg0);
extern void itfMesWindowLayout(s32 arg0, s32 arg1);
extern void itfMesWindowSetCursor(s32 arg0, s32 arg1);
extern u32 itfMesWindowSetParam(s32 arg0, s32 arg1, s32 arg2);
extern void nmMesWindowSetCurrentRunning(s32 arg0);
extern void nmMesWindowSetSlotRunning(s64 arg0, s32 arg1);
extern u32 fclGetMoney(void);
extern u8 *func_002e2170(u8 *arg0, s32 arg1, s32 arg2);
extern void sprintf();
extern s64 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s16 arg0);
extern s32 sdkSpriteRequestLoad(void *arg0);
extern s32 func_0046a750(s32 arg0);
extern void sdkSpriteRelease(void *arg0);
extern void func_002e2240(void *arg0, void *arg1, void *arg2);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern f32 cosf(f32 arg0);
extern f32 sinf(f32 arg0);
extern s32 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern s32 func_002be100(s32 arg0);
extern void fieldSceneLoad(s32 arg0, s32 arg1);
extern s32 fieldSceneLoadStep(void);
extern s32 mtSceneResListPrepareAll(void);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 func_00122640(s32 arg0, s32 arg1);
extern s32 fadeStatus(void);
extern s32 fclShopDrawIsReady(s32 arg0);
extern void fclShopDrawSetMode(s32 arg0, s32 arg1);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern void sdkSndPlayCue(s32 arg0, s32 arg1);
extern s32 kwlnTaskGetTaskByName(void *arg0);
extern u8 *kwlnGetCamera(void);
extern s32 MT_Scene_GetCameraResFirst(void);
extern f32 MT_Scene_GetCameraFov(void);
extern void K_View_SetFov(void *arg0, f32 arg1);
extern u8 D_0063F3B0[];


extern s32 smapWorldToColumn(u8 *arg0);
extern s32 smapWorldToRow(u8 *arg0);

extern f32 smapPlayerOffsetX(s32 arg0, f32 fparg0);
extern f32 smapPlayerOffsetZ(s32 arg0, f32 fparg0);
extern void mapSymbolMarkerDraw(u8 *arg0, s64 arg1, f32 fparg0, s32 arg2);
extern u8 *mdlGetMatrix(u32 arg0);
extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern void strcpy(void *arg0, ...);
extern void strcat(void *arg0, void *arg1);
extern void strncpy(void *arg0, void *arg1, s32 arg2);
extern void frFontExCopyString(void *arg0, void *arg1, s32 arg2);
extern s32 func_00443010(u8 *arg0, u8 *arg1);
extern s32 fclTagTextLength(u8 *arg0, s64 arg1);
extern u8 *D_0063F110[];
extern s8 D_007488C0[];



/* Retail digit RGBA occupies the four bytes at draw+0x75.
   MWCC requires packed after the typedef name. These guarded
   storage views preserve the native FclDrawColor call interface.
   See docs/probe_archive/Fcl_digit_packed_storage_ui_20261006. */
#ifdef NON_MATCHING
typedef union {
    FclDrawColor channels;
    u32 word;
} FclDigitColorStorage;
typedef struct {
    u32 word;
} FclDigitStoredWord __attribute__((packed));
typedef struct {
    u8 prefix;
    FclDigitStoredWord storage;
} FclDigitStoredWordAlignment;
typedef char FclDigitStoredWordSize[(sizeof(FclDigitStoredWord) == 4) ? 1 : -1];
typedef char FclDigitStoredWordByteAligned[(sizeof(FclDigitStoredWordAlignment) == 5) ? 1 : -1];
typedef char FclDigitColorStorageSize[(sizeof(FclDigitColorStorage) == 4) ? 1 : -1];
#endif

extern FclVec2 fclMakeVec2(f32 x, f32 y);
extern f32 fclEaseInterpolate(s64 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 fclAddClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);



extern s32 fclSubClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);




#pragma opt_rebuildconditionals off
extern s32 fclDecimalDigitCount(s32 arg0);
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
#pragma opt_loop_invariants off

// FUN_002B5100
void func_002b5100(u8 *arg0, s8 arg1)
{
    if (arg0 != NULL) {
        *(s8 *)(*(u8 **)(arg0 + 0x38) + 8) = arg1;
    }
}
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
#pragma opt_propagation off
// FUN_002B5120
void func_002b5120(s32 arg0, u8 *arg1)
{
    void (**base)(s32 arg0, s32 arg1);
    s8 temp_5;

    base = D_00887300;
    base[0](6, 1);
    base[0](7, 2);
    base[0](8, 1);
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, 0);
    if (*(s8 *)(arg1 + 0x184) == 1) {
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
        temp_5 = *(s8 *)(arg1 + 0x18C);
        switch (temp_5) {
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
/* measured: restores opt_propagation after func_002b5120. */
#pragma opt_propagation on
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
    u8 pad001[0xF];
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
    u8 pad184[4];
    s32 layer;                   // 0x188
} FclFadeRect;

/* measured: opt_loop_invariants on hoists the %hi of D_008872F8 above the vertex loop (156 words
   without it). */
// FUN_002B52A0
#pragma opt_loop_invariants on
s32 func_002b52a0(u8 *arg0)
{
    /* far-plane depth inside the render-state record; sized so that it is
       re-read after the vertex stores, as retail does */
    extern f32 D_008872F8[4];
    extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
    FclFadeRect *work;
    f32 q;
    s32 i;
    s32 j;
    u8 *pkt;

    work = *(FclFadeRect **)(arg0 + 0x38);
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
        q = 1.0f / *(f32 *)(kwlnGetCamera() + 0x80);
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
        *(void **)(pkt + 8) = (void *)func_002b5120;
        *(FclFadeRect **)(pkt + 0x10) = work;
        break;
    case 3:
        return -1;
    }
    return 0;
}
#pragma opt_loop_invariants off
// FUN_002B5C60
void func_002b5c60(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
/* Preserve the signed-halfword zero test without merging it with the
   preceding sentinel comparison. */
#pragma push
#pragma opt_common_subs off
static inline s32 fclDigitIsZero(const s16 *value)
{
    return *value == 0;
}
#pragma pop
#pragma push
#pragma opt_dead_assignments off
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs on
#pragma opt_common_subs on
#pragma pop
#pragma opt_common_subs off
#pragma opt_common_subs on










#pragma push
#pragma opt_propagation off
#pragma pop







