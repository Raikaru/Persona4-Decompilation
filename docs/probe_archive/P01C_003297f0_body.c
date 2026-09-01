/* object 1028B / window 1616B / normalized_diff 648; differing offsets: first_diffs [0,4,8,10,12,14,16,18,20,22,23,24,25,26,27,28] then broad remainder; classification: initial reconstruction undersized and residual in the hundreds; likely ldr/ldl versus ld plus stack-slot/call-shape/allocation differences; existing declarations used: func_002b2970(void *, f32, f32), func_002b6c30(s16, s64, s32, f32), func_002b6150(s16), func_002b69f0(s16, f2, f2, u32, u32, s16); no further probing per automatic archive condition. */
void func_003297f0(u8 *arg0, s64 arg1, s32 arg2, f32 arg3, f32 arg4) {
    FclVec2 base;
    FclVec2 pos;
    FclVec2 q0;
    FclVec2 q1;
    FclVec2 q2;
    FclVec2 q3;
    FclVec2 q4;
    FclVec2 q5;
    FclByte4 color;
    u8 *p;
    s8 mode;
    s8 which;

    mode = (s8)arg2;
    which = (s8)arg1;
    func_002b2970(&base, arg3, D_006440B8[1]);
    if (mode == 0) {
        func_002b6c30(105, *(s64 *)&base, 86, 132.0f);
        func_002b2a60(&color, 73, 114, 255, 255);
        p = func_002b6150(105);
        *(FclByte4 *)(p + 0x85) = color;
        func_002b2970(&q0, base.x + arg4, D_006440B8[1]);
        func_002b2970(&q1, base.x, D_006440B8[1]);
        func_002b69f0(105, q0, q1, 0, 8, 0);
    } else {
        p = func_002b6150(105);
        func_002b2970(&q2, base.x + arg4, D_006440B8[1]);
        func_002b69f0(105, *(FclVec2 *)(p + 0x38), q2, 0, 8, 0);
    }
    func_002b2970(&pos, 17.0f + base.x, 9.0f + D_006440B8[1]);
    if (mode == 0) {
        switch (which) {
        case 0:
            func_002b2970(&pos, 67.0f + base.x, 13.0f + D_006440B8[1]);
            func_002b6c30(265, *(s64 *)&pos, 86, 134.0f);
            func_002b2970(&q3, pos.x + arg4, D_006440B8[1]);
            func_002b69f0(265, q3, pos, 0, 8, 0);
            func_002b2970(&pos, 95.0f + base.x, 15.0f + D_006440B8[1]);
            func_002b6c30(266, *(s64 *)&pos, 86, 133.0f);
            func_002b2970(&q4, pos.x + arg4, D_006440B8[1]);
            func_002b69f0(266, q4, pos, 0, 8, 0);
            break;
        case 1:
            func_002b2970(&pos, 114.0f + base.x, 11.0f + D_006440B8[1]);
            func_002b6c30(284, *(s64 *)&pos, 86, 134.0f);
            func_002b2970(&q5, pos.x + arg4, D_006440B8[1]);
            func_002b69f0(284, q5, pos, 0, 8, 0);
            func_002b2970(&pos, 50.0f + base.x, 16.0f + D_006440B8[1]);
            func_002b6c30(283, *(s64 *)&pos, 86, 133.0f);
            func_002b2970(&q0, pos.x + arg4, D_006440B8[1]);
            func_002b69f0(283, q0, pos, 0, 8, 0);
            break;
        }
    }
}
