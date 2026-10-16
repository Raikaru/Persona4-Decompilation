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

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u32 datCalcChkBadStatus(int unit, u32 badStatus);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb3b8;
extern void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);

extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void memset(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 *func_00457120();
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d7c60-001d8010 */

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
/* 680/688 bytes; five resolved relocations and eight zero alignment bytes.
 * Active battle actions receive type-0/1 work from func_0019f5f0 through
 * btlActionSetUnit. Type-2 auxiliary work lives at work+0xA0C instead.
 * This construction contract defines both sides before they are used. */
// FUN_001D7C60
void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4)
{
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
    memset(arg1, 0, 0x30);
    *(u16 *)(arg1 + 0x38) = 0;
    *(u16 *)(arg1 + 0x3A) = 0;
    *(u8 *)(arg1 + 0x3C) = 0;
    *(u8 *)(arg1 + 0x3C) |= 1;
    if (arg0 != NULL) {
        switch (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2)) {
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
    eff = arg2 & 0xFF;
    if ((eff & 1) != 0) {
        mask |= sideA;
    }
    if ((eff & 2) != 0) {
        mask |= sideB;
    }
    if ((eff & 4) != 0) {
        mask |= 4;
    }
    flt = arg3 & 0xFF;
    if ((flt & 1) != 0) {
        *(u8 **)(arg1 + 0) = arg0;
        *(u16 *)(arg1 + 0x38) = 1;
        return;
    }
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    mcopy = mask & 0xFFFF;
    need4 = mcopy & 4;
    needExcl = flt & 2;
    skipDead = flt & 4;
    needAlive = flt & 8;
    while (unit != NULL) {
        if ((arg0 == NULL || (*(u16 *)(unit + 0x1A) & 8) != 0) &&
            (*(u16 *)(unit + 0x1A) & 1) != 0) {
            work = *(u8 **)(unit + 0x30);
            utype = *(u8 *)(work + 0xA2);
            if (utype == 2 || (*(s32 *)(work + 0x9C) & 8) != 0) {
                if ((mcopy & (1 << utype)) != 0) {
                    if (need4 != 0) {
                        goto store;
                    }
                    if (needExcl == 0 || arg0 != unit) {
                        if (skipDead != 0 || datCalcIsDead(*(u8 **)(work + 0xA64), 0) == 0) {
                            if (needAlive != 0) {
                                if (datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), 0x100000) == 0) {
                                    goto next;
                                }
                                goto store;
                            } else if (arg4 == 0 ||
                                ((*(s32 *)(*(u8 **)(work + 0xA64) + 0xC) & 0xFFEFFFFF) != 0 &&
                                 datCalcChkBadStatus((s32)*(u8 **)(work + 0xA64), arg4) == 0)) {
                                goto store;
                            }
                        }
                    }
                    goto next;
store:
                    *(u8 **)(arg1 + (u32)*(u16 *)(arg1 + 0x38) * 4) = unit;
                    *(u16 *)(arg1 + 0x38) = (u16)(*(u16 *)(arg1 + 0x38) + 1);
                }
            }
        }
next:
        unit = *(u8 **)(unit + 0x450);
    }
}

// FUN_001D7F10
u16 btlSkillClassifyTargets(u8 *arg0, u8 *arg1, u16 arg2, u32 arg3)
{
    u32 effect;
    s32 offset;
    u32 bVar4;
    if (arg1 != NULL) {
        offset = (arg2 & 0xFFFF) * 0x28;
        effect = *(u8 *)((u8 *)p4_001d7f10_add(
            offset, (s32)iGpffffb3b8) + 9);
        bVar4 = *(u8 *)((u8 *)(u32)iGpffffb3b8 + offset + 0xA);
        if (arg3 != 0) {
            arg3 = (u8)effect;
            if (((arg3 & 1) != 0) && ((arg3 & 2) == 0)) {
                effect = (u8)(effect & 0xFE);
                effect = (u8)(effect | 2);
            } else if (((arg3 & 2) != 0) && ((arg3 & 1) == 0)) {
                effect = (u8)(effect & 0xFD);
                effect = (u8)(effect | 1);
            }
            if (((u8)bVar4 & 1) != 0) {
                bVar4 = (u8)(bVar4 & 0xFE);
                bVar4 = (u8)(bVar4 | 2);
            }
        }
        func_001d7c60(arg0, arg1, effect, bVar4,
                      *(u16 *)((u8 *)p4_001d7f10_add(
                          (s32)offset, (s32)iGpffffb3b8) + 0xC));
    }
    arg0 = (u8 *)(u32)iGpffffb3b8;
    return (arg0 + (arg2 & 0xFFFF) * 0x28)[8];
}

