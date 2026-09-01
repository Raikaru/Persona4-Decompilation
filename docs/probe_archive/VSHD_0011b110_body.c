/* object 444B; retail window 448B; normalized_diff 16; differing offsets 0x58, 0x5C, 0x78, 0x7C; retail-only tail 0x1AC; exact cast applied: (f32)(u32)*(u8 *)(arg0 + 0x505); residual is two call-site aggregate/float argument-materialization swaps plus four-byte tail; ruled out declaration changes, common-subexpression pragma alternatives, hand-written conversion variants, direct float arguments, aggregate dereference casts, staged duplicate float locals, and Vec2f initializer syntax. */
void func_0011b110(u8 *arg0)
{
    Vec2f z;
    f32 intensity;
    s32 state;
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
        intensity = *(f32 *)(arg0 + 0x53C);
        func_0034c270(z, *(u8 *)(arg0 + 0x505), 0x10, intensity);
        return;
    case 3:
        intensity = *(f32 *)(arg0 + 0x53C);
        func_0034c270(z, *(u8 *)(arg0 + 0x505), 0x23, intensity);
        return;
    case 1:
        value = (f32)(u32)*(u8 *)(arg0 + 0x505);
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
