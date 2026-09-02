/* 2026-08-15 caller-saved temporary-rule probe: best candidate object_size=652B/window=656B, fndiff differing_words=45 (verifier normalized_diff=48), attempted-not-closed. Retail first definitions/registers: temp_2=lb->$v0, var_8=move->$t0, temp_7=lb->$a3, count=lhu->$v1, var_6(active)=sltu->$a2. Candidate emits the same order but colors temp_7->$a2 and var_6->$a3; arithmetic temp_5/var_3 are candidate $v1/$a1 versus retail $a1/$v1. Applied the derived liveness rule: rebuilt shared s8/s32 body and tried opt_propagation off, split/block-scoped temporaries, active aliases/gotos, staged/inline expressions, and type/control-flow variants; propagation/split/block probes left 45 words unchanged, while neutral liveness/type variants drifted size or control flow. Source reverted to INCLUDE_ASM after archive update; no pragma retained. */
s32 func_00115020(u8 *arg0, s32 arg1) {
    extern u16 D_008C027A[];
    s8 temp_2;
    s8 var_8;
    s8 temp_7;
    s32 var_6;
    u16 count;
    s32 temp_5;
    s32 var_3;

    temp_2 = *(s8 *)(arg0 + 4);
    var_8 = temp_2;
    temp_7 = *(s8 *)(arg0 + 5);
    count = *(u16 *)(arg0 + 0x22C);
    var_6 = arg1 != 0;
    if (var_6 == 0) {
        var_6 = (count & 0xFFFF) > 0;
    }
    if (D_008C027A[0] & 0x1000) {
        if (temp_2 < 4) {
            temp_5 = temp_2 + 3;
            var_3 = temp_5 & 3;
            if ((temp_5 < 0) && (var_3 != 0)) {
                var_3 -= 4;
            }
            var_8 = (s8)var_3;
        } else if (temp_2 < 8) {
            temp_5 = temp_2 + 3;
            var_3 = temp_5 & 3;
            if ((temp_5 < 0) && (var_3 != 0)) {
                var_3 -= 4;
            }
            var_8 = (s8)(var_3 + 4);
        }
    } else if (D_008C027A[0] & 0x4000) {
        if (temp_2 < 4) {
            temp_5 = temp_2 + 1;
            var_3 = temp_5 & 3;
            if ((temp_5 < 0) && (var_3 != 0)) {
                var_3 -= 4;
            }
            var_8 = (s8)var_3;
        } else if (temp_2 < 8) {
            temp_5 = temp_2 + 1;
            var_3 = temp_5 & 3;
            if ((temp_5 < 0) && (var_3 != 0)) {
                var_3 -= 4;
            }
            var_8 = (s8)(var_3 + 4);
        }
    } else if (D_008C027A[0] & 0x8000) {
        if (temp_2 < 4) {
            if (var_6 != 0) {
                var_8 = 8;
            } else {
                var_8 = (s8)(temp_2 + 4);
            }
        } else if (temp_2 < 8) {
            var_8 = (s8)(temp_2 - 4);
        } else {
            var_3 = temp_7 & 3;
            if ((temp_7 < 0) && (var_3 != 0)) {
                var_3 -= 4;
            }
            var_8 = (s8)(var_3 + 4);
        }
    } else if (D_008C027A[0] & 0x2000) {
        if (temp_2 < 4) {
            var_8 = (s8)(temp_2 + 4);
        } else if ((temp_2 < 8) && (var_6 != 0)) {
            var_8 = 8;
        } else {
            var_3 = temp_7 & 3;
            if ((temp_7 < 0) && (var_3 != 0)) {
                var_3 -= 4;
            }
            var_8 = (s8)var_3;
        }
    }
    if (var_8 != temp_2) {
        *(s8 *)(arg0 + 5) = temp_2;
        *(s8 *)(arg0 + 4) = var_8;
        return 1;
    }
    return 0;
}