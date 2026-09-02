/* probe KoB3 0x002b74f0
 * residual: 80-81 words
 * retail register list: $16 arg1/$17 off?/$18 j?/$19 i/$20 base
 * tried: opt_loop_invariants off, declaration/initialization order variations
 */
// FUN_002B74F0
#pragma opt_loop_invariants off
u8 *func_002b74f0(s32 arg0, s32 arg1) {
    u8 *p;
    u8 *base;
    u8 *q;
    s32 jx;
    s32 off;
    s16 j;
    s16 i;
    f2 pos;
    u4 color;
    u32 ff;
    u32 one;
    f32 zero;

    func_0044ea90(&D_0063F178, 0x3F3);
    p = D_008873F4[0](1, 0x31220, 0x40000);
    iGpffffb574 = (u8 *)func_00451fc0(arg0, D_0063F1B0, 0xF, 0, 0,
                                        (void (*)(u8 *))func_002b6ec0,
                                        (void (*)(u8 *))func_002b74c0, p);
    *(s32 *)(p + 0) = arg1;
    *(s16 *)(p + 0x30C04) = 0;
    j = 0;
    i = 0;
    while ((s32)i < 0x30C) {
        j = 0;
        off = (s32)i * 0x100;
        while ((s32)j < 3) {
            jx = (s32)j;
            base = *(u8 **)(iGpffffb574 + 0x38);
            zero = 0.0f;
            func_002b2970(&pos, zero, zero);
            *(f2 *)(base + off + jx * 8 + 0x2C) = pos;
            ff = 0xFF;
            *(u8 *)(*(u8 **)(iGpffffb574 + 0x38) + off + jx + 0x70) = ff;
            jx = jx * 4;
            *(s32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + jx + 0xCC) = 0;
            one = 0x3F800000;
            *(s32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + jx + 0xA8) = one;
            *(s32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + jx + 0x9C) = one;
            base = *(u8 **)(iGpffffb574 + 0x38);
            func_002b2a60((u8 *)&color, ff, ff, ff, ff);
            *(u8 *)(base + off + jx + 0x81) = color.c0;
            *(u8 *)(base + off + jx + 0x82) = color.c1;
            *(u8 *)(base + off + jx + 0x83) = color.c2;
            *(u8 *)(base + off + jx + 0x84) = color.c3;
            j++;
        }
        *(s32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x18) = 0x42C80000;
        *(s32 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x0C) = 0x55;
        *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 0x14) = 0;
        q = (u8 *)(*(u8 **)(iGpffffb574 + 0x38) + off);
        *(s16 *)(q + 0x12) = 0;
        *(s16 *)(q + 0x10) = 0;
        i++;
    }
    return iGpffffb574;
}
// FUN_002B7750