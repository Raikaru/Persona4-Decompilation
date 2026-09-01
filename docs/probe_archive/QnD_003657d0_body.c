/*
 * func_003657d0 best legal plain-C probe.
 * Object: 752B; retail window: 752B; normalized diff: 9 words.
 * Differing reloc-masked offsets: 0xD0, 0x148, 0x14C, 0x184, 0x188,
 *   0x1C0, 0x1C4, 0x1FC, 0x200.
 * The four-operation COP1 accumulator chain reproduced exactly:
 *   adda.s/madd.s at offsets 0x108/0x10C and 0x118/0x11C (retail).
 * Remaining residual: one commutative mul.s operand orientation at 0xD0,
 *   plus four repeated OR/MT1 destination-register colorings.
 * Ruled out: original parameter order (nd 163); five archived
 *   declaration/source-order variants (same saved-register/scheduler
 *   residual); swapping the angle multiply operands; splitting the angle
 *   multiply into ordinary mul/add (best setup); unsigned t; register t;
 *   low-bit-first and split low-bit temporaries; direct negative-byte
 *   expression; distinct integer temporaries; distinct float destinations.
 * Chain reproduced: yes. Added data references: none; all references are
 * existing symbols and are placeable.
 */
void func_003657d0(s64 arg0, f32 fparg0, s32 arg1, f32 fparg1, f32 fparg2, s32 arg2) {
    f32 vertices[4][16];
    f32 sine;
    f32 cosine;
    f32 temp_f23;
    f32 origin_x;
    f32 origin_y;
    f32 temp_f20;
    f32 temp_f27;
    f32 var_f0_19;
    f32 var_f0;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 var_20;
    u8 *temp_2;
    s32 t;
    s32 bit;

    origin_y = *((f32 *)(void *)&arg0 + 1);
    origin_x = *(f32 *)(void *)&arg0;
    temp_f23 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_f20 = D_008872F8[0];
    temp_19 = (s32)(u8)(((u32)arg1 & 0xFF000000) >> 24);
    temp_18 = (s32)(u8)(((u32)arg1 & 0x00FF0000) >> 16);
    temp_17 = (s32)(u8)(((u32)arg1 & 0x0000FF00) >> 8);
    temp_16 = arg1 & 0xFF;
    var_20 = 0;
    temp_f20 -= fparg0;
    while (var_20 < 4) {
        temp_f27 = (f32)var_20;
        temp_f27 = temp_f27 * iGpffff8094;
        temp_f27 += fparg2;
        sine = func_0044b7b0(temp_f27);
        cosine = func_0044b610(temp_f27);
        temp_2 = (u8 *)&vertices[var_20][0];
        *(f32 *)(temp_2 + 0) = origin_x + fparg1 * sine;
        *(f32 *)(temp_2 + 4) = origin_y + fparg1 * cosine;
        *(f32 *)(temp_2 + 8) = temp_f20;
        if (temp_19 >= 0) {
            var_f0_19 = (f32)temp_19;
        } else {
            t = (u32)temp_19 >> 1;
            bit = temp_19 & 1;
            t |= bit;
            var_f0_19 = (f32)t;
            var_f0_19 += var_f0_19;
        }
        *(f32 *)(temp_2 + 0x20) = var_f0_19;
        if (temp_18 >= 0) {
            var_f0 = (f32)temp_18;
        } else {
            t = ((u32)temp_18 >> 1) | (temp_18 & 1);
            var_f0 = (f32)t;
            var_f0 += var_f0;
        }
        *(f32 *)(temp_2 + 0x24) = var_f0;
        if (temp_17 >= 0) {
            var_f0 = (f32)temp_17;
        } else {
            t = ((u32)temp_17 >> 1) | (temp_17 & 1);
            var_f0 = (f32)t;
            var_f0 += var_f0;
        }
        *(f32 *)(temp_2 + 0x28) = var_f0;
        if (temp_16 >= 0) {
            var_f0 = (f32)temp_16;
        } else {
            t = ((u32)temp_16 >> 1) | (temp_16 & 1);
            var_f0 = (f32)t;
            var_f0 += var_f0;
        }
        *(f32 *)(temp_2 + 0x2C) = var_f0;
        *(f32 *)(temp_2 + 0x18) = temp_f23;
        var_20 += 1;
    }
    D_00887300[0](1, 0);
    if ((arg2 != 0) && ((temp_16 & 0xFF) == 0xFF)) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](5, &vertices[0], 4);
    if ((arg2 != 0) && ((temp_16 & 0xFF) == 0xFF)) {
        iGpffffabe8 &= ~0x80;
    }
}
