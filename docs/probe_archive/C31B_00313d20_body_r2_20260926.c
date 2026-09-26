// FUN_00313D20
#pragma push
#pragma opt_loop_invariants on
void func_00313d20(u8 *arg0, u8 month, u8 day, s8 mode)
{
    extern s64 func_00110a60(s32 month, s32 day);
    extern u8 D_00643D00[];
    u8 *work;
    s16 best;
    s8 selected;
    s16 m;
    s8 slot;
    u8 *entries;
    u8 *flags;
    u8 *entry;
    u8 *date;
    u8 *count;
    s16 k;
    s16 j;
    s8 priority;

    work = *(u8 **)(arg0 + 0x38);
    best = -1;
    m = mode;
    slot = ((s8 *)(work + 0x2D4))[m];
    if (slot == -1) {
        entries = D_00643D00 + (s8)func_00110a60(month, day) * 20;
        for (k = 0; k < 5; k++) {
            *(work + m * 5 + k + 0x2C4) = 0;
            entry = entries + k * 4;
            if (*(s8 *)entry != 0) {
                priority = *(s8 *)(entry + 1);
                if (best < priority) {
                    selected = k;
                    best = priority;
                }
            }
        }
        if (best != -1) {
            *(selected + (m * 5 + work) + 0x2C4) = 1;
        }
    } else {
        date = D_006432B0 + slot * 0x1C;
        *(s16 *)(work + m * 2 + 0x2C0) = 0;
        for (j = 0; j < 3; j++) {
            if (*(s8 *)(date + 2) != 0) {
                (*(s16 *)(work + m * 2 + 0x2C0))++;
            }
        }
        for (k = 0; k < 5; k++) {
            u8 *flag = work + mode * 5 + k + 0x2C4;

            *flag = 0;
            entry = date + k * 4;
            if (*(s8 *)(entry + 8) != 0) {
                (*(s16 *)(work + m * 2 + 0x2C0))++;
                priority = *(s8 *)(entry + 9);
                if (priority == 100) {
                    *flag = 1;
                } else if (best < priority) {
                    selected = k;
                    best = priority;
                }
            }
        }
        if (best != -1) {
            *(selected + (mode * 5 + work) + 0x2C4) = 1;
        }
    }
}
#pragma pop
