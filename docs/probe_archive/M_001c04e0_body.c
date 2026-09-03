/* object 1208B / window 1216B / normalized_diff 592
 * lane: M
 * levers tried: explicit PairF32 union frame struct with s64 pair fields for
 *   the 0x100/0x110/0x120 position copies, named f-reg locals for the saved
 *   FPR values (var_f20..var_f25), explicit 0.0f + ... + madd/msub source
 *   idioms for the COP1 accumulator chains, mula/madd dot-product ordering,
 *   split multiply chains into named temporaries, clamp comparisons against
 *   500.0f/25.0f/125.0f literals.
 * residual summary: major divergences remain across the whole window:
 *   - prologue frame size (sp allocation and saved-fp spill order),
 *   - saved FPR register allocation for var_f22/var_f23/var_f25 etc,
 *   - mula/madd/adda/msub operand and accumulator source selection,
 *   - branch delay slot and block layout around the two dot-product selects.
 *   First differing offsets: 0, 104, 116, 184, 240, 242, 246, 248, 249, 250,
 *   254, 260, 261, 262, 266, ...
 */
void func_001c04e0(u8 *arg0)
{
    typedef union {
        s64 pair;
        struct { f32 x; f32 y; } xy;
    } PairF32;
    struct {
        f32 sp60[8];
        f32 sp80;
        f32 sp84;
        f32 sp88;
        f32 sp8C;
        f32 sp90;
        f32 sp94;
        f32 sp98;
        f32 sp9C;
        f32 spA0;
        f32 spA4;
        f32 spA8;
        f32 spAC;
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
        u8 pad_to_E0[4];
        f32 spE0;
        f32 spE4;
        f32 spE8;
        u8 pad_to_F0[4];
        f32 spF0;
        f32 spF4;
        f32 spF8;
        u8 pad_to_100[4];
        PairF32 sp100;
        f32 sp108;
        u8 pad_to_110[4];
        PairF32 sp110;
        f32 sp118;
        u8 pad_to_120[4];
        PairF32 sp120;
        f32 sp128;
        u8 pad_tail[4];
    } frame;
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_001ec3d0(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
    extern f32 fGpffff8030;
    extern u8 D_0060A100[];
    extern void func_001bd5a0(f32 *arg0, f32 *arg1);
    u8 *obj_base;
    u8 *obj1;
    u8 *obj2;
    f32 var_f20;
    f32 var_f21;
    f32 var_f22;
    f32 var_f23;
    f32 var_f24;
    f32 var_f25;
    f32 scale;
    f32 f6;
    f32 a0;
    f32 a4;

    obj_base = *(u8 **)(arg0 + 0xE0);
    obj1 = *(u8 **)(obj_base + 0x30);
    obj2 = *(u8 **)(*(u8 **)(obj_base + 0x38) + 0x30);

    func_00195850(obj1, &frame.sp120.xy.x);
    func_00195850(obj2, &frame.sp110.xy.x);

    var_f23 = *(f32 *)(obj1 + 0x90) * *(f32 *)(obj1 + 0x2C);
    var_f22 = *(f32 *)(obj2 + 0x90) * *(f32 *)(obj2 + 0x2C);

    frame.spE0 = frame.sp120.xy.x - frame.sp110.xy.x;
    frame.spE4 = frame.sp120.xy.y - frame.sp110.xy.y;
    frame.spE8 = frame.sp128 - frame.sp118;

    var_f25 = func_003e40b0(&frame.spE0, &frame.spE0);

    frame.spA8 = *(f32 *)(arg0 + 0x9C) - frame.sp120.xy.x;
    frame.spAC = *(f32 *)(arg0 + 0xA4) - frame.sp128;

    func_003e41e0(&frame.spA8, &frame.spA8);

    {
        f32 temp_f2 = fGpffff80fc * var_f25;
        frame.spF0 = frame.spE0 * temp_f2;
        frame.spF4 = frame.spE4 * temp_f2;
        frame.spF8 = frame.spE8 * temp_f2;
        frame.spF0 = frame.spF0 + frame.sp110.xy.x;
        frame.spF4 = frame.spF4 + frame.sp110.xy.y;
        frame.spF8 = frame.spF8 + frame.sp118;
    }

    a0 = frame.spE0;
    a4 = frame.spE8;
    frame.spA0 = a0;
    frame.spA4 = a4;

    {
        f32 dot1 = a4 * frame.spAC + a0 * frame.spA8;
        if (dot1 < 0.0f) {
            obj1 = obj2;
            frame.sp100.pair = frame.sp110.pair;
            frame.sp108 = frame.sp118;
            f6 = 2.5f * (*(f32 *)(obj1 + 0x90) * *(f32 *)(obj1 + 0x2C));
            var_f24 = 2.25f;
        } else {
            frame.sp100.pair = frame.sp120.pair;
            frame.sp108 = frame.sp128;
            if (frame.sp100.xy.y < 125.0f) {
                frame.sp100.xy.y = 125.0f;
            }
            f6 = 2.5f * (*(f32 *)(obj1 + 0x90) * *(f32 *)(obj1 + 0x2C));
            var_f24 = 2.25f;
        }
    }

    a0 = frame.spE0;
    a4 = frame.spE8;
    frame.spA0 = a4;
    frame.spA4 = -a0;

    var_f20 = frame.sp100.xy.y;
    frame.spD4 = 0.0f + var_f20 + fGpffff8030 * (*(f32 *)(obj1 + 0x8C) * *(f32 *)(obj1 + 0x2C));

    {
        f32 b0 = a4;
        f32 b4 = -a0;
        f32 dot2 = b4 * frame.spAC + b0 * frame.spA8;
        if (dot2 < 0.0f) {
            frame.spD0 = 0.0f + frame.sp100.xy.x - b0 * f6;
            frame.spD8 = 0.0f + frame.sp108 + a0 * f6;
        } else {
            frame.spD0 = 0.0f + frame.sp100.xy.x + b0 * f6;
            frame.spD8 = 0.0f + frame.sp108 - a0 * f6;
        }
    }

    func_001bd780(&frame.sp8C, &frame.spD0, &frame.spF0, D_0060A0E0);
    func_003dcb40((s64 *)&frame.spE0, (s64 *)D_0060A100, 1, (u8 *)&frame.sp8C);

    frame.spB0 = frame.spF0;
    frame.spB4 = frame.spF8;
    frame.spB8 = frame.spD0;
    frame.spBC = frame.spD8;
    frame.spC8 = frame.sp100.xy.x;
    frame.spCC = frame.sp108;

    var_f21 = 0.0f + func_001ec3d0(&frame.spB0, &frame.spB8, &frame.spC8, &frame.spC0) +
              var_f24 * (*(f32 *)(obj1 + 0x90) * *(f32 *)(obj1 + 0x2C));

    frame.spD0 = frame.spC0;
    frame.spD4 = var_f20;
    frame.spD8 = frame.spC4;

    scale = var_f21 / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    if (scale < 500.0f) {
        scale = 500.0f;
    }

    frame.spE0 = frame.spE0 * scale;
    frame.spE4 = frame.spE4 * scale;
    frame.spE8 = frame.spE8 * scale;

    frame.sp80 = frame.spD0 + frame.spE0;
    frame.sp84 = frame.spD4 + frame.spE4;
    frame.sp88 = frame.spD8 + frame.spE8;
    if (frame.sp84 < 25.0f) {
        frame.sp84 = 25.0f;
    }

    func_001bd5a0((f32 *)(arg0 + 0x9C), &frame.sp80);
    func_001c8e90(arg0, &frame.sp80, &frame.sp60[0]);
    func_001bab00(arg0, &frame.sp60[0]);

    func_001bcd40(*(u8 **)(arg0 + 0xE0), (u8 *)(arg0 + 0x9C), (u8 *)(arg0 + 0x100),
                  0.5f * (var_f22 + (var_f25 + var_f23)), 3);
    if (var_f23 <= var_f22) {
        var_f23 = var_f22;
    }
    func_001bcd40(*(u8 **)(arg0 + 0xE0), (u8 *)&frame.sp120.xy.x, (u8 *)&frame.sp110.xy.x, var_f23, 3);
}
