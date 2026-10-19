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
extern u8 *H_Cdvd_AcquireDirectory(u8 *param, s32 mode);
extern void H_Cdvd_Destroy(u8 *ptr);
extern s32 H_Cdvd_IsFileLoaded(u8 *ptr);
extern s32 H_Cdvd_LookupRequest(u8 *param, s32 *out);
extern s32 func_0046a750(s32 param);
extern void sdkSpriteRelease(void *ptr);

extern void func_003e0f40(u8 *param);
extern void fieldSceneUnload();
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern u8 *PrimAllocQueueNode();
extern void PrimAppendNode(void *param, u8 *work);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 RwV3dNormalize(f32 *param, f32 *out);
extern u8 *mdlGetMatrix(s32 param);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern u8 *kwlnGetCamera();
extern void K_ClumpLookAtBasis(u8 *param, u8 *src, u8 *dst, s32 mode);
extern f32 sinf(f32 param);
extern f32 cosf(f32 param);
extern s64 datGetDateIndex();
extern s32 datGetTimeSlot();
extern s64 calGetDayEntryByPhase(s64 param, s32 param2);
extern s32 datGetFlag(s32 id);
extern u8 *func_003e0f80();
extern void fieldSceneLoad(s32 a, s32 b);
extern void fieldSceneRequestSecondaryRoom(s64 param);
extern s32 fieldSceneLoadStep();
extern u8 *MT_Scene_GetCameraResFirst();
extern f32 MT_Scene_GetCameraFov();
extern s32 sndRequestAreaTrack();
extern void sndPlayAreaCue();
extern void fadeBeginReturnTransition(s32 a, s32 b);
extern s32 fadeStatus();
extern void fadeBeginTransition(s32 a, s32 b);
extern s32 kwlnTaskIsLinked(u8 *param);
extern s32 scrStartProcedureChecked(s32 a, s32 b, s32 c, s32 d);
extern void func_003e9cb0(s32 param, u8 *src, s32 mode);
extern void K_View_SetFov(u8 *param, f32 value);
extern void FldLmapCameraMoveTo(u8 *param, s32 a, s32 b, f32 value);
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
void FldLmapCameraMoveTo(u8 *task, s32 fromSlot, s32 toSlot, f32 speed);

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
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
    s32 fileSize;
    u8 directoryPath[0x4C];
    s32 timeSlot;
    s32 state;
    s64 dateIndex;
    s64 dayEntry;
    s64 dayPhase;
    u8 *work;

    work = ((SdkTask *)task)->work;
    state = *(s32 *)work;
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
        *(u8 **)(work + 4) = H_Cdvd_AcquireDirectory(directoryPath, 1);
        *(s32 *)work = *(s32 *)work + 1;
        /* fallthrough */
    case 1:
        if (H_Cdvd_IsFileLoaded(*(u8 **)(work + 4)) != 0) {
            *(s32 *)(*(u8 **)(work + 8) + 0x38) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F10, &fileSize));
            *(s32 *)(*(u8 **)(work + 8) + 0x3C) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F30, &fileSize));
            *(s32 *)(*(u8 **)(work + 8) + 0x40) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F50, &fileSize));
            *(s32 *)(*(u8 **)(work + 8) + 0x44) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F70, &fileSize));
            *(s32 *)(*(u8 **)(work + 8) + 0x48) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F1F90, &fileSize));
            *(s32 *)work = *(s32 *)work + 1;
        }
        break;
    case 2:
        if ((func_0046a750(*(s32 *)(*(u8 **)(work + 8) + 0x38)) != 0) && (func_0046a750(*(s32 *)(*(u8 **)(work + 8) + 0x3C)) != 0) && (func_0046a750(*(s32 *)(*(u8 **)(work + 8) + 0x40)) != 0) && (func_0046a750(*(s32 *)(*(u8 **)(work + 8) + 0x44)) != 0) && (func_0046a750(*(s32 *)(*(u8 **)(work + 8) + 0x48)) != 0)) {
            *(s32 *)work = *(s32 *)work + 1;
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
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
    u8 *work;

    work = *(u8 **)(task + 0x38);
    *(s32 *)(*(u8 **)(work + 8) + 4) = 1;
    H_Cdvd_Destroy(*(u8 **)(work + 4));
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
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
    s32 *otherX;
    s32 *completionFlag;
    s32 delayFrames;
    s32 framesLeft;
    s32 state;
    u8 *work;

    work = ((SdkTask *)task)->work;
    state = *(s32 *)work;
    switch (state) {
    case 0:
        if (!((*(f32 *)(work + 0x10) - *(f32 *)(work + 0xC)) <= 0.0f)) {
            *(f32 *)(work + 0x14) = -1.0f;
        } else {
            *(f32 *)(work + 0x14) = 1.0f;
        }
        *(s32 *)work = *(s32 *)work + 1;
    case 1:
        delayFrames = *(s32 *)(work + 0x24);
        if (delayFrames > 0) {
            *(s32 *)(work + 0x24) = delayFrames - 1;
            goto block_19;
        }
        if (*(f32 *)(work + 0x14) < 0.0f) {
            *(f32 *)(*(u8 **)(work + 4)) = (*(f32 *)(work + 0x10) - *(f32 *)(work + 0xC)) * -sinf((iGpffff84a4 * (f32)*(s32 *)(work + 0x20)) / (f32)*(s32 *)(work + 0x1C));
        } else {
            *(f32 *)(*(u8 **)(work + 4)) = (*(f32 *)(work + 0x10) - *(f32 *)(work + 0xC)) * cosf((iGpffff84a4 * (f32)*(s32 *)(work + 0x20)) / (f32)*(s32 *)(work + 0x1C));
        }
        *(f32 *)(*(u8 **)(work + 4) + 4) = 0.0f;
        framesLeft = *(s32 *)(work + 0x20);
        if (framesLeft > 0) {
            *(s32 *)(work + 0x20) = framesLeft - 1;
            goto block_19;
        }
        *(f32 *)(*(u8 **)(work + 4)) = *(f32 *)(work + 0x10);
        *(f32 *)(*(u8 **)(work + 4) + 4) = 0.0f;
        otherX = *(s32 **)(work + 8);
        if (otherX != NULL) {
            *otherX = 0xC3660000; /* -230.0f x */
        }
        completionFlag = *(s32 **)(work + 0x28);
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
        *(s32 *)(*(u8 **)positionSlot + 8) = 0x43960000; /* 300.0f depth */
        *(s32 *)(*(u8 **)otherPositionSlot + 8) = 0x43C80000; /* 400.0f depth */
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
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
    s32 slotIndex;
    u8 *slot;

    slotIndex = 0;
    while (slotIndex < 5) {
        if ((u32)*(u32 *)work > 8U) {
            slot = work + (slotIndex * 4);
            *(s32 *)(slot + 0x4C) = 0;
            *(s32 *)(slot + 0x60) = 0;
        } else {
            if (*(s32 *)(work + 0xC) != slotIndex) {
                slot = work + (slotIndex * 4);
                *(s32 *)(slot + 0x4C) = 1;
            } else {
                slot = work + (slotIndex * 4);
                *(s32 *)(slot + 0x4C) = 0;
            }
            if (*(s32 *)(work + 0xC) == slotIndex) {
                *(s32 *)(slot + 0x60) = 1;
            } else {
                *(s32 *)(slot + 0x60) = 0;
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
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
    u8 *parent;
    u8 *work;
    s32 slotIndex;
    u8 markerPosition[12];
    s32 fileSize;
    extern s32 sdkSndStartStream(s16 index, s16 stream, s16 mode, s16 cue);

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
        *(f32 *)(work + 0x98) = 700.0f;
        FldLmapDrawCornerMarks(work, work + 0x90);
        *(f32 *)(markerPosition + 8) = (f32)590;
        for (slotIndex = 0; slotIndex < 5; slotIndex++) {
            if (*(s32 *)(work + slotIndex * 4 + 0x4C) != 0) {
                FldLmapDrawSlotMarker(work, markerPosition, slotIndex);
                FldLmapDrawSlotPair(work, work + slotIndex * 12 + 0x9C, slotIndex);
            }
        }
        for (slotIndex = 0; slotIndex < 5; slotIndex++) {
            if (*(s32 *)(work + slotIndex * 4 + 0x60) != 0) {
                FldLmapDrawSlotIcon(work, work + slotIndex * 12 + 0xD8, slotIndex);
            }
        }
        *(f32 *)(work + 0x98) = 500.0f;
        FldLmapDrawSlotRow(work, work + 0x90);
        if ((*(s32 *)(work + 4) != 0) && (*(s32 *)(work + 0x74) != 0)) {
            if (*(f32 *)(work + 0x11C) >= *(f32 *)(work + 0x128)) {
                FldLmapDrawPanel(work, work + 0x114, *(s32 *)(work + 0x80));
                FldLmapDrawPanel(work, work + 0x120, *(s32 *)(work + 0x84));
            } else {
                FldLmapDrawPanel(work, work + 0x120, *(s32 *)(work + 0x84));
                FldLmapDrawPanel(work, work + 0x114, *(s32 *)(work + 0x80));
            }
        }
    }
    switch (*(s32 *)work) {
    case 0: {
        s32 slotIndex;
        f32 iconStartX = (f32)-427;
        f32 iconDepth = (f32)550;
        s32 pairStartXBits = 0xC3BB0000;
        s32 pairDepthBits = 0x44160000;
        for (slotIndex = 0; slotIndex < 5; slotIndex++) {
            u8 *cursor = work + slotIndex * 12;
            *(s32 *)(cursor + 0x9C) = pairStartXBits;
            *(s32 *)(cursor + 0xA0) = 0;
            *(s32 *)(cursor + 0xA4) = pairDepthBits;
            *(f32 *)(cursor + 0xD8) = iconStartX;
            *(s32 *)(cursor + 0xDC) = 0;
            *(f32 *)(cursor + 0xE0) = iconDepth;
        }
        *(s32 *)(work + 0x74) = 1;
        *(f32 *)(work + 0x88) = -330.0f;
        *(f32 *)(work + 0x8C) = -330.0f;
        *(f32 *)(work + 0x114) = -230.0f;
        *(s32 *)(work + 0x118) = 0;
        *(f32 *)(work + 0x11C) = 400.0f;
        *(f32 *)(work + 0x120) = -230.0f;
        *(s32 *)(work + 0x124) = 0;
        *(f32 *)(work + 0x128) = 400.0f;
        *(f32 *)(work + 0x12C) = 36.0f;
        *(s32 *)(work + 0x130) = 0;
        *(f32 *)(work + 0x134) = 200.0f;
        *(s32 *)(work + 0x78) = 1;
        *(s32 *)work = *(s32 *)work + 1;
    }
    /* fallthrough */
    case 1:
        *(u8 **)(work + 0x18) = func_003e0f80();
        fieldSceneLoad(1, 1);
        fieldSceneRequestSecondaryRoom((s16)FldEnvStateFromCalendar(1, 1));
        func_00440b68(&iGpffff9f68, D_005F1EF8, 0x211);
        *(u8 **)(work + 0x1C) = H_Cdvd_AcquireDirectory(D_005F1FD0, 1);
        func_00440b68(&iGpffff9f68, D_005F1EF8, 0x212);
        *(u8 **)(work + 0x20) = H_Cdvd_AcquireDirectory(D_005F1FF0, 0);
        *(s32 *)work = *(s32 *)work + 1;
    /* fallthrough */
    case 2: {
        if (fieldSceneLoadStep() == 0) {
            break;
        }
        if (H_Cdvd_IsFileLoaded(*(u8 **)(work + 0x1C)) == 0) {
            break;
        }
        if (H_Cdvd_IsFileLoaded(*(u8 **)(work + 0x20)) == 0) {
            break;
        }
        *(FldLmapMatrix *)*(u8 **)(work + 0x18) = *(FldLmapMatrix *)MT_Scene_GetCameraResFirst();
        {
            u8 *camera = kwlnGetCamera();
            K_View_SetFov(camera, MT_Scene_GetCameraFov());
        }
        {
            u8 *camera = kwlnGetCamera();
            func_003e9cb0(*(s32 *)(camera + 4), *(u8 **)(work + 0x18), 0);
        }
        *(s32 *)(work + 0x24) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2010, &fileSize));
        *(s32 *)(work + 0x2C) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2030, &fileSize));
        *(s32 *)(work + 0x30) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2050, &fileSize));
        *(s32 *)(work + 0x28) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2070, &fileSize));
        *(s32 *)(work + 0x34) = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_LookupRequest(D_005F2090, &fileSize));
        *(u8 **)(work + 0x160) = (u8 *)scrStartProcedureChecked(15, *(s32 *)(*(u8 **)(work + 0x20) + 0x110), *(s32 *)(*(u8 **)(work + 0x20) + 0x118), 0);
        *(s32 *)work = *(s32 *)work + 1;
    }
    /* fallthrough */
    case 3:
        if (func_0046a750(*(s32 *)(work + 0x24)) == 0) {
            break;
        }
        if (func_0046a750(*(s32 *)(work + 0x2C)) == 0) {
            break;
        }
        if (func_0046a750(*(s32 *)(work + 0x30)) == 0) {
            break;
        }
        if (func_0046a750(*(s32 *)(work + 0x28)) == 0) {
            break;
        }
        if (func_0046a750(*(s32 *)(work + 0x34)) == 0) {
            break;
        }
        if (kwlnTaskIsLinked(*(u8 **)(work + 0x160)) == 1) {
            break;
        }
        H_Cdvd_Destroy(*(u8 **)(work + 0x1C));
        *(u8 **)(work + 0x1C) = NULL;
        *(s32 *)(work + 4) = 0;
        chkmemAllocSiteTag(D_005F1EF8, 0x104);
        {
            u8 *loadWork = (u8 *)D_008873F4[0](1, 12, 0x40000);
            s32 loadTask;
            if (loadWork == NULL) {
                loadTask = 0;
            } else {
                loadTask = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F1FA8), 15, 0, 0, FldLmapLoadUpdate, FldLmapLoadDestroy, (u8 *)(loadWork));
                *(u8 **)(loadWork + 8) = work;
            }
            *(s32 *)(work + 0x15C) = loadTask;
        }
        *(s32 *)(work + 0x140) = (s32)MT_Scene_GetRes(0x280A);
        *(s32 *)(work + 0x144) = (s32)MT_Scene_GetRes(0x2809);
        *(s32 *)(work + 0x148) = (s32)MT_Scene_GetRes(0x2806);
        *(s32 *)(work + 0x14C) = (s32)MT_Scene_GetRes(0x2808);
        *(s32 *)(work + 0x150) = (s32)MT_Scene_GetRes(0x2807);
        *(s32 *)(work + 0x154) = (s32)MT_Scene_GetRes(0x2805);
        *(u8 **)(work + 0x164) = FldLmapMarkerTaskCreate(parent, *(s32 *)(work + 0x140), work + 0x144);
        FldLmapMarkerSetTarget(*(u8 **)(work + 0x164), *(s32 *)(work + 0xC), 0.0f);
        *(u8 **)(work + 0x168) = FldLmapPathTaskCreate(parent);
        FldLmapCameraMoveTo(*(u8 **)(work + 0x168), *(s32 *)(work + 0xC), *(s32 *)(work + 0xC), 0.0f);
        if (sndRequestAreaTrack() == 0) {
            sndPlayAreaCue();
        }
        fadeBeginReturnTransition(1, 0);
        *(s32 *)work = *(s32 *)work + 1;
    /* fallthrough */
    case 4:
        if (fadeStatus() == 0) {
            break;
        }
        *(u8 **)(work + 0x158) = FldLmapScrollTaskCreate(parent, work + 0x90, -230.0f, 0.0f, NULL, NULL, 10, 0);
        *(s32 *)work = *(s32 *)work + 1;
    /* fallthrough */
    case 5:
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
        *(u8 **)(work + 0x158) = FldLmapScrollTaskCreate(parent, work + 0x108, -200.0f, 0.0f, NULL, NULL, 8, 8);
        *(s32 *)work = *(s32 *)work + 1;
    /* fallthrough */
    case 6:
        if (kwlnTaskIsLinked(*(u8 **)(work + 0x158)) == 1) {
            break;
        }
        *(s32 *)work = *(s32 *)work + 1;
    /* fallthrough */
    case 7:
        if (*(s32 *)(work + 8) == 1) {
            if (((D_008C024E[0] & 4) != 0) || ((D_008C024E[0] & 1) != 0) || ((D_008C024E[0] & 8) != 0) || ((D_008C024E[0] & 2) != 0)) {
                *(s32 *)(work + 0x74) = !(*(s32 *)(work + 0x78));
                *(s32 *)(work + 0x78) = !(*(s32 *)(work + 0x78));
            }
        }
        if ((D_008C024E[0] & 0x40) != 0) {
            s32 slotIndex;
            for (slotIndex = 0; slotIndex < 5; slotIndex++) {
                if (*(s32 *)(work + 0xC) == slotIndex) {
                    FldLmapScrollTaskCreate(parent, work + slotIndex * 12 + 0xD8, 0.0f, -300.0f, NULL, NULL, 10, 6);
                } else {
                    *(u8 **)(work + 0x158) = FldLmapScrollTaskCreate(parent, work + slotIndex * 12 + 0x9C, 0.0f, -230.0f, NULL, NULL, 10, 0);
                }
            }
            *(s32 *)(work + 0x78) = 0;
            *(s32 *)work = 8;
            sdkSndStartStream(0, 0, 0, 1);
            break;
        } else {
            if ((D_008C0252[0] & 0x1000) != 0) {
                sdkSndStartStream(0, 0, 0, 0);
                *(s32 *)(work + 0xC) = *(s32 *)(work + 0xC) - 1;
                *(s32 *)(work + 0x14) = 0;
            } else if ((D_008C0252[0] & 0x4000) != 0) {
                sdkSndStartStream(0, 0, 0, 0);
                *(s32 *)(work + 0xC) = *(s32 *)(work + 0xC) + 1;
                *(s32 *)(work + 0x14) = 0;
            }
            if (*(s32 *)(work + 0xC) < 0) {
                *(s32 *)(work + 0xC) = 4;
            }
            if (*(s32 *)(work + 0xC) > 4) {
                *(s32 *)(work + 0xC) = 0;
            }
            if (*(s32 *)(work + 0x10) != *(s32 *)(work + 0xC)) {
                *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 1;
            }
            FldLmapMarkerSetTarget(*(u8 **)(work + 0x164), *(s32 *)(work + 0xC), 0.0f);
            if (*(s32 *)(work + 0x14) > 5) {
                ((s32 *)(work + 0x80))[*(s32 *)(work + 0x7C)] = *(s32 *)(work + 0xC);
                {
                    s32 panelIndex = *(s32 *)(work + 0x7C);
                    s32 otherPanel = !panelIndex;
                    FldLmapScrollTaskCreate(parent, work + panelIndex * 12 + 0x114, -230.0f, 0.0f, work + otherPanel * 12 + 0x114, work + 0x170, 8, 0);
                }
                ((f32 *)(work + 0x88))[*(s32 *)(work + 0x7C)] = -330.0f;
                *(s32 *)(work + 0x7C) = !(*(s32 *)(work + 0x7C));
                FldLmapCameraMoveTo(*(u8 **)(work + 0x168), *(s32 *)(work + 0x10), *(s32 *)(work + 0xC), 3.0f);
                *(s32 *)(work + 0x10) = *(s32 *)(work + 0xC);
                *(s32 *)(work + 0x14) = 0;
                *(f32 *)(work + 0x12C) = 0.0f;
            }
            if (*(s32 *)(work + 0x16C) == 0) {
                s32 panelOffset = !(*(s32 *)(work + 0x7C)) * 4;
                u8 *panelCursor = (u8 *)(panelOffset + (s32)work);

                if (*(f32 *)(panelCursor + 0x88) < 0.0f) {
                    if (*(s32 *)(work + 0x174) == 0) {
                        *(f32 *)(panelCursor + 0x88) = *(f32 *)(panelCursor + 0x88) + 1.0f;
                    }
                } else {
                    *(s32 *)(work + 0x174) = 90;
                    *(s32 *)(work + 0x16C) = 1;
                }
            } else {
                s32 panelOffset = !(*(s32 *)(work + 0x7C)) * 4;
                u8 *panelCursor = (u8 *)(panelOffset + (s32)work);

                if (*(f32 *)(panelCursor + 0x88) > -330.0f) {
                    if (*(s32 *)(work + 0x174) == 0) {
                        *(f32 *)(panelCursor + 0x88) = *(f32 *)(panelCursor + 0x88) - 1.0f;
                    }
                } else {
                    *(s32 *)(work + 0x174) = 90;
                    *(s32 *)(work + 0x16C) = 0;
                }
            }
            if (*(s32 *)(work + 0x174) > 0) {
                *(s32 *)(work + 0x174) = *(s32 *)(work + 0x174) - 1;
            }
            if (*(s32 *)(work + 0x170) != 0) {
                *(s32 *)(work + 0x16C) = 0;
                *(s32 *)(work + 0x170) = 0;
                *(s32 *)(work + 0x174) = 0;
            }
            *(f32 *)(work + 0x12C) = *(f32 *)(work + 0x12C) - 2.0f;
            {
                s32 visiblePanel = !(*(s32 *)(work + 0x7C));
                s32 panelSlot = ((s32 *)(work + 0x80))[visiblePanel];
                if (*(f32 *)(work + 0x12C) < D_005F1E20[panelSlot]) {
                    *(f32 *)(work + 0x12C) = 36.0f;
                }
            }
        }
        break;
    case 8:
        if (kwlnTaskIsLinked(*(u8 **)(work + 0x158)) == 1) {
            break;
        }
        FldLmapScrollTaskCreate(parent, work + 0x90, 0.0f, -230.0f, NULL, NULL, 10, 0);
        FldLmapScrollTaskCreate(parent, work + 0x114, 0.0f, -230.0f, NULL, NULL, 10, 0);
        FldLmapScrollTaskCreate(parent, work + 0x120, 0.0f, -230.0f, NULL, NULL, 10, 0);
        fadeBeginTransition(1, 0);
        *(s32 *)work = *(s32 *)work + 1;
        break;
    case 9:
        if (fadeStatus() == 0) {
            break;
        }
        if (*(s32 *)(work + 4) == 0) {
            break;
        }
        if (*(s32 *)(work + 8) == 0) {
            scrStartProcedureChecked(15, *(s32 *)(*(u8 **)(work + 0x20) + 0x110), *(s32 *)(*(u8 **)(work + 0x20) + 0x118), *(s32 *)(work + 0xC) + 1);
        }
        *(s32 *)work = *(s32 *)work + 1;
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
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
    u8 *work;

    work = *(u8 **)(task + 0x38);
    sdkSpriteRelease(*(u8 **)(work + 0x24));
    sdkSpriteRelease(*(u8 **)(work + 0x2C));
    sdkSpriteRelease(*(u8 **)(work + 0x30));
    sdkSpriteRelease(*(u8 **)(work + 0x28));
    sdkSpriteRelease(*(u8 **)(work + 0x34));
    sdkSpriteRelease(*(u8 **)(work + 0x38));
    sdkSpriteRelease(*(u8 **)(work + 0x3C));
    sdkSpriteRelease(*(u8 **)(work + 0x40));
    sdkSpriteRelease(*(u8 **)(work + 0x44));
    sdkSpriteRelease(*(u8 **)(work + 0x48));
    fieldSceneUnload();
    func_003e0f40(*(u8 **)(work + 0x18));
    H_Cdvd_Destroy(*(u8 **)(work + 0x20));
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
    /* Vec3 access to position changed alias/reload scheduling under MWCC and lost MATCH. */
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
    f32 x;
    f32 y;

    x = -32.0f;
    x += *(f32 *)position;
    y = -7.0f + *(f32 *)(position + 4);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8), 0xFFFFFF, 0xFF, 0, *(void **)(work + 0x24), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    x = -32.0f;
    x += *(f32 *)position;
    y = 224.0f + *(f32 *)(position + 4);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8), 0xFFFFFF, 0xFF, 1, *(void **)(work + 0x24), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

