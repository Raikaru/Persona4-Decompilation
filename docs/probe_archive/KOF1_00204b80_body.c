/* residual=303 words, object_size=452, window=464; first diffs at 33-59; tried: 4-param u8 arg1, s16 loops, D_00764564, direct D_00887300 calls, var_2 = D_00764564 % 4. Issues: wrong saved-register allocation (arg0/arg1 in s0/s1, loops in s2/s3 vs retail arg0=s3,arg1=s2,outer=s1,inner=s0), D_00887300 top call order (args before base), bottom call not cached in s0, arg1 passed with andi vs move. */
// FUN_00204B80
void func_00204b80(u8 *arg0, f32 farg0, f32 farg1, u8 arg1)
{
    extern u8 D_00764564;
    f32 var_f20;
    f32 var_f21;
    s16 var_16;
    s16 var_17;
    s32 var_2;

    D_00887300[0](6, 1);
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
            var_16 = (s16)(var_16 + 1);
        }
        var_f20 += 126.0f;
        var_17 = (s16)(var_17 + 1);
    }
    func_00201820(0);
    func_002019e0(arg0, 0.0f);
    D_00887300[0](6, 0);
    D_00887300[0](1, 0);
}
