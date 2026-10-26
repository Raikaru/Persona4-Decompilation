/* Original translation unit btlShuffle.c (from __FILE__ assert strings). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "btl_shuffle_draw_internal.h"
#include "btl_shuffle_task_internal.h"
#include "datUnit_internal.h"
#include "sdktask.h"
#include "btl_result_ui_internal.h"

/* Partial interpretation of BtlResultWork.parameters (0x58 bytes at parent +8).
 * The shuffle result callback resets these fields through the saved parent work. */
typedef struct BtlShuffleResultParameters {
    u16 flags;
    u8 pad02[2];
    u32 unk04, unk08;
    u8 pad0C[0x24];
    u32 unk30;
    u8 pad34[0x24];
} BtlShuffleResultParameters;


extern void btlShuffleDrawTaskUpdate(u8 *work);

extern void btlShuffleDrawQueueCardsB(u8 *context);

extern u16 *kwlnTaskGetWork(void* task);

extern s32 kwlnTaskGetTaskByName(void *name);

extern u32 datCalcRandomBelow(u32 limit);

extern void kAssertFail(const void *file, s32 line);

extern u8 D_0064E5D0[];

extern u8 D_0064E610[];

extern u8 D_0064E790[];

extern void chkmemAllocSiteTag(const void *file, s32 line);

extern void *(*jtbl_008873E8[])(u32 size, u32 align);

extern void memset(void *dst, s32 value, s32 size);


extern void pscResInitScene(u8 *work, s32 resetCamera);

extern void btlShuffleDrawSetup(u8 *context, s32 parentTask, s32 cardCount, s32 pattern, s32 difficulty);

extern void btlShuffleRandomizeOrder(u8 *cards, u8 *selection);

extern u8 D_0064E7A0[];

extern s32 btlShuffleTaskUpdate(u8 *unusedTask);

extern void btlShuffleTaskDestroy(u8 *unusedTask);

extern u16 datCalcMaxHpById(s16 unitId);

extern void datSetUnitHp(s16 unitId, s16 hp);

extern u32 datCalcIsDeadById(s16 unitId);

extern s32 datGetPartyId();

extern u16 datCalcMaxSpById(s16 unitId);

extern u32 datCalcGetSpById(s16 unitId);

extern void datSetUnitSp(s16 unitId, s16 sp);

extern u8 D_0064E5F0[];

extern u8 D_0064E5F1[];

extern u32 RpRandom();

extern s32 datPersonaRosterCapacity();

extern s32 datPersonaGetLeadSlot();

extern s32 datPersonaRosterSlotActive(s16 slotIndex);

extern s32 datPersonaFindRosterSlotById();

extern struct DatPersonaRecord *datPersonaRosterSlot(s16 slotIndex);

/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern s32 datPersonaGetLevel();

/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern void datPersonaRemoveRosterMemberById();

extern u8 *datPersonaAddRosterMember(u16 personaId);

extern u8 *iGpffffb3c0;

extern u8 *iGpffffb3f0;
extern u8 *iGpffffb3e0;
extern u8 *iGpffffb3ec;
extern u16 *datPersonaGetSkills(struct DatPersonaRecord *persona);
extern s32 datPersonaReplaceSkill(u8 *persona, s16 oldSkill, u16 newSkill);
/* Interior column aliases of the reward table use a 12-byte stride. */
typedef struct BtlShuffleRewardHalfwordColumn { u16 value; u8 pad02[10]; } BtlShuffleRewardHalfwordColumn;
typedef struct BtlShuffleRewardCallbackColumn { s32 (*apply)(s32, s32 *); u8 pad04[8]; } BtlShuffleRewardCallbackColumn;

extern s32 D_0064E7B0[];

extern BtlShuffleRewardHalfwordColumn D_0064E7B4[];

extern BtlShuffleRewardHalfwordColumn D_0064E7B6[];

extern BtlShuffleRewardCallbackColumn D_0064E7B8[];

extern void datSetScriptValue(s32 index, u32 value);

extern s32 datGetFlag(s32 bit);

extern void datSetFlag(s32 flagId, s32 enabled);

extern void pscResTeardown(u8 *unusedTask);

extern void btlShuffleDrawRelease(u8 *context);

extern void (*jtbl_008873EC[])(void *ptr);

extern u8 D_0064E780[];

extern u8 D_0064E650[];

extern u8 D_0064E670[];

extern u8 D_0064E6A0[];
extern u16 datPersonaCountValidMembers(void);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern u8 datPersonaGetStat(u8 *persona, u16 statIndex);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern u8 datPersonaGetBuffedStat(u8 *persona, u16 statIndex);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern s32 datPersonaAddStat(u8 *persona, u16 statIndex, s8 delta);
extern u8 D_00793E80[];

