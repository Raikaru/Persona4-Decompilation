/* object 916/864 normalized_diff 271 differing_offsets 320,544,545,547,548,549,551,552,553,554,555,556,557,558,560,561; classification oversized by 52 bytes (20-byte over window), prologue/frame right (112-byte frame, saved s2/s1/s0, one incoming arg), ruled out movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, sd-s; exact through first-loop body after explicit pretest layout, residual loop-width/branch layout. */
s32 func_002e7510(s32 arg0)
{
    extern u8 D_0063FC80[];
    extern u8 D_0063FC90[];
    extern u8 *(*D_008873F4[])(s32, s32, s32);
    extern void func_0044ea90(const void *, s32);
    extern s32 func_00451fc0(s32, const void *, s32, s32, s32, void *, void *, u8 *);
    extern void func_0045aac0(s16, s32, s32);
    extern s8 func_00106ac0(s16);
    extern s8 func_00106af0(s16);
    extern s32 func_00106b20(s16);
    extern s32 func_00106b50(s16);
    extern void func_00110810(s64, u8);
    extern s32 func_00110830();
    extern void func_002b29e0(void *, f32, f32);
    extern void func_002b2a60(void *, s32, s32, s32, s32);
    extern void *func_002b5c90(s32, s64);
    extern void func_002b5db0(s32, s64, void *);
    extern void func_002b5e30(s32, s32);
    extern s32 func_002be100(s32);
    extern s32 func_002e72c0(u8 *);
    extern void func_002e74e0(u8 *);
    s32 sp6C;
    s64 sp60;
    s64 sp58;
    u8 sp40[16];
    s32 temp_17;
    s8 temp_18;
    s8 temp_18_2;
    s64 var_16;
    s64 var_16_2;
    u8 *temp_2;
    func_0044ea90(D_0063FC80, 0x11A);
    temp_2 = D_008873F4[0](1, 0x18, 0x40000);
    temp_17 = func_00451fc0(arg0, D_0063FC90, 0xF, 0, 0, (void *)func_002e72c0, (void *)func_002e74e0, temp_2);
    iGpffffb590 = NULL;
    func_002b2970(&sp60, 0.0f, 0.0f);
    iGpffffb590 = (u8 *)func_002b5c90(temp_17, sp60);
    func_002b2970(&sp58, 0.0f, 0.0f);
    func_002b29e0(sp40, 640.0f, 448.0f);
    func_002b5db0((s32)iGpffffb590, sp58, sp40);
    func_002b2a60(&sp6C, 0, 0, 0, 0xFF);
    func_002b5e30((s32)iGpffffb590, sp6C);
    *temp_2 = 1;
    func_0045aac0(3, 0, 30);
    var_16 = 0;
    goto loop_8_test;
loop_8_body:
    if ((((func_00106b20((s16)var_16) & 0xFFF00) >> 8) == 0) && (((func_00106b50((s16)var_16) & 0xFFF00) >> 8) == 0)) {
        func_00110810(var_16, (func_00110830(var_16) & 0xFF) | 4);
    } else if ((func_00106b20((s16)var_16) & 0xFF) == 0 && (func_00106b50((s16)var_16) & 0xFF) == 0) {
        func_00110810(var_16, (func_00110830(var_16) & 0xFF) | 4);
    }
    var_16 = (s32)var_16 + 1;
loop_8_test:
    if (var_16 < 0x2FF) goto loop_8_body;
    var_16_2 = 0x300;
    goto loop_16_test;
loop_16_body:
    temp_18 = (s8)(func_002be100(func_00106ac0((s16)var_16_2) & 0xFF) & 0xFF);
    if (temp_18 < (func_002be100(4) & 0xFF)) {
        func_00110810(var_16_2, (func_00110830(var_16_2) & 0xFF) | 4);
    } else {
        temp_18_2 = (s8)(func_002be100(func_00106ac0((s16)var_16_2) & 0xFF) & 0xFF);
        if (temp_18_2 == (func_002be100(4) & 0xFF) && (s8)func_00106af0((s16)var_16_2) < 2)
            func_00110810(var_16_2, (func_00110830(var_16_2) & 0xFF) | 4);
    }
    var_16_2 = (s32)var_16_2 + 1;
loop_16_test:
    if (var_16_2 < 0x3FF) goto loop_16_body;
    return temp_17;
}
