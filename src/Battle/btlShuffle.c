/* Original translation unit btlShuffle.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "btl_shuffle_draw_internal.h"


extern void btlShuffleDrawTaskUpdate(u8 *arg0);

extern void btlShuffleDrawQueueCardsB(u8 *arg0);

extern u16 *kwlnTaskGetWork();

extern s32 kwlnTaskGetTaskByName(void *arg0);

extern u32 datCalcRandomBelow(u32 max);

extern void kAssertFail(const void *file, s32 line);

extern u8 D_0064E5D0[];

extern u8 D_0064E610[];

extern u8 D_0064E790[];

extern void chkmemAllocSiteTag(const void *file, s32 line);

extern void *(*jtbl_008873E8[])(u32 size, u32 align);

extern void memset(void *dst, s32 value, s32 size);



extern void pscResInitScene(u8 *arg0, s32 arg1);

extern void btlShuffleDrawSetup(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void btlShuffleRandomizeOrder(u8 *arg0, u8 *arg1);

extern u8 D_0064E7A0[];

extern s32 btlShuffleTaskUpdate(u8 *task);

extern void btlShuffleTaskDestroy(u8 *task);

extern u16 datCalcMaxHpById(s16 character);

extern void datSetUnitHp(s16 character, s16 value);

extern u32 datCalcIsDeadById(s16 param);

extern s32 datGetPartyId();

extern u16 datCalcMaxSpById(s16 character);

extern u32 datCalcGetSpById(s16 character);

extern void datSetUnitSp(s16 character, s16 value);

extern u8 D_0064E5F0[];

extern u8 D_0064E5F1[];

extern u32 RpRandom();

extern s32 datPersonaRosterCapacity();

extern s32 datPersonaGetLeadSlot();

extern s32 datPersonaRosterSlotActive(s16 slot);

extern s32 datPersonaFindRosterSlotById();

extern u16 *datPersonaRosterSlot(s16 slot);

extern s32 datPersonaGetLevel();

extern void datPersonaRemoveRosterMemberById();

extern u8 *datPersonaAddRosterMember(u16 personaId);

extern u8 *iGpffffb3c0;

extern u8 *iGpffffb3f0;
extern u8 *iGpffffb3e0;
extern u8 *iGpffffb3ec;
extern u16 *datPersonaGetSkills(int persona);
extern s32 datPersonaReplaceSkill(u8 *arg0, s16 arg1, u16 arg2);

extern s32 D_0064E7B0[];

extern u16 D_0064E7B4[];

extern u16 D_0064E7B6[];

extern s32 D_0064E7B8[];

extern void func_00106550(s32 arg0, u32 arg1);

extern s32 datGetFlag(s32 id);

extern void datSetFlag(s32 a, s32 b);

extern void pscResTeardown(u8 *arg0);

extern void btlShuffleDrawRelease(u8 *arg0);

extern void (*jtbl_008873EC[])(void *ptr);

extern u8 D_0064E780[];

extern u8 D_0064E650[];

extern u8 D_0064E670[];

extern u8 D_0064E6A0[];
extern u16 datPersonaCountValidMembers(void);
extern u8 datPersonaGetStat(u8 *arg0, u16 arg1);
extern u8 datPersonaGetBuffedStat(u8 *arg0, u16 arg1);
extern s32 datPersonaAddStat(u8 *arg0, u16 arg1, s8 arg2);
extern u8 D_00793E80[];

extern s32 iGpffffa9c0;

extern void PrimAppendNode(u8 *arg0, u8 *arg1);

extern void btlShuffleDrawLoadSprites(u8 *arg0);

extern s32 btlShuffleDrawLoadBlob(u8 *arg0);

extern void btlShuffleDrawTaskInit(u8 *arg0, u8 *arg1);

extern s32 pscResIsIdle(void);

extern void btlShuffleDrawViewRestore(u8 *arg0);

extern void btlShuffleDrawFrame(u8 *arg0);

extern s32 btlEncounterIsActive(void);

extern s32 btlShuffleSeqCardTask(u8 *arg0);

extern u8 nmMesWindowOpenCurrent(u8 *message);

extern void nmMesWindowShowCurrentRecord(s32 arg0);

extern void nmMesWindowStepCurrent(s32 arg0);

extern s32 nmMesWindowCurrentOpenState(void);

extern void nmMesWindowCloseCurrent(s32 arg0);

extern void nmMesWindowResetCurrent(void);

extern void btlShuffleSeqClearA(u8 *arg0, s32 arg1);

extern s32 btlShuffleSeqFlag(u8 *arg0);



// FUN_0036E140
s32 btlShuffleTaskUpdate(u8 *unusedTask)
{
    u8 *work = (u8 *)kwlnTaskGetWork();
    s32 i;
    u16 flags;
    u16 cnt;

    for (i = 0; i < 2; i++) {
        u8 *p = work + i * 0x30;
        *(s32 *)(p + 0xC) = 0;
        *(s32 *)(p + 0x10) = 0;
        PrimAppendNode((u8 *)D_00793E80 + *(s32 *)((u8 *)&iGpffffa9c0 + i * 4) * 0x30, p + 0xC);
    }
    switch (*(s32 *)(work + 8)) {
    case 0:
        *(s32 *)(work + 8) = 1;
        break;
    case 1:
        flags = *(u16 *)work;
        if ((flags & 1) != 0) {
            if ((flags & 8) != 0) {
                goto case2_body;
            }
        }
        if ((flags & 4) == 0) {
            break;
        }
        if (((flags & 0x10) == 0) && ((flags & 0x80) == 0)) {
            btlShuffleDrawLoadSprites(work + 0x70);
            *(u16 *)work |= 0x80;
        }
        if (((*(u16 *)work) & 0x80) != 0) {
            if (btlShuffleDrawLoadBlob(work + 0x70) != 0) {
                *(u16 *)work |= 0x10;
                *(u16 *)work &= (u16)~0x80;
            }
        }
        flags = *(u16 *)work;
        if (((flags & 0x20) == 0) && ((flags & 0x40) == 0) && ((flags & 0x10) != 0)) {
            btlShuffleDrawTaskInit(work + 0x70, work + 0x1F2C0);
            *(u16 *)work |= 0x40;
        }
        if (((*(u16 *)work) & 0x40) != 0) {
            if (pscResIsIdle() != 0) {
                *(u16 *)work |= 0x20;
                *(u16 *)work &= (u16)~0x40;
            }
        }
        flags = *(u16 *)work;
        if (((flags & 0x10) != 0) && ((flags & 0x20) != 0)) {
            *(u16 *)work = flags | 8;
            *(u16 *)work &= (u16)~4;
        }
        break;
    case 2:
case2_body:
        btlShuffleDrawViewRestore(work + 0x70);
        *(s32 *)(work + 8) = 3;
        /* fallthrough */
    case 3:
        btlShuffleDrawFrame(work + 0x70);
        *(u16 *)work |= 2;
        if (datGetFlag(0x1430) == 0) {
            *(s32 *)(work + 4) = 0;
            *(s32 *)(work + 8) = 7;
            break;
        }
        *(s32 *)(work + 8) = 4;
        /* fallthrough */
    case 4:
        if (((*(u16 *)work) & 0x100) == 0) {
            if (btlEncounterIsActive() != 0) {
                break;
            }
            *(u16 *)work |= 0x100;
        }
        if (btlShuffleSeqCardTask(work + 0x70) != 0) {
            *(u16 *)work &= (u16)~1;
            *(s32 *)(work + 8) = 6;
        }
        break;
    case 5:
        cnt = ++*(u16 *)(work + 2);
        if ((cnt & 0xFFFF) < 0xA) {
            break;
        }
        return -1;
    case 6:
        break;
    case 7:
        if (btlEncounterIsActive() != 0) {
            break;
        }
        cnt = ++*(u16 *)(work + 2);
        if ((cnt & 0xFFFF) < 0x1E) {
            break;
        }
        *(u16 *)(work + 2) = 0;
        nmMesWindowOpenCurrent((u8 *)(*(s32 *)(work + 0x1F354)));
        nmMesWindowShowCurrentRecord(0);
        *(s32 *)(work + 8) = 8;
        /* fallthrough */
    case 8:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            {
                s32 t = *(s32 *)(work + 4) + 1;
                *(s32 *)(work + 4) = t;
                if (t < 4) {
                    nmMesWindowShowCurrentRecord(*(s32 *)(work + 4));
                } else {
                    nmMesWindowResetCurrent();
                    btlShuffleSeqClearA(work + 0x70, 0);
                    *(s32 *)(work + 8) = 9;
                }
            }
        }
        break;
    case 9:
        if (btlShuffleSeqFlag(work + 0x70) == 0) {
            break;
        }
        cnt = ++*(u16 *)(work + 2);
        if ((cnt & 0xFFFF) < 0x1E) {
            break;
        }
        *(s32 *)(work + 8) = 4;
        break;
    default:
        kAssertFail(D_0064E790, 0x178);
        break;
    }
    return 0;
}

