/* Archived best reconstruction: object 252B, window 256B, normalized_diff 10. */
void func_00201720(u8 *arg0, f32 fparg0, f32 fparg1)
{
    u16 var_5;
    f32 temp_f1;
    f32 temp_f1_2;
    if ((fparg0 == 1.0f) && (fparg1 == 1.0f)) {
        *(s16 *)(arg0 + 0x8C) = 0;
        *(s16 *)(arg0 + 0x8E) = 0;
    } else {
        temp_f1 = 4096.0f * fparg0;
        if (!(2147483648.0f > temp_f1)) {
            var_5 = (u16)((s32)0x80000000 |
                          (s32)(temp_f1 - 2147483648.0f));
        } else {
            var_5 = (u16)(s32)temp_f1;
        }
        *(u16 *)(arg0 + 0x8C) = var_5;
        temp_f1_2 = 4096.0f * fparg1;
        if (!(2147483648.0f > temp_f1_2)) {
            var_5 = (u16)((s32)0x80000000 |
                          (s32)(temp_f1_2 - 2147483648.0f));
        } else {
            var_5 = (u16)(s32)temp_f1_2;
        }
        *(u16 *)(arg0 + 0x8E) = var_5;
    }
    *(f32 *)(arg0 + 0x1C) = fparg0;
    *(f32 *)(arg0 + 0x20) = fparg1;
}
