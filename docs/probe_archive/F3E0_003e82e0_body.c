/* object_size=64B window=48B normalized_diff=41 differing_offsets=16,17,18,19,24,25,28,29,30,31,32,34,35,36,37; ruled out plain conditional form and old-style one-argument callee spellings; candidate overflows the retail window, and residual is retail movz $s0,$zero,$v0. */
u8 *func_003e82e0(u8 *arg0) {
    return (u8 *)((func_003ec480(*(s32 *)(arg0 + 0x60)) == 0) ? NULL : arg0);
}
