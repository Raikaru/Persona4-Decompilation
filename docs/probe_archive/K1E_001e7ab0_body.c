/* CLOSED: func_001e7ab0 matches with u16 var_17 and fused sp60[var_17++] (daddiu reset plus unmasked-counter addiu); prior s32 floor is retired. */
s32 func_001e7ab0(void) {
    extern s32 func_001dbba0();
    extern void func_001db5b0();
    extern s32 func_00231d70();
    extern s32 func_00231e20();
    extern s64 func_0029cc00();
    extern void func_0029cf50();
    extern u8 *func_0029d050();
    u8 *temp_20;
    u32 var_19;
    u32 var_18;
    s32 var_17;
    u8 *temp_16;
    u32 temp_3;
    u8 *sp60[12];
    u8 *var_2;

    temp_20 = func_0029d050();
    if (func_001dbba0(temp_20, func_0029cc00(0), 0, 0x2C, 1, &func_001db5b0) == 1) {
        if (*(u16 *)(temp_20 + 0x6A) == 1) {
            var_2 = *(u8 **)(temp_20 + 0x38);
        } else {
            var_17 = 0;
            var_18 = 0;
            var_19 = 0;
            goto loop_test;
loop_body:
            temp_16 = *(u8 **)(temp_20 + var_19 * 4 + 0x38);
            temp_3 = (u32)(func_00231e20(*(s32 *)(*(u8 **)(temp_16 + 0x30) + 0xA64)) & 0xFF);
            if (temp_3 >= var_18) {
                if (temp_3 == var_18) {
                    sp60[var_17 & 0xFFFF] = temp_16;
                    var_17 = (var_17 + 1) & 0xFFFF;
                } else {
                    var_18 = temp_3;
                    sp60[0] = temp_16;
                    var_17 = 1;
                }
            }
            var_19 += 1;
loop_test:
            if (var_19 < *(u16 *)(temp_20 + 0x6A))
                goto loop_body;
            var_2 = sp60[func_00231d70(var_17 & 0xFFFF)];
        }
        func_0029cf50(*(s32 *)(var_2 + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return -1;
}