/* Exact under MWCC b210/O2: preserve the float input view and associate the
   column offset before adding the caller's x coordinate. */
// FUN_00188320
/* Queue the row render state and draw the five two-column slot backgrounds. */
void FldLmapDrawSlotRow(u8 *work, u8 *position)
{
    /* Vec3 access to position changed alias/reload scheduling under MWCC and lost MATCH. */
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
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
    *(s32 *)(queueNode + 0x10) = 0;
    PrimAppendNode(D_00795E60, queueNode);
    x = -44.0f;
    x += *(f32 *)position;
    y = -7.0f + *(f32 *)(position + 4);
    sdkSpriteDrawQueued(
        (f32)(s32)x,
        (f32)(s32)y,
        *(f32 *)(position + 8) - 10.0f,
        0x313131,
        0xFF,
        0,
        *(void **)(work + 0x2C),
        0,
        0,
        0,
        0.0f,
        1.0f,
        1.0f,
        D_00795E60);
    x = -44.0f;
    x += *(f32 *)position;
    y = 224.0f + *(f32 *)(position + 4);
    sdkSpriteDrawQueued(
        (f32)(s32)x,
        (f32)(s32)y,
        *(f32 *)(position + 8) - 10.0f,
        0x313131,
        0xFF,
        1,
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
            y = -40.0f + *(f32 *)(position + 4) + rowOffset;
            sdkSpriteDrawQueued(
                (f32)(s32)x,
                (f32)(s32)y,
                *(f32 *)(position + 8),
                0x393939,
                0xFF,
                3,
                *(void **)(work + 0x2C),
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
    /* Vec3 access to position changed alias/reload scheduling under MWCC and lost MATCH. */
    /* Linker-split float symbols address interleaved records; their full table extent is not established here. */
    s32 tableOffset;
    f32 y;
    f32 x;

    tableOffset = slotIndex * 0x18;
    x = *(f32 *)position + *(f32 *)((u8 *)D_005F20B8 + tableOffset);
    y = *(f32 *)(position + 4) + *(f32 *)((u8 *)D_005F20BC + tableOffset);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8), 0xFFFF81, 0xFF, 7, ((FldLmapWork *)work)->sprites[4].pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    x = *(f32 *)position + *(f32 *)((u8 *)D_005F20C0 + tableOffset);
    y = *(f32 *)(position + 4) + *(f32 *)((u8 *)D_005F20C4 + tableOffset);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8), 0xEC7C00, 0xFF, slotIndex + 7, ((FldLmapWork *)work)->sprites[1].pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

/* measured re-triage: corrected two-call body has exact size, but MWCC b210
   sinks the f14 load below the integer arguments and serialises the f13
   chain. Best candidate: normalized_diff 79, object 336/336; discarded. */
// FUN_001887F0
/* Draw the selected slot background and label. */
void FldLmapDrawSlotIcon(u8 *work, u8 *position, s32 slotIndex)
{
    /* Vec3 access to position changed alias/reload scheduling under MWCC and lost MATCH. */
    /* Linker-split float symbols address interleaved records; their full table extent is not established here. */
    s32 tableOffset;
    f32 y;
    f32 x;

    tableOffset = slotIndex * 0x10;
    x = *(f32 *)position + *(f32 *)((u8 *)D_005F2130 + tableOffset);
    y = *(f32 *)(position + 4) + *(f32 *)((u8 *)D_005F2134 + tableOffset);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8), 0x313131, 0xFF, 6, ((FldLmapWork *)work)->sprites[4].pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    x = *(f32 *)position + *(f32 *)((u8 *)D_005F2138 + tableOffset);
    y = *(f32 *)(position + 4) + *(f32 *)((u8 *)D_005F213C + tableOffset);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8), 0xFFFFFF, 0xFF, slotIndex + 7, ((FldLmapWork *)work)->sprites[1].pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

