/* obj 444B / window 448B / normalized_diff 18 / differing offsets 192,196,444(tail); probes: result/bits local split, unsigned raw/direct conversion, bitwise operand order, declaration order, optimization_level 1, opt_common_subs off. */
void func_0011b110(u8 *arg0)
{
    Vec2f z;
    f32 intensity;
    s32 state;
    u32 bits;
    s32 temp;
    f32 value;
    f32 norm;
    s32 work[4];
    u8 color[4];
    z.x = 0.0f;
    z.y = 0.0f;
    state = *(s32 *)(arg0 + 0x52C);
    switch (state) {
    case 0:
    case 2:
    case 4:
        func_0034c270(z, *(f32 *)(arg0 + 0x53C), *(u8 *)(arg0 + 0x505), 0x10);
        return;
    case 3:
        func_0034c270(z, *(f32 *)(arg0 + 0x53C), *(u8 *)(arg0 + 0x505), 0x23);
        return;
    case 1:
        temp = *(u8 *)(arg0 + 0x505);
        if (temp >= 0) {
            value = (f32)temp;
        } else {
            bits = (u32)temp;
            bits = (bits >> 1) | (bits & 1);
            value = (f32)(s32)bits;
            value = value + value;
        }
        norm = value / 255.0f;
        work[0] = 0;
        work[1] = (s32)(231.0f - 166.0f * norm);
        work[2] = 0x280;
        work[3] = (s32)(332.0f * norm);
        color[0] = 0xFF;
        color[1] = 0xE9;
        color[2] = 0x2C;
        color[3] = *(u8 *)(arg0 + 0x505);
        D_00887300[0](1, 0);
        func_0045d6e0(color, work, 0, 0.0f);
        return;
    default:
        func_0046d730(D_005E4868, 0xB3D);
        return;
    }
}
