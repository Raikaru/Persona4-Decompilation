/* func_00110a60 compiler-floor archive (MWCCPS2 b210, current TU, 2026-09-03).
 * Best retained C body: object 488B, retail window 496B, normalized_diff 18B;
 * fndiff reports 10 relocation-masked differing words. Visible residual rows are
 * byte offsets 264, 296, 300, 304, 420, 452, 456, 460; the two branch-target
 * encodings account for the extra two fndiff words beyond the six fallback rows.
 * Retail fallback shape is lb $v0,2($v0); daddu $s1,$v0,$zero; daddu $v0,$s1,$zero
 * in both blocks. MWCC b210 instead loads directly into $s1 and emits dsll32/dsra32
 * on $v0, so the sentinel branches target four bytes earlier than retail.
 * Exact object/window sizing is stable; the retail tail is zero padding only.
 * Measured and ruled out in the current TU: D0H/Q011 body forms; direct, array,
 * pointer, const-pointer, and helper load spellings; s8/s16/s32/s64 loaded/result
 * locals and return widths; parameter reuse, declaration order, initialization,
 * alias, shadow, branch-local, and union liveness; exact block-scope prototypes
 * for func_00110d30/func_00110600 and the three 00123 callees; sentinel cast
 * forms; ternary, switch, goto, labels, do/while, early-return, and while layouts;
 * inline helpers; opt_propagation, opt_common_subs, opt_rebuildconditionals,
 * opt_loop_invariants, schedule, and optimization_level 1. These either remained
 * at fndiff 10 or regressed. No inline asm, volatile/register steering, banned
 * pragma, alias, GP-symbol, or ABI lever was used. Production is bare INCLUDE_ASM.
 */
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
