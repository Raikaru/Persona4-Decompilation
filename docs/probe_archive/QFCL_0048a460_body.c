/* object 176B / window 176B / normalized_diff 19 / differing byte offsets [86,90,92,93,94,101,108,109,110,114,118,120,121,122,129,136]; classification: exact-size FP register-colouring/arithmetic-sequence residual, no banned compiler-floor signature; tried raw u8 and f32 aggregate storage, declaration-order permutations, explicit temporaries, direct nested expressions, and optimization_level 1 (which regressed four siblings); restored INCLUDE_ASM. */
f32 *func_0048a460(void)
{
    f32 raw[12];
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    s32 zero1;
    s32 zero2;

    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(&D_00713D10)
        : "$vf10", "memory");
    raw[4] = D_00713D10[0];
    raw[5] = D_00713D14[0];
    raw[6] = D_00713D18[0];
    func_003e42a0(raw + 8, raw + 4,
                  mdlEffect_camera_matrix(func_00457120()));
    temp_f0 = raw[10];
    temp_f1 = raw[8];
    temp_f2 = temp_f1 / temp_f0;
    temp_f1 = 640.0f * temp_f2;
    raw[0] = temp_f1;
    temp_f1 = raw[9];
    temp_f2 = temp_f1 / temp_f0;
    temp_f1 = 448.0f * temp_f2;
    raw[1] = temp_f1;
    zero1 = 0;
    zero2 = 0;
    raw[2] = (f32)zero1;
    raw[3] = (f32)zero2;
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw)
        : "$vf10", "memory");
    return raw;
}
