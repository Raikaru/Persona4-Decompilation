/* FUN_0045FBE0 floor (v3, fndiff 333, obj 1488B/window 1504B, UNDER-16B).
 * Dispatch + 20-iter FMA loop + fills, 5 args. Frame -1632 (mine -1616).
 * Saves s0-s4 (ROTATED: mine s4/s2/s3/s1 for a0-a3 vs retail s4/s1/s2/s0);
 * floats f20-f22 mine vs f20-f25 retail (+3 saves, pressure).
 * Template: MATCHED neighbor 0045c870 (dispatch + work-struct).
 *
 * WINS:
 * - FMA adda/madd EMITTED via nested ((t22/W638)*((W638-t21)*t20))+t23
 *   (uses temp_f20/21/22, kills H007; 1a3840 single-nest precedent).
 * - f24-inc via fGpffff81f0 (removed spurious 457120 call; 15 calls exact).
 * - D_00887300/304/310 + D_00712490[6] neighbor patterns; 3e8200/3e42a0 decls.
 * - Loop-41 q-pattern; u-temp reassign-double (no mul).
 *
 * WALLS:
 * - s-map rotation (a1/a2/a3 homes); float-save pressure (+3).
 * - D_008872E0 GPREL-vs-absolute (needs _abs registration); frame -16B.
 * - Stop: coloring + pressure; complete (calls/FMA exact), under-size floor.
 */
