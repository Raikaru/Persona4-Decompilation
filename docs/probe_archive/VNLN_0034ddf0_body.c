/* func_0034ddf0 -- animated line rectangle, not promoted.
 * Context: src/promoted/nLine.c, including addF and the surrounding
 * opt_common_subs off scope. Object 700B / retail window 704B:
 * six reloc-masked differing words, comprising five COP1 register-field
 * differences in alpha conversion and one word beyond the emitted object.
 *
 * Corrected the old candidate's depth reference to D_0088467C and retained
 * separate right-coordinate additions for the last two vertices. A narrowed
 * byte snapshot follows the camera callback. Explicit top-offset evaluation,
 * bounded additions and paired projection fields preserve retail geometry,
 * instruction order and saved-register allocation. No padding was added.
 *
 * Native Clang ASan/UBSan/float-cast-overflow smoke passed together with
 * db60: 30,960 scenarios / 123,840 vertices. Covers every input alpha byte,
 * fractional narrowing, timing boundaries, zero/nonzero directions, inactive
 * states, camera/easing/vertex mutations, snapshots and db60 position reloads.
 * Production remains INCLUDE_ASM until the conversion allocation matches.
 */
#pragma opt_propagation off
void func_0034ddf0(u8 *arg0, s32 arg1) {
    f32 temp_f2;
    f32 temp_f21;
    f32 temp_f20;
    struct { f32 reciprocal; f32 depth; } projection;
    f32 temp_f24;
    f32 temp_f1;
    f32 temp_f2_2;
    f32 var_f0;
    f32 var_f1;
    s32 temp_16;
    u8 temp_2;
    u8 temp_3;

    temp_f2 = *(f32 *)(arg0 + 0x1688);
    if (*(s32 *)(arg0 + 0x1690) == 0) {
        temp_f1 = (f32)*(s16 *)(arg0 + 0x1684);
        if (temp_f1 < temp_f2) {
            var_f0 = func_0044b7b0((iGpffff8094 * temp_f1) / temp_f2);
        } else {
            var_f0 = 1.0f;
        }
    } else {
        var_f0 = 1.0f;
    }
    if (arg1 == 0) {
        var_f0 = 1.0f - var_f0;
    }
    temp_f21 = 171.0f * var_f0;
    temp_2 = *(u8 *)(arg0 + 0x994);
    var_f1 = (f32)(u32)temp_2;
    temp_f2_2 = var_f1 * var_f0;
    temp_16 = (u8)temp_f2_2;
    *(s32 *)(arg0 + 0x990) = 0;
    temp_f1 = iGpffff8220 - (171.0f * var_f0) / 2.0f;
    temp_f20 = addF(temp_f1, *(f32 *)(arg0 + 0x9A0));
    temp_f24 = 77.0f + *(f32 *)(arg0 + 0x99C);
    projection.depth = D_008872F8[0] - D_0088467C[0];
    projection.reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_3 = (u8)temp_16;
    func_0034f0d0(arg0 + 0x690, temp_f24, temp_f20, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, temp_3);
    temp_f21 = addF(temp_f20, temp_f21);
    func_0034f0d0(arg0 + 0x6D0, temp_f24, temp_f21, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, temp_3);
    func_0034f0d0(arg0 + 0x710, addF(temp_f24, 580.0f), temp_f21, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, temp_3);
    func_0034f0d0(arg0 + 0x750, addF(temp_f24, 580.0f), temp_f20, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, temp_3);
}
#pragma opt_propagation on
