#include "include_asm.h"
#include "type.h"

/* Encounter-selection helpers (Kosaka unit).
 *
 * gp-relative globals (GP base 0x007690F0, see config/symbol_data_addrs.txt):
 *   iGpffffb41c (gp-0x4BE4 = 0x0076450C) -- pointer to the 10-byte encounter
 *       table entries (u16 id at +0, u8 flags/rates at +2/+3/+4, u16 at +6)
 *   iGpffffb418 (gp-0x4BE8 = 0x00764508) -- pointer to the 0xF8-stride
 *       per-encounter sub-table (two 0x78 halves, selected by the bool flag)
 *   iGpffffb424 (gp-0x4BDC = 0x00764514) -- pointer to the 0x15C-stride
 *       encounter-record table used by func_00161c80
 */

extern s32 func_0014a230();
extern s32 func_0014a2a0();
extern s32 func_0015a740();
extern s64 func_001060b0();
extern s32 func_001060c0();
extern s64 func_00110960();
extern s32 func_00106330();
extern u32 func_003b7060();
extern void func_0046d730();
extern u8 *iGpffffb41c;
extern u8 *iGpffffb418;
extern u8 *iGpffffb424;
extern u8 D_005F1260[];
extern u8 D_005F12C8[];
extern u8 D_007E80A0[];

/* measured: retail loads the gp pointer iGpffffb41c FIRST (lw $a0,-0x4BE4($gp))
   then the *10 index chain, ending addu $v0,$v0,$a0; mwcc b210 sinks the load to
   its use (lw $v0 after the chain) and flips the final addu to $v0,$v0,$v1 with
   the chain in $v1. Tried: plain expr, base u8* local, m2c operand order
   (chain+base), fully split statements (base/m/idx) — all nd 8, identical
   bytes. Load-sinking + addu-flip floor (recorded in brief). */
// FUN_00161A70
INCLUDE_ASM("asm/nonmatchings/k_encount", func_00161a70);

/* measured: identical shape to FUN_00161A70 (same gp pointer, lbu at +4):
   retail lw $a0,-0x4BE4($gp) FIRST then the *10 chain, addu $v0,$v0,$a0;
   mwcc b210 sinks the load and flips the addu ($v0,$v0,$v1) — nd 8, single
   attempt. Load-sinking + addu-flip floor. */
// FUN_00161B10
INCLUDE_ASM("asm/nonmatchings/k_encount", func_00161b10);

/* measured: identical load-sinking residual to FUN_00161A70/61B10 — retail
   lw $v1,-0x4BE4($gp) FIRST then the *10 chain (andi in $a0, reused as the
   func_0015a740 arg); mwcc b210 sinks the load after the chain (lw $v0) and
   shifts the chain's final sll to $v1 — nd 8, 5 rows. Everything else
   (call-arg reuse, slti/beqz/move) matches. Load-sinking floor. */
// FUN_001619B0
INCLUDE_ASM("asm/nonmatchings/k_encount", func_001619b0);

/* measured: loop structure and base-hoist now reproduce (typed pointer locals
   for D_005F1260/D_007E80A0; (s32)temp_10 casts and s16 temp_4 each force a
   dsll32/dsra32 extension pair mwcc b210 emits but retail lacks; (u16) cast
   adds an andi) — best nd 44-45. Residual: pervasive temp-register allocation
   (retail $t4/$t2/$t1/$a1/$t3/$a3/$t0, mwcc $v1/$t1/$t0/$a3/$t2/$a1/$a2),
   constants 1/-1 materialized in-loop vs retail hoisted to entry, and the
   outer-compare extension problem (retail compares the raw lh result against
   the s64 temp_10 with one bne; b210 cannot be made to do this without an
   extra instruction). 4 attempts: 49/44/44/45. */
// FUN_00161BB0
INCLUDE_ASM("asm/nonmatchings/k_encount", func_00161bb0);

/* measured: nd 307 with a full C body (object 872B against a 896B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
// FUN_00161630
INCLUDE_ASM("asm/nonmatchings/k_encount", func_00161630);

// FUN_00161C80
INCLUDE_ASM("asm/nonmatchings/k_encount", func_00161c80);
