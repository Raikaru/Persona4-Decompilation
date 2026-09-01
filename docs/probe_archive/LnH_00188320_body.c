/* Lane: LnH; target: func_00188320; object/window: 628/624 bytes. */
/* Residual: normalized_diff 53; differing offsets: 0x164, 0x188, 0x1A4-0x224, 0x22C-0x26C, 0x270 (extra object word). */
/* COP1 accumulator chain: reproduced (adda.s + madd.s), but ordinary load/constant scheduling left one extra instruction. */
/* Ruled out: integer -5 constant, split x arithmetic, alternate sum grouping, pointer/index spellings, declaration-order-only changes, opt_propagation pragma. */
void func_00188320(u8 *arg0, u8 *arg1)
{
    s32 temp_17;
    s32 temp_16;
    u8 *temp_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;

    temp_2 = func_00460990();
    *(void (**)(void))(temp_2 + 8) = func_00187f50;
    *(s32 *)(temp_2 + 0x10) = 0;
    func_00460ac0(D_00795E60, temp_2);
    temp_f0 = -44.0f;
    temp_f0 += *(f32 *)arg1;
    temp_f1 = -7.0f + *(f32 *)(arg1 + 4);
    func_0025ecd0(
        (f32)(s32)temp_f0,
        (f32)(s32)temp_f1,
        *(f32 *)(arg1 + 8) - 10.0f,
        0x313131,
        0xFF,
        0,
        *(s32 *)(arg0 + 0x2C),
        0,
        0,
        0,
        0.0f,
        1.0f,
        1.0f,
        D_00795E60);
    temp_f0 = -44.0f;
    temp_f0 += *(f32 *)arg1;
    temp_f1 = 224.0f + *(f32 *)(arg1 + 4);
    func_0025ecd0(
        (f32)(s32)temp_f0,
        (f32)(s32)temp_f1,
        *(f32 *)(arg1 + 8) - 10.0f,
        0x313131,
        0xFF,
        1,
        *(s32 *)(arg0 + 0x2C),
        0,
        0,
        0,
        0.0f,
        1.0f,
        1.0f,
        D_00795E60);
    temp_17 = 0;
    while (temp_17 < 5) {
        temp_16 = 0;
        temp_f20 = 102.0f * (f32)temp_17;
        while (temp_16 < 2) {
            temp_f0 = -5.0f + *(f32 *)(arg1 + 0) + 93.0f * (f32)temp_16;
            temp_f1 = -40.0f + *(f32 *)(arg1 + 4) + temp_f20;
            func_0025ecd0(
                (f32)(s32)temp_f0,
                (f32)(s32)temp_f1,
                *(f32 *)(arg1 + 8),
                0x393939,
                0xFF,
                3,
                *(s32 *)(arg0 + 0x2C),
                1,
                0,
                0,
                0.0f,
                1.0f,
                1.0f,
                D_00795E60);
            temp_16 += 1;
        }
        temp_17 += 1;
    }
}
