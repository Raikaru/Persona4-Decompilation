void func_002b0b10(u8 *arg0, YVec2f arg1, u8 arg2, s32 arg3, s8 arg4, s32 arg5, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 spBC;
    s32 spB8;
    f32 spB4;
    f32 spB0;
    s32 spAC;
    f32 spA8;
    f32 spA4;
    s32 spA0;
    f32 sp9C;
    f32 sp98;
    s32 sp94;
    f32 sp90;
    s64 sp88;
    f32 temp_f0;
    f32 temp_f6;
    f32 temp_f5;
    f32 b88;
    u8 *temp_16;
    s32 temp_5;
    s32 temp_2;
    s32 temp_3;
    s32 temp_32;

    sp88 = *(s64 *)&arg1;
    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_f0 = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    *(f32 *)(temp_16 + 0x38) = temp_f0;
    temp_f6 = fparg0 * fparg3;
    temp_f5 = fparg1 * fparg3;
    temp_5 = arg2 & 0xFF;
    b88 = *(f32 *)&sp88;
    switch (temp_5) {
    case 0:
        sp90 = b88;
        sp94 = 0;
        sp98 = fparg2;
        sp9C = b88 + temp_f6;
        spA0 = 0;
        spA4 = fparg2;
        spA8 = b88;
        spAC = 0;
        spB0 = fparg2 + temp_f5;
        spB4 = b88 + temp_f6;
        spB8 = 0;
        spBC = fparg2 + temp_f5;
        break;
    case 1:
        temp_2 = arg4;
        switch (temp_2) {
        case 0:
            sp90 = b88;
            sp94 = 0;
            sp98 = fparg2 + temp_f5;
            sp9C = b88;
            spA0 = 0;
            spA4 = fparg2;
            spA8 = b88 + temp_f6;
            spAC = 0;
            spB0 = fparg2 + temp_f5;
            spB4 = b88 + temp_f6;
            spB8 = 0;
            spBC = fparg2;
            break;
        case 1:
            sp90 = b88;
            sp94 = 0;
            sp98 = fparg2 + temp_f6;
            sp9C = b88;
            spA0 = 0;
            spA4 = fparg2;
            spA8 = b88 + temp_f5;
            spAC = 0;
            spB0 = fparg2 + temp_f6;
            spB4 = b88 + temp_f5;
            spB8 = 0;
            spBC = fparg2;
            break;
        case 2:
            sp9C = b88;
            spA0 = 0;
            spA4 = fparg2 - 18.0f;
            spB4 = (b88 + temp_f6);
            spB8 = 0;
            spBC = fparg2 - 18.0f;
            sp90 = b88;
            sp94 = 0;
            sp98 = (fparg2 + temp_f5) - 18.0f;
            spA8 = b88 + temp_f6;
            spAC = 0;
            spB0 = (fparg2 + temp_f5) - 18.0f;
            break;
        }
        break;
    case 2:
        temp_3 = arg4;
        switch (temp_3) {
        case 0:
            spB4 = b88;
            spB8 = 0;
            spBC = fparg2;
            spA8 = b88 + temp_f6;
            spAC = 0;
            spB0 = fparg2;
            sp9C = b88;
            spA0 = 0;
            spA4 = fparg2 + temp_f5;
            sp90 = b88 + temp_f6;
            sp94 = 0;
            sp98 = fparg2 + temp_f5;
            break;
        case 1:
            spB4 = b88;
            spB8 = 0;
            spBC = fparg2;
            spA8 = b88 + temp_f6;
            spAC = 0;
            spB0 = fparg2;
            sp9C = b88;
            spA0 = 0;
            spA4 = fparg2 + temp_f5;
            sp90 = b88 + temp_f6;
            sp94 = 0;
            sp98 = fparg2 + temp_f5;
            break;
        case 2:
            spB4 = b88 - 18.0f;
            spB8 = 0;
            spBC = fparg2;
            spA8 = (b88 + temp_f6) - 18.0f;
            spAC = 0;
            spB0 = fparg2;
            sp9C = b88 - 18.0f;
            spA0 = 0;
            spA4 = fparg2 + temp_f5;
            sp90 = (b88 + temp_f6) - 18.0f;
            sp94 = 0;
            sp98 = fparg2 + temp_f5;
            break;
        }
        break;
    case 3:
        temp_32 = arg4;
        if (temp_32 == 0) {
            spA8 = b88;
            spAC = 0;
            spB0 = fparg2;
            sp90 = b88 + temp_f6;
            sp94 = 0;
            sp98 = fparg2;
            spB4 = b88;
            spB8 = 0;
            spBC = fparg2 + temp_f5;
            sp9C = b88 + temp_f6;
            spA0 = 0;
            spA4 = fparg2 + temp_f5;
        } else if (temp_32 == 1) {
            spB4 = b88;
            spB8 = 0;
            spBC = fparg2 + temp_f6;
            spA8 = b88;
            spAC = 0;
            spB0 = fparg2;
            sp9C = b88 + temp_f5;
            spA0 = 0;
            spA4 = fparg2 + temp_f6;
            sp90 = b88 + temp_f5;
            sp94 = 0;
            sp98 = fparg2;
        }
        break;
    }
    {
        s32 t52 = ((u32)(arg3 & 0xFF000000) >> 24) & 0xFF;
        s32 t4 = ((u32)(arg3 & 0xFF0000) >> 16) & 0xFF;
        s32 t33 = ((u32)(arg3 & 0xFF00) >> 8) & 0xFF;
        s32 t22 = arg3 & 0xFF;
        s32 v6 = 0;
        s32 tt11 = t4 & 1;
        s32 tt10 = t33 & 1;
        s32 tt9 = t22 & 1;
        while (v6 < 4) {
            u8 *t13 = temp_16 + (v6 << 6);
            *(f32 *)(t13 + 0x48) = D_008872F8[0] - fparg2;
            *(f32 *)(t13 + 0x58) = temp_f0;
            if (t52 >= 0) {
                *(f32 *)(t13 + 0x60) = (f32)t52;
            } else {
                s32 q52 = ((u32)t52 >> 1) | (t52 & 1);
                f32 g52 = (f32)q52;
                g52 += g52;
                *(f32 *)(t13 + 0x60) = g52;
            }
            if (t4 >= 0) {
                *(f32 *)(t13 + 0x64) = (f32)t4;
            } else {
                s32 q4 = ((u32)t4 >> 1) | tt11;
                f32 g4 = (f32)q4;
                g4 += g4;
                *(f32 *)(t13 + 0x64) = g4;
            }
            if (t33 >= 0) {
                *(f32 *)(t13 + 0x68) = (f32)t33;
            } else {
                s32 q33 = ((u32)t33 >> 1) | tt10;
                f32 g33 = (f32)q33;
                g33 += g33;
                *(f32 *)(t13 + 0x68) = g33;
            }
            if (t22 >= 0) {
                *(f32 *)(t13 + 0x6C) = (f32)t22;
            } else {
                s32 q22 = ((u32)t22 >> 1) | tt9;
                f32 g22 = (f32)q22;
                g22 += g22;
                *(f32 *)(t13 + 0x6C) = g22;
            }
            *(f32 *)(t13 + 0x40) = *(f32 *)((u8 *)&sp90 + v6 * 12);
            *(f32 *)(t13 + 0x44) = *(f32 *)((u8 *)&sp90 + v6 * 12 + 8);
            v6 += 1;
        }
    }
    {
        u8 *t23 = (u8 *)func_00461390((u8 *)&D_00793E80 + (arg5 * 0x30), 4, temp_16 + 0x40, 4);
        *(void (**)())(t23 + 8) = (void (*)())func_002b07a0;
        *(u8 **)(t23 + 0x10) = temp_16;
    }
}

// Reverted (322 rows, obj 940B/1424B under-484, frame -144 vs -192; inferior to prior documented 99-floor with YVec2f+s8/s32 protos, 4-arg 461390, D_008872F8-hoist + s2/s3 walls). Draft used correct protos but condensed switches/loop (frame under). Do not re-probe without full faithful body. D_00793E80 decl kept (correct).
