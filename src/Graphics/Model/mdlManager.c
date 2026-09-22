#include "model_motion_internal.h"
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
/* Pragma state is per-function in this file: opt_common_subs off + opt_propagation off are load-bearing in func_00479100 (29-word floor) but worse in func_00475cd0 (csoff 1057, propoff 1024 vs sched-on 915); func_00475cd0 uses schedule on only. Do not copy pragmas across functions. */
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
extern s32 func_00457a90(void* a, u8* b);
extern f32 func_004579a0(const RpMaterial* a, const char* b);
extern s32 func_0047e6f0(void** owner);

extern u32 func_00397460(s32 object);
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

extern u32 func_00399d80();
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
extern void (*DAT_008873ec[])();

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
extern int func_00442c30();
extern int func_003d8130();
extern void RtAnimInterpolatorSetAnimLoopCallBack();
extern void* func_00474ba0(void* param_1, void* param_2);
extern char gp0xffff9d10;
extern u8 LAB_00474a50;
extern u8 LAB_00474a50_abs[];
extern u8 LAB_00474a90;
extern u8 LAB_00474a90_abs[];

extern s32 func_00397470(u8* frame);
extern void func_003e05f0(void* a, void* b, void* c);

extern void func_004585c0(u8* arg0);
extern void* func_00476e90(void* object, void* data);
extern u32 func_004578b0();
extern f32 iGpffff8044;
extern u8 D_00713160[];
extern s32 func_004581a0(void* object, const char* data);
extern u8 D_007131D8[];
extern f32 DAT_00761130;
extern u8 D_00713138[];
extern u8 D_007241d0;
extern void* D_00922BE0[];
extern void func_00440b68(void* a, void* b, int c);
extern u8* func_00454a60(u8* a, s32 b);
extern void func_0044ea90(void* a, int b);
extern void func_0043f9c8(void* a, int b, int c);
extern void* DAT_008873e8[];
extern s64 DAT_00723cd8;
extern void func_004787e0(u8* a0);
extern void func_0048a000(void);
extern s32 func_004782b0(u8* a);
extern void* func_003bfae0(void);
extern int func_003e8200(void* a, void* b);
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
extern struct RwMatrixTag* func_003e0870(struct RwMatrixTag* matrix, const RwV3d* axis, f32 angle, RwOpCombineType combineOp);

