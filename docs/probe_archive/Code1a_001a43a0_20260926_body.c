/* func_001a43a0 (code1_001a.c, window 1104B) -- 2026-09-26 group 0 round 4.
 * Fresh rewrite from the retail listing. Object is 1096B against retail's
 * 1100B of code, with 45 aligned instruction edits (the old guarded draft
 * had 83 edits at 1092B). Its verify nd is 719, inflated by the
 * one-word size offset. NOT installed.
 *
 * What the rewrite fixed over the old draft:
 * - u16 counters/lists written naturally, with separate block-scoped copy and
 *   shuffle loops. A byte-address copy store
 *   `*(u8 **)(arg0 + start * 4 + m * 4 + 0x38)` gives retail's hoisted
 *   a2 = arg0 + start*4 and `sw 0x38(v0)` (the pointer and array forms
 *   do not).
 * - The last task's store is task[8] = cutin[0x58]. The old draft wrote
 *   +0x58 as the destination.
 * - Declaration order: retail's registers rank lowest-first (unit, self,
 *   nA, nB, i, work, skill, found). Mine match except for the rotation below.
 *
 * Residual (the same wall the old note recorded):
 * 1. Five-register rotation. Retail has unit s0, self s1, nA s2, i s4,
 *    work s6. This build gives work s0, unit s1, self s2, nA s4, i s6, so
 *    `work` ranks lowest here and highest in retail. A 400-step
 *    declaration-order hill-climb over all 11 top-level locals, a
 *    block-scoped `work`, and a separate variable for the func_001fa320
 *    result are all inert.
 * 2. `kind` (func_0023d8e0 result, s16) is kept in memory in retail
 *    (sh 0xB0 / lh 0xB0). Here it is sign-extended and spilled as sw/lw.
 * 3. The loop index `andi i` is recomputed at the body top in retail. Here
 *    it is CSE'd from the loop compare.
 * Callee contracts used (they agree with the definitions): func_001d7f10
 * returns u16, datCalcIsDead(s32, s32), func_00233a90 returns s8, and
 * func_00242800(u8 *, s32). func_001fa320 and func_002027e0 are
 * defined `void` in btlCutin.c/btlFormation.c but return their task
 * pointer, which every caller uses. Installing this needs those definitions
 * changed to return u8 * (the bytes are likely unchanged, since v0 already
 * holds the task).
 */
#pragma push
#pragma opt_loop_invariants on
// FUN_001A43A0
void func_001a43a0(u8 *arg0)
{
    extern u16 func_001d7f10(u8 *arg0, u8 *arg1, u16 arg2, u32 arg3);
    extern u32 datCalcIsDead(s32 unit, s32 hpDelta);
    extern s8 func_00233a90(u8 *arg0, s32 arg1);
    extern s32 func_00242800(u8 *arg0, s32 arg1);
    extern u8 *func_001fa320(void);
    u8 *listB[12];
    u8 *listA[12];
    u8 *unit;
    u8 *self;
    u16 nA;
    u16 nB;
    u16 i;
    u8 *work;
    u16 skill;
    s32 found;
    u16 mode;
    s16 kind;
    u8 *task;

    if (func_00193cd0(0xC00) != 0) {
        return;
    }
    self = *(u8 **)(arg0 + 0x90);
    skill = func_001f01a0(arg0, (s32)self);
    mode = func_001d7f10(arg0, arg0 + 0x98, skill, 0);
    kind = func_0023d8e0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), skill);
    found = 0;
    nB = 0;
    nA = 0;
    for (i = 0; i < *(u16 *)(arg0 + 0xD0); i++) {
        unit = *(u8 **)(arg0 + 0x98 + i * 4);
        if (!(*(u16 *)(unit + 0x1A) & 1)) {
            continue;
        }
        work = *(u8 **)(unit + 0x30);
        if (datCalcIsDead(*(s32 *)(work + 0xA64), 0) != 0) {
            continue;
        }
        if (func_00233a90(*(u8 **)(work + 0xA64), 0x10) > 0) {
            continue;
        }
        if (func_00242800(*(u8 **)(work + 0xA64), kind) & 0x7000000) {
            continue;
        }
        if (datCalcChkBadStatus(*(s32 *)(work + 0xA64), 0x100000) == 0) {
            listA[nA++] = unit;
        }
        if (self != unit) {
            listB[nB++] = unit;
        } else {
            found = 1;
        }
    }
    func_001eb3b0(arg0 + 0x38);
    *(s16 *)(arg0 + 0x6C) = 2;
    *(u16 *)(arg0 + 0x6E) = skill;
    if (mode == 0) {
        if (nA > 0) {
            *(u8 **)(arg0 + 0x38) = listA[func_00231d70(nA)];
        } else if (found) {
            *(u8 **)(arg0 + 0x38) = self;
        } else {
            *(u8 **)(arg0 + 0x38) = listB[func_00231d70(nB)];
        }
        *(u16 *)(arg0 + 0x6A) = 1;
    } else {
        u16 start;
        u16 k;

        nA = nB;

        for (k = 0; k < nA * 3; k++) {
            u16 a = func_00231d70(nA);
            u16 b = func_00231d70(nA);

            if (a != b) {
                u8 *tmp = listB[a];

                listB[a] = listB[b];
                listB[b] = tmp;
            }
        }
        if (found) {
            *(u8 **)(arg0 + 0x38) = self;
            *(u16 *)(arg0 + 0x6A) = 1;
            start = 1;
        } else {
            *(u16 *)(arg0 + 0x6A) = 0;
            start = 0;
        }
        if (nA > 1) {
            if (nA == 2) {
                nB = 1;
            } else {
                nB = func_00231d70(nA - 1) + 1;
            }
        }
        {
            u16 m;

            for (m = 0; m < nB; m++) {
                *(u8 **)(arg0 + start * 4 + m * 4 + 0x38) = listB[m];
            }
        }
        *(u16 *)(arg0 + 0x6A) += nB;
    }
    *(u16 *)(arg0 + 0x18) |= 2;
    task = func_001f99c0(arg0, 9, 0, 0, 0);
    *(u64 *)(task + 0x60) = *(u64 *)arg0;
    func_00194590(task, 1);
    work = func_001fa320();
    *(u64 *)(work + 0x60) = *(u64 *)arg0;
    func_00194590(work, 1);
    task = func_002027e0();
    task[0] = 4;
    *(u64 *)(task + 8) = *(u64 *)(work + 0x58);
    func_00194590(task, 1);
    btlActionSetState((BtlAction *)arg0, 0xF);
}
#pragma pop
