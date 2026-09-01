/* Archived best reconstruction: object 208B, window 208B, normalized_diff 7. */
void func_00200980(u8 *arg0)
{
    s32 temp_3;
    s32 temp_5;
    u8 *temp_6;
    f32 var_f1;
    f32 var_f0;
    f32 temp_f2;

    temp_6 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(arg0 + 0x28);
    temp_5 = *(s32 *)(temp_6 + 0);
    if ((temp_5 == 0) || ((u32)temp_5 < (u32)temp_3)) return;
    temp_f2 = *(f32 *)(temp_6 + 4);
    if (temp_3 >= 0) var_f1 = (f32)temp_3;
    else {
        u32 temp_7;
        u32 temp_8;
        temp_7 = (u32)temp_3 >> 1;
        temp_8 = (u32)temp_3 & 1;
        temp_7 |= temp_8;
        var_f1 = (f32)(s32)temp_7;
        var_f1 += var_f1;
    }
    if (temp_5 >= 0) var_f0 = (f32)temp_5;
    else {
        u32 temp_7;
        temp_7 = (u32)temp_5;
        var_f0 = (f32)(s32)((temp_7 >> 1) | (temp_7 & 1));
        var_f0 += var_f0;
    }
    var_f1 /= var_f0;
    var_f0 = *(f32 *)(temp_6 + 8) - temp_f2;
    var_f0 = func_0020_mul(var_f1, var_f0);
    var_f1 = var_f0 + temp_f2;
    *(f32 *)(D_0076449C + 0xDC) = fGpffff81a8 * var_f1;
}
