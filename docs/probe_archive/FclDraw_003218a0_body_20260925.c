void func_003218a0(u8 *arg0, s32 arg1) {
    FclDrawColor c16C;
    FclDrawColor c168;
    FclDrawColor c164;
    FclDrawColor c160;
    FclDrawColor c15C;
    FclDrawColor c158;
    FclDrawPosition sp150;
    FclDrawPosition sp148;
    FclDrawPosition sp140;
    FclDrawPosition sp138;
    u8 *t;
    u8 *e;
    u8 *h;
    s16 order;
    s16 i;
    s16 j;
    s16 res;
    s32 x;
    s32 xx;
    s32 fade;
    s32 row;
    s32 y;
    u8 *p;

    t = *(u8 **)(arg0 + 0x38);
    order = arg1;
    fade = order + 3;
    for (i = 0; i < (u16)func_0010b5b0(); i++) {
        x = i * 23;
        e = func_0034ae50(*(u8 **)(t + 0x184), i);
        func_002b2970((u8 *)&sp150, x + 0x149, 104.0f);
        c16C = func_002b2a60(0, 0, 0x99, 0xFF);
        c168 = func_002b2a60(0, 0, 0x99, 0xFF);
        func_002b83e0(e, sp150, c16C, c168, 0xFF, 0xFF, 32.0f, 159.0f, 2, order, 0, 0);
        res = i + 0x25E;
        h = func_0046d200(func_00331560(), 0x39);
        func_002b6a70(res, 0, 0xFF, 0, 0, (s16)fade);
        func_002b6af0(res, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg1);
        xx = x + 0x14E;
        func_002b2970((u8 *)&sp148, xx, 110.0f + func_0046b2f0(h) / 2.0f);
        func_002b2970((u8 *)&sp140, xx, 110.0f);
        func_002b69f0(res, sp148.position, sp140.position, 0, 3, arg1);
        func_002b68d0(res, 0, 0);
        func_0046d280(h);
        p = t + i * 4;
        row = i * 12;
        y = x + 0x7F;
        for (j = 0; j < (u16)func_0010b5b0(); j++) {
            if (*(s16 *)(t + 0x11E) == i) {
                c164 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                *(FclDrawColor *)(func_0034ae50(*(u8 **)(p + 0x154), j) + 0x75) = c164;
                if (*(s8 *)(func_002e4870(0) + row + j + 0x14) > 0) {
                    c160 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                    *(FclDrawColor *)(func_0034ae50(*(u8 **)(p + 0x154), j) + 0x75) = c160;
                }
            } else {
                c15C = func_002b2a60(0, 0, 0x99, 0xA5);
                *(FclDrawColor *)(func_0034ae50(*(u8 **)(p + 0x154), j) + 0x75) = c15C;
                if (*(s8 *)(func_002e4870(0) + row + j + 0x14) > 0) {
                    c158 = func_002b2a60(0x49, 0x72, 0xFF, 0xCC);
                    *(FclDrawColor *)(func_0034ae50(*(u8 **)(p + 0x154), j) + 0x75) = c158;
                }
            }
            e = func_0034ae50(*(u8 **)(p + 0x154), j);
            func_002b2970((u8 *)&sp138, j * 23 + 0x149, y);
            func_002b83e0(e, sp138,
                          *(FclDrawColor *)(func_0034ae50(*(u8 **)(p + 0x154), j) + 0x75),
                          *(FclDrawColor *)(func_0034ae50(*(u8 **)(p + 0x154), j) + 0x75),
                          *(func_0034ae50(*(u8 **)(p + 0x154), j) + 0x78),
                          *(func_0034ae50(*(u8 **)(p + 0x154), j) + 0x78),
                          32.0f,
                          *(f32 *)(func_0034ae50(*(u8 **)(p + 0x154), j) + 4),
                          3, order, 0, 0);
        }
    }
}
