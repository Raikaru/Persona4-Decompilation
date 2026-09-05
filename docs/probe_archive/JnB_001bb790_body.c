// Lane JnB residual archive: func_001bb790.
// Candidate object: 296 bytes; retail window: 304 bytes.
// normalized_diff: 23 reloc-masked words reported by fndiff; 59 differing bytes in the object comparison.
// differing instruction offsets (retail-relative): 0x7c, 0x80, 0x84, 0x88, 0x8c, 0x90, 0x94, 0x98, 0x9c, 0xa0, 0xa4, 0xa8, 0xac, 0xb0, 0xb4, 0xb8, 0xbc, 0xc0, 0xc4, 0xc8, 0x114.
// COP1 chain reproduced from plain C: madd.s emitted naturally, but the adda.s accumulator operands were f0,f1 rather than retail f1,f0; this is an ordinary register-colouring residual, not a COP1 expressiveness floor.
// Ruled out: scalar global declarations (aggregate RwV3d copy was required for exact global load/store scheduling); loop integer-width permutations; while/for forms; pointer/struct aliases; declaration-order permutations; allowed pragma modes (opt_propagation, opt_common_subs, opt_loop_invariants, schedule, no_branch_likely, opt_rebuildconditionals, optimization_level, tailcall); accumulator parenthesization and literal/named-zero variants.
// IDA replay: docs/ida_headstart/src/Battle/btlMain.c:898-936.
// The output-object weighted-accumulation helper ties this floor: 21 instruction
// differences plus two absent zero-tail words. Direct/local helpers measured
// 24 words; unit-weight and by-value alternatives were worse. Production is ASM.
extern RwV3d D_00881430;
void func_001bb790(u8 *arg0, f32 *arg1, f32 fparg0)
{
    f32 weights[4];
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 temp_f5;
    u16 i;
    s32 index;
    u8 *p;

    f3 = 1.0f - fparg0;
    f1 = f3 * f3;
    weights[0] = f3 * f1;
    f0 = fparg0 * f1;
    f2 = 3.0f;
    weights[1] = f2 * f0;
    f1 = fparg0 * fparg0;
    f0 = f3 * f1;
    weights[2] = f2 * f0;
    weights[3] = fparg0 * f1;
    index = *(u16 *)(arg0 + 0x74);
    *(RwV3d *)arg1 = D_00881430;
    i = 0;
    while (i < 4) {
        temp_f5 = weights[i];
        p = (u8 *)((u16)index * 0x1C) + (u32)arg0;
        f4 = *(f32 *)(p + 8) * temp_f5;
        f3 = *(f32 *)(p + 0xC) * temp_f5;
        arg1[0] = (arg1[0] + 0.0f) + *(f32 *)(p + 4) * temp_f5;
        arg1[1] += f4;
        arg1[2] += f3;
        index = (u16)(index + 1);
        if (index >= 4) {
            index = 0;
        }
        i++;
    }
}
