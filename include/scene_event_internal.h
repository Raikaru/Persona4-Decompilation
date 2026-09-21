#ifndef SCENE_EVENT_INTERNAL_H
#define SCENE_EVENT_INTERNAL_H

#include "type.h"

typedef struct SVec3 {
    f32 x, y, z;
} SVec3;

/* Transform pointers address three consecutive floats; NULL leaves that
   transform unchanged. Resource IDs contain the packed 16-bit type/index. */
void func_00146e60(u16 resourceId, u8 *position, u8 *angles);
void func_00146ee0(u16 resourceId, u8 *scale);

s32 func_00268f20(u32 resourceId, SVec3 *position, u32 duration, s8 easing);
s32 func_002690b0(u32 resourceId, u8 *fromPosition, u8 *toPosition,
                  f32 fromYaw, f32 toYaw, f32 fromPitch, f32 toPitch,
                  f32 fromDistance, f32 toDistance, s32 duration, s8 easing);
s32 func_00269340(u32 resourceId, SVec3 *angles, u32 duration, u8 easing);
s32 func_00269690(u32 resourceId, f32 fieldOfView, s32 duration);
s32 func_00269740(u32 resourceId);
void func_0026bf70(u32 resourceId);

/* The matrix output is sixteen words; both input vectors contain three floats. */
void func_00146f50(u32 *matrix, const void *position, u32 *angles);

/* The path address refers to a complete 304-byte count/flags/vector record. */
u32 func_002692d0(u32 resourceId, u32 pathAddress, f32 speed, u32 loop);
s32 func_0026bda0(u32 resourceId, s32 motion, u8 sound, s16 start, s16 end, s16 flags);
void func_002933a0(u16 resourceId, s32 motion, f32 speed);
void func_00293550(u16 resourceId, u16 duration, s32 motion, f32 speed);
void func_00293710(u16 resourceId, s32 motion, f32 positionX, f32 positionY,
                  f32 positionZ, f32 angle, s32 flags, u8 *settings);

/* Queued animation records store signed 32-bit motion and frame values.
   The model provider narrows them to the signed/unsigned 16-bit model API. */
u32 func_00269820(u16 *resource, s32 layer, s32 animation, s32 frame,
                  s32 flags, s32 blend, f32 speed);

/* Path sampling keeps elapsed and total distances together before outputs. */
f32 func_0026cef0(s8 *path, f32 distance, f32 total,
                  f32 *position, f32 *rotation);

#endif
