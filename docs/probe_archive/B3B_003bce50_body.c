// Lane B3B best body for func_003bce50 (never reached MATCH).
// Best normalized_diff 71, object 164B / window 192B.
// Residual: entry guard colors slt $v0 vs retail slt $at,$zero,$v0 + beqz
// (the same $at-guard floor as func_003b4230/cd50), retail places the
// func_003bc620 call OUT-OF-LINE after the loop exit reached by bnez while
// every spelling compiles it inline with beqz-skip, and one trailing nop.
// Levers that reached nd71: schedule on, no_branch_likely on,
// opt_rebuildconditionals off, opt_propagation off, cached count with
// volatile loop-tail reload, single-case switch wrap, goto next, role-swapped
// counters, declaration permutations, init inside/outside guard.
#pragma schedule on
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
#pragma opt_propagation off
s32 func_003bce50(s32 arg0, s32 arg1) {
    s32 result;
    s32 row;
    s32 sum;
    s32 i;
    u8 *work;
    s32 go;
    s32 count;

    result = 0;
    work = (u8 *)(arg0 + arg1);
    sum = 0;
    if (work != NULL) {
        count = *(volatile s32 *)work;
        if (count > 0) {
            {
                i = 0;
                row = 0;
                do {
                    u8 *a0 = *(u8 **)(work + 4) + i;
                    if (*(s32 *)(a0 + 4) != 0) {
                        sum += func_003bc620(a0);
                    }
                    row += 1;
                    i += 0x10;
                } while (row < *(volatile s32 *)work);
            }
        }
        if (sum > 0) {
            sum += 4;
        }
    }
    return result + sum;
}
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
#pragma schedule off