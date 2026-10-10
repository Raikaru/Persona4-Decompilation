#include "model_motion_internal.h"
#include "texture_callback_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
/* Source unit: src/Graphics/Model/mdlManager_004711e0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_003115a0 (verified MATCH there). */
/* W8 negative census corrected: 004776C0 is complete in C at 264B; its
   272B retail window has two zero words after jr/nop. 00475B90 (304B body
   plus jr/nop and two zero words) and 00473710 (332B body plus jr/nop and
   three zero words) likewise use placement padding, not missing logic.
   Remaining short probes are unresolved; do not add source-only padding.
   Best probes (object/window, nd): 00477810 232/240 nd169; 004776C0
   264/272 nd6; 00474BA0 316/320 nd153; 00475B90 304/320 nd147;
   00473710 332/352 nd202; 00477FB0 388/400 nd272. */
/* Keep optimization pragmas scoped to the functions whose retail code requires them. */
#include "type.h"
#include "model_matrix_internal.h"
#include "rw/std/stddef.h"
#include "Kosaka/k_clump_internal.h"
/* measured: index-first addu operand-order carrier (lever 3). Kept at top of
   file, OUTSIDE the opt_propagation pragma regions, so it inlines cleanly and
   does not emit a standalone symbol. */
static inline u32 addOff(u32 offset, u32 base) { return offset + base; }
static inline f32 mdlMulOrdered77810(f32 a, f32 b) { return a * b; }
extern f32 iGpffff8040;
extern f32 fGpffff809c;
extern u8 D_00713180[];
extern u8 D_007131A0[];
extern u8 D_007131C0[];
extern s32 K_Clump_MatUsrDataHasData(void* a, u8* b);
extern f32 func_004579a0(const RpMaterial* a, const char* b);
extern s32 func_0047e6f0(void** owner);

extern u32 RpHAnimFrameGetHierarchy(s32 object);
typedef void (*CallbackFn)(void);

extern s32 func_003b83d0(s32 object, s32 hierarchy);

extern void func_003e0e20(void *arg0, void *arg1, s32 arg2);
extern f32 DAT_0076112c;
extern void func_0039a260(void* a, void* b);
extern void func_0039ab20(void* a, int b, int c, int d);
extern int func_00475b90(void* buf, void* v, u32 idx, void* obj);
extern void* func_00457f40(void* obj, const char* name, s32 idx);
extern u8* func_003e9700(u8* a);
extern void func_003d5840(void* a, void* b);
extern u8* func_003d5790(s32 numNodes, s32 maxInterpKeyFrameSize);
extern s32 func_003d5e40(u8* a, f32 b);
extern void func_004633c0(void* clump, void* hierarchy);

typedef struct RtAnimAnimation RtAnimAnimation;

typedef void (*RtAnimKeyFrameBlendCallBack)(void* voidOut, void* voidIn1, void* voidIn2, f32 alpha);

typedef struct RtAnimInterpolator RtAnimInterpolator;

// 76 bytes. Layout from P3FES include/rw/rtanim.h.
struct RtAnimInterpolator
{
    RtAnimAnimation* pCurrentAnim;               // 0x00
    f32 currentTime;                             // 0x04
    void* pNextFrame;                            // 0x08
    void* pAnimCallBack;                         // 0x0c
    void* pAnimCallBackData;                     // 0x10
    f32 animCallBackTime;                        // 0x14
    void* pAnimLoopCallBack;                     // 0x18
    void* pAnimLoopCallBackData;                 // 0x1c
    s32 maxInterpKeyFrameSize;                   // 0x20
    s32 currentInterpKeyFrameSize;               // 0x24
    s32 currentAnimKeyFrameSize;                 // 0x28
    s32 numNodes;                                // 0x2c
    s32 isSubInterpoaltor;                       // 0x30
    s32 offsetInParent;                          // 0x34
    RtAnimInterpolator* parentAnimation;         // 0x38
    void* keyFrameApplyCB;                       // 0x3c
    RtAnimKeyFrameBlendCallBack keyFrameBlendCB; // 0x40
    void* keyFrameInterpolateCB;                 // 0x44
    void* keyFrameAddCB;                         // 0x48
};

typedef int (*code)();

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

extern code DAT_00922ba0;
extern s32 DAT_00922ba4;
extern s32 DAT_00922ba8;
extern float* DAT_00922bac;
extern code DAT_00922ba0_abs[];
extern u8 DAT_00922ba4_abs[];
extern u8 DAT_00922ba8_abs[];
extern u8 DAT_00922bac_abs[];
extern f32 D_00922BB0_abs[];
extern f32 D_00922BB4_abs[];
extern u8 D_00922BC0;
extern u8 D_00922BC0_abs[];

extern void RwMatrixScale(void* matrix, const RwV3d* scale, int combineOp);

extern u32 RpMatFXMaterialGetEffects();
extern s32 func_0039b6e0(s32 arg0);

extern u32 func_003b83f0(int object);
extern s32 func_003b85b0(u8* object);
extern void func_003b8520(u8* object, s32 value);
extern s32 func_00399b10(s32 object);
extern u32 func_003b8500(int object);
extern void func_00473140(int param_1);

typedef struct MdlAnimEntry MdlAnimEntry;

// 16 bytes. Layout from P3FES include/Graphics/Model/mdlManager.h.
typedef struct MdlAnimEntryTable
{
    MdlAnimEntry* entries; // 0x00
    u16 count;             // 0x04
    u16 unk_06;            // 0x06
    u8 unkData[0x08];
} MdlAnimEntryTable;

// 8 bytes
typedef struct MdlAnimResourceEntry
{
    void* resource;
    u8 flags;
    u8 unk_05[3];
} MdlAnimResourceEntry;

extern void func_0047fa60(int resource);
extern void (*DAT_008873ec[])(void* memory);

extern s32 func_003df7f0(u8* arg0);
extern void func_003d6230();

extern s32 func_003df890(s32* arg0);
extern void* func_003df8a0();
extern void* func_003df6e0(void* list, s32 index);

extern void func_003c21e0(u32 object, u32 arg1, u32 arg2);
extern void func_003d5e40_typed(f32 frame, void* interpolator);

extern s32 func_003bd0b0(u8* object, s32 index);
extern int strcmp(const char* s1, const char* s2);
extern char DAT_007641c8[1];

extern u32 func_003df5d0();
extern int func_00474970(int param_1, void* param_2);
extern void* func_00477350(void*, void*);
extern void* func_00477430(void*, void*);
extern void* func_00479880(void*, void*);
extern void* func_004776c0(void* param_1, void* param_2);
extern void* func_00474a10(void* param_1, void* data);
extern u32 func_00474ce0(void* param_1);
extern int strncmp();
extern int func_003d8130();
extern void RtAnimInterpolatorSetAnimLoopCallBack();
extern void* func_00474ba0(void* param_1, void* param_2);
extern char gp0xffff9d10;
extern u8 LAB_00474a50;
extern u8 LAB_00474a50_abs[];
extern u8 LAB_00474a90;
extern u8 LAB_00474a90_abs[];

extern s32 func_00397470(u8* frame);
extern void RwMatrixMultiply(void* a, void* b, void* c);

extern void func_004585c0(u8* arg0);
extern void* func_00476e90(void* object, void* data);
extern u8 D_00713160[];
extern s32 func_004581a0(void* object, const char* data);
extern u8 D_007131D8[];
extern f32 DAT_00761130;
extern u8 D_00713138[];
extern u8 D_007241d0;
extern void* D_00922BE0[];
extern void func_00440b68(void* a, void* b, int c);
extern u8* func_00454a60(u8* a, s32 b);
extern void func_0044ea90(const void* file, s32 line);
extern void* memset(void* destination, int value, size_t count);
extern void* DAT_008873e8[];
extern s64 DAT_00723cd8;
extern void func_004787e0(u8* a0);
extern void func_0048a000(void);
extern s32 func_004782b0(u8* a);
extern void* func_003bfae0(void);
extern int RwCameraFrustumTestSphere(void* a, void* b);
extern void* D_008872E0[];
extern void func_0047af60(void* a);
extern void func_0047aff0(void* a, void* b);
extern void func_0047afd0(void* a, void* b);
typedef void (*FnVoidPtr)(void*);

extern s32 K_Clump_MatUsrDataGetInt(const RpMaterial* material, const char* name);

typedef struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} RwRGBA;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

/* RwOpCombineType from rw/plcore/bamatrix.h; RWFORCEENUMSIZEINT is 0x7FFFFFFF. */
enum RwOpCombineType
{
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
};
typedef enum RwOpCombineType RwOpCombineType;

extern RwMatrix* RwMatrixTranslate(RwMatrix* matrix, const RwV3d* translation, RwOpCombineType combineOp);
struct RwMatrixTag;
extern struct RwMatrixTag* RwMatrixRotate(struct RwMatrixTag* matrix, const RwV3d* axis, f32 angle, RwOpCombineType combineOp);

// 12-byte attached-weapon slot: flags at 0x00, model at 0x04, signed frame ID at 0x08.
typedef struct MdlWpnSlot
{
    u8 flags;      // 0x00
    u8 pad1[3];    // 0x01..0x03
    void* wpnMdl; // 0x04
    s32 frameID;   // 0x08
} MdlWpnSlot;

// Model: mat 0x00, identityMat 0x40, scale 0x80, color 0xd0, clump 0xdc (layout from P3FES include/Graphics/Model/mdlManager.h).
typedef struct Model
{
    RwMatrix mat;         // 0x00
    RwMatrix identityMat; // 0x40
    RwV3d scale;          // 0x80
    u8 unkData0[0x44];    // 0x8c..0xd0
    RwRGBA color;         // 0xd0
    u8 unkData1[8];       // 0xd4..0xdc
    void* clump;          // 0xdc
    u8 unkData2[0x1AC];   // 0xe0..0x28c
    MdlWpnSlot attachedWpns[5]; // 0x28c (stride 0xC)
} Model;

extern void func_003e9cb0(void* frame, void* matrix, u32 flags);
extern void func_0047aee0(Model* mdl, RwMatrix* matrix);
extern void func_0047ae10(u8* mdl, u16 wpnIdx);
extern void func_0047d840();
extern void func_0047dda0();
extern void func_0047ea70(u8* a);
extern void func_0047adf0(u8* a, u16 b, s32 c);
extern s32 iGpffffbb28;
extern f32 iGpffff80cc;
extern void* func_004779b0(u32 type, u16 id);
extern s32 func_00479ca0(void* a, s32 b);
extern u32* func_003971d0(u8*, s32, s32, s32);
extern void* func_00462ae0(void* object);
extern void func_0047da30();
extern void* func_003c0520();
extern u32 *func_0047d200(u32 **head);
extern u32 *func_0047dc30(u32 **head);
extern void func_0047ea40();
extern s32 func_0047ae90(u8* model, u16 index);
extern void func_00478410(u8* a, u8* b);
extern void func_0047b050(void* a, int b);




/* measured: mwcc b210 rematerializes the 1.0f and 0x20003 constants inside the
   loop body; #pragma opt_loop_invariants on hoists both to function top to
   match retail (nd 54 -> 0). */
// FUN_00470E90
#pragma opt_loop_invariants on
u8* func_00470e90(u16 arg0)
{
    s32 size;
    u8* obj;
    u32 i;

    size = (s32)arg0 * 0x50 + 0x10;
    func_0044ea90(D_00713138, 0x142);
    obj = ((void* (*)(int, int))DAT_008873e8[0])(size, 0x40000);
    memset(obj, 0, size);
    *(u8**)(obj + 0) = obj + 0x10;
    *(u16*)(obj + 8) = arg0;
    for (i = 0; i < *(u16*)(obj + 8); i++) {
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x28) = 0x3F800000;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x14) = 0x3F800000;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x00) = 0x3F800000;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x10) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x08) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x04) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x24) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x20) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x18) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x38) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x34) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x30) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x0C) |= 0x20003;
    }
    *(s16*)(obj + 0xA) = 1;
    return obj;
}
#pragma opt_loop_invariants off

/* MATCHED this wave (nd 0, object 452B/window 464B): the former CSE-of-mask
   floor was disproved.  `#pragma opt_common_subs off`, declaration order
   var19, temp18, var17, var17_2, and explicit (u32) inner guards reproduce
   the retail body masks and sltiu tests; the prior nd~6 omission is gone. */
/* measured: opt_common_subs off probe for repeated u16 counter masks. */
#pragma opt_common_subs off
// FUN_00471010
void func_00471010(u8* arg0)
{
    extern s32 func_003d5300(u8* arg0);
    extern void func_003d5830(u8* arg0);
    s32 offset;
    u8* temp4;
    u8* temp4_2;
    u8* temp4_3;
    s32 var19;
    u8* temp18;
    s32 var17;
    s32 var17_2;
    u8* temp2;
    u8* temp4_4;

    *(u16*)(arg0 + 0xA) -= 1;
    if (*(u16*)(arg0 + 0xA) == 0) {
        temp4 = *(u8**)(arg0 + 4);
        if (temp4 != (u8*)0) {
            func_003d5300(temp4);
        }
        var19 = 0;
        goto loop20_check;
loop20_body:
        temp2 = *(u8**)(arg0 + 0);
        offset = (var19 & 0xFFFF) * 0x50;
        temp2 += offset;
        temp4_2 = *(u8**)(temp2 + 0x40);
        if ((temp4_2 != (u8*)0) &&
            ((*(u32*)(temp2 + 0x44) & 1) == 0) &&
            (temp4_2 != (u8*)D_00922BC0_abs)) {
            func_003d5300(temp4_2);
            temp2 = *(u8**)(arg0 + 0);
            temp2 += offset;
            temp18 = *(u8**)(temp2 + 0x48);
            if (temp18 != (u8*)0) {
                var17 = 0;
                goto loop10_check;
loop10_body:
                func_003d5300(*(u8**)(temp18 + ((var17 & 0xFFFF) * 4)));
                var17 = (var17 + 1) & 0xFFFF;
loop10_check:
                if ((u32)(var17 & 0xFFFF) < 4) {
                    goto loop10_body;
                }
                var17_2 = 0;
                goto loop15_check;
loop15_body:
                temp4_3 = *(u8**)(temp18 + ((var17_2 & 0xFFFF) * 4) + 0x10);
                if (temp4_3 != (u8*)0) {
                    func_003d5830(temp4_3);
                }
                var17_2 = (var17_2 + 1) & 0xFFFF;
loop15_check:
                if ((u32)(var17_2 & 0xFFFF) < 4) {
                    goto loop15_body;
                }
                DAT_008873ec[0](temp18);
            }
            temp2 = *(u8**)(arg0 + 0);
            temp2 += offset;
            temp4_4 = *(u8**)(temp2 + 0x4C);
            if (temp4_4 != (u8*)0) {
                DAT_008873ec[0](temp4_4);
            }
        }
        var19 = (var19 + 1) & 0xFFFF;
loop20_check:
        if ((var19 & 0xFFFF) < *(u16*)(arg0 + 8)) {
            goto loop20_body;
        }
        DAT_008873ec[0](arg0);
    }
}
/* measured: closes opt_common_subs off probe around func_00471010. */
#pragma opt_common_subs on
// FUN_004711E0
void* func_004711e0(void* param_1, void* param_2)
{
    u32 value;

    value = RpHAnimFrameGetHierarchy((s32)param_1);
    if (value != 0)
    {
        goto store_value;
    }
    func_003e9af0(param_1, func_004711e0, param_2);
    return param_1;
store_value:
    *(u32*)param_2 = value;
    return NULL;
}



// FUN_00471250
void* func_00471250(void* param_1, void* hierarchy)
{
    func_003b83d0((s32)param_1, (s32)hierarchy);
    return param_1;
}



// FUN_00471280
u32 func_00471280(RtAnimInterpolator* param_2, RtAnimInterpolator* param_3,
                  RtAnimInterpolator* param_4, f32 param_1)
{
    s32 frame;
    s32 offset2;
    s32 offset3;
    s32 offset4;
    f32 alpha;
    u8* out;
    u8* in1;
    u8* in2;
    u8* in2Out;
    offset2 = param_2->offsetInParent;
    offset3 = param_3->offsetInParent;
    offset4 = param_4->offsetInParent;
    for (frame = offset2; frame < param_2->numNodes + param_2->offsetInParent; frame++)
    {
        in2 = (u8*)(param_4->currentInterpKeyFrameSize * (frame - offset4) -
                     (0u - (u32)param_4)) + 0x4c;
        out = (u8*)(param_2->currentInterpKeyFrameSize * (frame - offset2) -
                    (0u - (u32)param_2));
        in1 = (u8*)(param_3->currentInterpKeyFrameSize * (frame - offset3) -
                    (0u - (u32)param_3));
        alpha = *(f32*)(in2 + 0x30);
        param_2->keyFrameBlendCB(out + 0x4c, in1 + 0x4c, in2,
                                 param_1 * alpha);
    }
    return 1;
}



/* Research-only controller reconstruction. Real matrix/quaternion/cache storage,
 * halfword controller views and direct callback ABI follow the retail window.
 * The former opt-off settings inflated a scalar-fragment draft; this candidate
 * uses the owner configuration. Quaternion interpolation and conversion phases
 * follow the retail arithmetic trees and the checked-in RenderWare macros.
 * Reviewed checkpoint: 7084/7104 live bytes, frame 0x550, 812 resolved-word
 * edits (unit-cost Levenshtein). Still NONMATCHING; see
 * docs/probe_archive/model_00471370_guarded_recovery.md.
 */
#pragma push
/* 2026-10-08: opt_loop_invariants on lowers fnalign from 879 to 856 edits. */
/* 2026-10-09: 856 -> 841 edits. The two angle-limit blocks follow retail's !(a <= lim) && a < 360 - lim test and a < 180 ? lim : 360 - lim choice, which reuses the 360 - lim value.
 * 2026-10-09: 841 -> 739: frame layout. Later declarations sit lower in the frame;
 * the small-vector group is declared axis, position, workingVector, look, eye,
 * direction, forwardAxis (mapped with tools/frameslots.py).
 * 2026-10-09: 739 -> 672: aggregate declaration order (greedy, scored with
 * tools/multiscore.py) moves the matrices and quaternions toward retail's frame slots.
 * 555: swap sweep.
 * 542: swap sweep.
 * fnalign 542 -> 445: aggregates declared in retail slot order (baseMatrix 0x4a0 ... temp_v22 0x150); spilled scalars iStack_420, uStack_430, hasParentMatrix, resetAnimation, iStack_450 in retail spill order.
 * fnalign 445 -> 404: owner-link path first, identity fallback in the else (retail block order).
 * fnalign 404 -> 399: early return for a ready non-null controller with zero weight; hierarchy pointer loaded before the index; temp_v3 int; mode masks tested in the loop (hoisted after the counter init, as retail).
 * fnalign 399 -> 373: angle-limit snapshot block in retail branch order with whole-quaternion copies.
 * fnalign 373 -> 338: controller quaternion writes are whole-quaternion copies.
 * fnalign 338 -> 315: angle wrap loops test x > 360 (direct bc1f, no boolean); func_003e9240 returns RwBool (s32; retail does not mask).
 * workingVector copied from the controller as a whole vector.
 * fnalign 301 -> 291: matrix positions copied from position as whole vectors.
 * 0x1389 node test written as a switch with a default (retail beq-case / b-default shape).
 * fnalign 291 -> 277: quaternion dot products in block-local floats (retail keeps them in f0 across the sign test).
 * hierarchy push/pop stack starts at &temp_v27[1] (retail $fp = sp+0x3e4).
 * fnalign 276 -> 259: dirty-list insert written as the RenderWare link-list macro (list address formed once).
 * hierarchy base loaded before the node index.
 * bit 2 cleared with ~4 (retail and with -5).
 * fnalign 251 -> 159: controller state half-word accessed through a byte pointer (no hoisted address), interpolator slots addressed before the create call, hierarchy base loaded first.
 * 0x3e half-word through a byte pointer too.
 * fnalign 159 -> 122: float control fields through *(float *)&puVar3[N]; final blend test in retail polarity (blend path first).
 * blend weight read from controller + 2 (retail lwc1 4($s2)); the previous controller + 4 read the wrong field.
 * blend step: duration loaded, reciprocal formed, then added.
 * controller flags cleared through a fresh u16 read in the angle-limit else (retail reloads).
 * second hierarchy lookup: node offset formed before the base.
 * owner-chain multiply source as a byte pointer.
 * parent row offset formed before the matrix array load.
 * float temporaries declared temp_v20, temp_v15, temp_v14, temp_v16, temp_v21 (retail FPR colours in the angle clamp).
 * fnalign 95 -> 69: aim angles in block-local floats (pitch, yaw, baseYaw, basePitch, limit); unused temporaries removed.
 */
// FUN_00471370 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
s32 func_00471370(u8 *param_1, u8 *param_2, u8 *param_3, void *param_4)

