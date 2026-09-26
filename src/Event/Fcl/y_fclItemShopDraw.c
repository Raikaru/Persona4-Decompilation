/* Original translation unit y_fclItemShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fcl_draw_types.h"
extern void (*jtbl_008873EC[])(void *ptr);
/* Row colours reach the packer as bytes in this unit: retail passes the u8
   locals through with no zero-extension, so this view of func_002b2a60
   takes u8 components (include/fcl_color.h keeps the int view other units
   need). */
typedef struct {
    u8 c0, c1, c2, c3;
} FclDrawColor;

FclDrawColor func_002b2a60(u8 red, u8 green, u8 blue, u8 alpha);
extern void *(*D_008873F4[])(size_t, size_t, u32);

typedef FclVec2 F2_0033;

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
extern f32 D_0064A2A0[];
extern f32 D_0064A2A8[];
extern f32 D_0064A338[];
extern f32 D_0064A094[];
extern f32 D_0064A1F0[];
extern f32 D_0064A1F8[];
extern f32 D_0064A200[];
extern f32 D_0064A208[];
extern f32 D_0064A220[];
extern f32 D_0064A228[];
extern f32 D_0064A230[];
extern f32 D_0064A318[];
extern f32 D_0064A320[];
extern f32 D_0064A340[];
extern f32 D_0064A348[];
extern f32 D_0064A350[];
extern f32 D_0064A358[];
extern void func_0033d420(void *arg0, s64 arg1, s64 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);


extern f32 iGpffff8504;
extern u8 D_00793E80[];
extern f32 D_0064A090[];
extern f32 D_0064A380[];
extern u8 D_0064A3D8[];
extern u8 D_0064A3F0[];

s32 func_00332bb0(u8 *arg0);
extern void func_00332a80(void);
extern s32 func_0033cc40(u8 *task);
void func_0044ea90(const void *, u32);

