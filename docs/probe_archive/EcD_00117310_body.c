/* object 388B / window 400B / normalized_diff 4.
   Classification: genuine independent prologue-order floor (fifth member).
   Residual is four mutually independent PROLOGUE words at 0x30,0x34,0x38,0x3c:
     emitted  move s0,t0 ; sw a1 ; move s4,a2 ; move s3,a3
     retail   sw a1 ; move s4,a2 ; move s3,a3 ; move s0,t0
   The exact retail saved-value mapping is packed(a1)->stack, n(a2)->s4,
   id(a3)->s3, mode(t0)->s0. The parameter list already gives the
   corresponding values; MWCC b210 still parks t0 first, so no source order
   or schedule pragma can reorder these independent transfers.
   Already exact: the guard branch bnez s3, and caller func_00116610
   stays MATCH.
   Levers that got here: I64 first parameter, arg3 u32 / arg4 s32,
   declaration initializers for packed/n/id, measured opt_loop_invariants.
   Additional assignment-rule probes: mode local after b2/b1, scoped
   opt_propagation off, and preloaded b2/b1; none changed the four words.
   SUPERSEDED: the earlier first-use explanation for this prologue order. */
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
