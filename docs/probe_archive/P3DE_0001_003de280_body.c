/* Lane P3DE_0001: func_003de280 under -O2,p with push/pop #pragma schedule on.
   object 52B, window 64B, normalized_diff 5, differing offsets 12 and 16.
   Residual: addiu $v1,$a0,0x58 + lw $v0,($v1) vs retail nop + lw $v0,0x58($a0).
   Tried: archive L3DF u32* base local with schedule on. */
#pragma push
#pragma schedule on
s32 func_003de280(u8 *arg0, u32 arg1) {
    u32 *base = (u32 *)(arg0 + 0x58);
    u32 offset;
    if (!(arg1 < *(u32 *)(arg0 + 4))) {
        goto zero;
    }
    offset = arg1 << 3;
    offset -= arg1;
    offset <<= 4;
    return *base + offset;
zero:
    return 0;
}
#pragma pop