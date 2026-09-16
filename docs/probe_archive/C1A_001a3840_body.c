// func_001a3840 (0x001a3840-0x001a3d50, 1296B) — guarded floor @279fndiff/1180B (116B under).
// Wins: full battle-packet coverage (sibling idioms); FMA mula/madd emitted (nested expr);
// all calls + decls (196bd0/1eb410/1979e0/1d3530/194b60/fGpffff811c); u16 counters.
// Walls: frame -0xB0 vs -0xF0 (spC0/spB0 stack slots vs regs); s0/s4 arg/t20 swap (arg-first,
//   FMA-commute neutral); FMA lwc1 pair order; daddiu-const rotation; st empty-then;
// 1991c0 s64-arg shape; GPREL phantoms.
// Unattempted before (no prior note). Production stays ASM.
void func_001a3840(u8 *arg0)
{
    u8 *t20;
    s16 st;
    s32 spC0;
    f32 f20;
    s16 spB0;
    s32 v18;
    s32 v19;
    s32 v21;
    s32 v22;
    s32 v23;
    u8 *pkt;

    t20 = *(u8 **)(arg0 + 1092);
    st = *(s16 *)(arg0 + 1096);
    if (st == 0) {
    } else if (st == 1) {
        spC0 = 0x100001;
        v18 = 27;
        v19 = 0;
        {
            f32 a = *(f32 *)(*(u8 **)(arg0 + 48) + 44);
            f32 b = *(f32 *)(*(u8 **)(arg0 + 48) + 144);
            f32 c = *(f32 *)(*(u8 **)(t20 + 48) + 44);
            f32 d = *(f32 *)(*(u8 **)(t20 + 48) + 144);
            f20 = 50.0f + (a * b + c * d);
        }
        spB0 = -1;
        v23 = 14;
        v22 = arg0[0] & 0xFFFF;
        v21 = 12;
        *(u16 *)(arg0 + 26) = *(u16 *)(arg0 + 26) | 0x800;
    } else {
        spC0 = 30;
        v18 = 29;
        f20 = 50.0f + func_00196bd0(*(u8 **)(arg0 + 48), *(u8 **)(t20 + 48), 29);
        v19 = func_001991c0(*(u8 **)(arg0 + 48), 29, 1.0f) & 0xFFFF;
        v23 = 15;
        spB0 = 40;
        v22 = 0;
        v21 = 10;
        *(u16 *)(arg0 + 26) = *(u16 *)(arg0 + 26) | 0x1000;
    }
    func_001a03b0((s64 *)arg0);
    func_001eb410(arg0 + 56);
    *(u8 **)(arg0 + 56) = t20;
    *(s16 *)(arg0 + 106) = 1;
    if ((v22 & 0xFFFF) != 0) {
        pkt = func_001f99c0(arg0, v22, *(u16 *)(*(u8 **)(t20 + 48) + 164), 0, 0);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 1);
    }
    if ((*(s32 *)(iGpffffb3ac + 12) & 0x200000) == 0) {
        pkt = func_001bc920(arg0, 25);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
        pkt = func_001979e0(*(u8 **)(arg0 + 48), *(u8 **)(t20 + 48), 10, f20, fGpffff811c);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
    } else {
        pkt = func_00194b60();
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 0);
    }
    pkt = func_002022e0(*(u32 *)(arg0 + 48), v23);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 3);
    pkt = func_001d3530(*(u8 **)(arg0 + 48), *(u8 **)(t20 + 48), v22);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    pkt = func_001bc920(arg0, 42);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    func_00194590(pkt, 0);
    if ((v21 & 0xFFFF) != 0) {
        pkt = func_001f99c0(arg0, v21, *(u16 *)(*(u8 **)(t20 + 48) + 164), 0, 0);
        *(pkt + 0) = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        func_00194590(pkt, 1);
    }
    pkt = func_00199ee0(*(u8 **)(arg0 + 48), v18, 0, 0, 1.0f);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    *(s16 *)(pkt + 74) = func_00199500(*(u8 **)(arg0 + 48), v18, 1.0f);
    func_00194590(pkt, 0);
    pkt = func_00199ee0(*(u8 **)(t20 + 48), v19, 0, 0, 1.0f);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)arg0;
    *(s16 *)(pkt + 72) = v19;
    func_00194590(pkt, 0);
    if (spB0 != -1) {
        pkt = (u8 *)func_001d6240(*(u32 *)(*(u8 **)((u8 *)iGpffffb3ac + spB0 * 4 + 3332)), (u32)*(u8 **)(arg0 + 48), (u32)*(u8 **)(t20 + 48), 1, 0);
        *(pkt + 0) = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(s64 *)(pkt + 96) = *(s64 *)arg0;
        *(s16 *)(pkt + 72) = v19;
        func_00194590(pkt, 2);
    }
}
