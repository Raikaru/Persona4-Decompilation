/* object_size=240 window=256 normalized_diff=194 differing_offsets=4,5,6,7,8,10,11,12,14,16,17,18,19,20,21,22 classification=undersized near-miss; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; recursive body and f0510 return declaration corrected, but retail frame/saved-register prologue is 16 bytes larger than candidate */
s32 func_003f1600(u8 **arg0, u8 *arg1, s32 arg2, s32 arg3)
{
    extern s32 func_003f0510(u8 *arg0, f32 *arg1);
    u8 **var_16;
    s32 var_17;
    s32 var_18;
    s32 var_2;
    s32 temp_2;
    u8 **var_21;

    var_2 = arg2;
    var_21 = arg0;
    if (var_21 != NULL) {
        if (arg3 > 0) {
            var_18 = 0;
            do {
                var_16 = *(u8 ***)((u8 *)var_21 + 0x1c);
                if (var_16 != NULL) {
                    if ((arg3 - 1) > 0) {
                        var_17 = 0;
                        do {
                            var_2 = func_003f1600(
                                *(u8 ***)((u8 *)var_16 + 0x1c),
                                arg1,
                                var_2,
                                arg3 - 2);
                            var_17 += 1;
                            var_16 += 4;
                        } while (var_17 < 0x10);
                    } else {
                        temp_2 = func_003f0510(arg1 + (var_2 * 4), (f32 *)var_16);
                        *(u8 *)((u8 *)var_16 + 0x18) = temp_2;
                        var_2 = temp_2 + 1;
                    }
                }
                var_18 += 1;
                var_21 += 1;
            } while (var_18 < 0x10);
            return var_2;
        }
        temp_2 = func_003f0510(arg1 + (var_2 * 4), (f32 *)var_21);
        *(u8 *)((u8 *)var_21 + 0x18) = temp_2;
        var_2 = temp_2 + 1;
        return var_2;
    }
    return var_2;
}
