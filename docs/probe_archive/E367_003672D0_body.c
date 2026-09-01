/* object size 340B / retail window 336B / normalized_diff 102 / differing offsets 136,164,196,197,198,199,200,201,204,205,206,207,209,210,213,214 / declarations corrected: func_0010a900, func_00104f10, func_00109440, func_00105290, func_00109220, func_00109280; also verified func_00109390 and func_00109430. */
void func_003672d0(u8 *arg0, s16 arg1)
{
    s32 temp_17_2;
    s32 temp_18;
    s32 temp_19;
    s32 temp_20;
    s32 temp_2;
    s32 var_3;
    s64 temp_17;
    s64 var_18;
    u8 *temp_16;

    temp_16 = (u8 *)(arg0 + 4);
    temp_20 = func_00105290(arg1) & 0xFFFF;
    temp_18 = arg1 & 0xFFFF;
    temp_19 = func_0010a900(temp_18);
    *(s16 *)temp_16 = arg1;
    *(s32 *)(temp_16 + 0x10) = func_00109220(temp_20);
    *(s8 *)(temp_16 + 0x14) = func_00109280(temp_20);
    *(s8 *)(temp_16 + 0x15) = func_00109390(temp_19);
    if (((s64)((s64)arg1 << 0x30) >> 0x30) == 1) {
        *(s32 *)(temp_16 + 0xC) = func_00105a50(arg1);
        var_18 = 0;
loop_3:
        temp_17 = (s64)(var_18 << 0x30) >> 0x30;
        if (temp_17 < 5) {
            *(s16 *)(temp_16 + (temp_17 * 2) + 2) = func_00104f10(var_18);
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
            goto loop_3;
        }
        return;
    }
    temp_2 = func_0010a900(temp_18);
    temp_17_2 = func_00109440(temp_2);
    var_3 = temp_17_2 - func_00109430(temp_2);
    if (var_3 < 0) {
        var_3 = 0;
    }
    *(s32 *)(temp_16 + 0xC) = var_3;
}
