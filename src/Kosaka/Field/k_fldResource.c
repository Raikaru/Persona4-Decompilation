#include "model_motion_internal.h"
#include "texture_callback_internal.h"
#include "include_asm.h"
#include "Kosaka/k_clump_property_internal.h"
/* Original translation unit k_fldResource.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "rw/ps2/ostypes.h"
#include "rw/plcore/barenderstate.h"

typedef struct RwMatrixTolerance {
    f32 Normal;
    f32 Orthogonal;
    f32 Identity;
} RwMatrixTolerance;

typedef struct RwV3d { f32 x; f32 y; f32 z; } Vec3;
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
typedef struct { f32 x; f32 y; f32 z; f32 w; } Vec4;

extern s32 sprintf(char *dst, const char *format, ...);
extern s32 func_00440b68(const char *format, ...);
extern s32 func_00454a60(char *path, s32 mode);
extern s32 H_Cdvd_IsFileLoaded(s32 handle);
extern u8 *func_00460f80(u8 *list, s32 arg1);
extern u8 *func_00461080(u8 *list, s32 arg1);
extern u8 *func_00461180(u8 *list, s32 arg1);
extern u8 *func_003e9d50(u8 *arg0);
extern void FldResource_BeginDrawState(u8 *arg0, u8 *arg1);
extern s32 K_Clump_CountIntUsrData(void *object, const char *name);
extern void kAssertFail(const char *file, s32 line);
extern void func_004b1290(s32 a0, f32 f12, f32 f13, f32 f14);
extern void func_003c9d40(void *arg0);
extern void func_003c0700(void *arg0);
extern void func_00462bf0(void *arg0);
extern void mdlDestroyModelObject(s32 arg0);
extern void func_004b1150(s32 arg0);
extern void func_003bbb60(void *arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *func_00460e80(u8 *list, s32 arg1);
extern u8 *func_00461290(u8 *list, s32 arg1);
extern s32 func_00457120(void);
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
extern s32 mdlPrepareModel(u32 arg0);
extern void mdlApplyModelMatrix(void *arg0, void *arg1, s32 arg2);
extern void mdlSetLayerWeight(void *arg0, s32 arg1, f32 arg2);
extern RwMatrix *func_003e9700(RwFrame *frame);
extern void K_Clump_FreeTextureNameList(void *arg0);
extern s32 func_004b1130(s32 a0);
extern void *memset(void *dst, s32 value, u32 size);
extern s32 func_00455f70(void *arg0, s32 *arg1);
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_003df3c0(s32 arg0, s32 *arg1);
extern void func_003e2ce0(s32 arg0, u32 arg1);
extern void func_003e2e40(s32 arg0, s32 arg1);
extern s32 func_004667d0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003dc370(void *arg0);
extern void func_003ef1b0(s32 arg0);
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
extern u8 *func_004669d0(s32 arg0, s32 *arg1, s32 *arg2);
extern s32 K_Clump_GeometryHasMatUsrData(u8 *arg0, char *arg1);
extern s32 K_Clump_ClumpHasMatUsrData(u8 *arg0, char *arg1);
extern void *func_00462ae0(void *arg0);
extern void func_003db550(u8 *arg0, u8 *arg1);
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
extern void *mdlCreateModelObjectFromData(u32 arg0, u16 arg1, void *arg2, u32 arg3);
extern void *mdlCreateModelObjectFromMemory(u32 arg0, u16 arg1, void *arg2, u32 arg3, u32 arg4);
extern s32 FldMap_IsInBandA(s32 a0, s32 a1);
extern s32 FldMap_IsInBandB(s32 a0, s32 a1);
extern u8 *FldStepLoadFilePair(s32 a0, s32 a1);
extern s32 *MT_Scene_GetFrameState(void);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern s32 atoi(const char *arg0);
extern void strcpy(char *dst, char *src);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 D_00754D88[];
extern s32 chkmemGetBytes(void);
extern s32 func_003c0520(s32 arg0);
extern s32 mdlCloneModelObject(s32 arg0);
extern s32 func_004b11b0(s32 arg0);
extern void func_004b1250(void *effect, f32 *position);
extern RwBool RwEngineGetMatrixTolerances(RwMatrixTolerance *tolerance);
extern RwMatrix *RwMatrixOptimize(RwMatrix *matrix, const RwMatrixTolerance *tolerance);
extern RwFrame *func_003e9680(RwFrame *frame);
extern RwMatrix *func_003e0f80(void);
extern RwBool func_003e0f40(RwMatrix *matrix);
extern RwMatrix *RwMatrixRotate(RwMatrix *matrix, const Vec3 *axis, f32 angle, RwOpCombineType combine);
extern Vec3 *func_003e42a0(Vec3 *pointOut, const Vec3 *pointIn, const RwMatrix *matrix);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const Vec3 *translation, s32 combine);
extern s64 D_005EFE28[];
extern f32 D_005EFE30[];
extern u8 *iGpffff9db0;
extern void H_Cdvd_Destroy(void *ptr);
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


// FUN_0014EED0
void FldResource_OpenPrimaryFile(s32 arg0, s32 arg1)
{
    char path[0x40];

    if (iGpffffb200 == 0) {
        sprintf(path, D_005EFC60, (u16)arg0, (u16)arg1);
        func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0x9E);
        iGpffffb200 = func_00454a60(path, 1);
    }
}

// FUN_0014EF40
s32 FldResource_IsPrimaryFileLoaded(void)
{
    if (iGpffffb200 == 0) {
        return 1;
    }
    return H_Cdvd_IsFileLoaded(iGpffffb200) != 0;
}

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
// FUN_0014EFC0
void FldResource_QueueFieldResources(s32 arg0, s32 arg1)
{
    char sp90[0x40];
    char sp50[0x40];
    s32 var17;
    s32 var16;
    u8 *work;
    *(s32 *)(iGpffff9db0 + 0x24) = 0;
    *(s32 *)(iGpffff9db0 + 0x94) = 0;
    memset(iGpffff9db0 + 0x9C, 0, 0x40);
    if (FldMap_IsInBandA(arg0, arg1) || FldMap_IsInBandB(arg0, arg1)) {
        if (FldMap_IsInBandB(arg0, arg1)) {
            var17 = (u16)((u16)arg0 - 0x14);
            *(s32 *)(iGpffff9db0 + 0x88) |= 0x80000000;
            var16 = (s32)FldStepLoadFilePair(arg0, arg1);
            *(s32 *)(((u8 *)MT_Scene_GetFrameState()) + 0x1864) = var16;
            var16 = D_005F0591[D_005F0590[(u16)var17] * 12];
        } else {
            var17 = (u16)arg0;
            var16 = fldResourcePresets[D_005F0590[var17]].ordinaryCount;
        }
        work = iGpffff9db0;
        if (*(s32 *)(work + 0x88) & 0x80000000) {
            if (iGpffffb204 == 0) {
                sprintf(sp90, D_005EFC90, (s16)arg0, (s16)arg1);
                func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0xC9);
                iGpffffb204 = func_00454a60(sp90, 1);
            }
            {
                s32 i;
                i = var16 - 1;
                for (; i >= 0; i--) {
                    work = iGpffff9db0;
                    *(s16 *)(work + *(s32 *)(work + 0x98) * 4 + 0x9C) = (s16)var17;
                    work = iGpffff9db0;
                    /* Both predicates normalize the major ID to40..59. */
                    *(s16 *)(work + *(s32 *)(work + 0x98) * 4 + 0x9E) =
                        *(const s8 *)(((const s8 *)D_005F0590 +
                                      D_005F05B8[(u16)var17 - 0x28] * 12) + i + 2);
                    *(s32 *)(iGpffff9db0 + 0x98) += 1;
                }
            }
        } else {
            *(s32 *)(work + 0x24) = var16;
            {
                s32 i;
                u32 offset;
                i = 0;
                for (; work = iGpffff9db0, i < *(s32 *)(work + 0x24); i++) {
                    offset = i * sizeof(s32);
                    *(s32 *)(work + offset + 0x28) = *(const s32 *)((const u8 *)D_007E8060 + offset);
                }
            }
            *(s32 *)(work + 0x94) = 4;
        }
    } else {
        if (iGpffffb204 == 0) {
            sprintf(sp50, D_005EFC90, (s16)arg0, (s16)arg1);
            func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0xC9);
            iGpffffb204 = func_00454a60(sp50, 1);
        }
        work = iGpffff9db0;
        *(s16 *)(fldResourceWorkOffset(*(s32 *)(work + 0x98) * 4, work) + 0x9C) = (s16)arg0;
        work = iGpffff9db0;
        *(s16 *)(fldResourceWorkOffset(*(s32 *)(work + 0x98) * 4, work) + 0x9E) = (s16)arg1;
        *(s32 *)(iGpffff9db0 + 0x98) += 1;
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
 * 2026-10-09: 90 -> 86: func_0015e960's last parameter is s16.
 * 2026-10-09: 86 -> 84: the loaded HBN entry is its own local `hbnEntry`.
 * 2026-10-09: 84 -> 83: the first file check assigns `var_2 = 1` in its NULL branch.
 * 2026-10-09: 83 -> 70: temp_18 is declared before temp_19.
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
static inline s32 fldResourceReady_0014f310(u8 *file)
{
    if (file == NULL) {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded((s32)file) != 0) {
        return 1;
    }
    return 0;
}

static inline s32 fldResourceReadyOne_0014f310(u8 *file, s32 one)
{
    if (file == NULL) {
        return one;
    }
    if (H_Cdvd_IsFileLoaded((s32)file) != 0) {
        return 1;
    }
    return 0;
}

