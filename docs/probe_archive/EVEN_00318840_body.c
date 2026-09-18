/* EVEN lane 2026-09-17 18840 floor: 394 differing words (probe_variants) over 194 fnalign edits, retail 444 vs object 457 (+13, +2.93% PASS 3% rule). Shapes: FclVec2/FclByte4 idioms, if-chain for 6/7/8 (not switch), s32 t16/t17/v18 with (s8)/(s16) casts and reuse (no recompute), word stores for 0x8 (sw not sb), FPU-fusion (5.0f+sp108)-2.0f*(hval/10.0f), iGpffff8360 for A0/AC. FP-saved-reg rotation floor persists (extra swc1). Repro: python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00318840 --candidate CAND=docs/probe_archive/EVEN_00318840_body.c ; python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00318840 --candidate docs/probe_archive/EVEN_00318840_body.c --quiet . Banked as guarded floor per 3% rule. */
void func_00318840(u8 *arg0, s64 arg1, s64 arg2, s32 arg3, s64 arg4) {
    FclByte4 c11C;
    FclByte4 c118;
    FclByte4 c114;
    FclByte4 c110;
    f32 sp10C;
    f32 sp108;
    s64 sp100;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    s64 spD8;
    s64 spD0;
    s64 spC8;
    s64 spC0;
    s64 spB8;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f24;
    s32 t16;
    s32 t17;
    s32 v18;
    u8 *t;
    u8 *p;
    u8 *h;
    f32 hval;
    f32 fmsub;

    t = *(u8 **)(arg0 + 0x38);
    t17 = (s8)arg2;
    t16 = t17 + 0x20D;
    p = func_002b6150((s16)t16);
    sp108 = *(f32 *)(p + 0x38);
    sp10C = *(f32 *)(p + 0x3C);
    v18 = (s16)(t17 * 2 + 0xDF);
    if ((s8)t17 == 6) {
        v18 = 0xEF;
    } else if ((s8)t17 == 7) {
        v18 = 0xEB;
    } else if ((s8)t17 == 8) {
        v18 = 0xED;
    }
    if (((s64)(arg1 << 0x38) >> 0x38) == *(s8 *)(t + 0xB4)) {
        p = func_002b6150(0x1DC);
        *(FclVec2 *)(p + 0x38) = (FclVec2){sp108, sp10C};
        f22 = 62.0f + sp10C;
        f21 = 6.0f + sp108;
        func_002b2970(&sp100, f21, f22);
        p = func_002b6150(0x216);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&sp100;
        f20 = 33.0f + sp108;
        func_002b2970(&spF8, f20, f22);
        p = func_002b6150(0x217);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spF8;
        f24 = 20.0f + sp108;
        func_002b2970(&spF0, f24, f22);
        p = func_002b6150(0x218);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spF0;
        f22 = sp10C - 44.0f;
        func_002b2970(&spE8, f21, f22);
        p = func_002b6150(0x219);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spE8;
        func_002b2970(&spE0, f20, f22);
        p = func_002b6150(0x21A);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spE0;
        func_002b2970(&spD8, f24, f22);
        p = func_002b6150(0x21B);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spD8;
        f20 = iGpffff8360;
        *(f32 *)(func_002b6150((s16)v18) + 0xA0) = f20;
        *(f32 *)(func_002b6150((s16)v18) + 0xAC) = f20;
        *(f32 *)(func_002b6150((s16)v18) + 0x14) = 59.0f;
        *(s32 *)(func_002b6150((s16)v18) + 0x8) = 0xAB;
        h = func_0046d200(func_00331560(), (u32)v18);
        hval = func_0046b260(h);
        fmsub = (5.0f + sp108) - 2.0f * (hval / 10.0f);
        func_002b2970(&spD0, fmsub, sp10C - 3.0f);
        p = func_002b6150((s16)v18);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spD0;
        func_0046d280(h);
        func_002b2a60(&c11C, 0xE0, 0xFF, 0x33, 0xFF);
        *(FclByte4 *)(func_002b6150((s16)v18) + 0x85) = c11C;
        /* reuse t17 */
        func_002b68d0((s16)t16, 0, 1);
        func_002b68d0((s16)(t17 + 0xF2), 0, 1);
        func_002b2970(&spC8, sp108 - 12.0f, 104.0f + sp10C);
        func_002b6c30((s16)(t17 + 0xFD), spC8, 0xAC, 59.0f);
        if (t17 < 6) {
            func_002b2970(&spC0, sp108 - 12.0f, 123.0f + sp10C);
            func_002b6c30(0xFC, spC0, 0xAC, 59.0f);
            func_002b2a60(&c118, 0xE0, 0xFF, 0x33, 0xFF);
            *(FclByte4 *)(func_002b6150(0xFC) + 0x85) = c118;
            return;
        }
        func_002b68d0(0xFC, 0, 1);
        return;
    }
    /* reuse t17 */
    func_002b68d0((s16)(t17 + 0xFD), 0, 1);
    func_002b68d0((s16)t16, 0, 0);
    t16 = t17 + 0xF2;
    func_002b68d0((s16)t16, 0, 0);
    func_002b2a60(&c114, 0x42, 0x6E, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150((s16)t16) + 0x85) = c114;
    *(f32 *)(func_002b6150((s16)v18) + 0xA0) = 1.0f;
    *(f32 *)(func_002b6150((s16)v18) + 0xAC) = 1.0f;
    *(f32 *)(func_002b6150((s16)v18) + 0x14) = (f32)arg3;
    *(s32 *)(func_002b6150((s16)v18) + 0x8) = (s32)arg4 + 1;
    func_002b2970(&spB8, 6.0f + sp108, 4.0f + sp10C);
    p = func_002b6150((s16)v18);
    *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spB8;
    func_002b2a60(&c110, 0x42, 0x6E, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150((s16)v18) + 0x85) = c110;
}
