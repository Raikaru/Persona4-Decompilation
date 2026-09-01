/* object_size=204 window=224 normalized_diff=42; differing offsets=0x0004 and 0x0020-0x00D4; levers tried: schedule-on hoist, pointer declaration/semantic register swaps, scalar-vs-pointer root, mask/source order, callback branch shape; schedule-on gave correct constant preheader but saved-register/call branch residual remains. */
s32 func_003a29f0(u8 *arg0, u8 *arg1)
{
    s64 var_18;
    u8 *temp_17;
    u8 *temp_16;

    var_18 = iGpffffb8d0 & 0x70000;
    temp_16 = *(u8 **)(arg0 + 0x4C);
    var_18 |= *(s64 *)(temp_16 + 0xC8);
    if (arg1 != NULL) {
        temp_17 = *(u8 **)arg1;
        if (func_0040f570(temp_17, 1) != 0) {
            func_00410390(temp_17, temp_16 + 0xD0, *(u8 *)(arg1 + 0x50));
            if ((*(u8 *)(temp_17 + 0x23) & 0xF) != 6) {
                var_18 |= 1;
            } else {
                var_18 &= ~1LL;
            }
            if (*(s32 *)(temp_17 + 0x14) < 9) {
                iGpffffb94c = -1;
            }
        }
    } else {
        *(s64 *)(temp_16 + 0xD0) = 0;
        var_18 &= ~1LL;
    }
    *(s64 *)(temp_16 + 0xC8) = var_18;
    return 1;
}
