/* Archived best reconstruction: object 740B, window 720B, normalized_diff 117. */
extern void func_00206dd0(u8 *arg0, u8 *arg1, void (*callback)(void), f32 fparg0, f32 fparg1);
void func_00208d00(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_2_2;
    u8 *temp_2;

    temp_2 = func_00452560(*(s32 *)(arg1 + 0x5B0));
    func_002012d0(temp_2, arg2[0], arg2[1]);
    if (*(u16 *)arg1 == 2) {
        func_00201650(temp_2, 9, 0x49, 77.0f, 314.0f,
                      0xFE, 0xFF, 0x22, 0xFF);
        func_00201650(temp_2, 9, 0x4A, 93.0f, 314.0f,
                      0x1B, 0x1B, 0x1B, 0xFF);
        func_00206dd0(arg1, arg0, func_00205170, arg2[0], arg2[1]);
    } else {
        func_00201650(temp_2, 9, 0x21, 75.0f, 317.0f,
                      0x1B, 0x1B, 0x1B, 0xFF);
    }
    D_00887300[0](6, 1);
    func_002019e0(temp_2, 0x42F00000);
    func_00201650(temp_2, 9, 0x37, 8.0f, 297.0f,
                  0x1B, 0x1B, 0x1B, 0xFF);
    D_00887300[0](6, 0);
    func_002019e0(temp_2, 0.0f);
    temp_2_2 = *(s16 *)(arg1 + 0x1A);
    if (temp_2_2 < 4) {
        *(s16 *)(arg1 + 0x1A) = temp_2_2 + 1;
    }
    if (func_001eb860() != 0) {
        func_00201650(temp_2, 9, 0x18, 100.0f, 411.0f,
                      0x1B, 0x1B, 0x1B, 0xFF);
        ((void (*)(u8 *, s32, s32, f32, f32))func_00201410)(
            temp_2, 9, 0x1C, 100.0f, 411.0f);
        func_00201650(temp_2, 9, 0x1A, 119.0f, 411.0f,
                      0x1B, 0x1B, 0x1B, 0xFF);
        ((void (*)(u8 *, s32, s32, f32, f32))func_00201410)(
            temp_2, 9, 0x19, 119.0f, 411.0f);
    }
}
