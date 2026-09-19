/* Original translation unit y_fclItemShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);

typedef struct {
    f32 x;
    f32 y;
} F2_0033;

extern void func_002b2970(F2_0033 *out, f32 x, f32 y);
extern u32 func_002e7a60(void);
extern s32 func_002b3170(s32 arg0);
extern void func_0033d3c0(void *, f32);
extern void func_0033d3e0(void *, F2_0033, F2_0033, u32, u32, s64);
extern void func_0033d4b0(void *, u8, u8, u8, s16, s64);
extern void func_0033d4e0(void *, s8, s16, s64, f32, f32);
extern f32 D_0064A1D8[];
extern f32 D_0064A1E0[];
extern f32 D_0064A1E8[];
extern f32 D_0064A0E8[];


extern f32 iGpffff8504;
extern u8 D_00793E80[];
extern f32 D_0064A090[];
extern f32 D_0064A380[];
extern u8 D_0064A3D8[];
extern u8 D_0064A3F0[];

void func_00332bb0(u8 *arg0);
extern void func_00332a80(void);
extern s32 func_0033cc40();
void func_0044ea90(const void *, u32);
u8 *func_00451fc0(void *, const void *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
void func_002e29a0(void);
void func_00454bd0(void *);
void func_0046b0d0(void *);
s32 func_00106a90(s64);
void *func_0046d200(void *, s32, ...);
void func_002e24a0(s32, s32, s32, s32);
f32 func_0046b260(void *);
f32 func_0046b2f0(void *);
void func_0046d280(void *);
s32 func_0033d390(void *, s32);
void func_0033d320(void *, s32, s32);
f32 func_002b2aa0(s32, f32, f32, f32, f32);
s32 func_002b2a30(u8, u8, u8, u8);
extern s32 func_00275520(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, void *arg9);
extern s16 func_002e2740(s32 arg0);
extern u32 func_001067f0(s16 arg0);
extern s32 func_00106600(s16 arg0);
extern s32 func_00110830(s32 arg0);
extern void func_002b2a60(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_002caa10(s64 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_002bc7f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, f32 arg8);
extern s16 func_002e2670(void);
extern s64 func_00106b80(s32 arg0);
extern s32 func_0033d310(u8 *arg0);
extern void func_0033d3d0(u8 *arg0, s32 arg1);
extern f32 D_0064A2B0[];
extern f32 D_0064A2B8[];
extern u8 D_00795E60[];
extern u32 func_0033cbc0(void *arg0, s64 arg1);
s16 func_002b2cb0(s32, s32, s32, s32, s32);
s16 func_002b2d00(s32, s32, s32, s32, s32);
void func_0043f810(void *, s32, s32);
s32 func_002b89a0(void *);
void *func_00460990(void);
void func_00460ac0(void *, void *);
s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern u8 D_00795FE0[];
extern u8 D_0064A360[];
extern u8 D_0064A3A0[];
extern u8 D_00763A18[];
extern void func_00332b60(u8 *, u8 *);
extern s32 func_0046aea0(void *);
extern void func_00440b68(void *, void *, s32);
extern void *func_00454a60(void *, s32);
extern s32 func_0046a750(s32);
extern s32 func_004553c0(void *);
extern u8 *func_0033d130(void *, s32, s32);
extern s32 func_00122720(void);

/* measured: func_00332bb0 recon + jump-table recovery (guarded dispatch skeleton installed - see tail). */
/* retail window 37392B = 9348 words (37392/4); fnalign decodes 9344 instrs (excludes 4 padding words). Band 9067-9628 (+-3%: 9348*0.97=9067.56, 9348*1.03=9628.44; fnalign band 9064-9624). */
/* frame 0x770 (addiu $29,$29,-0x770; sq $16-$22 + sd $31 + swc1 $f20). Calls 1214 jal. */
/* nop 1721/9348 = 18.4%; cond branches 241 (beq/bne/beqz/bnez/bgez/bltz/bgtz/blez/bc1*); */
/* total branch/jump 1569 (incl j/jal/jr); jr x2 (dispatch jr $2 at 0x00332C34 + return jr $ra). */
/* Delay slots: 0 non-nop - every branch/jump is followed by nop. Method: counted from */
/* asm/nonmatchings/y_fclItemShopDraw/func_00332bb0.s comment-lines + mnemonic regex. */
/* Dispatch: lb $2,0($18); sltiu $1,$2,0x13; beqz $1,.L0033BD80 (default); */
/*   lui/addiu jtbl_00749720; sll $2,$2,2; addu $2,$2,$3; lw $2,0($2); jr $2 (delay nop). */
/* jtbl_00749720 at 0x00749720, extent 20 words (0x50) to next jtbl_00749770 at 0x00749770; */
/*   valid 19 (indices 0..18); word 19 is 0x00000000 pad, not a case. sltiu bound 0x13 = 19 */
/*   cases (0..0x12); with the default that is 20 arms. The assignment's "twenty" counts the */
/*   default; the table itself holds 19 targets. */
/* Default .L0033BD80 = 0x0033BD80 (+0x91D0 from entry 0x00332BB0), which equals case 8's */
/*   target - case 8 shares the default block and must still be written as an explicit arm. */
/* Full table (valid 19; `python3 tools/jtbl.py 0x00749720 19 --func 0x00332bb0`): */
/*   case  0: 0x00332C3C (+0x8c)    case 10: 0x00337258 (+0x46a8) */
/*   case  1: 0x00332C88 (+0xd8)    case 11: 0x003373C4 (+0x4814) */
/*   case  2: 0x00332F64 (+0x3b4)   case 12: 0x00339A68 (+0x6eb8) */
/*   case  3: 0x00333BFC (+0x104c)  case 13: 0x0033A7D4 (+0x7c24) */
/*   case  4: 0x00334C40 (+0x2090)  case 14: 0x0033AE30 (+0x8280) */
/*   case  5: 0x0033510C (+0x255c)  case 15: 0x0033B568 (+0x89b8) */
/*   case  6: 0x00335044 (+0x2494)  case 16: 0x0033B584 (+0x89d4) */
/*   case  7: 0x003350C8 (+0x2518)  case 17: 0x0033B890 (+0x8ce0) */
/*   case  8: 0x0033BD80 (+0x91d0) = default   case 18: 0x0033BD64 (+0x91b4) */
/*   case  9: 0x00335C00 (+0x3050)  word 19: 0x00000000 pad (next table starts 0x749770). */
/* Object order (ascending targets): 0,1,2,3,4,6,7,5,9,10,11,12,13,14,15,16,17,18,8(default). */
/*   Cases 6/7 bodies precede case 5 in the object (5 at +0x255C after 7 at +0x2518); m2c */
/*   prints labels permuted (case 5 after 7) - source order stays numeric with fallthrough. */
/* C shape: switch (state) { case 0: ... case 18: ...; default: ... } where state is the */
/*   s8 at work+0 (lb, no subtract). Case 8 present but empty/fallthrough to default. The */
/*   bound matches iff all 19 cases are present; missing arms may be empty but the switch */
/*   must still span 0..18 or mwcc will not emit sltiu 0x13. */
/* m2c with tables (this lane): staged /tmp/m2c_in_00332bb0.s = build/m2c/func_00332bb0.s plus */
/*   the 19 .word entries as `.word .L<target>` under .rdata plus the missing `.L<target>:` */
/*   labels at each target's address-comment line (cf. tools/m2c_bulk.py prepare_assembly_block). */
/*   `python3 tools/vendor/m2c/m2c.py --target mipsee-mwcc-c --context build/m2c/func_00332bb0.ctx.c */
/*   --globals=used -f func_00332bb0 /tmp/m2c_in_00332bb0.s > /tmp/m2c_332bb0_out.c` succeeds; */
/*   without the table it fails `Found jr instruction at func_00332bb0.s line 38` (the dispatch). */
/*   Output /tmp/m2c_332bb0_out.c: 2366 lines (assignment lane reported 2322 - context drift), */
/*   46 M2C_ERROR, 219 distinct sp vars, 182 distinct temp_ vars, 20 unknown-sig `? func_` */
/*   decls, 0 M2C_UNK tokens (current m2c spells stack as spXXX). Switch 1 recovered with cases */
/*   0,1,2,3,4,6,7,5(permuted),9..18; case 8 merged into `default:` and must be re-added by hand. */
/*   Switches 2/3 `irregular` (3 cases each, inside the case-5 region) are branch if-chains, */
/*   not jump tables. Stack frame models as ~219 sp vars incl ~100 F2_0033 pairs (0x770 frame). */
/* Width calibration: this TU has MATCH func_0033cc40 (1216B/1216B, 304 instrs, 0 edits + 9 */
/*   reloc-only; floats-first 25ecd0 + lhu 0xF8 + inline s16/2) as the scheduling reference; */
/*   y_fclShopDraw.c supplies five banked floors with object/retail instr counts - */
/*   002cb6c0 2589/2608 (-0.7% PASS), 002cdf80 3545/3460 (+2.5% PASS, landing via s64->s32 */
/*   narrow of temp_18), 002d1590 2621/2644 (-0.9% PASS), 002db400 1983/1932, 002da0a0 */
/*   1260/1240. Expectation per assignment: an all-s32 draft lands ~10% short (~8400 vs 9348); */
/*   the landing set is 2-3 loop counters kept s64 for retail's dsll32/dsra32 pairs - candidates */
/*   var_16_2 (0x5A loop at .L00332CC4, dsll32/dsra32 at 0x232CFC/0x232D00), var_4 (0xF loop at */
/*   .L00332D24, pair at 0x232D44/0x232D48), var_16_3 (pair at 0x232D4C/0x232D50) - cf. cdf80 V8 */
/*   all-s64 3581 FAIL -> narrow temp_18 3545 PASS. */
/* Guarded body installed (this lane): structural dispatch skeleton, TU idiom (u8* work + offsets, */
/*   s8 state via lb, switch ascending 0..18 with explicit case 8, fallthrough 0->1, s64 g/h for the */
/*   0x5A/0xF dsll32 loops, per-case summaries with file protos). switch_probe: 0 chains (retail is */
/*   a real table jr $2 off jtbl_00749720, not an if-chain, so no rewrite; switch ascending is still */
/*   the lever that reproduces the table). measure_guarded: 7642 differing words (reloc-masked). */
/*   fnalign --candidate /tmp/guarded_332bb0.c: retail 9344 / object 530 instrs (5.67% of retail, */
/*   -94.33%, band 9064-9624 FAIL); edit instructions 9213 (+6 reloc-only). Rejected spellings */
/*   (all fnalign --candidate, retail 9344): chain 572/9218+4 (switch better by 5 edits, -42B); */
/*   descending switch 534/9698+2 (ascending better by 485 edits - highest-paying lever); missing */
/*   interior case 8 (still spans 0..18) 530/9213+6 identical (span matters, interior empties do not); */
/*   s32 state (lw) 530/9213+6 identical at skeleton scale (lb lever needs full scale); s32 loops */
/*   522/9218+6 (s64 better by 5 edits, +8B for dsll32 pairs). Full 9348-instr recovery remains */
/*   multi-day (m2c 2294 lines/38 M2C_ERROR via prepare_assembly_block, this lane re-ran 2026-09-19); */
/*   skeleton is structural (dispatch + call skeleton, ~530 instrs) and sits outside the band by */
/*   construction - table above + switch shape is the deliverable (gate handoff 7y). */
/* gate: func_00332bb0 is OUTSIDE the +-3% band at 530 against retail 9344 (-94.3%, band
   9064-9624).  This is a DISPATCH SKELETON, not a floor: retail dispatches through the real
   table jtbl_00749720 with 19 cases (case 8 is the default), and only the dispatch plus a few
   arms are written.  Measured while building it: an if-chain spelling is 572 instrs / 9218
   edits, descending case order is 534 / 9698, ascending is 530 / 9213 - so ascending is worth
   485 edits over descending even on a skeleton, and s64 loop counters beat s32 by 5.
   No word or edit number measured against this body is comparable until the arms are written
   (handoff 7y). */
