// FUN_00204B80 archive (wave Ko lane KoF, killed by provider rate limit mid-work; live state at cutoff, COMPILE_ERROR).
/* measured: opt_propagation off probe for func_00204b80 register/cache. */
#pragma opt_propagation off
void func_00204b80(u8 *arg0, f32 farg0, f32 farg1, u8 arg1)
{
    extern u8 D_00764564;
    s16 var_i;
    s16 var_j;
    f32 var_f20;
    f32 var_f21;
    s32 var_2;

    {
        void (**base)(u32, u32) = D_00887300;
        base[0](6, 1);
    }
    func_002012d0(arg0, 36.0f, 19.0f);
    func_002019e0(arg0, 50.0f);
    func_00201820(2);
    var_f20 = 0.0f;
    var_17 = 0;
    while ((s16)var_17 < 3) {
        var_f21 = 0.0f;
        var_16 = 0;
        while ((s16)var_16 < 5) {
            var_2 = D_00764564 % 4;
            D_00764564 = D_00764564 + 1;
            func_00201650(arg0, 0xF, (s16)var_2, var_f21, var_f20,
                          0xFF, 0xFF, 0xFF, arg1);
            var_f21 += 126.0f;
            var_16 = (s64)((var_16 + 1) << 0x30) >> 0x30;
        }
        var_f20 += 126.0f;
        var_17 = (s64)((var_17 + 1) << 0x30) >> 0x30;
    }
    func_00201820(0);
    func_002019e0(arg0, 0.0f);
    {
        void (**base)(u32, u32) = D_00887300;
        base[0](6, 0);
        base[0](1, 0);
    }
}
/* measured: close opt_propagation off probe for func_00204b80. */
#pragma opt_propagation on
