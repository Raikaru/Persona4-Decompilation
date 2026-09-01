/* Updated archive: object 136B, retail window 144B, normalized_diff 12 (fndiff differing offsets 40, 64, 84, 104, 108, 112, 116, 120, 124, 132; relocation-masked word residual 12). Best body uses the preincrement `++count` shape, which reproduces retail's exact list-load/count/sltu/beqz sequence. The candidate is exactly 8B shorter than retail: the residual is two absent retail nops at offsets 84 and 108, with the candidate node addiu at 84 instead of retail's delay-slot addiu at 104. Tried do/while, explicit-break/goto/for loop shapes, post/preincrement conditions, declaration order, opt_propagation, opt_loop_invariants, schedule on/off, schedule-off push/pop, no_branch_likely, optimization_level 3 and 1, and integer-domain/list/node/value-local casts. O1 on the nd12 body produced object 140B/nd15; an in-body off/on placement produced object 128B/nd19, so both were reverted. */
void func_003a3d50(u8 *arg0)
{
    s32 count;
    u8 *base;
    u8 *list;
    u8 *node;

    base = *(u8 **)(arg0 + iGpffffb610);
    if ((*(s32 *)(base + 0x44) & 0x10) == 0) {
        list = *(u8 **)(base + 0x9C);
        count = 0;
        node = list;
        do {
            if (*(s32 *)(node + 0x138) != 0) {
                func_003e1ea0(*(s32 *)(node + 0x138));
                *(s32 *)(node + 0x138) = 0;
            }
            node += 4;
        } while ((u32)*(s32 *)(list + 0xE8) >= (u32)++count);
    }
}
