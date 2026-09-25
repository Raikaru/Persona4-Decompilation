void func_00320b80(u8 *arg0, s8 arg1) {
    extern void func_002e4ac0(s32, s32);
    extern void func_002b8200(u8 *, s64, FclDrawColor, f32, f32, f32);
    FclByte4 c14C;
    FclByte4 c148;
    FclByte4 c144;
    FclByte4 c140;
    FclByte4 c13C;
    FclByte4 c138;
    FclByte4 c134;
    FclByte4 c130;
    FclByte4 c12C;
    FclPackedPosition sp120;
    FclPackedPosition sp118;
    FclPackedPosition sp110;
    FclPackedPosition sp108;
    FclPackedPosition sp100;
    FclPackedPosition spF8;
    FclPackedPosition spF0;
    FclPackedPosition spE8;
    u8 *task;
    s32 mode;
    u8 *t;
    u8 *h;
    u8 *e;
    u8 *q;
    u8 *row;
    s16 i;
    s16 j;
    s16 res;
    u16 w;
    u8 b;
    s32 m;
    s32 x;
    s32 y;
    s32 d;

    task = arg0;
    t = *(u8 **)(arg0 + 0x38);
    *(s16 *)(t + 0x11E) = 0;
    *(s8 *)(t + 0x128) = -1;
    mode = arg1;
    if (mode == 0) {
        func_002e4ac0(0, 0);
    }
    func_002b2970((u8 *)&sp120, 16.0f, 104.0f);
    func_0031e5b0(task, sp120.bits, 0, 0, 0, 0, 0);
    for (i = 0; i < (u16)func_0010b5b0(); i++) {
        func_002b2970((u8 *)&sp118, 16.0f, 128.0f);
        w = *(u16 *)(func_002e48a0(0, i) + 2);
        b = *(u8 *)(func_002e48a0(0, i) + 4);
        func_003191c0(task, sp118.bits, (s8)i, w, b, (s16)(i * 2), 0, *(s8 *)(func_002e4870(0) + 8));
        res = i + 0x25E;
        h = func_0046d200(func_00331560(), 0x39);
        m = i * 23;
        x = m + 0x14E;
        func_002b2970((u8 *)&sp110, x, 110.0f);
        func_002b6c30(res, sp110.position, 158.0f, 0x56);
        c14C = func_002b2a60(0x8C, 0xE2, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(res) + 0x85) = c14C;
        func_002b6a70(res, 0, 0xFF, 0, 2, i);
        func_002b6af0(res, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 2, i);
        func_002b2970((u8 *)&sp108, x, 110.0f + func_0046b2f0(h) / 2.0f);
        func_002b2970((u8 *)&sp100, x, 110.0f);
        func_002b69f0(res, sp108.position, sp100.position, 0, 2, i);
        func_0046d280(h);
        e = func_0034ae50(*(u8 **)(t + 0x184), i);
        func_002b2970((u8 *)&spF8, m + 0x149, 104.0f);
        c148 = func_002b2a60(0, 0, 0x99, 0xFF);
        c144 = func_002b2a60(0, 0, 0x99, 0xFF);
        func_002b83e0(e, *(FclDrawPosition *)&spF8, c148, c144, 0xFF, 0xFF, 32.0f, 159.0f, 2, i, 0, 0);
        if (mode == 0) {
            y = m + 0x7F;
            q = t + i * 4;
            row = t + i * 12;
            for (j = 0; j < (u16)func_0010b5b0(); j++) {
                e = func_0034ae50(*(u8 **)(q + 0x154), j);
                func_002b2970((u8 *)&spF0, j * 23 + 0x149, y);
                c140 = func_002b2a60(0, 0, 0x99, 0xA5);
                func_002b8200(e, spF0.bits, c140, 1.0f, 0.0f, 159.0f);
                d = j + i;
                e = func_0034ae50(*(u8 **)(q + 0x154), j);
                c13C = func_002b2a60(0, 0, 0x99, 0xFF);
                c138 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                func_002b8370(e, c13C, c138, 0, 0xA, d);
                func_002b82d0(func_0034ae50(*(u8 **)(q + 0x154), j), 0, 0xA5, 0, 0xA, d);
                *(row + j + 0x18C) = 0;
            }
        } else {
            y = m + 0x7F;
            q = t + i * 4;
            row = t + i * 12;
            for (j = 0; j < (u16)func_0010b5b0(); j++) {
                e = func_0034ae50(*(u8 **)(q + 0x154), j);
                func_002b2970((u8 *)&spE8, j * 23 + 0x149, y);
                c134 = func_002b2a60(0, 0, 0x99, 0xA5);
                func_002b8200(e, spE8.bits, c134, 1.0f, 0.0f, 159.0f);
                e = func_0034ae50(*(u8 **)(q + 0x154), j);
                c130 = func_002b2a60(0x49, 0x72, 0xFF, 0xA5);
                c12C = func_002b2a60(0, 0, 0x99, 0xA5);
                func_002b8370(e, c130, c12C, 0, 0xA, j + i);
                func_002b82d0(func_0034ae50(*(u8 **)(q + 0x154), j), 0, 0xA5, 0, 0xA, 0);
                *(row + j + 0x18C) = 0;
            }
        }
    }
}