{
    struct RtQuat;
    struct RtQuatSlerpCache;
    struct RwObjectOwnerLink;
    extern void *func_003d5790(int, int);
    extern s32 func_003e9240(struct RwObjectOwnerLink *); /* RwBool: retail tests the result unmasked */
    extern u8 * func_003e9700(u8 *);
    extern float func_0044b920(float);
    extern float func_0044b950(float, float);
    extern int func_003d5e40(unsigned char *, float);
    extern int func_003d5e90(unsigned char *, unsigned char *, unsigned char *, float);
    extern float func_004bd4a0(unsigned char *, unsigned char *);
    extern void func_003954b0(void *matrix, void *keyFrame);
    extern s32 func_00397c40(void* hierarchy);
    extern void func_003d5840(RtAnimInterpolator *, RtAnimAnimation *);
    extern s32 RtQuatConvertFromMatrix(struct RtQuat *, const RwMatrix *);
    extern struct RtQuat *func_003dc740(struct RtQuat *, const RwV3d *, f32, s32);
    extern RwV3d * RtQuatTransformVectors(RwV3d *, const RwV3d *, s32, const struct RtQuat *);
    extern void func_003dcc70(struct RtQuat *, struct RtQuat *, struct RtQuatSlerpCache *);
    extern RwMatrix * RwMatrixMultiply(RwMatrix *, const RwMatrix *, const RwMatrix *);
    extern RwMatrix * func_003e0960(RwMatrix *, const RwMatrix *);
    extern RwMatrix * RwMatrixScale(RwMatrix *, const RwV3d *, RwOpCombineType);
    extern f32 RwV3dNormalize(RwV3d *, const RwV3d *);
    extern RwV3d * func_003e42a0(RwV3d *, const RwV3d *, const RwMatrix *);
    extern RwV3d * func_003e4320(RwV3d *, const RwV3d *, const RwMatrix *);
    extern u8 * func_003e9680(u8 *);
    extern void func_003ed960(u8 *object);
/* Local declarations above follow the actual pointer/float call contracts. */
    extern s32 DAT_0088739c[];
    extern float DAT_00922bb0[];
    extern float DAT_00922bb4[];
    extern float fGpffff8040;
    extern float fGpffff8048;
    extern float fGpffff804c;
    extern float fGpffff8050;
    extern float fGpffff8054;
    extern float fGpffff8058;
    extern float fGpffff805c;
    extern float fGpffff8060;
    extern float fGpffff8064;
    extern float fGpffff8068;
    extern float fGpffff806c;
    extern float fGpffff8070;
    extern float fGpffff8074;
  typedef union { f32 value[4]; u32 bits[4]; } ControllerQuat;
  typedef struct { f32 from[4]; f32 to[4]; f32 omega; s32 nearlyZero; } ControllerSlerpCache;
  unsigned short temp_v0;
  void (*pcVar2)(void *matrix, void *keyFrame);
  unsigned int *puVar3;
  int *piVar4;
  int temp_v3;
  float *pfVar8;
  int temp_v4;
  unsigned int temp_v5;
  unsigned int temp_v6;
  unsigned int *puVar12;
  int temp_v7;
  int temp_v8;
  int temp_v9;
  float *pfVar16;
  float *pfVar17;
  unsigned int temp_v10;
  unsigned char *pbVar19;
  int temp_v11;
  float *pfVar21;
  unsigned int *puVar22;
  unsigned int temp_v12;
  unsigned int temp_v13;
  unsigned int temp_v17;
  float temp_v20;
  float temp_v21;
  /* Retail sp+0x100 is conditionally assigned at 004719dc/00471d7c/
   * 00471f0c and read at 00472280. Preserve that original lifetime. */
  int iStack_420;
  unsigned int uStack_430;
  s32 hasParentMatrix;
  s32 resetAnimation;
  int iStack_450;
  RwMatrix baseMatrix;
  RwMatrix identityMatrix;
  unsigned int temp_v27 [31];
  RwMatrix scaleMatrix;
  RwMatrix ancestorMatrix;
  RwMatrix frameMatrix;
  RwMatrix axisMatrix;
  unsigned char temp_v24 [64];
  unsigned char temp_v23 [64];
  RwMatrix localMatrix;
  ControllerQuat rotation;
  ControllerQuat afStack_350;
  ControllerSlerpCache interpolation;
  ControllerQuat rotationSnapshot;
  ControllerQuat blendedRotation;
  ControllerQuat startRotation;
  ControllerQuat fallbackRotation;
  unsigned char temp_v22 [64];
  
  u32 axis[3];
  RwV3d position;
  RwV3d workingVector;
  f32 look[3];
  f32 eye[3];
  f32 direction[3];
  u32 forwardAxis[3];

  typedef char ControllerPointerSize[(sizeof(void *) == 4) ? 1 : -1];
  typedef char ControllerMatrixSize[(sizeof(RwMatrix) == 64) ? 1 : -1];
  typedef char ControllerMatrixFlags[(offsetof(RwMatrix, flags) == 12) ? 1 : -1];
  typedef char ControllerMatrixUp[(offsetof(RwMatrix, up) == 16) ? 1 : -1];
  typedef char ControllerMatrixAt[(offsetof(RwMatrix, at) == 32) ? 1 : -1];
  typedef char ControllerMatrixPosition[(offsetof(RwMatrix, pos) == 48) ? 1 : -1];
  typedef char ControllerQuaternionSize[(sizeof(ControllerQuat) == 16) ? 1 : -1];
  typedef char ControllerCacheSize[(sizeof(ControllerSlerpCache) == 40) ? 1 : -1];
  typedef char ControllerCacheTo[(offsetof(ControllerSlerpCache, to) == 16) ? 1 : -1];
  typedef char ControllerCacheOmega[(offsetof(ControllerSlerpCache, omega) == 32) ? 1 : -1];
  typedef char ControllerCacheFlag[(offsetof(ControllerSlerpCache, nearlyZero) == 36) ? 1 : -1];
  typedef char ControllerPositionSize[(sizeof(position) == 12) ? 1 : -1];
  typedef char ControllerWorkingVectorSize[(sizeof(workingVector) == 12) ? 1 : -1];
  typedef char ControllerWorkingVectorX[(offsetof(RwV3d, x) == 0) ? 1 : -1];
  typedef char ControllerWorkingVectorY[(offsetof(RwV3d, y) == 4) ? 1 : -1];
  typedef char ControllerWorkingVectorZ[(offsetof(RwV3d, z) == 8) ? 1 : -1];
  typedef char ControllerDirectionSize[(sizeof(direction) == 12) ? 1 : -1];
  typedef char ControllerAxisSize[(sizeof(axis) == 12) ? 1 : -1];

  u16 *modelState = (u16 *)param_2;
  u16 *controller = (u16 *)param_3;

  hasParentMatrix = 0;
  temp_v3 = 0;
  resetAnimation = 0;
  puVar12 = (unsigned int *)param_1;
  temp_v10 = *puVar12;
  if (((temp_v10 & 1) != 0) && (puVar12[7] != 0xffffffff)) {
    temp_v4 = puVar12[7] * 0x40;
    pfVar21 = (float *)(*(int *)(puVar12[6] + 8) + temp_v4);
    if (((temp_v10 & 0x2000) != 0) && ((temp_v10 & 0x4000) != 0)) {
      hasParentMatrix = 1;
      temp_v3 = *(unsigned int *)(puVar12[6] + 0x14);
    }
  } else {
    if ((temp_v10 & 0x4000) != 0) {
      (*(u32 *)&identityMatrix.at.z) = 0x3f800000;
      (*(u32 *)&identityMatrix.up.y) = 0x3f800000;
      ((f32 *)&identityMatrix)[0] = 1.0f;
      (*(u32 *)&identityMatrix.up.x) = 0;
      ((f32 *)&identityMatrix)[2] = 0.0f;
      ((f32 *)&identityMatrix)[1] = 0.0f;
      (*(u32 *)&identityMatrix.at.y) = 0;
      (*(u32 *)&identityMatrix.at.x) = 0;
      (*(u32 *)&identityMatrix.up.z) = 0;
      (*(u32 *)&identityMatrix.pos.z) = 0;
      (*(u32 *)&identityMatrix.pos.y) = 0;
      (*(u32 *)&identityMatrix.pos.x) = 0;
      /* Retail 00471460 reads this flag word before any defining store. */
      identityMatrix.flags = identityMatrix.flags | 0x20003;
      pfVar21 = ((f32 *)&identityMatrix);
      if ((temp_v10 & 0x2000) != 0) {
        hasParentMatrix = 1;
        temp_v3 = puVar12[5];
      }
    } else {
      hasParentMatrix = 1;
      temp_v3 = puVar12[5];
      pfVar21 = ((f32 *)&baseMatrix);
    }
  }
  if (hasParentMatrix) {
    if ((temp_v3 != 0) && (temp_v9 = *(int *)(temp_v3 + 4), temp_v9 != 0)) {
      temp_v4 = func_003e9240((struct RwObjectOwnerLink *)((void *)temp_v9));
      if (temp_v4 == 0) {
        baseMatrix = *(const RwMatrix *)func_003e9700((u8 *)temp_v9);
      }
      else {
        baseMatrix = *(const RwMatrix *)(temp_v9 + 0x10);
        for (temp_v9 = *(int *)(temp_v9 + 4); temp_v9 != 0; temp_v9 = *(int *)(temp_v9 + 4)) {
          ancestorMatrix = baseMatrix;
          RwMatrixMultiply((RwMatrix *)(((f32 *)&baseMatrix)),(const RwMatrix *)(((f32 *)&ancestorMatrix)),(const RwMatrix *)((u8 *)temp_v9 + 0x10));
        }
      }
    }
    else {
      (*(u32 *)&baseMatrix.at.z) = 0x3f800000;
      ((f32 *)&baseMatrix)[5] = 1.0f;
      ((f32 *)&baseMatrix)[0] = 1.0f;
      ((f32 *)&baseMatrix)[4] = 0.0f;
      ((f32 *)&baseMatrix)[2] = 0.0f;
      ((f32 *)&baseMatrix)[1] = 0.0f;
      (*(u32 *)&baseMatrix.at.y) = 0;
      (*(u32 *)&baseMatrix.at.x) = 0;
      ((f32 *)&baseMatrix)[6] = 0.0f;
      (*(u32 *)&baseMatrix.pos.z) = 0;
      (*(u32 *)&baseMatrix.pos.y) = 0;
      (*(u32 *)&baseMatrix.pos.x) = 0;
      /* Retail 004715d0 likewise preserves the unwritten flag bits. */
      baseMatrix.flags |= 0x20003;
    }
  }
  temp_v3 = temp_v10 & 0x2000;
  if ((temp_v3 != 0) && ((*(unsigned char *)(*(int *)(puVar12[5] + 0xa0) + 3) & 3) == 0)) {
    typedef struct ControllerLink { struct ControllerLink *next; struct ControllerLink *prev; } ControllerLink;
    ControllerLink *list = (ControllerLink *)DAT_0088739c;

    ((ControllerLink *)(*(int *)(puVar12[5] + 0xa0) + 8))->next = list->next;
    ((ControllerLink *)(*(int *)(puVar12[5] + 0xa0) + 8))->prev = list;
    list->next->prev = (ControllerLink *)(*(int *)(puVar12[5] + 0xa0) + 8);
    temp_v9 = *(int *)(puVar12[5] + 0xa0);
    list->next = (ControllerLink *)(temp_v9 + 8);
    *(unsigned char *)(temp_v9 + 3) = *(unsigned char *)(temp_v9 + 3) | 2;
  }
  temp_v6 = puVar12[8];
  pcVar2 = *(void (**)(void *, void *))(temp_v6 + 0x3c);
  temp_v9 = *(int *)(temp_v6 + 0x24);
  puVar22 = &temp_v27[1];
  uStack_430 = puVar12[4];
  pfVar8 = (float *)puVar12[2];
  temp_v11 = temp_v6 + 0x4c;
  temp_v4 = **(int **)(modelState + 0x1a);
  puVar3 = *(unsigned int **)(temp_v4 + (short)modelState[2] * 0x50 + 0x48);
  if ((puVar3 != (unsigned int *)0x0) && (*(float *)(modelState + 4) == 0.0f)) {
    return 1;
  }
  {
    /* Per-hierarchy modes are snapped before callbacks and reused for all
     * nodes, as at retail 004716d0-004716dc. The full entry flags need not
     * remain live throughout the node traversal. */
    for (iStack_420 = 0; iStack_420 < (int)puVar12[1]; iStack_420 = iStack_420 + 1) {
      if (pcVar2 == func_003954b0) {
        /* RtQuatUnitConvertToMatrixMacro: independent square/cross/wimag
         * products precede matrix construction, as in retail 0047170c-0047172c. */
        const f32 x = *(f32 *)(temp_v11 + 8);
        const f32 y = *(f32 *)(temp_v11 + 0xc);
        const f32 z = *(f32 *)(temp_v11 + 0x10);
        const f32 w = *(f32 *)(temp_v11 + 0x14);
        RwV3d square;
        RwV3d cross;
        RwV3d wimag;
        square.x = x * x;
        square.y = y * y;
        square.z = z * z;
        cross.x = y * z;
        cross.y = z * x;
        cross.z = x * y;
        wimag.x = w * x;
        wimag.y = w * y;
        wimag.z = w * z;
        frameMatrix.right.x = 1.0f - 2.0f * (square.y + square.z);
        frameMatrix.right.y = 2.0f * (cross.z + wimag.z);
        frameMatrix.right.z = 2.0f * (cross.y - wimag.y);
        frameMatrix.up.x = 2.0f * (cross.z - wimag.z);
        frameMatrix.up.y = 1.0f - 2.0f * (square.x + square.z);
        frameMatrix.up.z = 2.0f * (cross.x + wimag.x);
        frameMatrix.at.x = 2.0f * (cross.y + wimag.y);
        frameMatrix.at.y = 2.0f * (cross.x - wimag.x);
        frameMatrix.at.z = 1.0f - 2.0f * (square.x + square.y);
        frameMatrix.pos.x = 0.0f;
        frameMatrix.pos.y = 0.0f;
        frameMatrix.pos.z = 0.0f;
        frameMatrix.flags = 3;
        frameMatrix.pos.x = *(f32 *)(temp_v11 + 0x18);
        frameMatrix.pos.y = *(f32 *)(temp_v11 + 0x1c);
        frameMatrix.pos.z = *(f32 *)(temp_v11 + 0x20);
      }
      else {
        (*pcVar2)(&frameMatrix.right.x,(void *)temp_v11);
      }
      switch (*(int *)(puVar12[4] + iStack_420 * 0x10)) {
      case 0x1389: {
        s32 angleLimited;
        if ((param_4 == 0) && ((*controller & 0x400) == 0)) {
          *controller = *controller | 0x600;
        }
        angleLimited = 0;
        workingVector.x = 1.0f / *(float *)(controller + 0x18);
        workingVector.y = 1.0f / *(float *)(controller + 0x1a);
        workingVector.z = 1.0f / *(float *)(controller + 0x1c);
        if ((*modelState & 0x10) != 0) {
          workingVector.x = workingVector.x * (1.0f / DAT_00922bb0[0]);
          temp_v21 = (1.0f / DAT_00922bb0[0]) * DAT_00922bb4[0];
          workingVector.y = workingVector.y * temp_v21;
          workingVector.z = workingVector.z * temp_v21;
        }
        scaleMatrix = *(const RwMatrix *)pfVar21;
        RwMatrixScale((RwMatrix *)(((f32 *)&scaleMatrix)),(const RwV3d *)(&workingVector),(RwOpCombineType)(1));
        RwMatrixMultiply((RwMatrix *)(&localMatrix.right.x),(const RwMatrix *)(&frameMatrix.right.x),(const RwMatrix *)(((f32 *)&scaleMatrix)));
        position = localMatrix.pos;
        if (param_4 == 0) {
          RwMatrixScale((RwMatrix *)(&localMatrix.right.x),(const RwV3d *)(&workingVector),(RwOpCombineType)(1));
          axis[0] = 0;
          axis[1] = 0x3f800000;
          axis[2] = 0;
          RwMatrixRotate((struct RwMatrixTag*)temp_v24, (const RwV3d*)&axis[0], 180.0f, rwCOMBINEREPLACE);
          axis[0] = 0;
          axis[1] = 0;
          axis[2] = 0x3f800000;
          RwMatrixRotate((struct RwMatrixTag*)temp_v24, (const RwV3d*)&axis[0], -90.0f, rwCOMBINEPOSTCONCAT);
          RwMatrixMultiply((RwMatrix *)(((u8 *)&axisMatrix)),(const RwMatrix *)(temp_v24),(const RwMatrix *)(((f32 *)&baseMatrix)));
          temp_v0 = *controller;
          if ((temp_v0 & 0x100) == 0) {
            if ((temp_v0 & 0x60) != 0) {
              iStack_450 = 1;
              if ((temp_v0 & 0x40) != 0) {
                workingVector.x = position.x - *(float *)(controller + 0x1e);
                workingVector.y = position.y - *(float *)(controller + 0x20);
                workingVector.z = position.z - *(float *)(controller + 0x22);
              } else {
                workingVector = *(const RwV3d *)(controller + 0x1e);
                workingVector.x = -workingVector.x;
                workingVector.y = -workingVector.y;
                workingVector.z = -workingVector.z;
              }
              RwV3dNormalize((RwV3d *)(&workingVector),(const RwV3d *)(&workingVector));
              func_003e0960((RwMatrix *)(temp_v23),(const RwMatrix *)(((f32 *)&baseMatrix)));
              func_003e4320((RwV3d *)(&workingVector),(const RwV3d *)(&workingVector),(const RwMatrix *)(temp_v23));
              RwV3dNormalize((RwV3d *)(&workingVector),(const RwV3d *)(&workingVector));
              eye[0] = 0.0f;
              eye[1] = 0.0f;
              eye[2] = -100.0f;
              func_003e42a0((RwV3d *)(&eye[0]),(const RwV3d *)(&eye[0]),(const RwMatrix *)(((f32 *)&scaleMatrix)));
              look[0] = position.x - eye[0];
              look[1] = position.y - eye[1];
              look[2] = position.z - eye[2];
              func_003e4320((RwV3d *)(&look[0]),(const RwV3d *)(&look[0]),(const RwMatrix *)(temp_v23));
              RwV3dNormalize((RwV3d *)(&look[0]),(const RwV3d *)(&look[0]));
               {
                 f32 pitch;
                 f32 yaw;
                 f32 baseYaw;
                 f32 basePitch;
                 f32 limit;

                 basePitch = fGpffff8048 * func_0044b920(look[1]) - 90.0f;
                 baseYaw = fGpffff8048 * func_0044b950(look[0],look[2]) + 180.0f;
                 pitch = fGpffff8048 * func_0044b920(workingVector.y) - 90.0f;
                 yaw = fGpffff8048 * func_0044b950(workingVector.x,workingVector.z) + 180.0f;
                 for (pitch = pitch - basePitch; pitch < 0.0f; pitch = pitch + 360.0f) {
                 }
                 for (; pitch > 360.0f; pitch = pitch - 360.0f) {
                 }
                 limit = *(float *)(controller + 4);
                 if (!(pitch <= limit) && pitch < 360.0f - limit) {
                   if (pitch < 180.0f) {
                     pitch = limit;
                   } else {
                     pitch = 360.0f - limit;
                   }
                   angleLimited = 1;
                 }
                 RwMatrixRotate((struct RwMatrixTag*)temp_v24, (const RwV3d*)((u8 *)&axisMatrix.up), -(pitch + basePitch), rwCOMBINEREPLACE);
                 for (yaw = yaw - baseYaw; yaw < 0.0f; yaw = yaw + 360.0f) {
                 }
                 for (; yaw > 360.0f; yaw = yaw - 360.0f) {
                 }
                 limit = *(float *)(controller + 6);
                 if (!(yaw <= limit) && yaw < 360.0f - limit) {
                   if (yaw < 180.0f) {
                     yaw = limit;
                   } else {
                     yaw = 360.0f - limit;
                   }
                   angleLimited = 1;
                 }
                 RwMatrixRotate((struct RwMatrixTag*)temp_v24, (const RwV3d*)((u8 *)&axisMatrix), yaw + baseYaw, rwCOMBINEPOSTCONCAT);
               }
              RwMatrixMultiply((RwMatrix *)(pfVar8),(const RwMatrix *)(((u8 *)&axisMatrix)),(const RwMatrix *)(temp_v24));
              RtQuatConvertFromMatrix((struct RtQuat *)(&rotation.value[0]),(const RwMatrix *)(pfVar8));
            } else {
              if ((temp_v0 & 0x80) != 0) {
                iStack_450 = 0;
                axis[0] = 0x3f800000;
                axis[1] = 0;
                axis[2] = 0;
                func_003e4320((RwV3d *)(&axis[0]),(const RwV3d *)(&axis[0]),(const RwMatrix *)(((f32 *)&baseMatrix)));
                RwMatrixRotate((struct RwMatrixTag*)temp_v24, (const RwV3d*)&axis[0], *(float *)(controller + 0x1e), rwCOMBINEREPLACE);
                axis[0] = 0;
                axis[1] = 0x3f800000;
                axis[2] = 0;
                func_003e4320((RwV3d *)(&axis[0]),(const RwV3d *)(&axis[0]),(const RwMatrix *)(((f32 *)&baseMatrix)));
                RwMatrixRotate((struct RwMatrixTag*)temp_v24, (const RwV3d*)&axis[0], *(float *)(controller + 0x20), rwCOMBINEPOSTCONCAT);
                RwMatrixMultiply((RwMatrix *)(pfVar8),(const RwMatrix *)(((u8 *)&axisMatrix)),(const RwMatrix *)(temp_v24));
                RtQuatConvertFromMatrix((struct RtQuat *)(&rotation.value[0]),(const RwMatrix *)(pfVar8));
              } else {
                RtQuatConvertFromMatrix((struct RtQuat *)(&rotation.value[0]),(const RwMatrix *)(&localMatrix.right.x));
              }
            }
            if (((*controller & 0x1000) != 0) && angleLimited) {
              if ((*controller & 0x800) == 0) {
                *(ControllerQuat *)(controller + 0x10) = rotation;
              }
              *controller = *controller | 0x800;
            }
            else {
              *(u16 *)controller = *(u16 *)controller & 0xf7ff;
            }
            if ((*controller & 0x800) != 0) {
              rotation = *(ControllerQuat *)(controller + 0x10);
            }
            if (((*controller & 0x8000) != 0) &&
               ((*(float *)(controller + 0x24) != 0.0f || (*(float *)(controller + 0x26) != 0.0f)))) {
              rotationSnapshot = rotation;
              iStack_450 = 0;
              axis[0] = 0;
              axis[1] = 0x3f800000;
              axis[2] = 0;
              RtQuatTransformVectors((RwV3d *)(&axis[0]),(const RwV3d *)(&axis[0]),(s32)(1),(const struct RtQuat *)(&rotationSnapshot.value[0]));
              func_003dc740((struct RtQuat *)&rotation.value[0],(const RwV3d *)&axis[0],*(float *)(controller + 0x24),2);
              axis[0] = 0x3f800000;
              axis[1] = 0;
              axis[2] = 0;
              RtQuatTransformVectors((RwV3d *)(&axis[0]),(const RwV3d *)(&axis[0]),(s32)(1),(const struct RtQuat *)(&rotationSnapshot.value[0]));
              func_003dc740((struct RtQuat *)&rotation.value[0],(const RwV3d *)&axis[0],*(float *)(controller + 0x26),2);
            }
          }
          else {
            RtQuatConvertFromMatrix((struct RtQuat *)(&rotation.value[0]),(const RwMatrix *)(&localMatrix.right.x));
          }
          if ((*controller & 0x200) != 0) {
            RtQuatConvertFromMatrix((struct RtQuat *)(controller + 8),(const RwMatrix *)(&localMatrix.right.x));
            *controller = *controller & 0xfdff;
            resetAnimation = 1;
            if ((*controller & 0x100) != 0) {
              *controller = *controller & 0x7e1f;
              *controller = *controller & 0xfbff;
              *controller = *controller & 0xf7ff;
            }
          } else {
            if ((puVar3 == (unsigned int *)0x0) && ((*controller & 0x100) != 0)) {
              {
                f32 dot;

                dot = func_004bd4a0((unsigned char *)(controller + 8),(unsigned char *)&rotation.value[0]);
                if (dot < 0.0f) {
                  afStack_350.value[3] = -rotation.value[3];
                  afStack_350.value[0] = -rotation.value[0];
                  afStack_350.value[1] = -rotation.value[1];
                  afStack_350.value[2] = -rotation.value[2];
                  dot = func_004bd4a0((unsigned char *)(controller + 8),(unsigned char *)afStack_350.value);
                }
                temp_v21 = func_0044b920(dot);
              }
              if (temp_v21 * 2.0f < fGpffff804c) {
                *controller = *controller & 0x7e1f;
                *controller = *controller & 0xfbff;
              }
              *controller = *controller & 0xf7ff;
            }
            /* Snapshot the complete starting controller quaternion. */
            startRotation = *(const ControllerQuat *)(controller + 8);
            func_003dcc70((struct RtQuat *)(&startRotation.value[0]),(struct RtQuat *)(&rotation.value[0]),(struct RtQuatSlerpCache *)(&interpolation.from[0]));
            {
              f32 interpolationTime = *(float *)(controller + 2);
              if (interpolationTime <= 0.0f) {
                blendedRotation = startRotation;
              }
              else if (1.0f <= interpolationTime) {
                blendedRotation = rotation;
              }
              else {
                f32 fromWeight = 1.0f - interpolationTime;
                f32 toWeight = interpolationTime;
                if (interpolation.nearlyZero == 0) {
                  fromWeight = fromWeight * interpolation.omega;
                  {
                    const f32 z = fromWeight * fromWeight;
                    f32 polynomial = fGpffff8050 * z + fGpffff8054;
                    polynomial = z * polynomial + fGpffff8058;
                    polynomial = z * polynomial + fGpffff805c;
                    polynomial = z * polynomial + fGpffff8060;
                    polynomial = z * polynomial + fGpffff8064;
                    fromWeight = z * fromWeight * polynomial + fromWeight;
                  }
                  toWeight = toWeight * interpolation.omega;
                  {
                    const f32 z = toWeight * toWeight;
                    f32 polynomial = fGpffff8050 * z + fGpffff8054;
                    polynomial = z * polynomial + fGpffff8058;
                    polynomial = z * polynomial + fGpffff805c;
                    polynomial = z * polynomial + fGpffff8060;
                    polynomial = z * polynomial + fGpffff8064;
                    toWeight = z * toWeight * polynomial + toWeight;
                  }
                }
                blendedRotation.value[0] = interpolation.from[0] * fromWeight;
                blendedRotation.value[1] = interpolation.from[1] * fromWeight;
                blendedRotation.value[2] = interpolation.from[2] * fromWeight;
                blendedRotation.value[0] = blendedRotation.value[0] + interpolation.to[0] * toWeight;
                blendedRotation.value[1] = blendedRotation.value[1] + interpolation.to[1] * toWeight;
                blendedRotation.value[2] = blendedRotation.value[2] + interpolation.to[2] * toWeight;
                blendedRotation.value[3] = interpolation.from[3] * fromWeight + interpolation.to[3] * toWeight;
              }
            }
            if (((*controller & 0x2000) != 0) && (iStack_450 != 0)) {
              RtQuatConvertFromMatrix((struct RtQuat *)(&fallbackRotation.bits[0]),(const RwMatrix *)(&localMatrix.right.x));
              {
                f32 dot;

                dot = func_004bd4a0((unsigned char *)&fallbackRotation.bits[0],(unsigned char *)&blendedRotation.value[0]);
                if (dot < 0.0f) {
                  afStack_350.value[3] = -blendedRotation.value[3];
                  afStack_350.value[0] = -blendedRotation.value[0];
                  afStack_350.value[1] = -blendedRotation.value[1];
                  afStack_350.value[2] = -blendedRotation.value[2];
                  dot = func_004bd4a0((unsigned char *)&fallbackRotation.bits[0],(unsigned char *)afStack_350.value);
                }
                temp_v21 = func_0044b920(dot);
              }
              if (temp_v21 * 2.0f <= fGpffff8068 * *(float *)(controller + 6)) {
                *(ControllerQuat *)(controller + 8) = blendedRotation;
              }
              else {
                temp_v21 = 1.0f - fGpffff806c / (temp_v21 * 2.0f);
                func_003dcc70((struct RtQuat *)(&blendedRotation.value[0]),(struct RtQuat *)(&fallbackRotation.bits[0]),(struct RtQuatSlerpCache *)(&interpolation.from[0]));
                if (temp_v21 <= 0.0f) {
                  *(ControllerQuat *)(controller + 8) = blendedRotation;
                }
                else if (1.0f <= temp_v21) {
                  *(ControllerQuat *)(controller + 8) = fallbackRotation;
                }
                else {
                  f32 fromWeight = 1.0f - temp_v21;
                  f32 toWeight = temp_v21;
                  if (interpolation.nearlyZero == 0) {
                    fromWeight = fromWeight * interpolation.omega;
                    {
                      const f32 z = fromWeight * fromWeight;
                      f32 polynomial = fGpffff8070 * z + fGpffff8054;
                      polynomial = z * polynomial + fGpffff8058;
                      polynomial = z * polynomial + fGpffff805c;
                      polynomial = z * polynomial + fGpffff8060;
                      polynomial = z * polynomial + fGpffff8064;
                      fromWeight = z * fromWeight * polynomial + fromWeight;
                    }
                    toWeight = toWeight * interpolation.omega;
                    {
                      const f32 z = toWeight * toWeight;
                      f32 polynomial = fGpffff8070 * z + fGpffff8054;
                      polynomial = z * polynomial + fGpffff8058;
                      polynomial = z * polynomial + fGpffff805c;
                      polynomial = z * polynomial + fGpffff8060;
                      polynomial = z * polynomial + fGpffff8064;
                      toWeight = z * toWeight * polynomial + toWeight;
                    }
                  }
                  *(float *)(controller + 8) = interpolation.from[0] * fromWeight;
                  *(float *)(controller + 10) = interpolation.from[1] * fromWeight;
                  *(float *)(controller + 0xc) = interpolation.from[2] * fromWeight;
                  *(float *)(controller + 8) = *(float *)(controller + 8) + interpolation.to[0] * toWeight;
                  *(float *)(controller + 10) = *(float *)(controller + 10) + interpolation.to[1] * toWeight;
                  *(float *)(controller + 0xc) = *(float *)(controller + 0xc) + interpolation.to[2] * toWeight;
                  *(float *)(controller + 0xe) = interpolation.from[3] * fromWeight + interpolation.to[3] * toWeight;
                }
              }
            } else {
              *(ControllerQuat *)(controller + 8) = blendedRotation;
            }
          }
        }
        if (puVar3 == (unsigned int *)0x0) {
          if (param_4 == 0) {
            {
              const ControllerQuat *controllerRotation = (const ControllerQuat *)(controller + 8);
              RwV3d scaled;
              RwV3d realScaled;
              RwV3d square;
              RwV3d cross;
              f32 scale = 2.0f / (controllerRotation->value[3] * controllerRotation->value[3] +
                  ((controllerRotation->value[0] * controllerRotation->value[0] +
                    controllerRotation->value[1] * controllerRotation->value[1]) +
                    controllerRotation->value[2] * controllerRotation->value[2]));
              scaled.x = controllerRotation->value[0] * scale;
              scaled.y = controllerRotation->value[1] * scale;
              scaled.z = controllerRotation->value[2] * scale;
              realScaled.x = scaled.x * controllerRotation->value[3];
              realScaled.y = scaled.y * controllerRotation->value[3];
              realScaled.z = scaled.z * controllerRotation->value[3];
              square.x = controllerRotation->value[0] * scaled.x;
              square.y = controllerRotation->value[1] * scaled.y;
              square.z = controllerRotation->value[2] * scaled.z;
              cross.x = controllerRotation->value[1] * scaled.z;
              cross.y = controllerRotation->value[2] * scaled.x;
              cross.z = controllerRotation->value[0] * scaled.y;
              ((RwMatrix *)pfVar8)->right.x = 1.0f - (square.y + square.z);
              ((RwMatrix *)pfVar8)->right.y = cross.z + realScaled.z;
              ((RwMatrix *)pfVar8)->right.z = cross.y - realScaled.y;
              ((RwMatrix *)pfVar8)->up.x = cross.z - realScaled.z;
              ((RwMatrix *)pfVar8)->up.y = 1.0f - (square.z + square.x);
              ((RwMatrix *)pfVar8)->up.z = cross.x + realScaled.x;
              ((RwMatrix *)pfVar8)->at.x = cross.y + realScaled.y;
              ((RwMatrix *)pfVar8)->at.y = cross.x - realScaled.x;
              ((RwMatrix *)pfVar8)->at.z = 1.0f - (square.x + square.y);
              ((RwMatrix *)pfVar8)->pos.x = 0.0f;
              ((RwMatrix *)pfVar8)->pos.y = 0.0f;
              ((RwMatrix *)pfVar8)->pos.z = 0.0f;
              ((RwMatrix *)pfVar8)->flags = 3;
            }
            /* Retail snapshots all controller-scale components before use:
             * 00472638-0047264c and 004727a0-004727b4. */
            workingVector = *(const RwV3d *)(controller + 0x18);
            if ((*modelState & 0x10) != 0) {
              /* Retail combines model scale and aspect before scaling Y/Z. */
              f32 modelScale = DAT_00922bb0[0];
              workingVector.x = workingVector.x * modelScale;
              modelScale = modelScale * DAT_00922bb4[0];
              workingVector.y = workingVector.y * modelScale;
              workingVector.z = workingVector.z * modelScale;
            }
            RwMatrixScale((RwMatrix *)(pfVar8),(const RwV3d *)(&workingVector),(RwOpCombineType)(1));
            *(RwV3d *)&pfVar8[0xc] = position;
          }
          else {
            {
              const ControllerQuat *controllerRotation = (const ControllerQuat *)(controller + 8);
              RwV3d scaled;
              RwV3d realScaled;
              RwV3d square;
              RwV3d cross;
              f32 scale = 2.0f / (controllerRotation->value[3] * controllerRotation->value[3] +
                  ((controllerRotation->value[0] * controllerRotation->value[0] +
                    controllerRotation->value[1] * controllerRotation->value[1]) +
                    controllerRotation->value[2] * controllerRotation->value[2]));
              scaled.x = controllerRotation->value[0] * scale;
              scaled.y = controllerRotation->value[1] * scale;
              scaled.z = controllerRotation->value[2] * scale;
              realScaled.x = scaled.x * controllerRotation->value[3];
              realScaled.y = scaled.y * controllerRotation->value[3];
              realScaled.z = scaled.z * controllerRotation->value[3];
              square.x = controllerRotation->value[0] * scaled.x;
              square.y = controllerRotation->value[1] * scaled.y;
              square.z = controllerRotation->value[2] * scaled.z;
              cross.x = controllerRotation->value[1] * scaled.z;
              cross.y = controllerRotation->value[2] * scaled.x;
              cross.z = controllerRotation->value[0] * scaled.y;
              (&localMatrix)->right.x = 1.0f - (square.y + square.z);
              (&localMatrix)->right.y = cross.z + realScaled.z;
              (&localMatrix)->right.z = cross.y - realScaled.y;
              (&localMatrix)->up.x = cross.z - realScaled.z;
              (&localMatrix)->up.y = 1.0f - (square.z + square.x);
              (&localMatrix)->up.z = cross.x + realScaled.x;
              (&localMatrix)->at.x = cross.y + realScaled.y;
              (&localMatrix)->at.y = cross.x - realScaled.x;
              (&localMatrix)->at.z = 1.0f - (square.x + square.y);
              (&localMatrix)->pos.x = 0.0f;
              (&localMatrix)->pos.y = 0.0f;
              (&localMatrix)->pos.z = 0.0f;
              (&localMatrix)->flags = 3;
            }
            /* Retail snapshots all controller-scale components before use:
             * 00472638-0047264c and 004727a0-004727b4. */
            workingVector = *(const RwV3d *)(controller + 0x18);
            if ((*modelState & 0x10) != 0) {
              /* Retail combines model scale and aspect before scaling Y/Z. */
              f32 modelScale = DAT_00922bb0[0];
              workingVector.x = workingVector.x * modelScale;
              modelScale = modelScale * DAT_00922bb4[0];
              workingVector.y = workingVector.y * modelScale;
              workingVector.z = workingVector.z * modelScale;
            }
            RwMatrixScale((RwMatrix *)(&localMatrix.right.x),(const RwV3d *)(&workingVector),(RwOpCombineType)(1));
            localMatrix.pos = position;
            RwMatrixMultiply((RwMatrix *)(pfVar8),(const RwMatrix *)(&localMatrix.right.x),(const RwMatrix *)(param_4));
          }
          if (((*(int *)(uStack_430 + 0xc) != 0) &&
              (temp_v7 = *(int *)(*(int *)(uStack_430 + 0xc) + 4), temp_v7 != 0)) &&
             ((*(unsigned char *)(*(int *)(temp_v7 + 0xa0) + 3) & 1) != 0)) {
            func_003ed960(*(u8 **)(temp_v7 + 0xa0));
          }
        }
        else {
          RwMatrixMultiply((RwMatrix *)(pfVar8),(const RwMatrix *)(&frameMatrix.right.x),(const RwMatrix *)(pfVar21));
        }
      }
        break;
      default:
      {
        RwMatrixMultiply((RwMatrix *)(pfVar8),(const RwMatrix *)(&frameMatrix.right.x),(const RwMatrix *)(pfVar21));
      }
        break;
      }
      temp_v7 = *(int *)(uStack_430 + 0xc);
      if (temp_v7 != 0) {
        if ((temp_v10 & 0x1000) != 0) {
          *(RwMatrix *)(temp_v7 + 0x10) = frameMatrix;
          if (temp_v3 == 0) {
            func_003e9680((u8 *)(temp_v7));
          }
        }
        if (temp_v3 != 0) {
          if ((temp_v10 & 0x4000) != 0) {
            RwMatrixMultiply((RwMatrix *)(temp_v7 + 0x50),(const RwMatrix *)(pfVar8),(const RwMatrix *)(((f32 *)&baseMatrix)));
          } else {
            *(RwMatrix *)(temp_v7 + 0x50) = *(const RwMatrix *)pfVar8;
          }
          *(unsigned char *)(temp_v7 + 3) = (*(unsigned char *)(temp_v7 + 3) & ~4) | 8;
        }
      }
      /* HAnim node parent-stack control: POP=1, PUSH=2. Both bits leave
       * the parent unchanged; retail dispatch 0047298c-004729f0. */
      switch (*(unsigned int *)(uStack_430 + 8) & 3) {
      case 0:
        pfVar21 = pfVar8;
        break;
      case 1:
        puVar22--;
        pfVar21 = (float *)*puVar22;
        break;
      case 2:
        *puVar22++ = (unsigned int)pfVar21;
        pfVar21 = pfVar8;
        break;
      case 3:
        break;
      }
      temp_v11 = temp_v11 + temp_v9;
      pfVar8 = pfVar8 + 0x10;
      uStack_430 = uStack_430 + 0x10;
    }
    if ((puVar3 != (unsigned int *)0x0) && ((*controller & 0x81e0) != 0)) {
      if (*(u16 *)((u8 *)puVar3 + 0x42) == 0) {
        for (temp_v10 = 0; temp_v10 < 4; temp_v10 = temp_v10 + 1) {
          unsigned int *slot = puVar3 + temp_v10;
          unsigned int *interp = slot + 4;

          temp_v5 = (unsigned int)func_003d5790((int)puVar12[1], (int)*(unsigned int *)(puVar12[8] + 0x20));
          *interp = temp_v5;
          func_003d5840((RtAnimInterpolator *)((void *)temp_v5),(RtAnimAnimation *)((void *)*slot));
        }
        *(u16 *)((u8 *)puVar3 + 0x42) = 1;
      }
      if (resetAnimation) {
        puVar3[0xc] = 0x3f800000;
        puVar3[0x12] = 0;
      }
      /* Preserve retail's less-than test and unordered fallback selection. */
      if ((!(*(float *)&puVar3[0xe] < 1.0f)) ||
         (pbVar19 = *(unsigned char **)(modelState + 0x14), pbVar19 == (unsigned char *)0x0)) {
        pbVar19 = (unsigned char *)puVar12[8];
        temp_v21 = *(float *)(pbVar19 + 4);
      }
      else {
        temp_v4 = (short)modelState[2] * 0x50;
        piVar4 = *(int **)(**(int **)(modelState + 0x1a) + 0x4c + temp_v4);
        if (piVar4 == (int *)0x0) {
          temp_v21 = 0.0f;
        }
        else {
          temp_v21 = fGpffff8040 * (float)*piVar4;
        }
      }
      forwardAxis[0] = 0;
      forwardAxis[1] = 0;
      forwardAxis[2] = 0x3f800000;
      if ((*controller & 0x100) == 0) {
        RtQuatTransformVectors((RwV3d *)(&direction[0]),(const RwV3d *)(&forwardAxis[0]),(s32)(1),(const struct RtQuat *)(controller + 8));
        /* Complete orientation snapshot, retail 00472b78-00472b94. */
        *(ControllerQuat *)(puVar3 + 8) = *(const ControllerQuat *)(controller + 8);
      }
      else {
        RtQuatTransformVectors((RwV3d *)(&direction[0]),(const RwV3d *)(&forwardAxis[0]),(s32)(1),(const struct RtQuat *)(puVar3 + 8));
      }
      func_003e0960((RwMatrix *)(temp_v22),(const RwMatrix *)(((f32 *)&baseMatrix)));
      func_003e4320((RwV3d *)(&direction[0]),(const RwV3d *)(&direction[0]),(const RwMatrix *)(temp_v22));
      RwV3dNormalize((RwV3d *)(&direction[0]),(const RwV3d *)(&direction[0]));
      temp_v20 = (float)*(u16 *)((u8 *)puVar3 + 0x3e) / *(float *)(controller + 6);
      if (!(direction[0] < 0.0f)) {
        func_003d5840((RtAnimInterpolator *)(puVar3[5]),(RtAnimAnimation *)(puVar3[1]));
        func_003d5e40((unsigned char *)puVar3[5],temp_v21);
        func_003d5e90((unsigned char *)puVar3[6],pbVar19,(unsigned char *)puVar3[5],direction[0] / temp_v20);
        temp_v9 = 2;
      }
      else {
        func_003d5840((RtAnimInterpolator *)(puVar3[6]),(RtAnimAnimation *)(puVar3[2]));
        func_003d5e40((unsigned char *)puVar3[6],temp_v21);
        func_003d5e90((unsigned char *)puVar3[5],pbVar19,(unsigned char *)puVar3[6],-direction[0] / temp_v20);
        temp_v9 = 1;
      }
      if (!(direction[1] < 0.0f)) {
        func_003d5840((RtAnimInterpolator *)(puVar3[7]),(RtAnimAnimation *)(puVar3[3]));
        func_003d5e40((unsigned char *)puVar3[7],temp_v21);
        func_003d5e90((unsigned char *)puVar3[4],(unsigned char *)puVar3[temp_v9 + 4],(unsigned char *)puVar3[7],direction[1]);
        puVar3[0x11] = 0;
      }
      else {
        func_003d5840((RtAnimInterpolator *)(puVar3[4]),(RtAnimAnimation *)(*puVar3));
        func_003d5e40((unsigned char *)puVar3[4],temp_v21);
        func_003d5e90((unsigned char *)puVar3[7],(unsigned char *)puVar3[temp_v9 + 4],(unsigned char *)puVar3[4],-direction[1]);
        puVar3[0x11] = 3;
      }
      /* Preserve retail's less-than test and unordered fallback selection. */
      if ((*(float *)&puVar3[0xe] < 1.0f) && (*(unsigned char **)(modelState + 0x12) != (unsigned char *)0x0)) {
        func_003d5e90((unsigned char *)puVar12[8],*(unsigned char **)(modelState + 0x12),(unsigned char *)puVar3[puVar3[0x11] + 4]
                      ,*(float *)&puVar3[0xe]);
        /* func_004740c0 stores blend duration as f32 at control+0x34;
         * retail 00472dd0-00472de0 loads it directly without integer conversion. */
        temp_v20 = *(float *)&puVar3[0xd];
        temp_v20 = 1.0f / temp_v20;
        *(float *)&puVar3[0xe] = *(float *)&puVar3[0xe] + temp_v20;
        puVar3[0xc] = 0;
      }
      else {
        if ((*(u16 *)controller & 0x100) == 0) {
          *(float *)&puVar3[0xc] = *(float *)&puVar3[0xc] * (1.0f - *(float *)(controller + 2));
          puVar3[0x12] = 0x3f800000;
          func_003d5e90((unsigned char *)puVar12[8],(unsigned char *)puVar12[8],(unsigned char *)puVar3[puVar3[0x11] + 4],
                        1.0f - *(float *)&puVar3[0xc]);
        }
        else {
          *(float *)&puVar3[0x12] = *(float *)&puVar3[0x12] * (1.0f - *(float *)(controller + 2));
          func_003d5e90((unsigned char *)puVar12[8],(unsigned char *)puVar12[8],(unsigned char *)puVar3[puVar3[0x11] + 4],
                        *(float *)&puVar3[0x12]);
          if (*(float *)&puVar3[0x12] < fGpffff8074) {
            *(u16 *)controller = *(u16 *)controller & 0x7e1f;
            *(u16 *)controller = *(u16 *)controller & 0xfbff;
          }
          *(u16 *)controller = *(u16 *)controller & 0xf7ff;
        }
      }
      func_00397c40(param_1);
    }
  }
  return 1;
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00471370);
#endif
#pragma pop
/* The controller remains a research-only NONMATCHING candidate. */

extern s32 func_00397c40(void* hierarchy);
extern s32 func_00471370(u8 *a, u8 *b, u8 *c, void *d);
// FUN_00472F30
void func_00472f30(u8* param_1, int param_2)
{
    if (*(s32*)DAT_00922ba8_abs == param_2) {
        *(float*)(param_2 + 0x18) = *(float*)(param_2 + 0x18) * *(*(float**)DAT_00922bac_abs);
        *(float*)(param_2 + 0x1c) = *(float*)(param_2 + 0x1c) * (*(float**)DAT_00922bac_abs)[1];
        *(float*)(param_2 + 0x20) = *(float*)(param_2 + 0x20) * (*(float**)DAT_00922bac_abs)[2];
    }
    (*DAT_00922ba0_abs)(param_1, param_2);
    if (*(s32*)DAT_00922ba4_abs == param_2) {
        RwMatrixScale((void*)param_1, (const RwV3d*)*(float**)DAT_00922bac_abs, 1);
    }
    return;
}




