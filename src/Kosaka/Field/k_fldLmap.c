#include "mt_scene_internal.h"
#include "field_transition_internal.h"
/* Original translation unit k_fldLmap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
#include "include_asm.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

extern void (*jtbl_008873EC[])(void *);
typedef struct Vec3 { f32 x; f32 y; f32 z; } Vec3;
#include "sdktask.h"
#include "primitive_queue_internal.h"
#include "resrc_manager_internal.h"
#include "rw_camera_internal.h"
#include "h_cdvd_request_internal.h"

/* Integer writes preserve the retail float bit patterns (including sw-zero stores). */
typedef union FldLmapCoordinate { f32 value; s32 bits; } FldLmapCoordinate;
typedef struct FldLmapPosition {
    FldLmapCoordinate x, y, z;
} FldLmapPosition;
/* Sprite/model/task handles are passed as both words and pointers by these APIs. */
typedef union FldLmapHandle { s32 value; u8 *data; void *pointer; } FldLmapHandle;

/* Layout is bounded by FldLmapCreate's 0x178-byte allocation and all users below. */
typedef struct FldLmapWork {
    s32 state, assetsLoaded, enableToggle, selectedSlot, previousSlot, selectionDelay;
    u8 *camera;
    u8 *spriteDirectory;
    u8 *scriptDirectory;
    FldLmapHandle sprites[10];
    s32 normalSlots[5];
    s32 selectedSlots[5];
    s32 panelsVisible, togglePanels, nextPanel;
    s32 panelSlots[2];
    f32 panelOffsets[2];
    FldLmapPosition rowPosition;
    FldLmapPosition normalPositions[5];
    FldLmapPosition selectedPositions[5];
    FldLmapPosition panelPositions[2];
    FldLmapPosition marqueePosition;
    u8 pad138[8];
    FldLmapHandle slotResources[6];
    FldLmapHandle scrollTask, loadTask, scriptTask, markerTask, pathTask;
    s32 slideDirection, scrollComplete, slideDelay;
} FldLmapWork;

typedef struct FldLmapLoadWork {
    s32 state;
    u8 *directory;
    FldLmapWork *map;
} FldLmapLoadWork;

/* 0x2C bytes allocated by FldLmapScrollTaskCreate. */
typedef struct FldLmapScrollWork {
    s32 state;
    FldLmapPosition *position;
    FldLmapPosition *otherPosition;
    f32 startX, endX, direction;
    u8 pad18[4];
    s32 duration, framesLeft, delayFrames;
    s32 *completionFlag;
} FldLmapScrollWork;

/* Five saved resource positions, then direction/speed and target/selected indices. */
typedef struct FldLmapMarkerWork {
    s32 state;
    FldLmapHandle marker;
    u8 **slotResources;
    Vec3 positions[5];
    Vec3 direction;
    f32 speed;
    s32 targetSlot, selectedSlot;
} FldLmapMarkerWork;

typedef struct FldLmapPathWork {
    s32 state;
    Vec3 eye, target;
    u8 pad1C[8];
    s32 frame, duration;
    u8 pad2C[4];
    s32 targetSlot;
} FldLmapPathWork;

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(s32, s32);
extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void kAssertFail(u8 *file, s32 line);
extern void func_00440b68();
extern void sprintf(u8 *dst, u8 *src);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern void H_Cdvd_Destroy(u8 *cdvd);
extern s32 H_Cdvd_IsFileLoaded(u8 *cdvd);
extern s32 H_Cdvd_LookupRequest(u8 *pathAddress, s32 *slot);
extern s32 hMaestroDecodeIsReady(s32 state);
extern void sdkSpriteRelease(void *node);

extern void func_003e0f40(u8 *param);
extern void fieldSceneUnload();
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern u8 *PrimAllocQueueNode();
extern void PrimAppendNode(void *list, u8 *node);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 RwV3dNormalize(f32 *param, f32 *out);
extern u8 *mdlGetMatrix(s32 model);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern u8 *kwlnGetCamera();
extern void K_ClumpLookAtBasis(u8 *object, u8 *position, u8 *target, s32 referenceUp);
extern f32 sinf(f32 param);
extern f32 cosf(f32 param);
extern s64 datGetDateIndex();
extern s32 datGetTimeSlot();
extern s64 calGetDayEntryByPhase(s64 day, s32 phase);
extern s32 datGetFlag(s32 bit);
extern u8 *func_003e0f80();
extern void fieldSceneLoad(s32 fieldId, s32 roomId);
extern void fieldSceneRequestSecondaryRoom(s64 roomId);
extern s32 fieldSceneLoadStep();
extern u8 *MT_Scene_GetCameraResFirst();
extern f32 MT_Scene_GetCameraFov();
extern s32 sndRequestAreaTrack();
extern void sndPlayAreaCue();
extern void fadeBeginReturnTransition(s32 mode, s32 duration);
extern s32 fadeStatus();
extern void fadeBeginTransition(s32 mode, s32 duration);
extern s32 kwlnTaskIsLinked(u8 *target);
extern s32 scrStartProcedureChecked(s32 priority, s32 source, s32 size, s32 procedureIndex);
extern void func_003e9cb0(s32 frame, u8 *transform, s32 combine);
extern void K_View_SetFov(u8 *camera, f32 fov);
extern void FldLmapCameraMoveTo(u8 *task, s32 mode, s32 preset, f32 speed);
void FldLmapSkyState71009(void);
void FldLmapSkyState7100D(void);
extern u8 D_005F1EF8[];
extern u8 D_005F1FB8[];
extern u8 D_005F1FA8[];
extern u8 D_005F1FD0[];
extern u8 D_005F1FF0[];
extern u8 D_005F1E40[];
extern u8 D_005F1E60[];
extern u8 D_005F1E80[];
extern u8 D_005F1EA0[];
extern u8 D_005F1EC0[];
extern u8 D_005F1EE0[];
extern u8 D_005F1F10[];
extern u8 D_005F1F30[];
extern u8 D_005F1F50[];
extern u8 D_005F1F70[];
extern u8 D_005F1F90[];
extern u8 D_005F2010[];
extern u8 D_005F2030[];
extern u8 D_005F2050[];
extern u8 D_005F2070[];
extern u8 D_005F2090[];
extern s32 FldLmapScrollUpdate(u8 *task);
extern s32 FldLmapMarkerUpdate(u8 *task);
extern s32 FldLmapPathUpdate(u8 *task);
extern u8 D_005F2180[];
extern f32 D_005F20B0[];
extern f32 D_005F20B4[];
extern f32 D_005F20B8[];
extern f32 D_005F20BC[];
extern f32 D_005F20C0[];
extern f32 D_005F20C4[];
extern f32 D_005F2130[];
extern f32 D_005F2134[];
extern f32 D_005F2138[];
extern f32 D_005F213C[];
extern f32 D_005F2190[];
extern f32 D_005F2194[];
extern f32 D_005F2198[];
extern f32 D_005F219C[];
extern f32 D_005F21A0[];
extern f32 D_005F21A4[];
extern f32 D_005F1E20[];
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u8 D_00795E60[];
extern char iGpffff9f68;
extern char iGpffff9f70;
extern f32 iGpffff84a4;
extern f32 iGpffff8538;
void FldLmapDrawCornerMarks(u8 *work, u8 *position);
void FldLmapDrawSlotRow(u8 *work, u8 *position);
void FldLmapDrawSlotMarker(u8 *work, u8 *position, s32 slotIndex);
void FldLmapDrawSlotPair(u8 *work, u8 *position, s32 slotIndex);
void FldLmapDrawSlotIcon(u8 *work, u8 *position, s32 slotIndex);
void FldLmapDrawPanel(u8 *work, u8 *position, s32 slotIndex);
u8 *FldLmapMarkerTaskCreate(u8 *parent, s32 markerResource, u8 *slotResources);
void FldLmapMarkerSetTarget(u8 *task, s32 slotIndex, f32 speed);
u8 *FldLmapPathTaskCreate(u8 *parent);
void FldLmapCameraMoveTo(u8 *task, s32 mode, s32 preset, f32 speed);

/* Source unit: src/promoted/k_fldLmap.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_fldLmap.c; members 001866d0-00189550 */

