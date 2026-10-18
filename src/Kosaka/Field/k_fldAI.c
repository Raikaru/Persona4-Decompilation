#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdktask.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "field_frame_internal.h"
extern u8 D_00756510[];
extern s32 FldCharacterAnimSelect();
extern void func_003e0f40();
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1B18[];
extern u8 D_005F1B28[];
extern u8 D_005F1CF0[];
extern f32 iGpffffba6c;
extern void chkmemAllocSiteTag(const void *file, s32 line);

extern s32 kwlnGetCamera(void);
extern s32 FldAI_ChaserUpdate(u8 *);
extern s32 FldAI_PatrolUpdate(u8 *);
extern u8 *D_007EFA00[];
extern s32 iGpffffb25c;
extern u8 *iGpffffb2c8;
extern s32 K_FldEvent_IsPosWithinFov(u8 *, u8 *, f32 );
extern s32 K_FldEvent_ArePosWithinDist(u8 *, u8 *, f32 );
extern s32 FldFrame_RaycastField(const RwV3d *line, RwV3d *hitPointDst);
extern f32 RwV3dLength(f32 *);
extern u8 *mdlGetMatrix(u8 *);

typedef RwV3d FldAIVec3;
typedef struct { f32 x, y, z, w; } FldAIVec4;
typedef struct {
    FldAIVec3 right; u32 flags;
    FldAIVec3 up; u32 pad1c;
    FldAIVec3 forward; u32 pad2c;
    FldAIVec3 pos; u32 pad3c;
} FldAIMatrix;
typedef struct {
    u8 unk00[0x40];
    u32 flags;
    u32 unk44;
    s32 used;
    u32 unk4c;
    u8 *model;
    u8 *movement;
    u8 unk58[0x144];
    FldAIVec3 origin;
    u8 unk1a8[0x20];
    u16 configIndex;
    u8 kind;
    u8 heightSlot;
} FldAINpc;

extern u8 D_005F1B40[];
extern u8 D_005F1B4C[];

extern s32 *MT_Scene_GetFrameState(void);

/* Field follower update. Readiness is a byte predicate; model-slot and
 * history addresses keep their storage boundaries. Position providers write
 * complete XYZ objects, and each model query keeps its native pointer ABI.
 */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
typedef union FldFollowerPositionOutput {
    RwV3d value;
    u8 bytes[sizeof(RwV3d)];
} FldFollowerPositionOutput;

static inline u8 *fldFollowerStorageOffset(u32 offset, u8 *entry)
{
    return (u8 *)(offset + (uintptr_t)entry);
}

static inline u8 **fldFollowerModelSlot(u8 *entry)
{
    return (u8 **)(entry + 0x50);
}

/* Raw follower-work fields retained: the typed 0x74-byte layout produced 5392/5248 bytes and lost MATCH; actor/matrix field rewrites below still match. */
// FUN_0017D3C0
s32 FldAI_ChaserUpdate(u8 *task)
{
    struct RwFrame;
    struct RwMatrix;
    extern u8 D_007EF9B0[];
    extern u32 iGpffff9f58;
    extern f32 iGpffff84e0;
    extern f32 iGpffff830c;
    extern f32 iGpffff82fc;
    extern u8 D_00756510[];
    extern void *func_003e0f80(void);
    extern struct RwMatrix *func_003e9700(struct RwFrame *);
    extern f32 RwV3dNormalize(RwV3d *, const RwV3d *);
    extern f32 FldEvent_GetVisibleDistance(const struct RwMatrix *, const RwV3d *, f32, f32, f32);
    extern f32 FldEvent_GetMoveStep(void);
    extern f32 func_0044b920(f32);
    extern s32 KMisc_CreateRmdFade(s32, s32, s32, s32, s32);
    extern s32 KDraw_IsEffectDone(u8 *);
    extern s32 FldFrameTask_GetTileX(u8 *);
    extern s32 FldFrameTask_GetTileZ(u8 *);
    extern void FldFrameTask_ClearFlags(u8 *, s32);
    extern void FldFrameTask_GetPosition(u8 *, u8 *);
    extern void FldFrameTask_SetPosition(u8 *, u8 *);
    extern void FldFrameTask_StartMove(u8 *, f32);
    extern void FldFrameTask_Rotate(u8 *, const void *, f32);
    extern s32 FldCharacterAnimSelect(s32);
    extern s32 FldMoveAnimSecondary(s32);
    extern s32 FldAI_ChaserGetState(u8 *);
    extern u32 RpRandom(void);
    extern void *memset(void *, int, size_t);
    extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *);
    extern void kAssertFail(const void *, s32);
    extern s16 mdlGetLayerAnimation(s32, s32);
    extern void mdlSetColor(void *, const void *);
    extern void mdlSetAlphaBlend(void *);
    extern void mdlClearAlphaBlend(void *);

    u8 *work;
    u8 *entry;
    u8 *matrix;
    s32 index;
    s32 active;
    s32 tileX;
    s32 tileZ;
    s32 historyIndex;
    s32 action;
    s32 currentAnimation;
    s32 desiredAnimation;
    f32 distance;
    f32 speed;
    f32 turn;
    f32 limit;
    f32 ratio;
    f32 dot;
    f32 turnAmount;
    RwV3d selfForward;
    RwV3d selfRight;
    RwV3d separation;
    RwV3d leaderDelta;
    RwV3d offset;
    RwV3d leaderRight;
    RwV3d focusPosition;
    RwV3d cameraDelta;
    RwV3d cameraPosition;
    RwV3d historyDelta;
    FldFollowerPositionOutput historyPoint;
    FldFollowerPositionOutput selfPosition;

    work = ((SdkTask *)task)->work;
    speed = 0.0f;
    turn = 0.0f;
    if (*(s32 *)(work + 4) == 1)
        return 0;
    {
        s32 firstUsed;
        s32 secondUsed;
        u8 firstReady;
        u8 secondReady;
        firstUsed = 0;
        entry = *(u8 **)(work + 0x10);
        if (*(s32 *)(entry + 0x48) == 0)
            goto firstAvailabilityDone;
        if (*(void **)(entry + 0x54) == NULL)
            goto firstAvailabilityDone;
        firstUsed = 1;
firstAvailabilityDone:
        firstReady = firstUsed != 0;
        if (firstReady == 0)
            goto unavailable;
        secondUsed = 0;
        entry = *(u8 **)(work + 0x14);
        if (*(s32 *)(entry + 0x48) == 0)
            goto secondAvailabilityDone;
        if (*(void **)(entry + 0x54) == NULL)
            goto secondAvailabilityDone;
        secondUsed = 1;
secondAvailabilityDone:
        secondReady = secondUsed != 0;
        if (secondReady != 0)
            goto available;
unavailable:
        return 0;
available:
        ;
    }

    switch (*(s32 *)work) {
    case 0: {
        s32 discoveryIndex;
        s32 discoveryAvailable;
        u8 discoveryReady;
        u8 *discoveryEntry;
        *(void **)(work + 0x50) = func_003e0f80();
        for (discoveryIndex = 0; discoveryIndex < 4; discoveryIndex++) {
            discoveryAvailable = 0;
            discoveryEntry = D_007EF9B0 + discoveryIndex * 0x750;
            if (*(s32 *)(discoveryEntry + 0x48) == 0)
                goto discoveryAvailabilityDone;
            if (*(void **)(discoveryEntry + 0x54) == NULL)
                goto discoveryAvailabilityDone;
            discoveryAvailable = 1;
discoveryAvailabilityDone:
            discoveryReady = discoveryAvailable != 0;
            if (discoveryReady && *(u8 **)(work + 0x10) == discoveryEntry)
                break;
        }
        if (discoveryIndex >= 4)
            kAssertFail(D_005F1B18, 0x97);
        *(s32 *)(work + 0x20) = discoveryIndex;
        *(f32 *)(work + 0x24) = 2800.0f;
        *(f32 *)(work + 0x28) = 360.0f;
        *(s32 *)(work + 0x58) = 0;
        *(s32 *)(work + 0x5C) = 0;
        *(s32 *)(work + 0x4C) = -1;
        *(s32 *)work += 1;
        break;

    }
    case 1:
        tileX = FldFrameTask_GetTileX(*(u8 **)(D_007EFA00[1] + 0x220));
        tileZ = FldFrameTask_GetTileZ(*(u8 **)(D_007EFA00[1] + 0x220));
        {
            struct RwFrame *frame = *(struct RwFrame **)((u8 *)(u32)kwlnGetCamera() + 4);
            FldFrameTask_GetPosition(selfPosition.bytes,
                *(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220));
            focusPosition = *(RwV3d *)selfPosition.bytes;
            focusPosition.y += 180.0f;
            matrix = (u8 *)func_003e9700(frame);
            cameraPosition = ((FldAIMatrix *)matrix)->pos;
        }
        cameraDelta.x = focusPosition.x - cameraPosition.x;
        cameraDelta.y = focusPosition.y - cameraPosition.y;
        cameraDelta.z = focusPosition.z - cameraPosition.z;
        distance = RwV3dLength(&cameraDelta.x);
        if (*(u8 **)(work + 0x6C) != NULL && KDraw_IsEffectDone(*(u8 **)(work + 0x6C)) == 1) {
            mdlClearAlphaBlend(*(void **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164));
            kwlnTaskDestroyWithHierarchy(*(KwlnTask **)(work + 0x6C));
            *(u8 **)(work + 0x6C) = NULL;
        }
        if (distance <= 110.0f + *(f32 *)(work + 0x64)) {
            if (*(u8 **)(work + 0x6C) != NULL) {
                mdlClearAlphaBlend(*(void **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164));
                kwlnTaskDestroyWithHierarchy(*(KwlnTask **)(work + 0x6C));
                *(u8 **)(work + 0x6C) = NULL;
            }
            mdlSetColor(*(void **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164), &iGpffff9f58);
            *(s32 *)(work + 0x68) = 1;
        }
        if (*(s32 *)(work + 0x68) == 1 && !(distance <= 110.0f + *(f32 *)(work + 0x64))) {
            mdlSetAlphaBlend(*(void **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164));
            *(s32 *)(work + 0x6C) = KMisc_CreateRmdFade((s32)task,
                *(s32 *)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164), 0, 255, 10);
            *(s32 *)(work + 0x68) = 0;
        }
        if (!(FldEvent_GetMoveStep() <= 0.0f))
            *(s32 *)(work + 0xC) = 1;
        if (*(s32 *)(work + 0xC) == 0) {
            currentAnimation = (s16)mdlGetLayerAnimation(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
            desiredAnimation = FldCharacterAnimSelect(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
            if (currentAnimation != desiredAnimation) {
                desiredAnimation = (s16)FldCharacterAnimSelect(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                mdlDispatchAnimIfPresent(((FldAINpc *)*(u8 **)(work + 0x10))->model, 0, (s16)desiredAnimation, 0, 1);
            }
            break;
        }
        {
            if (((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 2 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 9 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 10 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 11 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 12 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 13 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 14) {
                *(s32 *)(work + 0x58) = 0;
                *(s32 *)(work + 0x5C) = 0;
                *(s32 *)(work + 0x4C) = -1;
                FldFrameTask_ClearFlags(*(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220), 1);
                *(s32 *)(work + 0x18) = 1;
                if (*(s32 *)(work + 0x1C) != *(s32 *)(work + 0x18)) {
                    u32 random = RpRandom() & 1;
                    u8 *otherTask = *(u8 **)(*(u8 **)(work + 0x14) + 0x1B0);
                    if (otherTask != NULL) {
                        if (random != 0) {
                            action = FldAI_ChaserGetState(otherTask);
                            if (action > 0) *(s32 *)(work + 0x48) = -1;
                            else if (action < 0) *(s32 *)(work + 0x48) = 1;
                            else *(s32 *)(work + 0x48) = 0;
                        } else *(s32 *)(work + 0x48) = 0;
                    } else if (random != 0) *(s32 *)(work + 0x48) = 1;
                    else *(s32 *)(work + 0x48) = -1;
                    *(s32 *)(work + 0x1C) = *(s32 *)(work + 0x18);
                }
            } else {
                *(s32 *)(work + 0x18) = 0;
                if (*(s32 *)(work + 0x1C) != *(s32 *)(work + 0x18)) {
                    u32 random = RpRandom() & 1;
                    u8 *otherTask = *(u8 **)(*(u8 **)(work + 0x14) + 0x1B0);
                    if (otherTask != NULL) {
                        if (random != 0) {
                            action = FldAI_ChaserGetState(otherTask);
                            if (action > 0) *(s32 *)(work + 0x48) = -1;
                            else if (action < 0) *(s32 *)(work + 0x48) = 1;
                            else *(s32 *)(work + 0x48) = 0;
                        } else *(s32 *)(work + 0x48) = 0;
                    } else if (random != 0) *(s32 *)(work + 0x48) = 1;
                    else *(s32 *)(work + 0x48) = -1;
                    *(s32 *)(work + 0x1C) = *(s32 *)(work + 0x18);
                }
            }
        }
        *(s32 *)(work + 0x18) = 0;
        matrix = mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model);
        selfForward = ((FldAIMatrix *)matrix)->forward;
        matrix = mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model);
        selfRight = *(RwV3d *)matrix;
        RwV3dNormalize(&selfForward, &selfForward);
        RwV3dNormalize(&selfRight, &selfRight);
        memset(work + 0x30, 0, 12);
        memset(work + 0x3C, 0, 12);
        *(s32 *)(work + 0x2C) = 0;
        for (index = 0; index < 4; index++) {
            s32 neighborActive;
            u8 neighborReady;
            neighborActive = 0;
            entry = D_007EF9B0 + index * 0x750;
            if (*(s32 *)(entry + 0x48) == 0)
                goto neighborAvailabilityDone;
            if (*(void **)(entry + 0x54) == NULL)
                goto neighborAvailabilityDone;
            neighborActive = 1;
neighborAvailabilityDone:
            neighborReady = neighborActive != 0;
            if (neighborReady && *(u8 **)(work + 0x10) != entry) {
                u8 **otherModel = fldFollowerModelSlot(entry);
                f32 candidate = FldEvent_GetVisibleDistance(
                    (const struct RwMatrix *)mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model),
                    (const RwV3d *)(mdlGetMatrix(*otherModel) + 0x30),
                    *(f32 *)(work + 0x28), *(f32 *)(work + 0x24), 0.0f);
                if (!(candidate < 0.0f) && candidate <= 80.0f) {
                    u8 **nearbyModel = (u8 **)(D_007EF9B0 + (u32)index * 0x750u + 0x50);
                    f32 coordinate;
                    coordinate = *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x30);
                    separation.x = ((FldAIMatrix *)mdlGetMatrix(*nearbyModel))->pos.x - coordinate;
                    coordinate = *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x34);
                    separation.y = ((FldAIMatrix *)mdlGetMatrix(*nearbyModel))->pos.y - coordinate;
                    coordinate = *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x38);
                    separation.z = ((FldAIMatrix *)mdlGetMatrix(*nearbyModel))->pos.z - coordinate;
                    RwV3dNormalize(&separation, &separation);
                    turnAmount = 800.0f / candidate;
                    speed = iGpffff84e0;
                    dot = separation.x * selfRight.x + separation.y * selfRight.y + separation.z * selfRight.z;
                    if (!(dot < 0.0f)) turnAmount *= -1.0f;
                    turn += turnAmount;
                }
                if (*(u8 **)(work + 0x14) == entry && !(candidate < 0.0f)) {
                    u8 **leaderModel = (u8 **)(D_007EF9B0 + (u32)index * 0x750u + 0x50);
                    *(f32 *)(work + 0x30) += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->pos.x;
                    *(f32 *)(work + 0x34) += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->pos.y;
                    *(f32 *)(work + 0x38) += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->pos.z;
                    *(f32 *)(work + 0x3C) += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->forward.x;
                    *(f32 *)(work + 0x40) += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->forward.y;
                    *(f32 *)(work + 0x44) += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->forward.z;
                    *(s32 *)(work + 0x2C) += 1;
                }
            }
        }
        {
            f32 coordinate;
            coordinate = *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x14))->model) + 0x30);
            leaderDelta.x = coordinate - *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x30);
            coordinate = *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x14))->model) + 0x34);
            leaderDelta.y = coordinate - *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x34);
            coordinate = *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x14))->model) + 0x38);
            leaderDelta.z = coordinate - *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x38);
        }
        distance = RwV3dNormalize(&leaderDelta, &leaderDelta);
        if (FldEvent_GetMoveStep() <= 0.0f)
            goto idleDistance;
        limit = 400.0f;
        goto distanceChosen;
