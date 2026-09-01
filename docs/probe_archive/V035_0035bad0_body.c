/* object_size=320B; window=320B; normalized_diff=4; differing_offsets=
   0xE9-0xEA, 0x115-0x116. Plain C reproduces retail's complete four-op
   COP1 accumulator chain in both interpolation blocks: adda.s + madd.s,
   twice. The two remaining words are only the commutative MAC operand order:
   candidate madd.s $f0,$f0,$f2 versus retail madd.s $f0,$f2,$f0. This is the
   documented b210 fresh/invariant operand-order floor, not a failure to emit
   the accumulator chain; no inline asm or intrinsic was used.

   Ruled out: the original temporary-counter spelling (nd 14, with extra
   v1/v0 prologue words); direct-expression multiplication orders (all four
   tested orders retained nd 14 before the counter fix); ordered helper/product
   staging (304B object, nd 76/77); optimization_level 1 (332B object, nd 61
   words); opt_propagation off (same nd 4). Direct field store plus field
   comparison fixes the counter prologue and leaves only the two MAC words.
*/
f32 func_0035bad0(u8 *arg0)
{
    f32 temp_f0;
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
    temp_f0 = func_0044b7b0(temp_f22);
    *(f32 *)(arg0 + 8) = temp_f21 + ((*(f32 *)(arg0 + 0x10) - temp_f21) * temp_f0);
    temp_f21_2 = *(f32 *)(arg0 + 0x1C);
    temp_f0 = func_0044b7b0(temp_f22);
    *(f32 *)(arg0 + 0xC) = temp_f21_2 + ((*(f32 *)(arg0 + 0x14) - temp_f21_2) * temp_f0);
    return temp_f20;
}
