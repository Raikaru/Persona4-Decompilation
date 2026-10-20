/* Original translation unit evtModel.c (from __FILE__ assert strings). */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"

extern s32 kwlnTaskGetTaskByName();
extern void kwlnTaskDestroyWithHierarchy();
extern u8 D_0063C958[];

/* Model event update state machines share the 0x4C-byte queue record below;
   each callback receives an unused context followed by the record. */
typedef struct {
    f32 v[4];
} F32x4;

typedef struct {
    u16 id;      /* 0x00 */
    u16 targetId;     /* 0x02 */
    s32 motion;  /* 0x04: indexes D_0063C930 when queued */
    f32 speed;   /* 0x08 */
    u8 padC[4];  /* 0x0C */
    f32 yaw;    /* 0x10 */
    u8 pad14[4]; /* 0x14 */
    s32 duration;  /* 0x18 */
    s32 sound;   /* 0x1C */
    s16 soundStart;    /* 0x20 */
    u8 pad22[2];
    s16 soundEnd;    /* 0x24 */
    u8 pad26[2];
    s16 soundFlags;    /* 0x28 */
    u8 pad2A[2]; /* 0x2A */
    s32 (*step)(u8 **, u8 *); /* 0x2C */
    f32 phase;  /* 0x30 */
    f32 lookAtSnapshot[4];  /* 0x34 */
    s32 flags;   /* 0x44: bit 0 requests look-at on finish; bit 1 enables sound */
    s16 angleStableFrames; /* 0x48 */
    s16 finalStableFrames; /* 0x4A */
} EvtModelRec;

/* nmlist.c allocates a 0x18-byte node prefix and stores its payload at +0x14.
   Its 0x28-byte manager prefix embeds the list at +4 and work pointer at +0x24. */
typedef struct EvtModelQueueNode {
    u32 key;
    u32 unk04;
    u32 size;
    struct EvtModelQueueNode *prev;
    struct EvtModelQueueNode *next;
    EvtModelRec *entry;
} EvtModelQueueNode;
typedef struct EvtModelQueue {
    u32 unk00;
    EvtModelQueueNode *head;
    EvtModelQueueNode *tail;
    EvtModelQueueNode *cursor;
    u16 count;
    u8 pad12[0x12];
    u8 **work;
} EvtModelQueue;

/* Prefix copied by the queue constructors (0x2C bytes); the callback/state
   suffix is initialized separately in the 0x4C-byte EvtModelRec. */
typedef struct EvtModelParameters {
    s16 resourceId;
    u16 duration;
    s32 motion;
    f32 speed;
    u8 pad0C[0x20];
} EvtModelParameters;
/* Partial model view: the alternating look-at step samples this float to
   scale its blend; no interpretation beyond that use is established. */
typedef struct Model {
    u8 pad00[0x144];
    f32 unk144;
} Model;


extern u8 D_0063C948[];
extern s32 D_0063C930[];

/* GP-relative float globals (P4 gp = 0x7690F0). */
extern f32 fGpffff8218; /* gp -0x7de8 */
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern f32 fGpffff8478; /* gp -0x7b88 */
extern f32 fGpffff8504; /* gp -0x7afc */
extern f32 fGpffff8510; /* gp -0x7af0 */
extern f32 fGpffff8514; /* gp -0x7aec */
extern f32 D_00761260;  /* gp -0x7e90 */

extern s32 mtMiscResourceValue(u32 resourceId);
// lint: allow H011 -- measured: a u16 prototype makes callers mask wide id arguments, unlike
// retail.
extern void *MT_Scene_GetRes(u32 resTypeId);

extern u8 *nmListAllocManager(s32 payloadSize, s32 onInsert, s32 onRemove, s32 onUpdate);
extern void nmListDestroyManager(void *manager);
extern u8 *nmListAppendNode(void *manager, s32 owner, s32 payloadSize);
extern void comuDataRemoveAndReleaseNode(void *owner, void *source, void *nodeStorage);
extern void RwV3dNormalize(void *a, void *b);
extern void memcpy(void *dst, void *src, s32 size);
extern void memset(void *dst, s32 value, s32 size);
extern s32 func_0044b310(s32 a);
extern f32 func_0044b920(f32 value);
extern s32 fptodp(f32 a);
extern f32 dptofp(s32 a);

