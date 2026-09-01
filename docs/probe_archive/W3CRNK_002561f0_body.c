/* object 608B, window 624B, normalized_diff 146 (fndiff); abandoned pair/index probe */
void func_002561f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s64 arg5, s64 arg6, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    typedef struct { u8 r; u8 g; u8 b; u8 a; } RGBA;
    typedef union { struct { f32 x; f32 y; } f; struct { u32 w0; u32 w1; } w; s64 align; } Pair;
    typedef struct { RGBA rgba[16]; u8 scratch[16]; Pair pairs[16]; } Work;
    Work work;
    Pair *pairp; u8 *p; u8 *base; s32 i; s32 count; u32 w0; u32 w1; Pair *src; Pair *dst;
    s32 packed; s32 packed2; s32 packed3; s32 packed4; f32 value2; f32 value3;
    s32 b0; s32 b1; s32 b2; s32 b3; s32 c0; s32 c1; s32 c2; s32 c3;
    s32 d0; s32 d1; s32 d2; s32 d3; s32 e0; s32 e1; s32 e2; s32 e3; s32 one;
    src = (Pair *)D_00636310; dst = work.pairs; count = 16; do { w0 = src->w.w0; w1 = src->w.w1; src++; count--; dst->w.w0 = w0; dst->w.w1 = w1; dst++; } while (count > 0);
    i = 0; packed = arg0 << 8; b0 = (packed >> 24) & 0xFF; b1 = (packed >> 16) & 0xFF; b2 = arg0 & 0xFF; b3 = packed & 0xFF;
    value2 = ((f32)arg2 * 255.0f) / 255.0f; value3 = ((f32)arg3 * 255.0f) / 255.0f; packed2 = packed | arg1; c0 = (packed2 >> 24) & 0xFF; c1 = (packed2 >> 16) & 0xFF; c2 = (packed2 >> 8) & 0xFF; c3 = packed2 & 0xFF; packed4 = packed | (s32)value2; e0 = (packed4 >> 24) & 0xFF; e1 = (packed4 >> 16) & 0xFF; e2 = (packed4 >> 8) & 0xFF; e3 = packed4 & 0xFF; packed3 = packed | (s32)value3; d0 = (packed3 >> 24) & 0xFF; d1 = (packed3 >> 16) & 0xFF; d2 = (packed3 >> 8) & 0xFF; d3 = packed3 & 0xFF; one = 1;
    while (i < 16) {
      work.pairs[i].f.x += fparg0; work.pairs[i].f.y += fparg1;
      if (i == 0 || i == one || (u32)(i - 0xE) < 2U) { work.rgba[i].r = b0; work.rgba[i].g = b1; work.rgba[i].b = b2; work.rgba[i].a = b3; }
      else if ((u32)(i - 6) < 4U) { work.rgba[i].r = e0; work.rgba[i].g = e1; work.rgba[i].b = e2; work.rgba[i].a = e3; }
      else if ((u32)(i - 0xA) < 4U) { work.rgba[i].r = d0; work.rgba[i].g = d1; work.rgba[i].b = d2; work.rgba[i].a = d3; }
      else { work.rgba[i].r = c0; work.rgba[i].g = c1; work.rgba[i].b = c2; work.rgba[i].a = c3; }
      i++;
    }
    base = (u8 *)work.rgba;
    func_0045e6a0(base, work.pairs, fparg2, 0x10, 4, (s32)(s16)arg5, (s32)(s16)arg6, b1, 0, fparg3, fparg4);
}
