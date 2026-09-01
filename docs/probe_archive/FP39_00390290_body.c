/* object 56 / window 64 / nd 13; best plain-C fallback. Retail sinks sd $ra into the beqz delay slot after lw $a0, while b210 saves $ra in the prologue and emits the branch/body one word later; no source shape closed this schedule residual. */
/* Residual is a conditional-call prologue/branch-delay scheduling mismatch; callee prototype is canonical s32 func_0038fb20(u8 *). */
s32 func_00390290(s32 arg0, s32 arg1)
{
    if (*(s32 *)(arg0 + arg1) != 0) {
        return func_0038fb20((u8 *)*(s32 *)(arg0 + arg1)) + 0x10;
    }
    return 0;
}
