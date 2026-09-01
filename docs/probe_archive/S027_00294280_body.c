/* object 908/912 normalized_diff 92 differing_offsets 270,272,274,275,276,280,282,283,284,286,287,288,290,292,294,295; classification exact-size-near-miss with 4-byte tail deficit; prologue/frame right (144-byte frame, saved s0-s7, one incoming pointer), direct fallback-call and grouped float locals; residual byte-load ordering and final float-copy register/scheduling; ruled out movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, sd-s. */
void func_00294280(u8 *arg0)
{
    extern s32 func_00145260();
    extern u8 *func_00145270(s32 arg0);
    extern u8 *func_00147500(s32 arg0, s32 arg1);
    extern s32 func_001475c0(s32 arg0, s32 arg1);
    extern u8 *func_00286f00();
    extern void func_00286ff0();
    extern u8 *func_00287060();
    extern void func_0028f530();
    extern s32 func_00440b68();
    extern s32 func_0044dcd8(f32 arg0);
    extern u8 *func_0047a250(s32 arg0);
    extern u8 D_0063CAC0[];
    extern u8 D_0063CAD0[];
    u8 *temp_20_2;
    u8 *temp_22;
    u8 *temp_23;
    s32 temp_3;
    s32 temp_4;
    s32 var_16;
    s32 var_5;
    u16 *temp_2_2;
    u8 *temp_2_4;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *var_6;
    u8 *var_7;
    s32 temp_20;
    s32 temp_19;
    s32 temp_2;
    u8 *temp_2_2b;
    s32 temp_2_3;
    f32 value_0;
    f32 value_1;
    f32 value_2;

    temp_2 = func_00145260();
    if (temp_2 != 0) {
        temp_2_2 = (u16 *)func_00145270(0x400);
        if (temp_2_2 != NULL) {
            temp_2_3 = (s32)func_00286f00(1, arg0);
            func_00286ff0((u8 *)temp_2_3, 0x400, temp_2_2);
            *(s32 *)((u8 *)temp_2_3 + 8) = -1;
            value_2 = *(f32 *)((u8 *)temp_2_2 + 4);
            value_1 = *(f32 *)((u8 *)temp_2_2 + 8);
            value_0 = *(f32 *)((u8 *)temp_2_2 + 0xC);
            *(f32 *)((u8 *)temp_2_3 + 0x38) = value_2;
            *(f32 *)((u8 *)temp_2_3 + 0x3C) = value_1;
            *(f32 *)((u8 *)temp_2_3 + 0x40) = value_0;
            value_2 = *(f32 *)((u8 *)temp_2_2 + 0x10);
            value_1 = *(f32 *)((u8 *)temp_2_2 + 0x14);
            value_0 = *(f32 *)((u8 *)temp_2_2 + 0x18);
            *(f32 *)((u8 *)temp_2_3 + 0x44) = value_2;
            *(f32 *)((u8 *)temp_2_3 + 0x48) = value_1;
            *(f32 *)((u8 *)temp_2_3 + 0x4C) = value_0;
            temp_20 = func_0044dcd8(*(f32 *)(temp_2_2 + 2));
            temp_19 = func_0044dcd8(*(f32 *)(temp_2_2 + 4));
            func_00440b68(D_0063CAC0, temp_20, temp_19,
                          func_0044dcd8(*(f32 *)(temp_2_2 + 6)));
            temp_2_4 = func_0047a250(*(s32 *)((u8 *)temp_2_2 + 0x164));
            *(u8 *)((u8 *)temp_2_3 + 0x50) = *(u8 *)(temp_2_4 + 0);
            *(u8 *)((u8 *)temp_2_3 + 0x51) = *(u8 *)(temp_2_4 + 1);
            *(u8 *)((u8 *)temp_2_3 + 0x52) = *(u8 *)(temp_2_4 + 2);
            *(u8 *)((u8 *)temp_2_3 + 0x53) = *(u8 *)(temp_2_4 + 3);
        } else {
            func_00286ff0((u8 *)func_00286f00(1, arg0), 0x400, NULL);
        }
        temp_20 = func_001475c0(temp_2, 3);
        temp_2_2b = func_00147500(temp_2, 3);
        func_00440b68(D_0063CAD0, temp_20);
        temp_19 = 0;
        goto loop_6_test;
loop_6_body:
        func_0028f530(temp_2_2b);
        temp_2_3 = (s32)func_00287060(
            1, arg0, *(u16 *)temp_2_2b, temp_2_2b);
        *(s32 *)((u8 *)temp_2_3 + 8) = -1;
        value_2 = *(f32 *)(temp_2_2b + 4);
        value_1 = *(f32 *)(temp_2_2b + 8);
        value_0 = *(f32 *)(temp_2_2b + 0xC);
        *(f32 *)((u8 *)temp_2_3 + 0x38) = value_2;
        *(f32 *)((u8 *)temp_2_3 + 0x3C) = value_1;
        *(f32 *)((u8 *)temp_2_3 + 0x40) = value_0;
        value_2 = *(f32 *)(temp_2_2b + 0x10);
        value_1 = *(f32 *)(temp_2_2b + 0x14);
        value_0 = *(f32 *)(temp_2_2b + 0x18);
        *(f32 *)((u8 *)temp_2_3 + 0x44) = value_2;
        *(f32 *)((u8 *)temp_2_3 + 0x48) = value_1;
        *(f32 *)((u8 *)temp_2_3 + 0x4C) = value_0;
        temp_22 = (u8 *)func_0044dcd8(*(f32 *)(temp_2_2b + 4));
        temp_23 = (u8 *)func_0044dcd8(*(f32 *)(temp_2_2b + 8));
        func_00440b68(D_0063CAC0, temp_22, temp_23,
                      func_0044dcd8(*(f32 *)(temp_2_2b + 0xC)));
        temp_2_6 = func_0047a250(*(s32 *)(temp_2_2b + 0x164));
        *(u8 *)((u8 *)temp_2_3 + 0x50) = *(u8 *)(temp_2_6 + 0);
        *(u8 *)((u8 *)temp_2_3 + 0x51) = *(u8 *)(temp_2_6 + 1);
        *(u8 *)((u8 *)temp_2_3 + 0x52) = *(u8 *)(temp_2_6 + 2);
        *(u8 *)((u8 *)temp_2_3 + 0x53) = *(u8 *)(temp_2_6 + 3);
        temp_19++;
        temp_2_2b = *(u8 **)(temp_2_2b + 0x138);
loop_6_test:
        if (temp_19 < temp_20)
            goto loop_6_body;
        temp_2_3 = 0;
        goto loop_9_test;
loop_9_body:
        temp_2_7 = func_00286f00(1, arg0);
        temp_4 = temp_2_3 + 0x384;
        temp_4 = (temp_4 & 0x3FF) | 0xC00;
        func_00286ff0(temp_2_7, temp_4 & 0xFFFF, NULL);
        temp_2_3++;
loop_9_test:
        if (temp_2_3 < 3)
            goto loop_9_body;
        temp_2_7 = func_00147500(temp_2, 5);
        if (temp_2_7 != NULL) {
            *(f32 *)(arg0 + 0x6F0) = *(f32 *)(temp_2_7 + 0x140);
            *(f32 *)(arg0 + 0x6F4) = *(f32 *)(temp_2_7 + 0x144);
            *(f32 *)(arg0 + 0x6F8) = *(f32 *)(temp_2_7 + 0x148);
            *(f32 *)(arg0 + 0x6FC) = *(f32 *)(temp_2_7 + 0x14C);
            *(f32 *)(arg0 + 0x700) = *(f32 *)(temp_2_7 + 0x150);
            *(f32 *)(arg0 + 0x704) = *(f32 *)(temp_2_7 + 0x154);
            *(f32 *)(arg0 + 0x708) = *(f32 *)(temp_2_7 + 0x158);
            *(f32 *)(arg0 + 0x70C) = *(f32 *)(temp_2_7 + 0x15C);
            var_7 = temp_2_7 + 0x160;
            var_6 = arg0 + 0x710;
            var_5 = 8;
loop_9_copy:
            temp_4 = *(s32 *)var_7;
            temp_3 = *(s32 *)(var_7 + 4);
            var_7 += 8;
            var_5--;
            *(s32 *)var_6 = temp_4;
            *(s32 *)(var_6 + 4) = temp_3;
            var_6 += 8;
            if (var_5 > 0)
                goto loop_9_copy;
        }
    }
}
