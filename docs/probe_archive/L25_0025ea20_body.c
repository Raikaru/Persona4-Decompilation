/* MATCH: plain `(u16)(4096.0f * farg4)` and `(u16)(4096.0f * farg5)` casts reproduce both compiler-generated float-to-unsigned conversion paths; object 484B/window 496B, nd 0. Retail site 1 sequence: `lui 0x4580; mtc1; mul.s; lui 0x4F00; mtc1; c.ole.s`, then low `cvt.w.s; mfc1; andi` or high `sub.s; cvt.w.s; mfc1; lui 0x8000; or; andi; sh`. Site 2 repeats the same sequence. The `or` is after `mfc1`, not feeding `mtc1`; the 4096.0f `mul.s` is genuine scaling. */
s32 func_0025ea20(f32 farg0, f32 farg1, f32 farg2,
                  s32 arg0, s32 arg1, s32 arg2, void *arg3,
                  s32 arg4, s32 arg5, s32 arg6,
                  f32 farg3, f32 farg4, f32 farg5) {
    u8 *temp_2;

    temp_2 = func_0046d200((u32)arg3, arg2);
    *(f32 *)(temp_2 + 8) = farg0;
    *(f32 *)(temp_2 + 0xC) = farg1;
    *(f32 *)(temp_2 + 0x24) = farg2;
    *(s8 *)(temp_2 + 0x11) = (s8)(0xFF - (arg1 & 0xFF));
    *(s8 *)(temp_2 + 0x28) = (s8)((u32)arg0 >> 0x10);
    *(s8 *)(temp_2 + 0x29) = (s8)((u32)arg0 >> 8);
    *(u8 *)(temp_2 + 0x2A) = (u8)arg0;
    *(s16 *)(temp_2 + 0x1C) = (s16)arg5;
    *(s16 *)(temp_2 + 0x1E) = (s16)arg6;
    *(f32 *)(temp_2 + 0x18) = farg3;
    *(u16 *)(temp_2 + 0x20) = (u16)(4096.0f * farg4);
    *(u16 *)(temp_2 + 0x22) = (u16)(4096.0f * farg5);
    if ((*(u16 *)(temp_2 + 0x20) != 0) &&
        (*(u16 *)(temp_2 + 0x22) != 0)) {
        func_0046b380(temp_2, arg4);
    }
    func_0046d280(temp_2);
    return 0;
}