// FUN_00332BB0 NONMATCHING
#ifdef NON_MATCHING
void func_00332bb0(u8 *arg0) {
    u8 *work;
    void *tmp;
    s8 state;
    s64 g;
    s64 h;
    s32 i;
    s32 k;
    F2_0033 p0;
    F2_0033 p1;

    work = *(u8 **)(arg0 + 0x38);
    tmp = func_00460990();
    *(void **)((u8 *)tmp + 8) = (void *)func_00332b60;
    *(void **)((u8 *)tmp + 0x10) = work;
    func_00460ac0(D_00795FE0, tmp);
    state = *(s8 *)(work + 0);
    switch (state) {
    case 0:
        *(s32 *)(work + 0xC) = func_0046aea0(D_0064A360);
        func_00440b68(D_00763A18, D_0064A380, 0x17B);
        *(void **)(work + 0x428) = func_00454a60(D_0064A3A0, 0);
        *(s8 *)(work + 0) = 1;
        /* fallthrough */
    case 1:
        if (func_0046a750(*(s32 *)(work + 0xC)) != 0 && func_004553c0(*(void **)(work + 0x428)) != 0) {
            *(s8 *)(work + 0) = 2;
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 0x5A) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                if (*(void **)(work + k * 4 + 0x10) != 0) {
                    *(void **)(work + k * 4 + 0x10) = 0;
                }
                *(void **)(work + k * 4 + 0x10) = func_0033d130(arg0, k & 0xFFFF, *(s32 *)(work + 0xC));
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            h = 0;
            while (((s64)(h << 0x30) >> 0x30) < 0xF) {
                k = (s32)((s64)(h << 0x30) >> 0x30);
                if (*(s32 *)(work + k * 4 + 0x178) != 0) {
                    *(s32 *)(work + k * 4 + 0x178) = 0;
                }
                h = (s64)(((s64)(h << 0x30) >> 0x30) + 1);
            }
            *(void **)(work + 0x178) = func_0033d130(arg0, 0x2B, *(s32 *)(work + 0xC));
            *(void **)(work + 0x17C) = func_0033d130(arg0, 0x28, *(s32 *)(work + 0xC));
            *(void **)(work + 0x180) = func_0033d130(arg0, 0x28, *(s32 *)(work + 0xC));
            *(void **)(work + 0x184) = func_0033d130(arg0, 0x28, *(s32 *)(work + 0xC));
        }
        break;
    case 2:
        i = 0;
        while ((s16)i < 0x24) {
            *(s8 *)(work + (s16)i + 0x2D8) = 1;
            i = (s16)(i + 1);
        }
        func_0033d320((void *)*(s32 *)(work + 0x110), 0, 0);
        func_002b2970(&p0, D_0064A090[0], D_0064A090[1]);
        func_002b2970(&p1, D_0064A090[0], D_0064A090[1]);
        func_0033d3e0((void *)*(s32 *)(work + 0x110), p0, p1, 0, 0, 0);
        func_0033d3c0((void *)*(s32 *)(work + 0x110), 17.0f);
        func_0033d3d0((void *)*(s32 *)(work + 0x110), 0x63);
        func_0033d320((void *)*(s32 *)(work + 0x114), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0x10), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0x164), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0xB0), 0, 0);
        *(s8 *)(work + 0) = 3;
        break;
    case 3:
        i = 0;
        while ((s16)i < 4) {
            if (func_0033d390((void *)*(s32 *)(work + (s16)i * 4 + 0x1C), 2) == 0) {
                func_0033d3d0((void *)*(s32 *)(work + (s16)i * 4 + 0x1C), 0xAB);
            }
            i = (s16)(i + 1);
        }
        func_0033d320((void *)*(s32 *)(work + 0x58), 0, 0);
        func_0033d3c0((void *)*(s32 *)(work + 0x58), 80.0f);
        func_0033d3d0((void *)*(s32 *)(work + 0x58), 0x3D);
        func_0033d320((void *)*(s32 *)(work + 0x5C), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0x118), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0x11C), 0, 0);
        *(s8 *)(work + 0) = 4;
        break;
    case 4:
        if (*(s8 *)(work + 2) == 1) {
            func_0033d320((void *)*(s32 *)(work + 0x60), 0, 0);
            *(s8 *)(work + 0) = 5;
        } else {
            func_0033d320((void *)*(s32 *)(work + 0x60), 0, 1);
            *(s8 *)(work + 0) = 6;
        }
        break;
    case 5:
        func_0033d320((void *)*(s32 *)(work + 0x14), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0x40), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0x44), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0x48), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0x4C), 0, 0);
        *(s8 *)(work + 0) = 9;
        break;
    case 6:
        func_0033d320((void *)*(s32 *)(work + 0x14), 0, 1);
        *(s8 *)(work + 0) = 5;
        break;
    case 7:
        func_0033d320((void *)*(s32 *)(work + 0x14), 0, 2);
        *(s8 *)(work + 0) = 5;
        break;
    case 8:
        /* shares the default block in retail (.L0033BD80) - kept explicit so the switch still spans 0..18 and mwcc emits sltiu 0x13. */
        break;
    case 9:
        func_0033d320((void *)*(s32 *)(work + 0xB4), 0, 0);
        func_002b2970(&p0, D_0064A1D8[0], D_0064A1D8[1]);
        func_002b2970(&p1, -180.0f, D_0064A1D8[1]);
        func_0033d3e0((void *)*(s32 *)(work + 0xB4), p0, p1, 0, 0xF, 0x16);
        func_0033d320((void *)*(s32 *)(work + 0xB8), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0xBC), 0, 0);
        *(s8 *)(work + 0) = 10;
        break;
    case 10:
        func_0033d320((void *)*(s32 *)(work + 0x178), 0, 0);
        func_0033d320((void *)*(s32 *)(work + 0x3C), 0, 0);
        *(s8 *)(work + 0) = 11;
        break;
    case 11:
        i = 0;
        while ((s16)i < 3) {
            func_0033d320((void *)*(s32 *)(work + (s16)i * 4 + 0x17C), 0, 0);
            i = (s16)(i + 1);
        }
        func_0033d320((void *)*(s32 *)(work + 0xB0), 0, 0);
        *(s8 *)(work + 0) = 12;
        break;
    case 12:
        func_0033d320((void *)*(s32 *)(work + 0x58), 0, 1);
        func_0033d320((void *)*(s32 *)(work + 0x5C), 0, 1);
        func_0033d320((void *)*(s32 *)(work + 0x118), 0, 1);
        *(s8 *)(work + 0) = 13;
        break;
    case 13:
        func_0033d320((void *)*(s32 *)(work + 0x11C), 0, 1);
        func_0033d3d0((void *)*(s32 *)(work + 0xB0), 0x65);
        *(s8 *)(work + 0) = 14;
        break;
    case 14:
        func_0033d3d0((void *)*(s32 *)(work + 0x110), 0x65);
        func_0033d3d0((void *)*(s32 *)(work + 0x114), 0x65);
        func_0033d3d0((void *)*(s32 *)(work + 0x60), 0x65);
        *(s8 *)(work + 0) = 15;
        break;
    case 15:
        func_0033d320((void *)*(s32 *)(work + 0x10), 0, 0);
        func_002b2970(&p0, D_0064A090[0], D_0064A090[1]);
        func_002b2970(&p1, 650.0f, 241.0f);
        func_0033d3e0((void *)*(s32 *)(work + 0x10), p0, p1, 0, 0xA, 0);
        *(s8 *)(work + 0) = 16;
        break;
    case 16:
        func_0033d320((void *)*(s32 *)(work + 0x58), 0, 1);
        func_0033d320((void *)*(s32 *)(work + 0x5C), 0, 1);
        *(s8 *)(work + 0) = 17;
        break;
    case 17:
        func_0033d320((void *)*(s32 *)(work + 0x118), 0, 1);
        func_0033d320((void *)*(s32 *)(work + 0x11C), 0, 1);
        *(s8 *)(work + 0) = 18;
        break;
    case 18:
        if (func_00122720() != 0) {
            return;
        }
        break;
    default:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclItemShopDraw", func_00332bb0);
