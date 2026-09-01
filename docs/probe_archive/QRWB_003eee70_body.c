/* object_size=140 window=240 normalized_diff=114 differing_offsets=4,5,6,7,8,10,11,12,14,15,16,18,19,22,23,24 classification=undersized; ruled_out=plain s8/s64 case-fold candidate compiled 100 bytes short, while retail has repeated dsll32/dsra32 sign-extension chains; no movz/movn/COP1 accumulator/MMI/tail-jump floor observed */
s32 func_003eee70(s8 *arg0, s8 *arg1)
{
    s64 temp_3_2;
    s64 var_6;
    s64 var_7;
    s8 temp_2;
    s8 temp_3;

    for (;;) {
        temp_3 = *arg0;
        if (temp_3 != 0) {
            temp_2 = *arg1;
            if (temp_2 != 0) {
                var_7 = temp_3;
                var_6 = temp_2;
                if ((var_7 >= 0x61) && (var_7 < 0x7b)) {
                    var_7 -= 0x20;
                }
                temp_3_2 = var_6;
                if ((temp_3_2 >= 0x61) && (temp_3_2 < 0x7b)) {
                    var_6 -= 0x20;
                }
                if ((s8)var_7 == (s8)var_6) {
                    arg0 += 1;
                    arg1 += 1;
                    continue;
                }
                return 0;
            }
        }
        if (temp_3 == *arg1) {
            return 1;
        }
        return 0;
    }
}