// FUN_0036E580
void btlShuffleQueueDraw(u8 *arg0, u16 *arg1)
{
    if (*arg1 & 2) {
        btlShuffleDrawTaskUpdate((u8 *)arg1 + 0x70);
    }
}



// FUN_0036E5C0
void btlShuffleQueueSeqDraw(u8 *arg0, u16 *arg1)
{
    if (*arg1 & 2) {
        btlShuffleDrawQueueCardsB((u8 *)arg1 + 0x70);
    }
}

// FUN_0036E600
void btlShuffleTaskDestroy(u8 *unusedTask)
{
    u8 *work = (u8 *)kwlnTaskGetWork();

    if (datGetFlag(0x1430) == 0) {
        datSetFlag(0x1430, 1);
    }
    pscResTeardown(work + 0x1F384);
    btlShuffleDrawRelease(work + 0x70);
    jtbl_008873EC[0](work);
}

// FUN_0036E690
s32 btlShuffleTaskCreate(u8 *arg0, u8 *arg1)
{
    u8 *work;
    s32 handle;
    s32 tmp;

    chkmemAllocSiteTag(D_0064E7A0, 0x3A);
    work = (u8 *)(*jtbl_008873E8)(0x21ABC, 0x40000);
    memset(work, 0, 0x21ABC);
    handle = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0064E780), 0x12, 0, 0, btlShuffleTaskUpdate, btlShuffleTaskDestroy, (u8 *)(work));
    tmp = (s32)kwlnTaskGetWork(arg0);
    *(s32 *)(work + 8) = 0;
    *(s32 *)(work + 0x6C) = tmp;
    *(s32 *)(work + 0x14) = (s32)(void *)btlShuffleQueueDraw;
    *(s32 *)(work + 0x1C) = (s32)work;
    *(s32 *)(work + 0x44) = (s32)(void *)btlShuffleQueueSeqDraw;
    *(s32 *)(work + 0x4C) = (s32)work;
    pscResInitScene(work + 0x1F384, 0);
    btlShuffleDrawSetup(work + 0x70, handle, *(s32 *)(arg1 + 0xC),
                  *(s32 *)(arg1 + 0x10), *(s32 *)(arg1 + 0x14));
    btlShuffleRandomizeOrder(work + 0x1F2C0, arg1);
    return handle;
}

