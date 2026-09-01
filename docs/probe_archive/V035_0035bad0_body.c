/* object_size=320B; window=320B; normalized_diff=14; differing_offsets=0x22,0x24-0x28,0x2C-0x2F,0xE9-0xEA,0x115-0x116. */
/* Retail contains a COP1 accumulator chain in both interpolation blocks:
   mula.s, madda.s, and madd.s. The best plain-C body below reproduced the
   320-byte size but retained the MAC operand order and an unrelated temp_2
   v1/v0 prologue residual. Four direct-expression operand orders all compiled
   identically (nd 14); ordered helper probes lowered the body to 304B and nd
   76/77. This is a documented ordinary-COP1-MAC compiler floor; no inline asm
   was used. */
f32 func_0035bad0(u8 *arg0)
{
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f21_2;
    s32 temp_2;
    s16 temp_2_2;

    temp_2 = *(s16 *)(arg0 + 0x24) + 1;
    *(s16 *)(arg0 + 0x24) = temp_2;
    if ((s64)(s16)temp_2 >= 0x64) {
        *(s16 *)(arg0 + 0x24) = 0;
    }
    temp_2_2 = *(s16 *)(arg0 + 0x22);
    if (temp_2_2 < 0xA) {
        *(s16 *)(arg0 + 0x22) = (s16)(temp_2_2 + 1);
    }
    temp_f20 = (f32)*(s16 *)(arg0 + 0x22) / 10.0f;
    if ((temp_f20 < 0.0f) || (temp_f20 > 1.0f)) {
        func_0046d730(&D_0064CC98, 0x881);
    }
    temp_f22 = fGpffff84a4 * temp_f20;
    temp_f21 = *(f32 *)(arg0 + 0x18);
    temp_f0 = func_0044b7b0(temp_f22);
    *(f32 *)(arg0 + 8) = temp_f21 + (temp_f0 * (*(f32 *)(arg0 + 0x10) - temp_f21));
    temp_f21_2 = *(f32 *)(arg0 + 0x1C);
    temp_f0 = func_0044b7b0(temp_f22);
    *(f32 *)(arg0 + 0xC) = temp_f21_2 + (temp_f0 * (*(f32 *)(arg0 + 0x14) - temp_f21_2));
    return temp_f20;
}
