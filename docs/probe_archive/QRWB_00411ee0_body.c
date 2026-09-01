/* object_size=192 window=240 normalized_diff=151 differing_offsets=6,8,9,10,11,12,13,14,15,16,17,18,19,20,22,23 classification=undersized; ruled_out=plain raw list/slot iteration candidate remained 48 bytes short, no movz/movn/COP1 accumulator/MMI/tail-jump floor observed */
void func_00411ee0(u8 *arg0)
{
    s32 *temp_5;
    u8 *var_10;
    s32 temp_7;
    s32 var_11;
    u32 var_6;
    u32 var_8;
    u8 *var_7;
    u8 *var_9;

    var_7 = *(u8 **)(arg0 + 8);
    var_6 = 0;
    if (*(u32 *)(arg0 + 4) != 0) {
        do {
            if (*(s32 *)(var_7 + 0) != 0) {
                temp_5 = *(s32 **)(var_7 + 0x1c);
                temp_5[1] = 0;
                temp_5[0] = 0;
            }
            var_6 += 1;
            var_7 += 0x28;
        } while (var_6 < *(u32 *)(arg0 + 4));
    }
    var_9 = *(u8 **)(arg0 + 8);
    var_8 = 0;
    if (*(u32 *)(arg0 + 4) != 0) {
        do {
            if (*(s32 *)(var_9 + 0) != 0) {
                var_11 = *(s32 *)(var_9 + 4);
                if (var_11 != 0) {
                    var_10 = *(u8 **)(var_9 + 8);
                    do {
                        temp_7 = *(s32 *)var_10;
                        if (temp_7 != -1) {
                            temp_5 = *(s32 **)(*(u8 **)(arg0 + 8) +
                                               (temp_7 * 0x28) + 0x1c);
                            *temp_5 += 1;
                        }
                        var_11 -= 1;
                        var_10 += 4;
                    } while (var_11 != 0);
                }
            }
            var_8 += 1;
            var_9 += 0x28;
        } while (var_8 < *(u32 *)(arg0 + 4));
    }
}
