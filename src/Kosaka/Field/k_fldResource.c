#include "primitive_queue_internal.h"
#include "Kosaka/k_fld_rw_internal.h"
#include "resrc_manager_internal.h"
#include "h_cdvd_request_internal.h"
#include "rw_types_internal.h"
#include "model_motion_internal.h"
#include "texture_callback_internal.h"
#include "include_asm.h"
#include "Kosaka/k_clump_property_internal.h"
/* Original translation unit k_fldResource.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "rw/ps2/ostypes.h"
#include "field_frame_internal.h"
#include "rw/plcore/barenderstate.h"

typedef struct RwMatrixTolerance {
    f32 Normal;
    f32 Orthogonal;
    f32 Identity;
} RwMatrixTolerance;

typedef RwV3d Vec3;
typedef struct RwFrame RwFrame;
typedef struct RwCamera RwCamera;
typedef struct RpWorld RpWorld;
typedef struct RpLight RpLight;
typedef struct RwRGBAReal RwRGBAReal;
typedef struct RwMatrixTag RwMatrix;
typedef enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwOpCombineType;
typedef RwRGBAReal Vec4;

extern s32 sprintf(char *dst, const char *format, ...);
extern s32 func_00440b68(const char *format, ...);
extern s32 H_Cdvd_AcquireDirectory(char *path, s32 flags);
extern s32 H_Cdvd_IsFileLoaded(s32 cdvd);
extern u8 *sdkOtQueueClumpPrimaryPass(u8 *list, s32 stateId);
extern u8 *sdkOtQueueClumpSecondaryPass(u8 *list, s32 stateId);
extern u8 *PrimQueueSkyStateEnter(u8 *list, s32 stateId);
extern u8 *func_003e9d50(u8 *);
extern void FldResource_BeginDrawState(u8 *command, u8 *resource);
extern s32 K_Clump_CountIntUsrData(void *object, const char *name);
extern void kAssertFail(const char *file, s32 line);
extern void mdlEffectSetEulerRotation(s32 object, f32 angleX, f32 angleY, f32 angleZ);
extern void func_003c9d40(void *);
extern void func_003c0700(void *);
extern void hMaestroFreeListSet(void *listSet);
extern void mdlDestroyModelObject(s32 model);
extern void mdlEffectDestroy(s32 model);
extern void func_003bbb60(void *);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *sdkOtQueueClump(u8 *list, s32 stateId);
extern u8 *sdkOtQueueWorld(u8 *list, s32 stateId);
extern s32 kwlnGetCamera(void);
extern s32 K_Clump_GetWorld(void);
extern u8 *K_Clump_GetLightA(void);
extern u8 *K_Clump_GetLightB(void);
extern u8 *K_Clump_GetLightC(void);
extern u32 func_003e8110(u32 camera);
extern u32 func_003e8120(u32 camera);
extern RpWorld *func_003cbf30(RpWorld *world, RpLight *light);
extern RpWorld *func_003cbe80(RpWorld *world, RpLight *light);
extern s32 func_003cbc60(s32 world, u8 *camera);
extern RpWorld *func_003cbc10(RpWorld *world, RwCamera *camera);
extern RpLight *func_003c38b0(RpLight *light, const RwRGBAReal *color);
extern RwFrame *func_003e9cb0(RwFrame *frame, const RwMatrix *transform, RwOpCombineType combine);
extern s32 mdlPrepareModel(u32 model);
extern void mdlApplyModelMatrix(void *model, void *matrix, s32 combineOp);
extern void mdlSetLayerWeight(void *model, s32 layer, f32 speed);
extern RwMatrix *func_003e9700(RwFrame *frame);
extern void K_Clump_FreeTextureNameList(void *listHead);
extern s32 mdlEffectCreateFromResource(s32 resource);
extern void *memset(void *dst, s32 value, u32 size);
extern s32 H_Cdvd_LookupRequest(void *pathAddress, s32 *slot);
extern s32 func_003e2f60(s32, s32, s32 *);
extern s32 func_003df3c0(s32, s32 *);
extern void func_003e2ce0(s32, u32);
extern void func_003e2e40(s32, s32);
extern s32 filerEnqueueRequest(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003dc370(void *);
extern void func_003ef1b0(s32);
extern RwBool (*D_00887300[])(RwRenderState state, void *value);
extern u8 *resrcMngGetColorValue(void);
extern u8 *resrcMngGetColorTarget(void);
extern u8 *resrcMngGetTransform(void);
extern RwBool RpSkyRenderStateSet(s32 state, void *payload);
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern u8 *filerTakeCompletedRequest(s32 request, s32 *completed, s32 *resultValue);
extern s32 K_Clump_GeometryHasMatUsrData(u8 *geometry, char *name);
extern s32 K_Clump_ClumpHasMatUsrData(u8 *clump, char *name);
extern void *sdkClumpCreateBuckets(void *sourceClump);
extern void func_003db550(u8 *, u8 *);
extern char D_005EFCE0[];
extern char D_005EFD00[];
extern char D_005EFD80[];
extern char D_005EFD98[];
extern char D_005EFDA8[];
extern char D_005EFDB8[];
extern char D_005EFDC8[];
extern char D_005EFDD8[];
extern char D_005EFDE8[];
extern char D_005EFE00[];
extern char D_005EFE10[];
extern char iGpffff9e10;
extern void strcat(char *dst, char *src);
extern void *mdlCreateModelObjectFromData(u32 type, u16 id, void *resource, u32 flags);
extern void *mdlCreateModelObjectFromMemory(u32 type, u16 id, void *memory, u32 size, u32 flags);
extern s32 FldMap_IsInBandA(s32 fieldId, s32 roomId);
extern s32 FldMap_IsInBandB(s32 fieldId, s32 roomId);
extern u8 *FldStepLoadFilePair(s32 fieldId, s32 roomId);
extern s32 *MT_Scene_GetFrameState(void);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern s32 atoi(const char *);
extern void strcpy(char *dst, char *src);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 D_00754D88[];
extern s32 chkmemGetBytes(void);
extern s32 func_003c0520(s32);
extern s32 mdlCloneModelObject(s32 source);
extern s32 mdlEffectClone(s32 effect);
extern void mdlEffectSetChildPositionVec(void *object, f32 *position);
extern RwBool RwEngineGetMatrixTolerances(RwMatrixTolerance *tolerance);
extern RwMatrix *RwMatrixOptimize(RwMatrix *matrix, const RwMatrixTolerance *tolerance);
extern RwFrame *func_003e9680(RwFrame *frame);
extern RwMatrix *func_003e0f80(void);
extern RwBool func_003e0f40(RwMatrix *matrix);
extern RwMatrix *RwMatrixRotate(RwMatrix *matrix, const Vec3 *axis, f32 angle, RwOpCombineType combine);
extern Vec3 *func_003e42a0(Vec3 *pointOut, const Vec3 *pointIn, const RwMatrix *matrix);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const Vec3 *translation, s32 combineOp);
extern s64 D_005EFE28[];
extern f32 D_005EFE30[];
extern u8 *iGpffff9db0;
extern void H_Cdvd_Destroy(void *cdvd);
extern u8 D_005EFD20[];
extern u8 D_005EFD40[];
extern u8 D_005EFD60[];
extern s64 D_005EFE38[];
extern f32 D_005EFE40[];
extern char D_005EFC60[];
extern u8 D_005EFC80[];
extern s32 iGpffffb200;   /* gp - 0x4E00 = 0x007642F0 */
extern s32 iGpffffb204;   /* gp - 0x4DFC = 0x007642F4 */
extern u8 iGpffff9df0;    /* gp - 0x6210 = 0x00762EE0 */
extern char D_005EFC90[];
extern u8 D_005F0590[];
extern u8 D_005F0591[];
extern u8 D_005F05B8[];
extern s32 D_007E8060[];
extern s32 iGpffffb208;   /* gp - 0x4DF8 = 0x007642F8 */


typedef struct {
    u16 type;
    u16 flags;
    u16 id;
    u16 pad06;
    s32 frame;
    s32 model;
    s32 effect;
    union { s32 file; u8 *filePtr; };
} FldResourceEntry;

/* Object words are 32-bit address carriers: bit 0 selects worlds instead of
 * clumps; 0x80000000/0x40000000/0x20000000 select the draw-object variants.
 * 0x10000000 marks a missing distinct primary object; bit 1 marks a clone. */
typedef struct {
    u32 flags;
    s16 majorId;
    s16 minorId;
    union { s32 primaryObject; RpWorld *primaryWorld; };
    union { s32 primaryDrawObject; u8 *primaryDrawObjectPtr; };
    s32 alternateObject;
    s32 secondaryObject;
    u32 clumpCount;
    s32 clumps[32];
    union { s32 drawObjects[32]; void *drawObjectPointers[32]; };
    u32 entryCount;
    FldResourceEntry entries[96];
    s32 animation;
    union { Vec3 scale; struct { s32 scaleXBits, scaleYBits, scaleZBits; }; }; /* 0xA24 */
    u8 padA30[0xC];
    s32 hbnFile;                /* 0xA3C */
    union { s32 hbnData; u8 *hbnDataPtr; };                /* 0xA40 */
    u8 *loadWork;               /* 0xA44: separately allocated 0x12C-byte load state */
    s32 fbnFile;                /* 0xA48 */
    union { u8 *fbnData; s32 fbnDataWord; }; /* 0xA4C */
    Vec4 savedAmbientColor;     /* 0xA50 */
    Vec4 savedDirectionalColor; /* 0xA60 */
    u8 savedLightMatrix[0x40];  /* 0xA70: copied as eight scalar pairs */
} FldResource;


/* The 0x12C-byte load allocation contains the path and asynchronous readers. */
typedef struct FldResourceLoadWork {
    char path[0x80];
    s32 directory;
    s32 textureReader;
    u8 pad88[4];
    u32 worldCount;
    s32 worldReaders[4];
    u32 clumpCount;
    s32 clumpReaders[32];
    s32 animationReader;
    s32 textureNames;
} FldResourceLoadWork;

/* Field loader work: captures are re-read at the asynchronous phase boundaries. */
typedef struct FldResourceWork {
    s32 majorId;
    s32 minorId;
    u8 pad08[4];
    s32 flags;
    s16 variant;
    s16 environmentId;
    u8 pad14[0x10];
    s32 resourceCount;           /* 0x24 */
    s32 resources[24];           /* 0x28..0x87 */
    s32 queueFlags;              /* 0x88 */
    s32 textureNames;            /* 0x8C */
    u8 pad90[4];
    s32 state;                   /* 0x94 */
    s32 queuedCount;             /* 0x98 */
    struct { s16 majorId, minorId; } queuedIds[16]; /* 0x9C */
    s32 environmentFile;         /* 0xDC */
} FldResourceWork;

typedef char FldResourceEntrySize[sizeof(FldResourceEntry) == 0x18 ? 1 : -1];
typedef char FldResourceSize[sizeof(FldResource) == 0xAB0 ? 1 : -1];
typedef char FldResourceLoadWorkSize[sizeof(FldResourceLoadWork) == 0x12C ? 1 : -1];

/* Open the primary field directory once for the requested major/minor IDs. */
// FUN_0014EED0
void FldResource_OpenPrimaryFile(s32 majorId, s32 minorId)
{
    char path[0x40];

    if (iGpffffb200 == 0) {
        sprintf(path, D_005EFC60, (u16)majorId, (u16)minorId);
        func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0x9E);
        iGpffffb200 = H_Cdvd_AcquireDirectory(path, 1);
    }
}

/* Return ready when no primary directory is pending or its load has completed. */
// FUN_0014EF40
s32 FldResource_IsPrimaryFileLoaded(void)
{
    if (iGpffffb200 == 0) {
        return 1;
    }
    return H_Cdvd_IsFileLoaded(iGpffffb200) != 0;
}

/* Return ready when no secondary directory is pending or its load has completed. */
// FUN_0014EF80
s32 FldResource_IsSecondaryFileLoaded(void)
{
    if (iGpffffb204 == 0) {
        return 1;
    }
    return H_Cdvd_IsFileLoaded(iGpffffb204) != 0;
}


/* Form an address in the field work object after calculating the record offset. */
static inline u8 *fldResourceWorkOffset(u32 offset, u8 *work)
{
    return (u8 *)(offset + (uintptr_t)work);
}

typedef struct FldResourcePreset
{
    u8 ordinaryCount;
    u8 specialCount;
    s8 minorIds[10];
} FldResourcePreset;

/* Three 12-byte records at 0x005F0590; the field-index map is at 0x005F05B8. */
extern const FldResourcePreset fldResourcePresets[3];

