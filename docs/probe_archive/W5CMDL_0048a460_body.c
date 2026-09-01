/* object 176B / window 176B / normalized_diff 34; residual is FP register assignment and arithmetic sequence from +0x54 through +0x8C; prologue, globals, call setup, stores, and tail match. */
f32 *func_0048a460(void)
{
    u8 raw[0x30];
    f32 sp34;
    f32 sp38;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s32 sp1C;
    s32 sp18;
    f32 sp14;
    f32 sp10;

    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(&D_00713D10)
        : "$vf10", "memory");
    *(f32 *)(raw + 0x10) = D_00713D10[0];
    *(f32 *)(raw + 0x14) = D_00713D14[0];
    *(f32 *)(raw + 0x18) = D_00713D18[0];
    func_003e42a0(raw + 0x20, raw + 0x10,
                  mdlEffect_camera_matrix(func_00457120()));
    sp38 = *(f32 *)(raw + 0x28);
    sp30 = *(f32 *)(raw + 0x20);
    sp10 = 640.0f * (sp30 / sp38);
    sp34 = *(f32 *)(raw + 0x24);
    sp14 = 448.0f * (sp34 / sp38);
    *(f32 *)(raw + 0x0) = sp10;
    *(f32 *)(raw + 0x4) = sp14;
    sp18 = 0;
    sp1C = 0;
    *(s32 *)(raw + 0x8) = sp18;
    *(s32 *)(raw + 0xC) = sp1C;
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw)
        : "$vf10", "memory");
    return (f32 *)raw;
}