// FUN_0036E7E0
void btlShuffleTaskSetBusy(void)
{
    u16 *work = kwlnTaskGetWork();

    *work |= BTL_SHUFFLE_FLAG_BUSY;
}

// FUN_0036E810
void btlShuffleTaskResetPhase(void)
{
    u16 *work = kwlnTaskGetWork();

    work[1] = 0;
    *(u32 *)(work + 4) = 5;
}

// FUN_0036E840
u32 btlShuffleTaskIsBusy(void)
{
    return kwlnTaskGetWork()[0] & BTL_SHUFFLE_FLAG_BUSY;
}

// FUN_0036E870
void btlShuffleTaskRequestCancel(void)
{
    u16 *work = kwlnTaskGetWork();

    *work |= BTL_SHUFFLE_FLAG_CANCEL_REQUESTED;
}

// FUN_0036E8A0
u32 btlShuffleTaskIsCancelRequested(void)
{
    return (kwlnTaskGetWork()[0] & BTL_SHUFFLE_FLAG_CANCEL_REQUESTED) != 0;
}

// FUN_0036E8D0
s32 btlShuffleFindTask(void)
{
    return kwlnTaskGetTaskByName(D_0064E780) != 0;
}

// FUN_0036E900
void *func_0036e900(void *arg0)
{
    return *(void **)(*(u32 *)((u8 *)arg0 + 0x38) + 0x6C);
}

// FUN_0036E910
void *func_0036e910(void *arg0)
{
    return (u8 *)*(void **)((u8 *)arg0 + 0x38) + 0x70;
}

// FUN_0036E920
/* measured: without opt_loop_invariants MWCC rematerializes the loop-invariant
 * table base (lui/addiu/addu) inside the loop instead of hoisting it (nd 21);
 * with it the preheader hoist matches retail. */
