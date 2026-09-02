/* Best pre-replacement candidate for func_00143cf0.
 * Measured object 700B/window 672B; 120 differing words.
 * Retail register list derived: s3=arg0 then loop index, s2=arg1 then packet cursor,
 * s7=arg2, s5=arg3, fp=arg4, s1=arg6 then var17, s6=arg6>>4,
 * s0=arg7>>4, s4=var20, with spAC on stack. */
void func_00143cf0(u32 arg0, u8* arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0, s32 arg_sp8, s32 arg_sp10) {
    s32 spAC;
    s32 temp_16;
    s32 temp_22;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_4;
    s32 var_18;
    s32 var_19;
    u8* var_20;
    s32 var_3;
    s64 var_17;
    s32 var_6;

    temp_22 = arg6 >> 4;
    temp_16 = arg7 >> 4;
    spAC = arg5;
    func_00143f90((u64*)arg1, 0, 0U, 0, 1, 0, 3);
    func_00144000((u32*)(arg1 + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
    temp_2 = arg6 + 0x3F;
    var_3 = temp_2 >> 6;
    if (temp_2 < 0) {
        var_3 = (s32) (temp_2 + 0x3F) >> 6;
    }
    var_6 = (s64)(var_3 << 6);
    if ((s32)var_6 < 0) {
        var_6 = ((s32)var_6 + 0x3F) >> 6;
    }
    func_00144060((u32*)(arg1 + 0x20), arg0, (s32) var_6, 0);
    func_00144140((u32*)(arg1 + 0x30), 0x10, temp_16 * 0x10);
    var_20 = arg1 + 0x40;
    temp_4 = arg_sp10 >> 4;
    var_17 = arg2 + ((arg_sp0 >> 4) * (arg3 * (temp_16 + temp_4))) + (arg3 * (arg_sp8 >> 4));
    var_19 = 0;
    temp_2_2 = temp_16 << 0xA;
    var_18 = temp_2_2 >> 4;
    if (temp_16 & 0x200000) {
        var_18 = (s32) (temp_2_2 + 0xF) >> 4;
    }
loop_8:
    if (var_19 < temp_22) {
        func_00143f90((u64*)var_20, 0, 0U, 0, 1, 0, 4);
        func_00144000((u32*)(var_20 + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
        func_001440d0((u32*)(var_20 + 0x20), 0, arg4 + (var_19 * 0x10), spAC);
        func_001441a0((u32*)(var_20 + 0x30), 0);
        func_00144000((u32*)(var_20 + 0x40), 0, 0, 2, 0, 0, var_19 == (temp_22 - 1), var_18);
        func_00143f90((u64*)(var_20 + 0x50), 0, (u64) (var_17 << 0x24) >> 0x24, 0, 3, 0, var_18);
        var_20 += 0x60;
        var_17 = var_17 + (arg3 * temp_16) + (arg3 * temp_4);
        var_19 += 1;
        goto loop_8;
    }
    func_00143f90((u64*)var_20, 0, 0U, 0, 7, 0, 0);
}
