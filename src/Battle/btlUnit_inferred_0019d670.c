#include "btl_skill_target_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "effect_instance_internal.h"
#include "btl_skill_internal.h"
#include "btl_unit_internal.h"
#include "btl_unit_look_internal.h"
#include "model_battle_internal.h"
#include "resrc_manager_internal.h"
typedef RwV3d P4_95730_Vec3;
typedef struct P4_95730_Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4_95730_Vec4;
typedef struct P4_95730_Bytes4 {
    u8 x;
    u8 y;
    u8 z;
    u8 w;
} P4_95730_Bytes4;

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac; /* active battle context */
extern u8 *iGpffffb3b8; /* skill table, DatSkillEntry rows */
extern u8 *iGpffffb3c0; /* party visual records, stride 0x14C */
extern u8 *iGpffffb3cc; /* enemy visual records, stride 0xE8 */


extern u8 *iGpffff9db0;
extern u8 *D_0076449C; /* active battle context */
extern u8 *iGpffffb3ac; /* active battle context */
extern u8 *iGpffffb414;
extern u8 *iGpffffb3e0; /* child visual records, stride 0x58 */
extern s32 iGpffffb430;
extern s32 iGpffffb434;
extern s32 iGpffffb438;
extern u8 D_005F6BF0[];
extern u8 D_005F66C0[];
extern u64 iGpffffa090;
extern u16 iGpffffa098;
extern s32 iGpffffb43c;
extern u8 D_005F65D0[];
extern u8 D_005F65B0[];
extern u8 D_005F65C0[];

extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern void RtQuatTransformVectors(void *out, const void *in, s32 count,
                          const void *quat);
extern P4_95730_Vec3 D_0060A0D0;
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern P4_95730_Vec3 D_0060A100;
extern u8 *(*D_008873E8[])(s32 arg0, s32 arg1);


/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */
static inline u8 *p4_unit_00195530(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}
static inline s32 p4_base_add_0019f050(s32 offset, s32 base)
{
    return base + offset;
}
static inline s32 *p4_entries_001900a0(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}
static inline s32 p4_base_add_00194590(s32 offset, s32 base)
{
    return offset + base;
}
static inline u8 p4_one_00194470(void)
{
    return 1;
}
static inline s64 p4_sign16_001991c0(s16 value)
{
    return value;
}
static inline s32 p4_table_001951f0(s32 modeOffset, s32 charOffset,
                                    s32 base)
{
    return modeOffset + charOffset + base;
}
static inline f32 p4_add_0019a680(f32 left, f32 right)
{
    return left + right;
}
static inline void p4_d550_store(u8 *value, u8 *base, u32 index, u32 offset)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    *(u8 **)(address + offset) = stored;
}

static inline void p4_call_00198920(s16 arg1, u8 *arg0, u16 arg2, f32 arg3, u16 arg4)
{
    btlUnitSetMotion(arg0, arg1, arg2, arg3, arg4);
}
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    scrStartProcedureChecked(arg0, arg1, arg2, arg3);
}
extern u8 iGpffffa4d8;
extern void btlCameraSetUnitSlotValue(u8 *unit, s32 slotIndex, s32 slotValue);
extern void btlTargetRemoveRadiusNode(u8 *unit);
extern int mdlHasActiveMode(void *model);
extern void mdlSetLookAtActive(void *model);
extern void mdlSetLookAtRequested(void *model);
extern u8 *resrcMngFindResById(u8 *manager, u16 resourceId);
extern void btlUnitApplyModelState(u8 *unit, s32 mode);
extern void mdlSetBattleStateFlag(void *model);
extern void mdlSetAlphaBlend(void *model);
extern void mdlSetLookStateWord(void *model, u16 value);
extern u16 mdlGetLookStateWord(void *model);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern void mdlClearBattleStateFlag(void *model);
extern void mdlClearAlphaBlend(void *model);
extern void mdlSetBlendWeight(void *model, float value);
extern void mdlLookAtSetupSetRange(void *model, float pitchLimit, float yawLimit);
extern f32 DAT_0076112c;


