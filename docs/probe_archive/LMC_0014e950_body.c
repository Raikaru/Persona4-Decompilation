/* Candidate reconstruction for func_0014e950; lverify remained MISMATCH (object 652/window 720, nd 436), so the live source was restored to INCLUDE_ASM. */
s32 func_0014e950(u8 *arg0, s32 arg3) {
    struct {
        u8 pad0[8];
        s8 bytes[4];
        u8 pad1[4];
        f32 out[3];
        u8 pad2[4];
        f32 src[3];
    } stack;
    f32 temp_f0;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    s32 temp_3_2;
    s32 temp_4;
    s32 var_4;
    s32 var_5;
    s32 var_7;
    s32 var_8;
    u32 var_9;
    u8 *temp_16;
    u8 *temp_2;
    u8 *entry;
    u8 *ptr;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)temp_16 != 2) {
        var_8 = 1;
        if (*(s32 *)temp_16 == 0) {
            temp_2 = *(u8 **)(temp_16 + 0xC);
            if (temp_2 == NULL) {
            } else if (*(s32 *)(*(u8 **)(temp_2 + 0x38)) > 0) {
            } else {
                var_8 = 0;
            }
            if (var_8 != 0) {
                ptr = func_003e9700(*(s32 *)(func_00457120() + 4));
                entry = temp_16 + 0x10;
                var_5 = 8;
                do {
                    temp_4 = *(s32 *)(ptr + 0);
                    temp_3_2 = *(s32 *)(ptr + 4);
                    ptr += 8;
                    var_5 -= 1;
                    *(s32 *)(entry + 0) = temp_4;
                    *(s32 *)(entry + 4) = temp_3_2;
                    entry += 8;
                } while (var_5 > 0);
                stack.src[0] = *(f32 *)(temp_16 + 0x30);
                stack.src[1] = *(f32 *)(temp_16 + 0x34);
                stack.src[2] = *(f32 *)(temp_16 + 0x38);
                func_003e40b0(&stack.src[0], &stack.src[0]);
                temp_f5 = stack.src[0] * 700.0f;
                stack.src[0] = temp_f5;
                temp_f4 = stack.src[1] * 700.0f;
                stack.src[1] = temp_f4;
                temp_f3 = stack.src[2] * 700.0f;
                stack.src[2] = temp_f3;
                temp_f0 = *(f32 *)(temp_16 + 0x48);
                stack.out[0] = *(f32 *)(temp_16 + 0x40);
                stack.out[1] = *(f32 *)(temp_16 + 0x44);
                stack.out[2] = temp_f0;
                stack.out[0] += temp_f5;
                stack.out[1] += temp_f4;
                stack.out[2] = temp_f0 + temp_f3;
                func_0014e740(*(u8 **)(temp_16 + 0xC), &stack.out[0]);
                func_0045af60(1, 0xB, 3, 4);
                *(s32 *)(temp_16 + 8) = 0;
                *(s32 *)temp_16 = *(s32 *)temp_16 + 1;
            }
        } else if (*(s32 *)temp_16 == 1) {
            if (*(s32 *)(temp_16 + 8) < 0x54) {
                if (*(s32 *)(temp_16 + 8) >= 0x29) {
                    var_9 = 0;
                    do {
                        var_7 = 0;
                        entry = D_007EF9B0 + (var_9 * 0x750);
                        if ((*(s32 *)(entry + 0x48) != 0) &&
                            (*(u8 **)(entry + 0x54) != NULL)) {
                            var_7 = 1;
                        }
                        if (var_7 != 0) {
                            *(s32 *)(*(u8 **)(entry + 0x54) + 0x28) =
                                *(s32 *)(*(u8 **)(entry + 0x54) + 0x28) & ~2;
                        }
                        var_9 += 1;
                    } while (var_9 < 4U);
                    if (*(s32 *)(temp_16 + 4) == 1) {
                        ptr = (u8 *)&iGpffff9dd0 + 8;
                        entry = (u8 *)&stack.bytes[0];
                        var_4 = 4;
                        do {
                            *(s8 *)(entry + 0) = *(s8 *)(ptr + 0);
                            *(s8 *)(entry + 1) = *(s8 *)(ptr + 1);
                            ptr += 2;
                            entry += 2;
                            var_4 -= 1;
                        } while (var_4 > 0);
                        func_00122520(1, 1);
                        func_001228a0(stack.bytes[0], stack.bytes[1], stack.bytes[2]);
                        *(s32 *)temp_16 = *(s32 *)temp_16 + 1;
                    }
                }
                *(s32 *)(temp_16 + 8) = *(s32 *)(temp_16 + 8) + 1;
            } else {
                *(s32 *)temp_16 = 2;
            }
        }
        return 0;
    }
    return -1;
}