#pragma opt_loop_invariants on
s32 btlShuffleRollBelow(u8 arg0)
{
    s32 x = arg0 & 0xFF;
    s32 q;
    s32 sum;
    s32 i;
    s32 r;

    if (x == 0) {
        x = 1;
    } else if (x > 0x63) {
        x = 0x63;
    }
    q = (x - 1) / 10;
    r = datCalcRandomBelow(0x64);
    sum = 0;
    for (i = 0; i < 5; i++) {
        sum += D_0064E610[q * 5 + i];
        if (r < sum) {
            break;
        }
    }
    if (i >= 5) {
        kAssertFail(D_0064E790, 0x26C);
    }
    return i;
}
/* measured: see annotation above (func_0036e920). */
#pragma opt_loop_invariants off

// FUN_0036EA00
s32 btlShuffleRollCard(s32 arg0, u8 arg1)
{
    s32 x = arg1 & 0xFF;
    s32 q;
    s32 lo;
    s32 hi;
    s32 result;

    if (x == 0) {
        x = 1;
    } else if (x > 0x63) {
        x = 0x63;
    }
    q = (x - 1) / 10;
    lo = D_0064E5F0[q * 2];
    hi = D_0064E5F1[q * 2];
    if (hi == lo) {
        return hi;
    }
    result = lo + datCalcRandomBelow((u32)(hi - lo + 1));
    switch (arg0) {
    case 0:
        break;
    case 1:
        if (result < 4) {
            result = 4;
            break;
        }
        if (result & 1) {
            result += 1;
        }
        break;
    case 2:
        if (result < 5) {
            result = 3;
            break;
        }
        result = 6;
        break;
    case 3:
        if (result > 6) {
            result = 6;
        }
        break;
    case 4:
        break;
    default:
        break;
    }
    return result;
}
// FUN_0036EB50
/* measured: without opt_loop_invariants MWCC rematerializes the loop-invariant
 * table base (lui/addiu/addu) inside the loop instead of hoisting it (nd 21);
 * with it the preheader hoist matches retail. */
#pragma opt_loop_invariants on
s32 btlShuffleRollFlagged(s32 arg0, u8 arg1)
{
    s32 x = arg1 & 0xFF;
    s32 q;
    s32 limit;
    s32 i;
    s32 sum;

    if (x == 0) {
        x = 1;
    } else if (x > 0x63) {
        x = 0x63;
    }
    q = (x - 1) / 10;
    limit = datCalcRandomBelow(0x64);
    sum = 0;
    i = 0;
    switch (arg0) {
    case 0:
    case 1:
    case 2:
        if (datGetFlag(0x1431) != 0) {
            while (i < 3) {
                sum += D_0064E650[q * 3 + i];
                if (limit < sum) {
                    break;
                }
                i++;
            }
            if (i >= 3) {
                kAssertFail(D_0064E790, 0x2CF);
            }
        }
        break;
    case 3:
        if (datGetFlag(0x1432) != 0) {
            while (i < 4) {
                sum += D_0064E670[q * 4 + i];
                if (limit < sum) {
                    break;
                }
                i++;
            }
            if (i >= 4) {
                kAssertFail(D_0064E790, 0x2DB);
            }
        }
        break;
    case 4:
        if (datGetFlag(0x1433) != 0) {
            while (i < 3) {
                sum += D_0064E6A0[q * 3 + i];
                if (limit < sum) {
                    break;
                }
                i++;
            }
            if (i >= 3) {
                kAssertFail(D_0064E790, 0x2E7);
            }
        }
        break;
    }
    return i;
}
/* measured: see annotation above (func_0036eb50). */
#pragma opt_loop_invariants off

// FUN_0036EDA0
s32 btlShuffleRollIndex(s32 arg0)
{
    s32 i;
    s32 v = arg0 - 3;
    s32 r;
    u8 *tbl;

    if (v < 0) {
        v = 0;
    } else if ((u32)v >= 6) {
        v = 5;
    }
    r = datCalcRandomBelow(0x64);
    i = 3;
    tbl = D_0064E5D0 + v * 4;
    for (; i > 0; i--) {
        if (tbl[i] > r) {
            break;
        }
    }
    if (i < 0) {
        kAssertFail(D_0064E790, 0x307);
    }
    return i + 1;
}

extern s32 datCalcGetLevelById(s32 arg0);
extern u8 D_0064E76F[];
extern u8 *iGpffffb3d4;

/* The draw loop spills the u16 C-list cursor `cIdx` (sh/lhu at sp+0xE0).
 * cIdx and the B-list count tie on spill score / degree, and b210 then
 * spills the higher-numbered one. `(s32)bCount` in the B shuffle bound makes
 * the frontend copy bCount into a CSE temporary, so bCount stays a local
 * with its declared number below cIdx and cIdx is spilled, as in retail.
 * opt_loop_invariants on is required; without it verify reports MISMATCH. */
