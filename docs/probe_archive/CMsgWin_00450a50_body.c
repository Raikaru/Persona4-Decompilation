/* func_00450a50 floor 204w/194+4 224/224 exact s1 wins. See code1_0045.c guard. */
void func_00450a50(s32 arg0, s64 arg1, f32 fparg0, void *arg2)
{
    f32 vertices[4][16];
    Code45TexCoords uvs[4];
    PackedColor4 color;
    PackedVec2f pos;
    f32 farg;
    u8 *str;
    f32 inv;
    f32 fsub;
    s32 flag;
    s32 i;
    s32 j;
    s32 k;
    f32 fx;
    f32 fy;
    f32 fz;
    f32 fw;

    color.packed = arg0;
    pos.packed = arg1;
    farg = fparg0;
    str = (u8 *)arg2;
    inv = 1.0f / *(f32 *)(iGpffffb9e0 + 0x80);
    flag = iGpffffb9e8;
    if (flag == 0) {
        return;
    }
    D_00887300[0](1, flag);
    fsub = D_008872F8 - farg;
    for (i = 0; i < 4; i++) {
        vertices[i][6] = inv;
        vertices[i][8] = (f32)(u32)color.rgba[0];
        vertices[i][9] = (f32)(u32)color.rgba[1];
        vertices[i][10] = (f32)(u32)color.rgba[2];
        vertices[i][11] = (f32)(u32)color.rgba[3];
        vertices[i][2] = fsub;
    }
    fw = 11.0f + pos.xy.y;
    for (j = 0; j < 256; j++) {
        u8 ch;
        ch = str[j];
        if (ch == 0) {
            return;
        }
        if (ch == 0x20) {
            continue;
        }
        ch -= 0x20;
        if (ch >= 0x80) {
            ch -= 0x20;
        }
        fx = 12.0f * (f32)j;
        fy = fx + pos.xy.x;
        fz = 11.0f + fx + pos.xy.x;
        vertices[0][0] = fy;
        vertices[0][1] = pos.xy.y;
        vertices[1][0] = fz;
        vertices[1][1] = pos.xy.y;
        vertices[2][0] = fy;
        vertices[2][1] = fw;
        vertices[3][0] = fz;
        vertices[3][1] = fw;
        {
            s32 lo;
            s32 hi;
            lo = ch & 0xFF;
            hi = lo & 0xF;
            if (lo < 0) {
                if (hi != 0) {
                    hi -= 0x10;
                }
            }
            uvs[0].u = 0.0625f * (f32)hi;
            uvs[0].v = 0.0625f * (f32)(u32)((ch & 0xFF) >> 4);
            uvs[1].u = 0.046875f + uvs[0].u;
            uvs[1].v = uvs[0].v;
            uvs[2].u = uvs[0].u;
            uvs[2].v = 0.046875f + uvs[0].v;
            uvs[3].u = uvs[1].u;
            uvs[3].v = uvs[2].v;
        }
        for (k = 0; k < 4; k++) {
            vertices[k][4] = uvs[k].u;
            vertices[k][5] = uvs[k].v;
        }
        D_00887310[0](4, vertices, 4);
    }
}
