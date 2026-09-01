/* measured: object 328 bytes, retail window 288 bytes, normalized_diff 78.
 * Retail conversion site: lbu 3($t1) followed by mtc1/cvt.s.w and the
 * unsigned split path; source uses plain (f32)(u32)*(u8 *)(arg1 + 3).
 * Ruled out: direct plain C, explicit local/register declarations, omitted
 * and old-style func_0047ef10 declarations, interleaved parameter order,
 * opt_propagation off, and optimization_level 1. */
void func_0047f1a0(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1)
{
    s32 index;

    index = func_0047ef10(arg0, fparg0);
    if ((u32)index >= (u32)(*(s32 *)arg0 - 1)) {
        fGpffffbb4c = *(f32 *)(*(u8 **)(arg0 + 0xC) + (index * 8) + 4);
    } else {
        u8 *point = *(u8 **)(arg0 + 0xC) + (index * 8);
        f32 x0 = *(f32 *)(point + 0);
        f32 y0 = *(f32 *)(point + 4);
        f32 ratio = (fparg0 - x0) / (*(f32 *)(point + 8) - x0);
        f32 y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = y0 + ((y1 - y0) * ratio);
    }
    fGpffffbb48 = fparg0;
    fGpffffbb4c = fGpffffbb4c +
        ((1.0f - ((f32)(u32)*(u8 *)(arg1 + 3)) / 255.0f) - fGpffffbb4c) * fparg1;
}
