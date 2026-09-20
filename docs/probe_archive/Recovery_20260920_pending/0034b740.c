s32 func_0034b740(s32 arg0) {
    s32 handle;
    u8 *buf;
    s16 i;

    func_0044ea90(&D_0064A740, 0x14D);
    buf = (u8 *)D_008873F4[0](1, 0xF10, 0x40000);
    handle = func_00451fc0(arg0, D_0064A770, 0xF, 0, 0, (void (*)(u8 *))func_0034b380,
                  func_0034b710, buf);
    i = 0;
    *(s16 *)(buf + 0xE10) = 0;
    while (i < 0xE) {
        i++;
    }
    *(s16 *)(buf + 0) = 0x41;
    return handle;
}