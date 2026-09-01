/* object_size=476 window=464 normalized_diff=258 differing_offsets=0x60,0x81,0x85,0x88,0x91,0x95,0x98,0xA8-0xAE,... classification=oversized/residual-hundreds; ruled_out=corrected callee declarations (002012d0 u8*,f32,f32; 00201650 u8*,s32,s32,f32,f32,s32,s32,s32,s32; 00201820 s32; 002019e0 u8*,f32; D_00887300 callback), GP global iGpffffb474 at 0x00764564, parameter arg0 u8*, arg1 s8, loop/order/casts, opt_propagation off probe; no movz/movn, no COP1 accumulator chain, no standalone MMI, no framed tail-jump, no sd-saved-s register floor. */
// FUN_00204B80
void func_00204b80(u8 *arg0, s8 arg1)
{
    extern u8 iGpffffb474;
    f32 var_f20;
    f32 var_f21;
    s64 var_16;
    s64 var_17;
    s64 var_2;
    u8 temp_3;

    {
        void (**base)(u32, u32);

        base = D_00887300;
        base[0](6, 1);
    }
    func_002012d0(arg0, 36.0f, 19.0f);
    func_002019e0(arg0, 72.0f);
    func_00201820(2);
    var_f20 = 0.0f;
    var_17 = 0;
    while ((s16)var_17 < 3) {
        var_f21 = 0.0f;
        var_16 = 0;
        while ((s16)var_16 < 5) {
            temp_3 = iGpffffb474;
            var_2 = temp_3 & 3;
            if (((s8)temp_3 < 0) && (var_2 != 0)) {
                var_2 -= 4;
            }
            iGpffffb474 = temp_3 + 1;
            func_00201650(arg0, 15, (s16)var_2, var_f21, var_f20,
                          255, 255, 255, arg1);
            var_f21 += 126.0f;
            var_16 = (s64)((var_16 + 1) << 0x30) >> 0x30;
        }
        var_f20 += 126.0f;
        var_17 = (s64)((var_17 + 1) << 0x30) >> 0x30;
    }
    func_00201820(0);
    func_002019e0(arg0, 0.0f);
    {
        void (**base)(u32, u32);

        base = D_00887300;
        base[0](6, 0);
        base[0](1, 0);
    }
}
