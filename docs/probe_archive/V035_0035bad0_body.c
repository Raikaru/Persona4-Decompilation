/* object_size=320B; window=320B; normalized_diff=4 for the first plain-C
   candidate; differing_offsets=0xE9-0xEA, 0x115-0x116. That candidate
   reproduced the complete four-op COP1 chain (adda.s + madd.s twice), but
   named call-result locals left each madd as 0x4602001c
   (madd.s fd=$f0, fs=$f0, ft=$f2) instead of retail 0x4600101c
   (madd.s fd=$f0, fs=$f2, ft=$f0). The final inline-call form below closes
   the target at normalized_diff 0: keeping func_0044b7b0 directly in each
   multiply lets b210 preserve the source operand order. The accumulator
   chain itself is plain C; no inline asm or intrinsic was used.

   Ruled out before the inline-call closure: original temporary-counter
   spelling (nd 14, with extra v1/v0 prologue words); direct-expression
   operand swap with named temp_f0 (still nd 4); split curve_0/curve_1
   call-result locals (still nd 4); hoisted delta locals (328B, nd 76);
   ordered helper/product staging (304B, nd 76/77); optimization_level 1
   (332B, nd 61 words); and opt_propagation off (still nd 4). Direct field
   store plus field comparison fixes the counter prologue. The decisive
   source change is inlining each func_0044b7b0 call at the multiply site.
*/
f32 func_0035bad0(u8 *arg0)
{
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f21_2;
    s16 temp_2;
    s16 temp_2_2;

    *(s16 *)(arg0 + 0x24) = *(s16 *)(arg0 + 0x24) + 1;
    if (*(s16 *)(arg0 + 0x24) >= 0x64) {
        *(s16 *)(arg0 + 0x24) = 0;
    }
    temp_2_2 = *(s16 *)(arg0 + 0x22);
    if (temp_2_2 < 0xA) {
        *(s16 *)(arg0 + 0x22) = (s16)(temp_2_2 + 1);
    }
    temp_f20 = (f32)*(s16 *)(arg0 + 0x22) / 10.0f;
    if ((temp_f20 < 0.0f) || (temp_f20 > 1.0f)) {
        func_0046d730(&D_0064CC98, 0x881);
    }
    temp_f22 = fGpffff84a4 * temp_f20;
    temp_f21 = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg0 + 8) = temp_f21 + ((*(f32 *)(arg0 + 0x10) - temp_f21) * func_0044b7b0(temp_f22));
    temp_f21_2 = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0xC) = temp_f21_2 + ((*(f32 *)(arg0 + 0x14) - temp_f21_2) * func_0044b7b0(temp_f22));
    return temp_f20;
}
