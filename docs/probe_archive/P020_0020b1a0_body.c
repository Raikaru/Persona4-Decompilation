/* object_size=508B window=512B normalized_diff=36 differing_offsets=188,189,190,191,192,194,196,198,200,202,203,204,205,206,207,436; classification=ordinary mixed-ABI callback argument scheduling residual; ruled_out=not a COP1 floor (all 8 accumulator operations reproduced), not a size or branch residual, no new data reference; the first candidate placed lbu/t0 integer argument loads before the f13 move at both func_00203930 calls. */
/* Candidate body archived before the callback-argument reorder closed it: */
void func_0020b1a0(s32 arg0, u8 *arg1)
{
    extern void func_00203930(u8 *arg0, u8 arg1, u8 arg2, u8 arg3,
                              s32 arg4, f32 fparg0, f32 fparg1);
    u8 *temp_2;
    s16 temp_3;
    s16 temp_4;
    f32 temp_f12;
    f32 temp_f20;

    temp_2 = func_00452560(*(s32 *)(arg1 + 0x5B0));
    if ((*(s32 *)temp_2 & 1) != 0) {
        if (*(u16 *)arg1 != 0) {
            if (*(s16 *)(arg1 + 0x5AC) == -1) {
                func_00201350();
                temp_f12 = (f32)*(s16 *)(arg1 + 8) / 19.0f;
                if (temp_f12 < 1.0f) {
                    temp_f12 = (temp_f12 * 2.0f -
                                temp_f12 * temp_f12) *
                               1.5f;
                    func_00203930(
                        temp_2, *(u8 *)(arg1 + 0x24),
                        *(u8 *)(arg1 + 0x25), *(u8 *)(arg1 + 0x26),
                        0x4C, temp_f12, temp_f12);
                }
                temp_3 = *(s16 *)(arg1 + 0xA);
                if (temp_3 < 7) {
                    temp_f12 = (f32)(6 - temp_3) / 6.0f;
                    if (temp_f12 < 1.0f) {
                        temp_f20 = 1.0f -
                                   (temp_f12 * 2.0f -
                                    temp_f12 * temp_f12);
                    }
                } else {
                    temp_4 = temp_3 - 6;
                    temp_f12 = (f32)temp_4 / 5.0f;
                    if (temp_f12 < 1.0f) {
                        temp_f20 =
                            (temp_f12 * 2.0f -
                             temp_f12 * temp_f12) *
                                0.25f +
                            1.0f;
                    }
                }
                func_00203930(
                    temp_2, *(u8 *)(arg1 + 0x24),
                    *(u8 *)(arg1 + 0x25), *(u8 *)(arg1 + 0x26),
                    0xFF, temp_f20, temp_f20);
                func_002035a0(arg1 + 0x2C);
            }
        }
    }
}