/* Queue field resources from the ordinary/special preset or the requested
 * major/minor pair. Each work capture belongs to one append operation.
 * measured: b210 -O2 retains the loop bases and the explicit work reads;
 * the typed preset view separates records from the field-index bytes. */
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_loop_invariants on
/* Append preset or explicit field ID pairs to the loader queue. */
/* Typed queued-ID/table cursors preserve the measured byte-offset-first append/copy order. */
// FUN_0014EFC0
void FldResource_QueueFieldResources(s32 majorId, s32 minorId)
{
    char specialPath[0x40];
    char fieldPath[0x40];
    s32 presetMajorId;
    s32 resourceCount;
    u8 *work;
    ((FldResourceWork *)iGpffff9db0)->resourceCount = 0;
    ((FldResourceWork *)iGpffff9db0)->state = 0;
    memset(iGpffff9db0 + 0x9C, 0, 0x40);
    if (FldMap_IsInBandA(majorId, minorId) || FldMap_IsInBandB(majorId, minorId)) {
        if (FldMap_IsInBandB(majorId, minorId)) {
            presetMajorId = (u16)((u16)majorId - 0x14);
            ((FldResourceWork *)iGpffff9db0)->queueFlags |= 0x80000000;
            resourceCount = (s32)FldStepLoadFilePair(majorId, minorId);
            ((FldFrame *)MT_Scene_GetFrameState())->hbnHandle = (u8 *)resourceCount;
            resourceCount = D_005F0591[D_005F0590[(u16)presetMajorId] * 12];
        } else {
            presetMajorId = (u16)majorId;
            resourceCount = fldResourcePresets[D_005F0590[presetMajorId]].ordinaryCount;
        }
        work = iGpffff9db0;
        if (((FldResourceWork *)work)->queueFlags & 0x80000000) {
            if (iGpffffb204 == 0) {
                sprintf(specialPath, D_005EFC90, (s16)majorId, (s16)minorId);
                func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0xC9);
                iGpffffb204 = H_Cdvd_AcquireDirectory(specialPath, 1);
            }
            {
                s32 i;
                i = resourceCount - 1;
                for (; i >= 0; i--) {
                    work = iGpffff9db0;
                    ((FldResourceWork *)(work + ((FldResourceWork *)work)->queuedCount * 4))->queuedIds[0].majorId = (s16)presetMajorId;
                    work = iGpffff9db0;
                    /* Both predicates normalize the major ID to40..59. */
                    ((FldResourceWork *)(work + ((FldResourceWork *)work)->queuedCount * 4))->queuedIds[0].minorId =
                        ((const FldResourcePreset *)(D_005F0590 + D_005F05B8[(u16)presetMajorId - 0x28] * 12))->minorIds[i];
                    ((FldResourceWork *)iGpffff9db0)->queuedCount += 1;
                }
            }
        } else {
            ((FldResourceWork *)work)->resourceCount = resourceCount;
            {
                s32 i;
                u32 offset;
                i = 0;
                for (; work = iGpffff9db0, i < ((FldResourceWork *)work)->resourceCount; i++) {
                    offset = i * sizeof(s32);
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    ((FldResourceWork *)(work + offset))->resources[0] = *(const s32 *)((const u8 *)D_007E8060 + offset);
                }
            }
            ((FldResourceWork *)work)->state = 4;
        }
    } else {
        if (iGpffffb204 == 0) {
            sprintf(fieldPath, D_005EFC90, (s16)majorId, (s16)minorId);
            func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0xC9);
            iGpffffb204 = H_Cdvd_AcquireDirectory(fieldPath, 1);
        }
        work = iGpffff9db0;
        ((FldResourceWork *)fldResourceWorkOffset(((FldResourceWork *)work)->queuedCount * 4, work))->queuedIds[0].majorId = (s16)majorId;
        work = iGpffff9db0;
        ((FldResourceWork *)fldResourceWorkOffset(((FldResourceWork *)work)->queuedCount * 4, work))->queuedIds[0].minorId = (s16)minorId;
        ((FldResourceWork *)iGpffff9db0)->queuedCount += 1;
    }
    iGpffffb208 = chkmemGetBytes();
}
#pragma pop
/* Field-loader recovery history (the final byte-exact result is recorded below):
 * complete camera matrices, vectors and 32-entry tables; word-wide resource
 * publication; explicit state dispatch and default return. At the first
 * checkpoint, native b210/O1 gave 5516/5504 bytes and 513 aligned
 * edits (previous guard: 5392 bytes, 574 edits). All 20 guarded siblings are
 * unchanged. The unnecessary 44-byte dispatch table is gone. NPC file-handle
 * storage uses absolute addresses; the old guard emitted out-of-range GP loads.
 * Camera-member and legacy matrix output lifetimes were unresolved at that
 * checkpoint. Its evidence is in build/resume-field-worker12/loader-proof.json.

 * 2026-10-09: 513 -> 450: the m2c `loop_N: if (c) { ...; goto loop_N; }` loops
 * are while loops (retail tests at the bottom), with the re-read of
 * iGpffff9db0 repeated at the end of each body.
 * 2026-10-09: 450 -> 378: the nested grid searches are for loops that
 * leave by goto once the cell is found, and the two HBN read loops are while
 * loops whose exit code follows the loop.
 * 2026-10-09: 378 -> 361: the loops re-read iGpffff9db0 inside the loop test
 * (`while (i < *(s32 *)((w = (u8 *)(iGpffff9db0)) + 0x24))`) and the code after
 * the loop uses that pointer, as retail does.
 * 2026-10-09: 361 -> 339: the grid searches store (u8) counters (retail andi,
 * no sign extension) and clear the inner counter before forming the row base.
 * 2026-10-09: 339 -> 260: locals declared in descending order of the retail
 * saved register that holds them (b210 colours later declarations first here).
 * 2026-10-09: 260 -> 219: the two table-copy loops take the D_007E8060 /
 * D_005F05B8 / D_005F0590 addresses into locals before the loop (retail hoists
 * all three) and test the table entry inline.
 * 2026-10-09: 219 -> 215: the per-resource pointer lists are indexed as arrays
 * (`((u8 **)(w + 0x28))[*(s32 *)(w + 0x24)]`).
 * 2026-10-09: 215 -> 209: grid cells are `(u8 *)(row + (s32)MT_Scene_GetFrameState()) + col`
 * (retail adds the row base to the call result first).
 * 2026-10-09: 209 -> 205: the pending flags count failures (`pending += 1`).
 * 2026-10-09: 205 -> 194: hbnData, fieldOfView, cameraKind, cameraValue60,
 * cameraValue64 declared in that order give retail's frame slots.
 * 2026-10-09: 194 -> 193: one shared `return 0` at the end (the switch default and
 * the state transitions jump there); the dispatch is a switch; waitEnvironment
 * falls into readCamera after an if/else whose else returns.
 * 2026-10-09: 193 -> 165: the environment reload is `if (flags & 4) state = 0x28;
 * else { state = 999; break; }` followed by the loadEnvironment and
 * waitReloadedEnvironment cases at the same level.
 * 2026-10-09: 165 -> 163: the memcpy source is `(u8 *)entry + 4`.
 * 2026-10-09: 163 -> 155: the per-resource loops read iGpffff9db0 before
 * forming the index (`e = w; off = i * 4; e = *(u8 **)(e + off + 0x28)`).
 * 2026-10-09: 155 -> 153: the loaded hbnData pointer is tested and passed from
 * one local.
 * 2026-10-09: 153 -> 132: the frame lists re-read their header inside the loop
 * test as well, and the frame kind is an int-typed lhu result.
 * 2026-10-09: 132 -> 116: the table-copy locals are declared counter, base,
 * offset, destination, index table, count table.
 * 2026-10-09: 116 -> 99: MT_Scene_GetRes is called before the constant store, the
 * flag call passes one `enable` local twice (retail copies $a0 to $a1), and the
 * frame-list loop keeps a `u32 *frameCount` from its test for the final clear.
 * 2026-10-09: MT_Scene_SetResPlacement is declared here with an s32 id: retail passes the
 * masked id without the u16 re-mask that the header prototype would force
 * (H011, retail 0x0014FE90 area).
 * 2026-10-09: 99 -> 94: the frame record is the list base plus `i * 0x18`, added
 * after the base load.
 * 2026-10-09: 94 -> 90: MT_Scene_CreateCameraRes takes the camera entry arrays as pointers.
 * 2026-10-09: 90 -> 86: FldFbnReadTable's last parameter is s16.
 * 2026-10-09: 86 -> 84: the loaded HBN entry is its own local `hbnEntry`.
 * 2026-10-09: 84 -> 83: the first file check assigns `pendingCount = 1` in its NULL branch.
 * 2026-10-09: 83 -> 70: frameMatrix is declared before modelId.
 * 2026-10-09: 70 -> 65: the reload list walker is declared before its next pointer.
 * 2026-10-09: 65 -> 64: the resource pair offset is formed as `idx * 4` then
 * `+= base` (retail adds the base second).
 * 2026-10-09: 64 -> 53: body taken from the parallel cos/finish-first-party-20261009 worktree.
 * sdiff --regs 38 -> 32: the two load checks are one inline helper returning 1/0 in $v0, as retail; retail still reuses the switch's constant 1 for the first NULL case.
 * all four resource checks use the inline readiness helper (same output, consistent source).
 * structure identical (fnalign 64 -> 40): the dispatch is an if-chain in retail's descending order whose compare against 1 uses a local `one`; the first readiness check returns that `one` for a NULL file, so the switch's constant 1 in $v0 is reused as retail does; the last test is a one-case switch with default (retail beqz/b).
 * measured 2026-10-12: fnalign 40 -> 14; separate preset-index and copied-resource locals in each publication loop preserve their roles and free the retail table-base register.
 * 2026-10-12: the 14 edits are the $v0/$v1 swap of the state base and its
 * +0x28 resource in the two FldMap_IsCurrentInBandB()==1 part reads. Backend copy
 * propagation folds the base (memory uses only) into its late gp-load temp,
 * while the resource keeps its low variable number through the +0xA4C addiu;
 * whatif: base numbered below the resource gives retail. Block/struct/helper/
 * address-of spellings, an extra base copy and O1 + opt_common_subs stay 14+.
 * 2026-10-13: at O1 there is no propagate_copy_instructions stage; the
 * after_backend_optimization pass forwards copies only into memory-address
 * operands. The base (loads only) therefore folds into its gp-load temp r713
 * and the resource survives as r41 through its addiu +0xA4C argument.
 * Reading the resource twice (no O1 load CSE: duplicate lw, 47), address-of
 * argument spellings (still addiu, 14) and an inline part-load helper (its
 * argument is substituted, 14) leave the order unchanged.
 * Replay: the sites close iff the base is a local numbered below the
 * resource (r39 < r41) or the resource is a temp above r713. Named values
 * (block-scope locals r154, inline-parameter bindings r158) always number
 * below codegen temps, so the base must survive. O1 forwarding is block-local:
 * every memory-only local that survives has a use in a later block, and
 * retail has none after the call. No effect (14): register, u32/s32 base,
 * merging with the else-loop base, block scopes, typed helper parameters,
 * O1 + propagation/dead-code/lifetimes/strength-reduction toggles. O2 + no
 * CSE/propagation (44) needs the table-loop locals numbered in declaration
 * order, which only O1 keeps.
 * O1 + opt_common_subs on (frontend CSE only; O1 has no backend CSE stage) with the swap-site
 * call reading iGpffff9db0 directly reproduces both swap sites exactly: the frontend shadows base
 * then resource in creation order. The cost is ten iGpffff9db0 reloads that the frontend merges
 * across blocks (retail reloads them) plus two var * 0x18 strides (163). Reading the global as
 * *(u8 **)&iGpffff9db0 at one occurrence per site restores the reloads (87, build/f310_o1cse_87.c),
 * but the strides stay merged and the table loops regress to the O2 colouring.
 * Capture: with opt_common_subs on, the O1 backend pass also forwards the loop locals' copies into
 * arithmetic (sll/preset/resource fold), so the O1-only declaration-order colouring is lost.
 * Replay of the old single-definition resource web required a number >= 714
 * (its raw load temp); named values capped near r158 (inline parameter binding).
 * Also measured: a phase helper
 * around the whole if/else 79, an s64 base parameter 49 (adds a move per site), a resource passed as a
 * call-site expression into a helper 14, the base defined before the branch or via an a270 result
 * local 14, cross-phase variable reuse 19, register 14. Micros: build/micro_src/fwd1-3.
 * measured: fnalign 14 -> 4 by retaining the FBN output-member address in
 * each primary-resource read, rather than the resource base. The file handle
 * at +0xA48 immediately precedes the output buffer pointer at +0xA4C.
 * At that checkpoint all registers agreed; the output-address addiu was early
 * at each site, before the two ID loads and file load rather than after them.
 * measured: 4 -> 0, 1375 instructions. Each primary phase now keeps one result
 * word for the mode query and then the selected resource address. Both values
 * are consumed: the first selects the branch, the second supplies the FBN.
 * The capture in build/code1af310_captures/primary_word_match shows these two
 * phase-local webs (r41/r46) coalescing with physical $v0, without extra code.
 * Keep the output argument in the pointer domain: the typed member address is
 * formed after the file load; integer-address addition materializes it early.
 */
#pragma push
/* measured: O1 preserves the publication-loop pointer/offset lifetimes (fnalign 0). */
#pragma optimization_level 1
static inline s32 fldResourceIsReady(u8 *file)
{
    if (file == NULL) {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded((s32)file) != 0) {
        return 1;
    }
    return 0;
}

static inline s32 fldResourceIsReadyWithDefault(u8 *file, s32 one)
{
    if (file == NULL) {
        return one;
    }
    if (H_Cdvd_IsFileLoaded((s32)file) != 0) {
        return 1;
    }
    return 0;
}

