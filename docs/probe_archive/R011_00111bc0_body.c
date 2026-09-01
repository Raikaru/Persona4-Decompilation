/* object 1952/window 1856/normalized_diff 1406; oversized by 96 bytes; classification: typed-stack/branch-shape declaration residual; ruled out: movz/movn, COP1 MAC, standalone MMI, COP2/VU0, framed tail-jump. Prologue matched -1504 frame and s0-s6 saves; scalar global declarations produced GP loads instead of retail absolute loads. */
void func_00111bc0(void)
{
    s32 saved_global;
    s32 end_date;
    s32 value;
    s32 result;
    u8 count;
    s8 flag;
    s16 i;
    s32 stack[342];
    f32 f3;
    f32 f2;
    f32 f1;
    f32 f0;
    s32 func_001064f0(s32);
    void func_00106550(s32, u32);
    s32 func_00106600(s16);
    s32 func_00106330(s32);
    void func_00106390(s32, s32);
    s16 func_00104ea0(s16, s16);
    u32 func_00105ed0(void);
    void func_00105fa0(u32);
    void func_00106620(s16, s32);
    void func_001051a0(s16, s16, s16);
    void func_00110470(u32);
    void func_00310700(void);
    void func_00310850(void);
    extern f32 D_005E4700;
    extern f32 D_005E4704;
    extern f32 D_005E4708;
    extern f32 D_005E470C;

    saved_global = iGpffffb19c;
    count = 0;
    flag = 0;
    f3 = D_005E4700;
    f2 = D_005E4704;
    f1 = D_005E4708;
    f0 = D_005E470C;
    *(f32 *)((u8 *)stack + 0) = f3;
    *(f32 *)((u8 *)stack + 4) = f2;
    *(f32 *)((u8 *)stack + 8) = f1;
    *(f32 *)((u8 *)stack + 12) = f0;
    value = func_001064f0(0x7C);
    end_date = func_00110460() + 1;

    if ((func_00106600(0x4A0) & 0xFF) > 0) {
        stack[4] = 0x4A0;
        count = 1;
    }
    if ((func_00106600(0x4A1) & 0xFF) > 0) {
        stack[4 + count] = 0x4A1;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A2) & 0xFF) > 0) {
        stack[4 + count] = 0x4A2;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A3) & 0xFF) > 0) {
        stack[4 + count] = 0x4A3;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A4) & 0xFF) > 0) {
        stack[4 + count] = 0x4A4;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A5) & 0xFF) > 0) {
        stack[4 + count] = 0x4A5;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A6) & 0xFF) > 0) {
        stack[4 + count] = 0x4A6;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A7) & 0xFF) > 0) {
        stack[4 + count] = 0x4A7;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A8) & 0xFF) > 0) {
        stack[4 + count] = 0x4A8;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A9) & 0xFF) > 0) {
        stack[4 + count] = 0x4A9;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AA) & 0xFF) > 0) {
        stack[4 + count] = 0x4AA;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AB) & 0xFF) > 0) {
        stack[4 + count] = 0x4AB;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AC) & 0xFF) > 0) {
        stack[4 + count] = 0x4AC;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AD) & 0xFF) > 0) {
        stack[4 + count] = 0x4AD;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AE) & 0xFF) > 0) {
        stack[4 + count] = 0x4AE;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AF) & 0xFF) > 0) {
        stack[4 + count] = 0x4AF;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B0) & 0xFF) > 0) {
        stack[4 + count] = 0x4B0;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B1) & 0xFF) > 0) {
        stack[4 + count] = 0x4B1;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B2) & 0xFF) > 0) {
        stack[4 + count] = 0x4B2;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B3) & 0xFF) > 0) {
        stack[4 + count] = 0x4B3;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x418) & 0xFF) > 0) {
        stack[4 + count] = 0x418;
        count = (count + 1) & 0xFF;
    }

    if (func_00106330(0x2F) != 0) {
        flag = 1;
    }
    if (func_00106330(0x1DD) != 0) {
        flag = 1;
    }

    i = 0;
    goto loop_1_check;
loop_1:
    stack[332 + i] = func_00106330(i + 0x39);
    i++;
loop_1_check:
    if (i < 7) {
        goto loop_1;
    }

    result = 0;
    goto loop_2_check;
loop_2:
    if (*(s32 *)((u8 *)stack + 128 + result * 4) == 0) {
        goto loop_2_done;
    }
    *(s32 *)((u8 *)stack + 656 + result * 4) =
        func_00106330(*(s32 *)((u8 *)stack + 128 + result * 4));
    result++;
loop_2_check:
    if (result < 200) {
        goto loop_2;
    }
loop_2_done:
    func_00310700();

    i = 0;
    goto loop_3_check;
loop_3:
    *(s16 *)((u8 *)stack + 1360 + i * 2) =
        func_00104ea0(1, (s16)i);
    i++;
loop_3_check:
    if (i < 5) {
        goto loop_3;
    }

    result = func_00105ed0();
    func_001113b0();
    i = 0;
    goto loop_4_check;
loop_4:
    func_00106390(i + 0x39, stack[332 + i]);
    i++;
loop_4_check:
    if (i < 7) {
        goto loop_4;
    }

    i = 0;
    goto loop_5_check;
loop_5:
    if (*(s32 *)((u8 *)stack + 128 + i * 4) == 0) {
        goto loop_5_done;
    }
    func_00106390(*(s32 *)((u8 *)stack + 128 + i * 4),
                  *(s32 *)((u8 *)stack + 656 + i * 4));
    i++;
loop_5_check:
    if (i < 200) {
        goto loop_5;
    }
loop_5_done:
    count &= 0xFF;
    i = 0;
    goto loop_6_check;
loop_6:
    func_00106620(*(s16 *)((u8 *)stack + 144 + i * 4), 1);
    i++;
loop_6_check:
    if (i < count) {
        goto loop_6;
    }
    if (flag == 1) {
        func_00106390(0x1DD, 1);
    }
    func_00310850();
    func_00106390(0x1210, 1);
    func_00106550(0x7C, value);
    func_00110470(end_date);

    i = 0;
    goto loop_7_check;
loop_7:
    func_001051a0(1, (s16)i,
                  *(s16 *)((u8 *)stack + 1360 + i * 2));
    i++;
loop_7_check:
    if (i < 5) {
        goto loop_7;
    }
    func_00105fa0(result);
    func_00106390(0x800, 1);
    iGpffffb19c = saved_global;
}
