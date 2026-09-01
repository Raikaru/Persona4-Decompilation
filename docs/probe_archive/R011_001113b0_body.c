/* object 1024/window 1040/normalized_diff 352; undersized; classification: declaration and loop-shape residuals; ruled out: movz/movn, COP1 MAC, standalone MMI, COP2/VU0, framed tail-jump. Block declarations corrected for 00104dc0/00104e30/00105ce0/0010b9a0. */
void func_001113b0(void)
{
    s32 j;
    s32 i;
    u8 *p;
    s16 func_00104dc0(s16);
    s16 func_00104e30(s16);
    void func_001051a0(s16, s16, s16);
    void func_001055a0(s16);
    void func_00105690(s16, u8);
    void func_001056e0(s16, s16);
    void func_00105730(s16, s16);
    void func_00105990(s16, u32);
    void func_00105c90(s16, s16);
    void func_00105ce0(s16, s16);
    void func_00105dc0(s16, s16, s16);
    void func_00105fa0(u32);
    void func_00106000(s32, s16);
    void func_00106100(s16);
    void func_001062f0(u8);
    void func_00106300(s16);
    void func_00106310(u8);
    void func_00106320(u32);
    void func_00106480(void);
    void func_001064c0(void);
    void func_001065c0(void);
    void func_00106620(s16, s32);
    void func_00106d40(s16, s16, s16);
    void func_001070b0(void);
    s32 func_0010b9a0(s32, u16);
    void func_0010bd90(s16);
    void func_0010d490(u8 *, u8 *);
    void func_0010f390(void);
    void func_0010f4c0(void);
    void func_0010fc80(void);
    void func_00110470(u32);
    void func_00155250(void);
    void func_0015a630(void);
    void func_00162120(void);
    extern u16 D_005E4630[];
    extern s16 D_005E4650[];

    func_00110e70(0);
    func_00106320(0);
    func_0010d490((u8 *)&iGpffffb1b4 - 0x6448,
                  (u8 *)&iGpffffb1b4 - 0x6440);
    func_00105fa0(0);
    func_0010fc80();

    i = 1;
    goto loop_1_check;
loop_1:
    func_001055a0((s16)i);
    if (i == 1) {
        func_00105690((s16)i, 1);
        func_00105990((s16)i, 0);
    }
    func_001056e0((s16)i, 1);
    func_00105730((s16)i, 1);
    j = 0;
    goto loop_2_check;
loop_2:
    func_001051a0((s16)i, (s16)j, 0);
    j++;
loop_2_check:
    if (j < 5) {
        goto loop_2;
    }
    func_00105c90((s16)i, 0);
    func_00105ce0((s16)i, 0);
    func_00105dc0((s16)i, 0, -1);
    func_00105dc0((s16)i, 1, -1);
    func_00105dc0((s16)i, 2, -1);
    func_0010bd90((s16)i);
    func_0010b9a0(i, D_005E4630[i - 1]);
    func_001056e0((s16)i, func_00104dc0((s16)i));
    func_00105730((s16)i, func_00104e30((s16)i));
    i++;
loop_1_check:
    if (i < 11) {
        goto loop_1;
    }

    func_00106480();
    func_001065c0();
    func_001064c0();
    func_001062f0(5);
    func_00106100(9);
    func_00106310(5);
    func_00106300(9);
    i = 0;
    goto loop_3_check;
loop_3:
    func_00106620((s16)i, 0);
    i++;
loop_3_check:
    if (i < 1536) {
        goto loop_3;
    }

    i = 1;
    goto loop_4_check;
loop_4:
    p = (u8 *)D_005E4650 + i * 6;
    func_00106d40((s16)i, 0, *(s16 *)(p - 6));
    func_00106d40((s16)i, 1, *(s16 *)(p - 4));
    func_00106d40((s16)i, 2, *(s16 *)(p - 2));
    i++;
loop_4_check:
    if (i < 11) {
        goto loop_4;
    }

    func_00106000(0, 0);
    func_00106000(1, 0);
    func_00106000(2, 0);
    func_00106000(3, 0);
    func_00155250();
    func_00162120();
    func_0015a630();
    func_0010f390();
    func_0010f4c0();
    func_001070b0();

    i = 0;
    goto loop_5_check;
loop_5:
    func_00110810(i, 0);
    i++;
loop_5_check:
    if (i < 1536) {
        goto loop_5;
    }
    iGpffffb1bc = 0;
    iGpffffb19c = 0;
    func_00106390(0x39, 1);
    func_00106390(0x3A, 1);
    func_00106390(0x3B, 0);
    func_00106390(0x3C, 1);
    func_00106390(0x3D, 1);
    func_00106390(0x3E, 0);
}
