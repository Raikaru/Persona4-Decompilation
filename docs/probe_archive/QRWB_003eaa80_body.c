/* object_size=224 window=240 normalized_diff=82 differing_offsets=32,33,34,35,38,39,60,63,66,67,96,99,100,102,103,124 classification=undersized near-miss; ruled_out=movz/movn/COP1 accumulator/MMI/tail-jump floors absent; absolute-array declarations fixed D_008873D4/D_008873F0 addressing (nd154->82), explicit ordered temp/base probe worsened to object_size=228 nd118 and was reverted */
s8 *func_003eaa80(s8 *arg0)
{
    extern void func_003df4d0(s32 *arg0);
    extern s32 func_003df590(s32 arg0, s32 arg1);
    extern void func_0043f810(void *arg0, void *arg1, u32 arg2);
    extern s32 (*D_008873D4[])(void);
    extern s8 *(*D_008873F0[])(s8 *arg0, s32 arg1, s32 arg2);
    extern s32 D_008872E0[];
    s32 sp3C;
    s32 sp38;
    s32 temp_16;
    s8 *temp_2;

    temp_16 = D_008873D4[0]() + 1;
    if (*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 8) < temp_16) {
        temp_2 = D_008873F0[0](
            *(s8 **)((u8 *)D_008872E0 + iGpffffb7c8 + 4),
            temp_16,
            0x01040406);
        if (temp_2 != NULL) {
            *(s8 **)((u8 *)D_008872E0 + iGpffffb7c8 + 4) = temp_2;
            *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 8) = temp_16;
        } else {
            sp38 = 1;
            sp3C = func_003df590(0x80000013, temp_16);
            func_003df4d0(&sp38);
            return NULL;
        }
    }
    func_0043f810(
        *(void **)((u8 *)D_008872E0 + iGpffffb7c8 + 4),
        arg0,
        temp_16);
    return arg0;
}
