/* object_size: 796; window: 800; normalized_diff: 3; differing offsets: 0x170, 0x17c, 0x2bc */
/* Residual classification: REGISTER CLASS / operand-order residuals share the same four-byte color-buffer stores. Retail uses sb $a1,4($a2), sb $v0,7($a2), and addu $v1,$v0,$v1; candidate uses sb $v0,4($a2), sb $a1,7($a2), and addu $v1,$v1,$v0. The common factor is the color-byte local/register lifetime plus final lookup-address add operand order, not a missing instruction; the 4-byte tail is zero padding. Probed census callee declarations, global array/scalar forms, color load/assignment/mapping/declaration orders, widths/signedness, direct/pointer/inline stores, and lookup-address helper spellings; best remained nd 3. */
void func_00165fb0(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 temp_17_2;
    s32 temp_18;
    s32 temp_17;
    s32 temp_21;
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_4_2;
    u8 *temp_6;
    u8 *var_18;
    u8 color3;
    u8 color1;
    u8 color2;
    u8 color0;

    if (arg0 != NULL) {
        temp_17 = (s32)(((*(u8 **)(arg0 + 0x160) + 7)[0] & 1) != 0);
        *(u16 *)(arg0 + 0xC) = (u16)func_00145ac0(arg2 & 0xFFFF, func_00478750(*(s32 *)(func_0015a320())));
        temp_2 = func_00145270(*(u16 *)(arg0 + 0xC));
        func_0047aa30(*(u8 **)(temp_2 + 0x144), D_005DC920);
        temp_21 = temp_17 * 0xC;
        func_0047a1e0(*(u8 **)(temp_2 + 0x144), D_005F1530 + temp_21, 2);
        func_0047a1a0(*(u8 **)(temp_2 + 0x144), D_00756510, *(f32 *)(arg1 + 0x14C), 2);
        func_0047a180(*(u8 **)(temp_2 + 0x144), (f32 *)(arg1 + 0x140), 2);
        if (*(s32 *)(arg0 + 8) != 0) {
            func_00479940(*(u8 **)(temp_2 + 0x144), 0, 2, 0, 0);
        } else if (temp_17 == 1) {
            func_00479940(*(u8 **)(temp_2 + 0x144), 0, 3, 0, 0);
        }
        temp_3 = *(u8 **)(temp_2 + 0x144);
        *(s32 *)(temp_3 + 0xD8) |= 0x80;
        temp_3_2 = *(u8 **)(temp_2 + 0x144);
        var_18 = *(u8 **)(*(u8 **)(temp_3_2 + 0x2CC));
        temp_6 = *(u8 **)(temp_3_2 + 0x124);
        color0 = iGpffff9f28;
        color1 = iGpffff9f29;
        color2 = iGpffff9f2a;
        color3 = iGpffff9f2b;
        temp_6[4] = color3;
        temp_6[5] = color1;
        temp_6[6] = color2;
        temp_6[7] = color0;
        while (var_18 != NULL) {
            temp_4 = *(s32 *)(var_18 + 8);
            if (temp_4 != 0) {
                func_004b13f0((u8 *)temp_4, (u8 *)&iGpffff9f28);
            }
            var_18 = *(u8 **)(var_18 + 0x10);
        }
        if (temp_17 == 1) {
            func_0047a220((s32)*(u8 **)(temp_2 + 0x144), (u8 *)&iGpffff9f24);
        } else {
            func_0047a220((s32)*(u8 **)(temp_2 + 0x144), D_005F1570 + ((func_0015a160() / 20U) * 4));
        }
        temp_2_2 = (u8 *)func_00478750(D_00764364);
        *(u8 **)(temp_2 + 0x16C) = temp_2_2;
        func_0047a1a0(temp_2_2, D_00756510, *(f32 *)(arg1 + 0x14C), 2);
        func_0047a1e0(*(u8 **)(temp_2 + 0x16C), D_005F1550 + temp_21, 2);
        func_0047a180(*(u8 **)(temp_2 + 0x16C), (f32 *)(arg1 + 0x140), 2);
        temp_4_2 = *(u8 **)(temp_2 + 0x16C);
        *(u8 **)(arg0 + 0x164) = temp_4_2;
        func_00478e70(temp_4_2);
        temp_17_2 = (s32)((600.0f + *(f32 *)(arg1 + 0x140)) / 1200.0f);
        temp_18 = (s32)((600.0f + *(f32 *)(arg1 + 0x148)) / 1200.0f);
        *(u8 **)(temp_2 + 0x140) = func_00145270(*(u16 *)((u8 *)(temp_18 << 8) + (u32)func_00155280() + (temp_17_2 * 0x10) + 0x56));
        func_0014a0f0(*(u16 *)(arg0 + 0xC), 1);
        D_007643D8 += 1;
    }
}
