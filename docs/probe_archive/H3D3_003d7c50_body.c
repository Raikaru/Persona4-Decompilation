/* func_003d7c50 archived: retail window is 128B. Current corrected direct body (s32/u8* plus block externs) measures object 124B/window 128B, normalized_diff 72; M2C-shaped u8** body measures object 128B/nd69. The original void body was a compile error (missing callback/global declarations and illegal return value). Assembly fallback remains live. Retail behavior: decrement *(s32 *)(arg0[0x14] + 0x40); on zero call jtbl_008873FC(iGpffffb748, arg0[0x14]); then call func_003d5300(arg0) when callback path was taken; return 1. */
void func_003d7c50(u8 *arg0) {
    s32 result;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x14);
    *(s32 *)(temp_3 + 0x40) -= 1;
    if (*(s32 *)(temp_3 + 0x40) == 0) {
        ((void (*)(u8 *, u8 *))jtbl_008873FC[0])(
            (u8 *)iGpffffb748, *(u8 **)(arg0 + 0x14));
        result = 1;
    } else {
        result = 0;
    }
    if (result != 0) {
        func_003d5300(arg0);
    }
    return 1;
}
