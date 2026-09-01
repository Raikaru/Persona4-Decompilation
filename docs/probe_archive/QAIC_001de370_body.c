/* object 720B / window 720B / normalized_diff 0 words / differing offsets none / classification MATCH. */
/* COP1 accumulator chain reproduced by ordinary C arithmetic under measured opt_loop_invariants on. */
/* Ruled out: absolute 0x609600 literals (wrong HI16/LO16 form), direct 50.0f + score (wrong add.s operand order), pointer addition without an integer-offset cast (wrong addu operand order), and bubble locals without the measured pragma (wrong frame/colouring). */
u32 func_001de370(u8 *arg0)
{
    u32 i;
    u32 random;
    u32 cumulative;
    s16 scores[16];
    u32 selectionIndex;
    u32 total;

    if (*(u16 *)(arg0 + 0xD0) == 1)
        return *(u32 *)(arg0 + 0x98);

    total = 0;
    i = 0;
    while (i < *(u16 *)(arg0 + 0xD0)) {
        u8 *unit;
        s16 *score;
        u32 max;
        u32 current;
        f32 scoreFloat;
        f32 bonus;

        total += D_00609600[i];
        unit = *(u8 **)(arg0 + i * 4 + 0x98);
        score = scores + i;
        *score = 0;
        max = func_00231f80(*(u32 *)(*(u32 *)(unit + 0x30) + 0xA64)) & 0xFFFF;
        current = func_00231ed0(*(u32 *)(*(u32 *)(unit + 0x30) + 0xA64)) & 0xFFFF;
        *score += (s16)(100.0f - 100.0f * ((f32)current / (f32)max));
        switch (func_002326c0(*(u32 *)(*(u32 *)(unit + 0x30) + 0xA64))) {
        case 0x40:
            bonus = 50.0f;
            scoreFloat = (f32)*score;
            *score = (s16)(scoreFloat + bonus);
            break;
        default:
            break;
        }
        i++;
    }
    {
        u32 bubbleIndex;
        s16 *sortScore;
        s32 swapped;
        u32 one;
        one = 1;
        do {
        swapped = 0;
        for (bubbleIndex = 0; bubbleIndex < *(u16 *)(arg0 + 0xD0) - 1; bubbleIndex++) {
            s32 left;
            s32 right;
            s16 *nextScore;

            sortScore = scores + bubbleIndex;
            nextScore = sortScore + 1;
            right = *nextScore;
            left = *sortScore;
            if (left < right) {
                u8 *entry;
                u32 temp;

                entry = arg0 + bubbleIndex * 4;
                temp = *(u32 *)(entry + 0x98);
                *(u32 *)(entry + 0x98) = *(u32 *)(entry + 0x9C);
                *(u32 *)(entry + 0x9C) = temp;
                *sortScore = right;
                *nextScore = left;
                swapped = one;
            }
        }
        } while (swapped != 0);
    }
    cumulative = 0;
    random = func_00231d70(total);
    selectionIndex = 0;
    for (; selectionIndex < *(u16 *)(arg0 + 0xD0); selectionIndex++) {
        cumulative += D_00609600[selectionIndex];
        if (random < cumulative)
            return *(u32 *)((u8 *)(selectionIndex * 4) + (u32)arg0 + 0x98);
    }
    return 0;
}
