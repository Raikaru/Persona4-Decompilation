/* func_003c21e0 archive: object 156B, window 176B, normalized_diff 29. */
u8 *func_003c21e0(u8 *arg0, s32 (*arg1)(s32, s32), s32 arg2) {
    s32 positive;
    s32 var_18;
    s32 var_17;
    s32 temp_16;

    temp_16 = *(s32 *)(arg0 + 0x24);
    var_18 = 0;
    positive = temp_16 > 0;
    if (positive != 0) {
        var_17 = 0;
        goto start;
    }
    goto no_items;
start:
loop:
    if (arg1(*(s32 *)((u8 *)*(u8 **)(arg0 + 0x20) + var_17), arg2) == 0)
        goto callback_done;
    var_18 += 1;
    if (var_18 < temp_16) {
        var_17 += 4;
        goto loop;
    }
    goto no_items;
callback_done:
    return arg0;
no_items:
    return arg0;
}
