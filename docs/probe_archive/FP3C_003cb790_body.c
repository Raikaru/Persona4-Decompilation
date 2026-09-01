/* func_003cb790 near-match archive: object 56 bytes, window 48 bytes, normalized_diff 29. */
extern s32 func_003ce560(s32 arg0, u8 *arg1);
s32 func_003cb790(s32 arg0, s32 arg1, u8 *arg2) {
    s32 result;

    result = func_003ce560(arg0, arg2);
    return (result == 0) ? 0 : arg0;
}