extern s32 FldLmapUpdate(u8 *task);
typedef struct FldLmapMatrix {
    s32 words[16];
} FldLmapMatrix;
static inline f32 mulFp(f32 left, f32 right) { return left * right; }
// FUN_001866D0
/* Load calendar-dependent map sprite assets; return -1 after all sprite requests complete. */
s32 FldLmapLoadUpdate(u8 *task)
{
    s32 fileSize;
    u8 directoryPath[0x4C];
    s32 timeSlot;
    s32 state;
    s64 dateIndex;
    s64 dayEntry;
    s64 dayPhase;
    u8 *work;

    work = ((SdkTask *)task)->work;
    state = ((FldLmapLoadWork *)work)->state;
    switch (state) {
    case 0:
        dateIndex = (s16)datGetDateIndex();
        dayEntry = (s8)calGetDayEntryByPhase(dateIndex, datGetTimeSlot() & 0xFF);
        timeSlot = datGetTimeSlot() & 0xFF;
        if (datGetFlag(0x8A) == 1) {
            if ((s8)dayEntry == 1) {
                sprintf(directoryPath, D_005F1E40);
            } else {
                sprintf(directoryPath, D_005F1E60);
            }
        } else {
            dayPhase = (s8)dayEntry;
            if (dayPhase == 0) {
                if ((timeSlot & 0xFF) < 4) {
                    sprintf(directoryPath, D_005F1E80);
                } else {
                    sprintf(directoryPath, D_005F1EA0);
                }
            } else if (dayPhase == 2) {
                sprintf(directoryPath, D_005F1EC0);
            } else if (dayPhase == 1) {
                sprintf(directoryPath, D_005F1EE0);
            } else {
                kAssertFail(D_005F1EF8, 0xC5);
            }
        }
        func_00440b68(&iGpffff9f68, D_005F1EF8, 0xC8);
        ((FldLmapLoadWork *)work)->directory = H_Cdvd_AcquireDirectory(directoryPath, 1);
        ((FldLmapLoadWork *)work)->state = ((FldLmapLoadWork *)work)->state + 1;
        /* fallthrough */
    case 1:
        if (H_Cdvd_IsFileLoaded(((FldLmapLoadWork *)work)->directory) != 0) {
            /* measured: typing the retained access changes b210 output (normalized_diff 263); keep raw. */
            ((FldLmapWork *)(*(u8 **)(work + 8)))->sprites[5].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F10, &fileSize));
            /* measured: typing the retained access changes b210 output (normalized_diff 263); keep raw. */
            ((FldLmapWork *)(*(u8 **)(work + 8)))->sprites[6].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F30, &fileSize));
            /* measured: typing the retained access changes b210 output (normalized_diff 263); keep raw. */
            ((FldLmapWork *)(*(u8 **)(work + 8)))->sprites[7].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F50, &fileSize));
            /* measured: typing the retained access changes b210 output (normalized_diff 263); keep raw. */
            ((FldLmapWork *)(*(u8 **)(work + 8)))->sprites[8].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F70, &fileSize));
            ((FldLmapWork *)((u8 *)((FldLmapLoadWork *)work)->map))->sprites[9].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F90, &fileSize));
            ((FldLmapLoadWork *)work)->state = ((FldLmapLoadWork *)work)->state + 1;
        }
        break;
    case 2:
        /* measured: typing the retained access changes b210 output (normalized_diff 263); keep raw. */
        if ((hMaestroDecodeIsReady(((FldLmapWork *)(*(u8 **)(work + 8)))->sprites[5].value) != 0) && (hMaestroDecodeIsReady(((FldLmapWork *)(*(u8 **)(work + 8)))->sprites[6].value) != 0) && (hMaestroDecodeIsReady(((FldLmapWork *)(*(u8 **)(work + 8)))->sprites[7].value) != 0) && (hMaestroDecodeIsReady(((FldLmapWork *)(*(u8 **)(work + 8)))->sprites[8].value) != 0) && (hMaestroDecodeIsReady(((FldLmapWork *)((u8 *)((FldLmapLoadWork *)work)->map))->sprites[9].value) != 0)) {
            ((FldLmapLoadWork *)work)->state = ((FldLmapLoadWork *)work)->state + 1;
        }
        break;
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_00186A60
/* Signal asset completion to the map task and release the directory and loader work. */
void FldLmapLoadDestroy(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    ((FldLmapWork *)((u8 *)((FldLmapLoadWork *)work)->map))->assetsLoaded = 1;
    H_Cdvd_Destroy(((FldLmapLoadWork *)work)->directory);
    /* measured: typing the retained access changes b210 output (normalized_diff 5); keep raw. */
    jtbl_008873EC[0](*(void **)(task + 0x38));
}

/* measured re-triage: switch CFG candidate reproduces the main state/update
   path, but MWCC b210 still folds the retail mtc1 $0 + swc1 zero store to
   sw $0 and leaves the candidate 8 bytes short of the retail window. Best
   candidate: normalized_diff 103, object 456/464; discarded. */
// FUN_00186AC0
/* Animate a position horizontally after a delay; optionally adjust the other panel depth and signal completion. */
s32 FldLmapScrollUpdate(u8 *task)
{
    s32 *otherX;
    s32 *completionFlag;
    s32 delayFrames;
    s32 framesLeft;
    s32 state;
    u8 *work;

    work = ((SdkTask *)task)->work;
    state = ((FldLmapScrollWork *)work)->state;
    switch (state) {
    case 0:
        if (!((((FldLmapScrollWork *)work)->endX - ((FldLmapScrollWork *)work)->startX) <= 0.0f)) {
            ((FldLmapScrollWork *)work)->direction = -1.0f;
        } else {
            ((FldLmapScrollWork *)work)->direction = 1.0f;
        }
        ((FldLmapScrollWork *)work)->state = ((FldLmapScrollWork *)work)->state + 1;
    case 1:
        /* measured: typing the retained access changes b210 output (normalized_diff 235); keep raw. */
        delayFrames = *(s32 *)(work + 0x24);
        if (delayFrames > 0) {
            ((FldLmapScrollWork *)work)->delayFrames = delayFrames - 1;
            goto block_19;
        }
        if (((FldLmapScrollWork *)work)->direction < 0.0f) {
            /* measured: typing the retained access changes b210 output (normalized_diff 331..334); keep raw. */
            ((FldLmapPosition *)(*(u8 **)(work + 4)))->x.value = (*(f32 *)(work + 0x10) - ((FldLmapScrollWork *)work)->startX) * -sinf((iGpffff84a4 * (f32)*(s32 *)(work + 0x20)) / (f32)((FldLmapScrollWork *)work)->duration);
        } else {
            ((FldLmapPosition *)((u8 *)((FldLmapScrollWork *)work)->position))->x.value = (((FldLmapScrollWork *)work)->endX - ((FldLmapScrollWork *)work)->startX) * cosf((iGpffff84a4 * (f32)((FldLmapScrollWork *)work)->framesLeft) / (f32)((FldLmapScrollWork *)work)->duration);
        }
        /* measured: typing the retained access changes b210 output (normalized_diff 334); keep raw. */
        ((FldLmapPosition *)(*(u8 **)(work + 4)))->y.value = 0.0f;
        /* measured: typing the retained access changes b210 output (normalized_diff 332); keep raw. */
        framesLeft = *(s32 *)(work + 0x20);
        if (framesLeft > 0) {
            ((FldLmapScrollWork *)work)->framesLeft = framesLeft - 1;
            goto block_19;
        }
        ((FldLmapPosition *)((u8 *)((FldLmapScrollWork *)work)->position))->x.value = ((FldLmapScrollWork *)work)->endX;
        ((FldLmapPosition *)((u8 *)((FldLmapScrollWork *)work)->position))->y.value = 0.0f;
        otherX = (s32 *)((FldLmapScrollWork *)work)->otherPosition;
        if (otherX != NULL) {
            *otherX = 0xC3660000; /* -230.0f x */
        }
        completionFlag = ((FldLmapScrollWork *)work)->completionFlag;
        if (completionFlag != NULL) {
            *completionFlag = 1;
        }
        return -1;
block_19:
        ;
    default:
        return 0;
    }
}

// FUN_00186C90
void FldLmapScrollTaskDestroy(u8 *task)
{
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

// FUN_00186CC0
/* Create a delayed horizontal scroll with optional paired-position and completion outputs. */
u8 *FldLmapScrollTaskCreate(u8 *parent, u8 *position, f32 startX, f32 endX, u8 *otherPosition, u8 *completionFlag, s32 duration, s32 delayFrames)
{
    /* Indirect position slots retain the original alias/reload shape; both point to 12-byte positions. */
    u8 *work;
    u8 *task;
    u8 *positionSlot;
    u8 *otherPositionSlot;

    chkmemAllocSiteTag(D_005F1EF8, 0x175);
    work = (u8 *)D_008873F4[0](1, 0x2C, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = (u8 *)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F1FB8), 0xF, 0, 0, FldLmapScrollUpdate, FldLmapScrollTaskDestroy, (u8 *)(work));
    positionSlot = work + 4;
    ((FldLmapScrollWork *)work)->position = (FldLmapPosition *)position;
    ((FldLmapScrollWork *)work)->startX = startX;
    ((FldLmapScrollWork *)work)->endX = endX;
    otherPositionSlot = work + 8;
    ((FldLmapScrollWork *)work)->otherPosition = (FldLmapPosition *)otherPosition;
    ((FldLmapScrollWork *)work)->completionFlag = (s32 *)completionFlag;
    ((FldLmapScrollWork *)work)->duration = duration;
    ((FldLmapScrollWork *)work)->framesLeft = duration;
    ((FldLmapScrollWork *)work)->delayFrames = delayFrames;
    if (otherPosition != NULL) {
        ((FldLmapPosition *)(*(u8 **)positionSlot))->z.bits = 0x43960000; /* 300.0f depth */
        ((FldLmapPosition *)(*(u8 **)otherPositionSlot))->z.bits = 0x43C80000; /* 400.0f depth */
    }
    return task;
}

