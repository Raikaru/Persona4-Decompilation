/* object 284B/window 272B/normalized_diff 191; differing offsets 4-27; classification OVERSIZED; ruled out confirmed compiler floors (no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode); direct legal-C reconstruction is oversized and was discarded immediately. */
u8 *func_003d7b40(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    extern u8 *func_003d51c0(s32 arg0, u8 *arg1, s32 arg2);
    extern void func_00442de8(void *dst, const void *src, s32 size);
    extern s32 iGpffffb748;
    extern s32 D_0070B650;
    extern s32 D_0070B680;
    extern u8 *(*D_008873F8[])(s32 arg0, s32 arg1);
    u8 *temp_2;
    u8 *var_16;

    var_16 = NULL;
    switch (arg4) {
    case 0:
        var_16 = func_003d51c0(D_0070B650, arg2, 0);
        break;
    case 1:
        var_16 = func_003d51c0(D_0070B680, arg2, 0);
        break;
    }
    if (var_16 != NULL) {
        temp_2 = D_008873F8[0](iGpffffb748, 0x30135);
        if (temp_2 != NULL) {
            func_00442de8(temp_2, arg0, 0x20);
            *(s8 *)(temp_2 + 0x1F) = 0;
            func_0043f810(temp_2 + 0x20, arg3, arg1 * 4);
            *(s32 *)(temp_2 + 0x40) = 1;
            *(u8 **)(var_16 + 0x14) = temp_2;
        } else {
            var_16 = NULL;
        }
    }
    return var_16;
}
