/* object_size=196 window=256 normalized_diff=108 differing_offsets=18,26,36,39,40,42,43,54,58,59,62,63,66,67,70,71 classification=undersized near-miss/window-gap; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; callback/global declarations supplied at block scope including D_0088CD00/08/10/14 and iGpffffb9c0, but candidate remains materially different */
u8 *func_004114d0(u8 *arg0, s32 arg1, s32 arg2)
{
    extern void func_00414ef0(u8 *arg0);
    extern void func_00410f50(s32 arg0);
    extern u8 *D_0088CD00;
    extern s32 D_0088CD08;
    extern s32 D_0088CD10;
    extern u8 *D_0088CD14;
    s32 temp_2;
    u8 **temp_4_2;
    u8 *temp_4;

    if (arg2 != 0) {
        temp_4 = (u8 *)(iGpffffb9c0);
        if (*(s32 *)(temp_4 + 0x18) != 0) {
            func_00414ef0(temp_4);
        }
    }
    D_0088CD08 = 1;
    D_0088CD00 = arg0;
    D_0088CD10 = arg1;
    D_0088CD14 = (u8 *)(iGpffffb9c0);
    *(s32 *)(arg0 + 0x10) = 0;
    temp_4_2 = *(u8 ***)((u8 *)arg0 + 8);
    temp_2 = (*(s32 (**)(u8 **, s32 *))(*(u8 **)temp_4_2 + 4))(
        temp_4_2,
        &D_0088CD10);
    if (temp_2 == 0) {
        D_0088CD08 = temp_2;
    }
    if (*(s32 *)(arg0 + 0x10) >= 2) {
        *(s32 *)(arg0 + 0x10) = 2;
        func_00410f50(*(s32 *)(arg0 + 0x14));
    }
    D_0088CD10 = 0;
    D_0088CD00 = NULL;
    D_0088CD14 = NULL;
    if (D_0088CD08 != 0) {
        return arg0;
    }
    return NULL;
}
