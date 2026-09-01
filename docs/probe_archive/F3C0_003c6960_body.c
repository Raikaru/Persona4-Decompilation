/* func_003c6960 archive: object 232B, window 224B, normalized_diff 150; differing offsets 0x0c,0x14,0x18,0x1c,0x20,0x24,0x2c,0x30,0x34,0x38,0x3c,0x44,0x4c,0x50,0x54,0x58,0x5c,0x60,0x64,0x68,0x6c,0x70,0x74,0x78,0x7c,0x80,0x84,0x8c,0x90,0x94,0x98,0x9c,0xa0,0xa4,0xa8,0xac,0xb0,0xb4,0xb8,0xbc,0xc0,0xc4,0xcc,0xd0,0xd4,0xdc,0xe0,0xe4; classification: object-over-window; in-place $a2 key normalization and generated nested pair-check control flow ruled out; no callee/global declarations involved. */
// FUN_003C6960
u8 *func_003c6960(u8 *arg0, u16 arg1, s32 arg2) {
    s32 temp_8;
    u16 temp_4;
    u16 temp_5;
    u16 temp_7;
    u8 *var_2;

    var_2 = *(u8 **)(arg0 + 4);
    temp_8 = arg1 & 0xFFFF;
    temp_7 = *(u16 *)(var_2 + 0);
    if (temp_7 != temp_8)
        goto block_1;
    if (*(u16 *)(var_2 + 2) != (arg2 & 0xFFFF))
        goto block_1;
    return var_2;
block_1:
    arg2 &= 0xFFFF;
    if (temp_7 == arg2 && *(u16 *)(var_2 + 2) == temp_8)
        return var_2;
    var_2 = *(u8 **)(arg0 + 8);
    temp_5 = *(u16 *)(var_2 + 0);
    if (temp_5 != temp_8)
        goto block_5;
    if (*(u16 *)(var_2 + 2) != arg2)
        goto block_5;
    return var_2;
block_5:
    if (temp_5 == arg2 && *(u16 *)(var_2 + 2) == temp_8)
        return var_2;
    var_2 = *(u8 **)(arg0 + 0xC);
    temp_4 = *(u16 *)(var_2 + 0);
    if (temp_4 != temp_8)
        goto block_9;
    if (*(u16 *)(var_2 + 2) != arg2)
        goto block_9;
    return var_2;
block_9:
    if (temp_4 == arg2 && *(u16 *)(var_2 + 2) == temp_8)
        return var_2;
    var_2 = NULL;
    return var_2;
}