void func_002e29a0(void);
void H_Cdvd_Destroy(void *);
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
extern s64 func_002e2740(s32 arg0);
extern u32 func_001067f0(s16 arg0);
extern s32 func_00106600(s16 arg0);
extern s32 clndGetMoonPhase(s64 arg0);
extern void func_002caa10(s64 position, f32 depth, s32 color, u32 number, s16 glyphBase, void *sprite, s32 style);
extern void func_002bc7f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, f32 arg8);
extern s32 func_002e2670(void);
extern s64 func_00106b80(s32 arg0);
extern u8 *func_0033d310(u8 *arg0);
extern void func_0033d3d0(u8 *arg0, s32 arg1);
extern f32 D_0064A2B0[];
extern f32 D_0064A2B8[];
extern u8 D_00795E60[];
extern u32 func_0033cbc0(void *arg0, s64 arg1);
s16 func_002b2cb0(s32, s32, s32, s32, s32);
s16 func_002b2d00(s32, s32, s32, s32, s32);
void memcpy(void *, s32, s32);
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
extern s32 H_Cdvd_IsFileLoaded(void *);
extern u8 *func_0033d130(void *, s32, s32);
extern s32 func_00122720(void);
extern s32 func_002bb680(s8 arg0);
extern void func_002bbcf0(s8 arg0);
extern void func_002bb550(s8 arg0);
extern s8 func_002bab80(s32 arg0);
extern void func_002badc0(s32 arg0, s32 arg1);
extern u8 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern s32 func_00110a60(s32 arg0, s32 arg1);
extern s32 func_00452380(void *arg0);
extern u8 D_0064A3C0[];
extern f32 func_0033d630(F2_0033 pos, s32 step, s32 b, s32 unk, f32 f);
extern void func_0033d520(u8 *arg0, s8 arg1, s16 arg2, s64 arg3, f32 fparg0, f32 fparg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern f32 iGpffff8424;
extern f32 iGpffff851c;
extern f32 iGpffff809c;
extern f32 iGpffff84cc;
extern f32 D_0064A210[];
extern f32 D_0064A218[];
extern void func_0045af60(s32, s32, s32, s32);
extern s8 func_002bb1c0(s8 arg0);
extern void func_00106620(s16 arg0, s32 arg1);
extern void func_002e7a80(s32 arg0);
void func_0033c490(u8 *arg0);
extern void func_0033d550(void *arg0);
extern u16 D_008C024E[];
extern f32 D_0064A290[];
extern f32 D_0064A298[];
extern f32 D_0064A328[];
extern f32 D_0064A330[];
extern u16 D_008C027A[];
extern u8 D_007950B0[];
extern char iGpffffa930;
extern void sprintf(void *dst, void *fmt, s32 val);
extern void func_002bbd80(s8 arg0, s32 arg1, void *arg2);
extern void func_002bafc0(s8 arg0, s32 arg1);
extern void func_002bb0a0(s8 arg0, s32 arg1);
extern void func_002bbf60(void);

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
/* gate: func_00332bb0 OUTSIDE band at 5581 vs retail 9344 (band 9064-9624). 14 arms written */
/*   (0 fallthrough,1-tail,3,4,6,7,8=default,9,10,12,13,14,15,16,17,18), object 1451->1846 (+395 vs */
/*   407, -12) ->2299 (+453 vs 462, -9) ->3142 (+843 vs 861, -18) ->4158 (+1016 vs 1041, -25) */
/*   ->5581 (+1423 vs 1430, -7); edits 8559->8271->7972->7939->7428->5502 (all +8..20 reloc-only), */
/*   words 7636->7654->7650->7658->7705->7690 (reloc-masked). */
/*   Cases 15/18 return s32 (0/-1 via func_00122720); all break paths return 0 via shared epilogue */
/*   (BD80). Dispatch still exact ascending 0..18 with explicit case 8 (sltiu 0x13 off jtbl_00749720). */
/*   MAC WALL LIFTED (b210 probe /tmp/mac_probe.o): plain a*b+c*d emits mula+madd; t+5.0f*(f/10.0f) */
/*   emits div+adda+madd exactly retail's shape (probe $f0 dest vs retail $f20/$f13 = regalloc); t+f/2.0f */
/*   emits div+add with NO mac -- so preserve the 5.0f*(x/10.0f) spelling retail shows (10.0f/5.0f in */
/*   listing), never fold to /2, and term order per code1_001e.c (c1=mula). Cases 2/5/9/11 ALL WRITABLE */
/*   plain C (~5400 instrs); prior BLOCKED refusals stand as correct at the time (m2c M2C_ERROR hid it). */
/*   m2c WARNING (retail is ground truth, both directions): case 12 had a block SPLICED IN from case 2 */
/*   (1A8/1AC with D290/298, (f32)-0x125, 2a60 0,0,0,0xFF + unk79; absent from 878-line retail case12.s); */
/*   case 3 had a tail SILENTLY DROPPED (else-if 4C/44/48 + 0x24 + =4 mirror, truncated from m2c view). */
/*   Insertions and omissions are equally likely here -- check for extra blocks AND for missing tails; */
/*   different reading habits. Outstanding (3, ALL WRITABLE plain C): 2 (806) next, 5 (701), 11 */
/*   (2457) last. MAC spelling rule above (5.0f*(/10.0f), term order c1=mula) applies to all three. */
/*   RATIO-BREAK AS DETECTOR: case 3 shipped +931 real instructions looking like success; only -10.6% */
/*   vs the -2% baseline from five arms (now -12/-9/-18/-25/-7) said otherwise. Without per-arm span */
/*   measurement there would have been nothing to compare against and the truncated mirror would have */
/*   shipped -- argument for measuring every arm against its span, not once at the end. SHORTFALL stays */
/*   ~-2% distributed (~1/50); REFUTED D-table (12 uses flat at 7658/7939/3142) kept below. Next: 2 (806). */
/*   CASE 3 fix: +85 via tail mirror (d320 4C/44/48 x2 check; d310 25=25 killed folding first), now -25. */
/*   Checked 12/13/14 for mirror shape: none has if/else-if identical tails, fix local to 3. Prior kept. */
/* The shared SDK update signature accepts func_00332bb0 directly at the
   func_0033be40 registration site. */
// FUN_00332BB0 NONMATCHING
#ifdef NON_MATCHING
s32 func_00332bb0(u8 *arg0) {
    u8 *work;
    void *tmp;
    s8 state;
    s64 g;
    s64 h;
    s32 i;
    s32 k;
    s32 cw;
    char fbuf[32];
    s8 sel;
    s64 act;
    f32 f0;
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
        if (func_0046a750(*(s32 *)(work + 0xC)) != 0 && H_Cdvd_IsFileLoaded(*(void **)(work + 0x428)) != 0) {
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
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 4) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                tmp = (void *)(work + k * 4 + 0x188);
                *(void **)tmp = func_0033d130(arg0, 0x28, *(s32 *)(work + 0xC));
                func_0033d320(*(void **)tmp, 13, 0);
                func_0033d4e0(*(void **)tmp, 0, 0, 0, 0.0f, 0.0f);
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            *(void **)(work + 0x19C) = func_0033d130(arg0, 0x46, *(s32 *)(work + 0xC));
            *(void **)(work + 0x198) = func_0033d130(arg0, 0x46, *(s32 *)(work + 0xC));
            *(void **)(work + 0x1A0) = func_0033d130(arg0, 0x46, *(s32 *)(work + 0xC));
            *(void **)(work + 0x1A4) = func_0033d130(arg0, 0x46, *(s32 *)(work + 0xC));
            *(void **)(work + 0x1A8) = func_0033d130(arg0, 0x40, *(s32 *)(work + 0xC));
            *(void **)(work + 0x1AC) = func_0033d130(arg0, 0x41, *(s32 *)(work + 0xC));
            if (func_002e2670() >= 6) {
                *(f32 *)(work + 0x420) = 108.0f / (f32)(func_002e2670() - 5);
            }
            *(s8 *)(work + 9) = 0;
            if ((s8)func_00110a60((s32)(func_002e78a0() & 0xFF), (s32)(func_002e78e0() & 0xFF)) == 1) {
                *(s8 *)(work + 9) = 1;
            }
        }
        break;
    case 2:
        i = 0;
        while ((s16)i < 0x24) {
            *(s8 *)(work + (s16)i + 0x2D8) = 1;
            i = (s16)(i + 1);
        }
        func_0033d320((void *)*(s32 *)(work + 0x110), 0, 0);
        p0 = func_002b2970(D_0064A090[0], D_0064A090[1]);
        p1 = func_002b2970(D_0064A090[0], D_0064A090[1]);
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
        *(s16 *)(work + 0x3D4) = func_002b2d00((s32)*(s16 *)(work + 0x3D4), 1, 0, 0, 1);
        if (((s64)((s64)*(s16 *)(work + 0x3D4) << 0x30) >> 0x30) == 0) {
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 0x24) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                *(u8 *)(work + k + 0x2B4) = (u8)func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
                if (*(s8 *)(work + k + 0x2D8) == 1) {
                    p0 = func_002b2970(23.0f, 225.0f);
                    *(f32 *)(work + k * 4 + 0x2FC) = func_0033d630(p0, (s32)(((s64)(k * 10) << 0x30) >> 0x30), (s32)*(u8 *)(work + k + 0x2B4), 1, *(f32 *)(work + 0x2A8));
                }
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 720.0f);
            *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), (s32)*(s16 *)(work + 0x41E), 0x2D0, 1, 2);
            *(s32 *)(work + 0x2B0) = func_002b2cb0(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        }
        i = 0;
        while ((s16)i < 4) {
            if (func_0033d390((void *)*(s32 *)(work + (s16)i * 4 + 0x1C), 2) == 0) {
                func_0033d3d0((void *)*(s32 *)(work + (s16)i * 4 + 0x1C), 0xAB);
            }
            i = (s16)(i + 1);
        }
        if (func_0033d390((void *)*(s32 *)(work + 0xB0), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0xB0), 4) == 0) {
            func_0033d320((void *)*(s32 *)(work + 0x58), 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x58), 80.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x58), 0x3D);
            func_0033d320((void *)*(s32 *)(work + 0x5C), 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x5C), 81.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x5C), 0x3D);
            func_0033d320((void *)*(s32 *)(work + 0x118), 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x118), 82.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x118), 0x3E);
            p0 = func_002b2970(D_0064A2A0[0], D_0064A2A0[1] + (f32)(*(s8 *)(work + 1) * 0x1E));
            p1 = func_002b2970(D_0064A2A0[0], D_0064A2A0[1] + (f32)(*(s8 *)(work + 1) * 0x1E));
            func_0033d3e0((void *)*(s32 *)(work + 0x118), p0, p1, 0, 0, 0);
            func_0033d320((void *)*(s32 *)(work + 0x11C), 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x11C), 83.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x11C), 0x3E);
            p0 = func_002b2970(D_0064A2A8[0], D_0064A2A8[1] + (f32)(*(s8 *)(work + 1) * 0x1E));
            p1 = func_002b2970(D_0064A2A8[0], D_0064A2A8[1] + (f32)(*(s8 *)(work + 1) * 0x1E));
            func_0033d3e0((void *)*(s32 *)(work + 0x11C), p0, p1, 0, 0, 0);
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 6) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x40), 0, 1);
                func_0033d3c0((void *)*(s32 *)(work + k * 4 + 0x40), (f32)(k + 0x4A));
                func_0033d3d0((void *)*(s32 *)(work + k * 4 + 0x40), 0x3F);
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            func_0033d320((void *)*(s32 *)(work + 0x4C), 0, 0);
            func_0033d320((void *)*(s32 *)(work + 0x44), 0, 0);
            func_0033d320((void *)*(s32 *)(work + 0x48), 0, 0);
            h = 0;
            while (((s64)(h << 0x30) >> 0x30) < 0x24) {
                k = (s32)((s64)(h << 0x30) >> 0x30);
                f0 = *(f32 *)(work + k * 4 + 0x2FC);
                if (!(f0 < 140.0f) && (f0 < 340.0f)) {
                    *(s8 *)(work + k + 0x2D8) = 0;
                } else if (!(f0 < 140.0f)) {
                    *(s16 *)(work + k * 2 + 0x38C) = (s16)((f0 - 340.0f) / 10.0f);
                } else {
                    *(s16 *)(work + k * 2 + 0x38C) = (s16)((20.0f + f0) / 10.0f);
                }
                *(s16 *)(work + k * 2 + 0x3D6) = 0;
                *(s32 *)(work + 0x2B0) = 0;
                h = (s64)(((s64)(h << 0x30) >> 0x30) + 1);
            }
            *(s8 *)(work + 0) = 4;
        } else if ((D_008C024E[0] & 0x40) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x80)) {
            p0 = func_002b2970(200.0f + D_0064A290[0], D_0064A290[1]);
            tmp = func_0033d310((void *)*(s32 *)(work + 0x1A8));
            *(f32 *)((u8 *)tmp + 0x2C) = p0.x;
            *(f32 *)((u8 *)tmp + 0x30) = p0.y;
            func_0033d320((void *)*(s32 *)(work + 0x1A8), 1, 1);
            p0 = func_002b2970(200.0f + D_0064A298[0], D_0064A298[1]);
            tmp = func_0033d310((void *)*(s32 *)(work + 0x1AC));
            *(f32 *)((u8 *)tmp + 0x2C) = p0.x;
            *(f32 *)((u8 *)tmp + 0x30) = p0.y;
            func_0033d320((void *)*(s32 *)(work + 0x1AC), 1, 1);
            p0 = func_002b2970(D_0064A090[0], D_0064A094[0]);
            tmp = func_0033d310((void *)*(s32 *)(work + 0x10));
            *(f32 *)((u8 *)tmp + 0x2C) = p0.x;
            *(f32 *)((u8 *)tmp + 0x30) = p0.y;
            *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0x10)) + 0xC4) = 0.0f;
            func_0033d320((void *)*(s32 *)(work + 0x10), 1, 1);
            func_0033d320((void *)*(s32 *)(work + 0x10), 3, 1);
            *(u8 *)(func_0033d310((void *)*(s32 *)(work + 0x164)) + 0x62) = 0xFF;
            *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0x164)) + 0x94) = 1.0f;
            *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0x164)) + 0xA0) = 1.0f;
            p0 = func_002b2970(D_0064A338[0], D_0064A338[1]);
            tmp = func_0033d310((void *)*(s32 *)(work + 0x164));
            *(f32 *)((u8 *)tmp + 0x2C) = p0.x;
            *(f32 *)((u8 *)tmp + 0x30) = p0.y;
            func_0033d320((void *)*(s32 *)(work + 0x164), 2, 1);
            func_0033d320((void *)*(s32 *)(work + 0x164), 1, 1);
            func_0033d320((void *)*(s32 *)(work + 0x164), 4, 1);
            *(u8 *)(func_0033d310((void *)*(s32 *)(work + 0xB0)) + 0x62) = 0xFF;
            *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xB0)) + 0x94) = 1.0f;
            *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xB0)) + 0xA0) = 1.0f;
            func_0033d320((void *)*(s32 *)(work + 0xB0), 2, 1);
            func_0033d320((void *)*(s32 *)(work + 0xB0), 4, 1);
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 3) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                *(u8 *)(func_0033d310((void *)*(s32 *)(work + k * 4 + 0x17C)) + 0x62) = 0xFF;
                *(f32 *)(func_0033d310((void *)*(s32 *)(work + k * 4 + 0x17C)) + 0x94) = 1.0f;
                *(f32 *)(func_0033d310((void *)*(s32 *)(work + k * 4 + 0x17C)) + 0xA0) = 1.0f;
                *(f32 *)(func_0033d310((void *)*(s32 *)(work + k * 4 + 0x17C)) + 0xC4) = (f32)((k + 1) * 0x5A);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x17C), 2, 1);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x17C), 3, 1);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x17C), 4, 1);
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            *(f32 *)(work + 0x1E0) = 580.0f - (f32)func_002b3170(func_002e7a60()) * 21.0f;
            *(s32 *)(work + 0x1E4) = 0x41700000;
            *(s16 *)(work + 0x1EA) = 0xA;
            p0 = func_002b2970(D_0064A1D8[0], D_0064A1D8[1]);
            tmp = func_0033d310((void *)*(s32 *)(work + 0xB4));
            *(f32 *)((u8 *)tmp + 0x2C) = p0.x;
            *(f32 *)((u8 *)tmp + 0x30) = p0.y;
            func_0033d320((void *)*(s32 *)(work + 0xB4), 1, 1);
            p0 = func_002b2970(D_0064A1E0[0], D_0064A1E0[1]);
            tmp = func_0033d310((void *)*(s32 *)(work + 0xB8));
            *(f32 *)((u8 *)tmp + 0x2C) = p0.x;
            *(f32 *)((u8 *)tmp + 0x30) = p0.y;
            func_0033d320((void *)*(s32 *)(work + 0xB8), 1, 1);
            p0 = func_002b2970(153.0f, D_0064A1E8[1]);
            tmp = func_0033d310((void *)*(s32 *)(work + 0xBC));
            *(f32 *)((u8 *)tmp + 0x2C) = p0.x;
            *(f32 *)((u8 *)tmp + 0x30) = p0.y;
            func_0033d320((void *)*(s32 *)(work + 0xBC), 1, 1);
            p0 = func_002b2970(203.0f, D_0064A1E8[1]);
            tmp = func_0033d310((void *)*(s32 *)(work + 0x178));
            *(f32 *)((u8 *)tmp + 0x2C) = p0.x;
            *(f32 *)((u8 *)tmp + 0x30) = p0.y;
            func_0033d320((void *)*(s32 *)(work + 0x178), 1, 1);
            *(u8 *)(func_0033d310((void *)*(s32 *)(work + 0x3C)) + 0x62) = 0xFF;
            func_0033d320((void *)*(s32 *)(work + 0x3C), 2, 1);
            *(u8 *)(func_0033d310((void *)*(s32 *)(work + 0x14)) + 0x62) = 0xFF;
            func_0033d320((void *)*(s32 *)(work + 0x14), 2, 1);
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 4) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                p0 = func_002b2970(D_0064A090[(k + 3) * 2], D_0064A090[(k + 3) * 2 + 1]);
                tmp = func_0033d310((void *)*(s32 *)(work + k * 4 + 0x1C));
                *(f32 *)((u8 *)tmp + 0x2C) = p0.x;
                *(f32 *)((u8 *)tmp + 0x30) = p0.y;
                *(f32 *)(func_0033d310((void *)*(s32 *)(work + k * 4 + 0x1C)) + 0x94) = 1.0f;
                *(f32 *)(func_0033d310((void *)*(s32 *)(work + k * 4 + 0x1C)) + 0xA0) = 1.0f;
                *(u8 *)(func_0033d310((void *)*(s32 *)(work + k * 4 + 0x1C)) + 0x62) = 0xFF;
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x1C), 2, 1);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x1C), 1, 1);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x1C), 4, 1);
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            h = 0;
            while (((s64)(h << 0x30) >> 0x30) < 0x24) {
                k = (s32)((s64)(h << 0x30) >> 0x30);
                *(u8 *)(work + k + 0x2B4) = 0xFF;
                *(s8 *)(work + k + 0x2D8) = 1;
                h = (s64)(((s64)(h << 0x30) >> 0x30) + 1);
            }
            func_0033d320((void *)*(s32 *)(work + 0x58), 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x58), 80.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x58), 0x3D);
            func_0033d320((void *)*(s32 *)(work + 0x5C), 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x5C), 81.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x5C), 0x3D);
            func_0033d320((void *)*(s32 *)(work + 0x118), 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x118), 82.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x118), 0x3E);
            p0 = func_002b2970(D_0064A2A0[0], D_0064A2A0[1] + (f32)(*(s8 *)(work + 1) * 0x1E));
            p1 = func_002b2970(D_0064A2A0[0], D_0064A2A0[1] + (f32)(*(s8 *)(work + 1) * 0x1E));
            func_0033d3e0((void *)*(s32 *)(work + 0x118), p0, p1, 0, 0, 0);
            func_0033d320((void *)*(s32 *)(work + 0x11C), 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x11C), 83.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x11C), 0x3E);
            p0 = func_002b2970(D_0064A2A8[0], D_0064A2A8[1] + (f32)(*(s8 *)(work + 1) * 0x1E));
            p1 = func_002b2970(D_0064A2A8[0], D_0064A2A8[1] + (f32)(*(s8 *)(work + 1) * 0x1E));
            func_0033d3e0((void *)*(s32 *)(work + 0x11C), p0, p1, 0, 0, 0);
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 6) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x40), 0, 1);
                func_0033d3c0((void *)*(s32 *)(work + k * 4 + 0x40), (f32)(k + 0x4A));
                func_0033d3d0((void *)*(s32 *)(work + k * 4 + 0x40), 0x3F);
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            func_0033d320((void *)*(s32 *)(work + 0x4C), 0, 0);
            func_0033d320((void *)*(s32 *)(work + 0x44), 0, 0);
            func_0033d320((void *)*(s32 *)(work + 0x48), 0, 0);
            h = 0;
            while (((s64)(h << 0x30) >> 0x30) < 0x24) {
                k = (s32)((s64)(h << 0x30) >> 0x30);
                f0 = *(f32 *)(work + k * 4 + 0x2FC);
                if (!(f0 < 140.0f) && (f0 < 340.0f)) {
                    *(s8 *)(work + k + 0x2D8) = 0;
                } else if (!(f0 < 140.0f)) {
                    *(s16 *)(work + k * 2 + 0x38C) = (s16)((f0 - 340.0f) / 10.0f);
                } else {
                    *(s16 *)(work + k * 2 + 0x38C) = (s16)((20.0f + f0) / 10.0f);
                }
                *(s16 *)(work + k * 2 + 0x3D6) = 0;
                *(s32 *)(work + 0x2B0) = 0;
                h = (s64)(((s64)(h << 0x30) >> 0x30) + 1);
            }
            *(s8 *)(work + 0) = 4;
        }
        break;
    case 4:
        *(f32 *)(work + 0x1E0) = func_002b2aa0(0, *(f32 *)(work + 0x1D0), *(f32 *)(work + 0x1D8), (f32)*(s16 *)(work + 0x1EA), 10.0f);
        *(s16 *)(work + 0x1EA) = func_002b2cb0((s32)*(s16 *)(work + 0x1EA), 1, 0xA, 1, 1);
        g = 0;
        while (((s64)(g << 0x30) >> 0x30) < 0x24) {
            k = (s32)((s64)(g << 0x30) >> 0x30);
            if (*(s8 *)(work + k + 0x2D8) == 1) {
                *(s16 *)(work + k * 2 + 0x38C) = func_002b2d00((s32)*(s16 *)(work + k * 2 + 0x38C), 1, 0, 0, 1);
                if (((s64)((s64)*(s16 *)(work + k * 2 + 0x38C) << 0x30) >> 0x30) == 0) {
                    *(u8 *)(work + k + 0x2B4) = (u8)func_002b2aa0(0, 255.0f, 0.0f, (f32)*(s16 *)(work + k * 2 + 0x3D6), 15.0f);
                    *(s16 *)(work + k * 2 + 0x3D6) = func_002b2cb0((s32)*(s16 *)(work + k * 2 + 0x3D6), 1, 0xF, 1, 1);
                }
                p0 = func_002b2970(23.0f, 225.0f);
                *(f32 *)(work + k * 4 + 0x2FC) = func_0033d630(p0, (s32)(((s64)(k * 10) << 0x30) >> 0x30), (s32)*(u8 *)(work + k + 0x2B4), 1, *(f32 *)(work + 0x2A8));
            }
            g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
        }
        *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 720.0f);
        *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), (s32)*(s16 *)(work + 0x41E), 0x2D0, 1, 2);
        h = 0;
        act = 0;
        while (((s64)(h << 0x30) >> 0x30) < 0x24) {
            k = (s32)((s64)(h << 0x30) >> 0x30);
            f0 = *(f32 *)(work + k * 4 + 0x2FC);
            if (!(f0 < 140.0f) && (f0 < 340.0f)) {
                *(s8 *)(work + k + 0x2D8) = 0;
            } else if (*(s16 *)(work + k * 2 + 0x3D6) == 0xF) {
                *(s8 *)(work + k + 0x2D8) = 0;
            }
            if (*(s8 *)(work + k + 0x2D8) == 1) {
                act = 1;
            }
            h = (s64)(((s64)(h << 0x30) >> 0x30) + 1);
        }
        if (((s64)(act << 0x38) >> 0x38) == 0) {
            func_0033d320((void *)*(s32 *)(work + 0x60), 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x60), 14.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x60), 0x64);
            func_0033d320((void *)*(s32 *)(work + 0x164), 0, 1);
            *(s32 *)(work + 0x2AC) = 0;
            *(s8 *)(work + 0) = 5;
            if (*(s8 *)(work + 0x424) == 1) {
                sel = func_002bab80(*(s32 *)(*(s32 *)(work + 0x428) + 0x110));
                *(s8 *)(work + 8) = sel;
                func_002badc0((s32)sel, 2);
                *(s8 *)(work + 0) = 6;
            } else if (*(s8 *)(work + 9) == 1) {
                sel = func_002bab80(*(s32 *)(*(s32 *)(work + 0x428) + 0x110));
                *(s8 *)(work + 8) = sel;
                func_002badc0((s32)sel, 3);
                *(s8 *)(work + 0) = 7;
            } else {
                sel = func_002bab80(*(s32 *)(*(s32 *)(work + 0x428) + 0x110));
                *(s8 *)(work + 8) = sel;
                func_002badc0((s32)sel, 4);
                *(s8 *)(work + 0) = 7;
            }
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
        if (func_002bb680(*(s8 *)(work + 8)) != 0) {
            func_002bbcf0(*(s8 *)(work + 8));
        } else {
            func_002bb550(*(s8 *)(work + 8));
            *(s8 *)(work + 0) = 5;
            if (*(s8 *)(work + 9) == 1) {
                sel = func_002bab80(*(s32 *)(*(s32 *)(work + 0x428) + 0x110));
                *(s8 *)(work + 8) = sel;
                func_002badc0((s32)sel, 3);
                *(s8 *)(work + 0) = 7;
            }
        }
        break;
    case 7:
        if (func_002bb680(*(s8 *)(work + 8)) != 0) {
            func_002bbcf0(*(s8 *)(work + 8));
        } else {
            func_002bb550(*(s8 *)(work + 8));
            *(s8 *)(work + 0) = 5;
        }
        break;
    case 8:
        /* shares the default block in retail (.L0033BD80) - kept explicit so the switch still spans 0..18 and mwcc emits sltiu 0x13. */
        break;
    case 9:
        if (func_0033d390((void *)*(s32 *)(work + 0x14), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x1C), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x1C), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x1C), 1) == 0 && func_0033d390((void *)*(s32 *)(work + 0x20), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x20), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x20), 1) == 0 && func_0033d390((void *)*(s32 *)(work + 0x24), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x24), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x24), 1) == 0 && func_0033d390((void *)*(s32 *)(work + 0x28), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x28), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x28), 1) == 0) {
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 6) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x40), 0, 1);
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            func_0033d320((void *)*(s32 *)(work + 0x58), 0, 1);
            func_0033d320((void *)*(s32 *)(work + 0x5C), 0, 1);
            func_0033d320((void *)*(s32 *)(work + 0x118), 0, 1);
            func_0033d320((void *)*(s32 *)(work + 0x11C), 0, 1);
            func_0033d320((void *)*(s32 *)(work + 0x110), 0, 1);
            func_0033d320((void *)*(s32 *)(work + 0x114), 0, 1);
            func_0033d320((void *)*(s32 *)(work + 0x60), 0, 1);
            func_0033d3d0((void *)*(s32 *)(work + 0xB0), 0x65);
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 3) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                func_0033d3d0((void *)*(s32 *)(work + k * 4 + 0x17C), 0x65);
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            h = 0;
            while (((s64)(h << 0x30) >> 0x30) < 4) {
                k = (s32)((s64)(h << 0x30) >> 0x30);
                tmp = (void *)(work + k * 4 + 0x188);
                func_0033d320(*(void **)tmp, 0xD, 0);
                func_0033d320(*(void **)tmp, 0, 0);
                func_0033d4e0(*(void **)tmp, 0, 0xC, 0, iGpffff8504, iGpffff851c);
                func_0033d520(*(void **)tmp, 0, 0, 0, 0.0f, (f32)(k * 0x5A));
                func_0033d3c0(*(void **)tmp, 1.0f);
                func_0033d3d0(*(void **)tmp, 0x64);
                *(s16 *)(func_0033d310(*(void **)tmp) + 0x102) = 0;
                *(s16 *)(func_0033d310(*(void **)tmp) + 0x100) = 0;
                *(u8 *)(func_0033d310(*(void **)tmp) + 0x62) = 2;
                h = (s64)(((s64)(h << 0x30) >> 0x30) + 1);
            }
            func_0033d320((void *)*(s32 *)(work + 0x10), 0, 0);
            p0 = func_002b2970(D_0064A090[0], D_0064A094[0]);
            p1 = func_002b2970(428.0f, 241.0f);
            func_0033d3e0((void *)*(s32 *)(work + 0x10), p0, p1, 0, 0xF, 0);
            func_0033d520((void *)*(s32 *)(work + 0x10), 0, 0xF, 0, -360.0f, 0.0f);
            func_0033d320((void *)*(s32 *)(work + 0x158), 0, 0);
            func_0033d4b0((void *)*(s32 *)(work + 0x158), 0, 0xFF, 0, 0, 0xF);
            func_0033d4e0((void *)*(s32 *)(work + 0x158), 0, 8, 0xF, iGpffff8504, 1.0f);
            func_0033d3c0((void *)*(s32 *)(work + 0x158), 45.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x158), 0x5B);
            tmp = func_0046d200((void *)*(s32 *)(work + 0xC), 0x52);
            p0 = func_002b2970(D_0064A320[0] + 5.0f * (func_0046b260(tmp) / 10.0f), D_0064A320[1] + 5.0f * (func_0046b2f0(tmp) / 10.0f));
            p1 = func_002b2970(D_0064A320[0], D_0064A320[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0x158), p0, p1, 0, 8, 0xF);
            func_0046d280(tmp);
            func_0033d320((void *)*(s32 *)(work + 0xC8), 0, 0);
            p0 = func_002b2970(660.0f, D_0064A200[1]);
            p1 = func_002b2970(D_0064A200[0], D_0064A200[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0xC8), p0, p1, 1, 0x14, 5);
            func_0033d3c0((void *)*(s32 *)(work + 0xC8), 42.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xC8), 0x61);
            func_0033d320((void *)*(s32 *)(work + 0xC0), 0, 0);
            p0 = func_002b2970(660.0f, D_0064A1F0[1]);
            p1 = func_002b2970(D_0064A1F0[0], D_0064A1F0[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0xC0), p0, p1, 0, 8, 5);
            func_0033d3c0((void *)*(s32 *)(work + 0xC0), 43.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xC0), 0x61);
            func_0033d320((void *)*(s32 *)(work + 0xC4), 0, 0);
            p0 = func_002b2970(980.0f, D_0064A1F8[1]);
            p1 = func_002b2970(D_0064A1F8[0], D_0064A1F8[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0xC4), p0, p1, 0, 8, 5);
            func_0033d520((void *)*(s32 *)(work + 0xC4), 0, 0, 0, 0.0f, -90.0f);
            *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xC4)) + 0xC4) = -90.0f;
            *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xC4)) + 0xC0) = -90.0f;
            *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xC4)) + 0xBC) = -90.0f;
            func_0033d3c0((void *)*(s32 *)(work + 0xC4), 44.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xC4), 0x61);
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 4) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x2C), 0, 0);
                func_0033d4e0((void *)*(s32 *)(work + k * 4 + 0x2C), 0, 5, (k * 3) + 0xF, iGpffff809c, 1.0f);
                func_0033d4b0((void *)*(s32 *)(work + k * 4 + 0x2C), 0, 0xFF, 0, 5, (k * 3) + 0xF);
                func_0033d3c0((void *)*(s32 *)(work + k * 4 + 0x2C), (f32)(k + 0x1A));
                func_0033d3d0((void *)*(s32 *)(work + k * 4 + 0x2C), 0x63);
                tmp = func_0046d200((void *)*(s32 *)(work + 0xC), k + 7);
                p0 = func_002b2970(D_0064A090[(k + 7) * 2] + 5.0f * (func_0046b260(tmp) / 10.0f), D_0064A090[(k + 7) * 2 + 1] + 5.0f * (func_0046b2f0(tmp) / 10.0f));
                p1 = func_002b2970(D_0064A090[(k + 7) * 2], D_0064A090[(k + 7) * 2 + 1]);
                func_0033d3e0((void *)*(s32 *)(work + k * 4 + 0x2C), p0, p1, 0, 5, (k * 3) + 0xF);
                func_0046d280(tmp);
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            func_0033d320((void *)*(s32 *)(work + 0x18), 0, 0);
            func_0033d4b0((void *)*(s32 *)(work + 0x18), 0, 0xFF, 0, 0x14, 0xA);
            func_0033d3c0((void *)*(s32 *)(work + 0x18), 21.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x18), 0x64);
            func_0033d320((void *)*(s32 *)(work + 0xCC), 0, 0);
            p0 = func_002b2970(660.0f, D_0064A208[1]);
            p1 = func_002b2970(D_0064A208[0], D_0064A208[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0xCC), p0, p1, 1, 0xA, 5);
            func_0033d3c0((void *)*(s32 *)(work + 0xCC), 68.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xCC), 0x5B);
            func_0033d320((void *)*(s32 *)(work + 0xD0), 0, 0);
            p0 = func_002b2970(1064.0f, D_0064A210[1]);
            p1 = func_002b2970(D_0064A210[0], D_0064A210[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0xD0), p0, p1, 1, 0xA, 5);
            func_0033d3c0((void *)*(s32 *)(work + 0xD0), 60.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xD0), 0x5B);
            func_0033d320((void *)*(s32 *)(work + 0xD4), 0, 0);
            p0 = func_002b2970(1064.0f, D_0064A218[1]);
            p1 = func_002b2970(D_0064A218[0], D_0064A218[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0xD4), p0, p1, 1, 0xA, 5);
            func_0033d3c0((void *)*(s32 *)(work + 0xD4), 59.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xD4), 0x5B);
            func_0033d320((void *)*(s32 *)(work + 0x150), 0, 0);
            func_0033d4b0((void *)*(s32 *)(work + 0x150), 0, 0xFF, 0, 0, 0xA);
            func_0033d3c0((void *)*(s32 *)(work + 0x150), 56.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0x150), 0x5B);
            func_0033d320((void *)*(s32 *)(work + 0x198), 0, 0);
            func_0033d4b0((void *)*(s32 *)(work + 0x198), 0, 0xFF, 0, 0, 0xA);
            p0 = func_002b2970((f32)0x243, 185.0f);
            p1 = func_002b2970((f32)0x243, 185.0f);
            func_0033d3e0((void *)*(s32 *)(work + 0x198), p0, p1, 0, 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x198), 57.0f);
            *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x198)) + 0xF8) = (s16)(((func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF) % 10) + 0x46);
            func_0033d3d0((void *)*(s32 *)(work + 0x198), 0x5B);
            *(FclDrawColor *)&cw = func_002b2a60(0x7E, 0, 8, 0xFF);
            tmp = func_0033d310((void *)*(s32 *)(work + 0x198));
            *(u8 *)((u8 *)tmp + 0x79) = *(u8 *)&cw;
            *(u8 *)((u8 *)tmp + 0x7A) = *((u8 *)&cw + 1);
            *(u8 *)((u8 *)tmp + 0x7B) = *((u8 *)&cw + 2);
            *(u8 *)((u8 *)tmp + 0x7C) = *((u8 *)&cw + 3);
            func_0033d320((void *)*(s32 *)(work + 0x19C), 0, 0);
            func_0033d4b0((void *)*(s32 *)(work + 0x19C), 0, 0xFF, 0, 0, 0xA);
            p0 = func_002b2970(552.0f, 185.0f);
            p1 = func_002b2970(552.0f, 185.0f);
            func_0033d3e0((void *)*(s32 *)(work + 0x19C), p0, p1, 0, 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x19C), 57.0f);
            *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x19C)) + 0xF8) = (s16)(((func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF) / 10) + 0x46);
            func_0033d3d0((void *)*(s32 *)(work + 0x19C), 0x5B);
            *(FclDrawColor *)&cw = func_002b2a60(0x7E, 0, 8, 0xFF);
            tmp = func_0033d310((void *)*(s32 *)(work + 0x19C));
            *(u8 *)((u8 *)tmp + 0x79) = *(u8 *)&cw;
            *(u8 *)((u8 *)tmp + 0x7A) = *((u8 *)&cw + 1);
            *(u8 *)((u8 *)tmp + 0x7B) = *((u8 *)&cw + 2);
            *(u8 *)((u8 *)tmp + 0x7C) = *((u8 *)&cw + 3);
            if (((func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF) / 10) == 0) {
                func_0033d320((void *)*(s32 *)(work + 0x19C), 0, 1);
                p0 = func_002b2970((f32)0x243, 185.0f);
                p1 = func_002b2970((f32)0x243, 185.0f);
                func_0033d3e0((void *)*(s32 *)(work + 0x198), p0, p1, 0, 0, 0);
            }
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 4) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                func_0033d320((void *)*(s32 *)(work + k * 4 + 0x64), 0, 0);
                func_0033d4b0((void *)*(s32 *)(work + k * 4 + 0x64), 0, 0xFF, 0, 0xA, 0x19);
                func_0033d3c0((void *)*(s32 *)(work + k * 4 + 0x64), 15.0f);
                func_0033d3d0((void *)*(s32 *)(work + k * 4 + 0x64), 0x64);
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            func_0033d320((void *)*(s32 *)(work + 0x70), 0, 1);
            func_0033d320((void *)*(s32 *)(work + 0xDC), 0, 1);
            p0 = func_002b2970(D_0064A228[0], D_0064A228[1]);
            p1 = func_002b2970(D_0064A228[0], D_0064A228[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0xDC), p0, p1, 0, 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0xDC), 66.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xDC), 0x5B);
            func_0033d320((void *)*(s32 *)(work + 0xE0), 0, 1);
            p0 = func_002b2970(D_0064A230[0], D_0064A230[1]);
            p1 = func_002b2970(D_0064A230[0], D_0064A230[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0xE0), p0, p1, 0, 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0xE0), 67.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xE0), 0x5B);
            func_0033d320((void *)*(s32 *)(work + 0xD8), 0, 1);
            p0 = func_002b2970(D_0064A220[0], D_0064A220[1]);
            p1 = func_002b2970(D_0064A220[0], D_0064A220[1]);
            func_0033d3e0((void *)*(s32 *)(work + 0xD8), p0, p1, 0, 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0xD8), 61.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xD8), 0x5B);
            if (*(s8 *)(work + 0x424) == 1) {
                tmp = func_0046d200((void *)*(s32 *)(work + 0xC), 0x51);
                func_0033d320((void *)*(s32 *)(work + 0x154), 0, 0);
                p0 = func_002b2970(D_0064A318[0], D_0064A318[1]);
                p1 = func_002b2970(D_0064A318[0], D_0064A318[1]);
                func_0033d3e0((void *)*(s32 *)(work + 0x154), p0, p1, 0, 0, 0);
                func_0033d520((void *)*(s32 *)(work + 0x154), 0, 7, 0xA, -90.0f, 0.0f);
                func_0033d3c0((void *)*(s32 *)(work + 0x154), 40.0f);
                func_0033d3d0((void *)*(s32 *)(work + 0x154), 0x62);
                *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x154)) + 0x100) = 0;
                *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x154)) + 0x102) = (s16)func_0046b2f0(tmp);
                func_0046d280(tmp);
            }
            if (*(s8 *)(work + 9) == 1) {
                func_0033d320((void *)*(s32 *)(work + 0x168), 0, 0);
                p0 = func_002b2970(D_0064A340[0], D_0064A340[1]);
                p1 = func_002b2970(D_0064A340[0], D_0064A340[1]);
                func_0033d3e0((void *)*(s32 *)(work + 0x168), p0, p1, 0, 0, 0);
                func_0033d520((void *)*(s32 *)(work + 0x168), 0, 0xA, 0x1B, 150.0f, 0.0f);
                *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x168)) + 0x100) = (s16)((f32)0x231 - D_0064A340[0]);
                *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x168)) + 0x102) = (s16)(470.0f - D_0064A340[1]);
                func_0033d3c0((void *)*(s32 *)(work + 0x168), 24.0f);
                func_0033d3d0((void *)*(s32 *)(work + 0x168), 0x63);
                func_0033d320((void *)*(s32 *)(work + 0x16C), 0, 0);
                p0 = func_002b2970(D_0064A348[0], D_0064A348[1]);
                p1 = func_002b2970(D_0064A348[0], D_0064A348[1]);
                func_0033d3e0((void *)*(s32 *)(work + 0x16C), p0, p1, 0, 0, 0);
                func_0033d4b0((void *)*(s32 *)(work + 0x16C), 0xFF, 0x33, 0, 0x14, 0x34);
                func_0033d4e0((void *)*(s32 *)(work + 0x16C), 0, 0, 0x25, 0.0f, 1.0f);
                *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0x16C)) + 0xC4) = 0.0f;
                func_0033d3c0((void *)*(s32 *)(work + 0x16C), 23.0f);
                func_0033d3d0((void *)*(s32 *)(work + 0x16C), 0x63);
                tmp = func_0046d200((void *)*(s32 *)(work + 0xC), 0x58);
                p0 = func_002b2970(D_0064A350[0] + (func_0046b260(tmp) / 2.0f), D_0064A350[1] + (func_0046b2f0(tmp) / 2.0f));
                p1 = func_002b2970(D_0064A350[0] - 4.0f, D_0064A350[1] - 3.0f);
                func_0033d3e0((void *)*(s32 *)(work + 0x170), p0, p1, 0, 5, 0x23);
                func_0033d4e0((void *)*(s32 *)(work + 0x170), 2, 5, 0x23, 0.0f, iGpffff84cc);
                func_0033d4b0((void *)*(s32 *)(work + 0x170), 0, 0xFF, 0, 0, 0x23);
                *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0x170)) + 0xC4) = 0.0f;
                func_0033d3c0((void *)*(s32 *)(work + 0x170), 22.0f);
                func_0033d3d0((void *)*(s32 *)(work + 0x170), 0x63);
                func_0046d280(tmp);
                func_0033d320((void *)*(s32 *)(work + 0x174), 0, 0);
                p0 = func_002b2970((f32)0x113 + D_0064A358[0], D_0064A358[1]);
                p1 = func_002b2970(D_0064A358[0], D_0064A358[1] - 120.0f);
                func_0033d420((void *)*(s32 *)(work + 0x174), *(s64 *)&p0, *(s64 *)&p1, 1, 0, 0xE, 0x20);
                *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0x174)) + 0xC4) = 0.0f;
                func_0033d3c0((void *)*(s32 *)(work + 0x174), 9.0f);
                func_0033d3d0((void *)*(s32 *)(work + 0x174), 0x64);
            }
            *(s8 *)(work + 2) = 0;
            *(s8 *)(work + 0) = 0xA;
        }
        break;
    case 10:
        if (func_0033d390((void *)*(s32 *)(work + 0x170), 4) == 0) {
            func_0033d4e0((void *)*(s32 *)(work + 0x170), 0, 0, 0, 0.0f, 1.0f);
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x188), 4) != 0) {
            break;
        }
        func_0033d3d0((void *)*(s32 *)(work + 0xB0), 0x5B);
        i = 0;
        while ((s16)i < 3) {
            func_0033d3d0((void *)*(s32 *)(work + (s16)i * 4 + 0x17C), 0x5B);
            i = (s16)(i + 1);
        }
        i = 0;
        while ((s16)i < 4) {
            func_0033d320((void *)*(s32 *)(work + (s16)i * 4 + 0x188), 0, 1);
            func_0033d320((void *)*(s32 *)(work + (s16)i * 4 + 0x17C), 0, 1);
            i = (s16)(i + 1);
        }
        func_0033d320((void *)*(s32 *)(work + 0xB0), 0, 1);
        *(s32 *)(work + 0x2B0) = 0;
        i = 0;
        while ((s16)i < 0x24) {
            *(s8 *)(work + (s16)i + 0x2D8) = 1;
            i = (s16)(i + 1);
        }
        *(s8 *)(work + 0) = 0xB;
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
        g = 0;
        while (((s64)(g << 0x30) >> 0x30) < 0x24) {
            k = (s32)((s64)(g << 0x30) >> 0x30);
            *(u8 *)(work + k + 0x2B4) = (u8)func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
            if (*(s8 *)(work + k + 0x2D8) == 1) {
                p0 = func_002b2970(400.0f, 220.0f);
                *(f32 *)(work + k * 4 + 0x2FC) = func_0033d630(p0, (s32)(((s64)(k * 10) << 0x30) >> 0x30), (s32)*(u8 *)(work + k + 0x2B4), 0, *(f32 *)(work + 0x2A8));
            }
            g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
        }
        *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), 1, 0x3E8, 1, 2);
        *(s32 *)(work + 0x2B0) = func_002b2cb0(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        p0 = func_002b2970((f32)0x253, 78.0f);
        *(FclDrawColor *)&cw = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        func_002caa10(*(s64 *)&p0, 1.0f, cw, *(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))), 0x35, *(void **)(work + 0xC), 0xAB);
        func_0033c490(arg0);
        *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x198)) + 0xF8) = (s16)(((func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF) % 10) + 0x46);
        func_0033d320((void *)*(s32 *)(work + 0x19C), 0, 0);
        *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x19C)) + 0xF8) = (s16)(((func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF) / 10) + 0x46);
        if (((func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF) / 10) == 0) {
            func_0033d320((void *)*(s32 *)(work + 0x19C), 0, 1);
            p0 = func_002b2970((f32)0x243, 185.0f);
            p1 = func_002b2970((f32)0x243, 185.0f);
            func_0033d3e0((void *)*(s32 *)(work + 0x198), p0, p1, 0, 0, 0);
        }
        if (func_0033d390((void *)*(s32 *)(work + 0xD0), 1) == 0) {
            func_0033d320((void *)*(s32 *)(work + 0x1A0), 0, 0);
            p0 = func_002b2970((f32)0x167, 134.0f);
            p1 = func_002b2970((f32)0x167, 134.0f);
            func_0033d3e0((void *)*(s32 *)(work + 0x1A0), p0, p1, 0, 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x1A0), 57.0f);
            *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x1A0)) + 0xF8) = (s16)((*(s8 *)(work + 3) % 10) + 0x46);
            func_0033d3d0((void *)*(s32 *)(work + 0x1A0), 0x61);
            func_0033d320((void *)*(s32 *)(work + 0x1A4), 0, 0);
            p0 = func_002b2970(332.0f, 134.0f);
            p1 = func_002b2970(332.0f, 134.0f);
            func_0033d3e0((void *)*(s32 *)(work + 0x1A4), p0, p1, 0, 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0x1A4), 57.0f);
            *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x1A4)) + 0xF8) = (s16)((*(s8 *)(work + 3) / 10) + 0x46);
            func_0033d3d0((void *)*(s32 *)(work + 0x1A4), 0x61);
            if (((*(s8 *)(work + 3) / 10) == 0)) {
                func_0033d320((void *)*(s32 *)(work + 0x1A4), 0, 1);
                p0 = func_002b2970(346.0f, 134.0f);
                p1 = func_002b2970(346.0f, 134.0f);
                func_0033d3e0((void *)*(s32 *)(work + 0x1A0), p0, p1, 0, 0, 0);
            }
            func_0033d320((void *)*(s32 *)(work + 0xA0), 0, 0);
            p0 = func_002b2970(45.0f, 133.0f);
            p1 = func_002b2970(45.0f, 133.0f);
            func_0033d3e0((void *)*(s32 *)(work + 0xA0), p0, p1, 0, 0, 0);
            func_0033d3c0((void *)*(s32 *)(work + 0xA0), 53.0f);
            func_0033d3d0((void *)*(s32 *)(work + 0xA0), 0x61);
            i = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            k = func_001067f0((s16)func_002e2740(*(s16 *)(work + 4)));
            func_00275520(82.0f, 132.0f, 58.0f, i, 0, 1, k, 0, 0, D_007950B0);
            if (D_008C024E[0] & 0x40) {
                func_0045af60(0, 0, 0, 1);
                *(s8 *)(work + 8) = func_002bab80(*(s32 *)(*(s32 *)(work + 0x428) + 0x110));
                sprintf(fbuf, &iGpffffa930, *(s8 *)(work + 3));
                func_002bbd80(*(s8 *)(work + 8), 1, fbuf);
                sprintf(fbuf, &iGpffffa930, *(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))));
                func_002bbd80(*(s8 *)(work + 8), 2, fbuf);
                func_002badc0((s32)*(s8 *)(work + 8), 1);
                func_002bafc0(*(s8 *)(work + 8), 0);
                func_002bb0a0(*(s8 *)(work + 8), 0);
                func_002bbf60();
                *(s8 *)(work + 0) = 0xD;
            } else if (D_008C027A[0] & 0x1000) {
                if (*(s8 *)(work + 3) != (0x63 - (func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF))) {
                    func_0045af60(0, 0, 0, 0);
                }
                *(s8 *)(work + 3) = (s8)func_002b2cb0((s32)*(s8 *)(work + 3), 1, (0x63 - (func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF)), 0, 1);
                if (func_002e7a60() < (u32)(*(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))))) {
                    *(s8 *)(work + 3) = (s8)(func_002e7a60() / func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))));
                }
                p0 = func_002b2970(D_0064A328[0], D_0064A328[1]);
                p1 = func_002b2970(D_0064A328[0], D_0064A328[1] - 7.0f);
                func_0033d3e0((void *)*(s32 *)(work + 0x15C), p0, p1, 1, 0xA, 0);
            } else if (D_008C027A[0] & 0x4000) {
                if (*(s8 *)(work + 3) != 1) {
                    func_0045af60(0, 0, 0, 0);
                }
                *(s8 *)(work + 3) = (s8)func_002b2d00((s32)*(s8 *)(work + 3), 1, 1, 0x63, 1);
                p0 = func_002b2970(D_0064A330[0], D_0064A330[1]);
                p1 = func_002b2970(D_0064A330[0], 7.0f + D_0064A330[1]);
                func_0033d3e0((void *)*(s32 *)(work + 0x160), p0, p1, 1, 0xA, 0);
            } else if (D_008C027A[0] & 0x2000) {
                if (*(s8 *)(work + 3) != (0x63 - (func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF))) {
                    func_0045af60(0, 0, 0, 0);
                }
                *(s8 *)(work + 3) = (s8)func_002b2cb0((s32)*(s8 *)(work + 3), 0xA, (0x63 - (func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF)), 0, 1);
                if (func_002e7a60() < (u32)(*(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))))) {
                    *(s8 *)(work + 3) = (s8)(func_002e7a60() / func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))));
                }
                p0 = func_002b2970(D_0064A328[0], D_0064A328[1]);
                p1 = func_002b2970(D_0064A328[0], D_0064A328[1] - 7.0f);
                func_0033d3e0((void *)*(s32 *)(work + 0x15C), p0, p1, 1, 0xA, 0);
            } else if (D_008C027A[0] & 0x8000) {
                if (*(s8 *)(work + 3) != 1) {
                    func_0045af60(0, 0, 0, 0);
                }
                *(s8 *)(work + 3) = (s8)func_002b2d00((s32)*(s8 *)(work + 3), 0xA, 1, 0x63, 1);
                p0 = func_002b2970(D_0064A330[0], D_0064A330[1]);
                p1 = func_002b2970(D_0064A330[0], 7.0f + D_0064A330[1]);
                func_0033d3e0((void *)*(s32 *)(work + 0x160), p0, p1, 1, 0xA, 0);
            } else if (D_008C024E[0] & 0x20) {
                func_0045af60(0, 0, 0, 2);
                p0 = func_002b2970(*(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xD0)) + 0x2C), D_0064A210[1]);
                p1 = func_002b2970(D_0064A210[0], D_0064A210[1]);
                func_0033d3e0((void *)*(s32 *)(work + 0xD0), p0, p1, 0, 7, 0);
                p0 = func_002b2970(*(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xD4)) + 0x2C), *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xD4)) + 0x30));
                p1 = func_002b2970(D_0064A218[0], *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xD4)) + 0x30));
                func_0033d3e0((void *)*(s32 *)(work + 0xD4), p0, p1, 0, 7, 0);
                *(s8 *)(work + 0) = 0xB;
                func_0033d320((void *)*(s32 *)(work + 0x15C), 0, 1);
                func_0033d320((void *)*(s32 *)(work + 0x160), 0, 1);
                func_0033d320((void *)*(s32 *)(work + 0x1A0), 0, 1);
                func_0033d320((void *)*(s32 *)(work + 0x1A4), 0, 1);
                func_0033d320((void *)*(s32 *)(work + 0xA0), 0, 1);
            }
        }
        break;
    case 13:
        g = 0;
        while (((s64)(g << 0x30) >> 0x30) < 0x24) {
            k = (s32)((s64)(g << 0x30) >> 0x30);
            *(u8 *)(work + k + 0x2B4) = (u8)func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
            if (*(s8 *)(work + k + 0x2D8) == 1) {
                p0 = func_002b2970(400.0f, 220.0f);
                *(f32 *)(work + k * 4 + 0x2FC) = func_0033d630(p0, (s32)(((s64)(k * 10) << 0x30) >> 0x30), (s32)*(u8 *)(work + k + 0x2B4), 0, *(f32 *)(work + 0x2A8));
            }
            g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
        }
        *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), 1, 0x3E8, 1, 2);
        *(s32 *)(work + 0x2B0) = func_002b2cb0(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        p0 = func_002b2970((f32)0x253, 78.0f);
        *(FclDrawColor *)&cw = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        func_002caa10(*(s64 *)&p0, 1.0f, cw, *(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))), 0x35, *(void **)(work + 0xC), 0xAB);
        func_0033c490(arg0);
        i = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
        k = func_001067f0((s16)func_002e2740(*(s16 *)(work + 4)));
        func_00275520(82.0f, 132.0f, 58.0f, i, 0, 1, k, 0, 0, D_00795E60);
        if (func_002bb680(*(s8 *)(work + 8)) != 0) {
            func_002bbcf0(*(s8 *)(work + 8));
        } else {
            *(s8 *)(work + 0) = 0xC;
            if (func_002bb1c0(*(s8 *)(work + 8)) == 0) {
                func_00106620(func_002e2740(*(s16 *)(work + 4)), ((*(s8 *)(work + 3) + (func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF)) & 0xFF));
                func_002e7a80(func_002e7a60() - *(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))));
                *(f32 *)(work + 0x1E0) = 580.0f - (f32)func_002b3170(func_002e7a60()) * 21.0f;
                *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x198)) + 0xF8) = (s16)(((func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF) % 10) + 0x46);
                func_0033d320((void *)*(s32 *)(work + 0x19C), 0, 0);
                *(s16 *)(func_0033d310((void *)*(s32 *)(work + 0x19C)) + 0xF8) = (s16)(((func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF) / 10) + 0x46);
                if (((func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) & 0xFF) / 10) == 0) {
                    func_0033d320((void *)*(s32 *)(work + 0x19C), 0, 1);
                    p0 = func_002b2970((f32)0x243, 185.0f);
                    p1 = func_002b2970((f32)0x243, 185.0f);
                    func_0033d3e0((void *)*(s32 *)(work + 0x198), p0, p1, 0, 0, 0);
                }
                p0 = func_002b2970(*(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xD0)) + 0x2C), D_0064A210[1]);
                p1 = func_002b2970(D_0064A210[0], D_0064A210[1]);
                func_0033d3e0((void *)*(s32 *)(work + 0xD0), p0, p1, 0, 7, 0);
                p0 = func_002b2970(*(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xD4)) + 0x2C), *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xD4)) + 0x30));
                p1 = func_002b2970(D_0064A218[0], *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0xD4)) + 0x30));
                func_0033d3e0((void *)*(s32 *)(work + 0xD4), p0, p1, 0, 7, 0);
                *(s8 *)(work + 0) = 0xB;
                func_0033d320((void *)*(s32 *)(work + 0x15C), 0, 1);
                func_0033d320((void *)*(s32 *)(work + 0x160), 0, 1);
                func_0033d320((void *)*(s32 *)(work + 0x1A0), 0, 1);
                func_0033d320((void *)*(s32 *)(work + 0x1A4), 0, 1);
                func_0033d320((void *)*(s32 *)(work + 0xA0), 0, 1);
                func_0045af60(0, 0, 0, 6);
            }
            func_002bb550(*(s8 *)(work + 8));
        }
        break;
    case 14:
        g = 0;
        while (((s64)(g << 0x30) >> 0x30) < 0x24) {
            k = (s32)((s64)(g << 0x30) >> 0x30);
            *(u8 *)(work + k + 0x2B4) = (u8)func_002b2aa0(0, 255.0f, 0.0f, (f32)*(s32 *)(work + 0x2B0), 5.0f);
            if (*(s8 *)(work + k + 0x2D8) == 1) {
                p0 = func_002b2970(400.0f, 220.0f);
                *(f32 *)(work + k * 4 + 0x2FC) = func_0033d630(p0, (s32)(((s64)(k * 10) << 0x30) >> 0x30), (s32)*(u8 *)(work + k + 0x2B4), 0, *(f32 *)(work + 0x2A8));
            }
            g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
        }
        *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), 1, 0x3E8, 1, 2);
        *(s32 *)(work + 0x2B0) = func_002b2cb0(*(s32 *)(work + 0x2B0), 1, 5, 1, 1);
        if (func_0033d390((void *)*(s32 *)(work + 0x10), 1) == 0 && func_0033d390((void *)*(s32 *)(work + 0x10), 3) == 0 && func_0033d390((void *)*(s32 *)(work + 0xB4), 1) == 0 && func_0033d390((void *)*(s32 *)(work + 0xB8), 1) == 0 && func_0033d390((void *)*(s32 *)(work + 0x110), 1) == 0 && func_0033d390((void *)*(s32 *)(work + 0x114), 1) == 0 && func_0033d390((void *)*(s32 *)(work + 0x1C), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x20), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x24), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x28), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x14), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0xB0), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0xB0), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x17C), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x17C), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x180), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x180), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x184), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x184), 4) == 0 && func_0033d390((void *)*(s32 *)(work + 0x58), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x5C), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x118), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x11C), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x40), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x44), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x48), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x4C), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x50), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x54), 2) == 0 && func_0033d390((void *)*(s32 *)(work + 0x60), 2) == 0) {
            *(s8 *)(work + 0) = 5;
        } else if (func_0033d390((void *)*(s32 *)(work + 0x10), 1) != 0 && (D_008C024E[0] & 0x20)) {
            func_0045af60(0, 0, 0, 2);
            *(f32 *)(work + 0x1D0) = 580.0f - (f32)func_002b3170(func_002e7a60()) * 21.0f;
            *(s32 *)(work + 0x1D4) = 0x41700000;
            *(f32 *)(work + 0x1D8) = (f32)0x28A;
            *(s32 *)(work + 0x1DC) = 0x41700000;
            *(s16 *)(work + 0x1EA) = 0;
            p0 = func_002b2970((f32)0x28A, *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0x10)) + 0x30));
            func_0033d3e0((void *)*(s32 *)(work + 0x10), *(F2_0033 *)(func_0033d310((void *)*(s32 *)(work + 0x10)) + 0x2C), p0, 0, 0xA, 0);
            func_0033d520((void *)*(s32 *)(work + 0x10), 0, 0xA, 0, *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0x10)) + 0xC4), *(f32 *)(func_0033d310((void *)*(s32 *)(work + 0x10)) + 0xBC));
            func_0033d550((void *)*(s32 *)(work + 0xB4));
            func_0033d550((void *)*(s32 *)(work + 0xB8));
            func_0033d550((void *)*(s32 *)(work + 0xBC));
            func_0033d550((void *)*(s32 *)(work + 0x178));
            func_0033d550((void *)*(s32 *)(work + 0x3C));
            func_0033d550((void *)*(s32 *)(work + 0x110));
            func_0033d550((void *)*(s32 *)(work + 0x114));
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 4) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                func_0033d550((void *)*(s32 *)(work + k * 4 + 0x1C));
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            func_0033d550((void *)*(s32 *)(work + 0x14));
            func_0033d550((void *)*(s32 *)(work + 0xB0));
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 3) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                func_0033d550((void *)*(s32 *)(work + k * 4 + 0x17C));
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            func_0033d550((void *)*(s32 *)(work + 0x58));
            func_0033d550((void *)*(s32 *)(work + 0x5C));
            func_0033d550((void *)*(s32 *)(work + 0x118));
            func_0033d550((void *)*(s32 *)(work + 0x11C));
            g = 0;
            while (((s64)(g << 0x30) >> 0x30) < 6) {
                k = (s32)((s64)(g << 0x30) >> 0x30);
                func_0033d550((void *)*(s32 *)(work + k * 4 + 0x40));
                g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
            }
            func_0033d550((void *)*(s32 *)(work + 0x60));
            func_00122520(1, 0xA);
            *(s8 *)(work + 0) = 0xF;
        }
        break;
    case 15:
        if (func_00122720() == 0) {
            return 0;
        }
        return -1;
    case 16:
        if (func_00452380(D_0064A3C0) != 0) {
            break;
        }
        g = 0;
        while (((s64)(g << 0x30) >> 0x30) < 4) {
            k = (s32)((s64)(g << 0x30) >> 0x30);
            func_0033d4b0((void *)*(s32 *)(work + k * 4 + 0x1C), 0, 0xFF, 0, 5, 0);
            g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
        }
        func_0033d4b0((void *)*(s32 *)(work + 0x10), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x110), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x114), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x14), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0xB4), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0xB8), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0xBC), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x178), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x3C), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0xB0), 0, 0xFF, 0, 5, 0);
        g = 0;
        while (((s64)(g << 0x30) >> 0x30) < 3) {
            k = (s32)((s64)(g << 0x30) >> 0x30);
            func_0033d4b0((void *)*(s32 *)(work + k * 4 + 0x17C), 0, 0xFF, 0, 5, 0);
            g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
        }
        func_0033d4b0((void *)*(s32 *)(work + 0x58), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x5C), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x118), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x11C), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x40), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x50), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x48), 0, 0xFF, 0, 5, 0);
        func_0033d4b0((void *)*(s32 *)(work + 0x60), 0, 0xFF, 0, 5, 0);
        *(s8 *)(work + 0) = 5;
        break;
    case 17:
        *(f32 *)(work + 0x1E0) = func_002b2aa0(0, *(f32 *)(work + 0x1D0), *(f32 *)(work + 0x1D8), (f32)*(s16 *)(work + 0x1EA), 10.0f);
        *(s16 *)(work + 0x1EA) = func_002b2cb0((s32)*(s16 *)(work + 0x1EA), 1, 0xA, 1, 1);
        g = 0;
        while (((s64)(g << 0x30) >> 0x30) < 4) {
            k = (s32)((s64)(g << 0x30) >> 0x30);
            *(f32 *)(func_0033d310((void *)*(s32 *)(work + k * 4 + 0x188)) + 0xC4) = iGpffff8424;
            g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x14), 2) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x1C), 4) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x1C), 2) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x1C), 1) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x20), 4) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x20), 2) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x20), 1) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x24), 4) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x24), 2) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x24), 1) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x28), 4) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x28), 2) != 0) {
            break;
        }
        if (func_0033d390((void *)*(s32 *)(work + 0x28), 1) != 0) {
            break;
        }
        g = 0;
        while (((s64)(g << 0x30) >> 0x30) < 6) {
            k = (s32)((s64)(g << 0x30) >> 0x30);
            func_0033d320((void *)*(s32 *)(work + k * 4 + 0x40), 0, 1);
            g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
        }
        func_0033d320((void *)*(s32 *)(work + 0x58), 0, 1);
        func_0033d320((void *)*(s32 *)(work + 0x5C), 0, 1);
        func_0033d320((void *)*(s32 *)(work + 0x118), 0, 1);
        func_0033d320((void *)*(s32 *)(work + 0x11C), 0, 1);
        func_0033d3d0((void *)*(s32 *)(work + 0xB0), 0x65);
        g = 0;
        while (((s64)(g << 0x30) >> 0x30) < 3) {
            k = (s32)((s64)(g << 0x30) >> 0x30);
            func_0033d3d0((void *)*(s32 *)(work + k * 4 + 0x17C), 0x65);
            g = (s64)(((s64)(g << 0x30) >> 0x30) + 1);
        }
        func_0033d3d0((void *)*(s32 *)(work + 0x110), 0x65);
        func_0033d3d0((void *)*(s32 *)(work + 0x114), 0x65);
        func_0033d3d0((void *)*(s32 *)(work + 0x60), 0x65);
        h = 0;
        while (((s64)(h << 0x30) >> 0x30) < 4) {
            k = (s32)((s64)(h << 0x30) >> 0x30);
            tmp = (void *)(work + k * 4 + 0x188);
            func_0033d320(*(void **)tmp, 0xD, 0);
            func_0033d320(*(void **)tmp, 0, 0);
            func_0033d4e0(*(void **)tmp, 0, 0xA, 0, iGpffff8504, iGpffff851c);
            func_0033d520(*(void **)tmp, 0, 0, 0, 0.0f, (f32)(k * 0x5A));
            func_0033d3c0(*(void **)tmp, 1.0f);
            *(s16 *)(func_0033d310(*(void **)tmp) + 0x102) = 0;
            *(s16 *)(func_0033d310(*(void **)tmp) + 0x100) = 0;
            *(u8 *)(func_0033d310(*(void **)tmp) + 0x62) = 2;
            func_0033d3d0(*(void **)tmp, 0x64);
            h = (s64)(((s64)(h << 0x30) >> 0x30) + 1);
        }
        func_0033d320((void *)*(s32 *)(work + 0x10), 0, 0);
        p0 = func_002b2970(D_0064A090[0], D_0064A090[1]);
        p1 = func_002b2970(650.0f, 241.0f);
        func_0033d3e0((void *)*(s32 *)(work + 0x10), p0, p1, 0, 0xA, 0);
        func_0033d520((void *)*(s32 *)(work + 0x10), 0, 0xA, 0, -720.0f, 0.0f);
        func_0033d3d0((void *)*(s32 *)(work + 0x10), 0x62);
        func_00122520(1, 0x1E);
        *(s8 *)(work + 0) = 0x12;
        break;
    case 18:
        if (func_00122720() == 0) {
            return 0;
        }
        return -1;
    default:
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclItemShopDraw", func_00332bb0);
#endif

