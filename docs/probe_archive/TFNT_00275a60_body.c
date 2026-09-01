/* object=364 window=368 nd=8; differing_offsets=0xC0,0xD0,0xD4,0xD8,0xDC,0xE0,0xE8; deficit=1 instruction (retail window tail); classification=register-coloring cycle (retail limit $a0/next-node $a1, candidate swapped); ruled_out=declaration-order swaps, direct fresh bound expression (nd=19), explicit/recomputed next-node forms (nd=9/39), reordered i/limit production (nd=9), global-address spellings, D_0063bca0 array declaration; donor W389 probes also ruled out lifetimes/propagation/strength-reduction/dead-assignments/loop-invariants/common-subs. */
void func_00275a60(s32 count)
{
    int limit;
    int i;
    int *node;
    int size;
    u32 memory;
    u32 block;
    int *current;

    size = count * 0x21c + 0x18;
    if (iGpffffb954 != (u8 *)0x0) {
        func_0046d730(D_0063bc88, 0x26);
    }
    func_0044ea90(D_0063bc88, 0x27);
    memory = D_008873e8_abs[0](size, 0x40000);
    piGpffffb954 = (int *)memory;
    func_0043f9c8(memory, 0, size);
    *piGpffffb954 = count;
    piGpffffb954[1] = (int)(piGpffffb954 + 6);
    node = (int *)piGpffffb954[1];
    node[3] = (int)(node + 7);
    piGpffffb954[4] = (int)node;
    i = 0;
    limit = count - 1;
    for (; i < limit; i = i + 1) {
        node[6] = (int)(node[3] + 0x200);
        node = (int *)node[6];
        node[3] = (int)(node + 7);
    }
    piGpffffb954[5] = (int)node;
    current = (int *)piGpffffb954[4];
    while (current != (int *)0x0) {
        block = func_003ec590(0x20, 0x20, 4, 0x4504);
        current[5] = block;
        if (block == 0) {
            func_00440b68(D_0063bca0);
        } else {
            current = (int *)current[6];
        }
    }
}
