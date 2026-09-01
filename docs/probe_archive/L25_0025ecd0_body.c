/* MATCH: plain `(u16)(4096.0f * farg4)` and `(u16)(4096.0f * farg5)` casts reproduce both compiler-generated float-to-unsigned conversion paths; object 588B/window 592B, nd 0. Retail site 1 sequence: `lui 0x4580; mtc1; mul.s; lui 0x4F00; mtc1; c.ole.s`, then low `cvt.w.s; mfc1; andi` or high `sub.s; cvt.w.s; mfc1; lui 0x8000; or; andi; sh`. Site 2 repeats the same sequence. The `or` is after `mfc1`, not feeding `mtc1`; the 4096.0f `mul.s` is genuine scaling. */
s32 func_0025ecd0(f32 farg0, f32 farg1, f32 farg2,
                  s32 arg0, s32 arg1, s32 arg2, void *arg3,
                  s32 arg4, s16 arg5, s16 arg6,
                  f32 farg3, f32 farg4, f32 farg5, void *arg7) {
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = func_00460990();
    temp_2 = func_0046d200((u32)arg3, arg2);
    *(f32 *)(temp_2 + 8) = farg0;
    *(f32 *)(temp_2 + 0xC) = farg1;
    *(f32 *)(temp_2 + 0x24) = farg2;
    *(s8 *)(temp_2 + 0x11) = (s8)(0xFF - (arg1 & 0xFF));
    *(s8 *)(temp_2 + 0x28) = (s8)((u32)arg0 >> 0x10);
    *(s8 *)(temp_2 + 0x29) = (s8)((u32)arg0 >> 8);
    *(u8 *)(temp_2 + 0x2A) = arg0;
    *(s16 *)(temp_2 + 0x1C) = arg5;
    *(s16 *)(temp_2 + 0x1E) = arg6;
    *(f32 *)(temp_2 + 0x18) = farg3;
    *(u16 *)(temp_2 + 0x20) = (u16)(4096.0f * farg4);
    *(u16 *)(temp_2 + 0x22) = (u16)(4096.0f * farg5);
    if (*(u16 *)(temp_2 + 0x20) == 0) {
        goto cleanup;
    }
    if (*(u16 *)(temp_2 + 0x22) == 0) {
        goto cleanup;
    }
    if (arg4 != 1) {
        goto callback_2;
    }
    *(void **)(temp_16 + 8) = (void *)func_0025ec10;
    *(u8 **)(temp_16 + 0x10) = temp_2;
    goto callback_call;
callback_2:
    *(void **)(temp_16 + 8) = (void *)func_0025ec50;
    *(u8 **)(temp_16 + 0x10) = temp_2;
callback_call:
    func_00460ac0(arg7, temp_16);
    goto done;
cleanup:
    func_0046d280(temp_2);
done:
    return 0;
}
