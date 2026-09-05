/* Instruction-exact candidate for func_00277be0: object 664B/window 672B.
   fndiff: two absent zero-tail words, no emitted instruction differences.
   An s32 count reproduces SQ/LQ; declaring temp_23 before spBC reproduces
   the second-result register and third-result spill at stack offset 0xBC.
   NOT INSTALLED: 1U << var_18 is defined only for indices below 32. No
   bound on the signed table count is proven; retail SLLV wraps modulo 32.
   Explicit (var_18 & 31) adds an instruction (668B, fndiff 89 words).
   Independent semantic review agrees on calls, stores, widths and control
   flow, but its acceptance is conditional on this unresolved input bound. */
// FUN_00277BE0
void func_00277be0(s32 arg0, s32 arg1)
{
    u8 *temp_19;
    s32 temp_3;
    s32 var_18;
    s32 *var_21;
    s32 temp_22;
    s32 temp_23;
    s32 temp_21;
    u32 var_22;
    u8 *base;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_3_2;
    s32 spA0;
    u32 temp_5;
    s32 temp_4;
    u32 var_23;
    u8 *temp_2;
    s32 spBC;
    u8 *temp_16;
    s32 temp_2_2;


    temp_19 = D_00881808[arg0].unk0;
    if (temp_19 == NULL)
        func_0046d730(D_0063BE10, 0x686);
    temp_2 = (u8 *)func_00278de0((s32)temp_19, arg1);
    if (*(s32 *)temp_2 != 1)
        func_0046d730(D_0063BE10, 0x68A);
    base = temp_19 + 0x3C;
    temp_4 = *(s32 *)(temp_19 + 0x40);
    if (temp_4 != 0) {
        func_00271b70(temp_4);
        *(s32 *)(base + 4) = 0;
    }
    temp_16 = *(u8 **)(temp_2 + 4);
    var_22 = *(u32 *)(base + 8);
    spA0 = (s32)*(s16 *)(temp_16 + 0x1A);
    var_21 = (s32 *)(temp_16 + 0x20);
    var_23 = 0;
    var_18 = 0;
    while ((s32)var_18 < (s32)spA0) {
        if (var_22 & 1U) {
            var_22 >>= 1;
        } else {
            func_002748e0(*var_21, 2, 0);
            if (func_00274650(8) != 0)
                var_23 |= 1U << var_18;
        }
        var_18 += 1;
        var_21++;
    }
    temp_5 = *(u32 *)(base + 8) | var_23;
    *(u32 *)(base + 8) = temp_5;
    temp_2_2 = func_00279fd0(*(s16 *)(temp_16 + 0x1A), temp_5);
    func_0027b750(arg0, 0, temp_2_2);
    func_0027bb60(arg0);
    temp_22 = func_0027b6e0(arg0, 0);
    temp_23 = func_0027b6e0(arg0, 1);
    spBC = func_0027b6e0(arg0, 2);
    func_00279ce0(temp_19 + 0x94);
    temp_4_2 = *(s32 *)(temp_19 + 8);
    if (temp_4_2 != 0)
        func_002738a0(temp_4_2);
    temp_21 = iGpffffb4b0;
    if (temp_21 == 0)
        iGpffffb4b0 = 0x7B;
    *(s32 *)(base + 4) = (s32)func_0027a010(
        (u32 *)(temp_16 + 0x20),
        *(s16 *)(temp_16 + 0x1A),
        *(u32 *)(base + 8),
        temp_22, temp_23, *(s32 *)(temp_19 + 0xC), spBC, 0);
    iGpffffb4b0 = temp_21;
    func_0027bbc0(arg0);
    *(s16 *)(base + 0x12) = (s16)temp_2_2;
    temp_3 = *(s32 *)temp_19 & ~0x38;
    *(s32 *)temp_19 = temp_3;
    temp_4_3 = temp_3 | 0x10;
    *(s32 *)temp_19 = temp_4_3;
    temp_3_2 = temp_4_3 & ~0xC00;
    *(s32 *)temp_19 = temp_3_2;
    *(s32 *)temp_19 = temp_3_2 | 0x400;
    *(s16 *)(base + 0xC) = 1;
    *(s32 *)base = arg1;
}
