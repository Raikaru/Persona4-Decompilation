// E3E archive: func_003e4030 best normalized_diff 51, object 108B / window 128B.
// Math is byte-exact from offset 0x00 through the FMAs; sole residual is b210
// scheduling: retail hoists mtc1 zero,$f1 above the FMA chain (len stays in
// $f0, the accumulator register) while every probed source shape sinks the
// zero after sqrt.s into $f0 and holds len in $f1. Probed levers (all nd=51
// unless noted): addend orders 0-1-4 / 2-1-4 (nd 53), staged += chain,
// sum-variable split, ternary, !(len<=0), len>0, empty-then else, condition
// assignment, f32 zero variable, schedule on, register storage class.
// Retail window for reference:
//   lwc1 f2,4(a1); lwc1 f3,0(a1); lwc1 f0,8(a1); mtc1 zero,f1;
//   mula f2,f2; madda f3,f3; madd f0,f0,f0; sqrt f0,f0; nop; nop;
//   c.ole f0,f1; bc1t +8; nop; lui v0,0x3F80; mtc1 v0,f1; nop;
//   div f0,f1,f0; nop x3; mul f1,f3,f0; swc1 f1,0(a0);
//   lwc1 f2,4(a1); lwc1 f1,8(a1); mul f2,f2,f0; mul f1,f1,f0;
//   swc1 f2,4(a0); jr ra; swc1 f1,8(a0)
void func_003e4030(u8 *arg0, u8 *arg1) {
    f32 len;

    len = sqrtf(((*(f32 *)(arg1 + 0) * *(f32 *)(arg1 + 0)) + (*(f32 *)(arg1 + 4) * *(f32 *)(arg1 + 4))) + (*(f32 *)(arg1 + 8) * *(f32 *)(arg1 + 8)));
    if (len <= 0.0f) {
    } else {
        len = 1.0f / len;
    }
    *(f32 *)(arg0 + 0) = *(f32 *)(arg1 + 0) * len;
    *(f32 *)(arg0 + 4) = *(f32 *)(arg1 + 4) * len;
    *(f32 *)(arg0 + 8) = *(f32 *)(arg1 + 8) * len;
}
