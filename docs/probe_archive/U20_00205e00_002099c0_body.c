/* lane U20 drafts (2026-09-03, lane killed): func_00205e00 492/496 nd279; func_002099c0 508/512 nd90. Unfinished. */
void func_00205e00(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *temp_17;
    u8 var_16;
    f32 temp_f21;

    extern void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1, u8 arg5, u8 arg6, u8 arg7, s32 arg8);
    extern s32 func_002791f0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

    temp_17 = (u8 *)func_00452560(*(s32 *)(arg0 + 0x5B0));
    if (arg3 != 0) {
        var_16 = 0x1B;
    } else {
        var_16 = 0xFF;
    }


    temp_f21 = 8.0f + fparg1;
    func_00201650(temp_17, 9, 0x3C, 48.0f + fparg0, temp_f21, var_16, var_16, var_16, arg2);
    func_00201650(temp_17, 9, 0x3C, 270.0f + fparg0, temp_f21, var_16, var_16, var_16, arg2);
    func_00201650(temp_17, 9, arg1 + 0x3F, 71.0f + fparg0, fparg1, var_16, var_16, var_16, arg2);
    if (arg4 != 0) {
        func_00272c60(0x40);
        func_002791f0(10.0f + ((2.0f + (42.0f + fparg0)) - 1.0f), 36.0f + fparg1, 0.0f,
                      (arg2 & 0xFF) | ~0xFF, 1, 0, 0, *(s32 *)(temp_17 + 0x98), arg1);
        func_00272c80(0x40);
    }
}
void func_002099c0(u8 *arg0, u8 *arg1, f32 *arg2)
{
    u8 *temp_2;
    void (**base)(u32, u32);

    temp_2 = (u8 *)func_00452560(*(s32 *)(arg1 + 0x5B0));
    func_002012d0(temp_2, arg2[0], arg2[1]);
    func_00201650(temp_2, 9, 0x1F, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    base = D_00887300;
    base[0](6, 1);
    func_002019e0(temp_2, 120.0f);
    func_00201650(temp_2, 9, 0x35, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    base[0](6, 0);
    func_002019e0(temp_2, 0.0f);
    if (func_001eb860() != 0) {
        func_00201650(temp_2, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp_2, 9, 0x1C, 100.0f, (f32)0x19B);
        func_00201650(temp_2, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        func_00201410(temp_2, 9, 0x19, 119.0f, (f32)0x19B);
    }
}
