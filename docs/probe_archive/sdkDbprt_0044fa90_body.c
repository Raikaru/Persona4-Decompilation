/* Target: func_0044fa90
 * Owner: src/sdkDbprt.c
 * Retail address/window: 0x0044FA90, 1472B (0x5C0)
 * Compiler/profile: MWCCPS2 3.0.1 b210 -O2 -Iinclude (unit default; NOT -O2,p; NOT gcc)
 * Evidence read:
 *   asm/nonmatchings/sdkDbprt/func_0044fa90.s (405 lines, full)
 *   docs/ghidra_headstart/src/sdkDbprt.c FUN_0044fa90 (scale!=0 -> func_00450490(f12), scale==0 z=D_008872F8-*(0x110) else z=f20, 0x100 text loop, 12x11 quad + 0.0625/0.046875 UV, 4x0x40 packet + D_00887310(4,buf,4))
 *   docs/ida_headstart/src/sdkDbprt.c sub_44FA90 (node $s1, idx $s0, f21=1/w, f20=scaled, same two scale paths)
 *   src/generated/code1_0044.c P4_UNIT_0044FA90 (252-line M2C draft; duplicated scale arms, explicit low-nibble dead branch, explicit u8->float fixup expansion)
 *   src/sdkDbprt.c current section (minimal HDbText3D{next}, iGpffffb9dc/b9e0/b9e8, D_008873F4 helpers; NO file-scope D_00887300/10/D_008872F8/func_00450490)
 * Initial candidate: M2C draft verbatim intent (byte arithmetic, single-expr x0=base+12*idx, u8->float via plain (f32), low via &0xF without signed Highlands handling).
 *   Measured via probe_variants scratch splice: 393 differing words (reloc-masked), obj 1472B/window 1472B class, frame 0x170 vs retail 0x160, extra $s2 saved, madd fusion, sltiu vs slti, sra vs srl, bltz missing on colors.
 * Semantic gate: void(void) ABI (no incoming args Africa); helper func_00450490 takes f32 in $f12 (retail passes $f12 already, no move needed; declared extern f32 func_00450490(f32)); D_00887300 second arg is raster pointer value iGpffffb9e8 passed as u32 (extern void(*[])(u32,u32), call (1,(u32)iGpffffb9e8)); D_00887310 is (s32,void*,s32) with (4,quads,4); D_008872F8 is f32[ ] with [0]; colors are u8 0-255 to float via compiler idiom (f32)(u32) (NOT hand-written srl/or/add.s); low-nibble dead branch (tmp<0 && low!=0 -> low-=0x10) is retained verbatim to reproduce retail bgez/beqz/addiu (dead at runtime since tmp 0-255, but required for branch layout; NOT simplified away per 7f-defensive-C rule in reverse: retail keeps dead branch, source keeps it); text break on 0 and skip on 0x20 preserved; duplicated scale arms preserved as duplicated tails (shared epilogue would collapse per-arm stores, per 7-duplicated-tails).
 * Truthful residual (v8, measured 2026-09-16): fnalign edit instructions 146 (+5 reloc-only); retail 367 instrs vs object 366 instrs; frame 0x160 MATCHES (extra $s0 eliminated via mixed forms, see levers); stack bases quads sp+0x40 and uv sp+0x140 MATCH (uv-then-quads declaration order to satisfy reverse allocation); remaining is register-color permutation + scheduling + commutative orientation only:
 *   - int v in $v1 vs retail $a0 (andi/slti/addiu/andi chain), low in $a0 vs $v1 (andi/bgez/beqz/addiu/mtc1), j in $a2 vs $a1 (sll/addu/addiu/slti/bnez), quad base in $a1 vs $a0 (swc1 0x20/0x24/0x28/0x2C/0x18/0x10/0x14 displacements same, base reg differs)
 *   - float positions in $f7/$f6/$f5/$f4 vs $f3/$f2/$f1/$f0 (add.s/mul.s/cvt.s.w same opcodes, FPR colors differ; add.s $f7,$f1,$f0 vs $f3,$f0,$f1 operand orientation swapped for x0= t+base vs base+t; x1/y1 adds similarly swapped)
 *   - branch displacements shifted by scheduling (beqz/bne/bc1f targets +-1..2 words, same polarity)
 *   No instruction deficit/surplus beyond 1-word count (366 vs 367, single nop alignment); no stack-slot mismatch (0x160 frame, 0x40/0x140 bases); no relocation mismatch (see below).
 * Decisive source levers (each isolated by micro-experiment + probe):
 *   - byte->float colors as (f32)(u32)r/g/b/a (micro: unsigned -> bltz+srl/or/add.s doubling; signed -> plain cvt; retail colors have bltz, so unsigned; fixes 4x4 color sites)
 *   - high nibble as (f32)(s32)((v&0xFF)>>4) with u32 v (micro: (u32)>>4 gives srl, then (s32) cast gives signed cvt without bltz; retail high has srl+plain cvt, no bltz; plain (f32)(u32) would add bltz, plain (f32)(s32>>4) would give sra)
 *   - glyph index compare as if ((s32)v >= 0x80) with u32 v (gives retail slti signed; plain u32 compare gives sltiu)
 *   - x0 separate mul/add via x0=12.0f*(f32)idx; x0+=node->x (micro: single-expr base+12*idx or t=12*idx;x0=base+t both fuse to adda/madd; only x0=t;x0+=base stays mul+add separate; matches retail mul.s+add.s; orientation t+base vs base+t remains as commutative floor)
 *   - scale CSE break via mixed forms: outer if (Ext*)node->scale (field) vs inner if (*(f32*)((u8*)node+0xC)) (byte) (micro: same-form byte+byte hoists node+12 into $s0 with extra saved reg + 0x170 frame; same-form field+field also hoists in full function; mixed forms prevent CSE, restore 0x160 frame + $s1/$s0 map; opt_common_subs off also restores frame but costs +63 words elsewhere with 0x60 bases, so mixed-forms preferred)
 *   - packet as separate f32 uv[8]; f32 quads[64]; in that order (uv first, quads second) to satisfy reverse declaration allocation: quads lands sp+0x40, uv lands sp+0x140, matching retail addiu $a1,$sp,0x40 and sll/addu/addiu 0x140; quads-then-uv order lands quads at 0x60 (wrong) despite lower nd by 1 word (v7 313 vs v8 314); v8 bases correct, banked as more faithful)
 *   - text via byte *(u8*)((u8*)node+0x10+idx) (gives retail addu node,idx + lbu 0x10(disp); struct node->text[idx] gives addiu idx,0x10 + addu + lbu 0(disp); byte preferred per 7i-pointer-temp rule; both appear in retail across sites)
 *   - declaration-order neutral sweep measured: low/tmp swap and u0/vv0 swap each stay 314 (no lever; recorded to prevent repeat)
 * Candidate emitted/window: obj 1464B / window 1472B (366 vs 367 instrs, 8B short executable, NOT zero tail, so NOT matchable via tail rule)
 * Relocations: 12 entries, 0 unresolved, 0 mismatches (targets match retail):
 *   D_00887310:4 (2 calls x HI16+LO16), D_00887300:2 (1 call x HI16+LO16), D_008872F8:2 (HI16+LO16, hoisted base), iGpffffb9e0:1 (GPREL16, +0x80 float), iGpffffb9dc:1 (GPREL16, list head), iGpffffb9e8:1 (GPREL16, raster value as u32), func_00450490:1 (R_MIPS_26, f32 in $f12, no move)
 *   Resolved prefix comparison: reloc-masked differing words 314 (probe_variants scratch splice, current b210, actual owner context); single-instruction alignment shows only color/scheduling/orientation (see residual).
 * Retail suffix: 8B short executable (missing 2 instrs in alignment, NOT zero alignment after final jr/nop; fndiff tail shows executable divergence, not padding)
 * Other owner functions: unchanged (production untouched for floor; verify src/sdkDbprt.c still 5 MATCH + 2 ASM (f720,fa90); no table changes)
 * Other owner relocations: unchanged (no file-scope edits)
 * Owner tables: none
 * Callers/declarations changed: none (void(void) ABI unchanged; f720 calls fa90 as void, no prototype change; helper func_00450490 declared extern f32(f32) inside archived body only, NOT added to production)
 * Caller-owner isolation: N/A (no caller edits)
 * Hardware contract: none (ordinary EE C; no COP2/VU0/MMI/lqc2/sqc2/COP0/sync/syscall; no movz/movn)
 * Hardware proof boundary: N/A
 * Runtime/semantic smoke boundary: no host execution (PS2 EE float + render callbacks D_00887300/10 not emulatable on host; retail fallback proves target behavior; archived C proves portable reconstruction only)
 * Repository verifier/link: python tools/verify.py src/sdkDbprt.c -> 5 MATCH, 2 ASM (first-party 5/7, 71.4%); python tools/fndiff.py <scratch> func_0044fa90 -> 314 reloc-masked; python tools/fnalign.py <scratch> -> 146 edits +5 reloc-only, 366 vs 367 instrs; NO link (no data-symbol introduction/rename/re-point; reloc targets are pre-existing retail symbols, so linked-image gate waived per handoff-8)
 * Commit: NOT COMMITTED (production remains INCLUDE_ASM; this archive banks the floor)
 * Remaining caveats: register-color floor ($a0/$v1, $f7-$f4 vs $f3-$f0, $a1/$a0, $a2/$a1) + add.s operand orientation (t+base vs base+t for x0) resisted declaration-order (v9/v10 neutral) and expression-order (madd fusion wall: all base-first spellings fuse to madd, only t-first stays separate); duplicated scale arms required (shared zEpilogue would collapse); low-nibble dead branch required (simplifying to plain &0xF loses bgez/beqz/addiu and regresses); text must stay byte (struct array loses addu+lbu16 form); file-scope HDbText3D extension (next 0x00, x 0x04, y 0x08, scale 0x0C, text[0x100] 0x10, unk110 0x110, col[4] 0x114, size 0x118 matching sibling 0x118 alloc) derived ONLY from asm-shown offsets (lbu/lwc1 + 0x100 loop bound + 0x118 alloc in matched siblings 004501f0/00450340) is DOCUMENTED here but NOT landed in production (parent reverted struct+externs with no body; per assignment, struct lands together with body only on MATCH; floor keeps production minimal with local Ext inside archived body only)
 * Private artifacts: /tmp/cand_v1.c 393 (byte, single-expr, plain casts), /tmp/cand_v2.c COMPILE ERROR (C89 decl-after-stmt), /tmp/cand_v3.c 392 (C89-fixed minimal), /tmp/cand_v4.c 386 (split t12 mul/add), /tmp/cand_v5.c 384 (local Ext struct fields, still hoisted), /tmp/cand_v6.c 329 (u32+(s32)cast slti/srl, signed high, separate mul/add, separate quads/uv), /tmp/cand_v7.c 313 (mixed scale forms break CSE, frame 0x160 fixed), /tmp/cand_v8.c 314 (uv-then-quads order fixes sp+0x40/0x140 bases, banked as faithful), /tmp/cand_v9.c 314 (low/tmp swap neutral), /tmp/cand_v10.c 314 (u0/vv0 swap neutral); micro proofs: madd_single/split fuse vs madd_muladd separate; cvt_unsigned bltz vs cvt_signed_via_cast srl+plain cvt; micro_struct hoists vs micro_field folds; opt_common_subs off restores frame but costs 377 (ruled out file-wide)
 * Production: REMAINS ASM (INCLUDE_ASM asm/nonmatchings/sdkDbprt func_0044fa90); DO NOT add file-scope struct/externs without body.
 */
