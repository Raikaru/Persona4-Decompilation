/* func_003d30b0 archived: best body object_size 104B, retail window 112B, normalized_diff 66 after schedule-on and load-order probes. Residual is call/branch and store ordering; ruled out direct field forms, temp-before-call, switch form, and schedule on. */
void func_003d30b0(u8 *arg0) {
    u8 *temp_16;
    extern s32 func_003d2c40(void);

    if (func_003d2c40() == 0) {
        return;
    }
    temp_16 = *(u8 **)(arg0 + 0x14);
    *(u8 **)(temp_16 + 0x18) = D_0070C260;
    *(s32 *)(temp_16 + 0x1C) = 0x20;
    *(s32 *)(temp_16 + 0x14) = 0x114;
    *(s32 *)(temp_16 + 0) = 0;
    *(s32 *)(temp_16 + 4) = 0;
    *(s32 *)(temp_16 + 8) = 0;
    *(s32 *)(temp_16 + 0xC) = 0;
    *(s32 *)(temp_16 + 0x10) = 0;
    *(s32 *)(temp_16 + 0x328) = 0x34F9;
}
