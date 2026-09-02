// Main follow-up (2026-09-02): with code1_003b.c listed in config/speed_units.txt (-O2,p) the stray nop is supplied by the
// compiler. Remaining residual then: retail calls func_003df360 with the incoming $a0 (needs opt_common_subs ON) but also
// reloads *work after storing it (lw v1,(s0) right after sw v1,(s0)), which under CSE on no spelling tried reproduces
// (cast/struct-member/shift/u32/recomputed-address forms all forward the store). With opt_common_subs off the reload
// appears but the call gains a move a0,s4. Mid-function pragma flips are function-granular. Open.
// FUN_003BCD50 archive (wave Ko lane KoA, killed by provider rate limit; live state at cutoff, MISMATCH nd28 200/208).
// The (s64)0 < length guard is now exact (slt $at,$zero,$v0; beqz). ALL remaining words are one stray retail nop at +164
// (after the filled back-edge delay slot, before move $v0,$s4) shifting the epilogue. Same nop as func_003b4230 (+0x9c).
// Main swept 6 loop spellings and 8 pragma sets on the 4230 skeleton without producing it. Body uses volatile (banned) -
// drop the casts; they were never the lever.
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
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
    s32 cur;
    s32 i;
    s32 row;
    u8 *work;
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
    i = 0;
    if ((s64)0 < *(volatile s32 *)work) {
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
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
#pragma schedule off