// FUN_00186E10
/* Choose the normal or selected draw list for each of the five map slots. */
/* measured: without opt_loop_invariants MWCC rematerializes the loop-invariant
 * constant 1 (addiu $a1, $zero, 1) inside the loop body at both store sites;
 * retail hoists it to the preheader. The pragma restores the hoist (nd 35 -> 0). */
/* measured: FldLmapSetSlotFlags MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
static void FldLmapSetSlotFlags(u8 *work)
{
    s32 slotIndex;

    slotIndex = 0;
    while (slotIndex < 5) {
        if ((u32)*(u32 *)work > 8U) {
            ((FldLmapWork *)work)->normalSlots[slotIndex] = 0;
            ((FldLmapWork *)work)->selectedSlots[slotIndex] = 0;
        } else {
            /* measured: typing the retained access changes b210 output (normalized_diff 108); keep raw. */
            if (*(s32 *)(work + 0xC) != slotIndex) {
                ((FldLmapWork *)work)->normalSlots[slotIndex] = 1;
            } else {
                ((FldLmapWork *)work)->normalSlots[slotIndex] = 0;
            }
            if (((FldLmapWork *)work)->selectedSlot == slotIndex) {
                ((FldLmapWork *)work)->selectedSlots[slotIndex] = 1;
            } else {
                ((FldLmapWork *)work)->selectedSlots[slotIndex] = 0;
            }
        }
        slotIndex += 1;
    }
}

/* measured: see annotation above. */
#pragma push
/* measured: byte-exact (953/953 instructions, 0 differing words).  The camera
   matrix copy is a 64-byte struct assignment (retail's 8 x two-word loop), the
   pad globals are arrays (absolute %hi/%lo, not gp), the local zeroing loop
   counts an unsigned n (bnez, not bgtz), and FldLmapSetSlotFlags is static so the
   caller keeps $a0 across it.  The two scroll updates address the panel slot
   as `off + (s32)st` so the index is the first addu operand, as retail has it.
   opt_loop_invariants hoists the case-0 constants. */
