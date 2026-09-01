/* Attempted reconstruction; retained for archaeology. Best probe stayed oversized at 420 bytes versus the 400-byte retail window (normalized diff 94).
 * Residual is the bulk initialization loop's saved-register/scheduling shape and repeated -1 materialization. */
u32 *func_00395100(u32 *arg0, u32 arg1, u32 arg2)
{
    s32 sp5C;
    s32 sp58;
    s32 temp_19;
    s32 temp_6;
    s32 var_4;
    s32 var_6;
    u32 *temp_4;
    u32 var_5;
    u32 *temp_18;

    temp_6 = arg1 * 2;
    temp_19 = arg2 * 0x14;
    temp_18 = *(u32 **)(arg0 + 1) + temp_6;
    temp_18[1] = (u32)(*jtbl_008873E8)(temp_19, 0x30122);
    temp_4 = (u32 *)temp_18[1];
    if (temp_4 != NULL) {
        func_0043f9c8(temp_4, 0, temp_19);
        var_5 = 0;
        if (arg2 != 0) {
            if (arg2 >= 9U) {
                var_4 = 0;
                do {
                    var_5 += 8;
                    *(s32 *)((u8 *)temp_18[1] + var_4 + 0x10) = -1;
                    *(s32 *)((u8 *)temp_18[1] + var_4 + 0x24) = -1;
                    *(s32 *)((u8 *)temp_18[1] + var_4 + 0x38) = -1;
                    *(s32 *)((u8 *)temp_18[1] + var_4 + 0x4C) = -1;
                    *(s32 *)((u8 *)temp_18[1] + var_4 + 0x60) = -1;
                    *(s32 *)((u8 *)temp_18[1] + var_4 + 0x74) = -1;
                    *(s32 *)((u8 *)temp_18[1] + var_4 + 0x88) = -1;
                    *(s32 *)((u8 *)temp_18[1] + var_4 + 0x9C) = -1;
                    var_4 += 0xA0;
                } while (var_5 < arg2 - 8);
            }
            if (var_5 < arg2) {
                var_6 = var_5 * 0x14;
                do {
                    var_5 += 1;
                    *(s32 *)((u8 *)temp_18[1] + var_6 + 0x10) = -1;
                    var_6 += 0x14;
                } while (var_5 < arg2);
            }
        }
        temp_18[0] = arg2;
        return arg0;
    }
    sp58 = 0x122;
    sp5C = func_003df590(0x80000013, temp_19);
    func_003df4d0(&sp58);
    return NULL;
}