// FUN_00473000
void func_00473000(u8* arg0, u8* arg1)
{
    u8* p5;
    u8* obj;
    u8* obj2;
    s32 count;
    s32 base;

    p5 = arg1 + 0x3C;
    obj = *(u8**)(arg0 + 0x20);
    if (obj != 0) {
        *(s32*)DAT_00922ba0_abs = *(s32*)(obj + 0x3C);
        *(s32*)(obj + 0x3C) = (s32)func_00472f30;
        obj2 = *(u8**)(arg0 + 0x20);
        count = *(s32*)(obj2 + 0x24);
        base = (s32)obj2 + 0x4C;
        *(s32*)DAT_00922ba4_abs = base;
        base = base + count * *(s32*)(p5 + 0);
        *(s32*)DAT_00922ba4_abs = base;
        if (*(f32*)(arg1 + 8) != 0.0f) {
            *(s32*)DAT_00922ba8_abs = base;
        } else {
            *(s32*)DAT_00922ba8_abs = 0;
        }
        *(float**)DAT_00922bac_abs = (float*)(p5 + 4);
        *(f32*)D_00922BB0_abs = *(f32*)(p5 + 0x10);
        *(f32*)D_00922BB4_abs = *(f32*)(p5 + 0x14);
        if ((*(u16*)(arg1 + 0x54) & 0x81E0) != 0) {
            func_00471370(arg0, arg1, arg1 + 0x54, 0);
            *(u16*)(arg1 + 0x54) |= 0x4000;
        } else {
            func_00397c40(arg0);
            *(u16*)(arg1 + 0x54) &= 0xBFFF;
        }
        *(s32*)(*(u8**)(arg0 + 0x20) + 0x3C) = *(s32*)DAT_00922ba0_abs;
    }
}
// FUN_00473140
void func_00473140(int param_1)
{
    u32 uVar1;
    u32 uVar2;

    uVar2 = RpMatFXMaterialGetEffects();
    switch (uVar2) {
    case 1:
        uVar1 = func_0039b6e0(0x10021);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 2:
        uVar1 = func_0039b6e0(0x10022);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 3:
        uVar1 = func_0039b6e0(0x10023);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 4:
        uVar1 = func_0039b6e0(0x10024);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 5:
        uVar1 = func_0039b6e0(0x1002a);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 6:
        uVar1 = func_0039b6e0(0x1002b);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    default:
        uVar1 = func_0039b6e0(0x10020);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    }

    return;
}



// FUN_00473250
void* func_00473250(void* param_1, void* data)
{
    int iVar1;
    u32 uVar2;
    u32 lVar3;
    u32 uVar4;
    u8* iVar5;
    int iVar6;

    iVar5 = param_1;
    iVar1 = *(int*)(iVar5 + 0x18);
    if (iVar1 == 0) {
        return param_1;
    }

    lVar3 = func_003b83f0(iVar1);
    if (lVar3 == 0) {
        return param_1;
    }

    uVar4 = func_003b8500(lVar3);
    if (uVar4 <= 0x40) {
        return param_1;
    }

    if (param_1 != 0) {
        uVar2 = func_0039b6e0(0x1001f);
        *(u32*)(iVar5 + 0x6c) = uVar2;
        iVar5 = *(u8**)(iVar5 + 0x18);
        iVar1 = *(int*)(iVar5 + 0x24);
        for (iVar6 = 0; iVar6 < iVar1; iVar6 = iVar6 + 1) {
            func_00473140(*(u32*)(*(u8**)(iVar5 + 0x20) + iVar6 * 4));
        }
        return param_1;
    }

    return param_1;
}




// FUN_00473350
void* func_00473350(void* arg0, u8* arg1)
{
    s16 rawIndex;
    s64 lVar2;
    u16 count;
    s32* t3;
    s32 off;
    u8* elem;
    void* p38;
    void* v;
    void* t;
    u8* p;
    f32 c;

    rawIndex = *(s16*)(arg1 + 4);
    t3 = *(s32**)(arg1 + 0x34);
    if (t3 != 0 &&
        (lVar2 = (s64)rawIndex, count = *(u16*)((u8*)t3 + 8),
         lVar2 < (s64)(u32)count) &&
        (off = rawIndex * 0x50, elem = *(u8**)(*(s32*)((u8*)t3 + 0) + 0x40 + off)) != 0 &&
        elem != D_00922BC0_abs) {
        if (!(*(u16*)(arg1 + 0) & 1)) {
            if (lVar2 < (s64)(u32)count && rawIndex >= 0) {
                t = *(void**)((u8*)*(void**)(arg1 + 0x20) + 0x20);
                func_003d5e40_typed(*(f32*)(elem + 0xC), t);
                *(u8*)(arg1 + 2) = 1;
            }
        } else {
            p38 = *(void**)(arg1 + 0x38);
            if (p38 != 0) {
                if (*(s32*)((u8*)p38 + 0x18) != 0) {
                    func_0047d840(*(s32*)((u8*)p38 + 0x18), rawIndex);
                }
                if (*(s32*)((u8*)p38 + 0x24) != 0) {
                    func_0047dda0(*(s32*)((u8*)p38 + 0x24));
                }
            }
            t = *(void**)((u8*)*(void**)(arg1 + 0x20) + 0x20);
            RtAnimInterpolatorSetAnimLoopCallBack(t, 0, 0);
            c = iGpffff8040;
            *(f32*)(arg1 + 0xC) = c * *(f32*)(arg1 + 8);
            p = (u8*)*(s32*)((u8*)*(s32**)(arg1 + 0x34) + 0);
            p += 0x4C;
            p += off;
            v = *(void**)p;
            if (v != 0) {
                *(f32*)(arg1 + 0xC) = *(f32*)(arg1 + 0xC) + c * (f32)(s32)*(s32*)v;
            }
            t = *(void**)((u8*)*(void**)(arg1 + 0x20) + 0x20);
            func_003d5e40_typed(*(f32*)(arg1 + 0xC), t);
            t = *(void**)((u8*)*(void**)(arg1 + 0x20) + 0x20);
            RtAnimInterpolatorSetAnimLoopCallBack(t, func_00473350, arg1);
        }
    } else if (*(u16*)(arg1 + 0) & 1) {
        *(f32*)(arg1 + 0xC) = 0.0f;
    }
    return arg0;
}

// FUN_00473520
void func_00473520(void* param_1)
{
    memset(param_1, 0, 0xA4);
    *(u8*)((u8*)param_1 + 2) = 1;
    *(s16*)((u8*)param_1 + 4) = -1;
    *(f32*)((u8*)param_1 + 8) = 1.0f;
    *(u32*)((u8*)param_1 + 0xC) = 0;
    *(s16*)((u8*)param_1 + 0x10) = -1;
    *(f32*)((u8*)param_1 + 0x1C) = 1.0f;
    *(f32*)((u8*)param_1 + 0x58) = DAT_0076112c;
    *(u32*)((u8*)param_1 + 0x64) = 0;
    *(u32*)((u8*)param_1 + 0x68) = 0;
    *(u32*)((u8*)param_1 + 0x6C) = 0;
    *(f32*)((u8*)param_1 + 0x70) = 1.0f;
    *(f32*)((u8*)param_1 + 0x5C) = 70.0f;
    *(f32*)((u8*)param_1 + 0x60) = 80.0f;
    *(u16*)((u8*)param_1 + 0x54) = 0;
    *(f32*)((u8*)param_1 + 0x84) = 1.0f;
    *(f32*)((u8*)param_1 + 0x88) = 1.0f;
    *(f32*)((u8*)param_1 + 0x8C) = 1.0f;
}

/* measured: retail allocates q=$s0, i=$s1, arg0=$s2, i*4=$s3; mwcc b210
   rotates to i*4=$s0, q=$s2, arg0=$s3 (25 words, all register names; u8*
   param typing fixed the arg0+0x38 address-CSE frame growth, nd 81 -> 25).
   Tried: q,i,idx and i,q,idx declaration orders (25/28), idx named local.
   Saved-register rotation floor. */
/* MATCHED this wave (nd 0, was 25). Levers: (4) opt_propagation off forces the
   early obj[0x14]/obj[0x20] base load before the i*4 chain (FLYDraw), and
   declaring the loop counter i BEFORE obj steers allocation to retail's
   obj=$s0/i=$s1 (pure statement-order, cf FLYList). i*4 kept as a separate
   local named j. */
// FUN_004735B0
#pragma opt_propagation off
void func_004735b0(u8 *arg0)
{
    u32 i;
    u32 *obj;
    u32 *p;
    u32 j;
    u32 base;

    obj = *(u32**)(arg0 + 0x38);
    if (obj != 0)
    {
        i = 0;
        while (i < *obj)
        {
            base = *(u32*)((u8*)obj + 0x14);
            j = i * 4;
            p = (u32*)(base + j);
            if (*p != 0)
            {
                func_0047d2d0(*p);
            }
            base = *(u32*)((u8*)obj + 0x20);
            p = (u32*)(base + j);
            if (*p != 0)
            {
                func_0047dcc0(*p);
            }
            i++;
        }
        DAT_008873ec[0](obj);
        *(u32**)(arg0 + 0x38) = 0;
    }
    if (*(u32*)(arg0 + 0x24) != 0)
    {
        func_003d5830(*(u32*)(arg0 + 0x24));
        *(u32*)(arg0 + 0x24) = 0;
    }
    if (*(u32*)(arg0 + 0x28) != 0)
    {
        func_003d5830(*(u32*)(arg0 + 0x28));
        *(u32*)(arg0 + 0x28) = 0;
    }
    if (*(u32*)(arg0 + 0x2C) != 0)
    {
        func_003d5830(*(u32*)(arg0 + 0x2C));
        *(u32*)(arg0 + 0x2C) = 0;
    }
    if (*(u32*)(arg0 + 0x30) != 0)
    {
        func_003d5830(*(u32*)(arg0 + 0x30));
        *(u32*)(arg0 + 0x30) = 0;
    }
    if (*(u32*)(arg0 + 0x34) != 0)
    {
        func_00471010((u8*)*(u32*)(arg0 + 0x34));
        *(u32*)(arg0 + 0x34) = 0;
    }
    if ((*(u16*)(arg0 + 0) & 2) != 0)
    {
        if (*(u32*)(arg0 + 0x20) != 0)
        {
            func_00397120(*(u32*)(arg0 + 0x20));
            *(u32*)(arg0 + 0x20) = 0;
        }
    }
}
#pragma opt_propagation on
/* MATCH: 340B/352B; the remaining 12 bytes are zero tail padding.
   IDA preserves a hierarchy snapshot separately from the escaped output slot.
   Typed object fields and pointer-valued traversal data retain the retail
   reloads, frame address lifetime, and argument evaluation order. */
// FUN_00473710
void func_00473710(u8 *arg0, u8 *arg1, s32 arg2)
{
    typedef struct MdlHierarchyView {
        u32 flags;
        s32 numNodes;
        u8 unknown08[0x18];
        RtAnimInterpolator *interpolator;
    } MdlHierarchyView;
    typedef struct MdlAnimationSource {
        u32 unknown00;
        RtAnimAnimation *animation;
    } MdlAnimationSource;
    typedef struct MdlAttachState {
        u16 flags;
        u8 unknown02[0x1e];
        MdlHierarchyView *hierarchy;
        u8 unknown24[8];
        RtAnimInterpolator *first;
        RtAnimInterpolator *second;
        MdlAnimationSource *source;
    } MdlAttachState;
    typedef struct MdlClumpView {
        u8 header[4];
        u8 *frame;
    } MdlClumpView;
    MdlAttachState *model = (MdlAttachState *)arg0;
    MdlHierarchyView *selected;
    u32 hierarchy = 0;
    u8 **frame = &((MdlClumpView *)arg1)->frame;

    func_003e9af0(*frame, func_004711e0, &hierarchy);
    selected = (MdlHierarchyView *)hierarchy;
    model->hierarchy = selected;
    func_003bff30(arg1, func_00471250, selected);
    if (arg2 != 0)
        func_003bff30(arg1, func_00473250, *frame);
    func_004633c0(arg1, model->hierarchy);
    model->hierarchy->flags |= 0x3000;
    if (model->source != 0 && model->source->animation != 0) {
        model->first = (RtAnimInterpolator *)func_003d5790(
            model->hierarchy->numNodes,
            model->hierarchy->interpolator->maxInterpKeyFrameSize);
        model->second = (RtAnimInterpolator *)func_003d5790(
            model->hierarchy->numNodes,
            model->hierarchy->interpolator->maxInterpKeyFrameSize);
        func_003d5840(model->first, model->source->animation);
        func_003d5840(model->second, model->source->animation);
        func_003d5e40((u8 *)model->second, 0.0f);
        model->flags |= 0x80;
    }
}
extern s32 func_003d5bc0(void* a, f32 b);

/* measured: probing opt_loop_invariants on for loop-constant placement. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00473870
void func_00473870(u8 *arg0)
{
    typedef struct
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } MdlQuat;
    typedef struct
    {
        u8 pad0[8];
        MdlQuat quat;
        f32 values[6];
    } MdlBlendRecord;
    u8 *obj;
    u8 *base2;
    u8 *base1;
    u8 *base0;
    MdlBlendRecord *out;
    MdlBlendRecord *input;
    MdlBlendRecord *rotation;
    s32 i;
    s32 count;
    f32 one;
    f32 zero;
    f32 norm;
    f32 inverse;
    f32 rawY;
    f32 rawX;
    f32 rawZ;
    f32 rawW;
    f32 normW;
    f32 normX;
    f32 normY;
    f32 normZ;
    f32 inputY;
    f32 inputX;
    f32 inputZ;
    f32 inputW;
    f32 quatW;
    f32 crossX;
    f32 crossY;
    f32 crossZ;
    f32 quatX;
    f32 quatY;
    f32 quatZ;
    MdlQuat savedQuat;
    f32 diff1;
    f32 diff2;
    f32 diff0;

    obj = *(u8 **)(arg0 + 0x2C);
    if ((obj != 0) && ((*(u16 *)arg0 & 0x80) != 0))
    {
        func_003d5bc0(obj, iGpffff8040);
        count = *(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0x20) + 0x20) + 0x2C);
        for (i = 0, one = 1.0f, zero = 0.0f; i < count; i++)
        {
            base2 = *(u8 **)(*(u8 **)(arg0 + 0x20) + 0x20);
            out = (MdlBlendRecord *)(addOff(i * *(s32 *)(base2 + 0x24),
                                             (u32)base2) + 0x4C);
            base1 = *(u8 **)(arg0 + 0x2C);
            input = (MdlBlendRecord *)(addOff(i * *(s32 *)(base1 + 0x24),
                                               (u32)base1) + 0x4C);
            base0 = *(u8 **)(arg0 + 0x30);
            rotation = (MdlBlendRecord *)(addOff(i * *(s32 *)(base0 + 0x24),
                                                  (u32)base0) + 0x4C);
            rawY = rotation->quat.y;
            rawX = rotation->quat.x;
            rawZ = rotation->quat.z;
            rawW = rotation->quat.w;
            norm = rawY * rawY;
            norm += rawX * rawX;
            norm += rawZ * rawZ;
            norm += rawW * rawW;
            if (norm > zero)
            {
                inverse = one / norm;
                normW = rawW * inverse;
                inverse = -inverse;
                normX = rawX * inverse;
                normY = rawY * inverse;
                normZ = rawZ * inverse;
            }
            inputY = input->quat.y;
            inputX = input->quat.x;
            inputZ = input->quat.z;
            inputW = input->quat.w;

            quatW = normW * inputW -
                    (normX * inputX +
                     normY * inputY +
                     normZ * inputZ);
            crossX = normY * inputZ - normZ * inputY;
            crossY = normZ * inputX - normX * inputZ;
            crossZ = normX * inputY - normY * inputX;
            crossX = crossX + inputX * normW;
            crossY = crossY + inputY * normW;
            crossZ = crossZ + inputZ * normW;
            quatX = crossX + normX * inputW;
            quatY = crossY + normY * inputW;
            quatZ = crossZ + normZ * inputW;

            savedQuat = *(MdlQuat *)&out->quat;
            out->quat.w = savedQuat.w * quatW -
                          (savedQuat.x * quatX +
                           savedQuat.y * quatY +
                           savedQuat.z * quatZ);
            out->quat.x = savedQuat.y * quatZ - savedQuat.z * quatY;
            out->quat.y = savedQuat.z * quatX - savedQuat.x * quatZ;
            out->quat.z = savedQuat.x * quatY - savedQuat.y * quatX;
            out->quat.x = out->quat.x + quatX * savedQuat.w;
            out->quat.y = out->quat.y + quatY * savedQuat.w;
            out->quat.z = out->quat.z + quatZ * savedQuat.w;
            out->quat.x = out->quat.x + savedQuat.x * quatW;
            out->quat.y = out->quat.y + savedQuat.y * quatW;
            out->quat.z = out->quat.z + savedQuat.z * quatW;

            diff1 = rotation->values[1] - input->values[1];
            diff2 = rotation->values[2] - input->values[2];
            diff0 = rotation->values[0] - input->values[0];
            out->values[0] = out->values[0] + diff0;
            out->values[1] = out->values[1] + diff1;
            out->values[2] = out->values[2] + diff2;
        }
    }
}
#pragma pop

extern void func_00473870(u8* a);
extern s32 func_003d5e90(void* a, void* b, void* c, f32 d);
/* Native b210 O2 MATCH: 1432B/window 1440B; the remaining eight bytes are zero.
   Narrow each animation index after its table guard, including the repeated
   sentinel fallback check. Keep the blend input separate from post-callback
   increments, and share only the actual count, sentinel and conversion inputs. */
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
// FUN_00473B20
u8 *func_00473b20(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 idx;
    u8 *table;
    u8 *animation;
    u8 *animationBase;
    s32 offset;
    s32 selectedIndex;
    s64 count;
    f32 elapsed;
    f32 duration;
    f32 one;
    f32 step;
    f32 progress;
    f32 inputProgress;
    f32 fallbackDuration;
    f32 fallbackStep;
    f32 frameScale;
    f32 frameOffset;
    f32 frameTime;
    u32 flags;
    u8 *emptyAnimation;
    void *currentInterpolator;

    idx = *(s16 *)(arg0 + 4);
    if (idx < 0) {
        return arg1;
    }
    if (arg0[2] == 1) {
        table = *(u8 **)(arg0 + 0x34);
        if (table != 0 && idx < *(u16 *)(table + 8)) {
            offset = idx * 0x50;
            animation = *(u8 **)(*(u32 *)table + 0x40 + offset);
            if (animation != 0 && animation != (u8 *)D_00922BC0_abs) {
                if (table != 0 && *(u32 *)(table + 4) != 0) {
                    func_003d5e40(*(u8 **)(*(u8 **)(arg0 + 0x20) + 0x20),
                        *(f32 *)(arg0 + 0xC) - 1.0f);
                    func_003d5e40(*(u8 **)(*(u8 **)(arg0 + 0x20) + 0x20),
                        *(f32 *)(arg0 + 0xC));
                    func_00473870(arg0);
                }
                func_00397c40(*(void **)(arg0 + 0x20));
            }
        }
        return arg1;
    }
    elapsed = iGpffff8040 * *(f32 *)(arg0 + 8);
    if (!(elapsed <= 0.0f) || (*(u16 *)arg0 & 6) != 0) {
        inputProgress = *(f32 *)(arg0 + 0x1C);
        if (inputProgress < 1.0f) {
            table = *(u8 **)(arg0 + 0x34);
            if (table == 0) {
                goto advance_blend;
            }
            selectedIndex = (s16)idx;
            count = *(u16 *)(table + 8);
            if (selectedIndex >= count) {
                goto advance_blend;
            }
            offset = selectedIndex * 0x50;
            animationBase = *(u8 **)table + 0x40;
            animation = *(u8 **)(animationBase + offset);
            if (animation == 0) {
                goto advance_blend;
            }
            emptyAnimation = (u8 *)D_00922BC0_abs;
            if (animation == emptyAnimation) {
                goto advance_blend;
            }
            if (table == 0) {
                goto advance_blend;
            }
            selectedIndex = *(s16 *)(arg0 + 0x10);
            if (selectedIndex >= count) {
                goto advance_blend;
            }
            animation = *(u8 **)(animationBase + selectedIndex * 0x50);
            if (animation == 0 || animation == emptyAnimation) {
                goto advance_blend;
            }
            func_003d5e90(*(void **)(*(u8 **)(arg0 + 0x20) + 0x20),
                *(void **)(arg0 + 0x24), *(void **)(arg0 + 0x28),
                inputProgress);
            duration = (f32)(u32)*(u16 *)(arg0 + 0x18);
            one = 1.0f;
            step = one / duration;
            progress = *(f32 *)(arg0 + 0x1C) + step;
            *(f32 *)(arg0 + 0x1C) = progress;
            if (!(progress < one)) {
                func_003d5840(*(void **)(*(u8 **)(arg0 + 0x20) + 0x20),
                    *(void **)*(void **)(arg0 + 0x28));
                animation = *(u8 **)(*(u32 *)*(u8 **)(arg0 + 0x34) + 0x4C + offset);
                if (animation == 0) {
                    func_003d5e40(*(u8 **)(*(u8 **)(arg0 + 0x20) + 0x20), elapsed);
                } else {
                    frameScale = iGpffff8040;
                    frameOffset = (f32)*(s32 *)animation;
                    frameTime = elapsed + frameScale * frameOffset;
                    func_003d5e40(*(u8 **)(*(u8 **)(arg0 + 0x20) + 0x20), frameTime);
                }
            }
            goto finish_time;
advance_blend:
            fallbackDuration = (f32)(u32)*(u16 *)(arg0 + 0x18);
            fallbackStep = 1.0f / fallbackDuration;
            *(f32 *)(arg0 + 0x1C) = *(f32 *)(arg0 + 0x1C) + fallbackStep;
        } else {
            table = *(u8 **)(arg0 + 0x34);
            if (table != 0) {
                selectedIndex = (s16)idx;
                if (selectedIndex < (s64)(u32)*(u16 *)(table + 8)) {
                    offset = selectedIndex * 0x50;
                    animation = *(u8 **)(*(u32 *)table + 0x40 + offset);
                    if (animation != 0 && animation != (u8 *)D_00922BC0_abs) {
                        func_003d5bc0(*(void **)(*(u8 **)(arg0 + 0x20) + 0x20), elapsed);
                        goto finish_time;
                    }
                }
            }
            if (table == 0) {
                goto advance_clock;
            }
            selectedIndex = (s16)idx;
            if (selectedIndex >= (s64)(u32)*(u16 *)(table + 8)) {
                goto advance_clock;
            }
            animationBase = *(u8 **)table;
            offset = selectedIndex * 0x50;
            if (*(u8 **)(offset + (u32)animationBase + 0x40) == (u8 *)D_00922BC0_abs) {
                goto finish_time;
            }
advance_clock:
            *(f32 *)(arg0 + 0xC) = *(f32 *)(arg0 + 0xC) + elapsed;
        }
finish_time:
        *(u16 *)arg0 &= 0xFFFB;
    }
    table = *(u8 **)(arg0 + 0x34);
    if (table != 0) {
        selectedIndex = (s16)idx;
        if (selectedIndex < (s64)(u32)*(u16 *)(table + 8)) {
            offset = selectedIndex * 0x50;
            animation = *(u8 **)(*(u32 *)table + 0x40 + offset);
            if (animation != 0 && animation != (u8 *)D_00922BC0_abs) {
                if ((*(u16 *)arg0 & 2) != 0 && arg1 != 0) {
                    currentInterpolator = *(void **)(*(u8 **)(arg0 + 0x20) + 0x20);
                    func_00471280(currentInterpolator,
                        *(void **)(*(u8 **)(arg1 + 0x20) + 0x20),
                        currentInterpolator, 1.0f);
                }
                func_00473870(arg0);
                if (arg2 != 0) {
                    if ((*(u16 *)arg0 & 0x10) != 0) {
                        func_00473000(*(void **)(arg0 + 0x20), arg0);
                    } else if ((*(u16 *)(arg0 + 0x54) & 0x81E0) != 0) {
                        func_00471370(*(void **)(arg0 + 0x20), arg0, arg0 + 0x54, 0);
                    } else {
                        func_00397c40(*(void **)(arg0 + 0x20));
                    }
                }
                flags = *(u16 *)(arg0 + 0x54);
                if ((flags & 0x81E0) != 0) {
                    *(u16 *)(arg0 + 0x54) = flags | 0x4000;
                } else {
                    *(u16 *)(arg0 + 0x54) = flags & 0xBFFF;
                }
                *(f32 *)(arg0 + 0xC) = *(f32 *)(*(u8 **)(*(u8 **)(arg0 + 0x20) + 0x20) + 4);
            }
        }
    }
    return arg0;
}

#pragma pop
extern void func_003d59a0(void* a, void* b);
/* MATCH: 1320B instructions plus eight zero-tail bytes. Member-first
   field bases, signed promoted counts and separate attachment offsets
   preserve retail lifetimes. Reuse addOff for index-first address sums. */
typedef struct MdlDispatchAnimEntry {
    RwMatrix matrix;
    void* animation;
    u32 unknown44;
    u8* blendControl;
    s32* startFrame;
} MdlDispatchAnimEntry;

