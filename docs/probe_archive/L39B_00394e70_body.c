/* Rejected reconstruction archive: object 324B / window 352B / normalized_diff 137. */
s32 func_00394e70(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 temp_3;
    u8 *temp_20;
    u8 *temp_2;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    u8 sp80[0x40];
    u8 sp60[0x20];

    temp_3 = *(s32 *)(arg1 + 0x18);
    if (temp_3 == 5) goto case_5;
    if (temp_3 == 3) goto case_3;
    if (temp_3 == 1) goto case_1;
    return arg0;
case_1:
    temp_20 = *(u8 **)(arg0 + 0x18);
    func_003e0960(sp80, func_003e9700(*(s32 *)(arg0 + 4)));
    func_003e42e0(sp60, (void *)arg1, 2, sp80);
    if (*(s32 *)(temp_20 + 0x18) < 2) goto case_1_low;
    func_003941e0(temp_20, (void *)(arg0 + 0x4C), sp60, (void *)arg1, (void *)arg2, (void *)arg3);
    goto retarg;
case_1_low:
    func_00392bf0(temp_20, sp60, (void *)arg1, (void *)arg2, (void *)arg3);
    goto retarg;
case_3:
    func_00394c70((void *)arg0, (void *)arg1, (void *)arg1, (void *)arg2, (void *)arg3);
    goto retarg;
case_5:
    temp_2 = (u8 *)func_003bfae0(*(s32 *)arg1);
    spC0 = *(f32 *)(temp_2 + 0);
    spC4 = *(f32 *)(temp_2 + 4);
    spC8 = *(f32 *)(temp_2 + 8);
    spCC = *(f32 *)(temp_2 + 0xC);
    func_00394c70((void *)arg0, &spC0, (void *)arg1, (void *)arg2, (void *)arg3);
retarg:
    return arg0;
}