extern void btlUnitClearModelState(u8 *unit, s32 mode);
extern void btlUnitApplyModelState(u8 *unit, s32 mode);
extern u8 *btlSoundGetCharacterBank(u8 *unit);




extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern void btlUnitFreeRemovedUnits(void);
extern void (*jtbl_008873EC[])(void *arg0);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlUnitUpdateLookAtTarget(u8 *unit);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 0019d670-0019db40 */

/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Measured: 1164 instruction bytes in the 1168-byte window, three resolved
 * relocations and a four-byte zero tail. This callback uses the packet creator's
 * u32 (void *) contract. Modes 1..4 initialize every timing value; the retail
 * constructor callers use modes 3 or 4. The packet is 20 bytes.
 * Disabling propagation locally retains the alpha result's memory/merge
 * lifetime. Publication remains the actual four-byte color-by-value operation. */
#pragma push
#pragma pop
/* Retail reloads the 1/255 colour scale (0x3B808081, written here as a
 * literal) for every factor; with default optimisation b210 does the same.
 * `v41` and `chk` are function-scope locals so they keep retail's saved
 * registers. On the `i == 2 && alpha < 0xFE` path retail compares 0xE8
 * against the `mode` left from an earlier entry (0x0019CDE0); the C reads
 * `mode` uninitialised there in the same way. */
#pragma push
#pragma pop
/* Unlink and release all four genus lists, including camera-slot ownership. */
// FUN_0019D670
void btlUnitFreeRemovedUnits(void)
{
    /* measured: repeated typed list-link reads retain field addresses across
     * callbacks; the later link reloads preserve byte aliasing. */
    u8 *unit;
    u8 *nextUnit;
    u32 genusIndex;
    u8 *nextLink;
    u8 *previousLink;
    u8 genus;
    s8 cameraSlot;

    for (genusIndex = 0; genusIndex < 4; genusIndex++) {
        unit = ((BtlBattleState *)iGpffffb3ac)->unitLists[genusIndex * 2];
        while (unit != NULL) {
            nextUnit = *(u8 **)&((BtlUnit *)unit)->nextUnit;
            genus = ((BtlUnit *)unit)->genus;
            btlUnitReleaseAllResources(unit);
            btlTargetRemoveRadiusNode(unit);
            cameraSlot = ((BtlUnit *)unit)->cameraSlot;
            if (cameraSlot >= 0)
                btlCameraSetUnitSlotValue(unit, cameraSlot, 0);
            nextLink = *(u8 **)(unit + 0xA6C);
            if (nextLink != NULL)
                *(u8 **)&((BtlUnit *)nextLink)->prevUnit = *(u8 **)&((BtlUnit *)unit)->prevUnit;
            else
                ((BtlBattleState *)iGpffffb3ac)->unitLists[(genus & 0xFF) * 2 + 1] =
                    *(u8 **)(unit + 0xA68);
            previousLink = *(u8 **)(unit + 0xA68);
            if (previousLink != NULL)
                *(u8 **)&((BtlUnit *)previousLink)->nextUnit = *(u8 **)(unit + 0xA6C);
            else
                ((BtlBattleState *)iGpffffb3ac)->unitLists[(genus & 0xFF) * 2] =
                    *(u8 **)(unit + 0xA6C);
            jtbl_008873EC[0](unit);
            unit = nextUnit;
        }
    }
}

/* measured: plain-C switch reconstruction reproduces the 488-byte object against the 496-byte retail window; the jump-table base register remains the residual. Committed at nd 61. */
/* Enable one model presentation mode; modes 1..4 affect draw/look/sound state,
 * while mode 6 marks the scene resource. */
