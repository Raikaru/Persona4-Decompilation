#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "fr_font_internal.h"

typedef struct { f32 x, y; } Vec2f;
typedef struct { u8 r, g, b, a; } RGBA;
typedef unsigned int u_long128 __attribute__((mode(TI)));
static inline f32 shopAdd(f32 left, f32 right) { return left + right; }
typedef struct {
    u8 pad0a[2];
    s16 field_2;
    s16 field_4;
    f32 field_8;
    u8 pad1a[5];
    s8 field_11;
    s16 field_12;
    u8 pad1b[0x18];
    f32 field_2C;
    f32 field_30;
    u8 pad2[0x2E];
    u8 field_62;
    u8 pad3[0x16];
    u8 field_79;
    u8 field_7A;
    u8 field_7B;
    u8 pad4[0x18];
    f32 field_94;
    u8 pad5[0x8];
    f32 field_A0;
    u8 pad6[0x20];
    f32 field_C4;
    u8 pad7[0x7];
    u8 field_CF;
    u8 pad8[0x24];
    u32 field_F4;
    s16 field_F8;
    u8 pad9[0x2];
    u32 field_FC;
    s16 field_100;
    s16 field_102;
    u8 padA1a1a[0xB20];
    s8 field_C24;
    u8 padA1a1b[0x1F];
    void *field_C44;
    void *field_C48;
    u8 padA1a2a[0x14];
    void *field_C60;
    void *field_C64;
    u8 padA1a2b[8];
    void *field_C70;
    void *field_C74;
    void *field_C78;
    u8 padA1a2c[4];
    void *field_C80;
    void *field_C84;
    u8 padA1a2d[4];
    void *field_C8C;
    void *field_C90;
    void *field_C94;
    void *field_C98;
    void *field_C9C;
    void *field_CA0;
    void *field_CA4;
    void *field_CA8;
    void *field_CAC;
    void *field_CB0;
    void *field_CB4;
    void *field_CB8;
    void *field_CBC;
    void *field_CC0;
    void *field_CC4;
    void *field_CC8;
    u8 padA2b1[4];
    void *field_CD0;
    void *field_CD4;
    void *field_CD8;
    void *field_CDC;
    void *field_CE0;
    void *field_CE4;
    void *field_CE8;
    u8 padA2b3a[0x80];
    void *field_D6C;
    void *field_D70;
    u8 padA2b3b[8];
    void *field_D7C;
    u8 padA2b3c[0xC];
    void *field_D8C;
    void *field_D90;
    void *field_D94;
    u8 padB1[0x24];
    void *field_DBC[3];
    void *field_DC8;
    u8 padB2a1[4];
    void *field_DD0;
    u8 padB2a2[8];
    void *field_DDC;
    void *field_DE0;
    void *field_DE4;
    u8 padB2b[0x44];
    void *field_E2C;
    void *field_E30;
    u8 padC1[4];
    void *field_E38;
    u8 padC2a[0x14];
    void *field_E50;
    void *field_E54;
    void *field_E58;
    void *field_E5C;
    void *field_E60;
    u8 padD1a1[0x1C];
    void *field_E80;
    void *field_E84;
    u8 padD1a2a[4];
    u8 padD1a2b[8];
    void *field_E94;
    void *field_E98;
    void *field_E9C;
    void *field_EA0;
    void *field_EA4;
    void *field_EA8;
    void *field_EAC;
    void *field_EB0;
    void *field_EB4;
    void *field_EB8;
    void *field_EBC;
    void *field_EC0;
    void *field_EC4;
    void *field_EC8;
    u8 padD1b[8];
    void *field_ED4;
    void *field_ED8;
    void *field_EDC;
    void *field_EE0;
    u8 padD2a[8];
    void *field_EEC;
    void *field_EF0;
    void *field_EF4;
    void *field_EF8;
    void *field_EFC;
    void *field_F00;
    void *field_F04;
    u8 padD2b2[0x10];
    void *field_F18[3];
    u8 padD2b[4];
    void *field_F28;
} ShopWork;

extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00795E60[];
extern u8 D_00793E80[];
extern char iGpffffa884[2];
extern u8 D_0063FAC0[];
extern u8 D_0063FB30[];
extern u8 D_0063FB70[];
extern u8 D_0063F560[];
extern u8 D_0063F9F0[];
extern f32 fGpffff8504;
extern f32 D_0063F650[];
extern f32 D_0063F658[];
extern f32 D_0063F5B0[];
extern f32 D_0063F5D0[];
extern f32 D_0063F5D8[];
extern f32 D_0063F5E0[];
extern f32 D_0063F5F0[];
extern f32 D_0063F5F8[];
extern f32 D_0063F880[];
extern f32 D_0063F890[];
extern s8 D_00748908[];
extern u8 D_00795E30[];
extern u8 D_00794EA0[];
extern u8 D_00794ED0[];
extern u8 D_0063FB50[];

s32 func_002be530(u8 *arg0);
void func_002be3c0(void);
s32 func_0010d6d0(s16);
void func_00105780(s32);
s32 func_00106b20(s16);
void func_0044ea90(const void *, u32);
s32 func_00451fc0(s32, const void *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
s32 func_002e0100(void *);
void func_0043f810(void *, s32, s32);
s32 func_002b89a0(void *);
void *func_00460990(void);
void func_00460ac0(void *, void *);
/* measured: the second parameter is u8 - a u8 lvalue passed to a u8 parameter is a
   plain load and materialises in slot order (li $a0 before lbu $a1); passed to an
   s32 parameter it counts as a conversion and is hoisted ahead of the constant. */
s32 func_002b2a30(u8, u8, u8, u8);
s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
s8 func_002e0570(void *, s32);
void *func_002e04e0(void *);
void func_002e04f0(void *, s32, s32);
void func_002e0620(void *, u64, u64, s32, s32, s16);
void func_002e0940(void *, f32, f32, s32, s32, s32);
void func_002b2970(void *, f32, f32);
void *func_002b5c90(void *, u64);
void *func_002e2590(void *, s32, s32, s32, s32);
char *func_00442830(char *, const char *);
void *func_0046d200(void *, s32);
f32 func_0046b260(void *);
f32 func_0046b2f0(void *);
void func_0046d280(void *);
void func_0046b0d0(void *);
void func_00454bd0(void *);
void func_002e29a0(void);
s8 func_002bab80(void *);
void func_002bbd80(s32, s32, void *);
void func_002badc0(s32, s16);
void func_002bafc0(s32, s32);
void func_002bb0a0(s32, s32);
void func_002bbf60(void);

s32 func_002dfec0(void *, s32, void *, s8);
s32 func_002dff90(void *, s32, void *, void *, s8);
u32 func_003b7060(void);
void func_0043f9c8(void *, s32, s32);
/* measured: floats first - retail materialises $f12-$f14 before $a0..$t1. */
void func_0025ec90(f32, f32, f32, s32, u8, s32, void *, s32, void *);
void func_002e0700(void *, s32, f32, f32, s32, s32, s32);
void func_002e09e0(void *, s32, f32);
void func_002e0690(void *, f32, f32, s32, s32, s32);
void func_002e0660(void *, u8, u8, u8, s16, s64);
s32 func_002e26f0(void *);
void func_002e06d0(void *, f32, f32, f32, f32, s32, s32, s32);
void func_002e0b20(s32, Vec2f, f32, s32, u8, s32, u8 *);
void *func_001067f0(s32);
s16 func_00106cd0(s16, s16);
u32 func_00106880(s16);
u16 func_001068b0(s16);
u16 func_001068e0(s16);
u16 func_00106940(s16);
u16 func_00106970(s16);
s32 func_002b3170(s32);
void func_002b2a60(void *, s32, s32, s32, s32);
void func_002cacd0(u64, f32, RGBA, s32, s16, u32, s32, s32, s32, s32, s32);
void *func_0046a770(void *);
s16 func_002e2830(void *, s32);
s32 func_00106600(s16 id);
u16 func_001069d0(s64);
void func_002bc7f0(s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_002e0ca0(s32, Vec2f, f32, s32, u8, s32, u8 *);
void func_002e0a60(void *, s32, f32);
void func_002e0080(void *, s8, Vec2f, void *);
void func_002d8200(void *, s8);
void func_002d83c0(void *);
s32 func_002e2670(void);
s16 func_002e26a0(void);
s16 func_002b2cb0(s32, s32, s32, s32, s32);
s16 func_002b2d00(s32, s32, s32, s32, s32);
s16 func_002b2d50(s32, s32, s32, s32, s32);
void func_002b2e70(s32, s32, s32, s32, void *, void *);
void func_002b2f90(s32, s32, s32, s32, void *, void *);
void func_002e2a10(s32, s32, s32, s32);
void func_002e0970(void *, u32, u32, s32, s32, s32);
void func_002e09b0(void *, s32, f32);
void func_002e0be0(s32, Vec2f, f32, s32, u8, s32, u8 *);
u32 func_002e7a60(void);
u32 func_00106a90(s16);
s32 func_00110830(s32);
s8 func_002e29d0(void);
f32 func_002b2aa0(s32, f32, f32, f32, f32);
void func_002e2700(void *);
extern f32 D_0063F9C0[];
extern f32 D_0063F9C8[];
extern f32 D_0063F9D0[];
extern f32 D_0063F888[];
extern f32 D_0063F5A0[];
extern f32 D_0063F5A8[];
extern f32 D_0063F5B8[];
extern f32 D_0063F778[];
extern f32 D_0063F780[];
extern f32 D_0063F788[];
extern f32 D_0063F790[];
extern f32 D_0063F798[];
extern f32 D_0063F7A0[];
extern f32 D_0063F7B0[];
extern f32 D_0063F7B8[];
extern f32 D_0063F8C0[];
extern f32 D_0063FA40;
extern s16 D_0063FA44;
extern s16 D_0063FA46;
extern u8 D_0063FA48[];
extern u8 D_0063FA50[];
extern u8 D_0063FA58[];
extern u8 D_0063FA60[];
extern u8 D_0063FA68[];
extern u16 D_008C024E;
extern u16 D_008C0276;
extern u16 D_008C027A;
extern f32 fGpffff7ad4;

/* measured: rule 1 is NOT VU0 here - retail ldr 0x2C/ldl 0x33 (12 sites, all
   on the func_002e04e0 result, e.g. 0x002C134C) is *(u64 *)(p + 0x2C): the
   b210 probe of that exact read emits ldr 0x2C/ldl 0x33 (and +0x38 emits ld),
   and func_002dd230 in this file already matches with the same idiom. Rule 2
   FMA sites (adda.s/madd.s, msub.s pairs at 0x002D.../0x002E...) are acc +
   a*b with preserved fs/ft order. Blocked by scale, not the rule: 0xC240
   bytes, 1525 jals, m2c draft 3700 lines with 200+ M2C_UNK slots and 20+
   M2C_ERROR sites across 3 shapes (saved-$s0 ldr base, temp_f20 madd, msub
   pairs); sibling func_002cdf80 with the same rules fully adapted measured
   nd 3325. Function-scale reconstruction floor. */
/* measured: func_002be530 recon + jump-table recovery (no guarded body installed - see tail). */
/* Retail 49728B = 12432 instrs, the largest first-party function in the tree. */
/* Band 12059-12805 (+-3%: 12432*0.97=12059.04, 12432*1.03=12804.96). Frame 0x790 */
/* (addiu $29,$29,-0x790; sq $16-$23,$30 + sd $31 + swc1 $f20/$f21). Calls 1525 jal. */
/* nop 2287/12432 = 18.4%; cond branches 277; total branch/jump 2006; jr x3 (two dispatch */
/* jr $2 at 0x002BE5C4 and 0x002C187C + return jr $ra). Delay slots: 0 non-nop. Method: */
/* counted from asm/nonmatchings/y_fclShopDraw/func_002be530.s comment-lines + mnemonic regex. */
/* MAIN dispatch: lb $2,0($17); addiu $2,$2,-0x9; sltiu $1,$2,0x2F; beqz $1,.L002CA728 */
/*   (default); lui/addiu jtbl_00748930; sll $2,$2,2; addu; lw; jr $2 (delay nop). The -9 means */
/*   the C switch is over states 9..55 (0x9..0x37): index = state-9, 47 cases (0..46). */
/* jtbl_00748930 at 0x00748930, extent 48 words (0xC0) to next jtbl_007489F0 at 0x007489F0; */
/*   valid 47 (indices 0..46); word 47 is 0x00000000 pad, not a case. sltiu bound 0x2F = 47 */
/*   cases; with the default that is 48 arms. The assignment's "forty-eight" counts default. */
/* Default .L002CA728 = 0x002CA728 (+0xC1F8) equals indices 2,16,17 - states 11 (0xB), 25 */
/*   (0x19), 26 (0x1A) share the default block and must still be written as explicit arms. */
/* Full main table (valid 47; `python3 tools/jtbl.py 0x00748930 47 --func 0x002be530`): */
/*   idx state target (+off)        idx state target (+off)        idx state target (+off) */
/*   0    0x9  0x002BE5CC (+0x9c)   16   0x19 0x002CA728 default  32   0x29 0x002C855C (+0xa02c) */
/*   1    0xA  0x002BE618 (+0xe8)   17   0x1A 0x002CA728 default  33   0x2A 0x002C85D0 (+0xa0a0) */
/*   2    0xB  0x002CA728 default   18   0x1B 0x002C4004 (+0x5ad4) 34   0x2B 0x002C8650 (+0xa120) */
/*   3    0xC  0x002BEE4C (+0x91c)  19   0x1C 0x002C40DC (+0x5bac) 35   0x2C 0x002C86E4 (+0xa1b4) */
/*   4    0xD  0x002BEEA0 (+0x970)  20   0x1D 0x002C4558 (+0x6028) 36   0x2D 0x002C8744 (+0xa214) */
/*   5    0xE  0x002BF05C (+0xb2c)  21   0x1E 0x002C479C (+0x626c) 37   0x2E 0x002C80E0 (+0x9bb0) */
/*   6    0xF  0x002BF018 (+0xae8)  22   0x1F 0x002C4A44 (+0x6514) 38   0x2F 0x002C8C28 (+0xa6f8) */
/*   7    0x10 0x002BFEE0 (+0x19b0) 23   0x20 0x002C4C58 (+0x6728) 39   0x30 0x002C92A0 (+0xad70) */
/*   8    0x11 0x002C0A64 (+0x2534) 24   0x21 0x002C5570 (+0x7040) 40   0x31 0x002C976C (+0xb23c) */
/*   9    0x12 0x002C0BAC (+0x267c) 25   0x22 0x002C5EB8 (+0x7988) 41   0x32 0x002C99D4 (+0xb4a4) */
/*   10   0x13 0x002C14A8 (+0x2f78) 26   0x23 0x002C6008 (+0x7ad8) 42   0x33 0x002C99E4 (+0xb4b4) */
/*   11   0x14 0x002C1AF0 (+0x35c0) 27   0x24 0x002C616C (+0x7c3c) 43   0x34 0x002C9C24 (+0xb6f4) */
/*   12   0x15 0x002C1C34 (+0x3704) 28   0x25 0x002C61A8 (+0x7c78) 44   0x35 0x002C9E64 (+0xb934) */
/*   13   0x16 0x002C2D0C (+0x47dc) 29   0x26 0x002C8838 (+0xa308) 45   0x36 0x002CA4EC (+0xbfbc) */
/*   14   0x17 0x002C38C0 (+0x5390) 30   0x27 0x002C74B0 (+0x8f80) 46   0x37 0x002CA674 (+0xc144) */
/*   15   0x18 0x002C3AB8 (+0x5588) 31   0x28 0x002C7A20 (+0x94f0) word47: 0x0 pad. */
/* Object order (ascending targets): 0,1,3,4,6,5,7,8,9,10,11,12,13,14,15,18,19,20,21,22, */
/*   23,24,25,26,27,28,30,31,37,32,33,34,35,36,29,38,39,40,41,42,43,44,45,46,2/16/17-dflt. */
/*   Out-of-order pairs (5 after 6; 37 before 32-36; 29 after 36) are object layout only; */
/*   m2c prints labels permuted (e.g. case 0x2E before 0x29) - source order stays numeric. */
/* C shape (main): switch (state - 9) { case 0: ... case 46: ...; default: ... } (or */
/*   equivalently switch (state) { case 9: ... case 55: ...; default: ... } - mwcc normalises */
/*   contiguous 9..55 to the same addiu -9 + sltiu 0x2F). Cases 11/25/26 (idx 2/16/17) present */
/*   but empty/fallthrough to default; the bound matches iff all 47 cases are present. */
/* SECOND dispatch (inside main case idx 17 / state 0x1B region, at 0x002C1858): */
/*   lb $2,0x7($17); sltiu $1,$2,0x6; beqz $1,.L002CA728 (same default); lui/addiu */
/*   jtbl_00748910; sll/addu/lw; jr $2. jtbl_00748910 at 0x00748910, extent 8 words (0x20) */
/*   to next jtbl_00748930 at 0x00748930; valid 6 (indices 0..5); words 6-7 are 0x0 pad. */
/*   Bound 0x6 = 6 cases; with default that is 7 arms. Targets */
/*   (`python3 tools/jtbl.py 0x00748910 6 --func 0x002be530`): 0,1,2 -> 0x002C1884 (+0x3354) */
/*   shared; 3 -> 0x002C1898 (+0x3368); 4 -> 0x002C19B4 (+0x3484); 5 -> 0x002C1A58 (+0x3528). */
/*   C shape: switch (work[7]) { case 0: case 1: case 2: ...; case 3: ...; case 4: ...; */
/*   case 5: ...; default: ... } - default falls through to the main default block. */
/* m2c with tables (this lane): staged /tmp/m2c_in_002be530.s = build/m2c/func_002be530.s plus */
/*   47+6 .word entries plus missing `.L<target>:` labels (tools/m2c_bulk.py method); */
/*   `python3 tools/vendor/m2c/m2c.py --target mipsee-mwcc-c --context build/m2c/func_002be530.ctx.c */
/*   --globals=used -f func_002be530` succeeds; without tables it fails at the first jr */
/*   (same `Found jr instruction` class as 00332bb0 line 38). Output /tmp/m2c_2be530_out.c: */
/*   3608 lines (assignment lane reported 3738 - context drift), 63 M2C_ERROR, 406 distinct sp */
/*   vars, 407 distinct temp_ vars, 24 unknown-sig `? func_` decls, 0 M2C_UNK tokens. Main */
/*   switch recovered as cases 0x9..0x37 with 0xB/0x19/0x1A merged into `default: return;` */
/*   (re-add by hand); second switch 0..5 correct with 0/1/2 shared. Switches 3-6 (small, */
/*   inside case bodies, e.g. work[7]-adjacent 3-case groups at 0x2C...) are branch if-chains. */
/* Width calibration (five banked floors in this file, object/retail instrs): 002cb6c0 */
/*   2589/2608 (-0.7% PASS), 002cdf80 3545/3460 (+2.5% PASS, landing via s64->s32 narrow of */
/*   temp_18; V8 all-s64 3581 FAIL), 002d1590 2621/2644 (-0.9% PASS), 002db400 1983/1932, */
/*   002da0a0 1260/1240. Expectation: all-s32 draft ~10% short (~11200 vs 12432); landing set */
/*   is 2-3 loop counters kept s64 for dsll32/dsra32 pairs (e.g. var_16 0x91-loop at .L002BE65C */
/*   pair 0x1BE680/0x1BE684; inner 0x5A/0xF-style s16 counters as in 00332bb0). File rules from */
/*   the retained note above still apply: *(u64 *)(p+0x2C) for ldr/ldl sites, FMA as acc+a*b. */
/* No guarded body installed: adapting the 3608-line draft (406 sp vars, unk-offset struct, */
/*   63 M2C_ERROR, `?` protos, gp-relative immediates) to TU idiom (ShopWork, Vec2f/u64 slots, */
/*   RGBA, s16/s8 widths) is multi-week at this scale; installing anything short of 12059 */
/*   would be outside the band with an uncomparable word score (gate handoff 7y). The two */
/*   recovered tables + this decomposition is the deliverable, stated plainly. */
/* measured 002be530 (owner, 2026-09-19): first body this function has had, **12070 against
   retail 12429 (-2.89%), INSIDE the +-3% band (12056-12801)**, fnalign 20177 edits.
   The lever is local WIDTH, and it was found by bracketing rather than by guessing: an
   all-s64 reconstruction is 19647 instructions (+58.0%), narrowing 136 of those locals to
   s32 is 11938 (-3.95%, 118 short), so the answer had to lie between the two.  Widening
   the three loop counters that looked responsible bought only 39 instructions, because the
   per-declaration value is an average and not a rule - so the COUNT was bisected instead:
   68 wide -> 11969, 85 -> 11986, 94 -> 11984, 96 -> 11984, 97 -> 12017, 98 -> 12070 INSIDE,
   102 -> 12103.  98 is the first count that lands, and note 94/96 tie and 97 jumps 33:
   these declarations are not independent, which is exactly why bisecting the count beats
   reasoning about individual variables.
   The remaining 20177 edits are structure, not width; the dispatch and the s64 arithmetic
   sites (dsll32/dsra32 + madd) are the next thing to read against retail. */
/* rejected 002be530 (owner, 2026-09-20): a pass that removed 183 `(u8)`/`(s8)`/`(f32)(s32)`
   truncations from f32 arguments as 'spurious' measured **20177 -> 11129 edits**, the
   largest single reduction anyone produced, and has been REVERTED.
   The object went 12070 -> 7977 against retail 12429, from -2.9% INSIDE the band to
   -35.8% OUTSIDE, 4452 instructions short, so the change could not stand.
   My first reading of that arithmetic was WRONG and the agent corrected it, with an opcode
   census I then verified against the disassembly.  I argued the lost 4093 instructions
   proved retail performs those conversions.  It does not: retail has 110 `cvt.s.w`, 73
   `cvt.w.s` and 127 `andi` against the body's 424, 344 and 515, and retail's 1525 `jal`
   against the body's 891.  The casts really were spurious - roughly 2000 surplus
   conversions standing in for roughly 2000 missing loads, moves and CALLS.  The body's
   12070 was never a healthy count; it was short-359 with the shortfall papered over.
   Deleting the padding without writing the missing code simply exposed the true deficit.
   The edits fell only because fnalign stopped trying to pair 4000 instructions that no
   longer existed.  An alignment score against a body a third too short measures a
   different, smaller function (handoff 7y); 11129 is not better than 20177.
   The honest work here is the 359-instruction shortfall the good body already has - run
   deficit_scan.py and write the named regions. */
/* measured 002be530 (owner, 2026-09-20, banked step 1): `#pragma opt_common_subs off` */
/*   inside the guard writes the missing loads FIRST without touching the 183 */
/*   compensating casts. fnalign retail 12429 object 12070 -> 12083 (+13, deficit */
/*   359 -> 346, -2.8% INSIDE band 12056-12801), edits 20177 (+16 reloc-only) -> */
/*   20096 (+14 reloc-only, -81). measure_guarded 10969 -> 10958 words (-11). */
/*   deficit_scan after: retail has more addiu +711 move +694 jal +634 lw +424; top */
/*   CROSS 3447 at 0x002c63d4, 997 at 0x002c3258, 802 at 0x002c4458 (was 3447, */
/*   1568, 1041) - alignment shortened. verify 26 MATCH / 12 ASM, lint 0 errors. */
/*   Next: work one ABSENT run (<=346) at a time, removing its casts only as its */
/*   region is replaced. */
/* rejected 002be530 step 2 (owner, 2026-09-20): two single-region follow-ups */
/*   tried and REVERTED to stay in band. (a) Removing the 2 `(u8)` casts on one */
/*   `func_002b2970(&sp640,...)` pair (retail 0x002BF138 `lwc1/lwc1/jal`, no */
/*   conversions) measured fnalign 20096 -> 20032 (-64) but object 12083 -> */
/*   12019 (-64, 37 BELOW lower bound 12056, OUTSIDE) and guarded 10958 -> */
/*   10996 (+38 worse): one pair already costs 64, so all 183 cannot go at */
/*   once. (b) Adding `#pragma opt_propagation off` beside common_subs measured */
/*   object 12083 -> 13362 (+1279, ABOVE upper 12801, OUTSIDE) and edits 20096 */
/*   -> 20373 (+277) with guarded 10958 -> 11882 (+924): propagation is not the */
/*   lever here. Both reverted; production stays at step 1 (12083 INSIDE). */
// FUN_002BE530 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
s32 func_002be530(u8 *arg0)
{
    extern u8 D_0063FAA0[];
    extern u8 D_0063FAD0[];
    extern u8 D_00795FE0[];
    extern u8 D_00713908[];
    extern u8 D_00713910[];
    extern f32 fGpffff8520;
    extern f32 fGpffff8524;
    extern f32 fGpffff8528;
    extern f32 fGpffff8170;
    extern f32 fGpffff852C;
    extern u8 D_0063F7C8[];
    extern u8 D_0063F7D0[];
    extern u8 D_0063F9F0[];
    extern u8 D_0063F688[];
    extern u8 D_0063F690[];
    extern u8 D_0063FAF0[];
    extern u8 D_0063FB10[];
    extern void func_002be4a0(void);
    extern void func_00460ac0(void *, void *);
    extern s32 func_0046aea0(void *);
    extern void func_00440b68(const void *, const void *, s32);
    extern void *func_00454a60(const void *, s32);
    extern s32 func_004553c0(void *);
    extern s32 func_00106330(s32);
    extern void func_00106390(s32, s32);
    extern void func_00106620(s16, s32);
    extern u32 func_00106850(s32);
    extern s32 func_00106b50(s16);
    extern void func_00106d40(s16, s16, s16);
    extern void func_00110810(s32, u8);
    extern s64 func_00110a60(s32, s32);
    extern s32 func_002b32a0(s32, s32, s32, s32);
    extern s32 func_002bae80(s64, s32);
    extern s8 func_002bb1c0(s8);
    extern void func_002bb550(s8);
    extern s32 func_002bb680(s8);
    extern void func_002bbcf0(s8);
    extern s32 func_002be160(s32, s32);
    extern void func_002e24a0(s32, s32, s32, s32);
    extern s16 func_002e28f0(void *, s32);
    extern u8 func_002e78a0(void);
    extern u8 func_002e78e0(void);
    extern void func_002e7a80(s32);
    extern void func_00331fc0(u8 *);
    extern void func_00442088(void *, void *, s32);
    extern s32 func_00452380(void *);
    extern u8 func_0045aeb0(s16, const char *);
    extern void func_002e3560(void *, s32, s32, s32, s32);
    extern void func_002dfe00(void *arg0);
    extern s32 func_002dfd00(u16 arg0);
    extern s32 func_002dfec0(void *arg0, s32 arg1, void *arg2, s8 arg3);
    extern s32 func_002dff90(void *arg0, s32 arg1, void *arg2, void *arg3, s8 arg4);
    extern void func_002e0080(void *arg0, s8 arg1, Vec2f arg2, void *arg3);
    extern s32 func_002e0100(void *arg0);
    extern void func_002e02d0(void *arg0);

    extern void func_002caef0(void *arg0);
    extern void func_002cb6c0(void *arg0, s8 arg1);
    extern void func_002cdf80(void *arg0, s8 arg1);
    extern s32 func_002d1590(void *arg0);
    extern void func_002d3ee0(void *arg0);
    extern s8 func_002d4760(void *arg0, s8 arg1);
    extern s32 func_002d4f30(s16 arg0);
    extern void func_002d5040(void *arg0);
    extern void func_002d6190(void *arg0);
    extern void func_002d7300(void *arg0);
    extern void func_002d7f90(void *arg0);
    extern void func_002d8200(void *arg0, s8 arg1);
    extern void func_002d83c0(void *arg0);
    extern void func_002d8600(void *arg0);
    extern void func_002da0a0(register u8 *root);
    extern void func_002db400(void *arg0);
    extern void func_002dd230(void *arg0);
    extern void func_002de5a0(void *arg0);
    extern void func_002df020(void *arg0, s64 arg1, s32 arg2);
    extern void func_002df4c0(void *arg0);
    extern s32 func_002e0300(s32 arg0, s16 arg1, u32 arg2);
    extern void func_002cacd0(u64 arg0, f32 fparg0, RGBA arg1, s32 arg2, s16 arg3, u32 arg4_, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
    extern void func_002ca770(void *arg0);


    s32 s0;
    s32 sp6A9;
    s32 sp6AA;
    s32 sp6AB;
    s32 sp6AD;
    s32 sp6AE;
    s32 sp6AF;
    s32 sp6B1;
    s32 sp6B2;
    s32 sp6B3;
    s32 sp6B5;
    s32 sp6B6;
    s32 sp6B7;
    s32 sp6B9;
    s32 sp6BA;
    s32 sp6BB;
    s32 sp6BD;
    s32 sp6BE;
    s32 sp6BF;
    s32 sp6C1;
    s32 sp6C2;
    s32 sp6C3;
    s32 sp6C5;
    s32 sp6C6;
    s32 sp6C7;
    s32 sp6C9;
    s32 sp6CA;
    s32 sp6CB;
    s32 sp6CD;
    s32 sp6CE;
    s32 sp6CF;
    s32 sp6D1;
    s32 sp6D2;
    s32 sp6D3;
    s32 sp6D5;
    s32 sp6D6;
    s32 sp6D7;
    s32 sp6D9;
    s32 sp6DA;
    s32 sp6DB;
    s32 sp6DD;
    s32 sp6DE;
    s32 sp6DF;
    s32 sp6E1;
    s32 sp6E2;
    s32 sp6E3;
    s32 sp6E5;
    s32 sp6E6;
    s32 sp6E7;
    s32 sp6E9;
    s32 sp6EA;
    s32 sp6EB;
    s32 sp6ED;
    s32 sp6EE;
    s32 sp6EF;
    s32 sp6F1;
    s32 sp6F2;
    s32 sp6F3;
    s32 sp6F5;
    s32 sp6F6;
    s32 sp6F7;
    s32 sp6FD;
    s32 sp6FE;
    s32 sp6FF;
    s32 sp701;
    s32 sp702;
    s32 sp703;
    s32 sp705;
    s32 sp706;
    s32 sp707;
    s32 sp709;
    s32 sp70A;
    s32 sp70B;
    s32 sp70D;
    s32 sp70E;
    s32 sp70F;
    s32 sp729;
    s32 sp72A;
    s32 sp72B;
    s32 sp72D;
    s32 sp72E;
    s32 sp72F;
    s32 sp731;
    s32 sp732;
    s32 sp733;
    s32 sp735;
    s32 sp736;
    s32 sp737;
    s32 sp739;
    s32 sp73A;
    s32 sp73B;
    s32 sp73D;
    s32 sp73E;
    s32 sp73F;
    s32 sp741;
    s32 sp742;
    s32 sp743;
    s32 sp745;
    s32 sp746;
    s32 sp747;
    s32 sp749;
    s32 sp74A;
    s32 sp74B;
    s32 sp74D;
    s32 sp74E;
    s32 sp74F;
    s32 sp751;
    s32 sp752;
    s32 sp753;
    s32 sp755;
    s32 sp756;
    s32 sp757;
    s32 sp759;
    s32 sp75A;
    s32 sp75B;
    s32 sp75D;
    s32 sp75E;
    s32 sp75F;
    s32 sp761;
    s32 sp762;
    s32 sp763;
    s32 sp765;
    s32 sp766;
    s32 sp767;
    s32 sp769;
    s32 sp76A;
    s32 sp76B;
    s32 sp76D;
    s32 sp76E;
    s32 sp76F;
    s32 sp771;
    s32 sp772;
    s32 sp773;
    s32 sp775;
    s32 sp776;
    s32 sp777;
    s32 sp779;
    s32 sp77A;
    s32 sp77B;
    s32 sp77D;
    s32 sp77E;
    s32 sp77F;
    s32 sp781;
    s32 sp782;
    s32 sp783;
    s32 sp785;
    s32 sp786;
    s32 sp787;
    s32 sp789;
    s32 sp78A;
    s32 sp78B;
    s32 sp78D;
    s32 sp78E;
    s32 sp78F;
    s32 unksp1BC;
    s32 unksp1C4;
    s32 unksp1CC;
    s32 unksp1D4;
    s32 unksp1DC;
    s32 unksp1E4;
    s32 unksp1EC;
    s32 unksp40C;
    u8 sp78C;
    u8 sp788;
    u8 sp784;
    u8 sp780;
    u8 sp77C;
    u8 sp778;
    u8 sp774;
    u8 sp770;
    u8 sp76C;
    u8 sp768;
    u8 sp764;
    u8 sp760;
    u8 sp75C;
    u8 sp758;
    u8 sp754;
    u8 sp750;
    u8 sp74C;
    u8 sp748;
    u8 sp744;
    u8 sp740;
    u8 sp73C;
    u8 sp738;
    u8 sp734;
    u8 sp730;
    u8 sp72C;
    u8 sp728;
    u8 sp724;
    u8 sp720;
    u8 sp71C;
    u8 sp718;
    u8 sp714;
    u8 sp710;
    u8 sp70C;
    u8 sp708;
    u8 sp704;
    u8 sp700;
    u8 sp6FC;
    u8 sp6F8;
    u8 sp6F4;
    u8 sp6F0;
    u8 sp6EC;
    u8 sp6E8;
    u8 sp6E4;
    u8 sp6E0;
    u8 sp6DC;
    u8 sp6D8;
    u8 sp6D4;
    u8 sp6D0;
    u8 sp6CC;
    u8 sp6C8;
    u8 sp6C4;
    u8 sp6C0;
    u8 sp6BC;
    u8 sp6B8;
    u8 sp6B4;
    u8 sp6B0;
    u8 sp6AC;
    u8 sp6A8;
    s32 sp6A4;
    s32 sp6A0;
    s32 sp69C;
    s32 sp698;
    s32 sp694;
    s32 sp690;
    s32 sp68C;
    s32 sp688;
    s32 sp684;
    s32 sp680;
    s32 sp67C;
    s32 sp678;
    s32 sp674;
    s32 sp670;
    s32 sp66C;
    s32 sp668;
    f32 sp664;
    f32 sp660;
    f32 sp65C;
    f32 sp658;
    f32 sp654;
    f32 sp650;
    s64 sp648;
    s64 sp640;
    s64 sp638;
    s64 sp630;
    s64 sp628;
    s64 sp620;
    s64 sp618;
    s64 sp610;
    s64 sp608;
    s64 sp600;
    s64 sp5F8;
    s64 sp5F0;
    s64 sp5E8;
    s64 sp5E0;
    s64 sp5D8;
    s64 sp5D0;
    s64 sp5C8;
    s64 sp5C0;
    s64 sp5B8;
    s64 sp5B0;
    s64 sp5A8;
    s64 sp5A0;
    s64 sp598;
    s64 sp590;
    s64 sp588;
    s64 sp580;
    s64 sp578;
    s64 sp570;
    s64 sp568;
    s64 sp560;
    s64 sp558;
    s64 sp550;
    s64 sp548;
    s64 sp540;
    s64 sp538;
    s64 sp530;
    s64 sp528;
    s64 sp520;
    s64 sp518;
    s64 sp510;
    s64 sp508;
    s64 sp500;
    s64 sp4F8;
    s64 sp4F0;
    s64 sp4E8;
    s64 sp4E0;
    s64 sp4D8;
    s64 sp4D0;
    s64 sp4C8;
    s64 sp4C0;
    s64 sp4B8;
    s64 sp4B0;
    s64 sp4A8;
    s64 sp4A0;
    s64 sp498;
    s64 sp490;
    s64 sp488;
    s64 sp480;
    s64 sp478;
    s64 sp470;
    s64 sp468;
    s64 sp460;
    s64 sp458;
    s64 sp450;
    s64 sp448;
    s64 sp440;
    s64 sp438;
    s64 sp430;
    s64 sp428;
    s64 sp420;
    s64 sp418;
    s64 sp410;
    s64 sp408;
    s64 sp400;
    s64 sp3F8;
    s64 sp3F0;
    s64 sp3E8;
    s64 sp3E0;
    s64 sp3D8;
    s64 sp3D0;
    s64 sp3C8;
    s64 sp3C0;
    s64 sp3B8;
    s64 sp3B0;
    s64 sp3A8;
    s64 sp3A0;
    s64 sp398;
    s64 sp390;
    s64 sp388;
    s64 sp380;
    s64 sp378;
    s64 sp370;
    s64 sp368;
    s64 sp360;
    s64 sp358;
    s64 sp350;
    s64 sp348;
    s64 sp340;
    s64 sp338;
    s64 sp330;
    s64 sp328;
    s64 sp320;
    s64 sp318;
    s64 sp310;
    s64 sp308;
    s64 sp300;
    s64 sp2F8;
    s64 sp2F0;
    s64 sp2E8;
    s64 sp2E0;
    s64 sp2D8;
    s64 sp2D0;
    s64 sp2C8;
    s64 sp2C0;
    s64 sp2B8;
    s64 sp2B0;
    s64 sp2A8;
    s64 sp2A0;
    s64 sp298;
    s64 sp290;
    s64 sp288;
    s64 sp280;
    s64 sp278;
    s64 sp270;
    s64 sp268;
    s64 sp260;
    s64 sp258;
    s64 sp250;
    s64 sp248;
    s64 sp240;
    s64 sp238;
    s64 sp230;
    s64 sp228;
    s64 sp220;
    s64 sp218;
    s64 sp210;
    s64 sp208;
    s64 sp200;
    s64 sp1F8;
    s64 sp1F0;
    s64 sp1E8;
    s64 sp1E0;
    s64 sp1D8;
    s64 sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    s64 sp1A8;
    s64 sp1A0;
    s64 sp198;
    s64 sp190;
    s64 sp188;
    s64 sp180;
    s64 sp178;
    s64 sp170;
    s64 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    s32 spD0;
    s32 spC0;
    f32 *temp_16_12;
    f32 *temp_16_7;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_15;
    f32 temp_f0_16;
    f32 temp_f0_17;
    f32 temp_f0_18;
    f32 temp_f0_19;
    f32 temp_f0_20;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f20;
    f32 temp_f20_10;
    f32 temp_f20_11;
    f32 temp_f20_12;
    f32 temp_f20_13;
    f32 temp_f20_14;
    f32 temp_f20_15;
    f32 temp_f20_16;
    f32 temp_f20_17;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f20_9;
    f32 temp_f21;
    f32 var_f12;
    f32 var_f12_10;
    f32 var_f12_11;
    f32 var_f12_12;
    f32 var_f12_13;
    f32 var_f12_14;
    f32 var_f12_15;
    f32 var_f12_16;
    f32 var_f12_17;
    f32 var_f12_18;
    f32 var_f12_2;
    f32 var_f12_3;
    f32 var_f12_4;
    f32 var_f12_5;
    f32 var_f12_6;
    f32 var_f12_7;
    f32 var_f12_8;
    f32 var_f12_9;
    s16 temp_16_58;
    s16 temp_16_60;
    s16 temp_18_52;
    s16 temp_18_53;
    s16 temp_18_57;
    s16 temp_23_2;
    s16 temp_2_129;
    s16 temp_2_130;
    s16 temp_2_76;
    s16 temp_2_77;
    s16 temp_2_98;
    s16 temp_30;
    s16 temp_4_10;
    s16 temp_4_15;
    s16 temp_4_16;
    s16 temp_4_3;
    s16 temp_4_6;
    s16 temp_4_7;
    s16 temp_4_8;
    s16 temp_4_9;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_66;
    s32 temp_16_67;
    s32 temp_16_68;
    s32 temp_16_69;
    s32 temp_16_70;
    s32 temp_16_71;
    s32 temp_16_72;
    s32 temp_16_73;
    s32 temp_16_85;
    s32 temp_16_91;
    s32 temp_16_93;
    s32 temp_18_11;
    s32 temp_18_48;
    s32 temp_18_51;
    s32 temp_18_55;
    s32 temp_18_56;
    s32 temp_21_3;
    s32 temp_21_4;
    s32 temp_2_131;
    s32 temp_2_132;
    s32 temp_2_133;
    s32 temp_2_13;
    s32 temp_2_15;
    s32 temp_2_17;
    s32 temp_2_19;
    s32 temp_2_22;
    s32 temp_2_30;
    s32 temp_2_31;
    s32 temp_2_32;
    s32 temp_2_39;
    s32 temp_2_3;
    s32 temp_2_40;
    s32 temp_2_41;
    s32 temp_2_46;
    s32 temp_2_47;
    s32 temp_2_48;
    s32 temp_2_4;
    s32 temp_4_12;
    s32 temp_4_5;
    s32 var_21_2;
    s32 var_22;
    s64 temp_16_29;
    s64 temp_16_39;
    s64 temp_16_43;
    s64 temp_16_44;
    s64 temp_16_46;
    s64 temp_16_47;
    s64 temp_16_49;
    s64 temp_16_4;
    s64 temp_16_51;
    s64 temp_16_52;
    s64 temp_16_53;
    s64 temp_16_55;
    s64 temp_16_56;
    s64 temp_16_57;
    s64 temp_16_59;
    s64 temp_16_5;
    s64 temp_16_62;
    s64 temp_16_65;
    s64 temp_16_6;
    s64 temp_16_74;
    s64 temp_16_75;
    s64 temp_16_76;
    s64 temp_16_78;
    s64 temp_16_79;
    s64 temp_16_81;
    s64 temp_16_82;
    s64 temp_16_86;
    s64 temp_16_87;
    s64 temp_16_94;
    s64 temp_18;
    s64 temp_18_10;
    s64 temp_18_12;
    s64 temp_18_13;
    s64 temp_18_14;
    s64 temp_18_15;
    s64 temp_18_16;
    s64 temp_18_17;
    s64 temp_18_18;
    s64 temp_18_19;
    s64 temp_18_21;
    s64 temp_18_22;
    s64 temp_18_25;
    s64 temp_18_26;
    s64 temp_18_27;
    s64 temp_18_28;
    s64 temp_18_2;
    s64 temp_18_30;
    s64 temp_18_31;
    s64 temp_18_32;
    s64 temp_18_33;
    s64 temp_18_34;
    s64 temp_18_35;
    s64 temp_18_36;
    s64 temp_18_38;
    s64 temp_18_3;
    s64 temp_18_40;
    s64 temp_18_41;
    s64 temp_18_54;
    s64 temp_18_5;
    s64 temp_18_60;
    s64 temp_18_61;
    s64 temp_18_62;
    s64 temp_18_6;
    s64 temp_18_7;
    s64 temp_18_8;
    s64 temp_18_9;
    s64 temp_19;
    s64 temp_19_11;
    s64 temp_19_2;
    s64 temp_19_5;
    s64 temp_19_7;
    s64 temp_19_8;
    s64 temp_20;
    s64 temp_21_5;
    s64 temp_2_85;
    s64 temp_3_10;
    s64 temp_3_11;
    s64 temp_3_13;
    s64 temp_3_14;
    s64 temp_3_21;
    s64 temp_3_22;
    s64 temp_3_24;
    s64 temp_3_25;
    s64 temp_3_2;
    s64 temp_3_4;
    s64 temp_3_5;
    s64 temp_3_6;
    s64 temp_3_7;
    s64 temp_3_8;
    s64 temp_3_9;
    s64 temp_4;
    s64 temp_4_11;
    s64 temp_4_13;
    s64 temp_4_14;
    s64 temp_4_2;
    s64 temp_4_4;
    s64 var_16;
    s64 var_16_10;
    s64 var_16_11;
    s32 var_16_12;
    s32 var_16_13;
    s32 var_16_14;
    s32 var_16_15;
    s32 var_16_16;
    s32 var_16_17;
    s32 var_16_18;
    s32 var_16_19;
    s32 var_16_20;
    s32 var_16_21;
    s32 var_16_22;
    s32 var_16_23;
    s32 var_16_24;
    s32 var_16_25;
    s32 var_16_26;
    s64 var_16_2;
    s64 var_16_3;
    s32 var_16_4;
    s32 var_16_5;
    s32 var_16_6;
    s32 var_16_7;
    s32 var_16_8;
    s32 var_16_9;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_18_4;
    s32 var_18_5;
    s32 var_18_6;
    s32 var_19;
    s32 var_19_2;
    s32 var_19_3;
    s32 var_19_5;
    s32 var_20;
    s32 var_20_2;
    s32 var_20_3;
    s32 var_21;
    s32 var_21_3;
    s32 var_21_4;
    s32 var_5;
    s8 temp_16_83;
    s8 temp_16_90;
    s8 temp_16_92;
    s8 temp_19_3;
    s8 temp_22_2;
    s8 temp_2_2;
    s8 temp_2_44;
    s8 temp_2_5;
    s8 temp_2_65;
    s8 temp_2_78;
    s8 temp_2_79;
    s8 temp_2_97;
    s8 temp_3_18;
    s8 temp_3_19;
    s8 temp_5;
    s8 var_19_4;
    s8 var_3;
    s8 var_3_10;
    s8 var_3_11;
    s8 var_3_12;
    s8 var_3_13;
    s8 var_3_14;
    s8 var_3_15;
    s8 var_3_16;
    s8 var_3_17;
    s8 var_3_18;
    s8 var_3_19;
    s8 var_3_20;
    s8 var_3_2;
    s8 var_3_3;
    s8 var_3_6;
    s8 var_3_7;
    s8 var_3_8;
    s8 var_3_9;
    u32 temp_16_50;
    u32 temp_16_54;
    u32 temp_16_61;
    u32 temp_16_63;
    u32 temp_16_77;
    u32 temp_16_80;
    u32 temp_16_84;
    u32 temp_17_2;
    u32 temp_18_42;
    u32 temp_18_44;
    u32 temp_18_45;
    u32 temp_18_46;
    u32 temp_18_47;
    u32 temp_18_49;
    u32 temp_19_4;
    u32 temp_21_2;
    u8 temp_2_100;
    u8 temp_2_101;
    u8 temp_2_106;
    u8 temp_2_107;
    u8 temp_2_108;
    u8 temp_2_35;
    u8 temp_2_36;
    u8 temp_2_37;
    u8 temp_2_53;
    u8 temp_2_54;
    u8 temp_2_55;
    u8 temp_2_66;
    u8 temp_2_67;
    u8 temp_2_68;
    u8 temp_2_80;
    u8 temp_2_81;
    u8 temp_2_82;
    u8 temp_2_99;
    u8 temp_5_2;
    u8 temp_5_3;
    u8 temp_5_4;
    u8 temp_5_5;
    u8 temp_5_6;
    u8 temp_5_7;
    u8 temp_5_8;
    u8 temp_5_9;
    u8 temp_6;
    u8 temp_6_2;
    u8 temp_6_3;
    u8 temp_6_4;
    u8 temp_6_5;
    u8 temp_6_6;
    u8 temp_6_7;
    u8 temp_6_8;
    u8 var_3_4;
    u8 var_3_5;
    u8 *temp_16_10;
    u8 *temp_16_11;
    u8 *temp_16_13;
    u8 *temp_16_14;
    u8 *temp_16_15;
    u8 *temp_16_16;
    u8 *temp_16_17;
    u8 *temp_16_18;
    u8 *temp_16_19;
    u8 *temp_16_20;
    u8 *temp_16_21;
    u8 *temp_16_22;
    u8 *temp_16_23;
    u8 *temp_16_24;
    u8 *temp_16_25;
    u8 *temp_16_26;
    u8 *temp_16_27;
    u8 *temp_16_28;
    u8 *temp_16_30;
    u8 *temp_16_31;
    u8 *temp_16_32;
    u8 *temp_16_33;
    u8 *temp_16_34;
    u8 *temp_16_35;
    u8 *temp_16_36;
    u8 *temp_16_37;
    u8 *temp_16_38;
    u8 *temp_16_3;
    u8 *temp_16_40;
    u8 *temp_16_41;
    u8 *temp_16_42;
    u8 *temp_16_45;
    u8 *temp_16_48;
    u8 *temp_16_64;
    u8 *temp_16_88;
    u8 *temp_16_89;
    u8 *temp_16_8;
    u8 *temp_16_9;
    u8 *temp_17;
    u8 *temp_18_20;
    u8 *temp_18_23;
    u8 *temp_18_24;
    u8 *temp_18_29;
    u8 *temp_18_37;
    u8 *temp_18_39;
    u8 *temp_18_43;
    u8 *temp_18_4;
    u8 *temp_18_50;
    u8 *temp_18_58;
    u8 *temp_18_59;
    u8 *temp_18_63;
    u8 *temp_19_10;
    u8 *temp_19_6;
    u8 *temp_19_9;
    u8 *temp_21;
    u8 *temp_22;
    u8 *temp_23;
    u8 *temp_2;
    u8 *temp_2_102;
    u8 *temp_2_103;
    u8 *temp_2_104;
    u8 *temp_2_105;
    u8 *temp_2_109;
    u8 *temp_2_10;
    u8 *temp_2_110;
    u8 *temp_2_111;
    u8 *temp_2_112;
    u8 *temp_2_113;
    u8 *temp_2_114;
    u8 *temp_2_115;
    u8 *temp_2_116;
    u8 *temp_2_117;
    u8 *temp_2_118;
    u8 *temp_2_119;
    u8 *temp_2_11;
    u8 *temp_2_120;
    u8 *temp_2_121;
    u8 *temp_2_122;
    u8 *temp_2_123;
    u8 *temp_2_124;
    u8 *temp_2_125;
    u8 *temp_2_126;
    u8 *temp_2_127;
    u8 *temp_2_128;
    u8 *temp_2_12;
    u8 *temp_2_134;
    u8 *temp_2_135;
    u8 *temp_2_136;
    u8 *temp_2_137;
    u8 *temp_2_138;
    u8 *temp_2_14;
    u8 *temp_2_16;
    u8 *temp_2_18;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_23;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_26;
    u8 *temp_2_27;
    u8 *temp_2_28;
    u8 *temp_2_29;
    u8 *temp_2_33;
    u8 *temp_2_34;
    u8 *temp_2_38;
    u8 *temp_2_42;
    u8 *temp_2_43;
    u8 *temp_2_45;
    u8 *temp_2_49;
    u8 *temp_2_50;
    u8 *temp_2_51;
    u8 *temp_2_52;
    u8 *temp_2_56;
    u8 *temp_2_57;
    u8 *temp_2_58;
    u8 *temp_2_59;
    u8 *temp_2_60;
    u8 *temp_2_61;
    u8 *temp_2_62;
    u8 *temp_2_63;
    u8 *temp_2_64;
    u8 *temp_2_69;
    u8 *temp_2_6;
    u8 *temp_2_70;
    u8 *temp_2_71;
    u8 *temp_2_72;
    u8 *temp_2_73;
    u8 *temp_2_74;
    u8 *temp_2_75;
    u8 *temp_2_7;
    u8 *temp_2_83;
    u8 *temp_2_84;
    u8 *temp_2_86;
    u8 *temp_2_87;
    u8 *temp_2_88;
    u8 *temp_2_89;
    u8 *temp_2_8;
    u8 *temp_2_90;
    u8 *temp_2_91;
    u8 *temp_2_92;
    u8 *temp_2_93;
    u8 *temp_2_94;
    u8 *temp_2_95;
    u8 *temp_2_96;
    u8 *temp_2_9;
    u8 *temp_3;
    u8 *temp_3_12;
    u8 *temp_3_15;
    u8 *temp_3_16;
    u8 *temp_3_17;
    u8 *temp_3_20;
    u8 *temp_3_23;
    u8 *temp_3_3;

    temp_17 = (u8 *)((*(u8 **)((u8 *)(arg0) + (0x38))));
    var_19 = 0;
    temp_2 = (u8 *)(func_00460990());
    (*(void (**)())((u8 *)(temp_2) + (8))) = (void (*)())((void (**)())(func_002be4a0));
    (*(u8 **)((u8 *)(temp_2) + (0x10))) = (u8 *)(temp_17);
    func_00460ac0(&D_00795FE0, temp_2);
    temp_2_2 = (s8)((*(s8 *)((u8 *)(temp_17) + (0))));
    switch (temp_2_2) {                             /* switch 1 */
    case 0x9:                                       /* switch 1 */
        (*(s32 *)((u8 *)(temp_17) + (0xF28))) = func_0046aea0(&D_0063FAA0);
        func_00440b68(D_00713908, &D_0063FAC0, 0x147);
        (*(u8 **)((u8 *)(temp_17) + (0xF2C))) = (u8 *)(func_00454a60(&D_0063FAD0, 0));
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0xA;
        /* fallthrough */
    case 0xA:                                       /* switch 1 */
        if ((func_0046a750((*(s32 *)((u8 *)(temp_17) + (0xF28)))) != 0) && (func_004553c0((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) != 0)) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0xB;
            (*(s8 *)((u8 *)(temp_17) + (0xF30))) = 1;
            var_16 = 0;
loop_7:
            temp_18 = (s64) (var_16 << 0x30) >> 0x30;
            if (temp_18 < 0x91) {
                (*(s32 *)((u8 *)((temp_17 + (temp_18 * 4))) + (0xC38))) = func_002e0300((s32)arg0, var_16, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
                var_16 = (s64) ((var_16 + 1) << 0x30) >> 0x30;
                goto loop_7;
            }
            (*(s32 *)((u8 *)(temp_17) + (0xE7C))) = func_002e0300((s32)arg0, 6, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xE80))) = func_002e0300((s32)arg0, 0xA, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xE84))) = func_002e0300((s32)arg0, 0x1D, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            var_16_2 = 0;
loop_10:
            if (((s64) (var_16_2 << 0x30) >> 0x30) < 3) {
                temp_18_2 = (s64) (var_16_2 << 0x30) >> 0x30;
                (*(s32 *)((u8 *)((temp_17 + (temp_18_2 * 4))) + (0xE88))) = func_002e0300((s32)arg0, (s64) ((temp_18_2 + 0x61) << 0x30) >> 0x30, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
                var_16_2 = (s64) ((var_16_2 + 1) << 0x30) >> 0x30;
                goto loop_10;
            }
            var_16_3 = 0;
loop_13:
            if (((s64) (var_16_3 << 0x30) >> 0x30) < 4) {
                temp_18_3 = (s64) (var_16_3 << 0x30) >> 0x30;
                (*(s32 *)((u8 *)((temp_17 + (temp_18_3 * 4))) + (0xE94))) = func_002e0300((s32)arg0, (s64) ((temp_18_3 + 0x19) << 0x30) >> 0x30, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
                var_16_3 = (s64) ((var_16_3 + 1) << 0x30) >> 0x30;
                goto loop_13;
            }
            (*(s32 *)((u8 *)(temp_17) + (0xEA4))) = func_002e0300((s32)arg0, 0x1D, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEA8))) = func_002e0300((s32)arg0, 0x1D, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEAC))) = func_002e0300((s32)arg0, 0x20, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEB0))) = func_002e0300((s32)arg0, 0x21, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEB4))) = func_002e0300((s32)arg0, 3, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEB8))) = func_002e0300((s32)arg0, 4, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEBC))) = func_002e0300((s32)arg0, 3, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEC0))) = func_002e0300((s32)arg0, 4, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEC4))) = func_002e0300((s32)arg0, 3, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEC8))) = func_002e0300((s32)arg0, 4, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xED4))) = func_002e0300((s32)arg0, 3, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xED8))) = func_002e0300((s32)arg0, 4, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xECC))) = func_002e0300((s32)arg0, 5, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEDC))) = func_002e0300((s32)arg0, 0x2B, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEE0))) = func_002e0300((s32)arg0, 0x2C, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xED0))) = func_002e0300((s32)arg0, 0x5F, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF14))) = func_002e0300((s32)arg0, 0x5F, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEE4))) = func_002e0300((s32)arg0, 0x65, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEE8))) = func_002e0300((s32)arg0, 0x66, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEEC))) = func_002e0300((s32)arg0, 0xA, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEF0))) = func_002e0300((s32)arg0, 0xA, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEF4))) = func_002e0300((s32)arg0, 0x12, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEF8))) = func_002e0300((s32)arg0, 0xE, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEFC))) = func_002e0300((s32)arg0, 0x13, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF00))) = func_002e0300((s32)arg0, 0xF, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF04))) = func_002e0300((s32)arg0, 0x10, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF08))) = func_002e0300((s32)arg0, 0x8C, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF0C))) = func_002e0300((s32)arg0, 0x8D, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF10))) = func_002e0300((s32)arg0, 0x8E, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            temp_2_3 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x48));
            temp_f21 = 632.0f + func_0046b260((void *)(temp_2_3));
            func_0046d280((void *)(temp_2_3));
            temp_2_4 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x47));
            temp_f20 = 136.0f + func_0046b2f0((void *)(temp_2_4));
            func_0046d280((void *)(temp_2_4));
            temp_f1 = (f32) 0x1A3;
            (*(f32 *)((u8 *)(temp_17) + (0xF34))) = (f32) (temp_f1 + ((temp_f21 - temp_f1) / 2.0f));
            (*(f32 *)((u8 *)(temp_17) + (0xF38))) = (f32) (65.0f + ((temp_f20 - 65.0f) / 2.0f));
            (*(s8 *)((u8 *)(temp_17) + (0xF73))) = 1;
            (*(s8 *)((u8 *)(temp_17) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0(1, 0)) << 0x30) >> 0x30);
            (*(s8 *)((u8 *)(temp_17) + (9))) = 1;
            if (func_00106330(0x30) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 2;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (func_00106330(0x31) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 3;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (func_00106330(0x32) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 4;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (func_00106330(0x33) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 6;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (func_00106330(0x35) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 8;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (func_00106330(0x36) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 7;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            var_5 = 0;
loop_28:
            if (((s64) (var_5 << 0x30) >> 0x30) < 9) {
                temp_4 = (s64) (var_5 << 0x30) >> 0x30;
                temp_3 = (u8 *)(temp_17 + (temp_4 * 2));
                (*(s16 *)((u8 *)(temp_3) + (0xF46))) = (s16) (temp_4 * 3);
                (*(s16 *)((u8 *)(temp_3) + (0xF58))) = 0;
                (*(s8 *)((u8 *)((temp_17 + temp_4)) + (0xF6A))) = 0;
                var_5 = (s64) ((var_5 + 1) << 0x30) >> 0x30;
                goto loop_28;
            }
            (*(s8 *)((u8 *)(temp_17) + (8))) = 0;
        }
    default:                                        /* switch 1 */
block_626:
        return 0;
    case 0xC:                                       /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            func_00106390(0x1324, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0xD;
        }
        goto block_626;
    case 0xD:                                       /* switch 1 */
        if ((D_00748908[0] < func_002e26f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xF18)))))) && (func_00106330(0x1324) == 0)) {
            temp_2_5 = (s8)(func_002bab80((*(s32 **)((u8 *)((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) + (0x110)))));
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = temp_2_5;
            func_002bae80((s64) ((s64) temp_2_5 << 0x38) >> 0x38, 0xB);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0xC;
            return 0;
        }
        temp_16 = func_002e78a0() & 0xFF;
        if (((s64) (func_00110a60(temp_16, func_002e78e0() & 0xFF) << 0x38) >> 0x38) == 1) {
            temp_16_2 = func_002e78e0() & 0xFF;
            temp_3_2 = (s64) ((temp_16_2 + ((func_002e78a0() & 0xFF) * 0x64)) << 0x30) >> 0x30;
            if ((temp_3_2 >= 0x190) && (temp_3_2 < 0x207)) {
                (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 0xC, (*(s32 **)((u8 *)((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) + (0x110))), 0);
            } else {
                (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 0xD, (*(s32 **)((u8 *)((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) + (0x110))), 0);
            }
        } else {
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 0xC, (*(s32 **)((u8 *)((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) + (0x110))), 0);
        }
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0xF;
        goto block_626;
    case 0xF:                                       /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0xE;
        }
        goto block_626;
    case 0xE:                                       /* switch 1 */
        (*(s8 *)((u8 *)(temp_17) + (7))) = 0;
        temp_16_3 = (u8 *)((s32)&D_0063F9F0 + (((s64) (0 << 0x38) >> 0x38) * 0xC));
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0x41, 126.0f);
        temp_f20_2 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_3) + (0))));
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x2C))) = temp_f20_2;
        temp_f20_3 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_3) + (4))));
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) = temp_f20_3;
        func_002b2a60(&sp78C, 0xFE, 0xC6, 0x31, 0xFFU);
        temp_2_6 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
        (*(u8 *)((u8 *)(temp_2_6) + (0x79))) = sp78C;
        (*(u8 *)((u8 *)(temp_2_6) + (0x7A))) = sp78D;
        (*(u8 *)((u8 *)(temp_2_6) + (0x7B))) = sp78E;
        (*(u8 *)((u8 *)(temp_2_6) + (0x7C))) = sp78F;
        func_002b2970(&sp648, (*(f32 *)((u8 *)(temp_16_3) + (0))) - 80.0f, (*(f32 *)((u8 *)(temp_16_3) + (4))));
        func_002b2970(&sp640, ((u8)((*(f32 *)((u8 *)(temp_16_3) + (0))))), ((u8)((*(f32 *)((u8 *)(temp_16_3) + (4))))));
        func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), sp648, sp640, 0, 3, (s64) (((*(s8 *)((u8 *)(temp_17) + (7))) + 1) << 0x30) >> 0x30);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0U, 0xFF, 0, 3, (s64) (((*(s8 *)((u8 *)(temp_17) + (7))) + 1) << 0x30) >> 0x30);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0x41, 127.0f);
        temp_f20_4 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_3) + (0))) + (*(f32 *)((u8 *)(temp_16_3) + (8))));
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x2C))) = temp_f20_4;
        temp_f20_5 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_3) + (4))));
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) = temp_f20_5;
        func_002b2a60(&sp788, 0xFE, 0xC6, 0x31, 0xFFU);
        temp_2_7 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
        (*(u8 *)((u8 *)(temp_2_7) + (0x79))) = sp788;
        (*(u8 *)((u8 *)(temp_2_7) + (0x7A))) = sp789;
        (*(u8 *)((u8 *)(temp_2_7) + (0x7B))) = sp78A;
        (*(u8 *)((u8 *)(temp_2_7) + (0x7C))) = sp78B;
        func_002b2970(&sp638, ((*(f32 *)((u8 *)(temp_16_3) + (0))) + (*(f32 *)((u8 *)(temp_16_3) + (8)))) - 80.0f, (*(f32 *)((u8 *)(temp_16_3) + (4))));
        func_002b2970(&sp630, ((u8)(((*(f32 *)((u8 *)(temp_16_3) + (0))) + (*(f32 *)((u8 *)(temp_16_3) + (8)))))), ((u8)((*(f32 *)((u8 *)(temp_16_3) + (4))))));
        func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), sp638, sp630, 0, 3, (s64) (((*(s8 *)((u8 *)(temp_17) + (7))) + 1) << 0x30) >> 0x30);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0U, 0xFF, 0, 3, (s64) (((*(s8 *)((u8 *)(temp_17) + (7))) + 1) << 0x30) >> 0x30);
        func_002d7f90(arg0);
        var_20 = 0;
loop_50:
        if (((s64) (var_20 << 0x30) >> 0x30) < 7) {
            temp_19 = (s64) (var_20 << 0x30) >> 0x30;
            temp_18_4 = (u8 *)((s32)&D_0063F560 + ((temp_19 + 0x3A) * 8));
            temp_3_3 = (u8 *)(temp_17 + (temp_19 * 4));
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_3_3) + (0xD20)))), 0x56, (f32) (temp_19 + 0x64));
            if (temp_19 > 0) {
                func_002b2a60(&sp784, 0xED, 0x80, 0, 0xFFU);
                temp_2_8 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_3_3) + (0xD20))))));
                (*(u8 *)((u8 *)(temp_2_8) + (0x79))) = sp784;
                (*(u8 *)((u8 *)(temp_2_8) + (0x7A))) = sp785;
                (*(u8 *)((u8 *)(temp_2_8) + (0x7B))) = sp786;
                (*(u8 *)((u8 *)(temp_2_8) + (0x7C))) = sp787;
            }
            temp_2_9 = (u8 *)(temp_17 + (((s64) (var_20 << 0x30) >> 0x30) * 4));
            func_002b2970(&sp628, ((u8)((80.0f + (*(f32 *)((u8 *)(temp_18_4) + (0)))))), (u8) (*(f32 *)((u8 *)(temp_18_4) + (4))));
            func_002b2970(&sp620, ((u8)((*(f32 *)((u8 *)(temp_18_4) + (0))))), (u8) (*(f32 *)((u8 *)(temp_18_4) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_2_9) + (0xD20)))), sp628, sp620, 0, 3, var_20);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_2_9) + (0xD20)))), 0U, 0xFF, 0, 3, var_20);
            var_20 = (s64) ((var_20 + 1) << 0x30) >> 0x30;
            goto loop_50;
        }
        func_002b2a60(&sp780, 0x2D, 0x2D, 0x2D, 0xFFU);
        temp_2_10 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
        (*(u8 *)((u8 *)(temp_2_10) + (0x79))) = sp780;
        (*(u8 *)((u8 *)(temp_2_10) + (0x7A))) = sp781;
        (*(u8 *)((u8 *)(temp_2_10) + (0x7B))) = sp782;
        (*(u8 *)((u8 *)(temp_2_10) + (0x7C))) = sp783;
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC3C)))), 0x41, ((f32)(sp780)));
        func_002b2a60(&sp77C, 0x5A, 0, 2, 0xFFU);
        temp_2_11 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC3C))))));
        (*(u8 *)((u8 *)(temp_2_11) + (0x79))) = sp77C;
        (*(u8 *)((u8 *)(temp_2_11) + (0x7A))) = sp77D;
        (*(u8 *)((u8 *)(temp_2_11) + (0x7B))) = sp77E;
        (*(u8 *)((u8 *)(temp_2_11) + (0x7C))) = sp77F;
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC38)))), 0x56, ((f32)(sp77C)));
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40)))), 0x56, 183.0f);
        func_002b2a60(&sp778, 0xFE, 0xBE, 0x1E, 0xFFU);
        temp_2_12 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40))))));
        (*(u8 *)((u8 *)(temp_2_12) + (0x79))) = sp778;
        (*(u8 *)((u8 *)(temp_2_12) + (0x7A))) = sp779;
        (*(u8 *)((u8 *)(temp_2_12) + (0x7B))) = sp77A;
        (*(u8 *)((u8 *)(temp_2_12) + (0x7C))) = sp77B;
        temp_2_13 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 2));
        temp_18_5 = (s64) (((s64)((func_0046b260((void *)(temp_2_13)) / 2.0f))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40)))))) + (0x100))) = (s16) temp_18_5;
        temp_18_6 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_13)) / 2.0f))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40)))))) + (0x102))) = (s16) temp_18_6;
        func_0046d280((void *)(temp_2_13));
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40)))), 0, 0, 0, -90.0f, -90.0f);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
        func_002b2a60(&sp774, 0, 0, 0, 0xFFU);
        temp_2_14 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))));
        (*(u8 *)((u8 *)(temp_2_14) + (0x79))) = sp774;
        (*(u8 *)((u8 *)(temp_2_14) + (0x7A))) = sp775;
        (*(u8 *)((u8 *)(temp_2_14) + (0x7B))) = sp776;
        (*(u8 *)((u8 *)(temp_2_14) + (0x7C))) = sp777;
        temp_2_15 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
        temp_18_7 = (s64) (((s64)(func_0046b260((void *)(temp_2_15)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_7;
        temp_18_8 = (s64) (((s64)(func_0046b2f0((void *)(temp_2_15)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_8;
        func_0046d280((void *)(temp_2_15));
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0U, 0xA0, 0, 4, 4);
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 4, 4, 0.0f, fGpffff8520);
        func_002b2970(&sp618, 0xC3700000U, 0x43C80000U);
        func_002b2970(&sp610, 0xC3700000U, 0x439B0000U);
        func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), sp618, sp610, 0, 4, 4);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
        func_002b2a60(&sp770, 0xFF, 0xBE, 0x22, 0xFFU);
        temp_2_16 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))));
        (*(u8 *)((u8 *)(temp_2_16) + (0x79))) = sp770;
        (*(u8 *)((u8 *)(temp_2_16) + (0x7A))) = sp771;
        (*(u8 *)((u8 *)(temp_2_16) + (0x7B))) = sp772;
        (*(u8 *)((u8 *)(temp_2_16) + (0x7C))) = sp773;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 110.0f;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = -50.0f;
        temp_2_17 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
        temp_16_4 = (s64) (((s64)(func_0046b260((void *)(temp_2_17)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_16_4;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = 0;
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 4, 0, -90.0f, fGpffff8524);
        func_0046d280((void *)(temp_2_17));
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0U, 0xFF, 0, 4, 0);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 180.0f;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 30.0f;
        func_002b2a60(&sp76C, 0xED, 0x81, 3, 0xFFU);
        temp_2_18 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))));
        (*(u8 *)((u8 *)(temp_2_18) + (0x79))) = sp76C;
        (*(u8 *)((u8 *)(temp_2_18) + (0x7A))) = sp76D;
        (*(u8 *)((u8 *)(temp_2_18) + (0x7B))) = sp76E;
        (*(u8 *)((u8 *)(temp_2_18) + (0x7C))) = sp76F;
        temp_2_19 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
        temp_16_5 = (s64) (((s64)(func_0046b260((void *)(temp_2_19)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_16_5;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = 0;
        func_0046d280((void *)(temp_2_19));
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 4, 2, -85.0f, fGpffff8528);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0U, 0xFF, 0, 4, 2);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0x41, 46.0f);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0U, 0xFF, 0, 6, 0);
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x2C))) = 198.0f;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x30))) = (f32) 0x151;
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0x41, 146.0f);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0U, 0xFF, 0, 6, 0);
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))))) + (0x2C))) = 216.0f;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))))) + (0x30))) = 368.0f;
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0x3F, 207.0f);
        func_002b2a60(&sp768, 0xFF, 0xAE, 0, 0xFFU);
        temp_2_20 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C))))));
        (*(u8 *)((u8 *)(temp_2_20) + (0x79))) = sp768;
        (*(u8 *)((u8 *)(temp_2_20) + (0x7A))) = sp769;
        (*(u8 *)((u8 *)(temp_2_20) + (0x7B))) = sp76A;
        (*(u8 *)((u8 *)(temp_2_20) + (0x7C))) = sp76B;
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0, 0x708, 0, 0.0f, 360.0f);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 6, 0);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0x3D, 209.0f);
        func_002b2a60(&sp764, 0xE4, 0xFF, 0, 0xFFU);
        temp_2_21 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90))))));
        (*(u8 *)((u8 *)(temp_2_21) + (0x79))) = sp764;
        (*(u8 *)((u8 *)(temp_2_21) + (0x7A))) = sp765;
        (*(u8 *)((u8 *)(temp_2_21) + (0x7B))) = sp766;
        (*(u8 *)((u8 *)(temp_2_21) + (0x7C))) = sp767;
        temp_2_22 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x56));
        temp_18_9 = (s64) (((s64)(func_0046b260((void *)(temp_2_22)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))))) + (0x100))) = (s16) temp_18_9;
        temp_18_10 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_22)) / 2.0f))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))))) + (0x102))) = (s16) temp_18_10;
        func_0046d280((void *)(temp_2_22));
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0, 0x5A0, 0, 0.0f, 360.0f);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 6, 0);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0U, 0xFF, 0, 0xA, 0);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0x3D, 210.0f);
        func_002b2a60(&sp760, 0xE4, 0xFF, 0, 0xFFU);
        temp_2_23 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94))))));
        (*(u8 *)((u8 *)(temp_2_23) + (0x79))) = sp760;
        (*(u8 *)((u8 *)(temp_2_23) + (0x7A))) = sp761;
        (*(u8 *)((u8 *)(temp_2_23) + (0x7B))) = sp762;
        (*(u8 *)((u8 *)(temp_2_23) + (0x7C))) = sp763;
        temp_18_11 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x57));
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))))) + (0x100))) = 0;
        temp_16_6 = (s64) (((s64)((func_0046b2f0((void *)(temp_18_11)) / 2.0f))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))))) + (0x102))) = (s16) temp_16_6;
        func_0046d280((void *)(temp_18_11));
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0, 0x5A0, 0, 0.0f, 360.0f);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 6, 0);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0U, 0xFF, 0, 0xA, 0);
        var_16_4 = 0x59;
loop_53:
        temp_18_12 = (s64) (var_16_4 << 0x30) >> 0x30;
        if (temp_18_12 < 0x60) {
            func_002b2a60(&sp75C, 0xFF, 0xAE, 0, 0xFFU);
            temp_2_24 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_12 * 4))) + (0xC38))))));
            (*(u8 *)((u8 *)(temp_2_24) + (0x79))) = sp75C;
            (*(u8 *)((u8 *)(temp_2_24) + (0x7A))) = sp75D;
            (*(u8 *)((u8 *)(temp_2_24) + (0x7B))) = sp75E;
            (*(u8 *)((u8 *)(temp_2_24) + (0x7C))) = sp75F;
            var_16_4 = (s64) ((var_16_4 + 1) << 0x30) >> 0x30;
            goto loop_53;
        }
        var_16_5 = 0x64;
loop_56:
        temp_18_13 = (s64) (var_16_5 << 0x30) >> 0x30;
        if (temp_18_13 < 0x67) {
            func_002b2a60(&sp758, 0xFE, 0xC6, 0x31, 0xFFU);
            temp_2_25 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_13 * 4))) + (0xC38))))));
            (*(u8 *)((u8 *)(temp_2_25) + (0x79))) = sp758;
            (*(u8 *)((u8 *)(temp_2_25) + (0x7A))) = sp759;
            (*(u8 *)((u8 *)(temp_2_25) + (0x7B))) = sp75A;
            (*(u8 *)((u8 *)(temp_2_25) + (0x7C))) = sp75B;
            var_16_5 = (s64) ((var_16_5 + 1) << 0x30) >> 0x30;
            goto loop_56;
        }
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0x10;
        (*(s16 *)((u8 *)(temp_17) + (0xC26))) = 1;
        goto block_626;
    case 0x10:                                      /* switch 1 */
        if (D_008C027A & 0x4000) {
            (*(s8 *)((u8 *)(temp_17) + (7))) = func_002b2cb0((*(s8 *)((u8 *)(temp_17) + (7))), 1, 5, 0, 2);
            func_002d7f90(arg0);
            temp_16_7 = (f32 *)((s32)&D_0063F9F0 + ((*(s8 *)((u8 *)(temp_17) + (7))) * 0xC));
            temp_f20_6 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_7) + (0))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x2C))) = temp_f20_6;
            temp_f20_7 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_7) + (4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) = temp_f20_7;
            temp_f20_8 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_7) + (0))) + (*(f32 *)((u8 *)(temp_16_7) + (8))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x2C))) = temp_f20_8;
            temp_f20_9 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_7) + (4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) = temp_f20_9;
            temp_16_8 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
            func_002b2970(&sp608, (u8) (*(f32 *)((u8 *)(temp_16_8) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) - 4.0f))));
            temp_16_9 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
            func_002b2970(&sp600, (u8) (*(f32 *)((u8 *)(temp_16_9) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), sp608, sp600, 1, 2, 0);
            temp_16_10 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
            func_002b2970(&sp5F8, (u8) (*(f32 *)((u8 *)(temp_16_10) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) - 4.0f))));
            temp_16_11 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
            func_002b2970(&sp5F0, (u8) (*(f32 *)((u8 *)(temp_16_11) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), sp5F8, sp5F0, 1, 2, 0);
            var_16_6 = 0;
loop_61:
            temp_18_14 = (s64) (var_16_6 << 0x30) >> 0x30;
            if (temp_18_14 < 6) {
                func_002b2a60(&sp754, 0xED, 0x80, 0, 0xFFU);
                temp_2_26 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_14 * 4))) + (0xD24))))));
                (*(u8 *)((u8 *)(temp_2_26) + (0x79))) = sp754;
                (*(u8 *)((u8 *)(temp_2_26) + (0x7A))) = sp755;
                (*(u8 *)((u8 *)(temp_2_26) + (0x7B))) = sp756;
                (*(u8 *)((u8 *)(temp_2_26) + (0x7C))) = sp757;
                var_16_6 = (s64) ((var_16_6 + 1) << 0x30) >> 0x30;
                goto loop_61;
            }
            func_002b2a60(&sp750, 0x2D, 0x2D, 0x2D, 0xFFU);
            temp_2_27 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
            (*(u8 *)((u8 *)(temp_2_27) + (0x79))) = sp750;
            (*(u8 *)((u8 *)(temp_2_27) + (0x7A))) = sp751;
            (*(u8 *)((u8 *)(temp_2_27) + (0x7B))) = sp752;
            (*(u8 *)((u8 *)(temp_2_27) + (0x7C))) = sp753;
            func_0045af60(0, 0, 0, 0);
        } else if (D_008C027A & 0x1000) {
            (*(s8 *)((u8 *)(temp_17) + (7))) = func_002b2d00((*(s8 *)((u8 *)(temp_17) + (7))), 1, 0, 5, 2);
            func_002d7f90(arg0);
            temp_16_12 = (f32 *)((s32)&D_0063F9F0 + ((*(s8 *)((u8 *)(temp_17) + (7))) * 0xC));
            temp_f20_10 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_12) + (0))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x2C))) = temp_f20_10;
            temp_f20_11 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_12) + (4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) = temp_f20_11;
            temp_f20_12 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_12) + (0))) + (*(f32 *)((u8 *)(temp_16_12) + (8))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x2C))) = temp_f20_12;
            temp_f20_13 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_12) + (4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) = temp_f20_13;
            temp_16_13 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
            func_002b2970(&sp5E8, (u8) (*(f32 *)((u8 *)(temp_16_13) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) - 4.0f))));
            temp_16_14 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
            func_002b2970(&sp5E0, (u8) (*(f32 *)((u8 *)(temp_16_14) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), sp5E8, sp5E0, 1, 2, 0);
            temp_16_15 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
            func_002b2970(&sp5D8, (u8) (*(f32 *)((u8 *)(temp_16_15) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) - 4.0f))));
            temp_16_16 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
            func_002b2970(&sp5D0, (u8) (*(f32 *)((u8 *)(temp_16_16) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), sp5D8, sp5D0, 1, 2, 0);
            var_16_7 = 0;
loop_66:
            temp_18_15 = (s64) (var_16_7 << 0x30) >> 0x30;
            if (temp_18_15 < 6) {
                func_002b2a60(&sp74C, 0xED, 0x80, 0, 0xFFU);
                temp_2_28 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_15 * 4))) + (0xD24))))));
                (*(u8 *)((u8 *)(temp_2_28) + (0x79))) = sp74C;
                (*(u8 *)((u8 *)(temp_2_28) + (0x7A))) = sp74D;
                (*(u8 *)((u8 *)(temp_2_28) + (0x7B))) = sp74E;
                (*(u8 *)((u8 *)(temp_2_28) + (0x7C))) = sp74F;
                var_16_7 = (s64) ((var_16_7 + 1) << 0x30) >> 0x30;
                goto loop_66;
            }
            func_002b2a60(&sp748, 0x2D, 0x2D, 0x2D, 0xFFU);
            temp_2_29 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
            (*(u8 *)((u8 *)(temp_2_29) + (0x79))) = sp748;
            (*(u8 *)((u8 *)(temp_2_29) + (0x7A))) = sp749;
            (*(u8 *)((u8 *)(temp_2_29) + (0x7B))) = sp74A;
            (*(u8 *)((u8 *)(temp_2_29) + (0x7C))) = sp74B;
            func_0045af60(0, 0, 0, 0);
        } else if (D_008C024E & 0x40) {
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0xC4))), 0.0f);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0xC4))), 0.0f);
            var_18 = 0;
loop_71:
            if (((s64) (var_18 << 0x30) >> 0x30) < 2) {
                temp_16_17 = (u8 *)(temp_17 + (((s64) (var_18 << 0x30) >> 0x30) * 4));
                (*(u8 *)((u8 *)(temp_16_17) + (0xF3E))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_17) + (0xC44)))))) + (0x79)));
                (*(u8 *)((u8 *)(temp_16_17) + (0xF3F))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_17) + (0xC44)))))) + (0x7A)));
                (*(u8 *)((u8 *)(temp_16_17) + (0xF40))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_17) + (0xC44)))))) + (0x7B)));
                var_18 = (s64) ((var_18 + 1) << 0x30) >> 0x30;
                goto loop_71;
            }
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = 0;
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x12;
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E & 0x20) {
            var_16_8 = 0;
loop_76:
            if (((s64) (var_16_8 << 0x30) >> 0x30) < 7) {
                temp_4_2 = (s64) (var_16_8 << 0x30) >> 0x30;
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_4_2 * 4))) + (0xD20)))), 0xFFU, 0, 0, 5, (s64) ((temp_4_2 * 2) << 0x30) >> 0x30);
                var_16_8 = (s64) ((var_16_8 + 1) << 0x30) >> 0x30;
                goto loop_76;
            }
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0xFFU, 0, 0, 0, (s64) ((((*(s8 *)((u8 *)(temp_17) + (7))) * 2) + 2) << 0x30) >> 0x30);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0xFFU, 0, 0, 0, (s64) ((((*(s8 *)((u8 *)(temp_17) + (7))) * 2) + 2) << 0x30) >> 0x30);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
            temp_2_30 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
            temp_18_16 = (s64) (((s64)((func_0046b260((void *)(temp_2_30)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_16;
            temp_18_17 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_30)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_17;
            func_0046d280((void *)(temp_2_30));
            temp_16_18 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_16_18) + (0xC4))), 5.0f + (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0xC4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x2C))) = 14.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x30))) = 164.0f;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = 130.0f;
            temp_2_31 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_18 = (s64) (((s64)((func_0046b260((void *)(temp_2_31)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_18_18;
            temp_18_19 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_31)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = (s16) temp_18_19;
            temp_18_20 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_18_20) + (0xC4))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0xC4))) - 5.0f);
            func_0046d280((void *)(temp_2_31));
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 187.0f;
            temp_2_32 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_21 = (s64) (((s64)((func_0046b260((void *)(temp_2_32)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_18_21;
            temp_18_22 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_32)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = (s16) temp_18_22;
            func_0046d280((void *)(temp_2_32));
            temp_16_19 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_16_19) + (0xC4))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0xC4))) - 5.0f);
            var_16_9 = 0;
loop_79:
            temp_3_4 = (s64) (var_16_9 << 0x30) >> 0x30;
            if (temp_3_4 < 3) {
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_4 * 4))) + (0xC38)))), 0xFFU, 0, 0, 0xA, 0);
                var_16_9 = (s64) ((var_16_9 + 1) << 0x30) >> 0x30;
                goto loop_79;
            }
            (*(s8 *)((u8 *)(temp_17) + (7))) = 5;
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x13;
            func_0045af60(0, 0, 0, 2);
        }
        goto block_626;
    case 0x11:                                      /* switch 1 */
        var_16_10 = 0x55;
loop_85:
        temp_3_5 = (s64) (var_16_10 << 0x30) >> 0x30;
        if (temp_3_5 < 0x58) {
            temp_2_33 = (u8 *)(temp_17 + (temp_3_5 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_33) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_33) + (0xC38)))), 3, 0);
            }
            var_16_10 = (s64) ((var_16_10 + 1) << 0x30) >> 0x30;
            goto loop_85;
        }
        var_16_11 = 0x59;
loop_90:
        temp_3_6 = (s64) (var_16_11 << 0x30) >> 0x30;
        if (temp_3_6 < 0x60) {
            temp_2_34 = (u8 *)(temp_17 + (temp_3_6 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_34) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_34) + (0xC38)))), 3, 0);
            }
            var_16_11 = (s64) ((var_16_11 + 1) << 0x30) >> 0x30;
            goto loop_90;
        }
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 1) << 0x38) >> 0x38) == 0)) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x10;
        }
        goto block_626;
    case 0x12:                                      /* switch 1 */
loop_115:
        if (((s64) (var_19 << 0x30) >> 0x30) < 2) {
            temp_18_23 = (u8 *)(temp_17 + (((s64) (var_19 << 0x30) >> 0x30) * 4));
            temp_16_20 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_18_23) + (0xC44))))));
            temp_2_35 = (u8)((*(u8 *)((u8 *)(temp_18_23) + (0xF3E))));
            if ((s32) temp_2_35 >= 0) {
                var_f12 = (f32) temp_2_35;
            } else {
                var_f12 = 2.0f * (f32) ((temp_2_35 >> 1) | (temp_2_35 & 1));
            }
            temp_f0 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_20) + (0x79))) = var_3;
            temp_2_36 = (u8)((*(u8 *)((u8 *)(temp_18_23) + (0xF3F))));
            if ((s32) temp_2_36 >= 0) {
                var_f12_2 = (f32) temp_2_36;
            } else {
                var_f12_2 = 2.0f * (f32) ((temp_2_36 >> 1) | (temp_2_36 & 1));
            }
            temp_f0_2 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_2)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_2 >= 2.1474836e9f)) {
                var_3_2 = ((s32)(temp_f0_2)) & 0xFF;
            } else {
                var_3_2 = (((s32)((temp_f0_2 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_20) + (0x7A))) = var_3_2;
            temp_2_37 = (u8)((*(u8 *)((u8 *)(temp_18_23) + (0xF40))));
            if ((s32) temp_2_37 >= 0) {
                var_f12_3 = (f32) temp_2_37;
            } else {
                var_f12_3 = 2.0f * (f32) ((temp_2_37 >> 1) | (temp_2_37 & 1));
            }
            temp_f0_3 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_3)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_3 >= 2.1474836e9f)) {
                var_3_3 = ((s32)(temp_f0_3)) & 0xFF;
            } else {
                var_3_3 = (((s32)((temp_f0_3 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_20) + (0x7B))) = var_3_3;
            var_19 = (s64) ((var_19 + 1) << 0x30) >> 0x30;
            goto loop_115;
        }
        temp_4_3 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_3 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_3, 1, 6, 0, 1);
        } else {
            var_16_12 = 0;
loop_120:
            if (((s64) (var_16_12 << 0x30) >> 0x30) < 2) {
                temp_18_24 = (u8 *)(temp_17 + (((s64) (var_16_12 << 0x30) >> 0x30) * 4));
                temp_2_38 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_18_24) + (0xC44))))));
                (*(u8 *)((u8 *)(temp_2_38) + (0x79))) = (u8) (*(u8 *)((u8 *)(temp_18_24) + (0xF3E)));
                (*(u8 *)((u8 *)(temp_2_38) + (0x7A))) = (u8) (*(u8 *)((u8 *)(temp_18_24) + (0xF3F)));
                (*(u8 *)((u8 *)(temp_2_38) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_18_24) + (0xF40)));
                (*(u8 *)((u8 *)(temp_2_38) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_18_24) + (0xF41)));
                var_16_12 = (s64) ((var_16_12 + 1) << 0x30) >> 0x30;
                goto loop_120;
            }
            var_16_13 = 0;
loop_123:
            if (((s64) (var_16_13 << 0x30) >> 0x30) < 7) {
                temp_4_4 = (s64) (var_16_13 << 0x30) >> 0x30;
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_4_4 * 4))) + (0xD20)))), 0xFFU, 0, 0, 5, (s64) ((temp_4_4 * 2) << 0x30) >> 0x30);
                var_16_13 = (s64) ((var_16_13 + 1) << 0x30) >> 0x30;
                goto loop_123;
            }
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0xFFU, 0, 0, 0, (s64) ((((*(s8 *)((u8 *)(temp_17) + (7))) * 2) + 2) << 0x30) >> 0x30);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0xFFU, 0, 0, 0, (s64) ((((*(s8 *)((u8 *)(temp_17) + (7))) * 2) + 2) << 0x30) >> 0x30);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
            temp_2_39 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
            temp_18_25 = (s64) (((s64)((func_0046b260((void *)(temp_2_39)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_25;
            temp_18_26 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_39)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_26;
            func_0046d280((void *)(temp_2_39));
            temp_16_21 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_16_21) + (0xC4))), 5.0f + (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0xC4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x2C))) = 14.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x30))) = 164.0f;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = 130.0f;
            temp_2_40 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_27 = (s64) (((s64)((func_0046b260((void *)(temp_2_40)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_18_27;
            temp_18_28 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_40)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = (s16) temp_18_28;
            temp_18_29 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_18_29) + (0xC4))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0xC4))) - 5.0f);
            func_0046d280((void *)(temp_2_40));
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 187.0f;
            temp_2_41 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_30 = (s64) (((s64)((func_0046b260((void *)(temp_2_41)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_18_30;
            temp_18_31 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_41)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = (s16) temp_18_31;
            func_0046d280((void *)(temp_2_41));
            temp_16_22 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_16_22) + (0xC4))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0xC4))) - 5.0f);
            if ((*(s8 *)((u8 *)(temp_17) + (7))) != 5) {
                func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))));
                func_002b2970(&sp5C8, 0xC3830000U, 0xC2600000U);
                0;
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0, sp5C8, 0, 0xA, 0);
                func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))));
                func_002b2970(&sp5C0, 0xC1100000U, 0xC2600000U);
                0;
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0, sp5C0, 0, 0xA, 0);
                func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))));
                func_002b2970(&sp5B8, 0x439C0000U, 0xC30D0000U);
                0;
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0, sp5B8, 0, 0xA, 0);
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0, 0x708, 0, 0.0f, 360.0f);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 6, 0);
            }
            var_16_14 = 0;
loop_128:
            temp_3_7 = (s64) (var_16_14 << 0x30) >> 0x30;
            if (temp_3_7 < 3) {
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_7 * 4))) + (0xC38)))), 0xFFU, 0, 0, 0xA, 0);
                var_16_14 = (s64) ((var_16_14 + 1) << 0x30) >> 0x30;
                goto loop_128;
            }
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x13;
        }
        goto block_626;
    case 0x13:                                      /* switch 1 */
        var_16_15 = 0x55;
loop_134:
        temp_3_8 = (s64) (var_16_15 << 0x30) >> 0x30;
        if (temp_3_8 < 0x58) {
            temp_2_42 = (u8 *)(temp_17 + (temp_3_8 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_42) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_42) + (0xC38)))), 3, 0);
            }
            var_16_15 = (s64) ((var_16_15 + 1) << 0x30) >> 0x30;
            goto loop_134;
        }
        var_16_16 = 0x59;
loop_139:
        temp_3_9 = (s64) (var_16_16 << 0x30) >> 0x30;
        if (temp_3_9 < 0x60) {
            temp_2_43 = (u8 *)(temp_17 + (temp_3_9 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_43) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_43) + (0xC38)))), 3, 0);
            }
            var_16_16 = (s64) ((var_16_16 + 1) << 0x30) >> 0x30;
            goto loop_139;
        }
        if ((((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))) << 0x38) >> 0x38) == 0)) {
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 7, 6, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0xC4))), 0.0f);
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))));
            func_002b2970(&sp5B0, 0xC3C80000U, 0x43E10000U);
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, sp5B0, 0, 7, 6);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0xFFU, 0, 0, 7, 6);
            temp_16_23 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 7, 5, (*(f32 *)((u8 *)(temp_16_23) + (0xC4))), 30.0f + (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0xC4))));
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))));
            func_002b2970(&sp5A8, 0x442F0000U, ((u8)((f32) 0x2EE)));
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, sp5A8, 0, 7, 5);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0xFFU, 0, 0, 7, 5);
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))));
            func_002b2970(&sp5A0, 0x442F0000U, ((u8)((f32) 0x2EE)));
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, sp5A0, 0, 7, 3);
            temp_16_24 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 7, 3, (*(f32 *)((u8 *)(temp_16_24) + (0xC4))), 30.0f + (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0xC4))));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0xFFU, 0, 0, 7, 3);
            temp_2_44 = (s8)((*(s8 *)((u8 *)(temp_17) + (7))));
            switch (temp_2_44) {                    /* switch 2 */
            case 0:                                 /* switch 2 */
            case 1:                                 /* switch 2 */
            case 2:                                 /* switch 2 */
                func_002da0a0(arg0);
                break;
            case 3:                                 /* switch 2 */
                func_002db400(arg0);
                (*(s32 *)((u8 *)(temp_17) + (0xC20))) = 0;
                var_16_17 = 1;
loop_151:
                if (((s64) (var_16_17 << 0x30) >> 0x30) < func_002e26f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xF18)))))) {
                    temp_19_2 = (s64) (var_16_17 << 0x30) >> 0x30;
                    temp_18_32 = (s64) (func_002e2830((void *)((*(s32 *)((u8 *)(temp_17) + (0xF18)))), temp_19_2) << 0x30) >> 0x30;
                    func_002e28f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xF18)))), temp_19_2);
                    temp_20 = (s64) (temp_18_32 << 0x30) >> 0x30;
                    temp_19_3 = func_00110830(temp_20) & 0xFF;
                    func_002b2cb0(temp_19_3, func_00106600(temp_18_32) & 0xFF, 0xFF, 0, 1);
                    temp_19_4 = func_00106a90((s64) (temp_20 << 0x30) >> 0x30) / 5U;
                    temp_4_5 = (s32)((*(s32 *)((u8 *)(temp_17) + (0xC20))) + (temp_19_4 * (func_00106600(temp_18_32) & 0xFF)));
                    (*(s32 *)((u8 *)(temp_17) + (0xC20))) = temp_4_5;
                    (*(s32 *)((u8 *)(temp_17) + (0xC20))) = func_002b2cb0((s8) temp_4_5, 0, 0x98967F, 0, 1);
                    var_16_17 = (s64) ((var_16_17 + 1) << 0x30) >> 0x30;
                    goto loop_151;
                }
                break;
            case 4:                                 /* switch 2 */
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 1);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0, 1);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0xFFU, 0, 0, 0xA, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0xFFU, 0, 0, 0xA, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0xFFU, 0, 0, 0xA, 0);
                func_00331fc0(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x35;
                break;
            case 5:                                 /* switch 2 */
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 1);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0, 1);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0xFFU, 0, 0, 0xA, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0xFFU, 0, 0, 0xA, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0xFFU, 0, 0, 0xA, 0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x37;
                break;
            }
        }
        goto block_626;
    case 0x14:                                      /* switch 1 */
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))) << 0x38) >> 0x38) == 0) {
            temp_16_25 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
            func_002b2970(&sp598, (u8) (*(f32 *)((u8 *)(temp_16_25) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) - 4.0f))));
            temp_16_26 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
            func_002b2970(&sp590, (u8) (*(f32 *)((u8 *)(temp_16_26) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), sp598, sp590, 1, 4, 0);
            temp_16_27 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
            func_002b2970(&sp588, (u8) (*(f32 *)((u8 *)(temp_16_27) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) - 4.0f))));
            temp_16_28 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
            func_002b2970(&sp580, (u8) (*(f32 *)((u8 *)(temp_16_28) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), sp588, sp580, 1, 4, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x15;
        }
        /* fallthrough */
    case 0x15:                                      /* switch 1 */
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD60))))) << 0x38) >> 0x38) == 0) {
            func_002de5a0(arg0);
        }
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58))))) << 0x38) >> 0x38) == 0) {
            if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))) << 0x38) >> 0x38) != 0) {
                var_19 = 1;
            }
            if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))) << 0x38) >> 0x38) != 0) {
                var_19 = 1;
            }
            if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))) << 0x38) >> 0x38) != 0) {
                var_19 = 1;
            }
            if ((*(s8 *)((u8 *)(temp_17) + (0))) == 0x14) {
                var_19 = 1;
            }
            var_18_2 = 0;
loop_178:
            temp_5 = (s8)((*(s8 *)((u8 *)(temp_17) + (9))));
            temp_3_10 = (s64) (var_18_2 << 0x30) >> 0x30;
            if (temp_3_10 < temp_5) {
                temp_4_6 = (s16)((*(s16 *)((u8 *)((temp_17 + (temp_3_10 * 2))) + (0xF46))));
                if (temp_4_6 != 0) {
                    (*(s16 *)((u8 *)((temp_17 + (((s64) (var_18_2 << 0x30) >> 0x30) * 2))) + (0xF46))) = func_002b2d00((s8) temp_4_6, 1, 0, 0, 1);
                    var_19 = 1;
                } else {
                    temp_16_29 = (s64) (var_18_2 << 0x30) >> 0x30;
                    temp_2_45 = (u8 *)(temp_17 + (temp_16_29 * 2));
                    temp_23 = (u8 *)(temp_17 + temp_16_29);
                    temp_f0_4 = (f32)(s32)(func_002b2aa0(0, temp_5, 0.0f, 255.0f, (f32) (*(s16 *)((u8 *)(temp_2_45) + (0xF58)))));
                    if (!(temp_f0_4 >= 2.1474836e9f)) {
                        var_3_4 = ((s32)(temp_f0_4)) & 0xFF;
                    } else {
                        var_3_4 = (((s32)((temp_f0_4 - 2.1474836e9f))) | 0x80000000) & 0xFF;
                    }
                    (*(u8 *)((u8 *)(temp_23) + (0xF6A))) = var_3_4;
                    (*(s16 *)((u8 *)(temp_2_45) + (0xF58))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_2_45) + (0xF58))), 1, 6, 0, 1);
                    var_22 = (s32)(func_002b2a30(0xEC, 0x7FU, 0U, (*(u8 *)((u8 *)(temp_23) + (0xF6A)))));
                    if ((*(s8 *)((u8 *)(temp_17) + (8))) == temp_16_29) {
                        var_22 = (s32)(func_002b2a30(0x2D, 0x2DU, 0x2DU, (*(u8 *)((u8 *)(temp_23) + (0xF6A)))));
                    }
                    0;
                    func_002b2970(&sp578, 0x428E0000U, 0);
                    func_002e0080(arg0, (*(s8 *)((u8 *)(temp_23) + (0xF73))),(*(Vec2f *)&sp578),((void *)(s32)var_22));
                }
                var_18_2 = (s64) ((var_18_2 + 1) << 0x30) >> 0x30;
                goto loop_178;
            }
            if (((s64) (var_19 << 0x30) >> 0x30) == 0) {
                if (D_008C027A & 0x4000) {
                    (*(s8 *)((u8 *)(temp_17) + (8))) = func_002b2cb0((*(s8 *)((u8 *)(temp_17) + (8))), 1, temp_5 - 1, 0, 2);
                    func_002d83c0(arg0);
                    0;
                    temp_f20_14 = 0;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) = temp_f20_14;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) = temp_f20_14;
                    temp_16_30 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
                    func_002b2970(&sp570, (u8) (*(f32 *)((u8 *)(temp_16_30) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) - 4.0f))));
                    temp_16_31 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
                    func_002b2970(&sp568, (u8) (*(f32 *)((u8 *)(temp_16_31) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), sp570, sp568, 1, 2, 0);
                    temp_16_32 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
                    func_002b2970(&sp560, (u8) (*(f32 *)((u8 *)(temp_16_32) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) - 4.0f))));
                    temp_16_33 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
                    func_002b2970(&sp558, (u8) (*(f32 *)((u8 *)(temp_16_33) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), sp560, sp558, 1, 2, 0);
                    func_0045af60(0, 0, 0, 0);
                } else if (D_008C027A & 0x1000) {
                    (*(s8 *)((u8 *)(temp_17) + (8))) = func_002b2d00((*(s8 *)((u8 *)(temp_17) + (8))), 1, 0, temp_5 - 1, 2);
                    func_002d83c0(arg0);
                    0;
                    temp_f20_15 = 0;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) = temp_f20_15;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) = temp_f20_15;
                    temp_16_34 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
                    func_002b2970(&sp550, (u8) (*(f32 *)((u8 *)(temp_16_34) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) - 4.0f))));
                    temp_16_35 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
                    func_002b2970(&sp548, (u8) (*(f32 *)((u8 *)(temp_16_35) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), sp550, sp548, 1, 2, 0);
                    temp_16_36 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
                    func_002b2970(&sp540, (u8) (*(f32 *)((u8 *)(temp_16_36) + (0x2C))), ((u8)(((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) - 4.0f))));
                    temp_16_37 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
                    func_002b2970(&sp538, (u8) (*(f32 *)((u8 *)(temp_16_37) + (0x2C))), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), sp540, sp538, 1, 2, 0);
                    func_0045af60(0, 0, 0, 0);
                } else if (D_008C024E & 0x20) {
                    func_0045af60(0, 0, 0, 2);
                    func_002b2970(&sp530, (u8) (*(f32 *)((u8 *)(&D_0063F5A0) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F5A0) + (4))))));
                    func_002b2970(&sp528, (u8) (*(f32 *)((u8 *)(&D_0063F5A0) + (0))), ((u8)((500.0f + (*(f32 *)((u8 *)(&D_0063F5A0) + (4)))))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58)))), sp530, sp528, 0, 4, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58)))), 0xCCU, 0, 0, 2, 0);
                    func_002b2970(&sp520, (u8) (*(f32 *)((u8 *)(&D_0063F5A8) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F5A8) + (4))))));
                    func_002b2970(&sp518, (u8) (*(f32 *)((u8 *)(&D_0063F5A8) + (0))), ((u8)((500.0f + (*(f32 *)((u8 *)(&D_0063F5A8) + (4)))))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC5C)))), sp520, sp518, 0, 4, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC5C)))), 0xCCU, 0, 0, 2, 0);
                    func_002b2970(&sp510, ((u8)((*(f32 *)((u8 *)(&D_0063F7B0) + (0))))), ((u8)((*(f32 *)((u8 *)(&D_0063F7B0) + (4))))));
                    func_002b2970(&sp508, ((u8)((*(f32 *)((u8 *)(&D_0063F7B0) + (0))))), ((u8)((400.0f + (*(f32 *)((u8 *)(&D_0063F7B0) + (4)))))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD60)))), sp510, sp508, 2, 4, 0);
                    func_002b2970(&sp500, ((u8)((*(f32 *)((u8 *)(&D_0063F7B8) + (0))))), ((u8)((*(f32 *)((u8 *)(&D_0063F7B8) + (4))))));
                    func_002b2970(&sp4F8, ((u8)((*(f32 *)((u8 *)(&D_0063F7B8) + (0))))), ((u8)((400.0f + (*(f32 *)((u8 *)(&D_0063F7B8) + (4)))))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD64)))), sp500, sp4F8, 2, 4, 0);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 1);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))), 0, 1);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD3C)))), 0, 1);
                    var_19_2 = 0;
loop_187:
                    if (((s64) (var_19_2 << 0x30) >> 0x30) < 6) {
                        temp_18_33 = (s64) (var_19_2 << 0x30) >> 0x30;
                        temp_16_38 = (u8 *)((s32)&D_0063F560 + ((temp_18_33 + 0x43) * 8));
                        func_002b2970(&sp4F0, (u8) (*(f32 *)((u8 *)(temp_16_38) + (0))), (u8) (*(f32 *)((u8 *)(temp_16_38) + (4))));
                        func_002b2970(&sp4E8, (u8) (*(f32 *)((u8 *)(temp_16_38) + (0))), 0x442F0000U);
                        func_002e0620((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_33 * 4))) + (0xD44)))), sp4F0, sp4E8, 2, 5, 0);
                        var_19_2 = (s64) ((var_19_2 + 1) << 0x30) >> 0x30;
                        goto loop_187;
                    }
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), 0, 1);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), 0, 1);
                    func_002dd230(arg0);
                    var_16_18 = 0;
loop_190:
                    temp_3_11 = (s64) (var_16_18 << 0x30) >> 0x30;
                    if (temp_3_11 < 7) {
                        func_002e04f0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_11 * 4))) + (0xD20)))), 0, 0);
                        var_16_18 = (s64) ((var_16_18 + 1) << 0x30) >> 0x30;
                        goto loop_190;
                    }
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0, 0);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0, 0);
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0x41, 46.0f);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0U, 0xFF, 0, 6, 0);
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x2C))) = 198.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x30))) = (f32) 0x151;
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0x41, 146.0f);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0U, 0xFF, 0, 6, 0);
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))))) + (0x2C))) = 216.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))))) + (0x30))) = 368.0f;
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
                    temp_2_46 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
                    temp_18_34 = (s64) (((s64)(func_0046b260((void *)(temp_2_46)))) << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_34;
                    temp_18_35 = (s64) (((s64)(func_0046b2f0((void *)(temp_2_46)))) << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_35;
                    func_0046d280((void *)(temp_2_46));
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0U, 0xCC, 0, 4, 4);
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 4, 4, 0.0f, fGpffff8520);
                    func_002b2970(&sp4E0, 0xC3700000U, 0x43C80000U);
                    func_002b2970(&sp4D8, 0xC3700000U, 0x439B0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), sp4E0, sp4D8, 0, 4, 4);
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 110.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = -50.0f;
                    temp_2_47 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
                    temp_18_36 = (s64) (((s64)(func_0046b260((void *)(temp_2_47)))) << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_18_36;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = 0;
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 4, 4, -90.0f, fGpffff8524);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0U, 0xFF, 0, 4, 4);
                    func_0046d280((void *)(temp_2_47));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 180.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 30.0f;
                    temp_2_48 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
                    temp_16_39 = (s64) (((s64)(func_0046b260((void *)(temp_2_48)))) << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_16_39;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = 0;
                    func_0046d280((void *)(temp_2_48));
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 4, 2, -85.0f, fGpffff8528);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0U, 0xFF, 0, 4, 2);
                    var_21 = 0;
loop_195:
                    if (((s64) (var_21 << 0x30) >> 0x30) < 7) {
                        temp_19_5 = (s64) (var_21 << 0x30) >> 0x30;
                        temp_18_37 = (u8 *)((s32)&D_0063F560 + ((temp_19_5 + 0x3A) * 8));
                        temp_3_12 = (u8 *)(temp_17 + (temp_19_5 * 4));
                        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_3_12) + (0xD20)))), 0x56, (f32) (temp_19_5 + 0x64));
                        if (temp_19_5 > 0) {
                            func_002b2a60(&sp744, 0xED, 0x80, 0, 0xFFU);
                            temp_2_49 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_3_12) + (0xD20))))));
                            (*(u8 *)((u8 *)(temp_2_49) + (0x79))) = sp744;
                            (*(u8 *)((u8 *)(temp_2_49) + (0x7A))) = sp745;
                            (*(u8 *)((u8 *)(temp_2_49) + (0x7B))) = sp746;
                            (*(u8 *)((u8 *)(temp_2_49) + (0x7C))) = sp747;
                        }
                        temp_2_50 = (u8 *)(temp_17 + (((s64) (var_21 << 0x30) >> 0x30) * 4));
                        func_002b2970(&sp4D0, ((u8)((80.0f + (*(f32 *)((u8 *)(temp_18_37) + (0)))))), (u8) (*(f32 *)((u8 *)(temp_18_37) + (4))));
                        func_002b2970(&sp4C8, ((u8)((*(f32 *)((u8 *)(temp_18_37) + (0))))), (u8) (*(f32 *)((u8 *)(temp_18_37) + (4))));
                        func_002e0620((void *)((*(s32 *)((u8 *)(temp_2_50) + (0xD20)))), sp4D0, sp4C8, 0, 3, var_21);
                        func_002e0660((void *)((*(s32 *)((u8 *)(temp_2_50) + (0xD20)))), 0U, 0xFF, 0, 3, var_21);
                        var_21 = (s64) ((var_21 + 1) << 0x30) >> 0x30;
                        goto loop_195;
                    }
                    func_002b2a60(&sp740, 0x2D, 0x2D, 0x2D, 0xFFU);
                    temp_2_51 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
                    (*(u8 *)((u8 *)(temp_2_51) + (0x79))) = sp740;
                    (*(u8 *)((u8 *)(temp_2_51) + (0x7A))) = sp741;
                    (*(u8 *)((u8 *)(temp_2_51) + (0x7B))) = sp742;
                    (*(u8 *)((u8 *)(temp_2_51) + (0x7C))) = sp743;
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0U, 0xFF, 0, 0, (s64) (*(s8 *)((u8 *)(temp_17) + (7))));
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0U, 0xFF, 0, 0, (s64) (*(s8 *)((u8 *)(temp_17) + (7))));
                    var_16_19 = 0;
loop_198:
                    temp_3_13 = (s64) (var_16_19 << 0x30) >> 0x30;
                    if (temp_3_13 < 3) {
                        func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_13 * 4))) + (0xC38)))), 0U, 0xFF, 0, 0xA, 0);
                        var_16_19 = (s64) ((var_16_19 + 1) << 0x30) >> 0x30;
                        goto loop_198;
                    }
                    func_002d7f90(arg0);
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x11;
                } else if (D_008C024E & 0x40) {
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0xC4))), 0.0f);
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0xC4))), 0.0f);
                    var_18_3 = 0;
loop_203:
                    if (((s64) (var_18_3 << 0x30) >> 0x30) < 2) {
                        temp_16_40 = (u8 *)(temp_17 + (((s64) (var_18_3 << 0x30) >> 0x30) * 4));
                        (*(u8 *)((u8 *)(temp_16_40) + (0xF3E))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_40) + (0xED4)))))) + (0x79)));
                        (*(u8 *)((u8 *)(temp_16_40) + (0xF3F))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_40) + (0xED4)))))) + (0x7A)));
                        (*(u8 *)((u8 *)(temp_16_40) + (0xF40))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_40) + (0xED4)))))) + (0x7B)));
                        var_18_3 = (s64) ((var_18_3 + 1) << 0x30) >> 0x30;
                        goto loop_203;
                    }
                    (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = 0;
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x16;
                    func_0045af60(0, 0, 0, 1);
                }
            }
        }
        goto block_626;
    case 0x16:                                      /* switch 1 */
        func_002de5a0(arg0);
loop_215:
        temp_3_14 = (s64) (var_19 << 0x30) >> 0x30;
        if (temp_3_14 < (*(s8 *)((u8 *)(temp_17) + (9)))) {
            temp_4_7 = (s16)((*(s16 *)((u8 *)((temp_17 + (temp_3_14 * 2))) + (0xF46))));
            if (temp_4_7 != 0) {
                (*(s16 *)((u8 *)((temp_17 + (((s64) (var_19 << 0x30) >> 0x30) * 2))) + (0xF46))) = func_002b2d00((s8) temp_4_7, 1, 0, 0, 1);
            } else {
                temp_18_38 = (s64) (var_19 << 0x30) >> 0x30;
                temp_2_52 = (u8 *)(temp_17 + (temp_18_38 * 2));
                temp_22 = (u8 *)(temp_17 + temp_18_38);
                temp_f0_5 = (f32)(s32)(func_002b2aa0(0, 0, 255.0f, (f32) (*(s16 *)((u8 *)(temp_2_52) + (0xF58))), 6.0f));
                if (!(temp_f0_5 >= 2.1474836e9f)) {
                    var_3_5 = ((s32)(temp_f0_5)) & 0xFF;
                } else {
                    var_3_5 = (((s32)((temp_f0_5 - 2.1474836e9f))) | 0x80000000) & 0xFF;
                }
                (*(u8 *)((u8 *)(temp_22) + (0xF6A))) = var_3_5;
                (*(s16 *)((u8 *)(temp_2_52) + (0xF58))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_2_52) + (0xF58))), 1, 6, 0, 1);
                var_21_2 = (s32)(func_002b2a30(0xEC, 0x7FU, 0U, (*(u8 *)((u8 *)(temp_22) + (0xF6A)))));
                if ((*(s8 *)((u8 *)(temp_17) + (8))) == temp_18_38) {
                    var_21_2 = (s32)(func_002b2a30(0x2D, 0x2DU, 0x2DU, (*(u8 *)((u8 *)(temp_22) + (0xF6A)))));
                }
                0;
                func_002b2970(&sp4C0, 0x428E0000U, 0);
                func_002e0080(arg0, (*(s8 *)((u8 *)(temp_22) + (0xF73))),(*(Vec2f *)&sp4C0),((void *)(s32)var_21_2));
            }
            var_19 = (s64) ((var_19 + 1) << 0x30) >> 0x30;
            goto loop_215;
        }
        var_19_3 = 0;
loop_236:
        if (((s64) (var_19_3 << 0x30) >> 0x30) < 2) {
            temp_18_39 = (u8 *)(temp_17 + (((s64) (var_19_3 << 0x30) >> 0x30) * 4));
            temp_16_41 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_18_39) + (0xED4))))));
            temp_2_53 = (u8)((*(u8 *)((u8 *)(temp_18_39) + (0xF3E))));
            if ((s32) temp_2_53 >= 0) {
                var_f12_4 = (f32) temp_2_53;
            } else {
                var_f12_4 = 2.0f * (f32) ((temp_2_53 >> 1) | (temp_2_53 & 1));
            }
            temp_f0_6 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_4)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_6 >= 2.1474836e9f)) {
                var_3_6 = ((s32)(temp_f0_6)) & 0xFF;
            } else {
                var_3_6 = (((s32)((temp_f0_6 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_41) + (0x79))) = var_3_6;
            temp_2_54 = (u8)((*(u8 *)((u8 *)(temp_18_39) + (0xF3F))));
            if ((s32) temp_2_54 >= 0) {
                var_f12_5 = (f32) temp_2_54;
            } else {
                var_f12_5 = 2.0f * (f32) ((temp_2_54 >> 1) | (temp_2_54 & 1));
            }
            temp_f0_7 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_5)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_7 >= 2.1474836e9f)) {
                var_3_7 = ((s32)(temp_f0_7)) & 0xFF;
            } else {
                var_3_7 = (((s32)((temp_f0_7 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_41) + (0x7A))) = var_3_7;
            temp_2_55 = (u8)((*(u8 *)((u8 *)(temp_18_39) + (0xF40))));
            if ((s32) temp_2_55 >= 0) {
                var_f12_6 = (f32) temp_2_55;
            } else {
                var_f12_6 = 2.0f * (f32) ((temp_2_55 >> 1) | (temp_2_55 & 1));
            }
            temp_f0_8 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_6)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_8 >= 2.1474836e9f)) {
                var_3_8 = ((s32)(temp_f0_8)) & 0xFF;
            } else {
                var_3_8 = (((s32)((temp_f0_8 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_41) + (0x7B))) = var_3_8;
            var_19_3 = (s64) ((var_19_3 + 1) << 0x30) >> 0x30;
            goto loop_236;
        }
        temp_4_8 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_8 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_8, 1, 6, 0, 1);
        } else {
            var_18_4 = 0;
loop_241:
            if (((s64) (var_18_4 << 0x30) >> 0x30) < 2) {
                temp_16_42 = (u8 *)(temp_17 + (((s64) (var_18_4 << 0x30) >> 0x30) * 4));
                temp_2_56 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_42) + (0xED4))))));
                (*(u8 *)((u8 *)(temp_2_56) + (0x79))) = (u8) (*(u8 *)((u8 *)(temp_16_42) + (0xF3E)));
                (*(u8 *)((u8 *)(temp_2_56) + (0x7A))) = (u8) (*(u8 *)((u8 *)(temp_16_42) + (0xF3F)));
                (*(u8 *)((u8 *)(temp_2_56) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_16_42) + (0xF40)));
                (*(u8 *)((u8 *)(temp_2_56) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_16_42) + (0xF41)));
                var_18_4 = (s64) ((var_18_4 + 1) << 0x30) >> 0x30;
                goto loop_241;
            }
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 0x41, 38.0f);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 0, 5, 0, -105.0f, 27.0f);
            func_002b2a60(&sp73C, 0x97, 0xF, 0, 0xFFU);
            temp_2_57 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C))))));
            (*(u8 *)((u8 *)(temp_2_57) + (0x79))) = sp73C;
            (*(u8 *)((u8 *)(temp_2_57) + (0x7A))) = sp73D;
            (*(u8 *)((u8 *)(temp_2_57) + (0x7B))) = sp73E;
            (*(u8 *)((u8 *)(temp_2_57) + (0x7C))) = sp73F;
            temp_18_40 = (s64) (((s64)((173.0f - (*(f32 *)((u8 *)(&D_0063F7C8) + (0)))))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))))) + (0x100))) = (s16) temp_18_40;
            temp_16_43 = (s64) (((s64)(((f32) 0x223 - (*(f32 *)((u8 *)(&D_0063F7C8) + (4)))))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))))) + (0x102))) = (s16) temp_16_43;
            func_002b2970(&sp4B8, (u8) (*(f32 *)((u8 *)(&D_0063F780) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F780) + (4))))));
            func_002b2970(&sp4B0, 0xC3020000U, ((u8)(((*(f32 *)((u8 *)(&D_0063F780) + (4))) - 50.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD48)))), sp4B8, sp4B0, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD48)))), 0, 7, 3, 0.0f, -20.0f);
            func_002b2970(&sp4A8, ((u8)((*(f32 *)((u8 *)(&D_0063F778) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F778) + (4))));
            func_002b2970(&sp4A0, ((u8)(((*(f32 *)((u8 *)(&D_0063F778) + (0))) - 200.0f))), 0xC3020000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD44)))), sp4A8, sp4A0, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD44)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp498, ((u8)((*(f32 *)((u8 *)(&D_0063F788) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F788) + (4))));
            func_002b2970(&sp490, ((u8)(((*(f32 *)((u8 *)(&D_0063F788) + (0))) - 40.0f))), ((u8)((f32) 0x226)));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD4C)))), sp498, sp490, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD4C)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp488, ((u8)((*(f32 *)((u8 *)(&D_0063F798) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F798) + (4))));
            func_002b2970(&sp480, ((u8)((40.0f + (*(f32 *)((u8 *)(&D_0063F798) + (0)))))), ((u8)((f32) 0x226)));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD54)))), sp488, sp480, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD54)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp478, ((u8)((*(f32 *)((u8 *)(&D_0063F790) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F790) + (4))));
            func_002b2970(&sp470, ((u8)((40.0f + (*(f32 *)((u8 *)(&D_0063F790) + (0)))))), 0xC3160000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD50)))), sp478, sp470, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD50)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp468, ((u8)((*(f32 *)((u8 *)(&D_0063F7A0) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F7A0) + (4))));
            func_002b2970(&sp460, ((u8)((40.0f + (*(f32 *)((u8 *)(&D_0063F7A0) + (0)))))), 0xC3480000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD58)))), sp468, sp460, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD58)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp458, ((u8)((*(f32 *)((u8 *)(&D_0063F7B0) + (0))))), ((u8)((*(f32 *)((u8 *)(&D_0063F7B0) + (4))))));
            func_002b2970(&sp450, ((u8)(((f32) 0x29E + (*(f32 *)((u8 *)(&D_0063F7B0) + (0)))))), ((u8)(((*(f32 *)((u8 *)(&D_0063F7B0) + (4))) - 300.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD60)))), sp458, sp450, 1, 0xA, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD60)))), 1, 4, 3, fGpffff852C, 60.0f);
            func_002b2970(&sp448, ((u8)((*(f32 *)((u8 *)(&D_0063F7B8) + (0))))), ((u8)((*(f32 *)((u8 *)(&D_0063F7B8) + (4))))));
            func_002b2970(&sp440, ((u8)(((f32) 0x29E + (*(f32 *)((u8 *)(&D_0063F7B8) + (0)))))), ((u8)(((*(f32 *)((u8 *)(&D_0063F7B8) + (4))) - 300.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD64)))), sp448, sp440, 1, 4, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD64)))), 1, 4, 3, fGpffff852C, 60.0f);
            func_002b2970(&sp438, (u8) (*(f32 *)((u8 *)(&D_0063F5A0) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F5A0) + (4))))));
            func_002b2970(&sp430, (u8) (*(f32 *)((u8 *)(&D_0063F5A0) + (0))), ((u8)((500.0f + (*(f32 *)((u8 *)(&D_0063F5A0) + (4)))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58)))), sp438, sp430, 0, 4, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58)))), 0xCCU, 0, 0, 2, 0);
            func_002b2970(&sp428, (u8) (*(f32 *)((u8 *)(&D_0063F5A8) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F5A8) + (4))))));
            func_002b2970(&sp420, (u8) (*(f32 *)((u8 *)(&D_0063F5A8) + (0))), ((u8)((500.0f + (*(f32 *)((u8 *)(&D_0063F5A8) + (4)))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC5C)))), sp428, sp420, 0, 4, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC5C)))), 0xCCU, 0, 0, 2, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD3C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))), 0, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x17;
        }
        goto block_626;
    case 0x17:                                      /* switch 1 */
        if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 3) << 0x38) >> 0x38) == 0) {
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 0, 3, 0, 27.0f, -14.0f);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), 0x41, 157.0f);
            func_002b2970(&sp418, ((u8)((*(f32 *)((u8 *)(&D_0063F5B8) + (0))))), ((u8)((-300.0f + (*(f32 *)((u8 *)(&D_0063F5B8) + (4)))))));
            func_002b2970(&sp410, ((u8)((*(f32 *)((u8 *)(&D_0063F5B8) + (0))))), ((u8)((*(f32 *)((u8 *)(&D_0063F5B8) + (4))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), sp418, sp410, 0, 7, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), 0U, 0xCC, 0, 7, 0);
            func_002b2a60(&sp738, 0, 0, 0, 0xFFU);
            temp_2_58 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64))))));
            (*(u8 *)((u8 *)(temp_2_58) + (0x79))) = sp738;
            (*(u8 *)((u8 *)(temp_2_58) + (0x7A))) = sp739;
            (*(u8 *)((u8 *)(temp_2_58) + (0x7B))) = sp73A;
            (*(u8 *)((u8 *)(temp_2_58) + (0x7C))) = sp73B;
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), 0, 0, 0, 0.0f, -4.0f);
            temp_18_41 = (s64) (((s64)((320.0f - (*(f32 *)((u8 *)(&D_0063F5B8) + (0)))))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))))) + (0x100))) = (s16) temp_18_41;
            temp_16_44 = (s64) (((s64)(((*(f32 *)((u8 *)(&D_0063F5B8) + (4))) - 83.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))))) + (0x102))) = (s16) temp_16_44;
            func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), 0, 0, 0, 0x3F800000, 0x3FC00000, 1.0f, 0x3F800000);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x18;
        }
        goto block_626;
    case 0x18:                                      /* switch 1 */
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64))))) << 0x38) >> 0x38) == 0) {
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))), 0x41, 152.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))), 0U, 0xCC, 0, 5, 0);
            func_002b2a60(&sp734, 0, 0, 0, 0xFFU);
            temp_2_59 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C))))));
            (*(u8 *)((u8 *)(temp_2_59) + (0x79))) = sp734;
            (*(u8 *)((u8 *)(temp_2_59) + (0x7A))) = sp735;
            (*(u8 *)((u8 *)(temp_2_59) + (0x7B))) = sp736;
            (*(u8 *)((u8 *)(temp_2_59) + (0x7C))) = sp737;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))), 0x41, ((f32)(sp734)));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))), 0U, 0xCC, 0, 5, 0);
            func_002b2a60(&sp730, 0, 0, 0, 0xFFU);
            temp_2_60 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30))))));
            (*(u8 *)((u8 *)(temp_2_60) + (0x79))) = sp730;
            (*(u8 *)((u8 *)(temp_2_60) + (0x7A))) = sp731;
            (*(u8 *)((u8 *)(temp_2_60) + (0x7B))) = sp732;
            (*(u8 *)((u8 *)(temp_2_60) + (0x7C))) = sp733;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), 0x41, ((f32)(sp730)));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), 0U, 0xFF, 0, 0xA, 0);
            func_002b2970(&sp408, 0x42380000U, 0x43930000U);
            temp_2_61 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70))))));
            (*(f32 *)((u8 *)(temp_2_61) + (0x2C))) = (f32) sp408;
            (*(f32 *)((u8 *)(temp_2_61) + (0x30))) = unksp40C;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C)))), 0x41, 8.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C)))), 0U, 0xFF, 0, 0xA, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD8)))), 0x41, 45.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD8)))), 0U, 0xFF, 0, 6, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0x41, 46.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0U, 0xFF, 0, 6, 0);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x2C))) = (f32) 0x17F;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x30))) = 404.0f;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))), 0x41, 47.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))), 0U, 0xFF, 0, 6, 0);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))))) + (0x2C))) = 446.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))))) + (0x30))) = 404.0f;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4)))), 0x41, 47.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4)))), 0U, 0xFF, 0, 6, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))), 0x41, 47.0f);
            temp_16_45 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4))))));
            temp_2_62 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0))))));
            (*(f32 *)((u8 *)(temp_2_62) + (0x2C))) = (f32) (*(f32 *)((u8 *)(temp_16_45) + (0x2C)));
            (*(f32 *)((u8 *)(temp_2_62) + (0x30))) = (f32) (*(f32 *)((u8 *)(temp_16_45) + (0x30)));
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))))) + (0x62))) = 0xFF;
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))), 0, 1);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0x41, 139.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0U, 0xFF, 0, 6, 0);
            func_002b2a60(&sp72C, 0xCE, 0x71, 2, 0xFFU);
            temp_2_63 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C))))));
            (*(u8 *)((u8 *)(temp_2_63) + (0x79))) = sp72C;
            (*(u8 *)((u8 *)(temp_2_63) + (0x7A))) = sp72D;
            (*(u8 *)((u8 *)(temp_2_63) + (0x7B))) = sp72E;
            (*(u8 *)((u8 *)(temp_2_63) + (0x7C))) = sp72F;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0x41, ((f32)(sp72C)));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0U, 0xFF, 0, 6, 0);
            func_002b2a60(&sp728, 0xCE, 0x71, 2, 0xFFU);
            temp_2_64 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90))))));
            (*(u8 *)((u8 *)(temp_2_64) + (0x79))) = sp728;
            (*(u8 *)((u8 *)(temp_2_64) + (0x7A))) = sp729;
            (*(u8 *)((u8 *)(temp_2_64) + (0x7B))) = sp72A;
            (*(u8 *)((u8 *)(temp_2_64) + (0x7C))) = sp72B;
            (*(s16 *)((u8 *)(temp_17) + (4))) = 0;
            (*(s16 *)((u8 *)(temp_17) + (2))) = 0;
            temp_2_65 = (s8)((*(s8 *)((u8 *)(temp_17) + (7))));
            switch (temp_2_65) {                    /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                temp_3_15 = (u8 *)((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17);
                func_002e24a0(1 << ((s64) (((*(s8 *)((u8 *)(temp_3_15) + (0xF7C))) - 0x14) << 0x30) >> 0x30), 1 << ((*(s8 *)((u8 *)(temp_3_15) + (0xF73))) + 4), 2, 2);
                break;
            case 1:                                 /* switch 3 */
                func_002e24a0(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                break;
            case 2:                                 /* switch 3 */
                func_002e24a0(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                break;
            }
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
        }
        goto block_626;
    case 0x1B:                                      /* switch 1 */
        func_002cb6c0(arg0, 0);
        func_002b2970(&sp400, ((u8)((f32) 0x24E)), 0x42740000U);
        func_002b2a60(&sp724, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_17_2 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_46 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp400, (s32) sp724, (*(RGBA *)&(u32){0x11}), 5, temp_17_2, 0x70, 0x7A, temp_16_46, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        goto block_626;
    case 0x1C:                                      /* switch 1 */
        func_002cb6c0(arg0, 1);
        func_002b2970(&sp3F8, ((u8)((f32) 0x24E)), 0x42740000U);
        func_002b2a60(&sp720, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_42 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_47 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3F8, (s32) sp720, (*(RGBA *)&(u32){0x11}), 5, temp_18_42, 0x70, 0x7A, temp_16_47, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        var_21_3 = 0;
loop_275:
        if (((s64) (var_21_3 << 0x30) >> 0x30) < 2) {
            temp_19_6 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8))))));
            temp_18_43 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_16_48 = (u8 *)(temp_17 + (((s64) (var_21_3 << 0x30) >> 0x30) * 4));
            temp_2_66 = (u8)((*(u8 *)((u8 *)(temp_16_48) + (0xF3E))));
            if ((s32) temp_2_66 >= 0) {
                var_f12_7 = (f32) temp_2_66;
            } else {
                var_f12_7 = 2.0f * (f32) ((temp_2_66 >> 1) | (temp_2_66 & 1));
            }
            temp_f0_9 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_7)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_9 >= 2.1474836e9f)) {
                var_3_9 = ((s32)(temp_f0_9)) & 0xFF;
            } else {
                var_3_9 = (((s32)((temp_f0_9 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_43) + (0x79))) = var_3_9;
            (*(s8 *)((u8 *)(temp_19_6) + (0x79))) = var_3_9;
            temp_2_67 = (u8)((*(u8 *)((u8 *)(temp_16_48) + (0xF3F))));
            if ((s32) temp_2_67 >= 0) {
                var_f12_8 = (f32) temp_2_67;
            } else {
                var_f12_8 = 2.0f * (f32) ((temp_2_67 >> 1) | (temp_2_67 & 1));
            }
            temp_f0_10 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_8)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_10 >= 2.1474836e9f)) {
                var_3_10 = ((s32)(temp_f0_10)) & 0xFF;
            } else {
                var_3_10 = (((s32)((temp_f0_10 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_43) + (0x7A))) = var_3_10;
            (*(s8 *)((u8 *)(temp_19_6) + (0x7A))) = var_3_10;
            temp_2_68 = (u8)((*(u8 *)((u8 *)(temp_16_48) + (0xF40))));
            if ((s32) temp_2_68 >= 0) {
                var_f12_9 = (f32) temp_2_68;
            } else {
                var_f12_9 = 2.0f * (f32) ((temp_2_68 >> 1) | (temp_2_68 & 1));
            }
            temp_f0_11 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_9)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_11 >= 2.1474836e9f)) {
                var_3_11 = ((s32)(temp_f0_11)) & 0xFF;
            } else {
                var_3_11 = (((s32)((temp_f0_11 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_43) + (0x7B))) = var_3_11;
            (*(s8 *)((u8 *)(temp_19_6) + (0x7B))) = var_3_11;
            var_21_3 = (s64) ((var_21_3 + 1) << 0x30) >> 0x30;
            goto loop_275;
        }
        temp_4_9 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_9 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_9, 1, 6, 0, 1);
        } else {
            temp_2_69 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8))))));
            temp_6 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3E))));
            temp_5_2 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3F))));
            (*(u8 *)((u8 *)(temp_2_69) + (0x79))) = temp_6;
            (*(u8 *)((u8 *)(temp_2_69) + (0x7A))) = temp_5_2;
            (*(u8 *)((u8 *)(temp_2_69) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF40)));
            (*(u8 *)((u8 *)(temp_2_69) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF41)));
            temp_2_70 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_6_2 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF42))));
            temp_5_3 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF43))));
            (*(u8 *)((u8 *)(temp_2_70) + (0x79))) = temp_6_2;
            (*(u8 *)((u8 *)(temp_2_70) + (0x7A))) = temp_5_3;
            (*(u8 *)((u8 *)(temp_2_70) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF44)));
            (*(u8 *)((u8 *)(temp_2_70) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF45)));
            sp6A0 = (s32)(func_002e2740((*(s16 *)((u8 *)(temp_17) + (2))), temp_5_3, temp_6_2));
            sp6A4 = 0;
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 1, &sp6A0, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1D;
            func_002d6190(arg0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 1);
        }
        goto block_626;
    case 0x1D:                                      /* switch 1 */
        func_002d5040(arg0);
        func_002b2970(&sp3F0, ((u8)((f32) 0x24E)), 0x42740000U);
        func_002b2a60(&sp71C, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_44 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_49 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3F0, (s32) sp71C, (*(RGBA *)&(u32){0x11}), 5, temp_18_44, 0x70, 0x7A, temp_16_49, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        func_002b2970(&sp3E8, 0x424C0000U, 0x42400000U);
        func_002e0080(arg0, (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))),(*(Vec2f *)&sp3E8), (void *)func_002b2a30(0xFF, 0xFFU, 0xFFU, 0xFFU));
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
            func_0045af60(0, 0, 0, 6);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            temp_16_50 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
            func_002e7a80(func_002e7a60() - temp_16_50);
            sp698 = (s32)(func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))));
            sp69C = 0;
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 4, &sp698, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1E;
        } else {
            func_002d7300(arg0);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 0);
        }
        goto block_626;
    case 0x1E:                                      /* switch 1 */
        func_002d5040(arg0);
        func_002b2970(&sp3E0, 0x424C0000U, 0x42400000U);
        func_002e0080(arg0, (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))),(*(Vec2f *)&sp3E0), (void *)func_002b2a30(0xFF, 0xFFU, 0xFFU, 0xFFU));
        func_002b2970(&sp3D8, ((u8)((f32) 0x24E)), 0x42740000U);
        func_002b2a60(&sp718, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_45 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_51 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3D8, (s32) sp718, (*(RGBA *)&(u32){0x11}), 5, temp_18_45, 0x70, 0x7A, temp_16_51, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
                func_0045af60(0, 0, 0, 7);
                func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
                sp690 = (s32) ((s64) (func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7)))) << 0x30) >> 0x30);
                sp694 = 0;
                (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 5, &sp690, 1);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1F;
            } else {
                func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
                temp_16_52 = (s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30;
                func_00106620(temp_16_52, ((func_00106600((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30) & 0xFF) + 1) & 0xFF);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
            }
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 0);
            if (func_002e2670() >= 6) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 0, 0);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0, 0);
            }
            func_002d7300(arg0);
        }
        goto block_626;
    case 0x1F:                                      /* switch 1 */
        func_002d5040(arg0);
        func_002cb6c0(arg0, 1);
        func_002b2970(&sp3D0, ((u8)((f32) 0x24E)), 0x42740000U);
        func_002b2a60(&sp714, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_46 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_53 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3D0, (s32) sp714, (*(RGBA *)&(u32){0x11}), 5, temp_18_46, 0x70, 0x7A, temp_16_53, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
                temp_16_54 = (u32)(func_00106a90(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7))))) >> 2);
                func_002e7a80(func_002e7a60() + temp_16_54);
                func_0045af60(0, 0, 0, 6);
            } else {
                temp_16_55 = (s64)(s32)(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7)))));
                func_00106620(temp_16_55, ((func_00106600(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7))))) & 0xFF) + 1) & 0xFF);
            }
            func_00106d40((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7))), (s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
        }
        goto block_626;
    case 0x20:                                      /* switch 1 */
        func_002cb6c0(arg0, 1);
        func_002b2970(&sp3C8, ((u8)((f32) 0x24E)), 0x42740000U);
        func_002b2a60(&sp710, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_47 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_56 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3C8, (s32) sp710, (*(RGBA *)&(u32){0x11}), 5, temp_18_47, 0x70, 0x7A, temp_16_56, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 9) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 9) << 0x38) >> 0x38) == 0)) {
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 0, 4, 0, -14.0f, 110.0f);
            func_002e0690((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), 0, 5, 0, 0x3F800000, 0x3FC00000);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))))) + (0x62))), 0, 0, 5, 0);
            temp_18_48 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x4E));
            func_002b2970(&sp3C0, (u8) (*(f32 *)((u8 *)(&D_0063F7D0) + (0))), (u8) (*(f32 *)((u8 *)(&D_0063F7D0) + (4))));
            func_0046b260((void *)(temp_18_48));
            0;
            func_0046b2f0((void *)(temp_18_48));
            0;
            func_002b2970(&sp3B8, 0, 0);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), sp3C0, sp3B8, 0, 5, 0);
            func_0046d280((void *)(temp_18_48));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C)))))) + (0x62))), 0, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))))) + (0x62))), 0, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))))) + (0x62))), 0, 0, 5, 0);
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))));
            temp_f20_16 = (f32)(s32)((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))))) + (0x2C))) - 1000.0f);
            func_002b2970(&sp3B0, ((u8)(temp_f20_16)), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))))) + (0x30))));
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 0, sp3B0, 2, 3, 0);
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))));
            temp_f20_17 = (f32)(s32)((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))))) + (0x2C))) - 1000.0f);
            func_002b2970(&sp3A8, ((u8)(temp_f20_17)), (u8) (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))))) + (0x30))));
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0, sp3A8, 2, 3, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))), 0, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))))) + (0x62))), 0, 0, 0xA, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC60)))), 0x41, 109.0f);
            func_002b2970(&sp3A0, ((u8)((660.0f + (*(f32 *)((u8 *)(&D_0063F5B0) + (0)))))), (u8) (*(f32 *)((u8 *)(&D_0063F5B0) + (4))));
            func_002b2970(&sp398, ((u8)((*(f32 *)((u8 *)(&D_0063F5B0) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F5B0) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC60)))), sp3A0, sp398, 0, 4, 6);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC60)))))) + (0x62))) = 0xCC;
            func_002b2a60(&sp70C, 0, 0, 0, 0xFFU);
            temp_2_71 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC60))))));
            (*(u8 *)((u8 *)(temp_2_71) + (0x79))) = sp70C;
            (*(u8 *)((u8 *)(temp_2_71) + (0x7A))) = sp70D;
            (*(u8 *)((u8 *)(temp_2_71) + (0x7B))) = sp70E;
            (*(u8 *)((u8 *)(temp_2_71) + (0x7C))) = sp70F;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC80)))), 0x41, ((f32)(sp70C)));
            func_002b2970(&sp390, ((u8)((660.0f + (*(f32 *)((u8 *)(&D_0063F5F0) + (0)))))), (u8) (*(f32 *)((u8 *)(&D_0063F5F0) + (4))));
            func_002b2970(&sp388, ((u8)((*(f32 *)((u8 *)(&D_0063F5F0) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F5F0) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC80)))), sp390, sp388, 0, 4, 6);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC80)))))) + (0x62))) = 0xCC;
            func_002b2a60(&sp708, 0, 0, 0, 0xFFU);
            temp_2_72 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC80))))));
            (*(u8 *)((u8 *)(temp_2_72) + (0x79))) = sp708;
            (*(u8 *)((u8 *)(temp_2_72) + (0x7A))) = sp709;
            (*(u8 *)((u8 *)(temp_2_72) + (0x7B))) = sp70A;
            (*(u8 *)((u8 *)(temp_2_72) + (0x7C))) = sp70B;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC70)))), 0x41, ((f32)(sp708)));
            func_002b2970(&sp380, ((u8)((660.0f + (*(f32 *)((u8 *)(&D_0063F5D0) + (0)))))), (u8) (*(f32 *)((u8 *)(&D_0063F5D0) + (4))));
            func_002b2970(&sp378, ((u8)((*(f32 *)((u8 *)(&D_0063F5D0) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F5D0) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC70)))), sp380, sp378, 0, 4, 6);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC70)))))) + (0x62))) = 0xCC;
            func_002b2a60(&sp704, 0, 0, 0, 0xFFU);
            temp_2_73 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC70))))));
            (*(u8 *)((u8 *)(temp_2_73) + (0x79))) = sp704;
            (*(u8 *)((u8 *)(temp_2_73) + (0x7A))) = sp705;
            (*(u8 *)((u8 *)(temp_2_73) + (0x7B))) = sp706;
            (*(u8 *)((u8 *)(temp_2_73) + (0x7C))) = sp707;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE80)))), 0x41, ((f32)(sp704)));
            func_002b2970(&sp370, ((u8)((f32) -0x266)), 0x43720000U);
            func_002b2970(&sp368, 0x42AC0000U, 0x43720000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE80)))), sp370, sp368, 0, 4, 6);
            func_002b2a60(&sp700, 0xFF, 0xCB, 0x35, 0xFFU);
            temp_2_74 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE80))))));
            (*(u8 *)((u8 *)(temp_2_74) + (0x79))) = sp700;
            (*(u8 *)((u8 *)(temp_2_74) + (0x7A))) = sp701;
            (*(u8 *)((u8 *)(temp_2_74) + (0x7B))) = sp702;
            (*(u8 *)((u8 *)(temp_2_74) + (0x7C))) = sp703;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC84)))), 0x41, ((f32)(sp700)));
            func_002b2970(&sp360, ((u8)(((*(f32 *)((u8 *)(&D_0063F5F8) + (0))) - 700.0f))), (u8) (*(f32 *)((u8 *)(&D_0063F5F8) + (4))));
            func_002b2970(&sp358, ((u8)((*(f32 *)((u8 *)(&D_0063F5F8) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F5F8) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC84)))), sp360, sp358, 0, 4, 6);
            func_002b2a60(&sp6FC, 0xFF, 0xCB, 0x35, 0xFFU);
            temp_2_75 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC84))))));
            (*(u8 *)((u8 *)(temp_2_75) + (0x79))) = sp6FC;
            (*(u8 *)((u8 *)(temp_2_75) + (0x7A))) = sp6FD;
            (*(u8 *)((u8 *)(temp_2_75) + (0x7B))) = sp6FE;
            (*(u8 *)((u8 *)(temp_2_75) + (0x7C))) = sp6FF;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC74)))), 0x41, ((f32)(sp6FC)));
            func_002b2970(&sp350, ((u8)(((*(f32 *)((u8 *)(&D_0063F5D8) + (0))) - 700.0f))), (u8) (*(f32 *)((u8 *)(&D_0063F5D8) + (4))));
            func_002b2970(&sp348, ((u8)((*(f32 *)((u8 *)(&D_0063F5D8) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F5D8) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC74)))), sp350, sp348, 0, 4, 6);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC78)))), 0x41, 114.0f);
            func_002b2970(&sp340, ((u8)(((*(f32 *)((u8 *)(&D_0063F5E0) + (0))) - 700.0f))), (u8) (*(f32 *)((u8 *)(&D_0063F5E0) + (4))));
            func_002b2970(&sp338, ((u8)((*(f32 *)((u8 *)(&D_0063F5E0) + (0))))), (u8) (*(f32 *)((u8 *)(&D_0063F5E0) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC78)))), sp340, sp338, 0, 4, 6);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x21;
        }
        goto block_626;
    case 0x21:                                      /* switch 1 */
        if (func_002d1590(arg0) == 1) {
            if ((D_008C0276 & 0x1000) && ((*(s8 *)((u8 *)(temp_17) + (0x14))) == 0)) {
                func_0045af60(0, 0, 0, 0);
                if ((*(s16 *)((u8 *)(temp_17) + (2))) == 0) {
                    temp_2_76 = func_002e26a0();
                    (*(s16 *)((u8 *)(temp_17) + (2))) = temp_2_76;
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2cb0(0, (s64) ((s64) temp_2_76 << 0x30) >> 0x30, 4, 0, 1);
                } else {
                    (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 1, 0, func_002e2670(), 2);
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), (s64) (func_002e2670() << 0x30) >> 0x30, 5, -1);
                }
                (*(s8 *)((u8 *)(temp_17) + (0x14))) = 1;
                return 0;
            }
            if (D_008C027A & 0x1000) {
                if (func_002e2670() > 0) {
                    if ((*(s16 *)((u8 *)(temp_17) + (2))) != 0) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 1, 0, 0, 1);
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), (s64) (func_002e2670() << 0x30) >> 0x30, 5, -1);
                    (*(s8 *)((u8 *)(temp_17) + (0x14))) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C0276 & 0x4000) && ((*(s8 *)((u8 *)(temp_17) + (0x14))) == 0)) {
                func_0045af60(0, 0, 0, 0);
                temp_2_77 = (s16)(func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 1, func_002e26a0(), 0, 2));
                (*(s16 *)((u8 *)(temp_17) + (2))) = temp_2_77;
                if (((s64) ((s64) temp_2_77 << 0x30) >> 0x30) == 0) {
                    (*(s16 *)((u8 *)(temp_17) + (4))) = 0;
                } else if (func_002e26a0() >= 5) {
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), (s64) (func_002e26a0() << 0x30) >> 0x30, 5, 1);
                } else {
                    temp_16_57 = (s64) (func_002e26a0() << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), temp_16_57, (s64) (func_002e2670() << 0x30) >> 0x30, 1);
                }
                (*(s8 *)((u8 *)(temp_17) + (0x14))) = 1;
                return 0;
            }
            if (D_008C027A & 0x4000) {
                if (func_002e2670() > 0) {
                    temp_16_58 = (s16)((*(s16 *)((u8 *)(temp_17) + (2))));
                    if (temp_16_58 != func_002e26a0()) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 1, func_002e26a0(), 0, 1);
                    if (func_002e26a0() >= 5) {
                        (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), (s64) (func_002e26a0() << 0x30) >> 0x30, 5, 1);
                    } else {
                        temp_16_59 = (s64) (func_002e26a0() << 0x30) >> 0x30;
                        (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), temp_16_59, (s64) (func_002e2670() << 0x30) >> 0x30, 1);
                    }
                    (*(s8 *)((u8 *)(temp_17) + (0x14))) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C027A & 2) || (D_008C027A & 0x2000)) {
                temp_16_60 = (s16)((*(s16 *)((u8 *)(temp_17) + (2))));
                if (temp_16_60 != func_002e26a0()) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2e70((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), func_002e2670(), 5, temp_17 + 2, temp_17 + 4);
            } else if ((D_008C027A & 1) || (D_008C027A & 0x8000)) {
                if ((*(s16 *)((u8 *)(temp_17) + (2))) != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2f90((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), func_002e2670(), 5, temp_17 + 2, temp_17 + 4);
            } else if (D_008C027A & 8) {
                (*(s16 *)((u8 *)(temp_17) + (2))) = 0;
                (*(s16 *)((u8 *)(temp_17) + (4))) = 0;
                (*(s8 *)((u8 *)(temp_17) + (8))) = func_002b2cb0((*(s8 *)((u8 *)(temp_17) + (8))), 1, (*(s8 *)((u8 *)(temp_17) + (9))) - 1, 0, 2);
                temp_2_78 = (s8)((*(s8 *)((u8 *)(temp_17) + (7))));
                switch (temp_2_78) {                /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    temp_3_16 = (u8 *)((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17);
                    func_002e2a10(1 << ((s64) (((*(s8 *)((u8 *)(temp_3_16) + (0xF7C))) - 0x14) << 0x30) >> 0x30), 1 << ((*(s8 *)((u8 *)(temp_3_16) + (0xF73))) + 4), 2, 2);
                    break;
                case 1:                             /* switch 4 */
                    func_002e2a10(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                    break;
                case 2:                             /* switch 4 */
                    func_002e2a10(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                    break;
                }
                func_002caef0(arg0);
                func_002d8200(arg0, 0);
                func_0045af60(0, 0, 0, 5);
            } else if (D_008C027A & 4) {
                (*(s16 *)((u8 *)(temp_17) + (2))) = 0;
                (*(s16 *)((u8 *)(temp_17) + (4))) = 0;
                (*(s8 *)((u8 *)(temp_17) + (8))) = func_002b2d00((*(s8 *)((u8 *)(temp_17) + (8))), 1, 0, (*(s8 *)((u8 *)(temp_17) + (9))) - 1, 2);
                temp_2_79 = (s8)((*(s8 *)((u8 *)(temp_17) + (7))));
                switch (temp_2_79) {                /* switch 5; irregular */
                case 0:                             /* switch 5 */
                    temp_3_17 = (u8 *)((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17);
                    func_002e2a10(1 << ((s64) (((*(s8 *)((u8 *)(temp_3_17) + (0xF7C))) - 0x14) << 0x30) >> 0x30), 1 << ((*(s8 *)((u8 *)(temp_3_17) + (0xF73))) + 4), 2, 2);
                    break;
                case 1:                             /* switch 5 */
                    func_002e2a10(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                    break;
                case 2:                             /* switch 5 */
                    func_002e2a10(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                    break;
                }
                func_002caef0(arg0);
                func_002d8200(arg0, 0);
                func_0045af60(0, 0, 0, 5);
            } else if (D_008C024E & 0x20) {
                func_002d3ee0(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x22;
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))))) + (0xC4))), 0.0f);
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))))) + (0xC4))), 0.0f);
                func_0045af60(0, 1, 0, 4);
            } else if (D_008C024E & 0x80) {
                func_002d3ee0(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x22;
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))))) + (0xC4))), 0.0f);
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))))) + (0xC4))), 0.0f);
                func_0045af60(0, 1, 0, 4);
            } else if (D_008C024E & 0x40) {
                if (func_002e2670() > 0) {
                    temp_16_61 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
                    if ((func_002e7a60() >= temp_16_61) && ((func_00106600((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30) & 0xFF) < 0x63)) {
                        sp688 = (s32)(func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))));
                        sp68C = 0;
                        (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 1, &sp688, 1);
                        (*(s8 *)((u8 *)(temp_17) + (0))) = 0x23;
                        func_0045af60(0, 0, 0, 1);
                    } else {
                        func_0045af60(0, 0, 0, 8);
                    }
                } else {
                    func_0045af60(0, 0, 0, 8);
                }
            }
block_368:
            (*(s8 *)((u8 *)(temp_17) + (0x14))) = 0;
            goto block_626;
        }
        goto block_626;
    case 0x22:                                      /* switch 1 */
        func_002b2970(&sp330, ((u8)((f32) 0x24E)), 0x42740000U);
        func_002b2a60(&sp6F8, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_49 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_62 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp330, (s32) sp6F8, (*(RGBA *)&(u32){0x11}), 5, temp_18_49, 0x70, 0x7A, temp_16_62, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        func_002cb6c0(arg0, 0);
        if ((((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90))))) << 0x38) >> 0x38) == 0)) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
        }
        goto block_626;
    case 0x23:                                      /* switch 1 */
        func_002d1590(arg0);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
            func_0045af60(0, 0, 0, 6);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            func_002d3ee0(arg0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 1);
            sp680 = (s32)(func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))));
            sp684 = 0;
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 4, &sp680, 1);
            func_002d6190(arg0);
            temp_16_63 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
            func_002e7a80(func_002e7a60() - temp_16_63);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1E;
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x21;
        }
        goto block_626;
    case 0x24:                                      /* switch 1 */
        (*(s16 *)((u8 *)(temp_17) + (0x12))) = 1;
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64))))) << 0x38) >> 0x38) == 0) {
            func_002cdf80(arg0, 0);
        }
        goto block_626;
    case 0x25:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
loop_401:
        if (((s64) (var_19 << 0x30) >> 0x30) < 2) {
            temp_18_50 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_16_64 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_21 = (u8 *)(temp_17 + (((s64) (var_19 << 0x30) >> 0x30) * 4));
            temp_2_80 = (u8)((*(u8 *)((u8 *)(temp_21) + (0xF3E))));
            if ((s32) temp_2_80 >= 0) {
                var_f12_10 = (f32) temp_2_80;
            } else {
                var_f12_10 = 2.0f * (f32) ((temp_2_80 >> 1) | (temp_2_80 & 1));
            }
            temp_f0_12 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_10)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_12 >= 2.1474836e9f)) {
                var_3_12 = ((s32)(temp_f0_12)) & 0xFF;
            } else {
                var_3_12 = (((s32)((temp_f0_12 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_64) + (0x79))) = var_3_12;
            (*(s8 *)((u8 *)(temp_18_50) + (0x79))) = var_3_12;
            temp_2_81 = (u8)((*(u8 *)((u8 *)(temp_21) + (0xF3F))));
            if ((s32) temp_2_81 >= 0) {
                var_f12_11 = (f32) temp_2_81;
            } else {
                var_f12_11 = 2.0f * (f32) ((temp_2_81 >> 1) | (temp_2_81 & 1));
            }
            temp_f0_13 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_11)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_13 >= 2.1474836e9f)) {
                var_3_13 = ((s32)(temp_f0_13)) & 0xFF;
            } else {
                var_3_13 = (((s32)((temp_f0_13 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_64) + (0x7A))) = var_3_13;
            (*(s8 *)((u8 *)(temp_18_50) + (0x7A))) = var_3_13;
            temp_2_82 = (u8)((*(u8 *)((u8 *)(temp_21) + (0xF40))));
            if ((s32) temp_2_82 >= 0) {
                var_f12_12 = (f32) temp_2_82;
            } else {
                var_f12_12 = 2.0f * (f32) ((temp_2_82 >> 1) | (temp_2_82 & 1));
            }
            temp_f0_14 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_12)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_14 >= 2.1474836e9f)) {
                var_3_14 = ((s32)(temp_f0_14)) & 0xFF;
            } else {
                var_3_14 = (((s32)((temp_f0_14 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_64) + (0x7B))) = var_3_14;
            (*(s8 *)((u8 *)(temp_18_50) + (0x7B))) = var_3_14;
            var_19 = (s64) ((var_19 + 1) << 0x30) >> 0x30;
            goto loop_401;
        }
        temp_4_10 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_10 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_10, 1, 6, 0, 1);
        } else {
            temp_2_83 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_6_3 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3E))));
            temp_5_4 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3F))));
            (*(u8 *)((u8 *)(temp_2_83) + (0x79))) = temp_6_3;
            (*(u8 *)((u8 *)(temp_2_83) + (0x7A))) = temp_5_4;
            (*(u8 *)((u8 *)(temp_2_83) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF40)));
            (*(u8 *)((u8 *)(temp_2_83) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF41)));
            temp_2_84 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_6_4 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF42))));
            temp_5_5 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF43))));
            (*(u8 *)((u8 *)(temp_2_84) + (0x79))) = temp_6_4;
            (*(u8 *)((u8 *)(temp_2_84) + (0x7A))) = temp_5_5;
            (*(u8 *)((u8 *)(temp_2_84) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF44)));
            (*(u8 *)((u8 *)(temp_2_84) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF45)));
            temp_3_18 = (s8)((*(s8 *)((u8 *)(temp_17) + (0x11))));
            if ((temp_3_18 == 0) && ((*(s16 *)((u8 *)(temp_17) + (2))) == 0)) {
                var_19_4 = 0;
                var_18_5 = 1;
loop_408:
                temp_16_65 = (s64) (var_18_5 << 0x30) >> 0x30;
                if (temp_16_65 < func_002e26f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))))) {
                    temp_2_85 = (s64)(s32)(func_002e2830((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_65));
                    temp_21_2 = func_00106a90((s64) (temp_2_85 << 0x30) >> 0x30) / 5U;
                    var_19_4 += temp_21_2 * (func_00106600((s64) (temp_2_85 << 0x30) >> 0x30) & 0xFF);
                    var_18_5 = (s64) ((var_18_5 + 1) << 0x30) >> 0x30;
                    goto loop_408;
                }
                func_00442088(&spD0, D_00713910, func_002b2cb0(var_19_4, 0, 0x98967F, 0, 1));
                (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 6, &spD0, 1);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2E;
            } else if (func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_3_18 * 4) + temp_17)) + (0xF18))))) > 0) {
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), 0xFFU, 0, 0, 5, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0xFFU, 0, 0, 5, 0);
                if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 0) {
                    temp_16_66 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x2A));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), 0x56, 16.0f);
                    func_002b2a60(&sp6F4, 0xFE, 0xC6, 0x31, 0xFFU);
                    temp_2_86 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0))))));
                    (*(u8 *)((u8 *)(temp_2_86) + (0x79))) = sp6F4;
                    (*(u8 *)((u8 *)(temp_2_86) + (0x7A))) = sp6F5;
                    (*(u8 *)((u8 *)(temp_2_86) + (0x7B))) = sp6F6;
                    (*(u8 *)((u8 *)(temp_2_86) + (0x7C))) = sp6F7;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), 0, 5, 0, 0x3F800000, 0x3F800000, 0.5f, 0x3F800000);
                    func_0046b2f0((void *)(temp_16_66));
                    0;
                    func_002b2970(&sp328, 0x427C0000U, 0);
                    func_002b2970(&sp320, 0x427C0000U, 0x430F0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), sp328, sp320, 0, 5, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), 0U, 0xFF, 0, 0, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_66));
                    temp_16_67 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x2C));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0x56, 18.0f);
                    func_002b2a60(&sp6F0, 0xFE, 0xC6, 0x31, 0xFFU);
                    temp_2_87 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8))))));
                    (*(u8 *)((u8 *)(temp_2_87) + (0x79))) = sp6F0;
                    (*(u8 *)((u8 *)(temp_2_87) + (0x7A))) = sp6F1;
                    (*(u8 *)((u8 *)(temp_2_87) + (0x7B))) = sp6F2;
                    (*(u8 *)((u8 *)(temp_2_87) + (0x7C))) = sp6F3;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0, 5, 0, 0x3F800000, 0x3F800000, 0.5f, 0x3F800000);
                    func_0046b2f0((void *)(temp_16_67));
                    0;
                    func_002b2970(&sp318, ((u8)((f32) 0x222)), 0);
                    func_002b2970(&sp310, ((u8)((f32) 0x222)), 0x430F0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), sp318, sp310, 0, 5, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0U, 0xFF, 0, 0, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_67));
                    temp_16_68 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x27));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), 0x41, 20.0f);
                    func_002b2a60(&sp6EC, 0xFF, 0x96, 0, 0xFFU);
                    temp_2_88 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4))))));
                    (*(u8 *)((u8 *)(temp_2_88) + (0x79))) = sp6EC;
                    (*(u8 *)((u8 *)(temp_2_88) + (0x7A))) = sp6ED;
                    (*(u8 *)((u8 *)(temp_2_88) + (0x7B))) = sp6EE;
                    (*(u8 *)((u8 *)(temp_2_88) + (0x7C))) = sp6EF;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), 2, 4, 0, 0x3F800000, 0x3F800000, fGpffff8170, 0x3F800000);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), 0U, 0xFF, 0, 4, 0);
                    func_0046b2f0((void *)(temp_16_68));
                    0;
                    func_002b2970(&sp308, 0x42380000U, 0);
                    func_002b2970(&sp300, 0x42380000U, 0x43040000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), sp308, sp300, 2, 4, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_68));
                    temp_16_69 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x29));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 0x41, 21.0f);
                    func_002b2a60(&sp6E8, 0xFF, 0x96, 0, 0xFFU);
                    temp_2_89 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC))))));
                    (*(u8 *)((u8 *)(temp_2_89) + (0x79))) = sp6E8;
                    (*(u8 *)((u8 *)(temp_2_89) + (0x7A))) = sp6E9;
                    (*(u8 *)((u8 *)(temp_2_89) + (0x7B))) = sp6EA;
                    (*(u8 *)((u8 *)(temp_2_89) + (0x7C))) = sp6EB;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 2, 4, 0, 0x3F800000, 0x3F800000, fGpffff8170, 0x3F800000);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 0U, 0xFF, 0, 4, 0);
                    func_0046b2f0((void *)(temp_16_69));
                    0;
                    func_002b2970(&sp2F8, ((u8)((f32) 0x232)), 0);
                    func_002b2970(&sp2F0, ((u8)((f32) 0x232)), 0x43040000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), sp2F8, sp2F0, 2, 4, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_69));
                } else {
                    temp_16_70 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x2B));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), 0x56, 16.0f);
                    func_002b2a60(&sp6E4, 0xFE, 0xC6, 0x31, 0xFFU);
                    temp_2_90 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4))))));
                    (*(u8 *)((u8 *)(temp_2_90) + (0x79))) = sp6E4;
                    (*(u8 *)((u8 *)(temp_2_90) + (0x7A))) = sp6E5;
                    (*(u8 *)((u8 *)(temp_2_90) + (0x7B))) = sp6E6;
                    (*(u8 *)((u8 *)(temp_2_90) + (0x7C))) = sp6E7;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), 0, 5, 0, 0x3F800000, 0x3F800000, 0.5f, 0x3F800000);
                    func_0046b2f0((void *)(temp_16_70));
                    0;
                    func_002b2970(&sp2E8, 0x42860000U, 0);
                    func_002b2970(&sp2E0, 0x42860000U, 0x430C0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), sp2E8, sp2E0, 0, 5, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), 0U, 0xFF, 0, 0, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_70));
                    temp_16_71 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x2C));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0x56, 18.0f);
                    func_002b2a60(&sp6E0, 0xFE, 0xC6, 0x31, 0xFFU);
                    temp_2_91 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8))))));
                    (*(u8 *)((u8 *)(temp_2_91) + (0x79))) = sp6E0;
                    (*(u8 *)((u8 *)(temp_2_91) + (0x7A))) = sp6E1;
                    (*(u8 *)((u8 *)(temp_2_91) + (0x7B))) = sp6E2;
                    (*(u8 *)((u8 *)(temp_2_91) + (0x7C))) = sp6E3;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0, 5, 0, 0x3F800000, 0x3F800000, 0.5f, 0x3F800000);
                    func_0046b2f0((void *)(temp_16_71));
                    0;
                    func_002b2970(&sp2D8, ((u8)((f32) 0x22F)), 0);
                    func_002b2970(&sp2D0, ((u8)((f32) 0x22F)), 0x430C0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), sp2D8, sp2D0, 0, 5, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0U, 0xFF, 0, 0, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_71));
                    temp_16_72 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x28));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), 0x41, 20.0f);
                    func_002b2a60(&sp6DC, 0xFF, 0x96, 0, 0xFFU);
                    temp_2_92 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8))))));
                    (*(u8 *)((u8 *)(temp_2_92) + (0x79))) = sp6DC;
                    (*(u8 *)((u8 *)(temp_2_92) + (0x7A))) = sp6DD;
                    (*(u8 *)((u8 *)(temp_2_92) + (0x7B))) = sp6DE;
                    (*(u8 *)((u8 *)(temp_2_92) + (0x7C))) = sp6DF;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), 2, 4, 0, 0x3F800000, 0x3F800000, fGpffff8170, 0x3F800000);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), 0U, 0xFF, 0, 4, 0);
                    func_0046b2f0((void *)(temp_16_72));
                    0;
                    func_002b2970(&sp2C8, 0x42400000U, 0);
                    func_002b2970(&sp2C0, 0x42400000U, 0x42FE0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), sp2C8, sp2C0, 2, 4, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_72));
                    temp_16_73 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x29));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 0x41, 21.0f);
                    func_002b2a60(&sp6D8, 0xFF, 0x96, 0, 0xFFU);
                    temp_2_93 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC))))));
                    (*(u8 *)((u8 *)(temp_2_93) + (0x79))) = sp6D8;
                    (*(u8 *)((u8 *)(temp_2_93) + (0x7A))) = sp6D9;
                    (*(u8 *)((u8 *)(temp_2_93) + (0x7B))) = sp6DA;
                    (*(u8 *)((u8 *)(temp_2_93) + (0x7C))) = sp6DB;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 2, 4, 0, 0x3F800000, 0x3F800000, fGpffff8170, 0x3F800000);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 0U, 0xFF, 0, 4, 0);
                    func_0046b2f0((void *)(temp_16_73));
                    0;
                    func_002b2970(&sp2B8, 0x44120000U, 0);
                    func_002b2970(&sp2B0, 0x44120000U, 0x42FE0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), sp2B8, sp2B0, 2, 4, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_73));
                }
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), 0x57, 14.0f);
                func_002b2970(&sp2A8, (u8) (*(f32 *)((u8 *)(&D_0063F688) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F688) + (4))))));
                func_002b2970(&sp2A0, (u8) (*(f32 *)((u8 *)(&D_0063F688) + (0))), ((u8)(((*(f32 *)((u8 *)(&D_0063F688) + (4))) - 7.0f))));
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), sp2A8, sp2A0, 1, 0xA, 2);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), 0U, 0xFF, 0, 0xA, 2);
                (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))))) + (0x3B))) = 1;
                func_002b2a60(&sp6D4, 0xFF, 0x96, 0, 0xFFU);
                temp_2_94 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC))))));
                (*(u8 *)((u8 *)(temp_2_94) + (0x79))) = sp6D4;
                (*(u8 *)((u8 *)(temp_2_94) + (0x7A))) = sp6D5;
                (*(u8 *)((u8 *)(temp_2_94) + (0x7B))) = sp6D6;
                (*(u8 *)((u8 *)(temp_2_94) + (0x7C))) = sp6D7;
                (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))))) + (0x85))) = 1;
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), 0x57, 15.0f);
                func_002b2970(&sp298, (u8) (*(f32 *)((u8 *)(&D_0063F690) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F690) + (4))))));
                func_002b2970(&sp290, (u8) (*(f32 *)((u8 *)(&D_0063F690) + (0))), ((u8)((7.0f + (*(f32 *)((u8 *)(&D_0063F690) + (4)))))));
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), sp298, sp290, 1, 0xA, 2);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), 0U, 0xFF, 0, 0xA, 2);
                (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))))) + (0x3B))) = 1;
                func_002b2a60(&sp6D0, 0xFF, 0x96, 0, 0xFFU);
                temp_2_95 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0))))));
                (*(u8 *)((u8 *)(temp_2_95) + (0x79))) = sp6D0;
                (*(u8 *)((u8 *)(temp_2_95) + (0x7A))) = sp6D1;
                (*(u8 *)((u8 *)(temp_2_95) + (0x7B))) = sp6D2;
                (*(u8 *)((u8 *)(temp_2_95) + (0x7C))) = sp6D3;
                (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))))) + (0x85))) = 1;
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8)))), 0x57, 15.0f);
                func_002b2a60(&sp6CC, 0xDF, 0x6C, 0, 0xFFU);
                temp_2_96 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8))))));
                (*(u8 *)((u8 *)(temp_2_96) + (0x79))) = sp6CC;
                (*(u8 *)((u8 *)(temp_2_96) + (0x7A))) = sp6CD;
                (*(u8 *)((u8 *)(temp_2_96) + (0x7B))) = sp6CE;
                (*(u8 *)((u8 *)(temp_2_96) + (0x7C))) = sp6CF;
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8)))), 0U, 0xFF, 0, 4, 2);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x27;
            }
        }
        goto block_626;
    case 0x27:                                      /* switch 1 */
        temp_16_74 = (s64) (func_002e2830((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), (s64) (*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30;
        temp_18_51 = (s32)(func_002e28f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), (s64) (*(s16 *)((u8 *)(temp_17) + (2)))) & 0xFF);
        func_002cdf80(arg0, 2);
        func_002df020(arg0, temp_16_74, temp_18_51);
        func_002dd3b0(arg0);
        if (D_008C027A & 0x1000) {
            temp_18_52 = (s16)((*(s16 *)((u8 *)(temp_17) + (0x12))));
            if (temp_18_52 != (func_00106600(temp_16_74) & 0xFF)) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)((u8 *)(temp_17) + (0x12))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (0x12))), 1, func_00106600(temp_16_74) & 0xFF, 1, 1);
            func_002b2970(&sp288, (u8) (*(f32 *)((u8 *)(&D_0063F688) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F688) + (4))))));
            func_002b2970(&sp280, (u8) (*(f32 *)((u8 *)(&D_0063F688) + (0))), ((u8)(((*(f32 *)((u8 *)(&D_0063F688) + (4))) - 7.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), sp288, sp280, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))))) + (0x85))) = 1;
        } else if (D_008C027A & 0x2000) {
            temp_18_53 = (s16)((*(s16 *)((u8 *)(temp_17) + (0x12))));
            if (temp_18_53 != (func_00106600(temp_16_74) & 0xFF)) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)((u8 *)(temp_17) + (0x12))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (0x12))), 0xA, func_00106600(temp_16_74) & 0xFF, 1, 1);
            func_002b2970(&sp278, (u8) (*(f32 *)((u8 *)(&D_0063F688) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F688) + (4))))));
            func_002b2970(&sp270, (u8) (*(f32 *)((u8 *)(&D_0063F688) + (0))), ((u8)(((*(f32 *)((u8 *)(&D_0063F688) + (4))) - 7.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), sp278, sp270, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))))) + (0x85))) = 1;
        } else if (D_008C027A & 0x4000) {
            if ((*(s16 *)((u8 *)(temp_17) + (0x12))) != 1) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)((u8 *)(temp_17) + (0x12))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (0x12))), 1, 1, func_00106600(temp_16_74) & 0xFF, 1);
            func_002b2970(&sp268, (u8) (*(f32 *)((u8 *)(&D_0063F690) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F690) + (4))))));
            func_002b2970(&sp260, (u8) (*(f32 *)((u8 *)(&D_0063F690) + (0))), ((u8)((7.0f + (*(f32 *)((u8 *)(&D_0063F690) + (4)))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), sp268, sp260, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))))) + (0x85))) = 1;
        } else if (D_008C027A & 0x8000) {
            if ((*(s16 *)((u8 *)(temp_17) + (0x12))) != 1) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)((u8 *)(temp_17) + (0x12))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (0x12))), 0xA, 1, func_00106600(temp_16_74) & 0xFF, 1);
            func_002b2970(&sp258, (u8) (*(f32 *)((u8 *)(&D_0063F690) + (0))), ((u8)((*(f32 *)((u8 *)(&D_0063F690) + (4))))));
            func_002b2970(&sp250, (u8) (*(f32 *)((u8 *)(&D_0063F690) + (0))), ((u8)((7.0f + (*(f32 *)((u8 *)(&D_0063F690) + (4)))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), sp258, sp250, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))))) + (0x85))) = 1;
        } else if (D_008C024E & 0x40) {
            sp678 = (s32) ((s64) (temp_16_74 << 0x30) >> 0x30);
            sp67C = 0;
            func_00442088(&spC0, D_00713910, (s8) (*(s16 *)((u8 *)(temp_17) + (0x12))));
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dff90(arg0, 2, &sp678, &spC0, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x28;
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E & 0x20) {
            func_0045af60(0, 0, 0, 2);
            func_002df4c0(arg0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), 0xFFU, 0, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), 0xFFU, 0, 0, 5, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8)))), 0, 1);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), 0U, 0xFF, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0U, 0xFF, 0, 5, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
            if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x31;
            }
        }
        goto block_626;
    case 0x28:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        temp_19_7 = (s64) (func_002e2830((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), (s64) (*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30;
        temp_16_75 = (s64) (func_002e28f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), (s64) (*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30;
        temp_18_54 = (s64)(s32)(func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))));
        temp_23_2 = (s16)((*(s16 *)((u8 *)(temp_17) + (2))));
        temp_30 = (s16)((*(s16 *)((u8 *)(temp_17) + (4))));
        func_002df020(arg0, temp_19_7, temp_16_75 & 0xFF);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            (*(s16 *)((u8 *)(temp_17) + (0xC16))) = 0;
            (*(s16 *)((u8 *)(temp_17) + (0xC18))) = 0;
            if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
                func_0045af60(0, 0, 0, 6);
                if (func_00106850(temp_19_7) == 5) {
                    temp_16_76 = (s64) (temp_19_7 << 0x30) >> 0x30;
                    func_00110810(temp_16_76, func_002b2cb0(func_00110830(temp_16_76) & 0xFF, (s64) (*(s16 *)((u8 *)(temp_17) + (0x12))), 0xFF, 0, 1) & 0xFF);
                    var_16_20 = 0;
loop_446:
                    temp_4_11 = (s64) (var_16_20 << 0x30) >> 0x30;
                    if (temp_4_11 < 0x2FF) {
                        if (!(func_00110830(temp_4_11) & 0xFF)) {
                            temp_21_3 = (s32) (func_00106b20(var_16_20) & 0xFFF00) >> 8;
                            if (func_002be160(temp_21_3, func_00106b20(var_16_20) & 0xFF) == 1) {
                                temp_21_4 = (s32) (func_00106b50(var_16_20) & 0xFFF00) >> 8;
                                if (func_002be160(temp_21_4, func_00106b50(var_16_20) & 0xFF) == 1) {
                                    (*(s16 *)((u8 *)((temp_17 + ((*(s16 *)((u8 *)(temp_17) + (0xC16))) * 2))) + (0x16))) = (s16) var_16_20;
                                    (*(s16 *)((u8 *)(temp_17) + (0xC16))) = (s16) ((*(s16 *)((u8 *)(temp_17) + (0xC16))) + 1);
                                }
                            }
                        }
                        var_16_20 = (s64) ((var_16_20 + 1) << 0x30) >> 0x30;
                        goto loop_446;
                    }
                }
                temp_16_77 = func_00106a90((s64) (temp_19_7 << 0x30) >> 0x30) / 5U;
                func_002e7a80(func_002e7a60() + ((*(s16 *)((u8 *)(temp_17) + (0x12))) * temp_16_77));
                func_00106620(temp_19_7, ((func_00106600(temp_19_7) & 0xFF) - (*(s16 *)((u8 *)(temp_17) + (0x12)))) & 0xFF);
                temp_3_19 = (s8)((*(s8 *)((u8 *)(temp_17) + (0x11))));
                switch (temp_3_19) {                /* switch 6; irregular */
                case 0:                             /* switch 6 */
                    func_002e3560((void *)((*(s32 *)((u8 *)(((temp_3_19 * 4) + temp_17)) + (0xF18)))), 0x40000, 0, 4, 0);
                    (*(s32 *)((u8 *)(temp_17) + (0xC20))) = 0;
                    var_19_5 = 1;
loop_453:
                    if (((s64) (var_19_5 << 0x30) >> 0x30) < func_002e26f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))))) {
                        temp_16_78 = (s64) (var_19_5 << 0x30) >> 0x30;
                        temp_21_5 = (s64) (func_002e2830((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_78) << 0x30) >> 0x30;
                        func_002e28f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_78);
                        temp_16_79 = (s64) (temp_21_5 << 0x30) >> 0x30;
                        temp_22_2 = func_00110830(temp_16_79) & 0xFF;
                        func_002b2cb0(temp_22_2, func_00106600(temp_21_5) & 0xFF, 0xFF, 0, 1);
                        temp_16_80 = func_00106a90((s64) (temp_16_79 << 0x30) >> 0x30) / 5U;
                        temp_4_12 = (s32)((*(s32 *)((u8 *)(temp_17) + (0xC20))) + (temp_16_80 * (func_00106600(temp_21_5) & 0xFF)));
                        (*(s32 *)((u8 *)(temp_17) + (0xC20))) = temp_4_12;
                        (*(s32 *)((u8 *)(temp_17) + (0xC20))) = func_002b2cb0((s8) temp_4_12, 0, 0x98967F, 0, 1);
                        var_19_5 = (s64) ((var_19_5 + 1) << 0x30) >> 0x30;
                        goto loop_453;
                    }
                    break;
                case 1:                             /* switch 6 */
                    func_002e3560((void *)((*(s32 *)((u8 *)(((temp_3_19 * 4) + temp_17)) + (0xF18)))), 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:                             /* switch 6 */
                    func_002e3560((void *)((*(s32 *)((u8 *)(((temp_3_19 * 4) + temp_17)) + (0xF18)))), 0x10000, 0, 1, 0);
                    break;
                }
                if (temp_18_54 != func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))))) {
                    temp_4_13 = (s64) ((s64) temp_23_2 << 0x30) >> 0x30;
                    if ((temp_4_13 - ((s64) ((s64) temp_30 << 0x30) >> 0x30)) > 0) {
                        temp_16_81 = (s64) (func_002b2d00((s8) temp_4_13, 1, 0, 0, 1) << 0x30) >> 0x30;
                        (*(s16 *)((u8 *)(temp_17) + (2))) = 0;                        func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                        (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), (s64) (temp_16_81 << 0x30) >> 0x30,0, 0, 1);
                    } else {                        func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                        (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 0,0, 0, 1);
                    }                    func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (4))), 0,0, 0, 1);
                }
                func_002d4760(arg0, (*(s8 *)((u8 *)(temp_17) + (0x11))));
            }
            func_002df4c0(arg0);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), 0xFFU, 0, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), 0xFFU, 0, 0, 5, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8)))), 0, 1);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), 0U, 0xFF, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0U, 0xFF, 0, 5, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
            if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                if (D_00748908[(*(s8 *)((u8 *)(temp_17) + (0x11)))] >= func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))))) {
                    func_002d8600(arg0);
                } else {
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x31;
                }
            }
            if ((*(s16 *)((u8 *)(temp_17) + (0xC16))) > 0) {
                (*(s8 *)((u8 *)(temp_17) + (0xC1A))) = 0;
                func_002dfe00(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x29;
            }
        }
        goto block_626;
    case 0x2E:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            (*(s16 *)((u8 *)(temp_17) + (0xC16))) = 0;
            (*(s16 *)((u8 *)(temp_17) + (0xC18))) = 0;
            if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
                func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
                func_0045af60(0, 0, 0, 6);
                var_18_6 = 1;
loop_474:
                if (((s64) (var_18_6 << 0x30) >> 0x30) < func_002e26f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))))) {
                    temp_16_82 = (s64) (var_18_6 << 0x30) >> 0x30;
                    temp_19_8 = (s64)(s32)(func_002e2830((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_82));
                    func_002e28f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_82);
                    temp_16_83 = func_00110830(temp_19_8) & 0xFF;
                    func_00110810(temp_19_8, func_002b2cb0(temp_16_83, func_00106600((s64) (temp_19_8 << 0x30) >> 0x30) & 0xFF, 0xFF, 0, 1) & 0xFF);
                    temp_16_84 = func_00106a90((s64) (temp_19_8 << 0x30) >> 0x30) / 5U;
                    temp_16_85 = temp_16_84 * (func_00106600((s64) (temp_19_8 << 0x30) >> 0x30) & 0xFF);
                    func_002e7a80(func_002e7a60() + temp_16_85);
                    func_00106620((s64) (temp_19_8 << 0x30) >> 0x30, 0);
                    var_18_6 = (s64) ((var_18_6 + 1) << 0x30) >> 0x30;
                    goto loop_474;
                }
                (*(s32 *)((u8 *)(temp_17) + (0xC20))) = 0;
                var_16_21 = 0;
loop_481:
                temp_4_14 = (s64) (var_16_21 << 0x30) >> 0x30;
                if (temp_4_14 < 0x2FF) {
                    if (!(func_00110830(temp_4_14) & 0xFF)) {
                        temp_18_55 = (s32) (func_00106b20(var_16_21) & 0xFFF00) >> 8;
                        if (func_002be160(temp_18_55, func_00106b20(var_16_21) & 0xFF) == 1) {
                            temp_18_56 = (s32) (func_00106b50(var_16_21) & 0xFFF00) >> 8;
                            if (func_002be160(temp_18_56, func_00106b50(var_16_21) & 0xFF) == 1) {
                                (*(s16 *)((u8 *)((temp_17 + ((*(s16 *)((u8 *)(temp_17) + (0xC16))) * 2))) + (0x16))) = (s16) var_16_21;
                                (*(s16 *)((u8 *)(temp_17) + (0xC16))) = (s16) ((*(s16 *)((u8 *)(temp_17) + (0xC16))) + 1);
                            }
                        }
                    }
                    var_16_21 = (s64) ((var_16_21 + 1) << 0x30) >> 0x30;
                    goto loop_481;
                }
                func_002e3560((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), 0x40000, 0, 4, 0);
                (*(s32 *)((u8 *)(temp_17) + (0xC20))) = 0;                func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 0,0, 0, 1);
                temp_18_57 = (s16)((*(s16 *)((u8 *)(temp_17) + (4))));
                temp_16_86 = (s64)(s32)(func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))));                func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                if (func_002b32a0((*(s16 *)((u8 *)(temp_17) + (4))), 5, temp_16_86,0) < temp_18_57) {
                    temp_16_87 = (s64) (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) << 0x30) >> 0x30;                    func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b32a0((*(s16 *)((u8 *)(temp_17) + (4))), 5, temp_16_87,0);
                }
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE40)))), 0, 1);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE44)))), 0, 1);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE48)))), 0, 1);
                func_002d4760(arg0, (*(s8 *)((u8 *)(temp_17) + (0x11))));
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
                if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                    func_002d8600(arg0);
                }
                if ((*(s16 *)((u8 *)(temp_17) + (0xC16))) > 0) {
                    (*(s8 *)((u8 *)(temp_17) + (0xC1A))) = 0;
                    func_002dfe00(arg0);
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x29;
                }
            } else {
                func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
                if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                    func_002d8600(arg0);
                }
            }
        }
        goto block_626;
    case 0x29:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            func_0045aeb0(2, (const char *)&D_0063FAF0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2A;
        }
        goto block_626;
    case 0x2A:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        temp_2_97 = (s8)(func_002b2cb0((*(s8 *)((u8 *)(temp_17) + (0xC1A))), 1, 0x3C, 0, 1));
        (*(s8 *)((u8 *)(temp_17) + (0xC1A))) = temp_2_97;
        if (((s64) ((s64) temp_2_97 << 0x38) >> 0x38) >= 0x3C) {
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 0xA, NULL, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2B;
            (*(s8 *)((u8 *)(temp_17) + (0xC1A))) = 0;
        }
        goto block_626;
    case 0x2B:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            sp670 = (s32) (*(s16 *)((u8 *)((((*(s16 *)((u8 *)(temp_17) + (0xC18))) * 2) + temp_17)) + (0x16)));
            sp674 = 0;
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 3, &sp670, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2D;
        }
        goto block_626;
    case 0x2C:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        sp668 = (s32) (*(s16 *)((u8 *)((((*(s16 *)((u8 *)(temp_17) + (0xC18))) * 2) + temp_17)) + (0x16)));
        sp66C = 0;
        (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 3, &sp668, 0);
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2D;
        goto block_626;
    case 0x2D:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_00110810((s64) (*(s16 *)((u8 *)((((*(s16 *)((u8 *)(temp_17) + (0xC18))) * 2) + temp_17)) + (0x16))), ((func_00110830((s64) (*(s16 *)((u8 *)((((*(s16 *)((u8 *)(temp_17) + (0xC18))) * 2) + temp_17)) + (0x16)))) & 0xFF) | 1) & 0xFF);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            temp_2_98 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xC18))) + 1);
            (*(s16 *)((u8 *)(temp_17) + (0xC18))) = temp_2_98;
            if (((s64) ((s64) temp_2_98 << 0x30) >> 0x30) >= (*(s16 *)((u8 *)(temp_17) + (0xC16)))) {
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
                if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x31;
                }
            } else {
                func_002dfe00(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x29;
            }
        }
        goto block_626;
    case 0x26:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        var_20_2 = 0;
loop_525:
        if (((s64) (var_20_2 << 0x30) >> 0x30) < 2) {
            temp_19_9 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_18_58 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_16_88 = (u8 *)(temp_17 + (((s64) (var_20_2 << 0x30) >> 0x30) * 4));
            temp_2_99 = (u8)((*(u8 *)((u8 *)(temp_16_88) + (0xF3E))));
            if ((s32) temp_2_99 >= 0) {
                var_f12_13 = (f32) temp_2_99;
            } else {
                var_f12_13 = 2.0f * (f32) ((temp_2_99 >> 1) | (temp_2_99 & 1));
            }
            temp_f0_15 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_13)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_15 >= 2.1474836e9f)) {
                var_3_15 = ((s32)(temp_f0_15)) & 0xFF;
            } else {
                var_3_15 = (((s32)((temp_f0_15 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_58) + (0x79))) = var_3_15;
            (*(s8 *)((u8 *)(temp_19_9) + (0x79))) = var_3_15;
            temp_2_100 = (u8)((*(u8 *)((u8 *)(temp_16_88) + (0xF3F))));
            if ((s32) temp_2_100 >= 0) {
                var_f12_14 = (f32) temp_2_100;
            } else {
                var_f12_14 = 2.0f * (f32) ((temp_2_100 >> 1) | (temp_2_100 & 1));
            }
            temp_f0_16 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_14)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_16 >= 2.1474836e9f)) {
                var_3_16 = ((s32)(temp_f0_16)) & 0xFF;
            } else {
                var_3_16 = (((s32)((temp_f0_16 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_58) + (0x7A))) = var_3_16;
            (*(s8 *)((u8 *)(temp_19_9) + (0x7A))) = var_3_16;
            temp_2_101 = (u8)((*(u8 *)((u8 *)(temp_16_88) + (0xF40))));
            if ((s32) temp_2_101 >= 0) {
                var_f12_15 = (f32) temp_2_101;
            } else {
                var_f12_15 = 2.0f * (f32) ((temp_2_101 >> 1) | (temp_2_101 & 1));
            }
            temp_f0_17 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_15)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_17 >= 2.1474836e9f)) {
                var_3_17 = ((s32)(temp_f0_17)) & 0xFF;
            } else {
                var_3_17 = (((s32)((temp_f0_17 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_58) + (0x7B))) = var_3_17;
            (*(s8 *)((u8 *)(temp_19_9) + (0x7B))) = var_3_17;
            var_20_2 = (s64) ((var_20_2 + 1) << 0x30) >> 0x30;
            goto loop_525;
        }
        temp_4_15 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_15 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_15, 1, 6, 0, 1);
        } else {
            temp_2_102 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_6_5 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3E))));
            temp_5_6 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3F))));
            (*(u8 *)((u8 *)(temp_2_102) + (0x79))) = temp_6_5;
            (*(u8 *)((u8 *)(temp_2_102) + (0x7A))) = temp_5_6;
            (*(u8 *)((u8 *)(temp_2_102) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF40)));
            (*(u8 *)((u8 *)(temp_2_102) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF41)));
            temp_2_103 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_6_6 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF42))));
            temp_5_7 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF43))));
            (*(u8 *)((u8 *)(temp_2_103) + (0x79))) = temp_6_6;
            (*(u8 *)((u8 *)(temp_2_103) + (0x7A))) = temp_5_7;
            (*(u8 *)((u8 *)(temp_2_103) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF44)));
            (*(u8 *)((u8 *)(temp_2_103) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF45)));
            temp_2_104 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_f1_2 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_104) + (0x2C))));
            sp660 = temp_f1_2;
            sp664 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_104) + (0x30))));
            func_002b2970(&sp248, ((u8)((temp_f1_2 - 1000.0f))), (u8) sp664);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), ((s64)(sp660)), sp248, 1, 3, 0);
            temp_2_105 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_f1_3 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_105) + (0x2C))));
            sp160 = temp_f1_3;
            sp164 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_105) + (0x30))));
            func_002b2970(&sp240, ((u8)((temp_f1_3 - 1000.0f))), (u8) sp164);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), ((s64)(sp160)), sp240, 1, 3, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2F;
        }
        goto block_626;
    case 0x2F:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        var_20_3 = 0;
loop_549:
        if (((s64) (var_20_3 << 0x30) >> 0x30) < 2) {
            temp_19_10 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_18_59 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_16_89 = (u8 *)(temp_17 + (((s64) (var_20_3 << 0x30) >> 0x30) * 4));
            temp_2_106 = (u8)((*(u8 *)((u8 *)(temp_16_89) + (0xF3E))));
            if ((s32) temp_2_106 >= 0) {
                var_f12_16 = (f32) temp_2_106;
            } else {
                var_f12_16 = 2.0f * (f32) ((temp_2_106 >> 1) | (temp_2_106 & 1));
            }
            temp_f0_18 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_16)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_18 >= 2.1474836e9f)) {
                var_3_18 = ((s32)(temp_f0_18)) & 0xFF;
            } else {
                var_3_18 = (((s32)((temp_f0_18 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_59) + (0x79))) = var_3_18;
            (*(s8 *)((u8 *)(temp_19_10) + (0x79))) = var_3_18;
            temp_2_107 = (u8)((*(u8 *)((u8 *)(temp_16_89) + (0xF3F))));
            if ((s32) temp_2_107 >= 0) {
                var_f12_17 = (f32) temp_2_107;
            } else {
                var_f12_17 = 2.0f * (f32) ((temp_2_107 >> 1) | (temp_2_107 & 1));
            }
            temp_f0_19 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_17)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_19 >= 2.1474836e9f)) {
                var_3_19 = ((s32)(temp_f0_19)) & 0xFF;
            } else {
                var_3_19 = (((s32)((temp_f0_19 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_59) + (0x7A))) = var_3_19;
            (*(s8 *)((u8 *)(temp_19_10) + (0x7A))) = var_3_19;
            temp_2_108 = (u8)((*(u8 *)((u8 *)(temp_16_89) + (0xF40))));
            if ((s32) temp_2_108 >= 0) {
                var_f12_18 = (f32) temp_2_108;
            } else {
                var_f12_18 = 2.0f * (f32) ((temp_2_108 >> 1) | (temp_2_108 & 1));
            }
            temp_f0_20 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_18)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_20 >= 2.1474836e9f)) {
                var_3_20 = ((s32)(temp_f0_20)) & 0xFF;
            } else {
                var_3_20 = (((s32)((temp_f0_20 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_59) + (0x7B))) = var_3_20;
            (*(s8 *)((u8 *)(temp_19_10) + (0x7B))) = var_3_20;
            var_20_3 = (s64) ((var_20_3 + 1) << 0x30) >> 0x30;
            goto loop_549;
        }
        temp_4_16 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_16 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_16, 1, 6, 0, 1);
        } else {
            temp_2_109 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_6_7 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3E))));
            temp_5_8 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3F))));
            (*(u8 *)((u8 *)(temp_2_109) + (0x79))) = temp_6_7;
            (*(u8 *)((u8 *)(temp_2_109) + (0x7A))) = temp_5_8;
            (*(u8 *)((u8 *)(temp_2_109) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF40)));
            (*(u8 *)((u8 *)(temp_2_109) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF41)));
            temp_2_110 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_6_8 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF42))));
            temp_5_9 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF43))));
            (*(u8 *)((u8 *)(temp_2_110) + (0x79))) = temp_6_8;
            (*(u8 *)((u8 *)(temp_2_110) + (0x7A))) = temp_5_9;
            (*(u8 *)((u8 *)(temp_2_110) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF44)));
            (*(u8 *)((u8 *)(temp_2_110) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF45)));
            temp_2_111 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_f1_4 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_111) + (0x2C))));
            sp658 = temp_f1_4;
            sp65C = (f32)(s32)((*(f32 *)((u8 *)(temp_2_111) + (0x30))));
            func_002b2970(&sp238, ((u8)((temp_f1_4 - 1000.0f))), (u8) sp65C);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), ((s64)(sp658)), sp238, 1, 3, 0);
            temp_2_112 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_f1_5 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_112) + (0x2C))));
            sp158 = temp_f1_5;
            sp15C = (f32)(s32)((*(f32 *)((u8 *)(temp_2_112) + (0x30))));
            func_002b2970(&sp230, ((u8)((temp_f1_5 - 1000.0f))), (u8) sp15C);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), ((s64)(sp158)), sp230, 1, 3, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE50)))), 0x41, 109.0f);
            func_002b2970(&sp228, ((u8)((f32) -0x271)), 0x42F80000U);
            func_002b2970(&sp220, 0x42960000U, 0x42F80000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE50)))), sp228, sp220, 0, 4, 5);
            func_002b2a60(&sp6C8, 0xFF, 0xCB, 0x35, 0xFFU);
            temp_2_113 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE50))))));
            (*(u8 *)((u8 *)(temp_2_113) + (0x79))) = sp6C8;
            (*(u8 *)((u8 *)(temp_2_113) + (0x7A))) = sp6C9;
            (*(u8 *)((u8 *)(temp_2_113) + (0x7B))) = sp6CA;
            (*(u8 *)((u8 *)(temp_2_113) + (0x7C))) = sp6CB;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE54)))), 0x41, ((f32)(sp6C8)));
            func_002b2970(&sp218, ((u8)((f32) -0x271)), ((u8)((f32) 0x11D)));
            func_002b2970(&sp210, 0x42960000U, ((u8)((f32) 0x11D)));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE54)))), sp218, sp210, 0, 4, 5);
            func_002b2a60(&sp6C4, 0xFF, 0xCB, 0x35, 0xFFU);
            temp_2_114 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE54))))));
            (*(u8 *)((u8 *)(temp_2_114) + (0x79))) = sp6C4;
            (*(u8 *)((u8 *)(temp_2_114) + (0x7A))) = sp6C5;
            (*(u8 *)((u8 *)(temp_2_114) + (0x7B))) = sp6C6;
            (*(u8 *)((u8 *)(temp_2_114) + (0x7C))) = sp6C7;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE58)))), 0x41, ((f32)(sp6C4)));
            func_002b2970(&sp208, 0xC2EA0000U, 0x43000000U);
            func_002b2970(&sp200, ((u8)((f32) 0x247)), 0x43000000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE58)))), sp208, sp200, 0, 4, 5);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE5C)))), 0x41, 114.0f);
            func_002b2970(&sp1F8, ((u8)((f32) -0x2FD)), 0x43000000U);
            func_002b2970(&sp1F0, 0xC2820000U, 0x43000000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE5C)))), sp1F8, sp1F0, 0, 4, 5);
            (*(s8 *)((u8 *)(temp_17) + (0xC24))) = 1;
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x30;
        }
        goto block_626;
    case 0x30:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), 9) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 9) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE50))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE54))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE58))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE5C))))) << 0x38) >> 0x38) == 0)) {
            var_16_22 = 0;
loop_561:
            if (((s64) (var_16_22 << 0x30) >> 0x30) < 3) {
                temp_3_20 = (u8 *)(temp_17 + (((s64) (var_16_22 << 0x30) >> 0x30) * 4));
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_3_20) + (0xDBC)))), 0x41, 95.0f);
                func_002b2a60(&sp6C0, 0xFF, 0xEF, 0x80, 0xFFU);
                temp_2_115 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_3_20) + (0xDBC))))));
                (*(u8 *)((u8 *)(temp_2_115) + (0x79))) = sp6C0;
                (*(u8 *)((u8 *)(temp_2_115) + (0x7A))) = sp6C1;
                (*(u8 *)((u8 *)(temp_2_115) + (0x7B))) = sp6C2;
                (*(u8 *)((u8 *)(temp_2_115) + (0x7C))) = sp6C3;
                var_16_22 = (s64) ((var_16_22 + 1) << 0x30) >> 0x30;
                goto loop_561;
            }
            func_002b2970(&sp1E8, 0x42B20000U, 0x43230000U);
            temp_2_116 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDBC))))));
            (*(f32 *)((u8 *)(temp_2_116) + (0x2C))) = (f32) sp1E8;
            (*(f32 *)((u8 *)(temp_2_116) + (0x30))) = unksp1EC;
            func_002b2970(&sp1E0, ((u8)((f32) 0x1D1)), 0x43230000U);
            temp_2_117 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC0))))));
            (*(f32 *)((u8 *)(temp_2_117) + (0x2C))) = (f32) sp1E0;
            (*(f32 *)((u8 *)(temp_2_117) + (0x30))) = unksp1E4;
            func_002b2970(&sp1D8, ((u8)((f32) 0x22E)), 0x43230000U);
            temp_2_118 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC4))))));
            (*(f32 *)((u8 *)(temp_2_118) + (0x2C))) = (f32) sp1D8;
            (*(f32 *)((u8 *)(temp_2_118) + (0x30))) = unksp1DC;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCAC)))), 0x56, 91.0f);
            func_002b2970(&sp1D0, ((u8)((f32) 0x1DF)), 0x43270000U);
            temp_2_119 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCAC))))));
            (*(f32 *)((u8 *)(temp_2_119) + (0x2C))) = (f32) sp1D0;
            (*(f32 *)((u8 *)(temp_2_119) + (0x30))) = unksp1D4;
            func_002b2a60(&sp6BC, 0xFE, 0xC7, 0x31, 0xFFU);
            temp_2_120 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCAC))))));
            (*(u8 *)((u8 *)(temp_2_120) + (0x79))) = sp6BC;
            (*(u8 *)((u8 *)(temp_2_120) + (0x7A))) = sp6BD;
            (*(u8 *)((u8 *)(temp_2_120) + (0x7B))) = sp6BE;
            (*(u8 *)((u8 *)(temp_2_120) + (0x7C))) = sp6BF;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE84)))), 0x56, ((f32)(sp6BC)));
            func_002b2a60(&sp6B8, 0xFE, 0xC7, 0x31, 0xFFU);
            temp_2_121 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE84))))));
            (*(u8 *)((u8 *)(temp_2_121) + (0x79))) = sp6B8;
            (*(u8 *)((u8 *)(temp_2_121) + (0x7A))) = sp6B9;
            (*(u8 *)((u8 *)(temp_2_121) + (0x7B))) = sp6BA;
            (*(u8 *)((u8 *)(temp_2_121) + (0x7C))) = sp6BB;
            func_002b2970(&sp1C8, (f32) 0x1DF, 217.0f);
            temp_2_122 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE84))))));
            (*(f32 *)((u8 *)(temp_2_122) + (0x2C))) = (f32) sp1C8;
            (*(f32 *)((u8 *)(temp_2_122) + (0x30))) = unksp1CC;
            if (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) >= 2) {
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC94)))), 0x41, 88.0f);
                func_002b2a60(&sp6B4, 0xFF, 0x96, 0, 0xFFU);
                temp_2_123 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC94))))));
                (*(u8 *)((u8 *)(temp_2_123) + (0x79))) = sp6B4;
                (*(u8 *)((u8 *)(temp_2_123) + (0x7A))) = sp6B5;
                (*(u8 *)((u8 *)(temp_2_123) + (0x7B))) = sp6B6;
                (*(u8 *)((u8 *)(temp_2_123) + (0x7C))) = sp6B7;
                func_002b2970(&sp1C0, (f32) 0x247, 136.0f);
                temp_2_124 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC94))))));
                (*(f32 *)((u8 *)(temp_2_124) + (0x2C))) = (f32) sp1C0;
                (*(f32 *)((u8 *)(temp_2_124) + (0x30))) = unksp1C4;
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC98)))), 0x41, 89.0f);
                func_002b2a60(&sp6B0, 0xFF, 0x96, 0, 0xFFU);
                temp_2_125 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC98))))));
                (*(u8 *)((u8 *)(temp_2_125) + (0x79))) = sp6B0;
                (*(u8 *)((u8 *)(temp_2_125) + (0x7A))) = sp6B1;
                (*(u8 *)((u8 *)(temp_2_125) + (0x7B))) = sp6B2;
                (*(u8 *)((u8 *)(temp_2_125) + (0x7C))) = sp6B3;
                func_002b2970(&sp1B8, (f32) 0x247, 272.0f);
                temp_2_126 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC98))))));
                (*(f32 *)((u8 *)(temp_2_126) + (0x2C))) = (f32) sp1B8;
                (*(f32 *)((u8 *)(temp_2_126) + (0x30))) = unksp1BC;
            }
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x31;
        }
        goto block_626;
    case 0x31:                                      /* switch 1 */
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCA0)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCA8)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC9C)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCA4)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCB8)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xEAC)))), 0, 1);
        func_002cdf80(arg0, 1);
        func_002dd3b0(arg0);
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xE38)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC4)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC0)))), 1) << 0x38) >> 0x38) == 0) && ((D_008C0276 & 0x80) || (D_008C0276 & 0x20))) {
            func_0045af60(0, 1, 0, 4);
            func_002d8600(arg0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))), 0, 1);
            temp_2_127 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            sp650 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_127) + (0x2C))));
            sp654 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_127) + (0x30))));
            func_002b2970(&sp1B0, (700.0f + D_0063F888[0]), (u8) sp654);
            func_002b2970(&sp1A8, ((u8)(D_0063F888)), (u8) sp654);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), sp1B0, sp1A8, 1, 3, 2);
            temp_2_128 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            sp150 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_128) + (0x2C))));
            sp154 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_128) + (0x30))));
            func_002b2970(&sp1A0, (700.0f + D_0063F890[0]), (u8) sp154);
            func_002b2970(&sp198, ((u8)(D_0063F890)), (u8) sp154);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), sp1A0, sp198, 1, 3, 2);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
        }
        goto block_626;
    case 0x32:                                      /* switch 1 */
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
        goto block_626;
    case 0x33:                                      /* switch 1 */
        if (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) >= 6) {
            temp_16_90 = (s8)((*(s8 *)((u8 *)(temp_17) + (0x11))));
            if (D_00748908[temp_16_90] < func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_16_90 * 4) + temp_17)) + (0xF18)))))) {
                if (func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_16_90 * 4) + temp_17)) + (0xF18))))) >= 6) {
                    (*(f32 *)((u8 *)(temp_17) + (0xC))) = (f32) (104.0f / (f32) (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) - 5));
                }
                0;
                func_002b2970(&sp190, ((u8)((f32) 0x221)), 0);
                temp_16_91 = func_002b2a30(0xFF, 0xFEU, 0xC6U, 0x31U);
                func_002e0b20(0x36,(*(Vec2f *)&sp190), temp_16_91, (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))))) + (0x62))), 0, 0, D_00794EA0);
            }
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 0);
        } else {
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 1);
        }
        func_002d8a60(arg0, (*(s8 *)((u8 *)(temp_17) + (0x116E))), 80.0f, (f32) 0x352);
        func_002d8a60(arg0, (*(s8 *)((u8 *)(temp_17) + (0x11))), (f32) -0x352, 80.0f);
        temp_2_129 = (s16)(func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (0x1170))), 1, 0, 0, 1));
        (*(s16 *)((u8 *)(temp_17) + (0x1170))) = temp_2_129;
        if (((s64) ((s64) temp_2_129 << 0x30) >> 0x30) == 0) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
        }
        goto block_626;
    case 0x34:                                      /* switch 1 */
        if (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) >= 6) {
            temp_16_92 = (s8)((*(s8 *)((u8 *)(temp_17) + (0x11))));
            if (D_00748908[temp_16_92] < func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_16_92 * 4) + temp_17)) + (0xF18)))))) {
                if (func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_16_92 * 4) + temp_17)) + (0xF18))))) >= 6) {
                    (*(f32 *)((u8 *)(temp_17) + (0xC))) = (f32) (104.0f / (f32) (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) - 5));
                }
                0;
                func_002b2970(&sp188, ((u8)((f32) 0x221)), 0);
                temp_16_93 = func_002b2a30(0xFF, 0xFEU, 0xC6U, 0x31U);
                func_002e0b20(0x36,(*(Vec2f *)&sp188), temp_16_93, (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))))) + (0x62))), 0, 0, D_00794EA0);
            }
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 0);
        } else {
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 1);
        }
        func_002d8a60(arg0, (*(s8 *)((u8 *)(temp_17) + (0x116E))), 80.0f, (f32) -0x352);
        func_002d8a60(arg0, (*(s8 *)((u8 *)(temp_17) + (0x11))), (f32) 0x352, 80.0f);
        temp_2_130 = (s16)(func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (0x1170))), 1, 0, 0, 1));
        (*(s16 *)((u8 *)(temp_17) + (0x1170))) = temp_2_130;
        if (((s64) ((s64) temp_2_130 << 0x30) >> 0x30) == 0) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
        }
        goto block_626;
    case 0x35:                                      /* switch 1 */
        if (func_00452380(&D_0063FB10) == 0) {
            var_16_23 = 0;
loop_593:
            temp_3_21 = (s64) (var_16_23 << 0x30) >> 0x30;
            if (temp_3_21 < 7) {
                func_002e04f0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_21 * 4))) + (0xD20)))), 0, 0);
                var_16_23 = (s64) ((var_16_23 + 1) << 0x30) >> 0x30;
                goto loop_593;
            }
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0, 0);
            var_16_24 = 0;
loop_596:
            temp_3_22 = (s64) (var_16_24 << 0x30) >> 0x30;
            if (temp_3_22 < 3) {
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_22 * 4))) + (0xC38)))), 0U, 0xFF, 0, 0xA, 0);
                var_16_24 = (s64) ((var_16_24 + 1) << 0x30) >> 0x30;
                goto loop_596;
            }
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0U, 0xFF, 0, 0xA, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0U, 0xFF, 0, 0xA, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0U, 0xFF, 0, 0xA, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
            temp_2_131 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
            temp_18_60 = (s64) (((s64)(func_0046b260((void *)(temp_2_131)))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_60;
            temp_18_61 = (s64) (((s64)(func_0046b2f0((void *)(temp_2_131)))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_61;
            func_0046d280((void *)(temp_2_131));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0U, 0xCC, 0, 4, 4);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 4, 4, 0.0f, fGpffff8520);
            func_002b2970(&sp180, 0xC3700000U, 0x43C80000U);
            func_002b2970(&sp178, 0xC3700000U, 0x439B0000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), sp180, sp178, 0, 4, 4);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 110.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = -50.0f;
            temp_2_132 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_62 = (s64) (((s64)(func_0046b260((void *)(temp_2_132)))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_18_62;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = 0;
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 4, 4, -90.0f, fGpffff8524);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0U, 0xFF, 0, 4, 4);
            func_0046d280((void *)(temp_2_132));
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 180.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 30.0f;
            temp_2_133 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_16_94 = (s64) (((s64)(func_0046b260((void *)(temp_2_133)))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_16_94;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = 0;
            func_0046d280((void *)(temp_2_133));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 4, 2, -85.0f, fGpffff8528);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0U, 0xFF, 0, 4, 2);
            var_21_4 = 0;
loop_601:
            if (((s64) (var_21_4 << 0x30) >> 0x30) < 7) {
                temp_19_11 = (s64) (var_21_4 << 0x30) >> 0x30;
                temp_18_63 = (u8 *)((s32)&D_0063F560 + ((temp_19_11 + 0x3A) * 8));
                temp_3_23 = (u8 *)(temp_17 + (temp_19_11 * 4));
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_3_23) + (0xD20)))), 0x56, (f32) (temp_19_11 + 0x64));
                if (temp_19_11 > 0) {
                    func_002b2a60(&sp6AC, 0xED, 0x80, 0, 0xFFU);
                    temp_2_134 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_3_23) + (0xD20))))));
                    (*(u8 *)((u8 *)(temp_2_134) + (0x79))) = sp6AC;
                    (*(u8 *)((u8 *)(temp_2_134) + (0x7A))) = sp6AD;
                    (*(u8 *)((u8 *)(temp_2_134) + (0x7B))) = sp6AE;
                    (*(u8 *)((u8 *)(temp_2_134) + (0x7C))) = sp6AF;
                }
                temp_2_135 = (u8 *)(temp_17 + (((s64) (var_21_4 << 0x30) >> 0x30) * 4));
                func_002b2970(&sp170, ((u8)((80.0f + (*(f32 *)((u8 *)(temp_18_63) + (0)))))), (u8) (*(f32 *)((u8 *)(temp_18_63) + (4))));
                func_002b2970(&sp168, ((u8)((*(f32 *)((u8 *)(temp_18_63) + (0))))), (u8) (*(f32 *)((u8 *)(temp_18_63) + (4))));
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_2_135) + (0xD20)))), sp170, sp168, 0, 3, var_21_4);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_2_135) + (0xD20)))), 0U, 0xFF, 0, 3, var_21_4);
                var_21_4 = (s64) ((var_21_4 + 1) << 0x30) >> 0x30;
                goto loop_601;
            }
            func_002b2a60(&sp6A8, 0x2D, 0x2D, 0x2D, 0xFFU);
            temp_2_136 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
            (*(u8 *)((u8 *)(temp_2_136) + (0x79))) = sp6A8;
            (*(u8 *)((u8 *)(temp_2_136) + (0x7A))) = sp6A9;
            (*(u8 *)((u8 *)(temp_2_136) + (0x7B))) = sp6AA;
            (*(u8 *)((u8 *)(temp_2_136) + (0x7C))) = sp6AB;
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0U, 0xFF, 0, 0, (s64) (*(s8 *)((u8 *)(temp_17) + (7))));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0U, 0xFF, 0, 0, (s64) (*(s8 *)((u8 *)(temp_17) + (7))));
            func_002d7f90(arg0);
            func_002dd230(arg0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x36;
        }
        goto block_626;
    case 0x36:                                      /* switch 1 */
        var_16_25 = 0x55;
loop_607:
        temp_3_24 = (s64) (var_16_25 << 0x30) >> 0x30;
        if (temp_3_24 < 0x58) {
            temp_2_137 = (u8 *)(temp_17 + (temp_3_24 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_137) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_137) + (0xC38)))), 3, 0);
            }
            var_16_25 = (s64) ((var_16_25 + 1) << 0x30) >> 0x30;
            goto loop_607;
        }
        var_16_26 = 0x59;
loop_612:
        temp_3_25 = (s64) (var_16_26 << 0x30) >> 0x30;
        if (temp_3_25 < 0x60) {
            temp_2_138 = (u8 *)(temp_17 + (temp_3_25 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_138) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_138) + (0xC38)))), 3, 0);
            }
            var_16_26 = (s64) ((var_16_26 + 1) << 0x30) >> 0x30;
            goto loop_612;
        }
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 2) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 2) << 0x38) >> 0x38) == 0)) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x10;
        }
        goto block_626;
    case 0x37:                                      /* switch 1 */
        if ((((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC38))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC3C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40))))) << 0x38) >> 0x38) == 0)) {
            return -1;
        }
        goto block_626;
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002be530);
#endif

// FUN_002CA770
void func_002ca770(void *arg0) {
    s16 i;
    void *work = *(void **)((u8 *)arg0 + 0x38);

    for (i = 0; i < *(s8 *)((u8 *)work + 9); i++) {
        func_00105780(*(s8 *)((u8 *)work + i + 0xF73));
    }
    if (*(void **)((u8 *)work + 0xF28)) {
        func_0046b0d0(*(void **)((u8 *)work + 0xF28));
        *(u32 *)((s32)work + 0xF28) = 0;
    }
    if (*(void **)((u8 *)work + 0xF2C)) {
        func_00454bd0(*(void **)((u8 *)work + 0xF2C));
    }
    func_002e29a0();
    jtbl_008873EC[0](*(void **)((s32)arg0 + 0x38));
}

// FUN_002CA830
s32 func_002ca830(s32 arg0) {
    u64 sp48;
    u64 sp40;
    u64 sp38;
    u64 sp30;
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(&D_0063FAC0, 0xC47);
    temp_2 = D_008873F4[0](1, 0x1174, 0x40000);
    temp_17 = func_00451fc0(arg0, (char *)&D_0063FB30, 0xF, 0, 0, (void (*)(u8 *))func_002be530, (void (*)(u8 *))func_002ca770, temp_2);
    *(s8 *)(temp_2 + 0) = 9;
    func_002b2970(&sp48, 240.0f, 20.0f);
    *(void **)(temp_2 + 0xC28) = func_002b5c90((void *)temp_17, sp48);
    *(s8 *)(temp_2 + 0xC24) = 0;
    func_002b2970(&sp40, 50.0f, 30.0f);
    *(void **)(temp_2 + 0xC2C) = func_002b5c90((void *)temp_17, sp40);
    func_002b2970(&sp38, 50.0f, 30.0f);
    *(void **)(temp_2 + 0xC30) = func_002b5c90((void *)temp_17, sp38);
    func_002b2970(&sp30, 50.0f, 30.0f);
    *(void **)(temp_2 + 0xC34) = func_002b5c90((void *)temp_17, sp30);
    *(u32 *)(temp_2 + 0xF28) = 0;
    *(s8 *)(temp_2 + 0xF30) = 0;
    *(void **)(temp_2 + 0xF18) = func_002e2590((void *)temp_17, 0x40000, 0, 4, 0);
    *(void **)(temp_2 + 0xF1C) = func_002e2590((void *)temp_17, 0xFFFF, 0x1FE0, 1, 0);
    *(void **)(temp_2 + 0xF20) = func_002e2590((void *)temp_17, 0x10000, 0, 1, 0);
    return temp_17;
}

// FUN_002CAA00
void func_002caa00(void *arg0, s8 arg1) {
    *(s8 *)(*(u32 *)((u8 *)arg0 + 0x38)) = arg1;
}

/* Measured: 696/704 bytes, fourteen resolved relocations, eight zero
   alignment bytes. Separate glyph acquisition/release scopes preserve
   the saved-register allocation and callback order. */
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
// FUN_002CAA10
void func_002caa10(Vec2f position, f32 depth, RGBA color, u32 number_, s16 glyphBase, void *sprite_, s32 style)
{
    char text[16];
    f32 x;
    u32 number;
    s32 digitWidth;
    void *sprite;
    s32 count;
    s16 commaWidth;
    u8 *entry;
    s32 base;
    u8 a;
    u8 b;
    u8 g;
    f32 y;
    s32 comma;

    sprite = sprite_;
    number = number_;
    count = 0;
    x = position.x;
    {
        void *glyph;
        s32 measuredBase;
        measuredBase = (s16)glyphBase;
        glyph = func_0046d200(sprite, measuredBase);
        digitWidth = (s16)(s32)(func_0046b260(glyph) - 1.0f);
        func_0046d280(glyph);
        comma = measuredBase + 10;
    }
    {
        void *commaGlyph;
        commaGlyph = func_0046d200(sprite, comma);
        commaWidth = (s16)(s32)(func_0046b260(commaGlyph) - 1.0f);
        func_0046d280(commaGlyph);
    }
    func_00442830(text, iGpffffa884);
    entry = D_00793E80 + style * 0x30;
    base = (s16)glyphBase;
    a = color.a;
    b = color.b;
    g = color.g;
    y = position.y;
    do {
        func_0025ec90(x, y, depth, func_002b2a30(0xFF, color.r, g, b), a, base + number % 10, sprite, 1, entry);
        number /= 10;
        count = (s8)(count + 1);
        if (count % 3 == 0) {
            if (number != 0) {
                x -= (f32)commaWidth;
                func_0025ec90(x, y, depth, func_002b2a30(0xFF, color.r, g, b), a, comma, sprite, 1, entry);
                x -= (f32)digitWidth;
            } else {
                x -= (f32)digitWidth;
            }
        } else {
            x -= (f32)digitWidth;
        }
    } while (number != 0);
}
#pragma pop

/* measured: object 536B/window 544B, nd 0. Signature (u64, f32, RGBA, s32, s16, u32,
   s32, s32, s32, s32, s32): fparg0 second so it homes to $f22 right after $a0; RGBA
   by value so the colour bytes are lbu from the $a1 home slot; arg5/arg6 are s32
   (dsll32 in place). Stack layout is first-use order high-to-low: 16-byte memset
   target 0xD0, arg1 0xCC, arg0 0xC0, arg3 0xBE, arg7 0xB8. Byte colour locals
   agree with the packer and wrapper contracts. `arg4 = arg4_` before `count = 0`
   so $t0 homes last, comma local declared last for $s7, count s32 with (s8) cast,
   the three `x -= arg2` branches spelled out. */
// FUN_002CACD0
void func_002cacd0(u64 arg0, f32 fparg0, RGBA arg1, s32 arg2, s16 arg3, u32 arg4_, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9)
{
    u8 spD0[16];
    u32 arg4;
    s32 count;
    u8 *entry;
    f32 x;
    f32 y;
    s32 base;
    u8 a;
    u8 b;
    u8 g;
    s32 comma;

    arg4 = arg4_;
    count = 0;
    x = ((f32 *)&arg0)[0];
    func_0043f9c8(spD0, 0, 1);
    entry = D_00793E80 + arg9 * 0x30;
    base = (s16)arg5;
    a = arg1.a;
    b = arg1.b;
    g = arg1.g;
    y = ((f32 *)&arg0)[1];
    comma = (s16)arg6;
    do {
        func_0025ec90(x, y, fparg0, func_002b2a30(0xFF, ((u8 *)&arg1)[0], g, b), a, base + arg4 % 10, (void *)(u32)arg7, 1, entry);
        arg4 /= 10;
        count = (s8)(count + 1);
        if (count % 3 == 0) {
            if (arg4 != 0) {
                x -= (f32)arg3;
                func_0025ec90(x, y, fparg0, func_002b2a30(0xFF, ((u8 *)&arg1)[0], g, b), a, comma, (void *)(u32)arg8, 1, entry);
                x -= (f32)arg2;
            } else {
                x -= (f32)arg2;
            }
        } else {
            x -= (f32)arg2;
        }
    } while (arg4 != 0);
}
// FUN_002CAEF0
void func_002caef0(void *arg0) {
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    u64 spD8;
    u64 spD0;
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    RGBA c0;
    RGBA c1;
    RGBA c2;
    RGBA c3;
    RGBA c4;
    u8 *work;
    u8 *t;
    Vec2f *base;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    base = (Vec2f *)D_0063F5B0;
    func_002e0a60(*(void **)(work + 0xEEC), 0x41, 109.0f);
    func_002b2970(&sp110, base->x, base->y);
    func_002b2970(&sp108, base->x - 750.0f, base->y);
    func_002e0620(*(void **)(work + 0xEEC), sp110, sp108, 0, 4, 0);
    ((u8 *)func_002e04e0(*(void **)(work + 0xEEC)))[0x62] = 0xCC;
    func_002b2a60(&c0, 0, 0, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEEC));
    *(RGBA *)(t + 0x79) = c0;

    base = (Vec2f *)D_0063F5F0;
    func_002e0a60(*(void **)(work + 0xEF4), 0x41, 109.0f);
    func_002b2970(&sp100, base->x, base->y);
    func_002b2970(&spF8, base->x - 750.0f, base->y);
    func_002e0620(*(void **)(work + 0xEF4), sp100, spF8, 0, 4, 0);
    ((u8 *)func_002e04e0(*(void **)(work + 0xEF4)))[0x62] = 0xCC;
    func_002b2a60(&c1, 0, 0, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEF4));
    *(RGBA *)(t + 0x79) = c1;

    base = (Vec2f *)D_0063F5D0;
    func_002e0a60(*(void **)(work + 0xEF8), 0x41, 111.0f);
    func_002b2970(&spF0, base->x, base->y);
    func_002b2970(&spE8, base->x - 750.0f, base->y);
    func_002e0620(*(void **)(work + 0xEF8), spF0, spE8, 0, 4, 0);
    ((u8 *)func_002e04e0(*(void **)(work + 0xEF8)))[0x62] = 0xCC;
    func_002b2a60(&c2, 0, 0, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEF8));
    *(RGBA *)(t + 0x79) = c2;

    func_002e0a60(*(void **)(work + 0xEF0), 0x41, 109.0f);
    func_002b2970(&spE0, 86.0f, 242.0f);
    func_002b2970(&spD8, 786.0f, 242.0f);
    func_002e0620(*(void **)(work + 0xEF0), spE0, spD8, 0, 4, 0);
    func_002b2a60(&c3, 0xFF, 0xCB, 0x35, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEF0));
    *(RGBA *)(t + 0x79) = c3;

    base = (Vec2f *)D_0063F5F8;
    func_002e0a60(*(void **)(work + 0xEFC), 0x41, 112.0f);
    func_002b2970(&spD0, base->x, base->y);
    func_002b2970(&spC8, base->x + 700.0f, base->y);
    func_002e0620(*(void **)(work + 0xEFC), spD0, spC8, 0, 4, 0);
    func_002b2a60(&c4, 0xFF, 0xCB, 0x35, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEFC));
    *(RGBA *)(t + 0x79) = c4;

    base = (Vec2f *)D_0063F5D8;
    func_002e0a60(*(void **)(work + 0xF00), 0x41, 113.0f);
    func_002b2970(&spC0, base->x, base->y);
    func_002b2970(&spB8, base->x + 700.0f, base->y);
    func_002e0620(*(void **)(work + 0xF00), spC0, spB8, 0, 4, 0);

    base = (Vec2f *)D_0063F5E0;
    func_002e0a60(*(void **)(work + 0xF04), 0x41, 114.0f);
    func_002b2970(&spB0, base->x, base->y);
    func_002b2970(&spA8, base->x + 700.0f, base->y);
    func_002e0620(*(void **)(work + 0xF04), spB0, spA8, 0, 4, 0);

    base = (Vec2f *)D_0063F5B0;
    func_002b2970(&spA0, base->x + 660.0f, base->y);
    func_002b2970(&sp98, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC60), spA0, sp98, 0, 4, 6);
    base = (Vec2f *)D_0063F5F0;
    func_002b2970(&sp90, base->x + 660.0f, base->y);
    func_002b2970(&sp88, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC80), sp90, sp88, 0, 4, 6);
    base = (Vec2f *)D_0063F5D0;
    func_002b2970(&sp80, base->x + 660.0f, base->y);
    func_002b2970(&sp78, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC70), sp80, sp78, 0, 4, 6);
    func_002b2970(&sp70, -614.0f, 242.0f);
    func_002b2970(&sp68, 86.0f, 242.0f);
    func_002e0620(*(void **)(work + 0xE80), sp70, sp68, 0, 4, 6);
    base = (Vec2f *)D_0063F5F8;
    func_002b2970(&sp60, base->x - 700.0f, base->y);
    func_002b2970(&sp58, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC84), sp60, sp58, 0, 4, 6);
    base = (Vec2f *)D_0063F5D8;
    func_002b2970(&sp50, base->x - 700.0f, base->y);
    func_002b2970(&sp48, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC74), sp50, sp48, 0, 4, 6);
    base = (Vec2f *)D_0063F5E0;
    func_002b2970(&sp40, base->x - 700.0f, base->y);
    func_002b2970(&sp38, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC78), sp40, sp38, 0, 4, 6);
}

// FUN_002CB6A0
s32 func_002cb6a0(void *arg0) {
    return *(s8 *)(*(u32 *)((u8 *)arg0 + 0x38) + 0xF30) == 1;
}

/* measured: full m2c draft adapted and compiles (rule 2 at all 3 FMA sites:
   retail adda/madd at 0x1CB77C/0x1CCFA4/0x1CD038 = 142.0f + work[0xC] *
   (f32)(field_2-field_4) and 78.0f + 35.0f * (f32)work[8], fs/ft order
   preserved; 0-arg func_002e2670 (draft's 2-arg forms were phantom);
   D_0063FA40/44/46 as real s16 symbols; 75680/0080 shapes fixed); nd 2429.
   Residual: D_0063F778/F8C0/F5B8-style base hoists, 26f0/2670 result width
   (retail uses raw 32-bit, s16 prototypes over-extend), and the usual
   arg-order scrambling. Hoist + width floor. */
/* measured: recipe B re-test 2026-08-03: full draft re-adapted with the
   the Vec2f / u8 base locals (b re-assigned per group, fa for the D_0063FA48/50/
   58/60/68 struct bases - both hoist into saved regs like retail), 3-arg
   func_002e0a60 shapes, 75680 prototype corrected to (s32 x6, void*, s32,
   f32 x3), signed (s16) reads of field_4 (kills the lw/bltz dup), > 5 slti
   form, float literals (140.0f etc. not 0x430A0000): nd 2429 -> 2229, FMA
   head and 0b20/0be0/0080/0970/09b0/0940 shapes byte-exact. Residual: frame
   0x260 vs 0x230 - mwcc b210 spills the loop's func_002e04e0/2a30 results
   (sw/lw 0xF0/0xE0) because the scheduler sinks t[0x62] past the 2a30 call
   (retail keeps lbu before it), 9 saved regs all used; plus the 15 color
   blocks' lbu-binding (see func_002caef0 note). Spill + scheduling floor. */
/* measured 002cb6c0 (owner, trimA width-simplified from Cb002c cand7): 2614 against retail's 2608
   (+0.2%, band 2530-2686 PASS), 668 edits (+12 reloc-only), 2056 differing words.
   Frame 0x220 against retail 0x230; calls 347 matching retail (79x 04e0, 34x 2970,
   20x 2a60, 17x 09e0, 16x 0660, 15x 2670/2a30, 13x 45af60/0940/0620, 9x 2740, ...),
   lwc1 68 / swc1 16 (retail 70/17), madd-adda 6, no HW, dsll32/dsra32 49/49
   (retail 48/48). Adapted from /tmp/cb_cand7.c (2716 instr, 1738 edits):
   dropped all s64-double narrowings ((s16)((s64)(X<<0x30)>>0x30)->(s16)X,
   s8 ((s64)(F<<0x38)>>0x38)==0->F==0, loop-var re-narrows -> plain) saving
   102 instr and 1070 edits; single extends that retail has are kept via plain
   (s16)/s8 compares. Residual is lui +33 / addiu -21 scheduling wall.
   regsave_scan: retail 2608, frame 0x230 vs object 0x220, body saves spare $f21. */
/* measured 002cb6c0 (owner, Vec2f/u8 base hoist): 2589 against retail 2608
   (-0.7%, band 2530-2686 PASS), 567 edits (+12 reloc-only), 2084 differing words.
   Frame still 0x220 vs 0x230, still saves spare $f21. Hoisted all multi-read
   Vec2f bases (F5B8/F5A0/F5A8/F7B0/F7B8/F780/F778/F788/F790/F798/F7A0, both
   F7B0/F7B8 dups) into reassigned `Vec2f *b` and all FA48/50/58/60/68 struct
   bases into reassigned `u8 *fa`, matching the 002caef0/002d1590 pattern and
   clearing most of the lui +33 surplus (-25 instr, -101 edits vs trimA). */
// FUN_002CB6C0 NONMATCHING
#ifdef NON_MATCHING
void func_002cb6c0(void *arg0, s8 arg1) {
    extern s16 func_002e2740(s32);
    void func_0045af60(s32, s32, s32, s32);
    u8 clndGetMoonPhase(u32);
    RGBA c0;
    RGBA c1;
    RGBA c2;
    RGBA c3;
    RGBA c4;
    RGBA c5;
    RGBA c6;
    RGBA c7;
    RGBA c8;
    RGBA c9;
    u8 *work;
    u8 *t;
    Vec2f *b;
    u8 *fa;
    void *r;
    s32 sp22C;
    u32 sp228;
    u32 sp224;
    u32 sp220;
    u32 sp21C;
    Vec2f sp1E8;
    Vec2f sp1E0;
    Vec2f sp1D8;
    Vec2f sp1D0;
    f32 sp1C8;
    f32 sp1CC;
    u64 sp1C0;
    u64 sp1B8;
    u64 sp1B0;
    u64 sp1A8;
    u64 sp1A0;
    u64 sp198;
    u64 sp190;
    Vec2f sp188;
    Vec2f sp180;
    u64 sp178;
    u64 sp170;
    u64 sp168;
    u64 sp160;
    u64 sp158;
    u64 sp150;
    u64 sp148;
    u64 sp140;
    u64 sp138;
    u64 sp130;
    u64 sp128;
    u64 sp120;
    u64 sp118;
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    f32 spDC;
    f32 spD8;
    s8 spD7;
    s64 spC0;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    s16 temp_17_7;
    s16 temp_17_9;
    s16 temp_2;
    s16 temp_2_2;
    s32 temp_17;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 var_18;
    s32 var_19;
    s32 var_23;
    s64 temp_17_2;
    s64 temp_17_6;
    s64 temp_17_8;
    s64 temp_18_10;
    s64 temp_18_11;
    s64 temp_18_12;
    s64 temp_18_13;
    s64 temp_18_14;
    s64 temp_18_15;
    s64 temp_18_16;
    s64 temp_18_17;
    s64 temp_18_18;
    s64 temp_18_3;
    s64 temp_18_4;
    s64 temp_18_5;
    s64 temp_18_6;
    s64 temp_18_7;
    s64 temp_18_8;
    s64 temp_18_9;
    s64 temp_3_4;
    s64 var_20;
    s64 var_22;
    s64 var_6;
    s8 temp_2_3;
    s8 temp_2_4;
    s8 temp_3;
    u32 temp_17_10;
    u32 temp_17_5;
    u32 temp_30;
    u8 temp_18;
    u8 temp_18_2;
    u8 *temp_3_2;
    u8 *temp_3_3;
// var_23 set in switch
    spD7 = arg1;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    if (func_002e2670() >= 6) {
        if (func_002e2670() >= 6) {
            *(f32 *)(work + 0xC) = (f32) (104.0f / (f32) (func_002e2670() - 5));
        }
        // FMA via plain C
        func_002b2970(&sp1E8, (f32)0x221, 142.0f + *(f32 *)(work + 0xC) * (f32)(*(s16 *)(work + 2) - *(s16 *)(work + 4)));
        temp_17 = func_002b2a30(0xFFU, 0xFEU, 0xC6U, 0x31U);
        func_002e0b20(0x36, sp1E8, 138.0f, temp_17, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62), 0, D_00794EA0);
        func_002e04f0(*(void **)(work + 0xC8C), 0, 0);
        func_002e04f0(*(void **)(work + 0xC90), 0, 0);
    } else {
        func_002e04f0(*(void **)(work + 0xC8C), 0, 1);
        func_002e04f0(*(void **)(work + 0xC90), 0, 1);
    }
    func_002b2970(&sp1E0, 51.0f, 48.0f);
    func_002e0080(arg0, *(s8 *)((u8 *)work + *(s8 *)(work + 8) + 0xF73), sp1E0, (void *)func_002b2a30(0xFFU, 0xFFU, 0xFFU, 0xFFU));
    if ((func_002e0570(*(void **)(work + 0xDC8), 1) == 0)) {
        func_002e09e0(*(void **)(work + 0xDC8), 0x41, 124.0f);
        temp_18 = *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62);
        *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xDC8)) + 0x62) = temp_18;
        temp_f20 = *(f32 *)(D_0063F880 + 4) + (f32) (*(s16 *)(work + 4) << 5);
        *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xDC8)) + 0x30) = temp_f20;
    }
    if ((func_002e0570(*(void **)(work + 0xDD0), 1) == 0)) {
        func_002e09e0(*(void **)(work + 0xDD0), 0x41, 125.0f);
        temp_18_2 = *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62);
        *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xDD0)) + 0x62) = temp_18_2;
        temp_f20_2 = *(f32 *)(D_0063F890 + 4) + (f32) (*(s16 *)(work + 4) << 5);
        *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xDD0)) + 0x30) = temp_f20_2;
    }
    temp_3 = *(s8 *)(work + 7);
    switch (temp_3) {                               /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        var_23 = *(u16 *)((u8 *)work + *(s8 *)(work + 8) + 0xF7C) & 0xFFFF;
        break;
    case 2:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
        var_23 = (temp_3 + 0x1A) & 0xFFFF;
        break;
    }
    if ((func_002e29d0() == 0)) {
        var_20 = (*(s16 *)(work + 2) - *(s16 *)(work + 4));
        var_22 = 0;
        spC0 = var_20 + 5;
loop_32:
        temp_17_2 = var_20;
        if (temp_17_2 < spC0) {
            if (temp_17_2 < func_002e2670()) {
                var_19 = func_002b2a30(0xFFU, 0xAEU, 0U, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                var_18 = func_002b2a30(0U, 0xFFU, 0xAEU, 0U);
                func_002b2a60(&sp22C, 0xFF, 0xAE, 0, (s32) *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                temp_30 = func_00106a90((s16)func_002e2740(temp_17_2));
                if ((func_002e7a60() < temp_30) || ((func_00106600((s16)func_002e2740(temp_17_2)) & 0xFF) == 0x63)) {
                    var_19 = func_002b2a30(0xA6U, 0x7FU, 0x2BU, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                    var_18 = func_002b2a30(0U, 0xA6U, 0x7FU, 0x2BU);
                    func_002b2a60(&sp22C, 0xA6, 0x7F, 0x2B, (s32) *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                    if (clndGetMoonPhase(func_002e2740(temp_17_2)) & 0xFF & 1) {
                        var_19 = func_002b2a30(0xA8U, 0x9CU, 0x4CU, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                        var_18 = func_002b2a30(0U, 0xA8U, 0x9CU, 0x4CU);
                        func_002b2a60(&sp22C, 0xA8, 0x9C, 0x4C, (s32) *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                    }
                    if (temp_17_2 == *(s16 *)(work + 2)) {
                        var_19 = func_002b2a30(0x9EU, 0x73U, 0x1DU, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                        var_18 = func_002b2a30(0U, 0x9EU, 0x73U, 0x1DU);
                        func_002b2a60(&sp22C, 0x9E, 0x73, 0x1D, (s32) *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                    }
                } else if (temp_17_2 == *(s16 *)(work + 2)) {
                    var_19 = func_002b2a30(0x2DU, 0x2DU, 0x2DU, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                    var_18 = func_002b2a30(0U, 0x2DU, 0x2DU, 0x2DU);
                    func_002b2a60(&sp22C, 0x2D, 0x2D, 0x2D, (s32) *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                } else if (clndGetMoonPhase(func_002e2740(temp_17_2)) & 0xFF & 1) {
                    var_19 = func_002b2a30(0xFFU, 0xEFU, 0x81U, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                    var_18 = func_002b2a30(0U, 0xFFU, 0xEFU, 0x81U);
                    func_002b2a60(&sp22C, 0xFF, 0xEF, 0x81, (s32) *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62));
                }
                if (clndGetMoonPhase(func_002e2740(temp_17_2)) & 0xFF & 1) {
                    func_002b2970(&sp1D8, 91.0f, (f32) (((var_22) << 5) + 0x7A));
                    temp_17_3 = func_002b2a30(0U, 0xFFU, 0x66U, 0U);
                    func_002e0be0(0x49, sp1D8, 65.0f, temp_17_3, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62), 0, D_00794EA0);
                }
                temp_17_4 = (var_22) << 5;
                func_002b2970(&sp1D0, 146.0f, (f32) (temp_17_4 + 0x85));
                func_002e0b20(var_23, sp1D0, 69.0f, var_18, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62), 0, D_00795E60);
                func_002b2970(&sp1C8, 189.0f, 132.0f + (f32) temp_17_4);
                spD8 = sp1C8;
                spDC = sp1CC;
                temp_18_3 = var_20;
                func_00275680(spD8, spDC, 70.0f, var_19, 0, 1, func_001067f0(func_002e2740(temp_18_3)), 0, 0, D_00795E30, -1);
                func_002b2970(&sp1C0, 498.0f, 142.0f + (f32) temp_17_4);
                temp_17_5 = func_00106a90((s16)func_002e2740(temp_18_3));
                func_002cacd0(sp1C0, 70.0f, *(RGBA *)&sp22C, 0x10, 5, temp_17_5, 9, 0x7B, (s32)func_0046a770(D_0063FB50), (s32) (s64) *(s32 *)((u8 *)work + 0xF28), 0xA9);
            }
            var_20 = (var_20 + 1);
            var_22 = (var_22 + 1);
            goto loop_32;
        }
        if (spD7 != 1) {
            if ((D_008C0276 & 0x1000) && (*(s32 *)(work + 0x14) == 0)) {
                func_0045af60(0, 0, 0, 0);
                if (*(s16 *)(work + 2) == 0) {
                    temp_2 = func_002e26a0();
                    *(s16 *)(work + 2) = temp_2;
                    *(s16 *)(work + 4) = func_002b2cb0(0, (s32)temp_2, 4, 0, 1);
                } else {
                    *(s16 *)(work + 2) = func_002b2d00((s32) *(s16 *)(work + 2), 1, 0, func_002e2670(), 2);
                    *(s16 *)(work + 4) = func_002b2d50((s32) *(s16 *)(work + 2), (s32) *(s16 *)(work + 4), func_002e2670(), 5, -1);
                }
                *(s32 *)(work + 0x14) = 1;
                return;
            }
            if (D_008C027A & 0x1000) {
                if (func_002e2670() > 0) {
                    if (*(s16 *)(work + 2) != 0) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    *(s16 *)(work + 2) = func_002b2d00((s32) *(s16 *)(work + 2), 1, 0, 0, 1);
                    *(s16 *)(work + 4) = func_002b2d50((s32) *(s16 *)(work + 2), (s32) *(s16 *)(work + 4), func_002e2670(), 5, -1);
                    *(s32 *)(work + 0x14) = 1;
                    return;
                }
                goto block_104;
            }
            if ((D_008C0276 & 0x4000) && (*(s32 *)(work + 0x14) == 0)) {
                func_0045af60(0, 0, 0, 0);
                temp_2_2 = func_002b2cb0((s32) *(s16 *)(work + 2), 1, func_002e26a0(), 0, 2);
                *(s16 *)(work + 2) = temp_2_2;
                if ((temp_2_2 == 0)) {
                    *(s16 *)(work + 4) = 0;
                } else if (func_002e26a0() >= 5) {
                    *(s16 *)(work + 4) = func_002b2d50((s32) *(s16 *)(work + 2), (s32) *(s16 *)(work + 4), func_002e26a0(), 5, 1);
                } else {
                    temp_17_6 = func_002e26a0();
                    *(s16 *)(work + 4) = func_002b2d50((s32) *(s16 *)(work + 2), (s32) *(s16 *)(work + 4), (s32) temp_17_6, func_002e2670(), 1);
                }
                *(s32 *)(work + 0x14) = 1;
                return;
            }
            if (D_008C027A & 0x4000) {
                if (func_002e2670() > 0) {
                    temp_17_7 = *(s16 *)(work + 2);
                    if (temp_17_7 != func_002e26a0()) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    *(s16 *)(work + 2) = func_002b2cb0((s32) *(s16 *)(work + 2), 1, func_002e26a0(), 0, 1);
                    if (func_002e26a0() >= 5) {
                        *(s16 *)(work + 4) = func_002b2d50((s32) *(s16 *)(work + 2), (s32) *(s16 *)(work + 4), func_002e26a0(), 5, 1);
                    } else {
                        temp_17_8 = func_002e26a0();
                        *(s16 *)(work + 4) = func_002b2d50((s32) *(s16 *)(work + 2), (s32) *(s16 *)(work + 4), (s32) temp_17_8, func_002e2670(), 1);
                    }
                    *(s32 *)(work + 0x14) = 1;
                    return;
                }
                goto block_104;
            }
            if ((D_008C027A & 2) || (D_008C027A & 0x2000)) {
                temp_17_9 = *(s16 *)(work + 2);
                if (temp_17_9 != func_002e26a0()) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2e70((s32) *(s16 *)(work + 2), (s32) *(s16 *)(work + 4), func_002e2670(), 5, work + 2, work + 4);
            } else if ((D_008C027A & 1) || (D_008C027A & 0x8000)) {
                if (*(s16 *)(work + 2) != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2f90((s32) *(s16 *)(work + 2), (s32) *(s16 *)(work + 4), func_002e2670(), 5, work + 2, work + 4);
            } else if (D_008C027A & 8) {
                func_0045af60(0, 0, 0, 5);
                *(s16 *)(work + 2) = 0;
                *(s16 *)(work + 4) = 0;
                *(s8 *)(work + 8) = func_002b2cb0((s32) *(s8 *)(work + 8), 1, *(s8 *)(work + 9) - 1, 0, 2);
                temp_2_3 = *(s8 *)(work + 7);
                switch (temp_2_3) {                 /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    temp_3_2 = *(s8 *)(work + 8) + work;
                    func_002e2a10(1 << (*(s16 *)(temp_3_2 + 0xF7C) - 0x14), 1 << (*(s8 *)(temp_3_2 + 0xF73) + 4), 2, 2);
                    break;
                case 1:                             /* switch 2 */
                    func_002e2a10(0x4000, 1 << (*(s8 *)((u8 *)work + *(s8 *)(work + 8) + 0xF73) + 4), 2, 2);
                    break;
                case 2:                             /* switch 2 */
                    func_002e2a10(0x8000, 1 << (*(s8 *)((u8 *)work + *(s8 *)(work + 8) + 0xF73) + 4), 2, 2);
                    break;
                }
                func_002d8200(arg0, 0);
            } else if (D_008C027A & 4) {
                func_0045af60(0, 0, 0, 5);
                *(s16 *)(work + 2) = 0;
                *(s16 *)(work + 4) = 0;
                *(s8 *)(work + 8) = func_002b2d00((s32) *(s8 *)(work + 8), 1, 0, *(s8 *)(work + 9) - 1, 2);
                temp_2_4 = *(s8 *)(work + 7);
                switch (temp_2_4) {                 /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    temp_3_3 = *(s8 *)(work + 8) + work;
                    func_002e2a10(1 << (*(s16 *)(temp_3_3 + 0xF7C) - 0x14), 1 << (*(s8 *)(temp_3_3 + 0xF73) + 4), 2, 2);
                    break;
                case 1:                             /* switch 3 */
                    func_002e2a10(0x4000, 1 << (*(s8 *)((u8 *)work + *(s8 *)(work + 8) + 0xF73) + 4), 2, 2);
                    break;
                case 2:                             /* switch 3 */
                    func_002e2a10(0x8000, 1 << (*(s8 *)((u8 *)work + *(s8 *)(work + 8) + 0xF73) + 4), 2, 2);
                    break;
                }
                func_002d8200(arg0, 1);
            } else if (D_008C024E & 0x40) {
                if (func_002e2670() > 0) {
                    temp_17_10 = func_00106a90((s16)func_002e2740(*(s16 *)(work + 2)));
                    if ((func_002e7a60() >= temp_17_10) && ((func_00106600((s16)func_002e2740(*(s16 *)(work + 2))) & 0xFF) < 0x63)) {
                        func_0045af60(0, 0, 0, 1);
                        t = (u8 *)func_002e04e0(*(void **)(work + 0xDC8));
                        *(u8 *)(work + 0xF3E) = *(u8 *)(t + 0x79);
                        *(u8 *)(work + 0xF3F) = *(u8 *)(t + 0x7A);
                        *(u8 *)(work + 0xF40) = *(u8 *)(t + 0x7B);
                        *(u8 *)(work + 0xF41) = *(u8 *)(t + 0x7C);
                        t = (u8 *)func_002e04e0(*(void **)(work + 0xDD0));
                        *(u8 *)(work + 0xF42) = *(u8 *)(t + 0x79);
                        *(u8 *)(work + 0xF43) = *(u8 *)(t + 0x7A);
                        *(u8 *)(work + 0xF44) = *(u8 *)(t + 0x7B);
                        *(u8 *)(work + 0xF45) = *(u8 *)(t + 0x7C);
                        *(u8 *)(work + 0xF3C) = 0;
                        *(s8 *)work = 0x1C;
                    } else {
                        func_0045af60(0, 0, 0, 8);
                    }
                } else {
                    func_0045af60(0, 0, 0, 8);
                }
            } else if (D_008C024E & 0x80) {
                if (func_002e2670() > 0) {
                    func_0045af60(0, 1, 0, 3);
                    func_002b2a60(&sp228, 0xFE, 0xC6, 0x31, 0xFF);
                    func_002b2a60(&sp224, 0xFF, 0xE2, 0x91, 0xFF);
                    func_002e0970(*(void **)(work + 0xDC8), sp228, sp224, 1, 4, 0);
                    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xDC8)) + 0x85) = 1;
                    func_002b2a60(&sp220, 0xFE, 0xC6, 0x31, 0xFF);
                    func_002b2a60(&sp21C, 0xFF, 0xE2, 0x91, 0xFF);
                    func_002e0970(*(void **)(work + 0xDD0), sp220, sp21C, 1, 4, 0);
                    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xDD0)) + 0x85) = 1;
                    t = (u8 *)func_0046d200(*(void **)(work + 0xF28), 0x7D);
                    temp_18_4 = func_0046b260(t);
                    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xE2C)) + 0x100) = (s16) temp_18_4;
                                        *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xE2C)) + 0x102) = (s16)(func_0046b2f0(t) / 2.0f);
                    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xE30)) + 0x100) = 0;
                                        *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xE30)) + 0x102) = (s16)(func_0046b2f0(t) / 2.0f);
                    func_002e0940(*(void **)(work + 0xE2C), 0.0f, -4.0f, 0, 2, 0);
                    func_002e0940(*(void **)(work + 0xE30), 0.0f, -4.0f, 0, 2, 0);
                    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE2C)) + 0xCF) = 0;
                    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE30)) + 0xCF) = 0;
                    func_0046d280(t);
                    *(s8 *)work = 0x20;
                }
            } else if (D_008C024E & 0x20) {
                func_0045af60(0, 0, 0, 2);
                func_002e0940(*(void **)(work + 0xD6C), -14.0f, 110.0f, 0, 0xA, 0);
                func_002e0660(*(void **)(work + 0xE2C), *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE2C)) + 0x62), 0U, 0U, 5, 0);
                func_002e0660(*(void **)(work + 0xE30), *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE30)) + 0x62), 0U, 0U, 5, 0);
                func_002e0660(*(void **)(work + 0xD70), *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xD70)) + 0x62), 0U, 0U, 5, 0);
                func_002e0660(*(void **)(work + 0xD7C), *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xD7C)) + 0x62), 0U, 0U, 5, 0);
                func_002e04f0(*(void **)(work + 0xDD8), 0, 1);
                func_002e04f0(*(void **)(work + 0xDE8), 0, 1);
                func_002e04f0(*(void **)(work + 0xDF0), 0, 1);
                func_002e04f0(*(void **)(work + 0xDE4), 0, 1);
                func_002e0660(*(void **)(work + 0xC8C), *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC8C)) + 0x62), 0U, 0U, 5, 0);
                func_002e0660(*(void **)(work + 0xC90), *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC90)) + 0x62), 0U, 0U, 5, 0);
                func_002e0660(*(void **)(work + 0xDC8), *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xDC8)) + 0x62), 0U, 0U, 5, 0);
                func_002e0660(*(void **)(work + 0xDD0), *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xDD0)) + 0x62), 0U, 0U, 5, 0);
                b = (Vec2f *)D_0063F5B8;
                func_002b2970(&sp1B8, b->x, b->y);
                func_002b2970(&sp1B0, b->x, 300.0f + b->y);
                func_002e0620(*(void **)(work + 0xC64), sp1B8, sp1B0, 0, 0xA, 0);
                func_002e0660(*(void **)(work + 0xC64), *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC64)) + 0x62), 0U, 0U, 0xA, 0);
                func_002e09e0(*(void **)(work + 0xC58), 0x40, 162.0f);
                b = (Vec2f *)D_0063F5A0;
                func_002b2970(&sp1A8, b->x, b->y - 450.0f);
                func_002b2970(&sp1A0, b->x, b->y);
                func_002e0620(*(void **)(work + 0xC58), sp1A8, sp1A0, 0, 4, 0);
                func_002e0660(*(void **)(work + 0xC58), 0U, 0xCCU, 0U, 2, 0);
                func_002b2a60(&c9, 0, 0, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xC58));
                *(RGBA *)(t + 0x79) = c9;
                func_002e09e0(*(void **)(work + 0xC5C), 0x40, 163.0f);
                b = (Vec2f *)D_0063F5A8;
                func_002b2970(&sp198, b->x, b->y - 450.0f);
                func_002b2970(&sp190, b->x, b->y);
                func_002e0620(*(void **)(work + 0xC5C), sp198, sp190, 0, 4, 0);
                func_002e0660(*(void **)(work + 0xC5C), 0U, 0xCCU, 0U, 2, 0);
                func_002b2a60(&c8, 0, 0, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xC5C));
                *(RGBA *)(t + 0x79) = c8;
                var_6 = 0;
loop_102:
                if ((var_6) < *(s8 *)(work + 9)) {
                    temp_3_4 = var_6;
                    t = work + (temp_3_4 * 2);
                    *(s16 *)(t + 0xF46) = 0;
                    *(s16 *)(t + 0xF58) = 6;
                    *(s8 *)(work + temp_3_4 + 0xF6A) = 0xFF;
                    var_6 = (var_6 + 1);
                    goto loop_102;
                }
                func_002e04f0(*(void **)(work + 0xED4), 0, 0);
                func_002e0660(*(void **)(work + 0xED4), 0U, 0xFFU, 0U, 4, 0);
                // FMA via plain C
                func_002b2970(&sp188, 47.0f, 78.0f + 35.0f * (f32)*(s8 *)(work + 8));
                t = (u8 *)func_002e04e0(*(void **)(work + 0xED4));
                *(Vec2f *)(t + 0x2C) = sp188;
                func_002e04f0(*(void **)(work + 0xED8), 0, 0);
                func_002e0660(*(void **)(work + 0xED8), 0U, 0xFFU, 0U, 4, 0);
                // FMA via plain C
                func_002b2970(&sp180, 126.0f, 78.0f + 35.0f * (f32)*(s8 *)(work + 8));
                t = (u8 *)func_002e04e0(*(void **)(work + 0xED8));
                *(Vec2f *)(t + 0x2C) = sp180;
                func_002d83c0(arg0);
                func_002e09e0(*(void **)(work + 0xD3C), 0x41, 128.0f);
                func_002e0660(*(void **)(work + 0xD3C), 0U, 0xFFU, 0U, 0xA, 0);
                func_002e09e0(*(void **)(work + 0xD60), 0x41, 78.0f);
                b = (Vec2f *)D_0063F7B0;
                func_002b2970(&sp178, b->x, b->y - (f32) 0x226);
                func_002b2970(&sp170, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD60), sp178, sp170, 2, 4, 0);
                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD60)) + 0x102) = 0;
                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD60)) + 0x100) = (s16)0;
                func_002e0940(*(void **)(work + 0xD60), -5.0f, fGpffff7ad4, 2, 2, 2);
                func_002b2a60(&c7, 0xFF, 0x96, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xD60));
                *(RGBA *)(t + 0x79) = c7;
                func_002e09e0(*(void **)(work + 0xD64), 0x41, 78.0f);
                b = (Vec2f *)D_0063F7B8;
                func_002b2970(&sp168, b->x, b->y - (f32) 0x226);
                func_002b2970(&sp160, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD64), sp168, sp160, 2, 4, 0);
                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD64)) + 0x100) = -0x32;
                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD64)) + 0x102) = -0xDB;
                func_002e0940(*(void **)(work + 0xD64), -5.0f, fGpffff7ad4, 2, 2, 2);
                func_002e09e0(*(void **)(work + 0xDE8), 0x41, 46.0f);
                func_002e0660(*(void **)(work + 0xDE8), 0U, 0xFFU, 0U, 6, 0);
                temp_f20_3 = ((Vec2f *)D_0063F8C0)->x;
                *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xDE8)) + 0x2C) = temp_f20_3;
                temp_f20_4 = ((Vec2f *)D_0063F8C0)->y;
                *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xDE8)) + 0x30) = temp_f20_4;
                func_002e09e0(*(void **)(work + 0xDF0), 0x41, 47.0f);
                func_002e0660(*(void **)(work + 0xDF0), 0U, 0xFFU, 0U, 6, 0);
                *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xDF0)) + 0x2C) = 147.0f;
                *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xDF0)) + 0x30) = 376.0f;
                r = func_0046d200(*(void **)(work + 0xF28), 0x44);
                func_002e09e0(*(void **)(work + 0xD48), 0x56, 53.0f);
                b = (Vec2f *)D_0063F780;
                func_002b2970(&sp158, b->x, -130.0f);
                func_002b2970(&sp150, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD48), sp158, sp150, 2, 5, 0);
                func_002b2a60(&c6, 0xE4, 0xFF, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xD48));
                *(RGBA *)(t + 0x79) = c6;
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
                func_002e09b0(*(void **)(work + 0xD48), (s32) D_0063FA46, (f32) D_0063FA44);
                func_002e0940(*(void **)(work + 0xD48), D_0063FA40, 0.0f, 2, D_0063FA46 + 5, 0);
                func_0046d280(r);
                r = func_0046d200(*(void **)(work + 0xF28), 0x43);
                func_002e09e0(*(void **)(work + 0xD44), 0x56, 54.0f);
                b = (Vec2f *)D_0063F778;
                func_002b2970(&sp148, b->x, -189.0f);
                func_002b2970(&sp140, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD44), sp148, sp140, 2, 5, 3);
                func_002b2a60(&c5, 0xE4, 0xFF, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xD44));
                *(RGBA *)(t + 0x79) = c5;
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD44)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD44)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
                fa = (u8 *)D_0063FA48;
                func_002e09b0(*(void **)(work + 0xD44), (s32) *(s16 *)(fa + 6), (f32) *(s16 *)(fa + 4));
                func_002e0940(*(void **)(work + 0xD44), *(f32 *)fa, 0.0f, 2, *(s16 *)(fa + 6) + 5, 3);
                func_0046d280(r);
                r = func_0046d200(*(void **)(work + 0xF28), 0x45);
                func_002e09e0(*(void **)(work + 0xD4C), 0x56, 55.0f);
                b = (Vec2f *)D_0063F788;
                func_002b2970(&sp138, b->x, -75.0f);
                func_002b2970(&sp130, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD4C), sp138, sp130, 2, 5, 1);
                func_002b2a60(&c4, 0xE4, 0xFF, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xD4C));
                *(RGBA *)(t + 0x79) = c4;
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD4C)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD4C)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
                fa = (u8 *)D_0063FA50;
                func_002e09b0(*(void **)(work + 0xD4C), (s32) *(s16 *)(fa + 6), (f32) *(s16 *)(fa + 4));
                func_002e0940(*(void **)(work + 0xD4C), *(f32 *)fa, 0.0f, 2, *(s16 *)(fa + 6) + 5, 1);
                func_0046d280(r);
                r = func_0046d200(*(void **)(work + 0xF28), 0x46);
                func_002e09e0(*(void **)(work + 0xD50), 0x56, 56.0f);
                b = (Vec2f *)D_0063F790;
                func_002b2970(&sp128, b->x, -165.0f);
                func_002b2970(&sp120, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD50), sp128, sp120, 2, 5, 4);
                func_002b2a60(&c3, 0xE4, 0xFF, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xD50));
                *(RGBA *)(t + 0x79) = c3;
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
                *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0xC4) = 0.0f;
                fa = (u8 *)D_0063FA58;
                func_002e09b0(*(void **)(work + 0xD50), (s32) *(s16 *)(fa + 6), (f32) *(s16 *)(fa + 4));
                func_002e0940(*(void **)(work + 0xD50), *(f32 *)fa, 0.0f, 2, *(s16 *)(fa + 6) + 5, 4);
                func_0046d280(r);
                r = func_0046d200(*(void **)(work + 0xF28), 0x47);
                func_002e09e0(*(void **)(work + 0xD54), 0x56, 57.0f);
                b = (Vec2f *)D_0063F798;
                func_002b2970(&sp118, b->x, -126.0f);
                func_002b2970(&sp110, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD54), sp118, sp110, 2, 5, 2);
                func_002b2a60(&c2, 0xE4, 0xFF, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xD54));
                *(RGBA *)(t + 0x79) = c2;
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
                *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0xC4) = 0.0f;
                fa = (u8 *)D_0063FA60;
                func_002e09b0(*(void **)(work + 0xD54), (s32) *(s16 *)(fa + 6), (f32) *(s16 *)(fa + 4));
                func_002e0940(*(void **)(work + 0xD54), *(f32 *)fa, 0.0f, 1, *(s16 *)(fa + 6) + 5, 2);
                func_0046d280(r);
                r = func_0046d200(*(void **)(work + 0xF28), 0x48);
                func_002e09e0(*(void **)(work + 0xD58), 0x56, 58.0f);
                b = (Vec2f *)D_0063F7A0;
                func_002b2970(&sp108, b->x, -197.0f);
                func_002b2970(&sp100, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD58), sp108, sp100, 2, 5, 5);
                func_002b2a60(&c1, 0xE4, 0xFF, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xD58));
                *(RGBA *)(t + 0x79) = c1;
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
                                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
                *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0xC4) = 0.0f;
                fa = (u8 *)D_0063FA68;
                func_002e09b0(*(void **)(work + 0xD58), (s32) *(s16 *)(fa + 6), (f32) *(s16 *)(fa + 4));
                func_002e0940(*(void **)(work + 0xD58), *(f32 *)fa, 0.0f, 2, *(s16 *)(fa + 6) + 5, 5);
                func_0046d280(r);
                func_002e09e0(*(void **)(work + 0xD60), 0x41, 78.0f);
                b = (Vec2f *)D_0063F7B0;
                func_002b2970(&spF8, b->x, b->y - (f32) 0x226);
                func_002b2970(&spF0, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD60), spF8, spF0, 2, 4, 0);
                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD60)) + 0x102) = 0;
                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD60)) + 0x100) = (s16)0;
                func_002e0940(*(void **)(work + 0xD60), -5.0f, fGpffff7ad4, 2, 2, 2);
                func_002b2a60(&c0, 0xFF, 0x96, 0, 0xFF);
                t = (u8 *)func_002e04e0(*(void **)(work + 0xD60));
                *(RGBA *)(t + 0x79) = c0;
                func_002e09e0(*(void **)(work + 0xD64), 0x41, 78.0f);
                b = (Vec2f *)D_0063F7B8;
                func_002b2970(&spE8, b->x, b->y - (f32) 0x226);
                func_002b2970(&spE0, b->x, b->y);
                func_002e0620(*(void **)(work + 0xD64), spE8, spE0, 2, 4, 0);
                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD64)) + 0x100) = -0x32;
                *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD64)) + 0x102) = -0xDB;
                func_002e0940(*(void **)(work + 0xD64), -5.0f, fGpffff7ad4, 2, 2, 2);
                *(s8 *)work = 0x15;
            }
block_104:
            *(s32 *)(work + 0x14) = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002cb6c0);
#endif

/* measured 002cdf80 (owner, width-selected from m2c-adapted V8): 3545 against retail 3460
   (+2.5%, band 3356-3563 PASS, 18 of headroom), 2042 edits (+36 reloc-only), 3047 differing words.
   regsave_scan: retail 3460 instrs, frame 0x220 vs object 0x290, body saves spare $f21 $f22.
   calls 374 matching retail 374 (81x 04e0, 47x 26f0, 34x 2970, 19x 04f0, 18x 0660,
   17x 09e0, 16x 45af60, 15x 2a60/0620, 13x 0b20, 9x 0700, 8x 0570, 7x 2a30/2d50, 6x 46a770/05a0/3560,
   5x 2830/2cb0, 4x cacd0/2d00, 3x 46d200/46b260/46d280/0940, 2x 106a90/0ca0/2b2f90/2d4760/2d7c10,
   1x 2700/2a00/106880/1067f0/275680/106600/2b2e70/2b3050/46b2f0/2dd230); lwc1 66 / swc1 18,
   mtc1 115, add.s 28, madd 1 / adda 1 (142.0f + work[0xC] * (s16)(work[2]-work[4]) via plain C),
   cvt.s.w 17, no HW (ldr 9 / ldl 9 as *(u64*)(s1+0x2C) per file rule 1, lq 10 / sq 10 / sd 9 for spills),
   dsll32/dsra32 80/80 (retail 80/80), nop 589 (17.0%), 177 branches (56 b + 121 cond, all delay slots
   empty), 1 jr (return, no switch). Adapted from /tmp/cold_cdf80/m2c.c (876 lines) with u8* work,
   Vec2f/u64 slots, s16/s8 widths via plain casts, RGBA via separate bytes pending, FMA via plain C,
   0620 u64 via *(u64*)(s1+0x2C), cacd0 11-arg (phantom stack arg dropped), 2670 0-arg, GP floats as 0.0f,
   D_0063FAA0 local extern. Width selection (individual bisection, cf. 001a7720): V8 all-s64-ish 3581
   (+3.5%, 18 over top, 1896 edits, 3080 words) FAIL; narrow temp_18 (s64->s32, 10 uses) 3545 (-36, PASS,
   2042 edits, 3047 words) LANDING; narrow temp_17_4 (9 uses) 3576 (-5, 1888 edits) FAIL. temp_18 models
   $s2 from $v0 after void 2700 (retail dsll32/dsra32 16, uninitialized in C, saves 36 vs s64); sp1A4/sp1DC
   added as f32 (Vec2f halves), 35 missing u8 bytes added. Production guarded (edits 2042). */
/* measured 002cdf80 (owner, 2026-09-19): fnalign **2042 -> 2040 edits**, count
   3545 -> 3543 against retail 3460, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
/* measured 002cdf80 (owner, 2026-09-20): fnalign **2040 -> 2025 edits** (-15), count
   3543 -> 3506 against retail 3460 (+46, +1.3%, band 3356-3563 PASS with 57 headroom),
   frame 0x290 -> 0x280, __floatdisf removed (1 jal). No unsuffixed doubles
   (grep -nE '[0-9]+\\.[0-9]+([^fFeE0-9]|$)' on extracted body: 0 hits, ruled out first
   per assignment). The over-long object is recomputation retail hoists (reverse of the
   usual body-hoists/retail-recomputes direction): hoist work+index*4 duplicate
   (temp_2_24 = temp_3_10 instead of recomputing work+var_19_5*4, -4/+ -10 edits) and
   hoist 2830 results with same args in same iteration (369's dispatch + 397/398/404's
   275680/106a90/106600 chain share one temp_17 via temp_17_4, -19/-7 edits, combined
   -23/-4 vs baseline), plus narrow var_19_5/temp_18_5 s64->s32 for the 0..7 loop
   (removes s64->float __floatdisf helper + dsll32/dsra32 extends + daddiu/dsll, -7/-11).
   Rejected hoists that worsen edits (retail recomputes them, usual direction):
   46a770(FB50/FAA0) per-branch duplicates (-10 count but +18/+16 edits),
   D_0063F888/DCC-DD0 float (-5/+16), 2a30 0x2D duplicate (-6/+4), 04e0 E44/E48/E40
   per-branch duplicates (+5 count from new spill). Repro: measure_guarded
   --save-candidate + fnalign --candidate <path> --quiet. */

// FUN_002CDF80 NONMATCHING
#ifdef NON_MATCHING
void func_002cdf80(void *arg0, s8 arg1) {
    extern u8 D_0063FAA0[];
    s32 func_002e05a0(void *);
    s8 func_002e2a00(void *);
    void func_002e3560(void *, s32, s32, s32, s32);
    void func_002b3050(s16, s16, s32, s32, s32, s16 *, s16 *);
    s8 func_002d4760(void *, s8);
    void func_002d7c10(void *, s16);
    void func_002dd230(void *);
    RGBA sp21C;
    u8 sp218;
    u8 sp214;
    u8 sp210;
    RGBA sp20C;
    RGBA sp208;
    u8 sp204;
    u8 sp200;
    u8 sp1FC;
    u8 sp1F8;
    u8 sp1F4;
    u8 sp1F0;
    u8 sp1EC;
    u8 sp1E8;
    Vec2f sp1E0;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    Vec2f sp1C8;
    u64 sp1C0;
    u64 sp1B8;
    Vec2f sp1B0;
    Vec2f sp1A8;
    f32 sp1A0;
    u64 sp198;
    Vec2f sp190;
    u64 sp188;
    u64 sp180;
    u64 sp178;
    u64 sp170;
    u64 sp168;
    u64 sp160;
    u64 sp158;
    u64 sp150;
    u64 sp148;
    u64 sp140;
    u64 sp138;
    u64 sp130;
    u64 sp128;
    u64 sp120;
    u64 sp118;
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    f32 spDC;
    f32 spD8;
    s8 spD7;
    s32 spD0;
    s64 spC0;
    f32 sp1A4;
    f32 sp1DC;
    u8 sp1E9;
    u8 sp1EA;
    u8 sp1EB;
    u8 sp1ED;
    u8 sp1EE;
    u8 sp1EF;
    u8 sp1F1;
    u8 sp1F2;
    u8 sp1F3;
    u8 sp1F5;
    u8 sp1F6;
    u8 sp1F7;
    u8 sp1F9;
    u8 sp1FA;
    u8 sp1FB;
    u8 sp1FD;
    u8 sp1FE;
    u8 sp1FF;
    u8 sp201;
    u8 sp202;
    u8 sp203;
    u8 sp205;
    u8 sp206;
    u8 sp207;
    u8 sp211;
    u8 sp212;
    u8 sp213;
    u8 sp215;
    u8 sp216;
    u8 sp217;
    u8 sp219;
    u8 sp21A;
    u8 sp21B;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    s16 temp_17;
    s16 temp_17_11;
    s16 temp_17_12;
    s16 temp_17_13;
    s16 temp_17_14;
    s16 temp_17_15;
    s16 temp_17_16;
    s16 temp_18_3;
    s16 temp_18_4;
    s16 temp_2_13;
    s32 temp_19_2;
    s32 temp_30;
    s32 temp_30_2;
    s32 var_19_2;
    s32 var_22;
    s64 temp_17_4;
    s64 temp_17_5;
    s64 temp_17_7;
    s64 temp_17_9;
    s32 temp_18;
    s32 temp_18_5;
    s64 temp_22;
    s64 temp_3;
    s64 temp_3_11;
    s64 temp_3_3;
    s64 temp_3_5;
    s64 temp_3_7;
    s64 temp_3_8;
    s64 temp_3_9;
    s64 temp_4;
    s64 var_17;
    s64 var_17_2;
    s64 var_17_3;
    s64 var_17_4;
    s64 var_19;
    s64 var_19_3;
    s64 var_19_4;
    s32 var_19_5;
    s64 var_21;
    s64 var_23;
    s64 var_5;
    s64 var_5_2;
    s64 var_6;
    s64 var_6_2;
    s8 temp_17_10;
    s8 temp_17_8;
    s8 temp_18_2;
    s8 temp_19;
    s8 temp_19_4;
    s8 temp_19_5;
    s8 temp_19_6;
    s8 temp_2_14;
    s8 temp_2_16;
    s8 temp_2_17;
    s8 temp_2_19;
    s8 temp_2_20;
    s8 temp_2_4;
    s8 temp_3_2;
    s8 temp_3_4;
    s8 temp_3_6;
    s8 temp_4_2;
    s8 temp_4_3;
    u32 temp_17_6;
    u32 temp_19_3;
    u32 temp_22_2;
    u32 temp_2_12;
    u8 *work;
    u8 *temp_17_17;
    u8 *temp_17_18;
    u8 *temp_17_19;
    u8 *temp_17_20;
    u8 *temp_17_21;
    u8 *temp_17_22;
    u8 *temp_17_23;
    u8 *temp_17_24;
    u8 *temp_17_25;
    u8 *temp_17_26;
    u8 *temp_17_2;
    u8 *temp_17_3;
    u8 *temp_21;
    u8 *temp_21_2;
    u8 *temp_2;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_15;
    u8 *temp_2_18;
    u8 *temp_2_21;
    u8 *temp_2_22;
    u8 *temp_2_23;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_26;
    u8 *temp_2_27;
    u8 *temp_2_28;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;
    u8 *temp_3_10;

    spD7 = arg1;
    work = (*(void**)((u8*)arg0+0x38));
    func_002e2700((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18)));
    temp_17 = func_002e2830((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18)), (s32) (*(s16*)((u8*)work+0x2)));
    var_19 = 0;
do {
        temp_3 = (s64) (var_19 << 0x30) >> 0x30;
            func_002e04f0((*(void**)((u8*)((work + (temp_3 * 4)))+0xE40)), 0, 1);
            var_19 = (s64) ((var_19 + 1) << 0x30) >> 0x30;
} while (temp_3 < 3);
    if (func_002e2a00((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) == 0) {
        temp_19 = (*(s8*)((u8*)work+0x11));
        if (D_00748908[temp_19] >= func_002e26f0((*(void**)((u8*)(((temp_19 * 4) + work))+0xF18)))) {
            func_002e09e0((*(void**)((u8*)work+0xE68)), 0x57, 117.0f);
            func_002b2a60(&sp218, 0x2D, 0x2D, 0x2D, 0xFF);
            temp_2 = func_002e04e0((*(void**)((u8*)work+0xE68)));
            (*(u8*)((u8*)temp_2+0x79)) = sp218;
            (*(u8*)((u8*)temp_2+0x7A)) = sp219;
            (*(u8*)((u8*)temp_2+0x7B)) = sp21A;
            (*(u8*)((u8*)temp_2+0x7C)) = sp21B;
            func_002e09e0((*(void**)((u8*)work+0xE6C)), 0x56, 118.0f);
            func_002b2a60(&sp214, 0x6B, 0x6B, 0x6B, 0xFF);
            temp_2_2 = func_002e04e0((*(void**)((u8*)work+0xE6C)));
            (*(u8*)((u8*)temp_2_2+0x79)) = sp214;
            (*(u8*)((u8*)temp_2_2+0x7A)) = sp215;
            (*(u8*)((u8*)temp_2_2+0x7B)) = sp216;
            (*(u8*)((u8*)temp_2_2+0x7C)) = sp217;
            func_002e09e0((*(void**)((u8*)work+0xE70)), 0x56, 119.0f);
            func_002b2a60(&sp210, 0x6B, 0x6B, 0x6B, 0xFF);
            temp_2_3 = func_002e04e0((*(void**)((u8*)work+0xE70)));
            (*(u8*)((u8*)temp_2_3+0x79)) = sp210;
            (*(u8*)((u8*)temp_2_3+0x7A)) = sp211;
            (*(u8*)((u8*)temp_2_3+0x7B)) = sp212;
            (*(u8*)((u8*)temp_2_3+0x7C)) = sp213;
            func_002e04f0((*(void**)((u8*)work+0xDCC)), 0, 1);
            func_002e04f0((*(void**)((u8*)work+0xDD0)), 0, 1);
            func_002e04f0((*(void**)((u8*)work+0xC8C)), 0, 1);
            func_002e04f0((*(void**)((u8*)work+0xC90)), 0, 1);
        } else {
            if (func_002e26f0((*(void**)((u8*)(((temp_19 * 4) + work))+0xF18))) >= 6) {
                if (func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) >= 6) {
                    (*(f32*)((u8*)work+0xC)) = (f32) (104.0f / (f32) (func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) - 5));
                }
                func_002b2970(&sp1C8, (f32)0x221, 142.0f + (*(f32*)((u8*)work+0xC)) * (f32)(*(s16*)((u8*)work+0x2) - *(s16*)((u8*)work+0x4)));
                temp_19_2 = func_002b2a30(0xFFU, 0xFEU, 0xC6U, 0x31U);
                func_002e0b20(0x36, sp1C8, 138.0f, temp_19_2, (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC94))))+0x62)), 0, D_00794EA0);
                func_002e04f0((*(void**)((u8*)work+0xC8C)), 0, 0);
                func_002e04f0((*(void**)((u8*)work+0xC90)), 0, 0);
            } else {
                func_002e04f0((*(void**)((u8*)work+0xC8C)), 0, 1);
                func_002e04f0((*(void**)((u8*)work+0xC90)), 0, 1);
            }
            if (((*(s8*)((u8*)work+0x11)) == 0) && ((*(s16*)((u8*)work+0x2)) == 0)) {
                func_002b2970(&sp1C0, (f32) 0x24E, 61.0f);
                func_002b2a60(&sp20C, 0xFF, 0xFF, 0xFF, 0xFF);
                temp_17_2 = func_0046a770(&D_0063FAA0);
                func_002cacd0(sp1C0, 1.0f, sp20C, 0x11, 5, (*(s32*)((u8*)work+0xC20)), 0x70, 0x7A, (s32) temp_17_2, (s32) func_0046a770(&D_0063FAA0), 0xAA);
            } else {
                temp_19_3 = func_00106a90((s16) ((s64) ((s64) temp_17 << 0x30) >> 0x30)) / 5U;
                func_002b2970(&sp1B8, (f32) 0x24E, 61.0f);
                func_002b2a60(&sp208, 0xFF, 0xFF, 0xFF, 0xFF);
                temp_17_3 = func_0046a770(&D_0063FAA0);
                func_002cacd0(sp1B8, 1.0f, sp208, 0x11, 5, (*(s16*)((u8*)work+0x12)) * temp_19_3, 0x70, 0x7A, (s32) temp_17_3, (s32) func_0046a770(&D_0063FAA0), 0xAA);
            }
            if (func_002e0570((*(void**)((u8*)work+0xDCC)), 1) == 0) {
                temp_f20 = D_0063F888[1] + (f32) ((*(s16*)((u8*)work+0x4)) << 5);
                (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDCC))))+0x30)) = temp_f20;
            }
            if (func_002e0570((*(void**)((u8*)work+0xDD0)), 1) == 0) {
                temp_f20_2 = D_0063F888[1] + (f32) ((*(s16*)((u8*)work+0x4)) << 5);
                (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDD0))))+0x30)) = temp_f20_2;
            }
            func_002e04f0((*(void**)((u8*)work+0xE68)), 0, 1);
            func_002e04f0((*(void**)((u8*)work+0xE6C)), 0, 1);
            func_002e04f0((*(void**)((u8*)work+0xE70)), 0, 1);
            var_21 = (s64) (((*(s16*)((u8*)work+0x2)) - (*(s16*)((u8*)work+0x4))) << 0x30) >> 0x30;
            var_23 = 0;
            spC0 = var_21 + func_002b2cb0(0, func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 5, 0, 1);
loop_60:
            temp_17_4 = (s64) (var_21 << 0x30) >> 0x30;
            if (temp_17_4 < spC0) {
                if (temp_17_4 < func_002e26f0((*(void**)((u8*)((work + ((*(s8*)((u8*)work+0x11)) * 4)))+0xF18)))) {
                    spD0 = func_002b2a30(0xFFU, 0xAEU, 0U, (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC8C))))+0x62)));
                    var_19_2 = func_002b2a30(0U, 0xFFU, 0xAEU, 0U);
                    func_002b2a60(&sp21C, 0xFF, 0xAE, 0, (s32) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC8C))))+0x62)));
                    var_22 = func_002b2a30(0U, 0xFEU, 0xC7U, 0x31U);
                    if (temp_17_4 == (*(s16*)((u8*)work+0x2))) {
                        spD0 = func_002b2a30(0x2DU, 0x2DU, 0x2DU, (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC8C))))+0x62)));
                        var_19_2 = func_002b2a30(0U, 0x2DU, 0x2DU, 0x2DU);
                        func_002b2a60(&sp21C, 0x2D, 0x2D, 0x2D, (s32) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC8C))))+0x62)));
                        var_22 = func_002b2a30(0U, 0x2DU, 0x2DU, 0x2DU);
                    }
                    temp_2_4 = (*(s8*)((u8*)work+0x11));
                    if ((temp_2_4 == 0) && (temp_17_4 == 0)) {
                        if (func_002e26f0((*(void**)((u8*)((work + (temp_2_4 * 4)))+0xF18))) >= 2) {
                            var_19_3 = 0;
loop_28:
                            if (((s64) (var_19_3 << 0x30) >> 0x30) < 3) {
                                temp_30 = ((s64) (var_19_3 << 0x30) >> 0x30) << 5;
                                func_002b2970(&sp1B0, (f32) (temp_30 + 0x6F), 143.0f);
                                func_002e0b20(0x3C, sp1B0, 115.0f, var_22, 0xFFU, 0, D_00795E60);
                                func_002b2970(&sp1A8, (f32) (temp_30 + 0x1A1), 143.0f);
                                func_002e0b20(0x3C, sp1A8, 115.0f, var_22, 0xFFU, 0, D_00795E60);
                                var_19_3 = (s64) ((var_19_3 + 1) << 0x30) >> 0x30;
                                goto loop_28;
                            }
                            func_002e09e0((*(void**)((u8*)work+0xE44)), 0x56, 121.0f);
                            func_002b2a60(&sp204, 0xFE, 0xC7, 0x31, 0xFF);
                            temp_2_5 = func_002e04e0((*(void**)((u8*)work+0xE44)));
                            (*(u8*)((u8*)temp_2_5+0x79)) = sp204;
                            (*(u8*)((u8*)temp_2_5+0x7A)) = sp205;
                            (*(u8*)((u8*)temp_2_5+0x7B)) = sp206;
                            (*(u8*)((u8*)temp_2_5+0x7C)) = sp207;
                            if (temp_17_4 == (*(s16*)((u8*)work+0x2))) {
                                func_002b2a60(&sp200, 0x2D, 0x2D, 0x2D, 0xFF);
                                temp_2_6 = func_002e04e0((*(void**)((u8*)work+0xE44)));
                                (*(u8*)((u8*)temp_2_6+0x79)) = sp200;
                                (*(u8*)((u8*)temp_2_6+0x7A)) = sp201;
                                (*(u8*)((u8*)temp_2_6+0x7B)) = sp202;
                                (*(u8*)((u8*)temp_2_6+0x7C)) = sp203;
                            }
                            func_002e09e0((*(void**)((u8*)work+0xE48)), 0x56, 122.0f);
                            func_002b2a60(&sp1FC, 0xFE, 0xC7, 0x31, 0xFF);
                            temp_2_7 = func_002e04e0((*(void**)((u8*)work+0xE48)));
                            (*(u8*)((u8*)temp_2_7+0x79)) = sp1FC;
                            (*(u8*)((u8*)temp_2_7+0x7A)) = sp1FD;
                            (*(u8*)((u8*)temp_2_7+0x7B)) = sp1FE;
                            (*(u8*)((u8*)temp_2_7+0x7C)) = sp1FF;
                            if (temp_17_4 == (*(s16*)((u8*)work+0x2))) {
                                func_002b2a60(&sp1F8, 0x2D, 0x2D, 0x2D, 0xFF);
                                temp_2_8 = func_002e04e0((*(void**)((u8*)work+0xE48)));
                                (*(u8*)((u8*)temp_2_8+0x79)) = sp1F8;
                                (*(u8*)((u8*)temp_2_8+0x7A)) = sp1F9;
                                (*(u8*)((u8*)temp_2_8+0x7B)) = sp1FA;
                                (*(u8*)((u8*)temp_2_8+0x7C)) = sp1FB;
                            }
                            func_002e09e0((*(void**)((u8*)work+0xE40)), 0x57, 120.0f);
                            func_002b2a60(&sp1F4, 0x2D, 0x2D, 0x2D, 0xFF);
                            temp_2_9 = func_002e04e0((*(void**)((u8*)work+0xE40)));
                            (*(u8*)((u8*)temp_2_9+0x79)) = sp1F4;
                            (*(u8*)((u8*)temp_2_9+0x7A)) = sp1F5;
                            (*(u8*)((u8*)temp_2_9+0x7B)) = sp1F6;
                            (*(u8*)((u8*)temp_2_9+0x7C)) = sp1F7;
                            if (temp_17_4 == (*(s16*)((u8*)work+0x2))) {
                                func_002b2a60(&sp1F0, 0xFE, 0xC7, 0x31, 0xFF);
                                temp_2_10 = func_002e04e0((*(void**)((u8*)work+0xE40)));
                                (*(u8*)((u8*)temp_2_10+0x79)) = sp1F0;
                                (*(u8*)((u8*)temp_2_10+0x7A)) = sp1F1;
                                (*(u8*)((u8*)temp_2_10+0x7B)) = sp1F2;
                                (*(u8*)((u8*)temp_2_10+0x7C)) = sp1F3;
                            }
                        }
                    } else {
                        temp_22 = (s64) (var_23 << 0x30) >> 0x30;
                        temp_30_2 = temp_22 << 5;
                        func_002b2970(&sp1D8, D_0063F888[0], D_0063F888[1] + (f32) temp_30_2);
                        func_002b2970(&sp1E0, 10.0f + sp1D8, 9.0f + sp1DC);
                        func_002b2970(&sp1D0, 70.0f, 126.0f + (f32) temp_30_2);
                        if (temp_22 == (*(s16*)((u8*)work+0x4))) {
                            temp_f20_3 = 10.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDCC))))+0x2C));
                            func_002b2970(&sp1E0, temp_f20_3, 9.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDCC))))+0x30)));
                            temp_2_11 = func_002e04e0((*(void**)((u8*)work+0xDCC)));
                            sp1D0 = (*(f32*)((u8*)temp_2_11+0x2C));
                            sp1D4 = (*(f32*)((u8*)temp_2_11+0x30));
                        }
                        temp_17 = func_002e2830((*(void**)((u8*)((work + ((*(s8*)((u8*)work+0x11)) * 4)))+0xF18)), (s32) temp_17_4);
                        temp_2_12 = func_00106880(temp_17);
                        if (temp_2_12 & 0x81) {
                            func_002e0b20(0x14, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else if (temp_2_12 & 0x102) {
                            func_002e0b20(0x15, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else if (temp_2_12 & 0x204) {
                            func_002e0b20(0x16, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else if (temp_2_12 & 0x408) {
                            func_002e0b20(0x17, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else if (temp_2_12 & 0x810) {
                            func_002e0b20(0x18, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else if (temp_2_12 & 0x1020) {
                            func_002e0b20(0x19, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else if (temp_2_12 & 0x2040) {
                            func_002e0b20(0x1A, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else if (temp_2_12 & 0x4000) {
                            func_002e0b20(0x1B, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else if (temp_2_12 & 0x8000) {
                            func_002e0b20(0x1C, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else if (temp_2_12 & 0x40000) {
                            func_002e0ca0(0x1A, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        } else {
                            func_002e0ca0(0x1B, sp1E0, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        }
                        func_002b2970(&sp1A0, 53.0f + sp1D0, 7.0f + sp1D4);
                        spD8 = sp1A0;
                        spDC = sp1A4;
                        temp_17_5 = (s64) (var_21 << 0x30) >> 0x30;
                        func_00275680(spD8, spDC, 115.0f, spD0, 0, 1, func_001067f0((s32) temp_17), 0, 0, D_00795E30, -1);
                        temp_22_2 = func_00106a90(temp_17) / 5U;
                        func_002b2970(&sp198, 372.0f + sp1D0, 16.0f + sp1D4);
                        func_002cacd0(sp198, 115.0f, sp21C, 0x10, 5, temp_22_2, 9, 0x7B, (s32)func_0046a770(D_0063FB50), (s32) (s64) (*(s32*)((u8*)work+0xF28)), 0xA9);
                        func_002b2970(&sp190, 400.0f + sp1D0, 18.0f + sp1D4);
                        func_002e0b20(0x47, sp190, 115.0f, var_19_2, 0xFFU, 0, D_00795E60);
                        func_002b2970(&sp188, (f32) 0x1AF + sp1D0, 16.0f + sp1D4);
                        temp_17_6 = func_00106600(temp_17) & 0xFF;
                        func_002cacd0(sp188, 115.0f, sp21C, 0x10, 5, temp_17_6, 9, 0x7B, (s32)func_0046a770(D_0063FB50), (s32) (s64) (*(s32*)((u8*)work+0xF28)), 0xA9);
                    }
                }
                var_21 = (s64) ((var_21 + 1) << 0x30) >> 0x30;
                var_23 = (s64) ((var_23 + 1) << 0x30) >> 0x30;
                goto loop_60;
            }
        }
        if ((spD7 != 2) && (func_002e0570((*(void**)((u8*)work+0xDCC)), 1) == 0) && (func_002e0570((*(void**)((u8*)work+0xDD0)), 1) == 0) && (func_002e05a0((*(void**)((u8*)work+0xD44))) == 0) && (func_002e05a0((*(void**)((u8*)work+0xD48))) == 0) && (func_002e05a0((*(void**)((u8*)work+0xD4C))) == 0) && (func_002e05a0((*(void**)((u8*)work+0xD50))) == 0) && (func_002e05a0((*(void**)((u8*)work+0xD54))) == 0) && (func_002e05a0((*(void**)((u8*)work+0xD58))) == 0)) {
            if ((D_008C0276 & 0x1000) && ((*(s8*)((u8*)work+0x14)) == 0)) {
                temp_19_4 = (*(s8*)((u8*)work+0x11));
                if (D_00748908[temp_19_4] < func_002e26f0((*(void**)((u8*)(((temp_19_4 * 4) + work))+0xF18)))) {
                    if ((spD7 == 1) && (temp_19_4 == 0) && ((*(s16*)((u8*)work+0x2)) == 1)) {
                        func_0045af60(0, 0, 0, 0);
                        (*(s16*)((u8*)work+0x2)) = func_002b2d00((s32) (*(s16*)((u8*)work+0x2)), 1, 0, (s32) func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 2);
                        (*(s16*)((u8*)work+0x4)) = func_002b2d50((s32) (*(s16*)((u8*)work+0x2)), (s32) (*(s16*)((u8*)work+0x4)), (s32) func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 5, -1);
                    }
                    if ((*(s16*)((u8*)work+0x2)) == 0) {
                        func_0045af60(0, 0, 0, 0);
                        (*(s16*)((u8*)work+0x2)) = (s16) temp_18;
                        (*(s16*)((u8*)work+0x4)) = func_002b2cb0(0, (s32) ((s64) (temp_18 << 0x30) >> 0x30), 4, 0, 1);
                    } else {
                        func_0045af60(0, 0, 0, 0);
                        (*(s16*)((u8*)work+0x2)) = func_002b2d00((s32) (*(s16*)((u8*)work+0x2)), 1, 0, (s32) func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 2);
                        (*(s16*)((u8*)work+0x4)) = func_002b2d50((s32) (*(s16*)((u8*)work+0x2)), (s32) (*(s16*)((u8*)work+0x4)), (s32) func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 5, -1);
                    }
                    (*(s8*)((u8*)work+0x14)) = 1;
                }
            } else if (D_008C027A & 0x1000) {
                temp_18_2 = (*(s8*)((u8*)work+0x11));
                if ((D_00748908[temp_18_2] < func_002e26f0((*(void**)((u8*)(((temp_18_2 * 4) + work))+0xF18)))) && ((spD7 != 1) || (temp_18_2 != 0) || ((*(s16*)((u8*)work+0x2)) != 1))) {
                    if (func_002e26f0((*(void**)((u8*)(((temp_18_2 * 4) + work))+0xF18))) > 0) {
                        if ((*(s16*)((u8*)work+0x2)) != 0) {
                            func_0045af60(0, 0, 0, 0);
                        }
                        (*(s16*)((u8*)work+0x2)) = func_002b2d00((s32) (*(s16*)((u8*)work+0x2)), 1, 0, 0, 1);
                        (*(s16*)((u8*)work+0x4)) = func_002b2d50((s32) (*(s16*)((u8*)work+0x2)), (s32) (*(s16*)((u8*)work+0x4)), (s32) func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 5, -1);
                    }
                    (*(s8*)((u8*)work+0x14)) = 1;
                }
            } else if ((D_008C0276 & 0x4000) && ((*(s8*)((u8*)work+0x14)) == 0)) {
                if (D_00748908[(*(s8*)((u8*)work+0x11))] < func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18)))) {
                    func_0045af60(0, 0, 0, 0);
                    temp_17_7 = (s64) (temp_18 << 0x30) >> 0x30;
                    temp_2_13 = func_002b2cb0((s32) (*(s16*)((u8*)work+0x2)), 1, (s32) temp_17_7, 0, 2);
                    (*(s16*)((u8*)work+0x2)) = temp_2_13;
                    temp_4 = (s64) ((s64) temp_2_13 << 0x30) >> 0x30;
                    if (temp_4 == 0) {
                        (*(s16*)((u8*)work+0x4)) = 0;
                        if (((*(s8*)((u8*)work+0x11)) == 0) && ((*(s8*)((u8*)work+0xC24)) == 1)) {
                            (*(s16*)((u8*)work+0x2)) = 1;
                            (*(s16*)((u8*)work+0x4)) = 1;
                        }
                    } else if (temp_17_7 >= 5) {
                        (*(s16*)((u8*)work+0x4)) = func_002b2d50((s32) temp_4, (s32) (*(s16*)((u8*)work+0x4)), (s32) temp_18, 5, 1);
                    } else {
                        (*(s16*)((u8*)work+0x4)) = func_002b2d50((s32) (*(s16*)((u8*)work+0x2)), (s32) (*(s16*)((u8*)work+0x4)), (s32) temp_18, (s32) func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 1);
                    }
                    (*(s8*)((u8*)work+0x14)) = 1;
                }
            } else if (D_008C027A & 0x4000) {
                temp_17_8 = (*(s8*)((u8*)work+0x11));
                if (D_00748908[temp_17_8] < func_002e26f0((*(void**)((u8*)(((temp_17_8 * 4) + work))+0xF18)))) {
                    if (func_002e26f0((*(void**)((u8*)(((temp_17_8 * 4) + work))+0xF18))) > 0) {
                        if ((*(s16*)((u8*)work+0x2)) != ((s64) (temp_18 << 0x30) >> 0x30)) {
                            func_0045af60(0, 0, 0, 0);
                        }
                        temp_17_9 = (s64) (temp_18 << 0x30) >> 0x30;
                        (*(s16*)((u8*)work+0x2)) = func_002b2cb0((s32) (*(s16*)((u8*)work+0x2)), 1, (s32) temp_17_9, 0, 1);
                        if (temp_17_9 >= 5) {
                            (*(s16*)((u8*)work+0x4)) = func_002b2d50((s32) (*(s16*)((u8*)work+0x2)), (s32) (*(s16*)((u8*)work+0x4)), (s32) temp_18, 5, 1);
                        } else {
                            (*(s16*)((u8*)work+0x4)) = func_002b2d50((s32) (*(s16*)((u8*)work+0x2)), (s32) (*(s16*)((u8*)work+0x4)), (s32) temp_18, (s32) func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 1);
                        }
                        (*(s8*)((u8*)work+0x14)) = 1;
                    }
                }
            } else if ((D_008C027A & 2) || (D_008C027A & 0x2000)) {
                if (D_00748908[(*(s8*)((u8*)work+0x11))] < func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18)))) {
                    if ((*(s16*)((u8*)work+0x2)) != ((s64) (temp_18 << 0x30) >> 0x30)) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    func_002b2e70((s32) (*(s16*)((u8*)work+0x2)), (s32) (*(s16*)((u8*)work+0x4)), func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 5, (s16 *)(work + 2), (s16 *)(work + 4));
                    goto block_221;
                }
            } else if ((D_008C027A & 1) || (D_008C027A & 0x8000)) {
                temp_3_2 = (*(s8*)((u8*)work+0x11));
                temp_17_10 = D_00748908[temp_3_2];
                if (temp_17_10 < func_002e26f0((*(void**)((u8*)(((temp_3_2 * 4) + work))+0xF18)))) {
                    if ((*(s8*)((u8*)work+0xC24)) == 0) {
                        if ((*(s16*)((u8*)work+0x2)) != 0) {
                            func_0045af60(0, 0, 0, 0);
                        }
                        func_002b2f90((s32) (*(s16*)((u8*)work+0x2)), (s32) (*(s16*)((u8*)work+0x4)), func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))), 5, (s16 *)(work + 2), (s16 *)(work + 4));
                    } else {
                        if ((*(s16*)((u8*)work+0x2)) != temp_17_10) {
                            func_0045af60(0, 0, 0, 0);
                        }
                        temp_2_14 = (*(s8*)((u8*)work+0x11));
                        if (temp_2_14 == 0) {
                            func_002b3050((*(s16*)((u8*)work+0x2)), (*(s16*)((u8*)work+0x4)), func_002e26f0((*(void**)((u8*)(((temp_2_14 * 4) + work))+0xF18))), 5, 1, (s16 *)(work + 2), (s16 *)(work + 4));
                        } else {
                            func_002b2f90((s32) (*(s16*)((u8*)work+0x2)), (s32) (*(s16*)((u8*)work+0x4)), func_002e26f0((*(void**)((u8*)(((temp_2_14 * 4) + work))+0xF18))), 5, (s16 *)(work + 2), (s16 *)(work + 4));
                        }
                    }
                    goto block_221;
                }
            } else if (D_008C027A & 8) {
                if ((*(s8*)((u8*)work+0xC24)) != 1) {
                    var_5 = 0;
loop_137:
                    temp_3_3 = (s64) (var_5 << 0x30) >> 0x30;
                    if (temp_3_3 < 3) {
                        var_6 = 0;
loop_135:
                        if (((s64) (var_6 << 0x30) >> 0x30) < 5) {
                            temp_2_15 = work + (temp_3_3 * 0xA0) + (((s64) (var_6 << 0x30) >> 0x30) << 5);
                            (*(s16*)((u8*)temp_2_15+0xFA2)) = 0;
                            (*(s16*)((u8*)temp_2_15+0xFA0)) = 4;
                            (*(s16*)((u8*)temp_2_15+0xFA4)) = (s16) var_6;
                            var_6 = (s64) ((var_6 + 1) << 0x30) >> 0x30;
                            goto loop_135;
                        }
                        var_5 = (s64) ((var_5 + 1) << 0x30) >> 0x30;
                        goto loop_137;
                    }
                    (*(s8*)((u8*)(((*(s8*)((u8*)work+0x11)) + work))+0x1168)) = (s8) (*(s16*)((u8*)work+0x2));
                    (*(s8*)((u8*)(((*(s8*)((u8*)work+0x11)) + work))+0x116B)) = (s8) (*(s16*)((u8*)work+0x4));
                    (*(u8*)((u8*)work+0x116E)) = (s8) (*(s8*)((u8*)work+0x11));
                    if (func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) >= 5) {
                        (*(s16*)((u8*)work+0x1170)) = (s16) ((*(s16*)((u8*)((((*(s8*)((u8*)work+0x11)) * 0xA0) + work))+0x1020)) + 4);
                    } else {
                        temp_2_16 = (*(s8*)((u8*)work+0x11));
                        temp_17_11 = (*(s16*)((u8*)(((func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) << 5) + ((temp_2_16 * 0xA0) + work)))+0xFA0));
                        (*(s16*)((u8*)work+0x1170)) = (s16) (temp_17_11 + func_002e26f0((*(void**)((u8*)(((temp_2_16 * 4) + work))+0xF18))));
                    }
                    temp_2_17 = func_002b2cb0((s32) (*(s8*)((u8*)work+0x11)), 1, 2, 0, 2);
                    (*(s8*)((u8*)work+0x11)) = temp_2_17;
                    func_002d4760(arg0, (s64) ((s64) temp_2_17 << 0x38) >> 0x38);
                    func_002d7c10(arg0, (s16) (*(s8*)((u8*)work+0x11)));
                    (*(s16*)((u8*)work+0x2)) = 0;
                    (*(s16*)((u8*)work+0x4)) = 0;
                    (*(s8*)((u8*)(((*(s8*)((u8*)work+0x11)) + work))+0x1168)) = 0;
                    (*(s8*)((u8*)(((*(s8*)((u8*)work+0x11)) + work))+0x116B)) = 0;
                    if (func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) >= 5) {
                        (*(s16*)((u8*)work+0x1170)) = (s16) ((*(s16*)((u8*)((((*(s8*)((u8*)work+0x11)) * 0xA0) + work))+0x1020)) + 4);
                    } else {
                        temp_19_5 = (*(s8*)((u8*)work+0x11));
                        temp_18_3 = (*(s16*)((u8*)work+0x1170));
                        temp_17_12 = (*(s16*)((u8*)(((func_002e26f0((*(void**)((u8*)(((temp_19_5 * 4) + work))+0xF18))) << 5) + ((temp_19_5 * 0xA0) + work)))+0xFA0));
                        if (temp_18_3 < ((s64) ((temp_17_12 + func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18)))) << 0x30) >> 0x30)) {
                            temp_17_13 = (*(s16*)((u8*)(((func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) << 5) + (((*(s8*)((u8*)work+0x11)) * 0xA0) + work)))+0xFA0));
                            (*(s16*)((u8*)work+0x1170)) = (s16) (temp_17_13 + func_002e26f0((*(void**)((u8*)(((temp_19_5 * 4) + work))+0xF18))));
                        }
                    }
                    temp_3_4 = (*(s8*)((u8*)work+0x11));
                    switch (temp_3_4) {             /* switch 1; irregular */
                    case 0:                         /* switch 1 */
                        func_002e3560((*(void**)((u8*)(((temp_3_4 * 4) + work))+0xF18)), 0x40000, 0, 4, 0);
                        break;
                    case 1:                         /* switch 1 */
                        func_002e3560((*(void**)((u8*)(((temp_3_4 * 4) + work))+0xF18)), 0xFFFF, 0x1FE0, 1, 0);
                        break;
                    case 2:                         /* switch 1 */
                        func_002e3560((*(void**)((u8*)(((temp_3_4 * 4) + work))+0xF18)), 0x10000, 0, 1, 0);
                        break;
                    }
                    (*(u8*)((u8*)work+0x0)) = 0x33;
                    func_0045af60(0, 0, 0, 5);
                    goto block_221;
                }
            } else if (D_008C027A & 4) {
                if ((*(s8*)((u8*)work+0xC24)) != 1) {
                    var_5_2 = 0;
loop_160:
                    temp_3_5 = (s64) (var_5_2 << 0x30) >> 0x30;
                    if (temp_3_5 < 3) {
                        var_6_2 = 0;
loop_158:
                        if (((s64) (var_6_2 << 0x30) >> 0x30) < 5) {
                            temp_2_18 = work + (temp_3_5 * 0xA0) + (((s64) (var_6_2 << 0x30) >> 0x30) << 5);
                            (*(s16*)((u8*)temp_2_18+0xFA2)) = 0;
                            (*(s16*)((u8*)temp_2_18+0xFA0)) = 4;
                            (*(s16*)((u8*)temp_2_18+0xFA4)) = (s16) var_6_2;
                            var_6_2 = (s64) ((var_6_2 + 1) << 0x30) >> 0x30;
                            goto loop_158;
                        }
                        var_5_2 = (s64) ((var_5_2 + 1) << 0x30) >> 0x30;
                        goto loop_160;
                    }
                    (*(s8*)((u8*)(((*(s8*)((u8*)work+0x11)) + work))+0x1168)) = (s8) (*(s16*)((u8*)work+0x2));
                    (*(s8*)((u8*)(((*(s8*)((u8*)work+0x11)) + work))+0x116B)) = (s8) (*(s16*)((u8*)work+0x4));
                    (*(u8*)((u8*)work+0x116E)) = (s8) (*(s8*)((u8*)work+0x11));
                    if (func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) >= 5) {
                        (*(s16*)((u8*)work+0x1170)) = (s16) ((*(s16*)((u8*)((((*(s8*)((u8*)work+0x11)) * 0xA0) + work))+0x1020)) + 4);
                    } else {
                        temp_2_19 = (*(s8*)((u8*)work+0x11));
                        temp_17_14 = (*(s16*)((u8*)(((func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) << 5) + ((temp_2_19 * 0xA0) + work)))+0xFA0));
                        (*(s16*)((u8*)work+0x1170)) = (s16) (temp_17_14 + func_002e26f0((*(void**)((u8*)(((temp_2_19 * 4) + work))+0xF18))));
                    }
                    temp_2_20 = func_002b2d00((s32) (*(s8*)((u8*)work+0x11)), 1, 0, 2, 2);
                    (*(s8*)((u8*)work+0x11)) = temp_2_20;
                    func_002d4760(arg0, (s64) ((s64) temp_2_20 << 0x38) >> 0x38);
                    func_002d7c10(arg0, (s16) (*(s8*)((u8*)work+0x11)));
                    (*(s16*)((u8*)work+0x2)) = 0;
                    (*(s16*)((u8*)work+0x4)) = 0;
                    (*(s8*)((u8*)(((*(s8*)((u8*)work+0x11)) + work))+0x1168)) = 0;
                    (*(s8*)((u8*)(((*(s8*)((u8*)work+0x11)) + work))+0x116B)) = 0;
                    if (func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) >= 5) {
                        (*(s16*)((u8*)work+0x1170)) = (s16) ((*(s16*)((u8*)((((*(s8*)((u8*)work+0x11)) * 0xA0) + work))+0x1020)) + 4);
                    } else {
                        temp_19_6 = (*(s8*)((u8*)work+0x11));
                        temp_18_4 = (*(s16*)((u8*)work+0x1170));
                        temp_17_15 = (*(s16*)((u8*)(((func_002e26f0((*(void**)((u8*)(((temp_19_6 * 4) + work))+0xF18))) << 5) + ((temp_19_6 * 0xA0) + work)))+0xFA0));
                        if (temp_18_4 < ((s64) ((temp_17_15 + func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18)))) << 0x30) >> 0x30)) {
                            temp_17_16 = (*(s16*)((u8*)(((func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) << 5) + (((*(s8*)((u8*)work+0x11)) * 0xA0) + work)))+0xFA0));
                            (*(s16*)((u8*)work+0x1170)) = (s16) (temp_17_16 + func_002e26f0((*(void**)((u8*)(((temp_19_6 * 4) + work))+0xF18))));
                        }
                    }
                    temp_3_6 = (*(s8*)((u8*)work+0x11));
                    switch (temp_3_6) {             /* switch 2; irregular */
                    case 0:                         /* switch 2 */
                        func_002e3560((*(void**)((u8*)(((temp_3_6 * 4) + work))+0xF18)), 0x40000, 0, 4, 0);
                        break;
                    case 1:                         /* switch 2 */
                        func_002e3560((*(void**)((u8*)(((temp_3_6 * 4) + work))+0xF18)), 0xFFFF, 0x1FE0, 1, 0);
                        break;
                    case 2:                         /* switch 2 */
                        func_002e3560((*(void**)((u8*)(((temp_3_6 * 4) + work))+0xF18)), 0x10000, 0, 1, 0);
                        break;
                    }
                    (*(u8*)((u8*)work+0x0)) = 0x34;
                    func_0045af60(0, 0, 0, 5);
                    goto block_221;
                }
            } else {
                if (D_008C024E & 0x40) {
                    if (D_00748908[(*(s8*)((u8*)work+0x11))] >= func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18)))) {
                        func_0045af60(0, 0, 0, 8);
                        return;
                    }
                    (*(s16*)((u8*)work+0x12)) = 1;
                    temp_4_2 = (*(s8*)((u8*)work+0x11));
                    if ((temp_4_2 == 0) && (((*(s16*)((u8*)work+0x2)) - (*(s16*)((u8*)work+0x4))) == 0) && (func_002e26f0((*(void**)((u8*)(((temp_4_2 * 4) + work))+0xF18))) < 2)) {
                        func_0045af60(0, 0, 0, 8);
                        return;
                    }
                    if (func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18))) > 0) {
                        (*(u8*)((u8*)work+0xF3E)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDCC))))+0x79));
                        (*(u8*)((u8*)work+0xF3F)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDCC))))+0x7A));
                        (*(u8*)((u8*)work+0xF40)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDCC))))+0x7B));
                        (*(u8*)((u8*)work+0xF42)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDD0))))+0x79));
                        (*(u8*)((u8*)work+0xF43)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDD0))))+0x7A));
                        (*(u8*)((u8*)work+0xF44)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDD0))))+0x7B));
                        (*(s16*)((u8*)work+0xF3C)) = 0;
                        (*(u8*)((u8*)work+0x0)) = 0x25;
                        func_0045af60(0, 0, 0, 1);
                    }
                    goto block_221;
                }
                if (D_008C024E & 0x80) {
                    if ((D_00748908[(*(s8*)((u8*)work+0x11))] < func_002e26f0((*(void**)((u8*)((((*(s8*)((u8*)work+0x11)) * 4) + work))+0xF18)))) && (spD7 != 1)) {
                        if ((func_002e0570((*(void**)((u8*)work+0xE38)), 1) == 1) || (func_002e0570((*(void**)((u8*)work+0xCC4)), 1) == 1) || (func_002e0570((*(void**)((u8*)work+0xCC0)), 1) == 1)) {
                            return;
                        }
                        temp_4_3 = (*(s8*)((u8*)work+0x11));
                        if (((temp_4_3 != 0) || ((*(s16*)((u8*)work+0x2)) != 0)) && (func_002e26f0((*(void**)((u8*)(((temp_4_3 * 4) + work))+0xF18))) > 0)) {
                            (*(u8*)((u8*)work+0xF3E)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDCC))))+0x79));
                            (*(u8*)((u8*)work+0xF3F)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDCC))))+0x7A));
                            (*(u8*)((u8*)work+0xF40)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDCC))))+0x7B));
                            (*(u8*)((u8*)work+0xF42)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDD0))))+0x79));
                            (*(u8*)((u8*)work+0xF43)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDD0))))+0x7A));
                            (*(u8*)((u8*)work+0xF44)) = (u8) (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDD0))))+0x7B));
                            (*(s16*)((u8*)work+0xF3C)) = 0;
                            func_002e0700((*(void**)((u8*)work+0xEC4)), 3, 1.0f, 0.0f, 6, 0, 0);
                            func_002e0700((*(void**)((u8*)work+0xEC8)), 4, 1.0f, 0.0f, 6, 0, 0);
                            func_002e0700((*(void**)((u8*)work+0xE38)), 0x80, 1.0f, 0.0f, 6, 0, 0);
                            func_002e0700((*(void**)((u8*)work+0xEB4)), 3, 1.0f, 0.0f, 6, 1, 0);
                            func_002e0700((*(void**)((u8*)work+0xEB8)), 4, 1.0f, 0.0f, 6, 1, 0);
                            func_002e0700((*(void**)((u8*)work+0xCC4)), 0x23, 1.0f, 0.0f, 6, 1, 0);
                            func_002e0700((*(void**)((u8*)work+0xEBC)), 3, 1.0f, 0.0f, 6, 2, 0);
                            func_002e0700((*(void**)((u8*)work+0xEC0)), 4, 1.0f, 0.0f, 6, 2, 0);
                            func_002e0700((*(void**)((u8*)work+0xCC0)), 0x22, 1.0f, 0.0f, 6, 1, 0);
                            func_002e04f0((*(void**)((u8*)work+0xDDC)), 0, 1);
                            func_002e04f0((*(void**)((u8*)work+0xDE4)), 0, 1);
                            func_002e04f0((*(void**)((u8*)work+0xDE0)), 0, 0);
                            (*(u8*)((u8*)work+0x0)) = 0x2F;
                            func_0045af60(0, 1, 0, 3);
                        }
                        goto block_221;
                    }
                } else if (D_008C024E & 0x20) {
                    if (spD7 != 1) {
                        func_0045af60(0, 0, 0, 2);
                        func_002b2970(&sp180, D_0063F5B8[0], D_0063F5B8[1]);
                        func_002b2970(&sp178, D_0063F5B8[0], 300.0f + D_0063F5B8[1]);
                        func_002e0620((*(void**)((u8*)work+0xC64)), sp180, sp178, 0, 0xA, 0);
                        func_002e0660((*(void**)((u8*)work+0xC64)), (*(u8*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC64))))+0x62)), 0U, 0U, 0xA, 0);
                        func_002e09e0((*(void**)((u8*)work+0xD74)), 0x56, 11.0f);
                        func_002e0660((*(void**)((u8*)work+0xD74)), 0xFFU, 0U, 0U, 0xA, 0);
                        func_002e09e0((*(void**)((u8*)work+0xD80)), 0x56, 9.0f);
                        func_002e0660((*(void**)((u8*)work+0xD80)), 0xFFU, 0U, 0U, 0xA, 0);
                        var_19_4 = 0x43;
loop_200:
                        if (((s64) (var_19_4 << 0x30) >> 0x30) < 0x49) {
                            temp_2_21 = work + (((s64) (var_19_4 << 0x30) >> 0x30) * 4);
                            temp_21 = func_002e04e0((*(void**)((u8*)temp_2_21+0xC38)));
                            func_002b2970(&sp170, (*(f32*)((u8*)temp_21+0x2C)), (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)temp_2_21+0xC38))))+0x30)));
                            temp_21_2 = func_002e04e0((*(void**)((u8*)temp_2_21+0xC38)));
                            func_002b2970(&sp168, (*(f32*)((u8*)temp_21_2+0x2C)), 170.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)temp_2_21+0xC38))))+0x30)));
                            func_002e0620((*(void**)((u8*)temp_2_21+0xC38)), sp170, sp168, 1, 5, 0);
                            var_19_4 = (s64) ((var_19_4 + 1) << 0x30) >> 0x30;
                            goto loop_200;
                        }
                        func_002e0660((*(void**)((u8*)work+0xC8C)), 0xFFU, 0U, 0U, 6, 0);
                        func_002e0660((*(void**)((u8*)work+0xC90)), 0xFFU, 0U, 0U, 6, 0);
                        var_17 = 0;
loop_203:
                        temp_3_7 = (s64) (var_17 << 0x30) >> 0x30;
                        if (temp_3_7 < 3) {
                            func_002e04f0((*(void**)((u8*)((work + (temp_3_7 * 4)))+0xE40)), 0, 1);
                            var_17 = (s64) ((var_17 + 1) << 0x30) >> 0x30;
                            goto loop_203;
                        }
                        func_002e04f0((*(void**)((u8*)work+0xDCC)), 0, 1);
                        func_002e04f0((*(void**)((u8*)work+0xDD0)), 0, 1);
                        func_002e04e0((*(void**)((u8*)work+0xEC4)));
                        temp_17_17 = func_002e04e0((*(void**)((u8*)work+0xEC4)));
                        func_002b2970(&sp160, (*(f32*)((u8*)temp_17_17+0x2C)), 500.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xEC4))))+0x30)));
                        func_002e0620((*(void**)((u8*)work+0xEC4)), (*(u64*)((u8*)temp_17_17+0x2C)), sp160, 2, 0xF, 0);
                        func_002e04e0((*(void**)((u8*)work+0xEC8)));
                        temp_17_18 = func_002e04e0((*(void**)((u8*)work+0xEC8)));
                        func_002b2970(&sp158, (*(f32*)((u8*)temp_17_18+0x2C)), 500.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xEC8))))+0x30)));
                        func_002e0620((*(void**)((u8*)work+0xEC8)), (*(u64*)((u8*)temp_17_18+0x2C)), sp158, 2, 0xF, 0);
                        func_002e04e0((*(void**)((u8*)work+0xE38)));
                        temp_17_19 = func_002e04e0((*(void**)((u8*)work+0xE38)));
                        func_002b2970(&sp150, (*(f32*)((u8*)temp_17_19+0x2C)), 500.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xE38))))+0x30)));
                        func_002e0620((*(void**)((u8*)work+0xE38)), (*(u64*)((u8*)temp_17_19+0x2C)), sp150, 2, 0xF, 0);
                        func_002e04e0((*(void**)((u8*)work+0xEB4)));
                        temp_17_20 = func_002e04e0((*(void**)((u8*)work+0xEB4)));
                        func_002b2970(&sp148, (*(f32*)((u8*)temp_17_20+0x2C)), 500.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xEB4))))+0x30)));
                        func_002e0620((*(void**)((u8*)work+0xEB4)), (*(u64*)((u8*)temp_17_20+0x2C)), sp148, 2, 0xF, 1);
                        func_002e04e0((*(void**)((u8*)work+0xEB8)));
                        temp_17_21 = func_002e04e0((*(void**)((u8*)work+0xEB8)));
                        func_002b2970(&sp140, (*(f32*)((u8*)temp_17_21+0x2C)), 500.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xEB8))))+0x30)));
                        func_002e0620((*(void**)((u8*)work+0xEB8)), (*(u64*)((u8*)temp_17_21+0x2C)), sp140, 2, 0xF, 1);
                        func_002e04e0((*(void**)((u8*)work+0xCC4)));
                        temp_17_22 = func_002e04e0((*(void**)((u8*)work+0xCC4)));
                        func_002b2970(&sp138, (*(f32*)((u8*)temp_17_22+0x2C)), 500.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xCC4))))+0x30)));
                        func_002e0620((*(void**)((u8*)work+0xCC4)), (*(u64*)((u8*)temp_17_22+0x2C)), sp138, 2, 0xF, 1);
                        func_002e04e0((*(void**)((u8*)work+0xEBC)));
                        temp_17_23 = func_002e04e0((*(void**)((u8*)work+0xEBC)));
                        func_002b2970(&sp130, (*(f32*)((u8*)temp_17_23+0x2C)), 500.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xEBC))))+0x30)));
                        func_002e0620((*(void**)((u8*)work+0xEBC)), (*(u64*)((u8*)temp_17_23+0x2C)), sp130, 2, 0xF, 2);
                        func_002e04e0((*(void**)((u8*)work+0xEC0)));
                        temp_17_24 = func_002e04e0((*(void**)((u8*)work+0xEC0)));
                        func_002b2970(&sp128, (*(f32*)((u8*)temp_17_24+0x2C)), 500.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xEC0))))+0x30)));
                        func_002e0620((*(void**)((u8*)work+0xEC0)), (*(u64*)((u8*)temp_17_24+0x2C)), sp128, 2, 0xF, 2);
                        func_002e04e0((*(void**)((u8*)work+0xCC0)));
                        temp_17_25 = func_002e04e0((*(void**)((u8*)work+0xCC0)));
                        func_002b2970(&sp120, (*(f32*)((u8*)temp_17_25+0x2C)), 500.0f + (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xCC0))))+0x30)));
                        func_002e0620((*(void**)((u8*)work+0xCC0)), (*(u64*)((u8*)temp_17_25+0x2C)), sp120, 2, 0xF, 2);
                        var_17_2 = 0x8C;
loop_208:
                        temp_3_8 = (s64) (var_17_2 << 0x30) >> 0x30;
                        if (temp_3_8 < 0x8F) {
                            temp_2_22 = work + (temp_3_8 * 4);
                            if (func_002e0570((*(void**)((u8*)temp_2_22+0xC38)), 0) == 1) {
                                func_002e04f0((*(void**)((u8*)temp_2_22+0xC38)), 0, 1);
                            }
                            var_17_2 = (s64) ((var_17_2 + 1) << 0x30) >> 0x30;
                            goto loop_208;
                        }
                        var_17_3 = 0;
loop_211:
                        temp_3_9 = (s64) (var_17_3 << 0x30) >> 0x30;
                        if (temp_3_9 < 3) {
                            func_002e0660((*(void**)((u8*)((work + (temp_3_9 * 4)))+0xC38)), 0U, 0xFFU, 0U, 0xA, 0);
                            var_17_3 = (s64) ((var_17_3 + 1) << 0x30) >> 0x30;
                            goto loop_211;
                        }
                        var_19_5 = 0;
loop_216:
                        if (var_19_5 < 7) {
                            temp_18_5 = var_19_5;
                            temp_17_26 = D_0063F560 + ((temp_18_5 + 0x3A) * 8);
                            temp_3_10 = work + (temp_18_5 * 4);
                            func_002e09e0((*(void**)((u8*)temp_3_10+0xD20)), 0x56, (f32) (temp_18_5 + 0x64));
                            if (temp_18_5 > 0) {
                                func_002b2a60(&sp1EC, 0xED, 0x80, 0, 0xFF);
                                temp_2_23 = func_002e04e0((*(void**)((u8*)temp_3_10+0xD20)));
                                (*(u8*)((u8*)temp_2_23+0x79)) = sp1EC;
                                (*(u8*)((u8*)temp_2_23+0x7A)) = sp1ED;
                                (*(u8*)((u8*)temp_2_23+0x7B)) = sp1EE;
                                (*(u8*)((u8*)temp_2_23+0x7C)) = sp1EF;
                            }
                            temp_2_24 = temp_3_10;
                            func_002b2970(&sp118, 80.0f + (*(u8*)((u8*)temp_17_26+0x0)), (*(s16*)((u8*)temp_17_26+0x4)));
                            func_002b2970(&sp110, (*(u8*)((u8*)temp_17_26+0x0)), (*(s16*)((u8*)temp_17_26+0x4)));
                            func_002e0620((*(void**)((u8*)temp_2_24+0xD20)), sp118, sp110, 0, 3, (s16) var_19_5);
                            func_002e0660((*(void**)((u8*)temp_2_24+0xD20)), 0U, 0xFFU, 0U, 3, var_19_5);
                            var_19_5 = var_19_5 + 1;
                            goto loop_216;
                        }
                        func_002b2a60(&sp1E8, 0x2D, 0x2D, 0x2D, 0xFF);
                        temp_2_25 = func_002e04e0((*(void**)((u8*)((((*(s8*)((u8*)work+0x7)) * 4) + work))+0xD24)));
                        (*(u8*)((u8*)temp_2_25+0x79)) = sp1E8;
                        (*(u8*)((u8*)temp_2_25+0x7A)) = sp1E9;
                        (*(u8*)((u8*)temp_2_25+0x7B)) = sp1EA;
                        (*(u8*)((u8*)temp_2_25+0x7C)) = sp1EB;
                        func_002e0660((*(void**)((u8*)work+0xC44)), 0U, 0xFFU, 0U, 0, (s64) (*(s8*)((u8*)work+0x7)));
                        func_002e0660((*(void**)((u8*)work+0xC48)), 0U, 0xFFU, 0U, 0, (s64) (*(s8*)((u8*)work+0x7)));
                        var_17_4 = 0;
loop_219:
                        temp_3_11 = (s64) (var_17_4 << 0x30) >> 0x30;
                        if (temp_3_11 < 3) {
                            func_002e0660((*(void**)((u8*)((work + (temp_3_11 * 4)))+0xC38)), 0U, 0xFFU, 0U, 0xA, 0);
                            var_17_4 = (s64) ((var_17_4 + 1) << 0x30) >> 0x30;
                            goto loop_219;
                        }
                        func_002e09e0((*(void**)((u8*)work+0xDE8)), 0x41, 46.0f);
                        func_002e0660((*(void**)((u8*)work+0xDE8)), 0U, 0xFFU, 0U, 6, 0);
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDE8))))+0x2C)) = 198.0f;
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDE8))))+0x30)) = (f32) 0x151;
                        func_002e09e0((*(void**)((u8*)work+0xDEC)), 0x41, 146.0f);
                        func_002e0660((*(void**)((u8*)work+0xDEC)), 0U, 0xFFU, 0U, 6, 0);
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDEC))))+0x2C)) = 216.0f;
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDEC))))+0x30)) = 368.0f;
                        func_002e09e0((*(void**)((u8*)work+0xDDC)), 0x41, 49.0f);
                        func_002e0660((*(void**)((u8*)work+0xDDC)), 0xFFU, 0U, 0U, 0xA, 0);
                        func_002e09e0((*(void**)((u8*)work+0xDF0)), 0x41, 47.0f);
                        func_002e0660((*(void**)((u8*)work+0xDF0)), 0xFFU, 0U, 0U, 0xA, 0);
                        func_002b2970(&sp108, (f32) 0x103, 404.0f);
                        func_002b2970(&sp100, (f32) 0x103, 404.0f);
                        func_002e0620((*(void**)((u8*)work+0xDF0)), sp108, sp100, 0, 0, 0);
                        func_002e09e0((*(void**)((u8*)work+0xDE4)), 0x41, 47.0f);
                        func_002e0660((*(void**)((u8*)work+0xDE4)), 0xFFU, 0U, 0U, 0xA, 0);
                        func_002b2970(&spF8, 338.0f, 404.0f);
                        func_002b2970(&spF0, 338.0f, 404.0f);
                        func_002e0620((*(void**)((u8*)work+0xDE4)), spF8, spF0, 0, 0, 0);
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDE8))))+0x2C)) = 198.0f;
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xDE8))))+0x30)) = (f32) 0x151;
                        func_002e09e0((*(void**)((u8*)work+0xC4C)), 0x40, 191.0f);
                        temp_2_26 = func_0046d200((*(void**)((u8*)work+0xF28)), 5);

                        (*(s16*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC4C))))+0x100)) = (s16)func_0046b260(temp_2_26);

                        (*(s16*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC4C))))+0x102)) = (s16)func_0046b2f0(temp_2_26);
                        func_0046d280(temp_2_26);
                        func_002e0660((*(void**)((u8*)work+0xC4C)), 0U, 0xCCU, 0U, 4, 4);
                        func_002e0940((*(void**)((u8*)work+0xC4C)), 0.0f, 0.0f, 0, 4, 4);
                        func_002b2970(&spE8, -240.0f, 400.0f);
                        func_002b2970(&spE0, -240.0f, 310.0f);
                        func_002e0620((*(void**)((u8*)work+0xC4C)), spE8, spE0, 0, 4, 4);
                        func_002e09e0((*(void**)((u8*)work+0xC50)), 0x40, 192.0f);
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC50))))+0x2C)) = 110.0f;
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC50))))+0x30)) = -50.0f;
                        temp_2_27 = func_0046d200((*(void**)((u8*)work+0xF28)), 6);

                        (*(s16*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC50))))+0x100)) = (s16)func_0046b260(temp_2_27);
                        (*(s16*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xC50))))+0x102)) = 0;
                        func_002e0940((*(void**)((u8*)work+0xC50)), -90.0f, 0.0f, 0, 4, 4);
                        func_002e0660((*(void**)((u8*)work+0xC50)), 0U, 0xFFU, 0U, 4, 4);
                        func_0046d280(temp_2_27);
                        func_002e09e0((*(void**)((u8*)work+0xE7C)), 0x40, 190.0f);
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xE7C))))+0x2C)) = 180.0f;
                        (*(f32*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xE7C))))+0x30)) = 30.0f;
                        temp_2_28 = func_0046d200((*(void**)((u8*)work+0xF28)), 6);

                        (*(s16*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xE7C))))+0x100)) = (s16)func_0046b260(temp_2_28);
                        (*(s16*)((u8*)(func_002e04e0((*(void**)((u8*)work+0xE7C))))+0x102)) = 0;
                        func_0046d280(temp_2_28);
                        func_002e0940((*(void**)((u8*)work+0xE7C)), -85.0f, 0.0f, 0, 4, 2);
                        func_002e0660((*(void**)((u8*)work+0xE7C)), 0U, 0xFFU, 0U, 4, 2);
                        func_002dd230(arg0);
                        (*(u8*)((u8*)work+0x0)) = 0x11;
                        goto block_221;
                    }
                } else {
                    goto block_221;
                }
            }
        }
    } else {
block_221:
        (*(s8*)((u8*)work+0x14)) = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002cdf80);
#endif

/* measured: full m2c draft adapted and compiles (rule 2 at the FMA site
   0x1D2C58: 264.0f + work[0xC] * (f32)field_2 with madd fs/ft order
   preserved, f12 = D_0063F620[0] - 1.0f; four 75680 calls reordered to the
   (f32,f32,f32,...) prototype; 0080 Vec2f-by-value arg; func_002e2670 0-arg);
   nd 2637. Residual: D_0063F620/F660/F628/F630/F638/F640/F648/F668 base
   hoists per group, 26f0-width extension split, and 754f0/2a60 phantom-arg
   and arg-order scrambling. Hoist + width floor. */
/* measured: retail 2644 instrs / object 2649 instrs (+0.2%, gate 2565-2723, mid-band), */
/* fnalign 2201 edits +38 reloc-only, max delete-hole 3; production stays ASM. */
/* measured 002d1590 (owner, dedup 4 recomputations): 2621 against retail 2644
   (-0.9%, gate 2565-2723 PASS), 2141 edits (+38 reloc-only), 2194 differing words.
   regsave_scan clean (no callee-saved mismatch). Removed the second cA/uA pair
   in each of the four work[7] diff blocks (06940/06970/068b0/068e0): the fnalign
   script's asymmetric runs (293-vs-2, 446-vs-1 etc.) are difflib confusion over
   the repeated 0b20/cacd0 chains, but the 30-instr delete at retail[1505:1535]
   plus the four duplicated jal pairs are real; dropping the 8 redundant calls
   saves 28 instr and 60 edits (-5 words) with the count still in band. */
/* measured 002d1590 (owner, 2026-09-19): fnalign **2141 -> 2140 edits**, count
   2621 -> 2619 against retail 2642, by turning one constant-bound `for` loop into
   the `do { } while` retail emits.  A `for (i = <const>; i < <const>; i++)` compiles
   with a guard before the first iteration; retail has none, because the loop provably
   runs at least once and the original source said so.
   This is the same lever as the `loop_N:` goto sweep but reaches ordinary `for` loops,
   which that sweep could not see.  Across the 40 floors with the most constant-bound
   loops, 21 improved and 19 had no loop that helped - and only ONE loop per function
   was ever the right one, so each loop is measured separately rather than converting
   them all. */
/* measured 002d1590 (owner, 2026-09-19, structural round): baseline KEPT at fnalign */
/*   2140 edits, object 2619 against retail 2642 (-0.9% INSIDE the +-3% band). */
/*   tail_classify: 185 structure + 98 register hunks, STRUCTURE flag. table_order: N/A */
/*   (retail asm has no jtbl and source has no switch; both work+7 dispatches check 2,1,0 */
/*   in that order in retail and source, so layout already matches). */
/*   Width COUNT bisect, uniform s32/s64 over 24 integer locals in declaration order */
/*   (sp230..diff, first N wide): N0 2179/2597, N2 2062, N4 2062, N5 2042/2597 BEST (-98), */
/*   N6 2053, N7 2684 SPIKE, N8 2683, N9 2062, N10 2360, N15 2822/2644 exact count but */
/*   worst edits, N24 2900/2696. N7/N8 spike then N9 recovery proves the declarations are */
/*   not independent (same lesson as sibling 002be530). Best uniform N5 widens the u16/s16 */
/*   counters retail narrows (dsll32/dsra32 at 78:80,152:154; func_002e2740 truly returns s16 */
/*   per MATCHed code1_002e/y_list, so the (s16) casts are correctly no-ops) and shrinks the */
/*   frame to 0x250 (baseline 0x270 is closest to retail 0x2b0), so NOT adopted. */
/*   Copy spellings, micro-proved: RGBA field copies -> interleaved lbu/sb (object), struct */
/*   assign via pointers -> batched (retail) but via stack locals -> single lwc1 (neither */
/*   matches, so the c2AC site is left as-is); Vec2f struct assign (stack) -> ld/sd (object) */
/*   vs field assign -> lwc1 pair (retail) in isolation, but singles (sp130 2291, spF8 2238, */
/*   spE0 2194, sp128 2286, every one worse than 2140) vs all-8 field assigns 2043/2611 (-97) */
/*   with frame 0x240 and 2 float saves against retail 0 shows allocator coupling, not a */
/*   clean local win, so NOT adopted. Pointer decl-order probes (3 perms) neutral at 2140. */
/*   Next structural root is the $s0/$s2 assignment (retail $s2=arg0/$s0=work, object swapped, */
/*   98 register hunks cascade) plus the 0x40 frame gap - not individual copies or widths. */
// FUN_002D1590 NONMATCHING
#ifdef NON_MATCHING
s32 func_002d1590(void *arg0)
{
    extern s16 func_002e2740(s32 arg0);
    extern s64 func_00106b80(s32 arg0);
    extern f32 D_0063F620[];
    extern f32 D_0063F628[];
    extern f32 D_0063F630[];
    extern f32 D_0063F638[];
    extern f32 D_0063F640[];
    extern f32 D_0063F648[];
    extern f32 D_0063F660[];
    extern f32 D_0063F668[];
    extern f32 D_0063F9B0[];
    extern u8 D_0063FAA0[];
    u8 *work;
    Vec2f *b;
    u8 *p;
    u8 *q;
    Vec2f sp238;
    u64 sp230;
    Vec2f sp228;
    Vec2f sp220;
    Vec2f sp218;
    Vec2f sp210;
    Vec2f sp208;
    Vec2f sp200;
    Vec2f sp1F8;
    Vec2f sp1F0;
    Vec2f sp1E8;
    Vec2f sp1E0;
    Vec2f sp1D8;
    Vec2f sp1D0;
    Vec2f sp1C8;
    Vec2f sp1C0;
    Vec2f sp1B8;
    u64 sp1B0;
    Vec2f sp1A8;
    Vec2f sp1A0;
    Vec2f sp198;
    Vec2f sp190;
    Vec2f sp188;
    Vec2f sp180;
    Vec2f sp178;
    Vec2f sp170;
    Vec2f sp168;
    Vec2f sp160;
    Vec2f sp158;
    Vec2f sp150;
    Vec2f sp148;
    Vec2f sp140;
    Vec2f sp138;
    Vec2f sp130;
    Vec2f sp128;
    Vec2f sp120;
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    Vec2f spC0b;
    Vec2f spC8b;
    Vec2f spD0b;
    Vec2f spD8b;
    RGBA c2A8;
    RGBA c2AC;
    RGBA c2A4;
    RGBA cA6;
    RGBA cFE;
    RGBA cFE2;
    RGBA cFF;
    RGBA cFE3;
    RGBA cE7;
    RGBA cB0;
    RGBA c2D;
    s32 colA;
    s32 colB;
    s32 colC;
    s32 tmp;
    s32 tmp2;
    s32 h0;
    s32 cA;
    s32 c16;
    u16 uA;
    u16 uB;
    s16 i;
    s16 j;
    s16 k;
    s32 diff;
    f32 fdiv;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    func_002b2a60(&c2A8, 0x2D, 0x2D, 0x2D, 0xFF);
    c2AC.r = c2A8.r;
    c2AC.g = c2A8.g;
    c2AC.b = c2A8.b;
    c2AC.a = c2A8.a;
    colA = func_002b2a30(0, 0x2D, 0x2D, 0x2D);
    colB = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&sp238, 51.0f, 48.0f);
    func_002e0080(arg0, *(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), sp238, (void *)func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
    func_002b2970((Vec2f *)&sp230, 590.0f, 61.0f);
    func_002b2a60(&c2A4, 0xFF, 0xFF, 0xFF, 0xFF);
    tmp = func_00106a90((s16)func_002e2740(*(s16 *)(work + 2)));
    h0 = (s32)func_0046a770(D_0063FAA0);
    func_002cacd0(sp230, 1.0f, c2A4, 0x11, 5, (u32)tmp, 0x70, 0x7A, h0, (s32)func_0046a770(D_0063FAA0), 0xAA);
    if ((s8)func_002e05a0(*(void **)(work + 0xC60)) == 0 &&
        (s8)func_002e05a0(*(void **)(work + 0xC80)) == 0 &&
        (s8)func_002e05a0(*(void **)(work + 0xC70)) == 0 &&
        (s8)func_002e05a0(*(void **)(work + 0xC84)) == 0 &&
        (s8)func_002e05a0(*(void **)(work + 0xC74)) == 0 &&
        (s8)func_002e05a0(*(void **)(work + 0xC78)) == 0) {
        tmp = func_00106a90((s16)func_002e2740(*(s16 *)(work + 2)));
        if ((u32)func_002e7a60() < (u32)tmp) {
            goto LAB1898_skip;
        }
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        tmp2 = func_00106600((s16)cA);
        if ((tmp2 & 0xFF) != 0x63) {
            goto LAB1898_skip;
        }
        colA = func_002b2a30(0, 0xA6, 0x7F, 0x2B);
        func_002b2a60(&cA6, 0xA6, 0x7F, 0x2B, 0xFF);
        colB = func_002b2a30(0xA6, 0x7F, 0x2B, 0xFF);
LAB1898_skip:
        func_002b2970(&sp228, 129.0f, 255.0f);
        sp130 = sp228;
        func_00275680(sp130.x, sp130.y, 70.0f, colB, 0, 1, (const char *)func_001067f0((s16)func_002e2740(*(s16 *)(work + 2))), 0, 0, D_00794ED0, -1);
        if ((func_001069d0((s64)(s16)func_002e2740(*(s16 *)(work + 2))) & 0xFFFF) == 0) {
            for (i = 0; i < 0xF; i++) {
                func_002b2970(&sp220, (f32)(i * 0x16 + 0x6F), 299.0f);
                colC = func_002b2a30(0xFF, 0xFF, 0xC7, 0x31);
                func_002e0b20(0x3C, sp220, 86.0f, colC, 0xFF, 0, D_00794ED0);
            }
        } else {
            uA = func_001069d0((s64)(s16)func_002e2740(*(s16 *)(work + 2)));
            colC = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
            func_002bc7f0(uA, colC, 1, 0, 3, 0x57, 109.0f, 290.0f, 70.0f);
        }
        if (*(s8 *)(work + 7) == 2) {
            tmp = (s16)func_00106b80((s16)func_002e2740(*(s16 *)(work + 2)));
            colC = func_002b2a30(0xDF, 0x6C, 0, 0xFF);
            func_002bc7f0(tmp, colC, 1, 0, 2, 0x57, 109.0f, 324.0f, 70.0f);
            func_002b2970(&sp1E8, 86.0f, 256.0f);
            func_002e0b20(0x1C, sp1E8, 69.0f, colA, 0xFF, 0, D_00794ED0);
            func_002e09e0(*(void **)(work + 0xCB8), 0x57, 84.0f);
            ((u8 *)func_002e04e0(*(void **)(work + 0xCB8)))[0x62] = 0x7F;
            b = (Vec2f *)D_0063F660;
            func_002b2970(&sp1E0, b->x, b->y);
            p = func_002e04e0(*(void **)(work + 0xCB8));
            *(Vec2f *)(p + 0x2C) = sp1E0;
            func_002e09e0(*(void **)(work + 0xEAC), 0x57, 84.0f);
            ((u8 *)func_002e04e0(*(void **)(work + 0xEAC)))[0x62] = 0x7F;
            b = (Vec2f *)D_0063F660;
            func_002b2970(&sp1D8, b->x, b->y + 50.0f);
            p = func_002e04e0(*(void **)(work + 0xEAC));
            *(Vec2f *)(p + 0x2C) = sp1D8;
        } else if (*(s8 *)(work + 7) == 1) {
            tmp = (s16)func_00106b80((s16)func_002e2740(*(s16 *)(work + 2)));
            colC = func_002b2a30(0xDF, 0x6C, 0, 0xFF);
            func_002bc7f0(tmp, colC, 1, 0, 1, 0x57, 109.0f, 324.0f, 70.0f);
            func_002b2970(&sp200, 86.0f, 256.0f);
            func_002e0b20(0x1B, sp200, 69.0f, colA, 0xFF, 0, D_00794ED0);
            func_002e09e0(*(void **)(work + 0xC9C), 0x57, 81.0f);
            func_002b2a60(&cFE, 0xFE, 0xEF, 0x80, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xC9C));
            *(RGBA *)(p + 0x79) = cFE;
            func_002e09e0(*(void **)(work + 0xCA4), 0x57, 80.0f);
            func_002b2a60(&cFE2, 0xFE, 0xEF, 0x80, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xCA4));
            *(RGBA *)(p + 0x79) = cFE2;
            func_002b2970(&sp1F8, 518.0f, 324.0f);
            spF8 = sp1F8;
            cA = (s16)func_002e2740(*(s16 *)(work + 2));
            uA = func_00106940(cA);
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
            uB = func_00106940((s16)c16);
            diff = (s32)(u16)uA - (s32)(u16)uB;
            if (diff < 0) {
                func_002b2970(&spF0, spF8.x + 12.0f, spF8.y - 18.0f);
                colC = func_002b2a30(0, 0x67, 0x67, 0x67);
                func_002e0b20(0x29, spF0, 23.0f, colC, 0xFF, 0, D_00795E60);
            } else if (diff > 0) {
                func_002b2970(&spE8, spF8.x + 12.0f, spF8.y - 18.0f);
                colC = func_002b2a30(0, 0xFA, 0x22, 0x3A);
                func_002e0b20(0x28, spE8, 23.0f, colC, 0xFF, 0, D_00795E60);
            }
            tmp = func_002b3170(uA);
            func_002b2970((Vec2f *)&spA0, spF8.x + (f32)((s16)(tmp - 1) * 8), spF8.y);
            func_002b2a60(&c2D, 0x2D, 0x2D, 0x2D, 0xFF);
            h0 = (s32)func_0046a770(D_0063FB50);
            func_002cacd0(spA0, 22.0f, c2D, 0xF, 0, uA, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
            func_002b2970(&sp1F0, 518.0f, 374.0f);
            spE0 = sp1F0;
            cA = (s16)func_002e2740(*(s16 *)(work + 2));
            uA = func_00106970(cA);
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
            uB = func_00106970((s16)c16);
            diff = (s32)(u16)uA - (s32)(u16)uB;
            if (diff < 0) {
                func_002b2970(&spD8, spE0.x + 12.0f, spE0.y - 18.0f);
                colC = func_002b2a30(0, 0x67, 0x67, 0x67);
                func_002e0b20(0x29, spD8, 23.0f, colC, 0xFF, 0, D_00795E60);
            } else if (diff > 0) {
                func_002b2970(&spD0, spE0.x + 12.0f, spE0.y - 18.0f);
                colC = func_002b2a30(0, 0xFA, 0x22, 0x3A);
                func_002e0b20(0x28, spD0, 23.0f, colC, 0xFF, 0, D_00795E60);
            }
            tmp = func_002b3170(uA);
            func_002b2970((Vec2f *)&sp98, spE0.x + (f32)((s16)(tmp - 1) * 8), spE0.y);
            func_002b2a60(&c2D, 0x2D, 0x2D, 0x2D, 0xFF);
            h0 = (s32)func_0046a770(D_0063FB50);
            func_002cacd0(sp98, 22.0f, c2D, 0xF, 0, uA, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        } else if (*(s8 *)(work + 7) == 0) {
            tmp = (s16)func_00106b80((s16)func_002e2740(*(s16 *)(work + 2)));
            colC = func_002b2a30(0xDF, 0x6C, 0, 0xFF);
            func_002bc7f0(tmp, colC, 1, 0, 0, 0x57, 109.0f, 324.0f, 70.0f);
            func_002b2970(&sp218, 86.0f, 256.0f);
            func_002e0b20(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), sp218, 69.0f, colA, 0xFF, 0, D_00794ED0);
            func_002e09e0(*(void **)(work + 0xCA0), 0x57, 83.0f);
            func_002b2a60(&cFE, 0xFE, 0xEF, 0x80, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xCA0));
            *(RGBA *)(p + 0x79) = cFE;
            func_002e09e0(*(void **)(work + 0xCA8), 0x57, 82.0f);
            func_002b2a60(&cFE2, 0xFE, 0xEF, 0x80, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xCA8));
            *(RGBA *)(p + 0x79) = cFE2;
            func_002b2970(&sp210, 518.0f, 324.0f);
            sp128 = sp210;
            cA = (s16)func_002e2740(*(s16 *)(work + 2));
            uA = func_001068b0(cA);
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
            uB = func_001068b0((s16)c16);
            diff = (s32)(u16)uA - (s32)(u16)uB;
            if (diff < 0) {
                func_002b2970(&sp120, sp128.x + 12.0f, sp128.y - 18.0f);
                colC = func_002b2a30(0, 0x67, 0x67, 0x67);
                func_002e0b20(0x29, sp120, 23.0f, colC, 0xFF, 0, D_00795E60);
            } else if (diff > 0) {
                func_002b2970(&sp118, sp128.x + 12.0f, sp128.y - 18.0f);
                colC = func_002b2a30(0, 0xFA, 0x22, 0x3A);
                func_002e0b20(0x28, sp118, 23.0f, colC, 0xFF, 0, D_00795E60);
            }
            tmp = func_002b3170(uA);
            func_002b2970((Vec2f *)&spB0, sp128.x + (f32)((s16)(tmp - 1) * 8), sp128.y);
            func_002b2a60(&c2D, 0x2D, 0x2D, 0x2D, 0xFF);
            h0 = (s32)func_0046a770(D_0063FB50);
            func_002cacd0(spB0, 22.0f, c2D, 0xF, 0, uA, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
            func_002b2970(&sp208, 518.0f, 374.0f);
            sp110 = sp208;
            cA = (s16)func_002e2740(*(s16 *)(work + 2));
            uA = func_001068e0(cA);
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
            uB = func_001068e0((s16)c16);
            diff = (s32)(u16)uA - (s32)(u16)uB;
            if (diff < 0) {
                func_002b2970(&sp108, sp110.x + 12.0f, sp110.y - 18.0f);
                colC = func_002b2a30(0, 0x67, 0x67, 0x67);
                func_002e0b20(0x29, sp108, 23.0f, colC, 0xFF, 0, D_00795E60);
            } else if (diff > 0) {
                func_002b2970(&sp100, sp110.x + 12.0f, sp110.y - 18.0f);
                colC = func_002b2a30(0, 0xFA, 0x22, 0x3A);
                func_002e0b20(0x28, sp100, 23.0f, colC, 0xFF, 0, D_00795E60);
            }
            tmp = func_002b3170(uA);
            func_002b2970((Vec2f *)&spA8, sp110.x + (f32)((s16)(tmp - 1) * 8), sp110.y);
            func_002b2a60(&c2D, 0x2D, 0x2D, 0x2D, 0xFF);
            h0 = (s32)func_0046a770(D_0063FB50);
            func_002cacd0(spA8, 22.0f, c2D, 0xF, 0, uA, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        }
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        if (((func_00110830(cA) & 0xFF) & 1) != 0) {
            func_002b2970(&sp1D0, 37.0f, 243.0f);
            colC = func_002b2a30(0, 0xFF, 0x66, 0);
            func_002e0be0(0x49, sp1D0, 65.0f, colC, 0xFF, 0, D_00794EA0);
        }
        func_002e09e0(*(void **)(work + 0xE60), 0x56, 94.0f);
        b = (Vec2f *)D_0063F9B0;
        func_002b2970(&sp1C8, b->x, b->y);
        p = func_002e04e0(*(void **)(work + 0xE60));
        *(Vec2f *)(p + 0x2C) = sp1C8;
        func_002e0940(*(void **)(work + 0xE60), fGpffff7ad4, fGpffff7ad4, 0, 0, 0);
        for (i = 0; i < 3; i++) {
            q = work + i * 4;
            func_002e09e0(*(void **)(q + 0xDBC), 0x41, 95.0f);
            func_002b2a60(&cFF, 0xFF, 0xEF, 0x80, 0xFF);
            p = func_002e04e0(*(void **)(q + 0xDBC));
            *(RGBA *)(p + 0x79) = cFF;
        }
        func_002e09e0(*(void **)(work + 0xCAC), 0x56, 91.0f);
        func_002b2a60(&cFE3, 0xFE, 0xC7, 0x31, 0xFF);
        p = func_002e04e0(*(void **)(work + 0xCAC));
        *(RGBA *)(p + 0x79) = cFE3;
        func_002e09e0(*(void **)(work + 0xE84), 0x56, 91.0f);
        func_002b2a60(&cFE3, 0xFE, 0xC7, 0x31, 0xFF);
        p = func_002e04e0(*(void **)(work + 0xE84));
        *(RGBA *)(p + 0x79) = cFE3;
        func_002b2970(&sp1C0, 468.0f, 338.0f);
        p = func_002e04e0(*(void **)(work + 0xE84));
        *(Vec2f *)(p + 0x2C) = sp1C0;
        if (func_002e2670() >= 2) {
            func_002e09e0(*(void **)(work + 0xC94), 0x41, 88.0f);
            func_002b2a60(&cE7, 0xFF, 0x96, 0, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xC94));
            *(RGBA *)(p + 0x79) = cE7;
            func_002e09e0(*(void **)(work + 0xC98), 0x41, 89.0f);
            func_002b2a60(&cE7, 0xFF, 0x96, 0, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xC98));
            *(RGBA *)(p + 0x79) = cE7;
            fdiv = 91.0f / (f32)(func_002e2670() - 1);
            *(f32 *)(work + 0xC) = fdiv;
            b = (Vec2f *)D_0063F620;
            func_002b2970(&sp1B8, b->x - 1.0f, 264.0f + *(f32 *)(work + 0xC) * (f32)*(s16 *)(work + 2));
            colC = func_002b2a30(0xFF, 0xFF, 0x6D, 0x31);
            func_002e0b20(0x36, sp1B8, 87.0f, colC, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC98)) + 0x62), 0, D_00794EA0);
        }
        func_002b2970((Vec2f *)&sp1B0, 537.0f, 266.0f);
        tmp = func_00106a90((s16)func_002e2740(*(s16 *)(work + 2)));
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp1B0, 70.0f, c2AC, 0x10, 5, (u32)tmp, 9, 0x7B, h0, *(s32 *)((u8 *)work + 0xF28), 0xA9);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), *(s8 *)(work + 7));
        if ((func_001069d0((s64)c16) & 0xFFFF) == 0) {
            for (j = 0; j < 0xF; j++) {
                func_002b2970(&sp1A8, (f32)(j * 0x16 + 0x6F), 134.0f);
                colC = func_002b2a30(0xFF, 0x2D, 0x2D, 0x2D);
                func_002e0b20(0x3C, sp1A8, 86.0f, colC, 0xFF, 0, D_00794ED0);
            }
        } else {
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), *(s8 *)(work + 7));
            uA = func_001069d0((s64)c16);
            colC = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
            func_002bc7f0(uA, colC, 1, 0, 3, 0xAA, 109.0f, 124.0f, 70.0f);
        }
        if (*(s8 *)(work + 7) == 2) {
            colC = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            func_002b2970(&sp160, 129.0f, 89.0f);
            spC8b = sp160;
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 2);
            func_00275680(spC8b.x, spC8b.y, 70.0f, colC, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00794ED0, -1);
            func_002b2970(&sp158, 86.0f, 90.0f);
            colC = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            func_002e0b20(0x1C, sp158, 69.0f, colC, 0xFF, 0, D_00794ED0);
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 2);
            tmp = (s16)func_00106b80(c16);
            colC = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            func_002bc7f0(tmp, colC, 1, 0, 2, 0x57, 109.0f, 158.0f, 70.0f);
            func_002e09e0(*(void **)(work + 0xCBC), 0x57, 85.0f);
            func_002e09e0(*(void **)(work + 0xEB0), 0x57, 85.0f);
            b = (Vec2f *)D_0063F668;
            func_002b2970(&sp150, b->x, b->y + 50.0f);
            p = func_002e04e0(*(void **)(work + 0xEB0));
            *(Vec2f *)(p + 0x2C) = sp150;
        } else if (*(s8 *)(work + 7) == 1) {
            colC = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            func_002b2970(&sp180, 129.0f, 89.0f);
            spC0b = sp180;
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
            func_00275680(spC0b.x, spC0b.y, 70.0f, colC, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00794ED0, -1);
            func_002b2970(&sp178, 86.0f, 90.0f);
            colC = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            func_002e0b20(0x1B, sp178, 69.0f, colC, 0xFF, 0, D_00794ED0);
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
            tmp = (s16)func_00106b80(c16);
            colC = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            func_002bc7f0(tmp, colC, 1, 0, 1, 0x57, 109.0f, 158.0f, 70.0f);
            func_002e09e0(*(void **)(work + 0xE94), 0x57, 81.0f);
            func_002b2a60(&cE7, 0xE7, 0xE5, 0xE6, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xE94));
            *(RGBA *)(p + 0x79) = cE7;
            b = (Vec2f *)D_0063F628;
            func_002b2970(&sp170, b->x, b->y - 166.0f);
            p = func_002e04e0(*(void **)(work + 0xE94));
            *(Vec2f *)(p + 0x2C) = sp170;
            func_002e09e0(*(void **)(work + 0xE9C), 0x57, 80.0f);
            func_002b2a60(&cE7, 0xE7, 0xE5, 0xE6, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xE9C));
            *(RGBA *)(p + 0x79) = cE7;
            b = (Vec2f *)D_0063F638;
            func_002b2970(&sp168, b->x, b->y - 166.0f);
            p = func_002e04e0(*(void **)(work + 0xE9C));
            *(Vec2f *)(p + 0x2C) = sp168;
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
            uA = func_00106940(c16);
            tmp = func_002b3170(uA);
            func_002b2970((Vec2f *)&sp80, 518.0f + (f32)((s16)(tmp - 1) * 8), 158.0f);
            func_002b2a60(&c2D, 0x2D, 0x2D, 0x2D, 0xFF);
            h0 = (s32)func_0046a770(D_0063FB50);
            func_002cacd0(sp80, 22.0f, c2D, 0xF, 0, uA, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
            uA = func_00106970(c16);
            tmp = func_002b3170(uA);
            func_002b2970((Vec2f *)&sp78, 518.0f + (f32)((s16)(tmp - 1) * 8), 208.0f);
            func_002b2a60(&c2D, 0x2D, 0x2D, 0x2D, 0xFF);
            h0 = (s32)func_0046a770(D_0063FB50);
            func_002cacd0(sp78, 22.0f, c2D, 0xF, 0, uA, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        } else if (*(s8 *)(work + 7) == 0) {
            colC = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            func_002b2970(&sp1A0, 129.0f, 89.0f);
            spD8b = sp1A0;
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
            func_00275680(spD8b.x, spD8b.y, 70.0f, colC, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00794ED0, -1);
            func_002b2970(&sp198, 86.0f, 90.0f);
            colC = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            func_002e0b20(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), sp198, 69.0f, colC, 0xFF, 0, D_00794ED0);
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
            tmp = (s16)func_00106b80(c16);
            colC = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
            func_002bc7f0(tmp, colC, 1, 0, 0, 0x57, 109.0f, 158.0f, 70.0f);
            func_002e09e0(*(void **)(work + 0xE98), 0x57, 83.0f);
            func_002b2a60(&cE7, 0xE7, 0xE5, 0xE6, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xE98));
            *(RGBA *)(p + 0x79) = cE7;
            b = (Vec2f *)D_0063F630;
            func_002b2970(&sp190, b->x, b->y - 166.0f);
            p = func_002e04e0(*(void **)(work + 0xE98));
            *(Vec2f *)(p + 0x2C) = sp190;
            func_002e09e0(*(void **)(work + 0xEA0), 0x57, 82.0f);
            func_002b2a60(&cE7, 0xE7, 0xE5, 0xE6, 0xFF);
            p = func_002e04e0(*(void **)(work + 0xEA0));
            *(RGBA *)(p + 0x79) = cE7;
            b = (Vec2f *)D_0063F640;
            func_002b2970(&sp188, b->x, b->y - 166.0f);
            p = func_002e04e0(*(void **)(work + 0xEA0));
            *(Vec2f *)(p + 0x2C) = sp188;
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
            uA = func_001068b0(c16);
            tmp = func_002b3170(uA);
            func_002b2970((Vec2f *)&sp90, 518.0f + (f32)((s16)(tmp - 1) * 8), 158.0f);
            func_002b2a60(&c2D, 0x2D, 0x2D, 0x2D, 0xFF);
            h0 = (s32)func_0046a770(D_0063FB50);
            func_002cacd0(sp90, 22.0f, c2D, 0xF, 0, uA, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
            c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
            uA = func_001068e0(c16);
            tmp = func_002b3170(uA);
            func_002b2970((Vec2f *)&sp88, 518.0f + (f32)((s16)(tmp - 1) * 8), 208.0f);
            func_002b2a60(&c2D, 0x2D, 0x2D, 0x2D, 0xFF);
            h0 = (s32)func_0046a770(D_0063FB50);
            func_002cacd0(sp88, 22.0f, c2D, 0xF, 0, uA, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        }
        for (k = 0; k < 3; k++) {
            b = (Vec2f *)(D_0063F560 + (k + 0x61) * 8);
            q = work + k * 4;
            func_002e09e0(*(void **)(q + 0xE88), 0x41, 95.0f);
            func_002b2a60(&cB0, 0xE7, 0xE5, 0xE7, 0xFF);
            p = func_002e04e0(*(void **)(q + 0xE88));
            *(RGBA *)(p + 0x79) = cB0;
            func_002b2970(&sp148, b->x, b->y - 166.0f);
            p = func_002e04e0(*(void **)(q + 0xE88));
            *(Vec2f *)(p + 0x2C) = sp148;
        }
        func_002e09e0(*(void **)(work + 0xEA4), 0x56, 91.0f);
        func_002b2a60(&cB0, 0xB0, 0xAE, 0xAF, 0xFF);
        p = func_002e04e0(*(void **)(work + 0xEA4));
        *(RGBA *)(p + 0x79) = cB0;
        b = (Vec2f *)D_0063F648;
        func_002b2970(&sp140, b->x, b->y - 166.0f);
        p = func_002e04e0(*(void **)(work + 0xEA4));
        *(Vec2f *)(p + 0x2C) = sp140;
        func_002e09e0(*(void **)(work + 0xEA8), 0x56, 91.0f);
        func_002b2a60(&cB0, 0xB0, 0xAE, 0xAF, 0xFF);
        p = func_002e04e0(*(void **)(work + 0xEA8));
        *(RGBA *)(p + 0x79) = cB0;
        func_002b2970(&sp138, 468.0f, 172.0f);
        p = func_002e04e0(*(void **)(work + 0xEA8));
        *(Vec2f *)(p + 0x2C) = sp138;
        return 1;
    }
    func_002e04f0(*(void **)(work + 0xC9C), 0, 1);
    func_002e04f0(*(void **)(work + 0xCA0), 0, 1);
    func_002e04f0(*(void **)(work + 0xCA4), 0, 1);
    func_002e04f0(*(void **)(work + 0xCA8), 0, 1);
    func_002e04f0(*(void **)(work + 0xCB8), 0, 1);
    func_002e04f0(*(void **)(work + 0xEAC), 0, 1);
    i = 0;
    do {
        q = work + i * 4;
        func_002e04f0(*(void **)(q + 0xDBC), 0, 1);
        func_002e04f0(*(void **)(q + 0xE88), 0, 1);
        i++;
    } while (i < 3);
    func_002e04f0(*(void **)(work + 0xCAC), 0, 1);
    func_002e04f0(*(void **)(work + 0xE84), 0, 1);
    func_002e04f0(*(void **)(work + 0xC94), 0, 1);
    func_002e04f0(*(void **)(work + 0xC98), 0, 1);
    func_002e04f0(*(void **)(work + 0xE94), 0, 1);
    func_002e04f0(*(void **)(work + 0xE98), 0, 1);
    func_002e04f0(*(void **)(work + 0xE9C), 0, 1);
    func_002e04f0(*(void **)(work + 0xEA0), 0, 1);
    func_002e04f0(*(void **)(work + 0xCBC), 0, 1);
    func_002e04f0(*(void **)(work + 0xEB0), 0, 1);
    func_002e04f0(*(void **)(work + 0xEA4), 0, 1);
    func_002e04f0(*(void **)(work + 0xEA8), 0, 1);
    func_002e04f0(*(void **)(work + 0xE60), 0, 1);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d1590);
#endif

/* measured: func_002d3ee0's full body was reconstructed (all call shapes,
   u64 slot pairs, switch, loops) and compiles; nd 462 with inline
   D_0063F5xx[0]/[1] globals. Retail caches each absolute global base in $s0
   across the func_002b2970/func_002e0620 groups; mwcc b210 rematerialises
   lui/addiu per load (D_00887300-family global-address-hoist floor, cf.
   func_002d7300 note). A Vec2f* base local makes mwcc cache the base but then
   work moves to $s2 and the frame grows 0x10 (all 19 u64 slots shift +0x10),
   nd ~470; tried both declaration orders and block-scoped i/t. Also: the
   func_002e0660 colour-byte args need a u8 prototype for lbu/0xFF codegen.
   Four-attempt budget exhausted. */
/* measured: recipe B re-test 2026-08-03: single Vec2f *b re-assigned per
   group (retail re-hoists its $s0 base per group) WORKS here: nd 462 -> 9.
   Also needed: field_4 retyped u32 -> s16 (retail reads it with lh; the u32
   read produced lw + bltz/dup on (f32)(field_4<<5) AND hoisted a work+4
   address into a 3rd saved reg, frame 0xD0 -> 0xE0); plain i++ s16 loops
   (explicit (s16)/(s32) casts double the dsll32/dsra32 pairs). Residual 9
   words: (1) loop index addu operand order (obj addu $v0,$v0,$s1 vs retail
   $s1,$v0; u32-arithmetic spelling does not change it); (2) func_002e0690
   arg materialization - retail f12, $4, mov.s f13, $5-$7; mwcc emits $5-$7
   then mov.s; (3) the sp58 f32-pair stores: mwcc always loads in reverse
   store order (lwc1 0x5C before 0x58, first-loaded binds $f1) - tried f32
   temps in all declaration/assignment orders. Scheduling floor. */
/* MATCHED 2026-09-18.  The last 4 words were `mov.s $f13, $f12` three slots
   late.  b210 emits call-argument setup in source order, so retail's copy
   landing between `lw $a0` and `move $a1` means func_002e0690's two floats
   are arguments 2 and 3, not 5 and 6; the EABI gives integer and float
   arguments separate register files, so the reordered prototype is the same
   ABI and leaves the MATCHed callee in src/promoted/code1_002e.c byte-exact.
   Everything else here was already exact: switch dispatch, Vec2f-by-value
   arguments, and the raw u64 stack slots. */
// FUN_002D3EE0
void func_002d3ee0(void *arg0) {
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    ShopWork *work;
    u8 *t;
    Vec2f *b;
    s16 i;
    s8 v7;
    work = *(ShopWork **)((u8 *)arg0 + 0x38);
    b = (Vec2f *)D_0063F5B0;
    func_002e09e0(work->field_C60, 0x41, 109.0f);
    func_002b2970(&spC8, b->x, b->y);
    func_002b2970(&spC0, b->x - 740.0f, b->y);
    func_002e0620(work->field_C60, spC8, spC0, 0, 4, 0);
    b = (Vec2f *)D_0063F5F0;
    func_002e09e0(work->field_C80, 0x41, 109.0f);
    func_002b2970(&spB8, b->x, b->y);
    func_002b2970(&spB0, b->x - 740.0f, b->y);
    func_002e0620(work->field_C80, spB8, spB0, 0, 4, 0);
    b = (Vec2f *)D_0063F5D0;
    func_002e09e0(work->field_C70, 0x41, 111.0f);
    func_002b2970(&spA8, b->x, b->y);
    func_002b2970(&spA0, b->x - 740.0f, b->y);
    func_002e0620(work->field_C70, spA8, spA0, 0, 4, 0);
    for (i = 0; i < 3; i++) {
        func_002e04f0(*(void **)((u8 *)work + 0xE88 + i * 4), 0, 1);
    }
    func_002e04f0(work->field_EA4, 0, 1);
    func_002e04f0(work->field_EA8, 0, 1);
    v7 = *(s8 *)((u8 *)work + 7);
    switch (v7) {
    case 0:
        func_002e04f0(work->field_CA0, 0, 1);
        func_002e04f0(work->field_CA8, 0, 1);
        func_002e04f0(work->field_E98, 0, 1);
        func_002e04f0(work->field_EA0, 0, 1);
        break;
    case 1:
        func_002e04f0(work->field_C9C, 0, 1);
        func_002e04f0(work->field_CA4, 0, 1);
        func_002e04f0(work->field_E94, 0, 1);
        func_002e04f0(work->field_E9C, 0, 1);
        break;
    case 2:
        func_002e04f0(work->field_CB8, 0, 1);
        func_002e04f0(work->field_EAC, 0, 1);
        func_002e04f0(work->field_CBC, 0, 1);
        func_002e04f0(work->field_EB0, 0, 1);
        break;
    }
        func_002e09e0(work->field_E80, 0x41, 109.0f);
    func_002b2970(&sp98, 86.0f, 242.0f);
    func_002b2970(&sp90, 826.0f, 242.0f);
    func_002e0620(work->field_E80, sp98, sp90, 0, 4, 0);
    b = (Vec2f *)D_0063F5F8;
    func_002e09e0(work->field_C84, 0x41, 112.0f);
    func_002b2970(&sp88, b->x, b->y);
    func_002b2970(&sp80, 740.0f + b->x, b->y);
    func_002e0620(work->field_C84, sp88, sp80, 0, 4, 0);
    b = (Vec2f *)D_0063F5D8;
    func_002e09e0(work->field_C74, 0x41, 113.0f);
    func_002b2970(&sp78, b->x, b->y);
    func_002b2970(&sp70, 740.0f + b->x, b->y);
    func_002e0620(work->field_C74, sp78, sp70, 0, 4, 0);
    b = (Vec2f *)D_0063F5E0;
    func_002e09e0(work->field_C78, 0x41, 114.0f);
    func_002b2970(&sp68, b->x, b->y);
    func_002b2970(&sp60, 740.0f + b->x, b->y);
    func_002e0620(work->field_C78, sp68, sp60, 0, 4, 0);
    for (i = 0; i < 3; i++) {
        func_002e04f0(*(void **)((u8 *)work + 0xDBC + i * 4), 0, 1);
    }
    func_002e04f0(work->field_CAC, 0, 1);
    func_002e04f0(work->field_E84, 0, 1);
    func_002e04f0(work->field_C94, 0, 1);
    func_002e04f0(work->field_C98, 0, 1);
    func_002e04f0(work->field_E60, 0, 1);
    func_002e04f0(work->field_DE0, 0, 1);
    func_002e0940(work->field_D6C, -110.0f, -14.0f, 0, 4, 0);
    func_002e0690(work->field_D70, 1.0f, 1.0f, 0, 0, 0);
    func_002e0660(work->field_D70, 0, 0xFF, 0, 8, 6);
    func_002b2970(&sp58, 46.0f, 294.0f);
    t = (u8 *)func_002e04e0(work->field_D70);
    *(Vec2f *)(t + 0x2C) = *(Vec2f *)&sp58;
    func_002e0660(work->field_D7C, 0, 0xFF, 0, 8, 6);
    t = (u8 *)func_002e04e0(work->field_C8C);
    func_002e0660(work->field_C8C, t[0x62], 0xFF, 0, 8, 0);
    t = (u8 *)func_002e04e0(work->field_C90);
    func_002e0660(work->field_C90, t[0x62], 0xFF, 0, 8, 0);
    b = (Vec2f *)D_0063F880;
    func_002b2970(&sp50, 700.0f + b->x, b->y + (f32)(work->field_4 << 5));
    func_002b2970(&sp48, b->x, b->y + (f32)(work->field_4 << 5));
    func_002e0620(work->field_DC8, sp50, sp48, 1, 3, 3);
    t = (u8 *)func_002e04e0(work->field_C8C);
    func_002e0660(work->field_DC8, t[0x62], 0xFF, 0, 8, 0);
    b = (Vec2f *)D_0063F890;
    func_002b2970(&sp40, 700.0f + b->x, b->y + (f32)(work->field_4 << 5));
    func_002b2970(&sp38, b->x, b->y + (f32)(work->field_4 << 5));
    func_002e0620(work->field_DD0, sp40, sp38, 1, 3, 3);
    t = (u8 *)func_002e04e0(work->field_C8C);
    func_002e0660(work->field_DD0, t[0x62], 0xFF, 0, 8, 0);
    func_002e0660(work->field_C64, 0, 0xCC, 0, 8, 0);
    func_002e04f0(work->field_DE4, 0, 0);
}

/* measured: MWCC -O2 plain, object 1948B/window 2000B, normalized_diff 389 (VSHD baseline 399/2044B -> s32-i -10, s32+(s16)cast -8). Shape u8 colorA/B[3][4], s16 primary/secondary/y/thirdY, s8 ret/i-d, u8 *work, frame 0x100 matches. Levers: s32/u32/int, switch/ifelse, derived/void/work/decl/d/ret/indexed/forward/reload/y/primary/RGBA as reported. Remaining work $s4-vs-$s3, init $v0-vs-$v1, 0x2D scheduling, D swap, second-loop temps. Combine RGBA transfer fails (+5/+15), u8[3][4] optimal. No volatile/asm. Staged /tmp/push_4760_full.c via NearGA.Fcl4760. */
// FUN_002D4760 NONMATCHING
#ifdef NON_MATCHING
s8 func_002d4760(void *arg0, s8 arg1) {
    u8 colorA[3][4];
    u8 colorB[3][4];
    s16 primary[3];
    s16 secondary[3];
    s16 y[3][2];
    s16 thirdY[3];
    s8 ret;
    s32 i;
    s8 d;
    u8 *work;

    ret = arg1;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    colorA[2][0] = 0xBD;
    colorA[0][0] = 0xBD;
    colorA[2][1] = 0x68;
    colorA[0][1] = 0x68;
    colorA[2][2] = 3;
    colorA[0][2] = 3;
    primary[2] = 0x56;
    primary[0] = 0x56;
    y[2][0] = 0x86;
    y[0][0] = 0x86;
    y[2][1] = 0x87;
    y[0][1] = 0x87;
    colorB[2][0] = 0x2D;
    colorB[0][0] = 0x2D;
    colorB[2][1] = 0x2D;
    colorB[0][1] = 0x2D;
    colorB[2][2] = 0x2D;
    colorB[0][2] = 0x2D;
    secondary[2] = 0x57;
    secondary[0] = 0x57;
    thirdY[2] = 0x85;
    thirdY[0] = 0x85;
    colorA[1][0] = 0x90;
    colorA[1][1] = 0x4F;
    colorA[1][2] = 1;
    primary[1] = 0x41;
    y[1][0] = 0x89;
    y[1][1] = 0x8A;
    colorB[1][0] = 0x2D;
    colorB[1][1] = 0x2D;
    colorB[1][2] = 0x2D;
    secondary[1] = 0x42;
    thirdY[1] = 0x88;
    for (i = 0; i < 3; i++) {
        d = D_00748908[i];
        if (d >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
            colorA[i][2] = 0x2D;
            colorA[i][1] = 0x2D;
            colorA[i][0] = 0x2D;
            if (i == 1) {
                colorA[i][2] = 0;
                colorA[i][1] = 0;
                colorA[i][0] = 0;
            }
            colorB[i][2] = 0x6F;
            colorB[i][1] = 0x6F;
            colorB[i][0] = 0x6F;
        }
        if (i == arg1) {
            colorA[i][0] = 0xFF;
            colorA[i][1] = 0x96;
            colorA[i][2] = 1;
            primary[i] = 0x57;
            y[i][0] = 0x83;
            y[i][1] = 0x84;
            colorB[i][0] = 0xFF;
            colorB[i][1] = 0xF2;
            colorB[i][2] = 0x95;
            secondary[i] = primary[i] + 1;
            thirdY[i] = 0x82;
            if (d >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
                ((u8 *)colorA)[i * 4 + 2] = 0x9C;
                ((u8 *)colorA)[i * 4 + 1] = 0x9C;
                ((u8 *)colorA)[i * 4 + 0] = 0x9C;
                ((u8 *)colorB)[i * 4 + 2] = 0xFF;
                ((u8 *)colorB)[i * 4 + 1] = 0xFF;
                ((u8 *)colorB)[i * 4 + 0] = 0xFF;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            goto L2;
        }
        if (i == 1) {
            goto L1;
        }
        if (i == 0) {
            goto L0;
        }
        goto Lend;
L0: *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 8) = (f32)y[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 8) = (f32)y[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x79) = colorB[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7A) = colorB[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7B) = colorB[i][2];
        goto Lend;
L1: *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 8) = (f32)y[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 8) = (f32)y[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x79) = colorB[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7A) = colorB[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7B) = colorB[i][2];
        goto Lend;
L2: *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 8) = (f32)y[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 8) = (f32)y[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x79) = colorB[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7A) = colorB[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7B) = colorB[i][2];
Lend: ;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d4760);
#endif

// FUN_002D4F30
s32 func_002d4f30(s16 arg0) {
    if (arg0 & 0x81) return 0x14;
    if (arg0 & 0x102) return 0x15;
    if (arg0 & 0x204) return 0x16;
    if (arg0 & 0x408) return 0x17;
    if (arg0 & 0x810) return 0x18;
    if (arg0 & 0x1020) return 0x19;
    if (arg0 & 0x2040) return 0x1A;
    if (arg0 & 0x4000) return 0x1B;
    if (arg0 & 0x8000) return 0x1C;
    if (arg0 & 0x40000) return 0x1D;
    return 0;
}

/* measured: probe_variants 924 differing words reloc-masked (V5 workFirst with opt_propagation off; bare V1 964, V4 handle 926, V6 tmpLast 924 tie); fnalign retail 1105 vs object 1090 instrs (-15, -1.36% PASS, 691 edits +32 reloc-only via --candidate v5_workFirst.c --quiet); verify/lint clean. Count-first PASS (within 3%). */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclShopDraw.c func_002d5040 -o /var/tmp/cold2d5040/m2c.c` (193 lines, void(void*) + s64 homes) + `python3 -E -s tools/romwright_decompile.py func_002d5040 -o /var/tmp/cold2d5040/rom.c` (277 lines, (void*) arity confirmed, CONCAT44/stack extents confirmed); `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclShopDraw.c func_002d5040 --candidate V5=/var/tmp/cold2d5040/v5_workFirst.c` (924) + `python3 -E -s tools/fnalign.py src/Event/Fcl/y_fclShopDraw.c func_002d5040 --candidate /var/tmp/cold2d5040/v5_workFirst.c --quiet` (1105/1090) + `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclShopDraw.c func_002d5040`. */
/* Rounds in batch order (count first): v1 964 (m2c+rom de-noise, Vec2f/u64/RGBA homes, s32 c16=(s16)2740/106cd0 locals for dsll32/dsra32, byte-first addu (*(s8*)((u8*)(*(s8*)(work+8)+(u32)work)+0xF73)), 1153/1108 +45 FAIL); v1 propOff 927 (-37, 1090/1105 -15 PASS) <-- family convention (31fa20 needs propOff; 315600 deadOff 762->755; 302770 peephole 787->728); v1 deadOff 973 worse, peephole 1141 worse; v2 dual-04e0 999 worse (1165 +57 FAIL); v3 u16-mask 931 worse; v4 h0-handle 926 (-1, s32 h0=(s32)46a770 first-call save to $s2); v5 workFirst 924 (-2, best PASS) + v6 tmpLast 924 tie; v5 schedOn 923 (-1) but 942/1105 -163 FAIL unbankable; v7 noDoubleExt 927 worse. Step3 subscript tie (Vec2f/u64/RGBA already retail ld/lw forms); Step4 decl-order tie (workFirst/tmpLast). Stopped after three non-improving rounds above 60. Banked v5+propOff as guarded floor. */
/* Walls (same float-hoist+scheduling as sibling de5a0, now at 924): retail f20 hoisted vs object f12 rematerialised per 2970 pair (lui+lwc1 hoist vs interleaved lwc1/lui); retail lwc1/swc1 Vec2f copy vs object ld/sd; retail andi vs object ori/and under propOff (&0xFFFF); $s0/$s1 colouring (work/tmp/h0/dA/dB) persists -- body already in 7o form (bare decls, statement assigns in retail order) so eight probes are ties per handoff 7o; all logic matches: 2a30/0b20/75680 chain + three-case switch on work[7] (68b0/68e0 vs 6940/6970) + eight cacd0 digits (22.0f/0xF/0/0x1E/0x7B/h0/h1/0xA9) + blez/bgez tail pair (360+87/245/23). Prior nd-814 note superseded (sign-extension locals now in place via s32 cA/cB/c16); lever-1 audit void(void*) kept, cacd0 11-arg file decl kept (12-arg claim was wrong: 8 int regs + 2 stack + 1 float = 11). */
/* 2026-09-18 opcode census; floor stands at 924.  `tools/opclass.py` ranks
   this the largest opcode-class surplus on the board: `dsra32 +37`,
   `dsll32 +37` against `mtc1 -37` and `lui -35`.  Thirty-seven
   sign-extension pairs is the textbook too-narrow-local signature, but the
   `(s16)` casts in this body are not the cause - dropping the redundant
   `(s16)` on values that are already narrow ties at 924, declaring `cA`,
   `cB` and `c16` as `s16` and removing the casts ties at 924, and dropping
   every `(s16)` result cast costs 936.  The paired `mtc1`/`lui` deficit says
   retail materialises 35 constants this body does not, so the two halves are
   probably one phenomenon: retail keeps wide constants where this body
   narrows and re-extends.  That is the thread for the next pass. */
/* thread resolved 2026-09-19: retail `mtc1` spans are two families -- float-bit `lui+mtc1` for 37.0/35.0/31.0/79.0/34.0/296.0/51.0/87.0/22.0/149.0/360.0/245.0/23.0 (each `lwc1`-then-`lui/mtc1/add.s`, interleaved with dual `04e0` calls per `2970`) plus int-path `mtc1+cvt.s.w` for 263 (`addiu 0x107`) and `(nA-1)*8` (`sll 3`); body round-trips three values narrow: (1) `0046a770` handle via wrong file-scope `s64` (def returns `u8*`, sibs use `voidptr/s32`) -- `(s32)` narrows `s64->s32` as `dsll32 0/dsra32 0` (16 pairs, `daddu` in retail); (2) `002b3170` via wrong file-scope `s16` (def/promoted/sib return `s32`) -- `nA=(s16)` extends before `-1` (8 pairs, retail extends after only); (3) `c16` s32 store vs retail `daddu` for `06cd0->068x` chains. `and+17/andi-13` is mask `0xFFFF` hoisted to `$s3` (`ori+and`) under `propOff` via `cB/tmp` reuse across 8 arms vs retail per-use `andi`. */
/* banked 2026-09-19 at 907 words (-17): file-scope `0046a770 s64->void*` + `002b3170 s16->s32` (match defs/sibs, verify 26 MATCH no regress) + split 6 two-load `2970`s to dual `04e0` calls (`*(p+0x2C/0x30)` -> `*((u8*)04e0+0x2C/0x30)` each, 20->26 occ, fixes `jal/lw -4`, counts 1105/1074 PASS) + `cB8/cB0` struct->field assigns (`ld/sd` -> `lwc1/swc1`, edits 691->436). `measure_guarded` 907, `fnalign --candidate` 1105/1074 +44 reloc-only, `opclass` `dsll/dsra 13` (was 37: -16 handle, -8 nA), `mtc1/lui` + `and/andi` + `mov.s` walls stand (floats hoisted to `$f21-$f27`, mask to `$s3`). Rejected: wide-`u16` (drop `(s16)` on `68b0/e0/6940/6970`, 930/936 worse -- narrow matches retail `andi` sites); `c16`-inline (925, -43 FAIL); `commonSubs off` (908 tie, 1141 FAIL, 1530 edits). */
// FUN_002D5040 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_002d5040(void *arg0) {
    extern s16 func_002e2740(s32 arg0);
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    RGBA sp12C;
    RGBA sp128;
    RGBA sp124;
    RGBA sp120;
    RGBA sp11C;
    RGBA sp118;
    RGBA sp114;
    RGBA sp110;
    Vec2f cB8;
    Vec2f cB0;
    u8 *work;
    s32 tmp;
    s32 t0;
    s32 t1;
    s32 c16;
    s32 cA;
    s32 cB;
    s32 nA;
    s32 h0;
    s32 dA;
    s32 dB;
    u8 *pCE4;
    u8 *pEDC;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    cA = (s16)func_002e2740(*(s16 *)(work + 2));
    cB = (s16)func_00106880((s16)cA);
    tmp = func_002d4f30((s16)cB) & 0xFFFF;
    func_002b2970(&sp108, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x30));
    pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
    func_002e0b20(tmp, sp108, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    t0 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&sp100, 79.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 34.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x30));
    cB8.x = sp100.x; cB8.y = sp100.y;
    cA = (s16)func_002e2740(*(s16 *)(work + 2));
    func_00275680(cB8.x, cB8.y, 31.0f, t0, 0, 1, (const char *)func_001067f0(cA), 0, 0, D_00795E30, -1);
    t1 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&spF8, 79.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 34.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
    cB0.x = spF8.x; cB0.y = spF8.y;
    c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), *(s8 *)(work + 7));
    func_00275680(cB0.x, cB0.y, 31.0f, t1, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    if (*(s8 *)(work + 7) == 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068b0((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&spA8, 51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C)) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp12C, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(spA8, 22.0f, sp12C, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068e0((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&spA0, 87.0f + (51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C))) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp128, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(spA0, 22.0f, sp128, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        func_002b2970(&spF0, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        func_002e0b20(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), spF0, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        cB = (s16)func_001068b0(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp98, 51.0f + (296.0f + *(f32 *)(pEDC + 0x2C)) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp124, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp98, 22.0f, sp124, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        cB = (s16)func_001068e0(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp90, 87.0f + (51.0f + (296.0f + *(f32 *)(pEDC + 0x2C))) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp120, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp90, 22.0f, sp120, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        tmp = func_001068b0(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068b0((s16)cA);
        dB = (s16)((cB & 0xFFFF) - tmp);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        tmp = func_001068e0(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068e0((s16)cA);
        dA = (s16)((cB & 0xFFFF) - tmp);
    } else if (*(s8 *)(work + 7) == 1) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106940((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp88, 51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C)) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp11C, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp88, 22.0f, sp11C, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106970((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp80, 87.0f + (51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C))) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp118, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp80, 22.0f, sp118, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        func_002b2970(&spE8, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
        func_002e0b20(0x1B, spE8, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        cB = (s16)func_00106940(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp78, 51.0f + (296.0f + *(f32 *)(pEDC + 0x2C)) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp114, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp78, 22.0f, sp114, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        cB = (s16)func_00106970(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp70, 87.0f + (51.0f + (296.0f + *(f32 *)(pEDC + 0x2C))) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp110, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp70, 22.0f, sp110, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        tmp = func_00106940(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106940((s16)cA);
        dB = (s16)((cB & 0xFFFF) - tmp);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        tmp = func_00106970(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106970((s16)cA);
        dA = (s16)((cB & 0xFFFF) - tmp);
    } else if (*(s8 *)(work + 7) == 2) {
        func_002b2970(&spE0, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
        func_002e0b20(0x1C, spE0, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        dA = 0;
        dB = 0;
    } else {
        dA = 0;
        dB = 0;
    }
    if (dB > 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spD8, 360.0f + *(f32 *)(pCE4 + 0x2C), 245.0f);
        func_002e0b20(0x28, spD8, 23.0f, func_002b2a30(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
    } else if (dB < 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spD0, 360.0f + *(f32 *)(pCE4 + 0x2C), 245.0f);
        func_002e0b20(0x29, spD0, 23.0f, func_002b2a30(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
    if (dA > 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spC8, 87.0f + (360.0f + *(f32 *)(pCE4 + 0x2C)), 245.0f);
        func_002e0b20(0x28, spC8, 23.0f, func_002b2a30(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
        return;
    }
    if (dA < 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spC0, 87.0f + (360.0f + *(f32 *)(pCE4 + 0x2C)), 245.0f);
        func_002e0b20(0x29, spC0, 23.0f, func_002b2a30(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d5040);
#endif

/* measured: full body reconstructed (19 RGBA color groups + 0a60/2a60/04e0/
   2970/0620 chains, 48 u64 slots, 2 ifs + 3-case switch); frame 0x200 and all
   slot offsets matched; best nd 895 (obj only 2 words over window). Three
   residual families: (1) D_0063F658/D_0063F650 (f32[2]) base: retail hoists it
   into $s0 across the group's calls (lwc1 ($s0)/4($s0)); mwcc b210
   rematerialises lui+lwc1 per access even with named f32* base locals --
   same D_00887300 family as the func_002d7300 note. (2) color bytes: retail
   batches 4 lbu then 4 sb in address order into $a2/$a1/$a0/$v1; mwcc emits
   scrambled load order (g,b,a,r) for every spelling tried (array, u8 scalars,
   RGBA struct, explicit r/g/b/a temps). (3) work[7] if/switch: retail reloads
   lb 7($s1) per site; mwcc hoists addiu $s0,$s1,7. Global-address-hoist +
   scheduling floor. */
// FUN_002D6190
void func_002d6190(void *arg0) {
    RGBA sp1FC;
    RGBA sp1F8;
    RGBA sp1F4;
    RGBA sp1F0;
    RGBA sp1EC;
    RGBA sp1E8;
    RGBA sp1E4;
    RGBA sp1E0;
    RGBA sp1DC;
    RGBA sp1D8;
    RGBA sp1D4;
    RGBA sp1D0;
    RGBA sp1CC;
    RGBA sp1C8;
    RGBA sp1C4;
    RGBA sp1C0;
    RGBA sp1BC;
    RGBA sp1B8;
    RGBA sp1B4;
    u64 sp1A8;
    u64 sp1A0;
    u64 sp198;
    u64 sp190;
    u64 sp188;
    u64 sp180;
    u64 sp178;
    u64 sp170;
    u64 sp168;
    u64 sp160;
    u64 sp158;
    u64 sp150;
    u64 sp148;
    u64 sp140;
    u64 sp138;
    u64 sp130;
    u64 sp128;
    u64 sp120;
    u64 sp118;
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    u64 spD8;
    u64 spD0;
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    u64 sp30;
    u8 *work;
    u8 *t;
    Vec2f *base;
    s8 temp_4;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    func_002e0a60(*(void **)(work + 0xCE4), 0x56, 35.0f);
    func_002b2a60(&sp1FC, 0xFE, 0xC7, 0x31, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCE4)));
    *(RGBA *)(t + 0x79) = sp1FC;
    func_002b2970(&sp1A8, (f32) -0x212, 208.0f);
    func_002b2970(&sp1A0, 70.0f, 208.0f);
    func_002e0620(*(void **)(work + 0xCE4), sp1A8, sp1A0, 0, 8, 0);
    func_002e0a60(*(void **)(work + 0xCE8), 0x56, 35.0f);
    func_002b2a60(&sp1F8, 0xFE, 0xC7, 0x31, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCE8)));
    *(RGBA *)(t + 0x79) = sp1F8;
    func_002b2970(&sp198, -37.0f, 208.0f);
    func_002b2970(&sp190, (f32) 0x233, 208.0f);
    func_002e0620(*(void **)(work + 0xCE8), sp198, sp190, 0, 8, 0);
    base = (Vec2f *)D_0063F658;
    func_002e0a60(*(void **)(work + 0xCB4), 0x57, 33.0f);
    func_002b2a60(&sp1F4, 0xF7, 0x94, 0x1D, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCB4)));
    *(RGBA *)(t + 0x79) = sp1F4;
    func_002b2970(&sp188, base->x - 600.0f, base->y);
    func_002b2970(&sp180, base->x, base->y);
    func_002e0620(*(void **)(work + 0xCB4), sp188, sp180, 0, 8, 0);
    if (*(s8 *)(work + 7) != 2) {
        func_002e0a60(*(void **)(work + 0xCAC), 0x57, 30.0f);
        func_002b2a60(&sp1F0, 0xFF, 0xEF, 0x81, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xCAC)));
        *(RGBA *)(t + 0x79) = sp1F0;
        func_002b2970(&sp178, -232.0f, 227.0f);
        func_002b2970(&sp170, 368.0f, 227.0f);
        func_002e0620(*(void **)(work + 0xCAC), sp178, sp170, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xE84), 0x57, 30.0f);
        func_002b2a60(&sp1EC, 0xFF, 0xEF, 0x81, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE84)));
        *(RGBA *)(t + 0x79) = sp1EC;
        func_002b2970(&sp168, 468.0f, 338.0f);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE84)));
        *(Vec2f *)(t + 0x2C) = *(Vec2f *)&sp168;
        func_002b2970(&sp160, -145.0f, 227.0f);
        func_002b2970(&sp158, (f32) 0x1C7, 227.0f);
        func_002e0620(*(void **)(work + 0xE84), sp160, sp158, 0, 8, 0);
    }
    func_002e0a60(*(void **)(work + 0xEDC), 0x56, 35.0f);
    func_002b2a60(&sp1E8, 0xE7, 0xE6, 0xE6, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xEDC)));
    *(RGBA *)(t + 0x79) = sp1E8;
    func_002b2970(&sp150, (f32) 0x29E, 94.0f);
    func_002b2970(&sp148, 70.0f, 94.0f);
    func_002e0620(*(void **)(work + 0xEDC), sp150, sp148, 0, 8, 0);
    func_002e0a60(*(void **)(work + 0xEE0), 0x56, 35.0f);
    func_002b2a60(&sp1E4, 0xE7, 0xE6, 0xE6, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xEE0)));
    *(RGBA *)(t + 0x79) = sp1E4;
    func_002b2970(&sp140, (f32) 0x48B, 94.0f);
    func_002b2970(&sp138, (f32) 0x233, 94.0f);
    func_002e0620(*(void **)(work + 0xEE0), sp140, sp138, 0, 8, 0);
    base = (Vec2f *)D_0063F650;
    func_002e0a60(*(void **)(work + 0xCB0), 0x57, 34.0f);
    func_002b2a60(&sp1E0, 0xB0, 0xAF, 0xAF, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCB0)));
    *(RGBA *)(t + 0x79) = sp1E0;
    func_002b2970(&sp130, 600.0f + base->x, base->y);
    func_002b2970(&sp128, base->x, base->y);
    func_002e0620(*(void **)(work + 0xCB0), sp130, sp128, 0, 8, 0);
    func_002e0a60(*(void **)(work + 0xCD0), 0x57, 32.0f);
    func_002b2a60(&sp1DC, 0xE7, 0xE6, 0xE6, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCD0)));
    *(RGBA *)(t + 0x79) = sp1DC;
    func_002b2970(&sp120, (f32) 0x395, 178.0f);
    func_002b2970(&sp118, (f32) 0x13D, 178.0f);
    func_002e0620(*(void **)(work + 0xCD0), sp120, sp118, 0, 8, 0);
    if (*(s8 *)(work + 7) != 2) {
        func_002e0a60(*(void **)(work + 0xEA4), 0x57, 30.0f);
        func_002b2a60(&sp1D8, 0xB0, 0xAF, 0xAF, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xEA4)));
        *(RGBA *)(t + 0x79) = sp1D8;
        func_002b2970(&sp110, 968.0f, 113.0f);
        func_002b2970(&sp108, 368.0f, 113.0f);
        func_002e0620(*(void **)(work + 0xEA4), sp110, sp108, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xEA8), 0x57, 30.0f);
        func_002b2a60(&sp1D4, 0xB0, 0xAF, 0xAF, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xEA8)));
        *(RGBA *)(t + 0x79) = sp1D4;
        func_002b2970(&sp100, 468.0f, 338.0f);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xEA8)));
        *(Vec2f *)(t + 0x2C) = *(Vec2f *)&sp100;
        func_002b2970(&spF8, (f32) 0x41F, 113.0f);
        func_002b2970(&spF0, (f32) 0x1C7, 113.0f);
        func_002e0620(*(void **)(work + 0xEA8), spF8, spF0, 0, 8, 0);
    }
    temp_4 = (s8)(*(s8 *)(work + 7));
    switch (temp_4) {                               /* irregular */
    case 0:
        func_002e0a60(*(void **)(work + 0xCA0), 0x58, 27.0f);
        func_002b2a60(&sp1D0, 0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xCA0)));
        *(RGBA *)(t + 0x79) = sp1D0;
        func_002b2970(&spE8, -230.0f, 234.0f);
        func_002b2970(&spE0, 370.0f, 234.0f);
        func_002e0620(*(void **)(work + 0xCA0), spE8, spE0, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xCA8), 0x58, 26.0f);
        func_002b2a60(&sp1CC, 0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xCA8)));
        *(RGBA *)(t + 0x79) = sp1CC;
        func_002b2970(&spD8, -143.0f, 234.0f);
        func_002b2970(&spD0, (f32) 0x1C9, 234.0f);
        func_002e0620(*(void **)(work + 0xCA8), spD8, spD0, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xE98), 0x58, 27.0f);
        func_002b2a60(&sp1C8, 0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE98)));
        *(RGBA *)(t + 0x79) = sp1C8;
        func_002b2970(&spC8, (f32) 0x3CA, 121.0f);
        func_002b2970(&spC0, 370.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xE98), spC8, spC0, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xEA0), 0x58, 26.0f);
        func_002b2a60(&sp1C4, 0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xEA0)));
        *(RGBA *)(t + 0x79) = sp1C4;
        func_002b2970(&spB8, (f32) 0x421, 121.0f);
        func_002b2970(&spB0, (f32) 0x1C9, 121.0f);
        func_002e0620(*(void **)(work + 0xEA0), spB8, spB0, 0, 8, 0);
        return;
    case 1:
        func_002e0a60(*(void **)(work + 0xC9C), 0x58, 25.0f);
        func_002b2a60(&sp1C0, 0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xC9C)));
        *(RGBA *)(t + 0x79) = sp1C0;
        func_002b2970(&spA8, -230.0f, 234.0f);
        func_002b2970(&spA0, 370.0f, 234.0f);
        func_002e0620(*(void **)(work + 0xC9C), spA8, spA0, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xCA4), 0x58, 24.0f);
        func_002b2a60(&sp1BC, 0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xCA4)));
        *(RGBA *)(t + 0x79) = sp1BC;
        func_002b2970(&sp98, -143.0f, 234.0f);
        func_002b2970(&sp90, (f32) 0x1C9, 234.0f);
        func_002e0620(*(void **)(work + 0xCA4), sp98, sp90, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xE94), 0x58, 25.0f);
        func_002b2a60(&sp1B8, 0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE94)));
        *(RGBA *)(t + 0x79) = sp1B8;
        func_002b2970(&sp88, (f32) 0x3CA, 121.0f);
        func_002b2970(&sp80, 370.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xE94), sp88, sp80, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xE9C), 0x58, 24.0f);
        func_002b2a60(&sp1B4, 0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE9C)));
        *(RGBA *)(t + 0x79) = sp1B4;
        func_002b2970(&sp78, (f32) 0x421, 122.0f);
        func_002b2970(&sp70, (f32) 0x1C9, 120.0f);
        func_002e0620(*(void **)(work + 0xE9C), sp78, sp70, 0, 8, 0);
        return;
    case 2:
        func_002e0a60(*(void **)(work + 0xCB8), 0x58, 28.0f);
        ((u8 *)func_002e04e0(*(void **)(work + 0xCB8)))[0x62] = 0x7F;
        func_002b2970(&sp68, -233.0f, 225.0f);
        func_002b2970(&sp60, (f32) 0x16F, 225.0f);
        func_002e0620(*(void **)(work + 0xCB8), sp68, sp60, 0, 8, 0);
        func_002e09e0(*(void **)(work + 0xEAC), 0x58, 28.0f);
        ((u8 *)func_002e04e0(*(void **)(work + 0xEAC)))[0x62] = 0x7F;
        func_002b2970(&sp58, -146.0f, 225.0f);
        func_002b2970(&sp50, 454.0f, 225.0f);
        func_002e0620(*(void **)(work + 0xEAC), sp58, sp50, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xCBC), 0x58, 29.0f);
        ((u8 *)func_002e04e0(*(void **)(work + 0xCBC)))[0x62] = 0xFF;
        func_002b2970(&sp48, (f32) 0x3C7, 111.0f);
        func_002b2970(&sp40, (f32) 0x16F, 111.0f);
        func_002e0620(*(void **)(work + 0xCBC), sp48, sp40, 0, 8, 0);
        func_002e09e0(*(void **)(work + 0xEB0), 0x58, 29.0f);
        ((u8 *)func_002e04e0(*(void **)(work + 0xEB0)))[0x62] = 0xFF;
        func_002b2970(&sp38, (f32) 0x41E, 111.0f);
        func_002b2970(&sp30, 454.0f, 111.0f);
        func_002e0620(*(void **)(work + 0xEB0), sp38, sp30, 0, 8, 0);
        return;
    }
}

/* measured: full body reconstructed (45 u64 slots, 22 2970/0620 chains, 3-case
   switch on work[7]) with D_0063F650/D_0063F658 redeclared f32[] and read via
   `Vec2f *base = (Vec2f *)D_0063F658;` - this DOES reproduce retail's $s1 base
   hoist (frame 0x1A0, ra/s1/s0, all slot offsets byte-match; the func_002d6190
   note's d658/d650 hoist floor does not apply to this shape). Four variants,
   best nd 70 (obj 2316B vs window 2320B): every func_002e0620 site loads
   arg1/arg2 (ld sp198/sp190) BEFORE arg0 (lw 0xCE4($s0)) where retail loads
   arg0 first - a 2-instruction pre-jal ordering swap at each of 22 sites.
   func_002df4c0 (matched) has the identical call shape with u64 slots and
   retail order lw-first, so the s64-vs-u64 slot type or slot offset likely
   drives the scheduler; untested within budget. Pre-jal arg-order floor. */
/* lever-1 audit (this wave): func_002d7300 is void (void *arg0) -- confirmed
   by generated-draft call sites. D_0063F650/D_0063F658 are f32[] (matches
   the note's Vec2f*(f32[]) reading); func_002e0620 (void*,u64,u64,s32,s32,
   s16) and func_002e04e0 (void*) match m2c. No extern-width defect. */
/* MATCHED: Vec2f *base over f32[] D_0063F658/D_0063F650 reproduces the $s1 base hoist; (f32)int casts + float literals reproduce every 2970 chain. */
// FUN_002D7300
void func_002d7300(void *arg0) {
    u64 sp198;
    u64 sp190;
    u64 sp188;
    u64 sp180;
    u64 sp178;
    u64 sp170;
    u64 sp168;
    u64 sp160;
    u64 sp158;
    u64 sp150;
    u64 sp148;
    u64 sp140;
    u64 sp138;
    u64 sp130;
    u64 sp128;
    u64 sp120;
    u64 sp118;
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    u64 spD8;
    u64 spD0;
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    u64 sp30;
    u8 *work;
    Vec2f *base;
    s8 temp_4;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    func_002b2970(&sp198, 70.0f, 208.0f);
    func_002b2970(&sp190, (f32)0x29E, 208.0f);
    func_002e0620(*(void **)(work + 0xCE4), sp198, sp190, 0, 8, 0);
    func_002b2970(&sp188, (f32)0x233, 208.0f);
    func_002b2970(&sp180, (f32)0x48B, 208.0f);
    func_002e0620(*(void **)(work + 0xCE8), sp188, sp180, 0, 8, 0);
    base = (Vec2f *)D_0063F658;
    func_002b2970(&sp178, base->x, base->y);
    func_002b2970(&sp170, 600.0f + base->x, base->y);
    func_002e0620(*(void **)(work + 0xCB4), sp178, sp170, 0, 8, 0);
    func_002b2970(&sp168, 368.0f, 227.0f);
    func_002b2970(&sp160, 968.0f, 227.0f);
    func_002e0620(*(void **)(work + 0xCAC), sp168, sp160, 0, 8, 0);
    func_002b2970(&sp158, (f32)0x1C7, 227.0f);
    func_002b2970(&sp150, (f32)0x41F, 227.0f);
    func_002e0620(*(void **)(work + 0xE84), sp158, sp150, 0, 8, 0);
    func_002b2970(&sp148, 70.0f, 94.0f);
    func_002b2970(&sp140, (f32)-0x212, 94.0f);
    func_002e0620(*(void **)(work + 0xEDC), sp148, sp140, 0, 8, 0);
    func_002b2970(&sp138, (f32)0x233, 94.0f);
    func_002b2970(&sp130, -37.0f, 94.0f);
    func_002e0620(*(void **)(work + 0xEE0), sp138, sp130, 0, 8, 0);
    base = (Vec2f *)D_0063F650;
    func_002b2970(&sp128, base->x, base->y);
    func_002b2970(&sp120, base->x - 600.0f, base->y);
    func_002e0620(*(void **)(work + 0xCB0), sp128, sp120, 0, 8, 0);
    func_002b2970(&sp118, (f32)0x13D, 178.0f);
    func_002b2970(&sp110, (f32)-0x11B, 178.0f);
    func_002e0620(*(void **)(work + 0xCD0), sp118, sp110, 0, 8, 0);
    func_002b2970(&sp108, 368.0f, 113.0f);
    func_002b2970(&sp100, -232.0f, 113.0f);
    func_002e0620(*(void **)(work + 0xEA4), sp108, sp100, 0, 8, 0);
    func_002b2970(&spF8, (f32)0x1C7, 113.0f);
    func_002b2970(&spF0, -145.0f, 113.0f);
    func_002e0620(*(void **)(work + 0xEA8), spF8, spF0, 0, 8, 0);
    temp_4 = *(s8 *)(work + 7);
    switch (temp_4) {
    case 0:
        func_002b2970(&spE8, 370.0f, 234.0f);
        func_002b2970(&spE0, (f32)0x3CA, 234.0f);
        func_002e0620(*(void **)(work + 0xCA0), spE8, spE0, 0, 8, 0);
        func_002b2970(&spD8, (f32)0x1C9, 234.0f);
        func_002b2970(&spD0, (f32)0x421, 234.0f);
        func_002e0620(*(void **)(work + 0xCA8), spD8, spD0, 0, 8, 0);
        func_002b2970(&spC8, 370.0f, 121.0f);
        func_002b2970(&spC0, -230.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xE98), spC8, spC0, 0, 8, 0);
        func_002b2970(&spB8, (f32)0x1C9, 121.0f);
        func_002b2970(&spB0, -143.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xEA0), spB8, spB0, 0, 8, 0);
        return;
    case 1:
        func_002b2970(&spA8, 370.0f, 234.0f);
        func_002b2970(&spA0, (f32)0x3CA, 234.0f);
        func_002e0620(*(void **)(work + 0xC9C), spA8, spA0, 0, 8, 0);
        func_002b2970(&sp98, (f32)0x1C9, 234.0f);
        func_002b2970(&sp90, (f32)0x421, 234.0f);
        func_002e0620(*(void **)(work + 0xCA4), sp98, sp90, 0, 8, 0);
        func_002b2970(&sp88, 370.0f, 121.0f);
        func_002b2970(&sp80, -230.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xE94), sp88, sp80, 0, 8, 0);
        func_002b2970(&sp78, (f32)0x1C9, 120.0f);
        func_002b2970(&sp70, -143.0f, 122.0f);
        func_002e0620(*(void **)(work + 0xE9C), sp78, sp70, 0, 8, 0);
        return;
    case 2:
        func_002b2970(&sp68, (f32)0x16F, 225.0f);
        func_002b2970(&sp60, (f32)0x3C7, 225.0f);
        func_002e0620(*(void **)(work + 0xCB8), sp68, sp60, 0, 8, 0);
        func_002b2970(&sp58, 454.0f, 225.0f);
        func_002b2970(&sp50, (f32)0x41E, 225.0f);
        func_002e0620(*(void **)(work + 0xEAC), sp58, sp50, 0, 8, 0);
        func_002b2970(&sp48, (f32)0x16F, 111.0f);
        func_002b2970(&sp40, -233.0f, 111.0f);
        func_002e0620(*(void **)(work + 0xCBC), sp48, sp40, 0, 8, 0);
        func_002b2970(&sp38, 454.0f, 111.0f);
        func_002b2970(&sp30, -146.0f, 111.0f);
        func_002e0620(*(void **)(work + 0xEB0), sp38, sp30, 0, 8, 0);
        return;
    }
}



// FUN_002D7C10
void func_002d7c10(void *arg0, s16 arg1) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;

    r = (s32)func_0046d200(work->field_F28, 4);
    func_0046b260((u8 *)r);
    func_0046b2f0((u8 *)r);
    func_0046d280((u8 *)r);
    func_002e0940(work->field_EC4, ((ShopWork *)func_002e04e0(work->field_EC4))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EC8, ((ShopWork *)func_002e04e0(work->field_EC8))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_CC4, ((ShopWork *)func_002e04e0(work->field_CC4))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EB4, ((ShopWork *)func_002e04e0(work->field_EB4))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EB8, ((ShopWork *)func_002e04e0(work->field_EB8))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_CC0, ((ShopWork *)func_002e04e0(work->field_CC0))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EBC, ((ShopWork *)func_002e04e0(work->field_EBC))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EC0, ((ShopWork *)func_002e04e0(work->field_EC0))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_E38, ((ShopWork *)func_002e04e0(work->field_E38))->field_C4, 0.0f, 0, 2, 0);
    switch ((s32)arg1) {
    case 0:
        func_002e0940(work->field_EC4, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_EC8, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_E38, 0.0f, -3.0f, 0, 2, 0);
        break;
    case 1:
        func_002e0940(work->field_EB4, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_EB8, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_CC4, 0.0f, -3.0f, 0, 2, 0);
        break;
    case 2:
        func_002e0940(work->field_EBC, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_EC0, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_CC0, 0.0f, -3.0f, 0, 2, 0);
        break;
    }
}

// FUN_002D7F90
void func_002d7f90(void *arg0) {
    s16 v1;
    u8 *p;
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;
    s16 v2;
    u32 hi;
    f32 f1;
    f32 f20;

    p = D_0063F9F0 + (s32)*(s8 *)((u8 *)work + 7) * 12;
    r = (s32)func_0046d200(work->field_F28, 4);
    v1 = (s16)(s32)((*(f32 *)(p + 8) + func_0046b260((u8 *)r)) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_C44))->field_100 = v1;
    v2 = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_C44))->field_102 = v2;
    f1 = (f32)v1;
    v1 = (s16)(s32)(f1 - *(f32 *)(p + 8));
    ((ShopWork *)func_002e04e0(work->field_C48))->field_100 = v1;
    v2 = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_C48))->field_102 = v2;
    hi = func_003b7060() % 20U;
    f1 = (f32)hi;
    f20 = shopAdd(f1 / 10.0f, 1.0f);
    if (!(((ShopWork *)func_002e04e0(work->field_C44))->field_C4 <= 0.0f)) {
        f20 = f20 * -1.0f;
    }
    func_002e0940(work->field_C44, 0.0f, f20, 0, 0, 0);
    func_002e0940(work->field_C48, 0.0f, f20, 0, 0, 0);
    func_0046d280((u8 *)r);
}

// FUN_002D8200
void func_002d8200(void *arg0, s8 arg1) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;
    s16 v;
    f32 f20;

    func_002e04e0(work->field_E60);
    f20 = 4.0f;
    if (arg1 == 1) {
        f20 = f20 * -1.0f;
    }
    r = (s32)func_0046d200(work->field_F28, 0x7D);
    v = (s16)(s32)func_0046b260((u8 *)r);
    ((ShopWork *)func_002e04e0(work->field_E2C))->field_100 = v;
    v = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_E2C))->field_102 = v;
    ((ShopWork *)func_002e04e0(work->field_E30))->field_100 = 0;
    v = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_E30))->field_102 = v;
    func_002e0940(work->field_E2C, 0.0f, f20, 0, 4, 0);
    func_002e0940(work->field_E30, 0.0f, f20, 0, 4, 0);
    ((ShopWork *)func_002e04e0(work->field_E2C))->field_CF = 1;
    ((ShopWork *)func_002e04e0(work->field_E30))->field_CF = 1;
    func_0046d280((u8 *)r);
}


// FUN_002D83C0
void func_002d83c0(void *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;
    s16 v2;
    s16 v1;
    u32 hi;
    f32 f1;
    f32 f20;

    r = (s32)func_0046d200(work->field_F28, 4);
    v1 = (s16)(s32)((func_0046b260((u8 *)r) + 79.0f) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_ED4))->field_100 = v1;
    v2 = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_ED4))->field_102 = v2;
    v2 = (s16)(v1 - 0x4F);
    ((ShopWork *)func_002e04e0(work->field_ED8))->field_100 = v2;
    v2 = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_ED8))->field_102 = v2;
    hi = func_003b7060() % 20U;
    f1 = (f32)hi;
    f20 = shopAdd(f1 / 10.0f, 1.0f);
    if (!(((ShopWork *)func_002e04e0(work->field_ED4))->field_C4 <= 0.0f)) {
        f20 = f20 * -1.0f;
    }
    func_002e0940(work->field_ED4, 0.0f, f20, 0, 0, 0);
    func_002e0940(work->field_ED8, 0.0f, f20, 0, 0, 0);
    func_0046d280((u8 *)r);
}

// FUN_002D8600
void func_002d8600(void *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s16 i;
    u8 *t;
    Vec2f grp1;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    Vec2f grp4;
    Vec2f grp3;
    Vec2f grp2;

    func_002e04f0(work->field_CA0, 0, 1);
    func_002e04f0(work->field_CA8, 0, 1);
    func_002e04f0(work->field_C9C, 0, 1);
    func_002e04f0(work->field_CA4, 0, 1);
    func_002e04f0(work->field_CB8, 0, 1);
    func_002e04f0(work->field_EAC, 0, 1);
    for (i = 0; i < 3; i++) {
        s32 off = (s32)i * 4;
        func_002e04f0(*(void **)((u8 *)work + 0xDBC + off), 0, 1);
    }
    func_002e04f0(work->field_CAC, 0, 1);
    func_002e04f0(work->field_E84, 0, 1);
    func_002e04f0(work->field_C94, 0, 1);
    func_002e04f0(work->field_C98, 0, 1);
    t = (u8 *)func_002e04e0(work->field_E50);
    grp1 = *(Vec2f *)((u8 *)t + 0x2C);
    func_002b2970(&sp60, 740.0f + grp1.x, grp1.y);
    func_002e0620(work->field_E50, *(u64 *)&grp1, sp60, 0, 4, 0);
    t = (u8 *)func_002e04e0(work->field_E54);
    grp2 = *(Vec2f *)((u8 *)t + 0x2C);
    func_002b2970(&sp58, 740.0f + grp2.x, grp2.y);
    func_002e0620(work->field_E54, *(u64 *)&grp2, sp58, 0, 4, 0);
    t = (u8 *)func_002e04e0(work->field_E58);
    grp3 = *(Vec2f *)((u8 *)t + 0x2C);
    func_002b2970(&sp50, 740.0f + grp3.x, grp3.y);
    func_002e0620(work->field_E58, *(u64 *)&grp3, sp50, 0, 4, 0);
    t = (u8 *)func_002e04e0(work->field_E5C);
    grp4 = *(Vec2f *)((u8 *)t + 0x2C);
    func_002b2970(&sp48, 740.0f + grp4.x, grp4.y);
    func_002e0620(work->field_E5C, *(u64 *)&grp4, sp48, 0, 4, 0);
    func_002e0700(work->field_EC4, 3, fGpffff8504, 1.0f, 6, 0, 1);
    func_002e0700(work->field_EC8, 4, fGpffff8504, 1.0f, 6, 0, 1);
    func_002e0700(work->field_E38, 0x80, fGpffff8504, 1.0f, 6, 0, 1);
    func_002e0700(work->field_EB4, 3, fGpffff8504, 1.0f, 6, 1, 1);
    func_002e0700(work->field_EB8, 4, fGpffff8504, 1.0f, 6, 1, 1);
    func_002e0700(work->field_CC4, 0x23, fGpffff8504, 1.0f, 6, 1, 1);
    func_002e0700(work->field_EBC, 3, fGpffff8504, 1.0f, 6, 2, 1);
    func_002e0700(work->field_EC0, 4, fGpffff8504, 1.0f, 6, 2, 1);
    func_002e0700(work->field_CC0, 0x22, fGpffff8504, 1.0f, 6, 1, 1);
    func_002e04f0(work->field_DDC, 0, 0);
    func_002e04f0(work->field_DE4, 0, 0);
    func_002e04f0(work->field_DE0, 0, 1);
    *(s8 *)((u8 *)work + 0xC24) = 0;
}

/* measured: full m2c draft adapted (color-group chains, 46b260/2b2cb0/2a30
   calls, phantom args dropped, D_0063F9C0/C8/D0 f32[2] bases - real symbols
   here, unlike func_002da0a0 where they were mislabels) and compiles;
   nd 1196. Residual: D_0063F9C0-family base hoist into $s0 (retail lui+addiu
   once per group; mwcc rematerialises per access - cf. func_002d7300 note,
   Vec2f cast may apply), (f32)(s32) round-trip casts m2c invented on the
   temp_f2x values, and 46b260/26f0 result width handling. Hoist + cast
   floor. */
/* Wave 7 ran out of turns partway through adapting this body and left it
   uncompilable (a func_002e09e0 call with the wrong arity). Reverted. The
   wave's measured findings for this file's family are recorded above
   func_002CAEF0 and func_002D7300: the group base hoist works via a reassigned
   `Vec2f *base` local, taking func_002CAEF0 from nd 414 to 36. */
/* measured: first guarded draft from m2c 397 + rom 508 de-noised to file idiom (u8* work, s8 arg1, f32 floats, s16 FA4/FA2/FA0, u8 colors as separate bytes (pending RGBA), Vec2f via *(Vec2f*&) + u64 slots, s64 byte/counter via dsll32 idiom); fnalign retail 1421/obj 1405 (-16, -1.1% within 1378-1464) edits 949 - inside 3% gate. Frame 0x210 matches retail prologue. Prior archived high-nd note superseded for count-first floor. */
/* 2026-09-20: retail 0x002d9958-0x002d9c98 (208 instr, retail[958:1166]) is the first 8 of 11 icon arms: func_00106880 return tested against 0x81/0x102/0x204/0x408/0x810/0x1020/0x2040/0x4000 drawing icons 0x14-0x1B via func_002b2970 (var_f20, 135.0f+inner*32) + func_002e0b20 (141.0f, var_21); tail 0x8000->0x1C / 0x40000->0x1A via 002e0ca0 / else->0x1B follows. Body has all 11 arms; difflib splits them 208-vs-210 at 958-vs-945 (displacement 13, IN-PLACE per block_move_scan, ratio 0.971) so the run is recolour, not missing code. Byte table: retail reads signed bytes at +0x1168/+0x116B from computed base+index (addu $v1,$s2,$s3; lb; sll 5 for (byte<<5)+float base) where the body used *(s32*) (unaligned lwr/lwl at 0x116B) - file idiom at 5705/5721 already uses *(s8*) there. Fixed 7 lines to s8 (var_3 both bytes, temp_21 compare, 4x temp_f23 <<5, temp_20_2 compare); var_3 shift was UB (<<48 on int folds to zero, micro_codegen test_s32->move $v0,$zero) so wrote (s64)(s16)(a-b) which emits retail lb/lb/subu/dsll32/dsra32. fnalign 1421/1413 (-0.6% inside) edits 949->865, lb delta +8->matched, deficit 16->8. Remaining lbu +18 (6 early RGBA sites reload 4x stack bytes, object keeps repeated 0x2D/0x6B in regs), addu +9/sll +8 (outer *0xA0 sll2/addu/sll5 + inner *32; object uses dsll 64-bit from s64 loop vars vs retail sll 32-bit), sw +5/lwc1 +3 (sp138/sp13C float copy via lwc1/swc1 vs mov.s). */
// FUN_002D8A60 NONMATCHING
#ifdef NON_MATCHING
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x18, 0x1c, 0x20, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x4c, 0x50, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c, 0x70, 0x74, 0x78, 0x7c, 0x80, 0x84, 0x88, 0x8c, 0x90, 0x94, 0x98, 0x9c, 0xa0, 0xa4, 0xa8, 0xac, 0xb0, 0xb4, 0xb8, 0xbc, 0xc0, 0xc4], gap at: 0x28. */
void func_002d8a60(void *arg0, s8 arg1, f32 fparg0, f32 fparg1) {
    s32 sp20C;
    u8 sp1CD;
    u8 sp1CE;
    u8 sp1CF;
    u8 sp1D1;
    u8 sp1D2;
    u8 sp1D3;
    u8 sp1D5;
    u8 sp1D6;
    u8 sp1D7;
    u8 sp1D9;
    u8 sp1DA;
    u8 sp1DB;
    u8 sp1DD;
    u8 sp1DE;
    u8 sp1DF;
    u8 sp1E1;
    u8 sp1E2;
    u8 sp1E3;
    u8 sp1E5;
    u8 sp1E6;
    u8 sp1E7;
    u8 sp1E9;
    u8 sp1EA;
    u8 sp1EB;
    u8 sp1ED;
    u8 sp1EE;
    u8 sp1EF;
    u8 sp1F1;
    u8 sp1F2;
    u8 sp1F3;
    u8 sp1F5;
    u8 sp1F6;
    u8 sp1F7;
    u8 sp1F9;
    u8 sp1FA;
    u8 sp1FB;
    u8 sp1FD;
    u8 sp1FE;
    u8 sp1FF;
    u8 sp201;
    u8 sp202;
    u8 sp203;
    u8 sp205;
    u8 sp206;
    u8 sp207;
    u8 sp209;
    u8 sp20A;
    u8 sp20B;
    u8 sp208;
    u8 sp204;
    u8 sp200;
    u8 sp1FC;
    u8 sp1F8;
    u8 sp1F4;
    u8 sp1F0;
    u8 sp1EC;
    u8 sp1E8;
    u8 sp1E4;
    u8 sp1E0;
    u8 sp1DC;
    u8 sp1D8;
    u8 sp1D4;
    u8 sp1D0;
    u8 sp1CC;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    s64 sp1A8;
    s64 sp1A0;
    s64 sp198;
    s64 sp190;
    s64 sp188;
    s64 sp180;
    s64 sp178;
    s64 sp170;
    s64 sp168;
    s64 sp160;
    f32 sp158;
    f32 sp15C;
    u64 sp150;
    s64 sp148;
    u64 sp140;
    f32 sp13C;
    f32 sp138;
    s32 sp134;
    s32 sp130;
    u32 sp120;
    u8 *sp110;
    s64 sp100;
    u8 *spF0;
    u8 *spE0;
    u8 *spD0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f21_4;
    f32 temp_f21_5;
    f32 temp_f21_6;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f23_3;
    f32 temp_f23_4;
    f32 temp_f23_5;
    f32 var_f20;
    s16 temp_4;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_20;
    s32 temp_20_3;
    s32 temp_21_2;
    s32 var_21;
    s64 temp_16_3;
    s64 temp_18;
    s64 temp_20_2;
    s64 temp_21;
    s64 temp_23;
    s64 var_16;
    s64 var_22;
    s64 var_30;
    s64 var_3;
    u32 temp_16_4;
    u32 temp_2_18;
    u8 *temp_17;
    u8 *temp_18_2;
    u8 *temp_19;
    u8 *temp_2;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_17;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;

    temp_19 = *(u8**)((u8*)(arg0)+0x38);
    temp_18 = (s64) (arg1 << 0x38) >> 0x38;
    temp_16 = temp_18 * 4;
    temp_2 = temp_16 + temp_19;
    temp_20 = func_002e26f0(*(void**)((u8*)(temp_2)+0xF18));
    func_002e2700(*(void**)((u8*)(temp_2)+0xF18));
    if (D_00748908[temp_18] >= func_002e26f0(*(void**)((u8*)(temp_2)+0xF18))) {
        temp_3 = (temp_18 * 0xA0) + temp_19;
        temp_f20 = func_002b2aa0(0, fparg0, fparg1, (f32) *(s16*)((u8*)(temp_3)+0xFA2), (f32) *(s16*)((u8*)(temp_3)+0xFA0));
        *(s16*)((u8*)(temp_3)+0xFA2) = func_002b2cb0((s32) *(s16*)((u8*)(temp_3)+0xFA2), 1, (s32) *(s16*)((u8*)(temp_3)+0xFA0), 0, 1);
        if (temp_18 == *(s8*)((u8*)(temp_19)+0x11)) {
            func_002e09e0(*(void**)((u8*)(temp_19)+0xE68), 0x57, 117.0f);
            func_002b2a60(&sp208, 0x2D, 0x2D, 0x2D, 0xFF);
            temp_2_2 = func_002e04e0(*(void**)((u8*)(temp_19)+0xE68));
            *(u8*)((u8*)(temp_2_2)+0x79) = sp208;
            *(u8*)((u8*)(temp_2_2)+0x7A) = sp209;
            *(u8*)((u8*)(temp_2_2)+0x7B) = sp20A;
            *(u8*)((u8*)(temp_2_2)+0x7C) = sp20B;
            temp_f21 = *(f32*)((u8*)(D_0063F9C0)+0x4);
            *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xE68)))+0x30) = temp_f21;
            *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xE68)))+0x2C) = (f32) (86.0f + temp_f20);
            func_002e09e0(*(void**)((u8*)(temp_19)+0xE6C), 0x56, 118.0f);
            func_002b2a60(&sp204, 0x6B, 0x6B, 0x6B, 0xFF);
            temp_2_3 = func_002e04e0(*(void**)((u8*)(temp_19)+0xE6C));
            *(u8*)((u8*)(temp_2_3)+0x79) = sp204;
            *(u8*)((u8*)(temp_2_3)+0x7A) = sp205;
            *(u8*)((u8*)(temp_2_3)+0x7B) = sp206;
            *(u8*)((u8*)(temp_2_3)+0x7C) = sp207;
            temp_f21_2 = *(f32*)((u8*)(D_0063F9C8)+0x4);
            *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xE6C)))+0x30) = temp_f21_2;
            *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xE6C)))+0x2C) = (f32) (temp_f20 - 10.0f);
            func_002e09e0(*(void**)((u8*)(temp_19)+0xE70), 0x56, 119.0f);
            func_002b2a60(&sp200, 0x6B, 0x6B, 0x6B, 0xFF);
            temp_2_4 = func_002e04e0(*(void**)((u8*)(temp_19)+0xE70));
            *(u8*)((u8*)(temp_2_4)+0x79) = sp200;
            *(u8*)((u8*)(temp_2_4)+0x7A) = sp201;
            *(u8*)((u8*)(temp_2_4)+0x7B) = sp202;
            *(u8*)((u8*)(temp_2_4)+0x7C) = sp203;
            temp_f21_3 = *(f32*)((u8*)(D_0063F9D0)+0x4);
            *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xE70)))+0x30) = temp_f21_3;
            *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xE70)))+0x2C) = (f32) (440.0f + temp_f20);
            func_002e04f0(*(void**)((u8*)(temp_19)+0xDCC), 0, 1);
            func_002e04f0(*(void**)((u8*)(temp_19)+0xDD0), 0, 1);
            return;
        }
        func_002e09e0(*(void**)((u8*)(temp_19)+0xF08), 0x57, 117.0f);
        func_002b2a60(&sp1FC, 0x2D, 0x2D, 0x2D, 0xFF);
        temp_2_5 = func_002e04e0(*(void**)((u8*)(temp_19)+0xF08));
        *(u8*)((u8*)(temp_2_5)+0x79) = sp1FC;
        *(u8*)((u8*)(temp_2_5)+0x7A) = sp1FD;
        *(u8*)((u8*)(temp_2_5)+0x7B) = sp1FE;
        *(u8*)((u8*)(temp_2_5)+0x7C) = sp1FF;
        temp_f21_4 = *(f32*)((u8*)(D_0063F9C0)+0x4);
        *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xF08)))+0x30) = temp_f21_4;
        *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xF08)))+0x2C) = (f32) (86.0f + temp_f20);
        func_002e09e0(*(void**)((u8*)(temp_19)+0xF0C), 0x56, 118.0f);
        func_002b2a60(&sp1F8, 0x6B, 0x6B, 0x6B, 0xFF);
        temp_2_6 = func_002e04e0(*(void**)((u8*)(temp_19)+0xF0C));
        *(u8*)((u8*)(temp_2_6)+0x79) = sp1F8;
        *(u8*)((u8*)(temp_2_6)+0x7A) = sp1F9;
        *(u8*)((u8*)(temp_2_6)+0x7B) = sp1FA;
        *(u8*)((u8*)(temp_2_6)+0x7C) = sp1FB;
        temp_f21_5 = *(f32*)((u8*)(D_0063F9C8)+0x4);
        *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xF0C)))+0x30) = temp_f21_5;
        *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xF0C)))+0x2C) = (f32) (temp_f20 - 10.0f);
        func_002e09e0(*(void**)((u8*)(temp_19)+0xF10), 0x56, 119.0f);
        func_002b2a60(&sp1F4, 0x6B, 0x6B, 0x6B, 0xFF);
        temp_2_7 = func_002e04e0(*(void**)((u8*)(temp_19)+0xF10));
        *(u8*)((u8*)(temp_2_7)+0x79) = sp1F4;
        *(u8*)((u8*)(temp_2_7)+0x7A) = sp1F5;
        *(u8*)((u8*)(temp_2_7)+0x7B) = sp1F6;
        *(u8*)((u8*)(temp_2_7)+0x7C) = sp1F7;
        temp_f21_6 = *(f32*)((u8*)(D_0063F9D0)+0x4);
        *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xF10)))+0x30) = temp_f21_6;
        *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xF10)))+0x2C) = (f32) (440.0f + temp_f20);
        func_002e04f0(*(void**)((u8*)(temp_19)+0xEE4), 0, 1);
        func_002e04f0(*(void**)((u8*)(temp_19)+0xEE8), 0, 1);
        return;
    }
    func_002b2cb0(0, temp_20, 5, 0, 1);
    temp_3_2 = temp_18 + temp_19;
    var_3 = (s64)(s16)(*(s8*)((u8*)(temp_3_2)+0x1168) - *(s8*)((u8*)(temp_3_2)+0x116B));
    if (var_3 < 0) {
        var_3 = 0;
    }
    var_22 = (s64) (var_3 << 0x30) >> 0x30;
    var_30 = 0;
    temp_23 = (s64) (arg1 << 0x38) >> 0x38;
    sp110 = (temp_19 + (temp_23 * 0xA0));
    temp_18_2 = temp_19 + temp_23;
    temp_17 = temp_19 + temp_16;
    sp100 = var_22 + 5;
loop_53:
    temp_20_2 = (s64) (var_22 << 0x30) >> 0x30;
    if (temp_20_2 < sp100) {
        var_f20 = fparg0;
        temp_21 = (s64) (var_30 << 0x30) >> 0x30;
        temp_16_2 = temp_21 << 5;
        temp_3_3 = sp110 + temp_16_2;
        spF0 = temp_3_3 + 0xFA4;
        temp_4 = *(s16*)((u8*)(temp_3_3)+0xFA4);
        if (temp_4 > 0) {
            *spF0 = func_002b2d00((s32) temp_4, 1, 0, 0, 1);
        } else {
            spE0 = (temp_3_3 + 0xFA0);
            spD0 = (temp_3_3 + 0xFA2);
            var_f20 = func_002b2aa0(0, fparg0, fparg1, (f32) *(s16*)((u8*)(temp_3_3)+0xFA2), (f32) *(s16*)((u8*)(temp_3_3)+0xFA0));
            *spD0 = func_002b2cb0((s32) *(s16*)((u8*)(temp_3_3)+0xFA2), 1, (s32) *(s16*)((u8*)(temp_3_3)+0xFA0), 0, 1);
        }
        if (temp_21 == *(s8*)((u8*)(temp_18_2)+0x116B)) {
            if (temp_23 == *(s8*)((u8*)(temp_19)+0x11)) {
                func_002e09e0(*(void**)((u8*)(temp_19)+0xDCC), 0x41, 143.0f);
                func_002b2a60(&sp1F0, 0xFE, 0xC6, 0x31, 0xFF);
                temp_2_8 = func_002e04e0(*(void**)((u8*)(temp_19)+0xDCC));
                *(u8*)((u8*)(temp_2_8)+0x79) = sp1F0;
                *(u8*)((u8*)(temp_2_8)+0x7A) = sp1F1;
                *(u8*)((u8*)(temp_2_8)+0x7B) = sp1F2;
                *(u8*)((u8*)(temp_2_8)+0x7C) = sp1F3;
                *(u8*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xDCC)))+0x62) = 0xFF;
                temp_f23 = *(f32*)((u8*)(D_0063F888)+0x4) + (f32) (*(s8*)((u8*)(temp_18_2)+0x116B) << 5);
                *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xDCC)))+0x30) = temp_f23;
                *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xDCC)))+0x2C) = (f32) (var_f20 - 10.0f);
                func_002e09e0(*(void**)((u8*)(temp_19)+0xDD0), 0x41, 143.0f);
                func_002b2a60(&sp1EC, 0xFE, 0xC6, 0x31, 0xFF);
                temp_2_9 = func_002e04e0(*(void**)((u8*)(temp_19)+0xDD0));
                *(u8*)((u8*)(temp_2_9)+0x79) = sp1EC;
                *(u8*)((u8*)(temp_2_9)+0x7A) = sp1ED;
                *(u8*)((u8*)(temp_2_9)+0x7B) = sp1EE;
                *(u8*)((u8*)(temp_2_9)+0x7C) = sp1EF;
                *(u8*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xDD0)))+0x62) = 0xFF;
                temp_f23_2 = *(f32*)((u8*)(D_0063F888)+0x4) + (f32) (*(s8*)((u8*)(temp_18_2)+0x116B) << 5);
                *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xDD0)))+0x30) = temp_f23_2;
                *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xDD0)))+0x2C) = (f32) (444.0f + var_f20);
                func_002e04f0(*(void**)((u8*)(temp_19)+0xE68), 0, 1);
                func_002e04f0(*(void**)((u8*)(temp_19)+0xE6C), 0, 1);
                func_002e04f0(*(void**)((u8*)(temp_19)+0xE70), 0, 1);
            } else {
                func_002e09e0(*(void**)((u8*)(temp_19)+0xEE4), 0x41, 143.0f);
                func_002b2a60(&sp1E8, 0xFE, 0xC6, 0x31, 0xFF);
                temp_2_10 = func_002e04e0(*(void**)((u8*)(temp_19)+0xEE4));
                *(u8*)((u8*)(temp_2_10)+0x79) = sp1E8;
                *(u8*)((u8*)(temp_2_10)+0x7A) = sp1E9;
                *(u8*)((u8*)(temp_2_10)+0x7B) = sp1EA;
                *(u8*)((u8*)(temp_2_10)+0x7C) = sp1EB;
                *(u8*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xEE4)))+0x62) = 0xFF;
                temp_f23_3 = *(f32*)((u8*)(D_0063F888)+0x4) + (f32) (*(s8*)((u8*)(temp_18_2)+0x116B) << 5);
                *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xEE4)))+0x30) = temp_f23_3;
                *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xEE4)))+0x2C) = (f32) (var_f20 - 10.0f);
                func_002e09e0(*(void**)((u8*)(temp_19)+0xEE8), 0x41, 143.0f);
                func_002b2a60(&sp1E4, 0xFE, 0xC6, 0x31, 0xFF);
                temp_2_11 = func_002e04e0(*(void**)((u8*)(temp_19)+0xEE8));
                *(u8*)((u8*)(temp_2_11)+0x79) = sp1E4;
                *(u8*)((u8*)(temp_2_11)+0x7A) = sp1E5;
                *(u8*)((u8*)(temp_2_11)+0x7B) = sp1E6;
                *(u8*)((u8*)(temp_2_11)+0x7C) = sp1E7;
                *(u8*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xEE8)))+0x62) = 0xFF;
                temp_f23_4 = *(f32*)((u8*)(D_0063F888)+0x4) + (f32) (*(s8*)((u8*)(temp_18_2)+0x116B) << 5);
                *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xEE8)))+0x30) = temp_f23_4;
                *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xEE8)))+0x2C) = (f32) (444.0f + var_f20);
                func_002e04f0(*(void**)((u8*)(temp_19)+0xF08), 0, 1);
                func_002e04f0(*(void**)((u8*)(temp_19)+0xF0C), 0, 1);
                func_002e04f0(*(void**)((u8*)(temp_19)+0xF10), 0, 1);
            }
        }
        if (temp_20_2 < func_002e26f0(*(void**)((u8*)(temp_17)+0xF18))) {
            sp134 = func_002b2a30(0xFFU, 0xAEU, 0U, 0xFFU);
            var_21 = func_002b2a30(0U, 0xFFU, 0xAEU, 0U);
            func_002b2a60(&sp20C, 0xFF, 0xAE, 0, 0xFF);
            sp130 = func_002b2a30(0U, 0xFEU, 0xC7U, 0x31U);
            if (temp_20_2 == *(s8*)((u8*)(temp_18_2)+0x1168)) {
                sp134 = func_002b2a30(0x2DU, 0x2DU, 0x2DU, 0xFFU);
                var_21 = func_002b2a30(0U, 0x2DU, 0x2DU, 0x2DU);
                func_002b2a60(&sp20C, 0x2D, 0x2D, 0x2D, 0xFF);
                sp130 = func_002b2a30(0U, 0x2DU, 0x2DU, 0x2DU);
            }
            if ((temp_23 == 0) && (temp_20_2 == 0)) {
                if (func_002e26f0(*(void**)((u8*)(temp_17)+0xF18)) >= 2) {
                    var_16 = 0;
loop_22:
                    if (((s64) (var_16 << 0x30) >> 0x30) < 3) {
                        temp_21_2 = ((s64) (var_16 << 0x30) >> 0x30) << 5;
                        func_002b2970(&sp1C0, 31.0f + var_f20 + (f32) temp_21_2, 143.0f);
                        func_002e0b20(0x3C, *(Vec2f*)&sp1C0, 141.0f, sp130, 0xFFU, 0, D_00795E60);
                        func_002b2970(&sp1B8, (f32) 0x151 + var_f20 + (f32) temp_21_2, 143.0f);
                        func_002e0b20(0x3C, *(Vec2f*)&sp1B8, 141.0f, sp130, 0xFFU, 0, D_00795E60);
                        var_16 = (s64) ((var_16 + 1) << 0x30) >> 0x30;
                        goto loop_22;
                    }
                    func_002e09e0(*(void**)((u8*)(temp_19)+0xE44), 0x56, 142.0f);
                    func_002b2a60(&sp1E0, 0xFE, 0xC7, 0x31, 0xFF);
                    temp_2_12 = func_002e04e0(*(void**)((u8*)(temp_19)+0xE44));
                    *(u8*)((u8*)(temp_2_12)+0x79) = sp1E0;
                    *(u8*)((u8*)(temp_2_12)+0x7A) = sp1E1;
                    *(u8*)((u8*)(temp_2_12)+0x7B) = sp1E2;
                    *(u8*)((u8*)(temp_2_12)+0x7C) = sp1E3;
                    if (temp_20_2 == *(s16*)((u8*)(temp_19)+0x2)) {
                        func_002b2a60(&sp1DC, 0x2D, 0x2D, 0x2D, 0xFF);
                        temp_2_13 = func_002e04e0(*(void**)((u8*)(temp_19)+0xE44));
                        *(u8*)((u8*)(temp_2_13)+0x79) = sp1DC;
                        *(u8*)((u8*)(temp_2_13)+0x7A) = sp1DD;
                        *(u8*)((u8*)(temp_2_13)+0x7B) = sp1DE;
                        *(u8*)((u8*)(temp_2_13)+0x7C) = sp1DF;
                    }
                    *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xE44)))+0x2C) = (f32) (128.0f + var_f20);
                    func_002e09e0(*(void**)((u8*)(temp_19)+0xE48), 0x56, 142.0f);
                    func_002b2a60(&sp1D8, 0xFE, 0xC7, 0x31, 0xFF);
                    temp_2_14 = func_002e04e0(*(void**)((u8*)(temp_19)+0xE48));
                    *(u8*)((u8*)(temp_2_14)+0x79) = sp1D8;
                    *(u8*)((u8*)(temp_2_14)+0x7A) = sp1D9;
                    *(u8*)((u8*)(temp_2_14)+0x7B) = sp1DA;
                    *(u8*)((u8*)(temp_2_14)+0x7C) = sp1DB;
                    if (temp_20_2 == *(s16*)((u8*)(temp_19)+0x2)) {
                        func_002b2a60(&sp1D4, 0x2D, 0x2D, 0x2D, 0xFF);
                        temp_2_15 = func_002e04e0(*(void**)((u8*)(temp_19)+0xE48));
                        *(u8*)((u8*)(temp_2_15)+0x79) = sp1D4;
                        *(u8*)((u8*)(temp_2_15)+0x7A) = sp1D5;
                        *(u8*)((u8*)(temp_2_15)+0x7B) = sp1D6;
                        *(u8*)((u8*)(temp_2_15)+0x7C) = sp1D7;
                    }
                    *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xE48)))+0x2C) = (f32) ((f32) 0x133 + var_f20);
                    func_002e09e0(*(void**)((u8*)(temp_19)+0xE40), 0x57, 141.0f);
                    func_002b2a60(&sp1D0, 0x2D, 0x2D, 0x2D, 0xFF);
                    temp_2_16 = func_002e04e0(*(void**)((u8*)(temp_19)+0xE40));
                    *(u8*)((u8*)(temp_2_16)+0x79) = sp1D0;
                    *(u8*)((u8*)(temp_2_16)+0x7A) = sp1D1;
                    *(u8*)((u8*)(temp_2_16)+0x7B) = sp1D2;
                    *(u8*)((u8*)(temp_2_16)+0x7C) = sp1D3;
                    if (temp_20_2 == *(s16*)((u8*)(temp_19)+0x2)) {
                        func_002b2a60(&sp1CC, 0xFE, 0xC7, 0x31, 0xFF);
                        temp_2_17 = func_002e04e0(*(void**)((u8*)(temp_19)+0xE40));
                        *(u8*)((u8*)(temp_2_17)+0x79) = sp1CC;
                        *(u8*)((u8*)(temp_2_17)+0x7A) = sp1CD;
                        *(u8*)((u8*)(temp_2_17)+0x7B) = sp1CE;
                        *(u8*)((u8*)(temp_2_17)+0x7C) = sp1CF;
                    }
                    *(f32*)((u8*)(func_002e04e0(*(void**)((u8*)(temp_19)+0xE40)))+0x2C) = (f32) (144.0f + var_f20);
                }
            } else {
                temp_2_18 = func_00106880((s16) ((s64) (func_002e2830(*(void**)((u8*)(temp_17)+0xF18), (s32) temp_20_2) << 0x30) >> 0x30));
                if (temp_2_18 & 0x81) {
                    func_002b2970(&sp1B0, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0b20(0x14, *(Vec2f*)&sp1B0, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else if (temp_2_18 & 0x102) {
                    func_002b2970(&sp1A8, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0b20(0x15, *(Vec2f*)&sp1A8, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else if (temp_2_18 & 0x204) {
                    func_002b2970(&sp1A0, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0b20(0x16, *(Vec2f*)&sp1A0, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else if (temp_2_18 & 0x408) {
                    func_002b2970(&sp198, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0b20(0x17, *(Vec2f*)&sp198, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else if (temp_2_18 & 0x810) {
                    func_002b2970(&sp190, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0b20(0x18, *(Vec2f*)&sp190, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else if (temp_2_18 & 0x1020) {
                    func_002b2970(&sp188, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0b20(0x19, *(Vec2f*)&sp188, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else if (temp_2_18 & 0x2040) {
                    func_002b2970(&sp180, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0b20(0x1A, *(Vec2f*)&sp180, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else if (temp_2_18 & 0x4000) {
                    func_002b2970(&sp178, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0b20(0x1B, *(Vec2f*)&sp178, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else if (temp_2_18 & 0x8000) {
                    func_002b2970(&sp170, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0b20(0x1C, *(Vec2f*)&sp170, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else if (temp_2_18 & 0x40000) {
                    func_002b2970(&sp168, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0ca0(0x1A, *(Vec2f*)&sp168, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                } else {
                    func_002b2970(&sp160, var_f20, 135.0f + (f32) temp_16_2);
                    func_002e0ca0(0x1B, *(Vec2f*)&sp160, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                }
                temp_20_3 = ((s64) (var_30 << 0x30) >> 0x30) << 5;
                func_002b2970(&sp158, 43.0f + var_f20, 133.0f + (f32) temp_20_3);
                sp138 = sp158;
                sp13C = sp15C;
                temp_16_3 = (s64) (var_22 << 0x30) >> 0x30;
                func_00275680(sp138, sp13C, 141.0f, sp134, 0, 1, func_001067f0((s32) ((s64) (func_002e2830(*(void**)((u8*)(temp_17)+0xF18), (s32) temp_16_3) << 0x30) >> 0x30)), 0, 0, D_00795E30, -1);
                sp120 = func_00106a90((s16) ((s64) (func_002e2830(*(void**)((u8*)(temp_17)+0xF18), (s32) temp_16_3) << 0x30) >> 0x30)) / 5U;
                temp_f23_5 = 142.0f + (f32) temp_20_3;
                func_002b2970(&sp150, 362.0f + var_f20, temp_f23_5);
                func_002cacd0(sp150, 141.0f, *(RGBA*)&sp20C, 0x10, 5, sp120, 9, 0x7B, (s32)func_0046a770(D_0063FB50), (s32) (s64) *(s32*)((u8*)(temp_19)+0xF28), 0xA9);
                func_002b2970(&sp148, 390.0f + var_f20, 144.0f + (f32) temp_20_3);
                func_002e0b20(0x47, *(Vec2f*)&sp148, 141.0f, var_21, 0xFFU, 0, D_00795E60);
                func_002b2970(&sp140, (f32) 0x1A5 + var_f20, temp_f23_5);
                temp_16_4 = func_00106600((s16) ((s64) (func_002e2830(*(void**)((u8*)(temp_17)+0xF18), (s32) temp_16_3) << 0x30) >> 0x30)) & 0xFF;
                func_002cacd0(sp140, 141.0f, *(RGBA*)&sp20C, 0x10, 5, temp_16_4, 9, 0x7B, (s32)func_0046a770(D_0063FB50), (s32) (s64) *(s32*)((u8*)(temp_19)+0xF28), 0xA9);
            }
        }
        var_22 = (s64) ((var_22 + 1) << 0x30) >> 0x30;
        var_30 = (s64) ((var_30 + 1) << 0x30) >> 0x30;
        goto loop_53;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d8a60);
#endif

/* Archived C reconstruction: build/W8ShopRGBA_func_002da0a0_highnd.c.
   Best measured candidate object 5032/window 4960, normalized_diff 3080;
   bare INCLUDE_ASM restored after ruled-out source-shape probes. */
/* measured 002da0a0 (owner, installing archived high-nd body adapted): 1260 against retail's 1240
   (+1.6%, band 1203-1277), 1199 edits (+2 reloc-only), 1060 differing words. Frame -0x170
   against retail -0x160; calls 150 against 151, the gap a single 11-instruction hole at
   retail[209:220] (the ED4 func_002e04e0 + RGBA byte store the archived body never had); one
   4-instruction object lump at object[173:177] (signed s8-to-float scheduling at the 35.0f
   sites). Adapted from build/W8ShopRGBA_func_002da0a0_highnd.c (296-line body, 5032B/window
   4960, nd 3080): the only change is fGpffff7afc to the owner's fGpffff7ad4, matching retail's
   lwc1 -0x7AD4($gp) at both 002e0940 sites (0x1DA808/0x1DA918) and already used the same way at
   line 956; the archived symbol was a mislabel as the file's own notes warn. Residuals stay as
   archived: D_0063F5B8/F65x base hoist into $s1 and (s64)(s32) width casts on 46b260/46b2f0. */
// FUN_002DA0A0 NONMATCHING
#ifdef NON_MATCHING
void func_002da0a0(register u8 *root) {
    RGBA c0;
    RGBA c1;
    RGBA c2;
    RGBA c3;
    RGBA c4;
    RGBA c5;
    RGBA c6;
    RGBA c7;
    RGBA c8;
    RGBA c9;
    RGBA c10;
    RGBA c11;
    u64 sp128;
    u64 sp120;
    u64 sp118;
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    u64 spD8;
    u64 spD0;
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 f1;
    f32 f20;
    s64 width0;
    s64 width1;
    s64 i;
    s32 hi;
    register u8 *work;
    void *r;
    Vec2f *base;
    u8 *t;
    work = *(u8 **)(root + 0x38);
    func_002e04f0(*(void **)(work + 0xDEC), 0, 1);

    base = (Vec2f *)D_0063F5A0;
    func_002e09e0(*(void **)(work + 0xC58), 0x41, 162.0f);
    func_002b2970(&sp128, base->x, base->y - 450.0f);
    func_002b2970(&sp120, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC58), sp128, sp120, 0, 4, 0);
    func_002e0660(*(void **)(work + 0xC58), 0, 0xCC, 0, 2, 0);
    func_002b2a60(&c0, 0, 0, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xC58));
    *(RGBA *)(t + 0x79) = c0;

    base = (Vec2f *)D_0063F5A8;
    func_002e09e0(*(void **)(work + 0xC5C), 0x41, 163.0f);
    func_002b2970(&sp118, base->x, base->y - 450.0f);
    func_002b2970(&sp110, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC5C), sp118, sp110, 0, 4, 0);
    func_002e0660(*(void **)(work + 0xC5C), 0, 0xCC, 0, 2, 0);
    func_002b2a60(&c1, 0, 0, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xC5C));
    *(RGBA *)(t + 0x79) = c1;

    i = 0;
    while ((s16)i < *(s8 *)(work + 9)) {
        *(s16 *)((u8 *)work + ((s16)i * 2) + 0xF46) = 0;
        *(s16 *)((u8 *)work + ((s16)i * 2) + 0xF58) = 0;
        *(s8 *)((u8 *)work + (s16)i + 0xF6A) = 0;
        i++;
    }

    func_002e09e0(*(void **)(work + 0xED4), 0x41, 126.0f);
    func_002b2970(&sp108, 47.0f,
                  (78.0f + 35.0f * (f32)*(s8 *)(work + 8)) - 450.0f);
    func_002b2970(&sp100, 47.0f,
                  78.0f + 35.0f * (f32)*(s8 *)(work + 8));
    func_002e0620(*(void **)(work + 0xED4), sp108, sp100, 0, 6,
                  *(s16 *)((u8 *)work + ((s32)(s8)*(s8 *)(work + 8) * 2) + 0xF46));
    func_002b2a60(&c2, 0xFE, 0xC6, 0x31, 0xFF);
    func_002e09e0(*(void **)(work + 0xED8), 0x41, 127.0f);
    func_002b2a60(&c3, 0xFE, 0xC6, 0x31, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xED8));
    *(RGBA *)(t + 0x79) = c3;
    func_002b2970(&spF8, 126.0f,
                  (78.0f + 35.0f * (f32)*(s8 *)(work + 8)) - 450.0f);
    func_002b2970(&spF0, 126.0f,
                  78.0f + 35.0f * (f32)*(s8 *)(work + 8));
    func_002e0620(*(void **)(work + 0xED8), spF8, spF0, 0, 6, 0);
    root = *(u8 **)(root + 0x38);
    r = func_0046d200(*(void **)((u8 *)root + 0xF28), 4);
    width0 = (s64)((79.0f + func_0046b260(r)) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)((u8 *)root + 0xED4)) + 0x100) =
        (s16)width0;
    width1 = (s64)(func_0046b2f0(r) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)((u8 *)root + 0xED4)) + 0x102) =
        (s16)width1;
    width0 = width0 - 79;
    *(s16 *)((u8 *)func_002e04e0(*(void **)((u8 *)root + 0xED8)) + 0x100) =
        (s16)width0;
    width1 = (s64)(func_0046b2f0(r) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)((u8 *)root + 0xED8)) + 0x102) =
        (s16)width1;

    hi = (s32)(func_003b7060() % 20U);
    if (hi >= 0) {
        f1 = (f32)hi;
    } else {
        f1 = 2.0f * (f32)((hi >> 1) | (hi & 1));
    }
    f20 = shopAdd(f1 / 10.0f, 1.0f);
    if (*(f32 *)((u8 *)func_002e04e0(*(void **)((u8 *)root + 0xED4)) + 0xC4) > 0.0f) {
        f20 = f20 * -1.0f;
    }
    func_002e0940(*(void **)((u8 *)root + 0xED4), 0.0f, f20, 0, 0, 0);
    func_002e0940(*(void **)((u8 *)root + 0xED8), 0.0f, f20, 0, 0, 0);
    func_0046d280(r);

    func_002e09e0(*(void **)(work + 0xD3C), 0x41, 128.0f);
    func_002e0660(*(void **)(work + 0xD3C), 0, 0xFF, 0, 0xA, 0);

    base = (Vec2f *)D_0063F7B0;
    func_002e09e0(*(void **)(work + 0xD60), 0x41, 78.0f);
    func_002b2970(&spE8, base->x, base->y - 550.0f);
    func_002b2970(&spE0, base->x, base->y);
    func_002e0620(*(void **)(work + 0xD60), spE8, spE0, 2, 4, 0);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD60)) + 0x102) = 0;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD60)) + 0x100) = 0;
    func_002e0940(*(void **)(work + 0xD60), -5.0f, fGpffff7ad4, 2, 2, 2);
    func_002b2a60(&c4, 0xFF, 0x96, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD60));
    *(RGBA *)(t + 0x79) = c4;

    base = (Vec2f *)D_0063F7B8;
    func_002e09e0(*(void **)(work + 0xD64), 0x41, 78.0f);
    func_002b2970(&spD8, base->x, base->y - 550.0f);
    func_002b2970(&spD0, base->x, base->y);
    func_002e0620(*(void **)(work + 0xD64), spD8, spD0, 2, 4, 0);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD64)) + 0x100) = -50;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD64)) + 0x102) = -219;
    func_002e0940(*(void **)(work + 0xD64), -5.0f, fGpffff7ad4, 2, 2, 2);
    func_002b2a60(&c5, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD64));
    *(RGBA *)(t + 0x79) = c5;

    func_002e09e0(*(void **)(work + 0xDE8), 0x41, 46.0f);
    func_002e0660(*(void **)(work + 0xDE8), 0, 0xFF, 0, 6, 0);
    base = (Vec2f *)D_0063F8C0;
    temp_f20 = base->x;
    t = (u8 *)func_002e04e0(*(void **)(work + 0xDE8));
    *(f32 *)(t + 0x2C) = temp_f20;
    temp_f20_2 = base->y;
    t = (u8 *)func_002e04e0(*(void **)(work + 0xDE8));
    *(f32 *)(t + 0x30) = temp_f20_2;

    func_002e09e0(*(void **)(work + 0xDF0), 0x41, 47.0f);
    func_002e0660(*(void **)(work + 0xDF0), 0, 0xFF, 0, 6, 0);

    r = func_0046d200(*(void **)(work + 0xF28), 0x44);
    base = (Vec2f *)D_0063F780;
    func_002e09e0(*(void **)(work + 0xD48), 0x56, 53.0f);
    func_002b2970(&spC8, base->x, -130.0f);
    func_002b2970(&spC0, base->x, base->y);
    func_002e0620(*(void **)(work + 0xD48), spC8, spC0, 2, 5, 0);
    func_002b2a60(&c6, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD48));
    *(RGBA *)(t + 0x79) = c6;
    temp_f20 = (func_0046b260(r)) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0x100) =
        (s16)temp_f20;
    temp_f20 = (func_0046b2f0(r)) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0x102) =
        (s16)temp_f20;
    func_002e09b0(*(void **)(work + 0xD48), D_0063FA46,
                  (f32)D_0063FA44);
    func_002e0940(*(void **)(work + 0xD48), D_0063FA40, 0.0f,
                  2, D_0063FA46 + 5, 0);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x43);
    base = (Vec2f *)D_0063F778;
    func_002e09e0(*(void **)(work + 0xD44), 0x56, 54.0f);
    func_002b2970(&spB8, base->x, -189.0f);
    func_002b2970(&spB0, base->x, base->y);
    func_002e0620(*(void **)(work + 0xD44), spB8, spB0, 2, 5, 3);
    func_002b2a60(&c7, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD44));
    *(RGBA *)(t + 0x79) = c7;
    temp_f20 = func_0046b260(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD44)) + 0x100) =
        (s16)temp_f20;
    temp_f20 = func_0046b2f0(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD44)) + 0x102) =
        (s16)temp_f20;
    func_002e09b0(*(void **)(work + 0xD44), *(s16 *)(D_0063FA48 + 6),
                  (f32)*(s16 *)(D_0063FA48 + 4));
    func_002e0940(*(void **)(work + 0xD44), *(f32 *)D_0063FA48, 0.0f,
                  2, *(s16 *)(D_0063FA48 + 6) + 5, 3);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x45);
    base = (Vec2f *)D_0063F788;
    func_002e09e0(*(void **)(work + 0xD4C), 0x56, 55.0f);
    func_002b2970(&spA8, base->x, -75.0f);
    func_002b2970(&spA0, base->x, base->y);
    func_002e0620(*(void **)(work + 0xD4C), spA8, spA0, 2, 5, 1);
    func_002b2a60(&c8, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD4C));
    *(RGBA *)(t + 0x79) = c8;
    temp_f20 = func_0046b260(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD4C)) + 0x100) =
        (s16)temp_f20;
    temp_f20 = func_0046b2f0(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD4C)) + 0x102) =
        (s16)temp_f20;
    func_002e09b0(*(void **)(work + 0xD4C), *(s16 *)(D_0063FA50 + 6),
                  (f32)*(s16 *)(D_0063FA50 + 4));
    func_002e0940(*(void **)(work + 0xD4C), *(f32 *)D_0063FA50, 0.0f,
                  2, *(s16 *)(D_0063FA50 + 6) + 5, 1);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x46);
    base = (Vec2f *)D_0063F790;
    func_002e09e0(*(void **)(work + 0xD50), 0x56, 56.0f);
    func_002b2970(&sp98, base->x, -165.0f);
    func_002b2970(&sp90, base->x, base->y);
    func_002e0620(*(void **)(work + 0xD50), sp98, sp90, 2, 5, 4);
    func_002b2a60(&c9, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD50));
    *(RGBA *)(t + 0x79) = c9;
    temp_f20 = func_0046b260(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0x100) =
        (s16)temp_f20;
    temp_f20 = func_0046b2f0(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0x102) =
        (s16)temp_f20;
    *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0xC4) = 0.0f;
    func_002e09b0(*(void **)(work + 0xD50), *(s16 *)(D_0063FA58 + 6),
                  (f32)*(s16 *)(D_0063FA58 + 4));
    func_002e0940(*(void **)(work + 0xD50), *(f32 *)D_0063FA58, 0.0f,
                  2, *(s16 *)(D_0063FA58 + 6) + 5, 4);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x47);
    base = (Vec2f *)D_0063F798;
    func_002e09e0(*(void **)(work + 0xD54), 0x56, 57.0f);
    func_002b2970(&sp88, base->x, -126.0f);
    func_002b2970(&sp80, base->x, base->y);
    func_002e0620(*(void **)(work + 0xD54), sp88, sp80, 2, 5, 2);
    func_002b2a60(&c10, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD54));
    *(RGBA *)(t + 0x79) = c10;
    temp_f20 = func_0046b260(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0x100) =
        (s16)temp_f20;
    temp_f20 = func_0046b2f0(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0x102) =
        (s16)temp_f20;
    *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0xC4) = 0.0f;
    func_002e09b0(*(void **)(work + 0xD54), *(s16 *)(D_0063FA60 + 6),
                  (f32)*(s16 *)(D_0063FA60 + 4));
    func_002e0940(*(void **)(work + 0xD54), *(f32 *)D_0063FA60, 0.0f,
                  1, *(s16 *)(D_0063FA60 + 6) + 5, 2);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x48);
    base = (Vec2f *)D_0063F7A0;
    func_002e09e0(*(void **)(work + 0xD58), 0x56, 58.0f);
    func_002b2970(&sp78, base->x, -197.0f);
    func_002b2970(&sp70, base->x, base->y);
    func_002e0620(*(void **)(work + 0xD58), sp78, sp70, 2, 5, 5);
    func_002b2a60(&c11, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD58));
    *(RGBA *)(t + 0x79) = c11;
    temp_f20 = func_0046b260(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0x100) =
        (s16)temp_f20;
    temp_f20 = func_0046b2f0(r) / 2.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0x102) =
        (s16)temp_f20;
    *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0xC4) = 0.0f;
    func_002e09b0(*(void **)(work + 0xD58), *(s16 *)(D_0063FA68 + 6),
                  (f32)*(s16 *)(D_0063FA68 + 4));
    func_002e0940(*(void **)(work + 0xD58), *(f32 *)D_0063FA68, 0.0f,
                  2, *(s16 *)(D_0063FA68 + 6) + 5, 5);
    func_0046d280(r);
    *(s8 *)work = 0x14;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002da0a0);
#endif

/* measured: full m2c draft adapted (40 2970 chains, 46b200/46b260/46b2f0/
   46d280 handle calls, FA70-FA98 f32[2] bases, phantom args dropped) and
   compiles; nd 1663. Residual: D_0063F5B8/F65x base hoist into $s1 per group
   (retail lwc1 0/4($s1); mwcc lui+lwc1 per access - cf. func_002d7300 note),
   plus m2c's (s64)(s32) return-width casts on 46b260/46b2f0 and the 26f0
   sign-extension split. Hoist + width floor. */
/* measured 002db400 (owner, m2c-adapted floor cand3): 1983 against retail's 1932
   (+2.6%, band 1874-1990), 1744 edits, 1657 differing words. Frame/calls/transfers
   to be confirmed after install; candidate calls 254 matching retail 254, lwc1 13 /
   swc1 2 / madd 0, no HW. Adapted from build/m2c/func_002db400.c with RGBA+cN,
   Vec2f base hoist, (s16) width casts, D_00748908 array for 08/09/0A. */
// FUN_002DB400 NONMATCHING
#ifdef NON_MATCHING
void func_002db400(void *arg0) {
    extern u8 D_0063FA70[];
    extern u8 D_0063FA78[];
    extern u8 D_0063FA80[];
    extern u8 D_0063FA88[];
    extern u8 D_0063FA90[];
    extern u8 D_0063FA98[];
    void func_002e3560(void *, s32, s32, s32, s32);
    RGBA c0;
    RGBA c1;
    RGBA c2;
    RGBA c3;
    RGBA c4;
    RGBA c5;
    RGBA c6;
    RGBA c7;
    RGBA c8;
    RGBA c9;
    RGBA c10;
    RGBA c11;
    RGBA c12;
    RGBA c13;
    RGBA c14;
    RGBA c15;
    RGBA c16;
    RGBA c17;
    RGBA c18;
    RGBA c19;
    RGBA c20;
    RGBA c21;
    RGBA c22;
    RGBA c23;
    RGBA c24;
    RGBA c25;
    RGBA c26;
    u64 sp198;
    u64 sp190;
    u64 sp188;
    u64 sp180;
    u64 sp178;
    u64 sp170;
    u64 sp168;
    u64 sp160;
    u64 sp158;
    u64 sp150;
    u64 sp148;
    u64 sp140;
    u64 sp138;
    u64 sp130;
    u64 sp128;
    u64 sp120;
    u64 sp118;
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    u64 spD8;
    u64 spD0;
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    s64 temp_17;
    s64 temp_18;
    s64 temp_18_8;
    s64 temp_18_9;
    s64 temp_18_10;
    s64 temp_19;
    s64 temp_19_2;
    s64 temp_19_3;
    s64 temp_19_4;
    s64 temp_19_5;
    s64 temp_19_6;
    s64 temp_19_7;
    s64 temp_19_8;
    s64 temp_19_9;
    s64 temp_19_10;
    s64 temp_19_11;
    s64 temp_19_12;
    u8 *work;
    void *r;
    Vec2f *base;
    u8 *t;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    base = (Vec2f *)D_0063F5B8;
    func_002e04f0(*(void **)(work + 0xDEC), 0, 1);
    func_002e09e0(*(void **)(work + 0xC64), 0x41, 157.0f);
    func_002b2970(&sp198, base->x, -300.0f + base->y);
    func_002b2970(&sp190, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC64), sp198, sp190, 0, 7, 0);
    func_002e0660(*(void **)(work + 0xC64), 0U, 0xCCU, 0U, 7, 0);
    func_002b2a60(&c0, 0, 0, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xC64));
    *(RGBA *)(t + 0x79) = c0;
    func_002e0940(*(void **)(work + 0xC64), 0.0f, -4.0f, 0, 0, 0);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xC64)) + 0x100) = (s16)(320.0f - base->x);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xC64)) + 0x102) = (s16)(base->y - 83.0f);
    func_002e06d0(*(void **)(work + 0xC64), 1.0f, 1.5f, 1.0f, 1.0f, 0, 0, 0);
    r = func_0046d200(*(void **)(work + 0xF28), 0x44);
    func_002e09e0(*(void **)(work + 0xD48), 0x56, 53.0f);
    func_002b2970(&sp188, (f32) 0x271, -200.0f);
    func_002b2970(&sp180, (f32) 0x271, 300.0f);
    func_002e0620(*(void **)(work + 0xD48), sp188, sp180, 2, 5, 5);
    func_002b2a60(&c1, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD48));
    *(RGBA *)(t + 0x79) = c1;
    *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0xC4) = 0.0f;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
    func_002e09b0(*(void **)(work + 0xD48), (s32) *(s16 *)(D_0063FA70 + 6), (f32) *(s16 *)(D_0063FA70 + 4));
    func_002e0940(*(void **)(work + 0xD48), 180.0f + *(f32 *)D_0063FA70, 180.0f, 0, *(s16 *)(D_0063FA70 + 6) + 5, 5);
    func_0046d280(r);
    r = func_0046d200(*(void **)(work + 0xF28), 0x43);
    func_002e09e0(*(void **)(work + 0xD44), 0x56, 54.0f);
    func_002b2970(&sp178, 506.0f, -149.0f);
    func_002b2970(&sp170, 506.0f, (f32) 0x15F);
    func_002e0620(*(void **)(work + 0xD44), sp178, sp170, 2, 5, 2);
    func_002b2a60(&c2, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD44));
    *(RGBA *)(t + 0x79) = c2;
    temp_19_3 = (s64) ((s64) (func_0046b260(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD44)) + 0x100) = (s16) temp_19_3;
    temp_19_4 = (s64) ((s64) (func_0046b2f0(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD44)) + 0x102) = (s16) temp_19_4;
    func_002e09b0(*(void **)(work + 0xD44), (s32) *(s16 *)(D_0063FA78 + 6), (f32) *(s16 *)(D_0063FA78 + 4));
    func_002e0940(*(void **)(work + 0xD44), 180.0f + *(f32 *)D_0063FA78, 180.0f, 0, *(s16 *)(D_0063FA78 + 6) + 5, 2);
    func_0046d280(r);
    r = func_0046d200(*(void **)(work + 0xF28), 0x45);
    func_002e09e0(*(void **)(work + 0xD4C), 0x56, 55.0f);
    func_002b2970(&sp168, 592.0f, -191.0f);
    func_002b2970(&sp160, 592.0f, (f32) 0x135);
    func_002e0620(*(void **)(work + 0xD4C), sp168, sp160, 2, 5, 4);
    func_002b2a60(&c3, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD4C));
    *(RGBA *)(t + 0x79) = c3;
    temp_19_5 = (s64) ((s64) (func_0046b260(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD4C)) + 0x100) = (s16) temp_19_5;
    temp_19_6 = (s64) ((s64) (func_0046b2f0(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD4C)) + 0x102) = (s16) temp_19_6;
    func_002e09b0(*(void **)(work + 0xD4C), (s32) *(s16 *)(D_0063FA80 + 6), (f32) *(s16 *)(D_0063FA80 + 4));
    func_002e0940(*(void **)(work + 0xD4C), 180.0f + *(f32 *)D_0063FA80, 180.0f, 0, *(s16 *)(D_0063FA80 + 6) + 5, 4);
    func_0046d280(r);
    r = func_0046d200(*(void **)(work + 0xF28), 0x46);
    func_002e09e0(*(void **)(work + 0xD50), 0x56, 56.0f);
    func_002b2970(&sp158, (f32) 0x1D3, -123.0f);
    func_002b2970(&sp150, (f32) 0x1D3, (f32) 0x179);
    func_002e0620(*(void **)(work + 0xD50), sp158, sp150, 2, 5, 1);
    func_002b2a60(&c4, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD50));
    *(RGBA *)(t + 0x79) = c4;
    temp_19_7 = (s64) ((s64) (func_0046b260(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0x100) = (s16) temp_19_7;
    temp_19_8 = (s64) ((s64) (func_0046b2f0(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0x102) = (s16) temp_19_8;
    func_002e09b0(*(void **)(work + 0xD50), (s32) *(s16 *)(D_0063FA88 + 6), (f32) *(s16 *)(D_0063FA88 + 4));
    func_002e0940(*(void **)(work + 0xD50), 180.0f + *(f32 *)D_0063FA88, 180.0f, 0, *(s16 *)(D_0063FA88 + 6) + 5, 1);
    func_0046d280(r);
    r = func_0046d200(*(void **)(work + 0xF28), 0x47);
    func_002e09e0(*(void **)(work + 0xD54), 0x56, 57.0f);
    func_002b2970(&sp148, (f32) 0x225, -221.0f);
    func_002b2970(&sp140, (f32) 0x225, (f32) 0x117);
    func_002e0620(*(void **)(work + 0xD54), sp148, sp140, 2, 5, 3);
    func_002b2a60(&c5, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD54));
    *(RGBA *)(t + 0x79) = c5;
    temp_19_9 = (s64) ((s64) (func_0046b260(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0x100) = (s16) temp_19_9;
    temp_19_10 = (s64) ((s64) (func_0046b2f0(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0x102) = (s16) temp_19_10;
    func_002e09b0(*(void **)(work + 0xD54), (s32) *(s16 *)(D_0063FA90 + 6), (f32) *(s16 *)(D_0063FA90 + 4));
    func_002e0940(*(void **)(work + 0xD54), 180.0f + *(f32 *)D_0063FA90, 180.0f, 0, *(s16 *)(D_0063FA90 + 6) + 5, 3);
    func_0046d280(r);
    r = func_0046d200(*(void **)(work + 0xF28), 0x48);
    func_002e09e0(*(void **)(work + 0xD58), 0x56, 58.0f);
    func_002b2970(&sp138, (f32) 0x195, -113.0f);
    func_002b2970(&sp130, (f32) 0x195, (f32) 0x183);
    func_002e0620(*(void **)(work + 0xD58), sp138, sp130, 2, 5, 0);
    func_002b2a60(&c6, 0xE4, 0xFF, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xD58));
    *(RGBA *)(t + 0x79) = c6;
    temp_19_11 = (s64) ((s64) (func_0046b260(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0x100) = (s16) temp_19_11;
    temp_19_12 = (s64) ((s64) (func_0046b2f0(r) / 2.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0x102) = (s16) temp_19_12;
    func_002e09b0(*(void **)(work + 0xD58), (s32) *(s16 *)(D_0063FA98 + 6), (f32) *(s16 *)(D_0063FA98 + 4));
    func_002e0940(*(void **)(work + 0xD58), 180.0f + *(f32 *)D_0063FA98, 180.0f, 0, *(s16 *)(D_0063FA98 + 6) + 5, 0);
    func_0046d280(r);
    func_002e09e0(*(void **)(work + 0xD74), 0x56, 11.0f);
    func_002e0660(*(void **)(work + 0xD74), 0U, 0xFFU, 0U, 0xA, 0);
    func_002e09e0(*(void **)(work + 0xD80), 0x56, 9.0f);
    func_002e0660(*(void **)(work + 0xD80), 0U, 0xFFU, 0U, 0xA, 0);
    func_002e3560(*(void **)(work + 0xF18), 0x40000, 0, 4, 0);
    func_002e3560(*(void **)(work + 0xF1C), 0xFFFF, 0x1FE0, 1, 0);
    func_002e3560(*(void **)(work + 0xF20), 0x10000, 0, 1, 0);
    func_002e09e0(*(void **)(work + 0xC8C), 0x41, 139.0f);
    func_002e0660(*(void **)(work + 0xC8C), 0U, 0xFFU, 0U, 6, 7);
    func_002b2a60(&c7, 0xCE, 0x71, 2, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xC8C));
    *(RGBA *)(t + 0x79) = c7;
    func_002e09e0(*(void **)(work + 0xC90), 0x41, 140.0f);
    func_002e0660(*(void **)(work + 0xC90), 0U, 0xFFU, 0U, 6, 7);
    func_002b2a60(&c8, 0xCE, 0x71, 2, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xC90));
    *(RGBA *)(t + 0x79) = c8;
    r = func_0046d200(*(void **)(work + 0xF28), 3);
    func_002e09e0(*(void **)(work + 0xEC4), 0x56, 131.0f);
    func_002b2970(&sp128, 24.0f, -60.0f);
    func_002b2970(&sp120, 24.0f, 48.0f);
    func_002e0620(*(void **)(work + 0xEC4), sp128, sp120, 2, 7, 5);
    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x62) = 0xFF;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x100) = 0x55;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x102) = 0x17;
    func_002e0940(*(void **)(work + 0xEC4), -3.0f, -3.0f, 0, 0, 0);
    func_002b2a60(&c9, 0xFF, 0x96, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEC4));
    *(RGBA *)(t + 0x79) = c9;
    func_0046d280(r);
    r = func_0046d200(*(void **)(work + 0xF28), 4);
    func_002e09e0(*(void **)(work + 0xEC8), 0x56, 132.0f);
    func_002b2970(&sp118, 64.0f, -60.0f);
    func_002b2970(&sp110, 64.0f, 48.0f);
    func_002e0620(*(void **)(work + 0xEC8), sp118, sp110, 2, 7, 5);
    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x62) = 0xFF;
    temp_18_8 = (s64) ((s64) (func_0046b260(r) - 85.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x100) = (s16) temp_18_8;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x102) = 0x17;
    func_002e0940(*(void **)(work + 0xEC8), -3.0f, -3.0f, 0, 0, 0);
    func_002b2a60(&c10, 0xFF, 0x96, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEC8));
    *(RGBA *)(t + 0x79) = c10;
    func_0046d280(r);
    func_002e09e0(*(void **)(work + 0xE38), 0x57, 130.0f);
    func_002b2970(&sp108, 52.0f, -60.0f);
    func_002b2970(&sp100, 52.0f, 59.0f);
    func_002e0620(*(void **)(work + 0xE38), sp108, sp100, 2, 7, 5);
    func_002e0940(*(void **)(work + 0xE38), -3.0f, -3.0f, 0, 0, 0);
    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x62) = 0xFF;
    func_002b2a60(&c11, 0xFF, 0xF2, 0x95, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xE38));
    *(RGBA *)(t + 0x79) = c11;
    if (D_00748908[0] >= func_002e26f0(*(void **)(work + 0xF18))) {
        func_002b2a60(&c12, 0x9C, 0x9C, 0x9C, 0xFF);
        t = (u8 *)func_002e04e0(*(void **)(work + 0xEC4));
        *(RGBA *)(t + 0x79) = c12;
        func_002b2a60(&c13, 0x9C, 0x9C, 0x9C, 0xFF);
        t = (u8 *)func_002e04e0(*(void **)(work + 0xEC8));
        *(RGBA *)(t + 0x79) = c13;
        func_002b2a60(&c14, 0xFF, 0xFF, 0xFF, 0xFF);
        t = (u8 *)func_002e04e0(*(void **)(work + 0xE38));
        *(RGBA *)(t + 0x79) = c14;
    }
    r = func_0046d200(*(void **)(work + 0xF28), 3);
    func_002e09e0(*(void **)(work + 0xEB4), 0x41, 137.0f);
    func_002b2970(&spF8, 146.0f, -60.0f);
    func_002b2970(&spF0, 146.0f, 40.0f);
    func_002e0620(*(void **)(work + 0xEB4), spF8, spF0, 2, 7, 5);
    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x62) = 0xFF;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x100) = 0x55;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x102) = 0x17;
    func_002b2a60(&c15, 0xBD, 0x68, 3, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEB4));
    *(RGBA *)(t + 0x79) = c15;
    func_0046d280(r);
    r = func_0046d200(*(void **)(work + 0xF28), 4);
    func_002e09e0(*(void **)(work + 0xEB8), 0x41, 138.0f);
    func_002b2970(&spE8, 186.0f, -60.0f);
    func_002b2970(&spE0, 186.0f, 40.0f);
    func_002e0620(*(void **)(work + 0xEB8), spE8, spE0, 2, 7, 5);
    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x62) = 0xFF;
    temp_18_9 = (s64) ((s64) (func_0046b260(r) - 85.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x100) = (s16) temp_18_9;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x102) = 0x17;
    func_002b2a60(&c16, 0xBD, 0x68, 3, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEB8));
    *(RGBA *)(t + 0x79) = c16;
    func_0046d280(r);
    func_002e09e0(*(void **)(work + 0xCC4), 0x56, 136.0f);
    func_002b2970(&spD8, 188.0f, -60.0f);
    func_002b2970(&spD0, 188.0f, 51.0f);
    func_002e0620(*(void **)(work + 0xCC4), spD8, spD0, 2, 7, 5);
    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x62) = 0xFF;
    func_002b2a60(&c17, 0x2D, 0x2D, 0x2D, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xCC4));
    *(RGBA *)(t + 0x79) = c17;
    if (D_00748908[1] >= func_002e26f0(*(void **)(work + 0xF1C))) {
        func_002b2a60(&c18, 0, 0, 0, 0xFF);
        t = (u8 *)func_002e04e0(*(void **)(work + 0xEB4));
        *(RGBA *)(t + 0x79) = c18;
        func_002b2a60(&c19, 0, 0, 0, 0xFF);
        t = (u8 *)func_002e04e0(*(void **)(work + 0xEB8));
        *(RGBA *)(t + 0x79) = c19;
        func_002b2a60(&c20, 0x6F, 0x6F, 0x6F, 0xFF);
        t = (u8 *)func_002e04e0(*(void **)(work + 0xCC4));
        *(RGBA *)(t + 0x79) = c20;
    }
    r = func_0046d200(*(void **)(work + 0xF28), 3);
    func_002e09e0(*(void **)(work + 0xEBC), 0x56, 134.0f);
    func_002b2970(&spC8, 268.0f, -60.0f);
    func_002b2970(&spC0, 268.0f, 48.0f);
    func_002e0620(*(void **)(work + 0xEBC), spC8, spC0, 2, 7, 5);
    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x62) = 0xFF;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x100) = 0x55;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x102) = 0x17;
    func_002b2a60(&c21, 0x90, 0x4F, 1, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEBC));
    *(RGBA *)(t + 0x79) = c21;
    func_0046d280(r);
    r = func_0046d200(*(void **)(work + 0xF28), 4);
    func_002e09e0(*(void **)(work + 0xEC0), 0x56, 135.0f);
    func_002b2970(&spB8, 308.0f, -60.0f);
    func_002b2970(&spB0, 308.0f, 48.0f);
    func_002e0620(*(void **)(work + 0xEC0), spB8, spB0, 2, 7, 5);
    temp_18_10 = (s64) ((s64) (func_0046b260(r) - 85.0f) << 0x30) >> 0x30;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x100) = (s16) temp_18_10;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x102) = 0x17;
    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x62) = 0xFF;
    func_002b2a60(&c22, 0x90, 0x4F, 1, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEC0));
    *(RGBA *)(t + 0x79) = c22;
    func_0046d280(r);
    func_002e09e0(*(void **)(work + 0xCC0), 0x57, 133.0f);
    func_002b2970(&spA8, 288.0f, -60.0f);
    func_002b2970(&spA0, 288.0f, 59.0f);
    func_002e0620(*(void **)(work + 0xCC0), spA8, spA0, 2, 7, 5);
    *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x62) = 0xFF;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x100) = 0x23;
    func_002b2a60(&c23, 0x2D, 0x2D, 0x2D, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xCC0));
    *(RGBA *)(t + 0x79) = c23;
    if (D_00748908[2] >= func_002e26f0(*(void **)(work + 0xF20))) {
        func_002b2a60(&c24, 0x2D, 0x2D, 0x2D, 0xFF);
        t = (u8 *)func_002e04e0(*(void **)(work + 0xEBC));
        *(RGBA *)(t + 0x79) = c24;
        func_002b2a60(&c25, 0x2D, 0x2D, 0x2D, 0xFF);
        t = (u8 *)func_002e04e0(*(void **)(work + 0xEC0));
        *(RGBA *)(t + 0x79) = c25;
        func_002b2a60(&c26, 0x6F, 0x6F, 0x6F, 0xFF);
        t = (u8 *)func_002e04e0(*(void **)(work + 0xCC0));
        *(RGBA *)(t + 0x79) = c26;
    }
    func_002e09e0(*(void **)(work + 0xDDC), 0x57, 49.0f);
    func_002e0660(*(void **)(work + 0xDDC), 0U, 0xFFU, 0U, 0xA, 0);
    func_002e09e0(*(void **)(work + 0xDE8), 0x57, 46.0f);
    func_002e0660(*(void **)(work + 0xDE8), 0U, 0xFFU, 0U, 0xA, 0);
    func_002b2970(&sp98, 196.0f, 404.0f);
    func_002b2970(&sp90, 196.0f, 404.0f);
    func_002e0620(*(void **)(work + 0xDE8), sp98, sp90, 0, 0, 0);
    func_002e09e0(*(void **)(work + 0xDF0), 0x57, 47.0f);
    func_002e0660(*(void **)(work + 0xDF0), 0U, 0xFFU, 0U, 0xA, 0);
    func_002b2970(&sp88, (f32) 0x103, 404.0f);
    func_002b2970(&sp80, (f32) 0x103, 404.0f);
    func_002e0620(*(void **)(work + 0xDF0), sp88, sp80, 0, 0, 0);
    func_002e09e0(*(void **)(work + 0xDE4), 0x57, 47.0f);
    func_002e0660(*(void **)(work + 0xDE4), 0U, 0xFFU, 0U, 0xA, 0);
    func_002b2970(&sp78, 338.0f, 404.0f);
    func_002b2970(&sp70, 338.0f, 404.0f);
    func_002e0620(*(void **)(work + 0xDE4), sp78, sp70, 0, 0, 0);
    func_002e09e0(*(void **)(work + 0xDE0), 0x57, 47.0f);
    func_002e0660(*(void **)(work + 0xDE0), 0U, 0xFFU, 0U, 0xA, 0);
    func_002b2970(&sp68, 338.0f, 404.0f);
    func_002b2970(&sp60, 338.0f, 404.0f);
    func_002e0620(*(void **)(work + 0xDE0), sp68, sp60, 0, 0, 0);
    func_002e04f0(*(void **)(work + 0xDE0), 0, 1);
    func_002e09e0(*(void **)(work + 0xDCC), 0x41, 123.0f);
    func_002e0660(*(void **)(work + 0xDCC), 0U, 0xFFU, 0U, 6, 7);
    func_002e09e0(*(void **)(work + 0xDD0), 0x41, 125.0f);
    func_002e0660(*(void **)(work + 0xDD0), 0U, 0xFFU, 0U, 6, 7);
    *(s8 *)(work + 0x11) = 0;
    *(s16 *)(work + 2) = 0;
    *(s16 *)(work + 4) = 0;
    *(s8 *)work = 0x24;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002db400);
#endif
// FUN_002DD230
void func_002dd230(void *arg0) {
    u64 sp48;
    u64 sp40;
    u64 sp38;
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    void *s1;

    s1 = func_002e04e0(work->field_D90);
    func_002b2970(&sp48, 311.0f, -17.0f);
    func_002e0620(work->field_D90, *(u64 *)((u8 *)s1 + 0x2C), sp48, 0, 0xA, 0);
    s1 = func_002e04e0(work->field_D94);
    func_002b2970(&sp40, 564.0f, -17.0f);
    func_002e0620(work->field_D94, *(u64 *)((u8 *)s1 + 0x2C), sp40, 0, 0xA, 0);
    s1 = func_002e04e0(work->field_D8C);
    func_002b2970(&sp38, -610.0f, -620.0f);
    func_002e0620(work->field_D8C, *(u64 *)((u8 *)s1 + 0x2C), sp38, 0, 0xA, 0);
    func_002e04f0(work->field_D8C, 3, 1);
    func_002e0940(work->field_D8C, 0.0f, 360.0f, 0, 0x708, 0);
    func_002e04f0(work->field_D8C, 6, 0);
}

/* measured: func_002dd3b0's best reconstructed C body is archived verbatim at
   build/WBFclShopDraw_func_002dd3b0_archive.txt. Its scoped result was object
   4816B against a 4592B retail window, normalized_diff 3543, MISMATCH. The
   archive records the candidate/retail prologue and saved-register facts, the
   exact fndiff prologue rows, the two-call func_0046a770 findings for all four
   branch groups, the two regular work->field_F28 calls, and ruled-out probes. */
/* measured: probe_variants 895 differing words reloc-masked (V9loop with opt_propagation off + opt_common_subs off + opt_loop_invariants on; bare V1 1028, V2 swap 1025, V3prop 969, V7 cached 958, V8common 902); fnalign retail 1148 vs object 1163 instrs (+15, +1.31% PASS, 378 edits +26 reloc-only via --candidate v9_loop.c --quiet); verify/lint clean. Count-first PASS (within 3%). */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclShopDraw.c func_002dd3b0 -o /var/tmp/cold2dd3b0/m2c.c` (jr/jtbl failure, no output) + `python3 -E -s tools/romwright_decompile.py func_002dd3b0 -o /var/tmp/cold2dd3b0/rom.c` (356 lines, (void*) arity, stack extents) + `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclShopDraw.c func_002dd3b0 --candidate V9=/var/tmp/cold2dd3b0/v9_loop.c` (895) + `python3 -E -s tools/fnalign.py src/Event/Fcl/y_fclShopDraw.c func_002dd3b0 --candidate /var/tmp/cold2dd3b0/v9_loop.c --quiet` (1148/1163) + `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclShopDraw.c func_002dd3b0`. */
/* Rounds in batch order (count first): v1 1028 (m2c+rom de-noise, Vec2f/u64/RGBA homes, correct 0b20/cacd0/75680 orders per file header + fr_font_internal.h, 1209/1148 +61 FAIL); v2 swap 1025 (-3, outer dispatch 1-first to match retail L002DD960 layout 1-near/0-2-far, edits 1344->498); v3 propOff 969 (-56, family convention as 2d5040) + v3 commonOff 1002 (-23) vs loop/unroll/sched ties; v4 subscript ties (F18 P[i] vs off); v5 colouring ties (work/tmp swaps); v6 f32 ties (micro shows (f32)0x246 and 582.0f both emit addiu+cvt); v7 cached 958 (-11, 04e0 result caching 37->17 calls matching retail 17, 1146/1147 -1 PASS); v8 common 902 (-56, propOff+commonOff) + v8 loop 949 (-9) vs unroll/sched/sub ties; v9 loop 895 (-7, triple propOff+commonOff+loopInvOn) vs unroll/sched/col/sub ties; v10 sweep ties (dead/str/sched/unroll) + peep 1062 worse; v11 width worse (loop s16 970, c16 s16 984) + workLast tie. Step3/Step4 ties per handoff 7o (bare decls, assigns in retail order). */
/* Walls (same float-hoist+scheduling as sibling 2d5040, now at 895): retail f20 hoisted vs object f12 rematerialised per 2970 pair; retail lwc1/swc1 Vec2f copy vs object ld/sd; retail andi vs object ori/and under propOff (&0xFFFF); $s0/$s1/$s2 colouring (work/tmp/h0/pT) persists -- body already in 7o form so subscript/colouring probes are ties; all logic matches: 0b20/cacd0/75680 chains with correct 11-arg signatures + outer C24 + inner 26f0 + 069d0 loop/bc7f0 + three-case work[7] dispatch (0/2 far, 1 near with 20-28 jump table) + eight 04e0 groups cached. Prior nd-3543 archive superseded (helper orders + caching + dispatch layout fixed). */
// FUN_002DD3B0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_loop_invariants on
void func_002dd3b0(void *arg0) {
    extern s16 func_002e2740(s32 arg0);
    extern s64 func_00106b80(s32 arg0);
    Vec2f sp140;
    Vec2f sp138;
    Vec2f sp128;
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp70;
    Vec2f sp68;
    Vec2f sp60;
    Vec2f sp58;
    u64 sp130;
    u64 sp120;
    RGBA sp16C;
    RGBA sp168;
    RGBA sp154;
    RGBA sp150;
    RGBA sp14C;
    RGBA sp148;
    RGBA rCA0;
    RGBA rCA8;
    RGBA rC9C;
    RGBA rCA4;
    Vec2f c138;
    Vec2f cF8;
    Vec2f cD8;
    Vec2f cD0;
    u8 *work;
    u8 *pT;
    s32 tmp;
    s32 col;
    s32 c16;
    s32 div5;
    s32 msk;
    s32 nA;
    s32 h0;
    s32 h1;
    s32 sw;
    s32 sw2;
    s32 i;
    f32 var;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    if (*(s8 *)(work + 0xC24) != 0) {
        if (func_002e26f0(*(void **)((u8 *)work + (*(s8 *)(work + 0x11) * 4) + 0xF18)) >= 2) {
            if (*(s8 *)(work + 0x11) == 0) {
                if (func_002e26f0(*(void **)((u8 *)work + 0xF18)) >= 3) {
                    *(f32 *)(work + 0xC) = 91.0f / (f32)(func_002e26f0(*(void **)((u8 *)work + (*(s8 *)(work + 0x11) * 4) + 0xF18)) - 2);
                } else {
                    *(f32 *)(work + 0xC) = 91.0f;
                }
                var = 146.0f + *(f32 *)(work + 0xC) * (f32)(*(s16 *)(work + 2) - 1);
            } else {
                *(f32 *)(work + 0xC) = 91.0f / (f32)(func_002e26f0(*(void **)((u8 *)work + (*(s8 *)(work + 0x11) * 4) + 0xF18)) - 1);
                var = 146.0f + *(f32 *)(work + 0xC) * (f32)*(s16 *)(work + 2);
            }
            func_002b2970(&sp140, 582.0f, var);
            tmp = func_002b2a30(0xFF, 0xFF, 0x6D, 0x31);
            func_002e0b20(0x36, sp140, 88.0f, tmp, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC94)) + 0x62), 0, D_00794EA0);
            func_002e04f0(*(void **)(work + 0xC94), 0, 0);
            func_002e04f0(*(void **)(work + 0xC98), 0, 0);
        } else {
            func_002e04f0(*(void **)(work + 0xC94), 0, 1);
            func_002e04f0(*(void **)(work + 0xC98), 0, 1);
        }
        c16 = (s16)func_002e2830(*(void **)((u8 *)work + (*(s8 *)(work + 0x11) * 4) + 0xF18), *(s16 *)(work + 2));
        col = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b2970(&sp138, 129.0f, 134.0f);
        c138 = sp138;
        func_00275680(c138.x, c138.y, 70.0f, col, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
        div5 = func_00106a90((s16)c16) / 5;
        func_002b2970(&sp130, 486.0f, 145.0f);
        func_002b2a60(&sp16C, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp130, 70.0f, sp16C, 0x10, 5, (u32)div5, 9, 0x7B, h0, (s32)*(void **)(work + 0xF28), 0xA9);
        func_002b2970(&sp128, 514.0f, 147.0f);
        func_002e0b20(0x47, sp128, 70.0f, func_002b2a30(0x2D, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E60);
        func_002b2970(&sp120, 545.0f, 145.0f);
        func_002b2a60(&sp168, 0x2D, 0x2D, 0x2D, 0xFF);
        msk = func_00106600((s16)c16) & 0xFF;
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp120, 70.0f, sp168, 0x10, 5, (u32)msk, 9, 0x7B, h0, (s32)*(void **)(work + 0xF28), 0xA9);
        if ((func_001069d0((s64)c16) & 0xFFFF) == 0) {
            for (i = 0; i < 0xF; i++) {
                func_002b2970(&sp118, (f32)(i * 0x16 + 0x6F), 178.0f);
                func_002e0b20(0x3C, sp118, 86.0f, func_002b2a30(0xFF, 0xFF, 0xC7, 0x31), 0xFF, 0, D_00794ED0);
            }
        } else {
            tmp = func_001069d0((s64)c16) & 0xFFFF;
            func_002bc7f0(tmp, func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF), 1, 0, 3, 0x57, 109.0f, 169.0f, 70.0f);
        }
        if (*(s8 *)(work + 0x11) == 1) {
            tmp = func_002d4f30((s16)func_00106880((s16)c16)) & 0xFFFF;
            func_002b2970(&sp110, 86.0f, 135.0f);
            func_002e0b20(tmp, sp110, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
            sw = func_002d4f30((s16)func_00106880((s16)c16));
            switch (sw) {
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 0, 0x57, 109.0f, 201.0f, 70.0f);
                func_002e09e0(*(void **)(work + 0xCA0), 0x57, 83.0f);
                func_002b2a60(&rCA0, 0xFE, 0xEF, 0x80, 0xFF);
                pT = func_002e04e0(*(void **)(work + 0xCA0));
                *(u8 *)(pT + 0x79) = rCA0.r;
                *(u8 *)(pT + 0x7A) = rCA0.g;
                *(u8 *)(pT + 0x7B) = rCA0.b;
                *(u8 *)(pT + 0x7C) = rCA0.a;
                func_002b2970(&sp108, 481.0f, 174.0f);
                pT = func_002e04e0(*(void **)(work + 0xCA0));
                *(f32 *)(pT + 0x2C) = sp108.x;
                *(f32 *)(pT + 0x30) = sp108.y;
                func_002e09e0(*(void **)(work + 0xCA8), 0x57, 82.0f);
                func_002b2a60(&rCA8, 0xFE, 0xEF, 0x80, 0xFF);
                pT = func_002e04e0(*(void **)(work + 0xCA8));
                *(u8 *)(pT + 0x79) = rCA8.r;
                *(u8 *)(pT + 0x7A) = rCA8.g;
                *(u8 *)(pT + 0x7B) = rCA8.b;
                *(u8 *)(pT + 0x7C) = rCA8.a;
                func_002b2970(&sp100, 481.0f, 224.0f);
                pT = func_002e04e0(*(void **)(work + 0xCA8));
                *(f32 *)(pT + 0x2C) = sp100.x;
                *(f32 *)(pT + 0x30) = sp100.y;
                func_002b2970(&spF8, 526.0f, 202.0f);
                cF8 = spF8;
                tmp = func_001068b0((s16)c16) & 0xFFFF;
                nA = func_002b3170(tmp);
                func_002b2970(&sp70, cF8.x + (f32)((s16)(nA - 1) * 8), cF8.y);
                func_002b2a60(&sp154, 0x2D, 0x2D, 0x2D, 0xFF);
                h0 = (s32)func_0046a770(D_0063FB50);
                h1 = (s32)func_0046a770(D_0063FB50);
                func_002cacd0(*(u64 *)&sp70, 22.0f, sp154, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, h1, 0xA9);
                func_002b2970(&spE8, 526.0f, 252.0f);
                cF8 = spE8;
                tmp = func_001068e0((s16)c16) & 0xFFFF;
                nA = func_002b3170(tmp);
                func_002b2970(&sp68, cF8.x + (f32)((s16)(nA - 1) * 8), cF8.y);
                func_002b2a60(&sp150, 0x2D, 0x2D, 0x2D, 0xFF);
                h0 = (s32)func_0046a770(D_0063FB50);
                h1 = (s32)func_0046a770(D_0063FB50);
                func_002cacd0(*(u64 *)&sp68, 22.0f, sp150, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, h1, 0xA9);
                return;
            case 27:
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 1, 0x57, 109.0f, 201.0f, 70.0f);
                func_002e09e0(*(void **)(work + 0xC9C), 0x57, 81.0f);
                func_002b2a60(&rC9C, 0xFE, 0xEF, 0x80, 0xFF);
                pT = func_002e04e0(*(void **)(work + 0xC9C));
                *(u8 *)(pT + 0x79) = rC9C.r;
                *(u8 *)(pT + 0x7A) = rC9C.g;
                *(u8 *)(pT + 0x7B) = rC9C.b;
                *(u8 *)(pT + 0x7C) = rC9C.a;
                func_002b2970(&spE8, 481.0f, 174.0f);
                pT = func_002e04e0(*(void **)(work + 0xC9C));
                *(f32 *)(pT + 0x2C) = spE8.x;
                *(f32 *)(pT + 0x30) = spE8.y;
                func_002e09e0(*(void **)(work + 0xCA4), 0x57, 80.0f);
                func_002b2a60(&rCA4, 0xFE, 0xEF, 0x80, 0xFF);
                pT = func_002e04e0(*(void **)(work + 0xCA4));
                *(u8 *)(pT + 0x79) = rCA4.r;
                *(u8 *)(pT + 0x7A) = rCA4.g;
                *(u8 *)(pT + 0x7B) = rCA4.b;
                *(u8 *)(pT + 0x7C) = rCA4.a;
                func_002b2970(&spE0, 481.0f, 224.0f);
                pT = func_002e04e0(*(void **)(work + 0xCA4));
                *(f32 *)(pT + 0x2C) = spE0.x;
                *(f32 *)(pT + 0x30) = spE0.y;
                func_002b2970(&spD8, 526.0f, 202.0f);
                cD8 = spD8;
                tmp = func_00106940((s16)c16) & 0xFFFF;
                nA = func_002b3170(tmp);
                func_002b2970(&sp60, cD8.x + (f32)((s16)(nA - 1) * 8), cD8.y);
                func_002b2a60(&sp14C, 0x2D, 0x2D, 0x2D, 0xFF);
                h0 = (s32)func_0046a770(D_0063FB50);
                h1 = (s32)func_0046a770(D_0063FB50);
                func_002cacd0(*(u64 *)&sp60, 22.0f, sp14C, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, h1, 0xA9);
                func_002b2970(&spD0, 526.0f, 252.0f);
                cD0 = spD0;
                tmp = func_00106970((s16)c16) & 0xFFFF;
                nA = func_002b3170(tmp);
                func_002b2970(&sp58, cD0.x + (f32)((s16)(nA - 1) * 8), cD0.y);
                func_002b2a60(&sp148, 0x2D, 0x2D, 0x2D, 0xFF);
                h0 = (s32)func_0046a770(D_0063FB50);
                h1 = (s32)func_0046a770(D_0063FB50);
                func_002cacd0(*(u64 *)&sp58, 22.0f, sp148, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, h1, 0xA9);
                return;
            case 28:
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 2, 0x57, 109.0f, 201.0f, 70.0f);
                func_002e09e0(*(void **)(work + 0xCB8), 0x57, 84.0f);
                *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCB8)) + 0x62) = 0x7F;
                func_002b2970(&spC8, 478.0f, 166.0f);
                pT = func_002e04e0(*(void **)(work + 0xCB8));
                *(f32 *)(pT + 0x2C) = spC8.x;
                *(f32 *)(pT + 0x30) = spC8.y;
                func_002e09e0(*(void **)(work + 0xEAC), 0x57, 84.0f);
                *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEAC)) + 0x62) = 0x7F;
                func_002b2970(&spC0, 477.0f, 216.0f);
                pT = func_002e04e0(*(void **)(work + 0xEAC));
                *(f32 *)(pT + 0x2C) = spC0.x;
                *(f32 *)(pT + 0x30) = spC0.y;
                return;
            }
        } else if (*(s8 *)(work + 0x11) == 0 || *(s8 *)(work + 0x11) == 2) {
            if (*(s8 *)(work + 0x11) == 2) {
                func_002b2970(&spB8, 86.0f, 135.0f);
                func_002e0ca0(0x1B, spB8, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 4, 0x57, 109.0f, 201.0f, 70.0f);
            } else {
                func_002b2970(&spB0, 86.0f, 135.0f);
                func_002e0ca0(0x1A, spB0, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 7, 0x57, 109.0f, 201.0f, 70.0f);
            }
            func_002e09e0(*(void **)(work + 0xCB8), 0x56, 84.0f);
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCB8)) + 0x62) = 0x7F;
            func_002b2970(&spC8, 478.0f, 166.0f);
            pT = func_002e04e0(*(void **)(work + 0xCB8));
            *(f32 *)(pT + 0x2C) = spC8.x;
            *(f32 *)(pT + 0x30) = spC8.y;
            func_002e09e0(*(void **)(work + 0xEAC), 0x56, 84.0f);
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEAC)) + 0x62) = 0x7F;
            func_002b2970(&spC0, 477.0f, 216.0f);
            pT = func_002e04e0(*(void **)(work + 0xEAC));
            *(f32 *)(pT + 0x2C) = spC0.x;
            *(f32 *)(pT + 0x30) = spC0.y;
        }
    }
}
#pragma opt_loop_invariants off
#pragma opt_common_subs on
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002dd3b0);
#endif

/* measured: func_002de5a0's full body was reconstructed (all six 2a30/0b20
   groups, the three if/else dispatch pairs on work[7], the func_00275680
   calls with the Vec2f copies) and compiles; nd 586 across four variants,
   dominated by two mwcc b210 allocation gaps: (1) retail hoists the shared
   constants (f32)0x177 and 70.0f into callee-saved f21/f22 at the first-if
   branch tops for reuse in the second/third groups' 2970/0b20 calls, while
   mwcc rematerialises them per call site, so the candidate saves only f20
   (prologue 0x10 shorter, whole stream shifts 2 words); (2) work lands in
   $s1 instead of $s0 once the byte-index sum is written as (u32) pointer
   arithmetic. The byte-first addu ($v1,$v1,$s0) IS reproducible with
   `*(s8 *)((u8 *)(*(s8 *)(w+8) + (u32)w) + 0xF7C)`. FP-constant-hoist +
   register-coloring floor. */
/* measured: recipe B re-test 2026-08-03: full draft re-adapted; the
   f21/f22 constant hoist IS reproducible with named locals `f32 c375 =
   (f32)0x177; f32 c70 = 70.5f;` (retail hoists both at the first-if top;
   without the locals mwcc rematerialises per site), the (s32)-local c16 =
   (s16)func_00106cd0 emits retail's dsll32/dsra32 before func_001067f0, and
   the 75680/0b20 shapes match: nd 586 -> 572, frame 0x110 vs retail 0x120.
   Residual: mwcc b210 CSE-hoists `(u8 *)work + 8` and `(u8 *)work + 7` into
   saved regs $s1/$s0 (7 and 3 uses across calls; every spelling of the
   byte-index expr tried - (u32) cast, plain pointer add, reordered sum - and
   the struct-field read all fold to the same IR and hoist), so the candidate
   saves s0-s3 + f20-f22 vs retail s0-s1 + f20-f22, the frame stays 0x110 and
   every slot shifts 0x10; per-site the candidate is identical except
   lb ($s1) vs retail lb 8($s0). CSE-of-invariant-address floor. */
/* measured: bank 2026-09-17 S1 002de5a0 — object 2632B/window 2688B (2.1% short), normalized_diff 1925 MISMATCH via `python3 tools/try_bodies.py src/Event/Fcl/y_fclShopDraw.c func_002de5a0 /tmp/v_de5a0.json` (pwd source/Persona4-Decompilation); GUARDED_SCORE 583 via `python3 tools/measure_guarded.py src/Event/Fcl/y_fclShopDraw.c func_002de5a0` (differing words 583). Vec2f slots + Vec2f copies + s32 c16=(s16)106cd0 local + byte-first addu (*(s8*)((u8*)(*(s8*)(work+8)+(u32)work)+0xF7C/F73)); FP-hoist + CSE floor as prior note. */
/* measured 002de5a0 (owner, 2026-09-19): 658 against retail 671 (-1.9%, inside), **71
   edits**, and the deficit is unusually legible: the only opcodes retail has more of are
   `swc1 +14`, `lwc1 +14` and `mov.s +10`, and regsave_scan says retail additionally saves
   $f21 and $f22.  Reading the disassembly names all three saved floats: $f20 is 70.0f
   (`mtc1 $3, $f20` at 0x002de784, then `mov.s $f14, $f20` at every func_00275680 call),
   $f21 is `(f32)0x177` (`cvt.s.w $f21, $f0` at 0x002de648), and $f22 is 420.0f
   (`mtc1 $2, $f22` at 0x002de638).  So retail held exactly those three as variables,
   which is what handoff 7bb predicts from the saved-float count.
   Hoisting them into locals reproduces the `mov.s` shape and DOES cut edits, but it is
   rejected because every variant leaves the 3% band by shortening the object - b210 then
   materialises each literal once where the current body materialises it at each of the
   twelve sites, and the object is already 13 instructions short:
     70.0f alone            51 edits, 648 instrs (-3.4%, OUTSIDE)
     70.0f + (f32)0x177     67 edits, 638 instrs (-4.9%, OUTSIDE)
     70.0f + 420.0f         87 edits, 636 instrs (OUTSIDE)
     all three              103 edits, 626 instrs (OUTSIDE)
     420.0f + (f32)0x177   117 edits, 638 instrs (OUTSIDE)
     70.0f + 420.0f + 69.0f 114 edits, 627 instrs (OUTSIDE)
   The `mov.s` shape and the instruction count pull in opposite directions here, and the
   gate decides.  Find the 13 missing instructions first; then the hoist becomes free. */
// FUN_002DE5A0 NONMATCHING
#ifdef NON_MATCHING
void func_002de5a0(void *arg0) {
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    Vec2f sp88;
    Vec2f sp80;
    Vec2f sp78;
    Vec2f c100;
    Vec2f cE8;
    Vec2f cC8;
    Vec2f cB0;
    Vec2f c90;
    Vec2f c78;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 c16;
    u8 *work;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    func_002b2970(&sp118, 378.0f, 245.0f);
    func_002e0b20(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), sp118, 69.0f, func_002b2a30(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (*(s8 *)(work + 7) == 0) {
        func_002b2970(&sp110, (f32)0x177, 243.0f);
        func_002e0b20(2, sp110, 70.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        func_002b2970(&sp108, 420.0f, 246.0f);
        func_002e0b20(5, sp108, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        t0 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b2970(&sp100, 420.0f, (f32)0x10F);
        c100 = sp100;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        func_00275680(c100.x, c100.y, 70.0f, t0, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    } else {
        func_002b2970(&spF8, (f32)0x177, 243.0f);
        func_002e0b20(2, spF8, 70.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        func_002b2970(&spF0, 420.0f, 246.0f);
        func_002e0b20(5, spF0, 69.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        t1 = func_002b2a30(0xFF, 0xEF, 0x81, 0xFF);
        func_002b2970(&spE8, 420.0f, (f32)0x10F);
        cE8 = spE8;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        func_00275680(cE8.x, cE8.y, 70.0f, t1, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    }
    func_002b2970(&spE0, 378.0f, (f32)0x12F);
    func_002e0b20(0x1B, spE0, 69.0f, func_002b2a30(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (*(s8 *)(work + 7) == 1) {
        func_002b2970(&spD8, (f32)0x177, (f32)0x12D);
        func_002e0b20(3, spD8, 70.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        func_002b2970(&spD0, 420.0f, (f32)0x131);
        func_002e0b20(6, spD0, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        t2 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b2970(&spC8, 420.0f, 330.0f);
        cC8 = spC8;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        func_00275680(cC8.x, cC8.y, 70.0f, t2, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    } else {
        func_002b2970(&spC0, (f32)0x177, (f32)0x12D);
        func_002e0b20(3, spC0, 70.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        func_002b2970(&spB8, 420.0f, (f32)0x131);
        func_002e0b20(6, spB8, 69.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        t3 = func_002b2a30(0xFF, 0xEF, 0x81, 0xFF);
        func_002b2970(&spB0, 420.0f, 330.0f);
        cB0 = spB0;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        func_00275680(cB0.x, cB0.y, 70.0f, t3, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    }
    func_002b2970(&spA8, 378.0f, 368.0f);
    func_002e0b20(0x1C, spA8, 69.0f, func_002b2a30(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (*(s8 *)(work + 7) == 2) {
        func_002b2970(&spA0, (f32)0x177, 366.0f);
        func_002e0b20(3, spA0, 70.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        func_002b2970(&sp98, 420.0f, (f32)0x171);
        func_002e0b20(7, sp98, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        t4 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b2970(&sp90, 420.0f, 394.0f);
        c90 = sp90;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 2);
        func_00275680(c90.x, c90.y, 70.0f, t4, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
        return;
    }
    func_002b2970(&sp88, (f32)0x177, 366.0f);
    func_002e0b20(3, sp88, 70.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
    func_002b2970(&sp80, 420.0f, (f32)0x171);
    func_002e0b20(7, sp80, 69.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
    t5 = func_002b2a30(0xFF, 0xEF, 0x81, 0xFF);
    func_002b2970(&sp78, 420.0f, 394.0f);
    c78 = sp78;
    c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 2);
    func_00275680(c78.x, c78.y, 70.0f, t5, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002de5a0);
#endif

/* Floor: 219 reloc-masked differing words (window 296 words/1184B, emitted 301 words/1204B).
   Levers that closed it from 271 to 219: u64 Vec2f slots with Vec2f direct pass
   for 002e0ca0/002e0b20 (ld $a1, not lwc1), (f32)0x1F1 for the 497 cvt.s.w chain,
   goto order 0,1,2 (L0 first, L1 second, L2 third, Ljoin) to match retail layout
   L070/L0D8/L160/L1C0, single s32 tmp + u8 *work to hold frame at retail 0xC0
   with sd $ra + sq s3/s2/s1/s0, *(u64*)(iGpffffa890-8) for the 0x763978 GP load.
   Residual is systematic (2 sites, then shift): off 32 lw $s0 vs retail $s1 and
   off 36 lb ($s0) vs ($s1) -- work wants $s1, tmp wants $s0, candidate has them
   swapped (~10 words via work+0x12/0xF28/0xCC8 and andi); off 64 bnez vs beqz +
   off 72 missing b+nop -- IROEVAL "Removing branch around goto" folds beq-over-b
   (over 1) to bnez with L0 inline (6 words before L0, not retail 8), shifting
   every later offset by 8 so fndiff marks ~200 words that are mnemonically
   identical once realigned. #pragma opt_optimizecontrolflow off/on (file and
   scoped) is ignored by b210; #pragma peephole off restores beq+b (aligned) but
   costs +46 elsewhere (265). Orders 1,2,0 score 250. Archive: v11 floor banked
   in docs/probe_archive/ShopDraw_002df020_body.c (62 lines). */
/* measured 002df020: `opt_propagation off` inside the guard is worth 4 words (219 -> 215). */
/* measured 002df020 width: block-scope (arg1 s32, 106880 s32, 0046a770 pointer; keep 106a90 s16 + outer s16) removes all six excess pairs */
/* (wscan obj 8 -> 2 matching retail) but trades 215 words / 207 edits for 232 / 191 -- do not install; remaining is work/tmp colouring, */
/* bnez vs beqz+b, GP ld and lbu schedule. Correct but not yet profitable; prerequisite for the rest. */
// FUN_002DF020 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_002df020(void *arg0, s64 arg1, s32 arg2) {
    extern u8 iGpffffa890[];
    extern u8 D_0063FAA0[];
    s32 tmp;
    u8 *work;
    RGBA spBC;
    RGBA spB8;
    RGBA spB4;
    u64 spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    u64 sp88;
    u64 sp80;
    Vec2f sp78;
    u64 sp70;
    Vec2f sp68;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    if (*(s8 *)(work + 0x11) == 2) {
        goto L2;
    }
    if (*(s8 *)(work + 0x11) == 1) {
        goto L1;
    }
    if (*(s8 *)(work + 0x11) == 0) {
        goto L0;
    }
    goto Ljoin;
L0:
    func_002b2970(&spA0, 97.0f, 178.0f);
    func_002e0ca0(0x1A, spA0, 13.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    goto Ljoin;
L1:
    tmp = func_002d4f30((s16)func_00106880((s16)arg1)) & 0xFFFF;
    func_002b2970(&sp98, 97.0f, 178.0f);
    func_002e0b20(tmp, sp98, 13.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    goto Ljoin;
L2:
    func_002b2970(&sp90, 97.0f, 178.0f);
    func_002e0ca0(0x1B, sp90, 13.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
Ljoin:
    tmp = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&sp88, 140.0f, 178.0f);
    sp68 = *(Vec2f *)&sp88;
    func_00275680(sp68.x, sp68.y, 13.0f, tmp, 0, 1, (const char *)func_001067f0((s32)arg1), 0, 0, D_00795E30, -1);
    tmp = func_00106a90((s16)arg1) / 5U;
    func_002b2970(&sp80, 448.0f, 185.0f);
    func_002b2a60(&spBC, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002cacd0(sp80, 13.0f, spBC, 0x10, 5, (u32)tmp, 9, 0x7B, (s32)func_0046a770(D_0063FB50), *(s32 *)(work + 0xF28), 0xA9);
    func_002b2970(&sp78, 476.0f, 187.0f);
    func_002e0b20(0x47, sp78, 13.0f, func_002b2a30(0x2D, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E60);
    spA8 = *(u64 *)(iGpffffa890 - 8);
    if (*(s16 *)(work + 0x12) < 10) {
        *(f32 *)&spA8 = *(f32 *)&spA8 - 8.0f;
    }
    func_002b2a60(&spB8, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002cacd0(spA8, 13.0f, spB8, 0x10, 5, *(s16 *)(work + 0x12), 9, 0x7B, (s32)func_0046a770(D_0063FB50), *(s32 *)(work + 0xF28), 0xA9);
    func_002b2970(&sp70, (f32)0x1F1, 247.0f);
    func_002b2a60(&spB4, 0xDF, 0x6C, 0, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC8)) + 0x62));
    tmp = (s32)func_0046a770(D_0063FAA0);
    func_002cacd0(sp70, 1.0f, spB4, 0x1B, 0, arg2 & 0xFF, 0x2F, 0, tmp, (s32)func_0046a770(D_0063FAA0), 0xA9);
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002df020);
#endif










// FUN_002DF4C0
void func_002df4c0(void *arg0) {
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    u64 sp30;
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    void *r;

    if (work->field_C24 == 1) {
        r = func_0046d200(work->field_F28, 0x2B);
        func_002e06d0(work->field_CE4, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002b2970(&spA8, 67.0f, 140.0f);
        func_002b2970(&spA0, 67.0f, 140.0f + 5.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CE4, spA8, spA0, 0, 5, 0);
        func_002e0660(work->field_CE4, 0xFF, 0, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x2C);
        func_002e06d0(work->field_CE8, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002b2970(&sp98, (f32)0x22F, 140.0f);
        func_002b2970(&sp90, (f32)0x22F, 140.0f + 5.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CE8, sp98, sp90, 0, 5, 0);
        func_002e0660(work->field_CE8, 0xFF, 0, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x28);
        func_002e06d0(work->field_CD8, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002e0660(work->field_CD8, 0xFF, 0, 0, 5, 0);
        func_002b2970(&sp88, 48.0f, 127.0f);
        func_002b2970(&sp80, 48.0f, 127.0f + 2.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CD8, sp88, sp80, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x29);
        func_002e06d0(work->field_CDC, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002e0660(work->field_CDC, 0xFF, 0, 0, 5, 0);
        func_002b2970(&sp78, 584.0f, 127.0f);
        func_002b2970(&sp70, 584.0f, 127.0f + 2.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CDC, sp78, sp70, 0, 5, 0);
        func_0046d280((u8 *)r);
    } else {
        r = func_0046d200(work->field_F28, 0x2A);
        func_002e06d0(work->field_CE0, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002b2970(&sp68, 63.0f, 148.0f);
        func_002b2970(&sp60, 63.0f, 148.0f + 5.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CE0, sp68, sp60, 0, 5, 0);
        func_002e0660(work->field_CE0, 0xFF, 0, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x2C);
        func_002e06d0(work->field_CE8, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002b2970(&sp58, (f32)0x222, 148.0f);
        func_002b2970(&sp50, (f32)0x222, 148.0f + 5.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CE8, sp58, sp50, 0, 5, 0);
        func_002e0660(work->field_CE8, 0xFF, 0, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x27);
        func_002e06d0(work->field_CD4, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002e0660(work->field_CD4, 0xFF, 0, 0, 5, 0);
        func_002b2970(&sp48, 46.0f, 136.0f);
        func_002b2970(&sp40, 46.0f, 136.0f + 2.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CD4, sp48, sp40, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x29);
        func_002e06d0(work->field_CDC, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002e0660(work->field_CDC, 0xFF, 0, 0, 5, 0);
        func_002b2970(&sp38, (f32)0x232, 136.0f);
        func_002b2970(&sp30, (f32)0x232, 136.0f + 2.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CDC, sp38, sp30, 0, 5, 0);
        func_0046d280((u8 *)r);
    }
}

// FUN_002DFD00
s32 func_002dfd00(u16 arg0) {
    if (arg0 == 0x540 || arg0 == 0x503 || arg0 == 0x596 || arg0 == 0x517 ||
        arg0 == 0x52C || arg0 == 0x555 || arg0 == 0x54D || arg0 == 0x54B ||
        arg0 == 0x56A || arg0 == 0x519 || arg0 == 0x598 || arg0 == 0x582 ||
        arg0 == 0x599 || arg0 == 0x51A || arg0 == 0x59A || arg0 == 0x580 ||
        arg0 == 0x559 || arg0 == 0x59B) {
        return 1;
    }
    return 0;
}

// FUN_002DFE00
void func_002dfe00(void *arg0) {
    s32 r;
    s32 idx;
    u16 v;
    u32 t[2];
    void *work = *(void **)((u8 *)arg0 + 0x38);

    idx = *(s16 *)((u8 *)work + 0xC18) * 2;
    r = func_00106b20(*(s16 *)(idx + (u32)work + 0x16));
    v = (u16)((r & 0xFFF00) >> 8);
    t[0] = v;
    t[1] = 0;
    if (func_002dfd00(v) == 0) {
        *(s8 *)((u8 *)work + 0x10) = func_002dfec0(arg0, 7, t, 0);
    } else {
        *(s8 *)((u8 *)work + 0x10) = func_002dfec0(arg0, 8, t, 0);
    }
}

// FUN_002DFEC0
s32 func_002dfec0(void *arg0, s32 arg1, void *arg2, s8 arg3) {
    s32 v;
    void *t;

    t = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 0xF2C);
    v = func_002bab80(*(void **)((u8 *)t + 0x110));
    if (arg2 != 0) {
        func_002bbd80(v, 0, arg2);
    }
    func_002badc0(v, arg1);
    if (arg3 == 1) {
        func_002bafc0(v, 0);
        func_002bb0a0(v, 0);
        func_002bbf60();
    }
    return v;
}

// FUN_002DFF90
s32 func_002dff90(void *arg0, s32 arg1, void *arg2, void *arg3, s8 arg4) {
    s32 v;
    void *t;

    t = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 0xF2C);
    v = func_002bab80(*(void **)((u8 *)t + 0x110));
    func_002bbd80(v, 0, arg2);
    func_002bbd80(v, 1, arg3);
    func_002badc0(v, arg1);
    if (arg4 == 1) {
        func_002bafc0(v, 0);
        func_002bb0a0(v, 0);
        func_002bbf60();
    }
    return v;
}

// FUN_002E0080
void func_002e0080(void *arg0, s8 arg1, Vec2f arg2, void *arg3) {
    func_00275520(77.0f + arg2.x, arg2.y, 1.0f, (s32)(u32)arg3, 0, 1,
                  (const char *)func_0010d6d0(arg1), 8, 0, D_00795E60);
}

/* measured: 452B/464B, only three zero-tail words. Canonical byte color and
   opacity parameters preserve constant-first loads and the float-first draw
   argument sequence. Distinct p+4 spellings preserve both retail addresses. */
// FUN_002E0100
s32 func_002e0100(void *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);

    func_0043f810((u8 *)work + 4, func_002b89a0(&work->field_4), 0xF0);
    if (func_002e0570(arg0, 0) == 1) {
        if (func_002e0570(arg0, 0xD) == 1) {
            void *t = func_00460990();
            *(void (**)(void))((u8 *)t + 8) = func_002be3c0;
            *(s32 *)((u8 *)t + 0x10) = 0;
            func_00460ac0(&D_00793E80[work->field_FC * 0x30], t);
            func_0025ecd0(
                work->field_2C, work->field_30, work->field_8,
                func_002b2a30(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                (void *)work->field_F4,
                0,
                work->field_100,
                work->field_102,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        } else {
            func_0025ecd0(
                work->field_2C, work->field_30, work->field_8,
                func_002b2a30(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                (void *)work->field_F4,
                1,
                work->field_100,
                work->field_102,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        }
    }
    return 0;
}
// FUN_002E02D0
void func_002e02d0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

/* measured (this wave): func_002e0300's register layout is retail frame 0x50
   ($s0=p, $s1=arg0, $s2=arg2, $s3=arg1, loop counter $t0, base src ptr $a3,
   sign-ext index $a2). mwcc b210 balloons to frame 0x70 with $s0-$s5 for any
   natural spelling (nd 111): the `s32 a1=arg1` local + `src` local force extra
   saved regs and the loop counter lands in $a1 instead of $t0. Also confirmed
   func_0046d200's 2nd arg is (s32)sign-extended arg1 (kept in $5 across the
   loop as loop-invariant, m2c-confirmed), and func_00451fc0's callbacks need
   (void (*)(u8 *)) casts. The recorded best nd 22 (5 variants) not reachable
   via these levers. Loop-temp register-allocation floor. */
// FUN_002E0300
/* measured: retail hoists the loop-invariant 0xFF and 1.0f into the preheader. */
#pragma opt_loop_invariants on
s32 func_002e0300(s32 arg0, s16 arg1, u32 arg2) {
    s32 r;
    u8 *w;
    u8 *src;
    s16 i;
    void *h;
    func_0044ea90(&D_0063FAC0, 0x1D6A);
    w = D_008873F4[0](1, 0x104, 0x40000);
    r = func_00451fc0(arg0, (char *)&D_0063FB70, 0xF, 0, 0,
                      (void (*)(u8 *))func_002e0100, (void (*)(u8 *))func_002e02d0, w);
    w[0] = 0;
    *(s16 *)(w + 0xF8) = arg1;
    *(u32 *)(w + 0xF4) = arg2;
    src = D_0063F560 + arg1 * 8;
    for (i = 0; i < 3; i++) {
        *(f32 *)(w + i * 8 + 0x1C) = *(f32 *)src;
        *(f32 *)(w + i * 8 + 0x20) = *(f32 *)(src + 4);
        w[i + 0x60] = 0xFF;
        *(f32 *)(w + i * 4 + 0x98) = 1.0f;
        *(f32 *)(w + i * 4 + 0x8C) = 1.0f;
        *(s32 *)(w + i * 4 + 0xBC) = 0;
        w[i * 4 + 0x73] = 0xFF;
        w[i * 4 + 0x72] = 0xFF;
        w[i * 4 + 0x71] = 0xFF;
    }
    *(f32 *)(w + 8) = 100.0f;
    *(u32 *)(w + 0xFC) = 0x55;
    *(s16 *)(w + 4) = 0;
    h = func_0046d200(*(void **)(w + 0xF4), arg1);
    *(s16 *)(w + 0x100) = (s32)(func_0046b260(h) / 2.0f);
    *(s16 *)(w + 0x102) = (s32)(func_0046b2f0(h) / 2.0f);
    func_0046d280(h);
    return r;
}
// measured: closes the opt_loop_invariants bracket opened above and restores
// the -O2 baseline for the rest of the file.
#pragma opt_loop_invariants off

