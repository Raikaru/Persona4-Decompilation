/* Reconstructed func_001b1020 (src/Battle/btlOrder_grouped.c, 416B window;
 * 408B of real code, last two words zero padding).
 *
 * measured: b210 -O2 leaves object 404B / window 416B, normalized_diff 125,
 * 41 reloc-masked differing words. The first 240 bytes (the whole rank-
 * collection loop, both branches, the level/bonus percentage and its clamp)
 * are byte-exact. Every remaining difference is in the bubble-sort pass and
 * is register allocation plus one scheduling choice, never logic:
 *   - limit hoists into $t1 here, retail uses $a0
 *   - the sort cursor reuses callee-saved $s1; retail uses temp $t4
 *   - the swap flag lands in $t2 with an inline `addiu $t2,$zero,1`; retail
 *     hoists the constant once into $a1 and copies it with `move $t5,$a1`
 *   - `ranks[j+1]` addresses as 0x51($v1) here against retail's 1($t0)
 *
 * Tried, no change to the residual: separate block-scope cursor for the sort
 * pass (both a plain local and a for-initializer form), an explicit hoisted
 * `limit` local, and s32 instead of u32 for limit/swapped. Declaration order
 * was load-bearing and is already applied: with `BtlAction **scan` declared
 * before `u32 i`, the pointer takes $s1 and the index $s0, matching retail;
 * the reverse order swaps them and costs the whole first loop.
 *
 * Same floor family as the archived sibling func_001b11c0 in this unit
 * (F1B0_001b11c0_body.c), which records the identical key/index-swap class
 * and that "separate count/sort boundaries do not improve this floor".
 *
 * Proven callee contracts, both taken from their matched definitions:
 * func_00232c70 is `u8 func_00232c70(u8 *arg0, s32 arg1)` (datCalc.c:557) and
 * func_00231d70 is `u32 func_00231d70(u32 arg0)` (datCalc.c:111).
 *
 * Production remains ASM. The rank pass is a percentage of the level field
 * clamped to 1..99; the sort pass swaps adjacent slots whose rank ascends,
 * skipping empty slots. Preserve the fresh global base in each pass and the
 * `i - 1` bound computed once before the outer do/while.
 */
void func_001b1020(s32 arg0)
{
    u8 ranks[0xC];
    BtlAction **scan;
    u32 i;
    u32 j;
    s32 swapped;
    s32 limit;
    BtlAction *curr;
    BtlAction *next;
    u8 curr_rank;
    u8 next_rank;

    scan = (BtlAction **)(D_0076449C + 0x29C);
    for (i = 0; i < 0xCU; i++) {
        curr = *scan;
        if (curr == NULL) {
            break;
        }
        if (arg0 != 0 && (*(u8 *)(*(u8 **)((u8 *)curr + 0x30) + 0xA2)) == 1) {
            s32 level = func_00232c70(*(u8 **)(*(u8 **)((u8 *)curr + 0x30) + 0xA64), 3);
            s32 bonus = (s32)func_00231d70(0x15) + 0x5A;
            u32 score = (level * bonus) / 100u;
            if (score == 0) {
                score = 1;
            } else if (score > 99) {
                score = 99;
            }
            ranks[i] = (u8)score;
        } else {
            ranks[i] = func_00232c70(*(u8 **)(*(u8 **)((u8 *)curr + 0x30) + 0xA64), 3);
        }
        scan++;
    }

    limit = (s32)(i - 1);
    do {
        BtlAction **sort;
        swapped = 0;
        for (sort = (BtlAction **)(D_0076449C + 0x29C), j = 0; j < limit; j++) {
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
            sort++;
        }
    } while (swapped);
}

