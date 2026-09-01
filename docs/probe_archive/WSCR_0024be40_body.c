/* object 672B/window 672B (exact size), normalized_diff 8; differing offsets 196, 236, 480, 492, 520, 544, 556, 560 are table index/element-pointer register cycling. Retail int-to-float sites: +0x118 (bltz/mtc1/cvt.s.w; negative srl/andi/or/mtc1/cvt.s.w/add.s) and +0x16C (same sequence), both written as (f32)(u32); retail float-to-int site +0x1BC/+0x1D0 (trunc.w.s/mfc1, high path adds 0x80000000), written as (s32)(u32)product. Corrected func_00246e10 is block-scope extern s32(s32); file-scope u8*(u16) retained for cmmScript.c:1477. Fresh probes ruled out declaration-order/statement variants (base/found/i positions, scoped i, second-loop for form, swapped initializers), pointer split/integer-domain/reversed-operand forms, split found flag, and found declaration initialization; all preserve nd 8 except second-loop initializer swap nd 9 and i-after-base/inner-scope variants nd 12. O1 grows to 680B/window 672B (nd 467). Hoisting the pointer assignment above the first-loop call worsened the residual to nd 13; the $s2/$s0 pointer/counter cycle survived declaration swap, scoped propagation-off, and hoist probes. The archived body remains the best near-miss. */
// FUN_0024BE40
s32 func_0024be40(void)
{
    extern void* func_00452560();
    s32 month;
    extern s32 func_00246e10(s32 arg0);
    s32 day;
    s32 sum;
    s32 i;
    u8* work;
    f32 random_f;
    f32 sum_f;
    f32 product;
    u8* found;
    s32 index;
    s32 sum2;
    s32 j;
    u8* base;

    found = 0;
    index = 0;
    func_001104d0(func_001060b0(), &month, &day);
    base = (u8*)func_00246e10((u16)month);
    if ((func_001060c0() & 0xFF) == 5) {
        index = 2;
    }
    if ((s8)func_00110960(func_001060b0(), func_001060c0() & 0xFF) == 1) {
        found = (u8*)1;
    }
    index = index + (s32)found;
    sum = 0;
    j = 0;
    {
        found = base + index * 6;
        while (j < 6) {
            if ((j != 0) || (func_00106330(2703) != 0)) {
                sum += *(s8*)(found + j);
            }
            j++;
        }
        random_f = (f32)(u32)func_003b7060();
        random_f /= 2147483648.0f;
        sum_f = (f32)(u32)sum;
        product = sum_f * random_f;
        sum = (s32)(u32)product;
        sum2 = 0;
        i = 0;
        while (i < 6) {
            if ((i != 0) || (func_00106330(2703) != 0)) {
                sum2 += *(s8*)(found + i);
                if ((s32)sum < (s32)sum2) {
                    sum = i;
                    break;
                }
            }
            i++;
        }
    }
    work = (u8*)(u32)func_00452560((void*)(u32)func_00452380((s8*)D_00635A78));
    if (work == 0) {
        func_0046d730(D_006359F0, 1041);
    }
    *(s32*)(work + 32) = sum;
    return sum;
}
/* measured: the archived C reconstruction for func_0024c0e0 reached nd 35
   at object 892B/window 896B. Its FMA accumulator order, mov.s/address-load
   scheduling and mfc1 colouring residuals exceed the park threshold; the
   body and ruled-out probe list are preserved in
   build/W8CmmScript_c0e0_archive.json, so the bare INCLUDE_ASM fallback remains. */
