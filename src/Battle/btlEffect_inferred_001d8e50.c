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

extern u16 datCalcMaxHp(u8 *arg0);
extern u16 datCalcMaxSp(u8 *arg0);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u32 datCalcChkBadStatus(int unit, u32 badStatus);
extern u16 datCalcGetHp(u8 *arg0);
extern u16 datCalcGetSp(u8 *arg0);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb3b8;
extern void btlEffectCollectTargetUnits(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);

extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
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

extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d8e50-001d94d0 */

/* measured: opt_propagation off probe for func_001d14b0 loop masks. */
/* measured: close opt_propagation after func_001d14b0 probe. */
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
#pragma push
#pragma pop
// FUN_001D8E50
void func_001d8e50(u8 *arg0, u8 *arg1)
{
    u16 best_value1;
    s16 best_index1;
    u16 best_value2;
    s16 best_index2;
    s32 index;
    u32 offset;
    s32 target;
    u16 value;
    u16 alternate;
    u8 *work;

    if (*(u16 *)(arg1 + 0x38) <= 1)
        return;
    switch (*(u16 *)(arg0 + 0x6C)) {
    case 2:
        goto mode_valid;
    default:
        switch (*(u16 *)(arg0 + 0x6C)) {
        case 3:
            goto mode_valid;
        default:
            switch (*(u16 *)(arg0 + 0x6C)) {
            case 1:
                goto mode_valid;
            default:
                goto mode_done;
            }
        }
    }

mode_valid:

        offset = (u32)*(u16 *)(arg0 + 0x6E) * 0x28;
        {
            u8 *entry;
            entry = (u8 *)((u32)offset + (u32)iGpffffb3b8);
            if (entry[8] != 0)
                return;

            if (entry[0x18] == 2) {
            target = *(s32 *)((u8 *)((u32)iGpffffb3b8 + 0x1C) + offset);
            if (target != 0) {
                index = 0;
                while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                    if (*(u8 **)(arg0 + 0x30) ==
                        *(u8 **)(*(u8 **)(arg1 + (u32)(u16)index * 4) + 0x30) &&
                        datCalcChkBadStatus(
                            (s32)*(u8 **)(*(u8 **)(*(u8 **)(arg1 +
                                                          (u32)(u16)index * 4) +
                                                     0x30) +
                                     0xA64),
                            target) != 0) {
                        *(u16 *)(arg1 + 0x3A) = (u16)index;
                        return;
                    }
                    index = (index + 1) & 0xFFFF;
                }

                index = 0;
                while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                    if (datCalcChkBadStatus(
                            (s32)*(u8 **)(*(u8 **)(*(u8 **)(arg1 +
                                                          (u32)(u16)index * 4) +
                                                     0x30) +
                                     0xA64),
                            target) != 0) {
                        *(u16 *)(arg1 + 0x3A) = (u16)index;
                        return;
                    }
                    index = (index + 1) & 0xFFFF;
                }
            }
        }
        }

        target = *(s32 *)((u8 *)((u32)iGpffffb3b8 + 0x20) + offset);
        if (target != 0) {
            index = 0;
            while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                if (datCalcHasBuffMask(
                        *(u8 **)(*(u8 **)(*(u8 **)(arg1 +
                                                      (u32)(u16)index * 4) +
                                         0x30) +
                                 0xA64),
                        target) == 0) {
                    *(u16 *)(arg1 + 0x3A) = (u16)index;
                    return;
                }
                index = (index + 1) & 0xFFFF;
            }
        }

        switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
        case 15:
            goto mode1_select;
        default:
            switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
            case 11:
                goto mode1_select;
            default:
                switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
                case 9:
                    goto mode1_select;
                default:
                    switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
                    case 5:
                        goto mode1_select;
                    default:
                        switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x11)) {
                        case 2:
                            goto mode1_select;
                        default:
                            goto mode2_check;
                        }
                    }
                }
            }
        }

mode1_select:
        {
            best_value1 = 0xFFFF;
            best_index1 = -1;
            index = 0;
            while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                work = *(u8 **)(*(u8 **)(arg1 + (u32)(u16)index * 4) + 0x30);
                value = datCalcGetHp(*(u8 **)(work + 0xA64));
                alternate = datCalcMaxHp(*(u8 **)(work + 0xA64));
                if (value < best_value1 && value < alternate) {
                    best_value1 = value;
                    best_index1 = (s16)index;
                }
                index = (index + 1) & 0xFFFF;
            }
            if (best_index1 != -1) {
                *(u16 *)(arg1 + 0x3A) = (u16)best_index1;
                return;
            }
        }

mode2_check:
        switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
        case 15:
            goto mode2_select;
        default:
            switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
            case 11:
                goto mode2_select;
            default:
                switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
                case 9:
                    goto mode2_select;
                default:
                    switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
                    case 5:
                        goto mode2_select;
                    default:
                        switch (*(u8 *)((u8 *)((u32)offset + (u32)iGpffffb3b8) + 0x14)) {
                        case 2:
                            goto mode2_select;
                        default:
                            goto mode_done;
                        }
                    }
                }
            }
        }

