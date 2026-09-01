/* object 208B vs window 208B, normalized_diff 0 (ASM), differing offsets none; classification confirmed COP1 accumulator-chain compiler floor; ruled out plain-C probing because retail uses mula.s/msub.s/adda.s/madd.s. */
/* Retail evidence: mula.s $f0,$f4, msub.s $f3,$f1,$f5, then multiple adda.s/madd.s accumulator operations. */
