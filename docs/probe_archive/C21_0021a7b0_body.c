/* FUN_0021A7B0 floor (v1, fndiff 393, obj 1492B/window 1712B, UNDER-220B).
 * Struct fills + dispatch, 10 calls exact, 4+3 saves (s0-s3+f20-22;
 * retail s0-s2+f20-24). Frame -432 vs -528.
 * WINS: 6 decls + 3 symbols (D_00628FA0, D_007615B4/B8); Vec2f-struct
 *   trick for 3657d0 (*(Vec2f*)&sp208pair, ld a0); s64 for 365ac0;
 *   D_00887314_abs 5-arg; (u8) convs with if/else+doubling.
 * WALLS: save gap (extra s3, missing f23/f24 — pressure); frame -96B;
 *   393 scattered rows. Complete, under-size floor.
 */
// FUN_0021A7B0 floor body (v1, fndiff 393, obj 1492B/window 1712B)
void func_0021a7b0(u8 *arg1) {
    struct { s32 lo; s32 hi; } sp208pair;
    f32 spB8;
    s32 spA8;
    f32 spA0;
    u8 sp80[48];
    u8 spC0[48];
    u8 sp100[48];
    u8 sp140[48];
    u8 sp180[48];
    u8 sp1C0[48];
    u8 sp60[24];
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f21;
    f32 var_f0;
    f32 var_f1_5;
    f32 var_f24;
    s32 var_16;
    u16 temp_16;
    u16 temp_4;
    s32 *temp_22;

    temp_22 = (s32 *)func_00452560(*(void **)(arg1 + 0x10));
    if ((*temp_22 & 1) == 0) {
        return;
    }
    temp_4 = *(u16 *)(arg1 + 0);
    if (temp_4 & 1) {
        if (!(temp_4 & 2)) {
            *(u16 *)(arg1 + 4) += 1;
            if (*(u16 *)(arg1 + 4) == 0x0E) {
                *(u16 *)(arg1 + 0) |= 2;
            }
        }
        temp_16 = *(u16 *)(arg1 + 4);
        func_00201350();
        func_002012d0((u8 *)temp_22, 0.0f, 0.0f);
        if (*(u16 *)(arg1 + 0) & 4) {
            var_f21 = 298.0f;
        } else {
            var_f21 = 181.0f;
        }
        if ((s32)temp_16 < 5) {
            var_f24 = 0.0f;
        } else if ((s32)temp_16 < 0x0E) {
            var_f24 = (f32)((s32)temp_16 - 5) / 9.0f;
        } else {
            var_f24 = 1.0f;
        }
        if (!(var_f24 <= 0.0f)) {
            u8 *var_6 = D_00628FA0;
            u8 *var_5 = sp60;
            s32 var_4 = 6;
            s32 t3;
            s32 t22;
            temp_f20 = D_008872F8[0];
            temp_f0 = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
            do {
                t3 = *(s16 *)var_6;
                t22 = *(s16 *)(var_6 + 2);
                var_6 += 4;
                var_4 -= 1;
                *(s16 *)var_5 = (s16)t3;
                *(s16 *)(var_5 + 2) = (s16)t22;
                var_5 += 4;
            } while (var_4 > 0);
            *(f32 *)(sp80 + 0) = -10.0f;
            *(f32 *)(sp80 + 4) = 95.0f;
            *(f32 *)(sp80 + 8) = temp_f20;
            *(f32 *)(sp80 + 0x18) = temp_f0;
            *(s32 *)(sp80 + 0x20) = 0;
            *(s32 *)(sp80 + 0x24) = 0;
            *(s32 *)(sp80 + 0x28) = 0;
            {
                f32 tf3 = 204.0f * var_f24;
                s32 v42 = (u8)tf3;
                if (v42 >= 0) {
                    *(f32 *)(sp80 + 0x2C) = (f32)v42;
                } else {
                    s32 q42 = ((u32)v42 >> 1) | (v42 & 1);
                    f32 g42 = (f32)q42;
                    g42 += g42;
                    *(f32 *)(sp80 + 0x2C) = g42;
                }
            }
            *(f32 *)(spC0 + 0) = -10.0f + 241.0f;
            *(f32 *)(spC0 + 4) = 95.0f;
            *(f32 *)(spC0 + 8) = temp_f20;
            *(f32 *)(spC0 + 0x18) = temp_f0;
            *(s32 *)(spC0 + 0x20) = 0;
            *(s32 *)(spC0 + 0x24) = 0;
            *(s32 *)(spC0 + 0x28) = 0;
            {
                f32 tf3b = 204.0f * var_f24;
                s32 v43 = (u8)tf3b;
                if (v43 >= 0) {
                    *(f32 *)(spC0 + 0x2C) = (f32)v43;
                } else {
                    s32 q43 = ((u32)v43 >> 1) | (v43 & 1);
                    f32 g43 = (f32)q43;
                    g43 += g43;
                    *(f32 *)(spC0 + 0x2C) = g43;
                }
            }
            {
                f32 tf2 = 95.0f + var_f21;
                *(f32 *)(sp100 + 0) = -10.0f;
                *(f32 *)(sp100 + 4) = tf2;
                *(f32 *)(sp100 + 8) = temp_f20;
                *(f32 *)(sp100 + 0x18) = temp_f0;
                *(s32 *)(sp100 + 0x20) = 0;
                *(s32 *)(sp100 + 0x24) = 0;
                *(s32 *)(sp100 + 0x28) = 0;
                {
                    f32 tf3c = 204.0f * var_f24;
                    s32 v44 = (u8)tf3c;
                    if (v44 >= 0) {
                        *(f32 *)(sp100 + 0x2C) = (f32)v44;
                    } else {
                        s32 q44 = ((u32)v44 >> 1) | (v44 & 1);
                        f32 g44 = (f32)q44;
                        g44 += g44;
                        *(f32 *)(sp100 + 0x2C) = g44;
                    }
                }
            }
            {
                *(f32 *)(sp140 + 0) = -10.0f + 241.0f;
                *(f32 *)(sp140 + 4) = 95.0f + var_f21;
                *(f32 *)(sp140 + 8) = temp_f20;
                *(f32 *)(sp140 + 0x18) = temp_f0;
                *(s32 *)(sp140 + 0x20) = 0;
                *(s32 *)(sp140 + 0x24) = 0;
                *(s32 *)(sp140 + 0x28) = 0;
                {
                    f32 tf3d = 204.0f * var_f24;
                    s32 v45 = (u8)tf3d;
                    if (v45 >= 0) {
                        *(f32 *)(sp140 + 0x2C) = (f32)v45;
                    } else {
                        s32 q45 = ((u32)v45 >> 1) | (v45 & 1);
                        f32 g45 = (f32)q45;
                        g45 += g45;
                        *(f32 *)(sp140 + 0x2C) = g45;
                    }
                }
            }
            {
                f32 tf1 = -10.0f + (f32)0x15D;
                *(f32 *)(sp180 + 0) = tf1;
                *(f32 *)(sp180 + 4) = 95.0f;
                *(f32 *)(sp180 + 8) = temp_f20;
                *(f32 *)(sp180 + 0x18) = temp_f0;
                *(s32 *)(sp180 + 0x20) = 0;
                *(s32 *)(sp180 + 0x24) = 0;
                *(s32 *)(sp180 + 0x28) = 0;
                *(s32 *)(sp180 + 0x2C) = 0;
                *(f32 *)(sp1C0 + 0) = tf1;
                *(f32 *)(sp1C0 + 4) = 95.0f + var_f21;
                *(f32 *)(sp1C0 + 8) = temp_f20;
                *(f32 *)(sp1C0 + 0x18) = temp_f0;
                *(s32 *)(sp1C0 + 0x20) = 0;
                *(s32 *)(sp1C0 + 0x24) = 0;
                *(s32 *)(sp1C0 + 0x28) = 0;
                *(s32 *)(sp1C0 + 0x2C) = 0;
            }
            D_00887300[0](1, 0);
            D_00887314_abs[0](3, sp80, 6, sp60, 12);
        }
        sp208pair.lo = 0x43FB0000;
        sp208pair.hi = 0x43570000;
        {
            s32 t16b = (s32)temp_16;
            if (t16b < 0) {
                var_f0 = 0.0f;
            } else if (t16b < 0x0A) {
                var_f0 = (f32)(s32)(func_0044b7b0(fGpffff84a4 * ((f32)t16b / 10.0f)));
            } else {
                var_f0 = 1.0f;
            }
            if (!(var_f0 <= 0.0f)) {
                func_003657d0(*(Vec2f *)&sp208pair, 0xCC, 0, 0, D_007615B4 * var_f0, D_007615B8 * var_f0);
            }
        }
        {
            s32 t16c = (s32)temp_16;
            if (t16c < 0) {
                var_f1_5 = 0.0f;
            } else if (t16c < 8) {
                var_f1_5 = (f32)(s32)(1.0f - func_0044b610(fGpffff84a4 * ((f32)t16c / 8.0f)));
            } else {
                var_f1_5 = 1.0f;
            }
            if (!(var_f1_5 <= 0.0f)) {
                func_00365ac0(*(s64 *)&sp208pair, 0x89FF1FFF, 1, 0, fGpffff84a4 * var_f1_5, 125.5f * var_f1_5, 16.0f);
            }
        }
    }
}
