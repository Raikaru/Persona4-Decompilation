/* object_size=180 window=176 normalized_diff=38; differing offsets=0x0014-0x00AC plus 0x00B0-0x00B0; levers tried: callback pointer reuse/direct calls, reload count after first callback, saved argument local, declaration/liveness adjustments, >0 vs >=1 guard; frame and control flow nearly match but callback/materialization register cascade remains. */
s32 func_003a2290(s32 arg0)
{
    s32 saved_arg0;
    s32 var_16;
    s32 temp_6;
    u8 *temp_18;

    saved_arg0 = arg0;
    temp_18 = *(u8 **)(saved_arg0 + iGpffffb610);
    temp_6 = *(s32 *)(temp_18 + 4);
    if (temp_6 >= 1) {
        var_16 = 1;
        if (*(s32 (**)())(temp_18 + 0x1C) != NULL) {
            (*(s32 (**)())(temp_18 + 0x1C))(saved_arg0, temp_18 + 0x50, temp_6, *(s32 *)(temp_18 + 0x40));
            *(s32 *)(temp_18 + 0x40) = 0;
        }
        if (*(s32 (**)())(temp_18 + 0x20) != NULL) {
            var_16 = (*(s32 (**)())(temp_18 + 0x20))(saved_arg0, temp_18 + 0x50,
                                                     *(s32 *)(temp_18 + 4));
        }
        if (var_16 == 1) {
            (*(void (**)(s32))(temp_18 + 0x10))(saved_arg0);
        }
    }
    return saved_arg0;
}
