/* Closest candidate for func_002df020; rejected after scoped lverify.
 * Frame remained 0xE0 vs retail 0xC0; 235 reloc-masked differing words.
 */
void func_002df020(void *arg0, s64 arg1, s64 arg2) {
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    f32 sp6C;
    f32 sp68;
    RGBA spBC;
    RGBA spB8;
    RGBA spB4;
    ShopWork *work;

    work = *(ShopWork **)((u8 *)arg0 + 0x38);
    if (work->field_11 == 2) {
        s32 color;
        func_002b2970(&spA0, 140.0f, 178.0f);
        color = func_002b2a30(0, 0x2D, 0x2D, 0x2D);
        func_002e0ca0(0x1A, spA0, color, 0xFF, 0, D_00795E30, 80.0f);
    } else if (work->field_11 == 1) {
        s32 color;
        color = func_002d4f30((s16)func_00106880(arg1));
        func_002b2970(&sp98, 140.0f, 178.0f);
        func_002e0b20(color, sp98, func_002b2a30(0, 0x2D, 0x2D, 0x2D),
                      0xFF, 0, D_00795E30, 80.0f);
    } else if (work->field_11 == 0) {
        s32 color;
        func_002b2970(&sp90, 140.0f, 178.0f);
        func_002e0ca0(0x1B, sp90, func_002b2a30(0, 0x2D, 0x2D, 0x2D),
                      0xFF, 0, D_00795E30, 80.0f);
    }

    {
        s32 color;
        u32 count;
        color = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b2970(&sp88, 140.0f, 178.0f);
        sp68 = *(f32 *)&sp88;
        sp6C = *((f32 *)&sp88 + 1);
        func_00275680(color, 0, 1, func_001067f0(arg1), 0, 0,
                      D_00795E60, -1, sp68, sp6C, 80.0f);

        count = func_00106a90((s16)arg1) / 5U;
        func_002b2970(&sp80, 448.0f, 185.0f);
        func_002b2a60(&spBC, 0x2D, 0x2D, 0x2D, 0xFF);
        func_002cacd0(sp80, *(s32 *)&spBC, 0x10, 5, count, 9, 0x7B,
                      func_0046a770(D_0063FB50), 13.0f, (s32)work->field_F28, 0xA9);
    }

    func_002b2970(&sp78, 476.0f, 187.0f);
    func_002e0b20(0x47, sp78, func_002b2a30(0x2D, 0x2D, 0x2D, 0x2D),
                  0xFF, 0, D_00795E60, 80.0f);

    spA8 = *(u64 *)((u8 *)&iGpffffa890 - 8);
    if (work->field_12 < 10) {
        *(f32 *)&spA8 = *(f32 *)&spA8 - 8.0f;
    }
    func_002b2a60(&spB8, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002cacd0(spA8, *(s32 *)&spB8, 0x10, 5, work->field_12, 9, 0x7B,
                  func_0046a770(D_0063FB50), 13.0f, (s32)work->field_F28, 0xA9);

    {
        s32 color;
        func_002b2970(&sp70, 498.0f, 247.0f);
        color = ((ShopWork *)func_002e04e0(work->field_CC8))->field_62;
        func_002b2a60(&spB4, 0xDF, 0x6C, 0, color);
        {
            s64 resource;
            resource = func_0046a770(D_0063FAA0);
            func_002cacd0(sp70, *(s32 *)&spB4, 0x1B, 0, arg2 & 0xFF, 0x2F, 0,
                          resource, 1.0f, func_0046a770(D_0063FAA0), 0xA9);
        }
    }
}
