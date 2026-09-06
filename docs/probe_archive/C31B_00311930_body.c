/* Re-certified under scoped optimization_level 1: object 596B / window
 * 608B, raw fndiff 8 words = five executable words and three zero-tail
 * words. The historical normalized_diff=6 counts differing bytes, not
 * words. Executable offsets: 0x70, 0x74, 0x88, 0x8C, 0x90; candidate
 * cvt.w.s/mfc1 and sub.s/cvt.w.s/mfc1 use $f1 where retail uses $f0.
 * Direct u8 conversion of the same table expression, a direct integer
 * initializer, and a const float initializer all leave this unchanged.
 * Preserve both lookups, the u8 conversion, and the later unsigned
 * integer-to-float conversion. Reversed float declaration order also
 * failed previously. Retain ASM. */
/* Independent retail review confirms low-u16 community ID, input-only
 * persona pointer, low-s8 scaling flag and full s32 result. Correcting
 * these parameter types preserves the five-word floor. Native semantic
 * smoke: 42,735 scenarios / 204,435 helper calls, including independent
 * rank snapshots, assignment-loop behavior and division before scaling. */
/* saved-register audit: retail s7=arg2, s6=temp_17 (scaled delta), s5=arg0, s4=arg1, s3=temp_19 (byte count), s2=var_18 (accumulator), s1=var_17 (then var_3), s0=temp_16 (count); this list matches exactly under optimization_level 1. No opt_propagation-off three-part recipe is needed: no parameter-derived local is materialized. */
#pragma push
#pragma optimization_level 1
s32 func_00311930(u16 arg0, u8 *arg1, s8 arg2)
{
    extern s32 func_00115890(u8 *arg0, s32 arg1);
    extern f32 D_007494D0[];
    extern f32 D_00749500[];
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    s32 temp_19;
    s32 var_18;
    s64 temp_17;
    s32 var_17;
    s32 temp_16;
    s32 var_3;
    temp_f1 = D_00749500[func_00107ac0(arg0 & 0xFFFF)];
    temp_19 = (u8)temp_f1;
    temp_f1_2 = D_00749500[func_00107ac0(arg0 & 0xFFFF)];
    var_f0 = (f32)(u32)temp_19;
    temp_17 = (s16)(10.0f * (temp_f1_2 - var_f0));
    var_18 = 0;
    var_17 = 0;
    temp_16 = temp_19 & 0xFF;
    while ((s16)(s64)var_17 < temp_16) {
        var_18 = func_00115890(arg1, (u8)var_17);
        var_17 = (s16)(var_17 + 1);
    }
    var_3 = (s16)temp_17;
    if (var_3 != 0) {
        temp_16 = func_00115890(arg1, (u8)(temp_16 - 1));
        var_18 += (s32)((s32)var_3 * 10 * ((func_00115890(arg1, temp_19) - temp_16) / 100));
    }
    if ((s8)arg2 == 0) {
        return var_18;
    }
    return (s32)((f32)var_18 * D_007494D0[func_00107ac0(arg0 & 0xFFFF)]);
}
#pragma pop
