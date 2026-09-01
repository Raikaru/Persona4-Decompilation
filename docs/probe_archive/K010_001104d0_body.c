// measured: object_size 144, window 176, normalized_diff 85, differing offsets 0x8-0xF, 0x14-0x23, 0x28-0x2F, 0x50-0x5F, 0x64-0x9B; ruled out s16/s32 parameter widths, while/for/do/goto/trampoline/explicit-dispatch loop shapes, declaration permutations, named table base/limit/value locals, load-order variants, narrow casts, and pointer/index spellings. Retail's function is 176 bytes; candidate remains 144 bytes, indicating reconstruction/window fill rather than polish.
void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 temp_8;
    s32 temp_9;
    s32 var_10;
    s32 var_11;
    s32 var_12;
    var_11 = arg0 % 365;
    var_12 = 3;
    var_10 = 0;
loop_5:
    if (var_10 < 12) {
        temp_9 = var_12 + 1;
        temp_8 = temp_9 - 1;
        if (var_11 >= D_005E45E0[temp_8 % 12]) {
            var_11 -= D_005E45E0[temp_8 % 12];
            var_12 = temp_9;
            if (temp_9 >= 12) var_12 = 0;
            var_10 += 1;
            goto loop_5;
        }
    }
    *arg1 = var_12 + 1;
    *arg2 = var_11 + 1;
}
