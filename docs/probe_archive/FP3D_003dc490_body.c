/* Archived best attempt for func_003dc490: object 96 bytes, window 128 bytes, normalized_diff 32; plain C lacks retail c1 0x500C4. */
u8 *func_003dc490(u8 *arg0, u8 *arg1) {
    f32 value;
    f32 scale;

    value = *(f32 *)(arg1 + 0x18);
    scale = 0.5f / value;
    *(f32 *)(arg0 + 0x0) = 0.5f * value;
    *(f32 *)(arg0 + 0xC) = scale * (value - *(f32 *)(arg1 + 0x24));
    *(f32 *)(arg0 + 0x4) = scale * (*(f32 *)(arg1 + 0x4) + *(f32 *)(arg1 + 0x10));
    *(f32 *)(arg0 + 0x8) = scale * (*(f32 *)(arg1 + 0x8) + *(f32 *)(arg1 + 0x20));
    return arg0;
}
