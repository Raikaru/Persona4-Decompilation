/* object 416B / window 416B / normalized_diff 14.
 * Differing word offsets (relocations masked): 0x44; 0x58,0x5C,0x60,
 * 0x6C,0x70,0x74,0x78,0x7C,0x80,0x84,0x88,0x8C,0x90.
 * Frame and object size are exact; code from offset 0x94 onward is exact.
 * Offset 0x44 is a separate control-flow defect: the initial status-check
 * branch targets the loop body instead of retail's loop-tail load. The
 * 0x58-0x90 residual is the first-call setup/global-load scheduling block
 * (0x64 and 0x68 within that interval match retail).
 * Shape measured here: global-first setup with an aligned Stack0014 local
 * struct and absolute-array global declarations D_005EFB98[]/D_005EFBA0[].
 * Ruled out: separate scalar locals (packed frame mismatch), top-tested loop
 * form (wrong control-flow layout), scalar GP-relative loads, and an explicit
 * call-address temporary (which perturbed the otherwise exact tail).
 */ 
u16 func_0014be50(u8 *arg0, u8 **arg1) {
    struct Stack0014 {
        s64 sp50;
        f32 sp58;
        u32 pad5c;
        u8 *sp60;
        u8 *sp64;
        u8 *sp68;
    } stack;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    u16 var_17;
    u8 *var_16;

    var_17 = 0xFFFF & 0xFFFF;
    var_16 = (u8 *)(func_001452b0(0xD));
    if (func_0014a200() == 1) {
        return 0xFFFFU;
    }
    do {
        stack.sp50 = D_005EFB98[0];
        stack.sp58 = D_005EFBA0[0];
        stack.sp60 = (u8 *)(var_16 + 0x15C);
        stack.sp64 = (u8 *)(var_16 + 0x168);
        stack.sp68 = (u8 *)(var_16 + 0x174);
        if ((func_00168ec0(arg0, &stack.sp60, &stack.sp50) == 1) &&
            (temp_f3 = *(f32 *)(stack.sp60 + 4),
             temp_f2 = *(f32 *)(arg0 + 4),
             (temp_f2 < (100.0f + temp_f3))) &&
            !(temp_f2 <= (temp_f3 - 100.0f))) {
            var_17 = *(u16 *)var_16;
            *arg1 = var_16;
            goto done_11;
        }
        stack.sp60 = (u8 *)(var_16 + 0x168);
        stack.sp64 = (u8 *)(var_16 + 0x174);
        stack.sp68 = (u8 *)(var_16 + 0x180);
        if ((func_00168ec0(arg0, &stack.sp60, &stack.sp50) == 1) &&
            (temp_f3_2 = *(f32 *)(stack.sp60 + 4),
             temp_f2_2 = *(f32 *)(arg0 + 4),
             (temp_f2_2 < (100.0f + temp_f3_2))) &&
            !(temp_f2_2 <= (temp_f3_2 - 100.0f))) {
            var_17 = *(u16 *)var_16;
            *arg1 = var_16;
            goto done_11;
        }
        var_16 = *(u8 **)(var_16 + 0x138);
    } while (var_16 != NULL);
done_11:
    return var_17;
}
