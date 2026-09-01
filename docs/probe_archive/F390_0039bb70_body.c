/* object 92B / window 96B / normalized_diff 44 / differing byte offsets 4,5,6,7,8,10,11,28,30,48,49,50,51,52,53,54; plain C cursor/body shape; ruled out named nonempty boolean (obj108), opt_rebuildconditionals off, declaration/order and schedule probes. Retail uses sltu $at guard and puts the found-pointer addu in the branch delay slot. */
u8 *func_0039bb70(u8 **arg0, s32 arg1)
{
    u8 *base;
    u8 *entry;
    u32 index;
    u32 count;

    count = (u32)((s32 *)arg0)[1];
    if (count > 0) {
        index = 0;
        base = *arg0;
        entry = base;
        do {
            if (arg1 == *(s32 *)(entry + 8)) {
                return base + index * 20;
            }
            index += 1;
            entry += 20;
        } while (index < count);
    }
    return NULL;
}
