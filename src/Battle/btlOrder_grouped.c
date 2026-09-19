/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
typedef struct BtlAction BtlAction;
extern s32 iGpffffb3ac;
extern u8 *D_0076449C;

/* Canonical grouped function declarations. */
static u32 btlOrderRemoveAction(BtlAction** actions, u32 arrSize, BtlAction* action);

/* Source unit: src/Battle/btlOrder_001b0d00.c */

// FUN_001B0D00
static u32 btlOrderRemoveAction(BtlAction** actions, u32 arrSize, BtlAction* action)
{
    BtlAction* curr;
    s32 i;

    for (i = 0; i < arrSize; i++)
    {
        curr = *actions;
        if (curr != action)
        {
            actions++;
        }
        else
        {
            break;
        }
    }

    if (i == arrSize)
    {
        return 0;
    }

    for (; i < arrSize - 1; i++)
    {
        *actions = *(actions + 1);
        actions++;
    }

    *actions = NULL;

    return 1;
}

// FUN_001B0D70
s32 func_001b0d70(u8 *arg0)
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
    *p = (s32)arg0;
    return 1;
}
/* Same-TU helper knowledge preserves a2/a3/t0 across removal calls.
   Measured: object 84B/window 96B, no instruction differences; 12B zero tail. */
// FUN_001B0DD0
s32 func_001b0dd0(u8 *arg0)
{
    BtlAction **actions;
    s32 result;

    actions = (BtlAction **)((u8 *)iGpffffb3ac + 0x29C);
    result = 0;
    while (btlOrderRemoveAction(actions, 0xC, (BtlAction *)arg0) == 1) {
        result = 1;
    }
    return result;
}
// FUN_001B0E30
s32 func_001b0e30(s32 arg0)
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
    *p = arg0;
    return 1;
}
/* measured: opt_rebuildconditionals off probe for 0e90 guard polarity. */
#pragma opt_rebuildconditionals off
// FUN_001B0E90
s32 func_001b0e90(u8 *arg0)
{
    s32 temp;
    u8 *p;

    if (*(u8 *)(arg0 + 0x28) != 0) {
        goto ret1;
    }
    if (*(u8 *)(arg0 + 0x29) == 0) {
        goto check;
    }
ret1:
    return 1;
check:
    p = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(p + 0xC) & 8) == 0) {
        return 1;
    }
    if ((*(u16 *)(arg0 + 0x18) & 4) == 0) {
        temp = *(s32 *)(p + 0x2CC);
        if ((temp != 0) && ((u8 *)temp == arg0)) {
            return 1;
        }
    }
    return *(s32 *)(p + 0x2A0) == (s32)arg0;
}
/* measured: close opt_rebuildconditionals off for func_001b0e90. */
#pragma opt_rebuildconditionals on
// FUN_001B0F20
s32 func_001b0f20(s32 arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == arg0) {
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
    *p = arg0;
    return 1;
}
// FUN_001B0FA0
s32 func_001b0fa0(u8 *arg0)
{
    s32 *p;
    u32 i;
    s32 temp;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == (s32)arg0) {
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
    temp = *(p + 1);
    if (temp == 0) {
        goto store;
    }
    *p = temp;
    p++;
    i++;
limit:
    if (i < 0xB) {
        goto compact;
    }
store:
    *p = (s32)arg0;
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
// FUN_001B1020
#pragma push
#pragma opt_loop_invariants on
#pragma opt_dead_assignments off
void func_001b1020(s32 arg0)
{
    u8 ranks[0xC];
    u8 curr_rank;
    s32 swapped;
    BtlAction **scan;
    u32 i;
    BtlAction *curr;
    u8 next_rank;
    BtlAction *next;
    BtlAction **sort;
    u32 j;

    scan = (BtlAction **)(D_0076449C + 0x29C);
    for (i = 0; i < 0xCU; i++) {
        curr = *scan;
        if (curr == NULL) {
            break;
        }
        if (arg0 != 0 && (*(u8 *)(*(u8 **)((u8 *)curr + 0x30) + 0xA2)) == 1) {
            u32 r19 = func_00232c70(*(u8 **)(*(u8 **)((u8 *)curr + 0x30) + 0xA64), 3) & 0xFF;
            u32 bonus = func_00231d70(0x15) + 0x5A;
            u32 score = (r19 * bonus) / 100U;
            if (score == 0) {
                score = 1;
            } else if (score > 99U) {
                score = 99;
            }
            ranks[i] = (u8)score;
        } else {
            ranks[i] = func_00232c70(*(u8 **)(*(u8 **)((u8 *)curr + 0x30) + 0xA64), 3);
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
                curr_rank = ranks[j];
                next_rank = ranks[j + 1];
                if (curr_rank < next_rank) {
                    *sort = next;
                    sort[1] = curr;
                    ranks[j] = next_rank;
                    ranks[j + 1] = curr_rank;
                    swapped = 1;
                }
            }
        }
    } while (swapped);
}
#pragma pop
/* measured: F1B0 floor 192B/192B/5wd fresh (fnalign 5: key $t3 vs $t1 + i $t1 vs $t3 at +0x34,+0x4c,+0x88,+0x9c,+0xa4; $t1/$t3 swap). */
/* measured: ruled out this session value-side (decl perms 5,8,8 per owner) -- u16 key 33wd, i+1<count 35wd, key-inside-do 35wd, u8 kind+key&0xFF 33wd, i/scan order swap 35wd, key-after-i 35wd, compare/store reversal 35wd; all 33-35 vs 5; pragmas on the 5wd body: loop-inv removal 35 (installed pragma load-bearing, 5 -> 35), cse-off 35, propag-off 36, sched-on 42. $t1/$t3 allocator wall stands; honest 5wd floor kept. No volatile/asm. */
/* measured: pair sweep 2026-09-17 `python3 -E -s tools/pragma_sweep.py src/Battle/btlOrder_grouped.c func_001b11c0 --pairs` banked 5 (already carries opt_loop_invariants on); best ties 5 (loop-inv single + 3 pairs: loop+dead, loop+strength, loop+unroll). All 28 pairs neutral or worse: loop+peephole 23, commons/dead/propag/strength/unroll/peephole singles + 15 pairs 35, loop+propag 36, schedule block 42-45. Two-def pins per assignment all flat at 5: i duplicate-init 5, i kill-then-init 5, key duplicate 5 (retail key $t3 / i $t1; pinned lower $t1 i). fnalign 48/48 $t3/$t1 wall stands. */
/* 2026-09-18 lead pass, 6 more measured variants on top of the permuter's
   16379 compiles; floor confirmed at 5 words.  48/48 instructions and the
   entire residual is one temporary-register swap: retail holds the masked
   `arg0` in $t3 and the inner counter in $t1, this body has them the other
   way round, and the five differing words are the five instructions that
   name them.
   Not reachable by moving the values around: declaring `i` before `key`
   costs 5 -> 8, declaring it last costs 5 -> 11, and computing `key` before
   the counting loop costs 5 -> 24.  Recomputing `key` inside the do-while,
   declaring `i` as `s32`, and inlining `arg0 & 0xFFFF` at its use all tie at
   5 with a byte-identical stream.
   t-register numbering is not declaration-driven here; it would take a
   different number of live temporaries to rotate, and every shape that
   changes that count also changes the instruction stream. */
