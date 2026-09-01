/* remeasured 2026-08-14: object 120B/window 128B, normalized_diff 25, differing offsets 0x00, 0x30, 0x58-0x6B, 0x78-0x7B. schedule/no_branch_likely and do-loop preserve helper calls, callback loads, branch polarity and return; retail frame is 0x50 versus candidate 0x40, with branch landing and final call/epilogue scheduling residual. Restored fallback after scoped probe. */
s32 func_003d60f0(u8 *arg0)
{
    extern s32 func_003df8a0();
    extern s32 *func_003df890();
    extern void func_003df7f0();
    s32 *end;
    s32 *ptr;
    s32 value;

    end = (s32 *)func_003df8a0(*(s32 *)(arg0 + 4));
    ptr = func_003df890(*(s32 *)(arg0 + 4));
    if (ptr != end) {
        do {
            value = *ptr;
            ptr++;
            (*(void (**)(s32))(*(u8 **)arg0 + 0x1C))(value);
        } while (ptr != end);
    }
    func_003df7f0(*(s32 *)(arg0 + 4));
    return 1;
}
