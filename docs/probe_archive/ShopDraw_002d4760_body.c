/* Closest nonmatching candidate archived before reverting to INCLUDE_ASM.
 * Candidate used explicit color/coordinate arrays; compiled frame/register
 * allocation remained incompatible with retail (fndiff: 438 differing words).
 */
s8 func_002d4760(void *arg0, s8 arg1) {
    u8 colorA[24];
    u8 colorB[16];
    s16 primary[4];
    s16 secondary[4];
    s16 y[8];
    s16 thirdY[4];
    s8 ret;
    s16 i;
    u8 *work;

    ret = arg1;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    colorA[8] = 0xBD;
    colorA[0] = 0xBD;
    colorA[9] = 0x68;
    colorA[1] = 0x68;
    colorA[10] = 3;
    colorA[2] = 3;
    primary[2] = 0x56;
    primary[0] = 0x56;
    y[4] = 0x86;
    y[0] = 0x86;
    secondary[2] = 0x57;
    secondary[0] = 0x57;
    colorB[8] = 0x2D;
    colorB[0] = 0x2D;
    colorB[9] = 0x2D;
    colorB[1] = 0x2D;
    colorB[10] = 0x2D;
    colorB[2] = 0x2D;
    secondary[2] = 0x57;
    secondary[0] = 0x57;
    thirdY[2] = 0x85;
    thirdY[0] = 0x85;
    colorA[4] = 0x90;
    colorA[5] = 0x4F;
    colorA[6] = 1;
    primary[1] = 0x41;
    y[2] = 0x89;
    y[3] = 0x8A;
    colorB[4] = 0x2D;
    colorB[5] = 0x2D;
    colorB[6] = 0x2D;
    secondary[1] = 0x42;
    thirdY[1] = 0x88;

    for (i = 0; i < 3; i++) {
        if (D_00748908[i] >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
            colorA[i * 4 + 2] = 0x2D;
            colorA[i * 4 + 1] = 0x2D;
            colorA[i * 4] = 0x2D;
            if (i == 1) {
                colorA[i * 4 + 2] = 0;
                colorA[i * 4 + 1] = 0;
                colorA[i * 4] = 0;
            }
            colorB[i * 4 + 2] = 0x6F;
            colorB[i * 4 + 1] = 0x6F;
            colorB[i * 4] = 0x6F;
        }
        if (i == arg1) {
            colorA[i * 4] = 0xFF;
            colorA[i * 4 + 1] = 0x96;
            colorA[i * 4 + 2] = 1;
            primary[i] = 0x57;
            y[i * 2] = 0x83;
            y[i * 2 + 1] = 0x84;
            secondary[i] = primary[i] + 1;
            thirdY[i] = 0x82;
            if (D_00748908[i] >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
                colorA[i * 4 + 2] = 0x9C;
                colorA[i * 4 + 1] = 0x9C;
                colorA[i * 4] = 0x9C;
                colorB[i * 4 + 2] = 0xFF;
                colorB[i * 4 + 1] = 0xFF;
                colorB[i * 4] = 0xFF;
            }
        }
    }

    for (i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0xFC) = primary[0];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 8) = (f32)y[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x79) = colorA[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7A) = colorA[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7B) = colorA[2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0xFC) = primary[0];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 8) = (f32)y[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x79) = colorA[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7A) = colorA[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7B) = colorA[2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0xFC) = secondary[0];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 8) = (f32)thirdY[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x79) = colorB[0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7A) = colorB[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7B) = colorB[2];
            break;
        case 1:
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0xFC) = primary[1];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 8) = (f32)y[2];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x79) = colorA[4];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7A) = colorA[5];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7B) = colorA[6];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0xFC) = primary[1];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 8) = (f32)y[3];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x79) = colorA[4];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7A) = colorA[5];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7B) = colorA[6];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0xFC) = secondary[1];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 8) = (f32)thirdY[1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x79) = colorB[4];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7A) = colorB[5];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7B) = colorB[6];
            break;
        case 2:
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0xFC) = primary[2];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 8) = (f32)y[4];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x79) = colorA[8];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7A) = colorA[9];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7B) = colorA[10];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0xFC) = primary[2];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 8) = (f32)y[5];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x79) = colorA[8];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7A) = colorA[9];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7B) = colorA[10];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0xFC) = secondary[2];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 8) = (f32)thirdY[2];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x79) = colorB[8];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7A) = colorB[9];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7B) = colorB[10];
            break;
        default:
            break;
        }
    }
    return ret;
}