idleDistance:
        limit = 150.0f;
distanceChosen:
        if (!(distance <= limit)) {
            ratio = distance / limit;
            if (!(ratio <= 1.0f)) ratio = 1.0f;
            speed += iGpffff830c * ratio;
        }
        if (*(s32 *)(work + 0x2C) > 0) {
            memset(&offset, 0, sizeof(offset));
            if (*(s32 *)(work + 0x18) == 0) {
                matrix = mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x14))->model);
                leaderRight = *(RwV3d *)matrix;
                RwV3dNormalize(&leaderRight, &leaderRight);
                switch (*(s32 *)(work + 0x20)) {
                case 1:
                    if (*(s32 *)(work + 0x48) < 0) {
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = 100.0f * leaderRight.x;
                        offset.y = 100.0f * leaderRight.y;
                        offset.z = 100.0f * leaderRight.z;
                    }
                    break;
                case 2:
                    if (*(s32 *)(work + 0x48) < 0) {
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = 100.0f * leaderRight.x;
                        offset.y = 100.0f * leaderRight.y;
                        offset.z = 100.0f * leaderRight.z;
                    }
                    break;
                case 3:
                    if (*(s32 *)(work + 0x48) < 0) {
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = 100.0f * leaderRight.x;
                        offset.y = 100.0f * leaderRight.y;
                        offset.z = 100.0f * leaderRight.z;
                    }
                    break;
                default:
                    kAssertFail(D_005F1B18, 0x19F);
                    break;
                }
            } else {
                matrix = mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x14))->model);
                leaderRight = *(RwV3d *)matrix;
                RwV3dNormalize(&leaderRight, &leaderRight);
                switch (*(s32 *)(work + 0x20)) {
                case 1:
                    if (*(s32 *)(work + 0x48) < 0) {
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = 50.0f * leaderRight.x;
                        offset.y = 50.0f * leaderRight.y;
                        offset.z = 50.0f * leaderRight.z;
                    }
                    break;
                case 2:
                    if (*(s32 *)(work + 0x48) < 0) {
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = 50.0f * leaderRight.x;
                        offset.y = 50.0f * leaderRight.y;
                        offset.z = 50.0f * leaderRight.z;
                    }
                    break;
                case 3:
                    if (*(s32 *)(work + 0x48) < 0) {
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = 50.0f * leaderRight.x;
                        offset.y = 50.0f * leaderRight.y;
                        offset.z = 50.0f * leaderRight.z;
                    }
                    break;
                default:
                    kAssertFail(D_005F1B18, 0x1B6);
                    break;
                }
            }
            offset.x += *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x30);
            offset.y += *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x34);
            offset.z += *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x38);
            *(f32 *)(work + 0x30) += offset.x;
            *(f32 *)(work + 0x34) += offset.y;
            *(f32 *)(work + 0x38) += offset.z;
            *(f32 *)(work + 0x30) /= (f32)(*(s32 *)(work + 0x2C) + 1);
            *(f32 *)(work + 0x34) /= (f32)(*(s32 *)(work + 0x2C) + 1);
            *(f32 *)(work + 0x38) /= (f32)(*(s32 *)(work + 0x2C) + 1);
            separation.x = *(f32 *)(work + 0x30) - *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x30);
            separation.y = *(f32 *)(work + 0x34) - *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x34);
            separation.z = *(f32 *)(work + 0x38) - *(f32 *)(mdlGetMatrix(((FldAINpc *)*(u8 **)(work + 0x10))->model) + 0x38);
            RwV3dNormalize(&separation, &separation);
            dot = selfForward.x * separation.x + selfForward.y * separation.y + selfForward.z * separation.z;
            if (dot < 1.0f) {
                turnAmount = 20.0f * func_0044b920(dot) / iGpffff82fc;
                if (1.0f - dot < turnAmount / 180.0f) turnAmount = 180.0f * (1.0f - dot);
                ratio = separation.x * selfRight.x + separation.y * selfRight.y + separation.z * selfRight.z;
                if (ratio < 0.0f) turnAmount *= -1.0f;
                turn += turnAmount;
            }
        }
        if (distance <= 2800.0f)
            goto moveFollower;
        if (*(s32 *)(work + 8) != 0)
            goto moveFollower;
            matrix = mdlGetMatrix(*(u8 **)(D_007EFA00[1] + 0x164));
            FldFrameTask_SetPosition(*(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220), matrix + 0x30);
            *(s32 *)(work + 0x4C) = -1;
            *(s32 *)(work + 0x58) = 0;
            *(s32 *)(work + 0x5C) = 0;
        goto movementComplete;
