/* probe */
extern f32 sqrtf(f32);
u8 *func_003dc490(u8 *arg0, u8 *arg1) {
    f32 root;
    f32 scale;

    root = sqrtf(1.0f + (*(f32 *)(arg1 + 0x0) - (*(f32 *)(arg1 + 0x14) + *(f32 *)(arg1 + 0x28))));
    *(f32 *)(arg0 + 0x0) = 0.5f * root;
    scale = 0.5f / root;
    *(f32 *)(arg0 + 0xC) = scale * (*(f32 *)(arg1 + 0x18) - *(f32 *)(arg1 + 0x24));
    *(f32 *)(arg0 + 0x4) = scale * (*(f32 *)(arg1 + 0x4) + *(f32 *)(arg1 + 0x10));
    *(f32 *)(arg0 + 0x8) = scale * (*(f32 *)(arg1 + 0x8) + *(f32 *)(arg1 + 0x20));
    return arg0;
}
