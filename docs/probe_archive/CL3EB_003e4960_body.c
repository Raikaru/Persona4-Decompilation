/* object_size 64 / window 64 / normalized_diff 44; differing byte offsets 1,4,5,6,8,9,10,14,18,19,20,21,22,25,28,29. */
// FUN_003E4960 M2C_CANDIDATE
#pragma optimization_level 3
#pragma schedule on
s64 func_003e4960(s8 *arg0, s64 arg1) {
    s8 *var_2;
    s8 *var_4;
    s8 temp_3;

    var_2 = NULL;
    var_4 = (s8 *)(arg0);
    do {
        temp_3 = (s8)(*var_4);
        if (temp_3 == ((s64) (arg1 << 0x38) >> 0x38)) {
            var_2 = (s8 *)(var_4);
        }
        var_4 += 1;
    } while (0 != temp_3);
    return (s64) ((s64) var_2 << 0x20) >> 0x20;
}
#pragma schedule off
#pragma optimization_level 2
