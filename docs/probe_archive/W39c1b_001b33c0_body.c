/*
 * LANE: W39c1b
 * FILE: src/promoted/code1_001b.c
 * FUNCTION: func_001b33c0
 * BEST MEASURED: object 716B / retail window 752B, normalized_diff 150
 * Compiler: MWCCPS2 3.0.1 b210 -O2
 * Differing offsets: prologue register allocation (s0/s1/s3/s4 swap),
 *   s6 condition computation, func_0019b550 argument load (lh vs lhu),
 *   loop control/branch layout, func_001f6710 predicate materialization.
 * Levers tried: translation from generated m2c with D_0076449C/D_00764640;
 *   u8* pointer-arithmetic fields; while loops; explicit s6 variable;
 *   s16 and u16 arg prototypes for func_0019b550.
 * Floor suspected: register-colouring / prologue assignment order for the
 *   multi-packet linked-list loop (s6/s0/s4/s3 allocation not reproducible
 *   with the attempted declaration orders).
 */

void func_001b33c0(void)
{
    extern u8 *func_0019b550(u8 *arg0, s16 arg1, s16 arg2);
    extern u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
    extern u8 *func_001d7880(void);
    extern u8 *func_00202b60(s32 arg0);
    extern u8 *func_001f6710(s32 arg0);
    extern s32 D_00764640;
    u8 *var_16;
    u8 *var_5;
    u32 var_4;
    s32 var_21;
    s64 var_17;
    s64 var_18;
    s32 s6;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    s32 temp_4;
    s32 var_2;
    s16 var_4_2;

    var_21 = 1;
    var_18 = 0;
    var_17 = 0;
    var_4 = 0;
    var_16 = *(u8 **)(D_0076449C + 0x180);
    var_5 = var_16;
    while (var_5 != NULL) {
        var_4 = (var_4 + 1) & 0xFFFF;
        var_5 = *(u8 **)(var_5 + 0xA6C);
    }
    s6 = (var_4 < 4) + 1;
    while (var_16 != NULL) {
        temp_2 = func_0019b550(var_16, *(u16 *)(var_16 + 0xA4), 0x3E);
        *(s8 *)(temp_2 + 0) = 4;
        *(s64 *)(temp_2 + 8) = var_18;
        func_00194590(temp_2, 1);
        var_18 = *(s64 *)(temp_2 + 0x58);
        if (!(*(s32 *)(D_0076449C + 0x10) & 1)) {
            temp_2_2 = func_001d65d0(D_00764640, (s32)var_16, 0, 0, 0);
            var_4_2 = 4;
            *(s8 *)(temp_2_2 + 0) = 4;
            *(s64 *)(temp_2_2 + 8) = *(s64 *)(temp_2 + 0x58);
            if (var_21 == 1) {
                *(s16 *)(temp_2_2 + 0x48) = 1;
            } else {
                *(s8 *)(temp_2_2 + 0x10) = 5;
                *(s64 *)(temp_2_2 + 0x18) = var_17;
                if (s6) {
                    var_4_2 = 8;
                }
                *(s16 *)(temp_2_2 + 0x48) = var_4_2;
            }
            func_00194590(temp_2_2, 2);
            var_17 = *(s64 *)(temp_2_2 + 0x58);
            temp_2_3 = (u8 *)func_0019bbe0((BtlUnit *)var_16, 0xFFFFFFFF, 0xC, 0, 3, 1);
            *(s8 *)(temp_2_3 + 0) = 4;
            *(s64 *)(temp_2_3 + 8) = *(s64 *)(temp_2 + 0x58);
            *(s8 *)(temp_2_3 + 0x10) = 5;
            *(s64 *)(temp_2_3 + 0x18) = var_17;
            *(s16 *)(temp_2_3 + 0x48) = 0x1D;
            func_00194590(temp_2_3, 1);
        } else {
            temp_2_4 = (u8 *)func_0019bbe0((BtlUnit *)var_16, 0xFFFFFFFF, 0, 0, 3, 1);
            *(s8 *)(temp_2_4 + 0) = 4;
            *(s64 *)(temp_2_4 + 8) = *(s64 *)(temp_2 + 0x58);
            *(s16 *)(temp_2_4 + 0x48) = 2;
            func_00194590(temp_2_4, 1);
            var_17 = *(s64 *)(temp_2_4 + 0x58);
        }
        var_21 = 0;
        var_16 = *(u8 **)(var_16 + 0xA6C);
    }
    temp_4 = *(s32 *)(D_0076449C + 0xC);
    if (!(temp_4 & 0x20000000)) {
        temp_2_5 = func_001d7880();
        *(s8 *)(temp_2_5 + 0) = 4;
        *(s64 *)(temp_2_5 + 8) = var_18;
        func_00194590(temp_2_5, 1);
        temp_2_6 = func_00202b60(*(s32 *)(D_0076449C + 0xDD4));
        *(s8 *)(temp_2_6 + 0) = 4;
        *(s64 *)(temp_2_6 + 8) = *(s64 *)(temp_2_5 + 0x58);
        func_00194590(temp_2_6, 1);
        if (func_00106330(0x38) != 0) {
            var_2 = 1;
        } else {
            var_2 = 0;
        }
        temp_2_7 = func_001f6710(var_2 & 0xFFFF);
        *(s8 *)(temp_2_7 + 0) = 4;
        *(s64 *)(temp_2_7 + 8) = *(s64 *)(temp_2_6 + 0x58);
        func_00194590(temp_2_7, 1);
    }
}
