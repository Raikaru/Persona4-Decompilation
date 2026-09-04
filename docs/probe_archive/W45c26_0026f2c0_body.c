/* func_0026f2c0 probe archive: object 728B / window 736B / nd 27; differing offsets (byte): 0x13c, 0x144, 0x15c, 0x164, 0x16c, 0x194, 0x198, 0x19c, 0x1a0, 0x1a4, 0x1ac, 0x1b0, 0x1b4, 0x1bc, 0x1c0, 0x1c8, 0x1cc, 0x1d0, 0x1d8, 0x1e8, 0x1ec, 0x248, 0x24c, 0x254, 0x258, 0x25c, 0x260, 0x264, 0x26c, 0x270, 0x274, 0x27c, 0x280, 0x288, 0x28c, 0x290, 0x298, 0x29c, 0x2a0, 0x2a8, 0x2ac, 0x2b0, 0x2b4, 0x2b8, 0x2bc, 0x2c0, 0x2c4, 0x2c8, 0x2cc, 0x2d0; levers: generated M2C, explicit self/field loads, opt_propagation off, opt_common_subs off, s8 stack, early-return/control-flow variants, decode temporary/type variants, explicit nested slot, separate table value, register hints, prototype variants, declaration order, optimization-level probe, schedule probe, duplicate restore. */ 
// FUN_0026F2C0
s32 func_0026f2c0(s32 arg0, u8 *arg1)
{
    extern u8 *func_001067f0(s16 arg0);
    extern void func_00273cc0(u8 *arg0, u8 *arg1);
    u16 first;
    u16 second;
    s32 third;
    s32 **slot;
    u8 old;
    s8 stack[8];
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_2;
    s32 temp_3_6;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = temp_3_2 - 1;
        var_2 &= 0xFF;
    }
    first = (u16)(s16)(((var_2 & 0xFF) << 8) |
                       (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (temp_3[2] - 1) & 0xFF;
    temp_3_2 = temp_3[3];
    if (temp_3_2 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = temp_3_2 - 1;
        var_2_2 &= 0xFF;
    }
    second = (u16)(s16)(((var_2_2 & 0xFF) << 8) |
                        (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_4 = (temp_3[4] - 1) & 0xFF;
    temp_3_6 = temp_3[5];
    if (temp_3_6 == 0xFF) {
        var_2_3 = 0;
    } else {
        var_2_3 = temp_3_6 - 1;
        var_2_3 &= 0xFF;
    }
    third = (u16)(s16)(((var_2_3 & 0xFF) << 8) |
                       (temp_4 & 0xFF));

    if (func_002746a0(temp_4) != 0) {
        return 0;
    }
    slot = (s32 **)((s32)D_008815B0 +
                    ((third & 0xFFFF) * 4));
    if (*slot != 0) {
        old = *(u8 *)(arg1 + 0xD);
        if (first != 0xFFFF) {
            arg1[0xD] = first;
        }
        if (second != 0xFFFF) {
            stack[0] = -0x7D;
            stack[1] = second + 0xC7;
            stack[2] = 0;
            func_00273f70(arg1);
            func_00273cc0((u8 *)stack, arg1);
            func_00273f70(arg1);
            func_002739e0(third & 0xFF, arg1);
        } else {
            third = *(*slot);
            temp_2 = func_0026e360(third);
            switch (temp_2) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 9:
            case 11:
                var_2_3 = 1;
                break;
            default:
                var_2_3 = 0;
                break;
            }
            if (var_2_3 != 0) {
                arg1[0xD] = 4;
            }
            stack[0] = -0x7D;
            stack[1] = func_0026e360(third) + 0xC7;
            stack[2] = 0;
            func_00273f70(arg1);
            func_00273cc0((u8 *)stack, arg1);
            func_00273f70(arg1);
            func_00273cc0(func_001067f0((s16)third), arg1);
        }
        arg1[0xD] = old;
    }
    return 0;
}
