void func_00323d00(u8 *arg0, s32 arg1, s8 arg2) {
    FclByte4 cFC;
    FclByte4 cF8;
    FclByte4 cF4;
    FclByte4 cF0;
    FclByte4 cEC;
    FclByte4 cE8;
    FclPackedPosition spE0;
    FclPackedPosition spD8;
    FclPackedPosition spD0;
    FclPackedPosition spC8;
    FclPackedPosition spC0;
    FclPackedPosition spB8;
    FclPackedPosition spB0;
    FclPackedPosition spA8;
    FclPackedPosition spA0;
    FclPackedPosition sp98;
    s16 k;
    s16 res;
    s32 shown;
    s32 hidden;
    s32 count;
    FclVec2 *p;

    spE0.position = func_002b2970(16.0f, 104.0f);
    func_0031e5b0(arg0, spE0.position, 0, arg2, 0, 1, 2);
    spD8.position = func_002b2970(313, 104.0f);
    func_0031e5b0(arg0, spD8.position, 0, arg2, 1, 0, 0);
    for (k = 0; k < *(s32 *)(func_002e4870(1) + 8); k++) {
        spD0.position = func_002b2970(313, 128.0f);
        func_003191c0(arg0, spD0.position, (s8)k,
                      *(u16 *)(func_002e48a0(1, k) + 2),
                      *(u8 *)(func_002e48a0(1, k) + 4),
                      (s16)(k * arg1), arg2,
                      (count = *(s8 *)(func_002e4870(1) + 8)));
    }
    for (k = 0; k < *(s32 *)(func_002e4870(0) + 8); k++) {
        spC8.position = func_002b2970(16.0f, 128.0f);
        func_0031ac10(arg0, spC8.position, 0, (s8)k, *(u16 *)(func_002e48a0(0, k) + 2), *(u8 *)(func_002e48a0(0, k) + 4), (s16)(k * arg1), arg2, 1, 0xCC);
    }
    p = (FclVec2 *)D_006440F8;
    spC0.position = func_002b2970(p->x, p->y);
    func_002b6c30(0x71, spC0.position, 138.0f, 0x41);
    cFC = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
    *(FclDrawColor *)(func_002b6150(0x71) + 0x85) = cFC;
    hidden = (1 - (s8)arg2) * 0xFF;
    shown = (s8)arg2 * 0xFF;
    func_002b6a70(0x71, shown, hidden, 0, 0, 0);
    p = (FclVec2 *)D_006440F0;
    spB8.position = func_002b2970(p->x, p->y);
    func_002b6c30(0x70, spB8.position, 139.0f, 0x41);
    cF8 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
    *(FclDrawColor *)(func_002b6150(0x70) + 0x85) = cF8;
    func_002b6a70(0x70, shown, hidden, 0, 0, 0);
    for (k = 0; k < 2; k++) {
        p = (FclVec2 *)D_00644290;
        res = (s16)(k + 0x2BB);
        spB0.position = func_002b2970(p->x + (f32)(k * 313), p->y);
        func_002b6c30(res, spB0.position, 140.0f, 0x41);
        cF4 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(res) + 0x85) = cF4;
        func_002b6a70(res, shown, hidden, 0, 0, 0);
        p = (FclVec2 *)D_00644298;
        res = (s16)(k + 0x2BD);
        spA8.position = func_002b2970(p->x + (f32)(k * 330), p->y);
        func_002b6c30(res, spA8.position, 141.0f, 0x41);
        cF0 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(res) + 0x85) = cF0;
        func_002b6a70(res, shown, hidden, 0, 0, 0);
        p = (FclVec2 *)D_00644350;
        res = (s16)(k + 0x2BF);
        spA0.position = func_002b2970(p->x + (f32)(k * 14), p->y);
        func_002b6c30(res, spA0.position, 142.0f, 0x41);
        cEC = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(res) + 0x85) = cEC;
        func_002b6a70(res, shown, hidden, 0, 0, 0);
    }
    p = (FclVec2 *)D_00644350;
    sp98.position = func_002b2970(28.0f + p->x, p->y);
    func_002b6c30(0xBC, sp98.position, 142.0f, 0x41);
    cE8 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
    *(FclDrawColor *)(func_002b6150(0xBC) + 0x85) = cE8;
    func_002b6a70(0xBC, shown, hidden, 0, 0, 0);
}
