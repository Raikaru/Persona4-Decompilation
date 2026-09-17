/* lane=yCmb addr=00347c70
 * object_size=1204 window=1216 differing words (reloc-masked): 56
 * fnalign: retail 301 instrs object 301 instrs, edit instructions 58 (+4 reloc-only)
 * residual offsets (fnalign top-down, --candidate):
 *   preheader + loop head (retail[16:30] vs object[16:30]): move $a2 vs $a1,
 *     lui %hi(D_008872F8) hoisted alone in retail ($v0 at entry, lwc1 %lo per iter
 *     + sub.s per iter); with #pragma opt_loop_invariants on the whole D-1.0
 *     (lui+lwc1+sub) hoists to preheader (lui $v0,lwc1 $f0,sub $f1) and body stores $f1.
 *     lui-only hoist not reproduced (direct array keeps lui in body; f32*dtab hoists
 *     lui+addiu (270) or full address (279/289)). Isolated loop proof: opt_loop_invariants
 *     hoists whole invariant; without it rematerialises per iter (y_draw/y_smap family).
 *   loop body x4 (retail[31:88] vs object[31:88]): or/mtc1 chain keeps result in $v1
 *     (srl $v1,$v0 / andi $v0 / or $v1,$v1,$v0 / mtc1 $v1) vs retail $a0
 *     (srl $a0,$v1 / andi $v1 / or $a0,$a0,$v1 / mtc1 $a0); dest swc1 base $a0 vs $a1,
 *     lbu/mtc1 temp $v0 vs $v1, counter $a1 vs $a2 (dest $a1=>counter $a2 in retail;
 *     dest $a0=>counter $a1 here). Tried recipe A explicit v/c/doubling (76, worse),
 *     both if/else orders, per-site fresh locals, decl reorders, off+base lever
 *     (s32 off=(s32)i*0x40;(u8*)(off+(s32)obj), 279), raw (s32)obj+i*0x40+off fixes
 *     body-head dsll32/dsra32 (v9 265 size-exact 304/304, FMA matched) vs p=obj+i*0x40
 *     (no body-head ext, 261 smaller-but-wrong mul FMA). Same or-register coloring floor
 *     as prior 263 note + y_draw 002b7f20 + y_smap 002b0b10.
 *   FMA block (8x 0x10/0x14/0x50/0x54/0x90/0x94/0xD0/0xD4): MATCHED with reload idiom
 *     *(0x134/0x138) +/- 64.0f * *(0x1A0) (literal 64.0f => lui/mtc1, adda/msub/madd).
 *     Isolated proof: cached f1b/c64 (h1) => mul.s+sub.s/add.s (261, smaller-but-wrong);
 *     reload (h2) => adda.s+msub.s/madd.s with $f3=64,$f2=0 hoisted (matches retail
 *     $f3/$f2, only $v1 vs $v0 lui-temp differs). Cached 261 vs reload 279 without pragma;
 *     with pragma reload stays ACC and loop shrinks to 56.
 *   tail conversion (retail[269:281] vs object[269:281]): (u8)(s32)fres guard
 *     if (2147483648.0f > fres) direct else (fres-2^31)|0x80000000 keeps c.le.s/bc1t
 *     + per-arm andi, but mfc1/or/sb color $v0 vs $v1 (or $v0,$v1,$v0 vs $v1,$v1,$v0).
 *     Same conversion-coloring floor as 00348330 nd16 note.
 * levers tried (all measured via probe_variants in correct tree, pwd below):
 *   - v1 baseline p-style + one/div locals (262) -> v4 tight scope (261 best w/o pragma)
 *   - v2 no-p direct obj+i*0x40 (265), v3 p+literal (262), v5 reload FMA (279),
 *     v6 dtab pointer (279), v7 while (279), v8 off+base (279), v9 raw int
 *     ((s32)obj+(s32)i*0x40+off, 265, 304/304 size-exact, body-head ext + FMA matched)
 *   - v10 raw+opt_loop_invariants on (56) / push+on (56, kept): 265->56, full-hoist
 *     vs lui-only (see above); v11 raw+dtab (270), v12 raw+dtab+pragma (289) reject dtab
 *   - v13 recipe A explicit s32 v/u32 c/doubling (76) rejects recipe A here
 *     (plain (f32)*(u8*) already single bltz, as in matched 003489c0)
 *   - s16 i required for dsll32/dsra32 0x10 pairs; flag ((x&N)>>k)==1 for andi/sra;
 *     1.0f/64.0f literals for lui/mtc1; /2 for sra+correction; func_00285b30<0x208,
 *     func_002b2aa0(0/1,...), func_002b2cb0(...,1,...,0,1) per asm $4/$5/$6/$7/$8.
 * docs: docs/matching.md (bottom-test loop, raw byte-offset addu, mirror off+base,
 *   opt_loop_invariants lever not floor, FPU ACC from ordinary C, branch polarity
 *   per-if, call-arg order floor, saved-reg coloring floor, hoisting granularity floor),
 *   docs/compiler-floors.md (no movz floor here; commutative addu only when live-fixed),
 *   docs/STYLE.md (scoped push/pop, measured waiver).
 * fnalign: never bare on INCLUDE_ASM; all scripts via --candidate /var/tmp/cmb347c70/body_*.c
 * opclass: banked NONMATCHING only (0033e5c0, 00348c40); this target stays INCLUDE_ASM
 *   per floor policy, so opclass shows no surplus for it (1-2 floors scanned, 0 surplus).
 *   Width/signedness already correct (s16/dsll32, u8/lbu, s16/lh, f32/cvt) - earliest
 *   fnalign hunk is allocation/hoisting, not width.
 */
