/* object 72B/window 80B, normalized_diff 5; best focused reconstruction.
   #pragma opt_propagation off plus a named global assignment fixes the GP load
   order; schedule on and no_branch_likely on fix the loop tail and plain branch.
   Residuals: retail initializes result in $v0 at offset 4 and compares $zero
   at offset 16, while this body initializes the index in $a2 at offset 4 and
   compares that register; result/index zero-materialization swaps at offset 24.
   No global-vs-field ordering pair applies: the length field is at offset 0. */
/* measured: no_branch_likely on probe for target loop branch. */
#pragma no_branch_likely on
/* measured: opt_propagation off plus named global assignment probe for target load order. */
#pragma opt_propagation off
/* measured: schedule on probe for loop guard and delayed pointer increment. */
#pragma schedule on
s32 func_003bcf10(s32 arg0) {
    s32 global;
    s32 count;
    s32 index;
    s32 length;
    u8 *base;
    u8 *entry;

    global = iGpffffb668;
    count = 0;
    base = (u8 *)(arg0 + global);
    length = *(s32 *)(base + 0);
    index = 0;
    if (index < length) {
        entry = *(u8 **)(base + 4);
        do {
            if (*(s32 *)(entry + 0xC) == 0) goto no_count;
            count += 1;
no_count:
            index += 1;
            entry += 0x10;
        } while (index < length);
    }
    return count;
}
/* measured: closes schedule probe around func_003bcf10. */
#pragma schedule off
/* measured: closes opt_propagation probe around func_003bcf10. */
#pragma opt_propagation on
/* measured: closes no_branch_likely probe around func_003bcf10. */
#pragma no_branch_likely off
