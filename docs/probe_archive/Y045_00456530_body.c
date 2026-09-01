/* measured: object 348B, retail window 352B, normalized_diff 74; first differing offsets 141,144,146,147,148,150,151,152,153,154,155,156,158,159,160,161 (verify first_diffs; fndiff reloc-masked differing words 32); corrected target call shape with block-scope func_00454d20(u8 *,u8 *) and func_00456400(s32,s32,s32,u8 *), explicit pointer-to-int casts; tried trampoline/test-first loop forms, local declaration/type permutations, and file/block-scope callee declarations without reducing residual. No volatile, pragma, or inline asm used. */
void func_00456530(u8 *arg0, u8 *arg1, s32 arg2) {
    extern void func_00454d20(u8 *arg0, u8 *arg1);
    extern void func_00456400(s32 arg0, s32 arg1, s32 arg2, u8 *arg3);
    u8 sp34C[4];
    u8 sp240[0x100];
    u8 sp140[0x100];
    u8 sp40[0x100];
    s32 temp_16;
    u8 *temp_3;
    s8 temp_4;
    s32 temp_post_3;
    s32 temp_post_4;
    s32 var_16;
    s32 var_3;
    s32 var_7;

    func_00454d20(arg0, sp240);
    var_16 = 0;
loop_00456530_body:
    func_0043f810(sp40, sp240, 0xFC);
    func_0043f810(sp140, arg1 + var_16, 0xFC);
    if (*(s8 *)sp140 != 0) {
        func_0043f810(sp34C, arg1 + (var_16 + 0xFC), 4);
        temp_16 = var_16 + 0x100;
        func_00442428(sp40, sp140);
        var_7 = 0;
        {
            s32 temp_2;
            s32 temp_5;
            s8 temp_2_2;
            temp_5 = 0x5C;
            temp_2 = 0x2F;
            while (var_7 < 0xFF) {
                temp_3 = sp40 + var_7;
                temp_4 = *(s8 *)temp_3;
                if ((temp_4 >= 0x61) && (temp_4 < 0x7B)) {
                    *temp_3 = (u8)(temp_4 - 0x20);
                }
                temp_2_2 = *(s8 *)temp_3;
                if (temp_2_2 != 0) {
                    if (temp_2_2 == temp_2) {
                        *temp_3 = (u8)temp_5;
                    }
                    var_7 += 1;
                } else {
                    break;
                }
            }
        }
        func_00456400((s32)arg1, (s32)(arg1 + temp_16), *(s32 *)sp34C, sp40);
        temp_post_4 = *(s32 *)sp34C + 0x3F;
        var_3 = temp_post_4 >> 6;
        if (temp_post_4 < 0) {
            var_3 = (temp_post_4 + 0x3F) >> 6;
        }
        temp_post_3 = var_3 << 6;
        *(s32 *)sp34C = temp_post_3;
        var_16 = temp_16 + temp_post_3;
        if (arg2 != 1) {
            goto loop_00456530_body;
        }
    }
}
