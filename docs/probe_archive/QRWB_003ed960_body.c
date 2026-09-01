/* object_size=208 window=256 normalized_diff=157 differing_offsets=0,4,8,10,12,14,16,18,20,22,24,26,27,28,30,31 classification=undersized; ruled_out=raw recursive flag/list candidate was 48 bytes short versus retail frame96/s0-s4, no movz/movn/COP1 accumulator/MMI/tail-jump floor observed */
void func_003ed960(u8 *arg0)
{
    extern void func_003e05f0(u8 *arg0, u8 *arg1, s32 arg2);
    extern void func_003ed850(u8 *arg0, s32 arg1);
    s32 temp_18;
    s32 temp_3;
    s32 var_5;
    u8 temp_17;
    u8 *var_19;
    u8 *var_6;
    u8 *var_7;

    temp_17 = arg0[3];
    if ((temp_17 & 4) != 0) {
        var_7 = arg0 + 0x10;
        var_6 = arg0 + 0x50;
        var_5 = 8;
        do {
            var_5 -= 1;
            temp_3 = *(s32 *)(var_7 + 4);
            *(s32 *)var_6 = *(s32 *)var_7;
            var_7 += 8;
            *(s32 *)(var_6 + 4) = temp_3;
            var_6 += 8;
        } while (var_5 > 0);
    }
    var_19 = *(u8 **)(arg0 + 0x98);
    if (var_19 != NULL) {
        do {
            temp_18 = temp_17 | var_19[3];
            if ((temp_18 & 4) != 0) {
                func_003e05f0(
                    var_19 + 0x50,
                    var_19 + 0x10,
                    *(s32 *)(var_19 + 4) + 0x50);
                var_19[3] &= (u8)~4;
            }
            func_003ed850(*(u8 **)(var_19 + 0x98), temp_18);
            var_19 = *(u8 **)(var_19 + 0x9c);
        } while (var_19 != NULL);
    }
    arg0[3] = temp_17 & (u8)~5;
}
