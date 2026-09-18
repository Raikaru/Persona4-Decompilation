/* EVEN lane 2026-09-17 2b000 floor: 395 differing words (probe_variants) over 77 fnalign edits, retail 475 vs object 471 (-4, -0.84% PASS 3% rule). Shapes: s64 2970 slots with FclVec2 casts for 69f0 by-value, FclByte4 colours, heap ldr/ldl via *(FclVec2*)(p+0x38), (f32)0x163 for 355.0f cvt.s.w, (s8) t16/t17, (s16) digit stores at +0x4. Repro: python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_0032b000 --candidate CAND=docs/probe_archive/EVEN_0032b000_body.c ; python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0032b000 --candidate docs/probe_archive/EVEN_0032b000_body.c --quiet . Banked as guarded floor per 3% rule. */
void func_0032b000(u8 *arg0, s32 arg1) {
    FclByte4 cDC;
    s64 spC0;
    s64 spC8;
    s64 spB8;
    s64 spB0;
    s64 spA8;
    s64 spA0;
    s64 sp98;
    s64 sp90;
    s64 sp88;
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;
    s64 sp60;
    s64 sp58;
    f32 f21;
    s32 t16;
    s32 t17;
    u8 *p;
    (void)arg0;
    func_002b2970(&spC0, 266.0f, (f32)0x163);
    t17 = (s8)func_00110140();
    t16 = (s8)arg1;
    if (t16 == 0) {
        func_002b6c30(0x2CF, spC0, 0x56, 215.0f);
        func_002b2a60(&cDC, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x2CF);
        *(FclByte4 *)(p + 0x85) = cDC;
        func_002b2970(&spB8, 380.0f + *(f32 *)&spC0, *((f32 *)&spC0 + 1));
        func_002b2970(&spB0, *(f32 *)&spC0, *((f32 *)&spC0 + 1));
        func_002b69f0(0x2CF, *(FclVec2 *)&spB8, *(FclVec2 *)&spB0, 1, 0xA, 0);
    } else {
        p = func_002b6150(0x2CF);
        func_002b2970(&spA8, 380.0f + *(f32 *)&spC0, *((f32 *)&spC0 + 1));
        func_002b69f0(0x2CF, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&spA8, 1, 0xA, 0);
    }
    func_002b2970(&spC8, 35.0f + *(f32 *)&spC0, 11.0f + *((f32 *)&spC0 + 1));
    if (t16 == 0) {
        func_002b6c30(0x119, spC8, 0x57, 212.0f);
        func_002b6a70(0x119, 0, 0xFF, 0, 0xA, 2);
        func_002b2970(&spA0, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x119, *(FclVec2 *)&spA0, *(FclVec2 *)&spC8, 1, 0xA, 2);
    } else {
        func_002b6a70(0x119, 0xFF, 0, 0, 0xA, 0);
        func_002b2970(&sp98, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x119, *(FclVec2 *)&spC8, *(FclVec2 *)&sp98, 1, 0xA, 2);
    }
    func_002b2970(&spC8, (f32)0x11D + *(f32 *)&spC0, 12.0f + *((f32 *)&spC0 + 1));
    if (t16 == 0) {
        func_002b6c30(0x11A, spC8, 0x57, 213.0f);
        func_002b6a70(0x11A, 0, 0xFF, 0, 0xA, 2);
        func_002b2970(&sp90, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x11A, *(FclVec2 *)&sp90, *(FclVec2 *)&spC8, 1, 0xA, 2);
    } else {
        func_002b6a70(0x11A, 0xFF, 0, 0, 0xA, 0);
        func_002b2970(&sp88, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x11A, *(FclVec2 *)&spC8, *(FclVec2 *)&sp88, 1, 0xA, 2);
    }
    f21 = *((f32 *)&spC0 + 1) - 3.0f;
    func_002b2970(&spC8, 247.0f + *(f32 *)&spC0, f21);
    if (t16 == 0) {
        func_002b6c30(0x2D0, spC8, 0x57, 211.0f);
        *(s16 *)(func_002b6150(0x2D0) + 0x4) = (s16)(((t17 % 10) + 0x10C));
        func_002b6a70(0x2D0, 0, 0xFF, 0, 0xA, 2);
        func_002b2970(&sp80, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x2D0, *(FclVec2 *)&sp80, *(FclVec2 *)&spC8, 1, 0xA, 2);
    } else {
        func_002b6a70(0x2D0, 0xFF, 0, 0, 0xA, 0);
        func_002b2970(&sp78, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x2D0, *(FclVec2 *)&spC8, *(FclVec2 *)&sp78, 1, 0xA, 2);
    }
    if (t17 >= 0xA) {
        func_002b2970(&spC8, 221.0f + *(f32 *)&spC0, f21);
        if (t16 == 0) {
            func_002b6c30(0x2D1, spC8, 0x57, 211.0f);
            *(s16 *)(func_002b6150(0x2D1) + 0x4) = (s16)(((t17 / 10 % 10) + 0x10C));
            func_002b6a70(0x2D1, 0, 0xFF, 0, 0xA, 2);
            func_002b2970(&sp70, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
            func_002b69f0(0x2D1, *(FclVec2 *)&sp70, *(FclVec2 *)&spC8, 1, 0xA, 2);
        } else {
            func_002b6a70(0x2D1, 0xFF, 0, 0, 0xA, 0);
            func_002b2970(&sp68, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
            func_002b69f0(0x2D1, *(FclVec2 *)&spC8, *(FclVec2 *)&sp68, 1, 0xA, 2);
        }
    }
    if (func_00110140() == 0x64) {
        func_002b2970(&spC8, 195.0f + *(f32 *)&spC0, f21);
        if (t16 == 0) {
            func_002b6c30(0x10D, spC8, 0x57, 211.0f);
            func_002b6a70(0x10D, 0, 0xFF, 0, 0xA, 2);
            func_002b2970(&sp60, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
            func_002b69f0(0x10D, *(FclVec2 *)&sp60, *(FclVec2 *)&spC8, 1, 0xA, 2);
            return;
        }
        func_002b6a70(0x10D, 0xFF, 0, 0, 0xA, 0);
        func_002b2970(&sp58, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x10D, *(FclVec2 *)&spC8, *(FclVec2 *)&sp58, 1, 0xA, 2);
    }
}
