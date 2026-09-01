/* object_size=196 window=208 normalized_diff=96 differing_offsets=44,47,52,54,55,56,57,58,59,60,61,62,63,64,65,66 classification=undersized control-flow guard-polarity and callee-return declaration residual; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; declarations corrected at block scope: func_003ec3a0/003e8410/003ef890 as five-argument s32-returning calls, func_003e6210 as four-argument s32-returning call, callback addresses typed, iGpffffb93c/iGpffffb940 s32 GP scalars; no floor instruction */
s32 func_003fe630(void)
{
    extern s32 iGpffffb93c;
    extern s32 iGpffffb940;
    extern s32 func_003e6210(s32 arg0, void *arg1, void *arg2, void *arg3);
    extern s32 func_003e8410(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_003ec3a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_003ef890(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern void func_003f6910(void);
    extern void func_003f6990(void);
    extern void func_003f69f0(void);
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 var_2;
    s32 var_2_2;

    temp_2 = func_003ec3a0(0x5c, 0x40c, 0, 0, 0);
    iGpffffb938 = temp_2;
    var_2_2 = temp_2 >= 0;
    if (var_2_2 == 0) {
        goto block_1;
    }
    temp_2_2 = func_003e8410(0xd8, 0x40c, 0, 0, 0);
    iGpffffb93c = temp_2_2;
    var_2 = temp_2_2 >= 0;
    if (var_2 != 0) {
        temp_2_3 = func_003ef890(0, 0x110, 0, 0, 0);
        iGpffffb940 = temp_2_3;
        var_2 = temp_2_3 >= 0;
        if (var_2 != 0) {
            temp_2_4 = func_003e6210(
                0x110, &func_003f6910, &func_003f6990, &func_003f69f0);
            iGpffffb940 = temp_2_4;
            var_2_2 = temp_2_4 >= 0;
block_1:
            return var_2_2;
        }
    }
    return var_2;
}
