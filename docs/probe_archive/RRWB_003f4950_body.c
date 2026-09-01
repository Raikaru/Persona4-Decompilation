/* object_size=292 window=304 normalized_diff=155 first_diffs=6,7,14,15,18,19,40,43,50,51,52,53,54,55,58,59 classification=undersized/missing-block-or-argument; prologue=frame_0x10 saved_ra_only no_args; deficit=12_bytes=3_instructions_absent; declarations corrected at block scope: iGpffffabe0/iGpffffabdc/iGpffffabd8 GP s32, iGpffffb7e8/iGpffffb7f4/iGpffffb7ec GP byte stores, iGpffffb800 GP byte, K&R callee declarations; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; measured_minutes=12 */
s32 func_003f4950(void)
{
    extern s32 iGpffffabe0;
    extern s32 iGpffffabdc;
    extern s32 iGpffffabd8;
    extern s32 iGpffffb7e8;
    extern s32 iGpffffb7f8;
    extern s32 iGpffffb7f4;
    extern s32 iGpffffb7ec;
    extern u8 iGpffffb800;
    extern void func_003f2cd0();
    extern void func_003f2830();
    extern s32 func_004214c0();
    extern s32 func_004214f0();
    extern void func_00421510();
    extern void func_004214e0();
    extern s32 func_00422328();
    extern s32 func_004223f8();
    volatile u32 *reg_3820;
    volatile u32 *reg_e000;
    s32 value;

    *(s32 *)&iGpffffb7f8 = (s32)&iGpffffb7f8;
    value = func_004214c0(2, func_003f2cd0, 0);
    iGpffffabe0 = value;
    if (value == -1)
        goto done_zero;
got_first:
    value = func_004214f0(1, func_003f2830, 0);
    iGpffffabdc = value;
    if (value == -1)
        goto fail_second;
got_second:
    value = func_004214f0(2, func_003f2830, 0);
    iGpffffabd8 = value;
    if (value == -1) {
        func_00421510(1, iGpffffabdc);
        func_004214e0(2, iGpffffabe0);
        iGpffffabdc = -1;
        iGpffffabe0 = -1;
        goto done_zero;
    }
    *(u8 *)&iGpffffb7e8 = func_00422328(2);
    *(u8 *)&iGpffffb7f4 = func_00422328(2);
    *(u8 *)&iGpffffb800 = func_004223f8(1);
    *(u8 *)&iGpffffb7ec = func_004223f8(2);
    reg_3820 = (volatile u32 *)0x10003820;
    *reg_3820 = *reg_3820 | 2;
    *reg_3820 = *reg_3820 | 2;
    reg_e000 = (volatile u32 *)0x1000e000;
    *reg_e000 = *reg_e000 & ~0x703;
    return 1;
fail_second:
    func_004214e0(2, iGpffffabe0);
    iGpffffabe0 = -1;
done_zero:
    return 0;
}
