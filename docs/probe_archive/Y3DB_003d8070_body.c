/* measured: object 208B vs 192B window, normalized_diff 144; differing offsets (fndiff first_diffs byte offsets) [4,5,6,7,8,10,11,12,14,16,18,20,22,28,29,30] plus relocation-masked word residuals through 0xCC; casts written: none (integer/pointer-only); levers ruled out: corrected callee widths/counts at block scope, retained folded field displacement form; automatic archive because object exceeds retail window. */
s32 func_003d8070(s32 arg0, u8 **arg1, s32 arg2) {
    u8 *base;
    u8 **slot;
    u8 *obj;
    extern s32 func_003d5750(u8 *arg0);
    extern void func_003d5840(u8 *arg0, u8 *arg1);
    extern s32 *func_003d7490(s32 *arg0);
    extern void func_003d5830(u8 *arg0);

    base = (u8 *)arg0 + D_00724840;
    slot = (u8 **)(base + arg2 * 4 + 8);
    *slot = func_003d5790(func_003d5750((u8 *)arg1),
                           *(s32 *)(*(u8 **)arg1 + 4));
    if (*slot != NULL) {
        func_003d5840(*slot, (u8 *)arg1);
        if (func_003d7490((s32 *)base) != NULL) {
            obj = *(u8 **)((u8 *)arg1 + 0x14);
            *(s32 *)(obj + 0x40) += 1;
            return arg0;
        }
        func_003d5830(*slot);
    }
    return 0;
}
