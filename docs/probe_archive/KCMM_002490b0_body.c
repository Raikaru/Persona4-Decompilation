/* object_size=200 window=208 normalized_diff=24 differing_word_offsets=68,80,92,100,104,108,112,116,120; ruled out direct stack comparisons, guarded loop tests, explicit-goto branch joins, shared-result locals, declaration-order permutations, and opt_rebuildconditionals off. Residual is the loop branch/layout shape: retail keeps bne-to-advance plus an unconditional b-to-found, while compliant C collapses the second comparison branch. */
// FUN_002490B0 NONMATCHING
u8 *func_002490b0(s32 seed) {
    s32 sp4C;
    s32 sp48;
    u8 *temp_17;
    u8 *p;
    s32 count;
    s32 a0;
    s32 b0;
    s32 i;

    temp_17 = D_008814D0[0] + 8;
    p = temp_17;
    count = *(s32 *)(D_008814D0[0] + 4);
    func_001104d0(seed, &sp4C, &sp48);
    i = 0;
    a0 = sp4C;
    b0 = sp48;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            break;
        }
        p += 0x24;
        i++;
    }
    if (i == count) {
        i = -1;
    }
    if (i != -1) {
        return temp_17 + i * 0x24;
    }
    return NULL;
}
