// SFCL triage: object_size 1216/window 1216, normalized_diff 0 for the ASM fallback; best discarded C candidate normalized_diff 40 (source annotation, 40 differing words), differing offsets and candidate instruction deficit/surplus not retained; classification argument-evaluation-order scheduling floor; ruled-outs: prototype/old-style, hoisted-local, declaration-order, s32/u16 local-type, and #pragma schedule spellings were measured without changing the residual; proving calls 0x0033D06C and 0x0033D10C.

/* Retail's mixed argument materialisation at both func_0025ecd0 calls is:
   [3, 8, f12-f14, 1, 2, 4, 5, 6, 7, f15-f17].
   MWCCPS2 b210 emits [2, 3, 6, 7, 8, f12-f14, 1, 4, 5, f15-f17]
   regardless of tested source spelling. The 14-argument call cannot be made
   byte-exact with this compiler's scheduling. */
/*
    0x0033D03C..0x0033D068: retail loads f12-f14, then reaches the call setup
    for 0x0033D06C with the nested func_002b2a30 result and integer arguments.
    0x0033D0DC..0x0033D108: second call setup, including f20/f21 in f16/f17.
*/
