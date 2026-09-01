/* object_size=not_measured; window=1344; normalized_diff=not_measured; differing_offsets=not_applicable; classification=COP1_ACCUMULATOR_CHAIN_FLOOR+RECONSTRUCTION_SCALE; ruled_out=retail has no movz/movn, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; retail directly contains adda.s $f0,$f1 followed by madd.s $f20,$f3,$f2 in the coordinate calculation, a banned ordinary COP1 accumulator chain that b210 cannot emit from plain C; the 0x4F000000 c.le.s/trunc.w.s/mfc1/andi 0xFF sequence is MWCCPS2's native plain-cast float-to-u8 idiom, not a floor; prologue is frame=0x160 with sq s0-s8, saved f20-f22, and long-lived UI locals; no body kept or probed further. */

/* Retail reconstruction outline (not compiled):
 * validate arg1 against the 16-bit random source, derive two floating
 * coordinates (including the COP1 accumulator chain), convert the alpha-like
 * product through the guarded u8 narrowing idiom, draw either the two-page
 * branch or the detailed stat rows, then submit the final text/icon draw.
 */