#pragma push
#pragma opt_loop_invariants on
// FUN_0036EE60
s32 btlShuffleSelectMember(u8 *arg0, s16 arg1, s32 arg2)
{
    s16 listC[256];
    s16 listB[256];
    s16 listA[256];
    s16 lvl;
    s16 hi;
    s16 cap;
    s16 lo;
    s16 mlvl;
    s32 i;
    u16 nB;
    u16 nA;
    s32 nDraw;
    u16 nC;
    s32 bCount;
    s32 cCount;
    s32 total;
    s32 e;
    u16 r2;
    s16 tmp;
    s32 drawIndex;
    u16 aIdx;
    u16 bIdx;
    u16 cIdx;
    u16 r1;
    s16 item;
    u32 rate = 0;

    lvl = datCalcGetLevelById(1) & 0xFF;
    if (lvl > 0 && (u32)lvl < 10) {
        hi = D_0064E76F[lvl];
        lo = 1;
    } else if (lvl >= arg1) {
        hi = arg1 - 5;
        lo = arg1 - 10;
    } else {
        hi = lvl - 5;
        lo = lvl - 10;
    }
    cap = lvl + 3;
    if (cap > 99) {
        cap = 99;
    }
    if (lo < 0) {
        lo = 0;
    }
    if (hi < 0) {
        hi = 0;
    }
    nC = 0;
    nB = 0;
    nA = 0;
    for (i = 0; i < 256; i++) {
        u8 *rec = iGpffffb3d4;
        rec += i * 14;

        if ((*(u16 *)rec & 0xDB) != 0) {
            continue;
        }
        mlvl = rec[3];
        if (mlvl > cap) {
            continue;
        }
        if (mlvl <= lvl) {
            if (hi < mlvl) {
                continue;
            }
            if (mlvl < lo) {
                continue;
            }
        }
        if ((s16)datPersonaFindRosterSlotById((s16)i) != -1) {
            listA[nA++] = i;
        } else if (lvl < mlvl) {
            listB[nB++] = i;
        } else {
            listC[nC++] = i;
        }
    }
    bCount = nB;
    cCount = nC;
    total = nA + (cCount + bCount);
    if (total == 0) {
        return 0;
    }
    if (cCount > 1) {
        s32 k;
        for (k = 0; k < cCount; k++) {
            r1 = datCalcRandomBelow(cCount);
            r2 = datCalcRandomBelow(cCount);
            if (r1 != r2) {
                tmp = listC[r1];
                listC[r1] = listC[r2];
                listC[r2] = tmp;
            }
        }
    }
    if (bCount > 1) {
        s32 k;
        for (k = 0; k < (s32)bCount; k++) {
            r1 = datCalcRandomBelow(nB);
            r2 = datCalcRandomBelow(nB);
            if (r1 != r2) {
                tmp = listB[r1];
                listB[r1] = listB[r2];
                listB[r2] = tmp;
            }
        }
    }
    if (nA > 1) {
        s32 k;
        for (k = 0; k < nA; k++) {
            r1 = datCalcRandomBelow(nA);
            r2 = datCalcRandomBelow(nA);
            if (r1 != r2) {
                tmp = listA[r1];
                listA[r1] = listA[r2];
                listA[r2] = tmp;
            }
        }
    }
    *(s32 *)(arg0 + 0x10) = btlShuffleRollBelow(arg1);
    *(s32 *)(arg0 + 0x14) = btlShuffleRollFlagged(*(s32 *)(arg0 + 0x10), arg1);
    *(s32 *)(arg0 + 0xC) = btlShuffleRollCard(*(s32 *)(arg0 + 0x10), arg1);
    nDraw = btlShuffleRollIndex(*(s32 *)(arg0 + 0xC));
    if (total < nDraw) {
        nDraw = total;
    }
    bIdx = 0;
    cIdx = 0;
    aIdx = 0;
    e = 0;
    for (drawIndex = 0; drawIndex < nDraw; drawIndex++) {
        if (datCalcRandomBelow(100) < rate && bIdx < bCount) {
            item = listB[bIdx++];
        } else if (cIdx < cCount) {
            s32 index = cIdx;
            cIdx++;
            item = listC[index];
        } else if (aIdx < nA) {
            s32 index = aIdx;
            aIdx++;
            item = listA[index];
        } else {
            continue;
        }
        ((s16 *)arg0)[e] = item;
        e++;
    }
    if (e == 0) {
        return 0;
    }
    *(s32 *)(arg0 + 8) = e;
    if (aIdx == e && datCalcRandomBelow(100) >= 20) {
        return 0;
    }
    return 1;
}
#pragma pop

