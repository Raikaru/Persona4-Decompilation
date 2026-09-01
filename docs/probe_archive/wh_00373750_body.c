void func_00373750(s32 arg0, s32 arg1, f32 *arg2) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;

    if (arg2 == NULL) {
        func_0046d730(&D_0064E9C0, 0x38C);
    }
    switch (arg1) {
    case 3:
    case 4:
        f3 = (f32)(arg1 - 1);
        f1 = 0.5f;
        f0 = (f32)arg0;
        *arg2 = 320.0f + 100.0f * (f0 - f1 * f3);
        f1 = 120.0f;
        f0 = 224.0f;
        f2 = 0.0f;
        arg2[1] = f0 + f2 * f1;
        return;
    case 5:
        if (arg0 < 3) {
            f2 = 100.0f;
            f0 = (f32)arg0;
            f1 = 1.0f;
            f1 = f0 - f1;
            *arg2 = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            f3 = 0.0f;
            arg2[1] = f0 + f3 + f2 * f1;
            return;
        }
        f3 = (f32)(arg0 - 3);
        f4 = 0.5f;
        f3 = f3 - f4;
        f1 = 100.0f;
        f0 = 320.0f;
        f2 = 0.0f;
        *arg2 = f0 + f2 + f1 * f3;
        f1 = 120.0f;
        f0 = 224.0f;
        arg2[1] = f0 + f2 * f4;
        return;
    case 6:
        if (arg0 < 3) {
            f2 = 100.0f;
            f0 = (f32)arg0;
            f1 = 1.0f;
            f1 = f0 - f1;
            *arg2 = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            f3 = 0.0f;
            arg2[1] = f0 + f3 + f2 * f1;
            return;
        }
        f3 = (f32)(arg0 - 3);
        f1 = 1.0f;
        f2 = f3 - f1;
        f1 = 100.0f;
        f0 = 320.0f;
        f4 = 0.0f;
        *arg2 = f0 + f4 + f1 * f2;
        f1 = 120.0f;
        f0 = 224.0f;
        arg2[1] = f0 + f4 * f3;
        return;
    case 7:
        if (arg0 < 4) {
            f2 = 100.0f;
            f0 = (f32)arg0;
            f1 = 1.5f;
            f1 = f0 - f1;
            *arg2 = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            f3 = 0.0f;
            arg2[1] = f0 + f3 + f2 * f1;
            return;
        }
        f3 = (f32)(arg0 - 4);
        f1 = 1.0f;
        f2 = f3 - f1;
        f1 = 100.0f;
        f0 = 320.0f;
        f4 = 0.0f;
        *arg2 = f0 + f4 + f1 * f2;
        f1 = 120.0f;
        f0 = 224.0f;
        arg2[1] = f0 + f4 * f3;
        return;
    case 8:
        if (arg0 < 4) {
            f2 = 100.0f;
            f0 = (f32)arg0;
            f1 = 1.5f;
            f1 = f0 - f1;
            *arg2 = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            f3 = 0.0f;
            arg2[1] = f0 + f3 + f2 * f1;
            return;
        }
        f3 = (f32)(arg0 - 4);
        f1 = 1.5f;
        f2 = f3 - f1;
        f1 = 100.0f;
        f0 = 320.0f;
        f4 = 0.0f;
        *arg2 = f0 + f4 + f1 * f2;
        f1 = 120.0f;
        f0 = 224.0f;
        arg2[1] = f0 + f4 * f3;
        return;
    default:
        func_0046d730(&D_0064E9C0, 0x3BF);
        return;
    }
}
