#include "member_access.h"
#include "dat_skill_entry_internal.h"
#include "btl_effect_internal.h"
#include "btl_action_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"


extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 datCalcIsDead(u8 *unit, s32 hpDelta);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern u32 datCalcChkBadStatus(int unit, u32 badStatus);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb3b8;
extern void btlEffectCollectTargetUnits(u8 *action, u8 *selection, u32 sideFlags, u32 filterFlags, u32 statusMask);

extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *dst);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 input, s32 value);
extern void memset(u8 *input, s32 value, s32 options);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 *kwlnGetCamera();
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d7c60-001d8010 */

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
/* 680/688 bytes; five resolved relocations and eight zero alignment bytes.
 * Active battle actions receive type-0/1 work from func_0019f5f0 through
 * btlActionSetUnit. Type-2 auxiliary work lives at work+0xA0C instead.
 * This construction contract defines both sides before they are used. */
/* Collect active actions selected by relative side, self-exclusion, death and status filters into the target array. */
// FUN_001D7C60
void btlEffectCollectTargetUnits(u8 *action, u8 *selection, u32 sideFlags, u32 filterFlags, u32 statusMask)
{
    BtlTargetSelection *targetSelection = (BtlTargetSelection *)(selection);
    u16 sideA;
    u16 sideB;
    u16 mask;
    s32 eff;
    s32 flt;
    s32 mcopy;
    s32 need4;
    s32 needExcl;
    s32 skipDead;
    s32 needAlive;
    u8 *unit;
    u8 *work;
    u8 utype;
    memset(selection, 0, 0x30);
    ((BtlTargetSelection *)(selection))->count = 0;
    ((BtlTargetSelection *)(selection))->selected = 0;
    ((BtlTargetSelection *)(selection))->flags = 0;
    ((BtlTargetSelection *)(selection))->flags |= 1;
    if (action != NULL) {
        switch (((BtlUnit *)(*(u8 * *)&((BtlAction *)(action))->unit))->genus) {
        case 0:
            sideA = 1;
            sideB = 2;
            break;
        case 1:
            sideA = 2;
            sideB = 1;
            break;
        }
    } else {
        sideA = 1;
        sideB = 2;
    }
    mask = 0;
    eff = sideFlags & 0xFF;
    if ((eff & 1) != 0) {
        mask |= sideA;
    }
    if ((eff & 2) != 0) {
        mask |= sideB;
    }
    if ((eff & 4) != 0) {
        mask |= 4;
    }
    flt = filterFlags & 0xFF;
    if ((flt & 1) != 0) {
        ((BtlTargetSelection *)(selection))->entries[0] = action;
        targetSelection->count = 1;
        return;
    }
    unit = ((BtlBattleState *)(iGpffffb3ac))->actions;
    mcopy = mask & 0xFFFF;
    need4 = mcopy & 4;
    needExcl = flt & 2;
    skipDead = flt & 4;
    needAlive = flt & 8;
    while (unit != NULL) {
        if ((action == NULL || (((BtlAction *)(unit))->unk_1a & 8) != 0) &&
            (((BtlAction *)(unit))->unk_1a & 1) != 0) {
            work = *(u8 * *)&((BtlAction *)(unit))->unit;
            utype = ((BtlUnit *)(work))->genus;
            if (utype == 2 || (*(s32 *)&((BtlUnit *)(work))->flags3 & 8) != 0) {
                if ((mcopy & (1 << utype)) != 0) {
                    if (need4 != 0) {
                        goto store;
                    }
                    if (needExcl == 0 || action != unit) {
                        if (skipDead != 0 || datCalcIsDead(*(u8 * *)&((BtlUnit *)(work))->datUnit, 0) == 0) {
                            if (needAlive != 0) {
                                if (datCalcChkBadStatus((s32)*(u8 * *)&((BtlUnit *)(work))->datUnit, 0x100000) == 0) {
                                    goto next;
                                }
                                goto store;
                            } else if (statusMask == 0 ||
                                ((*(s32 *)&((DatUnit *)(*(u8 * *)&((BtlUnit *)(work))->datUnit))->bad & 0xFFEFFFFF) != 0 &&
                                 datCalcChkBadStatus((s32)*(u8 * *)&((BtlUnit *)(work))->datUnit, statusMask) == 0)) {
                                goto store;
                            }
                        }
                    }
                    goto next;
store:
                    ((BtlTargetSelection *)(selection))->entries[((u32)((BtlTargetSelection *)(selection))->count * 4)/4] = unit;
                    ((BtlTargetSelection *)(selection))->count = (u16)(((BtlTargetSelection *)(selection))->count + 1);
                }
            }
        }
next:
        unit = *(u8 * *)&((BtlAction *)(unit))->next;
    }
}

