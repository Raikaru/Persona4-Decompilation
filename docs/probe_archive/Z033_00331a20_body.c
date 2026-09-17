/* func_00331a20 floor for src/promoted/code1_0033.c (retail 0x00331A20, window 1392B).
 *
 * measured: object 1388B / window 1392B, 51 relocations (all resolved to the
 * retail symbols, no unresolved), 26 differing words (reloc-masked) at offsets
 * 40,112,192,216,224,396,488,496,516,520,728,732,748,776,816,824,892,1108,1112,
 * 1128,1156,1180,1188,1240,1260,1280. Retail suffix after the 1388B prefix is
 * one zero word (1388-1392: 00000000), so the size shortfall is accepted tail.
 * Residual is pure register colouring plus scratch-temp choice: retail keeps
 * work in $s2 ($18) and level in $s3 ($19) while b210 keeps work in $s3 and
 * level in $s2 (12 sb/lb/lw instances plus the level copy at 516/520 and the
 * slt sources at 748/824/1128/1188), and retail uses slt $at for the first
 * range test per loop (728/1108: slt $at,$s3,$v0 vs slt $v0,$s2,$v0) while
 * b210 reuses $v0. Instruction streams are otherwise aligned 347/347 with no
 * branch-displacement or scheduling residual.
 *
 * Decisive lever: duplicated per-arm return tails. An if/else-if chain with a
 * shared `goto done` (v6) gave 254 differing words at 1368B; keeping the four
 * state-zero `return 0` tails separate (simple path, 645090 path, first-loop
 * match, 1324 path) as `return 0` in each arm (v7) closed to 26 words at
 * 1388B with identical 347/347 streams. This is the shared-vs-duplicated-tail
 * rule in docs/matching.md: retail repeats `sb; move $v0,0; b` per arm
 * (61:63,124:127,206:209,297:300) instead of branching to one shared move.
 *
 * Probed and retained as neutral/regressing (fast in-process reloc-masked
 * scoring, ~2s each, same as probe_variants): 36 single declaration swaps
 * across work/i/j/level/level_value/min/max/entry/entry2 (all 26), s32/s16
 * swaps for level/min/max/level_value (161-194 words), `register` hints on
 * work/level/both (all 26), opt_propagation off (260), opt_loop_invariants on
 * (26), opt_dead_assignments off (26), opt_common_subs off (66), first-use
 * reorder level_value before work (40, plus extra lw from saved arg0).
 * No volatile, inline asm, synthetic padding, or UB. s8 loop indices cover
 * the 28-entry 0x10-stride table (terminator -1 at index 27), level/min/max
 * stay within s16 (100*255+255=25755), all s16/s32 table accesses are aligned.
 *
 * Semantic review: dispatch (2/1/0/else), simple path, triple-called
 * 107ac0(0x13)==6||==7 with (third&FFFF-6)*0x10 index, first-loop dual-flag
 * plus range, 1324 fallback to state 2 via func_003329e0, second-loop
 * flag-plus-range, and state 1/2 returns all match IDA/Ghidra/M2C. Host smoke
 * (gcc, 9 cases: state2 null/non-null, state1 bb680 0/non-0, default, simple
 * path, first-loop match at level 510, miss->1324->state2, empty table->-1)
 * passes ALL SMOKE PASS. Boundary: host smoke does not execute EE COP/FPU
 * exceptional behaviour; retail fallback proves target hardware behaviour.
 *
 * Production stays INCLUDE_ASM per lane policy; this archive is the faithful
 * floor. Re-measure before reuse; a later edit invalidates the numbers.
 */
