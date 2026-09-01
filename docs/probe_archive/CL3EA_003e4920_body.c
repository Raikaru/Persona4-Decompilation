/* object_size=64, window=64, normalized_diff=27 */
// FUN_003E4920 M2C_CANDIDATE
#pragma optimization_level 3
#pragma schedule on
s64 func_003e4920(s8 *arg0, s64 arg1) {
    s64 arg1_p = arg1;
    s8 *var_2;
    s8 *var_4;
    s8 temp_3;

    var_2 = NULL;
    var_4 = (s8 *)(arg0);
loop_1:
    temp_3 = (s8)(*var_4);
    if (temp_3 == ((s64) (arg1_p << 0x38) >> 0x38)) {
        var_2 = (s8 *)(var_4);
    } else {
        var_4 += 1;
        if (0 == temp_3) {

        } else {
            goto loop_1;
        }
    }
    return (s64) ((s64) var_2 << 0x20) >> 0x20;
}
#pragma schedule off
#pragma optimization_level 2
