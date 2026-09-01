/* SKIPPED candidate for func_0016a960 (src/Kosaka/Field/k_fldFrame.c).
 * object 600B / window 608B, normalized_diff 183. Compiler register-
 * allocation residual, not closed this session. */
s32 func_0016a960(s32 arg0, s32 arg1, s32 arg2, f32 fparg0)
{
    f32 fraction;
    s32 var_22;
    s32 var_19;
    s32 temp_3_2;
    s32 var_21;
    u16 temp_3_3;
    s32 temp_2;
    u8* temp_2_2;
    u8* temp_3;
    u8* var_20;

    fraction = fparg0;
    temp_3 = *(u8**)(iGpffff9db0 + 0x28);
    if (temp_3 == NULL)
    {
        return 0;
    }
    if ((*(s32*)temp_3 & 1) != 0)
    {
        return func_00169780((s32)*(void**)(temp_3 + 0xc),
                             (f32*)arg0, (f32*)arg1, fraction);
    }
    var_21 = 0;
    if ((func_0014a200() == 1) ||
        (((temp_3_2 = *(s32*)iGpffff9db0) >= 51) &&
         (temp_3_2 < 79)))
    {
        var_20 = func_001452b0(0xc);
        temp_2 = (s32)func_00145270(arg2);
        if ((arg2 & 0xffff) == 0xffff)
        {
            temp_2_2 = func_003e9700(
                *(s32*)((u8*)func_00457120() + 4));
            var_22 = (s32)((600.0f +
                            *(f32*)(temp_2_2 + 0x30)) /
                           1200.0f);
            var_19 = (s32)((600.0f +
                            *(f32*)(temp_2_2 + 0x38)) /
                           1200.0f);
        }
        else if (((arg2 & 0xffc00) >> 10) == 1)
        {
            var_22 = func_001687d0(*(s32*)(temp_2 + 0x220));
            var_19 = func_001687e0(*(s32*)(temp_2 + 0x220));
        }
        else
        {
            var_22 = func_001687d0(*(s32*)(temp_2 + 0x228));
            var_19 = func_001687e0(*(s32*)(temp_2 + 0x228));
        }
        temp_3_3 = *(u16*)((u8*)func_00155280() +
                           (var_19 << 8) + (var_22 << 4) + 0x56);
        while (var_20 != NULL)
        {
            if (*(u16*)var_20 == temp_3_3)
            {
                var_21 = *(s32*)(*(u8**)(var_20 + 0x1a0) + 8);
                break;
            }
            var_20 = *(u8**)(var_20 + 0x138);
        }
    }
    else
    {
        var_21 = *(s32*)(*(u8**)(iGpffff9db0 + 0x28) + 8);
    }
    return func_0016a110(var_21, (f32*)arg0, (f32*)arg1, arg2, fraction);
}
