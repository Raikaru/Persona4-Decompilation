/* Main 2026-09-03: the archived O1 body now measures nd8 in the live unit: retail keeps idx ($s0) and arg0
   ($s1) saved yet addresses everything through p ($s2); its first store is `li a0,5; move v1,s2; lui/addu; sw a0`
   and the second-call argument is `p + 0x1D70C` (b210 recomputes idx+arg0). Spelling all four uses through p,
   through idx+arg0, via q = p copies, via inline store helpers (value-first / base-first / offset param),
   at O1 / O2 / opt_propagation off: nd31-38. Open. */
/* object 156B / window 160B / normalized_diff 20; differing offsets: 70, 72-86; declaration audit: no declarations corrected (func_00370410 and func_00370a80 are the only callees and remain pointer prototypes); levers probed: O1/O2, pointer/base expression order, arg0/arg1 aliases, pointer reuse, typed/union/struct/array locals, named stores, constant locals, callee integer argument casts, and all archived f00 source shapes. */
#pragma optimization_level 1
void func_00375f00(u8 *arg0, s32 arg1) {
    u8 * arg0_p = arg0;
    s32 arg1_p = arg1;
    s32 idx;
    u8 *p;

    idx = arg1_p * 0xE8;
    p = (u8 *)((u32)arg0_p + (u32)idx);
    func_00370410(p + 0x1D6AC);
    *(s32 *)(p + 0x1D6A4) = 5;
    func_00370a80((u8 *)idx + (u32)arg0 + 0x1D70C);
    *(s32 *)((u8 *)idx + (u32)arg0 + 0x1D6A8) = 3;
}
#pragma optimization_level 2
