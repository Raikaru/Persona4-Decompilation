/* object 208B/window 208B, normalized_diff 123; differing word offsets 20-32,36-80,88-168,180,188-200; classification: exact frame/signature but loop pointer/register ordering and branch layout residual. Retail prologue is frame 0x10 with only $ra saved; first-touched args are arg0 descriptor, arg1 count, arg2 descriptor. Corrected block-scope func_003a4d50(u8 *,u8 *,s32) declaration and three-argument call. No movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or other confirmed floor. Source restored to INCLUDE_ASM.
void func_003b3f50(u8 *arg0, s32 arg1, u8 *arg2) {
    extern void func_003a4d50(u8 *arg0, u8 *arg1, s32 arg2);
    u8 *temp_13;
    u8 *var_14;
    f32 temp_f0;
    s32 temp_11;
    s32 temp_12;
    s32 var_24;
    u8 *temp_10;
    u8 *temp_4;
    u8 *temp_6;
    u8 *temp_7;
    u8 *temp_8;
    u8 *temp_9;
    u8 *var_15;

    temp_12 = *(s32 *)(arg0 + 4);
    temp_11 = *(s32 *)(arg2 + 0x48);
    var_14 = *(u8 **)(arg2 + 0x44);
    var_15 = *(u8 **)arg0;
    if (temp_11 != temp_12 * 4) {
        var_24 = 0;
        if (arg1 > 0) {
            do {
                temp_13 = var_14;
                temp_7 = var_15 + temp_12;
                temp_f0 = *(f32 *)(temp_13 + 0);
                temp_6 = temp_7 + temp_12;
                var_24 += 1;
                temp_10 = var_14 + 8;
                temp_9 = var_14 + 16;
                temp_8 = var_14 + 24;
                temp_4 = temp_6 + temp_12;
                var_14 += temp_11;
                *(f32 *)(var_15 + 0) = temp_f0;
                *(f32 *)(var_15 + 4) = *(f32 *)(temp_13 + 4);
                var_15 = temp_4 + temp_12;
                *(f32 *)(temp_7 + 0) = *(f32 *)(temp_10 + 0);
                *(f32 *)(temp_7 + 4) = *(f32 *)(temp_10 + 4);
                *(f32 *)(temp_6 + 0) = *(f32 *)(temp_9 + 0);
                *(f32 *)(temp_6 + 4) = *(f32 *)(temp_9 + 4);
                *(f32 *)(temp_4 + 0) = *(f32 *)(temp_8 + 0);
                *(f32 *)(temp_4 + 4) = *(f32 *)(temp_8 + 4);
            } while (var_24 < arg1);
        }
    } else {
        func_003a4d50(var_15, var_14, arg1 * temp_12 * 4);
    }
}
