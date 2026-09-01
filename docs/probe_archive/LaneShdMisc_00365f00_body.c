/* Closest clean-C probe for func_00365f00; object 1720B over a 1152B window,
   normalized diff 414. Rejected: packet stack placement and compiler schedule
   remain different from retail. */
void func_00365f00(s64 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 packet[102][16];
    s64 origin_bits;
    s32 color1_bits;
    s32 color2_bits;
    s32 count;
    s32 i;
    s32 t;
    f32 origin_x;
    f32 origin_y;
    f32 z;
    f32 scale;
    f32 angle;
    f32 sine;
    f32 cosine;
    u8 *color1;
    u8 *color2;

    origin_bits = arg0;
    color1_bits = arg1;
    color2_bits = arg2;
    count = arg3 & 0xFFFF;
    if ((count <= 0) || (count >= 0x65)) {
        func_0046d730(D_0064E2F8, 0x23B);
    }
    origin_x = *(f32 *)(void *)&origin_bits;
    origin_y = *((f32 *)(void *)&origin_bits + 1);
    z = D_008872F8[0] - fparg0;
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    color1 = (u8 *)(void *)&color1_bits;
    color2 = (u8 *)(void *)&color2_bits;

    packet[0][0] = origin_x;
    packet[0][1] = origin_y;
    packet[0][2] = z;
    if ((s8)color1[0] >= 0) {
        packet[0][8] = (f32)color1[0];
    } else {
        t = ((u32)color1[0] >> 1) | (color1[0] & 1);
        packet[0][8] = (f32)t;
        packet[0][8] += packet[0][8];
    }
    if ((s8)color1[1] >= 0) {
        packet[0][9] = (f32)color1[1];
    } else {
        t = ((u32)color1[1] >> 1) | (color1[1] & 1);
        packet[0][9] = (f32)t;
        packet[0][9] += packet[0][9];
    }
    if ((s8)color1[2] >= 0) {
        packet[0][10] = (f32)color1[2];
    } else {
        t = ((u32)color1[2] >> 1) | (color1[2] & 1);
        packet[0][10] = (f32)t;
        packet[0][10] += packet[0][10];
    }
    if ((s8)color1[3] >= 0) {
        packet[0][11] = (f32)color1[3];
    } else {
        t = ((u32)color1[3] >> 1) | (color1[3] & 1);
        packet[0][11] = (f32)t;
        packet[0][11] += packet[0][11];
    }
    packet[0][6] = scale;

    for (i = 0; i <= count; i++) {
        if (arg3 >= 0) {
            angle = fparg2 + (iGpffff81e0 * (f32)i) / (f32)arg3;
        } else {
            t = ((u32)arg3 >> 1) | (arg3 & 1);
            angle = fparg2 + (iGpffff81e0 * (f32)i) / (f32)t;
        }
        sine = func_0044b7b0(angle);
        packet[i + 1][0] = origin_x + fparg3 * (fparg1 * sine);
        cosine = func_0044b610(angle);
        packet[i + 1][1] = origin_y + fparg4 * (fparg1 * cosine);
        packet[i + 1][2] = z;
        if ((s8)color2[0] >= 0) {
            packet[i + 1][8] = (f32)color2[0];
        } else {
            t = ((u32)color2[0] >> 1) | (color2[0] & 1);
            packet[i + 1][8] = (f32)t;
            packet[i + 1][8] += packet[i + 1][8];
        }
        if ((s8)color2[1] >= 0) {
            packet[i + 1][9] = (f32)color2[1];
        } else {
            t = ((u32)color2[1] >> 1) | (color2[1] & 1);
            packet[i + 1][9] = (f32)t;
            packet[i + 1][9] += packet[i + 1][9];
        }
        if ((s8)color2[2] >= 0) {
            packet[i + 1][10] = (f32)color2[2];
        } else {
            t = ((u32)color2[2] >> 1) | (color2[2] & 1);
            packet[i + 1][10] = (f32)t;
            packet[i + 1][10] += packet[i + 1][10];
        }
        if ((s8)color2[3] >= 0) {
            packet[i + 1][11] = (f32)color2[3];
        } else {
            t = ((u32)color2[3] >> 1) | (color2[3] & 1);
            packet[i + 1][11] = (f32)t;
            packet[i + 1][11] += packet[i + 1][11];
        }
        packet[i + 1][6] = scale;
    }
    D_00887300[0](1, 0);
    if (arg4 != 0) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](5, &packet[0], count + 2);
    if (arg4 != 0) {
        iGpffffabe8 &= ~0x80;
    }
}
