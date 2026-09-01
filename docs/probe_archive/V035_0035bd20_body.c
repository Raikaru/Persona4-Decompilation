/* object_size=336B; window=336B; normalized_diff=N/A (not attempted); differing_offsets=N/A (no plain-C candidate). */
/* Floor confirmed directly from retail bytes: both interpolation blocks use
   ordinary COP1 accumulator operations mula.s, madda.s, and madd.s. This is a
   documented MWCCPS2 compiler floor, not a VU0/COP2 exemption; no plain-C
   reconstruction or inline-asm workaround was attempted. */
