/* object 240B / window 240B / normalized_diff 110 / differing offsets 4,6,7,8,10,11,14,15,16,28,44,60,76,96,98,99 / classification exact-size near-miss; corrected block-scope extern u8 iGpffffb984; ruled out: movz/movn, COP1 accumulator chain, standalone MMI, framed tail jump, custom COP1 sqrt, rd-form mult floor; explicit branch graph reproduces control-flow layout but MWCC schedules li 1 after flags load and keeps common sb out of branch delay slots; schedule on produced 208B/nd97; optimization_level 1 produced 256B/nd167. */
// FUN_003D0140
void func_003d0140(u8 *arg0, s32 arg1) {
    extern u8 iGpffffb984;
    s32 one;
    s32 flags;

    one = 1;
    flags = *(s32 *)(*(u8 **)(arg0 + 0xC) + (one - 1));
    if ((flags & 1) == one) goto block_bit1;
    if ((flags & 0xFF) == 0) goto block_low;
    if ((flags & 2) == 2) goto block_low;
    if ((flags & 0x10) == 0x10) goto block_bit10;
    if ((flags & 8) != 8) goto block_bit8_false;
    *(u8 *)(arg0 + 0x29) = 2;
    *(u8 *)(arg0 + 0x28) = iGpffffb984 | 0x10;
    goto block_after;
block_bit8_false:
    *(u8 *)(arg0 + 0x29) = 1;
    *(u8 *)(arg0 + 0x28) = iGpffffb984 | 0x14;
    goto block_after;
block_after:
    if (arg1 != 2) goto block_or;
    goto block_done;
block_bit1:
    *(u8 *)(arg0 + 0x29) = 4;
    *(u8 *)(arg0 + 0x28) = iGpffffb984;
    goto block_after;
block_low:
    *(u8 *)(arg0 + 0x29) = 3;
    *(u8 *)(arg0 + 0x28) = iGpffffb984 | 4;
    goto block_after;
block_bit10:
    *(u8 *)(arg0 + 0x29) = 4;
    *(u8 *)(arg0 + 0x28) = iGpffffb984;
    goto block_after;
block_or:
    *(u8 *)(arg0 + 0x28) |= 2;
block_done:
    return;
}
