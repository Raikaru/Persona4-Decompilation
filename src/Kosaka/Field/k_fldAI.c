#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
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
extern s32 FldAI_ChaserUpdate(u8 *arg0);
extern s32 FldAI_PatrolUpdate(u8 *arg0);
extern u8 *D_007EFA00[];
extern s32 iGpffffb25c;
extern u8 *iGpffffb2c8;
extern s32 K_FldEvent_IsPosWithinFov(u8 *arg0, u8 *arg1, f32 arg2);
extern s32 K_FldEvent_ArePosWithinDist(u8 *arg0, u8 *arg1, f32 arg2);
extern s32 FldFrame_RaycastField(const RwV3d *line, RwV3d *hitPointDst);
extern f32 RwV3dLength(f32 *arg0);
extern u8 *mdlGetMatrix(u8 *arg0);

typedef RwV3d FldAIVec3;
typedef struct { f32 x, y, z, w; } FldAIVec4;
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

    work = *(u8 **)(task + 0x38);
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
            cameraPosition = *(RwV3d *)(matrix + 0x30);
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
                mdlDispatchAnimIfPresent(*(u8 **)(*(u8 **)(work + 0x10) + 0x50), 0, (s16)desiredAnimation, 0, 1);
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
        matrix = mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50));
        selfForward = *(RwV3d *)(matrix + 0x20);
        matrix = mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50));
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
                    (const struct RwMatrix *)mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)),
                    (const RwV3d *)(mdlGetMatrix(*otherModel) + 0x30),
                    *(f32 *)(work + 0x28), *(f32 *)(work + 0x24), 0.0f);
                if (!(candidate < 0.0f) && candidate <= 80.0f) {
                    u8 **nearbyModel = (u8 **)(D_007EF9B0 + (u32)index * 0x750u + 0x50);
                    f32 coordinate;
                    coordinate = *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x30);
                    separation.x = *(f32 *)(mdlGetMatrix(*nearbyModel) + 0x30) - coordinate;
                    coordinate = *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x34);
                    separation.y = *(f32 *)(mdlGetMatrix(*nearbyModel) + 0x34) - coordinate;
                    coordinate = *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x38);
                    separation.z = *(f32 *)(mdlGetMatrix(*nearbyModel) + 0x38) - coordinate;
                    RwV3dNormalize(&separation, &separation);
                    turnAmount = 800.0f / candidate;
                    speed = iGpffff84e0;
                    dot = separation.x * selfRight.x + separation.y * selfRight.y + separation.z * selfRight.z;
                    if (!(dot < 0.0f)) turnAmount *= -1.0f;
                    turn += turnAmount;
                }
                if (*(u8 **)(work + 0x14) == entry && !(candidate < 0.0f)) {
                    u8 **leaderModel = (u8 **)(D_007EF9B0 + (u32)index * 0x750u + 0x50);
                    *(f32 *)(work + 0x30) += *(f32 *)(mdlGetMatrix(*leaderModel) + 0x30);
                    *(f32 *)(work + 0x34) += *(f32 *)(mdlGetMatrix(*leaderModel) + 0x34);
                    *(f32 *)(work + 0x38) += *(f32 *)(mdlGetMatrix(*leaderModel) + 0x38);
                    *(f32 *)(work + 0x3C) += *(f32 *)(mdlGetMatrix(*leaderModel) + 0x20);
                    *(f32 *)(work + 0x40) += *(f32 *)(mdlGetMatrix(*leaderModel) + 0x24);
                    *(f32 *)(work + 0x44) += *(f32 *)(mdlGetMatrix(*leaderModel) + 0x28);
                    *(s32 *)(work + 0x2C) += 1;
                }
            }
        }
        {
            f32 coordinate;
            coordinate = *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x14) + 0x50)) + 0x30);
            leaderDelta.x = coordinate - *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x30);
            coordinate = *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x14) + 0x50)) + 0x34);
            leaderDelta.y = coordinate - *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x34);
            coordinate = *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x14) + 0x50)) + 0x38);
            leaderDelta.z = coordinate - *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x38);
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
                matrix = mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x14) + 0x50));
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
                matrix = mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x14) + 0x50));
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
            offset.x += *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x30);
            offset.y += *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x34);
            offset.z += *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x38);
            *(f32 *)(work + 0x30) += offset.x;
            *(f32 *)(work + 0x34) += offset.y;
            *(f32 *)(work + 0x38) += offset.z;
            *(f32 *)(work + 0x30) /= (f32)(*(s32 *)(work + 0x2C) + 1);
            *(f32 *)(work + 0x34) /= (f32)(*(s32 *)(work + 0x2C) + 1);
            *(f32 *)(work + 0x38) /= (f32)(*(s32 *)(work + 0x2C) + 1);
            separation.x = *(f32 *)(work + 0x30) - *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x30);
            separation.y = *(f32 *)(work + 0x34) - *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x34);
            separation.z = *(f32 *)(work + 0x38) - *(f32 *)(mdlGetMatrix(*(u8 **)(*(u8 **)(work + 0x10) + 0x50)) + 0x38);
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
                        mdlDispatchAnimIfPresent(*(u8 **)(*(u8 **)(work + 0x10) + 0x50), 0, (s16)desiredAnimation, 16, 1);
                    }
                    *(s32 *)(work + 0x60) = 0;
                }
            } else {
                currentAnimation = (s16)mdlGetLayerAnimation(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
                desiredAnimation = FldMoveAnimSecondary(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                if (currentAnimation != desiredAnimation) {
                    desiredAnimation = (s16)FldMoveAnimSecondary(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                    mdlDispatchAnimIfPresent(*(u8 **)(*(u8 **)(work + 0x10) + 0x50), 0, (s16)desiredAnimation, 8, 1);
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
// FUN_0017E840
void FldAI_ChaserDestroy(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x50);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0017E890
s32 FldAI_SpawnChaser(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    u8 *work;

    chkmemAllocSiteTag(D_005F1B18, 0x3D9);
    work = D_008873F4[0](1, 0x74, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F1B28), 0xF, 0, 0, FldAI_ChaserUpdate, FldAI_ChaserDestroy, (u8 *)(work));
    *(s32 *)(work + 0x10) = arg1;
    *(s32 *)(work + 0x14) = arg2;
    *(s32 *)(work + 0x1C) = -1;
    *(f32 *)(work + 0x64) = *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
    return ret;
}

// FUN_0017E980
s32 FldAI_ChaserGetState(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x48);
}

// FUN_0017E990
void FldAI_ChaserEnable(u8 *arg0) {
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) = 1;
}

// FUN_0017E9B0
void FldAI_ChaserDisable(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

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
// FUN_0017EA10
s32 FldAI_ChaserCanSeeTarget(u8 *arg0)
{
    FldAIVec3 d;
    FldAIVec3 out;
    FldAIVec3 ab[2];
    f32 temp_f20;
    s32 var_17;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_2;
    u8 *temp_2_2;

    var_17 = 0;
    temp_16 = iGpffffb2c8 + (*(u8 *)(arg0 + 0x1CA) * 0x180) +
              (*(u16 *)(arg0 + 0x1C8) << 6);
    if (iGpffffb25c == 1) {
        return 0;
    }
    if (*(u8 *)(arg0 + 0x1CB) == 0) {
        temp_18 = mdlGetMatrix(*(u8 **)(arg0 + 0x50));
        if (K_FldEvent_ArePosWithinDist(temp_18 + 0x30,
                          mdlGetMatrix(D_007EFA00[0]) + 0x30,
                          *(f32 *)(temp_16 + 0x14) / 3.0f) == 1) {
            var_17 = 1;
        }
        return var_17;
    }
    temp_2 = mdlGetMatrix(*(u8 **)(arg0 + 0x50));
    ab[0] = *(FldAIVec3 *)(temp_2 + 0x30);
    temp_2_2 = mdlGetMatrix(D_007EFA00[0]);
    ab[1] = *(FldAIVec3 *)(temp_2_2 + 0x30);
    ab[0].y += 90.0f;
    ab[1].y += 90.0f;
    if (FldFrame_RaycastField(ab, &out) == 1) {
        return 0;
    }
    temp_2 = (u8 *)ab;
    temp_2_2 = (u8 *)&out;
    out = ab[0];
    ab[0] = ab[1];
    ab[1] = out;
    if (FldFrame_RaycastField((const RwV3d *)temp_2, (RwV3d *)temp_2_2) == 1) {
        return 0;
    }
    temp_17 = mdlGetMatrix(*(u8 **)(arg0 + 0x50));
    if (K_FldEvent_IsPosWithinFov(temp_17, mdlGetMatrix(D_007EFA00[0]) + 0x30,
                      *(f32 *)(temp_16 + 0xC)) == 1) {
        temp_f20 = *(f32 *)(mdlGetMatrix(*(u8 **)(arg0 + 0x50)) + 0x30);
        d.x = *(f32 *)(mdlGetMatrix(D_007EFA00[0]) + 0x30) - temp_f20;
        temp_f20 = *(f32 *)(mdlGetMatrix(*(u8 **)(arg0 + 0x50)) + 0x34);
        d.y = *(f32 *)(mdlGetMatrix(D_007EFA00[0]) + 0x34) - temp_f20;
        temp_f20 = *(f32 *)(mdlGetMatrix(*(u8 **)(arg0 + 0x50)) + 0x38);
        d.z = *(f32 *)(mdlGetMatrix(D_007EFA00[0]) + 0x38) - temp_f20;
        if (RwV3dLength((f32 *)&d) < *(f32 *)(temp_16 + 0x10)) {
            return 1;
        }
    }
    temp_17 = mdlGetMatrix(*(u8 **)(arg0 + 0x50));
    if (K_FldEvent_ArePosWithinDist(temp_17 + 0x30,
                      mdlGetMatrix(D_007EFA00[0]) + 0x30,
                      *(f32 *)(temp_16 + 0x14)) == 1) {
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
// FUN_0017F490
int FldAI_PatrolUpdate(unsigned char *param_1)
{
  typedef struct { unsigned char r, g, b, a; } FldAIColor;
  float distVec[3];
  int *piVar1;
  const FldAIPatrolBounds *patrolBounds;
  int temp_v0;
  unsigned char *puVar4;
  int temp_v1;
  float *pfVar6;
  unsigned char *pbVar7;
  float *pfVar8;
  void *pvVar9;
  unsigned int temp_v2;
  int temp_v3;
  unsigned char temp_v4;
  int temp_v5;
  int temp_v6;
  unsigned int temp_v7;
  float temp_v8;
  float temp_v9;
  float temp_v10;
  float temp_v11;
  FldAIVec3 aiPos;
  FldAIVec3 state2Forward;
  FldAIVec3 state2Right;
  FldAIVec3 state2Delta;
  FldAIVec3 aiV60;
  float vec70[3];
  float vec80[3];
  FldAIVec3 state6Delta;
  FldAIVec3 state6Direction;
  FldAIVec3 aiVB0;
  FldAIVec3 state7Forward;
  FldAIVec3 state7Right;
  FldAIVec3 state7Delta;
  FldAIVec3 aiVF0;
  FldAIVec3 state8Forward;
  FldAIVec3 state8Right;
  FldAIVec3 state8Delta;
  FldAIVec3 aiV130;
  FldAIVec3 aiPos2;
  FldAIVec3 state9Forward;
  FldAIVec3 state9Right;
  FldAIVec3 state9Delta;
  FldAIVec3 state9Direction;
  FldAIVec3 aiV190;
  FldAIVec3 state10Forward;
  FldAIVec3 state10Right;
  FldAIVec3 state10Delta;
  FldAIVec3 aiV1D0;
  FldAIVec3 state11Forward;
  FldAIVec3 state11Right;
  FldAIVec3 state11Delta;
  FldAIVec3 aiV210;
  FldAIVec3 picked;
  FldAIVec3 pick;
  FldAIVec3 aiPos6;
  FldAIVec3 aiPos8;
  FldAIVec3 aiHere;
  FldAIColor color;
  
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1[1] == 1) {
    return 0;
  }
  temp_v5 = 0;
  temp_v0 = piVar1[3];
  if (*(int *)(temp_v0 + 0x48) == 0)
    goto availabilityDone;
  if (*(void **)(temp_v0 + 0x54) == NULL)
    goto availabilityDone;
  temp_v5 = 1;
availabilityDone:
  temp_v4 = temp_v5 != 0;
  if (temp_v4 == 0)
    return 0;
  {
    if ((*(unsigned int *)(temp_v0 + 0x40) & 1) == 0) {
      return 0;
    }
    temp_v0 = kwlnGetCamera();
    temp_v0 = (int)func_003e9700((struct RwFrame *)*(unsigned int *)(temp_v0 + 4));
    puVar4 = (unsigned char *)mdlGetColor((void *)*(unsigned int *)(piVar1[3] + 0x50));
    {
        typedef struct { unsigned char c[4]; } FldAIColorBytes;
        color = *(FldAIColor *)puVar4;
    }
    temp_v8 = ((float *)(int *)(u32)piVar1)[0x20];
    temp_v10 = ((float *)piVar1)[0x21] - temp_v8;
    if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\0') {
      temp_v8 = fGpffff80f0 * temp_v10 + temp_v8 + 0.0f;
    }
    else {
      temp_v8 = fGpffff811c * temp_v10 + temp_v8 + 0.0f;
    }
    temp_v11 = ((float *)piVar1)[0x21] - temp_v8;
    temp_v1 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
    distVec[0] = *(float *)(temp_v1 + 0x30) - *(float *)(temp_v0 + 0x30);
    temp_v1 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
    distVec[1] = *(float *)(temp_v1 + 0x34) - *(float *)(temp_v0 + 0x34);
    temp_v1 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
    distVec[2] = *(float *)(temp_v1 + 0x38) - *(float *)(temp_v0 + 0x38);
    temp_v10 = RwV3dLength(&distVec[0]);
    if (!(temp_v10 < ((float *)(int *)(u32)piVar1)[0x21])) {
      ((float *)piVar1)[0x1f] = (float)(color.a = 0);
    }
    else if (temp_v10 >= temp_v8) {
      if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\0') {
        temp_v8 = 1.0f - fGpffff825c * ((temp_v10 - temp_v8) / temp_v11);
        temp_v9 = (temp_v8 < 0.0f) ? 0.0f : temp_v8;
      }
      else {
        temp_v9 = 1.0f - (temp_v10 - temp_v8) / temp_v11;
      }
      ((float *)piVar1)[0x1f] = (float)(color.a = (unsigned char)(temp_v9 * 255.0f));
    }
    else {
      *(float *)((u8 *)(u32)piVar1 + 0x7c) = (float)(color.a = 0xff);
    }
    if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\x01') {
      mdlSetColor(*(void **)(piVar1[3] + 0x50),&color);
    }
    for (temp_v0 = **(int **)(*(int *)(piVar1[3] + 0x50) + 0x2cc); temp_v0 != 0;
        temp_v0 = *(int *)(temp_v0 + 0x10)) {
      if (*(void **)(temp_v0 + 8) != (void *)0x0) {
        mdlEffectGetPackedColor(*(void **)(temp_v0 + 8),(int *)&color);
        temp_v8 = ((float *)piVar1)[0x1f];
        color.a = (unsigned char)temp_v8;
        mdlEffectSetPackedColor(*(void **)(temp_v0 + 8),(int *)&color);
      }
    }
    switch(*piVar1) {
    case 0:
      temp_v0 = (int)func_003e0f80();
      piVar1[4] = temp_v0;
      mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,0,0,1);
      piVar1[5] = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(piVar1[3] + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(piVar1[3] + 0x1c8) * 0x40;
      temp_v0 = piVar1[3];
      *(FldAIVec3 *)&((float *)piVar1)[9] = *(FldAIVec3 *)(temp_v0 + 0x19c);
      temp_v0 = piVar1[3];
      *(FldAIVec3 *)&((float *)piVar1)[6] = *(FldAIVec3 *)(temp_v0 + 0x19c);
      temp_v0 = piVar1[3];
      *(FldAIVec3 *)&((float *)piVar1)[0xf] = *(FldAIVec3 *)(temp_v0 + 0x19c);
      temp_v0 = piVar1[3];
      *(FldAIVec3 *)&((float *)piVar1)[0xc] = *(FldAIVec3 *)(temp_v0 + 0x19c);
      temp_v0 = RpRandom();
      piVar1[0x17] = (int)((unsigned int)temp_v0 % 3) + 1;
      ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
      ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x18);
      pbVar7 = (unsigned char *)KDraw_CreateAxesTask(param_1,D_00794420);
      piVar1[0x26] = (int)pbVar7;
      FldRc_SetAxesPosition(pbVar7,(u8 *)&((FldAINpc *)piVar1[3])->origin);
      FldRc_SetAxesColor((unsigned char *)piVar1[0x26],(unsigned char *)D_005F1CE0);
      FldRc_SetAxesTargeted((unsigned char *)piVar1[0x26],0);
      *piVar1 = *piVar1 + 1;
      break;
    case 1:
      temp_v3 = FldAI_AdvanceBoundsSample((u8 *)piVar1);
      if (temp_v3 == 0) {
        temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
        aiPos = *(FldAIVec3 *)(temp_v0 + 0x30);
        if (*(int *)(piVar1[3] + 0x73c) != 0) {
          FldRc_SetAxesTargeted((unsigned char *)piVar1[0x26],1);
          FldRc_SetAxesPosition((unsigned char *)piVar1[0x26],(unsigned char *)(piVar1 + 0x14));
          FldRc_SetAxesColor((unsigned char *)piVar1[0x26],(unsigned char *)(D_005F1CE0 + piVar1[0x12] * 4));
        }
        else {
          FldRc_SetAxesTargeted((unsigned char *)piVar1[0x26],0);
        }
        temp_v0 = (unsigned int)RpRandom() % 100;
        temp_v3 = 0;
        if (piVar1[2] == 0) {
          if ((unsigned int)temp_v0 < 5) {
            temp_v3 = 1;
          }
        }
        else if ((piVar1[2] == 1) && ((unsigned int)temp_v0 < 0x1e)) {
          temp_v3 = 1;
        }
        if (temp_v3 == 1) {
          temp_v2 = RpRandom();
          if ((temp_v2 & 1) != 0) {
            piVar1[0x1d] = 0x3f800000;
          }
          else {
            piVar1[0x1d] = -0x40800000;
          }
          temp_v0 = RpRandom();
          piVar1[0x23] = (int)((unsigned int)temp_v0 % 0x1e) + 0x1e;
          *piVar1 = 3;
        }
        else if (temp_v3 == 2) {
          piVar1[0x23] = *(int *)(piVar1[5] + 0x2c);
          *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) | 2;
          temp_v8 = ((float *)piVar1)[0x1f];
          temp_v7 = (unsigned int)temp_v8;
          temp_v0 = KMisc_CreateRmdFade((int)param_1,*(int *)(piVar1[3] + 0x50),temp_v7,0,10);
          piVar1[0x22] = temp_v0;
          *piVar1 = 4;
        }
        else {
          {
          int cur = piVar1[0x12];
          temp_v7 = cur != 0 ^ 1;
          temp_v5 = 0;
          if ((!(aiPos.x < ((float *)fldFollowerStorageOffset(temp_v7 * 24, (u8 *)piVar1))[9]) &&
               (aiPos.x <= ((float *)fldFollowerStorageOffset(temp_v7 * 24, (u8 *)piVar1))[6])) &&
              (!(aiPos.z < ((float *)fldFollowerStorageOffset(temp_v7 * 24, (u8 *)piVar1))[0xb])) &&
             (aiPos.z <= ((float *)fldFollowerStorageOffset(temp_v7 * 24, (u8 *)piVar1))[8])) {
            temp_v5 = 1;
          }
          if (temp_v5 == 1) {
            piVar1[0x12] = !cur;
          }
          }
          temp_v0 = RpRandom();
          temp_v8 = fGpffff8308 + (float)((unsigned int)temp_v0 % 0x50) / 100.0f;
          temp_v1 = RpRandom();
          temp_v10 = fGpffff8308 + (float)((unsigned int)temp_v1 % 0x50) / 100.0f;
          patrolBounds = (const FldAIPatrolBounds *)((float *)piVar1 + piVar1[0x12] * 6 + 6);
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
            pick.x = temp_v8 * (bounds->max.x - bounds->min.x) + bounds->min.x + 0.0f;
            pick.z = temp_v10 * (bounds->max.z - bounds->min.z) + bounds->min.z + 0.0f;
            picked = pick;
            *(FldAIVec3 *)&((float *)piVar1)[0x14] = picked;
          }
          if (piVar1[0x17] < 1) {
            temp_v7 = piVar1[0x19] != 0 ^ 1;
            piVar1[0x19] = temp_v7;
            if (temp_v7 != 0) {
              ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x1c);
            }
            else {
              ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x18);
            }
            piVar1[0x18] = 0xf;
            temp_v0 = RpRandom();
            piVar1[0x17] = (int)((unsigned int)temp_v0 % 3) + 1;
          }
          else {
            piVar1[0x17] = piVar1[0x17] - 1;
          }
          piVar1[0x1c] = 0;
          *piVar1 = 2;
        }
      }
      break;
    case 2:
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state2Forward = *(FldAIVec3 *)(temp_v0 + 0x20);
      RwV3dNormalize(&state2Forward,&state2Forward);
      pfVar8 = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state2Right = *(FldAIVec3 *)pfVar8;
      RwV3dNormalize(&state2Right,&state2Right);
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      aiV60 = *(FldAIVec3 *)(temp_v0 + 0x30);
      aiV60.y = 0.0f;
      state2Delta.x = ((float *)piVar1)[0x14] - aiV60.x;
      state2Delta.y = ((float *)piVar1)[0x15] - aiV60.y;
      state2Delta.z = ((float *)piVar1)[0x16] - aiV60.z;
      temp_v8 = RwV3dNormalize(&state2Delta,&state2Delta);
      temp_v9 = *(float *)((u8 *)(u32)piVar1 + 0x68);
      temp_v9 = fldAIScale(iGpffff830c, temp_v9);
      if (!(temp_v8 <= temp_v9)) {
        temp_v8 = temp_v9;
      }
      else {
        *piVar1 = 1;
      }
      temp_v9 = state2Delta.x * state2Forward.x + state2Delta.y * state2Forward.y + state2Delta.z * state2Forward.z;
      if (temp_v9 < 1.0f) {
        temp_v11 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v9 = 1.0f - temp_v9;
        if (temp_v9 < temp_v11 / 180.0f) {
          temp_v11 = temp_v9 * 180.0f;
        }
        if (state2Delta.x * state2Right.x + state2Delta.y * state2Right.y + state2Delta.z * state2Right.z < 0.0f) {
          temp_v11 = temp_v11 * -1.0f;
        }
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v11);
        temp_v11 = fldAIAccumulateTurn(&((float *)piVar1)[0x1c], temp_v11);
        if ((!(temp_v11 <= 360.0f)) || (temp_v11 < -360.0f)) {
          *piVar1 = 1;
        }
      }
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (0 < piVar1[0x18]) {
        if (piVar1[0x19] != 0) {
          ((float *)piVar1)[0x1a] = (((float *)piVar1)[0x1a] +
                              (*(float *)(piVar1[5] + 0x1c) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        }
        else {
          ((float *)piVar1)[0x1a] = (((float *)piVar1)[0x1a] -
                              (*(float *)(piVar1[5] + 0x1c) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        }
        piVar1[0x18] = piVar1[0x18] - 1;
      }
else {
        ((float *)piVar1)[0x1a] = ((float *)piVar1)[0x1b];
      }
      temp_v0 = FldAI_ChaserCanSeeTarget((unsigned char *)piVar1[3]);
      if (temp_v0 == 1) {
        temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
        *(FldAIVec3 *)vec70 = *(FldAIVec3 *)(temp_v0 + 0x30);
        vec70[1] = vec70[1] +
                    ((float (*)[4])D_005F1CC0)[*(unsigned char *)(piVar1[3] + 0x1ca)][*(unsigned char *)(piVar1[3] + 0x1cb)];
        pbVar7 = (unsigned char *)FldStepFileTask(1);
        FldRc_RequestPositionSlot(pbVar7,&vec70[0]);
        sdkSndStartStream(1,0xb,3,5);
        piVar1[0x23] = *(int *)(piVar1[5] + 0x30);
        *piVar1 = 6;
      }
      break;
    case 3:
      if (piVar1[0x23] >= 0) {
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510,
                      *(float *)(piVar1[5] + 0x18) * 10.0f * ((float *)piVar1)[0x1d]);
        temp_v0 = FldAI_ChaserCanSeeTarget((unsigned char *)piVar1[3]);
        if (temp_v0 == 1) {
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          *(FldAIVec3 *)vec80 = *(FldAIVec3 *)(temp_v0 + 0x30);
          vec80[1] = vec80[1] +
                      ((float (*)[4])D_005F1CC0)[*(unsigned char *)(piVar1[3] + 0x1ca)][*(unsigned char *)(piVar1[3] + 0x1cb)];
          pbVar7 = (unsigned char *)FldStepFileTask(1);
          FldRc_RequestPositionSlot(pbVar7,&vec80[0]);
          sdkSndStartStream(1,0xb,3,5);
          piVar1[0x23] = *(int *)(piVar1[5] + 0x30);
          *piVar1 = 6;
        }
        else {
          piVar1[0x23] = piVar1[0x23] - 1;
        }
      }
      else {
        *piVar1 = 1;
      }
      break;
    case 4:
      if ((unsigned char *)piVar1[0x22] != (unsigned char *)0x0) {
        temp_v0 = KDraw_IsEffectDone((unsigned char *)piVar1[0x22]);
        if (temp_v0 == 0) {
          break;
        }
        kwlnTaskDestroyWithHierarchy((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
      }
      if (piVar1[0x23] >= 0) {
        piVar1[0x23] = piVar1[0x23] - 1;
      }
      else {
        temp_v8 = ((float *)piVar1)[0x1f];
        temp_v7 = (unsigned int)temp_v8;
        temp_v0 = KMisc_CreateRmdFade((int)param_1,*(int *)(piVar1[3] + 0x50),0,temp_v7,10);
        piVar1[0x22] = temp_v0;
        *piVar1 = *piVar1 + 1;
      }
      break;
    case 5:
      temp_v0 = KDraw_IsEffectDone((unsigned char *)piVar1[0x22]);
      if (temp_v0 != 0) {
        kwlnTaskDestroyWithHierarchy((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffd;
        *piVar1 = 1;
      }
      break;
    case 6:
      if (piVar1[0x23] >= 0) {
        piVar1[0x23] = piVar1[0x23] - 1;
      }
      else {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) | 4;
        mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,1,8,1);
        temp_v0 = RpRandom();
        temp_v7 = (unsigned int)temp_v0 % 100;
        temp_v3 = 0;
        if (piVar1[2] == 0) {
          if (temp_v7 < 0x28) {
            temp_v3 = 2;
          }
          else if (temp_v7 < 0x50) {
            temp_v3 = 3;
          }
        }
        else if ((piVar1[2] == 1) && (temp_v7 < 0x14)) {
          temp_v3 = 2;
        }
        if (temp_v3 == 0) {
          *piVar1 = 7;
          ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x20);
          piVar1[0x18] = 0xf;
          piVar1[0x23] = 0xd2;
        }
        else if (temp_v3 == 2) {
          piVar1[0x1c] = 0;
          piVar1[0x1e] = 0;
          ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x28);
          piVar1[0x18] = 0xf;
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          aiVB0 = *(FldAIVec3 *)(temp_v0 + 0x30);
          aiVB0.y = 0.0f;
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state6Direction.x = *(float *)(temp_v0 + 0x30) - aiVB0.x;
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state6Direction.y = *(float *)(temp_v0 + 0x34) - aiVB0.y;
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state6Direction.z = *(float *)(temp_v0 + 0x38) - aiVB0.z;
          RwV3dNormalize(&state6Direction,&state6Direction);
          state6Direction.x = state6Direction.x * 200.0f;
          state6Direction.y = state6Direction.y * 200.0f;
          state6Direction.z = state6Direction.z * 200.0f;
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          *(float *)((u8 *)(u32)piVar1 + 0x50) = (state6Direction.x + *(float *)(temp_v0 + 0x30));
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          *(float *)((u8 *)(u32)piVar1 + 0x54) = (state6Direction.y + *(float *)(temp_v0 + 0x34));
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          *(float *)((u8 *)(u32)piVar1 + 0x58) = (state6Direction.z + *(float *)(temp_v0 + 0x38));
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          aiPos6 = *(FldAIVec3 *)(temp_v0 + 0x30);
          aiPos6.y = 0.0f;
          state6Delta.x = ((float *)piVar1)[0x14] - aiPos6.x;
          state6Delta.y = ((float *)piVar1)[0x15] - aiPos6.y;
          state6Delta.z = ((float *)piVar1)[0x16] - aiPos6.z;
          temp_v8 = RwV3dNormalize(&state6Delta,&state6Delta);
          piVar1[0x25] = (int)(temp_v8 / (iGpffff830c * *(float *)(piVar1[5] + 0x28)));
          *piVar1 = 9;
        }
        else if (temp_v3 == 3) {
          ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x28);
          piVar1[0x18] = 0xf;
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          *(FldAIVec3 *)&((float *)piVar1)[0x14] = *(FldAIVec3 *)(temp_v0 + 0x30);
          *piVar1 = 10;
        }
      }
      break;
    case 7:
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state7Forward = *(FldAIVec3 *)(temp_v0 + 0x20);
      RwV3dNormalize(&state7Forward,&state7Forward);
      pfVar8 = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state7Right = *(FldAIVec3 *)pfVar8;
      RwV3dNormalize(&state7Right,&state7Right);
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      aiVF0 = *(FldAIVec3 *)(temp_v0 + 0x30);
      aiVF0.y = 0.0f;
      temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state7Delta.x = *(float *)(temp_v0 + 0x30) - aiVF0.x;
      temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state7Delta.y = *(float *)(temp_v0 + 0x34) - aiVF0.y;
      temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state7Delta.z = *(float *)(temp_v0 + 0x38) - aiVF0.z;
      temp_v8 = RwV3dNormalize(&state7Delta,&state7Delta);
      temp_v9 = iGpffff830c * ((float *)piVar1)[0x1a];
      if (!(temp_v8 <= temp_v9)) {
        temp_v8 = temp_v9;
      }
      temp_v9 = state7Delta.x * state7Forward.x + state7Delta.y * state7Forward.y + state7Delta.z * state7Forward.z;
      if (temp_v9 < 1.0f) {
        temp_v11 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v9 = 1.0f - temp_v9;
        if (temp_v9 < temp_v11 / 180.0f) {
          temp_v11 = temp_v9 * 180.0f;
        }
        if (state7Delta.x * state7Right.x + state7Delta.y * state7Right.y + state7Delta.z * state7Right.z < 0.0f) {
          temp_v11 = temp_v11 * -1.0f;
        }
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v11);
      }
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (0 < piVar1[0x18]) {
        *(float *)((u8 *)(u32)piVar1 + 0x68) = (*(float *)((u8 *)(u32)piVar1 + 0x68) +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
else {
        *(float *)((u8 *)(u32)piVar1 + 0x68) = ((float *)piVar1)[0x1b];
      }
      if ((D_00764348 == 0) && (temp_v0 = piVar1[3], iGpffffb310 == 0)) {
        temp_v6 = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(temp_v0 + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(temp_v6 + 8), *(float *)(temp_v6 + 4)) == 1) {
          iGpffffb310 = temp_v0;
        }
      }
      if ((piVar1[0x23] < 1) && (temp_v0 = FldAI_ChaserCanSeeTarget((unsigned char *)piVar1[3]), temp_v0 == 0)) {
        piVar1[0x23] = *(int *)(piVar1[5] + 0x34);
        *piVar1 = 0xb;
        mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      else {
        if (0 < piVar1[0x23]) {
          piVar1[0x23] = piVar1[0x23] - 1;
        }
        temp_v0 = piVar1[0x24];
        if (temp_v0 < 1) {
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          state7Delta.x = *(float *)((u8 *)(u32)(temp_v0) + 0x30) - *(float *)(piVar1[3] + 0x19c);
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          state7Delta.y = *(float *)((u8 *)(u32)(temp_v0) + 0x34) - *(float *)(piVar1[3] + 0x1a0);
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          state7Delta.z = *(float *)((u8 *)(u32)(temp_v0) + 0x38) - *(float *)(piVar1[3] + 0x1a4);
          temp_v8 = RwV3dNormalize(&state7Delta,&state7Delta);
          if (temp_v8 >= *(float *)piVar1[5]) {
            piVar1[0x23] = *(int *)(piVar1[5] + 0x34);
            mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
            *piVar1 = 0xb;
          }
        }
        else if (0 < temp_v0) {
          piVar1[0x24] = temp_v0 - 1;
        }
      }
      break;
    case 8:
      temp_v8 = FldEvent_GetMoveStep();
      if (temp_v8 == 0.0f) {
        temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        aiPos2 = *(FldAIVec3 *)(temp_v0 + 0x30);
      }
      else {
        f32 facingZ;
        f32 playerFacingZ;
        f32 facingX;
        f32 playerFacingX;
        temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
        facingZ = *(float *)(temp_v0 + 0x28);
        temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        playerFacingZ = *(float *)(temp_v0 + 0x28);
        temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
        facingX = *(float *)(temp_v0 + 0x20);
        temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        playerFacingX = *(float *)(temp_v0 + 0x20);
        temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
        temp_v1 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        if (playerFacingX * facingX + *(float *)(temp_v1 + 0x24) * *(float *)(temp_v0 + 0x24) + playerFacingZ * facingZ > fGpffff8310)
        {
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          aiPos2 = *(FldAIVec3 *)(temp_v0 + 0x30);
          *piVar1 = 7;
        }
        else {
          temp_v8 = FldEvent_GetMoveStep();
          temp_v8 = temp_v8 - ((float *)piVar1)[0x1a];
          if (temp_v8 < 0.0f) {
            temp_v8 = temp_v8 * -1.0f;
          }
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          aiV130 = *(FldAIVec3 *)(temp_v0 + 0x30);
          aiV130.y = 0.0f;
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Delta.x = *(float *)(temp_v0 + 0x30) - aiV130.x;
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Delta.y = *(float *)(temp_v0 + 0x34) - aiV130.y;
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Delta.z = *(float *)(temp_v0 + 0x38) - aiV130.z;
          temp_v9 = RwV3dNormalize(&state8Delta,&state8Delta);
          temp_v9 = temp_v9 / temp_v8;
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Forward = *(FldAIVec3 *)(temp_v0 + 0x20);
          state8Forward.x = state8Forward.x * (temp_v9 * FldEvent_GetMoveStep());
          state8Forward.y = state8Forward.y * (temp_v9 * FldEvent_GetMoveStep());
          state8Forward.z = state8Forward.z * (temp_v9 * FldEvent_GetMoveStep());
          temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          aiPos2 = *(FldAIVec3 *)(temp_v0 + 0x30);
          aiPos2.x = aiPos2.x + state8Forward.x;
          aiPos2.y = aiPos2.y + state8Forward.y;
          aiPos2.z = aiPos2.z + state8Forward.z;
        }
      }
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state8Forward = *(FldAIVec3 *)(temp_v0 + 0x20);
      RwV3dNormalize(&state8Forward,&state8Forward);
      pfVar8 = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state8Right = *(FldAIVec3 *)pfVar8;
      RwV3dNormalize(&state8Right,&state8Right);
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      aiPos8 = *(FldAIVec3 *)(temp_v0 + 0x30);
      aiPos8.y = 0.0f;
      state8Delta.x = aiPos2.x - aiPos8.x;
      state8Delta.y = aiPos2.y - aiPos8.y;
      state8Delta.z = aiPos2.z - aiPos8.z;
      temp_v8 = RwV3dNormalize(&state8Delta,&state8Delta);
      temp_v9 = iGpffff830c * ((float *)piVar1)[0x1a];
      if (!(temp_v8 <= temp_v9)) {
        temp_v8 = temp_v9;
      }
      temp_v9 = state8Delta.x * state8Forward.x + state8Delta.y * state8Forward.y + state8Delta.z * state8Forward.z;
      if (temp_v9 < 1.0f) {
        temp_v11 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v9 = 1.0f - temp_v9;
        if (temp_v9 < temp_v11 / 180.0f) {
          temp_v11 = temp_v9 * 180.0f;
        }
        if (state8Delta.x * state8Right.x + state8Delta.y * state8Right.y + state8Delta.z * state8Right.z < 0.0f) {
          temp_v11 = temp_v11 * -1.0f;
        }
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v11);
      }
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (0 < piVar1[0x18]) {
        *(float *)((u8 *)(u32)piVar1 + 0x68) = (*(float *)((u8 *)(u32)piVar1 + 0x68) +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
else {
        *(float *)((u8 *)(u32)piVar1 + 0x68) = ((float *)piVar1)[0x1b];
      }
      if ((D_00764348 == 0) && (temp_v0 = piVar1[3], iGpffffb310 == 0)) {
        temp_v6 = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(temp_v0 + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(temp_v6 + 8), *(float *)(temp_v6 + 4)) == 1) {
          iGpffffb310 = temp_v0;
        }
      }
      if ((piVar1[0x23] < 1) && (temp_v0 = FldAI_ChaserCanSeeTarget((unsigned char *)piVar1[3]), temp_v0 == 0)) {
        piVar1[0x23] = *(int *)(piVar1[5] + 0x34);
        *piVar1 = 0xb;
        mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      else {
        if (0 < piVar1[0x23]) {
          piVar1[0x23] = piVar1[0x23] - 1;
        }
        temp_v0 = piVar1[0x24];
        if (temp_v0 < 1) {
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          state8Delta.x = *(float *)((u8 *)(u32)(temp_v0) + 0x30) - *(float *)(piVar1[3] + 0x19c);
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          state8Delta.y = *(float *)((u8 *)(u32)(temp_v0) + 0x34) - *(float *)(piVar1[3] + 0x1a0);
          temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
          state8Delta.z = *(float *)((u8 *)(u32)(temp_v0) + 0x38) - *(float *)(piVar1[3] + 0x1a4);
          temp_v8 = RwV3dNormalize(&state8Delta,&state8Delta);
          if (temp_v8 >= *(float *)piVar1[5]) {
            piVar1[0x23] = *(int *)(piVar1[5] + 0x34);
            *piVar1 = 0xb;
            mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
          }
        }
        else if (0 < temp_v0) {
          piVar1[0x24] = temp_v0 - 1;
        }
      }
      break;
    case 9:
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state9Forward = *(FldAIVec3 *)(temp_v0 + 0x20);
      RwV3dNormalize(&state9Forward,&state9Forward);
      pfVar8 = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state9Right = *(FldAIVec3 *)pfVar8;
      RwV3dNormalize(&state9Right,&state9Right);
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      aiV190 = *(FldAIVec3 *)(temp_v0 + 0x30);
      aiV190.y = 0.0f;
      temp_v11 = sinf(((f32 *)piVar1)[0x1e]);
      *(float *)((u8 *)(u32)piVar1 + 0x78) = (*(float *)((u8 *)(u32)piVar1 + 0x78) + fGpffff8218);
      state9Direction.x = *(float *)((u8 *)(u32)piVar1 + 0x50) - aiV190.x;
      temp_v8 = aiV190.y;
      state9Direction.y = *(float *)((u8 *)(u32)piVar1 + 0x54) - temp_v8;
      temp_v9 = aiV190.z;
      state9Direction.z = *(float *)((u8 *)(u32)piVar1 + 0x58) - temp_v9;
      RwV3dNormalize(&state9Direction,&state9Direction);
      state9Direction.x = state9Direction.x * 200.0f;
      state9Direction.y = state9Direction.y * 200.0f;
      state9Direction.z = state9Direction.z * 200.0f;
      state9Direction.x = state9Direction.x + ((float *)piVar1)[0x14];
      state9Direction.y = state9Direction.y + ((float *)piVar1)[0x15];
      state9Direction.z = state9Direction.z + ((float *)piVar1)[0x16];
      temp_v11 = fldAIScale(400.0f, temp_v11);
      state9Delta.x = state9Right.x * temp_v11;
      state9Delta.y = state9Right.y * temp_v11;
      state9Delta.z = state9Right.z * temp_v11;
      state9Delta.x = state9Delta.x + state9Direction.x;
      state9Delta.y = state9Delta.y + state9Direction.y;
      state9Delta.z = state9Delta.z + state9Direction.z;
      state9Delta.x = state9Delta.x - aiV190.x;
      state9Delta.y = state9Delta.y - temp_v8;
      state9Delta.z = state9Delta.z - temp_v9;
      temp_v8 = RwV3dNormalize(&state9Delta,&state9Delta);
      temp_v9 = *(float *)&piVar1[0x1a];
      temp_v9 = fldAIScale(iGpffff830c, temp_v9);
      if (!(temp_v8 <= temp_v9)) {
        temp_v8 = temp_v9;
      }
      if (piVar1[0x25] < 1) {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
        mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      else {
        piVar1[0x25] = piVar1[0x25] - 1;
      }
      temp_v9 = state9Delta.x * state9Forward.x + state9Delta.y * state9Forward.y + state9Delta.z * state9Forward.z;
      temp_v11 = 5.0f * (10.0f * *(float *)((u8 *)(u32)piVar1 + 0x68));
      temp_v9 = 1.0f - temp_v9;
      if (temp_v9 < temp_v11 / 180.0f) {
        temp_v11 = temp_v9 * 180.0f;
      }
      if (state9Delta.x * state9Right.x + state9Delta.y * state9Right.y + state9Delta.z * state9Right.z < 0.0f) {
        temp_v11 = temp_v11 * -1.0f;
      }
      FldFrameTask_Rotate(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v11);
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (0 < piVar1[0x18]) {
        ((float *)piVar1)[0x1a] = (((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
else {
        ((float *)piVar1)[0x1a] = ((float *)piVar1)[0x1b];
      }
      if ((D_00764348 == 0) && (temp_v0 = piVar1[3], iGpffffb310 == 0)) {
        temp_v6 = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(temp_v0 + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(temp_v6 + 8), *(float *)(temp_v6 + 4)) == 1) {
          iGpffffb310 = temp_v0;
        }
      }
      break;
    case 10:
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state10Forward = *(FldAIVec3 *)(temp_v0 + 0x20);
      RwV3dNormalize(&state10Forward,&state10Forward);
      pfVar8 = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state10Right = *(FldAIVec3 *)pfVar8;
      RwV3dNormalize(&state10Right,&state10Right);
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      aiV1D0 = *(FldAIVec3 *)(temp_v0 + 0x30);
      aiV1D0.y = 0.0f;
      state10Delta.x = ((float *)piVar1)[0x14] - aiV1D0.x;
      state10Delta.y = ((float *)piVar1)[0x15] - aiV1D0.y;
      state10Delta.z = ((float *)piVar1)[0x16] - aiV1D0.z;
      temp_v8 = RwV3dNormalize(&state10Delta,&state10Delta);
      temp_v9 = *(float *)&piVar1[0x1a];
      temp_v9 = fldAIScale(iGpffff830c, temp_v9);
      if (!(temp_v8 <= temp_v9)) {
        temp_v8 = temp_v9;
      }
      else {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
        mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      temp_v11 = state10Delta.x * state10Forward.x + state10Delta.y * state10Forward.y + state10Delta.z * state10Forward.z;
      temp_v9 = 10.0f * *(float *)((u8 *)(u32)piVar1 + 0x68);
      temp_v11 = 1.0f - temp_v11;
      if (temp_v11 < temp_v9 / 180.0f) {
        temp_v9 = temp_v11 * 180.0f;
      }
      if (state10Delta.x * state10Right.x + state10Delta.y * state10Right.y + state10Delta.z * state10Right.z < 0.0f) {
        temp_v9 = temp_v9 * -1.0f;
      }
      FldFrameTask_Rotate(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v9);
      temp_v9 = fldAIAccumulateTurn(&((float *)piVar1)[0x1c], temp_v9);
      if ((!(temp_v9 <= 360.0f)) || (temp_v9 < -360.0f)) {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
      }
      FldFrameTask_StartMove(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (0 < piVar1[0x18]) {
        ((float *)piVar1)[0x1a] = (((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
else {
        ((float *)piVar1)[0x1a] = ((float *)piVar1)[0x1b];
      }
      if ((D_00764348 == 0) && (temp_v0 = piVar1[3], iGpffffb310 == 0)) {
        temp_v6 = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(temp_v0 + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(temp_v6 + 8), *(float *)(temp_v6 + 4)) == 1) {
          iGpffffb310 = temp_v0;
        }
      }
      break;
    case 0xb:
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state11Forward = *(FldAIVec3 *)(temp_v0 + 0x20);
      RwV3dNormalize(&state11Forward,&state11Forward);
      pfVar8 = (float *)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      state11Right = *(FldAIVec3 *)pfVar8;
      RwV3dNormalize(&state11Right,&state11Right);
      temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
      aiV210 = *(FldAIVec3 *)(temp_v0 + 0x30);
      aiV210.y = 0.0f;
      temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state11Delta.x = *(float *)(temp_v0 + 0x30) - aiV210.x;
      temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state11Delta.y = *(float *)(temp_v0 + 0x34) - aiV210.y;
      temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state11Delta.z = *(float *)(temp_v0 + 0x38) - aiV210.z;
      RwV3dNormalize(&state11Delta,&state11Delta);
      temp_v8 = state11Delta.x * state11Forward.x + state11Delta.y * state11Forward.y + state11Delta.z * state11Forward.z;
      if (temp_v8 < 1.0f) {
        temp_v9 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v8 = 1.0f - temp_v8;
        if (temp_v8 < temp_v9 / 180.0f) {
          temp_v9 = temp_v8 * 180.0f;
        }
        if (state11Delta.x * state11Right.x + state11Delta.y * state11Right.y + state11Delta.z * state11Right.z < 0.0f) {
          temp_v9 = temp_v9 * -1.0f;
        }
        FldFrameTask_Rotate(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v9);
      }
      temp_v0 = FldAI_ChaserCanSeeTarget((unsigned char *)piVar1[3]);
      if (temp_v0 == 1) {
        temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        state11Delta.x = *(float *)((u8 *)(u32)(temp_v0) + 0x30) - *(float *)(piVar1[3] + 0x19c);
        temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        state11Delta.y = *(float *)((u8 *)(u32)(temp_v0) + 0x34) - *(float *)(piVar1[3] + 0x1a0);
        temp_v0 = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        state11Delta.z = *(float *)((u8 *)(u32)(temp_v0) + 0x38) - *(float *)(piVar1[3] + 0x1a4);
        temp_v8 = RwV3dNormalize(&state11Delta,&state11Delta);
        if (temp_v8 < *(float *)piVar1[5]) {
          ((float *)piVar1)[0x1a] = ((float *)piVar1[5])[6];
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x20);
          piVar1[0x18] = 1;
          piVar1[0x23] = 0xd2;
          piVar1[0x24] = 0x3c;
          *piVar1 = 7;
          mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,1,8,1);
          break;
        }
      }
      if ((D_00764348 == 0) && (temp_v0 = piVar1[3], iGpffffb310 == 0)) {
        temp_v6 = (u32)iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 + (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)*(unsigned int *)(temp_v0 + 0x50)),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         *(float *)(temp_v6 + 8), *(float *)(temp_v6 + 4)) == 1) {
          iGpffffb310 = temp_v0;
        }
      }
      if (piVar1[0x23] >= 0) {
        piVar1[0x23] = piVar1[0x23] - 1;
      }
      else {
        temp_v0 = (int)mdlGetMatrix((u8 *)*(unsigned int *)(piVar1[3] + 0x50));
        aiHere = *(FldAIVec3 *)(temp_v0 + 0x30);
        temp_v5 = 0;
        if ((!(aiHere.x < ((float *)piVar1)[9]) && (aiHere.x <= ((float *)piVar1)[6])) &&
            !(aiHere.z < ((float *)piVar1)[0xb]) && (aiHere.z <= ((float *)piVar1)[8])) {
          temp_v5 = 1;
        }
        if (temp_v5 == 0) {
          temp_v5 = 0;
          if ((!(aiHere.x < ((float *)piVar1)[0xf]) && (aiHere.x <= ((float *)piVar1)[0xc])) &&
             !(aiHere.z < ((float *)piVar1)[0x11]) && (aiHere.z <= ((float *)piVar1)[0xe])) {
            temp_v5 = 1;
          }
          if (temp_v5 == 0) {
            *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) | 2;
            if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\x01') {
              temp_v0 = *(int *)(piVar1[3] + 0x50);
              *(unsigned int *)(temp_v0 + 0xd8) = *(unsigned int *)(temp_v0 + 0xd8) & 0xffffff7f;
            }
            mdlSetAlphaBlend(*(unsigned char **)(piVar1[3] + 0x50));
            temp_v0 = piVar1[3];
            if (*(unsigned char *)(temp_v0 + 0x1ca) == '\0') {
              temp_v0 = KMisc_CreateRmdFade((int)param_1,*(int *)(temp_v0 + 0x50),0xff,0,10);
              piVar1[0x22] = temp_v0;
            }
            else if (*(unsigned char *)(temp_v0 + 0x1ca) == '\x01') {
              temp_v8 = ((float *)piVar1)[0x1f];
              temp_v7 = (unsigned int)temp_v8;
              temp_v0 = KMisc_CreateRmdFade((int)param_1,*(int *)(temp_v0 + 0x50),temp_v7,0,10);
              piVar1[0x22] = temp_v0;
            }
            ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
            *piVar1 = 0xc;
            mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
            break;
          }
        }
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
        mdlDispatchAnimIfPresent(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      break;
    case 0xc:
      temp_v0 = KDraw_IsEffectDone((unsigned char *)piVar1[0x22]);
      if (temp_v0 != 0) {
        kwlnTaskDestroyWithHierarchy((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
        FldFrameTask_SetPosition(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),(u8 *)&((FldAINpc *)piVar1[3])->origin);
        temp_v0 = piVar1[3];
        if (*(unsigned char *)(temp_v0 + 0x1ca) == '\0') {
          temp_v0 = KMisc_CreateRmdFade((int)param_1,*(int *)(temp_v0 + 0x50),0,0xff,10);
          piVar1[0x22] = temp_v0;
        }
        else if (*(unsigned char *)(temp_v0 + 0x1ca) == '\x01') {
          temp_v8 = ((float *)piVar1)[0x1f];
          temp_v7 = (unsigned int)temp_v8;
          temp_v0 = KMisc_CreateRmdFade((int)param_1,*(int *)(temp_v0 + 0x50),0,temp_v7,10);
          piVar1[0x22] = temp_v0;
        }
        *piVar1 = 0xd;
      }
      break;
    case 0xd:
      temp_v0 = KDraw_IsEffectDone((unsigned char *)piVar1[0x22]);
      if (temp_v0 != 0) {
        if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\x01') {
          temp_v0 = *(int *)(piVar1[3] + 0x50);
          *(unsigned int *)(temp_v0 + 0xd8) = *(unsigned int *)(temp_v0 + 0xd8) | 0x80;
        }
        mdlClearAlphaBlend(*(unsigned char **)(piVar1[3] + 0x50));
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffff9;
        kwlnTaskDestroyWithHierarchy((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
        *piVar1 = 1;
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

// FUN_001821D0
void FldAI_PatrolDestroy(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x10);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_00182220
s32 FldAI_SpawnPatrol(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    u8 *work;

    chkmemAllocSiteTag(D_005F1B18, 0xA50);
    work = D_008873F4[0](1, 0xA0, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F1CF0), 0xF, 0, 0, FldAI_PatrolUpdate, FldAI_PatrolDestroy, (u8 *)(work));
    *(s32 *)(work + 0xC) = arg1;
    *(s32 *)(work + 0x4) = 1;
    *(s32 *)(work + 0x8) = arg2;
    *(f32 *)(work + 0x80) = *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
    *(f32 *)(work + 0x84) = iGpffffba6c;
    return ret;
}