#pragma push
/* measured: 25 -> 18 -> 11 -> 0. Hoisting retains the live-count bound copies;
 * opt_lifetimes splits the reused gather counters after those bounds. */
/* measured: func_001d8010 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: func_001d8010 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* Select a neighbouring battle target by screen position, facing, or chain order. */
// FUN_001D8010
void func_001d8010(u8 *arg0, u8 *arg1) {
    extern void btlUnitGetSphereWorldCenter(u8 *a0, f32 *a1);
    extern void func_003e42a0(f32 *dst, f32 *src, u8 *cam);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 btlTargetAngleBetween(f32 *a0, f32 *a1, f32 *a2, f32 *a3);
    extern s32 btlEffectCollectGenusMask(u8 *a0);
    extern u8 *func_001d8bc0(u8 *a0);
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
    if (*(u16 *)(arg1 + 0x38) <= 1) {
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
    if ((btlEffectCollectGenusMask(arg1) & 0xFFFF) == 1) {
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

        cam = func_00457120() + 0x20;
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
        while ((i & 0xFFFF) < (s32)*(u16 *)(arg1 + 0x38)) {
            u8 *unit = *(u8 **)(arg1 + ((u16)i * 4));
            u8 *ud = *(u8 **)(unit + 0x30);
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
                u8 *curPtr = func_001d8bc0(arg1);
                for (i = 0; (i & 0xFFFF) < nn; i = (i + 1) & 0xFFFF) {
                    if (entries[(u16)i].unit == curPtr) {
                        break;
                    }
                }
                if ((mode & 0xFFFF) == 5) {
                    if ((i & 0xFFFF) + 1 == nn) {
                        selected = (hasFlag != 0) ? entries[0].idx : *(u16 *)(arg1 + 0x3A);
                    } else {
                        selected = entries[((i & 0xFFFF) + 1) & 0xFFFF].idx;
                    }
                } else {
                    if ((i & 0xFFFF) == 0) {
                        selected = (hasFlag != 0) ? entries[nn - 1].idx : *(u16 *)(arg1 + 0x3A);
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
        btlUnitGetSphereWorldCenter(*(u8 **)(arg0 + 0x30), POS);
        btlUnitGetGroupBounds(btlEffectCollectGenusMask(arg1) & 0xFFFF, 0, (RwV3d *)CENTER, 0, 0, 1);
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
        while ((i & 0xFFFF) < (s32)*(u16 *)(arg1 + 0x38)) {
            u8 *unit = *(u8 **)(arg1 + ((u16)i * 4));
            u8 *ud = *(u8 **)(unit + 0x30);
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
                u8 *curPtr = func_001d8bc0(arg1);
                for (i = 0; (i & 0xFFFF) < nn; i = (i + 1) & 0xFFFF) {
                    if (entries[(u16)i].unit == curPtr) {
                        break;
                    }
                }
                if ((mode & 0xFFFF) == 1) {
                    if ((i & 0xFFFF) + 1 == nn) {
                        selected = (hasFlag != 0) ? entries[0].idx : *(u16 *)(arg1 + 0x3A);
                    } else {
                        selected = entries[((i & 0xFFFF) + 1) & 0xFFFF].idx;
                    }
                } else {
                    if ((i & 0xFFFF) == 0) {
                        selected = (hasFlag != 0) ? entries[nn - 1].idx : *(u16 *)(arg1 + 0x3A);
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
        while ((i & 0xFFFF) < (s32)*(u16 *)(arg1 + 0x38)) {
            unit = *(u8 **)(arg1 + ((u16)i * 4));
            if ((*(u16 *)(unit + 0x1A) & 1) != 0) {
                ud = *(u8 **)(unit + 0x30);
                if (*(u8 *)(ud + 0xA2) == 0) {
                    depth = 0;
                    node = *(u8 **)(D_0076449C + 0x17C);
                    for (; node != 0; node = *(u8 **)(node + 0xA68)) {
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
            u8 *curPtr = func_001d8bc0(arg1);
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
                    selected = (hasFlag != 0) ? entries[0].idx : *(u16 *)(arg1 + 0x3A);
                } else {
                    selected = entries[((i & 0xFFFF) + 1) & 0xFFFF].idx;
                }
            } else {
                if ((i & 0xFFFF) == 0) {
                    selected = (hasFlag != 0) ? entries[nn - 1].idx : *(u16 *)(arg1 + 0x3A);
                } else {
                    selected = entries[((i & 0xFFFF) - 1) & 0xFFFF].idx;
                }
            }
        }
        break;
    }
    }
    if (*(u16 *)(arg1 + 0x3A) != (selected & 0xFFFF)) {
        *(u16 *)(arg1 + 0x3A) = selected;
        *(u8 *)(arg1 + 0x3C) |= 1;
    }
}