// FUN_0014F310
s32 FldResource_StepPartLoad(s32 arg0, s32 arg1) {
    /* Only the fields read while opening the primary FBN are described. */
    typedef struct FldPartReadWork {
        s32 majorId;                    /* 0x00, narrowed to u16 for the FBN */
        s32 minorId;                    /* 0x04, narrowed to u16 for the FBN */
        u8 unknown08[8];
        s16 variant;                    /* 0x10 */
        u8 unknown12[0x16];
        u8 *primaryResource;            /* 0x28 */
    } FldPartReadWork;
    typedef struct FldResourceFbnView {
        u8 unknown000[0xA48];
        u8 *file;                       /* 0xA48 */
        u8 *data;                       /* 0xA4C */
    } FldResourceFbnView;
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

    extern void *FldRc_CreateResource(s16 arg0, s16 arg1);
    extern s32 FldResource_IsFileLoaded(u8 *arg0);
    extern void FldResource_ParseChunks(u8 *arg0);
    extern s32 FldResource_PollLoads(u8 *arg0);
    extern void FldResource_RequestEntryLoads(u8 *arg0);
    extern s32 FldResource_TryInstallEntries(u8 *arg0);
    extern f32 KDraw_MatrixPitchDeg(u8 *arg0);
    extern f32 KDraw_MatrixYawDeg(u8 *arg0);
    extern f32 KDraw_MatrixRollDeg(u8 *arg0);
    extern s32 FldMap_IsCurrentInBandB(void);
    extern s32 FldMap_IsCurrentInBandA(void);
    extern void resrcMngResetRenderSlots(void);
    extern void resrcMngSetDrawEnabled(s32 arg0, s32 arg1);
    extern s32 func_00153c00(s32 arg0);
    extern s32 func_00153d60(u8 *arg0, s32 arg1);
    extern s32 func_00154b10(void);
    extern s32 func_00154be0(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3, s32 *arg4, u8 *arg5, f32 *arg6, f32 *arg7, s32 *arg_sp0, s32 *arg_sp8);
    /* lint: allow H011 -- retail passes an already-u16-masked ID as a word;
     * the provider consumes that same u16 ID. */
    extern void MT_Scene_SetResPlacement(s32 id, u8 *position, u8 *angles);
    /* lint: allow H011 -- the final arguments are array addresses; the provider
     * casts its s32 words to memcpy sources of 0x20 and 0x180 bytes. */
    extern s32 MT_Scene_CreateCameraRes(u16 id, s32 kind, f32 fieldOfView, u8 *cameraMatrix, u8 *secondaryMatrix, u8 *position, f32 value60, f32 value64, s8 *indices, Vec3 *positions);
    extern u8 *MT_Scene_GetResListHead(s32 arg0);
    // lint: allow H011 -- measured: u16 prototype regresses FldResource_StepPartLoad (andi on wide id args)
    extern u8 *MT_Scene_GetRes(s32 arg0);
    extern void MT_Scene_DestroyRes(u16 arg0);
    extern s32 MT_Scene_CreateModelFldRes(u16 arg0, s32 arg1);
    extern s32 MT_Scene_CreateRes11(u16 arg0, s32 arg1);
    /* lint: allow H011 -- the resource pointer is stored unchanged in the
     * provider's +0x1A0 field; its s32 parameter is a 32-bit address carrier. */
    extern s32 MT_Scene_CreateFldRes(u16 id, u8 *resource);
    extern u8 *func_0015f8e0(s32 arg0, s32 arg1);
    extern s32 func_0015f9b0(u8 *arg0, u16 **arg1, s32 arg2, s32 arg3);
    extern void func_0015fb00(u8 *arg0, s32 arg1);
    extern u8 *func_0015e870(s32 arg0, s32 arg1, s16 arg2);
    /* lint: allow H011 -- retail supplies a signed halfword variant; the
     * provider's only use narrows its s32 parameter to s16 for the filename. */
    extern s32 func_0015e960(u8 *arg0, u8 **arg1, s32 arg2, s32 arg3, s16 arg4);
    extern s32 func_0015f000(u8 *arg0, u8 *arg1);
    extern s32 FldStepLoadHandleIsDone(u8 *arg0);
    extern void FldStepLoadHandleDestroy(u8 *arg0);
    extern s32 NpcTable_RequestSceneTable(void);
    extern s32 NpcTable_InstallSceneTable(u8 *arg0);
    extern s32 NpcTable_RequestSecondaryTable(void);
    extern s32 NpcTable_InstallSecondaryTable(u8 *arg0);
    extern s32 FldStepIndex(void);
    extern s32 func_0015ac60(s32 arg0);
    extern s32 func_0015a7c0(s32 arg0);
    extern void func_001599d0(void);
    extern void func_0015b240(void);
    extern void func_001582f0(s32 arg0, s32 arg1, s32 arg2);
    extern void *mdlGetClump(void *arg0);
    extern s32 func_0018c6c0(u8 *arg0, s32 arg1);
    extern s32 func_003ef6d0(void);
    extern s32 func_003ef650(s32 arg0, u8 *arg1);
    extern void memcpy(void *dst, const void *src, s32 size);
    extern u8 *func_003e8180(u8 *arg0, f32 arg1);
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
    u8 *temp_16;
    u8 *var_18_4;
    u8 *temp_16_11;
    u8 *temp_17_3;
    s32 temp_19;
    u8 *temp_2;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_12;
    uintptr_t initialPrimary;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_17;
    uintptr_t reloadedPrimary;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_22;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;
    u8 *temp_3_11;
    u8 *temp_3_12;
    u8 *temp_3_13;
    u8 *temp_3_15;
    u8 *temp_3_16;
    u8 *temp_3_17;
    u8 *temp_3_18;
    FldPartReadWork *initialPartWork;
    u8 *temp_3_20;
    u8 *temp_3_21;
    u8 *temp_3_22;
    FldPartReadWork *reloadedPartWork;
    u8 *temp_3_24;
    u8 *temp_3_25;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *temp_3_6;
    u8 *temp_3_7;
    u8 *temp_3_8;
    u8 *temp_3_9;
    u8 *temp_4;
    u8 *temp_4_10;
    u8 *temp_4_11;
    u8 *temp_4_12;
    u8 *temp_4_13;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_8;
    u8 *temp_4_9;
    s32 var_9;
    u8 *temp_8;
    s32 temp_7;
    u8 *a_dst;
    u8 *a_idx;
    s32 a_preset;
    s32 a_resource;
    u8 *a_tbl;
    s32 var_9_2;
    u8 *temp_8_2;
    s32 temp_7_2;
    u8 *b_dst;
    u8 *b_idx;
    s32 b_preset;
    s32 b_resource;
    u8 *b_tbl;
    u8 *var_17_7;
    u8 *temp_16_10;
    u8 *temp_18;
    u32 *frameCount;
    u8 *hbnEntry;
    s32 var_19;
    s32 var_19_2;
    s32 temp_18_2;
    s32 temp_18_3;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_18_5;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_17_4;
    s32 temp_17_5;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 var_17;
    s32 var_17_2;
    s32 var_17_5;
    s32 var_17_6;
    s32 var_17_8;
    s32 var_17_9;
    u32 var_17_3;
    u32 var_17_4;
    s32 temp_16_12;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_16_4;
    s32 temp_16_5;
    s32 temp_16_6;
    s32 temp_16_7;
    s32 temp_16_8;
    s32 temp_16_9;
    s32 var_16;
    s32 var_16_10;
    s32 var_16_11;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_16_4;
    s32 var_16_5;
    s32 var_16_6;
    s32 var_16_7;
    s32 var_16_8;
    s32 var_16_9;
    s32 temp_4_5;
    u8 temp_4_6;
    u8 temp_4_7;
    s32 temp_3;
    s32 temp_3_10;
    s32 temp_3_14;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 one;
    s32 var_2_4;

    temp_3 = (s32)(*( s32 * )(iGpffff9db0 + 0x94));
    if (temp_3 == 999) goto completed;
    if (temp_3 == 41) goto waitReloadedEnvironment;
    if (temp_3 == 40) goto loadEnvironment;
    if (temp_3 == 32) goto waitReloadedParts;
    if (temp_3 == 31) goto readReloadedParts;
    if (temp_3 == 30) goto reloadParts;
    if (temp_3 == 13) goto waitParts;
    if (temp_3 == 12) goto readParts;
    if (temp_3 == 11) goto loadParts;
    if (temp_3 == 10) goto readCamera;
    if (temp_3 == 9) goto waitEnvironment;
    if (temp_3 == 8) goto readHbnResources;
    if (temp_3 == 7) goto readGrid;
    if (temp_3 == 6) goto prepareGrid;
    if (temp_3 == 5) goto waitNpcTables;
    if (temp_3 == 4) goto loadNpcTables;
    if (temp_3 == 3) goto waitResourceInitialization;
    if (temp_3 == 2) goto initializeResources;
    one = 1;
    if (temp_3 == one) goto waitFieldResource;
    switch (temp_3) {
    case 0: goto loadFieldResource;
    default: goto block_259;
    }
loadFieldResource:
            if (fldResourceReadyOne_0014f310((u8 *)iGpffffb200, one) == 0) {
                return 0;
            }
            if (fldResourceReady_0014f310((u8 *)iGpffffb204) == 0) {
                return 0;
            }
            temp_3_2 = (u8 *)(iGpffff9db0);
            *( s32 * )(temp_3_2 + 0x98) = (s32) (*( s32 * )(temp_3_2 + 0x98) - 1);
            temp_16 = (u8 *)(iGpffff9db0);
            temp_2 = (u8 *)(*( s32 * )(temp_16 + 0x98) * 4);
            temp_2 += (s32)temp_16;
            (((s32 *)(temp_16 + 0x28))[*( s32 * )(temp_16 + 0x24)]) = (s32)FldRc_CreateResource(*( s16 * )(temp_2 + 0x9C), *( s16 * )(temp_2 + 0x9E));
            *( s32 * )(iGpffff9db0 + 0x94) = 1;
waitFieldResource:
            temp_3_3 = (u8 *)(iGpffff9db0);
            if (FldResource_IsFileLoaded((((u8 **)(temp_3_3 + 0x28))[*( s32 * )(temp_3_3 + 0x24)])) == 0) {
                return 0;
            }
            temp_3_4 = (u8 *)(iGpffff9db0);
            FldResource_ParseChunks((u8 *)((((s8 **)(temp_3_4 + 0x28))[*( s32 * )(temp_3_4 + 0x24)])));
            *( s32 * )(iGpffff9db0 + 0x94) = 2;
initializeResources:
            temp_3_5 = (u8 *)(iGpffff9db0);
            if (FldResource_PollLoads((((u8 **)(temp_3_5 + 0x28))[*( s32 * )(temp_3_5 + 0x24)])) == 0) {
                return 0;
            }
            temp_3_6 = (u8 *)(iGpffff9db0);
            *( s32 * )(temp_3_6 + 0x24) = (s32) (*( s32 * )(temp_3_6 + 0x24) + 1);
            temp_4_3 = (u8 *)(iGpffff9db0);
            if (*( s32 * )(temp_4_3 + 0x98) > 0) {
                *( s32 * )(temp_4_3 + 0x94) = 0;
                return 0;
            }
            if (*( s32 * )(temp_4_3 + 0xC) & 0x80000000) {
                *( s32 * )(temp_4_3 + 0) = (s32) *( s16 * )(*( u8 ** )(temp_4_3 + 0x28) + 4);
                temp_3_7 = (u8 *)(iGpffff9db0);
                *( s32 * )(temp_3_7 + 4) = (s32) *( s16 * )(*( u8 ** )(temp_3_7 + 0x28) + 6);
            }
            var_16 = 0;
            while (var_16 < *( s32 * )((temp_3_8 = (u8 *)(iGpffff9db0)) + 0x24)) {
                FldResource_RequestEntryLoads(*( u8 ** )((temp_3_8 + (var_16 * 4)) + 0x28));
                var_16 += 1;
            }
            *( s32 * )(temp_3_8 + 0x94) = 3;
waitResourceInitialization:
            var_17 = 0;
            var_16_2 = 0;
            while (var_16_2 < *( s32 * )((temp_3_9 = (u8 *)(iGpffff9db0)) + 0x24)) {
                if (FldResource_TryInstallEntries(*( u8 ** )((temp_3_9 + (var_16_2 * 4)) + 0x28)) == 0) {
                    var_17 += 1;
                }
                var_16_2 += 1;
            }
            if (var_17 != 0) {
                return 0;
            }
            temp_4_4 = (u8 *)(iGpffffb204);
            if (temp_4_4 != NULL) {
                H_Cdvd_Destroy(temp_4_4);
                iGpffffb204 = 0;
            }
            temp_4_5 = (s32)(*( s32 * )(iGpffff9db0 + 0x8C));
            if (temp_4_5 != 0) {
                K_Clump_FreeTextureNameList((void *)(temp_4_5));
                *( s32 * )(iGpffff9db0 + 0x8C) = 0;
            }
            *( s32 * )(iGpffff9db0 + 0x94) = 4;
loadNpcTables:
            temp_3_10 = (s32)(chkmemGetBytes() - iGpffffb208);
            iGpffffb208 = temp_3_10;
            if (*( s32 * )(iGpffff9db0 + 0) < 0xC8) {
                iGpffffb208 = (s32) (temp_3_10 + 0x32000);
            }
            D_007D24E0[0] = NpcTable_RequestSceneTable();
            D_007D24E8[0] = NpcTable_RequestSecondaryTable();
            *( s32 * )(iGpffff9db0 + 0x94) = 5;
waitNpcTables:
            if (NpcTable_InstallSceneTable((u8 *)D_007D24E0[0]) == 0) {
                return 0;
            }
            D_007D24E0[0] = 0;
            if (NpcTable_InstallSecondaryTable((u8 *)D_007D24E8[0]) == 0) {
                return 0;
            }
            D_007D24E8[0] = 0;
            *( s32 * )(iGpffff9db0 + 0x94) = 6;
prepareGrid:
            *( s32 * )(iGpffff9db0 + 0x94) = 7;
readGrid:
            var_16_3 = 0;
            if (FldStepLoadHandleIsDone((u8 *)(*( s32 * )(((u8 *)MT_Scene_GetFrameState()) + 0x1864))) == 0) {
                var_16_3 += 1;
            }
            if (var_16_3 != 0) {
                return 0;
            }
            var_17_2 = 0;
            while (var_17_2 < *( s32 * )((temp_3_11 = (u8 *)(iGpffff9db0)) + 0x24)) {
                temp_16_2 = var_17_2 * 4;
                if (*( s32 * )(*( u8 ** )((temp_3_11 + temp_16_2) + 0x28) + 0xA40) == 0) {
                    temp_2_2 = (u8 *)(*( u8 ** )((iGpffff9db0 + temp_16_2) + 0x28));
                    *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_16_2) + 0x28) + 0xA3C) = (s32)func_0015f8e0(*( u16 * )(temp_2_2 + 4), *( u16 * )(temp_2_2 + 6));
                }
                var_17_2 += 1;
            }
            if (FldMap_IsCurrentInBandB() != 0) {
                temp_16_3 = (s32)(*( s32 * )(*( u8 ** )(((u8 *)MT_Scene_GetFrameState()) + 0x1864) + 0x110));
                memcpy(((u8 *)MT_Scene_GetFrameState()) + 0x54,(const void *)((u8 *)temp_16_3 + 4), 0x1800);
                FldStepLoadHandleDestroy((u8 *)(*( s32 * )(((u8 *)MT_Scene_GetFrameState()) + 0x1864)));
                for (var_18 = 0; var_18 < 0x18; var_18++) {
                    var_19 = 0;
                    temp_17 = var_18 << 8;
                    for (; var_19 < 0x10; var_19++) {
                        temp_16_4 = var_19 * 0x10;
                        if ((*( u8 * )(((u8 *)(temp_17 + (s32)MT_Scene_GetFrameState()) + temp_16_4) + 0x54) == 1) && (*( u8 * )(((u8 *)(temp_17 + (s32)MT_Scene_GetFrameState()) + temp_16_4) + 0x58) == 6)) {
                            *( u8 * )(((u8 *)MT_Scene_GetFrameState()) + 0x44) = (u8)var_19;
                            *( u8 * )(((u8 *)MT_Scene_GetFrameState()) + 0x45) = (u8)var_18;
                            goto found_loop_88;
                        }
                    }
                }
found_loop_88:
                for (var_19_2 = 0; var_19_2 < 0x18; var_19_2++) {
                    var_18_2 = 0;
                    temp_17_2 = var_19_2 << 8;
                    for (; var_18_2 < 0x10; var_18_2++) {
                        temp_16_5 = var_18_2 * 0x10;
                        if ((*( u8 * )(((u8 *)(temp_17_2 + (s32)MT_Scene_GetFrameState()) + temp_16_5) + 0x54) == 1) && ((*( u8 * )(((u8 *)(temp_17_2 + (s32)MT_Scene_GetFrameState()) + temp_16_5) + 0x58) == 0xA) || (*( u8 * )(((u8 *)(temp_17_2 + (s32)MT_Scene_GetFrameState()) + temp_16_5) + 0x58) == 0xC) || (*( u8 * )(((u8 *)(temp_17_2 + (s32)MT_Scene_GetFrameState()) + temp_16_5) + 0x58) == 0xE))) {
                            *( u8 * )(((u8 *)MT_Scene_GetFrameState()) + 0x46) = (u8)var_18_2;
                            *( u8 * )(((u8 *)MT_Scene_GetFrameState()) + 0x47) = (u8)var_19_2;
                            goto found_loop_99;
                        }
                    }
                }
found_loop_99:
                temp_2_3 = (u8 *)(iGpffff9db0);
                temp_16_6 = (s32)(func_0015f8e0(*( u16 * )(temp_2_3 + 0), *( u16 * )(temp_2_3 + 4)));
                *( s32 * )(((u8 *)MT_Scene_GetFrameState()) + 0x1864) = temp_16_6;
            }
            *( s32 * )(iGpffff9db0 + 0x94) = 8;
