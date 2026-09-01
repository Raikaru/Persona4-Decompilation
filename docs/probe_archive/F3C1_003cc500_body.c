/* func_003cc500: object_size=136, window=96, normalized_diff=99, differing_word_offsets=9,14,15,16,18,19,20,21,22,23,24,25,26,28,30,31; retail final global store is `sd $a1,-18192($gp)` (not a prologue save), and the s64 global/GP addressing is correct; explicit switch with ascending cases (obj144/nd102), descending if/goto chain, s64 temporary, and branch-shape/prologue pragmas were ruled out; residual is retail compact beql chain. */
s32 func_003cc500(s32 arg0) {
    s64 temp;
    s64 value;

    temp = iGpffffb8f0;
    value = temp & ~0x1E0;
    if (arg0 == 6) {
        value |= 0x160;
        goto done;
    }
    if (arg0 == 5) {
        value |= 0xC0;
        goto done;
    }
    if (arg0 == 4) {
        value |= 0x120;
        goto done;
    }
    if (arg0 == 3) {
        value |= 0x80;
        goto done;
    }
    if (arg0 == 2)
        value |= 0x60;
done:
    iGpffffb8f0 = value;
}
