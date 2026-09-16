/* FUN_001FBB50 floor (v5, fndiff 328, obj 1608B/window 1632B, UNDER-24B).
 * Dispatch + FMA-msub + fills, 38 calls, 4 saves (s0-s3; retail s0-s2).
 * Frame -144 vs -128 (base-var s3 costs +16B but saves 14 luis, net under).
 * WINS: loop-38 found (m2c missed; 38 calls exact); sp50 s32[7] + D_00625210
 *   s32[] (lw, indexed &sp50[i]/sp50[i]); FMA adda/msub emitted via
 *   255*(1-f21*pw5) nesting + 4-mul chain; base-var for 87300 (lw(s0));
 *   6 symbols + 10 decls; (u8) convs; union sp78 (lw a1).
 * WALLS: s-map rotation; extra s3 save; D_008872E0/D_00887304 absolute-vs-base;
 *   328 scattered rows (max gap 56). Complete, under-size floor.
 */
// FUN_001FBB50 floor body (v5, fndiff 328, obj 1608B/window 1632B)
s32 func_001fbb50(u8 *arg0) {
    union { s32 w; u8 b[4]; } sp78;
    s32 sp50[7];
    u8 sp7C[4];
    u8 sp7B;
    u8 sp7A;
    u8 sp79;
    f32 temp_f21;
    f32 temp_f20;
    s32 var_18;
    u32 var_16;
    u8 *temp_17;
    void (**base)();

    if (func_003e8120(func_00457120()) == 0) {
        return 0;
    }
    var_18 = 0;
    var_16 = 0;
    do {
        D_00887304[0](D_00625210[var_16], &sp50[var_16]);
        var_16 += 1;
    } while (var_16 < 7);
    base = D_00887300;
    temp_17 = *(u8 **)(arg0 + 0x38);
    {
        u8 t3 = *temp_17;
        switch (t3) {
        case 1: {
            u16 t2 = D_0076455C;
            if (t2 == 0) {
                D_0076455A++;
                {
                    u16 t22 = D_0076455A;
                    f32 vf1;
                    if ((s32)t22 >= 0) {
                        vf1 = (f32)t22;
                    } else {
                        s32 qq = ((u32)t22 >> 1) | (t22 & 1);
                        vf1 = (f32)qq;
                        vf1 += vf1;
                    }
                    temp_f21 = vf1 / 20.0f;
                }
                base[0](7, 2);
                base[0](0x14, 1);
                base[0](0x0E, 0);
                base[0](6, 0);
                base[0](8, 0);
                base[0](0x0C, 1);
                base[0](1, 0);
                func_003f6440(2, 0x44);
                func_003f6440(3, 0x31801);
                func_00489f80();
                sp7C[0] = 0xFF;
                sp7C[1] = 0xFF;
                sp7C[2] = 0xFF;
                {
                    f32 pw2 = temp_f21 * temp_f21;
                    f32 pw3 = temp_f21 * pw2;
                    f32 pw4 = temp_f21 * pw3;
                    f32 pw5 = temp_f21 * pw4;
                    f32 tf1 = 255.0f * (1.0f - temp_f21 * pw5);
                    u8 v3 = (u8)tf1;
                    sp7C[3] = v3;
                }
                func_0045c870(sp7C, 0);
                sp78.b[0] = 0xFF;
                sp78.b[1] = 0xFF;
                sp78.b[2] = 0xFF;
                {
                    f32 tf12 = 160.0f * (1.0f - (temp_f21 * temp_f21));
                    u8 v32 = (u8)tf12;
                    sp79 = v32;
                }
                {
                    u16 t23 = D_0076455A;
                    f32 vf12;
                    if ((s32)t23 >= 0) {
                        vf12 = (f32)t23;
                    } else {
                        s32 qq2 = ((u32)t23 >> 1) | (t23 & 1);
                        vf12 = (f32)qq2;
                        vf12 += vf12;
                    }
                    temp_f20 = 1.5f * (vf12 / 20.0f);
                }
                func_00457120();
                base[0](7, 2);
                base[0](0x14, 1);
                base[0](0x0E, 0);
                base[0](6, 0);
                base[0](8, 0);
                base[0](0x0C, 1);
                base[0](1, 0);
                func_003f6440(2, 0x44);
                func_003f6440(3, 0x31801);
                func_00204690(0, temp_f20, temp_f20, sp78.w, D_008872FC_abs[0]);
                func_0048a000();
                func_001fb480(D_007635C8, 0x54, 0x31801, (u8 *)1, 1.0f);
                if ((s32)D_0076455A >= 0x14) {
                    *temp_17 = 3;
                }
            } else {
                D_0076455C = t2 - 1;
            }
            break;
        }
        case 2: {
            if (iGpffffb469 == 0) {
                func_001fb480(D_007635C8, 0x44, 0x31801, (u8 *)1, 1.0f);
                if (*(u16 *)(temp_17 + 6) == 1) {
                    temp_f20 = (f32)(s32)D_007613E0;
                } else {
                    temp_f20 = (f32)(s32)D_007613E4;
                }
                sp7C[0] = 0xFF;
                sp7C[1] = 0xFF;
                sp7C[2] = 0xFF;
                if (*(u16 *)(temp_17 + 6) == 1) {
                    sp7C[3] = 6;
                } else {
                    sp7C[3] = 0x0A;
                }
                func_001fb480(sp7C, 0x44, 0x31801, (u8 *)2, temp_f20);
                sp7C[3] = 5;
                func_001fb480(sp7C, 0x48, 0x31801, (u8 *)2, temp_f20);
            }
            break;
        }
        case 3: {
            if (func_00122720() != 0) {
                func_00122640(1, 0x1E);
                iGpffffb468 = 0;
                var_18 = -1;
            }
            break;
        }
        }
        {
            u32 k;
            k = 0;
            do {
                base[0](D_00625210[k], sp50[k]);
                k += 1;
            } while (k < 7);
        }
        base[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        func_003e8110(func_00457120());
    }
    return var_18;
}
