#ifndef SCENE_EVENT_INTERNAL_H
#define SCENE_EVENT_INTERNAL_H

#include "type.h"

typedef struct SVec3 {
    f32 x, y, z;
} SVec3;

/* Transform pointers address three consecutive floats; NULL leaves that
   transform unchanged. Resource IDs contain the packed 16-bit type/index. */
void MT_Scene_SetResPlacement(u16 resourceId, u8 *position, u8 *angles);
void MT_Scene_SetResAngles(u16 resourceId, u8 *scale);

s32 MT_Scene_BeginResTimedMove(u32 resourceId, SVec3 *position, u32 duration, s8 easing);
s32 MT_Scene_SetResCurveParamsById(u32 resourceId, u8 *fromPosition, u8 *toPosition,
                  f32 fromYaw, f32 toYaw, f32 fromPitch, f32 toPitch,
                  f32 fromDistance, f32 toDistance, s32 duration, s8 easing);
s32 MT_Scene_BeginResRotation(u32 resourceId, SVec3 *angles, u32 duration, u8 easing);
s32 MT_Scene_BeginResFovChange(u32 resourceId, f32 fieldOfView, s32 duration);
s32 MT_Scene_ResetResMotion(u32 resourceId);
void MT_Scene_ClearResState(u32 resourceId);

/* The matrix output is sixteen words; both input vectors contain three floats. */
void MT_Scene_BuildResMatrix(u32 *matrix, const void *position, u32 *angles);

/* The path address refers to a complete 304-byte count/flags/vector record. */
u32 MT_Scene_BeginResPathAnimById(u32 resourceId, u32 pathAddress, f32 speed, u32 loop);
s32 MT_Scene_SetResSoundRange(u32 resourceId, s32 motion, u8 sound, s16 start, s16 end, s16 flags);
void evtModelQueueMotion(u16 resourceId, s32 motion, f32 speed);
void evtModelQueueTimedMotion(u16 resourceId, u16 duration, s32 motion, f32 speed);
void evtModelQueueMotionAt(u16 resourceId, s32 motion, f32 positionX, f32 positionY,
                  f32 positionZ, f32 angle, s32 flags, u8 *settings);

/* Queued animation records store signed 32-bit motion and frame values.
   The model provider narrows them to the signed/unsigned 16-bit model API. */
u32 MT_Scene_SetResMotion(u16 *resource, s32 layer, s32 animation, s32 frame,
                  s32 flags, s32 blend, f32 speed);

/* Path sampling keeps elapsed and total distances together before outputs. */
f32 MT_Scene_SamplePath(s8 *path, f32 distance, f32 total,
                  f32 *position, f32 *rotation);

extern s32 D_00882170[];

/* Event TU prototypes: functions defined in src/Event and the scene-event bucket. */
void func_00285260(void);
void evtSetNodeResourcesEnabled();
s32 evtFindTask(void);
void evtDestroyEventScene(u8 *arg0, s32 arg1);
void evtEnvSlotRestore(int, int);
void evtCamPosRestore(int);
u64 func_00298190(s16 param_1, int param_2);
void evtUpdateCutin(u8 *, u8 *, u8 *, s32, u8 *);
void evtSelectRangeChoice();
void sceneLightSlotsReset(void);
void evtSyncResManagerNodes();
void evtStepLayerByChoice();
void evtModelDestroy(void);
void func_0028be70();
void evtResetPendingState(int param_1);
void func_002e0dd0(void);
void evtReleaseRes(u8 *arg0);
void func_00290b00(u32 *param_1);
void func_00291900(void);
void func_00290fa0(u8 *arg0);
void func_00290470(s32 *arg0, u32 *arg1);
void func_00291470();
void func_00291220();
void func_002913d0();
s32 func_0028bef0(s32, u8 *, s32 *, s32 *);
void func_002909b0(s32 *, s32, s32, s32, s32);
s32 func_00290e50(u8 *, s32);
void evtMemAccount(s32 arg0, s32 arg1);
s32 evtSlotTableIdle(void);
s32 evtCheckCondition(u8 *arg0);
void evtListInsertSorted(u32 *, u32 *);
s32 evtKeyIndex(s32 arg0);
extern void *evtEnvSlot(int arg0, int arg1);
void func_0028f990(s32 arg0, f32 fparg0, f32 *arg1, f32 *arg2, f32 *arg3);
void sceneLightSlotSet(s32 slot, s32 mode, s32 modeValue, f32 *arg3, f32 *arg4, f32 *arg5);
f32 evtCommandParamF32(s32 param);
void func_0028b270(int param_1);
void func_0028bfb0(u8 *arg0, s32 arg1, u8 **arg2, u8 **arg3);
void func_0028c080(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3, f32 *arg4, f32 *arg5);
void func_002866c0(u8 *arg0, u8 *arg1);
s32 func_00291360(int param_1, int param_2);
u32 func_002909a0(u32 *object);
s32 func_00290de0(void *object);
void func_00290940(u32 *param_1);

#endif