typedef struct {
    f32 a;
    f32 b;
} ShuffleCard2;

// FUN_0036F410
void btlShuffleRandomizeOrder(u8 *arg0, u8 *arg1)
{
    s32 i;
    u32 v;
    s32 idx;
    f32 f;
    ShuffleCard2 tmp;

    for (i = 0; i < *(s32 *)(arg1 + 0xC); i++) {
        if (i < *(s32 *)(arg1 + 8)) {
            *(s32 *)(arg0 + i * 8) = 0;
            *(u16 *)(arg0 + i * 8 + 4) = *(u16 *)(arg1 + i * 2);
            *(u16 *)(arg0 + i * 8 + 6) = 0;
        } else {
            v = RpRandom() & 0xFFF;
            f = (f32)v;
            if (100.0f * (f / 4096.0f) < 30.0f) {
                *(s32 *)(arg0 + i * 8) = 3;
            } else {
                *(s32 *)(arg0 + i * 8) = 2;
            }
            *(u16 *)(arg0 + i * 8 + 4) = 0;
            *(u16 *)(arg0 + i * 8 + 6) = 0;
        }
    }
    for (i = *(s32 *)(arg1 + 0xC) - 1; i > 0; i--) {
        v = RpRandom() & 0xFFF;
        f = (f32)v / 4096.0f;
        idx = (s32)((f32)i * f);
        tmp = ((ShuffleCard2 *)arg0)[i];
        ((ShuffleCard2 *)arg0)[i] = ((ShuffleCard2 *)arg0)[idx];
        ((ShuffleCard2 *)arg0)[idx] = tmp;
    }
}
// FUN_0036F620
void btlShuffleResetSlot(u8 *arg0)
{
    *(u32 *)(arg0 + 0xC) = 0;
    *(u32 *)(arg0 + 0x10) = 0;
    *(u32 *)(arg0 + 0x38) = 0;
    *(u16 *)(arg0 + 8) |= 4;
}

// FUN_0036F640
s32 btlShuffleBuildRoster(s32 arg0, s32 *arg1)
{
    u32 idx;
    u16 a;
    u16 b;
    u32 result;
    u32 idx2;
    u8 *p;
    s32 (*fn)(s32, s32 *);

    memset(arg1, 0, 0xC);
    if (datGetFlag(0x1403) != 0) {
        a = 0;
        b = 0;
        for (idx = 0; idx < 0x2C; idx++) {
            p = (u8 *)D_0064E7B0 + idx * 12;
            if (datGetFlag(*(s32 *)p) != 0) {
                a = *(u16 *)((u8 *)D_0064E7B4 + idx * 12);
                b = *(u16 *)((u8 *)D_0064E7B6 + idx * 12);
                datSetFlag(*(s32 *)p, 0);
                break;
            }
        }
        result = (u32)b | ((u32)a << 16);
        datSetFlag(0x1403, 0);
    } else {
        result = 0;
    }
    for (idx2 = 0; idx2 < 0x2C; idx2++) {
        p = (u8 *)D_0064E7B0 + idx2 * 12;
        if (arg0 == (s32)(*(u16 *)(p + 6) | (*(u16 *)(p + 4) << 16))) {
            fn = (s32 (*)(s32, s32 *))*(s32 *)((u8 *)D_0064E7B8 + idx2 * 12);
            if (fn == NULL) {
                *arg1 = 1;
                datSetFlag(*(s32 *)p, 1);
                datSetFlag(0x1403, 1);
            } else {
                *arg1 = fn(arg0, arg1);
                datSetFlag(*(s32 *)p, 0);
                datSetFlag(0x1403, 0);
            }
            func_00106550(0x10, 0);
            break;
        }
        if (idx2 == 0x2C) {
            kAssertFail(D_0064E790, 0x4A1);
        }
    }
    return result;
}
/* Choose a random listed persona, collect the skill pairs from the
   iGpffffb3ec table that match one of its skills and whose partner skill it
   lacks (searching forward or backward by arg0), and pass one random pair to
   datPersonaReplaceSkill. One counter k serves both directions under scoped
   opt_lifetimes, and each chosen field address is formed separately; both
   are needed for retail's register assignment and address forms. See
   docs/probe_archive/BtlShuffle_worker8_20261005.md for the earlier layout
   recovery. */
