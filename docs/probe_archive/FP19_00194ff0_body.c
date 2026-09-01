/* Best attempt: object 500B, window 512B, normalized_diff 24. Reverted because the candidate remained non-exact. */
void func_00194ff0(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3)
{
    struct Work {
        f32 vec[3];
        u8 gap[4];
        f32 x;
        s32 y;
        f32 z;
    } frame;
    s16 temp_6;
    s32 temp_6_2;
    u8 temp_5;
    u8 *temp_2;
    u8 *temp_4;

    frame.x = (f32)(s32)((*(s16 *)(arg0 + 0x94) * 0x19) - 0x6D6);
    frame.y = 0;
    temp_6 = *(s16 *)(arg0 + 0x96);
    temp_6_2 = temp_6 * 5;
    frame.z = (f32)((temp_6 * 0x19) - 0x6D6);
    if (arg1 != NULL) {
        *(f32 *)(arg1 + 0) = frame.x;
        *(f32 *)(arg1 + 4) = (f32)frame.y;
        *(f32 *)(arg1 + 8) = frame.z;
    }
    if ((arg3 != NULL) || (arg2 != NULL)) {
        temp_5 = *(u8 *)(arg0 + 0xA2);
        switch (temp_5) {
        case 0:
            if (func_00232710(*(s32 *)(arg0 + 0xA64), 0x100, temp_6_2) == 0) {
                func_00196040(2, 1, frame.vec, 0, 0, 1);
            } else {
                func_001958f0(
                    *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                    frame.vec);
            }
            break;
        case 1:
            if (func_0022f7d0(arg0, frame.vec, temp_6_2) != 1) {
                temp_2 = func_001b1510();
                if ((temp_2 != NULL) &&
                    ((temp_4 = *(u8 **)(temp_2 + 0x30)),
                     (*(u8 *)(temp_4 + 0xA2) == 0)) &&
                    ((*(u16 *)(temp_2 + 0x18) & 4) == 0 ||
                     *(u16 *)(temp_2 + 0x16) != 0x1E)) {
                    func_001958f0(temp_4, frame.vec);
                } else {
                    func_001958f0(
                        *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                        frame.vec);
                }
            }
            break;
        }
        if (arg3 != NULL) {
            arg3[0] = frame.vec[0];
            arg3[1] = frame.vec[1];
            arg3[2] = frame.vec[2];
        }
        if (arg2 != NULL) {
            func_001ec1c0(arg2, &frame.x, frame.vec);
        }
    }
}
