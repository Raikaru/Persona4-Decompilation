#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "Kosaka/k_fldFrame_internal.h"
extern u8 D_00756510[];
extern s32 func_0016fd00();
extern void func_003e0f40();
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1B18[];
extern u8 D_005F1B28[];
extern u8 D_005F1CF0[];
extern f32 iGpffffba6c;
extern void func_0044ea90(const void *file, s32 line);

extern u8 *func_00457120(void);
extern s32 func_0017d3c0(u8 *arg0);
extern s32 func_0017f490(u8 *arg0);
extern u8 *D_007EFA00[];
extern s32 iGpffffb25c;
extern u8 *iGpffffb2c8;
extern s32 K_FldEvent_IsPosWithinFov(u8 *arg0, u8 *arg1, f32 arg2);
extern s32 K_FldEvent_ArePosWithinDist(u8 *arg0, u8 *arg1, f32 arg2);
extern s32 func_0016b8a0(const RwV3d *line, RwV3d *hitPointDst);
extern f32 RwV3dLength(f32 *arg0);
extern u8 *mdlGetMatrix(u8 *arg0);

typedef RwV3d FldAIVec3;
typedef struct { f32 x, y, z, w; } FldAIVec4;
extern u8 D_005F1B40[];
extern u8 D_005F1B4C[];

