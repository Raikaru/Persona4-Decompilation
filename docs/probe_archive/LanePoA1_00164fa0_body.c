/* LanePoA1 residual=132, retail saved: s0=D_007EFA00+s1, s1=arg0*0x750, s2=D_007EF9B0+s1, s3=arg0, s4=D_007EFA04, s5=D_007EF9F8. */
void func_00164fa0(s32 arg0)
{
    f32 sp70[3];
    f32 temp_f0;
    s32 temp_17;
    s32 temp_2_2;
    s32 temp_4;
    s32 temp_3;
    s32 *temp_21;
    s32 i;
    u8 **temp_16;
    u8 **temp_20;
    u8 *temp_2;
    u8 *temp_18;
    u8 *var_2;

    temp_17 = arg0 * 0x750;
    temp_21 = (s32 *)(D_007EF9F8 + temp_17);
    if (*temp_21 != 0) {
        temp_16 = (u8 **)(D_007EFA00 + temp_17);
        temp_20 = (u8 **)(D_007EFA04 + temp_17);
        temp_2 = func_00145270(func_00145540(arg0 & 0xFFFF, 3, *temp_16) & 0xFFFF);
        *temp_20 = temp_2;
        func_0017b9a0(*(s32 *)(temp_2 + 0x224), 60.0f);
        temp_18 = D_007EF9B0 + temp_17;
        var_2 = func_0047a2f0((s32)*temp_16);
        i = 8;
        do {
            temp_4 = *(s32 *)temp_18;
            temp_3 = *(s32 *)(temp_18 + 4);
            temp_18 += 8;
            *(s32 *)var_2 = temp_4;
            *(s32 *)(var_2 + 4) = temp_3;
            var_2 += 8;
            i -= 1;
        } while (i > 0);
        func_003e05d0(func_0047a2f0((s32)*temp_16));
        func_0014b0c0(*(u16 *)*temp_20, 1);
        func_00168730(*((s32 *)(*temp_20 + 0x220)), 0x40000000);
        func_00168c00(*((s32 *)(*temp_20 + 0x220)));
        if (arg0 == 0) {
            func_00168780(*((s32 *)(*temp_20 + 0x220)), 60.0f);
        } else {
            func_00168780(*((s32 *)(*temp_20 + 0x220)), 35.0f);
        }
        temp_20 = (u8 **)(D_007EFA04 + (arg0 * 0x750));
        *((s32 *)(*temp_20 + 0x228)) = func_00478750(iGpffffb274);
        temp_f0 = func_00168770(*((s32 *)(*temp_20 + 0x220)));
        sp70[0] = sp70[1] = sp70[2] = temp_f0;
        func_0047a1e0(*(u8 **)(*temp_20 + 0x228), &sp70[0], 2);
        func_00478e70(*(u8 **)(*temp_20 + 0x228));
        if (func_002319f0(*temp_21) == 0) {
            func_00479940(*temp_16, 0, (s16)func_0016fd00(*(u16 *)(D_007F00D8 + (arg0 * 0x750))), 0, 1);
        }
        if (arg0 != 0) {
            temp_2_2 = func_0017e890(0, D_007EF9B0 + (arg0 * 0x750), D_007EF9B0 + ((arg0 - 1) * 0x750));
            *(s32 *)(D_007EFB60 + (arg0 * 0x750)) = temp_2_2;
            func_0017e990(temp_2_2);
        }
        if (arg0 == 0) {
            *(s32 *)(D_007EFB64 + temp_17) = func_0017d070(0);
        }
    }
}
/* measured: restore common-subexpression elimination after func_00164fa0. */
#pragma opt_common_subs on


