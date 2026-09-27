/* Sony SDK libkernl.a:timer.o, SetT2_COUNT at 0x0042C300.
 * Retail: 16 bytes. MWCCPS2 b210 with tailcall/schedule on: 16 bytes,
 * normalized_diff 2 (offsets 4 and 12: lui $v0 / ori $a0,$v0 instead
 * of retail's lui $a0 / ori $a0,$a0). A pointer-typed first argument,
 * an integer-typed one, and opt_propagation off all give that result.
 * ee-gcc 2.96 -O2: 32 bytes, normalized_diff 7 (adds an RA frame);
 * both a plain void call and return of the void call were tested.
 * The adjacent SetT2_MODE/SetT2_COMP have the same retail shape with
 * different MMIO offsets; their candidate source was not separately diffed.
 * Leave the three holding-unit INCLUDE_ASM fallbacks until a source shape
 * reproduces the register allocation without instruction-level forcing.
 */
extern void func_0042c290(unsigned reg, unsigned value);
#pragma tailcall on
#pragma schedule on
void SetT2_COUNT(unsigned value)
{
    func_0042c290(0xB0001000, value);
}
#pragma schedule off
#pragma tailcall off
