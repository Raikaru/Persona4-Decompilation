#pragma push
/* measured: opt_propagation off preserves the two color word stores and the
   Quad4 copy that retail emits; without it the optimizer sinks the color and
   folds the copy. */
#pragma opt_propagation off
// FUN_002A4D10
s32 func_002a4d10(s32 arg0) {
    u8 *work;
    s32 v;
    f32 t;
    f32 sp54;
    f32 sp58;
    f32 sp5C;
    Quad4 sp30;
    Quad4 sp40;

    work = func_00452560();
    v = *(s32 *)(work + 0x568);
    if (v > 0x14) {
        v = 0x14;
    }
    t = func_0044b7b0((D_00761184 * (f32)v) / 20.0f);
    sp58 = iGpffffa818;
    sp5C = sp58;
    sp30 = D_0063ED50;
    sp30.b = (s32)(178.0f * (1.0f - t));
    sp30.d = (s32)(448.0f * t);
    sp40 = sp30;
    func_0045d6e0(&sp5C, &sp40, 0.0f, 1);

    v = *(s32 *)(work + 0x568);
    if (v >= 6) {
        v -= 5;
        if (v > 0xf) {
            v = 0xf;
        }
        t = func_0044b7b0((D_00761184 * (f32)v) / 15.0f);
        sp54 = iGpffffa81c;
        sp5C = sp54;
        sp30 = D_0063ED60;
        sp30.b = (s32)(178.0f - (94.0f * t) / 2.0f);
        sp30.d = (s32)(94.0f * t);
        sp40 = sp30;
        func_0045d6e0(&sp5C, &sp40, 0.0f, 1);
    }

    v = *(s32 *)(work + 0x568) + 1;
    *(s32 *)(work + 0x568) = v;
    if (v < 0x14) {
        return 0;
    }
    *(s32 *)(work + 0x568) = 0;
    return 1;
}
#pragma pop
