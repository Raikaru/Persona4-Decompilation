/* object 280B / window 272B / normalized_diff 174; differing offsets: 0x00-0x1c, 0x20-0x24, 0x28-0x34, 0x38-0x40, 0x44-0x4c, 0x50-0x58, 0x5c-0x64, 0x68-0x70, 0x74-0x7c, 0x80-0x88, 0x8c-0x94, 0x98-0xa0, 0xa4-0xac, 0xb0-0xb8, 0xbc-0xc4, 0xc8-0xd0, 0xd4-0xdc, 0xe0-0xe8, 0xec-0xf4, 0xf8-0x100, 0x104-0x10c; declaration audit: func_0014a230(s32,s32), func_0014a2a0(s32,s32), func_00454570(void*) agree with verified definitions; func_00442830, func_00442088, func_00442428 remain INCLUDE_ASM without verified ground truth. */
s32 func_00144b80(s32 arg0, s32 arg1)
{
    s32 result;
    s32 value;
    s32 compare;
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
    if (value == (compare = result + 0)) {
        goto set_result;
    }
    value = func_0014a2a0(arg0 & 0xFFFF, arg1 & 0xFFFF);
    if (value != (compare = result + 0)) {
        goto done;
    }
set_result:
    result = 1;
done:
    return result;
}
