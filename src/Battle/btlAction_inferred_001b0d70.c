#include "btl_action_internal.h"
#include "btl_effect_internal.h"
/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
#include "datPersona_internal.h"
typedef struct BtlAction BtlAction;
extern s32 iGpffffb3ac;
extern u8 *D_0076449C;

/* Canonical grouped function declarations. */

/* Source unit: src/Battle/btlOrder_001b0d00.c */

/* Source unit: src/Battle/btlOrder_grouped.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/Battle/btlOrder_grouped.c; members 001b0d70-001b1280 */

// FUN_001B0D70
/* Append an action to the first empty order slot; return zero if all twelve slots are occupied. */
s32 btlActionQueuePush(u8 *action)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == 0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto store;
    }
    return 0;
store:
    *p = (s32)action;
    return 1;
}

/* Append a follow-up action to the first empty active slot; return zero when all twelve slots are occupied. */
// FUN_001B0E30
s32 btlActionActiveListPush(s32 action)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x2CC);
    i = 0;
    goto check;
loop:
    if (*p == 0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto store;
    }
    return 0;
store:
    *p = action;
    return 1;
}

/* measured: opt_rebuildconditionals off probe for 0e90 guard polarity. */
// FUN_001B0E90
/* Allow queued or follow-up actions to run only when their order slot is currently eligible. */
s32 btlActionCanRunNow(u8 *action)
{
    s32 activeAction;
    u8 *battle;

    if (((BtlAction *)action)->unk_28 != 0) {
        goto ret1;
    }
    if (((BtlAction *)action)->unk_29 == 0) {
        goto check;
    }
ret1:
    return 1;
check:
    battle = (u8 *)iGpffffb3ac;
    if ((*(s32 *)&((BtlBattleState *)battle)->flags & 8) == 0) {
        return 1;
    }
    if ((((BtlAction *)action)->flags & 4) == 0) {
        activeAction = ((BtlBattleState *)battle)->activeActions[0];
        if ((activeAction != 0) && ((u8 *)activeAction == action)) {
            return 1;
        }
    }
    return ((BtlBattleState *)battle)->actionQueue[1] == (s32)action;
}

/* measured: close opt_rebuildconditionals off for func_001b0e90. */
// FUN_001B0F20
/* Find an action in the twelve-slot queue and shift its predecessors back one position. */
s32 btlActionQueueMoveToFront(s32 action)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == action) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto shift;
    }
    return 0;
shift:
    while ((s32)i > 0) {
        *p = *(p - 1);
        p--;
        i--;
    }
    *p = action;
    return 1;
}

/* Move an existing queued action behind the contiguous occupied entries; return zero if it was not queued. */
// FUN_001B0FA0
s32 btlActionQueueMoveToBack(u8 *action)
{
    s32 *p;
    u32 i;
    s32 nextAction;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == (s32)action) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto limit;
    }
    return 0;
compact:
    nextAction = *(p + 1);
    if (nextAction == 0) {
        goto store;
    }
    *p = nextAction;
    p++;
    i++;
limit:
    if (i < 0xB) {
        goto compact;
    }
store:
    *p = (s32)action;
    return 1;
}

/* Recovered.  Three measured shapes carry this one.  The loop bound is the
   expression `j < i - 1`, not a variable: retail hoists `i - 1` out of both
   loops, and an explicit `limit` local puts it in the preheader ahead of the
   hoisted constant instead of behind it.  The declaration order below fixes
   the temporaries ($t3 index, $t4 pointer, $t5 flag) - permuting it is the
   only thing that moves them.  `opt_dead_assignments off` keeps the
   pre-loop `swapped = 1` store, whose constant retail materialises in the
   outer preheader and reuses inside the loop (`move $t5,$a1`); with the
   store eliminated the constant is rebuilt inside the loop instead.  Both
   pragmas are scoped: the file-wide `opt_dead_assignments off` costs a
   match elsewhere in this unit. */