// FUN_0033BDC0
void func_0033bdc0(u8 *arg0) {
    u8 *work = *(u8 **)(arg0 + 0x38);

    func_002e29a0();
    if (*(s32 *)(work + 0x428) != 0) {
        H_Cdvd_Destroy((void *)*(s32 *)(work + 0x428));
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
    temp_17 = func_00451fc0((void *)(arg0), (const void *)(D_0064A3D8), 0xF, 0, 0, func_00332bb0, func_0033bdc0, (u8 *)((u8 *)temp_2));
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
        pos0 = func_002b2970(coords[0], coords[1]);
        x = (func_0046b260(font) / 10.0f) * 1.5f + coords[0] + 0.0f;
        y = (func_0046b2f0(font) / 10.0f) * 1.5f + coords[1] + 0.0f;
        pos1 = func_002b2970(x, y);
        func_0033d3e0((void *)*(s32 *)item, pos0, pos1, 0, 10, layer);
        func_0046d280(font);
        i = (s16)(i + 1);
    }
    func_0033d320((void *)*(s32 *)(work + 0x14), 0, 0);
    func_0033d4b0((void *)*(s32 *)(work + 0x14), 0xFF, 0, 0, 10, 0);
    func_0033d3d0((void *)*(s32 *)(work + 0x14), 0xAC);
    table = (u8 *)D_0064A1D8;
    pos2 = func_002b2970(*(f32 *)(table + 0), *(f32 *)(table + 4));
    pos3 = func_002b2970(-180.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xB4), pos2, pos3, 0, 0x14, 0);
    table = (u8 *)D_0064A1E0;
    pos4 = func_002b2970(*(f32 *)(table + 0), *(f32 *)(table + 4));
    pos5 = func_002b2970(-200.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xB8), pos4, pos5, 0, 10, 0);
    table = (u8 *)D_0064A1E8;
    pos6 = func_002b2970(153.0f, *(f32 *)(table + 4));
    pos7 = func_002b2970(-100.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xBC), pos6, pos7, 0, 0x14, 0);
    pos8 = func_002b2970(203.0f, *(f32 *)(table + 4));
    pos9 = func_002b2970(-50.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0x178), pos8, pos9, 0, 0x14, 0);
    table = (u8 *)D_0064A0E8;
    pos10 = func_002b2970(*(f32 *)(table + 0), *(f32 *)(table + 4));
    pos11 = func_002b2970(-200.0f, *(f32 *)(table + 4));
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

