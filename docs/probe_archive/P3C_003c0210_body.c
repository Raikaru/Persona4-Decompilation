/* func_003c0210 archive: best reconstruction object 196B/window 208B,
   normalized_diff 23. Census is clean (same four calls), float block is
   register-coloured differently (retail loads f3 first from +4); declaration,
   load-order, store-order, condition-nesting, and hoist probes were ruled out
   (480-variant permutation sweep floor at nd 23). No real C body retained;
   bare INCLUDE_ASM fallback remains. See build/P3C_003c0210_body.c. */
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c0210(u8 *arg0, u8 *arg1, s32 arg2) {
    extern void func_003c2a60(u8 *arg0);
    extern void func_003c2a80(u8 *arg0);
    extern s32 func_003cbce0(s32 arg0);
    extern void func_003e9680(u8 *arg0);
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f0;
    u8 *temp;
    u8 *temp_2;

    if (arg1 == *(u8 **)(arg0 + 0x18)) {
        goto end;
    }
    if (arg1 != NULL) {
        func_003c2a60(arg1);
    }
    temp = *(u8 **)(arg0 + 0x18);
    if (temp != NULL) {
        func_003c2a80(temp);
    }
    *(u8 **)(arg0 + 0x18) = arg1;
    if ((arg2 & 1) == 0) {
        if (arg1 != NULL) {
            temp_2 = *(u8 **)(arg1 + 0x5C);
            f0 = *(f32 *)(temp_2 + 0x10);
            f1 = *(f32 *)(temp_2 + 0xC);
            f3 = *(f32 *)(temp_2 + 4);
            f2 = *(f32 *)(temp_2 + 8);
            *(f32 *)(arg0 + 0x1C) = f3;
            *(f32 *)(arg0 + 0x20) = f2;
            *(f32 *)(arg0 + 0x28) = f0;
            *(f32 *)(arg0 + 0x24) = f1;
        }
    }
    temp = *(u8 **)(arg0 + 4);
    if (temp == NULL) {
        goto end;
    }
    if (func_003cbce0((s32)arg0) != 0) {
        func_003e9680(temp);
    }
end:
    return arg0;
}
