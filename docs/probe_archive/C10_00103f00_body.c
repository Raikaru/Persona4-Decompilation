/* FUN_00103F00 draft (v10, fndiff 354, obj 1572B/window 1488B, OVER+84B — REVERTED per overrun gate).
 * Two-pass u8->float + fills + calls. Frame -144, saves s0-s4+f20 (f20 fixed via volatile sp88/8C).
 * WINS: 457120 4-arg calls are phantom (void calls, stale regs); bytes as s32 (no andi-FF);
 *   (u8) not needed (s32 bytes, bltz kept); D_008872F8 via absolute v0-base (extern f32);
 *   temp_7 reuse in or (no &1 recompute); srl via (u32) cast.
 * WALLS: LICM hoists loop-invariant or to preheader (for/goto/do-while + opt_loop_invariants off all inert);
 *   counter a3-vs-t1; temp_f5 f0-vs-f5; +84B overrun from pressure spills (20 float vars).
 *   Stop: overrun fails gate; revert, do not bank.
 */
void func_00103f00(u8 *arg0) {
    f32 temp_f20;
    f32 temp_f5;
    volatile f32 sp88;
    volatile f32 sp8C;
    s32 temp_7;
    s32 temp_6;
    s32 temp_5;
    s32 temp_4;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_20;
    s32 i;
    u8 *t8;
    u8 sp70area[24];
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 k0;
    f32 k1;
    f32 k2;
    f32 k3;

    func_00457120();
    temp_20 = *(arg0 + 0x1F);
    if (temp_20 != 0) {
        temp_f20 = *(f32 *)(arg0 + 0x20);
        temp_19 = *(arg0 + 0x1E);
        temp_18 = *(arg0 + 0x1D);
        temp_17 = *(arg0 + 0x1C);
        temp_f5 = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
        temp_7 = temp_17 & 1;
        temp_6 = temp_18 & 1;
        temp_5 = temp_19 & 1;
        temp_4 = temp_20 & 1;
        i = 0;
        do {
            t8 = arg0 + (i << 6);
            if (temp_17 >= 0) {
                f0 = (f32)temp_17;
            } else {
                s32 u0 = ((u32)temp_17 >> 1) | temp_7;
                f0 = (f32)u0;
                f0 += f0;
            }
            *(f32 *)(t8 + 0x180) = f0;
            if (temp_18 >= 0) {
                f1 = (f32)temp_18;
            } else {
                s32 u1 = ((u32)temp_18 >> 1) | temp_6;
                f1 = (f32)u1;
                f1 += f1;
            }
            *(f32 *)(t8 + 0x184) = f1;
            if (temp_19 >= 0) {
                f2 = (f32)temp_19;
            } else {
                s32 u2 = ((u32)temp_19 >> 1) | temp_5;
                f2 = (f32)u2;
                f2 += f2;
            }
            *(f32 *)(t8 + 0x188) = f2;
            if (temp_20 >= 0) {
                f3 = (f32)temp_20;
            } else {
                s32 u3 = ((u32)temp_20 >> 1) | temp_4;
                f3 = (f32)u3;
                f3 += f3;
            }
            *(f32 *)(t8 + 0x18C) = f3;
            *(f32 *)(t8 + 0x168) = D_008872F8 - temp_f20;
            *(f32 *)(t8 + 0x178) = temp_f5;
            i++;
        } while (i < 4);
        sp88 = (f32)*(s32 *)(arg0 + 0x0C);
        sp8C = (f32)*(s32 *)(arg0 + 0x10);
        {
            f32 f7;
            f32 f6;
            f32 f22;
            f32 f55;
            f32 f4;
            f32 f33;
            f32 f11;
            f32 f00;
            f7 = (f32)(s32)((512.0f * *(f32 *)(arg0 + 0x28)) / 2.0f);
            f6 = (f32)(s32)((256.0f * *(f32 *)(arg0 + 0x2C)) / 2.0f);
            f22 = 256.0f + sp88;
            f55 = f22 - f7;
            *(f32 *)(arg0 + 0x160) = f55;
            f4 = 128.0f + sp8C;
            f33 = f4 - f6;
            *(f32 *)(arg0 + 0x164) = f33;
            f11 = (f22 + f7) - 1.0f;
            *(f32 *)(arg0 + 0x1A0) = f11;
            *(f32 *)(arg0 + 0x1A4) = f33;
            *(f32 *)(arg0 + 0x1E0) = f55;
            f00 = (f4 + f6) - 1.0f;
            *(f32 *)(arg0 + 0x1E4) = f00;
            *(f32 *)(arg0 + 0x220) = f11;
            *(f32 *)(arg0 + 0x224) = f00;
        }
        func_00457120();
        *(s32 *)(arg0 + 0x170) = 0;
        *(s32 *)(arg0 + 0x174) = 0;
        *(s32 *)(arg0 + 0x1B0) = 0x3F800000;
        *(s32 *)(arg0 + 0x1B4) = 0;
        *(s32 *)(arg0 + 0x1F0) = 0;
        *(s32 *)(arg0 + 0x1F4) = 0x3F800000;
        *(s32 *)(arg0 + 0x230) = 0x3F800000;
        *(s32 *)(arg0 + 0x234) = 0x3F800000;
        func_00460b60(D_00796460, 1, *(s32 *)(arg0 + 0x14));
        func_00461390(D_00796460, 4, arg0 + 0x160, 4);
        if (*(s32 *)(arg0 + 0x4C) >= 2) {
            s32 t20b;
            s32 t19b;
            s32 t18b;
            s32 t17b;
            s32 j;
            t20b = *(arg0 + 0x1F);
            if ((t20b == 0xFF) && (*(s32 *)(arg0 + 0x50) != 0)) {
                if (*(s32 *)(arg0 + 0x54) != 0) {
                    t19b = *(arg0 + 0x1E);
                    t18b = *(arg0 + 0x1D);
                    t17b = *(arg0 + 0x1C);
                    temp_f20 = *(f32 *)(arg0 + 0x20);
                    temp_f5 = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
                    temp_7 = t17b & 1;
                    temp_6 = t18b & 1;
                    temp_5 = t19b & 1;
                    temp_4 = t20b & 1;
                    j = 0;
                    do {
                        u8 *kb;
                        kb = arg0 + (j << 6);
                        if (t17b >= 0) {
                            k0 = (f32)t17b;
                        } else {
                            s32 w0 = ((u32)t17b >> 1) | temp_7;
                            k0 = (f32)w0;
                            k0 += k0;
                        }
                        *(f32 *)(kb + 0x280) = k0;
                        if (t18b >= 0) {
                            k1 = (f32)t18b;
                        } else {
                            s32 w1 = ((u32)t18b >> 1) | temp_6;
                            k1 = (f32)w1;
                            k1 += k1;
                        }
                        *(f32 *)(kb + 0x284) = k1;
                        if (t19b >= 0) {
                            k2 = (f32)t19b;
                        } else {
                            s32 w2 = ((u32)t19b >> 1) | temp_5;
                            k2 = (f32)w2;
                            k2 += k2;
                        }
                        *(f32 *)(kb + 0x288) = k2;
                        if (t20b >= 0) {
                            k3 = (f32)t20b;
                        } else {
                            s32 w3 = ((u32)t20b >> 1) | temp_4;
                            k3 = (f32)w3;
                            k3 += k3;
                        }
                        *(f32 *)(kb + 0x28C) = k3;
                        *(f32 *)(kb + 0x268) = D_008872F8 - temp_f20;
                        *(f32 *)(kb + 0x278) = temp_f5;
                        j++;
                    } while (j < 4);
                    {
                        f32 g8;
                        f32 g7;
                        f32 g6;
                        f32 g2;
                        f32 g5;
                        f32 g4;
                        f32 g3;
                        f32 g1;
                        f32 g0;
                        g8 = (f32)*(s32 *)(arg0 + 0x360);
                        g7 = (f32)(s32)((512.0f * *(f32 *)(arg0 + 0x28)) / 2.0f);
                        g6 = (f32)(s32)((64.0f * *(f32 *)(arg0 + 0x2C)) / 2.0f);
                        g2 = 256.0f + sp88;
                        g5 = g2 - g7;
                        *(f32 *)(arg0 + 0x260) = g5;
                        g4 = 32.0f + sp8C;
                        g3 = g8 + (g4 - g6);
                        *(f32 *)(arg0 + 0x264) = g3;
                        g1 = (g2 + g7) - 1.0f;
                        *(f32 *)(arg0 + 0x2A0) = g1;
                        *(f32 *)(arg0 + 0x2A4) = g3;
                        *(f32 *)(arg0 + 0x2E0) = g5;
                        g0 = (g8 + (g4 + g6)) - 1.0f;
                        *(f32 *)(arg0 + 0x2E4) = g0;
                        *(f32 *)(arg0 + 0x320) = g1;
                        *(f32 *)(arg0 + 0x324) = g0;
                    }
                    func_00457120();
                    *(s32 *)(arg0 + 0x270) = 0;
                    *(s32 *)(arg0 + 0x274) = 0;
                    *(s32 *)(arg0 + 0x2B0) = 0x3F800000;
                    *(s32 *)(arg0 + 0x2B4) = 0;
                    *(s32 *)(arg0 + 0x2F0) = 0;
                    *(s32 *)(arg0 + 0x2F4) = 0x3F800000;
                    *(s32 *)(arg0 + 0x330) = 0x3F800000;
                    *(s32 *)(arg0 + 0x334) = 0x3F800000;
                    func_00460b60(D_00796460, 1, *(s32 *)(arg0 + 0x18));
                    func_00461390(D_00796460, 4, arg0 + 0x260, 4);
                }
            }
        }
        {
            u8 *tab;
            u8 *dst;
            s32 n;
            s32 c0;
            s32 c1;
            tab = D_005DD680;
            dst = sp70area;
            n = 3;
            do {
                c0 = *(s32 *)tab;
                c1 = *(s32 *)(tab + 4);
                tab += 8;
                n -= 1;
                *(s32 *)dst = c0;
                *(s32 *)(dst + 4) = c1;
                dst += 8;
            } while (n > 0);
            c0 = *(s32 *)(arg0 + 0x58) - 1;
            *(s32 *)(arg0 + 0x58) = c0;
            if (c0 <= 0) {
                if (*(s32 *)(arg0 + 0x54) != 0) {
                    *(s32 *)(arg0 + 0x54) = 0;
                } else {
                    *(s32 *)(arg0 + 0x54) = 1;
                }
                c1 = *(s32 *)(arg0 + 0x5C) + 1;
                *(s32 *)(arg0 + 0x5C) = c1;
                c1 = c1 % 6;
                *(s32 *)(arg0 + 0x5C) = c1;
                *(s32 *)(arg0 + 0x58) = *(s32 *)(sp70area + c1 * 4);
            }
        }
    }
}
