/* Best measured near-match for func_00271d10 (576/576 bytes, normalized_diff 51).
 * Retail register list from disassembly: $a3 style, $t0 slot base, $a2/$a1
 * x/32 products and quotient, $v1/$a1 second quotient, $a1/$v1 scale tail.
 * Residual is the seven R5900 three-operand multiply destination/register
 * choices and their dependent shifts/stores; all control flow and loads match.
 * Tried: s16/s32 parameter, typed slot pointer, cached/direct table global,
 * switch case order, operand swaps, compound assignments, product/quotient
 * local swaps, declaration swaps, s64/narrow temporaries, direct global
 * condition/product spellings, explicit zero-minus/nested negative, and
 * optimization_level 2/3. Optimization pragmas were removed afterward.
 */
void func_00271d10(u8 *arg0, s32 arg1)
{
    FrFontSlot4 *temp_8;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_5_2;
    s32 temp_5_3;
    s32 temp_5_4;
    s32 temp_5_5;
    s32 temp_5_6;
    s32 temp_5_7;
    s32 temp_5_8;
    s32 temp_6_2;
    s32 temp_6_3;
    s32 var_5;
    s32 temp_6_4;
    s32 temp_6_6;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32 var_3_4;
    s32 var_3_5;
    s32 var_3_6;
    s32 temp_6_5;
    s32 var_5_2;
    s32 var_8;
    s8 temp_3_3;
    s8 temp_5;
    s32 temp_7_2;

    temp_8 =
        (FrFontSlot4 *)DAT_00881630_abs +
        *(u8 *)(arg0 + 0x15);
    temp_3 = D_007645A8;
    if (temp_3 > 0) {
        *(s8 *)(arg0 + 0x18) = (s8)temp_3;
    } else {
        *(s8 *)(arg0 + 0x18) =
            (&D_00763808)[*(u8 *)(arg0 + 0x15)];
    }
    *(s8 *)(arg0 + 0x19) =
        (&D_00763808)[*(u8 *)(arg0 + 0x15)];
    temp_3_2 = D_007645A8;
    if (temp_3_2 > 0) {
        *(s32 *)(arg0 + 0xC) = temp_3_2;
    } else {
        *(s32 *)(arg0 + 0xC) =
            (&D_00763808)[*(u8 *)(arg0 + 0x15)];
    }
    if ((*(u8 *)(arg0 + 0x17) & 1) &&
        *(u8 *)(*(u8 **)((u8 *)temp_8 + 4) + 0x16) != 0) {
        temp_7_2 = arg1 * 2;
        if (temp_7_2 < *(s32 *)((u8 *)temp_8 + 8)) {
            temp_6_2 = *(s32 *)((u8 *)temp_8 + 0x10);
            temp_5 = *(s8 *)(temp_6_2 + 1 + temp_7_2);
            if (temp_5 != 0) {
                temp_3_3 = *(s8 *)(temp_6_2 + temp_7_2);
                var_8 = temp_3_3 * 0x10;
                var_3 = temp_5 - temp_3_3;
                temp_6_3 = (temp_7_2 >> 1) + 0x20;
                switch (temp_6_3) {
                case 0x31:
                case 0x21:
                    var_8 -= 0x20;
                    var_3 += 4;
                    break;
                default:
                    break;
                }
                if (D_007645A8 > 0) {
                    var_5 = (-1 * var_8) * D_007645A8;
                    temp_6_5 = var_5 >> 5;
                    if (var_5 < 0) {
                        temp_6_5 = (var_5 + 0x1F) >> 5;
                    }
                    *(s32 *)(arg0 + 4) = temp_6_5;
                    temp_5_2 = (var_3 + 1) * D_007645A8;
                    var_3_2 = temp_5_2 >> 5;
                    if (temp_5_2 < 0) {
                        var_3_2 = (temp_5_2 + 0x1F) >> 5;
                    }
                    *(s32 *)(arg0 + 0xC) = var_3_2;
                } else {
                    temp_6_6 =
                        -var_8 * (&D_00763808)[*(u8 *)(arg0 + 0x15)];
                    var_5_2 = temp_6_6 >> 5;
                    if (temp_6_6 < 0) {
                        var_5_2 = (temp_6_6 + 0x1F) >> 5;
                    }
                    *(s32 *)(arg0 + 4) = var_5_2;
                    temp_5_3 =
                        (var_3 + 1) * (&D_00763808)[*(u8 *)(arg0 + 0x15)];
                    var_3_3 = temp_5_3 >> 5;
                    if (temp_5_3 < 0) {
                        var_3_3 = (temp_5_3 + 0x1F) >> 5;
                    }
                    *(s32 *)(arg0 + 0xC) = var_3_3;
                }
                temp_5_4 = D_007645A0;
                if (temp_5_4 > 0) {
                    temp_5_5 =
                        (u8)*(s8 *)(arg0 + 0x18) * temp_5_4;
                    var_3_4 = temp_5_5 >> 7;
                    if (temp_5_5 < 0) {
                        var_3_4 = (temp_5_5 + 0x7F) >> 7;
                    }
                    *(s8 *)(arg0 + 0x18) = (s8)var_3_4;
                    temp_5_6 = *(s32 *)(arg0 + 0xC) * D_007645A0;
                    var_3_5 = temp_5_6 >> 7;
                    if (temp_5_6 < 0) {
                        var_3_5 = (temp_5_6 + 0x7F) >> 7;
                    }
                    *(s32 *)(arg0 + 0xC) = var_3_5;
                }
                temp_5_7 = D_007645A4;
                if (temp_5_7 > 0) {
                    temp_5_8 =
                        (u8)*(s8 *)(arg0 + 0x19) * temp_5_7;
                    var_3_6 = temp_5_8 >> 7;
                    if (temp_5_8 < 0) {
                        var_3_6 = (temp_5_8 + 0x7F) >> 7;
                    }
                    *(s8 *)(arg0 + 0x19) = (s8)var_3_6;
                }
            }
        }
    }
}
