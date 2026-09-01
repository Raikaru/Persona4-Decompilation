/* object 444B; retail window 448B; normalized_diff 323; differing offsets 0x04, 0x08, 0x0A, 0x0C, 0x0E, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x19, 0x1A, 0x1C (first 16 verifier offsets); exact residual is the arg1 spill/prologue and cascaded s-register coloring, byte-clamp register order, and four-byte tail. Tried direct arg1, an s64 local, and a one-element s64 array; all retain the same coloring. The aggregate byte buffer is required to prevent dead-store elimination. The float-to-unsigned site is the plain (u8) cast below. */
void func_0034c500(u8 *arg0, s64 arg1, s32 arg2) {
    u8 bytes[4];
    u8 sp40[0x100];
    f32 var_f14;
    f32 var_f15;
    s32 var_16;
    u8 var_2;
    u8 var_3;
    u8 var_5;
    u8 var_3_2;
    u8 *temp_2;
    u8 *temp_4;

    func_0034edc0();
    if (*(s16 *)(D_007523CA + (*(s32 *)(arg0 + 0x1680) * 0x10)) != 0) {
        func_0034c860(arg0, arg1, arg2);
        func_0034cef0(arg0 + 0x690);
    }
    var_16 = 0;
    for (; var_16 < 0x14; var_16++) {
        temp_4 = arg0 + (var_16 * 0x54);
        if (*(s16 *)(D_007523C0 + (*(s32 *)(arg0 + 0x1680) * 0x10) + 8) == 0) {
            var_f15 = 448.0f;
            var_f14 = *(f32 *)(temp_4 + 0x34);
        } else {
            var_f15 = *(f32 *)(temp_4 + 0x34);
            var_f14 = 640.0f;
        }
        temp_2 = D_00749840 + (*(s16 *)(temp_4 + 0x48) * 4);
        var_5 = temp_2[0];
        if ((s32)var_5 < 0) {
            var_5 = 0;
        }
        var_3 = temp_2[1];
        if ((s32)var_3 < 0) {
            var_3 = 0;
        }
        var_2 = temp_2[2];
        if ((s32)var_2 < 0) {
            var_2 = 0;
        }
        bytes[0] = var_5;
        bytes[1] = var_3;
        bytes[2] = var_2;
        var_3_2 = (u8)*(f32 *)(temp_4 + 0x24);
        bytes[3] = var_3_2;
        func_0034c6c0(sp40, *(f32 *)(temp_4 + 8), *(f32 *)(temp_4 + 0xC), var_f14, var_f15, bytes);
        func_0034c820(sp40);
    }
}
