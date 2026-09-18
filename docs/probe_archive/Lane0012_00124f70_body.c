/* Proof record (batch workflow, first-party handoff):
 * Target: func_00124f70
 * Owner: src/promoted/code1_0012.c (// FUN_00124F70 INCLUDE_ASM retained in production)
 * Retail address/window: 0x00124F70, 3856B (0xF10, 964 instrs; .size 0xF10)
 * Compiler/profile: MWCCPS2 3.0.1 b210 -O2 -Iinclude (unit default)
 * Evidence read:
 *   - asm/nonmatchings/code1_0012/func_00124f70.s (full, 1037 lines incl .size, authoritative)
 *   - docs/ghidra_headstart/src/promoted/code1_0012.c FUN_00124f70 (full, 582 lines)
 *   - docs/ida_headstart/src/promoted/code1_0012.c sub_124F70 (full, 576 lines)
 *   - src/generated/code1_0012.c P4_UNIT_00124F70 (M2C draft, 4 args, ints-first 00124bb0 order)
 *   - src/promoted/code1_0012.c owner section around marker + provider decls (00124bb0 MATCHED, 002aaf20 titleVisual MATCHED, 0025f3f0 shdSprite MATCHED)
 *   - no prior docs/probe_archive body for 00124f70 (Lane0012Full_* only carry INCLUDE_ASM)
 * D_00887300/D_00887304 spelling (checked before inventing a form):
 *   - src/promoted/code1_0012.c func_001221a0 (MATCHED): extern s32 (*D_00887304[])(s32 arg0, void *arg1); extern void (*D_00887300[])(s32 arg0, s32 arg1); D_00887304[0](0xE,&result); base=D_00887300; base[0](...); with #pragma opt_propagation off/on around callback.
 *   - This target makes no D_00887300/D_00887304 calls (retail has zero such relocations; calls are 00124bb0 x2, 0025f3f0 x1, 002aaac0 x3, 002aaf20 x3, 003f6440 x4). No D_ table extern is introduced, avoiding the two archived bodies' failure mode in this family.
 * Initial candidate: Ghidra-direct translation with u32[8] buffers scored 922 differing words (reloc-masked, probe_variants, 988/964 instrs, frame 0x370 vs 0x360).
 * Semantic gate:
 *   - func_00124f70 ABI is (s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4): retail keeps $a0->$s0, $a1->$s5, $t0->$s4, $a3 flag->$s3; $a2 dead (third arg 0 vs 0xFF varies across callers sub_124F70(j,color,0,1,v9) and (10,255,255,64,v9) but retail never saves $a2, so declared s32 unused with (void)arg2). Callers in docs/ida_headstart 2267/2279/3222 pass 5 ints+ptr, no floats. Ghidra (int,uint,undef8,long,undef8) and IDA (int,int,i64,i64,i64) both over-type; m2c (s32,s8,s32,u32*) drops one arg. Owner had no decl; this floor adds the 5-arg decl once, neutral for rest of unit (74 MATCH unchanged).
 *   - func_00124bb0 is (s32,f32 x6,u32,u32,f32,s32,u32*) per src/promoted/code1_0012.c:1838 MATCHED. Floor uses that order verbatim (a0 from (s32)*(f32*)p5230, floats from p5234/0/5238/523C/5240/5244, a1 from stack&~0xFF|0xFF, a2 white/color, fparg6 from p5248, arg3 0x10052 / flag|0x12, ptr arg4). M2C ints-first (s32,u8,u8,s32,ptr,floats) is not used.
 *   - func_002aaf20 is (void*,f32 x5,s32,s32) ptr-first per src/promoted/code1_0012.c:2103 (00126090 local, matches retail $a0-first emission). TitleVisual defines floats-first (f32 x3,ptr,f32 x2,s32,ptr) but caller decides per 7a-bis; ptr-first reproduces retail addiu $a0,sp,0x35C first. Floor uses ptr-first with 640.0f/448.0f (0x44200000/0x43E00000), not 00126090's 640/480.
 *   - func_0025f3f0 is (f32 x3,s32,u8,s32 x4) floats-first per src/promoted/code1_0012.c:1953 and src/Kernel/mc.c:16. Floor uses (-1.0f,-1.0f,0.0f,rep>>8,0xFF,0,0,*(arg4+0x3C),0) per retail $f12=-1,$f13=-1,$f14=0.
 *   - No volatile, no asm, no intrinsics, no uninitialized locals, no UB shifts. (u8)f casts per 7a-quinquies replace Ghidra's 2.147e9 expanded form.
 * Truthful residual (v5, fnalign 964/992 instrs, 28 extra):
 *   - D_ pointer GPR coloring ($s0/$s1/$s2/$s6/$s7/$fp for 5244/5248/524C/5240/523C/5238 plus spilled 5234/5230 at 0xB0/0xA0 via sq/lq) partially closed via explicit p locals (v4 903 -> v5 900); remaining temp coloring for src/dst loops and color bytes.
 *   - Stack-address scheduling for 24B copies (sp+off ordering) closed by descending buffer declaration (first-declared highest, per micro stacktest2: a[6]/b[6]/c[6] at 0x50/0x30/0x10); v2 use-order 908 -> v3 address-ascending 904 -> v4 descending 903.
 *   - Float Madd/adda for white (255 = (255-r)*1.0+r) kept as (u8)((float)(0xFF-r)*1.0f+(float)r); folding would lose Madd.
 *   - Branch polarity for flag (beqz vs bnez) closed by if (arg3!=0){flag=0;}else{flag=0x10000;} (v2 908 -> v3 904 together with buffers).
 *   - Frame exact at 0x360 via u32[6] (24B) buffers, not [8]; [8] gave 0x370 (v1 922).
 * Decisive source levers (measured via probe_variants, reloc-masked differing words):
 *   - v1c baseline (Ghidra-direct, [6] frame fix): 921.
 *   - + D_5530/40 array (was s128 scalar gp-relative) + 002aaf20 640/448 (was 512/480,512/1216): 921 -> 908 (v2, -13).
 *   - + flag polarity flip + col order swap + buffers address-ascending: 908 -> 904 (v3, -4).
 *   - + buffers descending (first-declared highest): 904 -> 903 (v4, -1).
 *   - + explicit p5234/5230/524C/5248/5244/5240/523C/5238 locals (first two spill to 0xA0/0xB0): 903 -> 900 (v5, -3).
 * Stopped levers (all measured neutral/worse, recorded so not repeated):
 *   - opt_loop_invariants on: 921 -> 922 (+1 worse).
 *   - opt_unroll_loops off: 921 -> 921 tie.
 *   - schedule off: 921 -> 921 tie.
 *   - opt_propagation off: 921 -> 943 (+22 worse).
 *   - opt_common_subs off: 921 -> 940 (+19 worse).
 *   - b340 [8]->[6] alone: 922 -> 922 tie (frame needs all [6]).
 * Candidate emitted/window bytes: 3968B / 3856B (992/964 instrs; 112B over, no zero-tail acceptance yet).
 * Relocations: retail has D_005E5530/40/5230/5234/5238/523C/5240/5244/5248/524C plus 00124bb0/0025f3f0/002aaac0/002aaf20/003f6440; object resolves same set (reloc-masked score 900, fnalign 28 extra instrs from duplicated float/color temps).
 * Resolved prefix comparison: not exact; probe nd 900 reloc-masked differing words (verify normalized_diff large on same build; fnalign many edits from GPR/FPR coloring + scheduling).
 * Retail suffix: no tail acceptance (object longer than window).
 * Other owner functions: 74 MATCH unchanged (verify.py src/promoted/code1_0012.c 74 MATCH / 8 ASM baseline; with candidate 74 MATCH / 7 ASM / 1 MISMATCH target-only in isolation, production stays ASM so 0 MISMATCH).
 * Other owner relocations/tables: unchanged (no local tables touched).
 * Callers/declarations changed: only this floor's 5-arg decl (void,s32 x4? actually s32 x4+ptr) added once; provider TUs unchanged.
 * Hardware contract: none (no COP2/VU0, MMI, lqc2/sqc2, COP0, sync, syscall; Madd/adda are EE FPU accumulator from plain C float expr, not VU).
 * Repository verifier: python tools/verify.py src/promoted/code1_0012.c -> 74 MATCH, 8 ASM, 0 MISMATCH (production ASM).
 * Remaining caveat: production stays INCLUDE_ASM; this floor is semantically faithful but not instruction-exact due to GPR/FPR coloring + scheduling walls above. No pragmas (all free pragmas tie/worse).
 * Private artifacts: /var/tmp/cold124f70/{m2c_fresh.c,v1.c,v1c.c,v2.c,v3.c,v4.c,v5.c,pragma_*.c,baseline_verify.json}.
 */