readHbnResources:
            if (FldMap_IsCurrentInBandB() != 0) {
                hbnData = NULL;
                var_16_4 = 0;
                while (var_16_4 < *( s32 * )(iGpffff9db0 + 0x24)) {
                    temp_2_4 = (u8 *)iGpffff9db0;
                    temp_17_4 = var_16_4 * 4;
                    temp_2_4 = (u8 *)(*( u8 ** )((temp_2_4 + temp_17_4) + 0x28));
                    if (func_0015f9b0((u8 *)(*( s32 * )(temp_2_4 + 0xA3C)),(u16 **)(temp_2_4 + 0xA40), *( u16 * )(temp_2_4 + 4), *( u16 * )(temp_2_4 + 6)) == 0) {
                        return 0;
                    }
                    *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_17_4) + 0x28) + 0xA3C) = 0;
                    var_16_4 += 1;
                }
                var_16_5 = 0;
                while (var_16_5 < *( s32 * )((temp_17_3 = (u8 *)(iGpffff9db0)) + 0x24)) {
                    func_0015fb00((u8 *)(*( s8 ** )(*( u8 ** )((temp_17_3 + (var_16_5 * 4)) + 0x28) + 0xA40)), 0);
                    var_16_5 += 1;
                }
                if (func_0015f9b0((u8 *)(*( s32 * )(((u8 *)MT_Scene_GetFrameState()) + 0x1864)),&hbnData, *( u16 * )(temp_17_3 + 0), *( u16 * )(temp_17_3 + 4)) == 0) {
                    return 0;
                }
                if ((hbnEntry = (u8 *)hbnData) != NULL) {
                    func_0015fb00(hbnEntry, 1);
                    jtbl_008873EC[0](hbnData);
                    *( s32 * )(((u8 *)MT_Scene_GetFrameState()) + 0x1864) = 0;
                }
                goto block_123;
            }
            var_16_6 = 0;
            while (var_16_6 < *( s32 * )(iGpffff9db0 + 0x24)) {
                temp_2_10 = (u8 *)iGpffff9db0;
                temp_17_5 = var_16_6 * 4;
                temp_2_10 = (u8 *)(*( u8 ** )((temp_2_10 + temp_17_5) + 0x28));
                if (func_0015f9b0((u8 *)(*( s32 * )(temp_2_10 + 0xA3C)),(u16 **)(temp_2_10 + 0xA40), *( u16 * )(temp_2_10 + 4), *( u16 * )(temp_2_10 + 6)) == 0) {
                    return 0;
                }
                *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_17_5) + 0x28) + 0xA3C) = 0;
                var_16_6 += 1;
            }
            var_16_7 = 0;
            while (var_16_7 < *( s32 * )((temp_3_12 = (u8 *)(iGpffff9db0)) + 0x24)) {
                func_0015fb00((u8 *)(*( s8 ** )(*( u8 ** )((temp_3_12 + (var_16_7 * 4)) + 0x28) + 0xA40)), 0);
                var_16_7 += 1;
            }
block_123:
            if (FldMap_IsCurrentInBandA() == 1) {
                var_9 = 0;
                temp_8 = (u8 *)(iGpffff9db0);
                a_dst = (u8 *)D_007E8060;
                a_idx = (u8 *)D_005F05B8;
                a_tbl = (u8 *)D_005F0590;
                while (a_preset = *(u8 *)(a_idx + *(s32 *)temp_8 - 0x28),
                       var_9 < *(u8 *)(a_tbl + a_preset * 0xC)) {
                    temp_7 = var_9 * 4;
                    a_resource = *(s32 *)(temp_8 + temp_7 + 0x28);
                    *(s32 *)(a_dst + temp_7) = a_resource;
                    var_9 += 1;
                }
                if (func_0015ac60(FldStepIndex()) == 0) {
                    func_001582f0(*( s32 * )(iGpffff9db0 + 0) - 0x28, *( s32 * )(((u8 *)MT_Scene_GetFrameState()) + 0x4C), 1);
                    func_0015a7c0(FldStepIndex());
                }
                func_001599d0();
                func_0015b240();
            } else if (FldMap_IsCurrentInBandB() != 0) {
                var_9_2 = 0;
                temp_8_2 = (u8 *)(iGpffff9db0);
                b_dst = (u8 *)D_007E8060;
                b_idx = (u8 *)D_005F05B8;
                b_tbl = (u8 *)D_005F0590;
                while (b_preset = *(u8 *)(b_idx + *(s32 *)temp_8_2 - 0x3C),
                       var_9_2 < *(u8 *)(b_tbl + b_preset * 0xC + 1)) {
                    temp_7_2 = var_9_2 * 4;
                    b_resource = *(s32 *)(temp_8_2 + temp_7_2 + 0x28);
                    *(s32 *)(b_dst + temp_7_2) = b_resource;
                    var_9_2 += 1;
                }
                if (func_0015ac60(FldStepIndex()) == 0) {
                    func_0015a7c0(FldStepIndex());
                }
                func_001599d0();
                func_0015b240();
            } else {
                MT_Scene_CreateFldRes(0, *( u8 ** )(iGpffff9db0 + 0x28));
                var_17_3 = 0;
                while (var_17_3 < (u32) *( u32 * )((temp_3_13 = (u8 *)(*( u8 ** )(iGpffff9db0 + 0x28))) + 0x11C)) {
                    temp_16_7 = var_17_3 * 0x18;
                    temp_18 = (u8 *)(func_003e9700(*( RwFrame ** )((temp_3_13 + temp_16_7) + 0x128)));
                    temp_3_14 = (*( u16 * )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_7) + 0x120));
                    if ((temp_3_14 == 0) || (temp_3_14 == 2)) {
                        temp_2_5 = *( u8 ** )(iGpffff9db0 + 0x28);
                        temp_2_5 += var_17_3 * 0x18;
                        temp_19 = (s32)(MT_Scene_CreateModelFldRes(*( u16 * )(temp_2_5 + 0x124), *( s32 * )(temp_2_5 + 0x12C)) & 0xFFFF);
                        if (temp_19 == 0) {
                            kAssertFail((const char *)D_005EFC80, 0x297);
                        }
                        angles.x = KDraw_MatrixPitchDeg(temp_18);
                        angles.y = KDraw_MatrixYawDeg(temp_18);
                        angles.z = KDraw_MatrixRollDeg(temp_18);
                        MT_Scene_SetResPlacement(temp_19, temp_18 + 0x30, (u8 *)&angles);
                        temp_4_8 = (u8 *)(iGpffff9db0);
                        if ((*( s32 * )(temp_4_8 + 0) != 0x14) || (*( s32 * )(temp_4_8 + 4) != 1)) {
                            temp_18_2 = (s32)(mdlGetClump(*( void ** )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_7) + 0x12C)));
                            if (func_0018c6c0((u8 *)(temp_18_2), func_003ef650(func_003ef6d0(), D_005EFCB0)) == 1) {
                                temp_2_6 = (u8 *)(MT_Scene_GetRes(temp_19));
                                *( s32 * )(temp_2_6 + 0x28) = (s32) (*( s32 * )(temp_2_6 + 0x28) | 0x01000000);
                            }
                        }
                        if (*( u16 * )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_7) + 0x122) & 2) {
                            temp_2_6 = (u8 *)(MT_Scene_GetRes(temp_19));
                            *( s32 * )(temp_2_6 + 0x150) = 1;
                        }
                        *( s32 * )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_7) + 0x12C) = 0;
                    }
                    var_17_3 += 1;
                }
                var_17_4 = 0;
                while (var_17_4 < *(frameCount = (u32 *)((temp_4_9 = (u8 *)(*( u8 ** )(iGpffff9db0 + 0x28))) + 0x11C))) {
                    temp_16_8 = var_17_4 * 0x18;
                    func_003e9700(*( RwFrame ** )((temp_4_9 + temp_16_8) + 0x128));
                    temp_4_10 = (u8 *)(*( u8 ** )(iGpffff9db0 + 0x28));
                    if (*( u16 * )((temp_4_10 + temp_16_8) + 0x120) == 1) {
                        temp_2_7 = (u8 *)(temp_4_10 + (var_17_4 * 0x18));
                        temp_18_3 = (s32)(MT_Scene_CreateRes11(*( u16 * )(temp_2_7 + 0x124), *( s32 * )(temp_2_7 + 0x130)) & 0xFFFF);
                        if (temp_18_3 == 0) {
                            kAssertFail((const char *)D_005EFC80, 0x2C7);
                        }
                        *( s32 * )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_8) + 0x130) = 0;
                        temp_2_8 = (u8 *)(MT_Scene_GetRes(temp_18_3));
                        *( s32 * )(temp_2_8 + 0x28) = (s32) (*( s32 * )(temp_2_8 + 0x28) | 2);
                    }
                    var_17_4 += 1;
                }
                *frameCount = 0U;
                resrcMngResetRenderSlots();
                {
                    s32 enable = 1;

                    resrcMngSetDrawEnabled(enable, enable);
                }
            }
            *( s32 * )(iGpffff9db0 + 0xDC) = func_00153c00(*( s16 * )(iGpffff9db0 + 0x12));
            if (*( s32 * )(iGpffff9db0 + 0) >= 0xC8) {
                func_003e8180((void *)(u32)func_00457120(), 100.0f);
            }
            if (*( s32 * )(iGpffff9db0 + 0) < 0xC8) {
                func_003e8180((void *)(u32)func_00457120(), 100.0f);
            }
            temp_3_15 = (u8 *)(iGpffff9db0);
            if (*( s32 * )(temp_3_15 + 0xDC) == 0) {
                *( s32 * )(iGpffff9db0 + 0xDC) = func_00154b10();
                temp_3_16 = (u8 *)(iGpffff9db0);
                if (*( s32 * )(temp_3_16 + 0xDC) != 0) {
                    *( s32 * )(temp_3_16 + 0x94) = 0xA;
                } else {
                    *( s32 * )(temp_3_16 + 0x94) = 0xB;
                }
                goto block_259;
            }
            *( s32 * )(temp_3_15 + 0x94) = 9;
