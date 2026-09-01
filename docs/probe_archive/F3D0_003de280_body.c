/* object_size 52B, window 64B, normalized_diff 8, differing offsets 16 and 20 (reloc-masked; first_diffs 16-23). Classification: load/shift ORDER residual. Re-measured after declaration changes. Retail loads lw $v0,0x58($a0) at +16 then sll $v1,$a1,3 at +20; candidate emits the sll at +16 then the lw at +20. Best current body requires #pragma no_branch_likely on and #pragma schedule on, but measures nd8; reversing pragma order is unchanged. Prior ruled out: initialized pointer, direct folded base load without a named scalar, direct scalar/base forms, schedule off, optimization_level 1, opt_propagation off, comma/inner-block sequencing, pointer-index/address forms, guard variants, declaration/local-index probes, and schedule/order probes. No volatile or inline asm. */
s32 func_003de280(u8 *arg0, u32 arg1) {
    u32 base;
    u32 offset;
    if (!(arg1 < *(u32 *)(arg0 + 4))) {
        goto zero;
    }
    base = *(u32 *)(arg0 + 0x58);
    offset = arg1 << 3;
    offset -= arg1;
    offset <<= 4;
    return base + offset;
zero:
    return 0;
}
