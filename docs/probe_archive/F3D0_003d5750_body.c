/* object_size 64B, window 64B, normalized_diff 20, differing offsets 0,2,4,6,10,14,16,17,18,19,20,21,22,23,24,25. Classification: register-coloring and branch-delay ORDER residual. Retail maps object/head/stride/node to v1/a2/a1/v1 and places move-zero in the beq delay slot; the clean C candidate keeps the exact size but uses a different temporary register map and branch order. Re-measured after declaration changes. Freshly ruled out: an explicit obj local with object-first assignment (still 64B/nd20); prior ruled out: local declaration reversal, role-swapped sentinel/walker variables, comma-separated initialization, inlined stride load, integer-domain pointer addition, schedule on, no_branch_likely on, and optimization_level 1 plus opt_propagation off. No volatile or inline asm. */
s32 func_003d5750(u8 *arg0) {
    u8 *head;
    u8 *node;
    s32 stride;
    s32 count;
    head = *(u8 **)(arg0 + 0x10);
    stride = *(s32 *)(*(u8 **)arg0 + 8);
    node = *(u8 **)head;
    count = 0;
    if (node != head) {
        do {
            node = (u8 *)((u32)node + (u32)stride);
            count += 1;
        } while (*(u8 **)node != head);
    }
    return count;
}
