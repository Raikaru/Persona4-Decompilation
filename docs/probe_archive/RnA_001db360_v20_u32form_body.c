/* RnA_001db360_v20_u32form
 * object/window: 532B/544B
 * normalized_diff: 141 words
 * differing offsets: see build/RnA_001db360_v20_u32wrappers_scope.json (target 0x001db360)
 * ruled out: u64 formation causes dsll32/dsra32 before formation dereference;
 * u16 index rotates saved registers; pointer formation signatures and wrapper
 * function-pointer casts worsen code or prevent direct jal; no pragmas used.
 */
s32 func_001db360(u32 formation, s64 index, s32 enabled) {
    extern s32 func_0010f420(u32 arg0, u32 arg1);
    extern s32 func_001f9ce0(u8 *arg0, s32 arg1);
    extern s8 func_00233a90(u8 *arg0, s32 arg1);
    extern s32 func_0023d6e0(s16 arg0);
    extern u32 func_0023e130(u8 *arg0);
    extern u8 *func_0023e140(u8 *arg0);
    extern s32 func_00242800(u8 *arg0, s32 arg1);
    u8 *temp_17;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_2;
    s32 var_8;
    u16 temp_3;

    temp_17 = *(u8 **)((u8 *)formation + 0x30);
    if ((*(u8 *)(temp_17 + 0xA2) == 1) &&
        (func_001f9ce0((u8 *)formation, (s16)index) == 0) &&
        (func_0010f420(*(u16 *)(temp_17 + 0xA4), (u16)index) == 0)) {
        return 1;
    }
    temp_16 = func_0023d6e0((s16)index);
    if ((enabled == 1) && !(temp_16 & 0xE0001)) {
        if (temp_16 & 2) {
            if (func_00233a90(*(u8 **)(temp_17 + 0xA64), 0x10) > 0) {
                return 0;
            }
            goto block_12;
        }
        if (!(temp_16 & 0x40) &&
            (func_00233a90(*(u8 **)(temp_17 + 0xA64), 0x11) > 0)) {
            return 0;
        }
        goto block_12;
    }
block_12:
    if (temp_16 & 2) {
        if (*(u8 *)(temp_17 + 0xA2) == 1) {
            if (**(u16 **)(temp_17 + 0xA64) & 0x100) {
                return 0;
            }
            goto block_24;
        }
        temp_16_2 = (s32)(func_0023e130(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF);
        temp_2 = (s32)func_0023e140(*(u8 **)(temp_17 + 0xA64));
        var_8 = 0;
loop_23:
        if ((var_8 & 0xFFFF) >= (temp_16_2 & 0xFFFF)) {
            goto block_24;
        }
        temp_3 = *(u16 *)(temp_2 + ((var_8 & 0xFFFF) * 2));
        if ((temp_3 != 0x1F8) && (temp_3 != 0x1F7) && (temp_3 != 0x1F6)) {
            var_8 = (var_8 + 1) & 0xFFFF;
            goto loop_23;
        }
        return 0;
    }
block_24:
    return (func_00242800(*(u8 **)(temp_17 + 0xA64), (s16)index) & 0x07000000) == 0;
}
