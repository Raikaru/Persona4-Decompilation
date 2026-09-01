/* object 164B, retail window 160B, normalized_diff 70; oversized reconstruction archived. */
u8 *func_003d5790(s32 arg0, s32 arg1) {
    u8 *temp_2;
    s32 size;

    size = arg0 * arg1;
    temp_2 = jtbl_008873E8[0](size + 0x4C, 0x3001B);
    *(s32 *)(temp_2 + 0x2C) = arg0;
    *(s32 *)(temp_2 + 0x0) = 0;
    *(s32 *)(temp_2 + 0x8) = 0;
    *(s32 *)(temp_2 + 0x4) = 0;
    *(s32 *)(temp_2 + 0xC) = 0;
    *(s32 *)(temp_2 + 0x14) = 0xBF800000;
    *(s32 *)(temp_2 + 0x10) = 0;
    *(s32 *)(temp_2 + 0x18) = 0;
    *(s32 *)(temp_2 + 0x1C) = 0;
    *(s32 *)(temp_2 + 0x24) = arg1;
    *(s32 *)(temp_2 + 0x28) = -1;
    *(s32 *)(temp_2 + 0x20) = arg1;
    *(s32 *)(temp_2 + 0x30) = 0;
    *(s32 *)(temp_2 + 0x34) = 0;
    *(s32 *)(temp_2 + 0x38) = (s32)temp_2;
    *(s32 *)(temp_2 + 0x3C) = 0;
    *(s32 *)(temp_2 + 0x44) = 0;
    *(s32 *)(temp_2 + 0x40) = 0;
    *(s32 *)(temp_2 + 0x48) = 0;
}