waitEnvironment:
            temp_2_9 = (u8 *)(iGpffff9db0);
            if (func_00153d60((u8 *)(*( s32 * )(temp_2_9 + 0xDC)), *( s16 * )(temp_2_9 + 0x12)) != 0) {
                *( s32 * )(iGpffff9db0 + 0xDC) = func_00154b10();
                temp_3_17 = (u8 *)(iGpffff9db0);
                if (*( s32 * )(temp_3_17 + 0xDC) != 0) {
                    *( s32 * )(temp_3_17 + 0x94) = 0xA;
                } else {
                    *( s32 * )(temp_3_17 + 0x94) = 0xB;
                    goto block_259;
                }
            } else {
                return 0;
            }
readCamera:
            if (func_00154be0((u8 *)(*( s32 * )(iGpffff9db0 + 0xDC)), (u8 *)&cameraMatrix, (u8 *)&secondaryCameraMatrix, &fieldOfView, &cameraKind, (u8 *)&cameraPosition, &cameraValue60, &cameraValue64, (s32 *)cameraEntries, (s32 *)cameraEntryPositions) != 0) {
                MT_Scene_CreateCameraRes(0, cameraKind, fieldOfView, (u8 *)&cameraMatrix, (u8 *)&secondaryCameraMatrix, (u8 *)&cameraPosition, cameraValue60, cameraValue64, cameraEntries, cameraEntryPositions);
                *( s32 * )(iGpffff9db0 + 0x94) = 0xB;
                goto block_259;
            }
            return 0;
loadParts:
        if (FldMap_IsCurrentInBandB() == 1) {
            temp_2_11 = (u8 *)(iGpffff9db0);
            *( s32 * )(*( u8 ** )(iGpffff9db0 + 0x28) + 0xA48) = (s32)func_0015e870(*( u16 * )(temp_2_11 + 0), *( u16 * )(temp_2_11 + 4), *( s16 * )(temp_2_11 + 0x10));
        } else {
            var_16_8 = 0;
            while (var_16_8 < *( s32 * )(iGpffff9db0 + 0x24)) {
                temp_3_18 = (u8 *)(iGpffff9db0);
                temp_17_6 = var_16_8 * 4;
                temp_2_12 = (u8 *)(*( u8 ** )((temp_3_18 + temp_17_6) + 0x28));
                *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_17_6) + 0x28) + 0xA48) = (s32)func_0015e870(*( u16 * )(temp_2_12 + 4), *( u16 * )(temp_2_12 + 6), *( s16 * )(temp_3_18 + 0x10));
                var_16_8 += 1;
            }
        }
        *( s32 * )(iGpffff9db0 + 0x94) = 0xC;
        /* fallthrough */
readParts:
        var_16_9 = 0;
        initialPrimary = FldMap_IsCurrentInBandB();
        if (initialPrimary == 1) {
            initialPartWork = (FldPartReadWork *)iGpffff9db0;
            initialPrimary = (uintptr_t)initialPartWork->primaryResource;
            if (func_0015e960(((FldResourceFbnView *)initialPrimary)->file,
                             &((FldResourceFbnView *)initialPrimary)->data,
                             (u16)initialPartWork->majorId,
                             (u16)initialPartWork->minorId,
                             initialPartWork->variant) == 0) {
                var_16_9 += 1;
            }
        } else {
            var_17_5 = 0;
            while (var_17_5 < *( s32 * )(iGpffff9db0 + 0x24)) {
                temp_3_20 = (u8 *)(iGpffff9db0);
                temp_2_14 = (u8 *)(*( u8 ** )((temp_3_20 + (var_17_5 * 4)) + 0x28));
                if (func_0015e960((u8 *)(*( s32 * )(temp_2_14 + 0xA48)), (u8 **)(temp_2_14 + 0xA4C), *( u16 * )(temp_2_14 + 4), *( u16 * )(temp_2_14 + 6), *( s16 * )(temp_3_20 + 0x10)) == 0) {
                    var_16_9 += 1;
                }
                var_17_5 += 1;
            }
        }
        if (var_16_9 != 0) {
            return 0;
        }
        *( s32 * )(iGpffff9db0 + 0x94) = 0xD;
waitParts:
        var_17_6 = 0;
        var_18_3 = 0;
        while (var_18_3 < *( s32 * )((temp_3_21 = (u8 *)(iGpffff9db0)) + 0x24)) {
            temp_2_15 = (u8 *)iGpffff9db0;
            temp_16_9 = var_18_3 * 4;
            temp_2_15 = (u8 *)(*( u8 ** )((temp_2_15 + temp_16_9) + 0x28));
            if (func_0015f000((u8 *)(*( s32 * )(temp_2_15 + 0xA48)),(u8 *)(*( s32 * )(temp_2_15 + 0xA4C))) == 0) {
                var_17_6 += 1;
            } else {
                *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_16_9) + 0x28) + 0xA48) = 0;
            }
            var_18_3 += 1;
        }
        if (var_17_6 != 0) {
            return 0;
        }
        *( s32 * )(temp_3_21 + 0x94) = 0x3E7;
        goto block_259;
reloadParts:
        var_18_4 = (u8 *)(MT_Scene_GetResListHead(3));
        var_17_7 = (u8 *)(MT_Scene_GetResListHead(8));
        if (fldResourceReady_0014f310((u8 *)iGpffffb200) != 0) {
            while (var_18_4 != NULL) {
                temp_16_10 = (u8 *)(*( u8 ** )(var_18_4 + 0x138));
                MT_Scene_DestroyRes(*( u16 * )(var_18_4 + 0));
                var_18_4 = (u8 *)(temp_16_10);
            }
            while (var_17_7 != NULL) {
                temp_16_11 = (u8 *)(*( u8 ** )(var_17_7 + 0x138));
                MT_Scene_DestroyRes(*( u16 * )(var_17_7 + 0));
                var_17_7 = (u8 *)(temp_16_11);
            }
            if (FldMap_IsCurrentInBandB() == 1) {
                temp_2_16 = (u8 *)(iGpffff9db0);
                *( s32 * )(*( u8 ** )(iGpffff9db0 + 0x28) + 0xA48) = (s32)func_0015e870(*( u16 * )(temp_2_16 + 0), *( u16 * )(temp_2_16 + 4), *( s16 * )(temp_2_16 + 0x10));
            } else {
                var_16_10 = 0;
                while (var_16_10 < *( s32 * )(iGpffff9db0 + 0x24)) {
                    temp_3_22 = (u8 *)(iGpffff9db0);
                    temp_17_7 = var_16_10 * 4;
                    temp_2_17 = (u8 *)(*( u8 ** )((temp_3_22 + temp_17_7) + 0x28));
                    *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_17_7) + 0x28) + 0xA48) = (s32)func_0015e870(*( u16 * )(temp_2_17 + 4), *( u16 * )(temp_2_17 + 6), *( s16 * )(temp_3_22 + 0x10));
                    var_16_10 += 1;
                }
            }
            *( s32 * )(iGpffff9db0 + 0x94) = 0x1F;
readReloadedParts:
            var_16_11 = 0;
            reloadedPrimary = FldMap_IsCurrentInBandB();
            if (reloadedPrimary == 1) {
                reloadedPartWork = (FldPartReadWork *)iGpffff9db0;
                reloadedPrimary = (uintptr_t)reloadedPartWork->primaryResource;
                if (func_0015e960(((FldResourceFbnView *)reloadedPrimary)->file,
                                 &((FldResourceFbnView *)reloadedPrimary)->data,
                                 (u16)reloadedPartWork->majorId,
                                 (u16)reloadedPartWork->minorId,
                                 reloadedPartWork->variant) == 0) {
                    var_16_11 += 1;
                }
            } else {
                var_17_8 = 0;
                while (var_17_8 < *( s32 * )(iGpffff9db0 + 0x24)) {
                    temp_3_24 = (u8 *)(iGpffff9db0);
                    temp_2_19 = (u8 *)(*( u8 ** )((temp_3_24 + (var_17_8 * 4)) + 0x28));
                    if (func_0015e960((u8 *)(*( s32 * )(temp_2_19 + 0xA48)), (u8 **)(temp_2_19 + 0xA4C), *( u16 * )(temp_2_19 + 4), *( u16 * )(temp_2_19 + 6), *( s16 * )(temp_3_24 + 0x10)) == 0) {
                        var_16_11 += 1;
                    }
                    var_17_8 += 1;
                }
            }
            if (var_16_11 != 0) {
                return 0;
            }
            *( s32 * )(iGpffff9db0 + 0x94) = 0x20;
waitReloadedParts:
            var_17_9 = 0;
            if (FldMap_IsCurrentInBandB() == 1) {
                temp_2_20 = (u8 *)(*( u8 ** )(iGpffff9db0 + 0x28));
                if (func_0015f000((u8 *)(*( s32 * )(temp_2_20 + 0xA48)),(u8 *)(*( s32 * )(temp_2_20 + 0xA4C))) == 0) {
                    var_17_9 += 1;
                } else {
                    *( s32 * )(*( u8 ** )(iGpffff9db0 + 0x28) + 0xA48) = 0;
                }
            } else {
                var_18_5 = 0;
                while (var_18_5 < *( s32 * )(iGpffff9db0 + 0x24)) {
                    temp_2_21 = (u8 *)iGpffff9db0;
                    temp_16_12 = var_18_5 * 4;
                    temp_2_21 = (u8 *)(*( u8 ** )((temp_2_21 + temp_16_12) + 0x28));
                    if (func_0015f000((u8 *)(*( s32 * )(temp_2_21 + 0xA48)),(u8 *)(*( s32 * )(temp_2_21 + 0xA4C))) == 0) {
                        var_17_9 += 1;
                    } else {
                        *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_16_12) + 0x28) + 0xA48) = 0;
                    }
                    var_18_5 += 1;
                }
            }
            if (var_17_9 != 0) {
                return 0;
            }
            temp_3_25 = (u8 *)(iGpffff9db0);
            if (*( s32 * )(temp_3_25 + 0xC) & 4) {
                *( s32 * )(temp_3_25 + 0x94) = 0x28;
            } else {
                *( s32 * )(temp_3_25 + 0x94) = 0x3E7;
                goto block_259;
            }
loadEnvironment:
            if (fldResourceReady_0014f310((u8 *)iGpffffb200) == 0) {
                goto block_259;
            }
            *( s32 * )(iGpffff9db0 + 0xDC) = func_00153c00(*( s16 * )(iGpffff9db0 + 0x12));
            *( s32 * )(iGpffff9db0 + 0x94) = 0x29;
waitReloadedEnvironment:
            temp_2_22 = (u8 *)(iGpffff9db0);
            if (func_00153d60((u8 *)(*( s32 * )(temp_2_22 + 0xDC)), *( s16 * )(temp_2_22 + 0x12)) != 0) {
                *( s32 * )(iGpffff9db0 + 0x94) = 0x3E7;
                goto block_259;
            }
            return 0;
        }
        goto block_259;