// FUN_00188940
/* Draw a clipped content panel using its independently scrolling horizontal offset. */
void FldLmapDrawPanel(u8 *work, u8 *position, s32 slotIndex)
{
    /* Vec3 access to position changed alias/reload scheduling under MWCC and lost MATCH. */
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
    f32 x;
    f32 contentX;
    f32 y;
    u8 *cursor;
    u8 *queueNode;
    s32 offset;

    cursor = PrimAllocQueueNode();
    *(void (**)(void))(cursor + 8) = (void (*)(void))FldLmapSkyState71009;
    *(s32 *)(cursor + 0x10) = 0;
    PrimAppendNode(D_00795E60, cursor);
    x = -45.0f;
    x += *(f32 *)position;
    y = -5.0f + *(f32 *)(position + 4);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8) - 10.0f, 0xFF0000, 0xFF, 0, *(void **)(work + 0x2C), 0, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    x = -45.0f;
    x += *(f32 *)position;
    y = 224.0f + *(f32 *)(position + 4);
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8) - 10.0f, 0xFF0000, 0xFF, 1, *(void **)(work + 0x2C), 0, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
    queueNode = PrimAllocQueueNode();
    *(void (**)(void))(queueNode + 8) = (void (*)(void))FldLmapSkyState72001;
    *(s32 *)(queueNode + 0x10) = 0;
    PrimAppendNode(D_00795E60, queueNode);
    x = 185.0f;
    x += *(f32 *)position;
    y = 0.0f;
    sdkSpriteDrawQueued((f32)(s32)x, (f32)(s32)y, *(f32 *)(position + 8) - 10.0f, 0xFFFFFF, 0, 7, *(void **)(work + 0x30), 0, 0, 0, 0, iGpffff8538, 1.0f, D_00795E60);
    offset = (slotIndex ^ *(s32 *)(work + 0x80)) != 0;
    offset *= 4;
    cursor = (u8 *)(offset + (s32)work);
    y = *(f32 *)(cursor + 0x88);
    contentX = *(f32 *)position - 1.0f;
    contentX += y;
    y = *(f32 *)(position + 4);
    y -= 1.0f;
    offset = slotIndex * 4;
    cursor = (u8 *)(offset + (s32)work);
    sdkSpriteDrawQueued((f32)(s32)contentX, (f32)(s32)y, *(f32 *)(position + 8), 0xFFFFFF, 0xFF, 0, *(void **)(cursor + 0x38), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

// FUN_00188BE0
/* Show the selected scene resource and move the map marker toward its target position. */
/* measured: without opt_loop_invariants MWCC rematerializes the loop-invariant
 * ~2 mask (addiu $v1, $zero, -3) inside the loop body; retail hoists it to the
 * preheader. The pragma restores the hoist. */
s32 FldLmapMarkerUpdate(u8 *task)
{
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
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
        if (slotIndex == *(s32 *)(work + 0x5C)) {
            selectedResource = *(u8 **)(*(u8 **)(work + 8) + (slotIndex * 4));
            *(s32 *)(selectedResource + 0x28) = *(s32 *)(selectedResource + 0x28) | 2;
        } else {
            otherResource = *(u8 **)(*(u8 **)(work + 8) + (slotIndex * 4));
            *(s32 *)(otherResource + 0x28) = *(s32 *)(otherResource + 0x28) & ~2;
        }
        slotIndex += 1;
    }
    state = *(s32 *)work;
    switch (state) {
    case 0:
        *(s32 *)work = state + 1;
        break;
    case 1:
        break;
    case 2:
        cursor = mdlGetMatrix(*(s32 *)(*(u8 **)(work + 4) + 0x144));
        coordinate = *(f32 *)(cursor + 0x30);
        targetOffset = *(s32 *)(work + 0x58) * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        direction.x = *(f32 *)(cursor + 0xC) - coordinate;
        cursor = mdlGetMatrix(*(s32 *)(*(u8 **)(work + 4) + 0x144));
        coordinate = *(f32 *)(cursor + 0x34);
        targetOffset = *(s32 *)(work + 0x58) * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        direction.y = *(f32 *)(cursor + 0x10) - coordinate;
        cursor = mdlGetMatrix(*(s32 *)(*(u8 **)(work + 4) + 0x144));
        coordinate = *(f32 *)(cursor + 0x38);
        targetOffset = *(s32 *)(work + 0x58) * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        direction.z = *(f32 *)(cursor + 0x14) - coordinate;
        RwV3dNormalize(&direction.x, &direction.x);
        direction.x = direction.x * *(f32 *)(work + 0x54);
        direction.y = direction.y * *(f32 *)(work + 0x54);
        direction.z = direction.z * *(f32 *)(work + 0x54);
        cursor = mdlGetMatrix(*(s32 *)(*(u8 **)(work + 4) + 0x144));
        coordinate = *(f32 *)(cursor + 0x30);
        position.x = direction.x + coordinate;
        cursor = mdlGetMatrix(*(s32 *)(*(u8 **)(work + 4) + 0x144));
        coordinate = *(f32 *)(cursor + 0x34);
        position.y = direction.y + coordinate;
        cursor = mdlGetMatrix(*(s32 *)(*(u8 **)(work + 4) + 0x144));
        coordinate = *(f32 *)(cursor + 0x38);
        position.z = direction.z + coordinate;
        targetOffset = *(s32 *)(work + 0x58) * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        direction.x = *(f32 *)(cursor + 0xC) - position.x;
        targetOffset = *(s32 *)(work + 0x58) * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        direction.y = *(f32 *)(cursor + 0x10) - position.y;
        targetOffset = *(s32 *)(work + 0x58) * 0xC;
        cursor = (u8 *)(targetOffset + (s32)work);
        direction.z = *(f32 *)(cursor + 0x14) - position.z;
        RwV3dNormalize(&direction.x, &direction.x);
        if (*(f32 *)(work + 0x48) * direction.x + *(f32 *)(work + 0x4C) * direction.y + *(f32 *)(work + 0x50) * direction.z <= 0.0f) {
            targetOffset = *(s32 *)(work + 0x58) * 0xC;
            cursor = (u8 *)(targetOffset + (s32)work);
            *(Vec3 *)(&position.x) = *(Vec3 *)(cursor + 0xC);
            *(s32 *)(work + 0x5C) = *(s32 *)(work + 0x58);
            *(s32 *)(work + 0x58) = -1;
            *(s32 *)work = 1;
        }
        mdlTranslateMatrix((RwMatrix *)*(s32 *)(*(u8 **)(work + 4) + 0x144), (const RwV3d *)&position, 0);
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
    /* Biased position cursor retains the 12-byte struct-copy loop shape; matrices store translation at +0x30. */
    u8 *task;
    u8 *work;
    u8 *matrix;
    u8 *targetCursor;
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
        matrix = mdlGetMatrix(*(s32 *)(*(u8 **)(slotResources + (slotIndex * 4)) + 0x144));
        targetCursor = work + (slotIndex * 0xC);
        *(Vec3 *)(targetCursor + 0xC) = *(Vec3 *)(matrix + 0x30);
        slotIndex += 1;
    }
    return task;
}

