/* object 920B / window 896B / normalized_diff 665 / differing offsets 0,46,49,50,54,55,56,57,58,59,60,61,62,63,64,65 / classification object oversized and wrong declaration/register environment; best direct u_long128 candidate was discarded immediately per wave rule. Existing dbba0 archive notes record prior nd 204, but this re-measure produced an oversized object. */
typedef unsigned int u_long128 __attribute__((mode(TI)));
s32 func_001dbba0(arg0, arg1, arg2, arg3, arg4, arg5)
u64 arg0;
s64 arg1;
s32 arg2;
s32 arg3;
s32 arg4;
code arg5;
{
    u8 *unit;
    s32 spEC;
    code spE8;
    u_long128 spD0, spC0, spB0, spA0;
    u32 selected[8];
    s32 temp17, temp23, temp4, var22, var2, var2_2, var4, var6;
    u16 temp3, var18;
    u8 *temp16, *temp19, *temp3_2;

    unit = (u8 *)(u32)arg0;
    spEC = arg4;
    spE8 = arg5;
    temp23 = arg3 & 0xffff;
    if (temp23 & 0x20) {
        func_001d7c60(unit, unit + 0x98, 2, 0, 0);
        goto block7;
    }
    if (func_001d7f10(unit + 0x98, (u8 *)(unit + 0x6e), 0, 0) & 0xffff) {
        var4 = 0;
loop5:
        temp3 = *(u16 *)(unit + 0xd0);
        if ((var4 & 0xffff) < (s32)temp3) {
            temp3_2 = unit + (var4 & 0xffff) * 4;
            *(u32 *)(temp3_2 + 0x38) = *(u32 *)(temp3_2 + 0x98);
            var4 = (var4 + 1) & 0xffff;
            goto loop5;
        }
        *(u16 *)(unit + 0x6a) = temp3;
        return 1;
    }
block7:
    var18 = 0;
    var22 = 0;
    temp17 = arg3 & 0xffff;
    spD0 = (u_long128)(temp17 & 1);
    spC0 = (u_long128)(temp17 & 2);
    spB0 = (u_long128)(temp17 & 0x10);
    spA0 = (u_long128)(temp17 & 0x40);
loop25:
    if ((var22 & 0xffff) < (s32)*(u16 *)(unit + 0xd0)) {
        temp19 = *(u8 **)(unit + (var22 & 0xffff) * 4 + 0x98);
        if ((*(u16 *)(temp19 + 0x1a) & 1) == 0)
            goto next25;
        temp16 = *(u8 **)(temp19 + 0x30);
        if (temp17 != 0 &&
            ((*(u32 *)&spD0) == 0 || func_00232710(*(u32 *)(temp16 + 0xa64), 0x100000) != 0) &&
            ((*(u32 *)&spC0) == 0 || *(u8 *)(temp16 + 0xa2) != 1 ||
             func_001f9ce0(temp19, (s64)((s64)(arg1 << 0x30) >> 0x30)) != 0 ||
             func_0010f420(*(u16 *)(temp16 + 0xa4), arg1 & 0xffff) != 0) &&
            ((*(u32 *)&spB0) == 0 || func_001dd570(unit, temp19, 0, 0) >= 0) &&
            ((*(u32 *)&spA0) == 0 ?
             func_00232710(*(u32 *)(temp16 + 0xa64), arg2) == 0 :
             func_002340c0(*(u32 *)(temp16 + 0xa64), arg2) != 0) &&
            (u8 *)spEC != (u8 *)spE8(temp19, arg1)) {
            *(u32 *)(selected + (var18 & 0xffff)) = (u32)temp19;
            var18 = (var18 + 1) & 0xffff;
        }
    }
next25:
    var22 = (var22 + 1) & 0xffff;
    goto loop25;
    }
    temp4 = var18 & 0xffff;
    if (temp4 == 0)
        return (temp23 & 8) ? 0 : func_001dbf20(unit, (u32)arg1);
    if (!(temp23 & 4)) {
        var2_2 = 0;
        if (temp4 >= 2)
            var2_2 = func_00231d70(temp4) & 0xffff;
        *(u32 *)(unit + 0x38) = selected[var2_2 & 0xffff];
        *(u16 *)(unit + 0x6a) = 1;
    } else {
        var6 = 0;
loop37:
        if ((var6 & 0xffff) < temp4) {
            *(u32 *)(unit + (var6 & 0xffff) * 4 + 0x38) = selected[var6 & 0xffff];
            var6 = (var6 + 1) & 0xffff;
            goto loop37;
        }
        *(u16 *)(unit + 0x6a) = var18;
    }
    return 1;
}