#endif

// FUN_0033BDC0
void func_0033bdc0(u8 *arg0) {
    u8 *work = *(u8 **)(arg0 + 0x38);

    func_002e29a0();
    if (*(s32 *)(work + 0x428) != 0) {
        func_00454bd0((void *)*(s32 *)(work + 0x428));
    }
    if (*(s32 *)(work + 0xC) != 0) {
        func_0046b0d0((void *)*(s32 *)(work + 0xC));
        *(s32 *)(work + 0xC) = 0;
    }
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

/* measured: object_size 324/window 336, normalized_diff 0 (retail tail is
   zero padding). MWCCPS2 needs opt_loop_invariants on to hoist the loop's
   `1` constant before the entry jump, matching retail's preheader materialisation. */
#pragma opt_loop_invariants on
// FUN_0033BE40
u8 *func_0033be40(u8 *arg0) {
    s32 i;
    s32 one;
    u8 *temp_17;
    s8 *temp_2;

    func_0044ea90(D_0064A380, 0x958);
    temp_2 = (s8 *)D_008873F4[0](1, 0x42C, 0x40000);
    temp_17 = func_00451fc0(arg0, D_0064A3D8, 0xF, 0, 0, func_00332bb0, func_0033bdc0, (u8 *)temp_2);
    *(s8 *)(temp_2 + 0) = 0;
    *(s32 *)(temp_2 + 0xC) = 0;
    *(f32 *)(temp_2 + 0x1E0) = (f32)0x28A;
    *(s32 *)(temp_2 + 0x1E4) = 0x41700000;
    *(s16 *)(temp_2 + 0x1EA) = 0;
    *(s16 *)(temp_2 + 0x1EC) = 0;
    *(s8 *)(temp_2 + 1) = 0;
    *(s32 *)(temp_2 + 0x2B0) = 0;
    *(s32 *)(temp_2 + 0x2A8) = 0;
    *(s32 *)(temp_2 + 0x2AC) = 0;
    *(s8 *)(temp_2 + 0x424) = 0;
    one = 1;
    i = 0;
    while ((s16)i < 0x24) {
        *(s8 *)(temp_2 + (s16)i + 0x2D8) = one;
        i = (s16)(i + 1);
    }
    if (func_002e71c0() == 1) {
        *(s8 *)(temp_2 + 0x424) = 1;
    }
    func_002e24a0(0x10000, 0, 2, 1);
    return temp_17;
}
/* measured: closes the opt_loop_invariants scope required by func_0033be40. */
#pragma opt_loop_invariants off

// FUN_0033BF90
void func_0033bf90(u8 *arg0) {
    s32 i;
    u8 *work;
    s32 item_index;
    s64 layer;
    f32 *coords;
    u8 *item;
    void *font;
    register u8 *table;
    f32 x;
    f32 y;
    F2_0033 pos0;
    F2_0033 pos1;
    F2_0033 pos2;
    F2_0033 pos3;
    F2_0033 pos4;
    F2_0033 pos5;
    F2_0033 pos6;
    F2_0033 pos7;
    F2_0033 pos8;
    F2_0033 pos9;
    F2_0033 pos10;
    F2_0033 pos11;

    work = *(u8 **)(arg0 + 0x38);
    i = 0;
    while ((s16)i < 4) {
        layer = (s64)(s16)((s16)i * 3);
        item_index = (s16)i + 3;
        coords = (f32 *)((u8 *)D_0064A090 + (item_index * 8));
        item = work + (s16)i * 4 + 0x1C;
        func_0033d4e0((void *)*(s32 *)item, 0, 10, layer, 1.0f, 0.5f);
        func_0033d4b0((void *)*(s32 *)item, 0xFF, 0, 0, 10, layer);
        func_0033d3d0((void *)*(s32 *)item, 0xAC);
        font = func_0046d200((void *)*(s32 *)(work + 0xC), item_index);
        func_002b2970(&pos0, coords[0], coords[1]);
        x = (func_0046b260(font) / 10.0f) * 1.5f + coords[0] + 0.0f;
        y = (func_0046b2f0(font) / 10.0f) * 1.5f + coords[1] + 0.0f;
        func_002b2970(&pos1, x, y);
        func_0033d3e0((void *)*(s32 *)item, pos0, pos1, 0, 10, layer);
        func_0046d280(font);
        i = (s16)(i + 1);
    }
    func_0033d320((void *)*(s32 *)(work + 0x14), 0, 0);
    func_0033d4b0((void *)*(s32 *)(work + 0x14), 0xFF, 0, 0, 10, 0);
    func_0033d3d0((void *)*(s32 *)(work + 0x14), 0xAC);
    table = (u8 *)D_0064A1D8;
    func_002b2970(&pos2, *(f32 *)(table + 0), *(f32 *)(table + 4));
    func_002b2970(&pos3, -180.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xB4), pos2, pos3, 0, 0x14, 0);
    table = (u8 *)D_0064A1E0;
    func_002b2970(&pos4, *(f32 *)(table + 0), *(f32 *)(table + 4));
    func_002b2970(&pos5, -200.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xB8), pos4, pos5, 0, 10, 0);
    table = (u8 *)D_0064A1E8;
    func_002b2970(&pos6, 153.0f, *(f32 *)(table + 4));
    func_002b2970(&pos7, -100.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xBC), pos6, pos7, 0, 0x14, 0);
    func_002b2970(&pos8, 203.0f, *(f32 *)(table + 4));
    func_002b2970(&pos9, -50.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0x178), pos8, pos9, 0, 0x14, 0);
    table = (u8 *)D_0064A0E8;
    func_002b2970(&pos10, *(f32 *)(table + 0), *(f32 *)(table + 4));
    func_002b2970(&pos11, -200.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0x3C), pos10, pos11, 0, 0xF, 0);
    func_0033d4e0((void *)*(s32 *)(work + 0xB0), 0, 0xF, 0, 1.0f, 4.5f);
    i = 0;
    while ((s16)i < 3) {
        func_0033d4e0((void *)*(s32 *)(work + (s16)i * 4 + 0x17C), 0, 0xF, 0, 1.0f, 4.5f);
        i = (s16)(i + 1);
    }
    func_0033d3c0((void *)*(s32 *)(work + 0x110), 84.0f);
    func_0033d3c0((void *)*(s32 *)(work + 0x114), 84.0f);
    func_0033d3c0((void *)*(s32 *)(work + 0x60), 83.0f);
    *(f32 *)(work + 0x1D0) = 580.0f - (f32)func_002b3170(func_002e7a60()) * 21.0f;
    *(s32 *)(work + 0x1D4) = 0x41700000;
    *(f32 *)(work + 0x1D8) = (f32)0x28A;
    *(s32 *)(work + 0x1DC) = 0x41700000;
    *(s16 *)(work + 0x1EA) = 0;
    *(s8 *)(work + 0) = 0x11;
}