moveFollower:
        {
            active = 0;
            historyIndex = *(s32 *)(*(u8 **)(work + 0x10) + 0x710) - 1;
            if (turn != 0.0f && speed != 0.0f)
                FldFrameTask_Rotate(*(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220), D_00756510, turn);
            if (speed != 0.0f)
                FldFrameTask_StartMove(*(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220), speed);
            if (historyIndex < 0) historyIndex = 63;
            entry = *(u8 **)(work + 0x10);
            if (*(fldFollowerStorageOffset(historyIndex, entry) + 0x1D0) != 0) {
                FldFrameTask_GetPosition(historyPoint.bytes, *(u8 **)(*(u8 **)(entry + 0x54) + 0x220));
                historyDelta = *(RwV3d *)historyPoint.bytes;
                {
                    u8 *historySample = fldFollowerStorageOffset(historyIndex * 8, *(u8 **)(work + 0x10));
                    historyPoint.value.x = *(f32 *)(historySample + 0x210);
                    historyPoint.value.z = *(f32 *)(historySample + 0x214);
                }
                historyDelta.x = historyPoint.value.x - historyDelta.x;
                historyDelta.y = historyPoint.value.y - historyDelta.y;
                historyDelta.z = historyPoint.value.z - historyDelta.z;
                if (RwV3dLength(&historyDelta.x) < speed) active = 1;
            }
            if (speed == 0.0f || active == 1) {
                if (*(s32 *)(work + 0x60) < 30) *(s32 *)(work + 0x60) += 1;
                else {
                    currentAnimation = (s16)mdlGetLayerAnimation(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
                    desiredAnimation = FldCharacterAnimSelect(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                    if (currentAnimation != desiredAnimation) {
                        desiredAnimation = (s16)FldCharacterAnimSelect(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                        mdlDispatchAnimIfPresent(((FldAINpc *)*(u8 **)(work + 0x10))->model, 0, (s16)desiredAnimation, 16, 1);
                    }
                    *(s32 *)(work + 0x60) = 0;
                }
            } else {
                currentAnimation = (s16)mdlGetLayerAnimation(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
                desiredAnimation = FldMoveAnimSecondary(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                if (currentAnimation != desiredAnimation) {
                    desiredAnimation = (s16)FldMoveAnimSecondary(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                    mdlDispatchAnimIfPresent(((FldAINpc *)*(u8 **)(work + 0x10))->model, 0, (s16)desiredAnimation, 8, 1);
                    *(s32 *)(work + 0x60) = 0;
                }
            }
        }
movementComplete:
        if (*(s32 *)(work + 8) == 0) *(s32 *)(work + 8) = 1;
        break;
    case 2:
    default:
        break;
    }
    return 0;
}


#pragma pop
/* Release the follower transform and task-owned work. */
/* Raw task-work read retained: replacing +0x38 with SdkTask::work changes b210 instruction selection. */
// FUN_0017E840
void FldAI_ChaserDestroy(u8 *task) {
    s32 h = *(s32 *)(*(u8 **)(task + 0x38) + 0x50);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(task + 0x38));
}

/* Create a follower controller linking a follower actor to its leader. */
/* Raw fixed-offset access retained: the equivalent typed-field rewrite changed b210 code generation in whole-file verification. */
// FUN_0017E890
s32 FldAI_SpawnChaser(s32 parent, s32 follower, s32 leader)
{
    s32 ret;
    u8 *work;

    chkmemAllocSiteTag(D_005F1B18, 0x3D9);
    work = D_008873F4[0](1, 0x74, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F1B28), 0xF, 0, 0, FldAI_ChaserUpdate, FldAI_ChaserDestroy, (u8 *)(work));
    *(s32 *)(work + 0x10) = follower;
    *(s32 *)(work + 0x14) = leader;
    *(s32 *)(work + 0x1C) = -1;
    *(f32 *)(work + 0x64) = *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
    return ret;
}

/* Return the follower's selected lateral formation direction. */
/* The follower work exposes its lateral state at +0x48; the shared getter retains the native work-pointer chain. */
// FUN_0017E980
s32 FldAI_ChaserGetState(u8 *task) {
    return *(s32 *)(((SdkTask *)task)->work + 0x48);
}

/* Enable follower movement processing. */
/* The follower work movement-enable word is +0x0C; the native work-pointer chain is retained. */
// FUN_0017E990
void FldAI_ChaserEnable(u8 *task) {
    *(s32 *)(((SdkTask *)task)->work + 0xC) = 1;
}

/* Restore the idle animation and stop follower movement processing. */
/* Raw fixed-offset access retained: the equivalent typed-field rewrite changed b210 code generation in whole-file verification. */
// FUN_0017E9B0
void FldAI_ChaserDisable(u8 *task) {
    u8 *p = ((SdkTask *)task)->work;

    mdlDispatchAnimIfPresent(*(u8 **)(*(u8 **)(p + 0x10) + 0x50), 0,
                  (s16)FldCharacterAnimSelect(*(u16 *)(*(u8 **)(p + 0x10) + 0x728)), 0, 1);
    *(s32 *)(p + 0xC) = 0;
}

/* Measured near-match archived at object 808B/window 816B, normalized_diff 6.
 * The corrected func_003e4180(f32 *) declaration is required at this callsite.
 * Residual: retail orders ld 0x50(sp), lwc1 0x58(sp), sd 0x70(sp), while
 * MWCCPS2 emits ld, sd, lwc1, swc1 for the stack projection copy.
 * Probed scalar/aggregate copies, assignment reversal, temporary/comma and
 * shared-pointer staging, field-width variants, and volatile stack staging;
 * volatile reached nd0 but is rejected as an ordinary-memory claim. */
/* measured: the ld/lwc1/sd/swc1 projection copy is `out = ab[0]` between
   two FldAIVec3-typed locals (ab is a FldAIVec3[2], slot 0x50; out slot 0x70);
   ab[1] copies (0x5c, unaligned) are the three-lwc1 form. Casting f32 ab[6]
   to FldAIVec3 blinds the alignment and gives three lwc1 (nd290); the
   archive's {s64; f32} out type gives scalar order ld/sd/lwc1/swc1 (nd4). */
/* Test player visibility using configured distance/FOV limits and raycasts in both directions. */
/* Raw fixed-offset access retained: the equivalent typed-field rewrite changed b210 code generation in whole-file verification. */
// FUN_0017EA10
s32 FldAI_ChaserCanSeeTarget(u8 *actor)
{
    FldAIVec3 separation;
    FldAIVec3 hitPoint;
    FldAIVec3 line[2];
    f32 selfCoordinate;
    s32 visible;
    u8 *config;
    u8 *selfMatrix;
    u8 *distanceMatrix;
    u8 *lineSource;
    u8 *lineDestination;

    visible = 0;
    config = iGpffffb2c8 + (*(u8 *)(actor + 0x1CA) * 0x180) +
              (*(u16 *)(actor + 0x1C8) << 6);
    if (iGpffffb25c == 1) {
        return 0;
    }
    if (*(u8 *)(actor + 0x1CB) == 0) {
        distanceMatrix = mdlGetMatrix(*(u8 **)(actor + 0x50));
        if (K_FldEvent_ArePosWithinDist(distanceMatrix + 0x30,
                          mdlGetMatrix(D_007EFA00[0]) + 0x30,
                          *(f32 *)(config + 0x14) / 3.0f) == 1) {
            visible = 1;
        }
        return visible;
    }
    lineSource = mdlGetMatrix(*(u8 **)(actor + 0x50));
    line[0] = *(FldAIVec3 *)(lineSource + 0x30);
    lineDestination = mdlGetMatrix(D_007EFA00[0]);
    line[1] = *(FldAIVec3 *)(lineDestination + 0x30);
    line[0].y += 90.0f;
    line[1].y += 90.0f;
    if (FldFrame_RaycastField(line, &hitPoint) == 1) {
        return 0;
    }
    lineSource = (u8 *)line;
    lineDestination = (u8 *)&hitPoint;
    hitPoint = line[0];
    line[0] = line[1];
    line[1] = hitPoint;
    if (FldFrame_RaycastField((const RwV3d *)lineSource, (RwV3d *)lineDestination) == 1) {
        return 0;
    }
    selfMatrix = mdlGetMatrix(*(u8 **)(actor + 0x50));
    if (K_FldEvent_IsPosWithinFov(selfMatrix, mdlGetMatrix(D_007EFA00[0]) + 0x30,
                      *(f32 *)(config + 0xC)) == 1) {
        selfCoordinate = *(f32 *)(mdlGetMatrix(*(u8 **)(actor + 0x50)) + 0x30);
        separation.x = *(f32 *)(mdlGetMatrix(D_007EFA00[0]) + 0x30) - selfCoordinate;
        selfCoordinate = *(f32 *)(mdlGetMatrix(*(u8 **)(actor + 0x50)) + 0x34);
        separation.y = *(f32 *)(mdlGetMatrix(D_007EFA00[0]) + 0x34) - selfCoordinate;
        selfCoordinate = *(f32 *)(mdlGetMatrix(*(u8 **)(actor + 0x50)) + 0x38);
        separation.z = *(f32 *)(mdlGetMatrix(D_007EFA00[0]) + 0x38) - selfCoordinate;
        if (RwV3dLength((f32 *)&separation) < *(f32 *)(config + 0x10)) {
            return 1;
        }
    }
    selfMatrix = mdlGetMatrix(*(u8 **)(actor + 0x50));
    if (K_FldEvent_ArePosWithinDist(selfMatrix + 0x30,
                      mdlGetMatrix(D_007EFA00[0]) + 0x30,
                      *(f32 *)(config + 0x14)) == 1) {
        return 1;
    }
    return 0;
}

// FUN_0017ED40
/* Advance one of sixteen field-AI bounds samples. The ray query consumes
 * both endpoints, which must remain one contiguous two-vector array.
 * Steps 0-7 gather both bounds; later steps correct the selected x/z bound.
 * Measured b210 -O2: 1868/1872 bytes and seven resolved relocations.
 * Retained propagation preserves the copied vectors and centered coordinates.
 * Load each comparison value separately, and name the bound-array base before
 * each single-bound correction, to preserve the retail address lifetimes. */
#pragma push
#pragma opt_propagation off
/* Bounds are two max/min XYZ pairs at +0x18/+0x30; scaled integer cursors preserve the documented comparison/address lifetimes. */
s32 FldAI_AdvanceBoundsSample(u8 *work)
{
    FldAIVec3 hit;
    FldAIVec3 line[2];
    FldAIVec3 offsets[2];
    FldAIVec4 cell;
    f32 originZ;
    f32 originY;
    f32 originX;
    f32 endpointZ;
    f32 endpointX;
    s32 directionMask;
    s32 tableStep;
    s32 cachedStep;
    s32 axis;
    s32 result;
    s32 direction;
    u8 *unit;
    FldFrameCell *sourceCell;
    u8 *firstOffset;
    u8 *secondOffset;
    s32 cellX;
    s32 cellZ;

    result = 1;
    if (*(s32 *)(work + 0x4C) < 0x10) {
        unit = *(u8 **)(work + 0xC);
        originX = *(f32 *)(unit + 0x19C);
        originY = *(f32 *)(unit + 0x1A0);
        originZ = *(f32 *)(unit + 0x1A4);
        line[0].x = originX;
        line[0].y = originY;
        line[0].z = originZ;
        line[1] = line[0];
        cachedStep = *(s32 *)(work + 0x4C);
        if (cachedStep >= 4) {
            f32 centeredX = 600.0f + line[0].x;
            cellX = (s32)(centeredX / 1200.0f);
            cellZ = (s32)((600.0f + line[0].z) / 1200.0f);
            sourceCell = &((FldFrame *)MT_Scene_GetFrameState())->cells[cellZ][cellX];
            cell = *(FldAIVec4 *)sourceCell;
            cachedStep = *(s32 *)(work + 0x4C);
            direction = cachedStep & 3;
            if ((cachedStep < 0) && (direction != 0)) {
                direction -= 4;
            }
            directionMask = 1 << direction;
            if ((((u8 *)&cell)[10] & directionMask) == 0 || ((((u8 *)&cell)[11] & directionMask) != 0)) {
                goto tail;
            }
        }
        tableStep = (s32)*(u32 *)(work + 0x4C);
        firstOffset = D_005F1B40 + (tableStep * 0x18);
        offsets[0] = *(FldAIVec3 *)firstOffset;
        if ((tableStep >= 4) && (cachedStep < 8)) {
            if (offsets[0].x < 0.0f) {
                offsets[0].x = (1200.0f * (f32)(cellX - 1)) - line[0].x;
            } else if (!(offsets[0].x <= 0.0f)) {
                offsets[0].x = (1200.0f * (f32)(cellX + 1)) - line[0].x;
            }
            if (offsets[0].z < 0.0f) {
                offsets[0].z = (1200.0f * (f32)(cellZ - 1)) - line[0].z;
            } else if (!(offsets[0].z <= 0.0f)) {
                offsets[0].z = (1200.0f * (f32)(cellZ + 1)) - line[0].z;
            }
        }
        endpointX = line[0].x + offsets[0].x;
        line[0].x = endpointX;
        {
            f32 value = line[0].y + offsets[0].y;
            line[0].y = value;
        }
        endpointZ = line[0].z + offsets[0].z;
        line[0].z = endpointZ;
        secondOffset = D_005F1B4C + (*(s32 *)(work + 0x4C) * 0x18);
        offsets[1] = *(FldAIVec3 *)secondOffset;
        {
            f32 value = line[1].x + offsets[1].x;
            line[1].x = value;
        }
        {
            f32 value = line[1].y + offsets[1].y;
            line[1].y = value;
        }
        {
            f32 value = line[1].z + offsets[1].z;
            line[1].z = value;
        }
        {
            f32 centeredX = 600.0f + endpointX;
            s32 endpointCellX = (s32)(centeredX / 1200.0f);
            s32 endpointCellZ = (s32)((600.0f + endpointZ) / 1200.0f);
            FldFrameCell *cellB = &((FldFrame *)MT_Scene_GetFrameState())->cells[endpointCellZ][endpointCellX];
            if (cellB->occupied == 1) {
                axis = 0;
                if (FldFrame_RaycastField(line, &hit) == 1) {
                    s32 hitStep = *(s32 *)(work + 0x4C);
                    if (hitStep >= 4) {
                        axis = hitStep & 1;
                        if ((hitStep < 0) && (axis != 0)) {
                            axis -= 2;
                        }
                    }
                    if (hitStep < 8) {
                        f32 *bounds = (f32 *)work;
                        {
                            f32 value = hit.x;
                            if (bounds[axis * 6 + 6] < value) {
                                bounds[axis * 6 + 6] = value;
                            }
                        }
                        {
                            f32 value = hit.y;
                            if (bounds[axis * 6 + 7] < value) {
                                bounds[axis * 6 + 7] = value;
                            }
                        }
                        {
                            f32 value = hit.z;
                            if (bounds[axis * 6 + 8] < value) {
                                bounds[axis * 6 + 8] = value;
                            }
                        }
                        {
                            f32 value = hit.x;
                            if (!(bounds[axis * 6 + 9] <= value)) {
                                bounds[axis * 6 + 9] = value;
                            }
                        }
                        {
                            f32 value = hit.y;
                            if (!(bounds[axis * 6 + 10] <= value)) {
                                bounds[axis * 6 + 10] = value;
                            }
                        }
                        {
                            f32 value = hit.z;
                            if (!(bounds[axis * 6 + 11] <= value)) {
                                bounds[axis * 6 + 11] = value;
                            }
                        }
                        if (*(s32 *)(work + 0x4C) < 4) {
                            *(FldAIVec3 *)(work + 0x30) = *(FldAIVec3 *)(work + 0x18);
                            *(FldAIVec3 *)(work + 0x3C) = *(FldAIVec3 *)(work + 0x24);
                        }
                    } else if (hitStep < 0xC) {
                        if (axis == 0) {
                            {
                                f32 *bounds = (f32 *)work;
                                f32 value = hit.x;
                                if (bounds[axis * 6 + 9] < value) {
                                    bounds[axis * 6 + 9] = value;
                                }
                            }
                        } else {
                            {
                                f32 *bounds = (f32 *)work;
                                f32 value = hit.z;
                                if (bounds[axis * 6 + 11] < value) {
                                    bounds[axis * 6 + 11] = value;
                                }
                            }
                        }
                    } else if (axis == 0) {
                        {
                            f32 *bounds = (f32 *)work;
                            f32 value = hit.x;
                            if (!(bounds[axis * 6 + 6] <= value)) {
                                bounds[axis * 6 + 6] = value;
                            }
                        }
                    } else {
                        {
                            f32 *bounds = (f32 *)work;
                            f32 value = hit.z;
                            if (!(bounds[axis * 6 + 8] <= value)) {
                                bounds[axis * 6 + 8] = value;
                            }
                        }
                    }
                } else {
                    s32 missStep = *(s32 *)(work + 0x4C);
                    if (missStep >= 4) {
                        axis = missStep & 1;
                        if ((missStep < 0) && (axis != 0)) {
                            axis -= 2;
                        }
                    }
                    if (missStep < 8) {
                        f32 *bounds = (f32 *)work;
                        {
                            f32 value = line[1].x;
                            if (bounds[axis * 6 + 6] < value) {
                                bounds[axis * 6 + 6] = value;
                            }
                        }
                        {
                            f32 value = line[1].y;
                            if (bounds[axis * 6 + 7] < value) {
                                bounds[axis * 6 + 7] = value;
                            }
                        }
                        {
                            f32 value = line[1].z;
                            if (bounds[axis * 6 + 8] < value) {
                                bounds[axis * 6 + 8] = value;
                            }
                        }
                        {
                            f32 value = line[1].x;
                            if (!(bounds[axis * 6 + 9] <= value)) {
                                bounds[axis * 6 + 9] = value;
                            }
                        }
                        {
                            f32 value = line[1].y;
                            if (!(bounds[axis * 6 + 10] <= value)) {
                                bounds[axis * 6 + 10] = value;
                            }
                        }
                        {
                            f32 value = line[1].z;
                            if (!(bounds[axis * 6 + 11] <= value)) {
                                bounds[axis * 6 + 11] = value;
                            }
                        }
                        if (*(s32 *)(work + 0x4C) < 4) {
                            *(FldAIVec3 *)(work + 0x30) = *(FldAIVec3 *)(work + 0x18);
                            *(FldAIVec3 *)(work + 0x3C) = *(FldAIVec3 *)(work + 0x24);
                        }
                    }
                }
            }
        }
tail:
        *(s32 *)(work + 0x4C) = *(s32 *)(work + 0x4C) + 1;
    } else {
        result = 0;
    }
    return result;
}

#pragma pop

/* Field NPC patrol, steering, visibility and player-approach state machine.
 * Match: fnalign 369 -> 0. Preserve phase-specific vector lifetimes and snapshots;
 * propagation/pullout stay off while CSE stays on for retail's shared constants. */
#pragma push
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma opt_pulloutconstants off
typedef struct {
    FldAIVec3 max;
    FldAIVec3 min;
} FldAIPatrolBounds;
static inline f32 fldAIScale(f32 scale, f32 speed)
{
    return scale * speed;
}
static inline f32 fldAIAccumulateTurn(f32 *angle, f32 turn)
{
    f32 total = *angle + turn;
    *angle = total;
    return total;
}
extern u32 RpRandom(void);
extern void mdlSetColor(void *, const void *);
/* SDK vector normalization reads and writes complete three-float objects and
   returns their original length through the floating-point return register. */
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern unsigned char D_005F1CE0[];
extern float fGpffff80f0; /* 0xffff80f0 */
extern float fGpffff811c; /* 0xffff811c */
extern float fGpffff8218; /* 0xffff8218 */
extern float fGpffff825c; /* 0xffff825c */
extern float fGpffff8308; /* 0xffff8308 */
extern float iGpffff830c; /* 0xffff830c */
extern float fGpffff8310; /* 0xffff8310 */
extern int D_00764348; /* 0xffffb258 */
extern int iGpffffb310; /* 0xffffb310 */

struct RwFrame;
struct RwMatrix;
extern void *func_003e0f80(void);
extern struct RwMatrix *func_003e9700(struct RwFrame *);
extern f32 sinf(f32 angle);
extern void *mdlGetColor(void *);
extern int KMisc_CreateRmdFade(int, int, int, int, int);
extern int KDraw_IsEffectDone(unsigned char *);
extern unsigned int FldEvent_HasLineOfSight(void *, void *, float, float);
extern s32 KDraw_CreateAxesTask(void *, void *);
extern void FldRc_SetAxesTargeted(unsigned char *, int);
extern void FldRc_SetAxesColor(unsigned char *, unsigned char *);
extern void FldRc_SetAxesPosition(unsigned char *, unsigned char *);
extern int FldRc_RequestPositionSlot(unsigned char *, float *);
extern int FldStepFileTask(int);
extern void FldFrameTask_SetPosition(unsigned char *, unsigned char *);
extern void FldFrameTask_StartMove(unsigned char *, float);
extern void FldFrameTask_Rotate(u8 *task, const void *axis, f32 angle);
extern float FldEvent_GetMoveStep(void);
extern int kwlnTaskDestroyWithHierarchy(void *);
extern int sdkSndStartStream(short, short, short, short);
extern void mdlSetAlphaBlend(unsigned char *);
extern void mdlClearAlphaBlend(unsigned char *);
extern void mdlEffectSetPackedColor(void *, int *);
extern void mdlEffectGetPackedColor(void *, int *);

extern unsigned char D_00794420[];
extern unsigned char D_005F1CC0[];
/* Raw patrol word/float work accesses retained: typing its state/bounds fields produced 11784/11584 bytes and lost MATCH. */
// FUN_0017F490
int FldAI_PatrolUpdate(unsigned char *task)
{
  typedef struct { unsigned char r, g, b, a; } FldAIColor;
  float distVec[3];
  int *work;
  const FldAIPatrolBounds *patrolBounds;
  int value;
  unsigned char *modelColor;
  int otherValue;
  float *vector;
  unsigned char *effectTask;
  float *matrix;
  void *object;
  unsigned int randomBits;
  int action;
  unsigned char ready;
  int accepted;
  int configAddress;
  unsigned int unsignedValue;
  float distance;
  float factor;
  float distanceRange;
  float turnAmount;
  FldAIVec3 aiPos;
  FldAIVec3 state2Forward;
  FldAIVec3 state2Right;
  FldAIVec3 state2Delta;
  FldAIVec3 patrolPosition;
  float patrolNoticePosition[3];
  float turnNoticePosition[3];
  FldAIVec3 state6Delta;
  FldAIVec3 state6Direction;
  FldAIVec3 approachOrigin;
  FldAIVec3 state7Forward;
  FldAIVec3 state7Right;
  FldAIVec3 state7Delta;
  FldAIVec3 chasePosition;
  FldAIVec3 state8Forward;
  FldAIVec3 state8Right;
  FldAIVec3 state8Delta;
  FldAIVec3 predictionPosition;
  FldAIVec3 aiPos2;
  FldAIVec3 state9Forward;
  FldAIVec3 state9Right;
  FldAIVec3 state9Delta;
  FldAIVec3 state9Direction;
  FldAIVec3 weavePosition;
  FldAIVec3 state10Forward;
  FldAIVec3 state10Right;
  FldAIVec3 state10Delta;
  FldAIVec3 chargePosition;
  FldAIVec3 state11Forward;
  FldAIVec3 state11Right;
  FldAIVec3 state11Delta;
  FldAIVec3 returnPosition;
  FldAIVec3 picked;
  FldAIVec3 pick;
  FldAIVec3 aiPos6;
  FldAIVec3 aiPos8;
  FldAIVec3 aiHere;
  FldAIColor color;
  
  work = *(int **)(task + 0x38);
  if (work[1] == 1) {
    return 0;
  }
  accepted = 0;
  value = work[3];
  if (*(int *)(value + 0x48) == 0)
    goto availabilityDone;
  if (*(void **)(value + 0x54) == NULL)
    goto availabilityDone;
  accepted = 1;
availabilityDone:
  ready = accepted != 0;
  if (ready == 0)
    return 0;
  {
    if ((*(unsigned int *)(value + 0x40) & 1) == 0) {
      return 0;
    }
    value = kwlnGetCamera();
    value = (int)func_003e9700((struct RwFrame *)*(unsigned int *)(value + 4));
    modelColor = (unsigned char *)mdlGetColor((void *)*(unsigned int *)(work[3] + 0x50));
    {
        typedef struct { unsigned char c[4]; } FldAIColorBytes;
        color = *(FldAIColor *)modelColor;
    }
    distance = ((float *)(int *)(u32)work)[0x20];
    distanceRange = ((float *)work)[0x21] - distance;
    if (*(unsigned char *)(work[3] + 0x1ca) == '\0') {
      distance = fGpffff80f0 * distanceRange + distance + 0.0f;
    }
    else {
      distance = fGpffff811c * distanceRange + distance + 0.0f;
    }
    turnAmount = ((float *)work)[0x21] - distance;
    otherValue = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
    distVec[0] = ((FldAIMatrix *)otherValue)->pos.x - ((FldAIMatrix *)value)->pos.x;
    otherValue = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
    distVec[1] = ((FldAIMatrix *)otherValue)->pos.y - ((FldAIMatrix *)value)->pos.y;
    otherValue = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
    distVec[2] = ((FldAIMatrix *)otherValue)->pos.z - ((FldAIMatrix *)value)->pos.z;
    distanceRange = RwV3dLength(&distVec[0]);
    if (!(distanceRange < ((float *)(int *)(u32)work)[0x21])) {
      ((float *)work)[0x1f] = (float)(color.a = 0);
    }
    else if (distanceRange >= distance) {
      if (*(unsigned char *)(work[3] + 0x1ca) == '\0') {
        distance = 1.0f - fGpffff825c * ((distanceRange - distance) / turnAmount);
        factor = (distance < 0.0f) ? 0.0f : distance;
      }
      else {
        factor = 1.0f - (distanceRange - distance) / turnAmount;
      }
      ((float *)work)[0x1f] = (float)(color.a = (unsigned char)(factor * 255.0f));
    }
    else {
      *(float *)((u8 *)(u32)work + 0x7c) = (float)(color.a = 0xff);
    }
    if (*(unsigned char *)(work[3] + 0x1ca) == '\x01') {
      mdlSetColor(*(void **)(work[3] + 0x50),&color);
    }
    for (value = **(int **)(*(int *)(work[3] + 0x50) + 0x2cc); value != 0;
        value = *(int *)(value + 0x10)) {
      if (*(void **)(value + 8) != (void *)0x0) {
        mdlEffectGetPackedColor(*(void **)(value + 8),(int *)&color);
        distance = ((float *)work)[0x1f];
        color.a = (unsigned char)distance;
        mdlEffectSetPackedColor(*(void **)(value + 8),(int *)&color);
      }
    }
    switch(*work) {
    case 0:
      value = (int)func_003e0f80();
      work[4] = value;
      mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,0,1);
      work[5] = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(work[3] + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(work[3] + 0x1c8) * 0x40;
      value = work[3];
      *(FldAIVec3 *)&((float *)work)[9] = *(FldAIVec3 *)(value + 0x19c);
      value = work[3];
      *(FldAIVec3 *)&((float *)work)[6] = *(FldAIVec3 *)(value + 0x19c);
      value = work[3];
      *(FldAIVec3 *)&((float *)work)[0xf] = *(FldAIVec3 *)(value + 0x19c);
      value = work[3];
      *(FldAIVec3 *)&((float *)work)[0xc] = *(FldAIVec3 *)(value + 0x19c);
      value = RpRandom();
      work[0x17] = (int)((unsigned int)value % 3) + 1;
      ((float *)work)[0x1a] = *(float *)(work[5] + 0x18);
      ((float *)work)[0x1b] = *(float *)(work[5] + 0x18);
      effectTask = (unsigned char *)KDraw_CreateAxesTask(task,D_00794420);
      work[0x26] = (int)effectTask;
      FldRc_SetAxesPosition(effectTask,(u8 *)&((FldAINpc *)work[3])->origin);
      FldRc_SetAxesColor((unsigned char *)work[0x26],(unsigned char *)D_005F1CE0);
      FldRc_SetAxesTargeted((unsigned char *)work[0x26],0);
      *work = *work + 1;
      break;
    case 1:
      action = FldAI_AdvanceBoundsSample((u8 *)work);
      if (action == 0) {
        value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
        aiPos = ((FldAIMatrix *)value)->pos;
        if (*(int *)(work[3] + 0x73c) != 0) {
          FldRc_SetAxesTargeted((unsigned char *)work[0x26],1);
          FldRc_SetAxesPosition((unsigned char *)work[0x26],(unsigned char *)(work + 0x14));
          FldRc_SetAxesColor((unsigned char *)work[0x26],(unsigned char *)(D_005F1CE0 + work[0x12] * 4));
        }
        else {
          FldRc_SetAxesTargeted((unsigned char *)work[0x26],0);
        }
        value = (unsigned int)RpRandom() % 100;
        action = 0;
        if (work[2] == 0) {
          if ((unsigned int)value < 5) {
            action = 1;
          }
        }
        else if ((work[2] == 1) && ((unsigned int)value < 0x1e)) {
          action = 1;
        }
        if (action == 1) {
          randomBits = RpRandom();
          if ((randomBits & 1) != 0) {
            work[0x1d] = 0x3f800000;
          }
          else {
            work[0x1d] = -0x40800000;
          }
          value = RpRandom();
          work[0x23] = (int)((unsigned int)value % 0x1e) + 0x1e;
          *work = 3;
        }
        else if (action == 2) {
          work[0x23] = *(int *)(work[5] + 0x2c);
          *(unsigned int *)(work[3] + 0x40) = *(unsigned int *)(work[3] + 0x40) | 2;
          distance = ((float *)work)[0x1f];
          unsignedValue = (unsigned int)distance;
          value = KMisc_CreateRmdFade((int)task,*(int *)(work[3] + 0x50),unsignedValue,0,10);
          work[0x22] = value;
          *work = 4;
        }
        else {
          {
          int cur = work[0x12];
          unsignedValue = cur != 0 ^ 1;
          accepted = 0;
          if ((!(aiPos.x < ((float *)fldFollowerStorageOffset(unsignedValue * 24, (u8 *)work))[9]) &&
               (aiPos.x <= ((float *)fldFollowerStorageOffset(unsignedValue * 24, (u8 *)work))[6])) &&
              (!(aiPos.z < ((float *)fldFollowerStorageOffset(unsignedValue * 24, (u8 *)work))[0xb])) &&
             (aiPos.z <= ((float *)fldFollowerStorageOffset(unsignedValue * 24, (u8 *)work))[8])) {
            accepted = 1;
          }
          if (accepted == 1) {
            work[0x12] = !cur;
          }
          }
          value = RpRandom();
          distance = fGpffff8308 + (float)((unsigned int)value % 0x50) / 100.0f;
          otherValue = RpRandom();
          distanceRange = fGpffff8308 + (float)((unsigned int)otherValue % 0x50) / 100.0f;
          patrolBounds = (const FldAIPatrolBounds *)((float *)work + work[0x12] * 6 + 6);
          {
            const FldAIPatrolBounds *bounds;
            unsigned char *clearByte = (unsigned char *)&pick;
            int clearCount = 0xc;

            if (clearByte != NULL) {
              do {
                *clearByte = 0;
                clearByte++;
                clearCount--;
              } while (clearCount != 0);
            }
            bounds = patrolBounds;
            pick.x = distance * (bounds->max.x - bounds->min.x) + bounds->min.x + 0.0f;
            pick.z = distanceRange * (bounds->max.z - bounds->min.z) + bounds->min.z + 0.0f;
            picked = pick;
            *(FldAIVec3 *)&((float *)work)[0x14] = picked;
          }
          if (work[0x17] < 1) {
            unsignedValue = work[0x19] != 0 ^ 1;
            work[0x19] = unsignedValue;
            if (unsignedValue != 0) {
              ((float *)work)[0x1b] = *(float *)(work[5] + 0x1c);
            }
            else {
              ((float *)work)[0x1b] = *(float *)(work[5] + 0x18);
            }
            work[0x18] = 0xf;
            value = RpRandom();
            work[0x17] = (int)((unsigned int)value % 3) + 1;
          }
          else {
            work[0x17] = work[0x17] - 1;
          }
          work[0x1c] = 0;
          *work = 2;
        }
      }
      break;
    case 2:
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state2Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state2Forward,&state2Forward);
      matrix = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state2Right = *(FldAIVec3 *)matrix;
      RwV3dNormalize(&state2Right,&state2Right);
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      patrolPosition = ((FldAIMatrix *)value)->pos;
      patrolPosition.y = 0.0f;
      state2Delta.x = ((float *)work)[0x14] - patrolPosition.x;
      state2Delta.y = ((float *)work)[0x15] - patrolPosition.y;
      state2Delta.z = ((float *)work)[0x16] - patrolPosition.z;
      distance = RwV3dNormalize(&state2Delta,&state2Delta);
      factor = *(float *)((u8 *)(u32)work + 0x68);
      factor = fldAIScale(iGpffff830c, factor);
      if (!(distance <= factor)) {
        distance = factor;
      }
      else {
        *work = 1;
      }
      factor = state2Delta.x * state2Forward.x + state2Delta.y * state2Forward.y + state2Delta.z * state2Forward.z;
      if (factor < 1.0f) {
        turnAmount = ((float *)work)[0x1a] * 10.0f;
        factor = 1.0f - factor;
        if (factor < turnAmount / 180.0f) {
          turnAmount = factor * 180.0f;
        }
        if (state2Delta.x * state2Right.x + state2Delta.y * state2Right.y + state2Delta.z * state2Right.z < 0.0f) {
          turnAmount = turnAmount * -1.0f;
        }
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220), D_00756510, turnAmount);
        turnAmount = fldAIAccumulateTurn(&((float *)work)[0x1c], turnAmount);
        if ((!(turnAmount <= 360.0f)) || (turnAmount < -360.0f)) {
          *work = 1;
        }
      }
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220),distance);
      if (0 < work[0x18]) {
        if (work[0x19] != 0) {
          ((float *)work)[0x1a] = (((float *)work)[0x1a] +
                              (*(float *)(work[5] + 0x1c) - *(float *)(work[5] + 0x18)) / 15.0f);
        }
        else {
          ((float *)work)[0x1a] = (((float *)work)[0x1a] -
                              (*(float *)(work[5] + 0x1c) - *(float *)(work[5] + 0x18)) / 15.0f);
        }
        work[0x18] = work[0x18] - 1;
      }
