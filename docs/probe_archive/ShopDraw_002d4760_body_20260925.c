/* func_002d4760 (y_fclShopDraw.c) draft, measured 2026-09-25 with
 * probe_variants: 362 reloc-masked differing words (object 515 instrs vs
 * retail 500 incl. alignment; the guarded body in the source measures 389).
 * Levers that moved it (389 -> 362):
 *  - init as chained pairs `a[0] = a[2] = K`, `secondary[0] = secondary[2] =
 *    primary[0] + 1` (retail's addiu $v0,$v1,1 from the 0x56 register and
 *    $a0 for 0x2D): the init block is now exact;
 *  - loop 2 is a `switch (i)` with cases written 0,1,2 (retail beq 2 / beq 1
 *    / beqz 0 / b);
 *  - `s16 i`, and a separate `s32 sel = arg1` selector assigned after `i = 0`
 *    (retail hoists the s8 extension into $s4 and returns arg1 from its home
 *    slot 0xB7); no `ret` copy;
 *  - no `d` variable: D_00748908[i] read in both conditions (retail keeps it
 *    in $s1 after computing &work->F18[i] into $s2 first).
 * Residual: work $s4 vs retail $s3 / sel $s3 vs $s4 (declaration order has
 * no effect); D_00748908[i] kept as an address ($s1) + value ($s6) instead of
 * the value in $s1; retail CSEs &colorA[i][1..2] / &colorB[i][1..2] into
 * $s0/$s6/$s7/$fp across the second func_002e26f0 call and, in loop 2, the
 * row addresses &y[i] ($s6), &colorA[i] ($s5), &colorB[i] ($s1) -- b210 folds
 * every [i][k] into a per-element address here. Tried without gain:
 * RGBA/struct rows (identical code), chained stores in the second-if (416),
 * an inline label setter (420; retail re-reads the work handle per call).
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
        if (D_00748908[i] >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
            colorA[i][0] = colorA[i][1] = colorA[i][2] = 0x2D;
            if (i == 1) {
                colorA[i][0] = colorA[i][1] = colorA[i][2] = 0;
            }
            colorB[i][0] = colorB[i][1] = colorB[i][2] = 0x6F;
        }
        if (i == sel) {
            colorA[i][0] = 0xFF;
            colorA[i][1] = 0x96;
            colorA[i][2] = 1;
            primary[i] = 0x57;
            y[i][0] = 0x83;
            y[i][1] = 0x84;
            colorB[i][0] = 0xFF;
            colorB[i][1] = 0xF2;
            colorB[i][2] = 0x95;
            secondary[i] = primary[i] + 1;
            thirdY[i] = 0x82;
            if (D_00748908[i] >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
                ((u8 *)colorA)[i * 4 + 2] = 0x9C;
                ((u8 *)colorA)[i * 4 + 1] = 0x9C;
                ((u8 *)colorA)[i * 4 + 0] = 0x9C;
                ((u8 *)colorB)[i * 4 + 2] = 0xFF;
                ((u8 *)colorB)[i * 4 + 1] = 0xFF;
                ((u8 *)colorB)[i * 4 + 0] = 0xFF;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 8) = (f32)y[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 8) = (f32)y[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x79) = colorB[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7A) = colorB[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7B) = colorB[i][2];
            break;
        case 1:
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 8) = (f32)y[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 8) = (f32)y[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x79) = colorB[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7A) = colorB[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7B) = colorB[i][2];
            break;
        case 2:
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 8) = (f32)y[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 8) = (f32)y[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x79) = colorB[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7A) = colorB[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7B) = colorB[i][2];
            break;
        }
    }
    return arg1;
}
