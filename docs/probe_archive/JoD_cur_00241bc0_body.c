/* JoD_cur probe: current source before per-use u16 narrowing / arg3/arg2 mask fix. fndiff 104 differing words, obj 536 vs window 532. */
// FUN_00241BC0
#pragma push
/* measured: opt_propagation off keeps arg2 raw in $s2 and the masked u16 in $s0, matching retail's saved-register list and the $a2 raw-mask lifetime. */
#pragma opt_propagation off
s32 func_00241bc0(arg0, arg1, arg2, arg3, arg4)
u8 *arg0;
u8 *arg1;
s32 arg2;
s32 arg3;
s32 arg4;
{
    u16 idx;
    u32 offset;
    u8 *base;
    u8 *entry;
    u32 flag1;
    s16 value;

    idx = (u16)arg2;
    if (idx >= 0x1B8) {
        func_0046d730(D_00635938, 0x1305);
    }
    flag1 = *(u32 *)(arg1 + 0xC);
    if (((u32)((flag1 & 0x100000) != 0) != 0)) {
        return 0;
    }
    if ((arg3 & 0xFFFF) != 1) {
        return 0;
    }
    if ((*(u16 *)arg1 & 8)) {
        return 0;
    }
    offset = (arg2 & 0xFFFF) * 0x28;
    base = iGpffffb3b8;
    entry = (u8 *)(offset + (u32)base);
    if (entry[0x11] == 0 && (entry[0x18] != 1 || ((*(u32 *)(entry + 0x1C) & 0x80000) == 0))) {
        return 0;
    }
    if (arg0 != 0 && idx < 0x1B8 && ((*(u8 *)(base + offset) & 2))) {
        if ((*(u16 *)arg0 & 4)) {
            value = (s16)*(u8 *)(((u8 *)PTDatCalcOffsetAdd((u32)(*(u16 *)(arg0 + 2) * 0x3C), (u32)iGpffffb3c4)) + 0x38);
        } else {
            value = (s16)func_00106a30((s16)(func_00106cd0(*(s16 *)(arg0 + 2), 0) & 0xFFFF));
        }
    } else {
        value = *(s8 *)(iGpffffb3cc + (arg2 & 0xFFFF) * 2);
    }
    if (value >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    if (((1 << (value + 1)) & 0xE0001) == 0) {
        goto one;
    }
    return 0;
one:
    return 1;
}
#pragma pop
