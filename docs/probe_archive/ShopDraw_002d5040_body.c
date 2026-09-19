/* Faithful floor for func_002d5040 (y_fclShopDraw.c, retail 0x002D5040, window 1105 instrs/4432B).
 * Banked 2026-09-19: probe_variants 907 reloc-masked differing words (was 924);
 * fnalign retail 1105 vs object 1074 instrs (-31, -2.8% PASS, 436 edits +44 reloc-only);
 * opclass dsll/dsra 13 (was 37), mtc1 -37/lui -35/and+17/andi-13/mov.s+22 walls stand.
 * Requires file-scope `void *func_0046a770(void *)` (was s64; def returns u8*) and
 * `s32 func_002b3170(s32)` (was s16; def returns s32) plus `#pragma opt_propagation off`.
 * Shape: dual 04e0 calls per two-load 2970 (6 sites, 20->26 occ, fixes jal/lw -4);
 * Vec2f cB8/cB0 via field assigns (lwc1/swc1, not ld/sd); s32 cA/cB/c16/nA/tmp/t0/t1/h0/dA/dB
 * with (s16) on s16 returns (2740/06cd0/6880) kept, (s16) on u16 68b0/e0/6940/6970 kept
 * (wide hurts: 930/936), c16 stores kept (inline hurts: 925 FAIL). Residual: floats
 * hoisted to f21-f27 vs rematerialised per arm; mask FFFF hoisted to s3 (ori+and)
 * under propOff via cB/tmp reuse vs per-use andi; 360+87/245/23 tail pair matches.
 * See owner note at y_fclShopDraw.c FUN_002D5040 NONMATCHING. Production stays INCLUDE_ASM.
 */
void func_002d5040(void *arg0) {
    extern s16 func_002e2740(s32 arg0);
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    RGBA sp12C;
    RGBA sp128;
    RGBA sp124;
    RGBA sp120;
    RGBA sp11C;
    RGBA sp118;
    RGBA sp114;
    RGBA sp110;
    Vec2f cB8;
    Vec2f cB0;
    u8 *work;
    s32 tmp;
    s32 t0;
    s32 t1;
    s32 c16;
    s32 cA;
    s32 cB;
    s32 nA;
    s32 h0;
    s32 dA;
    s32 dB;
    u8 *pCE4;
    u8 *pEDC;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    cA = (s16)func_002e2740(*(s16 *)(work + 2));
    cB = (s16)func_00106880((s16)cA);
    tmp = func_002d4f30((s16)cB) & 0xFFFF;
    func_002b2970(&sp108, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x30));
    pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
    func_002e0b20(tmp, sp108, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    t0 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&sp100, 79.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 34.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x30));
    cB8.x = sp100.x; cB8.y = sp100.y;
    cA = (s16)func_002e2740(*(s16 *)(work + 2));
    func_00275680(cB8.x, cB8.y, 31.0f, t0, 0, 1, (const char *)func_001067f0(cA), 0, 0, D_00795E30, -1);
    t1 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&spF8, 79.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 34.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
    cB0.x = spF8.x; cB0.y = spF8.y;
    c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), *(s8 *)(work + 7));
    func_00275680(cB0.x, cB0.y, 31.0f, t1, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    if (*(s8 *)(work + 7) == 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068b0((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&spA8, 51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C)) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp12C, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(spA8, 22.0f, sp12C, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068e0((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&spA0, 87.0f + (51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C))) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp128, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(spA0, 22.0f, sp128, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        func_002b2970(&spF0, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        func_002e0b20(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), spF0, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        cB = (s16)func_001068b0(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp98, 51.0f + (296.0f + *(f32 *)(pEDC + 0x2C)) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp124, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp98, 22.0f, sp124, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        cB = (s16)func_001068e0(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp90, 87.0f + (51.0f + (296.0f + *(f32 *)(pEDC + 0x2C))) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp120, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp90, 22.0f, sp120, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        tmp = func_001068b0(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068b0((s16)cA);
        dB = (s16)((cB & 0xFFFF) - tmp);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        tmp = func_001068e0(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068e0((s16)cA);
        dA = (s16)((cB & 0xFFFF) - tmp);
    } else if (*(s8 *)(work + 7) == 1) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106940((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp88, 51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C)) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp11C, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp88, 22.0f, sp11C, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106970((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp80, 87.0f + (51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C))) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp118, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp80, 22.0f, sp118, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        func_002b2970(&spE8, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
        func_002e0b20(0x1B, spE8, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        cB = (s16)func_00106940(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp78, 51.0f + (296.0f + *(f32 *)(pEDC + 0x2C)) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp114, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp78, 22.0f, sp114, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        cB = (s16)func_00106970(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp70, 87.0f + (51.0f + (296.0f + *(f32 *)(pEDC + 0x2C))) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp110, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp70, 22.0f, sp110, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        tmp = func_00106940(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106940((s16)cA);
        dB = (s16)((cB & 0xFFFF) - tmp);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        tmp = func_00106970(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106970((s16)cA);
        dA = (s16)((cB & 0xFFFF) - tmp);
    } else if (*(s8 *)(work + 7) == 2) {
        func_002b2970(&spE0, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
        func_002e0b20(0x1C, spE0, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        dA = 0;
        dB = 0;
    } else {
        dA = 0;
        dB = 0;
    }
    if (dB > 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spD8, 360.0f + *(f32 *)(pCE4 + 0x2C), 245.0f);
        func_002e0b20(0x28, spD8, 23.0f, func_002b2a30(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
    } else if (dB < 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spD0, 360.0f + *(f32 *)(pCE4 + 0x2C), 245.0f);
        func_002e0b20(0x29, spD0, 23.0f, func_002b2a30(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
    if (dA > 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spC8, 87.0f + (360.0f + *(f32 *)(pCE4 + 0x2C)), 245.0f);
        func_002e0b20(0x28, spC8, 23.0f, func_002b2a30(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
        return;
    }
    if (dA < 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spC0, 87.0f + (360.0f + *(f32 *)(pCE4 + 0x2C)), 245.0f);
        func_002e0b20(0x29, spC0, 23.0f, func_002b2a30(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
}
