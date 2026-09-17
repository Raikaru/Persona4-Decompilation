/* Faithful floor for func_002d4760 (y_fclShopDraw.c), measured 2026-09-16:
 * probe_variants nd 399 (reloc-masked differing words), object 511 instrs
 * vs retail 500 (frame 0x100 matches after flat second-if; remaining is
 * register-color + scheduling: work lw $s4 vs retail $s3, D/addr $s2/$s1
 * swap, init $v0 vs $v1/$a0, second-loop color temps).
 * Shape: u8 colorA/B[3][4] (stride-4, 3+pad), s16 primary/secondary[3],
 * s16 y[3][2], s16 thirdY[3], s8 ret, s16 i, s8 d (D_00748908 value kept
 * live, matches retail $s1), u8 *work. Init order matches retail offsets
 * (F8/F0, F9/F1, FA/F2, DC/D8, C8/C0, CA/C2 added vs old archive which
 * missed y[0][1]/y[2][1]=0x87, E8/E0, E9/E1, EA/E2, D4/D0, BC/B8,
 * F4/F5/F6, DA, C4/C6, E4/E5/E6, D2, BA). First loop D>= stores reverse
 * (2,1,0, matches retail sb 2/1/0) with i==1 zeroing, selected block
 * forward (0,1,2, FF/96/01, 57, 83/84, FF/F2/95, secondary=primary+1,
 * thirdY=0x82), second D>= via flat ((u8*)colorA)[i*4+..] to break CSE and
 * remove the 0x110 spill (frame back to 0x100). Second loop goto layout
 * (checks 2,1,0 branching to L2/L1/L0 with bodies 0/EC4/EC8/E38, 1/EB4/
 * EB8/CC4, 2/EBC/EC0/CC0 in order, L2 fallthrough) reproduces retail beq
 * chain (2 first) and body order (0 near, 2 far); switch gives jump-table
 * (nd 431), if-else chain gives bodies 2-near (nd 418). (f32) casts for
 * y/thirdY cvt.s.w. Production stays INCLUDE_ASM.
 */
s8 func_002d4760(void *arg0, s8 arg1) {
    u8 colorA[3][4];
    u8 colorB[3][4];
    s16 primary[3];
    s16 secondary[3];
    s16 y[3][2];
    s16 thirdY[3];
    s8 ret;
    s16 i;
    s8 d;
    u8 *work;

    ret = arg1;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    colorA[2][0] = 0xBD;
    colorA[0][0] = 0xBD;
    colorA[2][1] = 0x68;
    colorA[0][1] = 0x68;
    colorA[2][2] = 3;
    colorA[0][2] = 3;
    primary[2] = 0x56;
    primary[0] = 0x56;
    y[2][0] = 0x86;
    y[0][0] = 0x86;
    y[2][1] = 0x87;
    y[0][1] = 0x87;
    colorB[2][0] = 0x2D;
    colorB[0][0] = 0x2D;
    colorB[2][1] = 0x2D;
    colorB[0][1] = 0x2D;
    colorB[2][2] = 0x2D;
    colorB[0][2] = 0x2D;
    secondary[2] = 0x57;
    secondary[0] = 0x57;
    thirdY[2] = 0x85;
    thirdY[0] = 0x85;
    colorA[1][0] = 0x90;
    colorA[1][1] = 0x4F;
    colorA[1][2] = 1;
    primary[1] = 0x41;
    y[1][0] = 0x89;
    y[1][1] = 0x8A;
    colorB[1][0] = 0x2D;
    colorB[1][1] = 0x2D;
    colorB[1][2] = 0x2D;
    secondary[1] = 0x42;
    thirdY[1] = 0x88;
    for (i = 0; i < 3; i++) {
        d = D_00748908[i];
        if (d >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
            colorA[i][2] = 0x2D;
            colorA[i][1] = 0x2D;
            colorA[i][0] = 0x2D;
            if (i == 1) {
                colorA[i][2] = 0;
                colorA[i][1] = 0;
                colorA[i][0] = 0;
            }
            colorB[i][2] = 0x6F;
            colorB[i][1] = 0x6F;
            colorB[i][0] = 0x6F;
        }
        if (i == arg1) {
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
            if (d >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
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
        if (i == 2) {
            goto L2;
        }
        if (i == 1) {
            goto L1;
        }
        if (i == 0) {
            goto L0;
        }
        goto Lend;
L0: *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0xFC) = primary[i];
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
        goto Lend;
L1: *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0xFC) = primary[i];
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
        goto Lend;
L2: *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0xFC) = primary[i];
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
Lend: ;
    }
    return ret;
}