completed:
        temp_4_13 = (u8 *)(iGpffffb200);
        if (temp_4_13 != NULL) {
            H_Cdvd_Destroy(temp_4_13);
            iGpffffb200 = 0;
        }
        return 1;
block_259:
    return 0;
}
#pragma pop
/* measured: opt_loop_invariants hoists the slash loop constant. */
#pragma push
#pragma opt_loop_invariants on

// FUN_00150970
u8 *FldResource_Create(char *arg0)
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
    resource = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(valid, 0xAB0, 0x40000);
    if (resource == NULL) {
        return resource;
    }
    chkmemAllocSiteTag(D_005EFC80, 0x462);
    work = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(valid, 0x12C, 0x40000);
    *(u8 **)(resource + 0xA44) = work;
    if (work == NULL) {
        jtbl_008873EC[0](resource);
        return NULL;
    }
    strcpy((char *)work, arg0);
    while (*arg0 != '\0') {
        arg0++;
    }
    for (; *arg0 != '/'; arg0--) {
    }
    if (arg0[1] == 'f') {
        if ((D_00754D88[(s8)arg0[2]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[3]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[4]] & 4) == 0) {
            valid = 0;
        }
        if (arg0[5] != '_') {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[6]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[7]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[8]] & 4) == 0) {
            valid = 0;
        }
    } else {
        valid = 0;
    }
    if (valid) {
        local.token[0] = arg0[2];
        local.token[1] = arg0[3];
        local.token[2] = arg0[4];
        local.token[3] = '\0';
        *(u16 *)(resource + 4) = (u16)atoi(local.token);
        local.token[0] = arg0[6];
        local.token[1] = arg0[7];
        local.token[2] = arg0[8];
        local.token[3] = '\0';
        *(u16 *)(resource + 6) = (u16)atoi(local.token);
    } else {
        *(s16 *)(resource + 4) = -1;
        *(s16 *)(resource + 6) = -1;
    }
    if (iGpffffb204 == 0) {
        func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0x4A5);
        *(s32 *)(*(u8 **)(resource + 0xA44) + 0x80) =
            func_00454a60(*(char **)(resource + 0xA44), 0);
    } else {
        *(s32 *)(*(u8 **)(resource + 0xA44) + 0x80) = 1;
    }
    return resource;
}
#pragma pop

// FUN_00150C80
s32 FldResource_IsFileLoaded(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x80);
    if (p == NULL) {
        return 1;
    }
    if (iGpffffb204 == 0) {
        return H_Cdvd_IsFileLoaded((s32)p) != 0;
    }
    return 1;
}

/* measured: 988B/992B, all emitted instructions match; 4B retail zero tail.
   The stream descriptors and complete chunk header are real helper storage.
   Keep resource snapshots on their retail side of the asynchronous callbacks. */
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

    data = func_00455f70(*(u8 **)(resource + 0xA44), &size);
    memory[0] = data;
    memory[1] = size;
    if (data != 0) {
        streamHandle = func_003e2f60(3, 1, &memory[0]);
        if (streamHandle != 0) {
            while (func_003df3c0(streamHandle, (s32 *)chunk) != 0) {
                switch (chunk[0]) {
                case 11:
                    if (*(s32 *)(*(u8 **)(resource + 0xA44) +
                                 *(s32 *)(*(u8 **)(resource + 0xA44) + 0x8C) * 4 + 0x90) == 0) {
                        chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    }
                    chunkMemory[1] = memory[1];
                    child = func_003e2f60(3, 1, &chunkMemory[0]);
                    destination = *(u8 **)(resource + 0xA44);
                    child = func_004667d0(1, 0, 0, 0, child, 0, 0, 0, 0, 0);
                    *(s32 *)(destination + *(s32 *)(destination + 0x8C) * 4 + 0x90) = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    *(s32 *)(*(u8 **)(resource + 0xA44) + 0x8C) =
                        *(s32 *)(*(u8 **)(resource + 0xA44) + 0x8C) + 1;
                    break;
                case 16:
                    chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    chunkMemory[1] = memory[1];
                    child = func_003e2f60(3, 1, &chunkMemory[0]);
                    destination = *(u8 **)(resource + 0xA44);
                    child = func_004667d0(2, 0, 0, 0, child, 0, 0, 0, 0, 0);
                    *(s32 *)(destination + *(s32 *)(destination + 0xA0) * 4 + 0xA4) = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    *(s32 *)(*(u8 **)(resource + 0xA44) + 0xA0) =
                        *(s32 *)(*(u8 **)(resource + 0xA44) + 0xA0) + 1;
                    break;
                case 35:
                    callbackHandle = func_003dc370((void *)streamHandle);
                    func_003ef260((const struct RwTexDictionary *)(u32)callbackHandle, K_Clump_AppendTextureName,
                                  *(u8 **)(resource + 0xA44) + 0x128);
                    func_003ef1b0(callbackHandle);
                    break;
                case 22:
                    chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    chunkMemory[1] = memory[1];
                    child = func_004667d0(8, 0, 0, 0, func_003e2f60(3, 1, &chunkMemory[0]), 0, 0, 0, 0, 0);
                    *(s32 *)(*(u8 **)(resource + 0xA44) + 0x84) = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    break;
                case 12:
                    chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    chunkMemory[1] = memory[1];
                    child = func_004667d0(0xB, 0, 0, 0, func_003e2f60(3, 1, &chunkMemory[0]), 0, 0, 0, 0, 0);
                    *(s32 *)(*(u8 **)(resource + 0xA44) + 0x124) = child;
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
            if (*(u8 **)(resource + 0xA44) != NULL) {
                H_Cdvd_Destroy(*(u8 **)(*(u8 **)(resource + 0xA44) + 0x80));
                jtbl_008873EC[0](*(u8 **)(resource + 0xA44));
            }
            if (resource != NULL) {
                jtbl_008873EC[0](resource);
            }
        }
    }
}

// FUN_001510C0
s32 FldResource_PollLoads(u8 *arg0)
{
    s32 sp6C;
    s32 sp68;
    s32 var_16;
    u32 var_20;
    s32 temp_18;
    u8 *temp_19;
    u8 *temp_20;
    u32 var_19;

    var_16 = 0;
    if (*(u8 **)(arg0 + 0xA44) == NULL) {
        return 1;
    }
    if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84) != 0) {
        if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x128) != 0) {
            kAssertFail((const char *)D_005EFC80, 0x56C);
        }
        temp_18 = (s32)func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84), &sp68, &sp6C);
        if (sp68 == 1) {
            func_003ef260((const struct RwTexDictionary *)(u32)temp_18, K_Clump_AppendTextureName, *(u8 **)(arg0 + 0xA44) + 0x128);
            func_003ef1b0(temp_18);
            *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84) = 0;
            if (sp6C != 0) {
                func_003e2e40(sp6C, 0);
            }
        } else {
            var_16 += 1;
        }
    }
    for (var_20 = 0; var_20 < *(u32 *)(*(u8 **)(arg0 + 0xA44) + 0x8C); var_20++) {
        if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_20 * 4 + 0x90) != 0) {
            temp_19 = func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_20 * 4 + 0x90), &sp68, &sp6C);
            if (sp68 == 1) {
                if (temp_19 == NULL) {
                    kAssertFail((const char *)D_005EFC80, 0x588);
                }
                if (K_Clump_GeometryHasMatUsrData(temp_19, D_005EFCE0) != 0) {
                    *(s32 *)(arg0 + 0x10) = (s32)temp_19;
                } else if (K_Clump_GeometryHasMatUsrData(temp_19, D_005EFD00) != 0) {
                    *(s32 *)(arg0 + 0x14) = (s32)temp_19;
                } else if (*(s32 *)(arg0 + 0xC) == 0) {
                    *(s32 *)(arg0 + 0xC) = (s32)temp_19;
                    func_003db550(temp_19, (void *)(u32)func_00457120());
                } else {
                    *(s32 *)(arg0 + 8) = (s32)temp_19;
                }
                *(s32 *)(*(u8 **)(arg0 + 0xA44) + var_20 * 4 + 0x90) = 0;
                *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) | 1;
                if (sp6C != 0) {
                    func_003e2e40(sp6C, 0);
                }
            } else {
                var_16 += 1;
            }
        }
    }
    for (var_19 = 0; var_19 < *(u32 *)(*(u8 **)(arg0 + 0xA44) + 0xA0); var_19++) {
        if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_19 * 4 + 0xA4) != 0) {
            temp_20 = func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_19 * 4 + 0xA4), &sp68, &sp6C);
            if (sp68 == 1) {
                if (temp_20 == NULL) {
                    kAssertFail((const char *)D_005EFC80, 0x5B4);
                }
                if (K_Clump_ClumpHasMatUsrData(temp_20, D_005EFCE0) != 0) {
                    *(s32 *)(arg0 + 0x10) = (s32)temp_20;
                } else if (K_Clump_ClumpHasMatUsrData(temp_20, D_005EFD00) != 0) {
                    *(s32 *)(arg0 + 0x14) = (s32)temp_20;
                } else if (!(*(s32 *)(arg0 + 0) & 1) && *(s32 *)(arg0 + 8) == 0) {
                    *(s32 *)(arg0 + 8) = (s32)temp_20;
                    *(void **)(arg0 + 0xC) = func_00462ae0(temp_20);
                } else {
                    *(s32 *)(arg0 + *(s32 *)(arg0 + 0x18) * 4 + 0x1C) = (s32)temp_20;
                    *(void **)(arg0 + *(s32 *)(arg0 + 0x18) * 4 + 0x9C) = func_00462ae0(temp_20);
                    *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x18) + 1;
                }
                *(s32 *)(*(u8 **)(arg0 + 0xA44) + var_19 * 4 + 0xA4) = 0;
                if (sp6C != 0) {
                    func_003e2e40(sp6C, 0);
                }
            } else {
                var_16 += 1;
            }
        }
    }
    if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124) != 0) {
        *(s32 *)(arg0 + 0xA20) = (s32)func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124), &sp68, &sp6C);
        if (sp68 == 1) {
            if (sp6C != 0) {
                func_003e2e40(sp6C, 0);
            }
            if (*(s32 *)(arg0 + 0xA20) == 0) {
                kAssertFail((const char *)D_005EFC80, 0x5D9);
            }
            *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124) = 0;
        } else {
            var_16 += 1;
        }
    }
    if (var_16 == 0) {
        if (*(s32 *)(arg0 + 8) == 0) {
            *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) | 0x10000000;
            *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 0xC);
        }
        if (!(*(s32 *)(arg0 + 0) & 1) && *(s32 *)(arg0 + 0x18) == 0) {
            *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) | 0x10000000;
        }
        if (iGpffffb204 == 0) {
            H_Cdvd_Destroy(*(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x80));
        }
        *(s32 *)(arg0 + 0xA24) = 0x3F800000;
        *(s32 *)(arg0 + 0xA28) = 0x3F800000;
        *(s32 *)(arg0 + 0xA2C) = 0x3F800000;
        return 1;
    }
    return 0;
}

// FUN_00151580
s32 FldResource_FindFrameForId(u8 *arg0, s32 arg1, s32 *arg2)
{
    KClumpIntPropertyResult spA8;
    KClumpIntPropertyResult spA0;
    KClumpIntPropertyResult sp98;
    s32 var_17;
    s32 var_16;
    u8 *temp_21;
    s32 var_22;
    s32 temp_23;

    var_22 = 0;
    for (var_17 = 0; var_17 < *(u32 *)(arg0 + 0x18); var_17++) {
        temp_21 = arg0 + var_17 * 4;
        temp_23 = K_Clump_CountIntUsrData(*(void **)(temp_21 + 0x1C), (const char *)D_005EFD20);
        for (var_16 = 0; var_16 < temp_23; var_16++) {
            K_Clump_GetIntUsrDataAt(&spA0, *(void **)(temp_21 + 0x1C), (const char *)D_005EFD40, var_16);
            if (spA0.value == 0) {
                kAssertFail((const char *)D_005EFC80, 0x622);
            }
            K_Clump_GetIntUsrDataAt(&spA8, *(void **)(temp_21 + 0x1C), (const char *)D_005EFD20, var_16);
            K_Clump_GetIntUsrDataAt(&sp98, *(void **)(temp_21 + 0x1C), (const char *)D_005EFD60, var_16);
            if (sp98.value != 0) {
                *arg2 = 1;
            } else {
                *arg2 = 0;
            }
            if (spA8.value != 1 && arg1 == spA0.value) {
                var_22 = (s32)spA8.frame;
                goto out;
            }
        }
    }
out:
    return var_22;
}

