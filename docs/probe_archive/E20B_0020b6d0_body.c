/* measured: object 904 / window 816 / normalized_diff 519; target remained MISMATCH. Corrected verified callee signatures: func_0010f8c0(s32)->u8, func_0010a900(s32)->u16 *, func_0010ce10(u8 *,u32)->s32, func_001d8df0(int)->u32, func_00233a90(u8 *,s32)->s8, func_00242800(u8 *,s32)->s32. Target ABI (s32, u8 *, u8 *, s16) confirmed from retail caller; s64 ABI variants were tried and reverted. */
void func_0020b6d0(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3) {
    u16 spD0;
    s128 spC0;
    s128 spB0;
    s128 spA0;
    u8 *temp_2_3;
    u8 *temp_2;
    s32 temp_2_2;
    s32 var_20;
    s32 var_23;
    s32 var_2;
    s32 var_30;
    s64 temp_18;
    s64 temp_3;
    s64 var_19;
    u16 temp_16;
    u8 *temp_16_2;
    u8 *temp_22;

    temp_2 = func_00452560();
    temp_2_3 = temp_2 + 0x710;
    *(s32 *)((u8 *)temp_2 + 0x718) = (s32)arg1;
    *(s32 *)((u8 *)temp_2 + 0x71C) = 0;
    *(u8 **)((u8 *)temp_2 + 0x720) = arg2;
    *(s16 *)((u8 *)temp_2 + 0x724) = arg3;
    *(s16 *)(temp_2_3 + 4) = 1;
    *(u8 *)(arg2 + 0x3C) = (u8)(*(u8 *)(arg2 + 0x3C) | 1);
    if ((func_001d8df0((int)arg2) & 0xFFFF) == 1) {
        *(u16 *)temp_2_3 = (u16)(*(u16 *)temp_2_3 | 2);
    } else {
        *(u16 *)temp_2_3 = (u16)(*(u16 *)temp_2_3 & 0xFFFD);
    }
    temp_3 = (s64)((s64)arg3 << 0x30) >> 0x30;
    if ((temp_3 != 0x10B) && (temp_3 != 0x110)) {
        var_30 = 0;
    } else {
        var_30 = 1;
    }
    var_23 = 0;
    if (temp_3 >= 0) {
        if (func_00106330(0x38) != 0) {
            var_2 = 5;
        } else {
            var_2 = 8;
        }
        if (func_0010ce10((u8 *)func_0010a900(var_2 & 0xFFFF), 0x10C) != -1) {
            var_23 = 1;
        }
    }
    spC0 = (s128)*(u16 *)((u8 *)arg2 + 0x38);
    temp_16 = arg3 & 0xFFFF;
    spB0 = func_0010f8c0(temp_16) & 0xFFFF;
    var_20 = 0;
    spD0 = temp_16 & 0xFFFF;
loop_34:
    if (var_20 < spC0) {
        temp_22 = *(u8 **)((u8 *)arg2 + (var_20 * 4));
        temp_16_2 = *(u8 **)(temp_22 + 0x30);
        if (var_30 != 0) {
            var_19 = 3;
        } else {
            var_19 = 0;
            temp_18 = (s64)(func_0023d8e0(*(u8 **)(temp_16_2 + 0xA64), spD0) << 0x30) >> 0x30;
            temp_2_2 = func_0023d6e0(temp_18);
            if (!(temp_2_2 & 0xE0001)) {
                if (temp_2_2 & 2) {
                    if (((s64)(func_00233a90(*(u8 **)(temp_16_2 + 0xA64), 0x10) << 0x38) >> 0x38) > 0) {
                        var_19 = 1;
                    }
                } else if (!(temp_2_2 & 0x40) &&
                           (((s64)(func_00233a90(*(u8 **)(temp_16_2 + 0xA64), 0x11) << 0x38) >> 0x38) > 0)) {
                    var_19 = 1;
                }
            }
            if ((var_23 != 0) && !(var_19 & 0xFFFF)) {
                spA0 = (s128)(s32)(func_00242800(*(u8 **)(temp_16_2 + 0xA64), temp_18));
                if (func_001f0950(*(u16 *)(temp_16_2 + 0xA4), temp_18 & 0xFFFF) != 0) {
                    if (((s32)spA0 & 0x02000000) != 0) {
                        var_19 = 1;
                    } else if (((s32)spA0 & 0x05000000) != 0) {
                        var_19 = 2;
                    }
                }
            }
        }
        func_0020bfc0(*(u8 **)(temp_22 + 0x30) + 0xA48,
                      (s64)(var_19 << 0x30) >> 0x30);
        if ((s32)spB0 != 0) {
            func_0020bfd0(*(u8 **)(temp_22 + 0x30) + 0xA48);
        }
        var_20 += 1;
        goto loop_34;
    }
    *(s16 *)(temp_2_3 + 2) = 0;
}
