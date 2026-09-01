/* func_003fe210 object=248 window=272 normalized_diff=184 differing_offsets=0,1,2,3,4,5,6,7,8,9,10,11,12,14,15,16 classification=undersized; ruled_out=missing-prologue-floor, saved-s-register-count(0), argument-count(4) */
void func_003fe210(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3)
{
    s32 temp_3;
    s32 var_11;
    s32 var_3;
    s32 var_7;
    u8 *var_10;
    u8 *var_6;
    s32 (**var_9)(void);

    var_6 = arg2;
    var_11 = 0;
    if (arg1 > 0) {
        if (arg1 >= 9) {
            var_3 = 0;
            if ((arg1 >= 0) && (arg1 < 0x7fffffff)) {
                var_3 = 1;
            }
            if (var_3 != 0) {
                var_10 = arg0;
                do {
                    *(s32 (**)(void))(var_10 + 0) = func_003fe200;
                    var_11 += 8;
                    *(s32 (**)(void))(var_10 + 4) = func_003fe200;
                    *(s32 (**)(void))(var_10 + 8) = func_003fe200;
                    *(s32 (**)(void))(var_10 + 0xc) = func_003fe200;
                    *(s32 (**)(void))(var_10 + 0x10) = func_003fe200;
                    *(s32 (**)(void))(var_10 + 0x14) = func_003fe200;
                    *(s32 (**)(void))(var_10 + 0x18) = func_003fe200;
                    *(s32 (**)(void))(var_10 + 0x1c) = func_003fe200;
                    var_10 += 0x20;
                } while (var_11 < (arg1 - 8));
            }
        }
        if (var_11 < arg1) {
            var_9 = (s32 (**)(void))(arg0 + (var_11 * 4));
            do {
                var_11 += 1;
                *var_9 = func_003fe200;
                var_9 += 1;
            } while (var_11 < arg1);
        }
    }
    var_7 = arg3 - 1;
    if (arg3 != 0) {
        do {
            temp_3 = *(s32 *)(var_6 + 0);
            if ((temp_3 < arg1) && (temp_3 >= 0)) {
                *(s32 *)(arg0 + (temp_3 * 4)) = *(s32 *)(var_6 + 4);
            }
            var_6 += 8;
            var_7 -= 1;
        } while (var_7 != 0);
    }
}