// FUN_00151710
void FldResource_RequestEntryLoads(u8 *arg0)
{
    s32 temp_16;
    u8 *temp_17;
    u32 var_19;
    s32 var_18;
    u32 sp20C;
    s32 sp208;
    KClumpIntPropertyResult sp200;
    KClumpIntPropertyResult sp1F8;
    KClumpIntPropertyResult sp1F0;
    KClumpIntPropertyResult sp1E8;
    KClumpIntPropertyResult sp1E0;
    char sp1A0[0x40];
    char sp160[0x40];
    char sp120[0x40];
    char spE0[0x40];
    char spA0[0x40];
    char sp60[0x40];
    s32 r;

    for (var_19 = 0; var_19 < *(u32 *)(arg0 + 0x18); var_19++) {
        temp_17 = arg0 + var_19 * 4;
        temp_16 = K_Clump_CountIntUsrData(*(void **)(temp_17 + 0x1C), (const char *)D_005EFD20);
        for (var_18 = 0; var_18 < temp_16; var_18++) {
            K_Clump_GetIntUsrDataAt(&sp1F8, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD80, var_18);
            if (sp1F8.value != 0) {
                K_Clump_GetIntUsrDataAt(&sp1E8, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD40, var_18);
                if (sp1E8.value == 0) {
                    kAssertFail((const char *)D_005EFC80, 0x65A);
                }
                *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x124) = (u16)sp1E8.value;
                K_Clump_GetIntUsrDataAt(&sp1E0, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD60, var_18);
                if (sp1E0.value != 0) {
                    *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x122) = 2;
                }
                K_Clump_GetIntUsrDataAt(&sp200, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD20, var_18);
                *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x120) = (u16)sp200.value;
                if (sp200.value == 0) {
                    if (iGpffffb204 == 0) {
                        strcpy(sp1A0, D_005EFD98);
                        sprintf(sp160, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        strcat(sp1A0, sp160);
                        sprintf(sp160, D_005EFDA8, sp1F8.value);
                        strcat(sp1A0, sp160);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x12C) = (s32)mdlCreateModelObjectFromData(4, (u16)sp1F8.value, sp1A0, 0);
                    } else {
                        strcpy(sp1A0, D_005EFDB8);
                        sprintf(sp160, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        strcat(sp1A0, sp160);
                        sprintf(sp160, D_005EFDA8, sp1F8.value);
                        strcat(sp1A0, sp160);
                        r = func_00455f70(sp1A0, (s32 *)&sp20C);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x12C) = (s32)mdlCreateModelObjectFromMemory(4, (u16)sp1F8.value, (void *)r, sp20C, 0);
                    }
                } else if (sp200.value == 1) {
                    if (iGpffffb204 == 0) {
                        strcpy(sp120, D_005EFDC8);
                        sprintf(spE0, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        strcat(sp120, spE0);
                        sprintf(spE0, D_005EFDD8, sp1F8.value);
                        strcat(sp120, spE0);
                        func_00440b68((const char *)&iGpffff9df0, (const char *)D_005EFC80, 0x6A1);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x134) = func_00454a60(sp120, 0);
                        if (*(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x134) == 0) {
                            kAssertFail((const char *)D_005EFC80, 0x6A2);
                        }
                    } else {
                        strcpy(sp120, D_005EFDE8);
                        sprintf(spE0, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        strcat(sp120, spE0);
                        sprintf(spE0, D_005EFDD8, sp1F8.value);
                        strcat(sp120, spE0);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x134) = func_00455f70(sp120, &sp208);
                    }
                } else if (sp200.value == 2) {
                    strcpy(spA0, D_005EFE00);
                    sprintf(sp60, D_005EFDA8, sp1F8.value);
                    strcat(spA0, sp60);
                    *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x12C) = (s32)mdlCreateModelObjectFromData(4, (u16)(sp1F8.value + 0x3E8), spA0, 0);
                }
                K_Clump_GetIntUsrDataAt(&sp1F0, *(void **)(temp_17 + 0x1C), (const char *)D_005EFE10, var_18);
                if (sp200.value == 0) {
                    *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x122) |= (u16)sp1F0.value;
                }
                *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x128) = (s32)sp200.frame;
                *(u32 *)(arg0 + 0x11C) = *(u32 *)(arg0 + 0x11C) + 1;
            }
        }
    }
}

// FUN_00151C80
s32 FldResource_TryInstallEntries(u8 *arg0)
{
    u32 i;
    u32 j;

    for (i = 0; i < *(u32 *)(arg0 + 0x11C); i++) {
        if (*(u16 *)(arg0 + i * 0x18 + 0x120) == 0 || *(u16 *)(arg0 + i * 0x18 + 0x120) == 2) {
            if (*(u32 *)(arg0 + i * 0x18 + 0x12C) == 0) {
                kAssertFail((const char *)D_005EFC80, 0x6E4);
            }
            if (mdlPrepareModel(*(u32 *)(arg0 + i * 0x18 + 0x12C)) == 0) {
                return 0;
            }
        } else if (*(u16 *)(arg0 + i * 0x18 + 0x120) == 1) {
            if (iGpffffb204 == 0 && *(u8 **)(arg0 + i * 0x18 + 0x134) != NULL && H_Cdvd_IsFileLoaded((s32)*(u8 **)(arg0 + i * 0x18 + 0x134)) == 0) {
                return 0;
            }
        }
    }
    for (j = 0; j < *(u32 *)(arg0 + 0x11C); j++) {
        if (*(u16 *)(arg0 + j * 0x18 + 0x120) == 0 || *(u16 *)(arg0 + j * 0x18 + 0x120) == 2) {
            mdlApplyModelMatrix(*(void **)(arg0 + j * 0x18 + 0x12C), func_003e9700(*(RwFrame **)(arg0 + j * 0x18 + 0x128)), 0);
            if (*(u16 *)(arg0 + j * 0x18 + 0x122) & 1) {
                mdlSetLayerWeight(*(void **)(arg0 + j * 0x18 + 0x12C), 0, 0.0f);
            } else {
                mdlDispatchAnimIfPresent(*(void **)(arg0 + j * 0x18 + 0x12C), 0, 0, 8, 1);
            }
        } else if (*(u16 *)(arg0 + j * 0x18 + 0x120) == 1) {
            if (iGpffffb204 == 0) {
                if (*(u8 **)(arg0 + j * 0x18 + 0x134) != NULL) {
                    *(s32 *)(arg0 + j * 0x18 + 0x130) = func_004b1130(*(u32 *)(*(u8 **)(arg0 + j * 0x18 + 0x134) + 0x110));
                    func_004b1250(*(void **)(arg0 + j * 0x18 + 0x130), (f32 *)((u8 *)func_003e9700(*(RwFrame **)(arg0 + j * 0x18 + 0x128)) + 0x30));
                    H_Cdvd_Destroy(*(u8 **)(arg0 + j * 0x18 + 0x134));
                    *(u8 **)(arg0 + j * 0x18 + 0x134) = NULL;
                }
            } else if (*(u8 **)(arg0 + j * 0x18 + 0x134) != NULL) {
                *(s32 *)(arg0 + j * 0x18 + 0x130) = func_004b1130((s32)*(u8 **)(arg0 + j * 0x18 + 0x134));
                func_004b1250(*(void **)(arg0 + j * 0x18 + 0x130), (f32 *)((u8 *)func_003e9700(*(RwFrame **)(arg0 + j * 0x18 + 0x128)) + 0x30));
                *(u8 **)(arg0 + j * 0x18 + 0x134) = NULL;
            }
        }
    }
    if (*(u8 **)(arg0 + 0xA44) != NULL) {
        if (*(s16 *)(arg0 + 4) >= 0x28 && *(s16 *)(arg0 + 4) < 0x31) {
            if (*(u32 *)(*(u8 **)(arg0 + 0xA44) + 0x128) != 0) {
                *(s32 *)(iGpffff9db0 + 0x8C) = *(u32 *)(*(u8 **)(arg0 + 0xA44) + 0x128);
            }
        } else {
            K_Clump_FreeTextureNameList(*(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x128));
        }
        jtbl_008873EC[0](*(u8 **)(arg0 + 0xA44));
        *(u8 **)(arg0 + 0xA44) = NULL;
    }
    return 1;
}

// FUN_00151F80
void FldResource_Destroy(u8 *arg0)
{
    s32 temp_4;
    u32 var_16;
    u32 var_18;
    u8 *temp_16;
    u8 *temp_4_8;

    if (*(u32 *)arg0 & 1) {
        temp_4 = *(s32 *)(arg0 + 8);
        if (temp_4 != 0 && temp_4 != *(s32 *)(arg0 + 0xC)) {
            func_003c9d40((void *)temp_4);
        }
        if (*(s32 *)(arg0 + 0xC) != 0) {
            func_003c9d40((void *)*(s32 *)(arg0 + 0xC));
        }
        if (*(s32 *)(arg0 + 0x10) != 0) {
            func_003c9d40((void *)*(s32 *)(arg0 + 0x10));
        }
        if (*(s32 *)(arg0 + 0x14) != 0) {
            func_003c9d40((void *)*(s32 *)(arg0 + 0x14));
        }
    } else {
        func_00462bf0((void *)*(s32 *)(arg0 + 0xC));
        if (*(s32 *)(arg0 + 8) != 0) {
            func_003c0700((void *)*(s32 *)(arg0 + 8));
        }
        if (*(s32 *)(arg0 + 0x10) != 0) {
            func_003c0700((void *)*(s32 *)(arg0 + 0x10));
        }
        if (*(s32 *)(arg0 + 0x14) != 0) {
            func_003c0700((void *)*(s32 *)(arg0 + 0x14));
        }
    }
    for (var_18 = 0; var_18 < *(u32 *)(arg0 + 0x18); var_18++) {
        temp_16 = arg0 + var_18 * 4;
        func_00462bf0((void *)*(s32 *)(temp_16 + 0x9C));
        func_003c0700((void *)*(s32 *)(temp_16 + 0x1C));
    }
    for (var_16 = 0; var_16 < *(u32 *)(arg0 + 0x11C); var_16++) {
        temp_4_8 = arg0 + var_16 * 0x18;
        if (*(u16 *)(temp_4_8 + 0x120) == 0 || *(u16 *)(temp_4_8 + 0x120) == 2) {
            mdlDestroyModelObject(*(s32 *)(temp_4_8 + 0x12C));
        } else if (*(u16 *)(temp_4_8 + 0x120) == 1) {
            func_004b1150(*(s32 *)(temp_4_8 + 0x130));
        }
    }
    if (*(s32 *)(arg0 + 0xA20) != 0) {
        func_003bbb60((void *)*(s32 *)(arg0 + 0xA20));
    }
    if (*(s32 *)(arg0 + 0xA40) != 0) {
        jtbl_008873EC[0]((void *)*(s32 *)(arg0 + 0xA40));
    }
    jtbl_008873EC[0](arg0);
}

/* The draw-state table has two address lifetimes: one at the initial call,
 * and one shared by the final render-state sequence. The context is passed
 * in the callback's second argument. Saved Vec4 values are light colors. */