/* Advance asynchronous resource, grid, NPC, camera and environment phases; return one at completion. */
/* Access-site fields preserve the O1 address lifetimes; only individually measured exceptions remain raw. */
// FUN_0014F310
s32 FldResource_StepPartLoad(s32 majorId, s32 minorId) {
    /* Only the fields read while opening the primary FBN are described. */
    typedef struct FldPartReadWork {
        s32 majorId;                    /* 0x00, narrowed to u16 for the FBN */
        s32 minorId;                    /* 0x04, narrowed to u16 for the FBN */
        u8 unknown08[8];
        s16 variant;                    /* 0x10 */
        u8 unknown12[0x16];
        u8 *primaryResource;            /* 0x28 */
    } FldPartReadWork;
    typedef struct FldResourceFbn {
        u8 unknown000[0xA48];
        u8 *file;                       /* 0xA48 */
        u8 *data;                       /* 0xA4C */
    } FldResourceFbn;
    /* The matrix layout is the 64-byte RenderWare matrix from bamatrix.h. */
    typedef struct FldResourceCameraTransform {
        Vec3 right;
        u32 flags;
        Vec3 up;
        u32 pad1;
        Vec3 at;
        u32 pad2;
        Vec3 pos;
        u32 pad3;
    } FldResourceCameraTransform;
    typedef char FldResourceCameraTransformSize[
        sizeof(FldResourceCameraTransform) == 0x40 ? 1 : -1];

    extern void *FldRc_CreateResource(s16 majorId, s16 minorId);
    extern s32 FldResource_IsFileLoaded(u8 *resource);
    extern void FldResource_ParseChunks(u8 *resource);
    extern s32 FldResource_PollLoads(u8 *resource);
    extern void FldResource_RequestEntryLoads(u8 *resource);
    extern s32 FldResource_TryInstallEntries(u8 *resource);
    extern f32 KDraw_MatrixPitchDeg(u8 *matrix);
    extern f32 KDraw_MatrixYawDeg(u8 *matrix);
    extern f32 KDraw_MatrixRollDeg(u8 *matrix);
    extern s32 FldMap_IsCurrentInBandB(void);
    extern s32 FldMap_IsCurrentInBandA(void);
    extern void resrcMngResetRenderSlots(void);
    extern void resrcMngSetDrawEnabled(s32 enabled, s32 includeFieldModels);
    extern s32 FldEnvOpenFile(s32 room);
    extern s32 FldEnvironmentLoad(u8 *file, s32 room);
    extern s32 FldCamOpenFile(void);
    extern s32 FldCamReadRecord(u8 *file, u8 *cameraMatrixOut, u8 *slotMatrixOut, f32 *fovOut, s32 *curveOut, u8 *viewOffsetOut, f32 *viewDistanceOut, f32 *cameraValueOut, s32 *slotIdsOut, s32 *slotVectorsOut);
    /* lint: allow H011 -- retail passes an already-u16-masked ID as a word;
     * the provider consumes that same u16 ID. */
    extern void MT_Scene_SetResPlacement(s32 resourceId, u8 *position, u8 *angles);
    /* lint: allow H011 -- the final arguments are array addresses; the provider
     * casts its s32 words to memcpy sources of 0x20 and 0x180 bytes. */
    extern s32 MT_Scene_CreateCameraRes(u16 resourceId, s32 cameraKind, f32 cameraValue, u8 *firstMatrixInput, u8 *secondMatrixInput, u8 *position, f32 nearValue, f32 farValue, s8 *parameters, Vec3 *data);
    extern u8 *MT_Scene_GetResListHead(s32 resourceType);
    // lint: allow H011 -- measured: u16 prototype regresses FldResource_StepPartLoad (andi on wide id args)
    extern u8 *MT_Scene_GetRes(s32 resTypeId);
    extern void MT_Scene_DestroyRes(u16 resTypeId);
    extern s32 MT_Scene_CreateModelFldRes(u16 resourceId, s32 model);
    extern s32 MT_Scene_CreateRes11(u16 resourceId, s32 model);
    /* lint: allow H011 -- the resource pointer is stored unchanged in the
     * provider's +0x1A0 field; its s32 parameter is a 32-bit address carrier. */
    extern s32 MT_Scene_CreateFldRes(u16 resourceId, u8 *model);
    extern u8 *FldHbnOpenData(s32 fieldId, s32 roomId);
    extern s32 FldHbnReadData(u8 *request, u16 **destination, s32 fieldId, s32 roomId);
    extern void FldHbnSpawnLights(u8 *header, s32 mode);
    extern u8 *FldFbnOpenData(s32 field, s32 room, s16 variant);
    /* lint: allow H011 -- retail supplies a signed halfword variant; the
     * provider's only use narrows its s32 parameter to s16 for the filename. */
    extern s32 FldFbnReadTable(u8 *file, u8 **cachedDataOut, s32 field, s32 room, s16 variant);
    extern s32 FldFbnApplyTable(u8 *file, u8 *cachedData);
    extern s32 FldStepLoadHandleIsDone(u8 *handle);
    extern void FldStepLoadHandleDestroy(u8 *handle);
    extern s32 NpcTable_RequestSceneTable(void);
    extern s32 NpcTable_InstallSceneTable(u8 *request);
    extern s32 NpcTable_RequestSecondaryTable(void);
    extern s32 NpcTable_InstallSecondaryTable(u8 *request);
    extern s32 FldStepIndex(void);
    extern s32 fldStepRestoreBoard(s32 stepIndex);
    extern s32 fldStepSaveBoard(s32 stepIndex);
    extern void FldCellCreateGrid(void);
    extern void FldStepRefreshBandResVisibility(void);
    extern void FldBoardGenerate(s32 mode, s32 seed, s32 unused);
    extern void *mdlGetClump(void *model);
    extern s32 FldRcClumpSetMipmapTex(u8 *clump, s32 textureHandle);
    extern s32 func_003ef6d0(void);
    extern s32 func_003ef650(s32 majorId, u8 *minorId);
    extern void memcpy(void *dst, const void *src, s32 size);
    extern u8 *func_003e8180(u8 *majorId, f32 minorId);
    extern s32 D_007D24E0[];
    extern s32 D_007D24E8[];
    extern u8 D_005EFCB0[];
    u16 *hbnData;
    f32 fieldOfView;
    s32 cameraKind;
    f32 cameraValue60;
    f32 cameraValue64;
    SVec3 angles;
    Vec3 cameraPosition;
    FldResourceCameraTransform cameraMatrix;
    FldResourceCameraTransform secondaryCameraMatrix;
    s8 cameraEntries[0x20];
    Vec3 cameraEntryPositions[0x20];
    u8 *queuedWork;
    u8 *modelResource;
    u8 *nextEffectResource;
    u8 *lightWork;
    s32 modelId;
    u8 *pairCursor;
    u8 *ordinaryHbnResource;
    u8 *primaryOpenWork;
    u8 *partOpenResource;
    uintptr_t initialPrimary;
    u8 *partReadResource;
    u8 *partApplyResource;
    u8 *primaryReloadWork;
    u8 *partReloadResource;
    uintptr_t reloadedPrimary;
    u8 *reloadedReadResource;
    u8 *primaryApplyResource;
    u8 *reloadedApplyResource;
    u8 *environmentReloadWork;
    u8 *hbnOpenResource;
    u8 *gridHbnWork;
    u8 *bandHbnResource;
    u8 *modelEntryCursor;
    u8 *sceneModelResource;
    u8 *effectEntryCursor;
    u8 *sceneEffectResource;
    u8 *environmentWork;
    u8 *hbnQueueWork;
    u8 *ordinaryLightWork;
    u8 *modelFrameResource;
    u8 *environmentOpenWork;
    u8 *cameraOpenWork;
    u8 *cameraReadWork;
    u8 *partOpenWork;
    FldPartReadWork *initialPartWork;
    u8 *partReadWork;
    u8 *partApplyWork;
    u8 *partReloadWork;
    FldPartReadWork *reloadedPartWork;
    u8 *reloadedReadWork;
    u8 *reloadedApplyWork;
    u8 *queuePopWork;
    u8 *fieldWaitWork;
    u8 *fieldParseWork;
    u8 *fieldPollWork;
    u8 *fieldCountWork;
    u8 *minorIdWork;
    u8 *entryRequestWork;
    u8 *entryInstallWork;
    u8 *secondaryFile;
    u8 *effectFrameResource;
    u8 *cameraFile;
    u8 *environmentFile;
    u8 *primaryFile;
    u8 *fieldFile;
    u8 *initializedWork;
    u8 *completedSecondaryFile;
    u8 *mipmapWork;
    u8 *effectCountResource;
    s32 ordinaryPublishIndex;
    u8 *ordinaryPublishWork;
    s32 ordinaryPublishOffset;
    u8 *ordinaryDestination;
    u8 *ordinaryIndexTable;
    s32 ordinaryPreset;
    s32 ordinaryResource;
    u8 *ordinaryCountTable;
    s32 specialPublishIndex;
    u8 *specialPublishWork;
    s32 specialPublishOffset;
    u8 *specialDestination;
    u8 *specialIndexTable;
    s32 specialPreset;
    s32 specialResource;
    u8 *specialCountTable;
    u8 *effectResource;
    u8 *nextModelResource;
    u8 *frameMatrix;
    u32 *frameCount;
    u8 *hbnEntry;
    s32 spawnColumn;
    s32 pickRow;
    s32 modelClump;
    s32 effectId;
    s32 spawnRow;
    s32 pickColumn;
    s32 partApplyIndex;
    s32 reloadedApplyIndex;
    s32 spawnRowOffset;
    s32 pickRowOffset;
    s32 bandHbnOffset;
    s32 ordinaryHbnOffset;
    s32 partOpenOffset;
    s32 partReloadOffset;
    s32 entryPendingCount;
    s32 hbnOpenIndex;
    s32 partReadIndex;
    s32 partApplyPendingCount;
    s32 reloadedReadIndex;
    s32 reloadedApplyPendingCount;
    u32 modelFrameIndex;
    u32 effectFrameIndex;
    s32 reloadedApplyOffset;
    s32 hbnOpenOffset;
    s32 gridData;
    s32 spawnColumnOffset;
    s32 pickColumnOffset;
    s32 gridHbnFile;
    s32 modelFrameOffset;
    s32 effectFrameOffset;
    s32 partApplyOffset;
    s32 entryRequestIndex;
    s32 partReloadIndex;
    s32 reloadedReadPendingCount;
    s32 entryInstallIndex;
    s32 gridPendingCount;
    s32 bandHbnIndex;
    s32 bandLightIndex;
    s32 ordinaryHbnIndex;
    s32 ordinaryLightIndex;
    s32 partOpenIndex;
    s32 partReadPendingCount;
    s32 textureNames;
    u8 cellValue;
    u8 cellKind;
    s32 loadState;
    s32 allocatedBytes;
    s32 frameKind;
    s32 pendingCount;
    s32 readyCount;
    s32 loadResult;
    s32 one;
    s32 phaseResult;

    loadState = (s32)(((FldResourceWork *)iGpffff9db0)->state);
    if (loadState == 999) goto completed;
    if (loadState == 41) goto waitReloadedEnvironment;
    if (loadState == 40) goto loadEnvironment;
    if (loadState == 32) goto waitReloadedParts;
    if (loadState == 31) goto readReloadedParts;
    if (loadState == 30) goto reloadParts;
    if (loadState == 13) goto waitParts;
    if (loadState == 12) goto readParts;
    if (loadState == 11) goto loadParts;
    if (loadState == 10) goto readCamera;
    if (loadState == 9) goto waitEnvironment;
    if (loadState == 8) goto readHbnResources;
    if (loadState == 7) goto readGrid;
    if (loadState == 6) goto prepareGrid;
    if (loadState == 5) goto waitNpcTables;
    if (loadState == 4) goto loadNpcTables;
    if (loadState == 3) goto waitResourceInitialization;
    if (loadState == 2) goto initializeResources;
    one = 1;
    if (loadState == one) goto waitFieldResource;
    switch (loadState) {
    case 0: goto loadFieldResource;
    default: goto pending;
    }
loadFieldResource:
            if (fldResourceIsReadyWithDefault((u8 *)iGpffffb200, one) == 0) {
                return 0;
            }
            if (fldResourceIsReady((u8 *)iGpffffb204) == 0) {
                return 0;
            }
            queuePopWork = (u8 *)(iGpffff9db0);
            ((FldResourceWork *)queuePopWork)->queuedCount = (s32) (((FldResourceWork *)queuePopWork)->queuedCount - 1);
            queuedWork = (u8 *)(iGpffff9db0);
            pairCursor = (u8 *)(((FldResourceWork *)queuedWork)->queuedCount * 4);
            pairCursor += (s32)queuedWork;
            (((s32 *)(queuedWork + 0x28))[((FldResourceWork *)queuedWork)->resourceCount]) = (s32)FldRc_CreateResource(((FldResourceWork *)pairCursor)->queuedIds[0].majorId, ((FldResourceWork *)pairCursor)->queuedIds[0].minorId);
            ((FldResourceWork *)iGpffff9db0)->state = 1;
waitFieldResource:
            fieldWaitWork = (u8 *)(iGpffff9db0);
            if (FldResource_IsFileLoaded((((u8 **)(fieldWaitWork + 0x28))[((FldResourceWork *)fieldWaitWork)->resourceCount])) == 0) {
                return 0;
            }
            fieldParseWork = (u8 *)(iGpffff9db0);
            FldResource_ParseChunks((u8 *)((((s8 **)(fieldParseWork + 0x28))[((FldResourceWork *)fieldParseWork)->resourceCount])));
            ((FldResourceWork *)iGpffff9db0)->state = 2;
initializeResources:
            fieldPollWork = (u8 *)(iGpffff9db0);
            if (FldResource_PollLoads((((u8 **)(fieldPollWork + 0x28))[((FldResourceWork *)fieldPollWork)->resourceCount])) == 0) {
                return 0;
            }
            fieldCountWork = (u8 *)(iGpffff9db0);
            ((FldResourceWork *)fieldCountWork)->resourceCount = (s32) (((FldResourceWork *)fieldCountWork)->resourceCount + 1);
            initializedWork = (u8 *)(iGpffff9db0);
            if (((FldResourceWork *)initializedWork)->queuedCount > 0) {
                ((FldResourceWork *)initializedWork)->state = 0;
                return 0;
            }
            if (((FldResourceWork *)initializedWork)->flags & 0x80000000) {
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                ((FldResourceWork *)initializedWork)->majorId = (s32) *( s16 * )((u8 *)((FldResourceWork *)initializedWork)->resources[0] + 4);
                minorIdWork = (u8 *)(iGpffff9db0);
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                ((FldResourceWork *)minorIdWork)->minorId = (s32) *( s16 * )((u8 *)((FldResourceWork *)minorIdWork)->resources[0] + 6);
            }
            entryRequestIndex = 0;
            while (entryRequestIndex < ((FldResourceWork *)(entryRequestWork = (u8 *)(iGpffff9db0)))->resourceCount) {
                FldResource_RequestEntryLoads((u8 *)((FldResourceWork *)(entryRequestWork + (entryRequestIndex * 4)))->resources[0]);
                entryRequestIndex += 1;
            }
            ((FldResourceWork *)entryRequestWork)->state = 3;
waitResourceInitialization:
            entryPendingCount = 0;
            entryInstallIndex = 0;
            while (entryInstallIndex < ((FldResourceWork *)(entryInstallWork = (u8 *)(iGpffff9db0)))->resourceCount) {
                if (FldResource_TryInstallEntries((u8 *)((FldResourceWork *)(entryInstallWork + (entryInstallIndex * 4)))->resources[0]) == 0) {
                    entryPendingCount += 1;
                }
                entryInstallIndex += 1;
            }
            if (entryPendingCount != 0) {
                return 0;
            }
            completedSecondaryFile = (u8 *)(iGpffffb204);
            if (completedSecondaryFile != NULL) {
                H_Cdvd_Destroy(completedSecondaryFile);
                iGpffffb204 = 0;
            }
            textureNames = (s32)(((FldResourceWork *)iGpffff9db0)->textureNames);
            if (textureNames != 0) {
                K_Clump_FreeTextureNameList((void *)(textureNames));
                ((FldResourceWork *)iGpffff9db0)->textureNames = 0;
            }
            ((FldResourceWork *)iGpffff9db0)->state = 4;
loadNpcTables:
            allocatedBytes = (s32)(chkmemGetBytes() - iGpffffb208);
            iGpffffb208 = allocatedBytes;
            if (((FldResourceWork *)iGpffff9db0)->majorId < 0xC8) {
                iGpffffb208 = (s32) (allocatedBytes + 0x32000);
            }
            D_007D24E0[0] = NpcTable_RequestSceneTable();
            D_007D24E8[0] = NpcTable_RequestSecondaryTable();
            ((FldResourceWork *)iGpffff9db0)->state = 5;
waitNpcTables:
            if (NpcTable_InstallSceneTable((u8 *)D_007D24E0[0]) == 0) {
                return 0;
            }
            D_007D24E0[0] = 0;
            if (NpcTable_InstallSecondaryTable((u8 *)D_007D24E8[0]) == 0) {
                return 0;
            }
            D_007D24E8[0] = 0;
            ((FldResourceWork *)iGpffff9db0)->state = 6;
prepareGrid:
            ((FldResourceWork *)iGpffff9db0)->state = 7;
readGrid:
            gridPendingCount = 0;
            if (FldStepLoadHandleIsDone(((FldFrame *)MT_Scene_GetFrameState())->hbnHandle) == 0) {
                gridPendingCount += 1;
            }
            if (gridPendingCount != 0) {
                return 0;
            }
            hbnOpenIndex = 0;
            while (hbnOpenIndex < ((FldResourceWork *)(hbnQueueWork = (u8 *)(iGpffff9db0)))->resourceCount) {
                hbnOpenOffset = hbnOpenIndex * 4;
                if (((FldResource *)((u8 *)((FldResourceWork *)(hbnQueueWork + hbnOpenOffset))->resources[0]))->hbnData == 0) {
                    hbnOpenResource = (u8 *)((u8 *)((FldResourceWork *)(iGpffff9db0 + hbnOpenOffset))->resources[0]);
                    ((FldResource *)((u8 *)((FldResourceWork *)(iGpffff9db0 + hbnOpenOffset))->resources[0]))->hbnFile = (s32)FldHbnOpenData((u16)((FldResource *)hbnOpenResource)->majorId, (u16)((FldResource *)hbnOpenResource)->minorId);
                }
                hbnOpenIndex += 1;
            }
            if (FldMap_IsCurrentInBandB() != 0) {
                gridData = (s32)((s32)((HCdvdRequest *)((FldFrame *)MT_Scene_GetFrameState())->hbnHandle)->data);
                memcpy(((FldFrame *)MT_Scene_GetFrameState())->cells,(const void *)((u8 *)gridData + 4), 0x1800);
                FldStepLoadHandleDestroy(((FldFrame *)MT_Scene_GetFrameState())->hbnHandle);
                for (spawnRow = 0; spawnRow < 0x18; spawnRow++) {
                    spawnColumn = 0;
                    spawnRowOffset = spawnRow << 8;
                    for (; spawnColumn < 0x10; spawnColumn++) {
                        spawnColumnOffset = spawnColumn * 0x10;
                        if ((((FldFrame *)((u8 *)(spawnRowOffset + (s32)MT_Scene_GetFrameState()) + spawnColumnOffset))->cells[0][0].occupied == 1) && (((FldFrame *)((u8 *)(spawnRowOffset + (s32)MT_Scene_GetFrameState()) + spawnColumnOffset))->cells[0][0].type == 6)) {
                            ((FldFrame *)MT_Scene_GetFrameState())->spawnColumn = (u8)spawnColumn;
                            ((FldFrame *)MT_Scene_GetFrameState())->spawnRow = (u8)spawnRow;
                            goto foundSpawnCell;
                        }
                    }
                }
foundSpawnCell:
                for (pickRow = 0; pickRow < 0x18; pickRow++) {
                    pickColumn = 0;
                    pickRowOffset = pickRow << 8;
                    for (; pickColumn < 0x10; pickColumn++) {
                        pickColumnOffset = pickColumn * 0x10;
                        if ((((FldFrame *)((u8 *)(pickRowOffset + (s32)MT_Scene_GetFrameState()) + pickColumnOffset))->cells[0][0].occupied == 1) && ((((FldFrame *)((u8 *)(pickRowOffset + (s32)MT_Scene_GetFrameState()) + pickColumnOffset))->cells[0][0].type == 0xA) || (((FldFrame *)((u8 *)(pickRowOffset + (s32)MT_Scene_GetFrameState()) + pickColumnOffset))->cells[0][0].type == 0xC) || (((FldFrame *)((u8 *)(pickRowOffset + (s32)MT_Scene_GetFrameState()) + pickColumnOffset))->cells[0][0].type == 0xE))) {
                            ((FldFrame *)MT_Scene_GetFrameState())->cellPick[0] = (u8)pickColumn;
                            ((FldFrame *)MT_Scene_GetFrameState())->cellPick[1] = (u8)pickRow;
                            goto foundPickedCell;
                        }
                    }
                }
foundPickedCell:
                gridHbnWork = (u8 *)(iGpffff9db0);
                gridHbnFile = (s32)(FldHbnOpenData((u16)((FldResourceWork *)gridHbnWork)->majorId, (u16)((FldResourceWork *)gridHbnWork)->minorId));
                ((FldFrame *)MT_Scene_GetFrameState())->hbnHandle = (u8 *)gridHbnFile;
            }
            ((FldResourceWork *)iGpffff9db0)->state = 8;
readHbnResources:
            if (FldMap_IsCurrentInBandB() != 0) {
                hbnData = NULL;
                bandHbnIndex = 0;
                while (bandHbnIndex < ((FldResourceWork *)iGpffff9db0)->resourceCount) {
                    bandHbnResource = (u8 *)iGpffff9db0;
                    bandHbnOffset = bandHbnIndex * 4;
                    bandHbnResource = (u8 *)((u8 *)((FldResourceWork *)(bandHbnResource + bandHbnOffset))->resources[0]);
                    if (FldHbnReadData((u8 *)(((FldResource *)bandHbnResource)->hbnFile),(u16 **)&((FldResource *)bandHbnResource)->hbnData, (u16)((FldResource *)bandHbnResource)->majorId, (u16)((FldResource *)bandHbnResource)->minorId) == 0) {
                        return 0;
                    }
                    ((FldResource *)((u8 *)((FldResourceWork *)(iGpffff9db0 + bandHbnOffset))->resources[0]))->hbnFile = 0;
                    bandHbnIndex += 1;
                }
                bandLightIndex = 0;
                while (bandLightIndex < ((FldResourceWork *)(lightWork = (u8 *)(iGpffff9db0)))->resourceCount) {
                    FldHbnSpawnLights((u8 *)((s8 *)((FldResource *)((u8 *)((FldResourceWork *)(lightWork + (bandLightIndex * 4)))->resources[0]))->hbnDataPtr), 0);
                    bandLightIndex += 1;
                }
                if (FldHbnReadData(((FldFrame *)MT_Scene_GetFrameState())->hbnHandle,&hbnData, (u16)((FldResourceWork *)lightWork)->majorId, (u16)((FldResourceWork *)lightWork)->minorId) == 0) {
                    return 0;
                }
                if ((hbnEntry = (u8 *)hbnData) != NULL) {
                    FldHbnSpawnLights(hbnEntry, 1);
                    jtbl_008873EC[0](hbnData);
                    ((FldFrame *)MT_Scene_GetFrameState())->hbnHandle = 0;
                }
                goto publishResources;
            }
            ordinaryHbnIndex = 0;
            while (ordinaryHbnIndex < ((FldResourceWork *)iGpffff9db0)->resourceCount) {
                ordinaryHbnResource = (u8 *)iGpffff9db0;
                ordinaryHbnOffset = ordinaryHbnIndex * 4;
                ordinaryHbnResource = (u8 *)((u8 *)((FldResourceWork *)(ordinaryHbnResource + ordinaryHbnOffset))->resources[0]);
                if (FldHbnReadData((u8 *)(((FldResource *)ordinaryHbnResource)->hbnFile),(u16 **)&((FldResource *)ordinaryHbnResource)->hbnData, (u16)((FldResource *)ordinaryHbnResource)->majorId, (u16)((FldResource *)ordinaryHbnResource)->minorId) == 0) {
                    return 0;
                }
                ((FldResource *)((u8 *)((FldResourceWork *)(iGpffff9db0 + ordinaryHbnOffset))->resources[0]))->hbnFile = 0;
                ordinaryHbnIndex += 1;
            }
            ordinaryLightIndex = 0;
            while (ordinaryLightIndex < ((FldResourceWork *)(ordinaryLightWork = (u8 *)(iGpffff9db0)))->resourceCount) {
                FldHbnSpawnLights((u8 *)((s8 *)((FldResource *)((u8 *)((FldResourceWork *)(ordinaryLightWork + (ordinaryLightIndex * 4)))->resources[0]))->hbnDataPtr), 0);
                ordinaryLightIndex += 1;
            }
publishResources:
            if (FldMap_IsCurrentInBandA() == 1) {
                ordinaryPublishIndex = 0;
                ordinaryPublishWork = (u8 *)(iGpffff9db0);
                ordinaryDestination = (u8 *)D_007E8060;
                ordinaryIndexTable = (u8 *)D_005F05B8;
                ordinaryCountTable = (u8 *)D_005F0590;
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                while (ordinaryPreset = *(u8 *)(ordinaryIndexTable + ((FldResourceWork *)ordinaryPublishWork)->majorId - 0x28),
                       /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                       ordinaryPublishIndex < *(u8 *)(ordinaryCountTable + ordinaryPreset * 0xC)) {
                    ordinaryPublishOffset = ordinaryPublishIndex * 4;
                    ordinaryResource = ((FldResourceWork *)(ordinaryPublishWork + ordinaryPublishOffset))->resources[0];
                    *(s32 *)(ordinaryDestination + ordinaryPublishOffset) = ordinaryResource;
                    ordinaryPublishIndex += 1;
                }
                if (fldStepRestoreBoard(FldStepIndex()) == 0) {
                    FldBoardGenerate(((FldResourceWork *)iGpffff9db0)->majorId - 0x28, ((FldFrame *)MT_Scene_GetFrameState())->boardParam, 1);
                    fldStepSaveBoard(FldStepIndex());
                }
                FldCellCreateGrid();
                FldStepRefreshBandResVisibility();
            } else if (FldMap_IsCurrentInBandB() != 0) {
                specialPublishIndex = 0;
                specialPublishWork = (u8 *)(iGpffff9db0);
                specialDestination = (u8 *)D_007E8060;
                specialIndexTable = (u8 *)D_005F05B8;
                specialCountTable = (u8 *)D_005F0590;
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                while (specialPreset = *(u8 *)(specialIndexTable + ((FldResourceWork *)specialPublishWork)->majorId - 0x3C),
                       specialPublishIndex < ((FldResourcePreset *)(specialCountTable + specialPreset * 0xC))->specialCount) {
                    specialPublishOffset = specialPublishIndex * 4;
                    specialResource = ((FldResourceWork *)(specialPublishWork + specialPublishOffset))->resources[0];
                    *(s32 *)(specialDestination + specialPublishOffset) = specialResource;
                    specialPublishIndex += 1;
                }
                if (fldStepRestoreBoard(FldStepIndex()) == 0) {
                    fldStepSaveBoard(FldStepIndex());
                }
                FldCellCreateGrid();
                FldStepRefreshBandResVisibility();
            } else {
                MT_Scene_CreateFldRes(0, (u8 *)((FldResourceWork *)iGpffff9db0)->resources[0]);
                modelFrameIndex = 0;
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                while (modelFrameIndex < (u32) *( u32 * )((modelFrameResource = (u8 *)((u8 *)((FldResourceWork *)iGpffff9db0)->resources[0])) + 0x11C)) {
                    modelFrameOffset = modelFrameIndex * 0x18;
                    frameMatrix = (u8 *)(func_003e9700((RwFrame *)((FldResource *)(modelFrameResource + modelFrameOffset))->entries[0].frame));
                    frameKind = (((FldResource *)((u8 *)((FldResourceWork *)iGpffff9db0)->resources[0] + modelFrameOffset))->entries[0].type);
                    if ((frameKind == 0) || (frameKind == 2)) {
                        modelEntryCursor = (u8 *)((FldResourceWork *)iGpffff9db0)->resources[0];
                        modelEntryCursor += modelFrameIndex * 0x18;
                        modelId = (s32)(MT_Scene_CreateModelFldRes(((FldResource *)modelEntryCursor)->entries[0].id, ((FldResource *)modelEntryCursor)->entries[0].model) & 0xFFFF);
                        if (modelId == 0) {
                            kAssertFail((const char *)D_005EFC80, 0x297);
                        }
                        angles.x = KDraw_MatrixPitchDeg(frameMatrix);
                        angles.y = KDraw_MatrixYawDeg(frameMatrix);
                        angles.z = KDraw_MatrixRollDeg(frameMatrix);
                        MT_Scene_SetResPlacement(modelId, frameMatrix + 0x30, (u8 *)&angles);
                        mipmapWork = (u8 *)(iGpffff9db0);
                        if ((((FldResourceWork *)mipmapWork)->majorId != 0x14) || (((FldResourceWork *)mipmapWork)->minorId != 1)) {
                            modelClump = (s32)(mdlGetClump((void *)((FldResource *)((u8 *)((FldResourceWork *)iGpffff9db0)->resources[0] + modelFrameOffset))->entries[0].model));
                            if (FldRcClumpSetMipmapTex((u8 *)(modelClump), func_003ef650(func_003ef6d0(), D_005EFCB0)) == 1) {
                                sceneModelResource = (u8 *)(MT_Scene_GetRes(modelId));
                                ((ResrcRecord *)sceneModelResource)->unk28 = (s32) (((ResrcRecord *)sceneModelResource)->unk28 | 0x01000000);
                            }
                        }
                        if (((FldResource *)((u8 *)((FldResourceWork *)iGpffff9db0)->resources[0] + modelFrameOffset))->entries[0].flags & 2) {
                            sceneModelResource = (u8 *)(MT_Scene_GetRes(modelId));
                            ((ResrcRecord *)sceneModelResource)->value150 = 1;
                        }
                        ((FldResource *)((u8 *)((FldResourceWork *)iGpffff9db0)->resources[0] + modelFrameOffset))->entries[0].model = 0;
                    }
                    modelFrameIndex += 1;
                }
                effectFrameIndex = 0;
                while (effectFrameIndex < *(frameCount = (u32 *)((effectCountResource = (u8 *)((u8 *)((FldResourceWork *)iGpffff9db0)->resources[0])) + 0x11C))) {
                    effectFrameOffset = effectFrameIndex * 0x18;
                    func_003e9700((RwFrame *)((FldResource *)(effectCountResource + effectFrameOffset))->entries[0].frame);
                    effectFrameResource = (u8 *)((u8 *)((FldResourceWork *)iGpffff9db0)->resources[0]);
                    if (((FldResource *)(effectFrameResource + effectFrameOffset))->entries[0].type == 1) {
                        effectEntryCursor = (u8 *)(effectFrameResource + (effectFrameIndex * 0x18));
                        effectId = (s32)(MT_Scene_CreateRes11(((FldResource *)effectEntryCursor)->entries[0].id, ((FldResource *)effectEntryCursor)->entries[0].effect) & 0xFFFF);
                        if (effectId == 0) {
                            kAssertFail((const char *)D_005EFC80, 0x2C7);
                        }
                        ((FldResource *)((u8 *)((FldResourceWork *)iGpffff9db0)->resources[0] + effectFrameOffset))->entries[0].effect = 0;
                        sceneEffectResource = (u8 *)(MT_Scene_GetRes(effectId));
                        ((ResrcRecord *)sceneEffectResource)->unk28 = (s32) (((ResrcRecord *)sceneEffectResource)->unk28 | 2);
                    }
                    effectFrameIndex += 1;
                }
                *frameCount = 0U;
                resrcMngResetRenderSlots();
                {
                    s32 enable = 1;

                    resrcMngSetDrawEnabled(enable, enable);
                }
            }
            ((FldResourceWork *)iGpffff9db0)->environmentFile = FldEnvOpenFile(((FldResourceWork *)iGpffff9db0)->environmentId);
            if (((FldResourceWork *)iGpffff9db0)->majorId >= 0xC8) {
                func_003e8180((void *)(u32)kwlnGetCamera(), 100.0f);
            }
            if (((FldResourceWork *)iGpffff9db0)->majorId < 0xC8) {
                func_003e8180((void *)(u32)kwlnGetCamera(), 100.0f);
            }
            environmentOpenWork = (u8 *)(iGpffff9db0);
            if (((FldResourceWork *)environmentOpenWork)->environmentFile == 0) {
                ((FldResourceWork *)iGpffff9db0)->environmentFile = FldCamOpenFile();
                cameraOpenWork = (u8 *)(iGpffff9db0);
                if (((FldResourceWork *)cameraOpenWork)->environmentFile != 0) {
                    ((FldResourceWork *)cameraOpenWork)->state = 0xA;
                } else {
                    ((FldResourceWork *)cameraOpenWork)->state = 0xB;
                }
                goto pending;
            }
            ((FldResourceWork *)environmentOpenWork)->state = 9;
waitEnvironment:
            environmentWork = (u8 *)(iGpffff9db0);
            if (FldEnvironmentLoad((u8 *)(((FldResourceWork *)environmentWork)->environmentFile), ((FldResourceWork *)environmentWork)->environmentId) != 0) {
                ((FldResourceWork *)iGpffff9db0)->environmentFile = FldCamOpenFile();
                cameraReadWork = (u8 *)(iGpffff9db0);
                if (((FldResourceWork *)cameraReadWork)->environmentFile != 0) {
                    ((FldResourceWork *)cameraReadWork)->state = 0xA;
                } else {
                    ((FldResourceWork *)cameraReadWork)->state = 0xB;
                    goto pending;
                }
            } else {
                return 0;
            }
readCamera:
            if (FldCamReadRecord((u8 *)(((FldResourceWork *)iGpffff9db0)->environmentFile), (u8 *)&cameraMatrix, (u8 *)&secondaryCameraMatrix, &fieldOfView, &cameraKind, (u8 *)&cameraPosition, &cameraValue60, &cameraValue64, (s32 *)cameraEntries, (s32 *)cameraEntryPositions) != 0) {
                MT_Scene_CreateCameraRes(0, cameraKind, fieldOfView, (u8 *)&cameraMatrix, (u8 *)&secondaryCameraMatrix, (u8 *)&cameraPosition, cameraValue60, cameraValue64, cameraEntries, cameraEntryPositions);
                ((FldResourceWork *)iGpffff9db0)->state = 0xB;
                goto pending;
            }
            return 0;
loadParts:
        if (FldMap_IsCurrentInBandB() == 1) {
            primaryOpenWork = (u8 *)(iGpffff9db0);
            ((FldResource *)(u8 *)((FldResourceWork *)iGpffff9db0)->resources[0])->fbnFile = (s32)FldFbnOpenData((u16)((FldResourceWork *)primaryOpenWork)->majorId, (u16)((FldResourceWork *)primaryOpenWork)->minorId, ((FldResourceWork *)primaryOpenWork)->variant);
        } else {
            partOpenIndex = 0;
            while (partOpenIndex < ((FldResourceWork *)iGpffff9db0)->resourceCount) {
                partOpenWork = (u8 *)(iGpffff9db0);
                partOpenOffset = partOpenIndex * 4;
                partOpenResource = (u8 *)((u8 *)((FldResourceWork *)(partOpenWork + partOpenOffset))->resources[0]);
                ((FldResource *)((u8 *)((FldResourceWork *)(iGpffff9db0 + partOpenOffset))->resources[0]))->fbnFile = (s32)FldFbnOpenData((u16)((FldResource *)partOpenResource)->majorId, (u16)((FldResource *)partOpenResource)->minorId, ((FldResourceWork *)partOpenWork)->variant);
                partOpenIndex += 1;
            }
        }
        ((FldResourceWork *)iGpffff9db0)->state = 0xC;
        /* fallthrough */
readParts:
        partReadPendingCount = 0;
        initialPrimary = FldMap_IsCurrentInBandB();
        if (initialPrimary == 1) {
            initialPartWork = (FldPartReadWork *)iGpffff9db0;
            initialPrimary = (uintptr_t)initialPartWork->primaryResource;
            if (FldFbnReadTable(((FldResourceFbn *)initialPrimary)->file,
                             &((FldResourceFbn *)initialPrimary)->data,
                             (u16)initialPartWork->majorId,
                             (u16)initialPartWork->minorId,
                             initialPartWork->variant) == 0) {
                partReadPendingCount += 1;
            }
        } else {
            partReadIndex = 0;
            while (partReadIndex < ((FldResourceWork *)iGpffff9db0)->resourceCount) {
                partReadWork = (u8 *)(iGpffff9db0);
                partReadResource = (u8 *)((u8 *)((FldResourceWork *)(partReadWork + (partReadIndex * 4)))->resources[0]);
                if (FldFbnReadTable((u8 *)(((FldResource *)partReadResource)->fbnFile), (u8 **)&((FldResource *)partReadResource)->fbnData, (u16)((FldResource *)partReadResource)->majorId, (u16)((FldResource *)partReadResource)->minorId, ((FldResourceWork *)partReadWork)->variant) == 0) {
                    partReadPendingCount += 1;
                }
                partReadIndex += 1;
            }
        }
        if (partReadPendingCount != 0) {
            return 0;
        }
        ((FldResourceWork *)iGpffff9db0)->state = 0xD;
waitParts:
        partApplyPendingCount = 0;
        partApplyIndex = 0;
        while (partApplyIndex < ((FldResourceWork *)(partApplyWork = (u8 *)(iGpffff9db0)))->resourceCount) {
            partApplyResource = (u8 *)iGpffff9db0;
            partApplyOffset = partApplyIndex * 4;
            partApplyResource = (u8 *)((u8 *)((FldResourceWork *)(partApplyResource + partApplyOffset))->resources[0]);
            if (FldFbnApplyTable((u8 *)(((FldResource *)partApplyResource)->fbnFile),(u8 *)(((FldResource *)partApplyResource)->fbnDataWord)) == 0) {
                partApplyPendingCount += 1;
            } else {
                ((FldResource *)((u8 *)((FldResourceWork *)(iGpffff9db0 + partApplyOffset))->resources[0]))->fbnFile = 0;
            }
            partApplyIndex += 1;
        }
        if (partApplyPendingCount != 0) {
            return 0;
        }
        ((FldResourceWork *)partApplyWork)->state = 0x3E7;
        goto pending;
reloadParts:
        modelResource = (u8 *)(MT_Scene_GetResListHead(3));
        effectResource = (u8 *)(MT_Scene_GetResListHead(8));
        if (fldResourceIsReady((u8 *)iGpffffb200) != 0) {
            while (modelResource != NULL) {
                nextModelResource = (u8 *)((u8 *)((ResrcRecord *)modelResource)->next);
                MT_Scene_DestroyRes((u16)((FldResource *)modelResource)->flags);
                modelResource = (u8 *)(nextModelResource);
            }
            while (effectResource != NULL) {
                nextEffectResource = (u8 *)((u8 *)((ResrcRecord *)effectResource)->next);
                MT_Scene_DestroyRes((u16)((FldResource *)effectResource)->flags);
                effectResource = (u8 *)(nextEffectResource);
            }
            if (FldMap_IsCurrentInBandB() == 1) {
                primaryReloadWork = (u8 *)(iGpffff9db0);
                ((FldResource *)(u8 *)((FldResourceWork *)iGpffff9db0)->resources[0])->fbnFile = (s32)FldFbnOpenData((u16)((FldResourceWork *)primaryReloadWork)->majorId, (u16)((FldResourceWork *)primaryReloadWork)->minorId, ((FldResourceWork *)primaryReloadWork)->variant);
            } else {
                partReloadIndex = 0;
                while (partReloadIndex < ((FldResourceWork *)iGpffff9db0)->resourceCount) {
                    partReloadWork = (u8 *)(iGpffff9db0);
                    partReloadOffset = partReloadIndex * 4;
                    partReloadResource = (u8 *)((u8 *)((FldResourceWork *)(partReloadWork + partReloadOffset))->resources[0]);
                    ((FldResource *)((u8 *)((FldResourceWork *)(iGpffff9db0 + partReloadOffset))->resources[0]))->fbnFile = (s32)FldFbnOpenData((u16)((FldResource *)partReloadResource)->majorId, (u16)((FldResource *)partReloadResource)->minorId, ((FldResourceWork *)partReloadWork)->variant);
                    partReloadIndex += 1;
                }
            }
            ((FldResourceWork *)iGpffff9db0)->state = 0x1F;
readReloadedParts:
            reloadedReadPendingCount = 0;
            reloadedPrimary = FldMap_IsCurrentInBandB();
            if (reloadedPrimary == 1) {
                reloadedPartWork = (FldPartReadWork *)iGpffff9db0;
                reloadedPrimary = (uintptr_t)reloadedPartWork->primaryResource;
                if (FldFbnReadTable(((FldResourceFbn *)reloadedPrimary)->file,
                                 &((FldResourceFbn *)reloadedPrimary)->data,
                                 (u16)reloadedPartWork->majorId,
                                 (u16)reloadedPartWork->minorId,
                                 reloadedPartWork->variant) == 0) {
                    reloadedReadPendingCount += 1;
                }
            } else {
                reloadedReadIndex = 0;
                while (reloadedReadIndex < ((FldResourceWork *)iGpffff9db0)->resourceCount) {
                    reloadedReadWork = (u8 *)(iGpffff9db0);
                    reloadedReadResource = (u8 *)((u8 *)((FldResourceWork *)(reloadedReadWork + (reloadedReadIndex * 4)))->resources[0]);
                    if (FldFbnReadTable((u8 *)(((FldResource *)reloadedReadResource)->fbnFile), (u8 **)&((FldResource *)reloadedReadResource)->fbnData, (u16)((FldResource *)reloadedReadResource)->majorId, (u16)((FldResource *)reloadedReadResource)->minorId, ((FldResourceWork *)reloadedReadWork)->variant) == 0) {
                        reloadedReadPendingCount += 1;
                    }
                    reloadedReadIndex += 1;
                }
            }
            if (reloadedReadPendingCount != 0) {
                return 0;
            }
            ((FldResourceWork *)iGpffff9db0)->state = 0x20;
waitReloadedParts:
            reloadedApplyPendingCount = 0;
            if (FldMap_IsCurrentInBandB() == 1) {
                primaryApplyResource = (u8 *)((u8 *)((FldResourceWork *)iGpffff9db0)->resources[0]);
                if (FldFbnApplyTable((u8 *)(((FldResource *)primaryApplyResource)->fbnFile),(u8 *)(((FldResource *)primaryApplyResource)->fbnDataWord)) == 0) {
                    reloadedApplyPendingCount += 1;
                } else {
                    ((FldResource *)(u8 *)((FldResourceWork *)iGpffff9db0)->resources[0])->fbnFile = 0;
                }
            } else {
                reloadedApplyIndex = 0;
                while (reloadedApplyIndex < ((FldResourceWork *)iGpffff9db0)->resourceCount) {
                    reloadedApplyResource = (u8 *)iGpffff9db0;
                    reloadedApplyOffset = reloadedApplyIndex * 4;
                    reloadedApplyResource = (u8 *)((u8 *)((FldResourceWork *)(reloadedApplyResource + reloadedApplyOffset))->resources[0]);
                    if (FldFbnApplyTable((u8 *)(((FldResource *)reloadedApplyResource)->fbnFile),(u8 *)(((FldResource *)reloadedApplyResource)->fbnDataWord)) == 0) {
                        reloadedApplyPendingCount += 1;
                    } else {
                        ((FldResource *)((u8 *)((FldResourceWork *)(iGpffff9db0 + reloadedApplyOffset))->resources[0]))->fbnFile = 0;
                    }
                    reloadedApplyIndex += 1;
                }
            }
            if (reloadedApplyPendingCount != 0) {
                return 0;
            }
            reloadedApplyWork = (u8 *)(iGpffff9db0);
            if (((FldResourceWork *)reloadedApplyWork)->flags & 4) {
                ((FldResourceWork *)reloadedApplyWork)->state = 0x28;
            } else {
                ((FldResourceWork *)reloadedApplyWork)->state = 0x3E7;
                goto pending;
            }
loadEnvironment:
            if (fldResourceIsReady((u8 *)iGpffffb200) == 0) {
                goto pending;
            }
            ((FldResourceWork *)iGpffff9db0)->environmentFile = FldEnvOpenFile(((FldResourceWork *)iGpffff9db0)->environmentId);
            ((FldResourceWork *)iGpffff9db0)->state = 0x29;
waitReloadedEnvironment:
            environmentReloadWork = (u8 *)(iGpffff9db0);
            if (FldEnvironmentLoad((u8 *)(((FldResourceWork *)environmentReloadWork)->environmentFile), ((FldResourceWork *)environmentReloadWork)->environmentId) != 0) {
                ((FldResourceWork *)iGpffff9db0)->state = 0x3E7;
                goto pending;
            }
            return 0;
        }
        goto pending;
completed:
        primaryFile = (u8 *)(iGpffffb200);
        if (primaryFile != NULL) {
            H_Cdvd_Destroy(primaryFile);
            iGpffffb200 = 0;
        }
        return 1;
pending:
    return 0;
}
#pragma pop
/* measured: opt_loop_invariants hoists the slash loop constant. */
#pragma push
#pragma opt_loop_invariants on

