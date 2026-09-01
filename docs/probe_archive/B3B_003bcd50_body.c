// Lane B3B best body for func_003bcd50 (never reached MATCH).
// Best normalized_diff 42, object 204B / window 208B.
// Residual: entry guard colors slt $v0 vs retail slt $at,$zero,$v0 + beqz
// (same $at-guard floor as func_003b4230), i=0 lands after the branch
// instead of in its delay slot, and one trailing nop before the return.
// Levers that reached nd42: schedule on, no_branch_likely on,
// opt_rebuildconditionals off, opt_propagation off, goto done structure,
// cur = arg0 with return arg0 (arg0 stays live in $s4), volatile work reads
// (fresh reload per loop test), declaration order sp6C/work/go/cur/i/row.
// Failed probes: while (row < count*0x10) single-counter loop, non-volatile
// cached count, i=0 hoisted before the guard, go declared last, plain
// if/&& structure, return cur (collapses frame to 0x50 and kills s4/s3).
#pragma schedule on
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
#pragma opt_propagation off
s32 func_003bcd50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp6C;
    u8 *work;
    s32 go;
    s32 cur;
    s32 i;
    s32 row;

    work = (u8 *)(arg2 + arg3);
    cur = arg0;
    if (work == NULL) {
        goto done;
    }
    if (func_003df360(arg0, &sp6C, 4) == 0) {
        goto done;
    }
    *(s32 *)work = sp6C;
    *(u8 **)(work + 4) = jtbl_008873E8[0](*(s32 *)work * 0x10, 0x3011F);
    go = 0 < *(volatile s32 *)work;
    if (go != 0) {
        i = 0;
        row = 0;
        do {
            cur = func_003bc150(*(u8 **)(work + 4) + row, cur);
            i += 1;
            row += 0x10;
        } while (i < *(volatile s32 *)work);
    }
done:
    return arg0;
}
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
#pragma schedule off