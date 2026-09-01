/* object_size=not_measured window=512 normalized_diff=not_measured differing_offsets=not_measured classification=confirmed COP1 accumulator floor; retail contains mula.s/msub.s at 0x0020B208-0x0020B214 and mula.s/adda.s/madd.s at 0x0020B320-0x0020B348; ruled_out=retail window has no movz/movn, standalone MMI, framed tail-jump forwarder, or ee-gcc sd-$sN signature; no source probe attempted per floor-first rule. Entry first-touch shows an unused $a0 and incoming $a1 state pointer (saved in $s1); the function calls func_00203930 twice and func_002035A0 on the state tail. Plain compliant MWCCPS2 C cannot emit the COP1 accumulator chains. */
/* Retail outline retained for reference only:
 * temp_2 = func_00452560(*(u8 **)(arg1 + 0x5B0));
 * if ((*(u32 *)temp_2 & 1) && (*(u16 *)arg1 != 0) &&
 *     (*(s16 *)(arg1 + 0x5AC) == -1)) {
 *     func_00201350();
 *     if (*(s16 *)(arg1 + 8) / 76.0f < 1.0f)
 *         func_00203930(temp_2, f, f, colors, 76);
 *     if (*(s16 *)(arg1 + 0xA) < 7) ... else ...;
 *     func_00203930(temp_2, f20, f20, colors, 255);
 *     func_002035A0(arg1 + 0x2C);
 * }
 */
