/*
 * Safe floor: 644B / 656B, 84 differing words (relocation-masked).
 * Reconstructed against docs/ida_headstart/src/promoted/code1_0031.c:211-292.
 * Keeps IDA's separate branch-local table/entry pointers, priorities, and saved
 * mode. The mode*2 counter base stays separate from the mode*5 flag base;
 * the superseded archive incorrectly reused the latter for a counter write.
 * IDA and Ghidra agree on signed-byte mode; func_00110a60 uses its measured
 * s8(s32,s32) contract. No register annotations or artificial ABI changes.
 * Native smoke: 40960 cases cover both modes, fallback/date rows, signed scores,
 * first-winner ties, priority-100 flags, counters, calls, and untouched bytes.
 * Residuals include GPR allocation, address grouping, and the retail second
 * mode sign-extension. Production remains INCLUDE_ASM.
 */
#pragma push
#pragma opt_loop_invariants on
void func_00313d20(u8 *arg0, u8 month, u8 day, s8 mode)
{
    extern s8 func_00110a60(s32 month, s32 day);
    extern u8 D_00643D00[];
    s8 selected;
    u8 *work;
    s16 best;
    s32 saved_mode;
    s8 slot;

    work = *(u8 **)(arg0 + 0x38);
    best = -1;
    saved_mode = mode;
    slot = *(s8 *)(mode + work + 0x2D4);
    if (slot == -1) {
        u32 *fallback;
        s16 i;
        u32 *entry;
        s8 priority;
        fallback = (u32 *)D_00643D00 + 5 * func_00110a60(month, day);
        for (i = 0; i < 5; i++) {
            work[5 * saved_mode + i + 0x2C4] = 0;
            entry = fallback + i;
            if (*(s8 *)entry != 0) {
                priority = *((s8 *)entry + 1);
                if (best < priority) {
                    selected = i;
                    best = priority;
                }
            }
        }
        if (best != -1) *(selected + (5 * saved_mode + work) + 0x2C4) = 1;
    } else {
        u32 *date;
        u8 *count_base;
        s16 j;
        s16 k;
        s32 flag_offset;
        u8 *flag;
        u32 *entry;
        s8 priority;
        date = (u32 *)D_006432B0 + 7 * slot;
        count_base = 2 * mode + work;
        *(s16 *)(count_base + 0x2C0) = 0;
        for (j = 0; j < 3; j++) {
            if (*((s8 *)date + 2) != 0) ++*(s16 *)(count_base + 0x2C0);
        }
        k = 0;
        flag_offset = 5 * mode;
        while (k < 5) {
            flag = work + flag_offset + k + 0x2C4;
            *flag = 0;
            entry = date + k;
            if (*((s8 *)entry + 8) != 0) {
                ++*(s16 *)(count_base + 0x2C0);
                priority = *((s8 *)entry + 9);
                if (priority == 100) *flag = 1;
                else if (best < priority) {
                    selected = k;
                    best = priority;
                }
            }
            ++k;
        }
        if (best != -1) *(selected + (flag_offset + work) + 0x2C4) = 1;
    }
}
#pragma pop
