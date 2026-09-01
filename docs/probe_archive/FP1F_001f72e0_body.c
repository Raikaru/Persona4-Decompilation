/* Best candidate for func_001f72e0: object 212B, window 224B, normalized_diff 19. */
void func_001f72e0(void)
{
    u8 *temp_3;
    u8 *temp_3_7;
    u8 *temp_3_4;
    u8 *temp_3_8;
    u8 *temp_3_9;
    s32 empty;
    s32 temp_3_2;
    s32 temp_3_5;
    s32 temp_6;
    s32 index_8;
    s32 var_8;

    temp_3 = iGpffffb3ac;
    temp_3_7 = temp_3 + 0xACA;
    temp_3_2 = *(s8 *)temp_3_7;
    if (temp_3_2 >= 0) {
        temp_3_2 = temp_3_2 + 1;
        *(s8 *)temp_3_7 = (s8)temp_3_2;
        if ((s8)temp_3_2 >= 3) {
            *(s8 *)(iGpffffb3ac + 0xACA) = -1;
        }
    }
    var_8 = 0;
    empty = -1;
    goto loop_test_8;
loop_8:
    temp_3_4 = iGpffffb3ac;
    index_8 = var_8 & 0xFFFF;
    temp_6 = index_8 * 6;
    temp_3_8 = temp_3_4 + temp_6;
    temp_3_9 = temp_3_8 + 0xAD0;
    temp_3_5 = *(s8 *)(temp_3_8 + 0xAD0);
    if (temp_3_5 >= 0) {
        temp_3_5 = temp_3_5 + 1;
        *(s8 *)temp_3_9 = (s8)temp_3_5;
        if ((s8)temp_3_5 >= 3) {
            *(s16 *)(iGpffffb3ac + temp_6 + 0xACC) = empty;
            *(s16 *)(iGpffffb3ac + temp_6 + 0xACE) = empty;
            *(s8 *)(iGpffffb3ac + temp_6 + 0xAD0) = empty;
        }
    }
    var_8 = (var_8 + 1) & 0xFFFF;
loop_test_8:
    if ((var_8 & 0xFFFF) < 0x10) {
        goto loop_8;
    }
}
