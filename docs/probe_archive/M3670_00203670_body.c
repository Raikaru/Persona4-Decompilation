void func_00203670(s32 unused, s32 arg1)
{
    struct {
        s16 values[2];
        s32 pad;
    } sp38;
    s32 temp_4;
    s32 mask;
    u8 *temp_2;
    u8 *temp_16;
    temp_2 = func_00452560();
    temp_16 = temp_2 + 0x9C;
    *(s32 *)(temp_2 + 0x214) = arg1;
    *(s16 *)(temp_2 + 0x9C) = 1;
    *(s16 *)(temp_2 + 0xA4) = 0;
    mask = -3;
    *(s16 *)(temp_2 + 0xA6) = mask;
    *(s16 *)(temp_2 + 0xA8) = 0;
    *(s16 *)(temp_2 + 0xAA) = -9;
    *(s16 *)(temp_2 + 0xAE) = 0;
    *(s16 *)(temp_2 + 0xB0) = 0;
    *(s16 *)(temp_2 + 0xBC) = 0;
    *(s16 *)(temp_2 + 0xBE) = 0;
    *(s16 *)(temp_2 + 0xB2) = 0;
    *(s16 *)(temp_2 + 0xB4) = 0;
    temp_4 = *(s32 *)(temp_2 + 0xA0);
    temp_4 &= mask;
    *(s32 *)(temp_2 + 0xA0) = temp_4;
    temp_4 = temp_4 & 0xFFFFFFFEU;
    *(s32 *)(temp_2 + 0xA0) = temp_4;
    func_00202c60(temp_16 + 0x40, 8, 8,
                  (void *)func_00207140, (void *)func_00207320,
                  (void *)func_00207b00, (void *)func_002089e0, temp_16);
    func_00202e60(temp_16 + 0x40, (s32)func_00208870);
    sp38.values[0] = 0x1000;
    sp38.values[1] = 0x4000;
    func_00202e00(temp_16 + 0x40, (s16 *)&sp38);
    func_00202d20(temp_16 + 0x40, 3, 0);
    func_00203360(temp_16 + 0x2C, temp_16 + 0x40);
    *(s32 *)(temp_16 + 0x2C) = 0;
    *(s32 *)(temp_16 + 0x30) = 0;
}
