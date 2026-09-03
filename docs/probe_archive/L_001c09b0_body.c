/* Lane L archive for func_001c09b0 @ 0x001c09b0.
 * Object: 1124B, window: 1168B, normalized_diff: 551,
 * differing words (reloc-masked): 209.
 * First differing offsets: 74, 78, 80, 82, 83, 84, 86, 87, 90, 91, 92, 93, 94, 95, 97, 98
 * (spCC MAC chain and surrounding prologue scheduling).
 * Levers tried: explicit-frame struct with spXX fields, polynomial sin
 * series copied from btlCamera.c (fGpffff8180 + fGpffff8054/8058/805c/8060/8108),
 * 0.0f + x + y*z / 0.0f + x - y*z patterns for adda/madd/msub,
 * block-scoped externs, s64 copy for frame.spD8 initialization,
 * func_0044b868 passed by value.
 * Notable residuals: the whole second half (scale/final vector/MAC chains)
 * is shifted and uses different register allocation; object is 44B shorter
 * than retail. The `0.5f * frame.sp40` factor for func_0044b868 is suspect,
 * as is the exact sp40-based fov source, but the bulk of the mismatch is
 * structural (frame layout/schedule and the polynomial chain order).
 */
// FUN_001C09B0
void func_001c09b0(u8 *arg0)
{
    extern u8 D_0060A0E0[];
    extern u8 D_0060A100[];
    extern void func_001bd560(f32 *arg0, f32 *arg1);
    extern void func_00194ff0(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3);
    extern void func_001bd780(void *arg0, void *arg1, void *arg2, void *arg3);
    extern f32 func_001ec2b0(f32 *arg0, f32 *arg1);
    extern f32 func_003dcc70(f32 *arg0, f32 *arg1, f32 *arg2);
    extern void func_003dcb40(s64 *arg0, s64 *arg1, s32 arg2, u8 *arg3);
    extern void func_003dc740(void *arg0, void *arg1, f32 arg2, s32 arg3);
    extern f32 func_0044b868(f32 arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 fGpffff815c;
    extern f32 fGpffff804c;
    extern f32 fGpffff8160;
    extern f32 fGpffff818c;
    extern f32 fGpffff8110;
    extern f32 fGpffff8180;
    extern f32 fGpffff8054;
    extern f32 fGpffff8058;
    extern f32 fGpffff805c;
    extern f32 fGpffff8060;
    extern f32 fGpffff8108;
    extern f32 fGpffff8118;

    struct {
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 sp4C;
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 sp5C;
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 sp6C;
        f32 sp70;
        f32 sp74;
        f32 sp78;
        f32 sp7C;
        f32 sp80;
        f32 sp84;
        f32 sp88;
        f32 sp8C;
        f32 sp90;
        f32 sp94;
        f32 sp98;
        f32 sp9C;
        f32 spA0;
        s32 spA4;
        u8 pad_A8[0x8];
        f32 spB0;
        f32 spB4;
        f32 spB8;
        f32 spBC;
        f32 spC0;
        f32 spC4;
        f32 spC8;
        f32 spCC;
        f32 spD0;
        f32 spD4;
        f32 spD8;
        f32 spDC;
        f32 spE0;
        f32 spE4;
        f32 spE8;
        f32 spEC;
    } frame;

    u8 *work;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 t;

    work = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_001bd560(&frame.sp40, (f32 *)(arg0 + 0x9C));
    func_00194ff0(work, (u8 *)&frame.spC8, NULL, NULL);
    frame.spCC = *(f32 *)(arg0 + 0x84) * *(f32 *)(work + 0x2C) +
                 fGpffff8118 * (*(f32 *)(arg0 + 0x8C) * *(f32 *)(work + 0x2C));
    *(s64 *)&frame.spD8 = *(s64 *)&frame.sp40;
    frame.spE0 = frame.sp48;
    frame.spDC = frame.spCC;
    func_001bd780(&frame.sp68, &frame.spD8, &frame.spC8, D_0060A0E0);
    temp_f0 = func_001ec2b0(&frame.sp4C, &frame.sp68);

    if (temp_f0 <= fGpffff815c) {
        t = fGpffff815c / temp_f0;
        func_003dcc70(&frame.sp4C, &frame.sp68, &frame.sp80);

        if (t <= 0.0f) {
            frame.spB0 = frame.sp4C;
            frame.spB4 = frame.sp50;
            frame.spB8 = frame.sp54;
            frame.spBC = frame.sp58;
        } else if (t >= 1.0f) {
            frame.spB0 = frame.sp68;
            frame.spB4 = frame.sp6C;
            frame.spB8 = frame.sp70;
            frame.spBC = frame.sp74;
        } else {
            temp_f0 = 1.0f - t;

            if (frame.spA4 == 0) {
                temp_f4 = temp_f0 * frame.spA0;
                temp_f3 = temp_f4 * temp_f4;
                temp_f0 = fGpffff8180 * temp_f3 + fGpffff8054;
                temp_f0 = temp_f3 * temp_f0 + fGpffff8058;
                temp_f0 = temp_f3 * temp_f0 + fGpffff805c;
                temp_f0 = temp_f3 * temp_f0 + fGpffff8060;
                temp_f1 = temp_f3 * temp_f0 + fGpffff8108;
                temp_f0 = temp_f3 * temp_f4;
                temp_f0 = temp_f0 * temp_f1 + temp_f4;

                temp_f4 = t * frame.spA0;
                temp_f3 = temp_f4 * temp_f4;
                temp_f2 = fGpffff8180 * temp_f3 + fGpffff8054;
                temp_f2 = temp_f3 * temp_f2 + fGpffff8058;
                temp_f2 = temp_f3 * temp_f2 + fGpffff805c;
                temp_f2 = temp_f3 * temp_f2 + fGpffff8060;
                temp_f1 = temp_f3 * temp_f2 + fGpffff8108;
                temp_f2 = temp_f3 * temp_f4;
                t = temp_f2 * temp_f1 + temp_f4;
            }

            frame.spB0 = 0.0f + frame.sp80 * temp_f0 + frame.sp90 * t;
            frame.spB4 = 0.0f + frame.sp84 * temp_f0 + frame.sp94 * t;
            frame.spB8 = 0.0f + frame.sp88 * temp_f0 + frame.sp98 * t;
            frame.spBC = frame.sp9C * t + frame.sp8C * temp_f0;
        }

        func_003dcb40((s64 *)&frame.spD8, (s64 *)D_0060A100, 1, (u8 *)&frame.spB0);
        frame.spD8 = frame.spD8 + frame.spC8;
        frame.spDC = frame.spDC + frame.spCC;
        frame.spE0 = frame.spE0 + frame.spD0;
        func_001bd780(&frame.sp68, &frame.spD8, &frame.spC8, D_0060A0E0);
    } else if (temp_f0 < fGpffff804c) {
        func_003dc740(&frame.sp68, D_0060A0E0, fGpffff8160, 2);
    }

    func_003dcb40((s64 *)&frame.spD8, (s64 *)D_0060A100, 1, (u8 *)&frame.sp68);

    t = 375.0f / func_0044b868(fGpffff8110 * (0.5f * frame.sp40));
    frame.spD8 = frame.spD8 * t;
    frame.spDC = frame.spDC * t;
    frame.spE0 = frame.spE0 * t;

    temp_f0 = func_0044b868(fGpffff8110 * (0.5f * frame.sp40));
    t = t * temp_f0 * 0.21875f;

    frame.spE8 = frame.spD8;
    frame.spEC = frame.spE0;
    func_003e41e0(&frame.spE8, &frame.spE8);

    frame.spC8 = 0.0f + frame.spC8 + frame.spEC * t;
    frame.spD0 = 0.0f + frame.spD0 - frame.spE8 * t;
    frame.sp5C = frame.spC8 + frame.spD8;
    frame.sp60 = frame.spCC + frame.spDC;
    frame.sp64 = frame.spD0 + frame.spE0;

    if (frame.sp60 < 25.0f) {
        frame.sp60 = 25.0f;
    }

    func_001bac20(arg0, &frame.sp40, &frame.sp5C, 1);
    func_001bbef0(arg0, fGpffff818c);
}