/* Stably sort queued actions by descending agility; optional enemy scores use a clamped 90–110 percent roll. */
// FUN_001B1020
#pragma push
/* measured: cached inner bounds and a while-sort retain 32 or more baseline words; either toggle alone differs. */
#pragma opt_loop_invariants on
#pragma opt_dead_assignments off
/* Sort descending by agility, optionally applying the enemy-only 90 through 110 percent random factor. */
void btlActionQueueSortByRank(s32 randomizeEnemies)
{
    u8 ranks[0xC];
    u8 currentRank;
    s32 swapped;
    BtlAction **scan;
    u32 i;
    BtlAction *curr;
    u8 nextRank;
    BtlAction *next;
    BtlAction **sort;
    u32 j;

    scan = (BtlAction **)(D_0076449C + 0x29C);
    for (i = 0; i < 0xCU; i++) {
        curr = *scan;
        if (curr == NULL) {
            break;
        }
        if (randomizeEnemies != 0 && (((BtlUnit *)*(u8 * *)&((BtlAction *)(u8 *)curr)->unit)->genus) == 1) {
            u32 agility = datCalcGetBattleStat(*(u8 * *)&((BtlUnit *)*(u8 * *)&((BtlAction *)(u8 *)curr)->unit)->datUnit, PERSONA_STAT_AGI) & 0xFF;
            u32 bonus = datCalcRandomBelow(0x15) + 0x5A;
            u32 score = (agility * bonus) / 100U;
            if (score == 0) {
                score = 1;
            } else if (score > 99U) {
                score = 99;
            }
            ranks[i] = (u8)score;
        } else {
            ranks[i] = datCalcGetBattleStat(*(u8 * *)&((BtlUnit *)*(u8 * *)&((BtlAction *)(u8 *)curr)->unit)->datUnit, PERSONA_STAT_AGI);
        }
        scan++;
    }

    swapped = 1;
    do {
        swapped = 0;
        for (sort = (BtlAction **)(D_0076449C + 0x29C), j = 0; j < i - 1; j++, sort++) {
            curr = *sort;
            next = sort[1];
            if (curr != NULL && next != NULL) {
                currentRank = ranks[j];
                nextRank = ranks[j + 1];
                if (currentRank < nextRank) {
                    *sort = next;
                    sort[1] = curr;
                    ranks[j] = nextRank;
                    ranks[j + 1] = currentRank;
                    swapped = 1;
                }
            }
        }
    } while (swapped);
}
#pragma pop

/* Sort the twelve order slots so units of the given kind keep their place:
   count the occupied prefix, then bubble adjacent units of different kinds.
   The counting pass reuses the sort cursor and index; scoped opt_lifetimes
   splits their two lifetimes, which gives the sort loop's cursor and index
   their retail registers. */
// FUN_001B11C0
#pragma push
/* measured: separate counting cursors and cached inner bounds retain 33 or more words; either toggle alone differs. */
#pragma opt_lifetimes on
/* measured: keeping lifetimes alone still leaves 33 differing words without invariant hoisting. */
#pragma opt_loop_invariants on
void btlActionQueueSortKeepingKind(s32 genus)
{
    u32 count;
    u16 key;
    s32 changed;
    u32 i;
    u8 **scan;
    u8 *left;
    u8 *right;
    u32 kind;

    scan = (u8 **)((u8 *)iGpffffb3ac + 0x29C);
    i = 0;
    while (i < 0xC) {
        if (*scan == NULL) break;
        scan++;
        i++;
    }
    count = i;
    key = genus;
    do {
        changed = 0;
        scan = (u8 **)((u8 *)iGpffffb3ac + 0x29C);
        i = 0;
        while (i < count - 1) {
            left = scan[0];
            right = scan[1];
            if (left != NULL && right != NULL) {
                kind = ((BtlUnit *)*(u8 * *)&((BtlAction *)left)->unit)->genus;
                if (kind != ((BtlUnit *)*(u8 * *)&((BtlAction *)right)->unit)->genus && kind != key) {
                    scan[0] = right;
                    scan[1] = left;
                    changed = 1;
                }
            }
            i++;
            scan++;
        }
    } while (changed != 0);
}
#pragma pop

/* For an enemy opening, move one or two of the leading enemy actions behind the rest of the queue. */
// FUN_001B1280
void btlActionQueueRequeueLeadingEnemies(s32 genus)
{
    u8 *base;
    u8 **scan;
    u8 *obj;
    u8 **start;
    s32 key;
    u32 i;
    s32 count;
    s32 requeueCount;
    u32 j;

    key = genus & 0xFFFF;
    if (key != 1) {
        return;
    }
    base = D_0076449C;
    scan = (u8 **)(base + 0x29C);
    for (count = 0, i = 0; i < 0xCU; i++) {
        obj = *scan;
        if (obj == NULL) {
            break;
        }
        if ((((BtlUnit *)*(u8 * *)&((BtlAction *)obj)->unit)->genus != key)) {
            break;
        }
        count++;
        scan++;
    }
    requeueCount = 2;
    switch (count) {
    case 5:
        requeueCount = 2;
        break;
    case 4:
        requeueCount = 2;
        break;
    case 3:
        requeueCount = 1;
        break;
    case 2:
        requeueCount = 1;
        break;
    case 1:
    default:
        return;
    }
    start = (u8 **)(base + (count - 1) * 4 + 0x29C);
    for (j = 0; j < (u32)requeueCount; j++) {
        btlActionQueueMoveToBack(*start);
        start--;
    }
}