// FUN_00186EB0
/* Drive map loading, slot input, panel transitions, camera tasks, and exit-script dispatch. */
s32 FldLmapUpdate(u8 *task)
{
    u8 *parent;
    u8 *work;
    s32 slotIndex;
    u8 markerPosition[12];
    s32 fileSize;
    extern s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags);

    parent = task;
    work = ((SdkTask *)task)->work;
    if (*(u32 *)work > 4U) {
        {
            u8 *cursor;
            u32 bytesLeft;
            cursor = markerPosition;
            bytesLeft = 12;
            if (cursor != 0) {
                do {
                    *cursor++ = 0;
                    bytesLeft--;
                } while (bytesLeft != 0);
            }
        }
        FldLmapSetSlotFlags(work);
        /* measured: typing the retained access changes b210 output (normalized_diff 2750); keep raw. */
        *(f32 *)(work + 0x98) = 700.0f;
        FldLmapDrawCornerMarks(work, work + 0x90);
        ((Vec3 *)markerPosition)->z = (f32)590;
        for (slotIndex = 0; slotIndex < 5; slotIndex++) {
            if (((FldLmapWork *)work)->normalSlots[slotIndex] != 0) {
                FldLmapDrawSlotMarker(work, markerPosition, slotIndex);
                FldLmapDrawSlotPair(work, work + slotIndex * 12 + 0x9C, slotIndex);
            }
        }
        for (slotIndex = 0; slotIndex < 5; slotIndex++) {
            if (((FldLmapWork *)work)->selectedSlots[slotIndex] != 0) {
                FldLmapDrawSlotIcon(work, work + slotIndex * 12 + 0xD8, slotIndex);
            }
        }
        ((FldLmapWork *)work)->rowPosition.z.value = 500.0f;
        FldLmapDrawSlotRow(work, work + 0x90);
        if ((((FldLmapWork *)work)->assetsLoaded != 0) && (((FldLmapWork *)work)->panelsVisible != 0)) {
            if (((FldLmapWork *)work)->panelPositions[0].z.value >= ((FldLmapWork *)work)->panelPositions[1].z.value) {
                FldLmapDrawPanel(work, work + 0x114, ((FldLmapWork *)work)->panelSlots[0]);
                FldLmapDrawPanel(work, work + 0x120, ((FldLmapWork *)work)->panelSlots[1]);
            } else {
                FldLmapDrawPanel(work, work + 0x120, ((FldLmapWork *)work)->panelSlots[1]);
                FldLmapDrawPanel(work, work + 0x114, ((FldLmapWork *)work)->panelSlots[0]);
            }
        }
    }
    switch (((FldLmapWork *)work)->state) {
    case 0: {
        s32 slotIndex;
        f32 iconStartX = (f32)-427;
        f32 iconDepth = (f32)550;
        s32 pairStartXBits = 0xC3BB0000;
        s32 pairDepthBits = 0x44160000;
        for (slotIndex = 0; slotIndex < 5; slotIndex++) {
            ((FldLmapWork *)work)->normalPositions[slotIndex].x.bits = pairStartXBits;
            ((FldLmapWork *)work)->normalPositions[slotIndex].y.bits = 0;
            ((FldLmapWork *)work)->normalPositions[slotIndex].z.bits = pairDepthBits;
            ((FldLmapWork *)work)->selectedPositions[slotIndex].x.value = iconStartX;
            ((FldLmapWork *)work)->selectedPositions[slotIndex].y.bits = 0;
            ((FldLmapWork *)work)->selectedPositions[slotIndex].z.value = iconDepth;
        }
        ((FldLmapWork *)work)->panelsVisible = 1;
        ((FldLmapWork *)work)->panelOffsets[0] = -330.0f;
        ((FldLmapWork *)work)->panelOffsets[1] = -330.0f;
        ((FldLmapWork *)work)->panelPositions[0].x.value = -230.0f;
        ((FldLmapWork *)work)->panelPositions[0].y.bits = 0;
        ((FldLmapWork *)work)->panelPositions[0].z.value = 400.0f;
        ((FldLmapWork *)work)->panelPositions[1].x.value = -230.0f;
        ((FldLmapWork *)work)->panelPositions[1].y.bits = 0;
        ((FldLmapWork *)work)->panelPositions[1].z.value = 400.0f;
        ((FldLmapWork *)work)->marqueePosition.x.value = 36.0f;
        ((FldLmapWork *)work)->marqueePosition.y.bits = 0;
        ((FldLmapWork *)work)->marqueePosition.z.value = 200.0f;
        ((FldLmapWork *)work)->togglePanels = 1;
        ((FldLmapWork *)work)->state = ((FldLmapWork *)work)->state + 1;
    }
    /* fallthrough */
    case 1:
        ((FldLmapWork *)work)->camera = func_003e0f80();
        fieldSceneLoad(1, 1);
        fieldSceneRequestSecondaryRoom((s16)FldEnvStateFromCalendar(1, 1));
        func_00440b68(&iGpffff9f68, D_005F1EF8, 0x211);
        ((FldLmapWork *)work)->spriteDirectory = H_Cdvd_AcquireDirectory(D_005F1FD0, 1);
        func_00440b68(&iGpffff9f68, D_005F1EF8, 0x212);
        ((FldLmapWork *)work)->scriptDirectory = H_Cdvd_AcquireDirectory(D_005F1FF0, 0);
        ((FldLmapWork *)work)->state = ((FldLmapWork *)work)->state + 1;
    /* fallthrough */
    case 2: {
        if (fieldSceneLoadStep() == 0) {
            break;
        }
        if (H_Cdvd_IsFileLoaded(((FldLmapWork *)work)->spriteDirectory) == 0) {
            break;
        }
        if (H_Cdvd_IsFileLoaded(((FldLmapWork *)work)->scriptDirectory) == 0) {
            break;
        }
        /* measured: typing the retained access changes b210 output (normalized_diff 2757); keep raw. */
        *(FldLmapMatrix *)*(u8 **)(work + 0x18) = *(FldLmapMatrix *)MT_Scene_GetCameraResFirst();
        {
            u8 *camera = kwlnGetCamera();
            K_View_SetFov(camera, MT_Scene_GetCameraFov());
        }
        {
            u8 *camera = kwlnGetCamera();
            func_003e9cb0((s32)((RwObject *)camera)->parent, ((FldLmapWork *)work)->camera, 0);
        }
        ((FldLmapWork *)work)->sprites[0].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2010, &fileSize));
        ((FldLmapWork *)work)->sprites[2].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2030, &fileSize));
        ((FldLmapWork *)work)->sprites[3].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2050, &fileSize));
        ((FldLmapWork *)work)->sprites[1].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2070, &fileSize));
        ((FldLmapWork *)work)->sprites[4].value = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2090, &fileSize));
        /* measured: typing the retained access changes b210 output (normalized_diff 8); keep raw. */
        ((FldLmapWork *)work)->scriptTask.data = (u8 *)scrStartProcedureChecked(15, *(s32 *)(((FldLmapWork *)work)->scriptDirectory + 0x110), ((HCdvdRequest *)((FldLmapWork *)work)->scriptDirectory)->signedSize, 0);
        ((FldLmapWork *)work)->state = ((FldLmapWork *)work)->state + 1;
    }
    /* fallthrough */
    case 3:
        if (hMaestroDecodeIsReady(((FldLmapWork *)work)->sprites[0].value) == 0) {
            break;
        }
        if (hMaestroDecodeIsReady(((FldLmapWork *)work)->sprites[2].value) == 0) {
            break;
        }
        if (hMaestroDecodeIsReady(((FldLmapWork *)work)->sprites[3].value) == 0) {
            break;
        }
        if (hMaestroDecodeIsReady(((FldLmapWork *)work)->sprites[1].value) == 0) {
            break;
        }
        if (hMaestroDecodeIsReady(((FldLmapWork *)work)->sprites[4].value) == 0) {
            break;
        }
        if (kwlnTaskIsLinked(((FldLmapWork *)work)->scriptTask.data) == 1) {
            break;
        }
        /* measured: typing the retained access changes b210 output (normalized_diff 1798); keep raw. */
        H_Cdvd_Destroy(*(u8 **)(work + 0x1C));
        ((FldLmapWork *)work)->spriteDirectory = NULL;
        ((FldLmapWork *)work)->assetsLoaded = 0;
        chkmemAllocSiteTag(D_005F1EF8, 0x104);
        {
            u8 *loadWork = (u8 *)D_008873F4[0](1, 12, 0x40000);
            s32 loadTask;
            if (loadWork == NULL) {
                loadTask = 0;
            } else {
                loadTask = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F1FA8), 15, 0, 0, FldLmapLoadUpdate, FldLmapLoadDestroy, (u8 *)(loadWork));
                ((FldLmapLoadWork *)loadWork)->map = (FldLmapWork *)work;
            }
            ((FldLmapWork *)work)->loadTask.value = loadTask;
        }
        /* measured: typing the retained access changes b210 output (normalized_diff 1707); keep raw. */
        *(s32 *)(work + 0x140) = (s32)MT_Scene_GetRes(0x280A);
        ((FldLmapWork *)work)->slotResources[1].value = (s32)MT_Scene_GetRes(0x2809);
        ((FldLmapWork *)work)->slotResources[2].value = (s32)MT_Scene_GetRes(0x2806);
        ((FldLmapWork *)work)->slotResources[3].value = (s32)MT_Scene_GetRes(0x2808);
        ((FldLmapWork *)work)->slotResources[4].value = (s32)MT_Scene_GetRes(0x2807);
        ((FldLmapWork *)work)->slotResources[5].value = (s32)MT_Scene_GetRes(0x2805);
        /* measured: typing the retained access changes b210 output (normalized_diff 1633); keep raw. */
        *(u8 **)(work + 0x164) = FldLmapMarkerTaskCreate(parent, ((FldLmapWork *)work)->slotResources[0].value, work + 0x144);
        FldLmapMarkerSetTarget(((FldLmapWork *)work)->markerTask.data, ((FldLmapWork *)work)->selectedSlot, 0.0f);
        /* measured: typing the retained access changes b210 output (normalized_diff 1598); keep raw. */
        *(u8 **)(work + 0x168) = FldLmapPathTaskCreate(parent);
        /* measured: typing the retained access changes b210 output (normalized_diff 1609); keep raw. */
        FldLmapCameraMoveTo(((FldLmapWork *)work)->pathTask.data, *(s32 *)(work + 0xC), *(s32 *)(work + 0xC), 0.0f);
        if (sndRequestAreaTrack() == 0) {
            sndPlayAreaCue();
        }
        fadeBeginReturnTransition(1, 0);
        ((FldLmapWork *)work)->state = ((FldLmapWork *)work)->state + 1;
    /* fallthrough */
    case 4:
        if (fadeStatus() == 0) {
            break;
        }
        ((FldLmapWork *)work)->scrollTask.data = FldLmapScrollTaskCreate(parent, work + 0x90, -230.0f, 0.0f, NULL, NULL, 10, 0);
        ((FldLmapWork *)work)->state = ((FldLmapWork *)work)->state + 1;
    /* fallthrough */
    case 5:
        /* measured: typing the retained access changes b210 output (normalized_diff 1474); keep raw. */
        if (kwlnTaskIsLinked(*(u8 **)(work + 0x158)) == 1) {
            break;
        }
        FldLmapScrollTaskCreate(parent, work + 0x9C, -200.0f, 0.0f, NULL, NULL, 8, 0);
        FldLmapScrollTaskCreate(parent, work + 0xA8, -200.0f, 0.0f, NULL, NULL, 8, 2);
        FldLmapScrollTaskCreate(parent, work + 0xB4, -200.0f, 0.0f, NULL, NULL, 8, 4);
        FldLmapScrollTaskCreate(parent, work + 0xC0, -200.0f, 0.0f, NULL, NULL, 8, 6);
        FldLmapScrollTaskCreate(parent, work + 0xCC, -200.0f, 0.0f, NULL, NULL, 8, 8);
        FldLmapScrollTaskCreate(parent, work + 0xD8, -200.0f, 0.0f, NULL, NULL, 8, 0);
        FldLmapScrollTaskCreate(parent, work + 0xE4, -200.0f, 0.0f, NULL, NULL, 8, 2);
        FldLmapScrollTaskCreate(parent, work + 0xF0, -200.0f, 0.0f, NULL, NULL, 8, 4);
        FldLmapScrollTaskCreate(parent, work + 0xFC, -200.0f, 0.0f, NULL, NULL, 8, 6);
        ((FldLmapWork *)work)->scrollTask.data = FldLmapScrollTaskCreate(parent, work + 0x108, -200.0f, 0.0f, NULL, NULL, 8, 8);
        ((FldLmapWork *)work)->state = ((FldLmapWork *)work)->state + 1;
    /* fallthrough */
    case 6:
        if (kwlnTaskIsLinked(((FldLmapWork *)work)->scrollTask.data) == 1) {
            break;
        }
        ((FldLmapWork *)work)->state = ((FldLmapWork *)work)->state + 1;
    /* fallthrough */
    case 7:
        if (((FldLmapWork *)work)->enableToggle == 1) {
            if (((D_008C024E[0] & 4) != 0) || ((D_008C024E[0] & 1) != 0) || ((D_008C024E[0] & 8) != 0) || ((D_008C024E[0] & 2) != 0)) {
                ((FldLmapWork *)work)->panelsVisible = !(((FldLmapWork *)work)->togglePanels);
                ((FldLmapWork *)work)->togglePanels = !(((FldLmapWork *)work)->togglePanels);
            }
        }
        if ((D_008C024E[0] & 0x40) != 0) {
            s32 slotIndex;
            for (slotIndex = 0; slotIndex < 5; slotIndex++) {
                if (((FldLmapWork *)work)->selectedSlot == slotIndex) {
                    FldLmapScrollTaskCreate(parent, work + slotIndex * 12 + 0xD8, 0.0f, -300.0f, NULL, NULL, 10, 6);
                } else {
                    ((FldLmapWork *)work)->scrollTask.data = FldLmapScrollTaskCreate(parent, work + slotIndex * 12 + 0x9C, 0.0f, -230.0f, NULL, NULL, 10, 0);
                }
            }
            ((FldLmapWork *)work)->togglePanels = 0;
            ((FldLmapWork *)work)->state = 8;
            sdkSndStartStream(0, 0, 0, 1);
            break;
        } else {
            if ((D_008C0252[0] & 0x1000) != 0) {
                sdkSndStartStream(0, 0, 0, 0);
                ((FldLmapWork *)work)->selectedSlot = ((FldLmapWork *)work)->selectedSlot - 1;
                ((FldLmapWork *)work)->selectionDelay = 0;
            } else if ((D_008C0252[0] & 0x4000) != 0) {
                sdkSndStartStream(0, 0, 0, 0);
                ((FldLmapWork *)work)->selectedSlot = ((FldLmapWork *)work)->selectedSlot + 1;
                ((FldLmapWork *)work)->selectionDelay = 0;
            }
            /* measured: typing the retained access changes b210 output (normalized_diff 1609); keep raw. */
            if (*(s32 *)(work + 0xC) < 0) {
                ((FldLmapWork *)work)->selectedSlot = 4;
            }
            /* measured: typing the retained access changes b210 output (normalized_diff 1609); keep raw. */
            if (*(s32 *)(work + 0xC) > 4) {
                ((FldLmapWork *)work)->selectedSlot = 0;
            }
            /* measured: typing the retained access changes b210 output (normalized_diff 730..1609); keep raw. */
            if (*(s32 *)(work + 0x10) != *(s32 *)(work + 0xC)) {
                ((FldLmapWork *)work)->selectionDelay = ((FldLmapWork *)work)->selectionDelay + 1;
            }
            /* measured: typing the retained access changes b210 output (normalized_diff 1609); keep raw. */
            FldLmapMarkerSetTarget(((FldLmapWork *)work)->markerTask.data, *(s32 *)(work + 0xC), 0.0f);
            /* measured: typing the retained access changes b210 output (normalized_diff 696); keep raw. */
            if (*(s32 *)(work + 0x14) > 5) {
                /* measured: typing the retained access changes b210 output (normalized_diff 682..1609); keep raw. */
                ((s32 *)(work + 0x80))[*(s32 *)(work + 0x7C)] = *(s32 *)(work + 0xC);
                {
                    /* measured: typing the retained access changes b210 output (normalized_diff 682); keep raw. */
                    s32 panelIndex = *(s32 *)(work + 0x7C);
                    s32 otherPanel = !panelIndex;
                    FldLmapScrollTaskCreate(parent, work + panelIndex * 12 + 0x114, -230.0f, 0.0f, work + otherPanel * 12 + 0x114, work + 0x170, 8, 0);
                }
                ((f32 *)(work + 0x88))[((FldLmapWork *)work)->nextPanel] = -330.0f;
                ((FldLmapWork *)work)->nextPanel = !(((FldLmapWork *)work)->nextPanel);
                /* measured: typing the retained access changes b210 output (normalized_diff 730..1609); keep raw. */
                FldLmapCameraMoveTo(((FldLmapWork *)work)->pathTask.data, *(s32 *)(work + 0x10), *(s32 *)(work + 0xC), 3.0f);
                ((FldLmapWork *)work)->previousSlot = ((FldLmapWork *)work)->selectedSlot;
                ((FldLmapWork *)work)->selectionDelay = 0;
                ((FldLmapWork *)work)->marqueePosition.x.value = 0.0f;
            }
            /* measured: typing the retained access changes b210 output (normalized_diff 540); keep raw. */
            if (*(s32 *)(work + 0x16C) == 0) {
                /* measured: typing the retained access changes b210 output (normalized_diff 682); keep raw. */
                s32 panelOffset = !(*(s32 *)(work + 0x7C)) * 4;
                u8 *panelCursor = (u8 *)(panelOffset + (s32)work);

                /* measured: typing the retained access changes b210 output (normalized_diff 508); keep raw. */
                if (*(f32 *)(panelCursor + 0x88) < 0.0f) {
                    /* measured: typing the retained access changes b210 output (normalized_diff 502); keep raw. */
                    if (*(s32 *)(work + 0x174) == 0) {
                        /* measured: typing the retained access changes b210 output (normalized_diff 508); keep raw. */
                        *(f32 *)(panelCursor + 0x88) = *(f32 *)(panelCursor + 0x88) + 1.0f;
                    }
                } else {
                    ((FldLmapWork *)work)->slideDelay = 90;
                    ((FldLmapWork *)work)->slideDirection = 1;
                }
            } else {
                s32 panelOffset = !(((FldLmapWork *)work)->nextPanel) * 4;
                u8 *panelCursor = (u8 *)(panelOffset + (s32)work);

                /* measured: typing the retained access changes b210 output (normalized_diff 508); keep raw. */
                if (*(f32 *)(panelCursor + 0x88) > -330.0f) {
                    if (((FldLmapWork *)work)->slideDelay == 0) {
                        ((FldLmapWork *)work)->panelOffsets[!((FldLmapWork *)work)->nextPanel] = ((FldLmapWork *)work)->panelOffsets[!((FldLmapWork *)work)->nextPanel] - 1.0f;
                    }
                } else {
                    ((FldLmapWork *)work)->slideDelay = 90;
                    ((FldLmapWork *)work)->slideDirection = 0;
                }
            }
            /* measured: typing the retained access changes b210 output (normalized_diff 502); keep raw. */
            if (*(s32 *)(work + 0x174) > 0) {
                ((FldLmapWork *)work)->slideDelay = ((FldLmapWork *)work)->slideDelay - 1;
            }
            /* measured: typing the retained access changes b210 output (normalized_diff 343); keep raw. */
            if (*(s32 *)(work + 0x170) != 0) {
                ((FldLmapWork *)work)->slideDirection = 0;
                ((FldLmapWork *)work)->scrollComplete = 0;
                ((FldLmapWork *)work)->slideDelay = 0;
            }
            /* measured: typing the retained access changes b210 output (normalized_diff 323); keep raw. */
            *(f32 *)(work + 0x12C) = *(f32 *)(work + 0x12C) - 2.0f;
            {
                s32 visiblePanel = !(((FldLmapWork *)work)->nextPanel);
                s32 panelSlot = ((s32 *)(work + 0x80))[visiblePanel];
                /* measured: typing the retained access changes b210 output (normalized_diff 323); keep raw. */
                if (*(f32 *)(work + 0x12C) < D_005F1E20[panelSlot]) {
                    ((FldLmapWork *)work)->marqueePosition.x.value = 36.0f;
                }
            }
        }
        break;
    case 8:
        if (kwlnTaskIsLinked(((FldLmapWork *)work)->scrollTask.data) == 1) {
            break;
        }
        FldLmapScrollTaskCreate(parent, work + 0x90, 0.0f, -230.0f, NULL, NULL, 10, 0);
        FldLmapScrollTaskCreate(parent, work + 0x114, 0.0f, -230.0f, NULL, NULL, 10, 0);
        FldLmapScrollTaskCreate(parent, work + 0x120, 0.0f, -230.0f, NULL, NULL, 10, 0);
        fadeBeginTransition(1, 0);
        ((FldLmapWork *)work)->state = ((FldLmapWork *)work)->state + 1;
        break;
    case 9:
        if (fadeStatus() == 0) {
            break;
        }
        if (((FldLmapWork *)work)->assetsLoaded == 0) {
            break;
        }
        if (((FldLmapWork *)work)->enableToggle == 0) {
            /* measured: typing the retained access changes b210 output (normalized_diff 8); keep raw. */
            scrStartProcedureChecked(15, *(s32 *)(((FldLmapWork *)work)->scriptDirectory + 0x110), ((HCdvdRequest *)((FldLmapWork *)work)->scriptDirectory)->signedSize, ((FldLmapWork *)work)->selectedSlot + 1);
        }
        ((FldLmapWork *)work)->state = ((FldLmapWork *)work)->state + 1;
        break;
    case 10:
        break;
    default:
        break;
    }
    return 0;
}

