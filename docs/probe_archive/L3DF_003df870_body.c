/* object_size 24B, window 32B, normalized_diff 8, differing offsets 12,16 (retail jr/addu delay-slot order versus candidate addu/jr; verifier tail rows 12-19). */
/* Probed: direct returned expression `return arg0[0] + arg0[3] * arg1;` (best nd8); local-result spelling; local base/product temporaries; pointer spellings; commutative operand orders; #pragma schedule on and scheduler/optimization combinations (all worse or unchanged). No inline asm or volatile. */
s32 func_003df870(s32 *arg0, s32 arg1) {
    return arg0[0] + arg0[3] * arg1;
}
