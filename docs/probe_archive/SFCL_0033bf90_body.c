// SFCL triage: object_size 1280/window 1280, normalized_diff 0 for the ASM fallback (no C candidate), differing offsets n/a, instruction deficit/surplus n/a; classification COP1 accumulator-chain compiler floor; ruled-outs: source reconstruction intentionally not attempted after decisive retail proof; no movz/movn, framed tail-jump, standalone-MMI, or unsigned-conversion residual was needed; proving offsets 0x0033C0B4 adda.s, 0x0033C0B8 madd.s, 0x0033C0EC adda.s, 0x0033C0F0 madd.s, 0x0033C43C adda.s, 0x0033C440 msub.s.

/* Retail proving excerpt from func_0033bf90 (window 0x500 bytes): */
/*
    0x0033C0B4: adda.s $f0,$f1
    0x0033C0B8: madd.s $f20,$f2,$f3
    0x0033C0EC: adda.s $f0,$f1
    0x0033C0F0: madd.s $f13,$f2,$f3
    ...
    0x0033C43C: adda.s $f0,$f1
    0x0033C440: msub.s $f0,$f2,$f3
*/
/* COP1 accumulator instructions are ordinary computation and are not
   reproducible by a permitted plain-C or inline-assembly spelling under b210. */
