/* ABI-corrected reference candidate; NOT MATCHING.
 * Measured: object 596B / retail 592B, 26 differing words after relocation
 * masking. The extra move $a0,$s0 before the deallocator shifts the tail.
 * The former two-word floor omitted the real child argument to
 * func_00286c60, whose existing definition takes (u8 *, u8 *).
 * Passing a dedicated child local closes those two words, but the old
 * zero-argument cast of jtbl_008873EC also omitted the allocation pointer.
 * Fixing both calls is mandatory even though retaining the invalid free
 * cast can score zero. Do not install that false match or weaken prototypes.
 * Pointer spelling, explicit allocation aliases, and propagation off leave
 * the correct deallocator call at the same 596B / nd26 floor.
 */

// FUN_0028AD90
void func_0028ad90(u8 *arg0, s32 arg1) {
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 *temp_2;
    s32 var_16;
    s32 *temp_16;
    u8 *child;

    func_0028f4f0();
    func_00293270();
    var_16 = 0;
    goto loop_6_test;
loop_6_body:
    temp_2 = (s32 *)(arg0 + (var_16 * 4) + 0x6C4);
    temp_4 = *temp_2;
    if (temp_4 != 0) {
        if (func_00452490(temp_4) != 0) {
            func_00452080(*temp_2);
        }
        *temp_2 = 0;
    }
    var_16 += 1;
loop_6_test:
    if (var_16 < 3) {
        goto loop_6_body;
    }
    func_002e0dd0();
    func_00113500();
    func_0026d810();
    func_0028c370();
    if ((*(s32 *)(arg0 + 4) != 0) && (func_002909a0((u32 *)(arg0 + 0x678)) != 0)) {
        func_00290b00(arg0 + 0x678);
    }
    func_0028d0a0(arg0);
    func_00298190(2, 0);
    temp_4_2 = (s32)(*(s32 *)(arg0 + 0x760));
    if ((temp_4_2 != 0) && (func_00452490(temp_4_2) != 0)) {
        func_00452080(*(s32 *)(arg0 + 0x760));
        *(s32 *)(arg0 + 0x760) = 0;
    }
    temp_4_3 = (s32)(*(s32 *)(arg0 + 0x768));
    if ((temp_4_3 != 0) && (func_00452490(temp_4_3) != 0)) {
        func_00452080(*(s32 *)(arg0 + 0x768));
        *(s32 *)(arg0 + 0x768) = 0;
    }
    if (arg1 != 0) {
        func_00459880();
    }
    temp_4_4 = (s32)(*(s32 *)(arg0 + 0x75C));
    if (temp_4_4 != 0) {
        func_00452080(temp_4_4);
        *(s32 *)(arg0 + 0x75C) = 0;
    }
    if (arg0 == NULL) {
        func_0046d730(D_0063C3B0, 0xF4);
    }
    func_00291900();
    func_002919e0();
    func_00290fa0(*(s32 *)(arg0 + 0x5D0));
    *(s32 *)(arg0 + 0x5D0) = 0;
    goto loop_27_test;
loop_27_body:
    temp_16 = *(s32 **)(arg0 + 0x4C);
    goto loop_25_test;
loop_25_body:
    func_00286c60((u8 *)temp_16, child);
loop_25_test:
    if ((child = *(u8 **)(temp_16 + 0x1A)) != 0) {
        goto loop_25_body;
    }
    func_00286e90((int)temp_16, (int)arg0);
    jtbl_008873EC[0](temp_16);
    func_002852a0(7, -0x98);
loop_27_test:
    temp_16 = *(s32 **)(arg0 + 0x4C);
    if (temp_16 != NULL) {
        goto loop_27_body;
    }
    temp_4_5 = (s32)(*(s32 *)(arg0 + 4));
    if (temp_4_5 != 0) {
        func_00290470(temp_4_5, arg0 + 0x678);
        *(s32 *)(arg0 + 4) = 0;
    }
}
