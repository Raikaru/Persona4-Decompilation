/* object 964B / window 896B; normalized_diff 621; differing offsets 69,74,76,86-98,100-101,...; corrected block prototypes: 2970(u8*,f32,f32), 2a60(u8*,s32,s32,s32,s32), 6140(u8*,u8), 6150(s16), 6a70(s16,u32,u32,u32,u32,s32), 6c30(s16,f2,s32,f32); probed canonical helper widths; remaining s16 argument-normalization floor. */
// FUN_003205F0
void func_003205f0(u8 *arg0, s64 arg1, s64 arg2) {
    extern void func_002b2970(u8 *, f32, f32);
    extern void func_002b6c30(s16, f2, s32, f32);
    extern void func_002b6a70(s16, u32, u32, u32, u32, s32);
    extern void func_002b2a60(u8 *, s32, s32, s32, s32);
    extern u8 *func_002b6150(s16);
    extern void func_002b6140(u8 *, u8);
    f32 spAD;
    f32 spAE;
    f32 spAF;
    u4 spAC;
    f2 spA0;
    f2 sp98;
    f2 sp90;
    f2 sp88;
    f2 sp80;
    f2 sp78;
    f2 sp70;
    f2 sp68;
    f2 sp60;
    f2 sp58;
    f2 sp50;
    s64 temp_16_3;
    s64 temp_17;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_17_2;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_002b6140(*(u8 **)(temp_16 + 0x28C), 0);
    func_002b6140(*(u8 **)(temp_16 + 0x290), 0);
    temp_17 = (s64) (arg1 << 0x30) >> 0x30;
    if (temp_17 != 0) {
        temp_16_2 = (u8 *)((s32)&D_00643D70 + (temp_17 * 8));
        func_002b2970((u8 *)&spA0, *(f32 *)(temp_16_2 + 0) - 200.0f, *(f32 *)(temp_16_2 + 4));
        func_002b6c30(arg1, spA0, 0xAC, 54.0f);
        func_002b2970((u8 *)&sp98, *(f32 *)(temp_16_2 + 0) - 200.0f, *(f32 *)(temp_16_2 + 4));
        func_002b2970((u8 *)&sp90, *(f32 *)(temp_16_2 + 0), *(f32 *)(temp_16_2 + 4));
        func_002b69f0(arg1, sp98, sp90, 0, 0xA, 0);
        func_002b6a70(arg1, 0U, 0xFFU, 0, 0xA, 0);
        if (temp_17 == 0x92) {
            func_002b2970((u8 *)&sp88, *(f32 *)(D_00644CA0 + 0), *(f32 *)(D_00644CA0 + 4));
            func_002b6c30(0x1E6, sp88, 0x65, 54.0f);
            func_002b2970((u8 *)&sp80, 58.0f, *(f32 *)(D_00644CA0 + 4));
            func_002b2970((u8 *)&sp78, *(f32 *)(D_00644CA0 + 0), *(f32 *)(D_00644CA0 + 4));
            func_002b69f0(0x1E6, sp80, sp78, 0, 0xA, 3);
            func_002b6a70(0x1E6, 0U, 0xFFU, 0, 0xA, 3);
            func_002b2a60((u8 *)&spAC, 0x49, 0x72, 0xFF, 0xFF);
            temp_2 = func_002b6150(0x1E6);
            temp_2[0x85] = spAC.b0;
            temp_2[0x86] = spAC.b1;
            temp_2[0x87] = spAC.b2;
            temp_2[0x88] = spAC.b3;
        }
    }
    temp_16_3 = (s64) (arg2 << 0x30) >> 0x30;
    if (temp_16_3 != 0) {
        temp_17_2 = (u8 *)((s32)&D_00643D70 + (temp_16_3 * 8));
        func_002b2970((u8 *)&sp70, *(f32 *)(temp_17_2 + 0), *(f32 *)(temp_17_2 + 4));
        func_002b6c30(arg2, sp70, 0xAC, 54.0f);
        func_002b2970((u8 *)&sp68, *(f32 *)(temp_17_2 + 0), *(f32 *)(temp_17_2 + 4));
        func_002b2970((u8 *)&sp60, 200.0f + *(f32 *)(temp_17_2 + 0), *(f32 *)(temp_17_2 + 4));
        func_002b69f0(arg2, sp68, sp60, 0, 0xA, 0);
        func_002b6a70(arg2, 0xFFU, 0U, 0, 0xA, 0);
        if (temp_16_3 == 0x92) {
            func_002b2970((u8 *)&sp58, *(f32 *)(D_00644CA0 + 0), *(f32 *)(D_00644CA0 + 4));
            func_002b2970((u8 *)&sp50, 122.0f, *(f32 *)(D_00644CA0 + 4));
            func_002b69f0(0x1E6, sp58, sp50, 0, 6, 2);
            func_002b6a70(0x1E6, 0xFFU, 0U, 0, 6, 2);
        }
    }
}

