// FUN_00235110 archive (wave Io lane IoD cut off mid-work; body is the live state at cutoff, status MISMATCH-nd240).
void func_00235110(u8 *arg0)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s8 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    s64 temp_18_2;
    s64 temp_21;
    s8 var_3;
    s64 var_3_2;
    u32 var_19;

    var_19 = 0;
    goto loop_check;
loop_body:
    temp_18 = var_19 & 0xFF;
    if (temp_18 >= 0x18) {
        func_0046d730(D_00635938, 0x4C1);
    }
    if (temp_18 < 0x10) {
        temp_3 = func_002332a0(arg0, (u8)var_19);
    } else {
        temp_3 = (s8)((*(s32 *)(arg0 + 0x14) & (1 << temp_18)) != 0);
    }
    var_3 = temp_3;
    if (temp_18 >= 0x18) {
        func_0046d730(D_00635938, 0x42A);
    }
    temp_4 = (u8)var_19;
    temp_17 = temp_4 >> 1;
    temp_3 = temp_17 & 0xFFFF;
    temp_16 = temp_4 & 1;
    if (temp_16 != 0) {
        var_3_2 = (s64)((s64)((s32)*(u8 *)(arg0 + (temp_3 & 0xFFFF) + 0x24) >> 4) << 0x38) >> 0x38;
    } else {
        var_3_2 = (s64)((*(u8 *)(arg0 + (temp_3 & 0xFFFF) + 0x24) & 0xF) << 0x38) >> 0x38;
    }
    if (var_3 != 0) {
        temp_21 = (s64)((s64)(var_3_2 << 0x38) >> 0x38);
        if (temp_21 < 0xF) {
            if (temp_18 >= 0x18) {
                func_0046d730(D_00635938, 0x45E);
            }
            temp_18_2 = (s64)((temp_21 + 1) << 0x38) >> 0x38;
            if (temp_18_2 < 0) {
                func_0046d730(D_00635938, 0x45F);
            }
            temp_3_2 = temp_17 & 0xFFFF;
            if (temp_16 != 0) {
                *(u8 *)(arg0 + (temp_3_2 & 0xFFFF) + 0x24) =
                    (*(u8 *)(arg0 + (temp_3_2 & 0xFFFF) + 0x24) & 0xF) |
                    ((temp_18_2 & 0xF) * 0x10);
            } else {
                *(u8 *)(arg0 + (temp_3_2 & 0xFFFF) + 0x24) =
                    (*(u8 *)(arg0 + (temp_3_2 & 0xFFFF) + 0x24) & 0xF0) |
                    (temp_18_2 & 0xF);
            }
        }
    }
    var_19 += 1;
loop_check:
    if (var_19 < 0x10U) {
        goto loop_body;
    }
}
