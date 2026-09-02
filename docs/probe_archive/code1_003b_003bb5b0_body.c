/* Probe body for func_003bb5b0 (0x003bb5b0) in src/promoted/code1_003b.c
 * lverify: object 1264B / window 1248B / normalized_diff 975
 * levers tried: #pragma schedule on, #pragma no_branch_likely on, points_base hoisted, += accumulation,
 * explicit u32->f32 conversion, smoothstep ordered -1.0 + (t*-2.0)*t + t*4.0.
 * Not a match; archived after several iterations.
 */
u8 *func_003bb5b0(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3, f32 fparg0)
{
    s32 type;
    s32 max;
    s32 step;
    s32 sub;
    f32 frac;
    u8 *points_base;
    f32 *p0;
    f32 *p1;
    f32 *p2;
    f32 *p3;
    f32 *out0;
    f32 *out1;
    f32 b0;
    f32 b1;
    f32 b2;
    f32 b3;
    s32 pair[2];
    u32 u;
    f32 conv;

    points_base = arg0 + 0x38;
    max = *(s32 *)(arg0 + 8);
    type = *(s32 *)(arg0 + 0xC);

    if (fparg0 < 0.0f) {
        fparg0 = -fparg0;
    }

    if ((type == 2) && (fparg0 > 1.0f)) {
        if (fparg0 < 2147483648.0f) {
            u = (s32)fparg0;
        } else {
            u = ((s32)(fparg0 - 2147483648.0f)) | 0x80000000;
        }
        if ((s32)u < 0) {
            conv = (f32)((u >> 1) | (u & 1));
            conv = conv + conv;
            fparg0 = fparg0 - conv;
        } else {
            fparg0 = fparg0 - (f32)(s32)u;
        }
    }

    if (arg1 == 0xB) {
        if (fparg0 <= 0.5f) {
            fparg0 = fparg0 * (fparg0 + fparg0);
        } else {
            fparg0 = -1.0f + (fparg0 * -2.0f) * fparg0 + fparg0 * 4.0f;
        }
    } else if (arg1 != 0xA) {
        pair[0] = 0x102;
        pair[1] = func_003df590(1);
        func_003df4d0(pair);
        return NULL;
    }

    if (fparg0 == 1.0f) {
        step = max - 4;
        sub = 0xFF;
        frac = 1.0f;
    } else {
        fparg0 = (f32)(max - 3) * fparg0;
        step = (s32)fparg0;
        fparg0 = (fparg0 - (f32)step) * 256.0f;
        sub = (s32)fparg0;
        frac = fparg0 - (f32)sub;
    }

    p0 = (f32 *)(points_base + step * 0xC);
    p1 = p0 + 3;
    p2 = p0 + 6;
    p3 = p0 + 9;
    out0 = (f32 *)arg2;

    b0 = *(f32 *)(iGpffffb628 + sub);
    b0 = b0 + frac * (((f32 *)(iGpffffb628 + sub))[1] - b0);

    b1 = *(f32 *)(iGpffffb624 + sub);
    b1 = b1 + frac * (((f32 *)(iGpffffb624 + sub))[1] - b1);

    b2 = *(f32 *)(iGpffffb620 + sub);
    b2 = b2 + frac * (((f32 *)(iGpffffb620 + sub))[1] - b2);

    b3 = *(f32 *)(iGpffffb61c + sub);
    b3 = b3 + frac * (((f32 *)(iGpffffb61c + sub))[1] - b3);

    out0[0] = p0[0] * b0;
    out0[1] = p0[1] * b0;
    out0[2] = p0[2] * b0;

    out0[0] += p1[0] * b1;
    out0[1] += p1[1] * b1;
    out0[2] += p1[2] * b1;

    out0[0] += p2[0] * b2;
    out0[1] += p2[1] * b2;
    out0[2] += p2[2] * b2;

    out0[0] += p3[0] * b3;
    out0[1] += p3[1] * b3;
    out0[2] += p3[2] * b3;

    if (arg3 != NULL) {
        out1 = (f32 *)arg3;

        b0 = *(f32 *)(iGpffffb638 + sub);
        b0 = b0 + frac * (((f32 *)(iGpffffb638 + sub))[1] - b0);

        b1 = *(f32 *)(iGpffffb634 + sub);
        b1 = b1 + frac * (((f32 *)(iGpffffb634 + sub))[1] - b1);

        b2 = *(f32 *)(iGpffffb630 + sub);
        b2 = b2 + frac * (((f32 *)(iGpffffb630 + sub))[1] - b2);

        b3 = *(f32 *)(iGpffffb62c + sub);
        b3 = b3 + frac * (((f32 *)(iGpffffb62c + sub))[1] - b3);

        out1[0] = p0[0] * b0;
        out1[1] = p0[1] * b0;
        out1[2] = p0[2] * b0;

        out1[0] += p1[0] * b1;
        out1[1] += p1[1] * b1;
        out1[2] += p1[2] * b1;

        out1[0] += p2[0] * b2;
        out1[1] += p2[1] * b2;
        out1[2] += p2[2] * b2;

        out1[0] += p3[0] * b3;
        out1[1] += p3[1] * b3;
        out1[2] += p3[2] * b3;

        frac = func_003e4030(arg3, arg3);
        if (frac == 0.0f) {
            out1[0] = 0.0f;
            out1[1] = 1.0f;
            out1[2] = 0.0f;
        }
    }

    return arg2;
}
