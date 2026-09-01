// object=676 window=672 normalized_diff=371 differing_offsets=76,77,78,79,80,81,82,83,86,87,88,89,91,92,94,95 classification=oversized by 4 / repeated draw-call materialisation residual; ruled_out=frame/signature corrected (64 bytes, s2/s1/s0), no movz/movn, no COP1 accumulator, no standalone MMI, no framed tail-jump; local integer-first draw prototype with pointer as arg7 was measured
void func_00188940(u8 *arg0, u8 *arg1, s32 arg2)
{
    extern void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32);
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    u8 *temp_2;
    u8 *temp_2_2;
    s32 temp_16;

    temp_2 = func_00460990();
    *(void (**)(void))(temp_2 + 8) = (void (*)(void))func_00187f50;
    *(s32 *)(temp_2 + 0x10) = 0;
    func_00460ac0(D_00795E60, temp_2);
    func_0025ecd0(0xFF0000, 0xFF, 0, *(s32 *)(arg0 + 0x2C), 0, 0, 0, D_00795E60, (f32)(s32)(-45.0f + *(f32 *)arg1), (f32)(s32)(-5.0f + *(f32 *)(arg1 + 4)), *(f32 *)(arg1 + 8) - 10.0f, 0.0f, 1.0f, 1.0f);
    func_0025ecd0(0xFF0000, 0xFF, 1, *(s32 *)(arg0 + 0x2C), 0, 0, 0, D_00795E60, (f32)(s32)(-45.0f + *(f32 *)arg1), (f32)(s32)(224.0f + *(f32 *)(arg1 + 4)), *(f32 *)(arg1 + 8) - 10.0f, 0.0f, 1.0f, 1.0f);
    temp_2_2 = func_00460990();
    *(void (**)(void))(temp_2_2 + 8) = (void (*)(void))func_00188110;
    *(s32 *)(temp_2_2 + 0x10) = 0;
    func_00460ac0(D_00795E60, temp_2_2);
    temp_f0 = (f32)(s32)(185.0f + *(f32 *)arg1);
    func_0025ecd0(0xFFFFFF, 0, 7, *(s32 *)(arg0 + 0x30), 0, 0, 0, D_00795E60, temp_f0, (f32)(s32)0.0f, *(f32 *)(arg1 + 8) - 10.0f, 0.0f, iGpffff8538, 1.0f);
    temp_16 = ((*(s32 *)(arg0 + 0x80) ^ arg2) != 0);
    temp_f1 = *(f32 *)(arg0 + (temp_16 * 4) + 0x88);
    temp_f0_2 = *(f32 *)arg1 - 1.0f + temp_f1;
    temp_f1 = *(f32 *)(arg1 + 4) - 1.0f;
    temp_2 = arg0 + (arg2 * 4) + 0x38;
    func_0025ecd0(0xFFFFFF, 0xFF, 0, *(s32 *)temp_2, 1, 0, 0, D_00795E60, (f32)(s32)temp_f0_2, (f32)(s32)temp_f1, *(f32 *)(arg1 + 8), 0.0f, 1.0f, 1.0f);
}
