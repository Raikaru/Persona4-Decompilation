/* func_003cb720 archive: object 72B, window 80B, normalized_diff 6; differing offsets 36,38,39,43,44,46; block-scope aggregate field body, helper declaration, argument order, schedule bracket, and integer widths reproduce all non-residual words; retail's movz $s1,$zero,$v0 conditional move remains the compiler-floor residual. */
s32 func_003cb720(s32 arg0, s32 arg1, u8 *arg2) {
    Cb720Obj *obj;

    obj = (Cb720Obj *)arg2;
    obj->field = func_003c5d10(arg0, arg2, arg2 + 0x20);
    if (obj->field == 0)
        arg0 = 0;
    return arg0;
}
