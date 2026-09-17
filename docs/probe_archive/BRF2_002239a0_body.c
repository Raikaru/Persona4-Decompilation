/* Proof record (batch workflow, first-party handoff):
 * Target: func_002239a0
 * Owner: src/promoted/btlResultFriendPsLvUp.c (// FUN_002239A0 INCLUDE_ASM retained)
 * Retail address/window: 0x002239A0, 1328B (0x530, 332 instrs)
 * Compiler/profile: MWCCPS2 3.0.1 b210 -O2 -Iinclude (unit default; not in compiler_units, not in speed_units)
 * Evidence read:
 *   - asm/nonmatchings/btlResultFriendPsLvUp/func_002239a0.s (full, 357 lines, authoritative)
 *   - docs/ghidra_headstart/src/promoted/btlResultFriendPsLvUp.c FUN_002239a0 (full)
 *   - docs/ida_headstart/src/promoted/btlResultFriendPsLvUp.c sub_2239A0 (full)
 *   - src/generated/code1_0022.c P4_UNIT_002239A0 (189-line block, 156-line func, 37 M2C lines)
 *   - docs/probe_archive/BRF_002239a0_body.c (full, 146 lines, 277 words, +60B overrun)
 *   - src/promoted/btlResultFriendPsLvUp.c owner section around marker + provider decls
 *   - src/Battle/btlResultHeroLvUp.c sibling func_00221f40 (MATCH, BtlResultWork idiom, switch 0-6)
 *   - tools/jtbl.py 0x007477B0 8 (cases 0:3A18, 1:3AB4, 2:3DCC, 3:3DD4, 4:3E00, 5:3E70, 6:3E88, 7:3EA0)
 * Initial candidate: BRF fixed for switch/array/float (250 words, 0x90 frame).
 *   v2 with base live + zw[2] + idx kept: 250 -> 186 with 0xA0 frame (exact size).
 *   v7 with s32 stmp (no shifts for first add): 191 -> 179 (v5 191 with D_ array fix).
 * Semantic gate:
 *   - func_00452560 provider is u32 func_00452560(void* task) (src/Kernel/sdkTask.c:986,
 *     MATCHED). Owner declared (void), omitting incoming $a0 (still in $a0 at jal).
 *     Corrected owner line 8 to (s32 arg0); sibling uses (u32). No other function in
 *     this owner calls it, so owner isolation holds (1 MATCH before and after).
 *   - D_008C024C/E provider is u16 array (sibling extern u16 D_008C024C[]). Owner
 *     declared scalar u16, forcing GP-relative lhu ($gp) vs retail absolute lui+lhu.
 *     Corrected owner lines 32-33 to u16 []; fnalign now reloc-only for both.
 *   - func_0011f410 provider is u8* (src/promoted/shdPersona.c:3257, MATCHED).
 *     Owner declares s32 return; same width ($v0), no codegen change, kept as is.
 *   - func_00455ea0 provider is u8* (sibling u8*). Owner declares s32 first param;
 *     same width, kept. No prototype change.
 *   - func_002238f0 defined in same owner as s32 (s64); final id via lh (s16)
 *     already sign-extends to 64-bit, no extra shifts (matches retail addiu $s0).
 *   - q (s4) only used when *(r+56) != 4 (success path via bgtz); early id==0
 *     exits go to increment, ==4 path never touches q. No UB on uninitialized use.
 * Truthful residual (v7_padded, fndiff 179 reloc-masked, fnalign 134/134 +12 reloc-only):
 *   - dominant s2/s3 register-colour permutation (retail r in s3/base in s2 vs
 *     object r in s2/base in s1/idx in s3): ~12 lw/sw/addu instances plus level
 *     copy and slt sources. Declaration-order perms (r/e swap, q-first, base-first,
 *     v-first) all neutral at 179.
 *   - scheduling: sh-then-andi (retail) vs andi-then-sh (object) for r+64 counter;
 *     lw-order for q+8 vs base+0x6A4 (neutral on swap); addu operand orientation.
 *   - single missing float store: retail zw[2] at 0x98/0x9C (0/0x41980000 = 19.0f);
 *     object keeps only zw[0] at 0x8C (zw[1] dead-store eliminated). Frame still
 *     exact 0xA0 via array sizes.
 *   - sound temporaries: s32 stmp (no shifts) matches first addiu $s0; s16 u keeps
 *     dsll32/dsra32 for sum (one extra insert at 243 remains).
 * Decisive source levers (measured via probe_variants, reloc-masked nd):
 *   - switch-8 with 0->1, 2->3->4, 5->6 fallthroughs vs BRF if/else: 277 -> 250.
 *   - base as function-scope live + zw[2] (0/0x41980000) + idx kept in s3: 250 -> 186.
 *   - D_008C scalar->array: GP-relative wall -> reloc-only (fnalign replace->reloc-only).
 *   - s32 stmp for 2238f0+125 (no shifts): 191 -> 179.
 *   - sp[11] with three trailing -1 (0x60-0x88); 10-word variant gives 0x90 frame.
 * Stopped levers (all measured neutral/worse, recorded so not repeated):
 *   - decl-order perms v10 (q-first) / v11 (base-first) / v12 (v-first): all 179.
 *   - r/e swap (v4): 186 -> 186 neutral.
 *   - add-order swap for q+8 (v6): 191 -> 191 neutral.
 *   - 113-first vs 112-first for sid (v8): 179 -> 180 (+1, kept 112-first for nd).
 *   - idx removal (v3, direct *(r+56) after call): 186 -> 248 worse (keep idx).
 *   - reload-after-call for q+8/base (v9): 179 -> 242 worse.
 *   - hoist/loop-invariant, schedule/propagation pragmas not tried: pure C floor,
 *     no pragma needed; no volatile/inline-asm/UB (lint 0).
 * Candidate emitted/window bytes: 1328B / 1328B (332/332 instrs, exact size).
 * Relocations: 46, all resolved (HI16/LO16 jtbl_007477B0 @107 x2 with 0x74/0x77B0 +
 *   D_00795F20/D_005E4810/D_00629720 x3 + D_008C024E/C x2, plus 20+ R_MIPS_26 calls:
 *   452560, 460ac0, 452380, 117780, 46d730, 11d100, 11bb90, 117580, 10a900,
 *   106330 x2, 106390 x2, 11b480, 455ea0 x2, 11f410, 231d70 x2, 1f86d0, 1f9a50,
 *   2238f0, 1f9a90, 1f8690, 2bb4e0, 11f560, 11f580, 21de60). No unresolved.
 * Resolved prefix comparison: not exact; 179 reloc-masked differing words at
 *   fndiff offsets (first_diffs 41,66,78,84,122,142,182,226,242,254,274,278,280,290,294,300).
 * Retail suffix: none (exact 1328B size, no zero tail needed).
 * Other owner functions: 1 MATCH (func_002238f0, 168B/176B with 8B zero tail) unchanged.
 * Other owner relocations/tables: unchanged (no local tables touched; jtbl is
 *   compiler-generated per-function rodata, verified via @107 HI16/LO16).
 * Callers/declarations changed: only owner lines 8 (452560 void->s32) and 32-33
 *   (D_008C scalar->array) to match providers/sibling.
 * Caller-owner isolation: provider TUs unchanged; sibling btlResultHeroLvUp still
 *   MATCH; no other TU calls through these headers (each TU has own decl).
 * Hardware contract: none (no COP2/VU0, MMI, lqc2/sqc2, COP0, sync, syscall).
 * Repository verifier: python tools/verify.py src/promoted/btlResultFriendPsLvUp.c
 *   -> 1 MATCH, 1 ASM (production); installed candidate -> 1 MATCH, 1 MISMATCH (179).
 *   python tools/fndiff.py -> 1328B/1328B, 179 words. python tools/fnalign.py
 *   -> 134 edits +12 reloc-only. python tools/decomp_lint.py --errors-only -> 0.
 * Remaining caveat: production stays INCLUDE_ASM; this floor is semantically faithful
 *   (158 body lines, 0 code noise) but not instruction-exact due to register-colour
 *   + scheduling wall.
 * Private artifacts: local/BRF2/{v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v7_padded,
 *   owner_backup}.c plus build/BRF2_scope.json (MISMATCH 179) and build/FINAL_scope.json.
 */