extern s32 iGpffffa9c0[2]; /* two draw-queue indices, accessed through the original GP-relative base */

extern void PrimAppendNode(u8 *list, u8 *node);

extern void btlShuffleDrawLoadSprites(u8 *context);

extern s32 btlShuffleDrawLoadBlob(u8 *work);

extern void btlShuffleDrawTaskInit(u8 *context, u8 *cardIndex);

extern s32 pscResIsIdle(void);

extern void btlShuffleDrawViewRestore(u8 *context);

extern void btlShuffleDrawFrame(u8 *context);

extern s32 btlEncounterIsActive(void);

extern s32 btlShuffleSeqCardTask(u8 *context);

extern u8 nmMesWindowOpenCurrent(u8 *message);

extern void nmMesWindowShowCurrentRecord(s32 recordIndex);

extern void nmMesWindowStepCurrent(s32 release);

extern s32 nmMesWindowCurrentOpenState(void);

extern void nmMesWindowCloseCurrent(s32 release);

extern void nmMesWindowResetCurrent(void);

extern void btlShuffleSeqClearA(u8 *context, s32 count);

extern s32 btlShuffleSeqFlag(u8 *context);


/* Drive shuffle resource loading, introduction messages, card selection, and delayed task termination. */
// FUN_0036E140
s32 btlShuffleTaskUpdate(u8 *unusedTask)
{
    BtlShuffleTaskWork *work = (BtlShuffleTaskWork *)kwlnTaskGetWork(unusedTask);
    s32 i;
    u16 flags;
    u16 cnt;

    for (i = 0; i < 2; i++) {
        BtlShuffleTaskWork *p = (BtlShuffleTaskWork *)((u8 *)work + i * 0x30);
        *(s32 *)&p->queues[0].node.pad00[0] = 0;
        *(s32 *)&p->queues[0].node.pad00[4] = 0;
        /* measured: the two-entry array declaration keeps the GP-relative base. */
        PrimAppendNode((u8 *)D_00793E80 + iGpffffa9c0[i] * 0x30, (u8 *)p + 0xC);
    }
    switch (work->phase) {
    case 0:
        work->phase = 1;
        break;
    case 1:
        flags = work->flags;
        if ((flags & 1) != 0) {
            if ((flags & 8) != 0) {
                goto case2_body;
            }
        }
        if ((flags & 4) == 0) {
            break;
        }
        if (((flags & 0x10) == 0) && ((flags & 0x80) == 0)) {
            btlShuffleDrawLoadSprites((u8 *)work + 0x70);
            work->flags |= 0x80;
        }
        if (((work->flags) & 0x80) != 0) {
            if (btlShuffleDrawLoadBlob((u8 *)work + 0x70) != 0) {
                work->flags |= 0x10;
                work->flags &= (u16)~0x80;
            }
        }
        flags = work->flags;
        if (((flags & 0x20) == 0) && ((flags & 0x40) == 0) && ((flags & 0x10) != 0)) {
            btlShuffleDrawTaskInit((u8 *)work + 0x70, (u8 *)work + 0x1F2C0);
            work->flags |= 0x40;
        }
        if (((work->flags) & 0x40) != 0) {
            if (pscResIsIdle() != 0) {
                work->flags |= 0x20;
                work->flags &= (u16)~0x40;
            }
        }
        flags = work->flags;
        if (((flags & 0x10) != 0) && ((flags & 0x20) != 0)) {
            work->flags = flags | 8;
            work->flags &= (u16)~4;
        }
        break;
    case 2:
case2_body:
        btlShuffleDrawViewRestore((u8 *)work + 0x70);
        work->phase = 3;
        /* fallthrough */
    case 3:
        btlShuffleDrawFrame((u8 *)work + 0x70);
        work->flags |= 2;
        if (datGetFlag(0x1430) == 0) {
            work->messageIndex = 0;
            work->phase = 7;
            break;
        }
        work->phase = 4;
        /* fallthrough */
    case 4:
        if (((work->flags) & 0x100) == 0) {
            if (btlEncounterIsActive() != 0) {
                break;
            }
            work->flags |= 0x100;
        }
        if (btlShuffleSeqCardTask((u8 *)work + 0x70) != 0) {
            work->flags &= (u16)~1;
            work->phase = 6;
        }
        break;
    case 5:
        cnt = ++work->frames;
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
        cnt = ++work->frames;
        if ((cnt & 0xFFFF) < 0x1E) {
            break;
        }
        work->frames = 0;
        nmMesWindowOpenCurrent((u8 *)work->drawing.textureBlobs[2]);
        nmMesWindowShowCurrentRecord(0);
        work->phase = 8;
        /* fallthrough */
    case 8:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            {
                s32 t = work->messageIndex + 1;
                work->messageIndex = t;
                if (t < 4) {
                    nmMesWindowShowCurrentRecord(work->messageIndex);
                } else {
                    nmMesWindowResetCurrent();
                    btlShuffleSeqClearA((u8 *)work + 0x70, 0);
                    work->phase = 9;
                }
            }
        }
        break;
    case 9:
        if (btlShuffleSeqFlag((u8 *)work + 0x70) == 0) {
            break;
        }
        cnt = ++work->frames;
        if ((cnt & 0xFFFF) < 0x1E) {
            break;
        }
        work->phase = 4;
        break;
    default:
        kAssertFail(D_0064E790, 0x178);
        break;
    }
    return 0;
}

