/* REVERTED AFTER LINK CHECK -- read before retrying.
 *
 * This body scored MATCH under scoped verify.py (object 504B, window 512B,
 * normalized_diff 0) and was committed-ready, but the FULL link check rejected
 * it and it was reverted.
 *
 * What happened: the body carries an R_MIPS_HI16/LO16 pair at offsets 52/56
 * against the compiler-local symbol `@165`, whose retail immediates resolve to
 * 0x00758020. That address holds a STRING literal in retail (bytes
 * "6f616420706172746974696f6e2900" = "oad partition)", i.e. the tail of a
 * longer message), not a float constant. verify.py masks relocations, so the
 * two code words compare equal no matter what the referenced data actually is
 * -- the match was real for the instructions and meaningless for the operand.
 *
 * tools/build.py's eligibility pass caught it (`ELIG-FAIL body/reloc at
 * func_00266690`) because it must resolve every relocation to a real placeable
 * address. The consequence was worse than one bad function: the whole
 * cldDayChange.c translation unit lost link eligibility, dropping the linked
 * TU count 166 -> 165 and taking all TEN of the unit's functions out of the
 * from-source link (linked_function_count 1815 -> 1805). Both image SHA1s
 * still verified OK, because an ineligible TU silently falls back to retail
 * bytes -- so SHA1 alone does NOT protect against this.
 *
 * Also suspect on its own terms: the closure lever was described as passing
 * 0.0f rather than 336.0f for a hidden fifth float argument. Substituting a
 * different constant is exactly the kind of change relocation masking hides.
 *
 * To retry: reproduce retail's actual referenced data. Find the string that
 * ends at 0x00758020, write that literal into the source so the TU's rodata
 * lands at retail's address, and re-check with a full `tools/build.py
 * --progress-report` confirming linked_tu_count stays at 166 -- not just with
 * lverify.
 */

/* func_00266690 near-miss probe; object 504B; retail window 512B; normalized_diff 8 words in fndiff's reloc-masked report; differing byte offsets 0x34-0x3B (jump-table relocation pair), 0x9C-0xA8 (first adda.s constant/FPR orientation), and 0x190-0x19C (second adda.s constant/FPR orientation). Ruled out: fifth-float 336.0f at the two dynamic func_00266050 calls, signed p+0x10 expressions for the second func_00265110 calls, prior declaration/intermediate-name and arithmetic-spelling variants, and opt_propagation/schedule probes. Plain C reproduced all four retail COP1 accumulator operations (two adda.s/madd.s chains and two adda.s/msub.s chains); the chain was not the residual. The final closure changed the dynamic func_00266050 fifth argument to 0.0f and retained u32 p+0x10 casts only on the second func_00265110 calls. */
void func_00266690(s32 arg0, s32 arg1)
{
    u8 *p;
    s32 state;
    s32 alpha;
    f32 ratio;
    f32 value;

    p = func_00452560(arg1);
    state = *(s32 *)(p + 0) - 4;
    switch (state) {
    case 0:
    case 1:
        ratio = (f32)*(s32 *)(p + 0x18) / 7.0f;
        alpha = (s32)(255.0f * ratio);
        value = 336.0f + 128.0f * func_0044b610(iGpffff8570 * ratio);
        func_00266050((s32)value, 0, alpha, *(s32 *)(p + 0x10), 336.0f);
        func_00265110(0x150, 0, 0.0f, alpha, *(u32 *)(p + 0x10),
                      *(s32 *)(p + 0x1C));
        break;
    case 2:
    case 3:
        func_00266050(0x150, 0, 0xFF, *(s32 *)(p + 0x10), 0.0f);
        func_00265110(0x150, 0, 0.0f, 0xFF, *(u32 *)(p + 0x10),
                      *(s32 *)(p + 0x1C));
        break;
    case 4:
    case 5:
        ratio = (f32)*(s32 *)(p + 0x18) / 10.0f;
        alpha = (s32)(255.0f * (1.0f - ratio));
        value = 336.0f - 192.0f * func_0044b7b0(iGpffff8570 * ratio);
        func_00266050((s32)value, 0, alpha, *(s32 *)(p + 0x10), 336.0f);
        func_00265110(0x150, 0, 0.0f, alpha, *(u32 *)(p + 0x10),
                      *(s32 *)(p + 0x1C));
        break;
    }
}
