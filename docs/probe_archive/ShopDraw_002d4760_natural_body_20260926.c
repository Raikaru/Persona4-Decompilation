/* Colour rows are u8[4] (r, g, b, pad).  Both setters address the g/b
   bytes through component pointers: the selected-tab path stores through
   the g/b addresses again after the second func_002e26f0 call, and retail
   keeps exactly those addresses live in saved registers ($s0/$s6/$s7/$fp).
   A local RGBA struct array instead grows the frame by 0x20. */
#define SHOP_SET_RGB(rgb, r, g, b) do { \
    u8 *g_ = &(rgb)[1];                  \
    u8 *b_ = &(rgb)[2];                  \
    (rgb)[0] = (r);                      \
    *g_ = (g);                           \
    *b_ = (b);                           \
} while (0)
#define SHOP_SET_GRAY(rgb, v) do {       \
    u8 *b_ = &(rgb)[2];                  \
    u8 *g_ = &(rgb)[1];                  \
    (rgb)[0] = *g_ = *b_ = (v);          \
} while (0)
#define SHOP_SPRITE(handle) ((ShopWork *)func_002e04e0(handle))

/* measured: MATCH (1,996 code bytes in the 2,000-byte window).  Sets the
   three shop tabs' priority, y and colour; the selected tab is highlighted
   and tabs whose stock is exhausted are greyed out. */
