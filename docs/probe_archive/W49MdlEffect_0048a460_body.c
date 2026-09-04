/* W49MdlEffect probe, 2026-09-03.
 *
 * This is the best honest C reconstruction measured for FUN_0048A460 before
 * restoring INCLUDE_ASM.  tools/fndiff.py reports object 176B, window 176B,
 * and 11 differing words (all at offsets 0x54..0x8c).  The prologue, global
 * loads, transform call, stores, and COP2 return transfer are exact.
 *
 * Retail allocates the projection arithmetic as f0=divisor, f1=dividend and
 * product, f2=quotient.  MWCCPS2 3.0.1b210 consistently allocates the same
 * operations as f2=divisor, f0=dividend and product, f1=quotient.  Probes
 * covered raw f32/u8 storage, typed Vec3/Vec4 aggregates, separate output and
 * transformed arrays, declaration and temporary-role orders, direct/nested
 * arithmetic, helper calls, register qualification, and optimization/schedule
 * controls; none reached MATCH without compiler-steering or ordinary inline
 * asm.  The two asm blocks below are only the existing COP2 transfer idiom.
 */
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
