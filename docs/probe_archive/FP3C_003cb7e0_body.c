/* func_003cb7e0 near-match archive: object 56 bytes, window 48 bytes, normalized_diff 29. */
extern s32 func_003cebb0(s32 arg0, u8 *arg1);
s32 func_003cb7e0(s32 arg0, s32 arg1, u8 *arg2) {
    s32 result;

    result = func_003cebb0(arg0, arg2);
    return (result == 0) ? 0 : arg0;
}
