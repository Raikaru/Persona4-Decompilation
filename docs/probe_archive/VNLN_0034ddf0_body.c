/* object 688B; retail window 704B; normalized_diff 168; first differing offsets 0x0BC, 0x118, 0x11D, 0x130, 0x134, 0x135, 0x139, 0x150, 0x154, 0x158, 0x15C, 0x160, 0x164, 0x168, 0x16C, 0x170; conversion sites: (f32)(u32)temp_2 for the lbu unsigned-byte-to-float idiom and (u8)temp_f2_2 for the c.ole.s/trunc.w.s/mfc1/lui 0x8000/or/andi float-to-unsigned-byte idiom. Ruled out corrected f0d0 signature, declaration-order swaps, temp_f20 initialization/assignment swaps, propagation and optimization-level probes, and common-subexpression work; residual is codegen/register-coloring plus the 16-byte retail tail. */
void func_0034ddf0(u8 *arg0, s32 arg1) {
    f32 temp_f2;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f1;
    f32 temp_f2_2;
    f32 var_f0;
    f32 var_f1;
    s32 temp_16;
    u8 temp_2;

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
    temp_f20 = var_f0;
    temp_f21 = 171.0f * var_f0;
    temp_2 = *(u8 *)(arg0 + 0x994);
    var_f1 = (f32)(u32)temp_2;
    temp_f2_2 = var_f1 * var_f0;
    temp_16 = (u8)temp_f2_2;
    *(s32 *)(arg0 + 0x990) = 0;
    temp_f20 = (iGpffff8220 - (171.0f * var_f0) / 2.0f) + *(f32 *)(arg0 + 0x9A0);
    temp_f24 = 77.0f + *(f32 *)(arg0 + 0x99C);
    temp_f23 = D_008872F8[0] - D_0088466C[0];
    temp_f22 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_16 &= 0xFF;
    func_0034f0d0(arg0 + 0x690, temp_f24, temp_f20, temp_f23, temp_f22, 0xFF, 0xE9, 0x2C, temp_16);
    temp_f21 = temp_f20 + temp_f21;
    func_0034f0d0(arg0 + 0x6D0, temp_f24, temp_f21, temp_f23, temp_f22, 0xFF, 0xE9, 0x2C, temp_16);
    temp_f24 = temp_f24 + 580.0f;
    func_0034f0d0(arg0 + 0x710, temp_f24, temp_f21, temp_f23, temp_f22, 0xFF, 0xE9, 0x2C, temp_16);
    func_0034f0d0(arg0 + 0x750, temp_f24, temp_f20, temp_f23, temp_f22, 0xFF, 0xE9, 0x2C, temp_16);
}
