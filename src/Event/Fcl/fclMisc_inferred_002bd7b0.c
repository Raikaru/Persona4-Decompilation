#include "sdk_snd_internal.h"
#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fcl_assist_internal.h"
#include "kwln_task_internal.h"
#include "kwln_view_internal.h"
#include "message_handle.h"
#include "shd_misc_internal.h"

/* Shop task work: a byte state followed by the draw-task handle. */
typedef struct FclShopMainWork {
    s8 state;
    u8 pad01[3];
    s32 drawTask;
} FclShopMainWork;

extern void (*jtbl_008873EC[])(void *);


extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern char D_0063F2A0[];
extern char D_007488E8[];


extern u8 *D_00882F40[];
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern u8 D_0063F1F0[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s32 iGpffffb57c;
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void fieldSceneUnload(void);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern void fieldSceneLoad(s32 fieldId, s32 roomId);
extern s32 fieldSceneLoadStep(void);
extern s32 mtSceneResListPrepareAll(void);
extern void fadeBeginTransition(s32 mode, s32 duration);
extern s32 fadeBeginReturnTransition(s32 mode, s32 duration);
extern s32 fadeStatus(void);
extern s32 fclShopDrawIsReady(s32 task);
extern void fclShopDrawSetMode(s32 task, s32 state);
extern void func_003e9cb0(s32 frame, void *transform, s32 combine);
extern s32 kwlnTaskGetTaskByName(void *name);
extern u8 *kwlnGetCamera(void);
extern s32 MT_Scene_GetCameraResFirst(void);
extern f32 MT_Scene_GetCameraFov(void);
extern void K_View_SetFov(void *camera, f32 fov);
extern u8 D_0063F3B0[];


extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 *D_0063F110[];
extern s8 D_007488C0[];


/* Retail digit RGBA occupies four unaligned bytes in the draw record; these guarded packed views
 * keep the native FclDrawColor call interface. */
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


extern void fclFadeRectSetRenderStates(s32 unusedQueue, u8 *work);
/* measured: retail loads the D_00887300 vtable base address once into a saved register, which needs
 * a typed local with propagation off. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Reset the shared window record and install its message window with style 1. */
// FUN_002BD7B0
s32 fclMiscEnsureMesWindow(u8 *object)
{
    FclAssistHandle *window;
    s32 handle;

    window = (FclAssistHandle *)D_00882F60;
    if (window != NULL) {
        window->handle = -1;
        window->mode = 0;
        window->suspended = 0;
        window->pending = -1;
        window->unk0c = 1;
        window->unk0d = 1;
    }
    if (window->handle < 0) {
        handle = itfMesWindowInstall(object);
        window->handle = handle;
        itfMesWindowSetStyle(handle, 1);
        return 1;
    }
    return 0;
}

/* Bind an item record to the shared message window and start its animation. */
// FUN_002BD840
s32 fclMesWindowShowItemRecord(s32 record)
{
    FclAssistHandle *window;

    window = (FclAssistHandle *)D_00882F60;
    if (window->handle < 0) {
        return 0;
    }
    itfMesWindowSetStyle(window->handle, 1);
    itfMesWindowSetFlagBits(window->handle, 0x200000);
    itfMesWindowBindRecord(window->handle, record, 0);
    window->mode = 1;
    itfMesWindowSetAnim(window->handle, -1);
    return 1;
}

/* Sequence shop scene loading, camera setup, fades, and draw-task completion.
 * The camera API has no shared layout here; +4 is its scene-camera handle. */
// FUN_002BD8E0
s32 fclShopMainUpdate(u8 *task)
{
    s8 state;
    FclShopMainWork *work;
    u8 *camera;
    u8 *sceneCamera;

    work = (FclShopMainWork *)((struct KwlnTask *)task)->work;
    state = work->state;
    switch (state) {
    case 1:
        fieldSceneLoad(8, 4);
        work->state = 2;
    case 2:
        if ((fieldSceneLoadStep() != 0) && (mtSceneResListPrepareAll() != 0)) {
            if (fclShopDrawIsReady(work->drawTask) == 0) {
                return 0;
            }
            sdkSndPlayCue(0x15, 1);
            camera = kwlnGetCamera();
            K_View_SetFov(camera, MT_Scene_GetCameraFov());
            sceneCamera = kwlnGetCamera();
            func_003e9cb0(((KwlnView *)sceneCamera)->camera, (void *)MT_Scene_GetCameraResFirst(), 0);
            work->state = 3;
        }
        goto block_26;
    case 3:
        fadeBeginReturnTransition(1, 0);
        work->state = 4;
    case 4:
        if (fadeStatus() != 0) {
            fclShopDrawSetMode(work->drawTask, 0xD);
            work->state = 7;
        }
        goto block_26;
    case 5:
        fadeBeginTransition(1, 0);
        work->state = 6;
    case 6:
        if (fadeStatus() != 0) {
            work->state = 0x11;
        }
        goto block_26;
    case 7:
        if (kwlnTaskGetTaskByName(&D_0063F3B0) == 0) {
            work->state = 5;
        }
        goto block_26;
    case 17:
        return -1;
    case 35:
        return -1;
    default:
    block_26:
        return 0;
    }
}

/* Unload the field scene and free the shop task work block. */
// FUN_002BDB10
void fclShopMainDestroy(u8 *task)
{
    fieldSceneUnload();
    jtbl_008873EC[0](((struct KwlnTask *)task)->work);
}

