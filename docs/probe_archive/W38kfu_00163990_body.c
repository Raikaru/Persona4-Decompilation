/*
 * W38kfu_00163990_v1 best probe for func_00163990.
 * object/window: 760B / 768B; residual: 173 words (reloc-masked).
 * Differing offsets: prologue diverges immediately (object uses 0x160 frame
 * and only s0-s4, retail uses 0x170 and s0-s5); the search-loop address is
 * formed via a single 32-bit relocatable lui/addiu pair for D_007E8C00
 * instead of retail's split lui a0/addiu. The slot pointer is held in s1
 * in the object versus s0 in retail, and temp_21 lands in s0 versus s5.
 * Switch code and average loop show the same structure but register
 * colouring produces different delay-slot/move patterns.
 * Ruled out: raw m2c output (M2C_UNK sp70, saved_reg_gp placeholders,
 * wrong call argument counts); u8 sp70[0x100] gives a smaller frame than
 * retail; s32 iGpffffb414 and u8 *iGpffffb414 both load the GP symbol
 * correctly but do not fix the prologue.
 */
u8 *func_00163990(u32 arg0, u8 *arg1, s32 arg2)
{
    u8 sp70[0x100];
    u32 temp_21;
    s32 temp_3_2;
    s32 var_17;
    s32 var_4;
    s32 var_6;
    s32 var_6_3;
    s32 var_7;
    u16 temp_5;
    u8 *temp_3;
    u8 *var_16;
    u8 *var_5;
    u8 *var_6_2;
    u8 *inner;

    var_16 = NULL;
    var_6 = 0;
loop_4:
    if (var_6 < 0xF) {
        temp_3 = D_007E8C00 + (var_6 * 0x750);
        if (*(s32 *)(temp_3 + 0x48) == 0) {
            var_16 = temp_3;
        } else {
            var_6 += 1;
            goto loop_4;
        }
    }
    var_17 = 0;
    if (var_16 == NULL) {
        return NULL;
    }
    temp_21 = arg0 & 0xFFFF;
    *(u8 **)(var_16 + 0x48) = func_00231630(temp_21, 0x750, var_6);
    *(s32 *)(var_16 + 0x4C) = (s32)(iGpffffb414 + (temp_21 * 0x18));
    *(s16 *)(var_16 + 0x728) = 0;
    temp_3_2 = (arg0 >> 0x10) & 0xFFFF;
    switch (temp_3_2) {
    case 1:
        *(s16 *)(var_16 + 0x1C8) = 1;
        break;
    case 2:
        *(s16 *)(var_16 + 0x1C8) = 2;
        break;
    case 4:
        *(s16 *)(var_16 + 0x1C8) = 3;
        break;
    default:
        func_00442088(sp70, D_005F1510, arg0);
        func_0046d740(sp70, D_005F1500, 0x4B6);
        break;
    }
    switch (arg2) {
    case 0:
        var_17 = 0;
        break;
    case 1:
        var_17 = 1;
        break;
    case 2:
        var_17 = func_003b7060() & 1;
        break;
    default:
        var_17 = 0;
        break;
    }
    if (var_17 == 0) {
        *(s32 *)(var_16 + 0x50) = func_00478140(8U, 1U, 0);
        *(s8 *)(var_16 + 0x1CA) = 0;
    } else {
        *(s32 *)(var_16 + 0x50) = func_00478140(8U, 2U, 0);
        *(s8 *)(var_16 + 0x1CA) = 1;
    }
    var_5 = var_16 + 0x5C;
    var_4 = 0x2A;
    var_6_2 = arg1;
    do {
        *(s32 *)var_5 = *(s32 *)var_6_2;
        *(s32 *)(var_5 + 4) = *(s32 *)(var_6_2 + 4);
        var_6_2 += 8;
        var_5 += 8;
        var_4 -= 1;
    } while (var_4 > 0);
    *(u8 **)(var_16 + 0x1AC) = var_16 + 0x5C;
    *(s16 *)(var_16 + 0x1CC) = (s16)((600.0f + *(f32 *)(arg1 + 0x140)) / 1200.0f);
    *(s16 *)(var_16 + 0x1CE) = (s16)((600.0f + *(f32 *)(arg1 + 0x148)) / 1200.0f);
    var_7 = 0;
    var_6_3 = 0;
    temp_5 = *(u16 *)(*(u8 **)(var_16 + 0x48) + 2);
    inner = *(u8 **)(*(u8 **)(var_16 + 0x48) + 4);
loop_29:
    if (var_7 < (s32)temp_5) {
        var_6_3 += *(u8 *)(inner + (var_7 * 0x30) + 6);
        var_7 += 1;
        goto loop_29;
    }
    *(s32 *)(var_16 + 0x1C0) = var_6_3 / (s32)temp_5;
    iGpffffb2e8 += 1;
    return var_16;
}
