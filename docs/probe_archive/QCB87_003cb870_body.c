// FUN_003CB870 NONMATCHING
s32 func_003cb870(s32 arg0, s32 arg1, u8 *arg2) {
    u8 *temp;
    s32 result;

    temp = func_003c9c20((u32)arg2);
    result = func_003c5d10(arg0, temp, temp + 0x10);
    *(s32 *)(arg2 + 0x78) = result;
    result = *(s32 *)(arg2 + 0x78);
    if (result == 0)
        arg0 = 0;
    return arg0;
}

