// measured: func_00156800 obj 1224B window 1264B nd 304; levers: u8* arg0, D_005F0000->D_005F05D0, switch->if
void func_00156800(void *arg0_v, u32 arg1) {
    u8 *arg0 = arg0_v;
    s16 spE;
    s16 spC;
    s16 spA;
    s16 sp8;
    s16 temp_3;
    s16 temp_6_2;
    s16 temp_6_3;
    s16 temp_9_2;
    s32 var_13;
    s32 var_14;
    s32 var_5;
    s32 var_6;
    s32 var_7;
    s32 var_7_2;
    s32 var_7_3;
    s32 var_7_4;
    s32 var_7_5;
    s32 var_8;
    u32 temp_9_3;
    u32 temp_9_4;
    u32 temp_9_5;
    u32 temp_9_6;
    u8 temp_12;
    u8 temp_12_2;
    u8 temp_5;
    u8 temp_5_2;
    u8 temp_5_3;
    u8 temp_6;
    u8 temp_7_2;
    u8 *temp_3_2;
    u8 *temp_7;
    s16 *temp_9;

    var_8 = 0;
    var_14 = 0;
loop_5:
    if (var_14 < 3) {
        var_13 = 0;
loop_3:
        if (var_13 < 3) {
            temp_9 = &D_005F05D0[(s32)arg0[(var_14 * 3) + var_13 + 4] * 2];
            temp_7 = (u8 *)(arg0 + (var_14 * 0xC) + (var_13 * 4));
            *( s16 * )((s8 *)(temp_7) + (0x32)) = (s16) temp_9[0];
            *( s16 * )((s8 *)(temp_7) + (0x34)) = (s16) temp_9[1];
            var_13 += 1;
            goto loop_3;
        }
        var_14 += 1;
        goto loop_5;
    }
    var_7 = 0;
loop_10:
    if (var_7 < 4) {
        if ((1 << var_7) == arg1) {
            var_8 = var_7;
        } else {
            var_7 += 1;
            goto loop_10;
        }
    }
    if ((arg0[1] == 1) && (arg0[2] == 1)) {
        return;
    }
    if ((arg0[1] == 2) && (arg0[2] == 2)) {
    for (var_7_2 = 0; var_7_2 < var_8; var_7_2++) {
        temp_3 = *(s16 *)(arg0 + 0x32);
        temp_6_2 = *(s16 *)(arg0 + 0x34);
        *(s16 *)(arg0 + 0x32) = *(s16 *)(arg0 + 0x36);
        *(s16 *)(arg0 + 0x34) = *(s16 *)(arg0 + 0x38);
        *(s16 *)(arg0 + 0x36) = *(s16 *)(arg0 + 0x42);
        *(s16 *)(arg0 + 0x38) = *(s16 *)(arg0 + 0x44);
        *(s16 *)(arg0 + 0x42) = *(s16 *)(arg0 + 0x3E);
        *(s16 *)(arg0 + 0x44) = *(s16 *)(arg0 + 0x40);
        *(s16 *)(arg0 + 0x3E) = temp_3;
        *(s16 *)(arg0 + 0x40) = temp_6_2;
        temp_5 = arg0[0xD];
        arg0[0xD] = arg0[0xE];
        arg0[0xE] = arg0[0x11];
        arg0[0x11] = arg0[0x10];
        arg0[0x10] = temp_5;
    }
    } else if ((arg0[1] == 3) && (arg0[2] == 3)) {
    for (var_5 = 0; var_5 < (var_8 * 2); var_5++) {
        temp_6_3 = *(s16 *)(arg0 + 0x32);
        temp_9_2 = *(s16 *)(arg0 + 0x34);
        *(s16 *)(arg0 + 0x32) = *(s16 *)(arg0 + 0x36);
        *(s16 *)(arg0 + 0x34) = *(s16 *)(arg0 + 0x38);
        *(s16 *)(arg0 + 0x36) = *(s16 *)(arg0 + 0x3A);
        *(s16 *)(arg0 + 0x38) = *(s16 *)(arg0 + 0x3C);
        *(s16 *)(arg0 + 0x3A) = *(s16 *)(arg0 + 0x46);
        *(s16 *)(arg0 + 0x3C) = *(s16 *)(arg0 + 0x48);
        *(s16 *)(arg0 + 0x46) = *(s16 *)(arg0 + 0x52);
        *(s16 *)(arg0 + 0x48) = *(s16 *)(arg0 + 0x54);
        *(s16 *)(arg0 + 0x52) = *(s16 *)(arg0 + 0x4E);
        *(s16 *)(arg0 + 0x54) = *(s16 *)(arg0 + 0x50);
        *(s16 *)(arg0 + 0x4E) = *(s16 *)(arg0 + 0x4A);
        *(s16 *)(arg0 + 0x50) = *(s16 *)(arg0 + 0x4C);
        *(s16 *)(arg0 + 0x4A) = *(s16 *)(arg0 + 0x3E);
        *(s16 *)(arg0 + 0x4C) = *(s16 *)(arg0 + 0x40);
        *(s16 *)(arg0 + 0x3E) = temp_6_3;
        *(s16 *)(arg0 + 0x40) = temp_9_2;
        temp_7_2 = arg0[0xD];
        arg0[0xD] = arg0[0xE];
        arg0[0xE] = arg0[0xF];
        arg0[0xF] = arg0[0x12];
        arg0[0x12] = arg0[0x15];
        arg0[0x15] = arg0[0x14];
        arg0[0x14] = arg0[0x13];
        arg0[0x13] = arg0[0x10];
        arg0[0x10] = temp_7_2;
    }
    }
    var_7_3 = 0;
loop_29:
    if (var_7_3 < 3) {
        var_6 = 0;
loop_27:
        if (var_6 < 3) {
            temp_3_2 = (u8 *)(arg0 + (var_7_3 * 0xC) + (var_6 * 4));
            temp_12 = (u8)(*( u8 * )((s8 *)(temp_3_2) + (0x32)));
            temp_9_3 = (temp_12 & 0xF & 0xF) << var_8;
            temp_9_4 = (((s32) (temp_12 & 0xF0) >> 4) & 0xF) << var_8;
            *( u8 * )((s8 *)(temp_3_2) + (0x32)) = (u8) ((temp_9_3 & 0xF) | (temp_9_3 >> 4) | (((temp_9_4 & 0xF) | (temp_9_4 >> 4)) * 0x10));
            temp_12_2 = (u8)(*( u8 * )((s8 *)(temp_3_2) + (0x33)));
            temp_9_5 = (temp_12_2 & 0xF & 0xF) << var_8;
            temp_9_6 = (((s32) (temp_12_2 & 0xF0) >> 4) & 0xF) << var_8;
            *( u8 * )((s8 *)(temp_3_2) + (0x33)) = (u8) ((temp_9_5 & 0xF) | (temp_9_5 >> 4) | (((temp_9_6 & 0xF) | (temp_9_6 >> 4)) * 0x10));
            var_6 += 1;
            goto loop_27;
        }
        var_7_3 += 1;
        goto loop_29;
    }
    if ((*( u8 * )((s8 *)(arg0) + (1)) == 2) && (*( u8 * )((s8 *)(arg0) + (2)) == 2)) {
        switch (var_8) {                            /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            break;
        case 1:                                     /* switch 2 */
            *( s8 * )((s8 *)(arg0) + (0x16)) = -2;
            *( s8 * )((s8 *)(arg0) + (0x17)) = -1;
            break;
        case 2:                                     /* switch 2 */
            *( s8 * )((s8 *)(arg0) + (0x16)) = -1;
            *( s8 * )((s8 *)(arg0) + (0x17)) = -1;
            break;
        case 3:                                     /* switch 2 */
            *( s8 * )((s8 *)(arg0) + (0x16)) = -1;
            *( s8 * )((s8 *)(arg0) + (0x17)) = -2;
            break;
        }
    }
    var_7_4 = 0;
loop_42:
    if (var_7_4 < (var_8 * 4)) {
        temp_5_2 = (u8)(*( u8 * )((s8 *)(arg0) + (0x18)));
        *( u8 * )((s8 *)(arg0) + (0x18)) = (u8) *( u8 * )((s8 *)(arg0) + (0x19));
        *( u8 * )((s8 *)(arg0) + (0x19)) = (u8) *( u8 * )((s8 *)(arg0) + (0x1A));
        *( u8 * )((s8 *)(arg0) + (0x1A)) = (u8) *( u8 * )((s8 *)(arg0) + (0x1B));
        *( u8 * )((s8 *)(arg0) + (0x1B)) = (u8) *( u8 * )((s8 *)(arg0) + (0x1C));
        *( u8 * )((s8 *)(arg0) + (0x1C)) = (u8) *( u8 * )((s8 *)(arg0) + (0x21));
        *( u8 * )((s8 *)(arg0) + (0x21)) = (u8) *( u8 * )((s8 *)(arg0) + (0x26));
        *( u8 * )((s8 *)(arg0) + (0x26)) = (u8) *( u8 * )((s8 *)(arg0) + (0x2B));
        *( u8 * )((s8 *)(arg0) + (0x2B)) = (u8) *( u8 * )((s8 *)(arg0) + (0x30));
        *( u8 * )((s8 *)(arg0) + (0x30)) = (u8) *( u8 * )((s8 *)(arg0) + (0x2F));
        *( u8 * )((s8 *)(arg0) + (0x2F)) = (u8) *( u8 * )((s8 *)(arg0) + (0x2E));
        *( u8 * )((s8 *)(arg0) + (0x2E)) = (u8) *( u8 * )((s8 *)(arg0) + (0x2D));
        *( u8 * )((s8 *)(arg0) + (0x2D)) = (u8) *( u8 * )((s8 *)(arg0) + (0x2C));
        *( u8 * )((s8 *)(arg0) + (0x2C)) = (u8) *( u8 * )((s8 *)(arg0) + (0x27));
        *( u8 * )((s8 *)(arg0) + (0x27)) = (u8) *( u8 * )((s8 *)(arg0) + (0x22));
        *( u8 * )((s8 *)(arg0) + (0x22)) = (u8) *( u8 * )((s8 *)(arg0) + (0x1D));
        *( u8 * )((s8 *)(arg0) + (0x1D)) = temp_5_2;
        var_7_4 += 1;
        goto loop_42;
    }
    var_7_5 = 0;
loop_45:
    if (var_7_5 < (var_8 * 2)) {
        temp_5_3 = (u8)(*( u8 * )((s8 *)(arg0) + (0x1E)));
        *( u8 * )((s8 *)(arg0) + (0x1E)) = (u8) *( u8 * )((s8 *)(arg0) + (0x1F));
        *( u8 * )((s8 *)(arg0) + (0x1F)) = (u8) *( u8 * )((s8 *)(arg0) + (0x20));
        *( u8 * )((s8 *)(arg0) + (0x20)) = (u8) *( u8 * )((s8 *)(arg0) + (0x25));
        *( u8 * )((s8 *)(arg0) + (0x25)) = (u8) *( u8 * )((s8 *)(arg0) + (0x2A));
        *( u8 * )((s8 *)(arg0) + (0x2A)) = (u8) *( u8 * )((s8 *)(arg0) + (0x29));
        *( u8 * )((s8 *)(arg0) + (0x29)) = (u8) *( u8 * )((s8 *)(arg0) + (0x28));
        *( u8 * )((s8 *)(arg0) + (0x28)) = (u8) *( u8 * )((s8 *)(arg0) + (0x23));
        *( u8 * )((s8 *)(arg0) + (0x23)) = temp_5_3;
        var_7_5 += 1;
        goto loop_45;
    }
}
