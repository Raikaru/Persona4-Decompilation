/* object 160B, retail window 176B, normalized_diff 64; schedule-on prologue/call ordering solved, repeated pointer-load and tail residuals remained. */
u8 *func_003d2240(u8 *arg0, s32 **arg1, s32 arg2, s32 arg3) {
    extern void func_003f3eb0(s32, s32);
    extern u8 *func_003f44c0(s32, s32);
    u8 *var_2;

    func_003f3eb0(0, 0x80);
    *arg1 = (s32 *)func_003f44c0(arg2 + 0x18, 0);
    (*arg1)[1] = 0;
    (*arg1)[0] = 0;
    (*arg1)[3] = *(s32 *)(arg0 + 8);
    (*arg1)[2] = arg2;
    (*arg1)[4] = 0;
    (*arg1)[5] = arg3;
    var_2 = (u8 *)*arg1;
    if (var_2 == NULL) {
        var_2 = NULL;
    }
    return var_2;
}
