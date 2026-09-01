/* Attempted C reconstruction of func_004824a0; retained for follow-up because scoped fndiff remained nonzero (pointer/arithmetic register allocation differences). */
void func_004824a0(u8 *arg0, u8 *arg1, u8 *arg2)
{
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f5;
    f32 temp_f6;
    s32 temp_7_2;
    s32 temp_8;
    s32 var_5;
    u32 temp_9;
    u32 temp_9_2;
    u8 **temp_3_2;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_5;
    u8 *temp_7;

    temp_3 = *(u8 **)(arg0 + 0);
    temp_7 = *(u8 **)(arg1 + 0xC);
    if ((*(s32 *)(temp_7 + 0x10) & 0x10000000) == 0) {
        temp_8 = *(s32 *)(arg1 + 8);
        if (temp_8 <= 0) {
            temp_9 = *(u32 *)(arg1 + 4) + 1;
            *(u32 *)(arg1 + 4) = temp_9;
            if (temp_9 >= *(u32 *)(temp_7 + 0xC)) {
                if ((*(s32 *)(temp_7 + 0x10) & 0x10) != 0) {
                    *(s16 *)(arg0 + 0x14) = 0;
                    *(u32 *)(arg1 + 4) = *(u32 *)(temp_7 + 0xC) - 1;
                } else {
                    *(u32 *)(arg1 + 4) = 0;
                }
            }
            *(s32 *)(arg1 + 8) =
                *(s16 *)(*(u8 **)(arg1 + 0x10) +
                         (*(u32 *)(arg1 + 4) * 0x18) + 0x12);
        } else {
            *(s32 *)(arg1 + 8) = temp_8 - 1;
        }
        temp_9_2 = *(u32 *)(arg1 + 4);
        temp_4 = *(u8 **)(arg1 + 0x10) + (temp_9_2 * 0x18);
        temp_7_2 = *(s32 *)(temp_7 + 0x10);
        if ((temp_7_2 & 1) != 0) {
            var_5 = *(s32 *)(*(u8 **)(temp_3 + 0) +
                             *(s32 *)(temp_7 + 4) + (temp_9_2 * 4));
        } else {
            var_5 = -1;
        }
        *(s32 *)(arg2 + 0x2C) = var_5;
        temp_3_2 = *(u8 ***)(temp_3 + 0x14) +
                   (*(s16 *)(temp_4 + 0x10) * 4);
        temp_5 = *(u8 **)(*temp_3_2 + 0);
        temp_f6 = (f32)*(s32 *)(temp_5 + 0xC);
        temp_f5 = (f32)*(s32 *)(temp_5 + 0x10);
        temp_7_2 = *(s32 *)(temp_7 + 0x10);
        if ((temp_7_2 & 2) != 0) {
            *(s16 *)(arg2 + 0x28) = 2;
        } else if ((temp_7_2 & 4) != 0) {
            *(s16 *)(arg2 + 0x28) = 3;
        } else {
            *(s16 *)(arg2 + 0x28) = 1;
        }
        *(f32 *)(arg2 + 0x10) = *(f32 *)(temp_4 + 0x14);
        *(f32 *)(arg2 + 0x18) =
            (f32)((s32)*(s16 *)(temp_4 + 8) >> 4) / temp_f6;
        *(f32 *)(arg2 + 0x1C) =
            (f32)((s32)*(s16 *)(temp_4 + 0xA) >> 4) / temp_f5;
        *(f32 *)(arg2 + 0x20) =
            (f32)((s32)*(s16 *)(temp_4 + 0xC) >> 4) / temp_f6;
        *(f32 *)(arg2 + 0x24) =
            (f32)((s32)*(s16 *)(temp_4 + 0xE) >> 4) / temp_f5;
        temp_f2 = (f32)*(s16 *)(temp_4 + 0) / 2.0f;
        temp_f1 = (f32)*(s16 *)(temp_4 + 2) / 2.0f;
        *(f32 *)(arg2 + 0) =
            temp_f2 - (f32)*(s16 *)(temp_4 + 4);
        *(f32 *)(arg2 + 4) =
            temp_f1 - (f32)*(s16 *)(temp_4 + 6);
        *(f32 *)(arg2 + 8) = temp_f2;
        *(f32 *)(arg2 + 0xC) = temp_f1;
        *(f32 *)(arg2 + 0x30) = temp_f6;
        *(f32 *)(arg2 + 0x34) = temp_f5;
        *(u8 **)(arg2 + 0x14) = (u8 *)temp_3_2;
    }
}
