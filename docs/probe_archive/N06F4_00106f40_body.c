/* object 356 bytes, retail window 368 bytes, normalized_diff 7; differing offsets 37,42,46,74,122,154,198. Best body retained after focused extent probes. Probed: m2c prelude expansion/removal; all local declaration orders and assignment orders; comma/separate initialization; local widths/signedness; pointer/result/field types; helper prototypes and call casts; loop/guard/goto shapes; optimization pragmas; volatile/qualifiers; local aliases and lifetimes; argument aliases/order; commutative arithmetic; parameter-vs-copy and live-range/recomputation probes; third-live-local pressure; corrected func_001077f0(s32) declaration (nd 10, restored empty declaration); declaration-reversed source (nd 10); id-first source (nd 6 but andi moved before jal); post-call mask recomputation and short-lived mask locals (nd 10); direct preassignment/raw aliases (nd 69/10). Retail saves s3,s2,s1,s0; e/id are exactly the two swapped values in s0/s1, with no unaccounted third live value. Residual remains saved-register swap: retail e=$s0/id=$s1, MWCC e=$s1/id=$s0. */
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
