#include "btl_target_state_packet_internal.h"
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
#include "rw_types_internal.h"
#include "btl_unit_look_internal.h"
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
typedef struct DatUnit DatUnit;

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



extern u8 iGpffffa4d8;
extern int mdlHasActiveMode(void *model);
extern void mdlSetLookAtActive(void *model);
extern void mdlSetLookAtRequested(void *model);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern void mdlLookAtSetupSetRange(void *model, float pitchLimit, float yawLimit);
extern f32 DAT_0076112c;






extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;

extern s32 btlUnitLookAtSidePacketUpdate(u8 *work);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 0019e850-0019e850 */

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
/* measured: opt_propagation off plus named call_angle locals preserve retail's stack reloads before mdlLookAtSetupSetRange. */
#pragma push
/* measured: restore pragma state after func_0019df20. */
#pragma pop
/* Refresh active look controllers for the requested side(s), or one unit. */
// FUN_0019E850
s32 btlUnitLookAtSidePacketUpdate(u8 *work)
{
    BtlUnit *typedUnit;
    BtlUnit *typedEnemyUnit;
    BtlUnitLookSideWork *typedWork = (BtlUnitLookSideWork *)work;
    BtlUnit *typedPartyUnit;
    u16 sideFlags;
    u8 *unit;
    u8 *partyUnit;
    u8 *enemyUnit;

    sideFlags = ((BtlUnitLookSideWork *)work)->flags;
    if (sideFlags & 3) {
        if (sideFlags & 1) {
            partyUnit = ((BtlBattleState *)D_0076449C)->unitLists[1];
            typedPartyUnit = (BtlUnit *)partyUnit;
            while (partyUnit != NULL) {
                if (((((BtlUnit *)partyUnit)->flags3 & 8) != 0) &&
                    ((((BtlUnit *)partyUnit)->flags2 & 2) != 0) &&
                    (mdlHasActiveMode(((BtlUnit *)partyUnit)->layerHandle) != 0)) {
                    /* measured: repeated typed layer loads hoist +0xA00; preserve the post-call reloads. */
                    mdlSetLookAtActive(typedPartyUnit->layerHandle);
                    mdlSetLookAtRequested(typedPartyUnit->layerHandle);
                }
                partyUnit = (u8 *)((BtlUnit *)partyUnit)->prevUnit;
                typedPartyUnit = (BtlUnit *)partyUnit;
            }
        }
        /* measured: a typed flags reload keeps work+4 in s0, exchanging the party traversal registers. */
        if ((typedWork->flags & 2) != 0) {
            enemyUnit = ((BtlBattleState *)D_0076449C)->unitLists[3];
            typedEnemyUnit = (BtlUnit *)enemyUnit;
            while (enemyUnit != NULL) {
                if (((((BtlUnit *)enemyUnit)->flags3 & 8) != 0) &&
                    ((((BtlUnit *)enemyUnit)->flags2 & 2) != 0) &&
                    (mdlHasActiveMode(((BtlUnit *)enemyUnit)->layerHandle) != 0)) {
                    /* Same post-call model reload constraint as the party branch. */
                    mdlSetLookAtActive(typedEnemyUnit->layerHandle);
                    mdlSetLookAtRequested(typedEnemyUnit->layerHandle);
                }
                enemyUnit = (u8 *)((BtlUnit *)enemyUnit)->prevUnit;
                typedEnemyUnit = (BtlUnit *)enemyUnit;
            }
        }
    } else {
        unit = ((BtlUnitLookSideWork *)work)->unit;
        typedUnit = (BtlUnit *)unit;
        if (((((BtlUnit *)unit)->flags2 & 2) != 0) &&
            (mdlHasActiveMode(((BtlUnit *)unit)->layerHandle) != 0)) {
            /* Same post-call model reload constraint as the side branches. */
            mdlSetLookAtActive(typedUnit->layerHandle);
            mdlSetLookAtRequested(typedUnit->layerHandle);
        }
    }
    return 1;
}

