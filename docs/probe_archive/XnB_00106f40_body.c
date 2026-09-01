/* object 356 bytes, retail window 368 bytes, normalized_diff 11; COUNT/assignment-rule probe. Retail saves four GPR values: s3=arg0, s2=j, s1=arg0&0xffff, s0=func_001070e0(arg0). Candidate count also is four. With declaration order j,e(id mask),id(result), call-first mask-after, and j initialized only after func_001070e0 and the two guard calls, MWCC assigns result to s1 and mask to s0. Moving j=0 before func_001070e0 fixes the e/id mapping in isolation, but emits the initialization at offset 0x1C (retail initializes j at 0x64). This is the measured late-live-local assignment floor; no global re-derivation or count reduction applies. */
void func_00106f40(s32 arg0) {
    s32 j;
    s32 e;
    s32 id;
    s32 lvl;
    id = func_001070e0(arg0);
    e = arg0 & 0xFFFF;
    if (e <= 0) {
        func_0046d730(D_005E42C8, 0x48);
    }
    if (e <= 0) {
        func_0046d730(D_005E42C8, 0x27);
    }
    j = 0;
    while (j < 0xD) {
        func_00106390(e + ((j << 5) + 0x3FF), 0);
        j++;
    }
    if (id == 0) {
        return;
    }
    if (func_001077f0(arg0) != 0) {
        func_00106db0(arg0, 0);
        lvl = *(u16 *)(id + 6);
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
