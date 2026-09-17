// func_001427c0 (0x001427C0, window 1072B) — guarded floor.
// Measured: object 1076B/window 1072B (4B over; 269 vs 268 instrs);
// reloc-masked nd 225 via probe_variants on actual-current owner with
// honest Float2 pos (s64 draft corrected per func_001424b0 precedent);
// fnalign edits 213 (+4 reloc-only).
// Retail relocs 14 (D_008872F8 hi/lo, func_00457120, D_0064B2F4 hi/lo,
// D_00887300 hi/lo, func_00364c50, D_00887310 hi/lo, func_00364c70,
// D_0064B2E8 hi/lo, func_0034f2e0); candidate resolves all 14 (no new data
// symbols; D_0064B2E8/F4 via block-scope u8[] as in func_001424b0).
// Wins: Float2 pos (s64 held two f32s; sd/lwc1 spill+reload matches 1424b0);
// (f32)(u32) byte/arg1 conversions (retail bltz+srl/andi/or doubling for
// u32->float); i%5 via div/mfhi with sll/addu/sll base+index (matches retail
// addu base,index); bottom-test while loops (jump-to-condition, as in 142bf0);
// x1/y1 loop-invariant hoists (explicit 1.0f+x/y before 6-loop; edits 221->213).
// Walls: frame 0x230 vs retail 0x250 (32B short; 3 int saves vs 5 — s2 pal base
// + s4 mdl; hoisting them regresses 225->236 with j/mdl swap and missing andi,
// mdl alone 257, pal alone 254, so kept direct with 15 extra luis); FPR colors
// (x f23 vs f21, y f22 vs f20, base f21 vs f23, recip f20 vs f22; reverse-definition
// vs retail; float-order sweep all 225-226, div one_first/div_first neutral);
// div scheduling (lwc1 before lui vs lui before lwc1; direct worse 248);
// u8 stack traffic vs u32 double-loads (u32 worse 235/274); prop_off worse 251/239.
// Levers tried: v1 227 -> v3 225 (float order base,recip,x,y) -> comma x1/y1
// 225/213; packet base+0x40 split neutral; 415 as (f32)0x19F same (constant-folded);
// int decl orders all 236 (edits 185 vs 194); loop_invariants on neutral.
// Production stays ASM.
void func_001427c0(Float2_0014 pos, s32 arg1, u8 *arg2, f32 fparg0)
{
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2F4[];
    extern void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u32 arg4);
    u8 buf[0x1C0];
    f32 base;
    f32 recip;
    f32 x;
    f32 y;
    f32 diff;
    u8 cr;
    u8 cg;
    u8 cb;
    s32 i;
    s32 j;
    u8 *src;
    u8 *dst;
    f32 x1;
    f32 y1;
    x = pos.x;
    y = pos.y;
    base = D_008872F8[0];
    recip = p4_0014_recip(*(f32 *)(func_00457120() + 0x80));
    D_00887300[0](1, 0);
    *(f32 *)(buf + 0x00) = 1.0f + ((f32)0x19F + x);
    *(f32 *)(buf + 0x04) = 1.0f + (221.0f + y);
    diff = base - fparg0;
    *(f32 *)(buf + 0x08) = diff;
    *(f32 *)(buf + 0x20) = (f32)(u32)(cr = D_0064B2F4[0]);
    *(f32 *)(buf + 0x24) = (f32)(u32)(cg = D_0064B2F4[1]);
    *(f32 *)(buf + 0x28) = (f32)(u32)(cb = D_0064B2F4[2]);
    *(f32 *)(buf + 0x2C) = (f32)(u32)arg1;
    *(f32 *)(buf + 0x18) = recip;
    i = 0;
    x1 = 1.0f + x;
    y1 = 1.0f + y;
    while (i < 6) {
        src = arg2 + ((i % 5) * 0x30);
        dst = buf + 0x40 + (i << 6);
        *(f32 *)(dst + 0x00) = x1 + *(f32 *)(src + 0x590);
        *(f32 *)(dst + 0x04) = y1 + *(f32 *)(src + 0x594);
        *(f32 *)(dst + 0x08) = diff;
        *(f32 *)(dst + 0x20) = (f32)(u32)cr;
        *(f32 *)(dst + 0x24) = (f32)(u32)cg;
        *(f32 *)(dst + 0x28) = (f32)(u32)cb;
        *(f32 *)(dst + 0x2C) = (f32)(u32)arg1;
        *(f32 *)(buf + 0x18) = recip;
        i += 1;
    }
    func_00364c50();
    D_00887310[0](5, buf, 7);
    func_00364c70();
    j = 0;
    while (j < 5) {
        u8 *e;
        f32 px;
        f32 py;
        u8 tint;
        u32 alpha;
        e = arg2 + (j * 0x30);
        px = (*(f32 *)(e + 0x590) + x) - 5.0f;
        py = (*(f32 *)(e + 0x594) + y) - 5.0f;
        tint = *(u8 *)(e + 0x59A);
        alpha = ((tint * (arg1 & 0xFF)) / 255) & 0xFF;
        func_0034f2e0(*(void **)(arg2 + 0x1838), px, py, D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], alpha);
        j += 1;
    }
}
