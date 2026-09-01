/* object 700/736 normalized_diff=461 differing offsets=10,14,18,22,26,30,34,38,42,46,50,58,62-... classification=register-coloring and repeated-global-reload residual; ruled-out=frame/signature (16B, a0 only), table-base temporary, pointer declaration order, scalar/array global forms, explicit flag-pointer aliases, opt_common_subs off */
void func_0029ecb0(u8 *arg0)
{
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern u16 D_008C024E[];
    extern u16 D_008C027A[];
    extern u8 D_007485D0[];
    u8 *state;
    u8 *table;
    u8 *entry;
    s32 value;

    state = *(u8 **)(arg0 + 0x38);
    *(s32 *)(state + 0x28) = *(s32 *)(state + 0x1C);
    *(s32 *)(state + 0x2C) = *(s32 *)(state + 0x20);
    *(s32 *)(state + 0x30) = *(s32 *)(state + 0x24);
    if (D_008C027A[0] & 0x4000) {
        table = D_007485D0;
        do {
            value = *(s32 *)(state + 0x20) + 1;
            *(s32 *)(state + 0x20) = value;
            if (value >= 6) {
                if (D_008C024E[0] & 0x4000)
                    *(s32 *)(state + 0x20) = 0;
                else
                    *(s32 *)(state + 0x20) = *(s32 *)(state + 0x2C);
            }
            entry = table + *(s32 *)(state + 0x20) * 0x28;
            entry += *(s32 *)(state + 0x1C) * 2;
        } while (*(s16 *)entry < 0);
    }
    if (D_008C027A[0] & 0x1000) {
        table = D_007485D0;
        do {
            value = *(s32 *)(state + 0x20) - 1;
            *(s32 *)(state + 0x20) = value;
            if (value < 0) {
                if (D_008C024E[0] & 0x1000)
                    *(s32 *)(state + 0x20) = 5;
                else
                    *(s32 *)(state + 0x20) = *(s32 *)(state + 0x2C);
            }
            entry = table + *(s32 *)(state + 0x20) * 0x28;
            entry += *(s32 *)(state + 0x1C) * 2;
        } while (*(s16 *)entry < 0);
    }
    if (D_008C027A[0] & 0x2000) {
        table = D_007485D0;
        do {
            value = *(s32 *)(state + 0x1C) + 1;
            *(s32 *)(state + 0x1C) = value;
            if (value >= 20) {
                if (D_008C024E[0] & 0x2000)
                    *(s32 *)(state + 0x1C) = 0;
                else
                    *(s32 *)(state + 0x1C) = *(s32 *)(state + 0x28);
            }
            entry = table + *(s32 *)(state + 0x20) * 0x28;
            entry += *(s32 *)(state + 0x1C) * 2;
        } while (*(s16 *)entry < 0);
    }
    if (D_008C027A[0] & 0x8000) {
        table = D_007485D0;
        do {
            value = *(s32 *)(state + 0x1C) - 1;
            *(s32 *)(state + 0x1C) = value;
            if (value < 0) {
                if (D_008C024E[0] & 0x8000)
                    *(s32 *)(state + 0x1C) = 19;
                else
                    *(s32 *)(state + 0x1C) = *(s32 *)(state + 0x28);
            }
            entry = table + *(s32 *)(state + 0x20) * 0x28;
            entry += *(s32 *)(state + 0x1C) * 2;
        } while (*(s16 *)entry < 0);
    }
    value = *(s32 *)(state + 0x1C) % 5 + *(s32 *)(state + 0x20) * 5;
    *(s32 *)(state + 0x24) = value;
    value += (*(s32 *)(state + 0x1C) / 5) * 30;
    *(s32 *)(state + 0x24) = value;
    if (value != *(s32 *)(state + 0x30)) {
        *(s32 *)(state + 0x34) = *(s32 *)(state + 0x28);
        *(s32 *)(state + 0x38) = *(s32 *)(state + 0x2C);
        *(s32 *)(state + 0x3C) = *(s32 *)(state + 0x30);
        func_0045af60(0, 0, 0, 0);
    }
}
