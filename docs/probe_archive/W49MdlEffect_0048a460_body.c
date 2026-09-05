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
 * IDA: docs/ida_headstart/src/Graphics/Model/mdlEffect.c:122-145.
 * Named frame fields retain this score. Native consumer smoke: 153 cases
 * with only VU transfers hooked; transformed XYZ, negative depth, sequential
 * projections, positive-zero lanes and 16-byte spill canaries pass.
 * This does not validate PS2 exceptional floating-point behavior.
 * Reproduce: python tools/probe_variants.py src/Graphics/Model/mdlEffect.c
 * func_0048a460 --candidate archive=docs/probe_archive/W49MdlEffect_0048a460_body.c
 */
void func_0048a460(void)
{
    struct { f32 output[4]; f32 input[4]; struct { f32 x, y, z, w; } transformed; } frame __attribute__((aligned(16)));

    __asm__ volatile(
        "sqc2 $vf10, 0(%1) \n"
        : "=m"(*(f32 (*)[4])D_00713D10)
        : "r"(&D_00713D10)
        : "$vf10", "memory");
    frame.input[0] = D_00713D10[0];
    frame.input[1] = D_00713D14[0];
    frame.input[2] = D_00713D18[0];
    func_003e42a0(&frame.transformed, frame.input,
                  mdlEffect_camera_matrix(func_00457120()));
    frame.output[0] = 640.0f * (frame.transformed.x / frame.transformed.z);
    frame.output[1] = 448.0f * (frame.transformed.y / frame.transformed.z);
    frame.output[2] = 0.0f;
    frame.output[3] = 0.0f;
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(frame.output), "m"(*(f32 (*)[4])frame.output)
        : "$vf10", "memory");
}
