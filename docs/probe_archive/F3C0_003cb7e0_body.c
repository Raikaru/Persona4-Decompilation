/* func_003cb7e0 archive: object 56B, window 48B, normalized_diff 29; differing offsets 24-29 and 31-40; wrapper takes three parameters (second ignored), helper prototype is block-scope s32 func_003cebb0(s32,u8*), and schedule fills the call delay slot; object exceeds window, so archive immediately; residual is the retail movz $s0,$zero,$v0 conditional-move shape and resulting epilogue size, not a declaration or global-address issue. */
s32 func_003cb7e0(s32 arg0, s32 arg1, u8 *arg2) {
    extern s32 func_003cebb0(s32 arg0, u8 *arg1);
    s32 result;

    result = func_003cebb0(arg0, arg2);
    return (result == 0) ? 0 : arg0;
}
