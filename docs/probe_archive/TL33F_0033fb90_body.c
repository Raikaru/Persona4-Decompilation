/* fresh 2026-08-14 verify: object_size=108 window=112 normalized_diff=8
 * differing_offsets=0x38,0x3c; relocation-only differing_offset=0x54.
 * Retail's epilogue is jr $ra at +0x64 with nop at +0x68; +0x6c..+0x6f
 * are zero padding, so the four-byte window gap is not a missing epilogue.
 * Corrected callee: func_0036dd10(void *, void *, f32).
 * Classification: MWCCPS2 b210 constant-selection floor. The candidate
 * consistently emits addiu +0x7fff; +0x6399 instead of retail ori 0xE398;
 * addu. Direct/u32/u16/unsigned-literal/named-displacement initializers and
 * assignments, combined and split displacement expressions, compound-OR
 * construction, helper passthroughs, pointer/array/struct-field address
 * forms, argument/type-width variants, helper operand order, and
 * opt_propagation/optimization probes remain ruled out.
 */
void func_0033fb90(u8 *arg0, s8 arg1, s64 arg2, f32 fp) {
    s64 sp18 = arg2;
    u32 p;
    u32 offset;

    p = *(u32 *)(*(u8 **)(*(u8 **)(arg0 + 0x38) + 4) + 0x38);
    offset = (u32)((s32)arg1 * 0xFB0);
    func_0036dd10((u8 *)(p + offset + 0xE398), &sp18, 90.0f * fp);
}