void func_00124f70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4)
{
    extern void func_002aaf20(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, s32 arg1, s32 arg2);
    extern s32 func_0025f3f0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    extern void func_002aaac0(void);
    extern s32 func_003f6440(s32 arg0, s32 arg1);
    extern void func_00124bb0(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, u32 arg1, u32 arg2, f32 fparg6, s32 arg3, u32 *arg4);
    extern u8 D_005E5530[];
    extern u8 D_005E5540[];
    extern u8 D_005E5230[];
    extern u8 D_005E5234[];
    extern u8 D_005E5238[];
    extern u8 D_005E523C[];
    extern u8 D_005E5240[];
    extern u8 D_005E5244[];
    extern u8 D_005E5248[];
    extern u8 D_005E524C[];
    u32 b340[6];
    u32 b320[6];
    u32 b300[6];
    u32 b2E0[6];
    u32 b2C0[6];
    u32 b2A0[6];
    u32 b280[6];
    u32 b260[6];
    u32 b240[6];
    u32 b220[6];
    u32 b200[6];
    u32 b1E0[6];
    u32 b1C0[6];
    u32 b1A0[6];
    u32 b180[6];
    u32 b160[6];
    u32 b140[6];
    u32 b120[6];
    u32 b100[6];
    u32 bE0[6];
    u32 bC0[6];
    u8 colBuf[4];
    u8 col4[4];
    u8 *p;
    s32 n;
    s32 *src;
    s32 *dst;
    s32 count;
    s32 t1;
    s32 t2;
    s32 idx;
    s32 *tbl;
    s32 vidx;
    u32 word;
    s32 r;
    s32 g;
    s32 b;
    u8 c0;
    u8 c1;
    u8 c2;
    f32 f0;
    f32 f1;
    f32 f2;
    u8 *p5234;
    u8 *p5230;
    u8 *p524C;
    u8 *p5248;
    u8 *p5244;
    u8 *p5240;
    u8 *p523C;
    u8 *p5238;
    s32 flag;
    (void)arg2;
    if (arg3 != 0) {
        flag = 0;
    } else {
        flag = 0x10000;
    }
    p = col4;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    *(f32 *)colBuf = *(f32 *)col4;
    func_002aaf20(colBuf, 0.0f, 0.0f, 0.0f, 640.0f, 448.0f, 0x12, 0);
    *(s128 *)b140 = *(s128 *)D_005E5530;
    *(s64 *)(b140 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)b140;
    dst = (s32 *)b1C0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    idx = arg0 * 0x28;
    tbl = (s32 *)(D_005E524C + idx);
    p524C = D_005E524C + idx;
    p5248 = D_005E5248 + idx;
    p5244 = D_005E5244 + idx;
    p5240 = D_005E5240 + idx;
    p523C = D_005E523C + idx;
    p5238 = D_005E5238 + idx;
    p5234 = D_005E5234 + idx;
    p5230 = D_005E5230 + idx;
    vidx = *tbl * 4;
    word = *(u32 *)((u8 *)b1C0 + vidx);
    src = (s32 *)b140;
    dst = (s32 *)b1A0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    r = (word >> 0x18) & 0xFF;
    g = (word >> 0x10) & 0xFF;
    b = (word >> 8) & 0xFF;
    f0 = (f32)(u8)((f32)(0xFF - r) * 1.0f + (f32)r);
    f1 = (f32)(u8)((f32)(0xFF - g) * 1.0f + (f32)g);
    f2 = (f32)(u8)((f32)(0xFF - b) * 1.0f + (f32)b);
    {
        s32 a0 = (s32)*(f32 *)p5230;
        u32 a1 = (*(u32 *)((u8 *)b1A0 + vidx) & 0xFFFFFF00) | 0xFF;
        u32 a2 = ((u32)(u8)f2 << 8) | ((u32)(u8)f0 << 0x18) | ((u32)(u8)f1 << 0x10) | 0xFF;
        func_00124bb0(a0, *(f32 *)p5234, 0.0f, *(f32 *)p5238, *(f32 *)p523C, *(f32 *)p5240, *(f32 *)p5244, a1, a2, *(f32 *)p5248, 0x10052, (u32 *)arg4);
    }
    *(s128 *)b120 = *(s128 *)D_005E5530;
    *(s64 *)(b120 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)b120;
    dst = (s32 *)b180;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    vidx = *tbl * 4;
    word = *(u32 *)((u8 *)b180 + vidx);
    src = (s32 *)b120;
    dst = (s32 *)b160;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    r = (word >> 0x18) & 0xFF;
    g = (word >> 0x10) & 0xFF;
    b = (word >> 8) & 0xFF;
    f0 = (f32)(u8)((f32)(0xFF - r) * 1.0f + (f32)r);
    f1 = (f32)(u8)((f32)(0xFF - g) * 1.0f + (f32)g);
    f2 = (f32)(u8)((f32)(0xFF - b) * 1.0f + (f32)b);
    {
        s32 a0 = (s32)*(f32 *)p5230;
        u32 a1 = (*(u32 *)((u8 *)b160 + vidx) & 0xFFFFFF00) | 0xFF;
        u32 a2 = ((u32)(u8)f2 << 8) | ((u32)(u8)f0 << 0x18) | ((u32)(u8)f1 << 0x10) | 0xFF;
        func_00124bb0(a0, *(f32 *)p5234, 0.0f, *(f32 *)p5238, *(f32 *)p523C, *(f32 *)p5240, *(f32 *)p5244, a1, a2, *(f32 *)p5248, flag | 0x12, (u32 *)arg4);
    }
    *(s128 *)b100 = *(s128 *)D_005E5530;
    *(s64 *)(b100 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)b100;
    dst = (s32 *)b340;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    vidx = *tbl * 4;
    colBuf[0] = (u8)(*(u32 *)((u8 *)b340 + vidx) >> 0x18);
    src = (s32 *)b100;
    dst = (s32 *)b320;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[1] = (u8)(*(u32 *)((u8 *)b320 + vidx) >> 0x10);
    src = (s32 *)b100;
    dst = (s32 *)b300;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[2] = (u8)(*(u32 *)((u8 *)b300 + vidx) >> 8);
    src = (s32 *)b100;
    dst = (s32 *)b2E0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[3] = (u8)*(u32 *)((u8 *)b2E0 + vidx);
    colBuf[0] = (u8)arg1;
    colBuf[1] = (u8)arg1;
    colBuf[2] = (u8)arg1;
    func_002aaac0();
    func_003f6440(3, 0x53001);
    func_003f6440(2, 0x52);
    {
        s32 c = arg1 & 0xFF;
        s32 rep = (c << 24) | (c << 16) | (c << 8) | 0xFF;
        func_0025f3f0(-1.0f, -1.0f, 0.0f, rep >> 8, 0xFF, 0, 0, *(s32 *)(arg4 + 0x3C), 0);
    }
    *(s128 *)bE0 = *(s128 *)D_005E5530;
    *(s64 *)(bE0 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)bE0;
    dst = (s32 *)b2C0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    vidx = *tbl * 4;
    colBuf[0] = (u8)(*(u32 *)((u8 *)b2C0 + vidx) >> 0x18);
    src = (s32 *)bE0;
    dst = (s32 *)b2A0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[1] = (u8)(*(u32 *)((u8 *)b2A0 + vidx) >> 0x10);
    src = (s32 *)bE0;
    dst = (s32 *)b280;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[2] = (u8)(*(u32 *)((u8 *)b280 + vidx) >> 8);
    src = (s32 *)bE0;
    dst = (s32 *)b260;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[3] = (u8)*(u32 *)((u8 *)b260 + vidx);
    {
        f32 base = (f32)arg1 / 255.0f;
        f32 v0 = (f32)colBuf[0] * base;
        f32 v1 = (f32)colBuf[1] * base;
        f32 v2 = (f32)colBuf[2] * base;
        colBuf[0] = (u8)v0;
        colBuf[1] = (u8)v1;
        colBuf[2] = (u8)v2;
    }
    func_002aaac0();
    func_003f6440(3, 0x53001);
    func_003f6440(2, 0x58);
    func_002aaf20(colBuf, 0.0f, 0.0f, 0.0f, 640.0f, 448.0f, 0x300, 0);
    *(s128 *)bC0 = *(s128 *)D_005E5530;
    *(s64 *)(bC0 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)bC0;
    dst = (s32 *)b240;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    vidx = *tbl * 4;
    {
        u32 w0 = *(u32 *)((u8 *)b240 + vidx);
        colBuf[0] = (u8)(((w0 & 0xFFFFFF00) | (u32)(u8)arg1) >> 0x18);
    }
    src = (s32 *)bC0;
    dst = (s32 *)b220;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    {
        u32 w1 = *(u32 *)((u8 *)b220 + vidx);
        colBuf[1] = (u8)(((w1 & 0xFFFFFF00) | (u32)(u8)arg1) >> 0x10);
    }
    src = (s32 *)bC0;
    dst = (s32 *)b200;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    {
        u32 w2 = *(u32 *)((u8 *)b200 + vidx);
        colBuf[2] = (u8)(((w2 & 0xFFFFFF00) | (u32)(u8)arg1) >> 8);
    }
    src = (s32 *)bC0;
    dst = (s32 *)b1E0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    {
        u32 w3 = *(u32 *)((u8 *)b1E0 + vidx);
        colBuf[3] = (u8)((w3 & 0xFFFFFF00) | (u32)(u8)arg1);
    }
    func_002aaac0();
    func_002aaf20(colBuf, 0.0f, 0.0f, 1.0f, 640.0f, 448.0f, 1, 0);
}
