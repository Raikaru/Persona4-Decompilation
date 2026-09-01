/* object 320B/window 368B, normalized_diff 88, differing offsets 0x008-0x13C plus 0x140-0x168 (88 differing words; object undersized); classification: MWCC near-miss from generated IEEE-float-to-half candidate, with major register/statement-order divergence and missing retail tail blocks. Retail prologue: addiu $sp,-16; swc1 $f12,12($sp); lw $v0,12($sp). Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature. No callee or global declarations involved; union bit-punning candidate measured once and restored immediately. */
// FUN_00415960
u16 func_00415960(f32 fparg0)
{
    union {
        f32 f;
        u32 u;
    } value;
    union {
        f32 f;
        u32 u;
    } adjust;
    u32 bits;
    s32 exponent;
    u16 result;

    value.f = fparg0;
    bits = value.u;
    if ((bits & 0xFFF) >= 0x800) {
        exponent = (s32)((bits & 0x7F800000) >> 0x17);
        if (exponent >= 0xD &&
            (exponent < 0xFE || (bits & 0x007FF000) != 0x007FF000)) {
            adjust.u = (bits & 0x80000000) | (u32)((exponent - 0xC) << 0x17);
            value.f += adjust.f;
            bits = value.u;
        }
    }
    bits &= ~0xFFF;
    value.u = bits;
    if ((bits & 0x7F800000) >= 0x3F800001)
        value.u = (bits & 0x80000000) | 0x7FFFF000;
    bits = value.u;
    if ((bits & 0x7F800000) < 0x38000000)
        value.u = bits & 0x80000000;
    bits = value.u;
    result = (u16)((bits >> 0x10) & 0x8000);
    if ((bits & 0x7FFFFFFF) != 0) {
        result = (u16)(result |
                       ((((bits >> 0x17) & 0xFF) - 0x70) << 0xB) |
                       ((bits >> 0xC) & 0x7FF));
    }
    return result;
}
