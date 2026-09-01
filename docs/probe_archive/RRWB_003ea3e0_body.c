/* object_size=284 window=304 normalized_diff=213 differing_offsets=24,25,26,27,28,30,31,32,34,35,36,38,39,40,41,42 classification=undersized/misaligned body; prologue=frame 0x60, saved $s3/$s2/$s1/$s0 four locals, $a0 incoming pointer and $a1 scratch; declarations corrected at block scope: jtbl_008873E8(u32,u32), func_003df590(s32,s32), func_003df4d0(s32*); measured no_branch_likely on/off and declaration rotation; no confirmed compiler floor */
/* Candidate retained only in build; source restored to INCLUDE_ASM after measurement. */
u8 *func_003ea3e0(u8 *arg0)
{
    extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
    extern s32 func_003df590(s32 arg0, s32 arg1);
    extern void func_003df4d0(s32 *arg0);
    s32 bytes;
    s32 flag;
    s32 total;
    u8 *self;
    u64 extra;
    u8 *result;
    u8 *work;
    s32 sp5c;
    s32 sp58;
    s32 field;

    field = *(s32 *)(arg0 + 0xc);
    flag = (field == 4);
    self = arg0;
    if (flag == 0) {
        flag = (field == 8);
    }
    if (flag != 0) {
        extra = ((u64)1 << field) << 2;
    } else {
        extra = 0;
    }
    *(s32 *)(self + 0x10) = (field + 7) >> 3;
    *(s32 *)(self + 0x10) =
        *(s32 *)(self + 0x10) * *(s32 *)(self + 4);
    *(s32 *)(self + 0x10) = (*(s32 *)(self + 0x10) + 3) & -4;
    bytes = *(s32 *)(self + 0x10) * *(s32 *)(self + 8);
    total = bytes + (s32)extra;
    result = jtbl_008873E8[0](total, 0x30018);
    *(u8 **)(self + 0x14) = result;
    if (result != NULL) {
        if (flag != 0) {
            work = result + bytes;
        } else {
            work = NULL;
        }
        *(u8 **)(self + 0x18) = work;
        *(s32 *)self |= 1;
        return self;
    }
    sp58 = 1;
    sp5c = func_003df590(0x80000013, total);
    func_003df4d0(&sp58);
    return NULL;
}
