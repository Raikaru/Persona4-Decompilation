/* FUN_002A4F20 floor (v2, fndiff 391, obj 1780B/window 1808B, UNDER-28B).
 * Loops + float fills + calls, 20 calls exact (452560 via funcptr-cast jalr),
 * 6+4 saves. Frame -128.
 * WINS: 2a66d0/25f3f0 floats-first (Wave-14 note; m2c s32-first wrong);
 *   2a9f50 o32 order (f32×3,s32,u8*,s32,s32,u8* with 5.0f not (u8*)bits);
 *   452560 void-call via funcptr-cast (proto takes void*, retail no arg);
 *   (s32)trunc for 2a6b60/6c30; gp-symbols pre-registered.
 * WALLS: s1-vs-s3 rotation; 452560 jalr-vs-jal; 385 scattered rows.
 *   Complete, under-size floor.
 */
// FUN_002A4F20 floor body (v2, fndiff 391, obj 1780B/window 1808B)
s32 func_002a4f20(s32 arg0) {
    extern f32 iGpffff8214;
    extern f32 iGpffff8084;
    extern f32 iGpffff8218;
    extern f32 iGpffff821c;
    extern f32 iGpffff8030;
    extern f32 D_00761184;
    f32 temp_f0;
    f32 temp_f21;
    f32 var_f1;
    f32 var_3;
    s32 temp_2_2;
    s32 var_20;
    s32 s0f0;
    s32 var_20_2;
    u8 *temp_2;

    temp_2 = ((u8 *(*)(void))func_00452560)();
    func_002a6b10(0, 0, 255, temp_2);
    func_002a7710(255, temp_2);
    temp_2_2 = *(s32 *)(temp_2 + 0x568);
    if (temp_2_2 < 0x0A) {
        var_f1 = (f32)temp_2_2 / 10.0f;
    } else {
        var_f1 = 1.0f;
    }
    temp_f0 = 255.0f * var_f1;
    func_002a6b60(0, 0, (s32)temp_f0, temp_2);
    func_002a6c30(0, 0, (s32)temp_f0, temp_2);
    s0f0 = (s32)temp_f0;
    temp_f21 = (f32)(s32)func_0044b7b0(iGpffff8214 * ((f32)*(s32 *)(temp_2 + 0x568) / 30.0f));
    {
        s32 t19 = (*(s32 *)(temp_2 + 0x3AC) << 16) >> 16;
        s32 t23 = *(s32 *)(temp_2 + 0x3B4);
        if (t23 != t19) {
            s32 t18 = t19 - t23;
            if ((f32)func_0043c6a0(t18) <= iGpffff8218 * (f32)t19) {
                *(s32 *)(temp_2 + 0x3B4) = t19;
            } else {
                f32 tf2 = (f32)t18;
                f32 tf02 = (f32)(s32)iGpffff821c;
                if (iGpffff821c * tf2 < tf02) {
                    var_3 = tf2 * 0.5f;
                } else {
                    var_3 = tf02;
                }
                *(s32 *)(temp_2 + 0x3B4) += (s32)var_3;
            }
        }
    }
    {
        s32 t182 = *(s32 *)(temp_2 + 0x3B4) >> 16;
        s32 t21 = t182 << 16;
        var_20 = 0;
        while (var_20 < 7) {
            s32 t192 = (t182 + var_20) - 3;
            if ((t192 >= 0) && (t192 < 0x10) && (((var_20 != 0) && (var_20 != 6)) || ((u16)*(s32 *)(temp_2 + 0x3B4) != 0))) {
                f32 tf23;
                f32 tf22;
                s32 t24 = t21 - *(s32 *)(temp_2 + 0x3B4);
                func_002a6960(0, 0, 0x280, 0x1C0, 5.0f);
                func_002a6960(0, 0, 0x280, 0x2D, 0.0f);
                func_002a6960(0, 0x195, 0x280, 0x30, 0.0f);
                tf23 = -59.0f + (f32)(var_20 * 0x1A) + ((f32)(t24 * 0x1A) / 65536.0f);
                tf22 = -152.0f + (f32)(var_20 * 0x5E) + ((f32)(t24 * 0x5E) / 65536.0f);
                func_002a7920(0xFF, temp_2 + 0x14, t192, 0, temp_2, tf23 - (350.0f * (1.0f - temp_f21)), tf22, 0, 1.0f);
                func_002a9f50(tf23, tf22, 5.0f, s0f0, temp_2 + 0x14, var_20, 0, temp_2);
            }
            var_20 += 1;
        }
    }
    func_0025f3f0(0.0f, 131.0f, 0.0f, 0xFFFFFF, 0xFF, 0x22, 0, *(s32 *)(temp_2 + 0x398), 1);
    {
        s32 t182b = *(s32 *)(temp_2 + 0x3B4) >> 16;
        s32 t21b = t182b << 16;
        var_20_2 = 0;
        while (var_20_2 < 7) {
            s32 t193 = (t182b + var_20_2) - 3;
            if ((t193 >= 0) && (t193 < 0x10) && (((t21b - *(s32 *)(temp_2 + 0x3B4)) != 0) || (t193 == t182b) || (t193 == t182b + 1))) {
                s32 t25 = t21b - *(s32 *)(temp_2 + 0x3B4);
                f32 tf222 = -59.0f + (f32)(var_20_2 * 0x1A) + ((f32)(t25 * 0x1A) / 65536.0f);
                f32 tf20 = -152.0f + (f32)(var_20_2 * 0x5E) + ((f32)(t25 * 0x5E) / 65536.0f);
                func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
                func_002a6960(0, 0x83, 0x280, 0x5E, 10.0f);
                func_002a9f50(tf222, tf20, 5.0f, s0f0, temp_2 + 0x14, var_20_2, 1, temp_2);
            }
            var_20_2 += 1;
        }
    }
    if ((*(s32 *)(temp_2 + 0x3AC) + 1) != 0) {
        f32 tf223;
        f32 tf202;
        func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
        {
            s32 t26 = *(s32 *)(temp_2 + 0x3B8);
            if (t26 > 0) {
                *(s32 *)(temp_2 + 0x3B8) = t26 - 1;
            }
        }
        tf223 = (f32)(s32)(1.0f + (iGpffff8030 * func_0044b7b0(iGpffff8084 * ((f32)*(s32 *)(temp_2 + 0x3B8) / 10.0f))));
        tf202 = 400.0f * (1.0f - temp_f21);
        func_002a66d0(72.0f - tf202, 179.0f, 0.0f, 124.0f * tf223, 116.0f * tf223, 0x2D2D2D, 0xFF, 1);
        func_002a7920(0xFF, temp_2 + 0x14, *(s32 *)(temp_2 + 0x3AC), 1, temp_2, 19.0f - tf202, 130.0f, 0, tf223);
    }
    {
        s32 t27 = *(s32 *)(temp_2 + 0x568) + 1;
        *(s32 *)(temp_2 + 0x568) = t27;
        if (t27 >= 0x1E) {
            *(s32 *)(temp_2 + 0x568) = 0;
            return 1;
        }
    }
    return 0;
}
