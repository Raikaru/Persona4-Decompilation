/* archived: object 348B, window 352B, normalized_diff 106; P3-FES FUN_0035aa10 twin shape, P4 field set 0x18/0x1C/0x20 */
void func_00417310(u8 *arg0, u8 *arg1, u8 *arg2)
{
    f32 w1;
    f32 w2;
    f32 y1;
    f32 y2;
    f32 x1;
    f32 x2;
    f32 z1;
    f32 z2;
    f32 dot;
    f32 term;

    w1 = *(f32 *)(arg1 + 0x14);
    w2 = *(f32 *)(arg2 + 0x14);
    y1 = *(f32 *)(arg1 + 0xC);
    y2 = *(f32 *)(arg2 + 0xC);
    x1 = *(f32 *)(arg1 + 8);
    x2 = *(f32 *)(arg2 + 8);
    z1 = *(f32 *)(arg1 + 0x10);
    z2 = *(f32 *)(arg2 + 0x10);
    dot = w1 * w2;
    term = y1 * y2;
    dot -= term;
    term = x1 * x2;
    dot -= term;
    term = z1 * z2;
    dot -= term;
    *(f32 *)(arg0 + 0x14) = dot;
    *(f32 *)(arg0 + 8) = *(f32 *)(arg1 + 0xC) * *(f32 *)(arg2 + 0x10) - *(f32 *)(arg1 + 0x10) * *(f32 *)(arg2 + 0xC);
    *(f32 *)(arg0 + 0xC) = *(f32 *)(arg1 + 0x10) * *(f32 *)(arg2 + 8) - *(f32 *)(arg1 + 8) * *(f32 *)(arg2 + 0x10);
    *(f32 *)(arg0 + 0x10) = *(f32 *)(arg1 + 8) * *(f32 *)(arg2 + 0xC) - *(f32 *)(arg1 + 0xC) * *(f32 *)(arg2 + 8);
    *(f32 *)(arg0 + 8) += *(f32 *)(arg2 + 8) * *(f32 *)(arg1 + 0x14);
    *(f32 *)(arg0 + 0xC) += *(f32 *)(arg2 + 0xC) * *(f32 *)(arg1 + 0x14);
    *(f32 *)(arg0 + 0x10) += *(f32 *)(arg2 + 0x10) * *(f32 *)(arg1 + 0x14);
    *(f32 *)(arg0 + 8) += *(f32 *)(arg1 + 8) * *(f32 *)(arg2 + 0x14);
    *(f32 *)(arg0 + 0xC) += *(f32 *)(arg1 + 0xC) * *(f32 *)(arg2 + 0x14);
    *(f32 *)(arg0 + 0x10) += *(f32 *)(arg1 + 0x10) * *(f32 *)(arg2 + 0x14);
    *(f32 *)(arg0 + 0x18) = *(f32 *)(arg1 + 0x18) + *(f32 *)(arg2 + 0x18);
    *(f32 *)(arg0 + 0x1C) = *(f32 *)(arg1 + 0x1C) + *(f32 *)(arg2 + 0x1C);
    *(f32 *)(arg0 + 0x20) = *(f32 *)(arg1 + 0x20) + *(f32 *)(arg2 + 0x20);
}
