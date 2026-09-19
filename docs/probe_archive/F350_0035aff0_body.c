/* repaired 2026-09-18: compiled clean against current tree (no stale signatures; removed 3 redundant function-local externs now at file scope: func_0044b7b0, D_0064CC98, func_0046d730; probe 449w tie). Fresh re-measure matches header: probe 449w, fnalign retail 692 vs object 646 (-46, -6.6%), 194 edits (+8 reloc-only), frame 0xB10. Disagreements quoted, not copied: task states 696 instrs vs fnalign 692 (window 2784B=696 words; 4-word diff already noted in header), task 317 lines vs file 316 (wc -l 316). Installed as // FUN_0035AFF0 NONMATCHING guarded floor in src/promoted/code1_0035.c (231-line body, production stays ASM). Bounded post-install: pragma_sweep singles best 446 (opt_dead_assignments off) but object 641 instrs (-51) and 225 edits (worse) -- REJECTED as shrinking false win per opclass trap; pairs no better than 446; 7n counter-split 449 tie (keep shared i/j); decl vtx/i swap 449 tie (keep order). opclass: nop -9, daddiu -6, mtc1/cvt -6, lui +5 (folding, not width; no dsll32). residual_signature: 194 edits, mask 1, class 1, perm 4. verify src/promoted/code1_0035.c 74 MATCH/6 ASM, lint 0, -DNON_MATCHING compiles. */
/* Target: func_0035aff0
   Owner: src/promoted/code1_0035.c
   Retail address/window: 0x0035aff0, 2784B window (692 instrs via fnalign; task states 696)
   Compiler/profile: MWCCPS2 3.0.1 build 210 at -O2 (first-party default; repo config wins)
   Evidence read: asm/nonmatchings/code1_0035/func_0035aff0.s (full 754 lines),
     docs/ghidra_headstart/src/promoted/code1_0035.c func_0035aff0 range,
     docs/ida_headstart/src/promoted/code1_0035.c sub_35AFF0 range,
     src/generated/code1_0035.c P4_UNIT_0035AFF0 M2C candidate,
     current owner around // FUN_0035AFF0 plus MATCHed siblings func_0035c040
     and func_00354ba0 in the same file, /var/tmp/cold35aff0/m2c.c (m2c),
     /var/tmp/cold35aff0/rom.c + rom_raw.c + --types (romwright).
   Initial candidate: de-noised m2c+romwright into this file's idiom (Qf quads,
     Float2 lighting points, s16 index buffer, plain (f32)(u32)/(u8) casts).
   Semantic gate: early guard is lb (s8 at p+0x20), not lhu like func_0035c040;
     kept as *(s8*)(t+0x20). func_00489f80/func_0048a000 are void (no arg setup
     in retail; mdlEffect.c void definition wins over mdlManager.c u32 decl).
     func_0035bd20 takes three Float2 by value (ld $4/$5/$6); written as
     Float2 triple. func_0044b7b0/func_0044b610 are f32(f32). D_008872F8 is
     absolute (lui); 2pi/pi are gp-relative fGpffff81e0/fGpffff82fc
     (lwc1 -0x7E20/-0x7D04($gp), reloc-only). D_00887300/310/314 are indirect
     arrays; first draw is func_0034f1e0 + 87300(1,*tex) + 87310(4,qs,4).
     No UB, no omitted args, no fake returns, no volatile/inline asm.
   Truthful residual (via fnalign --candidate): retail 692 instrs, object 646
     instrs (46 short, 6.6% short, outside the 3% banking gate, so this is a
     DRAFT, not a floor; production stays INCLUDE_ASM). 194 edits (+8
     reloc-only). Frame exact 0xB10 (prologue 0-22 match). Early qs fills
     match after float reorder; remaining groups are: flat-branch integer
     immediates (retail daddiu $t3/$t2/$t1/$t0 + 4x bltz/cvt vs object
     addiu + 2x lui/sw immediates for 242/255 constants -- b210 folds
     (f32)242 to 242.0f; opt_propagation off fixes it in micro but costs
     +165 words whole-function, scoped pragma inside function is inert);
     D_00887300/310 base hoist (retail lui+addiu into $s2/$s0 reused vs
     object per-call lui/lw); wave/index GPR colors (retail $s3/$s4/$s5 for
     outer/vtx/inner and $t0/$a3 temps for index vs object $s5/$s4 saved);
     wave sy FPR tint; index address-chain scheduling; 35bd20 grey lighting
     (u8 g8 then 4x (f32)g8 vs retail andi/masked s32 chain + scheduling).
     COP1 adda.s/madd.s/msub.s for ptA/ptB/cur are plain C
     (*p+0.78125*(64*s), *(p+4)-64*c, *p+2*(sx*(j/4-0.5))) and align.
   Decisive levers: Qf qs[4] first (high at sp+0x9F0) over idx/verts-first
     (512->484 words); float decl order sx,sy,u0,v0,u1,v1,blend,z,q to put
     sx/sy high ($f28/$f27) and q low ($f20) (484->449, early FPRs close,
     z reloc-only); dropping the dead s2hold spill (pt shift +8 fixed).
   Candidate emitted/window: 646/692 instrs (2584B/2768B), 46 short.
   Relocations: D_008872F8, func_00457120, func_0035bad0, func_0034f1e0,
     D_00887300/310/314, func_003f6440, func_00489f80/0048a000,
     func_0044b7b0/610, func_0035bd20, D_0064CC98, fGpffff81e0/82fc;
     fnalign reports 8 reloc-only (gp-relative lwc1 + lui/lo pairs).
   Resolved prefix: not byte-exact (449 reloc-masked differing words).
   Retail suffix: none claimed (object shorter; no zero-tail proof).
   Other owner functions: untouched (func_0035c040, func_00354ba0 MATCHed;
     func_00355920 banked floor). No TU edits made; all probes via
     probe_variants --candidate (source never written).
   Callers/declarations changed: none.
   Hardware contract: none (ordinary EE C; no COP2/VU transfers).
   Repository verifier/link: probe_variants 449 words (best), fnalign
     194 edits; no verify MATCH claimed; no build.py link run for draft.
   Remaining caveats: DRAFT outside 3% (46 short); flat constant folding,
     D-base hoist, and saved-vs-temp GPR cycle are the open 194 edits.
   Private artifacts: /var/tmp/cold35aff0/m2c.c, rom.c, rom_raw.c,
     cand_v1.c, reord_*.c, v5_floatreord.c, v6_flatfix.c (best),
     v7a/v7b, prag_*.c, v10_subscript.c, align_*.txt.

   Rejected variants with scores (per do-not-tidy rule, all via
   probe_variants on the actual owner):
   - cand_v1 (idx,verts,qs order; z,q,blend,sx... floats): 512w, 279e.
   - qs-first / idx-last (Qf qs high): 484w (both).
   - verts-first: 512w tie (no gain).
   - s2hold-last: 484w tie (s2hold dead; later removed).
   - float reorder sx,sy,u0,v0,u1,v1,blend,z,q + drop s2hold (v5): 449w, 204e.
   - flat pointer+off to subscript (v10): 449w tie.
   - pt orders cur/ptA/ptB permutations (4 variants): all 449w tie.
   - flat block-scope flatA/B (v9): 449w tie, 194e tie kept.
   - grey u8->s32 (v7a): 442w but 593 instrs (99 short, 14% short) -- REJECT
     per 3% gate (shrinks object; histogram trap).
   - flat s32->s64 (v7b): 447w, 200e tie-ish, size 646 kept.
   - grey+flat s64 (v7): 440w but 593 instrs -- REJECT per 3% gate.
   - free pragmas on v6: opt_loop_invariants on 643w, schedule on 638w,
     opt_unroll_loops off 449w tie, schedule off 449w tie.
   - whole-function opt_propagation off (v8): 614w -- REJECT (hurts early qs).
   - micro: (f32)242 folds to lui/sw; opt_propagation off gives
     addiu+mtc1/cvt in isolation but scoped pragma inside function is inert.
 */