// FUN_002D4760
s8 func_002d4760(void *arg0, s8 arg1) {
    u8 colorA[3][4];
    u8 colorB[3][4];
    s16 primary[3];
    s16 secondary[3];
    s16 y[3][2];
    s16 thirdY[3];
    s16 i;
    s16 j;
    s32 sel;
    ShopWork *work;
    u8 *ca;
    u8 *cb;
    s16 *row;
    u8 r;
    u8 g;
    u8 b;

    work = *(ShopWork **)((u8 *)arg0 + 0x38);
    colorA[0][0] = colorA[2][0] = 0xBD;
    colorA[0][1] = colorA[2][1] = 0x68;
    colorA[0][2] = colorA[2][2] = 3;
    primary[0] = primary[2] = 0x56;
    y[0][0] = y[2][0] = 0x86;
    y[0][1] = y[2][1] = 0x87;
    colorB[0][0] = colorB[2][0] = 0x2D;
    colorB[0][1] = colorB[2][1] = 0x2D;
    colorB[0][2] = colorB[2][2] = 0x2D;
    secondary[0] = secondary[2] = primary[0] + 1;
    thirdY[0] = thirdY[2] = 0x85;
    colorA[1][0] = 0x90;
    colorA[1][1] = 0x4F;
    colorA[1][2] = 1;
    primary[1] = 0x41;
    y[1][0] = 0x89;
    y[1][1] = 0x8A;
    colorB[1][0] = 0x2D;
    colorB[1][1] = 0x2D;
    colorB[1][2] = 0x2D;
    secondary[1] = primary[1] + 1;
    thirdY[1] = 0x88;
    /* The F18 handles are read by byte offset: work->field_F18[i] adds
       the index before the base (addu v1, v0, work) and misses by one word. */
    for (i = 0, sel = arg1; i < 3; i++) {
        if (func_002e26f0(*(void **)((u8 *)work + 0xF18 + i * 4)) <= D_00748908[i]) {
            SHOP_SET_GRAY(colorA[i], 0x2D);
            if (i == 1) {
                SHOP_SET_GRAY(colorA[i], 0);
            }
            SHOP_SET_GRAY(colorB[i], 0x6F);
        }
        if (i == sel) {
            SHOP_SET_RGB(colorA[i], 0xFF, 0x96, 1);
            primary[i] = 0x57;
            row = y[i];
            row[0] = 0x83;
            row[1] = 0x84;
            SHOP_SET_RGB(colorB[i], 0xFF, 0xF2, 0x95);
            secondary[i] = primary[i] + 1;
            thirdY[i] = 0x82;
            if (func_002e26f0(*(void **)((u8 *)work + 0xF18 + i * 4)) <= D_00748908[i]) {
                SHOP_SET_GRAY(colorA[i], 0x9C);
                SHOP_SET_GRAY(colorB[i], 0xFF);
            }
        }
    }
    /* Colour bytes of the first sprite are kept in r/g/b for the second. */
    for (j = 0; j < 3; j++) {
        switch (j) {
        case 0:
            SHOP_SPRITE(work->field_EC4)->field_FC = primary[j];
            row = y[j];
            SHOP_SPRITE(work->field_EC4)->field_8 = row[0];
            ca = colorA[j];
            r = ca[0];
            SHOP_SPRITE(work->field_EC4)->field_79 = r;
            g = ca[1];
            SHOP_SPRITE(work->field_EC4)->field_7A = g;
            b = ca[2];
            SHOP_SPRITE(work->field_EC4)->field_7B = b;
            SHOP_SPRITE(work->field_EC8)->field_FC = primary[j];
            SHOP_SPRITE(work->field_EC8)->field_8 = row[1];
            SHOP_SPRITE(work->field_EC8)->field_79 = r;
            SHOP_SPRITE(work->field_EC8)->field_7A = g;
            SHOP_SPRITE(work->field_EC8)->field_7B = b;
            SHOP_SPRITE(work->field_E38)->field_FC = secondary[j];
            SHOP_SPRITE(work->field_E38)->field_8 = thirdY[j];
            cb = colorB[j];
            SHOP_SPRITE(work->field_E38)->field_79 = cb[0];
            SHOP_SPRITE(work->field_E38)->field_7A = cb[1];
            SHOP_SPRITE(work->field_E38)->field_7B = cb[2];
            break;
        case 1:
            SHOP_SPRITE(work->field_EB4)->field_FC = primary[j];
            row = y[j];
            SHOP_SPRITE(work->field_EB4)->field_8 = row[0];
            ca = colorA[j];
            r = ca[0];
            SHOP_SPRITE(work->field_EB4)->field_79 = r;
            g = ca[1];
            SHOP_SPRITE(work->field_EB4)->field_7A = g;
            b = ca[2];
            SHOP_SPRITE(work->field_EB4)->field_7B = b;
            SHOP_SPRITE(work->field_EB8)->field_FC = primary[j];
            SHOP_SPRITE(work->field_EB8)->field_8 = row[1];
            SHOP_SPRITE(work->field_EB8)->field_79 = r;
            SHOP_SPRITE(work->field_EB8)->field_7A = g;
            SHOP_SPRITE(work->field_EB8)->field_7B = b;
            SHOP_SPRITE(work->field_CC4)->field_FC = secondary[j];
            SHOP_SPRITE(work->field_CC4)->field_8 = thirdY[j];
            cb = colorB[j];
            SHOP_SPRITE(work->field_CC4)->field_79 = cb[0];
            SHOP_SPRITE(work->field_CC4)->field_7A = cb[1];
            SHOP_SPRITE(work->field_CC4)->field_7B = cb[2];
            break;
        case 2:
            SHOP_SPRITE(work->field_EBC)->field_FC = primary[j];
            row = y[j];
            SHOP_SPRITE(work->field_EBC)->field_8 = row[0];
            ca = colorA[j];
            r = ca[0];
            SHOP_SPRITE(work->field_EBC)->field_79 = r;
            g = ca[1];
            SHOP_SPRITE(work->field_EBC)->field_7A = g;
            b = ca[2];
            SHOP_SPRITE(work->field_EBC)->field_7B = b;
            SHOP_SPRITE(work->field_EC0)->field_FC = primary[j];
            SHOP_SPRITE(work->field_EC0)->field_8 = row[1];
            SHOP_SPRITE(work->field_EC0)->field_79 = r;
            SHOP_SPRITE(work->field_EC0)->field_7A = g;
            SHOP_SPRITE(work->field_EC0)->field_7B = b;
            SHOP_SPRITE(work->field_CC0)->field_FC = secondary[j];
            SHOP_SPRITE(work->field_CC0)->field_8 = thirdY[j];
            cb = colorB[j];
            SHOP_SPRITE(work->field_CC0)->field_79 = cb[0];
            SHOP_SPRITE(work->field_CC0)->field_7A = cb[1];
            SHOP_SPRITE(work->field_CC0)->field_7B = cb[2];
            break;
        }
    }
    return arg1;
}
