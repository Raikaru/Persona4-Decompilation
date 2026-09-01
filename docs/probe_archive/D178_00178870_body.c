/* object 108B, retail window 112B, normalized_diff 4; residual offsets 56-59 are retail andi $a3,$s1,0xffff versus candidate move $a3,$s1 (WIDTH/TRUNCATION). Re-measured with the saved-register list a->s1, p->s0 and a local u16 fourth-parameter callee prototype; the latter leaves the residual unchanged. The saved-register assignment is already declaration-order exact (b dies before the next call). Narrowing/cast/local-load/pragma probes either preserve the move or hoist the mask before the lhu loads. File-scope func_00161630 remains u16,u16,u16,s32 for matching callers. */
s32 func_00178870(void) {
    s32 a = func_0029cc00(0);
    u8 *p = iGpffff9db0;
    s32 b = func_0015a160();

    func_0029cf50(func_00161630(*(u16 *)p, *(u16 *)(p + 4), b, a) & 0xFFFF);
    return 1;
}
