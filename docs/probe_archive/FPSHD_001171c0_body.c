/* measured: func_001171c0 candidate object 328B / retail window 336B / normalized_diff 11 under the current translation unit. Residuals are the arg2 narrowing and branch register choices in the prologue plus dependent loop argument registers; reverted to INCLUDE_ASM because this is not byte-exact. */
void func_001171c0(s64 arg0, f32 fparg0, s32 arg1, u8 arg2, s32 arg3)
{
    s64 sp70;
    s32 packed;
    f32 farg;
    f32 f;
    s32 n;
    s32 id;
    u8 b2;
    u8 b1;
    s32 inv;
    s32 rem;
    f32 y;

    sp70 = arg0;
    farg = fparg0;
    packed = arg1;
    id = arg3;
    y = *((f32 *)&sp70 + 1);
    n = arg2;
    if (id == 0) {
        func_0046d730(D_005E4868, 0x400);
    }
    rem = n & 0xFF;
    if (rem < 10) {
        f = 11.0f + *((f32 *)&sp70 + 0);
    } else {
        f = 22.0f + *((f32 *)&sp70 + 0);
    }
    b2 = *((u8 *)&packed + 2);
    b1 = *((u8 *)&packed + 1);
    inv = 0xFF;
    inv -= *((u8 *)&packed + 3);
    do {
        func_0046d4c0(0, id, (rem % 10) + 0x1D, f, y, inv,
                      shdPackedLow(&packed), b1, b2, farg, 0);
        n = ((u32)(n & 0xFF) / 10U) & 0xFF;
        f -= 22.0f;
        rem = n;
    } while (n > 0);
}
