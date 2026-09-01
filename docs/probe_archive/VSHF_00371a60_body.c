/* object 312B; retail window 320B; normalized_diff 26; differing offsets 0x10,0x14,0x1C,0x30,0x34,0x68,0xD0,0xD8,0xDC,0xE0,0xE4,0xE8,0xEC,0xF0,0xF4,0xF8,0xFC,0x100,0x104,0x108,0x10C,0x110,0x114,0x118; ruled out: u16/u32/s32 value locals, direct casts, typed ShuffleCalcUnit pointer, compound increment, helper argument staging, alternate FP lerp expression orders, optimization-level and propagation pragmas; residual is argument-register/CSE and FP register/schedule coloring. */
s32 func_00371a60(u8 *arg0, s32 arg1) {
    u32 value;
    f32 half;
    f32 zero;
    f32 temp_f0;
    f32 temp_f5;

    zero = 0.0f;
    value = *(u16 *)arg0;
    half = (f32)(u32)value;
    if (!(half < *(f32 *)(arg0 + 4))) {
        return 1;
    }
    *(u16 *)arg0 = *(u16 *)arg0 + 1;
    value = *(u16 *)arg0;
    half = (f32)(u32)value;
    temp_f0 = func_00373cb0(half + zero, *(f32 *)(arg0 + 8), *(f32 *)(arg0 + 4), arg1);
    temp_f5 = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg0 + 0xC) = (*(f32 *)(arg0 + 0x24) - temp_f5) * temp_f0 + temp_f5;
    *(f32 *)(arg0 + 0x10) = (*(f32 *)(arg0 + 0x28) - *(f32 *)(arg0 + 0x1C)) * temp_f0 + *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0x14) = (*(f32 *)(arg0 + 0x2C) - *(f32 *)(arg0 + 0x20)) * temp_f0 + *(f32 *)(arg0 + 0x20);
    return 0;
}
