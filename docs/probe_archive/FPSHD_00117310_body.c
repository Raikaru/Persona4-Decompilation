/* Recovered faithful number-rendering candidate; production remains ASM.
 * MWCCPS2 b210: object 388B / window 400B / differing words 9.
 * Six emitted prologue words rotate the mode argument save before the
 * coordinate spill, float argument, color, number and id copies. Retail
 * saves mode last. The remaining three words are absent zero tail padding.
 * Scoped loop invariants fix the mode-loop preheader; all instructions
 * from offset 0x40 through return match. Keep the actual s64 packed pair
 * and full s32 mode ABI, unsigned division and the zero-number draw.
 * Existing shdPackedLow supplies the low color byte. Register hints,
 * declaration initializers, direct arguments, unsigned mode and lifetimes
 * did not close the prologue. Disabling propagation scored 83 words.
 * Separate alpha lifetime, draw-only alpha scope, a phase union and a
 * placement snapshot retain nine words. Input and render snapshots give
 * 21 and 32 respectively. Retain this simpler faithful candidate.
 * IDA-first replay confirms unsigned digit traversal, but Hex-Rays omits
 * the mode-zero alignment branch, drawing floats and post-draw decrement.
 * Assembly and the caller retain the packed position/color ABI above.
 * A four-byte color aggregate still gives nine words; a local position
 * aggregate gives 89 words (404B/400B). Keep this body unchanged.
 */
#pragma push
#pragma opt_loop_invariants on
void func_00117310(s64 arg0, f32 fparg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    union { s64 bits; Vec2f xy; } sp70;
    s32 packed;
    f32 farg;
    f32 f;
    u32 n;
    u32 id;
    s32 mode;
    u8 b2;
    u8 b1;
    u32 rem;
    f32 y;

    sp70.bits = arg0;
    farg = fparg0;
    packed = arg1;
    n = arg2;
    id = arg3;
    mode = arg4;
    y = sp70.xy.y;
    if (id == 0) {
        func_0046d730(D_005E4868, 0x424);
    }
    if (mode != 0) {
        f = sp70.xy.x;
        rem = n;
        while (rem >= 10U) {
            f += 16.0f;
            rem = rem / 10U;
        }
    } else if (n < 10U) {
        f = 8.0f + sp70.xy.x;
    } else {
        f = 16.0f + sp70.xy.x;
    }
    b2 = *((u8 *)&packed + 2);
    b1 = *((u8 *)&packed + 1);
    mode = 0xFF;
    mode -= *((u8 *)&packed + 3);
    do {
        func_0046d4c0(0, id, (n % 10U) + 9,
                      f, y, (u8)mode, shdPackedLow(&packed), b1, b2,
                      farg, 0);
        n = n / 10U;
        f -= 16.0f;
    } while (n != 0);
}
#pragma pop