typedef struct MdlDispatchAnimTable {
    MdlDispatchAnimEntry* entries;
    u32 unknown;
    u16 count;
    u16 references;
} MdlDispatchAnimTable;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_004740C0
void func_004740c0(u8* layer, s16 animation, u16 blendTicks, s32 flags)
{
    u32 narrowFlags;
    s32 entryCount;
    void* missingClip;
    MdlDispatchAnimTable* table;
    u8* animationFields;
    s32 currentIndex;
    s32 currentOffset;
    s32 nextIndex;
    s32 nextOffset;
    void* clip;
    u8* hierarchy;
    RtAnimInterpolator* base;
    s32* startFrame;
    u8* control;
    u8* fieldBase;

    *(u16*)layer &= ~1u;
    narrowFlags = (u16)flags;
    *(u16*)layer |= narrowFlags & 1;
    layer[2] = 0;
    if ((u16)blendTicks > 0 &&
        (currentIndex = *(s16*)(layer + 4)) != -1 &&
        (table = *(MdlDispatchAnimTable**)(layer + 0x34)) != 0 &&
        currentIndex < (entryCount = table->count) &&
        (currentOffset = currentIndex * (s32)sizeof(MdlDispatchAnimEntry),
         animationFields = (u8*)table->entries + offsetof(MdlDispatchAnimEntry, animation),
         clip = *(void**)(animationFields + currentOffset)) != 0 &&
        clip != (missingClip = D_00922BC0_abs) &&
        table != 0 &&
        (nextIndex = (s16)animation) < entryCount &&
        (nextOffset = nextIndex * (s32)sizeof(MdlDispatchAnimEntry),
         clip = *(void**)(animationFields + nextOffset)) != 0 &&
        clip != missingClip) {
        if (*(RtAnimInterpolator**)(layer + 0x24) == 0) {
            hierarchy = *(u8**)(layer + 0x20);
            base = *(RtAnimInterpolator**)(hierarchy + 0x20);
            *(RtAnimInterpolator**)(layer + 0x24) = (RtAnimInterpolator*)
                func_003d5790(*(s32*)(hierarchy + 4), base->maxInterpKeyFrameSize);
        }
        if (*(RtAnimInterpolator**)(layer + 0x28) == 0) {
            hierarchy = *(u8**)(layer + 0x20);
            base = *(RtAnimInterpolator**)(hierarchy + 0x20);
            *(RtAnimInterpolator**)(layer + 0x28) = (RtAnimInterpolator*)
                func_003d5790(*(s32*)(hierarchy + 4), base->maxInterpKeyFrameSize);
        }
        func_003d5840(*(RtAnimInterpolator**)(layer + 0x24),
            (*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].animation);
        func_003d5840(*(RtAnimInterpolator**)(layer + 0x28),
            ((MdlDispatchAnimEntry*)(addOff((u32)nextOffset, (u32)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries)))->animation);
        table = *(MdlDispatchAnimTable**)(layer + 0x34);
        if (table == 0 || table->unknown == 0) {
            func_003d59a0(*(RtAnimInterpolator**)(layer + 0x24),
                *(RtAnimInterpolator**)(*(u8**)(layer + 0x20) + 0x20));
        } else {
            func_003d5e40(*(u8**)(layer + 0x24), *(f32*)(layer + 0x0c));
        }
        fieldBase = (u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries + offsetof(MdlDispatchAnimEntry, startFrame);
        startFrame = *(s32**)(fieldBase + nextOffset);
        if (startFrame != 0) {
            func_003d5e40(*(u8**)(layer + 0x28), iGpffff8040 * (f32)*startFrame);
        }
        *(s16*)(layer + 0x10) = *(s16*)(layer + 4);
        *(f32*)(layer + 0x14) = *(f32*)(layer + 0x0c);
        *(u16*)(layer + 0x18) = blendTicks;
        *(f32*)(layer + 0x1c) = 0.0f;
    } else {
        table = *(MdlDispatchAnimTable**)(layer + 0x34);
        if (table != 0 && (nextIndex = (s16)animation) < table->count &&
            (nextOffset = nextIndex * (s32)sizeof(MdlDispatchAnimEntry),
             animationFields = (u8*)table->entries + offsetof(MdlDispatchAnimEntry, animation),
             clip = *(void**)(animationFields + nextOffset)) != 0 &&
            clip != D_00922BC0_abs) {
            func_003d5840(*(RtAnimInterpolator**)(*(u8**)(layer + 0x20) + 0x20), clip);
            fieldBase = (u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries + offsetof(MdlDispatchAnimEntry, startFrame);
            startFrame = *(s32**)(fieldBase + nextOffset);
            if (startFrame == 0) {
                func_003d5e40(*(u8**)(*(u8**)(layer + 0x20) + 0x20), 0.0f);
            } else {
                func_003d5e40(*(u8**)(*(u8**)(layer + 0x20) + 0x20),
                    iGpffff8040 * (f32)*startFrame);
            }
            RtAnimInterpolatorSetAnimLoopCallBack(*(RtAnimInterpolator**)(*(u8**)(layer + 0x20) + 0x20),
                func_00473350, layer);
        }
        *(u16*)(layer + 0x18) = 0;
        *(f32*)(layer + 0x1c) = 1.0f;
    }
    *(u16*)(layer + 0x54) &= ~0x800u;
    if (*(u16*)(layer + 0x54) & 0x81e0) {
        currentOffset = *(s16*)(layer + 4) * (s32)sizeof(MdlDispatchAnimEntry);
        fieldBase = (u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries + offsetof(MdlDispatchAnimEntry, blendControl);
        control = *(u8**)(fieldBase + currentOffset);
        if (control != 0) {
            u32 one;
            *(f32*)(control + 0x34) = 0.0f;
            one = 0x3f800000; /* IEEE-754 1.0f, shared by the raw control fields. */
            *(u32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x38) = one;
            *(u32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x2c) = one;
            *(f32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x20) = 0.0f;
            *(f32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x24) = 0.0f;
            *(f32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x28) = 0.0f;
        }
        nextOffset = (s16)animation * (s32)sizeof(MdlDispatchAnimEntry);
        fieldBase = (u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries + offsetof(MdlDispatchAnimEntry, blendControl);
        control = *(u8**)(fieldBase + nextOffset);
        if (control != 0) {
            f32 fraction;
            *(f32*)(control + 0x34) = (f32)(u32)*(u16*)(layer + 0x18);
            fraction = *(f32*)(layer + 0x1c);
            *(f32*)(((MdlDispatchAnimEntry*)(addOff((u32)nextOffset, (u32)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries)))->blendControl + 0x38) = fraction;
        }
    }
    control = *(u8**)(layer + 0x38);
    if (control != 0) {
        nextOffset = (s16)animation * (s32)sizeof(void*);
        *(void**)(control + 0x1c) = *(void**)(*(u8**)(control + 0x14) + nextOffset);
        if (narrowFlags & 0x20) {
            clip = 0;
        } else {
            clip = *(void**)(*(u8**)(control + 0x20) + nextOffset);
        }
        *(void**)(control + 0x28) = clip;
        *(s32*)(control + 0x2c) = 1;
        *(u16*)(control + 0x30) = blendTicks;
    }
    *(f32*)(layer + 0x0c) = 0.0f;
    *(s16*)(layer + 4) = animation;
}
#pragma pop
// FUN_004745F0
void func_004745f0(MdlAnimEntryTable* table)
{
    u16 i;

    table->unk_06--;
    if (table->unk_06 == 0) {
        for (i = 0; i < table->count; i++) {
            MdlAnimResourceEntry* entry;

            entry = (MdlAnimResourceEntry*)table->entries;
            entry += i;

            if ((entry->resource != NULL) && ((entry->flags & 1) == 0)) {
                func_0047fa60((int)entry->resource);
            }
        }

        (*DAT_008873ec)(table);
    }
}




extern void func_0047ffc0(int *a);
extern void func_0047fd10(u8 **a, f32 b, u8 **c, f32 d, f32 e);
extern void func_0047fe90(u8 **a, f32 b, f32 c);
extern void func_0047fbf0(u8 **a, f32 b);
extern f32 func_00480060(u8 **a);
extern void* func_00473350(void* a, u8* b);
/* measured: u8* params fixed the param_2+0xC address-CSE (nd 106 -> 54) and
   the func_0047fd10 call needs FOUR args (e2, e, *(p2+0x14), 0.0f — the
   a1=$s0 move is deliberate, fixing it removes the shift). Residual
   (nd 54-79): the s16 t lands in $a2 vs retail $a1, the f32 alpha local lands
   in $f13 (arg reg, dead before calls) vs retail $f14 (forcing the
   mov.s $f13,$f14 in the fe90 call), and the fd10 arg materialization order
   (move/lwc1) swaps. Tried: one=1.0f local, alpha/one decl order, void*
   params. FP/integer register-allocation floor. */
// FUN_004746B0
void func_004746b0(u8* arg0, u8* arg1)
{
    f32 temp_f14;
    f32 var_f12;
    s16 temp_5;
    s32* temp_3;
    u8** temp_16;
    s32 temp_3_2;
    s32 temp_4;
    u8** temp_4_2;
    s32 temp_4_3;
    u32 temp_4_4;
    s32 temp_4_5;
    temp_3 = *(s32**)arg0;
    if ((temp_3 != NULL) &&
        ((temp_5 = *(s16*)(arg1 + 4)), (temp_5 >= 0))) {
        temp_4 = *temp_3;
        temp_16 = *(u8***)(temp_4 + temp_5 * 8);
        temp_f14 = *(f32*)(arg1 + 0x1C);
        if (temp_f14 < 1.0f) {
            temp_4_2 = *(u8***)(temp_4 + *(s16*)(arg1 + 0x10) * 8);
            if (temp_4_2 != NULL) {
                if (temp_16 != NULL) {
                    func_0047fd10(temp_4_2, *(f32*)(arg1 + 0x14), temp_16,
                                  0.0f, temp_f14);
                } else {
                    func_0047fe90(temp_4_2, 0.0f, temp_f14);
                }
            } else if (temp_16 != NULL) {
                func_0047fe90(temp_16, 0.0f, 1.0f - temp_f14);
            }
            *(s32*)(arg0 + 4) = (s32)temp_16;
            return;
        }
        if (temp_16 == NULL) {
            temp_4_3 = *(s32*)(arg0 + 4);
            if (temp_4_3 != 0) {
                func_0047ffc0((int*)temp_4_3);
            }
        } else {
            temp_4_4 = *(u32*)(arg1 + 0x34);
            if ((temp_4_4 != 0) &&
                (temp_5 < *(u16*)((u8*)temp_4_4 + 8)) &&
                ((temp_4_5 = temp_5 * 0x50,
                 temp_3_2 = *(s32*)((u32)((u32)*(s32*)temp_4_4 + 0x40) +
                                    (u32)(temp_4_5, temp_4_5))),
                 (temp_3_2 != 0)) &&
                ((u8*)temp_3_2 != (u8*)D_00922BC0_abs)) {
                if (temp_5 < 0) {
                    var_f12 = 0.0f;
                } else {
                    var_f12 = *(f32*)(arg1 + 0xC);
                }
                func_0047fbf0(temp_16, var_f12);
            } else {
                func_0047fbf0(temp_16, *(f32*)(arg1 + 0xC));
                if (*(f32*)(arg1 + 0xC) > func_00480060(temp_16)) {
                    func_00473350(NULL, arg1);
                }
            }
        }
        *(s32*)(arg0 + 4) = (s32)temp_16;
    }
}

// FUN_00474890
void func_00474890(void* param_1)
{
    void* piVar1;
    int* piVar2;
    s32 uVar3;

    piVar2 = (int*)param_1;

    *(u16*)((int)piVar2 + 0xe) = *(u16*)((int)piVar2 + 0xe) + -1;

    if (*(u16*)((int)piVar2 + 0xe) == 0) {
        if (piVar2[2] != 0) {
            func_003df7f0((void*)piVar2[2]);
        }

        if (piVar2[1] != 0) {
            func_003d6230((void*)piVar2[1]);
        }

        for (uVar3 = 0; (uVar3 & 0xffff) < *(u16*)(piVar2 + 3); uVar3 = uVar3 + 1 & 0xffff) {
            piVar1 = (void*)*piVar2;
            piVar1 = (void*)((u8*)piVar1 + (u16)uVar3 * 8);

            if ((*(int*)piVar1 != 0) &&
                ((*(u8*)((u8*)piVar1 + 4) & 1) == 0)) {
                func_003d6230(*(void**)piVar1);
            }
        }

        (*DAT_008873ec)(param_1);
    }

    return;
}


/* P4 port probe: removing opt_propagation off regresses 00474970 MATCH nd0 -> MISMATCH nd8 (s0/s1 coloring swap, 10 differing words) - measured. */
#pragma opt_propagation off

// FUN_00474970
int func_00474970(int param_1, void* param_2)
{
    int* piVar1;
    void* list;

    list = param_2;
    piVar1 = (int*)func_003df890(list);
    while (piVar1 != (int*)func_003df8a0(list)) {
        if (param_1 == *piVar1) {
            return param_1;
        }
        piVar1++;
    }

    *(int*)func_003df6e0(list, 0) = param_1;
    return param_1;
}
#pragma opt_propagation on



// FUN_00474A10
void* func_00474a10(void* param_1, void* data)
{
    u32* param_2 = data;
    func_003c21e0(*(u32*)((u8*)param_1 + 0x18), *param_2, param_2[1]);
    return param_1;
}





// FUN_00474A50
void func_00474a50(void* param_1, void* param_2)
{
    *(float*)((u8*)param_1 + 0x8) = *(float*)((u8*)param_2 + 0x8);
    *(float*)((u8*)param_1 + 0xC) = *(float*)((u8*)param_2 + 0xC);
    *(float*)((u8*)param_1 + 0x10) = *(float*)((u8*)param_2 + 0x10);
    *(float*)((u8*)param_1 + 0x14) = *(float*)((u8*)param_2 + 0x14);
    *(float*)((u8*)param_1 + 0x18) = *(float*)((u8*)param_2 + 0x18);
    *(float*)((u8*)param_1 + 0x1C) = *(float*)((u8*)param_2 + 0x1C);
}

// FUN_00474A90
void func_00474a90(void* param_1, void* param_2)
{
    *(float*)((u8*)param_1 + 0x8) = *(float*)((u8*)param_2 + 0x8);
    *(float*)((u8*)param_1 + 0xC) = *(float*)((u8*)param_2 + 0xC);
    *(float*)((u8*)param_1 + 0x10) = *(float*)((u8*)param_2 + 0x10);
    *(float*)((u8*)param_1 + 0x14) = *(float*)((u8*)param_2 + 0x14);
    *(float*)((u8*)param_1 + 0x18) = *(float*)((u8*)param_2 + 0x18);
    *(float*)((u8*)param_1 + 0x1C) = *(float*)((u8*)param_2 + 0x1C);
}

// FUN_00474AD0
void func_00474ad0(void) {}

// FUN_00474AE0
void func_00474ae0(void) {}
// FUN_00474AF0
void* func_00474af0(void* param_1, u16* param_2)
{
    s16 rawIndex;
    u16 count;
    s64 lVar2;
    int* piVar1;

    rawIndex = (s16)param_2[2];
    piVar1 = *(int**)(param_2 + 0xc);
    if (piVar1 != (int*)0x0) {
        lVar2 = (s64)rawIndex;
        count = *(u16*)(piVar1 + 3);
        if ((((lVar2 < (s64)(u32)count) &&
              (*(int*)(*piVar1 + rawIndex * 8) != 0)) && ((*param_2 & 1) == 0)) &&
            ((lVar2 < (s64)(u32)count && (0 <= rawIndex)))) {
            func_003d5e40_typed(*(f32*)(*(int*)param_1 + 0xc), param_1);
            *(u8*)(param_2 + 1) = 1;
        }
    }

    return param_1;
}




/* measured: probing opt_propagation off for first-target register scheduling. */
#pragma opt_propagation off
// FUN_00474BA0
void* func_00474ba0(void* param_1, void* param_2)
{
    struct Mdl74ba0Ctx {
        u16 flags;
        u8 pad2[2];
        s16 rawIndex;
        u8 pad[0x12];
        int* list;
    };
    s16 rawIndex;
    u16 count;
    s64 lVar2;
    int* piVar1;

    if (param_2 == (void*)0 ||
        ((rawIndex = ((struct Mdl74ba0Ctx*)param_2)->rawIndex,
          piVar1 = ((struct Mdl74ba0Ctx*)param_2)->list,
          piVar1 != (int*)0) &&
         (lVar2 = (s64)rawIndex,
          count = *(u16*)((u8*)piVar1 + 0xC),
          lVar2 < (s64)(u32)count) &&
         (*(int*)(*piVar1 + rawIndex * 8) != 0) &&
         ((*(u16*)param_2 & 1) != 0))) {
        func_003d5840(param_1, *(void**)param_1);
        *(void**)((u8*)param_1 + 0x40) = (void*)func_00474a50;
        *(void**)((u8*)param_1 + 0x44) = (void*)func_00474a90;
        return param_1;
    }

    rawIndex = *(s16*)((u8*)param_2 + 4);
    piVar1 = *(int**)((u8*)param_2 + 0x18);
    if (piVar1 != (int*)0) {
        lVar2 = (s64)rawIndex;
        count = *(u16*)((u8*)piVar1 + 0xC);
        if ((lVar2 < (s64)(u32)count) &&
            (*(int*)(*piVar1 + rawIndex * 8) != 0) &&
            ((*(u16*)param_2 & 1) == 0) &&
            (lVar2 < (s64)(u32)count) &&
            (rawIndex >= 0)) {
            func_003d5e40(param_1, *(f32*)(*(int*)param_1 + 0xC));
            *(u8*)((u8*)param_2 + 2) = 1;
        }
    }

    return param_1;
}
#pragma opt_propagation on
// FUN_00474CE0
u32 func_00474ce0(void* param_1)
{
    s32 iVar2;
    s32 iVar1;
    s32 uVar3;
    char* uVar4;
    s32 lVar5;
    s32 iVar6;
    RpUserDataArray* iVar7;

    iVar1 = func_003bcfb0(param_1);
    uVar3 = 0;
    while (uVar3 < iVar1) {
        iVar7 = func_003bd000(param_1, uVar3);
        uVar4 = func_003bd040(iVar7);
        if (strcmp(uVar4, DAT_007641c8) == 0) {
            iVar2 = func_003bd060(iVar7);
            iVar6 = 0;
            while (iVar6 < iVar2) {
                lVar5 = func_003bd050(iVar7);
                if (lVar5 == 3) {
                    return (u32)func_003bd0b0((u8*)iVar7, iVar6);
                }
                iVar6++;
            }
        }
        uVar3++;
    }
    return 0;
}



// FUN_00474DF0
void func_00474df0(u8* param_1, void* param_2)
{
    u32 uVar1;
    u32* puVar2;
    u32* puVar3;
    u32 userData;
    u32 animation;

    struct {
        code callback;
        u32 value;
    } callbackData;

    if ((*(int*)(param_1 + 0x18) != 0) &&
        (*(u32*)(param_1 + 0xc) = 0, *(int*)(*(int*)(param_1 + 0x18) + 8) == 0)) {
        uVar1 = func_003df5d0(4, 0);

        callbackData.callback = (code)func_00474970;
        callbackData.value = uVar1;

        func_003bff30(param_2, func_00474a10, &callbackData);

        *(u32*)(*(int*)(param_1 + 0x18) + 8) = uVar1;

        for (puVar2 = (u32*)func_003df890((s32*)(*(u32*)(*(int*)(param_1 + 0x18) + 8)));
             puVar3 = (u32*)func_003df8a0(*(u32*)(*(int*)(param_1 + 0x18) + 8)),
             puVar2 != puVar3; puVar2 = puVar2 + 1) {
            userData = func_00474ce0((void*)*puVar2);

            if (((userData != 0) && (strncmp(userData, &gp0xffff9d10, 5) == 0)) &&
                (animation = func_003d8130(*puVar2, 0), animation != 0)) {
                RtAnimInterpolatorSetAnimLoopCallBack(animation, func_00474ba0, 0);

                *(u8**)((int)animation + 0x40) = LAB_00474a50_abs;
                *(u8**)((int)animation + 0x44) = LAB_00474a90_abs;
            }
        }
    }

    return;
}




// FUN_00474F40
void* func_00474f40(void* arg0, void* data)
{
    void* obj;
    s32 count;
    s32 i;
    s32 flag;
    s32 t;

    obj = *(void**)((u8*)arg0 + 0x18);
    if (obj == 0) {
        return arg0;
    }
    flag = 0;
    count = *(s32*)((u8*)obj + 0x24);
    i = 0;
    while (i < count && flag == 0) {
        if (RpMatFXMaterialGetEffects(*(void**)((u8*)*(void**)((u8*)obj + 0x20) + i * 4)) != 0) {
            flag = 1;
        }
        i++;
    }
    if (func_003b83f0((int)obj) != 0) {
        t = func_003b85b0(arg0);
        switch (t) {
        case 0:
        case 3:
            break;
        default:
        case 1:
        case 2:
            if (flag != 0) {
                func_003b8520(arg0, 2);
            } else {
                func_003b8520(arg0, 1);
            }
            break;
        }
    } else if (flag != 0) {
        func_00399b10((s32)arg0);
    }
    return arg0;
}
// FUN_00475090
void* func_00475090(void* param_1, void* data)
{
    int iVar1;
    int iVar2;
    u32 lVar3;
    u32 uVar4;
    int iVar5;

    iVar1 = *(int*)((int)param_1 + 0x18);
    if (iVar1 == 0) {
        return param_1;
    }

    lVar3 = func_003b83f0(iVar1);
    if (lVar3 == 0) {
        return param_1;
    }

    uVar4 = func_003b8500(lVar3);
    if (uVar4 <= 0x40) {
        return param_1;
    }

    iVar2 = *(int*)(iVar1 + 0x24);
    for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
        func_00473140(*(u32*)(*(int*)(iVar1 + 0x20) + iVar5 * 4));
    }

    return param_1;
}




/* measured: MATCHED this wave (nd 0) — the old note's nd 111 floor was an
   artifact of the || / if-else-if dispatch spelling. Working spelling:
   switch(func_00399d80(*it)){case 5: case 6:} reproduces retail's
   beq 6/beq 5/b-skip with the body out of line; the cb checks must compare
   and store *(void**)(obj2+0x40) against (void*)func_00474a50/00474a90
   (u32 casts also work, void* keeps mwcc from adding conversions);
   re-read arg0->0x18 fresh for `list` (retail re-issues the lw). */
// FUN_00475170
void func_00475170(u8* arg0, f32 fparg0)
{
    u32* it;
    u32 list;
    u8* obj2;

    obj2 = *(u8**)(arg0 + 0x18);
    if (obj2 != 0 && *(u32*)(obj2 + 8) != 0) {
        *(f32*)(arg0 + 0xC) = fparg0;
        *(f32*)(arg0 + 0x10) = fparg0;
        list = *(u32*)(*(u8**)(arg0 + 0x18) + 8);
        it = (u32*)func_003df890((s32*)list);
        while (it != (u32*)func_003df8a0(list)) {
            switch (RpMatFXMaterialGetEffects(*it)) {
            case 5:
            case 6:
                obj2 = (u8*)func_003d8130(*it, 0);
                if (obj2 != 0) {
                    if (*(void**)(obj2 + 0x40) == (void*)func_00474a50 &&
                        *(void**)(obj2 + 0x44) == (void*)func_00474a90) {
                        func_003d5e40(obj2, fparg0);
                        *(void**)(obj2 + 0x40) = (void*)func_00474a50;
                        *(void**)(obj2 + 0x44) = (void*)func_00474a90;
                    } else {
                        func_003d5e40(obj2, fparg0);
                    }
                }
                if (*(u8*)(arg0 + 2) != 1) {
                    obj2 = (u8*)func_003d8130(*it, 1);
                    if (obj2 != 0) {
                        if (*(void**)(obj2 + 0x40) == (void*)func_00474a50 &&
                            *(void**)(obj2 + 0x44) == (void*)func_00474a90) {
                            func_003d5e40(obj2, fparg0);
                            *(void**)(obj2 + 0x40) = (void*)func_00474a50;
                            *(void**)(obj2 + 0x44) = (void*)func_00474a90;
                        } else {
                            func_003d5e40(obj2, fparg0);
                        }
                    }
                }
                break;
            }
            it++;
        }
    }
}

typedef struct MdlAnimResourceView {
    MdlAnimResourceEntry* entries;
    u32 unknown04;
    void* objects;
    u16 count;
    u16 unknown0e;
} MdlAnimResourceView;

typedef struct MdlAnimControlView {
    u16 flags;
    u8 mode;
    u8 unknown03;
    s16 index;
    u8 unknown06[6];
    f32 primaryTime;
    f32 secondaryTime;
    u16 ticks;
    u16 unknown16;
    MdlAnimResourceView* resource;
} MdlAnimControlView;

/* Prefix view of the interpolation scheme in rw/inc/rtanim.h. */
typedef struct MdlAnimSchemeView {
    s32 typeID;
    s32 interpKeyFrameSize;
    s32 animKeyFrameSize;
    void *keyFrameApplyCB;
    RtAnimKeyFrameBlendCallBack keyFrameBlendCB;
    void *keyFrameInterpolateCB;
} MdlAnimSchemeView;
typedef struct RtAnimInterpolatorInfo RtAnimInterpolatorInfo;
struct RtAnimAnimation {
    RtAnimInterpolatorInfo *interpInfo;
    s32 numFrames;
    s32 flags;
    f32 duration;
    void *pFrames;
    void *customData;
};
extern RtAnimAnimation *func_003d6170(void *, u32);
extern s32 func_003d5750(RtAnimAnimation *);
extern void func_003d7c50(RtAnimAnimation *);
extern void func_003d7cd0(RtAnimAnimation *);
extern void func_003d8070();
extern void func_0039a700();
extern void func_00399bf0();
extern s32 iGpffffb74c;

static inline void mdlSetupDetach(u32 *object) {
    RtAnimInterpolator *interpolator = (RtAnimInterpolator *)func_003d8130(*object, 1);
    if (interpolator != 0) {
        func_003d7c50(interpolator->pCurrentAnim);
        func_003d5830(interpolator);
        *(u32 *)((u8 *)*object + iGpffffb74c + 12) = 0;
    }
}

/* 1220/1232 bytes; 46 resolved relocations and twelve zero alignment bytes.
 * Animation and blend use their signed/unsigned short domains. The raw
 * flag word is narrowed at use; the dispatcher shares this typed boundary.
 * Keep the animation and interpolator lifetimes in this declaration order. */
// FUN_00475350
void func_00475350(void *clump, MdlAnimControlView *state,
                   s16 index, u16 blend, s32 flags)
{
    MdlAnimResourceView *resource;
    u32 *object;
    u32 name;
    RtAnimInterpolator *interpolator;
    RtAnimAnimation *animation;
    s32 special;
    if (state->resource != 0) {
        state->flags &= ~1u;
        state->flags |= (u16)flags & 0xffff & 1;
        state->mode = 0;
        state->secondaryTime = 0;
        if (blend > 0 && state->index != -1 && state->resource != 0 &&
            state->index < state->resource->count && state->resource->entries[state->index].resource != 0 &&
            state->resource != 0 && (s64)index < state->resource->count && state->resource->entries[index].resource != 0)
            state->ticks = blend;
        else
            state->ticks = 0;
        resource = state->resource;
        if (resource != 0 && (s64)index < resource->count && resource->entries[index].resource != 0) {
            s32 *objects = resource->objects;
            for (object = (u32 *)func_003df890(objects); object != (u32 *)func_003df8a0(objects); ++object) {
                switch (RpMatFXMaterialGetEffects(*object)) {
                case 5: case 6: func_0039a700(*object, 0, 0); break;
                }
                name = func_00474ce0((void *)*object);
                if (name != 0) {
                    animation = func_003d6170(((MdlAnimResourceEntry *)addOff((s32)index * 8, (u32)state->resource->entries))->resource, name);
                    if (animation != 0) {
                        special = strncmp(name, &gp0xffff9d10, 5) == 0;
                        interpolator = (RtAnimInterpolator *)func_003d8130(*object, 1);
                        if (interpolator != 0) {
                            s32 nodeCount;
                            func_003d7c50(interpolator->pCurrentAnim);
                            nodeCount = interpolator->numNodes;
                            if (nodeCount != func_003d5750(animation) || interpolator->currentInterpKeyFrameSize != ((MdlAnimSchemeView *)animation->interpInfo)->interpKeyFrameSize) {
                                func_003d5830(interpolator);
                                interpolator = 0;
                            }
                        }
                        if (interpolator != 0) {
                            func_003d5840(interpolator, animation);
                            func_003d7cd0(animation);
                        } else {
                            func_003d8070(*object, animation, 1);
                            interpolator = (RtAnimInterpolator *)func_003d8130(*object, 1);
                        }
                        if (func_003d5750(animation) == 1) func_00399bf0(*object, 5);
                        else func_00399bf0(*object, 6);
                        if (special == 1) {
                            RtAnimInterpolatorSetAnimLoopCallBack(interpolator, func_00474ba0, state);
                            interpolator->keyFrameBlendCB = (RtAnimKeyFrameBlendCallBack)func_00474a50;
                            interpolator->keyFrameInterpolateCB = (void *)func_00474a90;
                        } else {
                            RtAnimInterpolatorSetAnimLoopCallBack(interpolator, func_00474af0, state);
                            interpolator->keyFrameBlendCB = ((MdlAnimSchemeView *)animation->interpInfo)->keyFrameBlendCB;
                            interpolator->keyFrameInterpolateCB = ((MdlAnimSchemeView *)animation->interpInfo)->keyFrameInterpolateCB;
                        }
                    } else mdlSetupDetach(object);
                }
            }
            func_003bff30(clump, func_00475090, 0);
            func_003bff30(clump, func_00474f40, 0);
        } else {
            s32 *objects = resource->objects;
            for (object = (u32 *)func_003df890(objects); object != (u32 *)func_003df8a0(objects); ++object)
                if (func_00474ce0((void *)*object) != 0) mdlSetupDetach(object);
        }
        state->index = index;
    }
}

/* IDA 00475820, mdlManager.c:1687-1775: primary and secondary interpolators
   have separate lifetimes, including the mode-1 callback-only path.
   Measured 744B/752B: instruction match, followed by 8 zero tail bytes. */
#pragma push
#pragma always_inline on

static inline void mdl_step_secondary(MdlAnimControlView* state, u32* it)
{
    if (state->mode != 1) {
        RtAnimInterpolator* interp;
        interp = (RtAnimInterpolator*)func_003d8130(*it, 1);
        if (interp != NULL) {
            if (interp->keyFrameBlendCB == (RtAnimKeyFrameBlendCallBack)func_00474a50 &&
                interp->keyFrameInterpolateCB == (void*)func_00474a90) {
                RtAnimInterpolatorSetAnimLoopCallBack(interp, func_00474ba0, state);
                func_003d5e40((u8*)interp, state->secondaryTime);
                interp->keyFrameBlendCB = (RtAnimKeyFrameBlendCallBack)func_00474a50;
                interp->keyFrameInterpolateCB = (void*)func_00474a90;
            } else {
                RtAnimInterpolatorSetAnimLoopCallBack(interp, func_00474af0, state);
                if (interp->keyFrameBlendCB != (RtAnimKeyFrameBlendCallBack)func_00474ad0 &&
                    interp->keyFrameInterpolateCB != (void*)func_00474ae0) {
                    func_003d5e40((u8*)interp, state->secondaryTime);
                }
            }
            state->secondaryTime = interp->currentTime;
        }
        return;
    }
    {
        RtAnimInterpolator* interp;
        interp = (RtAnimInterpolator*)func_003d8130(*it, 1);
        if (interp != NULL) {
            if (interp->keyFrameBlendCB == (RtAnimKeyFrameBlendCallBack)func_00474a50 &&
                interp->keyFrameInterpolateCB == (void*)func_00474a90) {
                RtAnimInterpolatorSetAnimLoopCallBack(interp, func_00474ba0, state);
            } else {
                RtAnimInterpolatorSetAnimLoopCallBack(interp, func_00474af0, state);
            }
        }
    }
}

static inline void mdl_step_anim_object(MdlAnimControlView* state, u32* it)
{
    extern s32 func_003d7cf0(u32 object);
    RtAnimInterpolator* interp;
    switch (RpMatFXMaterialGetEffects(*it)) {
    case 5:
    case 6:
        break;
    default:
        return;
    }
    interp = (RtAnimInterpolator*)func_003d8130(*it, 0);
    if (interp != NULL) {
        if (interp->keyFrameBlendCB == (RtAnimKeyFrameBlendCallBack)func_00474a50 &&
            interp->keyFrameInterpolateCB == (void*)func_00474a90) {
            func_003d5e40((u8*)interp, state->primaryTime);
            interp->keyFrameBlendCB = (RtAnimKeyFrameBlendCallBack)func_00474a50;
            interp->keyFrameInterpolateCB = (void*)func_00474a90;
        } else {
            func_003d5e40((u8*)interp, state->primaryTime);
        }
        state->primaryTime = interp->currentTime;
    }
    mdl_step_secondary(state, it);
    func_003d7cf0(*it);
}

// FUN_00475820
void func_00475820(void* arg0, void* arg1)
{
    MdlAnimControlView* state = (MdlAnimControlView*)arg0;
    u32* it;
    void* list;
    if (state->resource != NULL && state->resource->objects != NULL) {
        if (state->ticks != 0)
            --state->ticks;
        state->primaryTime = state->primaryTime + iGpffff8040;
        state->secondaryTime = ((MdlAnimControlView*)arg1)->primaryTime;
        list = state->resource->objects;
        for (it = (u32*)func_003df890(list); it != (u32*)func_003df8a0(list); ++it) {
            mdl_step_anim_object(state, it);
        }
    }
}
#pragma pop

typedef struct MdlFrameSearch {
    void* frame;
    s32 id;
} MdlFrameSearch;

// FUN_00475B10
void* func_00475b10(void* object, void* data)
{
    MdlFrameSearch* search = (MdlFrameSearch*)data;
    if (search->id == func_00397470(object)) {
        search->frame = object;
        return NULL;
    }

    func_003e9af0(object, func_00475b10, data);
    return object;
}




/* Keep the root fast path separate from recursive child traversal.
   The inlined return paths preserve the retail branch layout. */
static inline u8* mdl_find_frame(u8* frame, s32 id)
{
    MdlFrameSearch data;
    if (id == func_00397470(frame))
        return frame;
    data.id = id;
    data.frame = NULL;
    func_003e9af0(frame, func_00475b10, &data);
    return data.frame;
}

/* MATCH: 312B/320B, with two zero-tail words. IDA-backed frame lookup
   lifetime and pointer-valued userdata preserve every retail instruction. */
// FUN_00475B90
int func_00475b90(void* buf, void* v, u32 idx, void* obj)
{
    s32 count;
    u16 i;
    u32 masked_idx;
    void* entry;
    u8* clump;
    s32 field44;

    count = (s32)*(u16*)v;
    i = 0;
    masked_idx = idx & 0xFFFF;
    while ((s32)(u16)i < count) {
        entry = (void*)((u8*)*(void**)((u8*)v + 4) + (u32)(u16)i * 0x50);
        if (masked_idx == *(s32*)((u8*)entry + 0x40)) {
            break;
        }
        i++;
    }
    if ((s32)(u16)i == count) {
        return 0;
    }

    entry = (void*)((u8*)*(void**)((u8*)v + 4) + (u32)(u16)i * 0x50);
    field44 = *(s32*)((u8*)entry + 0x44);
    clump = *(u8**)((u8*)obj + 4);
    clump = mdl_find_frame(clump, field44);
    if (clump == 0) {
        return 0;
    }

    RwMatrixMultiply(buf, entry, func_003e9700(clump));
    return 1;
}

/* RenderWare quaternion/slerp definitions mirror rtquat.h, rtslerp.h and rwplcore.h.
 * The full SDK headers conflict with this unit's existing RwV3d/RwMatrix types. */
extern f32 fabsf(f32);
typedef struct MdlRenderDevice {
    void (*set)(s32, s32);
    void (*get)(s32, void*);
} MdlRenderDevice;
typedef f32 RwReal;
typedef s32 RwBool;
#define MACRO_START do
#define MACRO_STOP while(0)
typedef struct RtQuat RtQuat;
struct RtQuat
{
    RwV3d               imag;   /**< The imaginary part(s) */
    RwReal              real;   /**< The real part */
};

typedef struct RtQuatSlerpCache RtQuatSlerpCache;
struct RtQuatSlerpCache
{
    RtQuat              raFrom; /**< Scaled initial quaternion  */
    RtQuat              raTo;   /**< Scaled final quaternion */
    RwReal              omega;  /**< Angular displacement in radians */
    RwBool              nearlyZeroOm; /**< Flags near-zero angular 
                                                displacement*/
};
#define   _RW_S1      ( (float)-1.6666667163e-01 )
#define   _RW_S2      ( (float) 8.3333337680e-03 )
#define   _RW_S3      ( (float)-1.9841270114e-04 )
#define   _RW_S4      ( (float) 2.7557314297e-06 )
#define   _RW_S5      ( (float)-2.5050759689e-08 )
#define   _RW_S6      ( (float) 1.5896910177e-10 )
#define RwSinMinusPiToPiMacro(result, x)                          \
do                                                                \
{                                                                 \
    const float z = x * x;                                        \
    const float v = z * x;                                        \
    const float r = ( _RW_S2 +                                    \
                      z * (_RW_S3 +                               \
                           z * (_RW_S4 +                          \
                                z * (_RW_S5 +                     \
                                     z * _RW_S6))) );             \
    result = x + v * (_RW_S1 + z * r);                            \
}                                                                 \
while(0)                                                                  

#define RwV3dScaleMacro(o, a, s)                                \
MACRO_START                                                     \
{                                                               \
    (o)->x = (((a)->x) * ( (s)));                               \
    (o)->y = (((a)->y) * ( (s)));                               \
    (o)->z = (((a)->z) * ( (s)));                               \
}                                                               \
MACRO_STOP

#define RwV3dIncrementScaledMacro(o, a, s)                      \
MACRO_START                                                     \
{                                                               \
    (o)->x += (((a)->x) * ( (s)));                              \
    (o)->y += (((a)->y) * ( (s)));                              \
    (o)->z += (((a)->z) * ( (s)));                              \
}                                                               \
MACRO_STOP

#define RtQuatSlerpMacro(qpResult, qpFrom, qpTo, rT, sCache)            \
MACRO_START                                                             \
{                                                                       \
    if ((rT) <= ((RwReal) 0))                                           \
    {                                                                   \
        /* t is before start */                                         \
        *(qpResult) = *(qpFrom);                                        \
    }                                                                   \
    else if (((RwReal) 1) <= (rT))                                      \
    {                                                                   \
                                                                        \
        /* t is after end */                                            \
        *(qpResult) = *(qpTo);                                          \
    }                                                                   \
    else                                                                \
    {                                                                   \
        /* ... so t must be in the interior then */                     \
        /* Calc coefficients rSclFrom, rSclTo */                        \
        RwReal rSclFrom = ((RwReal) 1) - (rT);                          \
        RwReal rSclTo = (rT);                                           \
                                                                        \
        if (!((sCache)->nearlyZeroOm))                                  \
        {                                                               \
            /* Standard case: slerp */                                  \
            /* SLERPMESSAGE(("Neither nearly ZERO nor nearly PI")); */  \
                                                                        \
            rSclFrom *= (sCache)->omega;                                \
            RwSinMinusPiToPiMacro(rSclFrom, rSclFrom);                   \
            rSclTo *= (sCache)->omega;                                  \
            RwSinMinusPiToPiMacro(rSclTo, rSclTo);                       \
        }                                                               \
                                                                        \
        /* Calc final values */                                         \
        RwV3dScaleMacro(&(qpResult)->imag,                              \
                        &(sCache)->raFrom.imag, rSclFrom);              \
        RwV3dIncrementScaledMacro(&(qpResult)->imag,                    \
                             &(sCache)->raTo.imag, rSclTo);             \
        (qpResult)->real =                                              \
            ((sCache)->raFrom.real * rSclFrom) +                        \
            ((sCache)->raTo.real * rSclTo);                             \
    }                                                                   \
}                                                                       \
MACRO_STOP
#define RtQuatNegateMacro( result, q )                                     \
MACRO_START                                                                \
{                                                                          \
    (result)->real = -(q)->real;                                           \
    (result)->imag.x = -(q)->imag.x;                                       \
    (result)->imag.y = -(q)->imag.y;                                       \
    (result)->imag.z = -(q)->imag.z;                                       \
}                                                                          \
MACRO_STOP
typedef struct MdlDrawState {
    RwMatrix matrix;
    RwMatrix identityMatrix;
    RwV3d scale;
    u8 unknown8c[0xD0-0x8C];
    RwRGBA color;
    u32 unknownD4;
    u32 flagsD8;
    void* clump;
    void* e0;
    u8 unknownE4[8];
    u16 animFlags;
    u8 unknownEE[2];
    s16 animIndex;
    u8 unknownF2[0x10C-0xF2];
    void* hierarchy;
    u8 unknown110[0x120-0x110];
    void* animations;
    void* effect124;
    u8 unknown128[0x140-0x128];
    u16 flags140;
    u8 unknown142[0x234-0x142];
    u8 state234[0x2C];
    u8 flags;
    u8 unknown261[3];
    RtQuat rotation;
    f32 limit;
    f32 targetLimit;
    f32 limitRate;
    u8 alpha;
    u8 targetAlpha;
    u8 alphaStep;
    u8 unknown283;
    f32 minBlend;
    f32 maxAngle;
    u8 unknown28C[0x2CC-0x28C];
    u8* effect2CC;
} MdlDrawState;

extern void RpSkyRenderStateSet(s32 a, s32 b);
extern void func_00477260(void* a, u32* b, u16 c);
extern void func_004789c0(Model* a);
extern s32 RtQuatConvertFromMatrix(RtQuat* out, const RwMatrix* in);
extern RwV3d* RtQuatTransformVectors(RwV3d* out, const RwV3d* in, s32 count, const RtQuat* quat);
extern void func_003dcc70(f32* first, f32* second, void* result);
extern f32 func_0044b920(f32 value);
extern s32 func_004571b0(void);
extern s32 func_004571c0(void);
extern void func_004746b0(u8* a, u8* b);
extern void func_00479910(void* a);
extern void* mdlGetMatrix(void* a);
extern s32 func_0047a510(void* a, s32 b, void* c);
extern s32 func_0047ae90(u8* model, u16 index);
extern void func_0047d540(u8** a, u8* b);
extern void func_0047d900(s32* a, f32* b);
extern void func_0047dd40(u8* a, void* model);
extern void (*D_00887300_abs[])(s32, s32);
extern void (*D_00887304[])(s32, void*);

/* Retail ORs identity.flags at sp+0xCC (0x004764F0) before its first store at
 * 0x00476500; nothing earlier defines that word. The C keeps the same
 * read-modify-write of the uninitialised field. */
// FUN_00475CD0
void func_00475cd0(MdlDrawState* owner)
{
    s32 current;
    s32 target;
    s32 value;
    u32 flags;
    u16 j;
    u16 layer;
    MdlDrawState* model;
    RwRGBA color;
    s32 renderState;
    RwV3d direction;
    RwMatrix matrix1;
    RwMatrix matrix0;
    RwMatrix identity;
    RtQuatSlerpCache interpolation;
    RtQuat result;
    RtQuat quaternion;
    MdlRenderDevice* renderStateSet;

    target = owner->targetAlpha;
    current = owner->alpha;
    if (current < target) {
        value = current + owner->alphaStep;
        if (target < value) {
            owner->alpha = (u8)target;
        } else {
            owner->alpha = (u8)value;
        }
    } else if (target < current) {
        value = current - owner->alphaStep;
        if (value < target) {
            owner->alpha = (u8)target;
        } else {
            owner->alpha = (u8)value;
        }
    } else {
        owner->alpha = (u8)target;
    }

    color.red = 0;
    color.green = 0;
    color.blue = 0;
    color.alpha = (u8)(255.0f * ((f32)(owner->alpha
                         * owner->color.alpha) / (255 * 255)));

    {
    u8* material;
    flags = owner->flags;
    if ((flags & 1) != 0 && (flags & 0x20) == 0) {
        material = *(u8**)((u8*)func_004571b0() + 4);
    } else {
        material = *(u8**)((u8*)func_004571c0() + 4);
    }

    flags = owner->flags;
    if ((flags & 2) != 0 && (flags & 0x20) == 0) {
        if ((flags & 4) == 0) {
            RtQuatConvertFromMatrix(&quaternion, (const RwMatrix*)(material + 0x10));
        } else {
            quaternion.imag.x = 0.707107f;
            quaternion.imag.y = 0.0f;
            quaternion.imag.z = 0.0f;
            quaternion.real = quaternion.imag.x;
        }
        {
            f32 dot;
            f32 angle;
            f32 amount;
            f32 limit;
            dot = owner->rotation.imag.x * quaternion.imag.x
                + owner->rotation.imag.y * quaternion.imag.y
                + owner->rotation.imag.z * quaternion.imag.z;
            dot += owner->rotation.real * quaternion.real;
            if (dot < 0.0f) {
                RtQuatNegateMacro(&result, &quaternion);
                dot = owner->rotation.real * result.real
                    + (owner->rotation.imag.x * result.imag.x
                    + owner->rotation.imag.y * result.imag.y
                    + owner->rotation.imag.z * result.imag.z);
            }
            angle = 2.0f * func_0044b920(dot);
            limit = owner->minBlend;
            if (limit < 1.0f) {
                f32 maximum;
                maximum = owner->maxAngle;
                if (!(angle <= maximum)) {
                    amount = maximum / angle;
                    if (amount < limit) {
                        amount = limit;
                    }
                } else {
                    amount = limit;
                }
                func_003dcc70((f32*)&owner->rotation, (f32*)&quaternion,
                              &interpolation);
                RtQuatSlerpMacro(&result, &owner->rotation, &quaternion,
                                amount, &interpolation);
                *&owner->rotation = result;
            } else {
                owner->rotation = quaternion;
            }
        }
        RtQuatTransformVectors(&direction, (const RwV3d*)(D_00713138 + 0x10), 1,
                      &owner->rotation);
    } else {
        u8* source = material + 0x10;
        RtQuatConvertFromMatrix(&owner->rotation, (const RwMatrix*)source);
        direction = ((RwMatrix*)source)->at;
    }

    }

    if (color.alpha == 0) {
        if ((owner->animFlags & 0x10) != 0) {
            func_00473000(owner->hierarchy,
                          (u8*)&owner->animFlags);
        } else if ((owner->flags140 & 0x81E0) != 0) {
            func_00471370(owner->hierarchy,
                          (u8*)&owner->animFlags, (u8*)&owner->flags140, 0);
        } else {
            func_00397c40(owner->hierarchy);
        }
        if ((owner->flagsD8 & 0x80000) != 0) {
            func_004746b0(owner->state234, (u8*)&owner->animFlags);
        }
        {
        u32 needsReset;
        u32 hasItem;
        u32 hasIndex;
        u8* animation;
        u8* slot;
        u8** child;
        s32* frameID;
        j = 0;
        while ((s64)j < 5) {
            slot = (u8*)owner + j * 0xC;
            if ((*(u8*)(slot + 0x28C) & 1) != 0 &&
                *(child = (u8**)(slot + 0x290)) != 0 &&
                func_0047ae90((u8*)owner, j) != 0) {
                model = (MdlDrawState*)*child;
                if ((model->flagsD8 & 2) == 0) {
                    if (*(frameID = (s32*)(slot + 0x294)) != -1) {
                        {
                        void* matrix = mdlGetMatrix(model);
                        s64 index = *frameID;
                        func_0047a510(owner, index, matrix);
                    }
                    } else {
                        model->matrix = owner->matrix;
                    }
                    needsReset = 0;
                    hasItem = 0;
                    hasIndex = 0;
                    animation = model->animations;
                    if (animation != 0 &&
                        *(u16*)(animation + 8) > model->animIndex) {
                        hasIndex = 1;
                    }
                    if (hasIndex != 0 &&
                        *(void**)((u8*)*(void**)animation
                                  + model->animIndex * 0x50 + 0x40) != 0) {
                        hasItem = 1;
                    }
                    if (hasItem != 0 &&
                        *(void**)((u8*)*(void**)animation
                                  + model->animIndex * 0x50 + 0x40)
                            != (void*)D_00922BC0_abs) {
                        needsReset = 1;
                    }
                    if (needsReset != 0) {
                        func_00397c40(model->hierarchy);
                    }
                    if ((model->flagsD8 & 0x80000) != 0) {
                        func_004746b0(model->state234, (u8*)&model->animFlags);
                    }
                }
            }
            j++;
        }
        }
        return;
    }

    if (!(direction.y < 0.0f)) {
        f32 unit;
        unit = 0.707107f;
        owner->rotation.imag.x = unit;
        owner->rotation.imag.y = 0.0f;
        owner->rotation.imag.z = 0.0f;
        owner->rotation.real = unit;
        RtQuatTransformVectors(&direction, (const RwV3d*)(D_00713138 + 0x10), 1,
                      &owner->rotation);
    }
    if (owner->limit !=
        owner->targetLimit) {
        owner->limit =
            owner->limit
            + owner->limitRate
              * (owner->targetLimit
                 - owner->limit);
    }
    {
        f32 limit;
        limit = owner->limit;
        if (fabsf(direction.y) < limit) {
            if (!(direction.y < 0.0f)) {
                direction.y = limit;
            } else {
                direction.y = -limit;
            }
        }
    }

    identity.right.x = identity.up.y = identity.at.z = 1.0f;
    identity.right.y = identity.right.z = identity.up.x = 0.0f;
    identity.up.z = identity.at.x = identity.at.y = 0.0f;
    identity.pos.x = identity.pos.y = identity.pos.z = 0.0f;
    identity.flags |= 0x20003;
    identity.up.x = -direction.x / direction.y;
    identity.up.y = 0.01f;
    identity.up.z = -direction.z / direction.y;

    {
    void* frame = *(void**)((u8*)owner->clump + 4);
    RwMatrixMultiply(&matrix0, &owner->identityMatrix, owner);
    RwMatrixMultiply(&matrix1, &matrix0, &identity);
    func_003e9cb0(frame, &matrix1, 0);
    }
    if ((owner->flags140 & 0x4000) != 0) {
        func_00471370(owner->hierarchy,
                      (u8*)&owner->animFlags, (u8*)&owner->flags140,
                      &identity);
    } else {
        func_00397c40(owner->hierarchy);
    }
    renderStateSet = (MdlRenderDevice*)D_00887300_abs;
    renderStateSet->set(6, 1);
    renderStateSet->set(8, 0);
    D_00887304[0](0xE, &renderState);
    renderStateSet->set(0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    if ((owner->flagsD8 & 0x80000) != 0) {
        func_004746b0(owner->state234, (u8*)&owner->animFlags);
    }
    func_00477260(owner->clump, (u32*)&color,
                        (u16)(s64)((owner->flags & 8) != 0));
    {
    u8* effect;
    effect = (u8*)owner->e0;
    if (effect == 0) {
        RpSkyRenderStateSet(3, 0x7C01B);
    } else if ((*(s32*)(effect + 0x10) != 0 || *(s32*)(effect + 0x1C) != 0)
               && ((owner->flags & 0x80) == 0)) {
        RpSkyRenderStateSet(3, 0x7F06B);
    } else {
        RpSkyRenderStateSet(3, 0x7D7FB);
    }
    }
    func_00479910(owner->clump);
    func_004789c0((Model*)owner);
    if ((owner->animFlags & 0x10) != 0) {
        func_00473000(owner->hierarchy,
                      (u8*)&owner->animFlags);
    } else if ((owner->flags140 & 0x81E0) != 0) {
        func_00471370(owner->hierarchy,
                      (u8*)&owner->animFlags, (u8*)&owner->flags140, 0);
    } else {
        func_00397c40(owner->hierarchy);
    }
    {
    u8* effect;
    effect = owner->effect2CC;
    if (effect != 0) {
        func_0047d900((s32*)effect, (f32*)(&owner->scale));
        func_0047d540((u8**)owner->effect2CC, (u8*)owner);
    }
    }
    {
    u8* model;
    u8* effect;
    layer = 0;
    while ((s64)layer < 2) {
        model = *(u8**)((u8*)owner + layer * 0xA4 + 0x124);
        if (model != 0) {
            effect = *(u8**)(model + 0x18);
            if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                func_0047d900((s32*)effect, (f32*)(model + 8));
                func_0047d540(*(u8***)(model + 0x18), (u8*)owner);
            }
            effect = *(u8**)(model + 0x24);
            if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                func_0047dd40(effect, owner);
            }
            if (*(u16*)(model + 0x30) > 0) {
                *(u16*)(model + 0x30) -= 1;
            }
        }
        layer++;
    }
    }
    {
    struct { u16 index; u8* slot; MdlDrawState* model; } attached;
    u8** child;
    s32* frameID;
    u32 hasItem;
    u32 hasIndex;
    u8* animation;
    u8* effect;
    attached.index = 0;
    while ((s64)attached.index < 5) {
        attached.slot = (u8*)((MdlWpnSlot*)owner + attached.index);
        if ((*(u8*)(attached.slot + 0x28C) & 1) != 0 &&
            *(child = (u8**)(attached.slot + 0x290)) != 0 &&
            func_0047ae90((u8*)owner, attached.index) != 0) {
            attached.slot = (u8*)owner + attached.index * 0xC;
            attached.model = (MdlDrawState*)*child;
            if (*(frameID = (s32*)(attached.slot + 0x294)) != -1) {
                {
                        void* matrix = mdlGetMatrix(attached.model);
                        s64 index = *frameID;
                        func_0047a510(owner, index, matrix);
                    }
            } else {
                attached.model->matrix = owner->matrix;
            }
            if ((attached.model->flagsD8 & 2) == 0 &&
                owner->color.alpha != 0) {
                u8* source = attached.model->clump;
                u8* material = *(u8**)(source + 4);
                u32 needsReset;
                RwMatrixMultiply(&matrix0, &attached.model->identityMatrix, attached.model);
                RwMatrixMultiply(&matrix1, &matrix0, &identity);
                func_003e9cb0(material, &matrix1, 0);
                needsReset = 0;
                hasItem = 0;
                hasIndex = 0;
                animation = attached.model->animations;
                if (animation != 0 &&
                    *(u16*)(animation + 8) > attached.model->animIndex) {
                    hasIndex = 1;
                }
                if (hasIndex != 0 &&
                    *(void**)((u8*)*(void**)animation
                              + attached.model->animIndex * 0x50 + 0x40) != 0) {
                    hasItem = 1;
                }
                if (hasItem != 0 &&
                    *(void**)((u8*)*(void**)animation
                              + attached.model->animIndex * 0x50 + 0x40)
                        != (void*)D_00922BC0_abs) {
                    needsReset = 1;
                }
                if (needsReset != 0) {
                    func_00397c40(attached.model->hierarchy);
                }
                if ((attached.model->flagsD8 & 0x80000) != 0) {
                    func_004746b0(attached.model->state234, (u8*)&attached.model->animFlags);
                }
                func_00477260(source, (u32*)&color,
                                    (u16)(s64)((attached.model->flags & 8) != 0));
                effect = (u8*)owner->e0;
                if (effect == 0) {
                    RpSkyRenderStateSet(3, 0x7C01B);
                } else if (*(s32*)(effect + 0x10) != 0 ||
                           *(s32*)(effect + 0x1C) != 0) {
                    RpSkyRenderStateSet(3, 0x7F08B);
                } else {
                    RpSkyRenderStateSet(3, 0x7D7FB);
                }
                func_00479910(source);
                func_004789c0((Model*)attached.model);
                if (needsReset != 0) {
                    func_00397c40(attached.model->hierarchy);
                }
                effect = attached.model->effect2CC;
                if (effect != 0) {
                    func_0047d900((s32*)effect, (f32*)&attached.model->scale);
                    func_0047d540((u8**)attached.model->effect2CC, (u8*)attached.model);
                }
                {
                struct { u16 index; u8* table; } layerCursor;
                layerCursor.index = 0;
                while ((s64)layerCursor.index < 2) {
                    layerCursor.table = *(u8**)((u8*)attached.model + layerCursor.index * 0xA4 + 0x124);
                    if (layerCursor.table != 0) {
                        source = *(u8**)(layerCursor.table + 0x18);
                        if (source != 0 && *(u16*)(layerCursor.table + 0x30) == 0) {
                            func_0047d900((s32*)source, (f32*)(layerCursor.table + 8));
                            func_0047d540(*(u8***)(layerCursor.table + 0x18), (u8*)attached.model);
                        }
                        source = *(u8**)(layerCursor.table + 0x24);
                        if (source != 0 && *(u16*)(layerCursor.table + 0x30) == 0) {
                            func_0047dd40(source, attached.model);
                        }
                        if (*(u16*)(layerCursor.table + 0x30) > 0) {
                            *(u16*)(layerCursor.table + 0x30) -= 1;
                        }
                    }
                    layerCursor.index++;
                }
                }
            }
        }
        attached.index++;
    }
    }
    renderStateSet = (MdlRenderDevice*)D_00887300_abs;
    renderStateSet->set(0xE, renderState);
    RpSkyRenderStateSet(3, 0x717FB);
    renderStateSet->set(8, 1);
}

#undef RtQuatNegateMacro
#undef RtQuatSlerpMacro
#undef RwV3dIncrementScaledMacro
#undef RwV3dScaleMacro
#undef RwSinMinusPiToPiMacro
#undef _RW_S1
#undef _RW_S2
#undef _RW_S3
#undef _RW_S4
#undef _RW_S5
#undef _RW_S6
#undef MACRO_START
#undef MACRO_STOP
typedef struct MdlFlags78ec0
{
    u8 pad0[0xD0];
    void* d0;   /* 0xD0 */
    u8 pad0b[4];
    u32 d8;     /* 0xD8 */
    void* dc;   /* 0xDC */
    void* e0;   /* 0xE0 */
    u8 pad1[0xEC - 0xE4];
    u16 ec;     /* 0xEC */
    u8 pad2[0x234 - 0xEE];
    u8* p234;   /* 0x234 */
    u8 pad3[0x310 - 0x238];
    void* p310; /* 0x310 */
    s32 p314;   /* 0x314 */
} MdlFlags78ec0;
extern void RpSkyRenderStateSet(s32 a, s32 b);
extern void (*D_00887304[])(s32, void*);
extern void func_00479910(void* a);
extern void* func_003bfae0_1(void* a);
extern void (*D_00887300_abs[])(s32, s32);
/* P4 port probe: opt_propagation off prevents mwcc folding the D_00887300_abs
   array address into per-call lui/lw (same measured fix as func_00478ec0). */
#pragma opt_propagation off

/* measured: the D3/7000F branch condition is (f&0x200)!=0 && (f&0x400)==0
   (the 0x400-beqz goes to the D3 part, not the 7000F). Residual: mwcc b210
   materializes param_1+0xD8 into $s0 (frame 0x40 vs 0x50, retail keeps the
   D_00887300 base in $s0) and mirrors the block layout (D3 inline + 7000F
   out-of-line vs retail's 7000F inline + D3 out-of-line). Tried: u8* params
   (94), condition flips. Address-CSE + if-placement floor. */
// FUN_00476C70
void func_00476c70(MdlFlags78ec0* o)
{
    void (**base)(s32, s32);
    void* node;
    void* list;
    void* elem;
    s32 sp4C;

    RpSkyRenderStateSet(2, 0x64);
    if (!(o->d8 & 0x200) || (o->d8 & 0x400)) {
        RpSkyRenderStateSet(3, 0x7000F);
    } else if (*(u8*)((u8*)o + 0xD3) > 0xC8) {
        RpSkyRenderStateSet(3, 0x704FD);
    } else {
        RpSkyRenderStateSet(3, 0x7008D);
    }
    base = D_00887300_abs;
    base[0](6, 1);
    D_00887304[0](0xE, &sp4C);
    base[0](0xE, 0);
    if (o->e0 == NULL || (o->d8 & 0x200)) {
        func_00479910(o->dc);
    } else {
        list = D_008872E0[0];
        node = *(void**)((u8*)o->e0 + 8);
        while (node != NULL) {
            if (RwCameraFrustumTestSphere(list, func_003bfae0_1(*(void**)((u8*)node + 0))) != 0) {
                elem = *(void**)((u8*)node + 0);
                ((void (*)(void*))*(void**)((u8*)elem + 0x48))(elem);
            }
            node = *(void**)((u8*)node + 0x24);
        }
    }
    base[0](0xE, sp4C);
}
#pragma opt_propagation on

// FUN_00476E10
void* func_00476e10(void* param_1, void* data)
{
    u8* iVar1;
    u32 uVar2;
    u32 uVar3;

    iVar1 = *(u8**)((u8*)param_1 + 0x18);
    uVar2 = *(u32*)(iVar1 + 0x24);
    for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
        func_004585c0((u8*)(*(u32**)(iVar1 + 0x20))[uVar3]);
    }

    return param_1;
}




typedef struct MdlMaterialColorReal { f32 red, green, blue, alpha; } MdlMaterialColorReal;
typedef struct MdlMaterialColor { u32 unknown00; RwRGBA color; } MdlMaterialColor;
typedef struct MdlMaterialColorGeometry {
    u8 unknown00[8];
    u32 flags;
    u8 unknown0c[20];
    MdlMaterialColor** materials;
    u32 count;
} MdlMaterialColorGeometry;

/* RwRGBA -> RwRGBAReal normalisation.  The 1/255 scale is a float literal, so
 * MWCC places it in .sdata and reloads it per channel (gp-relative), while the
 * shared 0.0f accumulator seed of the quantiser stays CSE'd across channels. */
#pragma push
#pragma always_inline on

static inline void mdlColorToReal(MdlMaterialColorReal* out, const RwRGBA* color)
{
    out->red = (f32)(u32)color->red * (1.0f / 255.0f);
    out->green = (f32)(u32)color->green * (1.0f / 255.0f);
    out->blue = (f32)(u32)color->blue * (1.0f / 255.0f);
    out->alpha = (f32)(u32)color->alpha * (1.0f / 255.0f);
}

static inline void mdlColorUnpack(RwRGBA* out, u32 packed)
{
    out->blue = packed;
    out->green = packed >> 8;
    out->red = packed >> 16;
    out->alpha = packed >> 24;
}

static inline void mdlColorQuantize(RwRGBA* out, const MdlMaterialColorReal* color)
{
    f32 maximum = 255.0f;
    f32 bias = 0.5f;
    out->red = (s32)(bias + maximum * color->red);
    out->green = (s32)(bias + maximum * color->green);
    out->blue = (s32)(bias + maximum * color->blue);
    out->alpha = (s32)(bias + maximum * color->alpha);
}

// FUN_00476E90
void* func_00476e90(void* object, void* data)
{
    MdlMaterialColorGeometry* geometry;
    u32 count;
    MdlMaterialColorReal scale;
    u32 index;
    geometry = *(MdlMaterialColorGeometry**)((u8*)object + 0x18);
    geometry->flags |= 0x40;
    count = geometry->count;
    mdlColorToReal(&scale, *(const RwRGBA**)data);
    for (index = 0; index < count; ++index) {
        MdlMaterialColor* material = geometry->materials[index];
        RwRGBA color;
        MdlMaterialColorReal real;
        mdlColorUnpack(&color, (u32)K_Clump_MatUsrDataGetInt((const RpMaterial*)material, (const char*)D_00713160));
        mdlColorToReal(&real, &color);
        real.red *= scale.red;
        real.green *= scale.green;
        real.blue *= scale.blue;
        if ((*(u16*)((u8*)data + 4) & 1) == 0)
            real.alpha *= scale.alpha;
        else
            real.alpha = scale.alpha;
        mdlColorQuantize(&color, &real);
        material->color = color;
    }
    return object;
}
#pragma pop
// FUN_00477260
void func_00477260(void* param_1, u32* param_2, u16 param_3)
{
    struct {
        u32* ptr;
        u16 value;
    } context;

    context.ptr = param_2;
    context.value = param_3;
    func_003bff30(param_1, func_00476e90, &context);
    return;
}



// FUN_004772A0
u32 func_004772a0(void* param_1, u32* param_2)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;
    u32 uVar4;
    u32* entries;

    iVar1 = *(int*)((int)param_1 + 0x18);
    uVar2 = *(u32*)(iVar1 + 0x24);
    uVar4 = 0;
    while (uVar4 < uVar2) {
        entries = *(u32**)(iVar1 + 0x20);
        uVar3 = K_Clump_MatUsrDataGetInt((const RpMaterial*)entries[uVar4], "per3modelMatColor");
        if (uVar3 >> 0x18 != 0) {
            *param_2 = 0;
            return 0;
        }
        uVar4 = uVar4 + 1;
    }
    return (u32)param_1;
}



