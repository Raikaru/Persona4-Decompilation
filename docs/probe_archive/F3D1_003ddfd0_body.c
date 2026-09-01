/* F3D1 archive func_003ddfd0: object 76B/window 80B, normalized_diff 38, differing offsets 0x04,0x08,0x0C,0x10,0x14,0x18,0x34,0x38,0x3C,0x40,0x44 (plus padded tail); classification: prologue/epilogue save-and-move ordering residual. Retail saves $ra/$s0 before the corresponding moves and restores before mflo; candidate computes the same call and arithmetic but MWCC orders those operations differently. Retail uses sq, not the GCC sd separator. The EE rd-form mult `$a2,$s0,$a2` (raw 0x02063018) is reachable from plain C here: candidate emits the same word at +0x14 versus retail +0x18, so the residual is ordering only, not a mult compiler floor. */
u32 func_003ddfd0(s32 arg0, u32 arg1, s32 arg2, u8 *arg3) {
    u32 result;

    arg2 = arg1 * arg2;
    result = (*(u32 (**)(u8 *, s32, s32))(*(u8 **)(arg3 + 0x50) + 0x34))(arg3, arg0, arg2);
    return result / arg1;
}
