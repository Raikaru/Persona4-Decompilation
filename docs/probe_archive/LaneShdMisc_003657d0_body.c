/* Closest clean-C probe for func_003657d0; object 748B over a 752B window,
   normalized diff 163. Rejected after five source/declaration variants: the
   saved-register and source-order schedule remained rotated from retail. */
void func_003657d0(s64 arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 vertices[4][16];
    f32 sine;
    f32 cosine;
    f32 temp_f20;
    f32 origin_x;
    f32 origin_y;
    f32 temp_f23;
    f32 temp_f27;
    f32 var_f0;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 var_20;
    s32 t;
    u8 *temp_2;

    origin_x = *(f32 *)(void *)&arg0;
    origin_y = *((f32 *)(void *)&arg0 + 1);
    temp_f23 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_19 = ((u32)arg1 & 0xFF000000) >> 24;
    temp_18 = ((u32)arg1 & 0x00FF0000) >> 16;
    temp_17 = ((u32)arg1 & 0x0000FF00) >> 8;
    temp_16 = arg1 & 0xFF;
    var_20 = 0;
    temp_f20 = D_008872F8[0] - fparg0;
    while (var_20 < 4) {
        temp_f27 = iGpffff8094 * (f32)var_20 + fparg2;
        sine = func_0044b7b0(temp_f27);
        cosine = func_0044b610(temp_f27);
        temp_2 = (u8 *)&vertices[var_20][0];
        *(f32 *)(temp_2 + 0) = origin_x + fparg1 * sine;
        *(f32 *)(temp_2 + 4) = origin_y + fparg1 * cosine;
        *(f32 *)(temp_2 + 8) = temp_f20;
        if (temp_19 >= 0) {
            var_f0 = (f32)temp_19;
        } else {
            t = ((u32)temp_19 >> 1) | (temp_19 & 1);
            var_f0 = (f32)t;
            var_f0 += var_f0;
        }
        *(f32 *)(temp_2 + 0x20) = var_f0;
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