// FUN_00152170
void FldResource_BeginDrawState(u8 *arg0, u8 *arg1)
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

    raster = (void *)(u32)func_00457120();
    gs = (u8 *)D_00887300;
    (*(RwBool (**)(RwRenderState, void *))gs)(0x14, (void *)2);
    func_003e8110((u32)raster);
    cam = (u8 *)(u32)K_Clump_GetLightA();
    *(Vec4 *)(arg1 + 0xA50) = *(Vec4 *)(cam + 0x18);
    cam = (u8 *)(u32)K_Clump_GetLightB();
    *(Vec4 *)(arg1 + 0xA60) = *(Vec4 *)(cam + 0x18);
    src = (CopyPair *)(*(u8 **)((u8 *)(u32)K_Clump_GetLightB() + 4) + 0x10);
    dst = (CopyPair *)(arg1 + 0xA70);
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
        func_003e9cb0(*(RwFrame **)((u8 *)(u32)K_Clump_GetLightB() + 4),
                      (const RwMatrix *)resrcMngGetTransform(), rwCOMBINEREPLACE);
    }
    *(s8 *)((u8 *)(u32)K_Clump_GetLightB() + 2) = 3;
    K_Clump_GetLightB();
    if (*(s32 *)arg1 & 1) {
        func_003cbc60(K_Clump_GetWorld(), (u8 *)raster);
        flags = *(s32 *)arg1;
        if (flags & 0x80000000) {
            func_003cbc10(*(RpWorld **)(arg1 + 0xC), (RwCamera *)raster);
        } else if (flags & 0x40000000) {
            light = *(s32 *)(arg1 + 0x10);
            if (light != 0) {
                func_003cbc10((RpWorld *)(u32)light, (RwCamera *)raster);
            }
        } else if (flags & 0x20000000) {
            light = *(s32 *)(arg1 + 0x14);
            if (light != 0) {
                func_003cbc10((RpWorld *)(u32)light, (RwCamera *)raster);
            }
        } else {
            func_003cbc10(*(RpWorld **)(arg1 + 8), (RwCamera *)raster);
        }
        func_003cbf30((RpWorld *)(u32)K_Clump_GetWorld(), (RpLight *)(u32)K_Clump_GetLightA());
        func_003cbf30((RpWorld *)(u32)K_Clump_GetWorld(), (RpLight *)(u32)K_Clump_GetLightB());
        flags = *(s32 *)arg1;
        if (flags & 0x80000000) {
            func_003cbe80(*(RpWorld **)(arg1 + 0xC), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbe80(*(RpWorld **)(arg1 + 0xC), (RpLight *)(u32)K_Clump_GetLightB());
        } else if (flags & 0x40000000) {
            func_003cbe80(*(RpWorld **)(arg1 + 0x10), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbe80(*(RpWorld **)(arg1 + 0x10), (RpLight *)(u32)K_Clump_GetLightB());
        } else if ((flags & 0x20000000) && (*(s32 *)(arg1 + 0x14) != 0)) {
            func_003cbe80(*(RpWorld **)(arg1 + 0x14), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbe80(*(RpWorld **)(arg1 + 0x14), (RpLight *)(u32)K_Clump_GetLightB());
        } else {
            func_003cbe80(*(RpWorld **)(arg1 + 8), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbe80(*(RpWorld **)(arg1 + 8), (RpLight *)(u32)K_Clump_GetLightB());
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

// FUN_00152630
void FldResource_EndDrawState(u8 *arg0, u8 *arg1)
{
    u8 *temp_2;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_18_3;

    temp_2 = (void *)(u32)func_00457120();
    func_003e8110((u32)temp_2);
    if (*(u32 *)arg1 & 1) {
        if (*(u32 *)arg1 & 0x80000000) {
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0xC), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0xC), (RpLight *)(u32)K_Clump_GetLightB());
        } else if (*(u32 *)arg1 & 0x40000000) {
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0x10), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0x10), (RpLight *)(u32)K_Clump_GetLightB());
        } else if ((*(u32 *)arg1 & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0x14), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0x14), (RpLight *)(u32)K_Clump_GetLightB());
        } else {
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 8), (RpLight *)(u32)K_Clump_GetLightA());
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 8), (RpLight *)(u32)K_Clump_GetLightB());
        }
        temp_18 = (void *)(u32)K_Clump_GetWorld();
        func_003cbe80((RpWorld *)temp_18, (RpLight *)(u32)K_Clump_GetLightA());
        temp_18_2 = (void *)(u32)K_Clump_GetWorld();
        func_003cbe80((RpWorld *)temp_18_2, (RpLight *)(u32)K_Clump_GetLightB());
        if (*(u32 *)arg1 & 0x80000000) {
            func_003cbc60(*(s32 *)(arg1 + 0xC), (u8 *)temp_2);
        } else if (*(u32 *)arg1 & 0x40000000) {
            func_003cbc60(*(s32 *)(arg1 + 0x10), (u8 *)temp_2);
        } else if ((*(u32 *)arg1 & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
            func_003cbc60(*(s32 *)(arg1 + 0x14), (u8 *)temp_2);
        } else {
            func_003cbc60(*(s32 *)(arg1 + 8), (u8 *)temp_2);
        }
        func_003cbc10((RpWorld *)(u32)K_Clump_GetWorld(), (RwCamera *)temp_2);
    } else {
        temp_18_3 = (void *)(u32)K_Clump_GetWorld();
        func_003cbe80((RpWorld *)temp_18_3, (RpLight *)(u32)K_Clump_GetLightC());
    }
    func_003c38b0((RpLight *)(u32)K_Clump_GetLightA(), (const RwRGBAReal *)(arg1 + 0xA50));
    func_003c38b0((RpLight *)(u32)K_Clump_GetLightB(), (const RwRGBAReal *)(arg1 + 0xA60));
    func_003e9cb0((RwFrame *)(u32)*(s32 *)((u8 *)(u32)K_Clump_GetLightB() + 4),
                  (const RwMatrix *)(arg1 + 0xA70), rwCOMBINEREPLACE);
    *(s8 *)((u8 *)(u32)K_Clump_GetLightB() + 2) = 3;
    K_Clump_GetLightB();
    func_003e8120((u32)temp_2);
}

// FUN_00152930
void FldResource_QueueDrawCallbacks(u8 *arg0, u8 *arg1)
{
    u8 *var_2;
    u8 *var_6;
    u8 *p2;
    s32 temp_3;
    u32 flags;
    u32 i;

    var_6 = NULL;
    flags = *(u32 *)arg1;
    if (flags & 1) {
        temp_3 = *(s32 *)(arg1 + 8);
        if (temp_3 != 0) {
            if (flags & 0x80000000) {
                var_2 = func_00461290(arg0, *(s32 *)(arg1 + 0xC));
            } else if (flags & 0x40000000) {
                var_2 = func_00461290(arg0, *(s32 *)(arg1 + 0x10));
            } else if ((flags & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
                var_2 = func_00461290(arg0, *(s32 *)(arg1 + 0x14));
            } else {
                var_2 = func_00461290(arg0, temp_3);
            }
            *(void (**)(void))(var_2 + 8) = (void (*)(void))FldResource_BeginDrawState;
            *(u8 **)(var_2 + 0x10) = arg1;
            *(void (**)(void))(var_2 + 0xC) = (void (*)(void))FldResource_EndDrawState;
            *(u8 **)(var_2 + 0x14) = arg1;
        }
    } else {
        if (flags & 0x80000000) {
            if (*(s32 *)(arg1 + 0xC) != 0) {
                var_6 = func_00460e80(arg0, *(s32 *)(arg1 + 0xC));
            } else {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 8));
            }
        } else if (flags & 0x40000000) {
            var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x10));
        } else if (flags & 0x20000000) {
            if (*(s32 *)(arg1 + 0x14) != 0) {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x14));
            }
        }
        if (var_6 != NULL) {
            *(void (**)(void))(var_6 + 8) = (void (*)(void))FldResource_BeginDrawState;
            *(u8 **)(var_6 + 0x10) = arg1;
            *(void (**)(void))(var_6 + 0xC) = (void (*)(void))FldResource_EndDrawState;
            *(u8 **)(var_6 + 0x14) = arg1;
        }
    }
    if (!(*(u32 *)arg1 & 0xC0000000)) {
        for (i = 0; i < *(u32 *)(arg1 + 0x18); i++) {
            if (*(s32 *)(arg1 + 0x9C + i * 4) != 0) {
                p2 = func_00460e80(arg0, *(s32 *)(arg1 + 0x9C + i * 4));
            } else {
                p2 = func_00461180(arg0, *(s32 *)(arg1 + 0x1C + i * 4));
            }
            if (p2 != NULL && i == 0) {
                *(void (**)(void))(p2 + 8) = (void (*)(void))FldResource_BeginDrawState;
                *(u8 **)(p2 + 0x10) = arg1;
            }
            if (p2 != NULL && i == *(u32 *)(arg1 + 0x18) - 1) {
                *(void (**)(void))(p2 + 0xC) = (void (*)(void))FldResource_EndDrawState;
                *(u8 **)(p2 + 0x14) = arg1;
            }
        }
    }
}

// FUN_00152BB0
void FldResource_QueueDrawCallbacksPrimary(u8 *arg0, u8 *arg1)
{
    u8 *var_6;
    u8 *temp_2;
    u32 i;

    var_6 = NULL;
    if (!(*(u32 *)arg1 & 1)) {
        if ((*(u32 *)arg1 & 0x80000000) && *(u8 **)(arg1 + 0xC) != NULL) {
            var_6 = func_00460f80(arg0, *(s32 *)(arg1 + 0xC));
        }
        if (var_6 != NULL) {
            *(void (**)(void))(var_6 + 8) = (void (*)(void))FldResource_BeginDrawState;
            *(u8 **)(var_6 + 0x10) = arg1;
            *(void (**)(void))(var_6 + 0xC) = (void (*)(void))FldResource_EndDrawState;
            *(u8 **)(var_6 + 0x14) = arg1;
        }
    }
    if (!(*(u32 *)arg1 & 0xC0000000)) {
        for (i = 0; i < *(u32 *)(arg1 + 0x18); i++) {
            if (*(u8 **)(arg1 + 0x9C + i * 4) != NULL) {
                temp_2 = func_00460f80(arg0, *(s32 *)(arg1 + 0x9C + i * 4));
                if (temp_2 != NULL && i == 0) {
                    *(void (**)(void))(temp_2 + 8) = (void (*)(void))FldResource_BeginDrawState;
                    *(u8 **)(temp_2 + 0x10) = arg1;
                    *(void (**)(void))(temp_2 + 0xC) = (void (*)(void))FldResource_EndDrawState;
                    *(u8 **)(temp_2 + 0x14) = arg1;
                }
            }
        }
    }
}

