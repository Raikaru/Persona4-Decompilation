/* Best candidate for func_00166e30, retained before rollback to ASM.
 * Object/window: 748B/752B.
 * Normalized residual: 15 words (fndiff prints 16 including one relocation
 * bookkeeping difference); differing byte offsets: 192, 200, 228, 232,
 * 236, 300, 308, 336, 340, 344, 408, 416, 444, 448, 452.
 * COP1 accumulator chain: reproduced; adda.s, madd.s, and both msub.s
 * operations matched, including all six accumulator-chain operations.
 * The opt_rebuildconditionals-off pragma reproduced all three c.le.s/bc1t
 * conversion guard shapes; without it the branch polarity/layout differs.
 * Ruled out: split mask assignment; direct branch stores; untruncated s32
 * conversion temporaries; scalar stack-byte locals; aggregate struct-byte
 * locals; separate conversion locals; u32 conversion local; threshold f32
 * local; direct indexed initial byte copies; byte-temp declaration reorder;
 * opt_propagation-off. Sibling archive probes also ruled out
 * opt_common_subs-off and schedule-off, direct float/pointer type-puns,
 * register-qualified/named-byte unions, integer-mask temporaries, and direct
 * 255.0f assignment. The remaining 15 words are ordinary conversion-result
 * GPR coloring (retail v1, candidate v0).
 * No new data references were introduced; D_007613EC and all called
 * func_XXXXXXXX symbols are existing, real, placeable references.
 */
#pragma push
/* measured: opt_rebuildconditionals probe for COP1 conversion branch shape. */
#pragma opt_rebuildconditionals off
// FUN_00166E30
s32 func_00166e30(u8 *arg0)
{
    u8 sp4C[4];
    u8 sp48[4];
    u8 sp44[4];
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f20;
    register s32 var_3;
    s32 temp_3;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_4;
    u8 *var_17;
    u8 temp_byte0;
    u8 temp_byte1;
    u8 temp_byte2;
    u8 temp_byte3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_f20 = func_0044b7b0(D_007613EC *
                             (f32)(*(s32 *)(temp_16 + 8)) /
                             (f32)(*(s32 *)(temp_16 + 0xC)));
    temp_2 = func_0047a250(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50));
    temp_byte0 = *temp_2++;
    temp_byte1 = *temp_2++;
    temp_byte2 = *temp_2++;
    temp_byte3 = *temp_2++;
    sp4C[0] = temp_byte0;
    sp4C[1] = temp_byte1;
    sp4C[2] = temp_byte2;
    sp4C[3] = temp_byte3;
    *(s32 *)(temp_16 + 0xC) = 0x28;
    temp_f1 = (175.0f + 0.0f) + (70.0f * temp_f20);
    if (!(2.1474836e9f <= temp_f1)) {
        var_3 = (u8)(s32)temp_f1;
    } else {
        var_3 = (u8)(0x80000000 | (s32)(temp_f1 - 2.1474836e9f));
    }
    sp4C[0] = var_3;
    temp_f1_2 = (37.0f + 0.0f) - (10.0f * temp_f20);
    if (2.1474836e9f <= temp_f1_2) {
        goto byte1_large;
    }
    var_3 = (u8)(s32)temp_f1_2;
    goto byte1_ready;
byte1_large:
    var_3 = (u8)((s32)(temp_f1_2 - 2.1474836e9f) | 0x80000000);
byte1_ready:
    sp4C[1] = var_3;
    temp_f1_3 = (255.0f + 0.0f) - (208.0f * temp_f20);
    if (2.1474836e9f <= temp_f1_3) {
        goto byte2_large;
    }
    var_3 = (u8)(s32)temp_f1_3;
    goto byte2_ready;
byte2_large:
    var_3 = (u8)((s32)(temp_f1_3 - 2.1474836e9f) | 0x80000000);
byte2_ready:
    sp4C[2] = var_3;
    temp_3 = *(s32 *)(temp_16 + 8) + 1;
    *(s32 *)(temp_16 + 8) = temp_3;
    if (*(s32 *)(temp_16 + 0xC) < temp_3) {
        *(s32 *)(temp_16 + 8) = 0;
    }
    temp_4 = *(u8 **)(temp_16 + 4);
    temp_3_2 = *(u8 *)(temp_4 + 0x1CA);
    if (temp_3_2 == 0) {
        var_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        var_17 = *(u8 **)var_17;
        goto loop_16_check;
loop_16_body:
        if (*(s32 *)(var_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(var_17 + 8), sp48);
            sp48[0] = 0xFF;
            sp48[1] = 0xFF;
            sp48[2] = 0xFF;
            func_004b13f0(*(u8 **)(var_17 + 8), sp48);
        }
        var_17 = *(u8 **)(var_17 + 0x10);
loop_16_check:
        if (var_17 == NULL) {
            goto mode_done;
        }
        goto loop_16_body;
    } else if (temp_3_2 == 1) {
        temp_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        temp_17 = *(u8 **)temp_17;
        temp_17 = *(u8 **)(temp_17 + 0x10);
        temp_17 = *(u8 **)(temp_17 + 0x10);
        if (*(s32 *)(temp_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(temp_17 + 8), sp44);
            sp44[0] = sp4C[0];
            sp44[1] = sp4C[1];
            sp44[2] = sp4C[2];
            func_004b13f0(*(u8 **)(temp_17 + 8), sp44);
        }
    }
mode_done:
    func_0047a220(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50), sp4C);
    return 0;
}
#pragma pop
