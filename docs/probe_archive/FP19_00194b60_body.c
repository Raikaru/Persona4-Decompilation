/* Best attempt: object 252B, window 256B, normalized_diff 1. The only residual was the preceding same-TU callback address relocation for func_00194b50. */
u8 *func_00194b60(void)
{
    u8 *temp_16;
    s32 j;
    s32 i;
    u8 *base;
    s32 value;

    func_0044ea90(D_005F6C00, 0x51);
    temp_16 = (u8 *)D_008873E8[0](0x90, 0x40000);
    func_0043f9c8(temp_16, 0, 0x90);
    *(s32 *)(temp_16 + 0x40) = 0xFF00;
    i = 0;
    value = 1;
    goto first_check;
first_body:
    *(u8 *)(temp_16 + ((i & 0xFFFF) << 4)) = (u8)value;
    i = (i + 1) & 0xFFFF;
first_check:
    if ((i & 0xFFFF) < 2) {
        goto first_body;
    }
    base = temp_16 + 0x20;
    j = 0;
    value = 1;
    goto second_check;
second_body:
    *(u8 *)(base + ((j & 0xFFFF) << 4)) = (u8)value;
    j = (j + 1) & 0xFFFF;
second_check:
    if ((j & 0xFFFF) < 2) {
        goto second_body;
    }
    *(u8 *)(temp_16 + 0x47) =
        (u8)(*(u8 *)(temp_16 + 0x47) | 0x31);
    *(s32 *)(temp_16 + 0x6C) = (s32)func_00194b50;
    return temp_16;
}