else {
        ((float *)work)[0x1a] = ((float *)work)[0x1b];
      }
      value = FldAI_ChaserCanSeeTarget((unsigned char *)work[3]);
      if (value == 1) {
        value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
        *(FldAIVec3 *)patrolNoticePosition = ((FldAIMatrix *)value)->pos;
        patrolNoticePosition[1] = patrolNoticePosition[1] +
                    ((float (*)[4])D_005F1CC0)[*(unsigned char *)(work[3] + 0x1ca)][*(unsigned char *)(work[3] + 0x1cb)];
        effectTask = (unsigned char *)FldStepFileTask(1);
        FldRc_RequestPositionSlot(effectTask,&patrolNoticePosition[0]);
        sdkSndStartStream(1,0xb,3,5);
        work[0x23] = *(int *)(work[5] + 0x30);
        *work = 6;
      }
      break;
    case 3:
      if (work[0x23] >= 0) {
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220), D_00756510,
                      *(float *)(work[5] + 0x18) * 10.0f * ((float *)work)[0x1d]);
        value = FldAI_ChaserCanSeeTarget((unsigned char *)work[3]);
        if (value == 1) {
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          *(FldAIVec3 *)turnNoticePosition = ((FldAIMatrix *)value)->pos;
          turnNoticePosition[1] = turnNoticePosition[1] +
                      ((float (*)[4])D_005F1CC0)[*(unsigned char *)(work[3] + 0x1ca)][*(unsigned char *)(work[3] + 0x1cb)];
          effectTask = (unsigned char *)FldStepFileTask(1);
          FldRc_RequestPositionSlot(effectTask,&turnNoticePosition[0]);
          sdkSndStartStream(1,0xb,3,5);
          work[0x23] = *(int *)(work[5] + 0x30);
          *work = 6;
        }
        else {
          work[0x23] = work[0x23] - 1;
        }
      }
      else {
        *work = 1;
      }
      break;
    case 4:
      if ((unsigned char *)work[0x22] != (unsigned char *)0x0) {
        value = KDraw_IsEffectDone((unsigned char *)work[0x22]);
        if (value == 0) {
          break;
        }
        kwlnTaskDestroyWithHierarchy((void *)work[0x22]);
        work[0x22] = 0;
      }
      if (work[0x23] >= 0) {
        work[0x23] = work[0x23] - 1;
      }
      else {
        distance = ((float *)work)[0x1f];
        unsignedValue = (unsigned int)distance;
        value = KMisc_CreateRmdFade((int)task,*(int *)(work[3] + 0x50),0,unsignedValue,10);
        work[0x22] = value;
        *work = *work + 1;
      }
      break;
    case 5:
      value = KDraw_IsEffectDone((unsigned char *)work[0x22]);
      if (value != 0) {
        kwlnTaskDestroyWithHierarchy((void *)work[0x22]);
        work[0x22] = 0;
        *(unsigned int *)(work[3] + 0x40) = *(unsigned int *)(work[3] + 0x40) & 0xfffffffd;
        *work = 1;
      }
      break;
    case 6:
      if (work[0x23] >= 0) {
        work[0x23] = work[0x23] - 1;
      }
      else {
        *(unsigned int *)(work[3] + 0x40) = *(unsigned int *)(work[3] + 0x40) | 4;
        mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,1,8,1);
        value = RpRandom();
        unsignedValue = (unsigned int)value % 100;
        action = 0;
        if (work[2] == 0) {
          if (unsignedValue < 0x28) {
            action = 2;
          }
          else if (unsignedValue < 0x50) {
            action = 3;
          }
        }
        else if ((work[2] == 1) && (unsignedValue < 0x14)) {
          action = 2;
        }
        if (action == 0) {
          *work = 7;
          ((float *)work)[0x1a] = *(float *)(work[5] + 0x18);
          ((float *)work)[0x1b] = *(float *)(work[5] + 0x20);
          work[0x18] = 0xf;
          work[0x23] = 0xd2;
        }
        else if (action == 2) {
          work[0x1c] = 0;
          work[0x1e] = 0;
          ((float *)work)[0x1a] = *(float *)(work[5] + 0x18);
          ((float *)work)[0x1b] = *(float *)(work[5] + 0x28);
          work[0x18] = 0xf;
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          approachOrigin = ((FldAIMatrix *)value)->pos;
          approachOrigin.y = 0.0f;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state6Direction.x = ((FldAIMatrix *)value)->pos.x - approachOrigin.x;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state6Direction.y = ((FldAIMatrix *)value)->pos.y - approachOrigin.y;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state6Direction.z = ((FldAIMatrix *)value)->pos.z - approachOrigin.z;
          RwV3dNormalize(&state6Direction,&state6Direction);
          state6Direction.x = state6Direction.x * 200.0f;
          state6Direction.y = state6Direction.y * 200.0f;
          state6Direction.z = state6Direction.z * 200.0f;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          *(float *)((u8 *)(u32)work + 0x50) = (state6Direction.x + ((FldAIMatrix *)value)->pos.x);
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          *(float *)((u8 *)(u32)work + 0x54) = (state6Direction.y + ((FldAIMatrix *)value)->pos.y);
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          *(float *)((u8 *)(u32)work + 0x58) = (state6Direction.z + ((FldAIMatrix *)value)->pos.z);
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          aiPos6 = ((FldAIMatrix *)value)->pos;
          aiPos6.y = 0.0f;
          state6Delta.x = ((float *)work)[0x14] - aiPos6.x;
          state6Delta.y = ((float *)work)[0x15] - aiPos6.y;
          state6Delta.z = ((float *)work)[0x16] - aiPos6.z;
          distance = RwV3dNormalize(&state6Delta,&state6Delta);
          work[0x25] = (int)(distance / (iGpffff830c * *(float *)(work[5] + 0x28)));
          *work = 9;
        }
        else if (action == 3) {
          ((float *)work)[0x1a] = *(float *)(work[5] + 0x18);
          ((float *)work)[0x1b] = *(float *)(work[5] + 0x28);
          work[0x18] = 0xf;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          *(FldAIVec3 *)&((float *)work)[0x14] = ((FldAIMatrix *)value)->pos;
          *work = 10;
        }
      }
      break;
    case 7:
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state7Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state7Forward,&state7Forward);
      matrix = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state7Right = *(FldAIVec3 *)matrix;
      RwV3dNormalize(&state7Right,&state7Right);
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      chasePosition = ((FldAIMatrix *)value)->pos;
      chasePosition.y = 0.0f;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state7Delta.x = ((FldAIMatrix *)value)->pos.x - chasePosition.x;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state7Delta.y = ((FldAIMatrix *)value)->pos.y - chasePosition.y;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state7Delta.z = ((FldAIMatrix *)value)->pos.z - chasePosition.z;
      distance = RwV3dNormalize(&state7Delta,&state7Delta);
      factor = iGpffff830c * ((float *)work)[0x1a];
      if (!(distance <= factor)) {
        distance = factor;
      }
      factor = state7Delta.x * state7Forward.x + state7Delta.y * state7Forward.y + state7Delta.z * state7Forward.z;
      if (factor < 1.0f) {
        turnAmount = ((float *)work)[0x1a] * 10.0f;
        factor = 1.0f - factor;
        if (factor < turnAmount / 180.0f) {
          turnAmount = factor * 180.0f;
        }
        if (state7Delta.x * state7Right.x + state7Delta.y * state7Right.y + state7Delta.z * state7Right.z < 0.0f) {
          turnAmount = turnAmount * -1.0f;
        }
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220), D_00756510, turnAmount);
      }
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220),distance);
      if (0 < work[0x18]) {
        *(float *)((u8 *)(u32)work + 0x68) = (*(float *)((u8 *)(u32)work + 0x68) +
                            (*(float *)(work[5] + 0x20) - *(float *)(work[5] + 0x18)) / 15.0f);
        work[0x18] = work[0x18] - 1;
      }
