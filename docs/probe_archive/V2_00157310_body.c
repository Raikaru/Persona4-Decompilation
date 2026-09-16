// FUN_00157310
void func_00157310(u8 *arg0, u16 arg1, u16 arg2, s16 arg3)
{
    extern s32 iGpffffb230;
    extern s32 iGpffffb228;
    extern s32 iGpffffb22c;
    extern s32 iGpffffb224;

    s16 spCE;
    s32 spB0;
    s32 spA0;
    s16 *temp_4;
    s16 *temp_4_2;
    s16 *temp_4_3;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_17;
    s32 temp_19;
    s32 temp_21;
    s32 temp_22;
    s32 var_17;
    s32 var_18;
    s32 var_18_2;
    s32 var_19;
    s32 var_23;
    s8 temp_30_4;
    u8 temp_23_2;
    u8 temp_30;
    u8 temp_30_2;
    u8 temp_30_3;
    u8 *temp_23;
spCE = arg3;
    var_23 = 0;
    temp_21 = arg1 & 0xFFFF;
    if (((temp_21 + (*( u8 *)((u8 *)(arg0) + 1))) - 1) >= 0x10) {
        func_0046d730(&D_005F05E8, 0x20B);
    }
    temp_22 = arg2 & 0xFFFF;
    if (((temp_22 + (*( u8 *)((u8 *)(arg0) + 2))) - 1) >= 0x18) {
        func_0046d730(&D_005F05E8, 0x20C);
    }
    (*( s8 *)((u8 *)((func_00155280() + ((arg2 & 0xFFFF) << 8) + ((arg1 & 0xFFFF) * 0x10))) + 0x55)) = 1;
    var_19 = 0;
loop_12:
    if (var_19 < (s32) (*( u8 *)((u8 *)(arg0) + 2))) {
        var_18 = 0;
        temp_17 = (temp_22 + var_19) << 8;
        spB0 = (s32) (arg0 + (var_19 * 3));
        spA0 = (s32) (arg0 + (var_19 * 0xC));
loop_10:
        if (var_18 < (s32) (*( u8 *)((u8 *)(arg0) + 1))) {
            if ((*( u8 *)((u8 *)((temp_17 + func_00155280() + ((temp_21 + var_18) * 0x10))) + 0x54)) == 0) {
                temp_4 = (s16 *)(arg0 + ((var_19 - (*( s8 *)((u8 *)(arg0) + 0x17))) * 5));
                if ((*( u8 *)((u8 *)(temp_4 + (var_18 - (*( s8 *)((u8 *)(arg0) + 0x16)))) + 0x18)) == 1) {
                    temp_16 = (temp_21 + var_18) * 0x10;
                    (*( s8 *)((u8 *)((temp_17 + func_00155280() + temp_16)) + 0x54)) = 1;
                    temp_4_2 = (s16 *)(temp_17 + func_00155280() + temp_16);
                    (*( u8 *)((u8 *)(temp_4_2) + 0x55)) = (u8) ((*( u8 *)((u8 *)(temp_4_2) + 0x55)) | (*( u8 *)((u8 *)((spB0 + var_18)) + 0xD)));
                    temp_23 = (u8 *)(spA0 + (var_18 * 4));
                    temp_30 = (u8)((*( u8 *)((u8 *)(temp_23) + 0x32)));
                    (*( u8 *)((u8 *)((temp_17 + func_00155280() + temp_16)) + 0x5E)) = temp_30;
                    temp_30_2 = (u8)((*( u8 *)((u8 *)(arg0) + 1)));
                    (*( u8 *)((u8 *)((temp_17 + func_00155280() + temp_16)) + 0x5A)) = temp_30_2;
                    temp_30_3 = (u8)((*( u8 *)((u8 *)(arg0) + 2)));
                    (*( u8 *)((u8 *)((temp_17 + func_00155280() + temp_16)) + 0x5B)) = temp_30_3;
                    temp_30_4 = (s8)((*( s8 *)((u8 *)(arg0) + 0)));
                    (*( s8 *)((u8 *)((temp_17 + func_00155280() + temp_16)) + 0x58)) = temp_30_4;
                    (*( u8 *)((u8 *)((temp_17 + func_00155280() + temp_16)) + 0x59)) = (u8) spCE;
                    temp_23_2 = (u8)((*( u8 *)((u8 *)(temp_23) + 0x33)));
                    (*( u8 *)((u8 *)((temp_17 + func_00155280() + temp_16)) + 0x5F)) = temp_23_2;
                    var_23 = 1;
                }
            }
            var_18 += 1;
            goto loop_10;
        }
        var_19 += 1;
        goto loop_12;
    }
    if (var_23 == 1) {
        var_18_2 = 0;
loop_24:
        if (var_18_2 < 5) {
            var_17 = 0;
            temp_16_2 = temp_22 + var_18_2;
loop_22:
            if (var_17 < 5) {
                if (((*( s8 *)((u8 *)(arg0) + 0x17)) + temp_16_2) < 0x18) {
                    temp_19 = temp_21 + var_17;
                    if (((*( s8 *)((u8 *)(arg0) + 0x16)) + temp_19) < 0x10) {
                        temp_4_3 = (s16 *)(func_00155280() + (((*( s8 *)((u8 *)(arg0) + 0x17)) + temp_16_2) << 8));
                        if ((*(u8 *)((u8 *)(temp_4_3 + (((*(s8 *)(arg0 + 0x16)) + temp_19) * 0x10)) + 0x54)) == 0 && (*(u8 *)((u8 *)((arg0 + (var_18_2 * 5) + var_17)) + 0x18)) != 0) {
                            (*(s8 *)((u8 *)(func_00155280() + (((*(s8 *)(arg0 + 0x17)) + temp_16_2) << 8) + (((*(s8 *)(arg0 + 0x16)) + temp_19) * 0x10)) + 0x54)) = 2;
                        }
                    }
                }
                var_17 += 1;
                goto loop_22;
            }
            var_18_2 += 1;
            goto loop_24;
        }
    }
    (*( s32 *)((u8 *)&iGpffffb230)) = (s32) ((*( s32 *)((u8 *)&iGpffffb230)) + 1);
    if ((*( s8 *)((u8 *)(arg0) + 0)) == 2) {
        (*( s32 *)((u8 *)&iGpffffb228)) = (s32) ((*( s32 *)((u8 *)&iGpffffb228)) + 1);
    }
    if ((*( s8 *)((u8 *)(arg0) + 0)) >= 9) {
        (*( s32 *)((u8 *)&iGpffffb22c)) = (s32) ((*( s32 *)((u8 *)&iGpffffb22c)) + 1);
    }
    (*( s32 *)((u8 *)&iGpffffb224)) = (s32) ((*( s32 *)((u8 *)&iGpffffb224)) + ((*( u8 *)((u8 *)(arg0) + 1)) * (*( u8 *)((u8 *)(arg0) + 2))));

}
