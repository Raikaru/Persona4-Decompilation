#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
typedef struct BtlPacket BtlPacket;
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern void btlUnitSetRot(void *arg0, void *arg1);
extern void btlTargetBlendVectors(void *out, void *first, void *second);
extern void btlTargetPositionToCell(s16 *arg0, s16 *arg1, f32 *position);
extern s32 datCalcGetAffinity(u8 *arg0, s32 arg1);
extern u16 datCalcMaxHp(u8 *arg0);
extern u16 datCalcMaxSp(u8 *arg0);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern s32 datCalcGetLevel(u8 *arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u32 datCalcChkBadStatus(int unit, u32 badStatus);
extern u16 datCalcGetHp(u8 *arg0);
extern u16 datCalcGetSp(u8 *arg0);
extern void btlEffectFreeEntry(s32 arg0, s32 arg1);
extern s32 btlEffectStepFormationPlacement(u8 *arg0);
extern void btlFormationResetState(s32 arg0);
extern void mdlEffectDestroyWithNodes(s32 arg0);
extern void mdlDestroyModelObject(s32 arg0);
extern void btlEffectResetEntry(u8 *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void btlFormationSetPlacement(s32 arg0);
extern void btlEffectReleaseNode(u8 *arg0);
extern void btlEffectReleaseAllPlacements(u8 *arg0);
extern void H_Cdvd_Destroy(u8 *arg0);
extern u32 iGpffffb3b8;
extern void btlEffectCollectTargetUnits(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);

extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern s32 mdlComputeIndexedAttachMatrix();
extern void mdlUpdateModelMatrix(u8 *arg0);
extern void mdlPrepareItemSlots(u8 *arg0);
extern void RtQuatTransformVectors(f32 *arg0, f32 *arg1, s32 arg2, u8 *arg3);
extern void func_00485870(s32 arg0);
extern s32 TnGetTableBase(void);
extern void TnSetTableBase(s32 arg0);
extern void mdlSetColor(u8 *arg0, u32 *arg1);
extern void mdlEffectApplyPackedColor(u8 *arg0, s32 arg1);
extern void mdlAdvanceModelFromFlags(s32 arg0);
extern void func_00485630(u8 *arg0);
extern void func_001d53e0(s32 arg0);
extern void mdlQueueModelForDraw(s32 arg0, u8 *arg1);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(char *arg0, u8 *arg1);
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
extern void btlFormationVuTransform(f32 arg0, f32 arg1, f32 *arg2, s32 *arg3, u8 *arg4, u8 *arg5);
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern void btlUnitSetPos(u8 *arg0, f32 *arg1);
extern void btlUnitGetAnimBoundsWorldCenterTowardUnit(u8 *arg0, s32 arg1, u8 *arg2);
extern u8 *btlUnitGetRecordPtr(u8 *arg0, s32 arg1);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);
extern void chkmemAllocSiteTag(u8 *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void memset(u8 *arg0, s32 arg1, s32 arg2);
extern s8 datCalcRandomBelow(s32 arg0);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern void mdlEffectCopyCameraAim(u8 *arg0);
extern void func_003dc740(void *arg0, void *arg1, f32 arg3, s32 arg2);


extern u8 *kwlnGetCamera();
extern void func_003e8110(u8 *arg0);
extern void func_003e8120(u8 *arg0);
extern void func_003e9cb0(s32 arg0, u8 *arg1, s32 arg2);
extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();






extern s32 datCalcSkillElement(u8 *arg0, u16 arg1);
extern s32 fadeBeginReturnTransition(s32 arg0, s32 arg1);

extern void btlFormationDispatchArgs(void);
extern void *btlPacketAlloc();

extern s32 btlEffectSetFadeLevel(u16 *arg0);
extern s32 btlUnitRealignCells(void);

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern s32 btlActionGetQueueFront(void);
extern void btlCameraLookAtQuat(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern f32 tanf(f32 arg0);
extern void btlMainCurveSetPoses(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
extern void btlCameraSetDuration(u8 *arg0, f32 arg1);
extern void btlCameraSetupActionGeometry(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

extern void btlFormationTransformOffset(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
extern void btlFormationOrientToUnit(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
extern void btlFormationApplyModelMatrix(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
extern void btlFormationApplyModelMatrixAlt(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
extern void btlFormationOffsetTransformA(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
extern void btlFormationOffsetTransformB(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
extern void btlFormationOffsetTransformC(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
extern void btlFormationAttachPosition(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
static inline f32 formationCapacityLimit(s32 limit)
{
    return (f32)limit;
}

#pragma pop
/* Position callbacks receive the attachment work, battle unit, 0x18-byte
 * entry, and the caller's four-float position buffer. Some callbacks use
 * only a subset of those objects; their shared pointer contract is unchanged.
 * D_00609500 has fourteen slots, including two null slots at types 5 and 6. */
typedef void BtlAttachPositionCallback(u8 *work, u8 *unit, u8 *entry, f32 *position);
BtlAttachPositionCallback btlFormationTransformOffset;
BtlAttachPositionCallback btlFormationOrientToUnit;
BtlAttachPositionCallback btlFormationApplyModelMatrix;
BtlAttachPositionCallback btlFormationApplyModelMatrixAlt;
BtlAttachPositionCallback btlFormationOffsetTransformA;
BtlAttachPositionCallback btlFormationOffsetTransformB;
BtlAttachPositionCallback btlFormationOffsetTransformC;
BtlAttachPositionCallback btlFormationClearAttachVector;
BtlAttachPositionCallback btlFormationAttachPosition;

/* Retail keeps {unit,entry,handles,frame,w} in $s0-$s4 and the loop index in
   $s5. The loop compares against `now = (u32)frame`: that converted copy is a
   copy use, so `frame` survives as its declared local (numbered after `w`)
   instead of folding into its load temporary, and colours to $s3. A plain
   `now = frame` folds both and keeps the old $s3/$s5 swap. */
typedef struct BtlAttachV3
{
    f32 x;
    f32 y;
    f32 z;
} BtlAttachV3;

typedef struct BtlAttachV4
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} BtlAttachV4;

typedef struct BtlAttachEntry
{
    u8 state;      // 0x00
    u8 pad01[3];
    u8 *resource;  // 0x04: template to clone, or an existing effect instance
    u8 type;       // 0x08
    u8 pad09[5];
    u16 kind;      // 0x0E
    u32 start;     // 0x10
    u8 pad14[4];
} BtlAttachEntry; // 0x18

typedef struct BtlAttachWork
{
    u8 *owner;            // 0x00
    u8 *table;            // 0x04
    u32 flags;            // 0x08
    u32 frame;            // 0x0C
    u32 color;            // 0x10
    u8 level;             // 0x14
    u8 pad15[3];
    u8 *unit;             // 0x18
    u8 *target;           // 0x1C
    BtlAttachV3 scale;    // 0x20
    f32 radius;           // 0x2C
    f32 height;           // 0x30
    BtlAttachV3 pos;      // 0x34
    BtlAttachV4 center;   // 0x40
    f32 size;             // 0x50
    u16 count;            // 0x54
    u8 pad56[2];
    u8 **handles;         // 0x58
} BtlAttachWork;

static inline f32 btlAttachEffectScale(u8 *unit)
{
    f32 s;

    s = 0.0125f * (0.5f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C) + 0.5f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C))));
    if (!(s <= 2.5f)) {
        s = 2.5f;
    } else if (s < 0.8f) {
        s = 0.8f;
    }
    return s;
}

static inline f32 btlAttachFieldScale(u8 *unit)
{
    f32 s;

    if (*(s32 *)(iGpffffb3ac + 0x314) == 0) {
        return 4.25f;
    }
    s = 2.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)) / 100.0f;
    if (!(s <= 5.0f)) {
        s = 5.0f;
    } else if (s < 2.0f) {
        s = 2.0f;
    }
    return s;
}

#pragma optimization_level 1
#pragma optimization_level 2


#pragma push
#pragma opt_propagation off
#pragma pop



#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on



#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#undef PROJ
#undef POS
#undef CENTER
#undef BASEXZ
#undef CENTERXZ
#undef CURXZ
#undef OUTXZ
#undef DELTA
#undef DIR
#pragma pop
#pragma push
#pragma opt_loop_invariants on
#pragma pop
