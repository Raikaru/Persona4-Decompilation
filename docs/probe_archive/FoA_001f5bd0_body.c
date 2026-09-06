/*
 * func_001f5bd0 archive (FoA)
 * Best measured lane: native unsigned casts with the grouped ratio expression.
 * Best measured result: object 708 bytes / retail window 720 bytes; 10 differing words.
 * Retail saved registers: $s0, $f20, $f21, $f22, $f23, $ra.
 *
 * Native casts alone reproduce the previous 12-word result: the five outer
 * random_value >= 0 checks were unsigned tautologies, not the emitted sign
 * tests. MWCC supplies the retail unsigned-to-float conversion branches.
 * Combining the final ratio expression without changing its operation tree
 * fixes both multiply operand orders. Seven executable words (12 bytes)
 * remain: the first two results exchange f20/f21 and their division follows
 * that coloring. The other three differing words are zero tail padding.
 * The body remains archived; no floating-point reassociation or ABI change.
 *
 * Probes attempted: baseline natural C; u32 value/half; opt_propagation on;
 * switch entry CFG; FP multiplication order variants; direct/helper pointer
 * arithmetic; canonical unsigned random_value/bits conversion; separate bit
 * temporary; conditional call assignment; u64 temporary; floating role swaps;
 * declaration-order permutations; mixed signed/unsigned conversion spelling.
 */
#pragma push
#pragma opt_propagation off
void func_001f5bd0(s32 arg0)
{
    u32 mask;
    unsigned int random_value;
    f32 fourth;
    f32 third;
    f32 first;
    f32 second;
    f32 random_ratio;
    f32 ratio;
    u16 result;

    mask = ((1 << (u16)arg0) & 0xFFFF);
    *(u16 *)(iGpffffb3ac + 0xA48) =
        (u16)(*(u16 *)(iGpffffb3ac + 0xA48) | mask);
    switch ((u16)arg0) {
    case 0:
        goto body;
    default:
        goto done;
    }
body:
    second = (f32)(u32)func_001ef5f0(1, 3, 0x80000);
    first = (f32)(u32)func_001ef5f0(2, 3, 0x80000);
    fourth = (f32)(u32)func_001ef5f0(1, 4, 0x80000);
    third = (f32)(u32)func_001ef5f0(2, 4, 0x80000);

    random_value = func_00231d70(0xF) + 5;
    random_ratio = (f32)random_value;
    random_ratio /= 10.0f;
    ratio = random_ratio * (30.0f * ((second / first) * (fourth / third)));
    if (ratio > 50.0f) {
        ratio = 50.0f;
    } else if (ratio < 10.0f) {
        ratio = 10.0f;
    }
    {
        s32 offset;
        u8 *p;
        offset = (u16)arg0 * 4;
        p = (u8 *)(offset + (s32)iGpffffb3ac);
        *(u16 *)(p + 0xA44) = 0;
        result = (u16)(100.0f / ratio);
        offset = (u16)arg0 * 4;
        p = (u8 *)(offset + (s32)iGpffffb3ac);
        *(u16 *)(p + 0xA46) = result;
    }
done:
    ;
}
#pragma opt_propagation on
#pragma pop
