#include "btl_effect_internal.h"
#include "btl_action_internal.h"
#include "rw_types_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 datCalcIsDead(u8 *unit, s32 hpDelta);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb3b8;

extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 input, s32 value);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();









extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d8c00-001d8cb0 */

/* measured: opt_propagation off probe for btlCameraFindFormationForCounts loop masks. */
/* measured: close opt_propagation after btlCameraFindFormationForCounts probe. */
#pragma push
#pragma pop
/* measured: optimization_level 1 probe for func_001d5990 stack reload scheduling. */
/* measured: restore optimization_level 2 after func_001d5990. */
#pragma push
#pragma pop
/* measured: opt_propagation off is required for the default GP load/store register order. */
/* measured: close opt_propagation after btlEffectFlagToColor. */
#pragma push
/* measured: 25 -> 18 -> 11 -> 0. Hoisting retains the live-count bound copies;
 * opt_lifetimes splits the reused gather counters after those bounds. */
#pragma pop
/* Find an active, living action whose UID matches the remembered selection key. */
// FUN_001D8C00
u8 *btlEffectFindUnitByKey(u8 *selection)
{
    u16 flags;
    u8 *data;
    u8 *unit;

    unit = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (unit != NULL) {
        flags = ((BtlAction *)unit)->unk_1a;
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            data = *(u8 * *)&((BtlUnit *)((u8 *)((BtlAction *)unit)->unit))->datUnit;
            if ((data == NULL || datCalcIsDead(data, 0) == 0) &&
                *(s64 *)unit == (s64)((BtlTargetSelection *)selection)->key) {
                return unit;
            }
        }
        unit = (u8 *)((BtlAction *)unit)->next;
    }
    return NULL;
}

/* Recovered from docs/probe_archive/R1EE_001d8cb0_body.c by swapping the
   two operands of the nearest-target test: retail emits the float
   comparison first (`c.olt.s`, `bc1t`, then `beqz` on the first-entry
   flag), so the source reads `(temp_f0 < var_f20) || (first != 0)`.
   That order reads the best distance before the first iteration has
   written it, which is exactly what retail does; the defensive order
   this floor used to carry - first-entry guard first, to avoid the
   uninitialised read - was the whole residual. */
/* Preserve a remembered UID when present; otherwise select the nearest target to the acting unit.
 * Empty selections and a missing action leave the cursor at zero. */
// FUN_001D8CB0
#pragma push
/* measured: btlEffectSelectNearestEntry MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 btlEffectSelectNearestEntry(u8 *action, u8 *targets)
{
    struct BtlUnit;
    struct BtlAction {
        u64 uid;
        u8 unknown08[4];
        u16 currState;
        u16 pendingState;
        u16 oldState;
        u16 pendingStateTimer;
        u16 state;
        u16 unknown16;
        u16 unknown18;
        u16 unknown1a;
        u32 stateTimer;
        u8 unknown20[0x10];
        struct BtlUnit *unit;
    };
    struct DistanceSelection {
        struct BtlAction *entries[12];
        u64 key;
        u16 count;
        u16 selected;
        u8 flags;
    };
    extern void btlUnitGetGridSphereCenter(struct BtlUnit *unit, struct RwV3d *dst);
    extern f32 btlTargetVectorDistance(const struct RwV3d *first, const struct RwV3d *second);
    struct RwV3d origin;
    struct RwV3d targetPosition;
    f32 distance;
    f32 bestDistance;
    struct DistanceSelection *selection = (struct DistanceSelection *)targets;
    s32 first;
    s32 index;
    selection->selected = 0;
    {
        u64 key;
        u16 key_index;
        key = selection->key;
        if (key != 0) {
            key_index = 0;
            while (key_index < selection->count) {
                if (key == selection->entries[key_index]->uid) {
                    selection->selected = key_index;
                    return 1;
                }
                key_index++;
            }
        }
    }
    if (action == NULL)
        goto return_one;
    first = 1;
    btlUnitGetGridSphereCenter(((struct BtlAction *)action)->unit, &origin);
    index = 0;
    goto distance_test;
distance_loop:
    btlUnitGetGridSphereCenter(selection->entries[index & 0xFFFF]->unit, &targetPosition);
    distance = btlTargetVectorDistance(&origin, &targetPosition);
    if ((distance < bestDistance) || (first != 0)) {
        selection->selected = (u16)index;
        bestDistance = distance;
        first = 0;
    }
    index = (index + 1) & 0xFFFF;
distance_test:
    if ((u16)index < selection->count)
        goto distance_loop;
return_one:
    return 1;
}

/* Restore the scoped nearest-target loop setting at the end of this unit. */
#pragma pop