else {
        *(float *)((u8 *)(u32)work + 0x68) = ((float *)work)[0x1b];
      }
      if ((D_00764348 == 0) && (value = work[3], iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(value + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(value + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(value + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(configAddress + 8), *(float *)(configAddress + 4)) == 1) {
          iGpffffb310 = value;
        }
      }
      if ((work[0x23] < 1) && (value = FldAI_ChaserCanSeeTarget((unsigned char *)work[3]), value == 0)) {
        work[0x23] = *(int *)(work[5] + 0x34);
        *work = 0xb;
        mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,8,1);
      }
      else {
        if (0 < work[0x23]) {
          work[0x23] = work[0x23] - 1;
        }
        value = work[0x24];
        if (value < 1) {
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          state7Delta.x = *(float *)((u8 *)(u32)(value) + 0x30) - *(float *)(work[3] + 0x19c);
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          state7Delta.y = *(float *)((u8 *)(u32)(value) + 0x34) - *(float *)(work[3] + 0x1a0);
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          state7Delta.z = *(float *)((u8 *)(u32)(value) + 0x38) - *(float *)(work[3] + 0x1a4);
          distance = RwV3dNormalize(&state7Delta,&state7Delta);
          if (distance >= *(float *)work[5]) {
            work[0x23] = *(int *)(work[5] + 0x34);
            mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,8,1);
            *work = 0xb;
          }
        }
        else if (0 < value) {
          work[0x24] = value - 1;
        }
      }
      break;
    case 8:
      distance = FldEvent_GetMoveStep();
      if (distance == 0.0f) {
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        aiPos2 = ((FldAIMatrix *)value)->pos;
      }
      else {
        f32 facingZ;
        f32 playerFacingZ;
        f32 facingX;
        f32 playerFacingX;
        value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
        facingZ = ((FldAIMatrix *)value)->forward.z;
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        playerFacingZ = ((FldAIMatrix *)value)->forward.z;
        value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
        facingX = ((FldAIMatrix *)value)->forward.x;
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        playerFacingX = ((FldAIMatrix *)value)->forward.x;
        value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
        otherValue = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        if (playerFacingX * facingX + ((FldAIMatrix *)otherValue)->forward.y * ((FldAIMatrix *)value)->forward.y + playerFacingZ * facingZ > fGpffff8310)
        {
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          aiPos2 = ((FldAIMatrix *)value)->pos;
          *work = 7;
        }
        else {
          distance = FldEvent_GetMoveStep();
          distance = distance - ((float *)work)[0x1a];
          if (distance < 0.0f) {
            distance = distance * -1.0f;
          }
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          predictionPosition = ((FldAIMatrix *)value)->pos;
          predictionPosition.y = 0.0f;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Delta.x = ((FldAIMatrix *)value)->pos.x - predictionPosition.x;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Delta.y = ((FldAIMatrix *)value)->pos.y - predictionPosition.y;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Delta.z = ((FldAIMatrix *)value)->pos.z - predictionPosition.z;
          factor = RwV3dNormalize(&state8Delta,&state8Delta);
          factor = factor / distance;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Forward = ((FldAIMatrix *)value)->forward;
          state8Forward.x = state8Forward.x * (factor * FldEvent_GetMoveStep());
          state8Forward.y = state8Forward.y * (factor * FldEvent_GetMoveStep());
          state8Forward.z = state8Forward.z * (factor * FldEvent_GetMoveStep());
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          aiPos2 = ((FldAIMatrix *)value)->pos;
          aiPos2.x = aiPos2.x + state8Forward.x;
          aiPos2.y = aiPos2.y + state8Forward.y;
          aiPos2.z = aiPos2.z + state8Forward.z;
        }
      }
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state8Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state8Forward,&state8Forward);
      matrix = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state8Right = *(FldAIVec3 *)matrix;
      RwV3dNormalize(&state8Right,&state8Right);
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      aiPos8 = ((FldAIMatrix *)value)->pos;
      aiPos8.y = 0.0f;
      state8Delta.x = aiPos2.x - aiPos8.x;
      state8Delta.y = aiPos2.y - aiPos8.y;
      state8Delta.z = aiPos2.z - aiPos8.z;
      distance = RwV3dNormalize(&state8Delta,&state8Delta);
      factor = iGpffff830c * ((float *)work)[0x1a];
      if (!(distance <= factor)) {
        distance = factor;
      }
      factor = state8Delta.x * state8Forward.x + state8Delta.y * state8Forward.y + state8Delta.z * state8Forward.z;
      if (factor < 1.0f) {
        turnAmount = ((float *)work)[0x1a] * 10.0f;
        factor = 1.0f - factor;
        if (factor < turnAmount / 180.0f) {
          turnAmount = factor * 180.0f;
        }
        if (state8Delta.x * state8Right.x + state8Delta.y * state8Right.y + state8Delta.z * state8Right.z < 0.0f) {
          turnAmount = turnAmount * -1.0f;
        }
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220), D_00756510, turnAmount);
      }
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220),distance);
      if (0 < work[0x18]) {
        *(float *)((u8 *)(u32)work + 0x68) = (*(float *)((u8 *)(u32)work + 0x68) +
                            (*(float *)(work[5] + 0x20) - *(float *)(work[5] + 0x18)) / 15.0f);
        work[0x18] = work[0x18] - 1;
      }
