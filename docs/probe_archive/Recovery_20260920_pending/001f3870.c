u8 *func_001f3870(u8 *arg0, s8 arg1)
{
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)func_00194470(0x701, 8);
    *(void **)(temp_2 + 0x68) = (void *)func_001f37b0;
    *(void **)(temp_2 + 0x6C) = (void *)func_001f37d0;
    *(void **)(temp_2 + 0x70) = (void *)func_001f3850;
    temp_3 = *(u8 **)(temp_2 + 0x78);
    *(u8 **)(temp_3 + 0) = arg0;
    *(s8 *)(temp_3 + 4) = arg1;
    return temp_2;
}