extern u8 **kwlnTaskGetWork();
extern void kAssertFail(void *file, s32 line);
extern void *mdlGetMatrix(s32 model);
extern void mdlSetBlendWeight(s32 model, f32 value);
extern void mdlSetLookAtDirection(s32 model, void *direction);
extern void mdlSetTrackScaleRange(s32 model, f32 yawOffset, f32 pitchOffset);
extern u8 *mdlGetLookAtSubobject(s32 model);
extern void mdlSetLookAtRequested(s32 model);
extern s32 mdlHasActiveMode(s32 model);
extern f32 effMiscQuatAngle(void *firstQuaternion, f32 *secondQuaternion);

// Single-model motion state machine: state 0 ramps the blend weight from speed, state 1 aims the
// look-at subobject at dst, then a timed step ends the motion.
// FUN_00291B60
s32 evtModelStepLookAt(s32 unusedContext, u8 *recordBytes) {
    EvtModelRec *rec = (EvtModelRec *)recordBytes;
    f32 speed;
    f32 angleCosine;
    f32 blendWeight;
    s32 model;
    s32 state;
    s32 settled;
    s32 flags;

    speed = rec->speed;
    model = mtMiscResourceValue(rec->id);
    if (model == 0) {
        return 1;
    }
    state = (u32)rec->phase;
    if (state == 0) {
        if (mdlHasActiveMode(model) == 0) {
            rec->flags |= 1;
        }
        mdlSetTrackScaleRange(model, 30.0f, 0.0f);
        blendWeight = fGpffff8218 * speed;
        if (!(blendWeight <= 1.0f)) {
            blendWeight = 1.0f;
        } else if (blendWeight < 0.0f) {
            blendWeight = 0.0f;
        }
        mdlSetBlendWeight(model, blendWeight);
        rec->phase += 1.0f;
        goto common;
    }
    if (state == 1) {
        angleCosine = effMiscQuatAngle(mdlGetLookAtSubobject(mtMiscResourceValue(rec->id)), rec->lookAtSnapshot);
        if ((angleCosine < -1.0f) || !(angleCosine <= 1.0f)) {
            kAssertFail(&D_0063C948, 0x176);
        }
        if (func_0044b920(dptofp(func_0044b310(fptodp(angleCosine)))) < fGpffff8478) {
            rec->angleStableFrames = rec->angleStableFrames + 1;
            if (rec->angleStableFrames >= 2) {
                rec->angleStableFrames = 0;
                settled = 1;
            } else {
                goto state1_counter;
            }
        } else {
            rec->angleStableFrames = 0;
state1_counter:
            settled = 0;
        }
        if (settled != 0) {
            mdlSetTrackScaleRange(model, 0.0f, 0.0f);
            blendWeight = fGpffff8218 * speed;
            if (!(blendWeight <= 1.0f)) {
                blendWeight = 1.0f;
            } else if (blendWeight < 0.0f) {
                blendWeight = 0.0f;
            }
            mdlSetBlendWeight(model, blendWeight);
            rec->phase += 1.0f;
        }
        goto common;
    }
    if (state == 2) {
        angleCosine = effMiscQuatAngle(mdlGetLookAtSubobject(mtMiscResourceValue(rec->id)), rec->lookAtSnapshot);
        if ((angleCosine < -1.0f) || !(angleCosine <= 1.0f)) {
            kAssertFail(&D_0063C948, 0x176);
        }
        if (func_0044b920(dptofp(func_0044b310(fptodp(angleCosine)))) < fGpffff8514) {
            rec->finalStableFrames = rec->finalStableFrames + 1;
            if (rec->finalStableFrames >= 2) {
                rec->angleStableFrames = 0;
                settled = 1;
            } else {
                goto state2_counter;
            }
        } else {
            rec->finalStableFrames = 0;
state2_counter:
            settled = 0;
        }
        if (settled != 0) {
            flags = rec->flags;
            if (flags & 1) {
                rec->flags = flags & ~1;
                mdlSetLookAtRequested(model);
            }
            return 1;
        }
    }
common:
    *(F32x4 *)rec->lookAtSnapshot = *(F32x4 *)mdlGetLookAtSubobject(model);
    return 0;
}

