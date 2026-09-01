/* object 452B; retail window 464B; normalized_diff 6; differing offsets 0x28, 0x30, 0xF8, 0x11C, 0x12C, 0x13C; classification: register class (saved FPU parameter coloring) plus 12B zero tail; tried DatUnit* block-scope callee prototypes, explicit f21 local/declaration order, parameter aliases, reversed names, and O1; none moved the residual. */
void func_0021b330(s32 arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2)
{
    f32 var_f23;
    s32 *temp_16;
    s32 temp_3;

    temp_16 = (s32 *)func_00452560((void *)arg0);
    if (*(s32 *)(arg1 + 4) != 0) {
        temp_3 = *(s32 *)(arg1 + 0) + 1;
        *(s32 *)(arg1 + 0) = temp_3;
        var_f23 = (f32)temp_3 / 4.0f;
        if (!(var_f23 <= 1.0f)) {
            var_f23 = 1.0f;
        }
    } else {
        var_f23 = 1.0f;
    }
    if (var_f23 != 0.0f) {
        fparg1 = fparg1 + 5.5f * (1.0f - var_f23);
        func_00201720(temp_16, 1.0f, var_f23);
        func_00201650((u8 *)temp_16, 0xA, 0, fparg0, fparg1,
                      0x19, 0x19, 0x19, 0xFF);
        if (!(fparg2 <= fGpffff849c)) {
            func_00201720(temp_16, fparg2, var_f23);
            func_00201650((u8 *)temp_16, 0xA, 1,
                          fparg2 + 5.0f * (1.0f - fparg2), fparg1,
                          0xFF, 0xFF, 0x51, 0xFF);
        }
        func_00201720(temp_16, 1.0f, 1.0f);
    }
}