// FUN_00189060
/* Move or snap the marker to a slot; speed zero selects the immediate path. */
void FldLmapMarkerSetTarget(u8 *task, s32 slotIndex, f32 speed)
{
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
    f32 *direction;
    s32 state;
    u8 *work;
    work = ((SdkTask *)task)->work;
    *(f32 *)(work + 0x54) = speed;
    state = *(s32 *)work;
    if (((state != 1) || (*(s32 *)(work + 0x5C) != slotIndex)) && ((state != 2) || (*(s32 *)(work + 0x58) != slotIndex))) {
        if (speed != 0.0f) {
            *(s32 *)(work + 0x58) = slotIndex;
            *(s32 *)(work + 0x5C) = -1;
            *(f32 *)(work + 0x48) = *(f32 *)((u8 *)(*(s32 *)(work + 0x58) * 0xC) + (u32)work + 0xC) - *(f32 *)(mdlGetMatrix(*(s32 *)(*(u8 **)(work + 4) + 0x144)) + 0x30);
            *(f32 *)(work + 0x4C) = *(f32 *)((u8 *)(*(s32 *)(work + 0x58) * 0xC) + (u32)work + 0x10) - *(f32 *)(mdlGetMatrix(*(s32 *)(*(u8 **)(work + 4) + 0x144)) + 0x34);
            *(f32 *)(work + 0x50) = *(f32 *)((u8 *)(*(s32 *)(work + 0x58) * 0xC) + (u32)work + 0x14) - *(f32 *)(mdlGetMatrix(*(s32 *)(*(u8 **)(work + 4) + 0x144)) + 0x38);
            direction = (f32 *)(work + 0x48);
            RwV3dNormalize(direction, direction);
            *(s32 *)work = 2;
            return;
        }
        *(s32 *)(work + 0x58) = -1;
        *(s32 *)(work + 0x5C) = slotIndex;
        mdlTranslateMatrix((RwMatrix *)*(s32 *)(*(u8 **)(work + 4) + 0x144), (const RwV3d *)(work + (slotIndex * 0xC) + 0xC), 0);
    }
}

