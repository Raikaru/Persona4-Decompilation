/* remeasured 2026-08-14: object 532B/window 544B, normalized_diff 8; differing byte offsets 234, 238, 249, 253, 254, 258, 262, 270 (word rows 232, 236, 248, 252, 256, 260, 268; relocation fields masked), with a 12B zero tail. Retail keeps D_008E4090 in $v1 and the sign-extended slot index in $a0; candidate uses $a0/$v1. Re-probed pointer construction split/base-first split, slot-index inlining, declaration and initialization order, pointer/base type, callee prototype/variadic forms, and direct-global shapes: nd stayed 8 or worsened. The file's arg1/u16 lever does not apply to this void function; corrected func_0043c008 ABI remains a known nd344 regression when its caller argument is removed. */
void func_0045b430(void) {
    s32 var_3;
    s32 var_5;
    s64 slot_index;
    s32 next;
    u8 *temp_2;

    func_00430e28();
    func_0043c008(0);
    func_0043c010(0x20);
    func_0043bb70(D_008E4230, 0x20, 0);
    func_0043c0c0(0, 0x8F, 0);
    func_0043c0c0(3, 0x83, 0x105, 0x3C, 0);
    func_0043c0c0(3, 0x84, 0x3C, 0x3C);
    func_0043c0c0(3, 0x82, 1);
    func_00430f80(1, 0x8010, 0x800, 0xFC0);
    func_00430f80(1, 0x8010, 0x801, 0xFCC);
    func_0043c0c0(3, 0x80, 0x7F, 0x7F);
    var_5 = 0;
    var_3 = (s32)D_008E4090;
    goto loop_0045b430_slot_test;
loop_0045b430_slot_body:
    slot_index = (s32)(s16)var_5;
    temp_2 = (u8 *)((u32)var_3 + (u32)((s32)slot_index * 0x44));
    *(s16 *)(temp_2 + 0) = 0;
    *(s32 *)(temp_2 + 4) = 0;
    *(s32 *)(temp_2 + 0x18) = 0;
    *(s16 *)(temp_2 + 0xA) = (s16)var_5;
    next = (s32)var_5 + 1;
    var_5 = (s64)(s16)next;
loop_0045b430_slot_test:
    if ((s16)var_5 < 6) {
        goto loop_0045b430_slot_body;
    }
    var_3 = 0;
    D_008E4018_abs[0] = 0;
    goto loop_0045b430_count_test;
loop_0045b430_count_body:
    next = (s32)var_3 + 1;
    var_3 = (s64)(s16)next;
loop_0045b430_count_test:
    if ((s16)var_3 < 0x10) {
        goto loop_0045b430_count_body;
    }
    D_008E40B4_abs[0] = func_0043bcb8(0x64000, var_5);
    D_008E40F8_abs[0] = func_0043bcb8(0xE1000);
    D_008E413C_abs[0] = func_0043bcb8(0x19000);
    D_008E4180_abs[0] = func_0043bcb8(0x19000);
    D_008E41C4_abs[0] = func_0043bcb8(0x19000);
    D_008E4208_abs[0] = func_0043bcb8(0x19000);
}