f32 func_0035aff0(u8 *arg0, s32 arg1)
{
    extern u8 *func_00457120(void);
    extern f32 D_008872F8[];
    extern f32 func_0035bad0(u8 *arg0);
    extern void func_0034f1e0(void);
    extern s32 (*D_00887300[])(s32, s32);
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    extern void (*D_00887314[])(s32 arg0, void *arg1, s32 arg2, void *arg3, s32 arg4);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0035bd20(Float2 first, Float2 second, Float2 origin);
    extern f32 fGpffff81e0;
    extern f32 fGpffff82fc;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        s32 _c;
        f32 u;
        f32 v;
        f32 q;
        s32 _1c;
        s32 r;
        s32 g;
        s32 b;
        f32 a;
        s32 _pad[4];
    } Qf;
    Qf qs[4];
    Float2 cur;
    Float2 ptA;
    Float2 ptB;
    Qf verts[35];
    s16 idx[64];
    u8 *p;
    f32 sx;
    f32 sy;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    f32 blend;
    f32 z;
    f32 q;
    f32 ang1;
    f32 ang2;
    f32 s1;
    f32 c1;
    f32 s2;
    f32 c2;
    s32 mode;
    s32 i;
    s32 j;
    s32 vtx;
    s32 flatA;
    s32 flatB;

    p = *(u8 **)(arg0 + 0x38);
    z = D_008872F8[0];
    q = 1.0f / *(f32 *)(func_00457120() + 0x80);
    {
        u8 *t = *(u8 **)(arg0 + 0x38);
        s32 flag;
        if ((*(s32 *)(t + 0x2C) == 0) || (*(s8 *)(t + 0x20) == 0)) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag == 0) {
            return 0.0f;
        }
    }
    blend = func_0035bad0(p);
    sx = 50.0f * *(f32 *)(p + 8);
    sy = 64.0f * *(f32 *)(p + 12);
    if (*(s32 *)(p + 0x28) & 1) {
        u0 = 0.78125f;
        v0 = 1.0f;
        u1 = -0.78125f;
        v1 = -1.0f;
    } else {
        u0 = 0.0f;
        v0 = 0.0f;
        u1 = 0.78125f;
        v1 = 1.0f;
    }
    qs[0].x = *(f32 *)p - sx;
    qs[0].y = *(f32 *)(p + 4) - sy;
    qs[0].z = z;
    qs[0].r = 0x437F0000;
    qs[0].g = 0x437F0000;
    qs[0].b = 0x437F0000;
    qs[0].a = (f32)(u32)arg1;
    qs[0].u = u0;
    qs[0].v = v0;
    qs[0].q = q;
    qs[1].x = *(f32 *)p + sx;
    qs[1].y = *(f32 *)(p + 4) - sy;
    qs[1].z = z;
    qs[1].r = 0x437F0000;
    qs[1].g = 0x437F0000;
    qs[1].b = 0x437F0000;
    qs[1].a = (f32)(u32)arg1;
    qs[1].u = u0 + u1;
    qs[1].v = v0;
    qs[1].q = q;
    qs[2].x = *(f32 *)p - sx;
    qs[2].y = *(f32 *)(p + 4) + sy;
    qs[2].z = z;
    qs[2].r = 0x437F0000;
    qs[2].g = 0x437F0000;
    qs[2].b = 0x437F0000;
    qs[2].a = (f32)(u32)arg1;
    qs[2].u = u0;
    qs[2].v = v0 + v1;
    qs[2].q = q;
    qs[3].x = *(f32 *)p + sx;
    qs[3].y = *(f32 *)(p + 4) + sy;
    qs[3].z = z;
    qs[3].r = 0x437F0000;
    qs[3].g = 0x437F0000;
    qs[3].b = 0x437F0000;
    qs[3].a = (f32)(u32)arg1;
    qs[3].u = u0 + u1;
    qs[3].v = v0 + v1;
    qs[3].q = q;
    func_0034f1e0();
    D_00887300[0](1, **(s32 **)(p + 0x3C));
    D_00887310[0](4, &qs[0], 4);
    mode = *(s32 *)(p + 0x28);
    if (((mode & 1) != 0) || ((mode & 2) != 0)) {
        if ((mode & 1) != 0) {
            flatA = 0x15;
            flatB = 0;
        } else {
            flatA = 0;
            flatB = 0xBA;
        }
        {
            s32 cR;
            s32 cW;
            s32 k;
            cR = 0xF2;
            cW = 0xFF;
            for (k = 0; k < 4; k++) {
                u8 *qpp;
                qpp = (u8 *)&qs[k];
                *(f32 *)(qpp + 0x20) = (f32)cR;
                *(f32 *)(qpp + 0x24) = (f32)flatA;
                *(f32 *)(qpp + 0x28) = (f32)flatB;
                *(f32 *)(qpp + 0x2C) = (f32)cW;
            }
        }
        func_00489f80();
        func_003f6440(3, 0x31801);
        D_00887310[0](4, &qs[0], 4);
        func_0048a000();
        D_00887300[0](1, 0);
        func_003f6440(3, 0x31801);
        func_003f6440(2, 0x58);
        D_00887310[0](4, &qs[0], 4);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    } else if (mode & 4) {
        f32 f;
        f = (f32)*(s16 *)(p + 0x24) / 100.0f;
        ang1 = fGpffff81e0 * f;
        ang2 = fGpffff82fc + ang1;
        s1 = func_0044b7b0(ang1);
        c1 = func_0044b610(ang1);
        s2 = func_0044b7b0(ang2);
        c2 = func_0044b610(ang2);
        ptA.x = *(f32 *)p + 0.78125f * (64.0f * s1);
        ptA.y = *(f32 *)(p + 4) - 64.0f * c1;
        ptB.x = *(f32 *)p + 0.78125f * (64.0f * s2);
        ptB.y = *(f32 *)(p + 4) - 64.0f * c2;
        vtx = 0;
        for (i = 0; i < 7; i++) {
            f32 rowDY;
            f32 rowV;
            rowDY = 2.0f * (sy * ((f32)i / 6.0f - 0.5f));
            rowV = v0 + v1 * ((f32)i / 6.0f);
            for (j = 0; j < 5; j++) {
                f32 grey;
                u8 g8;
                cur.x = *(f32 *)p + 2.0f * (sx * ((f32)j / 4.0f - 0.5f));
                cur.y = *(f32 *)(p + 4) + rowDY;
                verts[vtx].x = cur.x;
                verts[vtx].y = cur.y;
                verts[vtx].z = z;
                verts[vtx].u = u0 + u1 * ((f32)j / 4.0f);
                verts[vtx].v = rowV;
                verts[vtx].q = q;
                grey = 255.0f * func_0035bd20(ptA, ptB, cur);
                g8 = (u8)grey;
                verts[vtx].a = (f32)g8;
                *(f32 *)&verts[vtx].r = (f32)g8;
                *(f32 *)&verts[vtx].g = (f32)g8;
                *(f32 *)&verts[vtx].b = (f32)g8;
                vtx++;
            }
        }
        if (vtx >= 0x24) {
            func_0046d730(&D_0064CC98, 0x835);
        }
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 5; j++) {
                idx[i * 10 + j * 2] = (s16)(j + i * 5);
                idx[i * 10 + j * 2 + 1] = (s16)(j + (i + 1) * 5);
            }
        }
        func_00489f80();
        func_003f6440(3, 0x31801);
        for (i = 0; i < 6; i++) {
            D_00887314[0](4, &verts[0], 0x23, &idx[i * 10], 10);
        }
        func_0048a000();
        D_00887300[0](1, 0);
        func_003f6440(3, 0x31801);
        func_003f6440(2, 0x58);
        for (i = 0; i < 6; i++) {
            D_00887314[0](4, &verts[0], 0x23, &idx[i * 10], 10);
        }
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
    return blend;
}
