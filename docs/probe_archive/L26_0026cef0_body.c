// FUN_0026CEF0
f32 func_0026cef0(s8 *arg0, f32 *arg1, f32 *arg2,
                  f32 fparg0, f32 fparg1)
{
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spE8[4];
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spA0[4];
    f32 sp90[4];
    f32 sp80[4];
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f22;
    f32 temp_f3;
    f32 temp_f4;
    f32 var_f20;
    f32 var_f23;
    s32 var_16;
    s32 var_17;
    s32 var_5;
    s32 var_5_2;
    s8 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3_2;
    u8 *temp_3_3;

    var_f23 = 0.0f;
    temp_3 = *arg0;
    temp_f21 = (1.0f / (f32)temp_3) / 20.0f;
    var_f20 = 0.0f;
    if (fparg1 <= fparg0) {
        var_5 = 0;
        while (var_5 < 4) {
            temp_3_2 = (u8 *)(arg0 + ((temp_3 - 1) * 0x24) +
                               (var_5 * 0xC));
            spA0[var_5] = *(f32 *)(temp_3_2 + 4);
            sp90[var_5] = *(f32 *)(temp_3_2 + 8);
            sp80[var_5] = *(f32 *)(temp_3_2 + 0xC);
            var_5 += 1;
        }
        func_0026c960(fGpffff82d4, spA0, sp90, sp80,
                      &sp16C, &sp164, &sp15C);
        func_0026c960(1.0f, spA0, sp90, sp80,
                      &sp168, &sp160, &sp158);
        spD8 = sp168 - sp16C;
        spDC = sp160 - sp164;
        spE0 = sp158 - sp15C;
        func_003e4180(&spD8);
        sp118 = sp168;
        sp11C = sp160;
        sp120 = sp158;
        arg1[0] = sp118;
        arg1[1] = sp11C;
        arg1[2] = sp120;
        sp108 = sp168 - sp16C;
        sp10C = sp160 - sp164;
        sp110 = sp158 - sp15C;
        func_003e40b0(spE8, &sp108);
        func_0026c860(spE8, arg2);
        return 1.0f;
    }
    var_17 = 0;
    while (var_17 < *arg0) {
        var_5_2 = 0;
        while (var_5_2 < 4) {
            temp_3_3 = (u8 *)(arg0 +
                               ((var_5_2 + (var_17 * 3)) * 0xC));
            spA0[var_5_2] = *(f32 *)(temp_3_3 + 4);
            sp90[var_5_2] = *(f32 *)(temp_3_3 + 8);
            sp80[var_5_2] = *(f32 *)(temp_3_3 + 0xC);
            var_5_2 += 1;
        }
        var_16 = 0;
        while (var_16 < 0x14) {
            temp_f22 = (f32)var_16 * fGpffff83d0;
            func_0026c960(temp_f22, spA0, sp90, sp80,
                          &sp154, &sp14C, &sp144);
            func_0026c960((f32)(var_16 + 1) * fGpffff83d0,
                          spA0, sp90, sp80,
                          &sp150, &sp148, &sp140);
            spC8 = sp150 - sp154;
            spCC = sp148 - sp14C;
            spD0 = sp140 - sp144;
            temp_f0 = func_003e4180(&spC8);
            sp118 = sp150;
            sp11C = sp148;
            sp120 = sp140;
            var_f23 += temp_f0;
            if (!(var_f23 < fparg0)) {
                temp_f4 = 1.0f - ((var_f23 - fparg0) / temp_f0);
                temp_f3 = temp_f21 * temp_f4;
                sp108 = sp150 - sp154;
                sp10C = sp148 - sp14C;
                sp110 = sp140 - sp144;
                arg1[0] = sp108 * temp_f4 + sp154;
                arg1[1] = sp10C * temp_f4 + sp14C;
                arg1[2] = sp110 * temp_f4 + sp144;
                temp_f21_2 = temp_f22 + temp_f3;
                func_0026c960(temp_f21_2, spA0, sp90, sp80,
                              &sp13C, &sp134, &sp12C);
                func_0026c960(temp_f21_2 - fGpffff842c,
                              spA0, sp90, sp80,
                              &sp138, &sp130, &sp128);
                spB8 = sp138 - sp13C;
                spBC = sp130 - sp134;
                spC0 = sp128 - sp12C;
                func_003e4180(&spB8);
                spF8 = sp13C - sp138;
                spFC = sp134 - sp130;
                sp100 = sp12C - sp128;
                func_003e40b0(spE8, &spF8);
                func_0026c860(spE8, arg2);
                return var_f20 + temp_f3;
            }
            var_f20 += temp_f21;
            var_16 += 1;
        }
        var_17 += 1;
    }
    return 0.0f;
}
/* measured: optimization_level 1 register-coloring probe for func_0026db60. */
#pragma optimization_level 1
/* measured: opt_propagation off probe for func_0026db60 loop test ordering. */
