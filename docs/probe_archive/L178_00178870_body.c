/* object 108B, retail window 112B, normalized_diff 8; differing offsets 28 and 56. Probed raw s32/u16/u32 local types; callee func_00161630 width variants; explicit masks/casts; named argument/load locals; declaration order; comma/identity dependencies; optimization/schedule/peephole pragmas; control-flow anchors; expression narrowing/pointer/union/struct; and 600s permuter. No volatile or inline asm. */
s32 func_00178870(void) {
    u16 a = (u16)func_0029cc00(0);
    u8 *p = iGpffff9db0;
    s32 b = func_0015a160();

    func_0029cf50(func_00161630(*(u16 *)p, *(u16 *)(p + 4), b, a) & 0xFFFF);
    return 1;
}