/* Allocate a resource and load state, parse fNNN_NNN IDs, and request its directory. */
/* Earlier whole-layout probe changed 442 normalized bytes at equal size; only measured access-site exceptions remain. */
// FUN_00150970
u8 *FldResource_Create(char *path)
{
    u32 base;
    u8 *resource;
    u8 *work;
    s32 valid = 1;
    struct {
        char token[4];
        char pad[4];
    } local;

    chkmemAllocSiteTag(D_005EFC80, 0x460);
    base = (u32)D_008873F4;
    resource = ((u8 *(*)(s32, s32, s32))((FldResource *)base)->flags)(valid, 0xAB0, 0x40000);
    if (resource == NULL) {
        return resource;
    }
    chkmemAllocSiteTag(D_005EFC80, 0x462);
    work = ((u8 *(*)(s32, s32, s32))((FldResource *)base)->flags)(valid, 0x12C, 0x40000);
    *(u8 **)(resource + 0xA44) = work;
    if (work == NULL) {
        jtbl_008873EC[0](resource);
        return NULL;
    }
    strcpy((char *)work, path);
    while (*path != '\0') {
        path++;
    }
    for (; *path != '/'; path--) {
    }
    if (path[1] == 'f') {
        if ((D_00754D88[(s8)path[2]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)path[3]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)path[4]] & 4) == 0) {
            valid = 0;
        }
        if (path[5] != '_') {
            valid = 0;
        }
        if ((D_00754D88[(s8)path[6]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)path[7]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)path[8]] & 4) == 0) {
            valid = 0;
        }
    } else {
        valid = 0;
    }
    if (valid) {
        local.token[0] = path[2];
        local.token[1] = path[3];
        local.token[2] = path[4];
        local.token[3] = '\0';
        ((FldResource *)resource)->majorId = (u16)atoi(local.token);
        local.token[0] = path[6];
        local.token[1] = path[7];
        local.token[2] = path[8];
        local.token[3] = '\0';
        ((FldResource *)resource)->minorId = (u16)atoi(local.token);
    } else {
        ((FldResource *)resource)->majorId = -1;
        ((FldResource *)resource)->minorId = -1;
    }
    if (iGpffffb204 == 0) {
        func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0x4A5);
        ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->directory =
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            H_Cdvd_AcquireDirectory(*(char **)(resource + 0xA44), 0);
    } else {
        ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->directory = 1;
    }
    return resource;
}
#pragma pop

