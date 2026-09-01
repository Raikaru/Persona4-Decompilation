/* func_003cc680: object_size=124, window=96, normalized_diff=103, differing_offsets=0x00,0x01,0x02,0x03,0x08,0x0a,0x0b,0x0c,0x0e,0x0f,0x10,0x12,0x14,0x16,0x17,0x18; mixed declaration order (u8* then f32), exact scale constant 0x437F0001, established output global iGpffffb27c, integer-domain pointer, and scalar packed stores were tried; object exceeds window. Retail requires standalone MMI `pexew` at +0x24/+0x28 and `ppacw` at +0x3c, which MWCCPS2 cannot emit from ordinary C; inline ordinary MMI is forbidden, so this is a compiler floor. */
void func_003cc680(u8 *arg0, f32 fparg0) {
    extern s32 iGpffffb27c;
    union {
        u32 u;
        f32 f;
    } bits;
    f32 scale;
    f32 value0;
    f32 value1;
    f32 value2;
    f32 value3;
    u32 words[4];
    u8 *dst;

    bits.u = 0x437F0001;
    scale = bits.f;
    value0 = fparg0 * scale;
    value1 = *(f32 *)(arg0 + 4) * scale;
    value2 = *(f32 *)(arg0 + 8) * scale;
    value3 = *(f32 *)arg0 * scale;
    bits.f = value0;
    words[0] = bits.u;
    bits.f = value1;
    words[1] = bits.u;
    bits.f = value2;
    words[2] = bits.u;
    bits.f = value3;
    words[3] = bits.u;
    dst = (u8 *)(u32)iGpffffb27c;
    *(u32 *)(dst + 0) = words[0];
    *(u32 *)(dst + 4) = words[1];
    *(u32 *)(dst + 8) = words[2];
    *(u32 *)(dst + 12) = words[3];
    iGpffffb27c += 0x10;
}
