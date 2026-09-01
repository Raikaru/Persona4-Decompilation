/* re-measured 2026-08-14 12:26:59: object 356 bytes, retail window 368 bytes, normalized_diff 7; differing first-diff byte offsets 37,42,46,74,122,154,198. Residual is saved-register rotation: retail keeps func_001070e0's result in $s0 and arg0&0xFFFF in $s1, while MWCC b210 assigns the opposite colors. Re-probed reversed local declaration order and split e/id assignments (both unchanged nd 7); prior archive probes ruled out callee declarations, statement order, types, pragmas, qualifiers, aliases, lifetimes, argument staging and arithmetic rewrites. */
void func_00106f40(s32 arg0) {
    s32 e;
    s32 id;
    s32 j;
    s32 lvl;
    id = (e = func_001070e0(arg0), arg0 & 0xFFFF);
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
