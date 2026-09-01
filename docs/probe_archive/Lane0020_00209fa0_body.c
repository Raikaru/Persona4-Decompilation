/* Lane0020_09fa0_5 candidate; lverify MISMATCH (register allocation differs from retail). */
void func_00209fa0(s32 arg0, u8 *arg1, u8 *arg2)
{
    s8 sp7F;
    s8 sp7E;
    s8 sp7D;
    s8 sp7C;
    s32 sp6C;
    s32 sp68;
    f32 sp64;
    s32 sp60;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f21;
    s16 temp_2_2;
    s16 temp_2_3;
    s16 temp_2_4;
    s16 temp_2_5;
    s16 temp_2_6;
    s16 temp_2_7;
    s16 temp_3;
    s16 temp_3_2;
    s32 *temp_2;
    s32 temp_2_8;
    s32 temp_2_9;
    u8 var_10;
    void (**base)(u32, u32);
    Work4 work;

    extern s8 func_00105f00(s16 arg0);
    extern u32 func_0010d6d0(s16 arg0);
    extern void func_00272950(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_00273170(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_00271b70(u8 *arg0);
    extern s32 func_002738d0(u8 *arg0);
    extern void func_00205e00(void);
    extern s32 func_00274cd0(f32 x, f32 y, f32 scale, s32 color,
                             s32 chr, s32 id, s32 str, s32 flags, s32 *width);

    temp_2 = (s32 *)func_00452560(*(s32 *)(arg1 + 0x5B0));
    func_002012d0((u8 *)temp_2, *(f32 *)(arg2 + 0), *(f32 *)(arg2 + 4));
    if (*(u16 *)(arg1 + 0) != 2) {
        func_00205ff0(arg1, (u8 *)arg0, *(f32 *)(arg2 + 0),
                      *(f32 *)(arg2 + 4), (void (*)(void))func_00205e00,
                      (u8 *)arg0);
    }
    temp_2_2 = *(s16 *)(arg1 + 0x20);
    if (temp_2_2 < 4) {
        *(s16 *)(arg1 + 0x20) = temp_2_2 + 1;
    }
    temp_2_3 = *(s16 *)(arg1 + 0x22);
    if (temp_2_3 < 0xA) {
        *(s16 *)(arg1 + 0x22) = temp_2_3 + 1;
    }
    if ((*(s32 *)(arg1 + 4) & 4) != 0) {
        temp_2_4 = *(s16 *)(arg1 + 0x16);
        if (temp_2_4 < 4) {
            *(s16 *)(arg1 + 0x16) = temp_2_4 + 1;
        }
        temp_2_5 = *(s16 *)(arg1 + 0x18);
        if (temp_2_5 < 7) {
            *(s16 *)(arg1 + 0x18) = temp_2_5 + 1;
        }
    } else {
        temp_2_6 = *(s16 *)(arg1 + 0x16);
        if (temp_2_6 > 0) {
            *(s16 *)(arg1 + 0x16) = temp_2_6 - 1;
        }
        temp_2_7 = *(s16 *)(arg1 + 0x18);
        if (temp_2_7 > 0) {
            *(s16 *)(arg1 + 0x18) = temp_2_7 - 1;
        }
    }
    temp_f0 = (f32)*(s16 *)(arg1 + 0x1C) / 5.0f;
    temp_f1 = 1.0f;
    if (temp_f0 <= 1.0f) {
        temp_f1 = 0.0f;
        if (!(temp_f0 < 0.0f)) {
            temp_f1 = temp_f0;
        }
    }
    temp_f21 = 1.0f - (2.0f * temp_f1 - temp_f1 * temp_f1);
    temp_f20 = 36.0f * temp_f21;
    func_00201650((u8 *)temp_2, 9, 0x4E, 0xFE, 0xFF, 0x22, 0xFF,
                  (f32)0x1EB, 324.0f + temp_f20);
    if (!(temp_f21 <= 0.0f)) {
        base = D_00887300;
        base[0](1, 0);
        base[0](8, 1);
        work.colors.c0 = 0;
        work.colors.c1 = 0;
        work.colors.c2 = 0xFF;
        work.colors.c3 = 0;
        work.value3 = 0x64;
        work.value0 = (s32)((330.0f + temp_f20) - 40.0f);
        work.value1 = 0x1A4;
        work.value2 = 0x28;
        func_0045d6e0((u8 *)&work.colors, (f32 *)(void *)&work.value3,
                      0.0f, 0);
        base[0](8, 0);
    }
    base = D_00887300;
    base[0](6, 1);
    func_002019e0((u8 *)temp_2, 72.0f);
    func_00201650((u8 *)temp_2, 9, 0x3B, 0x1B, 0x1B, 0x1B, 0xFF,
                  (f32)0x1ED, 330.0f);
    temp_2_9 = func_00105f00(
        *(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4));
    func_00201650((u8 *)temp_2, 9, temp_2_9 + 0x3F, 0xFE, 0xFF, 0x22, 0xFF,
                  168.0f, 334.0f);
    func_00272c60(0x40);
    temp_2_8 = func_00274cd0(
        357.0f, 332.0f, 50.0f, -1, 0, 1,
        func_0010d6d0(*(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4)),
        0, 0);
    temp_f0 = (f32)func_002738d0((u8 *)temp_2_8);
    func_00272950((u8 *)temp_2_8,
                  (s32)(16.0f * (357.0f +
                      (0.5f * (138.0f - temp_f0)))),
                  0xA60);
    func_00273170((u8 *)temp_2_8, 1, 0);
    func_00271b70((u8 *)temp_2_8);
    func_00272c80(0x40);
    base[0](6, 0);
    func_002019e0((u8 *)temp_2, 0.0f);
    temp_f0_2 = (f32)*(s16 *)(arg1 + 0x1E) / 10.0f;
    temp_f1 = 1.0f;
    if (temp_f0_2 <= 1.0f) {
        temp_f1 = 0.0f;
        if (!(temp_f0_2 < 0.0f)) {
            temp_f1 = temp_f0_2;
        }
    }
    temp_f1 = 255.0f * (1.0f -
        (1.0f - (2.0f * temp_f1 - temp_f1 * temp_f1)));
    if (2.1474836e9f <= temp_f1) {
        var_10 = (u8)((s32)(temp_f1 - 2.1474836e9f) | 0x80000000);
    } else {
        var_10 = (u8)(s32)temp_f1;
    }
    func_00201650((u8 *)temp_2, 9, 0x44, 0xFE, 0xFF, 0x22, var_10,
                  402.0f - (150.0f * temp_f0_2), 308.0f);
    temp_3 = *(s16 *)(arg1 + 0x1C);
    if (temp_3 < 5) {
        *(s16 *)(arg1 + 0x1C) = temp_3 + 1;
    }
    temp_3_2 = *(s16 *)(arg1 + 0x1E);
    if (temp_3_2 < 0xA) {
        *(s16 *)(arg1 + 0x1E) = temp_3_2 + 1;
    }
}