// FUN_00347C70
#pragma push
#pragma opt_loop_invariants on
s32 func_00347c70(u8 *arg0)
{
    u8 *obj;
    f32 div;
    s16 i;

    obj = *(u8 **)(arg0 + 0x38);
    div = 1.0f / *(f32 *)(func_00457120() + 0x80);
    if (((( *(s32 *)(obj + 0x11C) & 2) >> 1) == 1)) {
        for (i = 0; i < 4; i++) {
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x18) = D_008872F8[0] - 1.0f;
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x28) = div;
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x30) = (f32)*(u8 *)(obj + 0x198);
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x34) = (f32)*(u8 *)(obj + 0x199);
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x38) = (f32)*(u8 *)(obj + 0x19A);
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x3C) = (f32)*(u8 *)(obj + 0x19B);
        }
    }
    *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x134) - 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x14) = *(f32 *)(obj + 0x138) - 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x50) = *(f32 *)(obj + 0x134) + 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x54) = *(f32 *)(obj + 0x138) - 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x90) = *(f32 *)(obj + 0x134) - 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x94) = *(f32 *)(obj + 0x138) + 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0xD0) = *(f32 *)(obj + 0x134) + 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0xD4) = *(f32 *)(obj + 0x138) + 64.0f * *(f32 *)(obj + 0x1A0);
    if (func_00285b30() < 0x208) {
        u8 *alloc = func_00461390(D_00794F00, 4, obj + 0x10, 4);
        *(u32 *)(alloc + 8) = (u32)func_00347b30;
        *(u8 **)(alloc + 0x10) = obj;
    }
    if (((( *(s32 *)(obj + 0x11C) & 4) >> 2) == 1)) {
        f32 f14 = (f32)*(s16 *)(obj + 0x13E);
        f32 f15 = (f32)*(s16 *)(obj + 0x13C);
        *(f32 *)(obj + 0x134) = func_002b2aa0(0, *(f32 *)(obj + 0x124), *(f32 *)(obj + 0x12C), f14, f15);
        f14 = (f32)*(s16 *)(obj + 0x13E);
        f15 = (f32)*(s16 *)(obj + 0x13C);
        *(f32 *)(obj + 0x138) = func_002b2aa0(0, *(f32 *)(obj + 0x128), *(f32 *)(obj + 0x130), f14, f15);
        if (*(s16 *)(obj + 0x13E) < *(s16 *)(obj + 0x13C)) {
            *(s16 *)(obj + 0x13E) = func_002b2cb0(*(s16 *)(obj + 0x13E), 1, *(s16 *)(obj + 0x13C), 0, 1);
        } else {
            *(s32 *)(obj + 0x11C) &= 0xFFFB;
        }
    }
    if (((( *(s32 *)(obj + 0x11C) & 0x10) >> 4) == 1)) {
        f32 f12 = (f32)*(u8 *)(obj + 0x193);
        f32 f13 = (f32)*(u8 *)(obj + 0x197);
        f32 f14 = (f32)*(s16 *)(obj + 0x19C);
        f32 f15 = (f32)(*(s16 *)(obj + 0x19E) / 2);
        f32 fres = func_002b2aa0(1, f12, f13, f14, f15);
        u8 cv;
        if (2147483648.0f > fres) {
            cv = (u8)(s32)fres;
        } else {
            cv = (u8)((s32)(fres - 2147483648.0f) | 0x80000000);
        }
        *(u8 *)(obj + 0x19B) = cv;
        if (*(s16 *)(obj + 0x19C) < *(s16 *)(obj + 0x19E)) {
            *(s16 *)(obj + 0x19C) = func_002b2cb0(*(s16 *)(obj + 0x19C), 1, *(s16 *)(obj + 0x19E), 0, 1);
        } else {
            *(s16 *)(obj + 0x19C) = 0;
        }
    }
    return 0;
}
#pragma pop