// FUN_00477350
void* func_00477350(void* param_1, void* param_2)
{
    void* p = *(void**)((u8*)param_1 + 0x18);
    u32 count = *(u32*)((u8*)p + 0x24);
    u32 i = 0;
    while (i < count) {
        void* e = (void*)*(u32*)((u8*)*(void**)((u8*)p + 0x20) + i * 4);
        if ((RpMatFXMaterialGetEffects(e) & 2) != 0) {
            func_0039a260(e, (void*)*(u32*)param_2);
        }
        i++;
    }
    return param_1;
}

// FUN_00477400
void func_00477400(void* param_1, int param_2)
{
    func_003bff30(param_1, func_00477350, &param_2);
}

// FUN_00477430
void* func_00477430(void* param_1, void* data)
{
    void* p = *(void**)((u8*)param_1 + 0x18);
    u32 count = *(u32*)((u8*)p + 0x24);
    u32 i = 0;
    while (i < count) {
        void* e = (void*)*(u32*)((u8*)*(void**)((u8*)p + 0x20) + i * 4);
        if ((RpMatFXMaterialGetEffects(e) & 2) != 0) {
            func_0039ab20(e, 2, 3, 0x73001);
        }
        i++;
    }
    return param_1;
}

// FUN_004774E0
void func_004774e0(void* param_1)
{
    func_003bff30(param_1, func_00477430, 0);
}

// FUN_00477510
void* func_00477510(void* arg0, void* data)
{
    void* base;
    u32 count;
    u32 i;
    void* item;
    f32 buf[3];

    base = *(void**)((u8*)arg0 + 0x18);
    count = *(u32*)((u8*)base + 0x24);
    for (i = 0; i < count; i++) {
        item = (void*)*(u32*)((u8*)*(void**)((u8*)base + 0x20) + i * 4);
        if (K_Clump_MatUsrDataHasData(item, D_00713180) != 0 &&
            K_Clump_MatUsrDataHasData(item, D_007131A0) != 0 &&
            K_Clump_MatUsrDataHasData(item, D_007131C0) != 0) {
            buf[0] = func_004579a0((const RpMaterial*)item, (const char*)D_00713180);
            buf[2] = func_004579a0((const RpMaterial*)item, (const char*)D_007131A0);
            buf[1] = func_004579a0((const RpMaterial*)item, (const char*)D_007131C0);
        } else {
            buf[0] = fGpffff809c;
            buf[2] = fGpffff809c;
            buf[1] = fGpffff809c;
        }
        *(RwV3d*)((u8*)item + 0xC) = *(RwV3d*)buf;
    }
    return arg0;
}

// FUN_00477660
void* func_00477660(void* param_1, void* data)
{
    RwV3d* param_2 = data;
    void* p = *(void**)((u8*)param_1 + 0x18);
    u32 count = *(u32*)((u8*)p + 0x24);
    u32 i = 0;
    while (i < count) {
        void* e = (void*)*(u32*)((u8*)*(void**)((u8*)p + 0x20) + i * 4);
        *(RwV3d*)((u8*)e + 0xC) = *param_2;
        i++;
    }
    return param_1;
}

/* measured: complete aggregate-buffer reconstruction matches every real
   instruction (264B object versus 272B window); the trailing 8B are two
   alignment nops after jr/nop. The previous six residual rows were the
   filter-result/item-pointer and loop-counter $s-register allocation swaps;
   declaration order now reproduces retail exactly (nd 0). */
// FUN_004776C0
void *func_004776c0(void *arg0, void *arg1)
{
    extern s32 strlen(s32 value);
    extern s32 strncmp(s32 a, s32 b, s32 c);
    extern u32 K_Clump_MatUsrDataGetInt(void* object, void* name);
    extern void func_004586f0(void* object, void* data);
    u8 buf[4];
    u8 *pArg1;
    u32 value;
    u8 *temp_19;
    u32 var_18;
    u32 temp_22;
    s32 temp_17;
    u8 *temp_16;
    pArg1 = (u8 *)arg1;
    temp_16 = *(u8 **)((u8 *)arg0 + 0x18);
    temp_22 = *(u32 *)(temp_16 + 0x24);
    temp_17 = strlen(*(s32 *)(pArg1 + 4));
    var_18 = 0;
    while (var_18 < temp_22) {
        temp_19 = (u8*)*(u32*)(*(u8 **)(temp_16 + 0x20) + var_18 * 4);
        if (strncmp(*(s32 *)(pArg1 + 4), (s32)func_00474ce0(temp_19), temp_17) == 0) {
            value = K_Clump_MatUsrDataGetInt(temp_19, D_00713160);
            buf[2] = (u8)value;
            buf[1] = (u8)(value >> 8);
            buf[0] = (u8)(value >> 16);
            buf[3] = *(u8 *)(pArg1 + 0);
            func_004586f0(temp_19, buf);
        }
        var_18 += 1;
    }
    return arg0;
}
// FUN_004777D0
void func_004777d0(void* param_1, int param_2, u8 param_3)
{
    struct {
        u8 b;
        int i;
    } s;
    s.b = param_3;
    s.i = param_2;
    func_003bff30(*(void**)((u8*)param_1 + 0xDC), func_004776c0, &s);
}

/* measured: retail hoists the 1.0f const (lui/mtc1 -> $f3) to function top and
   allocates inv184=$f2, inv188=$f1, product=$f5; mwcc b210 materializes the
   const at the use site into $f1 and lands the product in $f2; with
   #pragma opt_loop_invariants on the const hoists but the whole allocation
   permutes (counter $v1<->$a2, const $f4, nd 55). Integer t-regs are permuted
   in both loops regardless (p8 $t0 vs $t1, mask regs). Tried: plain C (nd 45),
   one=1.0f local (nd 45), pragma on (nd 55). Register-coloring floor. */
 
// FUN_00477810
/* measured probe: hoist invariant constant for retail prologue. */
#pragma opt_loop_invariants on
void func_00477810(void *arg0, void *arg1)
{
    s32 i;
    s32 j;
    s32 idx;
    s32 jidx;
    f32 one;
    f32 f5;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    u8 *src;
    u8 *dst;

    one = 1.0f;
    i = 0;
    while ((i & 0xFFFF) < 0x10) {
        idx = (u16)i;
        src = (u8 *)arg1 + idx * 2;
        if (*(u16 *)(src + 0x198) > 0) {
            if ((i & 0xFFFF) == 0) {
                f4 = *(f32 *)((u8 *)arg1 + 0x18C);
                f0 = *(f32 *)((u8 *)arg1 + 0x184);
                f2 = one / f0;
                f0 = *(f32 *)((u8 *)arg1 + 0x188);
                f1 = one / f0;
                f0 = *(f32 *)((u8 *)arg1 + 0x190);
                f0 = mdlMulOrdered77810(f4, f0);
                f0 = mdlMulOrdered77810(f2, f0);
                f5 = mdlMulOrdered77810(f1, f0);
                f1 = mdlMulOrdered77810(f4, f2);
            }
            j = 0;
            while ((j & 0xFFFF) < 2) {
                jidx = (u16)j;
                dst = (u8 *)arg0 + jidx * 0xA4;
                *(f32 *)(dst + 0x12C) = f1;
                *(f32 *)(dst + 0x130) = f5;
                *(f32 *)(dst + 0x134) = f5;
                *(f32 *)(dst + 0x138) = *(f32 *)((u8 *)arg1 + 0x18C);
                *(f32 *)(dst + 0x13C) = *(f32 *)((u8 *)arg1 + 0x190);
                *(s32 *)(dst + 0x128) = *(u16 *)(src + 0x198);
                *(u16 *)(dst + 0xEC) |= 0x10;
                j = (j + 1) & 0xFFFF;
            }
        }
        i = (i + 1) & 0xFFFF;
    }
}
/* measured probe: close invariant pragma. */
#pragma opt_loop_invariants off

/* Removing this loses FUN_00477900 (MATCH nd0 -> MISMATCH nd51) - measured W161 (ported from P3FES donor; re-probed in P4: nd0 -> nd51). */
#pragma opt_loop_invariants on

// FUN_00477900
void* func_00477900(void* param_1, void* data)
{
    u8* iVar1;
    u32 uVar2;
    int offset;
    u8* base;
    u8* iVar3;
    u8* iVar4;
    u32 uVar5;
    f32 two;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    volatile /* Removing this qualifier loses func_00477900 (MATCH nd0 -> MISMATCH nd105, size 172 -> 132) - measured W170 (ported from P3FES donor; re-probed in P4: nd0 -> nd105, size 132). */ f32 values[4];

    iVar4 = param_1;
    iVar1 = *(u8**)(iVar4 + 0x18);
    if (iVar1 == 0)
        goto done;

    uVar2 = *(u32*)(iVar1 + 0x18);
    uVar5 = 0;
    two = 2.0f;
    goto check;

loop:
    offset = uVar5 * 8;
    offset = offset - uVar5;
    offset = offset * 4;
    base = *(u8**)(iVar1 + 0x5c);
    iVar3 = base + offset;
    values[0] = *(f32*)(iVar3 + 4);
    values[1] = *(f32*)(iVar3 + 8);
    values[2] = *(f32*)(iVar3 + 0xc);
    values[3] = two * *(f32*)(iVar3 + 0x10);
    x = values[0];
    y = values[1];
    z = values[2];
    w = values[3];
    *(f32*)(iVar3 + 4) = x;
    *(f32*)(iVar3 + 8) = y;
    *(f32*)(iVar3 + 0xc) = z;
    *(f32*)(iVar3 + 0x10) = w;
    uVar5 = uVar5 + 1;
check:
    if (uVar5 < uVar2)
        goto loop;

done:
    *(u32*)(iVar4 + 0x4c) = *(u32*)(iVar4 + 0x4c) | 2;
    return param_1;
}
#pragma opt_loop_invariants off




/* measured: volatile RwRGBA* color forces the four lbu color loads in source
   order (removing it rotates/reorders them, nd 9). */
