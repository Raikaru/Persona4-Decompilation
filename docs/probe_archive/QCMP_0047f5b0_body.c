/* object_size=not_measured; window=352; normalized_diff=not_measured; differing_offsets=not_applicable; classification=COP1_ACCUMULATOR_CHAIN_FLOOR; retail_floor_sequence=adda.s at +0x108 then madd.s at +0x10c; adda.s at +0x11c then madd.s at +0x120; adda.s at +0x130 then madd.s at +0x134; plain C cannot emit these ordinary COP1 accumulator instructions under H009; ruled_out=retail has no movz/movn, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; frame=0x10, ra saved at sp+0, arg1 preserved in t1; diffed against func_0047f040 before writing and it is a different layout despite the same 352-byte window; no body kept or probed further. */

/* Retail normalizes three u8 channels from arg1, then interpolates the
 * returned vector's three f32 components with the three COP1 accumulator
 * pairs above and writes the vector in place. */
