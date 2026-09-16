/* FUN_0013AD40 draft (v1, fndiff 461, obj 1964B/window 1584B, OVER+380B — REVERTED per overrun gate).
 * 3-arg fills + clamps + loop, 7 calls. Frame -160 vs -224 (missing 4 int + 5 float saves).
 * WINS: 6 D_0064B2xx array decls; (u8)-free plain-u32 convs; *(s64*)& for 11fd50 (0013fb50 precedent).
 * WALLS: pressure gap (retail 9+5 saves, mine 5+0 — code too efficient, temps die);
 *   +380B overrun (~95 extra ins); 461 scattered rows. Stop: overrun fails gate.
 */
void func_0013ad40(u8 *arg0, s32 arg1, s32 arg2) {
    s32 spD8;
    s16 spD6;
    s16 spD0;
    f32 spCC;
    f32 spC8;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f23x;
    f32 var_f24;
    s32 var_23;
    s32 var_2;
    s32 var_21;
    s32 var_3;
    s32 var_5;
    s32 var_6;
    s32 var_4;
    s32 temp_21;
    u8 *var_17;
    u8 *var_18;
    u8 *t32;
    void *var_16;
    s16 temp_30;
    u8 temp_2;

    var_23 = 0;
    var_f24 = 1.0f;
    temp_30 = *(s16 *)((arg1 * 2) + arg0 + 0xF4);
    temp_f22 = (f32)*(s32 *)(arg0 + 4);
    temp_f21 = (f32)*(s32 *)(arg0 + 8);
    temp_2 = *(arg0 + 0);
    if ((s32)temp_2 >= 0) {
        temp_f23x = (f32)temp_2 / 255.0f;
    } else {
        s32 uu = ((u32)temp_2 >> 1) | (temp_2 & 1);
        f32 vf1 = (f32)uu;
        vf1 += vf1;
        temp_f23x = vf1 / 255.0f;
    }
    func_0011fd30(&spD0);
    spD8 = 1;
    spD0 = temp_30;
    if ((*(s16 *)((arg2 * 2) + arg0 + 0x5C) == arg1) || (*(s32 *)(arg0 + 0x1C) & 0x100)) {
        if ((arg2 == 0) && (*(s32 *)(arg0 + 0x1C) & 0x10)) {
            spD6 = 2;
            var_18 = D_0064B2F4;
            var_17 = D_0064B2F0;
            var_16 = D_0064B30C;
        } else {
            var_23 = 1;
            spD6 = 1;
            var_18 = D_0064B2E8;
            var_17 = D_0064B2EC;
            var_16 = D_0064B2FC;
        }
    } else {
        spD6 = 0;
        var_18 = D_0064B2E0;
        var_17 = D_0064B2F0;
        var_16 = D_0064B308;
        var_f24 = (f32)(s32)fGpffff82cc;
    }
    if (arg2 == 0) {
        var_2 = 5;
        var_21 = 1;
    } else {
        var_2 = 0x1C;
        var_21 = 0x18;
    }
    {
        u8 *t3 = (u8 *)((var_2 + arg1) * 0x30 + arg0);
        f32 f12t = 67.0f + (temp_f22 + *(f32 *)(t3 + 0x594));
        f32 f20 = 75.0f * (f32)arg1;
        f32 f13t = 24.0f + (temp_f21 + *(f32 *)(t3 + 0x598)) + f20;
        u8 b0 = *(t3 + 0x59E);
        f32 g0;
        u32 c0;
        f32 h1;
        spC8 = (f32)(s32)f12t;
        spCC = (f32)(s32)f13t;
        if ((s32)b0 >= 0) {
            g0 = (f32)b0;
        } else {
            s32 q0 = ((u32)b0 >> 1) | (b0 & 1);
            g0 = (f32)q0;
            g0 += g0;
        }
        h1 = g0 * temp_f23x;
        if (2147483648.0f <= h1) {
            c0 = (s32)(h1 - 2147483648.0f);
            c0 |= 0x80000000;
        } else {
            c0 = (s32)h1;
        }
        var_3 = c0;
        func_0011fd50(*(s64 *)&f12t, var_3 & 0xFF, &spD0, 0, 0.0f);
    }
    t32 = (u8 *)((var_21 + arg1) * 0x30 + arg0);
    {
        f32 f12b = 60.0f + (temp_f22 + *(f32 *)(t32 + 0x594));
        f32 f20b = 75.0f * (f32)arg1;
        f32 f13b = 21.0f + (temp_f21 + *(f32 *)(t32 + 0x598)) + f20b;
        u8 b1 = *(t32 + 0x59E);
        f32 gg;
        u32 c1;
        f32 h2;
        spC8 = f12b;
        spCC = f13b;
        if ((s32)b1 >= 0) {
            gg = (f32)b1;
        } else {
            s32 q1 = ((u32)b1 >> 1) | (b1 & 1);
            gg = (f32)q1;
            gg += gg;
        }
        h2 = gg * temp_f23x;
        if (2147483648.0f <= h2) {
            c1 = (s32)(h2 - 2147483648.0f);
            c1 |= 0x80000000;
        } else {
            c1 = (s32)h2;
        }
        temp_21 = c1 & 0xFF;
        func_0034f2e0(*(void **)(arg0 + 0x12BC), var_18[0], var_18[1], var_18[2], temp_21, f12b, spCC);
    }
    if (var_23 != 0) {
        f32 f12c = 2.0f + (temp_f22 + *(f32 *)(t32 + 0x594));
        f32 f20c = 75.0f * (f32)arg1;
        f32 f13c = 27.0f + (temp_f21 + *(f32 *)(t32 + 0x598)) + f20c;
        spC8 = f12c;
        spCC = f13c;
        func_0034f2e0(*(void **)(arg0 + 0x12C0), 0x4C, 0x4C, 0x4C, temp_21, f12c, f13c);
    }
    {
        s64 v182 = (s64)((func_00104c70(temp_30) & 0xFF) << 48) >> 48;
        f32 f2 = 43.0f + (temp_f22 + *(f32 *)(t32 + 0x594));
        f32 f25 = 25.0f + (temp_f21 + *(f32 *)(t32 + 0x598) + 75.0f * (f32)arg1);
        spC8 = f2;
        spCC = f25;
        if (v182 < 10) {
            spC8 = f2 - 11.0f;
        }
        while (v182 > 0) {
            s64 t24 = v182;
            u8 *dst = arg0 + ((t24 % 10) * 4);
            func_0034f2e0(*(void **)(dst + 0x12C4), var_17[0], var_17[1], var_17[2], temp_21, spC8, spCC);
            spC8 -= 22.0f;
            spCC -= 22.0f;
            v182--;
        }
    }
}