else {
        *(float *)((u8 *)(u32)work + 0x68) = ((float *)work)[0x1b];
      }
      if ((D_00764348 == 0) && (value = work[3], iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(value + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(value + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(value + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(configAddress + 8), *(float *)(configAddress + 4)) == 1) {
          iGpffffb310 = value;
        }
      }
      if ((work[0x23] < 1) && (value = FldAI_ChaserCanSeeTarget((unsigned char *)work[3]), value == 0)) {
        work[0x23] = *(int *)(work[5] + 0x34);
        *work = 0xb;
        mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,8,1);
      }
      else {
        if (0 < work[0x23]) {
          work[0x23] = work[0x23] - 1;
        }
        value = work[0x24];
        if (value < 1) {
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          state8Delta.x = *(float *)((u8 *)(u32)(value) + 0x30) - *(float *)(work[3] + 0x19c);
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          state8Delta.y = *(float *)((u8 *)(u32)(value) + 0x34) - *(float *)(work[3] + 0x1a0);
          value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
          state8Delta.z = *(float *)((u8 *)(u32)(value) + 0x38) - *(float *)(work[3] + 0x1a4);
          distance = RwV3dNormalize(&state8Delta,&state8Delta);
          if (distance >= *(float *)work[5]) {
            work[0x23] = *(int *)(work[5] + 0x34);
            *work = 0xb;
            mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,8,1);
          }
        }
        else if (0 < value) {
          work[0x24] = value - 1;
        }
      }
      break;
    case 9:
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state9Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state9Forward,&state9Forward);
      matrix = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state9Right = *(FldAIVec3 *)matrix;
      RwV3dNormalize(&state9Right,&state9Right);
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      weavePosition = ((FldAIMatrix *)value)->pos;
      weavePosition.y = 0.0f;
      turnAmount = sinf(((f32 *)work)[0x1e]);
      *(float *)((u8 *)(u32)work + 0x78) = (*(float *)((u8 *)(u32)work + 0x78) + fGpffff8218);
      state9Direction.x = *(float *)((u8 *)(u32)work + 0x50) - weavePosition.x;
      distance = weavePosition.y;
      state9Direction.y = *(float *)((u8 *)(u32)work + 0x54) - distance;
      factor = weavePosition.z;
      state9Direction.z = *(float *)((u8 *)(u32)work + 0x58) - factor;
      RwV3dNormalize(&state9Direction,&state9Direction);
      state9Direction.x = state9Direction.x * 200.0f;
      state9Direction.y = state9Direction.y * 200.0f;
      state9Direction.z = state9Direction.z * 200.0f;
      state9Direction.x = state9Direction.x + ((float *)work)[0x14];
      state9Direction.y = state9Direction.y + ((float *)work)[0x15];
      state9Direction.z = state9Direction.z + ((float *)work)[0x16];
      turnAmount = fldAIScale(400.0f, turnAmount);
      state9Delta.x = state9Right.x * turnAmount;
      state9Delta.y = state9Right.y * turnAmount;
      state9Delta.z = state9Right.z * turnAmount;
      state9Delta.x = state9Delta.x + state9Direction.x;
      state9Delta.y = state9Delta.y + state9Direction.y;
      state9Delta.z = state9Delta.z + state9Direction.z;
      state9Delta.x = state9Delta.x - weavePosition.x;
      state9Delta.y = state9Delta.y - distance;
      state9Delta.z = state9Delta.z - factor;
      distance = RwV3dNormalize(&state9Delta,&state9Delta);
      factor = *(float *)&work[0x1a];
      factor = fldAIScale(iGpffff830c, factor);
      if (!(distance <= factor)) {
        distance = factor;
      }
      if (work[0x25] < 1) {
        *(unsigned int *)(work[3] + 0x40) = *(unsigned int *)(work[3] + 0x40) & 0xfffffffb;
        ((float *)work)[0x1a] = *(float *)(work[5] + 0x18);
        *work = 1;
        mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,8,1);
      }
      else {
        work[0x25] = work[0x25] - 1;
      }
      factor = state9Delta.x * state9Forward.x + state9Delta.y * state9Forward.y + state9Delta.z * state9Forward.z;
      turnAmount = 5.0f * (10.0f * *(float *)((u8 *)(u32)work + 0x68));
      factor = 1.0f - factor;
      if (factor < turnAmount / 180.0f) {
        turnAmount = factor * 180.0f;
      }
      if (state9Delta.x * state9Right.x + state9Delta.y * state9Right.y + state9Delta.z * state9Right.z < 0.0f) {
        turnAmount = turnAmount * -1.0f;
      }
      FldFrameTask_Rotate(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220), D_00756510, turnAmount);
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220),distance);
      if (0 < work[0x18]) {
        ((float *)work)[0x1a] = (((float *)work)[0x1a] +
                            (*(float *)(work[5] + 0x20) - *(float *)(work[5] + 0x18)) / 15.0f);
        work[0x18] = work[0x18] - 1;
      }
