/* REVERTED floor draft (nd 521, obj 2180B vs 1168B window, ~2x overrun).
   Structure triple-verified (m2c + IDA + Ghidra + retail): switch, lbu-built
   color word, sign-vs-zero mask arbitration (dsll32/dsrl32 = zero-extend,
   IDA right), VU blend as scalar lanes, s32 1/0 return with short-inc.
   Verdict: scalar C cannot approach SIMD-dense VU blends in size parity;
   plain-C floor overruns ~2x. Revisit only with lane-count reduction.
   u32 (void*) sig per btlUnit_functions.c:93; iGpffff81f4 pre-registered. */
// FUN_0019B730
u32 func_0019b730(void *arg0)
{
    extern f32 iGpffff81f4;
    u8 *a;
    u8 *v8;
    s16 v9;
    u8 v10;
    s16 v1;
    s16 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    u32 v11;
    u32 w;
    f32 f;
    f32 c0;
    f32 c1;
    f32 c2;
    f32 c3;
    f32 d0;
    f32 d1;
    f32 d2;
    f32 d3;
    f32 e0;
    f32 e1;
    f32 e2;
    f32 e3;
    u32 pack;
    u32 wA;

    a = (u8 *)arg0;
    v8 = *(u8 **)a;
    v9 = *(s16 *)(a + 0x12);
    v10 = *(a + 0x10);
    v1 = 0;
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    switch (v10) {
    case 4:
    case 3:
        v2 = *(s16 *)(a + 0xC);
        v3 = 0;
        v1 = *(s16 *)(a + 0xE);
        v4 = 0;
        if (v1 >= v2) {
            v5 = v1;
        } else {
            v5 = v2;
        }
        break;
    case 2:
        v1 = *(s16 *)(a + 0xE);
        v4 = 0;
        v2 = *(s16 *)(a + 0xC);
        v3 = v1 + 1;
        v5 = v1 + v2;
        break;
    case 1:
        v2 = *(s16 *)(a + 0xC);
        v3 = 0;
        v1 = *(s16 *)(a + 0xE);
        v4 = v2 + 1;
        v5 = v1 + v2;
        break;
    default:
        break;
    }
    if (v9 == 0) {
        w = (u32)*(v8 + 0x33) << 24;
        w |= (u32)*(v8 + 0x32) << 16;
        w |= (u32)*(v8 + 0x31) << 8;
        w |= *(v8 + 0x30);
        *(u32 *)(a + 4) = w;
        if (*(a + 0x11) & 1) {
            *(u32 *)(a + 4) = *(u32 *)(a + 4) & 0xFFFFFF;
        }
        if (*(a + 0x11) & 2) {
            *(u32 *)(a + 4) = (*(u32 *)(a + 4) & 0xFFFFFF) | 0xFF000000;
        }
        if (*(a + 0x11) & 4) {
            *(u32 *)(a + 4) = 0;
        }
        if (*(a + 0x11) & 8) {
            *(u32 *)(a + 4) = 0xFFFFFFFF;
        }
        func_0019d040(v8);
    }
    v11 = *(u32 *)(a + 4);
    if (v9 >= v4) {
        if (v1 <= 0 || v9 >= v4 + v1) {
            f = 1.0f;
        } else {
            f = (f32)(v9 - v4) / (f32)v1;
        }
        wA = *(u32 *)(a + 8);
        c0 = (f32)(u8)(wA >> 0) * iGpffff81f4;
        c1 = (f32)(u8)(wA >> 8) * iGpffff81f4;
        c2 = (f32)(u8)(wA >> 16) * iGpffff81f4;
        c3 = (f32)(u8)(wA >> 24) * iGpffff81f4;
        d0 = (f32)(u8)(v11 >> 0) * iGpffff81f4;
        d1 = (f32)(u8)(v11 >> 8) * iGpffff81f4;
        d2 = (f32)(u8)(v11 >> 16) * iGpffff81f4;
        d3 = (f32)(u8)(v11 >> 24) * iGpffff81f4;
        e0 = d0 * (1.0f - f) + c0 * f;
        e1 = d1 * (1.0f - f) + c1 * f;
        e2 = d2 * (1.0f - f) + c2 * f;
        e3 = d3 * (1.0f - f) + c3 * f;
        pack = (u8)(s32)(e0 * 255.0f);
        pack |= (u32)(u8)(s32)(e1 * 255.0f) << 8;
        pack |= (u32)(u8)(s32)(e2 * 255.0f) << 16;
        pack |= (u32)(u8)(s32)(e3 * 255.0f) << 24;
        v11 = (v11 & 0xFF000000) | (pack & 0xFFFFFF);
    }
    if (v9 >= v3) {
        if (v2 <= 0 || v9 >= v3 + v2) {
            f = 1.0f;
        } else {
            f = (f32)(v9 - v3) / (f32)v2;
        }
        wA = *(u32 *)(a + 8);
        c0 = (f32)(u8)(wA >> 0) * iGpffff81f4;
        c1 = (f32)(u8)(wA >> 8) * iGpffff81f4;
        c2 = (f32)(u8)(wA >> 16) * iGpffff81f4;
        c3 = (f32)(u8)(wA >> 24) * iGpffff81f4;
        d0 = (f32)(u8)(v11 >> 0) * iGpffff81f4;
        d1 = (f32)(u8)(v11 >> 8) * iGpffff81f4;
        d2 = (f32)(u8)(v11 >> 16) * iGpffff81f4;
        d3 = (f32)(u8)(v11 >> 24) * iGpffff81f4;
        e0 = d0 * (1.0f - f) + c0 * f;
        e1 = d1 * (1.0f - f) + c1 * f;
        e2 = d2 * (1.0f - f) + c2 * f;
        e3 = d3 * (1.0f - f) + c3 * f;
        pack = (u8)(s32)(e0 * 255.0f);
        pack |= (u32)(u8)(s32)(e1 * 255.0f) << 8;
        pack |= (u32)(u8)(s32)(e2 * 255.0f) << 16;
        pack |= (u32)(u8)(s32)(e3 * 255.0f) << 24;
        v11 = (v11 & 0xFFFFFF) | (pack & 0xFF000000);
    }
    *(v8 + 0x30) = (u8)v11;
    *(v8 + 0x31) = (u8)(v11 >> 8);
    *(v8 + 0x32) = (u8)(v11 >> 16);
    *(v8 + 0x33) = (u8)(v11 >> 24);
    *(u32 *)(v8 + 0x98) = *(u32 *)(v8 + 0x98) | 4;
    if (v5 < v9) {
        return 1;
    }
    *(s16 *)(a + 0x12) = v9 + 1;
    return 0;
}
