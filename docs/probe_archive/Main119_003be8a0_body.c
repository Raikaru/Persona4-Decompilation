/* Main 2026-09-03 (cw3.0.1b119 unit): object 104B / window 112B, 5 real
   differing words. The movz ternary and both calls are exact under b119; the
   residual is the `lw $v0,OFF($a2)` that retail schedules ABOVE `sd $ra`,
   which no cached MWCC build does for this source (docs/matching.md, "The
   `lw` before `sd $ra` prologue"). Not installed. */
s32 func_003be8a0(s32 arg0, s32 arg1, u8 *arg2) {
    if (func_003df240(arg0, (s32)(*(u8 **)(arg2 + 0x6C) + 0x2C), 4) == 0) {
        return 0;
    }
    return func_003df240(arg0, (s32)(*(u8 **)(arg2 + 0x6C) + 0x30), 4) ? arg0 : 0;
}