else {
        ((float *)work)[0x1a] = ((float *)work)[0x1b];
      }
      if ((D_00764348 == 0) && (value = work[3], iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(value + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(value + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(value + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(configAddress + 8), *(float *)(configAddress + 4)) == 1) {
          iGpffffb310 = value;
        }
      }
      break;
    case 10:
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state10Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state10Forward,&state10Forward);
      matrix = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state10Right = *(FldAIVec3 *)matrix;
      RwV3dNormalize(&state10Right,&state10Right);
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      chargePosition = ((FldAIMatrix *)value)->pos;
      chargePosition.y = 0.0f;
      state10Delta.x = ((float *)work)[0x14] - chargePosition.x;
      state10Delta.y = ((float *)work)[0x15] - chargePosition.y;
      state10Delta.z = ((float *)work)[0x16] - chargePosition.z;
      distance = RwV3dNormalize(&state10Delta,&state10Delta);
      factor = *(float *)&work[0x1a];
      factor = fldAIScale(iGpffff830c, factor);
      if (!(distance <= factor)) {
        distance = factor;
      }
      else {
        *(unsigned int *)(work[3] + 0x40) = *(unsigned int *)(work[3] + 0x40) & 0xfffffffb;
        ((float *)work)[0x1a] = *(float *)(work[5] + 0x18);
        *work = 1;
        mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,8,1);
      }
      turnAmount = state10Delta.x * state10Forward.x + state10Delta.y * state10Forward.y + state10Delta.z * state10Forward.z;
      factor = 10.0f * *(float *)((u8 *)(u32)work + 0x68);
      turnAmount = 1.0f - turnAmount;
      if (turnAmount < factor / 180.0f) {
        factor = turnAmount * 180.0f;
      }
      if (state10Delta.x * state10Right.x + state10Delta.y * state10Right.y + state10Delta.z * state10Right.z < 0.0f) {
        factor = factor * -1.0f;
      }
      FldFrameTask_Rotate(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220), D_00756510, factor);
      factor = fldAIAccumulateTurn(&((float *)work)[0x1c], factor);
      if ((!(factor <= 360.0f)) || (factor < -360.0f)) {
        *(unsigned int *)(work[3] + 0x40) = *(unsigned int *)(work[3] + 0x40) & 0xfffffffb;
        ((float *)work)[0x1a] = *(float *)(work[5] + 0x18);
        *work = 1;
      }
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220),distance);
      if (0 < work[0x18]) {
        ((float *)work)[0x1a] = (((float *)work)[0x1a] +
                            (*(float *)(work[5] + 0x20) - *(float *)(work[5] + 0x18)) / 15.0f);
        work[0x18] = work[0x18] - 1;
      }
