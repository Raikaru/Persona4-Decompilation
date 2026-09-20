s32 func_0034ad70(s32 arg0, s8 arg1, s16 arg2) {
    s32 handle;
    u8 *buf;
    s32 i;

    func_0044ea90(&D_0064A740, 0x98);
    buf = (u8 *)D_008873F4[0](1, 0x1810, 0x40000);
    handle = func_00451fc0(arg0, D_0064A750, 0xF, 0, 0, (void (*)(u8 *))func_0034ac00,
                  func_0034ad40, buf);
    for (i = 0; i < 0xC; i++) {
        *(s16 *)(buf + (i << 9) + 0x104) = 0;
        *(s16 *)(buf + (i << 9) + 0x100) = arg2;
    }
    *(s8 *)(buf + 0x1800) = arg1;
    return handle;
}