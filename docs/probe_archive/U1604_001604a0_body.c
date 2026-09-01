/* Archived candidate for func_001604a0; did not match (object 248B, window 256B, normalized_diff 64). */
void func_001604a0(u8 *arg0)
{
    f32 inv = 1.0f / *(f32 *)(arg0 + 0x80);
    s32 i;
    s32 j;
    u8 *base = D_007E4320;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 8; j++) {
            u8 *p = base + (i << 11) + (j << 8);
            f32 x = code1_0016_cvt((j * 5) << 4);
            f32 y = code1_0016_cvt((i << 6) + 64);
            f32 z = code1_0016_cvt((j * 5 + 1) << 4);
            *(f32 *)(p + 0) = x; *(f32 *)(p + 4) = y; *(f32 *)(p + 8) = *(f32 *)(arg0 + 0x80);
            *(f32 *)(p + 64) = z; *(f32 *)(p + 68) = y; *(f32 *)(p + 72) = *(f32 *)(arg0 + 0x80);
            *(f32 *)(p + 128) = x; *(f32 *)(p + 132) = y; *(f32 *)(p + 136) = *(f32 *)(arg0 + 0x80);
            *(f32 *)(p + 192) = z; *(f32 *)(p + 196) = y; *(f32 *)(p + 200) = *(f32 *)(arg0 + 0x80);
            *(f32 *)(p + 24) = inv; *(f32 *)(p + 88) = inv; *(f32 *)(p + 152) = inv; *(f32 *)(p + 216) = inv;
        }
    }
}