/* Dispatch the shuffle drawing update while the parent draw-enabled flag is set. */
// FUN_0036E580
void btlShuffleQueueDraw(u8 *queue, u16 *work)
{
    if (*work & 2) {
        btlShuffleDrawTaskUpdate((u8 *)work + 0x70);
    }
}


/* Queue the sequence card drawing while the parent draw-enabled flag is set. */
// FUN_0036E5C0
void btlShuffleQueueSeqDraw(u8 *queue, u16 *work)
{
    if (*work & 2) {
        btlShuffleDrawQueueCardsB((u8 *)work + 0x70);
    }
}

/* Release scene and drawing resources, marking the introduction as seen. */
// FUN_0036E600
void btlShuffleTaskDestroy(u8 *unusedTask)
{
    u8 *work = (u8 *)kwlnTaskGetWork(unusedTask);

    if (datGetFlag(0x1430) == 0) {
        datSetFlag(0x1430, 1);
    }
    pscResTeardown(work + 0x1F384);
    btlShuffleDrawRelease(work + 0x70);
    jtbl_008873EC[0](work);
}

/* Allocate the parent work, register both draw callbacks, and initialize the shuffled card specification list. */
// FUN_0036E690
s32 btlShuffleTaskCreate(u8 *parent, u8 *selection)
{
    u8 *work;
    s32 handle;
    s32 tmp;

    chkmemAllocSiteTag(D_0064E7A0, 0x3A);
    work = (u8 *)(*jtbl_008873E8)(0x21ABC, 0x40000);
    memset(work, 0, 0x21ABC);
    handle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064E780), 0x12, 0, 0, btlShuffleTaskUpdate, btlShuffleTaskDestroy, (u8 *)(work));
    tmp = (s32)kwlnTaskGetWork(parent);
    ((BtlShuffleTaskWork *)work)->phase = 0;
    *(s32 *)&((BtlShuffleTaskWork *)work)->parentWork = tmp;
    *(s32 *)&((BtlShuffleTaskWork *)work)->queues[0].node.callback = (s32)(void *)btlShuffleQueueDraw;
    *(s32 *)&((BtlShuffleTaskWork *)work)->queues[0].node.argument.data = (s32)work;
    *(s32 *)&((BtlShuffleTaskWork *)work)->queues[1].node.callback = (s32)(void *)btlShuffleQueueSeqDraw;
    *(s32 *)&((BtlShuffleTaskWork *)work)->queues[1].node.argument.data = (s32)work;
    pscResInitScene(work + 0x1F384, 0);
    btlShuffleDrawSetup(work + 0x70, handle, ((BtlShuffleSelection *)selection)->cardCount,
                  ((BtlShuffleSelection *)selection)->pattern, ((BtlShuffleSelection *)selection)->difficulty);
    btlShuffleRandomizeOrder(work + 0x1F2C0, selection);
    return handle;
}

// FUN_0036E7E0
void btlShuffleTaskSetBusy(u8 *object)
{
    u16 *work = kwlnTaskGetWork(object);

    *work |= BTL_SHUFFLE_FLAG_BUSY;
}

/* Start the ten-frame termination delay and reset its elapsed counter. */
// FUN_0036E810
void btlShuffleTaskResetPhase(u8 *object)
{
    u16 *work = kwlnTaskGetWork(object);

    ((BtlShuffleTaskWork *)work)->frames = 0;
    *(u32 *)&((BtlShuffleTaskWork *)work)->phase = 5;
}

// FUN_0036E840
u32 btlShuffleTaskIsBusy(u8 *object)
{
    return kwlnTaskGetWork(object)[0] & BTL_SHUFFLE_FLAG_BUSY;
}

// FUN_0036E870
void btlShuffleTaskRequestCancel(u8 *object)
{
    u16 *work = kwlnTaskGetWork(object);

    *work |= BTL_SHUFFLE_FLAG_CANCEL_REQUESTED;
}

// FUN_0036E8A0
u32 btlShuffleTaskIsCancelRequested(u8 *object)
{
    return (kwlnTaskGetWork(object)[0] & BTL_SHUFFLE_FLAG_CANCEL_REQUESTED) != 0;
}

