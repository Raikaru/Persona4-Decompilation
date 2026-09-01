// Candidate archive for func_003c6080.
// Generated flag/ordering reconstruction with no_branch_likely on; object 488B/window 512B, normalized_diff 123. Retail register/control-flow layout remained different.
s32 func_003c6080(u8 **arg0, u8 **arg1) {
    s32 temp_7;
    s32 temp_7_2;
    s32 var_2;
    s32 var_3;
    s32 var_4;
    s32 var_4_2;
    s32 var_4_3;
    s32 var_5;
    s32 var_5_2;
    s32 var_6;
    s32 var_8;
    s32 var_8_2;
    u16 temp_2_2;
    u16 temp_4;
    u16 temp_4_2;
    u16 temp_4_3;
    u16 temp_5;
    u16 temp_5_2;
    u16 temp_6_3;
    u16 temp_7_3;
    u8 **temp_6;
    u8 **temp_6_2;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_8;
    u8 *temp_9;

    temp_2 = *arg0;
    temp_3 = *arg1;
    temp_9 = *(u8 **)(temp_2 + 8);
    var_4 = 0;
    temp_8 = *(u8 **)(temp_3 + 8);
    var_5 = 0;
    if (temp_9 != temp_8) {
        temp_6 = *(u8 ***)(temp_9 + 0);
        if (temp_6 != NULL) {
            temp_7 = (*(u8 *)(*(u8 **)(temp_6) + 0x23) << 8) & 0xF00;
            switch (temp_7) {
            case 0x500:
            case 0x100:
            case 0x300:
                var_5 = 0x10;
                break;
            }
        }
        if (*(u8 *)(temp_9 + 7) != 0xFF)
            var_5 |= 0x10;
        if (temp_8 != NULL) {
            temp_6_2 = *(u8 ***)(temp_8 + 0);
            if (temp_6_2 != NULL) {
                temp_7_2 = (*(u8 *)(*(u8 **)(temp_6_2) + 0x23) << 8) & 0xF00;
                if (temp_7_2 == 0x100 || temp_7_2 == 0x300 ||
                    temp_7_2 == 0x500)
                    var_4 = 0x10;
            }
            if (*(u8 *)(temp_8 + 7) != 0xFF)
                var_4 |= 0x10;
        }
        temp_7_3 = *(u16 *)(temp_3 + 0x10);
        temp_6_3 = *(u16 *)(temp_2 + 0x10);
        if (temp_7_3 < temp_6_3)
            var_8 = 8;
        else
            var_8 = 0;
        if (temp_6_3 < temp_7_3)
            var_5_2 = 8;
        else
            var_5_2 = 0;
        temp_5 = *(u16 *)(temp_3 + 0x12);
        temp_4 = *(u16 *)(temp_2 + 0x12);
        if (temp_5 < temp_4)
            var_6 = 4;
        else
            var_6 = 0;
        if (temp_4 < temp_5)
            var_4_2 = 4;
        else
            var_4_2 = 0;
        temp_5_2 = *(u16 *)(temp_3 + 0xE);
        temp_4_2 = *(u16 *)(temp_2 + 0xE);
        if (temp_5_2 < temp_4_2)
            var_8_2 = 2;
        else
            var_8_2 = 0;
        if (temp_4_2 < temp_5_2)
            var_4_3 = 2;
        else
            var_4_3 = 0;
        temp_2_2 = *(u16 *)(temp_2 + 0xC);
        temp_4_3 = *(u16 *)(temp_3 + 0xC);
        if (temp_4_3 < temp_2_2)
            var_3 = 1;
        else
            var_3 = 0;
        if (temp_2_2 < temp_4_3)
            var_2 = 1;
        else
            var_2 = 0;
        return (var_5 | var_8 | var_6 | var_8_2 | var_3) -
               (var_4 | var_5_2 | var_4_2 | var_4_3 | var_2);
    }
    return 0;
}
