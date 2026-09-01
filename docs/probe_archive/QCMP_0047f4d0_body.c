/* object_size=not_measured; window=224; normalized_diff=not_measured; differing_offsets=not_applicable; classification=COP1_ACCUMULATOR_CHAIN_FLOOR; retail_floor_sequence=adda.s at +0x78 then madd.s at +0x7c; adda.s at +0x94 then madd.s at +0x98; adda.s at +0xb0 then madd.s at +0xb4; plain C cannot emit these ordinary COP1 accumulator instructions under H009; ruled_out=retail has no movz/movn, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; frame=0x30, ra saved at sp+0, arg1 preserved in t1; no body kept or probed further. */

/* Retail computes three interpolated vector components from two func_0047f3a0
 * results, using the three COP1 accumulator pairs above, stores them to the
 * 0x922C54/0x922C58/0x922C5C globals, and returns &D_00922C50. */
