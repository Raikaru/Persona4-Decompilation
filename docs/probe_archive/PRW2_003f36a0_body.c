/* object_size=164 window=176 normalized_diff=102 differing_offsets=16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160; classification=near-miss/unknown GP-global declarations and local declaration/order; direct D_007648FC/D_00764900/D_00764904 names compile but remain unresolved relocation placeholders, so object diverges at first global access; corrected block-scope callee func_003f2f40(u16,u16). Ruled out: movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, mixed-unit sd/sq floor. */
void func_003f36a0(s32 arg0)
{
    extern u16 D_007648FC;
    extern s32 *D_00764904;
    extern u16 D_00764900;
    extern void func_003f2f40(u16 arg0, u16 arg1);
    u16 temp_5;
    u16 temp_16;
    u16 temp_3;
    u16 var_3;
    u16 var_3_2;
    u16 temp_4;
    D_00764904[D_007648FC] = arg0;
    temp_5 = iGpffffabd4;
    var_3 = D_007648FC + 1;
    D_007648FC = var_3;
    if (D_007648FC == temp_5) {
        D_007648FC = 0;
        var_3 = 0;
    }
    temp_16 = var_3 & 0xFFFF;
    temp_3 = D_00764900;
    if (temp_3 == temp_16) {
        var_3_2 = temp_3 + (temp_5 >> 1);
        temp_4 = var_3_2 & 0xFFFF;
        D_007648FC = var_3_2;
        if (temp_4 >= temp_5) {
            var_3_2 = temp_4 - temp_5;
            D_007648FC = var_3_2;
        }
        func_003f2f40(temp_4, temp_5);
        D_00764900 = var_3_2;
        D_007648FC = temp_16;
    }
}
