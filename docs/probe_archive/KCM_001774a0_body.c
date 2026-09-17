/* func_001774a0 @ 0x001774a0 / owner src/Kosaka/k_command/k_command.c
   asm asm/nonmatchings/k_command/func_001774a0.s / window 1392B (0x570)
   floor candidate: object 345 instrs (1380B) / retail 345 instrs executable (1380B)
   fndiff 183 differing words positional (reloc-masked) / fnalign 27 edit instructions (+6 reloc-only)
   relocations 49 R_MIPS_26 jal, all resolved to retail targets
     (0029cc00 x2, 001452b0, 0046d730 x2, 00145270 x3, 0047a2f0 x12,
      0047a180 x7, 0047a1a0 x4, 003e0380 x3, 003e03e0 x3, 003e05d0 x3,
      00168c00, 0015bae0, 0017e9b0, 00155280 x2, 0016ec90,
      00168770, 0047a1e0, 00478e70), plus GP-relative global loads
     (D_005F1858 x2, D_005F1868, D_005F1870, D_007EF9B0) resolved.
   retail suffix after emitted prefix is zero alignment (3 nops, 12B at end of 0x570 window).
   frame 0xB0, saved s0=p/id/i, s1=v, s2=s2; stack a at 0xA0, neg at 0x90 match retail.
   Residual: cfg at 0x70 vs 0x80 (0x10 low), m case1 at 0x60 vs 0x70,
     m case3 at 0x50 vs 0x60, zz at 0x80-0x88 vs 0x50-0x58 (offsets off,
     order now reverse 0x88,0x84,0x80 to match retail 0x58,0x54,0x50),
     sltu x-form (retail sltu $v0,$zero,$a0 + beqz vs object beqz $a0),
     plus branch-displacement consequences (6 branches off by 1) and 1 tail nop.
     No register-color differences remain for a/neg/m loads/stores (Vec3f copies match);
     FPR colors match for grouped lwc1/swc1.
   Levers that worked, all measured via fnalign --candidate (verify kept ASM):
   - truthful func_0047a1a0(obj, &cfg, float, int) per src/promoted/k_fldUnit.c:81
     (void *arg0, void *arg1, f32 arg2, s32 arg3); prior S774A passed (obj,&cfg,int,float)
     swapped, which forces promotion masks and reorders $f12/$a2. Fix restores
     $4=obj, $5=&cfg, $f12=*(s2+0x14C), $6=0/2 exactly.
   - 12-byte cfg as single struct { s64 lo; f32 hi; } (adjacent D_005F1868[0]+D_005F1870[0],
     0x5F1868 8B + 0x5F1870 4B contiguous 12B). Separate s64 cfg + f32 cfgf with &cfg_lo
     loses the f32 store as dead (342 vs 345 instrs, missing lwc1/swc1) because &cfg_lo
     legally covers only 8B; struct keeps both stores (345/345) and matches retail ld/sd + lwc1/swc1.
   - shared function-level f32 a[3] + neg[3] (retail single a at 0xA0, neg at 0x90 across
     all cases). Per-case a/neg tripled frame to 0x180 (v1) then 0xF0 (v2); sharing gives 0xB0 exact.
   - Vec3f struct copies (*(Vec3f *)a = *(Vec3f *)(q+0x30) and *(Vec3f *)(q+0x30) = *(Vec3f *)(s2+0x140))
     for grouped lwc1x3/swc1x3. Direct a[0]=*(q+0x30) interleaves load-store (6 instrs interleaved
     vs grouped) and temps permute order (0x144,0x148,0x140); struct copies give grouped in order
     and collapse 100+ edits (v6 276E -> v7/v8 27E). Matches owner Vec3f idiom (k_command.c:616).
   - while-with-break loop (if (s2==0) error; while (s2!=0) { if ((*(u16*)s2&0x3FF)==id) break; s2=next; })
     vs while(s2!=0 && ...!=id) (bne) and goto-loop (extra b/beqz). Break form removes 2 replaces
     (v5 281E -> v6 276E -> v7 27E with Vec3f) and reproduces retail beq-break + bnez-loop.
   - no cached obj (reload *(p+0x164)/0x144 at each call). Caching obj in $s1 adds 4th saved reg
     (lw $s1 + move $a0,$s1 x7) vs retail reloads lw $a0 each time (3 saved regs only: s0,s1,s2).
   - cases 1,3,10,default only in source order 1,3,10 (retail chain 10,3,1 reverse-label rule).
     Prior S774A had case 2 break + case 4-9 breaks, adding extra beq chain (rejected).
   - C89 + hex (0x2C3=707, 0x337=823, 0x138/0x164/0x144/0x22C/0x228/0x140/0x14C/0x798/0x7A4/0x900/0x750)
     per owner style; prior S774A used dec + C99 for(s32 i) + mixed decls after statements (MWCC error).
   - neg as -1.0f * a[x] (mul.s with lui 0xBF80/mtc1) vs S774A -a[x] (neg.s, wrong opcode).
   - zz reverse store (zz[2]=z; zz[1]=z; zz[0]=z) reproduces retail swc1 0x58,0x54,0x50 high-to-low
     order (object now 0x88,0x84,0x80 reverse, offsets still off); forward gives 0x80,0x84,0x88.
   - declaration search 120 orders (function-level cfg/a/neg) neutral (6 orders, best stays 27E);
     all documented pragmas neutral except opt_common_subs off regresses 27E->257E. Recorded.
   - k variable kept for sibling style (s32 k = (v&0xFFC00)>>10; switch(k) as in 001773d0);
     removing k (direct switch) neutral (27E stays 27E). Kept for readability.
   Semantic gate: no UB/uninit/omitted-args/fake-returns/volatile/synthetic padding/asm/intrinsics.
     All callees canonical widths per owner (u16 for 00145270, s32 for 0029cc00/001452b0/00168c00/
     0016ec90/0017e9b0/00168770(f32 return)/00155280, void*+f32+s32 for 0047a1a0, f32* for 003e0380).
     D_005F1868 as s64[], D_005F1870 as f32[], D_007EF9B0 as u8[] per owner; indexed [0] and +i*0x750.
     Switch dispatch 1,3,10,default matches retail beq-chain (10,3,1) + default 0x337.
   TU eligibility: production untouched, retains INCLUDE_ASM, so link eligibility unchanged.
     Baseline and final both 25 MATCH / 1 ASM (k_command.c), zero non-target byte/reloc diffs.
   Retail identity: unverified (no tools/build.py mid-batch per batch bound; production bytes unchanged
     so image unchanged by construction).
*/
s32 func_001774a0(void)
{
    s32 v;
    s32 id;
    u8 *s2;
    struct { s64 lo; f32 hi; } cfg;
    s32 k;
    f32 a[3];
    f32 neg[3];
    v = func_0029cc00(0);
    id = func_0029cc00(1);
    s2 = func_001452b0(14);
    cfg.lo = D_005F1868[0];
    cfg.hi = D_005F1870[0];
    if (s2 == 0) {
        func_0046d730(D_005F1858, 0x2C3);
    }
    while (s2 != 0) {
        if ((*(u16 *)s2 & 0x3FF) == id) {
            break;
        }
        s2 = *(u8 **)(s2 + 0x138);
    }
    k = (v & 0xFFC00) >> 10;
    switch (k) {
    case 1:
    {
        u8 *p;
        u8 *q;
        f32 m[4];
        s32 i;
        s32 x;
        u8 *r;
        u8 *t;
        p = func_00145270(v & 0xFFFF);
        if (p != 0) {
            q = func_0047a2f0(*(s32 *)(p + 0x164));
            *(Vec3f *)a = *(Vec3f *)(q + 0x30);
            neg[0] = -1.0f * a[0];
            neg[1] = -1.0f * a[1];
            neg[2] = -1.0f * a[2];
            func_0047a180(*(s32 *)(p + 0x164), neg, 2);
            func_0047a1a0(*(s32 *)(p + 0x164), &cfg, *(f32 *)(s2 + 0x14C), 0);
            func_0047a180(*(s32 *)(p + 0x164), a, 2);
            q = func_0047a2f0(*(s32 *)(p + 0x164));
            *(Vec3f *)(q + 0x30) = *(Vec3f *)(s2 + 0x140);
            func_003e0380(m);
            func_003e03e0(func_0047a2f0(*(s32 *)(p + 0x164)), m);
            func_003e05d0(func_0047a2f0(*(s32 *)(p + 0x164)));
            func_00168c00(*(s32 *)(p + 0x220));
            func_0015bae0();
            for (i = 0; i < 3; i++) {
                x = 0;
                r = D_007EF9B0 + i * 0x750;
                if (*(s32 *)(r + 0x798) != 0 && *(s32 *)(r + 0x7A4) != 0) {
                    x = 1;
                }
                if (x != 0 && *(s32 *)(r + 0x900) != 0) {
                    func_0017e9b0(*(s32 *)(r + 0x900));
                }
            }
            t = func_00155280();
            if (*(s32 *)(t + 4) != 0) {
                func_0016ec90(*(s32 *)(func_00155280() + 4));
            }
        }
        break;
    }
    case 3:
    {
        u8 *p;
        u8 *q;
        f32 m[4];
        f32 z;
        f32 zz[3];
        p = func_00145270(v & 0xFFFF);
        if (p != 0) {
            q = func_0047a2f0(*(s32 *)(p + 0x164));
            *(Vec3f *)a = *(Vec3f *)(q + 0x30);
            neg[0] = -1.0f * a[0];
            neg[1] = -1.0f * a[1];
            neg[2] = -1.0f * a[2];
            func_0047a180(*(s32 *)(p + 0x164), neg, 2);
            func_0047a1a0(*(s32 *)(p + 0x164), &cfg, *(f32 *)(s2 + 0x14C), 2);
            func_0047a180(*(s32 *)(p + 0x164), a, 2);
            q = func_0047a2f0(*(s32 *)(p + 0x164));
            *(Vec3f *)(q + 0x30) = *(Vec3f *)(s2 + 0x140);
            func_003e0380(m);
            func_003e03e0(func_0047a2f0(*(s32 *)(p + 0x164)), m);
            func_003e05d0(func_0047a2f0(*(s32 *)(p + 0x164)));
            if (*(s32 *)(p + 0x22C) != 0) {
                z = func_00168770(*(s32 *)(p + 0x228));
                zz[2] = z;
                zz[1] = z;
                zz[0] = z;
                func_0047a1a0(*(s32 *)(p + 0x22C), &cfg, *(f32 *)(s2 + 0x14C), 2);
                func_0047a1e0(*(s32 *)(p + 0x22C), zz, 2);
                func_0047a180(*(s32 *)(p + 0x22C), s2 + 0x140, 2);
                func_00478e70(*(s32 *)(p + 0x22C));
            }
        }
        break;
    }
    case 10:
    {
        u8 *p;
        u8 *q;
        f32 m[4];
        p = func_00145270(v & 0xFFFF);
        if (p != 0) {
            q = func_0047a2f0(*(s32 *)(p + 0x144));
            *(Vec3f *)a = *(Vec3f *)(q + 0x30);
            neg[0] = -1.0f * a[0];
            neg[1] = -1.0f * a[1];
            neg[2] = -1.0f * a[2];
            func_0047a180(*(s32 *)(p + 0x144), neg, 2);
            func_0047a1a0(*(s32 *)(p + 0x144), &cfg, *(f32 *)(s2 + 0x14C), 0);
            func_0047a180(*(s32 *)(p + 0x144), a, 2);
            q = func_0047a2f0(*(s32 *)(p + 0x144));
            *(Vec3f *)(q + 0x30) = *(Vec3f *)(s2 + 0x140);
            func_003e0380(m);
            func_003e03e0(func_0047a2f0(*(s32 *)(p + 0x144)), m);
            func_003e05d0(func_0047a2f0(*(s32 *)(p + 0x144)));
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x337);
        break;
    }
    return 1;
}
