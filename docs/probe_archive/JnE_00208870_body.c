/*
 * Probe archive: func_00208870 (lane JnE)
 * Object/window: 364B / 368B
 * Normalized diff: 10 (fndiff differing words: 9)
 * First differing byte offsets: 169, 172, 173, 177, 178, 242, 257, 261, 265, 302
 *
 * The COP1 accumulator chain itself is reproduced by plain C: the natural
 * multiply-fed expressions emit mula.s/msub.s and madd.s without pragmas,
 * intrinsics, or inline assembly. This residual is ordinary FP register
 * coloring (retail curve in f3 and zero in f12; candidate curve in f4 and
 * zero in f3), not a COP1 expressibility floor.
 *
 * Ruled out in this probe: early-return versus positive-body comparison
 * spellings; reversed comparison operands; declaration-order permutations;
 * explicit multiply intermediates; reused zero locals; opt_propagation,
 * opt_common_subs, opt_loop_invariants, opt_rebuildconditionals,
 * optimization_level, schedule, and no_branch_likely pragmas. The pragmas
 * were removed after measurement. The source target was restored to its
 * INCLUDE_ASM fallback because the body did not close.
 */

void func_00208870(u8 *unused, u8 *arg1, f32 *arg2)
{
    s32 values[4];
    Color4 color;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f3;
    f32 temp_f4;

    func_002012d0(func_00452560(*(s32 *)(arg1 + 0x5B0)), arg2[0], arg2[1]);
    temp_f0 = (f32)*(s16 *)(arg1 + 0xE) / 2.0f;
    if (temp_f0 > 1.0f) {
        temp_f1 = 1.0f;
    } else if (temp_f0 < 0.0f) {
        temp_f1 = 0.0f;
    } else {
        temp_f1 = temp_f0;
    }
    temp_f3 = temp_f1 * 2.0f - temp_f1 * temp_f1;
    if (temp_f3 <= 0.0f) {
        return;
    }
    color.c0 = 0xB4;
    color.c1 = 0;
    color.c2 = 0;
    color.c3 = 0xFF;
    values[0] = -10;
    temp_f4 = (1.0f - temp_f3) * 11.0f + 410.0f;
    values[1] = (s32)temp_f4;
    values[2] = 0x294;
    values[3] = (s32)(temp_f3 * 22.0f);
    func_0045d6e0((u8 *)&color, (f32 *)values, temp_f4, 0);
}
