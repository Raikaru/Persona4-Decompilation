/* Re-measured 2026-09-02 (Main): object 308B / window 320B / nd12, saved-register colouring only.
   The two post-store reloads (`sw v0,0xc(s2); lw s3,0xc(s2)` and `sw s0,0x10(s2); lw v0,0x10(s2)`)
   are NOT reachable by types, aliases, opt_propagation/opt_common_subs off - store-to-load forwarding
   is a PEEPHOLE in b210 and `#pragma peephole off` reproduces both reloads exactly. Remaining: retail
   colours ctx s0, flag s1, arg0 s2, node s3, obj s4, env s5; b210 puts the parameter park in the
   highest slot of the outer locals (node s2 / arg0 s3) unless node is block-scoped, which then
   swaps node/obj (this body). Nested blocks and declaration permutations tried (12 variants). */
// measured: schedule on fills the call delay slots in func_003a8500.
#pragma schedule on
// measured: no_branch_likely on keeps func_003a8500's null tests as plain beq.
#pragma no_branch_likely on
// measured: peephole off keeps the two post-store reloads through arg0 (b210 forwards them otherwise).
#pragma peephole off
// FUN_003A8500
s32 func_003a8500(u8 *arg0)
{
    extern void func_003a8180();
    s32 flag;
    s32 ctx;
    s32 obj;
    s32 *env;
    s32 tmp;

    flag = 0;
    *(s32 *)(arg0 + 0xC) = func_003a7f80();
    {
    s32 node;
    node = *(s32 *)(arg0 + 0xC);
    if (node != 0) {
        ctx = func_004115d0();
        if (ctx == 0) {
            goto fail;
        }
        obj = func_00412ca0(ctx);
        if (obj == 0) {
            goto fail_free;
        }
        env = func_003cfa70();
        obj = func_00412fb0(obj, 0, env, 0);
        func_00412e90(obj, *env, 0, 0);
        tmp = func_004125e0(obj);
        if (tmp == 0) {
            goto fail_free;
        }
        obj = func_00412e90(tmp, *env, 0, 0);
        func_003cf9b0((u8 *)obj, 1, (void *)func_003a8180);
        func_003cfa30(obj, node);
store:
        *(s32 *)(arg0 + 0x10) = ctx;
        if (*(s32 *)(arg0 + 0x10) != 0) {
            flag = 1;
        }
    }
    }
    return flag;
fail_free:
    func_00411670(ctx);
fail:
    ctx = 0;
    goto store;
}
// measured: closes the peephole-off bracket for func_003a8500.
#pragma peephole on
// measured: closes no_branch_likely for func_003a8500.
#pragma no_branch_likely off
// measured: closes the schedule-on bracket for func_003a8500.
#pragma schedule off