/* Read the skill's target classification and optionally gather its targets, reversing relative-side filters when requested. */
// FUN_001D7F10
u16 btlSkillClassifyTargets(u8 *action, u8 *selection, u16 skillId, u32 reverseSides)
{
    u32 effect;
    s32 offset;
    u32 filterFlags;
    if (selection != NULL) {
        offset = (skillId & 0xFFFF) * 0x28;
        effect = ((DatSkillEntry *)((u8 *)((offset) + ((s32)iGpffffb3b8))))->targetSides;
        filterFlags = ((DatSkillEntry *)((u8 *)(u32)iGpffffb3b8 + offset))->targetFilter;
        if (reverseSides != 0) {
            reverseSides = (u8)effect;
            if (((reverseSides & 1) != 0) && ((reverseSides & 2) == 0)) {
                effect = (u8)(effect & 0xFE);
                effect = (u8)(effect | 2);
            } else if (((reverseSides & 2) != 0) && ((reverseSides & 1) == 0)) {
                effect = (u8)(effect & 0xFD);
                effect = (u8)(effect | 1);
            }
            if (((u8)filterFlags & 1) != 0) {
                filterFlags = (u8)(filterFlags & 0xFE);
                filterFlags = (u8)(filterFlags | 2);
            }
        }
        btlEffectCollectTargetUnits(action, selection, effect, filterFlags,
                      ((DatSkillEntry *)((u8 *)(((s32)offset) + ((s32)iGpffffb3b8))))->excludedStatus);
    }
    action = (u8 *)(u32)iGpffffb3b8;
    return (action + (skillId & 0xFFFF) * 0x28)[8];
}

#pragma push
/* measured: 25 -> 18 -> 11 -> 0. Hoisting retains the live-count bound copies;
 * opt_lifetimes splits the reused gather counters after those bounds. */
/* measured: btlEffectSelectNeighbourTarget MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: btlEffectSelectNeighbourTarget MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* Select a neighbouring battle target by screen position, facing, or chain order. */
/* measured: site, typed-local, array and explicit member-address forms lose MATCH
 * on the party-tail reload; MEMBER retains the original global byte-cursor alias domain. */
// FUN_001D8010
void btlEffectSelectNeighbourTarget(u8 *action, u8 *selection) {
    BtlTargetSelection *targetSelection = (BtlTargetSelection *)(selection);
    extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *dst);
    extern void func_003e42a0(f32 *dst, f32 *src, u8 *cam);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 btlTargetAngleBetween(f32 *first, f32 *second, f32 *point, f32 *projection);
    extern s32 btlEffectCollectGenusMask(u8 *selection);
    extern u8 *btlFormationCurrentEntry(u8 *formation);
    extern u16 D_008C027A[];
    extern u16 D_008C0276[];
    extern u8 D_00881430[];
    extern u8 *D_0076449C;
    typedef struct {
        u8 *unit;
        u16 idx;
        u16 chain;
        f32 score;
    } Entry;
    f32 stk[24];
    Entry entries[12];
    u16 mode;
    s32 i;
    u16 selected;
    s32 hasFlag;
    s32 n;
