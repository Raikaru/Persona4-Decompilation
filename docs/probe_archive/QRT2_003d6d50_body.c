/* object 304B vs window 304B, normalized_diff 0 (ASM), differing offsets none; classification confirmed COP1 accumulator-chain compiler floor; ruled out plain-C probing because retail uses adda.s/madd.s repeatedly across six components. */
/* Retail evidence: adda.s $f2,$f5/$f1 and madd.s $f0,$f3,$f1/$f0, plus accumulator chain in every output component. */