static inline u16 *shuffleCandidateField(s32 offset, void *base)
{
    return (u16 *)((u8 *)base + offset);
}

// FUN_0036F880
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
s32 btlShufflePickRosterMember(s32 arg0, u8 *arg1)
{
    u8 *list[12];
    union { u32 word; u16 skills[2]; } cand[8];
    s32 flag = arg0 & 0xFFFF;
    u16 count = datPersonaRosterCapacity();
    u8 *p;
    u16 *skills;
    u16 i;
    u16 n;
    u16 j;
    u16 nc;
    u16 m;
    u16 r;
    u8 *tbl;
    u16 first;
    u16 second;
    u16 k;

    n = 0;
    if (count > 12) {
        kAssertFail(D_0064E790, 1207);
    }
    for (i = 0; i < count; i++) {
        if (datPersonaRosterSlotActive((s16)i) != 0) {
            list[n] = (u8 *)datPersonaRosterSlot((s16)i);
            n++;
        }
    }
    if (n == 0) {
        return 0;
    }
    p = list[datCalcRandomBelow(n)];
    skills = datPersonaGetSkills((int)p);
    nc = 0;
    m = 0;
    tbl = iGpffffb3ec;
    for (; m < 8; m++) {
        if (skills[m] == 0) {
            continue;
        }
        j = 0;
        if (flag != 0) {
            for (; skills[m] != *(u16 *)(tbl + j * 4) && *(u16 *)(tbl + j * 4) != 0; j++) {
            }
            if (*(u16 *)(tbl + j * 4) == 0) {
                continue;
            }
            for (k = 0; k < 8; k++) {
                if (skills[k] != 0 && skills[k] == *(u16 *)(tbl + j * 4 + 2)) {
                    break;
                }
            }
            if (k >= 8) {
                cand[nc].skills[0] = *(u16 *)(tbl + j * 4);
                cand[nc].skills[1] = *(u16 *)(tbl + j * 4 + 2);
                nc++;
            }
        } else {
            for (; skills[m] != *(u16 *)(tbl + j * 4 + 2) && *(u16 *)(tbl + j * 4 + 2) != 0; j++) {
            }
            if (*(u16 *)(tbl + j * 4 + 2) == 0) {
                continue;
            }
            for (k = 0; k < 8; k++) {
                if (skills[k] != 0 && skills[k] == *(u16 *)(tbl + j * 4)) {
                    break;
                }
            }
            if (k >= 8) {
                cand[nc].skills[0] = *(u16 *)(tbl + j * 4 + 2);
                cand[nc].skills[1] = *(u16 *)(tbl + j * 4);
                nc++;
            }
        }
    }
    if (nc == 0) {
        return 0;
    }
    r = datCalcRandomBelow(nc);
    {
        /* Each field address is formed from the chosen entry separately. */
        u16 *field = shuffleCandidateField(2, (u8 *)cand + r * 4);
        second = *field;
        field = shuffleCandidateField(r * 4, cand);
        first = *field;
    }
    datPersonaReplaceSkill(p, (s16)first, second);
    *(u16 *)(arg1 + 4) = *(u16 *)(p + 2);
    *(u16 *)(arg1 + 8) = first;
    *(u16 *)(arg1 + 6) = second;
    return 1;
}

#pragma pop


/* matched: s32 `s` and flag temporaries preserve retail's callee-saved
 * coloring ($s2/$s1) while u16 r and i use $s0/$s3. The explicit s16
 * conversion for the datCalcIsDeadById argument and re-conversion of r in the
 * flagged branch reproduce retail's sign-extension schedule. */
