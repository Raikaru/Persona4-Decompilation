// FUN_001E7400 NONMATCHING
#ifdef NON_MATCHING
s32 func_001e7400(void) {
    extern s32 func_001d9390();
    extern u32 func_00231d70(u32 arg0);
    extern s32 func_0029cc00(s32 arg0);
    extern void func_0029cf50(s32 arg0);
    extern u8 *func_0029d050(void);
    extern void func_001db8d0();
    u8 *temp_16;
    s32 temp_6;
    s32 var_7;
    u8 *temp_5;
    s32 temp_3;
    u8 *sp20[12];
    u8 *var_2;

    temp_16 = func_0029d050();
    temp_6 = func_001d9390(temp_16, func_0029cc00(0), 0x80000, 1, 1, &func_001db8d0, sp20) & 0xFFFF;
    if (temp_6 > 0) {
        var_7 = 0;
        temp_5 = iGpffffb3ac;
        goto loop_test;
loop_body:
        temp_3 = var_7 & 0xFFFF;
        if (*(s32 *)(temp_5 + 0x170) != *(s32 *)&sp20[(u16)var_7]) {
            var_7 = (var_7 + 1) & 0xFFFF;
            goto loop_test;
        }
        goto select;
loop_test:
        temp_3 = var_7 & 0xFFFF;
        if (temp_3 < temp_6)
            goto loop_body;
select:
        if (temp_3 == temp_6) {
            var_2 = sp20[func_00231d70(temp_6 & 0xFFFF)];
        } else {
            var_2 = *(u8 **)(temp_5 + 0x170);
        }
        func_0029cf50(*(s32 *)(var_2 + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e7400);
#endif