// FUN_0036E8D0
s32 btlShuffleFindTask(void)
{
    return kwlnTaskGetTaskByName(D_0064E780) != 0;
}

// FUN_0036E900
void *btlShuffleGetParentWork(void *task)
{
    return ((BtlShuffleTaskWork *)((SdkTask *)task)->work)->parentWork;
}

// FUN_0036E910
void *btlShuffleGetDrawContext(void *task)
{
    return (u8 *)((SdkTask *)task)->work + 0x70;
}

/* Choose a pattern from cumulative weights for the clamped level decade. */
// FUN_0036E920
/* measured: retail hoists the active weight row out of the cumulative-threshold loop, which needs
 * loop-invariant hoisting on. */
#pragma opt_loop_invariants on
s32 btlShuffleRollBelow(u8 level)
{
    s32 clampedLevel = level & 0xFF;
    s32 decade;
    s32 weightSum;
    s32 i;
    s32 roll;

    if (clampedLevel == 0) {
        clampedLevel = 1;
    } else if (clampedLevel > 0x63) {
        clampedLevel = 0x63;
    }
    decade = (clampedLevel - 1) / 10;
    roll = datCalcRandomBelow(0x64);
    weightSum = 0;
    for (i = 0; i < 5; i++) {
        weightSum += D_0064E610[decade * 5 + i];
        if (roll < weightSum) {
            break;
        }
    }
    if (i >= 5) {
        kAssertFail(D_0064E790, 0x26C);
    }
    return i;
}
/* measured: restores the unit setting after func_0036e920. */
#pragma opt_loop_invariants off

