/* b119 candidate for func_003c0050 (0x003c0050), 144B vs 144B window,
   differing words (reloc-masked): 12.  Residual is the ,p alignment nop after
   the filled back-edge delay slot; the code1_003c_cw119.c unit is plain -O2
   and cannot emit it.  Improved on W4C3C_003c0050_body.c (nd 13, 136B). */
#pragma schedule on
u8 *func_003c0050(u8 *arg0, s32 (*arg1)(s32, s32), s32 arg2) {
    extern s32 iGpffffb6b4;
    u8 *end;
    s32 *node;
    s32 next;

    end = arg0 + 0x10;
    node = *(s32 **)(arg0 + 0x10);
    if (node == (s32 *)end)
        return arg0;
loop:
    next = *node;
    if (arg1((s32)((u8 *)node - 4) - iGpffffb6b4, arg2) == 0)
        return arg0;
    node = (s32 *)next;
    if (next != (s32)end)
        goto loop;
    return arg0;
}
/* measured: closes the schedule bracket. */
#pragma schedule off
