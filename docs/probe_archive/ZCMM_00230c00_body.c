s32 func_00230c00(s32 arg0, s32 arg1, void *arg2)
{
    u8 sp40[0x100];
    s32 temp;
    s8 c;
    if (func_0047d0e0() == 0)
        return func_0047d0b0(arg0, arg1, arg2);
    func_0047d0b0(arg0, arg1, sp40);
    temp = func_00442948(sp40);
    *(s8 *)(temp + 0x3D) = 0x70;
    *(s8 *)(temp + 0x3E) = 0x61;
    *(s8 *)(temp + 0x3F) = 0x63;
    do {
        c = *(s8 *)(temp + 0x40);
        if (c == 0x5C || c == 0x2F)
            break;
        temp--;
    } while (1);
    if ((arg0 & 0xFFFF) == 2)
        func_00442088(arg2, D_006357C8, D_00635678, temp + 0x40);
    else
        func_00442088(arg2, D_006357C8, (char *)&iGpffffb3ac - 0x5A10, temp + 0x40);
    return 1;
}
