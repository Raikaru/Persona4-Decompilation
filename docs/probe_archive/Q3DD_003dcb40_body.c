/* object 304B/window 304B/normalized_diff N/A; classification COMPILER_FLOOR_COP1_ACCUMULATOR; retail contains mula.s/madda.s/madd.s and repeated adda.s/msub.s accumulator chains at offsets 0x20-0x2c and 0x5c onward, which plain MWCCPS2 C cannot emit. */
/* Retail-only floor evidence: func_003dcb40 begins with mul.s followed by mula.s, madda.s, madd.s, then uses adda.s and msub.s in the loop. */