#pragma pop
// FUN_00187DA0
/* Release map sprites, scene resources, saved camera, and task work. */
void FldLmapDestroy(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[0].data);
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[2].data);
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[3].data);
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[1].data);
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[4].data);
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[5].data);
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[6].data);
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[7].data);
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[8].data);
    sdkSpriteRelease(((FldLmapWork *)work)->sprites[9].data);
    fieldSceneUnload();
    func_003e0f40(((FldLmapWork *)work)->camera);
    H_Cdvd_Destroy(((FldLmapWork *)work)->scriptDirectory);
    /* measured: typing the retained access changes b210 output (normalized_diff 5); keep raw. */
    jtbl_008873EC[0](*(void **)(task + 0x38));
}

// FUN_00187E80
/* Create the map task with an initial slot and optional panel-toggle input. */
u8 *FldLmapCreate(u8 *parent, s32 selectedSlot, s32 enableToggle)
{
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(D_005F1EF8, 0x343);
    work = (u8 *)D_008873F4[0](1, 0x178, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = (u8 *)kwlnTaskCreateChild((void *)(parent), (const void *)(&iGpffff9f70), 0xF, 0, 0, FldLmapUpdate, FldLmapDestroy, (u8 *)(work));
    ((FldLmapWork *)work)->selectedSlot = selectedSlot;
    ((FldLmapWork *)work)->previousSlot = -1;
    ((FldLmapWork *)work)->enableToggle = enableToggle;
    return task;
}

// FUN_00187F50
/* Install the shared map sprite render state and the 0x71009 SKY state. */
void FldLmapSkyState71009(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x71009);
}

// FUN_00188030
/* Install the shared map sprite render state and the 0x7100D SKY state. */
void FldLmapSkyState7100D(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x7100D);
}

// FUN_00188110
/* Install the panel mask render state and the 0x72001 SKY state. */
void FldLmapSkyState72001(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    tbl[0](1, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x72001);
}

/* measured re-triage: corrected generated-style candidate has the complete
   color-call setup and exact size, but MWCC b210 serialises the retail
   constant-before-load and cross-chain float scheduling. Best candidate:
   normalized_diff 154, object 288/288; discarded. */
