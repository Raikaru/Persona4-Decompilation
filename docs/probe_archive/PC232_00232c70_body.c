// object_size 260, window 272, normalized_diff 4; differing offsets 208, 220, 224, 232
// FUN_00232C70 NONMATCHING
u32 func_00232c70(u8 *arg0, s32 arg1)
{
    u32 v;
    s32 temp_3;
    u32 flag;

    if (((s32)(arg1 & 0xFFFF) < 0) || ((arg1 & 0xFFFF) >= 5)) {
        func_0046d730(D_00635938, 0x313);
    }
    if ((*(u16 *)arg0 & 4) != 0) {
        v = func_00232b40(arg0, arg1);
        v &= 0xFF;
    } else {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0x31A);
        }
        v = func_00109bf0(*(u16 *)(arg0 + 2), arg1);
        v &= 0xFF;
    }
    flag = (*(s32 *)(arg0 + 0xC) & 0x80) != 0;
    if (flag != 0) {
        v >>= 1;
        v &= 0xFF;
    }
    temp_3 = v & 0xFF;
    if (temp_3 > 0) {
        goto clamp_value;
    }
    v = 1;
    goto done_value;
clamp_value:
    if (temp_3 < 0x64) {
        goto done_value;
    }
    v = 0x63;
done_value:
    return v;
}
