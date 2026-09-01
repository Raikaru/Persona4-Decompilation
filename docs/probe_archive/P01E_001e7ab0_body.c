/* object 364B, window 368B, normalized_diff 1, differing offsets 0xEC (retail daddiu $s1,$zero,1 vs candidate addiu $s1,$zero,1); classification: bounded MWCCPS2 width-selection floor (third member of the daddiu/addiu family); ruled out: no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump, or callee-saved sd floor; corrected block-scope callee views; whole-variable s64 widening (372B/nd137), 1u, (s32)1LL, 1L, 1LL (same nd1), explicit s64/u64 constant casts, sizeof(char), pointer differences, !0, computed comparisons, 64-bit helper returns, separate 64-bit locals, narrow temporaries, clean s64/u64/long-long function returns, u8/s8/u16/s16 destinations, and narrow initializer casts are ruled out by this family; retail daddiu is not source-drivable without unacceptable register churn. */
s32 func_001e7ab0(void) {
    extern s32 func_001dbba0();
    extern void func_001db5b0();
    extern s32 func_00231d70();
    extern s32 func_00231e20();
    extern s64 func_0029cc00();
    extern void func_0029cf50();
    extern u8 *func_0029d050();
    u8 *temp_20;
    u32 var_19;
    u32 var_18;
    s32 var_17;
    u8 *temp_16;
    u32 temp_3;
    u8 *sp60[12];
    u8 *var_2;

    temp_20 = func_0029d050();
    if (func_001dbba0(temp_20, func_0029cc00(0), 0, 0x2C, 1, &func_001db5b0) == 1) {
        if (*(u16 *)(temp_20 + 0x6A) == 1) {
            var_2 = *(u8 **)(temp_20 + 0x38);
        } else {
            var_17 = 0;
            var_18 = 0;
            var_19 = 0;
            goto loop_test;
loop_body:
            temp_16 = *(u8 **)(temp_20 + var_19 * 4 + 0x38);
            temp_3 = (u32)(func_00231e20(*(s32 *)(*(u8 **)(temp_16 + 0x30) + 0xA64)) & 0xFF);
            if (temp_3 >= var_18) {
                if (temp_3 == var_18) {
                    sp60[var_17 & 0xFFFF] = temp_16;
                    var_17 = (var_17 + 1) & 0xFFFF;
                } else {
                    var_18 = temp_3;
                    sp60[0] = temp_16;
                    var_17 = 1;
                }
            }
            var_19 += 1;
loop_test:
            if (var_19 < *(u16 *)(temp_20 + 0x6A))
                goto loop_body;
            var_2 = sp60[func_00231d70(var_17 & 0xFFFF)];
        }
        func_0029cf50(*(s32 *)(var_2 + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return -1;
}
