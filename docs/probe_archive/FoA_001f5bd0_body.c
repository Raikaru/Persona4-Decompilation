/*
 * func_001f5bd0 archive (FoA)
 * Best measured lane: FoA5bd0roleswap
 * Best measured result: object 708 bytes / retail window 720 bytes; 12 differing words.
 * Retail saved registers: $s0, $f20, $f21, $f22, $f23, $ra.
 *
 * Best measured body retained the canonical unsigned conversion idiom from
 * func_00249960, swapped floating result roles to obtain the retail f22/f23
 * assignment, and used a signed offset local plus comma-address expression for
 * the indexed global stores. Remaining differences were first/second FPR
 * assignment, two multiplication operand orders, and the first/second ratio
 * division operand order.
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
    u32 bits;
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
    random_value = func_001ef5f0(1, 3, 0x80000);
    if (random_value >= 0) {
        second = (f32)random_value;
    } else {
        bits = (u32)random_value;
        second = (f32)((s32)((bits >> 1) | (bits & 1)));
        second = second + second;
    }
    random_value = func_001ef5f0(2, 3, 0x80000);
    if (random_value >= 0) {
        first = (f32)random_value;
    } else {
        bits = (u32)random_value;
        first = (f32)((s32)((bits >> 1) | (bits & 1)));
        first = first + first;
    }
    random_value = func_001ef5f0(1, 4, 0x80000);
    if (random_value >= 0) {
        fourth = (f32)random_value;
    } else {
        bits = (u32)random_value;
        fourth = (f32)((s32)((bits >> 1) | (bits & 1)));
        fourth = fourth + fourth;
    }
    random_value = func_001ef5f0(2, 4, 0x80000);
    if (random_value >= 0) {
        third = (f32)random_value;
    } else {
        bits = (u32)random_value;
        third = (f32)((s32)((bits >> 1) | (bits & 1)));
        third = third + third;
    }

    random_value = func_00231d70(0xF) + 5;
    if (random_value >= 0) {
        random_ratio = (f32)random_value;
    } else {
        bits = (u32)random_value;
        random_ratio = (f32)((s32)((bits >> 1) | (bits & 1)));
        random_ratio = random_ratio + random_ratio;
    }
    random_ratio /= 10.0f;
    ratio = second / first;
    ratio = ratio * (fourth / third);
    ratio = 30.0f * ratio;
    ratio = random_ratio * ratio;
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
