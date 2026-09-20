s32 func_002b5c90(s32 arg0, f2 p1) {
    s32 handle;
    u8 *p;
    s32 i;
    func_0044ea90(&D_0063F178, 0xD4);
    p = D_008873F4[0](1, 0x190, 0x40000);
    handle = func_00451fc0(arg0, D_0063F188, 0xF, 0, 0, (void (*)(u8 *))func_002b52a0, (void (*)(u8 *))func_002b5c60, p);
    *(f2 *)(p + 0x134) = p1;
    *(s16 *)(p + 0x14C) = 0;
    p[0x154] = 0;
    for (i = 0; i < 4; i++) {
        u8 *q = p + 0x110 + i * 4;
        q[0] = 0xFF;
        q[1] = 0xFF;
        q[2] = 0xFF;
        q[3] = 0xFF;
    }
    *(u32 *)(p + 0x188) = 0x49;
    p[0x184] = 0;
    *(s16 *)(p + 0x156) = -1;
    p[0x180] = 0;
    p[0x18C] = 0;
    *(s16 *)(p + 0x182) = 0;
    return handle;
}