/* object_size=not_measured window=368 normalized_diff=not_measured differing_offsets=not_measured classification=confirmed COP1 accumulator floor; retail contains mula.s at 0x0020890c followed by msub.s, adda.s and madd.s chains; ruled_out=the retail window has no movz/movn, standalone MMI, framed tail-jump forwarder, or ee-gcc sd-$sN signature; no source probe attempted per floor-first rule. Retail also uses the ordinary COP1 accumulator instructions in the post-clamp arithmetic, which plain MWCCPS2 C cannot emit. Entry first-touch indicates a callback with unused arg0 and incoming arg1/arg2 (raw uses $a1/$a2). */
/*
 * M2C outline retained for reference only; not compiled because the confirmed
 * accumulator instructions are not expressible in compliant plain C:
 *
 * f32 func_00208870(u8 *arg1, u8 *arg2) {
 *     f32 x = (f32)*(s16 *)(arg1 + 0xE) / 2.0f;
 *     if (x > 1.0f) x = 1.0f;
 *     else if (x < 0.0f) x = 0.0f;
 *     // retail mula.s/ msub.s/ adda.s/ madd.s accumulator chain
 *     if (accumulated <= 0.0f) return 0.0f;
 *     // color {0xB4,0,0,0xFF}; params {-10, ..., 0x294, 22*accumulated}
 *     // func_0045d6e0(color, params, 0, accumulator)
 * }
 */
