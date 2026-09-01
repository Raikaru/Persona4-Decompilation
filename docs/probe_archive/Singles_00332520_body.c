/* Closest candidate: object 1156B/window 1168B, normalized_diff 717.
   The exact-size body still has unresolved helper/prologue/register ordering;
   source was reverted to INCLUDE_ASM. */
s32 func_00332520(u8 *arg0) {
    u8 *work;
    u8 *table;
    s32 temp_2;
    s32 temp_16;
    s32 temp_16_3;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 i;
    s32 index;
    s16 temp_4;
    s16 low;
    s16 high;
    s8 slot;
    s8 var_20;
    s8 id;

    work = *(u8 **)(arg0 + 0x38);
    temp_16 = (func_002be100(func_002e78a0()) & 0xFF) * 0x64;
    temp_4 = (s16)((func_002e78e0() & 0xFF) + temp_16);
    var_20 = 0;
    switch (*(s8 *)work) {
    case 0:
        for (;;) {
            table = D_006450B0 + (s32)var_20 * 4;
            low = (s16)((s32)table[1] +
                        (func_002be100(table[0]) & 0xFF) * 0x64);
            high = (s16)((s32)table[3] +
                         (func_002be100(table[2]) & 0xFF) * 0x64);
            if ((temp_4 >= low) && (high >= temp_4)) {
                *(s8 *)work = *(s8 *)work + 1;
                *(s8 *)(work + 0x1808) = var_20;
                return 0;
            }
            var_20 = (s8)(var_20 + 1);
            if (table[0] == 0)
                return -1;
        }
    case 1:
        *(u32 *)(work + 0x1804) = 0;
        for (i = 0; i < 0x600; i++) {
            *(s32 *)(work + i * 4 + 4) = 0;
            temp_2 = func_002be1b0((s16)i);
            if ((temp_2 != 0x10) && (temp_2 != 0x11) && (temp_2 != 0x12)) {
                slot = *(s8 *)(work + 0x1808);
                if (slot == func_00106ac0((s16)i) &&
                    func_002dfd00((u16)((func_002be1b0((s16)i) & 0xFFF00) >> 8)) == 0) {
                    temp_17_3 = (s32)((func_00106b20((s16)i) & 0xFFF00) >> 8);
                    if ((func_002be160((u8 *)(u32)temp_17_3,
                                       func_00106b20((s16)i) & 0xFF) == 0) ||
                        ((temp_17_4 = (s32)((func_00106b50((s16)i) & 0xFFF00) >> 8),
                          func_002be160((u8 *)(u32)temp_17_4,
                                        func_00106b50((s16)i) & 0xFF) == 0))) {
                        *(s32 *)(work + (*(u32 *)(work + 0x1804) * 4) + 4) = i;
                        *(u32 *)(work + 0x1804) += 1;
                    }
                }
            }
        }
        *(s8 *)work = *(s8 *)work + 1;
        goto done;
    case 2:
        if (*(u32 *)(work + 0x1804) == 0) {
            id = func_002bab80(D_00645240);
            *(s8 *)(work + 1) = id;
            func_002badc0(id, 0x1D);
        } else {
            index = *(s32 *)(work + ((func_003b7060() %
                                      *(u32 *)(work + 0x1804)) * 4) + 4);
            if (((func_00106b20((s16)index) & 0xFFF00) >> 8) != 0x500)
                func_00332370(arg0, index, func_00106b20((s16)index));
            else if (((func_00106b50((s16)index) & 0xFFF00) >> 8) != 0x500)
                func_00332370(arg0, index, func_00106b50((s16)index));
        }
        *(s8 *)work = *(s8 *)work + 1;
        goto done;
    case 3:
        if (func_002bb680(*(s8 *)(work + 1)) != 0) {
            func_002bbcf0(*(s8 *)(work + 1));
            goto done;
        }
        func_002bb550(*(s8 *)(work + 1));
        return -1;
    default:
    done:
        return 0;
    }
}