// FUN_00152CD0
void FldResource_QueueDrawCallbacksSecondary(u8 *arg0, u8 *arg1)
{
    u8 *var_6;
    u8 *temp_2;
    u32 i;

    var_6 = NULL;
    if (!(*(u32 *)arg1 & 1)) {
        if ((*(u32 *)arg1 & 0x80000000)) {
            if (*(s32 *)(arg1 + 0xC) != 0) {
                var_6 = func_00461080(arg0, *(s32 *)(arg1 + 0xC));
            }
        } else if ((*(u32 *)arg1 & 0x40000000)) {
            if (*(s32 *)(arg1 + 0x10) != 0) {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x10));
            }
        } else if ((*(u32 *)arg1 & 0x20000000)) {
            if (*(s32 *)(arg1 + 0x14) != 0) {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x14));
            }
        }
        if (var_6 != NULL) {
            *(void (**)(void))(var_6 + 8) = (void (*)(void))FldResource_BeginDrawState;
            *(u8 **)(var_6 + 0x10) = arg1;
            *(void (**)(void))(var_6 + 0xC) = (void (*)(void))FldResource_EndDrawState;
            *(u8 **)(var_6 + 0x14) = arg1;
        }
    }
    if (!(*(u32 *)arg1 & 0xC0000000)) {
        for (i = 0; i < *(u32 *)(arg1 + 0x18); i++) {
            if (*(u8 **)(arg1 + 0x9C + i * 4) != NULL) {
                temp_2 = func_00461080(arg0, *(s32 *)(arg1 + 0x9C + i * 4));
                if (temp_2 != NULL && i == 0) {
                    *(void (**)(void))(temp_2 + 8) = (void (*)(void))FldResource_BeginDrawState;
                    *(u8 **)(temp_2 + 0x10) = arg1;
                    *(void (**)(void))(temp_2 + 0xC) = (void (*)(void))FldResource_EndDrawState;
                    *(u8 **)(temp_2 + 0x14) = arg1;
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
// FUN_00152E50
void FldResource_TransformFrames(u8 *arg0, u8 *arg1, f32 fparg0)
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

    if (!(*(s32 *)arg0 & 1)) {
        res = *(u8 **)(arg0 + 8);
        if (res != NULL) {
            frame = *(u8 **)(res + 4);
            mtx = (u8 *)func_003e9700((RwFrame *)frame);
            stk.v0 = *(Vec3 *)(mtx + 0x30);
            stk.v0.x += *(f32 *)(arg1 + 0);
            stk.v0.y += *(f32 *)(arg1 + 4);
            stk.v0.z += *(f32 *)(arg1 + 8);
            *(Vec3 *)(frame + 0x40) = stk.v0;
            RwEngineGetMatrixTolerances(&stk.t0);
            RwMatrixOptimize((RwMatrix *)(frame + 0x10), &stk.t0);
            func_003e9680((RwFrame *)frame);
        }
        res2 = *(u8 **)(arg0 + 0x10);
        if (res2 != NULL) {
            frame2 = *(u8 **)(res2 + 4);
            mtx = (u8 *)func_003e9700((RwFrame *)frame2);
            stk.v1 = *(Vec3 *)(mtx + 0x30);
            stk.v1.x += *(f32 *)(arg1 + 0);
            stk.v1.y += *(f32 *)(arg1 + 4);
            stk.v1.z += *(f32 *)(arg1 + 8);
            *(Vec3 *)(frame2 + 0x40) = stk.v1;
            RwEngineGetMatrixTolerances(&stk.t1);
            RwMatrixOptimize((RwMatrix *)(frame2 + 0x10), &stk.t1);
            func_003e9680((RwFrame *)frame2);
        }
        res3 = *(u8 **)(arg0 + 0x14);
        if (res3 != NULL) {
            frame3 = *(u8 **)(res3 + 4);
            mtx = (u8 *)func_003e9700((RwFrame *)frame3);
            stk.v2 = *(Vec3 *)(mtx + 0x30);
            stk.v2.x += *(f32 *)(arg1 + 0);
            stk.v2.y += *(f32 *)(arg1 + 4);
            stk.v2.z += *(f32 *)(arg1 + 8);
            *(Vec3 *)(frame3 + 0x40) = stk.v2;
            RwEngineGetMatrixTolerances(&stk.t2);
            RwMatrixOptimize((RwMatrix *)(frame3 + 0x10), &stk.t2);
            func_003e9680((RwFrame *)frame3);
        }
    }
    i = 0;
    while (i < *(u32 *)(arg0 + 0x18)) {
        res4 = *(u8 **)(arg0 + i * 4 + 0x1C);
        if (res4 != NULL) {
            frame4 = *(u8 **)(res4 + 4);
            mtx = (u8 *)func_003e9700((RwFrame *)frame4);
            stk.v3 = *(Vec3 *)(mtx + 0x30);
            stk.v3.x += *(f32 *)(arg1 + 0);
            stk.v3.y += *(f32 *)(arg1 + 4);
            stk.v3.z += *(f32 *)(arg1 + 8);
            *(Vec3 *)(frame4 + 0x40) = stk.v3;
            RwEngineGetMatrixTolerances(&stk.t3);
            RwMatrixOptimize((RwMatrix *)(frame4 + 0x10), &stk.t3);
            func_003e9680((RwFrame *)frame4);
        }
        i += 1;
    }
    j = 0;
    while (j < *(u32 *)(arg0 + 0x11C)) {
        kind = *(u16 *)(arg0 + j * 0x18 + 0x120);
        if (kind == 0 || kind == 2) {
            mdlTranslateMatrix(*(RwMatrix **)(arg0 + j * 0x18 + 0x12C), (const Vec3 *)arg1, 2);
        } else if (kind == 1) {
            {
                s64 tmp_xy = D_005EFE28[0];
                f32 tmp_z = D_005EFE30[0];
                stk.axis.bits.xy = tmp_xy;
                stk.axis.bits.z = tmp_z;
            }
            mtx2 = (u8 *)func_003e0f80();
            *(s32 *)(mtx2 + 0x28) = 0x3F800000;
            *(s32 *)(mtx2 + 0x14) = 0x3F800000;
            *(s32 *)(mtx2 + 0) = 0x3F800000;
            *(s32 *)(mtx2 + 0x10) = 0;
            *(s32 *)(mtx2 + 8) = 0;
            *(s32 *)(mtx2 + 4) = 0;
            *(s32 *)(mtx2 + 0x24) = 0;
            *(s32 *)(mtx2 + 0x20) = 0;
            *(s32 *)(mtx2 + 0x18) = 0;
            *(s32 *)(mtx2 + 0x38) = 0;
            *(s32 *)(mtx2 + 0x34) = 0;
            *(s32 *)(mtx2 + 0x30) = 0;
            *(s32 *)(mtx2 + 0xC) |= 0x20003;
            RwMatrixRotate((RwMatrix *)mtx2, &stk.axis.vector, fparg0, rwCOMBINEPOSTCONCAT);
            {
                u32 k = j;
                u8 *base = arg0 + k * 0x18;
                mtx = (u8 *)func_003e9700(*(RwFrame **)(base + 0x128));
                stk.trans = *(Vec3 *)(mtx + 0x30);
                func_003e42a0(&stk.trans, &stk.trans, (const RwMatrix *)mtx2);
                stk.trans.x += *(f32 *)(arg1 + 0);
                stk.trans.y += *(f32 *)(arg1 + 4);
                stk.trans.z += *(f32 *)(arg1 + 8);
                func_004b1250(*(void **)(base + 0x130), (f32 *)&stk.trans);
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
    copy_s64 = (src).sp40; \
    copy_f32 = (src).sp48; \
    (dst).sp40 = copy_s64; \
    (dst).sp48 = copy_f32; \
} while (0)
// FUN_00153300
void FldResource_AdvanceAnimations(s8 *arg0, f32 fparg0)
{
    extern void func_003e9d50(s32 a0, void *a1, f32 f12, s32 a3);
    void *ptr;
    struct {
        s64 sp40;
        f32 sp48;
    } sp;
    u16 temp_4;
    u32 var_16;
    u32 var_16_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_5;

    ptr = &sp.sp40;
    COPY_SCALAR_PAIR(sp, *(typeof(sp) *)D_005EFE38);
    if (!(*(u32 *)arg0 & 1)) {
        temp_3 = *(u8 **)(arg0 + 8);
        if (temp_3 != NULL) {
            func_003e9d50(*(s32 *)(temp_3 + 4), ptr, fparg0, 2);
        }
        temp_3_2 = *(u8 **)(arg0 + 0x10);
        if (temp_3_2 != NULL) {
            func_003e9d50(*(s32 *)(temp_3_2 + 4), &sp.sp40, fparg0, 2);
        }
        temp_3_3 = *(u8 **)(arg0 + 0x14);
        if (temp_3_3 != NULL) {
            func_003e9d50(*(s32 *)(temp_3_3 + 4), &sp.sp40, fparg0, 2);
        }
    }
    var_16 = 0;
    goto loop_test_11;
loop_body_11:
    temp_3_4 = *(u8 **)(arg0 + var_16 * 4 + 0x1C);
    if (temp_3_4 != NULL) {
        func_003e9d50(*(s32 *)(temp_3_4 + 4), &sp.sp40, fparg0, 2);
    }
    var_16 += 1;
loop_test_11:
    if (var_16 < *(u32 *)(arg0 + 0x18)) {
        goto loop_body_11;
    }
    var_16_2 = 0;
    goto loop_test_19;
loop_body_19:
    temp_5 = (u8 *)arg0 + var_16_2 * 0x18;
    temp_4 = *(u16 *)(temp_5 + 0x120);
    if (temp_4 == 0) {
        goto switch_body_a;
    }
    if (temp_4 != 2) {
        goto switch_case_1_test;
    }
switch_body_a:
    mdlRotateMatrix((void *)(*(s32 *)(temp_5 + 0x12C)), &sp.sp40, fparg0, 2);
    goto switch_end;
switch_case_1_test:
    if (temp_4 != 1) {
        goto switch_end;
    }
    func_004b1290(*(s32 *)(temp_5 + 0x130), 0.0f, fparg0, 0.0f);
switch_end:
    ;
    var_16_2 += 1;
loop_test_19:
    if (var_16_2 < *(u32 *)(arg0 + 0x11C)) {
        goto loop_body_19;
    }
}
/* measured: restore propagation after FldResource_AdvanceAnimations. */
#pragma pop

typedef struct {
    u16 type;
    u16 flags;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} k_fldSubEntry;

typedef struct {
    u32 flags;
    s16 field_04;
    s16 field_06;
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    u32 count1;
    s32 arr1[32];
    s32 arr2[32];
    u32 count2;
    k_fldSubEntry entries[96];
    s32 field_a20;
    Vec3 scale;
} k_fldResource;

extern void FldResource_TransformFrames(u8 *arg0, u8 *arg1, f32 arg2);

/* measured: MWCCPS2 b210 -O2, 792B/window 800B, 17 relocations,
 * eight zero alignment bytes. Ghidra identifies the unsigned angle
 * conversion; IDA identifies the three-pair copy of each 24-byte entry.
 * The arrays end at the measured count/scale fields, not at the allocation
 * boundary: the original allocation remains 0xAB0 bytes. */
// FUN_001534A0
k_fldResource *FldResource_CloneRotated(k_fldResource *src, void *arg1, u32 arg2)
{
    k_fldResource *dst;
    f32 temp_f20;
    u32 i;
    u32 j;
    u8 *p_dst;

    temp_f20 = 90.0f * (f32)arg2;
    if (src->flags & 1) {
        return NULL;
    }
    chkmemAllocSiteTag(D_005EFC80, 0xA2A);
    dst = (k_fldResource *)D_008873F4[0](1, 0xAB0, 0x40000);
    dst->flags = src->flags | 2;
    dst->field_04 = src->field_04;
    dst->field_06 = src->field_06;
    if (src->field_08 != 0) {
        dst->field_08 = func_003c0520(src->field_08);
        dst->field_0c = (s32)func_00462ae0((void *)dst->field_08);
    }
    if (src->field_10 != 0) {
        dst->field_10 = func_003c0520(src->field_10);
    }
    if (src->field_14 != 0) {
        dst->field_14 = func_003c0520(src->field_14);
    }
    dst->count1 = src->count1;
    for (i = 0; i < src->count1; i++) {
        s32 arg = *(s32 *)((u8 *)src + i * 4 + 28);
        if (arg != 0) {
            s32 *s1;
            p_dst = (u8 *)dst + i * 4;
            s1 = (s32 *)(p_dst + 28);
            *s1 = func_003c0520(arg);
            *(s32 *)(p_dst + 156) = (s32)func_00462ae0((void *)*s1);
        }
    }
    dst->count2 = src->count2;
    for (j = 0; j < src->count2; j++) {
        u8 *src_base = (u8 *)src + (s32)j * 24;
        k_fldSubEntry *a3 = (k_fldSubEntry *)(src_base + 288);
        p_dst = (u8 *)dst + (s32)j * 24;
        *(k_fldSubEntry *)(p_dst + 288) = *a3;

        if (a3->type == 0 || a3->type == 2) {
            u8 *s1 = (u8 *)src + j * 24;
            s32 *s0 = &dst->entries[j].field_c;
            *s0 = mdlCloneModelObject(*(s32 *)(s1 + 300));
            mdlApplyModelMatrix((void *)*s0, func_003e9700(*(void **)(s1 + 296)), 0);
            if (*(u16 *)(s1 + 290) & 2) {
                *(u16 *)(p_dst + 290) |= 2;
            }
        } else if (a3->type == 1) {
            *(s32 *)(p_dst + 304) = func_004b11b0(*(s32 *)(src_base + 304));
        }
    }
    dst->scale = src->scale;
    FldResource_AdvanceAnimations((s8 *)dst, temp_f20);
    FldResource_TransformFrames((u8 *)dst, arg1, temp_f20);
    return dst;
}