/* 2026-09-19 pair close-out (Main request): fnalign 48/48, 5 edits +2 reloc-only =7 floor_distance edits, 7 words. Frame frameless both sides (no addiu $sp) -- match, closed on frame. */
/* Pairs, all against retail at 0x001b11c0: */
/* - reloc-only [0:1] lw $v1,-0x4c54($gp) vs lw $v1,($gp): immediate (GP addend, linker-owned). */
/* - replace [13:14] andi $t3,$a0,0xffff vs andi $t1,$a0,0xffff: register-only rotation $t1<->$t3 (key), exchange class 7m, closed per 7ah. */
/* - reloc-only [17:18] lw $v1,-0x4c54($gp) vs lw $v1,($gp): immediate (GP addend). */
/* - replace [19:20] move $t1,$zero vs move $t3,$zero: register-only rotation (i init). */
/* - replace [34:35] beq $a2,$t3,.+5 vs beq $a2,$t1,.+5: register-only rotation (kind vs key); branch offset identical. */
/* - replace [39:40] addiu $t1,$t1,1 vs addiu $t3,$t3,1: register-only rotation (i++). */
/* - replace [41:42] sltu $v1,$t1,$a0 vs sltu $v1,$t3,$a0: register-only rotation (i < count-1). */
/* No $a0-$t0 spill-order move, no operand-order, no branch-offset, no nop-vs-work in this residual. Five swaps one pair ($t1/$t3 = key/i); next person: finished on frame and count, open only on temp colour. */
// FUN_001B11C0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_001b11c0(s32 arg0)
{
    u8 **count_scan;
    u32 count;
    u32 key;
    s32 changed;
    u32 i;
    u8 **scan;
    u8 *left;
    u8 *right;
    u32 kind;

    count_scan = (u8 **)((u8 *)iGpffffb3ac + 0x29C);
    count = 0;
    while (count < 0xC) {
        if (*count_scan == NULL) break;
        count_scan++;
        count++;
    }
    key = arg0 & 0xFFFF;
    do {
        changed = 0;
        scan = (u8 **)((u8 *)iGpffffb3ac + 0x29C);
        i = 0;
        while (i < count - 1) {
            left = scan[0];
            right = scan[1];
            if (left != NULL && right != NULL) {
                kind = *(u8 *)(*(u8 **)(left + 0x30) + 0xA2);
                if (kind != *(u8 *)(*(u8 **)(right + 0x30) + 0xA2) && kind != key) {
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
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b11c0);
#endif
// FUN_001B1280
void func_001b1280(s32 arg0)
{
    u8 *base;
    u8 **scan;
    u8 *obj;
    u8 **start;
    s32 key;
    u32 i;
    s32 count;
    s32 reverse_count;
    u32 j;

    key = arg0 & 0xFFFF;
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
        if ((*(u8 *)(*(u8 **)(obj + 0x30) + 0xA2) != key)) {
            break;
        }
        count++;
        scan++;
    }
    reverse_count = 2;
    switch (count) {
    case 5:
        reverse_count = 2;
        break;
    case 4:
        reverse_count = 2;
        break;
    case 3:
        reverse_count = 1;
        break;
    case 2:
        reverse_count = 1;
        break;
    case 1:
    default:
        return;
    }
    start = (u8 **)(base + (count - 1) * 4 + 0x29C);
    for (j = 0; j < (u32)reverse_count; j++) {
        func_001b0fa0(*start);
        start--;
    }
}
/* Auto-inlining preserves the externally called 13c0 body as well as its
   expansion in 1450. Plain inline drops that required standalone symbol.
   Measured: 13c0 132B/144B, 1450 188B/192B; only retail zero tails remain. */
#pragma auto_inline on
// FUN_001B13C0
void func_001b13c0(u8 *arg0)
{
    u8 *ptr;
    u8 *global;

    ptr = arg0;
    if ((*(u16 *)(ptr + 0x18) & 4) != 0) {
        btlOrderRemoveAction((BtlAction **)((u8 *)iGpffffb3ac + 0x2CC), 0xC, (BtlAction *)ptr);
        *(u16 *)(ptr + 0x18) &= 0xFFFB;
        goto done;
    }
    global = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(global + 0xC) & 8) != 0) {
        *(u8 **)(global + 0x298) = ptr;
        func_001b0fa0(ptr);
    }
done:
    global = (u8 *)iGpffffb3ac;
    *(u16 *)(global + 0x290) |= 8;
}
// FUN_001B1450
void func_001b1450(u8 *arg0)
{
    u8 *global;
    if ((*(u16 *)(arg0 + 0x18) & 4) != 0) {
        func_001b13c0(arg0);
    } else {
        global = (u8 *)iGpffffb3ac;
        if ((*(s32 *)(global + 0xC) & 8) != 0) {
            *(u8 **)(global + 0x298) = arg0;
        }
        global = (u8 *)iGpffffb3ac;
        *(u16 *)(global + 0x290) |= 8;
    }
}
#pragma auto_inline off
