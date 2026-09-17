/* func_0044fa90 floor 314w/132+5 366/367 bare wins. See sdkDbprt.c guard. */
/* Target: func_0044fa90 -- source-repo faithful floor (banked, production stays ASM).
 * Owner: src/sdkDbprt.c (source/Persona4-Decompilation, CRLF; candidates LF, probe normalises).
 * Retail: 0x0044FA90, window 1472B (0x5C0), 368 words / 367 instrs after padding strip.
 * Measured (source): probe_variants 314 words (reloc-masked), fnalign 132 edits (+5 reloc-only), obj 366 vs retail 367 (1464B/1472B).
 * Shape: uv[8] then quads[64] (reverse-alloc bases sp+0x140/sp+0x40), mixed scale forms (field outer / byte inner, 0x160 frame), split x0 (mul+add), byte text, dead low-nibble branch kept, unsigned colors, (s32) high, (s32)v>=0x80.
 * No owner edits; no pragma (bare wins words+edits jointly). See report.md for full sweep.
 */
void func_0044fa90(void) {
    extern void (*D_00887300[])(u32, u32);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern f32 D_008872F8[];
    extern f32 func_00450490(f32);
    typedef struct Ext Ext;
    struct Ext { HDbText3D *next; f32 x; f32 y; f32 scale; u8 text[256]; f32 unk110; u8 col[4]; };
    HDbText3D *node;
    s32 idx;
    f32 invW;
    f32 scaled;
    f32 uv[8];
    f32 quads[64];
    invW = 1.0f / *(f32 *)((u8 *)iGpffffb9e0 + 0x80);
    node = iGpffffb9dc;
    D_00887300[0](1, (u32)iGpffffb9e8);
    while (node != NULL) {
        if (((Ext *)node)->scale != 0.0f) {
            scaled = func_00450490(((Ext *)node)->scale);
        }
        idx = 0;
        while (idx < 0x100) {
            u8 ch;
            ch = *(u8 *)((u8 *)node + 0x10 + idx);
            if (ch == 0) {
                break;
            }
            if (ch != 0x20) {
                if (*(f32 *)((u8 *)node + 0xC) == 0.0f) {
                    u32 v;
                    f32 x0;
                    f32 y0;
                    f32 x1;
                    f32 y1;
                    s32 low;
                    s32 tmp;
                    f32 u0;
                    f32 vv0;
                    s32 j;
                    v = (ch - 0x20) & 0xFF;
                    if ((s32)v >= 0x80) {
                        v = (v - 0x20) & 0xFF;
                    }
                    x0 = 12.0f * (f32)idx;
                    x0 += ((Ext *)node)->x;
                    y0 = ((Ext *)node)->y;
                    x1 = 11.0f + x0;
                    y1 = 11.0f + y0;
                    low = (s32)((v & 0xFF) & 0xF);
                    tmp = (s32)(v & 0xFF);
                    if (tmp < 0 && low != 0) {
                        low -= 0x10;
                    }
                    u0 = 0.0625f * (f32)low;
                    vv0 = 0.0625f * (f32)(s32)((v & 0xFF) >> 4);
                    quads[0] = x0;
                    quads[1] = y0;
                    quads[16] = x1;
                    quads[17] = y0;
                    quads[32] = x0;
                    quads[33] = y1;
                    quads[48] = x1;
                    quads[49] = y1;
                    uv[0] = u0;
                    uv[1] = vv0;
                    uv[2] = 0.046875f + u0;
                    uv[3] = vv0;
                    uv[4] = u0;
                    uv[5] = 0.046875f + vv0;
                    uv[6] = 0.046875f + u0;
                    uv[7] = 0.046875f + vv0;
                    j = 0;
                    while (j < 4) {
                        f32 *quad;
                        f32 *uvp;
                        quad = &quads[j * 16];
                        uvp = &uv[j * 2];
                        quad[2] = D_008872F8[0] - ((Ext *)node)->unk110;
                        quad[8] = (f32)(u32)((Ext *)node)->col[0];
                        quad[9] = (f32)(u32)((Ext *)node)->col[1];
                        quad[10] = (f32)(u32)((Ext *)node)->col[2];
                        quad[11] = (f32)(u32)((Ext *)node)->col[3];
                        quad[6] = invW;
                        quad[4] = uvp[0];
                        quad[5] = uvp[1];
                        j += 1;
                    }
                    D_00887310[0](4, quads, 4);
                } else {
                    u32 v;
                    f32 x0;
                    f32 y0;
                    f32 x1;
                    f32 y1;
                    s32 low;
                    s32 tmp;
                    f32 u0;
                    f32 vv0;
                    s32 j;
                    v = (ch - 0x20) & 0xFF;
                    if ((s32)v >= 0x80) {
                        v = (v - 0x20) & 0xFF;
                    }
                    x0 = 12.0f * (f32)idx;
                    x0 += ((Ext *)node)->x;
                    y0 = ((Ext *)node)->y;
                    x1 = 11.0f + x0;
                    y1 = 11.0f + y0;
                    low = (s32)((v & 0xFF) & 0xF);
                    tmp = (s32)(v & 0xFF);
                    if (tmp < 0 && low != 0) {
                        low -= 0x10;
                    }
                    u0 = 0.0625f * (f32)low;
                    vv0 = 0.0625f * (f32)(s32)((v & 0xFF) >> 4);
                    quads[0] = x0;
                    quads[1] = y0;
                    quads[16] = x1;
                    quads[17] = y0;
                    quads[32] = x0;
                    quads[33] = y1;
                    quads[48] = x1;
                    quads[49] = y1;
                    uv[0] = u0;
                    uv[1] = vv0;
                    uv[2] = 0.046875f + u0;
                    uv[3] = vv0;
                    uv[4] = u0;
                    uv[5] = 0.046875f + vv0;
                    uv[6] = 0.046875f + u0;
                    uv[7] = 0.046875f + vv0;
                    j = 0;
                    while (j < 4) {
                        f32 *quad;
                        f32 *uvp;
                        quad = &quads[j * 16];
                        uvp = &uv[j * 2];
                        quad[2] = scaled;
                        quad[8] = (f32)(u32)((Ext *)node)->col[0];
                        quad[9] = (f32)(u32)((Ext *)node)->col[1];
                        quad[10] = (f32)(u32)((Ext *)node)->col[2];
                        quad[11] = (f32)(u32)((Ext *)node)->col[3];
                        quad[6] = invW;
                        quad[4] = uvp[0];
                        quad[5] = uvp[1];
                        j += 1;
                    }
                    D_00887310[0](4, quads, 4);
                }
            }
            idx += 1;
        }
        node = node->next;
    }
}
