/* Lane P3DE_0025: func_003d5fb0 under -O2,p. Tried: archive body with schedule on + no_branch_likely on. Residual: compiler inverts the if and places the sw in the bnez delay slot instead of keeping it a nop; object 76 vs window 96. */
#pragma push
#pragma schedule on
#pragma no_branch_likely on
s32 func_003d5fb0(u8 *arg0) {
    u8 *self;
    s32 value;
    self = arg0;
    value = func_003df5d0(4, *(s32 *)(self + 4) | 0x40000);
    *(s32 *)(self + 0x10) = value;
    if (value == 0) {
        return 0;
    }
    *(s32 *)(self + 0x14) = 0;
    return (s32)self;
}
#pragma pop