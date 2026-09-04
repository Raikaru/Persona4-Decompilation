/* lane W42c20 probe for func_002055d0 (0x002055d0)
 * measured: obj 876B, window 896B, differing words 201 (fndiff)
 * levers tried: Vec2f/Color4 aggregates, block-scope prototypes for
 *   func_00113280/func_00275020/func_002bc4b0, explicit color packing,
 *   un-folded float expressions. Prologue/register allocation mismatch.
 */

void func_002055d0(u8 *arg0, s16 arg1, s8 arg2, s32 arg3, s32 arg4, f32 fparg0, f32 fparg1)
{
    Vec2f pos;
    Color4 color;
    s32 packed_color;
    u8 *temp_19;
    s16 temp_16;
    s8 digit;
    s32 temp_17;
    s8 var_18;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f23;
    s32 tens;

    extern void func_00113280(Vec2f arg0, f32 fparg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4);
    extern s32 func_00275020(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0, f32 fparg1, f32 fparg2);
    extern void func_002bc4b0(s64 arg0, s32 arg1, s32 arg2, f32 fparg0, s32 arg3, s32 arg4, s32 arg5);

    temp_19 = func_00452560(*(s32 *)(arg0 + 0x5B0));
    temp_17 = (s32)arg1 * 4;
    temp_16 = *(s16 *)(arg0 + temp_17 + 0x1A6);
    if (arg3 != 0) {
        var_18 = 0x1B;
    } else {
        var_18 = 0xFF;
    }

    pos.x = fparg0;
    pos.y = fparg1;
    color.c0 = var_18;
    color.c1 = var_18;
    color.c2 = var_18;
    color.c3 = arg2;
    func_00113280(pos, 50.0f, *(s32 *)&color, temp_16, *(s32 *)(temp_19 + 0x5C), *(s32 *)(temp_19 + 0x60));

    func_00272c60(0x40);
    packed_color = (arg2 & 0xFF) | ((var_18 & 0xFF) << 8) | ((var_18 & 0xFF) << 16) | ((var_18 & 0xFF) << 24);
    temp_f20 = 42.0f + fparg0;
    temp_f21 = (2.0f + fparg1) - 1.0f;
    func_00275020(packed_color, 0, 1, func_001067f0(temp_16), 0, -1, temp_f20, temp_f21, 50.0f);
    func_00272c80(0x40);

    temp_f22 = (374.0f + fparg0) - 97.0f;
    temp_f23 = (157.0f + fparg1) - 145.0f;
    func_00201650(temp_19, 0xC, 0x47, temp_f22, temp_f23, var_18, var_18, var_18, arg2);

    digit = *(s8 *)(arg0 + temp_17 + 0x1A8);
    temp_f22 = (398.0f + fparg0) - 97.0f;
    temp_f23 = (155.0f + fparg1) - 145.0f;
    func_00201650(temp_19, 0xC, (digit % 10) + 9, 16.0f + temp_f22, temp_f23, var_18, var_18, var_18, arg2);

    tens = digit / 10;
    if (tens != 0) {
        func_00201650(temp_19, 0xC, (tens % 10) + 9, temp_f22, temp_f23, var_18, var_18, var_18, arg2);
    }

    if (arg4 != 0) {
        func_00272c60(0x40);
        func_002bc4b0((s64)(s16)temp_16, (s32)(53.0f + fparg0), (s32)(36.0f + fparg1), 0.0f,
                      (arg2 & 0xFF) | ~0xFF, 1, 0);
        func_00272c80(0x40);
    }
}
