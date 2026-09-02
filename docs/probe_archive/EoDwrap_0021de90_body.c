/*
 * func_0021de90 attempted-not-closed.
 * Best measured candidate: lane EoD33, object 440B / 448B window,
 * residual 5 words (retail uses $at for the upper-bound compare;
 * candidate uses $v1). Retail live-across-call saved registers: $s2, $s1, $s0;
 * $ra is saved in the standard frame. Retail upper-bound tail:
 *   lui $at,1; slt $at,$v0,$at; bnez $at,loc_21E020;
 *   nop; li $v0,0xFFFF; b loc_21E02C; nop;
 *   loc_21E020: bgtz $v0,loc_21E02C; nop; li $v0,1.
 * Rules applied: saved-register declaration order, left-to-right argument
 * materialisation, GP-before-field load ordering, explicit table-value local
 * with opt_propagation off, FPU multiply operand ordering, and goto tail
 * layout. Other probes tried ternary/nested ternary, named limit/boolean
 * locals, equivalent bounds, loop layout, and permitted optimization pragmas;
 * none closed the final register difference without disturbing the match.
 */
#pragma push
#pragma opt_propagation off
s32 func_0021de90(s32 arg0, u8 *arg1)
{
    s32 value;
    s32 result;
    f32 scale;
    f32 table_value;
    s32 delta;
    s32 index;

    value = *(s32 *)(arg1 + 4);
    if (value <= 0) {
        return 0;
    }
    if ((*(u16 *)arg1 & 8) == 0 && func_00106330(0x1403) != 0) {
        if (func_00106330(0x1428) != 0) {
            value = (s32)(2.0f * (f32)value);
        } else if (func_00106330(0x1429) != 0) {
            value = 0;
        }
    }
    scale = 1.0f / (f32)*(s32 *)(arg1 + 0x20);
    if ((*(s32 *)(iGpffffb414 + (*(s32 *)(arg1 + 0xC) * 0x18)) & 0x80) != 0) {
        result = (s32)((f32)value * scale);
    } else {
        delta = *(s32 *)(arg1 + 0x38) - arg0;
        if (delta >= 10) {
            index = 20;
        } else if (delta < -9) {
            index = 0;
        } else {
            index = delta + 10;
        }
        table_value = iGpffffb40c[index];
        result = (s32)(scale * ((f32)value * table_value));
    }
    if ((result < 0x10000) ? 1 : 0) {
        goto normal_result;
    }
    result = 0xFFFF;
    goto finish;
normal_result:
    if (result > 0) {
        goto finish;
    }
    result = 1;
finish:
    return result;
}
#pragma opt_propagation on
#pragma pop
