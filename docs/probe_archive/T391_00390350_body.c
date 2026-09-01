/* object 428B / window 432B / normalized_diff 81; differing offsets 0x2C, 0x5C, 0xDC-0xF0, 0xFC-0x104, 0x134-0x1AC; one-instruction deficit. Classification: structurally correct frame/locals and main path, residual branch-target/layout and default-path load/store order; final retail movz at 0x003904C4 is a conditional-move floor. Ruled out: scalar-vs-array stack layout (array gives exact 0x70 frame), reversed integer declaration order, no_branch_likely off/on, positive guard polarity, saved-argument lifetime copy. Prologue: frame 0x70, saved s0/s1/s2 (3), incoming a0/a2/a3 with a1 scratch. Block-scope declarations: func_003df050(s32,s32,s32,s32), func_0038fd30(s32), func_0038fe90(s32,s32,s32,f32*,s32*). */

s32 func_00390350(s32 arg0, s32 unused, u8 *arg2, s32 arg3)
{
    f32 values[6];
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 saved_arg0;
    extern s32 func_003df050(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern u8 *func_0038fd30(s32 arg0);
    extern u8 *func_0038fe90(s32 arg0, s32 arg1, s32 arg2, f32 *arg3, s32 *arg4);
    u8 **out;
    u8 *base;

    saved_arg0 = arg0;
    out = (u8 **)(arg2 + arg3);
    if (func_003df360(arg0, &sp6C, 4) != 0) {
        if ((u32)sp6C < 0x36001U) {
            if (func_003df360(saved_arg0, &sp68, 4) != 0) {
                if (arg2[0] == 8) {
                    base = *(u8 **)(arg2 + 0x5C);
                    values[3] = *(f32 *)(base + 4) - *(f32 *)(base + 0x10);
                    values[4] = *(f32 *)(base + 8) - *(f32 *)(base + 0x10);
                    values[5] = *(f32 *)(base + 0xC) - *(f32 *)(base + 0x10);
                    values[0] = *(f32 *)(base + 4) + *(f32 *)(base + 0x10);
                    values[1] = *(f32 *)(base + 8) + *(f32 *)(base + 0x10);
                    values[2] = *(f32 *)(base + 0xC) + *(f32 *)(base + 0x10);
                } else {
                    values[0] = *(f32 *)(arg2 + 0x60);
                    values[1] = *(f32 *)(arg2 + 0x64);
                    values[2] = *(f32 *)(arg2 + 0x68);
                    values[3] = *(f32 *)(arg2 + 0x6C);
                    values[4] = *(f32 *)(arg2 + 0x70);
                    values[5] = *(f32 *)(arg2 + 0x74);
                }
                sp64 = 0;
                *out = func_0038fe90(saved_arg0, sp68, sp6C - 1, values, &sp64);
                if (sp64 != 0) {
                    return saved_arg0;
                }
                goto check_out;
            }
        } else if (func_003df050(saved_arg0, 44, 0, 0) != 0) {
            *out = func_0038fd30(saved_arg0);
            goto check_out;
        }
    }
    return 0;
check_out:
    return *out != NULL ? saved_arg0 : 0;
}