// Variant of evtModelStepLookAt with a different track scale range and blend factor.
// FUN_00291FA0
s32 evtModelStepLookAtAlt(s32 unusedContext, u8 *recordBytes) {
    EvtModelRec *rec = (EvtModelRec *)recordBytes;
    f32 unusedBlendValue;
    f32 firstBlendLimit;
    f32 firstAngleCosine;
    f32 secondBlendLimit;
    f32 secondAngleCosine;
    f32 thirdAngleCosine;
    f32 fourthBlendLimit;
    f32 fourthAngleCosine;
    f32 finalAngleCosine;
    f32 speed;
    f32 initialAngleCosine;
    f32 initialBlendWeight;
    f32 firstTurnBlend;
    f32 firstTrackBlend;
    f32 secondTurnBlend;
    f32 secondTrackBlend;
    f32 thirdTurnBlend;
    f32 thirdTrackBlend;
    f32 fourthTurnBlend;
    f32 fourthTrackBlend;
    f32 finalBlendWeight;
    f32 firstTrackScale;
    f32 secondTrackScale;
    f32 thirdTrackScale;
    f32 fourthTrackScale;
    s16 unusedCounterFirst;
    s16 unusedCounterSecond;
    s16 unusedCounterThird;
    s16 unusedCounterFourth;
    s16 unusedCounterFifth;
    s16 unusedCounterFinal;
    s32 model;
    s32 flags;
    s32 firstSettled;
    s32 secondSettled;
    s32 thirdSettled;
    s32 fourthSettled;
    s32 fifthSettled;
    s32 finalSettled;
    s32 state;

    speed = rec->speed;
    model = mtMiscResourceValue(rec->id);
    if (model == 0) {
        return 1;
    }
    state = (u32)rec->phase;
    if (state == 0) {
        if (mdlHasActiveMode(model) == 0) {
            rec->flags |= 1;
        }
        mdlSetTrackScaleRange(model, 0.0f, 15.0f);
        initialBlendWeight = fGpffff82cc * speed;
        if (!(initialBlendWeight <= 1.0f)) {
            initialBlendWeight = 1.0f;
        } else if (initialBlendWeight < 0.0f) {
            initialBlendWeight = 0.0f;
        }
        mdlSetBlendWeight(model, initialBlendWeight);
        rec->phase += 1.0f;
        goto common;
    }
    if (state == 1) {
        initialAngleCosine = effMiscQuatAngle(mdlGetLookAtSubobject(mtMiscResourceValue(rec->id)), rec->lookAtSnapshot);
        if ((initialAngleCosine < -1.0f) || !(initialAngleCosine <= 1.0f)) {
            kAssertFail(&D_0063C948, 0x176);
        }
        if (func_0044b920(dptofp(func_0044b310(fptodp(initialAngleCosine)))) < fGpffff8478) {
            rec->angleStableFrames = rec->angleStableFrames + 1;
            if (rec->angleStableFrames >= 2) {
                rec->angleStableFrames = 0;
                firstSettled = 1;
            } else {
                goto block_21;
            }
        } else {
            rec->angleStableFrames = 0;
block_21:
            firstSettled = 0;
        }
        if (firstSettled != 0) {
            mdlSetTrackScaleRange(model, 0.0f, -17.5f);
            firstTurnBlend = fGpffff8504 * speed;
            if (!(firstTurnBlend <= 1.0f)) {
                firstTurnBlend = 1.0f;
            } else if (firstTurnBlend < 0.0f) {
                firstTurnBlend = 0.0f;
            }
            mdlSetBlendWeight(model, firstTurnBlend);
            rec->phase += 1.0f;
        }
        goto common;
    }
    if (state == 2) {
        firstTrackScale = 2.0f * ((Model *)model)->unk144;
        firstBlendLimit = D_00761260;
        if (!(firstTrackScale < firstBlendLimit)) {
            firstTrackScale = firstBlendLimit;
        }
        firstTrackBlend = firstTrackScale * speed;
        if (!(firstTrackBlend <= 1.0f)) {
            firstTrackBlend = 1.0f;
        } else if (firstTrackBlend < 0.0f) {
            firstTrackBlend = 0.0f;
        }
        mdlSetBlendWeight(model, firstTrackBlend);
        firstAngleCosine = effMiscQuatAngle(mdlGetLookAtSubobject(mtMiscResourceValue(rec->id)), rec->lookAtSnapshot);
        if ((firstAngleCosine < -1.0f) || !(firstAngleCosine <= 1.0f)) {
            kAssertFail(&D_0063C948, 0x176);
        }
        if (func_0044b920(dptofp(func_0044b310(fptodp(firstAngleCosine)))) < fGpffff8478) {
            rec->angleStableFrames = rec->angleStableFrames + 1;
            if (rec->angleStableFrames >= 2) {
                rec->angleStableFrames = 0;
                secondSettled = 1;
            } else {
                goto block_42;
            }
        } else {
            rec->angleStableFrames = 0;
block_42:
            secondSettled = 0;
        }
        if (secondSettled != 0) {
            mdlSetTrackScaleRange(model, 0.0f, 17.5f);
            secondTurnBlend = fGpffff8504 * speed;
            if (!(secondTurnBlend <= 1.0f)) {
                secondTurnBlend = 1.0f;
            } else if (secondTurnBlend < 0.0f) {
                secondTurnBlend = 0.0f;
            }
            mdlSetBlendWeight(model, secondTurnBlend);
            rec->phase += 1.0f;
        }
        goto common;
    }
    if (state == 3) {
        secondTrackScale = 2.0f * ((Model *)model)->unk144;
        secondBlendLimit = D_00761260;
        if (!(secondTrackScale < secondBlendLimit)) {
            secondTrackScale = secondBlendLimit;
        }
        secondTrackBlend = secondTrackScale * speed;
        if (!(secondTrackBlend <= 1.0f)) {
            secondTrackBlend = 1.0f;
        } else if (secondTrackBlend < 0.0f) {
            secondTrackBlend = 0.0f;
        }
        mdlSetBlendWeight(model, secondTrackBlend);
        secondAngleCosine = effMiscQuatAngle(mdlGetLookAtSubobject(mtMiscResourceValue(rec->id)), rec->lookAtSnapshot);
        if ((secondAngleCosine < -1.0f) || !(secondAngleCosine <= 1.0f)) {
            kAssertFail(&D_0063C948, 0x176);
        }
        if (func_0044b920(dptofp(func_0044b310(fptodp(secondAngleCosine)))) < fGpffff8478) {
            rec->angleStableFrames = rec->angleStableFrames + 1;
            if (rec->angleStableFrames >= 2) {
                rec->angleStableFrames = 0;
                thirdSettled = 1;
            } else {
                goto block_63;
            }
        } else {
            rec->angleStableFrames = 0;
block_63:
            thirdSettled = 0;
        }
        if (thirdSettled != 0) {
            mdlSetTrackScaleRange(model, 0.0f, -15.0f);
            thirdTurnBlend = fGpffff8504 * speed;
            if (!(thirdTurnBlend <= 1.0f)) {
                thirdTurnBlend = 1.0f;
            } else if (thirdTurnBlend < 0.0f) {
                thirdTurnBlend = 0.0f;
            }
            mdlSetBlendWeight(model, thirdTurnBlend);
            rec->phase += 1.0f;
        }
        goto common;
    }
    if (state == 4) {
        thirdTrackScale = 2.0f * ((Model *)model)->unk144;
        if (!(thirdTrackScale < 0.5f)) {
            thirdTrackScale = 0.5f;
        }
        thirdTrackBlend = thirdTrackScale * speed;
        if (!(thirdTrackBlend <= 1.0f)) {
            thirdTrackBlend = 1.0f;
        } else if (thirdTrackBlend < 0.0f) {
            thirdTrackBlend = 0.0f;
        }
        mdlSetBlendWeight(model, thirdTrackBlend);
        thirdAngleCosine = effMiscQuatAngle(mdlGetLookAtSubobject(mtMiscResourceValue(rec->id)), rec->lookAtSnapshot);
        if ((thirdAngleCosine < -1.0f) || !(thirdAngleCosine <= 1.0f)) {
            kAssertFail(&D_0063C948, 0x176);
        }
        if (func_0044b920(dptofp(func_0044b310(fptodp(thirdAngleCosine)))) < fGpffff8478) {
            rec->angleStableFrames = rec->angleStableFrames + 1;
            if (rec->angleStableFrames >= 2) {
                rec->angleStableFrames = 0;
                fourthSettled = 1;
            } else {
                goto block_84;
            }
        } else {
            rec->angleStableFrames = 0;
block_84:
            fourthSettled = 0;
        }
        if (fourthSettled != 0) {
            mdlSetTrackScaleRange(model, 0.0f, 10.0f);
            fourthTurnBlend = fGpffff8504 * speed;
            if (!(fourthTurnBlend <= 1.0f)) {
                fourthTurnBlend = 1.0f;
            } else if (fourthTurnBlend < 0.0f) {
                fourthTurnBlend = 0.0f;
            }
            mdlSetBlendWeight(model, fourthTurnBlend);
            rec->phase += 1.0f;
        }
        goto common;
    }
    if (state == 5) {
        fourthTrackScale = 2.0f * ((Model *)model)->unk144;
        fourthBlendLimit = fGpffff8510;
        if (!(fourthTrackScale < fourthBlendLimit)) {
            fourthTrackScale = fourthBlendLimit;
        }
        fourthTrackBlend = fourthTrackScale * speed;
        if (!(fourthTrackBlend <= 1.0f)) {
            fourthTrackBlend = 1.0f;
        } else if (fourthTrackBlend < 0.0f) {
            fourthTrackBlend = 0.0f;
        }
        mdlSetBlendWeight(model, fourthTrackBlend);
        fourthAngleCosine = effMiscQuatAngle(mdlGetLookAtSubobject(mtMiscResourceValue(rec->id)), rec->lookAtSnapshot);
        if ((fourthAngleCosine < -1.0f) || !(fourthAngleCosine <= 1.0f)) {
            kAssertFail(&D_0063C948, 0x176);
        }
        if (func_0044b920(dptofp(func_0044b310(fptodp(fourthAngleCosine)))) < fGpffff8478) {
            rec->angleStableFrames = rec->angleStableFrames + 1;
            if (rec->angleStableFrames >= 2) {
                rec->angleStableFrames = 0;
                fifthSettled = 1;
            } else {
                goto block_105;
            }
        } else {
            rec->angleStableFrames = 0;
block_105:
            fifthSettled = 0;
        }
        if (fifthSettled != 0) {
            mdlSetTrackScaleRange(model, 0.0f, 0.0f);
            finalBlendWeight = fGpffff8218 * speed;
            if (!(finalBlendWeight <= 1.0f)) {
                finalBlendWeight = 1.0f;
            } else if (finalBlendWeight < 0.0f) {
                finalBlendWeight = 0.0f;
            }
            mdlSetBlendWeight(model, finalBlendWeight);
            rec->phase += 1.0f;
        }
        goto common;
    }
    if (state == 6) {
        finalAngleCosine = effMiscQuatAngle(mdlGetLookAtSubobject(mtMiscResourceValue(rec->id)), rec->lookAtSnapshot);
        if ((finalAngleCosine < -1.0f) || !(finalAngleCosine <= 1.0f)) {
            kAssertFail(&D_0063C948, 0x176);
        }
        if (func_0044b920(dptofp(func_0044b310(fptodp(finalAngleCosine)))) < fGpffff8514) {
            rec->finalStableFrames = rec->finalStableFrames + 1;
            if (rec->finalStableFrames >= 2) {
                rec->angleStableFrames = 0;
                finalSettled = 1;
            } else {
                goto block_120;
            }
        } else {
            rec->finalStableFrames = 0;
block_120:
            finalSettled = 0;
        }
        if (finalSettled != 0) {
            flags = rec->flags;
            if (flags & 1) {
                rec->flags = flags & ~1;
                mdlSetLookAtRequested(model);
            }
            return 1;
        }
        goto common;
    }
common:
        *(F32x4 *)rec->lookAtSnapshot = *(F32x4 *)mdlGetLookAtSubobject(model);
        return 0;
}