// FUN_004779B0
void* func_004779b0(u32 type, u16 id)
{
    u8* obj;
    u32 i;
    void** head;
    u8* prev;
    volatile RwRGBA* color;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;

    func_0044ea90(D_00713138, 0x108A);
    obj = ((void* (*)(int, int))DAT_008873e8[0])(0x320, 0x40000);
    memset(obj, 0, 0x320);
    *(s32*)(obj + 0xD8) = 0x10118;
    *(u8*)(obj + 0xD0) = 0xFF;
    *(u8*)(obj + 0xD1) = 0xFF;
    *(u8*)(obj + 0xD2) = 0xFF;
    *(u8*)(obj + 0xD3) = 0xFF;
    color = (RwRGBA*)(obj + 0xD0);
    red = color->red;
    green = color->green;
    blue = color->blue;
    alpha = color->alpha;
    *(u8*)(obj + 0x300) = red;
    *(u8*)(obj + 0x301) = green;
    *(u8*)(obj + 0x302) = blue;
    *(u8*)(obj + 0x303) = alpha;
    *(u16*)(obj + 0xD4) = type;
    *(u16*)(obj + 0xD6) = id;
    *(s32*)(obj + 0xE4) = 0x44;
    *(s32*)(obj + 0xE8) = 0x717FB;
    *(s32*)(obj + 0x2FC) = iGpffffbb28;
    *(s32*)(obj + 0x28) = 0x3F800000;
    *(s32*)(obj + 0x14) = 0x3F800000;
    *(s32*)(obj + 0x00) = 0x3F800000;
    *(s32*)(obj + 0x10) = 0;
    *(s32*)(obj + 0x08) = 0;
    *(s32*)(obj + 0x04) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x18) = 0;
    *(s32*)(obj + 0x38) = 0;
    *(s32*)(obj + 0x34) = 0;
    *(s32*)(obj + 0x30) = 0;
    *(s32*)(obj + 0x0C) |= 0x20003;
    *(s32*)(obj + 0x68) = 0x3F800000;
    *(s32*)(obj + 0x54) = 0x3F800000;
    *(s32*)(obj + 0x40) = 0x3F800000;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x48) = 0;
    *(s32*)(obj + 0x44) = 0;
    *(s32*)(obj + 0x64) = 0;
    *(s32*)(obj + 0x60) = 0;
    *(s32*)(obj + 0x58) = 0;
    *(s32*)(obj + 0x78) = 0;
    *(s32*)(obj + 0x74) = 0;
    *(s32*)(obj + 0x70) = 0;
    *(s32*)(obj + 0x4C) |= 0x20003;
    *(s32*)(obj + 0x80) = 0x3F800000;
    *(s32*)(obj + 0x84) = 0x3F800000;
    *(s32*)(obj + 0x88) = 0x3F800000;
    for (i = 0; i < 2; i++) {
        func_00473520(obj + i * 0xA4 + 0xEC);
    }
    *(s32*)(obj + 0x238) = 0;
    *(s8*)(obj + 0x23E) = 1;
    *(s16*)(obj + 0x240) = -1;
    *(s32*)(obj + 0x244) = 0x3F800000;
    memset(obj + 0x258, 0, 8);
    *(s8*)(obj + 0x25A) = 1;
    *(s32*)(obj + 0x25C) = 0x3F800000;
    *(s8*)(obj + 0x260) = 0;
    *(s32*)(obj + 0x274) = 0;
    *(s32*)(obj + 0x278) = 0;
    *(s32*)(obj + 0x27C) = 0;
    *(s8*)(obj + 0x280) = 0x70;
    *(s8*)(obj + 0x281) = 0x70;
    *(s8*)(obj + 0x282) = 0;
    func_0047ea70(obj + 0x2D0);
    for (i = 0; i < 5; i++) {
        func_0047adf0(obj, i & 0xFFFF, -1);
    }
    head = &D_00922BE0[(u16)type];
    prev = *head;
    *(void**)(obj + 0x304) = 0;
    if (prev != 0) {
        *(void**)((u8*)prev + 0x304) = obj;
        *(void**)(obj + 0x308) = prev;
    } else {
        *(void**)(obj + 0x308) = 0;
    }
    *head = obj;
    return obj;
}

// FUN_00477C40
void* func_00477c40(u32 type, u16 id, u32 flags)
{
    void* node = D_00922BE0[type & 0xFFFF];
    u32 v1 = id;
    u32 v2 = flags & 0xFFFF;
    while (node != 0) {
        if (*(u16*)((u8*)node + 0xD6) == v1 &&
            (v2 == 0 || (*(u32*)((u8*)node + 0xD8) & v2) != 0)) {
            break;
        }
        node = *(void**)((u8*)node + 0x308);
    }
    return node;
}

extern void func_0047b060(void* a);
/* measured: MATCH (468B instructions plus 12 zero-tail bytes). The u16
   loop counter preserves retail masks; the canonical hierarchy constructor
   prototype preserves load-before-move argument materialization. */
// FUN_00477CA0
void func_00477ca0(u8* arg0)
{
    extern void func_0047da30(u32*);
    extern f32 fGpffff80cc;
    f32 values[3];
    u8 (*entries)[0xA4];
    s32* temp_4;
    u16 var_17;
    u16 temp_3;
    u32 temp_4_2;
    u8* temp_16;

    entries = (u8 (*)[0xA4])arg0;
    func_003bff30(*(void**)(arg0 + 0xDC), func_00477900, NULL);
    if (*(s32*)(arg0 + 0x254) != 0) {
        func_00474df0(arg0 + 0x23C, *(void**)(arg0 + 0xDC));
    }
    if (func_00479ca0(arg0, 0) != 0) {
        func_00473710(arg0 + 0xEC, *(void**)(arg0 + 0xDC), 1);
        func_00479940(arg0, 0, 0, 0, 1);
        for (var_17 = (u64)1; (var_17 & 0xFFFF) < 2; var_17++) {
            temp_16 = entries[var_17];
            if (*(s32*)(temp_16 + 0x120) != 0) {
                *(u16*)(temp_16 + 0xEC) = *(u16*)(temp_16 + 0xEC) | 2;
                temp_4 = *(s32**)(arg0 + 0x10C);
                temp_4_2 = *temp_4;
                *(s32*)(temp_16 + 0x10C) = (s32)func_003971d0((u8*)temp_4, 0, temp_4_2, -1);
            }
        }
    }
    *(void**)(arg0 + 0xE0) = func_00462ae0(*(void**)(arg0 + 0xDC));
    func_003bff30(*(void**)(arg0 + 0xDC), func_00476e10, NULL);
    temp_3 = *(u16*)(arg0 + 0xD4);
    switch (temp_3) {
    case 1:
    case 2:
        values[0] = fGpffff80cc;
        values[2] = 1.0f;
        values[1] = fGpffff809c;
        func_003bff30(*(void**)(arg0 + 0xDC), func_00477660, values);
        break;
    default:
        func_003bff30(*(void**)(arg0 + 0xDC), func_00477510, NULL);
        break;
    }
    temp_4_2 = *(u32*)(arg0 + 0x2CC);
    if (temp_4_2 != 0) {
        func_0047da30((u32*)temp_4_2);
    }
}
// FUN_00477E80
void* func_00477e80(u32 type, u16 id, void* param_3, u32 param_4)
{
    void* obj = func_004779b0(type, id);
    if ((param_4 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    func_0047aff0(obj, param_3);
    func_004782b0(obj);
    return obj;
}

// FUN_00477F10
void* func_00477f10(u32 type, u16 id, void* memory, u32 size, u32 flags)
{
    void* obj = func_004779b0(type, id);
    if ((flags & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    {
        struct {
            void* memory;
            u32 size;
        } data;
        data.memory = memory;
        data.size = size;
        func_0047afd0(obj, &data);
    }
    func_004782b0(obj);
    return obj;
}

/* MATCHED this wave (nd 0, object 400B/window 400B): the former slot-coalescing
   / saved-register-rotation floor was disproved.  A return-tail `return arg2;`
   shape and distinct pair structs reproduce the retail stack layout and
   return path; the previous nd-74/nd-9 layouts are retained here only as
   historical probe context. */
// FUN_00477FB0
void* func_00477fb0(u32 arg0, u16 arg1, void* arg2, u32 arg3)
{
    extern u8* func_00455ea0(u8*, s32, s32*);
    extern void func_0047e450(void**, u32, u16, s32, u32);
    void* obj;
    void* result;
    u32 stack9c;
    u32 retA;
    u32 retVal;
    u32 retB;
    struct {
        u32 a;
        u32 b;
    } pair0;
    struct {
        u32 a;
        u32 b;
    } pair1;

    if (func_0047d0e0(arg0, arg1) == 0) {
        retA = *(u32*)((u8*)arg2 + 0x110);
        retVal = *(u32*)((u8*)arg2 + 0x118);
        stack9c = retVal;
        arg2 = func_004779b0(arg0, arg1);
        if ((arg3 & 1) != 0) {
            *(u32*)((u8*)arg2 + 0xD8) |= 0x4000;
        }
        func_0047af60(arg2);
        pair0.a = retA;
        pair0.b = retVal;
        func_0047afd0(arg2, &pair0);
        func_004782b0(arg2);
        return arg2;
    }
    retA = (u32)func_00455ea0(arg2, 0, (s32*)&stack9c);
    retVal = stack9c;
    obj = func_004779b0(arg0, arg1);
    if ((arg3 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    pair1.a = retA;
    pair1.b = retVal;
    func_0047afd0(obj, &pair1);
    func_004782b0(obj);
    retB = (u32)func_00455ea0(arg2, 1, (s32*)&stack9c);
    func_0047e450((void**)((u8*)obj + 0x2D0), arg0, arg1, (s32)retB, stack9c);
    result = obj;
done:
    return result;
}

// FUN_00478140
void* func_00478140(u32 param_1, u16 param_2, u32 param_3)
{
    void* node;
    void* obj;
    void* result;
    u8 buf[0x100];
    u32 id;

    node = D_00922BE0[param_1 & 0xFFFF];
    id = param_2 & 0xFFFF;
    while (node != 0) {
        if (*(u16*)((u8*)node + 0xD6) == id) {
            break;
        }
        node = *(void**)((u8*)node + 0x308);
    }
    if (node == 0) {
        func_0047d110(param_1, param_2, (char*)buf);
        obj = func_004779b0(param_1, param_2);
        if ((param_3 & 1) != 0) {
            *(u32*)((u8*)obj + 0xD8) |= 0x4000;
        }
        func_0047af60(obj);
        func_0047aff0(obj, buf);
        func_004782b0(obj);
        if (func_0047d0e0(param_1, param_2) != 0) {
            func_0047b050(obj, 1);
        }
        result = obj;
        goto done;
    } else {
        obj = func_004779b0(param_1, param_2);
        if ((param_3 & 1) != 0) {
            *(u32*)((u8*)obj + 0xD8) |= 0x4000;
        }
        *(u32*)((u8*)obj + 0xD8) |= 0x2000;
        func_004782b0(obj);
        result = obj;
    }
done:
    return result;
}

// FUN_004782B0
s32 func_004782b0(u8* param_1)
{
    s32 f;
    void* node;
    s32 id2;

    f = *(s32*)(param_1 + 0xD8);
    if ((f & 0x1000) != 0) {
        return 1;
    }
    if ((f & 0x2000) == 0) {
        if (func_0047ce00() == 0) {
            return 0;
        }
        if (func_0047e6f0((void**)(param_1 + 0x2D0)) == 0) {
            return 0;
        }
        func_0047b060(param_1);
        func_00477ca0(param_1);
    } else {
        if (func_0047e6f0((void**)(param_1 + 0x2D0)) == 0) {
            return 0;
        }
        id2 = *(u16*)(param_1 + 0xD6);
        node = D_00922BE0[*(u16*)(param_1 + 0xD4)];
        while (node != 0) {
            if (*(u16*)((u8*)node + 0xD6) == id2 &&
                (*(s32*)((u8*)node + 0xD8) & 0x1000) != 0) {
                break;
            }
            node = *(void**)((u8*)node + 0x308);
        }
        if (node == 0) {
            return 0;
        }
        func_00478410(node, param_1);
        *(s32*)(param_1 + 0xD8) &= ~0x2000;
    }
    *(s32*)(param_1 + 0xD8) |= 0x1000;
    return 1;
}


typedef struct MdlMatrixEntry {
    RwMatrix matrix;
    s32 id;
    s32 frameId;
    u8 unknown[8];
} MdlMatrixEntry;

typedef struct MdlMatrixTable {
    u16 count;
    u16 unknown;
    MdlMatrixEntry* entries;
} MdlMatrixTable;

typedef struct MdlCloneAttachmentTable {
    union {
        u32 word;
        struct {
            u16 count;
            u16 unknown02;
        } halves;
    } count;
    RwRGBA color;                  /* 0x04 */
    RwV3d scale;                   /* 0x08 */
    void** primary;                 /* 0x14 */
    void* primaryDraw;             /* 0x18 */
    void* nextPrimary;             /* 0x1c */
    void** secondary;               /* 0x20 */
    void* secondaryDraw;           /* 0x24 */
    void* nextSecondary;           /* 0x28 */
    u32 pendingSecondary;          /* 0x2c */
    u16 delay;                     /* 0x30 */
    u16 unknown32;                 /* 0x32 */
} MdlCloneAttachmentTable;

typedef struct MdlCloneHierarchyView {
    u32 flags;
} MdlCloneHierarchyView;

typedef struct MdlCloneLayerView {
    u16 flags;                     /* relative 0x00, model 0xec */
    u8 unknown02[0x1e];
    MdlCloneHierarchyView* hierarchy; /* relative 0x20, model 0x10c */
    u8 unknown24[8];
    RtAnimInterpolator* first;     /* relative 0x2c */
    RtAnimInterpolator* second;    /* relative 0x30 */
    MdlDispatchAnimTable* resource; /* relative 0x34, model 0x120 */
    MdlCloneAttachmentTable* attachments; /* relative 0x38 */
    u8 unknown3c[0x68];             /* next layer at 0xa4 */
} MdlCloneLayerView;

static inline MdlCloneAttachmentTable* mdl_clone_attachment_storage(u32 count)
{
    MdlCloneAttachmentTable* copy;
    s32 size = sizeof(MdlCloneAttachmentTable);
    size += count * sizeof(void*);
    size += count * sizeof(void*);
    func_0044ea90(D_00713138, 0x1d6);
    copy = ((void* (*)(int, int))DAT_008873e8[0])(size, 0x40000);
    memset(copy, 0, size);
    copy->count.word = (u16)count;
    copy->primary = (void**)(copy + 1);
    copy->secondary = copy->primary + (u16)count;
    return copy;
}

/* IDA mdlManager.c:2448-2545; 824B instructions plus eight zero-tail bytes.
   Preserve the model-relative layer base, separately sized attachment arrays
   and callback-visible table reloads. Counts originate in unsigned halfwords. */
// FUN_00478410
void func_00478410(u8* source, u8* destination)
{
    u32 layer;

    if (*(void**)(source + 0xdc) != 0) {
        void* clump = func_003c0520(*(void**)(source + 0xdc));
        *(void**)(destination + 0xdc) = clump;
        *(void**)(destination + 0xe0) = func_00462ae0(clump);
    }
    for (layer = 0; layer < 2; layer++) {
        if (func_00479ca0(source, (u16)layer) != 0) {
            MdlCloneLayerView* sourceLayer =
                (MdlCloneLayerView*)(source + 0xec + layer * 0xa4);
            MdlDispatchAnimTable* resource = sourceLayer->resource;
            u8* destinationBase;

            resource->references++;
            destinationBase = destination + layer * 0xa4;
            ((MdlCloneLayerView*)(destinationBase + 0xec))->resource = resource;
            if ((sourceLayer->flags & 2) == 0) {
                func_00473710(destinationBase + 0xec, *(u8**)(destination + 0xdc), 0);
            } else {
                ((MdlCloneLayerView*)(destinationBase + 0xec))->flags |= 2;
                {
                    MdlCloneHierarchyView* hierarchy =
                        ((MdlCloneLayerView*)(destination + 0xec))->hierarchy;
                    ((MdlCloneLayerView*)(destinationBase + 0xec))->hierarchy =
                        (MdlCloneHierarchyView*)func_003971d0((u8*)hierarchy, 0, hierarchy->flags, -1);
                }
            }
        }
        {
            MdlCloneAttachmentTable* original =
                ((MdlCloneLayerView*)(source + 0xec + layer * 0xa4))->attachments;
            if (original != 0) {
                MdlCloneAttachmentTable* copy = mdl_clone_attachment_storage(original->count.halves.count);
                u32 index;
                for (index = 0; index < copy->count.word; index++) {
                    void** primary = original->primary;
                    if (primary[index] != 0) {
                        void* cloned = func_0047d200(primary[index]);
                        copy->primary[index] = cloned;
                    }
                    if (original->secondary[index] != 0) {
                        void* cloned = func_0047dc30(original->secondary[index]);
                        copy->secondary[index] = cloned;
                    }
                }
                ((MdlCloneLayerView*)(destination + 0xec + layer * 0xa4))->attachments = copy;
            }
        }
    }
    {
        MdlAnimEntryTable* resource = *(MdlAnimEntryTable**)(source + 0x234);
        if (resource != 0) {
            resource->unk_06++;
            *(MdlAnimEntryTable**)(destination + 0x234) = resource;
        }
    }
    {
        MdlAnimResourceView* resource = ((MdlAnimControlView*)(source + 0x23c))->resource;
        if (resource != 0) {
            resource->unknown0e++;
            ((MdlAnimControlView*)(destination + 0x23c))->resource = resource;
            func_00474df0(destination + 0x23c, *(void**)(destination + 0xdc));
            ((MdlAnimControlView*)(destination + 0x23c))->mode = 1;
        }
    }
    {
        MdlMatrixTable* resource = *(MdlMatrixTable**)(source + 0x2c8);
        if (resource != 0) {
            resource->unknown++;
            *(MdlMatrixTable**)(destination + 0x2c8) = resource;
        }
    }
    if (*(void**)(source + 0x2cc) != 0) {
        void* copy = func_0047d200(*(void**)(source + 0x2cc));
        *(void**)(destination + 0x2cc) = copy;
        func_0047da30(copy);
    }
    if (*(void**)(source + 0x2d0) != 0)
        func_0047ea40(destination + 0x2d0, source + 0x2d0);
    if (func_00479ca0(destination, 0) != 0)
        func_00479940(destination, 0, 0, 0, 1);
}
// FUN_00478750
u32* func_00478750(u8* param_1)
{
    u32* obj;

    obj = func_004779b0(*(u16*)(param_1 + 0xD4), *(u16*)(param_1 + 0xD6));
    if ((*(s32*)(param_1 + 0xD8) & 0x1000) != 0) {
        func_00478410(param_1, (u8*)obj);
        *(s32*)((u8*)obj + 0xD8) |= 0x1000;
    } else {
        *(s32*)((u8*)obj + 0xD8) |= 0x2000;
    }
    return obj;
}

// FUN_004787E0
void func_004787e0(u8* param_1)
{
    u32 i;
    void* t;

    if (*(void**)(param_1 + 0xDC) != 0) {
        func_003c0700(*(void**)(param_1 + 0xDC));
    }
    for (i = 0; i < 2; i++) {
        func_004735b0(param_1 + i * 0xA4 + 0xEC);
    }
    if (*(void**)(param_1 + 0x234) != 0) {
        func_004745f0(*(void**)(param_1 + 0x234));
        *(void**)(param_1 + 0x234) = 0;
    }
    if (*(void**)(param_1 + 0x254) != 0) {
        func_00474890(*(void**)(param_1 + 0x254));
        *(void**)(param_1 + 0x254) = 0;
    }
    t = *(void**)(param_1 + 0x2C8);
    if (t != 0) {
        *(u16*)((u8*)t + 2) = *(u16*)((u8*)t + 2) - 1;
        if (*(u16*)((u8*)t + 2) == 0) {
            DAT_008873ec[0](*(void**)((u8*)t + 4));
        }
    }
    if (*(void**)(param_1 + 0xE0) != 0) {
        func_00462bf0(*(void**)(param_1 + 0xE0));
    }
    for (i = 0; i < 5; i++) {
        if ((*(u8*)(param_1 + i * 0xC + 0x28C) & 1) != 0 &&
            *(void**)(param_1 + i * 0xC + 0x290) != 0) {
            func_0047ae10(param_1, i & 0xFFFF);
        }
    }
    func_004b7140(param_1);
    if (*(void**)(param_1 + 0x2CC) != 0) {
        func_0047d2d0(*(void**)(param_1 + 0x2CC));
    }
    func_0047eaa0(param_1 + 0x2D0);
    if (*(void**)(param_1 + 0x308) != 0) {
        *(void**)((u8*)*(void**)(param_1 + 0x308) + 0x304) = *(void**)(param_1 + 0x304);
    }
    if (*(void**)(param_1 + 0x304) != 0) {
        *(void**)((u8*)*(void**)(param_1 + 0x304) + 0x308) = *(void**)(param_1 + 0x308);
    } else {
        D_00922BE0[*(u16*)(param_1 + 0xD4)] = *(void**)(param_1 + 0x308);
    }
    DAT_008873ec[0](param_1);
}
// FUN_004789C0
void func_004789c0(Model* mdl)
{
    RwMatrix matrix;
    void* frame;

    frame = *(void**)((u8*)mdl->clump + 4);
    RwMatrixMultiply(&matrix, &mdl->identityMat, (void*)mdl);
    func_003e9cb0(frame, &matrix, 0);
    func_0047aee0(mdl, &matrix);
}



extern void func_00475820(void* a, void* b);
extern u8* func_00473b20(u8* a, u8* b, s32 c);
extern s32 func_0047a510(void* a, s32 b, void* c);
extern void* mdlGetMatrix(void* a);
extern void func_0047dae0(u32 a);
extern void func_0047de50(u32 a);
extern void func_0047de00(u32 a, void* b);
extern void func_0047dd40(u8* a, void* model);
extern void func_0047d900(s32* a, f32* b);
extern void func_0047d540(u8** a, u8* b);
extern void func_0047ed60(void* a);
extern void func_0047a0e0(u8* a, s32 b, f32 c);
extern void func_0047aa10(void* a, RwV3d* b);
extern int func_0047a9d0(void* a);
/* Measured: 1080B/window 1088B, MATCH with two zero-padding words.
   Cache predicate inputs only until their immediate call; reload every
   callback-visible field afterward. CSE-off retains per-phase matrix
   addresses; propagation-off preserves the post-getter frame-ID snapshot. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00478A30
void func_00478a30(u8* mdl, s32 tick)
{
    RwMatrix matrix;
    void* frame;
    u8* previousLayer;
    u32 animationLayer;
    u32 switchLayer;
    u32 updateLayer;
    MdlCloneAttachmentTable* attachments;
    u32 child;
    void* draw;
    s32 delay;

    if ((*(u32*)(mdl + 0xD8) & 0x1000) != 0) {
        frame = *(void**)((u8*)((Model*)mdl)->clump + 4);
        RwMatrixMultiply(&matrix, &((Model*)mdl)->identityMat, mdl);
        func_003e9cb0(frame, &matrix, 0);
        func_0047aee0((Model*)mdl, &matrix);
        previousLayer = 0;
        if (func_0047a9d0(mdl) != 0) {
            func_0047aa10(mdl, &((Model*)mdl)->scale);
        }
        for (animationLayer = 0; animationLayer < 2; animationLayer++) {
            if (func_00479ca0(mdl, (u16)animationLayer) != 0) {
                previousLayer = func_00473b20(mdl + animationLayer * 0xA4 + 0xEC,
                                             previousLayer, tick);
            }
        }
        *(u32*)(mdl + 0xD8) |= 0x80000;
        func_00475820(mdl + 0x23C, mdl + 0xEC);
        for (switchLayer = 0; switchLayer < 2; switchLayer++) {
            attachments = ((MdlCloneLayerView*)(mdl + switchLayer * 0xA4 + 0xEC))->attachments;
            if (attachments != 0) {
                draw = attachments->primaryDraw;
                if (attachments->nextPrimary != draw) {
                    if (draw != 0) {
                        func_0047dae0((u32)draw);
                    }
                    draw = attachments->nextPrimary;
                    if (draw != 0) {
                        func_0047da30(draw);
                    }
                    attachments->primaryDraw = attachments->nextPrimary;
                }
                if (attachments->pendingSecondary != 0) {
                    draw = attachments->secondaryDraw;
                    if (draw != 0) {
                        func_0047de50((u32)draw);
                    }
                    draw = attachments->nextSecondary;
                    if (draw != 0) {
                        func_0047de00((u32)draw, mdl);
                    }
                    attachments->secondaryDraw = attachments->nextSecondary;
                    attachments->pendingSecondary = 0;
                }
            }
        }
        if (tick != 0) {
            draw = *(void**)(mdl + 0x2CC);
            if (draw != 0) {
                func_0047d900((s32*)draw, (f32*)&((Model*)mdl)->scale);
                func_0047d540(*(u8***)(mdl + 0x2CC), mdl);
            }
            for (updateLayer = 0; updateLayer < 2; updateLayer++) {
                attachments = ((MdlCloneLayerView*)(mdl + updateLayer * 0xA4 + 0xEC))->attachments;
                if (attachments != 0) {
                    draw = attachments->primaryDraw;
                    if (draw != 0 && attachments->delay == 0) {
                        func_0047d900((s32*)draw, (f32*)&attachments->scale);
                        func_0047d540((u8**)attachments->primaryDraw, mdl);
                    }
                    draw = attachments->secondaryDraw;
                    if (draw != 0 && attachments->delay == 0) {
                        func_0047dd40((u8*)draw, mdl);
                    }
                    delay = attachments->delay;
                    if (delay > 0) {
                        attachments->delay = delay - 1;
                    }
                }
            }
        }
        func_0047ed60(mdl + 0x2D0);
        for (child = 0; child < 5; child++) {
            u8* childBase = mdl + child * 0xC;
            if ((*(u8*)(childBase + 0x28C) & 1) != 0) {
                void** childSlot = (void**)(childBase + 0x290);
                if (*childSlot != 0 && func_0047ae90(mdl, (u16)child) != 0) {
                    ((Model*)*childSlot)->identityMat = ((Model*)mdl)->identityMat;
                    if (tick != 0) {
                        s32* frameId = (s32*)(childBase + 0x294);
                        if (*frameId != -1) {
                            void* childMatrix = mdlGetMatrix(*childSlot);
                            s32 childFrame = *frameId;
                            func_0047a510(mdl, childFrame, childMatrix);
                        } else {
                            ((Model*)*childSlot)->mat = ((Model*)mdl)->mat;
                        }
                    }
                    {
                        void** updateSlot = (void**)(mdl + child * 0xC + 0x290);
                        func_0047a0e0(*updateSlot, 0, *(f32*)(mdl + 0xF4));
                        func_00478a30(*updateSlot, tick);
                    }
                }
            }
        }
    }
}
#pragma pop

// FUN_00478EA0
void func_00478ea0(void* param_1, int param_2, int param_3)
{
    *(int*)((u8*)param_1 + 0x310) = param_2;
    *(int*)((u8*)param_1 + 0x314) = param_3;
}

// FUN_00478EB0
void func_00478eb0(void* param_1, int param_2, int param_3)
{
    *(int*)((u8*)param_1 + 0x318) = param_2;
    *(int*)((u8*)param_1 + 0x31C) = param_3;
}

extern void func_004746b0(u8* a, u8* b);
extern void func_00489f80(u32 a);
extern s64 iGpffffabe8;

/* P4 port probe: opt_propagation off prevents mwcc folding the D_00887300_abs
   array address into per-call lui/lw (measured: with it on, mid-function base
   assignment rematerializes per use). */
#pragma opt_propagation off

// FUN_00478EC0
void func_00478ec0(void* param_1, MdlFlags78ec0* o)
{
    struct {
        void* p38;
        u16 p3C;
    } ctx;
    void (**base)(s32, s32);
    s32 flag;
    void* dc;
    s32 t;

    if (o->d8 & 0x80000) {
        func_004746b0((u8*)o + 0x234, (u8*)o + 0xEC);
        o->d8 &= 0xFFF7FFFF;
    }
    dc = o->dc;
    ctx.p38 = (u8*)o + 0xD0;
    ctx.p3C = 0;
    func_003bff30(dc, func_00476e90, &ctx);
    t = (o->d8 & 8) != 0;
    base = D_00887300_abs;
    base[0](6, t);
    base[0](8, (o->d8 & 0x10) != 0);
    base[0](0xE, (o->d8 & 0x100) != 0);
    if (o->d8 & 0x40) {
        flag = 3;
    } else {
        flag = 2;
    }
    base[0](0x14, flag);
    if (o->d8 & 0x40000) {
        iGpffffabe8 |= 0x80;
    }
    if (o->d8 & 0x100000) {
        func_00489f80(o->d8);
    }
    if (o->p310 != NULL) {
        ((void (*)(void*))o->p310)((void*)o->p314);
    }
}
#pragma opt_propagation on

// FUN_00479080
void func_00479080(void* param_1, void* param_2)
{
    u32* p = (u32*)param_2;
    if ((p[0xD8 / 4] & 0x40000) != 0) {
        DAT_00723cd8 &= ~0x80;
    }
    if ((p[0xD8 / 4] & 0x100000) != 0) {
        func_0048a000();
    }
    if (*(void**)((u8*)p + 0x318) != 0) {
        ((FnVoidPtr)*(void**)((u8*)p + 0x318))(*(void**)((u8*)p + 0x31C));
    }
}

/* Colour tint uses the same RwRGBA <-> real helpers as func_00476e90; the
 * draw-colour forwarder func_0047d8a0 takes the colour by pointer. */
// FUN_00479100
/* IDA mdlManager.c:2696-2870; retail 00479100-00479870.
 * Integration requirements, including attachment fields and the corrected
 * color-forwarding wrapper, are recorded in IDA_model_followthrough.json. */
/* Queue command uses k_draw.c raw offsets (obj+8/0x0C/0x10/0x14/0x18/0x1A/0x1C); no new struct. */

extern u8* func_00460990(void);
extern void func_00460ac0(void*, void*);
extern void func_00478a30(u8*, s32);
extern void func_00479030(u8*, u8*);
extern void func_0047d8a0(u8**, s32*);
extern void func_0047d7e0(s32, u8**);
extern void func_0047ddd0(u8*, const u8*);
extern void func_0047dd70(u8*, u8*);
extern void mdlSetColor(Model*, const RwRGBA*);

void func_00479100(void* queue, u8* model)
{
    u8* command;
    u8* renderCommand;
    u32 flags;
    u16 layer;
    u16 childIndex;
    RwRGBA color;
    u32 uncolored;
    u32 childUncolored;

    flags = *(u32*)(model + 0xd8);
    if ((flags & 0x1000) == 0)
        return;
    if ((flags & 4) == 0)
        func_00478a30(model, (flags & 1) == 0);
    flags = *(u32*)(model + 0xd8);
    if ((flags & 2) != 0)
        return;
    if (model[0xd3] <= 0)
        return;

    if ((flags & 1) != 0 && (flags & 0x8000) == 0)
    {
        command = func_00460990();
        *(u16*)(command + 0x18) = 0x1c;
        *(void**)(command + 0x1c) = model;
        func_00460ac0(*(void**)(model + 0x2f8), command);
    }
    renderCommand = func_00460990();
    if (*(void**)(model + 0xe0) != 0)
    {
        *(void**)(renderCommand + 8) = (void*)func_00478ec0;
        *(void**)(renderCommand + 0x10) = model;
    }
    else
    {
        *(void**)(renderCommand + 8) = (void*)func_00479030;
        *(void**)(renderCommand + 0x10) = model;
    }
    *(void**)(renderCommand + 0x0C) = (void*)func_00479080;
    *(void**)(renderCommand + 0x14) = model;
    flags = *(u32*)(model + 0xd8);
    if ((flags & 0x20) == 0 || ((Model*)model)->color.alpha == 255)
    {
        if (*(void**)(model + 0xe0) == 0)
        {
            *(u16*)(renderCommand + 0x18) = 9;
            *(void**)(renderCommand + 0x1C) = ((Model*)model)->clump;
            func_00460ac0(queue, renderCommand);
        }
        else
        {
            if ((flags & 0x18) == 0x18)
                *(u16*)(renderCommand + 0x1A) &= 0xFFFD;
            else
                *(u16*)(renderCommand + 0x1A) |= 2;
            *(u16*)(renderCommand + 0x18) = 5;
            *(void**)(renderCommand + 0x1C) = *(void**)(model + 0xe0);
            func_00460ac0(queue, renderCommand);
        }
    }
    else
    {
        *(u16*)(renderCommand + 0x18) = 0x1B;
        *(void**)(renderCommand + 0x1C) = model;
        func_00460ac0(queue, renderCommand);
    }

    if (*(void**)(model + 0x2cc) != 0)
    {
        flags = *(u32*)(model + 0xd8);
        if ((flags & 0x20000) != 0)
            goto layers;
        if ((flags & 0x8000) != 0)
        {
            void* clump = ((Model*)model)->clump;
            uncolored = 1;
            func_003bff30(clump, (KClumpCallback)func_004772a0, &uncolored);
            if (uncolored != 0)
                goto layers;
        }
        if ((*(u32*)(model + 0xd8) & 0x80) == 0)
        {
            MdlMaterialColorReal real;
            MdlMaterialColorReal tint;
            mdlColorToReal(&real, &((Model*)model)->color);
            mdlColorToReal(&tint, (RwRGBA*)(model + 0x300));
            real.red *= tint.red;
            real.green *= tint.green;
            real.blue *= tint.blue;
            real.alpha *= tint.alpha;
            mdlColorQuantize(&color, &real);
            func_0047d8a0(*(u8***)(model + 0x2cc), (s32*)&color);
            if (color.alpha > 0)
                func_0047d7e0(*(s32*)(model + 0x2fc), *(u8***)(model + 0x2cc));
        }
        else
        {
            func_0047d7e0(*(s32*)(model + 0x2fc), *(u8***)(model + 0x2cc));
        }
    }

layers:
    for (layer = 0; layer < 2; ++layer)
    {
        MdlCloneAttachmentTable** slot = &((MdlCloneLayerView*)(model + 0xec + (u32)layer * sizeof(MdlCloneLayerView)))->attachments;
        MdlCloneAttachmentTable* attachments = *slot;
        if (attachments != 0 && (*(u32*)(model + 0xd8) & 0x20000) == 0)
        {
            u8* attachmentQueue;
            void* draw;
            attachments->scale = ((Model*)model)->scale;
            if ((*(u32*)(model + 0xd8) & 0x80) == 0)
                (*slot)->color = ((Model*)model)->color;
            attachments = *slot;
            attachmentQueue = *(u8**)(model + 0x2fc);
            draw = attachments->primaryDraw;
            if (draw != 0)
            {
                func_0047d8a0(draw, (s32*)&attachments->color);
                func_0047d7e0((s32)attachmentQueue, attachments->primaryDraw);
            }
            draw = attachments->secondaryDraw;
            if (draw != 0)
            {
                func_0047ddd0(draw, (const u8*)&attachments->color);
                func_0047dd70(attachmentQueue, attachments->secondaryDraw);
            }
        }
    }
    for (childIndex = 0; (s64)childIndex < 5; childIndex++)
    {
        u8* childBase = (u8*)((MdlWpnSlot*)model + (u16)childIndex);
        if ((childBase[0x28c] & 1) != 0)
        {
            void** child = (void**)(childBase + 0x290);
            if (*child != 0 && func_0047ae90(model, childIndex) != 0)
            {
                void* childClump = ((Model*)*child)->clump;
                childUncolored = 1;
                func_003bff30(childClump, (KClumpCallback)func_004772a0, &childUncolored);
                if (childUncolored == 0)
                    *(u32*)((u8*)*child + 0xd8) &= ~0x20000u;
                else
                    *(u32*)((u8*)*child + 0xd8) |= 0x20000;
                mdlSetColor((Model*)*child, &((Model*)model)->color);
                if ((*(u32*)(model + 0xd8) & 0x20) == 0)
                    *(u32*)((u8*)*child + 0xd8) &= ~0x20u;
                else
                    *(u32*)((u8*)*child + 0xd8) |= 0x20;
                func_00479100(queue, *child);
            }
        }
    }
}

// FUN_00479880
void* func_00479880(void* param_1, void* data)
{
    if ((*(u8*)((u8*)param_1 + 2) & 4) == 0) {
        return param_1;
    }
    if (*(void**)((u8*)param_1 + 0x18) != 0) {
        if (RwCameraFrustumTestSphere(D_008872E0[0], func_003bfae0()) != 0) {
            ((FnVoidPtr)*(void**)((u8*)param_1 + 0x48))(param_1);
        }
    }
    return param_1;
}

// FUN_00479910
void func_00479910(void* param_1)
{
    func_003bff30(param_1, func_00479880, 0);
}

/* IDA 00479940, mdlManager.c:2873-2957: validate raw arguments before
   dispatching the base transform, layer animation and attached children.
   Measured 752B/752B, fully relocated exact match. */
#pragma push
#pragma opt_common_subs off

static inline void mdl_dispatch_animation(u8* mdl, u32 layer, s16 animation, u16 frame, s32 flags)
{
    u32 baseLayer;
    u32 narrowFlags;
    u8** blend;
    u16 i;
    void** child;
    baseLayer = (u16)layer;
    if (baseLayer == 0) {
        {
            MdlDispatchAnimTable* table;
            MdlDispatchAnimEntry* entries;
            void* clip;
            s32 offset;
            s32 index = (s16)animation;
            if (index >= 0 && (table = *(MdlDispatchAnimTable**)(mdl + 0x120)) != 0 &&
                index < table->count &&
                (offset = index * 80, entries = table->entries,
                 clip = *(void**)addOff((u32)entries + 64, offset)) != 0 && clip != D_00922BC0_abs) {
                *(RwMatrix*)(mdl + 64) = *(RwMatrix*)((u8*)entries + offset);
            } else {
                RwMatrix* matrix = (RwMatrix*)(mdl + 64);
                matrix->right.x = matrix->up.y = matrix->at.z = 1.0f;
                matrix->up.x = 0.0f;
                matrix->right.z = 0.0f;
                matrix->right.y = 0.0f;
                matrix->at.y = 0.0f;
                matrix->at.x = 0.0f;
                matrix->up.z = 0.0f;
                matrix->pos.z = 0.0f;
                matrix->pos.y = 0.0f;
                matrix->pos.x = 0.0f;
                matrix->flags |= 0x20003;
            }
        }
        if (*(void**)(mdl + 0x234) && (blend = *(u8***)(mdl + 0x238)))
            func_0047fe90(blend, 0.0f, 1.0f);
        func_00475350(*(void**)(mdl + 0xdc), (MdlAnimControlView*)(mdl + 0x23c), animation, frame, flags);
    }
    func_004740c0(mdl + 0xec + (u16)layer * 0xa4, animation, frame, flags);
    if (*(void**)(mdl + 0x2d0) && !((narrowFlags = (u16)flags) & 0x40) && baseLayer == 0) {
        if (narrowFlags & 0x100) {
            *(u16*)(mdl + 0x2e0) &= ~0x20;
            func_0047eb20(mdl + 0x2d0, animation, frame);
        } else {
            *(u16*)(mdl + 0x2e0) |= 0x20;
            func_0047eb20(mdl + 0x2d0, animation, frame);
        }
    }
    if (*(u32*)(mdl + 0xd8) & 0x10000) {
        for (i = 0; (s64)i < 5; i++) {
            u8* slot = mdl + (u16)i * 12;
            if (*(u8*)(slot + 0x28c) & 1) {
                child = (void**)(slot + 0x290);
                if (*child && func_0047ae90(mdl, i))
                    func_00479940(*child, 0, animation, frame, flags);
            }
        }
    }
}
#pragma opt_common_subs on
// FUN_00479940
s32 func_00479940(u8* mdl, u32 layer, s16 animation, u16 frame, s32 flags)
{
    if (func_00479d10(mdl, layer, animation))
        mdl_dispatch_animation(mdl, layer, animation, frame, flags);
    return 1;
}
#pragma pop

// FUN_00479CA0
s32 func_00479ca0(void* param_1, s32 param_2)
{
    u16 mask = (u16)param_2;
    s32 off;
    void* ptr;
    if (mask == 0) {
        if (*(s32*)((u8*)param_1 + 0x120) == 0 && *(s32*)((u8*)param_1 + 0x234) == 0) {
            return 0;
        }
    } else {
        off = (s32)mask * 0xA4;
        ptr = (void*)(off + (s32)param_1);
        if (*(s32*)((u8*)ptr + 0x120) == 0) {
            return 0;
        }
    }
    return 1;
}

/* measured: MATCHED this wave (nd 0, was 91). Levers: (3) addOff index-first
   addu helper, (4) explicit iVar5 temp for the *(u16*)(iVar4+8) load, and
   reusing iVar4 for *obj (iVar4 = *(int*)(iVar4+0)) which routes the load into
   the $a3 mask reg exactly as retail does, with addOff folding index into the
   addu. The (u16)param_2 second check uses plain ints (no mask local). */
/* The signed-short animation contract is shared by the model and battle
   callers. Integer comparisons perform the retail sign extension here. */
// FUN_00479D10
s32 func_00479d10(u8* param_1, u32 param_2, s16 param_3)
{
    int result = 0;
    int iVar4;
    int iVar5;
    iVar4 = *(int*)(addOff((param_2 & 0xffff) * 0xa4, (u32)param_1) + 0x120);
    if (iVar4 != 0) {
        iVar5 = *(u16*)(iVar4 + 8);
        if (param_3 < iVar5) {
            iVar4 = *(int*)(iVar4 + 0);
            if (*(int*)(addOff(param_3 * 0x50, (u32)iVar4) + 0x40) != 0) result = 1;
        }
    }
    if ((u16)param_2 == 0) {
        int r = *(int*)(param_1 + 0x234);
        if (r != 0) {
            if (param_3 < *(u16*)(r + 4)) {
                int s = *(int*)(r + 0);
                if (*(int*)(s + param_3 * 8) != 0) result = 1;
            }
        }
    }
    return result;
}

/* measured: 4 attempts (nd 33/36/36/36). Correct spellings found: the byte
   chain wants 32-bit arithmetic on a byte base - *(void**)((u8*)arr +
   idx*0x50 + 0x40) folds 0x40 into the lw (element form *0x50+0x10 emits an
   extra sll 6 chain + daddiu, nd 33; (s16) param typing emits no dance at
   all). Residual: (1) retail re-derives the s16 sign-extension (dsll32/
   dsra32) at BOTH use sites; b210 CSEs the two conversions into one pair in
   every spelling tried (s64 shifts, (s64)(s16) casts, s32 param + (s16)
   narrowing, named s32 local nd 22); (2) retail loads arr = *elem at the top
   of the flag body, b210 sinks it below the idx re-derivation + 0x50 chain
   (load-sinking, brief-confirmed); (3) the return-1 path gets its own b to
   the epilogue where retail falls through. Load-CSE +
   sign-extension-reissue floor (same family as 79d10). */
/* MATCHED this wave (nd 0, was 33). Levers: (3) addOff index-first addu
   helper, (7) D_00922BC0_abs lui/addiu address, (4) opt_propagation off forces
   the lhu-before-signext load order (FLYDraw/FLYCmbcardeff combo). Helper is
   defined at top of file, outside the pragma. */
// FUN_00479DD0
#pragma opt_propagation off
s32 func_00479dd0(u8* param_1, u16 param_2, s16 param_3)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;

    iVar1 = 0;
    iVar2 = 0;
    iVar3 = (param_2 & 0xffff) * 0xa4;
    iVar4 = *(int*)(addOff(iVar3, (u32)param_1) + 0x120);
    if (iVar4 != 0)
    {
        iVar5 = *(u16*)(iVar4 + 8);
        if (param_3 < iVar5)
        {
            iVar2 = 1;
        }
    }
    if (iVar2 != 0)
    {
        iVar4 = *(int*)(iVar4 + 0);
        iVar3 = addOff(param_3 * 0x50, (u32)iVar4);
        if (*(int*)(iVar3 + 0x40) == (int)D_00922BC0_abs)
        {
            iVar1 = 1;
        }
    }
    return iVar1;
}
#pragma opt_propagation on
/* measured: probing opt_common_subs off to retain the raw parameter register. */
#pragma opt_common_subs off
// FUN_00479E60
void func_00479e60(void* param_1, s32 param_2, f32 param_3)
{
    s32 arg1;
    s32 off;
    u8* arr;
    s32 index;
    s32 elemOff;
    s32 elem;
    s32 slot;
    f32 frame;

    arg1 = param_2;
    frame = iGpffff8040 * param_3;
    off = (arg1 & 0xFFFF) * 0xA4;
    slot = addOff(off, (u32)param_1);
    index = *(s16*)(slot + 0xF0);
    if (index < 0)
        goto tail;
    arr = *(u8**)(slot + 0x120);
    if (arr == 0)
        goto tail;
    if (*(u16*)(arr + 8) <= index)
        goto tail;
    elemOff = index * 0x50;
    elem = *(s32 *)((u32)((u32)*(s32 *)arr + 0x40) + (u32)(elemOff, elemOff));
    if (elem == 0)
        goto tail;
    if (elem == (s32)D_00922BC0_abs)
        goto tail;
    func_003d5e40(*(void**)(*(u8**)(slot + 0x10C) + 0x20), frame);
    slot = addOff(off, (u32)param_1);
    *(u16*)(slot + 0xEC) |= 4;
tail:
    if ((arg1 & 0xFFFF) == 0) {
        func_00475170((u8*)param_1 + 0x23C, frame);
    }
}
/* measured: closes the scoped opt_common_subs probe for func_00479e60. */
#pragma opt_common_subs on
// FUN_00479F60
f32 func_00479f60(void* param_1, s32 param_2)
{
    f32 value;
    s32 off;
    void* ptr;
    off = (s32)(param_2 & 0xFFFF) * 0xA4;
    ptr = (void*)(off + (s32)param_1);
    if (*(s16*)((u8*)ptr + 0xF0) < 0) {
        value = 0.0f;
    } else if (*(void**)((u8*)ptr + 0x10C) == 0 ||
               *(void**)((u8*)*(void**)((u8*)ptr + 0x10C) + 0x20) == 0) {
        value = 0.0f;
    } else if (*(void**)((u8*)*(void**)((u8*)*(void**)((u8*)ptr + 0x10C) + 0x20)) == 0) {
        value = 0.0f;
    } else {
        value = *(f32*)((u8*)*(void**)((u8*)*(void**)((u8*)*(void**)((u8*)ptr + 0x10C) + 0x20)) + 0xC);
    }
    return value / iGpffff8040;
}

// FUN_0047A000
f32 func_0047a000(void* param_1, s32 param_2, s64 param_3)
{
    f32 value;
    u16 mask = (u16)param_2;
    s32 off;
    void* ptr;
    void* base;
    void* arr;
    void* obj;
    s32 idx;
    s32 off2;
    off = (s32)mask * 0xA4;
    ptr = (void*)(off + (s32)param_1);
    if (*(s32*)((u8*)ptr + 0x10C) == 0) {
        value = 0.0f;
    } else {
        base = *(void**)((u8*)ptr + 0x120);
        arr = *(void**)base;
        idx = (s16)param_3;
        off2 = idx * 0x50;
        obj = (void*)(off2 + (s32)arr);
        value = *(f32*)((u8*)*(void**)((u8*)obj + 0x40) + 0xC);
    }
    return value / iGpffff8040;
}

// FUN_0047A080
f32 func_0047a080(s32 arg0, s32 arg1) {
    s32 off = (arg1 & 0xFFFF) * 0xA4;
    u8 *p = (u8 *)(off + arg0);
    f32 v;

    if (*(s16 *)(p + 0xF0) < 0) {
        v = 0.0f;
    } else {
        v = *(f32 *)(p + 0xF8);
    }
    return v / iGpffff8040;
}

// FUN_0047A0E0
void func_0047a0e0(u8 *arg0, s32 arg1, f32 fparg0) {
    s32 i = arg1 & 0xFFFF;
    s32 off = i * 0xA4;

    *(f32 *)((off + (s32)arg0) + 0xF4) = fparg0;
    if (i == 0) {
        *(f32 *)(arg0 + 0x244) = fparg0;
    }
}

// FUN_0047A120
void func_0047a120(void* param_1)
{
    void* p = *(void**)((u8*)param_1 + 0x120);
    if (p != 0 && *(void**)((u8*)p + 4) != 0) {
        *(u16*)((u8*)param_1 + 0xEC) |= 0x80;
    }
}

// FUN_0047A150
void func_0047a150(void* param_1)
{
    void* p = *(void**)((u8*)param_1 + 0x120);
    if (p != 0 && *(void**)((u8*)p + 4) != 0) {
        *(u16*)((u8*)param_1 + 0xEC) &= 0xFF7F;
    }
}

// FUN_0047A180
RwMatrix* func_0047a180(RwMatrix* matrix, const RwV3d* translation, int combineOp)
{
    return RwMatrixTranslate(matrix, translation, (RwOpCombineType)combineOp);
}

// FUN_0047A1A0
void func_0047a1a0(void *matrix, const void *axis, f32 angle, s32 combineOp)
{
    RwMatrixRotate((struct RwMatrixTag *)matrix, (const RwV3d *)axis,
                  angle, (RwOpCombineType)combineOp);
}

// FUN_0047A1C0
void func_0047a1c0(void *arg0, void *arg1, s32 arg2)
{
    func_003e0e20(arg0, arg1, arg2);
}
// FUN_0047A1E0
void mdlScale(Model* mdl, const RwV3d* scale, int combineOp)
{
    mdl->scale = *scale;
    RwMatrixScale(&mdl->mat, scale, combineOp);
}



// FUN_0047A220
void mdlSetColor(Model* mdl, const RwRGBA* color)
{
    mdl->color = *color;
}




// FUN_0047A260
void func_0047a260(void* param_1)
{
    struct {
        void* ptr;
        u16 v;
    } s;
    void* arg0 = *(void**)((u8*)param_1 + 0xDC);
    s.ptr = (u8*)param_1 + 0xD0;
    s.v = 0;
    func_003bff30(arg0, func_00476e90, &s);
}
// FUN_0047A2A0
void func_0047a2a0(u32* param_1)
{
    param_1[10] = 0x3f800000;
    param_1[5] = 0x3f800000;
    *param_1 = 0x3f800000;
    param_1[4] = 0;
    param_1[2] = 0;
    param_1[1] = 0;
    param_1[9] = 0;
    param_1[8] = 0;
    param_1[6] = 0;
    param_1[0xe] = 0;
    param_1[0xd] = 0;
    param_1[0xc] = 0;
    param_1[3] = param_1[3] | 0x20003;
    return;
}

/* measured (recipe A retest, 4 attempts nd 82/67/63/6): no u16 sign-test in
   this function - recipe A does not apply. Working spellings: goto-shared
   fail (single move $v0,0 block), s32 loop counter with explicit (u16)
   casts (increment andi $s0 + re-mask andi $v0 at the test, exactly retail),
   p = arg0 + (i & 0xFFFF) * 0xC (the explicit mask keeps the andi at the
   chain), nested ifs with t2 = p + 0x290 materialized between the 0x28C and
   0x290 tests (retail's addiu $s2, $v1, 0x290 position), named mp for the
   inner ptr load (load-before-chain order). Residual nd 6 is the recorded
   outer-block schedule: [sll chain; addiu 0x40; lw ptr] vs retail [sll
   chain; lw ptr; addiu 0x40] - the chain result lands in $v0 vs retail $v1
   and the addiu applies to the chain instead of the loaded ptr; `*a + (0x40
   + idx)` avoids the fold but keeps this order, plain `*a + 0x40 + idx`
   folds 0x40 into the load (3 words, nd 84). Chain-vs-load schedule floor
   (same as recorded). */
/* measured: 0047A320 now loads the inner list base into a named local before
   the index chain, reproducing retail's lw-base-then-sll order and all inner
   register colors. Scoped verify: normalized_diff 0, object 372B/window 384B;
   the remaining 12-byte tail is zero padding after the matching jr/nop. */
// FUN_0047A320
s32 func_0047a320(void* arg0) {
    void* list;
    void* item;
    void* wpn;
    void* inner;
    void* innerBase;
    void* slot;
    s16 idx;
    s16 widx;
    u16 i;
    s32 elemOff;
    list = *(void**)((u8*)arg0 + 0x120);
    if (list != (void*)0) {
        idx = *(s16*)((u8*)arg0 + 0xF0);
        if (idx < *(u16*)((u8*)list + 8)) {
            elemOff = (s32)idx * 0x50;
            item = *(void**)((u32)((u32)*(s32*)list + 0x40) + (u32)elemOff);
            if (item != (void*)0 && item != (void*)D_00922BC0_abs) {
                func_00397c40(*(void**)((u8*)arg0 + 0x10C));
                i = 0;
                while ((s64)i < 5) {
                    elemOff = (u16)i;
                    slot = (u8*)arg0 + (elemOff * 0xC);
                    if ((*(u8*)((u8*)slot + 0x28C) & 1) != 0 && *(void**)((u8*)slot + 0x290) != (void*)0 && func_0047ae90(arg0, i) != 0) {
                        wpn = *(void**)((u8*)slot + 0x290);
                        inner = *(void**)((u8*)wpn + 0x120);
                        if (inner != (void*)0) {
                            widx = *(s16*)((u8*)wpn + 0xF0);
                            if (widx < *(u16*)((u8*)inner + 8)) {
                                innerBase = *(void**)inner;
                                item = *(void**)((u32)innerBase + (u32)((s32)widx * 0x50) + 0x40);
                                if (item != (void*)0 && item != (void*)D_00922BC0_abs) {
                                    func_00397c40(*(void**)((u8*)wpn + 0x10C));
                                }
                            }
                        }
                    }
                    i++;
                }
                return 1;
            }
        }
    }
    return 0;
  }

// FUN_0047A4A0
void *func_0047a4a0(void *arg0, void *arg1) {
    /* arg1 is reassigned rather than using a fresh local: retail reuses the
       $a1 argument register for the node pointer once the mask is loaded. */
    s32 mask = *(s32 *)arg1;

    arg1 = *(void **)((u8 *)arg0 + 0x18);
    *(s32 *)((u8 *)arg1 + 8) &= ~mask;
    return arg0;
}

// FUN_0047A4D0
void func_0047a4d0(void* param_1, int param_2)
{
    func_003bff30(*(void**)((u8*)param_1 + 0xDC), func_0047a4a0, &param_2);
}


#pragma push
/* Retain the separate body, test and found-index masks from retail. */
#pragma opt_common_subs off
static inline s32 mdl_matrix_from_table(MdlMatrixTable* list, void* arg0,
                                       s32 arg1, u8* dst)
{
    u8* container;
    s32 count, key, bodyIndex, testIndex, foundIndex, value, result;
    u16 index;
    MdlMatrixEntry* entry;
    u8* temp;

    container = *(u8**)((u8*)arg0 + 0xDC);
    count = list->count;
    index = 0;
    key = arg1 & 0xFFFF;
    goto loop_test;
loop_body:
    bodyIndex = index & 0xFFFF;
    entry = list->entries + bodyIndex;
    if (key == entry->id) {
        goto found;
    }
    index += 1;
loop_test:
    testIndex = index & 0xFFFF;
    if (testIndex < count) {
        goto loop_body;
    }
found:
    if (testIndex == count) {
        result = 0;
    } else {
        foundIndex = index & 0xFFFF;
        entry = list->entries + foundIndex;
        value = entry->frameId;
        temp = *(u8**)(container + 4);
        temp = mdl_find_frame(temp, value);
        if (temp == 0) {
            result = 0;
        } else {
            RwMatrixMultiply(dst, &entry->matrix, func_003e9700(temp));
            result = 1;
        }
    }
    return result;
}

/* MATCH: 440B/448B, with two zero-tail words. The table helper retains
   its shared return block; RwMatrix assignment emits the retail pair-copy. */
// FUN_0047A510
s32 func_0047a510(void* arg0, s32 arg1, void* arg2)
{
    MdlMatrixTable* list;
    s32 result;
    u8* dst;
    u8* src;

    dst = (u8*)arg2;
    list = *(MdlMatrixTable**)((u8*)arg0 + 0x2C8);
    if (list != 0) {
        result = mdl_matrix_from_table(list, arg0, arg1, dst);
    } else {
        src = (u8*)func_00457f40(*(void**)((u8*)arg0 + 0xDC),
                               (const char*)D_007131D8, arg1);
        if (src == NULL) {
            result = 0;
        } else {
            src = func_003e9700(src);
            *(RwMatrix*)dst = *(RwMatrix*)src;
            result = 1;
        }
    }
    return result;
}
#pragma pop
// FUN_0047A6D0
s32 func_0047a6d0(void* arg0, s32 arg1, void* arg2)
{
    s32 result;
    u32 lo;
    u32 hi;
    u8* src;
    u32* dst;
    s32 count;
    u32 buf[16];

    if (*(void**)((u8*)arg0 + 0x2C8) != 0) {
        result = func_00475b90(buf, *(void**)((u8*)arg0 + 0x2C8), arg1 & 0xFFFF, *(void**)((u8*)arg0 + 0xDC));
    } else {
        src = (u8*)func_00457f40(*(void**)((u8*)arg0 + 0xDC), (const char*)D_007131D8, (s32)arg1);
        if (src == 0) {
            result = 0;
        } else {
            src = (u8*)func_003e9700(src);
            dst = buf;
            count = 8;
            do {
                lo = *(u32*)(src + 0);
                hi = *(u32*)(src + 4);
                src += 8;
                count -= 1;
                *(u32*)(dst + 0) = lo;
                *(u32*)(dst + 1) = hi;
                dst += 2;
            } while (count > 0);
            result = 1;
        }
    }
    if (result == 0) {
        return 0;
    }
    *(RwV3d*)((u8*)arg2) = *(RwV3d*)(buf + 12);
    return 1;
}
// FUN_0047A7C0
u32 func_0047a7c0(void* param_1)
{
    u16* p = *(u16**)((u8*)param_1 + 0x2C8);
    if (p != 0) {
        return p[0];
    }
    return func_004581a0(*(void**)((u8*)param_1 + 0xDC), (const char*)D_007131D8);
}

// FUN_0047A810
void func_0047a810(void* param_1)
{
    *(u32*)((u8*)param_1 + 0xD8) |= 1;
}

// FUN_0047A830
void func_0047a830(void* param_1)
{
    *(u32*)((u8*)param_1 + 0xD8) &= ~1;
}

// FUN_0047A850
void func_0047a850(void* param_1)
{
    *(u32*)((u8*)param_1 + 0xD8) |= 0x20;
}

// FUN_0047A870
void func_0047a870(void* param_1)
{
    *(u32*)((u8*)param_1 + 0xD8) &= ~0x20;
}

// FUN_0047A890
void func_0047a890(void* param_1, float param_2)
{
    *(float*)((u8*)param_1 + 0x144) = param_2;
}

// FUN_0047A8A0
void func_0047a8a0(void* param_1, float param_2, float param_3)
{
    *(float*)((u8*)param_1 + 0x148) = param_2;
    *(float*)((u8*)param_1 + 0x14C) = param_3;
}

// FUN_0047A8B0
void func_0047a8b0(void* param_1, RwV3d* param_2)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x40;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFF5F;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFEFF;
    *(RwV3d*)((u8*)param_1 + 0x17C) = *param_2;
}

// FUN_0047A900
void func_0047a900(void* param_1, RwV3d* param_2)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x20;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFF3F;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFEFF;
    *(RwV3d*)((u8*)param_1 + 0x17C) = *param_2;
}

// FUN_0047A950
void func_0047a950(void* param_1, float param_2, float param_3)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x8000;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFEFF;
    *(float*)((u8*)param_1 + 0x188) = param_2;
    *(float*)((u8*)param_1 + 0x18C) = param_3;
}

// FUN_0047A980
void* func_0047a980(void* param_1)
{
    return (char*)param_1 + 0x150;
}

// FUN_0047A990
void func_0047a990(void* param_1)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x100;
}

// FUN_0047A9B0
void func_0047a9b0(void* param_1)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x200;
}