// 12 bytes. attachedWpns slot layout from P4 retail (flags bit 0 at 0x00, wpnMdl at 0x04, unk_08 at 0x08).
typedef struct MdlWpnSlot
{
    u8 flags;      // 0x00
    u8 pad1[3];    // 0x01..0x03
    void* wpnMdl; // 0x04
    u8 unk_08;     // 0x08
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

extern void* RwMatrixMultiply(void* dst, void* left, void* right);
extern void func_003e9cb0(void* frame, void* matrix, u32 flags);
extern void func_0047aee0(Model* mdl, RwMatrix* matrix);
extern void func_0047ae10(u8* mdl, u16 wpnIdx);
extern void func_0047d840();
extern void func_0047dda0();
extern void func_0047ea70(u8* a);
extern void func_0047adf0(u8* a, u16 b, s32 c);
extern s32 iGpffffbb28;
extern f32 iGpffff80cc;
extern void* func_004779b0();
extern s32 func_00479ca0(void* a, s32 b);
extern u32* func_003971d0(u8*, s32, s32, s32);
extern void* func_00462ae0(void* object);
extern void func_0047da30();
extern void* func_003c0520();
extern void* func_0047d200();
extern void* func_0047dc30();
extern void func_0047ea40();
extern s32 func_0047ae90();
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
    func_0043f9c8(obj, 0, size);
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

    value = func_00397460((s32)param_1);
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



/* measured 00471370 (owner): the romwright body is NOT banked.  It measures object 2561
   against retail 1776 - **+44.2%**, where the gate allows 53 instructions - and a body 44%
   too long is not a floor, it is a different function.  Its word and edit scores (2496 and
   3645) are meaningless against a body of that length (handoff 7y), and leaving it installed
   would corrupt every later measurement on this file.  Archived at
   docs/probe_archive/romwright_func_00471370_R1.c with its diagnosis: float accumulator mul/add where
   retail uses mula/madd (7r), the lhu+bltz sign-test floor shared with func_00473b20 and
   func_00479100, saved-register rotation, and an if-else chain where retail has a jump
   table.  Rebuild from retail's dispatch shape, not from the decompiler's. */
/* measured 00471370 R2 (B6_floatbits, shared-context guarded): object 1971/retail 1776
   (+195, +11.0%). Retail 7104B/1776, frame -0x550, 77 jal +1 jalr (callback 0x004717FC),
   no jump table (if-chain, NOT table), band 1723-1829 (53 allowed). Batches over R1 2561:
   B1 strip trailing +0.0 (30 occ, Horner + lerp) 2561->2225 (-336);
   B2 merge split lerp *(param+8/10/c)=C*D then =A*B+*(param)+0.0 into single A*B+C*D
   2225->2215 (-10); B3 float proto (0044b920/50 u32->float, DAT_00922bb0/b4 s32->float,
   drop (float) casts) 2215->2132 (-83); B5 u64 fix (003d5790 u64->ptr, 003e9240 long->int,
   lq-emulation (float)u64 casts -> direct float copies) 2132->2118 (-14);
   B6 float bits (*(u32*)&afStack_b0[3]|=, (float)puVar3[c/e/12]->((float*)puVar3)[])
   2118->1971 (-147). Total -590, remaining +195. Zero widen (u8/u16->u32) ties 2132;
   quat-share temps ties 1971; pragma off 2079 (+108); schedule on 1668 (-303, -6.1% short)
   banned (fills delays retail leaves empty, hides surplus like 00475cd0 handoff 7y).
   Concrete sites: 0x42180-0x421FC mul f4,f1,f11 + mul f3,f4,f4 sharing f3 across six
   adda/madd (Horner, fixed by B1); mula 0x42264/0x4251C (lerp A*B+C*D, fixed by B1+B2);
   madda pairs 0x42574-0x42580 + 0x426DC-0x426E8 (2.0/sum-of-4-squares, already single).
   ~44 shared-product sites. lhu+bltz 0x472BF0 untouched (7az floor, struct u32 fix). */
/* gate: func_00471370 is INSIDE the +-3% band at 1776 against retail 1776 (exact count,
   band 1723-1829).  From the 1971 body: unsuffixed double constants were emitting ~155
   fptodp/dpsub/dptofp/lito emulation calls (object had 233 jal vs retail's 78); `f`
   suffixes on all 86 float constants -420 to 1551 with 79 calls.  The MAC-fusion theory
   was inverted for this body: at equal precision our fused mula+madd undershoots retail,
   whose 79 adda/mula/madd/madda lines are mostly SPLIT shapes (mul+store, reload+adda+
   madd).  Length came back via retail-observed splits: push/pop opt_common_subs off +
   opt_propagation off around the function +130 (1676, wrapper placement; in-body pragmas
   are inert); column-major lerp splits (mul+store, reload+combine, 4th row fused) +11/+15;
   negate-triple store-then-negate +2; afStack_350[4] array (sign-flip quads were scalar-
   addressed so MWCC dropped 3 of 4 dead stores; array forces the 16B callee window) +12;
   afStack_30[3] array (same scalar-escape loss on fStack_2c/28 scalings/reciprocals) +60.
   Rotation calls use the native matrix/axis/float-angle/combine-op contract;
   the angle occupies $f12 without the old unprototyped float-to-double promotion.
   lhu+bltz 0x472BF0 remains untouched (7az floor).
   Measured at gate: GUARDED_SCORE 1636, fnalign edits 2073, frame -0x400 vs retail -0x550.
   Word/edit scores are comparable from here (equal length).  Production guarded, fallback
   INCLUDE_ASM retained. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00471370 NONMATCHING
#ifdef NON_MATCHING
s32 func_00471370(u8 *param_1, u8 *param_2, u8 *param_3, void *param_4)

{
    extern void *func_003d5790(int, int);
    extern int func_003e9240(void *);
    extern unsigned int func_003e9700(int);
    extern float func_0044b920(float);
    extern float func_0044b950(float, float);
    extern int func_003d5e40(unsigned char *, float);
    extern int func_003d5e90(unsigned char *, unsigned char *, unsigned char *, float);
    extern float func_004bd4a0(unsigned char *, unsigned char *);
    extern s32 func_003954b0();
    extern s32 func_00397c40();
    extern s32 func_003d5840();
    extern s32 func_003dc610();
    extern s32 func_003dc740();
    extern s32 func_003dcb40();
    extern s32 func_003dcc70();
    extern s32 func_003e05f0();
    extern s32 func_003e0960();
    extern s32 func_003e0a90();
    extern s32 func_003e40b0();
    extern s32 func_003e42a0();
    extern s32 func_003e4320();
    extern s32 func_003e9680();
    extern s32 func_003ed960();
/* irregular: 19 native warning(s); review required */
    extern s32 DAT_0088739c;
    extern float DAT_00922bb0;
    extern float DAT_00922bb4;
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
  unsigned short temp_v0;
  code *pcVar2;
  unsigned int *puVar3;
  int *piVar4;
  unsigned char temp_v1;
  unsigned char temp_v2;
  unsigned int temp_v3;
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
  float temp_v14;
  float temp_v15;
  float temp_v16;
  unsigned int temp_v17;
  float temp_v18;
  float temp_v19;
  float temp_v20;
  float temp_v21;
  int iStack_450;
  unsigned int uStack_430;
  int iStack_420;
  unsigned char temp_v22 [64];
  int uStack_3c0;
  unsigned int uStack_3bc;
  unsigned int uStack_3b8;
  unsigned int uStack_3b4;
  float fStack_3b0;
  float fStack_3ac;
  float fStack_3a8;
  float fStack_3a4;
  float fStack_3a0;
  float fStack_39c;
  float fStack_398;
  float fStack_394;
  float fStack_390;
  float fStack_38c;
  float fStack_388;
  float fStack_384;
  float fStack_380;
  float fStack_37c;
  float fStack_378;
  float fStack_374;
  float fStack_370;
  float fStack_36c;
  float fStack_368;
  float fStack_364;
  float fStack_360;
  int iStack_35c;
  float afStack_350[4];
  float fStack_340;
  float fStack_33c;
  float fStack_338;
  float fStack_334;
  float fStack_330;
  float fStack_32c;
  float fStack_328;
  unsigned int uStack_324;
  float fStack_320;
  float fStack_31c;
  float fStack_318;
  float fStack_310;
  float fStack_30c;
  float fStack_308;
  float fStack_300;
  float fStack_2fc;
  float fStack_2f8;
  unsigned char temp_v23 [64];
  unsigned char temp_v24 [64];
  unsigned char temp_v25 [16];
  unsigned char temp_v26 [48];
  float fStack_230;
  float fStack_22c;
  float fStack_228;
  unsigned int uStack_224;
  float fStack_220;
  float fStack_21c;
  float fStack_218;
  float fStack_210;
  float fStack_20c;
  float fStack_208;
  unsigned int uStack_200;
  unsigned int uStack_1fc;
  unsigned int uStack_1f8;
  float afStack_1f0 [16];
  float afStack_1b0 [17];
  unsigned int temp_v27 [31];
  float afStack_f0 [3];
  unsigned int uStack_e4;
  unsigned int uStack_e0;
  unsigned int uStack_dc;
  unsigned int uStack_d8;
  unsigned int uStack_d0;
  unsigned int uStack_cc;
  unsigned int uStack_c8;
  unsigned int uStack_c0;
  unsigned int uStack_bc;
  unsigned int uStack_b8;
  float afStack_b0 [8];
  unsigned int uStack_90;
  unsigned int uStack_8c;
  unsigned int uStack_88;
  unsigned int uStack_80;
  unsigned int uStack_7c;
  unsigned int uStack_78;
  int uStack_70;
  unsigned int uStack_6c;
  unsigned int uStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float afStack_30[3];
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  int uStack_10;
  unsigned int uStack_c;
  unsigned int uStack_8;
  
  temp_v1 = 0;
  temp_v3 = 0;
  temp_v2 = 0;
  puVar12 = (unsigned int *)param_1;
  temp_v10 = *puVar12;
  if (((temp_v10 & 1) == 0) || (puVar12[7] == 0xffffffff)) {
    if ((temp_v10 & 0x4000) == 0) {
      temp_v1 = 1;
      temp_v3 = puVar12[5];
      pfVar21 = afStack_b0;
    }
    else {
      uStack_c8 = 0x3f800000;
      uStack_dc = 0x3f800000;
      afStack_f0[0] = 1.0f;
      uStack_e0 = 0;
      afStack_f0[2] = 0.0f;
      afStack_f0[1] = 0.0f;
      uStack_cc = 0;
      uStack_d0 = 0;
      uStack_d8 = 0;
      uStack_b8 = 0;
      uStack_bc = 0;
      uStack_c0 = 0;
      uStack_e4 = uStack_e4 | 0x20003;
      pfVar21 = afStack_f0;
      if ((temp_v10 & 0x2000) != 0) {
        temp_v1 = 1;
        temp_v3 = puVar12[5];
      }
    }
  }
  else {
    pfVar21 = (float *)(*(int *)(puVar12[6] + 8) + puVar12[7] * 0x40);
    if (((temp_v10 & 0x2000) != 0) && ((temp_v10 & 0x4000) != 0)) {
      temp_v1 = 1;
      temp_v3 = *(unsigned int *)(puVar12[6] + 0x14);
    }
  }
  if (temp_v1) {
    if ((temp_v3 == 0) || (temp_v9 = *(int *)(temp_v3 + 4), temp_v9 == 0)) {
      uStack_88 = 0x3f800000;
      afStack_b0[5] = 1.0f;
      afStack_b0[0] = 1.0f;
      afStack_b0[4] = 0.0f;
      afStack_b0[2] = 0.0f;
      afStack_b0[1] = 0.0f;
      uStack_8c = 0;
      uStack_90 = 0;
      afStack_b0[6] = 0.0f;
      uStack_78 = 0;
      uStack_7c = 0;
      uStack_80 = 0;
      *(u32 *)&afStack_b0[3] |= 0x20003;
    }
    else {
      temp_v4 = func_003e9240((void *)temp_v9);
      if (temp_v4 == 0) {
        pfVar8 = (float *)func_003e9700(temp_v9);
        pfVar16 = afStack_b0;
        temp_v9 = 8;
        do {
          temp_v21 = *pfVar8;
          temp_v20 = pfVar8[1];
          pfVar8 = pfVar8 + 2;
          temp_v9 = temp_v9 - 1;
          *pfVar16 = temp_v21;
          pfVar16[1] = temp_v20;
          pfVar16 = pfVar16 + 2;
        } while (0 < temp_v9);
      }
      else {
        pfVar16 = (float *)(temp_v9 + 0x10);
        pfVar8 = afStack_b0;
        temp_v11 = 8;
        do {
          temp_v21 = *pfVar16;
          temp_v20 = pfVar16[1];
          pfVar16 = pfVar16 + 2;
          temp_v11 = temp_v11 - 1;
          *pfVar8 = temp_v21;
          pfVar8[1] = temp_v20;
          pfVar8 = pfVar8 + 2;
        } while (0 < temp_v11);
        for (temp_v9 = *(int *)(temp_v9 + 4); temp_v9 != 0; temp_v9 = *(int *)(temp_v9 + 4)) {
          pfVar16 = afStack_b0;
          pfVar8 = afStack_1f0;
          temp_v11 = 4;
          do {
            pfVar8[0] = pfVar16[0];
            pfVar8[1] = pfVar16[1];
            pfVar8[2] = pfVar16[2];
            pfVar8[3] = pfVar16[3];
            pfVar16 = pfVar16 + 4;
            temp_v11 = temp_v11 - 1;
            pfVar8 = pfVar8 + 4;
          } while (0 < temp_v11);
          func_003e05f0(afStack_b0,afStack_1f0,temp_v9 + 0x10);
        }
      }
    }
  }
  temp_v3 = temp_v10 & 0x2000;
  if ((temp_v3 != 0) && ((*(unsigned char *)(*(int *)(puVar12[5] + 0xa0) + 3) & 3) == 0)) {
    *(int *)(*(int *)(puVar12[5] + 0xa0) + 8) = DAT_0088739c;
    *(int **)(*(int *)(puVar12[5] + 0xa0) + 0xc) = &DAT_0088739c;
    *(int *)(DAT_0088739c + 4) = *(int *)(puVar12[5] + 0xa0) + 8;
    temp_v9 = *(int *)(puVar12[5] + 0xa0);
    DAT_0088739c = temp_v9 + 8;
    *(unsigned char *)(temp_v9 + 3) = *(unsigned char *)(temp_v9 + 3) | 2;
  }
  temp_v6 = puVar12[8];
  pcVar2 = *(code **)(temp_v6 + 0x3c);
  temp_v9 = *(int *)(temp_v6 + 0x24);
  puVar22 = temp_v27;
  uStack_430 = puVar12[4];
  pfVar8 = (float *)puVar12[2];
  temp_v11 = temp_v6 + 0x4c;
  puVar3 = *(unsigned int **)((short)param_2[2] * 0x50 + **(int **)(param_2 + 0x1a) + 0x48);
  if ((puVar3 == (unsigned int *)0x0) || (*(float *)(param_2 + 4) != 0.0f)) {
    for (iStack_420 = 0; iStack_420 < (int)puVar12[1]; iStack_420 = iStack_420 + 1) {
      if (*pcVar2 == func_003954b0) {
        temp_v14 = *(float *)(temp_v11 + 8);
        temp_v15 = *(float *)(temp_v11 + 0xc);
        temp_v21 = *(float *)(temp_v11 + 0x10);
        temp_v20 = *(float *)(temp_v11 + 0x14);
        fStack_230 = 1.0f - (temp_v15 * temp_v15 + temp_v21 * temp_v21) * 2.0f;
        fStack_22c = (temp_v14 * temp_v15 + temp_v20 * temp_v21) * 2.0f;
        fStack_228 = (temp_v21 * temp_v14 - temp_v20 * temp_v15) * 2.0f;
        fStack_220 = (temp_v14 * temp_v15 - temp_v20 * temp_v21) * 2.0f;
        fStack_21c = 1.0f - (temp_v14 * temp_v14 + temp_v21 * temp_v21) * 2.0f;
        fStack_218 = (temp_v15 * temp_v21 + temp_v20 * temp_v14) * 2.0f;
        fStack_210 = (temp_v21 * temp_v14 + temp_v20 * temp_v15) * 2.0f;
        fStack_20c = (temp_v15 * temp_v21 - temp_v20 * temp_v14) * 2.0f;
        fStack_208 = 1.0f - (temp_v14 * temp_v14 + temp_v15 * temp_v15) * 2.0f;
        uStack_224 = 3;
        uStack_200 = *(unsigned int *)(temp_v11 + 0x18);
        uStack_1fc = *(unsigned int *)(temp_v11 + 0x1c);
        uStack_1f8 = *(unsigned int *)(temp_v11 + 0x20);
      }
      else {
        (*pcVar2)(&fStack_230,temp_v11);
      }
      if (*(int *)(puVar12[4] + iStack_420 * 0x10) == 0x1389) {
        if ((param_4 == 0) && ((*param_3 & 0x400) == 0)) {
          *param_3 = *param_3 | 0x600;
        }
        temp_v1 = 0;
        afStack_30[0] = 1.0f / *(float *)(param_3 + 0x18);
        afStack_30[1] = 1.0f / *(float *)(param_3 + 0x1a);
        afStack_30[2] = 1.0f / *(float *)(param_3 + 0x1c);
        if ((*param_2 & 0x10) != 0) {
          afStack_30[0] = afStack_30[0] * (1.0f / DAT_00922bb0);
          temp_v21 = (1.0f / DAT_00922bb0) * DAT_00922bb4;
          afStack_30[1] = afStack_30[1] * temp_v21;
          afStack_30[2] = afStack_30[2] * temp_v21;
        }
        pfVar17 = afStack_1b0;
        temp_v7 = 8;
        pfVar16 = pfVar21;
        do {
          temp_v21 = *pfVar16;
          temp_v20 = pfVar16[1];
          pfVar16 = pfVar16 + 2;
          temp_v7 = temp_v7 - 1;
          *pfVar17 = temp_v21;
          pfVar17[1] = temp_v20;
          pfVar17 = pfVar17 + 2;
        } while (0 < temp_v7);
        func_003e0a90(afStack_1b0,afStack_30,1);
        func_003e05f0(&fStack_330,&fStack_230,afStack_1b0);
        fStack_20 = fStack_300;
        fStack_1c = fStack_2fc;
        fStack_18 = fStack_2f8;
        if (param_4 == 0) {
          func_003e0a90(&fStack_330,afStack_30,1);
          uStack_10 = 0;
          uStack_c = 0x3f800000;
          uStack_8 = 0;
          func_003e0870((struct RwMatrixTag*)temp_v24, (const RwV3d*)&uStack_10, 180.0f, rwCOMBINEREPLACE);
          uStack_10 = 0;
          uStack_c = 0;
          uStack_8 = 0x3f800000;
          func_003e0870((struct RwMatrixTag*)temp_v24, (const RwV3d*)&uStack_10, -90.0f, rwCOMBINEPOSTCONCAT);
          func_003e05f0(temp_v25,temp_v24,afStack_b0);
          temp_v0 = *param_3;
          if ((temp_v0 & 0x100) == 0) {
            if ((temp_v0 & 0x60) == 0) {
              if ((temp_v0 & 0x80) == 0) {
                func_003dc610(&fStack_340,&fStack_330);
              }
              else {
                iStack_450 = 0;
                uStack_10 = 0x3f800000;
                uStack_c = 0;
                uStack_8 = 0;
                func_003e4320(&uStack_10,&uStack_10,afStack_b0);
                func_003e0870((struct RwMatrixTag*)temp_v24, (const RwV3d*)&uStack_10, *(float *)(param_3 + 0x1e), rwCOMBINEREPLACE);
                uStack_10 = 0;
                uStack_c = 0x3f800000;
                uStack_8 = 0;
                func_003e4320(&uStack_10,&uStack_10,afStack_b0);
                func_003e0870((struct RwMatrixTag*)temp_v24, (const RwV3d*)&uStack_10, *(float *)(param_3 + 0x20), rwCOMBINEPOSTCONCAT);
                func_003e05f0(pfVar8,temp_v25,temp_v24);
                func_003dc610(&fStack_340,pfVar8);
              }
            }
            else {
              iStack_450 = 1;
              if ((temp_v0 & 0x40) == 0) {
                afStack_30[0] = *(float *)(param_3 + 0x1e);
                afStack_30[1] = *(float *)(param_3 + 0x20);
                afStack_30[2] = *(float *)(param_3 + 0x22);
                afStack_30[0] = -afStack_30[0];
                afStack_30[1] = -afStack_30[1];
                afStack_30[2] = -afStack_30[2];
              }
              else {
                afStack_30[0] = fStack_20 - *(float *)(param_3 + 0x1e);
                afStack_30[1] = fStack_1c - *(float *)(param_3 + 0x20);
                afStack_30[2] = fStack_18 - *(float *)(param_3 + 0x22);
              }
              func_003e40b0(afStack_30,afStack_30);
              func_003e0960(temp_v23,afStack_b0);
              func_003e4320(afStack_30,afStack_30,temp_v23);
              func_003e40b0(afStack_30,afStack_30);
              fStack_50 = 0.0f;
              fStack_4c = 0.0f;
              fStack_48 = -100.0f;
              func_003e42a0(&fStack_50,&fStack_50,afStack_1b0);
              fStack_40 = fStack_20 - fStack_50;
              fStack_3c = fStack_1c - fStack_4c;
              fStack_38 = fStack_18 - fStack_48;
              func_003e4320(&fStack_40,&fStack_40,temp_v23);
              func_003e40b0(&fStack_40,&fStack_40);
              temp_v21 = func_0044b920(fStack_3c);
              temp_v15 = fGpffff8048 * temp_v21 - 90.0f;
              temp_v21 = func_0044b950(fStack_40,fStack_38);
              temp_v14 = fGpffff8048 * temp_v21 + 180.0f;
              temp_v21 = func_0044b920(afStack_30[1]);
              temp_v20 = fGpffff8048 * temp_v21 - 90.0f;
              temp_v21 = func_0044b950(afStack_30[0],afStack_30[2]);
              temp_v21 = fGpffff8048 * temp_v21;
              for (temp_v20 = temp_v20 - temp_v15; temp_v20 < 0.0f; temp_v20 = temp_v20 + 360.0f) {
              }
              for (; 360.0f < temp_v20; temp_v20 = temp_v20 - 360.0f) {
              }
              temp_v16 = *(float *)(param_3 + 4);
              if ((temp_v16 < temp_v20) && (temp_v20 < 360.0f - temp_v16)) {
                if (180.0f <= temp_v20) {
                  temp_v16 = 360.0f - temp_v16;
                }
                temp_v1 = 1;
                temp_v20 = temp_v16;
              }
              func_003e0870((struct RwMatrixTag*)temp_v24, (const RwV3d*)temp_v26, -(temp_v20 + temp_v15), rwCOMBINEREPLACE);
              for (temp_v21 = (temp_v21 + 180.0f) - temp_v14; temp_v21 < 0.0f; temp_v21 = temp_v21 + 360.0f) {
              }
              for (; 360.0f < temp_v21; temp_v21 = temp_v21 - 360.0f) {
              }
              temp_v20 = *(float *)(param_3 + 6);
              if ((temp_v20 < temp_v21) && (temp_v21 < 360.0f - temp_v20)) {
                if (180.0f <= temp_v21) {
                  temp_v20 = 360.0f - temp_v20;
                }
                temp_v1 = 1;
                temp_v21 = temp_v20;
              }
              func_003e0870((struct RwMatrixTag*)temp_v24, (const RwV3d*)temp_v25, temp_v21 + temp_v14, rwCOMBINEPOSTCONCAT);
              func_003e05f0(pfVar8,temp_v25,temp_v24);
              func_003dc610(&fStack_340,pfVar8);
            }
            if (((*param_3 & 0x1000) == 0) || (!temp_v1)) {
              *param_3 = *param_3 & 0xf7ff;
            }
            else {
              if ((*param_3 & 0x800) == 0) {
                *(float *)(param_3 + 0x10) = fStack_340;
                *(float *)(param_3 + 0x14) = fStack_33c;
                *(float *)(param_3 + 0x18) = fStack_338;
                *(float *)(param_3 + 0x1c) = fStack_334;
              }
              *param_3 = *param_3 | 0x800;
            }
            if ((*param_3 & 0x800) != 0) {
              fStack_340 = *(float *)(param_3 + 0x10);
              fStack_33c = *(float *)(param_3 + 0x14);
              fStack_338 = *(float *)(param_3 + 0x18);
              fStack_334 = *(float *)(param_3 + 0x1c);
            }
            if (((*param_3 & 0x8000) != 0) &&
               ((*(float *)(param_3 + 0x24) != 0.0f || (*(float *)(param_3 + 0x26) != 0.0f)))) {
              fStack_390 = fStack_340;
              fStack_38c = fStack_33c;
              fStack_388 = fStack_338;
              fStack_384 = fStack_334;
              iStack_450 = 0;
              uStack_10 = 0;
              uStack_c = 0x3f800000;
              uStack_8 = 0;
              func_003dcb40(&uStack_10,&uStack_10,1,&fStack_390);
              func_003dc740(*(unsigned int *)(param_3 + 0x24),&fStack_340,&uStack_10,2);
              uStack_10 = 0x3f800000;
              uStack_c = 0;
              uStack_8 = 0;
              func_003dcb40(&uStack_10,&uStack_10,1,&fStack_390);
              func_003dc740(*(unsigned int *)(param_3 + 0x26),&fStack_340,&uStack_10,2);
            }
          }
          else {
            func_003dc610(&fStack_340,&fStack_330);
          }
          if ((*param_3 & 0x200) == 0) {
            if ((puVar3 == (unsigned int *)0x0) && ((*param_3 & 0x100) != 0)) {
              temp_v21 = func_004bd4a0((unsigned char *)(param_3 + 8),(unsigned char *)&fStack_340);
              if (temp_v21 < 0.0f) {
                afStack_350[3] = -fStack_334;
                afStack_350[0] = -fStack_340;
                afStack_350[1] = -fStack_33c;
                afStack_350[2] = -fStack_338;
                temp_v21 = func_004bd4a0((unsigned char *)(param_3 + 8),(unsigned char *)afStack_350);
              }
              temp_v21 = func_0044b920(temp_v21);
              if (temp_v21 * 2.0f < fGpffff804c) {
                *param_3 = *param_3 & 0x7e1f;
                *param_3 = *param_3 & 0xfbff;
              }
              *param_3 = *param_3 & 0xf7ff;
            }
            fStack_3b0 = *(float *)(param_3 + 8);
            fStack_3ac = *(float *)(param_3 + 10);
            fStack_3a8 = *(float *)(param_3 + 0xc);
            fStack_3a4 = *(float *)(param_3 + 0xe);
            func_003dcc70(&fStack_3b0,&fStack_340,&fStack_380);
            temp_v21 = *(float *)(param_3 + 2);
            if (temp_v21 <= 0.0f) {
              fStack_3a0 = fStack_3b0;
              fStack_39c = fStack_3ac;
              fStack_398 = fStack_3a8;
              fStack_394 = fStack_3a4;
            }
            else if (1.0f <= temp_v21) {
              fStack_3a0 = fStack_340;
              fStack_39c = fStack_33c;
              fStack_398 = fStack_338;
              fStack_394 = fStack_334;
            }
            else {
              temp_v20 = 1.0f - temp_v21;
              if (iStack_35c == 0) {
                temp_v20 = temp_v20 * fStack_360;
                temp_v14 = temp_v20 * temp_v20;
                temp_v20 = temp_v14 * temp_v20 *
                         (temp_v14 * (temp_v14 * (temp_v14 * (temp_v14 * (fGpffff8050 * temp_v14 +
                                                                 fGpffff8054) +
                                                       fGpffff8058) + fGpffff805c) +
                                   fGpffff8060) + fGpffff8064) + temp_v20;
                temp_v21 = temp_v21 * fStack_360;
                temp_v14 = temp_v21 * temp_v21;
                temp_v21 = temp_v14 * temp_v21 *
                         (temp_v14 * (temp_v14 * (temp_v14 * (temp_v14 * (fGpffff8050 * temp_v14 +
                                                                 fGpffff8054) +
                                                       fGpffff8058) + fGpffff805c) +
                                   fGpffff8060) + fGpffff8064) + temp_v21;
              }
              fStack_3a0 = fStack_380 * temp_v20;
              fStack_39c = fStack_37c * temp_v20;
              fStack_398 = fStack_378 * temp_v20;
              fStack_3a0 = fStack_3a0 + fStack_370 * temp_v21;
              fStack_39c = fStack_39c + fStack_36c * temp_v21;
              fStack_398 = fStack_398 + fStack_368 * temp_v21;
              fStack_394 = fStack_374 * temp_v20 + fStack_364 * temp_v21;
            }
            if (((*param_3 & 0x2000) == 0) || (iStack_450 == 0)) {
              *(float *)(param_3 + 8) = fStack_3a0;
              *(float *)(param_3 + 10) = fStack_39c;
              *(float *)(param_3 + 0xc) = fStack_398;
              *(float *)(param_3 + 0xe) = fStack_394;
            }
            else {
              func_003dc610(&uStack_3c0,&fStack_330);
              temp_v21 = func_004bd4a0((unsigned char *)&uStack_3c0,(unsigned char *)&fStack_3a0);
              if (temp_v21 < 0.0f) {
                afStack_350[3] = -fStack_394;
                afStack_350[0] = -fStack_3a0;
                afStack_350[1] = -fStack_39c;
                afStack_350[2] = -fStack_398;
                temp_v21 = func_004bd4a0((unsigned char *)&uStack_3c0,(unsigned char *)afStack_350);
              }
              temp_v21 = func_0044b920(temp_v21);
              if (temp_v21 * 2.0f <= fGpffff8068 * *(float *)(param_3 + 6)) {
                *(float *)(param_3 + 8) = fStack_3a0;
                *(float *)(param_3 + 10) = fStack_39c;
                *(float *)(param_3 + 0xc) = fStack_398;
                *(float *)(param_3 + 0xe) = fStack_394;
              }
              else {
                temp_v21 = 1.0f - fGpffff806c / (temp_v21 * 2.0f);
                func_003dcc70(&fStack_3a0,&uStack_3c0,&fStack_380);
                if (temp_v21 <= 0.0f) {
                  *(float *)(param_3 + 8) = fStack_3a0;
                  *(float *)(param_3 + 10) = fStack_39c;
                  *(float *)(param_3 + 0xc) = fStack_398;
                  *(float *)(param_3 + 0xe) = fStack_394;
                }
                else if (1.0f <= temp_v21) {
                  *(unsigned int *)(param_3 + 8) = uStack_3c0;
                  *(unsigned int *)(param_3 + 10) = uStack_3bc;
                  *(unsigned int *)(param_3 + 0xc) = uStack_3b8;
                  *(unsigned int *)(param_3 + 0xe) = uStack_3b4;
                }
                else {
                  temp_v20 = 1.0f - temp_v21;
                  if (iStack_35c == 0) {
                    temp_v20 = temp_v20 * fStack_360;
                    temp_v14 = temp_v20 * temp_v20;
                    temp_v20 = temp_v14 * temp_v20 *
                             (temp_v14 * (temp_v14 * (temp_v14 * (temp_v14 * (fGpffff8070 * temp_v14 +
                                                                     fGpffff8054) +
                                                           fGpffff8058) + fGpffff805c) +
                                       fGpffff8060) + fGpffff8064) + temp_v20;
                    temp_v21 = temp_v21 * fStack_360;
                    temp_v14 = temp_v21 * temp_v21;
                    temp_v21 = temp_v14 * temp_v21 *
                             (temp_v14 * (temp_v14 * (temp_v14 * (temp_v14 * (fGpffff8070 * temp_v14 +
                                                                     fGpffff8054) +
                                                           fGpffff8058) + fGpffff805c) +
                                       fGpffff8060) + fGpffff8064) + temp_v21;
                  }
                  *(float *)(param_3 + 8) = fStack_380 * temp_v20;
                  *(float *)(param_3 + 10) = fStack_37c * temp_v20;
                  *(float *)(param_3 + 0xc) = fStack_378 * temp_v20;
                  *(float *)(param_3 + 8) = *(float *)(param_3 + 8) + fStack_370 * temp_v21;
                  *(float *)(param_3 + 10) = *(float *)(param_3 + 10) + fStack_36c * temp_v21;
                  *(float *)(param_3 + 0xc) = *(float *)(param_3 + 0xc) + fStack_368 * temp_v21;
                  *(float *)(param_3 + 0xe) = fStack_374 * temp_v20 + fStack_364 * temp_v21;
                  /* gate 1370-52blend: third instance of the 1060/1124 blend shape. */
                  /* dest param_3+0x10, retail 0x4724B4-0x472524 blend arm only. */
                  /* mul-factor temp_v20 (= retail f0, Horner#3 output), mac-factor */
                  /* temp_v21 (= retail f20). Slot names from matched instance one */
                  /* by construction (0x1e0 spill is fStack_370). */
                  /* measured 1776+28=1804 (blend arm only). UNPAIRED: our compiler */
                  /* holds param_3 in $s3, retail in $s2, so composition stays flat */
                  /* (missing 114/extra 8) for that reason, not because the block */
                  /* is wrong; it pairs when the base-register blocker clears. */
                  *(float *)(param_3 + 0x10) = fStack_380 * temp_v20;
                  *(float *)(param_3 + 0x14) = fStack_37c * temp_v20;
                  *(float *)(param_3 + 0x18) = fStack_378 * temp_v20;
                  *(float *)(param_3 + 0x10) = *(float *)(param_3 + 0x10) + fStack_370 * temp_v21;
                  *(float *)(param_3 + 0x14) = *(float *)(param_3 + 0x14) + fStack_36c * temp_v21;
                  *(float *)(param_3 + 0x18) = *(float *)(param_3 + 0x18) + fStack_368 * temp_v21;
                  *(float *)(param_3 + 0x1c) = fStack_374 * temp_v20 + fStack_364 * temp_v21;
                }
              }
            }
          }
          else {
            func_003dc610(param_3 + 8,&fStack_330);
            *param_3 = *param_3 & 0xfdff;
            temp_v2 = 1;
            if ((*param_3 & 0x100) != 0) {
              *param_3 = *param_3 & 0x7e1f;
              *param_3 = *param_3 & 0xfbff;
              *param_3 = *param_3 & 0xf7ff;
            }
          }
        }
        if (puVar3 == (unsigned int *)0x0) {
          if (param_4 == 0) {
            temp_v16 = *(float *)(param_3 + 10);
            temp_v19 = *(float *)(param_3 + 8);
            temp_v18 = *(float *)(param_3 + 0xc);
            temp_v14 = *(float *)(param_3 + 0xe);
            temp_v20 = 2.0f / (temp_v14 * temp_v14 + temp_v18 * temp_v18 + temp_v19 * temp_v19 + temp_v16 * temp_v16);
            temp_v15 = temp_v19 * temp_v20;
            temp_v21 = temp_v16 * temp_v20;
            temp_v20 = temp_v18 * temp_v20;
            *pfVar8 = 1.0f - (temp_v16 * temp_v21 + temp_v18 * temp_v20);
            pfVar8[1] = temp_v19 * temp_v21 + temp_v20 * temp_v14;
            pfVar8[2] = temp_v18 * temp_v15 - temp_v21 * temp_v14;
            pfVar8[4] = temp_v19 * temp_v21 - temp_v20 * temp_v14;
            pfVar8[5] = 1.0f - (temp_v18 * temp_v20 + temp_v19 * temp_v15);
            pfVar8[6] = temp_v16 * temp_v20 + temp_v15 * temp_v14;
            pfVar8[8] = temp_v18 * temp_v15 + temp_v21 * temp_v14;
            pfVar8[9] = temp_v16 * temp_v20 - temp_v15 * temp_v14;
            pfVar8[10] = 1.0f - (temp_v19 * temp_v15 + temp_v16 * temp_v21);
            pfVar8[0xc] = 0.0f;
            pfVar8[0xd] = 0.0f;
            pfVar8[0xe] = 0.0f;
            pfVar8[3] = 4.2039e-45f;
            afStack_30[0] = *(float *)(param_3 + 0x18);
            afStack_30[1] = *(float *)(param_3 + 0x1a);
            afStack_30[2] = *(float *)(param_3 + 0x1c);
            if ((*param_2 & 0x10) != 0) {
              afStack_30[0] = afStack_30[0] * DAT_00922bb0;
              afStack_30[1] = afStack_30[1] * DAT_00922bb0 * DAT_00922bb4;
              afStack_30[2] = afStack_30[2] * DAT_00922bb0 * DAT_00922bb4;
            }
            func_003e0a90(pfVar8,afStack_30,1);
            pfVar8[0xc] = fStack_20;
            pfVar8[0xd] = fStack_1c;
            pfVar8[0xe] = fStack_18;
          }
          else {
            temp_v16 = *(float *)(param_3 + 10);
            temp_v19 = *(float *)(param_3 + 8);
            temp_v18 = *(float *)(param_3 + 0xc);
            temp_v14 = *(float *)(param_3 + 0xe);
            temp_v20 = 2.0f / (temp_v14 * temp_v14 + temp_v18 * temp_v18 + temp_v19 * temp_v19 + temp_v16 * temp_v16);
            temp_v15 = temp_v19 * temp_v20;
            temp_v21 = temp_v16 * temp_v20;
            temp_v20 = temp_v18 * temp_v20;
            fStack_330 = 1.0f - (temp_v16 * temp_v21 + temp_v18 * temp_v20);
            fStack_32c = temp_v19 * temp_v21 + temp_v20 * temp_v14;
            fStack_328 = temp_v18 * temp_v15 - temp_v21 * temp_v14;
            fStack_320 = temp_v19 * temp_v21 - temp_v20 * temp_v14;
            fStack_31c = 1.0f - (temp_v18 * temp_v20 + temp_v19 * temp_v15);
            fStack_318 = temp_v16 * temp_v20 + temp_v15 * temp_v14;
            fStack_310 = temp_v18 * temp_v15 + temp_v21 * temp_v14;
            fStack_30c = temp_v16 * temp_v20 - temp_v15 * temp_v14;
            fStack_308 = 1.0f - (temp_v19 * temp_v15 + temp_v16 * temp_v21);
            fStack_300 = 0.0f;
            fStack_2fc = 0.0f;
            fStack_2f8 = 0.0f;
            uStack_324 = 3;
            afStack_30[0] = *(float *)(param_3 + 0x18);
            afStack_30[1] = *(float *)(param_3 + 0x1a);
            afStack_30[2] = *(float *)(param_3 + 0x1c);
            if ((*param_2 & 0x10) != 0) {
              afStack_30[0] = afStack_30[0] * DAT_00922bb0;
              afStack_30[1] = afStack_30[1] * DAT_00922bb0 * DAT_00922bb4;
              afStack_30[2] = afStack_30[2] * DAT_00922bb0 * DAT_00922bb4;
            }
            func_003e0a90(&fStack_330,afStack_30,1);
            fStack_300 = fStack_20;
            fStack_2fc = fStack_1c;
            fStack_2f8 = fStack_18;
            func_003e05f0(pfVar8,&fStack_330,param_4);
          }
          if (((*(int *)(uStack_430 + 0xc) != 0) &&
              (temp_v7 = *(int *)(*(int *)(uStack_430 + 0xc) + 4), temp_v7 != 0)) &&
             ((*(unsigned char *)(*(int *)(temp_v7 + 0xa0) + 3) & 1) != 0)) {
            func_003ed960();
          }
        }
        else {
          func_003e05f0(pfVar8,&fStack_230,pfVar21);
        }
      }
      else {
        func_003e05f0(pfVar8,&fStack_230,pfVar21);
      }
      temp_v7 = *(int *)(uStack_430 + 0xc);
      if (temp_v7 != 0) {
        if ((temp_v10 & 0x1000) != 0) {
          pfVar17 = &fStack_230;
          pfVar16 = (float *)(temp_v7 + 0x10);
          temp_v8 = 8;
          do {
            temp_v21 = *pfVar17;
            temp_v20 = pfVar17[1];
            pfVar17 = pfVar17 + 2;
            temp_v8 = temp_v8 - 1;
            *pfVar16 = temp_v21;
            pfVar16[1] = temp_v20;
            pfVar16 = pfVar16 + 2;
          } while (0 < temp_v8);
          if (temp_v3 == 0) {
            func_003e9680(temp_v7);
          }
        }
        if (temp_v3 != 0) {
          if ((temp_v10 & 0x4000) == 0) {
            pfVar17 = (float *)(temp_v7 + 0x50);
            temp_v8 = 8;
            pfVar16 = pfVar8;
            do {
              temp_v21 = *pfVar16;
              temp_v20 = pfVar16[1];
              pfVar16 = pfVar16 + 2;
              temp_v8 = temp_v8 - 1;
              *pfVar17 = temp_v21;
              pfVar17[1] = temp_v20;
              pfVar17 = pfVar17 + 2;
            } while (0 < temp_v8);
          }
          else {
            func_003e05f0(temp_v7 + 0x50,pfVar8,afStack_b0);
          }
          *(unsigned char *)(temp_v7 + 3) = (*(unsigned char *)(temp_v7 + 3) & 0xfb) | 8;
        }
      }
      temp_v6 = *(unsigned int *)(uStack_430 + 8) & 3;
      pfVar16 = pfVar21;
      if (temp_v6 != 3) {
        pfVar16 = pfVar8;
        if (temp_v6 == 2) {
          *puVar22 = (unsigned int)pfVar21;
          puVar22 = puVar22 + 1;
        }
        else if (temp_v6 == 1) {
          puVar22 = puVar22 + -1;
          pfVar16 = (float *)*puVar22;
        }
        else if (temp_v6 != 0) {
          pfVar16 = pfVar21;
        }
      }
      pfVar21 = pfVar16;
      temp_v11 = temp_v11 + temp_v9;
      pfVar8 = pfVar8 + 0x10;
      uStack_430 = uStack_430 + 0x10;
    }
    if ((puVar3 != (unsigned int *)0x0) && ((*param_3 & 0x81e0) != 0)) {
      if (*(short *)((int)puVar3 + 0x42) == 0) {
        for (temp_v10 = 0; temp_v10 < 4; temp_v10 = temp_v10 + 1) {
          temp_v5 = (unsigned int)func_003d5790((int)puVar12[1], (int)*(unsigned int *)(puVar12[8] + 0x20));
          (puVar3 + temp_v10)[4] = (int)temp_v5;
          func_003d5840((void *)temp_v5, (void *)puVar3[temp_v10]);
        }
        *(unsigned short *)((int)puVar3 + 0x42) = 1;
      }
      if (temp_v2) {
        puVar3[0xc] = 0x3f800000;
        puVar3[0x12] = 0;
      }
      if ((1.0f <= ((float *)puVar3)[0xe]) ||
         (pbVar19 = *(unsigned char **)(param_2 + 0x14), pbVar19 == (unsigned char *)0x0)) {
        pbVar19 = (unsigned char *)puVar12[8];
        temp_v21 = *(float *)(pbVar19 + 4);
      }
      else {
        piVar4 = *(int **)(**(int **)(param_2 + 0x1a) + 0x4c + (short)param_2[2] * 0x50);
        if (piVar4 == (int *)0x0) {
          temp_v21 = 0.0f;
        }
        else {
          temp_v21 = fGpffff8040 * (float)*piVar4;
        }
      }
      uStack_70 = 0;
      uStack_6c = 0;
      uStack_68 = 0x3f800000;
      if ((*param_3 & 0x100) == 0) {
        func_003dcb40(&fStack_60,&uStack_70,1,param_3 + 8);
        temp_v17 = *(unsigned int *)(param_3 + 10);
        temp_v12 = *(unsigned int *)(param_3 + 0xc);
        temp_v13 = *(unsigned int *)(param_3 + 0xe);
        puVar3[8] = *(unsigned int *)(param_3 + 8);
        puVar3[9] = temp_v17;
        puVar3[10] = temp_v12;
        puVar3[0xb] = temp_v13;
      }
      else {
        func_003dcb40(&fStack_60,&uStack_70,1,puVar3 + 8);
      }
      func_003e0960(temp_v22,afStack_b0);
      func_003e4320(&fStack_60,&fStack_60,temp_v22);
      func_003e40b0(&fStack_60,&fStack_60);
      temp_v20 = (float)*(unsigned short *)((int)puVar3 + 0x3e) / *(float *)(param_3 + 6);
      if (0.0f <= fStack_60) {
        func_003d5840(puVar3[5],puVar3[1]);
        func_003d5e40((unsigned char *)puVar3[5],temp_v21);
        func_003d5e90((unsigned char *)puVar3[6],pbVar19,(unsigned char *)puVar3[5],fStack_60 / temp_v20);
        temp_v9 = 2;
      }
      else {
        func_003d5840(puVar3[6],puVar3[2]);
        func_003d5e40((unsigned char *)puVar3[6],temp_v21);
        func_003d5e90((unsigned char *)puVar3[5],pbVar19,(unsigned char *)puVar3[6],-fStack_60 / temp_v20);
        temp_v9 = 1;
      }
      if (0.0f <= fStack_5c) {
        func_003d5840(puVar3[7],puVar3[3]);
        func_003d5e40((unsigned char *)puVar3[7],temp_v21);
        func_003d5e90((unsigned char *)puVar3[4],(unsigned char *)puVar3[temp_v9 + 4],(unsigned char *)puVar3[7],fStack_5c);
        puVar3[0x11] = 0;
      }
      else {
        func_003d5840(puVar3[4],*puVar3);
        func_003d5e40((unsigned char *)puVar3[4],temp_v21);
        func_003d5e90((unsigned char *)puVar3[7],(unsigned char *)puVar3[temp_v9 + 4],(unsigned char *)puVar3[4],-fStack_5c);
        puVar3[0x11] = 3;
      }
      if ((1.0f <= ((float *)puVar3)[0xe]) || (*(unsigned char **)(param_2 + 0x12) == (unsigned char *)0x0)) {
        if ((*(u16 *)param_3 & 0x100) == 0) {
          ((float *)puVar3)[0xc] = ((float *)puVar3)[0xc] * (1.0f - *(float *)(param_3 + 4));
          puVar3[0x12] = 0x3f800000;
          func_003d5e90((unsigned char *)puVar12[8],(unsigned char *)puVar12[8],(unsigned char *)puVar3[puVar3[0x11] + 4],
                        1.0f - ((float *)puVar3)[0xc]);
        }
        else {
          ((float *)puVar3)[0x12] = ((float *)puVar3)[0x12] * (1.0f - *(float *)(param_3 + 4));
          func_003d5e90((unsigned char *)puVar12[8],(unsigned char *)puVar12[8],(unsigned char *)puVar3[puVar3[0x11] + 4],
                        ((float *)puVar3)[0x12]);
          if (((float *)puVar3)[0x12] < fGpffff8074) {
            *(u16 *)param_3 = *(u16 *)param_3 & 0x7e1f;
            *(u16 *)param_3 = *(u16 *)param_3 & 0xfbff;
          }
          *(u16 *)param_3 = *(u16 *)param_3 & 0xf7ff;
        }
      }
      else {
        func_003d5e90((unsigned char *)puVar12[8],*(unsigned char **)(param_2 + 0x12),(unsigned char *)puVar3[puVar3[0x11] + 4]
                      ,((float *)puVar3)[0xe]);
        ((float *)puVar3)[0xe] = ((float *)puVar3)[0xe] + 1.0f / (float)puVar3[0xd];
        puVar3[0xc] = 0;
      }
      func_00397c40(param_1);
    }
  }
  return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00471370);