// FUN_0019D7A0
void btlUnitApplyModelState(u8 *unit, s32 mode)
{
    /* measured: repeated typed layerHandle loads hoist unit+0xA00 into
     * a saved register; subsequent handle reloads remain byte-addressed. */
    s32 stateFlags;
    u16 sceneDrawId;
    u16 selectedMode;
    u8 *resource;
    u8 *model;
    u8 *soundModel;
    if ((*(s32 *)&((BtlUnit *)unit)->flags2 & 2) != 0) {
        selectedMode = (u16)mode;
        switch (selectedMode) {
        case 6:
            sceneDrawId = ((BtlUnit *)unit)->sceneDrawId;
            if ((sceneDrawId != 0) &&
                (((s32)(sceneDrawId & 0xFFC00) >> 10) == 1)) {
                /* The enclosing scene context is opaque; +8 holds its resource manager. */
                resource = resrcMngFindResById(*(u8 **)(iGpffff9db0 + 8), sceneDrawId);
                *(s32 *)&((ResrcRecord *)resource)->handle22C = 0x34;
                *(s32 *)&((ResrcRecord *)resource)->unk28 |= 0x04000000;
                return;
            }
            break;
        case 1:
            stateFlags = ((BtlBattleState *)iGpffffb3ac)->battleFlags;
            if (((stateFlags & 0x100) == 0) ||
                (((BtlUnit *)unit)->genus != 0)) {
                if (((stateFlags & 0x200) == 0) ||
                    (((BtlUnit *)unit)->genus != 1)) {
                    mdlSetBattleStateFlag(((BtlUnit *)unit)->layerHandle);
                    *(u8 **)&((Model *)(*(u8 **)(unit + 0xA00)))->queue =
                        D_007940F0;
                    ((Model *)(*(u8 **)(unit + 0xA00)))->limit =
                        fGpffff80fc;
                    model = *(u8 **)(unit + 0xA00);
                    ((Model *)model)->targetLimit =
                        ((Model *)model)->limit;
                    *(s32 *)&((Model *)(*(u8 **)(unit + 0xA00)))->limitRate =
                        0x3F800000;
                    return;
                }
            }
            break;
        case 2:
            mdlSetAlphaBlend(*(u8 **)(unit + 0xA00));
            return;
        case 3:
            mdlSetLookStateWord(*(u8 **)(unit + 0xA00), (u16)((mdlGetLookStateWord(*(u8 **)(unit + 0xA00)) &
                   0xFFFF) | 0x1000));
            mdlSetLookStateWord(*(u8 **)(unit + 0xA00), (u16)((mdlGetLookStateWord(*(u8 **)(unit + 0xA00)) &
                   0xFFFF) | 0x2000));
            stateFlags = mdlGetLookStateWord(*(u8 **)(unit + 0xA00)) & 0xFFFF;
            stateFlags = stateFlags & -0x801;
            mdlSetLookStateWord(*(u8 **)(unit + 0xA00), (u16)stateFlags);
            return;
        case 4:
            ((Model *)(*(u8 **)(unit + 0xA00)))->motion.request =
                (s32)btlSoundGetCharacterBank(unit);
            soundModel = *(u8 **)(unit + 0xA00);
            ((Model *)soundModel)->motion.flags |= 0x10;
            break;
        case 0:
        case 5:
            break;
        }
    }
}

