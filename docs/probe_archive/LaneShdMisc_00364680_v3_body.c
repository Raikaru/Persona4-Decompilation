/* Lane floor: func_00364680 (src/shdMisc.c, retail 00364680..00364C50, 1488B).
 * Banked guarded floor (// FUN_00364680 NONMATCHING): probe 411 differing
 * words. Reproduce: `python3 tools/probe_variants.py src/shdMisc.c
 * func_00364680 --candidate v3=/var/tmp/cand_00364680_v3.c`; replay with
 * `python3 tools/measure_guarded.py src/shdMisc.c func_00364680`.
 * opclass on the banked floor reports no opcode-class surplus: the residual
 * is register coloring/scheduling only.
 *
 * Fully decoded 3-pass quad renderer (white pre-pass + white/alpha main +
 * full-color final over 4x64B structs); ABI, CFG, base-hoisted call tables,
 * arg3 switch (==1 then ==0), bltz colors with f+f doubling all verify.
 * Supersedes the 1840B struct-array attempt. WALL: candidate frame 0x1B0
 * (one sq short of retail 0x1C0), bytes s3-s0 not s5-s2, args rotated,
 * addu-grouped moves, drawbase hoist timing, switch arm layout. Seven
 * declaration variants tie/regress (411-462). Production stays ASM.
 */

void func_00364680(s32 color, u8 *ptr, s32 arg2, s32 arg3, f32 depth, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6) {
    void (**swbase)(u32, u32);
    s32 (**drawbase)(s32, void *, s32);
    f32 verts[4][16];
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f27;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f26;
    f32 temp_f25;
    s32 temp_21;
    s32 temp_20;
    s32 temp_19;
    s32 temp_18;
    s32 flag;
    s32 i;
    s32 bit0;
    s32 b3;
    s32 b2;
    s32 b1;
    s32 b0;
    f32 hh;

    temp_f24 = fparg1;
    temp_f23 = fparg2;
    temp_f22 = fparg3;
    temp_f27 = fparg4;
    temp_f21 = fparg5;
    temp_f20 = fparg6;
    temp_f26 = D_008872F8[0] - depth;
    temp_f25 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    if (ptr == NULL) {
        func_0046d730(D_0064E2F8, 153);
    }
    temp_21 = (s32)(u8)(((u32)color & 0xFF000000) >> 24);
    temp_20 = (s32)(u8)(((u32)color & 0x00FF0000) >> 16);
    temp_19 = (s32)(u8)(((u32)color & 0x0000FF00) >> 8);
    temp_18 = color & 0xFF;
    flag = (temp_18 ^ 0xFF) != 0;
    if (flag) {
        flag = arg2 != 0;
    }
    verts[0][2] = temp_f26;
    verts[1][2] = temp_f26;
    verts[2][2] = temp_f26;
    verts[3][2] = temp_f26;
    verts[0][6] = temp_f25;
    verts[1][6] = temp_f25;
    verts[2][6] = temp_f25;
    verts[3][6] = temp_f25;
    ((u32 *)verts)[4] = 0;
    ((u32 *)verts)[5] = 0;
    ((u32 *)verts)[1 * 16 + 4] = 0x3F800000;
    ((u32 *)verts)[1 * 16 + 5] = 0;
    ((u32 *)verts)[2 * 16 + 4] = 0x3F800000;
    ((u32 *)verts)[2 * 16 + 5] = 0x3F800000;
    ((u32 *)verts)[3 * 16 + 4] = 0;
    ((u32 *)verts)[3 * 16 + 5] = 0x3F800000;
    swbase = D_00887300;
    drawbase = D_00887310;
    swbase[0](7, 2);
    swbase[0](6, 0);
    swbase[0](8, 0);
    swbase[0](0xE, 0);
    swbase[0](9, 2);
    swbase[0](0xC, 1);
    swbase[0](1, *(s32 *)ptr);
    func_003f6440(2, 0x44);
    func_00489f80();
    if (flag) {
        verts[0][0] = temp_f22;
        verts[0][1] = temp_f27;
        verts[1][0] = temp_f22 + temp_f21;
        verts[1][1] = temp_f27;
        verts[2][0] = temp_f22 + temp_f21;
        verts[2][1] = temp_f27 + temp_f20;
        verts[3][0] = temp_f22;
        verts[3][1] = temp_f27 + temp_f20;
        for (i = 0; i < 4; i++) {
            ((u32 *)verts)[i * 16 + 8] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 9] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 10] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 11] = 0x437F0000;
        }
        func_003f6440(3, 0x31801);
        drawbase[0](5, verts, 4);
    }
    verts[0][0] = temp_f24;
    verts[0][1] = temp_f23;
    verts[1][0] = temp_f24 + temp_f21;
    verts[1][1] = temp_f23;
    verts[2][0] = temp_f24 + temp_f21;
    verts[2][1] = temp_f23 + temp_f20;
    verts[3][0] = temp_f24;
    verts[3][1] = temp_f23 + temp_f20;
    bit0 = temp_18 & 1;
    for (i = 0; i < 4; i++) {
        ((u32 *)verts)[i * 16 + 8] = 0x437F0000;
        ((u32 *)verts)[i * 16 + 9] = 0x437F0000;
        ((u32 *)verts)[i * 16 + 10] = 0x437F0000;
        if (temp_18 >= 0) {
            verts[i][11] = (f32)(u32)temp_18;
        } else {
            hh = (f32)(((u32)temp_18 >> 1) | bit0);
            verts[i][11] = hh + hh;
        }
    }
    if (flag) {
        func_003f6440(3, 0x35801);
    } else {
        func_003f6440(3, 0x31801);
    }
    drawbase[0](5, verts, 4);
    func_0048a000();
    swbase[0](1, 0);
    switch (arg3) {
    case 1:
        func_003f6440(2, 0x58);
        break;
    case 0:
        func_003f6440(2, 0x54);
        break;
    default:
        func_0046d730(D_0064E2F8, 265);
        break;
    }
    if (flag) {
        func_003f6440(3, 0x35801);
    } else {
        func_003f6440(3, 0x31801);
    }
    verts[0][0] = temp_f24;
    verts[0][1] = temp_f23;
    verts[1][0] = temp_f24 + temp_f21;
    verts[1][1] = temp_f23;
    verts[2][0] = temp_f24 + temp_f21;
    verts[2][1] = temp_f23 + temp_f20;
    verts[3][0] = temp_f24;
    verts[3][1] = temp_f23 + temp_f20;
    b3 = temp_21 & 1;
    b2 = temp_20 & 1;
    b1 = temp_19 & 1;
    b0 = temp_18 & 1;
    for (i = 0; i < 4; i++) {
        f32 *row = &verts[i][0];
        if (temp_21 >= 0) {
            row[8] = (f32)(u32)temp_21;
        } else {
            hh = (f32)(((u32)temp_21 >> 1) | b3);
            row[8] = hh + hh;
        }
        if (temp_20 >= 0) {
            row[9] = (f32)(u32)temp_20;
        } else {
            hh = (f32)(((u32)temp_20 >> 1) | b2);
            row[9] = hh + hh;
        }
        if (temp_19 >= 0) {
            row[10] = (f32)(u32)temp_19;
        } else {
            hh = (f32)(((u32)temp_19 >> 1) | b1);
            row[10] = hh + hh;
        }
        if (temp_18 >= 0) {
            row[11] = (f32)(u32)temp_18;
        } else {
            hh = (f32)(((u32)temp_18 >> 1) | b0);
            row[11] = hh + hh;
        }
    }
    drawbase[0](4, verts, 4);
}
