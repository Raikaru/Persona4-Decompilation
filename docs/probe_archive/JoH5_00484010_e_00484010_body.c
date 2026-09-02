/* object 432B/window 432B, normalized_diff 9, differing words 9. Lane JoH5_00484010_e.
   Residual: copy loop temp registers (src=$v1, counter=$a1) vs retail (src=$a1, counter=$v1).
   Tried: moved var_3=0 before dst/src loads to reserve a register; outer loop var_16=0 before temp_6.
   Next: for-loop form for copy, src load first, var_3 in v1. */
u8 *func_00484010(u8 *arg0)
{
    u8 *temp_23;
    u8 *temp_22;
    s32 var_20;
    u8 *temp_19;
    u8 *temp_18;
    u8 *var_17;
    u8 *temp_6;
    s32 var_16;
    s32 var_3;

    temp_23 = func_00483a00(
        *(u16 *)(arg0 + 0x48),
        *(u16 *)(arg0 + 8),
        *(u16 *)(arg0 + 0xA),
        *(s32 *)(arg0 + 4));
    temp_22 = *(u8 **)(temp_23 + 0x54);
    temp_19 = *(u8 **)(*(u8 **)(arg0 + 0x10) + 0x18);
    temp_18 = *(u8 **)(*(u8 **)(temp_23 + 0x10) + 0x18);

    var_16 = 0;
    while (var_16 < *(s16 *)(arg0 + 0x48)) {
        s32 temp_3;
        u8 *p;

        temp_3 = var_16 * 4;
        p = *(u8 **)(*(u8 **)(arg0 + 0x54) + temp_3);
        if (*(s32 *)p != 0) {
            func_003c42b0(*(void **)(temp_22 + temp_3), *(s32 *)p);
        }
        var_16 += 1;
    }

    func_003c2290(temp_19, 1);

    {
        u8 *dst;
        u8 *src;

        var_3 = 0;
        dst = *(u8 **)(temp_18 + 0x2C);
        src = *(u8 **)(temp_19 + 0x2C);
        var_17 = dst;
        while (var_3 < *(s16 *)(arg0 + 0x4C)) {
            *(u16 *)dst = *(u16 *)src;
            *(u16 *)(dst + 2) = *(u16 *)(src + 2);
            *(u16 *)(dst + 4) = *(u16 *)(src + 4);
            src += 8;
            dst += 8;
            var_3 += 1;
        }
    }

    var_20 = 0;
    while (var_20 < *(s16 *)(arg0 + 0x48)) {
        var_16 = 0;
        temp_6 = (u8 *)(temp_22 + var_20 * 4);
        while (var_16 < *(s16 *)(arg0 + 0xA)) {
            func_003c2150(temp_18, var_17, *(s32 *)temp_6);
            var_17 += 8;
            var_16 += 1;
        }
        var_20 += 1;
    }

    func_003c22f0(temp_19);
    return temp_23;
}
