/* Current-TU named-boolean probe: object 132B/window 128B, normalized_diff 63; differing word offsets 4,5,6,7,8,9,10,11,12,14,16,17,20,21,22,23,24,26,40,44,48,64,68,72,76,84,88,92,96,104,108,112,116,120,124,128. Object exceeds the retail window; archived plain-C body below remains the prior best attempt. */
typedef struct {
    u8 pad_0[0x10];
    u32 field_10;
} Func7510Rec;
void func_003b7510(Func7510Rec *arg0, s32 *arg1, u32 arg2) {
    u32 four;
    s32 *var_8;
    s32 *var_5;
    u32 var_10;
    u32 var_9;

    var_5 = arg1;
    arg0->field_10 = 1U;
    if ((arg2 > 0U) == 1) {
        var_10 = 0;
        four = 4;
loop_2:
        var_9 = arg0->field_10;
        if (var_9 < four) {
            var_8 = var_5 + var_9;
loop_4:
            if (*var_8 != 0) {
                arg0->field_10 = arg0->field_10 + 1;
                if (arg0->field_10 != four) {
                    var_9 += 1;
                    var_8 += 4;
                    if (var_9 >= four) {
                        goto block_8;
                    }
                    goto loop_4;
                }
            } else {
                goto block_8;
            }
        } else {
block_8:
            var_10 += 1;
            var_5 += 4;
            if (var_10 < arg2) {
                goto loop_2;
            }
        }
    }
}
