// Lane B3B best body for func_003b4230 (never reached MATCH).
// Best normalized_diff 9, object 164B / window 176B.
// Residual: entry guard colors slt $v1 vs retail slt $at,$zero,$a1 + beqz,
// plus one trailing nop retail keeps before jr $ra (retail real body 168B).
// Every spelling probed: literal 0<arg1 / arg1>0 / >=1 / >=0 / ==1 forms,
// named boolean go = 0 < arg1 (nd9), volatile read, unsigned compare,
// while/for/do-while shapes, O1, common-subs off, declaration permutations,
// goto labels, loads-inside-guard. Levers that reached nd9: schedule on,
// no_branch_likely on, opt_rebuildconditionals off, opt_propagation off,
// go = 0 < arg1 named boolean placed after i = 0, m2c load order,
// unrotated do-while with bottom test i < arg1.
#pragma schedule on
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
#pragma opt_propagation off
void func_003b4230(u8 *arg0, s32 arg1, u8 *arg2) {
    s32 i;
    u8 *dst;
    u8 *src;
    u8 *row1;
    u8 *row2;
    u8 *row3;
    s32 pitch;
    s32 stride;
    s32 go;

    dst = *(u8 **)(arg0 + 0);
    pitch = *(s32 *)(arg0 + 4);
    src = *(u8 **)(arg2 + 0x14);
    stride = *(s32 *)(arg2 + 0x18);
    i = 0;
    go = 0 < arg1;
    if (go != 0) {
        do {
            row1 = dst + pitch;
            row2 = row1 + pitch;
            row3 = row2 + pitch;
            *(f32 *)(dst + 0) = *(f32 *)(src + 0);
            *(f32 *)(dst + 4) = *(f32 *)(src + 4);
            *(f32 *)(dst + 8) = *(f32 *)(src + 8);
            dst = row3 + pitch;
            *(f32 *)(row1 + 0) = *(f32 *)(src + 0);
            *(f32 *)(row1 + 4) = *(f32 *)(src + 4);
            *(f32 *)(row1 + 8) = *(f32 *)(src + 8);
            *(f32 *)(row2 + 0) = *(f32 *)(src + 0);
            *(f32 *)(row2 + 4) = *(f32 *)(src + 4);
            *(f32 *)(row2 + 8) = *(f32 *)(src + 8);
            *(f32 *)(row3 + 0) = *(f32 *)(src + 0);
            *(f32 *)(row3 + 4) = *(f32 *)(src + 4);
            *(f32 *)(row3 + 8) = *(f32 *)(src + 8);
            src += stride;
            i += 1;
        } while (i < arg1);
    }
}
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
#pragma schedule off