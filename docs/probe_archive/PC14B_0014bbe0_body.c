/* object 432B / window 432B / normalized_diff 4; fndiff differing words 4 at offsets 0x11C, 0x120, 0x15C, 0x160. The residual is the repeated half-scaler OR result coloring: retail uses $v1 for the OR result and mtc1 source while b210 uses $v0. Exhausted source-shape probes include exact func_0044ea90 and func_00451fc0 declarations, operand reversal, inline OR helpers, separate shifted/OR locals, compound and in-place OR forms, signed/unsigned half temporaries, declaration-order rotations, direct cast, and both-arm shared shapes; best remained nd 4 at exact object size. Source is intentionally reverted to bare INCLUDE_ASM; this is the best retained C body. */
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