// FUN_00188200
/* Draw the two corner marks relative to the supplied screen position. */
void FldLmapDrawCornerMarks(u8 *work, u8 *position)
{
    f32 x;
    f32 y;

    x = -32.0f;
    x += ((Vec3 *)position)->x;
    /* measured: typing the retained access changes b210 output (normalized_diff 151); keep raw. */
    y = -7.0f + *(f32 *)(position + 4);
    /* measured: typing the retained access changes b210 output (normalized_diff 171..227); keep raw. */
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8), 0xFFFFFF, 0xFF, 0, *(void **)(work + 0x24), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    x = -32.0f;
    x += ((Vec3 *)position)->x;
    y = 224.0f + ((Vec3 *)position)->y;
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, ((Vec3 *)position)->z, 0xFFFFFF, 0xFF, 1, ((FldLmapWork *)work)->sprites[0].pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

/* Exact under MWCC b210/O2: preserve the float input view and associate the
   column offset before adding the caller's x coordinate. */
// FUN_00188320
/* Queue the row render state and draw the five two-column slot backgrounds. */
void FldLmapDrawSlotRow(u8 *work, u8 *position)
{
    s32 rowIndex;
    s32 columnIndex;
    u8 *queueNode;
    f32 x;
    f32 y;
    f32 rowOffset;
    const f32 *coordinates;

    coordinates = (const f32 *)position;
    queueNode = PrimAllocQueueNode();
    *(void (**)(void))(queueNode + 8) = FldLmapSkyState71009;
    ((PrimQueueNode *)queueNode)->argument.handle = 0;
    PrimAppendNode(D_00795E60, queueNode);
    x = -44.0f;
    x += ((Vec3 *)position)->x;
    /* measured: typing the retained access changes b210 output (normalized_diff 371); keep raw. */
    y = -7.0f + *(f32 *)(position + 4);
    sdkSpriteDrawQueued(
        (f32)(s32)x,
        (f32)(s32)y,
        /* measured: typing the retained access changes b210 output (normalized_diff 471); keep raw. */
        *(f32 *)(position + 8) - 10.0f,
        0x313131,
        0xFF,
        0,
        /* measured: typing the retained access changes b210 output (normalized_diff 392); keep raw. */
        *(void **)(work + 0x2C),
        0,
        0,
        0,
        0.0f,
        1.0f,
        1.0f,
        D_00795E60);
    x = -44.0f;
    x += ((Vec3 *)position)->x;
    /* measured: typing the retained access changes b210 output (normalized_diff 371); keep raw. */
    y = 224.0f + *(f32 *)(position + 4);
    sdkSpriteDrawQueued(
        (f32)(s32)x,
        (f32)(s32)y,
        /* measured: typing the retained access changes b210 output (normalized_diff 471); keep raw. */
        *(f32 *)(position + 8) - 10.0f,
        0x313131,
        0xFF,
        1,
        /* measured: typing the retained access changes b210 output (normalized_diff 392); keep raw. */
        *(void **)(work + 0x2C),
        0,
        0,
        0,
        0.0f,
        1.0f,
        1.0f,
        D_00795E60);
    rowIndex = 0;
    while (rowIndex < 5) {
        columnIndex = 0;
        rowOffset = 102.0f * (f32)rowIndex;
        while (columnIndex < 2) {
            x = 93.0f * (f32)columnIndex + (-5.0f + coordinates[0]);
            y = -40.0f + ((Vec3 *)position)->y + rowOffset;
            sdkSpriteDrawQueued(
                (f32)(s32)x,
                (f32)(s32)y,
                ((Vec3 *)position)->z,
                0x393939,
                0xFF,
                3,
                ((FldLmapWork *)work)->sprites[2].pointer,
                1,
                0,
                0,
                0.0f,
                1.0f,
                1.0f,
                D_00795E60);
            columnIndex += 1;
        }
        rowIndex += 1;
    }
}

