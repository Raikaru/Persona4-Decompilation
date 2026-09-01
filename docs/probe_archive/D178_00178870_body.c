/* object 108B, retail window 112B, normalized_diff 4; residual offsets 56-59 are retail andi $a3,$s1,0xffff versus candidate move $a3,$s1 (WIDTH/TRUNCATION). Re-measured nd 4 with the archived s32 local. Ruled out block-scope fourth-u16 (nd 10, mask hoisted before lhu), mixed third-s32/fourth-u16 (nd 6), u16/u32 locals, explicit casts/masks, named loads, comma-sequenced dependency (nd 12), aggregate/union/bitfield forms, declaration-order, formal-width, register, pointer/struct, O1, schedule/propagation/CSE, function-pointer, widened s64 return-source, and identity arithmetic dependencies. File-scope func_00161630 remains u16,u16,u16,s32 for matching callers. */
s32 func_00178870(void) {
    s32 a = func_0029cc00(0);
    u8 *p = iGpffff9db0;
    s32 b = func_0015a160();

    func_0029cf50(func_00161630(*(u16 *)p, *(u16 *)(p + 4), b, a) & 0xFFFF);
    return 1;
}
