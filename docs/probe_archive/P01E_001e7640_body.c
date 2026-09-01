/* object 416B vs window 432B, normalized_diff 284, differing offsets begin 0x00 (prologue/frame and all following offsets); classification: initial plain-C reconstruction had an extra saved register/frame due to retaining work across calls, not a retail floor. Later pointer-lifetime probe reduced to frame208/five saved registers but remained a branch-shape/materialization near-miss in the mode setup. Ruled out on sight: movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump forwarder, and sd-saved-register floor; callee declarations corrected at function scope for func_001d7c60, func_00231e20(u8 *), func_00231d70(u32), and func_0029cf50(s32). */
s32 func_001e7640(void) {
    struct Frame {
        u8 *selected[12];
        u8 *entries[14];
        u16 count;
    } frame;
    extern void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);
    extern s32 func_00231e20(u8 *arg0);
    extern u32 func_00231d70(u32 arg0);
    extern void func_0029cf50(s32 arg0);
    u8 *formation;
    s32 mode;
    u32 best_score;
    u32 selected_count;
    u32 index;
    u8 *current;
    u16 flags;
    u8 *work;
    u32 score;

    formation = func_0029d050();
    mode = (*(u8 **)(formation + 0x30))[0xA2] == 0;
    func_001d7c60(formation, (u8 *)&frame.entries[0], 2, 0, 0);
    best_score = 0;
    selected_count = 0;
    index = 0;
    mode = mode & 0xFFFF;
    while ((u16)index < frame.count) {
        current = frame.entries[(u16)index];
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            work = *(u8 **)(current + 0x30);
            if (*(u8 *)(work + 0xA2) == (u16)mode &&
                func_002428f0(*(s32 *)(work + 0xA64), 0) == 0) {
                score = func_00231e20(*(u8 **)(work + 0xA64)) & 0xFF;
                if (score == best_score) {
                    frame.selected[(u16)selected_count] = current;
                    selected_count = (selected_count + 1) & 0xFFFF;
                } else if (best_score < score) {
                    best_score = score;
                    frame.selected[0] = current;
                    selected_count = 1;
                }
            }
        }
        index = (index + 1) & 0xFFFF;
    }
    if ((s32)(u16)selected_count > 0) {
        current = frame.selected[func_00231d70((u16)selected_count)];
        func_0029cf50(*(s32 *)(current + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
