/* object 432B/window 432B, normalized_diff 42, differing words 33. Lane JoH1_00484010_a.
   Retail saved reg assignment: s7=temp_23, fp=temp_6, s6=temp_22, s5=arg0,
   s4=var_20, s3=temp_19, s2=temp_18, s1=var_17, s0=var_16.
   Candidate assignment: s7=temp_23, fp=temp_6, s6=temp_22, s5=arg0,
   s4=temp_19, s3=temp_18, s2=var_17, s1=var_16, s0=var_20.
   Tried: local declaration order temp_23, temp_22, temp_19, temp_18,
   var_17, temp_6, var_16, var_3, var_20. Result: lower saved regs shifted
   by one; var_20 in s0 instead of s4. Next: move var_20 declaration up. */
// FUN_00484010
u8 *func_00484010(u8 *arg0)
{
    u8 *temp_23;
    u8 *temp_22;
    u8 *temp_19;
    u8 *temp_18;
    u8 *var_17;
    u8 *temp_6;
    s32 var_16;
    s32 var_3;
    s32 var_20;

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
        u8 *src;
        u8 *dst;

        src = *(u8 **)(temp_19 + 0x2C);
        dst = *(u8 **)(temp_18 + 0x2C);
        var_17 = dst;
        var_3 = 0;
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
        temp_6 = (u8 *)(temp_22 + var_20 * 4);
        var_16 = 0;
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