// FUN_0045FBE0 floor body (v3, fndiff 333, obj 1488B/window 1504B)
void func_0045fbe0(f32 *arg0, u8 *arg1, f32 *arg2, s32 arg3, f32 fparg0) {
    u8 work[0x5E0];
    f32 temp_f23;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 *temp_19;
    f32 *var_18;
    u32 var_20;
    u32 var_18_2;
    u32 var_16;
    u8 *temp_18;

#define W8(off) (*(f32 *)(work + ((off) - 0x80)))
#define W32(off) (*(s32 *)(work + ((off) - 0x80)))
#define WU32(off) (*(u32 *)(work + ((off) - 0x80)))

    var_18 = arg2;
    W8(0x8C) = fparg0;
    W8(0x80) = (f32)*(s32 *)(arg0 + 0);
    W32(0x84) = *(s32 *)(arg0 + 4);
    W32(0x88) = *(s32 *)(arg0 + 8);
    if (func_003e8200(D_008872E0, work + 0) != 0) {
        temp_f23 = D_008872FC_abs[0];
        temp_f20 = D_008872F8_abs[0];
        temp_f21 = *(f32 *)((u8 *)(u32)func_00457120() + 0x84);
        temp_f22 = *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
        temp_19 = (f32 *)((u8 *)(u32)func_00457120() + 0x20);
        if (var_18 != NULL) {
            f32 *dst = (f32 *)(work + (0x90 - 0x80));
            s32 n = 8;
            do {
                f32 t0 = (f32)*(s32 *)var_18;
                s32 t1 = *(s32 *)((u8 *)var_18 + 4);
                var_18 += 8;
                n -= 1;
                dst[0] = t0;
                *(s32 *)(dst + 1) = t1;
                dst += 8;
            } while (n > 0);
        } else {
            W32(0xB8) = 0x3F800000;
            W32(0xA4) = 0x3F800000;
            W8(0x90) = 1.0f;
            W32(0xA0) = 0;
            W32(0x98) = 0;
            W32(0x94) = 0;
            W32(0xB4) = 0;
            W32(0xB0) = 0;
            W32(0xA8) = 0;
            W32(0xC8) = 0;
            W32(0xC4) = 0;
            W8(0xC0) = 0.0f;
            W32(0x9C) |= 0x20003;
        }
        W8(0xC0) = (f32)*(s32 *)(arg0 + 0);
        W32(0xC4) = *(s32 *)(arg0 + 4);
        W32(0xC8) = *(s32 *)(arg0 + 8);
        if (arg3 != 0) {
            s32 *p;
            var_20 = 0;
loop_9:
            if (var_20 < 6) {
                p = (s32 *)&D_00712490[var_20];
                D_00887304[0](p[0], work + (0xD0 - 0x80) + var_20 * 4);
                D_00887300[0](p[0], p[1]);
                var_20 += 1;
                goto loop_9;
            }
            D_00887300[0](1, 0);
            func_003f6440(2, 0x48);
            func_003f6440(3, 0x71801);
        }
        {
            f32 *out = (f32 *)(work + (0xF0 - 0x80));
            f32 f24 = 0.0f;
            var_18_2 = 0;
loop_25:
            if (var_18_2 < 20) {
                f32 f3;
                W8(0x650) = fparg0 * func_0044b610(f24);
                W8(0x658) = fparg0 * func_0044b7b0(f24);
                func_003e42a0(work + (0x640 - 0x80), work + (0x650 - 0x80), work + (0x90 - 0x80));
                func_003e42a0(work + (0x630 - 0x80), work + (0x640 - 0x80), temp_19);
                f3 = ((temp_f22 / W8(0x638)) * ((W8(0x638) - temp_f21) * temp_f20)) + temp_f23;
                W8(0x630) = 640.0f * (W8(0x630) / W8(0x638));
                W8(0x634) = 448.0f * (W8(0x634) / W8(0x638));
                out[0] = W8(0x630);
                out[1] = W8(0x634);
                out[2] = f3;
                out[6] = 1.0f / f3;
                {
                    s32 b0 = *(arg1 + 0);
                    f32 g0;
                    if (b0 >= 0) {
                        g0 = (f32)b0;
                    } else {
                        s32 q0 = ((u32)b0 >> 1) | (b0 & 1);
                        g0 = (f32)q0;
                        g0 += g0;
                    }
                    out[8] = g0;
                }
                {
                    s32 b1 = *(arg1 + 1);
                    f32 g1;
                    if (b1 >= 0) {
                        g1 = (f32)b1;
                    } else {
                        s32 q1 = ((u32)b1 >> 1) | (b1 & 1);
                        g1 = (f32)q1;
                        g1 += g1;
                    }
                    out[9] = g1;
                }
                {
                    s32 b2 = *(arg1 + 2);
                    f32 g2;
                    if (b2 >= 0) {
                        g2 = (f32)b2;
                    } else {
                        s32 q2 = ((u32)b2 >> 1) | (b2 & 1);
                        g2 = (f32)q2;
                        g2 += g2;
                    }
                    out[10] = g2;
                }
                {
                    s32 b3 = *(arg1 + 3);
                    f32 g3;
                    if (b3 >= 0) {
                        g3 = (f32)b3;
                    } else {
                        s32 q3 = ((u32)b3 >> 1) | (b3 & 1);
                        g3 = (f32)q3;
                        g3 += g3;
                    }
                    out[11] = g3;
                }
                out += 16;
                f24 += fGpffff81f0;
                var_18_2 += 1;
                goto loop_25;
            }
            out[0] = W8(0xF0);
            out[1] = W8(0xF4);
            out[2] = W8(0xF8);
            out[6] = W8(0x108);
            {
                s32 c0 = *(arg1 + 0);
                f32 h0;
                if (c0 >= 0) {
                    h0 = (f32)c0;
                } else {
                    s32 r0 = ((u32)c0 >> 1) | (c0 & 1);
                    h0 = (f32)r0;
                    h0 += h0;
                }
                out[8] = h0;
            }
            {
                s32 c1 = *(arg1 + 1);
                f32 h1;
                if (c1 >= 0) {
                    h1 = (f32)c1;
                } else {
                    s32 r1 = ((u32)c1 >> 1) | (c1 & 1);
                    h1 = (f32)r1;
                    h1 += h1;
                }
                out[9] = h1;
            }
            {
                s32 c2 = *(arg1 + 2);
                f32 h2;
                if (c2 >= 0) {
                    h2 = (f32)c2;
                } else {
                    s32 r2 = ((u32)c2 >> 1) | (c2 & 1);
                    h2 = (f32)r2;
                    h2 += h2;
                }
                out[10] = h2;
            }
            {
                s32 c3 = *(arg1 + 3);
                f32 h3;
                if (c3 >= 0) {
                    h3 = (f32)c3;
                } else {
                    s32 r3 = ((u32)c3 >> 1) | (c3 & 1);
                    h3 = (f32)r3;
                    h3 += h3;
                }
                out[11] = h3;
            }
            D_00887310[0](2, work + (0xF0 - 0x80), 21);
            if (arg3 != 0) {
                s32 *q;
                var_16 = 0;
loop_41:
                if (var_16 < 6) {
                    q = (s32 *)&D_00712490[var_16];
                    D_00887300[0](*(u8 *)q, *(s32 *)(work + (0xD0 - 0x80) + var_16 * 4));
                    var_16 += 1;
                    goto loop_41;
                }
            }
        }
    }
}
