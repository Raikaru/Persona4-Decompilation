/* BEST BODY archive for func_002483c0.
 * Measured object/window: 544B / 544B.
 * normalized_diff_words: 7 (reloc-masked).
 * differing offsets (bytes): 0x28, 0x34, 0xAC, 0xBC, 0xC8, 0x124, 0x188.
 * Residual: saved-register coloring only: retail arg=$s2/mask=$s3;
 * candidate arg=$s3/mask=$s2.
 * Ruled out: bare/no pragma (object 540B, normalized diff 79); direct
 * opt_common_subs off (object 552B, duplicated D_00881494 load); propagation
 * off (object 560B/frame change); narrow u16 locals, explicit casts and U
 * constants, old-style declarations/wrappers, declaration-order swaps,
 * inner/outer mask scope, direct parameter masks, and alternate loop CFGs.
 * Target has no daddiu materialization, so the narrow-unsigned rule does not
 * apply. This body was not retained live because the saved-register residual
 * remained nonzero.
 */
void func_002483c0(u16 arg0) {
    s32 var_20;
    s32 temp_17;
    s32 var_3;
    u32 *temp_16;
    u32 *temp_16_2;
    u8 *temp_2;
    u32 temp_19;
    s32 temp_20;

    var_20 = 1;
    temp_19 = arg0;
    while (var_20 < 0x1F) {
        if (temp_19 == var_20) {
            goto block_15;
        }
        if (func_001077f0(var_20) == 0) {
            goto block_15;
        }
        if ((func_00107ac0(var_20 & 0xFFFF) & 0xFFFF) != 0xA) {
            goto block_15;
        }
        if (func_00248a60(var_20 & 0xFFFF) == 0) {
            goto block_15;
        }
        if (func_00107a00(var_20 & 0xFFFF, 3) != 0) {
            goto block_15;
        }
        {
            u8 *p;
            s32 count;
            s32 i;
            s32 temp_18;

            temp_16 = (u32 *)D_00881494[0];
            p = (u8 *)temp_16 + 8;
            count = *(s32 *)(temp_16 + 1);
            i = 0;
            temp_18 = var_20 & 0xFFFF;
            while (i < count) {
                if (*(u16 *)p == temp_18) {
                    if (*(u16 *)(p + 2) == temp_19) {
                        temp_17 = *(s32 *)(p + 4);
                        goto block_14;
                    }
                }
                p += 8;
                i += 1;
            }
            temp_17 = 0;
block_14:
            temp_2 = (u8 *)func_001070e0(var_20 & 0xFFFF);
            if (temp_2 == NULL) {
                var_3 = 0;
                goto block_13;
            }
            temp_16 = (u32 *)D_00881480[0];
            if (temp_18 >= temp_16[1]) {
                func_0046d730(D_006359D0, 0x4C);
            }
            temp_20 = (var_20 & 0xFFFF) * 0x64;
            if (*(u16 *)((u32)temp_20 + (u32)temp_16 + 0x12) == 0) {
                goto block_12;
            }
            *(u16 *)(temp_2 + 0xA) += temp_17 & 0xFFFF;
            temp_16_2 = (u32 *)D_00881480[0];
            if (temp_18 >= temp_16_2[1]) {
                func_0046d730(D_006359D0, 0x4C);
            }
            if (*(u16 *)(temp_2 + 0xA) >= *(u16 *)((u32)temp_20 + (u32)temp_16_2 + 0x12)) {
                var_3 = 1;
            } else {
                goto block_12;
            }
            goto block_13;
block_12:
            var_3 = 0;
block_13:
            if (var_3 != 0) {
                func_00107ce0(var_20 & 0xFFFF);
            }
        }
block_15:
        var_20 += 1;
    }
}