// FUN_00188590
/* Draw one slot marker using the interleaved per-slot position table. */
void FldLmapDrawSlotMarker(u8 *work, u8 *position, s32 slotIndex)
{
    /* Linker-split float symbols address interleaved records; their full table extent is not established here. */
    s32 tableOffset;
    u8 *queueNode;
    f32 depth;
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void (*)(void))FldLmapSkyState7100D;
    ((PrimQueueNode *)queueNode)->argument.handle = 0;
    PrimAppendNode(D_00795E60, queueNode);
    tableOffset = slotIndex * 0x18;
    depth = ((Vec3 *)position)->z;
    sdkSpriteDrawQueued((f32)(s32)(((Vec3 *)position)->x + *(f32 *)((u8 *)D_005F20B0 + tableOffset)), (f32)(s32)(((Vec3 *)position)->y + *(f32 *)((u8 *)D_005F20B4 + tableOffset)), depth, 0xFF0000, 2, slotIndex, ((FldLmapWork *)work)->sprites[4].pointer, 0, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

/* measured re-triage: corrected two-call body has the expected setup and
   near-retail size, but MWCC b210 sinks the f14 load below the integer
   arguments and does not interleave the f13 chain. Best candidate:
   normalized_diff 82, object 344/352; discarded. */
// FUN_00188690
/* Draw the normal slot label and its paired decoration. */
void FldLmapDrawSlotPair(u8 *work, u8 *position, s32 slotIndex)
{
    /* Linker-split float symbols address interleaved records; their full table extent is not established here. */
    s32 tableOffset;
    f32 y;
    f32 x;

    tableOffset = slotIndex * 0x18;
    x = ((Vec3 *)position)->x + *(f32 *)((u8 *)D_005F20B8 + tableOffset);
    /* measured: typing the retained access changes b210 output (normalized_diff 257); keep raw. */
    y = *(f32 *)(position + 4) + *(f32 *)((u8 *)D_005F20BC + tableOffset);
    /* measured: typing the retained access changes b210 output (normalized_diff 257); keep raw. */
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8), 0xFFFF81, 0xFF, 7, ((FldLmapWork *)work)->sprites[4].pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    x = ((Vec3 *)position)->x + *(f32 *)((u8 *)D_005F20C0 + tableOffset);
    y = ((Vec3 *)position)->y + *(f32 *)((u8 *)D_005F20C4 + tableOffset);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, ((Vec3 *)position)->z, 0xEC7C00, 0xFF, slotIndex + 7, ((FldLmapWork *)work)->sprites[1].pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

/* measured re-triage: corrected two-call body has exact size, but MWCC b210
   sinks the f14 load below the integer arguments and serialises the f13
   chain. Best candidate: normalized_diff 79, object 336/336; discarded. */
// FUN_001887F0
/* Draw the selected slot background and label. */
void FldLmapDrawSlotIcon(u8 *work, u8 *position, s32 slotIndex)
{
    /* Linker-split float symbols address interleaved records; their full table extent is not established here. */
    s32 tableOffset;
    f32 y;
    f32 x;

    tableOffset = slotIndex * 0x10;
    x = ((Vec3 *)position)->x + *(f32 *)((u8 *)D_005F2130 + tableOffset);
    /* measured: typing the retained access changes b210 output (normalized_diff 253); keep raw. */
    y = *(f32 *)(position + 4) + *(f32 *)((u8 *)D_005F2134 + tableOffset);
    /* measured: typing the retained access changes b210 output (normalized_diff 254); keep raw. */
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8), 0x313131, 0xFF, 6, ((FldLmapWork *)work)->sprites[4].pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    x = ((Vec3 *)position)->x + *(f32 *)((u8 *)D_005F2138 + tableOffset);
    y = ((Vec3 *)position)->y + *(f32 *)((u8 *)D_005F213C + tableOffset);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, ((Vec3 *)position)->z, 0xFFFFFF, 0xFF, slotIndex + 7, ((FldLmapWork *)work)->sprites[1].pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

// FUN_00188940
/* Draw a clipped content panel using its independently scrolling horizontal offset. */
void FldLmapDrawPanel(u8 *work, u8 *position, s32 slotIndex)
{
    f32 x;
    f32 contentX;
    f32 y;
    u8 *cursor;
    u8 *queueNode;
    s32 offset;

    cursor = PrimAllocQueueNode();
    *(void (**)(void))(cursor + 8) = (void (*)(void))FldLmapSkyState71009;
    ((PrimQueueNode *)cursor)->argument.handle = 0;
    PrimAppendNode(D_00795E60, cursor);
    x = -45.0f;
    x += ((Vec3 *)position)->x;
    /* measured: typing the retained access changes b210 output (normalized_diff 491); keep raw. */
    y = -5.0f + *(f32 *)(position + 4);
    /* measured: typing the retained access changes b210 output (normalized_diff 504); keep raw. */
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8) - 10.0f, 0xFF0000, 0xFF, 0, *(void **)(work + 0x2C), 0, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    x = -45.0f;
    x += ((Vec3 *)position)->x;
    /* measured: typing the retained access changes b210 output (normalized_diff 491); keep raw. */
    y = 224.0f + *(f32 *)(position + 4);
    /* measured: typing the retained access changes b210 output (normalized_diff 504); keep raw. */
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8) - 10.0f, 0xFF0000, 0xFF, 1, ((FldLmapWork *)work)->sprites[2].pointer, 0, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    queueNode = PrimAllocQueueNode();
    *(void (**)(void))(queueNode + 8) = (void (*)(void))FldLmapSkyState72001;
    ((PrimQueueNode *)queueNode)->argument.handle = 0;
    PrimAppendNode(D_00795E60, queueNode);
    x = 185.0f;
    x += ((Vec3 *)position)->x;
    y = 0.0f;
    /* measured: typing the retained access changes b210 output (normalized_diff 504); keep raw. */
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8) - 10.0f, 0xFFFFFF, 0, 7, ((FldLmapWork *)work)->sprites[3].pointer, 0, 0, 0, 0, iGpffff8538, 1.0f, D_00795E60);
    offset = (slotIndex ^ ((FldLmapWork *)work)->panelSlots[0]) != 0;
    offset *= 4;
    cursor = (u8 *)(offset + (s32)work);
    /* measured: typing the retained access changes b210 output (normalized_diff 2); keep raw. */
    y = *(f32 *)(cursor + 0x88);
    contentX = ((Vec3 *)position)->x - 1.0f;
    contentX += y;
    y = ((Vec3 *)position)->y;
    y -= 1.0f;
    offset = slotIndex * 4;
    cursor = (u8 *)(offset + (s32)work);
    /* measured: typing the retained access changes b210 output (normalized_diff 2); keep raw. */
    sdkSpriteDrawQueued((f32)(s32)contentX, (f32)(s32)y, ((Vec3 *)position)->z, 0xFFFFFF, 0xFF, 0, *(void **)(cursor + 0x38), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

// FUN_00188BE0
/* Show the selected scene resource and move the map marker toward its target position. */
/* measured: without opt_loop_invariants MWCC rematerializes the loop-invariant
 * ~2 mask (addiu $v1, $zero, -3) inside the loop body; retail hoists it to the
 * preheader. The pragma restores the hoist. */
s32 FldLmapMarkerUpdate(u8 *task)
{
    Vec3 direction;
    Vec3 position;
    f32 coordinate;
    s32 targetOffset;
    s32 state;
    s32 slotIndex;
    u8 *work;
    u8 *cursor;
    u8 *otherResource;
    u8 *selectedResource;

    work = ((SdkTask *)task)->work;
    slotIndex = 0;
    while (slotIndex < 5) {
        if (slotIndex == ((FldLmapMarkerWork *)work)->selectedSlot) {
            selectedResource = ((FldLmapMarkerWork *)work)->slotResources[slotIndex];
            ((ResrcRecord *)(selectedResource))->unk28 = ((ResrcRecord *)(selectedResource))->unk28 | 2;
        } else {
            otherResource = ((FldLmapMarkerWork *)work)->slotResources[slotIndex];
            ((ResrcRecord *)(otherResource))->unk28 = ((ResrcRecord *)(otherResource))->unk28 & ~2;
        }
        slotIndex += 1;
    }
    state = ((FldLmapMarkerWork *)work)->state;
    switch (state) {
    case 0:
        ((FldLmapMarkerWork *)work)->state = state + 1;
        break;
    case 1:
        break;
    case 2:
        /* measured: typing the retained access changes b210 output (normalized_diff 571); keep raw. */
        cursor = mdlGetMatrix((s32)((ResrcRecord *)(*(u8 **)(work + 4)))->slotHandle[1]);
        coordinate = ((RwMatrixTag *)cursor)->pos.x;
        /* measured: typing the retained access changes b210 output (normalized_diff 570); keep raw. */
        targetOffset = *(s32 *)(work + 0x58) * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        /* measured: typing the retained access changes b210 output (normalized_diff 570); keep raw. */
        direction.x = *(f32 *)(cursor + 0xC) - coordinate;
        /* measured: typing the retained access changes b210 output (normalized_diff 571); keep raw. */
        cursor = mdlGetMatrix((s32)((ResrcRecord *)(*(u8 **)(work + 4)))->slotHandle[1]);
        coordinate = ((RwMatrixTag *)cursor)->pos.y;
        /* measured: typing the retained access changes b210 output (normalized_diff 570); keep raw. */
        targetOffset = *(s32 *)(work + 0x58) * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        /* measured: typing the retained access changes b210 output (normalized_diff 567); keep raw. */
        direction.y = *(f32 *)(cursor + 0x10) - coordinate;
        /* measured: typing the retained access changes b210 output (normalized_diff 571); keep raw. */
        cursor = mdlGetMatrix((s32)((ResrcRecord *)(*(u8 **)(work + 4)))->slotHandle[1]);
        coordinate = ((RwMatrixTag *)cursor)->pos.z;
        /* measured: typing the retained access changes b210 output (normalized_diff 570); keep raw. */
        targetOffset = *(s32 *)(work + 0x58) * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        /* measured: typing the retained access changes b210 output (normalized_diff 565); keep raw. */
        direction.z = *(f32 *)(cursor + 0x14) - coordinate;
        RwV3dNormalize(&direction.x, &direction.x);
        direction.x = direction.x * ((FldLmapMarkerWork *)work)->speed;
        direction.y = direction.y * ((FldLmapMarkerWork *)work)->speed;
        direction.z = direction.z * ((FldLmapMarkerWork *)work)->speed;
        /* measured: typing the retained access changes b210 output (normalized_diff 571); keep raw. */
        cursor = mdlGetMatrix((s32)((ResrcRecord *)(*(u8 **)(work + 4)))->slotHandle[1]);
        coordinate = ((RwMatrixTag *)cursor)->pos.x;
        position.x = direction.x + coordinate;
        /* measured: typing the retained access changes b210 output (normalized_diff 571); keep raw. */
        cursor = mdlGetMatrix((s32)((ResrcRecord *)(*(u8 **)(work + 4)))->slotHandle[1]);
        coordinate = ((RwMatrixTag *)cursor)->pos.y;
        position.y = direction.y + coordinate;
        /* measured: typing the retained access changes b210 output (normalized_diff 571); keep raw. */
        cursor = mdlGetMatrix((s32)((ResrcRecord *)(*(u8 **)(work + 4)))->slotHandle[1]);
        coordinate = ((RwMatrixTag *)cursor)->pos.z;
        position.z = direction.z + coordinate;
        targetOffset = ((FldLmapMarkerWork *)work)->targetSlot * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        /* measured: typing the retained access changes b210 output (normalized_diff 570); keep raw. */
        direction.x = *(f32 *)(cursor + 0xC) - position.x;
        targetOffset = ((FldLmapMarkerWork *)work)->targetSlot * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        direction.y = ((FldLmapMarkerWork *)work)->positions[((FldLmapMarkerWork *)work)->targetSlot].y - position.y;
        targetOffset = ((FldLmapMarkerWork *)work)->targetSlot * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        direction.z = ((FldLmapMarkerWork *)work)->positions[((FldLmapMarkerWork *)work)->targetSlot].z - position.z;
        RwV3dNormalize(&direction.x, &direction.x);
        if (((FldLmapMarkerWork *)work)->direction.x * direction.x + ((FldLmapMarkerWork *)work)->direction.y * direction.y + ((FldLmapMarkerWork *)work)->direction.z * direction.z <= 0.0f) {
            targetOffset = ((FldLmapMarkerWork *)work)->targetSlot * 0xC;
            cursor = (u8 *)(targetOffset + (s32)work);
            /* measured: typing the retained access changes b210 output (normalized_diff 2); keep raw. */
            position = *(Vec3 *)(cursor + 0xC);
            ((FldLmapMarkerWork *)work)->selectedSlot = ((FldLmapMarkerWork *)work)->targetSlot;
            ((FldLmapMarkerWork *)work)->targetSlot = -1;
            ((FldLmapMarkerWork *)work)->state = 1;
        }
        mdlTranslateMatrix((RwMatrix *)((ResrcRecord *)(((FldLmapMarkerWork *)work)->marker.data))->slotHandleValue[1], (const RwV3d *)&position, 0);
        break;
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}

/* measured: see annotation above. */
// FUN_00188EF0
void FldLmapMarkerTaskDestroy(u8 *task)
{
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

// FUN_00188F20
/* Snapshot the five slot-resource positions and create the map-marker task. */
u8 *FldLmapMarkerTaskCreate(u8 *parent, s32 markerResource, u8 *slotResources)
{
    /* Each resource contributes one 12-byte position copied from its model matrix translation. */
    u8 *task;
    u8 *work;
    u8 *matrix;
    s32 slotIndex;

    chkmemAllocSiteTag(D_005F1EF8, 0x622);
    work = (u8 *)D_008873F4[0](1, 0x60, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = (u8 *)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F2180), 0xF, 0, 0, FldLmapMarkerUpdate, FldLmapMarkerTaskDestroy, (u8 *)(work));
    ((FldLmapMarkerWork *)work)->marker.value = markerResource;
    ((FldLmapMarkerWork *)work)->slotResources = (u8 **)slotResources;
    ((FldLmapMarkerWork *)work)->targetSlot = -1;
    ((FldLmapMarkerWork *)work)->selectedSlot = -1;
    slotIndex = 0;
    while (slotIndex < 5) {
        matrix = mdlGetMatrix((s32)((ResrcRecord *)(((u8 **)slotResources)[slotIndex]))->slotHandle[1]);
        ((FldLmapMarkerWork *)work)->positions[slotIndex] = *(Vec3 *)&((RwMatrixTag *)(matrix))->pos;
        slotIndex += 1;
    }
    return task;
}

// FUN_00189060
/* Move or snap the marker to a slot; speed zero selects the immediate path. */
void FldLmapMarkerSetTarget(u8 *task, s32 slotIndex, f32 speed)
{
    f32 *direction;
    s32 state;
    u8 *work;
    work = ((SdkTask *)task)->work;
    ((FldLmapMarkerWork *)work)->speed = speed;
    state = ((FldLmapMarkerWork *)work)->state;
    if (((state != 1) || (((FldLmapMarkerWork *)work)->selectedSlot != slotIndex)) && ((state != 2) || (((FldLmapMarkerWork *)work)->targetSlot != slotIndex))) {
        if (speed != 0.0f) {
            /* measured: typing the retained access changes b210 output (normalized_diff 276); keep raw. */
            *(s32 *)(work + 0x58) = slotIndex;
            ((FldLmapMarkerWork *)work)->selectedSlot = -1;
            /* measured: typing the retained access changes b210 output (normalized_diff 276..277); keep raw. */
            ((FldLmapMarkerWork *)work)->direction.x = *(f32 *)((u8 *)(*(s32 *)(work + 0x58) * 0xC) + (u32)work + 0xC) - ((RwMatrixTag *)(mdlGetMatrix(((ResrcRecord *)(*(u8 **)(work + 4)))->slotHandleValue[1])))->pos.x;
            /* measured: typing the retained access changes b210 output (normalized_diff 274..277); keep raw. */
            ((FldLmapMarkerWork *)work)->direction.y = *(f32 *)((u8 *)(*(s32 *)(work + 0x58) * 0xC) + (u32)work + 0x10) - ((RwMatrixTag *)(mdlGetMatrix(((ResrcRecord *)(*(u8 **)(work + 4)))->slotHandleValue[1])))->pos.y;
            /* measured: typing the retained access changes b210 output (normalized_diff 2); keep raw. */
            ((FldLmapMarkerWork *)work)->direction.z = *(f32 *)((u8 *)(((FldLmapMarkerWork *)work)->targetSlot * 0xC) + (u32)work + 0x14) - ((RwMatrixTag *)(mdlGetMatrix(((ResrcRecord *)(((FldLmapMarkerWork *)work)->marker.data))->slotHandleValue[1])))->pos.z;
            direction = (f32 *)(work + 0x48);
            RwV3dNormalize(direction, direction);
            ((FldLmapMarkerWork *)work)->state = 2;
            return;
        }
        ((FldLmapMarkerWork *)work)->targetSlot = -1;
        ((FldLmapMarkerWork *)work)->selectedSlot = slotIndex;
        mdlTranslateMatrix((RwMatrix *)((ResrcRecord *)(((FldLmapMarkerWork *)work)->marker.data))->slotHandleValue[1], (const RwV3d *)(work + (slotIndex * 0xC) + 0xC), 0);
    }
}

// FUN_001891D0
/* Interpolate camera eye and target toward a slot pose, then snap at the final frame. */
s32 FldLmapPathUpdate(u8 *task)
{
    /* Eye/target constants are interior linker aliases in interleaved 24-byte pose records. */
    f32 direction[3];
    f32 progress;
    f32 targetDistance;
    f32 eyeDistance;
    s32 eyeOffset;
    s32 targetOffset;
    s32 nextFrame;
    s32 state;
    u8 *work;
    u8 *cameraPose;
    u8 *target;
    u8 *eye;

    work = ((SdkTask *)task)->work;
    kwlnGetCamera();
    state = ((FldLmapPathWork *)work)->state;
    switch (state) {
    case 0:
        ((FldLmapPathWork *)work)->state = state + 1;
        break;
    case 1:
        break;
    case 2:
        /* measured: typing the retained access changes b210 output (normalized_diff 543..624); keep raw. */
        progress = sinf((iGpffff84a4 * (f32)*(s32 *)(work + 0x24)) / (f32)*(s32 *)(work + 0x28));
        /* measured: typing the retained access changes b210 output (normalized_diff 512); keep raw. */
        eyeOffset = *(s32 *)(work + 0x30) * 0x18;
        /* measured: typing the retained access changes b210 output (normalized_diff 504); keep raw. */
        direction[0] = *(f32 *)((u8 *)D_005F2190 + eyeOffset) - *(f32 *)(work + 4);
        /* measured: typing the retained access changes b210 output (normalized_diff 465); keep raw. */
        direction[1] = *(f32 *)((u8 *)D_005F2194 + eyeOffset) - *(f32 *)(work + 8);
        /* measured: typing the retained access changes b210 output (normalized_diff 444); keep raw. */
        direction[2] = *(f32 *)((u8 *)D_005F2198 + eyeOffset) - *(f32 *)(work + 0xC);
        eyeDistance = mulFp(RwV3dNormalize(&direction[0], &direction[0]), progress);
        direction[0] = direction[0] * eyeDistance;
        direction[1] = direction[1] * eyeDistance;
        direction[2] = direction[2] * eyeDistance;
        ((FldLmapPathWork *)work)->eye.x = ((FldLmapPathWork *)work)->eye.x + direction[0];
        ((FldLmapPathWork *)work)->eye.y = ((FldLmapPathWork *)work)->eye.y + direction[1];
        ((FldLmapPathWork *)work)->eye.z = ((FldLmapPathWork *)work)->eye.z + direction[2];
        targetOffset = ((FldLmapPathWork *)work)->targetSlot * 0x18;
        /* measured: typing the retained access changes b210 output (normalized_diff 357); keep raw. */
        direction[0] = *(f32 *)((u8 *)D_005F219C + targetOffset) - *(f32 *)(work + 0x10);
        /* measured: typing the retained access changes b210 output (normalized_diff 316); keep raw. */
        direction[1] = *(f32 *)((u8 *)D_005F21A0 + targetOffset) - *(f32 *)(work + 0x14);
        /* measured: typing the retained access changes b210 output (normalized_diff 295); keep raw. */
        direction[2] = *(f32 *)((u8 *)D_005F21A4 + targetOffset) - *(f32 *)(work + 0x18);
        targetDistance = mulFp(RwV3dNormalize(&direction[0], &direction[0]), progress);
        direction[0] = direction[0] * targetDistance;
        direction[1] = direction[1] * targetDistance;
        direction[2] = direction[2] * targetDistance;
        ((FldLmapPathWork *)work)->target.x = ((FldLmapPathWork *)work)->target.x + direction[0];
        ((FldLmapPathWork *)work)->target.y = ((FldLmapPathWork *)work)->target.y + direction[1];
        ((FldLmapPathWork *)work)->target.z = ((FldLmapPathWork *)work)->target.z + direction[2];
        K_ClumpLookAtBasis(kwlnGetCamera(), work + 4, work + 0x10, 0);
        /* measured: typing the retained access changes b210 output (normalized_diff 624); keep raw. */
        nextFrame = *(s32 *)(work + 0x24) + 1;
        /* measured: typing the retained access changes b210 output (normalized_diff 624); keep raw. */
        *(s32 *)(work + 0x24) = nextFrame;
        if (((FldLmapPathWork *)work)->duration < nextFrame) {
            /* measured: typing the retained access changes b210 output (normalized_diff 512); keep raw. */
            cameraPose = (u8 *)D_005F2190 + (*(s32 *)(work + 0x30) * 0x18);
            K_ClumpLookAtBasis(kwlnGetCamera(), cameraPose, cameraPose + 0xC, 0);
            eye = (u8 *)D_005F2190 + (((FldLmapPathWork *)work)->targetSlot * 0x18);
            /* measured: typing the retained access changes b210 output (normalized_diff 620); keep raw. */
            *(Vec3 *)(work + 4) = *(Vec3 *)(eye + 0);
            target = (u8 *)D_005F219C + (((FldLmapPathWork *)work)->targetSlot * 0x18);
            /* measured: typing the retained access changes b210 output (normalized_diff 618); keep raw. */
            *(Vec3 *)(work + 0x10) = *(Vec3 *)(target + 0);
            ((FldLmapPathWork *)work)->frame = 0;
            ((FldLmapPathWork *)work)->state = 1;
        }
        break;
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_00189520
void FldLmapPathTaskDestroy(u8 *task)
{
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

// FUN_00189550
/* Create an idle map-camera path task with no target slot. */
u8 *FldLmapPathTaskCreate(u8 *parent)
{
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(D_005F1EF8, 0x735);
    work = (u8 *)D_008873F4[0](1, 0x34, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = (u8 *)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F2180), 0xF, 0, 0, FldLmapPathUpdate, FldLmapPathTaskDestroy, (u8 *)(work));
    ((FldLmapPathWork *)work)->targetSlot = -1;
    return task;
}

