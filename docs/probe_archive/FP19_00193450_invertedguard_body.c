s32 func_00193450(void)
{
    extern s64 func_00105ee0(s32 arg0);
    extern s32 func_00105610();
    extern void func_001056e0();
    extern void func_00105d50();
    u32 var_16;
    u32 dep;

    if (func_0029d020() >= 0xB) {
        if (iGpffffb3ac != NULL) {
            iGpffffb3b0 = 0;
            return 0;
        }
        if (iGpffffb3b0 == 0) {
            if (func_002428f0(func_00105510(1), 0) != 0) {
                dep = iGpffffb280;
                func_0029db50(0xF, iGpffffb284, dep, 0);
                func_0014b990(*(s32 *)(func_0029d040() + 0x148));
                func_00260510();
                iGpffffb3b0 = 1;
                goto block_13;
            }
            var_16 = 0;
            goto loop_11_check;
loop_11_body:
            if ((((s64)(func_00105ee0((s32)var_16) << 0x30) >> 0x30) != 0) &&
                (func_00105610(func_00105ee0((s32)var_16)) != 0)) {
                func_001056e0(func_00105ee0((s32)var_16), 1);
                func_00105d50(func_00105ee0((s32)var_16), 0x80000);
            }
            var_16 += 1;
loop_11_check:
            if (var_16 < 3U) {
                goto loop_11_body;
            }
            return 1;
        }
    }
block_13:
    return 0;
}