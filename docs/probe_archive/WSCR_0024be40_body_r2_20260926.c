// FUN_0024BE40
s32 func_0024be40(void)
{
    extern s32 func_00246e10(s32 arg0);
    s32 sum;
    s32 i;
    s8 *row;
    u8 *work;
    f32 r;
    s32 month;
    s32 j;
    s32 flag;
    s8 *base;
    s32 acc;
    s32 day;
    s32 index;

    flag = 0;
    index = 0;
    func_001104d0(func_001060b0(), &month, &day);
    base = (s8 *)func_00246e10((u16)month);
    if ((func_001060c0() & 0xFF) == 5) {
        index = 2;
    }
    if ((s8)func_00110960(func_001060b0(), func_001060c0() & 0xFF) == 1) {
        flag = 1;
    }
    index += flag;
    sum = 0;
    row = base + index * 6;
    for (j = 0; j < 6; j++) {
        if (j != 0 || datGetFlag(2703) != 0) {
            sum += row[j];
        }
    }
    r = (f32)(u32)RpRandom() / 2147483648.0f;
    sum = (u32)((f32)(u32)sum * r);
    acc = 0;
    for (i = 0; i < 6; i++) {
        if (i != 0 || datGetFlag(2703) != 0) {
            acc += row[i];
            if (sum < acc) {
                sum = i;
                break;
            }
        }
    }
    work = (u8 *)func_00452560((void *)func_00452380((s8 *)D_00635A78));
    if (work == 0) {
        func_0046d730(D_006359F0, 1041);
    }
    *(s32 *)(work + 32) = sum;
    return sum;
}