// FUN_0047A9D0
int func_0047a9d0(void* param_1)
{
    return (*(u16*)((u8*)param_1 + 0x140) & 0x81E0) != 0;
}

// FUN_0047A9F0
void func_0047a9f0(void* param_1, u16 param_2)
{
    *(u16*)((u8*)param_1 + 0x140) = param_2;
}

// FUN_0047AA00
u16 func_0047aa00(void* param_1)
{
    return *(u16*)((u8*)param_1 + 0x140);
}

// FUN_0047AA10
void func_0047aa10(void* param_1, RwV3d* param_2)
{
    *(RwV3d*)((u8*)param_1 + 0x170) = *param_2;
}

/* measured: retail masks the counter head (andi $v1,$a3,0xffff; slti $v1,$v1,5)
   AND at the body top (andi $a2,$a3,0xffff). A plain s32 counter with (u16)
   casts at each use CSEs the two masks into one carried register and emits a
   redundant self-mask. The matching form is a while loop that derives the body
   index into a separate u32 local (idx = (u16)i) so mwcc keeps the body-top
   andi distinct from the loop-head andi (nd 0, byte-exact). Committed at nd 0. */
// FUN_0047AA30
void func_0047aa30(void* param_1, void* param_2) {
    s32 i;
    *(void**)((u8*)param_1 + 0x2FC) = param_2;
    i = 0;
    while ((u16)i < 5) {
        u32 idx = (u16)i;
        void* slot = (u8*)param_1 + idx * 0xC;
        if ((*(u8*)((u8*)slot + 0x28C) & 1) != 0 && *(void**)((u8*)slot + 0x290) != 0) {
            *(void**)((u8*)*(void**)((u8*)slot + 0x290) + 0x2FC) = param_2;
        }
        i = (u16)(i + 1);
    }
}

