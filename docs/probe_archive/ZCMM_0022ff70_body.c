s32 func_0022ff70(u8 *arg0)
{
    s32 temp;
    if ((*(s32 *)(DAT_0076449c - 0x4C54) & 0x200000) == 0)
        return 0;
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1)
        return 0;
    temp = func_001d7f10(arg0, 0, *(u16 *)(arg0 + 0x6E), 0);
    temp &= 0xFFFF;
    if ((temp != 2) && (temp != 1))
        return 0;
    return 1;
}
