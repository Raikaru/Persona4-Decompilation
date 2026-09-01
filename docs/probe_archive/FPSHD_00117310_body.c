/* measured: func_00117310 candidate object 388B / retail window 400B / normalized_diff 49 under the current translation unit. Residuals are fifth-argument/arg2/arg3 saved-register ordering in the prologue plus the mode preheader; reverted to INCLUDE_ASM because this is not byte-exact. */
void func_00117310(s64 arg0, f32 fparg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s64 sp70;
    s32 packed;
    f32 farg;
    f32 f;
    u32 n;
    u32 id;
    s32 mode;
    u8 b2;
    u8 b1;
    u32 rem;
    f32 y;

    sp70 = arg0;
    farg = fparg0;
    packed = arg1;
    n = arg2;
    id = arg3;
    mode = arg4;
    y = *((f32 *)&sp70 + 1);
    if (id == 0) {
        func_0046d730(D_005E4868, 0x424);
    }
    if (mode != 0) {
        f = *(f32 *)&sp70;
        rem = n;
        while (rem >= 10U) {
            f += 16.0f;
            rem = rem / 10U;
        }
    } else if (n < 10U) {
        f = 8.0f + *(f32 *)&sp70;
    } else {
        f = 16.0f + *(f32 *)&sp70;
    }
    b2 = *((u8 *)&packed + 2);
    b1 = *((u8 *)&packed + 1);
    mode = 0xFF;
    mode -= *((u8 *)&packed + 3);
    do {
        func_0046d4c0(0, id, (n % 10U) + 9,
                      f, y, (u8)mode, *((u8 *)&packed), b1, b2,
                      farg, 0);
        n = n / 10U;
        f -= 16.0f;
        rem = n;
    } while (n != 0);
}
