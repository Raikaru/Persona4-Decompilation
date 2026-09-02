/* object 108B, retail window 112B, normalized_diff 4; residual offsets 56-59 are retail andi $a3,$s1,0xffff versus candidate move $a3,$s1 (WIDTH/TRUNCATION). This is a call-site narrowing, not the caller-saved temporary pool, so the temporary rule predicts no pool/register-liveness change. Tried the requested argument-expression spellings with u32 s1val: `(u16)s1val` and inline `s1val & 0xffff`; both remained nd4 (one real word), hoisting `andi $a3,$s1,0xffff` before the two lhu loads rather than into the retail argument slot. No closure; retain this best body and revert source to INCLUDE_ASM. The saved-register assignment is already declaration-order exact (b dies before the next call). Narrowing/cast/local-load/pragma probes either preserve the move or hoist the mask before the lhu loads. File-scope func_00161630 remains u16,u16,u16,s32 for matching callers. */
s32 func_00178870(void) {
    s32 a = func_0029cc00(0);
    u8 *p = iGpffff9db0;
    s32 b = func_0015a160();

    func_0029cf50(func_00161630(*(u16 *)p, *(u16 *)(p + 4), b, a) & 0xFFFF);
    return 1;
}