extern u8 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern s32 func_002be100(u8 arg0);
extern u16 func_00107ac0(s32 arg0);
extern s8 func_002bab80(void *arg0);
extern void func_002badc0(s8 arg0, s32 arg1);
extern s32 func_00106600(s16 arg0);
extern void func_00106620(s32 arg0, s32 arg1);
extern s32 func_002bb680(s8 arg0);
extern void func_002bbcf0(s8 arg0);
extern void func_002bb550(s8 arg0);
extern void func_003329e0(u8 *arg0);
extern u8 D_00644ED0[];
extern u8 D_00645090[];
extern u8 D_00645240[];
extern u8 D_0064A000[];
s32 func_00331a20(u8 *arg0)
{
    s8 *work;
    s8 i;
    s8 j;
    s32 level;
    s16 level_value;
    s16 min;
    s16 max;
    u8 *entry;
    u8 *entry2;

    work = *(s8 **)(arg0 + 0x38);
    level_value = (s16)(100 * (func_002be100(func_002e78a0()) & 0xFF) + (func_002e78e0() & 0xFF));
    switch (*work) {
    case 0:
        goto state_zero;
    case 1:
        goto state_one;
    case 2:
        goto state_two;
    default:
        goto done;
    }
state_zero:
    if (func_00106330(0x1C0) == 0) {
        work[1] = func_002bab80(D_00645240);
        func_002badc0(work[1], 0);
        (*work)++;
        func_00106390(0x1C0, 1);
        return 0;
    }
    if (((func_00107ac0(0x13) & 0xFFFF) == 6 || (func_00107ac0(0x13) & 0xFFFF) == 7)) {
        u8 *e;

        e = D_00645090 + ((func_00107ac0(0x13) & 0xFFFF) - 6) * 0x10;
        if (func_00106330(*(s32 *)(e + 12)) != 0 || *(s32 *)(e + 12) == 0) {
            work[1] = func_002bab80(D_00645240);
            func_002badc0(work[1], *(s16 *)e);
            func_00106620(*(s16 *)(e + 2), ((func_00106600(*(s16 *)(e + 2)) & 0xFF) + 1) & 0xFF);
            func_00106390(*(s32 *)(e + 4), 1);
            func_00106390(*(s32 *)(e + 8), 0);
            (*work)++;
            return 0;
        }
    }
    i = 0;
    level = level_value;
    do {
        entry = D_00644ED0 + (i * 0x10);
        min = (s16)(entry[9] + 100 * (func_002be100(entry[8]) & 0xFF));
        max = (s16)(entry[11] + 100 * (func_002be100(entry[10]) & 0xFF));
        if (*(s16 *)entry == -1) {
            goto scan_next;
        }
        if (func_00106330(*(s32 *)(entry + 12)) != 0) {
            goto scan_next;
        }
        if (func_00106330(*(s32 *)(entry + 4)) == 0 && *(s32 *)(entry + 4) != 0) {
            goto scan_next;
        }
        if (level < min) {
            goto scan_next;
        }
        if (max < level) {
            goto scan_next;
        }
        work[1] = func_002bab80(D_00645240);
        func_002badc0(work[1], *(s16 *)entry);
        func_00106390(*(s32 *)(entry + 12), 1);
        (*work)++;
        return 0;
scan_next:
        i++;
    } while (*(s16 *)entry != -1);
    if (func_00106330(0x1324) != 0) {
        *work = 2;
        func_003329e0(arg0);
        return 0;
    }
    j = 0;
    do {
        entry2 = D_00644ED0 + (j * 0x10);
        min = (s16)(entry2[9] + 100 * (func_002be100(entry2[8]) & 0xFF));
        max = (s16)(entry2[11] + 100 * (func_002be100(entry2[10]) & 0xFF));
        if (*(s16 *)entry2 == -1) {
            goto scan_next2;
        }
        if (func_00106330(*(s32 *)(entry2 + 4)) == 0 && *(s32 *)(entry2 + 4) != 0) {
            goto scan_next2;
        }
        if (level < min) {
            goto scan_next2;
        }
        if (max < level) {
            goto scan_next2;
        }
        work[1] = func_002bab80(D_00645240);
        func_002badc0(work[1], *(s16 *)entry2);
        (*work)++;
        return 0;
scan_next2:
        j++;
    } while (*(s16 *)entry2 != -1);
    return -1;
state_one:
    if (func_002bb680(work[1]) != 0) {
        func_002bbcf0(work[1]);
        goto done;
    }
    func_002bb550(work[1]);
    return -1;
state_two:
    if (func_00452380((s8 *)D_0064A000) == 0) {
        return -1;
    }
done:
    return 0;
}
