/*
 * func_00473870 intermediate candidate before grouped translation locals closed the target.
 * object_size=684B; retail_window=688B; normalized_diff=14 differing words (reloc-masked).
 * first_diffs=0x230,0x234,0x238,0x23c,0x240,0x244,0x248,0x24c,0x254,0x25c,0x260,0x264,0x268,0x270.
 * COP1 chain: all 46 retail accumulator-chain operations (mula.s/madda.s/madd.s/msub.s/adda.s)
 * reproduced naturally from compliant C; the residual was ordinary translation load/store scheduling.
 * Ruled out: COP1 expressiveness floor; inline asm/intrinsics/volatile; whole-function asm;
 * text permuter; pointer carrier variants; raw-versus-normalized aliasing; direct translation
 * assignments. Closure used opt_loop_invariants on (measured), aggregate saved-quaternion copy,
 * normalized-local declaration order, MAC-term spelling, and grouped translation differences.
 * No new data reference beyond the existing placeable iGpffff8040 global and func_003d5bc0.
 */
