/* archived candidate: object 484B / retail window 496B / normalized_diff 348
   Natural C reconstruction is substantially undersized and differs throughout;
   archive immediately per oversized/large residual policy after callee declarations
   and float literals were corrected. Retail contains COP1 accumulator instructions
   (adda.s/madd.s/mula.s) in its central chains; pure COP1 MAC is a known floor and
   no inline asm was added. Callees used with verified signatures: func_004bd050
   (u32 -> u32), func_004bd0b0 (u32 -> f32), func_0044b610 (f32 -> f32), and
   func_0044b7b0 (f32 -> f32). Natural source shape tried below.
*/

void func_004a8da0(u8 *arg0, u8 *arg1) {
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f22;
    f32 temp_f23;
    u8 *temp_16;

    *(u32 *)arg1 = func_004bd050(0) % (u32)(*(s32 *)(arg0 + 4) + 1);
    *(f32 *)(arg1 + 4) = fGpffff80f4;
    temp_16 = arg1 + 8;
    *(s32 *)(arg1 + 0x10) = *(s32 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0x14) = *(f32 *)(arg0 + 0x14);
    *(s32 *)(arg1 + 0xC) = *(s32 *)(arg0 + 0xC);
    temp_f20 = 0.5f * (f32)*(s32 *)(arg0 + 0x28);
    temp_f22 = fGpffff8044 * (2.0f * (func_004bd0b0(0) - 0.5f));
    temp_f21 = *(f32 *)(arg0 + 0x30);
    temp_f21 = temp_f21 + (810.0f - temp_f20 - temp_f21) * func_004bd0b0(0);
    temp_f23 = *(f32 *)(arg0 + 0x2C);
    temp_f23 = temp_f23 + (650.0f - temp_f20 - temp_f23) * func_004bd0b0(0);
    temp_f23 = temp_f23 * 0.5f;
    temp_f1 = fGpffff80cc * temp_f20;
    temp_f21 = temp_f21 + *(f32 *)(arg0 + 0x1C) * func_0044b610(temp_f22);
    temp_f23 = temp_f23 + temp_f1;
    temp_f21_2 = temp_f21;
    temp_f1 = *(f32 *)(arg0 + 0x20) + temp_f23 * func_0044b7b0(temp_f22);
    *(f32 *)(temp_16 + 0x14) = temp_f21_2;
    *(f32 *)(temp_16 + 0x18) = temp_f1;
    *(f32 *)(temp_16 + 0x1C) = temp_f21_2 - temp_f20;
    *(f32 *)(temp_16 + 0x20) = temp_f1 - temp_f20;
    *(f32 *)(temp_16 + 0x24) = temp_f21_2 + temp_f20;
    *(f32 *)(temp_16 + 0x28) = temp_f1 + temp_f20;
}
