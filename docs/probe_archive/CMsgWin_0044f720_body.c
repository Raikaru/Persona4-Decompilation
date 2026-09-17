/* func_0044f720 floor 163w/87+8 920/880B over bare wins. See sdkDbprt.c guard. */
void func_0044f720(void)
{
    extern s32 func_003e8120(s32 arg0);
    extern void func_003e8110(s32 arg0);
    extern void func_0044fa90(void);
    extern void func_00450630(void);
    extern void (*D_00887300[])(u32, u32);
    extern void (*D_00887304[])(s32, s32 *);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern f32 D_008872F8[];
    f32 uv[8];
    f32 quads[64];
    s32 save;
    f32 inv;
    f32 rowY;
    f32 rowY1;
    s32 row;
    s32 col;
    u32 vtBase;
    u8 *gridRow;

    inv = 1.0f / *(f32 *)((u8 *)iGpffffb9e0 + 0x80);
    if (func_003e8120((s32)iGpffffb9e0) != 0) {
        D_00887304[0](14, &save);
        vtBase = (u32)D_00887300;
        ((void (*)(u32, u32))*(u32 *)vtBase)(14, 0);
        ((void (*)(u32, u32))*(u32 *)vtBase)(6, 1);
        ((void (*)(u32, u32))*(u32 *)vtBase)(7, 2);
        ((void (*)(u32, u32))*(u32 *)vtBase)(8, 1);
        ((void (*)(u32, u32))*(u32 *)vtBase)(9, 1);
        ((void (*)(u32, u32))*(u32 *)vtBase)(12, 1);
        ((void (*)(u32, u32))*(u32 *)vtBase)(1, (u32)iGpffffb9e8);
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                quads[i * 16 + 6] = inv;
                *(s32 *)&quads[i * 16 + 8] = 0x437F0000;
                *(s32 *)&quads[i * 16 + 9] = 0x437F0000;
                *(s32 *)&quads[i * 16 + 10] = 0x437F0000;
                *(s32 *)&quads[i * 16 + 11] = 0x437F0000;
                quads[i * 16 + 2] = D_008872F8[0];
            }
        }
        for (row = 0; row < 0x28; row++) {
            gridRow = (u8 *)((u32)D_008BF720 + (u32)(row * 0x35));
            rowY = 12.0f * (f32)row;
            rowY1 = 11.0f + rowY;
            for (col = 0; col < 0x35; col++) {
                u8 ch;
                ch = *(u8 *)((u8 *)gridRow + col);
                if (ch != 0x20) {
                    u32 v;
                    f32 x0;
                    f32 x1;
                    s32 low;
                    s32 tmp;
                    f32 u0;
                    f32 vv0;
                    s32 k;
                    v = (ch - 0x20) & 0xFF;
                    if ((s32)v >= 0x80) {
                        v = (v - 0x20) & 0xFF;
                    }
                    x0 = 12.0f * (f32)col;
                    x1 = 11.0f + x0;
                    quads[0] = x0;
                    quads[1] = rowY;
                    quads[16] = x1;
                    quads[17] = rowY;
                    quads[32] = x0;
                    quads[33] = rowY1;
                    quads[48] = x1;
                    quads[49] = rowY1;
                    low = (s32)((v & 0xFF) & 0xF);
                    tmp = (s32)(v & 0xFF);
                    if (tmp < 0 && low != 0) {
                        low -= 0x10;
                    }
                    u0 = 0.0625f * (f32)low;
                    vv0 = 0.0625f * (f32)(s32)((v & 0xFF) >> 4);
                    uv[0] = u0;
                    uv[1] = vv0;
                    uv[2] = 0.046875f + u0;
                    uv[3] = vv0;
                    uv[4] = u0;
                    uv[5] = 0.046875f + vv0;
                    uv[6] = 0.046875f + u0;
                    uv[7] = 0.046875f + vv0;
                    k = 0;
                    while (k < 4) {
                        f32 *quad;
                        f32 *uvp;
                        quad = &quads[k * 16];
                        uvp = &uv[k * 2];
                        quad[4] = uvp[0];
                        quad[5] = uvp[1];
                        k += 1;
                    }
                    D_00887310[0](4, quads, 4);
                }
            }
        }
        func_0044fa90();
        func_00450630();
        ((void (*)(u32, u32))*(u32 *)vtBase)(14, save);
        func_003e8110((s32)iGpffffb9e0);
    }
}
