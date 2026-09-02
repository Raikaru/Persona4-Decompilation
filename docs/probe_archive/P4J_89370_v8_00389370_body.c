/* residual: 16 first_diffs [450,458,459,478,485-498], normalized_diff 203; retail saves $s0(palette), $ra; tried: u8 **arg0, s32 color0/color1 computed before size0/size1, passed uncast to s64/s32 args; still mfc1/andi into $v1 then copy to $t2/$t3 vs retail direct $t2/$t3 for color conversion. */
void func_00389370(u8 **arg0)
{
    extern f32 D_00761470;
    extern f32 func_0044b610(f32);
    u16 *tick;
    s32 palette;
    u16 phase;
    f32 t;
    f32 value0;
    f32 q0;
    f32 q1;
    f32 size0_f;
    f32 size1_f;
    s32 size0;
    s32 size1;
    s32 color0;
    s32 color1;

    tick = (u16 *)((u8 *)arg0 + 0x68);
    palette = *(s32 *)(*arg0 + 0x1F2B0);

    *tick += 1;
    if (*tick >= 0x320) {
        *tick = 0;
    }

    phase = (u16)(*tick % 100);
    if (phase < 50) {
        t = (f32)phase;
        value0 = 1.0f - func_0044b610((D_00761470 * t) / 50.0f);
    } else {
        t = (f32)(phase - 50);
        value0 = func_0044b610((D_00761470 * t) / 50.0f);
    }

    if (value0 < 0.0f) {
        value0 = 0.0f;
    }

    q0 = (0.0f + 644.0f + 584.0f * value0) / 254.0f;
    q1 = (0.0f + 454.0f + 404.0f * value0) / 254.0f;

    size0_f = 127.0f * q0;
    size1_f = 127.0f * q1;

    color0 = (u16)(4096.0f * q0);
    color1 = (u16)(4096.0f * q1);

    size0 = (s32)size0_f;
    size1 = (s32)size1_f;

    func_0034f4a0(palette, 0, 320.0f - size0_f, 224.0f - size1_f, 0.0f,
                  0xFF, 0xFF, 0xFF, 0xFF, color0, color1,
                  0.0f, (s16)size0, (s16)size1);
}
