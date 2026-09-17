/* Proof record (batch workflow, first-party handoff):
 * Target: func_00122a40
 * Owner: src/promoted/code1_0012.c (// FUN_00122A40 INCLUDE_ASM retained)
 * Retail address/window: 0x00122A40, 3232B (0xCA0, 808 instrs; .size 0xCA0)
 * Compiler/profile: MWCCPS2 3.0.1 b210 -O2 -Iinclude (unit default; not in speed_units, not in compiler_units)
 * Evidence read:
 *   - asm/nonmatchings/code1_0012/func_00122a40.s (full, 846 lines incl .size, authoritative)
 *   - docs/ghidra_headstart/src/promoted/code1_0012.c FUN_00122a40 (full)
 *   - docs/ida_headstart/src/promoted/code1_0012.c sub_122A40 (full)
 *   - src/generated/code1_0012.c P4_UNIT_00122A40 (183 body lines, M2C direct-call draft)
 *   - src/promoted/code1_0012.c owner section around marker + provider decls
 *   - no prior docs/probe_archive body for 00122a40 (Lane0012Full_* only carry INCLUDE_ASM)
 * D_00887300/D_00887304 spelling (checked before inventing a form):
 *   - src/promoted/code1_0012.c func_001221a0 (MATCHED, lines 528-538):
 *       extern s32 (*D_00887304[])(s32 arg0, void *arg1);
 *       extern void (*D_00887300[])(s32 arg0, s32 arg1);
 *       D_00887304[0](0xE, &result); base = D_00887300; base[0](...);
 *     with #pragma opt_propagation off/on around the callback (lines 514/588).
 *   - src/promoted/code1_0012.c line 1588 + 1668 (MATCHED func_00125e80):
 *       extern void (*D_00887300[])(s32 arg0, s32 arg1); D_00887300[0](6, 1);
 *   - This floor copies the 001221a0 form verbatim (local externs + hoisted base),
 *     not the M2C direct-call D_00887300(...)/D_00887304(...) spelling.
 * Initial candidate: M2C draft with direct calls scores far; truthful v1 (indexed
 *   base + truthful 0046d3b0/0046d4c0 order from src/Kernel/sdkSpr.c + code1_0011.c)
 *   scored 710 differing words (reloc-masked, probe_variants).
 * Semantic gate:
 *   - func_00122a40 ABI is (void *arg0, u8 *arg1): retail keeps incoming $a1 ($5)
 *     in $s2 ($18) and never reads $a0 ($4); callback slot at p+8 is stored via
 *     (void *) cast (src/promoted/code1_0012.c:747) so no caller code changes.
 *     Owner line 56 corrected from old-style (void) to (void *, u8 *);
 *     verify.py still 74 MATCH / 8 ASM before and after (neutral).
 *   - func_0046d3b0 is (s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2,
 *     u8 arg3, f32 z, s32 arg4) (src/Kernel/sdkSpr.c:359 MATCHED; code1_0011.c:60).
 *     M2C order (parent, arg0, arg1, 0, alpha, 1, x, y, 0) is wrong; floor uses
 *     (0, res, id, x, y, 0, alpha, 0.0f, 1) per retail $4-$9/$f12-$f14.
 *   - func_0046d4c0 is (parent, arg0, arg1, x, y, arg2-arg5, z, arg6)
 *     (sdkSpr.c:378; code1_0011.c:60). Floor uses (node, res, id, x, y, alpha,
 *     0x19 x3 / colors, 0.0f, 1) per retail regs, not M2C int-then-float order.
 *   - func_001104d0 (s32, s32*, s32*) (code1_0011.c:125), func_00110580 (s32)->s32
 *     (code1_0011.c:163), func_00110d30 (s32)->s32 (code1_0011.c:456) replace the
 *     owner old-style extern s32 func_00110d30(); via local truthful externs.
 *   - func_0046b2f0 (u8*)->f32 (sdkSpr.c:287), func_0046b380 (u8*, s32)
 *     (sdkSpr.c:16), func_0046d200 (u32,u32)->u8* + func_0046d280 (void*)
 *     already truthful in owner; 003f6440 (s32,s32) via local extern.
 *   - No volatile, no asm, no intrinsics, no uninitialized locals, no UB shifts.
 * Truthful residual (v8, fnalign 804/804 instrs, 97 edits + 4 reloc-only):
 *   - systematic int->float + float FPR-color swap at nested 14.0f+(int+field)
 *     sites; simple 574/547 sites fixed via distinct ft1/ft2 temps (v5 336 -> v8 324).
 *   - GPR-temp coloring for (0xFF-*(u8*))&0xFF alpha (retail $v1/$t0 vs $a0/$v1).
 *   - within-call 0x19/0xFF sharing (retail move vs addiu) lost under the
 *     float-hoist fix; explicit c19 sharing regressed (+14), kept as-is.
 *   - q-remap branch polarity (retail beq vs bne) inert to rebuildconditionals.
 *   - tail (int)(half+ret/2) FPR shape + 1 trailing nop alignment.
 * Decisive source levers (measured via probe_variants, reloc-masked differing words):
 *   - v1 truthful indexed base + truthful call order: 710.
 *   - + pragma opt_propagation off (as in 001221a0): 710 -> 702 (v2).
 *   - + pragma opt_common_subs off (kills 17.0f/14.0f hoist into $f20/$f21,
 *     frame 0x80 -> 0x70): 702 -> 336 (v5; v3/v4 call-first ordering neutral at 692).
 *   - + distinct ft1/ft2 temps for (f32)0x23E+field0x30 and (f32)0x223+field0x60:
 *     336 -> 324 (v8). Single reused ftmp regressed (602); 11-temp all-sites 596.
 * Stopped levers (all measured neutral/worse, recorded so not repeated):
 *   - swap (int+field) to (field+int) (v6a): 336 -> 336 neutral.
 *   - single ftmp for first site (v6b): 336 -> 330 (-6) kept as ft1/ft2 only.
 *   - inner-sum temp ft3=(f32)463+field then 14+ft3 (v17): 324 -> 329 worse.
 *   - nested inner/outer order swaps for 463 (v12/v13): 324 neutral.
 *   - rebuildconditionals off (v14): 324 neutral.
 *   - ratio split into ratio1/ratio2 (v15): 324 neutral.
 *   - declaration reorder to base-last (v16): 324 neutral.
 *   - c19 sharing for 0x19 triplets (v18): 324 -> 338 worse (extra lw).
 *   - ft3/ft4 for 463/513 nested sites (v10/v11): 324 -> 327 worse.
 * Candidate emitted/window bytes: 3216B / 3232B (804/804 instrs; 16B retail zero
 *   tail after emitted prefix: jr delay nop + 3 alignment nops at 0x236D0-0x236DC).
 * Relocations: 46, all resolved to retail targets/addends, 0 unresolved
 *   (HI16/LO16 D_00887304 + D_00887300; R_MIPS_26 003f6440 x2, 001437b0,
 *   0046d3b0 x7, 0046d200 x5, 0015a160 x2, 0028b650 x2, 0046b380 x2, 0046d280 x2,
 *   001104d0, 00110d30 x2, 00110580 x4, 0046b2f0 x2).
 * Resolved prefix comparison: not exact; probe nd 324 reloc-masked differing words
 *   (verify normalized_diff 1021B on same build; fnalign 97 edits + 4 reloc-only).
 * Retail suffix: 16B zero tail only after 3216B prefix; accepted tail only.
 * Other owner functions: 74 MATCH unchanged (verify.py src/promoted/code1_0012.c
 *   74 MATCH / 8 ASM baseline; local/scratch_v8.c with candidate 74 MATCH / 7 ASM /
 *   1 MISMATCH target-only, no translation-unit regressions).
 * Other owner relocations/tables: unchanged (no local tables touched).
 * Callers/declarations changed: only owner line 56 (void) -> (void *, u8 *);
 *   single callback store via (void *) cast needs no code change; provider TUs unchanged.
 * Hardware contract: none (no COP2/VU0, MMI, lqc2/sqc2, COP0, sync, syscall).
 * Repository verifier: python tools/verify.py src/promoted/code1_0012.c -> 74 MATCH, 8 ASM.
 * Remaining caveat: production stays INCLUDE_ASM; this floor is semantically faithful
 *   but not instruction-exact due to FPR-color/scheduling + temp-color walls above.
 *   Required owner pragmas for this score (included below with the body):
 *     #pragma opt_propagation off + #pragma opt_common_subs off around the body.
 * Private artifacts: source/Persona4-Decompilation/local/cand_v*.c (v1,v2,v5,v8 best,
 *   v3,v4,v6a,v6b,v7,v9-v18 levers), scratch_v5/v8 objects + dumps,
 *   verify_v8.json (74/7/1 isolation).
 */
