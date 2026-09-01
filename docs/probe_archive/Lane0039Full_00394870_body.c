/* Closest nonmatching probe (generated-shaped plain C; nd 245, object 592B). Reverted to INCLUDE_ASM. */
// FUN_00394870
void func_00394870(u8 *arg0, u8 *arg1, u8 *arg2,
                   s32 (*arg3)(), s32 (*arg4)(), s32 (*arg5)())
{
    f32 sp13c;
    f32 sp12c;
    s32 sp128;
    s32 sp124;
    f32 sp120;
    f32 sp11c;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10c;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 *spf4;
    f32 *spf0;
    f32 *spec;
    s32 spe8;
    f32 spdc[3];
    f32 spd0[3];
    u8 *spcc;
    u8 *spc8;
    s32 (*spc4)();
    s32 (*spc0)();
    s32 (*spbc)();
    f32 *var19;
    f32 *var20;
    f32 *var21;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f4_2;
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;
    s32 temp_4_3;
    s32 temp_5_3;
    s32 var18;
    u8 *temp_3_2;
    u8 *temp_4_2;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *var17;

    var21 = &sp100;
    var20 = &sp10c;
    var19 = &sp118;
    var18 = 0;
    spc4 = arg3;
    spc8 = arg2;
    spc0 = arg4;
    spbc = arg5;
    temp_f20 = 1.0f / *(f32 *)(arg2 + 0xC);
    sp124 = *(s32 *)(*(s32 *)(arg0 + 0x5C) + 28 * *(s16 *)(arg1 + 4) + 0x14);
    sp128 = *(s32 *)(*(s32 *)(arg0 + 0x5C) + 28 * *(s16 *)(arg1 + 6) + 0x14);
    sp12c = *(f32 *)(arg1 + 0xC) * *(f32 *)(arg1 + 0x10);
    var17 = *(u8 **)(arg0 + 0x2C);
    spcc = arg0;
    if (*(s32 *)(arg0 + 0x10) > 0) {
loop_2:
        temp_3 = sp128;
        temp_2 = sp124;
        if (temp_2 != temp_3) {
            temp_f0 = sp12c;
            temp_4 = (s32)(*(u16 *)var17 * 0xC);
            temp_5 = (u8 *)(temp_2 + temp_4);
            temp_4_2 = (u8 *)(temp_3 + temp_4);
            temp_f1 = *(f32 *)temp_4_2 - *(f32 *)temp_5;
            sp100 = temp_f1;
            temp_f4 = temp_f1 * temp_f0;
            sp104 = *(f32 *)(temp_4_2 + 4) - *(f32 *)(temp_5 + 4);
            sp104 *= temp_f0;
            sp108 = (*(f32 *)(temp_4_2 + 8) - *(f32 *)(temp_5 + 8)) * temp_f0;
            sp100 = temp_f4;
            sp100 = temp_f4 + *(f32 *)temp_5;
            sp104 += *(f32 *)(temp_5 + 4);
            sp108 += *(f32 *)(temp_5 + 8);
            temp_4_3 = (s32)(*(u16 *)(var17 + 2) * 0xC);
            temp_5_2 = (u8 *)(temp_2 + temp_4_3);
            temp_4_4 = (u8 *)(temp_3 + temp_4_3);
            sp10c = *(f32 *)temp_4_4 - *(f32 *)temp_5_2;
            temp_f4_2 = sp10c * temp_f0;
            sp110 = *(f32 *)(temp_4_4 + 4) - *(f32 *)(temp_5_2 + 4);
            sp110 *= temp_f0;
            sp114 = (*(f32 *)(temp_4_4 + 8) - *(f32 *)(temp_5_2 + 8)) * temp_f0;
            sp10c = temp_f4_2;
            sp10c = temp_f4_2 + *(f32 *)temp_5_2;
            sp110 += *(f32 *)(temp_5_2 + 4);
            sp114 += *(f32 *)(temp_5_2 + 8);
            temp_5_3 = (s32)(*(u16 *)(var17 + 4) * 0xC);
            temp_4_5 = (u8 *)(temp_2 + temp_5_3);
            temp_3_2 = (u8 *)(temp_3 + temp_5_3);
            sp118 = *(f32 *)temp_3_2 - *(f32 *)temp_4_5;
            sp11c = *(f32 *)(temp_3_2 + 4) - *(f32 *)(temp_4_5 + 4);
            temp_f3 = sp118 * temp_f0;
            sp120 = (*(f32 *)(temp_3_2 + 8) - *(f32 *)(temp_4_5 + 8)) * temp_f0;
            sp11c *= temp_f0;
            sp118 = temp_f3;
            sp118 = temp_f3 + *(f32 *)temp_4_5;
            sp11c += *(f32 *)(temp_4_5 + 4);
            sp120 += *(f32 *)(temp_4_5 + 8);
        } else {
            var20 = (f32 *)(temp_2 + (*(u16 *)(var17 + 2) * 0xC));
            var21 = (f32 *)(temp_2 + (*(u16 *)var17 * 0xC));
            var19 = (f32 *)(temp_2 + (*(u16 *)(var17 + 4) * 0xC));
        }
        if ((s32)func_003d9760(spc8, (u8 *)var21, (u8 *)var20,
                               (u8 *)var19, (u8 *)spd0, &sp13c) == 0)
            goto block_6;
        spe8 = var18;
        spec = var21;
        temp_f12 = sp13c * temp_f20;
        spdc[0] = (f32)var21[0];
        spf0 = var20;
        spdc[1] = (f32)var21[1];
        spf4 = var19;
        spdc[2] = (f32)var21[2];
        sp13c = temp_f12;
        if (spc0(spc4, spd0, spbc, temp_f12) == 0)
            return;
block_6:
        var18 += 1;
        var17 += 8;
        if (var18 < *(s32 *)(spcc + 0x10))
            goto loop_2;
    }
}
