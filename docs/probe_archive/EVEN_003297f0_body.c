/* EVEN lane 2026-09-17 297f0 floor: 356 differing words (probe_variants) over 151 fnalign edits, retail 404 vs object 414 (+10, +2.48% PASS 3% rule). Shapes: s64 2970 slots with FclVec2 casts for 69f0 by-value, FclByte4 colours, heap ldr/ldl via *(FclVec2*)(p+0x38) (heap base emits ldr/ldl), D_006440B8[1] for high halves. Repro: python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003297f0 --candidate CAND=docs/probe_archive/EVEN_003297f0_body.c ; python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_003297f0 --candidate docs/probe_archive/EVEN_003297f0_body.c --quiet . Banked as guarded floor per 3% rule (whatever score). */
void func_003297f0(u8 *arg0, s64 arg1, s32 arg2, f32 fparg0, f32 fparg1) {
    FclByte4 cDC;
    FclByte4 cD8;
    s64 spD0;
    s64 spC8;
    s64 spC0;
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
    s64 t16;
    s64 t4;
    u8 *p;
    u8 *q;

    func_002b2970(&spD0, fparg0, D_006440B8[1]);
    t16 = (s64)((s64)arg2 << 0x38) >> 0x38;
    if (t16 == 0) {
        func_002b6c30(0x69, spD0, 0x56, 132.0f);
        func_002b2a60(&cDC, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x69);
        *(FclByte4 *)(p + 0x85) = cDC;
        func_002b2970(&spC0, *(f32 *)&spD0 + fparg1, D_006440B8[1]);
        func_002b2970(&spB8, *(f32 *)&spD0, D_006440B8[1]);
        func_002b69f0(0x69, *(FclVec2 *)&spC0, *(FclVec2 *)&spB8, 0, 8, 0);
    } else {
        p = func_002b6150(0x69);
        func_002b2970(&spB0, *(f32 *)&spD0 + fparg1, D_006440B8[1]);
        func_002b69f0(0x69, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&spB0, 0, 8, 0);
    }
    func_002b2970(&spC8, 17.0f + *(f32 *)&spD0, 9.0f + *((f32 *)&spD0 + 1));
    if (t16 == 0) {
        func_002b6c30(0x1AD, spC8, 0x41, 135.0f);
        func_002b2a60(&cD8, 0xE, 0x17, 0x49, 0xFF);
        q = func_002b6150(0x1AD);
        *(FclByte4 *)(q + 0x85) = cD8;
        *(u8 *)(func_002b6150(0x1AD) + 0x6E) = 0x80;
        func_002b2970(&spA8, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
        func_002b69f0(0x1AD, *(FclVec2 *)&spA8, *(FclVec2 *)&spC8, 0, 8, 0);
    } else {
        p = func_002b6150(0x1AD);
        func_002b2970(&spA0, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
        func_002b69f0(0x1AD, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&spA0, 0, 8, 0);
    }
    t4 = (s64)(arg1 << 0x38) >> 0x38;
    switch ((s8)t4) {
    case 0:
        func_002b2970(&spC8, 67.0f + *(f32 *)&spD0, 13.0f + *((f32 *)&spD0 + 1));
        if (t16 == 0) {
            func_002b6c30(0x109, spC8, 0x56, 134.0f);
            func_002b2970(&sp98, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x109, *(FclVec2 *)&sp98, *(FclVec2 *)&spC8, 0, 8, 0);
        } else {
            p = func_002b6150(0x109);
            func_002b2970(&sp90, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x109, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&sp90, 0, 8, 0);
        }
        func_002b2970(&spC8, 95.0f + *(f32 *)&spD0, 15.0f + *((f32 *)&spD0 + 1));
        if (t16 == 0) {
            func_002b6c30(0x10A, spC8, 0x56, 133.0f);
            func_002b2970(&sp88, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x10A, *(FclVec2 *)&sp88, *(FclVec2 *)&spC8, 0, 8, 0);
            return;
        }
        p = func_002b6150(0x10A);
        func_002b2970(&sp80, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
        func_002b69f0(0x10A, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&sp80, 0, 8, 0);
        return;
    case 1:
        func_002b2970(&spC8, 114.0f + *(f32 *)&spD0, 11.0f + *((f32 *)&spD0 + 1));
        if (t16 == 0) {
            func_002b6c30(0x11C, spC8, 0x56, 134.0f);
            func_002b2970(&sp78, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x11C, *(FclVec2 *)&sp78, *(FclVec2 *)&spC8, 0, 8, 0);
        } else {
            p = func_002b6150(0x11C);
            func_002b2970(&sp70, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x11C, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&sp70, 0, 8, 0);
        }
        func_002b2970(&spC8, 50.0f + *(f32 *)&spD0, 16.0f + *((f32 *)&spD0 + 1));
        if (t16 == 0) {
            func_002b6c30(0x11B, spC8, 0x56, 133.0f);
            func_002b2970(&sp68, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x11B, *(FclVec2 *)&sp68, *(FclVec2 *)&spC8, 0, 8, 0);
            return;
        }
        p = func_002b6150(0x11B);
        func_002b2970(&sp60, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
        func_002b69f0(0x11B, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&sp60, 0, 8, 0);
        return;
    default:
        break;
    }
}
