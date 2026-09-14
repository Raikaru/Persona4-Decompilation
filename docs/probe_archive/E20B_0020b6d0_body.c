/* Instruction-exact executable body: 812B / 816B retail window, 14 resolved
 * relocations, and one absent zero tail word. The authoritative typed
 * func_00242800(u8 *, s32) declaration is required. Declaring var_19 before
 * temp_18 reproduces retail's $s3/$s2 allocation without an old-style
 * declaration or 64-bit argument mismatch. */
void func_0020b6d0(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3)
{
    u16 spD0;
    u32 spC0;
    u32 spB0;
    u32 spA0;
    u8 *temp_2_3;
    u8 *temp_2;
    s32 temp_2_2;
    s32 var_20;
    s32 var_23;
    s32 var_2;
    s32 var_30;
    u16 var_19;
    s32 temp_18;
    s32 temp_3;
    u16 temp_16;
    u8 *temp_16_2;
    u8 *temp_22;

    temp_2 = (u8 *)func_00452560();
    temp_2_3 = temp_2 + 0x710;
    *(s32 *)(temp_2 + 0x718) = (s32)arg1;
    *(s32 *)(temp_2 + 0x71C) = 0;
    *(u8 **)(temp_2 + 0x720) = arg2;
    *(s16 *)(temp_2 + 0x724) = arg3;
    *(s16 *)(temp_2_3 + 4) = 1;
    *(u8 *)(arg2 + 0x3C) |= 1;
    if ((func_001d8df0(arg2) & 0xFFFF) == 1) {
        *(u16 *)temp_2_3 |= 2;
    } else {
        *(u16 *)temp_2_3 &= 0xFFFD;
    }
    switch (arg3) {
    case 0x110:
    case 0x10B:
        var_30 = 1;
        break;
    default:
        var_30 = 0;
        break;
    }
    var_23 = 0;
    if (arg3 >= 0) {
        if (func_00106330(0x38) != 0) {
            var_2 = 5;
        } else {
            var_2 = 8;
        }
        if (func_0010ce10((u8 *)func_0010a900(var_2 & 0xFFFF), 0x10C) != -1) {
            var_23 = 1;
        }
    }
    spC0 = *(u16 *)(arg2 + 0x38);
    temp_16 = (u16)arg3;
    spB0 = func_0010f8c0(temp_16) & 0xFFFF;
    var_20 = 0;
    spD0 = temp_16 & 0xFFFF;
    goto loop_condition;
loop_body:
    temp_22 = *(u8 **)(arg2 + var_20 * 4);
    temp_16_2 = *(u8 **)(temp_22 + 0x30);
    if (var_30 != 0) {
        var_19 = 3;
    } else {
        var_19 = 0;
        temp_18 = (s16)func_0023d8e0(*(u8 **)(temp_16_2 + 0xA64), spD0);
        temp_2_2 = func_0023d6e0((s64)(s16)temp_18);
        if (!(temp_2_2 & 0xE0001)) {
            if (temp_2_2 & 2) {
                if ((s8)func_00233a90(*(u8 **)(temp_16_2 + 0xA64), 0x10) > 0) {
                    var_19 = 1;
                }
            } else if (!(temp_2_2 & 0x40) &&
                       (s8)func_00233a90(*(u8 **)(temp_16_2 + 0xA64), 0x11) > 0) {
                var_19 = 1;
            }
        }
        if ((var_23 != 0) && !(var_19 & 0xFFFF)) {
            spA0 = func_00242800(*(u8 **)(temp_16_2 + 0xA64), temp_18);
            var_2 = (u16)temp_18;
            temp_3 = *(u16 *)(temp_16_2 + 0xA4);
            if (func_001f0950(temp_3, var_2) != 0) {
                if ((spA0 & 0x02000000) != 0) {
                    var_19 = 1;
                } else if ((spA0 & 0x05000000) != 0) {
                    var_19 = 2;
                }
            }
        }
    }
    func_0020bfc0(*(u8 **)(temp_22 + 0x30) + 0xA48, (s16)var_19);
    if (spB0 != 0) {
        func_0020bfd0(*(u8 **)(temp_22 + 0x30) + 0xA48);
    }
    var_20 += 1;
loop_condition:
    if (var_20 < (s32)spC0) {
        goto loop_body;
    }
    *(s16 *)(temp_2_3 + 2) = 0;
}