/* Poll the resource directory; shared secondary-directory resources are already available. */
/* The load-state directory handle retains the pointer/integer transport used by the CDVD ABI. */
// FUN_00150C80
s32 FldResource_IsFileLoaded(u8 *resource)
{
    u8 *file;

    file = (u8 *)((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->directory;
    if (file == NULL) {
        return 1;
    }
    if (iGpffffb204 == 0) {
        return H_Cdvd_IsFileLoaded((s32)file) != 0;
    }
    return 1;
}

/* measured: 988B/992B, all emitted instructions match; 4B retail zero tail.
   The stream descriptors and complete chunk header are real helper storage.
   Keep resource snapshots on their retail side of the asynchronous callbacks. */
/* Dispatch world, clump, texture and animation chunks to asynchronous readers. */
/* Earlier whole-layout probe: 988 -> 1016 bytes; the mixed body retains only measured load-state/stream exceptions. */
// FUN_00150CE0
void FldResource_ParseChunks(u8 *resource)
{
    s32 size;
    s32 memory[2]; /* RwMemory: start, length. */
    s32 chunkMemory[2];
    u32 chunk[5]; /* RwChunkHeaderInfo, including the unsigned byte length. */
    s32 data;
    s32 callbackHandle;
    s32 streamHandle;
    s32 child;
    u8 *destination;

    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
    data = H_Cdvd_LookupRequest(*(u8 **)(resource + 0xA44), &size);
    memory[0] = data;
    memory[1] = size;
    if (data != 0) {
        streamHandle = func_003e2f60(3, 1, &memory[0]);
        if (streamHandle != 0) {
            while (func_003df3c0(streamHandle, (s32 *)chunk) != 0) {
                switch (chunk[0]) {
                case 11:
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    if (((FldResourceLoadWork *)(*(u8 **)(resource + 0xA44) +
                                 /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                                 (s32)((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->worldCount * 4))->worldReaders[0] == 0) {
                        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                        chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    }
                    chunkMemory[1] = memory[1];
                    child = func_003e2f60(3, 1, &chunkMemory[0]);
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    destination = *(u8 **)(resource + 0xA44);
                    child = filerEnqueueRequest(1, 0, 0, 0, child, 0, 0, 0, 0, 0);
                    ((FldResourceLoadWork *)(destination + (s32)((FldResourceLoadWork *)destination)->worldCount * 4))->worldReaders[0] = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->worldCount =
                        ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->worldCount + 1;
                    break;
                case 16:
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    chunkMemory[1] = memory[1];
                    child = func_003e2f60(3, 1, &chunkMemory[0]);
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    destination = *(u8 **)(resource + 0xA44);
                    child = filerEnqueueRequest(2, 0, 0, 0, child, 0, 0, 0, 0, 0);
                    ((FldResourceLoadWork *)(destination + (s32)((FldResourceLoadWork *)destination)->clumpCount * 4))->clumpReaders[0] = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->clumpCount =
                        ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->clumpCount + 1;
                    break;
                case 35:
                    callbackHandle = func_003dc370((void *)streamHandle);
                    func_003ef260((const struct RwTexDictionary *)(u32)callbackHandle, K_Clump_AppendTextureName,
                                  ((FldResource *)resource)->loadWork + 0x128);
                    func_003ef1b0(callbackHandle);
                    break;
                case 22:
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    chunkMemory[1] = memory[1];
                    child = filerEnqueueRequest(8, 0, 0, 0, func_003e2f60(3, 1, &chunkMemory[0]), 0, 0, 0, 0, 0);
                    ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->textureReader = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    break;
                case 12:
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    chunkMemory[1] = memory[1];
                    child = filerEnqueueRequest(0xB, 0, 0, 0, func_003e2f60(3, 1, &chunkMemory[0]), 0, 0, 0, 0, 0);
                    ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->animationReader = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    break;
                default:
                    func_003e2ce0(streamHandle, chunk[1]);
                    break;
                }
            }
            if (streamHandle != 0) {
                func_003e2e40(streamHandle, 0);
            }
        } else {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            if (*(u8 **)(resource + 0xA44) != NULL) {
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                H_Cdvd_Destroy((u8 *)((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->directory);
                jtbl_008873EC[0](((FldResource *)resource)->loadWork);
            }
            if (resource != NULL) {
                jtbl_008873EC[0](resource);
            }
        }
    }
}

/* Install completed chunk readers and return one after every pending reader is consumed. */
/* Earlier whole-layout probe: 1240/1216 bytes. The remaining raw resource loads are individually measured below. */
// FUN_001510C0
s32 FldResource_PollLoads(u8 *resource)
{
    s32 stream;
    s32 status;
    s32 pendingCount;
    u32 worldIndex;
    s32 dictionary;
    u8 *world;
    u8 *clump;
    u32 clumpIndex;

    pendingCount = 0;
    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
    if (*(u8 **)(resource + 0xA44) == NULL) {
        return 1;
    }
    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
    if (((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->textureReader != 0) {
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        if (((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->textureNames != 0) {
            kAssertFail((const char *)D_005EFC80, 0x56C);
        }
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        dictionary = (s32)filerTakeCompletedRequest(((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->textureReader, &status, &stream);
        if (status == 1) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003ef260((const struct RwTexDictionary *)(u32)dictionary, K_Clump_AppendTextureName, *(u8 **)(resource + 0xA44) + 0x128);
            func_003ef1b0(dictionary);
            ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->textureReader = 0;
            if (stream != 0) {
                func_003e2e40(stream, 0);
            }
        } else {
            pendingCount += 1;
        }
    }
    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
    for (worldIndex = 0; worldIndex < ((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->worldCount; worldIndex++) {
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        if (((FldResourceLoadWork *)(*(u8 **)(resource + 0xA44) + worldIndex * 4))->worldReaders[0] != 0) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            world = filerTakeCompletedRequest(((FldResourceLoadWork *)(*(u8 **)(resource + 0xA44) + worldIndex * 4))->worldReaders[0], &status, &stream);
            if (status == 1) {
                if (world == NULL) {
                    kAssertFail((const char *)D_005EFC80, 0x588);
                }
                if (K_Clump_GeometryHasMatUsrData(world, D_005EFCE0) != 0) {
                    ((FldResource *)resource)->alternateObject = (s32)world;
                } else if (K_Clump_GeometryHasMatUsrData(world, D_005EFD00) != 0) {
                    ((FldResource *)resource)->secondaryObject = (s32)world;
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                } else if (*(s32 *)(resource + 0xC) == 0) {
                    ((FldResource *)resource)->primaryDrawObject = (s32)world;
                    func_003db550(world, (void *)(u32)kwlnGetCamera());
                } else {
                    ((FldResource *)resource)->primaryObject = (s32)world;
                }
                ((FldResourceLoadWork *)(((FldResource *)resource)->loadWork + worldIndex * 4))->worldReaders[0] = 0;
                ((FldResource *)resource)->flags = ((FldResource *)resource)->flags | 1;
                if (stream != 0) {
                    func_003e2e40(stream, 0);
                }
            } else {
                pendingCount += 1;
            }
        }
    }
    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
    for (clumpIndex = 0; clumpIndex < ((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->clumpCount; clumpIndex++) {
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        if (((FldResourceLoadWork *)(*(u8 **)(resource + 0xA44) + clumpIndex * 4))->clumpReaders[0] != 0) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            clump = filerTakeCompletedRequest(((FldResourceLoadWork *)(*(u8 **)(resource + 0xA44) + clumpIndex * 4))->clumpReaders[0], &status, &stream);
            if (status == 1) {
                if (clump == NULL) {
                    kAssertFail((const char *)D_005EFC80, 0x5B4);
                }
                if (K_Clump_ClumpHasMatUsrData(clump, D_005EFCE0) != 0) {
                    ((FldResource *)resource)->alternateObject = (s32)clump;
                } else if (K_Clump_ClumpHasMatUsrData(clump, D_005EFD00) != 0) {
                    ((FldResource *)resource)->secondaryObject = (s32)clump;
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                } else if (!(((FldResource *)resource)->flags & 1) && *(s32 *)(resource + 8) == 0) {
                    ((FldResource *)resource)->primaryObject = (s32)clump;
                    ((FldResource *)resource)->primaryDrawObjectPtr = sdkClumpCreateBuckets(clump);
                } else {
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    ((FldResource *)(resource + *(s32 *)(resource + 0x18) * 4))->clumps[0] = (s32)clump;
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    ((FldResource *)(resource + *(s32 *)(resource + 0x18) * 4))->drawObjectPointers[0] = sdkClumpCreateBuckets(clump);
                    ((FldResource *)resource)->clumpCount = (s32)((FldResource *)resource)->clumpCount + 1;
                }
                ((FldResourceLoadWork *)(((FldResource *)resource)->loadWork + clumpIndex * 4))->clumpReaders[0] = 0;
                if (stream != 0) {
                    func_003e2e40(stream, 0);
                }
            } else {
                pendingCount += 1;
            }
        }
    }
    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
    if (((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->animationReader != 0) {
        *(s32 *)(resource + 0xA20) = (s32)filerTakeCompletedRequest(((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->animationReader, &status, &stream);
        if (status == 1) {
            if (stream != 0) {
                func_003e2e40(stream, 0);
            }
            if (((FldResource *)resource)->animation == 0) {
                kAssertFail((const char *)D_005EFC80, 0x5D9);
            }
            ((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->animationReader = 0;
        } else {
            pendingCount += 1;
        }
    }
    if (pendingCount == 0) {
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        if (*(s32 *)(resource + 8) == 0) {
            ((FldResource *)resource)->flags = ((FldResource *)resource)->flags | 0x10000000;
            ((FldResource *)resource)->primaryObject = ((FldResource *)resource)->primaryDrawObject;
        }
        if (!(((FldResource *)resource)->flags & 1) && (s32)((FldResource *)resource)->clumpCount == 0) {
            ((FldResource *)resource)->flags = ((FldResource *)resource)->flags | 0x10000000;
        }
        if (iGpffffb204 == 0) {
            H_Cdvd_Destroy((u8 *)((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->directory);
        }
        ((FldResource *)resource)->scaleXBits = 0x3F800000;
        ((FldResource *)resource)->scaleYBits = 0x3F800000;
        ((FldResource *)resource)->scaleZBits = 0x3F800000;
        return 1;
    }
    return 0;
}

/* Find the first non-effect property frame with the requested ID; also publish its flag. */
/* measured: typed clump-pointer reads change this body; retain only the marked cursor reads. */
// FUN_00151580
s32 FldResource_FindFrameForId(u8 *resource, s32 entryId, s32 *flagsOut)
{
    KClumpIntPropertyResult kindProperty;
    KClumpIntPropertyResult idProperty;
    KClumpIntPropertyResult flagsProperty;
    s32 clumpIndex;
    s32 propertyIndex;
    u8 *clumpCursor;
    s32 result;
    s32 propertyCount;

    result = 0;
    for (clumpIndex = 0; clumpIndex < ((FldResource *)resource)->clumpCount; clumpIndex++) {
        clumpCursor = resource + clumpIndex * 4;
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        propertyCount = K_Clump_CountIntUsrData(*(void **)(clumpCursor + 0x1C), (const char *)D_005EFD20);
        for (propertyIndex = 0; propertyIndex < propertyCount; propertyIndex++) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            K_Clump_GetIntUsrDataAt(&idProperty, *(void **)(clumpCursor + 0x1C), (const char *)D_005EFD40, propertyIndex);
            if (idProperty.value == 0) {
                kAssertFail((const char *)D_005EFC80, 0x622);
            }
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            K_Clump_GetIntUsrDataAt(&kindProperty, *(void **)(clumpCursor + 0x1C), (const char *)D_005EFD20, propertyIndex);
            K_Clump_GetIntUsrDataAt(&flagsProperty, (void *)((FldResource *)clumpCursor)->clumps[0], (const char *)D_005EFD60, propertyIndex);
            if (flagsProperty.value != 0) {
                *flagsOut = 1;
            } else {
                *flagsOut = 0;
            }
            if (kindProperty.value != 1 && entryId == idProperty.value) {
                result = (s32)kindProperty.frame;
                goto out;
            }
        }
    }
out:
    return result;
}

/* Read clump user properties and request the model/effect assets for each entry. */
/* Earlier whole-layout probe: 1416/1392 bytes. Only the marked clump/count reads remain raw. */
// FUN_00151710
void FldResource_RequestEntryLoads(u8 *resource)
{
    s32 propertyCount;
    u8 *clumpCursor;
    u32 clumpIndex;
    s32 propertyIndex;
    u32 modelSize;
    s32 effectSize;
    KClumpIntPropertyResult kindProperty;
    KClumpIntPropertyResult assetProperty;
    KClumpIntPropertyResult flagsProperty;
    KClumpIntPropertyResult idProperty;
    KClumpIntPropertyResult hiddenProperty;
    char modelPath[0x40];
    char modelSuffix[0x40];
    char effectPath[0x40];
    char effectSuffix[0x40];
    char sharedModelPath[0x40];
    char sharedModelSuffix[0x40];
    s32 modelData;

    for (clumpIndex = 0; clumpIndex < ((FldResource *)resource)->clumpCount; clumpIndex++) {
        clumpCursor = resource + clumpIndex * 4;
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        propertyCount = K_Clump_CountIntUsrData(*(void **)(clumpCursor + 0x1C), (const char *)D_005EFD20);
        for (propertyIndex = 0; propertyIndex < propertyCount; propertyIndex++) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            K_Clump_GetIntUsrDataAt(&assetProperty, *(void **)(clumpCursor + 0x1C), (const char *)D_005EFD80, propertyIndex);
            if (assetProperty.value != 0) {
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                K_Clump_GetIntUsrDataAt(&idProperty, *(void **)(clumpCursor + 0x1C), (const char *)D_005EFD40, propertyIndex);
                if (idProperty.value == 0) {
                    kAssertFail((const char *)D_005EFC80, 0x65A);
                }
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                ((FldResource *)(resource + *(u32 *)(resource + 0x11C) * 0x18))->entries[0].id = (u16)idProperty.value;
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                K_Clump_GetIntUsrDataAt(&hiddenProperty, *(void **)(clumpCursor + 0x1C), (const char *)D_005EFD60, propertyIndex);
                if (hiddenProperty.value != 0) {
                    ((FldResource *)(resource + ((FldResource *)resource)->entryCount * 0x18))->entries[0].flags = 2;
                }
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                K_Clump_GetIntUsrDataAt(&kindProperty, *(void **)(clumpCursor + 0x1C), (const char *)D_005EFD20, propertyIndex);
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                ((FldResource *)(resource + *(u32 *)(resource + 0x11C) * 0x18))->entries[0].type = (u16)kindProperty.value;
                if (kindProperty.value == 0) {
                    if (iGpffffb204 == 0) {
                        strcpy(modelPath, D_005EFD98);
                        sprintf(modelSuffix, &iGpffff9e10, ((FldResource *)resource)->majorId);
                        strcat(modelPath, modelSuffix);
                        sprintf(modelSuffix, D_005EFDA8, assetProperty.value);
                        strcat(modelPath, modelSuffix);
                        ((FldResource *)(resource + ((FldResource *)resource)->entryCount * 0x18))->entries[0].model = (s32)mdlCreateModelObjectFromData(4, (u16)assetProperty.value, modelPath, 0);
                    } else {
                        strcpy(modelPath, D_005EFDB8);
                        sprintf(modelSuffix, &iGpffff9e10, ((FldResource *)resource)->majorId);
                        strcat(modelPath, modelSuffix);
                        sprintf(modelSuffix, D_005EFDA8, assetProperty.value);
                        strcat(modelPath, modelSuffix);
                        modelData = H_Cdvd_LookupRequest(modelPath, (s32 *)&modelSize);
                        ((FldResource *)(resource + ((FldResource *)resource)->entryCount * 0x18))->entries[0].model = (s32)mdlCreateModelObjectFromMemory(4, (u16)assetProperty.value, (void *)modelData, modelSize, 0);
                    }
                } else if (kindProperty.value == 1) {
                    if (iGpffffb204 == 0) {
                        strcpy(effectPath, D_005EFDC8);
                        sprintf(effectSuffix, &iGpffff9e10, ((FldResource *)resource)->majorId);
                        strcat(effectPath, effectSuffix);
                        sprintf(effectSuffix, D_005EFDD8, assetProperty.value);
                        strcat(effectPath, effectSuffix);
                        func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0x6A1);
                        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                        ((FldResource *)(resource + *(u32 *)(resource + 0x11C) * 0x18))->entries[0].file = H_Cdvd_AcquireDirectory(effectPath, 0);
                        if (((FldResource *)(resource + ((FldResource *)resource)->entryCount * 0x18))->entries[0].file == 0) {
                            kAssertFail((const char *)D_005EFC80, 0x6A2);
                        }
                    } else {
                        strcpy(effectPath, D_005EFDE8);
                        sprintf(effectSuffix, &iGpffff9e10, ((FldResource *)resource)->majorId);
                        strcat(effectPath, effectSuffix);
                        sprintf(effectSuffix, D_005EFDD8, assetProperty.value);
                        strcat(effectPath, effectSuffix);
                        ((FldResource *)(resource + ((FldResource *)resource)->entryCount * 0x18))->entries[0].file = H_Cdvd_LookupRequest(effectPath, &effectSize);
                    }
                } else if (kindProperty.value == 2) {
                    strcpy(sharedModelPath, D_005EFE00);
                    sprintf(sharedModelSuffix, D_005EFDA8, assetProperty.value);
                    strcat(sharedModelPath, sharedModelSuffix);
                    ((FldResource *)(resource + ((FldResource *)resource)->entryCount * 0x18))->entries[0].model = (s32)mdlCreateModelObjectFromData(4, (u16)(assetProperty.value + 0x3E8), sharedModelPath, 0);
                }
                K_Clump_GetIntUsrDataAt(&flagsProperty, (void *)((FldResource *)clumpCursor)->clumps[0], (const char *)D_005EFE10, propertyIndex);
                if (kindProperty.value == 0) {
                    ((FldResource *)(resource + ((FldResource *)resource)->entryCount * 0x18))->entries[0].flags |= (u16)flagsProperty.value;
                }
                ((FldResource *)(resource + ((FldResource *)resource)->entryCount * 0x18))->entries[0].frame = (s32)kindProperty.frame;
                ((FldResource *)resource)->entryCount = ((FldResource *)resource)->entryCount + 1;
            }
        }
    }
}

/* Wait for every entry, apply model placements, create effects and release temporary load state. */
/* Earlier whole-layout probe: 776/768 bytes. Only marked count/effect/load-state reads remain raw. */
// FUN_00151C80
s32 FldResource_TryInstallEntries(u8 *resource)
{
    u32 checkIndex;
    u32 installIndex;

    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
    for (checkIndex = 0; checkIndex < *(u32 *)(resource + 0x11C); checkIndex++) {
        if (((FldResource *)resource)->entries[checkIndex].type == 0 || ((FldResource *)resource)->entries[checkIndex].type == 2) {
            if ((u32)((FldResource *)resource)->entries[checkIndex].model == 0) {
                kAssertFail((const char *)D_005EFC80, 0x6E4);
            }
            if (mdlPrepareModel((u32)((FldResource *)resource)->entries[checkIndex].model) == 0) {
                return 0;
            }
        } else if (((FldResource *)resource)->entries[checkIndex].type == 1) {
            if (iGpffffb204 == 0 && (u8 *)((FldResource *)resource)->entries[checkIndex].file != NULL && H_Cdvd_IsFileLoaded((s32)(u8 *)((FldResource *)resource)->entries[checkIndex].file) == 0) {
                return 0;
            }
        }
    }
    for (installIndex = 0; installIndex < ((FldResource *)resource)->entryCount; installIndex++) {
        if (((FldResource *)resource)->entries[installIndex].type == 0 || ((FldResource *)resource)->entries[installIndex].type == 2) {
            mdlApplyModelMatrix((void *)((FldResource *)resource)->entries[installIndex].model, func_003e9700((RwFrame *)((FldResource *)resource)->entries[installIndex].frame), 0);
            if (((FldResource *)resource)->entries[installIndex].flags & 1) {
                mdlSetLayerWeight((void *)((FldResource *)resource)->entries[installIndex].model, 0, 0.0f);
            } else {
                mdlDispatchAnimIfPresent((void *)((FldResource *)resource)->entries[installIndex].model, 0, 0, 8, 1);
            }
        } else if (((FldResource *)resource)->entries[installIndex].type == 1) {
            if (iGpffffb204 == 0) {
                if (((FldResource *)resource)->entries[installIndex].filePtr != NULL) {
                    *(s32 *)(resource + installIndex * 0x18 + 0x130) = mdlEffectCreateFromResource((u32)((HCdvdRequest *)(((FldResource *)resource)->entries[installIndex].filePtr))->data);
                    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                    mdlEffectSetChildPositionVec(*(void **)(resource + installIndex * 0x18 + 0x130), (f32 *)((u8 *)func_003e9700((RwFrame *)((FldResource *)resource)->entries[installIndex].frame) + 0x30));
                    H_Cdvd_Destroy(((FldResource *)resource)->entries[installIndex].filePtr);
                    ((FldResource *)resource)->entries[installIndex].filePtr = NULL;
                }
            } else if (((FldResource *)resource)->entries[installIndex].filePtr != NULL) {
                *(s32 *)(resource + installIndex * 0x18 + 0x130) = mdlEffectCreateFromResource((s32)(u8 *)((FldResource *)resource)->entries[installIndex].file);
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                mdlEffectSetChildPositionVec(*(void **)(resource + installIndex * 0x18 + 0x130), (f32 *)((u8 *)func_003e9700((RwFrame *)((FldResource *)resource)->entries[installIndex].frame) + 0x30));
                ((FldResource *)resource)->entries[installIndex].filePtr = NULL;
            }
        }
    }
    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
    if (*(u8 **)(resource + 0xA44) != NULL) {
        if (((FldResource *)resource)->majorId >= 0x28 && ((FldResource *)resource)->majorId < 0x31) {
            if ((u32)((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->textureNames != 0) {
                ((FldResourceWork *)iGpffff9db0)->textureNames = (u32)((FldResourceLoadWork *)((FldResource *)resource)->loadWork)->textureNames;
            }
        } else {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            K_Clump_FreeTextureNameList((u8 *)((FldResourceLoadWork *)*(u8 **)(resource + 0xA44))->textureNames);
        }
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        jtbl_008873EC[0](*(u8 **)(resource + 0xA44));
        ((FldResource *)resource)->loadWork = NULL;
    }
    return 1;
}

/* Destroy the owned worlds or clumps, entry models/effects and resource allocation. */
/* Typed object/entry cursors preserve the pointer and word aliases of the owned allocations. */
// FUN_00151F80
void FldResource_Destroy(u8 *resource)
{
    s32 primaryWorld;
    u32 entryIndex;
    u32 clumpIndex;
    u8 *clumpCursor;
    u8 *entryCursor;

    if (((FldResource *)resource)->flags & 1) {
        primaryWorld = ((FldResource *)resource)->primaryObject;
        if (primaryWorld != 0 && primaryWorld != ((FldResource *)resource)->primaryDrawObject) {
            func_003c9d40((void *)primaryWorld);
        }
        if (((FldResource *)resource)->primaryDrawObject != 0) {
            func_003c9d40((void *)((FldResource *)resource)->primaryDrawObject);
        }
        if (((FldResource *)resource)->alternateObject != 0) {
            func_003c9d40((void *)((FldResource *)resource)->alternateObject);
        }
        if (((FldResource *)resource)->secondaryObject != 0) {
            func_003c9d40((void *)((FldResource *)resource)->secondaryObject);
        }
    } else {
        hMaestroFreeListSet((void *)((FldResource *)resource)->primaryDrawObject);
        if (((FldResource *)resource)->primaryObject != 0) {
            func_003c0700((void *)((FldResource *)resource)->primaryObject);
        }
        if (((FldResource *)resource)->alternateObject != 0) {
            func_003c0700((void *)((FldResource *)resource)->alternateObject);
        }
        if (((FldResource *)resource)->secondaryObject != 0) {
            func_003c0700((void *)((FldResource *)resource)->secondaryObject);
        }
    }
    for (clumpIndex = 0; clumpIndex < ((FldResource *)resource)->clumpCount; clumpIndex++) {
        clumpCursor = resource + clumpIndex * 4;
        hMaestroFreeListSet((void *)((FldResource *)clumpCursor)->drawObjects[0]);
        func_003c0700((void *)((FldResource *)clumpCursor)->clumps[0]);
    }
    for (entryIndex = 0; entryIndex < ((FldResource *)resource)->entryCount; entryIndex++) {
        entryCursor = resource + entryIndex * 0x18;
        if (((FldResource *)entryCursor)->entries[0].type == 0 || ((FldResource *)entryCursor)->entries[0].type == 2) {
            mdlDestroyModelObject(((FldResource *)entryCursor)->entries[0].model);
        } else if (((FldResource *)entryCursor)->entries[0].type == 1) {
            mdlEffectDestroy(((FldResource *)entryCursor)->entries[0].effect);
        }
    }
    if (((FldResource *)resource)->animation != 0) {
        func_003bbb60((void *)((FldResource *)resource)->animation);
    }
    if (((FldResource *)resource)->hbnData != 0) {
        jtbl_008873EC[0]((void *)((FldResource *)resource)->hbnData);
    }
    jtbl_008873EC[0](resource);
}

/* The draw-state table has two address lifetimes: one at the initial call,
 * and one shared by the final render-state sequence. The context is passed
 * in the callback's second argument. Saved Vec4 values are light colors. */
/* Save light colors/transform, move the camera/lights to the selected world and set draw state. */
/* Only measured world-pointer reads remain raw; the saved matrix still copies eight 8-byte scalar pairs. */
// FUN_00152170
void FldResource_BeginDrawState(u8 *command, u8 *resource)
{
    typedef struct { u32 w0; u32 w1; } CopyPair;
    u8 *gs;
    void *raster;
    u8 *cam;
    CopyPair *src;
    CopyPair *dst;
    u32 w0;
    u32 w1;
    s32 n;
    s32 flags;
    s32 light;

    raster = (void *)(u32)kwlnGetCamera();
    gs = (u8 *)D_00887300;
    (*(RwBool (**)(RwRenderState, void *))gs)(0x14, (void *)2);
    func_003e8110((u32)raster);
    cam = (u8 *)(u32)K_Clump_GetLightA();
    ((FldResource *)resource)->savedAmbientColor = ((struct RpLight *)cam)->color;
    cam = (u8 *)(u32)K_Clump_GetLightB();
    ((FldResource *)resource)->savedDirectionalColor = ((struct RpLight *)cam)->color;
    src = (CopyPair *)((u8 *)((struct RpLight *)(u8 *)(u32)K_Clump_GetLightB())->object.parent + 0x10);
    dst = (CopyPair *)(resource + 0xA70);
    n = 8;
    do {
        w0 = src->w0;
        w1 = src->w1;
        src++;
        n--;
        dst->w0 = w0;
        dst->w1 = w1;
        dst++;
    } while (n > 0);
    if (resrcMngGetColorValue() != 0) {
        func_003c38b0((RpLight *)(u32)K_Clump_GetLightA(), (const RwRGBAReal *)resrcMngGetColorValue());
        func_003c38b0((RpLight *)(u32)K_Clump_GetLightB(), (const RwRGBAReal *)resrcMngGetColorTarget());
        func_003e9cb0((RwFrame *)((struct RpLight *)(u8 *)(u32)K_Clump_GetLightB())->object.parent,
                      (const RwMatrix *)resrcMngGetTransform(), rwCOMBINEREPLACE);
    }
    ((struct RpLight *)(u8 *)(u32)K_Clump_GetLightB())->object.flags = 3;
    K_Clump_GetLightB();
    if ((s32)((FldResource *)resource)->flags & 1) {
        func_003cbc60(K_Clump_GetWorld(), (u8 *)raster);
        flags = (s32)((FldResource *)resource)->flags;
        if (flags & 0x80000000) {
            func_003cbc10((RpWorld *)((FldResource *)resource)->primaryDrawObject, (RwCamera *)raster);
        } else if (flags & 0x40000000) {
            light = ((FldResource *)resource)->alternateObject;
            if (light != 0) {
                func_003cbc10((RpWorld *)(u32)light, (RwCamera *)raster);
            }
        } else if (flags & 0x20000000) {
            light = ((FldResource *)resource)->secondaryObject;
            if (light != 0) {
                func_003cbc10((RpWorld *)(u32)light, (RwCamera *)raster);
            }
        } else {
            func_003cbc10((RpWorld *)((FldResource *)resource)->primaryObject, (RwCamera *)raster);
        }
        func_003cbf30((RpWorld *)(u32)K_Clump_GetWorld(), (RpLight *)(u32)K_Clump_GetLightA());
        func_003cbf30((RpWorld *)(u32)K_Clump_GetWorld(), (RpLight *)(u32)K_Clump_GetLightB());
        flags = (s32)((FldResource *)resource)->flags;
        if (flags & 0x80000000) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003cbe80(*(RpWorld **)(resource + 0xC), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbe80((RpWorld *)((FldResource *)resource)->primaryDrawObject, (RpLight *)(u32)K_Clump_GetLightB());
        } else if (flags & 0x40000000) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003cbe80(*(RpWorld **)(resource + 0x10), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbe80((RpWorld *)((FldResource *)resource)->alternateObject, (RpLight *)(u32)K_Clump_GetLightB());
        } else if ((flags & 0x20000000) && (((FldResource *)resource)->secondaryObject != 0)) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003cbe80(*(RpWorld **)(resource + 0x14), (RpLight *)(u32)K_Clump_GetLightA());
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003cbe80(*(RpWorld **)(resource + 0x14), (RpLight *)(u32)K_Clump_GetLightB());
        } else {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003cbe80(*(RpWorld **)(resource + 8), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbe80((RpWorld *)((FldResource *)resource)->primaryObject, (RpLight *)(u32)K_Clump_GetLightB());
        }
    } else {
        func_003cbf30((RpWorld *)(u32)K_Clump_GetWorld(), (RpLight *)(u32)K_Clump_GetLightC());
    }
    func_003e8120((u32)raster);
    gs = (u8 *)D_00887300;
    (*(RwBool (**)(RwRenderState, void *))gs)(6, (void *)1);
    (*(RwBool (**)(RwRenderState, void *))gs)(8, (void *)1);
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    (*(RwBool (**)(RwRenderState, void *))gs)(0x14, (void *)2);
    if (iGpffffba48 == 1) {
        (*(RwBool (**)(RwRenderState, void *))gs)(0xE, (void *)1);
        (*(RwBool (**)(RwRenderState, void *))gs)(0xF,
            (void *)(iGpffffba54 | (((u32)iGpffffba50 << 8) | (((u32)iGpffffba58 << 0x18) | ((u32)iGpffffba4c << 0x10)))));
        (*(RwBool (**)(RwRenderState, void *))gs)(0x10, (void *)1);
    }
}

/* Restore the global world camera/lights and the light state saved by BeginDrawState. */
/* Earlier whole-layout probe: 784/768 bytes. Only the marked secondary-world read remains raw. */
// FUN_00152630
void FldResource_EndDrawState(u8 *command, u8 *resource)
{
    u8 *camera;
    u8 *ambientWorld;
    u8 *directionalWorld;
    u8 *thirdLightWorld;

    camera = (void *)(u32)kwlnGetCamera();
    func_003e8110((u32)camera);
    if (((FldResource *)resource)->flags & 1) {
        if (((FldResource *)resource)->flags & 0x80000000) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003cbf30((RpWorld *)(u32)*(s32 *)(resource + 0xC), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbf30((RpWorld *)(u32)((FldResource *)resource)->primaryDrawObject, (RpLight *)(u32)K_Clump_GetLightB());
        } else if (((FldResource *)resource)->flags & 0x40000000) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003cbf30((RpWorld *)(u32)*(s32 *)(resource + 0x10), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbf30((RpWorld *)(u32)((FldResource *)resource)->alternateObject, (RpLight *)(u32)K_Clump_GetLightB());
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        } else if ((((FldResource *)resource)->flags & 0x20000000) && *(s32 *)(resource + 0x14) != 0) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003cbf30((RpWorld *)(u32)*(s32 *)(resource + 0x14), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbf30((RpWorld *)(u32)((FldResource *)resource)->secondaryObject, (RpLight *)(u32)K_Clump_GetLightB());
        } else {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            func_003cbf30((RpWorld *)(u32)*(s32 *)(resource + 8), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbf30((RpWorld *)(u32)((FldResource *)resource)->primaryObject, (RpLight *)(u32)K_Clump_GetLightB());
        }
        ambientWorld = (void *)(u32)K_Clump_GetWorld();
        func_003cbe80((RpWorld *)ambientWorld, (RpLight *)(u32)K_Clump_GetLightA());
        directionalWorld = (void *)(u32)K_Clump_GetWorld();
        func_003cbe80((RpWorld *)directionalWorld, (RpLight *)(u32)K_Clump_GetLightB());
        if (((FldResource *)resource)->flags & 0x80000000) {
            func_003cbc60(((FldResource *)resource)->primaryDrawObject, (u8 *)camera);
        } else if (((FldResource *)resource)->flags & 0x40000000) {
            func_003cbc60(((FldResource *)resource)->alternateObject, (u8 *)camera);
        } else if ((((FldResource *)resource)->flags & 0x20000000) && ((FldResource *)resource)->secondaryObject != 0) {
            func_003cbc60(((FldResource *)resource)->secondaryObject, (u8 *)camera);
        } else {
            func_003cbc60(((FldResource *)resource)->primaryObject, (u8 *)camera);
        }
        func_003cbc10((RpWorld *)(u32)K_Clump_GetWorld(), (RwCamera *)camera);
    } else {
        thirdLightWorld = (void *)(u32)K_Clump_GetWorld();
        func_003cbe80((RpWorld *)thirdLightWorld, (RpLight *)(u32)K_Clump_GetLightC());
    }
    func_003c38b0((RpLight *)(u32)K_Clump_GetLightA(), (const RwRGBAReal *)(resource + 0xA50));
    func_003c38b0((RpLight *)(u32)K_Clump_GetLightB(), (const RwRGBAReal *)(resource + 0xA60));
    /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
    func_003e9cb0((RwFrame *)(u32)*(s32 *)((u8 *)(u32)K_Clump_GetLightB() + 4),
                  (const RwMatrix *)(resource + 0xA70), rwCOMBINEREPLACE);
    ((struct RpLight *)(u8 *)(u32)K_Clump_GetLightB())->object.flags = 3;
    K_Clump_GetLightB();
    func_003e8120((u32)camera);
}

/* Queue selected world/clumps and bracket their drawing with light-state callbacks. */
/* Earlier whole-layout probe: 644/640 bytes. Commands are typed; only the marked clump-count read remains raw. */
// FUN_00152930
void FldResource_QueueDrawCallbacks(u8 *list, u8 *resource)
{
    u8 *worldCommand;
    u8 *primaryCommand;
    u8 *clumpCommand;
    s32 primaryObject;
    u32 flags;
    u32 i;

    primaryCommand = NULL;
    flags = ((FldResource *)resource)->flags;
    if (flags & 1) {
        primaryObject = ((FldResource *)resource)->primaryObject;
        if (primaryObject != 0) {
            if (flags & 0x80000000) {
                worldCommand = sdkOtQueueWorld(list, ((FldResource *)resource)->primaryDrawObject);
            } else if (flags & 0x40000000) {
                worldCommand = sdkOtQueueWorld(list, ((FldResource *)resource)->alternateObject);
            } else if ((flags & 0x20000000) && ((FldResource *)resource)->secondaryObject != 0) {
                worldCommand = sdkOtQueueWorld(list, ((FldResource *)resource)->secondaryObject);
            } else {
                worldCommand = sdkOtQueueWorld(list, primaryObject);
            }
            ((PrimQueueDrawNode *)worldCommand)->begin.callback = (void (*)(void))FldResource_BeginDrawState;
            ((PrimQueueDrawNode *)worldCommand)->begin.argument.data = resource;
            ((PrimQueueDrawNode *)worldCommand)->begin.endCallback = (void (*)(void))FldResource_EndDrawState;
            ((PrimQueueDrawNode *)worldCommand)->endArgument.data = resource;
        }
    } else {
        if (flags & 0x80000000) {
            if (((FldResource *)resource)->primaryDrawObject != 0) {
                primaryCommand = sdkOtQueueClump(list, ((FldResource *)resource)->primaryDrawObject);
            } else {
                primaryCommand = PrimQueueSkyStateEnter(list, ((FldResource *)resource)->primaryObject);
            }
        } else if (flags & 0x40000000) {
            primaryCommand = PrimQueueSkyStateEnter(list, ((FldResource *)resource)->alternateObject);
        } else if (flags & 0x20000000) {
            if (((FldResource *)resource)->secondaryObject != 0) {
                primaryCommand = PrimQueueSkyStateEnter(list, ((FldResource *)resource)->secondaryObject);
            }
        }
        if (primaryCommand != NULL) {
            ((PrimQueueDrawNode *)primaryCommand)->begin.callback = (void (*)(void))FldResource_BeginDrawState;
            ((PrimQueueDrawNode *)primaryCommand)->begin.argument.data = resource;
            ((PrimQueueDrawNode *)primaryCommand)->begin.endCallback = (void (*)(void))FldResource_EndDrawState;
            ((PrimQueueDrawNode *)primaryCommand)->endArgument.data = resource;
        }
    }
    if (!(((FldResource *)resource)->flags & 0xC0000000)) {
        /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
        for (i = 0; i < *(u32 *)(resource + 0x18); i++) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            if (*(s32 *)(resource + 0x9C + i * 4) != 0) {
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                clumpCommand = sdkOtQueueClump(list, *(s32 *)(resource + 0x9C + i * 4));
            } else {
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                clumpCommand = PrimQueueSkyStateEnter(list, *(s32 *)(resource + 0x1C + i * 4));
            }
            if (clumpCommand != NULL && i == 0) {
                ((PrimQueueDrawNode *)clumpCommand)->begin.callback = (void (*)(void))FldResource_BeginDrawState;
                ((PrimQueueDrawNode *)clumpCommand)->begin.argument.data = resource;
            }
            if (clumpCommand != NULL && i == ((FldResource *)resource)->clumpCount - 1) {
                ((PrimQueueDrawNode *)clumpCommand)->begin.endCallback = (void (*)(void))FldResource_EndDrawState;
                ((PrimQueueDrawNode *)clumpCommand)->endArgument.data = resource;
            }
        }
    }
}

/* Queue the primary clump pass and attach draw-state callbacks to its first command. */
/* PrimQueueDrawNode names both callback ABI slots and their contexts. */
// FUN_00152BB0
void FldResource_QueueDrawCallbacksPrimary(u8 *list, u8 *resource)
{
    u8 *primaryCommand;
    u8 *clumpCommand;
    u32 i;

    primaryCommand = NULL;
    if (!(((FldResource *)resource)->flags & 1)) {
        if ((((FldResource *)resource)->flags & 0x80000000) && (u8 *)((FldResource *)resource)->primaryDrawObject != NULL) {
            primaryCommand = sdkOtQueueClumpPrimaryPass(list, ((FldResource *)resource)->primaryDrawObject);
        }
        if (primaryCommand != NULL) {
            ((PrimQueueDrawNode *)primaryCommand)->begin.callback = (void (*)(void))FldResource_BeginDrawState;
            ((PrimQueueDrawNode *)primaryCommand)->begin.argument.data = resource;
            ((PrimQueueDrawNode *)primaryCommand)->begin.endCallback = (void (*)(void))FldResource_EndDrawState;
            ((PrimQueueDrawNode *)primaryCommand)->endArgument.data = resource;
        }
    }
    if (!(((FldResource *)resource)->flags & 0xC0000000)) {
        for (i = 0; i < ((FldResource *)resource)->clumpCount; i++) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            if (*(u8 **)(resource + 0x9C + i * 4) != NULL) {
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                clumpCommand = sdkOtQueueClumpPrimaryPass(list, *(s32 *)(resource + 0x9C + i * 4));
                if (clumpCommand != NULL && i == 0) {
                    ((PrimQueueDrawNode *)clumpCommand)->begin.callback = (void (*)(void))FldResource_BeginDrawState;
                    ((PrimQueueDrawNode *)clumpCommand)->begin.argument.data = resource;
                    ((PrimQueueDrawNode *)clumpCommand)->begin.endCallback = (void (*)(void))FldResource_EndDrawState;
                    ((PrimQueueDrawNode *)clumpCommand)->endArgument.data = resource;
                }
            }
        }
    }
}

/* Queue the secondary clump pass with the selected alternate objects and callbacks. */
/* PrimQueueDrawNode names both callback ABI slots and their contexts. */
// FUN_00152CD0
void FldResource_QueueDrawCallbacksSecondary(u8 *list, u8 *resource)
{
    u8 *primaryCommand;
    u8 *clumpCommand;
    u32 i;

    primaryCommand = NULL;
    if (!(((FldResource *)resource)->flags & 1)) {
        if ((((FldResource *)resource)->flags & 0x80000000)) {
            if (((FldResource *)resource)->primaryDrawObject != 0) {
                primaryCommand = sdkOtQueueClumpSecondaryPass(list, ((FldResource *)resource)->primaryDrawObject);
            }
        } else if ((((FldResource *)resource)->flags & 0x40000000)) {
            if (((FldResource *)resource)->alternateObject != 0) {
                primaryCommand = PrimQueueSkyStateEnter(list, ((FldResource *)resource)->alternateObject);
            }
        } else if ((((FldResource *)resource)->flags & 0x20000000)) {
            if (((FldResource *)resource)->secondaryObject != 0) {
                primaryCommand = PrimQueueSkyStateEnter(list, ((FldResource *)resource)->secondaryObject);
            }
        }
        if (primaryCommand != NULL) {
            ((PrimQueueDrawNode *)primaryCommand)->begin.callback = (void (*)(void))FldResource_BeginDrawState;
            ((PrimQueueDrawNode *)primaryCommand)->begin.argument.data = resource;
            ((PrimQueueDrawNode *)primaryCommand)->begin.endCallback = (void (*)(void))FldResource_EndDrawState;
            ((PrimQueueDrawNode *)primaryCommand)->endArgument.data = resource;
        }
    }
    if (!(((FldResource *)resource)->flags & 0xC0000000)) {
        for (i = 0; i < ((FldResource *)resource)->clumpCount; i++) {
            /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
            if (*(u8 **)(resource + 0x9C + i * 4) != NULL) {
                /* measured: typing this remaining site changes b210 instruction bytes (owner loses MATCH). */
                clumpCommand = sdkOtQueueClumpSecondaryPass(list, *(s32 *)(resource + 0x9C + i * 4));
                if (clumpCommand != NULL && i == 0) {
                    ((PrimQueueDrawNode *)clumpCommand)->begin.callback = (void (*)(void))FldResource_BeginDrawState;
                    ((PrimQueueDrawNode *)clumpCommand)->begin.argument.data = resource;
                    ((PrimQueueDrawNode *)clumpCommand)->begin.endCallback = (void (*)(void))FldResource_EndDrawState;
                    ((PrimQueueDrawNode *)clumpCommand)->endArgument.data = resource;
                }
            }
        }
    }
}

/* Measured: 1188 bytes and 27 resolved relocations; twelve zero tail bytes.
 * Real twelve-byte vectors/tolerances occupy quadword-aligned stack slots.
 * The packed axis view preserves the independent eight- and four-byte loads;
 * resource pointers, loop bounds and the post-rotate frame remain reloads. */
#pragma push
#pragma opt_propagation off
/* Translate clump frames and models; rotate effect positions about the supplied angle first. */
/* Typed matrix bit members preserve integer initialization in the measured scalar-copy body. */
// FUN_00152E50
void FldResource_TransformFrames(u8 *resource, u8 *translation, f32 angle)
{
    struct {
        Vec3 RWALIGN(trans, 16);
        union {
            Vec3 vector;
            struct { s64 xy; f32 z; } bits;
        } RWALIGN(axis, 16);
        RwMatrixTolerance RWALIGN(t3, 16);
        Vec3 RWALIGN(v3, 16);
        RwMatrixTolerance RWALIGN(t2, 16);
        Vec3 RWALIGN(v2, 16);
        RwMatrixTolerance RWALIGN(t1, 16);
        Vec3 RWALIGN(v1, 16);
        RwMatrixTolerance RWALIGN(t0, 16);
        Vec3 RWALIGN(v0, 16);
    } stk;
    u16 kind;
    u32 i;
    u8 *mtx2;
    u32 j;
    u8 *frame;
    u8 *frame2;
    u8 *frame3;
    u8 *frame4;
    u8 *mtx;
    u8 *res;
    u8 *res2;
    u8 *res3;
    u8 *res4;

    if (!((s32)((FldResource *)resource)->flags & 1)) {
        res = (u8 *)((FldResource *)resource)->primaryObject;
        if (res != NULL) {
            frame = (u8 *)((RwObject *)res)->parent;
            mtx = (u8 *)func_003e9700((RwFrame *)frame);
            stk.v0 = ((RwMatrix *)mtx)->pos;
            stk.v0.x += ((Vec3 *)translation)->x;
            stk.v0.y += ((Vec3 *)translation)->y;
            stk.v0.z += ((Vec3 *)translation)->z;
            ((RwFrame *)frame)->modelling.pos = stk.v0;
            RwEngineGetMatrixTolerances(&stk.t0);
            RwMatrixOptimize((RwMatrix *)&((RwFrame *)frame)->modelling, &stk.t0);
            func_003e9680((RwFrame *)frame);
        }
        res2 = (u8 *)((FldResource *)resource)->alternateObject;
        if (res2 != NULL) {
            frame2 = (u8 *)((RwObject *)res2)->parent;
            mtx = (u8 *)func_003e9700((RwFrame *)frame2);
            stk.v1 = ((RwMatrix *)mtx)->pos;
            stk.v1.x += ((Vec3 *)translation)->x;
            stk.v1.y += ((Vec3 *)translation)->y;
            stk.v1.z += ((Vec3 *)translation)->z;
            ((RwFrame *)frame2)->modelling.pos = stk.v1;
            RwEngineGetMatrixTolerances(&stk.t1);
            RwMatrixOptimize((RwMatrix *)&((RwFrame *)frame2)->modelling, &stk.t1);
            func_003e9680((RwFrame *)frame2);
        }
        res3 = (u8 *)((FldResource *)resource)->secondaryObject;
        if (res3 != NULL) {
            frame3 = (u8 *)((RwObject *)res3)->parent;
            mtx = (u8 *)func_003e9700((RwFrame *)frame3);
            stk.v2 = ((RwMatrix *)mtx)->pos;
            stk.v2.x += ((Vec3 *)translation)->x;
            stk.v2.y += ((Vec3 *)translation)->y;
            stk.v2.z += ((Vec3 *)translation)->z;
            ((RwFrame *)frame3)->modelling.pos = stk.v2;
            RwEngineGetMatrixTolerances(&stk.t2);
            RwMatrixOptimize((RwMatrix *)&((RwFrame *)frame3)->modelling, &stk.t2);
            func_003e9680((RwFrame *)frame3);
        }
    }
    i = 0;
    while (i < ((FldResource *)resource)->clumpCount) {
        res4 = (u8 *)((FldResource *)resource)->clumps[i];
        if (res4 != NULL) {
            frame4 = (u8 *)((RwObject *)res4)->parent;
            mtx = (u8 *)func_003e9700((RwFrame *)frame4);
            stk.v3 = ((RwMatrix *)mtx)->pos;
            stk.v3.x += ((Vec3 *)translation)->x;
            stk.v3.y += ((Vec3 *)translation)->y;
            stk.v3.z += ((Vec3 *)translation)->z;
            ((RwFrame *)frame4)->modelling.pos = stk.v3;
            RwEngineGetMatrixTolerances(&stk.t3);
            RwMatrixOptimize((RwMatrix *)&((RwFrame *)frame4)->modelling, &stk.t3);
            func_003e9680((RwFrame *)frame4);
        }
        i += 1;
    }
    j = 0;
    while (j < ((FldResource *)resource)->entryCount) {
        kind = ((FldResource *)resource)->entries[j].type;
        if (kind == 0 || kind == 2) {
            mdlTranslateMatrix((RwMatrix *)((FldResource *)resource)->entries[j].model, (const Vec3 *)translation, 2);
        } else if (kind == 1) {
            {
                s64 axisXY = D_005EFE28[0];
                f32 axisZ = D_005EFE30[0];
                stk.axis.bits.xy = axisXY;
                stk.axis.bits.z = axisZ;
            }
            mtx2 = (u8 *)func_003e0f80();
            ((RwMatrix *)mtx2)->atZBits = 0x3F800000;
            ((RwMatrix *)mtx2)->upYBits = 0x3F800000;
            ((RwMatrix *)mtx2)->rightXBits = 0x3F800000;
            ((RwMatrix *)mtx2)->upXBits = 0;
            ((RwMatrix *)mtx2)->rightZBits = 0;
            ((RwMatrix *)mtx2)->rightYBits = 0;
            ((RwMatrix *)mtx2)->atYBits = 0;
            ((RwMatrix *)mtx2)->atXBits = 0;
            ((RwMatrix *)mtx2)->upZBits = 0;
            ((RwMatrix *)mtx2)->posZBits = 0;
            ((RwMatrix *)mtx2)->posYBits = 0;
            ((RwMatrix *)mtx2)->posXBits = 0;
            ((RwMatrix *)mtx2)->flags |= 0x20003;
            RwMatrixRotate((RwMatrix *)mtx2, &stk.axis.vector, angle, rwCOMBINEPOSTCONCAT);
            {
                u32 k = j;
                u8 *base = resource + k * 0x18;
                mtx = (u8 *)func_003e9700((RwFrame *)((FldResource *)base)->entries[0].frame);
                stk.trans = ((RwMatrix *)mtx)->pos;
                func_003e42a0(&stk.trans, &stk.trans, (const RwMatrix *)mtx2);
                stk.trans.x += ((Vec3 *)translation)->x;
                stk.trans.y += ((Vec3 *)translation)->y;
                stk.trans.z += ((Vec3 *)translation)->z;
                mdlEffectSetChildPositionVec((void *)((FldResource *)base)->entries[0].effect, (f32 *)&stk.trans);
            }
            func_003e0f40((RwMatrix *)mtx2);
        }
        j += 1;
    }
}
#pragma pop

/* measured: opt_propagation off preserves the named scalar global loads; this scalar pair copy suppresses aggregate ld/sd traffic. */
#pragma push
#pragma opt_propagation off
#define COPY_SCALAR_PAIR(dst, src) \
do { \
    s64 copy_s64; \
    f32 copy_f32; \
    copy_s64 = (src).xy; \
    copy_f32 = (src).z; \
    (dst).xy = copy_s64; \
    (dst).z = copy_f32; \
} while (0)
/* Rotate clump frames, entry models and effect Euler angles about the stored axis. */
/* Typed frame/entry fields preserve the packed-axis scalar loads and pointer/handle aliases. */
// FUN_00153300
void FldResource_AdvanceAnimations(s8 *resource, f32 angle)
{
    extern void func_003e9d50(s32 a0, void *a1, f32 f12, s32 a3);
    void *ptr;
    struct {
        s64 xy;
        f32 z;
    } axis;
    u16 kind;
    u32 clumpIndex;
    u32 entryIndex;
    u8 *primaryClump;
    u8 *firstAlternateClump;
    u8 *secondAlternateClump;
    u8 *clump;
    u8 *entryCursor;

    ptr = &axis.xy;
    COPY_SCALAR_PAIR(axis, *(typeof(axis) *)D_005EFE38);
    if (!(((FldResource *)resource)->flags & 1)) {
        primaryClump = (u8 *)((FldResource *)resource)->primaryObject;
        if (primaryClump != NULL) {
            func_003e9d50((s32)((RwObject *)primaryClump)->parent, ptr, angle, 2);
        }
        firstAlternateClump = (u8 *)((FldResource *)resource)->alternateObject;
        if (firstAlternateClump != NULL) {
            func_003e9d50((s32)((RwObject *)firstAlternateClump)->parent, &axis.xy, angle, 2);
        }
        secondAlternateClump = (u8 *)((FldResource *)resource)->secondaryObject;
        if (secondAlternateClump != NULL) {
            func_003e9d50((s32)((RwObject *)secondAlternateClump)->parent, &axis.xy, angle, 2);
        }
    }
    clumpIndex = 0;
    goto testClump;
rotateClump:
    clump = (u8 *)((FldResource *)resource)->clumps[clumpIndex];
    if (clump != NULL) {
        func_003e9d50((s32)((RwObject *)clump)->parent, &axis.xy, angle, 2);
    }
    clumpIndex += 1;
testClump:
    if (clumpIndex < ((FldResource *)resource)->clumpCount) {
        goto rotateClump;
    }
    entryIndex = 0;
    goto testEntry;
rotateEntry:
    entryCursor = (u8 *)resource + entryIndex * 0x18;
    kind = ((FldResource *)entryCursor)->entries[0].type;
    if (kind == 0) {
        goto rotateModel;
    }
    if (kind != 2) {
        goto testEffect;
    }
rotateModel:
    mdlRotateMatrix((void *)(((FldResource *)entryCursor)->entries[0].model), &axis.xy, angle, 2);
    goto nextEntry;
testEffect:
    if (kind != 1) {
        goto nextEntry;
    }
    mdlEffectSetEulerRotation(((FldResource *)entryCursor)->entries[0].effect, 0.0f, angle, 0.0f);
nextEntry:
    ;
    entryIndex += 1;
testEntry:
    if (entryIndex < ((FldResource *)resource)->entryCount) {
        goto rotateEntry;
    }
}
/* measured: restore propagation after FldResource_AdvanceAnimations. */
#pragma pop

extern void FldResource_TransformFrames(u8 *resource, u8 *translation, f32 angle);

/* measured: MWCCPS2 b210 -O2, 792B/window 800B, 17 relocations,
 * eight zero alignment bytes. Ghidra identifies the unsigned angle
 * conversion; IDA identifies the three-pair copy of each 24-byte entry.
 * The arrays end at the measured count/scale fields, not at the allocation
 * boundary: the original allocation remains 0xAB0 bytes. */
/* Clone non-world resources and apply an unsigned number of quarter turns plus translation. */
/* Typed clone cursors preserve the measured three-pair 24-byte entry copies and word-backed pointer aliases. */
// FUN_001534A0
FldResource *FldResource_CloneRotated(FldResource *src, void *translation, u32 quarterTurns)
{
    FldResource *dst;
    f32 angle;
    u32 i;
    u32 j;
    u8 *destinationCursor;

    angle = 90.0f * (f32)quarterTurns;
    if (src->flags & 1) {
        return NULL;
    }
    chkmemAllocSiteTag(D_005EFC80, 0xA2A);
    dst = (FldResource *)D_008873F4[0](1, 0xAB0, 0x40000);
    dst->flags = src->flags | 2;
    dst->majorId = src->majorId;
    dst->minorId = src->minorId;
    if (src->primaryObject != 0) {
        dst->primaryObject = func_003c0520(src->primaryObject);
        dst->primaryDrawObject = (s32)sdkClumpCreateBuckets((void *)dst->primaryObject);
    }
    if (src->alternateObject != 0) {
        dst->alternateObject = func_003c0520(src->alternateObject);
    }
    if (src->secondaryObject != 0) {
        dst->secondaryObject = func_003c0520(src->secondaryObject);
    }
    dst->clumpCount = src->clumpCount;
    for (i = 0; i < src->clumpCount; i++) {
        s32 clump = ((FldResource *)((u8 *)src + i * 4))->clumps[0];
        if (clump != 0) {
            s32 *clumpSlot;
            destinationCursor = (u8 *)dst + i * 4;
            clumpSlot = (s32 *)&((FldResource *)destinationCursor)->clumps[0];
            *clumpSlot = func_003c0520(clump);
            ((FldResource *)destinationCursor)->drawObjects[0] = (s32)sdkClumpCreateBuckets((void *)*clumpSlot);
        }
    }
    dst->entryCount = src->entryCount;
    for (j = 0; j < src->entryCount; j++) {
        u8 *sourceCursor = (u8 *)src + (s32)j * 24;
        FldResourceEntry *entry = (FldResourceEntry *)&((FldResource *)sourceCursor)->entries[0].type;
        destinationCursor = (u8 *)dst + (s32)j * 24;
        dst->entries[j] = *entry;

        if (entry->type == 0 || entry->type == 2) {
            u8 *sourceCursor = (u8 *)src + j * 24;
            s32 *modelSlot = &dst->entries[j].model;
            *modelSlot = mdlCloneModelObject(((FldResource *)sourceCursor)->entries[0].model);
            mdlApplyModelMatrix((void *)*modelSlot, func_003e9700((void *)((FldResource *)sourceCursor)->entries[0].frame), 0);
            if (((FldResource *)sourceCursor)->entries[0].flags & 2) {
                ((FldResource *)destinationCursor)->entries[0].flags |= 2;
            }
        } else if (entry->type == 1) {
            ((FldResource *)destinationCursor)->entries[0].effect = mdlEffectClone(((FldResource *)sourceCursor)->entries[0].effect);
        }
    }
    dst->scale = src->scale;
    FldResource_AdvanceAnimations((s8 *)dst, angle);
    FldResource_TransformFrames((u8 *)dst, translation, angle);
    return dst;
}