// FUN_001891D0
/* Interpolate camera eye and target toward a slot pose, then snap at the final frame. */
s32 FldLmapPathUpdate(u8 *task)
{
    /* Proven work layouts are above; typed field access changed MWCC scheduling and lost MATCH. */
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
    state = *(s32 *)work;
    switch (state) {
    case 0:
        *(s32 *)work = state + 1;
        break;
    case 1:
        break;
    case 2:
        progress = sinf((iGpffff84a4 * (f32)*(s32 *)(work + 0x24)) / (f32)*(s32 *)(work + 0x28));
        eyeOffset = *(s32 *)(work + 0x30) * 0x18;
        direction[0] = *(f32 *)((u8 *)D_005F2190 + eyeOffset) - *(f32 *)(work + 4);
        direction[1] = *(f32 *)((u8 *)D_005F2194 + eyeOffset) - *(f32 *)(work + 8);
        direction[2] = *(f32 *)((u8 *)D_005F2198 + eyeOffset) - *(f32 *)(work + 0xC);
        eyeDistance = mulFp(RwV3dNormalize(&direction[0], &direction[0]), progress);
        direction[0] = direction[0] * eyeDistance;
        direction[1] = direction[1] * eyeDistance;
        direction[2] = direction[2] * eyeDistance;
        *(f32 *)(work + 4) = *(f32 *)(work + 4) + direction[0];
        *(f32 *)(work + 8) = *(f32 *)(work + 8) + direction[1];
        *(f32 *)(work + 0xC) = *(f32 *)(work + 0xC) + direction[2];
        targetOffset = *(s32 *)(work + 0x30) * 0x18;
        direction[0] = *(f32 *)((u8 *)D_005F219C + targetOffset) - *(f32 *)(work + 0x10);
        direction[1] = *(f32 *)((u8 *)D_005F21A0 + targetOffset) - *(f32 *)(work + 0x14);
        direction[2] = *(f32 *)((u8 *)D_005F21A4 + targetOffset) - *(f32 *)(work + 0x18);
        targetDistance = mulFp(RwV3dNormalize(&direction[0], &direction[0]), progress);
        direction[0] = direction[0] * targetDistance;
        direction[1] = direction[1] * targetDistance;
        direction[2] = direction[2] * targetDistance;
        *(f32 *)(work + 0x10) = *(f32 *)(work + 0x10) + direction[0];
        *(f32 *)(work + 0x14) = *(f32 *)(work + 0x14) + direction[1];
        *(f32 *)(work + 0x18) = *(f32 *)(work + 0x18) + direction[2];
        K_ClumpLookAtBasis(kwlnGetCamera(), work + 4, work + 0x10, 0);
        nextFrame = *(s32 *)(work + 0x24) + 1;
        *(s32 *)(work + 0x24) = nextFrame;
        if (*(s32 *)(work + 0x28) < nextFrame) {
            cameraPose = (u8 *)D_005F2190 + (*(s32 *)(work + 0x30) * 0x18);
            K_ClumpLookAtBasis(kwlnGetCamera(), cameraPose, cameraPose + 0xC, 0);
            eye = (u8 *)D_005F2190 + (*(s32 *)(work + 0x30) * 0x18);
            *(Vec3 *)(work + 4) = *(Vec3 *)(eye + 0);
            target = (u8 *)D_005F219C + (*(s32 *)(work + 0x30) * 0x18);
            *(Vec3 *)(work + 0x10) = *(Vec3 *)(target + 0);
            *(s32 *)(work + 0x24) = 0;
            *(s32 *)work = 1;
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