/* measured: opt_propagation off preserves the single hoisted D_00887300 base, as in func_001221a0. */
#pragma opt_propagation off
#pragma opt_common_subs off
void func_00122a40(void *arg0, u8 *arg1)
{
    extern s32 (*D_00887304[])(s32 arg0, void *arg1);
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3, f32 z, s32 arg4);
    extern f32 func_0046b2f0(u8 *arg0);
    extern void func_0046b380(u8 *arg0, s32 arg1);
    extern void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2);
    extern s32 func_00110580(s32 arg0);
    extern s32 func_00110d30(s32 arg0);
    extern s32 func_003f6440(s32 arg0, s32 arg1);
    void (**base)(s32 arg0, s32 arg1);
    u8 *node;
    u8 *obj;
    s32 tmp;
    s32 ratio;
    s32 result;
    s32 v;
    s32 w;
    s32 v2;
    s32 i;
    s32 sp68;
    s32 sp64;
    s32 ival;
    s32 q;
    f32 ft1;
    f32 ft2;
    f32 ft3;
    f32 ft4;
    obj = arg1;
    node = (u8 *)0;
    D_00887304[0](0xE, &result);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](7, 2);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](0xB, 6);
    base[0](0xA, 5);
    base[0](2, 4);
    base[0](0xE, 0);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    if ((*(s32 *)(obj + 0xC) & 1) != 0) {
        if (*(s32 *)(obj + 0x14) != 0) {
            tmp = *(s32 *)(obj + 0x10);
            if (tmp < 0x64) {
                *(s32 *)(obj + 0x10) = tmp + 1;
            }
        } else {
            tmp = *(s32 *)(obj + 0x10);
            if (tmp != 0) {
                *(s32 *)(obj + 0x10) = tmp - 1;
            }
            if (*(s32 *)(obj + 0x10) == 0) {
                *(s32 *)(obj + 0xC) = 0;
            }
        }
        for (i = 0; i < 5; i++) {
            func_001437b0(obj + i * 0x30 + 0x20, *(s32 *)(obj + 0x10), 0);
        }
        v = *(s32 *)(obj + 0x78);
        tmp = *(s32 *)(obj + 0x10);
        if (tmp < v) {
            w = 0;
        } else {
            w = tmp - v;
        }
        v2 = *(s32 *)(obj + 0x7C) - v;
        if (v2 < w) {
            w = v2;
        }
        ratio = (w * 0x90) / v2;
        ft1 = (f32)0x23E;
        func_0046d3b0(0, *(s32 *)(obj + 0x110), 0x25, ft1 + *(f32 *)(obj + 0x30), *(f32 *)(obj + 0x34), 0, (0xFF - *(u8 *)(obj + 0x3A)) & 0xFF, 0.0f, 1);
        if (*(s32 *)(obj + 0x18) != 0) {
            if (*(s32 *)(obj + 0x1C) == 0) {
                node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), 0x1D);
            } else {
                node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), 0x1E);
            }
        } else if ((func_0015a160() == 0) && (func_0028b650() == 0)) {
            node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), 0x1D);
        } else {
            node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), 0x1E);
        }
        *(s32 *)(node + 0x24) = 0;
        ft2 = (f32)0x223;
        *(f32 *)(node + 8) = ft2 + *(f32 *)(obj + 0x60);
        *(f32 *)(node + 0xC) = -33.0f + *(f32 *)(obj + 0x64);
        *(s8 *)(node + 0x10) = (s8)(0xFF - *(u8 *)(obj + 0x6A));
        *(s16 *)(node + 0x1C) = 0x50;
        *(s16 *)(node + 0x1E) = 0x2D;
        *(f32 *)(node + 0x18) = (f32)(0x90 - ratio);
        func_0046b380(node, 1);
        func_0046d280(node);
    }
    if ((*(s32 *)(obj + 0xC) & 2) != 0) {
        func_001104d0(*(s16 *)(obj + 4), &sp68, &sp64);
        tmp = (s32)*(f32 *)(obj + 0x90);
        func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), 7, (f32)(tmp + 0x1C2), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0x19, 0x19, 0x19, 0.0f, 1);
        func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), 8, (f32)(tmp + 0x246), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0x19, 0x19, 0x19, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), sp68 / 10 + 9, 14.0f + ((f32)0x1CF + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), sp68 % 10 + 9, 14.0f + (476.0f + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), 0x13, 14.0f + (490.0f + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), sp64 / 10 + 9, 14.0f + (500.0f + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), sp64 % 10 + 9, 14.0f + ((f32)0x201 + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        if (func_00110d30(*(s16 *)(obj + 4)) != 0) {
            func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), func_00110580(*(s16 *)(obj + 4)), (f32)0x219 + *(f32 *)(obj + 0x90), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0xFF, 0xAC, 0x99, 0.0f, 1);
        } else if (func_00110580(*(s16 *)(obj + 4)) == 6) {
            func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), func_00110580(*(s16 *)(obj + 4)), (f32)0x219 + *(f32 *)(obj + 0x90), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0x99, 0xA4, 0xFF, 0.0f, 1);
        } else {
            func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), func_00110580(*(s16 *)(obj + 4)), (f32)0x219 + *(f32 *)(obj + 0x90), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0xFF, 0xFF, 0xFF, 0.0f, 1);
        }
        v = *(s32 *)(obj + 0xD8);
        tmp = *(s32 *)(obj + 0x10);
        if (tmp < v) {
            w = 0;
        } else {
            w = tmp - v;
        }
        v2 = *(s32 *)(obj + 0xDC) - v;
        if (v2 < w) {
            w = v2;
        }
        ratio = (w << 0xC) / v2;
        if (func_00110d30(*(s16 *)(obj + 4)) != 0) {
            tmp = *(s16 *)(obj + 6);
            if (tmp == 3) {
                q = 0x1A;
            } else {
                q = tmp + 0x14;
            }
        } else {
            q = *(s16 *)(obj + 6) + 0x14;
        }
        if (*(s32 *)(obj + 0x18) != 0) {
            if (*(s32 *)(obj + 0x1C) == 1) {
                if (q == 0x1A) {
                    q = 0x1C;
                } else if (q == 0x18) {
                    q = 0x1B;
                }
            }
        } else if ((func_0015a160() != 0) || (func_0028b650() != 0)) {
            if (q == 0x1A) {
                q = 0x1C;
            } else if (q == 0x18) {
                q = 0x1B;
            }
        }
        node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), q);
        *(s32 *)(node + 0x24) = 0;
        *(f32 *)(node + 8) = 552.0f + *(f32 *)(obj + 0xC0);
        *(f32 *)(node + 0xC) = 31.0f + *(f32 *)(obj + 0xC4);
        *(s8 *)(node + 0x10) = (s8)(0xFF - *(u8 *)(obj + 0xCA));
        ival = (s32)func_0046b2f0(node);
        *(s16 *)(node + 0x20) = 0xFF6;
        *(s16 *)(node + 0x22) = (s16)ratio;
        *(f32 *)(node + 0xC) = (f32)ival + ((31.0f + *(f32 *)(obj + 0xC4)) - (f32)(s32)(func_0046b2f0(node) / 2.0f + (f32)(ival / 2)));
        func_0046b380(node, 1);
        func_0046d280(node);
    }
    if ((*(s32 *)(obj + 0xC) & 4) != 0) {
        if (*(s32 *)(obj + 0x18) != 0) {
            if (*(s32 *)(obj + 0x1C) == 0) {
                func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), 0x1F, (f32)0x247 + *(f32 *)(obj + 0xF0), 51.0f + *(f32 *)(obj + 0xF4), 0, (0xFF - *(u8 *)(obj + 0xFA)) & 0xFF, 0.0f, 1);
                func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), *(s16 *)(obj + 8) + 0x20, (f32)0x247 + *(f32 *)(obj + 0xF0), 51.0f + *(f32 *)(obj + 0xF4), 0, (0xFF - *(u8 *)(obj + 0xFA)) & 0xFF, 0.0f, 1);
            }
        } else if ((func_0015a160() == 0) && (func_0028b650() == 0)) {
            func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), 0x1F, (f32)0x247 + *(f32 *)(obj + 0xF0), 51.0f + *(f32 *)(obj + 0xF4), 0, (0xFF - *(u8 *)(obj + 0xFA)) & 0xFF, 0.0f, 1);
            func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), *(s16 *)(obj + 8) + 0x20, (f32)0x247 + *(f32 *)(obj + 0xF0), 51.0f + *(f32 *)(obj + 0xF4), 0, (0xFF - *(u8 *)(obj + 0xFA)) & 0xFF, 0.0f, 1);
        }
    }
    base[0](0xE, result);
}
/* measured: closes the opt_propagation bracket. */
#pragma opt_common_subs on
#pragma opt_propagation on
