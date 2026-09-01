/* object_size=236 window=256 normalized_diff=168 differing_offsets=6,7,8,10,11,12,14,16,17,19,24,25,26,27,28 classification=undersized near-miss; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; callback loaded from absolute jtbl_008873FC and recursive body translated, but candidate is 20 bytes short of retail's 160-byte frame */
void func_003f25c0(u8 *arg0, u8 *arg1, s32 arg2)
{
    void (*callback)(u8 *arg0, u8 *arg1);
    s32 var_18;
    s32 var_20;
    u8 *temp_19;
    u8 *var_17;
    u8 *var_22;

    callback = jtbl_008873FC[0];
    if (arg1 != NULL) {
        if (arg2 > 0) {
            var_20 = 0;
            var_22 = arg1;
            do {
                temp_19 = *(u8 **)(var_22 + 0x1c);
                if (temp_19 != NULL) {
                    if ((arg2 - 1) > 0) {
                        var_18 = 0;
                        var_17 = temp_19;
                        do {
                            func_003f25c0(arg0, *(u8 **)(var_17 + 0x1c), arg2 - 2);
                            var_18 += 1;
                            var_17 += 4;
                        } while (var_18 < 0x10);
                    }
                    callback(*(u8 **)(arg0 + 0x4004), temp_19);
                }
                var_20 += 1;
                var_22 += 4;
            } while (var_20 < 0x10);
        }
        callback(*(u8 **)(arg0 + 0x4004), arg1);
    }
}
