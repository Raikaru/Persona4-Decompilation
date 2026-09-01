/* Re-measured 2026-08-14 12:30 UTC: object 432B, retail window 432B,
   normalized_diff 19, fndiff differing words 44,48,92,96,124,176,180,184,
   228,236,268,272. The exact-size residual has one common factor: MWCC
   assigns the two long-lived locals opposite to retail (candidate first
   position value in $f20 versus retail $f21, and the derived value in $f21
   versus retail $f20), plus the prologue's move $s4 before sd $a1. Archived
   callee-declaration, union, pointer-staging, parameter-width, and
   commutative-order probes remain ruled out; fresh float/local declaration
   reorder, WV16 color-local, O1, opt_propagation, and schedule probes did
   not improve it (schedule off regressed 13 sibling rows). */
void func_00135520(u8 *arg0, s64 arg1, u8 arg2, s32 arg3)
{
    union {
        s64 raw;
        f32 f[2];
    } pos;
    f32 temp_f21;
    f32 temp_f20;
    s32 temp_16;
    u8 temp_17;
    u8 temp_18;
    u8 temp_19;
    s32 p;

    pos.raw = arg1;
    temp_17 = D_0064B2E8[0];
    temp_18 = D_0064B2E8[1];
    temp_19 = D_0064B2E8[2];
    temp_f21 = code13Add(pos.f[1], 26.0f);
    pos.f[1] = temp_f21;
    temp_16 = arg3 & 0xffff;
    if (temp_16 & 2) {
        p = *(s32 *)(arg0 + 0x1538);
        func_0034f2e0((void *)p, pos.f[0], temp_f21, temp_17, temp_18, temp_19, arg2);
        p = *(s32 *)(arg0 + 0x153c);
        temp_f20 = code13Add(467.0f, pos.f[0]);
        func_0034f2e0((void *)p, temp_f20, temp_f21, temp_17, temp_18, temp_19, arg2);
        p = *(s32 *)(arg0 + 0x1540);
        temp_f21 = code13Add(130.0f, temp_f21);
        func_0034f2e0((void *)p, pos.f[0], temp_f21, temp_17, temp_18, temp_19, arg2);
        p = *(s32 *)(arg0 + 0x1544);
        func_0034f2e0((void *)p, temp_f20, temp_f21, temp_17, temp_18, temp_19, arg2);
    }
    if (temp_16 & 1) {
        pos.f[0] -= 2.0f;
        pos.f[1] -= 26.0f;
        func_00134f40(arg0, pos.raw, 1, arg2);
    }
}