/* Undo the selected model presentation mode and reset its associated state. */
// FUN_0019D990
void btlUnitClearModelState(u8 *unit, s32 mode)
{
    /* measured: repeated typed layerHandle loads hoist unit+0xA00 into
     * a saved register; subsequent handle reloads remain byte-addressed. */
    s32 lookFlags;
    u16 sceneDrawId;
    u32 selectedMode;
    u8 *resource;
    u8 *model;
    if ((*(s32 *)&((BtlUnit *)unit)->flags2 & 2) != 0) {
        selectedMode = (u32)mode & 0xFFFF;
        switch (selectedMode) {
        case 6:
            sceneDrawId = ((BtlUnit *)unit)->sceneDrawId;
            if ((sceneDrawId != 0) &&
                (((s32)(sceneDrawId & 0xFFC00) >> 10) == 1)) {
                /* The enclosing scene context is opaque; +8 holds its resource manager. */
                resource = resrcMngFindResById(*(u8 **)(iGpffff9db0 + 8), sceneDrawId);
                *(s32 *)&((ResrcRecord *)resource)->unk28 &= 0xFBFFFFFF;
                return;
            }
            break;
        case 1:
            mdlClearBattleStateFlag(((BtlUnit *)unit)->layerHandle);
            model = *(u8 **)(unit + 0xA00);
            ((Model *)model)->drawFlags &= 0xE2;
            return;
        case 2:
            mdlClearAlphaBlend(*(u8 **)(unit + 0xA00));
            return;
        case 3:
            mdlSetBlendWeight(*(u8 **)(unit + 0xA00), DAT_0076112c);
            mdlLookAtSetupSetRange(*(u8 **)(unit + 0xA00), 70.0f, 80.0f);
            mdlSetLookAtActive(*(u8 **)(unit + 0xA00));
            mdlSetLookAtRequested(*(u8 **)(unit + 0xA00));
            lookFlags = mdlGetLookStateWord(*(u8 **)(unit + 0xA00)) & 0xFFFF;
            lookFlags = lookFlags & -0x2001;
            mdlSetLookStateWord(*(u8 **)(unit + 0xA00), (u16)lookFlags);
            lookFlags = mdlGetLookStateWord(*(u8 **)(unit + 0xA00)) & 0xFFFF;
            lookFlags = lookFlags & -0x1001;
            mdlSetLookStateWord(*(u8 **)(unit + 0xA00), (u16)lookFlags);
            *(s16 *)&((BtlUnit *)unit)->lookAtMode = 0;
            return;
        case 4:
            model = *(u8 **)(unit + 0xA00);
            ((Model *)model)->motion.flags &= 0xFFEF;
            ((Model *)(*(u8 **)(unit + 0xA00)))->motion.request = 0;
            break;
        case 0:
        case 5:
            break;
        }
    }
}

// FUN_0019DB40
/* measured: object 812B/window 816B, nd 0. The mode dispatch is an explicit goto
   chain (`== 0x11` -> case11, `!= 0` -> def, fall to case0; a switch sorts the
   zero test first and drops the `b default`). func_00232710 is called with two
   arguments through an unprototyped block-scope extern; func_0019efe0 needs its
   real prototype at block scope (it is defined later in the unit). The scale
   multiplies are inline `*(f32 *)(target + 0x80) * *(f32 *)(target + 0x2C)` so the
   0x80 load precedes the 0x2C load. */
