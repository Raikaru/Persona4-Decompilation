// FUN_00232C70 NONMATCHING
u32 func_00232c70(u8 *arg0, s32 arg1)
{
    u32 value;
    s32 temp_3;
    u8 flag;
    if (((s32)(arg1 & 0xFFFF) < 0) || ((arg1 & 0xFFFF) >= 5))
        func_0046d730(D_00635938, 0x313);
    if ((*(u16 *)arg0 & 4) != 0) {
        value = (u32)func_00232b40(arg0, arg1);
    } else {
        if (*(u16 *)(arg0 + 2) >= 0xB)
            func_0046d730(D_00635938, 0x31A);
        value = (u32)func_00109BF0((u8 *)((u32)*(u16 *)(arg0 + 2)), arg1);
    }
    flag = (u8)((*(u32 *)(arg0 + 0xC) & 0x80) != 0);
    if (flag != 0)
        value >>= 1;
    temp_3 = value & 0xFF;
    if (temp_3 == 0)
        return 1;
    if (temp_3 >= 0x64)
        return 0x63;
    return value;
}
