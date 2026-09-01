#pragma schedule on
u8 *func_003dc490(u8 *arg0, u8 *arg1) {
    f32 m00;
    f32 m11;
    f32 m22;
    f32 m21;
    f32 m12;
    f32 m01;
    f32 m10;
    f32 m02;
    f32 m20;
    f32 root;
    f32 scale;
    extern f32 sqrtf(f32);

    m00 = *(f32 *)(arg1 + 0x00);
    m11 = *(f32 *)(arg1 + 0x14);
    m22 = *(f32 *)(arg1 + 0x28);
    m21 = *(f32 *)(arg1 + 0x18);
    m12 = *(f32 *)(arg1 + 0x24);
    m01 = *(f32 *)(arg1 + 0x04);
    m10 = *(f32 *)(arg1 + 0x10);
    m02 = *(f32 *)(arg1 + 0x08);
    m20 = *(f32 *)(arg1 + 0x20);
    root = sqrtf(1.0f + (m00 - (m11 + m22)));
    *(f32 *)(arg0 + 0x00) = 0.5f * root;
    scale = 0.5f / root;
    *(f32 *)(arg0 + 0x0C) = scale * (m21 - m12);
    *(f32 *)(arg0 + 0x04) = scale * (m01 + m10);
    *(f32 *)(arg0 + 0x08) = scale * (m02 + m20);
    return arg0;
}
#pragma schedule off
