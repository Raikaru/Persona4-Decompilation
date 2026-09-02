/* Lane P3DE_0003: func_003de280 under -O2,p. Tried: direct u32 value local with schedule on + no_branch_likely on. Residual: lw $v0,0x58($a0) and the first sll are swapped in the positive branch; object 52 vs window 64. */
#pragma push
#pragma schedule on
#pragma no_branch_likely on
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