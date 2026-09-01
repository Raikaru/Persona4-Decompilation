/* FUNC 00103B00 near-match archive: object 308B/window 320B, normalized_diff 1, first differing offset 0x103 (instruction at 0x100: retail daddiu $v1,$s0,1 vs candidate addiu), no real code deficit (remaining 12B are zero tail); classification scalar-width residual. Prologue: one saved s0, no arguments. Corrected block-scope declarations: func_00460b60(u8 *,s32,s32), func_00103c40(u8 *), D_00796460[]. Ruled out: direct while/for forms, explicit s64 casts, separate temporary, generated loop shape, optimization_level 1; no compiler-floor family applies. */
void func_00103b00(void) {
    extern u8 *func_00460b60(u8 *list, s32 arg1, s32 arg2);
    extern void func_00103c40(u8 *arg0);
    extern u8 D_00796460[];
    s64 index;

    func_00460b60(D_00796460, 6, 1);
    func_00460b60(D_00796460, 7, 2);
    func_00460b60(D_00796460, 8, 1);
    func_00460b60(D_00796460, 0xB, 6);
    func_00460b60(D_00796460, 0xA, 5);
    func_00460b60(D_00796460, 9, 1);
    func_00460b60(D_00796460, 0xC, 1);
    func_00460b60(D_00796460, 2, 4);

    for (index = 0; (s16)index < 2; index = (s16)(index + 1)) {
        func_00103c40(D_00796700 + ((s16)index * 0x370));
    }
}