#endif
#pragma pop
/* gate: object 1776 against retail 1776 - INSIDE the +-3% band (1723-1829).  Scores at
   gate: GUARDED_SCORE 1636, fnalign edits 2073, both comparable (equal length).
   Production guarded, fallback INCLUDE_ASM retained. */

extern void func_00397c40(void* a, void* b);
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
            func_00397c40(arg0, p5);
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

    uVar2 = func_00399d80();
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
    func_0043f9c8(param_1, 0, 0xA4);
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
extern void func_003d5e90(void* a, void* b, void* c, f32 d);
extern void func_00397c40_1(void* a);
/* measured: simplified v18 (manual 2.0f halving removed) + fixed 3d5bc0 arity (retail 2-arg a0/f12, not 3-arg with tbl). Transferable lever: write `(f32)(u32)x` and let b210 emit bltz/srl/andi/or/mtc1/cvt/add.s itself. Prior draft 298 words 1380/1440 (4.2% short, correctly unbanked); this 1472/1440 passes. */
// FUN_00473B20 NONMATCHING
#ifdef NON_MATCHING
u8 *func_00473b20(u8 *arg0, u8 *arg1, s32 arg2)
{
    extern void func_00397c40();
    s16 idx;
    u8 *tbl;
    u8 *ptr;
    u8 *ptr2;
    f32 temp_f20;
    s32 off;
    s32 off2;
    u16 cnt;
    s64 sIdx;
    s64 sIdx2;
    u16 v18;
    f32 var_f;
    f32 nf;
    u32 b40;

    idx = *(s16*)(arg0 + 4);
    if (idx < 0) {
        return arg1;
    }
    if (*(u8*)(arg0 + 2) == 1) {
        tbl = *(u8**)(arg0 + 0x34);
        if ((tbl != (u8*)0) && (idx < *(u16*)(tbl + 8))) {
            off = (s32)idx * 0x50;
            ptr = *(u8**)(*(u32*)tbl + 0x40 + off);
            if ((ptr != (u8*)0) && (ptr != (u8*)D_00922BC0_abs)) {
                if ((tbl != (u8*)0) && (*(s32*)(tbl + 4) != 0)) {
                    func_003d5e40(*(u8**)(*(u8**)(arg0 + 0x20) + 0x20), *(f32*)(arg0 + 0xC) - 1.0f);
                    func_003d5e40(*(u8**)(*(u8**)(arg0 + 0x20) + 0x20), *(f32*)(arg0 + 0xC));
                    func_00473870(arg0);
                }
                func_00397c40(*(u8**)(arg0 + 0x20));
            }
        }
        return arg1;
    }
    temp_f20 = iGpffff8040 * *(f32*)(arg0 + 8);
    if ((!(temp_f20 <= 0.0f)) || (*(u16*)(arg0 + 0) & 6)) {
        if (*(f32*)(arg0 + 0x1C) < 1.0f) {
            tbl = *(u8**)(arg0 + 0x34);
            if ((tbl != (u8*)0) && (sIdx = (s64)idx, cnt = *(u16*)(tbl + 8), sIdx < (s64)(u32)cnt) && (off = (s32)sIdx * 0x50, b40 = *(u32*)tbl + 0x40, ptr = *(u8**)(b40 + off), (ptr != (u8*)0) && (ptr != (u8*)D_00922BC0_abs)) && (sIdx2 = (s64)*(s16*)(arg0 + 0x10), sIdx2 < (s64)(u32)cnt) && (off2 = (s32)sIdx2 * 0x50, ptr2 = *(u8**)(b40 + off2), (ptr2 != (u8*)0) && (ptr2 != (u8*)D_00922BC0_abs))) {
                func_003d5e90(*(void**)(*(u8**)(arg0 + 0x20) + 0x20), *(void**)(arg0 + 0x24), *(void**)(arg0 + 0x28), *(f32*)(arg0 + 0x1C));
                v18 = *(u16*)(arg0 + 0x18);
                var_f = (f32)(u32)v18;
                nf = *(f32*)(arg0 + 0x1C) + (1.0f / var_f);
                *(f32*)(arg0 + 0x1C) = nf;
                if (!(nf < 1.0f)) {
                    func_003d5840(*(void**)(*(u8**)(arg0 + 0x20) + 0x20), *(void**)(*(u8**)(arg0 + 0x28)));
                    ptr = *(u8**)(*(u32*)(*(u32*)(arg0 + 0x34)) + 0x4C + off);
                    if (ptr == (u8*)0) {
                        func_003d5e40(*(u8**)(*(u8**)(arg0 + 0x20) + 0x20), temp_f20);
                    } else {
                        func_003d5e40(*(u8**)(*(u8**)(arg0 + 0x20) + 0x20), temp_f20 + iGpffff8040 * (f32)*(s32*)ptr);
                    }
                }
            } else {
                v18 = *(u16*)(arg0 + 0x18);
                var_f = (f32)(u32)v18;
                *(f32*)(arg0 + 0x1C) = *(f32*)(arg0 + 0x1C) + (1.0f / var_f);
            }
        } else {
            tbl = *(u8**)(arg0 + 0x34);
            if ((tbl != (u8*)0) && ((s64)idx < (s64)(u32)*(u16*)(tbl + 8)) && (*(u8**)(*(u32*)tbl + 0x40 + (s32)idx * 0x50) != (u8*)0) && (*(u8**)(*(u32*)tbl + 0x40 + (s32)idx * 0x50) != (u8*)D_00922BC0_abs)) {
                func_003d5bc0(*(void**)(*(u8**)(arg0 + 0x20) + 0x20), temp_f20);
            } else if (tbl == (u8*)0) {
                *(f32*)(arg0 + 0xC) = *(f32*)(arg0 + 0xC) + temp_f20;
            } else if (*(u8**)(*(u32*)tbl + (s32)idx * 0x50 + 0x40) == (u8*)D_00922BC0_abs) {
            } else {
                *(f32*)(arg0 + 0xC) = *(f32*)(arg0 + 0xC) + temp_f20;
            }
        }
        *(u16*)(arg0 + 0) = *(u16*)(arg0 + 0) & 0xFFFB;
    }
    tbl = *(u8**)(arg0 + 0x34);
    if ((tbl != (u8*)0) && ((s64)idx < (s64)(u32)*(u16*)(tbl + 8))) {
        off = (s32)idx * 0x50;
        ptr = *(u8**)(*(u32*)tbl + 0x40 + off);
        if ((ptr != (u8*)0) && (ptr != (u8*)D_00922BC0_abs)) {
            if ((*(u16*)(arg0 + 0) & 2) && (arg1 != (u8*)0)) {
                func_00471280(*(void**)(*(u8**)(arg0 + 0x20) + 0x20), *(void**)(*(u8**)(arg1 + 0x20) + 0x20), *(void**)(*(u8**)(arg0 + 0x20) + 0x20), 1.0f);
            }
            func_00473870(arg0);
            if (arg2 != 0) {
                if (*(u16*)(arg0 + 0) & 0x10) {
                    func_00473000(*(u8**)(arg0 + 0x20), arg0);
                } else if (*(u16*)(arg0 + 0x54) & 0x81E0) {
                    func_00471370(*(u8**)(arg0 + 0x20), arg0, arg0 + 0x54, (void*)0);
                } else {
                    func_00397c40(*(u8**)(arg0 + 0x20));
                }
            }
            v18 = *(u16*)(arg0 + 0x54);
            if (v18 & 0x81E0) {
                *(u16*)(arg0 + 0x54) = v18 | 0x4000;
            } else {
                *(u16*)(arg0 + 0x54) = v18 & 0xBFFF;
            }
            *(f32*)(arg0 + 0xC) = *(f32*)(*(u32*)(*(u32*)(arg0 + 0x20) + 0x20) + 4);
        }
    }
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00473b20);
#endif
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

            if (((userData != 0) && (func_00442c30(userData, &gp0xffff9d10, 5) == 0)) &&
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
        if (func_00399d80(*(void**)((u8*)*(void**)((u8*)obj + 0x20) + i * 4)) != 0) {
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
            switch (func_00399d80(*it)) {
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
                switch (func_00399d80(*object)) {
                case 5: case 6: func_0039a700(*object, 0, 0); break;
                }
                name = func_00474ce0((void *)*object);
                if (name != 0) {
                    animation = func_003d6170(((MdlAnimResourceEntry *)addOff((s32)index * 8, (u32)state->resource->entries))->resource, name);
                    if (animation != 0) {
                        special = func_00442c30(name, &gp0xffff9d10, 5) == 0;
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
    switch (func_00399d80(*it)) {
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

    func_003e05f0(buf, entry, func_003e9700(clump));
    return 1;
}

/* LaneMdlManager func_00475cd0 best: sched 4028B/4000B nd 915 (base 4524B nd 1014).
 * Retail window 4000B frame 0x1A0; candidate frame 0x1D0 (3 extra saved s5-s7).
 * First diffs sched at 0 (frame), 56 (sltu vs slt head), 64 (sb via $a2 vs direct 0x280),
 * 132+ (color alpha div/mul order), 260+ (flags CSE), 340+ (jal/addiu order).
 * Measured probe_variants (serial, isolated TU copies, source unchanged):
 *   base 1014, 77260-u64->void* 1014, noflags 1021, split-i/j/has 1014,
 *   csub_off 1057, prop_off 1024, loopinv 1014, sched_on 915 (-99, 4524->4028B),
 *   sched+csub 967, sched+prop 918, sched+nobrlikely 924, sched+loopinv 915,
 *   s32 915, u8cast 921, swap_ij 915, modellast 915, hasfirst 915, u8param 915, idx 916.
 * Floor: address-CSE (param+0x280/$a2, +0x260/s2, +0xD3/s7 saved vs retail direct),
 *   saved-coloring (param s4 vs s0, 8 vs 5 regs), branch-likely under sched (beql vs beqz),
 *   value(0x80)+result(0x90,40B) vs merged interpolation, easing two-stage vs independent curves.
 * Production remains INCLUDE_ASM; owner 126 markers, 120 MATCH/6 ASM unchanged. func_00479100 untouched (29-word floor).
 */
/* gate: func_00475cd0 is INSIDE the +-3% band at 1002 against retail 1000 (+0.2%).
   Fix was deleting early-return surplus work retail does not do: after the first
   0xD8/0x80000 check the body called func_00477260, e0 effect (0x7C01B/0x7F06B/0x7D7FB),
   func_00479910/004789c0, a second 0xEC/0x140 three-way, 0x2CC effect, and the i<2
   loop before the j<5 loop. Retail/M2C early (color[3]==0) goes directly from the
   first 0xD8 check to the j-loop then return. Deletion 1131->1002 (-129, +13.1%->+0.2%),
   fnalign 1089->610 edits (-479). Also: 00477260 u64->void* (matches FUN_00477260
   void*), current/target/value u32->s32 (retail slt, M2C s32), main j-loop copy outside
   the (&2==0 && d3!=0) guard with !=-1 call-first (matches M2C/retail). Frame still
   0x1E0 vs 0x1A0 (address-CSE/saved-coloring floor, count-neutral). */
typedef struct {
    u8 _00[0xD3];
    u8 d3;
    u8 _D4[0x0C];
    void* e0;
    u8 _E4[0x17C];
    u8 flags;
} Mdl475Param;

// FUN_00475CD0 NONMATCHING
#ifdef NON_MATCHING
/* measured: schedule on 1014->915 (-99, 4524->4028B, 28B over window; frame still 0x1D0 vs 0x1A0). */
void func_00475cd0(void* param_1)
{
    extern void func_00397c40();
    extern void func_003f6440(s32 a, s32 b);
    extern void func_00477260(void* a, u32* b, u16 c);
    extern void func_004789c0(void* a);
    extern void func_003dc610(void* out, void* in);
    extern void func_003dcb40(void* out, const void* in, s32 count, const void* quat);
    extern void func_003dcc70(f32* first, f32* second, void* result);
    extern f32 func_0044b920(f32 value);
    extern void* func_004571b0(void);
    extern void* func_004571c0(void* object, u32 index);
    extern void func_004746b0(u8* a, u8* b);
    extern void func_00479910(void* a);
    extern void* func_0047a2f0(void* a);
    extern s32 func_0047a510(void* a, s32 b, void* c);
    extern void func_0047d540(u32 a, void* b);
    extern void func_0047d900(u32 a, void* b);
    extern void func_0047dd40(u32 a, void* b);
    extern void (*D_00887300_abs[])(s32, s32);
    extern void (*D_00887304[])(s32, void*);
    extern f32 fGpffff8054;
    extern f32 fGpffff8058;
    extern f32 fGpffff805c;
    extern f32 fGpffff8060;
    extern f32 fGpffff80f0;
    extern f32 fGpffff81f4;

    s32 current;
    s32 target;
    s32 value;
    u32 flags;
    struct {
        f32 quaternion[4];
        struct {
            f32 value[4];
            f32 second[4];
            f32 scale;
            s32 flag;
        } interpolation;
        u8 padding[0x18];
        u8 identity[0x40];
        u8 matrix0[0x40];
        u8 matrix1[0x48];
        f32 direction[3];
        u8 directionPadding[4];
        s32 renderState;
        u8 color[4];
    } stack;
#define color stack.color
#define quaternion stack.quaternion
#define interpolation stack.interpolation
#define direction stack.direction
#define matrix0 stack.matrix0
#define matrix1 stack.matrix1
#define identity stack.identity
#define renderState stack.renderState
    void (**renderStateSet)(s32, s32);
    u8* material;
    u8* source;
    u8* effect;
    u8* slot;
    u8* model;
    u8* animation;
    u16 i;
    u16 j;
    u16 k;
    u32 hasIndex;
    u32 hasItem;
    u32 needsReset;
    u32 copyCount;
    u32* copySource;
    u32* copyTarget;

    target = *(u8*)((u8*)param_1 + 0x281);
    current = *(u8*)((u8*)param_1 + 0x280);
    if (current < target) {
        value = current + *(u8*)((u8*)param_1 + 0x282);
        if (target < value) {
            *(u8*)((u8*)param_1 + 0x280) = (u8)target;
        } else {
            *(u8*)((u8*)param_1 + 0x280) = (u8)value;
        }
    } else if (target < current) {
        value = current - *(u8*)((u8*)param_1 + 0x282);
        if (value < target) {
            *(u8*)((u8*)param_1 + 0x280) = (u8)target;
        } else {
            *(u8*)((u8*)param_1 + 0x280) = (u8)value;
        }
    } else {
        *(u8*)((u8*)param_1 + 0x280) = (u8)target;
    }

    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    flags = ((Mdl475Param*)param_1)->flags;
    {
        f32 alpha;
        s32 alphaValue;
        alpha = 255.0f * ((f32)(*(u8*)((u8*)param_1 + 0x280)
                                * ((Mdl475Param*)param_1)->d3) / 65025.0f);
        if (alpha >= 2147483600.0f) {
            alphaValue = (s32)(alpha - 2147483600.0f);
        } else {
            alphaValue = (s32)alpha;
        }
        color[3] = (u8)alphaValue;
    }

    if ((flags & 1) != 0 && (flags & 0x20) == 0) {
        material = (u8*)func_004571b0();
    } else {
        material = (u8*)func_004571c0(param_1, target);
    }
    material = *(u8**)(material + 4);

    if ((flags & 2) != 0 && (flags & 0x20) == 0) {
        if ((flags & 4) == 0) {
            func_003dc610(quaternion, material + 0x10);
        } else {
            quaternion[0] = *((f32*)((u8*)&fGpffff81f4) + 1);
            quaternion[1] = 0.0f;
            quaternion[2] = 0.0f;
            quaternion[3] = quaternion[0];
        }
        {
            f32 dot;
            f32 angle;
            f32 amount;
            f32 limit;
            dot = *(f32*)((u8*)param_1 + 0x268) * quaternion[1]
                + *(f32*)((u8*)param_1 + 0x264) * quaternion[0]
                + *(f32*)((u8*)param_1 + 0x26C) * quaternion[2]
                + *(f32*)((u8*)param_1 + 0x270) * quaternion[3];
            if (dot < 0.0f) {
                quaternion[3] = -quaternion[3];
                quaternion[0] = -quaternion[0];
                quaternion[1] = -quaternion[1];
                quaternion[2] = -quaternion[2];
                dot = *(f32*)((u8*)param_1 + 0x268) * quaternion[1]
                    + *(f32*)((u8*)param_1 + 0x264) * quaternion[0]
                    + *(f32*)((u8*)param_1 + 0x26C) * quaternion[2]
                    + *(f32*)((u8*)param_1 + 0x270) * quaternion[3];
            }
            angle = 2.0f * func_0044b920(dot);
            limit = *(f32*)((u8*)param_1 + 0x284);
            if (limit < 1.0f) {
                f32 maximum;
                maximum = *(f32*)((u8*)param_1 + 0x288);
                if (angle <= maximum) {
                    amount = limit;
                } else {
                    amount = maximum / angle;
                    if (amount < limit) {
                        amount = limit;
                    }
                }
                func_003dcc70((f32*)((u8*)param_1 + 0x264), quaternion,
                              &interpolation);
                if (amount <= 0.0f) {
                    interpolation.value[0] = *(f32*)((u8*)param_1 + 0x264);
                    interpolation.value[1] = *(f32*)((u8*)param_1 + 0x268);
                    interpolation.value[2] = *(f32*)((u8*)param_1 + 0x26C);
                    interpolation.value[3] = *(f32*)((u8*)param_1 + 0x270);
                } else if (amount >= 1.0f) {
                    interpolation.value[0] = quaternion[0];
                    interpolation.value[1] = quaternion[1];
                    interpolation.value[2] = quaternion[2];
                    interpolation.value[3] = quaternion[3];
                } else {
                    f32 remaining;
                    f32 t;
                    f32 t2;
                    f32 t3;
                    f32 curve0;
                    f32 curve1;
                    remaining = 1.0f - amount;
                    if (interpolation.flag == 0) {
                        t = remaining * interpolation.scale;
                        t2 = t * t;
                        curve0 = t2 * (t2 * (t2 * (t2 * (t2 * fGpffff8054
                            + fGpffff8058) + fGpffff805c) + fGpffff8060)
                            + *(f32*)((u8*)&fGpffff81f4 + 8))
                            + t;
                        t = curve0 * interpolation.scale;
                        t2 = t * t;
                        curve1 = t2 * (t2 * (t2 * (t2 * (t2 * fGpffff8054
                            + fGpffff8058) + fGpffff805c) + fGpffff8060)
                            + *(f32*)((u8*)&fGpffff81f4 + 8))
                            + t;
                        interpolation.scale = curve1;
                    }
                    t = interpolation.value[0] * remaining;
                    interpolation.value[0] = t + interpolation.second[0] * interpolation.scale;
                    t = interpolation.value[1] * remaining;
                    interpolation.value[1] = t + interpolation.second[1] * interpolation.scale;
                    t = interpolation.value[2] * remaining;
                    interpolation.value[2] = t + interpolation.second[2] * interpolation.scale;
                    interpolation.value[3] = interpolation.value[3] * amount;
                    interpolation.value[3] = interpolation.value[3] + interpolation.second[3] * interpolation.scale;
                }
                *(f32*)((u8*)param_1 + 0x264) = interpolation.value[0];
                *(f32*)((u8*)param_1 + 0x268) = interpolation.value[1];
                *(f32*)((u8*)param_1 + 0x26C) = interpolation.value[2];
                *(f32*)((u8*)param_1 + 0x270) = interpolation.value[3];
            } else {
                *(f32*)((u8*)param_1 + 0x264) = quaternion[0];
                *(f32*)((u8*)param_1 + 0x268) = quaternion[1];
                *(f32*)((u8*)param_1 + 0x26C) = quaternion[2];
                *(f32*)((u8*)param_1 + 0x270) = quaternion[3];
            }
        }
        func_003dcb40(direction, (u8*)D_00713138 + 0x10, 1,
                      (u8*)param_1 + 0x264);
    } else {
        source = material + 0x10;
        func_003dc610((u8*)param_1 + 0x264, source);
        direction[0] = *(f32*)(source + 0x20);
        direction[1] = *(f32*)(source + 0x24);
        direction[2] = *(f32*)(source + 0x28);
    }

    if (color[3] == 0) {
        if ((*(u16*)((u8*)param_1 + 0xEC) & 0x10) != 0) {
            func_00473000(*(void**)((u8*)param_1 + 0x10C),
                          (u8*)param_1 + 0xEC);
        } else if ((*(u16*)((u8*)param_1 + 0x140) & 0x81E0) != 0) {
            func_00471370(*(void**)((u8*)param_1 + 0x10C),
                          (u8*)param_1 + 0xEC, (u8*)param_1 + 0x140, 0);
        } else {
            func_00397c40(*(void**)((u8*)param_1 + 0x10C));
        }
        if ((*(u32*)((u8*)param_1 + 0xD8) & 0x80000) != 0) {
            func_004746b0((u8*)param_1 + 0x234, (u8*)param_1 + 0xEC);
        }
        j = 0;
        while (j < 5) {
            slot = (u8*)param_1 + j * 0xC;
            if ((*(u8*)(slot + 0x28C) & 1) != 0 &&
                *(void**)(slot + 0x290) != 0 &&
                func_0047ae90(param_1, j) != 0) {
                model = *(u8**)(slot + 0x290);
                if ((*(u32*)(model + 0xD8) & 2) == 0) {
                    if (*(s32*)(slot + 0x294) == -1) {
                        copyCount = 8;
                        copySource = (u32*)param_1;
                        copyTarget = (u32*)model;
                        do {
                            copyTarget[0] = copySource[0];
                            copyTarget[1] = copySource[1];
                            copySource += 2;
                            copyTarget += 2;
                            copyCount--;
                        } while (copyCount > 0);
                    } else {
                        func_0047a510(param_1, *(s32*)(slot + 0x294),
                                      func_0047a2f0(model));
                    }
                    hasIndex = 0;
                    hasItem = 0;
                    needsReset = 0;
                    animation = *(u8**)(model + 0x120);
                    if (animation != 0 &&
                        *(s16*)(model + 0xF0) < *(u16*)(animation + 8)) {
                        hasIndex = 1;
                    }
                    if (hasIndex != 0 &&
                        *(void**)((u8*)*(void**)animation
                                  + *(s16*)(model + 0xF0) * 0x50 + 0x40) != 0) {
                        hasItem = 1;
                    }
                    if (hasItem != 0 &&
                        *(void**)((u8*)*(void**)animation
                                  + *(s16*)(model + 0xF0) * 0x50 + 0x40)
                            != (void*)D_00922BC0_abs) {
                        needsReset = 1;
                    }
                    if (needsReset != 0) {
                        func_00397c40(*(void**)(model + 0x10C));
                    }
                    if ((*(u32*)(model + 0xD8) & 0x80000) != 0) {
                        func_004746b0(model + 0x234, model + 0xEC);
                    }
                }
            }
            j++;
        }
        return;
    }

    if (direction[1] >= 0.0f) {
        f32 unit;
        unit = *((f32*)((u8*)&fGpffff81f4) + 1);
        *(f32*)((u8*)param_1 + 0x264) = unit;
        *(f32*)((u8*)param_1 + 0x268) = 0.0f;
        *(f32*)((u8*)param_1 + 0x26C) = 0.0f;
        *(f32*)((u8*)param_1 + 0x270) = unit;
        func_003dcb40(direction, (u8*)D_00713138 + 0x10, 1,
                      (u8*)param_1 + 0x264);
    }
    if (*(f32*)((u8*)param_1 + 0x274) !=
        *(f32*)((u8*)param_1 + 0x278)) {
        *(f32*)((u8*)param_1 + 0x274) =
            *(f32*)((u8*)param_1 + 0x274)
            + *(f32*)((u8*)param_1 + 0x27C)
              * (*(f32*)((u8*)param_1 + 0x278)
                 - *(f32*)((u8*)param_1 + 0x274));
    }
    {
        f32 limit;
        limit = *(f32*)((u8*)param_1 + 0x274);
        if (fabsf(direction[1]) < limit) {
            if (direction[1] < 0.0f) {
                direction[1] = -limit;
            } else {
                direction[1] = limit;
            }
        }
    }

    *(f32*)(identity + 0x00) = 1.0f;
    *(f32*)(identity + 0x04) = 0.0f;
    *(f32*)(identity + 0x08) = 0.0f;
    *(f32*)(identity + 0x10) = -direction[0] / direction[1];
    *(f32*)(identity + 0x14) = fGpffff80f0;
    *(f32*)(identity + 0x18) = -direction[2] / direction[1];
    *(f32*)(identity + 0x20) = 0.0f;
    *(f32*)(identity + 0x24) = 0.0f;
    *(f32*)(identity + 0x28) = 1.0f;
    *(f32*)(identity + 0x30) = 0.0f;
    *(f32*)(identity + 0x34) = 0.0f;
    *(f32*)(identity + 0x38) = 0.0f;
    *(u32*)(identity + 0x0C) |= 0x20003;

    func_003e05f0(&matrix0, (u8*)param_1 + 0x40, param_1);
    func_003e05f0(&matrix1, &matrix0, &identity);
    func_003e9cb0(*(void**)((u8*)*(u8**)((u8*)param_1 + 0xDC) + 4),
                  &matrix1, 0);
    if ((*(u16*)((u8*)param_1 + 0x140) & 0x4000) != 0) {
        func_00471370(*(void**)((u8*)param_1 + 0x10C),
                      (u8*)param_1 + 0xEC, (u8*)param_1 + 0x140,
                      &identity);
    } else {
        func_00397c40(*(void**)((u8*)param_1 + 0x10C));
    }
    renderStateSet = D_00887300_abs;
    renderStateSet[0](6, 1);
    renderStateSet[0](8, 0);
    D_00887304[0](0xE, &renderState);
    renderStateSet[0](0xE, 0);
    func_003f6440(2, 0x44);
    if ((*(u32*)((u8*)param_1 + 0xD8) & 0x80000) != 0) {
        func_004746b0((u8*)param_1 + 0x234, (u8*)param_1 + 0xEC);
    }
    func_00477260(*(void**)((u8*)param_1 + 0xDC), (u32*)color,
                        (u16)((((Mdl475Param*)param_1)->flags & 8) != 0));
    effect = (u8*)((Mdl475Param*)param_1)->e0;
    if (effect == 0) {
        func_003f6440(3, 0x7C01B);
    } else if ((*(s32*)(effect + 0x10) != 0 || *(s32*)(effect + 0x1C) != 0)
               && ((((Mdl475Param*)param_1)->flags & 0x80) == 0)) {
        func_003f6440(3, 0x7F06B);
    } else {
        func_003f6440(3, 0x7D7FB);
    }
    func_00479910(*(void**)((u8*)param_1 + 0xDC));
    func_004789c0(param_1);
    if ((*(u16*)((u8*)param_1 + 0xEC) & 0x10) != 0) {
        func_00473000(*(void**)((u8*)param_1 + 0x10C),
                      (u8*)param_1 + 0xEC);
    } else if ((*(u16*)((u8*)param_1 + 0x140) & 0x81E0) != 0) {
        func_00471370(*(void**)((u8*)param_1 + 0x10C),
                      (u8*)param_1 + 0xEC, (u8*)param_1 + 0x140, 0);
    } else {
        func_00397c40(*(void**)((u8*)param_1 + 0x10C));
    }
    effect = *(u8**)((u8*)param_1 + 0x2CC);
    if (effect != 0) {
        func_0047d900((u32)effect, (u8*)param_1 + 0x80);
        func_0047d540((u32)effect, param_1);
    }
    i = 0;
    while (i < 2) {
        model = *(u8**)((u8*)param_1 + i * 0xA4 + 0x124);
        if (model != 0) {
            effect = *(u8**)(model + 0x18);
            if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                func_0047d900((u32)effect, model + 8);
                func_0047d540((u32)effect, param_1);
            }
            effect = *(u8**)(model + 0x24);
            if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                func_0047dd40((u32)effect, param_1);
            }
            if (*(u16*)(model + 0x30) > 0) {
                *(u16*)(model + 0x30) -= 1;
            }
        }
        i++;
    }
    j = 0;
    while (j < 5) {
        slot = (u8*)param_1 + j * 0xC;
        if ((*(u8*)(slot + 0x28C) & 1) != 0 &&
            *(void**)(slot + 0x290) != 0 &&
            func_0047ae90(param_1, j) != 0) {
            model = *(u8**)(slot + 0x290);
            if (*(s32*)(slot + 0x294) != -1) {
                func_0047a510(param_1, *(s32*)(slot + 0x294),
                              func_0047a2f0(model));
            } else {
                copyCount = 8;
                copySource = (u32*)param_1;
                copyTarget = (u32*)model;
                do {
                    copyTarget[0] = copySource[0];
                    copyTarget[1] = copySource[1];
                    copySource += 2;
                    copyTarget += 2;
                    copyCount--;
                } while (copyCount > 0);
            }
            if ((*(u32*)(model + 0xD8) & 2) == 0 &&
                ((Mdl475Param*)param_1)->d3 != 0) {
                source = *(u8**)(model + 0xDC);
                material = *(u8**)(source + 4);
                func_003e05f0(&matrix0, model + 0x40, model);
                func_003e05f0(&matrix1, &matrix0, &identity);
                func_003e9cb0(material, &matrix1, 0);
                hasIndex = 0;
                hasItem = 0;
                needsReset = 0;
                animation = *(u8**)(model + 0x120);
                if (animation != 0 &&
                    *(s16*)(model + 0xF0) < *(u16*)(animation + 8)) {
                    hasIndex = 1;
                }
                if (hasIndex != 0 &&
                    *(void**)((u8*)*(void**)animation
                              + *(s16*)(model + 0xF0) * 0x50 + 0x40) != 0) {
                    hasItem = 1;
                }
                if (hasItem != 0 &&
                    *(void**)((u8*)*(void**)animation
                              + *(s16*)(model + 0xF0) * 0x50 + 0x40)
                        != (void*)D_00922BC0_abs) {
                    needsReset = 1;
                }
                if (needsReset != 0) {
                    func_00397c40(*(void**)(model + 0x10C));
                }
                if ((*(u32*)(model + 0xD8) & 0x80000) != 0) {
                    func_004746b0(model + 0x234, model + 0xEC);
                }
                func_00477260(*(void**)(model + 0xDC), (u32*)color,
                                    (u16)((*(u8*)(model + 0x260) & 8) != 0));
                effect = (u8*)((Mdl475Param*)param_1)->e0;
                if (effect == 0) {
                    func_003f6440(3, 0x7C01B);
                } else if (*(s32*)(effect + 0x10) != 0 ||
                           *(s32*)(effect + 0x1C) != 0) {
                    func_003f6440(3, 0x7F08B);
                } else {
                    func_003f6440(3, 0x7D7FB);
                }
                func_00479910(*(void**)(model + 0xDC));
                func_004789c0(model);
                if (needsReset != 0) {
                    func_00397c40(*(void**)(model + 0x10C));
                }
                effect = *(u8**)(model + 0x2CC);
                if (effect != 0) {
                    func_0047d900((u32)effect, model + 0x80);
                    func_0047d540((u32)effect, model);
                }
                k = 0;
                while (k < 2) {
                    effect = *(u8**)(model + k * 0xA4 + 0x124);
                    if (effect != 0) {
                        source = *(u8**)(effect + 0x18);
                        if (source != 0 && *(u16*)(effect + 0x30) == 0) {
                            func_0047d900((u32)source, effect + 8);
                            func_0047d540((u32)source, model);
                        }
                        source = *(u8**)(effect + 0x24);
                        if (source != 0 && *(u16*)(effect + 0x30) == 0) {
                            func_0047dd40((u32)source, model);
                        }
                        if (*(u16*)(effect + 0x30) > 0) {
                            *(u16*)(effect + 0x30) -= 1;
                        }
                    }
                    k++;
                }
            }
        }
        j++;
    }
    renderStateSet = D_00887300_abs;
    renderStateSet[0](0xE, renderState);
    func_003f6440(3, 0x717FB);
    renderStateSet[0](8, 1);
}
#undef renderState
#undef identity
#undef matrix1
#undef matrix0
#undef direction
#undef interpolation
#undef quaternion
#undef color

#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00475cd0);
#endif
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
extern void func_003f6440(s32 a, s32 b);
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

    func_003f6440(2, 0x64);
    if (!(o->d8 & 0x200) || (o->d8 & 0x400)) {
        func_003f6440(3, 0x7000F);
    } else if (*(u8*)((u8*)o + 0xD3) > 0xC8) {
        func_003f6440(3, 0x704FD);
    } else {
        func_003f6440(3, 0x7008D);
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
            if (func_003e8200(list, func_003bfae0_1(*(void**)((u8*)node + 0))) != 0) {
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

/* Retail reloads iGpffff8044 for each channel instead of holding it in one
 * register.  That reload used to be forced with `*(volatile f32*)&iGpffff8044`,
 * which reaches GUARDED_SCORE 0 on func_00476e90 - and is removed anyway,
 * because `volatile` on ordinary memory is a banned construct here: it is a
 * lie about the storage, and a body that depends on it is not a faithful
 * reconstruction however well it scores.
 * Measured replacements, all without volatile: `opt_common_subs off` 73,
 * `opt_common_subs on` 180, `opt_propagation on` 81, and dropping the `channel`
 * temporary 73.  `opt_common_subs off` is kept as a measured pair (73 against
 * 180); the remaining 73 is the honest floor until a non-volatile spelling of
 * the per-channel reload is found. */
#pragma push
#pragma always_inline on
#pragma opt_common_subs off
#pragma opt_propagation off

static inline void mdlColorToReal(MdlMaterialColorReal* out, const RwRGBA* color)
{
    f32 channel;
    channel = (f32)(u32)color->red;
    out->red = iGpffff8044 * channel;
    channel = (f32)(u32)color->green;
    out->green = iGpffff8044 * channel;
    channel = (f32)(u32)color->blue;
    out->blue = iGpffff8044 * channel;
    channel = (f32)(u32)color->alpha;
    out->alpha = iGpffff8044 * channel;
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

/* measured 00476e90 (owner, 2026-09-19): demoted from MATCH to a guarded NONMATCHING body,
   and the reason matters more than the loss.  It matched only because the four per-channel
   reads of iGpffff8044 were spelled `*(volatile f32*)&iGpffff8044`.  `volatile` on ordinary
   memory is a banned construct here - it is a lie about the storage - so it was removed,
   and the function stopped matching.  Leaving it unguarded would have left verify.py
   reporting MISMATCH, which is a false claim that the C reproduces retail; a guarded body
   over the INCLUDE_ASM says what is actually true.
   The residual is 73 differing words and it is NOT the float reloads - those still land on
   retail's `lwc1 $f0, -0x7fbc($gp)`.  It is register identity: `geometry` lands in $s0
   where retail holds it in $s1, and the packed colour round-trips through 0x8c-0x8f($sp)
   where retail stores straight to the material.
   Measured against the 73: ALL TWENTY-FOUR permutations of the four local declarations
   score exactly 73, so declaration order does not reach this allocation (consistent with
   handoff 7bf); quantising straight into `material->color` instead of through the `color`
   temporary is 147, twice as bad.  Earlier, without volatile: `opt_common_subs off` 73,
   `opt_common_subs on` 180, `opt_propagation on` 81, dropping the `channel` temporary 73. */
// FUN_00476E90 NONMATCHING
#ifdef NON_MATCHING
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
#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00476e90);
#endif
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
        if ((func_00399d80(e) & 2) != 0) {
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
        if ((func_00399d80(e) & 2) != 0) {
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
        if (func_00457a90(item, D_00713180) != 0 &&
            func_00457a90(item, D_007131A0) != 0 &&
            func_00457a90(item, D_007131C0) != 0) {
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
    extern s32 func_00442948(s32 value);
    extern s32 func_00442c30(s32 a, s32 b, s32 c);
    extern u32 func_004578b0(void* object, void* name);
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
    temp_17 = func_00442948(*(s32 *)(pArg1 + 4));
    var_18 = 0;
    while (var_18 < temp_22) {
        temp_19 = (u8*)*(u32*)(*(u8 **)(temp_16 + 0x20) + var_18 * 4);
        if (func_00442c30(*(s32 *)(pArg1 + 4), (s32)func_00474ce0(temp_19), temp_17) == 0) {
            value = func_004578b0(temp_19, D_00713160);
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
   order (removing it rotates/reorders them, nd 9) and the K&R parameter
   definition keeps the file's heterogeneous 0-arg and void*-arg callers
   compiling. */
// FUN_004779B0
void* func_004779b0(type, id)
    u16 type;
    u16 id;
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
    func_0043f9c8(obj, 0, 0x320);
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
    func_0043f9c8(obj + 0x258, 0, 8);
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
    head = &D_00922BE0[type];
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
void* func_00477c40(u32 param_1, u32 param_2, u32 param_3)
{
    void* node = D_00922BE0[param_1 & 0xFFFF];
    u32 v1 = param_2 & 0xFFFF;
    u32 v2 = param_3 & 0xFFFF;
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
void* func_00477e80(void* param_1, void* param_2, void* param_3, u32 param_4)
{
    void* obj = func_004779b0();
    if ((param_4 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    func_0047aff0(obj, param_3);
    func_004782b0(obj);
    return obj;
}

// FUN_00477F10
void* func_00477f10(void* param_1, void* param_2, int param_3, int param_4, u32 param_5)
{
    void* obj = func_004779b0();
    if ((param_5 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    {
        int tmp[2];
        tmp[0] = param_3;
        tmp[1] = param_4;
        func_0047afd0(obj, tmp);
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
void* func_00477fb0(void* arg0, void* arg1, void* arg2, u32 arg3)
{
    extern s32 func_0047d0e0(void);
    extern u8* func_00455ea0(u8*, s32, s32*);
    extern void* func_004779b0(void*, void*);
    extern void func_0047e450(void*, void*, void*, void*, u32);
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

    if (func_0047d0e0() == 0) {
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
    func_0047e450((u8*)obj + 0x2D0, arg0, arg1, (void*)retB, stack9c);
    result = obj;
done:
    return result;
}

// FUN_00478140
void* func_00478140(u32 param_1, u32 param_2, u32 param_3)
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
        func_0047d110(param_1, param_2, buf);
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
    s32 size = sizeof(MdlCloneAttachmentTable);
    MdlCloneAttachmentTable* copy;
    size += count * sizeof(void*);
    size += count * sizeof(void*);
    func_0044ea90(D_00713138, 0x1d6);
    copy = ((void* (*)(int, int))DAT_008873e8[0])(size, 0x40000);
    func_0043f9c8(copy, 0, size);
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
    void* func_004779b0(u16, u16);
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
extern void* func_0047a2f0(void* a);
extern void func_0047dae0(u32 a);
extern void func_0047de50(u32 a);
extern void func_0047de00(u32 a, void* b);
extern void func_0047dd40(u32 a, void* b);
extern void func_0047d900(u32 a, void* b);
extern void func_0047d540(u32 a, void* b);
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
                func_0047d900((u32)draw, &((Model*)mdl)->scale);
                func_0047d540(*(u32*)(mdl + 0x2CC), mdl);
            }
            for (updateLayer = 0; updateLayer < 2; updateLayer++) {
                attachments = ((MdlCloneLayerView*)(mdl + updateLayer * 0xA4 + 0xEC))->attachments;
                if (attachments != 0) {
                    draw = attachments->primaryDraw;
                    if (draw != 0 && attachments->delay == 0) {
                        func_0047d900((u32)draw, &attachments->scale);
                        func_0047d540((u32)attachments->primaryDraw, mdl);
                    }
                    draw = attachments->secondaryDraw;
                    if (draw != 0 && attachments->delay == 0) {
                        func_0047dd40((u32)draw, mdl);
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
                            void* childMatrix = func_0047a2f0(*childSlot);
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

/* measured cold479100+4: sanitized m2c (K&R->ANSI) 187 lines COP2 M2C_ERROR; k_draw raw idiom (Model/RwRGBA/MdlCloneLayer/MdlWpnSlot, no new struct). Gap 477/477. R3: blez<=0 29 (adopts opcode), noCSE 414, nopragma 414, CSEonly 246, volatile 29. R4 widths via casts: ae90-narrow 101, wide-cast 99, loaded-u32 29, d7e0-u32 29, child-u16 31 (empty () correct, no andi). R5: reorder 36, layer-s32 172, uncolored/flags-s32 29, void-cmd COMPILE ERROR (u8* required). R6 floats: alpha-first 135, merged-alpha 80, signed-300 29, perchan-literal 190, hoisted-inv 309 (separate lifetimes/order correct). fnalign 477/477 15+18; resid 0x48c-0x500 3x mtc1/nop + addiu shift + blez-offset/jal at 0x4f4. Best 29. Archive COLD_00479100_body.c. Production ASM. */
/* 2026-09-18 probe; floor stands at 29.  The residual is three extra
   `mtc1 $zero, $fN` + `nop` pairs this body emits around instruction 291-309
   and one `addiu $a1, $sp, 0x6c` issued a slot early.  They are NOT the
   unsigned-conversion idiom: the `(f32)(u32)` casts on the colour bytes are
   retail's shape, and weakening them is a large regression - all eight to
   `(f32)(s32)` costs 312, the three `model[0x300..0x302]` ones 255, the four
   `color.*` ones 314, and `model[0x303]` alone 202.  Leave them alone.  The
   zero materialisations are the FPU accumulator prime described in handoff
   7r, and aligning instructions 272-300 says exactly what the difference is:
   both bodies are identical through instruction 283, where each primes
   `mtc1 $zero, $f3` before the first channel's `adda.s`/`madd.s` pair.
   Retail then keeps that zeroed register live and reuses it for the other
   three channels; this body re-primes into $f2, $f1 and $f0.  So it is not
   the expression shape - `a * b + c` always costs the prime, and no spelling
   avoids it (7r measures six).  It is whether the allocator keeps one zero
   live across the four conversions.  Measured and not moved: writing the
   products first, `maximum * red + bias`, ties at 29; computing the four
   floats into temporaries and converting afterwards costs 31; an explicit
   shared `f32 zero` local costs 196.  Treat as constant-rematerialisation
   colouring unless someone finds a source form that pins the zero.
   Micro-test lead: the same four lines in isolation prime `mtc1 $zero` once
   and reuse it, so the re-prime inside this function is register pressure,
   not expression shape — fewer simultaneously live values across the four
   channels, a tighter scope around each, or letting one value die before the
   next is born should keep $f3 live. */
// FUN_00479100 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
/* IDA mdlManager.c:2696-2870; retail 00479100-00479870.
 * Integration requirements, including attachment fields and the corrected
 * color-forwarding wrapper, are recorded in IDA_model_followthrough.json. */
/* Queue command uses k_draw.c raw offsets (obj+8/0x0C/0x10/0x14/0x18/0x1A/0x1C); no new struct. */

extern u8* func_00460990(void);
extern void func_00460ac0(void*, void*);
extern void func_00478a30(u8*, s32);
extern void func_00479030(u8*, u8*);
extern void func_0047d8a0(u8**, s32);
extern void func_0047d7e0(s32, u8**);
extern void func_0047ddd0(u8*, const u8*);
extern void func_0047dd70(u8*, u8*);
extern void func_0047a220(void*, void*);

void func_00479100(void* queue, u8* model)
{
    u8* command;
    u8* renderCommand;
    u32 flags;
    u16 layer;
    s32 childIndex;
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
    if (((Model*)model)->color.alpha <= 0)
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
            f32 red;
            f32 green;
            f32 blue;
            f32 alpha;
            f32 modulatedAlpha;
            f32 maximum;
            f32 bias;
            red = iGpffff8044 * (f32)(u32)((Model*)model)->color.red;
            green = iGpffff8044 * (f32)(u32)((Model*)model)->color.green;
            blue = iGpffff8044 * (f32)(u32)((Model*)model)->color.blue;
            alpha = iGpffff8044 * (f32)(u32)((Model*)model)->color.alpha;
            red *= iGpffff8044 * (f32)(u32)model[0x300];
            green *= iGpffff8044 * (f32)(u32)model[0x301];
            blue *= iGpffff8044 * (f32)(u32)model[0x302];
            modulatedAlpha = alpha * (iGpffff8044 * (f32)(u32)model[0x303]);
            maximum = 255.0f;
            bias = 0.5f;
            color.red = (s32)(bias + maximum * red);
            color.green = (s32)(bias + maximum * green);
            color.blue = (s32)(bias + maximum * blue);
            color.alpha = (s32)(bias + maximum * modulatedAlpha);
            func_0047d8a0(*(u8***)(model + 0x2cc), (s32)&color);
            if (color.alpha <= 0)
                goto layers;
        }
        func_0047d7e0(*(s32*)(model + 0x2fc), *(u8***)(model + 0x2cc));
    }

layers:
    for (layer = 0; layer < 2; ++layer)
    {
        MdlCloneAttachmentTable** slot = &((MdlCloneLayerView*)(model + 0xec + layer * 0xa4))->attachments;
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
                func_0047d8a0(draw, (s32)&attachments->color);
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
    for (childIndex = 0; (u16)childIndex < 5; childIndex = (u16)(childIndex + 1))
    {
        s32 index = (u16)childIndex;
        u8* childBase = model + index * sizeof(MdlWpnSlot);
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
                func_0047a220(*child, &((Model*)model)->color);
                if ((*(u32*)(model + 0xd8) & 0x20) == 0)
                    *(u32*)((u8*)*child + 0xd8) &= ~0x20u;
                else
                    *(u32*)((u8*)*child + 0xd8) |= 0x20;
                func_00479100(queue, *child);
            }
        }
    }
}

#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479100);
#endif

// FUN_00479880
void* func_00479880(void* param_1, void* data)
{
    if ((*(u8*)((u8*)param_1 + 2) & 4) == 0) {
        return param_1;
    }
    if (*(void**)((u8*)param_1 + 0x18) != 0) {
        if (func_003e8200(D_008872E0[0], func_003bfae0()) != 0) {
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
    s32 i;
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
        for (i = 0; (s64)(u16)i < 5; i = (u16)(i + 1)) {
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
    func_003e0870((struct RwMatrixTag *)matrix, (const RwV3d *)axis,
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
    s32 i;
    s32 elemOff;
    list = *(void**)((u8*)arg0 + 0x120);
    if (list != (void*)0) {
        idx = *(s16*)((u8*)arg0 + 0xF0);
        if (idx < *(u16*)((u8*)list + 8)) {
            elemOff = (s32)idx * 0x50;
            item = *(void**)((u32)((u32)*(s32*)list + 0x40) + (u32)elemOff);
            if (item != (void*)0 && item != (void*)D_00922BC0_abs) {
                { extern void func_00397c40(); func_00397c40(*(void**)((u8*)arg0 + 0x10C)); }
                i = 0;
                while ((i & 0xFFFF) < 5) {
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
                                    func_00397c40(*(void**)((u8*)wpn + 0x10C), wpn);
                                }
                            }
                        }
                    }
                    i = (i + 1) & 0xFFFF;
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
            func_003e05f0(dst, &entry->matrix, func_003e9700(temp));
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
void func_0047aaa0(void* param_1, s32 param_2, void* param_3, void* param_4, void* param_5, u32 param_6)
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
void func_0047ab90(void* param_1, s32 param_2, void* param_3, void* param_4, void* param_5, void* param_6, u32 param_7)
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
        tmp[0] = (s32)param_5;
        tmp[1] = (s32)param_6;
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
void func_0047ac90(void* param_1, u32 param_2, void* param_3, void* param_4, u32 param_5)
{
    void* obj;
    void* result;
    u8 buf[0x100];
    u32 off;
    void* slot;

    if (func_00477c40((u32)param_3, (u32)param_4, 0) == (void*)0) {
        func_0047d110(param_3, param_4, buf);
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
    func_0043f9c8(obj, 0, 0x48);
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

/* measured: 1 transcription attempt (nd 1237 of 0x15A0). The whole
   switch-driven resource-loader is transcribed (cases 0x10/0x16/0x1B/0x23/
   0x2B + the 0xF0F000xx family, the 0x30C slot table, 0x254/0x234/0x2CC
   alloc blocks, the 8-word copy, 0x124/0x14/0x20 slot tables, func_004667d0
   10-arg calls with (s64)&D_0070B610). Residual: b210's switch emits a
   linear beq chain in source order with the case bodies INLINE where retail
   uses the jump-table shape with bodies out of line (the m2c's "irregular"
   switch - needs the mwccps2-switch-linear-chain-declaration-order levers),
   plus the usual saved-register rotation across the ~30 temp loads. Verified
   call shapes for retry: func_00397c40-style 1-arg sites use func_003e2ce0
   (always 1-arg); func_00463100 is (void*); func_0047f9f0 returns u32;
   func_004800d0 is s32(void*,u8**,u32,void*); func_003d60e0 (void*,s32);
   func_0047d200/7dc30 return void* (cast to s32); jtbl_008873E8 =
   (void* (*)(int,int))DAT_008873e8[0]; D_0070B610 is an u8 extern; mwcc C89
   rejects void*+int - cast derefs to u8* first. Switch-layout +
   register-rotation floor. */
/* measured 0047b0c0 R2: object 1350/retail 1380 (-30, -2.2% INSIDE +-3% gate, 41 allowed); fnalign 2135 edits+2 reloc-only; words 1269. Fix: 11x func_0044ea90(void)->(D_00713138,imm) with retail imms 0x125,0xfa,0x1d6,0x1d6,0xc93,0x18c5,0x18b7,0x850,0x1896,0x1834,0x908 + prototype (void*,int); lui -13->-2, addiu -18->+4, delete 181:182 gone. Remaining: switch inline vs out-of-line (478 delete artifact) + spare $s6/$s7 + lw -27/beq -23. Production guarded, fallback INCLUDE_ASM retained. */
/* measured 0047b0c0 R3 (2026-09-19, OR-as-fallthrough + global-asc switch): object 1359/retail 1380 (-21, -1.5% INSIDE +-3% gate, 41 allowed); fnalign 1539 edits+12 reloc-only (was 2135+2); words 1279 (was 1269). Spellings: chain (08||07) 2135, chain (07||08) 2135 (tie); switch source-order asc 2054, desc 2054 (tie), 8083src 2054 (tie), global-desc 2054; switch global-asc 1539 (-596 vs chain, -515 vs source-order). Tail: before struct 70 reg 6, after struct 154 reg 35 (old 478-delete splits into body-order hunks; largest retail[821:968]/object[1022:1027] 147v5). Remaining: frame 0xb0 vs 0xd0 + spare s-regs, compares source-order vs descending. Production guarded, fallback retained. */
/* measured 0047b0c0 R4 (2026-09-20, deficit-shape fixes): object 1367/retail 1380 (-13, -0.9% INSIDE +-3% gate, 41 allowed); fnalign 1530 edits+12 reloc-only (was 1539+12); frame 0xc0 (was 0xb0, retail 0xd0). Fixes: 3x func_004667d0 8->10 args (2 trailing zeros, sd+6 gone, +6 instrs, per sdkSpr/k_fldResource 10-arg prototype); temp_v5 unsigned->int (sltiu->slti, sltu->slt, retail signed); 2x func_003ef260 0x463100->func_00463100 + 2x 0x70b610->&D_0070B610 (reloc-correct, per effObjectParticle/k_clumpInstance/003d60e0 &D_ usage); loop masks 06/D0/03 compare+index (temp&0xFFFF) + E0/E1 header (temp_v2&0xFFFF) (andi 6->3, lhu 8->6); case 02/04 short->unsigned short (lh->lhu, retail lhu). Remaining: 147 at 0x0047bd94 + 130 at 0x0047c3d4 (switch body order: retail reverse-dispatch layout vs global-asc jump table) + 65 at 0x0047b494 (2B stack home), lw+27/lhu+6/addu+6/sw+5/subu+5/beqz+5 (retail stack-reload vs object reg-cache for uStack_4c/uStack_2). Production guarded, fallback retained. */
// FUN_0047B0C0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0047b0c0(u8 *arg0)
{
    extern unsigned int func_003c0f20(int);
    extern unsigned int func_003d53c0(int);
    extern unsigned int func_003d6350(unsigned int, int);
    extern unsigned int func_003dc370(int);
    extern unsigned int func_003e6a90(int);
    extern unsigned int func_0047d200(void);
    extern unsigned int func_0047d320(unsigned int, int, unsigned int, unsigned short, unsigned int);
    extern unsigned int func_0047db50(int, unsigned int);
    extern unsigned int func_0047dc30(void);
    extern unsigned int func_0047f9f0(void);
    extern unsigned int func_003d60e0(unsigned int, unsigned int);
    extern void func_0044ea90(void *a, int b);
    extern unsigned char * func_00470e90(unsigned short);
    extern void func_00477810(void *, void *);
    extern unsigned int func_0047d1a0(void);
    extern int func_004800d0(void *, unsigned char **, unsigned int, void *);
    extern s32 func_003df3c0();
    extern s32 func_003e2910();
    extern s32 func_003e2ce0();
    extern s32 func_003e2f60();
    extern s32 func_003ef1b0();
    extern s32 func_003ef260();
    extern s32 func_0043f9c8();
    extern s32 func_004667d0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_00463100(void *);
    extern u8 D_0070B610;
    extern s32 func_0047d460();
/* irregular: 10 native warning(s); review required */
  unsigned short temp_v0;
  int *piVar2;
  unsigned int temp_v1;
  unsigned short temp_v2;
  int temp_v3;
  unsigned char *pbVar6;
  unsigned int temp_v4;
  int temp_v5;
  unsigned int *puVar9;
  int temp_v6;
  u32 temp_v7;
  long temp_v8;
  unsigned int *puVar13;
  unsigned int *puVar14;
  int temp_v9;
  unsigned short *puVar16;
  int *piVar17;
  unsigned int uStack_50;
  unsigned int uStack_4c;
  unsigned short uStack_30;
  unsigned short uStack_2e;
  unsigned int uStack_2c;
  unsigned int uStack_28;
  unsigned int uStack_24;
  int iStack_18;
  int iStack_14;
  int uStack_c;
  unsigned short uStack_6;
  unsigned short uStack_4;
  unsigned short uStack_2;
  
  piVar2 = *(int **)((int)arg0 + 0x30c);
  uStack_2 = 0x20;
  for (temp_v5 = 0; temp_v5 < 2; temp_v5 = (temp_v5 + 1) & 0xffff) {
    *(unsigned short *)((int)piVar2 + temp_v5 * 2 + 0x20) = 0x20;
  }
  while ((temp_v8 = func_003df3c0(*piVar2,&uStack_50), temp_v2 = uStack_2, temp_v8 != 0 &&
         (uStack_50 != 0))) {
    switch (uStack_50) {
    case 0x10:
        if ((*(unsigned int *)((int)arg0 + 0xd8) & 0x4000) == 0) {
          if (((*(int *)((int)arg0 + 0xdc) == 0) && (piVar2[5] == 0)) && (piVar2[4] == 0)) {
            iStack_18 = piVar2[0xb] + *(int *)(*piVar2 + 0xc);
            iStack_14 = piVar2[0xc] - *(int *)(*piVar2 + 0xc);
            temp_v3 = func_003e2f60(3,1,&iStack_18);
            piVar2[5] = temp_v3;
          }
          func_003e2ce0(*piVar2,uStack_4c);
        }
        else if (*(int *)((int)arg0 + 0xdc) == 0) {
          temp_v4 = func_003c0f20(*piVar2);
          *(unsigned int *)((int)arg0 + 0xdc) = temp_v4;
        }
      break;
    case 0x16:
        if ((*(unsigned int *)((int)arg0 + 0xd8) & 0x4000) == 0) {
          iStack_18 = piVar2[0xb] + *(int *)(*piVar2 + 0xc);
          iStack_14 = piVar2[0xc] - *(int *)(*piVar2 + 0xc);
          temp_v7 = func_003e2f60(3,1,&iStack_18);
          temp_v3 = func_004667d0(8,0,0,0,temp_v7,0,0,0,0,0);
          piVar2[1] = temp_v3;
          func_003e2ce0(*piVar2,uStack_4c);
        }
        else {
          temp_v7 = func_003e6a90(*piVar2);
          func_003ef260(temp_v7,func_00463100,piVar2 + 0xd);
          func_003ef1b0(temp_v7);
        }
      break;
    case 0x1b:
        if (*(int *)((int)arg0 +
                    ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 +
                    0x120) == 0) {
          pbVar6 = func_00470e90(uStack_2);
          *(unsigned char **)((int)arg0 +
                    ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 +
                    0x120) = pbVar6;
        }
        temp_v4 = func_003d53c0(*piVar2);
        if ((piVar2[0x11] == 0) ||
           (temp_v3 = *(int *)((int)arg0 +
                            ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) *
                            4 + 0x120), *(int *)(temp_v3 + 4) != 0)) {
          *(unsigned int *)
           (**(int **)((int)arg0 +
                      ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 +
                      0x120) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50 + 0x40) = temp_v4;
        }
        else {
          *(unsigned int *)(temp_v3 + 4) = temp_v4;
        }
      break;
    case 0x1e:
      break;
    case 0x23:
        temp_v7 = func_003dc370(*piVar2);
        func_003ef260(temp_v7,func_00463100,piVar2 + 0xd);
        func_003ef1b0(temp_v7);
      break;
    case 0x2b:
        if ((*(unsigned int *)((int)arg0 + 0xd8) & 0x4000) == 0) {
          if ((piVar2[5] == 0) && (piVar2[4] == 0)) {
            iStack_18 = piVar2[0xb] + *(int *)(*piVar2 + 0xc);
            iStack_14 = piVar2[0xc] - *(int *)(*piVar2 + 0xc);
            temp_v7 = func_003e2f60(3,1,&iStack_18);
            temp_v3 = func_004667d0(7,0,0,0,temp_v7,0,0,0,0,0);
            piVar2[2] = temp_v3;
          }
          else {
            if (piVar2[3] == 0) {
              func_0044ea90(D_00713138, 0x1834);
              temp_v7 = (u32)((void*(*)(int,int))DAT_008873e8[0])((unsigned int)uStack_2 << 2,0x40000);
              piVar2[3] = (int)temp_v7;
              func_0043f9c8(temp_v7,0,(unsigned int)uStack_2 << 2);
            }
            iStack_18 = piVar2[0xb] + *(int *)(*piVar2 + 0xc);
            iStack_14 = piVar2[0xc] - *(int *)(*piVar2 + 0xc);
            temp_v7 = func_003e2f60(3,1,&iStack_18);
            temp_v4 = func_004667d0(7,0,0,0,temp_v7,0,0,0,0,0);
            *(unsigned int *)(piVar2[3] + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 4) = temp_v4;
          }
          func_003e2ce0(*piVar2,uStack_4c);
        }
        else {
          if (*(int *)((int)arg0 + 0x254) == 0) {
            temp_v3 = (unsigned int)uStack_2 * 8 + 0x10;
            func_0044ea90(D_00713138, 0x908);
            temp_v7 = (u32)((void*(*)(int,int))DAT_008873e8[0])(temp_v3,0x40000);
            func_0043f9c8(temp_v7,0,temp_v3);
            piVar17 = (int *)temp_v7;
            *piVar17 = (int)(piVar17 + 4);
            *(unsigned short *)(piVar17 + 3) = temp_v2;
            *(unsigned short *)((int)piVar17 + 0xe) = 1;
            *(int **)((int)arg0 + 0x254) = piVar17;
          }
          temp_v5 = func_003d6350((u32)&D_0070B610,*piVar2);
          if (*(int *)((int)arg0 + 0xdc) == 0) {
            *(unsigned int *)(*(int *)((int)arg0 + 0x254) + 4) = temp_v5;
            func_003d60e0((u32)&D_0070B610,temp_v5);
          }
          else {
            *(unsigned int *)(**(int **)((int)arg0 + 0x254) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 8)
                 = temp_v5;
          }
        }
      break;
    case 0xf0f00001:
      if (*(int *)((int)arg0 +
                  ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x120
                  ) == 0) {
        pbVar6 = func_00470e90(uStack_2);
        *(unsigned char **)((int)arg0 +
                  ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x120
                  ) = pbVar6;
      }
      *(void**)(**(int **)((int)arg0 +
                           ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) *
                           4 + 0x120) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50 + 0x40) = (void*)&D_00922BC0;
      func_003e2ce0(*piVar2,uStack_4c);
      break;
    case 0xf0f00002:
      *(unsigned short *)(piVar2 + 7) = *(unsigned short *)(piVar2 + 7) + 1;
      *(unsigned short *)((int)piVar2 + 0x1e) = 0;
      func_003e2ce0(*piVar2,uStack_4c);
      break;
    case 0xf0f00003:
      if ((*(unsigned int *)((int)arg0 + 0xd8) & 0x4000) == 0) {
        func_003e2910(*piVar2,&uStack_4,uStack_4c);
        if (piVar2[*(unsigned short *)(piVar2 + 7) + 9] == 0) {
          func_0044ea90(D_00713138, 0x1896);
          temp_v3 = (u32)((void*(*)(int,int))DAT_008873e8[0])((unsigned int)uStack_2 << 1,0x40000);
          piVar2[*(unsigned short *)(piVar2 + 7) + 9] = temp_v3;
          for (temp_v5 = 0; (temp_v5 & 0xffff) < (int)uStack_2; temp_v5 = (temp_v5 + 1) & 0xffff) {
            *(unsigned short *)(piVar2[*(unsigned short *)(piVar2 + 7) + 9] + (temp_v5 & 0xffff) * 2) = 0xffff;
          }
        }
        *(unsigned short *)(piVar2[*(unsigned short *)(piVar2 + 7) + 9] + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 2)
             = uStack_4;
      }
      else {
        func_003e2910(*piVar2,&uStack_4,uStack_4c);
        temp_v2 = uStack_4;
        piVar17 = *(int **)((int)arg0 +
                           ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) *
                           4 + 0x120);
        temp_v9 = (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50;
        puVar14 = (unsigned int *)(*piVar17 + (unsigned int)uStack_4 * 0x50);
        puVar13 = (unsigned int *)(*piVar17 + temp_v9);
        temp_v3 = 8;
        do {
          temp_v4 = *puVar14;
          temp_v1 = puVar14[1];
          puVar14 = puVar14 + 2;
          temp_v3 = temp_v3 - 1;
          *puVar13 = temp_v4;
          puVar13[1] = temp_v1;
          puVar13 = puVar13 + 2;
        } while (0 < temp_v3);
        temp_v3 = *piVar17;
        if (*(int *)(temp_v3 + (unsigned int)uStack_4 * 0x50 + 0x40) != 0) {
          *(unsigned int *)(temp_v3 + temp_v9 + 0x40) =
               *(unsigned int *)(temp_v3 + (unsigned int)uStack_4 * 0x50 + 0x40);
        }
        *(unsigned int *)(*piVar17 + temp_v9 + 0x44) = *(unsigned int *)(*piVar17 + temp_v9 + 0x44) | 1;
        piVar17 = *(int **)((int)arg0 + 0x234);
        if ((piVar17 != (int *)0x0) && (uStack_4 < *(unsigned short *)(piVar17 + 1))) {
          temp_v3 = *(int *)(*piVar17 + (unsigned int)uStack_4 * 8);
          if (temp_v3 != 0) {
            temp_v9 = (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 8;
            *(int *)(*piVar17 + temp_v9) = temp_v3;
            temp_v9 = *piVar17 + temp_v9;
            *(unsigned char *)(temp_v9 + 4) = *(unsigned char *)(temp_v9 + 4) | 1;
          }
        }
        piVar17 = *(int **)((int)arg0 + 0x254);
        if ((piVar17 != (int *)0x0) && (uStack_4 < *(unsigned short *)(piVar17 + 3))) {
          temp_v3 = *(int *)(*piVar17 + (unsigned int)uStack_4 * 8);
          if (temp_v3 != 0) {
            temp_v9 = (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 8;
            *(int *)(*piVar17 + temp_v9) = temp_v3;
            temp_v9 = *piVar17 + temp_v9;
            *(unsigned char *)(temp_v9 + 4) = *(unsigned char *)(temp_v9 + 4) | 1;
          }
        }
        temp_v3 = *(int *)((int)arg0 +
                        ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 +
                        0x124);
        if (temp_v3 != 0) {
          temp_v0 = *(unsigned short *)((int)piVar2 + 0x1e);
          if (*(int *)(*(int *)(temp_v3 + 0x14) + (unsigned int)uStack_4 * 4) != 0) {
            temp_v4 = func_0047d200();
            *(unsigned int *)(*(int *)(temp_v3 + 0x14) + (unsigned int)temp_v0 * 4) = temp_v4;
          }
          if (*(int *)(*(int *)(temp_v3 + 0x20) + (unsigned int)temp_v2 * 4) != 0) {
            temp_v4 = func_0047dc30();
            *(unsigned int *)(*(int *)(temp_v3 + 0x20) + (unsigned int)temp_v0 * 4) = temp_v4;
          }
        }
      }
      break;
    case 0xf0f00004:
      *(unsigned short *)((int)piVar2 + 0x1e) = *(unsigned short *)((int)piVar2 + 0x1e) + 1;
      func_003e2ce0(*piVar2,uStack_4c);
      break;
    case 0xf0f00005:
      if (*(int *)((int)arg0 +
                  ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x120
                  ) == 0) {
        pbVar6 = func_00470e90(uStack_2);
        *(unsigned char **)((int)arg0 +
                  ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x120
                  ) = pbVar6;
      }
      func_003e2910(*piVar2,**(int **)((int)arg0 +
                                     ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 +
                                     (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x120) +
                           (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50,uStack_4c);
      break;
    case 0xf0f00006:
      temp_v3 = *piVar2;
      func_003e2910(temp_v3,&uStack_6,2);
      temp_v5 = (unsigned int)uStack_6;
      func_0044ea90(D_00713138, 0xc93);
      temp_v9 = (int)((void*(*)(int,int))DAT_008873e8[0])(temp_v5 * 0x50 + 8,0x40000);
      puVar16 = (unsigned short *)(temp_v9 + (unsigned int)uStack_6 * 0x50);
      *puVar16 = uStack_6;
      puVar16[1] = 1;
      *(int *)(puVar16 + 2) = temp_v9;
      for (temp_v5 = 0; (temp_v5 & 0xffff) < (int)uStack_6; temp_v5 = (temp_v5 + 1) & 0xffff) {
        temp_v9 = (temp_v5 & 0xffff) * 0x50;
        func_003e2910(temp_v3,*(int *)(puVar16 + 2) + temp_v9 + 0x40,4);
        func_003e2910(temp_v3,*(int *)(puVar16 + 2) + temp_v9 + 0x44,4);
        func_003e2910(temp_v3,*(int *)(puVar16 + 2) + temp_v9,0x40);
      }
      *(unsigned short **)((int)arg0 + 0x2c8) = puVar16;
      break;
    case 0xf0f00007:
    case 0xf0f00008:
      func_003e2910(*piVar2,&uStack_c,uStack_4c);
      if (*(int *)(**(int **)((int)arg0 +
                             ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7))
                             * 4 + 0x120) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50 + 0x4c) ==
          0) {
        func_0044ea90(D_00713138, 0x125);
        temp_v7 = (u32)((void*(*)(int,int))DAT_008873e8[0])(8,0x40000);
        func_0043f9c8(temp_v7,0,8);
        *(int *)(**(int **)((int)arg0 +
                           ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) *
                           4 + 0x120) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50 + 0x4c) =
             (int)temp_v7;
      }
      if (uStack_50 == 0xf0f00007) {
        **(unsigned int **)
          (**(int **)((int)arg0 +
                     ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 +
                     0x120) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50 + 0x4c) = uStack_c;
      }
      else {
        *(unsigned int *)
         (*(int *)(**(int **)((int)arg0 +
                             ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7))
                             * 4 + 0x120) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50 + 0x4c) + 4
         ) = uStack_c;
      }
      break;
    case 0xf0f00009:
      piVar2[0x11] = 1;
      func_003e2ce0(*piVar2,uStack_4c);
      break;
    case 0xf0f00070:
      func_0044ea90(D_00713138, 0x18c5);
      temp_v7 = (u32)((void*(*)(int,int))DAT_008873e8[0])(0x2b8,0x40000);
      func_003e2910(*piVar2,temp_v7,uStack_4c);
      func_00477810(arg0,(void *)temp_v7);
      DAT_008873ec[0](temp_v7);
      break;
    case 0xf0f00080:
    case 0xf0f00081:
    case 0xf0f00082:
    case 0xf0f00083:
      if ((*(unsigned int *)((int)arg0 + 0xd8) & 0x4000) == 0) {
        func_0044ea90(D_00713138, 0x18b7);
        puVar9 = (unsigned int *)((void*(*)(int,int))DAT_008873e8[0])(0x10,0x40000);
        iStack_18 = piVar2[0xb] + *(int *)(*piVar2 + 0xc);
        iStack_14 = piVar2[0xc] - *(int *)(*piVar2 + 0xc);
        *puVar9 = uStack_50;
        *(unsigned short *)(puVar9 + 1) = *(unsigned short *)((int)piVar2 + 0x1e);
        temp_v5 = func_003e2f60(3,1,&iStack_18);
        puVar9[2] = temp_v5;
        func_003e2ce0(*piVar2,uStack_4c);
        puVar9[3] = piVar2[6];
        piVar2[6] = (int)puVar9;
      }
      else {
        if (*(int *)((int)arg0 + 0x234) == 0) {
          temp_v3 = (unsigned int)uStack_2 * 8 + 8;
          func_0044ea90(D_00713138, 0x850);
          temp_v7 = (u32)((void*(*)(int,int))DAT_008873e8[0])(temp_v3,0x40000);
          func_0043f9c8(temp_v7,0,temp_v3);
          piVar17 = (int *)temp_v7;
          *piVar17 = (int)(piVar17 + 2);
          *(unsigned short *)(piVar17 + 1) = temp_v2;
          *(unsigned short *)((int)piVar17 + 6) = 1;
          *(int **)((int)arg0 + 0x234) = piVar17;
        }
        if (*(int *)(**(int **)((int)arg0 + 0x234) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 8)
            == 0) {
          temp_v4 = func_0047f9f0();
          *(unsigned int *)
           (**(int **)((int)arg0 + 0x234) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 8) = temp_v4;
        }
        func_004800d0((void *)*piVar2,
                      *(unsigned char ***)
                       (**(int **)((int)arg0 + 0x234) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 8
                       ),uStack_50,*(void **)((int)arg0 + 0xdc));
      }
      break;
    case 0xf0f000d0:
      func_0044ea90(D_00713138, 0xfa);
      temp_v7 = (u32)((void*(*)(int,int))DAT_008873e8[0])(0x4c,0x40000);
      func_0043f9c8(temp_v7,0,0x4c);
      temp_v3 = (int)temp_v7;
      *(unsigned int *)(temp_v3 + 0x30) = 0x3f800000;
      *(unsigned int *)(temp_v3 + 0x38) = 0x3f800000;
      *(int *)(**(int **)((int)arg0 +
                         ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4
                         + 0x120) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50 + 0x48) = temp_v3;
      func_003e2910(*piVar2,*(int *)(**(int **)((int)arg0 +
                                              ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 +
                                              (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x120) +
                                    (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50 + 0x48) + 0x3c,
                   uStack_4c);
      for (temp_v5 = 0; (temp_v5 & 0xffff) < 4; temp_v5 = (temp_v5 + 1) & 0xffff) {
        func_003df3c0(*piVar2,&uStack_50);
        temp_v4 = func_003d53c0(*piVar2);
        *(unsigned int *)
         (*(int *)(**(int **)((int)arg0 +
                             ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7))
                             * 4 + 0x120) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 0x50 + 0x48) +
         (temp_v5 & 0xffff) * 4) = temp_v4;
      }
      break;
    case 0xf0f000e0:
      func_003e2910(*piVar2,&uStack_30,0x14);
      func_003e2ce0(*piVar2,uStack_28);
      temp_v2 = uStack_2;
      temp_v3 = piVar2[0xb];
      temp_v9 = *(int *)(*piVar2 + 0xc);
      if ((*(int *)((int)arg0 + 0xdc) == 0) && (piVar2[5] == 0)) {
        if (*(int *)((int)arg0 + 0x2cc) == 0) {
          temp_v5 = func_0047d1a0();
          *(unsigned int *)((int)arg0 + 0x2cc) = temp_v5;
        }
        temp_v4 = *(unsigned int *)((int)arg0 + 0x2cc);
      }
      else {
        if (*(int *)((int)arg0 +
                    ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 +
                    0x124) == 0) {
          temp_v6 = (unsigned int)uStack_2 * 8 + 0x34;
          func_0044ea90(D_00713138, 0x1d6);
          temp_v7 = (u32)((void*(*)(int,int))DAT_008873e8[0])(temp_v6,0x40000);
          func_0043f9c8(temp_v7,0,temp_v6);
          puVar9 = (unsigned int *)temp_v7;
          *puVar9 = (temp_v2 & 0xffff);
          puVar9[5] = (unsigned int)(puVar9 + 0xd);
          puVar9[8] = (unsigned int)(puVar9 + 0xd + (temp_v2 & 0xffff));
          *(unsigned int **)((int)arg0 +
                    ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 +
                    0x124) = puVar9;
        }
        if (*(int *)(*(int *)(*(int *)((int)arg0 +
                                      ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 +
                                      (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x124) + 0x14) +
                    (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 4) == 0) {
          temp_v5 = func_0047d1a0();
          *(unsigned int *)(*(int *)(*(int *)((int)arg0 +
                                     ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 +
                                     (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x124) + 0x14) +
                   (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 4) = temp_v5;
        }
        temp_v4 = *(unsigned int *)
                 (*(int *)(*(int *)((int)arg0 +
                                   ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 +
                                   (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x124) + 0x14) +
                 (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 4);
      }
      temp_v7 = func_0047d320(temp_v4,temp_v3 + temp_v9,uStack_2c,uStack_30,uStack_24);
      temp_v5 = (unsigned int)uStack_30;
      while (temp_v5 = (temp_v5 + 1) & 0xffff, temp_v5 < uStack_2e + 1) {
        func_0047d460(temp_v4,temp_v7,temp_v5);
      }
      func_003e2ce0(*piVar2,uStack_2c);
      break;
    case 0xf0f000e1:
      temp_v3 = piVar2[0xb];
      temp_v9 = *(int *)(*piVar2 + 0xc);
      if (*(int *)((int)arg0 +
                  ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x124
                  ) == 0) {
        temp_v6 = (unsigned int)uStack_2 * 8 + 0x34;
        func_0044ea90(D_00713138, 0x1d6);
        temp_v7 = (u32)((void*(*)(int,int))DAT_008873e8[0])(temp_v6,0x40000);
        func_0043f9c8(temp_v7,0,temp_v6);
        puVar9 = (unsigned int *)temp_v7;
        *puVar9 = (temp_v2 & 0xffff);
        puVar9[5] = (unsigned int)(puVar9 + 0xd);
        puVar9[8] = (unsigned int)(puVar9 + 0xd + (temp_v2 & 0xffff));
        *(unsigned int **)((int)arg0 +
                  ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4 + 0x124
                  ) = puVar9;
      }
      temp_v4 = func_0047db50(temp_v3 + temp_v9,uStack_4c);
      *(unsigned int *)
       (*(int *)(*(int *)((int)arg0 +
                         ((unsigned int)*(unsigned short *)(piVar2 + 7) * 0x28 + (unsigned int)*(unsigned short *)(piVar2 + 7)) * 4
                         + 0x124) + 0x20) + (unsigned int)*(unsigned short *)((int)piVar2 + 0x1e) * 4) = temp_v4;
      func_003e2ce0(*piVar2,uStack_4c);
      break;
    case 0xf0f000f0:
      func_003e2910(*piVar2,&uStack_2,uStack_4c);
      *(unsigned short *)((int)piVar2 + (unsigned int)*(unsigned short *)(piVar2 + 7) * 2 + 0x20) = uStack_2;
      break;
    default:
      func_003e2ce0(*piVar2,uStack_4c);
      break;
    }
  }
  return 1;
}


#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047b0c0);
#endif


typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u32 func_004669d0(u32 a, u32* b, u32* c);
extern void func_003ef260(void* a, void* b, void* c);
extern void func_003ef1b0(void* a);
extern void func_003e2e40(void* a, void* b);
extern void func_003d60e0(void* a, s32 b);
extern s32 func_004667d0();
extern u32 func_0047f9f0(void* a);
extern s32 func_004800d0(void *stream, u8 **head, u32 kind, void *clump);
extern void func_00463100(void* a);
extern u8 D_0070B610;
/* measured cold47c660: sanitized m2c (3x K&R->ANSI) 282 lines; raw u8* idiom (no new struct,
   alloc/free/memset via DAT_008873e8[0]/DAT_008873ec[0]/func_0043f9c8, single-arg d200/dc30).
   Count first: fndiff window 1952B (488 words incl. 3 trailing nops), fnalign retail 485 instrs.
   R1: v1 de-noised 366 words / 464 instrs / 309 edits+6 reloc-only, frame 0xD0 vs 0x100.
   R2: v3 explicit outer/mapBase/cntBase/layer (tbl k-stride fix) 364 / 464 / 294+6 (best, -2/-15).
   R3: Model-clump idiom 373 (+9 regress, raw kept); u_long128 spills v2 400/480 and v4 400/471
   (+36 regress, mixed-width dsll32/dsrl32 before sq where retail sq's directly, cf 0x480670).
   R4 pragmas on v3: propoff 364 tie (466 instrs), loopinv 364 tie, csuboff 461, schedon 443.
   Two unproductive families (pragmas, spills/idiom) after one productive (explicit locals), stop.
   fnalign best (v3): retail 485 vs object 464 (21 short, 4.3% short), 294 edits+6 reloc-only.
   Residual: 5-way saved-reg rotation (retail sz:$s0/t17:$s1/p:$s2/v19:$s3/v20:$s4/obj:$s5/cnt:$s6/cnt2:$s7
   vs b210 t17:$s0/p:$s2/obj:$s4/v20:$s5...), D_0070B610 scalar gp-relative vs retail lui (1 word),
   and 4x sq/lq 32-bit spills emitted as sw/lw (frame 0xD0 vs 0x100). Prior nd~409 floor retained
   below as context; production stays ASM. */
/* prior floor context (retained): three alloc blocks, 0xC list loop, 0x234/0x254 slot tables,
   8-word 0x50 copy, d200/dc30 1-arg calls, 0x667d0 10-arg call, sq/lq u_long128 spE0/D0/C0/B0,
   rotation groups {t17,sz} and {v19,v20,obj} rotate together in every declaration order tried. */
/* gate: object 475 against retail 485, -2.1% - INSIDE the +-3% band (need >=470).
   Fixes: 0x234 block (s32)map->(s32)(s64)map to match retail dsll32/dsra32 for both
   0x234/0x254 tables (+2, 464->466); u32 i/j/k->u16 to match retail andi wrapping
   (+9, 466->475, frame 0xE0->0x100 matching retail). fnalign 294->298 edits (count
   fix before word-score comparison, handoff 7y). Remaining: saved-reg rotation,
   D_0070B610 gp-relative vs lui (1 word), sq/lq spills (count-neutral). */
// FUN_0047C660 NONMATCHING
#ifdef NON_MATCHING
s32 func_0047c660(u8 *arg0)
{
    u8 *owner;
    s32 ok;
    s32 okA;
    s32 okB;
    u32 size;
    u32 res;
    u32 ready;
    void *handle;
    u16 cnt;
    u16 i;
    u16 j;
    u16 k;
    u8 *slot;
    u8 *base;
    s16 map;
    u32 srcIdx;
    u32 dstIdx;
    s32 srcOff;
    s32 dstOff;
    u8 *srcEnt;
    u8 *dstEnt;
    s32 n;
    u8 *s;
    u8 *d;
    u32 anim;
    u8 *tbl;
    u8 *node;
    u8 *next;
    u8 *outer;
    u8 *mapBase;
    u8 *cntBase;
    u8 *layer;

    owner = *(u8 **)(arg0 + 0x30C);
    ok = 1;
    okA = 1;
    okB = 1;
    if (*(u32 *)(owner + 4) != 0) {
        res = func_004669d0(*(u32 *)(owner + 4), &ready, (u32 *)&handle);
        if (ready == 1) {
            func_003ef260((void *)res, func_00463100, owner + 0x34);
            func_003ef1b0((void *)res);
            func_003e2e40(handle, 0);
            *(u32 *)(owner + 4) = 0;
        } else {
            okA = 0;
            ok = 0;
        }
    }
    if (*(u32 *)(owner + 8) != 0) {
        res = func_004669d0(*(u32 *)(owner + 8), &ready, (u32 *)&handle);
        if (ready == 1) {
            if (*(void **)(arg0 + 0x254) == 0) {
                cnt = *(u16 *)(owner + 0x20);
                size = (u32)cnt * 8 + 0x10;
                func_0044ea90(D_00713138, 0x908);
                slot = ((void *(*)(int, int))DAT_008873e8[0])((int)size, 0x40000);
                func_0043f9c8(slot, 0, (int)size);
                *(u8 **)(slot + 0) = slot + 0x10;
                *(u16 *)(slot + 0xC) = cnt;
                *(u16 *)(slot + 0xE) = 1;
                *(u8 **)(arg0 + 0x254) = slot;
            }
            *(u32 *)(*(u8 **)(arg0 + 0x254) + 4) = res;
            func_003d60e0(&D_0070B610, (s32)res);
            func_003e2e40(handle, 0);
            *(u32 *)(owner + 8) = 0;
        } else {
            ok = 0;
            okB = 0;
        }
    }
    if (*(u32 *)(owner + 0xC) != 0) {
        i = 0;
        while (i < *(u16 *)(owner + 0x20)) {
            if (*(u32 *)(*(u8 **)(owner + 0xC) + i * 4) != 0) {
                res = func_004669d0(*(u32 *)(*(u8 **)(owner + 0xC) + i * 4), &ready, (u32 *)&handle);
                if (ready == 1) {
                    if (*(void **)(arg0 + 0x254) == 0) {
                        cnt = *(u16 *)(owner + 0x20);
                        size = (u32)cnt * 8 + 0x10;
                        func_0044ea90(D_00713138, 0x908);
                        slot = ((void *(*)(int, int))DAT_008873e8[0])((int)size, 0x40000);
                        func_0043f9c8(slot, 0, (int)size);
                        *(u8 **)(slot + 0) = slot + 0x10;
                        *(u16 *)(slot + 0xC) = cnt;
                        *(u16 *)(slot + 0xE) = 1;
                        *(u8 **)(arg0 + 0x254) = slot;
                    }
                    base = *(u8 **)(*(u8 **)(arg0 + 0x254) + 0);
                    *(u32 *)(base + (i & 0xFFFF) * 8) = res;
                    func_003e2e40(handle, 0);
                    *(u32 *)(*(u8 **)(owner + 0xC) + i * 4) = 0;
                } else {
                    ok = 0;
                }
            }
            i++;
        }
    }
    if (*(u32 *)(owner + 0x14) != 0 || *(u32 *)(owner + 0x10) != 0) {
        if (okA == 1 && okB == 1) {
            if (*(u32 *)(owner + 0x14) != 0) {
                *(u32 *)(owner + 0x10) = (u32)func_004667d0(2, 0, 0, 0, *(s32 *)(owner + 0x14), 0, 0, 0, 0, 0);
                *(u32 *)(owner + 0x14) = 0;
                ok = 0;
            } else {
                res = func_004669d0(*(u32 *)(owner + 0x10), &ready, (u32 *)&handle);
                if (ready == 1) {
                    *(u32 *)(arg0 + 0xDC) = res;
                    func_003e2e40(handle, 0);
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
                    func_0043f9c8(slot, 0, (int)size);
                    *(u8 **)(slot + 0) = slot + 8;
                    *(u16 *)(slot + 4) = cnt;
                    *(u16 *)(slot + 6) = 1;
                    *(u8 **)(arg0 + 0x234) = slot;
                }
                base = *(u8 **)(arg0 + 0x234);
                if (*(u32 *)(*(u8 **)(base + 0) + *(u16 *)(node + 4) * 8) == 0) {
                    *(u32 *)(*(u8 **)(base + 0) + *(u16 *)(node + 4) * 8) = (u32)func_0047f9f0(base);
                }
                func_004800d0(*(void **)(node + 8), (u8 **)*(void **)(*(u8 **)(base + 0) + *(u16 *)(node + 4) * 8), *(u32 *)(node + 0), *(void **)(arg0 + 0xDC));
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
            cntBase = owner + k * 2;
            layer = arg0 + k * 0xA4;
            if (*(u32 *)(outer + 0x24) != 0) {
                j = 0;
                while (j < *(u16 *)(cntBase + 0x20)) {
                    mapBase = *(u8 **)(outer + 0x24);
                    map = *(s16 *)(mapBase + j * 2);
                    if (map != -1) {
                        srcIdx = (u16)map;
                        dstIdx = (u16)j;
                        srcOff = (s32)srcIdx * 0x50;
                        dstOff = (s32)dstIdx * 0x50;
                        base = *(u8 **)(layer + 0x120);
                        srcEnt = *(u8 **)base + srcOff;
                        dstEnt = *(u8 **)base + dstOff;
                        s = srcEnt;
                        d = dstEnt;
                        n = 8;
                        do {
                            *(u32 *)(d + 0) = *(u32 *)(s + 0);
                            *(u32 *)(d + 4) = *(u32 *)(s + 4);
                            s += 8;
                            n--;
                            d += 8;
                        } while (n > 0);
                        base = *(u8 **)base;
                        anim = *(u32 *)(base + srcOff + 0x40);
                        if (anim != 0) {
                            *(u32 *)(base + dstOff + 0x40) = anim;
                        }
                        *(u32 *)(base + dstOff + 0x44) |= 1;
                        if (k == 0) {
                            if (*(void **)(arg0 + 0x234) != 0) {
                                if ((s32)(s64)map < (s32)*(u16 *)(*(u8 **)(arg0 + 0x234) + 4)) {
                                    base = *(u8 **)(*(u8 **)(arg0 + 0x234) + 0);
                                    if (*(u32 *)(base + (u32)(u16)map * 8) != 0) {
                                        *(u32 *)(base + (j & 0xFFFF) * 8) = *(u32 *)(base + (u32)(u16)map * 8);
                                        *(u8 *)(base + (j & 0xFFFF) * 8 + 4) |= 1;
                                    }
                                }
                            }
                            if (*(void **)(arg0 + 0x254) != 0) {
                                if ((s32)(s64)map < (s32)*(u16 *)(*(u8 **)(arg0 + 0x254) + 0xC)) {
                                    base = *(u8 **)(*(u8 **)(arg0 + 0x254) + 0);
                                    if (*(u32 *)(base + (u32)(u16)map * 8) != 0) {
                                        *(u32 *)(base + (j & 0xFFFF) * 8) = *(u32 *)(base + (u32)(u16)map * 8);
                                        *(u8 *)(base + (j & 0xFFFF) * 8 + 4) |= 1;
                                    }
                                }
                            }
                            tbl = *(u8 **)(layer + 0x124);
                            if (tbl != 0) {
                                if (*(void **)(tbl + 0x14 + (u32)(u16)map * 4) != 0) {
                                    *(void **)(tbl + 0x14 + (u16)j * 4) = func_0047d200(*(void **)(tbl + 0x14 + (u32)(u16)map * 4));
                                }
                                if (*(void **)(tbl + 0x20 + (u32)(u16)map * 4) != 0) {
                                    *(void **)(tbl + 0x20 + (u16)j * 4) = func_0047dc30(*(void **)(tbl + 0x20 + (u32)(u16)map * 4));
                                }
                            }
                        }
                    }
                    j++;
                }
                DAT_008873ec[0](*(void **)(outer + 0x24));
            }
            k++;
        }
    }
    return ok;
}
#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047c660);
#endif
