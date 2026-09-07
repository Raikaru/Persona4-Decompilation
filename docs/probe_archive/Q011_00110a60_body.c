/* Current replay: 488B/496B, eight executable differing words and eight
 * omitted zero-tail bytes. All 15 relocations resolve. Each fallback differs
 * in its join target, lb destination and two return-materialization words.
 * Early/shared/conditional/switch joins, a narrow inline accessor and
 * common-subexpression-off do not improve the retained source.
 * All 46 existing owner C functions preserve bytes and relocations.
 * No different getter width or compiler impossibility is established.
 */
/* The production owner now declares these getters consistently with their
 * live definitions: s8 func_00123ae0 and s16 func_00123b10/func_00123b40.
 * No block-scope prototype overrides are needed. The actual getters and
 * existing func_00110960 consumer pass 307,200 native32 override cases;
 * this unpromoted selector still has its eight-word executable floor. */
s8 func_00110a60(s32 arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 var_5;
    s32 var_7;
    s32 var_6;

    var_5 = arg1;
    temp_16 = var_5;
    var_6 = 0;
    if (arg0 != 4) {
        var_7 = arg0 - 1;
        if (var_7 == 0) {
            var_7 = 0xC;
        }
loop_3:
        var_5 = var_7 - 1;
        var_6 += D_005E45E0[var_5 % 12];
        if (var_7 != 4) {
            var_7 = var_5;
            if (var_5 == 0) {
                var_7 = 0xC;
            }
            goto loop_3;
        }
    }
    if (func_00110d30(var_6 + (temp_16 - 1)) == 1) {
        temp_16_2 = func_00110600(arg0, temp_16);
        arg0 = -1;
        if ((temp_16_2 == (s32)func_00123b10()) &&
            ((s32)func_00123b40() == 3)) {
            arg0 = (s64)func_00123ae0();
        }
        if ((s8)arg0 == -1) {
            arg0 = *(s8 *)((u8 *)&D_005E3A02[temp_16_2 * 6] + 2);
        }
        return (s8)arg0;
    }
    temp_16_3 = func_00110600(arg0, temp_16);
    arg0 = -1;
    if ((temp_16_3 == (s32)func_00123b10()) &&
        ((s32)func_00123b40() == 4)) {
        arg0 = (s64)func_00123ae0();
    }
    if ((s8)arg0 == -1) {
        arg0 = *(s8 *)((u8 *)&D_005E3A02[temp_16_3 * 6] + 2);
    }
    return (s8)arg0;
}
