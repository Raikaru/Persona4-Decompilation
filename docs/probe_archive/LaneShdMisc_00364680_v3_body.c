/* Lane floor: func_00364680 (src/shdMisc.c, retail 00364680..00364C50, 1488B).
 * Banked guarded floor (// FUN_00364680 NONMATCHING): 276 differing words,
 * 383/372 instrs (inside the 361-383 gate), 160 edits (+8 reloc-only).
 * Replay: `python3 tools/measure_guarded.py src/shdMisc.c func_00364680`
 * and `python3 tools/fnalign.py src/shdMisc.c func_00364680 --candidate <body> --quiet`.
 * opclass residual is lui +6, nop +5 (addu +1 below its threshold): the
 * conversion surplus is gone, remainder is register coloring/scheduling.
 *
 * Fully decoded 3-pass quad renderer (white pre-pass + white/alpha main +
 * full-color final over 4x64B structs); ABI (f32 depth, s32 color, f32x6,
 * u8 ptr, s32 arg2/arg3), CFG (NULL assert, early flag, drawbase-cached /
 * swbase-direct tables, arg3 switch testing ==1 then ==0), plain
 * `(f32)(u32)x` colors with compiler-emitted bltz/srl/andi/or/mtc1/cvt/add.s
 * idiom all verify. Supersedes the v3 body (411 words, 499 instrs) whose
 * hand-written halving/doubling compiled to ten extra copies of that idiom
 * (mtc1/cvt/srl/or/add.s/b/bltz +10 each, andi +9, nop +35). Both directions
 * measured on the banked body: signed `(f32)t` is 334 words at 325 instrs
 * (outside the gate, short), so unsigned is retail's own shape. WALL:
 * bytes in s4-s1 (retail s5-s2), swbase loads absolute where retail caches
 * via $s0, drawbase hoist timing; seven declaration-order variants tied or
 * regressed on the v3 body. No dsll32/dsra32, no volatile/asm. Production
 * stays ASM.
 */

void func_00364680(f32 depth, s32 color, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6, u8 *ptr, s32 arg2, s32 arg3) {
    s32 (**drawbase)(s32, void *, s32);
    f32 verts[4][16];
    f32 temp_f26;
    f32 temp_f25;
    s32 temp_21;
    s32 temp_20;
    s32 temp_19;
    s32 temp_18;
    s32 flag;
    s32 i;
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
    drawbase = D_00887310;
    D_00887300[0](7, 2);
    D_00887300[0](6, 0);
    D_00887300[0](8, 0);
    D_00887300[0](0xE, 0);
    D_00887300[0](9, 2);
    D_00887300[0](0xC, 1);
    D_00887300[0](1, *(s32 *)ptr);
    func_003f6440(2, 0x44);
    func_00489f80();
    if (flag) {
        verts[0][0] = fparg3;
        verts[0][1] = fparg4;
        verts[1][0] = fparg3 + fparg5;
        verts[1][1] = fparg4;
        verts[2][0] = fparg3 + fparg5;
        verts[2][1] = fparg4 + fparg6;
        verts[3][0] = fparg3;
        verts[3][1] = fparg4 + fparg6;
        for (i = 0; i < 4; i++) {
            ((u32 *)verts)[i * 16 + 8] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 9] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 10] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 11] = 0x437F0000;
        }
        func_003f6440(3, 0x31801);
        drawbase[0](5, verts, 4);
    }
    verts[0][0] = fparg1;
    verts[0][1] = fparg2;
    verts[1][0] = fparg1 + fparg5;
    verts[1][1] = fparg2;
    verts[2][0] = fparg1 + fparg5;
    verts[2][1] = fparg2 + fparg6;
    verts[3][0] = fparg1;
    verts[3][1] = fparg2 + fparg6;
    for (i = 0; i < 4; i++) {
        ((u32 *)verts)[i * 16 + 8] = 0x437F0000;
        ((u32 *)verts)[i * 16 + 9] = 0x437F0000;
        ((u32 *)verts)[i * 16 + 10] = 0x437F0000;
        verts[i][11] = (f32)(u32)temp_18;
    }
    if (flag) {
        func_003f6440(3, 0x35801);
    } else {
        func_003f6440(3, 0x31801);
    }
    drawbase[0](5, verts, 4);
    func_0048a000();
    D_00887300[0](1, 0);
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
    verts[0][0] = fparg1;
    verts[0][1] = fparg2;
    verts[1][0] = fparg1 + fparg5;
    verts[1][1] = fparg2;
    verts[2][0] = fparg1 + fparg5;
    verts[2][1] = fparg2 + fparg6;
    verts[3][0] = fparg1;
    verts[3][1] = fparg2 + fparg6;
    for (i = 0; i < 4; i++) {
        f32 *row = &verts[i][0];
        row[8] = (f32)(u32)temp_21;
        row[9] = (f32)(u32)temp_20;
        row[10] = (f32)(u32)temp_19;
        row[11] = (f32)(u32)temp_18;
    }
    drawbase[0](4, verts, 4);
}
