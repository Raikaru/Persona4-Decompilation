/* object 1316B / window 1408B / normalized_diff 1025; differing offsets: 0x0A, 0x0C, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x24, 0x26, 0x27, 0x28, 0x2A and throughout; classification: residual in hundreds after corrected helper declarations; ruled out: direct 3-argument signature, canonical block-scope func_0034f460/func_0034f4a0/func_0046d730 declarations, switch case order, float constants, and 64-bit packed call arguments; archived immediately per residual-hundreds rule. */
void func_0038b530(u8 *arg0, s32 arg1, f32 *arg2)
{
    extern void func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3,
                               s8 arg4, s64 arg5, f32 fparg0, f32 fparg1);
    extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                               f32 fparg2, s8 arg2, s8 arg3, s8 arg4,
                               s64 arg5, s64 arg6, s32 arg7, f32 fparg3,
                               s16 arg_sp0, s16 arg_sp8);
    extern void func_0046d730(void *arg0, s32 arg1);
    extern u8 D_0064F0E0[];
    s32 base;
    f32 x;
    f32 y;

    base = *(s32 *)(*(u8 **)arg0 + 0x1F2AC);
    x = arg2[0];
    y = arg2[1];
    switch (arg1) {
    case 1:
        func_0034f460(base, 64, 255, 255, 255, 255, 492.0f + x,
                      407.0f + y);
        func_0034f4a0(base, 65, 507.0f + x, 403.0f + y, 0.0f,
                      255, 219, 118, 0x1000, 0x1000, 0, -30.0f, 0, 0);
        func_0034f460(base, 6, 255, 255, 255, 255, 516.0f + x,
                      416.0f + y);
        func_0034f4a0(base, 1, 541.0f + x, 414.0f + y, 0.0f,
                      255, 219, 118, 0x1000, 0x1000, 0, -30.0f, 0, 0);
        break;
    case 2:
        func_0034f460(base, 6, 255, 255, 255, 255, 516.0f + x,
                      417.0f + y);
        func_0034f4a0(base, 3, 541.0f + x, 414.0f + y, 0.0f,
                      255, 219, 118, 0x1000, 0x1000, 0, -30.0f, 0, 0);
        break;
    case 3:
        func_0034f460(base, 7, 180, 180, 180, 255, 493.0f + x,
                      361.0f + y);
        func_0034f4a0(base, 4, 504.0f + x, 358.0f + y, 0.0f,
                      255, 219, 118, 0x1000, 0x1000, 0, -30.0f, 0, 0);
        func_0034f460(base, 6, 255, 255, 255, 255, 479.0f + x,
                      397.0f + y);
        func_0034f4a0(base, 5, 492.0f + x, 394.0f + y, 0.0f,
                      255, 219, 118, 0x1000, 0x1000, 0, -30.0f, 0, 0);
        break;
    case 4:
        func_0034f460(base, 20, 255, 255, 255, 255, 483.0f + x,
                      413.0f + y);
        func_0034f4a0(base, 29, 498.0f + x, 410.0f + y, 0.0f,
                      255, 219, 118, 0x1000, 0x1000, 0, -30.0f, 0, 0);
        func_0034f460(base, 6, 255, 255, 255, 255, 516.0f + x,
                      414.0f + y);
        func_0034f4a0(base, 19, 542.0f + x, 414.0f + y, 0.0f,
                      255, 219, 118, 0x1000, 0x1000, 0, -30.0f, 0, 0);
        break;
    default:
        func_0046d730(D_0064F0E0, 946);
        break;
    }
}
