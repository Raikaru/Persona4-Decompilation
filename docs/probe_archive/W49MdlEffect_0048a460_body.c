/* Honest vf10 projection recovery, MWCCPS2 b210: 176B/window 176B.
 * Standard replay: 15 differing instruction words, no tail-size gap.
 * The former 11-word candidate returned a dangling stack pointer merely to
 * retain v0. The two observed callers consume vf10, not v0; this body is
 * void and exposes only the genuine COP2 input/output hardware contract.
 * Remaining differences: f0/f1/f2 projection allocation and v0/v1 allocation
 * for constants/final transfer address. Explicit 16-byte alignment and exact
 * vector memory operands preserve valid storage and transfer dependencies.
 * No local pointer escapes. Both output zero lanes are positive zero.
 * The transform helper returns its destination; this routine ignores it.
 * Source-shape probes consuming that return did not improve the floor.
 * Production remains INCLUDE_ASM.
 * Reproduce: python tools/probe_variants.py src/Graphics/Model/mdlEffect.c
 * func_0048a460 --candidate archive=docs/probe_archive/W49MdlEffect_0048a460_body.c
 */
void func_0048a460(void)
{
    f32 raw[12] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;

    __asm__ volatile(
        "sqc2 $vf10, 0(%1) \n"
        : "=m"(*(f32 (*)[4])D_00713D10)
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
    raw[2] = 0.0f;
    raw[3] = 0.0f;
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw), "m"(*(f32 (*)[4])raw)
        : "$vf10", "memory");
}
