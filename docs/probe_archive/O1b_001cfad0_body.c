/* object 1024B / window 1024B / normalized_diff 460; differing offsets:
 * 217,224,228,232,236,240,248,252,256,258,260,261,262,264,268,272,276,280,
 * 284,288,292,296,308,320,324,328,332,336,340,344,348,352,360,364,368,372,
 * 380,384,388,392,396,400,404,408,412,416,420,424,428,432,436,440,444,448,
 * 452,456,460,464,468,472,476,480,484,488,492,496,500,504,508,512,516,520,
 * 524,528,532,536,540,548,552,556,560,564,568,572,576,580,584,588,592,596,
 * 600,604,608,612,616,620,624,628,632,636,640,644,648,652,656,660,664,668,
 * 672,676,680,684,688,692,696,700,704,708,712,716,720,724,728,732,736,740,
 * 744,748,752,756,760,764,768,772,776,780,784,788,792,796,800,804,808,812,
 * 816,820,824,828,832,836,840,844,848,852,856,860,864,868,872,876,880,884,
 * 888,892,896,900,904,908,912,916,920,924,928,932,936,940,944,948,952,956,
 * 960,964,968,972,976,980,984,988,992,996,1000,1004,1008,1012,1016
 * (160 differing words reloc-masked)
 * levers tried: COP1 chain idiom 0.0f + spD4 +/- fGpffff80fc * (s0[0x8C] * s0[0x2C]);
 *   named product local (hoisted branch, worsened diff); stack frame struct with
 *   fields at observed sp offsets; no opt_propagation/schedule pragmas.
 * residual: instruction selection/register allocation differs through entire
 *   function; first big divergence is 200.0f scaling (reg f1 vs f2, temp
 *   assignment order), then branch/schedule differences around func_00231d70
 *   switch and rotation/scaling blocks.
 */
void func_001cfad0(u8 *arg0, f32 arg1, f32 arg2)
{
    struct {
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
        u8 pad_to_90[8];
        f32 sp90;
        f32 sp94;
        f32 sp98;
        f32 sp9C;
        u8 pad_to_D0[0x30];
        f32 spD0;
        f32 spD4;
        f32 spD8;
        u8 pad_to_E0[4];
        f32 spE0;
        f32 spE4;
        f32 spE8;
        u8 pad_to_F0[4];
        f32 spF0;
        f32 spF4;
        f32 spF8;
    } frame;
    u8 *s0;
    s32 temp;
    f32 var_f1;
    f32 var_f20;
    f32 scale1;
    f32 scale2;
    extern void func_001959d0(u8 *arg0, f32 *arg1);

    s0 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp = func_00232710(*(s32 *)(s0 + 0xA64), 0x100000);
    func_001959d0(s0, &frame.spD0);
    if (temp == 0) {
        frame.spD4 = 0.0f + frame.spD4 + fGpffff80fc *
                     ((*(f32 *)(s0 + 0x8C)) * (*(f32 *)(s0 + 0x2C)));
    } else {
        frame.spD4 = 0.0f + frame.spD4 - fGpffff80fc *
                     ((*(f32 *)(s0 + 0x8C)) * (*(f32 *)(s0 + 0x2C)));
    }
    func_003dcb40((s64 *)&frame.spE0, (s64 *)D_0060A0F0, 1, s0 + 0x1C);
    frame.spF0 = 200.0f * frame.spE0;
    frame.spF4 = 200.0f * frame.spE4;
    frame.spF8 = 200.0f * frame.spE8;
    frame.spE0 = (frame.spD0 + frame.spF0) - frame.spD0;
    frame.spE4 = ((frame.spD4 + frame.spF4) + 55.0f) - frame.spD4;
    frame.spE8 = (frame.spD8 + frame.spF8) - frame.spD8;
    func_003e40b0(&frame.spE0, &frame.spE0);
    var_f1 = *(f32 *)(s0 + 0x90) * *(f32 *)(s0 + 0x2C);
    if (var_f1 < 75.0f) {
        var_f1 = 75.0f;
    }
    scale1 = var_f1 * arg1;
    scale2 = var_f1 * arg2;
    temp = func_00231d70(2);
    if (temp == 1) {
        var_f20 = -30.0f;
    } else if (temp == 0) {
        var_f20 = 30.0f;
    } else {
        var_f20 = -30.0f;
    }
    func_001c_rotate(&frame.sp90, D_0060A0E0, -0.5f * var_f20, 0);
    func_003e4320(&frame.spF0, &frame.spE0, &frame.sp90);
    scale1 = scale1 / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    frame.spF0 = frame.spF0 * scale1;
    frame.spF4 = frame.spF4 * scale1;
    frame.spF8 = frame.spF8 * scale1;
    frame.sp50 = frame.spD0 + frame.spF0;
    frame.sp54 = frame.spD4 + frame.spF4;
    frame.sp58 = frame.spD8 + frame.spF8;
    func_001bd780(&frame.sp5C, &frame.sp50, &frame.spD0, D_0060A0E0);
    func_001c_rotate(&frame.sp90, D_0060A0E0, 0.5f * var_f20, 0);
    func_003e4320(&frame.spF0, &frame.spE0, &frame.sp90);
    scale2 = scale2 / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    frame.spF0 = frame.spF0 * scale2;
    frame.spF4 = frame.spF4 * scale2;
    frame.spF8 = frame.spF8 * scale2;
    frame.sp6C = frame.spD0 + frame.spF0;
    frame.sp70 = frame.spD4 + frame.spF4;
    frame.sp74 = frame.spD8 + frame.spF8;
    func_001bd780(&frame.sp78, &frame.sp6C, &frame.spD0, D_0060A0E0);
    if (frame.sp54 < 25.0f) {
        frame.sp54 = 25.0f;
    }
    if (frame.sp70 < 25.0f) {
        frame.sp70 = 25.0f;
    }
    func_001b73f0(s0);
    func_001bac20(arg0, &frame.sp50, &frame.sp6C, 1);
    func_001bbef0(arg0, 3.0f);
}