// Points model id's look-at direction at model id2 while blending, then waits for model id's motion
// to finish.
// FUN_00292BB0
s32 evtModelStepAimAtModel(s32 unusedContext, u8 *recordBytes) {
    EvtModelRec *rec = (EvtModelRec *)recordBytes;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } F32x3;
    typedef struct {
        u8 pad00[0x30];
        F32x3 position;
    } EvtAimMatrix;
    struct {
        F32x3 target;
        u32 pad0C;
        F32x3 initialTarget;
        u32 pad1C;
        F32x3 direction;
        u32 pad2C;
    } aimScratch;
    f32 speed;
    f32 deltaX;
    f32 initialBlendWeight;
    f32 blendWeight;
    s32 handle1;
    s32 handle2;
    s32 equalComponents;
    u32 state;
    EvtAimMatrix *initialSourceMatrix;
    EvtAimMatrix *initialTargetMatrix;
    EvtAimMatrix *sourceMatrix;
    EvtAimMatrix *targetMatrix;
    u8 *lookAt;

    speed = rec->speed;
    handle1 = mtMiscResourceValue(rec->id);
    handle2 = mtMiscResourceValue(rec->targetId);
    if (handle1 == 0) {
        return 1;
    }
    if (handle2 == 0) {
        return 1;
    }
    state = (u32)rec->phase;
    if (state == 0) {
        initialSourceMatrix = (EvtAimMatrix *)mdlGetMatrix(handle1);
        aimScratch.direction = initialSourceMatrix->position;
        initialTargetMatrix = (EvtAimMatrix *)mdlGetMatrix(handle2);
        aimScratch.initialTarget = initialTargetMatrix->position;
        deltaX = aimScratch.initialTarget.x - aimScratch.direction.x;
        aimScratch.direction.x = deltaX;
        aimScratch.direction.z = aimScratch.initialTarget.z - aimScratch.direction.z;
        *(u32 *)&aimScratch.direction.y = 0;
        if (deltaX == aimScratch.direction.z) {
            equalComponents = 1;
        } else {
            equalComponents = 0;
        }
        if ((f32)equalComponents == 0.0f) {
            aimScratch.direction.z = 1.0f;
        }
        RwV3dNormalize(&aimScratch.direction, &aimScratch.direction);
        mdlSetLookAtDirection(handle1, &aimScratch.direction);
        initialBlendWeight = fGpffff8218 * speed;
        if (!(initialBlendWeight <= 1.0f)) {
            initialBlendWeight = 1.0f;
        } else if (initialBlendWeight < 0.0f) {
            initialBlendWeight = 0.0f;
        }
        mdlSetBlendWeight(handle1, initialBlendWeight);
        rec->phase += 1.0f;
    } else {
        if (mdlHasActiveMode(handle1) == 0) {
            return 1;
        }
        sourceMatrix = (EvtAimMatrix *)mdlGetMatrix(handle1);
        aimScratch.direction = sourceMatrix->position;
        targetMatrix = (EvtAimMatrix *)mdlGetMatrix(handle2);
        aimScratch.target = targetMatrix->position;
        aimScratch.direction.x = aimScratch.target.x - aimScratch.direction.x;
        aimScratch.direction.z = aimScratch.target.z - aimScratch.direction.z;
        *(u32 *)&aimScratch.direction.y = 0;
        RwV3dNormalize(&aimScratch.direction, &aimScratch.direction);
        mdlSetLookAtDirection(handle1, &aimScratch.direction);
        blendWeight = fGpffff8218 * speed;
        if (!(blendWeight <= 1.0f)) {
            blendWeight = 1.0f;
        } else if (blendWeight < 0.0f) {
            blendWeight = 0.0f;
        }
        mdlSetBlendWeight(handle1, blendWeight);
    }
    lookAt = (u8 *)mdlGetLookAtSubobject(handle1);
    *(F32x4 *)rec->lookAtSnapshot = *(F32x4 *)lookAt;
    return 0;
}