else {
        ((float *)work)[0x1a] = ((float *)work)[0x1b];
      }
      if ((D_00764348 == 0) && (value = work[3], iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(value + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(value + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(value + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(configAddress + 8), *(float *)(configAddress + 4)) == 1) {
          iGpffffb310 = value;
        }
      }
      break;
    case 0xb:
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state11Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state11Forward,&state11Forward);
      matrix = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      state11Right = *(FldAIVec3 *)matrix;
      RwV3dNormalize(&state11Right,&state11Right);
      value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
      returnPosition = ((FldAIMatrix *)value)->pos;
      returnPosition.y = 0.0f;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state11Delta.x = ((FldAIMatrix *)value)->pos.x - returnPosition.x;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state11Delta.y = ((FldAIMatrix *)value)->pos.y - returnPosition.y;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state11Delta.z = ((FldAIMatrix *)value)->pos.z - returnPosition.z;
      RwV3dNormalize(&state11Delta,&state11Delta);
      distance = state11Delta.x * state11Forward.x + state11Delta.y * state11Forward.y + state11Delta.z * state11Forward.z;
      if (distance < 1.0f) {
        factor = ((float *)work)[0x1a] * 10.0f;
        distance = 1.0f - distance;
        if (distance < factor / 180.0f) {
          factor = distance * 180.0f;
        }
        if (state11Delta.x * state11Right.x + state11Delta.y * state11Right.y + state11Delta.z * state11Right.z < 0.0f) {
          factor = factor * -1.0f;
        }
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220), D_00756510, factor);
      }
      value = FldAI_ChaserCanSeeTarget((unsigned char *)work[3]);
      if (value == 1) {
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        state11Delta.x = *(float *)((u8 *)(u32)(value) + 0x30) - *(float *)(work[3] + 0x19c);
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        state11Delta.y = *(float *)((u8 *)(u32)(value) + 0x34) - *(float *)(work[3] + 0x1a0);
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        state11Delta.z = *(float *)((u8 *)(u32)(value) + 0x38) - *(float *)(work[3] + 0x1a4);
        distance = RwV3dNormalize(&state11Delta,&state11Delta);
        if (distance < *(float *)work[5]) {
          ((float *)work)[0x1a] = ((float *)work[5])[6];
          ((float *)work)[0x1b] = *(float *)(work[5] + 0x20);
          work[0x18] = 1;
          work[0x23] = 0xd2;
          work[0x24] = 0x3c;
          *work = 7;
          mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,1,8,1);
          break;
        }
      }
      if ((D_00764348 == 0) && (value = work[3], iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(value + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(value + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(value + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(configAddress + 8), *(float *)(configAddress + 4)) == 1) {
          iGpffffb310 = value;
        }
      }
      if (work[0x23] >= 0) {
        work[0x23] = work[0x23] - 1;
      }
      else {
        value = (int)mdlGetMatrix((u8 *)*(unsigned int *)(work[3] + 0x50));
        aiHere = ((FldAIMatrix *)value)->pos;
        accepted = 0;
        if ((!(aiHere.x < ((float *)work)[9]) && (aiHere.x <= ((float *)work)[6])) &&
            !(aiHere.z < ((float *)work)[0xb]) && (aiHere.z <= ((float *)work)[8])) {
          accepted = 1;
        }
        if (accepted == 0) {
          accepted = 0;
          if ((!(aiHere.x < ((float *)work)[0xf]) && (aiHere.x <= ((float *)work)[0xc])) &&
             !(aiHere.z < ((float *)work)[0x11]) && (aiHere.z <= ((float *)work)[0xe])) {
            accepted = 1;
          }
          if (accepted == 0) {
            *(unsigned int *)(work[3] + 0x40) = *(unsigned int *)(work[3] + 0x40) | 2;
            if (*(unsigned char *)(work[3] + 0x1ca) == '\x01') {
              value = *(int *)(work[3] + 0x50);
              *(unsigned int *)(value + 0xd8) = *(unsigned int *)(value + 0xd8) & 0xffffff7f;
            }
            mdlSetAlphaBlend(((FldAINpc *)work[3])->model);
            value = work[3];
            if (*(unsigned char *)(value + 0x1ca) == '\0') {
              value = KMisc_CreateRmdFade((int)task,*(int *)(value + 0x50),0xff,0,10);
              work[0x22] = value;
            }
            else if (*(unsigned char *)(value + 0x1ca) == '\x01') {
              distance = ((float *)work)[0x1f];
              unsignedValue = (unsigned int)distance;
              value = KMisc_CreateRmdFade((int)task,*(int *)(value + 0x50),unsignedValue,0,10);
              work[0x22] = value;
            }
            ((float *)work)[0x1a] = *(float *)(work[5] + 0x18);
            *work = 0xc;
            mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,8,1);
            break;
          }
        }
        *(unsigned int *)(work[3] + 0x40) = *(unsigned int *)(work[3] + 0x40) & 0xfffffffb;
        ((float *)work)[0x1a] = *(float *)(work[5] + 0x18);
        *work = 1;
        mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,8,1);
      }
      break;
    case 0xc:
      value = KDraw_IsEffectDone((unsigned char *)work[0x22]);
      if (value != 0) {
        kwlnTaskDestroyWithHierarchy((void *)work[0x22]);
        work[0x22] = 0;
        FldFrameTask_SetPosition(*(unsigned char **)(*(int *)(work[3] + 0x54) + 0x220),(u8 *)&((FldAINpc *)work[3])->origin);
        value = work[3];
        if (*(unsigned char *)(value + 0x1ca) == '\0') {
          value = KMisc_CreateRmdFade((int)task,*(int *)(value + 0x50),0,0xff,10);
          work[0x22] = value;
        }
        else if (*(unsigned char *)(value + 0x1ca) == '\x01') {
          distance = ((float *)work)[0x1f];
          unsignedValue = (unsigned int)distance;
          value = KMisc_CreateRmdFade((int)task,*(int *)(value + 0x50),0,unsignedValue,10);
          work[0x22] = value;
        }
        *work = 0xd;
      }
      break;
    case 0xd:
      value = KDraw_IsEffectDone((unsigned char *)work[0x22]);
      if (value != 0) {
        if (*(unsigned char *)(work[3] + 0x1ca) == '\x01') {
          value = *(int *)(work[3] + 0x50);
          *(unsigned int *)(value + 0xd8) = *(unsigned int *)(value + 0xd8) | 0x80;
        }
        mdlClearAlphaBlend(((FldAINpc *)work[3])->model);
        *(unsigned int *)(work[3] + 0x40) = *(unsigned int *)(work[3] + 0x40) & 0xfffffff9;
        kwlnTaskDestroyWithHierarchy((void *)work[0x22]);
        work[0x22] = 0;
        *work = 1;
      }
      break;
    case 14:
      break;
    }
    return 0;
  }
  return 0;
}
#pragma pop

/* Release the patrol transform and task-owned work. */
/* Raw task-work read retained: replacing +0x38 with SdkTask::work changes b210 instruction selection. */
// FUN_001821D0
void FldAI_PatrolDestroy(u8 *task) {
    s32 h = *(s32 *)(*(u8 **)(task + 0x38) + 0x10);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(task + 0x38));
}

/* Create a disabled patrol controller and capture its camera-distance fade range. */
/* The 0xA0-byte patrol allocation stores actor/paused/behavior and camera fade limits; remaining fields are initialized by the update. */
// FUN_00182220
s32 FldAI_SpawnPatrol(s32 parent, s32 actor, s32 behavior)
{
    s32 ret;
    u8 *work;

    chkmemAllocSiteTag(D_005F1B18, 0xA50);
    work = D_008873F4[0](1, 0xA0, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F1CF0), 0xF, 0, 0, FldAI_PatrolUpdate, FldAI_PatrolDestroy, (u8 *)(work));
    *(s32 *)(work + 0xC) = actor;
    *(s32 *)(work + 0x4) = 1;
    *(s32 *)(work + 0x8) = behavior;
    *(f32 *)(work + 0x80) = *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
    *(f32 *)(work + 0x84) = iGpffffba6c;
    return ret;
}
