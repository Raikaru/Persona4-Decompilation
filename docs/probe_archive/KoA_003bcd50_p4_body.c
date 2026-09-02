/* Lane KoA probe 4 for func_003bcd50: object 204B/window 208B, normalized_diff 42.
 Residual: using a `go` local for the guard fixes the trailing nop alignment
 (done at 0x003bcdf8) but the guard becomes `slt $v0`/`beqz $v0` instead of
 retail's `slt $at`/`beqz $at`, and the loop preheader is shifted 4 bytes.
 Also missing the final function-end nop. */
/* measured: schedule on fills the guard and call delay slots; no_branch_likely
   on keeps the beqz plain; opt_rebuildconditionals off and opt_propagation off
   retain the B3B saved-register assignment.  The `(s64)0 < count` guard from
   func_003bcf10 fixes the slt $at floor; i=0 is hoisted before the guard. */
// FUN_003BCD50
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
    *(u8 **)(work + 4) = jtbl_008873E8[0](*(volatile s32 *)work * 0x10, 0x3011F);
    go = (s64)0 < *(volatile s32 *)work;
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
/* measured: close the schedule/no_branch_likely/opt_rebuildconditionals/opt_propagation bracket. */
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
#pragma schedule off
