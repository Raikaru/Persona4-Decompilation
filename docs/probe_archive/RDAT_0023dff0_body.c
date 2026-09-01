/* object 288 / window 320 / normalized_diff 185 / differing offsets 45,52-211,216-224,232,240-288 / undersized; classification loop-register rotation floor (retail counter=$a0, index=$v1, value=$t0; candidate counter/index/value allocation differs); ruled-outs: u16/s32 return, while/for/do-while forms, raw-value and range switch forms, j-limit ordering, value local. */
// FUN_0023DFF0
u16 func_0023dff0(u8 *arg0)
{
    u16 count;
    u8 *table;
    u16 i;
    u16 j;
    u16 value;
    u16 arr[16];

    count = func_0023e130(arg0) & 0xFFFF;
    table = func_0023e140(arg0);
    i = 0;
    j = 0;
    while (j < count && i < 0x10) {
        value = *(u16 *)(table + j * 2);
        switch (value) {
        case 0xC0:
        case 0xC1:
        case 0xC2:
        case 0xC3:
        case 0xC4:
        case 0xC5:
            arr[i] = value;
            i = (u16)(i + 1);
            break;
        }
        j = (u16)(j + 1);
    }
    if (i == 0) {
        return 0;
    }
    if (i == 0) {
        func_0046d730(D_00635938, 0x17);
    }
    return arr[func_003b7060() % i];
}
