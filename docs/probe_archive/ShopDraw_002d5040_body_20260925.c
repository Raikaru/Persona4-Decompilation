/* func_002d5040 (y_fclShopDraw.c) draft, measured 2026-09-25 with
 * probe_variants against the unit at commit 9a458bd (Vec2f-returning
 * func_002b2970, Vec2f/FclDrawColor func_002cacd0, u8 colour packer):
 * 95 reloc-masked differing words, object 1106 instructions = retail 1106.
 * EVERY remaining difference is one saved-register swap: retail keeps `work`
 * in $s1 and the short-lived values (the top item id, both label colours,
 * the eight stat values, the delta subtrahends) in $s0; this body has them
 * the other way round (69 swap-only blocks, nothing else).
 * Rename shopDrawLabelX -> shopDrawLabel when the helper is defined earlier
 * in the unit (it is defined with func_002de5a0, after this function).
 * Shape that closed everything else (guarded body was 1111 after the unit
 * refactor): switch on work[7] written 0,1,2; func_002b2970 / colour calls as
 * arguments; label as the inlined size-first helper; stat numbers as an
 * inlined (value, x, y) helper so the x base (e04e0 read, $f20) is evaluated
 * before the value; value = get((s32)id) & 0xFFFF (the (s32) gives retail's
 * dsll32/dsra32 before func_001068b0 for both e2740 and 106cd0 ids); deltas
 * as an inlined (item, cur) helper so cur is evaluated first; dB declared
 * before dA; `dB = dA = 0` in case 2 (retail's ext of $zero).
 * Tried without moving the swap: declaration order (all 6), register work,
 * explicit id local, named x/value locals (133), stat value as an inline
 * local, value assigned inside the argument, propagation off (911),
 * common_subs off (133), int-typed work (944).  A skeleton micro-test
 * (two s16 locals + switch + inline helpers) reproduces work-in-$s0, so the
 * lever is structural, not a spelling of this body.
 */
static inline void shopDrawLabelX(f32 size, const char *text, Vec2f pos, s32 color)
{
    func_00275680(pos.x, pos.y, size, color, 0, 1, text, 0, 0, D_00795E30, -1);
}

static inline u32 shopStatValue(u16 (*get)(s16), s32 id)
{
    return get(id) & 0xFFFF;
}

static inline s16 shopStatDelta(u32 item, u32 cur)
{
    return item - cur;
}

static inline void shopDrawStat(u32 value, f32 x, f32 y)
{
    func_002cacd0(func_002b2970(x + (f32)((s16)(func_002b3170(value) - 1) * 8), y), 22.0f, func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF), 0xF, 0, value, 0x1E, 0x7B, (s32)func_0046a770(D_0063FB50), (s32)func_0046a770(D_0063FB50), 0xA9);
}

void func_002d5040(void *arg0) {
    extern s16 func_002e2740(s32 arg0);
    s16 dB;
    s16 dA;
    u8 *work;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    func_002e0b20(func_002d4f30((s16)func_00106880(func_002e2740(*(s16 *)(work + 2)))) & 0xFFFF, func_002b2970(37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x30)), 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    shopDrawLabelX(31.0f, (const char *)func_001067f0(func_002e2740(*(s16 *)(work + 2))), func_002b2970(79.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 34.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x30)), func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF));
    shopDrawLabelX(31.0f, (const char *)func_001067f0(func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), *(s8 *)(work + 7))), func_002b2970(79.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 34.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30)), func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF));
    switch (*(s8 *)(work + 7)) {
    case 0:
        shopDrawStat((func_001068b0((s32)func_002e2740(*(s16 *)(work + 2))) & 0xFFFF), 51.0f + (296.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C)), (f32)0x107);
        shopDrawStat((func_001068e0((s32)func_002e2740(*(s16 *)(work + 2))) & 0xFFFF), 87.0f + (51.0f + (296.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C))), (f32)0x107);
        func_002e0b20(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), func_002b2970(37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30)), 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        shopDrawStat((func_001068b0((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0)) & 0xFFFF), 51.0f + (296.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C)), 149.0f);
        shopDrawStat((func_001068e0((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0)) & 0xFFFF), 87.0f + (51.0f + (296.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C))), 149.0f);
        dB = shopStatDelta((func_001068b0((s32)func_002e2740(*(s16 *)(work + 2))) & 0xFFFF), func_001068b0(func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0)) & 0xFFFF);
        dA = shopStatDelta((func_001068e0((s32)func_002e2740(*(s16 *)(work + 2))) & 0xFFFF), func_001068e0(func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0)) & 0xFFFF);
        break;
    case 1:
        shopDrawStat((func_00106940((s32)func_002e2740(*(s16 *)(work + 2))) & 0xFFFF), 51.0f + (296.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C)), (f32)0x107);
        shopDrawStat((func_00106970((s32)func_002e2740(*(s16 *)(work + 2))) & 0xFFFF), 87.0f + (51.0f + (296.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C))), (f32)0x107);
        func_002e0b20(0x1B, func_002b2970(37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30)), 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        shopDrawStat((func_00106940((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1)) & 0xFFFF), 51.0f + (296.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C)), 149.0f);
        shopDrawStat((func_00106970((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1)) & 0xFFFF), 87.0f + (51.0f + (296.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C))), 149.0f);
        dB = shopStatDelta((func_00106940((s32)func_002e2740(*(s16 *)(work + 2))) & 0xFFFF), func_00106940(func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1)) & 0xFFFF);
        dA = shopStatDelta((func_00106970((s32)func_002e2740(*(s16 *)(work + 2))) & 0xFFFF), func_00106970(func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1)) & 0xFFFF);
        break;
    case 2:
        func_002e0b20(0x1C, func_002b2970(37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30)), 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        dB = dA = 0;
        break;
    }
    if (dB > 0) {
        func_002e0b20(0x28, func_002b2970(360.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 245.0f), 23.0f, func_002b2a30(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
    } else if (dB < 0) {
        func_002e0b20(0x29, func_002b2970(360.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 245.0f), 23.0f, func_002b2a30(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
    if (dA > 0) {
        func_002e0b20(0x28, func_002b2970(87.0f + (360.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C)), 245.0f), 23.0f, func_002b2a30(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
    } else if (dA < 0) {
        func_002e0b20(0x29, func_002b2970(87.0f + (360.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C)), 245.0f), 23.0f, func_002b2a30(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
}
