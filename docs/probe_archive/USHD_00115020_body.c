/* object_size=652B; window=656B; normalized_diff=8; differing_offsets=0x00A,0x011,0x016,0x021,0x15E,0x1A6,0x21A,0x22E; differing_words=8; instruction_deficit=0 (body ends 4B before window; zero tail padding); retail_prologue=frame0B,saved_s0=0,arguments=(u8*,s32),first-touches=a0 pointer,a1 read,a2 scratch,a3 field-byte; candidate_prologue=frame0B,saved_s0=0,other-byte in a2 versus retail a3,active flag in a3 versus retail a2; classification=register/temp-register rotation residual; ruled_out=movz/movn,COP1 accumulator chain,standalone MMI,framed tail-jump,ee-gcc sd-$sN signature; plain-C signed-byte arithmetic, explicit u16 promotion mask, signed %4 fixup, shared high-range modulo path, absolute D_008C027A array addressing, and all five named floor signatures. */
s32 func_00115020(u8 *arg0, s32 arg1) {
    extern u16 D_008C027A[];
    s8 temp_2;
    s32 var_6;
    s8 var_8;
    u16 count;
    s8 temp_7;
    s32 var_3;
    s32 temp_5;

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