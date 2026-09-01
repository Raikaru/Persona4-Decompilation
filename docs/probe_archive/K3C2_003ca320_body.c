/* func_003ca320 archive: object 168 bytes, retail window 176 bytes, current normalized_diff 28; differing offsets 104,107,112-126. The residual is callback branch polarity/layout and continuation/epilogue displacement. Inverted callback guard/switch reduced object to 160B (nd 24), common finish label was 164B (nd 34), and pragma order was unchanged; prior declaration/volatile/asm probes remain ruled out. */
u8 *func_003ca320(u8 *arg0, s32 (*arg1)(u8 *, s32), s32 arg2) {
    u8 *stack[64];
    s32 depth;
    s32 value;
    u8 *current;

    current = *(u8 **)(arg0 + 0x1C);
    depth = 0;
loop:
    if (*(s32 *)current < 0)
        goto callback;
    value = *(s32 *)(current + 0xC);
    depth += 1;
    current = *(u8 **)(current + 8);
    stack[depth] = (u8 *)value;
check:
    if (depth >= 0)
        goto loop;
    goto finish;
finish:
    return arg0;
callback:
    if (arg1(current, arg2) != 0)
        goto callback_continue;
    return arg0;
callback_continue:
    current = stack[depth];
    depth -= 1;
    goto check;
}
