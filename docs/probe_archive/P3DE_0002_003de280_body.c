/* Lane P3DE_0002: func_003de280 under -O2,p with schedule on and direct u32 value local.
   object 44B, window 64B, normalized_diff 12. Tried: u32 base + offset with return base+offset.
   Result: beql with zero move in delay slot, lw sunk below first sll. */
#pragma push
#pragma schedule on
s32 func_003de280(u8 *arg0, u32 arg1) {
    u32 base;
    u32 offset;
    if (!(arg1 < *(u32 *)(arg0 + 4))) {
        goto zero;
    }
    offset = arg1 << 3;
    offset -= arg1;
    offset <<= 4;
    base = *(u32 *)(arg0 + 0x58);
    return base + offset;
zero:
    return 0;
}
#pragma pop