/* Choose a card count from the level range, then apply the selected pattern constraints. */
// FUN_0036EA00
s32 btlShuffleRollCard(s32 pattern, u8 level)
{
    s32 clampedLevel = level & 0xFF;
    s32 decade;
    s32 minimum;
    s32 maximum;
    s32 result;

    if (clampedLevel == 0) {
        clampedLevel = 1;
    } else if (clampedLevel > 0x63) {
        clampedLevel = 0x63;
    }
    decade = (clampedLevel - 1) / 10;
    minimum = D_0064E5F0[decade * 2];
    maximum = D_0064E5F1[decade * 2];
    if (maximum == minimum) {
        return maximum;
    }
    result = minimum + datCalcRandomBelow((u32)(maximum - minimum + 1));
    switch (pattern) {
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
/* Choose an unlocked pattern variant from its cumulative level-decade weights. */
/* measured: cached weight-row pointers match at baseline; opt_loop_invariants on is no longer needed. */
// FUN_0036EB50
/* measured: retail hoists the table base out of the loop; without opt_loop_invariants it is
 * recomputed each iteration. */
s32 btlShuffleRollFlagged(s32 pattern, u8 level)
{
    s32 clampedLevel = level & 0xFF;
    s32 decade;
    s32 roll;
    s32 i;
    s32 weightSum;
    u8 *weights;

    if (clampedLevel == 0) {
        clampedLevel = 1;
    } else if (clampedLevel > 0x63) {
        clampedLevel = 0x63;
    }
    decade = (clampedLevel - 1) / 10;
    roll = datCalcRandomBelow(0x64);
    weightSum = 0;
    i = 0;
    switch (pattern) {
    case 0:
    case 1:
    case 2:
        if (datGetFlag(0x1431) != 0) {
            weights = &D_0064E650[decade * 3];
            while (i < 3) {
                weightSum += weights[i];
                if (roll < weightSum) {
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
            weights = &D_0064E670[decade * 4];
            while (i < 4) {
                weightSum += weights[i];
                if (roll < weightSum) {
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
            weights = &D_0064E6A0[decade * 3];
            while (i < 3) {
                weightSum += weights[i];
                if (roll < weightSum) {
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

/* Choose the persona-card count using descending cumulative thresholds for the total card count. */
// FUN_0036EDA0
s32 btlShuffleRollIndex(s32 cardCount)
{
    s32 i;
    s32 tableIndex = cardCount - 3;
    s32 roll;
    u8 *thresholds;

    if (tableIndex < 0) {
        tableIndex = 0;
    } else if ((u32)tableIndex >= 6) {
        tableIndex = 5;
    }
    roll = datCalcRandomBelow(0x64);
    i = 3;
    thresholds = D_0064E5D0 + tableIndex * 4;
    for (; i > 0; i--) {
        if (thresholds[i] > roll) {
            break;
        }
    }
    if (i < 0) {
        kAssertFail(D_0064E790, 0x307);
    }
    return i + 1;
}

extern s32 datCalcGetLevelById(s32 unitId);
extern u8 D_0064E76F[];
extern u8 *iGpffffb3d4;

/* The (s32)bCount cast keeps bCount numbered below cIdx so the u16 C-list cursor is the spilled
 * value, as in retail. */
#pragma push
/* measured: retail hoists loop invariants in the pool-building loops. */
#pragma opt_loop_invariants on
/* Build and shuffle owned, higher-level, and ordinary persona pools, then choose the result card candidates. */
// FUN_0036EE60
s32 btlShuffleSelectMember(u8 *selection, s16 encounterLevel, s32 unusedMode)
{
    s16 listC[256];
    s16 listB[256];
    s16 listA[256];
    s16 playerLevel;
    s16 maximumLevel;
    s16 levelCap;
    s16 minimumLevel;
    s16 personaLevel;
    s32 i;
    u16 nB;
    u16 nA;
    s32 drawCount;
    u16 nC;
    s32 bCount;
    s32 cCount;
    s32 total;
    s32 selectedCount;
    u16 r2;
    s16 swappedPersona;
    s32 drawIndex;
    u16 aIdx;
    u16 bIdx;
    u16 cIdx;
    u16 r1;
    s16 item;
    u32 rate = 0;
    BtlShuffleSelection *setup = (BtlShuffleSelection *)selection;

    playerLevel = datCalcGetLevelById(1) & 0xFF;
    if (playerLevel > 0 && (u32)playerLevel < 10) {
        maximumLevel = D_0064E76F[playerLevel];
        minimumLevel = 1;
    } else if (playerLevel >= encounterLevel) {
        maximumLevel = encounterLevel - 5;
        minimumLevel = encounterLevel - 10;
    } else {
        maximumLevel = playerLevel - 5;
        minimumLevel = playerLevel - 10;
    }
    levelCap = playerLevel + 3;
    if (levelCap > 99) {
        levelCap = 99;
    }
    if (minimumLevel < 0) {
        minimumLevel = 0;
    }
    if (maximumLevel < 0) {
        maximumLevel = 0;
    }
    nC = 0;
    nB = 0;
    nA = 0;
    for (i = 0; i < 256; i++) {
        u8 *candidate = iGpffffb3d4;
        candidate += i * 14;

        if ((((BtlShufflePersonaCandidate *)candidate)->flags & 0xDB) != 0) {
            continue;
        }
        personaLevel = ((BtlShufflePersonaCandidate *)candidate)->level;
        if (personaLevel > levelCap) {
            continue;
        }
        if (personaLevel <= playerLevel) {
            if (maximumLevel < personaLevel) {
                continue;
            }
            if (personaLevel < minimumLevel) {
                continue;
            }
        }
        if ((s16)datPersonaFindRosterSlotById((s16)i) != -1) {
            listA[nA++] = i;
        } else if (playerLevel < personaLevel) {
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
                swappedPersona = listC[r1];
                listC[r1] = listC[r2];
                listC[r2] = swappedPersona;
            }
        }
    }
    if (bCount > 1) {
        s32 k;
        for (k = 0; k < (s32)bCount; k++) {
            r1 = datCalcRandomBelow(nB);
            r2 = datCalcRandomBelow(nB);
            if (r1 != r2) {
                swappedPersona = listB[r1];
                listB[r1] = listB[r2];
                listB[r2] = swappedPersona;
            }
        }
    }
    if (nA > 1) {
        s32 k;
        for (k = 0; k < nA; k++) {
            r1 = datCalcRandomBelow(nA);
            r2 = datCalcRandomBelow(nA);
            if (r1 != r2) {
                swappedPersona = listA[r1];
                listA[r1] = listA[r2];
                listA[r2] = swappedPersona;
            }
        }
    }
    setup->pattern = btlShuffleRollBelow(encounterLevel);
    setup->difficulty = btlShuffleRollFlagged(setup->pattern, encounterLevel);
    setup->cardCount = btlShuffleRollCard(setup->pattern, encounterLevel);
    drawCount = btlShuffleRollIndex(setup->cardCount);
    if (total < drawCount) {
        drawCount = total;
    }
    bIdx = 0;
    cIdx = 0;
    aIdx = 0;
    selectedCount = 0;
    for (drawIndex = 0; drawIndex < drawCount; drawIndex++) {
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
        setup->personas[selectedCount] = item;
        selectedCount++;
    }
    if (selectedCount == 0) {
        return 0;
    }
    setup->personaCount = selectedCount;
    if (aIdx == selectedCount && datCalcRandomBelow(100) >= 20) {
        return 0;
    }
    return 1;
}
#pragma pop

typedef struct {
    f32 a;
    f32 b;
} ShuffleCard2;

/* Fill persona and miscellaneous card specifications, then shuffle their eight-byte records. */
// FUN_0036F410
void btlShuffleRandomizeOrder(u8 *cards, u8 *selection)
{
    s32 i;
    u32 randomBits;
    s32 swapIndex;
    f32 randomFraction;
    ShuffleCard2 swappedCard;

    for (i = 0; i < ((BtlShuffleSelection *)selection)->cardCount; i++) {
        if (i < ((BtlShuffleSelection *)selection)->personaCount) {
            ((BtlShuffleCardSpec *)cards)[i].kind = 0;
            ((BtlShuffleCardSpec *)cards)[i].id = *(u16 *)&((BtlShuffleSelection *)selection)->personas[i];
            ((BtlShuffleCardSpec *)cards)[i].index = 0;
        } else {
            randomBits = RpRandom() & 0xFFF;
            randomFraction = (f32)randomBits;
            if (100.0f * (randomFraction / 4096.0f) < 30.0f) {
                ((BtlShuffleCardSpec *)cards)[i].kind = 3;
            } else {
                ((BtlShuffleCardSpec *)cards)[i].kind = 2;
            }
            ((BtlShuffleCardSpec *)cards)[i].id = 0;
            ((BtlShuffleCardSpec *)cards)[i].index = 0;
        }
    }
    for (i = ((BtlShuffleSelection *)selection)->cardCount - 1; i > 0; i--) {
        randomBits = RpRandom() & 0xFFF;
        randomFraction = (f32)randomBits / 4096.0f;
        swapIndex = (s32)((f32)i * randomFraction);
        swappedCard = ((ShuffleCard2 *)cards)[i];
        ((ShuffleCard2 *)cards)[i] = ((ShuffleCard2 *)cards)[swapIndex];
        ((ShuffleCard2 *)cards)[swapIndex] = swappedCard;
    }
}
/* Clear the parent result's shuffle bookkeeping and set its reset flag. */
// FUN_0036F620
void btlShuffleResetSlot(u8 *slot)
{
    ((BtlShuffleResultParameters *)((BtlResultWork *)slot)->parameters)->unk04 = 0;
    ((BtlShuffleResultParameters *)((BtlResultWork *)slot)->parameters)->unk08 = 0;
    ((BtlShuffleResultParameters *)((BtlResultWork *)slot)->parameters)->unk30 = 0;
    ((BtlShuffleResultParameters *)((BtlResultWork *)slot)->parameters)->flags |= 4;
}

/* Consume the pending reward rule, apply or defer the selected rule, and return the previous selector pair. */
// FUN_0036F640
s32 btlShuffleBuildRoster(s32 selector, s32 *result)
{
    /* The rule table has linker-visible aliases at each field. */
    u32 idx;
    u16 kind;
    u16 variant;
    u32 previousSelector;
    u32 idx2;
    u8 *rule;
    s32 (*applyRule)(s32, s32 *);

    memset(result, 0, 0xC);
    if (datGetFlag(0x1403) != 0) {
        kind = 0;
        variant = 0;
        for (idx = 0; idx < 0x2C; idx++) {
            rule = (u8 *)D_0064E7B0 + idx * 12;
            if (datGetFlag(((BtlShuffleRewardRule *)rule)->flag) != 0) {
                kind = D_0064E7B4[idx].value;
                variant = D_0064E7B6[idx].value;
                datSetFlag(((BtlShuffleRewardRule *)rule)->flag, 0);
                break;
            }
        }
        previousSelector = (u32)variant | ((u32)kind << 16);
        datSetFlag(0x1403, 0);
    } else {
        previousSelector = 0;
    }
    for (idx2 = 0; idx2 < 0x2C; idx2++) {
        rule = (u8 *)D_0064E7B0 + idx2 * 12;
        if (selector == (s32)(((BtlShuffleRewardRule *)rule)->variant | (((BtlShuffleRewardRule *)rule)->kind << 16))) {
            applyRule = D_0064E7B8[idx2].apply;
            if (applyRule == NULL) {
                *result = 1;
                datSetFlag(((BtlShuffleRewardRule *)rule)->flag, 1);
                datSetFlag(0x1403, 1);
            } else {
                *result = applyRule(selector, result);
                datSetFlag(((BtlShuffleRewardRule *)rule)->flag, 0);
                datSetFlag(0x1403, 0);
            }
            datSetScriptValue(0x10, 0);
            break;
        }
        if (idx2 == 0x2C) {
            kAssertFail(D_0064E790, 0x4A1);
        }
    }
    return previousSelector;
}
/* Picks a random listed persona and swaps one skill via datPersonaReplaceSkill, using a random
 * matching pair from the iGpffffb3ec table searched forward or backward by arg0. measured: the
 * inline helper forms each candidate field address separately before the load, as retail does. */
static inline u16 *btlShuffleCandidateField(s32 offset, void *base)
{
    return (u16 *)((u8 *)base + offset);
}

// FUN_0036F880
#pragma push
/* measured: retail shares one counter for both search directions, which needs scoped lifetimes. */
#pragma opt_lifetimes on
/* measured: retail hoists the loop-invariant table addresses out of the search loops. */
#pragma opt_loop_invariants on
s32 btlShufflePickRosterMember(s32 selector, u8 *result)
{
    u8 *list[12];
    union { u32 word; u16 skills[2]; } candidates[8];
    s32 reverse = selector & 0xFFFF;
    u16 count = datPersonaRosterCapacity();
    u8 *persona;
    u16 *skills;
    u16 i;
    u16 rosterCount;
    u16 j;
    u16 candidateCount;
    u16 m;
    u16 r;
    u8 *pairs;
    u16 first;
    u16 second;
    u16 k;

    rosterCount = 0;
    if (count > 12) {
        kAssertFail(D_0064E790, 1207);
    }
    for (i = 0; i < count; i++) {
        if (datPersonaRosterSlotActive((s16)i) != 0) {
            list[rosterCount] = (u8 *)datPersonaRosterSlot((s16)i);
            rosterCount++;
        }
    }
    if (rosterCount == 0) {
        return 0;
    }
    persona = list[datCalcRandomBelow(rosterCount)];
    skills = datPersonaGetSkills((struct DatPersonaRecord *)persona);
    candidateCount = 0;
    m = 0;
    pairs = iGpffffb3ec;
    for (; m < 8; m++) {
        if (skills[m] == 0) {
            continue;
        }
        j = 0;
        if (reverse != 0) {
            for (; skills[m] != ((BtlShuffleSkillPair *)pairs)[j].first && ((BtlShuffleSkillPair *)pairs)[j].first != 0; j++) {
            }
            if (((BtlShuffleSkillPair *)pairs)[j].first == 0) {
                continue;
            }
            for (k = 0; k < 8; k++) {
                if (skills[k] != 0 && skills[k] == ((BtlShuffleSkillPair *)pairs)[j].second) {
                    break;
                }
            }
            if (k >= 8) {
                candidates[candidateCount].skills[0] = ((BtlShuffleSkillPair *)pairs)[j].first;
                candidates[candidateCount].skills[1] = ((BtlShuffleSkillPair *)pairs)[j].second;
                candidateCount++;
            }
        } else {
            for (; skills[m] != ((BtlShuffleSkillPair *)pairs)[j].second && ((BtlShuffleSkillPair *)pairs)[j].second != 0; j++) {
            }
            if (((BtlShuffleSkillPair *)pairs)[j].second == 0) {
                continue;
            }
            for (k = 0; k < 8; k++) {
                if (skills[k] != 0 && skills[k] == ((BtlShuffleSkillPair *)pairs)[j].first) {
                    break;
                }
            }
            if (k >= 8) {
                candidates[candidateCount].skills[0] = ((BtlShuffleSkillPair *)pairs)[j].second;
                candidates[candidateCount].skills[1] = ((BtlShuffleSkillPair *)pairs)[j].first;
                candidateCount++;
            }
        }
    }
    if (candidateCount == 0) {
        return 0;
    }
    r = datCalcRandomBelow(candidateCount);
    {
        /* Each field address is formed from the chosen entry separately. */
        u16 *field = btlShuffleCandidateField(2, (u8 *)candidates + r * 4);
        second = *field;
        field = btlShuffleCandidateField(r * 4, candidates);
        first = *field;
    }
    datPersonaReplaceSkill(persona, (s16)first, second);
    ((BtlShuffleRewardResult *)result)->personaId = ((DatPersonaRecord *)persona)->id;
    ((BtlShuffleRewardResult *)result)->previous = first;
    ((BtlShuffleRewardResult *)result)->replacement = second;
    return 1;
}

#pragma pop


/* Restore living party members to maximum HP or reduce them to one HP; always include the
 * protagonist. The explicit s16 casts reproduce retail's sign-extension order. */
// FUN_0036FBE0
s32 btlShuffleIsPartyMember(s32 selector)
{
    s16 character;
    u16 i;
    u16 partyId;
    s32 restore = selector & 0xFFFF;

    if (restore != 0) {
        datSetUnitHp(1, (s16)datCalcMaxHpById(1));
    } else {
        datSetUnitHp(1, 1);
    }
    i = 0;
    for (; i < 4; i++) {
        partyId = (u16)datGetPartyId(i);
        if (partyId != 0) {
            character = (s16)partyId;
            if (datCalcIsDeadById(character) == 0) {
                if (restore != 0) {
                    datSetUnitHp((s16)partyId, (s16)datCalcMaxHpById((s16)partyId));
                } else {
                    datSetUnitHp(character, 1);
                }
            }
        }
    }
    return 1;
}
/* Replace the lowest-level eligible non-lead persona through the selected replacement table column. */
// FUN_0036FD00
s32 btlShuffleFindLeadMember(s32 selector, u8 *result)
{
    s32 column = selector & 0xFFFF;
    s32 count = (u16)datPersonaRosterCapacity();
    u8 *persona;
    u8 *best = NULL;
    u16 i;
    u16 minimumLevel = 0x64;
    u16 replacementId = 0;
    u16 candidateId;

    for (i = 0; i < count; i++) {
        if (i == (s16)datPersonaGetLeadSlot()) {
            continue;
        }
        if (datPersonaRosterSlotActive((s16)i) == 0) {
            continue;
        }
        persona = (u8 *)datPersonaRosterSlot((s16)i);
        if (column != 0) {
            candidateId = ((BtlShufflePersonaPair *)iGpffffb3f0)[((DatPersonaRecord *)persona)->id].second;
        } else {
            candidateId = ((BtlShufflePersonaPair *)iGpffffb3f0)[((DatPersonaRecord *)persona)->id].first;
        }
        if (candidateId != 0 && (s16)datPersonaFindRosterSlotById((s16)candidateId) == -1 && (datPersonaGetLevel(persona) & 0xFF) < minimumLevel) {
            best = persona;
            minimumLevel = datPersonaGetLevel(persona) & 0xFF;
            replacementId = candidateId & 0xFFFF;
        }
    }
    if (best == NULL) {
        return 0;
    }
    ((BtlShuffleRewardResult *)result)->personaId = ((DatPersonaRecord *)best)->id;
    *(s16 *)&((BtlShuffleRewardResult *)result)->previous = replacementId;
    datPersonaRemoveRosterMemberById(((DatPersonaRecord *)best)->id);
    datPersonaAddRosterMember(replacementId);
    return 1;
}

/* Restore living party members to maximum SP or halve their current SP; always include the protagonist. */
// FUN_0036FED0
s32 btlShuffleCountPartyMembers(s32 selector)
{
    u16 restore = (u16)selector;
    u16 i;
    u16 partyId;

    if (restore != 0) {
        datSetUnitSp(1, (s16)datCalcMaxSpById(1));
    } else {
        datSetUnitSp(1, (s16)((u32)((u16)datCalcGetSpById(1)) >> 1));
    }
    for (i = 0; i < 4; i++) {
        partyId = (u16)datGetPartyId(i);
        if (partyId != 0 && datCalcIsDeadById((s16)partyId) == 0) {
            if (restore != 0) {
                datSetUnitSp((s16)partyId, (s16)datCalcMaxSpById((s16)partyId));
            } else {
                datSetUnitSp((s16)partyId, (s16)((u32)((u16)datCalcGetSpById((s16)partyId)) >> 1));
            }
        }
    }
    return 1;
}

/* Apply the selected random stat increase or decrease to a roster persona, respecting the one-to-99
 * limits. */
// FUN_00370020
s32 btlShuffleBuffedStat(s32 selector, u8 *result)
{
    s32 increase = selector & 0xFFFF;
    u16 effect = (u16)((u32)(selector & 0xFFFF0000) >> 16);
    u8 *persona;
    u16 stat;
    s16 change;
    s16 current;

    switch (effect) {
    case 8:
        stat = 3;
        break;
    case 9:
        stat = 0;
        break;
    case 11:
        stat = 4;
        break;
    case 12:
        stat = 1;
        break;
    case 13:
        stat = 2;
        break;
    default:
        kAssertFail(D_0064E790, 0x5D6);
        break;
    }
    persona = (u8 *)datPersonaRosterSlot((s16)datCalcRandomBelow(datPersonaCountValidMembers() & 0xFFFF));
    if (persona == NULL) {
        kAssertFail(D_0064E790, 0x5DC);
    }
    if ((increase & 0xFFFF) != 0) {
        s32 sum;
        change = (s16)(datCalcRandomBelow(3) + 1);
        current = (s16)(datPersonaGetBuffedStat(persona, stat) & 0xFF);
        if (current >= 0x63) {
            return 0;
        }
        sum = current + change;
        if (sum > 0x63) {
            change = 0x63 - current;
        }
        datPersonaAddStat(persona, stat, (s8)change);
    } else {
        change = (s16)(datCalcRandomBelow(1) + 1);
        current = (s16)(datPersonaGetStat(persona, stat) & 0xFF);
        if (current < 2) {
            return 0;
        }
        if (current <= change) {
            change = current - 1;
        }
        datPersonaAddStat(persona, stat, (s8)(-change));
    }
    ((BtlShuffleRewardResult *)result)->personaId = ((DatPersonaRecord *)persona)->id;
    ((BtlShuffleRewardResult *)result)->previous = (u16)change;
    return 1;
}
