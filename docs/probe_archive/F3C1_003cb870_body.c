/* func_003cb870: object_size=84, window=96, normalized_diff=6, differing_offsets=0x30,0x32,0x33,0x37,0x38,0x3a; retail prologue saves are sq (not sd); corrected three-argument signature, existing file-scope func_003c9c20/func_003c5d10 helper types, schedule-on bracket, stored-field reload, declaration order, and pointer arithmetic were ruled out; residual is retail movz $s1,$zero,$v0 versus MWCCPS2 branch/store scheduling. */
s32 func_003cb870(s32 arg0, s32 arg1, u8 *arg2) {
    u8 *temp;
    s32 result;

    temp = func_003c9c20((u32)arg2);
    result = func_003c5d10(arg0, temp, temp + 0x10);
    *(s32 *)(arg2 + 0x78) = result;
    result = *(s32 *)(arg2 + 0x78);
    if (result == 0)
        arg0 = 0;
    return arg0;
}