#define PROJ (&stk[4])
#define POS (&stk[12])
#define CENTER (&stk[8])
#define BASEXZ (&stk[0])
#define CENTERXZ (&stk[2])
#define CURXZ (&stk[22])
#define OUTXZ (&stk[20])
#define DELTA (&stk[18])
#define DIR (&stk[16])
    if (((BtlTargetSelection *)(selection))->count <= 1) {
        return;
    }
    if (D_008C027A[0] & 0x2000) {
        mode = 5;
        hasFlag = (D_008C0276[0] & 0x2000) != 0;
    } else if (D_008C027A[0] & 0x8000) {
        mode = 4;
        hasFlag = (D_008C0276[0] & 0x8000) != 0;
    } else if (D_008C027A[0] & 0x1000) {
        mode = 2;
        hasFlag = (D_008C0276[0] & 0x1000) != 0;
    } else if (D_008C027A[0] & 0x4000) {
        mode = 3;
        hasFlag = (D_008C0276[0] & 0x4000) != 0;
    } else {
        return;
    }
    if ((btlEffectCollectGenusMask(selection) & 0xFFFF) == 1) {
        switch (mode) {
        case 0:
        case 4:
            mode = 2;
            break;
        case 1:
        case 5:
            mode = 3;
            break;
        }
    }
    switch (mode & 0xFFFF) {
    case 4:
    case 5: {
        u8 *cam;

        cam = kwlnGetCamera() + 0x20;
        func_003e42a0(PROJ, (f32 *)D_00881430, cam);
        if (PROJ[2] != 0.0f) {
            stk[20] = 640.0f * (PROJ[0] / PROJ[2]);
            stk[21] = 448.0f * (PROJ[1] / PROJ[2]);
        } else {
            stk[20] = 640.0f * PROJ[0];
            stk[21] = 448.0f * PROJ[1];
        }
        selected = 0;
        i = 0;
        while ((i & 0xFFFF) < (s32)targetSelection->count) {
            u8 *unit = ((BtlTargetSelection *)selection)->entries[(u16)i];
            u8 *ud = *(u8 * *)&((BtlAction *)(unit))->unit;
            f32 len;
            btlUnitGetSphereWorldCenter(ud, POS);
            func_003e42a0(PROJ, POS, cam);
            if (PROJ[2] != 0.0f) {
                stk[22] = 640.0f * (PROJ[0] / PROJ[2]);
                stk[23] = 448.0f * (PROJ[1] / PROJ[2]);
            } else {
                /* Retail overwrites the anchor; stk[22..23] remain stale or unset. */
                stk[20] = 640.0f * PROJ[0];
                stk[21] = 448.0f * PROJ[1];
            }
            DELTA[0] = stk[22] - stk[20];
            DELTA[1] = stk[23] - stk[21];
            len = func_003e41e0(DELTA, DELTA);
            if (0.0f >= DELTA[0]) {
                entries[selected & 0xFFFF].score = len;
            } else {
                entries[selected & 0xFFFF].score = -len;
            }
            entries[selected & 0xFFFF].unit = unit;
            entries[selected & 0xFFFF].idx = (u16)i;
            selected++;
            i = (i + 1) & 0xFFFF;
        }
        {
            s32 swapped;
            s32 nn = selected & 0xFFFF;
            do {
                swapped = 0;
                i = 0;
                while ((i & 0xFFFF) < selected - 1) {
                    if (entries[(u16)i].score < entries[(i & 0xFFFF) + 1].score) {
                        u8 *tp = entries[(u16)i].unit;
                        u16 ti = entries[(u16)i].idx;
                        f32 ts = entries[(u16)i].score;
                        entries[(u16)i].unit = entries[(i & 0xFFFF) + 1].unit;
                        entries[(u16)i].idx = entries[(i & 0xFFFF) + 1].idx;
                        entries[(u16)i].score = entries[(i & 0xFFFF) + 1].score;
                        entries[(i & 0xFFFF) + 1].unit = tp;
                        entries[(i & 0xFFFF) + 1].idx = ti;
                        entries[(i & 0xFFFF) + 1].score = ts;
                        swapped = 1;
                    }
                    i = (i + 1) & 0xFFFF;
                }
            } while (swapped != 0);
            {
                u8 *curPtr = btlFormationCurrentEntry(selection);
                for (i = 0; (i & 0xFFFF) < nn; i = (i + 1) & 0xFFFF) {
                    if (entries[(u16)i].unit == curPtr) {
                        break;
                    }
                }
                if ((mode & 0xFFFF) == 5) {
                    if ((i & 0xFFFF) + 1 == nn) {
                        selected = (hasFlag != 0) ? entries[0].idx : ((BtlTargetSelection *)(selection))->selected;
                    } else {
                        selected = entries[((i & 0xFFFF) + 1) & 0xFFFF].idx;
                    }
                } else {
                    if ((i & 0xFFFF) == 0) {
                        selected = (hasFlag != 0) ? entries[nn - 1].idx : ((BtlTargetSelection *)(selection))->selected;
                    } else {
                        selected = entries[((i & 0xFFFF) - 1) & 0xFFFF].idx;
                    }
                }
            }
        }
        break;
    }
    case 0:
    case 1: {
        btlUnitGetSphereWorldCenter(*(u8 * *)&((BtlAction *)(action))->unit, POS);
        btlUnitGetGroupBounds(btlEffectCollectGenusMask(selection) & 0xFFFF, 0, (RwV3d *)CENTER, 0, 0, 1);
        BASEXZ[0] = POS[0];
        BASEXZ[1] = POS[2];
        CENTERXZ[0] = CENTER[0];
        CENTERXZ[1] = CENTER[2];
        DELTA[0] = POS[0] - CENTER[0];
        DELTA[1] = POS[2] - CENTER[2];
        DIR[0] = DELTA[1];
        DIR[1] = -DELTA[0];
        func_003e41e0(DIR, DIR);
        selected = 0;
        i = 0;
        while ((i & 0xFFFF) < (s32)targetSelection->count) {
            u8 *unit = ((BtlTargetSelection *)selection)->entries[(u16)i];
            u8 *ud = *(u8 * *)&((BtlAction *)(unit))->unit;
            f32 dist;
            f32 dot;
            btlUnitGetSphereWorldCenter(ud, POS);
            CURXZ[0] = POS[0];
            CURXZ[1] = POS[2];
            dist = btlTargetAngleBetween(BASEXZ, CENTERXZ, CURXZ, OUTXZ);
            DELTA[0] = CURXZ[0] - OUTXZ[0];
            DELTA[1] = CURXZ[1] - OUTXZ[1];
            func_003e41e0(DELTA, DELTA);
            dot = DELTA[0] * DIR[0] + DELTA[1] * DIR[1];
            if (0.0f >= dot) {
                entries[selected & 0xFFFF].score = dist;
            } else {
                entries[selected & 0xFFFF].score = -dist;
            }
            entries[selected & 0xFFFF].unit = unit;
            entries[selected & 0xFFFF].idx = (u16)i;
            selected++;
            i = (i + 1) & 0xFFFF;
        }
        {
            s32 swapped;
            s32 nn = selected & 0xFFFF;
            do {
                swapped = 0;
                i = 0;
                while ((i & 0xFFFF) < selected - 1) {
                    if (entries[(u16)i].score < entries[(i & 0xFFFF) + 1].score) {
                        u8 *tp = entries[(u16)i].unit;
                        u16 ti = entries[(u16)i].idx;
                        f32 ts = entries[(u16)i].score;
                        entries[(u16)i].unit = entries[(i & 0xFFFF) + 1].unit;
                        entries[(u16)i].idx = entries[(i & 0xFFFF) + 1].idx;
                        entries[(u16)i].score = entries[(i & 0xFFFF) + 1].score;
                        entries[(i & 0xFFFF) + 1].unit = tp;
                        entries[(i & 0xFFFF) + 1].idx = ti;
                        entries[(i & 0xFFFF) + 1].score = ts;
                        swapped = 1;
                    }
                    i = (i + 1) & 0xFFFF;
                }
            } while (swapped != 0);
            {
                u8 *curPtr = btlFormationCurrentEntry(selection);
                for (i = 0; (i & 0xFFFF) < nn; i = (i + 1) & 0xFFFF) {
                    if (entries[(u16)i].unit == curPtr) {
                        break;
                    }
                }
                if ((mode & 0xFFFF) == 1) {
                    if ((i & 0xFFFF) + 1 == nn) {
                        selected = (hasFlag != 0) ? entries[0].idx : ((BtlTargetSelection *)(selection))->selected;
                    } else {
                        selected = entries[((i & 0xFFFF) + 1) & 0xFFFF].idx;
                    }
                } else {
                    if ((i & 0xFFFF) == 0) {
                        selected = (hasFlag != 0) ? entries[nn - 1].idx : ((BtlTargetSelection *)(selection))->selected;
                    } else {
                        selected = entries[((i & 0xFFFF) - 1) & 0xFFFF].idx;
                    }
                }
            }
        }
        break;
    }
    case 2:
    case 3: {
        u8 *unit;
        u8 *ud;
        u8 *node;
        /* Keep the halfword depth wrap; its finished lifetime becomes the swap flag. */
        s32 depth;

        n = 0;
        i = 0;
        while ((i & 0xFFFF) < (s32)targetSelection->count) {
            unit = ((BtlTargetSelection *)selection)->entries[(u16)i];
            if ((((BtlAction *)(unit))->unk_1a & 1) != 0) {
                ud = *(u8 * *)&((BtlAction *)(unit))->unit;
                if (((BtlUnit *)(ud))->genus == 0) {
                    depth = 0;
                    node = MEMBER(u8 *, D_0076449C, BtlBattleState, unitLists[1]);
                    for (; node != 0; node = *(u8 * *)&((BtlUnit *)(node))->prevUnit) {
                        if (node == ud) {
                            break;
                        }
                        depth = (depth + 1) & 0xFFFF;
                    }
                    entries[n & 0xFFFF].unit = unit;
                    entries[n & 0xFFFF].idx = (u16)i;
                    entries[n & 0xFFFF].chain = depth;
                    n = (n + 1) & 0xFFFF;
                }
            }
            i = (i + 1) & 0xFFFF;
        }
        if ((n & 0xFFFF) == 0) {
            return;
        }
        if ((n & 0xFFFF) >= 2) {
            do {
                depth = 0;
                i = 0;
                while ((i & 0xFFFF) < (n & 0xFFFF) - 1) {
                    if (entries[(u16)i].chain < entries[(i & 0xFFFF) + 1].chain) {
                        u8 *tp = entries[(u16)i].unit;
                        u16 tc;

                        selected = entries[(u16)i].idx;
                        tc = entries[(u16)i].chain;
                        entries[(u16)i].unit = entries[(i & 0xFFFF) + 1].unit;
                        entries[(u16)i].idx = entries[(i & 0xFFFF) + 1].idx;
                        entries[(u16)i].chain = entries[(i & 0xFFFF) + 1].chain;
                        entries[(i & 0xFFFF) + 1].unit = tp;
                        entries[(i & 0xFFFF) + 1].idx = selected;
                        entries[(i & 0xFFFF) + 1].chain = tc;
                        depth = 1;
                    }
                    i = (i + 1) & 0xFFFF;
                }
            } while (depth != 0);
        }
        {
            u8 *curPtr = btlFormationCurrentEntry(selection);
            s32 nn = n & 0xFFFF;
            for (i = 0; (i & 0xFFFF) < nn; i = (i + 1) & 0xFFFF) {
                if (entries[(u16)i].unit == curPtr) {
                    break;
                }
            }
            if ((i & 0xFFFF) == nn) {
                /* Retail reads the index saved by the last swap; unset if none ran. */
                break;
            }
            if ((mode & 0xFFFF) == 2) {
                if ((i & 0xFFFF) + 1 == nn) {
                    selected = (hasFlag != 0) ? entries[0].idx : ((BtlTargetSelection *)(selection))->selected;
                } else {
                    selected = entries[((i & 0xFFFF) + 1) & 0xFFFF].idx;
                }
            } else {
                if ((i & 0xFFFF) == 0) {
                    selected = (hasFlag != 0) ? entries[nn - 1].idx : ((BtlTargetSelection *)(selection))->selected;
                } else {
                    selected = entries[((i & 0xFFFF) - 1) & 0xFFFF].idx;
                }
            }
        }
        break;
    }
    }
    if (((BtlTargetSelection *)(selection))->selected != (selected & 0xFFFF)) {
        targetSelection->selected = selected;
        ((BtlTargetSelection *)(selection))->flags |= 1;
    }
}

/* Restore the scoped target-selection settings at the end of this unit. */
#pragma pop