/* measured: live body obj 1856B/window 1840B (+16B, 464/460 instrs); fndiff 326
 * differing words (reloc-masked); fnalign 178 edits (+8 reloc-only). Reconstructed
 * from retail asm (verified via bash after one corrupted tool read) + IDA +
 * same-file decls (25ecd0 14-param, 275520 float-first 10-param, d310/d3d0,
 * D_0064A2B0/B8 + D_00795E60 registered). Residual is a saved-register coloring
 * rotation (p in $s4 vs $s0 + cascade; p decl first/last compile identically),
 * sw/lw at the three sq/lq spill slots (bound/b2/w0), color-init daddiu/andi
 * shapes, 2b2a30 late-move. Tried: block-scope lessons from cc40 do not apply
 * (no extra save; frame exact). Next: find the $s0 squatter or accept floor. */
// FUN_0033C490 NONMATCHING
#ifdef NON_MATCHING
void func_0033c490(u8 *arg0)
{
    s32 v4;
    s32 v6;
    s32 c18;
    s32 c19;
    s32 c20;
    s32 v21;
    s32 v23;
    f32 *tbl;
    s32 cbret;
    s32 bound;
    s16 w;
    f32 f20v;
    s32 b2;
    s32 w0;
    s32 off28;
    F2_0033 f2[2];
    s32 sw[2];
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(p + 2) == 1) {
        func_0025ecd0(44.0f, 77.0f, 62.0f, func_002b2a30(0xFF, 0x26, 0x26, 0x26), 0xFF, 0x24, *(void **)(p + 0xC), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
        v4 = func_002b2a30(0x26, 0x26, 0x26, 0xFF);
        {
            s32 t5 = func_002e2740(*(s16 *)(p + 4));
            v6 = func_001067f0((s16)t5);
        }
        func_00275520(78.0f, 77.0f, 62.0f, v4, 0, 1, v6, 0, 0, D_00795E60);
        func_002b2970(&f2[1], 406.0f, 84.0f);
        func_002b2a60(&sw[1], 0x26, 0x26, 0x26, 0xFF);
        func_002caa10(*(s64 *)&f2[1], sw[1], func_0033cbc0(arg0, func_002e2740(*(s16 *)(p + 4))), 0x19, *(s32 *)(p + 0xC), 0xAB);
        {
            s32 t5 = func_002e2740(*(s16 *)(p + 4));
            func_002bc7f0((s16)func_00106b80((s16)t5), -1, 1, 0, 4, 0xAA, 71.0f, 135.0f, 62.0f);
        }
        func_0033d320((void *)*(s32 *)(p + 0x120), 0, 1);
        func_0033d320((void *)*(s32 *)(p + 0x124), 0, 1);
        func_0033d320((void *)*(s32 *)(p + 0xDC), 0, 0);
        func_0033d320((void *)*(s32 *)(p + 0xE0), 0, 0);
        func_0033d320((void *)*(s32 *)(p + 0x6C), 0, 1);
        func_0033d320((void *)*(s32 *)(p + 0x70), 0, 0);
        func_0033d320((void *)*(s32 *)(p + 0xD8), 0, 0);
    } else {
        func_0033d320((void *)*(s32 *)(p + 0xDC), 0, 1);
        func_0033d320((void *)*(s32 *)(p + 0xE0), 0, 1);
        func_0033d320((void *)*(s32 *)(p + 0x6C), 0, 0);
        func_0033d320((void *)*(s32 *)(p + 0x70), 0, 1);
        func_0033d320((void *)*(s32 *)(p + 0xD8), 0, 1);
        func_0033d320((void *)*(s32 *)(p + 0x120), 0, 0);
        tbl = D_0064A2B0;
        f20v = tbl[0];
        *(f32 *)(func_0033d310((u8 *)*(s32 *)(p + 0x120)) + 0x2C) = f20v;
        f20v = tbl[1] + (f32)(28 * *(s16 *)(p + 6));
        *(f32 *)(func_0033d310((u8 *)*(s32 *)(p + 0x120)) + 0x30) = f20v;
        func_0033d3c0((void *)*(s32 *)(p + 0x120), 63.0f);
        func_0033d3d0((u8 *)*(s32 *)(p + 0x120), 0x5B);
        func_0033d320((void *)*(s32 *)(p + 0x124), 0, 0);
        tbl = D_0064A2B8;
        f20v = tbl[0];
        *(f32 *)(func_0033d310((u8 *)*(s32 *)(p + 0x124)) + 0x2C) = f20v;
        f20v = tbl[1] + (f32)(28 * *(s16 *)(p + 6));
        *(f32 *)(func_0033d310((u8 *)*(s32 *)(p + 0x124)) + 0x30) = f20v;
        func_0033d3c0((void *)*(s32 *)(p + 0x124), 63.0f);
        func_0033d3d0((u8 *)*(s32 *)(p + 0x124), 0x5B);
        func_0033d320((void *)*(s32 *)(p + 0x124), 0, 0);
        v21 = (s16)(*(s16 *)(p + 4) - *(s16 *)(p + 6));
        v23 = 0;
        bound = v21 + 5;
        while ((w = (s16)v21) < bound) {
            if (w < func_002e2670()) {
                c20 = 0xFF;
                c18 = 0;
                c19 = 0;
                if (w == *(s16 *)(p + 4)) {
                    c18 = 0x26;
                    c19 = 0x26;
                    c20 = 0x26;
                } else {
                    cbret = func_0033cbc0(arg0, func_002e2740(w));
                    if (func_002e7a60() < cbret) {
                        c20 = 0x4F;
                        c18 = 0;
                        c19 = 0;
                    } else {
                        {
                            s32 t5 = func_002e2740(w);
                            if (((u8)func_00106600((s16)t5)) == 0x63) {
                                c20 = 0x4F;
                                c18 = 0;
                                c19 = 0;
                            } else {
                                s32 t6 = func_002e2740(w);
                                if (((u8)func_00110830(t6)) & 1) {
                                    c20 = 0x9F;
                                    c18 = 0x2F;
                                }
                            }
                        }
                    }
                }
                off28 = (s16)v23 * 28;
                b2 = off28 + 0x4D;
                f20v = (f32)b2;
                w0 = func_002b2a30(0xFF, c20, c19, c18);
                func_0025ecd0(44.0f, f20v, 62.0f, w0, 0xFF, 0x24, *(void **)(p + 0xC), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
                w0 = func_002b2a30(c20, c19, c18, 0xFF);
                {
                    s32 t5 = func_002e2740(w);
                    v6 = func_001067f0((s16)t5);
                }
                func_00275520(78.0f, f20v, 62.0f, w0, 0, 1, v6, 0, 0, D_00795E60);
                func_002b2970(&f2[0], 406.0f, (f32)(off28 + 0x54));
                func_002b2a60(&sw[0], c20, c19, c18, 0xFF);
                v4 = func_0033cbc0(arg0, func_002e2740(w));
                func_002caa10(*(s64 *)&f2[0], sw[0], v4, 0x19, *(s32 *)(p + 0xC), 0xAB);
            }
            v21 = (s16)(v21 + 1);
            v23 = (s16)(v23 + 1);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclItemShopDraw", func_0033c490);
#endif
// FUN_0033CBC0
u32 func_0033cbc0(void *arg0, s64 arg1) {
    u8 *work = *(u8 **)((u8 *)arg0 + 0x38);
    u32 d = (u32)((s32)(*(s8 *)(work + 9) * (s32)func_00106a90((s64)(s16)arg1)) * 0x14) / 100U;

    return (u32)func_00106a90((s64)(s16)(s32)arg1) - d;
}

/* measured: 1216B/1216B MATCH (304 instrs, 0 edits + 9 reloc-only). Re-probed from scratch: floats-first func_0025ecd0 spelling (f32,f32,f32 first, then color/ints, then f32,f32,f32, pointer last) with u16 0xF8 load (lhu) and inline s16/2 division gives retail scheduling; shift+temp hoisting was +33, s16 F8 was +2 (35), archive ints-first is a compile error under this prototype. Mixed-arg orders tested explicitly. */
// FUN_0033CC40
s32 func_0033cc40(void *arg0) {
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f20;
    s16 temp_4;
    s16 temp_4_2;
    s16 temp_6;
    s8 temp_3;
    s8 temp_3_5;
    u8 *temp_2;
    u8 *callback_work;

    callback_work = *(u8 **)((u8 *)arg0 + 0x38);
    func_0043f810(callback_work + 4, func_002b89a0(callback_work + 4), 0xF0);
    if (func_0033d390((u8 *)arg0, 0xA) == 1) {
        temp_4 = *(s16 *)(callback_work + 0x38);
        if (temp_4 == 0) {
            temp_3 = *(s8 *)(callback_work + 0x3B);
            switch (temp_3) {
            case 0:
                *(f32 *)(callback_work + 0x2C) = func_002b2aa0(
                    0, *(f32 *)(callback_work + 0x1C), *(f32 *)(callback_work + 0x24),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                *(f32 *)(callback_work + 0x30) = func_002b2aa0(
                    *(s8 *)(callback_work + 0x3A), *(f32 *)(callback_work + 0x20),
                    *(f32 *)(callback_work + 0x28), (f32)*(s16 *)(callback_work + 0x36),
                    (f32)(*(s16 *)(callback_work + 0x34) / 2));
                break;
            case 1:
                *(f32 *)(callback_work + 0x2C) = func_002b2aa0(
                    *(s8 *)(callback_work + 0x3A), *(f32 *)(callback_work + 0x1C),
                    *(f32 *)(callback_work + 0x24), (f32)*(s16 *)(callback_work + 0x36),
                    (f32)(*(s16 *)(callback_work + 0x34) / 2));
                *(f32 *)(callback_work + 0x30) = func_002b2aa0(
                    0, *(f32 *)(callback_work + 0x20), *(f32 *)(callback_work + 0x28),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                break;
            case 2:
                *(f32 *)(callback_work + 0x2C) = func_002b2aa0(
                    1, *(f32 *)(callback_work + 0x1C), *(f32 *)(callback_work + 0x24),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                *(f32 *)(callback_work + 0x30) = func_002b2aa0(
                    2, *(f32 *)(callback_work + 0x20), *(f32 *)(callback_work + 0x28),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                *(f32 *)(callback_work + 0x30) = (f32)(
                    *(f32 *)(callback_work + 0x30) -
                    func_002b2aa0(1, 0.0f, 100.0f,
                                  (f32)*(s16 *)(callback_work + 0x36), (f32)(*(s16 *)(callback_work + 0x34) / 2)));
                break;
            }
            temp_6 = *(s16 *)(callback_work + 0x34);
            temp_4_2 = *(s16 *)(callback_work + 0x36);
            if (temp_4_2 < temp_6) {
                *(s16 *)(callback_work + 0x36) = func_002b2cb0(
                    (s32)temp_4_2, 1, (s32)temp_6, 0, 1);
            } else {
                *(f32 *)(callback_work + 0x2C) = *(f32 *)(callback_work + 0x24);
                *(f32 *)(callback_work + 0x30) = *(f32 *)(callback_work + 0x28);
                temp_3_5 = *(s8 *)(callback_work + 0x3B);
                if (temp_3_5 == 0) {
                    *(f32 *)(callback_work + 0x30) = *(f32 *)(callback_work + 0x20);
                } else if (temp_3_5 == 1) {
                    *(f32 *)(callback_work + 0x2C) = *(f32 *)(callback_work + 0x1C);
                }
                func_0033d320((u8 *)arg0, 0xA, 1);
            }
        } else {
            *(s16 *)(callback_work + 0x38) = func_002b2d00(temp_4, 1, 0, 0, 1);
        }
    }
    if (func_0033d390((u8 *)arg0, 0) == 1) {
        if (func_0033d390((u8 *)arg0, 0xD) == 1) {
            temp_2 = (u8 *)func_00460990();
            *(void **)(temp_2 + 8) = (void *)func_00332a80;
            *(s32 *)(temp_2 + 0x10) = 0;
            func_00460ac0(
                (void *)((u8 *)D_00793E80 +
                         (*(s32 *)(callback_work + 0xFC) * 0x30)),
                temp_2);
            func_0025ecd0(
                *(f32 *)(callback_work + 0x2C), *(f32 *)(callback_work + 0x30),
                *(f32 *)(callback_work + 8),
                func_002b2a30(0xFF, *(u8 *)(callback_work + 0x79),
                              *(u8 *)(callback_work + 0x7A), *(u8 *)(callback_work + 0x7B)),
                *(u8 *)(callback_work + 0x62), *(u16 *)(callback_work + 0xF8),
                (void *)*(s32 *)(callback_work + 0xF4), 0,
                *(s16 *)(callback_work + 0x100), *(s16 *)(callback_work + 0x102),
                *(f32 *)(callback_work + 0xC4),
                *(f32 *)(callback_work + 0x94), *(f32 *)(callback_work + 0xA0),
                (void *)((u8 *)D_00793E80 + (*(s32 *)(callback_work + 0xFC) * 0x30)));
        } else {
            temp_f20 = *(f32 *)(callback_work + 0x94);
            temp_f0 = iGpffff8504;
            if (!(temp_f20 < temp_f0)) {
                temp_f21 = *(f32 *)(callback_work + 0xA0);
                if (!(temp_f21 < temp_f0)) {
                    func_0025ecd0(
                        *(f32 *)(callback_work + 0x2C), *(f32 *)(callback_work + 0x30),
                        *(f32 *)(callback_work + 8),
                        func_002b2a30(0xFF, *(u8 *)(callback_work + 0x79),
                                      *(u8 *)(callback_work + 0x7A),
                                      *(u8 *)(callback_work + 0x7B)),
                        *(u8 *)(callback_work + 0x62), *(u16 *)(callback_work + 0xF8),
                        (void *)*(s32 *)(callback_work + 0xF4), 1,
                        *(s16 *)(callback_work + 0x100), *(s16 *)(callback_work + 0x102),
                        *(f32 *)(callback_work + 0xC4),
                        temp_f20, temp_f21,
                        (void *)((u8 *)D_00793E80 + (*(s32 *)(callback_work + 0xFC) * 0x30)));
                }
            }
        }
    }
    return 0;
}

// FUN_0033D100
void func_0033d100(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0033D130
/* Counter must be s32 with explicit (s16) casts at each use to reproduce
   retail's $a3 counter coloring and the per-use dsll32/dsra32 normalization.
   measured: without this pragma mwcc rematerializes the 0xFF / 0x3F800000
   constants inside the loop body (nd 50+); with it they hoist to the
   preheader exactly as retail does (nd 0). */
#pragma opt_loop_invariants on
u8 *func_0033d130(void *arg0, s32 arg1, s32 arg2) {
    s32 i;
    u8 *temp_17;
    u8 *work;
    f32 *item_data;
    void *r;

    func_0044ea90(D_0064A380, 0xACA);
    work = D_008873F4[0](1, 0x104, 0x40000);
    temp_17 = func_00451fc0(arg0, D_0064A3F0, 0xF, 0, 0, (void (*)(u8 *))func_0033cc40, func_0033d100, work);
    work[0] = 0;
    *(s16 *)(work + 0xF8) = arg1;
    *(s32 *)(work + 0xF4) = arg2;
    item_data = (f32 *)((u8 *)D_0064A090 + ((arg1 & 0xFFFF) * 8));
    for (i = 0; (s16)i < 3; i = (s16)(i + 1)) {
        *(f32 *)(work + (s16)i * 8 + 0x1C) = item_data[0];
        *(f32 *)(work + (s16)i * 8 + 0x20) = item_data[1];
        work[(s16)i + 0x60] = 0xFF;
        *(s32 *)(work + (s16)i * 4 + 0x8C) = 0x3F800000;
        *(s32 *)(work + (s16)i * 4 + 0x98) = 0x3F800000;
        *(s32 *)(work + (s16)i * 4 + 0xBC) = 0;
        work[(s16)i * 4 + 0x73] = 0xFF;
        work[(s16)i * 4 + 0x72] = 0xFF;
        work[(s16)i * 4 + 0x71] = 0xFF;
    }
    *(s32 *)(work + 8) = 0x42C80000;
    *(s32 *)(work + 0xFC) = 0x55;
    *(s16 *)(work + 4) = 0;
    r = func_0046d200((void *)*(s32 *)(work + 0xF4), 0, item_data, i);
    *(s16 *)(work + 0x100) = (s16)(s32)(func_0046b260(r) / 2.0f);
    *(s16 *)(work + 0x102) = (s16)(s32)(func_0046b2f0(r) / 2.0f);
    func_0046d280(r);
    return temp_17;
}
/* measured: see annotation above (func_0033d130). */
#pragma opt_loop_invariants off

