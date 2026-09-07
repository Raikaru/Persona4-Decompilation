/* Full-owner exact recovery: 740 executable bytes / 752B retail window.
 * All eight relocations resolved; twelve omitted retail zero-tail bytes.
 * Requires y_fclCombine.c types, helper declarations and both table symbols.
 * Five s32 weights and five s8 IDs are real buffers, not IDA frame aliases. */
#pragma opt_loop_invariants on
void func_00303de0(u8 *arg0)
{
    s32 weights[5];
    s8 ids[5];
    s8 *p;
    u32 total;
    s8 count;
    s16 cumulative;
    u32 selectedAddress;
    s8 *calendar;
    s32 month;
    s16 i;
    s16 j;
    s16 k;
    s32 roll;
    s32 *entry;

    p = *(s8 **)(arg0 + 0x38);
    total = 0;
    count = 0;
    cumulative = 0;
    /* Keep the pre-callback selector snapshot without forming a pointer
       before the table when the selector is -1. */
    selectedAddress = (u32)D_0063FCA0 + p[724] * 28;
    month = func_002e78a0();
    calendar = (s8 *)D_006406F0 + (s8)func_00110a60(month, func_002e78e0()) * 20;
    p[735] = 0;
    if (p[724] == -1) {
        for (i = 0; i < 5; i++) {
            s8 id;
            s8 weight;
            ids[i] = 0;
            weights[i] = 0;
            id = calendar[i * 4];
            if (id != 0) {
                weight = calendar[i * 4 + 1];
                if (weight == 100) {
                    p[p[735] + 730] = id;
                    p[735]++;
                } else {
                    entry = weights + count;
                    *entry = weight;
                    total += weight;
                    ids[count] = id;
                    count++;
                }
            }
        }
    } else {
        for (j = 0; j < 5; j++) {
            s8 id;
            s8 weight;
            ids[j] = 0;
            weights[j] = 0;
            id = ((s8 *)selectedAddress)[j * 4 + 8];
            if (id != 0) {
                weight = ((s8 *)selectedAddress)[j * 4 + 9];
                if (weight == 100) {
                    p[p[735] + 730] = id;
                    p[735]++;
                } else {
                    entry = weights + count;
                    *entry = weight;
                    total += weight;
                    ids[count] = id;
                    count++;
                }
            }
        }
    }
    if (count > 0) {
        roll = (s16)(func_003b7060() % total);
        for (k = 0; k < count; k++) {
            cumulative += (s16)weights[k];
            if (roll < cumulative) {
                p[p[735] + 730] = ids[k];
                p[735]++;
                return;
            }
        }
    }
}
#pragma opt_loop_invariants reset
