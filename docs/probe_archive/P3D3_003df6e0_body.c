/* object 280B / window 256B / normalized_diff 225 / differing offsets broad beginning at 4 (first [4,5,6,7,8,10,11,12,13,14,15,16,17,18,19,20]) / classification oversized automatic archive; candidate used s32 arg0 pointer and s32 arg1, block-scope D_008873F0(s32,s32,s32) function-pointer table, func_003df4d0(s32*) and variadic func_003df590(s64,...), signed divide-by-four correction; direct callback/global forms and saved-register declaration order were not further probed after oversized result; ruled out movz/movn, COP1 accumulator chain, standalone MMI, framed tail jump, custom COP1 sqrt, rd-form mult floor. */
s32 func_003df6e0(u8 *arg0, s32 arg1) {
    extern s32 (*D_008873F0[])(s32 arg0, s32 arg1, s32 arg2);
    extern s32 *func_003df4d0(s32 *arg0);
    extern s32 func_003df590(s64 arg0, ...);
    s32 flag;
    s32 error;
    s32 value;
    s32 rounded;
    s32 result;

    value = *(s32 *)(arg0 + 0x8);
    if (*(s32 *)(arg0 + 0x4) < value) {
        rounded = value >> 2;
        if (value < 0) {
            rounded = (value + 3) >> 2;
        }
        result = (*D_008873F0)(
            *(s32 *)arg0,
            *(s32 *)(arg0 + 0xC) * (value + rounded),
            arg1);
        if (result != 0) {
            *(s32 *)arg0 = result;
            value = *(s32 *)(arg0 + 0x8);
            rounded = value >> 2;
            if (value < 0) {
                rounded = (value + 3) >> 2;
            }
            *(s32 *)(arg0 + 0x8) = value + rounded;
        } else {
            flag = 1;
            value = *(s32 *)(arg0 + 0x8);
            rounded = value >> 2;
            if (value < 0) {
                rounded = (value + 3) >> 2;
            }
            error = func_003df590(
                0x80000013, *(s32 *)(arg0 + 0xC) * (value + rounded));
            func_003df4d0(&flag);
            return 0;
        }
    }
    value = *(s32 *)(arg0 + 0x4);
    *(s32 *)(arg0 + 0x4) = value + 1;
    return *(s32 *)arg0 + value * *(s32 *)(arg0 + 0xC);
}