// Per-frame step for one queued node's resource. Frame 0 sets the motion, frame 5
// begins the rotation (with a sound range when flag 0x2 is set), frame 25 ends
// it. Returns 1 once the resource is gone or the motion has ended, else 0.
// FUN_00292EF0
#pragma push
/* measured: retail does not propagate copies here; the phase is cast unsigned to avoid a rebuilt
 * toggle. */
#pragma opt_propagation off
s32 evtModelStepMotion(s32 unusedContext, u8 *recordBytes) {
    EvtModelRec *rec = (EvtModelRec *)recordBytes;
    SVec3 angles;
    u32 id;
    s32 handle;
    s32 frame;

    id = rec->id;
    handle = mtMiscResourceValue(id);
    if (handle == 0) {
        return 1;
    }
    frame = (u32)rec->phase;
    if (frame == 0) {
        MT_Scene_SetResMotion(MT_Scene_GetRes(id), 0, 1, 5, 0, 0, 1.0f);
    } else if (frame == 5) {
        angles.x = 0.0f;
        angles.y = rec->yaw;
        angles.z = 0.0f;
        MT_Scene_BeginResRotation(id, &angles, *(u32 *)&rec->duration, 0);
        if (rec->flags & 2) {
            u8 sound = (rec->sound + 1) & 0xFF;
            s16 start = rec->soundStart;
            s16 end = rec->soundEnd;
            s16 flags = rec->soundFlags;
            MT_Scene_SetResSoundRange(id, 2, sound, start, end, flags);
        }
    } else if (frame == 25) {
        MT_Scene_SetResMotion(MT_Scene_GetRes(id), 0, 0, 5, 1, 0, 1.0f);
        return 1;
    }
    rec->phase += 1.0f;
    *(F32x4 *)rec->lookAtSnapshot = *(F32x4 *)mdlGetLookAtSubobject(handle);
    return 0;
}
#pragma pop

