/* Best candidate for func_00167120, retained before rollback to ASM.
 * Object/window: 708B/720B.
 * Normalized residual: 24 words.
 * Differing offsets (words): 136, 144, 148, 152, 164, 168, 176,
 *   188, 204, 208, 212, 276, 284, 312, 316, 320, 368, 376,
 *   404, 408, 412, 708, 712, 716.
 * The final three offsets are the retail alignment nops omitted by the 708B
 * object; fndiff reports 24 total normalized differing words.
 * COP1 accumulator chain: reproduced; adda.s and all madd.s operations matched.
 * Ruled out: opt_propagation-off, opt_common_subs-off, schedule-off;
 *   direct float locals and pointer type-puns; register-qualified union;
 *   named-byte union; scalar byte locals (dead-store/stack-frame mismatch);
 *   integer-mask conversion temporaries; direct 255.0f assignment.
 * Ordinary causes remaining: union bit-pun forces sp40 store/load and
 *   reverses literal FPR operands; conversion result coloring selects v0
 *   instead of retail v1. No new data references were introduced.
 */
#pragma push
#pragma opt_rebuildconditionals off
s32 func_00167120(u8 *arg0)
{
    u8 sp4C[4];
    u8 sp48[4];
    u8 sp44[4];
    union {
        u32 bits;
        f32 value;
    } byte0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    u8 var_3;
    u8 var_3_2;
    u8 var_3_3;
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
    *(s32 *)(temp_16 + 0xC) = 0x14;
    byte0.bits = 0x437F0000;
    if (2.1474836e9f <= byte0.value) {
        goto byte0_large;
    }
    var_3 = (u8)(s32)byte0.value;
    goto byte0_ready;
byte0_large:
    var_3 = (u8)((s32)(byte0.value - 2.1474836e9f) | 0x80000000);
byte0_ready:
    sp4C[0] = var_3;
    temp_f1 = (198.0f + 0.0f) + (57.0f * temp_f20);
    if (2.1474836e9f <= temp_f1) {
        goto byte1_large;
    }
    var_3_2 = (u8)(s32)temp_f1;
    goto byte1_ready;
byte1_large:
    var_3_2 = (u8)((s32)(temp_f1 - 2.1474836e9f) | 0x80000000);
byte1_ready:
    sp4C[1] = var_3_2;
    temp_f1_2 = 100.0f * temp_f20;
    if (2.1474836e9f <= temp_f1_2) {
        goto byte2_large;
    }
    var_3_3 = (u8)(s32)temp_f1_2;
    goto byte2_ready;
byte2_large:
    var_3_3 = (u8)((s32)(temp_f1_2 - 2.1474836e9f) | 0x80000000);
byte2_ready:
    sp4C[2] = var_3_3;
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
