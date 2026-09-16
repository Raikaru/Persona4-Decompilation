void *func_00495160(u8 *arg0) {
    typedef signed __int128 s128;
    s128 spD0;
    s128 spC0;
    s128 spB0;
    s128 spA0;
    void *temp_2;
    void *temp_22;
    void **var_19;
    f32 temp_30;
    f32 temp_f1;
    f32 var_f7;
    u32 temp_23;
    u32 temp_17;
    u32 temp_16;
    u32 temp_22b;
    s32 temp_7;
    s32 temp_lo;
    u32 var_18;
    u32 var_10;
    u8 *var_9;

    temp_23 = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713E50, 0x50);
    temp_2 = (void *)(*jtbl_008873E8)(temp_23 * 0x10 + 4, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_00713E50, 0x51);
    }
    *(void **)temp_2 = (void *)((u8 *)temp_2 + 4);
    if (*(u32 *)(arg0 + 0x3C) < 3U) {
        *(u32 *)(arg0 + 0x3C) = 3U;
    }
    spD0 = (s128)((*(u32 *)(arg0 + 0x70) << 8) >> 8);
    spC0 = (s128)((*(u32 *)(arg0 + 0x74) << 8) >> 8);
    spB0 = (s128)((*(u32 *)(arg0 + 0x78) << 8) >> 8);
    temp_17 = *(u32 *)(arg0 + 0x70) >> 24;
    temp_16 = *(u32 *)(arg0 + 0x74) >> 24;
    temp_22b = *(u32 *)(arg0 + 0x78) >> 24;
    var_19 = (void **)(*(void **)temp_2);
    temp_f1 = (f32)(*(u32 *)(arg0 + 0x3C) + 1);
    temp_30 = (f32)(s32)(*(f32 *)(arg0 + 0x68) * temp_f1);
    spA0 = (s128)(s32)(*(f32 *)(arg0 + 0x6C) * temp_f1);
    var_18 = 0;
    while (var_18 < temp_23) {
        temp_22 = (void *)func_00482dc0((u16)*(u32 *)(arg0 + 0x3C), D_00713360, 5, 0x48);
        *var_19 = (void *)temp_22;
        temp_lo = (s16)*(s16 *)((u8 *)temp_22 + 8) / 5;
        var_9 = (u8 *)(*(u8 **)(*(u8 **)(*(u8 **)((u8 *)temp_22 + 0x10) + 0x18) + 0x30));
        var_10 = 0;
        temp_7 = temp_lo - (s32)spA0;
        while (var_10 < (u32)temp_lo) {
            if (var_10 < (u32)temp_30) {
                f32 vf0;
                if ((s32)var_10 >= 0) {
                    vf0 = (f32)var_10;
                } else {
                    s32 q = ((u32)var_10 >> 1) | (var_10 & 1);
                    vf0 = (f32)q;
                    vf0 += vf0;
                }
                var_f7 = vf0 / temp_30;
            } else if ((s32)spA0 < (s32)var_10) {
                s32 t11 = temp_lo - var_10;
                f32 g2;
                f32 g1;
                if (t11 >= 0) {
                    g2 = (f32)t11;
                } else {
                    s32 q11 = ((u32)t11 >> 1) | (t11 & 1);
                    g2 = (f32)q11;
                    g2 += g2;
                }
                if (temp_7 >= 0) {
                    g1 = (f32)temp_7;
                } else {
                    s32 q7 = ((u32)temp_7 >> 1) | (temp_7 & 1);
                    g1 = (f32)q7;
                    g1 += g1;
                }
                var_f7 = g2 / g1;
            } else {
                var_f7 = 1.0f;
            }
            {
                f32 tf0;
                if ((s32)temp_22b >= 0) {
                    tf0 = (f32)temp_22b * var_f7;
                } else {
                    s32 qb = ((u32)temp_22b >> 1) | (temp_22b & 1);
                    f32 gb = (f32)qb;
                    gb += gb;
                    tf0 = gb * var_f7;
                }
                if (tf0 >= 2.1474836e9f) {
                    *(s32 *)(var_9 + 0) = (s32)spB0 | ((((s32)(tf0 - 2.1474836e9f)) | 0x80000000) << 24);
                } else {
                    *(s32 *)(var_9 + 0) = (s32)spB0 | (((s32)tf0) << 24);
                }
            }
            {
                f32 tf02;
                if ((s32)temp_16 >= 0) {
                    tf02 = (f32)temp_16 * var_f7;
                } else {
                    s32 qg = ((u32)temp_16 >> 1) | (temp_16 & 1);
                    f32 gg = (f32)qg;
                    gg += gg;
                    tf02 = gg * var_f7;
                }
                if (tf02 >= 2.1474836e9f) {
                    *(s32 *)(var_9 + 4) = (s32)spC0 | ((((s32)(tf02 - 2.1474836e9f)) | 0x80000000) << 24);
                } else {
                    *(s32 *)(var_9 + 4) = (s32)spC0 | (((s32)tf02) << 24);
                }
            }
            {
                f32 tf03;
                if ((s32)temp_17 >= 0) {
                    tf03 = (f32)temp_17 * var_f7;
                } else {
                    s32 qr = ((u32)temp_17 >> 1) | (temp_17 & 1);
                    f32 gr = (f32)qr;
                    gr += gr;
                    tf03 = gr * var_f7;
                }
                if (tf03 >= 2.1474836e9f) {
                    *(s32 *)(var_9 + 8) = (s32)spD0 | ((((s32)(tf03 - 2.1474836e9f)) | 0x80000000) << 24);
                } else {
                    *(s32 *)(var_9 + 8) = (s32)spD0 | (((s32)tf03) << 24);
                }
            }
            *(u8 *)(var_9 + 0x0C) = (u8)*(s32 *)(var_9 + 4);
            *(u8 *)(var_9 + 0x0D) = *(u8 *)(var_9 + 5);
            *(u8 *)(var_9 + 0x0E) = *(u8 *)(var_9 + 6);
            *(u8 *)(var_9 + 0x0F) = *(u8 *)(var_9 + 7);
            *(u8 *)(var_9 + 0x10) = (u8)*(s32 *)(var_9 + 0);
            *(u8 *)(var_9 + 0x11) = *(u8 *)(var_9 + 1);
            *(u8 *)(var_9 + 0x12) = *(u8 *)(var_9 + 2);
            *(u8 *)(var_9 + 0x13) = *(u8 *)(var_9 + 3);
            var_10 += 1;
            var_9 += 0x14;
        }
        *(s32 *)((u8 *)var_19 + 4) = -1 - (var_18 * 4);
        *(s32 *)((u8 *)var_19 + 0x0C) = 0;
        var_18 += 1;
        var_19 += 4;
    }
    return temp_2;
}

Overrun-reverted (+444B, 1660/1216, 374 scattered no bulk>16). s128-locals + u32-conv + reassign-double + nested loops complete (3+1 calls). No new decls/symbols (all existed). 24-bit shifts + s128 spills likely over-cost. Do not re-probe without new lever.
