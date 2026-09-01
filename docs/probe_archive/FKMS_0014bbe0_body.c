/* FAMILY OR-destination colouring floor with func_004633f0 (see build/PC463_004633f0_body.c): object 432B / window 432B / normalized_diff 4; differing offsets 0x11C, 0x120, 0x15C, 0x160. Exact residual: candidate `or $v0,$v1,$v0` + `mtc1 $v0,$f0`; retail `or $v1,$v1,$v0` + `mtc1 $v1,$f0`, repeated in both negative-alpha arms. Four hypothesis lanes failed in both: hidden return (both already return s32; this function's s32/u32 return probes nd 4), early live return local (existing `task` is live from before the first OR through the final return; a renamed ret_value local also nd 4), first-operand destination (`half |= argN & 1`; nd 4), and extending an existing local lifetime/post-mtc1 read (nd 4). Earlier exhausted probes include inline helpers, separate shifted/OR locals, signed/unsigned/int/narrow/wide half temporaries, declaration-order/types, direct casts, shared-arm variants, hidden-return/task-local and callee prototypes/return types, overlapping lifetimes, guard/parameter/literal/storage/knob variants, single-exit/goto (nd 275, object 420B), reversed operands (nd 20), typed ORs, named result/conversion locals, distinct arms, post-mtc1 reads, and typed post-mtc1 (object 528B, nd 190). Retail 0014bbe0 has two distinct negative-arm blocks, so no shared OR/mtc1 block exists to recover. Best retained C is exact-size nd 4; source remains bare INCLUDE_ASM. */
s32 func_0014bbe0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 half;
    RwRGBA color;
    u8* rgba;
    f32 target;
    f32 current;
    s32 task;
    RmdFadeWork* work;

    rgba = func_0047a250((void*)arg1);
    color = *(RwRGBA *)rgba;
    if (arg1 == 0) {
        return 0;
    }
    func_0044ea90(D_005EFB28, 0x1C6);
    work = (RmdFadeWork*)D_008873F4[0](1, sizeof(RmdFadeWork), 0x40000);
    if (work == NULL) {
        return 0;
    }
    task = func_00451fc0(arg0, D_005EFB80, 0xF, 0, 0,
                         func_0014ba40, func_0014bbb0, (u8*)work);
    work->mdl = (Model*)arg1;
    if (arg3 >= 0) {
        target = (f32)arg3;
    } else {
        half = arg3;
        half = ((u32)half >> 1) | (half & 1);
        target = (f32)half + (f32)half;
    }
    work->targetAlpha = target;
    work->framesRemaining = arg4;
    if (arg2 >= 0) {
        current = (f32)arg2;
    } else {
        half = arg2;
        half = ((u32)half >> 1) | (half & 1);
        current = (f32)half + (f32)half;
    }
    work->currentAlpha = current;
    func_0047a220((void*)arg1, &color);
    return task;
}
