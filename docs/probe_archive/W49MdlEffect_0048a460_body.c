/* Honest vf10 projection recovery, MWCCPS2 b210: 176B/window 176B.
 * Standard replay: 15 differing instruction words, no tail-size gap.
 * The former 11-word candidate returned a dangling stack pointer merely to
 * retain v0. The two observed callers consume vf10, not v0; this body is
 * void and exposes only the genuine COP2 input/output hardware contract.
 * Remaining differences: f0/f1/f2 projection allocation and v0/v1 allocation
 * for constants/final transfer address. The four-lane output has explicit
 * 16-byte alignment and exact vector memory operands preserve dependencies.
 * No local pointer escapes. Both output zero lanes are positive zero.
 * The transform helper returns its destination; this routine ignores it.
 * Source-shape probes consuming that return did not improve the floor.
 * Production remains INCLUDE_ASM.
 * IDA: docs/ida_headstart/src/Graphics/Model/mdlEffect.c:122-145.
 * Genuine 12-byte input/transformed XYZ locals retain this score without
 * widened vectors. Native consumer smoke: 1,010 affine projections with
 * capture/getter/transform/restore ordering, snapshot-before-getter mutation,
 * negative depth, sequential projections, positive-zero output lanes,
 * 16-byte output alignment and spill canaries pass. Only VU transfers are
 * hooked; the transform is a bounded native affine implementation.
 * This does not validate PS2 exceptional floating-point behavior.
 * Further b210 probes retain 15 words: multiplication operand swaps, named
 * depth/component/quotient/extent lifetimes, scoped CSE/propagation controls,
 * an inline component helper, a pointer-return transform declaration,
 * precise final read-only memory dependencies, array/address spellings,
 * and an explicit void return. Staging depth with propagation off restores
 * the initial depth-before-X load order, but not its FPR allocation.
 * Changing only the compiler binary to b119, retaining the owner's flags,
 * regresses to 204B/176B and 45 words. No compiler profile is changed.
 * A private inline final-VF10 load with the same memory contract retains
 * 15 words. A scalar quotient helper, in numerator-first and depth-first
 * argument order, also retains 15; these helper boundaries are not kept.
 * Reproduce: python tools/probe_variants.py src/Graphics/Model/mdlEffect.c
 * func_0048a460 --candidate archive=docs/probe_archive/W49MdlEffect_0048a460_body.c
 */
void func_0048a460(void)
{
    /* RwV3d is exactly three f32 components (batypes.h); only the COP2
       output needs four lanes and 16-byte alignment. */
    struct { f32 x, y, z; } transformed, input;
    f32 output[4] __attribute__((aligned(16)));

    /* Capture incoming VF10 to the 16-byte global scratch vector. The
       explicit output operand and memory clobber publish all four lanes. */
    __asm__ volatile(
        "sqc2 $vf10, 0(%1) \n"
        : "=m"(*(f32 (*)[4])D_00713D10)
        : "r"(&D_00713D10)
        : "$vf10", "memory");
    input.x = D_00713D10[0];
    input.y = D_00713D14[0];
    input.z = D_00713D18[0];
    func_003e42a0(&transformed, &input,
                  mdlEffect_camera_matrix(func_00457120()));
    output[0] = 640.0f * (transformed.x / transformed.z);
    output[1] = 448.0f * (transformed.y / transformed.z);
    output[2] = 0.0f;
    output[3] = 0.0f;
    /* Publish the projection through VF10; the input memory operand
       requires every output lane to be initialized before the transfer. */
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(output), "m"(*(f32 (*)[4])output)
        : "$vf10", "memory");
}