s32 func_002239a0(s32 arg0)
{
    // Retail frame 0xA0 (160B); zw[2] + sp[11] give 52B locals + saves = 0xA0.
    // Register map: r in s3, base in s2, e/k in s1, q in s4, arg0 in s0.
    // Switch gives 8-entry jtbl_007477B0 (0-7); 0->1, 2->3->4, 5->6 fallthroughs.
    // base = e + 96 kept live across case 1 for 0x69A/0x6A4/0x6B4/0x6B6 forms.
    // idx in s3 across 10a900 call; reload-after-call variant measured worse (179->242).
    // sp[11] with three trailing -1 (0x60-0x88); 10-word variant shortens frame to 0x90.
    // zw[1] = 0x41980000 (19.0f); single-store residual is dead-store elimination.
    // stmp as s32 (no shifts) vs s16 (shifts); s32 saves 12 words (191->179).
    // D_008C as [0] array (sibling idiom); scalar gives GP-relative wall (now reloc-only).
    // 452560(s32) matches sdkTask.c provider; void omits incoming $a0 (semantic gate).
    // q only used when idx != 4 (success path), so no UB on early id==0 exit.
    // Final id via lh (s16) for 2238f0 s64; earlier ids via lhu (u16).
    // Case 4: retail sh-then-andi vs object andi-then-sh scheduling wall.
    u8 *r;
    u8 *e;
    u8 *base;
    u32 st;
    u8 *q;
    s32 v;
    s32 k;
    u16 id;
    s32 sp[11];
    s32 zw[2];

    r = func_00452560(arg0);
    e = *(u8 **)(r + 60);
    *(s32 *)(r + 8) = 0;
    *(s32 *)(r + 12) = 0;
    func_00460ac0(D_00795F20, r + 8);
    st = *(u32 *)(r + 4);
    switch (st) {
    case 0:
        *(s32 *)(r + 56) = 0;
        v = func_00452380(D_005E4810);
        *(s32 *)(r + 68) = v;
        if (v == 0) {
            v = func_00117780(0, 15, 4, 5, 0);
            *(s32 *)(r + 68) = v;
            if (v == 0) {
                func_0046d730(D_00629720, 116);
            }
            zw[0] = 0;
            zw[1] = 0x41980000;
            func_0011d100(*(s32 *)(r + 68), zw);
            func_0011bb90(*(s32 *)(r + 68));
        }
        func_00117580(*(s32 *)(r + 68), 174);
        *(u32 *)(r + 4) = 2;
        /* fallthrough */
    case 1:
        base = e + 96;
        while (*(s32 *)(r + 56) < 4) {
            s32 idx = *(s32 *)(r + 56);
            id = *(u16 *)(base + idx * 2 + 0x69A);
            if (id == 0) {
                *(s32 *)(r + 56) = idx + 1;
                continue;
            }
            q = func_0010a900(id);
            *(s32 *)(q + 8) = *(s32 *)(base + idx * 4 + 0x6A4) + *(s32 *)(q + 8);
            if ((s32)*(u8 *)(base + idx * 136 + 0x6B4) <= 0) {
                *(s32 *)(r + 56) = idx + 1;
                continue;
            }
            break;
        }
        if (*(s32 *)(r + 56) != 4) {
            k = 0;
            while (k < 32) {
                u16 sid = *(u16 *)(base + *(s32 *)(r + 56) * 136 + k * 2 + 0x6B6);
                if (sid == 0) {
                    break;
                }
                if (sid == 0x112) {
                    if (func_00106330(0x1012) != 0) {
                        func_0046d730(D_00629720, 158);
                    }
                    func_00106390(0x1012, 1);
                } else if (sid == 0x113) {
                    if (func_00106330(0x1013) != 0) {
                        func_0046d730(D_00629720, 163);
                    }
                    func_00106390(0x1013, 1);
                }
                k++;
            }
            func_0011b480(*(s32 *)(r + 68), *(u16 *)(base + *(s32 *)(r + 56) * 2 + 0x69A), q, 0);
            sp[0] = 27;
            sp[1] = 25;
            sp[2] = 6;
            sp[3] = 9;
            sp[4] = 10;
            sp[5] = 26;
            sp[6] = 13;
            sp[7] = 14;
            sp[8] = -1;
            sp[9] = -1;
            sp[10] = -1;
            {
                s32 a = func_00455ea0(*(s32 *)(*(u8 **)(r + 60) + 2356), 0, 0);
                s32 b = func_00455ea0(*(s32 *)(*(u8 **)(r + 60) + 2356), 1, 0);
                *(s32 *)(r + 72) = func_0011f410(arg0, *(s32 *)(r + 68), base + *(s32 *)(r + 56) * 136 + 0x6B4, a, b, sp);
            }
            if (*(s16 *)(base + *(s32 *)(r + 56) * 2 + 0x69A) == 5) {
                s16 t = (s16)(func_00231d70(3) + 468);
                func_001f86d0();
                func_001f9a50((u16)t, 3);
            } else {
                s32 stmp = func_002238f0(*(s16 *)(base + *(s32 *)(r + 56) * 2 + 0x69A)) + 125;
                s16 u = (s16)(stmp + (s16)func_00231d70(3));
                func_001f9a90();
                func_001f8690((u16)u);
            }
            *(u16 *)r = *(u16 *)r | 2;
            *(u32 *)(r + 4) = 2;
        } else {
            *(u16 *)r = *(u16 *)r & 0xFFFE;
            *(u32 *)(r + 4) = 7;
            func_002bb4e0();
        }
        break;
    case 2:
        *(u32 *)(r + 4) = 3;
        /* fallthrough */
    case 3:
        if (func_0011f560(*(s32 *)(r + 72)) != 0) {
            func_0011f580(*(s32 *)(r + 72));
            *(u32 *)(r + 4) = 4;
            *(u16 *)(r + 64) = 0;
        }
        /* fallthrough */
    case 4:
        {
            u16 t = *(u16 *)(r + 64) + 1;
            *(u16 *)(r + 64) = t;
            if ((t >= 45) || ((D_008C024E[0] & 0x50) != 0) || (((D_008C024C[0] & 0x10) != 0) && (*(u16 *)(r + 64) >= 4))) {
                *(u32 *)(r + 4) = 1;
                *(s32 *)(r + 56) = *(s32 *)(r + 56) + 1;
            }
        }
        break;
    case 5:
        if (func_0021de60() != 0) {
            *(u32 *)(r + 4) = 6;
            /* fallthrough */
        case 6:
            *(u16 *)r = *(u16 *)r & 0xFFFD;
            return -1;
        }
        break;
    case 7:
    default:
        break;
    }
    return 0;
}
