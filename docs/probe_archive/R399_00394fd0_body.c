/* object 284 / window 304 / normalized_diff 153; differing offsets 0x1c-0x118; undersized 20 bytes: frame exact but branch-likely failure test, allocation/zero-loop pointer colors, and failure-local store order differ; classification no_branch_likely plus pointer type/declaration order; ruled out none (initial plain-C candidate). */
u8 *func_00394fd0(u32 arg0)
{
    s32 sp38;
    s32 sp3c;
    u32 temp17;
    u8 *ptr;
    u8 *var5;
    u32 var6;
    extern s32 func_003df590();
    extern void func_003df4d0();
    temp17 = arg0 * 8 + 8;
    ptr = (u8 *)(*jtbl_008873E8)(temp17, 0x3001e);
    if (ptr != NULL) {
        *(u32 *)ptr = arg0;
        *(u8 **)(ptr + 4) = ptr + 8;
        var5 = *(u8 **)(ptr + 4); var6=0;
        if (arg0 != 0) { if (arg0 >= 9U) { do {
            *(u32 *)(var5+0)=0; var6+=8; *(u32 *)(var5+4)=0; *(u32 *)(var5+8)=0;
            *(u32 *)(var5+0xc)=0; *(u32 *)(var5+0x10)=0; *(u32 *)(var5+0x14)=0; *(u32 *)(var5+0x18)=0;
            *(u32 *)(var5+0x1c)=0; *(u32 *)(var5+0x20)=0; *(u32 *)(var5+0x24)=0; *(u32 *)(var5+0x28)=0;
            *(u32 *)(var5+0x2c)=0; *(u32 *)(var5+0x30)=0; *(u32 *)(var5+0x34)=0; *(u32 *)(var5+0x38)=0;
            *(u32 *)(var5+0x3c)=0; var5+=0x40;
        } while (var6 < arg0-8); } if (var6 < arg0) { do {
            *(u32 *)(var5+0)=0; var6+=1; *(u32 *)(var5+4)=0; var5+=8;
        } while (var6<arg0); } }
        return ptr;
    }
    sp38=0x122; sp3c=func_003df590(0x80000013,temp17); func_003df4d0(&sp38); return NULL;
}