// Task update: runs each queued node's callback (stored at +0x2C of its entry);
// a node whose callback returns nonzero is removed. Returns -1 when the queue
// count at +0x10 is zero, else 0.
// FUN_002930E0
s32 evtModelUpdateTask(u8 *unusedTask) {
    u8 **list;
    u8 *head;
    u8 *node;
    u8 *next;
    u8 *entry;
    s32 (*cb)(u8 **, u8 *);

    list = (u8 **)kwlnTaskGetWork();
    head = (u8 *)*list;
    node = (u8 *)((EvtModelQueue *)head)->head;
    while (node != NULL) {
        next = (u8 *)((EvtModelQueueNode *)node)->next;
        entry = (u8 *)((EvtModelQueueNode *)node)->entry;
        cb = ((EvtModelRec *)entry)->step;
        if ((cb != NULL) && (cb(list, entry) != 0)) {
            comuDataRemoveAndReleaseNode(head, head + 4, node);
        }
        node = next;
    }
    if (((EvtModelQueue *)head)->count != 0) {
        goto ret0;
    }
    return -1;
ret0:
    return 0;
}

// Task destroy: resets each queued node's resource (blend weight and look-at
// request) and frees the queue.
// FUN_002931A0
void evtModelTaskDestroy(u8 *unusedTask) {
    u8 **list;
    u8 *head;
    u8 *node;
    u8 *next;
    s32 handle;

    list = (u8 **)kwlnTaskGetWork();
    head = (u8 *)*list;
    if (head != NULL) {
        node = (u8 *)((EvtModelQueue *)head)->head;
        while (node != NULL) {
            next = (u8 *)((EvtModelQueueNode *)node)->next;
            handle = mtMiscResourceValue(((EvtModelQueueNode *)node)->entry->id);
            if (handle != 0) {
                mdlSetBlendWeight(handle, fGpffff8218);
                mdlSetLookAtRequested(handle);
            }
            comuDataRemoveAndReleaseNode(head, head + 4, node);
            node = next;
        }
    }
    nmListDestroyManager(*list);
}

