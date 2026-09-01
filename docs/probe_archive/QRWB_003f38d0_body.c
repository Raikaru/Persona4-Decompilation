/* object_size=228 window=240 normalized_diff=101 differing_offsets=15,18,19,22,26,36,39,42,43,44,45,46,47,48,50,51 classification=undersized near-miss; ruled_out=global GP declarations corrected to iGpffffb81c/b840/b83c/b830/b82c/b860/b848/b868, no movz/movn/COP1 accumulator/MMI/tail-jump floor; duplicate global guard chain retained but candidate stayed 12 bytes short */
void func_003f38d0(void)
{
    extern void func_003f2830(s32 arg0);
    extern void func_003f32d0(u32 arg0, u32 arg1);
    extern u8 iGpffffb81c;
    extern u8 iGpffffb840;
    extern u8 iGpffffb83c;
    extern s32 iGpffffb830;
    extern s32 iGpffffb82c;
    extern u8 iGpffffb860;
    extern s32 iGpffffb848;
    extern s32 iGpffffb868[];
    u32 temp_4;
    u32 temp_4_2;
    u32 temp_5;
    u32 temp_5_2;

    if (iGpffffb81c != 0) {
        iGpffffb81c = 0;
        if ((iGpffffb840 == 0) &&
            (iGpffffb83c == 0) &&
            (iGpffffb840 == 0) &&
            (iGpffffb830 == iGpffffb82c)) {
            temp_5 = iGpffffb860 * 4;
            temp_4 = *(u32 *)((u8 *)iGpffffb868 + temp_5);
            if (temp_4 != (u32)iGpffffb848) {
                func_003f32d0(temp_4, temp_5);
            }
        } else {
            if ((iGpffffb830 != iGpffffb82c) &&
                (iGpffffb840 == 0) &&
                (iGpffffb83c == 0) &&
                (iGpffffb840 == 0)) {
                func_003f2830(-1);
            }
            temp_5_2 = iGpffffb860 * 4;
            temp_4_2 = *(u32 *)((u8 *)iGpffffb868 + temp_5_2);
            if (temp_4_2 != (u32)iGpffffb848) {
                func_003f32d0(temp_4_2, temp_5_2);
            }
        }
    }
}
