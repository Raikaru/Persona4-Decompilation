/* Closest clean-C probe for func_00364fb0; object 1488B over a 2080B window,
   normalized diff 495. Rejected after one structural attempt. */
void func_00364fb0(s64 arg0, u32 arg1, s32 arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    f32 vertices[4][16];
    f32 origin_x;
    f32 origin_y;
    f32 z;
    f32 scale;
    f32 sine;
    f32 cosine;
    f32 xoff;
    f32 yoff;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    s32 i;
    s32 t;

    origin_x = *(f32 *)(void *)&arg0;
    origin_y = *((f32 *)(void *)&arg0 + 1);
    z = D_008872F8[0] - fparg0;
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    sine = func_0044b7b0(fparg1);
    cosine = func_0044b610(fparg1);
    c0 = ((arg1 & 0xFF000000) >> 24) & 0xFF;
    c1 = ((arg1 & 0x00FF0000) >> 16) & 0xFF;
    c2 = ((arg1 & 0x0000FF00) >> 8) & 0xFF;
    c3 = arg1 & 0xFF;

    vertices[0][0] = origin_x;
    vertices[0][1] = origin_y;
    vertices[0][2] = z - fparg0;
    if (c0 >= 0) {
        vertices[0][8] = (f32)c0;
    } else {
        t = ((u32)c0 >> 1) | (c0 & 1);
        vertices[0][8] = (f32)t;
        vertices[0][8] += vertices[0][8];
    }
    if (c1 >= 0) {
        vertices[0][9] = (f32)c1;
    } else {
        t = ((u32)c1 >> 1) | (c1 & 1);
        vertices[0][9] = (f32)t;
        vertices[0][9] += vertices[0][9];
    }
    if (c2 >= 0) {
        vertices[0][10] = (f32)c2;
    } else {
        t = ((u32)c2 >> 1) | (c2 & 1);
        vertices[0][10] = (f32)t;
        vertices[0][10] += vertices[0][10];
    }
    if (c3 >= 0) {
        vertices[0][11] = (f32)c3;
    } else {
        t = ((u32)c3 >> 1) | (c3 & 1);
        vertices[0][11] = (f32)t;
        vertices[0][11] += vertices[0][11];
    }
    vertices[0][6] = scale;

    xoff = 71.0f * cosine;
    yoff = 71.0f * sine;
    vertices[1][0] = origin_x + xoff;
    vertices[1][1] = origin_y + yoff;
    vertices[1][2] = z;
    if (c0 >= 0) {
        vertices[1][8] = (f32)c0;
    } else {
        t = ((u32)c0 >> 1) | (c0 & 1);
        vertices[1][8] = (f32)t;
        vertices[1][8] += vertices[1][8];
    }
    if (c1 >= 0) {
        vertices[1][9] = (f32)c1;
    } else {
        t = ((u32)c1 >> 1) | (c1 & 1);
        vertices[1][9] = (f32)t;
        vertices[1][9] += vertices[1][9];
    }
    if (c2 >= 0) {
        vertices[1][10] = (f32)c2;
    } else {
        t = ((u32)c2 >> 1) | (c2 & 1);
        vertices[1][10] = (f32)t;
        vertices[1][10] += vertices[1][10];
    }
    if (c3 >= 0) {
        vertices[1][11] = (f32)c3;
    } else {
        t = ((u32)c3 >> 1) | (c3 & 1);
        vertices[1][11] = (f32)t;
        vertices[1][11] += vertices[1][11];
    }
    vertices[1][6] = scale;

    if (arg3 != 0) {
        vertices[2][0] = origin_x - 402.0f * sine;
        vertices[2][1] = origin_y + 402.0f * cosine;
        vertices[3][0] = origin_x + xoff - 473.0f * sine;
        vertices[3][1] = origin_y + yoff + 473.0f * cosine;
    } else {
        vertices[2][0] = origin_x - 473.0f * sine;
        vertices[2][1] = origin_y + 473.0f * cosine;
        vertices[3][0] = origin_x + xoff - 402.0f * sine;
        vertices[3][1] = origin_y + yoff + 402.0f * cosine;
    }
    vertices[2][2] = z;
    vertices[3][2] = z;
    for (i = 2; i < 4; i++) {
        if (c0 >= 0) {
            vertices[i][8] = (f32)c0;
        } else {
            t = ((u32)c0 >> 1) | (c0 & 1);
            vertices[i][8] = (f32)t;
            vertices[i][8] += vertices[i][8];
        }
        if (c1 >= 0) {
            vertices[i][9] = (f32)c1;
        } else {
            t = ((u32)c1 >> 1) | (c1 & 1);
            vertices[i][9] = (f32)t;
            vertices[i][9] += vertices[i][9];
        }
        if (c2 >= 0) {
            vertices[i][10] = (f32)c2;
        } else {
            t = ((u32)c2 >> 1) | (c2 & 1);
            vertices[i][10] = (f32)t;
            vertices[i][10] += vertices[i][10];
        }
        if (c3 >= 0) {
            vertices[i][11] = (f32)c3;
        } else {
            t = ((u32)c3 >> 1) | (c3 & 1);
            vertices[i][11] = (f32)t;
            vertices[i][11] += vertices[i][11];
        }
        vertices[i][6] = scale;
    }
    if (arg2 != 0) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](4, &vertices[0], 4);
    if (arg2 != 0) {
        iGpffffabe8 &= ~0x80;
    }
}
