/* FUN_001B4060 floor (v4, fndiff ~308, obj 1416B / window 1488B, UNDER-72B).
 * Battle-packet chain, void, no args. Frame -336 retail, saves ra+s0-s7.
 *
 * WINS (retail-confirmed, m2c wrong):
 * - 1d6240 call is (t18, s4, s4, 1, 0) (m2c temp_5/0/0 wrong).
 * - 1f0a10 takes &sp120 (sp+288), NOT spA0 (m2c wrong).
 * - 201de0 9th stack arg is 64-bit (sd zero,0(sp)); decl last param u64.
 * - Missing 1d3e00(t18) tail call found (retail 50th jal).
 * - sp12C is UNINIT if 2428f0-test false (conditional store only, no else).
 * - sp124 stored but never read (dead store is retail shape; H007 warn expected).
 * - 1b7080/1b7090 MATCHED void-defs DO take a0=317 at call sites; sigs updated
 *   to (s32 arg0) (unused param, verified zero-byte, still MATCH).
 * - Masked-temp idiom: (call&0xFFFF)-(call&0xFFFF) via andi/subu/sw.
 *
 * WALLS (coloring/frame, stop):
 * - Frame -160B (mine -176/-272 vs retail -336); saves s0-s5 vs s0-s7.
 * - s-map rotation (t16 s1-vs-s0, t18 s0-vs-s2, v19 not-in-s3).
 * - Retail keeps masked temps in s1/s7 (reused packet regs); single-pkt var
 *   cannot split across s-regs (disjoint ranges coalesce).
 * - s6/s7 hold short-span values (no pressure in clean C to force them).
 * - spA0[32] vs [128] both miss (frame -176/-272); s32 offsets cluster low
 *   (retail spread 288-332 with 8B/28B gaps = hidden locals/spills).
 * - Function-scope masked temps + pkt-split pressure all measured inert.
 * - Stop: two orthogonal levers (spA0 size, temp scope) inert; coloring wall.
 */
// FUN_001B4060 floor body (v4, fndiff ~308, obj 1416B/window 1488B)
void func_001b4060(void)
{
    u8 *t16;
    s32 v19;
    s32 t18;
    u8 *pkt;
    u8 spA0[32];
    s32 sp14C;
    s32 sp148;
    s32 sp12C;
    s32 sp124;
    s32 sp120;
    u8 *v20;

    t16 = *(u8 **)(iGpffffb3ac + 368);
    v19 = 0;
    t18 = func_001d3d50(0);
    func_001d69f0(317, spA0);
    pkt = func_001d5eb0(t18, spA0, 0);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = func_001f8000(317, 0);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    func_001b7060(317, &sp14C, &sp148);
    pkt = func_001b7880(sp14C, sp148, 16);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    t18 = func_001b7080(317);
    func_001b70a0(317, &sp14C, &sp148);
    pkt = func_001b83f0(t18, sp14C, sp148, 16, 0);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = func_001b9560(func_001b7090(317), 16);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = (u8 *)func_001d6240(t18, (u32)t16, (u32)t16, 0, 0);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 2);
    pkt = func_001f8140(0);
    *(pkt + 0) = 5;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    func_00194590(pkt, 1);
    v20 = *(u8 **)(iGpffffb3ac + 376);
    while (v20 != NULL) {
        u8 *t21;
        s32 v0a;
        s32 v1a;
        t21 = (u8 *)func_001b0c80((s32)v20);
        func_001f0a10((u8 *)&sp120);
        v0a = func_00231f80((DatUnit *)(v20 + 2660)) & 0xFFFF;
        v1a = func_00232290((DatUnit *)(v20 + 2660)) & 0xFFFF;
        sp120 = (v0a & 0xFFFF) - (func_00231ed0(v20 + 2660) & 0xFFFF);
        sp124 = (v1a & 0xFFFF) - (func_00231ee0(v20 + 2660) & 0xFFFF);
        if (func_002428f0(*(s32 *)(v20 + 2660), 0) != 0) {
            sp12C = 0x80000;
        }
        pkt = func_00202740(v20);
        *(s64 *)(pkt + 96) = *(s64 *)t16;
        func_00194590(pkt, 1);
        pkt = (u8 *)func_001d6240(t18, (u32)v20, (u32)v20, 1, 0);
        *(pkt + 0) = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(pkt + 16) = 4;
        *(s64 *)(pkt + 24) = v19;
        *(s64 *)(pkt + 96) = *(s64 *)t16;
        func_00194590(pkt, 2);
        pkt = func_001f8140(1);
        *(pkt + 0) = 5;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        func_00194590(pkt, 1);
        pkt = func_001bc920(t21, 27);
        *(pkt + 0) = 5;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(pkt + 32) = 11;
        *(s64 *)(pkt + 40) = *(s64 *)(pkt + 88);
        *(s16 *)(pkt + 74) = 18;
        *(s64 *)(pkt + 96) = *(s64 *)t16;
        func_00194590(pkt, 0);
        if ((sp12C & 0x80000) != 0 && (*(s32 *)(v20 + 156) & 0x200) != 0) {
            pkt = func_00199ee0((u8 *)v20, 20, 0, 0, 1.0f);
            *(pkt + 0) = 11;
            *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
            *(s64 *)(pkt + 96) = *(s64 *)t16;
            func_00194590(pkt, 1);
        }
        pkt = func_001f36e0((s32)v20, (s32)v20, &sp120, 1, 1);
        *(pkt + 0) = 11;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(s64 *)(pkt + 96) = *(s64 *)t16;
        func_00194590(pkt, 1);
        if (sp120 != 0) {
            pkt = func_00202590((u8 *)v20, 0, 0);
            *(pkt + 0) = 4;
            *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
            *(pkt + 71) = *(pkt + 71) & 0xDF;
            func_00194590(pkt, 3);
        }
        pkt = func_00201de0((s32)v20, (s32)v20, -1, 0, 0, 0, 1, (u8 *)&sp120, 0);
        *(pkt + 0) = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(pkt + 71) = *(pkt + 71) & 0xDF;
        func_00194590(pkt, 3);
        v20 = *(u8 **)(v20 + 2668);
    }
    pkt = func_001b7e20(16);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = v19;
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = func_001b9360(16, 0);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = v19;
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = func_001b99a0(16);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    func_001d3e00(t18);
}
