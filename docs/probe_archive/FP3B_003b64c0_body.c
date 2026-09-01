/* func_003b64c0 best current plain-C attempt: object 124B, window 128B, normalized_diff 90. */
void func_003b64c0(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *var_11;
    s32 temp_8;
    u8 *temp_10;
    u8 *temp_9;
    u8 *temp_7;
    s32 count;
    f32 temp_f0;
    var_11 = *(u8 **)arg0;
    temp_8 = *(s32 *)(arg0 + 4);
    temp_10 = arg2 + 0x90;
    temp_9 = arg2 + 0x98;
    if (arg1 <= 0) goto done_003b64c0;
        count = 0;
        do {
            temp_f0 = *(f32 *)(arg2 + 0x90);
            temp_7 = var_11 + temp_8;
            *(f32 *)(var_11 + 0) = temp_f0;
            *(f32 *)(var_11 + 4) = *(f32 *)(temp_9 + 4);
            *(f32 *)(temp_7 + 0) = *(f32 *)(arg2 + 0x98);
            *(f32 *)(temp_7 + 4) = *(f32 *)(temp_9 + 4);
            temp_7 += temp_8;
            *(f32 *)(temp_7 + 0) = *(f32 *)(arg2 + 0x98);
            *(f32 *)(temp_7 + 4) = *(f32 *)(temp_10 + 4);
            temp_7 += temp_8;
            *(f32 *)(temp_7 + 0) = *(f32 *)(arg2 + 0x90);
            *(f32 *)(temp_7 + 4) = *(f32 *)(temp_10 + 4);
            var_11 = temp_7 + temp_8;
            count += 1;
        } while (count < arg1);
done_003b64c0:
    ;
}
