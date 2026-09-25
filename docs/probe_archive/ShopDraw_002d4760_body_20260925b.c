/* func_002d4760 (y_fclShopDraw.c) draft, second pass 2026-09-25 (builds on
 * ShopDraw_002d4760_body_20260925.c, 362 words).  Measured with
 * tools/fndiff.py: 350 reloc-masked differing words, object 1968 bytes vs
 * the 2000-byte window, frame 0x100 and all nine saved registers exact.
 * The word count is dominated by misalignment; by region:
 *  - init block: exact (unchanged).
 *  - loop 1 head: exact apart from register names once D_00748908 is
 *    declared `extern const s8 D_00748908[];` (unit change, not applied:
 *    retail keeps the table byte in $s1 across both func_002e26f0 calls,
 *    which b210 only does for a const table) and the test is written
 *    `func_002e26f0(slot) <= D_00748908[i]` (retail's `slt $at` form).
 *  - loop 2: exact apart from register names ($s3/$s4/$s5 rotations) with
 *    row pointers assigned at first use (`(yr = y[i])[0]`,
 *    `(ca = colorA[i])[0]`, `(cb = colorB[i])[0]`) and the three colorA
 *    bytes held in named `r`/`g`/`bl` locals for the second object.  Plain
 *    `colorA[i][k]` folds the row offset into each access (&y + (i*4+k))
 *    where retail keeps &y[i] in $s6; struct rows give the same code as
 *    the 2-D arrays.
 *  - the selected-row block (i == sel) is the open region: retail writes
 *    colorA[i][0..2] / colorB[i][0..2] through a row pointer, CSEs only the
 *    [1] and [2] addresses ($s0/$s6, $s7/$fp) into the 0x9C/0xFF stores
 *    after the second func_002e26f0 call and recomputes [0]; array form
 *    CSEs all three (and spills), pointer form CSEs none.
 * Registers still rotated: work $s4 (retail $s3), sel $s5 ($s4), i $s4
 * ($s5).  Casting the colour arrays to u8 * (the first draft's 0x9C stores)
 * makes b210 treat them as aliased and reload every byte in loop 2.
 */
s8 func_002d4760(void *arg0, s8 arg1) {
    u8 colorA[3][4];
    u8 colorB[3][4];
    s16 primary[3];
    s16 secondary[3];
    s16 y[3][2];
    s16 thirdY[3];
    s16 i;
    s32 sel;
    u8 *work;
    s16 *yr;
    u8 *ca;
    u8 *cb;
    u8 r;
    u8 g;
    u8 bl;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    colorA[0][0] = colorA[2][0] = 0xBD;
    colorA[0][1] = colorA[2][1] = 0x68;
    colorA[0][2] = colorA[2][2] = 3;
    primary[0] = primary[2] = 0x56;
    y[0][0] = y[2][0] = 0x86;
    y[0][1] = y[2][1] = 0x87;
    colorB[0][0] = colorB[2][0] = 0x2D;
    colorB[0][1] = colorB[2][1] = 0x2D;
    colorB[0][2] = colorB[2][2] = 0x2D;
    secondary[0] = secondary[2] = primary[0] + 1;
    thirdY[0] = thirdY[2] = 0x85;
    colorA[1][0] = 0x90;
    colorA[1][1] = 0x4F;
    colorA[1][2] = 1;
    primary[1] = 0x41;
    y[1][0] = 0x89;
    y[1][1] = 0x8A;
    colorB[1][0] = 0x2D;
    colorB[1][1] = 0x2D;
    colorB[1][2] = 0x2D;
    secondary[1] = primary[1] + 1;
    thirdY[1] = 0x88;
    i = 0;
    sel = arg1;
    for (; i < 3; i++) {
        if (func_002e26f0(*(void **)(work + 0xF18 + i * 4)) <= D_00748908[i]) {
            colorA[i][0] = colorA[i][1] = colorA[i][2] = 0x2D;
            if (i == 1) {
                colorA[i][0] = colorA[i][1] = colorA[i][2] = 0;
            }
            colorB[i][0] = colorB[i][1] = colorB[i][2] = 0x6F;
        }
        if (i == sel) {
            ca = colorA[i];
            ca[0] = 0xFF;
            ca[1] = 0x96;
            ca[2] = 1;
            primary[i] = 0x57;
            yr = y[i];
            yr[0] = 0x83;
            yr[1] = 0x84;
            cb = colorB[i];
            cb[0] = 0xFF;
            cb[1] = 0xF2;
            cb[2] = 0x95;
            secondary[i] = primary[i] + 1;
            thirdY[i] = 0x82;
            if (func_002e26f0(*(void **)(work + 0xF18 + i * 4)) <= D_00748908[i]) {
                colorA[i][0] = colorA[i][1] = colorA[i][2] = 0x9C;
                colorB[i][0] = colorB[i][1] = colorB[i][2] = 0xFF;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x8) = (f32)(yr = y[i])[0];
            r = (ca = colorA[i])[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x79) = r;
            g = ca[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7A) = g;
            bl = ca[2];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7B) = bl;
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x8) = (f32)yr[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x79) = r;
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7A) = g;
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7B) = bl;
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x79) = (cb = colorB[i])[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7A) = cb[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7B) = cb[2];
            break;
        case 1:
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x8) = (f32)(yr = y[i])[0];
            r = (ca = colorA[i])[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x79) = r;
            g = ca[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7A) = g;
            bl = ca[2];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7B) = bl;
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x8) = (f32)yr[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x79) = r;
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7A) = g;
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7B) = bl;
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x79) = (cb = colorB[i])[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7A) = cb[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7B) = cb[2];
            break;
        case 2:
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x8) = (f32)(yr = y[i])[0];
            r = (ca = colorA[i])[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x79) = r;
            g = ca[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7A) = g;
            bl = ca[2];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7B) = bl;
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x8) = (f32)yr[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x79) = r;
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7A) = g;
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7B) = bl;
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x79) = (cb = colorB[i])[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7A) = cb[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7B) = cb[2];
            break;
        }
    }
    return arg1;
}
