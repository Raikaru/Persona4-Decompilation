/* Best attempted reconstruction for func_003a7970; object 188B, retail window 192B, normalized_diff 17. Restored to INCLUDE_ASM because it did not match. Uses O3; opt_propagation was left at its original state. */
s32 func_003a7970(u8 *arg0, u8 *arg1)
{
    s32 mask = 0xEFFFFFFF;
    void (*callback)(u8 *, s32 *, s32) = func_003a76c0;
    u8 *arg0_2c = *(u8 **)(arg0 + 0x2C);
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_2;
    s32 index;
    s32 temp_10;

    temp_4 = *(s32 *)(arg0 + 8);
    temp_16 = *(u8 **)(temp_4 + iGpffffb610);
    temp_2 = *(u8 **)(temp_16 + 0x9C);
    *(s32 *)(temp_2 + (*(s32 *)(temp_2 + 0xE4) * 0x24) + 0x140) = *(s32 *)(arg1 + 4);
    *(s32 *)(temp_2 + (*(s32 *)(temp_2 + 0xE4) * 0x24) + 0x154) = *(s32 *)(arg1 + 0);
    index = *(s32 *)(temp_2 + 0xE4);
    temp_10 = *(s32 *)(arg1 + 8);
    *(s32 *)(temp_2 + (index * 0x24) + 0x160) = temp_10;
    *(void (**)(u8 *, s32 *, s32))(temp_16 + 0x24) = callback;
    func_003b42e0(temp_4, temp_16 + 0x50,
                  (u32)*(u32 *)(arg0_2c + 4) >> 2, mask,
                  index * 0x24, index, temp_10);
    *(void (**)(u8 *, s32 *, s32))(temp_16 + 0x24) =
        (void (*)(u8 *, s32 *, s32))func_003a72a0;
    return 1;
}
