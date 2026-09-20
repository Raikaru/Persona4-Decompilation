s32 func_002e8410(u8 *arg0) {
    s32 k;
    s32 task;
    u8 *out;
    FclVec2 v0;
    FclVec2 v1;
    FclVec2 v2;
    FclVec2 v3;
    FclVec2 v4;
    FclVec2 v5;
    FclVec2 v6;
    FclVec2 v7;
    FclVec2 v8;
    FclVec2 v9;
    FclByte4 menuColor;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclDrawColor c3;
    FclDrawColor c4;
    f32 b0[4];
    f32 b1[4];
    f32 b2[4];
    f32 b3[4];
    f32 b4[4];
    u8 *e;
    extern s32 func_00331560(void);

    func_0044ea90(D_00641B00, 0x166);
    out = D_008873F4[0](1, 0x314, 0x40000);
    task = func_00451fc0((s32)arg0, D_00641B10, 0xF, 0, 0, func_002e7ac0, func_002e82b0, out);
    *out = 0;
    *(out + 1) = 0x11;
    *(out + 0x144) = 0;
    func_00313b50(task);
    *(out + 0x20) = 0;
    *(out + 0xB3) = 0;
    *(s32 *)(out + 0x254) = func_0034a4f0((s32)arg0, 0);
    {
        s32 partyIndex;
        for (partyIndex = 0; partyIndex < (func_0010b5b0() & 0xFFFF); partyIndex++) {
            *(s32 *)(out + partyIndex * 4 + 0x154) = func_0034ad70((s32)arg0, func_0010b5b0() & 0xFF, 0x41);
        }
    }
    *(s32 *)(out + 0x184) = func_0034ad70((s32)arg0, func_0010b5b0() & 0xFF, 0x41);
    *(s32 *)(out + 0x188) = func_0034ad70((s32)arg0, func_0010b5b0() & 0xFF, 0x58);
    {
        s32 segmentIndex;
        for (segmentIndex = 0; segmentIndex < 0xC; segmentIndex++) {
            func_002b2a60(&menuColor, 0, 0, 0x99, 0xFF);
            e = func_0034ae50(*(u8 **)(out + 0x188), (s8)segmentIndex);
            *(FclByte4 *)(e + 0x75) = menuColor;
        }
    }
    *(s32 *)(out + 0x24C) = (s32)func_002b74f0((s32)arg0, func_00331560());
    {
        s32 descriptorId;
        for (descriptorId = 0; descriptorId < 500; descriptorId++) {
            func_002b7750((s16)descriptorId, (s16)descriptorId);
        }
    }
    {
        s32 pairIndex;
        for (pairIndex = 0; pairIndex < 0xC; pairIndex++) {
            func_002b7750((s16)(pairIndex * 2 + 500), 0x1AC);
            func_002b7750((s16)(pairIndex * 2 + 501), 0x1AF);
        }
    }
    func_002b7750(0x20C, 0x80);
    {
        s32 arrowIndex;
        for (arrowIndex = 0; arrowIndex < 9; arrowIndex++) {
            func_002b7750((s16)(arrowIndex + 0x20D), 0xDC);
        }
    }
    {
        s32 indicatorIndex;
        for (indicatorIndex = 0; indicatorIndex < 3; indicatorIndex++) {
            func_002b7750((s16)(indicatorIndex + 0x216), 0x86);
            func_002b7750((s16)(indicatorIndex + 0x219), 0x87);
        }
    }
    {
        s32 rowIndex;
        for (rowIndex = 0; rowIndex < 0xC; rowIndex++) {
            func_002b7750((s16)(rowIndex + 0x21C), 0x193);
            func_002b7750((s16)(rowIndex + 0x22B), 0x19A);
            func_002b7750((s16)(rowIndex + 0x238), 0x188);
            func_002b7750((s16)(rowIndex + 0x244), 0x18C);
            func_002b7750((s16)(rowIndex + 0x250), 0x1C);
            func_002b7750((s16)(rowIndex + 0x25E), (s16)(rowIndex + 0x39));
            func_002b7750((s16)(rowIndex + 0x270), 0x193);
            func_002b7750((s16)(rowIndex + 0x27D), 0x19B);
            func_002b7750((s16)(rowIndex + 0x28B), 0x188);
            func_002b7750((s16)(rowIndex + 0x297), 0x18D);
            func_002b7750((s16)(rowIndex + 0x2A3), 0x1C);
        }
    }
    func_002b7750(0x228, 0x193);
    func_002b7750(0x229, 0x193);
    func_002b7750(0x2B1, 0x1A2);
    func_002b7750(0x25C, 0x1C);
    func_002b7750(0x25D, 0x1C);
    func_002b7750(0x27C, 0x193);
    func_002b7750(0x289, 0x19B);
    func_002b7750(0x28A, 0x19B);
    func_002b7750(0x237, 0x73);
    func_002b7750(0x2AF, 0x73);
    func_002b7750(0x2B0, 0x73);
    func_002b7750(0x26A, 0x46);
    func_002b7750(0x26B, 0x46);
    func_002b7750(0x26C, 0x46);
    func_002b7750(0x26D, 0x46);
    func_002b7750(0x26E, 0x46);
    func_002b7750(0x26F, 0x46);
    func_002b7750(0x2B2, 0x54);
    func_002b7750(0x2B3, 0x54);
    {
        s32 ballIndex;
        for (ballIndex = 0; ballIndex < 0xC; ballIndex++) {
            *(s32 *)(out + ballIndex * 4 + 0x21C) = func_0034b740((s32)arg0);
        }
    }
    func_002b7750(0x2B4, 0x193);
    func_002b7750(0x2B5, 0x19A);
    func_002b7750(0x2B6, 0x51);
    func_002b7750(0x2B7, 0x52);
    func_002b7750(0x2B8, 0x53);
    func_002b7750(0x2B9, 0x73);
    func_002b7750(0x2BA, 0x73);
    for (k = 0; k < 2; k++) {
        func_002b7750((s16)(k + 0x2BB), 0xA4);
        func_002b7750((s16)(k + 0x2BD), 0xA5);
        func_002b7750((s16)(k + 0x2BF), 0xBC);
        func_002b7750((s16)(k + 0x2C3), 0x19C);
        func_002b7750((s16)(k + 0x2C1), 0x14F);
    }
    for (k = 0; k < 8; k++) {
        func_002b7750((s16)(k + 0x2C5), 0x19E);
    }
    func_002b7750(0x2CD, 0x9E);
    func_002b7750(0x2CE, 0xA0);
    func_002b7750(0x2CF, 0x81);
    func_002b7750(0x2D0, 0x11E);
    func_002b7750(0x2D1, 0x11E);
    func_002b7750(0x2D8, 0x1D6);
    func_002b7750(0x2D9, 0x1D7);
    func_002b7750(0x2DA, 0x165);
    func_002b7750(0x2DB, (s16)((func_002e78a0() % 10) + 9));
    func_002b7750(0x2DC, (s16)((func_002e78e0() / 10) + 9));
    func_002b7750(0x2DD, (s16)((func_002e78e0() % 10) + 9));
    func_002b7750(0x22A, 0x193);
    func_002b7750(0x2DE, 0x126);
    func_002b7750(0x2DE, 0x125);
    for (k = 0; k < 0xC; k++) {
        func_002b7750((s16)(k + 0x2FB), 0x131);
        *(s32 *)(out + k * 4 + 0x258) = func_002b8150(task);
    }
    func_002b2970((u8 *)&v0, 288.0f, 14.0f);
    *(s32 *)(out + 0x28C) = (s32)func_002b5c90(task, v0);
    func_002b2970((u8 *)&v1, 288.0f, 14.0f);
    func_002b29e0(b0, 160.0f, 36.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x28C), v1, b0);
    func_002b6130(*(s32 *)(out + 0x28C), 0xAB);
    func_002b6140(*(s32 *)(out + 0x28C), 0);
    func_002b2a60(&c0, 0xFF, 0xFF, 0xFF, 0);
    func_002b5e30((u8 *)*(s32 *)(out + 0x28C), c0);
    func_002b5e20(*(s32 *)(out + 0x28C), 53.0f);
    func_002b2970((u8 *)&v2, 0.0f, 14.0f);
    *(s32 *)(out + 0x290) = (s32)func_002b5c90(task, v2);
    func_002b2970((u8 *)&v3, 0.0f, 14.0f);
    func_002b29e0(b1, 26.0f, 36.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x290), v3, b1);
    func_002b6130(*(s32 *)(out + 0x290), 0xAB);
    func_002b6140(*(s32 *)(out + 0x290), 0);
    func_002b2a60(&c1, 0xFF, 0xFF, 0xFF, 0);
    func_002b5e30((u8 *)*(s32 *)(out + 0x290), c1);
    func_002b5e20(*(s32 *)(out + 0x290), 53.0f);
    func_002b2970((u8 *)&v4, 0.0f, 0.0f);
    *(s32 *)(out + 0x2AC) = (s32)func_002b5c90(task, v4);
    func_002b2970((u8 *)&v5, 0.0f, 0.0f);
    func_002b29e0(b2, 640.0f, 7.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x2AC), v5, b2);
    func_002b6130(*(s32 *)(out + 0x2AC), 0xB2);
    func_002b2a60(&c2, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002b5e30((u8 *)*(s32 *)(out + 0x2AC), c2);
    func_002b6140(*(s32 *)(out + 0x2AC), 1);
    func_002b6120(*(s32 *)(out + 0x2AC), 1);
    func_002b2970((u8 *)&v6, 0.0f, 432.0f);
    *(s32 *)(out + 0x2B0) = (s32)func_002b5c90(task, v6);
    func_002b2970((u8 *)&v7, 0.0f, 432.0f);
    func_002b29e0(b3, 640.0f, 16.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x2B0), v7, b3);
    func_002b6130(*(s32 *)(out + 0x2B0), 0xB2);
    func_002b2a60(&c3, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002b5e30((u8 *)*(s32 *)(out + 0x2B0), c3);
    func_002b6140(*(s32 *)(out + 0x2B0), 1);
    func_002b6120(*(s32 *)(out + 0x2B0), 1);
    func_002b2970((u8 *)&v8, 0.0f, 69.0f);
    *(s32 *)(out + 0x2B4) = (s32)func_002b5c90(task, v8);
    func_002b2970((u8 *)&v9, 0.0f, 69.0f);
    func_002b29e0(b4, 640.0f, 343.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x2B4), v9, b4);
    func_002b6130(*(s32 *)(out + 0x2B4), 0xB2);
    func_002b2a60(&c4, 0x2D, 0x2D, 0x2D, 0xE5);
    func_002b5e30((u8 *)*(s32 *)(out + 0x2B4), c4);
    func_002b6140(*(s32 *)(out + 0x2B4), 1);
    func_002b6120(*(s32 *)(out + 0x2B4), 1);
    *(s32 *)(out + 0x250) = func_0033e3f0(task);
    *(s32 *)(out + 0x2BC) = func_002b9f90(task, 0x30, func_00331600());
    return task;
}
