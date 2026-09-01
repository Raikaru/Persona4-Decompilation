/* object_size=not_measured; window=352; normalized_diff=not_measured; differing_offsets=not_applicable; classification=COP1_ACCUMULATOR_CHAIN_FLOOR; retail_floor_sequence=adda.s at +0x78 then madd.s at +0x7c; adda.s at +0x104 then madd.s at +0x108; adda.s at +0x130 then madd.s at +0x134; plain C cannot emit these ordinary COP1 accumulator instructions under H009; ruled_out=retail has no movz/movn, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; frame=0x20, ra saved at sp+0, arg0/arg1 preserved in t2/t1 and interpolation tables are traversed twice; diffed against func_0047f5b0 before writing and it is a different layout despite the same 352-byte window; no body kept or probed further. */

/* Retail interpolates f32 values from the two curve objects using three COP1
 * accumulator pairs, stores the result in fGpffffbb4c, and returns a pointer
 * to the updated global interpolation state. */
