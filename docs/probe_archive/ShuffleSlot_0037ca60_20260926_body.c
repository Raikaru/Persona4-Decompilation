/* func_0037ca60 (src/Battle/btlShuffleSeqShuffle4.c), 2026-09-26.
 * Measured with tools/fndiff.py: 50 reloc-masked differing words, object
 * 2052B in the 2064B window; fnalign 513/513 instructions. Previous floor
 * was 99 words at 2036B.
 *
 * Lever that closed the frame: the slot position is a local two-float
 * struct copied out once at the end (`*(CardSlotPos *)arg2 = pos;`).
 * Retail builds it at 0x48/0x4C(sp) in a 0x50 frame and copies it through
 * lwc1/swc1. Writing arg2[0]/arg2[1] directly gives the 0x40 frame; a local
 * f32[2] or anonymous struct copied member-wise is promoted to registers
 * and the object shrinks to 1980B.
 *
 * Residual (all 50 words): in the five branches whose column is the bare
 * `(f32)arg1` (the first row of cases 8/10/12/14/16), retail materialises
 * 80.0f into $f3 before converting arg1 and multiplies 80*diff; here the
 * subtraction is built first and 80.0f lands in $f2. Branches with
 * `(f32)(arg1 - k)` already match. Tied at 50: operands swapped, implicit
 * int conversion, `(f32)(arg1 - 0)`, a spacing local (propagated back to the
 * literal), and every pragma except the ones that cost 431-564.
 */

/* Round 2 (2026-09-26): 50 -> 25 words. In the five bare-column branches a
 * float local assigned as its own statement (`col = arg1;` then
 * `320.0f + 80.0f * (col - 1.5f)`) gives retail's register assignment
 * (80.0f in $f3, the difference in $f2). The residual 5 words per branch are
 * pure order: retail materialises 80.0f (lui/mtc1) BEFORE `mtc1 $s1; cvt`,
 * i.e. evaluates `80.0f * ((f32)arg1 - k)` left operand first, while every
 * source shape here converts first. Measured and tied/worse: `col` for the
 * `arg1 - k` branches too (116), inline helpers taking s32 or f32 column (50),
 * `(w = arg1) - k` (50), `col` hoisted above the switch or the call (428/498),
 * `(f32)(arg1 + 0 | * 1 | | 0)` (50), operand swaps and `x*80 + 320` (25),
 * function-scope `#pragma opt_propagation off` with or without a spacing
 * local (510). btlShuffleCalc.c's matched sibling (the 100.0f table) shows
 * the same bare/offset asymmetry and only matched with propagation off and
 * register-shaped temps, so the order is likely a compiler weight quirk of
 * `cvt(var)` vs `cvt(expr)`.
 */
typedef struct { f32 x; f32 y; } CardSlotPos;
void func_0037ca60(u8 *arg0, s32 arg1, f32 *arg2) {
    s32 n;
    CardSlotPos pos;
    f32 col;
    if (*(s32 *)(arg0 + 0x1F2FC) != 3) {
        func_0046d730(&D_0064EB20[0], 0x5B);
    }
    n = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    switch (n) {
    case 6:
        pos.x = 320.0f + 80.0f * ((f32)(arg1 % 3) - 1.0f);
        pos.y = 224.0f + 100.0f * ((f32)(arg1 / 3) - 0.5f);
        break;
    case 8:
        if (arg1 < 4) {
            col = arg1;
            pos.x = 320.0f + 80.0f * (col - 1.5f);
            pos.y = 174.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 4) - 1.5f);
            pos.y = 274.0f;
        }
        break;
    case 10:
        if (arg1 < 3) {
            col = arg1;
            pos.x = 320.0f + 80.0f * (col - 1.0f);
            pos.y = 74.0f;
        } else if (arg1 < 5) {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 3) - 0.5f);
            pos.y = 174.0f;
        } else if (arg1 < 7) {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 5) - 0.5f);
            pos.y = 274.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 7) - 1.0f);
            pos.y = 374.0f;
        }
        break;
    case 12:
        if (arg1 < 3) {
            col = arg1;
            pos.x = 320.0f + 80.0f * (col - 1.0f);
            pos.y = 74.0f;
        } else if (arg1 < 6) {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 3) - 1.0f);
            pos.y = 174.0f;
        } else if (arg1 < 9) {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 6) - 1.0f);
            pos.y = 274.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 9) - 1.0f);
            pos.y = 374.0f;
        }
        break;
    case 14:
        if (arg1 < 4) {
            col = arg1;
            pos.x = 320.0f + 80.0f * (col - 1.5f);
            pos.y = 74.0f;
        } else if (arg1 < 7) {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 4) - 1.0f);
            pos.y = 174.0f;
        } else if (arg1 < 11) {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 7) - 1.5f);
            pos.y = 274.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 11) - 1.0f);
            pos.y = 374.0f;
        }
        break;
    case 16:
        if (arg1 < 4) {
            col = arg1;
            pos.x = 320.0f + 80.0f * (col - 1.5f);
            pos.y = 74.0f;
        } else if (arg1 < 8) {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 4) - 1.5f);
            pos.y = 174.0f;
        } else if (arg1 < 12) {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 8) - 1.5f);
            pos.y = 274.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(arg1 - 12) - 1.5f);
            pos.y = 374.0f;
        }
        break;
    default:
        func_0046d730(&D_0064EB20[0], 0x116);
        break;
    }
    *(CardSlotPos *)arg2 = pos;
}
