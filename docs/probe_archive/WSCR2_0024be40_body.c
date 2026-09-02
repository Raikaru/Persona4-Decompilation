/* object 672B/window 672B (exact size), normalized_diff 12; probe WSCR2. Moved locals to order: sum, found, index, j, base, floats, sum2, i, work. Residual worsened: found still in $s0, second-loop i/sum2 swapped. */
// FUN_0024BE40
s32 func_0024be40(void)
{
    extern void* func_00452560();
    s32 month;
    extern s32 func_00246e10(s32 arg0);
    s32 day;
    s32 sum;
    u8* found;
    s32 index;
    s32 j;
    u8* base;
    f32 random_f;
    f32 sum_f;
    f32 product;
    s32 sum2;
    s32 i;
    u8* work;

    found = 0;
    index = 0;
    func_001104d0(func_001060b0(), &month, &day);
    base = (u8*)func_00246e10((u16)month);
    if ((func_001060c0() & 0xFF) == 5) {
        index = 2;
    }
    if ((s8)func_00110960(func_001060b0(), func_001060c0() & 0xFF) == 1) {
        found = (u8*)1;
    }
    index = index + (s32)found;
    sum = 0;
    j = 0;
    {
        found = base + index * 6;
        while (j < 6) {
            if ((j != 0) || (func_00106330(2703) != 0)) {
                sum += *(s8*)(found + j);
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
                sum2 += *(s8*)(found + i);
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
