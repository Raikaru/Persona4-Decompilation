/* Closest non-matching reconstruction archived before reverting to INCLUDE_ASM. */
void func_0045d6e0(u8 *arg0, u8 *arg1, s32 arg2, f32 farg0) {
    u8 work[0x130];
    f32 x0;
    f32 x1;
    f32 x2;
    f32 x3;
    f32 angle;
    u32 i;
    u32 j;
    s32 *state;
    s32 *restore_state;

    angle = farg0;
    x2 = *(f32 *)arg1;
    x3 = *(f32 *)(arg1 + 4);
    x0 = *(f32 *)(arg1 + 8);
    x1 = *(f32 *)(arg1 + 0xC);
    *(f32 *)(work + 0x120) = x2;
    *(f32 *)(work + 0x124) = x3;
    *(f32 *)(work + 0x128) = x0;
    *(f32 *)(work + 0x12C) = x1;
    if (arg2 != 0) {
        for (i = 0; i < 6; i++) {
            state = &D_00712490[i * 2];
            D_00887304[0](state[0], work + i * 4);
            D_00887300[0](state[0], state[1]);
        }
        D_00887300[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
    }
    memset(work + 0x20, 0, 0x100);
    func_0045ce40((f32 *)(work + 0x20), arg0, (s32 *)(work + 0x120), angle);
    D_00887310[0](4, work + 0x20, 4);
    if (arg2 != 0) {
        for (j = 0; j < 6; j++) {
            restore_state = &D_00712490[j * 2];
            D_00887300[0](restore_state[0], *(s32 *)(work + j * 4));
        }
    }
}
