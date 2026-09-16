// func_0014c960 (0x0014c960-0x0014cef0, 1424B) — guarded floor @283fndiff/1324B (100B under; frame/saves/args match).
// Wins: trunc+mfc1 int-compare chains (m2c BITWISE wrong); c.le.s/bc1t not needed here; mult+addu-input
// idiom reproduced (162390 precedent); GPREL relocs present; all calls; return-1 flows without li.
// Walls: s0/s1/s2 temp rotation (decl-swap/assign-order inert); flag homes (var_2→s6 not v0-temp,
// var_10→s5 not t2; no-init experiment kept); temp rotations; stride-li reg; t5/t6 block-temps;
// D_007E80A0/D_007E8C00 absolute-vs-reloc phantoms.
// Unattempted before (no prior note). Production stays ASM.
s32 func_0014c960(s32 *arg0, s32 *arg1)
{
    s32 var_20;
    s32 var_19;
    u8 *temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 var_3;
    s32 var_2;
    u8 *var_18;
    s32 var_22;
    s32 var_9;
    s32 var_10;
    s32 stride;
    u8 *temp_8;
    s32 f0a;
    s32 f0b;
    u8 *t0e;
    s32 t21;
    s32 t32;
    s32 b0;
    s32 b1;
    s32 a1t;
    s32 a2t;
    s32 b1t;
    s32 o2;
    u8 *ae;

    var_20 = iGpffffb1fc;
    while (var_20 < 0x18) {
        var_19 = iGpffffb1f8;
        temp_17 = var_20 << 8;
        temp_16 = D_007D24B0 + var_20 * 2;
        for (; var_19 < 0x10; var_19++) {
            temp_18 = var_19 * 0x10;
            if (*(u8 *)(temp_17 + func_00155280() + temp_18 + 84) != 1) {
                continue;
            }
            if (*(u8 *)(temp_17 + func_00155280() + temp_18 + 88) == 9) {
            } else if (*(u8 *)(temp_17 + func_00155280() + temp_18 + 88) == 11) {
            } else if (*(u8 *)(temp_17 + func_00155280() + temp_18 + 88) != 13) {
                continue;
            }
            if ((*(u8 *)(temp_17 + func_00155280() + temp_18 + 85) & 0xF0) != 0x20) {
                continue;
            }
            if (((1 << var_19) & *(u16 *)temp_16) != 0) {
                continue;
            }
            {
                s32 t6 = var_19 + 1;
                s32 t5 = var_20 + 1;
                var_3 = 0;
                while (var_3 < 8) {
                temp_8 = D_007E80A0 + var_3 * 0x168;
                if (*(s32 *)temp_8 != 0) {
                    f0a = (s32)(((600.0f + *(f32 *)(temp_8 + 336)) / 1200.0f));
                    f0b = (s32)(((600.0f + *(f32 *)(temp_8 + 344)) / 1200.0f));
                    if ((f0a == var_19 && f0b == var_20) || (f0a == t6 && f0b == var_20) || (f0a == var_19 && f0b == t5) || (f0a == t6 && f0b == t5)) {
                        b0 = (1 << var_19) & 0xFFFF;
                        b1 = (1 << (var_19 + 1)) & 0xFFFF;
                        *(u16 *)temp_16 |= b0;
                        *(u16 *)temp_16 |= b1;
                        *(u16 *)(temp_16 + 2) |= b0;
                        *(u16 *)(temp_16 + 2) |= b1;
                        var_2 = 0;
                        break;
                    }
                }
                var_3++;
            }
            }
            if (var_2 != 0) {
                var_22 = 1;
                var_18 = func_001452b0(3);
                while (var_18 != NULL) {
                    t21 = (s32)(((600.0f + *(f32 *)(*(s32 *)(var_18 + 356) + 48)) / 1200.0f));
                    t32 = (s32)(((600.0f + *(f32 *)(*(s32 *)(var_18 + 356) + 56)) / 1200.0f));
                    {
                        s32 t6 = var_19 + 1;
                        s32 t5 = var_20 + 1;
                    if ((t21 == var_19 && t32 == var_20) || (t21 == t6 && t32 == var_20) || (t21 == var_19 && t32 == t5) || (t21 == t6 && t32 == t5)) {
                        b0 = (1 << var_19) & 0xFFFF;
                        b1 = (1 << (var_19 + 1)) & 0xFFFF;
                        *(u16 *)temp_16 |= b0;
                        *(u16 *)temp_16 |= b1;
                        *(u16 *)(temp_16 + 2) |= b0;
                        *(u16 *)(temp_16 + 2) |= b1;
                        var_22 = 0;
                        break;
                    }
                    }
                    var_18 = *(u8 **)(var_18 + 312);
                }
                if (var_22 != 0) {
                    var_10 = 1;
                    var_9 = 0;
                    stride = 1872;
                    while (var_9 < 15) {
                        t0e = D_007E8C00 + var_9 * stride;
                        if (*(s32 *)t0e != 0) {
                            f0a = (s32)(((600.0f + *(f32 *)(t0e + 412)) / 1200.0f));
                            f0b = (s32)(((600.0f + *(f32 *)(t0e + 420)) / 1200.0f));
                            {
                                s32 t6 = var_19 + 1;
                                s32 t5 = var_20 + 1;
                            if ((f0a == var_19 && f0b == var_20) || (f0a == t6 && f0b == var_20) || (f0a == var_19 && f0b == t5) || (f0a == t6 && f0b == t5)) {
                                b0 = (1 << var_19) & 0xFFFF;
                                b1 = (1 << (var_19 + 1)) & 0xFFFF;
                                *(u16 *)temp_16 |= b0;
                                *(u16 *)temp_16 |= b1;
                                *(u16 *)(temp_16 + 2) |= b0;
                                *(u16 *)(temp_16 + 2) |= b1;
                                var_10 = 0;
                                break;
                            }
                            }
                        }
                        var_9++;
                    }
                    if (var_10 != 0) {
                        *arg0 = var_19;
                        *arg1 = var_20;
                        a1t = 1 << var_19;
                        o2 = var_20 * 2;
                        ae = D_007D24B0 + o2;
                        a2t = a1t & 0xFFFF;
                        *(u16 *)ae |= a2t;
                        b1t = (1 << (var_19 + 1)) & 0xFFFF;
                        *(u16 *)ae |= b1t;
                        *(u16 *)(ae + 2) |= a2t;
                        *(u16 *)(ae + 2) |= b1t;
                        iGpffffb1fc = var_20;
                        iGpffffb1f8 = var_19;
                        return 1;
                    }
                }
            }
        }
        iGpffffb1f8 = 0;
        var_20++;
    }
    return 0;
}
