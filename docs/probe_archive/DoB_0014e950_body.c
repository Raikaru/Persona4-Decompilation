/* Best measured reconstruction for func_0014e950 (not closed).
 * Best probe: DoB_0014e950_ac, object 684B/window 720B, residual 158 words.
 * Earlier probe residuals: 163, 160, 159, 158; opt_common_subs off reached 704B/157.
 * Tried: direct switch, explicit labelled joins, outer state guard, declaration/order
 * permutations, u8/s32 validity types, opt_rebuildconditionals off, schedule off,
 * opt_common_subs off. State dispatch register matched after naming temp_3 and
 * retaining temp_2_2; remaining control-flow/register/layout differences persisted.
 * Retail saved-register list: s0 (prologue sq/lq s0).
 */
s32 func_0014e950(u8 *arg0) {
    struct {
        u8 pad0[8];
        u8 bytes[4];
        u8 pad1[4];
        SVec3 out;
        u8 pad2[4];
        SVec3 src;
    } stack;
    f32 temp_f5;
    f32 temp_f4;
    f32 temp_f3;
    s32 temp_2_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    s32 var_4;
    s32 var_5;
    s32 var_7;
    s32 var_8;
    s8 temp_2_3;
    s8 temp_3_3;
    u32 var_9;
    u8 *var_5_2;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *var_2;
    u8 *var_6;
    u8 *var_6_2;
    extern void func_00122520(s32 arg0, s32 arg1);
    extern void func_001228a0(s32 arg0, s32 arg1, s32 arg2);
    extern void func_003e40b0(f32 *arg0, f32 *arg1);

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)temp_16;
    if (temp_3 != 2) {
        var_8 = 1;
        switch (temp_3) {
        case 0:
            temp_2 = *(u8 **)(temp_16 + 0xC);
            if (temp_2 != NULL) {
                if (*(s32 *)(*(u8 **)(temp_2 + 0x38)) <= 0) {
                    goto invalid_0014e950_valid;
                }
                goto check_0014e950_valid;
            }
            goto check_0014e950_valid;
invalid_0014e950_valid:
            var_8 = 0;
            goto check_0014e950_valid;
check_0014e950_valid:
            if (var_8 != 0) {
                var_2 = func_003e9700(*(s32 *)(func_00457120() + 4));
                var_6 = temp_16 + 0x10;
                var_5 = 8;
                do {
                    temp_4 = *(s32 *)(var_2 + 0);
                    temp_3_2 = *(s32 *)(var_2 + 4);
                    var_2 += 8;
                    var_5 -= 1;
                    *(s32 *)(var_6 + 0) = temp_4;
                    *(s32 *)(var_6 + 4) = temp_3_2;
                    var_6 += 8;
                } while (var_5 > 0);
                stack.src = *(SVec3 *)(temp_16 + 0x30);
                func_003e40b0(&stack.src.x, &stack.src.x);
                temp_f5 = stack.src.x * 700.0f;
                stack.src.x = temp_f5;
                temp_f4 = stack.src.y * 700.0f;
                stack.src.y = temp_f4;
                temp_f3 = stack.src.z * 700.0f;
                stack.src.z = temp_f3;
                stack.out = *(SVec3 *)(temp_16 + 0x40);
                stack.out.x += temp_f5;
                stack.out.y += temp_f4;
                stack.out.z += temp_f3;
                func_0014e740(*(u8 **)(temp_16 + 0xC), &stack.out.x);
                func_0045af60(1, 0xB, 3, 4);
                *(s32 *)(temp_16 + 8) = 0;
                *(s32 *)temp_16 = *(s32 *)temp_16 + 1;
            }
            break;
        case 1:
            temp_2_2 = *(s32 *)(temp_16 + 8);
            if (temp_2_2 < 0x54) {
                if (temp_2_2 >= 0x29) {
                    var_9 = 0;
                    while (var_9 < 4U) {
                        var_7 = 0;
                        temp_4_2 = D_007EF9B0 + (var_9 * 0x750);
                        if ((*(s32 *)(temp_4_2 + 0x48) != 0) &&
                            (*(u8 **)(temp_4_2 + 0x54) != NULL)) {
                            var_7 = 1;
                        }
                        if (var_7 != 0) {
                            temp_4_3 = *(u8 **)(temp_4_2 + 0x54);
                            *(s32 *)(temp_4_3 + 0x28) &= ~2;
                        }
                        var_9 += 1;
                    }
                }
                if (*(s32 *)(temp_16 + 4) == 1) {
                    var_6_2 = (u8 *)&iGpffff9dd0 + 8;
                    var_5_2 = (u8 *)&stack.bytes[0];
                    var_4 = 4;
                    do {
                        temp_3_3 = *(s8 *)(var_6_2 + 0);
                        temp_2_3 = *(s8 *)(var_6_2 + 1);
                        var_6_2 += 2;
                        var_4 -= 1;
                        *(s8 *)(var_5_2 + 0) = temp_3_3;
                        *(s8 *)(var_5_2 + 1) = temp_2_3;
                        var_5_2 += 2;
                    } while (var_4 > 0);
                    func_00122520(1, 1);
                    func_001228a0(stack.bytes[0], stack.bytes[1], stack.bytes[2]);
                    *(s32 *)temp_16 = *(s32 *)temp_16 + 1;
                }
                *(s32 *)(temp_16 + 8) = *(s32 *)(temp_16 + 8) + 1;
            } else {
                *(s32 *)temp_16 = temp_3 + 1;
            }
            break;
        default:
            break;
        }
        return 0;
    }
    return -1;
}
