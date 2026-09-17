s32 func_00275d80(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5, u32 arg6, f32 fparg0) {
    u8 stk[336];
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    s32 temp_19;
    u8 *temp_17;
    s32 var_4;
    u8 *var_20;

    temp_f22 = (f32)arg0 / 16.0f;
    temp_f21 = (f32)arg1 / 8.0f;
    temp_f20 = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    {
        u8 *v7 = D_0063BCC0;
        u8 *v6 = stk;
        s32 v4 = 4;
        s32 t3;
        s32 t2;
        do {
            t3 = *(s32 *)v7;
            t2 = *(s32 *)(v7 + 4);
            v7 += 8;
            v4 -= 1;
            *(s32 *)v6 = t3;
            *(s32 *)(v6 + 4) = t2;
            v6 += 8;
        } while (v4 > 0);
    }
    sp80 = temp_f22;
    sp84 = temp_f21;
    if (arg4 >= 0) {
        sp88 = temp_f22 + (f32)arg4;
    } else {
        s32 uu = ((u32)arg4 >> 1) | (arg4 & 1);
        f32 vf0 = (f32)uu;
        vf0 += vf0;
        sp88 = temp_f22 + vf0;
    }
    sp8C = temp_f21;
    sp90 = temp_f22;
    if (arg5 >= 0) {
        sp94 = temp_f21 + (f32)arg5;
    } else {
        s32 uu2 = ((u32)arg5 >> 1) | (arg5 & 1);
        f32 vf02 = (f32)uu2;
        vf02 += vf02;
        sp94 = temp_f21 + vf02;
    }
    sp98 = sp88;
    sp9C = sp94;
    temp_19 = arg6 & 0xFF;
    if (*(u8 **)(arg2 + 0x1C) == NULL) {
        func_0046d730(&D_0063BC88, 0x9B);
    }
    var_20 = *(u8 **)(*(u8 **)(arg2 + 0x1C) + 0x0C);
    if (*(s16 *)(var_20 + 8) != arg3) {
        temp_17 = (u8 *)func_00271f50((u32 *)arg2, *(s32 *)(var_20 + 4));
        *(u16 *)((*(u8 **)(arg2 + 0x1C)) + 4) -= 1;
        {
            u8 *t5 = *(u8 **)(arg2 + 0x1C);
            if ((t5 != NULL) && (*(u16 *)(t5 + 4) == 0)) {
                u8 *t4 = *(u8 **)(t5 + 0x0C);
                if (t4 != NULL) {
                    *(s32 *)(t4 + 0) &= ~1;
                    *(s32 *)(t4 + 0x10) = 0;
                }
                func_00271310(*(s32 *)(t5 + 8));
                D_00881750 -= 1;
            }
        }
        *(u8 **)(arg2 + 0x1C) = temp_17;
        var_20 = *(u8 **)(temp_17 + 0x0C);
    }
    *(s32 *)(var_20 + 0) |= 1;
    if (temp_19 == 0) {
        return 0;
    }
    func_0043f9c8(stk, 0, 0x100);
    {
        s32 v22 = 0;
        s32 t10 = (arg6 >> 24) & 0xFF;
        s32 t9 = t10 & 1;
        s32 t8 = (arg6 >> 16) & 0xFF;
        s32 t7 = t8 & 1;
        s32 t6 = (arg6 >> 8) & 0xFF;
        while (v22 < 4) {
            u8 *t33 = stk + v22 * 64 + 0xC0;
            u8 *t34 = stk + v22 * 8;
            u8 *t12 = t33;
            *(f32 *)(t12 + 8) = D_008872F8[0] - fparg0;
            *(f32 *)(t12 + 0x18) = temp_f20;
            *(f32 *)(t12 + 0x10) = *(f32 *)(t34 + 0xA0);
            *(f32 *)(t12 + 0x14) = *(f32 *)(t34 + 0xA0 + 4);
            if (t10 >= 0) {
                *(f32 *)(t12 + 0x20) = (f32)t10;
            } else {
                s32 q10 = ((u32)t10 >> 1) | t9;
                f32 g10 = (f32)q10;
                g10 += g10;
                *(f32 *)(t12 + 0x20) = g10;
            }
            if (t8 >= 0) {
                *(f32 *)(t12 + 0x24) = (f32)t8;
            } else {
                s32 q8 = ((u32)t8 >> 1) | t7;
                f32 g8 = (f32)q8;
                g8 += g8;
                *(f32 *)(t12 + 0x24) = g8;
            }
            if (t6 >= 0) {
                *(f32 *)(t12 + 0x28) = (f32)t6;
            } else {
                s32 q6 = ((u32)t6 >> 1) | (t6 & 1);
                f32 g6 = (f32)q6;
                g6 += g6;
                *(f32 *)(t12 + 0x28) = g6;
            }
            if (temp_19 >= 0) {
                *(f32 *)(t12 + 0x2C) = (f32)temp_19;
            } else {
                s32 q19 = ((u32)temp_19 >> 1) | (temp_19 & 1);
                f32 g19 = (f32)q19;
                g19 += g19;
                *(f32 *)(t12 + 0x2C) = g19;
            }
            *(f32 *)(t33 + 0xC0) = *(f32 *)(t34 + 0x80);
            *(f32 *)(t12 + 4) = *(f32 *)(t34 + 0x80 + 4);
            v22 += 1;
        }
    }
    D_00887300[0](1, *(s32 *)(var_20 + 0x14));
    D_00887310[0](4, stk, 4);
    return 0;
}

// Wins: frame -448 exact (stk[336]); 5 direct +2 jalr complete (46d730 NULL-branch found — m2c had it; 276290/2f0 belong to next func); 271f50 (u32*,u32 via cast); 271310 1-arg (retail lw a0,8(a1), m2c 2nd-arg phantom dropped); 46d730 2-arg (TU proto, m2c 3rd-arg phantom dropped); 87300 2-arg via K&R-absolute (retail lui 0x88, no base-var); 87310 (4,&sp,4); reassign-double (NOT 2.0f*); D_00881750/D_0063BCC0/D_0063BC88 registered+recovered.
// Walls: 246 scattered, no bulk>16; obj under-292B (844/1136); 6 H007 dead stores (kept, retail shape); saves unconfirmed (retail 6+4).
