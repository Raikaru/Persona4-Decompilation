/* Closest non-matching reconstruction for func_0035e8b0.
 * Candidate: exact 0x6D0-byte object/window, but 91 normalized instruction differences remain.
 * Main unresolved floor: switch/case-7 control-flow placement and unsigned float conversion.
 */
s32 func_0035e8b0(u32 *arg0, s32 *arg1, u8 *arg2)
{
    u8 buf[44];
    f32 temp_f1;
    f32 var_f1;
    s32 temp_2;
    s32 var_6;
    s32 var_3;
    s32 temp_2_3;
    s16 temp_2_4;
    u32 temp_2_5;

    *arg1 = (var_6 = 1);
    temp_2_5 = *arg0;
    switch (temp_2_5) {
    case 0:
        *(s32 *)(arg2 + 4) = 0;
        *(s32 *)(arg2 + 8) = 0;
        *(s8 *)arg2 = 0xFF;
        func_00356250(arg2);
        *arg0 = 1;
        *arg1 = 0;
        break;
    case 1:
        if ((func_00356820(arg2) & func_0034c210()) != 0) {
            *arg0 = 3;
            func_0034bb20(0x19);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (func_003596a0(arg2) != 0) {
            func_00359720(arg2);
            return 1;
        }
        break;
    case 3:
        if (func_003596a0(arg2) != 0) {
            func_00353fe0();
            func_00355190((u8 *)*(s32 *)(arg2 + 0x1308), 1);
            func_0035ac60((u8 *)*(s32 *)(arg2 + 0x1308), 0, 1, 0);
            *arg0 = 4;
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            func_00359400(arg2, 1);
            *arg0 = 2;
            func_00353fb0();
            func_0034bb20(0x1B);
            func_0035ac60((u8 *)*(s32 *)(arg2 + 0x1308), 0, 0, 1);
            func_0045af60(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x40) {
            if (*(s16 *)(arg2 + 0x134) > 0) {
                func_00359400(arg2, 2);
                func_003598d0(arg2);
                *arg0 = 5;
                func_003593e0((s32)arg2, 2, 0);
                func_0034bb20(0x1A);
                func_0035ac60((u8 *)*(s32 *)(arg2 + 0x1308), 1, 0, 0);
                func_0035ef80(arg2);
                func_003597f0(arg2);
                func_0035f020(arg2);
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 7;
        } else {
            func_00453670(buf, 5, *(s16 *)(arg2 + 0x134), *(s16 *)(arg2 + 0x24), *(s16 *)(arg2 + 0x26));
            func_004538e0(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            temp_2 = func_00453960(buf);
            if (temp_2 > 0) {
                func_003593e0((s32)arg2, 1, *(s32 *)(buf + 0x28));
                func_003593e0((s32)arg2, 0, *(s32 *)(buf + 0x24));
                func_00354080(temp_2);
            }
        }
        break;
    case 5:
        if (func_003596a0(arg2) != 0) {
            func_00359400(arg2, 3);
            *arg0 = 6;
            func_0034bb20(0x1C);
            func_003599a0(arg2);
            func_00355190((u8 *)*(s32 *)(arg2 + 0x1308), 0);
        }
        break;
    case 6:
        if (func_003596a0(arg2) != 0) {
            if (D_008C024E[0] & 0x20) {
                func_00359400(arg2, 4);
                *arg0 = 3;
                func_0034bd60(0x19);
                func_0035c480(*(s32 *)(arg2 + 0x1310), 0, 0);
                func_0045af60(0, 0, 0, 2);
            } else if (D_008C024E[0] & 0x10) {
                *(s32 *)(arg2 + 0x10) = func_00354030();
                *arg0 = 7;
            } else {
                func_00453670(buf, 5, *(s16 *)(arg2 + 0x134), *(s16 *)(arg2 + 0x24), *(s16 *)(arg2 + 0x26));
                func_00453760(buf, 0);
                func_004538e0(buf, 8, 4, 0, 0);
                if (func_00453960(buf) != 0) {
                    func_003593e0((s32)arg2, 1, *(s32 *)(buf + 0x28));
                    func_003593e0((s32)arg2, 0, *(s32 *)(buf + 0x24));
                    func_003593e0((s32)arg2, 2, 0);
                    func_0035ef80(arg2);
                    func_003599a0(arg2);
                    func_003597f0(arg2);
                    func_0035f020(arg2);
                    func_0045af60(0, 1, 0, 5);
                } else if (*(s32 *)(arg2 + 0x148) >= 2) {
                    func_00453670(buf, 8, *(s32 *)(arg2 + 0x148), *(s16 *)(arg2 + 0x28), 0);
                    func_004538e0(buf, 0x4000, 0x1000, 0, 0);
                    if (func_00453960(buf) != 0) {
                        func_003593e0((s32)arg2, 2, *(s32 *)(buf + 0x24));
                        func_0035f020(arg2);
                        func_0045af60(0, 1, 0, 0);
                    }
                }
            }
        }
        break;
    case 7:
        temp_2_3 = *(u16 *)(arg2 + 0xC) + 1;
        *(u16 *)(arg2 + 0xC) = temp_2_3;
        if ((temp_2_3 & 0xFFFF) >= 3) {
        } else {
            temp_2_4 = *(u16 *)(arg2 + 0xC);
            if ((s32)temp_2_4 >= 0) {
                var_f1 = (f32)temp_2_4;
            } else {
                var_f1 = 2.0f * (f32)((temp_2_4 >> 1) | (temp_2_4 & 1));
            }
            temp_f1 = 255.0f * (1.0f - (var_f1 / 3.0f));
            var_3 = (u8)temp_f1;
            *(s8 *)arg2 = var_3;
            var_6 = 0;
        }
        if (var_6 != 0) {
            return 2;
        }
        break;
    }
    return 0;
}