// FUN_0047AAA0
void func_0047aaa0(void* param_1, u16 param_2, u32 param_3, u16 param_4, void* param_5, u32 param_6)
{
    void* obj;
    s32 off;
    void* slot;
    obj = func_004779b0(param_3, param_4);
    if ((param_6 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    func_0047aff0(obj, param_5);
    func_004782b0(obj);
    off = (s32)(param_2 & 0xFFFF) * 0xC;
    slot = (void*)(off + (s32)param_1);
    *(void**)((u8*)slot + 0x290) = obj;
    *(u32*)((u8*)obj + 0xD8) |= 0x4;
    *(u32*)((u8*)*(void**)((u8*)slot + 0x290) + 0xD8) |= 0x8000;
    *(u8*)((u8*)slot + 0x28C) |= 0x1;
}

// FUN_0047AB90
void func_0047ab90(void* param_1, u16 param_2, u32 param_3, u16 param_4, s32 param_5, s32 param_6, u32 param_7)
{
    void* obj;
    s32 off;
    void* slot;

    obj = func_004779b0(param_3, param_4);
    if ((param_7 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    {
        int tmp[2];
        tmp[0] = param_5;
        tmp[1] = param_6;
        func_0047afd0(obj, tmp);
    }
    func_004782b0(obj);
    off = (s32)(param_2 & 0xFFFF) * 0xC;
    slot = (void*)(off + (s32)param_1);
    *(void**)((u8*)slot + 0x290) = obj;
    *(u32*)((u8*)obj + 0xD8) |= 0x4;
    *(u32*)((u8*)*(void**)((u8*)slot + 0x290) + 0xD8) |= 0x8000;
    *(u8*)((u8*)slot + 0x28C) |= 0x1;
}

// FUN_0047AC90
void func_0047ac90(void* param_1, u16 param_2, u32 param_3, u16 param_4, u32 param_5)
{
    void* obj;
    void* result;
    u8 buf[0x100];
    u32 off;
    void* slot;

    if (func_00477c40(param_3, param_4, 0) == (void*)0) {
        func_0047d110(param_3, param_4, (char*)buf);
        obj = func_00477e80(param_3, param_4, buf, param_5);
        if (func_0047d0e0(param_3, param_4) != 0) {
            func_0047b050(obj, 1);
        }
        result = obj;
        goto done;
    } else {
        obj = func_004779b0(param_3, param_4);
        if ((param_5 & 1) != 0) {
            *(u32*)((u8*)obj + 0xD8) |= 0x4000;
        }
        *(u32*)((u8*)obj + 0xD8) |= 0x2000;
        func_004782b0(obj);
        result = obj;
    }
done:
    off = (param_2 & 0xFFFF) * 0xC;
    slot = (void*)addOff(off, (u32)(u8*)param_1);
    *(void**)((u8*)slot + 0x290) = result;
    *(u32*)((u8*)result + 0xD8) |= 4;
    *(u32*)((u8*)*(void**)((u8*)slot + 0x290) + 0xD8) |= 0x8000;
    *(u8*)((u8*)slot + 0x28C) |= 1;
}

/* Ported from P3FES mdlManager.c func_003196f0 (verified MATCH there). Keep the
   iVar1/iVar2/pWpnMdl local structure and the recompute of iVar2+param_1 before
   the post-call byte clear exactly; P4 offsets are wpnMdl ptr 0x290, flags byte
   0x28C, stride 0xC (donor used 0x3b8/0x3b4). */
// FUN_0047AE10
void func_0047ae10(u8* param_1, u16 param_2)
{
    int iVar1;
    int iVar2;
    int* pWpnMdl;

    iVar1 = (int)(u8*)param_1;
    iVar2 = (param_2 & 0xffff) * 0xc;
    iVar1 = iVar2;
    iVar1 += (int)(u8*)param_1;
    pWpnMdl = (int*)(iVar1 + 0x290);
    if (*pWpnMdl != 0)
    {
        func_004787e0((u8*)*pWpnMdl);
        *pWpnMdl = 0;
        iVar2 = iVar2 + (int)(u8*)param_1;
        *(u8*)(iVar2 + 0x28C) = *(u8*)(iVar2 + 0x28C) & 0xfe;
    }
}

/* Ported from P3FES mdlManager.c func_003197c0 (verified MATCH there).
   P4 offsets: attachedWpns base 0x28C, wpnMdl ptr 0x290, stride 0xC (donor used
   0x3b4/0x3b8). The RwMatrix copy at wpnMdl+0x90 is 8 words. */
/* measured: removing the pragma regresses this MATCH (nd 0) to a re-mask/hoist
   mismatch; the struct-access spelling needs it to reproduce retail's andi re-mask. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_0047AEE0
void func_0047aee0(Model* param_1, RwMatrix* param_2)
{
    u16 uVar6;
    int iVar3;

    uVar6 = 0;
    for (; uVar6 < 5; uVar6++)
    {
        iVar3 = (int)param_1->attachedWpns[uVar6].wpnMdl;
        if (iVar3 != 0)
        {
            *(RwMatrix*)((u8*)(u32)iVar3 + 0x90) = *param_2;
        }
    }
}
#pragma pop

// FUN_0047AF60
void func_0047af60(void* param_1)
{
    void* obj;
    func_0044ea90(D_00713138, 0x1769);
    obj = ((void* (*)(int, int))DAT_008873e8[0])(0x48, 0x40000);
    *(void**)((u8*)param_1 + 0x30C) = obj;
    memset(obj, 0, 0x48);
}

// FUN_0047AFD0
void func_0047afd0(void* param_1, void* param_2)
{
    void* obj = *(void**)((u8*)param_1 + 0x30C);
    *(u32*)((u8*)obj + 0x2C) = *(u32*)param_2;
    *(u32*)((u8*)obj + 0x30) = *(u32*)((u8*)param_2 + 4);
}

// FUN_0047AFF0
void func_0047aff0(void* param_1, void* param_2)
{
    void* obj = *(void**)((u8*)param_1 + 0x30C);
    func_00440b68(&D_007241d0, D_00713138, 0x1786);
    *(u32*)((u8*)obj + 0x38) = (u32)func_00454a60((u8*)param_2, 0);
    *(u32*)((u8*)obj + 0x0) = 0;
}

// FUN_0047B050
void func_0047b050(void* param_1, int param_2)
{
    *(int*)((u8*)*(void**)((u8*)param_1 + 0x30C) + 0x40) = param_2;
}

// FUN_0047B060
void func_0047b060(void* param_1)
{
    u32* m = (u32*)param_1;
    void* obj = (void*)m[0x30C / 4];
    if (*(void**)((u8*)obj + 0xC) != 0) {
        DAT_008873ec[0](*(void**)((u8*)obj + 0xC));
    }
    DAT_008873ec[0]((void*)m[0x30C / 4]);
    m[0x30C / 4] = 0;
}

/* Recover the full chunk/effect headers and memory-stream descriptor, the
   selected clone wrappers, and the schema argument for both deferred UV reads.
   The typed candidate retains retail's 0xd0 frame but does not match yet.
   Native measurements and the complete relocation/data proof are recorded in
   docs/probe_archive/Model_loader_contracts_20261005_worker15.md.
   2026-10-08: the chunk dispatch is a switch whose case bodies follow in source order; b210 compares the cases in reverse (385 edits).
   The base-animation store is the out-of-line else arm (378 edits). */
/* 2026-10-09: 378 -> 277 edits from a block-declaration order climb. 
   2026-10-09: 277 -> 271: capacity init loop stores the address-taken capacity, and case 0x1b/0xf0f00001 write through a shared layerResource local (retail computes the slot index before loading the entries base).
   2026-10-09: 271 -> 230: the attachment branch tests `model + 0xdc == 0 &&
   clumpStream == 0` first (retail lays the 0x2CC wrapper path first), the
   effect-slot loop counter is u16, and the per-slot resource writes go through
   `layerResource = LOAD_LAYER()->resource;` so the index is computed before
   `entries` is loaded.
   2026-10-09: 230 -> 226: the 0xF0F00001 store writes
   `LOAD_LAYER()->resource->entries[state->slot].animation` directly (the
   D_00922BC0 address is materialised first), and one source-entry read uses
   addOff.
 * 2026-10-09: 226 -> 196: the clone-source case reads `src`/`dst` once for the
 * animation entry copy, and the material and UV tables through locals.
 * 161: the material/UV copy reads `state->slot` once into `dst`.
 * 155: u16 clone-slot fill counter.
 * 122: u16 counter for the blend-control animation loop.
 * 118: conversion lever (slot:(1, 3)).
 * sdiff 29/103 -> 28/95: clone-slot fill loop compares as int (retail slt).
 * sdiff 28/95 -> 27/94: matrix loop compare as int (retail slt).
 * sdiff 27/94 -> 22/88: animation field read relative to the element (retail folds +0x40 into the load).
 * sdiff 22/88 -> 22/84: startFrame stores through an inline entry accessor (retail loads entries after the index).
 * sdiff 22/84 -> 20/81: material bound test reads the count first.
 * sdiff 20/81 -> 16/75: start-frame stores through an inline setter (value, table, slot) as retail evaluates them.
 * sdiff 16/75 -> 14/70: the clip store uses the same inline setter shape.
 * sdiff 14/70 -> 10/66: material/uv value reads through an index accessor (index before the entries load, as retail).
 * sdiff 10/66 -> 8/64: matrix copy through a local entries pointer.
 * matrix loop test compares (u16)slot, the body keeps its own (slot & 0xffff) as retail.
 * sdiff 8/64 -> 6/60: secondary attachment test adds the table first (retail order).
 * 2026-10-10: whole-owner guarded replay improves 72 -> 38 aligned instruction edits
 * (1382/1382 instructions). The existing attachment allocator's declaration
 * order and local UV/material table lifetimes account for most of the gain.
 * Still NONMATCHING; retained native probes: build/first-party-final-20261010/models.
 * fnalign 38 -> 34: s16 clone slots (retail -1), cloneSlots/capacities layer reads as base-first byte offsets.
 * fnalign 34 -> 28: layerResource entry reads at the slot as base-first byte offsets.
 */
// FUN_0047B0C0 NONMATCHING
#ifdef NON_MATCHING
static inline void **mdlLoaderValueAt(void *table, u32 index)
{
    return (void **)(*(u8 **)table + index * 8);
}

static inline MdlDispatchAnimEntry *mdlLoaderAnimEntry(MdlDispatchAnimTable *table, u32 slot)
{
    return &table->entries[slot];
}

static inline void mdlLoaderSetFrame(s32 value, MdlDispatchAnimTable *table, u32 slot, s32 which)
{
    mdlLoaderAnimEntry(table, slot)->startFrame[which] = value;
}

static inline void mdlLoaderSetAnimation(void *value, MdlDispatchAnimTable *table, u32 slot)
{
    mdlLoaderAnimEntry(table, slot)->animation = value;
}

s32 func_0047b0c0(u8 *model)
{
    typedef struct MdlLoaderMaterial {
        u32 kind;
        u16 slot;
        void *stream;
        struct MdlLoaderMaterial *next;
    } MdlLoaderMaterial;
    typedef struct MdlLoaderState {
        void *stream;
        u8 *textureRequest;
        u8 *uvRequest;
        u8 **uvRequests;
        u8 *clumpRequest;
        void *clumpStream;
        MdlLoaderMaterial *materials;
        u16 layer, slot;
        u16 capacities[2];
        s16 *cloneSlots[2];
        u8 *memory;
        u32 memoryLength;
        u32 *textureList;
        u8 *fileRequest;
        u32 unknown3c;
        s32 mode;
        s32 baseAnimation;
    } MdlLoaderState;
    typedef struct MdlLoaderEntry {
        void *value;
        u32 flags;
    } MdlLoaderEntry;
    typedef struct MdlLoaderMaterialTable {
        MdlLoaderEntry *entries;
        u16 count, references;
    } MdlLoaderMaterialTable;
    typedef struct MdlLoaderUvTable {
        MdlLoaderEntry *entries;
        void *base;
        void *objects;
        u16 count, references;
    } MdlLoaderUvTable;
    struct MdlEffectChunk {
        u16 first, last;
        u32 length, skip, flags, unknown10;
    } effect;
    struct RwChunkHeaderInfo {
        u32 type, length, version, buildNum;
        s32 isComplex;
    } chunk;
    struct RwMemory {
        u8 *start;
        u32 length;
    } memory;
    s32 metadata;
    u16 capacity;
    u16 sourceIndex;
    u16 matrixCount;
    MdlLoaderState *state;
    MdlDispatchAnimTable *layerResource;
    s32 index;
    extern void *func_003df3c0(void *stream, struct RwChunkHeaderInfo *header);
    extern u32 func_003e2910(void *stream, void *buffer, u32 length);
    extern void *func_003e2ce0(void *stream, u32 length);
    extern void *func_003e2f60(s32 type, s32 access, const void *memory);
    extern void *func_003c0f20(void *stream);
    extern void *func_003d53c0(void *stream);
    extern void *func_003d6350(void *schema, void *stream);
    extern struct RwTexDictionary *func_003dc370(void *stream);
    extern struct RwTexDictionary *func_003e6a90(void *stream);
    extern s32 func_003ef1b0(void *dictionary);
    extern u32 func_003d60e0(u32 schema, u32 dictionary);
    extern u8 *func_004667d0(s32 kind, const char *name, const char *path,
        s32 flags, s32 source, s32 buffer, s32 byteCount, const char *cacheName,
        s32 resultKind, s32 memoryKind);
    extern u32 func_0047d1a0(void);
    extern u32 *func_0047d320(u32 **head, s32 data, u32 length, u16 index, u32 flags);
    extern u32 *func_0047d460(u32 *head, u32 *node, u16 index);
    extern u32 *func_0047db50(s32 data, s32 length);
    extern s32 *func_0047f9f0(void);
    extern s32 func_004800d0(void *stream, u8 **head, u32 kind, void *clump);
    extern u8 D_0070B610[];

#define LOAD_LAYER() ((MdlCloneLayerView *)(model + 0xec + (u32)state->layer * 0xa4))
#define LOAD_MATERIALS() (*(MdlLoaderMaterialTable **)(model + 0x234))
#define LOAD_UVS() (*(MdlLoaderUvTable **)(model + 0x254))
#define LOAD_MEMORY() do { \
    u32 position = *(u32 *)((u8 *)state->stream + 0xc); \
    memory.start = state->memory + position; \
    memory.length = state->memoryLength - position; \
} while (0)

    state = *(MdlLoaderState **)(model + 0x30c);
    capacity = 32;
    {
        u16 c;

        for (c = 0; c < 2; c++) {
            u16 *destination = &state->capacities[c];
            *destination = capacity;
        }
    }
    while (func_003df3c0(state->stream, &chunk) != 0) {
        if (chunk.type == 0) {
            break;
        }
        switch (chunk.type) {

        case 0x16:
        if ((*(u32 *)(model + 0xd8) & 0x4000) != 0) {
            struct RwTexDictionary *dictionary = func_003e6a90(state->stream);
            func_003ef260(dictionary, func_00463100, &state->textureList);
            func_003ef1b0(dictionary);
        } else {
            LOAD_MEMORY();
            state->textureRequest = func_004667d0(8, 0, 0, 0,
                (s32)func_003e2f60(3, 1, &memory), 0, 0, 0, 0, 0);
            func_003e2ce0(state->stream, chunk.length);
        }
        continue;

        case 0x23:
        {
            struct RwTexDictionary *dictionary = func_003dc370(state->stream);
            func_003ef260(dictionary, func_00463100, &state->textureList);
            func_003ef1b0(dictionary);
        }
        continue;

        case 0x1b:
        {
            void *animation;
            if (LOAD_LAYER()->resource == 0) {
                MdlDispatchAnimTable *table = (MdlDispatchAnimTable *)func_00470e90(capacity);
                LOAD_LAYER()->resource = table;
            }
            animation = func_003d53c0(state->stream);
            if (state->baseAnimation == 0 || LOAD_LAYER()->resource->unknown != 0) {
                layerResource = LOAD_LAYER()->resource;
                (*(MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry))).animation = animation;
            } else {
                LOAD_LAYER()->resource->unknown = (u32)animation;
            }
        }
        continue;

        case 0x2b:
        if ((*(u32 *)(model + 0xd8) & 0x4000) != 0) {
            void *dictionary;
            MdlLoaderUvTable *table = LOAD_UVS();
            if (table == 0) {
                u16 count = capacity;
                s32 size = (u32)count * sizeof(MdlLoaderEntry) + sizeof(MdlLoaderUvTable);
                func_0044ea90(D_00713138, 0x908);
                table = ((void *(*)(int, int))DAT_008873e8[0])(size, 0x40000);
                memset(table, 0, size);
                table->entries = (MdlLoaderEntry *)(table + 1);
                table->count = count;
                table->references = 1;
                LOAD_UVS() = table;
            }
            dictionary = func_003d6350(D_0070B610, state->stream);
            if (*(void **)(model + 0xdc) == 0) {
                LOAD_UVS()->base = dictionary;
                func_003d60e0((u32)D_0070B610, (u32)dictionary);
            } else {
                LOAD_UVS()->entries[state->slot].value = dictionary;
            }
        } else {
            if (state->clumpStream == 0 && state->clumpRequest == 0) {
                LOAD_MEMORY();
                state->uvRequest = func_004667d0(7, 0, 0, 0,
                    (s32)func_003e2f60(3, 1, &memory), 0, 0, 0, (s32)D_0070B610, 0);
            } else {
                if (state->uvRequests == 0) {
                    func_0044ea90(D_00713138, 0x1834);
                    state->uvRequests = ((void *(*)(int, int))DAT_008873e8[0])((u32)capacity * 4, 0x40000);
                    memset(state->uvRequests, 0, (u32)capacity * 4);
                }
                LOAD_MEMORY();
                {
                    u8 *request = func_004667d0(7, 0, 0, 0,
                        (s32)func_003e2f60(3, 1, &memory), 0, 0, 0, (s32)D_0070B610, 0);
                    state->uvRequests[state->slot] = request;
                }
            }
            func_003e2ce0(state->stream, chunk.length);
        }
        continue;

        case 0x10:
        if ((*(u32 *)(model + 0xd8) & 0x4000) != 0) {
            if (*(void **)(model + 0xdc) == 0) {
                void *clump = func_003c0f20(state->stream);
                *(void **)(model + 0xdc) = clump;
            }
        } else {
            if (*(void **)(model + 0xdc) == 0 && state->clumpStream == 0 && state->clumpRequest == 0) {
                LOAD_MEMORY();
                state->clumpStream = func_003e2f60(3, 1, &memory);
            }
            func_003e2ce0(state->stream, chunk.length);
        }
        continue;

        case 0x1e:
            continue;
        case 0xf0f00001:
        if (LOAD_LAYER()->resource == 0) {
            MdlDispatchAnimTable *table = (MdlDispatchAnimTable *)func_00470e90(capacity);
            LOAD_LAYER()->resource = table;
        }
        mdlLoaderSetAnimation(D_00922BC0_abs, LOAD_LAYER()->resource, state->slot);
        func_003e2ce0(state->stream, chunk.length);
        continue;

        case 0xf0f00005:
        if (LOAD_LAYER()->resource == 0) {
            MdlDispatchAnimTable *table = (MdlDispatchAnimTable *)func_00470e90(capacity);
            LOAD_LAYER()->resource = table;
        }
        layerResource = LOAD_LAYER()->resource;
        func_003e2910(state->stream, &layerResource->entries[state->slot].matrix, chunk.length);
        continue;

        case 0xf0f00004:
        state->slot++;
        func_003e2ce0(state->stream, chunk.length);
        continue;

        case 0xf0f00002:
        state->layer++;
        state->slot = 0;
        func_003e2ce0(state->stream, chunk.length);
        continue;

        case 0xf0f00003:
        if ((*(u32 *)(model + 0xd8) & 0x4000) != 0) {
            MdlDispatchAnimTable *animations;
            MdlCloneAttachmentTable *attachments;
            func_003e2910(state->stream, &sourceIndex, chunk.length);
            {
                u16 src = sourceIndex;
                u16 dst = state->slot;

                animations = LOAD_LAYER()->resource;
                {
                    MdlDispatchAnimEntry *entries = animations->entries;

                    entries[dst].matrix = entries[src].matrix;
                }
                if (*(u32 *)((u8 *)&animations->entries[src] + 0x40) != 0) {
                    *(u32 *)((u8 *)&animations->entries[dst] + 0x40) = *(u32 *)((u8 *)&animations->entries[src] + 0x40);
                }
                animations->entries[dst].unknown44 |= 1;
            }
            {
                MdlLoaderMaterialTable *materials = LOAD_MATERIALS();

                if (materials != 0 && materials->count > sourceIndex) {
                    void *value = *mdlLoaderValueAt(materials, sourceIndex);
                    if (value != 0) {
                        u16 dst = state->slot;

                        materials->entries[dst].value = value;
                        *(u8 *)&materials->entries[dst].flags |= 1;
                    }
                }
            }
            {
                MdlLoaderUvTable *uvs = LOAD_UVS();

                if (uvs != 0 && sourceIndex < uvs->count) {
                    void *value = *mdlLoaderValueAt(uvs, sourceIndex);
                    if (value != 0) {
                        u16 dst = state->slot;

                        uvs->entries[dst].value = value;
                        *(u8 *)&uvs->entries[dst].flags |= 1;
                    }
                }
            }
            attachments = LOAD_LAYER()->attachments;
            if (attachments != 0) {
                u16 source = sourceIndex;
                u16 destination = state->slot;
                if (attachments->primary[source] != 0) {
                    void *copy = func_0047d200(attachments->primary[source]);
                    attachments->primary[destination] = copy;
                }
                if (*(void **)((u32)attachments->secondary + source * 4) != 0) {
                    void *copy = func_0047dc30(attachments->secondary[source]);
                    attachments->secondary[destination] = copy;
                }
            }
        } else {
            func_003e2910(state->stream, &sourceIndex, chunk.length);
            if ((*(s16 **)((u8 *)state + state->layer * 4 + 0x24)) == 0) {
                u16 slot;
                func_0044ea90(D_00713138, 0x1896);
                (*(s16 **)((u8 *)state + state->layer * 4 + 0x24)) = ((void *(*)(int, int))DAT_008873e8[0])((u32)capacity * 2, 0x40000);
                for (slot = 0; slot < capacity; slot++) {
                    (*(s16 **)((u8 *)state + state->layer * 4 + 0x24))[slot] = -1;
                }
            }
            (*(s16 **)((u8 *)state + state->layer * 4 + 0x24))[state->slot] = sourceIndex;
        }
        continue;

        case 0xf0f00080:
        case 0xf0f00081:
        case 0xf0f00083:
        case 0xf0f00082:
        if ((*(u32 *)(model + 0xd8) & 0x4000) != 0) {
            MdlLoaderMaterialTable *table = LOAD_MATERIALS();
            if (table == 0) {
                u16 count = capacity;
                s32 size = (u32)count * sizeof(MdlLoaderEntry) + sizeof(MdlLoaderMaterialTable);
                func_0044ea90(D_00713138, 0x850);
                table = ((void *(*)(int, int))DAT_008873e8[0])(size, 0x40000);
                memset(table, 0, size);
                table->entries = (MdlLoaderEntry *)(table + 1);
                table->count = count;
                table->references = 1;
                LOAD_MATERIALS() = table;
            }
            if (LOAD_MATERIALS()->entries[state->slot].value == 0) {
                s32 *material = func_0047f9f0();
                LOAD_MATERIALS()->entries[state->slot].value = material;
            }
            func_004800d0(state->stream, LOAD_MATERIALS()->entries[state->slot].value,
                chunk.type, *(void **)(model + 0xdc));
        } else {
            MdlLoaderMaterial *pending;
            func_0044ea90(D_00713138, 0x18b7);
            pending = ((void *(*)(int, int))DAT_008873e8[0])(sizeof(*pending), 0x40000);
            LOAD_MEMORY();
            pending->kind = chunk.type;
            pending->slot = state->slot;
            pending->stream = func_003e2f60(3, 1, &memory);
            func_003e2ce0(state->stream, chunk.length);
            pending->next = state->materials;
            state->materials = pending;
        }
        continue;

        case 0xf0f00070:
        {
            void *properties;
            func_0044ea90(D_00713138, 0x18c5);
            properties = ((void *(*)(int, int))DAT_008873e8[0])(0x2b8, 0x40000);
            func_003e2910(state->stream, properties, chunk.length);
            func_00477810(model, properties);
            DAT_008873ec[0](properties);
        }
        continue;

        case 0xf0f00006:
        {
            void *stream = state->stream;
            MdlMatrixEntry *entries;
            MdlMatrixTable *table;
            s32 slot;
            s32 size;
            func_003e2910(stream, &matrixCount, 2);
            size = (u32)matrixCount * sizeof(MdlMatrixEntry) + sizeof(MdlMatrixTable);
            func_0044ea90(D_00713138, 0xc93);
            entries = ((void *(*)(int, int))DAT_008873e8[0])(size, 0x40000);
            table = (MdlMatrixTable *)(entries + matrixCount);
            table->count = matrixCount;
            table->unknown = 1;
            table->entries = entries;
            for (slot = 0; (u16)slot < matrixCount; slot = (slot + 1) & 0xffff) {
                u32 offset = (slot & 0xffff) * sizeof(MdlMatrixEntry);
                func_003e2910(stream, (u8 *)table->entries + offset + 0x40, 4);
                func_003e2910(stream, (u8 *)table->entries + offset + 0x44, 4);
                func_003e2910(stream, (u8 *)table->entries + offset, sizeof(RwMatrix));
            }
            *(MdlMatrixTable **)(model + 0x2c8) = table;
        }
        continue;

        case 0xf0f000f0:
        func_003e2910(state->stream, &capacity, chunk.length);
        (*(u16 *)((u8 *)state + state->layer * 2 + 0x20)) = capacity;
        continue;

        case 0xf0f000e0:
        {
            u32 **head;
            u8 *payload;
            u32 *node;
            u16 slot;
            func_003e2910(state->stream, &effect, sizeof(effect));
            func_003e2ce0(state->stream, effect.skip);
            payload = state->memory + *(u32 *)((u8 *)state->stream + 0xc);
            if (*(void **)(model + 0xdc) == 0 && state->clumpStream == 0) {
                if (*(void **)(model + 0x2cc) == 0) {
                    *(u32 *)(model + 0x2cc) = func_0047d1a0();
                }
                head = *(u32 ***)(model + 0x2cc);
            } else {
                if (LOAD_LAYER()->attachments == 0) {
                    MdlCloneAttachmentTable *table = mdl_clone_attachment_storage(capacity);
                    LOAD_LAYER()->attachments = table;
                }
                if (LOAD_LAYER()->attachments->primary[state->slot] == 0) {
                    void *wrapper = (void *)func_0047d1a0();
                    LOAD_LAYER()->attachments->primary[state->slot] = wrapper;
                }
                head = LOAD_LAYER()->attachments->primary[state->slot];
            }
            node = func_0047d320(head, (s32)payload, effect.length, effect.first, effect.flags);
            for (slot = effect.first + 1; slot < effect.last + 1; slot++) {
                func_0047d460((u32 *)head, node, slot);
            }
            func_003e2ce0(state->stream, effect.length);
        }
        continue;

        case 0xf0f000e1:
        {
            u8 *payload = state->memory + *(u32 *)((u8 *)state->stream + 0xc);
            if (LOAD_LAYER()->attachments == 0) {
                MdlCloneAttachmentTable *table = mdl_clone_attachment_storage(capacity);
                LOAD_LAYER()->attachments = table;
            }
            {
                u32 *wrapper = func_0047db50((s32)payload, chunk.length);
                LOAD_LAYER()->attachments->secondary[state->slot] = wrapper;
            }
            func_003e2ce0(state->stream, chunk.length);
        }
        continue;

        case 0xf0f000d0:
        {
            u8 *group;
            u16 slot;
            func_0044ea90(D_00713138, 0xfa);
            group = ((void *(*)(int, int))DAT_008873e8[0])(0x4c, 0x40000);
            memset(group, 0, 0x4c);
            *(f32 *)(group + 0x30) = 1.0f;
            *(f32 *)(group + 0x38) = 1.0f;
            layerResource = LOAD_LAYER()->resource;
            (*(MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry))).blendControl = group;
            layerResource = LOAD_LAYER()->resource;
            func_003e2910(state->stream, (*(MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry))).blendControl + 0x3c,
                chunk.length);
            for (slot = 0; slot < 4; slot++) {
                func_003df3c0(state->stream, &chunk);
                {
                    void *animation = func_003d53c0(state->stream);
                    layerResource = LOAD_LAYER()->resource;
                    ((void **)(*(MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry))).blendControl)[slot] = animation;
                }
            }
        }
        continue;

        case 0xf0f00007:
        case 0xf0f00008:
        func_003e2910(state->stream, &metadata, chunk.length);
        layerResource = LOAD_LAYER()->resource;
        if ((*(MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry))).startFrame == 0) {
            s32 *values;
            func_0044ea90(D_00713138, 0x125);
            values = ((void *(*)(int, int))DAT_008873e8[0])(8, 0x40000);
            memset(values, 0, 8);
            layerResource = LOAD_LAYER()->resource;
            (*(MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry))).startFrame = values;
        }
        if (chunk.type == 0xf0f00007) {
            mdlLoaderSetFrame(metadata, LOAD_LAYER()->resource, state->slot, 0);
        } else {
            mdlLoaderSetFrame(metadata, LOAD_LAYER()->resource, state->slot, 1);
        }
        continue;

        case 0xf0f00009:
        state->baseAnimation = 1;
        func_003e2ce0(state->stream, chunk.length);
        continue;

        default:
        func_003e2ce0(state->stream, chunk.length);
        }
    }
#undef LOAD_MEMORY
#undef LOAD_UVS
#undef LOAD_MATERIALS
#undef LOAD_LAYER
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047b0c0);
#endif


extern u8 *func_004669d0(u8 *request, s32 *ready, s32 *handle);
extern s32 func_003ef1b0(void* dictionary);
extern s32 func_003e2e40(void* stream, void* data);
extern void* func_003d60e0(void* schema, void* dictionary);
extern u8 *func_004667d0(s32 kind, const char *name, const char *path,
    s32 flags, s32 source, s32 buffer, s32 byteCount, const char *cacheName,
    s32 resultKind, s32 memoryKind);
extern s32 *func_0047f9f0(void);
extern s32 func_004800d0(void *stream, u8 **head, u32 kind, void *clump);
extern u8 D_0070B610[];
/* Native b210 O2 MATCH: 1944B/window 1952B; the remaining eight bytes are zero.
   Poll results retain their real pointer type and their status/stream outputs.
   Copy the RwMatrix value, reload entry storage after writes and callbacks,
   and dereference the two effect-list pointer arrays at offsets 0x14/0x20.
   Full-width iteration and independently narrowed asset indices are distinct.
   Prior probe notes and native receipts are retained in model-manager-after-rebase. */
#pragma push
#pragma opt_propagation off
// FUN_0047C660
s32 func_0047c660(u8 *arg0)
{
    u8 *secondaryResult;
    u8 *primaryResult;
    u8 *owner;
    u8 *slot;
    u32 k;
    s32 ok;
    s32 okA;
    s32 okB;
    u32 size;
    u32 i;
    u8 *node;
    u32 j;
    u8 *next;
    u8 *entryResult;
    u8 *clumpResult;
    struct { s32 ready; s32 handle; } loaded;
    u16 cnt;
    s32 map;
    s16 checkedMap;
    u32 srcIdx;
    u32 dstIdx;
    s32 srcOff;
    s32 dstOff;
    u8 *srcEnt;
    u8 *dstEnt;
    u32 anim;
    u8 *tbl;
    u8 *outer;
    u8 *mapBase;
    u8 *cntBase;
    u8 *layer;
    u8 *table;
    u8 *entries;
    u8 **mapSlot;
    s32 srcPointerOff;
    s32 dstPointerOff;
    s32 pendingSource;
    u8 *requestTable;
    u8 *pendingRequest;
    u32 requestByteOffset;
    u32 resourceEntryOffset;
    s32 checkedByteOffset;

    owner = *(u8 **)(arg0 + 0x30C);
    ok = 1;
    okA = 1;
    okB = 1;
    if (*(u32 *)(owner + 4) != 0) {
        primaryResult = func_004669d0(*(u8 **)(owner + 4), &loaded.ready, &loaded.handle);
        if (loaded.ready == 1) {
            func_003ef260((const struct RwTexDictionary *)primaryResult, func_00463100, owner + 0x34);
            func_003ef1b0((void *)primaryResult);
            func_003e2e40((void *)loaded.handle, 0);
            *(u32 *)(owner + 4) = 0;
        } else {
            okA = 0;
            ok = 0;
        }
    }
    if (*(u32 *)(owner + 8) != 0) {
        secondaryResult = func_004669d0(*(u8 **)(owner + 8), &loaded.ready, &loaded.handle);
        if (loaded.ready == 1) {
            if (*(void **)(arg0 + 0x254) == 0) {
                cnt = *(u16 *)(owner + 0x20);
                size = (u32)cnt * 8 + 0x10;
                func_0044ea90(D_00713138, 0x908);
                slot = ((void *(*)(int, int))DAT_008873e8[0])((int)size, 0x40000);
                memset(slot, 0, (int)size);
                *(u8 **)(slot + 0) = slot + 0x10;
                *(u16 *)(slot + 0xC) = cnt;
                *(u16 *)(slot + 0xE) = 1;
                *(u8 **)(arg0 + 0x254) = slot;
            }
            *(u32 *)(*(u8 **)(arg0 + 0x254) + 4) = (u32)secondaryResult;
            func_003d60e0(D_0070B610, secondaryResult);
            func_003e2e40((void *)loaded.handle, 0);
            *(u32 *)(owner + 8) = 0;
        } else {
            ok = 0;
            okB = 0;
        }
    }
    if (*(u32 *)(owner + 0xC) != 0) {
        i = 0;
        while (i < *(u16 *)(owner + 0x20)) {
            requestTable = *(u8 **)(owner + 0xC);
            requestByteOffset = i * 4;
            pendingRequest = *(u8 **)(requestTable + requestByteOffset);
            if (pendingRequest != 0) {
                entryResult = func_004669d0(pendingRequest, &loaded.ready, &loaded.handle);
                if (loaded.ready == 1) {
                    if (*(void **)(arg0 + 0x254) == 0) {
                        cnt = *(u16 *)(owner + 0x20);
                        size = (u32)cnt * 8 + 0x10;
                        func_0044ea90(D_00713138, 0x908);
                        slot = ((void *(*)(int, int))DAT_008873e8[0])((int)size, 0x40000);
                        memset(slot, 0, (int)size);
                        *(u8 **)(slot + 0) = slot + 0x10;
                        *(u16 *)(slot + 0xC) = cnt;
                        *(u16 *)(slot + 0xE) = 1;
                        *(u8 **)(arg0 + 0x254) = slot;
                    }
                    table = *(u8 **)(arg0 + 0x254);
                    resourceEntryOffset = (u16)i * 8;
                    *(u32 *)(*(u8 **)table + resourceEntryOffset) = (u32)entryResult;
                    func_003e2e40((void *)loaded.handle, 0);
                    *(u32 *)(*(u8 **)(owner + 0xC) + requestByteOffset) = 0;
                } else {
                    ok = 0;
                }
            }
            i++;
        }
    }
    pendingSource = *(s32 *)(owner + 0x14);
    if (pendingSource != 0 || *(u32 *)(owner + 0x10) != 0) {
        if (okA == 1 && okB == 1) {
            if (pendingSource != 0) {
                *(u32 *)(owner + 0x10) = (u32)func_004667d0(2, 0, 0, 0, pendingSource, 0, 0, 0, 0, 0);
                *(u32 *)(owner + 0x14) = 0;
                ok = 0;
            } else {
                clumpResult = func_004669d0(*(u8 **)(owner + 0x10), &loaded.ready, &loaded.handle);
                if (loaded.ready == 1) {
                    *(u32 *)(arg0 + 0xDC) = (u32)clumpResult;
                    func_003e2e40((void *)loaded.handle, 0);
                    *(u32 *)(owner + 0x10) = 0;
                } else {
                    ok = 0;
                }
            }
        } else {
            ok = 0;
        }
    }
    node = *(u8 **)(owner + 0x18);
    if (node != 0) {
        if (*(void **)(arg0 + 0xDC) != 0) {
            while (node != 0) {
                if (*(void **)(arg0 + 0x234) == 0) {
                    cnt = *(u16 *)(owner + 0x20);
                    size = (u32)cnt * 8 + 8;
                    func_0044ea90(D_00713138, 0x850);
                    slot = ((void *(*)(int, int))DAT_008873e8[0])((int)size, 0x40000);
                    memset(slot, 0, (int)size);
                    *(u8 **)(slot + 0) = slot + 8;
                    *(u16 *)(slot + 4) = cnt;
                    *(u16 *)(slot + 6) = 1;
                    *(u8 **)(arg0 + 0x234) = slot;
                }
                if (*(u32 *)(**(u8 ***)(arg0 + 0x234) + *(u16 *)(node + 4) * 8) == 0) {
                    *(u32 *)(**(u8 ***)(arg0 + 0x234) + *(u16 *)(node + 4) * 8) = (u32)func_0047f9f0();
                }
                func_004800d0(*(void **)(node + 8), (u8 **)*(void **)(**(u8 ***)(arg0 + 0x234) + *(u16 *)(node + 4) * 8), *(u32 *)(node + 0), *(void **)(arg0 + 0xDC));
                func_003e2e40(*(void **)(node + 8), 0);
                next = *(u8 **)(node + 0xC);
                DAT_008873ec[0](node);
                node = next;
            }
            *(u8 **)(owner + 0x18) = 0;
        } else {
            ok = 0;
        }
    }
    if (ok == 1) {
        k = 0;
        while (k < 2) {
            outer = owner + k * 4;
            mapSlot = (u8 **)(outer + 0x24);
            if (*(u8 **)(outer + 0x24) != 0) {
                j = 0;
                layer = arg0 + k * 0xA4;
                cntBase = owner + k * 2;
                while (j < *(u16 *)(cntBase + 0x20)) {
                    mapBase = *(u8 **)(outer + 0x24);
                    map = *(s16 *)(mapBase + j * 2);
                    if (map != -1) {
                        table = *(u8 **)(layer + 0x120);
                        entries = *(u8 **)table;
                        srcIdx = (u16)map;
                        srcOff = srcIdx * 0x50;
                        dstIdx = (u16)j;
                        dstOff = dstIdx * 0x50;
                        srcEnt = entries + srcOff;
                        dstEnt = entries + dstOff;
                        *(RwMatrix*)dstEnt = *(RwMatrix*)srcEnt;
                        entries = *(u8 **)table;
                        anim = *(u32 *)(entries + srcOff + 0x40);
                        if (anim != 0) {
                            *(u32 *)(entries + dstOff + 0x40) = anim;
                        }
                        entries = *(u8 **)table;
                        *(u32 *)(entries + dstOff + 0x44) |= 1;
                        if (k == 0) {
                            table = *(u8 **)(arg0 + 0x234);
                            if (table != 0) {
                                checkedMap = (s16)map;
                                if (checkedMap < (s64)(u32)*(u16 *)(table + 4)) {
                                    checkedByteOffset = checkedMap * 8;
                                    entries = *(u8 **)table;
                                    if (*(u32 *)(entries + checkedByteOffset) != 0) {
                                        dstPointerOff = (u16)j * 8;
                                        *(u32 *)(entries + dstPointerOff) = *(u32 *)(entries + srcIdx * 8);
                                        entries = *(u8 **)table;
                                        *(u8 *)(entries + dstPointerOff + 4) |= 1;
                                    }
                                }
                            }
                            table = *(u8 **)(arg0 + 0x254);
                            if (table != 0) {
                                checkedMap = (s16)map;
                                if (checkedMap < (s64)(u32)*(u16 *)(table + 0xC)) {
                                    checkedByteOffset = checkedMap * 8;
                                    entries = *(u8 **)table;
                                    if (*(u32 *)(entries + checkedByteOffset) != 0) {
                                        dstPointerOff = (u16)j * 8;
                                        *(u32 *)(entries + dstPointerOff) = *(u32 *)(entries + srcIdx * 8);
                                        entries = *(u8 **)table;
                                        *(u8 *)(entries + dstPointerOff + 4) |= 1;
                                    }
                                }
                            }
                            tbl = *(u8 **)(layer + 0x124);
                            if (tbl != 0) {
                                entries = *(u8 **)(tbl + 0x14);
                                srcPointerOff = srcIdx * 4;
                                if (*(u32 **)(entries + srcPointerOff) != 0) {
                                    *(u32 **)(*(u8 **)(tbl + 0x14) + dstIdx * 4) =
                                        func_0047d200(*(u32 ***)(entries + srcPointerOff));
                                }
                                entries = *(u8 **)(tbl + 0x20);
                                if (*(u32 **)(entries + srcPointerOff) != 0) {
                                    *(u32 **)(*(u8 **)(tbl + 0x20) + dstIdx * 4) =
                                        func_0047dc30(*(u32 ***)(entries + srcPointerOff));
                                }
                            }
                        }
                    }
                    j++;
                }
                DAT_008873ec[0](*mapSlot);
            }
            k++;
        }
    }
    return ok;
}

#pragma pop
