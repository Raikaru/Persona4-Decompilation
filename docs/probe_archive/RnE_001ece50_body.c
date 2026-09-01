/* object 532/window 528/normalized_diff 111; best measured candidate (u8 orientation-helper return). Differing offsets: 0x000-0x20C excluding matching words (see fndiff); ruled out: while versus for outer loop, f32* versus u8* parameters, pointer locals versus inline address expressions, integer-address locals, unprototyped/u64/s64/u8 helper declarations, opt_propagation off, optimization_level 1. */
s32 func_001ece50(f32 *arg0, f32 *arg1, f32 arg2)
{
    extern u8 func_001ecde0(const f32 *first, const f32 *second, const f32 *point);
    extern s32 func_001ec8c0(f32 *first, f32 *second, f32 *point, f32 threshold);
    u8 *node;
    s32 edge;

    for (node = *(u8 **)(iGpffffb3ac + 0x318);
         node != NULL;
         node = *(u8 **)(node + 0x4CC)) {
        if ((*(f32 *)(node + 8) < arg0[0]) &&
            (*(f32 *)(node + 0xC) < arg0[1]) &&
            (arg0[0] < *(f32 *)(node + 0x268)) &&
            (arg0[1] < *(f32 *)(node + 0x26C))) {
            continue;
        }
        if ((*(f32 *)(node + 8) < arg1[0]) &&
            (*(f32 *)(node + 0xC) < arg1[1]) &&
            (arg1[0] < *(f32 *)(node + 0x268)) &&
            (arg1[1] < *(f32 *)(node + 0x26C))) {
            continue;
        }
        for (edge = 0; edge < 4; edge++) {
            if (func_001ecde0(
                    (f32 *)(node + (edge * 0x130) + 8),
                    (f32 *)(node + (((edge + 1) & 3) * 0x130) + 8),
                    arg0) !=
                func_001ecde0(
                    (f32 *)(node + (edge * 0x130) + 8),
                    (f32 *)(node + (((edge + 1) & 3) * 0x130) + 8),
                    arg1)) {
                if (func_001ecde0(
                        arg0,
                        arg1,
                        (f32 *)(node + (edge * 0x130) + 8)) !=
                    func_001ecde0(
                        arg0,
                        arg1,
                        (f32 *)(node + (((edge + 1) & 3) * 0x130) + 8))) {
                    return 1;
                }
            }
            if (func_001ec8c0(
                    arg0,
                    arg1,
                    (f32 *)(node + (edge * 0x130) + 8),
                    arg2) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
