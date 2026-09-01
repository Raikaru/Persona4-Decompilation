/* Closest non-matching reconstruction archived before reverting to INCLUDE_ASM. */
void func_0045d890(void *unused, u8 *arg1) {
    struct {
        s32 c0;
        f32 c1;
        f32 c2;
        f32 c3;
        s32 saved[6];
        u8 pad[8];
        f32 output[60];
        u8 tail[0x10];
    } work;
    f32 angle;
    s32 flag;
    u32 i;
    u32 j;
    s32 *state;
    f32 x0;
    f32 x1;
    f32 x2;
    f32 x3;

    x0 = *(f32 *)(arg1 + 4);
    x1 = *(f32 *)(arg1 + 8);
    x2 = *(f32 *)(arg1 + 0xC);
    x3 = *(f32 *)(arg1 + 0x10);
    *(f32 *)&work.c0 = x0;
    work.c1 = x1;
    work.c2 = x2;
    work.c3 = x3;
    angle = *(f32 *)(arg1 + 0x14);
    flag = *(s32 *)(arg1 + 0x18);
    if (flag != 0) {
        for (i = 0; i < 6; i++) {
            state = &D_00712490[i * 2];
            D_00887304[0](state[0], &work.saved[i]);
            D_00887300[0](state[0], state[1]);
        }
        D_00887300[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
    }
    func_0045ce40(work.output, arg1, &work.c0, angle);
    D_00887310[0](4, work.output, 4);
    if (flag != 0) {
        for (j = 0; j < 6; j++) {
            D_00887300[0](D_00712490[j * 2], work.saved[j]);
        }
    }
    jtbl_008873EC[0](arg1);
}
