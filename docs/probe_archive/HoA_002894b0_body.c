// FUN_002894B0 near-match archive (HoA, wave Ho). Best measured state 42 MATCH / 1 MISMATCH in
// evtMain.c; lane yielded without measuring its final edit. Rules tried: five-formal signature (arg3
// unused, keeps fifth arg in $t0), reverse switch case order, scoped case-1 locals, saved-register
// declaration order s2/s1/s6/s7/s0, comma-expression boolean normalisation. Residual per lane:
// bounds register / block layout / final ordering. Body below is the live state at yield (unmeasured).

#pragma push
/* measured: temporary propagation-off bounds register experiment */
#pragma opt_propagation off
s32 func_002894b0(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s32 sp9C;
    s32 sp98;
    s32 var_2;
    s32 temp_2;
    s32 var_18;
    s32 var_17;
    s32 var_16;
    s32 var_22;
    s32 var_23;
    u32 flag;

    sp9C = 0;
    sp98 = 0;
    switch (arg0) {
    case 0:
        if (D_008821E0[0] != 1) {
            return 0;
        }
        if (func_002909a0((u32 *)(arg2 + 0x678)) == 0) {
            return 0;
        }
        D_008821E4[0] = 0;
        D_008821E8[0] = 0;
        D_008821EC[0] = -1;
        D_008821F0[0] = -1;
        D_008821F4[0] = 0;
        return 1;
    case 1: {
        s32 state0;
        s32 state1;
        s32 state2;
        s32 state3;
        s32 state4;

        state0 = D_008821E4[0];
        state1 = D_008821E8[0];
        state2 = D_008821EC[0];
        state3 = D_008821F0[0];
        state4 = D_008821F4[0];
        if ((state2 != -1) || (state3 != -1)) {
            if (state0 == 1) {
                *(s32 *)arg2 = *(s32 *)arg2 | 0x20;
            }
            func_002909b0(arg2 + 0x678, state1, state2, state3, state4);
        }
        return 1;
    }
    case 2:
        if (*(u16 *)arg4 == arg1) {
            if ((flag = ((*(u32 *)arg2 & 0x10) != 0), flag == 1)) {
                return 1;
            }
            if (func_0028bef0(arg2, arg4, &sp9C, &sp98) == 0) {
                return 1;
            }
            var_18 = D_008821E4[0];
            var_17 = D_008821E8[0];
            var_22 = D_008821EC[0];
            var_23 = D_008821F0[0];
            var_16 = D_008821F4[0];
            temp_2 = func_00290e50(arg2 + 0x678, sp9C);
            if (temp_2 == 0) {
                var_22 = sp9C;
                if (*(s8 *)(arg4 + 0x14) == 0) {
                    var_18 = 1;
                }
                var_17 = *(s8 *)(arg4 + 0x16);
            } else if (temp_2 != 0) {
                if ((sp98 == 0) || (sp98 >= 0xB)) {
                    var_2 = -1;
                } else {
                    var_2 = sp98 - 1;
                }
                *(s16 *)(arg2 + 0xBA) = var_2;
                var_23 = sp9C;
                var_16 = (s32)(s16)var_2;
                if (*(s8 *)(arg4 + 0x14) == 0) {
                    var_18 = 1;
                }
                func_00440b68((char *)D_0063C580, sp9C, arg1, var_16 - 0xC8);
            }
            D_008821E4[0] = var_18;
            D_008821E8[0] = var_17;
            D_008821EC[0] = var_22;
            D_008821F0[0] = var_23;
            D_008821F4[0] = var_16;
            return 1;
        }
    default:
        return 1;
    }
}
#pragma pop