// Destroys the event-model manager task by name, with its child tasks.
// FUN_00293270
void evtModelDestroy(void) {
    s32 handle = kwlnTaskGetTaskByName(D_0063C958);

    if (handle != 0) {
        kwlnTaskDestroyWithHierarchy(handle);
    }
}

// Resets the blend weight and look-at request on resourceId and removes its
// nodes from the queue.
// FUN_002932B0
void evtModelFlushResource(s32 resourceId) {
    u8 **list;
    u8 *head;
    u8 *node;
    u8 *next;
    s32 handle;
    u32 outer;
    u32 masked;

    outer = kwlnTaskGetTaskByName(D_0063C958);
    if (outer != 0) {
        list = (u8 **)kwlnTaskGetWork(outer);
        head = (u8 *)*list;
        if (head != NULL) {
            node = (u8 *)((EvtModelQueue *)head)->head;
            masked = (u16)resourceId;
            while (node != NULL) {
                next = (u8 *)((EvtModelQueueNode *)node)->next;
                if (((EvtModelQueueNode *)node)->entry->id == masked) {
                    handle = mtMiscResourceValue(((EvtModelQueueNode *)node)->entry->id);
                    if (handle != 0) {
                        mdlSetBlendWeight(handle, fGpffff8218);
                        mdlSetLookAtRequested(handle);
                    }
                    comuDataRemoveAndReleaseNode(head, head + 4, node);
                }
                node = next;
            }
        }
    }
}