mode2_select:
        {
            best_value2 = 0xFFFF;
            best_index2 = -1;
            index = 0;
            while ((u16)index < *(u16 *)(arg1 + 0x38)) {
                work = *(u8 **)(*(u8 **)(arg1 + (u32)(u16)index * 4) + 0x30);
                value = datCalcGetSp(*(u8 **)(work + 0xA64));
                alternate = datCalcMaxSp(*(u8 **)(work + 0xA64));
                if (value < best_value2 && value < alternate) {
                    best_value2 = value;
                    best_index2 = (s16)index;
                }
                index = (index + 1) & 0xFFFF;
            }
            if (best_index2 != -1)
                *(u16 *)(arg1 + 0x3A) = (u16)best_index2;
        }

mode_done:
    return;
}

// FUN_001D9280
u8 *func_001d9280(s32 arg0, s32 arg1, s32 arg2) {
    s32 work_flags;
    u8 *unit;
    u8 *work;
    u16 flags;
    u32 mask;
    u32 filter;
    s32 id;

    work_flags = arg2;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    mask = (u16)arg1;
    filter = work_flags & 0x80000;
    id = (u16)arg0;
    goto next_branch;
loop:
    flags = *(u16 *)(unit + 0x1A);
    if ((flags & 1) != 0) {
        if ((flags & 8) != 0) {
            work = *(u8 **)(unit + 0x30);
            if ((mask & (1 << *(u8 *)(work + 0xA2))) != 0) {
                if (filter != 0) {
                    if (datCalcIsDead(*(u8 **)(work + 0xA64), 0) != 0) {
                        goto next;
                    }
                }
                if (datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), work_flags) != 0) {
                    goto next;
                }
                if (*(u16 *)(work + 0xA4) == id) {
                    return unit;
                }
            }
        }
    }
next:
    unit = *(u8 **)(unit + 0x450);
next_branch:
    if (unit != NULL) {
        goto loop;
    }
    return NULL;
}

// FUN_001D9390
int btlSideSelectUnits(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 (*arg5)(u8 *, s32), u8 **arg6) {
    struct Frame {
        u8 *entries[14];
        u16 count;
        u16 unknown3a;
        u8 flags;
    } frame;
    u8 *unit;
    s32 index;
    s32 matches;
    u8 *work;
    u16 flags;

    btlEffectCollectTargetUnits((u8 *)arg0, (u8 *)&frame, arg3, 0, 0);
    matches = 0;
    index = 0;
    goto test;
loop:
    unit = frame.entries[(u16)index];
    flags = *(u16 *)(unit + 0x1A);
    if ((flags & 1) != 0) {
        if ((flags & 8) != 0) {
            work = *(u8 **)(unit + 0x30);
            if (datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), arg2) == 0) {
                if (arg5(unit, arg1) != arg4) {
                    if (arg6 != NULL) {
                        arg6[(u16)matches] = unit;
                    }
                    matches = (matches + 1) & 0xFFFF;
                }
            }
        }
    }
    index = (index + 1) & 0xFFFF;
test:
    if ((u16)index < frame.count) {
        goto loop;
    }
    return matches;
}

// FUN_001D94D0
int func_001d94d0(int param_1, int param_2, int param_3, int param_4, int param_5, code param_6)
{
    u8 *unit;
    u8 *work;
    u16 flags;
    s32 type_mask;
    s32 options;
    s32 option_one;
    s32 option_two;
    s32 option_four_eight;
    s32 option_four_value;
    s32 ignore_dead_value;
    s32 status;
    s32 effects;

    extern s32 datCalcElementBit(s16 arg0);
    extern s8 datCalcGetBuffStatus(u8 *arg0, s32 arg1);
    extern s32 func_001f9ce0(u8 *arg0, s32 arg1);
    extern s32 func_0010f420(u16 arg0, u16 arg1);

    (void)param_1;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    type_mask = (u16)param_3;
    options = (u16)param_5;
    option_one = options & 1;
    option_two = options & 2;
    option_four_eight = options & 0xC;
    option_four_value = options & 4;
    ignore_dead_value = param_4 & 0x80000;
    goto test;

loop:
    flags = *(u16 *)(unit + 0x1A);
    if ((flags & 1) != 0 && (flags & 8) != 0) {
        work = *(u8 **)(unit + 0x30);
        if ((type_mask & (1 << *(u8 *)(work + 0xA2))) != 0) {
            if (options == 0)
                goto check_general;
            if (option_one != 0 &&
                datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), 0x100000) == 0)
                goto next;
            if (option_two != 0) {
                status = datCalcElementBit((s16)param_2);
                if ((status & 0xE0001) == 0) {
                    if ((status & 2) != 0) {
                        effects = datCalcGetBuffStatus(*(u8 **)(work + 0xA64), 0x10);
                        if (effects > 0)
                            goto next;
                    } else if ((status & 0x40) == 0) {
                        effects = datCalcGetBuffStatus(*(u8 **)(work + 0xA64), 0x11);
                        if (effects > 0)
                            goto next;
                    }
                }
            }
            if (option_four_eight != 0 &&
                *(u8 *)(work + 0xA2) == 1 &&
                func_001f9ce0(unit, (s16)param_2) == 0 &&
                func_0010f420(*(u16 *)(work + 0xA4), (u16)param_2) == 0) {
                if (option_four_value != 0)
                    goto next;
                return 1;
            }
check_general:
            if ((ignore_dead_value == 0 ||
                 datCalcIsDead(*(u8 **)(work + 0xA64), 0) == 0) &&
                datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), param_4) == 0 &&
                param_6(unit, param_2) != 0)
                return 1;
        }
    }
next:
    unit = *(u8 **)(unit + 0x450);
test:
    if (unit != NULL)
        goto loop;
    return 0;
}

