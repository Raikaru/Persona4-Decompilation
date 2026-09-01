s32 func_00144b80(s32 arg0, s32 arg1)
{
    s32 result;
    s32 value;
    u8 spC0[0x80];
    u8 sp40[0x80];

    func_00442830(spC0, (const char *)D_005EF7C0);
    func_00442088(sp40, (const char *)&iGpffff9db8, arg0);
    func_00442428(spC0, sp40);
    func_00442088(sp40, (const char *)&iGpffff9dc0, arg1);
    func_00442428(spC0, sp40);
    func_00442428(spC0, (const char *)&iGpffff9dc8);
    if (func_00454570(spC0) == 0) {
        return 0;
    }
    result = 1;
    value = func_0014a230(arg0 & 0xFFFF, arg1 & 0xFFFF);
    if (value == result) {
        goto set_result;
    }
    value = func_0014a2a0(arg0 & 0xFFFF, arg1 & 0xFFFF);
    if (value != result) {
        goto done;
    }
set_result:
    result = 1;
done:
    return result;
}
