/* MWCCPS2 b210: object 356B / window 368B / differing words 6.
 * With explicit helper prototypes, the old call-first body scores 10 words,
 * not its historical byte-valued normalized_diff 7. Mask-first preserves
 * the retail saved registers but moves the pure andi before the lookup:
 * three reported instruction differences and three absent zero tail words.
 * The displaced jal is relocation-masked; this is not an exact match.
 * Previous declaration/assignment orders, scalar widths, pointer/result
 * types, CFG shapes, optimizer controls, aliases, recomputation and live-range
 * variants did not close the floor. Typed aggregate field-order variants,
 * inline output-parameter lifetimes, opt_lifetimes and propagation controls
 * likewise did not improve the mask-first six-word result.
 * Production remains ASM. Keep real call arguments and complete prototypes.
 */
extern s32 func_001070e0(s32);
extern s32 func_001077f0(s32);
extern s32 func_00107c80(s32);
extern s32 func_00107ea0(s32);
void func_00106f40(s32 arg0) {
    s32 e;
    s32 id;
    s32 j;
    s32 lvl;
    id = arg0 & 0xFFFF;
    e = func_001070e0(arg0);
    if (id <= 0) {
        func_0046d730(D_005E42C8, 0x48);
    }
    if (id <= 0) {
        func_0046d730(D_005E42C8, 0x27);
    }
    j = 0;
    while (j < 0xD) {
        func_00106390(id + ((j << 5) + 0x3FF), 0);
        j++;
    }
    if (e == 0) {
        return;
    }
    if (func_001077f0(arg0) != 0) {
        func_00106db0(arg0, 0);
        lvl = *(u16 *)(e + 6);
        if (lvl == 0xA) {
            func_00106db0(arg0, 1);
        } else {
            func_00106db0(arg0, lvl + 3);
        }
    }
    if (func_00107c80(arg0) != 0) {
        func_00106db0(arg0, 2);
    }
    if (func_00107ea0(arg0) != 0) {
        func_00106db0(arg0, 3);
    }
}
