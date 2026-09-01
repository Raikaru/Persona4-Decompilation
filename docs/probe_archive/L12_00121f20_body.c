/* Closest rejected reconstruction for FUN_00121F20.
 * Probe: object/window near-match with normalized differences confined to the
 * initial scalar setup (retail's accumulator-style adda/msub sequence versus
 * MWCC's plain-C setup). Loop geometry, calls, point generation, and quad
 * copies match; restored to INCLUDE_ASM because nd != 0.
 */
void func_00121f20(void)
{
    extern f32 func_0044b7b0(f32 fparg0);
    Code1Point4 points[0x25];
    Code1Point2 quad[4];
    Code1Color4 color[4];
    u8 *temp_6;
    Code1Point4 *point;
    f32 result;
    f32 angle;
    f32 scale;
    f32 x;
    f32 sine;
    f32 cosine;
    s32 i;

    temp_6 = (u8 *)iGpffffb1cc;
    if (temp_6 != NULL) {
        color[0].c3 = 0xFF;
        color[0].c0 = iGpffffb1d8;
        color[0].c1 = iGpffffb1d4;
        color[0].c2 = iGpffffb1d0;
        color[3] = color[0];
        color[2] = color[3];
        color[1] = color[2];
        result = func_0044b7b0(
            (fGpffff84a4 * (f32)*(s32 *)(temp_6 + 0xC)) /
            (f32)*(s32 *)(temp_6 + 8));
        scale = 600.0f - (600.0f * result);
        angle = 0.0f;
        angle += 600.0f;
        i = 0;
        while (i < 0x25) {
            x = fGpffff8478 * angle;
            sine = func_0044b610(x);
            cosine = func_0044b7b0(x);
            point = &points[i];
            point->p0 = ((scale * sine * 1066.0f) / 1000.0f) + 320.0f;
            point->p1 = (scale * cosine) + 224.0f;
            point->p2 = ((sine * 600.0f * 1066.0f) / 1000.0f) + 320.0f;
            point->p3 = (cosine * 600.0f) + 224.0f;
            angle += 10.0f;
            i++;
        }
        i = 0;
        while (i < 0x24) {
            point = &points[i];
            quad[0] = *(Code1Point2 *)point;
            quad[1] = *(Code1Point2 *)((u8 *)point + 8);
            quad[2] = *(Code1Point2 *)(point + 1);
            quad[3] = *(Code1Point2 *)((u8 *)(point + 1) + 8);
            func_0045dfd0(color, quad, 0.0f, 4, 4, 1);
            i++;
        }
    }
}
