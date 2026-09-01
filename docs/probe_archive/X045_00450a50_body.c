/* func_00450a50 archive: object 936 bytes, retail window 896 bytes, normalized_diff 619.
 * Differing instruction offsets (fndiff): 0x74, 0x90-0x168, 0x170-0x1c0, 0x1c8-0x1f0, 0x1fc-0x268, 0x284-0x28c, 0x298-0x2d4, 0x2dc-0x36c, 0x374-0x3a4.
 * Casts written: lbu arg0 bytes c0/c1/c2/c3 -> (f32)(u32)c0, (f32)(u32)c1,
 * (f32)(u32)c2, (f32)(u32)c3; loop index -> (f32)i; low nibble ->
 * (f32)low_nibble; high nibble -> (f32)((u32)(ch & 0xff) >> 4).
 * Callee/global declarations added at file scope: iGpffffb9e8, D_00887300,
 * D_00887310; no callee signature corrections were required.
 * Ruled out: direct plain-cast candidate still has register/control-flow and
 * texture-loop residuals; no volatile, inline asm, pragma, or scheduler probes.
 */
{
    struct Glyph {
        f32 x;
        f32 y;
        f32 value;
        f32 padc;
        f32 u;
        f32 v;
        f32 scale;
        f32 c0;
        f32 c1;
        f32 c2;
        f32 c3;
        u8 pad30[0x10];
    };
    struct {
        struct Glyph glyph[4];
        f32 uv[8];
        u8 tail[0x10];
    } work;
    s32 i;
    s32 c3;
    s32 c2;
    s32 c1;
    s32 c0;
    f32 low;
    f32 high;
    f32 scale;
    f32 base_y;
    s32 flag;

    high = ((f32 *)&arg1)[1];
    low = ((f32 *)&arg1)[0];
    c3 = ((u8 *)&arg0)[3];
    c2 = ((u8 *)&arg0)[2];
    c1 = ((u8 *)&arg0)[1];
    c0 = ((u8 *)&arg0)[0];
    scale = 1.0f / *(f32 *)(iGpffffb9e0 + 0x80);
    flag = iGpffffb9e8;
    if (flag == 0) {
        return;
    }
    D_00887300[0](1, flag);
    {
        s32 j;

        j = 0;
        do {
            work.glyph[j].scale = scale;
            work.glyph[j].c0 = (f32)(u32)c0;
            work.glyph[j].c1 = (f32)(u32)c1;
            work.glyph[j].c2 = (f32)(u32)c2;
            work.glyph[j].c3 = (f32)(u32)c3;
            work.glyph[j].value = *(f32 *)D_008872F8_abs - fparg0;
            j++;
        } while (j < 4);
    }

    base_y = 11.0f + high;
    i = 0;
    do {
        s32 ch;

        ch = ((u8 *)arg2)[i];
        if (ch == 0) {
            break;
        }
        if (ch != 32) {
            s32 nibble;
            s32 low_nibble;
            s32 j;
            f32 u;
            f32 v;
            f32 u2;
            f32 v2;

            ch = (ch - 32) & 0xFF;
            if (ch >= 0x80) {
                ch = (ch - 32) & 0xFF;
            }
            work.glyph[0].x = 12.0f * (f32)i + low;
            work.glyph[0].y = high;
            work.glyph[1].x = 11.0f + 12.0f * (f32)i + low;
            work.glyph[1].y = high;
            work.glyph[2].x = 12.0f * (f32)i + low;
            work.glyph[2].y = base_y;
            work.glyph[3].x = 11.0f + 12.0f * (f32)i + low;
            work.glyph[3].y = base_y;
            nibble = ch & 0xFF;
            low_nibble = nibble & 0xF;
            if ((nibble < 0) && (low_nibble != 0)) {
                low_nibble -= 0x10;
            }
            u = 0.0625f * (f32)low_nibble;
            v = 0.0625f * (f32)((u32)(ch & 0xFF) >> 4);
            u2 = 0.046875f + u;
            v2 = 0.046875f + v;
            work.uv[0] = u;
            work.uv[1] = v;
            work.uv[2] = u2;
            work.uv[3] = v;
            work.uv[4] = u;
            work.uv[5] = v2;
            work.uv[6] = u2;
            work.uv[7] = v2;
            for (j = 0; j < 4; j++) {
                work.glyph[j].u = work.uv[j * 2];
                work.glyph[j].v = work.uv[j * 2 + 1];
            }
            D_00887310[0](4, work.glyph, 4);
        }
        i++;
    } while (i < 0x100);
}