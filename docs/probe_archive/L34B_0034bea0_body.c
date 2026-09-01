/* fresh 2026-08-14 verify: func_0034bea0 object_size=636 window=640 normalized_diff=8;
 * differing byte offsets 160-167 (+0xA0/+0xA4) only. Candidate preheader is
 * andi $s0,$v1,1 then move $s2,$zero; retail is move $s2,$zero then
 * andi $s0,$v1,1. The +0x27c..+0x27f window tail is zero padding.
 * Corrected callee declaration: func_0046d730(void *, s32).
 * Newly re-tested and ruled out: source preheader order (nd 23), scoped
 * opt_common_subs off (nd 408), and schedule off (nd 8 with the same
 * residual; it regressed 14 following nLine functions). Existing ruled-out
 * probes remain: m2c prelude expansion/removal; for-initializer and pointer/
 * shift-index forms; local declaration order/register/type/width variants;
 * split byte-load/temporary dependencies; nested/comma assignment forms;
 * optimization levels; schedule on; opt_loop_invariants on; opt_propagation
 * off; randomized permute 1950 compiles/155s. Classification: preheader
 * statement-order scheduling floor.
 */
void func_0034bea0(void) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f2;
    s32 temp_16;
    s32 temp_4;
    s32 var_18;
    u8 *temp_17;

    if ((D_00884684[0] == 0) || (D_00884670[0] == 0)) {
        func_0046d730(&iGpffffa950, 0x235);
    }
    if ((f32)D_00884674[0] < D_00884678[0]) {
        D_00884674[0] += 1;
    }
    temp_16 = D_007523C0[D_00884670[0] * 0x10] & 1;
    var_18 = 0;
    for (; var_18 < 0x14; var_18++) {
        temp_4 = var_18 * 0x54;
        temp_17 = D_00882FF0 + temp_4;
        temp_f2 = *(f32 *)(temp_17 + 0x4C);
        temp_f1 = (f32)D_00884674[0];
        if (temp_f1 < temp_f2) {
            temp_f20 = 0.0f;
            temp_f0 = temp_f20;
        } else if (temp_f1 < *(f32 *)(temp_17 + 0x50)) {
            temp_f1 = temp_f1 - temp_f2;
            temp_f0 = *(f32 *)(temp_17 + 0x50) - temp_f2;
            temp_f21 = temp_f1 / temp_f0;
            temp_f22 = iGpffff8094 * temp_f21;
            temp_f20 = func_0044b7b0(temp_f22);
            if (temp_f21 < 0.5f) {
                temp_f0 = func_0044b7b0(2.0f * temp_f22);
            } else {
                if (*(s32 *)(temp_17 + 0x44) == 0) {
                    *(f32 *)(temp_17 + 0x3C) = *(f32 *)(temp_17 + 0x40);
                    *(f32 *)(temp_17 + 0x38) = *(f32 *)(temp_17 + 0x30) - *(f32 *)(temp_17 + 0x40);
                    *(s32 *)(temp_17 + 0x44) = 1;
                }
                temp_f0 = func_0044b7b0(2.0f * temp_f22 - iGpffff8094);
            }
        } else {
            temp_f20 = 1.0f;
            temp_f0 = temp_f20;
        }
        *(f32 *)(temp_17 + 8) = *(f32 *)(temp_17 + 0x18) + *(f32 *)(temp_17 + 0x10) * temp_f20;
        *(f32 *)(temp_17 + 0xC) = *(f32 *)(temp_17 + 0x1C) + *(f32 *)(temp_17 + 0x14) * temp_f20;
        *(f32 *)(temp_17 + 0x24) = *(f32 *)(temp_17 + 0x2C) + *(f32 *)(temp_17 + 0x28) * temp_f20;
        *(f32 *)(temp_17 + 0x34) = *(f32 *)(temp_17 + 0x3C) + *(f32 *)(temp_17 + 0x38) * temp_f0;
        if (temp_16 != 0) {
            func_0034c120(temp_17);
        }
    }
}
