/* object_size=52B window=64B normalized_diff=36 differing_offsets=0,1,2,4,5,6,7,8,9,12,13,14,15,18,19,20; ruled out scalar-result plain-C loop plus schedule-on probe: b210 selects a2 for the found pointer and schedule introduces branch-likely instructions. */
s64 func_003e4960(s8 *arg0, s32 arg1) {
    s8 c;
    s32 result;

    result = 0;
    do {
        c = *arg0;
        if (c == (s8)arg1) {
            result = (s32)arg0;
        }
        arg0 += 1;
    } while (c != 0);
    return (s64)result;
}
