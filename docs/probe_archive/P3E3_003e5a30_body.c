/* object_size=176B window=176B normalized_diff=106 differing_offsets=[4,6,7,8,10,11,12,14,16,17,18,19,20,22,24,25] classification=compiler/source-shape near-miss; fndiff differing_words=35; ruled_out=callee declaration (block-scope func_003e3370(u8*,s32)), global D_0070B7A0 array addressing, declaration/register order, split loop statement order, switch positive-dispatch shape, schedule on/off, no_branch_likely on/off, optimization levels 1 and 3, direct-vs-temporary global argument materialization. */
s32 func_003e5a30(u8 *arg0) {
    extern s32 func_003e3370(u8 *, s32);
    s32 temp_4;
    s32 var_18;
    s32 var_17;
    s32 var_16;

    temp_4 = *(s32 *)(arg0 + 4);
    var_17 = 0;
    var_18 = temp_4 * 0x38;
    var_18 += 4;
    var_18 += 0xC;
    temp_4 = 0 < temp_4;
    switch (temp_4) {
    case 1:
        var_16 = 0;
        do {
            var_18 += func_003e3370(
                D_0070B7A0,
                *(s32 *)((u8 *)(*(s32 *)arg0 + var_16))) + 0xC;
            var_17 += 1;
            var_16 += 4;
        } while (var_17 < *(s32 *)(arg0 + 4));
        break;
    default:
        break;
    }
    return var_18;
}
