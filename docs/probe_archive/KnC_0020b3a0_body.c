/* object_size=500B window=512B normalized_diff=7 differing_offsets=0x1A8,0x1AC,0x1B0,0x1B4 classification=near-match-before-compound-increment; ruled_out=outer-condition spelling, COP1 accumulator emission, table relocation, callback float-argument order; COP1 chain reproduced by plain C (all 6 accumulator ops matched). Final compound-assignment form closed this residual. */
void func_0020b3a0(s32 arg0, u8 *arg1)
{
    extern void func_00204b80(u8 *arg0, f32 farg0, f32 farg1, u8 arg1);
    extern u8 D_00626BE0[];
    u8 *temp_2;
    s32 temp_2_2;
    s16 temp_3;
    s16 temp_4;
    f32 temp_f20;

    temp_2 = func_00452560(*(s32 *)(arg1 + 0x5B0));
    if ((*(s32 *)temp_2 & 1) != 0) {
        if (*(u16 *)arg1 != 0) {
            if (*(s16 *)(arg1 + 0x5AC) == -1) {
                func_00201350();
                temp_3 = *(s16 *)(arg1 + 0xA);
                if (temp_3 < 7) {
                    if (((f32)(6 - temp_3) / 6.0f) < 1.0f) {
                        temp_f20 = 1.0f -
                            ((f32)(6 - temp_3) / 6.0f * 2.0f -
                             (f32)(6 - temp_3) / 6.0f *
                                 ((f32)(6 - temp_3) / 6.0f));
                    }
                } else {
                    temp_4 = temp_3 - 6;
                    if (((f32)temp_4 / 5.0f) < 1.0f) {
                        temp_f20 =
                            ((f32)temp_4 / 5.0f * 2.0f -
                             (f32)temp_4 / 5.0f *
                                 ((f32)temp_4 / 5.0f)) *
                                0.25f +
                            1.0f;
                    }
                }
                func_00204a30(temp_2, temp_f20, temp_f20);
                if (((*(s32 *)(arg1 + 4) & 2) != 0) &&
                    (*(u16 *)arg1 != 2) &&
                    (*(s16 *)(arg1 + 0xA) < 7)) {
                    func_00204b80(temp_2, 1.0f, 1.0f,
                                  D_00626BE0[*(s16 *)(arg1 + 0x10)]);
                    temp_2_2 = *(s16 *)(arg1 + 0x10) + 1;
                    *(s16 *)(arg1 + 0x10) = temp_2_2;
                    if ((u32)(s16)temp_2_2 >= 0x14) {
                        *(s16 *)(arg1 + 0x10) = 0x13;
                    }
                }
                func_00203600(arg1 + 0x2C);
            }
        }
    }
}