// FUN_0036FBE0
s32 btlShuffleIsPartyMember(s32 arg0)
{
    s16 s;
    u16 i;
    u16 r;
    s32 flag = arg0 & 0xFFFF;

    if (flag != 0) {
        datSetUnitHp(1, (s16)datCalcMaxHpById(1));
    } else {
        datSetUnitHp(1, 1);
    }
    i = 0;
    for (; i < 4; i++) {
        r = (u16)datGetPartyId(i);
        if (r != 0) {
            s = (s16)r;
            if (datCalcIsDeadById(s) == 0) {
                if (flag != 0) {
                    datSetUnitHp((s16)r, (s16)datCalcMaxHpById((s16)r));
                } else {
                    datSetUnitHp(s, 1);
                }
            }
        }
    }
    return 1;
}
// FUN_0036FD00
s32 btlShuffleFindLeadMember(s32 arg0, u8 *arg1)
{
    s32 flag = arg0 & 0xFFFF;
    s32 count = (u16)datPersonaRosterCapacity();
    u8 *p;
    u8 *best = NULL;
    u16 i;
    u16 min = 0x64;
    u16 bestFlag = 0;
    u16 t;

    for (i = 0; i < count; i++) {
        if (i == (s16)datPersonaGetLeadSlot()) {
            continue;
        }
        if (datPersonaRosterSlotActive((s16)i) == 0) {
            continue;
        }
        p = (u8 *)datPersonaRosterSlot((s16)i);
        if (flag != 0) {
            t = *(u16 *)((u8 *)iGpffffb3f0 + *(u16 *)(p + 2) * 4 + 2);
        } else {
            t = *(u16 *)((u8 *)iGpffffb3f0 + *(u16 *)(p + 2) * 4);
        }
        if (t != 0 && (s16)datPersonaFindRosterSlotById((s16)t) == -1 && (datPersonaGetLevel(p) & 0xFF) < min) {
            best = p;
            min = datPersonaGetLevel(p) & 0xFF;
            bestFlag = t & 0xFFFF;
        }
    }
    if (best == NULL) {
        return 0;
    }
    *(u16 *)(arg1 + 4) = *(u16 *)(best + 2);
    *(s16 *)(arg1 + 8) = bestFlag;
    datPersonaRemoveRosterMemberById(*(u16 *)(best + 2));
    datPersonaAddRosterMember(bestFlag);
    return 1;
}

// FUN_0036FED0
s32 btlShuffleCountPartyMembers(s32 arg0)
{
    u16 flag = (u16)arg0;
    u16 i;
    u16 r;

    if (flag != 0) {
        datSetUnitSp(1, (s16)datCalcMaxSpById(1));
    } else {
        datSetUnitSp(1, (s16)((u32)((u16)datCalcGetSpById(1)) >> 1));
    }
    for (i = 0; i < 4; i++) {
        r = (u16)datGetPartyId(i);
        if (r != 0 && datCalcIsDeadById((s16)r) == 0) {
            if (flag != 0) {
                datSetUnitSp((s16)r, (s16)datCalcMaxSpById((s16)r));
            } else {
                datSetUnitSp((s16)r, (s16)((u32)((u16)datCalcGetSpById((s16)r)) >> 1));
            }
        }
    }
    return 1;
}

/* matched: u16 sel reproduces the lui/and/srl/andi dispatch; u16 kind with */
/* narrow callee prototypes yields retail's daddiu constants with no extra */
/* masking; s32 flag + (flag & 0xFFFF) keeps the redundant andi; s16 v/t give */
/* the dsll32/dsra32 schedule, sum = t+v with (sum > 0x63) and (t <= v) fix the */
/* slti/slt $at coloring. */
// FUN_00370020
s32 btlShuffleBuffedStat(s32 arg0, u8 *arg1)
{
    s32 flag = arg0 & 0xFFFF;
    u16 sel = (u16)((u32)(arg0 & 0xFFFF0000) >> 16);
    u8 *p;
    u16 kind;
    s16 v;
    s16 t;

    switch (sel) {
    case 8:
        kind = 3;
        break;
    case 9:
        kind = 0;
        break;
    case 11:
        kind = 4;
        break;
    case 12:
        kind = 1;
        break;
    case 13:
        kind = 2;
        break;
    default:
        kAssertFail(D_0064E790, 0x5D6);
        break;
    }
    p = (u8 *)datPersonaRosterSlot((s16)datCalcRandomBelow(datPersonaCountValidMembers() & 0xFFFF));
    if (p == NULL) {
        kAssertFail(D_0064E790, 0x5DC);
    }
    if ((flag & 0xFFFF) != 0) {
        s32 sum;
        v = (s16)(datCalcRandomBelow(3) + 1);
        t = (s16)(datPersonaGetBuffedStat(p, kind) & 0xFF);
        if (t >= 0x63) {
            return 0;
        }
        sum = t + v;
        if (sum > 0x63) {
            v = 0x63 - t;
        }
        datPersonaAddStat(p, kind, (s8)v);
    } else {
        v = (s16)(datCalcRandomBelow(1) + 1);
        t = (s16)(datPersonaGetStat(p, kind) & 0xFF);
        if (t < 2) {
            return 0;
        }
        if (t <= v) {
            v = t - 1;
        }
        datPersonaAddStat(p, kind, (s8)(-v));
    }
    *(u16 *)(arg1 + 4) = *(u16 *)(p + 2);
    *(u16 *)(arg1 + 8) = (u16)v;
    return 1;
}
