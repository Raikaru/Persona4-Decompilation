/* object_size 28B, window 32B, normalized_diff 8, differing offsets 16,20 (retail jr/addu delay-slot order versus candidate addu/jr; verifier tail rows 16-23). */
/* Probed: direct returned expression `return arg0[0] + arg0[3] * arg0[1];` (best nd8); local-result spelling; local base/product temporaries; pointer spellings; commutative operand orders; #pragma schedule on and scheduler/optimization combinations (all worse or unchanged). No inline asm or volatile. */
s32 func_003df8a0(s32 *arg0) {
    return arg0[0] + arg0[3] * arg0[1];
}
