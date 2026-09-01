/* func_003cb720 near-match archive: object 72 bytes, window 80 bytes, normalized_diff 6; differing byte offsets 36,38,39,43,44,46; classification: conditional-move/branch-materialisation residual (retail movz $s1,$zero,$v0 versus MWCC branch+move); aggregate-field if body measured nd 6, ternary form nd 10, so source shape and width/order changes are ruled out; no compliant C form emits movz. */
s32 func_003cb720(s32 arg0, s32 arg1, u8 *arg2) {
    Cb720Obj *obj;

    obj = (Cb720Obj *)arg2;
    obj->field = func_003c5d10(arg0, arg2, arg2 + 0x20);
    if (obj->field == 0)
        arg0 = 0;
    return arg0;
}
