/* object_size=64 window=48 normalized_diff=41 differing_offsets=16,17,18,19,24,25,28,29,30,31,32,34,35,36,37; casts_written=none; levers_ruled_out=callee call remains old-style one-argument at retail site, plain conditional form emits a larger branch sequence; movz conditional-move is a known MWCCPS2 floor. */
u8 *func_003e82e0(u8 *arg0) {
    return (u8 *)((func_003ec480(*(s32 *)(arg0 + 0x60)) == 0) ? NULL : arg0);
}
