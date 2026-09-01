/* Closest clean-C candidate for func_003d0230; skipped after five attempts (normalized_diff remained nonzero). */
#pragma no_branch_likely on
#pragma schedule on
// FUN_003D0230
void func_003d0230(u8 *arg0) {
    f32 spD4;
    f32 spD0;
    u8 work[0x58];
    f32 temp_f0;
    f32 var_f2;
    f32 distance;
    f32 radius;
    s32 *temp_6;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_21;
    u8 *temp_22;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *var_19;
    u8 *var_20;

    temp_21 = *(u8 **)(arg0 + 8);
    temp_16 = *(u8 **)(temp_21 + 0x18);
    if ((*(u32 *)(temp_16 + 8) & 0x20) != 0) {
        D_008872EA += 1;
        temp_2 = func_003e9700(*(s32 *)(temp_21 + 4));
        func_003e0960(work + 0x10, temp_2);
        if ((*(u32 *)(temp_2 + 0xC) & 3) == 3) {
            spD0 = 1.0f;
            spD4 = 1.0f;
        } else {
            temp_f0 = *(f32 *)(work + 0x24);
            var_f2 = *(f32 *)(work + 0x20);
            spD0 = sqrtf(
                temp_f0 * temp_f0 + var_f2 * var_f2 +
                *(f32 *)(work + 0x28) * *(f32 *)(work + 0x28));
            spD4 = spD0;
            if (spD0 > 0.0f) {
                spD4 = 1.0f / spD0;
            }
        }
        temp_3 = *(u8 **)(temp_16 + 0x54);
        *(s32 *)work =
            *(s32 *)(temp_3 + *(s32 *)(temp_3 + 0xC) + 0x18) + 0xC;
        func_003c96d0(func_003cffa0, work);
        var_20 = *(u8 **)(temp_21 + 0x64);
        temp_22 = temp_21 + 0x64;
        if (var_20 != temp_22) {
            do {
                temp_3_2 = *(u8 **)(var_20 + 8);
                var_19 = *(u8 **)(temp_3_2 + 0x40);
                temp_17 = temp_3_2 + 0x40;
                if (var_19 != temp_17) {
                    do {
                        temp_6 = *(s32 **)(var_19 + 8);
                        if ((temp_6 != NULL) &&
                            (*(u16 *)((u8 *)temp_6 + 0x3C) !=
                             D_008872EA) &&
                            ((*(u8 *)((u8 *)temp_6 + 2) & 1) != 0)) {
                            *(u16 *)((u8 *)temp_6 + 0x3C) = D_008872EA;
                            temp_16 = func_003e9700(
                                *(s32 *)((u8 *)temp_6 + 4)) + 0x30;
                            temp_2 = func_003bfae0(temp_21);
                            distance =
                                (*(f32 *)(temp_2 + 4) -
                                 *(f32 *)(temp_16 + 4)) *
                                    (*(f32 *)(temp_2 + 4) -
                                     *(f32 *)(temp_16 + 4)) +
                                (*(f32 *)(temp_2 + 0) -
                                 *(f32 *)(temp_16 + 0)) *
                                    (*(f32 *)(temp_2 + 0) -
                                     *(f32 *)(temp_16 + 0)) +
                                (*(f32 *)(temp_2 + 8) -
                                 *(f32 *)(temp_16 + 8)) *
                                    (*(f32 *)(temp_2 + 8) -
                                     *(f32 *)(temp_16 + 8));
                            radius = *(f32 *)(temp_2 + 0xC) +
                                     *(f32 *)((u8 *)temp_6 + 0x14);
                            if (distance < radius * radius) {
                                if ((*(u8 *)((u8 *)temp_6 + 2) & 1) != 0) {
                                    func_003cfa80(
                                        (u8 *)temp_6, (s32)(work + 0x10),
                                        *(f32 *)(work + 0x50),
                                        *(f32 *)(work + 0x54));
                                }
                            }
                        }
                        var_19 = *(u8 **)var_19;
                    } while (var_19 != temp_17);
                }
                var_20 = *(u8 **)var_20;
            } while (var_20 != temp_22);
        }
    }
}
#pragma schedule off
#pragma no_branch_likely off
