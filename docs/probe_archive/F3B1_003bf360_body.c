/* object 100B/window 112B, normalized_diff 43; differing word offsets 44,48,52,56,60,64,68,72,76,80,84,88,92,96,100 (byte residual starts 44,46,47,48,50,51); missing retail reload at +0x2C causes tail shift. Corrected declarations: block-scope extern u8 D_0070AF70[] and s32 func_003e3370(u8 *,u8 *). Ruled out: struct-alias locals, explicit reload temporaries, s32* versus u8* output-pointer signatures, optimization_level 1, opt_common_subs/opt_propagation off, and default optimization; b210 keeps the first increment's value instead of retail's second lw. */
u8 *func_003bf360(u8 *arg0, s32 *arg1) {
    extern u8 D_0070AF70[];
    extern s32 func_003e3370(u8 *desc, u8 *arg1);

    *arg1 += 0xC;
    *arg1 += 0x1C;
    *arg1 += func_003e3370(D_0070AF70, arg0) + 0xC;
    return arg0;
}