extern s32 *func_00155280(void);

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
s32 func_0017d3c0(u8 *task)
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
    extern f32 func_0014c3d0(const struct RwMatrix *, const RwV3d *, f32, f32, f32);
    extern f32 func_00175db0(void);
    extern f32 func_0044b920(f32);
    extern s32 func_0014bbe0(s32, s32, s32, s32, s32);
    extern s32 func_0014bd90(u8 *);
    extern s32 func_001687d0(u8 *);
    extern s32 func_001687e0(u8 *);
    extern void func_00168750(u8 *, s32);
    extern void func_001687f0(u8 *, u8 *);
    extern void func_00168ae0(u8 *, u8 *);
    extern void func_00168cb0(u8 *, f32);
    extern void func_00168de0(u8 *, const void *, f32);
    extern s32 func_0016fd00(s32);
    extern s32 func_0016ffd0(s32);
    extern s32 func_0017e980(u8 *);
    extern u32 RpRandom(void);
    extern void *memset(void *, int, size_t);
    extern s32 func_00452080(KwlnTask *);
    extern void func_0046d730(const void *, s32);
    extern s16 func_00479c30(s32, s32);
    extern void mdlSetColor(void *, const void *);
    extern void func_0047a850(void *);
    extern void func_0047a870(void *);

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
            func_0046d730(D_005F1B18, 0x97);
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
        tileX = func_001687d0(*(u8 **)(D_007EFA00[1] + 0x220));
        tileZ = func_001687e0(*(u8 **)(D_007EFA00[1] + 0x220));
        {
            struct RwFrame *frame = *(struct RwFrame **)(func_00457120() + 4);
            func_001687f0(selfPosition.bytes,
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
        if (*(u8 **)(work + 0x6C) != NULL && func_0014bd90(*(u8 **)(work + 0x6C)) == 1) {
            func_0047a870(*(void **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164));
            func_00452080(*(KwlnTask **)(work + 0x6C));
            *(u8 **)(work + 0x6C) = NULL;
        }
        if (distance <= 110.0f + *(f32 *)(work + 0x64)) {
            if (*(u8 **)(work + 0x6C) != NULL) {
                func_0047a870(*(void **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164));
                func_00452080(*(KwlnTask **)(work + 0x6C));
                *(u8 **)(work + 0x6C) = NULL;
            }
            mdlSetColor(*(void **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164), &iGpffff9f58);
            *(s32 *)(work + 0x68) = 1;
        }
        if (*(s32 *)(work + 0x68) == 1 && !(distance <= 110.0f + *(f32 *)(work + 0x64))) {
            func_0047a850(*(void **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164));
            *(s32 *)(work + 0x6C) = func_0014bbe0((s32)task,
                *(s32 *)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x164), 0, 255, 10);
            *(s32 *)(work + 0x68) = 0;
        }
        if (!(func_00175db0() <= 0.0f))
            *(s32 *)(work + 0xC) = 1;
        if (*(s32 *)(work + 0xC) == 0) {
            currentAnimation = (s16)func_00479c30(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
            desiredAnimation = func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
            if (currentAnimation != desiredAnimation) {
                desiredAnimation = (s16)func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                func_00479940(*(u8 **)(*(u8 **)(work + 0x10) + 0x50), 0, (s16)desiredAnimation, 0, 1);
            }
            break;
        }
        {
            s32 rowOffset = tileZ * 0x100;
            s32 columnOffset = tileX * 0x10;
            if (*(u8 *)((u8 *)func_00155280() + rowOffset + columnOffset + 0x58) == 2 ||
                *(u8 *)((u8 *)func_00155280() + rowOffset + columnOffset + 0x58) == 9 ||
                *(u8 *)((u8 *)func_00155280() + rowOffset + columnOffset + 0x58) == 10 ||
                *(u8 *)((u8 *)func_00155280() + rowOffset + columnOffset + 0x58) == 11 ||
                *(u8 *)((u8 *)func_00155280() + rowOffset + columnOffset + 0x58) == 12 ||
                *(u8 *)((u8 *)func_00155280() + rowOffset + columnOffset + 0x58) == 13 ||
                *(u8 *)((u8 *)func_00155280() + rowOffset + columnOffset + 0x58) == 14) {
                *(s32 *)(work + 0x58) = 0;
                *(s32 *)(work + 0x5C) = 0;
                *(s32 *)(work + 0x4C) = -1;
                func_00168750(*(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220), 1);
                *(s32 *)(work + 0x18) = 1;
                if (*(s32 *)(work + 0x1C) != *(s32 *)(work + 0x18)) {
                    u32 random = RpRandom() & 1;
                    u8 *otherTask = *(u8 **)(*(u8 **)(work + 0x14) + 0x1B0);
                    if (otherTask != NULL) {
                        if (random != 0) {
                            action = func_0017e980(otherTask);
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
                            action = func_0017e980(otherTask);
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
                f32 candidate = func_0014c3d0(
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
        if (func_00175db0() <= 0.0f)
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
                    func_0046d730(D_005F1B18, 0x19F);
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
                    func_0046d730(D_005F1B18, 0x1B6);
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
            func_00168ae0(*(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220), matrix + 0x30);
            *(s32 *)(work + 0x4C) = -1;
            *(s32 *)(work + 0x58) = 0;
            *(s32 *)(work + 0x5C) = 0;
        goto movementComplete;
moveFollower:
        {
            active = 0;
            historyIndex = *(s32 *)(*(u8 **)(work + 0x10) + 0x710) - 1;
            if (turn != 0.0f && speed != 0.0f)
                func_00168de0(*(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220), D_00756510, turn);
            if (speed != 0.0f)
                func_00168cb0(*(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220), speed);
            if (historyIndex < 0) historyIndex = 63;
            entry = *(u8 **)(work + 0x10);
            if (*(fldFollowerStorageOffset(historyIndex, entry) + 0x1D0) != 0) {
                func_001687f0(historyPoint.bytes, *(u8 **)(*(u8 **)(entry + 0x54) + 0x220));
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
                    currentAnimation = (s16)func_00479c30(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
                    desiredAnimation = func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                    if (currentAnimation != desiredAnimation) {
                        desiredAnimation = (s16)func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                        func_00479940(*(u8 **)(*(u8 **)(work + 0x10) + 0x50), 0, (s16)desiredAnimation, 16, 1);
                    }
                    *(s32 *)(work + 0x60) = 0;
                }
            } else {
                currentAnimation = (s16)func_00479c30(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
                desiredAnimation = func_0016ffd0(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                if (currentAnimation != desiredAnimation) {
                    desiredAnimation = (s16)func_0016ffd0(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                    func_00479940(*(u8 **)(*(u8 **)(work + 0x10) + 0x50), 0, (s16)desiredAnimation, 8, 1);
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
void func_0017e840(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x50);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0017E890
s32 func_0017e890(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    u8 *work;

    func_0044ea90(D_005F1B18, 0x3D9);
    work = D_008873F4[0](1, 0x74, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005F1B28), 0xF, 0, 0, func_0017d3c0, func_0017e840, (u8 *)(work));
    *(s32 *)(work + 0x10) = arg1;
    *(s32 *)(work + 0x14) = arg2;
    *(s32 *)(work + 0x1C) = -1;
    *(f32 *)(work + 0x64) = *(f32 *)(func_00457120() + 0x80);
    return ret;
}

// FUN_0017E980
s32 func_0017e980(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x48);
}

// FUN_0017E990
void func_0017e990(u8 *arg0) {
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) = 1;
}

// FUN_0017E9B0
void func_0017e9b0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_00479940(*(u8 **)(*(u8 **)(p + 0x10) + 0x50), 0,
                  (s16)func_0016fd00(*(u16 *)(*(u8 **)(p + 0x10) + 0x728)), 0, 1);
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
s32 func_0017ea10(u8 *arg0)
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
    if (func_0016b8a0(ab, &out) == 1) {
        return 0;
    }
    temp_2 = (u8 *)ab;
    temp_2_2 = (u8 *)&out;
    out = ab[0];
    ab[0] = ab[1];
    ab[1] = out;
    if (func_0016b8a0((const RwV3d *)temp_2, (RwV3d *)temp_2_2) == 1) {
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
s32 func_0017ed40(u8 *work)
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
    u8 *sourceCell;
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
            sourceCell = ((u8 *)func_00155280()) + (cellZ * 0x100) + (cellX * 0x10);
            cell = *(FldAIVec4 *)(sourceCell + 0x54);
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
            u8 *cellB = ((u8 *)func_00155280()) + (endpointCellZ * 0x100) + (endpointCellX * 0x10);
            if (*(u8 *)(cellB + 0x54) == 1) {
                axis = 0;
                if (func_0016b8a0(line, &hit) == 1) {
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
/* measured 0017f490 (owner, romwright R1 + doubles-to-float + uStack_4 byte-cast + DAT data fix): fndiff obj 11680B vs window 11584B (+96B); fnalign retail 2896 vs object 2920 (+24, +0.83%, band 2809-2983, inside); edits 3363 (+9 reloc-only); GUARDED_SCORE 2631. Frame retail -0x2D0 vs object -0x100 (-464B). `#pragma opt_common_subs off` scoped to this function and closed after it (same file idiom as 0017d3c0, CSE off for per-call addresses). Residual is saved-reg colour, hoisted bases, and COP1 vs plain arithmetic; no helpers (all floats are f-suffixed, 003e0870 takes f32). */
/* measured 0017f490 (Xa17f490, 2026-09-20): baseline 3015 edits (+10 reloc-only), retail 2894/obj 2822 (-72, -2.5% inside) via measure_guarded+fnalign --candidate --quiet; deficit_scan swc1+133 lwc1+116 move+23 bc1t+16 sub.s+11 lbu+11 add.s+10 divu+7, runs 405@0x00181970/201@0x00180d70/111@0x00180768 (all branch-layout, not missing code; dispatch jtbl_00746D80 15 entries already layout order, untouched). Tried (all --candidate --quiet): char->uchar 9x 0x1ca 3015 (0, tie); case6 int->float stores 3015 (0); prologue distinct temp 3015 (0); 003e4180 Vec3*+casts 3015 (0); 003e40b0 Vec3B*+25 casts 3235 (+220, obj 2803, LOSS, old-style decl is correct); 003e4180 old-style 3009 (0). WIN unsigned % 8x (2x %3, 2x %100 outer-cast removed, 1x %0x1e, 2x %0x50 inner-unsigned, 1x temp_v7) 3015->3009 (-6, obj same). WIN case3 if(<0)->if(>=0) arm swap 3009->3004 (-5). WIN case4 same 3004->2998 (-6). WIN case6 same (69-line CUT/PUT) 2998->2992 (-6). HUGE WIN case11 same (47-line CUT/PUT; retail small-first layout lw 0x8c bltz->0x181dec at 0x00181dd0, bounds-check large second) 2992->2407 (-585, obj 2822 same, +12 reloc-only). Final 2407 (-608), retail 2894/obj 2822 (-72 inside), gate INSIDE (3 inside 0 outside), lint 0. */
/* 2026-10-03: the earlier old-style-normalization claim above was incorrect.
   Retail 003e40b0 reads/writes three floats and returns f32 in f0. The guarded
   reconstruction now supplies 21 complete XYZ objects at its 25 calls and
   consumes all ten lengths as floats. This contract repair is not a match;
   see docs/probe_archive/Field_AI_normalization_0017f490_20261003.md.
   2026-10-08: opt_lifetimes on lowers fnalign from 2257 to 1795 edits. */
/* 2026-10-09: 1795 -> 1218 edits. Ghidra's expanded float-to-unsigned conversions (the 2.1474836e+09f compare/subtract blocks) are written as plain (unsigned int)/(unsigned char) casts, the alpha byte is converted once from temp_v9 * 255.0f, and opt_common_subs off is removed: retail shares the 180.0f/200.0f/1.0f constants within each block.
 * 2026-10-09: 1218 -> 1160: aggregate declaration order (greedy move/swap climb
 * scored with tools/multiscore.py).
 * 1155: the 0x1CA mode byte is unsigned (retail lbu).
 */
// FUN_0017F490 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_lifetimes on
extern int FUN_003b7060();
extern int FUN_0047a220();
/* SDK vector normalization reads and writes complete three-float objects and
   returns their original length through the floating-point return register. */
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern unsigned char DAT_005f1ce0[];
extern int FUN_0047a2f0();
extern unsigned int DAT_007efa00; /* 0x7efa00 */
extern float CAND_fGpffff80f0; /* 0xffff80f0 */
extern float CAND_fGpffff811c; /* 0xffff811c */
extern float CAND_fGpffff8218; /* 0xffff8218 */
extern float CAND_fGpffff825c; /* 0xffff825c */
extern float CAND_fGpffff8308; /* 0xffff8308 */
extern float CAND_fGpffff830c; /* 0xffff830c */
extern float CAND_fGpffff8310; /* 0xffff8310 */
extern int CAND_iGpffffb258; /* 0xffffb258 */
extern int CAND_iGpffffb2c8; /* 0xffffb2c8 */
extern int CAND_iGpffffb310; /* 0xffffb310 */

/* Unsupported intrinsic, declaration required: CONCAT44 (PIECE). */
extern s32 FUN_0017ed40(u8 *);
/* Supplied declaration required: FUN_003b7060. */
extern int FUN_003e0f80(void);
extern int FUN_003e9700(unsigned int);
extern unsigned int FUN_0044b7b0(int);
/* Supplied declaration required: FUN_0047a220. */
extern unsigned int FUN_0047a250(unsigned int);
/* Supplied declaration required: FUN_0047a2f0. */
extern int FUN_0014bbe0(int, int, int, int, int);
extern int FUN_0014bd90(unsigned char *);
extern unsigned int FUN_0014c240(void *, void *, float, float);
extern int FUN_0014dbb0(int, int);
extern void FUN_0014dcd0(unsigned char *, int);
extern void FUN_0014dce0(unsigned char *, unsigned char *);
extern void FUN_0014dd10(unsigned char *, unsigned char *);
extern int FUN_0014e740(unsigned char *, float *);
extern int FUN_0015c1e0(int);
extern void FUN_00168ae0(unsigned char *, unsigned char *);
extern void FUN_00168cb0(unsigned char *, float);
extern void func_00168de0(u8 *task, const void *axis, f32 angle);
extern float FUN_00175db0(void);
extern int FUN_0017ea10(unsigned char *);
extern float FUN_003e4180(float *);
extern int FUN_00452080(void *);
extern int FUN_00457120(void);
extern int FUN_0045af60(short, short, short, short);
extern void FUN_0047a850(unsigned char *);
extern void FUN_0047a870(unsigned char *);
extern void FUN_004b13f0(void *, int *);
extern void FUN_004b14f0(void *, int *);

/* WARNING: Removing unreachable block (ram,0x0017f7e0) */
/* WARNING: Removing unreachable block (ram,0x0017f66c) */
/* WARNING: Removing unreachable block (ram,0x0017f790) */
/* WARNING: Type propagation algorithm not settling */

int func_0017f490(unsigned char *param_1)

{
/* irregular: 10 native warning(s); review required */
  int *piVar1;
  float *pfVar2;
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
  unsigned char temp_v5;
  int temp_v6;
  unsigned int temp_v7;
  float temp_v8;
  float temp_v9;
  float temp_v10;
  float temp_v11;
  float fStack_230;
  int iStack_22c;
  float fStack_228;
  unsigned int uStack_220;
  float fStack_218;
  float fStack_210;
  float fStack_20c;
  float fStack_208;
  FldAIVec3 state7Forward;
  FldAIVec3 state8Delta;
  FldAIVec3 state11Right;
  FldAIVec3 state11Forward;
  float fStack_1d0;
  unsigned int uStack_1cc;
  float fStack_1c8;
  FldAIVec3 state8Right;
  FldAIVec3 state10Right;
  FldAIVec3 state10Forward;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  FldAIVec3 state9Direction;
  FldAIVec3 state9Delta;
  FldAIVec3 state9Right;
  FldAIVec3 state9Forward;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  FldAIVec3 state10Delta;
  FldAIVec3 state8Forward;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  FldAIVec3 state7Delta;
  FldAIVec3 state7Right;
  FldAIVec3 state11Delta;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  FldAIVec3 state6Direction;
  FldAIVec3 state6Delta;
  float fStack_80;
  float fStack_7c;
  unsigned int uStack_78;
  float fStack_70;
  float fStack_6c;
  unsigned int uStack_68;
  float fStack_60;
  unsigned int uStack_5c;
  float fStack_58;
  FldAIVec3 state2Delta;
  FldAIVec3 state2Right;
  FldAIVec3 state2Forward;
  float fStack_20;
  unsigned int uStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  int uStack_4;
  
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1[1] == 1) {
    return 0;
  }
  temp_v5 = 0;
  temp_v0 = piVar1[3];
  if ((*(int *)(temp_v0 + 0x48) != 0) && (*(int *)(temp_v0 + 0x54) != 0)) {
    temp_v5 = 1;
  }
  if (temp_v5) {
    if ((*(unsigned int *)(temp_v0 + 0x40) & 1) == 0) {
      return 0;
    }
    temp_v0 = FUN_00457120();
    temp_v0 = FUN_003e9700(*(unsigned int *)(temp_v0 + 4));
    puVar4 = (unsigned char *)FUN_0047a250(*(unsigned int *)(piVar1[3] + 0x50));
    ((unsigned char*)&uStack_4)[0] = *puVar4;
    ((unsigned char*)&uStack_4)[1] = puVar4[1];
    ((unsigned char*)&uStack_4)[2] = puVar4[2];
    ((unsigned char*)&uStack_4)[3] = puVar4[3];
    temp_v8 = ((float *)piVar1)[0x20];
    temp_v10 = ((float *)piVar1)[0x21] - temp_v8;
    if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\0') {
      temp_v8 = CAND_fGpffff80f0 * temp_v10 + temp_v8 + 0.0f;
    }
    else {
      temp_v8 = CAND_fGpffff811c * temp_v10 + temp_v8 + 0.0f;
    }
    temp_v11 = ((float *)piVar1)[0x21] - temp_v8;
    temp_v1 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
    fStack_10 = *(float *)(temp_v1 + 0x30) - *(float *)(temp_v0 + 0x30);
    temp_v1 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
    fStack_c = *(float *)(temp_v1 + 0x34) - *(float *)(temp_v0 + 0x34);
    temp_v1 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
    fStack_8 = *(float *)(temp_v1 + 0x38) - *(float *)(temp_v0 + 0x38);
    temp_v10 = FUN_003e4180(&fStack_10);
    if (((float *)piVar1)[0x21] <= temp_v10) {
      ((unsigned char*)&uStack_4)[3] = 0;
      piVar1[0x1f] = 0;
    }
    else if (temp_v8 <= temp_v10) {
      if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\0') {
        temp_v9 = 0.0f;
        temp_v8 = 1.0f - CAND_fGpffff825c * ((temp_v10 - temp_v8) / temp_v11);
        if (0.0f <= temp_v8) {
          temp_v9 = temp_v8;
        }
      }
      else {
        temp_v9 = 1.0f - (temp_v10 - temp_v8) / temp_v11;
      }
      ((unsigned char*)&uStack_4)[3] = (unsigned char)(temp_v9 * 255.0f);
      ((float *)piVar1)[0x1f] = (float)((unsigned char*)&uStack_4)[3];
    }
    else {
      ((unsigned char*)&uStack_4)[3] = 0xff;
      piVar1[0x1f] = 0x437f0000;
    }
    if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\x01') {
      FUN_0047a220(*(unsigned int *)(piVar1[3] + 0x50),&uStack_4);
    }
    for (temp_v0 = **(int **)(*(int *)(piVar1[3] + 0x50) + 0x2cc); temp_v0 != 0;
        temp_v0 = *(int *)(temp_v0 + 0x10)) {
      if (*(void **)(temp_v0 + 8) != (void *)0x0) {
        FUN_004b14f0(*(void **)(temp_v0 + 8),&uStack_4);
        temp_v8 = ((float *)piVar1)[0x1f];
        ((unsigned char*)&uStack_4)[3] = (unsigned char)temp_v8;
        FUN_004b13f0(*(void **)(temp_v0 + 8),&uStack_4);
      }
    }
    switch(*piVar1) {
    case 0:
      temp_v0 = FUN_003e0f80();
      piVar1[4] = temp_v0;
      func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,0,1);
      piVar1[5] = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(piVar1[3] + 0x1ca) * 0x180 +
                  (unsigned int)*(unsigned short *)(piVar1[3] + 0x1c8) * 0x40;
      temp_v0 = piVar1[3];
      ((float *)piVar1)[9] = *(float *)(temp_v0 + 0x19c);
      ((float *)piVar1)[10] = *(float *)(temp_v0 + 0x1a0);
      ((float *)piVar1)[0xb] = *(float *)(temp_v0 + 0x1a4);
      temp_v0 = piVar1[3];
      ((float *)piVar1)[6] = *(float *)(temp_v0 + 0x19c);
      ((float *)piVar1)[7] = *(float *)(temp_v0 + 0x1a0);
      ((float *)piVar1)[8] = *(float *)(temp_v0 + 0x1a4);
      temp_v0 = piVar1[3];
      ((float *)piVar1)[0xf] = *(float *)(temp_v0 + 0x19c);
      ((float *)piVar1)[0x10] = *(float *)(temp_v0 + 0x1a0);
      ((float *)piVar1)[0x11] = *(float *)(temp_v0 + 0x1a4);
      temp_v0 = piVar1[3];
      ((float *)piVar1)[0xc] = *(float *)(temp_v0 + 0x19c);
      ((float *)piVar1)[0xd] = *(float *)(temp_v0 + 0x1a0);
      ((float *)piVar1)[0xe] = *(float *)(temp_v0 + 0x1a4);
      temp_v0 = FUN_003b7060();
      piVar1[0x17] = (int)((unsigned int)temp_v0 % 3) + 1;
      ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
      ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x18);
      pbVar7 = (unsigned char *)FUN_0014dbb0((int)param_1,0x794420);
      piVar1[0x26] = (int)pbVar7;
      FUN_0014dd10(pbVar7,(unsigned char *)(piVar1[3] + 0x19c));
      FUN_0014dce0((unsigned char *)piVar1[0x26],(unsigned char *)DAT_005f1ce0);
      FUN_0014dcd0((unsigned char *)piVar1[0x26],0);
      *piVar1 = *piVar1 + 1;
      break;
    case 1:
      temp_v3 = FUN_0017ed40((u8 *)piVar1);
      if (temp_v3 == 0) {
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        fStack_20 = *(float *)(temp_v0 + 0x30);
        uStack_1c = *(unsigned int *)(temp_v0 + 0x34);
        fStack_18 = *(float *)(temp_v0 + 0x38);
        if (*(int *)(piVar1[3] + 0x73c) == 0) {
          FUN_0014dcd0((unsigned char *)piVar1[0x26],0);
        }
        else {
          FUN_0014dcd0((unsigned char *)piVar1[0x26],1);
          FUN_0014dd10((unsigned char *)piVar1[0x26],(unsigned char *)(piVar1 + 0x14));
          FUN_0014dce0((unsigned char *)piVar1[0x26],(unsigned char *)(DAT_005f1ce0 + piVar1[0x12] * 4));
        }
        temp_v0 = FUN_003b7060();
        temp_v3 = 0;
        if (piVar1[2] == 0) {
          if ((unsigned int)temp_v0 % 100 < 5) {
            temp_v3 = 1;
          }
        }
        else if ((piVar1[2] == 1) && ((unsigned int)temp_v0 % 100 < 0x1e)) {
          temp_v3 = 1;
        }
        if (temp_v3 == 1) {
          temp_v2 = FUN_003b7060();
          if ((temp_v2 & 1) == 0) {
            piVar1[0x1d] = -0x40800000;
          }
          else {
            piVar1[0x1d] = 0x3f800000;
          }
          temp_v0 = FUN_003b7060();
          piVar1[0x23] = (int)((unsigned int)temp_v0 % 0x1e) + 0x1e;
          *piVar1 = 3;
        }
        else if (temp_v3 == 2) {
          piVar1[0x23] = *(int *)(piVar1[5] + 0x2c);
          *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) | 2;
          temp_v8 = ((float *)piVar1)[0x1f];
          temp_v7 = (unsigned int)temp_v8;
          temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(piVar1[3] + 0x50),temp_v7,0,10);
          piVar1[0x22] = temp_v0;
          *piVar1 = 4;
        }
        else {
          temp_v7 = piVar1[0x12] != 0 ^ 1;
          temp_v4 = 0;
          temp_v5 = temp_v4;
          if ((((((float *)piVar1)[temp_v7 * 6 + 9] <= fStack_20) &&
               (fStack_20 <= ((float *)piVar1)[temp_v7 * 6 + 6])) &&
              (((float *)piVar1)[temp_v7 * 6 + 0xb] <= fStack_18)) &&
             (temp_v5 = 1, ((float *)piVar1)[temp_v7 * 6 + 8] < fStack_18)) {
            temp_v5 = temp_v4;
          }
          if (temp_v5) {
            piVar1[0x12] = piVar1[0x12] != 0 ^ 1;
          }
          temp_v0 = FUN_003b7060();
          temp_v8 = CAND_fGpffff8308 + (float)((unsigned int)temp_v0 % 0x50) / 100.0f;
          temp_v1 = FUN_003b7060();
          temp_v0 = piVar1[0x12];
          pfVar6 = (float *)0xc;
          pfVar8 = &fStack_230;
          pfVar2 = pfVar8;
          while (pfVar2 != (float *)0x0) {
            *(unsigned char *)pfVar8 = 0;
            pfVar8 = (float *)((int)pfVar8 + 1);
            pfVar6 = (float *)((int)pfVar6 - 1);
            pfVar2 = pfVar6;
          }
          fStack_230 = temp_v8 * (((float *)piVar1)[temp_v0 * 6 + 6] - ((float *)piVar1)[temp_v0 * 6 + 9]) +
                       ((float *)piVar1)[temp_v0 * 6 + 9] + 0.0f;
          fStack_228 = (CAND_fGpffff8308 + (float)((unsigned int)temp_v1 % 0x50) / 100.0f) *
                       (((float *)piVar1)[temp_v0 * 6 + 8] - ((float *)piVar1)[temp_v0 * 6 + 0xb]) +
                       ((float *)piVar1)[temp_v0 * 6 + 0xb] + 0.0f;
          uStack_220 = CONCAT44(iStack_22c,fStack_230);
          ((float *)piVar1)[0x14] = fStack_230;
          piVar1[0x15] = iStack_22c;
          ((float *)piVar1)[0x16] = fStack_228;
          if (piVar1[0x17] < 1) {
            temp_v7 = piVar1[0x19] != 0 ^ 1;
            piVar1[0x19] = temp_v7;
            if (temp_v7 == 0) {
              ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x18);
            }
            else {
              ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x1c);
            }
            piVar1[0x18] = 0xf;
            fStack_218 = fStack_228;
            temp_v0 = FUN_003b7060();
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
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state2Forward.x = *(float *)(temp_v0 + 0x20);
      state2Forward.y = *(float *)(temp_v0 + 0x24);
      state2Forward.z = *(float *)(temp_v0 + 0x28);
      RwV3dNormalize(&state2Forward,&state2Forward);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state2Right.x = *pfVar8;
      state2Right.y = pfVar8[1];
      state2Right.z = pfVar8[2];
      RwV3dNormalize(&state2Right,&state2Right);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_60 = *(float *)(temp_v0 + 0x30);
      fStack_58 = *(float *)(temp_v0 + 0x38);
      uStack_5c = 0;
      state2Delta.x = ((float *)piVar1)[0x14] - fStack_60;
      state2Delta.y = ((float *)piVar1)[0x15] - 0.0f;
      state2Delta.z = ((float *)piVar1)[0x16] - fStack_58;
      temp_v10 = RwV3dNormalize(&state2Delta,&state2Delta);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        *piVar1 = 1;
        temp_v8 = temp_v10;
      }
      temp_v10 = state2Delta.z * state2Forward.z + state2Delta.x * state2Forward.x + state2Delta.y * state2Forward.y;
      if (temp_v10 < 1.0f) {
        temp_v11 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v10 = 1.0f - temp_v10;
        if (temp_v10 < temp_v11 / 180.0f) {
          temp_v11 = temp_v10 * 180.0f;
        }
        if (state2Delta.z * state2Right.z + state2Delta.x * state2Right.x + state2Delta.y * state2Right.y < 0.0f) {
          temp_v11 = temp_v11 * -1.0f;
        }
        func_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v11);
        temp_v11 = ((float *)piVar1)[0x1c] + temp_v11;
        ((float *)piVar1)[0x1c] = temp_v11;
        if ((360.0f < temp_v11) || (temp_v11 < -360.0f)) {
          *piVar1 = 1;
        }
      }
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        if (piVar1[0x19] == 0) {
          piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] -
                              (*(float *)(piVar1[5] + 0x1c) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        }
        else {
          piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                              (*(float *)(piVar1[5] + 0x1c) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        }
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]);
      if (temp_v0 == 1) {
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        fStack_70 = *(float *)(temp_v0 + 0x30);
        uStack_68 = *(unsigned int *)(temp_v0 + 0x38);
        fStack_6c = *(float *)(temp_v0 + 0x34) +
                    *(float *)((unsigned int)*(unsigned char *)(piVar1[3] + 0x1cb) * 4 +
                              (unsigned int)*(unsigned char *)(piVar1[3] + 0x1ca) * 0x10 + 0x5f1cc0);
        pbVar7 = (unsigned char *)FUN_0015c1e0(1);
        FUN_0014e740(pbVar7,&fStack_70);
        FUN_0045af60(1,0xb,3,5);
        piVar1[0x23] = *(int *)(piVar1[5] + 0x30);
        *piVar1 = 6;
      }
      break;
    case 3:
      if (piVar1[0x23] >= 0) {
        func_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510,
                      *(float *)(piVar1[5] + 0x18) * 10.0f * ((float *)piVar1)[0x1d]);
        temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]);
        if (temp_v0 == 1) {
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_80 = *(float *)(temp_v0 + 0x30);
          uStack_78 = *(unsigned int *)(temp_v0 + 0x38);
          fStack_7c = *(float *)(temp_v0 + 0x34) +
                      *(float *)((unsigned int)*(unsigned char *)(piVar1[3] + 0x1cb) * 4 +
                                (unsigned int)*(unsigned char *)(piVar1[3] + 0x1ca) * 0x10 + 0x5f1cc0);
          pbVar7 = (unsigned char *)FUN_0015c1e0(1);
          FUN_0014e740(pbVar7,&fStack_80);
          FUN_0045af60(1,0xb,3,5);
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
        temp_v0 = FUN_0014bd90((unsigned char *)piVar1[0x22]);
        if (temp_v0 == 0) {
          return 0;
        }
        FUN_00452080((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
      }
      if (piVar1[0x23] >= 0) {
        piVar1[0x23] = piVar1[0x23] - 1;
      }
      else {
        temp_v8 = ((float *)piVar1)[0x1f];
        temp_v7 = (unsigned int)temp_v8;
        temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(piVar1[3] + 0x50),0,temp_v7,10);
        piVar1[0x22] = temp_v0;
        *piVar1 = *piVar1 + 1;
      }
      break;
    case 5:
      temp_v0 = FUN_0014bd90((unsigned char *)piVar1[0x22]);
      if (temp_v0 != 0) {
        FUN_00452080((void *)piVar1[0x22]);
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
        func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,1,8,1);
        temp_v0 = FUN_003b7060();
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
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_b0 = *(float *)(temp_v0 + 0x30);
          fStack_a8 = *(float *)(temp_v0 + 0x38);
          fStack_ac = 0.0f;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          state6Direction.x = *(float *)(temp_v0 + 0x30) - fStack_b0;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          state6Direction.y = *(float *)(temp_v0 + 0x34) - fStack_ac;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          state6Direction.z = *(float *)(temp_v0 + 0x38) - fStack_a8;
          RwV3dNormalize(&state6Direction,&state6Direction);
          state6Direction.x = state6Direction.x * 200.0f;
          state6Direction.y = state6Direction.y * 200.0f;
          state6Direction.z = state6Direction.z * 200.0f;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          ((float *)piVar1)[0x14] = (state6Direction.x + *(float *)(temp_v0 + 0x30));
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          ((float *)piVar1)[0x15] = (state6Direction.y + *(float *)(temp_v0 + 0x34));
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          ((float *)piVar1)[0x16] = (state6Direction.z + *(float *)(temp_v0 + 0x38));
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          state6Delta.x = ((float *)piVar1)[0x14] - *(float *)(temp_v0 + 0x30);
          state6Delta.y = ((float *)piVar1)[0x15] - 0.0f;
          state6Delta.z = ((float *)piVar1)[0x16] - *(float *)(temp_v0 + 0x38);
          temp_v8 = RwV3dNormalize(&state6Delta,&state6Delta);
          piVar1[0x25] = (int)(temp_v8 / (CAND_fGpffff830c * *(float *)(piVar1[5] + 0x28)));
          *piVar1 = 9;
        }
        else if (temp_v3 == 3) {
          ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x28);
          piVar1[0x18] = 0xf;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          temp_v1 = *(int *)(temp_v0 + 0x34);
          temp_v6 = *(int *)(temp_v0 + 0x38);
          ((float *)piVar1)[0x14] = *(float *)(temp_v0 + 0x30);
          piVar1[0x15] = temp_v1;
          piVar1[0x16] = temp_v6;
          *piVar1 = 10;
        }
      }
      break;
    case 7:
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state7Forward.x = *(float *)(temp_v0 + 0x20);
      state7Forward.y = *(float *)(temp_v0 + 0x24);
      state7Forward.z = *(float *)(temp_v0 + 0x28);
      RwV3dNormalize(&state7Forward,&state7Forward);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state7Right.x = *pfVar8;
      state7Right.y = pfVar8[1];
      state7Right.z = pfVar8[2];
      RwV3dNormalize(&state7Right,&state7Right);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_f0 = *(float *)(temp_v0 + 0x30);
      fStack_e8 = *(float *)(temp_v0 + 0x38);
      fStack_ec = 0.0f;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      state7Delta.x = *(float *)(temp_v0 + 0x30) - fStack_f0;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      state7Delta.y = *(float *)(temp_v0 + 0x34) - fStack_ec;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      state7Delta.z = *(float *)(temp_v0 + 0x38) - fStack_e8;
      temp_v10 = RwV3dNormalize(&state7Delta,&state7Delta);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        temp_v8 = temp_v10;
      }
      temp_v10 = state7Delta.z * state7Forward.z + state7Delta.x * state7Forward.x + state7Delta.y * state7Forward.y;
      if (temp_v10 < 1.0f) {
        temp_v11 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v10 = 1.0f - temp_v10;
        if (temp_v10 < temp_v11 / 180.0f) {
          temp_v11 = temp_v10 * 180.0f;
        }
        if (state7Delta.z * state7Right.z + state7Delta.x * state7Right.x + state7Delta.y * state7Right.y < 0.0f) {
          temp_v11 = temp_v11 * -1.0f;
        }
        func_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v11);
      }
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      if ((piVar1[0x23] < 1) && (temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]), temp_v0 == 0)) {
        piVar1[0x23] = *(int *)(piVar1[5] + 0x34);
        *piVar1 = 0xb;
        func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      else {
        if (0 < piVar1[0x23]) {
          piVar1[0x23] = piVar1[0x23] - 1;
        }
        temp_v0 = piVar1[0x24];
        if (temp_v0 < 1) {
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          state7Delta.x = *(float *)(temp_v0 + 0x30) - *(float *)(piVar1[3] + 0x19c);
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          state7Delta.y = *(float *)(temp_v0 + 0x34) - *(float *)(piVar1[3] + 0x1a0);
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          state7Delta.z = *(float *)(temp_v0 + 0x38) - *(float *)(piVar1[3] + 0x1a4);
          temp_v8 = RwV3dNormalize(&state7Delta,&state7Delta);
          if (*(float *)piVar1[5] <= temp_v8) {
            piVar1[0x23] = (int)((float *)piVar1[5])[0xd];
            func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
            *piVar1 = 0xb;
          }
        }
        else if (0 < temp_v0) {
          piVar1[0x24] = temp_v0 - 1;
        }
      }
      break;
    case 8:
      temp_v8 = FUN_00175db0();
      if (temp_v8 == 0.0f) {
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        fStack_140 = *(float *)(temp_v0 + 0x30);
        fStack_13c = *(float *)(temp_v0 + 0x34);
        fStack_138 = *(float *)(temp_v0 + 0x38);
      }
      else {
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        temp_v11 = *(float *)(temp_v0 + 0x28);
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        temp_v9 = *(float *)(temp_v0 + 0x28);
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        temp_v8 = *(float *)(temp_v0 + 0x20);
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        temp_v10 = *(float *)(temp_v0 + 0x20);
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        if (CAND_fGpffff8310 <
            temp_v9 * temp_v11 + temp_v10 * temp_v8 + *(float *)(temp_v1 + 0x24) * *(float *)(temp_v0 + 0x24))
        {
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_140 = *(float *)(temp_v0 + 0x30);
          fStack_13c = *(float *)(temp_v0 + 0x34);
          fStack_138 = *(float *)(temp_v0 + 0x38);
          *piVar1 = 7;
        }
        else {
          temp_v8 = FUN_00175db0();
          temp_v8 = temp_v8 - ((float *)piVar1)[0x1a];
          if (temp_v8 < 0.0f) {
            temp_v8 = temp_v8 * -1.0f;
          }
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_130 = *(float *)(temp_v0 + 0x30);
          fStack_128 = *(float *)(temp_v0 + 0x38);
          fStack_12c = 0.0f;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          state8Delta.x = *(float *)(temp_v0 + 0x30) - fStack_130;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          state8Delta.y = *(float *)(temp_v0 + 0x34) - fStack_12c;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          state8Delta.z = *(float *)(temp_v0 + 0x38) - fStack_128;
          temp_v10 = RwV3dNormalize(&state8Delta,&state8Delta);
          temp_v10 = temp_v10 / temp_v8;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          state8Forward.x = *(float *)(temp_v0 + 0x20);
          state8Forward.y = *(float *)(temp_v0 + 0x24);
          state8Forward.z = *(float *)(temp_v0 + 0x28);
          temp_v8 = FUN_00175db0();
          state8Forward.x = state8Forward.x * temp_v10 * temp_v8;
          temp_v8 = FUN_00175db0();
          state8Forward.y = state8Forward.y * temp_v10 * temp_v8;
          temp_v8 = FUN_00175db0();
          state8Forward.z = state8Forward.z * temp_v10 * temp_v8;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_140 = *(float *)(temp_v0 + 0x30) + state8Forward.x;
          fStack_13c = *(float *)(temp_v0 + 0x34) + state8Forward.y;
          fStack_138 = *(float *)(temp_v0 + 0x38) + state8Forward.z;
        }
      }
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state8Forward.x = *(float *)(temp_v0 + 0x20);
      state8Forward.y = *(float *)(temp_v0 + 0x24);
      state8Forward.z = *(float *)(temp_v0 + 0x28);
      RwV3dNormalize(&state8Forward,&state8Forward);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state8Right.x = *pfVar8;
      state8Right.y = pfVar8[1];
      state8Right.z = pfVar8[2];
      RwV3dNormalize(&state8Right,&state8Right);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state8Delta.x = fStack_140 - *(float *)(temp_v0 + 0x30);
      state8Delta.y = fStack_13c - 0.0f;
      state8Delta.z = fStack_138 - *(float *)(temp_v0 + 0x38);
      temp_v10 = RwV3dNormalize(&state8Delta,&state8Delta);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        temp_v8 = temp_v10;
      }
      temp_v10 = state8Delta.z * state8Forward.z + state8Delta.x * state8Forward.x + state8Delta.y * state8Forward.y;
      if (temp_v10 < 1.0f) {
        temp_v11 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v10 = 1.0f - temp_v10;
        if (temp_v10 < temp_v11 / 180.0f) {
          temp_v11 = temp_v10 * 180.0f;
        }
        if (state8Delta.z * state8Right.z + state8Delta.x * state8Right.x + state8Delta.y * state8Right.y < 0.0f) {
          temp_v11 = temp_v11 * -1.0f;
        }
        func_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v11);
      }
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      if ((piVar1[0x23] < 1) && (temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]), temp_v0 == 0)) {
        piVar1[0x23] = *(int *)(piVar1[5] + 0x34);
        *piVar1 = 0xb;
        func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      else {
        if (0 < piVar1[0x23]) {
          piVar1[0x23] = piVar1[0x23] - 1;
        }
        temp_v0 = piVar1[0x24];
        if (temp_v0 < 1) {
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          state8Delta.x = *(float *)(temp_v0 + 0x30) - *(float *)(piVar1[3] + 0x19c);
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          state8Delta.y = *(float *)(temp_v0 + 0x34) - *(float *)(piVar1[3] + 0x1a0);
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          state8Delta.z = *(float *)(temp_v0 + 0x38) - *(float *)(piVar1[3] + 0x1a4);
          temp_v8 = RwV3dNormalize(&state8Delta,&state8Delta);
          if (*(float *)piVar1[5] <= temp_v8) {
            piVar1[0x23] = (int)((float *)piVar1[5])[0xd];
            *piVar1 = 0xb;
            func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
          }
        }
        else if (0 < temp_v0) {
          piVar1[0x24] = temp_v0 - 1;
        }
      }
      break;
    case 9:
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state9Forward.x = *(float *)(temp_v0 + 0x20);
      state9Forward.y = *(float *)(temp_v0 + 0x24);
      state9Forward.z = *(float *)(temp_v0 + 0x28);
      RwV3dNormalize(&state9Forward,&state9Forward);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state9Right.x = *pfVar8;
      state9Right.y = pfVar8[1];
      state9Right.z = pfVar8[2];
      RwV3dNormalize(&state9Right,&state9Right);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_190 = *(float *)(temp_v0 + 0x30);
      fStack_188 = *(float *)(temp_v0 + 0x38);
      fStack_18c = 0.0f;
      temp_v11 = (float)FUN_0044b7b0(piVar1[0x1e]);
      temp_v8 = fStack_18c;
      ((float *)piVar1)[0x1e] = (((float *)piVar1)[0x1e] + CAND_fGpffff8218);
      state9Direction.x = ((float *)piVar1)[0x14] - fStack_190;
      state9Direction.y = ((float *)piVar1)[0x15] - fStack_18c;
      state9Direction.z = ((float *)piVar1)[0x16] - fStack_188;
      temp_v10 = fStack_188;
      RwV3dNormalize(&state9Direction,&state9Direction);
      state9Direction.x = state9Direction.x * 200.0f + ((float *)piVar1)[0x14];
      state9Direction.y = state9Direction.y * 200.0f + ((float *)piVar1)[0x15];
      state9Direction.z = state9Direction.z * 200.0f + ((float *)piVar1)[0x16];
      temp_v11 = temp_v11 * 400.0f;
      state9Delta.x = (state9Right.x * temp_v11 + state9Direction.x) - fStack_190;
      state9Delta.y = (state9Right.y * temp_v11 + state9Direction.y) - temp_v8;
      state9Delta.z = (state9Right.z * temp_v11 + state9Direction.z) - temp_v10;
      temp_v10 = RwV3dNormalize(&state9Delta,&state9Delta);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        temp_v8 = temp_v10;
      }
      if (piVar1[0x25] < 1) {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
        func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      else {
        piVar1[0x25] = piVar1[0x25] - 1;
      }
      temp_v11 = ((float *)piVar1)[0x1a] * 10.0f * 5.0f;
      temp_v10 = 1.0f - (state9Delta.z * state9Forward.z + state9Delta.x * state9Forward.x + state9Delta.y * state9Forward.y);
      if (temp_v10 < temp_v11 / 180.0f) {
        temp_v11 = temp_v10 * 180.0f;
      }
      if (state9Delta.z * state9Right.z + state9Delta.x * state9Right.x + state9Delta.y * state9Right.y < 0.0f) {
        temp_v11 = temp_v11 * -1.0f;
      }
      func_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v11);
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      break;
    case 10:
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state10Forward.x = *(float *)(temp_v0 + 0x20);
      state10Forward.y = *(float *)(temp_v0 + 0x24);
      state10Forward.z = *(float *)(temp_v0 + 0x28);
      RwV3dNormalize(&state10Forward,&state10Forward);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state10Right.x = *pfVar8;
      state10Right.y = pfVar8[1];
      state10Right.z = pfVar8[2];
      RwV3dNormalize(&state10Right,&state10Right);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_1d0 = *(float *)(temp_v0 + 0x30);
      fStack_1c8 = *(float *)(temp_v0 + 0x38);
      uStack_1cc = 0;
      state10Delta.x = ((float *)piVar1)[0x14] - fStack_1d0;
      state10Delta.y = ((float *)piVar1)[0x15] - 0.0f;
      state10Delta.z = ((float *)piVar1)[0x16] - fStack_1c8;
      temp_v10 = RwV3dNormalize(&state10Delta,&state10Delta);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
        func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
        temp_v8 = temp_v10;
      }
      temp_v10 = ((float *)piVar1)[0x1a] * 10.0f;
      temp_v11 = 1.0f - (state10Delta.z * state10Forward.z + state10Delta.x * state10Forward.x + state10Delta.y * state10Forward.y);
      if (temp_v11 < temp_v10 / 180.0f) {
        temp_v10 = temp_v11 * 180.0f;
      }
      if (state10Delta.z * state10Right.z + state10Delta.x * state10Right.x + state10Delta.y * state10Right.y < 0.0f) {
        temp_v10 = temp_v10 * -1.0f;
      }
      func_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v10);
      temp_v10 = ((float *)piVar1)[0x1c] + temp_v10;
      ((float *)piVar1)[0x1c] = temp_v10;
      if ((360.0f < temp_v10) || (temp_v10 < -360.0f)) {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
      }
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      break;
    case 0xb:
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state11Forward.x = *(float *)(temp_v0 + 0x20);
      state11Forward.y = *(float *)(temp_v0 + 0x24);
      state11Forward.z = *(float *)(temp_v0 + 0x28);
      RwV3dNormalize(&state11Forward,&state11Forward);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      state11Right.x = *pfVar8;
      state11Right.y = pfVar8[1];
      state11Right.z = pfVar8[2];
      RwV3dNormalize(&state11Right,&state11Right);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_210 = *(float *)(temp_v0 + 0x30);
      fStack_208 = *(float *)(temp_v0 + 0x38);
      fStack_20c = 0.0f;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      state11Delta.x = *(float *)(temp_v0 + 0x30) - fStack_210;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      state11Delta.y = *(float *)(temp_v0 + 0x34) - fStack_20c;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      state11Delta.z = *(float *)(temp_v0 + 0x38) - fStack_208;
      RwV3dNormalize(&state11Delta,&state11Delta);
      temp_v8 = state11Delta.z * state11Forward.z + state11Delta.x * state11Forward.x + state11Delta.y * state11Forward.y;
      if (temp_v8 < 1.0f) {
        temp_v10 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v8 = 1.0f - temp_v8;
        if (temp_v8 < temp_v10 / 180.0f) {
          temp_v10 = temp_v8 * 180.0f;
        }
        if (state11Delta.z * state11Right.z + state11Delta.x * state11Right.x + state11Delta.y * state11Right.y < 0.0f) {
          temp_v10 = temp_v10 * -1.0f;
        }
        func_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220), D_00756510, temp_v10);
      }
      temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]);
      if (temp_v0 == 1) {
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        state11Delta.x = *(float *)(temp_v0 + 0x30) - *(float *)(piVar1[3] + 0x19c);
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        state11Delta.y = *(float *)(temp_v0 + 0x34) - *(float *)(piVar1[3] + 0x1a0);
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        state11Delta.z = *(float *)(temp_v0 + 0x38) - *(float *)(piVar1[3] + 0x1a4);
        temp_v8 = RwV3dNormalize(&state11Delta,&state11Delta);
        if (temp_v8 < *(float *)piVar1[5]) {
          ((float *)piVar1)[0x1a] = ((float *)piVar1[5])[6];
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x20);
          piVar1[0x18] = 1;
          piVar1[0x23] = 0xd2;
          piVar1[0x24] = 0x3c;
          *piVar1 = 7;
          func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,1,8,1);
          return 0;
        }
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      if (piVar1[0x23] >= 0) {
        piVar1[0x23] = piVar1[0x23] - 1;
      }
      else {
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        temp_v10 = *(float *)(temp_v0 + 0x30);
        temp_v8 = *(float *)(temp_v0 + 0x38);
        temp_v5 = 0;
        if ((((((float *)piVar1)[9] <= temp_v10) && (temp_v10 <= ((float *)piVar1)[6])) &&
            (((float *)piVar1)[0xb] <= temp_v8)) && (temp_v8 <= ((float *)piVar1)[8])) {
          temp_v5 = 1;
        }
        if (!temp_v5) {
          temp_v5 = 0;
          if (((((float *)piVar1)[0xf] <= temp_v10) && (temp_v10 <= ((float *)piVar1)[0xc])) &&
             ((((float *)piVar1)[0x11] <= temp_v8 && (temp_v8 <= ((float *)piVar1)[0xe])))) {
            temp_v5 = 1;
          }
          if (!temp_v5) {
            *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) | 2;
            if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\x01') {
              temp_v0 = *(int *)(piVar1[3] + 0x50);
              *(unsigned int *)(temp_v0 + 0xd8) = *(unsigned int *)(temp_v0 + 0xd8) & 0xffffff7f;
            }
            FUN_0047a850(*(unsigned char **)(piVar1[3] + 0x50));
            temp_v0 = piVar1[3];
            if (*(char *)(temp_v0 + 0x1ca) == '\0') {
              temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(temp_v0 + 0x50),0xff,0,10);
              piVar1[0x22] = temp_v0;
            }
            else if (*(char *)(temp_v0 + 0x1ca) == '\x01') {
              temp_v8 = ((float *)piVar1)[0x1f];
              temp_v7 = (unsigned int)temp_v8;
              temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(temp_v0 + 0x50),temp_v7,0,10);
              piVar1[0x22] = temp_v0;
            }
            ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
            *piVar1 = 0xc;
            func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
            return 0;
          }
        }
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
        func_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      break;
    case 0xc:
      temp_v0 = FUN_0014bd90((unsigned char *)piVar1[0x22]);
      if (temp_v0 != 0) {
        FUN_00452080((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
        FUN_00168ae0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),(unsigned char *)(piVar1[3] + 0x19c));
        temp_v0 = piVar1[3];
        if (*(char *)(temp_v0 + 0x1ca) == '\0') {
          temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(temp_v0 + 0x50),0,0xff,10);
          piVar1[0x22] = temp_v0;
        }
        else if (*(char *)(temp_v0 + 0x1ca) == '\x01') {
          temp_v8 = ((float *)piVar1)[0x1f];
          temp_v7 = (unsigned int)temp_v8;
          temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(temp_v0 + 0x50),0,temp_v7,10);
          piVar1[0x22] = temp_v0;
        }
        *piVar1 = 0xd;
      }
      break;
    case 0xd:
      temp_v0 = FUN_0014bd90((unsigned char *)piVar1[0x22]);
      if (temp_v0 != 0) {
        if (*(unsigned char *)(piVar1[3] + 0x1ca) == '\x01') {
          temp_v0 = *(int *)(piVar1[3] + 0x50);
          *(unsigned int *)(temp_v0 + 0xd8) = *(unsigned int *)(temp_v0 + 0xd8) | 0x80;
        }
        FUN_0047a870(*(unsigned char **)(piVar1[3] + 0x50));
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffff9;
        FUN_00452080((void *)piVar1[0x22]);
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
#else
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017f490);
#endif

// FUN_001821D0
void func_001821d0(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x10);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_00182220
s32 func_00182220(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    u8 *work;

    func_0044ea90(D_005F1B18, 0xA50);
    work = D_008873F4[0](1, 0xA0, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005F1CF0), 0xF, 0, 0, func_0017f490, func_001821d0, (u8 *)(work));
    *(s32 *)(work + 0xC) = arg1;
    *(s32 *)(work + 0x4) = 1;
    *(s32 *)(work + 0x8) = arg2;
    *(f32 *)(work + 0x80) = *(f32 *)(func_00457120() + 0x80);
    *(f32 *)(work + 0x84) = iGpffffba6c;
    return ret;
}
