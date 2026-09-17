/* func_0027cae0 floor (measured 2026-09-17, source-repo): probe 10w bare, fnalign 465/465/11 (+34 reloc), emitted 1860B/window 1872B (99.4%% exact count). Four sweeps bare wins. Residual rotation + inner-switch order. See src/promoted/itfMsgProcedure_Window.c guard. */
s32 func_0027cae0(MsgProcWindowEntry *arg)
{
    s32 ret;
    s32 v0;
    s32 v1;
    float f;
    float g;
    u8 *tmp;

    ret = 0;
    arg->field10++;
    switch (arg->field4) {
    case 0:
        if (arg->field10 < 4) {
            func_0027d800(0x23, 0x128, 0xFFA107, 0xFF, 0, 0, 0.0f, -4.7f, 1.0f, 1.0f, D_00796430);
            func_0027d800(0x25, 0x152, 0x423C2B, 0xFF, 0, 0, 0.0f, 0.0f, 1.0f, 1.0f, D_00796490);
        } else if (arg->field10 < 7) {
            f = (float)(arg->field10 - 3) / 3.0f;
            func_0027d800((s32)(f * 2.0f + 35.0f), (s32)(f * 42.0f + 296.0f), 0xFFA107, 0xFF, 0, 0, 0.0f, -4.7f * (1.0f - f), 1.0f, 1.0f, D_00796430);
            func_0027d800(0x25, 0x152, 0x423C2B, 0xFF, 0, 0, 0.0f, 0.0f, 1.0f, 1.0f, D_00796490);
        } else if (arg->field10 < 12) {
            f = func_0044b7b0(iGpffff8094 * (float)(arg->field10 - 6) / 5.0f);
            func_0027d800((s32)(f * 200.0f + 37.0f), (s32)(f * 200.0f + 338.0f), 0x423C2B, 0xFF, 0, 0, 0.0f, f * 10.0f, 1.0f, 1.0f, D_00796490);
        }
        if (arg->field10 < 11) {
            break;
        }
        ret = 1;
        break;
    case 1:
    case 2:
    case 3:
        switch (arg->field4) {
        case 3:
            v0 = 0x76;
            v1 = 0xB;
            break;
        case 2:
            v0 = 0x51;
            v1 = 0xC;
            break;
        case 1:
            v0 = 0x45;
            v1 = 0xD;
            break;
        default:
            break;
        }
        f = func_0044b7b0(iGpffff8094 * (float)arg->field10 / 5.0f);
        func_0025ecd0(0.0f, (float)v0 * f + 123.0f, 0.0f, 0xFFFFFF, 0xD8, v1, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, 1.0f, 1.0f - f, D_00796490);
        if (arg->field10 < 5) {
            break;
        }
        func_0027f6a0();
        ret = 1;
        break;
    case 4:
        if (arg == 0) {
            func_0046d730(D_0063BFC0, 0xCC);
        }
        tmp = func_00460990();
        *(void **)(tmp + 8) = (void *)func_0027bf30;
        *(MsgProcWindowEntry **)(tmp + 0x10) = arg;
        func_00460ac0(D_00796490, tmp);
        if (arg->field10 < 20) {
            break;
        }
        func_00283360();
        ret = 1;
        break;
    case 5:
        f = func_0044b7b0(iGpffff8094 * (float)arg->field10 / 7.0f);
        if (arg->field10 < 8) {
            g = 1.0f - f;
            func_0027d620((s32)(f * 202.0f + 70.0f), (s32)(f * 27.0f + 27.0f), (s32)(g * 394.0f + 10.0f), (s32)(g * 45.0f + 10.0f), 0, 0xB2, 0, 0, D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
        }
        g = (float)arg->field10 / 4.0f;
        if (arg->field10 < 5) {
            func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f - g, 1.0f - iGpffff8198 * g, D_00796490);
        }
        if (arg->field10 < 7) {
            break;
        }
        ret = 1;
        break;
    case 6:
        f = func_0044b7b0(iGpffff8094 * (float)arg->field10 / 10.0f);
        g = (1.0f - f) * 255.0f;
        func_0025ecd0(592.0f, 394.0f, 0.0f, 0xFFA107, (u8)g, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, f * 360.0f + 180.0f, 1.0f, 1.0f, D_00796490);
        if (arg->field10 < 10) {
            break;
        }
        ret = 1;
        break;
    default:
        break;
    }
    return ret;
}