/* Resolve a fixed or unit-relative look point for an idle, loaded model. */
void btlUnitUpdateLookAtTarget(u8 *unit)
{
    /* measured: repeated typed model/look-state addresses add saved registers;
     * the corresponding flags, handle, mode, id and data reloads stay byte-addressed. */
    extern void mdlSetLookAtTargetPoint(void *model, void *target);
    extern s32 mdlComputeIndexedAttachMatrix(void *model, s32 index, void *destination);
    extern f32 DAT_007613f8;
    extern u8 *btlUnitFindById(s32 unitId);
    P4_95730_Vec3 lookPoint;
    P4_95730_Vec3 scaledCenter;
    P4_95730_Vec3 rotatedCenter;
    P4_95730_Vec3 modelScaledCenter;
    P4_95730_Vec3 modelRotatedCenter;
    s16 motion;
    u8 *target;

    if (*(s32 *)&((BtlUnit *)unit)->flags2 & 2) {
        if (*(s32 *)(unit + 0x98) & 2) {
            motion = ((BtlUnit *)unit)->currentMotion;
        } else {
            motion = 0;
        }
        if (motion == 0x11) {
            goto case11;
        }
        if (motion != 0) {
            goto def;
        }
        goto case0;
    case11:
        if (mdlHasActiveMode(((BtlUnit *)unit)->layerHandle) != 0) {
            mdlSetLookAtRequested(*(u8 **)(unit + 0xA00));
        }
        return;
    def:
        if (mdlHasActiveMode(*(u8 **)(unit + 0xA00)) != 0) {
            mdlSetLookAtActive(*(u8 **)(unit + 0xA00));
            mdlSetLookAtRequested(*(u8 **)(unit + 0xA00));
        }
        return;
    case0:
            if (*(s32 *)&((BtlUnit *)unit)->datUnit != 0 && datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100) != 0) {
                if (mdlHasActiveMode(*(u8 **)(unit + 0xA00)) != 0) {
                    mdlSetLookAtRequested(*(u8 **)(unit + 0xA00));
                }
                return;
            }
            if (((BtlUnit *)unit)->lookAtMode != 0 && !(((Model *)(*(u8 **)(unit + 0xA00)))->layerBlend < 1.0f) && !(mdlGetLookStateWord(*(u8 **)(unit + 0xA00)) & 0x200)) {
                switch (*(u16 *)(unit + 0xB0)) {
                case 1:
                    mdlSetLookAtTargetPoint(*(u8 **)(unit + 0xA00), &((BtlUnit *)unit)->lookAtTargetPos);
                    return;
                case 2:
                    if (*(s32 *)&((BtlUnit *)unit)->lookAtTargetId != 0) {
                        target = btlUnitFindById(*(s32 *)(unit + 0xB4) & 0xFFFF);
                        if (target != NULL && target != unit) {
                            if (!(*(s32 *)&((BtlUnit *)target)->flags2 & 2)) {
                                scaledCenter.x = ((BtlUnit *)target)->sphereCenter.x * ((BtlUnit *)target)->scale;
                                scaledCenter.y = ((BtlUnit *)target)->sphereCenter.y * ((BtlUnit *)target)->scale;
                                scaledCenter.z = ((BtlUnit *)target)->sphereCenter.z * ((BtlUnit *)target)->scale;
                                RtQuatTransformVectors(&rotatedCenter, &scaledCenter, 1, &((BtlUnit *)target)->rot);
                                lookPoint.x = rotatedCenter.x + ((BtlUnit *)target)->pos.x;
                                lookPoint.y = rotatedCenter.y + ((BtlUnit *)target)->pos.y;
                                lookPoint.z = rotatedCenter.z + ((BtlUnit *)target)->pos.z;
                            } else if (mdlComputeIndexedAttachMatrix(((BtlUnit *)target)->layerHandle, 0, &lookPoint) == 0) {
                                modelScaledCenter.x = ((BtlUnit *)target)->sphereCenter.x * ((BtlUnit *)target)->scale;
                                modelScaledCenter.y = ((BtlUnit *)target)->sphereCenter.y * ((BtlUnit *)target)->scale;
                                modelScaledCenter.z = ((BtlUnit *)target)->sphereCenter.z * ((BtlUnit *)target)->scale;
                                RtQuatTransformVectors(&modelRotatedCenter, &modelScaledCenter, 1, &((BtlUnit *)target)->rot);
                                lookPoint.x = modelRotatedCenter.x + ((BtlUnit *)target)->pos.x;
                                lookPoint.y = modelRotatedCenter.y + ((BtlUnit *)target)->pos.y;
                                lookPoint.z = modelRotatedCenter.z + ((BtlUnit *)target)->pos.z;
                            }
                            lookPoint.y += ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale * DAT_007613f8;
                            mdlSetLookAtTargetPoint(*(u8 **)(unit + 0xA00), &lookPoint);
                            return;
                        }
                        mdlSetLookAtRequested(*(u8 **)(unit + 0xA00));
                        *(s32 *)(unit + 0xB4) = 0;
                    }
                    break;
                }
            }
    }
}

