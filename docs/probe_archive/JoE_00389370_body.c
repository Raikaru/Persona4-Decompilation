// FUN_00389370 archive (wave Jo lane JoE, killed by provider rate limit mid-work; body is the live state at cutoff, MISMATCH nd203 728/720).
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

    size0 = (s32)size0_f;
    size1 = (s32)size1_f;

    func_0034f4a0(palette, 0, 320.0f - size0_f, 224.0f - size1_f, 0.0f,
                  0xFF, 0xFF, 0xFF, 0xFF,
                  (s64)(u16)(4096.0f * q0), (s32)(u16)(4096.0f * q1),
                  0.0f, (s16)size0, (s16)size1);
}
