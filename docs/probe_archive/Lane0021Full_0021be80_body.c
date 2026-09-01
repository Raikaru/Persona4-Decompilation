/* Closest attempted candidate for func_0021be80; reverted because it did not match retail (object 3228B vs 5568B, nd 2356). */
void func_0021be80(u8 *arg0, u8 *arg1)
{
    extern void func_0021bbb0(s32 color, s32 frame);
    extern void func_0021b500(void *dst, f32 x, f32 y, f32 z, f32 u, f32 v,
                              s32 color);
    extern s32 func_003b7060(void);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern u8 *func_00457120(void);
    extern void func_0046d730(void *file, s32 line);
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    extern void func_0021b630(f32 f0, f32 f1, f32 f2, f32 f3, f32 f4,
                              f32 f5, f32 f6, f32 f7, s32 color, f32 f8);
    extern f32 D_00628FD0[];
    extern f32 D_00628FE8[];
    extern f32 D_00629000[];
    extern f32 D_00629018[];
    extern f32 D_00629030[];
    extern f32 D_006290B0;
    extern f32 D_006290B4;
    extern f32 D_006290B8;
    extern f32 D_006290BC;
    extern f32 D_008872F8;
    extern f32 fGpffff84cc;
    extern f32 fGpffff84d0;
    u8 quad[0x100];
    u8 color0[4];
    u8 *ctx;
    f32 *tile;
    f32 *tex;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 u0;
    f32 v0;
    f32 du;
    f32 dv;
    f32 scale;
    f32 z;
    f32 randomf;
    f32 edge;
    f32 width;
    f32 height;
    f32 texw;
    f32 texh;
    s32 mode;
    s32 frame;
    s32 i;
    s32 j;
    s32 bit;
    s32 id;
    s32 row;
    s32 group;
    s32 side;
    s32 signx;
    s32 signy;
    s32 value;
    s32 flags;
    s32 color;
    s32 base;
    u16 index;

    (void)arg0;
    ctx = func_00452560(*(s32 *)(arg1 + 8));
    func_00201350();
    mode = *(u16 *)arg1;
    if (mode & 1) {
        frame = *(u16 *)(arg1 + 2);
        if (frame < 0x30) {
            if (*(u16 *)(iGpffffb3ac + 0x1A) == 1) {
                if (frame == 4) {
                    func_0045af60(1, 14, 2, 0);
                }
                color = 0xFFFF9F2D;
                func_0021bbb0(color, frame);
                D_00887300[0](1, iGpffffb470);
                func_0021b630(D_00628FD0[0], D_00628FD0[1], 0.0f,
                              D_00628FD0[2], D_00628FD0[3], D_00628FD0[4],
                              D_00628FD0[5], D_00628FD0[4] + D_00628FD0[2],
                              color, D_00628FD0[5] + D_00628FD0[3]);
                func_0021b630(D_00628FE8[0], D_00628FE8[1], 0.0f,
                              D_00628FE8[2], D_00628FE8[3], D_00628FE8[4],
                              D_00628FE8[5], D_00628FE8[4] + D_00628FE8[2],
                              color, D_00628FE8[5] + D_00628FE8[3]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              -fGpffff84cc * D_00629030[2], -D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              fGpffff84cc * D_00629030[2], -D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_003f6440(2, 0x48);
                color = 0xFF6B9EFF;
                index = *(u16 *)(arg1 + 4);
                if (index >= 0xC) {
                    func_0046d730((void *)&D_00629030[0], 0xC6);
                }
                for (i = 0; i < 4; i++) {
                    id = (i == 0) ? index : ((i == 1) ? index + 6 :
                         (i == 2) ? (index + 1) % 6 : ((index + 7) % 6));
                    row = (id % 6 < 3) ? (id % 3) : (3 - (id % 3));
                    tile = &D_00628FD0[(row + 5) * 6];
                    group = id / 6;
                    side = ((id / 3) + group) & 1;
                    signx = (side == 0) ? 1 : -1;
                    signy = (group == 0) ? 1 : -1;
                    func_0021b630(tile[0], tile[1], 0.0f,
                                  fGpffff84cc * (f32)(-signx) * tile[2],
                                  (f32)(-signy) * tile[3],
                                  tile[4] + tile[2], tile[5] + tile[3], tile[4],
                                  color, tile[5]);
                }
                func_003f6440(2, 0x44);
                color0[0] = 0x14;
                color0[1] = 0x14;
                color0[2] = 0x14;
                color0[3] = 0xFF;
                tex = D_00629000;
                x0 = tex[0];
                y0 = tex[1];
                u0 = tex[2];
                v0 = tex[3];
                width = tex[4];
                height = tex[5];
                z = D_008872F8;
                for (i = 0; i < 4; i++) {
                    func_0021b500(quad + i * 0x40,
                                  x0 + ((i == 1 || i == 3) ? width : 0.0f),
                                  y0 + ((i >= 2) ? height : 0.0f), z,
                                  (i == 1 || i == 3) ? width / 256.0f : 0.0f,
                                  (i >= 2) ? height / 256.0f : 0.0f,
                                  *(s32 *)color0);
                }
                D_00887310[0](4, quad, 4);
                index = *(u16 *)(arg1 + 4) + 1;
                *(u16 *)(arg1 + 4) = (index >= 6) ? 0 : index;
            } else {
                if (frame == 4) {
                    func_0045af60(1, 14, 2, 1);
                }
                color = 0xFF2324FF;
                func_0021bbb0(color, frame);
                D_00887300[0](1, iGpffffb470);
                func_0021b630(D_00628FD0[0], D_00628FD0[1], 0.0f,
                              D_00628FD0[2], D_00628FD0[3], D_00628FD0[4],
                              D_00628FD0[5], D_00628FD0[4] + D_00628FD0[2],
                              color, D_00628FD0[5] + D_00628FD0[3]);
                func_0021b630(D_00628FE8[0], D_00628FE8[1], 0.0f,
                              D_00628FE8[2], D_00628FE8[3], D_00628FE8[4],
                              D_00628FE8[5], D_00628FE8[4] + D_00628FE8[2],
                              color, D_00628FE8[5] + D_00628FE8[3]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              -fGpffff84cc * D_00629030[2], D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              fGpffff84cc * D_00629030[2], D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_003f6440(2, 0x48);
                color = 0xFF2727FF;
                for (i = 0; i < 12; i++) {
                    bit = 1 << i;
                    if (bit & 0xC61) {
                        value = func_003b7060();
                        randomf = (value < 0) ? (f32)(2 * (((u32)value >> 1) | (value & 1))) :
                            (f32)value;
                        if ((s32)(4.0f * (randomf / 2147483600.0f)) == 0) {
                            row = (i % 6 < 3) ? (i % 3) : (3 - (i % 3));
                            tile = &D_00628FD0[(row + 5) * 6];
                            group = i / 6;
                            side = ((i / 3) + group) & 1;
                            signx = (side == 0) ? 1 : -1;
                            signy = (group == 0) ? 1 : -1;
                            func_0021b630(tile[0], tile[1], 0.0f,
                                          fGpffff84cc * (f32)(-signx) * tile[2],
                                          (f32)(-signy) * tile[3],
                                          tile[4] + tile[2], tile[5] + tile[3],
                                          tile[4], color, tile[5]);
                        }
                    }
                    if (*(u16 *)(arg1 + 4) & bit) {
                        row = (i % 6 < 3) ? (i % 3) : (3 - (i % 3));
                        tile = &D_00628FD0[(row + 5) * 6];
                        group = i / 6;
                        side = ((i / 3) + group) & 1;
                        signx = (side == 0) ? 1 : -1;
                        signy = (group == 0) ? 1 : -1;
                        func_0021b630(tile[0], tile[1], 0.0f,
                                      fGpffff84cc * (f32)(-signx) * tile[2],
                                      (f32)(-signy) * tile[3],
                                      tile[4] + tile[2], tile[5] + tile[3],
                                      tile[4], color, tile[5]);
                    }
                }
                func_003f6440(2, 0x44);
                color0[0] = 0x14;
                color0[1] = 0x14;
                color0[2] = 0x14;
                color0[3] = 0xFF;
                tex = D_00629018;
                x0 = tex[0];
                y0 = tex[1];
                u0 = tex[2];
                v0 = tex[3];
                width = tex[4];
                height = tex[5];
                z = D_008872F8;
                for (i = 0; i < 4; i++) {
                    func_0021b500(quad + i * 0x40,
                                  x0 + ((i == 1 || i == 3) ? width : 0.0f),
                                  y0 + ((i >= 2) ? height : 0.0f), z,
                                  (i == 1 || i == 3) ? width / 256.0f : 0.0f,
                                  (i >= 2) ? height / 256.0f : 0.0f,
                                  *(s32 *)color0);
                }
                D_00887310[0](4, quad, 4);
                index = *(u16 *)(arg1 + 2);
                if ((index & 1) == 0) {
                    value = func_003b7060();
                    randomf = (value < 0) ? (f32)(2 * (((u32)value >> 1) | (value & 1))) :
                        (f32)value;
                    value = (s32)(2.0f * (randomf / 2147483600.0f));
                    *(u16 *)(arg1 + 4) = (u16)(func_003b7060() & (0xAAAAA >> value));
                }
            }
            (*(u16 *)(arg1 + 2))++;
            return;
        }
        *(u16 *)arg1 &= (u16)~1;
    }
}
