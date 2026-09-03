/* Lane119d3e_003e8ed0_body.c
 * best measured candidate for func_003e8ed0 under MWCCPS2 3.0.1 b119
 * source: src/promoted/code1_003e_cw119.c
 * object: 172B, window: 176B, fndiff differing words (reloc-masked): 12
 * lverify: normalized_diff 17, first_diffs [16,17,18,19,20,21,22,23,30,34,38,46,50,66,90,130]
 * levers tried: #pragma schedule on (baseline), no_branch_likely on/off,
 *   arg1 typed s32*/s32/u8*, arg1_p local copy, reordered var_19 load vs arg0 store,
 *   for-loops, static linkage, permute.py seed 0 (2771 iters) and seed 42 (1000 iters).
 * residual: prologue move of a1 hoisted before sq s1 vs retail's a1->s2 after sq s1,
 *   and the resulting s2/s3 register swap for arg1 and the first child.
 * This matches the documented b119 floor for a parameter move scheduled between
 * the sq saves in a fresh unit, so the function is archived and left in the parent.
 */
#pragma schedule on
void func_003e8ed0(u8 *arg0, s32 *arg1) {
    u8 *var_19;
    u8 *var_17;
    u8 *var_16;

    *(s32 **)(arg0 + 0xA0) = arg1;
    var_19 = *(u8 **)(arg0 + 0x98);
    if (var_19 != NULL) {
        do {
            *(s32 **)(var_19 + 0xA0) = arg1;
            var_17 = *(u8 **)(var_19 + 0x98);
            if (var_17 != NULL) {
                do {
                    *(s32 **)(var_17 + 0xA0) = arg1;
                    var_16 = *(u8 **)(var_17 + 0x98);
                    if (var_16 != NULL) {
                        do {
                            func_003e8ed0(var_16, arg1);
                            var_16 = *(u8 **)(var_16 + 0x9C);
                        } while (var_16 != NULL);
                    }
                    var_17 = *(u8 **)(var_17 + 0x9C);
                } while (var_17 != NULL);
            }
            var_19 = *(u8 **)(var_19 + 0x9C);
        } while (var_19 != NULL);
    }
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off
