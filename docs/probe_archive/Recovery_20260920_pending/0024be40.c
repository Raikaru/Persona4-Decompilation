s32 func_0024be40(void)
{
    extern u32 func_00452560(void *task);
    extern u8 *func_00452380(s8 *name);
    extern u8 func_001060c0(void);
    extern s64 func_00110960(s32 date, u32 period);
    extern void func_001104d0(s32 date, s32 *month, s32 *day);
    s32 month;
    extern s32 func_00246e10(s32 arg0);
    s32 sum;
    u8* work;
    s32 j;
    f32 random_f;
    s32 flag;
    struct CmmWeights { s8 value[6]; } *found;
    s32 i;
    s32 day;
    f32 product;
    s32 index;
    u8* base;
    s32 sum2;
    f32 sum_f;

    flag = 0;
    index = 0;
    func_001104d0(func_001060b0(), &month, &day);
    base = (u8*)func_00246e10((u16)month);
    if ((func_001060c0() & 0xFF) == 5) {
        index = 2;
    }
    if ((s8)func_00110960(func_001060b0(), func_001060c0() & 0xFF) == 1) {
        flag = 1;
    }
    index = index + flag;
    sum = 0;
    j = 0;
    {
        found = (struct CmmWeights *)(base + index * 6);
        while (j < 6) {
            if ((j != 0) || (func_00106330(2703) != 0)) {
                sum += found->value[j];
            }
            j++;
        }
        random_f = (f32)(u32)func_003b7060();
        random_f /= 2147483648.0f;
        sum_f = (f32)(u32)sum;
        product = sum_f * random_f;
        sum = (u32)product;
        sum2 = 0;
        i = 0;
        while (i < 6) {
            if ((i != 0) || (func_00106330(2703) != 0)) {
                sum2 += found->value[i];
                if ((s32)sum < (s32)sum2) {
                    sum = i;
                    break;
                }
            }
            i++;
        }
    }
    work = (u8*)(u32)func_00452560((void*)(u32)func_00452380((s8*)D_00635A78));
    if (work == 0) {
        func_0046d730(D_006359F0, 1041);
    }
    *(s32*)(work + 32) = sum;
    return sum;
}