/* Item list panel: the selected-item header, or five scrolling item rows with
   their frame, name and price. Shaping that matters: the frame and name
   draws are inline helpers (their float y parameters live in $f20 and the
   shared row top is one int that retail spills), the price goes out through
   its own pos/colour pair, the cursor tables are read through an F2_0033
   pointer (kept in $s1 across the reset call), and the shaded colour is
   written `green = blue = 0` (the andi on $zero). */
static inline void fclShopDrawItemFrame(u8 *p, f32 y, u8 red, u8 green, u8 blue)
{
    func_0025ecd0(44.0f, y, 62.0f, func_002b2a30(0xFF, red, green, blue), 0xFF, 0x24,
                  *(void **)(p + 0xC), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

static inline void fclShopDrawItemName(s16 item, f32 y, u8 red, u8 green, u8 blue)
{
    func_00275520(78.0f, y, 62.0f, func_002b2a30(red, green, blue, 0xFF), 0, 1,
                  func_001067f0((s16)func_002e2740(item)), 0, 0, D_00795E60);
}

// FUN_0033C490
void func_0033c490(u8 *arg0)
{
    u8 *p;
    s32 color;
    u32 value;
    s16 i;
    s16 row;
    s32 bound;
    u8 red;
    u8 green;
    u8 blue;
    u32 price;
    s32 y;
    s32 top;
    f32 fy;
    F2_0033 *tbl;
    F2_0033 pos1;
    FclDrawColor col1;
    F2_0033 pos2;
    FclDrawColor col2;

    p = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(p + 2) == 1) {
        func_0025ecd0(44.0f, 77.0f, 62.0f, func_002b2a30(0xFF, 0x26, 0x26, 0x26), 0xFF, 0x24,
                      *(void **)(p + 0xC), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
        color = func_002b2a30(0x26, 0x26, 0x26, 0xFF);
        value = func_001067f0((s16)func_002e2740(*(s16 *)(p + 4)));
        func_00275520(78.0f, 77.0f, 62.0f, color, 0, 1, value, 0, 0, D_00795E60);
        pos1 = func_002b2970(406.0f, 84.0f);
        col1 = func_002b2a60(0x26, 0x26, 0x26, 0xFF);
        func_002caa10(*(s64 *)&pos1, 62.0f, *(s32 *)&col1,
                      func_0033cbc0(arg0, func_002e2740(*(s16 *)(p + 4))), 0x19,
                      *(void **)(p + 0xC), 0xAB);
        func_002bc7f0((s16)func_00106b80((s16)func_002e2740(*(s16 *)(p + 4))), -1, 1, 0, 4, 0xAA,
                      71.0f, 135.0f, 62.0f);
        func_0033d320(*(void **)(p + 0x120), 0, 1);
        func_0033d320(*(void **)(p + 0x124), 0, 1);
        func_0033d320(*(void **)(p + 0xDC), 0, 0);
        func_0033d320(*(void **)(p + 0xE0), 0, 0);
        func_0033d320(*(void **)(p + 0x6C), 0, 1);
        func_0033d320(*(void **)(p + 0x70), 0, 0);
        func_0033d320(*(void **)(p + 0xD8), 0, 0);
        return;
    }
    func_0033d320(*(void **)(p + 0xDC), 0, 1);
    func_0033d320(*(void **)(p + 0xE0), 0, 1);
    func_0033d320(*(void **)(p + 0x6C), 0, 0);
    func_0033d320(*(void **)(p + 0x70), 0, 1);
    func_0033d320(*(void **)(p + 0xD8), 0, 1);
    tbl = (F2_0033 *)D_0064A2B0;
    func_0033d320(*(void **)(p + 0x120), 0, 0);
    fy = tbl->x;
    *(f32 *)(func_0033d310(*(u8 **)(p + 0x120)) + 0x2C) = fy;
    fy = tbl->y + (f32)(*(s16 *)(p + 6) * 28);
    *(f32 *)(func_0033d310(*(u8 **)(p + 0x120)) + 0x30) = fy;
    func_0033d3c0(*(void **)(p + 0x120), 63.0f);
    func_0033d3d0(*(u8 **)(p + 0x120), 0x5B);
    tbl = (F2_0033 *)D_0064A2B8;
    func_0033d320(*(void **)(p + 0x124), 0, 0);
    fy = tbl->x;
    *(f32 *)(func_0033d310(*(u8 **)(p + 0x124)) + 0x2C) = fy;
    fy = tbl->y + (f32)(*(s16 *)(p + 6) * 28);
    *(f32 *)(func_0033d310(*(u8 **)(p + 0x124)) + 0x30) = fy;
    func_0033d3c0(*(void **)(p + 0x124), 63.0f);
    func_0033d3d0(*(u8 **)(p + 0x124), 0x5B);
    i = *(s16 *)(p + 4) - *(s16 *)(p + 6);
    row = 0;
    bound = i + 5;
    for (; i < bound; i++, row++) {
        if (i >= func_002e2670()) {
            continue;
        }
        red = green = blue = 0xFF;
        if (i == *(s16 *)(p + 4)) {
            red = green = blue = 0x26;
        } else {
            price = func_0033cbc0(arg0, func_002e2740(i));
            if (func_002e7a60() < price) {
                red = 0x4F;
                green = blue = 0;
            } else if ((u8)func_00106600((s16)func_002e2740(i)) == 0x63) {
                red = 0x4F;
                green = blue = 0;
            } else if ((u8)clndGetMoonPhase(func_002e2740(i)) & 1) {
                red = 0x9F;
                blue = 0x2F;
            }
        }
        y = row * 28;
        top = y + 0x4D;
        fclShopDrawItemFrame(p, (f32)top, red, green, blue);
        fclShopDrawItemName(i, (f32)top, red, green, blue);
        pos2 = func_002b2970(406.0f, (f32)(y + 0x54));
        col2 = func_002b2a60(red, green, blue, 0xFF);
        func_002caa10(*(s64 *)&pos2, 62.0f, *(s32 *)&col2, func_0033cbc0(arg0, func_002e2740(i)),
                      0x19, *(void **)(p + 0xC), 0xAB);
    }
}
// FUN_0033CBC0
u32 func_0033cbc0(void *arg0, s64 arg1) {
    u8 *work = *(u8 **)((u8 *)arg0 + 0x38);
    u32 d = (u32)((s32)(*(s8 *)(work + 9) * (s32)func_00106a90((s64)(s16)arg1)) * 0x14) / 100U;

    return (u32)func_00106a90((s64)(s16)(s32)arg1) - d;
}

/* measured: 1216B/1216B MATCH (304 instrs, 0 edits + 9 reloc-only). Re-probed from scratch: floats-first func_0025ecd0 spelling (f32,f32,f32 first, then color/ints, then f32,f32,f32, pointer last) with u16 0xF8 load (lhu) and inline s16/2 division gives retail scheduling; shift+temp hoisting was +33, s16 F8 was +2 (35), archive ints-first is a compile error under this prototype. Mixed-arg orders tested explicitly. */
// FUN_0033CC40
s32 func_0033cc40(u8 *arg0) {
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
    memcpy(callback_work + 4, func_002b89a0(callback_work + 4), 0xF0);
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
    temp_17 = func_00451fc0((void *)(arg0), (const void *)(D_0064A3F0), 0xF, 0, 0, func_0033cc40, func_0033d100, (u8 *)(work));
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
