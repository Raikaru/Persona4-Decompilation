/* object 388B / window 400B / normalized_diff 4.
   Residual is four PROLOGUE words at 0x30,0x34,0x38,0x3c only:
     emitted  move s0,t0 ; sw a1 ; move s4,a2 ; move s3,a3
     retail   sw a1 ; move s4,a2 ; move s3,a3 ; move s0,t0
   i.e. retail spills the stack argument first and defers the s0 copy to
   last; prologue spill order follows first-use order, so the value that
   becomes s0 must not be read until later in retail's source.
   Already exact: the guard branch bnez s3, and caller func_00116610
   stays MATCH.
   Levers that got here: I64 first parameter, arg3 u32 / arg4 s32 with
   direct arg4 mode use (the unsigned arg3 is what fixed the branch),
   declaration initializers for packed/n/id, measured opt_loop_invariants.
   Ruled out: late/mid/top mode declaration, nested mode scope, direct
   formal mode, zero-dependency expressions through packed/n/id,
   signed/unsigned parameter variants, I64 struct vs scalar forms,
   opt_propagation off, schedule off. */
void func_00117310(I64 arg0, f32 fparg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4)
{
    u32 packed = arg1;
    f32 f;
    u32 n = (u32)arg2;
    s32 id = arg3;
    u8 b2;
    u8 b1;
    u32 rem;
    f32 y;

    y = *((f32 *)&arg0 + 1);
    if (id == 0) {
        func_0046d730(D_005E4868, 0x424);
    }
    if (arg4 != 0) {
        f = *(f32 *)&arg0;
        rem = n;
        while (rem >= 10U) {
            f += 16.0f;
            rem /= 10U;
        }
    } else if (n < 10U) {
        f = 8.0f + *(f32 *)&arg0;
    } else {
        f = 16.0f + *(f32 *)&arg0;
    }
    b2 = *((u8 *)&packed + 2);
    b1 = *((u8 *)&packed + 1);
    arg4 = 0xFF;
    arg4 -= *((u8 *)&packed + 3);
    do {
        func_0046d4c0(0, id, (n % 10U) + 9,
                      f, y, (u8)arg4, *((u8 *)&packed), b1, b2,
                      fparg0, 0);
        n /= 10U;
        f -= 16.0f;
        rem = n;
    } while (n != 0);
}