// FUN_0044FA90
void func_0044fa90(void) {
    extern void (*D_00887300[])(u32, u32);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern f32 D_008872F8[];
    extern f32 func_00450490(f32);
    typedef struct Ext Ext;
    struct Ext { HDbText3D *next; f32 x; f32 y; f32 scale; u8 text[256]; f32 unk110; u8 col[4]; };
    HDbText3D *node;
    s32 idx;
    f32 invW;
    f32 scaled;
    f32 uv[8];
    f32 quads[64];
    invW = 1.0f / *(f32 *)((u8 *)iGpffffb9e0 + 0x80);
    node = iGpffffb9dc;
    D_00887300[0](1, (u32)iGpffffb9e8);
    while (node != NULL) {
        if (((Ext *)node)->scale != 0.0f) {
            scaled = func_00450490(((Ext *)node)->scale);
        }
        idx = 0;
        while (idx < 0x100) {
            u8 ch;
            ch = *(u8 *)((u8 *)node + 0x10 + idx);
            if (ch == 0) {
                break;
            }
            if (ch != 0x20) {
                if (*(f32 *)((u8 *)node + 0xC) == 0.0f) {
                    u32 v;
                    f32 x0;
                    f32 y0;
                    f32 x1;
                    f32 y1;
                    s32 low;
                    s32 tmp;
                    f32 u0;
                    f32 vv0;
                    s32 j;
                    v = (ch - 0x20) & 0xFF;
                    if ((s32)v >= 0x80) {
                        v = (v - 0x20) & 0xFF;
                    }
                    x0 = 12.0f * (f32)idx;
                    x0 += ((Ext *)node)->x;
                    y0 = ((Ext *)node)->y;
                    x1 = 11.0f + x0;
                    y1 = 11.0f + y0;
                    low = (s32)((v & 0xFF) & 0xF);
                    tmp = (s32)(v & 0xFF);
                    if (tmp < 0 && low != 0) {
                        low -= 0x10;
                    }
                    u0 = 0.0625f * (f32)low;
                    vv0 = 0.0625f * (f32)(s32)((v & 0xFF) >> 4);
                    quads[0] = x0;
                    quads[1] = y0;
                    quads[16] = x1;
                    quads[17] = y0;
                    quads[32] = x0;
                    quads[33] = y1;
                    quads[48] = x1;
                    quads[49] = y1;
                    uv[0] = u0;
                    uv[1] = vv0;
                    uv[2] = 0.046875f + u0;
                    uv[3] = vv0;
                    uv[4] = u0;
                    uv[5] = 0.046875f + vv0;
                    uv[6] = 0.046875f + u0;
                    uv[7] = 0.046875f + vv0;
                    j = 0;
                    while (j < 4) {
                        f32 *quad;
                        f32 *uvp;
                        quad = &quads[j * 16];
                        uvp = &uv[j * 2];
                        quad[2] = D_008872F8[0] - ((Ext *)node)->unk110;
                        quad[8] = (f32)(u32)((Ext *)node)->col[0];
                        quad[9] = (f32)(u32)((Ext *)node)->col[1];
                        quad[10] = (f32)(u32)((Ext *)node)->col[2];
                        quad[11] = (f32)(u32)((Ext *)node)->col[3];
                        quad[6] = invW;
                        quad[4] = uvp[0];
                        quad[5] = uvp[1];
                        j += 1;
                    }
                    D_00887310[0](4, quads, 4);
                } else {
                    u32 v;
                    f32 x0;
                    f32 y0;
                    f32 x1;
                    f32 y1;
                    s32 low;
                    s32 tmp;
                    f32 u0;
                    f32 vv0;
                    s32 j;
                    v = (ch - 0x20) & 0xFF;
                    if ((s32)v >= 0x80) {
                        v = (v - 0x20) & 0xFF;
                    }
                    x0 = 12.0f * (f32)idx;
                    x0 += ((Ext *)node)->x;
                    y0 = ((Ext *)node)->y;
                    x1 = 11.0f + x0;
                    y1 = 11.0f + y0;
                    low = (s32)((v & 0xFF) & 0xF);
                    tmp = (s32)(v & 0xFF);
                    if (tmp < 0 && low != 0) {
                        low -= 0x10;
                    }
                    u0 = 0.0625f * (f32)low;
                    vv0 = 0.0625f * (f32)(s32)((v & 0xFF) >> 4);
                    quads[0] = x0;
                    quads[1] = y0;
                    quads[16] = x1;
                    quads[17] = y0;
                    quads[32] = x0;
                    quads[33] = y1;
                    quads[48] = x1;
                    quads[49] = y1;
                    uv[0] = u0;
                    uv[1] = vv0;
                    uv[2] = 0.046875f + u0;
                    uv[3] = vv0;
                    uv[4] = u0;
                    uv[5] = 0.046875f + vv0;
                    uv[6] = 0.046875f + u0;
                    uv[7] = 0.046875f + vv0;
                    j = 0;
                    while (j < 4) {
                        f32 *quad;
                        f32 *uvp;
                        quad = &quads[j * 16];
                        uvp = &uv[j * 2];
                        quad[2] = scaled;
                        quad[8] = (f32)(u32)((Ext *)node)->col[0];
                        quad[9] = (f32)(u32)((Ext *)node)->col[1];
                        quad[10] = (f32)(u32)((Ext *)node)->col[2];
                        quad[11] = (f32)(u32)((Ext *)node)->col[3];
                        quad[6] = invW;
                        quad[4] = uvp[0];
                        quad[5] = uvp[1];
                        j += 1;
                    }
                    D_00887310[0](4, quads, 4);
                }
            }
            idx += 1;
        }
        node = node->next;
    }
}
