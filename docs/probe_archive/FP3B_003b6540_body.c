/* Current-TU remeasure: object 140B/window 144B, normalized_diff 96; differing word offsets 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132. Archived nd31/object144 is stale under current declarations; plain-C body below is retained as historical best attempt. */
void func_003b6540(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *var_13;
    s32 temp_9;
    u8 *temp_4;
    u8 *temp_6;
    u8 *temp_7;
    u8 *src_0;
    u8 *src_1;
    u8 *src_2;
    u8 *src_3;
    s32 var_14;
    s32 positive;

    var_13 = *(u8 **)(arg0 + 0);
    positive = 0 < arg1;
    temp_9 = *(s32 *)(arg0 + 4);
    src_0 = (u8 *)(arg2 + 0x90);
    src_1 = (u8 *)(arg2 + 0x98);
    src_2 = (u8 *)(arg2 + 0xA0);
    src_3 = (u8 *)(arg2 + 0xA8);
    if (positive) {
        var_14 = 0;
        do {
            temp_7 = var_13 + temp_9;
            temp_6 = temp_7 + temp_9;
            var_14 += 1;
            temp_4 = temp_6 + temp_9;
            *(f32 *)(var_13 + 0) = *(f32 *)(src_0 + 0);
            *(f32 *)(var_13 + 4) = *(f32 *)(src_0 + 4);
            var_13 = temp_4 + temp_9;
            *(f32 *)(temp_7 + 0) = *(f32 *)(src_1 + 0);
            *(f32 *)(temp_7 + 4) = *(f32 *)(src_1 + 4);
            *(f32 *)(temp_6 + 0) = *(f32 *)(src_2 + 0);
            *(f32 *)(temp_6 + 4) = *(f32 *)(src_2 + 4);
            *(f32 *)(temp_4 + 0) = *(f32 *)(src_3 + 0);
            *(f32 *)(temp_4 + 4) = *(f32 *)(src_3 + 4);
        } while (var_14 < arg1);
    }
}
