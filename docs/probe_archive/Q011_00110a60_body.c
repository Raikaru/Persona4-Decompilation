/* Main 2026-09-03: live nd10 (both fallback blocks): retail `lb v0,2(v0); move s1,v0; move v0,s1`, b210 `lb s1`
   + dsll32/dsra32 for the s8 return. s8/s32 result locals, an s8 temp copy, s32 return type, (s8) casts on the
   call result, opt_propagation off: the load always lands in $s1 directly. Open. */
// measured: object_size 488, window 496, normalized_diff 18; differing offsets 264,298,300,301,302,304,305,306,307,420,454,456,457,458,460,461; classification: near-miss register/codegen residual in signed-byte fallback load; ruled out corrected callee declarations (func_00110d30 one s32 arg, func_00110600 two s32 args, func_00123b10/func_00123b40 s16 returns, func_00123ae0 s8 return), s8/s16/s32/s64 result locals, direct/array/pointer load spellings, parameter reuse, declaration order, explicit sentinel casts, and optimization_level 1 (regressed 14 siblings); no compiler-floor instruction observed.
s8 func_00110a60(s32 arg0, s32 arg1)
{
    extern s8 func_00123ae0(void);
    extern s16 func_00123b10(void);
    extern s16 func_00123b40(void);
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
