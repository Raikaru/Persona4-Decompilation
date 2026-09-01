/* Best clean-C candidate for func_0048aff0 (src/promoted/code1_0048.c).
 * Replaces a banned raw __asm__ block (H009: inline asm emitting ordinary
 * MIPS instructions with no privileged/COP2/VU0 op) that was hand-written
 * to force a MATCH. This honest reconstruction, keyframe-interpolation
 * logic confirmed against Ghidra's independent decompile of the retail
 * function, reaches object 560B == window 560B, normalized_diff 12 (97.9%
 * byte match).
 * The residual is 3 symmetric operand-order swaps (subu/div.s)
 * inside the mode==1 and mode==2 sub-range branches: retail computes
 * the interpolation denominator (hi-lo) into $f1 before the numerator
 * (pos-lo) into $f0, then divides f0/f1; MWCC's -O2 instruction
 * scheduler reorders these two independent subtractions based on its own
 * dependency heuristic, NOT source statement order -- confirmed by testing
 * both textual orders (numerator-first single expression, and an explicit
 * denom-temp computed in a separate statement before the numerator) and
 * getting byte-identical output either way. Differing word offsets were
 * 216, 232, 248, 400, 416, 432, 464, 480, and 496. A static helper function
 * for the "frac" computation was not inlined by MWCC at -O2 (became a real
 * call, nd shot up to 313). #pragma schedule off did not change this
 * function's residual and broke 7 unrelated MATCHes later in the file
 * (global toggle, not block-scoped). The plain-C return reproduced the
 * retail COP1 accumulator chain (adda.s/madd.s at offsets 544/548); this
 * was not a floor. The residual was subsequently closed at nd 0 by a
 * balanced, measured #pragma opt_propagation off around the target.
 * Ruled out: alternate subtraction statement order, explicit denominator
 * temporary, static helper call, and #pragma schedule off.
 * This file preserves the pre-fix nd12 probe candidate for future reference.
 */
f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 mode;
    f32 from;
    f32 to;
    f32 t;
    f32 fArg2;

    if (arg2 == 0) {
        return *(f32 *)(arg0 + 4);
    }

    fArg2 = (f32)arg2;
    mode = *(u8 *)arg0;
    switch (mode) {
    case 0:
        from = *(f32 *)(arg0 + 4);
        to = *(f32 *)(arg0 + 8);
        t = (f32)arg1 / fArg2;
        break;
    case 1: {
        s32 v1 = (s32)(*(f32 *)(arg0 + 0x18) * fArg2);
        if (arg1 < v1) {
            from = *(f32 *)(arg0 + 4);
            to = *(f32 *)(arg0 + 0x14);
            t = (f32)arg1 / (f32)v1;
        } else {
            f32 denom;
            from = *(f32 *)(arg0 + 0x14);
            to = *(f32 *)(arg0 + 8);
            denom = (f32)(arg2 - v1);
            t = (f32)(arg1 - v1) / denom;
        }
        break;
    }
    case 2: {
        s32 t1 = (s32)(*(f32 *)(arg0 + 0x18) * fArg2);
        if (arg1 < t1) {
            from = *(f32 *)(arg0 + 4);
            to = *(f32 *)(arg0 + 0x14);
            t = (f32)arg1 / (f32)t1;
        } else {
            s32 t2 = (s32)(*(f32 *)(arg0 + 0x20) * fArg2);
            if (arg1 < t2) {
                from = *(f32 *)(arg0 + 0x14);
                to = *(f32 *)(arg0 + 0x1c);
                {
                    f32 denom = (f32)(t2 - t1);
                    t = (f32)(arg1 - t1) / denom;
                }
            } else {
                f32 denom;
                from = *(f32 *)(arg0 + 0x1c);
                to = *(f32 *)(arg0 + 8);
                denom = (f32)(arg2 - t2);
                t = (f32)(arg1 - t2) / denom;
            }
        }
        break;
    }
    default:
        from = *(f32 *)(arg0 + 4);
        to = *(f32 *)(arg0 + 8);
        t = 0.0f;
        break;
    }

    return from + t * (to - from);
}
