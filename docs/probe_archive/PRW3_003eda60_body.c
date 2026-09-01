/* object_size=188 window=208 normalized_diff=102 differing_offsets=12,13,14,15,28,29,30,31,34,37,38,42,54,58,70,71 classification=undersized-register-order/global-address residual; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; declarations corrected at block scope: D_00752FD0 as s8[] absolute DATA array, D_008873B4 as typed callback array; no callee prototype mismatch; no pragma retained */
/* Best measured body: typed three-byte stack buffer and callback pointer local. */
s32 func_003eda60(s8 *arg0, s8 *arg1, s32 arg2)
{
    extern s8 D_00752FD0[];
    extern void (*D_008873B4[])(s8 *arg0, s8 *arg1);
    s8 temp_3[3];
    s32 temp_2;
    s32 var_3;
    void (**callback)(s8 *arg0, s8 *arg1);

    temp_3[0] = 0x6d;
    var_3 = 0;
    temp_2 = arg2 & 0xff;
    if ((temp_2 > 0) && (temp_2 < 0x10)) {
        var_3 = 1;
    }
    if (var_3 != 0) {
        temp_3[1] = D_00752FD0[arg2 & 0xff];
    } else {
        temp_3[1] = 0;
    }
    temp_3[2] = 0;
    if (temp_3[1] != 0) {
        callback = D_008873B4;
        callback[0](arg0, temp_3);
        if ((arg1 != 0) && (*arg1 != 0)) {
            callback[0](arg1, temp_3);
        }
    }
    return 1;
}
