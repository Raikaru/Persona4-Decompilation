// func_00110a60 archival near miss.
// Retail: 0x00110A60, 488 bytes (window 496 bytes).
// Best candidate: object 488 bytes, window 496 bytes, 10 reloc-masked differing words.
// Residual offsets: 264, 296, 300, 304, 420, 452, 456, 460; branch targets account for two additional word differences.
// Initial M2C-shaped probe was 32 differing words; declaration-order/parameter-reuse and corrected narrow callee casts reduced it to 10.
// Retail saved-register list: $s1 = arg0/month (also result sentinel), $s0 = arg1/day/index;
// loop values: $a2 = sum, $a3 = current month, $a1 = prior month; fallback address uses $v0/$v1.
// Applied rules: saved-register declaration order (var_7 before var_6), parameter reuse for the result,
// strict helper return widths (s16 comparisons and s8 result), global/field load ordering, and caller-saved
// temporary ordering. Tested and ruled out result locals of s8/s16/s32/s64, loaded locals, direct/array/pointer/helper
// load spellings, explicit result casts, declaration reorderings, opt_propagation off, opt_common_subs off,
// and optimization_level 1. opt_common_subs off regressed the loop register allocation; all other probes retained
// the same signed-byte tail residual. No inline asm, volatile, register, alias pragma, or new GP symbol used.
// Residual instruction shape: retail loads the fallback byte into $v0 then moves $s1,$v0 and $v0,$s1;
// MWCC candidate loads directly into $s1 then emits the signed-byte extension sequence.

s8 func_00110a60(s32 arg0, s32 arg1)
{
    s32 loaded;
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
        if ((temp_16_2 == (s16)func_00123b10()) &&
            ((s16)func_00123b40() == 3)) {
            arg0 = (s8)func_00123ae0();
        }
        if ((s8)arg0 == -1) {
            loaded = *(s8 *)((u8 *)&D_005E3A02[temp_16_2 * 6] + 2);
            arg0 = loaded;
        }
        return (s8)arg0;
    }
    temp_16_3 = func_00110600(arg0, temp_16);
    arg0 = -1;
    if ((temp_16_3 == (s16)func_00123b10()) &&
        ((s16)func_00123b40() == 4)) {
        arg0 = (s8)func_00123ae0();
    }
    if ((s8)arg0 == -1) {
        loaded = *(s8 *)((u8 *)&D_005E3A02[temp_16_3 * 6] + 2);
        arg0 = loaded;
    }
    return (s8)arg0;
}