// Queues motion `motion` at `speed` for resource resourceId. Creates the manager task
// on first use.
// FUN_002933A0
void evtModelQueueMotion(u16 resourceId, s32 motion, f32 speed) {
    EvtModelParameters parameters;
    u32 task;
    u8 **newWork;
    u8 **work;
    u8 *newQueue;
    u8 *existingQueue;
    u8 *nextNode;
    u8 *entry;
    u8 *queue;
    u8 *queuedEntry;
    u8 *node;
    u32 masked;

    task = kwlnTaskGetTaskByName(D_0063C958);
    if (task == 0) {
        newQueue = (u8 *)nmListAllocManager(4, 0, 0, 0);
        newWork = ((EvtModelQueue *)newQueue)->work;
        *newWork = newQueue;
        task = (s32)kwlnTaskCreate((const void *)(D_0063C958), 0xF, 0, 0, evtModelUpdateTask, evtModelTaskDestroy, (u8 *)(newWork));
    }
    work = (u8 **)kwlnTaskGetWork(task);
    memset(&parameters, 0, 0x2C);
    parameters.resourceId = resourceId;
    parameters.motion = motion;
    parameters.speed = speed;
    if (work == NULL) {
        kAssertFail(D_0063C948, 0x32C);
    }
    existingQueue = (u8 *)*work;
    if (existingQueue != NULL) {
        node = (u8 *)((EvtModelQueue *)existingQueue)->head;
        masked = (u16)resourceId;
        while (node != NULL) {
            nextNode = (u8 *)((EvtModelQueueNode *)node)->next;
            entry = (u8 *)((EvtModelQueueNode *)node)->entry;
            if ((((EvtModelRec *)entry)->id == masked) && (((EvtModelRec *)entry)->motion == 3)) {
                comuDataRemoveAndReleaseNode(existingQueue, existingQueue + 4, node);
            }
            node = nextNode;
        }
    }
    queue = (u8 *)*work;
    queuedEntry = (u8 *)((EvtModelQueueNode *)nmListAppendNode(queue, ((EvtModelQueue *)queue)->count + 1, 0x4C))->entry;
    memcpy(queuedEntry, &parameters, 0x2C);
    ((EvtModelRec *)queuedEntry)->step = (s32 (*)(u8 **, u8 *))D_0063C930[parameters.motion];
}

// Queues motion like evtModelQueueMotion, but first removes this resource's
// motion-3 nodes and stores `duration` with the node. Creates the manager task
// on first use.
// FUN_00293550
void evtModelQueueTimedMotion(u16 resourceId, u16 duration, s32 motion, f32 speed) {
    EvtModelParameters parameters;
    u32 task;
    u8 **newWork;
    u8 **work;
    u8 *newQueue;
    u8 *existingQueue;
    u8 *nextNode;
    u8 *entry;
    u8 *queue;
    u8 *queuedEntry;
    u8 *node;
    u32 masked;

    task = kwlnTaskGetTaskByName(D_0063C958);
    if (task == 0) {
        newQueue = (u8 *)nmListAllocManager(4, 0, 0, 0);
        newWork = ((EvtModelQueue *)newQueue)->work;
        *newWork = newQueue;
        task = (s32)kwlnTaskCreate((const void *)(D_0063C958), 0xF, 0, 0, evtModelUpdateTask, evtModelTaskDestroy, (u8 *)(newWork));
    }
    work = (u8 **)kwlnTaskGetWork(task);
    memset(&parameters, 0, 0x2C);
    parameters.resourceId = resourceId;
    parameters.duration = duration;
    parameters.motion = motion;
    parameters.speed = speed;
    if (work == NULL) {
        kAssertFail(D_0063C948, 0x32C);
    }
    existingQueue = (u8 *)*work;
    if (existingQueue != NULL) {
        node = (u8 *)((EvtModelQueue *)existingQueue)->head;
        masked = (u16)resourceId;
        while (node != NULL) {
            nextNode = (u8 *)((EvtModelQueueNode *)node)->next;
            entry = (u8 *)((EvtModelQueueNode *)node)->entry;
            if ((((EvtModelRec *)entry)->id == masked) && (((EvtModelRec *)entry)->motion == 3)) {
                comuDataRemoveAndReleaseNode(existingQueue, existingQueue + 4, node);
            }
            node = nextNode;
        }
    }
    queue = (u8 *)*work;
    queuedEntry = (u8 *)((EvtModelQueueNode *)nmListAppendNode(queue, ((EvtModelQueue *)queue)->count + 1, 0x4C))->entry;
    memcpy(queuedEntry, &parameters, 0x2C);
    ((EvtModelRec *)queuedEntry)->step = (s32 (*)(u8 **, u8 *))D_0063C930[parameters.motion];
}
