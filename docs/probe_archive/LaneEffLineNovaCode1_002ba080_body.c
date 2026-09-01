/* Closest plain-C probe archived before restoring INCLUDE_ASM: explicit stack-local translation matched the 1360-byte retail window in size but retained a 0x120 frame, rotated saved GPR/FP registers, and different instruction order. */
// FUN_002BA080
void func_002ba080(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s32 arg4,
                   s64 arg5, s64 arg6, s16 arg7, f32 fparg0, s8 arg_sp0)
{
    s32 sp12C;
    s32 sp128;
    f32 sp120;
    f32 sp124;
    f32 sp118;
    f32 sp11C;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    s128 spF0;
    s128 spE0;
    s128 spD0;
    s32 spCC;
    s64 spC0;
    s32 temp_16_2;
    s32 temp_6_3;
    s32 temp_6_5;
    s32 temp_7;
    s64 temp_16;
    s64 temp_23;
    s64 temp_30;
    s64 temp_3;
    s64 temp_6;
    s64 var_22;
    s64 var_5;
    u8 *temp_16_3;
    u8 *temp_16_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_4;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *temp_6_2;
    u8 *temp_6_4;

    spC0 = arg3;
    spCC = arg4;
    func_002b29e0((u8 *)&spF0, 88.0f, 17.0f);
    func_002b2970((u8 *)&sp120,
                  *(f32 *)&spC0 + 284.0f,
                  *((f32 *)&spC0 + 1) + 6.0f);
    temp_16 = (s16)arg2;
    if ((temp_16 == -1) || (temp_16 == 0)) {
        var_5 = 10;
        var_22 = 10;
    } else {
        var_5 = (s8)(temp_16 % 10);
        var_22 = (s8)(temp_16 / 10);
    }
    temp_3 = (s16)arg1 * 2;
    temp_6 = (s16)temp_3;
    temp_23 = (s16)(temp_3 + 1);
    temp_30 = (s8)arg_sp0;
    if (temp_30 == 0) {
        temp_5 = D_0063F1F0 + ((s32)(s8)var_5 * 0x10);
        temp_7 = (s32)(s16)temp_6 * 0x220;
        temp_2 = (u8 *)(temp_7 + *(u8 **)(arg0 + 0x38));
        *(f32 *)(temp_2 + 0x1F4) = *(f32 *)(temp_5 + 0);
        *(f32 *)(temp_2 + 0x1F8) = *(f32 *)(temp_5 + 4);
        *(f32 *)(temp_2 + 0x1FC) = *(f32 *)(temp_5 + 8);
        *(f32 *)(temp_2 + 0x200) = *(f32 *)(temp_5 + 0xC);
        spE0 = spF0;
        sp12C = spCC;
        temp_6_2 = *(u8 **)(arg0 + 0x38) + temp_7;
        *(f32 *)(temp_6_2 + 0x12C) = sp120;
        *(f32 *)(temp_6_2 + 0x130) = sp124;
        *(s32 *)(temp_6_2 + 0x1A0) = 0x3F800000;
        *(s32 *)(temp_6_2 + 0x194) = 0x3F800000;
        *(u8 *)(temp_6_2 + 0x162) = ((u8 *)&sp12C)[3];
        *(u8 *)(temp_6_2 + 0x179) = ((u8 *)&spCC)[0];
        *(u8 *)(temp_6_2 + 0x17A) = ((u8 *)&spCC)[1];
        *(u8 *)(temp_6_2 + 0x17B) = ((u8 *)&spCC)[2];
        *(u8 *)(temp_6_2 + 0x17C) = ((u8 *)&spCC)[3];
        *(s32 *)(temp_6_2 + 0x1C4) = 0;
        *(f32 *)(temp_6_2 + 0x108) = fparg0;
        *(s16 *)(temp_6_2 + 0x104) = *(s16 *)(temp_6_2 + 0x104) | 1;
        *(f32 *)(temp_6_2 + 0x204) = *(f32 *)&spE0;
        *(f32 *)(temp_6_2 + 0x208) = *((f32 *)&spE0 + 1);
        *(f32 *)(temp_6_2 + 0x20C) = *((f32 *)&spE0 + 2);
        *(f32 *)(temp_6_2 + 0x210) = *((f32 *)&spE0 + 3);
        *(s16 *)(temp_6_2 + 0x100) = arg7;
        func_002b83e0(temp_6_2 + 0x104, *(s64 *)&sp120, spCC, spCC,
                      0, ((u8 *)&spCC)[3], arg5, arg6,
                      ((f32 *)&spF0)[3], fparg0, arg_sp0, 0);
    } else {
        temp_3_2 = *(u8 **)(arg0 + 0x38) + ((s32)(s16)temp_6 * 0x220);
        temp_4 = temp_3_2 + 0x104;
        if ((*(s16 *)(temp_3_2 + 0x104) & 1) == 1) {
            func_002b83e0(temp_4, *(s64 *)(temp_4 + 0x28),
                          *(s32 *)(temp_4 + 0x75), *(s32 *)(temp_4 + 0x75),
                          *(u8 *)(temp_4 + 0x5E), 0, arg5, arg6,
                          ((f32 *)&spF0)[3], fparg0, arg_sp0, 0);
        }
    }
    if (temp_30 == 0) {
        if ((temp_16 >= 10) || (temp_16 == 0)) {
            temp_5_2 = D_0063F1F0 + ((s32)(s8)var_22 * 0x10);
            temp_16_2 = (s32)(s16)temp_23 * 0x220;
            temp_2_2 = (u8 *)(temp_16_2 + *(u8 **)(arg0 + 0x38));
            *(f32 *)(temp_2_2 + 0x1F4) = *(f32 *)(temp_5_2 + 0);
            *(f32 *)(temp_2_2 + 0x1F8) = *(f32 *)(temp_5_2 + 4);
            *(f32 *)(temp_2_2 + 0x1FC) = *(f32 *)(temp_5_2 + 8);
            *(f32 *)(temp_2_2 + 0x200) = *(f32 *)(temp_5_2 + 0xC);
            func_002b2970((u8 *)&sp118, sp120 - 18.0f, sp124);
            sp100 = sp118;
            sp104 = sp11C;
            spD0 = spF0;
            sp128 = spCC;
            temp_6_4 = *(u8 **)(arg0 + 0x38) + temp_16_2;
            *(f32 *)(temp_6_4 + 0x12C) = sp118;
            *(f32 *)(temp_6_4 + 0x130) = sp11C;
            *(s32 *)(temp_6_4 + 0x1A0) = 0x3F800000;
            *(s32 *)(temp_6_4 + 0x194) = 0x3F800000;
            *(u8 *)(temp_6_4 + 0x162) = ((u8 *)&sp128)[3];
            *(u8 *)(temp_6_4 + 0x179) = ((u8 *)&spCC)[0];
            *(u8 *)(temp_6_4 + 0x17A) = ((u8 *)&spCC)[1];
            *(u8 *)(temp_6_4 + 0x17B) = ((u8 *)&spCC)[2];
            *(u8 *)(temp_6_4 + 0x17C) = ((u8 *)&spCC)[3];
            *(s32 *)(temp_6_4 + 0x1C4) = 0;
            *(f32 *)(temp_6_4 + 0x108) = fparg0;
            *(s16 *)(temp_6_4 + 0x104) = *(s16 *)(temp_6_4 + 0x104) | 1;
            *(f32 *)(temp_6_4 + 0x204) = *(f32 *)&spD0;
            *(f32 *)(temp_6_4 + 0x208) = *((f32 *)&spD0 + 1);
            *(f32 *)(temp_6_4 + 0x20C) = *((f32 *)&spD0 + 2);
            *(f32 *)(temp_6_4 + 0x210) = *((f32 *)&spD0 + 3);
            *(s16 *)(temp_6_4 + 0x100) = arg7;
            temp_16_3 = *(u8 **)(arg0 + 0x38) + temp_16_2 + 0x104;
            func_002b2970((u8 *)&sp110, sp120 - 18.0f, sp124);
            func_002b83e0(temp_16_3, *(s64 *)&sp110, spCC, spCC,
                          0, ((u8 *)&spCC)[3], arg5, arg6,
                          ((f32 *)&spF0)[3], fparg0, arg_sp0, 0);
        }
    } else {
        temp_3_3 = *(u8 **)(arg0 + 0x38) + ((s32)(s16)temp_23 * 0x220);
        temp_16_4 = temp_3_3 + 0x104;
        if ((*(s16 *)(temp_3_3 + 0x104) & 1) == 1) {
            func_002b2970((u8 *)&sp108, sp120 - 18.0f,
                          *(f32 *)(temp_16_4 + 0x2C));
            temp_6_5 = *(s32 *)(temp_16_4 + 0x75);
            func_002b83e0(temp_16_4, *(s64 *)&sp108, temp_6_5, temp_6_5,
                          *(u8 *)(temp_16_4 + 0x5E), 0, arg5, arg6,
                          ((f32 *)&spF0)[3], fparg0, arg_sp0, 0);
        }
    }
}
