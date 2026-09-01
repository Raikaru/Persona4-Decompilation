/* object 776/784 normalized_diff 19 differing_offsets 285,290,294,298,302,306,310,318,322,324,326,327,328,332,334,336; classification exact-frame near-miss (8-byte zero tail), prologue/saved-register count exact (96-byte frame, saved s0-s3, two incoming pointers), block-scope untyped helper declarations; tried scalar s16 fields, reversed/array struct field order, struct aggregate copy, union aggregate, stack-array aggregate, pointer declaration/order, loop-shape, optimization_level 1/2, opt_common_subs off/on; archive because remaining residual is transient register/lifetime mapping in the field-copy block. */
void func_002962f0(u8 *arg0, u8 *arg1)
{
    extern u8 *func_00286780();
    extern u8 *func_00286f00();
    extern s32 func_002909a0();
    extern s32 func_00290e10();
    typedef struct {
        s16 v[4];
    } Values;
    Values stack;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_7;
    s32 temp_3;
    s32 temp_5;
    s32 var_16;
    u16 var_2;
    u16 var_3;
    u16 var_4;
    u8 *var_4_2;
    u8 *var_4_3;
    u8 *var_4_4;
    u8 *var_4_5;
    u8 *var_3_2;

    if ((func_002909a0(arg1 + 0x678) == 1) &&
        (func_00290e10(arg1 + 0x678) > 0)) {
        temp_17 = func_00286f00(4, arg1);
        var_16 = 0;
        goto loop_30_test;
loop_30_body:
            temp_5 = *(s32 *)(*(u8 **)(arg0 + 0x80) + 0x14);
            if (temp_5 == 4) {
                var_3 = *(u16 *)((u8 *)*(s32 **)(arg0 + 0x94) +
                                 var_16 * 0x10);
            } else {
                var_3 = *(u16 *)((u8 *)*(s32 **)(arg0 + 0x98) +
                                 var_16 * 0x3C);
            }
            if ((var_3 & 0xFFFF) == 4) {
                if (temp_5 == 4) {
                    var_2 = *(u16 *)((u8 *)*(s32 **)(arg0 + 0x94) +
                                     var_16 * 0x10 + 2);
                } else {
                    var_2 = *(u16 *)((u8 *)*(s32 **)(arg0 + 0x98) +
                                     var_16 * 0x3C + 2);
                }
                temp_2 = func_00286780(temp_17, var_2 & 0xFFFF, arg1);
                temp_3 = var_16 * 0x3C;
                temp_7 = (u8 *)*(s32 **)(arg0 + 0x98) + temp_3;
                stack = *(Values *)(temp_7 + 0xC);
                *(s16 *)(temp_2 + 8) = stack.v[0];
                *(s16 *)(temp_2 + 0xA) = stack.v[1];
                *(s16 *)(temp_2 + 0xC) = stack.v[2];
                *(s16 *)(temp_2 + 0xE) = stack.v[3];
                if (*(s32 *)(*(u8 **)(arg0 + 0x80) + 0x14) == 4) {
                    var_4 = *(u16 *)((u8 *)*(s32 **)(arg0 + 0x94) +
                                     var_16 * 0x10 + 4);
                } else {
                    var_4 = *(u16 *)((u8 *)*(s32 **)(arg0 + 0x98) +
                                     temp_3 + 4);
                }
                *(u16 *)(temp_2 + 2) = var_4;
                if (*(s32 *)(*(u8 **)(arg0 + 0x80) + 0x14) == 4) {
                    var_4_2 = (u8 *)*(s32 **)(arg0 + 0x94) +
                              var_16 * 0x10 + 8;
                } else {
                    var_4_2 = (u8 *)*(s32 **)(arg0 + 0x98) +
                              temp_3 + 0x14;
                }
                *(s16 *)(temp_2 + 0x10) = *(s16 *)var_4_2;
                if (*(s32 *)(*(u8 **)(arg0 + 0x80) + 0x14) == 4) {
                    var_4_3 = (u8 *)*(s32 **)(arg0 + 0x94) +
                              var_16 * 0x10 + 8;
                } else {
                    var_4_3 = (u8 *)*(s32 **)(arg0 + 0x98) +
                              temp_3 + 0x14;
                }
                *(s16 *)(temp_2 + 0x12) = *(s16 *)(var_4_3 + 2);
                if (*(s32 *)(*(u8 **)(arg0 + 0x80) + 0x14) == 4) {
                    var_4_4 = (u8 *)*(s32 **)(arg0 + 0x94) +
                              var_16 * 0x10 + 8;
                } else {
                    var_4_4 = (u8 *)*(s32 **)(arg0 + 0x98) +
                              temp_3 + 0x14;
                }
                *(s8 *)(temp_2 + 0x14) = *(s8 *)(var_4_4 + 4);
                if (*(s32 *)(*(u8 **)(arg0 + 0x80) + 0x14) == 4) {
                    var_4_5 = (u8 *)*(s32 **)(arg0 + 0x94) +
                              var_16 * 0x10 + 8;
                } else {
                    var_4_5 = (u8 *)*(s32 **)(arg0 + 0x98) +
                              temp_3 + 0x14;
                }
                *(s8 *)(temp_2 + 0x15) = *(s8 *)(var_4_5 + 5);
                if (*(s32 *)(*(u8 **)(arg0 + 0x80) + 0x14) == 4) {
                    var_3_2 = (u8 *)*(s32 **)(arg0 + 0x94) +
                              var_16 * 0x10 + 8;
                } else {
                    var_3_2 = (u8 *)*(s32 **)(arg0 + 0x98) +
                              temp_3 + 0x14;
                }
                *(s8 *)(temp_2 + 0x16) = *(s8 *)(var_3_2 + 6);
            }
            var_16 += 1;
loop_30_test:
        if (var_16 < *(s32 *)(arg0 + 0xAC))
            goto loop_30_body;
    }
}
