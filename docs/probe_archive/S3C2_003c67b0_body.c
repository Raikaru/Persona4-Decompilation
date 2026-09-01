/* func_003c67b0: object 432B/window 432B/normalized_diff 299; first differing offsets 0,4,6-7,10-12,14-16,18,20,22,24-28; typed six-argument helper gave 424B/window 432B (undersized 8B), old-style helper gave 432B but frame 0xB0 vs retail 0x90, a 0x20-byte surplus from two long-lived locals; ASM restored. */
s8 *func_003c67b0(u32 arg0, u8 ***arg1, s16 arg2, u8 *arg3) {
    extern u8 **func_003e1210(s32 arg0, u32 arg1, s32 arg2, s32 arg3);
    extern s32 func_003c65b0();
    u8 *table;
    u8 *entry;
    u8 *cursor;
    u32 index;
    u8 **output;

    table = (u8 *)((u8 **(*)(s32, s32))jtbl_008873E8[0])((s32)(arg0 * 4), 0x30502);
    output = (u8 **)func_003e1210(0x24, arg0, 4, 0x30502);
    *(arg1 + 0) = output;
    output = (u8 **)func_003e1210(0x10, (arg0 >> 1) + 1, 4, 0x30502);
    *(arg1 + 1) = output;
    index = 0;
    if (arg0 != 0) {
        cursor = table;
        do {
            entry = (u8 *)D_008873F8[0](*(s32 *)((u8 *)arg1 + 0), 0x30502);
            *(u8 **)(cursor + 0) = entry;
            *(u8 *)(entry + 0x20) = 0;
            *(u32 *)(entry + 0) = index;
            *(s32 *)(entry + 0x14) = 0;
            *(s32 *)(entry + 0x10) = 0;
            *(s32 *)(entry + 0x18) = 0;
            *(s32 *)(entry + 4) = func_003c65b0(*(u8 **)((u8 *)arg1 + 4), arg2,
                                                 *(u16 *)(arg3 + 0), *(u16 *)(arg3 + 2),
                                                 index, table);
            *(s32 *)(entry + 8) = func_003c65b0(*(u8 **)((u8 *)arg1 + 4), arg2,
                                                 *(u16 *)(arg3 + 2), *(u16 *)(arg3 + 4),
                                                 index, table);
            *(s32 *)(entry + 0xC) = func_003c65b0(*(u8 **)((u8 *)arg1 + 4), arg2,
                                                   *(u16 *)(arg3 + 4), *(u16 *)(arg3 + 0),
                                                   index, table);
            index += 1;
            arg3 += 0x14;
            cursor += 4;
        } while (index < arg0);
    }
    return (s8 *)table;
}
