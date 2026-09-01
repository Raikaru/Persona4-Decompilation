/* measured: hypothesis 10; restore seed shape as final pre-archive check. */
// FUN_0011DD50
void func_0011dd50(u8 *arg0)
{
    u8 *work;
    work = ((SdkTask *)arg0)->work;
    if (*(s32 *)(work + 0) == 3 &&
        *(s32 *)(work + 4) != 0 &&
        *(s32 *)(work + 0x14) != 0) {
        *(f32 *)(work + 0x40) =
            *(f32 *)(work + 0x40) +
            (*(f32 *)(work + 0x28) - *(f32 *)(work + 0x40)) / 3.0f;
        *(f32 *)(work + 0x44) =
            *(f32 *)(work + 0x44) +
            (*(f32 *)(work + 0x2C) - *(f32 *)(work + 0x44)) / 3.0f;
        func_00364680(*(s32 *)(work + 0x0C), (s32 *)(work + 0x50), 1, 0,
                      *(f32 *)(work + 0x18),
                      *(f32 *)(work + 0x40) + *(f32 *)(work + 0x38),
                      *(f32 *)(work + 0x44) + *(f32 *)(work + 0x3C),
                      *(f32 *)(work + 0x28), *(f32 *)(work + 0x2C),
                      512.0f, 512.0f);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 68);
    }
}





