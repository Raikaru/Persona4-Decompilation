/* lane W42c20 probe for func_00206dd0 (0x00206dd0)
 * measured: obj 868B, window 880B, differing words 88 (fndiff)
 * levers tried: explicit clamping, (2.0f * f) - (f * f) to trigger mula/msub,
 *   base = D_00887300, s32[4] pos with bit-pattern values, Color4 byte writes.
 * Remaining differences: D_00887300 base register/relocation handling
 *   and prologue saved-register copy order for s2 vs f20/f21.
 */

void func_00206dd0(u8 *arg0, u8 *arg1, void (*arg2)(u8 *, s16, s8, s32, s32, f32, f32), f32 fparg0, f32 fparg1)
{
    u8 *temp_2;
    f32 var_f0;
    f32 var_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 pos[4];
    Color4 color;
    void (**base)(u32, u32);

    temp_2 = func_00452560(*(s32 *)(arg0 + 0x5B0));
    func_002012d0(temp_2, fparg0, fparg1);

    var_f0 = (f32)(*(s16 *)(arg0 + 0x1A)) / 4.0f;
    if (var_f0 > 1.0f) {
        var_f1 = 1.0f;
    } else if (var_f0 < 0.0f) {
        var_f1 = 0.0f;
    } else {
        var_f1 = var_f0;
    }

    temp_f20 = (2.0f * var_f1) - (var_f1 * var_f1);
    if (temp_f20 <= 0.0f) {
        return;
    }

    base = D_00887300;
    base[0](8, 1);

    if (temp_f20 < 1.0f) {
        base[0](1, 0);

        color.c0 = 0;
        color.c1 = 0;
        color.c2 = 0xFF;
        color.c3 = 0;
        pos[0] = 0x6E;
        pos[1] = 0x14D;
        pos[2] = 0x17C;
        pos[3] = 0x25;
        func_0045d6e0((u8 *)&color, (f32 *)pos, 0.0f, 0);
    }

    func_002019e0(temp_2, 170.0f);
    func_00201720(temp_2, 1.0f, temp_f20);

    temp_f20_2 = (f32)0x14D + (18.5f * (1.0f - temp_f20));
    func_00201410(temp_2, 9, 0x30, 110.0f, temp_f20_2);
    func_00201410(temp_2, 9, 0x31, 470.0f, temp_f20_2);

    func_00201720(temp_2, 1.0f, 1.0f);
    base[0](8, 0);
    func_002019e0(temp_2, 150.0f);
    base[0](6, 1);
    arg2(arg0, *(s16 *)(arg1 + 4), 0xFF, 0, 0, 127.0f, 338.0f);
    base[0](6, 0);
    func_002019e0(temp_2, 0.0f);
    func_00201410(temp_2, 9, 0x32, 215.0f, 412.0f);
    func_00201410(temp_2, 9, 0x33, 193.0f, 412.0f);
    func_00201410(temp_2, 9, 0x33, (f32)0x19D, 412.0f);
}
