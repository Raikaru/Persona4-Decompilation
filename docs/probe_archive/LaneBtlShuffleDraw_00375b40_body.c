/*
 * Probe archive: LaneBtlShuffleDraw / func_00375b40
 *
 * Candidate measurement (MWCCPS2 b210 -O2): object 512B, retail window 528B.
 * normalized_diff: 264 bytes (88 differing words, relocations masked).
 * Differing word-offset ranges: 0x030-0x03f, 0x0b0, 0x0b8,
 * 0x0c0-0x10b, 0x110-0x1d3, 0x1d8-0x1ff.
 *
 * COP1 accumulator result: YES. Plain C emitted all 21/21 retail-chain
 * operation slots (mula/madda/madd, mula/msub x3, adda/madd x6); the
 * candidate's operation count and fused forms are present. The residual is
 * ordinary: FPR load/register coloring, dispatch block orientation, global
 * load/store scheduling, and the resulting shifted tail—not a COP1 floor.
 *
 * Ruled out by scoped probes: direct || spelling; negated && spelling;
 * nested else-if spelling; explicit forward-goto and explicit-else dispatch
 * layouts; named f32 arithmetic temporaries; scalar staging of the two global
 * inputs; #pragma opt_rebuildconditionals off; #pragma opt_propagation off.
 * These either preserved the same residual or made the object larger/different.
 * No probe pragma is retained in the source.
 */
void func_00375b40(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    ShuffleVec2s tmp;
    ShuffleVec4 rotation;
    ShuffleVec4 output;
    s64 global_a;
    f32 global_b;
    s32 state;
    s32 active;
    u8 *p;

    global_a = D_0064EA48[0];
    global_b = D_0064EA50[0];
    tmp.a = global_a;
    tmp.b = global_b;
    if (arg1 >= func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC))) {
        func_0046d730(D_0064EA20, 0x3E9);
    }
    p = (u8 *)(arg0 + arg1 * 0xE8 + 0x1D6A0);
    state = *(s32 *)(p + 8);
    if (state == 3) {
        goto active_true;
    }
    if (state == 0) {
        goto active_true;
    } else {
        goto check_count;
    }
active_true:
    active = 1;
    goto active_done;
check_count:
    if (*(u16 *)(p + 0x6C) < *(u16 *)(p + 0x6E)) {
        goto inactive;
    }
    active = 1;
    goto active_done;
inactive:
    active = 0;
active_done:
    if (active != 0) {
        func_003dc740(&rotation, &tmp, 0, 180.0f);
        output.w = *(f32 *)(p + 0x80) * rotation.w
            - ((*(f32 *)(p + 0x78) * rotation.y + *(f32 *)(p + 0x74) * rotation.x)
                + *(f32 *)(p + 0x7C) * rotation.z);
        output.x = *(f32 *)(p + 0x78) * rotation.z - *(f32 *)(p + 0x7C) * rotation.y;
        output.y = *(f32 *)(p + 0x7C) * rotation.x - *(f32 *)(p + 0x74) * rotation.z;
        output.z = *(f32 *)(p + 0x74) * rotation.y - *(f32 *)(p + 0x78) * rotation.x;
        output.x = output.x + rotation.x * *(f32 *)(p + 0x80);
        output.y = output.y + rotation.y * *(f32 *)(p + 0x80);
        output.z = output.z + rotation.z * *(f32 *)(p + 0x80);
        output.x = output.x + *(f32 *)(p + 0x74) * rotation.w;
        output.y = output.y + *(f32 *)(p + 0x78) * rotation.w;
        output.z = output.z + *(f32 *)(p + 0x7C) * rotation.w;
        func_003760f0(arg0, arg1, arg2, arg3, 0, (f32 *)&output);
    }
}
