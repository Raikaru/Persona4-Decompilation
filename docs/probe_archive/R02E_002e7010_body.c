/* object 368/384 normalized_diff 249 differing_offsets 12,13,14,15,16,19,20,21,22,23,39,60,69,72,73,74; classification exact-size-near-miss (16-byte tail zero), prologue/frame right (96-byte frame, no saved s), ruled out movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, sd-s; tried narrow s16 fields, raw-style distinct loop vars, structured first loop, hoisted sentinel. */

s32 func_002e7010(u8 *arg0, s64 arg1)
{
    s16 values[0x30];
    s16 *temp_5_2;
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_5_4;
    s16 temp_5;
    s16 temp_5_3;
    s16 temp_5_5;
    s16 temp_6;
    s16 temp_7;
    s32 var_2;
    s32 var_8_3;
    s64 var_7;
    s64 var_8;
    s64 var_8_2;
    s64 var_9;

    var_2 = 0;
    var_8 = 0;
    for (; (s16)var_8 < 0x30; var_8 = (s16)(var_8 + 1)) {
        values[(s16)var_8] = -1;
    }
    var_9 = 0;
loop_7_test:
    temp_7 = *(s16 *)(arg0 + 0x60);
    temp_5 = (s16)var_9;
    if (temp_5 < temp_7) {
        temp_5_2 = (s16 *)(arg0 + temp_5 * 2);
        if ((s16)arg1 == *temp_5_2) {
            *temp_5_2 = -1;
        }
        var_9 = (s16)(var_9 + 1);
        goto loop_7_test;
    }
    var_8_2 = 0;
loop_12_test:
    temp_5_3 = (s16)var_8_2;
    if (temp_5_3 < temp_7) {
        temp_5_4 = *(s16 *)(arg0 + temp_5_3 * 2);
        if (temp_5_4 != -1) {
            values[(u8)var_2] = temp_5_4;
            var_2 = (u8)(var_2 + 1);
        }
        var_8_2 = (s16)(var_8_2 + 1);
        goto loop_12_test;
    }
    var_8_3 = 0;
    var_7 = 0;
loop_17_test:
    temp_5_5 = (s16)var_7;
    temp_3 = *(s16 *)(arg0 + 0x60);
    if (temp_5_5 < temp_3) {
        temp_3_2 = values[temp_5_5];
        if (temp_3_2 != -1) {
            *(s16 *)(arg0 + ((u8)var_8_3 * 2)) = temp_3_2;
            var_8_3 = (u8)(var_8_3 + 1);
        }
        var_7 = (s16)(var_7 + 1);
        goto loop_17_test;
    }
    *(s16 *)(arg0 + 0x60) = temp_3 - 1;
    return 1;
}
