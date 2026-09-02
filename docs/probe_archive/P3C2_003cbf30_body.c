/* Re-measured 2026-09-02 (Main): still the two-word swap (retail lw $v1,0x38($s3) before
   move $v0,$s4; b210 the reverse). Levers re-tried: -O2,p/-O3,p (no change; 003c is not a
   speed unit, ,p breaks a third function), schedule-only/no_branch_likely-only brackets,
   return arg0 direct, (s32) cast return, goto-ret tail, q-local for the 0x38 load,
   value-assignment placement (entry, after self, at done, at tail). The move is the
   scheduler filling the load-use slot; not source-reachable. */
/* object 220B/window 224B normalized_diff 3; differing offsets 164,168 (retail loads self+0x38 before move $v0,$s4; b210 reverses those two instructions); classification NEAR_MISS. Newly ruled out: shared return-tail goto, explicit q destination load, result assignment at tail, direct argument return with no local, and u64 return (all unchanged at nd 3). Retail window has no movz/movn, COP1 accumulator chain, standalone MMI floor, framed tail-jump, or sd/sq mixed-unit floor. Best source uses value-before-self liveness order, void (**table) callback table local, explicit value_loop/done gotos, nested first cleanup load, and schedule + no_branch_likely on. opt_common_subs off regressed to nd 38; in-function schedule-off had no effect. No callee prototype correction required; iGpffffb714/iGpffffb718 remain existing GP declarations and D_008872E0 remains array/global form. */
s32 func_003cbf30(s32 arg0, u8 *arg1) {
    u8 *self;
    s32 value;
    u8 *cursor;
    u8 *sentinel;
    void (**table)(u8 *, u8 *);
    u8 *entry;
    u8 *p;
    u8 *q;

    value = arg0;
    self = arg1;
    sentinel = self + 0x2C;
    *(s32 *)(self + iGpffffb714) = 0;
    cursor = *(u8 **)(self + 0x2C);
    if (cursor == sentinel)
        goto done;
    table = jtbl_008873FC;
value_loop:
    entry = cursor - 0xC;
    cursor = *(u8 **)cursor;
    p = *(u8 **)(entry + 0xC);
    q = *(u8 **)(entry + 0x10);
    *(u8 **)q = p;
    p = *(u8 **)(entry + 0x10);
    q = *(u8 **)(entry + 0xC);
    *(u8 **)(q + 4) = p;
    p = *(u8 **)(entry);
    q = *(u8 **)(entry + 4);
    *(u8 **)q = p;
    p = *(u8 **)(entry + 4);
    q = *(u8 **)entry;
    *(u8 **)(q + 4) = p;
    table[0](*(u8 **)(D_008872E0 + (s32)iGpffffb718 + 4), entry);
    if (cursor != sentinel)
        goto value_loop;
done:
    p = *(u8 **)(self + 0x34);
    *(u8 **)(*(u8 **)(self + 0x38)) = p;
    p = *(u8 **)(self + 0x38);
    q = *(u8 **)(self + 0x34);
    *(u8 **)(q + 4) = p;
    return value;
}
