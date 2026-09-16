/* FUN_001496C0 draft (v3, fndiff 393, obj 1688B/window 1504B, OVER+184B — REVERTED per overrun gate).
 * List-walk + float compares + u8/u32 convs + calls. Saves s0/s1 (SWAPPED vs retail s1/s0).
 * WINS: plain-u32-conv idiom (c.le+bc1t, trunc, or-0x8000, no andi); temp_16 or-tree order
 *   ((a<<24)|(b<<16)|(c<<8)|d); 5 gp-byte symbols registered (ba5c/ba60/ba64/ba68 + existing ba4c);
 *   14a000/1538a0/457140/457160 decls; c.ole polarity matches head.
 * WALLS: s0/s1 rotation (decl-order inert); frame -48 vs -64 (sp3C reg-vs-stack, volatile inert);
 *   +184B overrun (~43 extra ins, not spills). Stop: overrun fails gate.
 */
void func_001496c0(u8 *arg0) {
    u8 *var_16;
    u32 temp_16;
    u32 var_4;
    u32 var_5;
    u32 var_6;
    u32 var_3;
    u8 var_3_2;
    u8 var_7;
    u8 var_6_2;
    u8 var_5_2;
    u8 *temp_2;

    var_16 = func_001452b0(12);
loop_2:
    if (var_16 != NULL) {
        func_001538a0(*(s32 *)(var_16 + 0x1A0), arg0);
        var_16 = *(u8 **)(var_16 + 0x138);
        goto loop_2;
    }
    if ((((*(f32 *)(arg0 + 0) <= 0.0f) && (*(f32 *)(arg0 + 4) <= 0.0f)) && (*(f32 *)(arg0 + 8) <= 0.0f)) || (*(f32 *)(arg0 + 0x0C) <= 0.0f)) {
        func_0014a000(0, 1);
    } else {
        func_0014a000(1, 1);
    }
    temp_2 = func_00457160();
    sp3C[0] = *(temp_2 + 0);
    sp3C[1] = *(temp_2 + 1);
    sp3C[2] = *(temp_2 + 2);
    sp3C[3] = *(temp_2 + 3);
    temp_16 = (iGpffffba68 << 24) | (iGpffffba5c << 16) | (iGpffffba60 << 8) | iGpffffba64;
    {
        f32 f0;
        if ((s32)sp3C[0] >= 0) {
            f0 = (f32)sp3C[0];
        } else {
            s32 u0 = ((u32)sp3C[0] >> 1) | (sp3C[0] & 1);
            f0 = (f32)u0;
            f0 += f0;
        }
        {
            u32 v4;
            f32 t1 = f0 * *(f32 *)(arg0 + 0);
            if (2147483648.0f <= t1) {
                v4 = (s32)(t1 - 2147483648.0f);
                v4 |= 0x80000000;
            } else {
                v4 = (s32)t1;
            }
            var_4 = v4;
        }
    }
    {
        f32 f1;
        if ((s32)sp3C[1] >= 0) {
            f1 = (f32)sp3C[1];
        } else {
            s32 u1 = ((u32)sp3C[1] >> 1) | (sp3C[1] & 1);
            f1 = (f32)u1;
            f1 += f1;
        }
        {
            u32 v5;
            f32 t2 = f1 * *(f32 *)(arg0 + 4);
            if (2147483648.0f <= t2) {
                v5 = (s32)(t2 - 2147483648.0f);
                v5 |= 0x80000000;
            } else {
                v5 = (s32)t2;
            }
            var_5 = v5;
        }
    }
    {
        f32 f2;
        if ((s32)sp3C[2] >= 0) {
            f2 = (f32)sp3C[2];
        } else {
            s32 u2 = ((u32)sp3C[2] >> 1) | (sp3C[2] & 1);
            f2 = (f32)u2;
            f2 += f2;
        }
        {
            u32 v6;
            f32 t3 = f2 * *(f32 *)(arg0 + 8);
            if (2147483648.0f <= t3) {
                v6 = (s32)(t3 - 2147483648.0f);
                v6 |= 0x80000000;
            } else {
                v6 = (s32)t3;
            }
            var_6 = v6;
        }
    }
    {
        f32 f3;
        if ((s32)sp3C[3] >= 0) {
            f3 = (f32)sp3C[3];
        } else {
            s32 u3 = ((u32)sp3C[3] >> 1) | (sp3C[3] & 1);
            f3 = (f32)u3;
            f3 += f3;
        }
        {
            u32 v3;
            f32 t4 = f3 * *(f32 *)(arg0 + 0x0C);
            if (2147483648.0f <= t4) {
                v3 = (s32)(t4 - 2147483648.0f);
                v3 |= 0x80000000;
            } else {
                v3 = (s32)t4;
            }
            var_3 = v3;
        }
    }
    if (var_3 >= 0x100) {
        var_3 = 0xFF;
    }
    if (var_6 >= 0x100) {
        var_6 = 0xFF;
    }
    if (var_5 >= 0x100) {
        var_5 = 0xFF;
    }
    if (var_4 >= 0x100) {
        var_4 = 0xFF;
    }
    func_00457140(var_4 & 0xFF, var_5 & 0xFF, var_6 & 0xFF, var_3 & 0xFF);
    {
        s32 t3 = (temp_16 >> 16) & 0xFF;
        f32 g0;
        if (t3 >= 0) {
            g0 = (f32)t3;
        } else {
            s32 w0 = ((u32)t3 >> 1) | (t3 & 1);
            g0 = (f32)w0;
            g0 += g0;
        }
        {
            u32 c0;
            f32 h1 = g0 * *(f32 *)(arg0 + 0);
            if (2147483648.0f <= h1) {
                c0 = (s32)(h1 - 2147483648.0f);
                c0 |= 0x80000000;
            } else {
                c0 = (s32)h1;
            }
            var_3_2 = c0;
        }
    }
    {
        s32 t4 = (temp_16 >> 8) & 0xFF;
        f32 g1;
        if (t4 >= 0) {
            g1 = (f32)t4;
        } else {
            s32 w1 = ((u32)t4 >> 1) | (t4 & 1);
            g1 = (f32)w1;
            g1 += g1;
        }
        {
            u32 c1;
            f32 h2 = g1 * *(f32 *)(arg0 + 4);
            if (2147483648.0f <= h2) {
                c1 = (s32)(h2 - 2147483648.0f);
                c1 |= 0x80000000;
            } else {
                c1 = (s32)h2;
            }
            var_7 = c1;
        }
    }
    {
        s32 t5 = temp_16 & 0xFF;
        f32 g2;
        if (t5 >= 0) {
            g2 = (f32)t5;
        } else {
            s32 w2 = ((u32)t5 >> 1) | (t5 & 1);
            g2 = (f32)w2;
            g2 += g2;
        }
        {
            u32 c2;
            f32 h3 = g2 * *(f32 *)(arg0 + 8);
            if (2147483648.0f <= h3) {
                c2 = (s32)(h3 - 2147483648.0f);
                c2 |= 0x80000000;
            } else {
                c2 = (s32)h3;
            }
            var_6_2 = c2;
        }
    }
    {
        s32 t6 = (temp_16 >> 24) & 0xFF;
        f32 g3;
        if (t6 >= 0) {
            g3 = (f32)t6;
        } else {
            s32 w3 = ((u32)t6 >> 1) | (t6 & 1);
            g3 = (f32)w3;
            g3 += g3;
        }
        {
            u32 c3;
            f32 h4 = g3 * *(f32 *)(arg0 + 0x0C);
            if (2147483648.0f <= h4) {
                c3 = (s32)(h4 - 2147483648.0f);
                c3 |= 0x80000000;
            } else {
                c3 = (s32)h4;
            }
            var_5_2 = c3;
        }
    }
    if (var_3_2 >= 0x100) {
        var_3_2 = 0xFF;
    }
    iGpffffba4c = var_3_2;
    if (var_7 >= 0x100) {
        var_7 = 0xFF;
    }
    iGpffffba50 = var_7;
    if (var_6_2 >= 0x100) {
        var_6_2 = 0xFF;
    }
    iGpffffba54 = var_6_2;
    if (var_5_2 >= 0x100) {
        var_5_2 = 0xFF;
    }
    iGpffffba58 = var_5_2;
}
